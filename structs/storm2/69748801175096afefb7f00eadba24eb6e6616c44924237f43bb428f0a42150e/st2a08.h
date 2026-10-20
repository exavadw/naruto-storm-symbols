/*
 * st2a08.h -- Storm 2 (NSUNS2.exe, build s2) adventure-mode class structs
 * Group: st2a08 (ccAdv* classes with >= 3 methods)
 * All offsets are PC x64 RVA from image base 0x140000000.
 * All fields are INFERRED from static analysis; none are CONFIRMED by runtime trace.
 * Sizes are unproven unless noted; no sizeof assertions on incomplete types.
 * Generated 2026-10-19. Do not commit to git.
 */
#ifndef ST2A08_H
#define ST2A08_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* Forward declarations for pointer-only references                   */
/* ------------------------------------------------------------------ */
typedef struct ccAdvCharaParam ccAdvCharaParam;
typedef struct ccAdvLivetalkActor ccAdvLivetalkActor;

/* ------------------------------------------------------------------ */
/* Opaque / embedded helper types (sizes unproven -> byte arrays)     */
/* ------------------------------------------------------------------ */

/* Nucc::Vector3 -- 3 floats, 12 bytes, no padding in packed context */
typedef struct __attribute__((packed)) {
    float x;
    float y;
    float z;
} Nucc_Vector3;

/* DName -- inline name buffer, 16 bytes observed at +0x1548 */
typedef struct __attribute__((packed)) {
    uint8_t data[16];
} DName;

/* mmMutex -- opaque mutex wrapper, 8 bytes (pointer-sized handle) */
typedef struct __attribute__((packed)) {
    uint8_t data[8];
} mmMutex;

/* Nucc::Memory::BlockAllocator -- opaque, 24 bytes from Clear decompile */
typedef struct __attribute__((packed)) {
    uint8_t data[24];
} BlockAllocator;

/* ccWindowCollisionHandler -- embedded, 16 bytes from dtor offset math */
typedef struct __attribute__((packed)) {
    uint8_t data[16];
} ccWindowCollisionHandler;

/* ================================================================== */
/* ccAdvCharaState (42 methods)                                       */
/* Inherits ccTaskBase. Vtable PTR_FUN_14079a1a8 (own),               */
/*         base vtable PTR_FUN_1407dd918 (ccTaskBase).                */
/* Size unknown, >= 0x15D8.                                           */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCharaState {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x004F[0x48];
    /* 0x0050 */ int32_t task_state;
    /* 0x0054 */ int32_t action_type;
    /* 0x0058 */ uint8_t _pad_0x0058_0x005F[0x08];
    /* 0x0060 */ int32_t movement_flag;
    /* 0x0064 */ uint8_t _pad_0x0064_0x14B7[0x1454];
    /* 0x14B8 */ float position_x;
    /* 0x14BC */ float position_y;
    /* 0x14C0 */ float angle_y;
    /* 0x14C4 */ uint8_t _pad_0x14C4_0x14C7[0x04];
    /* 0x14C8 */ ccAdvCharaParam *chara_param;
    /* 0x14D0 */ void *skill_dir_1;
    /* 0x14D8 */ void *skill_dir_2;
    /* 0x14E0 */ void *skill_dir_3;
    /* 0x14E8 */ float velocity_x;
    /* 0x14EC */ float velocity_y;
    /* 0x14F0 */ float rotation;
    /* 0x14F4 */ uint8_t _pad_0x14F4_0x14FF[0x0C];
    /* 0x1500 */ int32_t collision_enable;
    /* 0x1504 */ uint8_t _pad_0x1504_0x1543[0x40];
    /* 0x1544 */ int32_t base_angle;
    /* 0x1548 */ DName name_buffer;
    /* 0x1558 */ mmMutex vector_alloc_1_mutex;
    /* 0x1560 */ void *vector_end_1;
    /* 0x1568 */ uint8_t _pad_0x1568_0x156F[0x08];
    /* 0x1570 */ BlockAllocator vector_data_1;
    /* 0x1588 */ mmMutex vector_alloc_2_mutex;
    /* 0x1590 */ void *vector_end_2;
    /* 0x1598 */ uint8_t _pad_0x1598_0x159F[0x08];
    /* 0x15A0 */ BlockAllocator vector_data_2;
    /* 0x15B8 */ int32_t state_flag;
    /* 0x15BC */ uint8_t _pad_0x15BC_0x15BF[0x04];
    /* 0x15C0 */ ccAdvLivetalkActor *ui_object;
    /* 0x15C8 */ ccWindowCollisionHandler window_collision_handler;
    /* 0x15D8 -- end of known fields; total size unknown, >= 0x15D8 */
} ccAdvCharaState;

