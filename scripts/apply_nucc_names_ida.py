"""apply_nucc_names_ida.py: apply NUCC function names (functions.csv) in IDA Pro 7.4+ / 8.x / 9.x (IDAPython 3).

File > Script file..., then pick the functions.csv for this exact exe (meta.json beside it is checked against
the input file's SHA-256; a mismatch aborts).
  high   -> renamed
  medium -> renamed + function comment "[nucc medium <methods>]"
  low    -> name kept; function comment "[nucc low] maybe <name> (<methods>)"
Qualified names keep their "::" (IDA shows them like PDB names). Duplicate names get IDA's numeric suffix.
Set MIN_CONFIDENCE below to "medium" or "high" to apply fewer names."""
import csv, json, os

import ida_funcs, ida_kernwin, ida_nalt, idaapi, idc

MIN_CONFIDENCE = "low"
RANK = {"low": 1, "medium": 2, "high": 3}


def main():
    path = ida_kernwin.ask_file(0, "*.csv", "NUCC functions.csv for this exe")
    if not path:
        return
    meta = os.path.join(os.path.dirname(path), "meta.json")
    va = False
    if os.path.exists(meta):
        mj = json.load(open(meta)); va = mj.get("address_kind", "").startswith("VA")
        want = mj["exe_sha256"].lower()
        have = (ida_nalt.retrieve_input_file_sha256() or b"").hex().lower()
        if have != want:
            ida_kernwin.warning(f"SHA-256 mismatch:\nthis database: {have}\nnames are for: {want}\nNot applying.")
            return
    else:
        print("[nucc] warning: no meta.json beside the CSV; skipping the SHA-256 check")
    base = 0 if va else idaapi.get_imagebase()     # console builds list absolute VAs
    flags = idc.SN_NOWARN | idc.SN_NOCHECK | getattr(idc, "SN_FORCE", 0)
    renamed = commented = created = skipped = 0
    for r in csv.DictReader(open(path, newline="", encoding="utf-8")):
        if RANK[r["confidence"]] < RANK[MIN_CONFIDENCE]:
            skipped += 1
            continue
        ea = base + int(r["rva"], 16)
        if ida_funcs.get_func(ea) is None or ida_funcs.get_func(ea).start_ea != ea:
            if not ida_funcs.add_func(ea):
                skipped += 1
                continue
            created += 1
        if r["confidence"] == "low":
            idc.set_func_cmt(ea, append(idc.get_func_cmt(ea, 0), f"[nucc low] maybe {r['name']} ({r['methods']})"), 0)
            commented += 1
            continue
        if idc.set_name(ea, r["name"], flags):
            renamed += 1
        else:
            idc.set_func_cmt(ea, append(idc.get_func_cmt(ea, 0), f"[nucc] {r['name']} (rename failed)"), 0)
            commented += 1
            continue
        if r["confidence"] == "medium":
            idc.set_func_cmt(ea, append(idc.get_func_cmt(ea, 0), f"[nucc medium {r['methods']}]"), 0)
    print(f"[nucc] {renamed} renamed, {commented} comment-only, {created} functions created, {skipped} skipped")


def append(old, text):
    old = old or ""
    return old if text in old else (old + "\n" + text).strip()


main()
