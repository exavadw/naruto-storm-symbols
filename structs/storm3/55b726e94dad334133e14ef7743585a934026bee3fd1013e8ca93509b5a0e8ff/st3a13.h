/* st3a13.h — Story progression structs for NSUNS3.exe (s3, 64-bit)
 * Generated from the decompiler cache state_surface analysis.
 * All layouts are INFERRED from static decompilation, not CONFIRMED at runtime.
 * Sizes marked "unknown" where no operator new / allocator proof exists.
 */
#ifndef ST3A13_H
#define ST3A13_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccAdvScreenEffect — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvScreenEffect {
    uint8_t _pad_0000[288];
    uint8_t field_0120[256];
    uint8_t field_0220[384];
    uint8_t field_03a0[256];
    uint8_t field_04a0[288];
    uint8_t field_05c0[216];
    uint8_t field_0698[208];
    uint8_t field_0768[64];
} ccAdvScreenEffect;

static_assert(offsetof(ccAdvScreenEffect, field_0120) == 0x120, "ccAdvScreenEffect::field_0120 offset mismatch");
static_assert(offsetof(ccAdvScreenEffect, field_0220) == 0x220, "ccAdvScreenEffect::field_0220 offset mismatch");
static_assert(offsetof(ccAdvScreenEffect, field_03a0) == 0x3A0, "ccAdvScreenEffect::field_03a0 offset mismatch");
static_assert(offsetof(ccAdvScreenEffect, field_04a0) == 0x4A0, "ccAdvScreenEffect::field_04a0 offset mismatch");
static_assert(offsetof(ccAdvScreenEffect, field_05c0) == 0x5C0, "ccAdvScreenEffect::field_05c0 offset mismatch");
static_assert(offsetof(ccAdvScreenEffect, field_0698) == 0x698, "ccAdvScreenEffect::field_0698 offset mismatch");
static_assert(offsetof(ccAdvScreenEffect, field_0768) == 0x768, "ccAdvScreenEffect::field_0768 offset mismatch");

