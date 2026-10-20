/* cmn36 s4: Nucc::Matrix33_MathGeo struct layout
 * Build: s4 (NSUNS4_release.exe, sha 147e52a3e0d7)
 * All layouts INFERRED from static analysis, not CONFIRMED at runtime.
 * Size proven from copy ctor (RVA 0xA2D740) copying 4×8 + 1×4 = 36 bytes,
 * ToQuat (RVA 0x8712E0) reading param_1[0..8] as uint32 indices (9 floats),
 * matching s3 layout exactly.
 */
#ifndef CMN36_S4_H
#define CMN36_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Nucc::Matrix33_MathGeo
 * Plain 3x3 matrix stored as 9 floats in row-major order.
 * No vtable. Delegates to math::float3x3 thunks for arithmetic.
 * Size: 0x24 (36 bytes), proven by copy ctor (0xA2D740) and ToQuat (0x8712E0).
 */
typedef struct __attribute__((packed)) Nucc_Matrix33_MathGeo {
    /* 0x00 */ float m00; /* row0 col0 */
    /* 0x04 */ float m01; /* row0 col1 */
    /* 0x08 */ float m02; /* row0 col2 */
    /* 0x0C */ float m10; /* row1 col0 */
    /* 0x10 */ float m11; /* row1 col1 */
    /* 0x14 */ float m12; /* row1 col2 */
    /* 0x18 */ float m20; /* row2 col0 */
    /* 0x1C */ float m21; /* row2 col1 */
    /* 0x20 */ float m22; /* row2 col2 */
} Nucc_Matrix33_MathGeo;

static_assert(sizeof(Nucc_Matrix33_MathGeo) == 0x24,
              "Nucc_Matrix33_MathGeo size must be 0x24");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m00) == 0x00,
              "Nucc_Matrix33_MathGeo::m00 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m01) == 0x04,
              "Nucc_Matrix33_MathGeo::m01 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m02) == 0x08,
              "Nucc_Matrix33_MathGeo::m02 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m10) == 0x0C,
              "Nucc_Matrix33_MathGeo::m10 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m11) == 0x10,
              "Nucc_Matrix33_MathGeo::m11 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m12) == 0x14,
              "Nucc_Matrix33_MathGeo::m12 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m20) == 0x18,
              "Nucc_Matrix33_MathGeo::m20 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m21) == 0x1C,
              "Nucc_Matrix33_MathGeo::m21 offset");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m22) == 0x20,
              "Nucc_Matrix33_MathGeo::m22 offset");

#endif /* CMN36_S4_H */