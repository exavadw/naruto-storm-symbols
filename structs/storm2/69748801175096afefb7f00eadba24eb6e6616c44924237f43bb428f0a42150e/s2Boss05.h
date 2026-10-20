#ifndef S2_BOSS05_H
#define S2_BOSS05_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s2Boss05 - Storm 2 (NSUNS2.exe) boss battle structs for Boss 05 fight
 * Build: s2 (sha 697488011750...)
 * All fields INFERRED from static analysis (state_surface + decomp).
 * Fight identity: UNKNOWN — see REPORT.md Correction 2026-10-19.
 * Character codes SSV/SSK appear in Phase03 player classes but are unidentified.
 *
 * Class hierarchy (from ctor chains):
 * ccScene -> ccSceneBoss05PhaseXX (scene phases)
 * ccSceneBoss05Phase03 embeds ccSceneBoss05Phase03Changer at +0x128
 * ccSceneBoss05Phase03 embeds ccBossBattleState at +0x3FB0
 *
 * Allocation sizes (from CreateScene<T> factories calling FUN_140580190):
 * ccSceneBoss05Phase00: 0x4D0 (1232)
 * ccSceneBoss05Phase01: 0x2AA8 (10920)
 * ccSceneBoss05Phase02: 0x4D8 (1240)
 * ccSceneBoss05Phase03: 0x5468 (21608)
 * ccSceneBoss05Phase04: 0x4D0 (1232)
 */

/* ========================================================================= */
/* ccSceneBoss05Phase03 — main boss phase with embedded Changer + BattleState */
/* Size: 0x5468 from CreateScene<ccSceneBoss05Phase03> -> FUN_140580190(0x5468) */
/* ========================================================================= */
typedef struct ccSceneBoss05Phase03 {
    uint64_t vtable;                    /* 0x0000 - set to PTR_FUN_140831388 in ctor */
    uint8_t pad_0008[288];              /* 0x0008 - ccScene base fields */
    /* ccSceneBoss05Phase03Changer embedded at +0x128 (ctor calls FUN_14042ad18 = Phase03Changer::ctor) */
    uint8_t changer_subobj[1888];       /* 0x0128 - ccSceneBoss05Phase03Changer */
    /* After changer: dtor accesses at +0x888,+0x898,+0x8A8 are ccUiObjectContainer sub-objects */
    uint8_t ui_container_0[16];         /* 0x0888 - ccUiObjectContainer (dtor calls FUN_140363aa0) */
    uint8_t ui_container_1[16];         /* 0x0898 - ccUiObjectContainer (dtor calls FUN_140363aa0) */
    uint8_t ui_container_2[16];         /* 0x08A8 - ccUiObjectContainer (dtor calls FUN_140363aa0) */
    uint8_t pad_08B8[208];              /* 0x08B8 */
    uint8_t unk_subobj_0988[24];        /* 0x0988 - mmMutex or similar (dtor calls FUN_1403d6be4) */
    uint64_t vtable_slot_09a0;          /* 0x09A0 - vtable ptr written in dtor (medium conf) */
    uint8_t pad_09A8[2920];             /* 0x09A8 */
    uint64_t vtable_slot_1510;          /* 0x1510 - vtable ptr written in dtor (medium conf) */
    uint8_t pad_1518[40];               /* 0x1518 */
    uint64_t vtable_slot_1540;          /* 0x1540 - vtable ptr written in dtor (medium conf) */
    uint8_t pad_1548[128];              /* 0x1548 */
    uint8_t unk_subobj_15c8[264];       /* 0x15C8 - sub-object destroyed by FUN_1406678c0 */
    uint8_t pad_16D0[10464];            /* 0x16D0 */
    /* ccBossBattleState embedded at +0x3FB0 (ctor calls FUN_1402f0e9c = ccBossBattleState::ctor) */
    uint8_t boss_battle_state[5304];    /* 0x3FB0 - ccBossBattleState (size = 0x5468 - 0x3FB0 = 0x14B8) */
} ccSceneBoss05Phase03;
static_assert(sizeof(ccSceneBoss05Phase03) == 0x5468, "ccSceneBoss05Phase03 size must be 0x5468");
static_assert(offsetof(ccSceneBoss05Phase03, changer_subobj) == 0x0128, "changer at +0x128");
static_assert(offsetof(ccSceneBoss05Phase03, vtable_slot_09a0) == 0x09A0, "vtable_slot_09a0 at +0x9A0");
static_assert(offsetof(ccSceneBoss05Phase03, vtable_slot_1510) == 0x1510, "vtable_slot_1510 at +0x1510");
static_assert(offsetof(ccSceneBoss05Phase03, vtable_slot_1540) == 0x1540, "vtable_slot_1540 at +0x1540");
static_assert(offsetof(ccSceneBoss05Phase03, boss_battle_state) == 0x3FB0, "ccBossBattleState at +0x3FB0");

/* ========================================================================= */
/* ccSceneBoss05Phase03Changer — embedded in Phase03 at +0x128 */
/* Standalone class in ns2 with 13 methods. No standalone factory found; */
/* size inferred from Phase03 layout gap. */
/* State surface: 3 fields at +0x14B8, +0x29C0, +0x29C8 (relative to Phase03 param_1) */
/* ========================================================================= */
typedef struct ccSceneBoss05Phase03Changer {
    uint8_t opaque[1888];               /* 0x0000 - internal layout unknown, size from Phase03 gap */
    /* Note: state_surface offsets are relative to Phase03 param_1, not this sub-object.
     * +0x14B8 from Phase03 = within this sub-object if it extends that far
     * +0x29C0 from Phase03 = beyond this sub-object's 1888-byte span
     * Actual internal layout unknown; declared as opaque blob. */
} ccSceneBoss05Phase03Changer;

