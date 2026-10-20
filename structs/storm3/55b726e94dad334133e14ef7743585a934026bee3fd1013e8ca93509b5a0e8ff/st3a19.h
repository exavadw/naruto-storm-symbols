#ifndef ST3A19_H
#define ST3A19_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Auto-generated from merged_fields.json — INFERRED, not CONFIRMED */
/* Build: s3 (NSUNS3.exe 64-bit, Storm 3 Full Burst HD PC) */
/* Overlapping fields from different decompile sources are deduplicated; */
/* pointer types demoted to integer when recorded sz != 8. */

/* ccUiAdvLetterBoxStateMachine */
typedef struct __attribute__((packed)) ccUiAdvLetterBoxStateMachine {
    uint8_t _pad_000[84];
    uint32_t field_054; /* offset 0x54 */
    uint8_t _pad_058[8];
    uint32_t field_060; /* offset 0x60 */
    uint8_t _pad_064[12];
    uint64_t* field_070; /* offset 0x70 */
    uint8_t _pad_078[632];
    int64_t* field_2f0; /* offset 0x2F0 */
    uint8_t _pad_2f8[88];
    uint32_t field_350; /* offset 0x350 */
} ccUiAdvLetterBoxStateMachine;

static_assert(offsetof(ccUiAdvLetterBoxStateMachine, field_054) == 0x54, "ccUiAdvLetterBoxStateMachine.field_054 offset");
static_assert(offsetof(ccUiAdvLetterBoxStateMachine, field_060) == 0x60, "ccUiAdvLetterBoxStateMachine.field_060 offset");
static_assert(offsetof(ccUiAdvLetterBoxStateMachine, field_070) == 0x70, "ccUiAdvLetterBoxStateMachine.field_070 offset");
static_assert(offsetof(ccUiAdvLetterBoxStateMachine, field_2f0) == 0x2F0, "ccUiAdvLetterBoxStateMachine.field_2f0 offset");
static_assert(offsetof(ccUiAdvLetterBoxStateMachine, field_350) == 0x350, "ccUiAdvLetterBoxStateMachine.field_350 offset");

/* ccUiAdvLetterDetail */
typedef struct __attribute__((packed)) ccUiAdvLetterDetail {
    uint8_t _pad_000[136];
    uint32_t field_088; /* offset 0x88 */
    uint32_t field_08c; /* offset 0x8C */
    uint8_t _pad_090[8];
    uint32_t field_098; /* offset 0x98 */
    uint8_t _pad_09c[20];
    uint32_t field_0b0; /* offset 0xB0 */
    uint8_t _pad_0b4[4];
    uint64_t* field_0b8; /* offset 0xB8 */
    int64_t* field_0c0; /* offset 0xC0 */
    uint8_t _pad_0c8[8];
    int64_t** field_0d0; /* offset 0xD0 */
    int64_t** field_0d8; /* offset 0xD8 */
    int64_t** field_0e0; /* offset 0xE0 */
    uint64_t* field_0e8; /* offset 0xE8 */
    int64_t* field_0f0; /* offset 0xF0 */
    int64_t* field_0f8; /* offset 0xF8 */
    uint32_t field_100; /* offset 0x100 */
    uint32_t field_104; /* offset 0x104 */
    uint32_t field_108; /* offset 0x108 */
    uint32_t field_10c; /* offset 0x10C */
    uint32_t field_110; /* offset 0x110 */
    uint32_t field_114; /* offset 0x114 */
    uint32_t field_118; /* offset 0x118 */
    uint32_t field_11c; /* offset 0x11C */
    uint32_t field_120; /* offset 0x120 */
    uint32_t field_124; /* offset 0x124 */
    uint32_t field_128; /* offset 0x128 */
    uint8_t _pad_12c[4];
    uint32_t field_130; /* offset 0x130 */
    uint8_t _pad_134[4];
    int64_t* field_138; /* offset 0x138 */
    int64_t* field_140; /* offset 0x140 */
    uint8_t _pad_148[36];
    uint32_t field_16c; /* offset 0x16C */
} ccUiAdvLetterDetail;

