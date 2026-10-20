/*
 * cmn24.h - Common struct group for NARUTO STORM 1 PC (NSUNS1.exe, build s1)
 *
 * Classes: math::float4x4, math::Quat, math::ScaleOp, math::Sphere,
 *          Memory (static only), mmAllocatorBase, mmAlphaBlendTranslator (<3 methods, skipped)
 *
 * All layouts INFERRED from static analysis of s1 build (sha 10231093af9c).
 * Image base: 0x140000000. Sizes proven from decompiled code where noted.
 *
 * OWN-GAME NAMES ONLY: all field names derived from Storm 1 (s1) symbols/strings.
 */

#ifndef CMN24_S1_H
#define CMN24_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * math::float4x4 - 4x4 row-major matrix of floats
 * Size: 0x40 (16 floats), proven from operator= which copies indices 0..0xb as uint32
 * Evidence: math::float4x4::operator= (RVA 0x146700) writes param_1[0]..param_1[0xb]
 *           as undefined4 (4 bytes each) = 16 * 4 = 0x40 bytes
 * Vtable: none (value type, no virtual methods)
 */
typedef struct __attribute__((packed)) math_float4x4 {
    float m[4][4]; /* row-major: m[row][col] */
} math_float4x4;

static_assert(sizeof(math_float4x4) == 0x40, "math::float4x4 size");
static_assert(offsetof(math_float4x4, m) == 0x00, "math::float4x4::m offset");

/*
 * math::Quat - quaternion (x, y, z, w)
 * Size: 0x10 (4 floats), proven from ToFloat4x4 which reads param_1[0]..param_1[3] as float
 * Evidence: math::Quat::ToFloat4x4 (RVA 0x147DA0) reads *param_1, param_1[1], param_1[2], param_1[3]
 * Vtable: none (value type)
 */
typedef struct __attribute__((packed)) math_Quat {
    float x;
    float y;
    float z;
    float w;
} math_Quat;

static_assert(sizeof(math_Quat) == 0x10, "math::Quat size");
static_assert(offsetof(math_Quat, x) == 0x00, "math::Quat::x offset");
static_assert(offsetof(math_Quat, y) == 0x04, "math::Quat::y offset");
static_assert(offsetof(math_Quat, z) == 0x08, "math::Quat::z offset");
static_assert(offsetof(math_Quat, w) == 0x0C, "math::Quat::w offset");

/*
 * math::ScaleOp - scale factors for x, y, z axes
 * Size: 0x0C (3 uint32/float), proven from ToFloat4x4 which reads param_1[0], param_1[1], param_1[2] as uint
 * Evidence: math::ScaleOp::ToFloat4x4 (RVA 0x147640) reads param_1[0], param_1[1], param_1[2]
 * Vtable: none (value type)
 */
typedef struct __attribute__((packed)) math_ScaleOp {
    uint32_t sx;
    uint32_t sy;
    uint32_t sz;
} math_ScaleOp;

static_assert(sizeof(math_ScaleOp) == 0x0C, "math::ScaleOp size");
static_assert(offsetof(math_ScaleOp, sx) == 0x00, "math::ScaleOp::sx offset");
static_assert(offsetof(math_ScaleOp, sy) == 0x04, "math::ScaleOp::sy offset");
static_assert(offsetof(math_ScaleOp, sz) == 0x08, "math::ScaleOp::sz offset");

/*
 * math::Sphere - bounding sphere with center + radius
 * Size: 0x10 (vec3 center + float radius), proven from Sphere ctor (RVA 0x148720)
 *   which copies *param_2 (8 bytes = 2 floats), param_2[1] (4 bytes = 1 float) = center xyz,
 *   then writes *(param_1 + 0xc) = param_3 (radius at offset 0xC)
 * Note: RandomPointOnSurface writes to a separate output buffer (param_1 is a float4x4 out-param),
 *   NOT to the Sphere itself. The state_surface fields at 0x2C-0x3C are from that output buffer.
 * Vtable: none (value type)
 */
typedef struct __attribute__((packed)) math_Sphere {
    float center_x;
    float center_y;
    float center_z;
    float radius;
} math_Sphere;

static_assert(sizeof(math_Sphere) == 0x10, "math::Sphere size");
static_assert(offsetof(math_Sphere, center_x) == 0x00, "math::Sphere::center_x offset");
static_assert(offsetof(math_Sphere, center_y) == 0x04, "math::Sphere::center_y offset");
static_assert(offsetof(math_Sphere, center_z) == 0x08, "math::Sphere::center_z offset");
static_assert(offsetof(math_Sphere, radius) == 0x0C, "math::Sphere::radius offset");

/*
 * Memory - static-only class (no instance data)
 * Methods: Initialize (RVA 0x42C62C), Finalize (RVA 0x42C600)
 * Both call Nucc::Memory::GetBlockManager() - purely static, no this pointer.
 * No struct layout needed.
 */

/*
 * mmAllocatorBase - allocator base with repeating pool descriptor entries
 * Size: unknown, >= 0xEC (last observed write at offset 0xE8 in Construct<nummInputManager>)
 * Evidence: mmAllocatorBase::Construct<nummInputManager> (RVA 0x1158496) writes fields
 *   at offsets 0x44, 0x58, 0x60, 0x68, 0x6C, 0x70, 0x80, 0x88, 0x90, 0x94, 0x98,
 *   0xA8, 0xB0, 0xB8, 0xBC, 0xC0, 0xD0, 0xD8, 0xE0, 0xE4, 0xE8
 * Pattern: repeating 0x20-byte pool descriptor blocks starting at ~0x44
 * Vtable: not observed (only 1 method found, template instantiation)
 * NOTE: Only 1 method in s1. Listed but reconstruction is partial.
 */
