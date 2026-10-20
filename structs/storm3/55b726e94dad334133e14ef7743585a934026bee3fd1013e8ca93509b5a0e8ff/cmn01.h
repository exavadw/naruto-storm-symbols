/*
 * cmn01.h — Common engine struct group for Storm 3 (s3, NSUNS3.exe x64)
 * Build: s3 (NARUTO STORM 3 Full Burst HD PC, 64-bit)
 * All layouts INFERRED from static decompilation; no runtime confirmation.
 * Sizes are lower bounds from field access; structs end at last proven field.
 * Own-game names only (Storm 3 / ns3:: / strings).
 */
#ifndef CMN01_S3_H
#define CMN01_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* ccAppInitParam                                                      */
/* Embedded in ccApplication at +0x3C (see Initialize).                */
/* Fields from ParseCamera (0x6275C4) and ParseData (0x6277BC).        */
/* ParseCamera writes float at param_1+8, +0xC, +0x10 and u32 at +0x14.*/
/* ParseData writes u32 at param_1+0 and param_1+4.                    */
/* Size unknown, >= 0x18.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccAppInitParam {
    uint32_t readDrive;              /* 0x00: from ParseData "readDrive" (bool as u32) */
    uint32_t readCpk;                /* 0x04: from ParseData "readCpk" (bool as u32) */
    float    moveSpdScale;           /* 0x08: from ParseCamera "moveSpdScale" */
    float    approachSpdScaleInitial;/* 0x0C: from ParseCamera "approachSpdScaleInitial" */
    float    rotSpeed;               /* 0x10: from ParseCamera "rotSpeed" */
    uint32_t speedUp;                /* 0x14: from ParseCamera "speedUp" (bool as u32) */
} ns3_ccAppInitParam;

static_assert(offsetof(ns3_ccAppInitParam, readDrive) == 0x00, "ns3_ccAppInitParam.readDrive");
static_assert(offsetof(ns3_ccAppInitParam, readCpk) == 0x04, "ns3_ccAppInitParam.readCpk");
static_assert(offsetof(ns3_ccAppInitParam, moveSpdScale) == 0x08, "ns3_ccAppInitParam.moveSpdScale");
static_assert(offsetof(ns3_ccAppInitParam, approachSpdScaleInitial) == 0x0C, "ns3_ccAppInitParam.approachSpdScaleInitial");
static_assert(offsetof(ns3_ccAppInitParam, rotSpeed) == 0x10, "ns3_ccAppInitParam.rotSpeed");
static_assert(offsetof(ns3_ccAppInitParam, speedUp) == 0x14, "ns3_ccAppInitParam.speedUp");

/* ------------------------------------------------------------------ */
/* ccApplication                                                       */
/* Main application class. Fields from Initialize (0x627C10),          */
/* Finalize (0x627B38), UnsetPushedSignoutDialogFlag (0x6281A4),       */
/* IsIntercepted (0x62819C).                                           */
/* Decompiler uses longlong* => param_1[N] = byte offset N*8.          */
/* param_1[4]=+0x20, [5]=+0x28, [0xC]=+0x60, [0x12]=+0x90             */
/* *(param_1+7)=+0x38, *(param_1+0x15)=+0xA8                           */
/* initParam embedded at (longlong)param_1+0x3C = byte +0x3C.          */
/* Size unknown, >= 0xAC.                                              */
/* Vtable: set in Initialize.                                          */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccApplication {
    uint8_t  vtable[8];              /* 0x00: vtable ptr */
    uint8_t  pad_08[0x18];           /* 0x08-0x1F: base class / padding */
    void    *fileLoadListUi;         /* 0x20: param_1[4], freed in Finalize */
    void    *partyPlayHosting;       /* 0x28: param_1[5], freed in Finalize */
    uint8_t  pad_30[0x08];           /* 0x30-0x37: gap */
    uint32_t signoutDialogFlag;      /* 0x38: *(param_1+7), cleared by Unset/Finalize */
    ns3_ccAppInitParam initParam;    /* 0x3C: embedded, passed to Parse */
    uint8_t  pad_54[0x0C];           /* 0x54-0x5F: gap */
    void    *pauseUpdateThread;      /* 0x60: param_1[0xC], thread handle */
    uint8_t  pad_68[0x20];           /* 0x68-0x87: gap */
    uint32_t field_88;               /* 0x88: *(param_1+0x11) cleared in Finalize */
    uint8_t  pad_8C[0x04];           /* 0x8C-0x8F: gap */
    void    *blockAllocator;         /* 0x90: param_1[0x12], freed in Finalize */
    uint8_t  pad_98[0x04];           /* 0x98-0x9B: gap */
    uint32_t interceptFlag;          /* 0x9C: *(param_1+0x9c), read by IsIntercepted */
    uint8_t  pad_A0[0x08];           /* 0xA0-0xA7: gap */
    uint32_t initMode;               /* 0xA8: *(param_1+0x15), set in Initialize */
} ns3_ccApplication;