/* ccAdvStageLoadState — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvStageLoadState {
    uint8_t _pad_0000[84];
    uint32_t field_0054;
    uint32_t field_0058;
    uint32_t field_005c;
    uint32_t field_0060;
    uint8_t _pad_0064[4];
    uint32_t field_0068;
    uint32_t field_006c;
    uint64_t field_0070;
    uint8_t field_0078[56];
    uint8_t field_00b0[464];
    uint32_t field_0280;
    uint32_t field_0284;
    uint32_t field_0288;
    uint32_t field_028c;
} ccAdvStageLoadState;

static_assert(offsetof(ccAdvStageLoadState, field_0054) == 0x54, "ccAdvStageLoadState::field_0054 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0058) == 0x58, "ccAdvStageLoadState::field_0058 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_005c) == 0x5C, "ccAdvStageLoadState::field_005c offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0060) == 0x60, "ccAdvStageLoadState::field_0060 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0068) == 0x68, "ccAdvStageLoadState::field_0068 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_006c) == 0x6C, "ccAdvStageLoadState::field_006c offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0070) == 0x70, "ccAdvStageLoadState::field_0070 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0078) == 0x78, "ccAdvStageLoadState::field_0078 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_00b0) == 0xB0, "ccAdvStageLoadState::field_00b0 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0280) == 0x280, "ccAdvStageLoadState::field_0280 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0284) == 0x284, "ccAdvStageLoadState::field_0284 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_0288) == 0x288, "ccAdvStageLoadState::field_0288 offset mismatch");
static_assert(offsetof(ccAdvStageLoadState, field_028c) == 0x28C, "ccAdvStageLoadState::field_028c offset mismatch");

/* ccAdvStageParam — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvStageParam {
    uint8_t _pad_0000[88];
    uint64_t field_0058;
    uint64_t field_0060;
    uint8_t field_0068[8];
    uint8_t field_0070[16];
    uint64_t field_0080;
    uint64_t field_0088;
    uint64_t field_0090;
    uint8_t _pad_0098[8];
    uint8_t field_00a0[8];
    uint8_t field_00a8[16];
    uint64_t field_00b8;
    uint64_t field_00c0;
    uint8_t _pad_00c8[8];
    uint8_t field_00d0[24];
    uint8_t field_00e8[80];
    uint64_t field_0138;
    uint64_t field_0140;
    uint8_t _pad_0148[56];
    uint8_t field_0180[64];
    uint64_t field_01c0;
} ccAdvStageParam;

static_assert(offsetof(ccAdvStageParam, field_0058) == 0x58, "ccAdvStageParam::field_0058 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0060) == 0x60, "ccAdvStageParam::field_0060 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0068) == 0x68, "ccAdvStageParam::field_0068 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0070) == 0x70, "ccAdvStageParam::field_0070 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0080) == 0x80, "ccAdvStageParam::field_0080 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0088) == 0x88, "ccAdvStageParam::field_0088 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0090) == 0x90, "ccAdvStageParam::field_0090 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_00a0) == 0xA0, "ccAdvStageParam::field_00a0 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_00a8) == 0xA8, "ccAdvStageParam::field_00a8 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_00b8) == 0xB8, "ccAdvStageParam::field_00b8 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_00c0) == 0xC0, "ccAdvStageParam::field_00c0 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_00d0) == 0xD0, "ccAdvStageParam::field_00d0 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_00e8) == 0xE8, "ccAdvStageParam::field_00e8 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0138) == 0x138, "ccAdvStageParam::field_0138 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0140) == 0x140, "ccAdvStageParam::field_0140 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_0180) == 0x180, "ccAdvStageParam::field_0180 offset mismatch");
static_assert(offsetof(ccAdvStageParam, field_01c0) == 0x1C0, "ccAdvStageParam::field_01c0 offset mismatch");

/* ccAdvSupportParam — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvSupportParam {
    uint8_t _pad_0000[20];
    uint32_t field_0014;
    uint8_t _pad_0018[12];
    uint8_t field_0024[2084];
    uint8_t field_0848[1424];
    uint64_t field_0dd8;
    uint8_t field_0de0[1424];
    uint64_t field_1370;
    uint32_t field_1378;
    uint8_t field_137c[12];
    uint8_t field_1388[240];
    uint8_t field_1478[12];
    uint32_t field_1484;
    uint64_t field_1488;
    uint64_t field_1490;
    uint64_t field_1498;
    uint64_t field_14a0;
    uint8_t _pad_14a8[16];
    uint32_t field_14b8;
    uint8_t _pad_14bc[4];
    uint64_t field_14c0;
    uint32_t field_14c8;
    uint8_t _pad_14cc[4];
    uint64_t field_14d0;
} ccAdvSupportParam;

static_assert(offsetof(ccAdvSupportParam, field_0014) == 0x14, "ccAdvSupportParam::field_0014 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_0024) == 0x24, "ccAdvSupportParam::field_0024 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_0848) == 0x848, "ccAdvSupportParam::field_0848 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_0dd8) == 0xDD8, "ccAdvSupportParam::field_0dd8 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_0de0) == 0xDE0, "ccAdvSupportParam::field_0de0 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1370) == 0x1370, "ccAdvSupportParam::field_1370 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1378) == 0x1378, "ccAdvSupportParam::field_1378 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_137c) == 0x137C, "ccAdvSupportParam::field_137c offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1388) == 0x1388, "ccAdvSupportParam::field_1388 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1478) == 0x1478, "ccAdvSupportParam::field_1478 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1484) == 0x1484, "ccAdvSupportParam::field_1484 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1488) == 0x1488, "ccAdvSupportParam::field_1488 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1490) == 0x1490, "ccAdvSupportParam::field_1490 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_1498) == 0x1498, "ccAdvSupportParam::field_1498 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_14a0) == 0x14A0, "ccAdvSupportParam::field_14a0 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_14b8) == 0x14B8, "ccAdvSupportParam::field_14b8 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_14c0) == 0x14C0, "ccAdvSupportParam::field_14c0 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_14c8) == 0x14C8, "ccAdvSupportParam::field_14c8 offset mismatch");
static_assert(offsetof(ccAdvSupportParam, field_14d0) == 0x14D0, "ccAdvSupportParam::field_14d0 offset mismatch");

/* ccAdvSupportSensor — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvSupportSensor {
    uint8_t _pad_0000[20];
    uint64_t field_0014;
    uint8_t field_001c[68];
    uint64_t field_0060;
    uint64_t field_0068;
    uint64_t field_0070;
    uint64_t field_0078;
    uint8_t _pad_0080[16];
    uint64_t field_0090;
    uint64_t field_0098;
    uint64_t field_00a0;
    uint64_t field_00a8;
    uint8_t _pad_00b0[16];
    uint64_t field_00c0;
    uint64_t field_00c8;
    uint64_t field_00d0;
    uint64_t field_00d8;
} ccAdvSupportSensor;

static_assert(offsetof(ccAdvSupportSensor, field_0014) == 0x14, "ccAdvSupportSensor::field_0014 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_001c) == 0x1C, "ccAdvSupportSensor::field_001c offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_0060) == 0x60, "ccAdvSupportSensor::field_0060 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_0068) == 0x68, "ccAdvSupportSensor::field_0068 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_0070) == 0x70, "ccAdvSupportSensor::field_0070 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_0078) == 0x78, "ccAdvSupportSensor::field_0078 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_0090) == 0x90, "ccAdvSupportSensor::field_0090 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_0098) == 0x98, "ccAdvSupportSensor::field_0098 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_00a0) == 0xA0, "ccAdvSupportSensor::field_00a0 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_00a8) == 0xA8, "ccAdvSupportSensor::field_00a8 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_00c0) == 0xC0, "ccAdvSupportSensor::field_00c0 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_00c8) == 0xC8, "ccAdvSupportSensor::field_00c8 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_00d0) == 0xD0, "ccAdvSupportSensor::field_00d0 offset mismatch");
static_assert(offsetof(ccAdvSupportSensor, field_00d8) == 0xD8, "ccAdvSupportSensor::field_00d8 offset mismatch");

/* ccAdvSupportState — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvSupportState {
    uint8_t _pad_0000[84];
    uint64_t field_0054;
    uint32_t field_005c;
    uint32_t field_0060;
    uint8_t _pad_0064[4];
    uint64_t field_0068;
    uint8_t field_0070[8];
    uint64_t field_0078;
    uint64_t field_0080;
    uint64_t field_0088;
    uint8_t _pad_0090[16];
    uint64_t field_00a0;
    uint64_t field_00a8;
    uint64_t field_00b0;
    uint64_t field_00b8;
    uint8_t field_00c0[12];
    uint32_t field_00cc;
    uint8_t field_00d0[112];
    uint64_t field_0140;
    uint8_t _pad_0148[8];
    uint8_t field_0150[112];
    uint64_t field_01c0;
    uint8_t field_01c8[112];
    uint64_t field_0238;
    uint32_t field_0240;
    uint32_t field_0244;
    uint32_t field_0248;
    uint8_t _pad_024c[4];
    uint64_t field_0250;
} ccAdvSupportState;

static_assert(offsetof(ccAdvSupportState, field_0054) == 0x54, "ccAdvSupportState::field_0054 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_005c) == 0x5C, "ccAdvSupportState::field_005c offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0060) == 0x60, "ccAdvSupportState::field_0060 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0068) == 0x68, "ccAdvSupportState::field_0068 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0070) == 0x70, "ccAdvSupportState::field_0070 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0078) == 0x78, "ccAdvSupportState::field_0078 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0080) == 0x80, "ccAdvSupportState::field_0080 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0088) == 0x88, "ccAdvSupportState::field_0088 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00a0) == 0xA0, "ccAdvSupportState::field_00a0 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00a8) == 0xA8, "ccAdvSupportState::field_00a8 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00b0) == 0xB0, "ccAdvSupportState::field_00b0 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00b8) == 0xB8, "ccAdvSupportState::field_00b8 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00c0) == 0xC0, "ccAdvSupportState::field_00c0 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00cc) == 0xCC, "ccAdvSupportState::field_00cc offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_00d0) == 0xD0, "ccAdvSupportState::field_00d0 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0140) == 0x140, "ccAdvSupportState::field_0140 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0150) == 0x150, "ccAdvSupportState::field_0150 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_01c0) == 0x1C0, "ccAdvSupportState::field_01c0 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_01c8) == 0x1C8, "ccAdvSupportState::field_01c8 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0238) == 0x238, "ccAdvSupportState::field_0238 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0240) == 0x240, "ccAdvSupportState::field_0240 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0244) == 0x244, "ccAdvSupportState::field_0244 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0248) == 0x248, "ccAdvSupportState::field_0248 offset mismatch");
static_assert(offsetof(ccAdvSupportState, field_0250) == 0x250, "ccAdvSupportState::field_0250 offset mismatch");

/* ccAdvSupportStateList — size unknown (embedded sub-object, no standalone allocation found) */
typedef struct __attribute__((packed)) ccAdvSupportStateList {
    uint8_t _pad_0000[104];
    uint8_t field_0068[8];
    uint64_t field_0070;
    uint64_t field_0078;
    uint64_t field_0080;
    uint8_t _pad_0088[16];
    uint64_t field_0098;
    uint64_t field_00a0;
    uint64_t field_00a8;
    uint64_t field_00b0;
    uint8_t _pad_00b8[28];
    uint32_t field_00d4;
    uint64_t field_00d8;
    uint64_t field_00e0;
    uint64_t field_00e8;
} ccAdvSupportStateList;

