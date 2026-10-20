/*
 * cmn32.h — Common engine/shader/script struct layouts for NARUTO STORM 1 (s1, NSUNS1.exe)
 *
 * All offsets INFERRED from static analysis of s1 decompiled code.
 * Sizes proven from ctor/dtor/operator new where noted; otherwise "size unknown, >= 0xN".
 * No sizeof asserts for unproven sizes.
 *
 * Build: s1 (NSUNS1.exe, image base 0x140000000)
 * Generated: 2026-10-19
 */

#ifndef CMN32_H
#define CMN32_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * eastl container stubs (opaque, size from dtor/ctor evidence)
 * ======================================================================== */

/* eastl::rbtree node pointer + allocator pattern: 0x28 bytes per tree
 * Evidence: mmShaderBufferBinder dtor accesses three trees at +0x08, +0x38, +0x68
 * Each tree: root_ptr(8) + end_node(8) + size(8) + header(8) = 0x20 or 0x28
 * We use opaque blobs sized by the gap between consecutive field offsets.
 */

/* eastl::vector-like: begin(8) + end(8) + capacity(8) = 0x18 */
typedef struct {
    uint64_t begin;      /* +0x00 */
    uint64_t end;        /* +0x08 */
    uint64_t capacity;   /* +0x10 */
} eastl_vector_stub;     /* 0x18 */

/* eastl::rbtree-like: 0x28 based on spacing in mmShaderBufferBinder */
typedef struct {
    uint8_t opaque[0x28];
} eastl_rbtree_stub;     /* 0x28 */

/* mmBasicString (eastl::basic_string): ptr(8) + size(8) + capacity(8) = 0x18
 * Evidence: mmShaderEffect dtor calls format() on 5 strings spaced 0x28 apart
 * but ctor shows param_1+5 through param_1+0x19 as longlong* indices → 0x28 stride
 * Actually from dtor: param_1+0xf, +0x14, +0x19 → offsets 0x78, 0xA0, 0xC8
 * Gap = 0x28 each → each string is 0x28 (may include inline buffer or allocator)
 */
typedef struct {
    uint8_t opaque[0x28];
} mmBasicString;         /* 0x28 */

/* ========================================================================
 * mmShaderBufferBinder
 * Evidence: dtor at 0x11AA80 accesses three rbtrees at +0x08, +0x38, +0x68
 * Size: >= 0x88 (last access at +0x80 for tree metadata)
 * Methods: ClearAll, Register(x2), BindAll, ~mmShaderBufferBinder (5 total)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t           pad_0x00[0x08];       /* +0x00: unknown (vtable or padding) */
    eastl_rbtree_stub tree_semantic_0;      /* +0x08: rbtree<mmSemantic,...> */
    uint8_t           pad_0x30[0x08];       /* +0x30: gap */
    eastl_rbtree_stub tree_semantic_1;      /* +0x38: rbtree<mmSemantic,...> */
    uint8_t           pad_0x60[0x08];       /* +0x60: gap */
    eastl_rbtree_stub tree_semantic_2;      /* +0x68: rbtree<mmSemantic,...> */
    /* 3 * 0x28 = 0x78 bytes of rbtrees, ending at 0x90 */
    uint64_t          tree_meta_0x90;       /* +0x90: tree metadata/root */
    /* size unknown, >= 0x98 */
} mmShaderBufferBinder;

static_assert(offsetof(mmShaderBufferBinder, tree_semantic_0) == 0x08, "mmShaderBufferBinder.tree_semantic_0");
static_assert(offsetof(mmShaderBufferBinder, tree_semantic_1) == 0x38, "mmShaderBufferBinder.tree_semantic_1");
static_assert(offsetof(mmShaderBufferBinder, tree_semantic_2) == 0x68, "mmShaderBufferBinder.tree_semantic_2");
static_assert(offsetof(mmShaderBufferBinder, tree_meta_0x90) == 0x90, "mmShaderBufferBinder.tree_meta_0x90");

