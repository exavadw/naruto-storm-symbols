/*
 * ccSoundFamily - NARUTO STORM 1 (NSUNS1.exe, build s1)
 * Reconstructed from Ghidra decompilation via the decompiler cache state_surface + manual ctor analysis.
 *
 * Classes covered:
 *   ccSound_Sub          - sub-object embedded in ccSound (size unknown, >= 0xB0)
 *   nuccCriAdx2Manager   - CRI ADX2 audio middleware wrapper (size 0x1D8)
 *   nuccSound            - top-level sound system singleton (size 0x29B8)
 *   ccSeCallManager      - SE call/queue manager (size unknown, >= 0x50)
 *   ccSoundLoadThread    - async sound loading thread (size unknown, >= 0x70)
 *
 * Classes absent from s1 symbol table (no methods found):
 *   ccSoundEvent, ccSoundEventManager, ccSoundEvent_Demo, ccSoundEvent_DemoEx,
 *   ccSoundEvent_Anm, ccSoundFileLoader, ccSoundTable, ccVoiceParamManager
 *
 * All fields INFERRED from static analysis; not runtime-confirmed.
 * Offsets are BYTE offsets from x64 PC decompilation (image base 0x140000000).
 * All structs use __attribute__((packed)) for exact byte-offset matching.
 */
#ifndef CCSOUNDFAMILY_S1_H
#define CCSOUNDFAMILY_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ccSound ccSound;

/* ccSound_Sub: ctor FUN_1404fde60, vtable PTR_LAB_14073fd70, size >= 0xB0 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void     *vtable;
    /* 0x08 */ uint64_t  unk_08;
    /* 0x10 */ uint64_t  unk_10;
    /* 0x18 */ uint64_t  unk_18;
    /* 0x20 */ uint64_t  unk_20;
    /* 0x28 */ uint64_t  unk_28;
    /* 0x30 */ uint64_t  unk_30;
    /* 0x38 */ uint32_t  unk_38;
    /* 0x3C */ uint64_t  unk_3c;
    /* 0x44 */ uint64_t  unk_44;
    /* 0x4C */ uint8_t   pad_4c[4];
    /* 0x50 */ uint8_t   zeroed_50[0x50];
    /* 0xA0 */ uint32_t  unk_a0;
    /* 0xA4 */ uint8_t   pad_a4[4];
    /* 0xA8 */ uint64_t  unk_a8;
} ccSound_Sub;

static_assert(offsetof(ccSound_Sub, vtable) == 0x0, "ccSound_Sub.vtable");
static_assert(offsetof(ccSound_Sub, unk_08) == 0x8, "ccSound_Sub.unk_08");
static_assert(offsetof(ccSound_Sub, unk_10) == 0x10, "ccSound_Sub.unk_10");
static_assert(offsetof(ccSound_Sub, unk_18) == 0x18, "ccSound_Sub.unk_18");
static_assert(offsetof(ccSound_Sub, unk_20) == 0x20, "ccSound_Sub.unk_20");
static_assert(offsetof(ccSound_Sub, unk_28) == 0x28, "ccSound_Sub.unk_28");
static_assert(offsetof(ccSound_Sub, unk_30) == 0x30, "ccSound_Sub.unk_30");
static_assert(offsetof(ccSound_Sub, unk_38) == 0x38, "ccSound_Sub.unk_38");
static_assert(offsetof(ccSound_Sub, unk_3c) == 0x3C, "ccSound_Sub.unk_3c");
static_assert(offsetof(ccSound_Sub, unk_44) == 0x44, "ccSound_Sub.unk_44");
static_assert(offsetof(ccSound_Sub, zeroed_50) == 0x50, "ccSound_Sub.zeroed_50");
static_assert(offsetof(ccSound_Sub, unk_a0) == 0xA0, "ccSound_Sub.unk_a0");
static_assert(offsetof(ccSound_Sub, unk_a8) == 0xA8, "ccSound_Sub.unk_a8");

/* nuccCriAdx2Manager: ctor FUN_1404cd740, factory FUN_1404cda90 (alloc 0x1D8),
 * vtable PTR_FUN_14073b320, global DAT_1408c60d0 */
