/*
 * st2a07.h — Storm 2 (NSUNS2.exe, build s2) adventure/story progression structs
 *
 * All results are INFERRED from static analysis of decompiled pseudocode.
 * Offsets are PC x64 only (image base 0x140000000).
 * Own-game names only (Storm 2 / ns2:: namespace).
 *
 * Classes with <3 methods in this build are listed but not reconstructed:
 * ccAdvAnmMobDraw (1), ccAdvAreaGraph (1), ccAdvAreaInfoManager (1),
 * ccAdvBattleParamManager (1), ccAdvBirdCaptureGauge (2)
 */
#ifndef ST2A07_H
#define ST2A07_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types */
typedef struct Nucc_Vector3 {
    float x;
    float y;
    float z;
} Nucc_Vector3;
static_assert(sizeof(Nucc_Vector3) == 12, "Nucc_Vector3 size");

/*
 * ccAdvBattleSaveData — battle result / save data embedded in ccTreeCoord
 *
 * Size proven >= 0x5408 by ctor (RVA 0x365598): writes +0x5400 and +0x5404.
 * Embedded at byte offset 0x20 inside ccTreeCoord (ctor RVA 0x3656D4).
 * Vtable: not directly set in own ctor; inherits from embedding context.
 */
typedef struct __attribute__((packed)) ccAdvBattleSaveData {
    uint8_t _pad_0x00[0x08];        /* 0x00: unknown (base/vtable area) */
    uint32_t bonus[3];              /* 0x08: GetBonus/SetBonus array[3] */
    uint8_t _pad_0x14[0x53EC];      /* 0x14: gap to proven high fields */
    int32_t field_0x5400;           /* 0x5400: init -1 in ctor */
    int32_t field_0x5404;           /* 0x5404: init 0 in ctor */
} ccAdvBattleSaveData;
static_assert(offsetof(ccAdvBattleSaveData, bonus) == 0x08, "ccAdvBattleSaveData.bonus");
static_assert(offsetof(ccAdvBattleSaveData, field_0x5400) == 0x5400, "ccAdvBattleSaveData.field_0x5400");
static_assert(offsetof(ccAdvBattleSaveData, field_0x5404) == 0x5404, "ccAdvBattleSaveData.field_0x5404");
/* Size >= 0x5408 proven by ctor write at +0x5404 (uint32) */

/*
 * ccAdvBirdCaptureTarget — individual bird capture target entity
 *
 * Size proven >= 0x2A98 by CreateCollision (RVA 0x1A7698): accesses +0x2A90.
 * Vtable: not found in own methods (likely set by factory).
 */
