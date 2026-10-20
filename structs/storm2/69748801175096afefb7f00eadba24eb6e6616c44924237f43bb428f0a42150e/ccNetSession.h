/*
 * ccNetSession network classes — NARUTO STORM 2 PC (s2, NSUNS2.exe)
 * INFERRED layout from static analysis (state_surface + decompiled ctors/methods).
 * NOT CONFIRMED at runtime. All offsets are x64 PC (image base 0x140000000).
 * Names from s2 own-game symbols/strings only; no cross-game name reuse.
 */
#ifndef CC_NET_SESSION_S2_H
#define CC_NET_SESSION_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ======================================================================
 * ccNetMatchingReady
 * Size: unknown, >= 0x18 (highest proven field end: 0x12 + 1 = 0x13)
 * Vtable: not directly observed in ctor (likely set by caller or base)
 * Evidence: ccNetMatchingReady::Ctrl writes fields at +0x11, +0x12;
 *           ::Ready writes +0x04 (int), +0x10 (byte);
 *           ::Ctrl reads param_1[2] (+0x08 int), param_1[3] (+0x0C int),
 *           and *param_1 (+0x00 int)
 * ====================================================================== */
typedef struct ccNetMatchingReady {
    /* 0x00 */ int32_t  status;            /* Ctrl: *param_1 = 0; Ready sets via vtable call */
    /* 0x04 */ int32_t  ready_flag;        /* Ready: *(int*)(param_1+4) = 1 */
    /* 0x08 */ int32_t  unk_08;            /* Ctrl: param_1[2] read/write */
    /* 0x0C */ int32_t  unk_0c;            /* Ctrl: param_1[3] read/write */
    /* 0x10 */ uint8_t  unk_10;            /* Ready: *(byte*)(param_1+0x10) = 0 */
    /* 0x11 */ uint8_t  match_result_lo;   /* Ctrl: write from vtable+0xf8 result low byte */
    /* 0x12 */ uint8_t  match_result_hi;   /* Ctrl: write from vtable+0xf8 result high byte */
    /* 0x13 */ uint8_t  pad_13[5];         /* padding to alignment */
} ccNetMatchingReady;
static_assert(offsetof(ccNetMatchingReady, status) == 0x00, "ccNetMatchingReady.status");
static_assert(offsetof(ccNetMatchingReady, ready_flag) == 0x04, "ccNetMatchingReady.ready_flag");
static_assert(offsetof(ccNetMatchingReady, unk_08) == 0x08, "ccNetMatchingReady.unk_08");
static_assert(offsetof(ccNetMatchingReady, unk_0c) == 0x0C, "ccNetMatchingReady.unk_0c");
static_assert(offsetof(ccNetMatchingReady, unk_10) == 0x10, "ccNetMatchingReady.unk_10");
static_assert(offsetof(ccNetMatchingReady, match_result_lo) == 0x11, "ccNetMatchingReady.match_result_lo");
static_assert(offsetof(ccNetMatchingReady, match_result_hi) == 0x12, "ccNetMatchingReady.match_result_hi");

/* ======================================================================
 * ccNetMatchingUserData
 * Size: unknown, >= 0xC8 (highest proven field: +0xC0 ptr read)
 * Evidence: SendUserData reads contiguous block +0x08..+0x58 as payload,
 *           reads +0xC0 as interface ptr; Ctrl writes +0x60..+0xBC
 * ====================================================================== */