typedef struct __attribute__((packed)) {
    /* 0x000 */ void     *vtable;
    /* 0x008 */ uint8_t   pad_008[0x38];
    /* 0x040 */ int32_t   unk_040;
    /* 0x044 */ uint8_t   pad_044[0x2C];
    /* 0x070 */ uint64_t  unk_070;
    /* 0x078 */ uint32_t  unk_078;
    /* 0x07C */ uint8_t   pad_07c[0x14];
    /* 0x090 */ uint64_t  unk_090;
    /* 0x098 */ uint32_t  unk_098;
    /* 0x09C */ uint64_t  unk_09c;
    /* 0x0A4 */ int32_t   unk_0a4;
    /* 0x0A8 */ int32_t   unk_0a8;
    /* 0x0AC */ uint64_t  unk_0ac;
    /* 0x0B4 */ uint64_t  unk_0b4;
    /* 0x0BC */ uint64_t  unk_0bc;
    /* 0x0C4 */ float     volumeMaster;
    /* 0x0C8 */ float     volumeBgm;
    /* 0x0CC */ float     volumeSe;
    /* 0x0D0 */ float     volumeVoice;
    /* 0x0D4 */ uint8_t   pad_0d4[4];
    /* 0x0D8 */ uint8_t   nameBuf[0x40];
    /* 0x118 */ uint32_t  unk_118;
    /* 0x11C */ uint8_t   pad_11c[4];
    /* 0x120 */ uint64_t  unk_120;
    /* 0x128 */ uint64_t  unk_128;
    /* 0x130 */ uint16_t  unk_130;
    /* 0x132 */ uint8_t   pad_132[2];
    /* 0x134 */ uint64_t  unk_134;
    /* 0x13C */ uint32_t  unk_13c;
    /* 0x140 */ uint16_t  unk_140;
    /* 0x142 */ uint8_t   pad_142[2];
    /* 0x144 */ uint64_t  unk_144;
    /* 0x14C */ uint32_t  unk_14c;
    /* 0x150 */ uint16_t  unk_150;
    /* 0x152 */ uint8_t   pad_152[2];
    /* 0x154 */ uint64_t  unk_154;
    /* 0x15C */ uint32_t  unk_15c;
    /* 0x160 */ uint8_t   pad_160[0x0C];
    /* 0x16C */ uint64_t  unk_16c;
    /* 0x174 */ uint32_t  unk_174;
    /* 0x178 */ uint64_t  unk_178;
    /* 0x180 */ uint32_t  unk_180;
    /* 0x184 */ uint64_t  unk_184;
    /* 0x18C */ uint32_t  unk_18c;
    /* 0x190 */ uint8_t   pad_190[0x0C];
    /* 0x19C */ uint64_t  unk_19c;
    /* 0x1A4 */ uint32_t  unk_1a4;
    /* 0x1A8 */ int32_t   unk_1a8;
    /* 0x1AC */ int32_t   unk_1ac;
    /* 0x1B0 */ uint8_t   pad_1b0[8];
    /* 0x1B8 */ uint64_t  unk_1b8;
    /* 0x1C0 */ uint64_t  unk_1c0;
    /* 0x1C8 */ uint64_t  unk_1c8;
    /* 0x1D0 */ uint32_t  unk_1d0;
    /* 0x1D4 */ uint8_t   pad_1d4[4];
} nuccCriAdx2Manager;

