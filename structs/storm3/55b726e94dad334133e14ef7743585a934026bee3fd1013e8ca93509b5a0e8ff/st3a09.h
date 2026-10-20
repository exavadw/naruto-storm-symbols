/* st3a09.h - Storm 3 (NSUNS3.exe) adventure-mode class layouts
 * Generated from the decompiler cache state_surface analysis, build s3/st3a09.
 * All layouts are INFERRED (static analysis only), not CONFIRMED at runtime.
 * Object sizes are unproven unless noted; structs end at last known field.
 */
#ifndef ST3A09_H
#define ST3A09_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccAdvCalcCameraPos: no instance state (6 methods, stateless or param_1 typing failed) */

/* ccAdvCameraCtrl: no instance state (5 methods, stateless or param_1 typing failed) */

/* ccAdvCameraState: 15 fields, size unknown >= 0xD8 */
struct __attribute__((packed)) ccAdvCameraState {
    uint8_t _pad_0x00[84];
    uint64_t field_0x54; /* 0x54, 8B, w */
    uint32_t field_0x5C; /* 0x5C, 4B, w */
    uint32_t field_0x60; /* 0x60, 4B, w */
    uint8_t _pad_0x64[4];
    uint64_t field_0x68; /* 0x68, 8B, w */
    uint64_t field_0x70; /* 0x70, 8B, w */
    uint64_t field_0x78; /* 0x78, 8B, w */
    uint8_t field_0x80[8]; /* 0x80, size unproven, r */
    uint8_t _pad_0x88[16];
    uint64_t field_0x98; /* 0x98, 8B, w */
    uint32_t field_0xA0; /* 0xA0, 4B, w */
    uint32_t field_0xA4; /* 0xA4, 4B, w */
    uint64_t field_0xA8; /* 0xA8, 8B, w */
    uint8_t field_0xB0[8]; /* 0xB0, size unproven, r */
    uint8_t _pad_0xB8[4];
    uint8_t field_0xBC[8]; /* 0xBC, size unproven, r */
    uint8_t _pad_0xC4[4];
    uint64_t field_0xC8; /* 0xC8, 8B, w */
    uint64_t field_0xD0; /* 0xD0, 8B, w */
};

static_assert(offsetof(struct ccAdvCameraState, field_0x54) == 0x54, "ccAdvCameraState.field_0x54 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x5C) == 0x5C, "ccAdvCameraState.field_0x5C offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x60) == 0x60, "ccAdvCameraState.field_0x60 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x68) == 0x68, "ccAdvCameraState.field_0x68 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x70) == 0x70, "ccAdvCameraState.field_0x70 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x78) == 0x78, "ccAdvCameraState.field_0x78 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x80) == 0x80, "ccAdvCameraState.field_0x80 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0x98) == 0x98, "ccAdvCameraState.field_0x98 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xA0) == 0xA0, "ccAdvCameraState.field_0xA0 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xA4) == 0xA4, "ccAdvCameraState.field_0xA4 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xA8) == 0xA8, "ccAdvCameraState.field_0xA8 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xB0) == 0xB0, "ccAdvCameraState.field_0xB0 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xBC) == 0xBC, "ccAdvCameraState.field_0xBC offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xC8) == 0xC8, "ccAdvCameraState.field_0xC8 offset");
static_assert(offsetof(struct ccAdvCameraState, field_0xD0) == 0xD0, "ccAdvCameraState.field_0xD0 offset");

/* ccAdvChangeStageBoard: 7 fields, size unknown >= 0x124 */
struct __attribute__((packed)) ccAdvChangeStageBoard {
    uint8_t _pad_0x00[136];
    uint8_t field_0x88[8]; /* 0x88, size unproven, r */
    uint8_t _pad_0x90[48];
    uint8_t field_0xC0[8]; /* 0xC0, size unproven, r */
    uint8_t _pad_0xC8[48];
    uint8_t field_0xF8[8]; /* 0xF8, size unproven, r */
    uint8_t _pad_0x100[16];
    uint32_t field_0x110; /* 0x110, 4B, rw */
    uint32_t field_0x114; /* 0x114, 4B, rw */
    uint64_t field_0x118; /* 0x118, 8B, w */
    uint32_t field_0x120; /* 0x120, 4B, w */
};

