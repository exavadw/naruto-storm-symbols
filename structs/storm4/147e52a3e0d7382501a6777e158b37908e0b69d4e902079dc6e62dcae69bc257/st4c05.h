/* st4c05.h — Story cutscene / event playback structs for NARUTO STORM 4 (s4, PC 1.09)
 *
 * All layouts INFERRED from static analysis (the decompiler cache state_surface + decomp).
 * Not CONFIRMED at runtime. Offsets are PC x64 (image base 0x140000000).
 *
 * Group: ccGroupBattleEventBoot, ccGroupBattleEventBootCheckerScript,
 *        ccGroupBattleEventCtrlScript, ccGroupBattleEventManager,
 *        ccGroupBattleScriptManager, ccIaCaption, ccLoDemoEventLoadState,
 *        ccLoDemoEventManager, ccLoDemoEventState, ccLoDemoLipSync,
 *        ccLoDemoStateMachine, ccLoDemoWaitTime, ccMsgWindowHugebtl,
 *        ccMsgWindowPlot
 */

#ifndef ST4C05_S4_H
#define ST4C05_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccGroupBattleEventManager
 * Size: 0x490 (1168 bytes) — proven by operator_new(0x490) in
 *   ccGroupBattleSystem::ResetCheckPointParam (RVA 0x442E00)
 * 6 fields from state_surface (7 seeds)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccGroupBattleEventManager {
    uint8_t _pad_0x00[0x0C];                     /* 0x00-0x0B: vtable + unknown */
    uint32_t field_0x0C;                          /* 0x0C: w, medium — set to 1 in ctor */
    uint8_t _pad_0x10[0x60];                     /* 0x10-0x6F: gap */
    uint64_t field_0x70;                          /* 0x70: w, medium — zeroed in ctor */
    uint64_t field_0x78;                          /* 0x78: w, medium — zeroed in ctor */
    uint64_t field_0x80;                          /* 0x80: w, medium — zeroed in ctor */
    uint32_t field_0x88;                          /* 0x88: w, medium — zeroed in ctor */
    uint8_t field_0x8C[0x400];                    /* 0x8C: r, low — memset(ptr+0x8C, 0, 0x400) */
    uint8_t _pad_0x48C[0x04];                     /* 0x48C-0x48F: tail pad to 0x490 */
} ccGroupBattleEventManager;

static_assert(sizeof(ccGroupBattleEventManager) == 0x490, "ccGroupBattleEventManager size");
static_assert(offsetof(ccGroupBattleEventManager, field_0x0C) == 0x0C, "ccGroupBattleEventManager.field_0x0C");
static_assert(offsetof(ccGroupBattleEventManager, field_0x70) == 0x70, "ccGroupBattleEventManager.field_0x70");
static_assert(offsetof(ccGroupBattleEventManager, field_0x78) == 0x78, "ccGroupBattleEventManager.field_0x78");
static_assert(offsetof(ccGroupBattleEventManager, field_0x80) == 0x80, "ccGroupBattleEventManager.field_0x80");
static_assert(offsetof(ccGroupBattleEventManager, field_0x88) == 0x88, "ccGroupBattleEventManager.field_0x88");
static_assert(offsetof(ccGroupBattleEventManager, field_0x8C) == 0x8C, "ccGroupBattleEventManager.field_0x8C");

/* =========================================================================
 * ccLoDemoEventState
 * Size: unknown, >= 0xB8 (highest accessed offset 0xB0 + pointer-sized read)
 * 4 fields from state_surface (12 seeds)
 * Key method: CreateCore (RVA 0x55EA18) allocates ccScript at offset 0x98
 * ========================================================================= */
typedef struct __attribute__((packed)) ccLoDemoEventState {
    uint8_t _pad_0x00[0x80];                     /* 0x00-0x7F: vtable + base class */
    /* 0x80: r, low — vtable call (**(code **)(*param_1 + 0x10))(param_1) */
    uint8_t _pad_0x80[0x18];                     /* 0x80-0x97: gap */
    uint64_t pScript_0x98;                        /* 0x98: rw, medium — ccScript* via operator_new(0x68) */
    uint8_t _pad_0xA0[0x04];                     /* 0xA0-0xA3: gap */
    uint32_t field_0xA4;                          /* 0xA4: w, medium — param_4 in CreateCore */
    uint8_t _pad_0xA8[0x08];                     /* 0xA8-0xAF: gap */
    /* 0xB0: r, low — ccFileLoadListForUi::LoadTh(param_1+0x16, "data/rpg/medemo.xfbin") */
    uint8_t _tail_0xB0[0x08];                    /* 0xB0-0xB7: last observed access region */
} ccLoDemoEventState;

static_assert(offsetof(ccLoDemoEventState, pScript_0x98) == 0x98, "ccLoDemoEventState.pScript_0x98");
static_assert(offsetof(ccLoDemoEventState, field_0xA4) == 0xA4, "ccLoDemoEventState.field_0xA4");

