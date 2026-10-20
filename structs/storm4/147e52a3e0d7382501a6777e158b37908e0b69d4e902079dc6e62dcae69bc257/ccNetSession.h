/*
 * ccNetSession network classes - NARUTO STORM 4 PC (s4, NSUNS4.exe 1.09)
 * INFERRED layout from static analysis (state_surface + decompiled ctors/methods).
 * NOT CONFIRMED at runtime. All offsets are x64 PC (image base 0x140000000).
 * Names from s4 own-game symbols/strings only; no cross-game name reuse.
 *
 * ALIGNMENT NOTE: Fields at offsets not matching their natural alignment use
 * uint8_t[N] byte arrays to prevent compiler-inserted padding.
 */
#ifndef CC_NET_SESSION_S4_H
#define CC_NET_SESSION_S4_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>


/* ======================================================================
 * ccNetManager
 * Size: unknown, >= 0x1D300
 * Vtable: (inferred from ctor)
 * s4 notes: gained field at 0x2A0 vs s3; large array region near 0x1D2F8
 * ====================================================================== */
typedef struct ccNetManager {
    /* 0x00000 */ void* vtable;
    /* 0x00008 */ uint8_t pad_8[0x6C];
    /* 0x00074 */ int32_t unk_74; /* r: range check in seeds */
    /* 0x00078 */ uint8_t pad_78[0x8];
    /* 0x00080 */ uint8_t init_block[0x8]; /* rw: vtable+0x10 call site */
    /* 0x00088 */ uint8_t unk_88[4]; /* rw: mixed 4/8 size accesses */
    /* 0x0008C */ int32_t unk_8c; /* w: int32 write */
    /* 0x00090 */ uint8_t pad_90[0x98];
    /* 0x00128 */ void* unk_128; /* w: ptr write */
    /* 0x00130 */ uint8_t pad_130[0x170];
    /* 0x002A0 */ void* unk_2a0; /* rw: NEW in s4, ptr check; not present in s3 */
    /* 0x002A8 */ uint8_t pad_2a8[0x1D050];
    /* 0x1D2F8 */ uint64_t array_element_1d2f8; /* rw: large offset array element */
} ccNetManager;
static_assert(offsetof(ccNetManager, vtable) == 0x0, "ccNetManager.vtable");
static_assert(offsetof(ccNetManager, unk_74) == 0x74, "ccNetManager.unk_74");
static_assert(offsetof(ccNetManager, init_block) == 0x80, "ccNetManager.init_block");
static_assert(offsetof(ccNetManager, unk_88) == 0x88, "ccNetManager.unk_88");
static_assert(offsetof(ccNetManager, unk_8c) == 0x8C, "ccNetManager.unk_8c");
static_assert(offsetof(ccNetManager, unk_128) == 0x128, "ccNetManager.unk_128");
static_assert(offsetof(ccNetManager, unk_2a0) == 0x2A0, "ccNetManager.unk_2a0");
static_assert(offsetof(ccNetManager, array_element_1d2f8) == 0x1D2F8, "ccNetManager.array_element_1d2f8");

/* ======================================================================
 * ccNetSession
 * Size: unknown (Abstract base class; virtual-dispatch-only, 0 surface fields)
 * ====================================================================== */