static_assert(offsetof(ccAdvCharaState, vtable) == 0x0000, "ccAdvCharaState.vtable");
static_assert(offsetof(ccAdvCharaState, task_state) == 0x0050, "ccAdvCharaState.task_state");
static_assert(offsetof(ccAdvCharaState, action_type) == 0x0054, "ccAdvCharaState.action_type");
static_assert(offsetof(ccAdvCharaState, movement_flag) == 0x0060, "ccAdvCharaState.movement_flag");
static_assert(offsetof(ccAdvCharaState, position_x) == 0x14B8, "ccAdvCharaState.position_x");
static_assert(offsetof(ccAdvCharaState, position_y) == 0x14BC, "ccAdvCharaState.position_y");
static_assert(offsetof(ccAdvCharaState, angle_y) == 0x14C0, "ccAdvCharaState.angle_y");
static_assert(offsetof(ccAdvCharaState, chara_param) == 0x14C8, "ccAdvCharaState.chara_param");
static_assert(offsetof(ccAdvCharaState, skill_dir_1) == 0x14D0, "ccAdvCharaState.skill_dir_1");
static_assert(offsetof(ccAdvCharaState, skill_dir_2) == 0x14D8, "ccAdvCharaState.skill_dir_2");
static_assert(offsetof(ccAdvCharaState, skill_dir_3) == 0x14E0, "ccAdvCharaState.skill_dir_3");
static_assert(offsetof(ccAdvCharaState, velocity_x) == 0x14E8, "ccAdvCharaState.velocity_x");
static_assert(offsetof(ccAdvCharaState, velocity_y) == 0x14EC, "ccAdvCharaState.velocity_y");
static_assert(offsetof(ccAdvCharaState, rotation) == 0x14F0, "ccAdvCharaState.rotation");
static_assert(offsetof(ccAdvCharaState, collision_enable) == 0x1500, "ccAdvCharaState.collision_enable");
static_assert(offsetof(ccAdvCharaState, base_angle) == 0x1544, "ccAdvCharaState.base_angle");
static_assert(offsetof(ccAdvCharaState, name_buffer) == 0x1548, "ccAdvCharaState.name_buffer");
static_assert(offsetof(ccAdvCharaState, vector_alloc_1_mutex) == 0x1558, "ccAdvCharaState.vector_alloc_1_mutex");
static_assert(offsetof(ccAdvCharaState, vector_end_1) == 0x1560, "ccAdvCharaState.vector_end_1");
static_assert(offsetof(ccAdvCharaState, vector_data_1) == 0x1570, "ccAdvCharaState.vector_data_1");
static_assert(offsetof(ccAdvCharaState, vector_alloc_2_mutex) == 0x1588, "ccAdvCharaState.vector_alloc_2_mutex");
static_assert(offsetof(ccAdvCharaState, vector_end_2) == 0x1590, "ccAdvCharaState.vector_end_2");
static_assert(offsetof(ccAdvCharaState, vector_data_2) == 0x15A0, "ccAdvCharaState.vector_data_2");
static_assert(offsetof(ccAdvCharaState, state_flag) == 0x15B8, "ccAdvCharaState.state_flag");
static_assert(offsetof(ccAdvCharaState, ui_object) == 0x15C0, "ccAdvCharaState.ui_object");
static_assert(offsetof(ccAdvCharaState, window_collision_handler) == 0x15C8, "ccAdvCharaState.window_collision_handler");

