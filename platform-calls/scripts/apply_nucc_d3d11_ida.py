"""apply_nucc_d3d11_ida.py: annotate Direct3D 11 / DXGI COM calls and platform imports (nucc-d3d11 package) in IDA 7.4+.

File > Script file..., then pick calls.csv in the folder for this exact exe (meta.json beside it is checked against the
input file's SHA-256). Comments only: "[d3d11] ID3D11DeviceContext::DrawIndexed" at each call site, plus a function
comment line listing what the function uses. Nothing is renamed."""
import csv, json, os

import ida_kernwin, ida_nalt, idaapi, idc


def main():
    path = ida_kernwin.ask_file(0, "calls.csv", "nucc-d3d11 calls.csv for this exe")
    if not path:
        return
    d = os.path.dirname(path)
    meta = os.path.join(d, "meta.json")
    if os.path.exists(meta):
        want = json.load(open(meta))["exe_sha256"].lower()
        have = (ida_nalt.retrieve_input_file_sha256() or b"").hex().lower()
        if have != want:
            ida_kernwin.warning(f"SHA-256 mismatch:\nthis database: {have}\ndata is for: {want}\nNot applying.")
            return
    base = idaapi.get_imagebase()
    per_func, sites = {}, 0
    for fname, kind in (("calls.csv", "d3d11"), ("imports.csv", "import")):
        p = os.path.join(d, fname)
        if not os.path.exists(p):
            continue
        for r in csv.DictReader(open(p, newline="", encoding="utf-8")):
            fa, ca = base + int(r["function_rva"], 16), base + int(r["call_rva"], 16)
            what = f"{r['interface']}::{r['method']}" if kind == "d3d11" else r["import"]
            tag = f"[{kind}] {what}"
            old = idc.get_cmt(ca, 0) or ""
            if tag not in old:
                idc.set_cmt(ca, (old + "; " + tag).strip("; "), 0)
                sites += 1
            per_func.setdefault(fa, set()).add(r["method"] if kind == "d3d11" else what)
    for fa, uses in per_func.items():
        old = idc.get_func_cmt(fa, 0) or ""
        if "[d3d11/platform]" not in old:
            idc.set_func_cmt(fa, (old + "\n[d3d11/platform] " + ", ".join(sorted(uses))).strip(), 0)
    print(f"[nucc-d3d11] {sites} call sites commented in {len(per_func)} functions")


main()
