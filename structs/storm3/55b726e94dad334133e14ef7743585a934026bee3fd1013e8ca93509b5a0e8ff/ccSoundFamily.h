/*
 * ccSoundFamily - NARUTO STORM 3 Full Burst HD (NSUNS3.exe, build s3)
 * Reconstructed from Ghidra decompilation via the decompiler cache state_surface + manual ctor/factory analysis.
 *
 * Classes covered:
 *   ccSoundEvent (size unknown)
 *   ccSoundEventManager (size unknown)
 *   ccSoundEvent_Anm (size 0xE0)
 *   ccSoundEvent_Demo (size 0x48)
 *   ccSoundEvent_DemoEx (size 0x58)
 *   ccSoundFileLoader (size 0x50)
 *   ccSoundTable (size 0x30)
 *   ccSound_Sub (size unknown)
 *   ccVoiceParamManager (size 0x50)
 *   nuccCriAdx2Manager (size 0x1D8)
 *   nuccSound (size 0x29B8)
 *
 * All fields INFERRED from static analysis; not runtime-confirmed.
 * Offsets are BYTE offsets from x64 PC decompilation (image base 0x140000000).
 * All structs use __attribute__((packed)) for exact byte-offset matching.
 */
#ifndef CCSOUNDFAMILY_S3_H
#define CCSOUNDFAMILY_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccSoundEvent: size unknown, >= 0x344
 * Fields: 0 named, 29 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[52];
/* 0x0034 */ uint32_t unk_034; /*  medium */
/* 0x0038 */ uint8_t pad_038[4];
/* 0x003C */ uint32_t unk_03c; /*  low */
/* 0x0040 */ uint8_t pad_040[4];
/* 0x0044 */ uint64_t unk_044; /*  medium */
/* 0x004C */ uint64_t unk_04c; /*  medium */
/* 0x0054 */ uint64_t unk_054; /*  medium */
/* 0x005C */ uint64_t unk_05c; /*  medium */
/* 0x0064 */ uint8_t pad_064[8];
/* 0x006C */ uint64_t unk_06c; /*  medium */
/* 0x0074 */ uint64_t unk_074; /*  medium */
/* 0x007C */ uint64_t unk_07c; /*  low */
/* 0x0084 */ uint64_t unk_084; /*  medium */
/* 0x008C */ uint64_t unk_08c; /*  medium */
/* 0x0094 */ uint64_t unk_094; /*  medium */
/* 0x009C */ uint64_t unk_09c; /*  medium */
/* 0x00A4 */ uint64_t unk_0a4; /*  medium */
/* 0x00AC */ uint32_t unk_0ac; /*  medium */
/* 0x00B0 */ uint32_t unk_0b0; /*  medium */
/* 0x00B4 */ uint32_t unk_0b4; /*  medium */
/* 0x00B8 */ uint32_t unk_0b8; /*  medium */
/* 0x00BC */ uint32_t unk_0bc; /*  high */
/* 0x00C0 */ uint32_t unk_0c0; /*  low */
/* 0x00C4 */ uint64_t unk_0c4; /*  medium */
/* 0x00CC */ uint8_t pad_0cc[180];
/* 0x0180 */ uint32_t unk_180; /*  low */
/* 0x0184 */ uint8_t pad_184[60];
/* 0x01C0 */ uint32_t unk_1c0; /*  low */
/* 0x01C4 */ uint8_t pad_1c4[60];
/* 0x0200 */ uint32_t unk_200; /*  low */
/* 0x0204 */ uint8_t pad_204[60];
/* 0x0240 */ uint32_t unk_240; /*  low */
/* 0x0244 */ uint8_t pad_244[60];
/* 0x0280 */ uint32_t unk_280; /*  low */
/* 0x0284 */ uint8_t pad_284[60];
/* 0x02C0 */ uint32_t unk_2c0; /*  low */
/* 0x02C4 */ uint8_t pad_2c4[60];
/* 0x0300 */ uint32_t unk_300; /*  low */
/* 0x0304 */ uint8_t pad_304[60];
/* 0x0340 */ uint32_t unk_340; /*  low */
} ccSoundEvent;

