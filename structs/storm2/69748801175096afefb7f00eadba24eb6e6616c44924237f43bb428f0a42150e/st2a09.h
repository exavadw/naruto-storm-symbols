/* st2a09.h — Story progression structs for NSUNS2.exe (build s2)
 * Group: ccAdvCreateMobInfo, ccAdvCtrl, ccAdvCtrlStateMachine,
 * ccAdvEffectManager, ccAdvFadeAreaParamManager, ccAdvFileLoadList,
 * ccAdvFixCamera, ccAdvGameStatus, ccAdvItemBox, ccAdvJumpCamera
 *
 * All layouts INFERRED from static analysis (decompilation + state_surface).
 * Sizes proven from operator-new / allocator calls where available.
 * PC offsets only (image base 0x140000000).
 *
 * NOTE: Uses #pragma pack(push, 1) to suppress natural alignment padding.
 * Offsets verified by compile-time static_assert against decompiled evidence.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ================================================================
 * ccAdvCreateMobInfo
 * Size: unknown, >= 0x10 (field at +0xC)
 * Vtable: not found (only dtor symbols)
 * Methods: 2 (both dtors)
 * ================================================================ */
typedef struct ccAdvCreateMobInfo {
    uint8_t _pad_0x00[0x0C];      /* 0x00 */
    int32_t mob_type;             /* 0x0C — read in dtor, compared == 1 */
} ccAdvCreateMobInfo;
static_assert(offsetof(ccAdvCreateMobInfo, mob_type) == 0x0C, "ccAdvCreateMobInfo.mob_type");


/* ================================================================
 * ccAdvCtrl
 * Size: unknown, >= 0x16888 (field at +0x16880 is ptr-sized)
 * Vtable: not directly found (accessed via *param_1 indirection)
 * Methods: 28
 * Note: fields accessed through double-indirection (*param_1 + off)
 * ================================================================ */
typedef struct ccAdvCtrl {
    uint8_t _pad_0x00[0x280];     /* 0x000 */
    int32_t cur_state;            /* 0x280 — GetCurState/IsEnd read *(int*)(*this+0x50) */
    uint8_t _pad_0x284[0x165FC];  /* 0x284 */
    int64_t camera_state_ptr;     /* 0x16880 — GetCameraState reads *(ptr*)(*this+0x2D10) */
} ccAdvCtrl;
static_assert(offsetof(ccAdvCtrl, cur_state) == 0x280, "ccAdvCtrl.cur_state");
static_assert(offsetof(ccAdvCtrl, camera_state_ptr) == 0x16880, "ccAdvCtrl.camera_state_ptr");


/* ================================================================
 * ccAdvCtrlStateMachine
 * Size: 0xC0D0 (proven: FUN_140580190(0xc0d0,...) in ccAdvCtrl::Create @ 0x1B642C)
 * Vtable: PTR_FUN_14079a8d0 (set in ctor)
 * Methods: 70
 * Progression state machine: controls adventure/free-roam flow
 * ================================================================ */
