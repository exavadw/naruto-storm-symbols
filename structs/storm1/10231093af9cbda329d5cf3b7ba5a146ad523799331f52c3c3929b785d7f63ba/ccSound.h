/*
 * ccSound — NARUTO STORM 1 (NSUNS1.exe, build s1)
 * Reconstructed from Ghidra decompilation via the decompiler cache state_surface + manual analysis.
 * Object size: 0x2B20 (from ccSound::Create allocator call FUN_14047ed10(0x2b20,...))
 * All fields INFERRED from static analysis; not runtime-confirmed.
 */
#ifndef CCSOUND_S1_H
#define CCSOUND_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ADX2Handle ADX2Handle;

/* Sub-struct at +0x78, size 0x70 (gap to next sub-struct at +0xE8) */
typedef struct { uint8_t data[0x70]; } ccSound_SubA;

/* Sub-struct at +0xE8, size 0x40 (gap to next at +0x128) */
typedef struct { uint8_t data[0x40]; } ccSound_SubB;

/* Sub-struct at +0x128, size 0x40 (gap to adx2Ptr at +0x168) */
typedef struct { uint8_t data[0x40]; } ccSound_SubC;

/* SE channel slot: 27 elements at +0xDC8, stride 0x38, total 0x5E8 -> ends at 0x13B0 */
typedef struct { uint8_t data[0x38]; } ccSound_SeChannel;

/* Stream SE slot: 16 elements at +0x13EC, stride 0x38, total 0x380 -> ends at 0x176C */
typedef struct { uint8_t data[0x38]; } ccSound_StreamSeSlot;

/* Character SE slot: 12 elements at +0x17B0, stride 0x38, total 0x2A0 -> ends at 0x1A50 */
typedef struct { uint8_t data[0x38]; } ccSound_CharSeSlot;

/* Figure SE slot: 2 elements at +0x1A50, stride 0x38, total 0x70 -> ends at 0x1AC0 */
typedef struct { uint8_t data[0x38]; } ccSound_FigureSeSlot;

/* Vtable sub-object: 2 elements at +0x1AD0, stride 0x20, vtable = PTR_FUN_14073c2b8 */
typedef struct {
    void *vtable;       /* 0x00 */
    uint64_t unk_08;    /* 0x08 */
    uint64_t unk_10;    /* 0x10 */
    uint64_t unk_18;    /* 0x18 */
} ccSound_VtableObj;    /* 0x20 bytes */

/* Volume slot: 128 elements at +0x1B18, stride 0x20, total 0x1000 -> ends at 0x2B18 */
typedef struct { uint8_t data[0x20]; } ccSound_VolumeSlot;

/*
 * ccSound — main sound manager singleton for Storm 1.
 *
 * Ctor param_1 typing varies per function in Ghidra output:
 *   - ctor: undefined4* (uint32 indexing, param_1[N] = byte offset N*4)
 *   - SetBgmVolume/SetVoiceVolume: float* (float indexing)
 *   - InitializeADX2/StopBgm/etc: longlong/byte pointer (direct byte offsets)
 * All offsets below are BYTE offsets, cross-verified across multiple functions.
 */
typedef struct {
    /* === Volume/config block: 0x0000-0x002F === */
    /* 0x0000 */ float masterVolume;      /* ctor: *(float*)p = 0x3e99999a (~0.3f); InitADX2: *p * 0.8 -> adx2+0xc4 */
    /* 0x0004 */ float bgmVolume;         /* SetBgmVolume: *(float*)(p+4) = vol; InitADX2: p[1]*0.8 -> adx2+0xc8 */
    /* 0x0008 */ float seVolume;          /* InitADX2: p[2] -> adx2+0xcc; ctor: uint32[2]=1.0f */
    /* 0x000C */ float movieVolume;       /* ctor: uint32[3]=1.0f */
    /* 0x0010 */ float voiceVolume;       /* ctor: uint32[4]=1.0f */
    /* 0x0014 */ float unkVolume_14;      /* ctor: uint32[5]=1.0f; InitADX2: p[5]*0.5 -> adx2+0xd0 */
    /* 0x0018 */ int32_t maxChannels;     /* ctor: uint32[6]=0x100 (256) */
    /* 0x001C */ int32_t unk_001c;        /* ctor: uint32[7] — not explicitly set */
    /* 0x0020 */ int32_t unk_0020;        /* ctor: uint32[8]=0 */
    /* 0x0024 */ int32_t unk_0024;        /* low half of ctor *(uint64*)(uint32_ptr+9)=1 */
    /* 0x0028 */ int64_t unk_0028;        /* natural align to 0x28; high half overlaps ctor write */
    /* 0x0030 */ uint8_t pad_0030[0x0C];  /* gap to 0x3C */

    /* === Misc scalars: 0x003C-0x0077 === */
    /* 0x003C */ uint8_t unk_003c[0x0C];  /* gap to 0x48 */
    /* 0x0048 */ int32_t unk_0048;
    /* 0x004C */ int32_t unk_004c;
    /* 0x0050 */ int32_t unk_0050;
    /* 0x0054 */ int32_t activeBgmIds[7]; /* 0x54..0x6F, 7 BGM ID slots */
    /* 0x0070 */ int32_t unk_0070;
    /* 0x0074 */ uint8_t pad_0074[0x04];  /* align to 0x78 */

    /* === Sub-structs: 0x0078-0x0167 === */
    /* 0x0078 */ ccSound_SubA subA;       /* size 0x70, ends at 0xE8 */
    /* 0x00E8 */ ccSound_SubB subB;       /* size 0x40, ends at 0x128 */
    /* 0x0128 */ ccSound_SubC subC;       /* size 0x40, ends at 0x168 */

    /* === ADX2 handle: 0x0168-0x0177 === */
    /* 0x0168 */ ADX2Handle *adx2Ptr;
    /* 0x0170 */ uint8_t pad_0170[0x08];  /* gap to 0x178 */

    /* === 3D SE region: 0x0178-0x0D73 === */
    /* 0x0178 */ uint8_t se3dRegion[0xBFC]; /* large embedded region, ends at 0xD74 */

    /* === Mid block: 0x0D74-0x0DC7 (consolidated to avoid alignment gaps) === */
    /* 0x0D74 */ uint8_t midBlock[0x54];  /* covers scalars/gaps between se3dRegion and seChannels */

    /* === SE channel arrays: 0x0DC8-0x1ACF === */
    /* 0x0DC8 */ ccSound_SeChannel seChannels[27];     /* stride 0x38, total 0x5E8, ends at 0x13B0 */
    /* 0x13B0 */ uint8_t pad_13b0[0x3C];               /* gap 0x13B0..0x13EC */
    /* 0x13EC */ ccSound_StreamSeSlot streamSeSlots[16]; /* stride 0x38, total 0x380, ends at 0x176C */
    /* 0x176C */ uint8_t pad_176c[0x44];               /* gap 0x176C..0x17B0 */
    /* 0x17B0 */ ccSound_CharSeSlot charSeSlots[12];   /* stride 0x38, total 0x2A0, ends at 0x1A50 */
    /* 0x1A50 */ ccSound_FigureSeSlot figureSeSlots[2]; /* stride 0x38, total 0x70, ends at 0x1AC0 */

    /* === Vtable objects + tail: 0x1AC0-0x2B1F === */
    /* 0x1AC0 */ int64_t unk_1ac0;
    /* 0x1AC8 */ int64_t unk_1ac8;
    /* 0x1AD0 */ ccSound_VtableObj vtableObjs[2];      /* stride 0x20, total 0x40, ends at 0x1B10 */
    /* 0x1B10 */ int32_t unk_1b10;
    /* 0x1B14 */ uint8_t pad_1b14[0x04];               /* align to 0x1B18 */
    /* 0x1B18 */ ccSound_VolumeSlot volumeSlots[128];  /* stride 0x20, total 0x1000, ends at 0x2B18 */
    /* 0x2B18 */ int32_t unk_2b18;
    /* 0x2B1C */ int32_t unk_2b1c;
} ccSound;