/* =========================================================================
 * ccGroupBattleEventCtrlScript
 * Size: unknown, >= 0xC8 (highest accessed offset 0xC0 + vtable read)
 * 3 fields from state_surface (3 seeds)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccGroupBattleEventCtrlScript {
    uint8_t _pad_0x00[0x0C];                     /* 0x00-0x0B: vtable + unknown */
    uint32_t field_0x0C;                          /* 0x0C: w, HIGH — set to 3 in Ctrl */
    uint8_t _pad_0x10[0x70];                     /* 0x10-0x7F: gap */
    /* 0x80: r, low — vtable call (**(code **)(*param_1 + 0x10))(param_1) */
    uint8_t _pad_0x80[0x40];                     /* 0x80-0xBF: gap */
    /* 0xC0: r, low — vtable call (**(code **)(*param_1 + 0x18))(param_1) */
    uint8_t _tail_0xC0[0x08];                    /* 0xC0-0xC7: last observed access region */
} ccGroupBattleEventCtrlScript;

static_assert(offsetof(ccGroupBattleEventCtrlScript, field_0x0C) == 0x0C, "ccGroupBattleEventCtrlScript.field_0x0C");

/* =========================================================================
 * ccLoDemoEventManager
 * Size: unknown, >= 0x88 (highest accessed offset 0x80 + vtable read)
 * 1 field from state_surface (1 seed)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccLoDemoEventManager {
    uint8_t _pad_0x00[0x80];                     /* 0x00-0x7F: vtable + base class */
    /* 0x80: r, low — vtable call (**(code **)(*param_1 + 0x10))(param_1) in Update */
    uint8_t _tail_0x80[0x08];                    /* 0x80-0x87: last observed access region */
} ccLoDemoEventManager;

/* No named fields with static_assert — only vtable access at 0x80 */

/* =========================================================================
 * NO INSTANCE STATE classes
 *
 * The following classes have no recoverable instance fields from
 * state_surface analysis. They are either pure utility/static classes,
 * interfaces, or their methods only access base-class state through
 * byte-cast patterns that state_surface cannot resolve into typed fields.
 *
 * Evidence per class:
 *
 * ccGroupBattleEventBoot: 3 seeds (Initialize, Add, IsBootOk), 0 fields.
 *   Methods use byte-cast param_1 access; no typed field writes found.
 *
 * ccGroupBattleEventBootCheckerScript: 3 seeds (Initialize, Finalize, IsBootOk),
 *   0 fields. Pure checker interface with no instance state beyond base.
 *
 * ccGroupBattleScriptManager: 2 seeds, 0 fields.
 *   Manager dispatches to sub-managers; no own instance state recovered.
 *
 * ccIaCaption: 1 seed, 0 fields.
 *   Caption display logic; state may live in a parent UI object.
 *
 * ccLoDemoEventLoadState: 3 seeds (LoadChara, GetProgress, LoadSound), 0 fields.
 *   ctor (RVA 0x4736BC) is AMBIG_GHIDRA (collides with CD2DPathGeometry ctor);
 *   remaining methods use byte-cast access patterns.
 *
 * ccLoDemoLipSync: 4 seeds (Create, GetData, ctor, dtor), 0 fields.
 *   Confirmed EMBEDDED subobject within ccEventLipSyncState at offset 0x78
 *   (via FUN_140754f78 placement-new in ccEventLipSyncState ctor RVA 0x4C669C).
 *   No standalone heap allocation found.
 *
 * ccLoDemoStateMachine: 1 seed, 0 fields.
 *   State machine dispatch; transitions likely encoded in script data.
 *
 * ccLoDemoWaitTime: 1 seed, 0 fields.
 *   Timer utility; wait duration likely passed as parameter, not stored.
 *
 * ccMsgWindowHugebtl: 1 seed, 0 fields.
 *   Message window variant; rendering state in parent message system.
 *
 * ccMsgWindowPlot: 1 seed, 0 fields.
 *   Plot message window; text/state managed externally.
 * ========================================================================= */

/* Placeholder types for documentation; no layout claims */
typedef struct ccGroupBattleEventBoot { uint8_t _unused; } ccGroupBattleEventBoot;
typedef struct ccGroupBattleEventBootCheckerScript { uint8_t _unused; } ccGroupBattleEventBootCheckerScript;
typedef struct ccGroupBattleScriptManager { uint8_t _unused; } ccGroupBattleScriptManager;
typedef struct ccIaCaption { uint8_t _unused; } ccIaCaption;
typedef struct ccLoDemoEventLoadState { uint8_t _unused; } ccLoDemoEventLoadState;
typedef struct ccLoDemoLipSync { uint8_t _unused; } ccLoDemoLipSync;
typedef struct ccLoDemoStateMachine { uint8_t _unused; } ccLoDemoStateMachine;
typedef struct ccLoDemoWaitTime { uint8_t _unused; } ccLoDemoWaitTime;
typedef struct ccMsgWindowHugebtl { uint8_t _unused; } ccMsgWindowHugebtl;
typedef struct ccMsgWindowPlot { uint8_t _unused; } ccMsgWindowPlot;

#endif /* ST4C05_S4_H */