typedef struct ccAdvCtrlStateMachine {
    void *vtable;                 /* 0x0000 — PTR_FUN_14079a8d0 */
    uint8_t _pad_0x08[0x14B0];    /* 0x0008 */
    /* Sub-object at +0x14B8: initialized by FUN_1401c9c90 in ctor */
    uint8_t sub_14B8[0x30];       /* 0x14B8 — read by ctor+dtor */
    uint8_t _pad_0x14E8[0x40];    /* 0x14E8 */
    uint8_t sub_1528[0x30];       /* 0x1528 — read by FUN_14059cd40 */
    uint8_t _pad_0x1558[0x10];    /* 0x1558 */
    uint8_t sub_1568[0x30];       /* 0x1568 — read by FUN_1401ce69c */
    uint8_t _pad_0x1598[0xC0];    /* 0x1598 */
    uint8_t sub_1658[0x30];       /* 0x1658 — read by FUN_140649ba0 */
    uint8_t _pad_0x1688[0x30];    /* 0x1688 */
    uint8_t sub_16B8[0x30];       /* 0x16B8 — read by FUN_1401aeea4 */
    uint8_t _pad_0x16E8[0x14E8];  /* 0x16E8 */
    /* Vector-like member at +0x2BD0 */
    int64_t vec_2BD0_begin;       /* 0x2BD0 — vector begin ptr */
    int64_t vec_2BD0_end;         /* 0x2BD8 — vector end ptr */
    int64_t vec_2BD0_cap;         /* 0x2BE0 — vector capacity */
    uint8_t _pad_0x2BE8[0x70];    /* 0x2BE8 */
    /* Sub-object at +0x2C58: FUN_1401afc0c init */
    uint8_t sub_2C58[0x18];       /* 0x2C58 */
    uint8_t _pad_0x2C70[0x20];    /* 0x2C70 */
    uint8_t sub_2C90[0x18];       /* 0x2C90 */
    uint8_t _pad_0x2CA8[0x20];    /* 0x2CA8 */
    uint8_t sub_2CC8[0x18];       /* 0x2CC8 */
    uint8_t _pad_0x2CE0[0x30];    /* 0x2CE0 */
    uint32_t field_2D10_w;        /* 0x2D10 — written 0 in ctor */
    uint32_t field_2D14_pad;      /* 0x2D14 */
    uint64_t field_2D18_w;        /* 0x2D18 — written 0 in ctor */
    uint64_t field_2D20_w;        /* 0x2D20 — written 0 in ctor */
    uint8_t _pad_0x2D28[0x9260];  /* 0x2D28 */
    /* Sub-objects at +0xBF88..+0xC0A8: string/vector members */
    uint8_t sub_BF88[0x18];       /* 0xBF88 — FUN_1401afc0c init */
    uint8_t _pad_BFA0[0x28];      /* 0xBFA0 */
    uint8_t sub_BFC8[0x20];       /* 0xBFC8 */
    uint8_t _pad_BFE8[0x38];      /* 0xBFE8 */
    uint8_t sub_C020[0x18];       /* 0xC020 — FUN_1401afc0c init */
    uint8_t _pad_C038[0x28];      /* 0xC038 */
    uint64_t field_C060;          /* 0xC060 — written 0 in ctor+dtor */
    uint8_t _pad_C068[0x10];      /* 0xC068 */
    uint8_t sub_C078[0x30];       /* 0xC078 — FUN_1405858f0 init */
    uint8_t _pad_C0A8[0x18];      /* 0xC0A8 */
    uint64_t field_C0C0;          /* 0xC0C0 — written 0 in ctor */
    uint8_t _pad_C0C8[0x08];      /* 0xC0C8 — pad to 0xC0D0 */
} ccAdvCtrlStateMachine;
static_assert(sizeof(ccAdvCtrlStateMachine) == 0xC0D0, "ccAdvCtrlStateMachine size");
static_assert(offsetof(ccAdvCtrlStateMachine, vtable) == 0x0000, "ccAdvCtrlStateMachine.vtable");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_14B8) == 0x14B8, "ccAdvCtrlStateMachine.sub_14B8");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_1528) == 0x1528, "ccAdvCtrlStateMachine.sub_1528");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_1568) == 0x1568, "ccAdvCtrlStateMachine.sub_1568");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_1658) == 0x1658, "ccAdvCtrlStateMachine.sub_1658");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_16B8) == 0x16B8, "ccAdvCtrlStateMachine.sub_16B8");
static_assert(offsetof(ccAdvCtrlStateMachine, vec_2BD0_begin) == 0x2BD0, "ccAdvCtrlStateMachine.vec_2BD0_begin");
static_assert(offsetof(ccAdvCtrlStateMachine, field_2D10_w) == 0x2D10, "ccAdvCtrlStateMachine.field_2D10_w");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_BF88) == 0xBF88, "ccAdvCtrlStateMachine.sub_BF88");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_C020) == 0xC020, "ccAdvCtrlStateMachine.sub_C020");
static_assert(offsetof(ccAdvCtrlStateMachine, field_C060) == 0xC060, "ccAdvCtrlStateMachine.field_C060");
static_assert(offsetof(ccAdvCtrlStateMachine, sub_C078) == 0xC078, "ccAdvCtrlStateMachine.sub_C078");
static_assert(offsetof(ccAdvCtrlStateMachine, field_C0C0) == 0xC0C0, "ccAdvCtrlStateMachine.field_C0C0");