static_assert(offsetof(ns3_ccApplication, fileLoadListUi) == 0x20, "ns3_ccApplication.fileLoadListUi");
static_assert(offsetof(ns3_ccApplication, partyPlayHosting) == 0x28, "ns3_ccApplication.partyPlayHosting");
static_assert(offsetof(ns3_ccApplication, signoutDialogFlag) == 0x38, "ns3_ccApplication.signoutDialogFlag");
static_assert(offsetof(ns3_ccApplication, initParam) == 0x3C, "ns3_ccApplication.initParam");
static_assert(offsetof(ns3_ccApplication, pauseUpdateThread) == 0x60, "ns3_ccApplication.pauseUpdateThread");
static_assert(offsetof(ns3_ccApplication, field_88) == 0x88, "ns3_ccApplication.field_88");
static_assert(offsetof(ns3_ccApplication, blockAllocator) == 0x90, "ns3_ccApplication.blockAllocator");
static_assert(offsetof(ns3_ccApplication, interceptFlag) == 0x9C, "ns3_ccApplication.interceptFlag");
static_assert(offsetof(ns3_ccApplication, initMode) == 0xA8, "ns3_ccApplication.initMode");

/* ------------------------------------------------------------------ */
/* ccBuildUniqueId                                                     */
/* Simple ID generator. Embedded in parent classes.                    */
/* Fields from ctor (0x75E610), GetId (0x75E660),                      */
/* SetWrapAroundHalt (0x75E690), SetWrapAroundWarning (0x75E680).      */
/* ctor: *param_1 = 1 (u64), *(u32*)(param_1+1) = 0 (byte +0x08).     */
/* GetId increments *(int*)(param_1+8) = byte +0x08, wraps to 1.      */
/* SetWrapAroundHalt writes *(u32*)(param_1+4) where param_1 is        */
/*   longlong = byte +0x04.                                            */
/* SetWrapAroundWarning writes *param_1 as undefined4* = u32 at +0x00. */
/* Size: >= 0x0C (last field at +0x08, 4 bytes).                       */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccBuildUniqueId {
    uint32_t initial;                /* 0x00: SetWrapAroundWarning writes u32 here */
    uint32_t haltThreshold;          /* 0x04: SetWrapAroundHalt writes u32 here */
    uint32_t counter;                /* 0x08: incremented by GetId, wraps to 1 */
} ns3_ccBuildUniqueId;

static_assert(offsetof(ns3_ccBuildUniqueId, initial) == 0x00, "ns3_ccBuildUniqueId.initial");
static_assert(offsetof(ns3_ccBuildUniqueId, haltThreshold) == 0x04, "ns3_ccBuildUniqueId.haltThreshold");
static_assert(offsetof(ns3_ccBuildUniqueId, counter) == 0x08, "ns3_ccBuildUniqueId.counter");

