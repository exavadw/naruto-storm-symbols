/*
 * ccSoundFamily - NARUTO STORM 2 (NSUNS2.exe, build s2)
 * Reconstructed from Ghidra decompilation via the decompiler cache state_surface + manual ctor/factory analysis.
 *
 * Classes covered:
 *   ccSound              - top-level sound system singleton (size 0x2AE8)
 *   ccSound_Sub          - sub-object embedded in ccSound (size >= 0xB0)
 *   ccSoundEvent         - sound event instance (size 0xE8)
 *   ccSoundLoadThread    - async sound loading thread (size >= 0x78)
 *   ccSoundTable         - SE name-to-ID lookup table (size 0x30)
 *   nuccCriAdx2Manager   - CRI ADX2 audio middleware wrapper (size 0x1D8)
 *   nuccSound            - low-level sound system singleton (size 0x29B8)
 *
 * Classes absent from s2 symbol table (no methods found):
 *   ccSoundEventManager, ccSoundEvent_Demo, ccSoundEvent_DemoEx,
 *   ccSoundEvent_Anm, ccSoundFileLoader, ccSeCallManager, ccVoiceParamManager
 *
 * All fields INFERRED from static analysis; not runtime-confirmed.
 * Offsets are BYTE offsets from x64 PC decompilation (image base 0x140000000).
 * All structs use __attribute__((packed)) for exact byte-offset matching.
 * Field names carried forward from s1 header where offsets match.
 */
#ifndef CCSOUNDFAMILY_S2_H
#define CCSOUNDFAMILY_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ccSound ccSound;

/* =========================================================================
 * ccSound_Sub: ctor FUN_1405E7220, vtable PTR_LAB_1408974F0, size >= 0xB0
 * state_surface: 4 write-only fields in ctor (zero-init)
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void     *vtable;           /* PTR_LAB_1408974F0 */
    /* 0x08 */ uint64_t  unk_08;           /* zeroed in ctor */
    /* 0x10 */ uint64_t  unk_10;           /* zeroed in ctor */
    /* 0x18 */ uint64_t  unk_18;           /* zeroed in ctor */
    /* 0x20 */ uint64_t  unk_20;           /* zeroed in ctor */
    /* 0x28 */ uint64_t  unk_28;           /* zeroed in ctor */
    /* 0x30 */ uint64_t  unk_30;           /* zeroed in ctor */
    /* 0x38 */ uint32_t  unk_38;           /* zeroed in ctor */
    /* 0x3C */ uint64_t  unk_3c;           /* zeroed in ctor (state_surface w) */
    /* 0x44 */ uint64_t  unk_44;           /* zeroed in ctor (state_surface w) */
    /* 0x4C */ uint8_t   pad_4c[4];
    /* 0x50 */ uint8_t   zeroed_50[0x50];  /* memset(0, 0x50) in ctor */
    /* 0xA0 */ uint32_t  unk_a0;           /* zeroed in ctor (state_surface w) */
    /* 0xA4 */ uint8_t   pad_a4[4];
    /* 0xA8 */ uint64_t  unk_a8;           /* zeroed in ctor (state_surface w) */
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

