#!/usr/bin/env python3
"""validate_contribution.py: check a contributed names CSV before it is merged.

    python tools/validate_contribution.py contrib/storm4/<sha256>/yourname.csv [--exe NSUNS4.exe] [--strict]
    python tools/validate_contribution.py my_names.csv --build games/storm4/<sha256>

Format (see CONTRIBUTING.md): header `rva,name,confidence,method,src_rva,evidence`.

The build is taken from --build, or from the 64-hex-digit SHA-256 folder in the CSV's path. Errors (exit 1): bad
header or values, the same address given two different names, a SHA-256 mismatch with --exe, an address outside the
exe's code with --exe. Warnings (exit 0, or 1 with --strict): an address the package already names differently
(conflict), a name the package already uses at another address, rows repeated verbatim, high/medium rows without
evidence.
"""
import argparse
import csv
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from nucc_common import PE, build_dir, die, is_va, load_functions, load_meta, sha256_file  # noqa: E402

HEADER = ["rva", "name", "confidence", "method", "src_rva", "evidence"]
HEX = re.compile(r"0x[0-9a-fA-F]+$")
METHOD = re.compile(r"[a-z0-9_.\-]+(?:[+>][a-z0-9_.\-]+)*(?:;[a-z0-9_.\-]+(?:[+>][a-z0-9_.\-]+)*)*$")
PLACEHOLDER = re.compile(r"(?:FUN|SUB|LAB|DAT|thunk_FUN|nullsub|sub|loc|j_sub|unknown|func)_[0-9a-fA-F]+$")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def find_build(csv_path):
    here = os.path.dirname(os.path.abspath(csv_path))
    if os.path.exists(os.path.join(here, "meta.json")):          # CSV dropped into the build folder itself
        return here
    m = re.search(r"(?:^|[\\/])([0-9a-fA-F]{64})(?:[\\/]|$)", os.path.abspath(csv_path))
    if not m:
        die("cannot tell which build this is for: put the CSV under a <sha256> folder or pass --build")
    hits = glob.glob(os.path.join(REPO, "games", "*", m.group(1).lower()))
    if not hits:
        die(f"no build with SHA-256 {m.group(1)} under games/")
    return hits[0]


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("csv", help="the contribution CSV")
    ap.add_argument("--build", help="games/<game>/<sha256> folder (default: from the CSV's path)")
    ap.add_argument("--exe", help="your copy of the exe: checks its SHA-256 and that each address is in code")
    ap.add_argument("--strict", action="store_true", help="treat warnings as errors")
    a = ap.parse_args()

    d = build_dir(a.build) if a.build else find_build(a.csv)
    meta = load_meta(d)
    errors, warnings = [], []

    m = re.search(r"(?:^|[\\/])([0-9a-fA-F]{64})(?:[\\/]|$)", os.path.abspath(a.csv))
    if m and m.group(1).lower() != meta["exe_sha256"].lower():
        errors.append(f"path says SHA-256 {m.group(1)} but the build is {meta['exe_sha256']}")

    pe = None
    if a.exe:
        have = sha256_file(a.exe)
        if have != meta["exe_sha256"].lower():
            errors.append(f"--exe SHA-256 {have} does not match the build ({meta['exe_sha256']}, {meta['label']})")
        elif is_va(meta):
            warnings.append("console build: --exe address checks are skipped (addresses are VAs in the XEX image)")
        else:
            pe = PE(a.exe)

    known = {r["rva"]: r["name"] for r in load_functions(d)}
    known_names = {}
    for rva, name in known.items():
        known_names.setdefault(name, []).append(rva)

    seen = {}
    with open(a.csv, newline="", encoding="utf-8-sig") as f:
        rd = csv.reader(f)
        header = next(rd, None)
        if header != HEADER:
            die(f"{a.csv}:1: header must be exactly: {','.join(HEADER)} (got {header})")
        for row in rd:
            ln = rd.line_num
            where = f"{a.csv}:{ln}"
            if not any(c.strip() for c in row):
                continue
            if len(row) != len(HEADER):
                errors.append(f"{where}: expected {len(HEADER)} columns, got {len(row)} (quote names that contain commas)")
                continue
            rva_s, name, conf, method, src, evidence = row
            if not HEX.match(rva_s):
                errors.append(f"{where}: rva '{rva_s}' is not hex like 0x1a2b")
                continue
            rva = int(rva_s, 16)
            if not name or name != name.strip() or any(ord(c) < 32 for c in name):
                errors.append(f"{where}: empty name, or leading/trailing spaces or control characters")
            elif PLACEHOLDER.match(name.split("::")[-1]):
                errors.append(f"{where}: '{name}' is a tool placeholder, not a real name")
            if conf not in ("high", "medium", "low"):
                errors.append(f"{where}: confidence must be high, medium or low (got '{conf}')")
            if not METHOD.match(method):
                errors.append(f"{where}: method '{method}' must be lowercase tags like manual or manual+llm-disputed")
            if src and not HEX.match(src):
                errors.append(f"{where}: src_rva '{src}' must be empty or hex")
            if not evidence.strip() and conf in ("high", "medium"):
                warnings.append(f"{where}: {conf} name without evidence; say how you know")
            if pe is not None and not pe.is_code(rva):
                errors.append(f"{where}: {rva_s} is not inside an executable section of the exe")

            if rva in seen:
                prev_ln, prev_name = seen[rva]
                if prev_name == name:
                    warnings.append(f"{where}: duplicate of line {prev_ln} ({rva_s} {name})")
                else:
                    errors.append(f"{where}: {rva_s} named '{name}' here but '{prev_name}' on line {prev_ln}")
                continue
            seen[rva] = (ln, name)

            if rva in known and known[rva] != name:
                warnings.append(f"{where}: CONFLICT {rva_s}: package says '{known[rva]}', contribution says '{name}'")
            elif rva in known:
                warnings.append(f"{where}: {rva_s} {name} is already in the package (raises confidence only)")
            others = [x for x in known_names.get(name, []) if x != rva]
            if others:
                warnings.append(f"{where}: '{name}' is already used at {', '.join(hex(x) for x in others[:3])} "
                                "(fine for overloads or duplicated code; otherwise one of them is wrong)")

    for e in errors:
        print("ERROR  " + e)
    for w in warnings:
        print("WARN   " + w)
    print(f"{len(seen)} names checked against {meta['label']}: {len(errors)} errors, {len(warnings)} warnings")
    sys.exit(1 if errors or (a.strict and warnings) else 0)


if __name__ == "__main__":
    main()
