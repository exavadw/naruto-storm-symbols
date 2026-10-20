/* cmn37.h — Nucc::Matrix44_MathGeo struct layout for NSUNS3.exe (s3)
 * INFERRED from static decompilation of s3 build (sha 55b726e94dad).
 * NOT CONFIRMED at runtime. All offsets derived from PC x64 decompile.
 *
 * This is a MathGeo float4x4 wrapper. Internal storage is column-major
 * (indices 0-3 = col0, 4-7 = col1, 8-11 = col2, 12-15 = col3).
 * Methods transpose to/from MathGeo row-major on entry/exit via
 * FUN_1401746c0 / FUN_140174700 helpers.
 *
 * Size proven at 0x40 (64 bytes) from default ctor at RVA 0x685600
 * accessing param_1[0xf] (offset 0x3C, last uint32) and SetIdentity
 * at RVA 0x686950 accessing offset 0x3C.
 */

#ifndef CMN37_H
#define CMN37_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Nucc::Matrix44_MathGeo — 4x4 matrix (column-major float storage)
 * Size: 0x40 (64 bytes), proven by default ctor at 0x685600 and
 * SetIdentity at 0x686950 accessing param_1[0xf] / offset 0x3C.
 * Vtable: none (no virtual methods observed)
 * Methods: 61 symbols in s3 build
 */
typedef struct __attribute__((packed)) Nucc_Matrix44_MathGeo {
    /* Column 0 */
    float m0;     /* +0x00 */
    float m1;     /* +0x04 */
    float m2;     /* +0x08 */
    float m3;     /* +0x0C */
    /* Column 1 */
    float m4;     /* +0x10 */
    float m5;     /* +0x14 */
    float m6;     /* +0x18 */
    float m7;     /* +0x1C */
    /* Column 2 */
    float m8;     /* +0x20 */
    float m9;     /* +0x24 */
    float m10;    /* +0x28 */
    float m11;    /* +0x2C */
    /* Column 3 (translation part when affine) */
    float m12;    /* +0x30 */
    float m13;    /* +0x34 */
    float m14;    /* +0x38 */
    float m15;    /* +0x3C */
} Nucc_Matrix44_MathGeo;

/* Layout assertions — every field verified against decompiled offsets */
static_assert(offsetof(Nucc_Matrix44_MathGeo, m0)  == 0x00, "m0 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m1)  == 0x04, "m1 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m2)  == 0x08, "m2 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m3)  == 0x0C, "m3 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m4)  == 0x10, "m4 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m5)  == 0x14, "m5 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m6)  == 0x18, "m6 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m7)  == 0x1C, "m7 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m8)  == 0x20, "m8 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m9)  == 0x24, "m9 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m10) == 0x28, "m10 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m11) == 0x2C, "m11 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m12) == 0x30, "m12 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m13) == 0x34, "m13 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m14) == 0x38, "m14 offset");
static_assert(offsetof(Nucc_Matrix44_MathGeo, m15) == 0x3C, "m15 offset");
static_assert(sizeof(Nucc_Matrix44_MathGeo) == 0x40, "Nucc_Matrix44_MathGeo size");

#endif /* CMN37_H */