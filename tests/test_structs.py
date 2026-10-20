"""Every header under structs/ compiles as C11 and declares its layout with offsetof asserts.

    python -m unittest discover -s tests

Needs a C compiler (cc / gcc / clang) on PATH; skipped otherwise."""
import glob
import json
import os
import shutil
import subprocess
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HEADERS = sorted(glob.glob(os.path.join(ROOT, "structs", "*", "*", "*.h")))
CC = shutil.which("cc") or shutil.which("gcc") or shutil.which("clang")


class StructHeaders(unittest.TestCase):
    def test_headers_exist(self):
        self.assertGreater(len(HEADERS), 0)

    @unittest.skipUnless(CC, "no C compiler on PATH")
    def test_headers_compile_c11(self):
        bad = []
        for h in HEADERS:
            r = subprocess.run([CC, "-fsyntax-only", "-x", "c", "-std=c11", h], capture_output=True, text=True)
            if r.returncode:
                bad.append(os.path.relpath(h, ROOT) + ": " + (r.stderr.strip().splitlines() or [""])[0])
        self.assertEqual(bad, [])

    def test_layouts_are_asserted(self):
        # a header either asserts its field offsets or states that a class has no instance state
        missing = [os.path.relpath(h, ROOT) for h in HEADERS
                   if "offsetof" not in open(h, encoding="utf-8").read()
                   and "no instance" not in open(h, encoding="utf-8").read().lower()
                   and "absent" not in open(h, encoding="utf-8").read().lower()]
        self.assertEqual(missing, [])

    def test_build_folders_match_games(self):
        for h in HEADERS:
            game, sha = h.split(os.sep)[-3:-1]
            self.assertTrue(os.path.isfile(os.path.join(ROOT, "games", game, sha, "meta.json")), h)

    def test_index_lists_every_header(self):
        index = json.load(open(os.path.join(ROOT, "structs", "index.json")))
        for h in HEADERS:
            game, group = h.split(os.sep)[-3], os.path.basename(h)[:-2]
            self.assertIn(group, index.get(game, {}), h)


if __name__ == "__main__":
    unittest.main()