/* ================================================================== */
/* ccAdvCameraState (23 methods)                                      */
/* Has ccAdvStageParam embedded at +0x15F0 (80 bytes).                */
/* Size unknown, >= 0x1734.                                           */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCameraState {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x012F[0x128];
    /* 0x0130 */ int32_t camera_mode;           /* ctor sets 0xFFFFFFFF */
    /* 0x0134 */ int32_t camera_submode;        /* ctor sets 0 */
    /* 0x0138 */ int32_t camera_flag_1;         /* ctor sets 0 */
    /* 0x013C */ int32_t camera_flag_2;         /* ctor sets 0 */
    /* 0x0140 */ int32_t camera_flag_3;         /* ctor sets 0 */
    /* 0x0144 */ float camera_fov;              /* ctor sets 0x41F00000 = 30.0f */
    /* 0x0148 */ float camera_near_clip;        /* ctor sets 0x3F800000 = 1.0f */
    /* 0x014C */ uint8_t _pad_0x014C_0x014F[0x04];
    /* 0x0150 */ uint8_t _embedded_nucc_camera[0x14A0]; /* nuccCamera or similar at +0x150, FUN_140276d30 init */
    /* 0x15F0 */ uint8_t stage_param[80];       /* ccAdvStageParam embedded, FUN_1401df3cc */
    /* 0x1640 */ void *camera_ptr_1;            /* ctor sets 0 */
    /* 0x1648 */ void *camera_ptr_2;            /* ctor sets 0 */
    /* 0x1650 */ void *camera_ptr_3;            /* ctor sets 0 */
    /* 0x1658 */ uint8_t _pad_0x1658_0x1677[0x20]; /* FUN_1402ef670 init region */
    /* 0x1678 */ int32_t camera_flag_4;         /* ctor sets 0 */
    /* 0x167C */ int32_t camera_flag_5;         /* ctor sets 2 */
    /* 0x1680 */ void *camera_ptr_4;            /* ctor sets 0 */
    /* 0x1688 */ void *camera_ptr_5;            /* ctor sets 0 */
    /* 0x1690 */ void *camera_ptr_6;            /* ctor sets 0 */
    /* 0x1698 */ uint8_t _pad_0x1698_0x16CF[0x38];
    /* 0x16D0 */ uint8_t _pad_0x16D0_0x16D7[0x08]; /* plVar1 = param_1 + 0x2da read */
    /* 0x16D8 */ void *camera_ptr_7;            /* ctor2 sets 0 */
    /* 0x16E0 */ void *camera_rw_ptr_1;         /* ctor2 rw, sets 0 */
    /* 0x16E8 */ uint8_t _pad_0x16E8_0x16EF[0x08]; /* FUN_1405858f0 init */
    /* 0x16F0 */ uint8_t _pad_0x16F0_0x16FF[0x10];
    /* 0x1700 */ uint8_t _pad_0x1700_0x1707[0x08]; /* plVar2 = param_1 + 0x2e0 read */
    /* 0x1708 */ void *camera_rw_ptr_2;         /* ctor2 sets 0 */
    /* 0x1710 */ void *camera_rw_ptr_3;         /* ctor2 rw, sets 0 */
    /* 0x1718 */ uint8_t _pad_0x1718_0x172F[0x18]; /* FUN_1405858f0 init */
    /* 0x1730 */ int32_t camera_final_flag;     /* ctor2 sets 0 */
    /* 0x1734 -- end of known fields; size unknown, >= 0x1734 */
} ccAdvCameraState;

