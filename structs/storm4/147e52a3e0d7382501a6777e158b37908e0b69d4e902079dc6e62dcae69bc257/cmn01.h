/*
 * cmn01.h — Storm 4 (s4, NSUNS4_release.exe 1.09) struct layouts
 * Group: bul::CBuffer, bul::CCommandBuffer, bul::CDevice, bul::CShader,
 *        ccAppInitParam, ccApplication, ccBltUtil, ccBuildUniqueId,
 *        ccBulletCollisionContactResult, ccCmnCamera, ccCmnCameraOperator
 *
 * All structs __attribute__((packed)). Every field has a static_assert
 * on offsetof. Sizes proven from allocator/ctor/factory calls in game code.
 * Static analysis only — everything is INFERRED, not CONFIRMED.
 *
 * Build: s4 = NSUNS4_release.exe, SHA 147e52a3e0d7, image base 0x140000000
 */

#ifndef CMN01_S4_H
#define CMN01_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* ccAppInitParam — embedded in ccApplication at +0x68                 */
/* Size >= 0x24 (pad to align after embedded use).                     */
/* Ctor/init writes up to +0x1C. s4 shifted +0x08 vs s3.              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  pad_00[8];             /* +0x00 */
    uint32_t readDrive;             /* +0x08 PRES */
    uint32_t readCpk;               /* +0x0C PRES */
    float    moveSpdScale;          /* +0x10 SIM */
    float    approachSpdScaleInitial;/* +0x14 SIM */
    float    rotSpeed;              /* +0x18 SIM */
    uint32_t speedUp;               /* +0x1C PRES */
} ccAppInitParam;

static_assert(offsetof(ccAppInitParam, readDrive) == 0x08, "ccAppInitParam.readDrive");
static_assert(offsetof(ccAppInitParam, readCpk) == 0x0C, "ccAppInitParam.readCpk");
static_assert(offsetof(ccAppInitParam, moveSpdScale) == 0x10, "ccAppInitParam.moveSpdScale");
static_assert(offsetof(ccAppInitParam, approachSpdScaleInitial) == 0x14, "ccAppInitParam.approachSpdScaleInitial");
static_assert(offsetof(ccAppInitParam, rotSpeed) == 0x18, "ccAppInitParam.rotSpeed");
static_assert(offsetof(ccAppInitParam, speedUp) == 0x1C, "ccAppInitParam.speedUp");

/* ------------------------------------------------------------------ */
/* ccBuildUniqueId — size >= 0x0C                                      */
/* Ctor: +0x00=1, +0x04=0. GetId increments +0x08, wraps to 1.       */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint32_t initial;               /* +0x00 UNKNOWN, ctor=1 */
    uint32_t haltThreshold;         /* +0x04 UNKNOWN, SetWrapAroundHalt */
    uint32_t counter;               /* +0x08 PRES, GetId increments */
} ccBuildUniqueId;

static_assert(offsetof(ccBuildUniqueId, initial) == 0x00, "ccBuildUniqueId.initial");
static_assert(offsetof(ccBuildUniqueId, haltThreshold) == 0x04, "ccBuildUniqueId.haltThreshold");
static_assert(offsetof(ccBuildUniqueId, counter) == 0x08, "ccBuildUniqueId.counter");

/* ------------------------------------------------------------------ */
/* ccCmnCamera — size >= 0xA0                                          */
/* vtable at +0x00. nuccCamera base to +0x2C. viewMatrix 0x40 bytes.  */
/* Eye/lookAt/up/right vectors +0x70..+0x9C.                           */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    void    *vtable;                /* +0x00 */
    uint8_t  base_08[0x24];         /* +0x08 nuccCamera base to +0x2C */
    uint32_t flags;                 /* +0x2C UNKNOWN */
    uint8_t  viewMatrix[0x40];      /* +0x30 SIM Matrix44 */
    float    eyePosition[3];        /* +0x70 SIM Vector3 */
    float    lookAtTarget[3];       /* +0x7C SIM Vector3 */
    float    upVector[3];           /* +0x88 SIM Vector3 */
    float    rightDirection[3];     /* +0x94 UNKNOWN Vector3 */
} ccCmnCamera;