static_assert(offsetof(ccUiAdvLetterDetail, field_088) == 0x88, "ccUiAdvLetterDetail.field_088 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_08c) == 0x8C, "ccUiAdvLetterDetail.field_08c offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_098) == 0x98, "ccUiAdvLetterDetail.field_098 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0b0) == 0xB0, "ccUiAdvLetterDetail.field_0b0 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0b8) == 0xB8, "ccUiAdvLetterDetail.field_0b8 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0c0) == 0xC0, "ccUiAdvLetterDetail.field_0c0 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0d0) == 0xD0, "ccUiAdvLetterDetail.field_0d0 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0d8) == 0xD8, "ccUiAdvLetterDetail.field_0d8 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0e0) == 0xE0, "ccUiAdvLetterDetail.field_0e0 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0e8) == 0xE8, "ccUiAdvLetterDetail.field_0e8 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0f0) == 0xF0, "ccUiAdvLetterDetail.field_0f0 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_0f8) == 0xF8, "ccUiAdvLetterDetail.field_0f8 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_100) == 0x100, "ccUiAdvLetterDetail.field_100 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_104) == 0x104, "ccUiAdvLetterDetail.field_104 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_108) == 0x108, "ccUiAdvLetterDetail.field_108 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_10c) == 0x10C, "ccUiAdvLetterDetail.field_10c offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_110) == 0x110, "ccUiAdvLetterDetail.field_110 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_114) == 0x114, "ccUiAdvLetterDetail.field_114 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_118) == 0x118, "ccUiAdvLetterDetail.field_118 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_11c) == 0x11C, "ccUiAdvLetterDetail.field_11c offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_120) == 0x120, "ccUiAdvLetterDetail.field_120 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_124) == 0x124, "ccUiAdvLetterDetail.field_124 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_128) == 0x128, "ccUiAdvLetterDetail.field_128 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_130) == 0x130, "ccUiAdvLetterDetail.field_130 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_138) == 0x138, "ccUiAdvLetterDetail.field_138 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_140) == 0x140, "ccUiAdvLetterDetail.field_140 offset");
static_assert(offsetof(ccUiAdvLetterDetail, field_16c) == 0x16C, "ccUiAdvLetterDetail.field_16c offset");

/* ccUiAdvLetterDetailStateMachine */
typedef struct __attribute__((packed)) ccUiAdvLetterDetailStateMachine {
    uint8_t _pad_000[22];
    uint32_t field_016; /* offset 0x16 */
    uint8_t _pad_01a[12];
    uint32_t field_026; /* offset 0x26 */
    uint8_t _pad_02a[3];
    uint32_t field_02d; /* offset 0x2D */
    uint8_t _pad_031[35];
    uint32_t field_054; /* offset 0x54 */
    uint8_t _pad_058[8];
    uint32_t field_060; /* offset 0x60 */
    uint8_t _pad_064[12];
    uint64_t* field_070; /* offset 0x70 */
    uint8_t _pad_078[56];
    uint32_t field_0b0; /* offset 0xB0 */
    uint8_t _pad_0b4[4];
    uint64_t field_0b8; /* offset 0xB8 */
    uint64_t field_0c0; /* offset 0xC0 */
    uint64_t field_0c8; /* offset 0xC8 */
    uint64_t field_0d0; /* offset 0xD0 */
    uint64_t field_0d8; /* offset 0xD8 */
    uint64_t field_0e0; /* offset 0xE0 */
    uint64_t field_0e8; /* offset 0xE8 */
    uint64_t field_0f0; /* offset 0xF0 */
    uint64_t field_0f8; /* offset 0xF8 */
    uint64_t field_100; /* offset 0x100 */
    uint64_t field_108; /* offset 0x108 */
    uint64_t field_110; /* offset 0x110 */
    uint64_t field_118; /* offset 0x118 */
    uint64_t field_120; /* offset 0x120 */
    uint64_t field_128; /* offset 0x128 */
    uint32_t field_130; /* offset 0x130 */
    uint8_t _pad_134[4];
    uint64_t field_138; /* offset 0x138 */
    uint64_t field_140; /* offset 0x140 */
    uint64_t field_148; /* offset 0x148 */
    uint64_t field_150; /* offset 0x150 */
    uint8_t _pad_158[16];
    uint32_t field_168; /* offset 0x168 */
    uint32_t field_16c; /* offset 0x16C */
} ccUiAdvLetterDetailStateMachine;

