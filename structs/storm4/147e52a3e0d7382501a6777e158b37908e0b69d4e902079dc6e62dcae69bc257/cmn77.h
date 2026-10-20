/* cmn77 struct group — build s4 (NSUNS4_release.exe, NARUTO STORM 4 PC 1.09)
 * Reconstructed from decompiled code + state_surface. All static analysis = INFERRED.
 * Sizes proven from operator_new / mmAppAllocator::Allocate call sites.
 * Storm 4 has no ns3:: namespace; names carried from s3 header where layout matches.
 * Offsets are PC x64 (image base 0x140000000).
 */
#ifndef CMN77_S4_H
#define CMN77_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nummShader — size 0x358 proven via nummShaderManager::Bank::Load (RVA 0x9E9F00):
 * operator_new(0x358,0,0x10) → placement new ctor
 * Vtable: PTR_LAB_1412f8758 (set in ctor at param_1+4 after mmShaderResourceBindList init)
 * param_1 is uint* (4-byte stride) in ctor
 */
typedef struct __attribute__((packed)) {
/* 0x000 */ uint32_t flags_a;                /* ctor: param_3 */
/* 0x004 */ uint32_t flags_b;                /* ctor: param_4 */
/* 0x008 */ uint32_t init_param_copy;        /* ctor: *(uint*)(param_2+8) */
/* 0x00C */ uint32_t _pad_0x00C;
/* 0x010 */ uint8_t vs_bind_list[0xF0];      /* mmShaderResourceBindList @ +0x10, vtable PTR_LAB_1412f8758 */
/* 0x100 */ int32_t rw_field_0x100;          /* surface: rw, Apply_Priority + ctor */
/* 0x104 */ uint32_t field_0x104;            /* surface: w, ctor */
/* 0x108 */ int64_t rw_field_0x108;          /* surface: rw, ctor */
/* 0x110 */ uint8_t _gap_0x110[0x08];
/* 0x118 */ uint8_t subobj_ref_0x118[0x50];  /* surface: r at 0x118 */
/* 0x168 */ uint8_t subobj_ref_0x168[0x30];  /* surface: r at 0x168 */
/* 0x198 */ uint8_t subobj_ref_0x198[0x28];  /* surface: r at 0x198 */
/* 0x1C0 */ uint8_t container_0x1C0[0x38];   /* surface: r at 0x1C0, ConstantBufferUpdateInfo::ApplyConstantBuffer */
/* 0x1F8 */ int32_t rw_field_0x1F8;          /* surface: rw, Apply_Priority + ctor */
/* 0x1FC */ uint32_t field_0x1FC;            /* surface: w, ctor */
/* 0x200 */ uint8_t subobj_ref_0x200[0x08];  /* surface: r at 0x200 */
/* 0x208 */ int32_t r_field_0x208;           /* surface: r, ctor */
/* 0x20C */ uint32_t _pad_0x20C;
/* 0x210 */ uint8_t _gap_0x210[0x40];
/* 0x250 */ void* subobj_ref_0x250;          /* surface: r */
/* 0x258 */ uint8_t _gap_0x258[0x28];
/* 0x280 */ void* subobj_ref_0x280;          /* surface: r */
/* 0x288 */ uint8_t _gap_0x288[0x30];
/* 0x2B8 */ uint8_t subobj_ref_0x2B8[0x08];  /* surface: r */
/* 0x2C0 */ uint8_t ctor_init_block[0x90];   /* surface: mostly w, ctor init region 0x2C0-0x34C */
/* 0x350 */ uint8_t _gap_0x350[0x8];
} nummShader;
static_assert(sizeof(nummShader) == 0x358, "nummShader size");
static_assert(offsetof(nummShader, flags_a) == 0x000, "flags_a");
static_assert(offsetof(nummShader, flags_b) == 0x004, "flags_b");
static_assert(offsetof(nummShader, init_param_copy) == 0x008, "init_param_copy");
static_assert(offsetof(nummShader, vs_bind_list) == 0x010, "vs_bind_list");
static_assert(offsetof(nummShader, rw_field_0x100) == 0x100, "rw_field_0x100");
static_assert(offsetof(nummShader, field_0x104) == 0x104, "field_0x104");
static_assert(offsetof(nummShader, rw_field_0x108) == 0x108, "rw_field_0x108");
static_assert(offsetof(nummShader, subobj_ref_0x118) == 0x118, "subobj_ref_0x118");
static_assert(offsetof(nummShader, subobj_ref_0x168) == 0x168, "subobj_ref_0x168");
static_assert(offsetof(nummShader, subobj_ref_0x198) == 0x198, "subobj_ref_0x198");
static_assert(offsetof(nummShader, container_0x1C0) == 0x1C0, "container_0x1C0");
static_assert(offsetof(nummShader, rw_field_0x1F8) == 0x1F8, "rw_field_0x1F8");
static_assert(offsetof(nummShader, field_0x1FC) == 0x1FC, "field_0x1FC");
static_assert(offsetof(nummShader, subobj_ref_0x200) == 0x200, "subobj_ref_0x200");
static_assert(offsetof(nummShader, r_field_0x208) == 0x208, "r_field_0x208");
static_assert(offsetof(nummShader, subobj_ref_0x250) == 0x250, "subobj_ref_0x250");
static_assert(offsetof(nummShader, subobj_ref_0x280) == 0x280, "subobj_ref_0x280");
static_assert(offsetof(nummShader, subobj_ref_0x2B8) == 0x2B8, "subobj_ref_0x2B8");
static_assert(offsetof(nummShader, ctor_init_block) == 0x2C0, "ctor_init_block");