static_assert(offsetof(struct ccAdvChangeStageBoard, field_0x88) == 0x88, "ccAdvChangeStageBoard.field_0x88 offset");
static_assert(offsetof(struct ccAdvChangeStageBoard, field_0xC0) == 0xC0, "ccAdvChangeStageBoard.field_0xC0 offset");
static_assert(offsetof(struct ccAdvChangeStageBoard, field_0xF8) == 0xF8, "ccAdvChangeStageBoard.field_0xF8 offset");
static_assert(offsetof(struct ccAdvChangeStageBoard, field_0x110) == 0x110, "ccAdvChangeStageBoard.field_0x110 offset");
static_assert(offsetof(struct ccAdvChangeStageBoard, field_0x114) == 0x114, "ccAdvChangeStageBoard.field_0x114 offset");
static_assert(offsetof(struct ccAdvChangeStageBoard, field_0x118) == 0x118, "ccAdvChangeStageBoard.field_0x118 offset");
static_assert(offsetof(struct ccAdvChangeStageBoard, field_0x120) == 0x120, "ccAdvChangeStageBoard.field_0x120 offset");

/* ccAdvCharaCmnParam: 8 fields, size unknown >= 0xF4 */
struct __attribute__((packed)) ccAdvCharaCmnParam {
    uint8_t _pad_0x00[144];
    uint32_t field_0x90; /* 0x90, 4B, w */
    uint32_t field_0x94; /* 0x94, 4B, w */
    uint32_t field_0x98; /* 0x98, 4B, w */
    uint8_t _pad_0x9C[4];
    uint8_t field_0xA0[8]; /* 0xA0, size unproven, r */
    uint8_t _pad_0xA8[48];
    uint64_t field_0xD8; /* 0xD8, 8B, rw */
    uint64_t field_0xE0; /* 0xE0, 8B, w */
    uint64_t field_0xE8; /* 0xE8, 8B, rw */
    uint32_t field_0xF0; /* 0xF0, 4B, w */
};

static_assert(offsetof(struct ccAdvCharaCmnParam, field_0x90) == 0x90, "ccAdvCharaCmnParam.field_0x90 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0x94) == 0x94, "ccAdvCharaCmnParam.field_0x94 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0x98) == 0x98, "ccAdvCharaCmnParam.field_0x98 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0xA0) == 0xA0, "ccAdvCharaCmnParam.field_0xA0 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0xD8) == 0xD8, "ccAdvCharaCmnParam.field_0xD8 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0xE0) == 0xE0, "ccAdvCharaCmnParam.field_0xE0 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0xE8) == 0xE8, "ccAdvCharaCmnParam.field_0xE8 offset");
static_assert(offsetof(struct ccAdvCharaCmnParam, field_0xF0) == 0xF0, "ccAdvCharaCmnParam.field_0xF0 offset");

/* ccAdvCharaDraw: no instance state (4 methods, stateless or param_1 typing failed) */

/* ccAdvCharaLoadState: no instance state (9 methods, stateless or param_1 typing failed) */

/* ccAdvCharaParam: 23 fields, size unknown >= 0x19F8 */
struct __attribute__((packed)) ccAdvCharaParam {
    uint8_t _pad_0x00[12];
    uint32_t field_0x0C; /* 0xC, 4B, w */
    uint8_t _pad_0x10[12];
    uint8_t field_0x1C[8]; /* 0x1C, size unproven, r */
    uint8_t _pad_0x24[16];
    uint32_t field_0x34; /* 0x34, 4B, w */
    uint8_t _pad_0x38[4];
    uint32_t field_0x3C; /* 0x3C, 4B, w */
    uint8_t _pad_0x40[24];
    uint64_t field_0x58; /* 0x58, 8B, rw */
    uint64_t field_0x60; /* 0x60, 8B, rw */
    uint8_t _pad_0x68[16];
    uint32_t field_0x78; /* 0x78, 4B, w */
    uint32_t field_0x7C; /* 0x7C, 4B, w */
    uint32_t field_0x80; /* 0x80, 4B, w */
    uint32_t field_0x84; /* 0x84, 4B, w */
    uint32_t field_0x88; /* 0x88, 4B, w */
    uint8_t _pad_0x8C[4];
    uint8_t field_0x90[8]; /* 0x90, size unproven, r */
    uint8_t _pad_0x98[40];
    uint8_t field_0xC0[8]; /* 0xC0, size unproven, r */
    uint8_t _pad_0xC8[1368];
    uint8_t field_0x620[8]; /* 0x620, size unproven, r */
    uint8_t _pad_0x628[1416];
    uint8_t field_0xBB0[8]; /* 0xBB0, size unproven, r */
    uint8_t _pad_0xBB8[1416];
    uint64_t field_0x1140; /* 0x1140, 8B, w */
    uint8_t field_0x1148[8]; /* 0x1148, size unproven, r */
    uint8_t _pad_0x1150[1416];
    uint64_t field_0x16D8; /* 0x16D8, 8B, w */
    uint64_t field_0x16E0; /* 0x16E0, 8B, w */
    uint64_t field_0x16E8; /* 0x16E8, 8B, w */
    uint32_t field_0x16F0; /* 0x16F0, 4B, w */
    uint8_t field_0x16F4[8]; /* 0x16F4, size unproven, r */
    uint8_t _pad_0x16FC[760];
    uint32_t field_0x19F4; /* 0x19F4, 4B, w */
};

