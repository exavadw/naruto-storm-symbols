# Changelog

## 1.0.0 (2026-10-16)

First public release.

- **Names** for 10 builds, 139,450 in total: Storm 1 (release and debug), Storm 2, Storm 3 HD, Storm 3 Full Burst
  (2014), Storm Revolution, Storm 4 (debug 1.06 and release), Storm Connections, and Storm Generations (Xbox 360
  retail, USA).
- **Apply scripts** for Ghidra (`ApplyNuccNames.java`) and IDA (`apply_nucc_names_ida.py`), plus a Binary Ninja
  script (`binja_apply_nucc_names.py`) that has not been tested in Binary Ninja itself. All three check the exe's
  SHA-256.
- **Exporters** in `tools/`:
  - `make_pdb.py` writes a PDB of public symbols with the exe's own GUID and age, for x64dbg, WinDbg and Visual
    Studio.
  - `export_x64dbg.py` writes an x64dbg database (labels and comments).
  - `export_symbol_map.py` writes a plain `address name` map.
- **Contribution validator**: `tools/validate_contribution.py`.
- **Platform-call annotations** (`platform-calls/`): DLL import calls and proven Direct3D COM calls for the PC
  builds.
- The `mangled` column of the internal data set (Itanium-mangled names copied from the Switch build) is **not**
  included. `name`, `namespace` and `short_name` carry the same information in readable form.

Verification for this release:

- PDBs were generated for Storm 1, 2, 3 HD, 4 debug and 4 release. They pass `llvm-pdbutil dump -all` and are accepted
  as matched by LLDB (which rejects a PDB whose GUID was altered). The Storm 1 (age 1) and Storm 4 release (age 21)
  PDBs resolve names both ways in Microsoft DbgHelp: 8 of 8 sampled addresses and 4 of 4 names each.
- The x64dbg database, symbol map and validator outputs were checked row by row against `functions.csv`.
