/*
 * cmn32.h — Common engine/shader/script struct layouts for NARUTO STORM 3 Full Burst HD (s3, NSUNS3.exe)
 *
 * All offsets INFERRED from static analysis of s3 decompiled code.
 * Sizes proven from ctor/dtor/operator new where noted; otherwise "size unknown, >= 0xN".
 * No sizeof asserts for unproven sizes.
 *
 * Build: s3 (NSUNS3.exe, image base 0x140000000)
 * Generated: 2026-10-19
 */
#ifndef CMN32_S3_H
#define CMN32_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * mmShaderBufferBinder
 * Evidence: dtor at 0x148B10 cleans three rbtrees at +0x08, +0x38, +0x68
 * with metadata loaded from +0x20, +0x50, +0x80.
 * Register at 0x142550 walks tree rooted at *(param_1+0x20), sentinel at param_1+0x10,
 * inserts via FUN_140142b90(param_1+8,...), stores value at node[5] (=node+0x28).
 * Size: >= 0x88 (last access at +0x80 for tree metadata in dtor)
 * Methods: ClearAll(0x1426D0), Register(0x142550,0x1425D0), ~mmShaderBufferBinder(0x148B10) = 4
 * Vtable: not identified
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t field_0x00[0x08];       /* +0x00: unknown header */
    uint8_t tree_region_0[0x18];    /* +0x08: rbtree region 0 */
    uint8_t tree_meta_0[0x08];      /* +0x20: tree 0 metadata ptr */
    uint8_t tree_sentinel_0[0x10];  /* +0x28: sentinel/extra (Register uses param_1+0x10 as sentinel) */
    uint8_t tree_region_1[0x18];    /* +0x38: rbtree region 1 */
    uint8_t tree_meta_1[0x08];      /* +0x50: tree 1 metadata ptr */
    uint8_t pad_0x58[0x10];         /* +0x58: gap to tree_region_2 */
    uint8_t tree_region_2[0x18];    /* +0x68: rbtree region 2 */
    uint8_t tree_meta_2[0x08];      /* +0x80: tree 2 metadata ptr */
    /* size unknown, >= 0x88 */
} mmShaderBufferBinder;

static_assert(offsetof(mmShaderBufferBinder, field_0x00) == 0x00, "mmShaderBufferBinder.field_0x00");
static_assert(offsetof(mmShaderBufferBinder, tree_region_0) == 0x08, "mmShaderBufferBinder.tree_region_0");
static_assert(offsetof(mmShaderBufferBinder, tree_meta_0) == 0x20, "mmShaderBufferBinder.tree_meta_0");
static_assert(offsetof(mmShaderBufferBinder, tree_sentinel_0) == 0x28, "mmShaderBufferBinder.tree_sentinel_0");
static_assert(offsetof(mmShaderBufferBinder, tree_region_1) == 0x38, "mmShaderBufferBinder.tree_region_1");
static_assert(offsetof(mmShaderBufferBinder, tree_meta_1) == 0x50, "mmShaderBufferBinder.tree_meta_1");
static_assert(offsetof(mmShaderBufferBinder, pad_0x58) == 0x58, "mmShaderBufferBinder.pad_0x58");
static_assert(offsetof(mmShaderBufferBinder, tree_region_2) == 0x68, "mmShaderBufferBinder.tree_region_2");
static_assert(offsetof(mmShaderBufferBinder, tree_meta_2) == 0x80, "mmShaderBufferBinder.tree_meta_2");

