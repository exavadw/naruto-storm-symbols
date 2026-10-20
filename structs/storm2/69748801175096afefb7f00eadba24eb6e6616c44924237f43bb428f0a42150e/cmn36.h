/* cmn36 s2: Nucc::Matrix33_MathGeo struct layout
 * Build: s2 (NSUNS2.exe, sha 697488011750)
 * All layouts INFERRED from static analysis, not CONFIRMED at runtime.
 * Size proven from copy ctor (RVA 0x59D360) copying 4×8 + 1×4 = 36 bytes,
 * ToQuat (RVA 0x59D540) reading param_1[0..8] as uint32 indices (9 floats),
 * and RotateZ (RVA 0x59D490) writing 4×8 + 1×4 = 36 bytes to output.
 */

#ifndef CMN36_S2_H
#define CMN36_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Nucc::Matrix33_MathGeo
 * Plain 3x3 matrix stored as 9 floats in row-major order.
 * No vtable. Delegates to math::float3x3 thunks for arithmetic.
 * Size: 0x24 (36 bytes), proven by copy ctor (0x59D360), ToQuat (0x59D540),
 * and RotateZ (0x59D490) access patterns.
 */
typedef struct __attribute__((packed)) Nucc_Matrix33_MathGeo {
    float m[9]; /* row-major: m[0..2] = row0, m[3..5] = row1, m[6..8] = row2 */
} Nucc_Matrix33_MathGeo;

static_assert(sizeof(Nucc_Matrix33_MathGeo) == 0x24,
              "Nucc_Matrix33_MathGeo size must be 0x24");
static_assert(offsetof(Nucc_Matrix33_MathGeo, m) == 0x00,
              "Nucc_Matrix33_MathGeo::m offset");

#endif /* CMN36_S2_H */