/* ========================================================================
 * mmShaderCBufferInfoList
 * Evidence: ctor at 0x1154D0 initializes through param_1[9] (offset 0x48)
 * Contains two eastl containers (list/vector of CBufferInfo pointers)
 * Size: >= 0x50
 * Methods: ctor, dtor, Add, Remove, GetCount (5 total)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t          ptr_begin_0;          /* +0x00: container begin */
    uint64_t          ptr_end_0;            /* +0x08: container end */
    uint64_t          ptr_capacity_0;       /* +0x10: container capacity */
    uint64_t          self_ptr_0;           /* +0x18: self-referential ptr */
    uint64_t          field_0x20;           /* +0x20: initialized to 0 */
    uint64_t          field_0x28;           /* +0x28: initialized to 0 */
    uint64_t          self_ptr_1;           /* +0x30: self-referential ptr (param_1+5) */
    uint64_t          ptr_begin_1;          /* +0x38: second container begin */
    uint64_t          ptr_end_1;            /* +0x40: second container end */
    uint8_t           flag_0x48;            /* +0x48: uint8 initialized to 0 */
    uint8_t           pad_0x49[3];          /* +0x49: padding */
    uint32_t          field_0x4c;           /* +0x4C: uint32 initialized to 0 */
    /* size unknown, >= 0x50 */
} mmShaderCBufferInfoList;

static_assert(offsetof(mmShaderCBufferInfoList, ptr_begin_0) == 0x00, "mmShaderCBufferInfoList.ptr_begin_0");
static_assert(offsetof(mmShaderCBufferInfoList, self_ptr_1) == 0x30, "mmShaderCBufferInfoList.self_ptr_1");
static_assert(offsetof(mmShaderCBufferInfoList, flag_0x48) == 0x48, "mmShaderCBufferInfoList.flag_0x48");
static_assert(offsetof(mmShaderCBufferInfoList, field_0x4c) == 0x4C, "mmShaderCBufferInfoList.field_0x4c");

/* ========================================================================
 * mmShaderEffectCompiler
 * Evidence: ctor at 0x11A1D0 allocates inner 0x110 via _aligned_malloc
 * Outer object: vfunc ptrs at +0x50,+0x58, XML parser ptr at +0x00
 * state_surface: +0x58 (w), +0x60 (w, high conf), +0x80/+0xC0/+0x100 (r)
 * Size: >= 0x108 (from state_surface max offset + assumed ptr size)
 * Methods: ctor, Compile, ~mmShaderEffectCompiler (3 total)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t          xml_parser_ptr;       /* +0x00: mmScriptParserXML* (allocated 0x110) */
    uint64_t          self_ptr_0;           /* +0x08: self-referential (param_1+1) */
    uint64_t          self_end_0;           /* +0x10: end ptr */
    uint64_t          self_ptr_1;           /* +0x18: second self-ref (param_1+4) */
    uint64_t          self_end_1;           /* +0x20: second end ptr */
    uint64_t          vtable_or_func_0;     /* +0x28: PTR_LAB_1407755c0 */
    uint64_t          vtable_or_func_1;     /* +0x30: PTR_FUN_140773df8 */
    uint64_t          dat_ptr_0;            /* +0x38: &DAT_140b8d0a0 */
    uint64_t          dat_ptr_1;            /* +0x40: &DAT_140b8d0a0 */
    uint64_t          dat_ptr_2;            /* +0x48: &DAT_140b8d0a1 */
    uint64_t          func_ptr_0x50;        /* +0x50: vfunc table ptr */
    uint64_t          func_ptr_0x58;        /* +0x58: vfunc/destructor ptr */
    uint32_t          flags_0x60;           /* +0x60: uint32 (high conf write) */
    uint8_t           pad_0x64[4];          /* +0x64: padding */
    uint8_t           gap_0x68[0x18];       /* +0x68: unknown */
    uint64_t          field_0x80;           /* +0x80: read in Compile */
    uint8_t           gap_0x88[0x38];       /* +0x88: unknown */
    uint64_t          field_0xc0;           /* +0xC0: read in Compile */
    uint8_t           gap_0xc8[0x38];       /* +0xC8: unknown */
    uint64_t          field_0x100;          /* +0x100: read in Compile */
    /* size unknown, >= 0x108 */
} mmShaderEffectCompiler;

static_assert(offsetof(mmShaderEffectCompiler, xml_parser_ptr) == 0x00, "mmShaderEffectCompiler.xml_parser_ptr");
static_assert(offsetof(mmShaderEffectCompiler, func_ptr_0x58) == 0x58, "mmShaderEffectCompiler.func_ptr_0x58");
static_assert(offsetof(mmShaderEffectCompiler, flags_0x60) == 0x60, "mmShaderEffectCompiler.flags_0x60");
static_assert(offsetof(mmShaderEffectCompiler, field_0x80) == 0x80, "mmShaderEffectCompiler.field_0x80");
static_assert(offsetof(mmShaderEffectCompiler, field_0xc0) == 0xC0, "mmShaderEffectCompiler.field_0xc0");
static_assert(offsetof(mmShaderEffectCompiler, field_0x100) == 0x100, "mmShaderEffectCompiler.field_0x100");

