/* cmn77 struct group — build s3 (NSUNS3.exe, NARUTO STORM 3 Full Burst HD PC)
 * Reconstructed from decompiled code + state_surface. All static analysis = INFERRED.
 * Sizes proven from operator_new / mmAppAllocator::Allocate call sites.
 * Own-game names only (ns3:: namespace). Offsets are PC x64 (image base 0x140000000).
 */
#ifndef CMN77_S3_H
#define CMN77_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nummShader — size 0x358 proven via nummShaderManager::Bank::Load (RVA 0x66C170):
 * operator_new(0x358) → placement new ctor
 * Vtable: PTR_LAB_140a1ca60 (set in ctor at param_1+4 after mmShaderResourceBindList init)
 * param_1 is uint* (4-byte stride) in ctor
 */
typedef struct __attribute__((packed)) {
/* 0x000 */ uint32_t flags_a;               /* ctor: param_3 */
/* 0x004 */ uint32_t flags_b;               /* ctor: param_4 */
/* 0x008 */ uint32_t init_param_copy;       /* ctor: *(uint*)(param_2+8) */
/* 0x00C */ uint32_t _pad_0x00C;
/* 0x010 */ uint8_t vs_bind_list[0xF0];     /* mmShaderResourceBindList @ +0x10, vtable PTR_LAB_140a1ca60 */
/* 0x100 */ int32_t rw_field_0x100;         /* surface: rw, Apply_Priority + ctor */
/* 0x104 */ uint32_t field_0x104;           /* surface: w, ctor */
/* 0x108 */ int64_t rw_field_0x108;         /* surface: rw, ctor */
/* 0x110 */ uint8_t _gap_0x110[0x08];
/* 0x118 */ uint8_t subobj_ref_0x118[0x50]; /* surface: r at 0x118 */
/* 0x168 */ uint8_t subobj_ref_0x168[0x30]; /* surface: r at 0x168 */
/* 0x198 */ uint8_t subobj_ref_0x198[0x28]; /* surface: r at 0x198 */
/* 0x1C0 */ uint8_t container_0x1C0[0x38];  /* surface: r at 0x1C0, ConstantBufferUpdateInfo::ApplyConstantBuffer */
/* 0x1F8 */ int32_t rw_field_0x1F8;         /* surface: rw, Apply_Priority + ctor */
/* 0x1FC */ uint32_t field_0x1FC;           /* surface: w, ctor */
/* 0x200 */ uint8_t subobj_ref_0x200[0x08]; /* surface: r at 0x200 */
/* 0x208 */ int32_t r_field_0x208;          /* surface: r, ctor */
/* 0x20C */ uint32_t _pad_0x20C;
/* 0x210 */ uint8_t _gap_0x210[0x40];
/* 0x250 */ void* subobj_ref_0x250;         /* surface: r */
/* 0x258 */ uint8_t _gap_0x258[0x28];
/* 0x280 */ void* subobj_ref_0x280;         /* surface: r */
/* 0x288 */ uint8_t _gap_0x288[0x30];
/* 0x2B8 */ uint8_t subobj_ref_0x2B8[0x08]; /* surface: r */
/* 0x2C0 */ uint8_t ctor_init_block[0x90];  /* surface: mostly w, ctor init region 0x2C0-0x34C */
/* 0x350 */ uint8_t _gap_0x350[0x8];
} ns3_nummShader;
static_assert(sizeof(ns3_nummShader) == 0x358, "ns3_nummShader size");
static_assert(offsetof(ns3_nummShader, flags_a) == 0x000, "flags_a");
static_assert(offsetof(ns3_nummShader, flags_b) == 0x004, "flags_b");
static_assert(offsetof(ns3_nummShader, init_param_copy) == 0x008, "init_param_copy");
static_assert(offsetof(ns3_nummShader, vs_bind_list) == 0x010, "vs_bind_list");
static_assert(offsetof(ns3_nummShader, rw_field_0x100) == 0x100, "rw_field_0x100");
static_assert(offsetof(ns3_nummShader, field_0x104) == 0x104, "field_0x104");
static_assert(offsetof(ns3_nummShader, rw_field_0x108) == 0x108, "rw_field_0x108");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x118) == 0x118, "subobj_ref_0x118");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x168) == 0x168, "subobj_ref_0x168");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x198) == 0x198, "subobj_ref_0x198");
static_assert(offsetof(ns3_nummShader, container_0x1C0) == 0x1C0, "container_0x1C0");
static_assert(offsetof(ns3_nummShader, rw_field_0x1F8) == 0x1F8, "rw_field_0x1F8");
static_assert(offsetof(ns3_nummShader, field_0x1FC) == 0x1FC, "field_0x1FC");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x200) == 0x200, "subobj_ref_0x200");
static_assert(offsetof(ns3_nummShader, r_field_0x208) == 0x208, "r_field_0x208");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x250) == 0x250, "subobj_ref_0x250");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x280) == 0x280, "subobj_ref_0x280");
static_assert(offsetof(ns3_nummShader, subobj_ref_0x2B8) == 0x2B8, "subobj_ref_0x2B8");
static_assert(offsetof(ns3_nummShader, ctor_init_block) == 0x2C0, "ctor_init_block");