static_assert(offsetof(ccSoundEvent, pad_000) == 0x0, "ccSoundEvent.pad_000");
static_assert(offsetof(ccSoundEvent, unk_034) == 0x34, "ccSoundEvent.unk_034");
static_assert(offsetof(ccSoundEvent, pad_038) == 0x38, "ccSoundEvent.pad_038");
static_assert(offsetof(ccSoundEvent, unk_03c) == 0x3C, "ccSoundEvent.unk_03c");
static_assert(offsetof(ccSoundEvent, pad_040) == 0x40, "ccSoundEvent.pad_040");
static_assert(offsetof(ccSoundEvent, unk_044) == 0x44, "ccSoundEvent.unk_044");
static_assert(offsetof(ccSoundEvent, unk_04c) == 0x4C, "ccSoundEvent.unk_04c");
static_assert(offsetof(ccSoundEvent, unk_054) == 0x54, "ccSoundEvent.unk_054");
static_assert(offsetof(ccSoundEvent, unk_05c) == 0x5C, "ccSoundEvent.unk_05c");
static_assert(offsetof(ccSoundEvent, pad_064) == 0x64, "ccSoundEvent.pad_064");
static_assert(offsetof(ccSoundEvent, unk_06c) == 0x6C, "ccSoundEvent.unk_06c");
static_assert(offsetof(ccSoundEvent, unk_074) == 0x74, "ccSoundEvent.unk_074");
static_assert(offsetof(ccSoundEvent, unk_07c) == 0x7C, "ccSoundEvent.unk_07c");
static_assert(offsetof(ccSoundEvent, unk_084) == 0x84, "ccSoundEvent.unk_084");
static_assert(offsetof(ccSoundEvent, unk_08c) == 0x8C, "ccSoundEvent.unk_08c");
static_assert(offsetof(ccSoundEvent, unk_094) == 0x94, "ccSoundEvent.unk_094");
static_assert(offsetof(ccSoundEvent, unk_09c) == 0x9C, "ccSoundEvent.unk_09c");
static_assert(offsetof(ccSoundEvent, unk_0a4) == 0xA4, "ccSoundEvent.unk_0a4");
static_assert(offsetof(ccSoundEvent, unk_0ac) == 0xAC, "ccSoundEvent.unk_0ac");
static_assert(offsetof(ccSoundEvent, unk_0b0) == 0xB0, "ccSoundEvent.unk_0b0");
static_assert(offsetof(ccSoundEvent, unk_0b4) == 0xB4, "ccSoundEvent.unk_0b4");
static_assert(offsetof(ccSoundEvent, unk_0b8) == 0xB8, "ccSoundEvent.unk_0b8");
static_assert(offsetof(ccSoundEvent, unk_0bc) == 0xBC, "ccSoundEvent.unk_0bc");
static_assert(offsetof(ccSoundEvent, unk_0c0) == 0xC0, "ccSoundEvent.unk_0c0");
static_assert(offsetof(ccSoundEvent, unk_0c4) == 0xC4, "ccSoundEvent.unk_0c4");
static_assert(offsetof(ccSoundEvent, pad_0cc) == 0xCC, "ccSoundEvent.pad_0cc");
static_assert(offsetof(ccSoundEvent, unk_180) == 0x180, "ccSoundEvent.unk_180");
static_assert(offsetof(ccSoundEvent, pad_184) == 0x184, "ccSoundEvent.pad_184");
static_assert(offsetof(ccSoundEvent, unk_1c0) == 0x1C0, "ccSoundEvent.unk_1c0");
static_assert(offsetof(ccSoundEvent, pad_1c4) == 0x1C4, "ccSoundEvent.pad_1c4");
static_assert(offsetof(ccSoundEvent, unk_200) == 0x200, "ccSoundEvent.unk_200");
static_assert(offsetof(ccSoundEvent, pad_204) == 0x204, "ccSoundEvent.pad_204");
static_assert(offsetof(ccSoundEvent, unk_240) == 0x240, "ccSoundEvent.unk_240");
static_assert(offsetof(ccSoundEvent, pad_244) == 0x244, "ccSoundEvent.pad_244");
static_assert(offsetof(ccSoundEvent, unk_280) == 0x280, "ccSoundEvent.unk_280");
static_assert(offsetof(ccSoundEvent, pad_284) == 0x284, "ccSoundEvent.pad_284");
static_assert(offsetof(ccSoundEvent, unk_2c0) == 0x2C0, "ccSoundEvent.unk_2c0");
static_assert(offsetof(ccSoundEvent, pad_2c4) == 0x2C4, "ccSoundEvent.pad_2c4");
static_assert(offsetof(ccSoundEvent, unk_300) == 0x300, "ccSoundEvent.unk_300");
static_assert(offsetof(ccSoundEvent, pad_304) == 0x304, "ccSoundEvent.pad_304");
static_assert(offsetof(ccSoundEvent, unk_340) == 0x340, "ccSoundEvent.unk_340");
/* ccSoundEvent: size unknown, >= 0x344 */

