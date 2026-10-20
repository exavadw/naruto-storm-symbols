/* cmn60.h — Common struct group for build s3 (NARUTO STORM 3 Full Burst HD PC, NSUNS3.exe 64-bit)
 * Generated 2026-10-19 from the decompiler cache decompilation cache + state_surface.
 * All offsets verified against s3 x64 decompile. Sizes proven from allocator calls.
 * INFERRED only — not CONFIRMED by runtime trace.
 */
#ifndef CMN60_S3_H
#define CMN60_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for opaque types */
typedef struct nuccFogParam nuccFogParam;

/* =========================================================================
 * nuccModelHit — value type, no vtable, size 0xA0 proven by
 * FUN_140683f70(0xa0,...) in nuccClump::EntryModelHit (RVA 0x68A930).
 * Two Matrix44_MathGeo (64 bytes each) + flag + copies.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t matrix_a[64];       /* 0x00: Matrix44_MathGeo copied via FUN_1406856b0(param_1) */
    uint8_t matrix_b[64];       /* 0x40: Matrix44_MathGeo copied via FUN_1406856b0(param_1+0x40) */
    uint16_t flag;              /* 0x80: init=0x100 in ctor */
    uint8_t _pad_82[6];         /* 0x82: alignment padding */
    uint64_t field_88;          /* 0x88: qword copy from param_2+0x10 */
    uint64_t field_90;          /* 0x90: init=0 */
    uint64_t name_ptr;          /* 0x98: from FUN_1406af410(param_2) = nuccChunk::GetName */
} nuccModelHit;

_Static_assert(offsetof(nuccModelHit, matrix_a) == 0x00, "nuccModelHit.matrix_a");
_Static_assert(offsetof(nuccModelHit, matrix_b) == 0x40, "nuccModelHit.matrix_b");
_Static_assert(offsetof(nuccModelHit, flag) == 0x80, "nuccModelHit.flag");
_Static_assert(offsetof(nuccModelHit, field_88) == 0x88, "nuccModelHit.field_88");
_Static_assert(offsetof(nuccModelHit, field_90) == 0x90, "nuccModelHit.field_90");
_Static_assert(offsetof(nuccModelHit, name_ptr) == 0x98, "nuccModelHit.name_ptr");
_Static_assert(sizeof(nuccModelHit) == 0xA0, "nuccModelHit size");

/* =========================================================================
 * nuccModelHitDataPolygon — polygon hit data, dense float layout 0x30–0x9C.
 * No standalone allocator found; size unknown, >= 0xA0.
 * SetData writes all floats at +0x40 through +0x9C.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t _head_00[48];       /* 0x00: unknown head before first known field */
    float plane_normal_x;       /* 0x30: read-only float */
    float plane_normal_y;       /* 0x34: read-only float */
    float plane_normal_z;       /* 0x38: read-only float */
    float plane_dist;           /* 0x3C: read-only float */
    float vertex_data[24];      /* 0x40: 24 floats written by SetData (vertex/edge data) */
} nuccModelHitDataPolygon;

_Static_assert(offsetof(nuccModelHitDataPolygon, plane_normal_x) == 0x30, "HitDataPolygon.plane_normal_x");
_Static_assert(offsetof(nuccModelHitDataPolygon, plane_normal_y) == 0x34, "HitDataPolygon.plane_normal_y");
_Static_assert(offsetof(nuccModelHitDataPolygon, plane_normal_z) == 0x38, "HitDataPolygon.plane_normal_z");
_Static_assert(offsetof(nuccModelHitDataPolygon, plane_dist) == 0x3C, "HitDataPolygon.plane_dist");
_Static_assert(offsetof(nuccModelHitDataPolygon, vertex_data) == 0x40, "HitDataPolygon.vertex_data");
/* Size unproven — no sizeof assert */

/* =========================================================================
 * nuccModelHitNodeOct — vtable class, size 0xA8 carried from s1 LoadTh proof
 * (no s3-specific allocator found). Vtable PTR_FUN_1409e6f90 set in ctor (RVA 0x7047A0).
 * Sub-object at +0x78 initialized via FUN_140704680(param_1+0xf).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;            /* 0x00: PTR_FUN_1409e6f90 */
    uint8_t _pad_08[112];       /* 0x08: interior unknown region */
    uint64_t sub_obj_ptr;       /* 0x78: initialized via FUN_140704680(param_1+0xf) */
    uint8_t _pad_80[32];        /* 0x80: interior unknown region */
    uint32_t field_a0;          /* 0xA0: init=0 in ctor */
    uint32_t _pad_a4;           /* 0xA4: tail padding to 0xA8 */
} nuccModelHitNodeOct;