static_assert(sizeof(nuccCriAdx2Manager) == 0x1D8, "nuccCriAdx2Manager size");
static_assert(offsetof(nuccCriAdx2Manager, vtable) == 0x000, "nuccCriAdx2Manager.vtable");
static_assert(offsetof(nuccCriAdx2Manager, unk_040) == 0x040, "nuccCriAdx2Manager.unk_040");
static_assert(offsetof(nuccCriAdx2Manager, unk_070) == 0x070, "nuccCriAdx2Manager.unk_070");
static_assert(offsetof(nuccCriAdx2Manager, unk_078) == 0x078, "nuccCriAdx2Manager.unk_078");
static_assert(offsetof(nuccCriAdx2Manager, unk_090) == 0x090, "nuccCriAdx2Manager.unk_090");
static_assert(offsetof(nuccCriAdx2Manager, unk_098) == 0x098, "nuccCriAdx2Manager.unk_098");
static_assert(offsetof(nuccCriAdx2Manager, unk_09c) == 0x09C, "nuccCriAdx2Manager.unk_09c");
static_assert(offsetof(nuccCriAdx2Manager, unk_0a4) == 0x0A4, "nuccCriAdx2Manager.unk_0a4");
static_assert(offsetof(nuccCriAdx2Manager, unk_0a8) == 0x0A8, "nuccCriAdx2Manager.unk_0a8");
static_assert(offsetof(nuccCriAdx2Manager, unk_0ac) == 0x0AC, "nuccCriAdx2Manager.unk_0ac");
static_assert(offsetof(nuccCriAdx2Manager, unk_0b4) == 0x0B4, "nuccCriAdx2Manager.unk_0b4");
static_assert(offsetof(nuccCriAdx2Manager, unk_0bc) == 0x0BC, "nuccCriAdx2Manager.unk_0bc");
static_assert(offsetof(nuccCriAdx2Manager, volumeMaster) == 0x0C4, "nuccCriAdx2Manager.volumeMaster");
static_assert(offsetof(nuccCriAdx2Manager, volumeBgm) == 0x0C8, "nuccCriAdx2Manager.volumeBgm");
static_assert(offsetof(nuccCriAdx2Manager, volumeSe) == 0x0CC, "nuccCriAdx2Manager.volumeSe");
static_assert(offsetof(nuccCriAdx2Manager, volumeVoice) == 0x0D0, "nuccCriAdx2Manager.volumeVoice");
static_assert(offsetof(nuccCriAdx2Manager, nameBuf) == 0x0D8, "nuccCriAdx2Manager.nameBuf");
static_assert(offsetof(nuccCriAdx2Manager, unk_118) == 0x118, "nuccCriAdx2Manager.unk_118");
static_assert(offsetof(nuccCriAdx2Manager, unk_120) == 0x120, "nuccCriAdx2Manager.unk_120");
static_assert(offsetof(nuccCriAdx2Manager, unk_128) == 0x128, "nuccCriAdx2Manager.unk_128");
static_assert(offsetof(nuccCriAdx2Manager, unk_130) == 0x130, "nuccCriAdx2Manager.unk_130");
static_assert(offsetof(nuccCriAdx2Manager, unk_134) == 0x134, "nuccCriAdx2Manager.unk_134");
static_assert(offsetof(nuccCriAdx2Manager, unk_13c) == 0x13C, "nuccCriAdx2Manager.unk_13c");
static_assert(offsetof(nuccCriAdx2Manager, unk_140) == 0x140, "nuccCriAdx2Manager.unk_140");
static_assert(offsetof(nuccCriAdx2Manager, unk_144) == 0x144, "nuccCriAdx2Manager.unk_144");
static_assert(offsetof(nuccCriAdx2Manager, unk_14c) == 0x14C, "nuccCriAdx2Manager.unk_14c");
static_assert(offsetof(nuccCriAdx2Manager, unk_150) == 0x150, "nuccCriAdx2Manager.unk_150");
static_assert(offsetof(nuccCriAdx2Manager, unk_154) == 0x154, "nuccCriAdx2Manager.unk_154");
static_assert(offsetof(nuccCriAdx2Manager, unk_15c) == 0x15C, "nuccCriAdx2Manager.unk_15c");
static_assert(offsetof(nuccCriAdx2Manager, unk_16c) == 0x16C, "nuccCriAdx2Manager.unk_16c");
static_assert(offsetof(nuccCriAdx2Manager, unk_174) == 0x174, "nuccCriAdx2Manager.unk_174");
static_assert(offsetof(nuccCriAdx2Manager, unk_178) == 0x178, "nuccCriAdx2Manager.unk_178");
static_assert(offsetof(nuccCriAdx2Manager, unk_180) == 0x180, "nuccCriAdx2Manager.unk_180");
static_assert(offsetof(nuccCriAdx2Manager, unk_184) == 0x184, "nuccCriAdx2Manager.unk_184");
static_assert(offsetof(nuccCriAdx2Manager, unk_18c) == 0x18C, "nuccCriAdx2Manager.unk_18c");
static_assert(offsetof(nuccCriAdx2Manager, unk_19c) == 0x19C, "nuccCriAdx2Manager.unk_19c");
static_assert(offsetof(nuccCriAdx2Manager, unk_1a4) == 0x1A4, "nuccCriAdx2Manager.unk_1a4");
static_assert(offsetof(nuccCriAdx2Manager, unk_1a8) == 0x1A8, "nuccCriAdx2Manager.unk_1a8");
static_assert(offsetof(nuccCriAdx2Manager, unk_1ac) == 0x1AC, "nuccCriAdx2Manager.unk_1ac");
static_assert(offsetof(nuccCriAdx2Manager, unk_1b8) == 0x1B8, "nuccCriAdx2Manager.unk_1b8");
static_assert(offsetof(nuccCriAdx2Manager, unk_1c0) == 0x1C0, "nuccCriAdx2Manager.unk_1c0");
static_assert(offsetof(nuccCriAdx2Manager, unk_1c8) == 0x1C8, "nuccCriAdx2Manager.unk_1c8");
static_assert(offsetof(nuccCriAdx2Manager, unk_1d0) == 0x1D0, "nuccCriAdx2Manager.unk_1d0");