/* nummShaderManager — size 0x28C8 proven via nummShaderCreateBuffer (RVA 0x66AF50):
 * mmAppAllocator::Allocate(&local_res8, 0x28c8, ...)
 * Vtable: PTR_FUN_1409dab18 (set in ctor)
 */
typedef struct __attribute__((packed)) {
/* 0x0000 */ void* vtable;                  /* ctor: PTR_FUN_1409dab18 */
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
/* 0x2870 */ void* data_ptr_0x2870;          /* ctor: &DAT reference */
/* 0x2878 */ uint64_t count_0x2878;           /* ctor: value 1 */
/* 0x2880 */ float f_0x2880;                  /* ctor: 1.0f */
/* 0x2884 */ double d_0x2884;                 /* ctor: 2.0 */
/* 0x288C */ uint32_t _pad_0x288C;
/* 0x2890 */ uint8_t subobj_0x2890[0x20];    /* surface: r */
/* 0x28B0 */ uint64_t rw_field_0x28B0;        /* surface: rw */
/* 0x28B8 */ uint8_t subobj_0x28B8[0x8];      /* surface: r */
/* 0x28C0 */ uint64_t slot_0x28C0;            /* ctor: zeroed */
} ns3_nummShaderManager;
static_assert(sizeof(ns3_nummShaderManager) == 0x28C8, "ns3_nummShaderManager size");
static_assert(offsetof(ns3_nummShaderManager, vtable) == 0x0000, "vtable");
static_assert(offsetof(ns3_nummShaderManager, embedded_array) == 0x0008, "embedded_array");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2808) == 0x2808, "slot_0x2808");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2810) == 0x2810, "slot_0x2810");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2818) == 0x2818, "slot_2818");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2828) == 0x2828, "slot_0x2828");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2830) == 0x2830, "slot_0x2830");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2838) == 0x2838, "slot_0x2838");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2848) == 0x2848, "slot_0x2848");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2850) == 0x2850, "slot_0x2850");
static_assert(offsetof(ns3_nummShaderManager, slot_0x2858) == 0x2858, "slot_0x2858");
static_assert(offsetof(ns3_nummShaderManager, data_ptr_0x2870) == 0x2870, "data_ptr_0x2870");
static_assert(offsetof(ns3_nummShaderManager, count_0x2878) == 0x2878, "count_0x2878");
static_assert(offsetof(ns3_nummShaderManager, f_0x2880) == 0x2880, "f_0x2880");
static_assert(offsetof(ns3_nummShaderManager, d_0x2884) == 0x2884, "d_0x2884");
static_assert(offsetof(ns3_nummShaderManager, subobj_0x2890) == 0x2890, "subobj_0x2890");
static_assert(offsetof(ns3_nummShaderManager, rw_field_0x28B0) == 0x28B0, "rw_field_0x28B0");
static_assert(offsetof(ns3_nummShaderManager, subobj_0x28B8) == 0x28B8, "subobj_0x28B8");
static_assert(offsetof(ns3_nummShaderManager, slot_0x28C0) == 0x28C0, "slot_0x28C0");