/* nummShaderManager — size 0x28C8 inferred from ctor (RVA 0x9E6FB0):
 * _eh_vector_constructor_iterator_(puVar1,0x28,0x100,...) = 0x100 entries × 0x28 at param_1+8
 * Last field at 0x28C0 + 8 bytes = 0x28C8 total. No explicit allocator call found yet.
 * Vtable: PTR_FUN_141101cd8 (set in ctor)
 */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void* vtable;                  /* ctor: PTR_FUN_141101cd8 */
/* 0x0008 */ uint8_t embedded_array[0x2800]; /* FUN(puVar1,0x28,0x100,...); 0x100 entries × 0x28 */
/* 0x2808 */ uint64_t slot_0x2808;           /* ctor: zeroed */
/* 0x2810 */ uint64_t slot_0x2810;           /* ctor: zeroed */
/* 0x2818 */ uint64_t slot_0x2818;           /* ctor: zeroed */
/* 0x2820 */ uint64_t _pad_0x2820;
/* 0x2828 */ uint64_t slot_0x2828;           /* ctor: zeroed */
/* 0x2830 */ uint64_t slot_0x2830;           /* ctor: zeroed */
/* 0x2838 */ uint64_t slot_0x2838;           /* ctor: zeroed */
/* 0x2840 */ uint64_t _pad_0x2840;
/* 0x2848 */ uint64_t slot_0x2848;           /* ctor: zeroed */
/* 0x2850 */ uint64_t slot_0x2850;           /* ctor: zeroed */
/* 0x2858 */ uint64_t slot_0x2858;           /* ctor: zeroed */
/* 0x2860 */ uint64_t _pad_0x2860;
/* 0x2868 */ uint64_t _pad_0x2868;
/* 0x2870 */ void* data_ptr_0x2870;         /* ctor: &DAT reference */
/* 0x2878 */ uint64_t count_0x2878;          /* ctor: value 1 */
/* 0x2880 */ float f_0x2880;                 /* ctor: 1.0f */
/* 0x2884 */ double d_0x2884;                /* ctor: 2.0 */
/* 0x288C */ uint32_t _pad_0x288C;
/* 0x2890 */ uint8_t subobj_0x2890[0x20];    /* surface: r */
/* 0x28B0 */ uint64_t rw_field_0x28B0;       /* surface: rw */
/* 0x28B8 */ uint8_t subobj_0x28B8[0x8];     /* surface: r */
/* 0x28C0 */ uint64_t slot_0x28C0;           /* ctor: zeroed */
} nummShaderManager;
static_assert(sizeof(nummShaderManager) == 0x28C8, "nummShaderManager size");
static_assert(offsetof(nummShaderManager, vtable) == 0x0000, "vtable");
static_assert(offsetof(nummShaderManager, embedded_array) == 0x0008, "embedded_array");
static_assert(offsetof(nummShaderManager, slot_0x2808) == 0x2808, "slot_0x2808");
static_assert(offsetof(nummShaderManager, slot_0x2810) == 0x2810, "slot_0x2810");
static_assert(offsetof(nummShaderManager, slot_0x2818) == 0x2818, "slot_0x2818");
static_assert(offsetof(nummShaderManager, slot_0x2828) == 0x2828, "slot_0x2828");
static_assert(offsetof(nummShaderManager, slot_0x2830) == 0x2830, "slot_0x2830");
static_assert(offsetof(nummShaderManager, slot_0x2838) == 0x2838, "slot_0x2838");
static_assert(offsetof(nummShaderManager, slot_0x2848) == 0x2848, "slot_0x2848");
static_assert(offsetof(nummShaderManager, slot_0x2850) == 0x2850, "slot_0x2850");
static_assert(offsetof(nummShaderManager, slot_0x2858) == 0x2858, "slot_0x2858");
static_assert(offsetof(nummShaderManager, data_ptr_0x2870) == 0x2870, "data_ptr_0x2870");
static_assert(offsetof(nummShaderManager, count_0x2878) == 0x2878, "count_0x2878");
static_assert(offsetof(nummShaderManager, f_0x2880) == 0x2880, "f_0x2880");
static_assert(offsetof(nummShaderManager, d_0x2884) == 0x2884, "d_0x2884");
static_assert(offsetof(nummShaderManager, subobj_0x2890) == 0x2890, "subobj_0x2890");
static_assert(offsetof(nummShaderManager, rw_field_0x28B0) == 0x28B0, "rw_field_0x28B0");
static_assert(offsetof(nummShaderManager, subobj_0x28B8) == 0x28B8, "subobj_0x28B8");
static_assert(offsetof(nummShaderManager, slot_0x28C0) == 0x28C0, "slot_0x28C0");