static_assert(offsetof(ccAdvCameraState, vtable) == 0x0000, "ccAdvCameraState.vtable");
static_assert(offsetof(ccAdvCameraState, camera_mode) == 0x0130, "ccAdvCameraState.camera_mode");
static_assert(offsetof(ccAdvCameraState, camera_submode) == 0x0134, "ccAdvCameraState.camera_submode");
static_assert(offsetof(ccAdvCameraState, camera_flag_1) == 0x0138, "ccAdvCameraState.camera_flag_1");
static_assert(offsetof(ccAdvCameraState, camera_flag_2) == 0x013C, "ccAdvCameraState.camera_flag_2");
static_assert(offsetof(ccAdvCameraState, camera_flag_3) == 0x0140, "ccAdvCameraState.camera_flag_3");
static_assert(offsetof(ccAdvCameraState, camera_fov) == 0x0144, "ccAdvCameraState.camera_fov");
static_assert(offsetof(ccAdvCameraState, camera_near_clip) == 0x0148, "ccAdvCameraState.camera_near_clip");
static_assert(offsetof(ccAdvCameraState, stage_param) == 0x15F0, "ccAdvCameraState.stage_param");
static_assert(offsetof(ccAdvCameraState, camera_ptr_1) == 0x1640, "ccAdvCameraState.camera_ptr_1");
static_assert(offsetof(ccAdvCameraState, camera_ptr_2) == 0x1648, "ccAdvCameraState.camera_ptr_2");
static_assert(offsetof(ccAdvCameraState, camera_ptr_3) == 0x1650, "ccAdvCameraState.camera_ptr_3");
static_assert(offsetof(ccAdvCameraState, camera_flag_4) == 0x1678, "ccAdvCameraState.camera_flag_4");
static_assert(offsetof(ccAdvCameraState, camera_flag_5) == 0x167C, "ccAdvCameraState.camera_flag_5");
static_assert(offsetof(ccAdvCameraState, camera_ptr_4) == 0x1680, "ccAdvCameraState.camera_ptr_4");
static_assert(offsetof(ccAdvCameraState, camera_ptr_5) == 0x1688, "ccAdvCameraState.camera_ptr_5");
static_assert(offsetof(ccAdvCameraState, camera_ptr_6) == 0x1690, "ccAdvCameraState.camera_ptr_6");
static_assert(offsetof(ccAdvCameraState, camera_ptr_7) == 0x16D8, "ccAdvCameraState.camera_ptr_7");
static_assert(offsetof(ccAdvCameraState, camera_rw_ptr_1) == 0x16E0, "ccAdvCameraState.camera_rw_ptr_1");
static_assert(offsetof(ccAdvCameraState, camera_rw_ptr_2) == 0x1708, "ccAdvCameraState.camera_rw_ptr_2");
static_assert(offsetof(ccAdvCameraState, camera_rw_ptr_3) == 0x1710, "ccAdvCameraState.camera_rw_ptr_3");
static_assert(offsetof(ccAdvCameraState, camera_final_flag) == 0x1730, "ccAdvCameraState.camera_final_flag");

/* ================================================================== */
/* ccAdvCharaLoadState (8 methods)                                    */
/* Size unknown, >= 0x1508.                                           */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCharaLoadState {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x14B7[0x14B0];
    /* 0x14B8 */ uint8_t _pad_0x14B8_0x14BF[0x08]; /* plVar1 = param_1 + 0x297 read */
    /* 0x14C0 */ void *load_ptr_1;                /* ctor sets 0 */
    /* 0x14C8 */ void *load_rw_ptr_1;             /* ctor rw, sets 0 */
    /* 0x14D0 */ uint8_t _pad_0x14D0_0x14D7[0x08]; /* FUN_1405858f0 init */
    /* 0x14D8 */ uint8_t _pad_0x14D8_0x14E7[0x10];
    /* 0x14E8 */ uint8_t _pad_0x14E8_0x14EF[0x08]; /* plVar2 = param_1 + 0x29d read */
    /* 0x14F0 */ void *load_ptr_2;                /* ctor sets 0 */
    /* 0x14F8 */ void *load_rw_ptr_2;             /* ctor rw, sets 0 */
    /* 0x1500 */ uint8_t _pad_0x1500_0x1507[0x08]; /* FUN_1405858f0 init */
    /* 0x1508 -- end of known fields; size unknown, >= 0x1508 */
} ccAdvCharaLoadState;

