/*
 * cmn32.h — Common engine/shader/script struct layouts for NARUTO STORM 4 (s4, NSUNS4_release.exe)
 *
 * All offsets INFERRED from static analysis of s4 decompiled code.
 * Sizes proven from ctor/dtor/operator new where noted; otherwise "size unknown, >= 0xN".
 * No sizeof asserts for unproven sizes.
 *
 * Build: s4 (NSUNS4_release.exe, image base 0x140000000, sha 147e52a3e0d7)
 * Generated: 2026-10-19
 */
#ifndef CMN32_S4_H
#define CMN32_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * mmShaderBufferBinder
 * Evidence: dtor at 0x198B60 cleans three rbtrees at +0x08, +0x38, +0x68
 * with metadata loaded from +0x20, +0x50, +0x80.
 * BindAll at 0x191DF0 reads param_1[0..4] (=+0x00,+0x08,+0x10,+0x18,+0x20).
 * Size: >= 0x88 (last access at +0x80 for tree metadata in dtor)
 * Methods: ClearAll(0x192720), Register(0x1925A0,0x192620,0x9F1690),
 *          ~mmShaderBufferBinder(0x198B60), BindAll(0x191DF0) = 6
 * Vtable: not identified
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t field_0x00[0x08];       /* +0x00: unknown header (BindAll reads param_1[0]) */
    uint8_t tree_region_0[0x18];    /* +0x08: rbtree region 0 (dtor cleans at +0x08) */
    uint8_t tree_meta_0[0x08];      /* +0x20: tree 0 metadata ptr (dtor loads from +0x20) */
    uint8_t tree_sentinel_0[0x10];  /* +0x28: sentinel/extra */
    uint8_t tree_region_1[0x18];    /* +0x38: rbtree region 1 (dtor cleans at +0x38) */
    uint8_t tree_meta_1[0x08];      /* +0x50: tree 1 metadata ptr (dtor loads from +0x50) */
    uint8_t pad_0x58[0x10];         /* +0x58: gap to tree_region_2 */
    uint8_t tree_region_2[0x18];    /* +0x68: rbtree region 2 (dtor cleans at +0x68) */
    uint8_t tree_meta_2[0x08];      /* +0x80: tree 2 metadata ptr (dtor loads from +0x80) */
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
 * Evidence: ctor at 0x1935B0 initializes param_1[0..2]=0, self-ptr at param_1+5 (=+0x28),
 * byte at param_1+8 (=+0x40), uint32 at param_1+9 (=+0x48).
 * Size: >= 0x50 (ctor last write at param_1+9 = +0x48 + 4 = 0x4C, rounded to 0x50)
 * Methods: ctor(0x1935B0), dtor(inferred), AddCBufferInfo(inferred), Clear(inferred), Merge(inferred) = 5
 * Vtable: not identified in ctor
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t header[0x28];           /* +0x00: header (ctor sets [0..2]=0) */
    uint8_t self_ptr_region[0x18];  /* +0x28: self-ptr region (ctor: param_1+5 = puVar1) */
    uint8_t flags_region[0x08];     /* +0x40: byte flag + uint32 count (ctor: param_1+8, param_1+9) */
    /* size unknown, >= 0x50 */
} mmShaderCBufferInfoList;

static_assert(offsetof(mmShaderCBufferInfoList, header) == 0x00, "mmShaderCBufferInfoList.header");
static_assert(offsetof(mmShaderCBufferInfoList, self_ptr_region) == 0x28, "mmShaderCBufferInfoList.self_ptr_region");
static_assert(offsetof(mmShaderCBufferInfoList, flags_region) == 0x40, "mmShaderCBufferInfoList.flags_region");