typedef struct __attribute__((packed)) mmAllocatorBase {
    uint8_t _unknown_0x00[0x44];       /* 0x00-0x43: unobserved header */
    uint64_t pool0_ptr;                /* 0x44: pool pointer or size constant */
    uint8_t _pad_0x4C[0x0C];           /* 0x4C-0x57: gap */
    uint64_t pool0_vtbl_or_dat;        /* 0x58: DAT_14085ce10 reference */
    uint64_t pool0_count;              /* 0x60: count = 1 */
    uint32_t pool0_float_val;          /* 0x68: 0x3f800000 (1.0f) */
    uint32_t _pad_0x6C_val;            /* 0x6C: written as 8 bytes but low 4 = 0x40000000 */
    uint32_t pool0_zero;               /* 0x70: zero */
    uint8_t _pad_0x74[0x0C];           /* 0x74-0x7F: gap */
    uint64_t pool1_vtbl_or_dat;        /* 0x80: DAT_14085ce10 reference */
    uint64_t pool1_count;              /* 0x88: count = 1 */
    uint32_t pool1_float_val;          /* 0x90: 0x3f800000 (1.0f) */
    uint32_t _pad_0x94_val;            /* 0x94: written as 8 bytes */
    uint32_t pool1_zero;               /* 0x98: zero */
    uint8_t _pad_0x9C[0x0C];           /* 0x9C-0xA7: gap */
    uint64_t pool2_vtbl_or_dat;        /* 0xA8: DAT_14085ce10 reference */
    uint64_t pool2_count;              /* 0xB0: count = 1 */
    uint32_t pool2_float_val;          /* 0xB8: 0x3f800000 (1.0f) */
    uint32_t _pad_0xBC_val;            /* 0xBC: written as 8 bytes */
    uint32_t pool2_zero;               /* 0xC0: zero */
    uint8_t _pad_0xC4[0x0C];           /* 0xC4-0xCF: gap */
    uint64_t pool3_vtbl_or_dat;        /* 0xD0: DAT_14085ce10 reference */
    uint64_t pool3_count;              /* 0xD8: count = 1 */
    uint32_t pool3_float_val;          /* 0xE0: 0x3f800000 (1.0f) */
    uint32_t _pad_0xE4_val;            /* 0xE4: written as 8 bytes */
    uint32_t pool3_zero;               /* 0xE8: zero */
    /* size unknown, >= 0xEC */
} mmAllocatorBase;

static_assert(offsetof(mmAllocatorBase, pool0_ptr) == 0x44, "mmAllocatorBase::pool0_ptr offset");
static_assert(offsetof(mmAllocatorBase, pool0_vtbl_or_dat) == 0x58, "mmAllocatorBase::pool0_vtbl_or_dat offset");
static_assert(offsetof(mmAllocatorBase, pool0_count) == 0x60, "mmAllocatorBase::pool0_count offset");
static_assert(offsetof(mmAllocatorBase, pool0_float_val) == 0x68, "mmAllocatorBase::pool0_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool0_zero) == 0x70, "mmAllocatorBase::pool0_zero offset");
static_assert(offsetof(mmAllocatorBase, pool1_vtbl_or_dat) == 0x80, "mmAllocatorBase::pool1_vtbl_or_dat offset");
static_assert(offsetof(mmAllocatorBase, pool1_count) == 0x88, "mmAllocatorBase::pool1_count offset");
static_assert(offsetof(mmAllocatorBase, pool1_float_val) == 0x90, "mmAllocatorBase::pool1_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool1_zero) == 0x98, "mmAllocatorBase::pool1_zero offset");
static_assert(offsetof(mmAllocatorBase, pool2_vtbl_or_dat) == 0xA8, "mmAllocatorBase::pool2_vtbl_or_dat offset");
static_assert(offsetof(mmAllocatorBase, pool2_count) == 0xB0, "mmAllocatorBase::pool2_count offset");
static_assert(offsetof(mmAllocatorBase, pool2_float_val) == 0xB8, "mmAllocatorBase::pool2_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool2_zero) == 0xC0, "mmAllocatorBase::pool2_zero offset");
static_assert(offsetof(mmAllocatorBase, pool3_vtbl_or_dat) == 0xD0, "mmAllocatorBase::pool3_vtbl_or_dat offset");
static_assert(offsetof(mmAllocatorBase, pool3_count) == 0xD8, "mmAllocatorBase::pool3_count offset");
static_assert(offsetof(mmAllocatorBase, pool3_float_val) == 0xE0, "mmAllocatorBase::pool3_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool3_zero) == 0xE8, "mmAllocatorBase::pool3_zero offset");

/*
 * mmAlphaBlendTranslator - script translator for alpha blend attributes
 * Only 1 method found in s1: Translate (RVA 0x133580)
 * Skipped: < 3 methods, cannot reconstruct meaningful layout.
 * Appears to be a subclass of mmScriptTranslator (calls TranslateAttribute 8x).
 */

#endif /* CMN24_S1_H */