static_assert(offsetof(struct ccAdvCharaParam, field_0x0C) == 0xC, "ccAdvCharaParam.field_0x0C offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x1C) == 0x1C, "ccAdvCharaParam.field_0x1C offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x34) == 0x34, "ccAdvCharaParam.field_0x34 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x3C) == 0x3C, "ccAdvCharaParam.field_0x3C offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x58) == 0x58, "ccAdvCharaParam.field_0x58 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x60) == 0x60, "ccAdvCharaParam.field_0x60 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x78) == 0x78, "ccAdvCharaParam.field_0x78 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x7C) == 0x7C, "ccAdvCharaParam.field_0x7C offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x80) == 0x80, "ccAdvCharaParam.field_0x80 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x84) == 0x84, "ccAdvCharaParam.field_0x84 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x88) == 0x88, "ccAdvCharaParam.field_0x88 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x90) == 0x90, "ccAdvCharaParam.field_0x90 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0xC0) == 0xC0, "ccAdvCharaParam.field_0xC0 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x620) == 0x620, "ccAdvCharaParam.field_0x620 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0xBB0) == 0xBB0, "ccAdvCharaParam.field_0xBB0 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x1140) == 0x1140, "ccAdvCharaParam.field_0x1140 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x1148) == 0x1148, "ccAdvCharaParam.field_0x1148 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x16D8) == 0x16D8, "ccAdvCharaParam.field_0x16D8 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x16E0) == 0x16E0, "ccAdvCharaParam.field_0x16E0 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x16E8) == 0x16E8, "ccAdvCharaParam.field_0x16E8 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x16F0) == 0x16F0, "ccAdvCharaParam.field_0x16F0 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x16F4) == 0x16F4, "ccAdvCharaParam.field_0x16F4 offset");
static_assert(offsetof(struct ccAdvCharaParam, field_0x19F4) == 0x19F4, "ccAdvCharaParam.field_0x19F4 offset");

/* ccAdvCharaState: 38 fields, size unknown >= 0x1B8 */
struct __attribute__((packed)) ccAdvCharaState {
    uint8_t _pad_0x00[84];
    uint64_t field_0x54; /* 0x54, 8B, w */
    uint32_t field_0x5C; /* 0x5C, 4B, w */
    uint32_t field_0x60; /* 0x60, 4B, w */
    uint8_t _pad_0x64[4];
    uint64_t field_0x68; /* 0x68, 8B, w */
    uint8_t field_0x70[8]; /* 0x70, size unproven, r */
    uint8_t _pad_0x78[8];
    uint64_t field_0x80; /* 0x80, 8B, w */
    uint64_t field_0x88; /* 0x88, 8B, w */
    uint64_t field_0x90; /* 0x90, 8B, w */
    uint64_t field_0x98; /* 0x98, 8B, w */
    uint64_t field_0xA0; /* 0xA0, 8B, w */
    uint8_t field_0xA8[8]; /* 0xA8, size unproven, r */
    uint8_t _pad_0xB0[4];
    uint8_t field_0xB4[8]; /* 0xB4, size unproven, r */
    uint8_t _pad_0xBC[4];
    uint64_t field_0xC0; /* 0xC0, 8B, w */
    uint64_t field_0xC8; /* 0xC8, 8B, w */
    uint64_t field_0xD0; /* 0xD0, 8B, w */
    uint32_t field_0xD8; /* 0xD8, 4B, w */
    uint32_t field_0xDC; /* 0xDC, 4B, w */
    uint8_t field_0xE0[8]; /* 0xE0, size unproven, r */
    uint8_t _pad_0xE8[4];
    uint8_t field_0xEC[8]; /* 0xEC, size unproven, r */
    uint8_t _pad_0xF4[4];
    uint8_t field_0xF8[8]; /* 0xF8, size unproven, r */
    uint8_t _pad_0x100[4];
    uint8_t field_0x104[8]; /* 0x104, size unproven, r */
    uint8_t _pad_0x10C[4];
    uint32_t field_0x110; /* 0x110, 4B, w */
    uint8_t field_0x114[8]; /* 0x114, size unproven, r */
    uint8_t _pad_0x11C[4];
    uint8_t field_0x120[8]; /* 0x120, size unproven, r */
    uint64_t field_0x128; /* 0x128, 8B, w */
    uint64_t field_0x130; /* 0x130, 8B, rw */
    uint64_t field_0x138; /* 0x138, 8B, rw */
    uint8_t _pad_0x140[16];
    uint8_t field_0x150[8]; /* 0x150, size unproven, r */
    uint64_t field_0x158; /* 0x158, 8B, w */
    uint64_t field_0x160; /* 0x160, 8B, rw */
    uint64_t field_0x168; /* 0x168, 8B, rw */
    uint8_t _pad_0x170[16];
    uint64_t field_0x180; /* 0x180, 8B, w */
    uint64_t field_0x188; /* 0x188, 8B, w */
    uint64_t field_0x190; /* 0x190, 8B, w */
    uint32_t field_0x198; /* 0x198, 4B, w */
    uint8_t _pad_0x19C[4];
    uint64_t field_0x1A0; /* 0x1A0, 8B, w */
    uint64_t field_0x1A8; /* 0x1A8, 8B, w */
    uint64_t field_0x1B0; /* 0x1B0, 8B, w */
};