/* ========================================================================
 * mmShaderEffectCompiler
 * Evidence: ctor at 0x1982B0 allocates 0x110 bytes via _aligned_malloc for sub-object,
 * initializes self-ptr containers at +0x08 and +0x20, vtable-like ptrs at +0x38..+0x58,
 * uint32 flags at +0x60. Sub-object stored at *param_1 (=+0x00).
 * Size: >= 0x68 (last explicit write at +0x60 + 4 = 0x64, rounded; sub-object is separate 0x110 alloc)
 * Methods: ctor(0x1982B0), Compile(0x1984E0), ~mmShaderEffectCompiler(0x198390) = 3
 * Vtable: PTR_LAB_1412f7f18 at +0x50, PTR_FUN_1412f7ea8 at +0x58
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t sub_object_ptr;        /* +0x00: ptr to 0x110-byte aligned alloc (ctor) */
    uint8_t container_0[0x18];      /* +0x08: self-ptr container (ctor: param_1+1) */
    uint8_t container_1[0x18];      /* +0x20: self-ptr container (ctor: param_1+4) */
    uint64_t dat_ptr_0x38;          /* +0x38: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0x40;          /* +0x40: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0x48;          /* +0x48: &DAT_148d31ae9 (ctor) */
    uint64_t func_ptr_0x50;         /* +0x50: &PTR_LAB_1412f7f18 (ctor) */
    uint64_t func_ptr_0x58;         /* +0x58: &PTR_FUN_1412f7ea8 (ctor) */
    uint32_t flags_0x60;            /* +0x60: uint32 init 0 (ctor) */
    uint8_t pad_0x64[0x04];         /* +0x64: alignment padding */
    /* size unknown, >= 0x68 */
} mmShaderEffectCompiler;

static_assert(offsetof(mmShaderEffectCompiler, sub_object_ptr) == 0x00, "mmShaderEffectCompiler.sub_object_ptr");
static_assert(offsetof(mmShaderEffectCompiler, container_0) == 0x08, "mmShaderEffectCompiler.container_0");
static_assert(offsetof(mmShaderEffectCompiler, container_1) == 0x20, "mmShaderEffectCompiler.container_1");
static_assert(offsetof(mmShaderEffectCompiler, dat_ptr_0x38) == 0x38, "mmShaderEffectCompiler.dat_ptr_0x38");
static_assert(offsetof(mmShaderEffectCompiler, dat_ptr_0x40) == 0x40, "mmShaderEffectCompiler.dat_ptr_0x40");
static_assert(offsetof(mmShaderEffectCompiler, dat_ptr_0x48) == 0x48, "mmShaderEffectCompiler.dat_ptr_0x48");
static_assert(offsetof(mmShaderEffectCompiler, func_ptr_0x50) == 0x50, "mmShaderEffectCompiler.func_ptr_0x50");
static_assert(offsetof(mmShaderEffectCompiler, func_ptr_0x58) == 0x58, "mmShaderEffectCompiler.func_ptr_0x58");
static_assert(offsetof(mmShaderEffectCompiler, flags_0x60) == 0x60, "mmShaderEffectCompiler.flags_0x60");
static_assert(offsetof(mmShaderEffectCompiler, pad_0x64) == 0x64, "mmShaderEffectCompiler.pad_0x64");

/* ========================================================================
 * mmShaderPass
 * Evidence: ctor at 0x1989F0 initializes extensively through param_1[0x42] (=+0x210).
 * Self-referential container patterns at +0x70, +0xA8, +0xD8.
 * Render state init FUN_14018e780 at param_1+0x1f (=+0xF8).
 * pass_type uint32 at param_1+0xc (=+0x60) set to 7 (SIM).
 * Last ctor write at param_1[0x42] = +0x210.
 * Size: >= 0x220 (ctor writes through +0x210 + 8 = 0x218, rounded to 0x220)
 * Methods: ctor(0x1989F0), Submit(inferred), AddParameter(inferred) = 4
 * Vtable: PTR_LAB_1412f7f18 at +0x20, PTR_FUN_1412f7ea8 at +0x28
 * SIM fields: 1 (pass_type_0x60 set to 7)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t field_0x00;            /* +0x00: init 0 (ctor) */
    uint64_t dat_ptr_0x08;          /* +0x08: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0x10;          /* +0x10: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0x18;          /* +0x18: &DAT_148d31ae9 (ctor) */
    uint64_t func_ptr_0x20;         /* +0x20: &PTR_LAB_1412f7f18 (ctor) */
    uint64_t func_ptr_0x28;         /* +0x28: &PTR_FUN_1412f7ea8 (ctor) */
    uint64_t field_0x30;            /* +0x30: init 0 (ctor) */
    uint64_t dat_ptr_0x38;          /* +0x38: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0x40;          /* +0x40: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0x48;          /* +0x48: &DAT_148d31ae9 (ctor) */
    uint64_t func_ptr_0x50;         /* +0x50: &PTR_LAB_1412f7f18 (ctor) */
    uint64_t func_ptr_0x58;         /* +0x58: &PTR_FUN_1412f7ea8 (ctor) */
    uint32_t pass_type_0x60;        /* +0x60: uint32, set to 7 (SIM) */
    uint8_t pad_0x64[0x0c];         /* +0x64: gap */
    uint8_t container_0[0x38];      /* +0x70: self-ref container group 0 (ctor rw) */
    uint8_t container_1[0x30];      /* +0xA8: self-ref container group 1 (ctor rw) */
    uint8_t container_2[0x20];      /* +0xD8: self-ref container group 2 (ctor rw) */
    uint8_t render_state[0x128];    /* +0xF8: embedded render state (FUN_14018e780 init at param_1+0x1f) */
    uint8_t tail_region[0x10];      /* +0x220: region up to last ctor write at param_1[0x42]=+0x210 */
    /* size unknown, >= 0x220 */
} mmShaderPass;

