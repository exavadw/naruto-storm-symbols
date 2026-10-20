/*
 * ccSoundFamily - NARUTO STORM 4 (NSUNS4_release.exe, build s4)
 * Reconstructed from Ghidra decompilation via the decompiler cache state_surface + manual ctor/factory analysis.
 *
 * Classes covered:
 *   ccSoundEvent (size unknown)
 *   ccSoundEventManager (size unknown)
 *   ccSoundEvent_Anm (size unknown)
 *   ccSoundEvent_Demo (size unknown)
 *   ccSoundEvent_DemoEx (size unknown)
 *   ccSoundFileLoader (size unknown)
 *   ccSoundTable (size unknown)
 *   ccSound_Sub (size unknown)
 *   ccVoiceParamManager (size unknown)
 *   nuccCriAdx2Manager (size 0x1D8)
 *   nuccSound (size 0x19B0)
 *
 * All fields INFERRED from static analysis; not runtime-confirmed.
 * Offsets are BYTE offsets from x64 PC decompilation (image base 0x140000000).
 * All structs use __attribute__((packed)) for exact byte-offset matching.
 */
#ifndef CCSOUNDFAMILY_S4_H
#define CCSOUNDFAMILY_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccSoundEvent: size unknown, >= 0xE0
 * Fields from state_surface + manual decompilation.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[68];
/* 0x0044 */ uint32_t unk_044; /* medium */
/* 0x0048 */ uint8_t pad_048[4];
/* 0x004C */ uint32_t unk_04c; /* high */
/* 0x0050 */ uint8_t pad_050[8];
/* 0x0058 */ uint64_t unk_058; /* medium */
/* 0x0060 */ uint64_t unk_060; /* medium */
/* 0x0068 */ uint64_t unk_068; /* medium */
/* 0x0070 */ uint64_t unk_070; /* medium */
/* 0x0078 */ uint64_t unk_078; /* medium */
/* 0x0080 */ uint64_t unk_080; /* low */
/* 0x0088 */ uint64_t unk_088; /* medium */
/* 0x0090 */ uint64_t unk_090; /* low */
/* 0x0098 */ uint64_t unk_098; /* medium */
/* 0x00A0 */ uint64_t unk_0a0; /* medium */
/* 0x00A8 */ uint64_t unk_0a8; /* medium */
/* 0x00B0 */ uint64_t unk_0b0; /* medium */
/* 0x00B8 */ uint64_t unk_0b8; /* medium */
/* 0x00C0 */ uint32_t unk_0c0; /* medium */
/* 0x00C4 */ uint32_t unk_0c4; /* medium */
/* 0x00C8 */ uint32_t unk_0c8; /* medium */
/* 0x00CC */ uint32_t unk_0cc; /* medium */
/* 0x00D0 */ uint32_t unk_0d0; /* high */
/* 0x00D4 */ uint32_t unk_0d4; /* medium */
/* 0x00D8 */ uint32_t unk_0d8; /* medium */
/* 0x00DC */ uint32_t unk_0dc; /* medium */
} ccSoundEvent;