/* nuccSound_SubObj: stride 0x20, vtable PTR_FUN_14073c2b8 */
typedef struct __attribute__((packed)) {
    void *vtable;
    uint64_t unk_08;
    uint64_t unk_10;
    uint64_t unk_18;
} nuccSound_SubObj;
static_assert(sizeof(nuccSound_SubObj) == 0x20, "nuccSound_SubObj size");

/* nuccSound: ctor FUN_1404d1250, factory FUN_1404d14a0 (alloc 0x29B8),
 * global DAT_1408c63b0, 319 sub-objects at stride 0x20 */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint64_t unk_0000;
    /* 0x0008 */ uint8_t pad_0008[4];
    /* 0x000C */ uint32_t configVersion;
    /* 0x0010 */ uint32_t unk_0010;
    /* 0x0014 */ uint8_t pad_0014[4];
    /* 0x0018 */ nuccSound_SubObj subObj_0018;
    /* 0x0038 */ uint64_t configBuffer;
    /* 0x0040 */ uint64_t unk_0040;
    /* 0x0048 */ uint64_t handleSlot_00[0x10];
    /* 0x00C8 */ uint64_t handleSlot_01[7];
    /* 0x0100 */ uint64_t handleSlot_02[0x0C];
    /* 0x0160 */ uint32_t unk_0160;
    /* 0x0164 */ int32_t idSlot_0164[0x10];
    /* 0x01A4 */ int32_t idSlot_01a4[7];
    /* 0x01C0 */ int32_t slotFlags[0x0C];
    /* 0x01F0 */ nuccSound_SubObj subObj_01f0;
    /* 0x0210 */ nuccSound_SubObj subObjArr_0210[16];
    /* 0x0410 */ nuccSound_SubObj subObjArr_0410[7];
    /* 0x04F0 */ nuccSound_SubObj subObjArr_04f0[12];
    /* 0x0670 */ nuccSound_SubObj subObjArr_0670[16];
    /* 0x0870 */ nuccSound_SubObj subObjArr_0870[128];
    /* 0x1870 */ nuccSound_SubObj subObjArr_1870[128];
    /* 0x2870 */ uint32_t unk_2870;
    /* 0x2874 */ uint8_t pad_2874[4];
    /* 0x2878 */ nuccSound_SubObj subObjArr_2878[10];
} nuccSound;