typedef struct ccNetSession {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSession;
static_assert(offsetof(ccNetSession, vtable) == 0x00, "ccNetSession.vtable");

/* ======================================================================
 * ccNetSessionXPT
 * Size: unknown (Cross-platform transport; virtual dispatch only, 0 surface fields)
 * ====================================================================== */
typedef struct ccNetSessionXPT {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSessionXPT;
static_assert(offsetof(ccNetSessionXPT, vtable) == 0x00, "ccNetSessionXPT.vtable");

/* ======================================================================
 * ccNetSessionSearch
 * Size: unknown (Virtual dispatch only, 0 surface fields in s4)
 * ====================================================================== */
typedef struct ccNetSessionSearch {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSessionSearch;
static_assert(offsetof(ccNetSessionSearch, vtable) == 0x00, "ccNetSessionSearch.vtable");

/* ======================================================================
 * ccNetMatchingUserData
 * Size: unknown (No surface data generated for s4; carried from s3 pattern)
 * ====================================================================== */
typedef struct ccNetMatchingUserData {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetMatchingUserData;
static_assert(offsetof(ccNetMatchingUserData, vtable) == 0x00, "ccNetMatchingUserData.vtable");

/* ======================================================================
 * ccNetOnlineCheckAdapter
 * Size: unknown (Thin adapter; 0 surface fields in s4)
 * ====================================================================== */
typedef struct ccNetOnlineCheckAdapter {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetOnlineCheckAdapter;
static_assert(offsetof(ccNetOnlineCheckAdapter, vtable) == 0x00, "ccNetOnlineCheckAdapter.vtable");

/* ======================================================================
 * ccNetLobbyBaseState
 * Size: unknown (0 surface fields in s4)
 * ====================================================================== */
typedef struct ccNetLobbyBaseState {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetLobbyBaseState;
static_assert(offsetof(ccNetLobbyBaseState, vtable) == 0x00, "ccNetLobbyBaseState.vtable");

/* ======================================================================
 * ccNetEndlessMatchLobbyState_New
 * Size: unknown, >= 0x5C8
 * s4 notes: substantial field coverage (15 fields), much larger than s3 stub
 * ====================================================================== */
typedef struct ccNetEndlessMatchLobbyState_New {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x46];
    /* 0x004E */ uint16_t unk_4e; /* rw: undefined2 */
    /* 0x0050 */ uint8_t pad_50[0xC];
    /* 0x005C */ int32_t unk_5c; /* r: read in RequestInvitedLeave */
    /* 0x0060 */ uint8_t pad_60[0x24];
    /* 0x0084 */ int32_t invite_leave_flag; /* w: set to 1 in RequestInvitedLeave */
    /* 0x0088 */ uint8_t pad_88[0xF8];
    /* 0x0180 */ uint64_t unk_180; /* r: qword read in RequestInvitedLeave */
    /* 0x0188 */ uint8_t pad_188[0x34];
    /* 0x01BC */ int32_t sync_return_battle; /* rw: set to 0 in CtrlState_SyncReturnBattle */
    /* 0x01C0 */ int32_t unk_1c0; /* rw: mixed 4/8 size */
    /* 0x01C4 */ uint8_t pad_1c4[0x4];
    /* 0x01C8 */ uint64_t unk_1c8; /* rw: qword increment */
    /* 0x01D0 */ uint8_t pad_1d0[0x4];
    /* 0x01D4 */ uint8_t unk_1d4; /* r: char read, null check */
    /* 0x01D5 */ uint8_t pad_1d5[0x3];
    /* 0x01D8 */ int32_t unk_1d8; /* w: set to 1 in RequestInvitedLeave */
    /* 0x01DC */ uint8_t pad_1dc[0x40];
    /* 0x021C */ int32_t unk_21c; /* r: zero check in SyncReturnBattle */
    /* 0x0220 */ uint8_t pad_220[0x4];
    /* 0x0224 */ int32_t unk_224; /* w: set to 1 in SyncReturnBattle */
    /* 0x0228 */ uint8_t pad_228[0x10];
    /* 0x0238 */ int32_t unk_238; /* rw: mixed 4/8 size */
    /* 0x023C */ uint8_t pad_23c[0x4];
    /* 0x0240 */ uint64_t unk_240; /* r: qword read */
    /* 0x0248 */ uint8_t pad_248[0xB8];
    /* 0x0300 */ uint8_t vcall_region_300[0x8]; /* r: low-conf vcall at vtable+0x60 */
    /* 0x0308 */ uint8_t pad_308[0x2B8];
    /* 0x05C0 */ uint8_t vcall_region_5c0[0x8]; /* r: low-conf vcall at vtable+0xb8 */
} ccNetEndlessMatchLobbyState_New;
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, vtable) == 0x0, "ccNetEndlessMatchLobbyState_New.vtable");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_4e) == 0x4E, "ccNetEndlessMatchLobbyState_New.unk_4e");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_5c) == 0x5C, "ccNetEndlessMatchLobbyState_New.unk_5c");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, invite_leave_flag) == 0x84, "ccNetEndlessMatchLobbyState_New.invite_leave_flag");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_180) == 0x180, "ccNetEndlessMatchLobbyState_New.unk_180");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, sync_return_battle) == 0x1BC, "ccNetEndlessMatchLobbyState_New.sync_return_battle");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_1c0) == 0x1C0, "ccNetEndlessMatchLobbyState_New.unk_1c0");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_1c8) == 0x1C8, "ccNetEndlessMatchLobbyState_New.unk_1c8");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_1d4) == 0x1D4, "ccNetEndlessMatchLobbyState_New.unk_1d4");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_1d8) == 0x1D8, "ccNetEndlessMatchLobbyState_New.unk_1d8");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_21c) == 0x21C, "ccNetEndlessMatchLobbyState_New.unk_21c");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_224) == 0x224, "ccNetEndlessMatchLobbyState_New.unk_224");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_238) == 0x238, "ccNetEndlessMatchLobbyState_New.unk_238");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, unk_240) == 0x240, "ccNetEndlessMatchLobbyState_New.unk_240");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, vcall_region_300) == 0x300, "ccNetEndlessMatchLobbyState_New.vcall_region_300");
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, vcall_region_5c0) == 0x5C0, "ccNetEndlessMatchLobbyState_New.vcall_region_5c0");