static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_016) == 0x16, "ccUiAdvLetterDetailStateMachine.field_016 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_026) == 0x26, "ccUiAdvLetterDetailStateMachine.field_026 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_02d) == 0x2D, "ccUiAdvLetterDetailStateMachine.field_02d offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_054) == 0x54, "ccUiAdvLetterDetailStateMachine.field_054 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_060) == 0x60, "ccUiAdvLetterDetailStateMachine.field_060 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_070) == 0x70, "ccUiAdvLetterDetailStateMachine.field_070 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0b0) == 0xB0, "ccUiAdvLetterDetailStateMachine.field_0b0 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0b8) == 0xB8, "ccUiAdvLetterDetailStateMachine.field_0b8 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0c0) == 0xC0, "ccUiAdvLetterDetailStateMachine.field_0c0 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0c8) == 0xC8, "ccUiAdvLetterDetailStateMachine.field_0c8 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0d0) == 0xD0, "ccUiAdvLetterDetailStateMachine.field_0d0 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0d8) == 0xD8, "ccUiAdvLetterDetailStateMachine.field_0d8 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0e0) == 0xE0, "ccUiAdvLetterDetailStateMachine.field_0e0 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0e8) == 0xE8, "ccUiAdvLetterDetailStateMachine.field_0e8 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0f0) == 0xF0, "ccUiAdvLetterDetailStateMachine.field_0f0 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_0f8) == 0xF8, "ccUiAdvLetterDetailStateMachine.field_0f8 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_100) == 0x100, "ccUiAdvLetterDetailStateMachine.field_100 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_108) == 0x108, "ccUiAdvLetterDetailStateMachine.field_108 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_110) == 0x110, "ccUiAdvLetterDetailStateMachine.field_110 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_118) == 0x118, "ccUiAdvLetterDetailStateMachine.field_118 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_120) == 0x120, "ccUiAdvLetterDetailStateMachine.field_120 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_128) == 0x128, "ccUiAdvLetterDetailStateMachine.field_128 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_130) == 0x130, "ccUiAdvLetterDetailStateMachine.field_130 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_138) == 0x138, "ccUiAdvLetterDetailStateMachine.field_138 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_140) == 0x140, "ccUiAdvLetterDetailStateMachine.field_140 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_148) == 0x148, "ccUiAdvLetterDetailStateMachine.field_148 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_150) == 0x150, "ccUiAdvLetterDetailStateMachine.field_150 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_168) == 0x168, "ccUiAdvLetterDetailStateMachine.field_168 offset");
static_assert(offsetof(ccUiAdvLetterDetailStateMachine, field_16c) == 0x16C, "ccUiAdvLetterDetailStateMachine.field_16c offset");

/* ccUiAdvMiddleMap */
typedef struct __attribute__((packed)) ccUiAdvMiddleMap {
    uint8_t _pad_000[21];
    uint32_t field_015; /* offset 0x15 */
    uint8_t _pad_019[31];
    uint64_t* field_038; /* offset 0x38 */
    uint64_t* field_040; /* offset 0x40 */
    int64_t* field_048; /* offset 0x48 */
    int64_t* field_050; /* offset 0x50 */
    uint64_t field_058; /* offset 0x58 */
    uint64_t field_060; /* offset 0x60 */
    uint8_t _pad_068[64];
    uint32_t field_0a8; /* offset 0xA8 */
    uint32_t field_0ac; /* offset 0xAC */
    uint32_t field_0b0; /* offset 0xB0 */
} ccUiAdvMiddleMap;

/* ccUiAdvMiddleMap: skipped 2 overlapping/zero-size fields */

static_assert(offsetof(ccUiAdvMiddleMap, field_015) == 0x15, "ccUiAdvMiddleMap.field_015 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_038) == 0x38, "ccUiAdvMiddleMap.field_038 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_040) == 0x40, "ccUiAdvMiddleMap.field_040 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_048) == 0x48, "ccUiAdvMiddleMap.field_048 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_050) == 0x50, "ccUiAdvMiddleMap.field_050 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_058) == 0x58, "ccUiAdvMiddleMap.field_058 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_060) == 0x60, "ccUiAdvMiddleMap.field_060 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_0a8) == 0xA8, "ccUiAdvMiddleMap.field_0a8 offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_0ac) == 0xAC, "ccUiAdvMiddleMap.field_0ac offset");
static_assert(offsetof(ccUiAdvMiddleMap, field_0b0) == 0xB0, "ccUiAdvMiddleMap.field_0b0 offset");

