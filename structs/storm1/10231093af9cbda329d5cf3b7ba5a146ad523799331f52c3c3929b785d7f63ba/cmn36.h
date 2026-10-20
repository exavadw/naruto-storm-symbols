/* cmn36 s1: Nucc::Matrix33_MathGeo struct layout
 * Build: s1 (NSUNS1.exe, sha 10231093af9c)
 * All layouts INFERRED from static analysis, not CONFIRMED at runtime.
 * Size proven from math::float3x3::operator* accessing float indices 0..8
 * and copy pattern in copy ctor / operator* / RotateY / RotateZ
 * (4 x 8 + 1 x 4 = 36 bytes).
 */

#ifndef CMN36_S1_H
#define CMN36_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Nucc::Matrix33_MathGeo
 * Plain 3x3 matrix stored as 9 floats in row-major order.
 * No vtable. Delegates to math::float3x3 thunks for arithmetic.
 * Size: 0x24 (36 bytes), proven by float[9] access in math::float3x3::operator*
 * (RVA 0x145540) and 36-byte copy in copy ctor (RVA 0x4B79F0).
 */
typedef struct __attribute__((packed)) Nucc_Matrix33_MathGeo {
    float m[9]; /* row-major: m[0..2] = row0, m[3..5] = row1, m[6..8] = row2 */
} Nucc_Matrix33_MathGeo;

static_assert(sizeof(Nucc_Matrix33_MathGeo) == 0x24,
              "Nucc_Matrix33_MathGeo size must be 0x24");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m) == 0x00,
              "Nucc_Matrix33_MathGeo::m offset");

#endif /* CMN36_S1_H */