static_assert(offsetof(mmShaderPass, field_0x00) == 0x00, "mmShaderPass.field_0x00");
static_assert(offsetof(mmShaderPass, dat_ptr_0x08) == 0x08, "mmShaderPass.dat_ptr_0x08");
static_assert(offsetof(mmShaderPass, dat_ptr_0x10) == 0x10, "mmShaderPass.dat_ptr_0x10");
static_assert(offsetof(mmShaderPass, dat_ptr_0x18) == 0x18, "mmShaderPass.dat_ptr_0x18");
static_assert(offsetof(mmShaderPass, func_ptr_0x20) == 0x20, "mmShaderPass.func_ptr_0x20");
static_assert(offsetof(mmShaderPass, func_ptr_0x28) == 0x28, "mmShaderPass.func_ptr_0x28");
static_assert(offsetof(mmShaderPass, field_0x30) == 0x30, "mmShaderPass.field_0x30");
static_assert(offsetof(mmShaderPass, dat_ptr_0x38) == 0x38, "mmShaderPass.dat_ptr_0x38");
static_assert(offsetof(mmShaderPass, dat_ptr_0x40) == 0x40, "mmShaderPass.dat_ptr_0x40");
static_assert(offsetof(mmShaderPass, dat_ptr_0x48) == 0x48, "mmShaderPass.dat_ptr_0x48");
static_assert(offsetof(mmShaderPass, func_ptr_0x50) == 0x50, "mmShaderPass.func_ptr_0x50");
static_assert(offsetof(mmShaderPass, func_ptr_0x58) == 0x58, "mmShaderPass.func_ptr_0x58");
static_assert(offsetof(mmShaderPass, pass_type_0x60) == 0x60, "mmShaderPass.pass_type_0x60");
static_assert(offsetof(mmShaderPass, pad_0x64) == 0x64, "mmShaderPass.pad_0x64");
static_assert(offsetof(mmShaderPass, container_0) == 0x70, "mmShaderPass.container_0");
static_assert(offsetof(mmShaderPass, container_1) == 0xA8, "mmShaderPass.container_1");
static_assert(offsetof(mmShaderPass, container_2) == 0xD8, "mmShaderPass.container_2");
static_assert(offsetof(mmShaderPass, render_state) == 0xF8, "mmShaderPass.render_state");
static_assert(offsetof(mmShaderPass, tail_region) == 0x220, "mmShaderPass.tail_region");

