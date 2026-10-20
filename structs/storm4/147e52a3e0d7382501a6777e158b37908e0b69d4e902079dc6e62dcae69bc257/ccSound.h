/*
 * ccSound — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 * Reconstructed from static analysis (Ghidra + the decompiler cache). ALL fields INFERRED.
 * Object size: 0x3230 (from operator_new(0x3230,...) in ccSound::Create)
 *
 * Ctor typing notes:
 * - ccSound::ccSound types param_1 as undefined4*: param_1[N] = byte offset N*4
 * - InitializeADX2 types param_1 as float*: param_1[N] = byte offset N*4
 * - SetBgmVolume/SeAllOff type param_1 as longlong: direct byte offsets
 * All offsets below are BYTE offsets verified against decompiled code.
 * Natural x64 MSVC alignment (no pragma pack).
 */
#ifndef CCSOUND_S4_H
#define CCSOUND_S4_H

#include <stdint.h>
#include <stddef.h>

typedef struct ccSound {
    /* === Volume floats: 0x00–0x13 === */
    float       masterVolume;       /* 0x0000 ctor: *param_1 = 0x3e99999a (0.3f); SetVoiceVolume reads *param_1 */
    float       bgmVolume;          /* 0x0004 SetBgmVolume: *(float*)(p+4)=vol */
    float       voiceVolume;        /* 0x0008 SetVoiceVolume: param_1[2] as float* */
    float       unk_000c;           /* 0x000C ctor: param_1[3]=0x3f800000 (1.0f) */
    float       movieVolume;        /* 0x0010 GetMovieVolume: return *(u4*)(p+0x10); SeAllOff writes 0 */

    /* === Unknown region 0x14–0x27 === */
    uint8_t     unk_0014[8];        /* 0x0014 ctor: *(undef8*)(p+5)=0x3f800000 spans 0x14..0x1B */
    uint32_t    unk_001c;           /* 0x001C InitializeADX2: param_1[7] read (float*) */
    uint32_t    unk_0020;           /* 0x0020 InitializeADX2: param_1[8] written (float*) */
    uint32_t    unk_0024;           /* 0x0024 gap before undef8 block */

    /* === Config scalars: 0x28–0x3B === */
    uint64_t    unk_0028;           /* 0x0028 ctor: *(undef8*)(p+10)=1 */
    uint32_t    unk_0030;           /* 0x0030 ctor: param_1[0xc]=1 */
    uint32_t    unk_0034;           /* 0x0034 ctor loop: puVar1[-7]=0xffffffff (first iter) */
    uint32_t    unk_0038;           /* 0x0038 ctor loop region */
    uint32_t    unk_003c;           /* 0x003C ctor loop region */

    /* === Loop-init region continues: 0x40–0x6B === */
    uint8_t     unk_0040[0x2C];     /* 0x0040 ctor loop body fills 0x40..0x6B (7 iterations × 3 writes) */

    /* === BGM slot / channel region: 0x6C–0x8F === */
    uint32_t    unk_006c;           /* 0x006C ctor: param_1[0x1b]=0xffffffff */
    uint32_t    maxChannels;        /* 0x0070 SeAllOff: *(u4*)(p+0x70)=1 */
    uint32_t    unk_0074;           /* 0x0074 ctor: param_1[0x1d]=0xffffffff */
    uint32_t    unk_0078_lo;        /* 0x0078 SeAllOff: *(u8*)(p+0x78)=0 low half */
    uint32_t    unk_007c_hi;        /* 0x007C SeAllOff: *(u8*)(p+0x78)=0 high half; ctor param_1[0x1f]=0 */
    uint32_t    unk_0080;           /* 0x0080 SeAllOff: *(u4*)(p+0x80)=0xfffffc19; PlayBgmFadeIn array base */
    uint8_t     unk_0084[0xC];      /* 0x0084 gap to 0x90 */

    /* === Mid-region scalars: 0x90–0xBF === */
    uint8_t     unk_0090[0x18];     /* 0x0090 state_surface fields at 0x9C, 0xA4, 0xA8, 0xB0 */
    uint64_t    unk_00a8;           /* 0x00A8 ctor: *(undef8*)(p+0x2a)=0xffffffffffffffff */
    uint64_t    unk_00b0;           /* 0x00B0 ctor: *(undef8*)(p+0x2c)=0xffffffffffffffff */
    uint32_t    unk_00b8;           /* 0x00B8 ctor: param_1[0x2e]=0xffffffff */
    uint32_t    distanceScale;      /* 0x00BC ctor: param_1[0x2f]=100 */

    /* === Region 0xC0–0xDF === */
    uint8_t     unk_00c0[0x20];     /* 0x00C0 state_surface fields at 0xC0, 0xC8, 0xCC, 0xD0, 0xD4, 0xD8, 0xDC */

    /* === ADX2 engine pointer: 0xE0–0xEF === */
    float       unk_00e0;           /* 0x00E0 InitializeADX2: param_1[0x38]=0.0 (float*) */
    uint32_t    pad_00e4;           /* 0x00E4 align pad for pointer */
    void       *adx2Engine;         /* 0x00E8 SetBgmVolume: *(longlong*)(p+0xe8); InitADX2: *(longlong*)(p+0x3a) float* */

    /* === SE slots array: 128 elements × 0x20 stride = 0x1000 bytes === */
    uint8_t     seSlots[0x1000];    /* 0x00F0 ctor: memset(param_1+0x3c, 0, 0x1000); undefined4* 0x3c*4=0xF0 */

    /* === CHandle array: 128 elements × 0x20 stride = 0x1000 bytes === */
    uint8_t     chandleArray[0x1000]; /* 0x10F0 ctor: CHandle loop at param_1+0x43c (0x10F0), 128 iters × 32 bytes */

    /* === Sub-object regions === */
    uint8_t     subObject_20f0[0x48]; /* 0x20F0 ctor: FUN_14061bb64(param_1+0x83c); 0x83c*4=0x20F0 */
    uint8_t     subObject_2138[0xC0]; /* 0x2138 ctor: FUN_14073993c(param_1+0x84e); 0x84e*4=0x2138; ends at 0x21F8 */

    /* === Entry bank / mid-tail region: 0x21F8–0x320B === */
    uint8_t     unk_21f8[0x1014];   /* 0x21F8 large gap; state_surface hints at 0x21F8, 0x2200; ends at 0x320C */

    /* === Tail scalars: 0x320C–0x322F === */
    uint8_t     tail_320c[0x1C];    /* 0x320C ctor: param_1[0xc83..0xc8a] writes; 0xc83*4=0x320C */
    float       distanceScaleLive;  /* 0x3228 SetDistanceScale: *(float*)(p+0x3228)=param_2 */
    uint8_t     pad_322c[4];        /* 0x322C trailing pad to reach 0x3230 */
} ccSound;