/* ======================================================================
 * ccNetEndlessMatchAdjustBattleTableState
 * Size: unknown (0 surface fields in s4)
 * ====================================================================== */
typedef struct ccNetEndlessMatchAdjustBattleTableState {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetEndlessMatchAdjustBattleTableState;
static_assert(offsetof(ccNetEndlessMatchAdjustBattleTableState, vtable) == 0x00, "ccNetEndlessMatchAdjustBattleTableState.vtable");

/* ======================================================================
 * ccNetTopMenuState
 * Size: unknown (Virtual dispatch only; no s4 surface data)
 * ====================================================================== */
typedef struct ccNetTopMenuState {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetTopMenuState;
static_assert(offsetof(ccNetTopMenuState, vtable) == 0x00, "ccNetTopMenuState.vtable");

/* ======================================================================
 * ccNetCommunicateUserInfo
 * Size: unknown (0 surface fields in s4; byte-cast only)
 * ====================================================================== */
typedef struct ccNetCommunicateUserInfo {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetCommunicateUserInfo;
static_assert(offsetof(ccNetCommunicateUserInfo, vtable) == 0x00, "ccNetCommunicateUserInfo.vtable");

/* ======================================================================
 * ccNetSessionImpl
 * Size: unknown, >= 0x498
 * s4 notes: same 4-field layout as s3 (0x80, 0x128, 0x488, 0x490)
 * ====================================================================== */
typedef struct ccNetSessionImpl {
    /* 0x0000 */ void* vtable; /* vcall at (*vtable+0x10) */
    /* 0x0008 */ uint8_t pad_8[0x78];
    /* 0x0080 */ uint8_t unk_80_region[0xA8]; /* r: vtable-related access */
    /* 0x0128 */ int32_t owner_ctrl_state; /* ChangeOwnerCtrl_STOP_SOCKET */
    /* 0x012C */ uint8_t pad_12c[0x35C];
    /* 0x0488 */ void* unk_488_ptr; /* if (param_1[0x91] != 0) */
    /* 0x0490 */ void* unk_490_ptr; /* if (param_1[0x92] != 0) */
} ccNetSessionImpl;
static_assert(offsetof(ccNetSessionImpl, vtable) == 0x0, "ccNetSessionImpl.vtable");
static_assert(offsetof(ccNetSessionImpl, unk_80_region) == 0x80, "ccNetSessionImpl.unk_80_region");
static_assert(offsetof(ccNetSessionImpl, owner_ctrl_state) == 0x128, "ccNetSessionImpl.owner_ctrl_state");
static_assert(offsetof(ccNetSessionImpl, unk_488_ptr) == 0x488, "ccNetSessionImpl.unk_488_ptr");
static_assert(offsetof(ccNetSessionImpl, unk_490_ptr) == 0x490, "ccNetSessionImpl.unk_490_ptr");

/* ======================================================================
 * ccNetSessionAdapter
 * Size: unknown (Thin adapter; 0 surface fields in s4)
 * ====================================================================== */
typedef struct ccNetSessionAdapter {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSessionAdapter;
static_assert(offsetof(ccNetSessionAdapter, vtable) == 0x00, "ccNetSessionAdapter.vtable");

/* ======================================================================
 * ccNetSessionManager
 * Size: unknown, >= 0x1D330
 * s4 notes: massive growth vs s3 (>= 0x608); embedded array region 0x1D108-0x1D328
 * ====================================================================== */
typedef struct ccNetSessionManager {
    /* 0x00000 */ void* vtable;
    /* 0x00008 */ uint8_t pad_8[0x4C];
    /* 0x00054 */ uint8_t unk_54[0x8];       /* w: qword zero in ctor (misaligned) */
    /* 0x0005C */ uint8_t unk_5c[0x4];       /* w: int32 zero in ctor (misaligned) */
    /* 0x00060 */ uint8_t unk_60[0x8];       /* w: set to 1 in ctor (misaligned) */
    /* 0x00068 */ uint8_t unk_68[0x8];       /* w: qword zero in ctor (misaligned) */
    /* 0x00070 */ uint8_t unk_70[0x8];       /* w: qword zero in ctor (misaligned) */
    /* 0x00078 */ uint8_t unk_78[0x8];       /* w: qword zero in ctor (misaligned) */
    /* 0x00080 */ uint8_t vcall_region_80[0x8]; /* r: vtable+0x10 call in Finalize */
    /* 0x00088 */ uint8_t unk_88[0x10];      /* rw: ptr read/write in Finalize (misaligned) */
    /* 0x00098 */ uint8_t unk_98[0x40];      /* rw: ptr read/write in Finalize (misaligned) */
    /* 0x000D8 */ uint8_t unk_d8[0x1D030];   /* rw: ptr read/write in Finalize (misaligned) */
    /* 0x1D108 */ void* array_elem_1d108;    /* rw: array region start */
    /* 0x1D110 */ void* array_elem_1d110;    /* rw */
    /* 0x1D118 */ void* array_elem_1d118;    /* rw */
    /* 0x1D120 */ uint8_t pad_1d120[0x8];
    /* 0x1D128 */ void* array_elem_1d128;    /* rw */
    /* 0x1D130 */ void* array_elem_1d130;    /* rw */
    /* 0x1D138 */ void* array_elem_1d138;    /* rw */
    /* 0x1D140 */ void* array_elem_1d140;    /* rw */
    /* 0x1D148 */ uint8_t subobj_1d148[0x8]; /* r: FUN call target */
    /* 0x1D150 */ uint8_t pad_1d150[0x1B0];
    /* 0x1D300 */ void* array_elem_1d300;    /* rw */
    /* 0x1D308 */ void* array_elem_1d308;    /* rw: null-checked */
    /* 0x1D310 */ void* array_elem_1d310;    /* rw */
    /* 0x1D318 */ void* array_elem_1d318;    /* rw */
    /* 0x1D320 */ void* array_elem_1d320;    /* rw */
    /* 0x1D328 */ void* array_elem_1d328;    /* rw: null-checked */
} ccNetSessionManager;
static_assert(offsetof(ccNetSessionManager, vtable) == 0x0, "ccNetSessionManager.vtable");
static_assert(offsetof(ccNetSessionManager, unk_54) == 0x54, "ccNetSessionManager.unk_54");
static_assert(offsetof(ccNetSessionManager, unk_5c) == 0x5C, "ccNetSessionManager.unk_5c");
static_assert(offsetof(ccNetSessionManager, unk_60) == 0x60, "ccNetSessionManager.unk_60");
static_assert(offsetof(ccNetSessionManager, unk_68) == 0x68, "ccNetSessionManager.unk_68");
static_assert(offsetof(ccNetSessionManager, unk_70) == 0x70, "ccNetSessionManager.unk_70");
static_assert(offsetof(ccNetSessionManager, unk_78) == 0x78, "ccNetSessionManager.unk_78");
static_assert(offsetof(ccNetSessionManager, vcall_region_80) == 0x80, "ccNetSessionManager.vcall_region_80");
static_assert(offsetof(ccNetSessionManager, unk_88) == 0x88, "ccNetSessionManager.unk_88");
static_assert(offsetof(ccNetSessionManager, unk_98) == 0x98, "ccNetSessionManager.unk_98");
static_assert(offsetof(ccNetSessionManager, unk_d8) == 0xD8, "ccNetSessionManager.unk_d8");
static_assert(offsetof(ccNetSessionManager, array_elem_1d108) == 0x1D108, "ccNetSessionManager.array_elem_1d108");
static_assert(offsetof(ccNetSessionManager, array_elem_1d300) == 0x1D300, "ccNetSessionManager.array_elem_1d300");
static_assert(offsetof(ccNetSessionManager, array_elem_1d328) == 0x1D328, "ccNetSessionManager.array_elem_1d328");

/* ======================================================================
 * ccNetSessionSearchAdapter
 * Size: unknown, >= 0x158
 * s4 notes: 7 concrete fields (vs 0 in s3 surface)
 * ====================================================================== */
typedef struct ccNetSessionSearchAdapter {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x78];
    /* 0x0080 */ uint64_t unk_80;
    /* 0x0088 */ uint8_t pad_88[0xA0];
    /* 0x0128 */ uint64_t unk_128;
    /* 0x0130 */ uint64_t unk_130;
    /* 0x0138 */ uint64_t unk_138;
    /* 0x0140 */ uint8_t pad_140[0xC];
    /* 0x014C */ uint32_t unk_14c;
    /* 0x0150 */ uint32_t unk_150;
    /* 0x0154 */ uint32_t unk_154;
} ccNetSessionSearchAdapter;
static_assert(offsetof(ccNetSessionSearchAdapter, vtable) == 0x0, "ccNetSessionSearchAdapter.vtable");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_80) == 0x80, "ccNetSessionSearchAdapter.unk_80");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_128) == 0x128, "ccNetSessionSearchAdapter.unk_128");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_130) == 0x130, "ccNetSessionSearchAdapter.unk_130");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_138) == 0x138, "ccNetSessionSearchAdapter.unk_138");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_14c) == 0x14C, "ccNetSessionSearchAdapter.unk_14c");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_150) == 0x150, "ccNetSessionSearchAdapter.unk_150");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_154) == 0x154, "ccNetSessionSearchAdapter.unk_154");

