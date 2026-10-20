#ifndef CMN35_S3_H
#define CMN35_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* cmn35 group (NARUTO STORM 3 Full Burst HD / s3 / NSUNS3.exe 64-bit)
 * INFERRED layouts from static analysis of s3 decompiled code.
 * All structs packed with explicit padding. Field names from s3 method
 * names and decompiled access patterns only (own-game rule).
 * Sizes proven from game code where possible; otherwise noted.
 */

/* =========================================================================
 * Nucc::MathGeoSphere — bounding sphere (center.xyz + radius)
 * Size: 0x10 (proven: TranslateAbs writes 8 bytes at +0x0 as uint64,
 *   TranslateAbsZ writes uint32 at +0x8, Radius/ExpandRadius access +0xC;
 *   ctor at 0x6B2FB0 calls math::float3::float3 for center)
 * No vtable — pure value type.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoSphere {
    uint8_t center_x[4];      /* 0x00 f32 — written by ctor 0x6B2FB0 via math::float3::float3 */
    uint8_t center_y[4];      /* 0x04 f32 — TranslateAbs copies 8 bytes covering +0x0..+0x7 */
    uint8_t center_z[4];      /* 0x08 f32 — TranslateAbsZ writes *(uint32*)(param_1+8) */
    uint8_t radius[4];        /* 0x0C f32 — Radius() returns *(uint32*)(param_1+0xC) */
} Nucc_MathGeoSphere;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoSphere, center_x) == 0x00, "MathGeoSphere.center_x");
static_assert(offsetof(Nucc_MathGeoSphere, center_y) == 0x04, "MathGeoSphere.center_y");
static_assert(offsetof(Nucc_MathGeoSphere, center_z) == 0x08, "MathGeoSphere.center_z");
static_assert(offsetof(Nucc_MathGeoSphere, radius)   == 0x0C, "MathGeoSphere.radius");
static_assert(sizeof(Nucc_MathGeoSphere) == 0x10, "MathGeoSphere size");

/* =========================================================================
 * Nucc::MathGeoAABB — axis-aligned bounding box (min.xyz + max.xyz)
 * Size: 0x18 (proven: ctor at 0x6C2540 writes through +0x14 i.e. 6 floats;
 *   CenterPoint/MaxPoint/MinPoint pass (this+0xC, this) to btDbvtAabbMm::FromMM;
 *   nuccBoundingBox::Set copies 3 uint64s = 0x18 from local_58[80] stack alloc)
 * No vtable — pure value type.
 * Layout: min.xyz at +0x0, max.xyz at +0xC (from ctor param ordering).
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoAABB {
    uint8_t min_x[4];         /* 0x00 f32 — set by ctor from param_3 */
    uint8_t min_y[4];         /* 0x04 f32 */
    uint8_t min_z[4];         /* 0x08 f32 — *(uint32*)(param_1+1) = *(uint32*)(param_3+1) */
    uint8_t max_x[4];         /* 0x0C f32 — set by ctor from param_2 */
    uint8_t max_y[4];         /* 0x10 f32 */
    uint8_t max_z[4];         /* 0x14 f32 — *(uint32*)(param_1+0x14) = *(uint32*)(param_2+1) */
} Nucc_MathGeoAABB;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoAABB, min_x) == 0x00, "MathGeoAABB.min_x");
static_assert(offsetof(Nucc_MathGeoAABB, min_y) == 0x04, "MathGeoAABB.min_y");
static_assert(offsetof(Nucc_MathGeoAABB, min_z) == 0x08, "MathGeoAABB.min_z");
static_assert(offsetof(Nucc_MathGeoAABB, max_x) == 0x0C, "MathGeoAABB.max_x");
static_assert(offsetof(Nucc_MathGeoAABB, max_y) == 0x10, "MathGeoAABB.max_y");
static_assert(offsetof(Nucc_MathGeoAABB, max_z) == 0x14, "MathGeoAABB.max_z");
static_assert(sizeof(Nucc_MathGeoAABB) == 0x18, "MathGeoAABB size");

/* =========================================================================
 * Nucc::MathGeoPolygon — dynamic vertex array (3 pointers, element=0xC)
 * Size: 0x18 (proven: AddVertex accesses param_1[0..2] as 3 uint64 pointers;
 *   RemoveAllVertex sets param_1[1]=param_1[0]; element stride 0xC = 3 floats
 *   per vertex; no ctor found in s3 — initialized externally or zeroed)
 * No vtable — plain struct with pointer members.
 * Fields: base (allocated buffer start), end (next write position),
 *   capacity (buffer end / realloc trigger).
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoPolygon {
    uint8_t base[8];          /* 0x00 ptr — allocated vertex buffer start; AddVertex reads *param_1 */
    uint8_t end[8];           /* 0x08 ptr — next write position; param_1[1], incremented by 0xC */
    uint8_t capacity[8];      /* 0x10 ptr — buffer end; param_1[2], triggers FUN_1401772a0 realloc */
} Nucc_MathGeoPolygon;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoPolygon, base)     == 0x00, "MathGeoPolygon.base");
static_assert(offsetof(Nucc_MathGeoPolygon, end)      == 0x08, "MathGeoPolygon.end");
static_assert(offsetof(Nucc_MathGeoPolygon, capacity) == 0x10, "MathGeoPolygon.capacity");
static_assert(sizeof(Nucc_MathGeoPolygon) == 0x18, "MathGeoPolygon size");

#endif /* CMN35_S3_H */
/* verified: gcc -fsyntax-only -x c -std=c11 passes */