static_assert(offsetof(ccCmnCamera, vtable) == 0x00, "ccCmnCamera.vtable");
static_assert(offsetof(ccCmnCamera, flags) == 0x2C, "ccCmnCamera.flags");
static_assert(offsetof(ccCmnCamera, viewMatrix) == 0x30, "ccCmnCamera.viewMatrix");
static_assert(offsetof(ccCmnCamera, eyePosition) == 0x70, "ccCmnCamera.eyePosition");
static_assert(offsetof(ccCmnCamera, lookAtTarget) == 0x7C, "ccCmnCamera.lookAtTarget");
static_assert(offsetof(ccCmnCamera, upVector) == 0x88, "ccCmnCamera.upVector");
static_assert(offsetof(ccCmnCamera, rightDirection) == 0x94, "ccCmnCamera.rightDirection");

/* ------------------------------------------------------------------ */
/* QuakeParamEntry — 0x24 bytes, array of 3 in ccCmnCameraOperator    */
/* SetQuakeParam writes: +0x00=duration, +0x04=0, +0x08=vec1(u64+u32),*/
/*   +0x14=vec2(u64+u32), +0x20=param.                                */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint32_t duration;              /* +0x00 PRES */
    uint32_t elapsed;               /* +0x04 PRES */
    float    vec1[3];               /* +0x08 SIM Vector3 */
    float    vec2[3];               /* +0x14 SIM Vector3 */
    uint32_t param;                 /* +0x20 PRES */
} QuakeParamEntry;

static_assert(offsetof(QuakeParamEntry, duration) == 0x00, "QuakeParamEntry.duration");
static_assert(offsetof(QuakeParamEntry, elapsed) == 0x04, "QuakeParamEntry.elapsed");
static_assert(offsetof(QuakeParamEntry, vec1) == 0x08, "QuakeParamEntry.vec1");
static_assert(offsetof(QuakeParamEntry, vec2) == 0x14, "QuakeParamEntry.vec2");
static_assert(offsetof(QuakeParamEntry, param) == 0x20, "QuakeParamEntry.param");

/* ------------------------------------------------------------------ */
/* ccCmnCameraOperator — size >= 0x1B0                                 */
/* Embedded ccCmnCamera at +0x40 (after 0x40 ccTaskBase).             */
/* Quake system +0xE0..+0x170. Array at +0x104 (3×0x24).             */
/* Snapshot mirrors camera at +0x170..+0x194.                         */
/* Interp state +0x198/+0x19C. Ctor zeroes +0x1A4(u64), +0x1AC(u32). */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    void           *vtable;         /* +0x00 PTR_FUN_141115870 */
    uint8_t         taskBase[0x38]; /* +0x08 ccTaskBase to +0x40 */
    ccCmnCamera     camera;         /* +0x40 embedded, 0xA0 to +0xE0 */
    uint32_t        quakeDuration;  /* +0xE0 PRES */
    uint32_t        quakeIndex;     /* +0xE4 PRES */
    float           quakeVec1[3];   /* +0xE8 SIM fallback Vector3 */
    float           quakeVec2[3];   /* +0xF4 SIM fallback Vector3 */
    uint32_t        quakeIntensity; /* +0x100 PRES fallback param */
    QuakeParamEntry quakeArray[3];  /* +0x104, 3*0x24=0x6C, to +0x170 */
    /* Snapshot fields (UpdateCamera copies from camera): */
    uint64_t        snap_eyePos_xy; /* +0x170 from camera.eyePosition */
    uint32_t        snap_eyePos_z;  /* +0x178 from camera.eyePosition+8 */
    uint64_t        snap_lookAt_xy; /* +0x17C from camera.lookAtTarget */
    uint32_t        snap_lookAt_z;  /* +0x184 from camera.lookAtTarget+8 */
    uint64_t        snap_up_xy;     /* +0x188 from camera.upVector */
    uint32_t        snap_up_z;      /* +0x190 (=dec 400) from camera.upVector+8 */
    uint32_t        snap_flags;     /* +0x194 from camera.flags (+0x6C rel operator) */
    int32_t         interpActive;   /* +0x198 PRES, InterpView checks !=0 */
    float           interpAlpha;    /* +0x19C SIM, lerp factor, ctor=0x3dcccccd */
    uint64_t        field_1A0;      /* +0x1A0 UNKNOWN, ctor sets 0x42340000 as u64 */
    uint32_t        field_1A8;      /* +0x1A8 UNKNOWN, ctor sets 0x3e4ccccd (~0.2f) */
    uint32_t        activeFlag;     /* +0x1AC PRES, SetQuakeParam checks !=0, ctor=0 */
} ccCmnCameraOperator;