/* ------------------------------------------------------------------ */
/* ccCmnCamera                                                         */
/* Inherits nuccCamera (ctor calls nuccCamera::nuccCamera first).      */
/* Fields from Copy (0x74AC40) and Update (0x74ABB0).                  */
/* nuccCamera base size = 0x2C (inferred from first own-field offset). */
/* Copy copies: +0x2C(u32), +0x30(Matrix44=0x40), then scattered.      */
/* Update reads Vector3 at +0x70, +0x7C, +0x88.                        */
/* Vtable: PTR_FUN_1408d4b10.                                          */
/* Size unknown, >= 0xA0.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccCmnCamera {
    uint8_t  nuccCamera_base[0x2C];  /* 0x00: nuccCamera base */
    uint32_t flags;                  /* 0x2C: copied in Copy */
    uint8_t  viewMatrix[0x40];       /* 0x30: Matrix44, written by Update */
    uint8_t  eyePosition[0x0C];      /* 0x70: Vector3, read by Update */
    uint8_t  lookAtTarget[0x0C];     /* 0x7C: Vector3, read by Update */
    uint8_t  upVector[0x0C];         /* 0x88: Vector3, read by Update */
    uint8_t  rightDirection[0x0C];   /* 0x94: copied in Copy as u64+u32 */
} ns3_ccCmnCamera;

static_assert(offsetof(ns3_ccCmnCamera, flags) == 0x2C, "ns3_ccCmnCamera.flags");
static_assert(offsetof(ns3_ccCmnCamera, viewMatrix) == 0x30, "ns3_ccCmnCamera.viewMatrix");
static_assert(offsetof(ns3_ccCmnCamera, eyePosition) == 0x70, "ns3_ccCmnCamera.eyePosition");
static_assert(offsetof(ns3_ccCmnCamera, lookAtTarget) == 0x7C, "ns3_ccCmnCamera.lookAtTarget");
static_assert(offsetof(ns3_ccCmnCamera, upVector) == 0x88, "ns3_ccCmnCamera.upVector");
static_assert(offsetof(ns3_ccCmnCamera, rightDirection) == 0x94, "ns3_ccCmnCamera.rightDirection");

/* ------------------------------------------------------------------ */
/* QuakeParamEntry — sub-struct within ccCmnCameraOperator             */
/* Stride 0x24, array of 3 at +0x108.                                 */
/* From SetQuakeParam (0x74B4C0) and ClearQuakeParam (0x74B640).       */
/* Layout per entry: u32 duration, u32 elapsed, Vector3 vec1,          */
/*   Vector3 vec2, u32 param.                                          */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_QuakeParamEntry {
    uint32_t duration;               /* 0x00: quake duration */
    uint32_t elapsed;                /* 0x04: set to 0 in SetQuakeParam */
    uint8_t  vec1[0x0C];             /* 0x08: Vector3 */
    uint8_t  vec2[0x0C];             /* 0x14: Vector3 */
    uint32_t param;                  /* 0x20: quake parameter */
} ns3_QuakeParamEntry;

static_assert(sizeof(ns3_QuakeParamEntry) == 0x24, "ns3_QuakeParamEntry stride");

/* ------------------------------------------------------------------ */
/* ccCmnCameraOperator                                                 */
/* Inherits ccTaskBase (0x40) then embeds ccCmnCamera at +0x40.        */
/* Fields from ctor (0x74B2E0), UpdateCamera (0x74B440),               */
/* SetQuakeParam (0x74B4C0), ClearQuakeParam (0x74B640),               */
/* Quake (0x74B6F0), InterpView (0x74BAC0).                            */
/* ccCmnCamera at param_1+8 (=+0x40), size 0xA0 -> ends at +0xE0.     */
/* Quake fields at +0xE0..+0x108, quakeArray[3] at +0x108.            */
/* Camera copy at +0x174..+0x198, fov at +0x198.                      */
/* activeFlag at +0x1B0 checked in SetQuakeParam.                      */
/* Vtable: PTR_FUN_1409ec390 (from ctor).                              */
/* Size unknown, >= 0x1B8.                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccCmnCameraOperator {
    uint8_t  ccTaskBase[0x40];       /* 0x00: ccTaskBase base class */
    ns3_ccCmnCamera camera;          /* 0x40: embedded ccCmnCamera (0xA0) */
    uint32_t quakeDuration;          /* 0xE0: fallback quake duration */
    uint32_t quakeIndex;             /* 0xE4: current quake index */
    uint8_t  quakeVec1[0x0C];        /* 0xE8: fallback Vector3 */
    uint8_t  quakeVec2[0x0C];        /* 0xF4: fallback Vector3 */
    uint32_t quakeVec2_z;            /* 0x100: part of quakeVec2 or separate */
    uint32_t quakeParam;             /* 0x104: fallback param */
    ns3_QuakeParamEntry quakeArray[3]; /* 0x108: stride 0x24, max 3 entries */
    uint64_t camCopy_eyePos;         /* 0x174: copied from camera */
    uint32_t camCopy_flags;          /* 0x17C: copied from camera */
    uint64_t camCopy_lookAt;         /* 0x180: copied from camera */
    uint32_t camCopy_up_x;           /* 0x188: copied from camera */
    uint64_t camCopy_up_yz;          /* 0x18C: copied from camera */
    uint32_t camCopy_field;          /* 0x194: copied from camera */
    float    fov;                    /* 0x198: 45.0f default */
    int32_t  interpActive;           /* 0x19C: checked != 0 in InterpView */
    float    interpAlpha;            /* 0x1A0: lerp alpha in InterpView */
    float    field_1A4;              /* 0x1A4: ~0.2f in ctor */
    uint64_t field_1A8;              /* 0x1A8: zeroed in ctor */
    int32_t  activeFlag;             /* 0x1B0: checked != 0 in SetQuakeParam */
    uint32_t field_1B4;              /* 0x1B4: set to 0 in ctor */
} ns3_ccCmnCameraOperator;