/* =========================================================================
 * ccSoundEventManager: size unknown, >= 0x0
 * Fields: 0 named, 0 unnamed
 * ========================================================================= */
/* ccSoundEventManager: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccSoundEventManager;

/* =========================================================================
 * ccSoundEvent_Anm: size 0xE0
 * Alloc: FUN_140683f70(0xe0) in ccSoundEvent_Anm::CreateSndevData (0x493B0C)
 * Vtable: PTR_FUN_140975c08
 * Fields: 0 named, 0 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void * vtable; /* PTR_FUN_140975c08 */
/* 0x0008 */ uint8_t pad_008[216]; /* trailing */
} ccSoundEvent_Anm;

static_assert(offsetof(ccSoundEvent_Anm, vtable) == 0x0, "ccSoundEvent_Anm.vtable");
static_assert(offsetof(ccSoundEvent_Anm, pad_008) == 0x8, "ccSoundEvent_Anm.pad_008");
static_assert(sizeof(ccSoundEvent_Anm) == 0xE0, "ccSoundEvent_Anm size");

/* =========================================================================
 * ccSoundEvent_Demo: size 0x48
 * Alloc: FUN_140683f70(0x48) in ccSoundEvent_Demo::CreateSndevData (0x493ABC)
 * Vtable: PTR_FUN_140975bf8
 * Fields: 0 named, 0 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void * vtable; /* PTR_FUN_140975bf8 */
/* 0x0008 */ uint8_t pad_008[64]; /* trailing */
} ccSoundEvent_Demo;

static_assert(offsetof(ccSoundEvent_Demo, vtable) == 0x0, "ccSoundEvent_Demo.vtable");
static_assert(offsetof(ccSoundEvent_Demo, pad_008) == 0x8, "ccSoundEvent_Demo.pad_008");
static_assert(sizeof(ccSoundEvent_Demo) == 0x48, "ccSoundEvent_Demo size");

/* =========================================================================
 * ccSoundEvent_DemoEx: size 0x58
 * Alloc: FUN_140683f70(0x58) in ccSoundEvent_DemoEx::CreateSndevData (0x493B78)
 * Vtable: PTR_FUN_140975c18
 * Fields: 0 named, 1 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void * vtable; /* PTR_FUN_140975c18 */
/* 0x0008 */ uint8_t pad_008[44];
/* 0x0034 */ uint32_t unk_034; /*  medium */
/* 0x0038 */ uint8_t pad_038[32]; /* trailing */
} ccSoundEvent_DemoEx;

static_assert(offsetof(ccSoundEvent_DemoEx, vtable) == 0x0, "ccSoundEvent_DemoEx.vtable");
static_assert(offsetof(ccSoundEvent_DemoEx, pad_008) == 0x8, "ccSoundEvent_DemoEx.pad_008");
static_assert(offsetof(ccSoundEvent_DemoEx, unk_034) == 0x34, "ccSoundEvent_DemoEx.unk_034");
static_assert(offsetof(ccSoundEvent_DemoEx, pad_038) == 0x38, "ccSoundEvent_DemoEx.pad_038");
static_assert(sizeof(ccSoundEvent_DemoEx) == 0x58, "ccSoundEvent_DemoEx size");

/* =========================================================================
 * ccSoundFileLoader: size 0x50
 * Alloc: FUN_140683f70(0x50) in ccSoundFileLoader::CreateInstance (0x495A14)
 * Fields: 0 named, 0 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[80]; /* trailing */
} ccSoundFileLoader;

static_assert(offsetof(ccSoundFileLoader, pad_000) == 0x0, "ccSoundFileLoader.pad_000");
static_assert(sizeof(ccSoundFileLoader) == 0x50, "ccSoundFileLoader size");

/* =========================================================================
 * ccSoundTable: size 0x30
 * Alloc: FUN_140683f70(0x30) in ccSoundTable::Initialize (0x490EE8)
 * Vtable: PTR_FUN_14096eb20
 * Fields: 0 named, 0 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void * vtable; /* PTR_FUN_14096eb20 */
/* 0x0008 */ uint8_t pad_008[40]; /* trailing */
} ccSoundTable;