typedef struct __attribute__((packed)) ccAdvBirdCaptureTarget {
    uint8_t _base[0xE8];            /* 0x00: base class / vtable area */
    int32_t anim_id;                /* 0xE8: animation index (<6), ChangeAnimation */
    int32_t state_timer;            /* 0xEC: timer, StateCapture/StateEscape */
    int32_t field_0xF0;             /* 0xF0: timer used in StateCapture/StateEscape */
    int32_t field_0xF4;             /* 0xF4: padding or sub-field */
    int32_t field_0xF8;             /* 0xF8: state transition flag */
    int32_t current_state;          /* 0xFC: padding or state id */
    uint8_t _pad_0x100[0x1450];     /* 0x100: gap to 0x1550 */
    int32_t bird_type;              /* 0x1550: type index (<10), ChangeAnimation */
    Nucc_Vector3 position;          /* 0x1554: world position, Draw/HearingTest/Regard */
    Nucc_Vector3 direction;         /* 0x1560: facing direction, Regard/StateCapture */
    float visual_range;             /* 0x156C: sight distance, VisualTest */
    float visual_angle;             /* 0x1570: FOV angle, VisualTest/EscapeTest */
    float hearing_range;            /* 0x1574: audio detection range, HearingTest */
    uint8_t _pad_0x1578[0x08];      /* 0x1578: gap to 0x1580 */
    void *anm_base;                 /* 0x1580: nuccAnmBase*, Draw/ChangeAnimation */
    void *effect_ptr;               /* 0x1588: effect object*, Draw/EnterCapture */
    uint8_t _pad_0x1590[0x50];      /* 0x1590: sub-object region to 0x15E0 */
    int32_t field_0x15E0;           /* 0x15E0: state check (==2||3), StateCapture */
    uint8_t _pad_0x15E4[0x14A4];    /* 0x15E4: gap to 0x2A88 */
    int32_t caution_value;          /* 0x2A88: set to 0x5A in EnterCaution */
    int32_t collision_flag;         /* 0x2A8C: -1 = no collision, CreateCollision */
    void *collision_component;      /* 0x2A90: collision component ptr, CreateCollision */
    uint8_t _pad_0x2A98[0x08];      /* 0x2A98: trailing pad */
} ccAdvBirdCaptureTarget;
static_assert(offsetof(ccAdvBirdCaptureTarget, anim_id) == 0xE8, "ccAdvBirdCaptureTarget.anim_id");
static_assert(offsetof(ccAdvBirdCaptureTarget, state_timer) == 0xEC, "ccAdvBirdCaptureTarget.state_timer");
static_assert(offsetof(ccAdvBirdCaptureTarget, field_0xF0) == 0xF0, "ccAdvBirdCaptureTarget.field_0xF0");
static_assert(offsetof(ccAdvBirdCaptureTarget, field_0xF8) == 0xF8, "ccAdvBirdCaptureTarget.field_0xF8");
static_assert(offsetof(ccAdvBirdCaptureTarget, bird_type) == 0x1550, "ccAdvBirdCaptureTarget.bird_type");
static_assert(offsetof(ccAdvBirdCaptureTarget, position) == 0x1554, "ccAdvBirdCaptureTarget.position");
static_assert(offsetof(ccAdvBirdCaptureTarget, direction) == 0x1560, "ccAdvBirdCaptureTarget.direction");
static_assert(offsetof(ccAdvBirdCaptureTarget, visual_range) == 0x156C, "ccAdvBirdCaptureTarget.visual_range");
static_assert(offsetof(ccAdvBirdCaptureTarget, visual_angle) == 0x1570, "ccAdvBirdCaptureTarget.visual_angle");
static_assert(offsetof(ccAdvBirdCaptureTarget, hearing_range) == 0x1574, "ccAdvBirdCaptureTarget.hearing_range");
static_assert(offsetof(ccAdvBirdCaptureTarget, anm_base) == 0x1580, "ccAdvBirdCaptureTarget.anm_base");
static_assert(offsetof(ccAdvBirdCaptureTarget, effect_ptr) == 0x1588, "ccAdvBirdCaptureTarget.effect_ptr");
static_assert(offsetof(ccAdvBirdCaptureTarget, field_0x15E0) == 0x15E0, "ccAdvBirdCaptureTarget.field_0x15E0");
static_assert(offsetof(ccAdvBirdCaptureTarget, caution_value) == 0x2A88, "ccAdvBirdCaptureTarget.caution_value");
static_assert(offsetof(ccAdvBirdCaptureTarget, collision_flag) == 0x2A8C, "ccAdvBirdCaptureTarget.collision_flag");
static_assert(offsetof(ccAdvBirdCaptureTarget, collision_component) == 0x2A90, "ccAdvBirdCaptureTarget.collision_component");
/* Size >= 0x2A98 proven by collision_component access at +0x2A90 (ptr, 8 bytes) */

/*
 * ccAdvBirdCapture — bird capture mini-game controller
 *
 * Size proven >= 0x1508 by Initialize (RVA 0x1A8434): accesses +0x1500.
 * Contains embedded ccFileLoadListForUi at +0x14C0 (Load/Unload).
 * Vtable: not found in own methods.
 *
 * Note: field_0x14F0 and field_0x14F8 are INSIDE file_load_list region
 * (0x14C0..0x14FF). They are sub-object pointers within the load list.
 * file_load_list is declared as opaque bytes; the ptr fields overlay it.
 */
typedef struct __attribute__((packed)) ccAdvBirdCapture {
    uint8_t _base[0x50];            /* 0x00: base class area */
    int32_t return_state;           /* 0x50: SetReturnState */
    int32_t state_id;               /* 0x54: current state, Clear/StateFailureMessage */
    int32_t state_timer;            /* 0x58: timer, StateFailureMessage/StateSuccessMessage */
    int32_t state_flag;             /* 0x5C: flag, Clear/Init */
    uint8_t _pad_0x60[0x1460];      /* 0x60: gap to 0x14C0 */
    uint8_t file_load_list[0x30];   /* 0x14C0: ccFileLoadListForUi sub-object (to 0x14EF) */
    void *field_0x14F0;             /* 0x14F0: sub-object ptr, Clear/Initialize */
    void *field_0x14F8;             /* 0x14F8: sub-object ptr, Clear/Initialize */
    int32_t field_0x1500;           /* 0x1500: Initialize/SetReturnState */
    uint8_t _pad_0x1504[0x04];      /* 0x1504: trailing pad */
} ccAdvBirdCapture;
static_assert(offsetof(ccAdvBirdCapture, return_state) == 0x50, "ccAdvBirdCapture.return_state");
static_assert(offsetof(ccAdvBirdCapture, state_id) == 0x54, "ccAdvBirdCapture.state_id");
static_assert(offsetof(ccAdvBirdCapture, state_timer) == 0x58, "ccAdvBirdCapture.state_timer");
static_assert(offsetof(ccAdvBirdCapture, state_flag) == 0x5C, "ccAdvBirdCapture.state_flag");
static_assert(offsetof(ccAdvBirdCapture, file_load_list) == 0x14C0, "ccAdvBirdCapture.file_load_list");
static_assert(offsetof(ccAdvBirdCapture, field_0x14F0) == 0x14F0, "ccAdvBirdCapture.field_0x14F0");
static_assert(offsetof(ccAdvBirdCapture, field_0x14F8) == 0x14F8, "ccAdvBirdCapture.field_0x14F8");
static_assert(offsetof(ccAdvBirdCapture, field_0x1500) == 0x1500, "ccAdvBirdCapture.field_0x1500");
/* Size >= 0x1508 proven by field_0x1500 access (int32 at +0x1500) */