/* ========================================================================= */
/* ccSceneBoss05Phase01 — second boss phase */
/* Size: 0x2AA8 from CreateScene<ccSceneBoss05Phase01> -> FUN_140580190(0x2AA8) */
/* ========================================================================= */
typedef struct ccSceneBoss05Phase01 {
    uint64_t vtable;                    /* 0x0000 - set to PTR_FUN_1408310b0 in ctor */
    uint8_t pad_0008[288];              /* 0x0008 - ccScene base */
    uint64_t field_0128;                /* 0x0128 - zeroed in ctor (param_1[0x25] = 0) */
    uint8_t pad_0130[5304];             /* 0x0130 - includes ccBossBattleState at +0x130 (FUN_1402f0e9c) */
    uint8_t tail_subobj[5312];          /* 0x15E8 - sub-object passed to FUN_1402508d4 in ctor */
} ccSceneBoss05Phase01;
static_assert(sizeof(ccSceneBoss05Phase01) == 0x2AA8, "ccSceneBoss05Phase01 size must be 0x2AA8");
static_assert(offsetof(ccSceneBoss05Phase01, field_0128) == 0x0128, "field_0128 at +0x128");

/* ========================================================================= */
/* ccSceneBoss05Phase00 — initial boss phase */
/* Size: 0x4D0 from CreateScene<ccSceneBoss05Phase00> -> FUN_140580190(0x4D0) */
/* ========================================================================= */
typedef struct ccSceneBoss05Phase00 {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[1224];             /* 0x0008 */
} ccSceneBoss05Phase00;
static_assert(sizeof(ccSceneBoss05Phase00) == 0x4D0, "ccSceneBoss05Phase00 size must be 0x4D0");

/* ========================================================================= */
/* ccSceneBoss05Phase02 — third boss phase */
/* Size: 0x4D8 from CreateScene<ccSceneBoss05Phase02> -> FUN_140580190(0x4D8) */
/* ========================================================================= */
typedef struct ccSceneBoss05Phase02 {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[1232];             /* 0x0008 */
} ccSceneBoss05Phase02;
static_assert(sizeof(ccSceneBoss05Phase02) == 0x4D8, "ccSceneBoss05Phase02 size must be 0x4D8");

/* ========================================================================= */
/* ccSceneBoss05Phase04 — final boss phase */
/* Size: 0x4D0 from CreateScene<ccSceneBoss05Phase04> -> FUN_140580190(0x4D0) */
/* ========================================================================= */
typedef struct ccSceneBoss05Phase04 {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[1224];             /* 0x0008 */
} ccSceneBoss05Phase04;
static_assert(sizeof(ccSceneBoss05Phase04) == 0x4D0, "ccSceneBoss05Phase04 size must be 0x4D0");

/* ========================================================================= */
/* Classes with >= 3 methods in ns2 but no factory/size found — stubs only */
/* ========================================================================= */

/* ccBoss05PlayVoiceState: 9 methods in ns2. No factory found; size unknown. */
typedef struct ccBoss05PlayVoiceState {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccBoss05PlayVoiceState;

/* ccBoss05Flash: 6 methods in ns2. No factory found; size unknown. */
typedef struct ccBoss05Flash {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccBoss05Flash;

/* ccBoss05CameraFilter: 7 methods in ns2. No factory found; size unknown. */
typedef struct ccBoss05CameraFilter {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccBoss05CameraFilter;

/* ccBoss05Stage00: 11 methods + factory template in ns2. No allocation size found yet. */
typedef struct ccBoss05Stage00 {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccBoss05Stage00;

/* ccSceneBoss05Phase03State: 15 methods in ns2. No factory found; size unknown. */
typedef struct ccSceneBoss05Phase03State {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccSceneBoss05Phase03State;

/* ccBoss0503Player1SSV: 3 methods in ns2. Phase03 Player1 with char code SSV. */
typedef struct ccBoss0503Player1SSV {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccBoss0503Player1SSV;

/* ccBoss0503Player2SSK: 3 methods in ns2. Phase03 Player2 with char code SSK. */
typedef struct ccBoss0503Player2SSK {
    uint64_t vtable;                    /* 0x0000 */
    uint8_t pad_0008[56];               /* 0x0008 - size unknown, >= 0x40 */
} ccBoss0503Player2SSK;

/* ccSceneBoss05: 6 methods + Load/Unload free functions in ns2. Dispatch-only. */
/* No persistent per-instance state beyond vtable observed. */

#endif /* S2_BOSS05_H */
/* ========================================================================= */
/* ccSceneBoss05: no instance state                                          */
/* Evidence: state_surface returned 0 fields across all 4 methods            */
/* (Initialize, Finalize, Execute, ~ccSceneBoss05). Decompiled code shows    */
/* dispatch-only behavior: Initialize calls 19 callees with string refs to   */
/* 'Boss05 UI Manage'/'bossBattle_ui_mgr'; Execute has only 2 callees and    */
/* 14 lines; Finalize has 10 callees. No param_1 offset accesses found.     */
/* Class is a thin scene dispatcher with no persistent per-instance data     */
/* beyond the vtable. Size unknown, >= 0x8 (vtable only).                   */
/* ========================================================================= */