static_assert(offsetof(ccSoundTable, vtable) == 0x0, "ccSoundTable.vtable");
static_assert(offsetof(ccSoundTable, pad_008) == 0x8, "ccSoundTable.pad_008");
static_assert(sizeof(ccSoundTable) == 0x30, "ccSoundTable size");

/* =========================================================================
 * ccSound_Sub: size unknown, >= 0xB0
 * Fields: 0 named, 4 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[60];
/* 0x003C */ uint64_t unk_03c; /*  medium */
/* 0x0044 */ uint64_t unk_044; /*  medium */
/* 0x004C */ uint8_t pad_04c[84];
/* 0x00A0 */ uint32_t unk_0a0; /*  medium */
/* 0x00A4 */ uint8_t pad_0a4[4];
/* 0x00A8 */ uint64_t unk_0a8; /*  medium */
} ccSound_Sub;

static_assert(offsetof(ccSound_Sub, pad_000) == 0x0, "ccSound_Sub.pad_000");
static_assert(offsetof(ccSound_Sub, unk_03c) == 0x3C, "ccSound_Sub.unk_03c");
static_assert(offsetof(ccSound_Sub, unk_044) == 0x44, "ccSound_Sub.unk_044");
static_assert(offsetof(ccSound_Sub, pad_04c) == 0x4C, "ccSound_Sub.pad_04c");
static_assert(offsetof(ccSound_Sub, unk_0a0) == 0xA0, "ccSound_Sub.unk_0a0");
static_assert(offsetof(ccSound_Sub, pad_0a4) == 0xA4, "ccSound_Sub.pad_0a4");
static_assert(offsetof(ccSound_Sub, unk_0a8) == 0xA8, "ccSound_Sub.unk_0a8");
/* ccSound_Sub: size unknown, >= 0xB0 */

/* =========================================================================
 * ccVoiceParamManager: size 0x50
 * Alloc: FUN_140683f70(0x50) in ccVoiceParamManager::Create (0x5BBA6C)
 * Fields: 0 named, 0 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[80]; /* trailing */
} ccVoiceParamManager;

static_assert(offsetof(ccVoiceParamManager, pad_000) == 0x0, "ccVoiceParamManager.pad_000");
static_assert(sizeof(ccVoiceParamManager) == 0x50, "ccVoiceParamManager size");

/* =========================================================================
 * nuccCriAdx2Manager: size 0x1D8
 * Alloc: FUN_140683f70(0x1d8) in nuccCriAdx2Manager::CreateInstance (0x6BA120)
 * Vtable: set by ctor FUN_1406b9da0
 * Fields: 6 named, 43 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void * vtable; /* set by ctor FUN_1406b9da0 */
