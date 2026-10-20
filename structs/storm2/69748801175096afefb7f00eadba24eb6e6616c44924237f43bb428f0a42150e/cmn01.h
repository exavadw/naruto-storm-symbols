/*
 * cmn01.h — Common engine struct group for Storm 2 (s2, NSUNS2.exe x64)
 * Build: s2 (sha 69748801175096afefb7f00eadba24eb6e6616c44924237f43bb428f0a42150e)
 * All layouts INFERRED from static decompilation; no runtime confirmation.
 * Sizes are lower bounds from field access; structs end at last proven field.
 * Own-game names only (Storm 2 / ns2:: / strings).
 */
#ifndef CMN01_S2_H
#define CMN01_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* ccAppInitParam                                                      */
/* Embedded in ccApplication at +0x3C (see Initialize).                */
/* Fields from ParseCamera (0x63B504) and ParseData (0x63B6FC).        */
/* ParseCamera writes float at param_1+8, +0xC, +0x10 and u32 at +0x14.*/
/* ParseData writes u32 at param_1+0 and param_1+4.                    */
/* Size unknown, >= 0x18.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns2_ccAppInitParam {
    uint32_t readDrive;           /* 0x00: from ParseData "readDrive" (bool as u32) */
    uint32_t readCpk;             /* 0x04: from ParseData "readCpk" (bool as u32) */
    float    moveSpdScale;        /* 0x08: from ParseCamera "moveSpdScale" */
    float    approachSpdScaleInitial; /* 0x0C: from ParseCamera "approachSpdScaleInitial" */
    float    rotSpeed;            /* 0x10: from ParseCamera "rotSpeed" */
    uint32_t speedUp;             /* 0x14: from ParseCamera "speedUp" (bool as u32) */
} ns2_ccAppInitParam;

static_assert(offsetof(ns2_ccAppInitParam, readDrive) == 0x00, "ns2_ccAppInitParam.readDrive");
static_assert(offsetof(ns2_ccAppInitParam, readCpk) == 0x04, "ns2_ccAppInitParam.readCpk");
static_assert(offsetof(ns2_ccAppInitParam, moveSpdScale) == 0x08, "ns2_ccAppInitParam.moveSpdScale");
static_assert(offsetof(ns2_ccAppInitParam, approachSpdScaleInitial) == 0x0C, "ns2_ccAppInitParam.approachSpdScaleInitial");
static_assert(offsetof(ns2_ccAppInitParam, rotSpeed) == 0x10, "ns2_ccAppInitParam.rotSpeed");
static_assert(offsetof(ns2_ccAppInitParam, speedUp) == 0x14, "ns2_ccAppInitParam.speedUp");

/* ------------------------------------------------------------------ */
/* ccApplication                                                       */
/* Main application class. Fields from Initialize (0x63BA84),          */
/* Finalize (0x63B9AC), UnsetPushedSignoutDialogFlag (0x63BF90),       */
/* IsIntercepted (0x63C068).                                           */
/* Decompiler uses longlong* => param_1[N] = byte offset N*8.          */
/* param_1[4]=+0x20, [5]=+0x28, [6]=+0x30, [0xC]=+0x60, [0x12]=+0x90 */
/* *(param_1+7)=+0x38, *(param_1+0x15)=+0xA8                           */
/* initParam embedded at (longlong)param_1+0x3C = byte +0x3C.          */
/* IsIntercepted reads *(param_1 + 0x9c) — NEW in s2, not in s1.       */
/* field_30 set to 9 in s2 (was 1 in s1).                              */
/* Size unknown, >= 0xAC.                                              */
/* Vtable: PTR_FUN_1408310e0 (from Initialize).                        */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns2_ccApplication {
    uint8_t  vtable[8];           /* 0x00: vtable ptr */
    uint8_t  pad_08[0x18];        /* 0x08-0x1F: base class / padding */
    void    *fileLoadListUi;      /* 0x20: param_1[4], freed in Finalize */
    void    *partyPlayHosting;    /* 0x28: param_1[5], freed in Finalize */
    uint32_t field_30;            /* 0x30: param_1[6] set to 9 in Initialize */
    uint8_t  pad_34[0x04];        /* 0x34-0x37: gap */
    uint32_t signoutDialogFlag;   /* 0x38: *(param_1+7), cleared by Unset/Finalize */
    ns2_ccAppInitParam initParam; /* 0x3C: embedded, passed to Parse */
    uint8_t  pad_54[0x0C];        /* 0x54-0x5F: gap */
    void    *pauseUpdateThread;   /* 0x60: param_1[0xC], thread handle */
    uint8_t  pad_68[0x20];        /* 0x68-0x87: gap (param_1[0xD..0x10]) */
    uint32_t field_88;            /* 0x88: *(param_1+0x11) cleared in Finalize */
    uint8_t  pad_8C[0x04];        /* 0x8C-0x8F: gap */
    void    *blockAllocator;      /* 0x90: param_1[0x12], Nucc::Memory::BlockAllocator */
    uint8_t  pad_98[0x04];        /* 0x98-0x9B: gap */
    uint32_t interceptFlag;       /* 0x9C: *(param_1+0x9c), read by IsIntercepted (NEW s2) */
    uint8_t  pad_A0[0x08];        /* 0xA0-0xA7: gap */
    uint32_t initMode;            /* 0xA8: *(param_1+0x15), set in Initialize */
} ns2_ccApplication;

