/*
 * ccSound — NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, build s3)
 * Reconstructed from static analysis (Ghidra + the decompiler cache). ALL fields INFERRED.
 * Object size: 0x22C0 (from FUN_140683f70(0x22c0,...) in ccSound::Create)
 *
 * Ctor typing notes:
 * - ccSound::ccSound types param_1 as undefined4*: param_1[N] = byte offset N*4
 * - SetVoiceVolume types param_1 as float*: param_1[N] = byte offset N*4
 * - SetBgmVolume/SeAllOff/PlayBgm type param_1 as longlong/byte*: direct byte offsets
 * All offsets below are BYTE offsets verified against decompiled code.
 * Natural x64 MSVC alignment (no pragma pack).
 */
#ifndef CCSOUND_S3_H
#define CCSOUND_S3_H

#include <stdint.h>
#include <stddef.h>

typedef struct ccSound {
    /* === Volume floats: 0x00–0x13 === */
    float       masterVolume;       /* 0x0000 ctor: *param_1 = 0x3e99999a (0.3f) */
    float       bgmVolume;          /* 0x0004 SetBgmVolume: *(float*)(p+4)=vol */
    float       voiceVolume;        /* 0x0008 SetVoiceVolume: param_1[2] as float* */
    float       movieVolume;        /* 0x000C GetMovieVolume: return *(u32*)(p+0x10) */
    float       seVolume;           /* 0x0010 ctor param_1[4]=1.0f */
    uint8_t     pad_0014[4];        /* 0x0014 ctor *(undef8*)(p+5)=0x3f800000 spans 0x14..0x17 */

    /* === Config scalars: 0x0018–0x0027 === */
    int32_t     maxChannels;        /* 0x0018 SeAllOff: *(u4*)(p+0x18)=1 */
    int32_t     regionFlag;         /* 0x001C SeAllOff: *(u8*)(p+0x1c)=3 */
    int32_t     unk_0020;           /* 0x0020 state_surface field */
    int32_t     unk_0024;           /* 0x0024 SeAllOff: *(u4*)(p+0x24)=0 */
    uint8_t     pad_0028[8];        /* 0x0028 gap; ctor *(undef8*)(p+10)=1 at byte 0x28 */

    /* === Early state: 0x0030–0x003B === */
    int64_t     unk_0030;           /* 0x0030 ctor *(undef8*)(p+0xc)=1 */
    uint8_t     pad_0038[4];        /* 0x0038 gap to loop region */

    /* === Loop-init region (ctor puVar1 loop, 7 iterations): 0x003C–0x0073 === */
    int32_t     unk_003c;           /* 0x003C ctor loop first iter */
    int32_t     unk_0040;           /* 0x0040 */
    int32_t     unk_0044;           /* 0x0044 */
    int32_t     unk_0048;           /* 0x0048 */
    int32_t     unk_004c;           /* 0x004C */
    int32_t     unk_0050;           /* 0x0050 */
    int32_t     unk_0054;           /* 0x0054 */
    int32_t     unk_0058;           /* 0x0058 */
    uint8_t     pad_005c[24];       /* 0x005C remaining loop coverage gap → 0x0074 */

    /* === BGM slot cursor region: 0x0074–0x008F === */
    int32_t     unk_0074;           /* 0x0074 ctor param_1[0x1d]=-1 */
    int32_t     unk_0078;           /* 0x0078 ctor param_1[0x1e]=-1 */
    int32_t     unk_007c;           /* 0x007C ctor param_1[0x1f]=-1 */
    int32_t     unk_0080;           /* 0x0080 ctor param_1[0x20]=1.0f */
    int32_t     bgmSlotCursor;      /* 0x0084 PlayBgm: iVar1=*(int*)(p+0x84) */
    uint8_t     pad_0088[8];        /* 0x0088 gap → 0x0090 */

    /* === BGM queue vector: 0x0090–0x00A7 === */
    int64_t     bgmQueue_begin;     /* 0x0090 PlayBgm: *(longlong*)(p+0x90) */
    int64_t     bgmQueue_end;       /* 0x0098 PlayBgm: *(longlong*)(p+0x98) */
    uint8_t     pad_00a0[8];        /* 0x00A0 gap → 0x00A8 (align for int64) */

    /* === Mid-region scalars: 0x00A8–0x00B7 === */
    int64_t     unk_00a8;           /* 0x00A8 ctor *(undef8*)(p+0x29)=-1 */
    int32_t     unk_00b0;           /* 0x00B0 ctor param_1[0x2b]=-1 */
    int32_t     distanceScale;      /* 0x00B4 ctor param_1[0x2c]=100 */

    /* === Sub-object at 0xB8 (FUN_140496ec0 on param_1+0x2e = byte 0xB8) === */
    uint8_t     subObject_b8[0x190];/* 0x00B8 opaque, 400 bytes → ends at 0x0248 */

    /* === ADX2 engine pointer: 0x0248 === */
    void       *adx2Engine;         /* 0x0248 SetBgmVolume: *(longlong*)(p+0x248) */
    uint8_t     pad_0250[0x1D4];    /* 0x0250 gap → 0x0424 */

    /* === SE / CHandle array: 128 elements × 0x20 stride === */
    uint8_t     seSlots[0x1000];    /* 0x0424 128 * 0x20 = 0x1000 bytes → ends at 0x1424 */
    uint8_t     pad_1424[0xC3C];    /* 0x1424 gap → 0x2060 */

    /* === BlockAllocator / sub-object region === */
    uint8_t     subRegion_2060[0x78];/* 0x2060 FUN_140490ca0(p+0x814), etc. */
    uint8_t     pad_20d8[0x18];     /* 0x20D8 gap → 0x20F0 */

    /* === EntryBank arrays (from ccSound::EntryBank decompile) === */
    uint8_t     entryBankArr_20f0[0x80]; /* 0x20F0 EntryBank: p+0x20f0+param_4*8, 16 ptrs */
    uint8_t     entryBankArr_2170[0x80]; /* 0x2170 EntryBank: p+0x2170+param_4*8, 16 ptrs */
    uint8_t     entryBankList_21f0[0x28];/* 0x21F0 FUN_14049aac4((longlong*)(p+0x21f0),...) */
    uint8_t     entryBankList_2218[0x28];/* 0x2218 FUN_14049aac4((longlong*)(p+0x2218),...) */

    /* === Tail scalars: 0x2240–0x225F === */
    int32_t     tail_2240;          /* 0x2240 ctor param_1[0x890]=-1 */
    int32_t     tail_2244;          /* 0x2244 ctor param_1[0x891]=-1 */
    int32_t     tail_2248;          /* 0x2248 ctor param_1[0x892]=0 */
    uint8_t     pad_224c[4];        /* 0x224C align pad → 0x2250 */
    int64_t     tail_2250;          /* 0x2250 ctor *(undef8*)(p+0x894)=0 */
    int64_t     tail_2258;          /* 0x2258 ctor *(undef8*)(p+0x896)=0 */
    uint8_t     pad_2260[0x28];     /* 0x2260 gap → 0x2288 */

    /* === Stream SE control region === */
    int32_t     streamSe_2288;      /* 0x2288 ctor param_1[0x8a2]=-1 */
    int32_t     streamSe_228c;      /* 0x228C */
    int32_t     streamSe_2290;      /* 0x2290 */
    int32_t     streamSe_2294;      /* 0x2294 */
    int32_t     streamSe_2298;      /* 0x2298 */
    uint8_t     pad_229c[4];        /* 0x229C gap → 0x22A0 */
    uint8_t     streamSe_22a0[8];   /* 0x22A0 ctor *(undef8*)(p+0x8a9)=-1 (relaxed align) */
    int32_t     streamSe_22a8;      /* 0x22A8 ctor param_1[0x8ab]=-1 */
    uint8_t     pad_22ac[4];        /* 0x22AC gap → 0x22B0 */
    uint8_t     tail_22b0[8];       /* 0x22B0 ctor *(undef8*)(p+0x8ae)=0 */

    /* Trailing padding to reach 0x22C0 */
    uint8_t     _pad_tail[8];       /* 0x22B8 → struct ends at 0x22C0 */
} ccSound;

