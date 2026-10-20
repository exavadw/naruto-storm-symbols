#ifndef CMN39_H
#define CMN39_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Nucc::Vector2 -- INFERRED from s3 (NSUNS3.exe) static analysis.
 *
 * Size proven at 8 bytes by:
 * - Nucc::Vector2::Set(undefined4 *p, undefined4 a, undefined4 b): writes p[0]=a, p[1]=b
 *   (the decompiler cache symbolize, RVA 0x6A94A0, build s3)
 * - Nucc::Vector2::At(param_1, idx): returns param_1 + idx*4, bounds-checks idx < 2
 *   (RVA 0x176E60) -- confirms exactly 2 float elements, stride 4, total 8 bytes
 * - Nucc::Vector2::one() initializes static via _Cbuild(&DAT, 0x3f800000, 0x3f800000);
 *   guard at DAT+8 confirms 8-byte payload (RVA 0x6A94B0)
 * - Nucc::Vector2::zero() same layout at separate DAT (RVA 0x6A9510)
 * - operator+, operator+=, IsZero, Normalize all delegate to math::float2:: on 8-byte value
 * - Trilogy cross-map confirms Nucc::Vector2::Set -> ns3 equivalent (bsim-direct)
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