/* ========================================================================
 * mmShaderResourceBindList
 * Evidence: ctor at 0x18E4F0 takes (param_1, param_2). Sets vtable at +0x00,
 * uint32 param_2 at +0x08, zeros at +0x10,+0x18,+0x20,+0x40,+0x48,+0x50.
 * Self-ref containers at +0x38, +0x68, +0x98. Trailing ptrs at +0xC8..+0xE8.
 * Size: >= 0xF0 (last field at +0xE8 + 8 = 0xF0)
 * Methods: ctor(0x18E4F0), dtor(inferred), Add(inferred), Clear(inferred),
 *          Find(inferred), Merge(inferred) = 7
 * Vtable: PTR__purecall_1412f8798 at +0x00
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vtable_ptr;            /* +0x00: &PTR__purecall_1412f8798 (ctor) */
    uint32_t bind_type_0x08;        /* +0x08: uint32 from param_2 (ctor) */
    uint8_t pad_0x0c[0x04];         /* +0x0C: alignment */
    uint64_t field_0x10;            /* +0x10: init 0 (ctor) */
    uint64_t field_0x18;            /* +0x18: init 0 (ctor) */
    uint64_t field_0x20;            /* +0x20: init 0 (ctor) */
    uint8_t pad_0x28[0x10];         /* +0x28: gap */
    uint8_t container_0[0x30];      /* +0x38: self-ref container (ctor: param_1+7) */
    uint8_t pad_0x68_0[0x00];       /* placeholder for alignment */
    uint8_t container_1[0x30];      /* +0x68: self-ref container (ctor: param_1+0xd) */
    uint8_t container_2[0x30];      /* +0x98: self-ref container (ctor: param_1+0x13) */
    uint32_t field_0xc8;            /* +0xC8: init 0 (ctor: param_1+0x18) */
    uint8_t pad_0xcc[0x04];         /* +0xCC: alignment */
    uint64_t dat_ptr_0xd0;          /* +0xD0: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0xd8;          /* +0xD8: &DAT_148d31ae8 (ctor) */
    uint64_t dat_ptr_0xe0;          /* +0xE0: &DAT_148d31ae9 (ctor) */
    uint64_t func_ptr_0xe8;         /* +0xE8: &PTR_LAB_1412f7f18 (ctor) */
    /* Note: ctor also writes func_ptr at param_1[0x1d]=+0xE8 and param_1[0x1c]=+0xE0 */
    /* size unknown, >= 0xF0 */
} mmShaderResourceBindList;

static_assert(offsetof(mmShaderResourceBindList, vtable_ptr) == 0x00, "mmShaderResourceBindList.vtable_ptr");
static_assert(offsetof(mmShaderResourceBindList, bind_type_0x08) == 0x08, "mmShaderResourceBindList.bind_type_0x08");
static_assert(offsetof(mmShaderResourceBindList, field_0x10) == 0x10, "mmShaderResourceBindList.field_0x10");
static_assert(offsetof(mmShaderResourceBindList, field_0x18) == 0x18, "mmShaderResourceBindList.field_0x18");
static_assert(offsetof(mmShaderResourceBindList, field_0x20) == 0x20, "mmShaderResourceBindList.field_0x20");
static_assert(offsetof(mmShaderResourceBindList, container_0) == 0x38, "mmShaderResourceBindList.container_0");
static_assert(offsetof(mmShaderResourceBindList, container_1) == 0x68, "mmShaderResourceBindList.container_1");
static_assert(offsetof(mmShaderResourceBindList, container_2) == 0x98, "mmShaderResourceBindList.container_2");
static_assert(offsetof(mmShaderResourceBindList, field_0xc8) == 0xC8, "mmShaderResourceBindList.field_0xc8");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xd0) == 0xD0, "mmShaderResourceBindList.dat_ptr_0xd0");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xd8) == 0xD8, "mmShaderResourceBindList.dat_ptr_0xd8");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xe0) == 0xE0, "mmShaderResourceBindList.dat_ptr_0xe0");
static_assert(offsetof(mmShaderResourceBindList, func_ptr_0xe8) == 0xE8, "mmShaderResourceBindList.func_ptr_0xe8");