/* Compile-time layout verification */
_Static_assert(sizeof(ccSound) == 0x3230, "ccSound s4 size must be 0x3230");
_Static_assert(offsetof(ccSound, masterVolume) == 0x0000, "masterVolume");
_Static_assert(offsetof(ccSound, bgmVolume) == 0x0004, "bgmVolume");
_Static_assert(offsetof(ccSound, voiceVolume) == 0x0008, "voiceVolume");
_Static_assert(offsetof(ccSound, unk_000c) == 0x000C, "unk_000c");
_Static_assert(offsetof(ccSound, movieVolume) == 0x0010, "movieVolume");
_Static_assert(offsetof(ccSound, unk_0014) == 0x0014, "unk_0014");
_Static_assert(offsetof(ccSound, unk_001c) == 0x001C, "unk_001c");
_Static_assert(offsetof(ccSound, unk_0020) == 0x0020, "unk_0020");
_Static_assert(offsetof(ccSound, unk_0024) == 0x0024, "unk_0024");
_Static_assert(offsetof(ccSound, unk_0028) == 0x0028, "unk_0028");
_Static_assert(offsetof(ccSound, unk_0030) == 0x0030, "unk_0030");
_Static_assert(offsetof(ccSound, unk_0034) == 0x0034, "unk_0034");
_Static_assert(offsetof(ccSound, unk_0038) == 0x0038, "unk_0038");
_Static_assert(offsetof(ccSound, unk_003c) == 0x003C, "unk_003c");
_Static_assert(offsetof(ccSound, unk_0040) == 0x0040, "unk_0040");
_Static_assert(offsetof(ccSound, unk_006c) == 0x006C, "unk_006c");
_Static_assert(offsetof(ccSound, maxChannels) == 0x0070, "maxChannels");
_Static_assert(offsetof(ccSound, unk_0074) == 0x0074, "unk_0074");
_Static_assert(offsetof(ccSound, unk_0078_lo) == 0x0078, "unk_0078_lo");
_Static_assert(offsetof(ccSound, unk_007c_hi) == 0x007C, "unk_007c_hi");
_Static_assert(offsetof(ccSound, unk_0080) == 0x0080, "unk_0080");
_Static_assert(offsetof(ccSound, unk_0084) == 0x0084, "unk_0084");
_Static_assert(offsetof(ccSound, unk_0090) == 0x0090, "unk_0090");
_Static_assert(offsetof(ccSound, unk_00a8) == 0x00A8, "unk_00a8");
_Static_assert(offsetof(ccSound, unk_00b0) == 0x00B0, "unk_00b0");
_Static_assert(offsetof(ccSound, unk_00b8) == 0x00B8, "unk_00b8");
_Static_assert(offsetof(ccSound, distanceScale) == 0x00BC, "distanceScale");
_Static_assert(offsetof(ccSound, unk_00c0) == 0x00C0, "unk_00c0");
_Static_assert(offsetof(ccSound, unk_00e0) == 0x00E0, "unk_00e0");
_Static_assert(offsetof(ccSound, pad_00e4) == 0x00E4, "pad_00e4");
_Static_assert(offsetof(ccSound, adx2Engine) == 0x00E8, "adx2Engine");
_Static_assert(offsetof(ccSound, seSlots) == 0x00F0, "seSlots");
_Static_assert(offsetof(ccSound, chandleArray) == 0x10F0, "chandleArray");
_Static_assert(offsetof(ccSound, subObject_20f0) == 0x20F0, "subObject_20f0");
_Static_assert(offsetof(ccSound, subObject_2138) == 0x2138, "subObject_2138");
_Static_assert(offsetof(ccSound, unk_21f8) == 0x21F8, "unk_21f8");
_Static_assert(offsetof(ccSound, tail_320c) == 0x320C, "tail_320c");
_Static_assert(offsetof(ccSound, distanceScaleLive) == 0x3228, "distanceScaleLive");
_Static_assert(offsetof(ccSound, pad_322c) == 0x322C, "pad_322c");

#endif /* CCSOUND_S4_H */