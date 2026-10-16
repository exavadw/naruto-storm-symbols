#!/usr/bin/env python3
"""export_symbol_map.py: write a plain `address name` symbol map for one build (one line per function, sorted).

    python tools/export_symbol_map.py games/storm4/<sha256> [-o NSUNS4.map] [--rva] [--min-confidence medium]

Addresses are absolute (image base + RVA) unless --rva is given; console builds are always absolute. Useful for
Cheat Engine / ReClass / radare2 / custom tooling, or any tool that imports "address name" lists.
Default is high + medium; with --min-confidence low, low-confidence names are written as "maybe_<name>".
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from nucc_common import build_dir, is_va, load_functions, load_meta  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("build", help="games/<game>/<sha256> folder (or its functions.csv)")
    ap.add_argument("-o", "--output", help="output file (default: stdout)")
    ap.add_argument("--rva", action="store_true", help="write RVAs instead of absolute addresses (PC builds)")
    ap.add_argument("--min-confidence", choices=["high", "medium", "low"], default="medium")
    a = ap.parse_args()

    d = build_dir(a.build)
    meta = load_meta(d)
    base = 0 if a.rva or is_va(meta) else int(meta["image_base"], 16)
    width = 16 if int(meta["image_base"], 16) > 0xFFFFFFFF and base else 8
    lines = [f"{base + r['rva']:0{width}X} {'maybe_' if r['confidence'] == 'low' else ''}{r['name']}"
             for r in sorted(load_functions(d, a.min_confidence), key=lambda r: r["rva"])]
    text = "\n".join(lines) + "\n"
    if a.output:
        with open(a.output, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        print(f"{a.output}: {len(lines)} symbols ({meta['label']})", file=sys.stderr)
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main()
