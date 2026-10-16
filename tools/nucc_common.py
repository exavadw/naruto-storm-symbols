"""Shared helpers for the nucc-symbols tools: build folders, functions.csv, SHA-256, minimal PE parsing.

Standard library only (Python 3.8+)."""
import csv
import hashlib
import json
import os
import struct
import sys

RANK = {"low": 1, "medium": 2, "high": 3}


def die(msg):
    sys.exit(f"error: {msg}")


def build_dir(path):
    """Accept a build folder, its functions.csv or its meta.json; return the folder."""
    path = os.path.abspath(path)
    d = path if os.path.isdir(path) else os.path.dirname(path)
    if not os.path.exists(os.path.join(d, "meta.json")):
        die(f"no meta.json in {d} (expected games/<game>/<sha256>/)")
    return d


def load_meta(d):
    with open(os.path.join(d, "meta.json"), encoding="utf-8") as f:
        return json.load(f)


def is_va(meta):
    """Console builds list absolute VAs; PC builds list RVAs."""
    return meta.get("address_kind", "").startswith("VA")


def load_functions(d, min_confidence="low"):
    """Rows of functions.csv at or above min_confidence, with 'rva' parsed to int."""
    out = []
    with open(os.path.join(d, "functions.csv"), newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if RANK[r["confidence"]] >= RANK[min_confidence]:
                r["rva"] = int(r["rva"], 16)
                out.append(r)
    return out


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def check_exe(exe, meta):
    have = sha256_file(exe)
    if have != meta["exe_sha256"].lower():
        die(f"SHA-256 mismatch:\n  {exe}: {have}\n  names are for: {meta['exe_sha256']} ({meta['label']})")


class PE:
    """Just enough of a PE/COFF image: machine, timestamp, image base, sections, CodeView (RSDS) record."""

    def __init__(self, path):
        with open(path, "rb") as f:
            self.data = data = f.read()
        if data[:2] != b"MZ":
            die(f"{path} is not a PE file")
        pe = struct.unpack_from("<I", data, 0x3C)[0]
        if data[pe:pe + 4] != b"PE\0\0":
            die(f"{path} is not a PE file")
        self.machine, nsec, self.timestamp, _, _, opt_size, _ = struct.unpack_from("<HHIIIHH", data, pe + 4)
        opt = pe + 24
        magic = struct.unpack_from("<H", data, opt)[0]
        self.pe32plus = magic == 0x20B
        self.image_base = struct.unpack_from("<Q" if self.pe32plus else "<I", data, opt + (24 if self.pe32plus else 28))[0]
        self.size_of_image = struct.unpack_from("<I", data, opt + 56)[0]
        ndirs_off = opt + (108 if self.pe32plus else 92)
        ndirs = struct.unpack_from("<I", data, ndirs_off)[0]
        dirs = [struct.unpack_from("<II", data, ndirs_off + 4 + 8 * i) for i in range(ndirs)]
        sec = opt + opt_size
        self.section_headers = data[sec:sec + 40 * nsec]       # raw IMAGE_SECTION_HEADERs (copied into the PDB)
        self.sections = []
        for i in range(nsec):
            name, vsize, va, rawsize, rawptr = struct.unpack_from("<8sIIII", data, sec + 40 * i)
            chars = struct.unpack_from("<I", data, sec + 40 * i + 36)[0]
            self.sections.append(dict(name=name.rstrip(b"\0").decode("latin-1"), vsize=vsize, va=va,
                                      rawsize=rawsize, rawptr=rawptr, chars=chars))
        self.codeview = None                                   # (guid bytes, age, pdb path)
        if len(dirs) > 6 and dirs[6][0]:
            dbg_rva, dbg_size = dirs[6]
            dbg = self.rva_to_offset(dbg_rva)
            for i in range(dbg_size // 28):
                typ, size, _, ptr = struct.unpack_from("<IIII", data, dbg + 28 * i + 12)
                if typ == 2 and data[ptr:ptr + 4] == b"RSDS":
                    guid = data[ptr + 4:ptr + 20]
                    age = struct.unpack_from("<I", data, ptr + 20)[0]
                    path = data[ptr + 24:ptr + size].split(b"\0")[0].decode("utf-8", "replace")
                    self.codeview = (guid, age, path)

    def rva_to_offset(self, rva):
        for s in self.sections:
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["rawsize"]):
                return rva - s["va"] + s["rawptr"]
        die(f"RVA {rva:#x} is outside every section")

    def section_of(self, rva):
        """(1-based section index, offset in section), or None."""
        for i, s in enumerate(self.sections):
            if s["va"] <= rva < s["va"] + max(s["vsize"], s["rawsize"]):
                return i + 1, rva - s["va"]
        return None

    def is_code(self, rva):
        sec = self.section_of(rva)
        return sec is not None and bool(self.sections[sec[0] - 1]["chars"] & 0x20000000)   # IMAGE_SCN_MEM_EXECUTE


def guid_str(g):
    d1, d2, d3 = struct.unpack_from("<IHH", g)
    return f"{{{d1:08X}-{d2:04X}-{d3:04X}-{g[8:10].hex().upper()}-{g[10:].hex().upper()}}}"