_Static_assert(offsetof(nuccModelHitNodeOct, vtable) == 0x00, "nuccModelHitNodeOct.vtable");
_Static_assert(offsetof(nuccModelHitNodeOct, sub_obj_ptr) == 0x78, "nuccModelHitNodeOct.sub_obj_ptr");
_Static_assert(offsetof(nuccModelHitNodeOct, field_a0) == 0xA0, "nuccModelHitNodeOct.field_a0");
_Static_assert(sizeof(nuccModelHitNodeOct) == 0xA8, "nuccModelHitNodeOct size");

/* =========================================================================
 * nuccModelHitResultList_entry — entry within results array.
 * s3 ctor loop: puVar1=(undefined4*)(param_1+0x4c), stride puVar1+=0x58
 * = 0x58*4 = 0x160 bytes per entry, 4 iterations → entries at +0x4C,+0x1AC,+0x30C,+0x46C.
 * Layout from Reset/NewResult/EraseNearest methods.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint32_t field_00;          /* 0x00: int r/w in EraseNearest */
    uint32_t field_04;          /* 0x04: uint r/w in EraseNearest */
    uint64_t field_08;          /* 0x08: qword copy */
    uint64_t field_10;          /* 0x10: written via *(int*)(*param_1+0x10) */
    uint64_t field_18;          /* 0x18: float at +0x18 used in SetNearest comparison */
    uint64_t field_20;          /* 0x20: qword copy */
    uint64_t field_28;          /* 0x28: qword copy */
    uint64_t field_30;          /* 0x30: qword copy */
    uint64_t field_38;          /* 0x38: qword copy */
    uint8_t _tail_40[288];      /* 0x40: remainder of 0x160-byte entry */
} nuccModelHitResultList_entry;

_Static_assert(offsetof(nuccModelHitResultList_entry, field_00) == 0x00, "entry.field_00");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_04) == 0x04, "entry.field_04");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_08) == 0x08, "entry.field_08");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_10) == 0x10, "entry.field_10");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_18) == 0x18, "entry.field_18");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_20) == 0x20, "entry.field_20");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_28) == 0x28, "entry.field_28");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_30) == 0x30, "entry.field_30");
_Static_assert(offsetof(nuccModelHitResultList_entry, field_38) == 0x38, "entry.field_38");
_Static_assert(sizeof(nuccModelHitResultList_entry) == 0x160, "entry stride s3");

/* =========================================================================
 * nuccModelHitResultList — vtable PTR_FUN_1408a7620 set in ctor (RVA 0x19E100).
 * 4 entries × 0x160 starting at +0x4C. nearest_index at +0x808, count at +0x80C
 * confirmed by state_surface. Size unknown, >= 0x810.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;            /* 0x000: PTR_FUN_1408a7620 */
    uint32_t field_08;          /* 0x008: init=0 in ctor (*(uint*)(param_1+1)=0) */
    uint8_t _gap_0c[64];        /* 0x00C: gap to results array */
    nuccModelHitResultList_entry results[4]; /* 0x04C: 4×0x160 = 0x580 bytes */
    uint8_t _gap_5cc[572];      /* 0x5CC: gap between results end and nearest_index */
    uint32_t nearest_index;     /* 0x808: state_surface field */
    uint32_t count;             /* 0x80C: state_surface field */
} nuccModelHitResultList;

_Static_assert(offsetof(nuccModelHitResultList, vtable) == 0x000, "ResultList.vtable");
_Static_assert(offsetof(nuccModelHitResultList, field_08) == 0x008, "ResultList.field_08");
_Static_assert(offsetof(nuccModelHitResultList, results) == 0x04C, "ResultList.results");
_Static_assert(offsetof(nuccModelHitResultList, nearest_index) == 0x808, "ResultList.nearest_index");
_Static_assert(offsetof(nuccModelHitResultList, count) == 0x80C, "ResultList.count");
/* Size unproven — no sizeof assert */

