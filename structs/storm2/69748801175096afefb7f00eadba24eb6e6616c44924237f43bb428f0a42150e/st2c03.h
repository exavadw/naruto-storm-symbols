/*
 * st2c03.h — Story CUTSCENE / EVENT playback structs for NARUTO STORM 2 PC (NSUNS2.exe, build s2)
 *
 * All layouts are INFERRED from static analysis of NSUNS2.exe (sha256 prefix 697488011750).
 * Offsets and sizes derived from decompiled ctors, allocator size arguments in
 * ccAdvScreenEffect::ccAdvScreenEffect (0x1DD530) and ccLoDemoStateMachine::Create (0x3462A8).
 * Field names from s2 symbols only (own-game rule). No cross-game names.
 *
 * Image base: 0x140000000
 */

#ifndef ST2C03_H
#define ST2C03_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccEventDofState — Depth-of-field post-effect state
 * Size: 0x14E0 (proven: embedded at +0x3ED0 in ccAdvScreenEffect, next at +0x53B0)
 * Vtable: 0x1407f2088
 * Methods: 5 (ctor, dtor, EnterInit, EnterStartDof x2)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventDofState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f2088 */
    uint8_t  _pad_base[0x14B8 - 0x8]; /* 0x0008: inherited/base fields */
    uint64_t dof_param_0;         /* 0x14B8: ctor writes param_1[0x297]=0 */
    uint64_t dof_param_1;         /* 0x14C0: ctor writes param_1[0x298]=0 */
    uint64_t dof_param_2;         /* 0x14C8: ctor writes param_1[0x299]=0 */
    uint64_t dof_param_3;         /* 0x14D0: ctor writes param_1[0x29a]=0 */
    uint8_t  _pad_tail[0x14E0 - 0x14D8]; /* 0x14D8: padding to proven size */
} ccEventDofState;

static_assert(offsetof(ccEventDofState, vtable) == 0x0000, "ccEventDofState.vtable");
static_assert(offsetof(ccEventDofState, dof_param_0) == 0x14B8, "ccEventDofState.dof_param_0");
static_assert(offsetof(ccEventDofState, dof_param_1) == 0x14C0, "ccEventDofState.dof_param_1");
static_assert(offsetof(ccEventDofState, dof_param_2) == 0x14C8, "ccEventDofState.dof_param_2");
static_assert(offsetof(ccEventDofState, dof_param_3) == 0x14D0, "ccEventDofState.dof_param_3");
static_assert(sizeof(ccEventDofState) == 0x14E0, "ccEventDofState size");

/* =========================================================================
 * ccEventGlareState — Glare/bloom post-effect state
 * Size: 0x14F0 (proven: embedded at +0x53B0 in ccAdvScreenEffect, next at +0x68A0)
 * Vtable: 0x1407e2450
 * Methods: 5 (ctor, dtor, EnterInit, EnterStartGlare x2)
 * Note: ctor FUN_14032d358 has no symbol name in s2; named by position.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventGlareState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407e2450 */
    uint8_t  _pad_base[0x14C8 - 0x8]; /* 0x0008: inherited/base fields */
    uint64_t glare_param_0;       /* 0x14C8: ctor writes param_1[0x299]=0 */
    uint64_t glare_param_1;       /* 0x14D0: ctor writes param_1[0x298]=0 */
    uint64_t glare_param_2;       /* 0x14D8: ctor writes param_1[0x29b]=0 */
    uint64_t glare_param_3;       /* 0x14E0: ctor writes param_1[0x29a]=0 */
    uint64_t glare_param_4;       /* 0x14E8: ctor writes param_1[0x29c]=0 */
} ccEventGlareState;

static_assert(offsetof(ccEventGlareState, vtable) == 0x0000, "ccEventGlareState.vtable");
static_assert(offsetof(ccEventGlareState, glare_param_0) == 0x14C8, "ccEventGlareState.glare_param_0");
static_assert(offsetof(ccEventGlareState, glare_param_1) == 0x14D0, "ccEventGlareState.glare_param_1");
static_assert(offsetof(ccEventGlareState, glare_param_2) == 0x14D8, "ccEventGlareState.glare_param_2");
static_assert(offsetof(ccEventGlareState, glare_param_3) == 0x14E0, "ccEventGlareState.glare_param_3");
static_assert(offsetof(ccEventGlareState, glare_param_4) == 0x14E8, "ccEventGlareState.glare_param_4");
static_assert(sizeof(ccEventGlareState) == 0x14F0, "ccEventGlareState size");

