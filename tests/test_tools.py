"""End-to-end tests for tools/ on a synthetic PE (no game files needed).

    python -m unittest discover -s tests

If llvm-pdbutil is on PATH, the generated PDB is also checked with it."""
import csv
import hashlib
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest

TOOLS = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools")
GUID = bytes(range(16))
AGE = 7
BASE = 0x140000000
ROWS = [  # rva, name, confidence, methods
    (0x1000, "ccTest::Update", "high", "selfname"),
    (0x1040, "ccTest::Draw", "medium", "vtable"),
    (0x1080, "criTest_Init", "low", "fill-callees"),
    (0x10C0, "std::map<int,int>::find", "high", "switch-string"),
]


def synthetic_pe():
    """x64 PE: .text at RVA 0x1000, .rdata at 0x2000 holding a debug directory with an RSDS record."""
    pdb_path = b"D:\\build\\obj\\test_Release_x64.pdb\0"
    img = bytearray(0x800)
    img[0:2] = b"MZ"
    struct.pack_into("<I", img, 0x3C, 0x40)
    img[0x40:0x44] = b"PE\0\0"
    struct.pack_into("<HHIIIHH", img, 0x44, 0x8664, 2, 0x5F000000, 0, 0, 240, 0x22)
    opt = 0x58
    struct.pack_into("<H", img, opt, 0x20B)
    struct.pack_into("<Q", img, opt + 24, BASE)
    struct.pack_into("<I", img, opt + 56, 0x3000)
    struct.pack_into("<I", img, opt + 108, 16)
    struct.pack_into("<II", img, opt + 112 + 6 * 8, 0x2000, 28)            # debug directory
    sec = opt + 240
    struct.pack_into("<8sIIII", img, sec, b".text", 0x1000, 0x1000, 0x200, 0x400)
    struct.pack_into("<I", img, sec + 36, 0x60000020)
    struct.pack_into("<8sIIII", img, sec + 40, b".rdata", 0x1000, 0x2000, 0x200, 0x600)
    struct.pack_into("<I", img, sec + 76, 0x40000040)
    rsds = b"RSDS" + GUID + struct.pack("<I", AGE) + pdb_path
    struct.pack_into("<IIHHIIII", img, 0x600, 0, 0, 0, 0, 2, len(rsds), 0x2040, 0x640)
    img[0x640:0x640 + len(rsds)] = rsds
    return bytes(img)