/* ========================================================================
 * mmShaderEffect
 * Evidence: dtor at 0x198F40 calls FUN_140199630 on sub-objects at
 * param_1+5 (=+0x28), param_1+10 (=+0x50), param_1+0xf (=+0x78),
 * param_1+0x14 (=+0xA0), param_1+0x19 (=+0xC8). Also vtable dispatch at
 * *(param_1+3)+0x10 when param_1[2]-*param_1 > 1.
 * Size: >= 0xF0 (last sub-object at +0xC8 + 0x28 = 0xF0 minimum)
 * Methods: GetShaderTechnique(0x9F0280), GetVertexShader(0x1AE5D0),
 *          ~mmShaderEffect(0x198F40), GetTexture(0x1AEBC0),
 *          RegisterTexture(0x190AA0,0x199730), GetSampler(0x1926A0),
 *          RegisterTechnique(0x1998E0), RegisterVertexShader(0x18F7A0) = 9
 * Vtable: dereferenced at *param_1 in RegisterVertexShader
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vtable_or_data_ptr;    /* +0x00: vtable/data ptr (dtor checks *param_1) */
    uint8_t pad_0x08[0x08];         /* +0x08: gap */
    uint64_t count_or_end_0x10;     /* +0x10: end ptr (dtor: param_1[2]-*param_1) */
    uint64_t dispatch_base_0x18;    /* +0x18: dispatch base (dtor: *(param_1+3)+0x10) */
    uint8_t pad_0x20[0x08];         /* +0x20: gap */
    uint8_t sub_object_0[0x28];     /* +0x28: sub-object (dtor: FUN(param_1+5)) */
    uint8_t sub_object_1[0x28];     /* +0x50: sub-object (dtor: FUN(param_1+10)) */
    uint8_t sub_object_2[0x28];     /* +0x78: sub-object (dtor: FUN(param_1+0xf)) */
    uint8_t sub_object_3[0x28];     /* +0xA0: sub-object (dtor: FUN(param_1+0x14)) */
    uint8_t sub_object_4[0x28];     /* +0xC8: sub-object (dtor: FUN(param_1+0x19)) */
    /* size unknown, >= 0xF0 */
} mmShaderEffect;

static_assert(offsetof(mmShaderEffect, vtable_or_data_ptr) == 0x00, "mmShaderEffect.vtable_or_data_ptr");
static_assert(offsetof(mmShaderEffect, count_or_end_0x10) == 0x10, "mmShaderEffect.count_or_end_0x10");
static_assert(offsetof(mmShaderEffect, dispatch_base_0x18) == 0x18, "mmShaderEffect.dispatch_base_0x18");
static_assert(offsetof(mmShaderEffect, sub_object_0) == 0x28, "mmShaderEffect.sub_object_0");
static_assert(offsetof(mmShaderEffect, sub_object_1) == 0x50, "mmShaderEffect.sub_object_1");
static_assert(offsetof(mmShaderEffect, sub_object_2) == 0x78, "mmShaderEffect.sub_object_2");
static_assert(offsetof(mmShaderEffect, sub_object_3) == 0xA0, "mmShaderEffect.sub_object_3");
static_assert(offsetof(mmShaderEffect, sub_object_4) == 0xC8, "mmShaderEffect.sub_object_4");

