/*
 * cmn24.h - Common struct group for NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, build s3)
 *
 * Classes: math::float4x4, math::Quat, math::ScaleOp, math::Sphere,
 *          Memory (static only), mmAllocatorBase, mmAlphaBlendTranslator (<3 methods, skipped)
 *
 * All layouts INFERRED from static analysis of s3 build (sha 55b726e94dad). Re-committed to bring header to HEAD.
 * Image base: 0x140000000. Sizes proven from decompiled code where noted.
 *
 * OWN-GAME NAMES ONLY: all field names derived from Storm 3 (s3) symbols/strings.
 */

#ifndef CMN24_S3_H
#define CMN24_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * math::float4x4 - 4x4 row-major matrix of floats
 * Size: 0x40 (16 floats), proven from operator= (RVA 0x174900) which writes
 * param_1[0]..param_1[0xb] as undefined4 plus undefined8 at param_1+0xc and param_1+0xe
 * spanning bytes 0x00..0x3F = 0x40 total.
 * Vtable: none (value type, no virtual methods)
 */
typedef struct __attribute__((packed)) math_float4x4 {
    float m[4][4]; /* row-major: m[row][col], indices 0..0xf as float* */
} math_float4x4;

static_assert(sizeof(math_float4x4) == 0x40, "math::float4x4 size");
static_assert(offsetof(math_float4x4, m) == 0x00, "math::float4x4::m offset");

/*
 * math::Quat - quaternion (x, y, z, w)
 * Size: 0x10 (4 floats), proven from ToFloat4x4 (RVA 0x1763A0) which reads
 * param_1[0], param_1[1], param_1[2], param_1[3] as float = 4 * 4 = 0x10 bytes.
 * Also confirmed by Normalized (RVA 0x175EB0) and Conjugated (RVA 0x175F30).
 * Vtable: none (value type)
 */
typedef struct __attribute__((packed)) math_Quat {
    float x; /* 0x00 */
    float y; /* 0x04 */
    float z; /* 0x08 */
    float w; /* 0x0C */
} math_Quat;

static_assert(sizeof(math_Quat) == 0x10, "math::Quat size");
static_assert(offsetof(math_Quat, x) == 0x00, "math::Quat::x offset");
static_assert(offsetof(math_Quat, y) == 0x04, "math::Quat::y offset");
static_assert(offsetof(math_Quat, z) == 0x08, "math::Quat::z offset");
static_assert(offsetof(math_Quat, w) == 0x0C, "math::Quat::w offset");

/*
 * math::ScaleOp - scale factors for x, y, z axes
 * Size: 0x0C (3 uint32), proven from ToFloat4x4 (RVA 0x175B30) which reads
 * param_1[0], param_1[1], param_1[2] as uint = 3 * 4 = 0x0C bytes.
 * Vtable: none (value type)
 */
typedef struct __attribute__((packed)) math_ScaleOp {
    uint32_t sx; /* 0x00 */
    uint32_t sy; /* 0x04 */
    uint32_t sz; /* 0x08 */
} math_ScaleOp;

static_assert(sizeof(math_ScaleOp) == 0x0C, "math::ScaleOp size");
static_assert(offsetof(math_ScaleOp, sx) == 0x00, "math::ScaleOp::sx offset");
static_assert(offsetof(math_ScaleOp, sy) == 0x04, "math::ScaleOp::sy offset");
static_assert(offsetof(math_ScaleOp, sz) == 0x08, "math::ScaleOp::sz offset");

/*
 * math::Sphere - bounding sphere with center + radius
 * Size: 0x10 (vec3 center + float radius), proven from RandomPointOnSurface (RVA 0x736FF0)
 * which reads param_2[0], param_2[1], param_2[2], param_2[3] as float = 4 * 4 = 0x10 bytes.
 * Note: In s3, Sphere::Sphere at RVA 0x736EA0 is a real constructor (unlike s2 where it was
 * misassigned). Layout confirmed from RandomPointOnSurface.
 * Vtable: none (value type)
 */
typedef struct __attribute__((packed)) math_Sphere {
    float center_x; /* 0x00 */
    float center_y; /* 0x04 */
    float center_z; /* 0x08 */
    float radius;   /* 0x0C */
} math_Sphere;

static_assert(sizeof(math_Sphere) == 0x10, "math::Sphere size");
static_assert(offsetof(math_Sphere, center_x) == 0x00, "math::Sphere::center_x offset");
static_assert(offsetof(math_Sphere, center_y) == 0x04, "math::Sphere::center_y offset");
static_assert(offsetof(math_Sphere, center_z) == 0x08, "math::Sphere::center_z offset");
static_assert(offsetof(math_Sphere, radius) == 0x0C, "math::Sphere::radius offset");

/*
 * Memory: no instance state
 * Static-only class (no instance data). All 3 methods access zero fields on param_1
 * per the decompiler cache state_surface analysis. All call Nucc::Memory::GetBlockManager()
 * or are thunks thereof — purely static, no this pointer used.
 * Methods: Initialize (RVA 0x5B7770), Finalize (RVA 0x3A7CF4), Finalize (RVA 0x5B7744)
 * No struct layout needed.
 */

/*
 * mmAllocatorBase - allocator base with repeating pool descriptor entries
 * Size: unknown, >= 0xEC (last observed write at offset 0xE8 in Construct<nummInputManager>)
 * Evidence: mmAllocatorBase::Construct<nummInputManager> (RVA 0x148DF0) writes fields
 * at offsets 0x00-0x20 (header pointers/data), 0x40 (float 1.0f), then repeating
 * 0x28-byte pool descriptor blocks at 0x44, 0x6C, 0x94, 0xBC, 0xE4.
 * Pool block stride = 0x28 (40 bytes). Each block has pad_val at +0x00 and float/pad/zero later.
 * Vtable: not observed (only 1 method found, template instantiation)
 * NOTE: Only 1 method in s3. Listed but reconstruction is partial.
 * s3 vs s2: identical pool block pattern (5 blocks at same offsets, same values).
 */