static_assert(offsetof(ccSoundEvent, pad_000) == 0x0, "ccSoundEvent.pad_000");
static_assert(offsetof(ccSoundEvent, unk_044) == 0x44, "ccSoundEvent.unk_044");
static_assert(offsetof(ccSoundEvent, pad_048) == 0x48, "ccSoundEvent.pad_048");
static_assert(offsetof(ccSoundEvent, unk_04c) == 0x4C, "ccSoundEvent.unk_04c");
static_assert(offsetof(ccSoundEvent, pad_050) == 0x50, "ccSoundEvent.pad_050");
static_assert(offsetof(ccSoundEvent, unk_058) == 0x58, "ccSoundEvent.unk_058");
static_assert(offsetof(ccSoundEvent, unk_060) == 0x60, "ccSoundEvent.unk_060");
static_assert(offsetof(ccSoundEvent, unk_068) == 0x68, "ccSoundEvent.unk_068");
static_assert(offsetof(ccSoundEvent, unk_070) == 0x70, "ccSoundEvent.unk_070");
static_assert(offsetof(ccSoundEvent, unk_078) == 0x78, "ccSoundEvent.unk_078");
static_assert(offsetof(ccSoundEvent, unk_080) == 0x80, "ccSoundEvent.unk_080");
static_assert(offsetof(ccSoundEvent, unk_088) == 0x88, "ccSoundEvent.unk_088");
static_assert(offsetof(ccSoundEvent, unk_090) == 0x90, "ccSoundEvent.unk_090");
static_assert(offsetof(ccSoundEvent, unk_098) == 0x98, "ccSoundEvent.unk_098");
static_assert(offsetof(ccSoundEvent, unk_0a0) == 0xA0, "ccSoundEvent.unk_0a0");
static_assert(offsetof(ccSoundEvent, unk_0a8) == 0xA8, "ccSoundEvent.unk_0a8");
static_assert(offsetof(ccSoundEvent, unk_0b0) == 0xB0, "ccSoundEvent.unk_0b0");
static_assert(offsetof(ccSoundEvent, unk_0b8) == 0xB8, "ccSoundEvent.unk_0b8");
static_assert(offsetof(ccSoundEvent, unk_0c0) == 0xC0, "ccSoundEvent.unk_0c0");
static_assert(offsetof(ccSoundEvent, unk_0c4) == 0xC4, "ccSoundEvent.unk_0c4");
static_assert(offsetof(ccSoundEvent, unk_0c8) == 0xC8, "ccSoundEvent.unk_0c8");
static_assert(offsetof(ccSoundEvent, unk_0cc) == 0xCC, "ccSoundEvent.unk_0cc");
static_assert(offsetof(ccSoundEvent, unk_0d0) == 0xD0, "ccSoundEvent.unk_0d0");
static_assert(offsetof(ccSoundEvent, unk_0d4) == 0xD4, "ccSoundEvent.unk_0d4");
static_assert(offsetof(ccSoundEvent, unk_0d8) == 0xD8, "ccSoundEvent.unk_0d8");
static_assert(offsetof(ccSoundEvent, unk_0dc) == 0xDC, "ccSoundEvent.unk_0dc");
/* ccSoundEvent: size unknown, >= 0xE0 */

/* ccSoundEventManager: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccSoundEventManager;

/* ccSoundEvent_Anm: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccSoundEvent_Anm;

/* ccSoundEvent_Demo: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccSoundEvent_Demo;

/* =========================================================================
 * ccSoundEvent_DemoEx: size unknown, >= 0xE8
 * Fields from state_surface + manual decompilation.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[68];
/* 0x0044 */ uint32_t unk_044; /* medium */
/* 0x0048 */ uint8_t pad_048[136];
/* 0x00D0 */ uint64_t unk_0d0; /* medium */
/* 0x00D8 */ uint64_t unk_0d8; /* medium */
/* 0x00E0 */ uint64_t unk_0e0; /* high */
} ccSoundEvent_DemoEx;

static_assert(offsetof(ccSoundEvent_DemoEx, pad_000) == 0x0, "ccSoundEvent_DemoEx.pad_000");
static_assert(offsetof(ccSoundEvent_DemoEx, unk_044) == 0x44, "ccSoundEvent_DemoEx.unk_044");
static_assert(offsetof(ccSoundEvent_DemoEx, pad_048) == 0x48, "ccSoundEvent_DemoEx.pad_048");
static_assert(offsetof(ccSoundEvent_DemoEx, unk_0d0) == 0xD0, "ccSoundEvent_DemoEx.unk_0d0");
static_assert(offsetof(ccSoundEvent_DemoEx, unk_0d8) == 0xD8, "ccSoundEvent_DemoEx.unk_0d8");
static_assert(offsetof(ccSoundEvent_DemoEx, unk_0e0) == 0xE0, "ccSoundEvent_DemoEx.unk_0e0");
/* ccSoundEvent_DemoEx: size unknown, >= 0xE8 */

