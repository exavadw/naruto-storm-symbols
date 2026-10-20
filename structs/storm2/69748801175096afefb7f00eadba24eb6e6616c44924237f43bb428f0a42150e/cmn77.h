/* cmn77 struct group — build s2 (NSUNS2.exe, NARUTO STORM 2 PC)
 * Reconstructed from decompiled code + state_surface. All static analysis = INFERRED.
 * Sizes proven from operator_new / mmAppAllocator::Allocate call sites.
 * Own-game names only (ns2:: namespace). Offsets are PC x64 (image base 0x140000000).
 */
#ifndef CMN77_S2_H
#define CMN77_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nummShader — size 0x358 proven via FUN_140568240: operator_new(0x358) → placement new ctor
 * Vtable: PTR_LAB_1408cf4c8 (set in ctor at param_1+4 after mmShaderResourceBindList init)
 */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint32_t flags_a;              /* ctor: param_3 */
    /* 0x004 */ uint32_t flags_b;              /* ctor: param_4 */
    /* 0x008 */ uint32_t init_param_copy;      /* ctor: *(uint*)(param_2+8) */
    /* 0x00C */ uint32_t _pad_0x00C;
    /* 0x010 */ uint8_t vs_bind_list[0xF0];   /* mmShaderResourceBindList @ +0x10, vtable PTR_LAB_1408cf4c8 */
    /* 0x100 */ int32_t rw_field_0x100;        /* surface: rw */
    /* 0x104 */ uint32_t field_0x104;          /* surface: w */
    /* 0x108 */ int64_t rw_field_0x108;        /* surface: rw */
    /* 0x110 */ uint8_t _gap_0x110[0x50];
    /* 0x160 */ uint8_t subobj_0x160[0x38];   /* surface: r at 0x168 */
    /* 0x198 */ uint8_t _gap_0x198[0x8];
    /* 0x1A0 */ uint8_t container_0x1A0[0x20]; /* surface: r at 0x1C0 */
    /* 0x1C0 */ uint8_t _gap_0x1C0[0x8];
    /* 0x1C8 */ uint8_t subobj_0x1C8[0x38];   /* surface: r at 0x200 */
    /* 0x200 */ uint8_t _gap_0x200[0x8];
    /* 0x208 */ int32_t r_field_0x208;         /* surface: r */
    /* 0x20C */ uint32_t _pad_0x20C;
    /* 0x210 */ uint8_t _gap_0x210[0x40];
    /* 0x250 */ void* subobj_ref_0x250;        /* surface: r */
    /* 0x258 */ uint8_t _gap_0x258[0x28];
    /* 0x280 */ void* subobj_ref_0x280;        /* surface: r */
    /* 0x288 */ uint8_t _gap_0x288[0x38];
    /* 0x2C0 */ uint8_t ctor_init_block[0x90]; /* surface: mostly w, ctor init region 0x2C0-0x34C */
    /* 0x350 */ uint8_t _gap_0x350[0x8];
} ns2_nummShader;
static_assert(sizeof(ns2_nummShader) == 0x358, "ns2_nummShader size");
static_assert(offsetof(ns2_nummShader, flags_a) == 0x000, "flags_a");
static_assert(offsetof(ns2_nummShader, flags_b) == 0x004, "flags_b");
static_assert(offsetof(ns2_nummShader, init_param_copy) == 0x008, "init_param_copy");
static_assert(offsetof(ns2_nummShader, vs_bind_list) == 0x010, "vs_bind_list");
static_assert(offsetof(ns2_nummShader, rw_field_0x100) == 0x100, "rw_field_0x100");
static_assert(offsetof(ns2_nummShader, field_0x104) == 0x104, "field_0x104");
static_assert(offsetof(ns2_nummShader, rw_field_0x108) == 0x108, "rw_field_0x108");
static_assert(offsetof(ns2_nummShader, r_field_0x208) == 0x208, "r_field_0x208");
static_assert(offsetof(ns2_nummShader, subobj_ref_0x250) == 0x250, "subobj_ref_0x250");
static_assert(offsetof(ns2_nummShader, subobj_ref_0x280) == 0x280, "subobj_ref_0x280");
static_assert(offsetof(ns2_nummShader, ctor_init_block) == 0x2C0, "ctor_init_block");

