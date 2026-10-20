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