/* ========================================================================
 * mmShaderCBufferInfoList
 * Evidence: ctor at 0x143560 initializes param_1[0..2]=0, param_1[6..8]=0,
 * self-ptr at param_1+5 (=+0x28), byte at param_1+8 (=+0x40), uint32 at param_1+9 (=+0x48).
 * dtor at 0x13DE60 cleans containers at +0x60 (meta +0x78), +0x90 (meta +0xA8),
 * plus vtable-dispatch block at +0xC8..+0xE0. Also calls FUN_1401435a0(param_1+0x10).
 * Size: >= 0xE8 (dtor accesses through +0xE0 for vtable dispatch)
 * Methods: ctor(0x143560), dtor(0x13DE60), AddCBufferInfo(0x143750), Clear(0x1450E0), Merge(0x143930) = 5
 * Vtable: dispatch at *(param_1+0xE0)+0x10 in dtor
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t header[0x10];           /* +0x00: header (ctor sets [0..2]=0) */
    uint8_t sub_struct[0x18];       /* +0x10: sub-struct cleaned by FUN_1401435a0 in dtor */
    uint8_t self_ptr_region[0x18];  /* +0x28: self-ptr region (ctor: param_1+5 = puVar1) */
    uint8_t flags_region[0x18];     /* +0x40: byte flag + uint32 count (ctor: param_1+8, param_1+9) */
    uint8_t pad_0x58[0x08];         /* +0x58: gap to container_0 */
    uint8_t container_0[0x30];      /* +0x60: container group 0 (dtor: FUN(p+0x60, *(p+0x78))) */
    uint8_t container_1[0x30];      /* +0x90: container group 1 (dtor: FUN(p+0x90, *(p+0xA8))) */
    uint8_t pad_0xc0[0x08];         /* +0xC0: gap */
    uint64_t vtable_base_0xc8;      /* +0xC8: vtable base ptr (dtor reads *(p+0xC8)) */
    uint64_t vtable_count_0xd0;     /* +0xD0: count/index (dtor reads *(p+0xD0)) */
    uint64_t vtable_dispatch_0xd8;  /* +0xD8: dispatch ptr (dtor reads *(p+0xD8)) */
    uint64_t vtable_func_0xe0;      /* +0xE0: func table ptr (dtor: (**(*(p+0xE0)+0x10))(...)) */
    /* size unknown, >= 0xE8 */
} mmShaderCBufferInfoList;

static_assert(offsetof(mmShaderCBufferInfoList, header) == 0x00, "mmShaderCBufferInfoList.header");
static_assert(offsetof(mmShaderCBufferInfoList, sub_struct) == 0x10, "mmShaderCBufferInfoList.sub_struct");
static_assert(offsetof(mmShaderCBufferInfoList, self_ptr_region) == 0x28, "mmShaderCBufferInfoList.self_ptr_region");
static_assert(offsetof(mmShaderCBufferInfoList, flags_region) == 0x40, "mmShaderCBufferInfoList.flags_region");
static_assert(offsetof(mmShaderCBufferInfoList, pad_0x58) == 0x58, "mmShaderCBufferInfoList.pad_0x58");
static_assert(offsetof(mmShaderCBufferInfoList, container_0) == 0x60, "mmShaderCBufferInfoList.container_0");
static_assert(offsetof(mmShaderCBufferInfoList, container_1) == 0x90, "mmShaderCBufferInfoList.container_1");
static_assert(offsetof(mmShaderCBufferInfoList, pad_0xc0) == 0xC0, "mmShaderCBufferInfoList.pad_0xc0");
static_assert(offsetof(mmShaderCBufferInfoList, vtable_base_0xc8) == 0xC8, "mmShaderCBufferInfoList.vtable_base_0xc8");
static_assert(offsetof(mmShaderCBufferInfoList, vtable_count_0xd0) == 0xD0, "mmShaderCBufferInfoList.vtable_count_0xd0");
static_assert(offsetof(mmShaderCBufferInfoList, vtable_dispatch_0xd8) == 0xD8, "mmShaderCBufferInfoList.vtable_dispatch_0xd8");
static_assert(offsetof(mmShaderCBufferInfoList, vtable_func_0xe0) == 0xE0, "mmShaderCBufferInfoList.vtable_func_0xe0");

/* ========================================================================
 * mmShaderEffectCompiler
 * Evidence: state_surface from ctor+Compile shows func ptr at +0x58, flags at +0x60,
 * vtable deref reads at +0x80, +0xC0, +0x100 in Compile.
 * Size: >= 0x108 (state_surface max offset 0x100 + ptr)
 * Methods: ctor(0x148260), Compile(0x148490), ~mmShaderEffectCompiler(0x148340) = 3
 * Vtable: func ptr at +0x58 (PTR_FUN_140a1c498)
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x58];         /* +0x00: unknown header */
    uint64_t func_ptr_0x58;         /* +0x58: PTR_FUN_140a1c498 (ctor write) */
    uint32_t flags_0x60;            /* +0x60: uint32 (high conf write in Compile & ctor) */
    uint8_t pad_0x64[0x1c];         /* +0x64: gap */
    uint64_t vfunc_read_0x80;       /* +0x80: vtable deref read in Compile */
    uint8_t pad_0x88[0x38];         /* +0x88: gap */
    uint64_t vfunc_read_0xc0;       /* +0xC0: vtable deref read in Compile */
    uint8_t pad_0xc8[0x38];         /* +0xC8: gap */
    uint64_t vfunc_read_0x100;      /* +0x100: vtable deref read in Compile */
    /* size unknown, >= 0x108 */
} mmShaderEffectCompiler;

