/*
 * ccNetSession network classes - NARUTO STORM 3 Full Burst HD PC (s3, NSUNS3.exe 64-bit)
 * INFERRED layout from static analysis (state_surface + decompiled ctors/methods).
 * NOT CONFIRMED at runtime. All offsets are x64 PC (image base 0x140000000).
 * Names from s3 own-game symbols/strings only; no cross-game name reuse.
 *
 * ALIGNMENT NOTE: Fields at offsets not matching their natural alignment use
 * uint8_t[N] byte arrays to prevent compiler-inserted padding.
 */
#ifndef CC_NET_SESSION_S3_H
#define CC_NET_SESSION_S3_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>


/* ======================================================================
 * ccNetManager
 * Size: unknown, >= 0x130
 * Vtable: PTR_FUN_1409ec308
 * ====================================================================== */
typedef struct ccNetManager {
    /* 0x0000 */ void* vtable; /* ctor: *param_1 = &PTR_FUN_1409ec308 */
    /* 0x0008 */ uint8_t pad_8[0x6C];
    /* 0x0074 */ uint8_t unk_74[0x8]; /* originally uint64_t ctor: *(qword*)(param_1+0x74) = 0 * */
    /* 0x007C */ int32_t unk_7c; /* ctor: *(int*)(param_1+0x7c) = -1 */
    /* 0x0080 */ uint8_t init_block[0x24]; /* memset covers 0x80..0xA3 */
    /* 0x00A4 */ int32_t unk_a4; /* ctor: *(int*)(param_1+0xa4) = 0 */
    /* 0x00A8 */ uint64_t unk_a8; /* ctor: param_1[0x15] = 0 */
    /* 0x00B0 */ int32_t unk_b0; /* ctor: *(int*)(param_1+0xb0) = 0 */
    /* 0x00B4 */ uint8_t unk_b4[0x8]; /* originally uint64_t MISALIGNED: *(qword*)(param_1+0xb4) = 1 * */
    /* 0x00BC */ int32_t unk_bc; /* ctor: *(int*)(param_1+0xbc) = -1 */
    /* 0x00C0 */ int32_t unk_c0; /* ctor: *(int*)(param_1+0xc0) = 0 */
    /* 0x00C4 */ uint8_t pad_c4[0x44];
    /* 0x0108 */ uint64_t unk_108; /* ctor: param_1[0x21] = 0 */
    /* 0x0110 */ uint64_t rank_param_mgr; /* CreateRankParamManager */
    /* 0x0118 */ uint64_t item_param_mgr; /* CreateItemParamManager */
    /* 0x0120 */ uint64_t file_load_handle; /* RequestFileLoad */
    /* 0x0128 */ uint64_t dialog_handle; /* DeleteDialog */
} ccNetManager;
static_assert(offsetof(ccNetManager, vtable) == 0x0, "ccNetManager.vtable");
static_assert(offsetof(ccNetManager, unk_74) == 0x74, "ccNetManager.unk_74");
static_assert(offsetof(ccNetManager, unk_7c) == 0x7C, "ccNetManager.unk_7c");
static_assert(offsetof(ccNetManager, init_block) == 0x80, "ccNetManager.init_block");
static_assert(offsetof(ccNetManager, unk_a4) == 0xA4, "ccNetManager.unk_a4");
static_assert(offsetof(ccNetManager, unk_a8) == 0xA8, "ccNetManager.unk_a8");
static_assert(offsetof(ccNetManager, unk_b0) == 0xB0, "ccNetManager.unk_b0");
static_assert(offsetof(ccNetManager, unk_b4) == 0xB4, "ccNetManager.unk_b4");
static_assert(offsetof(ccNetManager, unk_bc) == 0xBC, "ccNetManager.unk_bc");
static_assert(offsetof(ccNetManager, unk_c0) == 0xC0, "ccNetManager.unk_c0");
static_assert(offsetof(ccNetManager, unk_108) == 0x108, "ccNetManager.unk_108");
static_assert(offsetof(ccNetManager, rank_param_mgr) == 0x110, "ccNetManager.rank_param_mgr");
static_assert(offsetof(ccNetManager, item_param_mgr) == 0x118, "ccNetManager.item_param_mgr");
static_assert(offsetof(ccNetManager, file_load_handle) == 0x120, "ccNetManager.file_load_handle");
static_assert(offsetof(ccNetManager, dialog_handle) == 0x128, "ccNetManager.dialog_handle");

