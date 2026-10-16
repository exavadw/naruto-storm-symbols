#!/usr/bin/env python3
"""make_pdb.py: write a PDB of public symbols for one PC build, so debuggers (x64dbg, WinDbg, Visual Studio) and
other PDB readers show the names.

    python tools/make_pdb.py games/storm4/<sha256> "C:/Games/NSUNS4/NSUNS4.exe" [-o out.pdb] [--min-confidence medium]

Needs your own exe: the SHA-256 is checked against meta.json, the section table is copied into the PDB, and the
exe's CodeView record (GUID + age + PDB file name) is reused so debuggers accept the PDB as the exe's own.
Output defaults to the PDB file name from that record, next to the exe; that is where x64dbg and WinDbg look.

Contents: one S_PUB32 (function) public symbol per name, an empty type stream, and the exe's section headers. No
types, locals or line numbers (none exist). Standard library only; no LLVM/Microsoft tools needed.

min-confidence: high and medium by default. With "low", low-confidence names are added as "maybe_<name>".
"""
import argparse
import os
import struct
import sys
import time
import uuid

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from nucc_common import PE, build_dir, check_exe, die, guid_str, is_va, load_functions, load_meta  # noqa: E402

BLOCK = 4096
IPHR_HASH = 4096                    # GSI hash buckets
S_PUB32 = 0x110E
S_CONSTANT = 0x1107
T_UINT4 = 0x0075
PUBSYM_FUNCTION = 0x2
NIL = 0xFFFF                        # "no stream"


# --- hashing (as in Microsoft's reference implementation / LLVM's hashStringV1) -----------------------------------

def hash_v1(s: bytes) -> int:
    r = 0
    n4 = len(s) // 4
    for (w,) in struct.iter_unpack("<I", s[:n4 * 4]):
        r ^= w
    rest = s[n4 * 4:]
    if len(rest) >= 2:
        r ^= struct.unpack_from("<H", rest)[0]
        rest = rest[2:]
    if rest:
        r ^= rest[0]
    r |= 0x20202020
    r ^= r >> 11
    return (r ^ (r >> 16)) & 0xFFFFFFFF


def gsi_key(name: bytes):
    """Order of records inside a GSI hash bucket: length first, then case-insensitive (ASCII) / bytewise."""
    try:
        return (len(name), name.decode("ascii").lower().encode(), name)
    except UnicodeDecodeError:
        return (len(name), name, name)


# --- streams ----------------------------------------------------------------------------------------------------

def pub32(segment, offset, name: bytes) -> bytes:
    body = struct.pack("<HIIH", S_PUB32, PUBSYM_FUNCTION, offset, segment) + name + b"\0"
    body += b"\0" * (-(len(body) + 2) % 4)
    return struct.pack("<H", len(body)) + body


def constant(name: bytes, value: int) -> bytes:
    """S_CONSTANT of type unsigned int (value < 0x8000)."""
    body = struct.pack("<HIH", S_CONSTANT, T_UINT4, value) + name + b"\0"
    body += b"\0" * (-(len(body) + 2) % 4)
    return struct.pack("<H", len(body)) + body


