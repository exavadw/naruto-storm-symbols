/* rbSpatk s2 — NARUTO STORM 2 PC (NSUNS2.exe) */
/* All layouts INFERRED from static analysis; not runtime-confirmed. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * NO INSTANCE STATE: ccSpatkMng, ccSpatkPlayer, ccSpatkInput have no instance
 * state in build s2 because these classes are ABSENT from the binary.
 *
 * Evidence:
 *   - sqlite3 the decompiler cache.db: 0 symbols matching ccSpatkMng/ccSpatkPlayer/ccSpatkInput
 *     for build_alias='s2' (only ccSpatkDebugPlay ctor, ccUiCollectionModeSpAtk::*,
 *     ccSound::SpAtkPauseOff exist — none are equivalents).
 *   - storm_map ccSpatkMng::Ctrl --from s1 --to s2: unmapped=["s2"].
 *   - the decompiler cache find "spatk" -b s2 --mode string: 0 string matches.
 *   - state_surface on all 7 same-RVA-fallback decompiles returned 0 fields each
 *     (the RVAs point to unrelated code in s2).
 *
 * No structs, no fields, no static_assert(offsetof) checks needed.
 * See rbSpatk-REPORT.md for full evidence and mapping failure details.
 */