/* 0x0008 */ uint8_t pad_008[20];
/* 0x001C */ uint32_t initFlag_01c; /*  medium */
/* 0x0020 */ uint8_t pad_020[4];
/* 0x0024 */ uint32_t sampleRate; /*  medium */
/* 0x0028 */ uint8_t pad_028[4];
/* 0x002C */ uint64_t channelCount; /*  medium */
/* 0x0034 */ uint8_t pad_034[52];
/* 0x0068 */ uint64_t unk_068; /*  high */
/* 0x0070 */ uint64_t unk_070; /*  high */
/* 0x0078 */ uint32_t unk_078; /*  high */
/* 0x007C */ uint8_t pad_07c[4];
/* 0x0080 */ uint64_t unk_080; /*  low */
/* 0x0088 */ uint8_t pad_088[8];
/* 0x0090 */ uint64_t unk_090; /*  medium */
/* 0x0098 */ uint32_t unk_098; /*  medium */
/* 0x009C */ uint64_t unk_09c; /*  medium */
/* 0x00A4 */ uint32_t unk_0a4; /*  medium */
/* 0x00A8 */ uint32_t unk_0a8; /*  medium */
/* 0x00AC */ uint64_t unk_0ac; /*  medium */
/* 0x00B4 */ uint64_t unk_0b4; /*  medium */
/* 0x00BC */ uint32_t unk_0bc; /*  low */
/* 0x00C0 */ uint32_t unk_0c0; /*  medium */
/* 0x00C4 */ uint32_t volumeMaster; /*  high */
/* 0x00C8 */ uint32_t volumeBgm; /*  high */
/* 0x00CC */ uint32_t volumeSe; /*  high */
/* 0x00D0 */ uint64_t unk_0d0; /*  medium */
/* 0x00D8 */ uint32_t unk_0d8; /*  low */
/* 0x00DC */ uint8_t pad_0dc[60];
/* 0x0118 */ uint32_t unk_118; /*  high */
/* 0x011C */ uint8_t pad_11c[4];
/* 0x0120 */ uint64_t unk_120; /*  high */
/* 0x0128 */ uint64_t unk_128; /*  high */
/* 0x0130 */ uint16_t unk_130; /*  medium */
/* 0x0132 */ uint8_t pad_132[2];
/* 0x0134 */ uint64_t unk_134; /*  medium */
/* 0x013C */ uint32_t unk_13c; /*  medium */
/* 0x0140 */ uint16_t unk_140; /*  medium */
/* 0x0142 */ uint8_t pad_142[2];
/* 0x0144 */ uint64_t unk_144; /*  medium */
/* 0x014C */ uint32_t unk_14c; /*  medium */
/* 0x0150 */ uint16_t unk_150; /*  medium */
/* 0x0152 */ uint8_t pad_152[2];
/* 0x0154 */ uint64_t unk_154; /*  medium */
/* 0x015C */ uint32_t unk_15c; /*  medium */
/* 0x0160 */ uint32_t unk_160; /*  low */
/* 0x0164 */ uint8_t pad_164[8];
/* 0x016C */ uint64_t unk_16c; /*  high */
/* 0x0174 */ uint32_t unk_174; /*  high */
/* 0x0178 */ uint64_t unk_178; /*  high */
/* 0x0180 */ uint32_t unk_180; /*  high */
/* 0x0184 */ uint64_t unk_184; /*  high */
/* 0x018C */ uint32_t unk_18c; /*  high */
/* 0x0190 */ uint8_t pad_190[12];
/* 0x019C */ uint64_t unk_19c; /*  high */
/* 0x01A4 */ uint32_t unk_1a4; /*  high */
/* 0x01A8 */ uint32_t unk_1a8; /*  low */
/* 0x01AC */ uint32_t unk_1ac; /*  medium */
/* 0x01B0 */ uint32_t unk_1b0; /*  high */
/* 0x01B4 */ uint8_t pad_1b4[4];
/* 0x01B8 */ uint64_t unk_1b8; /*  high */
/* 0x01C0 */ uint64_t unk_1c0; /*  high */
/* 0x01C8 */ uint64_t unk_1c8; /*  high */
/* 0x01D0 */ uint32_t unk_1d0; /*  medium */
/* 0x01D4 */ uint8_t pad_1d4[4]; /* trailing */
} nuccCriAdx2Manager;