/* =========================================================================
 * nuccCriAdx2Manager: ctor FUN_1405A8F60, factory FUN_1405A92B0 (alloc 0x1D8),
 * global DAT_140A5E350, vtable set by ctor
 * state_surface: 50 fields (47 writable, 3 read-only), 27 seeds
 * Volume floats at 0xC4/0xC8/0xCC confirmed by SetMasterVolume/SetVolumeGrp
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x000 */ void     *vtable;
    /* 0x008 */ uint8_t   pad_008[0x14];
    /* 0x01C */ int32_t   initFlag_01c;      /* set to 8 in Initialize */
    /* 0x020 */ uint8_t   pad_020[4];
    /* 0x024 */ int32_t   sampleRate;        /* set to 48000 in Initialize */
    /* 0x028 */ uint8_t   pad_028[4];
    /* 0x02C */ int32_t   channelCount;      /* set to 2 in Initialize */
    /* 0x030 */ uint8_t   pad_030[0x38];
    /* 0x068 */ uint64_t  unk_068;           /* high confidence rw */
    /* 0x070 */ uint64_t  unk_070;           /* high confidence rw */
    /* 0x078 */ uint8_t   pad_078[0x44];
    /* 0x0BC */ uint64_t  unk_0bc;           /* low confidence rw */
    /* 0x0C4 */ float     volumeMaster;      /* 1.0f default, high rw */
    /* 0x0C8 */ float     volumeBgm;         /* 1.0f default, high rw */
    /* 0x0CC */ float     volumeSe;          /* 1.0f default, high rw */
    /* 0x0D0 */ uint8_t   pad_0d0[0x58];
    /* 0x128 */ uint64_t  unk_128;           /* high confidence rw */
    /* 0x130 */ uint8_t   pad_130[0x98];
    /* 0x1C8 */ uint8_t   zeroed_1c8[0x10];  /* zero-init span in ctor/finalize */
    /* 0x1D8 */ /* end of allocation */
} nuccCriAdx2Manager;

static_assert(sizeof(nuccCriAdx2Manager) == 0x1D8, "nuccCriAdx2Manager size");
static_assert(offsetof(nuccCriAdx2Manager, vtable) == 0x000, "nuccCriAdx2Manager.vtable");
static_assert(offsetof(nuccCriAdx2Manager, initFlag_01c) == 0x01C, "nuccCriAdx2Manager.initFlag_01c");
static_assert(offsetof(nuccCriAdx2Manager, sampleRate) == 0x024, "nuccCriAdx2Manager.sampleRate");
static_assert(offsetof(nuccCriAdx2Manager, channelCount) == 0x02C, "nuccCriAdx2Manager.channelCount");
static_assert(offsetof(nuccCriAdx2Manager, unk_068) == 0x068, "nuccCriAdx2Manager.unk_068");
static_assert(offsetof(nuccCriAdx2Manager, unk_070) == 0x070, "nuccCriAdx2Manager.unk_070");
static_assert(offsetof(nuccCriAdx2Manager, unk_0bc) == 0x0BC, "nuccCriAdx2Manager.unk_0bc");
static_assert(offsetof(nuccCriAdx2Manager, volumeMaster) == 0x0C4, "nuccCriAdx2Manager.volumeMaster");
static_assert(offsetof(nuccCriAdx2Manager, volumeBgm) == 0x0C8, "nuccCriAdx2Manager.volumeBgm");
static_assert(offsetof(nuccCriAdx2Manager, volumeSe) == 0x0CC, "nuccCriAdx2Manager.volumeSe");
static_assert(offsetof(nuccCriAdx2Manager, unk_128) == 0x128, "nuccCriAdx2Manager.unk_128");
static_assert(offsetof(nuccCriAdx2Manager, zeroed_1c8) == 0x1C8, "nuccCriAdx2Manager.zeroed_1c8");

/* =========================================================================
 * nuccSound_SubObj: stride 0x20, sub-object used in nuccSound arrays
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    void *vtable;
    uint64_t unk_08;
    uint64_t unk_10;
    uint64_t unk_18;
} nuccSound_SubObj;
static_assert(sizeof(nuccSound_SubObj) == 0x20, "nuccSound_SubObj size");

/* =========================================================================
 * nuccSound: ctor FUN_1405C26E0, factory FUN_1405C2930 (alloc 0x29B8),
 * global DAT_140A9EE00
 * state_surface: 16 fields (4 writable, 12 read-only), 27 seeds
 * Layout matches s1 exactly (same allocation size 0x29B8)
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint64_t unk_0000;
    /* 0x0008 */ uint8_t pad_0008[4];
    /* 0x000C */ uint32_t configVersion;       /* rw, high confidence */
    /* 0x0010 */ uint32_t unk_0010;
    /* 0x0014 */ uint8_t pad_0014[4];
    /* 0x0018 */ nuccSound_SubObj subObj_0018;
    /* 0x0038 */ uint64_t configBuffer;
    /* 0x0040 */ uint64_t unk_0040;
    /* 0x0048 */ uint64_t handleSlot_00[0x10];
    /* 0x00C8 */ uint64_t handleSlot_01[7];
    /* 0x0100 */ uint64_t handleSlot_02[0x0C];
    /* 0x0160 */ uint32_t unk_0160;            /* w, medium, 0xffffffff */
    /* 0x0164 */ int32_t idSlot_0164[0x10];
    /* 0x01A4 */ int32_t idSlot_01a4[7];
    /* 0x01C0 */ int32_t slotFlags[0x0C];
    /* 0x01F0 */ nuccSound_SubObj subObj_01f0;  /* rw, low */
    /* 0x0210 */ nuccSound_SubObj subObjArr_0210[16];
    /* 0x0410 */ nuccSound_SubObj subObjArr_0410[7];
    /* 0x04F0 */ nuccSound_SubObj subObjArr_04f0[12];
    /* 0x0670 */ nuccSound_SubObj subObjArr_0670[16];
    /* 0x0870 */ nuccSound_SubObj subObjArr_0870[128];
    /* 0x1870 */ nuccSound_SubObj subObjArr_1870[128];
    /* 0x2870 */ uint32_t unk_2870;             /* w, medium */
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

