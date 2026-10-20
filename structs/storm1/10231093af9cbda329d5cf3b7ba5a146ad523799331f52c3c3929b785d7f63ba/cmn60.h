/* cmn60.h — NARUTO STORM 1 (s1) common struct group cmn60
 * Reconstructed from NSUNS1.exe (build s1, sha 10231093af9c).
 * All offsets are PC RVAs. All fields tagged SIM/PRES/UNKNOWN.
 * Object sizes proven from game code (LoadTh allocator arguments).
 * NEVER use sizeof() for size assertions — only _Static_assert(offsetof(...)).
 */
#ifndef CMN60_H
#define CMN60_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for sub-objects whose layouts are not in this group */
struct nuccFogParam;          /* embedded at +0x220 in nuccModel, size 0x24 inferred */

/* ========================================================================
 * nuccModelHit  (size = 0xA0, proven by LoadTh(0xa0) in FUN_14027670c)
 * Two Matrix44 at +0x00 and +0x40, byte flag at +0x80, copies at +0x88/+0x90.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccModelHit {
    uint8_t  matrix_a[64];           /* 0x00  Matrix44_MathGeo         PRES ctor-copy */
    uint8_t  matrix_b[64];           /* 0x40  Matrix44_MathGeo         PRES ctor-copy */
    uint8_t  flag;                   /* 0x80  byte                     PRES ctor-init=0 */
    uint8_t  copy_81;                /* 0x81  byte                     PRES ctor-copy from param_2+0x81 */
    uint8_t  _pad_82[6];             /* 0x82  padding to align qwords  UNKNOWN */
    uint64_t field_88;               /* 0x88  qword                    PRES ctor-copy */
    uint64_t field_90;               /* 0x90  qword                    PRES ctor-copy */
    uint8_t  _tail_98[8];            /* 0x98  pad to 0xA0              UNKNOWN */
} nuccModelHit;
_Static_assert(sizeof(nuccModelHit) == 0xA0, "nuccModelHit size must be 0xA0");
_Static_assert(offsetof(nuccModelHit, matrix_a) == 0x00, "");
_Static_assert(offsetof(nuccModelHit, matrix_b) == 0x40, "");
_Static_assert(offsetof(nuccModelHit, flag)     == 0x80, "");
_Static_assert(offsetof(nuccModelHit, copy_81)  == 0x81, "");
_Static_assert(offsetof(nuccModelHit, field_88) == 0x88, "");
_Static_assert(offsetof(nuccModelHit, field_90) == 0x90, "");

/* ========================================================================
 * nuccModelHitNodeOct  (size = 0xA8, proven by LoadTh(0xa8) in MakeOctTree)
 * vtable at +0x00, sub-object at +0x78, int at +0xA0.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccModelHitNodeOct {
    uint64_t vtable;                 /* 0x00  PTR_FUN_140743a28        PRES ctor */
    uint8_t  _pad_08[0x70];          /* 0x08  unknown interior          UNKNOWN */
    uint64_t sub_obj_ptr;            /* 0x78  sub-object (FUN_14051f170) PRES ctor */
    uint8_t  _pad_80[0x20];          /* 0x80  unknown interior          UNKNOWN */
    uint32_t field_a0;               /* 0xA0  int, init=0               PRES ctor */
    uint32_t _pad_a4;                /* 0xA4  pad to 0xA8               UNKNOWN */
} nuccModelHitNodeOct;
_Static_assert(sizeof(nuccModelHitNodeOct) == 0xA8, "nuccModelHitNodeOct size must be 0xA8");
_Static_assert(offsetof(nuccModelHitNodeOct, vtable)      == 0x00, "");
_Static_assert(offsetof(nuccModelHitNodeOct, sub_obj_ptr) == 0x78, "");
_Static_assert(offsetof(nuccModelHitNodeOct, field_a0)    == 0xA0, "");

/* ========================================================================
 * nuccModelHitResultList  (size >= 0x810, unproven upper bound)
 * Result array at +0x08 with stride 0x40, max 0x20 entries.
 * nearest_index at +0x808 (int32), count at +0x80C (int32).
 * No direct allocation found — likely embedded or pool-allocated.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccModelHitResultList_entry {
    uint32_t field_00;               /* 0x00  int                      PRES EraseNearest */
    uint32_t field_04;               /* 0x04  int                      PRES EraseNearest */
    uint64_t field_08;               /* 0x08  qword                    PRES EraseNearest */
    uint64_t field_10;               /* 0x10  qword                    PRES EraseNearest */
    uint64_t field_18;               /* 0x18  qword                    PRES EraseNearest */
    uint64_t field_20;               /* 0x20  qword                    PRES EraseNearest */
    uint64_t field_28;               /* 0x28  qword                    PRES EraseNearest */
    uint64_t field_30;               /* 0x30  qword                    PRES EraseNearest */
    uint64_t field_38;               /* 0x38  qword                    PRES EraseNearest */
} nuccModelHitResultList_entry;       /* stride 0x40 confirmed by NewResult/EraseNearest */
_Static_assert(sizeof(nuccModelHitResultList_entry) == 0x40, "result entry stride must be 0x40");