static_assert(offsetof(struct ccAdvCharaState, field_0x54) == 0x54, "ccAdvCharaState.field_0x54 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x5C) == 0x5C, "ccAdvCharaState.field_0x5C offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x60) == 0x60, "ccAdvCharaState.field_0x60 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x68) == 0x68, "ccAdvCharaState.field_0x68 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x70) == 0x70, "ccAdvCharaState.field_0x70 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x80) == 0x80, "ccAdvCharaState.field_0x80 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x88) == 0x88, "ccAdvCharaState.field_0x88 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x90) == 0x90, "ccAdvCharaState.field_0x90 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x98) == 0x98, "ccAdvCharaState.field_0x98 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xA0) == 0xA0, "ccAdvCharaState.field_0xA0 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xA8) == 0xA8, "ccAdvCharaState.field_0xA8 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xB4) == 0xB4, "ccAdvCharaState.field_0xB4 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xC0) == 0xC0, "ccAdvCharaState.field_0xC0 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xC8) == 0xC8, "ccAdvCharaState.field_0xC8 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xD0) == 0xD0, "ccAdvCharaState.field_0xD0 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xD8) == 0xD8, "ccAdvCharaState.field_0xD8 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xDC) == 0xDC, "ccAdvCharaState.field_0xDC offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xE0) == 0xE0, "ccAdvCharaState.field_0xE0 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xEC) == 0xEC, "ccAdvCharaState.field_0xEC offset");
static_assert(offsetof(struct ccAdvCharaState, field_0xF8) == 0xF8, "ccAdvCharaState.field_0xF8 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x104) == 0x104, "ccAdvCharaState.field_0x104 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x110) == 0x110, "ccAdvCharaState.field_0x110 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x114) == 0x114, "ccAdvCharaState.field_0x114 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x120) == 0x120, "ccAdvCharaState.field_0x120 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x128) == 0x128, "ccAdvCharaState.field_0x128 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x130) == 0x130, "ccAdvCharaState.field_0x130 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x138) == 0x138, "ccAdvCharaState.field_0x138 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x150) == 0x150, "ccAdvCharaState.field_0x150 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x158) == 0x158, "ccAdvCharaState.field_0x158 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x160) == 0x160, "ccAdvCharaState.field_0x160 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x168) == 0x168, "ccAdvCharaState.field_0x168 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x180) == 0x180, "ccAdvCharaState.field_0x180 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x188) == 0x188, "ccAdvCharaState.field_0x188 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x190) == 0x190, "ccAdvCharaState.field_0x190 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x198) == 0x198, "ccAdvCharaState.field_0x198 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x1A0) == 0x1A0, "ccAdvCharaState.field_0x1A0 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x1A8) == 0x1A8, "ccAdvCharaState.field_0x1A8 offset");
static_assert(offsetof(struct ccAdvCharaState, field_0x1B0) == 0x1B0, "ccAdvCharaState.field_0x1B0 offset");

/* ccAdvCtrl: 1 fields, size unknown >= 0x80 */
struct __attribute__((packed)) ccAdvCtrl {
    uint8_t _pad_0x00[120];
    uint64_t field_0x78; /* 0x78, 8B, rw */
};

static_assert(offsetof(struct ccAdvCtrl, field_0x78) == 0x78, "ccAdvCtrl.field_0x78 offset");

/* Missing from surf data: ccAdvCamera, ccAdvCamera_LookAt, ccAdvCheckPointData, ccAdvCollisionResultList */

#endif /* ST3A09_H */