/* =========================================================================
 * nuccModelHitList — size unknown (embedded in nuccClump).
 * Only 3 fields known from state_surface. No standalone allocation found.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t _head_00[48];       /* 0x000: unknown head before first known field */
    uint64_t field_30;          /* 0x030: SIM — state_surface qword */
    uint8_t _gap_38[96];        /* 0x038: gap between known fields */
    uint64_t field_98;          /* 0x098: SIM — state_surface qword */
    uint8_t _gap_a0[656];       /* 0x0A0: gap between known fields */
    uint32_t field_330;         /* 0x330: SIM — state_surface int */
    uint32_t _pad_334;          /* 0x334: tail padding */
} nuccModelHitList;

_Static_assert(offsetof(nuccModelHitList, field_30) == 0x030, "HitList.field_30");
_Static_assert(offsetof(nuccModelHitList, field_98) == 0x098, "HitList.field_98");
_Static_assert(offsetof(nuccModelHitList, field_330) == 0x330, "HitList.field_330");
/* Size unknown — no sizeof assert */

/* =========================================================================
 * nuccModelMng — manager class, no fields found by state_surface.
 * Only Reset method decompiled. Size unknown.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t _placeholder[1];    /* placeholder — no fields proven */
} nuccModelMng;
/* Size unknown — no sizeof assert */

/* =========================================================================
 * nuccModel — size 0x250 proven by FUN_140683f70(0x250,...) in
 * nuccChunkModel::Create (RVA 0x6B2460). Vtable PTR_FUN_1409e34a8 set in
 * ctor (RVA 0x6D49E0). Three BlockAllocator sub-objects at +0x50, +0x78, +0xA8
 * with vtables PTR_FUN_1409e35d0, PTR_FUN_1409e35d0, PTR_FUN_1409e3490.
 * FogParam embedded at +0x220. Large unknown region 0x0E8–0x1FF.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;            /* 0x000: PTR_FUN_1409e34a8 */
    uint8_t base_08[16];        /* 0x008: nuccTblBase region, no field evidence */
    uint64_t field_18;          /* 0x018: param_1[3]=0 */
    uint64_t field_20;          /* 0x020: param_1[4]=0 */
    uint16_t field_28;          /* 0x028: *(ushort*)(param_1+5)=0 */
    uint8_t field_2a;           /* 0x02A: byte copy from chunk (InitModel) */
    uint8_t field_2b;           /* 0x02B: byte copy from chunk+0xae (InitModel) */
    uint16_t field_2c;          /* 0x02C: ushort copy from chunk+0xaa (InitModel) */
    uint8_t _gap_2e[26];        /* 0x02E: pad to instance_list/BA region */
    uint32_t field_48_count;    /* 0x048: instance count / BA#1 internal */
    uint32_t field_4c;          /* 0x04C: pad / BA#1 internal */
    uint8_t block_alloc_1[40];  /* 0x050: BlockAllocator #1, vtable PTR_FUN_1409e35d0 */
    uint8_t block_alloc_2[40];  /* 0x078: BlockAllocator #2, vtable PTR_FUN_1409e35d0 */
    uint8_t _gap_a0[8];         /* 0x0A0: pad between BA#2 end and BA#3 start */
    uint8_t block_alloc_3[40];  /* 0x0A8: BlockAllocator #3, vtable PTR_FUN_1409e3490 */
    uint8_t _gap_d0[20];        /* 0x0D0: pad after BA#3 */
    uint16_t field_e4_word;     /* 0x0E4: init=0 in ctor (*(ushort*)(param_1+0xe4)=0) */
    uint8_t _gap_e6[2];         /* 0x0E6: pad to qword */
    uint64_t field_e8;          /* 0x0E8: SIM — state_surface; InitModel sets=0 */
    uint64_t field_f0;          /* 0x0F0: UNKNOWN gap fill */
    uint64_t field_f8;          /* 0x0F8: UNKNOWN gap fill */
    uint64_t field_100;         /* 0x100: UNKNOWN gap fill */
    uint64_t field_108;         /* 0x108: UNKNOWN gap fill */
    uint64_t field_110;         /* 0x110: UNKNOWN gap fill */
    uint64_t field_118;         /* 0x118: UNKNOWN gap fill */
    uint64_t field_120;         /* 0x120: UNKNOWN gap fill */
    uint64_t field_128;         /* 0x128: UNKNOWN gap fill */
    uint64_t field_130;         /* 0x130: UNKNOWN gap fill */
    uint64_t field_138;         /* 0x138: UNKNOWN gap fill */
    uint64_t field_140;         /* 0x140: UNKNOWN gap fill */
    uint64_t field_148;         /* 0x148: UNKNOWN gap fill */
    uint64_t field_150;         /* 0x150: UNKNOWN gap fill */
    uint64_t field_158;         /* 0x158: UNKNOWN gap fill */
    uint64_t field_160;         /* 0x160: UNKNOWN gap fill */
    uint64_t field_168;         /* 0x168: UNKNOWN gap fill */
    uint64_t field_170;         /* 0x170: UNKNOWN gap fill */
    uint64_t field_178;         /* 0x178: UNKNOWN gap fill */
    uint64_t field_180;         /* 0x180: UNKNOWN gap fill */
    uint64_t field_188;         /* 0x188: UNKNOWN gap fill */
    uint64_t field_190;         /* 0x190: UNKNOWN gap fill */
    uint64_t field_198;         /* 0x198: UNKNOWN gap fill */
    uint64_t field_1a0;         /* 0x1A0: UNKNOWN gap fill */
    uint64_t field_1a8;         /* 0x1A8: UNKNOWN gap fill */
    uint64_t field_1b0;         /* 0x1B0: UNKNOWN gap fill */
    uint64_t field_1b8;         /* 0x1B8: UNKNOWN gap fill */
    uint64_t field_1c0;         /* 0x1C0: UNKNOWN gap fill */
    uint64_t field_1c8;         /* 0x1C8: UNKNOWN gap fill */
    uint64_t field_1d0;         /* 0x1D0: UNKNOWN gap fill */
    uint64_t field_1d8;         /* 0x1D8: UNKNOWN gap fill */
    uint64_t field_1e0;         /* 0x1E0: UNKNOWN gap fill */
    uint64_t field_1e8;         /* 0x1E8: UNKNOWN gap fill */
    uint64_t field_1f0;         /* 0x1F0: UNKNOWN gap fill */
    uint64_t field_1f8;         /* 0x1F8: UNKNOWN gap fill */
    uint64_t field_200;         /* 0x200: PRES — ctor param_1[0x40]=-1 */
    uint64_t field_208;         /* 0x208: PRES — ctor param_1[0x41]=-1 */
    uint32_t field_210;         /* 0x210: SIM/PRES — state_surface + ctor init=0 */
    uint8_t _gap_214[12];       /* 0x214: pad to fog_param */
    uint8_t fog_param[36];      /* 0x220: nuccFogParam, size 0x24 inferred */
    uint32_t field_244;         /* 0x244: PRES — ctor init=1 */
    uint8_t _tail_248[8];       /* 0x248: pad to proven size 0x250 */
} nuccModel;

