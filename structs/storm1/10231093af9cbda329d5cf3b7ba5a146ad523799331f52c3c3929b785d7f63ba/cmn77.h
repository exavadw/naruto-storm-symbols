/* cmn77.h — NARUTO STORM 1 (s1) common struct group cmn77
 * Generated: 2026-10-19
 * Build: s1 (NSUNS1.exe, image base 0x140000000)
 * Source: the decompiler cache state_surface + decomp cache
 * All fields INFERRED (static analysis only, no runtime confirmation)
 * Own-game naming: s1 sources only (ns1:: from Switch Trilogy, Storm 1 strings/code)
 */

#ifndef CMN77_S1_H
#define CMN77_S1_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

/* =========================================================================
 * nummShader
 * Size: 0x358 (proven by operator new in nummShaderManager::Bank::Load @ 0x458440)
 * Vtable: PTR_LAB_140774620 (set in ctor @ 0x454F90)
 * Fields: 43 from state_surface, named where evidence supports it
 * ========================================================================= */
typedef struct __attribute__((packed)) nummShader {
    /* 0x000 */ void *vtable;                          /* PTR_LAB_140774620, set in ctor */
    /* 0x008 */ uint32_t flags_a;                      /* param_3 from ctor call */
    /* 0x00C */ uint32_t flags_b;                      /* param_4 from ctor call */
    /* 0x010 */ uint32_t init_param_copy;              /* *(uint*)(param_2+8) copied in ctor */
    /* 0x014 */ uint32_t _pad_0x14;                    /* alignment padding */
    /* 0x018 */ uint8_t subobj_0x18[0x28];             /* FUN_140110440(param_1+4,1); vtable PTR_LAB_140774620 */
    /* 0x040 */ uint32_t field_0x40;                   /* zeroed in ctor (param_1[0x40]=0) */
    /* 0x044 */ uint32_t field_0x44;                   /* zeroed in ctor (param_1[0x41]=0) */
    /* 0x048 */ uint8_t subobj_0x48[0x38];             /* FUN_140110440(param_1+0x42,2); vtable PTR_LAB_140774620 */
    /* 0x080 */ uint8_t container_0x80[0x14];          /* FUN_1401154d0 init; vector-like */
    /* 0x094 */ uint8_t subobj_0x94[0xC];              /* FUN_140116b20 init */
    /* 0x0A0 */ uint8_t subobj_0xA0[0xE];              /* FUN_140116ee0 target */
    /* 0x0AE */ uint8_t list_node_0xAE[0x12];          /* self-linked list node */
    /* 0x0C0 */ uint32_t sentinel_0xC0;                /* 0xFFFFFFFF pattern */
    /* 0x0C4 */ uint32_t sentinel_0xC4;                /* 0xFFFFFFFF pattern */
    /* 0x0C8 */ uint32_t sentinel_0xC8;                /* 0xFFFFFFFF pattern */
    /* 0x0CC */ uint32_t field_0xCC;                   /* zeroed in ctor */
    /* 0x0D0 */ uint8_t vector_0xD0[0x18];             /* ptr/begin/end/capacity for allocated items */
    /* 0x0E8 */ uint8_t _pad_0xE8[0x18];               /* gap to 0x100 */
    /* 0x100 */ int32_t rw_field_0x100;                /* state_surface: rw, int32 */
    /* 0x104 */ uint32_t _pad_0x104;                   /* alignment */
    /* 0x108 */ int64_t rw_field_0x108;                /* state_surface: rw, int64 */
    /* 0x110 */ uint8_t _gap_0x110[0xE8];              /* gap to 0x1F8 */
    /* 0x1F8 */ int32_t rw_field_0x1F8;                /* state_surface: rw, int32 */
    /* 0x1FC */ uint32_t _pad_0x1FC;                   /* alignment */
    /* 0x200 */ uint8_t _gap_0x200[0x8];               /* gap to 0x208 */
    /* 0x208 */ int32_t r_field_0x208;                 /* state_surface: r, int32 */
    /* 0x20C */ uint32_t _pad_0x20C;                   /* alignment */
    /* 0x210 */ uint8_t _gap_0x210[0x40];              /* gap to 0x250 */
    /* 0x250 */ void *subobj_ref_0x250;                /* state_surface: r, passed to FUN_140116b20 */
    /* 0x258 */ uint8_t _gap_0x258[0x28];              /* gap to 0x280 */
    /* 0x280 */ void *subobj_ref_0x280;                /* state_surface: r, sub-object */
    /* 0x288 */ uint8_t _gap_0x288[0x38];              /* gap to 0x2C0 */
    /* 0x2C0 */ uint8_t ctor_init_block[0x98];         /* state_surface: mostly w, ctor init region 0x2C0-0x357 */
} nummShader_t;