static_assert(offsetof(ns2_ccApplication, fileLoadListUi) == 0x20, "ns2_ccApplication.fileLoadListUi");
static_assert(offsetof(ns2_ccApplication, partyPlayHosting) == 0x28, "ns2_ccApplication.partyPlayHosting");
static_assert(offsetof(ns2_ccApplication, field_30) == 0x30, "ns2_ccApplication.field_30");
static_assert(offsetof(ns2_ccApplication, signoutDialogFlag) == 0x38, "ns2_ccApplication.signoutDialogFlag");
static_assert(offsetof(ns2_ccApplication, initParam) == 0x3C, "ns2_ccApplication.initParam");
static_assert(offsetof(ns2_ccApplication, pauseUpdateThread) == 0x60, "ns2_ccApplication.pauseUpdateThread");
static_assert(offsetof(ns2_ccApplication, field_88) == 0x88, "ns2_ccApplication.field_88");
static_assert(offsetof(ns2_ccApplication, blockAllocator) == 0x90, "ns2_ccApplication.blockAllocator");
static_assert(offsetof(ns2_ccApplication, interceptFlag) == 0x9C, "ns2_ccApplication.interceptFlag");
static_assert(offsetof(ns2_ccApplication, initMode) == 0xA8, "ns2_ccApplication.initMode");

/* ------------------------------------------------------------------ */
/* ccBuildUniqueId                                                     */
/* Simple ID generator. Embedded in parent classes.                    */
/* Fields from ctor (0x6597D0), GetId (0x659820), Reset (0x659800).   */
/* s2 ctor: *param_1 = 1 (u64), *(param_1+1) = 0 (u32 at +0x08).     */
/* NOTE: s2 layout differs from s1! s1 had u32 at +0x00; s2 has u64.  */
/* GetId increments *(param_1+8) as int, wraps to 1 if 0.             */
/* Size: >= 0x0C (last field at +0x08, 4 bytes).                       */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns2_ccBuildUniqueId {
    uint64_t initial;             /* 0x00: set to 1 in ctor/Reset (u64 in s2) */
    uint32_t counter;             /* 0x08: incremented by GetId, wraps to 1 on overflow */
} ns2_ccBuildUniqueId;

static_assert(offsetof(ns2_ccBuildUniqueId, initial) == 0x00, "ns2_ccBuildUniqueId.initial");
static_assert(offsetof(ns2_ccBuildUniqueId, counter) == 0x08, "ns2_ccBuildUniqueId.counter");