static_assert(offsetof(ccCmnCameraOperator, vtable) == 0x00, "ccCmnCameraOperator.vtable");
static_assert(offsetof(ccCmnCameraOperator, camera) == 0x40, "ccCmnCameraOperator.camera");
static_assert(offsetof(ccCmnCameraOperator, quakeDuration) == 0xE0, "ccCmnCameraOperator.quakeDuration");
static_assert(offsetof(ccCmnCameraOperator, quakeIndex) == 0xE4, "ccCmnCameraOperator.quakeIndex");
static_assert(offsetof(ccCmnCameraOperator, quakeVec1) == 0xE8, "ccCmnCameraOperator.quakeVec1");
static_assert(offsetof(ccCmnCameraOperator, quakeVec2) == 0xF4, "ccCmnCameraOperator.quakeVec2");
static_assert(offsetof(ccCmnCameraOperator, quakeIntensity) == 0x100, "ccCmnCameraOperator.quakeIntensity");
static_assert(offsetof(ccCmnCameraOperator, quakeArray) == 0x104, "ccCmnCameraOperator.quakeArray");
static_assert(offsetof(ccCmnCameraOperator, snap_eyePos_xy) == 0x170, "ccCmnCameraOperator.snap_eyePos_xy");
static_assert(offsetof(ccCmnCameraOperator, snap_eyePos_z) == 0x178, "ccCmnCameraOperator.snap_eyePos_z");
static_assert(offsetof(ccCmnCameraOperator, snap_lookAt_xy) == 0x17C, "ccCmnCameraOperator.snap_lookAt_xy");
static_assert(offsetof(ccCmnCameraOperator, snap_lookAt_z) == 0x184, "ccCmnCameraOperator.snap_lookAt_z");
static_assert(offsetof(ccCmnCameraOperator, snap_up_xy) == 0x188, "ccCmnCameraOperator.snap_up_xy");
static_assert(offsetof(ccCmnCameraOperator, snap_up_z) == 0x190, "ccCmnCameraOperator.snap_up_z");
static_assert(offsetof(ccCmnCameraOperator, snap_flags) == 0x194, "ccCmnCameraOperator.snap_flags");
static_assert(offsetof(ccCmnCameraOperator, interpActive) == 0x198, "ccCmnCameraOperator.interpActive");
static_assert(offsetof(ccCmnCameraOperator, interpAlpha) == 0x19C, "ccCmnCameraOperator.interpAlpha");
static_assert(offsetof(ccCmnCameraOperator, field_1A0) == 0x1A0, "ccCmnCameraOperator.field_1A0");
static_assert(offsetof(ccCmnCameraOperator, field_1A8) == 0x1A8, "ccCmnCameraOperator.field_1A8");
static_assert(offsetof(ccCmnCameraOperator, activeFlag) == 0x1AC, "ccCmnCameraOperator.activeFlag");

/* ------------------------------------------------------------------ */
/* ccApplication — size >= 0x335C (partial layout)                     */
/* param_1 is longlong* in decompile; [N] = byte offset N*8.          */
/* Embedded ccAppInitParam at +0x68 (param_1+0xd).                    */
/* Finalize@0x40C218 frees 8 ptrs starting at +0x331C.               */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    void           *vtable;         /* +0x00 */
    uint8_t         pad_08[0x10];   /* +0x08 */
    void           *field_18;       /* +0x18 PRES, alloc 0x60, freed Finalize */
    void           *field_20;       /* +0x20 PRES, alloc 0x48, freed Finalize */
    void           *sceneBootRoot;  /* +0x28 PRES, ccSceneBootRoot, freed Finalize */
    uint8_t         pad_30[0x38];   /* +0x30 */
    ccAppInitParam  initParam;      /* +0x68 embedded, FUN_140855458(param_1+0xd,0) */
    uint8_t         pad_88[0x10];   /* +0x88 gap: initParam ends at 0x88, next field at 0x98 */
    void           *field_98;       /* +0x98 PRES, param_1[0x13], freed Finalize */
    void           *field_A0;       /* +0xA0 PRES, param_1[0x14], freed Finalize */
    void           *field_A8;       /* +0xA8 PRES, param_1[0x15], freed Finalize */
    void           *field_B0;       /* +0xB0 PRES, param_1[0x16], freed Finalize */
    void           *field_B8;       /* +0xB8 PRES, param_1[0x17], freed Finalize */
    uint8_t         pad_C0[0x08];   /* +0xC0 */
    void           *field_C8;       /* +0xC8 PRES, param_1[0x19], alloc 0x78, freed */
    uint8_t         pad_D0[0x02];   /* +0xD0 */
    uint16_t        signoutDialogFlag; /* +0xD2 PRES, UnsetPushedSignoutDialogFlag writes u16 */
    uint32_t        interceptFlag;  /* +0xD4 PRES, IsIntercepted reads here */
    uint8_t         pad_D8[0x3244]; /* +0xD8 gap to +0x331C */
    void           *latePtrs[8];    /* +0x331C, 8 ptrs freed via vcall in Finalize@0x40C218 */
} ccApplication;

