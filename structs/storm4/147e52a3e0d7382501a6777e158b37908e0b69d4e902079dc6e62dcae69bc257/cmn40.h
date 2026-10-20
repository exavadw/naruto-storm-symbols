/*
 * cmn40.h - Nucc::Vector3 struct reconstruction for NSUNS4_release.exe (build s4)
 * INFERRED from static decompilation only; not runtime-confirmed.
 * All offsets/sizes derived from s4 x64 PC build (image base 0x140000000).
 */
#ifndef CMN40_S4_H
#define CMN40_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Nucc::Vector3
 * Size: 0xC (12 bytes) — proven by Set (0xA04BC0) writing param_1[0..2] as undefined4 (float),
 * operator[] (0x1BD6D0) returning param_1 + index*4 with bounds check < 3,
 * At (0x1BD6B0) reading *(param_1 + index*4) with bounds check < 3,
 * Dot (0x1BDBF0) computing param_1[0]*param_2[0] + param_1[1]*param_2[1] + param_1[2]*param_2[2],
 * MaxElem (0x1BD8B0) comparing param_1[0], param_1[1], param_1[2].
 * No vtable (pure value type, no virtual methods observed in any of 58 cached methods).
 * Fields named from own-game evidence: Set/operator[]/At/Dot/MaxElem confirm x,y,z ordering.
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

#endif /* CMN40_S4_H */