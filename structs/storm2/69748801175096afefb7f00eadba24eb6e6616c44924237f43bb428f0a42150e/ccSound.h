/*
 * ccSound — NARUTO STORM 2 PC (NSUNS2.exe, build s2)
 * Reconstructed from static analysis (Ghidra + the decompiler cache). ALL fields INFERRED.
 * Object size: 0x2AE8 (from ccFileLoadListForUi::LoadTh allocator in Create)
 */
#ifndef CCSOUND_S2_H
#define CCSOUND_S2_H

#include <stdint.h>
#include <stddef.h>

#pragma pack(push, 1)

/* Forward declarations for opaque sub-objects */
typedef struct ccSound_SubObjectB0 { uint8_t data[0xB0]; } ccSound_SubObjectB0;

typedef struct ccSound {
    /* === Volume / config block: 0x00–0x1B === */
    float       masterVolume;           /* 0x0000 */
    float       bgmVolume;              /* 0x0004 */
    float       seVolume;               /* 0x0008 */
    float       movieVolume;            /* 0x000C */
    float       voiceVolume;            /* 0x0010 */
    float       unkVolume_14;           /* 0x0014 */
    int32_t     maxChannels;            /* 0x0018 */
    int32_t     regionFlag;             /* 0x001C */

    /* 0x0020 */
    int32_t     unk_0020;               /* 0x0020 */
    int64_t     unk_0024;               /* 0x0024 */

    uint8_t     pad_002c[0x20];         /* 0x002C – gap to BGM handle IDs */

    /* BGM handle IDs: 3 slots (PlayBgm loop < 3) */
    int32_t     bgmHandleIds[3];        /* 0x004C */

    uint8_t     pad_0058[0x10];         /* 0x0058 */

    /* Active BGM IDs: 3 slots (PlayBgm loop < 3) */
    int32_t     activeBgmIds[3];        /* 0x0068 */

    uint8_t     pad_0074[0x10];         /* 0x0074 */

    /* BGM slot markers: 3 int32 (PlayBgm loop < 3, ctor inits to -1) */
    int32_t     bgmSlotMarkers[3];      /* 0x0084 */

    uint8_t     pad_0090[0x04];         /* 0x0090 */

    int32_t     unk_0094;               /* 0x0094 */
    int32_t     unk_0098;               /* 0x0098 */
    int64_t     unk_009c;               /* 0x009C */
    int32_t     unk_00a4;               /* 0x00A4 */
    int32_t     distanceScale;          /* 0x00A8 – ctor sets 100 */
    int32_t     unk_00ac;               /* 0x00AC */

    /* Sub-object initialised by FUN_14053a85c(param_1+0x2c) → byte 0xB0 */
    ccSound_SubObjectB0 subObject_b0;   /* 0x00B0 */

    uint8_t     pad_0160[0xE0];         /* 0x0160 – gap to adx2Ptr */

    /* ADX2 engine handle pointer (SetBgmVolume/SetMainVolume/PlayBgm) */
    void       *adx2Ptr;                /* 0x0240 */

    uint8_t     pad_0248[0xE00];        /* 0x0248 – large gap to SE slots */

    /* SE / CHandle array: 128 elements, stride 0x20 (ctor loop 0x7f+1) */
    uint8_t     seSlots[0x1000];        /* 0x1048 */

    /* BlockAllocator array: 36 elements, stride 0x48 (ctor loop 0x23+1) */
    uint8_t     blockAllocators[0xA20]; /* 0x2048 */

    uint8_t     pad_2a68[0x04];         /* 0x2A68 */

    /* Tail scalars from ctor */
    int32_t     tail_2a6c;              /* 0x2A6C */
    int32_t     tail_2a70;              /* 0x2A70 */
    int32_t     tail_2a74;              /* 0x2A74 */
    int64_t     tail_2a78;              /* 0x2A78 */
    int64_t     tail_2a80;              /* 0x2A80 */

    uint8_t     pad_2a88[0x04];         /* 0x2A88 */

    /* Stream SE control region (SeAllOffStr: uint* at 0x2A8C, undef4* at 0x2AB0, 5 iters) */
    uint8_t     streamSeCtrl[0x28];     /* 0x2A8C */

    uint8_t     pad_2ab4[0x10];         /* 0x2AB4 */

    int64_t     tail_2ac4;              /* 0x2AC4 */
    int64_t     tail_2acc;              /* 0x2ACC */
    int32_t     tail_2ad4;              /* 0x2AD4 */
    int64_t     tail_2ad8;              /* 0x2AD8 */
    int64_t     tail_2ae0;              /* 0x2AE0 */
} ccSound;