def gsi_hash(records):
    """records: [(name bytes, symbol-record-stream offset)] -> GSI hash section (header, hash records, buckets)."""
    buckets = [[] for _ in range(IPHR_HASH)]
    for name, off in records:
        buckets[hash_v1(name) % IPHR_HASH].append((gsi_key(name), off))
    hrs, bitmap, starts, n = [], [0] * ((IPHR_HASH + 32) // 32), [], 0
    for i, b in enumerate(buckets):
        if not b:
            continue
        bitmap[i // 32] |= 1 << (i % 32)
        starts.append(n * 12)       # offset as if each hash record were 12 bytes (32-bit HROffsetCalc)
        for _, off in sorted(b):
            hrs.append(struct.pack("<II", off + 1, 1))
            n += 1
    body = b"".join(hrs)
    tail = struct.pack(f"<{len(bitmap)}I", *bitmap) + struct.pack(f"<{len(starts)}I", *starts)
    return struct.pack("<IIII", 0xFFFFFFFF, 0xEFFE0000 + 19990810, len(body), len(tail)) + body + tail


def tpi_stream(hash_stream):
    return struct.pack("<IIIIIHHII" + "iI" * 3, 20040203, 56, 0x1000, 0x1000, 0, hash_stream, NIL,
                       4, 0x3FFFF, 0, 0, 0, 0, 0, 0)


def names_stream():
    """Empty /names string table."""
    return struct.pack("<III", 0xEFFEEFFE, 1, 1) + b"\0" + struct.pack("<III", 1, 0, 0)


def info_stream(signature, age, guid, names_index):
    name = b"/names\0"
    capacity = 8
    present = 1 << ((hash_v1(name[:-1]) & 0xFFFF) % capacity)
    return (struct.pack("<III", 20000404, signature, age) + guid
            + struct.pack("<I", len(name)) + name
            + struct.pack("<II", 1, capacity)            # hash table: size, capacity
            + struct.pack("<II", 1, present)              # present bit vector (1 word)
            + struct.pack("<I", 0)                        # deleted bit vector (0 words)
            + struct.pack("<II", 0, names_index)          # "/names" (offset 0) -> stream
            + struct.pack("<I", 20140508))                # feature: VC140


def module_info(stream_index):
    sc = struct.pack("<HHiIIHHII", NIL, 0, 0, 0xFFFFFFFF, 0, 0, 0, 0, 0)    # no section contribution
    rec = (struct.pack("<I", 0) + sc + struct.pack("<HHIIIHHIII", 0, stream_index, 4, 0, 0, 0, 0, 0, 0, 0)
           + b"* Linker *\0" + b"\0")
    return rec + b"\0" * (-len(rec) % 4)


def section_map(pe):
    entries = []
    for i, s in enumerate(pe.sections):
        c = s["chars"]
        flags = 0x8 | 0x100 | (0x1 if c & 0x40000000 else 0) | (0x2 if c & 0x80000000 else 0) \
            | (0x4 if c & 0x20000000 else 0)                               # 32-bit addr, selector, R/W/X
        entries.append(struct.pack("<HHHHHHII", flags, 0, 0, i + 1, NIL, NIL, 0, s["vsize"]))
    entries.append(struct.pack("<HHHHHHII", 0x8 | 0x200, 0, 0, len(pe.sections) + 1, NIL, NIL, 0, 0xFFFFFFFF))
    return struct.pack("<HH", len(entries), len(entries)) + b"".join(entries)


def dbi_stream(age, machine, globals_index, publics_index, symrec_index, modi, secmap, sechdr_index):
    sec_contrib = struct.pack("<I", 0xEFFE0000 + 19970605)
    srcinfo = struct.pack("<HHHH", 1, 0, 0, 0)                     # 1 module, 0 files
    dbg = [NIL] * 11
    dbg[5] = sechdr_index                                          # section header stream
    opt = struct.pack("<11H", *dbg)
    ec = names_stream()                                            # EC (edit-and-continue) names: empty table
    header = struct.pack("<iIIHHHHHHiiiiiIiiHHI", -1, 19990903, age, globals_index, 0x8E0B, publics_index, 0,
                         symrec_index, 0, len(modi), len(sec_contrib), len(secmap), len(srcinfo), 0, 0,
                         len(opt), len(ec), 0, machine, 0)
    return header + modi + sec_contrib + secmap + srcinfo + ec + opt


# --- MSF container ------------------------------------------------------------------------------------------------

def write_msf(path, streams):
    def is_fpm(b):
        return b % BLOCK in (1, 2)

    nxt = [3]

    def alloc(n):
        out = []
        while len(out) < n:
            if not is_fpm(nxt[0]):
                out.append(nxt[0])
            nxt[0] += 1
        return out

    blocks = {}
    stream_blocks = []
    for s in streams:
        bl = alloc(-(-len(s) // BLOCK))
        stream_blocks.append(bl)
        for i, b in enumerate(bl):
            blocks[b] = s[i * BLOCK:(i + 1) * BLOCK]
    directory = struct.pack("<I", len(streams)) + struct.pack(f"<{len(streams)}I", *map(len, streams)) \
        + b"".join(struct.pack(f"<{len(bl)}I", *bl) for bl in stream_blocks)
    dir_blocks = alloc(-(-len(directory) // BLOCK))
    for i, b in enumerate(dir_blocks):
        blocks[b] = directory[i * BLOCK:(i + 1) * BLOCK]
    if len(dir_blocks) > BLOCK // 4:
        die("PDB too large for a single directory block map")
    (map_block,) = alloc(1)
    blocks[map_block] = struct.pack(f"<{len(dir_blocks)}I", *dir_blocks)
    nblocks = nxt[0]
    # free page map: bit set = free; every block up to nblocks is in use
    fpm = bytearray(b"\xff" * BLOCK)
    for b in range(nblocks):
        fpm[b // 8] &= ~(1 << (b % 8)) & 0xFF
    for b in range(nblocks):
        if is_fpm(b):
            blocks[b] = bytes(fpm) if b == 1 else b"\xff" * BLOCK
    blocks[0] = (b"Microsoft C/C++ MSF 7.00\r\n\x1aDS\0\0\0"
                 + struct.pack("<IIIIII", BLOCK, 1, nblocks, len(directory), 0, map_block))
    with open(path, "wb") as f:
        for b in range(nblocks):
            data = blocks.get(b, b"")
            f.write(data + b"\0" * (BLOCK - len(data)))


# --- main -------------------------------------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("build", help="games/<game>/<sha256> folder (or its functions.csv)")
    ap.add_argument("exe", help="your copy of the exe (SHA-256 must match meta.json)")
    ap.add_argument("-o", "--output", help="output .pdb (default: the exe's CodeView PDB file name, next to the exe)")
    ap.add_argument("--min-confidence", choices=["high", "medium", "low"], default="medium")
    a = ap.parse_args()

    d = build_dir(a.build)
    meta = load_meta(d)
    if is_va(meta):
        die(f"{meta['label']} is a console build; PDBs are for Windows PE builds. Use export_symbol_map.py instead.")
    check_exe(a.exe, meta)
    pe = PE(a.exe)

    if pe.codeview:
        guid, age, cv_path = pe.codeview
        default_name = cv_path.replace("\\", "/").rsplit("/", 1)[-1]
    else:
        guid, age, default_name = uuid.uuid4().bytes_le, 1, os.path.splitext(os.path.basename(a.exe))[0] + ".pdb"
        print("warning: the exe has no CodeView record, so debuggers will not pick this PDB up automatically; "
              "load it by hand (see README, 'Builds without a CodeView record').", file=sys.stderr)
    out = a.output or os.path.join(os.path.dirname(os.path.abspath(a.exe)), default_name)

    syms, pubs, skipped = bytearray(), [], 0
    for r in load_functions(d, a.min_confidence):
        loc = pe.section_of(r["rva"])
        if loc is None:
            skipped += 1
            continue
        name = (("maybe_" if r["confidence"] == "low" else "") + r["name"]).encode("utf-8")
        pubs.append((name, len(syms), loc))
        syms += pub32(loc[0], loc[1], name)

    # One global so the globals table is not empty (LLVM-based readers such as lldb crash on an empty one).
    marker = b"nucc_symbols_pdb"
    globals_records = [(marker, len(syms))]
    syms += constant(marker, 1)

    addr_map = [off for _, off, _ in sorted(pubs, key=lambda p: (p[2][0], p[2][1], p[0]))]
    publics_hash = gsi_hash([(n, off) for n, off, _ in pubs])
    publics = (struct.pack("<IIIIHHII", len(publics_hash), 4 * len(addr_map), 0, 0, 0, 0, 0, 0)
               + publics_hash + struct.pack(f"<{len(addr_map)}I", *addr_map))

    # stream indices
    TPI, DBI, IPI, NAMES, GLOBALS, PUBLICS, SYMREC, SECHDR, TPIHASH, IPIHASH, MODULE = range(2, 13)
    streams = [b""] * 13
    streams[1] = info_stream(pe.timestamp or int(time.time()), age, guid, NAMES)
    streams[TPI] = tpi_stream(TPIHASH)
    streams[IPI] = tpi_stream(IPIHASH)
    streams[DBI] = dbi_stream(age, pe.machine, GLOBALS, PUBLICS, SYMREC, module_info(MODULE), section_map(pe), SECHDR)
    streams[NAMES] = names_stream()
    streams[GLOBALS] = gsi_hash(globals_records)
    streams[PUBLICS] = publics
    streams[SYMREC] = bytes(syms)
    streams[SECHDR] = pe.section_headers
    streams[MODULE] = struct.pack("<II", 4, 0)   # CV_SIGNATURE_C13, no symbols, no global refs
    write_msf(out, streams)

    print(f"{out}: {len(pubs)} public symbols ({meta['label']}, min confidence {a.min_confidence}), "
          f"GUID {guid_str(guid)} age {age}" + (f", {skipped} outside any section" if skipped else ""))


if __name__ == "__main__":
    main()