/* nummShaderManager — size 0x28C8 proven via nummShaderCreateBuffer (RVA 0x566E70):
 * mmAppAllocator::Allocate(&local_res8, 0x28c8, ...)
 * Vtable: PTR_FUN_14088cfb0 (set in ctor)
 */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ void* vtable;                  /* ctor: PTR_FUN_14088cfb0 */
    /* 0x0008 */ uint8_t embedded_array[0x2800]; /* FUN_1405a55d0(puVar1,0x28,0x100,...); 0x100 entries × 0x28 */
    /* 0x2808 */ uint64_t slot_0x2808;          /* ctor: zeroed */
    /* 0x2810 */ uint64_t slot_0x2810;          /* ctor: zeroed */
    /* 0x2818 */ uint64_t slot_0x2818;          /* ctor: zeroed */
    /* 0x2820 */ uint64_t _pad_0x2820;
    /* 0x2828 */ uint64_t slot_0x2828;          /* ctor: zeroed */
    /* 0x2830 */ uint64_t slot_0x2830;          /* ctor: zeroed */
    /* 0x2838 */ uint64_t slot_0x2838;          /* ctor: zeroed */
    /* 0x2840 */ uint64_t _pad_0x2840;
    /* 0x2848 */ uint64_t slot_0x2848;          /* ctor: zeroed */
    /* 0x2850 */ uint64_t slot_0x2850;          /* ctor: zeroed */
    /* 0x2858 */ uint64_t slot_0x2858;          /* ctor: zeroed */
    /* 0x2860 */ uint64_t _pad_0x2860;
    /* 0x2868 */ uint64_t _pad_0x2868;
    /* 0x2870 */ void* data_ptr_0x2870;         /* ctor: &DAT_140a5cbe0 reference */
    /* 0x2878 */ uint64_t count_0x2878;         /* ctor: value 1 */
    /* 0x2880 */ float f_0x2880;                /* ctor: 1.0f */
    /* 0x2884 */ double d_0x2884;               /* ctor: 2.0 */
    /* 0x288C */ uint32_t _pad_0x288C;
    /* 0x2890 */ uint8_t subobj_0x2890[0x20];   /* surface: r */
    /* 0x28B0 */ uint64_t rw_field_0x28B0;      /* surface: rw */
    /* 0x28B8 */ uint8_t subobj_0x28B8[0x8];    /* surface: r */
    /* 0x28C0 */ uint64_t slot_0x28C0;          /* ctor: zeroed */
} ns2_nummShaderManager;
static_assert(sizeof(ns2_nummShaderManager) == 0x28C8, "ns2_nummShaderManager size");
static_assert(offsetof(ns2_nummShaderManager, vtable) == 0x0000, "vtable");
static_assert(offsetof(ns2_nummShaderManager, embedded_array) == 0x0008, "embedded_array");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2808) == 0x2808, "slot_0x2808");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2810) == 0x2810, "slot_0x2810");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2818) == 0x2818, "slot_0x2818");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2828) == 0x2828, "slot_0x2828");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2830) == 0x2830, "slot_0x2830");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2838) == 0x2838, "slot_0x2838");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2848) == 0x2848, "slot_0x2848");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2850) == 0x2850, "slot_0x2850");
static_assert(offsetof(ns2_nummShaderManager, slot_0x2858) == 0x2858, "slot_0x2858");
static_assert(offsetof(ns2_nummShaderManager, data_ptr_0x2870) == 0x2870, "data_ptr_0x2870");
static_assert(offsetof(ns2_nummShaderManager, count_0x2878) == 0x2878, "count_0x2878");
static_assert(offsetof(ns2_nummShaderManager, f_0x2880) == 0x2880, "f_0x2880");
static_assert(offsetof(ns2_nummShaderManager, d_0x2884) == 0x2884, "d_0x2884");
static_assert(offsetof(ns2_nummShaderManager, subobj_0x2890) == 0x2890, "subobj_0x2890");
static_assert(offsetof(ns2_nummShaderManager, rw_field_0x28B0) == 0x28B0, "rw_field_0x28B0");
static_assert(offsetof(ns2_nummShaderManager, subobj_0x28B8) == 0x28B8, "subobj_0x28B8");
static_assert(offsetof(ns2_nummShaderManager, slot_0x28C0) == 0x28C0, "slot_0x28C0");