static_assert(offsetof(ccAdvCharaLoadState, vtable) == 0x0000, "ccAdvCharaLoadState.vtable");
static_assert(offsetof(ccAdvCharaLoadState, load_ptr_1) == 0x14C0, "ccAdvCharaLoadState.load_ptr_1");
static_assert(offsetof(ccAdvCharaLoadState, load_rw_ptr_1) == 0x14C8, "ccAdvCharaLoadState.load_rw_ptr_1");
static_assert(offsetof(ccAdvCharaLoadState, load_ptr_2) == 0x14F0, "ccAdvCharaLoadState.load_ptr_2");
static_assert(offsetof(ccAdvCharaLoadState, load_rw_ptr_2) == 0x14F8, "ccAdvCharaLoadState.load_rw_ptr_2");

/* ================================================================== */
/* ccAdvCharaParam (7 methods)                                        */
/* Size unknown, >= 0x1970.                                           */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCharaParam {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x000B[0x04];
    /* 0x000C */ int32_t param_id;                /* Create/ctor sets 0 */
    /* 0x0010 */ uint8_t _pad_0x0010_0x001B[0x0C];
    /* 0x001C */ uint8_t _pad_0x001C_0x004B[0x30]; /* FUN_140580a40 init */
    /* 0x004C */ uint8_t _pad_0x004C_0x0057[0x0C];
    /* 0x0058 */ void *string_or_buf;             /* dtor checks length > 0xF */
    /* 0x0060 */ uint8_t _pad_0x0060_0x0077[0x18]; /* FUN_140585990 init */
    /* 0x0078 */ int32_t param_flag;              /* ctor sets 1 */
    /* 0x007C */ uint8_t _pad_0x007C_0x007F[0x04];
    /* 0x0080 */ void *param_ptr_1;               /* ctor sets 0 */
    /* 0x0088 */ void *param_ptr_2;               /* ctor sets 0 */
    /* 0x0090 */ uint8_t _pad_0x0090_0x0097[0x08];
    /* 0x0098 */ uint8_t _pad_0x0098_0x00BF[0x28]; /* puVar5 = param_1 + 0x13 region */
    /* 0x00C0 */ uint8_t _pad_0x00C0_0x04BF[0x400]; /* vtable deref region */
    /* 0x04C0 */ uint8_t _pad_0x04C0_0x089F[0x3E0]; /* Create writes *(ptr+0x98)=0 */
    /* 0x08A0 */ uint8_t _pad_0x08A0_0x0E2F[0x590]; /* FUN_1401b5fc8 init */
    /* 0x0E30 */ void *param_rw_ptr_1;            /* ctor/dtor rw, sets 0 */
    /* 0x0E38 */ uint8_t _pad_0x0E38_0x13C7[0x590]; /* FUN_1401b5fc8 init */
    /* 0x13C8 */ void *param_rw_ptr_2;            /* ctor/dtor rw, sets 0 */
    /* 0x13D0 */ uint8_t _pad_0x13D0_0x195F[0x590]; /* FUN_1401b5fc8 init */
    /* 0x1960 */ void *param_rw_ptr_3;            /* ctor/dtor rw, sets 0 */
    /* 0x1968 */ int32_t param_final_flag;        /* ctor sets 0 */
    /* 0x196C */ uint8_t _pad_0x196C_0x196F[0x04]; /* lVar2 = param_1 + 0x196c read */
    /* 0x1970 -- end of known fields; size unknown, >= 0x1970 */
} ccAdvCharaParam;