/* =========================================================================
 * ccEventLipSyncState — Lip-sync animation state for cutscene characters
 * Size: 0x1578 (proven: allocator size 0x1578 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407f2198
 * Methods: 8 (ctor, dtor x2, EnterInit, EnterMotion, SetLipParam, SetMotionParam, StateMotion)
 * Contains 4 std::string fields (lip motion names) initialized via FUN_1401afc0c.
 * String offsets: param_1[0x298]=0x14C0, [0x29a]=0x14D0, [0x2a1]=0x1508, [0x2a8]=0x1540
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventLipSyncState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f2198 */
    uint8_t  body[0x1578 - 0x8];  /* 0x0008: body includes lip_mode at 0x14B8, strings at 0x14C0+ */
} ccEventLipSyncState;

static_assert(offsetof(ccEventLipSyncState, vtable) == 0x0000, "ccEventLipSyncState.vtable");
static_assert(sizeof(ccEventLipSyncState) == 0x1578, "ccEventLipSyncState size");

/* =========================================================================
 * ccEventMovieCaptionState — Subtitle/caption display state for cutscenes
 * Size: 0x14E0 (proven: allocator size 0x14E0 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407e2450
 * Methods: 4 (ctor, Clear, Create, StateWait)
 * Ctor clears caption entries starting at +0x14C4; count/stride TBD.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventMovieCaptionState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407e2450 */
    uint8_t  body[0x14E0 - 0x8];  /* 0x0008: body includes caption data region at 0x14C4 */
} ccEventMovieCaptionState;

static_assert(offsetof(ccEventMovieCaptionState, vtable) == 0x0000, "ccEventMovieCaptionState.vtable");
static_assert(sizeof(ccEventMovieCaptionState) == 0x14E0, "ccEventMovieCaptionState size");

/* =========================================================================
 * ccEventMovieFadeState — Screen fade effect state for cutscene transitions
 * Size: 0x14C8 (proven: allocator size 0x14C8 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407e2450
 * Methods: 3 (ctor, SetMovieFrame, StateWait)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventMovieFadeState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407e2450 */
    uint8_t  _pad_base[0x14B8 - 0x8]; /* 0x0008: inherited/base fields */
    uint64_t fade_param_0;        /* 0x14B8: ctor writes param_1[0x297]=0 */
    uint64_t fade_param_1;        /* 0x14C0: ctor writes param_1[0x298]=0 */
} ccEventMovieFadeState;

static_assert(offsetof(ccEventMovieFadeState, vtable) == 0x0000, "ccEventMovieFadeState.vtable");
static_assert(offsetof(ccEventMovieFadeState, fade_param_0) == 0x14B8, "ccEventMovieFadeState.fade_param_0");
static_assert(offsetof(ccEventMovieFadeState, fade_param_1) == 0x14C0, "ccEventMovieFadeState.fade_param_1");
static_assert(sizeof(ccEventMovieFadeState) == 0x14C8, "ccEventMovieFadeState size");

/* =========================================================================
 * ccEventMovieState — Main movie/cutscene playback state machine
 * Size: 0x14700 (proven: allocator size 0x14700 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407f22c8
 * Methods: 12 (largest class in group)
 * Contains embedded sub-objects initialized via FUN_14032dd48 (+0x14C0)
 * and FUN_14032e070 (+0x131A0), plus a std::vector-like structure.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventMovieState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f22c8 */
    uint8_t  body[0x14700 - 0x8]; /* 0x0008: large body with embedded sub-objects */
} ccEventMovieState;

static_assert(offsetof(ccEventMovieState, vtable) == 0x0000, "ccEventMovieState.vtable");
static_assert(sizeof(ccEventMovieState) == 0x14700, "ccEventMovieState size");

