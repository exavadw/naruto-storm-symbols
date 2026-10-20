/* cmn60.h — Common struct group for build s4 (NARUTO STORM 4 PC 1.09, NSUNS4_release.exe)
 * Generated 2026-10-19 from the decompiler cache decompilation cache + state_surface.
 * All offsets verified against s4 x64 decompile. Sizes proven from allocator calls.
 * INFERRED only — not CONFIRMED by runtime trace.
 */
#ifndef CMN60_S4_H
#define CMN60_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for opaque types */
typedef struct nuccFogParam nuccFogParam;

/* =========================================================================
 * nuccModelHit — value type, no vtable, size 0xA0 proven by
 * operator_new(0xa0,...) in nuccClump::EntryModelHit (RVA 0xA1ED30),
 * nuccModel::InitModel (RVA 0xA4A0A0), nuccModel::EntryModelHit (RVA 0xA49D70).
 * Two Matrix44_MathGeo (64 bytes each) + flag + copies.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t matrix_a[64];   /* 0x00: Matrix44_MathGeo via ctor(param_1) */
    uint8_t matrix_b[64];   /* 0x40: Matrix44_MathGeo via ctor(param_1+0x40) */
    uint16_t flag;          /* 0x80: init=0x100 in ctor */
    uint8_t _pad_82[6];     /* 0x82: alignment padding */
    uint64_t field_88;      /* 0x88: qword copy from param_2+0x10 */
    uint64_t field_90;      /* 0x90: init=0 */
    uint64_t name_ptr;      /* 0x98: from nuccChunk::GetName(param_2) */
} nuccModelHit;

_Static_assert(offsetof(nuccModelHit, matrix_a) == 0x00, "nuccModelHit.matrix_a");
_Static_assert(offsetof(nuccModelHit, matrix_b) == 0x40, "nuccModelHit.matrix_b");
_Static_assert(offsetof(nuccModelHit, flag) == 0x80, "nuccModelHit.flag");
_Static_assert(offsetof(nuccModelHit, field_88) == 0x88, "nuccModelHit.field_88");
_Static_assert(offsetof(nuccModelHit, field_90) == 0x90, "nuccModelHit.field_90");
_Static_assert(offsetof(nuccModelHit, name_ptr) == 0x98, "nuccModelHit.name_ptr");
_Static_assert(sizeof(nuccModelHit) == 0xA0, "nuccModelHit size");

/* =========================================================================
 * nuccModelHitDataPolygon — polygon hit data, dense float layout 0x40-0x70+.
 * No standalone allocator found; size unknown, >= 0x74 (last proven field
 * at +0x70 is 4 bytes). SetData writes floats at +0x40 through +0x5C
 * (high confidence), +0x70 (write-only).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t _head_00[64];   /* 0x00: unknown head before first known field */
    float field_40;         /* 0x40: rw float, SetData writes fVar15 */
    float field_44;         /* 0x44: rw float, SetData writes fVar2 */
    float field_48;         /* 0x48: rw float, SetData writes fVar5 */
    float field_4c;         /* 0x4C: gap fill to next known */
    float field_50;         /* 0x50: gap fill */
    float field_54;         /* 0x54: rw float, SetData reads+writes */
    float field_58;         /* 0x58: rw float, SetData reads+writes */
    float field_5c;         /* 0x5C: rw float, SetData reads+writes */
    uint8_t _gap_60[16];    /* 0x60: gap to field_70 */
    float field_70;         /* 0x70: write-only float, SetData writes fVar1 */
} nuccModelHitDataPolygon;

_Static_assert(offsetof(nuccModelHitDataPolygon, field_40) == 0x40, "HitDataPolygon.field_40");
_Static_assert(offsetof(nuccModelHitDataPolygon, field_44) == 0x44, "HitDataPolygon.field_44");
_Static_assert(offsetof(nuccModelHitDataPolygon, field_48) == 0x48, "HitDataPolygon.field_48");
_Static_assert(offsetof(nuccModelHitDataPolygon, field_54) == 0x54, "HitDataPolygon.field_54");
_Static_assert(offsetof(nuccModelHitDataPolygon, field_58) == 0x58, "HitDataPolygon.field_58");
_Static_assert(offsetof(nuccModelHitDataPolygon, field_5c) == 0x5C, "HitDataPolygon.field_5c");
_Static_assert(offsetof(nuccModelHitDataPolygon, field_70) == 0x70, "HitDataPolygon.field_70");
/* Size unproven — no sizeof assert */

