/*
 * cmn32.h — Common engine/shader/script struct layouts for NARUTO STORM 2 (s2, NSUNS2.exe)
 *
 * All offsets INFERRED from static analysis of s2 decompiled code.
 * Sizes proven from ctor/dtor/operator new where noted; otherwise "size unknown, >= 0xN".
 * No sizeof asserts for unproven sizes.
 *
 * Build: s2 (NSUNS2.exe, image base 0x140000000)
 * Generated: 2026-10-19
 */

#ifndef CMN32_S2_H
#define CMN32_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * mmShaderBufferBinder
 * Evidence: dtor at 0x16EEB0 accesses three rbtrees at +0x08, +0x38, +0x68
 * with metadata loaded from +0x20, +0x50, +0x80
 * BindAll reads param_1[0..4] -> fields at +0x00,+0x08,+0x10,+0x18,+0x20
 * Size: >= 0x88 (last access at +0x80 for tree metadata)
 * Methods: ClearAll, Register(x2), BindAll, ~mmShaderBufferBinder (5 total)
 * Vtable: not identified
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t field_0x00;              /* +0x00: read in BindAll as *param_1 */
    uint8_t  tree_region_0[0x30];     /* +0x08: rbtree+meta region (dtor: FUN(p+8, *(p+0x20))) */
    uint8_t  tree_region_1[0x30];     /* +0x38: rbtree+meta region (dtor: FUN(p+0x38, *(p+0x50))) */
    uint8_t  tree_region_2[0x28];     /* +0x68: rbtree+meta region (dtor: FUN(p+0x68, *(p+0x80))) */
    /* size unknown, >= 0x88 */
} mmShaderBufferBinder;

static_assert(offsetof(mmShaderBufferBinder, field_0x00) == 0x00, "mmShaderBufferBinder.field_0x00");
static_assert(offsetof(mmShaderBufferBinder, tree_region_0) == 0x08, "mmShaderBufferBinder.tree_region_0");
static_assert(offsetof(mmShaderBufferBinder, tree_region_1) == 0x38, "mmShaderBufferBinder.tree_region_1");
static_assert(offsetof(mmShaderBufferBinder, tree_region_2) == 0x68, "mmShaderBufferBinder.tree_region_2");

/* ========================================================================
 * mmShaderCBufferInfoList
 * Evidence: ctor at 0x169900 initializes param_1[0..8] and self-ptr at param_1+5
 * dtor accesses containers at +0x60, +0x90 with metadata
 * Size: >= 0xC0 (dtor accesses through +0xB8)
 * Methods: ctor, dtor, Add, Remove, GetCount (5 total)
 * Vtable: not identified
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t container_group_0[0x60];  /* +0x00: first container group (ctor inits param_1[0..8]) */
    uint8_t container_group_1[0x30];  /* +0x60: second container (dtor: FUN(p+0x60,...)) */
    uint8_t container_group_2[0x30];  /* +0x90: third container (dtor: FUN(p+0x90,...)) */
    /* size unknown, >= 0xC0 */
} mmShaderCBufferInfoList;

static_assert(offsetof(mmShaderCBufferInfoList, container_group_0) == 0x00, "mmShaderCBufferInfoList.container_group_0");
static_assert(offsetof(mmShaderCBufferInfoList, container_group_1) == 0x60, "mmShaderCBufferInfoList.container_group_1");
static_assert(offsetof(mmShaderCBufferInfoList, container_group_2) == 0x90, "mmShaderCBufferInfoList.container_group_2");

/* ========================================================================
 * mmShaderEffectCompiler
 * Evidence: ctor writes func ptr at +0x58, flags at +0x60
 * Compile reads vfuncs at +0x80, +0xC0, +0x100 via vtable deref
 * Size: >= 0x108 (state_surface max offset 0x100 + ptr)
 * Methods: ctor, Compile, ~mmShaderEffectCompiler (3 total)
 * Vtable: func ptrs at +0x58 (PTR_FUN_1408cede8)
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x58];          /* +0x00: unknown header */
    uint64_t func_ptr_0x58;           /* +0x58: PTR_FUN_1408cede8 (ctor write) */
    uint32_t flags_0x60;              /* +0x60: uint32 (high conf write in Compile & ctor) */
    uint8_t  pad_0x64[0x1c];          /* +0x64: gap */
    uint64_t vfunc_read_0x80;         /* +0x80: vtable deref read in Compile */
    uint8_t  pad_0x88[0x38];          /* +0x88: gap */
    uint64_t vfunc_read_0xc0;         /* +0xC0: vtable deref read in Compile */
    uint8_t  pad_0xc8[0x38];          /* +0xC8: gap */
    uint64_t vfunc_read_0x100;        /* +0x100: vtable deref read in Compile */
    /* size unknown, >= 0x108 */
} mmShaderEffectCompiler;

