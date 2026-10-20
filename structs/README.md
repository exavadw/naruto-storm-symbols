# Struct layouts

C11 headers describing in-memory layouts of classes in the Storm PC builds, one folder per build (same folder names as
`games/`: `<game>/<exe sha256>/`). Each group has `<group>.h` (packed structs with explicit padding and one
`static_assert(offsetof(...))` per field) and `<group>-fields.tsv` (offset, size, type, read/write, name, confidence,
evidence). `index.json` lists the struct types each header defines.

| Build | Headers | Struct types |
|---|---|---|
| storm1 (`10231093af9c…`) | 123 | 617 |
| storm2 (`697488011750…`) | 148 | 940 |
| storm3 (`55b726e94dad…`) | 151 | 1045 |
| storm4 (`147e52a3e0d7…`) | 140 | 744 |

## Status: INFERRED

Every layout was reconstructed by **static analysis** of the decompiled exe (which offsets each class's methods read
and write, allocation sizes, constructors, vtables). None of it is confirmed at runtime. Field names are given only where
the code supports them; the rest are `unk_<offset>` / `pad_<offset>`. Object sizes come from the game's own allocation
or constructor code; when that was not found the struct ends at its last proven field and the header says
"size unknown". Offsets are PC offsets for the exact build in the folder name.

Names follow the same rule as `games/`: Storm 1, 2 and 3 names come only from that game's own symbols and strings.

## Groups

- `ccPlayer`, `ccPlayerPad`, `ccCharacterBase`, `ccCpu*`, `ccGame*`, `ccScene*`, `ccSound*`, `ccUiSelectList`, `nucc*`:
  core engine classes, per build.
- `cmnNN`: the remaining engine / UI / render / math classes that exist in all four builds (88 groups).
- `s2Boss*`, `s3Boss*`, `ccBossBattleS1`, `ccHugeBattle`: boss-battle classes (Storm 1 giant battles; Storm 2 / 3 by boss number).
- `ccNet*`: network session, sockets, sync and services (Storm 2-4).
- `rb*`: classes relevant to rollback netcode (duel state, fighters, collision, projectiles, effects, frame stepping, RNG
  state, Bullet physics).
- `lib*`: statically linked libraries (dlmalloc, Lua 5.1, CRIWARE, zlib, libcurl, Scaleform). Public-source libraries
  (Bullet, Lua, zlib, libcurl, dlmalloc) follow the official source of the matching version, checked against the exe.
- `stNc*` / `stNa*`: story cutscene / event playback and adventure / mission progression.

Coverage is not complete: some classes with few named methods have no struct yet. Corrections and additions are
welcome through `contrib/` (see CONTRIBUTING.md).