/* ccUiAdvMiniMap */
typedef struct __attribute__((packed)) ccUiAdvMiniMap {
    uint8_t _pad_000[56];
    int64_t** field_038; /* offset 0x38 */
    int64_t* field_040; /* offset 0x40 */
    int64_t* field_048; /* offset 0x48 */
    uint64_t* field_050; /* offset 0x50 */
    uint64_t field_058; /* offset 0x58 */
    uint64_t field_060; /* offset 0x60 */
    uint64_t field_068; /* offset 0x68 */
    uint8_t _pad_070[16];
    uint64_t field_080; /* offset 0x80 */
    uint64_t field_088; /* offset 0x88 */
    uint64_t field_090; /* offset 0x90 */
    uint64_t field_098; /* offset 0x98 */
    uint8_t _pad_0a0[16];
    uint64_t field_0b0; /* offset 0xB0 */
    uint8_t _pad_0b8[104];
    uint64_t* field_120; /* offset 0x120 */
    uint32_t field_128; /* offset 0x128 */
    uint8_t _pad_12c[8];
    uint32_t field_134; /* offset 0x134 */
    uint64_t* field_138; /* offset 0x138 */
    uint32_t field_140; /* offset 0x140 */
    uint64_t* field_144; /* offset 0x144 */
    uint32_t field_14c; /* offset 0x14C */
    uint64_t* field_150; /* offset 0x150 */
    uint32_t field_158; /* offset 0x158 */
    uint64_t field_15c; /* offset 0x15C */
    uint64_t field_164; /* offset 0x164 */
    uint32_t field_16c; /* offset 0x16C */
    uint64_t* field_170; /* offset 0x170 */
    uint32_t field_178; /* offset 0x178 */
    uint64_t field_17c; /* offset 0x17C */
} ccUiAdvMiniMap;

/* ccUiAdvMiniMap: skipped 6 overlapping/zero-size fields */