/*
 * ccAdv3dCameraCtrl — adventure mode 3D camera controller (state machine)
 *
 * Inherits ccTaskBase (ctor calls ccTaskBase::ccTaskBase with tag 6).
 * Size proven >= 0x1610 by StateDungeon (RVA 0x1A3A98): accesses +0x1608.
 * Embeds ccAdvCalc3dNormalCameraPos at byte offset 0x14B8 (size 0x80).
 * Embeds ccAdvCalc3dMapCameraPos at byte offset 0x1538 (size 0x40).
 * Vtable: PTR_FUN_140798db0 (set in ctor).
 */
typedef struct __attribute__((packed)) ccAdv3dCameraCtrl {
    void *vtable;                   /* 0x00: PTR_FUN_140798db0 */
    uint8_t _ccTaskBase[0x4C];      /* 0x08: ccTaskBase base (to 0x54) */
    int32_t state_id;               /* 0x54: current state, Init/StateNormal */
    uint8_t _pad_0x58[0x08];        /* 0x58: gap to 0x60 */
    int32_t state_flag;             /* 0x60: flag, Init/StateNormal */
    uint8_t _pad_0x64[0x1454];      /* 0x64: gap to 0x14B8 */
    uint8_t calc_normal_cam[0x80];  /* 0x14B8: ccAdvCalc3dNormalCameraPos embedded */
    uint8_t calc_map_cam[0x40];     /* 0x1538: ccAdvCalc3dMapCameraPos embedded */
    uint8_t _pad_0x1578[0x50];      /* 0x1578: gap to 0x15C8 */
    int32_t field_0x15C8;           /* 0x15C8: init 0, Init */
    int32_t field_0x15CC;           /* 0x15CC: init 0x41700000 (float 15.0), Init/ctor */
    void *chara_param;              /* 0x15D0: ccAdvCharaParam*, Init/StateNormal/StateDungeon */
    Nucc_Vector3 cam_end_pos;       /* 0x15D8: end camera position, Init/StateNormal */
    Nucc_Vector3 cam_start_pos;     /* 0x15E4: start camera position, Init/StateNormal */
    Nucc_Vector3 cam_view_dir;      /* 0x15F0: view direction (init 0,0,1), Init */
    float field_0x15FC;             /* 0x15FC: init 0x42340000 (float 45.0), ctor */
    Nucc_Vector3 field_0x1600;      /* 0x1600: interpolated pos, StateDungeon */
    uint8_t _pad_0x160C[0x04];      /* 0x160C: trailing pad */
} ccAdv3dCameraCtrl;
static_assert(offsetof(ccAdv3dCameraCtrl, vtable) == 0x00, "ccAdv3dCameraCtrl.vtable");
static_assert(offsetof(ccAdv3dCameraCtrl, state_id) == 0x54, "ccAdv3dCameraCtrl.state_id");
static_assert(offsetof(ccAdv3dCameraCtrl, state_flag) == 0x60, "ccAdv3dCameraCtrl.state_flag");
static_assert(offsetof(ccAdv3dCameraCtrl, calc_normal_cam) == 0x14B8, "ccAdv3dCameraCtrl.calc_normal_cam");
static_assert(offsetof(ccAdv3dCameraCtrl, calc_map_cam) == 0x1538, "ccAdv3dCameraCtrl.calc_map_cam");
static_assert(offsetof(ccAdv3dCameraCtrl, field_0x15C8) == 0x15C8, "ccAdv3dCameraCtrl.field_0x15C8");
static_assert(offsetof(ccAdv3dCameraCtrl, field_0x15CC) == 0x15CC, "ccAdv3dCameraCtrl.field_0x15CC");
static_assert(offsetof(ccAdv3dCameraCtrl, chara_param) == 0x15D0, "ccAdv3dCameraCtrl.chara_param");
static_assert(offsetof(ccAdv3dCameraCtrl, cam_end_pos) == 0x15D8, "ccAdv3dCameraCtrl.cam_end_pos");
static_assert(offsetof(ccAdv3dCameraCtrl, cam_start_pos) == 0x15E4, "ccAdv3dCameraCtrl.cam_start_pos");
static_assert(offsetof(ccAdv3dCameraCtrl, cam_view_dir) == 0x15F0, "ccAdv3dCameraCtrl.cam_view_dir");
static_assert(offsetof(ccAdv3dCameraCtrl, field_0x15FC) == 0x15FC, "ccAdv3dCameraCtrl.field_0x15FC");
static_assert(offsetof(ccAdv3dCameraCtrl, field_0x1600) == 0x1600, "ccAdv3dCameraCtrl.field_0x1600");
/* Size >= 0x1610 proven by StateDungeon access at +0x1608 (within field_0x1600 Vector3) */