/* ======================================================================
 * ccNetSession
 * Size: unknown (Abstract base class; no surface fields)
 * ====================================================================== */
typedef struct ccNetSession {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSession;
static_assert(offsetof(ccNetSession, vtable) == 0x00, "ccNetSession.vtable");

/* ======================================================================
 * ccNetSessionXPT
 * Size: unknown (Cross-platform transport; virtual dispatch only)
 * ====================================================================== */
typedef struct ccNetSessionXPT {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSessionXPT;
static_assert(offsetof(ccNetSessionXPT, vtable) == 0x00, "ccNetSessionXPT.vtable");

/* ======================================================================
 * ccNetSessionSearch
 * Size: unknown (No surface fields in s3)
 * ====================================================================== */
typedef struct ccNetSessionSearch {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetSessionSearch;
static_assert(offsetof(ccNetSessionSearch, vtable) == 0x00, "ccNetSessionSearch.vtable");

/* ======================================================================
 * ccNetMatchingUserData
 * Size: unknown (No surface fields in s3)
 * ====================================================================== */
typedef struct ccNetMatchingUserData {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetMatchingUserData;
static_assert(offsetof(ccNetMatchingUserData, vtable) == 0x00, "ccNetMatchingUserData.vtable");

/* ======================================================================
 * ccNetOnlineCheckAdapter
 * Size: unknown (Thin adapter; no surface fields)
 * ====================================================================== */
typedef struct ccNetOnlineCheckAdapter {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetOnlineCheckAdapter;
static_assert(offsetof(ccNetOnlineCheckAdapter, vtable) == 0x00, "ccNetOnlineCheckAdapter.vtable");

/* ======================================================================
 * ccNetLobbyBaseState
 * Size: unknown (No surface fields)
 * ====================================================================== */
typedef struct ccNetLobbyBaseState {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetLobbyBaseState;
static_assert(offsetof(ccNetLobbyBaseState, vtable) == 0x00, "ccNetLobbyBaseState.vtable");

/* ======================================================================
 * ccNetEndlessMatchLobbyState_New
 * Size: unknown (No surface fields)
 * ====================================================================== */
typedef struct ccNetEndlessMatchLobbyState_New {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetEndlessMatchLobbyState_New;
static_assert(offsetof(ccNetEndlessMatchLobbyState_New, vtable) == 0x00, "ccNetEndlessMatchLobbyState_New.vtable");

/* ======================================================================
 * ccNetEndlessMatchAdjustBattleTableState
 * Size: unknown (No surface fields)
 * ====================================================================== */
typedef struct ccNetEndlessMatchAdjustBattleTableState {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetEndlessMatchAdjustBattleTableState;
static_assert(offsetof(ccNetEndlessMatchAdjustBattleTableState, vtable) == 0x00, "ccNetEndlessMatchAdjustBattleTableState.vtable");

/* ======================================================================
 * ccNetTopMenuState
 * Size: unknown (Virtual dispatch only)
 * ====================================================================== */
typedef struct ccNetTopMenuState {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetTopMenuState;
static_assert(offsetof(ccNetTopMenuState, vtable) == 0x00, "ccNetTopMenuState.vtable");

/* ======================================================================
 * ccNetCommunicateUserInfo
 * Size: unknown (No surface fields)
 * ====================================================================== */
typedef struct ccNetCommunicateUserInfo {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08; /* placeholder */
} ccNetCommunicateUserInfo;
static_assert(offsetof(ccNetCommunicateUserInfo, vtable) == 0x00, "ccNetCommunicateUserInfo.vtable");

/* ======================================================================
 * ccNetSessionImpl
 * Size: unknown, >= 0x498
 * ====================================================================== */
typedef struct ccNetSessionImpl {
    /* 0x0000 */ void* vtable; /* vcall at (*vtable+0x10) */
    /* 0x0008 */ uint8_t pad_8[0x120];
    /* 0x0128 */ int32_t owner_ctrl_state; /* ChangeOwnerCtrl_STOP_SOCKET */
    /* 0x012C */ uint8_t pad_12c[0x35C];
    /* 0x0488 */ void* unk_488_ptr; /* if (param_1[0x91] != 0) */
    /* 0x0490 */ void* unk_490_ptr; /* if (param_1[0x92] != 0) */
} ccNetSessionImpl;
static_assert(offsetof(ccNetSessionImpl, vtable) == 0x0, "ccNetSessionImpl.vtable");
static_assert(offsetof(ccNetSessionImpl, owner_ctrl_state) == 0x128, "ccNetSessionImpl.owner_ctrl_state");
static_assert(offsetof(ccNetSessionImpl, unk_488_ptr) == 0x488, "ccNetSessionImpl.unk_488_ptr");
static_assert(offsetof(ccNetSessionImpl, unk_490_ptr) == 0x490, "ccNetSessionImpl.unk_490_ptr");

/* ======================================================================
 * ccNetSessionAdapter
 * Size: unknown, >= 0xA10
 * ====================================================================== */
typedef struct ccNetSessionAdapter {
    /* 0x0000 */ void* vtable; /* vtable slots: +0x28(Ctrl), +0x58(GetSessionParam) */
    /* 0x0008 */ uint8_t pad_8[0x2C];
    /* 0x0034 */ int32_t invite_state; /* JoinInvite: if (*(int*)(param_1+0x34) == 1) */
    /* 0x0038 */ uint8_t pad_38[0x14];
    /* 0x004C */ int32_t ctrl_field_4c; /* Ctrl: *(int*)(param_1+0x4c) = lVar1 */
    /* 0x0050 */ uint8_t pad_50[0x4];
    /* 0x0054 */ int32_t ctrl_field_54; /* Ctrl: *(int*)(param_1+0x54) = 0 */
    /* 0x0058 */ uint8_t pad_58[0xA0];
    /* 0x00F8 */ int32_t session_param_f8; /* GetSessionParam: copy from sub-object +0x2C */
    /* 0x00FC */ int32_t session_param_fc; /* GetSessionParam: copy from sub-object +0x7C */
    /* 0x0100 */ int32_t session_param_100; /* GetSessionParam: copy from sub-object +0x28 */
    /* 0x0104 */ uint8_t session_data_block[0x18]; /* FUN_1406a2b70 copies 0x18 bytes */
    /* 0x011C */ uint8_t pad_11c[0x8D4];
    /* 0x09F0 */ void* user_data_ptr; /* SendMyUserData: if (param_1[0x13e] != 0) */
    /* 0x09F8 */ void* invite_subobj; /* JoinInvite: vcall on subobj */
    /* 0x0A00 */ uint8_t pad_a00[0x8];
    /* 0x0A08 */ void* ctrl_subobj; /* Ctrl: if (param_1[0x141] != 0) */
} ccNetSessionAdapter;
static_assert(offsetof(ccNetSessionAdapter, vtable) == 0x0, "ccNetSessionAdapter.vtable");
static_assert(offsetof(ccNetSessionAdapter, invite_state) == 0x34, "ccNetSessionAdapter.invite_state");
static_assert(offsetof(ccNetSessionAdapter, ctrl_field_4c) == 0x4C, "ccNetSessionAdapter.ctrl_field_4c");
static_assert(offsetof(ccNetSessionAdapter, ctrl_field_54) == 0x54, "ccNetSessionAdapter.ctrl_field_54");
static_assert(offsetof(ccNetSessionAdapter, session_param_f8) == 0xF8, "ccNetSessionAdapter.session_param_f8");
static_assert(offsetof(ccNetSessionAdapter, session_param_fc) == 0xFC, "ccNetSessionAdapter.session_param_fc");
static_assert(offsetof(ccNetSessionAdapter, session_param_100) == 0x100, "ccNetSessionAdapter.session_param_100");
static_assert(offsetof(ccNetSessionAdapter, session_data_block) == 0x104, "ccNetSessionAdapter.session_data_block");
static_assert(offsetof(ccNetSessionAdapter, user_data_ptr) == 0x9F0, "ccNetSessionAdapter.user_data_ptr");
static_assert(offsetof(ccNetSessionAdapter, invite_subobj) == 0x9F8, "ccNetSessionAdapter.invite_subobj");
static_assert(offsetof(ccNetSessionAdapter, ctrl_subobj) == 0xA08, "ccNetSessionAdapter.ctrl_subobj");

/* ======================================================================
 * ccNetSessionManager
 * Size: unknown, >= 0x608
 * ====================================================================== */
typedef struct ccNetSessionManager {
    /* 0x0000 */ void* vtable; /* vtable slots: +0x10(Init), +0xA0(Finalize1) */
    /* 0x0008 */ uint8_t pad_8[0x78];
    /* 0x0080 */ uint8_t init_region[0x44]; /* Initialize: vcall at +0x80 */
    /* 0x00C4 */ uint8_t session_array[0x40]; /* memset(+0xC4, 0, 0x40) */
    /* 0x0104 */ uint8_t pad_104[0x3FC];
    /* 0x0500 */ uint8_t finalize_region_1[0x100]; /* Finalize: vcall at +0x500 */
    /* 0x0600 */ uint8_t finalize_region_2[0x08]; /* Finalize: vcall at +0x600 */
} ccNetSessionManager;
static_assert(offsetof(ccNetSessionManager, vtable) == 0x0, "ccNetSessionManager.vtable");
static_assert(offsetof(ccNetSessionManager, init_region) == 0x80, "ccNetSessionManager.init_region");
static_assert(offsetof(ccNetSessionManager, session_array) == 0xC4, "ccNetSessionManager.session_array");
static_assert(offsetof(ccNetSessionManager, finalize_region_1) == 0x500, "ccNetSessionManager.finalize_region_1");
static_assert(offsetof(ccNetSessionManager, finalize_region_2) == 0x600, "ccNetSessionManager.finalize_region_2");

/* ======================================================================
 * ccNetSessionSearchAdapter
 * Size: 0x588 (confirmed from CreateSearch allocation)
 * Vtable: PTR_FUN_14096c490
 * ====================================================================== */
typedef struct ccNetSessionSearchAdapter {
    /* 0x0000 */ void* vtable; /* PTR_FUN_14096c490 */
    /* 0x0008 */ void* next; /* linked list node; ctor: param_1[1] = 0 */
    /* 0x0010 */ void* tcp_subobj; /* ctor: param_1[2] = sub-object */
    /* 0x0018 */ uint8_t pad_18[0x4];
    /* 0x001C */ uint8_t unk_1c[0x8]; /* originally uint64_t MISALIGNED: *(qword*)(param_1+0x1c) = 1 * */
    /* 0x0024 */ uint8_t unk_24[0x8]; /* originally uint64_t MISALIGNED: *(qword*)(param_1+0x24) = 0 * */
    /* 0x002C */ uint8_t cleared_block[0x540]; /* memset(+0x2C, 0, 0x540) */
    /* 0x056C */ uint8_t pad_56c[0x4];
    /* 0x0570 */ void* manager_backptr; /* CreateSearch: backptr to manager */
    /* 0x0578 */ int32_t search_index; /* CreateSearch: counter */
    /* 0x057C */ uint8_t pad_57c[0x4];
    /* 0x0580 */ int32_t unk_580; /* ctor: *(int*)(param_1+0x580) = 0 */
} ccNetSessionSearchAdapter;
static_assert(offsetof(ccNetSessionSearchAdapter, vtable) == 0x0, "ccNetSessionSearchAdapter.vtable");
static_assert(offsetof(ccNetSessionSearchAdapter, next) == 0x8, "ccNetSessionSearchAdapter.next");
static_assert(offsetof(ccNetSessionSearchAdapter, tcp_subobj) == 0x10, "ccNetSessionSearchAdapter.tcp_subobj");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_1c) == 0x1C, "ccNetSessionSearchAdapter.unk_1c");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_24) == 0x24, "ccNetSessionSearchAdapter.unk_24");
static_assert(offsetof(ccNetSessionSearchAdapter, cleared_block) == 0x2C, "ccNetSessionSearchAdapter.cleared_block");
static_assert(offsetof(ccNetSessionSearchAdapter, manager_backptr) == 0x570, "ccNetSessionSearchAdapter.manager_backptr");
static_assert(offsetof(ccNetSessionSearchAdapter, search_index) == 0x578, "ccNetSessionSearchAdapter.search_index");
static_assert(offsetof(ccNetSessionSearchAdapter, unk_580) == 0x580, "ccNetSessionSearchAdapter.unk_580");
static_assert(sizeof(ccNetSessionSearchAdapter) == 0x588, "ccNetSessionSearchAdapter size");

/* ======================================================================
 * ccNetSessionInfoEX
 * Size: unknown, >= 0x98
 * ====================================================================== */
typedef struct ccNetSessionInfoEX {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x24];
    /* 0x002C */ int32_t info_field_2c; /* operator=: param_1[0xb] = param_2[0xc] */
    /* 0x0030 */ int32_t info_field_30; /* operator=: param_1[0xc] = param_2[0xd] */
    /* 0x0034 */ uint8_t pad_34[0x4];
    /* 0x0038 */ void* info_ptr_38; /* operator=: puVar5 = param_1 + 0xe */
    /* 0x0040 */ uint8_t pad_40[0x20];
    /* 0x0060 */ uint64_t info_field_60; /* operator=: uVar4 = *(qword*)(param_1+0x18) */
    /* 0x0068 */ uint8_t pad_68[0xC];
    /* 0x0074 */ int32_t info_field_74; /* operator=: read */
    /* 0x0078 */ uint8_t pad_78[0x4];
    /* 0x007C */ int32_t info_field_7c; /* operator=: rw */
    /* 0x0080 */ char name_buffer[0x17]; /* strncpy to +0x80, len 0x17 */
} ccNetSessionInfoEX;
static_assert(offsetof(ccNetSessionInfoEX, vtable) == 0x0, "ccNetSessionInfoEX.vtable");
static_assert(offsetof(ccNetSessionInfoEX, info_field_2c) == 0x2C, "ccNetSessionInfoEX.info_field_2c");
static_assert(offsetof(ccNetSessionInfoEX, info_field_30) == 0x30, "ccNetSessionInfoEX.info_field_30");
static_assert(offsetof(ccNetSessionInfoEX, info_ptr_38) == 0x38, "ccNetSessionInfoEX.info_ptr_38");
static_assert(offsetof(ccNetSessionInfoEX, info_field_60) == 0x60, "ccNetSessionInfoEX.info_field_60");
static_assert(offsetof(ccNetSessionInfoEX, info_field_74) == 0x74, "ccNetSessionInfoEX.info_field_74");
static_assert(offsetof(ccNetSessionInfoEX, info_field_7c) == 0x7C, "ccNetSessionInfoEX.info_field_7c");
static_assert(offsetof(ccNetSessionInfoEX, name_buffer) == 0x80, "ccNetSessionInfoEX.name_buffer");

/* ======================================================================
 * ccNetMatchingReady
 * Size: unknown, >= 0x1A
 * ====================================================================== */
typedef struct ccNetMatchingReady {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0xD];
    /* 0x0015 */ uint8_t match_result_15; /* Ctrl: write from uVar8 */
    /* 0x0016 */ uint8_t match_result_16; /* Ctrl: write from uVar8 */
    /* 0x0017 */ uint8_t ready_flag; /* Ctrl: read, non-zero check */
    /* 0x0018 */ uint8_t pad_18[0x1];
    /* 0x0019 */ uint8_t unk_19; /* Ctrl: cVar2 = *(char*)(param_1+0x19) */
} ccNetMatchingReady;
static_assert(offsetof(ccNetMatchingReady, vtable) == 0x0, "ccNetMatchingReady.vtable");
static_assert(offsetof(ccNetMatchingReady, match_result_15) == 0x15, "ccNetMatchingReady.match_result_15");
static_assert(offsetof(ccNetMatchingReady, match_result_16) == 0x16, "ccNetMatchingReady.match_result_16");
static_assert(offsetof(ccNetMatchingReady, ready_flag) == 0x17, "ccNetMatchingReady.ready_flag");
static_assert(offsetof(ccNetMatchingReady, unk_19) == 0x19, "ccNetMatchingReady.unk_19");

/* ======================================================================
 * ccNetStartUp::Impl
 * Size: unknown, >= 0x68
 * ====================================================================== */
typedef struct ccNetStartUp_Impl {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x4];
    /* 0x000C */ int32_t ctrl_state; /* Impl::Ctrl: *(int*)(param_1+0xc) = 1 */
    /* 0x0010 */ uint8_t pad_10[0x50];
    /* 0x0060 */ uint64_t ctrl_field_60; /* Impl::Ctrl: param_1[0xc] = 0 */
} ccNetStartUp_Impl;
static_assert(offsetof(ccNetStartUp_Impl, vtable) == 0x0, "ccNetStartUp_Impl.vtable");
static_assert(offsetof(ccNetStartUp_Impl, ctrl_state) == 0xC, "ccNetStartUp_Impl.ctrl_state");
static_assert(offsetof(ccNetStartUp_Impl, ctrl_field_60) == 0x60, "ccNetStartUp_Impl.ctrl_field_60");

/* ======================================================================
 * ccNetStartUp
 * Size: unknown (thin wrapper around Impl)
 * ====================================================================== */
typedef struct ccNetStartUp {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x4];
    /* 0x000C */ int32_t ctrl_state; /* Impl::Ctrl: *(int*)(param_1+0xc) = 1 */
    /* 0x0010 */ uint8_t pad_10[0x50];
    /* 0x0060 */ uint64_t ctrl_field_60; /* Impl::Ctrl: param_1[0xc] = 0 */
} ccNetStartUp;
static_assert(offsetof(ccNetStartUp, vtable) == 0x0, "ccNetStartUp.vtable");
static_assert(offsetof(ccNetStartUp, ctrl_state) == 0xC, "ccNetStartUp.ctrl_state");
static_assert(offsetof(ccNetStartUp, ctrl_field_60) == 0x60, "ccNetStartUp.ctrl_field_60");

/* ======================================================================
 * ccNetOnlineCheck::Impl
 * Size: unknown, >= 0x34
 * ====================================================================== */
typedef struct ccNetOnlineCheck_Impl {
    /* 0x0000 */ void* connection_handle; /* ~Impl: freed conditionally */
    /* 0x0008 */ uint8_t pad_8[0x4];
    /* 0x000C */ uint8_t unk_0c[0x8]; /* originally uint64_t MISALIGNED: ~Impl cleared to 0 * */
    /* 0x0014 */ uint8_t pad_14[0x18];
    /* 0x002C */ uint8_t unk_2c[0x8]; /* originally uint64_t MISALIGNED: ~Impl cleared to 0 * */
} ccNetOnlineCheck_Impl;
static_assert(offsetof(ccNetOnlineCheck_Impl, connection_handle) == 0x0, "ccNetOnlineCheck_Impl.connection_handle");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_0c) == 0xC, "ccNetOnlineCheck_Impl.unk_0c");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_2c) == 0x2C, "ccNetOnlineCheck_Impl.unk_2c");

/* ======================================================================
 * ccNetOnlineCheck
 * Size: unknown (thin pimpl wrapper)
 * ====================================================================== */
typedef struct ccNetOnlineCheck {
    /* 0x0000 */ void* vtable;
    /* 0x0008 */ uint8_t pad_8[0x4];
    /* 0x000C */ uint8_t unk_0c[0x8]; /* originally uint64_t MISALIGNED: ~Impl cleared to 0 * */
    /* 0x0014 */ uint8_t pad_14[0x18];
    /* 0x002C */ uint8_t unk_2c[0x8]; /* originally uint64_t MISALIGNED: ~Impl cleared to 0 * */
} ccNetOnlineCheck;
static_assert(offsetof(ccNetOnlineCheck, vtable) == 0x0, "ccNetOnlineCheck.vtable");
static_assert(offsetof(ccNetOnlineCheck, unk_0c) == 0xC, "ccNetOnlineCheck.unk_0c");
static_assert(offsetof(ccNetOnlineCheck, unk_2c) == 0x2C, "ccNetOnlineCheck.unk_2c");

#endif /* CC_NET_SESSION_S3_H */