/* nummSkinningComputeShader — size 0x38 proven via nummSkinningComputeShader::nummSkinningComputeShader (RVA 0x9FAD90):
 * mmAppAllocator::Allocate(local_res8,0x38,0x10,...)
 * Vtable: PTR_FUN_1411033a0 (set in ctor)
 * Singleton at DAT_141665ce0
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ void* vtable;                    /* ctor: PTR_FUN_1411033a0 */
/* 0x08 */ uint32_t capacity_or_count;      /* ctor: param_1[1], checked for realloc */
/* 0x0C */ uint32_t _pad_0x0C;
/* 0x10 */ void* data_ptr;                  /* ctor: &DAT reference */
/* 0x18 */ uint32_t flags;                  /* ctor: 1 */
/* 0x1C */ int32_t config_value;            /* surface: r */
/* 0x20 */ uint32_t _pad_0x20;
/* 0x24 */ int32_t scale_factor;            /* surface: w, 0x40000000 = 2.0f */
/* 0x28 */ uint64_t packed_float_pair;      /* ctor: 0x40000000447a0000 */
/* 0x30 */ uint32_t buffer_handle;          /* post-ctor: CreateBuffer sets *(lVar1+0x30) */
/* 0x34 */ uint32_t _pad_0x34;
} nummSkinningComputeShader;
static_assert(sizeof(nummSkinningComputeShader) == 0x38, "nummSkinningComputeShader size");
static_assert(offsetof(nummSkinningComputeShader, vtable) == 0x00, "vtable");
static_assert(offsetof(nummSkinningComputeShader, capacity_or_count) == 0x08, "capacity_or_count");
static_assert(offsetof(nummSkinningComputeShader, data_ptr) == 0x10, "data_ptr");
static_assert(offsetof(nummSkinningComputeShader, flags) == 0x18, "flags");
static_assert(offsetof(nummSkinningComputeShader, config_value) == 0x1C, "config_value");
static_assert(offsetof(nummSkinningComputeShader, scale_factor) == 0x24, "scale_factor");
static_assert(offsetof(nummSkinningComputeShader, packed_float_pair) == 0x28, "packed_float_pair");
static_assert(offsetof(nummSkinningComputeShader, buffer_handle) == 0x30, "buffer_handle");

/* nummSharedRenderState — size 0xD8 proven via nummSharedRenderState::Create (RVA 0x9F87A0):
 * operator_new(0xd8,0,0x10,...)
 * Opaque body initialized by mmRenderState::UpdateRenderState
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ uint8_t opaque_body[0xD8];       /* mmRenderState::UpdateRenderState init */
} nummSharedRenderState;
static_assert(sizeof(nummSharedRenderState) == 0xD8, "nummSharedRenderState size");

/* nummSharedSamplerState — size 0x28 proven via nummSharedSamplerState::Create (RVA 0x9F8800):
 * operator_new(0x28,0,0x10,...)
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ uint32_t flags;                  /* Create: &0xfffffff3|3, &0xffff000f */
/* 0x04 */ uint32_t _pad_0x04;
/* 0x08 */ uint32_t field_0x08;             /* Create: zeroed */
/* 0x0C */ float f_0x0C;                    /* Create: 0x41800000 = 16.0f */
/* 0x10 */ uint8_t subobj_0x10[0x18];       /* Create: mmSamplerData::Initialize pair */
} nummSharedSamplerState;
static_assert(sizeof(nummSharedSamplerState) == 0x28, "nummSharedSamplerState size");
static_assert(offsetof(nummSharedSamplerState, flags) == 0x00, "flags");
static_assert(offsetof(nummSharedSamplerState, field_0x08) == 0x08, "field_0x08");
static_assert(offsetof(nummSharedSamplerState, f_0x0C) == 0x0C, "f_0x0C");
static_assert(offsetof(nummSharedSamplerState, subobj_0x10) == 0x10, "subobj_0x10");

/* nummShaderManager::Bank — size unknown, >= 0x18 (eastl::vector layout from Bank::Load RVA 0x9E9F00):
 * param_1+2 = begin ptr, param_1+4 = end ptr, param_1+6 = capacity ptr
 * Each entry is a nummShader* allocated via operator_new(0x358)
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ uint8_t opaque_body[0x18];       /* minimum proven extent (eastl::vector) */
} nummShaderManager_Bank;
static_assert(sizeof(nummShaderManager_Bank) == 0x18, "nummShaderManager_Bank min size");

#endif /* CMN77_S4_H */