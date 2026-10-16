"""binja_apply_nucc_names.py: apply NUCC function names (functions.csv) in Binary Ninja (4.x, Python 3).

Open the exe, then run this file from the scripting console (`exec(open(r"...binja_apply_nucc_names.py").read())`)
or via File > Run Script, and pick the functions.csv for this exact exe (meta.json beside it is checked against the
file's SHA-256; a mismatch aborts).
  high   -> renamed
  medium -> renamed + function comment "[nucc medium <methods>]"
  low    -> name kept; function comment "[nucc low] maybe <name> (<methods>)"
Set MIN_CONFIDENCE below to "medium" or "high" to apply fewer names.
Untested in Binary Ninja itself (written against the documented API); please report problems."""
import csv
import hashlib
import json
import os

from binaryninja import interaction

MIN_CONFIDENCE = "low"
RANK = {"low": 1, "medium": 2, "high": 3}


def append(old, text):
    old = old or ""
    return old if text in old else (old + "\n" + text).strip()


def apply_names(bv, path):
    meta = os.path.join(os.path.dirname(path), "meta.json")
    va = False
    if os.path.exists(meta):
        with open(meta, encoding="utf-8") as f:
            mj = json.load(f)
        va = mj.get("address_kind", "").startswith("VA")
        raw = bv.file.raw
        have = hashlib.sha256(raw.read(0, raw.length)).hexdigest()
        if have != mj["exe_sha256"].lower():
            interaction.show_message_box("NUCC names", f"SHA-256 mismatch:\nthis file: {have}\n"
                                         f"names are for: {mj['exe_sha256']}\nNot applying.")
            return
    else:
        print("[nucc] warning: no meta.json beside the CSV; skipping the SHA-256 check")
    base = 0 if va else bv.start            # PE views start at the image base; console builds list absolute VAs
    renamed = commented = created = skipped = 0
    with open(path, newline="", encoding="utf-8") as f:
        rows = [r for r in csv.DictReader(f) if RANK[r["confidence"]] >= RANK[MIN_CONFIDENCE]]
    for r in rows:
        ea = base + int(r["rva"], 16)
        if bv.get_function_at(ea) is None:
            bv.create_user_function(ea)
            created += 1
    bv.update_analysis_and_wait()
    for r in rows:
        ea = base + int(r["rva"], 16)
        fn = bv.get_function_at(ea)
        if fn is None:
            skipped += 1
            continue
        if r["confidence"] == "low":
            fn.comment = append(fn.comment, f"[nucc low] maybe {r['name']} ({r['methods']})")
            commented += 1
            continue
        fn.name = r["name"]
        renamed += 1
        if r["confidence"] == "medium":
            fn.comment = append(fn.comment, f"[nucc medium {r['methods']}]")
    print(f"[nucc] {renamed} renamed, {commented} comment-only, {created} functions created, {skipped} skipped")


if "bv" in globals():
    _path = interaction.get_open_filename_input("NUCC functions.csv for this exe", "*.csv")
    if _path:
        apply_names(bv, _path.decode() if isinstance(_path, bytes) else _path)  # noqa: F821 (bv from Binary Ninja)