/* nummSkinningComputeShader — size 0x38 proven via nummModelManager::CreateBuffer (RVA 0x56C270):
 * mmAppAllocator::Allocate(&local_res20, 0x38, ...)
 * Vtable: set in ctor (PTR_FUN_1408cede8 pattern)
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void* vtable;                   /* ctor */
    /* 0x08 */ uint32_t capacity_or_count;     /* ctor: param_1[1], checked for realloc */
    /* 0x0C */ uint32_t _pad_0x0C;
    /* 0x10 */ void* data_ptr;                 /* ctor: &DAT_140a5cbf0 */
    /* 0x18 */ uint32_t flags;                 /* ctor: 1 */
    /* 0x1C */ int32_t config_value;           /* surface: r */
    /* 0x20 */ uint32_t _pad_0x20;
    /* 0x24 */ int32_t scale_factor;           /* surface: w, 0x40000000 = 2.0f */
    /* 0x28 */ uint64_t packed_float_pair;     /* ctor: 0x40000000447a0000 */
    /* 0x30 */ uint32_t buffer_handle;         /* post-ctor: CreateBuffer sets *(lVar1+0x30) */
    /* 0x34 */ uint32_t _pad_0x34;
} ns2_nummSkinningComputeShader;
static_assert(sizeof(ns2_nummSkinningComputeShader) == 0x38, "ns2_nummSkinningComputeShader size");
static_assert(offsetof(ns2_nummSkinningComputeShader, vtable) == 0x00, "vtable");
static_assert(offsetof(ns2_nummSkinningComputeShader, capacity_or_count) == 0x08, "capacity_or_count");
static_assert(offsetof(ns2_nummSkinningComputeShader, data_ptr) == 0x10, "data_ptr");
static_assert(offsetof(ns2_nummSkinningComputeShader, flags) == 0x18, "flags");
static_assert(offsetof(ns2_nummSkinningComputeShader, config_value) == 0x1C, "config_value");
static_assert(offsetof(ns2_nummSkinningComputeShader, scale_factor) == 0x24, "scale_factor");
static_assert(offsetof(ns2_nummSkinningComputeShader, packed_float_pair) == 0x28, "packed_float_pair");
static_assert(offsetof(ns2_nummSkinningComputeShader, buffer_handle) == 0x30, "buffer_handle");

/* nummSharedSamplerState — size 0x28 proven via nummSharedSamplerState::Create (RVA 0x57C8B0):
 * operator_new(0x28, ...)
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint32_t flags;                 /* Create: &0xfffffff3|3, &0xffff000f */
    /* 0x04 */ uint32_t _pad_0x04;
    /* 0x08 */ uint32_t field_0x08;            /* Create: zeroed */
    /* 0x0C */ float f_0x0C;                   /* Create: 0x41800000 = 16.0f */
    /* 0x10 */ uint8_t subobj_0x10[0x18];      /* Create: mmSamplerData::Initialize pair */
} ns2_nummSharedSamplerState;
static_assert(sizeof(ns2_nummSharedSamplerState) == 0x28, "ns2_nummSharedSamplerState size");
static_assert(offsetof(ns2_nummSharedSamplerState, flags) == 0x00, "flags");
static_assert(offsetof(ns2_nummSharedSamplerState, field_0x08) == 0x08, "field_0x08");
static_assert(offsetof(ns2_nummSharedSamplerState, f_0x0C) == 0x0C, "f_0x0C");
static_assert(offsetof(ns2_nummSharedSamplerState, subobj_0x10) == 0x10, "subobj_0x10");

/* nummSharedRenderState — size 0xD8 proven via nummSharedRenderState::Create (RVA 0x57C850):
 * operator_new(0xd8, ...)
 * Opaque body initialized by mmRenderState::UpdateRenderState; bit ops at offset 0x20.
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t opaque_body[0xD8];      /* mmRenderState::UpdateRenderState init */
} ns2_nummSharedRenderState;
static_assert(sizeof(ns2_nummSharedRenderState) == 0xD8, "ns2_nummSharedRenderState size");

/* nummShaderManager::Bank — size unknown, >= 0x20 (from Bank::Load param_1 accesses) */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t opaque_body[0x20];      /* minimum proven extent */
} ns2_nummShaderManager_Bank;
static_assert(sizeof(ns2_nummShaderManager_Bank) == 0x20, "ns2_nummShaderManager_Bank min size");

#endif /* CMN77_S2_H */