/* ccSoundFileLoader: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccSoundFileLoader;

/* ccSoundTable: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccSoundTable;

/* =========================================================================
 * ccSound_Sub: size unknown, >= 0xB0
 * Fields from state_surface + manual decompilation.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[60];
/* 0x003C */ uint64_t unk_03c; /* medium */
/* 0x0044 */ uint64_t unk_044; /* medium */
/* 0x004C */ uint8_t pad_04c[84];
/* 0x00A0 */ uint32_t unk_0a0; /* medium */
/* 0x00A4 */ uint8_t pad_0a4[4];
/* 0x00A8 */ uint64_t unk_0a8; /* medium */
} ccSound_Sub;

static_assert(offsetof(ccSound_Sub, pad_000) == 0x0, "ccSound_Sub.pad_000");
static_assert(offsetof(ccSound_Sub, unk_03c) == 0x3C, "ccSound_Sub.unk_03c");
static_assert(offsetof(ccSound_Sub, unk_044) == 0x44, "ccSound_Sub.unk_044");
static_assert(offsetof(ccSound_Sub, pad_04c) == 0x4C, "ccSound_Sub.pad_04c");
static_assert(offsetof(ccSound_Sub, unk_0a0) == 0xA0, "ccSound_Sub.unk_0a0");
static_assert(offsetof(ccSound_Sub, pad_0a4) == 0xA4, "ccSound_Sub.pad_0a4");
static_assert(offsetof(ccSound_Sub, unk_0a8) == 0xA8, "ccSound_Sub.unk_0a8");
/* ccSound_Sub: size unknown, >= 0xB0 */

/* ccVoiceParamManager: no fields found, size unknown */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder;
} ccVoiceParamManager;

/* =========================================================================
 * nuccCriAdx2Manager: size 0x1D8
 * Fields from state_surface + manual decompilation.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[28];
/* 0x001C */ uint32_t initFlag_01c; /* medium */
/* 0x0020 */ uint8_t pad_020[4];
/* 0x0024 */ uint32_t sampleRate; /* medium */
/* 0x0028 */ uint8_t pad_028[4];
/* 0x002C */ uint64_t channelCount; /* medium */
/* 0x0034 */ uint8_t pad_034[52];
/* 0x0068 */ uint64_t unk_068; /* high */
/* 0x0070 */ uint64_t unk_070; /* high */
/* 0x0078 */ uint32_t unk_078; /* high */
/* 0x007C */ uint8_t pad_07c[4];
/* 0x0080 */ uint64_t unk_080; /* low */
/* 0x0088 */ uint8_t pad_088[8];
/* 0x0090 */ uint64_t unk_090; /* medium */
/* 0x0098 */ uint32_t unk_098; /* medium */
/* 0x009C */ uint64_t unk_09c; /* medium */
/* 0x00A4 */ uint32_t unk_0a4; /* medium */
/* 0x00A8 */ uint32_t unk_0a8; /* medium */
/* 0x00AC */ uint64_t unk_0ac; /* medium */
/* 0x00B4 */ uint64_t unk_0b4; /* medium */
/* 0x00BC */ uint32_t unk_0bc; /* low */
/* 0x00C0 */ uint32_t unk_0c0; /* medium */
/* 0x00C4 */ uint32_t volumeMaster; /* high */
/* 0x00C8 */ uint32_t volumeBgm; /* high */
/* 0x00CC */ uint32_t volumeSe; /* high */
/* 0x00D0 */ uint64_t unk_0d0; /* medium */
/* 0x00D8 */ uint8_t pad_0d8[16];
/* 0x00E8 */ uint64_t unk_0e8; /* medium */
/* 0x00F0 */ uint8_t pad_0f0[40];
/* 0x0118 */ uint32_t unk_118; /* high */
/* 0x011C */ uint8_t pad_11c[4];
/* 0x0120 */ uint64_t unk_120; /* high */
/* 0x0128 */ uint64_t unk_128; /* high */
/* 0x0130 */ uint16_t unk_130; /* medium */
/* 0x0132 */ uint8_t pad_132[2];
/* 0x0134 */ uint64_t unk_134; /* medium */
/* 0x013C */ uint32_t unk_13c; /* medium */
/* 0x0140 */ uint16_t unk_140; /* medium */
/* 0x0142 */ uint8_t pad_142[2];
/* 0x0144 */ uint64_t unk_144; /* medium */
/* 0x014C */ uint32_t unk_14c; /* medium */
/* 0x0150 */ uint16_t unk_150; /* medium */
/* 0x0152 */ uint8_t pad_152[2];
/* 0x0154 */ uint64_t unk_154; /* medium */
/* 0x015C */ uint32_t unk_15c; /* medium */
/* 0x0160 */ uint8_t pad_160[12];
/* 0x016C */ uint64_t unk_16c; /* high */
/* 0x0174 */ uint32_t unk_174; /* high */
/* 0x0178 */ uint64_t unk_178; /* high */
/* 0x0180 */ uint32_t unk_180; /* high */
/* 0x0184 */ uint64_t unk_184; /* high */
/* 0x018C */ uint32_t unk_18c; /* high */
/* 0x0190 */ uint8_t pad_190[12];
/* 0x019C */ uint64_t unk_19c; /* high */
/* 0x01A4 */ uint32_t unk_1a4; /* high */
/* 0x01A8 */ uint32_t unk_1a8; /* low */
/* 0x01AC */ uint32_t unk_1ac; /* medium */
/* 0x01B0 */ uint32_t unk_1b0; /* high */
/* 0x01B4 */ uint8_t pad_1b4[4];
/* 0x01B8 */ uint64_t unk_1b8; /* high */
/* 0x01C0 */ uint64_t unk_1c0; /* high */
/* 0x01C8 */ uint64_t unk_1c8; /* high */
/* 0x01D0 */ uint32_t unk_1d0; /* medium */
/* 0x01D4 */ uint8_t pad_1d4[4]; /* trailing */
} nuccCriAdx2Manager;