static_assert(offsetof(mmShaderEffectCompiler, func_ptr_0x58) == 0x58, "mmShaderEffectCompiler.func_ptr_0x58");
static_assert(offsetof(mmShaderEffectCompiler, flags_0x60) == 0x60, "mmShaderEffectCompiler.flags_0x60");
static_assert(offsetof(mmShaderEffectCompiler, vfunc_read_0x80) == 0x80, "mmShaderEffectCompiler.vfunc_read_0x80");
static_assert(offsetof(mmShaderEffectCompiler, vfunc_read_0xc0) == 0xC0, "mmShaderEffectCompiler.vfunc_read_0xc0");
static_assert(offsetof(mmShaderEffectCompiler, vfunc_read_0x100) == 0x100, "mmShaderEffectCompiler.vfunc_read_0x100");

/* ========================================================================
 * mmShaderPass
 * Evidence: state_surface 28 fields. ctor initializes extensively.
 * Submit reads/writes pass_type at +0x60 (set to 7 = SIM), vtable deref at +0x780.
 * Container groups at +0x70, +0xA0, +0xD0, +0x1F8. Render state init at +0xF8.
 * Size: >= 0x788 (state_surface max offset 0x780 + ptr deref in Submit)
 * Methods: ctor(0x1489A0), Submit(0x148C00), AddParameter(0x160F90,0x148060) = 4+
 * Vtable: dereferenced at *param_1+0xF0 in Submit (offset 0x780 = 0xF0*8)
 * SIM fields: 1 (pass_type_0x60 set to 7)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x58];         /* +0x00: unknown/vtable region */
    uint64_t func_ptr_0x58;         /* +0x58: PTR_FUN_140a1c498 (ctor write) */
    uint32_t pass_type_0x60;        /* +0x60: uint32, set to 7 (SIM) */
    uint8_t pad_0x64[0x0c];         /* +0x64: gap */
    uint8_t container_0[0x30];      /* +0x70: container group 0 (ctor rw) */
    uint8_t container_1[0x30];      /* +0xA0: container group 1 (ctor rw) */
    uint8_t container_2[0x28];      /* +0xD0: container group 2 (ctor rw) */
    uint8_t render_state[0xD0];     /* +0xF8: embedded render state (FUN_14013df30 init) */
    uint64_t field_0x1c8;           /* +0x1C8: rw in Submit */
    uint64_t field_0x1d0;           /* +0x1D0: init 0 */
    uint64_t field_0x1d8;           /* +0x1D8: init 0 */
    uint64_t field_0x1e0;           /* +0x1E0: init 0 */
    uint8_t pad_0x1e8[0x10];        /* +0x1E8: gap */
    uint8_t container_3[0x20];      /* +0x1F8: container group 3 (ctor rw) */
    uint8_t pad_0x218[0x568];       /* +0x218: large gap to 0x780 */
    uint64_t vtable_deref_0x780;    /* +0x780: vtable check in Submit (*param_1+0xF0) */
    /* size unknown, >= 0x788 */
} mmShaderPass;

static_assert(offsetof(mmShaderPass, func_ptr_0x58) == 0x58, "mmShaderPass.func_ptr_0x58");
static_assert(offsetof(mmShaderPass, pass_type_0x60) == 0x60, "mmShaderPass.pass_type_0x60");
static_assert(offsetof(mmShaderPass, container_0) == 0x70, "mmShaderPass.container_0");
static_assert(offsetof(mmShaderPass, container_1) == 0xA0, "mmShaderPass.container_1");
static_assert(offsetof(mmShaderPass, container_2) == 0xD0, "mmShaderPass.container_2");
static_assert(offsetof(mmShaderPass, render_state) == 0xF8, "mmShaderPass.render_state");
static_assert(offsetof(mmShaderPass, field_0x1c8) == 0x1C8, "mmShaderPass.field_0x1c8");
static_assert(offsetof(mmShaderPass, container_3) == 0x1F8, "mmShaderPass.container_3");
static_assert(offsetof(mmShaderPass, vtable_deref_0x780) == 0x780, "mmShaderPass.vtable_deref_0x780");