typedef struct ccNetMatchingUserData {
    /* 0x00 */ void*    vtable;            /* assumed; standard pattern */
    /* 0x08 */ uint64_t user_data[11];     /* SendUserData copies +0x08..+0x58 as payload (11 qwords) */
    /* 0x60 */ uint64_t ctrl_field_0;      /* Ctrl: param_1[0xc] */
    /* 0x68 */ uint64_t ctrl_field_1;      /* Ctrl: param_1[0xd] */
    /* 0x70 */ uint64_t ctrl_field_2;      /* Ctrl: param_1[0xe] */
    /* 0x78 */ uint64_t ctrl_field_3;      /* Ctrl: param_1[0xf] */
    /* 0x80 */ uint64_t ctrl_field_4;      /* Ctrl: param_1[0x10] */
    /* 0x88 */ uint64_t ctrl_field_5;      /* Ctrl: param_1[0x11] */
    /* 0x90 */ uint64_t ctrl_field_6;      /* Ctrl: param_1[0x12] */
    /* 0x98 */ uint64_t ctrl_field_7;      /* Ctrl: param_1[0x13] */
    /* 0xA0 */ uint32_t ctrl_field_8;      /* Ctrl: *(uint*)(param_1+0x14) */
    /* 0xA4 */ uint32_t ctrl_field_9;      /* Ctrl: *(uint*)(param_1+0xa4) */
    /* 0xA8 */ uint32_t ctrl_field_a;      /* Ctrl: *(uint*)(param_1+0x15) */
    /* 0xAC */ uint32_t ctrl_field_b;      /* Ctrl: *(uint*)(param_1+0xac) */
    /* 0xB0 */ uint64_t ctrl_field_c;      /* Ctrl: param_1[0x16] */
    /* 0xB8 */ uint32_t ctrl_field_d;      /* Ctrl: *(uint*)(param_1+0x17) = 1 */
    /* 0xBC */ uint32_t pad_bc;
    /* 0xC0 */ void*    net_interface;     /* SendUserData: reads *(ptr*)(param_1+0xc0) */
} ccNetMatchingUserData;
static_assert(offsetof(ccNetMatchingUserData, vtable) == 0x00, "ccNetMatchingUserData.vtable");
static_assert(offsetof(ccNetMatchingUserData, user_data) == 0x08, "ccNetMatchingUserData.user_data");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_0) == 0x60, "ccNetMatchingUserData.ctrl_field_0");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_8) == 0xA0, "ccNetMatchingUserData.ctrl_field_8");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_9) == 0xA4, "ccNetMatchingUserData.ctrl_field_9");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_a) == 0xA8, "ccNetMatchingUserData.ctrl_field_a");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_b) == 0xAC, "ccNetMatchingUserData.ctrl_field_b");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_c) == 0xB0, "ccNetMatchingUserData.ctrl_field_c");
static_assert(offsetof(ccNetMatchingUserData, ctrl_field_d) == 0xB8, "ccNetMatchingUserData.ctrl_field_d");
static_assert(offsetof(ccNetMatchingUserData, net_interface) == 0xC0, "ccNetMatchingUserData.net_interface");

/* ======================================================================
 * ccNetOnlineCheck::Impl (nested impl class)
 * Size: unknown, >= 0x50 (destructor accesses param_1[9] = +0x48)
 * Evidence: ~Impl frees +0x00 ptr, checks +0x48/+0x38/+0x40, clears +0x2C/+0x0C,
 *           accesses +0x18 (param_1[3]), +0x20 (param_1[4])
 * ====================================================================== */
#pragma pack(push, 4)
typedef struct ccNetOnlineCheck_Impl {
    /* 0x00 */ void*    connection_handle; /* ~Impl: if (*param_1 != 0) free */
    /* 0x08 */ uint32_t unk_08;
    /* 0x0C */ uint64_t unk_0c;            /* ~Impl: cleared to 0 */
    /* 0x14 */ uint32_t unk_14;            /* gap filler */
    /* 0x18 */ void*    callback_ptr;      /* ~Impl: param_1[3], freed conditionally */
    /* 0x20 */ uint64_t callback_owned;    /* ~Impl: param_1[4], bool-like flag */
    /* 0x28 */ uint32_t unk_28;
    /* 0x2C */ uint64_t unk_2c;            /* ~Impl: cleared to 0 */
    /* 0x34 */ uint32_t unk_34;            /* gap filler */
    /* 0x38 */ void*    unk_38_ptr;        /* ~Impl: param_1[7], freed conditionally */
    /* 0x40 */ uint64_t unk_40_owned;      /* ~Impl: param_1[8], bool-like flag */
    /* 0x48 */ void*    unk_48_ptr;        /* ~Impl: param_1[9], vcall+0x20 */
} ccNetOnlineCheck_Impl;
#pragma pack(pop)
static_assert(offsetof(ccNetOnlineCheck_Impl, connection_handle) == 0x00, "ccNetOnlineCheck_Impl.connection_handle");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_0c) == 0x0C, "ccNetOnlineCheck_Impl.unk_0c");
static_assert(offsetof(ccNetOnlineCheck_Impl, callback_ptr) == 0x18, "ccNetOnlineCheck_Impl.callback_ptr");
static_assert(offsetof(ccNetOnlineCheck_Impl, callback_owned) == 0x20, "ccNetOnlineCheck_Impl.callback_owned");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_2c) == 0x2C, "ccNetOnlineCheck_Impl.unk_2c");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_38_ptr) == 0x38, "ccNetOnlineCheck_Impl.unk_38_ptr");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_40_owned) == 0x40, "ccNetOnlineCheck_Impl.unk_40_owned");
static_assert(offsetof(ccNetOnlineCheck_Impl, unk_48_ptr) == 0x48, "ccNetOnlineCheck_Impl.unk_48_ptr");

