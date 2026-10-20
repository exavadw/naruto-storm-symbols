/* cmn35 group — s4 (NARUTO STORM 4 PC 1.09, NSUNS4_release.exe)
 * All layouts INFERRED from static analysis of decompiled code.
 * No runtime confirmation. Sizes proven from access patterns in game code.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Nucc::MathGeoSphere — bounding sphere (center + radius)
 * Size 0x10 proven: TranslateAbs copies 8 bytes at +0x0, TranslateAbsZ writes
 * uint32 at +0x8, Radius/ExpandRadius access uint32 at +0xC. All methods fit
 * exactly 16 bytes. Matches s3 layout.
 */
typedef struct __attribute__((packed)) Nucc_MathGeoSphere {
    float center_x;   /* 0x00 */
    float center_y;   /* 0x04 */
    float center_z;   /* 0x08 */
    float radius;     /* 0x0C */
} Nucc_MathGeoSphere;

static_assert(sizeof(Nucc_MathGeoSphere) == 0x10, "MathGeoSphere size");
static_assert(offsetof(Nucc_MathGeoSphere, center_x) == 0x00, "MathGeoSphere.center_x");
static_assert(offsetof(Nucc_MathGeoSphere, center_y) == 0x04, "MathGeoSphere.center_y");
static_assert(offsetof(Nucc_MathGeoSphere, center_z) == 0x08, "MathGeoSphere.center_z");
static_assert(offsetof(Nucc_MathGeoSphere, radius) == 0x0C, "MathGeoSphere.radius");

/* Nucc::MathGeoAABB — axis-aligned bounding box (min + max)
 * Size 0x18 proven: ctor writes through +0x14 (6 floats = 24 bytes).
 * i_ComputeExtents passes (this+0xC, this) to helper, consistent with
 * max at +0xC and min at +0x0. Matches s3 layout.
 */
typedef struct __attribute__((packed)) Nucc_MathGeoAABB {
    float min_x;      /* 0x00 */
    float min_y;      /* 0x04 */
    float min_z;      /* 0x08 */
    float max_x;      /* 0x0C */
    float max_y;      /* 0x10 */
    float max_z;      /* 0x14 */
} Nucc_MathGeoAABB;

static_assert(sizeof(Nucc_MathGeoAABB) == 0x18, "MathGeoAABB size");
static_assert(offsetof(Nucc_MathGeoAABB, min_x) == 0x00, "MathGeoAABB.min_x");
static_assert(offsetof(Nucc_MathGeoAABB, min_y) == 0x04, "MathGeoAABB.min_y");
static_assert(offsetof(Nucc_MathGeoAABB, min_z) == 0x08, "MathGeoAABB.min_z");
static_assert(offsetof(Nucc_MathGeoAABB, max_x) == 0x0C, "MathGeoAABB.max_x");
static_assert(offsetof(Nucc_MathGeoAABB, max_y) == 0x10, "MathGeoAABB.max_y");
static_assert(offsetof(Nucc_MathGeoAABB, max_z) == 0x14, "MathGeoAABB.max_z");

/* Nucc: no instance state.
 * The bare Nucc:: namespace contains only free/static utility functions with
 * no this pointer or shared instance data. All 7 symbols in s4 are void/param
 * functions operating on globals or pure inputs:
 *   0xA01E30  Nucc::CalcHash(longlong, int) -> uint
 *   0xA01DF0  Nucc::CalcHash16FromStr(byte*) -> uint
 *   0x4485B0  Nucc::CalcHashFromStr(longlong) -> undefined8
 *   0xA01EB0  Nucc::CalcHashFromStr(longlong) -> undefined8
 *   0xB0A710  Nucc::GetSystemDialog(void) -> undefined8
 *   0xA19640  Nucc::InitMatrixStack(void) -> void
 *   0xA01ED0  Nucc::InvalidHash(void) -> undefined*
 * INFERRED from decompiled signatures (no param_1 this-pointer pattern).
 */

/* Nucc::Effect: no instance state.
 * All 4 methods are static singleton accessors returning global manager pointers.
 * Three take void (no this); one takes a longlong* output parameter:
 *   0xA08280  Nucc::Effect::GetManager(void) -> undefined*
 *   0x37CEA4  Nucc::Effect::GetManager(longlong) -> void  [low confidence]
 *   0xA069F0  Nucc::Effect::GetParticleRootManager(void) -> undefined*
 *   0xA06E40  Nucc::Effect::GetParticleRootManager(longlong*) -> void
 * state_surface found only vtable-dispatch reads at +0x80/+0x5C0 (not data fields).
 * INFERRED from decompiled signatures and state_surface analysis.
 */