/* =========================================================================
 * nuccModelHitList — size unknown (embedded in nuccClump).
 * state_surface returned 0 fields (byte-cast accesses only).
 * Ctor calls FUN_140a41930(), FUN_140a419a0(param_1+0x28), FUN_140a215e0 twice.
 * Sub-object at +0x28. No standalone allocation found.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t _head_00[40];   /* 0x00: unknown head; FUN_140a215e0(param_1) */
    uint8_t sub_obj_28[40]; /* 0x28: sub-object via FUN_140a419a0 + FUN_140a215e0 */
} nuccModelHitList;

_Static_assert(offsetof(nuccModelHitList, sub_obj_28) == 0x28, "HitList.sub_obj_28");
/* Size unknown — no sizeof assert */

/* =========================================================================
 * nuccModelHitNodeOct — vtable class, 1 method only (< 3 threshold).
 * Vtable PTR_FUN_1411100a8 set in ctor (RVA 0xA8F5B0).
 * Sub-object at +0x78 via FUN_140a8f490(param_1+0xf). Field at +0xA0 init=0.
 * Size carried from s1 proof: 0xA8.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;        /* 0x00: PTR_FUN_1411100a8 */
    uint8_t _pad_08[112];   /* 0x08: interior unknown region */
    uint64_t sub_obj_ptr;   /* 0x78: initialized via FUN_140a8f490(param_1+0xf) */
    uint8_t _pad_80[32];    /* 0x80: interior unknown region */
    uint32_t field_a0;      /* 0xA0: init=0 in ctor */
    uint32_t _pad_a4;       /* 0xA4: tail padding to 0xA8 */
} nuccModelHitNodeOct;

_Static_assert(offsetof(nuccModelHitNodeOct, vtable) == 0x00, "nuccModelHitNodeOct.vtable");
_Static_assert(offsetof(nuccModelHitNodeOct, sub_obj_ptr) == 0x78, "nuccModelHitNodeOct.sub_obj_ptr");
_Static_assert(offsetof(nuccModelHitNodeOct, field_a0) == 0xA0, "nuccModelHitNodeOct.field_a0");
_Static_assert(sizeof(nuccModelHitNodeOct) == 0xA8, "nuccModelHitNodeOct size");

/* =========================================================================
 * nuccModelHitResultList — 2 methods only (< 3 threshold).
 * Reset (RVA 0x4FA728): sets vtable PTR_FUN_14100ef68, count=0.
 * Ctor at RVA 0x66FBB8 is MISATTRIBUTED (actually ccUiFlashManager code);
 * real ctor not identified. Size unknown.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;        /* 0x00: PTR_FUN_14100ef68 (from Reset) */
    uint64_t count;         /* 0x08: Reset sets param_1[1]=0 */
} nuccModelHitResultList;

_Static_assert(offsetof(nuccModelHitResultList, vtable) == 0x00, "ResultList.vtable");
_Static_assert(offsetof(nuccModelHitResultList, count) == 0x08, "ResultList.count");
/* Size unknown — no sizeof assert */

/* =========================================================================
 * nuccModelMng — manager class, 1 method only (< 3 threshold).
 * Reset (RVA 0xA6AAA0) calls luaU_header at +0x14, +0x2c, +0x44, +0x5c.
 * Size >= 0x5c + sub-object size. No allocator found.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t _head_00[20];   /* 0x00: unknown head before first sub-object */
    uint8_t sub_obj_14[24]; /* 0x14: luaU_header target #1 */
    uint8_t sub_obj_2c[24]; /* 0x2C: luaU_header target #2 */
    uint8_t sub_obj_44[24]; /* 0x44: luaU_header target #3 */
    uint8_t sub_obj_5c[24]; /* 0x5C: luaU_header target #4 */
} nuccModelMng;

_Static_assert(offsetof(nuccModelMng, sub_obj_14) == 0x14, "ModelMng.sub_obj_14");
_Static_assert(offsetof(nuccModelMng, sub_obj_2c) == 0x2C, "ModelMng.sub_obj_2c");
_Static_assert(offsetof(nuccModelMng, sub_obj_44) == 0x44, "ModelMng.sub_obj_44");
_Static_assert(offsetof(nuccModelMng, sub_obj_5c) == 0x5C, "ModelMng.sub_obj_5c");
/* Size unknown — no sizeof assert */

