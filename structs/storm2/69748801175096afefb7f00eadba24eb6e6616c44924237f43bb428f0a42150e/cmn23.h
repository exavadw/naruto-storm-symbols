#ifndef CMN23_H
#define CMN23_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * cmn23: math::float4, math::float3x4 — INFERRED from s2 (NSUNS2.exe) decompiled code.
 * All layouts derived from PC x64 decompile; no sizeof asserts for unproven sizes.
 *
 * Evidence summary:
 *   math::float4 — 4 × float at offsets 0,4,8,12. Proven by ctor (copy 4 elements),
 *     operator+= (4 float adds), Dot3 (indices 0-2), Cross3 (indices 0-3), LengthSq3.
 *     Size = 0x10 (16 bytes). No vtable (pure value type, all methods take this as param_1).
 *
 *   math::float3x4 — 3 rows × 4 floats, row-major, stride 4 floats per row.
 *     Proven by Set3x3Part (0x19AC20): writes undefined4 indices [0,1,2], [4,5,6], [8,9,10]
 *     (skips 3,7,11 = w-column of each row). Size >= 0x30 (48 bytes, 12 floats).
 *     TransformDir reads float indices [0..8] confirming 3×3 rotation submatrix.
 *     Set (0x2FFCFC) uses undefined8* with indices up to 0x16 (byte offset 0xB0+4=0xB4),
 *     but this is a decompiler widening artifact — the actual struct is 48 bytes per
 *     Set3x3Part access pattern which is the authoritative layout source.
 *     No vtable found. Size not proven by operator new; marked as >= 0x30.
 */

typedef struct __attribute__((packed)) math_float4 {
    float x;    /* offset 0x00, evidence: ctor param_1[0], Dot3 *param_1, LengthSq3 *param_1 */
    float y;    /* offset 0x04, evidence: ctor param_1[1], Dot3 param_1[1], LengthSq3 param_1[1] */
    float z;    /* offset 0x08, evidence: ctor param_1[2], Dot3 param_1[2], LengthSq3 param_1[2] */
    float w;    /* offset 0x0C, evidence: ctor param_1[3], Cross3 param_1[3], Normalize4 */
} math_float4;

static_assert(offsetof(math_float4, x) == 0x00, "math_float4.x offset");
static_assert(offsetof(math_float4, y) == 0x04, "math_float4.y offset");
static_assert(offsetof(math_float4, z) == 0x08, "math_float4.z offset");
static_assert(offsetof(math_float4, w) == 0x0C, "math_float4.w offset");

/*
 * math::float3x4 — 3×4 matrix, row-major, 4 floats per row.
 * Rows: m[0][0..3], m[1][0..3], m[2][0..3].
 * Set3x3Part sets columns 0-2 of each row (skips column 3 / w-component).
 * TransformDir uses indices [0..8] as 3×3 rotation part.
 * Size >= 0x30 proven by last accessed field at offset 0x2C (index 10 of undefined4*).
 * No operator new found to prove exact size.
 */
typedef struct __attribute__((packed)) math_float3x4 {
    /* Row 0 */
    float m00;  /* offset 0x00, evidence: Set3x3Part param_1[0], TransformDir *param_1 */
    float m01;  /* offset 0x04, evidence: Set3x3Part param_1[1], TransformDir param_1[1] */
    float m02;  /* offset 0x08, evidence: Set3x3Part param_1[2], TransformDir param_1[2] */
    float m03;  /* offset 0x0C, evidence: Set3x3Part skips index 3 (w-column); TransformDir param_1[3] */
    /* Row 1 */
    float m10;  /* offset 0x10, evidence: Set3x3Part param_1[4], TransformDir param_1[4] */
    float m11;  /* offset 0x14, evidence: Set3x3Part param_1[5], TransformDir param_1[5] */
    float m12;  /* offset 0x18, evidence: Set3x3Part param_1[6], TransformDir param_1[6] */
    float m13;  /* offset 0x1C, evidence: Set3x3Part skips index 7 (w-column); TransformDir param_1[7] */
    /* Row 2 */
    float m20;  /* offset 0x20, evidence: Set3x3Part param_1[8], TransformDir param_1[8] */
    float m21;  /* offset 0x24, evidence: Set3x3Part param_1[9] */
    float m22;  /* offset 0x28, evidence: Set3x3Part param_1[10] */
    float m23;  /* offset 0x2C, evidence: implied by row stride; not directly accessed in analyzed methods */
} math_float3x4;

static_assert(offsetof(math_float3x4, m00) == 0x00, "math_float3x4.m00 offset");
static_assert(offsetof(math_float3x4, m01) == 0x04, "math_float3x4.m01 offset");
static_assert(offsetof(math_float3x4, m02) == 0x08, "math_float3x4.m02 offset");
static_assert(offsetof(math_float3x4, m03) == 0x0C, "math_float3x4.m03 offset");
static_assert(offsetof(math_float3x4, m10) == 0x10, "math_float3x4.m10 offset");
static_assert(offsetof(math_float3x4, m11) == 0x14, "math_float3x4.m11 offset");
static_assert(offsetof(math_float3x4, m12) == 0x18, "math_float3x4.m12 offset");
static_assert(offsetof(math_float3x4, m13) == 0x1C, "math_float3x4.m13 offset");
static_assert(offsetof(math_float3x4, m20) == 0x20, "math_float3x4.m20 offset");
static_assert(offsetof(math_float3x4, m21) == 0x24, "math_float3x4.m21 offset");
static_assert(offsetof(math_float3x4, m22) == 0x28, "math_float3x4.m22 offset");
static_assert(offsetof(math_float3x4, m23) == 0x2C, "math_float3x4.m23 offset");

#endif /* CMN23_H */