static_assert(offsetof(nummShader_t, vtable) == 0x000, "nummShader::vtable");
static_assert(offsetof(nummShader_t, flags_a) == 0x008, "nummShader::flags_a");
static_assert(offsetof(nummShader_t, flags_b) == 0x00C, "nummShader::flags_b");
static_assert(offsetof(nummShader_t, init_param_copy) == 0x010, "nummShader::init_param_copy");
static_assert(offsetof(nummShader_t, subobj_0x18) == 0x018, "nummShader::subobj_0x18");
static_assert(offsetof(nummShader_t, field_0x40) == 0x040, "nummShader::field_0x40");
static_assert(offsetof(nummShader_t, field_0x44) == 0x044, "nummShader::field_0x44");
static_assert(offsetof(nummShader_t, subobj_0x48) == 0x048, "nummShader::subobj_0x48");
static_assert(offsetof(nummShader_t, container_0x80) == 0x080, "nummShader::container_0x80");
static_assert(offsetof(nummShader_t, subobj_0x94) == 0x094, "nummShader::subobj_0x94");
static_assert(offsetof(nummShader_t, subobj_0xA0) == 0x0A0, "nummShader::subobj_0xA0");
static_assert(offsetof(nummShader_t, list_node_0xAE) == 0x0AE, "nummShader::list_node_0xAE");
static_assert(offsetof(nummShader_t, sentinel_0xC0) == 0x0C0, "nummShader::sentinel_0xC0");
static_assert(offsetof(nummShader_t, vector_0xD0) == 0x0D0, "nummShader::vector_0xD0");
static_assert(offsetof(nummShader_t, rw_field_0x100) == 0x100, "nummShader::rw_field_0x100");
static_assert(offsetof(nummShader_t, rw_field_0x108) == 0x108, "nummShader::rw_field_0x108");
static_assert(offsetof(nummShader_t, rw_field_0x1F8) == 0x1F8, "nummShader::rw_field_0x1F8");
static_assert(offsetof(nummShader_t, r_field_0x208) == 0x208, "nummShader::r_field_0x208");
static_assert(offsetof(nummShader_t, subobj_ref_0x250) == 0x250, "nummShader::subobj_ref_0x250");
static_assert(offsetof(nummShader_t, subobj_ref_0x280) == 0x280, "nummShader::subobj_ref_0x280");
static_assert(offsetof(nummShader_t, ctor_init_block) == 0x2C0, "nummShader::ctor_init_block");
static_assert(sizeof(nummShader_t) == 0x358, "nummShader size proven by operator new(0x358) @ 0x458440");


/* =========================================================================
 * nummShaderManager
 * Size: 0x28C8 (proven by operator new in nummShaderCreateBuffer @ 0x456E90)
 * Vtable: PTR_FUN_140732488 (set in ctor @ 0x4553C0)
 * Fields: 18 from state_surface, all in ctor init region 0x2808-0x28C0
 * Note: large embedded structure before 0x2808 not fully characterized
 * ========================================================================= */
typedef struct __attribute__((packed)) nummShaderManager {
    /* 0x0000 */ void *vtable;                         /* PTR_FUN_140732488, set in ctor */
    /* 0x0008 */ uint8_t embedded_array[0x2800];       /* FUN_1405a55d0(puVar1,0x28,0x100,...); 0x100 entries of 0x28 bytes each */
    /* 0x2808 */ uint64_t slot_0x2808;                 /* state_surface: w, zeroed in ctor */
    /* 0x2810 */ uint64_t slot_0x2810;                 /* state_surface: w, zeroed in ctor */
    /* 0x2818 */ uint64_t slot_0x2818;                 /* state_surface: w, zeroed in ctor */
    /* 0x2820 */ uint64_t _gap_0x2820;                 /* not accessed */
    /* 0x2828 */ uint64_t slot_0x2828;                 /* state_surface: w, zeroed in ctor */
    /* 0x2830 */ uint64_t slot_0x2830;                 /* state_surface: w, zeroed in ctor */
    /* 0x2838 */ uint64_t slot_0x2838;                 /* state_surface: w, zeroed in ctor */
    /* 0x2840 */ uint64_t _gap_0x2840;                 /* not accessed */
    /* 0x2848 */ uint64_t slot_0x2848;                 /* state_surface: w, zeroed in ctor */
    /* 0x2850 */ uint64_t slot_0x2850;                 /* state_surface: w, zeroed in ctor */
    /* 0x2858 */ uint64_t slot_0x2858;                 /* state_surface: w, zeroed in ctor */
    /* 0x2860 */ uint64_t _gap_0x2860[2];              /* not accessed */
    /* 0x2870 */ void *data_ptr_0x2870;                /* state_surface: w, &DAT_14085ce10 */
    /* 0x2878 */ uint64_t count_0x2878;                /* state_surface: w, value 1 */
    /* 0x2880 */ float f_0x2880;                       /* state_surface: w, 0x3f800000 = 1.0f */
    /* 0x2884 */ double d_0x2884;                      /* state_surface: w, 0x40000000 = 2.0 */
    /* 0x288C */ uint32_t _pad_0x288C;                 /* alignment */
    /* 0x2890 */ uint8_t subobj_0x2890[0x20];          /* state_surface: r, FUN_140113c50 init */
    /* 0x28B0 */ uint64_t rw_field_0x28B0;             /* state_surface: rw, read+written in ctor */
    /* 0x28B8 */ uint8_t subobj_0x28B8[0x8];           /* state_surface: r, FUN_1400fec60 init */
    /* 0x28C0 */ uint64_t slot_0x28C0;                 /* state_surface: w, zeroed in ctor */
} nummShaderManager_t;