static_assert(offsetof(nuccCriAdx2Manager, vtable) == 0x0, "nuccCriAdx2Manager.vtable");
static_assert(offsetof(nuccCriAdx2Manager, pad_008) == 0x8, "nuccCriAdx2Manager.pad_008");
static_assert(offsetof(nuccCriAdx2Manager, initFlag_01c) == 0x1C, "nuccCriAdx2Manager.initFlag_01c");
static_assert(offsetof(nuccCriAdx2Manager, pad_020) == 0x20, "nuccCriAdx2Manager.pad_020");
static_assert(offsetof(nuccCriAdx2Manager, sampleRate) == 0x24, "nuccCriAdx2Manager.sampleRate");
static_assert(offsetof(nuccCriAdx2Manager, pad_028) == 0x28, "nuccCriAdx2Manager.pad_028");
static_assert(offsetof(nuccCriAdx2Manager, channelCount) == 0x2C, "nuccCriAdx2Manager.channelCount");
static_assert(offsetof(nuccCriAdx2Manager, pad_034) == 0x34, "nuccCriAdx2Manager.pad_034");
static_assert(offsetof(nuccCriAdx2Manager, unk_068) == 0x68, "nuccCriAdx2Manager.unk_068");
static_assert(offsetof(nuccCriAdx2Manager, unk_070) == 0x70, "nuccCriAdx2Manager.unk_070");
static_assert(offsetof(nuccCriAdx2Manager, unk_078) == 0x78, "nuccCriAdx2Manager.unk_078");
static_assert(offsetof(nuccCriAdx2Manager, pad_07c) == 0x7C, "nuccCriAdx2Manager.pad_07c");
static_assert(offsetof(nuccCriAdx2Manager, unk_080) == 0x80, "nuccCriAdx2Manager.unk_080");
static_assert(offsetof(nuccCriAdx2Manager, pad_088) == 0x88, "nuccCriAdx2Manager.pad_088");
static_assert(offsetof(nuccCriAdx2Manager, unk_090) == 0x90, "nuccCriAdx2Manager.unk_090");
static_assert(offsetof(nuccCriAdx2Manager, unk_098) == 0x98, "nuccCriAdx2Manager.unk_098");
static_assert(offsetof(nuccCriAdx2Manager, unk_09c) == 0x9C, "nuccCriAdx2Manager.unk_09c");
static_assert(offsetof(nuccCriAdx2Manager, unk_0a4) == 0xA4, "nuccCriAdx2Manager.unk_0a4");
static_assert(offsetof(nuccCriAdx2Manager, unk_0a8) == 0xA8, "nuccCriAdx2Manager.unk_0a8");
static_assert(offsetof(nuccCriAdx2Manager, unk_0ac) == 0xAC, "nuccCriAdx2Manager.unk_0ac");
static_assert(offsetof(nuccCriAdx2Manager, unk_0b4) == 0xB4, "nuccCriAdx2Manager.unk_0b4");
static_assert(offsetof(nuccCriAdx2Manager, unk_0bc) == 0xBC, "nuccCriAdx2Manager.unk_0bc");
static_assert(offsetof(nuccCriAdx2Manager, unk_0c0) == 0xC0, "nuccCriAdx2Manager.unk_0c0");
static_assert(offsetof(nuccCriAdx2Manager, volumeMaster) == 0xC4, "nuccCriAdx2Manager.volumeMaster");
static_assert(offsetof(nuccCriAdx2Manager, volumeBgm) == 0xC8, "nuccCriAdx2Manager.volumeBgm");
static_assert(offsetof(nuccCriAdx2Manager, volumeSe) == 0xCC, "nuccCriAdx2Manager.volumeSe");
static_assert(offsetof(nuccCriAdx2Manager, unk_0d0) == 0xD0, "nuccCriAdx2Manager.unk_0d0");
static_assert(offsetof(nuccCriAdx2Manager, unk_0d8) == 0xD8, "nuccCriAdx2Manager.unk_0d8");
static_assert(offsetof(nuccCriAdx2Manager, pad_0dc) == 0xDC, "nuccCriAdx2Manager.pad_0dc");
static_assert(offsetof(nuccCriAdx2Manager, unk_118) == 0x118, "nuccCriAdx2Manager.unk_118");
static_assert(offsetof(nuccCriAdx2Manager, pad_11c) == 0x11C, "nuccCriAdx2Manager.pad_11c");
static_assert(offsetof(nuccCriAdx2Manager, unk_120) == 0x120, "nuccCriAdx2Manager.unk_120");
static_assert(offsetof(nuccCriAdx2Manager, unk_128) == 0x128, "nuccCriAdx2Manager.unk_128");
static_assert(offsetof(nuccCriAdx2Manager, unk_130) == 0x130, "nuccCriAdx2Manager.unk_130");
static_assert(offsetof(nuccCriAdx2Manager, pad_132) == 0x132, "nuccCriAdx2Manager.pad_132");
static_assert(offsetof(nuccCriAdx2Manager, unk_134) == 0x134, "nuccCriAdx2Manager.unk_134");
static_assert(offsetof(nuccCriAdx2Manager, unk_13c) == 0x13C, "nuccCriAdx2Manager.unk_13c");
static_assert(offsetof(nuccCriAdx2Manager, unk_140) == 0x140, "nuccCriAdx2Manager.unk_140");
static_assert(offsetof(nuccCriAdx2Manager, pad_142) == 0x142, "nuccCriAdx2Manager.pad_142");
static_assert(offsetof(nuccCriAdx2Manager, unk_144) == 0x144, "nuccCriAdx2Manager.unk_144");
static_assert(offsetof(nuccCriAdx2Manager, unk_14c) == 0x14C, "nuccCriAdx2Manager.unk_14c");
static_assert(offsetof(nuccCriAdx2Manager, unk_150) == 0x150, "nuccCriAdx2Manager.unk_150");
static_assert(offsetof(nuccCriAdx2Manager, pad_152) == 0x152, "nuccCriAdx2Manager.pad_152");
static_assert(offsetof(nuccCriAdx2Manager, unk_154) == 0x154, "nuccCriAdx2Manager.unk_154");
static_assert(offsetof(nuccCriAdx2Manager, unk_15c) == 0x15C, "nuccCriAdx2Manager.unk_15c");
static_assert(offsetof(nuccCriAdx2Manager, unk_160) == 0x160, "nuccCriAdx2Manager.unk_160");
static_assert(offsetof(nuccCriAdx2Manager, pad_164) == 0x164, "nuccCriAdx2Manager.pad_164");
static_assert(offsetof(nuccCriAdx2Manager, unk_16c) == 0x16C, "nuccCriAdx2Manager.unk_16c");
static_assert(offsetof(nuccCriAdx2Manager, unk_174) == 0x174, "nuccCriAdx2Manager.unk_174");
static_assert(offsetof(nuccCriAdx2Manager, unk_178) == 0x178, "nuccCriAdx2Manager.unk_178");
static_assert(offsetof(nuccCriAdx2Manager, unk_180) == 0x180, "nuccCriAdx2Manager.unk_180");
static_assert(offsetof(nuccCriAdx2Manager, unk_184) == 0x184, "nuccCriAdx2Manager.unk_184");
static_assert(offsetof(nuccCriAdx2Manager, unk_18c) == 0x18C, "nuccCriAdx2Manager.unk_18c");
static_assert(offsetof(nuccCriAdx2Manager, pad_190) == 0x190, "nuccCriAdx2Manager.pad_190");
static_assert(offsetof(nuccCriAdx2Manager, unk_19c) == 0x19C, "nuccCriAdx2Manager.unk_19c");
static_assert(offsetof(nuccCriAdx2Manager, unk_1a4) == 0x1A4, "nuccCriAdx2Manager.unk_1a4");
static_assert(offsetof(nuccCriAdx2Manager, unk_1a8) == 0x1A8, "nuccCriAdx2Manager.unk_1a8");
static_assert(offsetof(nuccCriAdx2Manager, unk_1ac) == 0x1AC, "nuccCriAdx2Manager.unk_1ac");
static_assert(offsetof(nuccCriAdx2Manager, unk_1b0) == 0x1B0, "nuccCriAdx2Manager.unk_1b0");
static_assert(offsetof(nuccCriAdx2Manager, pad_1b4) == 0x1B4, "nuccCriAdx2Manager.pad_1b4");
static_assert(offsetof(nuccCriAdx2Manager, unk_1b8) == 0x1B8, "nuccCriAdx2Manager.unk_1b8");
static_assert(offsetof(nuccCriAdx2Manager, unk_1c0) == 0x1C0, "nuccCriAdx2Manager.unk_1c0");
static_assert(offsetof(nuccCriAdx2Manager, unk_1c8) == 0x1C8, "nuccCriAdx2Manager.unk_1c8");
static_assert(offsetof(nuccCriAdx2Manager, unk_1d0) == 0x1D0, "nuccCriAdx2Manager.unk_1d0");
static_assert(offsetof(nuccCriAdx2Manager, pad_1d4) == 0x1D4, "nuccCriAdx2Manager.pad_1d4");
static_assert(sizeof(nuccCriAdx2Manager) == 0x1D8, "nuccCriAdx2Manager size");