/* ------------------------------------------------------------------ */
/* ccCmnCamera                                                         */
/* Inherits nuccCamera (ctor calls nuccCamera::nuccCamera first).      */
/* Fields from Copy (0x63C200) and Update (0x63C250).                  */
/* nuccCamera base size = 0x2C (inferred from first own-field offset). */
/* Copy copies: +0x2C(u32), +0x30(Matrix44=0x40), then scattered.      */
/* Update reads Vector3 at +0x70, +0x7C, +0x88 and writes matrix +0x30.*/
/* Stack allocation local_a8[160] in SetStandDemoCameraPrevCmnCamera   */
/* confirms size >= 0xA0.                                              */
/* Vtable: PTR_FUN_1408312b0 (from ctor).                              */
/* Size unknown, >= 0xA0.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns2_ccCmnCamera {
    uint8_t  nuccCamera_base[0x2C]; /* 0x00: nuccCamera base */
    uint32_t flags;               /* 0x2C: copied in Copy */
    uint8_t  viewMatrix[0x40];    /* 0x30: Nucc::Matrix44_MathGeo, written by Update */
    uint8_t  eyePosition[0x0C];   /* 0x70: Vector3, read by Update/TonuVECTOR3 */
    uint8_t  lookAtTarget[0x0C];  /* 0x7C: Vector3, read by Update/TonuVECTOR3 */
    uint8_t  upVector[0x0C];      /* 0x88: Vector3, read by Update/TonuVECTOR3 */
    uint64_t field_94;            /* 0x94: copied in Copy as u64 */
    uint32_t field_9C;            /* 0x9C: copied in Copy as u32 */
} ns2_ccCmnCamera;

static_assert(offsetof(ns2_ccCmnCamera, flags) == 0x2C, "ns2_ccCmnCamera.flags");
static_assert(offsetof(ns2_ccCmnCamera, viewMatrix) == 0x30, "ns2_ccCmnCamera.viewMatrix");
static_assert(offsetof(ns2_ccCmnCamera, eyePosition) == 0x70, "ns2_ccCmnCamera.eyePosition");
static_assert(offsetof(ns2_ccCmnCamera, lookAtTarget) == 0x7C, "ns2_ccCmnCamera.lookAtTarget");
static_assert(offsetof(ns2_ccCmnCamera, upVector) == 0x88, "ns2_ccCmnCamera.upVector");
static_assert(offsetof(ns2_ccCmnCamera, field_94) == 0x94, "ns2_ccCmnCamera.field_94");
static_assert(offsetof(ns2_ccCmnCamera, field_9C) == 0x9C, "ns2_ccCmnCamera.field_9C");

/* ------------------------------------------------------------------ */
/* QuakeParamEntry — sub-struct within ccCmnCameraOperator             */
/* Stride 0x24, array of 3 at +0x104.                                 */
/* From SetQuakeParam (0x63CBA0) and ClearQuakeParam (0x63CD20).       */
/* Layout per entry: u32 duration, u32 elapsed, Vector3 vec1,          */
/*   Vector3 vec2, u32 param, u32 pad.                                 */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns2_QuakeParamEntry {
    uint32_t duration;            /* 0x00: param_3 in SetQuakeParam */
    uint32_t elapsed;             /* 0x04: set to 0 in SetQuakeParam */
    uint8_t  vec1[0x0C];          /* 0x08: Vector3 from param_2 */
    uint8_t  vec2[0x0C];          /* 0x14: Vector3 from param_2 */
    uint32_t param;               /* 0x20: param_4 in SetQuakeParam */
} ns2_QuakeParamEntry;

static_assert(sizeof(ns2_QuakeParamEntry) == 0x24, "ns2_QuakeParamEntry stride");