static_assert(offsetof(mmShaderEffectCompiler, func_ptr_0x58) == 0x58, "mmShaderEffectCompiler.func_ptr_0x58");
static_assert(offsetof(mmShaderEffectCompiler, flags_0x60) == 0x60, "mmShaderEffectCompiler.flags_0x60");
static_assert(offsetof(mmShaderEffectCompiler, vfunc_read_0x80) == 0x80, "mmShaderEffectCompiler.vfunc_read_0x80");
static_assert(offsetof(mmShaderEffectCompiler, vfunc_read_0xc0) == 0xC0, "mmShaderEffectCompiler.vfunc_read_0xc0");
static_assert(offsetof(mmShaderEffectCompiler, vfunc_read_0x100) == 0x100, "mmShaderEffectCompiler.vfunc_read_0x100");

/* ========================================================================
 * mmShaderPass
 * Evidence: ctor initializes extensively; state_surface 28 fields
 * Submit reads/writes pass_type at +0x60, vtable deref at +0xF0
 * Embedded render_state block at +0xF8
 * 4 container groups at +0x70, +0xA0, +0xD0, +0x1F8
 * Size: >= 0x788 (state_surface max offset 0x780 + ptr deref)
 * Methods: ctor, Submit, ~mmShaderPass (3+ total)
 * Vtable: dereferenced at *param_1+0xF0 in Submit
 * SIM fields: 1 (pass_type_0x60 set to 7)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x58];          /* +0x00: unknown/vtable region */
    uint64_t func_ptr_0x58;           /* +0x58: PTR_FUN_1408cede8 (ctor write) */
    uint32_t pass_type_0x60;          /* +0x60: uint32, set to 7 (SIM) */
    uint8_t  pad_0x64[0x0c];          /* +0x64: gap */
    uint8_t  container_0[0x30];       /* +0x70: container group 0 */
    uint8_t  container_1[0x30];       /* +0xA0: container group 1 */
    uint8_t  container_2[0x28];       /* +0xD0: container group 2 */
    uint8_t  render_state[0xD0];      /* +0xF8: embedded render state (FUN_1401642d0) */
    uint64_t field_0x1c8;             /* +0x1C8: rw in Submit */
    uint64_t field_0x1d0;             /* +0x1D0: init 0 */
    uint64_t field_0x1d8;             /* +0x1D8: init 0 */
    uint64_t field_0x1e0;             /* +0x1E0: init 0 */
    uint8_t  pad_0x1e8[0x10];         /* +0x1E8: gap */
    uint8_t  container_3[0x20];       /* +0x1F8: container group 3 */
    uint8_t  pad_0x218[0x568];        /* +0x218: large gap to 0x780 */
    uint64_t vtable_deref_0x780;      /* +0x780: vtable check in Submit */
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
 * Evidence: ctor initializes two containers + trailing metadata ptrs
 * state_surface 17 fields, dtor pattern matches s1
 * Size: >= 0xF0 (last field at +0xE8)
 * Methods: ctor, dtor, Add, Remove, Find, GetCount, Clear (7 total)
 * Vtable: func ptrs at +0xE0/+0xE8
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x58];          /* +0x00: unknown/vtable region */
    uint32_t count_0x58;              /* +0x58: uint32 init 0 */
    uint8_t  pad_0x5c[0x0c];          /* +0x5C: gap */
    uint8_t  container_0[0x30];       /* +0x68: container group 0 */
    uint8_t  container_1[0x24];       /* +0x98: container group 1 (0x24 bytes to reach 0xBC) */
    uint32_t field_0xbc;              /* +0xBC: uint32 init 0 */
    uint64_t dat_ptr_0xc0;            /* +0xC0: &DAT_148110be0 */
    uint64_t dat_ptr_0xc8;            /* +0xC8: &DAT_148110be0 */
    uint64_t dat_ptr_0xd0;            /* +0xD0: &DAT_148110be1 */
    uint64_t func_ptr_0xd8;           /* +0xD8: PTR_LAB_1408cee18 */
    uint64_t func_ptr_0xe0;           /* +0xE0: PTR_FUN_1408cede8 */
    uint64_t field_0xe8;              /* +0xE8: tail */
    /* size unknown, >= 0xF0 */
} mmShaderResourceBindList;

