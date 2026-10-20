/*
 * cmn01.h — Common engine struct group for Storm 1 (s1, NSUNS1.exe x64)
 * Build: s1 (sha 10231093af9c)
 * All layouts INFERRED from static decompilation; no runtime confirmation.
 * Sizes are unproven unless noted; structs end at last proven field.
 * Own-game names only (Storm 1 / ns1:: / mobile / strings).
 */
#ifndef CMN01_S1_H
#define CMN01_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* ccAppInitParam                                                      */
/* Embedded in ccApplication at +0x3C (see Initialize).                */
/* Fields from ParseCamera (0x42C914) and ParseData (0x42CB0C).        */
/* ParseCamera writes float at param_1+8, +0xC, +0x10 and u32 at +0x14.*/
/* ParseData writes u32 at param_1+0 and param_1+4.                    */
/* Size unknown, >= 0x18.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAppInitParam {
    uint32_t readDrive;           /* 0x00: from ParseData "readDrive" (bool as u32) */
    uint32_t readCpk;             /* 0x04: from ParseData "readCpk" (bool as u32) */
    float    moveSpdScale;        /* 0x08: from ParseCamera "moveSpdScale" */
    float    approachSpdScaleInitial; /* 0x0C: from ParseCamera "approachSpdScaleInitial" */
    float    rotSpeed;            /* 0x10: from ParseCamera "rotSpeed" */
    uint32_t speedUp;             /* 0x14: from ParseCamera "speedUp" (bool as u32) */
} ccAppInitParam;

static_assert(offsetof(ccAppInitParam, readDrive) == 0x00, "ccAppInitParam.readDrive");
static_assert(offsetof(ccAppInitParam, readCpk) == 0x04, "ccAppInitParam.readCpk");
static_assert(offsetof(ccAppInitParam, moveSpdScale) == 0x08, "ccAppInitParam.moveSpdScale");
static_assert(offsetof(ccAppInitParam, approachSpdScaleInitial) == 0x0C, "ccAppInitParam.approachSpdScaleInitial");
static_assert(offsetof(ccAppInitParam, rotSpeed) == 0x10, "ccAppInitParam.rotSpeed");
static_assert(offsetof(ccAppInitParam, speedUp) == 0x14, "ccAppInitParam.speedUp");

/* ------------------------------------------------------------------ */
/* ccApplication                                                       */
/* Main application class. Fields from Initialize (0x42CF84),          */
/* Finalize (0x42CEAC), UnsetPushedSignoutDialogFlag (0x42D490).       */
/* Decompiler uses longlong* => param_1[N] = byte offset N*8.          */
/* param_1[4]=+0x20, [5]=+0x28, [6]=+0x30, [0xC]=+0x60, [0x12]=+0x90 */
/* *(param_1+0xBC)=byte +0xBC, *(param_1+7)=byte +0x38                 */
/* initParam embedded at (longlong)param_1+0x3C = byte +0x3C.          */
/* Size unknown, >= 0xE4.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccApplication {
    uint8_t  vtable[8];           /* 0x00: vtable ptr (vfunc+0x08, +0x10 called) */
    uint8_t  pad_08[0x18];        /* 0x08-0x1F: base class / padding */
    void    *fileLoadListUi;      /* 0x20: param_1[4], freed in Finalize */
    void    *partyPlayHosting;    /* 0x28: param_1[5], freed in Finalize */
    uint32_t field_30;            /* 0x30: param_1[6] set to 1 in Initialize */
    uint8_t  pad_34[0x04];        /* 0x34-0x37: gap */
    uint32_t signoutDialogFlag;   /* 0x38: *(param_1+7), cleared by Unset/Finalize */
    ccAppInitParam initParam;     /* 0x3C: embedded, passed to Parse */
    uint8_t  pad_54[0x0C];        /* 0x54-0x5F: gap */
    void    *pauseUpdateThread;   /* 0x60: param_1[0xC], thread handle */
    uint8_t  pad_68[0x28];        /* 0x68-0x8F: gap (param_1[0xD..0x11]) */
    void    *blockAllocator;      /* 0x90: param_1[0x12], Nucc::Memory::BlockAllocator */
    uint8_t  pad_98[0x24];        /* 0x98-0xBB: gap */
    uint32_t initMode;            /* 0xBC: set in Initialize, checked ==1 */
    uint8_t  pad_C0[0x24];        /* 0xC0-0xE3: trailing */
} ccApplication;