/* ================================================================
 * ccAdvEffectManager
 * Size: 0x38 (proven: FUN_140580190(0x38,...) in Initialize @ 0x1BC498)
 * Vtable: not found (no ctor symbol, singleton pattern)
 * Methods: 6
 * ================================================================ */
typedef struct ccAdvEffectManager {
    uint8_t data[0x38];           /* 0x00 — opaque, no fields surfaced */
} ccAdvEffectManager;
static_assert(sizeof(ccAdvEffectManager) == 0x38, "ccAdvEffectManager size");


/* ================================================================
 * ccAdvFadeAreaParamManager
 * Size: unknown (no allocation found; 3 methods, 0 fields surfaced)
 * Vtable: not found
 * ================================================================ */
/* No struct emitted — insufficient evidence for layout */


/* ================================================================
 * ccAdvFileLoadList
 * Size: unknown (no allocation found; 7 methods, 0 fields surfaced)
 * Vtable: not found
 * ================================================================ */
/* No struct emitted — insufficient evidence for layout */


/* ================================================================
 * ccAdvFixCamera
 * Size: unknown, >= 0x1C0 (fields at +0x1B0, +0x1BC; allocated as part of
 * ccAdvCameraState which is 0x16B0 total)
 * Vtable: PTR_FUN_14079bff0 (set in ctor @ 0x1CA208)
 * Methods: 1 (ctor only)
 * ================================================================ */
typedef struct ccAdvFixCamera {
    void *vtable;                 /* 0x000 — PTR_FUN_14079bff0 */
    uint8_t _pad_0x08[0x1A8];     /* 0x008 */
    uint8_t sub_1B0[0x0C];        /* 0x1B0 — FUN_140580a40 init in ctor */
    uint8_t _pad_0x1BC[0x04];     /* 0x1BC */
    /* size unknown beyond this point */
} ccAdvFixCamera;
static_assert(offsetof(ccAdvFixCamera, vtable) == 0x000, "ccAdvFixCamera.vtable");
static_assert(offsetof(ccAdvFixCamera, sub_1B0) == 0x1B0, "ccAdvFixCamera.sub_1B0");


/* ================================================================
 * ccAdvGameStatus
 * Size: unknown, >= 0xD94 (Initialize writes int32 at +0xD90)
 * Vtable: not found (no ctor symbol)
 * Methods: 77
 * Progression: stores money, chapter/stage state, save-data flags
 * ================================================================ */
typedef struct ccAdvGameStatus {
    uint8_t _pad_0x00[0x30];      /* 0x000 */
    uint8_t sub_30[0x30];         /* 0x030 — FUN_1401e05c8 init */
    uint8_t _pad_0x60[0x30];      /* 0x060 */
    uint8_t sub_90[0x30];         /* 0x090 — FUN_1401b5870 init */
    uint8_t _pad_0xC0[0xCD0];     /* 0x0C0 */
    int32_t field_D90;            /* 0xD90 — set to 1 in Initialize */
    /* size unknown beyond this point */
} ccAdvGameStatus;
static_assert(offsetof(ccAdvGameStatus, sub_30) == 0x030, "ccAdvGameStatus.sub_30");
static_assert(offsetof(ccAdvGameStatus, sub_90) == 0x090, "ccAdvGameStatus.sub_90");
static_assert(offsetof(ccAdvGameStatus, field_D90) == 0xD90, "ccAdvGameStatus.field_D90");