static_assert(offsetof(ccAdvCharaParam, vtable) == 0x0000, "ccAdvCharaParam.vtable");
static_assert(offsetof(ccAdvCharaParam, param_id) == 0x000C, "ccAdvCharaParam.param_id");
static_assert(offsetof(ccAdvCharaParam, string_or_buf) == 0x0058, "ccAdvCharaParam.string_or_buf");
static_assert(offsetof(ccAdvCharaParam, param_flag) == 0x0078, "ccAdvCharaParam.param_flag");
static_assert(offsetof(ccAdvCharaParam, param_ptr_1) == 0x0080, "ccAdvCharaParam.param_ptr_1");
static_assert(offsetof(ccAdvCharaParam, param_ptr_2) == 0x0088, "ccAdvCharaParam.param_ptr_2");
static_assert(offsetof(ccAdvCharaParam, param_rw_ptr_1) == 0x0E30, "ccAdvCharaParam.param_rw_ptr_1");
static_assert(offsetof(ccAdvCharaParam, param_rw_ptr_2) == 0x13C8, "ccAdvCharaParam.param_rw_ptr_2");
static_assert(offsetof(ccAdvCharaParam, param_rw_ptr_3) == 0x1960, "ccAdvCharaParam.param_rw_ptr_3");
static_assert(offsetof(ccAdvCharaParam, param_final_flag) == 0x1968, "ccAdvCharaParam.param_final_flag");

/* ================================================================== */
/* ccAdvCharaBird (5 methods)                                         */
/* Size unknown, >= 0x60.                                             */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCharaBird {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x0057[0x50];
    /* 0x0058 */ void *bird_ptr;                  /* ctor sets 0 */
    /* 0x0060 -- end of known fields; size unknown, >= 0x60 */
} ccAdvCharaBird;

static_assert(offsetof(ccAdvCharaBird, vtable) == 0x0000, "ccAdvCharaBird.vtable");
static_assert(offsetof(ccAdvCharaBird, bird_ptr) == 0x0058, "ccAdvCharaBird.bird_ptr");

/* ================================================================== */
/* ccAdvCollisonResultList (4 methods)                                */
/* Note: original typo "Collison" preserved from s2 symbols.          */
/* Size unknown, >= 0x50.                                             */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCollisonResultList {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x004B[0x44];
    /* 0x004C */ uint8_t _pad_0x004C_0x004F[0x04]; /* puVar1 = param_1 + 0x4c read */
    /* 0x0050 -- end of known fields; size unknown, >= 0x50 */
} ccAdvCollisonResultList;

static_assert(offsetof(ccAdvCollisonResultList, vtable) == 0x0000, "ccAdvCollisonResultList.vtable");

/* ================================================================== */
/* ccAdvClumpMobDraw (4 methods)                                      */
/* No fields found in state surface. Minimal vtable-only struct.      */
/* Size unknown, >= 0x8.                                              */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvClumpMobDraw {
    /* 0x0000 */ void *vtable;
    /* 0x0008 -- end of known fields; size unknown, >= 0x8 */
} ccAdvClumpMobDraw;

static_assert(offsetof(ccAdvClumpMobDraw, vtable) == 0x0000, "ccAdvClumpMobDraw.vtable");

/* ================================================================== */
/* ccAdvCharaDraw (4 methods)                                         */
/* No fields found in state surface. Minimal vtable-only struct.      */
/* Size unknown, >= 0x8.                                              */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCharaDraw {
    /* 0x0000 */ void *vtable;
    /* 0x0008 -- end of known fields; size unknown, >= 0x8 */
} ccAdvCharaDraw;

static_assert(offsetof(ccAdvCharaDraw, vtable) == 0x0000, "ccAdvCharaDraw.vtable");