/* ========================================================================
 * mmShaderPass
 * Evidence: ctor at 0x11A910 initializes extensively through offset 0x218+
 * state_surface: 28 fields, min_size >= 0x788
 * Contains embedded mmRenderState at +0xF8 (from ctor: operator_new(param_1+0x1f,...))
 * Multiple eastl containers (4 groups of begin/end/capacity patterns)
 * Methods: ctor, AddParameter, Submit (3 total)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t           pad_0x00[0x58];       /* +0x00: unknown/vtable region */
    uint64_t          func_ptr_0x58;        /* +0x58: PTR_FUN_140773df8 */
    uint32_t          pass_type_0x60;       /* +0x60: uint32, set to 7 in ctor */
    uint8_t           pad_0x64[4];          /* +0x64: padding */
    uint64_t          container_0_begin;    /* +0x68: eastl container group 0 */
    uint64_t          container_0_end;      /* +0x70: self-ptr in ctor */
    uint64_t          container_0_cap;      /* +0x78: init 0 */
    uint64_t          container_0_extra;    /* +0x80: init 0 */
    uint8_t           container_0_flag;     /* +0x88: uint8 init 0 */
    uint8_t           pad_0x89[3];          /* +0x89: padding */
    uint32_t          container_0_count;    /* +0x8C: uint32 init 0 (sample: *(uint32*)(p+0x12)=0 → 0x90) */
    uint8_t           pad_0x90[0x10];       /* +0x90: gap to next container */
    uint64_t          container_1_begin;    /* +0xA0: eastl container group 1 */
    uint64_t          container_1_end;      /* +0xA8: init 0 */
    uint64_t          container_1_cap;      /* +0xB0: init 0 */
    uint8_t           container_1_flag;     /* +0xB8: uint8 init 0 */
    uint8_t           pad_0xB9[3];          /* +0xB9: padding */
    uint32_t          container_1_count;    /* +0xBC: uint32 init 0 */
    uint8_t           pad_0xC0[0x10];       /* +0xC0: gap */
    uint64_t          container_2_begin;    /* +0xD0: eastl container group 2 */
    uint64_t          container_2_end;      /* +0xD8: init 0 */
    uint64_t          container_2_cap;      /* +0xE0: init 0 */
    uint8_t           container_2_flag;     /* +0xE8: uint8 init 0 */
    uint8_t           pad_0xE9[3];          /* +0xE9: padding */
    uint32_t          container_2_count;    /* +0xEC: uint32 init 0 */
    uint8_t           pad_0xF0[0x08];       /* +0xF0: gap to render state */
    uint8_t           render_state[0xD0];   /* +0xF8: embedded mmRenderState (operator_new at param_1+0x1f) */
    uint64_t          field_0x1c8;          /* +0x1C8: rw in Submit */
    uint64_t          field_0x1d0;          /* +0x1D0: init 0 */
    uint64_t          field_0x1d8;          /* +0x1D8: init 0 */
    uint64_t          field_0x1e0;          /* +0x1E0: init 0 */
    uint8_t           pad_0x1e8[0x10];      /* +0x1E8: gap */
    uint64_t          container_3_begin;    /* +0x1F8: eastl container group 3 */
    uint64_t          container_3_end;      /* +0x200: init 0 */
    uint64_t          container_3_cap;      /* +0x208: init 0 */
    uint8_t           container_3_flag;     /* +0x210: uint8 init 0 */
    uint8_t           pad_0x211[3];         /* +0x211: padding */
    uint32_t          container_3_count;    /* +0x214: uint32 init 0 */
    uint8_t           pad_0x218[0x568];     /* +0x218: large gap to 0x780 */
    uint64_t          field_0x780;          /* +0x780: read in Submit (vtable deref at +0xF0) */
    /* size unknown, >= 0x788 */
} mmShaderPass;

