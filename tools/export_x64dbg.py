#!/usr/bin/env python3
"""export_x64dbg.py: write an x64dbg database (labels + comments) for one PC build.

    python tools/export_x64dbg.py games/storm4/<sha256> [--module NSUNS4.exe] [-o NSUNS4.exe.dd64] [--exe NSUNS4.exe]

Load it in x64dbg with File > Database > Import database (or the command `dbload <path>`) while the game is being
debugged, or copy it to x64dbg's db folder as `<exe file name>.dd64` (x32dbg: `.dd32`) before starting.

  high   -> label
  medium -> label + comment "[nucc medium <methods>]"
  low    -> comment only "[nucc low] maybe <name> (<methods>)"
Names longer than x64dbg's 255-character label limit go into a comment instead.

--module must be the exe's file name as x64dbg sees it (case does not matter); it defaults to the name in meta.json.
Pass --exe to check your copy's SHA-256 first.
"""
import argparse
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from nucc_common import build_dir, check_exe, die, is_va, load_functions, load_meta  # noqa: E402

MAX_LABEL = 255     # x64dbg MAX_LABEL_SIZE (256) minus the terminator
MAX_COMMENT = 511   # x64dbg MAX_COMMENT_SIZE (512) minus the terminator


def default_module(meta):
    m = re.search(r"\(([^()]+\.exe)\)", meta["label"])
    return m.group(1) if m else None


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("build", help="games/<game>/<sha256> folder (or its functions.csv)")
    ap.add_argument("--module", help="exe file name as loaded in x64dbg (default: from meta.json)")
    ap.add_argument("-o", "--output", help="output file (default: <module>.dd64 / .dd32 in the current folder)")
    ap.add_argument("--exe", help="your copy of the exe, to check its SHA-256")
    ap.add_argument("--min-confidence", choices=["high", "medium", "low"], default="low")
    a = ap.parse_args()

    d = build_dir(a.build)
    meta = load_meta(d)
    if is_va(meta):
        die(f"{meta['label']} is a console build; x64dbg debugs Windows programs.")
    if a.exe:
        check_exe(a.exe, meta)
    module = a.module or (os.path.basename(a.exe) if a.exe else default_module(meta))
    if not module:
        die(f"meta.json does not name the exe for {meta['label']}; pass --module <exe file name>")
    ext = ".dd64" if int(meta["image_base"], 16) > 0xFFFFFFFF else ".dd32"
    out = a.output or module + ext

    labels, comments = [], []
    for r in load_functions(d, a.min_confidence):
        addr = f"0x{r['rva']:X}"
        name, conf, methods = r["name"], r["confidence"], r["methods"]
        notes = []
        if conf == "low":
            notes.append(f"[nucc low] maybe {name} ({methods})")
        elif len(name) > MAX_LABEL:
            notes.append(f"[nucc {conf} {methods}] {name}")
        else:
            labels.append({"module": module, "address": addr, "manual": True, "text": name})
            if conf == "medium":
                notes.append(f"[nucc medium {methods}]")
        for text in notes:
            comments.append({"module": module, "address": addr, "manual": True, "text": text[:MAX_COMMENT]})

    with open(out, "w", encoding="utf-8") as f:
        json.dump({"labels": labels, "comments": comments}, f, indent=1)
    print(f"{out}: {len(labels)} labels, {len(comments)} comments for module {module} ({meta['label']})")


if __name__ == "__main__":
    main()