/* ========================================================================
 * mmShaderResourceBindList
 * Evidence: state_surface 17 fields. ctor initializes two containers + trailing ptrs.
 * dtor pattern matches s2. Containers at +0x68, +0x98. Data/func ptrs at +0xC8..+0xE8.
 * Size: >= 0xF0 (last field at +0xE8 + 8)
 * Methods: ctor(0x13DCA0,0x673020), dtor(0x144BE0), Add(0x144C20), Clear(0x164D40),
 *          Find(0x144EC0), Merge(0x145010) = 7
 * Vtable: func ptrs at +0xE0/+0xE8
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x58];         /* +0x00: unknown/vtable region */
    uint32_t count_0x58;            /* +0x58: uint32 init 0 */
    uint8_t pad_0x5c[0x0c];         /* +0x5C: gap */
    uint8_t container_0[0x30];      /* +0x68: container group 0 */
    uint8_t container_1[0x24];      /* +0x98: container group 1 */
    uint32_t field_0xbc;            /* +0xBC: uint32 init 0 */
    uint64_t dat_ptr_0xc0;          /* +0xC0: data ptr (ctor) */
    uint64_t dat_ptr_0xc8;          /* +0xC8: &DAT_1482d8290 */
    uint64_t dat_ptr_0xd0;          /* +0xD0: &DAT_1482d8290 */
    uint64_t dat_ptr_0xd8;          /* +0xD8: &DAT_1482d8291 */
    uint64_t func_ptr_0xe0;         /* +0xE0: &PTR_LAB_140a1dc50 */
    uint64_t func_ptr_0xe8;         /* +0xE8: &PTR_FUN_140a1c498 */
    /* size unknown, >= 0xF0 */
} mmShaderResourceBindList;

static_assert(offsetof(mmShaderResourceBindList, count_0x58) == 0x58, "mmShaderResourceBindList.count_0x58");
static_assert(offsetof(mmShaderResourceBindList, container_0) == 0x68, "mmShaderResourceBindList.container_0");
static_assert(offsetof(mmShaderResourceBindList, container_1) == 0x98, "mmShaderResourceBindList.container_1");
static_assert(offsetof(mmShaderResourceBindList, field_0xbc) == 0xBC, "mmShaderResourceBindList.field_0xbc");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xc0) == 0xC0, "mmShaderResourceBindList.dat_ptr_0xc0");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xc8) == 0xC8, "mmShaderResourceBindList.dat_ptr_0xc8");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xd0) == 0xD0, "mmShaderResourceBindList.dat_ptr_0xd0");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xd8) == 0xD8, "mmShaderResourceBindList.dat_ptr_0xd8");
static_assert(offsetof(mmShaderResourceBindList, func_ptr_0xe0) == 0xE0, "mmShaderResourceBindList.func_ptr_0xe0");
static_assert(offsetof(mmShaderResourceBindList, func_ptr_0xe8) == 0xE8, "mmShaderResourceBindList.func_ptr_0xe8");

/* ========================================================================
 * mmShaderEffect
 * Evidence: state_surface 4 fields. dtor calls FUN_1401495e0 on strings at
 * param_1+0xf, +0x14, +0x19 which as longlong* indices = offsets +0x78, +0xA0, +0xC8.
 * RegisterVertexShader dereferences vtable at *param_1+0x10 (=vtable slot 2).
 * Size: >= 0xF0 (last string at +0xC8 + 0x28 = 0xF0 minimum)
 * Methods: 9 total (RegisterVertexShader, RegisterPixelShader, etc.)
 * Vtable: dereferenced at +0x00 in RegisterVertexShader
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vtable_ptr;            /* +0x00: vtable (deref in RegisterVertexShader) */
    uint8_t pad_0x08[0x70];         /* +0x08: gap to first string */
    uint8_t name_0[0x28];           /* +0x78: mmBasicString (dtor param_1+0xf) */
    uint8_t name_1[0x28];           /* +0xA0: mmBasicString (dtor param_1+0x14) */
    uint8_t name_2[0x28];           /* +0xC8: mmBasicString (dtor param_1+0x19) */
    /* size unknown, >= 0xF0 */
} mmShaderEffect;

static_assert(offsetof(mmShaderEffect, vtable_ptr) == 0x00, "mmShaderEffect.vtable_ptr");
static_assert(offsetof(mmShaderEffect, name_0) == 0x78, "mmShaderEffect.name_0");
static_assert(offsetof(mmShaderEffect, name_1) == 0xA0, "mmShaderEffect.name_1");
static_assert(offsetof(mmShaderEffect, name_2) == 0xC8, "mmShaderEffect.name_2");