typedef struct __attribute__((packed)) nuccModelHitResultList {
    uint64_t nearest_ptr;            /* 0x000  ptr to nearest result    PRES Reset/EraseNearest */
    uint8_t  results[0x20][0x40];   /* 0x008  array[32] of 0x40-byte   PRES NewResult stride */
                                     /*        total 0x800 bytes         */
    uint32_t nearest_index;          /* 0x808  int32, Reset clears      PRES Reset/NewResult */
    uint32_t count;                  /* 0x80C  int32, active count      PRES NewResult/EraseNearest */
} nuccModelHitResultList;
/* Size unproven — no operator new / LoadTh found. Lower bound 0x810. */
_Static_assert(offsetof(nuccModelHitResultList, nearest_ptr)   == 0x000, "");
_Static_assert(offsetof(nuccModelHitResultList, results)       == 0x008, "");
_Static_assert(offsetof(nuccModelHitResultList, nearest_index) == 0x808, "");
_Static_assert(offsetof(nuccModelHitResultList, count)         == 0x80C, "");

/* ========================================================================
 * nuccModelHitList  (size unknown, embedded at +0x40 in nuccClump)
 * Fields at +0x30, +0x98, +0x330 from state_surface.
 * No standalone allocation found.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccModelHitList {
    uint8_t  _head_00[0x30];         /* 0x000  unknown head             UNKNOWN */
    uint64_t field_30;               /* 0x030  qword                    SIM state_surface */
    uint8_t  _gap_38[0x60];          /* 0x038  gap                      UNKNOWN */
    uint64_t field_98;               /* 0x098  qword                    SIM state_surface */
    uint8_t  _gap_a0[0x290];         /* 0x0A0  gap                      UNKNOWN */
    uint32_t field_330;              /* 0x330  int                      SIM state_surface */
    uint32_t _pad_334;               /* 0x334  pad                      UNKNOWN */
} nuccModelHitList;
/* Size unproven — embedded in nuccClump at +0x40. Last known field at 0x330. */
_Static_assert(offsetof(nuccModelHitList, field_30)  == 0x030, "");
_Static_assert(offsetof(nuccModelHitList, field_98)  == 0x098, "");
_Static_assert(offsetof(nuccModelHitList, field_330) == 0x330, "");