/* =========================================================================
 * nuccSound: size 0x29B8
 * Alloc: FUN_140683f70(0x29b8) in nuccSound::Create (0x6BBE50)
 * Vtable: PTR_FUN_1409e06e8
 * Fields: 1 named, 15 unnamed
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void * vtable; /* PTR_FUN_1409e06e8 */
/* 0x0008 */ uint8_t pad_008[4];
/* 0x000C */ uint32_t configVersion; /*  high */
/* 0x0010 */ uint8_t pad_010[184];
/* 0x00C8 */ uint32_t unk_0c8; /*  low */
/* 0x00CC */ uint8_t pad_0cc[52];
/* 0x0100 */ uint32_t unk_100; /*  low */
/* 0x0104 */ uint8_t pad_104[92];
/* 0x0160 */ uint32_t unk_160; /*  medium */
/* 0x0164 */ uint32_t unk_164; /*  low */
/* 0x0168 */ uint8_t pad_168[60];
/* 0x01A4 */ uint32_t unk_1a4; /*  low */
/* 0x01A8 */ uint8_t pad_1a8[24];
/* 0x01C0 */ uint32_t unk_1c0; /*  low */
/* 0x01C4 */ uint8_t pad_1c4[44];
/* 0x01F0 */ uint64_t unk_1f0; /*  low */
/* 0x01F8 */ uint8_t pad_1f8[24];
/* 0x0210 */ uint32_t unk_210; /*  low */
/* 0x0214 */ uint8_t pad_214[508];
/* 0x0410 */ uint32_t unk_410; /*  low */
/* 0x0414 */ uint8_t pad_414[220];
/* 0x04F0 */ uint32_t unk_4f0; /*  low */
/* 0x04F4 */ uint8_t pad_4f4[380];
/* 0x0670 */ uint32_t unk_670; /*  low */
/* 0x0674 */ uint8_t pad_674[508];
/* 0x0870 */ uint32_t unk_870; /*  low */
/* 0x0874 */ uint8_t pad_874[4092];
/* 0x1870 */ uint32_t unk_1870; /*  low */
/* 0x1874 */ uint8_t pad_1874[4092];
/* 0x2870 */ uint32_t unk_2870; /*  medium */
/* 0x2874 */ uint8_t pad_2874[4];
/* 0x2878 */ uint32_t unk_2878; /*  low */
/* 0x287C */ uint8_t pad_287c[316]; /* trailing */
} nuccSound;