/* Compile-time layout verification */
_Static_assert(sizeof(ccSound) == 0x22C0, "ccSound s3 size must be 0x22C0");
_Static_assert(offsetof(ccSound, masterVolume) == 0x0000, "masterVolume");
_Static_assert(offsetof(ccSound, bgmVolume) == 0x0004, "bgmVolume");
_Static_assert(offsetof(ccSound, voiceVolume) == 0x0008, "voiceVolume");
_Static_assert(offsetof(ccSound, movieVolume) == 0x000C, "movieVolume");
_Static_assert(offsetof(ccSound, seVolume) == 0x0010, "seVolume");
_Static_assert(offsetof(ccSound, maxChannels) == 0x0018, "maxChannels");
_Static_assert(offsetof(ccSound, regionFlag) == 0x001C, "regionFlag");
_Static_assert(offsetof(ccSound, unk_0020) == 0x0020, "unk_0020");
_Static_assert(offsetof(ccSound, unk_0024) == 0x0024, "unk_0024");
_Static_assert(offsetof(ccSound, unk_0030) == 0x0030, "unk_0030");
_Static_assert(offsetof(ccSound, unk_003c) == 0x003C, "unk_003c");
_Static_assert(offsetof(ccSound, unk_0040) == 0x0040, "unk_0040");
_Static_assert(offsetof(ccSound, unk_0044) == 0x0044, "unk_0044");
_Static_assert(offsetof(ccSound, unk_0048) == 0x0048, "unk_0048");
_Static_assert(offsetof(ccSound, unk_004c) == 0x004C, "unk_004c");
_Static_assert(offsetof(ccSound, unk_0050) == 0x0050, "unk_0050");
_Static_assert(offsetof(ccSound, unk_0054) == 0x0054, "unk_0054");
_Static_assert(offsetof(ccSound, unk_0058) == 0x0058, "unk_0058");
_Static_assert(offsetof(ccSound, unk_0074) == 0x0074, "unk_0074");
_Static_assert(offsetof(ccSound, unk_0078) == 0x0078, "unk_0078");
_Static_assert(offsetof(ccSound, unk_007c) == 0x007C, "unk_007c");
_Static_assert(offsetof(ccSound, unk_0080) == 0x0080, "unk_0080");
_Static_assert(offsetof(ccSound, bgmSlotCursor) == 0x0084, "bgmSlotCursor");
_Static_assert(offsetof(ccSound, bgmQueue_begin) == 0x0090, "bgmQueue_begin");
_Static_assert(offsetof(ccSound, bgmQueue_end) == 0x0098, "bgmQueue_end");
_Static_assert(offsetof(ccSound, unk_00a8) == 0x00A8, "unk_00a8");
_Static_assert(offsetof(ccSound, unk_00b0) == 0x00B0, "unk_00b0");
_Static_assert(offsetof(ccSound, distanceScale) == 0x00B4, "distanceScale");
_Static_assert(offsetof(ccSound, subObject_b8) == 0x00B8, "subObject_b8");
_Static_assert(offsetof(ccSound, adx2Engine) == 0x0248, "adx2Engine");
_Static_assert(offsetof(ccSound, seSlots) == 0x0424, "seSlots");
_Static_assert(offsetof(ccSound, subRegion_2060) == 0x2060, "subRegion_2060");
_Static_assert(offsetof(ccSound, entryBankArr_20f0) == 0x20F0, "entryBankArr_20f0");
_Static_assert(offsetof(ccSound, entryBankArr_2170) == 0x2170, "entryBankArr_2170");
_Static_assert(offsetof(ccSound, entryBankList_21f0) == 0x21F0, "entryBankList_21f0");
_Static_assert(offsetof(ccSound, entryBankList_2218) == 0x2218, "entryBankList_2218");
_Static_assert(offsetof(ccSound, tail_2240) == 0x2240, "tail_2240");
_Static_assert(offsetof(ccSound, tail_2244) == 0x2244, "tail_2244");
_Static_assert(offsetof(ccSound, tail_2248) == 0x2248, "tail_2248");
_Static_assert(offsetof(ccSound, tail_2250) == 0x2250, "tail_2250");
_Static_assert(offsetof(ccSound, tail_2258) == 0x2258, "tail_2258");
_Static_assert(offsetof(ccSound, streamSe_2288) == 0x2288, "streamSe_2288");
_Static_assert(offsetof(ccSound, streamSe_228c) == 0x228C, "streamSe_228c");
_Static_assert(offsetof(ccSound, streamSe_2290) == 0x2290, "streamSe_2290");
_Static_assert(offsetof(ccSound, streamSe_2294) == 0x2294, "streamSe_2294");
_Static_assert(offsetof(ccSound, streamSe_2298) == 0x2298, "streamSe_2298");
_Static_assert(offsetof(ccSound, streamSe_22a0) == 0x22A0, "streamSe_22a0");
_Static_assert(offsetof(ccSound, streamSe_22a8) == 0x22A8, "streamSe_22a8");
_Static_assert(offsetof(ccSound, tail_22b0) == 0x22B0, "tail_22b0");

#endif /* CCSOUND_S3_H */