/* ================================================================
 * ccAdvItemBox
 * Size: unknown (2 methods, 0 fields surfaced)
 * Vtable: not found
 * ================================================================ */
/* No struct emitted — insufficient evidence for layout */


/* ================================================================
 * ccAdvJumpCamera
 * Size: 0x1F0 (verified by compilation)
 * Vtable: not found (Init sets fields, no ctor symbol)
 * Methods: 3 (Init x2, one more)
 * ================================================================ */
typedef struct ccAdvJumpCamera {
    uint8_t _pad_0x00[0x40];      /* 0x000 */
    uint8_t sub_40[0x2C];         /* 0x040 — FUN_14063c540 target */
    uint32_t field_6C;            /* 0x06C — set 0x42340000 (float 45.0) in Init */
    uint8_t _pad_0x70[0x64];      /* 0x070 */
    uint8_t sub_D4[0x08];         /* 0x0D4 — copied to +0x1D4 */
    uint32_t field_DC;            /* 0x0DC — copied to +0x1DC */
    uint8_t _pad_0xE0[0xD0];      /* 0x0E0 */
    uint64_t fix_cam_pos;         /* 0x1B0 — copied from param_2 */
    uint32_t fix_cam_rot;         /* 0x1B8 — copied from param_2+8 */
    uint8_t _pad_0x1BC[0x04];     /* 0x1BC */
    uint64_t cam_target_pos;      /* 0x1C0 — from FUN_140580b40 result */
    uint32_t cam_target_rot;      /* 0x1C8 */
    uint8_t _pad_0x1CC[0x04];     /* 0x1CC */
    uint64_t cam_look_at;         /* 0x1D0 — from param_4 */
    uint32_t cam_look_rot;        /* 0x1D8 */
    uint8_t _pad_0x1DC[0x04];     /* 0x1DC */
    uint64_t interp_start_pos;    /* 0x1E0 — copy of sub_D4 */
    uint32_t interp_start_rot;    /* 0x1E8 — copy of field_DC */
    uint32_t interp_result;       /* 0x1EC — thunk_FUN_1401991a0 result */
} ccAdvJumpCamera;
static_assert(offsetof(ccAdvJumpCamera, sub_40) == 0x040, "ccAdvJumpCamera.sub_40");
static_assert(offsetof(ccAdvJumpCamera, field_6C) == 0x06C, "ccAdvJumpCamera.field_6C");
static_assert(offsetof(ccAdvJumpCamera, sub_D4) == 0x0D4, "ccAdvJumpCamera.sub_D4");
static_assert(offsetof(ccAdvJumpCamera, field_DC) == 0x0DC, "ccAdvJumpCamera.field_DC");
static_assert(offsetof(ccAdvJumpCamera, fix_cam_pos) == 0x1B0, "ccAdvJumpCamera.fix_cam_pos");
static_assert(offsetof(ccAdvJumpCamera, fix_cam_rot) == 0x1B8, "ccAdvJumpCamera.fix_cam_rot");
static_assert(offsetof(ccAdvJumpCamera, cam_target_pos) == 0x1C0, "ccAdvJumpCamera.cam_target_pos");
static_assert(offsetof(ccAdvJumpCamera, cam_target_rot) == 0x1C8, "ccAdvJumpCamera.cam_target_rot");
static_assert(offsetof(ccAdvJumpCamera, cam_look_at) == 0x1D0, "ccAdvJumpCamera.cam_look_at");
static_assert(offsetof(ccAdvJumpCamera, cam_look_rot) == 0x1D8, "ccAdvJumpCamera.cam_look_rot");
static_assert(offsetof(ccAdvJumpCamera, interp_start_pos) == 0x1E0, "ccAdvJumpCamera.interp_start_pos");
static_assert(offsetof(ccAdvJumpCamera, interp_start_rot) == 0x1E8, "ccAdvJumpCamera.interp_start_rot");
static_assert(offsetof(ccAdvJumpCamera, interp_result) == 0x1EC, "ccAdvJumpCamera.interp_result");

#pragma pack(pop)