/* =========================================================================
 * ccSoundEvent: factory FUN_140539BC8 (alloc 0xE8), ctor FUN_140539AF0
 * state_surface: 0 fields (all methods had unknown param_1 element size)
 * Size 0xE8 from allocator call in CreateInstance
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t data[0xE8];  /* opaque: state_surface yielded no field accesses */
} ccSoundEvent;

static_assert(sizeof(ccSoundEvent) == 0xE8, "ccSoundEvent size");

/* =========================================================================
 * ccSoundTable: factory in Initialize (alloc 0x30), global DAT_140A4B9F8
 * state_surface: 0 fields (only 1 seed: Initialize)
 * Size 0x30 from allocator call in Initialize
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t data[0x30];  /* opaque: state_surface yielded no field accesses */
} ccSoundTable;

static_assert(sizeof(ccSoundTable) == 0x30, "ccSoundTable size");

/* =========================================================================
 * ccSoundLoadThread: Exec FUN_14053B0EC, size >= 0x78
 * state_surface: 0 fields (Exec had unknown param_1 element size)
 * Fields from decompiled Exec: accesses at 0x60, 0x68, 0x70, 0x64 (decimal 100)
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t pad_00[0x60];
    /* 0x60 */ int32_t stopFlag;         /* checked != 0 in Exec loop */
    /* 0x64 */ int32_t unk_64;           /* accessed as *(int*)(param_1 + 100) = 0x64 */
    /* 0x68 */ uint64_t unk_68;          /* passed to FUN_14053b604 */
    /* 0x70 */ uint32_t unk_70;          /* passed to FUN_1405858b0 */
    /* 0x74 */ uint8_t pad_74[4];
} ccSoundLoadThread;

static_assert(offsetof(ccSoundLoadThread, stopFlag) == 0x60, "ccSoundLoadThread.stopFlag");
static_assert(offsetof(ccSoundLoadThread, unk_64) == 0x64, "ccSoundLoadThread.unk_64");
static_assert(offsetof(ccSoundLoadThread, unk_68) == 0x68, "ccSoundLoadThread.unk_68");
static_assert(offsetof(ccSoundLoadThread, unk_70) == 0x70, "ccSoundLoadThread.unk_70");

/* =========================================================================
 * ccSound: factory FUN_14053AD70 (alloc 0x2AE8), ctor FUN_14053A6C4,
 * global DAT_140A59880
 * Not in GROUP for state_surface (ccSound:: methods are separate from ccSound_Sub)
 * Size 0x2AE8 from allocator; embeds ccSound_Sub internally
 * ========================================================================= */
struct __attribute__((packed)) ccSound {
    /* 0x0000 */ uint8_t data[0x2AE8];  /* opaque: full layout requires dedicated state_surface pass */
};

static_assert(sizeof(ccSound) == 0x2AE8, "ccSound size");

#endif /* CCSOUNDFAMILY_S2_H */