static_assert(offsetof(nuccSound, vtable) == 0x0, "nuccSound.vtable");
static_assert(offsetof(nuccSound, pad_008) == 0x8, "nuccSound.pad_008");
static_assert(offsetof(nuccSound, configVersion) == 0xC, "nuccSound.configVersion");
static_assert(offsetof(nuccSound, pad_010) == 0x10, "nuccSound.pad_010");
static_assert(offsetof(nuccSound, unk_0c8) == 0xC8, "nuccSound.unk_0c8");
static_assert(offsetof(nuccSound, pad_0cc) == 0xCC, "nuccSound.pad_0cc");
static_assert(offsetof(nuccSound, unk_100) == 0x100, "nuccSound.unk_100");
static_assert(offsetof(nuccSound, pad_104) == 0x104, "nuccSound.pad_104");
static_assert(offsetof(nuccSound, unk_160) == 0x160, "nuccSound.unk_160");
static_assert(offsetof(nuccSound, unk_164) == 0x164, "nuccSound.unk_164");
static_assert(offsetof(nuccSound, pad_168) == 0x168, "nuccSound.pad_168");
static_assert(offsetof(nuccSound, unk_1a4) == 0x1A4, "nuccSound.unk_1a4");
static_assert(offsetof(nuccSound, pad_1a8) == 0x1A8, "nuccSound.pad_1a8");
static_assert(offsetof(nuccSound, unk_1c0) == 0x1C0, "nuccSound.unk_1c0");
static_assert(offsetof(nuccSound, pad_1c4) == 0x1C4, "nuccSound.pad_1c4");
static_assert(offsetof(nuccSound, unk_1f0) == 0x1F0, "nuccSound.unk_1f0");
static_assert(offsetof(nuccSound, pad_1f8) == 0x1F8, "nuccSound.pad_1f8");
static_assert(offsetof(nuccSound, unk_210) == 0x210, "nuccSound.unk_210");
static_assert(offsetof(nuccSound, pad_214) == 0x214, "nuccSound.pad_214");
static_assert(offsetof(nuccSound, unk_410) == 0x410, "nuccSound.unk_410");
static_assert(offsetof(nuccSound, pad_414) == 0x414, "nuccSound.pad_414");
static_assert(offsetof(nuccSound, unk_4f0) == 0x4F0, "nuccSound.unk_4f0");
static_assert(offsetof(nuccSound, pad_4f4) == 0x4F4, "nuccSound.pad_4f4");
static_assert(offsetof(nuccSound, unk_670) == 0x670, "nuccSound.unk_670");
static_assert(offsetof(nuccSound, pad_674) == 0x674, "nuccSound.pad_674");
static_assert(offsetof(nuccSound, unk_870) == 0x870, "nuccSound.unk_870");
static_assert(offsetof(nuccSound, pad_874) == 0x874, "nuccSound.pad_874");
static_assert(offsetof(nuccSound, unk_1870) == 0x1870, "nuccSound.unk_1870");
static_assert(offsetof(nuccSound, pad_1874) == 0x1874, "nuccSound.pad_1874");
static_assert(offsetof(nuccSound, unk_2870) == 0x2870, "nuccSound.unk_2870");
static_assert(offsetof(nuccSound, pad_2874) == 0x2874, "nuccSound.pad_2874");
static_assert(offsetof(nuccSound, unk_2878) == 0x2878, "nuccSound.unk_2878");
static_assert(offsetof(nuccSound, pad_287c) == 0x287C, "nuccSound.pad_287c");
static_assert(sizeof(nuccSound) == 0x29B8, "nuccSound size");

#endif /* CCSOUNDFAMILY_S3_H */