static_assert(sizeof(nuccSound) == 0x29B8, "nuccSound size");
static_assert(offsetof(nuccSound, unk_0000) == 0x0000, "nuccSound.unk_0000");
static_assert(offsetof(nuccSound, configVersion) == 0x000C, "nuccSound.configVersion");
static_assert(offsetof(nuccSound, unk_0010) == 0x0010, "nuccSound.unk_0010");
static_assert(offsetof(nuccSound, subObj_0018) == 0x0018, "nuccSound.subObj_0018");
static_assert(offsetof(nuccSound, configBuffer) == 0x0038, "nuccSound.configBuffer");
static_assert(offsetof(nuccSound, unk_0040) == 0x0040, "nuccSound.unk_0040");
static_assert(offsetof(nuccSound, handleSlot_00) == 0x0048, "nuccSound.handleSlot_00");
static_assert(offsetof(nuccSound, handleSlot_01) == 0x00C8, "nuccSound.handleSlot_01");
static_assert(offsetof(nuccSound, handleSlot_02) == 0x0100, "nuccSound.handleSlot_02");
static_assert(offsetof(nuccSound, unk_0160) == 0x0160, "nuccSound.unk_0160");
static_assert(offsetof(nuccSound, idSlot_0164) == 0x0164, "nuccSound.idSlot_0164");
static_assert(offsetof(nuccSound, idSlot_01a4) == 0x01A4, "nuccSound.idSlot_01a4");
static_assert(offsetof(nuccSound, slotFlags) == 0x01C0, "nuccSound.slotFlags");
static_assert(offsetof(nuccSound, subObj_01f0) == 0x01F0, "nuccSound.subObj_01f0");
static_assert(offsetof(nuccSound, subObjArr_0210) == 0x0210, "nuccSound.subObjArr_0210");
static_assert(offsetof(nuccSound, subObjArr_0410) == 0x0410, "nuccSound.subObjArr_0410");
static_assert(offsetof(nuccSound, subObjArr_04f0) == 0x04F0, "nuccSound.subObjArr_04f0");
static_assert(offsetof(nuccSound, subObjArr_0670) == 0x0670, "nuccSound.subObjArr_0670");
static_assert(offsetof(nuccSound, subObjArr_0870) == 0x0870, "nuccSound.subObjArr_0870");
static_assert(offsetof(nuccSound, subObjArr_1870) == 0x1870, "nuccSound.subObjArr_1870");
static_assert(offsetof(nuccSound, unk_2870) == 0x2870, "nuccSound.unk_2870");
static_assert(offsetof(nuccSound, subObjArr_2878) == 0x2878, "nuccSound.subObjArr_2878");

/* ccSeCallManager_SeSlot: 0x80 entries, stride 0x30, heap-allocated in Init FUN_1403fb1f4 */
typedef struct __attribute__((packed)) {
    int32_t seId;
    int32_t unk_04;
    float volume;
    uint8_t pad_0c[0x10];
    int32_t unk_1c;
    uint8_t pad_20[0x0C];
    int32_t flags;
} ccSeCallManager_SeSlot;
static_assert(sizeof(ccSeCallManager_SeSlot) == 0x30, "ccSeCallManager_SeSlot size");

/* ccSeCallManager: methods Ctrl/Exit/Init/IsCalledSeId/SeOn/SeOn3D, size >= 0x50 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t pad_00[0x30];
    /* 0x30 */ ccSeCallManager_SeSlot *slots;
    /* 0x38 */ int32_t activeCount;
    /* 0x3C */ uint8_t pad_3c[4];
    /* 0x40 */ void *buffer;
    /* 0x48 */ int32_t unk_48;
    /* 0x4C */ uint8_t pad_4c[4];
} ccSeCallManager;

static_assert(offsetof(ccSeCallManager, slots) == 0x30, "ccSeCallManager.slots");
static_assert(offsetof(ccSeCallManager, activeCount) == 0x38, "ccSeCallManager.activeCount");
static_assert(offsetof(ccSeCallManager, buffer) == 0x40, "ccSeCallManager.buffer");
static_assert(offsetof(ccSeCallManager, unk_48) == 0x48, "ccSeCallManager.unk_48");

/* ccSoundLoadThread: Exec FUN_14040e0e4, size >= 0x70 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t pad_00[0x60];
    /* 0x60 */ int32_t stopFlag;
    /* 0x64 */ int32_t unk_64;
    /* 0x68 */ int32_t unk_68;
    /* 0x6C */ int32_t unk_6c;
} ccSoundLoadThread;

static_assert(offsetof(ccSoundLoadThread, stopFlag) == 0x60, "ccSoundLoadThread.stopFlag");
static_assert(offsetof(ccSoundLoadThread, unk_64) == 0x64, "ccSoundLoadThread.unk_64");
static_assert(offsetof(ccSoundLoadThread, unk_68) == 0x68, "ccSoundLoadThread.unk_68");
static_assert(offsetof(ccSoundLoadThread, unk_6c) == 0x6C, "ccSoundLoadThread.unk_6c");

#endif /* CCSOUNDFAMILY_S1_H */
