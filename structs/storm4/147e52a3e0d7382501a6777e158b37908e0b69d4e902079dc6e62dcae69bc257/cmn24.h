/*
 * cmn24.h - Common struct group for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 *
 * Classes: math::float4x4, math::Quat, math::ScaleOp, math::Sphere,
 *          Memory (static only), mmAllocatorBase (<3 methods, skipped),
 *          mmAlphaBlendTranslator (<3 methods, skipped)
 *
 * All layouts INFERRED from static analysis of s4 build (sha 147e52a3e0d7).
 * Image base: 0x140000000. Sizes proven from decompiled code where noted.
 *
 * OWN-GAME NAMES ONLY: all field names derived from Storm 4 (s4) symbols/strings.
 */
#ifndef CMN24_S4_H
#define CMN24_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * math::float4x4 - 4x4 row-major matrix of floats
 * Size: 0x40 (16 floats), proven from operator= (RVA 0x1BF5E0) which writes
 * param_1[0]..param_1[0xb] as undefined4* plus undefined8 at param_1+0xc and param_1+0xe
 * spanning bytes 0x00..0x3F = 0x40 total. Also confirmed by float4x4 ctor (RVA 0x1BEC50)
 * which types param_1 as undefined1(*)[16] and writes indices 0..3 = 4*16 = 0x40.
 * Vtable: none (value type, no virtual methods)
 */
typedef struct __attribute__((packed)) math_float4x4 {
    float m[4][4]; /* row-major: m[row][col], 16 floats = 0x40 bytes */
} math_float4x4;

static_assert(sizeof(math_float4x4) == 0x40, "math::float4x4 size");
static_assert(offsetof(math_float4x4, m) == 0x00, "math::float4x4::m offset");

/*
 * math::Quat - quaternion (x, y, z, w)
 * Size: 0x10 (4 floats), proven from RotateZ (RVA 0x1C1570) which reads/writes
 * param_1[0], param_1[1], param_1[2], param_1[3] as float* = 4 * 4 = 0x10 bytes.
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
 * Size: 0x0C (3 uint32), proven from ToFloat4x4 (RVA 0x1C0BC0) which reads
 * param_1[0], param_1[1], param_1[2] as uint* = 3 * 4 = 0x0C bytes.
 * Vtable: none (value type)
 * NOTE: Only 1 method in s4. Layout carried from s3 with s4 size verification.
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
 * Size: 0x10 (vec3 center + float radius), proven from Sphere ctor (RVA 0xAB1AD0)
 * which writes param_1[0], param_1[1], param_1[2], param_1[3] as float* = 4*4 = 0x10.
 * Also confirmed by MaxDistance (RVA 0x1BDBA0) reading indices 0,1,2.
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
 * Memory - static-only class (no instance data)
 * Methods in s4: Initialize (RVA 0x564B6C), Finalize (RVA 0x564B98)
 * Both are purely static, no this pointer. No struct layout needed.
 */

/*
 * mmAllocatorBase - allocator base with repeating pool descriptor entries
 * Only 1 method in s4: Construct<nummInputManager> (RVA 0x198E40). Skipped (<3 methods).
 * Listed for completeness. See s3/cmn24.h for partial layout reference.
 */

/*
 * mmAlphaBlendTranslator - script translator for alpha blend attributes
 * Only 1 method in s4: Translate (RVA 0x1B0DB0). Skipped (<3 methods).
 */

#endif /* CMN24_S4_H */