#pragma pack(pop)

/* Compile-time layout verification */
_Static_assert(sizeof(ccSound) == 0x2AE8, "ccSound s2 size must be 0x2AE8");
_Static_assert(offsetof(ccSound, masterVolume)     == 0x0000, "masterVolume offset");
_Static_assert(offsetof(ccSound, bgmVolume)        == 0x0004, "bgmVolume offset");
_Static_assert(offsetof(ccSound, seVolume)         == 0x0008, "seVolume offset");
_Static_assert(offsetof(ccSound, movieVolume)      == 0x000C, "movieVolume offset");
_Static_assert(offsetof(ccSound, voiceVolume)      == 0x0010, "voiceVolume offset");
_Static_assert(offsetof(ccSound, unkVolume_14)     == 0x0014, "unkVolume_14 offset");
_Static_assert(offsetof(ccSound, maxChannels)      == 0x0018, "maxChannels offset");
_Static_assert(offsetof(ccSound, regionFlag)       == 0x001C, "regionFlag offset");
_Static_assert(offsetof(ccSound, unk_0020)         == 0x0020, "unk_0020 offset");
_Static_assert(offsetof(ccSound, unk_0024)         == 0x0024, "unk_0024 offset");
_Static_assert(offsetof(ccSound, bgmHandleIds)     == 0x004C, "bgmHandleIds offset");
_Static_assert(offsetof(ccSound, activeBgmIds)     == 0x0068, "activeBgmIds offset");
_Static_assert(offsetof(ccSound, bgmSlotMarkers)   == 0x0084, "bgmSlotMarkers offset");
_Static_assert(offsetof(ccSound, unk_0094)         == 0x0094, "unk_0094 offset");
_Static_assert(offsetof(ccSound, unk_0098)         == 0x0098, "unk_0098 offset");
_Static_assert(offsetof(ccSound, unk_009c)         == 0x009C, "unk_009c offset");
_Static_assert(offsetof(ccSound, unk_00a4)         == 0x00A4, "unk_00a4 offset");
_Static_assert(offsetof(ccSound, distanceScale)    == 0x00A8, "distanceScale offset");
_Static_assert(offsetof(ccSound, unk_00ac)         == 0x00AC, "unk_00ac offset");
_Static_assert(offsetof(ccSound, subObject_b0)     == 0x00B0, "subObject_b0 offset");
_Static_assert(offsetof(ccSound, adx2Ptr)          == 0x0240, "adx2Ptr offset");
_Static_assert(offsetof(ccSound, seSlots)          == 0x1048, "seSlots offset");
_Static_assert(offsetof(ccSound, blockAllocators)  == 0x2048, "blockAllocators offset");
_Static_assert(offsetof(ccSound, tail_2a6c)        == 0x2A6C, "tail_2a6c offset");
_Static_assert(offsetof(ccSound, tail_2a70)        == 0x2A70, "tail_2a70 offset");
_Static_assert(offsetof(ccSound, tail_2a74)        == 0x2A74, "tail_2a74 offset");
_Static_assert(offsetof(ccSound, tail_2a78)        == 0x2A78, "tail_2a78 offset");
_Static_assert(offsetof(ccSound, tail_2a80)        == 0x2A80, "tail_2a80 offset");
_Static_assert(offsetof(ccSound, streamSeCtrl)     == 0x2A8C, "streamSeCtrl offset");
_Static_assert(offsetof(ccSound, tail_2ac4)        == 0x2AC4, "tail_2ac4 offset");
_Static_assert(offsetof(ccSound, tail_2acc)        == 0x2ACC, "tail_2acc offset");
_Static_assert(offsetof(ccSound, tail_2ad4)        == 0x2AD4, "tail_2ad4 offset");
_Static_assert(offsetof(ccSound, tail_2ad8)        == 0x2AD8, "tail_2ad8 offset");
_Static_assert(offsetof(ccSound, tail_2ae0)        == 0x2AE0, "tail_2ae0 offset");

#endif /* CCSOUND_S2_H */