typedef struct __attribute__((packed)) mmAllocatorBase {
    uint64_t header_ptr0;     /* 0x00: DAT_1482d8290 */
    uint64_t header_ptr1;     /* 0x08: DAT_1482d8290 */
    uint64_t header_ptr2;     /* 0x10: DAT_1482d8291 */
    uint64_t header_vtbl;     /* 0x18: PTR_LAB_140a1dc50 */
    uint64_t header_func;     /* 0x20: PTR_FUN_140a1c498 */
    uint8_t _unknown_0x28[0x08]; /* 0x28-0x2F: unobserved */
    uint64_t header_dat;      /* 0x30: DAT_140b75940 */
    uint64_t header_count;    /* 0x38: 1 */
    uint32_t header_float;    /* 0x40: 0x3f800000 (1.0f) */
    uint32_t pool0_pad_val;   /* 0x44: 0x40000000 (written as 8B) */
    uint8_t _gap_0x48[0x20];  /* 0x48-0x67: gap (32 bytes) */
    uint32_t pool1_float_val; /* 0x68: 0x3f800000 (1.0f) */
    uint32_t pool1_pad_val;   /* 0x6C: 0x40000000 (written as 8B) */
    uint8_t _gap_0x70[0x20];  /* 0x70-0x8F: gap (32 bytes) */
    uint32_t pool2_float_val; /* 0x90: 0x3f800000 (1.0f) */
    uint32_t pool2_pad_val;   /* 0x94: 0x40000000 (written as 8B) */
    uint8_t _gap_0x98[0x20];  /* 0x98-0xB7: gap (32 bytes) */
    uint32_t pool3_float_val; /* 0xB8: 0x3f800000 (1.0f) */
    uint32_t pool3_pad_val;   /* 0xBC: 0x40000000 (written as 8B) */
    uint8_t _gap_0xC0[0x20];  /* 0xC0-0xDF: gap (32 bytes) */
    uint32_t pool4_float_val; /* 0xE0: 0x3f800000 (1.0f) */
    uint32_t pool4_pad_val;   /* 0xE4: 0x40000000 (written as 8B) */
    uint32_t pool4_zero;      /* 0xE8: 0 */
    /* size unknown, >= 0xEC */
} mmAllocatorBase;

static_assert(offsetof(mmAllocatorBase, header_ptr0) == 0x00, "mmAllocatorBase::header_ptr0 offset");
static_assert(offsetof(mmAllocatorBase, header_ptr1) == 0x08, "mmAllocatorBase::header_ptr1 offset");
static_assert(offsetof(mmAllocatorBase, header_ptr2) == 0x10, "mmAllocatorBase::header_ptr2 offset");
static_assert(offsetof(mmAllocatorBase, header_vtbl) == 0x18, "mmAllocatorBase::header_vtbl offset");
static_assert(offsetof(mmAllocatorBase, header_func) == 0x20, "mmAllocatorBase::header_func offset");
static_assert(offsetof(mmAllocatorBase, _unknown_0x28) == 0x28, "mmAllocatorBase::_unknown_0x28 offset");
static_assert(offsetof(mmAllocatorBase, header_dat) == 0x30, "mmAllocatorBase::header_dat offset");
static_assert(offsetof(mmAllocatorBase, header_count) == 0x38, "mmAllocatorBase::header_count offset");
static_assert(offsetof(mmAllocatorBase, header_float) == 0x40, "mmAllocatorBase::header_float offset");
static_assert(offsetof(mmAllocatorBase, pool0_pad_val) == 0x44, "mmAllocatorBase::pool0_pad_val offset");
static_assert(offsetof(mmAllocatorBase, _gap_0x48) == 0x48, "mmAllocatorBase::_gap_0x48 offset");
static_assert(offsetof(mmAllocatorBase, pool1_float_val) == 0x68, "mmAllocatorBase::pool1_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool1_pad_val) == 0x6C, "mmAllocatorBase::pool1_pad_val offset");
static_assert(offsetof(mmAllocatorBase, _gap_0x70) == 0x70, "mmAllocatorBase::_gap_0x70 offset");
static_assert(offsetof(mmAllocatorBase, pool2_float_val) == 0x90, "mmAllocatorBase::pool2_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool2_pad_val) == 0x94, "mmAllocatorBase::pool2_pad_val offset");
static_assert(offsetof(mmAllocatorBase, _gap_0x98) == 0x98, "mmAllocatorBase::_gap_0x98 offset");
static_assert(offsetof(mmAllocatorBase, pool3_float_val) == 0xB8, "mmAllocatorBase::pool3_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool3_pad_val) == 0xBC, "mmAllocatorBase::pool3_pad_val offset");
static_assert(offsetof(mmAllocatorBase, _gap_0xC0) == 0xC0, "mmAllocatorBase::_gap_0xC0 offset");
static_assert(offsetof(mmAllocatorBase, pool4_float_val) == 0xE0, "mmAllocatorBase::pool4_float_val offset");
static_assert(offsetof(mmAllocatorBase, pool4_pad_val) == 0xE4, "mmAllocatorBase::pool4_pad_val offset");
static_assert(offsetof(mmAllocatorBase, pool4_zero) == 0xE8, "mmAllocatorBase::pool4_zero offset");

/*
 * mmAlphaBlendTranslator - script translator for alpha blend attributes
 * Only 1 method found in s3: Translate (RVA 0x161610)
 * Skipped: < 3 methods, cannot reconstruct meaningful layout.
 */

#endif /* CMN24_S3_H */