static_assert(offsetof(ccApplication, vtable) == 0x00, "ccApplication.vtable");
static_assert(offsetof(ccApplication, field_18) == 0x18, "ccApplication.field_18");
static_assert(offsetof(ccApplication, field_20) == 0x20, "ccApplication.field_20");
static_assert(offsetof(ccApplication, sceneBootRoot) == 0x28, "ccApplication.sceneBootRoot");
static_assert(offsetof(ccApplication, initParam) == 0x68, "ccApplication.initParam");
static_assert(offsetof(ccApplication, field_98) == 0x98, "ccApplication.field_98");
static_assert(offsetof(ccApplication, field_A0) == 0xA0, "ccApplication.field_A0");
static_assert(offsetof(ccApplication, field_A8) == 0xA8, "ccApplication.field_A8");
static_assert(offsetof(ccApplication, field_B0) == 0xB0, "ccApplication.field_B0");
static_assert(offsetof(ccApplication, field_B8) == 0xB8, "ccApplication.field_B8");
static_assert(offsetof(ccApplication, field_C8) == 0xC8, "ccApplication.field_C8");
static_assert(offsetof(ccApplication, signoutDialogFlag) == 0xD2, "ccApplication.signoutDialogFlag");
static_assert(offsetof(ccApplication, interceptFlag) == 0xD4, "ccApplication.interceptFlag");
static_assert(offsetof(ccApplication, latePtrs) == 0x331C, "ccApplication.latePtrs");

/* ------------------------------------------------------------------ */
/* bul::CCommandBuffer — size >= 0x130 (partial layout)                */
/* CallCommands: vtable-like deref at *(param_1+8).                    */
/* UpdateUniformBuffer: ptr shuffle at +0x18/+0x20/+0x28.             */
/* ResetReportCounter: ptr at +0x110, flag at +0x128.                  */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    void    *vtable;                /* +0x00 */
    void    *cmdDispatch;           /* +0x08 PRES, CallCommands derefs **(+0x08) */
    uint8_t  pad_10[0x08];          /* +0x10 */
    void    *ubCur;                 /* +0x18 PRES, UpdateUniformBuffer swaps */
    void    *ubPrev;                /* +0x20 PRES, UpdateUniformBuffer stores old */
    void    *ubNext;                /* +0x28 PRES, UpdateUniformBuffer zeroes */
    uint8_t  pad_30[0xE0];          /* +0x30 gap to +0x110 */
    void    *reportObj;             /* +0x110 PRES, ResetReportCounter vcall */
    uint8_t  pad_118[0x10];         /* +0x118 */
    void    *reportFlag;            /* +0x128 PRES, ResetReportCounter checks !=0 */
} bul_CCommandBuffer;

static_assert(offsetof(bul_CCommandBuffer, vtable) == 0x00, "bul_CCommandBuffer.vtable");
static_assert(offsetof(bul_CCommandBuffer, cmdDispatch) == 0x08, "bul_CCommandBuffer.cmdDispatch");
static_assert(offsetof(bul_CCommandBuffer, ubCur) == 0x18, "bul_CCommandBuffer.ubCur");
static_assert(offsetof(bul_CCommandBuffer, ubPrev) == 0x20, "bul_CCommandBuffer.ubPrev");
static_assert(offsetof(bul_CCommandBuffer, ubNext) == 0x28, "bul_CCommandBuffer.ubNext");
static_assert(offsetof(bul_CCommandBuffer, reportObj) == 0x110, "bul_CCommandBuffer.reportObj");
static_assert(offsetof(bul_CCommandBuffer, reportFlag) == 0x128, "bul_CCommandBuffer.reportFlag");

/* ccBltUtil: no instance state — ToNuccPos@0xA2D9F0, ToNuccRot@0xA2DA20, TobulletPos@0xA2DA60; state_surface=0 fields */
#endif /* CMN01_S4_H */