static_assert(offsetof(nummShaderManager_t, vtable) == 0x0000, "nummShaderManager::vtable");
static_assert(offsetof(nummShaderManager_t, embedded_array) == 0x0008, "nummShaderManager::embedded_array");
static_assert(offsetof(nummShaderManager_t, slot_0x2808) == 0x2808, "nummShaderManager::slot_0x2808");
static_assert(offsetof(nummShaderManager_t, slot_0x2810) == 0x2810, "nummShaderManager::slot_0x2810");
static_assert(offsetof(nummShaderManager_t, slot_0x2818) == 0x2818, "nummShaderManager::slot_0x2818");
static_assert(offsetof(nummShaderManager_t, slot_0x2828) == 0x2828, "nummShaderManager::slot_0x2828");
static_assert(offsetof(nummShaderManager_t, slot_0x2830) == 0x2830, "nummShaderManager::slot_0x2830");
static_assert(offsetof(nummShaderManager_t, slot_0x2838) == 0x2838, "nummShaderManager::slot_0x2838");
static_assert(offsetof(nummShaderManager_t, slot_0x2848) == 0x2848, "nummShaderManager::slot_0x2848");
static_assert(offsetof(nummShaderManager_t, slot_0x2850) == 0x2850, "nummShaderManager::slot_0x2850");
static_assert(offsetof(nummShaderManager_t, slot_0x2858) == 0x2858, "nummShaderManager::slot_0x2858");
static_assert(offsetof(nummShaderManager_t, data_ptr_0x2870) == 0x2870, "nummShaderManager::data_ptr_0x2870");
static_assert(offsetof(nummShaderManager_t, count_0x2878) == 0x2878, "nummShaderManager::count_0x2878");
static_assert(offsetof(nummShaderManager_t, f_0x2880) == 0x2880, "nummShaderManager::f_0x2880");
static_assert(offsetof(nummShaderManager_t, d_0x2884) == 0x2884, "nummShaderManager::d_0x2884");
static_assert(offsetof(nummShaderManager_t, subobj_0x2890) == 0x2890, "nummShaderManager::subobj_0x2890");
static_assert(offsetof(nummShaderManager_t, rw_field_0x28B0) == 0x28B0, "nummShaderManager::rw_field_0x28B0");
static_assert(offsetof(nummShaderManager_t, subobj_0x28B8) == 0x28B8, "nummShaderManager::subobj_0x28B8");
static_assert(offsetof(nummShaderManager_t, slot_0x28C0) == 0x28C0, "nummShaderManager::slot_0x28C0");
static_assert(sizeof(nummShaderManager_t) == 0x28C8, "nummShaderManager size proven by operator new(0x28C8) @ 0x456E90");


/* =========================================================================
 * nummSkinningComputeShader
 * Size: 0x38 (proven by operator new in nummModelManager::CreateBuffer @ 0x46B960)
 * Vtable: PTR_FUN_140734b28 (set in ctor @ 0x46A5A0)
 * Fields: 2 from state_surface + ctor-initialized fields visible in decomp
 * ========================================================================= */
typedef struct __attribute__((packed)) nummSkinningComputeShader {
    /* 0x00 */ void *vtable;                           /* PTR_FUN_140734b28, set in ctor */
    /* 0x08 */ uint32_t capacity_or_count;             /* param_1[1] in ctor, checked against uVar1 */
    /* 0x0C */ uint32_t _pad_0x0C;                     /* alignment */
    /* 0x10 */ void *data_ptr;                         /* param_1[2] = &DAT_14085ce10 */
    /* 0x18 */ uint32_t flags;                         /* param_1[3] = 1 */
    /* 0x1C */ int32_t config_value;                   /* state_surface: r, read via FUN_1400fdd70 */
    /* 0x20 */ uint32_t _pad_0x20;                     /* alignment */
    /* 0x24 */ int32_t scale_factor;                   /* state_surface: w, 0x40000000 = 2.0f */
    /* 0x28 */ uint64_t packed_float_pair;             /* param_1[4] = 0x40000000447a0000 */
    /* 0x30 */ uint32_t buffer_handle;                 /* set post-ctor: *(lVar1+0x30) = lVar2 */
    /* 0x34 */ uint32_t _pad_0x34;                     /* alignment to 0x38 */
} nummSkinningComputeShader_t;

