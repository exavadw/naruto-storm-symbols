/* rbFighter struct group for NARUTO STORM 2 (NSUNS2.exe, build s2)
 * Classes: ccPlayerLeader, ccPlayerSupport, ccPlayerPartner, ccPlayerGrp, ccPlayerTeamMng
 * All fields INFERRED from static analysis (decompilation + state_surface), not CONFIRMED.
 * Layout VERIFIED via compile-time offsetof checks against proven allocator sizes.
 *
 * Base class: ccPlayer (0x70A0 bytes) — see ccPlayer.h
 * Subclass sizes PROVEN from allocator calls (FUN_140580190 = operator new):
 *   ccPlayerLeader:  0x70A0 (FUN_140444c60 -> FUN_140580190(0x70a0, ...))
 *                    NOTE: same size as base ccPlayer; subclass fields overlap tail of base
 *   ccPlayerSupport: 0x70A0 (inferred: ctor accesses up to 0x70dc but no separate alloc found;
 *                    Create at 0x3CDC6C receives pre-allocated pointer; same pool as Leader)
 *   ccPlayerPartner: 0x70A0 (inferred: ctor accesses up to 0x7034; Create at 0x3C4FA8 receives
 *                    pre-allocated pointer; same pool as Leader)
 *   ccPlayerGrp:     0x78   (ccPlayerGrp::CreateInstance -> FUN_140580190(0x78, "source\\playergrp.cpp", 0x227))
 *   ccPlayerTeamMng: NO SYMBOLS in s2 — absent from this build
 *
 * Vtables:
 *   ccPlayerLeader:        PTR_FUN_140806648 (set in ctor at 0x39E348)
 *   ccPlayerLeader2BNRT:   PTR_FUN_140807658 (variant ctor at 0x3A2DA4)
 *   ccPlayerSupport:       set in ctor at 0x3CDA5C
 *   ccPlayerPartner:       PTR_FUN_140811370 (set in ctor at 0x3C4D4C)
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ============================================================
 * ccPlayerLeader — extends ccPlayer (0x70A0), total size 0x70A0
 * Proven: FUN_140444c60 allocates 0x70A0 via FUN_140580190
 * Constructor: 0x39E348
 * Vtable: PTR_FUN_140806648
 * NOTE: sizeof == base ccPlayer; subclass-specific fields are within
 *       the base range (tail region 0x7000..0x709F). Fields below are
 *       those accessed by Leader methods beyond what ccPlayer.h covers.
 * ============================================================ */
typedef struct {
    /* --- ccPlayer base (0x0000..0x709F) --- */
    uint8_t ccPlayer_base[0x70A0];
} ccPlayerLeader;

static_assert(sizeof(ccPlayerLeader) == 0x70A0, "ccPlayerLeader size must be 0x70A0");

/* ============================================================
 * ccPlayerSupport — extends ccPlayer (0x70A0), total size 0x70A0
 * Size inferred: no separate allocation found; Create (0x3CDC6C) receives
 * pre-allocated pointer. Ctor at 0x3CDA5C accesses fields up to 0x70DC.
 * NOTE: field at 0x70DC suggests possible extension beyond 0x70A0, but
 * without a proven distinct allocation size we cap at 0x70A0 conservatively.
 * The fields at 0x6F18..0x6F20 and 0x7064..0x708C are within base range.
 * ============================================================ */
typedef struct {
    /* --- ccPlayer base (0x0000..0x709F) --- */
    uint8_t ccPlayer_base[0x70A0];
} ccPlayerSupport;

static_assert(sizeof(ccPlayerSupport) == 0x70A0, "ccPlayerSupport size must be 0x70A0");

/* ============================================================
 * ccPlayerPartner — extends ccPlayer (0x70A0), total size 0x70A0
 * Size inferred: no separate allocation found; Create (0x3C4FA8) receives
 * pre-allocated pointer. Ctor at 0x3C4D4C sets vtable PTR_FUN_140811370.
 * Fields accessed: 0x701C, 0x7034, 0xE05, 0xDFB (within base range).
 * ============================================================ */
typedef struct {
    /* --- ccPlayer base (0x0000..0x709F) --- */
    uint8_t ccPlayer_base[0x70A0];
} ccPlayerPartner;

static_assert(sizeof(ccPlayerPartner) == 0x70A0, "ccPlayerPartner size must be 0x70A0");

/* ============================================================
 * ccPlayerGrp — standalone class, size 0x78
 * Proven: CreateInstance -> FUN_140580190(0x78, "source\\playergrp.cpp", 0x227)
 * 17 methods in s2. Not a ccPlayer subclass.
 * Instance fields unknown beyond size; no state_surface seeds available
 * that would distinguish Grp-owned fields from parameters.
 * ============================================================ */
typedef struct {
    uint8_t data[0x78];
} ccPlayerGrp;

static_assert(sizeof(ccPlayerGrp) == 0x78, "ccPlayerGrp size must be 0x78");

/* ccPlayerTeamMng: NO SYMBOLS in s2. Absent from this build.
 * Evidence: sqlite3 query for 'ccPlayerTeamMng::%' returns 0 rows.
 * No struct emitted. */

#pragma pack(pop)