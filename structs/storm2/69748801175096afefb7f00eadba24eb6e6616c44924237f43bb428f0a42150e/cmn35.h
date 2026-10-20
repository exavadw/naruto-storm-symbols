#ifndef CMN35_S2_H
#define CMN35_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* cmn35 group (NARUTO STORM 2 / s2) — INFERRED layouts from static analysis.
 * All structs are packed with explicit padding. Field names derived from
 * s2 method names and decompiled access patterns only (own-game rule).
 * Sizes proven from game code where possible; otherwise noted as >= N.
 */

/* =========================================================================
 * Nucc::MathGeoSphere — bounding sphere (center + radius)
 * Size: 0x10 (proven: math::Sphere::Sphere writes param_1[0..3] = 4 floats;
 *   TranslateAbs copies 12 bytes center; Radius/ExpandRadius access +0xC)
 * No vtable — pure value type.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoSphere {
    uint8_t center_x[4];      /* 0x00 f32 — written by ctor 0x587D30 via math::float3::float3 */
    uint8_t center_y[4];      /* 0x04 f32 */
    uint8_t center_z[4];      /* 0x08 f32 — TranslateAbsZ writes here */
    uint8_t radius[4];        /* 0x0C f32 — read by Radius(), written by ExpandRadius() */
} Nucc_MathGeoSphere;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoSphere, center_x) == 0x00, "MathGeoSphere.center_x");
static_assert(offsetof(Nucc_MathGeoSphere, center_y) == 0x04, "MathGeoSphere.center_y");
static_assert(offsetof(Nucc_MathGeoSphere, center_z) == 0x08, "MathGeoSphere.center_z");
static_assert(offsetof(Nucc_MathGeoSphere, radius)   == 0x0C, "MathGeoSphere.radius");
static_assert(sizeof(Nucc_MathGeoSphere) == 0x10, "MathGeoSphere size");

/* =========================================================================
 * Nucc::MathGeoAABB — axis-aligned bounding box (min + max vectors)
 * Size: 0x18 (proven: ctor at 0x5C5EB0 writes through +0x14, i.e. 6 floats)
 * No vtable — pure value type.
 * Layout: min.xyz at +0x0, max.xyz at +0xC (from ctor param ordering).
 * CenterPoint/MaxPoint/MinPoint all pass (this+0xC, this) to btDbvtAabbMm::FromMM.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoAABB {
    uint8_t min_x[4];         /* 0x00 f32 — set by ctor from param_3 */
    uint8_t min_y[4];         /* 0x04 f32 */
    uint8_t min_z[4];         /* 0x08 f32 */
    uint8_t max_x[4];         /* 0x0C f32 — set by ctor from param_2 */
    uint8_t max_y[4];         /* 0x10 f32 */
    uint8_t max_z[4];         /* 0x14 f32 */
} Nucc_MathGeoAABB;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoAABB, min_x) == 0x00, "MathGeoAABB.min_x");
static_assert(offsetof(Nucc_MathGeoAABB, min_y) == 0x04, "MathGeoAABB.min_y");
static_assert(offsetof(Nucc_MathGeoAABB, min_z) == 0x08, "MathGeoAABB.min_z");
static_assert(offsetof(Nucc_MathGeoAABB, max_x) == 0x0C, "MathGeoAABB.max_x");
static_assert(offsetof(Nucc_MathGeoAABB, max_y) == 0x10, "MathGeoAABB.max_y");
static_assert(offsetof(Nucc_MathGeoAABB, max_z) == 0x14, "MathGeoAABB.max_z");
static_assert(sizeof(Nucc_MathGeoAABB) == 0x18, "MathGeoAABB size");

#endif /* CMN35_S2_H */
/* =========================================================================
 * Nucc: no instance state
 * All 13 methods in the Nucc:: namespace (free functions / operators) are
 * static utility functions with no this pointer. Evidence from decompiled
 * signatures (s2 build):
 *   0x58F440  Nucc::CalcHash(uint,longlong)           — pure hash, params only
 *   0x58F400  Nucc::CalcHash16FromStr(byte*)          — string hash, param only
 *   0x58F4C0  Nucc::CalcHashFromStr(longlong)         — string hash, param only
 *   0x66C230  Nucc::GetSystemDialog(void)             — void args, returns global
 *   0x82F60   Nucc::GetThreadId(void)                 — void args, TLS read
 *   0x58DE30  Nucc::InitMatrixStack(void)             — void args, global init
 *   0x58F4E0  Nucc::InvalidHash(void)                 — void args, returns constant
 *   0x58E380  Nucc::SystemCallback(void)              — void args, callback stub
 *   0x594B40  Nucc::operator*(u8,u8,u8)               — 3-arg operator, no this
 *   0x594C00  Nucc::operator*(u8,u8,u8)               — 3-arg operator, no this
 *   0x594C50  Nucc::operator*(u8,u8,u8)               — 3-arg operator, no this
 *   0x580CD0  Nucc::Cross(u8*,u8)                     — output ptr + value, no this
 *   0x626150  Nucc::operator*(longlong,float)         — scalar multiply, no this
 * No struct reconstruction applies. INFERRED from static analysis.
 * ========================================================================= */