/* nummSkinningComputeShader — size 0x38 proven via nummModelManager::CreateBuffer (RVA 0x670590):
 * mmAppAllocator::Allocate(&local_res20, 0x38, ...)
 * Vtable: PTR_FUN_1409dae50 (set in ctor)
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ void* vtable;                   /* ctor: PTR_FUN_1409dae50 */
/* 0x08 */ uint32_t capacity_or_count;     /* ctor: param_1[1], checked for realloc */
/* 0x0C */ uint32_t _pad_0x0C;
/* 0x10 */ void* data_ptr;                 /* ctor: &DAT reference */
/* 0x18 */ uint32_t flags;                 /* ctor: 1 */
/* 0x1C */ int32_t config_value;           /* surface: r */
/* 0x20 */ uint32_t _pad_0x20;
/* 0x24 */ int32_t scale_factor;           /* surface: w, 0x40000000 = 2.0f */
/* 0x28 */ uint64_t packed_float_pair;     /* ctor: 0x40000000447a0000 */
/* 0x30 */ uint32_t buffer_handle;         /* post-ctor: CreateBuffer sets *(lVar1+0x30) */
/* 0x34 */ uint32_t _pad_0x34;
} ns3_nummSkinningComputeShader;
static_assert(sizeof(ns3_nummSkinningComputeShader) == 0x38, "ns3_nummSkinningComputeShader size");
static_assert(offsetof(ns3_nummSkinningComputeShader, vtable) == 0x00, "vtable");
static_assert(offsetof(ns3_nummSkinningComputeShader, capacity_or_count) == 0x08, "capacity_or_count");
static_assert(offsetof(ns3_nummSkinningComputeShader, data_ptr) == 0x10, "data_ptr");
static_assert(offsetof(ns3_nummSkinningComputeShader, flags) == 0x18, "flags");
static_assert(offsetof(ns3_nummSkinningComputeShader, config_value) == 0x1C, "config_value");
static_assert(offsetof(ns3_nummSkinningComputeShader, scale_factor) == 0x24, "scale_factor");
static_assert(offsetof(ns3_nummSkinningComputeShader, packed_float_pair) == 0x28, "packed_float_pair");
static_assert(offsetof(ns3_nummSkinningComputeShader, buffer_handle) == 0x30, "buffer_handle");

/* nummSharedSamplerState — size 0x28 proven via nummSharedSamplerState::Create (RVA 0x680850):
 * operator_new(0x28, ...)
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ uint32_t flags;                 /* Create: &0xfffffff3|3, &0xffff000f */
/* 0x04 */ uint32_t _pad_0x04;
/* 0x08 */ uint32_t field_0x08;            /* Create: zeroed */
/* 0x0C */ float f_0x0C;                   /* Create: 0x41800000 = 16.0f */
/* 0x10 */ uint8_t subobj_0x10[0x18];      /* Create: mmSamplerData::Initialize pair */
} ns3_nummSharedSamplerState;
static_assert(sizeof(ns3_nummSharedSamplerState) == 0x28, "ns3_nummSharedSamplerState size");
static_assert(offsetof(ns3_nummSharedSamplerState, flags) == 0x00, "flags");
static_assert(offsetof(ns3_nummSharedSamplerState, field_0x08) == 0x08, "field_0x08");
static_assert(offsetof(ns3_nummSharedSamplerState, f_0x0C) == 0x0C, "f_0x0C");
static_assert(offsetof(ns3_nummSharedSamplerState, subobj_0x10) == 0x10, "subobj_0x10");

/* nummSharedRenderState — size 0xD8 proven via nummSharedRenderState::Create (RVA 0x6807F0):
 * operator_new(0xd8, ...)
 * Opaque body initialized by mmRenderState::UpdateRenderState; bit ops at offset 0x20.
 */
typedef struct __attribute__((packed)) {
/* 0x00 */ uint8_t opaque_body[0xD8];      /* mmRenderState::UpdateRenderState init */
} ns3_nummSharedRenderState;
static_assert(sizeof(ns3_nummSharedRenderState) == 0xD8, "ns3_nummSharedRenderState size");

/* nummShaderManager::Bank — size unknown, >= 0x20 (from Bank::Load param_1 accesses) */
typedef struct __attribute__((packed)) {
/* 0x00 */ uint8_t opaque_body[0x20];      /* minimum proven extent */
} ns3_nummShaderManager_Bank;
static_assert(sizeof(ns3_nummShaderManager_Bank) == 0x20, "ns3_nummShaderManager_Bank min size");

#endif /* CMN77_S3_H */