# Changelog

## 1.1.0 (2026-10-16)

Data update: 144,211 names in total, up from 139,450. Same 10 builds, same file format; scripts and tools are
unchanged.

- **New name source:** the Storm 1 mobile (Android arm64) build's exported C++ symbols, carried to the PC builds by
  strings, BSim and call-graph position (method `mobile-symbol`). 28,863 rows now cite it.
- **Changes against 1.0.0, all builds:**
  - 7,164 names added and 2,403 removed;
  - 3,582 addresses renamed;
  - 8,130 names raised in confidence.
- **Coverage now:**
  - Storm 1: 54%; Storm 1 debug: 46%;
  - Storm 2: 52%; Storm 3 HD: 54%; Storm 3 Full Burst: 36%; Revolution: 29%;
  - Storm 4 debug: 22%; Storm 4 release: 24%;
  - Connections: 18%; Generations 360: 15%.

  The README table has the per-confidence counts.
- **Removed 4 bad Connections rows that were also in 1.0.0:**
  - an `rtti-vtable` entry with a negative address (`ccAdvBaseDraw::GetCoordPos`);
  - three data exports that were listed as functions: `NvOptimusEnablement`, `AmdPowerXpressRequestHighPerformance`
    and Scaleform's `HasMemoryLeaks` flag. Applying them would have created functions on data.
- Generations `counterparts.csv`: the same 12,926 functions; the `name`/`confidence` columns follow the new names
  (227 rows changed).
- README: `fill-similar` documented, with its hold-out accuracy (95% medium, 89% low). Standard MIT licence text, so
  GitHub detects it.

Verification: the tool tests, the exporters (PDB, x64dbg database, symbol map) and the validator were rerun against
the new data, and the repository audit was repeated. A new check found the 4 bad rows above. Every remaining row
has a valid address, and for the 5 PC builds available locally every address is inside an executable section.

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