static_assert(offsetof(mmShaderResourceBindList, count_0x58) == 0x58, "mmShaderResourceBindList.count_0x58");
static_assert(offsetof(mmShaderResourceBindList, container_0) == 0x68, "mmShaderResourceBindList.container_0");
static_assert(offsetof(mmShaderResourceBindList, container_1) == 0x98, "mmShaderResourceBindList.container_1");
static_assert(offsetof(mmShaderResourceBindList, field_0xbc) == 0xBC, "mmShaderResourceBindList.field_0xbc");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xc0) == 0xC0, "mmShaderResourceBindList.dat_ptr_0xc0");
static_assert(offsetof(mmShaderResourceBindList, func_ptr_0xe0) == 0xE0, "mmShaderResourceBindList.func_ptr_0xe0");
static_assert(offsetof(mmShaderResourceBindList, field_0xe8) == 0xE8, "mmShaderResourceBindList.field_0xe8");

/* ========================================================================
 * mmShaderEffect
 * Evidence: dtor calls format() on strings at param_1+0xf,+0x14,+0x19
 *   which as uint64* indices means offsets +0x78, +0xA0, +0xC8 (each *8)
 * RegisterVertexShader dereferences vtable at *param_1+0x10 -> offset +0x80?
 *   Actually *param_1 is the vtable ptr at +0x00, +0x10 is vtable slot offset.
 * state_surface 4 fields
 * Size: >= 0xF0 (last string at +0xC8 + 0x28 = 0xF0 minimum)
 * Methods: 9 total (RegisterVertexShader, RegisterPixelShader, etc.)
 * Vtable: dereferenced at +0x00 in RegisterVertexShader
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vtable_ptr;              /* +0x00: vtable (deref in RegisterVertexShader) */
    uint8_t  pad_0x08[0x70];          /* +0x08: gap to first string */
    uint8_t  name_0[0x28];            /* +0x78: mmBasicString (dtor param_1+0xf) */
    uint8_t  name_1[0x28];            /* +0xA0: mmBasicString (dtor param_1+0x14) */
    uint8_t  name_2[0x28];            /* +0xC8: mmBasicString (dtor param_1+0x19) */
    /* size unknown, >= 0xF0 */
} mmShaderEffect;

static_assert(offsetof(mmShaderEffect, vtable_ptr) == 0x00, "mmShaderEffect.vtable_ptr");
static_assert(offsetof(mmShaderEffect, name_0) == 0x78, "mmShaderEffect.name_0");
static_assert(offsetof(mmShaderEffect, name_1) == 0xA0, "mmShaderEffect.name_1");
static_assert(offsetof(mmShaderEffect, name_2) == 0xC8, "mmShaderEffect.name_2");

/* ========================================================================
 * mmScriptTranslatorManager
 * Evidence: state_surface from Initialize shows repeating 0x50-byte translator slots
 * 9 translator slots at +0x08..+0x2D0 (each 0x50 bytes)
 * Container groups follow at observed offsets from dtor/Initialize
 * Size: >= 0x4B0 (from s1 reference, adjusted for s2 offsets)
 * Methods: ctor, dtor, Initialize (3 total)
 * Vtable: not identified
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t field_0x00;              /* +0x00: unknown (possibly vtable or flags) */
    uint8_t  translators[0x2C8];      /* +0x08: 9 x 0x50-byte translator slots (0x08..0x2CF) */
    uint8_t  container_group_0[0x30]; /* +0x2D0: container group 0 */
    uint8_t  container_group_1[0x30]; /* +0x300: container group 1 */
    uint8_t  container_group_2[0x30]; /* +0x330: container group 2 */
    uint8_t  container_group_3[0x30]; /* +0x360: container group 3 */
    uint8_t  container_group_4[0x30]; /* +0x390: container group 4 */
    uint8_t  container_group_5[0x30]; /* +0x3C0: container group 5 */
    uint8_t  pad_0x3f0[0xc0];         /* +0x3F0: gap to end */
    /* size unknown, >= 0x4B0 */
} mmScriptTranslatorManager;

static_assert(offsetof(mmScriptTranslatorManager, field_0x00) == 0x00, "mmScriptTranslatorManager.field_0x00");
static_assert(offsetof(mmScriptTranslatorManager, translators) == 0x08, "mmScriptTranslatorManager.translators");
static_assert(offsetof(mmScriptTranslatorManager, container_group_0) == 0x2D0, "mmScriptTranslatorManager.container_group_0");
static_assert(offsetof(mmScriptTranslatorManager, container_group_1) == 0x300, "mmScriptTranslatorManager.container_group_1");
static_assert(offsetof(mmScriptTranslatorManager, container_group_2) == 0x330, "mmScriptTranslatorManager.container_group_2");
static_assert(offsetof(mmScriptTranslatorManager, container_group_3) == 0x360, "mmScriptTranslatorManager.container_group_3");
static_assert(offsetof(mmScriptTranslatorManager, container_group_4) == 0x390, "mmScriptTranslatorManager.container_group_4");
static_assert(offsetof(mmScriptTranslatorManager, container_group_5) == 0x3C0, "mmScriptTranslatorManager.container_group_5");

#endif /* CMN32_S2_H */