static_assert(offsetof(nuccCriAdx2Manager, pad_000) == 0x0, "nuccCriAdx2Manager.pad_000");
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
static_assert(offsetof(nuccCriAdx2Manager, pad_0d8) == 0xD8, "nuccCriAdx2Manager.pad_0d8");
static_assert(offsetof(nuccCriAdx2Manager, unk_0e8) == 0xE8, "nuccCriAdx2Manager.unk_0e8");
static_assert(offsetof(nuccCriAdx2Manager, pad_0f0) == 0xF0, "nuccCriAdx2Manager.pad_0f0");
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
static_assert(offsetof(nuccCriAdx2Manager, pad_160) == 0x160, "nuccCriAdx2Manager.pad_160");
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
 * nuccSound: size 0x19B0
 * Fields from state_surface + manual decompilation.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* 0x0000 */ uint8_t pad_000[12];
/* 0x000C */ uint32_t configVersion; /* high */
/* 0x0010 */ uint8_t pad_010[328];
/* 0x0158 */ uint32_t unk_158; /* medium */
/* 0x015C */ uint8_t pad_15c[140];
/* 0x01E8 */ uint64_t unk_1e8; /* low */
/* 0x01F0 */ uint8_t pad_1f0[5752];
/* 0x1868 */ uint32_t unk_1868; /* medium */
/* 0x186C */ uint8_t pad_186c[324]; /* trailing */
} nuccSound;

static_assert(offsetof(nuccSound, pad_000) == 0x0, "nuccSound.pad_000");
static_assert(offsetof(nuccSound, configVersion) == 0xC, "nuccSound.configVersion");
static_assert(offsetof(nuccSound, pad_010) == 0x10, "nuccSound.pad_010");
static_assert(offsetof(nuccSound, unk_158) == 0x158, "nuccSound.unk_158");
static_assert(offsetof(nuccSound, pad_15c) == 0x15C, "nuccSound.pad_15c");
static_assert(offsetof(nuccSound, unk_1e8) == 0x1E8, "nuccSound.unk_1e8");
static_assert(offsetof(nuccSound, pad_1f0) == 0x1F0, "nuccSound.pad_1f0");
static_assert(offsetof(nuccSound, unk_1868) == 0x1868, "nuccSound.unk_1868");
static_assert(offsetof(nuccSound, pad_186c) == 0x186C, "nuccSound.pad_186c");
static_assert(sizeof(nuccSound) == 0x19B0, "nuccSound size");

#endif /* CCSOUNDFAMILY_S4_H */