static_assert(offsetof(nummSkinningComputeShader_t, vtable) == 0x00, "nummSkinningComputeShader::vtable");
static_assert(offsetof(nummSkinningComputeShader_t, capacity_or_count) == 0x08, "nummSkinningComputeShader::capacity_or_count");
static_assert(offsetof(nummSkinningComputeShader_t, data_ptr) == 0x10, "nummSkinningComputeShader::data_ptr");
static_assert(offsetof(nummSkinningComputeShader_t, flags) == 0x18, "nummSkinningComputeShader::flags");
static_assert(offsetof(nummSkinningComputeShader_t, config_value) == 0x1C, "nummSkinningComputeShader::config_value");
static_assert(offsetof(nummSkinningComputeShader_t, scale_factor) == 0x24, "nummSkinningComputeShader::scale_factor");
static_assert(offsetof(nummSkinningComputeShader_t, packed_float_pair) == 0x28, "nummSkinningComputeShader::packed_float_pair");
static_assert(offsetof(nummSkinningComputeShader_t, buffer_handle) == 0x30, "nummSkinningComputeShader::buffer_handle");
static_assert(sizeof(nummSkinningComputeShader_t) == 0x38, "nummSkinningComputeShader size proven by operator new(0x38) @ 0x46B960");


/* =========================================================================
 * nummSharedSamplerState
 * Size: 0x28 (proven by operator new in Create @ 0x47CAD0)
 * No instance methods access param_1 as object pointer (state_surface: 0 fields)
 * Layout reconstructed from Create method body only
 * ========================================================================= */
typedef struct __attribute__((packed)) nummSharedSamplerState {
    /* 0x00 */ uint32_t flags;                         /* bits manipulated in Create: &0xfffffff3|3, &0xffff000f */
    /* 0x04 */ uint32_t _pad_0x04;                     /* alignment */
    /* 0x08 */ uint32_t field_0x08;                    /* zeroed in Create */
    /* 0x0C */ float f_0x0C;                           /* 0x41800000 = 16.0f, set in Create */
    /* 0x10 */ uint8_t subobj_0x10[0x18];              /* FUN_140113c50/FUN_140113c60 init pair */
} nummSharedSamplerState_t;

static_assert(offsetof(nummSharedSamplerState_t, flags) == 0x00, "nummSharedSamplerState::flags");
static_assert(offsetof(nummSharedSamplerState_t, field_0x08) == 0x08, "nummSharedSamplerState::field_0x08");
static_assert(offsetof(nummSharedSamplerState_t, f_0x0C) == 0x0C, "nummSharedSamplerState::f_0x0C");
static_assert(offsetof(nummSharedSamplerState_t, subobj_0x10) == 0x10, "nummSharedSamplerState::subobj_0x10");
static_assert(sizeof(nummSharedSamplerState_t) == 0x28, "nummSharedSamplerState size proven by operator new(0x28) @ 0x47CAD0");


/* =========================================================================
 * nummSharedRenderState
 * Size: 0xD8 (proven by operator new in Create @ 0x47CA70)
 * No instance methods access param_1 as object pointer (state_surface: 0 fields)
 * Layout reconstructed from Create method body only; inner init via FUN_1401107c0
 * ========================================================================= */
typedef struct __attribute__((packed)) nummSharedRenderState {
    /* 0x00 */ uint8_t opaque_body[0xD8];              /* initialized by FUN_1401107c0; bit ops at offset 0x20 */
} nummSharedRenderState_t;

static_assert(sizeof(nummSharedRenderState_t) == 0xD8, "nummSharedRenderState size proven by operator new(0xD8) @ 0x47CA70");


/* =========================================================================
 * nummShaderManager::Bank
 * Size: unknown, >= 0x20 (minimum from Bank::Load param_1 accesses: param_1+2 through param_1+6)
 * state_surface returned 0 fields; Load uses param_1 as a vector-like container
 * No operator new size found in decompiled callers
 * ========================================================================= */
typedef struct __attribute__((packed)) nummShaderManager_Bank {
    /* 0x00 */ uint8_t opaque_body[0x20];              /* minimum proven extent from Bank::Load */
} nummShaderManager_Bank_t;

/* No sizeof assert: size unproven */

#endif /* CMN77_S1_H */