/* ========================================================================
 * mmScriptTranslatorManager
 * Evidence: state_surface 38 fields from ctor. Repeating 0x50-byte translator slots
 * visible at +0x58, +0xA8, +0xF8, +0x148, +0x198, +0x1E8, +0x238, +0x288, +0x2D8
 * (each passed to distinct FUN_14015xxxx functions). Func ptrs written at +0x328, +0x378,
 * +0x418, +0x468 in groups of 4 slots each. Container-like reads follow at +0x330..+0x4A0.
 * Size: >= 0x4B0 (last field at +0x4A8 + 8; matches s2 reference)
 * Methods: CreateInstance(0x163540), DestroyInstance(0x163A40), ctor(0x164340) = 3
 * Vtable: not identified
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t header[0x58];               /* +0x00: unknown header */
    uint8_t translator_0[0x50];         /* +0x58: translator slot 0 (FUN_14015e110) */
    uint8_t translator_1[0x50];         /* +0xA8: translator slot 1 (FUN_14015e2d0) */
    uint8_t translator_2[0x50];         /* +0xF8: translator slot 2 (FUN_14015e390) */
    uint8_t translator_3[0x50];         /* +0x148: translator slot 3 (FUN_14015e450) */
    uint8_t translator_4[0x50];         /* +0x198: translator slot 4 (FUN_14015e510) */
    uint8_t translator_5[0x50];         /* +0x1E8: translator slot 5 (FUN_14015e650) */
    uint8_t translator_6[0x50];         /* +0x238: translator slot 6 (FUN_14015e790) */
    uint8_t translator_7[0x50];         /* +0x288: translator slot 7 (FUN_14015e8d0) */
    uint8_t translator_8[0x50];         /* +0x2D8: translator slot 8 (FUN_14015e990) */
    uint8_t container_group_0[0x30];    /* +0x328: func ptr + container (ctor writes) */
    uint8_t container_group_1[0x30];    /* +0x358: gap-adjusted container region */
    uint8_t container_group_2[0x30];    /* +0x388: container region */
    uint8_t container_group_3[0x30];    /* +0x3B8: container region */
    uint8_t container_group_4[0x30];    /* +0x3E8: func ptr + container (ctor writes) */
    uint8_t container_group_5[0x30];    /* +0x418: container region */
    uint8_t container_group_6[0x30];    /* +0x448: container region */
    uint8_t container_group_7[0x30];    /* +0x478: tail container */
    uint8_t pad_0x4a8[0x08];            /* +0x4A8: tail padding */
    /* size unknown, >= 0x4B0 */
} mmScriptTranslatorManager;

static_assert(offsetof(mmScriptTranslatorManager, header) == 0x00, "mmScriptTranslatorManager.header");
static_assert(offsetof(mmScriptTranslatorManager, translator_0) == 0x58, "mmScriptTranslatorManager.translator_0");
static_assert(offsetof(mmScriptTranslatorManager, translator_1) == 0xA8, "mmScriptTranslatorManager.translator_1");
static_assert(offsetof(mmScriptTranslatorManager, translator_2) == 0xF8, "mmScriptTranslatorManager.translator_2");
static_assert(offsetof(mmScriptTranslatorManager, translator_3) == 0x148, "mmScriptTranslatorManager.translator_3");
static_assert(offsetof(mmScriptTranslatorManager, translator_4) == 0x198, "mmScriptTranslatorManager.translator_4");
static_assert(offsetof(mmScriptTranslatorManager, translator_5) == 0x1E8, "mmScriptTranslatorManager.translator_5");
static_assert(offsetof(mmScriptTranslatorManager, translator_6) == 0x238, "mmScriptTranslatorManager.translator_6");
static_assert(offsetof(mmScriptTranslatorManager, translator_7) == 0x288, "mmScriptTranslatorManager.translator_7");
static_assert(offsetof(mmScriptTranslatorManager, translator_8) == 0x2D8, "mmScriptTranslatorManager.translator_8");
static_assert(offsetof(mmScriptTranslatorManager, container_group_0) == 0x328, "mmScriptTranslatorManager.container_group_0");
static_assert(offsetof(mmScriptTranslatorManager, container_group_4) == 0x3E8, "mmScriptTranslatorManager.container_group_4");
static_assert(offsetof(mmScriptTranslatorManager, container_group_7) == 0x478, "mmScriptTranslatorManager.container_group_7");

#endif /* CMN32_S3_H */