/* ======================================================================
 * ccNetOnlineCheck
 * Size: unknown, >= 0x10 (wraps Impl pointer)
 * Evidence: IsDisconnected/IsError/IsSystemResumeCallback are thin wrappers;
 *           Impl is a separate heap object managed by this class
 * ====================================================================== */
typedef struct ccNetOnlineCheck {
    /* 0x00 */ void*    vtable;
    /* 0x08 */ ccNetOnlineCheck_Impl* impl;
} ccNetOnlineCheck;
static_assert(offsetof(ccNetOnlineCheck, vtable) == 0x00, "ccNetOnlineCheck.vtable");
static_assert(offsetof(ccNetOnlineCheck, impl) == 0x08, "ccNetOnlineCheck.impl");

/* ======================================================================
 * ccNetOnlineCheckAdapter
 * Size: unknown (no surface fields found; thin adapter wrapper)
 * Evidence: state_surface returned 0 fields; likely a small wrapper
 * ====================================================================== */
typedef struct ccNetOnlineCheckAdapter {
    /* 0x00 */ void*    vtable;
    /* 0x08 */ uint64_t unk_08;            /* placeholder; size unknown */
} ccNetOnlineCheckAdapter;
static_assert(offsetof(ccNetOnlineCheckAdapter, vtable) == 0x00, "ccNetOnlineCheckAdapter.vtable");

/* ======================================================================
 * ccNetSession
 * Size: unknown (no surface fields found; base class)
 * Evidence: state_surface returned 0 fields; destructor calls FUN_14066a750
 * ====================================================================== */
typedef struct ccNetSession {
    /* 0x00 */ void*    vtable;
    /* 0x08 */ uint64_t unk_08;            /* placeholder; size unknown */
} ccNetSession;
static_assert(offsetof(ccNetSession, vtable) == 0x00, "ccNetSession.vtable");

/* ======================================================================
 * ccNetSessionSearch_TCPSubObject
 * Size: 0x20 (allocated via LoadTh(0x20, ...))
 * Vtable: PTR_FUN_1408a2e88
 * Evidence: ccNetSessionSearch ctor allocates 0x20 bytes, sets vtable,
 *           initializes puVar1[1]=0, *(uint*)(puVar1+2)=0, *(qword*)(puVar1+0x14)=0
 * ====================================================================== */
typedef struct ccNetSessionSearch_TCPSubObject {
    /* 0x00 */ void*    vtable;            /* PTR_FUN_1408a2e88 */
    /* 0x08 */ uint64_t unk_08;            /* ctor: puVar1[1] = 0 */
    /* 0x10 */ uint32_t unk_10;            /* ctor: *(uint*)(puVar1+2) = 0 */
    /* 0x14 */ uint32_t pad_14;            /* explicit pad; unk_14 is qword at 0x18 */
    /* 0x18 */ uint64_t unk_14;            /* ctor: *(qword*)(puVar1+0x14) = 0 → actual offset 0x18 after align */
} ccNetSessionSearch_TCPSubObject;
static_assert(sizeof(ccNetSessionSearch_TCPSubObject) == 0x20, "ccNetSessionSearch_TCPSubObject size");
static_assert(offsetof(ccNetSessionSearch_TCPSubObject, vtable) == 0x00, "TCPSubObject.vtable");
static_assert(offsetof(ccNetSessionSearch_TCPSubObject, unk_08) == 0x08, "TCPSubObject.unk_08");
static_assert(offsetof(ccNetSessionSearch_TCPSubObject, unk_10) == 0x10, "TCPSubObject.unk_10");
static_assert(offsetof(ccNetSessionSearch_TCPSubObject, unk_14) == 0x18, "TCPSubObject.unk_14");

/* ======================================================================
 * ccNetSessionSearch
 * Size: unknown, >= 0x548 (highest proven field: param_1[0xa8] at +0x540)
 * Vtable: PTR_FUN_1408a2708
 * Alloc: sub-object via LoadTh(0x20, "ccNetSessionTCPSocket_Win32.cpp", 0x11d)
 * Evidence: ctor sets vtable, allocates TCP socket sub-object at +0x08;
 *           IsSearchEnd reads +0x3C, writes +0x44/+0x4C/+0x58, reads +0xA8/+0x540
 * ====================================================================== */