/* ------------------------------------------------------------------ */
/* ccCmnCameraOperator                                                 */
/* Inherits ccTaskBase (0x40) then embeds ccCmnCamera at +0x40.        */
/* Fields from ctor (0x63C9C0), UpdateCamera (0x63CB20),               */
/* SetQuakeParam (0x63CBA0), ClearQuakeParam (0x63CD20).               */
/* ccCmnCamera at param_1+8 (=+0x40), size >= 0xA0 → ends at +0xE0.   */
/* Quake fields at +0xE0..+0x170, camera copy at +0x170..+0x194.      */
/* fov=45.0f at +0x194, nearPlane=0.1f at +0x19C.                     */
/* activeFlag at +0x1A8 checked in SetQuakeParam.                      */
/* Vtable: PTR_FUN_14089df98 (from ctor).                              */
/* Size unknown, >= 0x1B0.                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns2_ccCmnCameraOperator {
    uint8_t  ccTaskBase[0x40];    /* 0x00: ccTaskBase base class */
    ns2_ccCmnCamera camera;       /* 0x40: embedded ccCmnCamera (>= 0xA0) */
    uint32_t quakeDuration;       /* 0xE0: fallback quake duration */
    uint32_t quakeIndex;          /* 0xE4: current quake index, compared to quakeDuration */
    uint8_t  quakeVec1[0x0C];     /* 0xE8: fallback Vector3 */
    uint8_t  quakeVec2[0x0C];     /* 0xF4: fallback Vector3 */
    uint32_t quakeParam;          /* 0x100: fallback param */
    uint8_t  pad_104[0x00];       /* alignment */
    ns2_QuakeParamEntry quakeArray[3]; /* 0x104: stride 0x24, max 3 entries */
    uint64_t camCopy_eyePos;      /* 0x170: u64 copied from camera +0xB0 in UpdateCamera */
    uint32_t camCopy_flags;       /* 0x178: u32 copied from camera +0xB8 */
    uint64_t camCopy_lookAt;      /* 0x17C: u64 copied from camera +0xBC */
    uint32_t camCopy_up_x;        /* 0x184: u32 copied from camera +0xC4 */
    uint64_t camCopy_up_yz;       /* 0x188: u64 copied from camera +0xC8 */
    uint32_t camCopy_field;       /* 0x190: u32 copied from camera +0xD0 */
    float    fov;                 /* 0x194: 45.0f default, copied from camera +0x6C */
    uint8_t  pad_198[0x04];       /* 0x198: gap */
    float    nearPlane;           /* 0x19C: 0.1f default */
    float    field_1A0;           /* 0x1A0: 0x3e4ccccd (~0.2f) in ctor */
    uint32_t field_1A4;           /* 0x1A4: zeroed in ctor (u64 zero covers 0x1A4-0x1AB) */
    int32_t  activeFlag;          /* 0x1A8: checked != 0 in SetQuakeParam */
    uint32_t field_1AC;           /* 0x1AC: set to 0 in ctor */
} ns2_ccCmnCameraOperator;

static_assert(offsetof(ns2_ccCmnCameraOperator, camera) == 0x40, "ns2_ccCmnCameraOperator.camera");
static_assert(offsetof(ns2_ccCmnCameraOperator, quakeDuration) == 0xE0, "ns2_ccCmnCameraOperator.quakeDuration");
static_assert(offsetof(ns2_ccCmnCameraOperator, quakeIndex) == 0xE4, "ns2_ccCmnCameraOperator.quakeIndex");
static_assert(offsetof(ns2_ccCmnCameraOperator, quakeVec1) == 0xE8, "ns2_ccCmnCameraOperator.quakeVec1");
static_assert(offsetof(ns2_ccCmnCameraOperator, quakeVec2) == 0xF4, "ns2_ccCmnCameraOperator.quakeVec2");
static_assert(offsetof(ns2_ccCmnCameraOperator, quakeParam) == 0x100, "ns2_ccCmnCameraOperator.quakeParam");
static_assert(offsetof(ns2_ccCmnCameraOperator, quakeArray) == 0x104, "ns2_ccCmnCameraOperator.quakeArray");
static_assert(offsetof(ns2_ccCmnCameraOperator, fov) == 0x194, "ns2_ccCmnCameraOperator.fov");
static_assert(offsetof(ns2_ccCmnCameraOperator, nearPlane) == 0x19C, "ns2_ccCmnCameraOperator.nearPlane");
static_assert(offsetof(ns2_ccCmnCameraOperator, activeFlag) == 0x1A8, "ns2_ccCmnCameraOperator.activeFlag");
static_assert(offsetof(ns2_ccCmnCameraOperator, field_1AC) == 0x1AC, "ns2_ccCmnCameraOperator.field_1AC");

#endif /* CMN01_S2_H */