static_assert(offsetof(mmShaderPass, func_ptr_0x58) == 0x58, "mmShaderPass.func_ptr_0x58");
static_assert(offsetof(mmShaderPass, pass_type_0x60) == 0x60, "mmShaderPass.pass_type_0x60");
static_assert(offsetof(mmShaderPass, container_0_begin) == 0x68, "mmShaderPass.container_0_begin");
static_assert(offsetof(mmShaderPass, container_1_begin) == 0xA0, "mmShaderPass.container_1_begin");
static_assert(offsetof(mmShaderPass, container_2_begin) == 0xD0, "mmShaderPass.container_2_begin");
static_assert(offsetof(mmShaderPass, render_state) == 0xF8, "mmShaderPass.render_state");
static_assert(offsetof(mmShaderPass, field_0x1c8) == 0x1C8, "mmShaderPass.field_0x1c8");
static_assert(offsetof(mmShaderPass, container_3_begin) == 0x1F8, "mmShaderPass.container_3_begin");
static_assert(offsetof(mmShaderPass, field_0x780) == 0x780, "mmShaderPass.field_0x780");

/* ========================================================================
 * mmShaderResourceBindList
 * Evidence: ctor initializes two eastl containers + trailing metadata
 * state_surface: 17 fields, min_size >= 0xF0
 * Methods: ctor, dtor, Add, Remove, Find, GetCount, Clear (7 total)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t           pad_0x00[0x58];       /* +0x00: unknown/vtable region */
    uint32_t          count_0x58;           /* +0x58: uint32 init 0 */
    uint8_t           pad_0x5c[4];          /* +0x5C: padding */
    uint64_t          container_0_begin;    /* +0x60: eastl container 0 */
    uint64_t          container_0_end;      /* +0x68: self-ptr */
    uint64_t          container_0_cap;      /* +0x70: init 0 */
    uint64_t          container_0_extra;    /* +0x78: init 0 */
    uint8_t           container_0_flag;     /* +0x80: uint8 init 0 */
    uint8_t           pad_0x81[3];          /* +0x81: padding */
    uint32_t          container_0_count;    /* +0x84: uint32 init 0 */
    uint8_t           pad_0x88[0x10];       /* +0x88: gap */
    uint64_t          container_1_begin;    /* +0x98: eastl container 1 */
    uint64_t          container_1_end;      /* +0xA0: init 0 */
    uint64_t          container_1_cap;      /* +0xA8: init 0 */
    uint8_t           container_1_flag;     /* +0xB0: uint8 init 0 */
    uint8_t           pad_0xB1[3];          /* +0xB1: padding */
    uint32_t          container_1_count;    /* +0xB4: uint32 init 0 */
    uint32_t          field_0xb8;           /* +0xB8: uint32 init 0 */
    uint32_t          field_0xbc;           /* +0xBC: uint32 init 0 */
    uint64_t          dat_ptr_0xc0;         /* +0xC0: &DAT_140b8d0a0 */
    uint64_t          dat_ptr_0xc8;         /* +0xC8: &DAT_140b8d0a0 */
    uint64_t          dat_ptr_0xd0;         /* +0xD0: &DAT_140b8d0a1 */
    uint64_t          func_ptr_0xd8;        /* +0xD8: PTR_LAB_1407755c0 */
    uint64_t          func_ptr_0xe0;        /* +0xE0: PTR_FUN_140773df8 */
    uint8_t           pad_0xe8[0x08];       /* +0xE8: tail padding */
    /* size unknown, >= 0xF0 */
} mmShaderResourceBindList;

static_assert(offsetof(mmShaderResourceBindList, count_0x58) == 0x58, "mmShaderResourceBindList.count_0x58");
static_assert(offsetof(mmShaderResourceBindList, container_0_begin) == 0x60, "mmShaderResourceBindList.container_0_begin");
static_assert(offsetof(mmShaderResourceBindList, container_1_begin) == 0x98, "mmShaderResourceBindList.container_1_begin");
static_assert(offsetof(mmShaderResourceBindList, dat_ptr_0xc0) == 0xC0, "mmShaderResourceBindList.dat_ptr_0xc0");
static_assert(offsetof(mmShaderResourceBindList, func_ptr_0xe0) == 0xE0, "mmShaderResourceBindList.func_ptr_0xe0");