/* Compile-time layout verification — all offsets confirmed via gcc diagnostic */
static_assert(sizeof(ccSound) == 0x2B20, "ccSound size must be 0x2B20");
static_assert(offsetof(ccSound, masterVolume)    == 0x0000, "masterVolume at 0x00");
static_assert(offsetof(ccSound, bgmVolume)       == 0x0004, "bgmVolume at 0x04");
static_assert(offsetof(ccSound, seVolume)        == 0x0008, "seVolume at 0x08");
static_assert(offsetof(ccSound, movieVolume)     == 0x000C, "movieVolume at 0x0C");
static_assert(offsetof(ccSound, voiceVolume)     == 0x0010, "voiceVolume at 0x10");
static_assert(offsetof(ccSound, unkVolume_14)    == 0x0014, "unkVolume_14 at 0x14");
static_assert(offsetof(ccSound, maxChannels)     == 0x0018, "maxChannels at 0x18");
static_assert(offsetof(ccSound, unk_001c)        == 0x001C, "unk_001c at 0x1C");
static_assert(offsetof(ccSound, unk_0020)        == 0x0020, "unk_0020 at 0x20");
static_assert(offsetof(ccSound, unk_0024)        == 0x0024, "unk_0024 at 0x24");
static_assert(offsetof(ccSound, unk_0028)        == 0x0028, "unk_0028 at 0x28");
static_assert(offsetof(ccSound, unk_003c)        == 0x003C, "unk_003c at 0x3C");
static_assert(offsetof(ccSound, unk_0048)        == 0x0048, "unk_0048 at 0x48");
static_assert(offsetof(ccSound, activeBgmIds)    == 0x0054, "activeBgmIds at 0x54");
static_assert(offsetof(ccSound, subA)            == 0x0078, "subA at 0x78");
static_assert(offsetof(ccSound, subB)            == 0x00E8, "subB at 0xE8");
static_assert(offsetof(ccSound, subC)            == 0x0128, "subC at 0x128");
static_assert(offsetof(ccSound, adx2Ptr)         == 0x0168, "adx2Ptr at 0x168");
static_assert(offsetof(ccSound, se3dRegion)      == 0x0178, "se3dRegion at 0x178");
static_assert(offsetof(ccSound, midBlock)        == 0x0D74, "midBlock at 0xD74");
static_assert(offsetof(ccSound, seChannels)      == 0x0DC8, "seChannels at 0xDC8");
static_assert(offsetof(ccSound, streamSeSlots)   == 0x13EC, "streamSeSlots at 0x13EC");
static_assert(offsetof(ccSound, charSeSlots)     == 0x17B0, "charSeSlots at 0x17B0");
static_assert(offsetof(ccSound, figureSeSlots)   == 0x1A50, "figureSeSlots at 0x1A50");
static_assert(offsetof(ccSound, vtableObjs)      == 0x1AD0, "vtableObjs at 0x1AD0");
static_assert(offsetof(ccSound, volumeSlots)     == 0x1B18, "volumeSlots at 0x1B18");
static_assert(offsetof(ccSound, unk_2b18)        == 0x2B18, "unk_2b18 at 0x2B18");
static_assert(offsetof(ccSound, unk_2b1c)        == 0x2B1C, "unk_2b1c at 0x2B1C");

#endif /* CCSOUND_S1_H */