/*
 * ccAdvCalcCameraPos — abstract camera position calculator base
 *
 * Ctor (RVA 0x3738F8): two BlockAllocator sub-objects at qword offsets 2 and 4.
 * Size unknown, >= 0x18 (3 qwords minimum from ctor).
 * Vtable: set by FUN_1403784dc.
 */
typedef struct __attribute__((packed)) ccAdvCalcCameraPos {
    void *vtable;                   /* 0x00: set by FUN_1403784dc */
    void *block_alloc_1;            /* 0x08: BlockAllocator sub-object */
    void *block_alloc_2;            /* 0x10: BlockAllocator sub-object */
} ccAdvCalcCameraPos;
static_assert(offsetof(ccAdvCalcCameraPos, vtable) == 0x00, "ccAdvCalcCameraPos.vtable");
static_assert(offsetof(ccAdvCalcCameraPos, block_alloc_1) == 0x08, "ccAdvCalcCameraPos.block_alloc_1");
static_assert(offsetof(ccAdvCalcCameraPos, block_alloc_2) == 0x10, "ccAdvCalcCameraPos.block_alloc_2");
/* Size >= 0x18 proven by ctor (3 qwords initialized) */

/*
 * ccAdvCalc3dNormalCameraPos — normal-mode camera interpolation
 *
 * Embedded in ccAdv3dCameraCtrl at byte offset 0x14B8.
 * 7 methods in build. Size inferred from embedding: 0x80 bytes.
 */
typedef struct __attribute__((packed)) ccAdvCalc3dNormalCameraPos {
    uint8_t data[0x80];             /* opaque: accessed via parent ccAdv3dCameraCtrl */
} ccAdvCalc3dNormalCameraPos;
static_assert(sizeof(ccAdvCalc3dNormalCameraPos) == 0x80, "ccAdvCalc3dNormalCameraPos size from embedding");

/*
 * ccAdvCalc3dMapCameraPos — map-mode camera position calculator
 *
 * Embedded in ccAdv3dCameraCtrl at byte offset 0x1538.
 * 7 methods in build. Size inferred from embedding: 0x40 bytes.
 */
typedef struct __attribute__((packed)) ccAdvCalc3dMapCameraPos {
    uint8_t data[0x40];             /* opaque: accessed via parent ccAdv3dCameraCtrl */
} ccAdvCalc3dMapCameraPos;
static_assert(sizeof(ccAdvCalc3dMapCameraPos) == 0x40, "ccAdvCalc3dMapCameraPos size from embedding");

/*
 * ccAdv3DMapCamera — 3D map camera (minimal, 3 methods)
 *
 * Ctor (RVA 0x1A4B5C), ReStart (0x1A4B70), Init (0x1A4B7C).
 * Size unknown; too few methods for field extraction.
 */
/* Not reconstructed: insufficient field evidence */

/*
 * ccAdvAreaInfo — area information (9 methods)
 *
 * Surface returned 0 fields (indirect access pattern).
 * Size unknown; methods exist but field offsets not extractable from decompile.
 */
/* Not reconstructed: state_surface returned 0 fields */

/*
 * ccAdvBirdCaptureGauge — bird capture gauge UI (2 methods)
 *
 * PostProcess (0x1A89C0), StateNut (0x1A9868).
 * Too few methods (<3 threshold); skipped per task rules.
 */
/* Skipped: <3 methods */

/*
 * Classes with only 1 method (skipped per task rules):
 * ccAdvAnmMobDraw::Create (0x1A23B8)
 * ccAdvAreaGraph::Initialize (0x1E2572)
 * ccAdvAreaInfoManager::Create (0x1A6300)
 * ccAdvBattleParamManager::Create (0x1A69D8)
 */

#endif /* ST2A07_H */