/* ======================================================================
 * ccNetMatchingReady
 * Size: unknown, >= 0x39C
 * s4 notes: massive growth vs s3 (>= 0x1A); 25 fields including floats at 0x188/0x18C
 * ====================================================================== */
typedef struct ccNetMatchingReady {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x88];
    /* 0x0090 */ void* unk_90;               /* rw: ptr */
    /* 0x0098 */ uint8_t pad_98[0x10];
    /* 0x00A8 */ uint64_t unk_a8;             /* w: qword zero */
    /* 0x00B0 */ int32_t unk_b0;              /* w: int32 zero */
    /* 0x00B4 */ uint8_t pad_b4[0x4];
    /* 0x00B8 */ uint64_t unk_b8;             /* w: qword zero */
    /* 0x00C0 */ uint64_t unk_c0;             /* w: qword zero */
    /* 0x00C8 */ uint64_t unk_c8;             /* w: qword zero */
    /* 0x00D0 */ uint64_t unk_d0;             /* w: qword zero */
    /* 0x00D8 */ uint8_t subobj_d8[0x8];      /* r: FUN_1404fa6a0 call target */
    /* 0x00E0 */ uint8_t pad_e0[0xA8];
    /* 0x0188 */ float unk_188;               /* w: -1.0f (0xbf800000) */
    /* 0x018C */ float unk_18c;               /* w: 1.0f (0x3f800000) */
    /* 0x0190 */ uint8_t subobj_190[0x8];     /* r: FUN_1405057b4 call target */
    /* 0x0198 */ uint8_t pad_198[0x130];
    /* 0x02C8 */ uint8_t subobj_2c8[0x8];     /* r: ptr load */
    /* 0x02D0 */ uint64_t unk_2d0;            /* w: qword zero */
    /* 0x02D8 */ uint64_t unk_2d8;            /* rw: qword zero */
    /* 0x02E0 */ uint8_t subobj_2e0[0x8];     /* r: FUN_1401ca8f8 call target */
    /* 0x02E8 */ uint8_t pad_2e8[0x68];
    /* 0x0350 */ uint64_t unk_350;            /* w: qword zero */
    /* 0x0358 */ uint64_t unk_358;            /* w: qword zero */
    /* 0x0360 */ int32_t unk_360;             /* w: 0xffffffff */
    /* 0x0364 */ uint8_t unk_364[0x8];        /* w: 0xffffffffffffffff (misaligned) */
    /* 0x036C */ uint8_t unk_36c[0x8];        /* w: 0xffffffffffffffff (misaligned) */
    /* 0x0374 */ uint8_t pad_374[0x4];
    /* 0x0378 */ uint64_t unk_378;            /* w: qword zero */
    /* 0x0380 */ uint64_t unk_380;            /* w: qword zero */
    /* 0x0388 */ int32_t unk_388;             /* w: int32 zero */
    /* 0x038C */ uint8_t unk_38c[0x8];        /* w: 0xffffffffffffffff (misaligned) */
    /* 0x0394 */ uint8_t unk_394[0x8];        /* w: qword 1 (misaligned) */
} ccNetMatchingReady;
static_assert(offsetof(ccNetMatchingReady, vtable) == 0x0, "ccNetMatchingReady.vtable");
static_assert(offsetof(ccNetMatchingReady, unk_90) == 0x90, "ccNetMatchingReady.unk_90");
static_assert(offsetof(ccNetMatchingReady, unk_a8) == 0xA8, "ccNetMatchingReady.unk_a8");
static_assert(offsetof(ccNetMatchingReady, unk_b0) == 0xB0, "ccNetMatchingReady.unk_b0");
static_assert(offsetof(ccNetMatchingReady, unk_b8) == 0xB8, "ccNetMatchingReady.unk_b8");
static_assert(offsetof(ccNetMatchingReady, unk_c0) == 0xC0, "ccNetMatchingReady.unk_c0");
static_assert(offsetof(ccNetMatchingReady, unk_c8) == 0xC8, "ccNetMatchingReady.unk_c8");
static_assert(offsetof(ccNetMatchingReady, unk_d0) == 0xD0, "ccNetMatchingReady.unk_d0");
static_assert(offsetof(ccNetMatchingReady, subobj_d8) == 0xD8, "ccNetMatchingReady.subobj_d8");
static_assert(offsetof(ccNetMatchingReady, unk_188) == 0x188, "ccNetMatchingReady.unk_188");
static_assert(offsetof(ccNetMatchingReady, unk_18c) == 0x18C, "ccNetMatchingReady.unk_18c");
static_assert(offsetof(ccNetMatchingReady, subobj_190) == 0x190, "ccNetMatchingReady.subobj_190");
static_assert(offsetof(ccNetMatchingReady, subobj_2c8) == 0x2C8, "ccNetMatchingReady.subobj_2c8");
static_assert(offsetof(ccNetMatchingReady, unk_2d0) == 0x2D0, "ccNetMatchingReady.unk_2d0");
static_assert(offsetof(ccNetMatchingReady, unk_2d8) == 0x2D8, "ccNetMatchingReady.unk_2d8");
static_assert(offsetof(ccNetMatchingReady, subobj_2e0) == 0x2E0, "ccNetMatchingReady.subobj_2e0");
static_assert(offsetof(ccNetMatchingReady, unk_350) == 0x350, "ccNetMatchingReady.unk_350");
static_assert(offsetof(ccNetMatchingReady, unk_358) == 0x358, "ccNetMatchingReady.unk_358");
static_assert(offsetof(ccNetMatchingReady, unk_360) == 0x360, "ccNetMatchingReady.unk_360");
static_assert(offsetof(ccNetMatchingReady, unk_364) == 0x364, "ccNetMatchingReady.unk_364");
static_assert(offsetof(ccNetMatchingReady, unk_36c) == 0x36C, "ccNetMatchingReady.unk_36c");
static_assert(offsetof(ccNetMatchingReady, unk_378) == 0x378, "ccNetMatchingReady.unk_378");
static_assert(offsetof(ccNetMatchingReady, unk_380) == 0x380, "ccNetMatchingReady.unk_380");
static_assert(offsetof(ccNetMatchingReady, unk_388) == 0x388, "ccNetMatchingReady.unk_388");
static_assert(offsetof(ccNetMatchingReady, unk_38c) == 0x38C, "ccNetMatchingReady.unk_38c");
static_assert(offsetof(ccNetMatchingReady, unk_394) == 0x394, "ccNetMatchingReady.unk_394");