/* ========================================================================
 * mmShaderEffect
 * Evidence: dtor at 0x11AE60 calls format() on 5 mmBasicString fields
 * Strings at param_1+5,+0xa,+0xf,+0x14,+0x19 → offsets 0x28,0x50,0x78,0xA0,0xC8
 * Plus vtable deref at +0x00 and vector at +0x18 (param_1[3])
 * state_surface: 4 fields, min_size >= 0xD0
 * Methods: 9 total (RegisterVertexShader, RegisterPixelShader, etc.)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t          vtable_ptr;           /* +0x00: vtable (dereferenced in RegisterVertexShader) */
    uint64_t          field_0x08;           /* +0x08: unknown */
    uint64_t          field_0x10;           /* +0x10: unknown */
    uint64_t          vector_ptr;           /* +0x18: vector/array ptr (param_1[3]) */
    uint64_t          vector_end;           /* +0x20: vector end */
    mmBasicString     name_0;               /* +0x28: mmBasicString (dtor format param_1+5) */
    mmBasicString     name_1;               /* +0x50: mmBasicString (dtor format param_1+0xa) */
    mmBasicString     name_2;               /* +0x78: mmBasicString (dtor format param_1+0xf) */
    mmBasicString     name_3;               /* +0xA0: mmBasicString (dtor format param_1+0x14) */
    mmBasicString     name_4;               /* +0xC8: mmBasicString (dtor format param_1+0x19) */
    /* size unknown, >= 0xF0 (5 * 0x28 + 0x28 header) */
} mmShaderEffect;

static_assert(offsetof(mmShaderEffect, vtable_ptr) == 0x00, "mmShaderEffect.vtable_ptr");
static_assert(offsetof(mmShaderEffect, vector_ptr) == 0x18, "mmShaderEffect.vector_ptr");
static_assert(offsetof(mmShaderEffect, name_0) == 0x28, "mmShaderEffect.name_0");
static_assert(offsetof(mmShaderEffect, name_1) == 0x50, "mmShaderEffect.name_1");
static_assert(offsetof(mmShaderEffect, name_2) == 0x78, "mmShaderEffect.name_2");
static_assert(offsetof(mmShaderEffect, name_3) == 0xA0, "mmShaderEffect.name_3");
static_assert(offsetof(mmShaderEffect, name_4) == 0xC8, "mmShaderEffect.name_4");

/* ========================================================================
 * mmScriptTranslatorManager
 * Evidence: state_surface 38 fields, repeating 0x50-byte translator slots
 * 9 translator sub-objects at +0x58,+0xA8,+0xF8,+0x148,+0x198,+0x1E8,+0x238,+0x288,+0x2D8
 * Followed by 5 eastl container pairs at +0x328,+0x378,+0x3B8,+0x418,+0x468
 * Size: >= 0x4B0
 * Methods: ctor, dtor, Initialize (3 total)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t           pad_0x00[0x58];       /* +0x00: unknown header */
    uint8_t           translator_0[0x50];   /* +0x58: translator sub-object 0 */
    uint8_t           translator_1[0x50];   /* +0xA8: translator sub-object 1 */
    uint8_t           translator_2[0x50];   /* +0xF8: translator sub-object 2 */
    uint8_t           translator_3[0x50];   /* +0x148: translator sub-object 3 */
    uint8_t           translator_4[0x50];   /* +0x198: translator sub-object 4 */
    uint8_t           translator_5[0x50];   /* +0x1E8: translator sub-object 5 */
    uint8_t           translator_6[0x50];   /* +0x238: translator sub-object 6 */
    uint8_t           translator_7[0x50];   /* +0x288: translator sub-object 7 */
    uint8_t           translator_8[0x50];   /* +0x2D8: translator sub-object 8 */
    uint64_t          container_0_vfunc;    /* +0x328: vfunc ptr */
    uint64_t          container_0_self;     /* +0x330: self-ptr */
    uint64_t          container_0_begin;    /* +0x338: begin */
    uint64_t          container_0_pad;      /* +0x340: gap */
    uint64_t          container_0_end;      /* +0x348: end */
    uint64_t          container_0_gap;      /* +0x350: gap */
    uint64_t          container_0_cap;      /* +0x358: capacity */
    uint64_t          container_0_extra;    /* +0x360: extra */
    uint64_t          container_1_vfunc;    /* +0x368: vfunc ptr */
    uint64_t          container_1_self;     /* +0x370: self-ptr */
    uint64_t          container_1_begin;    /* +0x378: begin */
    uint64_t          container_1_pad;      /* +0x380: gap */
    uint64_t          container_1_end;      /* +0x388: end */
    uint64_t          container_1_gap;      /* +0x390: gap */
    uint64_t          container_1_cap;      /* +0x398: capacity */
    uint64_t          container_1_extra;    /* +0x3A0: extra */
    uint64_t          container_2_vfunc;    /* +0x3A8: vfunc ptr */
    uint64_t          container_2_self;     /* +0x3B0: self-ptr */
    uint64_t          container_2_begin;    /* +0x3B8: begin */
    uint64_t          container_2_pad;      /* +0x3C0: gap */
    uint64_t          container_2_end;      /* +0x3C8: end */
    uint8_t           gap_0x3d0[0x48];      /* +0x3D0: gap to next container block */
    uint64_t          container_3_vfunc;    /* +0x418: vfunc ptr */
    uint64_t          container_3_self;     /* +0x420: self-ptr */
    uint64_t          container_3_begin;    /* +0x428: begin */
    uint64_t          container_3_pad;      /* +0x430: gap */
    uint64_t          container_3_end;      /* +0x438: end */
    uint64_t          container_3_gap;      /* +0x440: gap */
    uint64_t          container_3_cap;      /* +0x448: capacity */
    uint64_t          container_3_extra;    /* +0x450: extra */
    uint64_t          container_4_vfunc;    /* +0x458: vfunc ptr */
    uint64_t          container_4_self;     /* +0x460: self-ptr */
    uint64_t          container_4_begin;    /* +0x468: begin */
    uint64_t          container_4_pad;      /* +0x470: gap */
    uint64_t          container_4_end;      /* +0x478: end */
    uint64_t          container_4_gap;      /* +0x480: gap */
    uint64_t          container_4_cap;      /* +0x488: capacity */
    uint64_t          container_4_extra;    /* +0x490: extra */
    uint64_t          container_5_vfunc;    /* +0x498: vfunc ptr (inferred from pattern) */
    uint64_t          container_5_self;     /* +0x4A0: self-ptr */
    uint64_t          container_5_begin;    /* +0x4A8: begin */
    /* size unknown, >= 0x4B0 */
} mmScriptTranslatorManager;

