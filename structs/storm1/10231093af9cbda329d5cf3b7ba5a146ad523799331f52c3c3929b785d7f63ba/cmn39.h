#ifndef CMN39_H
#define CMN39_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Nucc::Vector2 -- INFERRED from s1 (NSUNS1.exe) static analysis.
 *
 * Size proven at 8 bytes by:
 * - _Cbuild(undefined4 *p, undefined4 a, undefined4 b): writes p[0]=a, p[1]=b
 *   (the decompiler cache symbolize, RVA 0x147780, build s1)
 * - Nucc::Vector2::Set(undefined4 *p, undefined4 a, undefined4 b): same pattern
 *   (RVA 0x4AC440)
 * - Nucc::Vector2::one() initializes static at DAT_140884f70 via
 *   _Cbuild(&DAT, 0x3f800000, 0x3f800000); guard at DAT+8 confirms 8-byte payload
 *   (RVA 0x4AC450)
 * - Nucc::Vector2::zero() same layout at DAT_140884f60 (RVA 0x4AC4B0)
 * - Copy ctor at 0x4AC2B0 copies single undefined8 (*param_1 = *param_2)
 * - Trilogy cross-map confirms Nucc::Vector2::Set -> _ZN4Nucc7Vector2C1Ef
 *   (bsim-direct, score 1.0)
 *
 * No vtable: all methods are non-virtual; operators delegate to CRI/math helpers.
 */
typedef struct __attribute__((packed)) Nucc_Vector2 {
    float x; /* offset 0x00, size 4 */
    float y; /* offset 0x04, size 4 */
} Nucc_Vector2;

static_assert(sizeof(Nucc_Vector2) == 8, "Nucc::Vector2 must be 8 bytes");
static_assert(offsetof(Nucc_Vector2, x) == 0x00, "Nucc::Vector2.x at 0x00");
static_assert(offsetof(Nucc_Vector2, y) == 0x04, "Nucc::Vector2.y at 0x04");

#endif /* CMN39_H */