static_assert(offsetof(ccUiAdvMiniMap, field_038) == 0x38, "ccUiAdvMiniMap.field_038 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_040) == 0x40, "ccUiAdvMiniMap.field_040 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_048) == 0x48, "ccUiAdvMiniMap.field_048 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_050) == 0x50, "ccUiAdvMiniMap.field_050 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_058) == 0x58, "ccUiAdvMiniMap.field_058 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_060) == 0x60, "ccUiAdvMiniMap.field_060 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_068) == 0x68, "ccUiAdvMiniMap.field_068 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_080) == 0x80, "ccUiAdvMiniMap.field_080 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_088) == 0x88, "ccUiAdvMiniMap.field_088 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_090) == 0x90, "ccUiAdvMiniMap.field_090 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_098) == 0x98, "ccUiAdvMiniMap.field_098 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_0b0) == 0xB0, "ccUiAdvMiniMap.field_0b0 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_120) == 0x120, "ccUiAdvMiniMap.field_120 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_128) == 0x128, "ccUiAdvMiniMap.field_128 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_134) == 0x134, "ccUiAdvMiniMap.field_134 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_138) == 0x138, "ccUiAdvMiniMap.field_138 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_140) == 0x140, "ccUiAdvMiniMap.field_140 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_144) == 0x144, "ccUiAdvMiniMap.field_144 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_14c) == 0x14C, "ccUiAdvMiniMap.field_14c offset");
static_assert(offsetof(ccUiAdvMiniMap, field_150) == 0x150, "ccUiAdvMiniMap.field_150 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_158) == 0x158, "ccUiAdvMiniMap.field_158 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_15c) == 0x15C, "ccUiAdvMiniMap.field_15c offset");
static_assert(offsetof(ccUiAdvMiniMap, field_164) == 0x164, "ccUiAdvMiniMap.field_164 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_16c) == 0x16C, "ccUiAdvMiniMap.field_16c offset");
static_assert(offsetof(ccUiAdvMiniMap, field_170) == 0x170, "ccUiAdvMiniMap.field_170 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_178) == 0x178, "ccUiAdvMiniMap.field_178 offset");
static_assert(offsetof(ccUiAdvMiniMap, field_17c) == 0x17C, "ccUiAdvMiniMap.field_17c offset");

/* ccUiAdvMission3dObject */
typedef struct __attribute__((packed)) ccUiAdvMission3dObject {
    uint8_t _pad_000[24];
    uint32_t field_018; /* offset 0x18 */
    uint8_t _pad_01c[28];
    uint64_t* field_038; /* offset 0x38 */
    uint8_t _pad_040[48];
    int64_t* field_070; /* offset 0x70 */
    uint8_t _pad_078[48];
    int64_t** field_0a8; /* offset 0xA8 */
    int64_t* field_0b0; /* offset 0xB0 */
    uint64_t* field_0b8; /* offset 0xB8 */
    uint32_t field_0c0; /* offset 0xC0 */
} ccUiAdvMission3dObject;

static_assert(offsetof(ccUiAdvMission3dObject, field_018) == 0x18, "ccUiAdvMission3dObject.field_018 offset");
static_assert(offsetof(ccUiAdvMission3dObject, field_038) == 0x38, "ccUiAdvMission3dObject.field_038 offset");
static_assert(offsetof(ccUiAdvMission3dObject, field_070) == 0x70, "ccUiAdvMission3dObject.field_070 offset");
static_assert(offsetof(ccUiAdvMission3dObject, field_0a8) == 0xA8, "ccUiAdvMission3dObject.field_0a8 offset");
static_assert(offsetof(ccUiAdvMission3dObject, field_0b0) == 0xB0, "ccUiAdvMission3dObject.field_0b0 offset");
static_assert(offsetof(ccUiAdvMission3dObject, field_0b8) == 0xB8, "ccUiAdvMission3dObject.field_0b8 offset");
static_assert(offsetof(ccUiAdvMission3dObject, field_0c0) == 0xC0, "ccUiAdvMission3dObject.field_0c0 offset");

/* ccUiAdvMissionOutline */
typedef struct __attribute__((packed)) ccUiAdvMissionOutline {
    uint8_t _pad_000[56];
    uint32_t field_038; /* offset 0x38 */
    uint8_t _pad_03c[4];
    uint64_t* field_040; /* offset 0x40 */
    int64_t* field_048; /* offset 0x48 */
} ccUiAdvMissionOutline;

static_assert(offsetof(ccUiAdvMissionOutline, field_038) == 0x38, "ccUiAdvMissionOutline.field_038 offset");
static_assert(offsetof(ccUiAdvMissionOutline, field_040) == 0x40, "ccUiAdvMissionOutline.field_040 offset");
static_assert(offsetof(ccUiAdvMissionOutline, field_048) == 0x48, "ccUiAdvMissionOutline.field_048 offset");

/* ccUiAdvMissionOutlineWindow */
typedef struct __attribute__((packed)) ccUiAdvMissionOutlineWindow {
    uint8_t _pad_000[19];
    uint32_t field_013; /* offset 0x13 */
    uint8_t _pad_017[5];
    uint32_t field_01c; /* offset 0x1C */
    uint8_t _pad_020[24];
    uint32_t field_038; /* offset 0x38 */
    uint32_t field_03c; /* offset 0x3C */
    int64_t* field_040; /* offset 0x40 */
    uint8_t _pad_048[8];
    uint32_t field_050; /* offset 0x50 */
    uint32_t field_054; /* offset 0x54 */
    uint64_t field_058; /* offset 0x58 */
    uint64_t field_060; /* offset 0x60 */
    uint64_t field_068; /* offset 0x68 */
    uint64_t field_070; /* offset 0x70 */
    uint64_t field_078; /* offset 0x78 */
    uint64_t field_080; /* offset 0x80 */
    uint64_t field_088; /* offset 0x88 */
    uint64_t field_090; /* offset 0x90 */
    uint32_t field_098; /* offset 0x98 */
    uint8_t _pad_09c[4];
    uint64_t field_0a0; /* offset 0xA0 */
    uint8_t _pad_0a8[24];
    uint64_t* field_0c0; /* offset 0xC0 */
    uint8_t _pad_0c8[24];
    uint32_t field_0e0; /* offset 0xE0 */
} ccUiAdvMissionOutlineWindow;

/* ccUiAdvMissionOutlineWindow: skipped 8 overlapping/zero-size fields */

static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_013) == 0x13, "ccUiAdvMissionOutlineWindow.field_013 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_01c) == 0x1C, "ccUiAdvMissionOutlineWindow.field_01c offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_038) == 0x38, "ccUiAdvMissionOutlineWindow.field_038 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_03c) == 0x3C, "ccUiAdvMissionOutlineWindow.field_03c offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_040) == 0x40, "ccUiAdvMissionOutlineWindow.field_040 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_050) == 0x50, "ccUiAdvMissionOutlineWindow.field_050 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_054) == 0x54, "ccUiAdvMissionOutlineWindow.field_054 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_058) == 0x58, "ccUiAdvMissionOutlineWindow.field_058 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_060) == 0x60, "ccUiAdvMissionOutlineWindow.field_060 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_068) == 0x68, "ccUiAdvMissionOutlineWindow.field_068 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_070) == 0x70, "ccUiAdvMissionOutlineWindow.field_070 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_078) == 0x78, "ccUiAdvMissionOutlineWindow.field_078 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_080) == 0x80, "ccUiAdvMissionOutlineWindow.field_080 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_088) == 0x88, "ccUiAdvMissionOutlineWindow.field_088 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_090) == 0x90, "ccUiAdvMissionOutlineWindow.field_090 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_098) == 0x98, "ccUiAdvMissionOutlineWindow.field_098 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_0a0) == 0xA0, "ccUiAdvMissionOutlineWindow.field_0a0 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_0c0) == 0xC0, "ccUiAdvMissionOutlineWindow.field_0c0 offset");
static_assert(offsetof(ccUiAdvMissionOutlineWindow, field_0e0) == 0xE0, "ccUiAdvMissionOutlineWindow.field_0e0 offset");

