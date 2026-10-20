#ifndef CMN39_H
#define CMN39_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Nucc::Vector2 -- INFERRED from s4 (NSUNS4_release.exe 1.09) static analysis.
 *
 * Size proven at 8 bytes by:
 * - Nucc::Vector2::Set(undefined4 *p, undefined4 a, undefined4 b): writes p[0]=a, p[1]=b
 *   (RVA 0xA2A280, build s4) -- exactly 2 uint32/float elements, stride 4, total 8 bytes
 * - Nucc::Vector2::one() initializes static via math__float2__float2(&DAT, 0x3f800000, 0x3f800000);
 *   guard at DAT+8 confirms 8-byte payload (RVA 0xA2A2D0)
 * - Nucc::Vector2::zero() same layout at separate DAT (RVA 0xA2A330)
 * - operator+, operator-, operator*, operator+= all delegate to FUN_1401c0e* helpers
 *   operating on undefined8 (8-byte value passed by value or pointer)
 * - Normalize delegates to FUN_140887e70 on the 8-byte param
 * - s3 reconstruction (cmn39.h) confirms identical layout; carried forward via BSim
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