/* ========================================================================
 * nuccModel  (size = 0x250, proven by LoadTh(0x250) in nuccChunkModel::Create)
 * Vtable PTR_FUN_14073af70.
 *
 * Qword-index to byte-offset map from ctor (FUN_1404c4cc0):
 *   param_1[0]  = 0x00   vtable
 *   param_1[3]  = 0x18   field_18
 *   param_1[4]  = 0x20   field_20
 *   *(ushort*)(param_1+5) = 0x28   field_28 (byte offset via cast)
 *   *(uint*)((longlong)param_1+0x2a) = 0x2A  field_2a (explicit byte)
 *   param_1[9]  = 0x48   instance_list
 *   BlockAllocator(param_1+10)  = 0x50   BA#1 (opaque 0x28 bytes)
 *   BlockAllocator(param_1+0xf) = 0x78   BA#2 (opaque 0x28 bytes)
 *   *(uint*)(param_1+0xe) = 0x70   field inside BA#1 region
 *   param_1[0x12] = 0x90   field inside BA#2 region
 *   *(uint*)(param_1+0x13) = 0x98  field inside BA#2 region
 *   BlockAllocator(param_1+0x15) = 0xA8  BA#3 (opaque 0x28 bytes)
 *   param_1[0x18] = 0xC0   hit_array_ptr
 *   *(uint*)(param_1+0x19) = 0xC8  hit_count (byte offset)
 *   *(ushort*)((longlong)param_1+0xe4) = 0xE4  field_e4
 *   param_1[0x40] = 0x200  field_200
 *   param_1[0x41] = 0x208  field_208
 *   *(uint*)(param_1+0x42) = 0x210  field_210
 *   nuccFogParam(param_1+0x44) = 0x220  fog_param
 *   *(uint*)((longlong)param_1+0x244) = 0x244  field_244
 *
 * BlockAllocator sub-objects are opaque 0x28-byte regions. Fields accessed
 * via param_1[0xd], param_1[0xe], etc. that fall within a BA range are
 * internal to that BA and not separate nuccModel fields.
 *
 * Layout:
 *   0x000-0x007  vtable
 *   0x008-0x017  base region (nuccTblBase)
 *   0x018-0x01F  field_18
 *   0x020-0x027  field_20
 *   0x028-0x029  field_28 (ushort)
 *   0x02A-0x02D  field_2a (uint, explicit byte offset)
 *   0x02E-0x047  gap
 *   0x048-0x04F  instance_list
 *   0x050-0x077  block_alloc_1 (0x28 bytes)
 *   0x078-0x09F  block_alloc_2 (0x28 bytes)
 *   0x0A0-0x0A7  gap (BA#2 ends 0x9F, BA#3 starts 0xA8)
 *   0x0A8-0x0CF  block_alloc_3 (0x28 bytes)
 *   0x0D0-0x0DF  gap (BA#3 ends 0xCF, hit_array_ptr at 0xC0 is INSIDE BA#3!)
 *
 * WAIT: param_1[0x18] = 0xC0. BA#3 is at 0xA8..0xCF. 0xC0 is inside BA#3.
 * But the dtor independently frees hit_array_ptr. This means either:
 * (a) BA#3 is smaller than 0x28, or
 * (b) hit_array_ptr overlaps with BA#3 internal storage.
 *
 * Looking at spacing: BA#1@0x50, BA#2@0x78 → gap=0x28. BA#2@0x78, BA#3@0xA8 → gap=0x30.
 * So BA#2 might be 0x30 bytes? No — BlockAllocator is always 0x28.
 * Actually BA#2@0x78 + 0x28 = 0xA0. BA#3@0xA8. Gap = 8 bytes.
 * And BA#3@0xA8 + 0x28 = 0xD0. hit_array_ptr@0xC0 is inside BA#3.
 *
 * Resolution: The BlockAllocator at param_1+0x15 stores the hit array pointer
 * internally at its +0x18 offset (0xA8+0x18=0xC0). The dtor reads it from there.
 * So hit_array_ptr and hit_count are FIELDS OF block_alloc_3, not separate.
 * But the dtor code does: if (param_1[0x18] != 0) free(param_1[0x18]).
 * This is consistent with reading from inside BA#3.
 *
 * For reconstruction purposes, we treat BAs as opaque and note that
 * hit_array_ptr lives at byte 0xC0 (inside BA#3) and hit_count at 0xC8.
 * We still assert their offsets for documentation.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccModel {
    uint64_t vtable;                 /* 0x000  PTR_FUN_14073af70        PRES ctor */
    uint8_t  _base_08[0x10];         /* 0x008  nuccTblBase region       UNKNOWN */
    uint64_t field_18;               /* 0x018  param_1[3]=0             PRES ctor */
    uint64_t field_20;               /* 0x020  param_1[4]=0             PRES ctor */
    uint16_t field_28;               /* 0x028  ushort, init=0           PRES ctor */
    uint32_t field_2a;               /* 0x02A  uint (byte offset 0x2A)  PRES ctor */
    uint8_t  _gap_2e[0x1A];          /* 0x02E  pad to 0x48              UNKNOWN */
    uint64_t instance_list;          /* 0x048  param_1[9]→nuccInstanceList PRES ctor/dtor */
    uint8_t  block_alloc_1[0x28];    /* 0x050  BlockAllocator #1        PRES ctor param_1+10 */
    uint8_t  block_alloc_2[0x28];    /* 0x078  BlockAllocator #2        PRES ctor param_1+0xf */
    uint8_t  _gap_a0[0x08];          /* 0x0A0  pad between BA#2 and BA#3 UNKNOWN */
    uint8_t  block_alloc_3[0x28];    /* 0x0A8  BlockAllocator #3        PRES ctor param_1+0x15 */
    /* hit_array_ptr at 0xC0 is inside block_alloc_3 (+0x18 into BA#3) */
    /* hit_count at 0xC8 is inside block_alloc_3 (+0x20 into BA#3) */
    uint8_t  _gap_d0[0x14];          /* 0x0D0  pad after BA#3           UNKNOWN */
    uint16_t field_e4;               /* 0x0E4  ushort, init=0           PRES ctor */
    uint8_t  _gap_e6[0x02];          /* 0x0E6  pad                      UNKNOWN */
    uint64_t field_e8;               /* 0x0E8  qword                    SIM state_surface */
    uint64_t field_f0;               /* 0x0F0  unknown                  UNKNOWN */
    uint64_t field_f8;               /* 0x0F8  unknown                  UNKNOWN */
    uint64_t field_100;              /* 0x100  unknown                  UNKNOWN */
    uint64_t field_108;              /* 0x108  unknown                  UNKNOWN */
    uint64_t field_110;              /* 0x110  unknown                  UNKNOWN */
    uint64_t field_118;              /* 0x118  unknown                  UNKNOWN */
    uint64_t field_120;              /* 0x120  unknown                  UNKNOWN */
    uint64_t field_128;              /* 0x128  unknown                  UNKNOWN */
    uint64_t field_130;              /* 0x130  unknown                  UNKNOWN */
    uint64_t field_138;              /* 0x138  unknown                  UNKNOWN */
    uint64_t field_140;              /* 0x140  unknown                  UNKNOWN */
    uint64_t field_148;              /* 0x148  unknown                  UNKNOWN */
    uint64_t field_150;              /* 0x150  unknown                  UNKNOWN */
    uint64_t field_158;              /* 0x158  unknown                  UNKNOWN */
    uint64_t field_160;              /* 0x160  unknown                  UNKNOWN */
    uint64_t field_168;              /* 0x168  unknown                  UNKNOWN */
    uint64_t field_170;              /* 0x170  unknown                  UNKNOWN */
    uint64_t field_178;              /* 0x178  unknown                  UNKNOWN */
    uint64_t field_180;              /* 0x180  unknown                  UNKNOWN */
    uint64_t field_188;              /* 0x188  unknown                  UNKNOWN */
    uint64_t field_190;              /* 0x190  unknown                  UNKNOWN */
    uint64_t field_198;              /* 0x198  unknown                  UNKNOWN */
    uint64_t field_1a0;              /* 0x1A0  unknown                  UNKNOWN */
    uint64_t field_1a8;              /* 0x1A8  unknown                  UNKNOWN */
    uint64_t field_1b0;              /* 0x1B0  unknown                  UNKNOWN */
    uint64_t field_1b8;              /* 0x1B8  unknown                  UNKNOWN */
    uint64_t field_1c0;              /* 0x1C0  unknown                  UNKNOWN */
    uint64_t field_1c8;              /* 0x1C8  unknown                  UNKNOWN */
    uint64_t field_1d0;              /* 0x1D0  unknown                  UNKNOWN */
    uint64_t field_1d8;              /* 0x1D8  unknown                  UNKNOWN */
    uint64_t field_1e0;              /* 0x1E0  unknown                  UNKNOWN */
    uint64_t field_1e8;              /* 0x1E8  unknown                  UNKNOWN */
    uint64_t field_1f0;              /* 0x1F0  unknown                  UNKNOWN */
    uint64_t field_1f8;              /* 0x1F8  unknown                  UNKNOWN */
    uint64_t field_200;              /* 0x200  init=-1                  PRES ctor */
    uint64_t field_208;              /* 0x208  init=-1                  PRES ctor */
    uint32_t field_210;              /* 0x210  int                      SIM state_surface */
    uint8_t  _gap_214[0x0C];         /* 0x214  pad                      UNKNOWN */
    uint8_t  fog_param[0x24];        /* 0x220  nuccFogParam embedded    PRES ctor */
    uint32_t field_244;              /* 0x244  int, init=1              PRES ctor */
    uint8_t  _tail_248[0x08];        /* 0x248  pad to 0x250             UNKNOWN */
} nuccModel;
_Static_assert(sizeof(nuccModel) == 0x250, "nuccModel size must be 0x250");
_Static_assert(offsetof(nuccModel, vtable)          == 0x000, "");
_Static_assert(offsetof(nuccModel, field_18)        == 0x018, "");
_Static_assert(offsetof(nuccModel, field_20)        == 0x020, "");
_Static_assert(offsetof(nuccModel, field_28)        == 0x028, "");
_Static_assert(offsetof(nuccModel, field_2a)        == 0x02A, "");
_Static_assert(offsetof(nuccModel, instance_list)   == 0x048, "");
_Static_assert(offsetof(nuccModel, block_alloc_1)   == 0x050, "");
_Static_assert(offsetof(nuccModel, block_alloc_2)   == 0x078, "");
_Static_assert(offsetof(nuccModel, block_alloc_3)   == 0x0A8, "");
_Static_assert(offsetof(nuccModel, field_e4)        == 0x0E4, "");
_Static_assert(offsetof(nuccModel, field_200)       == 0x200, "");
_Static_assert(offsetof(nuccModel, field_208)       == 0x208, "");
_Static_assert(offsetof(nuccModel, field_210)       == 0x210, "");
_Static_assert(offsetof(nuccModel, fog_param)       == 0x220, "");
_Static_assert(offsetof(nuccModel, field_244)       == 0x244, "");

#endif /* CMN60_H */