/* ======================================================================
 * ccNetStartUp_Impl
 * Size: unknown, >= 0x68
 * s4 notes: identical layout to s3 (fields at 0xC and 0x60)
 * ====================================================================== */
typedef struct ccNetStartUp_Impl {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint8_t pad_8[0x4];
    /* 0x0C */ int32_t ctrl_state;
    /* 0x10 */ uint8_t pad_10[0x50];
    /* 0x60 */ uint64_t ctrl_field;
} ccNetStartUp_Impl;
static_assert(offsetof(ccNetStartUp_Impl, vtable) == 0x0, "ccNetStartUp_Impl.vtable");
static_assert(offsetof(ccNetStartUp_Impl, ctrl_state) == 0xC, "ccNetStartUp_Impl.ctrl_state");
static_assert(offsetof(ccNetStartUp_Impl, ctrl_field) == 0x60, "ccNetStartUp_Impl.ctrl_field");

/* ======================================================================
 * ccNetStartUp
 * Size: unknown, >= 0x68
 * s4 notes: identical layout to s3 (fields at 0xC and 0x60)
 * ====================================================================== */
typedef struct ccNetStartUp {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint8_t pad_8[0x4];
    /* 0x0C */ int32_t ctrl_state;
    /* 0x10 */ uint8_t pad_10[0x50];
    /* 0x60 */ uint64_t ctrl_field;
} ccNetStartUp;
static_assert(offsetof(ccNetStartUp, vtable) == 0x0, "ccNetStartUp.vtable");
static_assert(offsetof(ccNetStartUp, ctrl_state) == 0xC, "ccNetStartUp.ctrl_state");
static_assert(offsetof(ccNetStartUp, ctrl_field) == 0x60, "ccNetStartUp.ctrl_field");

/* ======================================================================
 * ccNetOnlineCheck_Impl
 * Size: unknown (carried from s3 pattern; no s4 surface data generated)
 * ====================================================================== */
typedef struct ccNetOnlineCheck_Impl {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetOnlineCheck_Impl;
static_assert(offsetof(ccNetOnlineCheck_Impl, vtable) == 0x00, "ccNetOnlineCheck_Impl.vtable");

/* ======================================================================
 * ccNetOnlineCheck
 * Size: unknown, >= 0x88
 * s4 notes: single vtable-related field at 0x80
 * ====================================================================== */
typedef struct ccNetOnlineCheck {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint8_t pad_8[0x78];
    /* 0x80 */ uint8_t unk_80_region[0x8]; /* vtable-related access */
} ccNetOnlineCheck;
static_assert(offsetof(ccNetOnlineCheck, vtable) == 0x0, "ccNetOnlineCheck.vtable");
static_assert(offsetof(ccNetOnlineCheck, unk_80_region) == 0x80, "ccNetOnlineCheck.unk_80_region");

#endif /* CC_NET_SESSION_S4_H */