typedef struct ccNetSessionSearch {
    /* 0x00 */ void*    vtable;            /* PTR_FUN_1408a2708 */
    /* 0x08 */ ccNetSessionSearch_TCPSubObject* tcp_socket; /* ctor: param_1[1] = sub-obj */
    /* 0x10 */ uint8_t  pad_10[0x2C];     /* gap to first surface field */
    /* 0x3C */ int32_t  search_state;      /* IsSearchEnd: read */
    /* 0x40 */ uint32_t pad_40;
    /* 0x44 */ int32_t  search_end_flag;   /* IsSearchEnd: written = 1 */
    /* 0x48 */ uint32_t pad_48;
    /* 0x4C */ int32_t  unk_4c;            /* IsSearchEnd: written = 0 */
    /* 0x50 */ uint32_t pad_50;
    /* 0x54 */ int32_t  result_index;      /* IsSearchEnd: param_1[0xb] incremented */
    /* 0x58 */ int32_t  unk_58;            /* IsSearchEnd: written */
    /* 0x5C */ uint8_t  pad_5c[0x4E4];    /* gap to +0x540 */
    /* 0x540 */ int64_t result_count;     /* IsSearchEnd: param_1[0xa8] compared */
} ccNetSessionSearch;
static_assert(offsetof(ccNetSessionSearch, vtable) == 0x00, "ccNetSessionSearch.vtable");
static_assert(offsetof(ccNetSessionSearch, tcp_socket) == 0x08, "ccNetSessionSearch.tcp_socket");
static_assert(offsetof(ccNetSessionSearch, search_state) == 0x3C, "ccNetSessionSearch.search_state");
static_assert(offsetof(ccNetSessionSearch, search_end_flag) == 0x44, "ccNetSessionSearch.search_end_flag");
static_assert(offsetof(ccNetSessionSearch, unk_4c) == 0x4C, "ccNetSessionSearch.unk_4c");
static_assert(offsetof(ccNetSessionSearch, result_index) == 0x54, "ccNetSessionSearch.result_index");
static_assert(offsetof(ccNetSessionSearch, unk_58) == 0x58, "ccNetSessionSearch.unk_58");
static_assert(offsetof(ccNetSessionSearch, result_count) == 0x540, "ccNetSessionSearch.result_count");

/* ======================================================================
 * ccNetSessionSearchAdapter
 * Size: 0x558 (from CreateSearch: LoadTh(0x558, ...))
 * Vtable: PTR_FUN_140800810
 * Evidence: ctor initializes fields; CreateSearch allocates exactly 0x558 bytes;
 *           linked list node at +0x18 (next ptr); manager back-ptr at +0x548; index at +0x550
 * ====================================================================== */