class Msf:
    """Minimal MSF reader for checking the generated PDB."""

    def __init__(self, path):
        with open(path, "rb") as f:
            d = f.read()
        assert d.startswith(b"Microsoft C/C++ MSF 7.00\r\n\x1aDS\0\0\0")
        bs, _, nblocks, dir_bytes, _, map_addr = struct.unpack_from("<IIIIII", d, 32)
        assert len(d) == bs * nblocks
        ndir = -(-dir_bytes // bs)
        dir_blocks = struct.unpack_from(f"<{ndir}I", d, map_addr * bs)
        directory = b"".join(d[b * bs:(b + 1) * bs] for b in dir_blocks)[:dir_bytes]
        n = struct.unpack_from("<I", directory)[0]
        sizes = struct.unpack_from(f"<{n}I", directory, 4)
        pos, self.streams = 4 + 4 * n, []
        for size in sizes:
            k = -(-size // bs)
            blocks = struct.unpack_from(f"<{k}I", directory, pos)
            pos += 4 * k
            self.streams.append(b"".join(d[b * bs:(b + 1) * bs] for b in blocks)[:size])


class ToolsTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.mkdtemp()
        cls.exe = os.path.join(cls.tmp, "TEST.exe")
        data = synthetic_pe()
        with open(cls.exe, "wb") as f:
            f.write(data)
        sha = hashlib.sha256(data).hexdigest()
        cls.build = os.path.join(cls.tmp, "games", "test", sha)
        os.makedirs(cls.build)
        with open(os.path.join(cls.build, "meta.json"), "w") as f:
            json.dump({"label": "Test PC (TEST.exe)", "game": "test", "exe_sha256": sha, "image_base": hex(BASE),
                       "address_kind": "RVA (add image_base for VA)"}, f)
        with open(os.path.join(cls.build, "functions.csv"), "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["rva", "size", "name", "namespace", "short_name", "confidence", "self_named", "methods",
                        "sources", "conflict_with", "evidence"])
            for rva, name, conf, methods in ROWS:
                w.writerow([hex(rva), 16, name, "", name, conf, False, methods, 1, "", ""])

    @classmethod
    def tearDownClass(cls):
        shutil.rmtree(cls.tmp)

    def run_tool(self, *args, ok=True):
        p = subprocess.run([sys.executable, os.path.join(TOOLS, args[0]), *args[1:]], capture_output=True, text=True,
                           cwd=self.tmp)
        if ok:
            self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
        return p

    def test_pdb_matches_exe_and_maps_names(self):
        self.run_tool("make_pdb.py", self.build, self.exe)
        pdb = os.path.join(self.tmp, "test_Release_x64.pdb")      # name from the exe's CodeView record
        msf = Msf(pdb)
        info = msf.streams[1]
        self.assertEqual(struct.unpack_from("<I", info, 8)[0], AGE)
        self.assertEqual(info[12:28], GUID)
        dbi = msf.streams[3]
        self.assertEqual(struct.unpack_from("<I", dbi, 8)[0], AGE)
        publics_idx, symrec_idx = struct.unpack_from("<H", dbi, 16)[0], struct.unpack_from("<H", dbi, 20)[0]
        publics, symrec = msf.streams[publics_idx], msf.streams[symrec_idx]
        n = struct.unpack_from("<I", publics, 4)[0] // 4
        addr_map = struct.unpack_from(f"<{n}I", publics, len(publics) - 4 * n)
        got = []
        for off in addr_map:
            _, kind, flags, sec_off, seg = struct.unpack_from("<HHIIH", symrec, off)
            name = symrec[off + 14:symrec.index(b"\0", off + 14)].decode()
            self.assertEqual((kind, flags, seg), (0x110E, 2, 1))
            got.append((0x1000 + sec_off, name))
        want = [(rva, name) for rva, name, conf, _ in ROWS if conf != "low"]
        self.assertEqual(got, want)                                # default: high + medium, sorted by address
        if shutil.which("llvm-pdbutil"):
            p = subprocess.run(["llvm-pdbutil", "dump", "-all", pdb], capture_output=True, text=True)
            self.assertEqual(p.returncode, 0, p.stderr)

    def test_pdb_refuses_wrong_exe(self):
        other = os.path.join(self.tmp, "other.exe")
        with open(other, "wb") as f:
            f.write(synthetic_pe() + b"x")
        p = self.run_tool("make_pdb.py", self.build, other, ok=False)
        self.assertNotEqual(p.returncode, 0)
        self.assertIn("SHA-256 mismatch", p.stderr)

    def test_x64dbg_policy(self):
        self.run_tool("export_x64dbg.py", self.build, "--exe", self.exe, "-o", "t.dd64")
        with open(os.path.join(self.tmp, "t.dd64")) as f:
            db = json.load(f)
        labels = {l["address"]: l["text"] for l in db["labels"]}
        comments = {c["address"]: c["text"] for c in db["comments"]}
        self.assertEqual(labels, {"0x1000": "ccTest::Update", "0x1040": "ccTest::Draw", "0x10C0": "std::map<int,int>::find"})
        self.assertEqual(comments, {"0x1040": "[nucc medium vtable]",
                                    "0x1080": "[nucc low] maybe criTest_Init (fill-callees)"})
        self.assertTrue(all(x["module"] == "TEST.exe" for x in db["labels"] + db["comments"]))

    def test_symbol_map(self):
        out = self.run_tool("export_symbol_map.py", self.build, "--min-confidence", "low").stdout.splitlines()
        self.assertEqual(out[2], "0000000140001080 maybe_criTest_Init")
        self.assertEqual(len(out), 4)

    def test_validator(self):
        contrib = os.path.join(self.build, "contrib.csv")
        with open(contrib, "w", newline="") as f:
            f.write("rva,name,confidence,method,src_rva,evidence\n"
                    "0x1100,ccTest::New,high,manual,,string 'ccTest::New' in its assert\n"
                    "0x1000,ccTest::Other,medium,manual,,conflicts with the package\n")
        p = self.run_tool("validate_contribution.py", contrib, "--exe", self.exe)
        self.assertIn("CONFLICT 0x1000", p.stdout)
        p = self.run_tool("validate_contribution.py", contrib, "--strict", ok=False)
        self.assertEqual(p.returncode, 1)
        with open(contrib, "a") as f:
            f.write("0x10,HeaderNotCode,low,manual,,x\n0x1100,ccTest::Clash,low,manual,,x\n")
        p = self.run_tool("validate_contribution.py", contrib, "--exe", self.exe, ok=False)
        self.assertEqual(p.returncode, 1)
        self.assertIn("not inside an executable section", p.stdout)
        self.assertIn("named 'ccTest::Clash' here but 'ccTest::New'", p.stdout)


if __name__ == "__main__":
    unittest.main()