static_assert(offsetof(ns3_ccCmnCameraOperator, camera) == 0x40, "ns3_ccCmnCameraOperator.camera");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeDuration) == 0xE0, "ns3_ccCmnCameraOperator.quakeDuration");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeIndex) == 0xE4, "ns3_ccCmnCameraOperator.quakeIndex");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeVec1) == 0xE8, "ns3_ccCmnCameraOperator.quakeVec1");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeVec2) == 0xF4, "ns3_ccCmnCameraOperator.quakeVec2");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeVec2_z) == 0x100, "ns3_ccCmnCameraOperator.quakeVec2_z");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeParam) == 0x104, "ns3_ccCmnCameraOperator.quakeParam");
static_assert(offsetof(ns3_ccCmnCameraOperator, quakeArray) == 0x108, "ns3_ccCmnCameraOperator.quakeArray");
static_assert(offsetof(ns3_ccCmnCameraOperator, camCopy_eyePos) == 0x174, "ns3_ccCmnCameraOperator.camCopy_eyePos");
static_assert(offsetof(ns3_ccCmnCameraOperator, camCopy_flags) == 0x17C, "ns3_ccCmnCameraOperator.camCopy_flags");
static_assert(offsetof(ns3_ccCmnCameraOperator, camCopy_lookAt) == 0x180, "ns3_ccCmnCameraOperator.camCopy_lookAt");
static_assert(offsetof(ns3_ccCmnCameraOperator, camCopy_up_x) == 0x188, "ns3_ccCmnCameraOperator.camCopy_up_x");
static_assert(offsetof(ns3_ccCmnCameraOperator, camCopy_up_yz) == 0x18C, "ns3_ccCmnCameraOperator.camCopy_up_yz");
static_assert(offsetof(ns3_ccCmnCameraOperator, camCopy_field) == 0x194, "ns3_ccCmnCameraOperator.camCopy_field");
static_assert(offsetof(ns3_ccCmnCameraOperator, fov) == 0x198, "ns3_ccCmnCameraOperator.fov");
static_assert(offsetof(ns3_ccCmnCameraOperator, interpActive) == 0x19C, "ns3_ccCmnCameraOperator.interpActive");
static_assert(offsetof(ns3_ccCmnCameraOperator, interpAlpha) == 0x1A0, "ns3_ccCmnCameraOperator.interpAlpha");
static_assert(offsetof(ns3_ccCmnCameraOperator, field_1A4) == 0x1A4, "ns3_ccCmnCameraOperator.field_1A4");
static_assert(offsetof(ns3_ccCmnCameraOperator, field_1A8) == 0x1A8, "ns3_ccCmnCameraOperator.field_1A8");
static_assert(offsetof(ns3_ccCmnCameraOperator, activeFlag) == 0x1B0, "ns3_ccCmnCameraOperator.activeFlag");
static_assert(offsetof(ns3_ccCmnCameraOperator, field_1B4) == 0x1B4, "ns3_ccCmnCameraOperator.field_1B4");

#endif /* CMN01_S3_H */