_Static_assert(offsetof(nuccModel, vtable) == 0x000, "nuccModel.vtable");
_Static_assert(offsetof(nuccModel, field_18) == 0x018, "nuccModel.field_18");
_Static_assert(offsetof(nuccModel, field_20) == 0x020, "nuccModel.field_20");
_Static_assert(offsetof(nuccModel, field_28) == 0x028, "nuccModel.field_28");
_Static_assert(offsetof(nuccModel, field_2a) == 0x02A, "nuccModel.field_2a");
_Static_assert(offsetof(nuccModel, field_2b) == 0x02B, "nuccModel.field_2b");
_Static_assert(offsetof(nuccModel, field_2c) == 0x02C, "nuccModel.field_2c");
_Static_assert(offsetof(nuccModel, field_48_count) == 0x048, "nuccModel.field_48_count");
_Static_assert(offsetof(nuccModel, block_alloc_1) == 0x050, "nuccModel.block_alloc_1");
_Static_assert(offsetof(nuccModel, block_alloc_2) == 0x078, "nuccModel.block_alloc_2");
_Static_assert(offsetof(nuccModel, block_alloc_3) == 0x0A8, "nuccModel.block_alloc_3");
_Static_assert(offsetof(nuccModel, field_e4_word) == 0x0E4, "nuccModel.field_e4_word");
_Static_assert(offsetof(nuccModel, field_e8) == 0x0E8, "nuccModel.field_e8");
_Static_assert(offsetof(nuccModel, field_200) == 0x200, "nuccModel.field_200");
_Static_assert(offsetof(nuccModel, field_208) == 0x208, "nuccModel.field_208");
_Static_assert(offsetof(nuccModel, field_210) == 0x210, "nuccModel.field_210");
_Static_assert(offsetof(nuccModel, fog_param) == 0x220, "nuccModel.fog_param");
_Static_assert(offsetof(nuccModel, field_244) == 0x244, "nuccModel.field_244");
_Static_assert(sizeof(nuccModel) == 0x250, "nuccModel size");

#endif /* CMN60_S3_H */