#pragma pack(push, 4)
typedef struct ccNetSessionSearchAdapter {
    /* 0x00 */ void*    vtable;            /* PTR_FUN_140800810 */
    /* 0x08 */ uint64_t unk_08;            /* ctor: not directly set (inherited/default) */
    /* 0x10 */ uint64_t unk_10;            /* ctor: not directly set (inherited/default) */
    /* 0x18 */ struct ccNetSessionSearchAdapter* next; /* ctor: param_1[3]=0; CreateSearch linked list */
    /* 0x20 */ uint64_t unk_20;            /* ctor: *puVar1=0 (param_1+4, qword at 0x20) */
    /* 0x28 */ uint64_t unk_28;            /* ctor: param_1[5]=0 (qword at 0x28) */
    /* 0x30 */ uint32_t unk_30;            /* ctor: *(uint*)(param_1+6)=0 */
    /* 0x34 */ uint64_t unk_34;            /* ctor: *(qword*)(param_1+0x34)=1 */
    /* 0x3C */ uint64_t unk_3c;            /* ctor: *(qword*)(param_1+0x3c)=0 */
    /* 0x44 */ uint64_t unk_44;            /* ctor: *(qword*)(param_1+0x44)=0 */
    /* 0x4C */ uint64_t unk_4c;            /* ctor: *(qword*)(param_1+0x4c)=0 (written twice) */
    /* 0x54 */ uint64_t unk_54;            /* ctor: *(qword*)(param_1+0x54)=0 */
    /* 0x5C */ uint32_t unk_5c;            /* ctor: *(uint*)(param_1+0x5c)=0 */
    /* 0x60 */ uint8_t  session_info_block[0x98]; /* 0x60..0xF8 */
    /* 0xF8 */ uint8_t  unk_f8_block[0x448]; /* ctor loop area; 0xF8..0x540 */
    /* 0x540 */ uint32_t unk_540;           /* ctor: *(uint*)(param_1+0xa8)=0 */
    /* 0x544 */ uint32_t pad_544;
    /* 0x548 */ void*    manager_backptr;   /* CreateSearch: back-pointer to manager */
    /* 0x550 */ uint32_t search_index;      /* CreateSearch: index within manager's list */
    /* 0x554 */ uint32_t pad_554;
} ccNetSessionSearchAdapter;
#pragma pack(pop)
static_assert(sizeof(ccNetSessionSearchAdapter) == 0x558, "ccNetSessionSearchAdapter size");
static_assert(offsetof(ccNetSessionSearchAdapter, vtable) == 0x00, "ccNetSessionSearchAdapter.vtable");
static_assert(offsetof(ccNetSessionSearchAdapter, next) == 0x18, "ccNetSessionSearchAdapter.next");
static_assert(offsetof(ccNetSessionSearchAdapter, session_info_block) == 0x60, "ccNetSessionSearchAdapter.session_info_block");
static_assert(offsetof(ccNetSessionSearchAdapter, manager_backptr) == 0x548, "ccNetSessionSearchAdapter.manager_backptr");
static_assert(offsetof(ccNetSessionSearchAdapter, search_index) == 0x550, "ccNetSessionSearchAdapter.search_index");

/* ======================================================================
 * ccNetSessionAdapter
 * Size: unknown (no surface fields found)
 * Evidence: state_surface returned 0 fields; likely thin adapter wrapper
 * ====================================================================== */
typedef struct ccNetSessionAdapter {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08;             /* placeholder; size unknown */
} ccNetSessionAdapter;
static_assert(offsetof(ccNetSessionAdapter, vtable) == 0x00, "ccNetSessionAdapter.vtable");

/* ======================================================================
 * ccNetSessionImpl
 * Size: unknown (no surface fields found)
 * Evidence: state_surface returned 0 fields; implementation detail class
 * ====================================================================== */
typedef struct ccNetSessionImpl {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08;             /* placeholder; size unknown */
} ccNetSessionImpl;
static_assert(offsetof(ccNetSessionImpl, vtable) == 0x00, "ccNetSessionImpl.vtable");

/* ======================================================================
 * ccNetSessionInfoEX
 * Size: unknown (no surface fields found)
 * Evidence: state_surface returned 0 fields; extended session info struct
 * ====================================================================== */
typedef struct ccNetSessionInfoEX {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08;             /* placeholder; size unknown */
} ccNetSessionInfoEX;
static_assert(offsetof(ccNetSessionInfoEX, vtable) == 0x00, "ccNetSessionInfoEX.vtable");

/* ======================================================================
 * ccNetSessionManager
 * Size: unknown (no surface fields found)
 * Evidence: state_surface returned 0 fields; manages session lifecycle
 * ====================================================================== */
typedef struct ccNetSessionManager {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08;             /* placeholder; size unknown */
} ccNetSessionManager;
static_assert(offsetof(ccNetSessionManager, vtable) == 0x00, "ccNetSessionManager.vtable");

/* ======================================================================
 * ccNetSessionXPT
 * Size: unknown (no surface fields found)
 * Evidence: state_surface returned 0 fields; XPT (cross-platform transport?)
 * ====================================================================== */
typedef struct ccNetSessionXPT {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08;             /* placeholder; size unknown */
} ccNetSessionXPT;
static_assert(offsetof(ccNetSessionXPT, vtable) == 0x00, "ccNetSessionXPT.vtable");

/* ======================================================================
 * ccNetStartUp
 * Size: unknown (no surface fields found)
 * Evidence: state_surface returned 0 fields; network initialization class
 * ====================================================================== */
typedef struct ccNetStartUp {
    /* 0x00 */ void* vtable;
    /* 0x08 */ uint64_t unk_08;             /* placeholder; size unknown */
} ccNetStartUp;
static_assert(offsetof(ccNetStartUp, vtable) == 0x00, "ccNetStartUp.vtable");

#endif /* CC_NET_SESSION_S2_H */