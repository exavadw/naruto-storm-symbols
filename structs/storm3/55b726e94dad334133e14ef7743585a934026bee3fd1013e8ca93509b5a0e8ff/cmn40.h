/*
 * cmn40.h - Nucc::Vector3 struct reconstruction for NSUNS3.exe (build s3)
 * INFERRED from static decompilation only; not runtime-confirmed.
 * All offsets/sizes derived from s3 x64 PC build (image base 0x140000000).
 */
#ifndef CMN40_S3_H
#define CMN40_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Nucc::Vector3
 * Size: 0xC (12 bytes) — proven by Set (0x684910) writing param_1[0..2] as undefined4 (float),
 * operator+ (0x684530) accessing indices 0,1,2 as float, Dot (0x172AC0) computing x*x+y*y+z*z,
 * operator[] (0x1726A0) returning param_1 + index*4 with bounds check < 3.
 * No vtable (pure value type, no virtual methods observed in any of 53 cached methods).
 * Fields named from own-game evidence: Set/operator[]/MaxElem confirm x,y,z ordering.
 * Ctor at 0x6843A0 delegates to math::float3::float3 confirming 3-float layout.
 */
typedef struct __attribute__((packed)) Nucc_Vector3 {
    float x; /* offset 0x0, size 4, rw */
    float y; /* offset 0x4, size 4, rw */
    float z; /* offset 0x8, size 4, rw */
} Nucc_Vector3;

static_assert(sizeof(Nucc_Vector3) == 0xC, "Nucc_Vector3 size must be 12 bytes");
static_assert(offsetof(Nucc_Vector3, x) == 0x0, "Nucc_Vector3.x offset");
static_assert(offsetof(Nucc_Vector3, y) == 0x4, "Nucc_Vector3.y offset");
static_assert(offsetof(Nucc_Vector3, z) == 0x8, "Nucc_Vector3.z offset");

#endif /* CMN40_S3_H */