/* =========================================================================
 * ccEventMovieTelopState — Telop (title card overlay) state for cutscenes
 * Size: 0x14E0 (proven: allocator size 0x14E0 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407f2358
 * Methods: 3 (ctor, Ctrl, Draw)
 * Ctor initializes a sub-object at param_1+6 (= byte offset 0x30) via FUN_140330958.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventMovieTelopState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f2358 */
    uint8_t  _pad[0x30 - 0x8];    /* 0x0008: padding to sub-object */
    uint8_t  telop_subobj[0x14E0 - 0x30]; /* 0x0030: telop rendering sub-object */
} ccEventMovieTelopState;

static_assert(offsetof(ccEventMovieTelopState, vtable) == 0x0000, "ccEventMovieTelopState.vtable");
static_assert(offsetof(ccEventMovieTelopState, telop_subobj) == 0x0030, "ccEventMovieTelopState.telop_subobj");
static_assert(sizeof(ccEventMovieTelopState) == 0x14E0, "ccEventMovieTelopState size");

/* =========================================================================
 * ccEventPostEffectState — Composite post-effect state (blur, color, etc.)
 * Size: 0x15B0 (proven: allocator size 0x15B0 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407f2418
 * Methods: 6 (ctor with memset, dtor, EnterInit, etc.)
 * Ctor FUN_14032eb44 zeroes 0x60 bytes at +0x1520, sets float at +0x14FC.
 * Contains vector-like structure at +0x1570.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventPostEffectState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f2418 */
    uint8_t  body[0x15B0 - 0x8];  /* 0x0008: large body with multiple sub-fields */
} ccEventPostEffectState;

static_assert(offsetof(ccEventPostEffectState, vtable) == 0x0000, "ccEventPostEffectState.vtable");
static_assert(sizeof(ccEventPostEffectState) == 0x15B0, "ccEventPostEffectState size");

/* =========================================================================
 * ccEventScreenFilterState — Minimal screen filter toggle state
 * Size: 0x10 (proven: allocator size 0x10 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407f24f8
 * Methods: 5 (ctor, dtor, EnterInit, EnterStart, EnterEnd)
 * Only vtable + one int32 field.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventScreenFilterState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f24f8 */
    uint32_t filter_mode;         /* 0x0008: filter enable/mode flag */
    uint32_t _pad;                /* 0x000C: padding to 0x10 */
} ccEventScreenFilterState;

static_assert(offsetof(ccEventScreenFilterState, vtable) == 0x0000, "ccEventScreenFilterState.vtable");
static_assert(offsetof(ccEventScreenFilterState, filter_mode) == 0x0008, "ccEventScreenFilterState.filter_mode");
static_assert(sizeof(ccEventScreenFilterState) == 0x10, "ccEventScreenFilterState size");

/* =========================================================================
 * ccEventShadowState — Shadow rendering state for cutscenes
 * Size: 0x14F0 (proven: allocator size 0x14F0 in ccLoDemoStateMachine::Create)
 * Vtable: 0x1407f2538
 * Methods: 4 (ctor, dtor, EnterInit, EnterStartShadow)
 * Fields at 0x14C0-0x14E0 from ctor analysis.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccEventShadowState {
    uint64_t vtable;              /* 0x0000: PTR_FUN_1407f2538 */
    uint8_t  body[0x14F0 - 0x8];  /* 0x0008: body includes shadow params at 0x14C0+ */
} ccEventShadowState;

static_assert(offsetof(ccEventShadowState, vtable) == 0x0000, "ccEventShadowState.vtable");
static_assert(sizeof(ccEventShadowState) == 0x14F0, "ccEventShadowState size");

/* =========================================================================
 * Classes with < 3 methods (skipped per brief):
 * - ccEventFogState (2 methods)
 * - ccEventManagerNS2 (1 method - dtor only)
 * - ccEventMovieMessageParam (1 method - Create only)
 * - ccEventSoftFocusState (needs ctor decompile, not yet analyzed)
 * ========================================================================= */

#endif /* ST2C03_H */