/* ccUiAdvMissionResult */
typedef struct __attribute__((packed)) ccUiAdvMissionResult {
    uint8_t _pad_000[14];
    uint32_t field_00e; /* offset 0xE */
    uint8_t _pad_012[5];
    uint32_t field_017; /* offset 0x17 */
    uint8_t _pad_01b[29];
    int64_t** field_038; /* offset 0x38 */
    uint32_t field_040; /* offset 0x40 */
    uint8_t _pad_044[4];
    uint64_t* field_048; /* offset 0x48 */
    int64_t** field_050; /* offset 0x50 */
    uint64_t field_058; /* offset 0x58 */
    uint64_t field_060; /* offset 0x60 */
    uint64_t field_068; /* offset 0x68 */
    uint32_t field_070; /* offset 0x70 */
    uint8_t _pad_074[4];
    uint64_t field_078; /* offset 0x78 */
    uint8_t _pad_080[24];
    uint64_t* field_098; /* offset 0x98 */
    uint8_t _pad_0a0[24];
    uint32_t field_0b8; /* offset 0xB8 */
    uint64_t field_0bc; /* offset 0xBC */
} ccUiAdvMissionResult;

/* ccUiAdvMissionResult: skipped 3 overlapping/zero-size fields */

static_assert(offsetof(ccUiAdvMissionResult, field_00e) == 0xE, "ccUiAdvMissionResult.field_00e offset");
static_assert(offsetof(ccUiAdvMissionResult, field_017) == 0x17, "ccUiAdvMissionResult.field_017 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_038) == 0x38, "ccUiAdvMissionResult.field_038 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_040) == 0x40, "ccUiAdvMissionResult.field_040 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_048) == 0x48, "ccUiAdvMissionResult.field_048 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_050) == 0x50, "ccUiAdvMissionResult.field_050 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_058) == 0x58, "ccUiAdvMissionResult.field_058 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_060) == 0x60, "ccUiAdvMissionResult.field_060 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_068) == 0x68, "ccUiAdvMissionResult.field_068 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_070) == 0x70, "ccUiAdvMissionResult.field_070 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_078) == 0x78, "ccUiAdvMissionResult.field_078 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_098) == 0x98, "ccUiAdvMissionResult.field_098 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_0b8) == 0xB8, "ccUiAdvMissionResult.field_0b8 offset");
static_assert(offsetof(ccUiAdvMissionResult, field_0bc) == 0xBC, "ccUiAdvMissionResult.field_0bc offset");

/* ccUiAdvMMIconList */
typedef struct __attribute__((packed)) ccUiAdvMMIconList {
    uint8_t _pad_000[68];
    uint32_t field_044; /* offset 0x44 */
    uint8_t _pad_048[24];
    int64_t* field_060; /* offset 0x60 */
    uint8_t _pad_068[72];
    uint64_t field_0b0; /* offset 0xB0 */
    uint8_t _pad_0b8[312];
    uint64_t field_1f0; /* offset 0x1F0 */
    uint64_t field_1f8; /* offset 0x1F8 */
    uint64_t field_200; /* offset 0x200 */
    uint64_t field_208; /* offset 0x208 */
    uint8_t _pad_210[16];
    uint32_t field_220; /* offset 0x220 */
} ccUiAdvMMIconList;