/* =========================================================================
 * nuccModel — size 0x250 proven by operator_new(0x250,...) in
 * nuccChunkModel::Create (RVA 0xA3BBC0). Vtable PTR_FUN_1411077b8 set in
 * ctor (RVA 0xA47F80). Three BlockAllocator sub-objects at +0x50, +0x78,
 * +0xA8 with vtables PTR_FUN_141107788, PTR_FUN_141107788, PTR_FUN_1411077a0.
 * FogParam embedded at +0x220. Large unknown region 0x0F0–0x1BF.
 * NEW in s4 vs s3: field_248 at offset 0x248 (init=1) was padding in s3.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;            /* 0x000: PTR_FUN_1411077b8 */
    uint8_t base_08[16];        /* 0x008: nuccTblBase region, no field evidence */
    uint64_t field_18;          /* 0x018: ctor param_1[3]=0 */
    uint64_t field_20;          /* 0x020: ctor param_1[4]=0 */
    uint16_t field_28;          /* 0x028: ctor *(ushort*)(param_1+5)=0 */
    uint8_t field_2a;           /* 0x02A: byte, InitModel copies from chunk */
    uint8_t field_2b;           /* 0x02B: byte, InitModel copies from chunk+0xae */
    uint16_t field_2c;          /* 0x02C: ushort, InitModel copies from chunk+0xaa */
    uint8_t _gap_2e[26];        /* 0x02E: pad to instance_list/BA region */
    uint32_t field_48_count;    /* 0x048: instance count / BA#1 internal */
    uint32_t field_4c;          /* 0x04C: pad / BA#1 internal */
    uint8_t block_alloc_1[40];  /* 0x050: BlockAllocator #1, vtable PTR_FUN_141107788 */
    uint8_t block_alloc_2[40];  /* 0x078: BlockAllocator #2, vtable PTR_FUN_141107788 */
    uint8_t _gap_a0[8];         /* 0x0A0: pad between BA#2 end and BA#3 start */
    uint8_t block_alloc_3[40];  /* 0x0A8: BlockAllocator #3, vtable PTR_FUN_1411077a0 */
    uint8_t _gap_d0[20];        /* 0x0D0: pad after BA#3 */
    uint16_t field_e4_word;     /* 0x0E4: ctor init=0 */
    uint8_t _gap_e6[2];         /* 0x0E6: pad to qword */
    uint64_t field_e8;          /* 0x0E8: SIM — state_surface; InitModel sets=0 */
    uint8_t _gap_f0[208];       /* 0x0F0: large unknown region 0xF0-0x1BF (216 = 0xD8 bytes) */
    uint64_t field_1c0;         /* 0x1C0: state_surface field */
    uint8_t _gap_1c8[56];       /* 0x1C8: pad to PRES region (56 = 0x38 bytes) */
    uint64_t field_200;         /* 0x200: PRES — ctor param_1[0x40]=-1 */
    uint64_t field_208;         /* 0x208: PRES — ctor param_1[0x41]=-1 */
    uint32_t field_210;         /* 0x210: PRES — ctor init=0 */
    uint8_t _gap_214[12];       /* 0x214: pad to fog_param */
    uint8_t fog_param[36];      /* 0x220: nuccFogParam, size 0x24 inferred */
    uint32_t field_244;         /* 0x244: PRES — ctor init=1 */
    uint32_t field_248;         /* 0x248: PRES — ctor init=1 (NEW in s4) */
    uint8_t _tail_24c[4];       /* 0x24C: pad to proven size 0x250 */
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
_Static_assert(offsetof(nuccModel, field_1c0) == 0x1C0, "nuccModel.field_1c0");
_Static_assert(offsetof(nuccModel, field_200) == 0x200, "nuccModel.field_200");
_Static_assert(offsetof(nuccModel, field_208) == 0x208, "nuccModel.field_208");
_Static_assert(offsetof(nuccModel, field_210) == 0x210, "nuccModel.field_210");
_Static_assert(offsetof(nuccModel, fog_param) == 0x220, "nuccModel.fog_param");
_Static_assert(offsetof(nuccModel, field_244) == 0x244, "nuccModel.field_244");
_Static_assert(offsetof(nuccModel, field_248) == 0x248, "nuccModel.field_248");
_Static_assert(sizeof(nuccModel) == 0x250, "nuccModel size");

#endif /* CMN60_S4_H */