static_assert(offsetof(ccApplication, fileLoadListUi) == 0x20, "ccApplication.fileLoadListUi");
static_assert(offsetof(ccApplication, partyPlayHosting) == 0x28, "ccApplication.partyPlayHosting");
static_assert(offsetof(ccApplication, field_30) == 0x30, "ccApplication.field_30");
static_assert(offsetof(ccApplication, signoutDialogFlag) == 0x38, "ccApplication.signoutDialogFlag");
static_assert(offsetof(ccApplication, initParam) == 0x3C, "ccApplication.initParam");
static_assert(offsetof(ccApplication, pauseUpdateThread) == 0x60, "ccApplication.pauseUpdateThread");
static_assert(offsetof(ccApplication, blockAllocator) == 0x90, "ccApplication.blockAllocator");
static_assert(offsetof(ccApplication, initMode) == 0xBC, "ccApplication.initMode");

/* ------------------------------------------------------------------ */
/* ccBuildUniqueId                                                     */
/* Simple ID generator. Embedded at +0x7C in parent (FUN_140553b60).   */
/* Fields from ctor (0x577C80), GetId (0x577CD0), Reset (0x577CB0),   */
/* SetWrapAroundWarning (0x577CF0), SetWrapAroundHalt (0x577D00).      */
/* Size: >= 0x0C (last field at +0x08, 4 bytes).                       */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccBuildUniqueId {
    uint32_t wrapAroundWarning;   /* 0x00: set by SetWrapAroundWarning, reset to 1 in ctor/Reset */
    uint32_t wrapAroundHalt;      /* 0x04: set by SetWrapAroundHalt, reset to 0 in ctor/Reset */
    uint32_t counter;             /* 0x08: incremented by GetId, wraps to 1 on overflow */
} ccBuildUniqueId;

static_assert(offsetof(ccBuildUniqueId, wrapAroundWarning) == 0x00, "ccBuildUniqueId.wrapAroundWarning");
static_assert(offsetof(ccBuildUniqueId, wrapAroundHalt) == 0x04, "ccBuildUniqueId.wrapAroundHalt");
static_assert(offsetof(ccBuildUniqueId, counter) == 0x08, "ccBuildUniqueId.counter");

/* ------------------------------------------------------------------ */
/* ccCmnCamera                                                         */
/* Inherits nuccCamera (ctor calls nuccCamera::nuccCamera first).      */
/* Fields from Copy (0x5376E0) and Update (0x537650).                  */
/* nuccCamera base size unknown; ccCmnCamera own fields start at +0x2C.*/
/* Copy copies: +0x2C(u32), +0x30(Matrix44=0x40), then scattered.      */
/* Update reads Vector3 at +0x70, +0x7C, +0x88 and writes matrix +0x30.*/
/* Size unknown, >= 0xA0.                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccCmnCamera {
    uint8_t  nuccCamera_base[0x2C]; /* 0x00: nuccCamera base (size inferred) */
    uint32_t flags;               /* 0x2C: copied in Copy */
    uint8_t  viewMatrix[0x40];    /* 0x30: Nucc::Matrix44_MathGeo, written by Update */
    uint8_t  eyePosition[0x0C];   /* 0x70: Vector3, read by Update/TonuVECTOR3 */
    uint8_t  lookAtTarget[0x0C];  /* 0x7C: Vector3, read by Update/TonuVECTOR3 */
    uint8_t  upVector[0x0C];      /* 0x88: Vector3, read by Update/TonuVECTOR3 */
    uint32_t field_94;            /* 0x94: copied in Copy */
    uint8_t  field_98[0x08];      /* 0x98: copied in Copy (+0x94 as u64, +0x9C as u32) */
} ccCmnCamera;

static_assert(offsetof(ccCmnCamera, flags) == 0x2C, "ccCmnCamera.flags");
static_assert(offsetof(ccCmnCamera, viewMatrix) == 0x30, "ccCmnCamera.viewMatrix");
static_assert(offsetof(ccCmnCamera, eyePosition) == 0x70, "ccCmnCamera.eyePosition");
static_assert(offsetof(ccCmnCamera, lookAtTarget) == 0x7C, "ccCmnCamera.lookAtTarget");
static_assert(offsetof(ccCmnCamera, upVector) == 0x88, "ccCmnCamera.upVector");
static_assert(offsetof(ccCmnCamera, field_94) == 0x94, "ccCmnCamera.field_94");

/* ------------------------------------------------------------------ */
/* Classes with <3 methods (listed but not reconstructed):             */
/*   bul::CBuffer (1 method), bul::CCommandBuffer (2), bul::CDevice (1),*/
/*   bul::CShader (1), ccBltUtil (1), ccBulletCollisionContactResult (1),*/
/*   ccCmnCameraOperator (1)                                           */
/* ------------------------------------------------------------------ */

#endif /* CMN01_S1_H */