static_assert(offsetof(ccAdvSupportStateList, field_0068) == 0x68, "ccAdvSupportStateList::field_0068 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_0070) == 0x70, "ccAdvSupportStateList::field_0070 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_0078) == 0x78, "ccAdvSupportStateList::field_0078 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_0080) == 0x80, "ccAdvSupportStateList::field_0080 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_0098) == 0x98, "ccAdvSupportStateList::field_0098 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00a0) == 0xA0, "ccAdvSupportStateList::field_00a0 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00a8) == 0xA8, "ccAdvSupportStateList::field_00a8 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00b0) == 0xB0, "ccAdvSupportStateList::field_00b0 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00d4) == 0xD4, "ccAdvSupportStateList::field_00d4 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00d8) == 0xD8, "ccAdvSupportStateList::field_00d8 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00e0) == 0xE0, "ccAdvSupportStateList::field_00e0 offset mismatch");
static_assert(offsetof(ccAdvSupportStateList, field_00e8) == 0xE8, "ccAdvSupportStateList::field_00e8 offset mismatch");

/* ccAdvStageDrawList — present in build but state_surface found no field accesses */
typedef struct __attribute__((packed)) ccAdvStageDrawList {
    uint8_t _opaque[1]; /* size unknown */
} ccAdvStageDrawList;

/* ccAdvUiManager — present in build but state_surface found no field accesses */
typedef struct __attribute__((packed)) ccAdvUiManager {
    uint8_t _opaque[1]; /* size unknown */
} ccAdvUiManager;

#endif /* ST3A13_H */