/* ================================================================== */
/* ccAdvCameraCtrl (4 methods)                                        */
/* Size unknown, >= 0x1500.                                           */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCameraCtrl {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x14B7[0x14B0];
    /* 0x14B8 */ void *ctrl_ptr_1;                /* ctor sets 0 */
    /* 0x14C0 */ void *ctrl_ptr_2;                /* ctor sets 0 */
    /* 0x14C8 */ uint8_t _pad_0x14C8_0x14D3[0x0C]; /* FUN_140580a40 init */
    /* 0x14D4 */ uint8_t _pad_0x14D4_0x14DF[0x0C]; /* FUN_140580a40 init */
    /* 0x14E0 */ uint8_t _pad_0x14E0_0x14EB[0x0C]; /* FUN_140580a40 init */
    /* 0x14EC */ uint8_t _pad_0x14EC_0x14F7[0x0C]; /* FUN_140580a40 init */
    /* 0x14F8 */ float ctrl_float_1;              /* ctor sets 0x42340000 = 45.0f */
    /* 0x14FC */ int32_t ctrl_flag;               /* ctor sets 0 */
    /* 0x1500 -- end of known fields; size unknown, >= 0x1500 */
} ccAdvCameraCtrl;

static_assert(offsetof(ccAdvCameraCtrl, vtable) == 0x0000, "ccAdvCameraCtrl.vtable");
static_assert(offsetof(ccAdvCameraCtrl, ctrl_ptr_1) == 0x14B8, "ccAdvCameraCtrl.ctrl_ptr_1");
static_assert(offsetof(ccAdvCameraCtrl, ctrl_ptr_2) == 0x14C0, "ccAdvCameraCtrl.ctrl_ptr_2");
static_assert(offsetof(ccAdvCameraCtrl, ctrl_float_1) == 0x14F8, "ccAdvCameraCtrl.ctrl_float_1");
static_assert(offsetof(ccAdvCameraCtrl, ctrl_flag) == 0x14FC, "ccAdvCameraCtrl.ctrl_flag");

/* ================================================================== */
/* ccAdvCheckPointData (3 methods)                                    */
/* No fields found in state surface. Minimal vtable-only struct.      */
/* Size unknown, >= 0x8.                                              */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCheckPointData {
    /* 0x0000 */ void *vtable;
    /* 0x0008 -- end of known fields; size unknown, >= 0x8 */
} ccAdvCheckPointData;

static_assert(offsetof(ccAdvCheckPointData, vtable) == 0x0000, "ccAdvCheckPointData.vtable");

/* ================================================================== */
/* ccAdvCharaFootEffect (3 methods)                                   */
/* No fields found in state surface. Minimal vtable-only struct.      */
/* Size unknown, >= 0x8.                                              */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCharaFootEffect {
    /* 0x0000 */ void *vtable;
    /* 0x0008 -- end of known fields; size unknown, >= 0x8 */
} ccAdvCharaFootEffect;

static_assert(offsetof(ccAdvCharaFootEffect, vtable) == 0x0000, "ccAdvCharaFootEffect.vtable");

/* ================================================================== */
/* ccAdvCameraAreaParamManager (3 methods)                            */
/* Only one field access found (indirect write through ptr).          */
/* Size unknown, >= 0x8.                                              */
/* ================================================================== */
typedef struct __attribute__((packed)) ccAdvCameraAreaParamManager {
    /* 0x0000 */ void *vtable;
    /* 0x0008 */ uint8_t _pad_0x0008_0x007F[0x78];
    /* 0x0080 */ uint8_t _pad_0x0080_0x0087[0x08]; /* indirect: *(longlong*)(*param_1+0x10) = *param_1 */
    /* 0x0088 -- end of known fields; size unknown, >= 0x8 */
} ccAdvCameraAreaParamManager;

static_assert(offsetof(ccAdvCameraAreaParamManager, vtable) == 0x0000, "ccAdvCameraAreaParamManager.vtable");

#endif /* ST2A08_H */