/* ccUiAdvMMIconList: skipped 1 overlapping/zero-size fields */

static_assert(offsetof(ccUiAdvMMIconList, field_044) == 0x44, "ccUiAdvMMIconList.field_044 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_060) == 0x60, "ccUiAdvMMIconList.field_060 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_0b0) == 0xB0, "ccUiAdvMMIconList.field_0b0 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_1f0) == 0x1F0, "ccUiAdvMMIconList.field_1f0 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_1f8) == 0x1F8, "ccUiAdvMMIconList.field_1f8 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_200) == 0x200, "ccUiAdvMMIconList.field_200 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_208) == 0x208, "ccUiAdvMMIconList.field_208 offset");
static_assert(offsetof(ccUiAdvMMIconList, field_220) == 0x220, "ccUiAdvMMIconList.field_220 offset");

/* ccUiAdvPickupItemBar */
typedef struct __attribute__((packed)) ccUiAdvPickupItemBar {
    uint8_t _pad_000[11];
    uint32_t field_00b; /* offset 0xB */
    uint8_t _pad_00f[41];
    uint64_t* field_038; /* offset 0x38 */
    uint32_t field_040; /* offset 0x40 */
    uint32_t field_044; /* offset 0x44 */
    uint32_t field_048; /* offset 0x48 */
    uint8_t _pad_04c[4];
    uint64_t* field_050; /* offset 0x50 */
    uint32_t field_058; /* offset 0x58 */
} ccUiAdvPickupItemBar;

static_assert(offsetof(ccUiAdvPickupItemBar, field_00b) == 0xB, "ccUiAdvPickupItemBar.field_00b offset");
static_assert(offsetof(ccUiAdvPickupItemBar, field_038) == 0x38, "ccUiAdvPickupItemBar.field_038 offset");
static_assert(offsetof(ccUiAdvPickupItemBar, field_040) == 0x40, "ccUiAdvPickupItemBar.field_040 offset");
static_assert(offsetof(ccUiAdvPickupItemBar, field_044) == 0x44, "ccUiAdvPickupItemBar.field_044 offset");
static_assert(offsetof(ccUiAdvPickupItemBar, field_048) == 0x48, "ccUiAdvPickupItemBar.field_048 offset");
static_assert(offsetof(ccUiAdvPickupItemBar, field_050) == 0x50, "ccUiAdvPickupItemBar.field_050 offset");
static_assert(offsetof(ccUiAdvPickupItemBar, field_058) == 0x58, "ccUiAdvPickupItemBar.field_058 offset");

/* ccUiAdvPlayerGauge */
typedef struct __attribute__((packed)) ccUiAdvPlayerGauge {
    uint8_t _pad_000[16];
    uint32_t field_010; /* offset 0x10 */
    uint8_t _pad_014[100];
    uint64_t field_078; /* offset 0x78 */
    uint32_t field_080; /* offset 0x80 */
    uint64_t field_084; /* offset 0x84 */
    uint64_t field_08c; /* offset 0x8C */
    uint32_t field_094; /* offset 0x94 */
    uint32_t field_098; /* offset 0x98 */
    uint32_t field_09c; /* offset 0x9C */
    uint32_t field_0a0; /* offset 0xA0 */
    uint32_t field_0a4; /* offset 0xA4 */
} ccUiAdvPlayerGauge;

/* ccUiAdvPlayerGauge: skipped 2 overlapping/zero-size fields */

static_assert(offsetof(ccUiAdvPlayerGauge, field_010) == 0x10, "ccUiAdvPlayerGauge.field_010 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_078) == 0x78, "ccUiAdvPlayerGauge.field_078 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_080) == 0x80, "ccUiAdvPlayerGauge.field_080 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_084) == 0x84, "ccUiAdvPlayerGauge.field_084 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_08c) == 0x8C, "ccUiAdvPlayerGauge.field_08c offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_094) == 0x94, "ccUiAdvPlayerGauge.field_094 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_098) == 0x98, "ccUiAdvPlayerGauge.field_098 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_09c) == 0x9C, "ccUiAdvPlayerGauge.field_09c offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_0a0) == 0xA0, "ccUiAdvPlayerGauge.field_0a0 offset");
static_assert(offsetof(ccUiAdvPlayerGauge, field_0a4) == 0xA4, "ccUiAdvPlayerGauge.field_0a4 offset");

#endif /* ST3A19_H */