static_assert(offsetof(mmScriptTranslatorManager, translator_0) == 0x58, "mmScriptTranslatorManager.translator_0");
static_assert(offsetof(mmScriptTranslatorManager, translator_1) == 0xA8, "mmScriptTranslatorManager.translator_1");
static_assert(offsetof(mmScriptTranslatorManager, translator_8) == 0x2D8, "mmScriptTranslatorManager.translator_8");
static_assert(offsetof(mmScriptTranslatorManager, container_0_vfunc) == 0x328, "mmScriptTranslatorManager.container_0_vfunc");
static_assert(offsetof(mmScriptTranslatorManager, container_3_vfunc) == 0x418, "mmScriptTranslatorManager.container_3_vfunc");
static_assert(offsetof(mmScriptTranslatorManager, container_5_begin) == 0x4A8, "mmScriptTranslatorManager.container_5_begin");

/* ========================================================================
 * mmShaderCBufferStruct (small, <3 methods but has state_surface data)
 * Evidence: AddMember writes byte at +0x58; Merge reads ptr at +0x30
 * Size: >= 0x59
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t           pad_0x00[0x30];       /* +0x00: unknown */
    uint64_t          merge_ptr;            /* +0x30: pointer read in Merge */
    uint8_t           pad_0x38[0x20];       /* +0x38: gap */
    uint8_t           has_members;          /* +0x58: uint8, set to 1 in AddMember */
    /* size unknown, >= 0x59 */
} mmShaderCBufferStruct;

static_assert(offsetof(mmShaderCBufferStruct, merge_ptr) == 0x30, "mmShaderCBufferStruct.merge_ptr");
static_assert(offsetof(mmShaderCBufferStruct, has_members) == 0x58, "mmShaderCBufferStruct.has_members");

/* ========================================================================
 * mmShaderCBufferStructMember (small, 1 method)
 * Evidence: ctor writes vtable-like ptr at +0x30
 * Size: >= 0x38
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t           pad_0x00[0x30];       /* +0x00: unknown */
    uint64_t          vtable_ptr;           /* +0x30: PTR_FUN_140773df8 */
    /* size unknown, >= 0x38 */
} mmShaderCBufferStructMember;

static_assert(offsetof(mmShaderCBufferStructMember, vtable_ptr) == 0x30, "mmShaderCBufferStructMember.vtable_ptr");

#endif /* CMN32_H */