/* ========================================================================
 * mmScriptTranslatorManager
 * Evidence: ctor at 0x1B3C60 sets vtable at +0x00, calls FUN_1401ad6f0(),
 * then initializes 9 translator slots via distinct functions at offsets
 * +0x58, +0xA8, +0xF8, +0x148, +0x198, +0x1E8, +0x238, +0x288, +0x2D8
 * (each 0x50 bytes, passed to FUN_1401ad8b0..FUN_1401ae130).
 * Self-ref containers at +0x330, +0x348, +0x360, +0x380, +0x398, +0x3B0, +0x3C8.
 * Func ptrs at +0x328, +0x378, +0x3E8, +0x418, +0x448.
 * Last ctor write at param_1+0x94 (=+0x4A0) + 8 = 0x4A8.
 * Size: >= 0x4B0 (last field at +0x4A8, rounded)
 * Methods: ctor(0x1B3C60), CreateInstance(inferred), DestroyInstance(inferred) = 3
 * Vtable: &PTR_FUN_1412f9f48 at +0x00
 * SIM fields: 0
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vtable_ptr;                /* +0x00: &PTR_FUN_1412f9f48 (ctor) */
    uint8_t header[0x50];               /* +0x08: unknown header (FUN_1401ad6f0 init) */
    uint8_t translator_0[0x50];         /* +0x58: slot 0 (FUN_1401ad8b0 at param_1+0xb) */
    uint8_t translator_1[0x50];         /* +0xA8: slot 1 (FUN_1401ada70 at param_1+0x15) */
    uint8_t translator_2[0x50];         /* +0xF8: slot 2 (FUN_1401adb30 at param_1+0x1f) */
    uint8_t translator_3[0x50];         /* +0x148: slot 3 (FUN_1401adbf0 at param_1+0x29) */
    uint8_t translator_4[0x50];         /* +0x198: slot 4 (FUN_1401adcb0 at param_1+0x33) */
    uint8_t translator_5[0x50];         /* +0x1E8: slot 5 (FUN_1401addf0 at param_1+0x3d) */
    uint8_t translator_6[0x50];         /* +0x238: slot 6 (FUN_1401adf30 at param_1+0x47) */
    uint8_t translator_7[0x50];         /* +0x288: slot 7 (FUN_1401ae070 at param_1+0x51) */
    uint8_t translator_8[0x50];         /* +0x2D8: slot 8 (FUN_1401ae130 at param_1+0x5b) */
    uint64_t func_ptr_0x328;            /* +0x328: &PTR_FUN_1412f9fc8 (ctor) */
    uint8_t container_0[0x28];          /* +0x330: self-ref container (ctor: param_1+0x66) */
    uint64_t func_ptr_0x358;            /* +0x358: placeholder */
    uint8_t container_1[0x28];          /* +0x360: self-ref container (ctor: param_1+0x6c) */
    uint64_t func_ptr_0x388;            /* +0x388: placeholder */
    uint8_t container_2[0x28];          /* +0x390: self-ref container (ctor: param_1+0x73) */
    uint64_t func_ptr_0x3b8;            /* +0x3B8: placeholder */
    uint8_t container_3[0x28];          /* +0x3C0: self-ref container (ctor: param_1+0x76) */
    uint64_t func_ptr_0x3e8;            /* +0x3E8: &PTR_FUN_1412f9f38 (ctor) */
    uint8_t container_4[0x28];          /* +0x3F0: region after func_ptr */
    uint64_t func_ptr_0x418;            /* +0x418: &PTR_FUN_1412fa020 (ctor) */
    uint8_t container_5[0x28];          /* +0x420: self-ref container (ctor: param_1+0x84) */
    uint64_t func_ptr_0x448;            /* +0x448: &PTR_FUN_1412f9f40 (ctor) */
    uint8_t container_6[0x28];          /* +0x450: self-ref container (ctor: param_1+0x8e) */
    uint8_t tail[0x38];                 /* +0x478: tail region through +0x4A8 */
    /* size unknown, >= 0x4B0 */
} mmScriptTranslatorManager;

static_assert(offsetof(mmScriptTranslatorManager, vtable_ptr) == 0x00, "mmScriptTranslatorManager.vtable_ptr");
static_assert(offsetof(mmScriptTranslatorManager, header) == 0x08, "mmScriptTranslatorManager.header");
static_assert(offsetof(mmScriptTranslatorManager, translator_0) == 0x58, "mmScriptTranslatorManager.translator_0");
static_assert(offsetof(mmScriptTranslatorManager, translator_1) == 0xA8, "mmScriptTranslatorManager.translator_1");
static_assert(offsetof(mmScriptTranslatorManager, translator_2) == 0xF8, "mmScriptTranslatorManager.translator_2");
static_assert(offsetof(mmScriptTranslatorManager, translator_3) == 0x148, "mmScriptTranslatorManager.translator_3");
static_assert(offsetof(mmScriptTranslatorManager, translator_4) == 0x198, "mmScriptTranslatorManager.translator_4");
static_assert(offsetof(mmScriptTranslatorManager, translator_5) == 0x1E8, "mmScriptTranslatorManager.translator_5");
static_assert(offsetof(mmScriptTranslatorManager, translator_6) == 0x238, "mmScriptTranslatorManager.translator_6");
static_assert(offsetof(mmScriptTranslatorManager, translator_7) == 0x288, "mmScriptTranslatorManager.translator_7");
static_assert(offsetof(mmScriptTranslatorManager, translator_8) == 0x2D8, "mmScriptTranslatorManager.translator_8");
static_assert(offsetof(mmScriptTranslatorManager, func_ptr_0x328) == 0x328, "mmScriptTranslatorManager.func_ptr_0x328");
static_assert(offsetof(mmScriptTranslatorManager, func_ptr_0x3e8) == 0x3E8, "mmScriptTranslatorManager.func_ptr_0x3e8");
static_assert(offsetof(mmScriptTranslatorManager, func_ptr_0x418) == 0x418, "mmScriptTranslatorManager.func_ptr_0x418");
static_assert(offsetof(mmScriptTranslatorManager, func_ptr_0x448) == 0x448, "mmScriptTranslatorManager.func_ptr_0x448");

#endif /* CMN32_S4_H */