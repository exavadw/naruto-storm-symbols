/* cmn22.h — struct group cmn22 for NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, build s3)
 * All layouts INFERRED from static decompilation. Not CONFIRMED.
 * Offsets derived from s3 x64 decompile only. Names from s3 symbols/strings.
 */
#ifndef CMN22_S3_H
#define CMN22_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * math::float2
 * Size: 0x8 (proven by operator+=: param_1[0] and param_1[1] as float*)
 * Evidence: math::float2::operator+= @ RVA 0x177020
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float2 {
    float x; /* 0x00 */
    float y; /* 0x04 */
} math_float2;

static_assert(offsetof(math_float2, x) == 0x00, "math_float2.x");
static_assert(offsetof(math_float2, y) == 0x04, "math_float2.y");

/* ========================================================================
 * math::float3
 * Size: 0xC (proven by ctor: 3x undefined4 writes at [0],[1],[2])
 * Evidence: math::float3::float3 @ RVA 0x172620
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float3 {
    float x; /* 0x00 */
    float y; /* 0x04 */
    float z; /* 0x08 */
} math_float3;

static_assert(offsetof(math_float3, x) == 0x00, "math_float3.x");
static_assert(offsetof(math_float3, y) == 0x04, "math_float3.y");
static_assert(offsetof(math_float3, z) == 0x08, "math_float3.z");

/* ========================================================================
 * math::float3x3
 * Size: 0x24 (36 bytes, proven by Inverse reading 9 floats 0x00..0x20)
 * 3x3 matrix stored row-major as 9 floats.
 * Evidence: Inverse @ RVA 0x174E30
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float3x3 {
    float m[3][3]; /* 0x00 - 0x20, row-major: m[row][col] */
} math_float3x3;

static_assert(offsetof(math_float3x3, m) == 0x00, "math_float3x3.m");
/* Individual element offsets verified by Inverse:
 *   m[0][0]=0x00, m[0][1]=0x04, m[0][2]=0x08
 *   m[1][0]=0x0C, m[1][1]=0x10, m[1][2]=0x14
 *   m[2][0]=0x18, m[2][1]=0x1C, m[2][2]=0x20
 */

/* ========================================================================
 * InplaceSolverIslandCallback (Bullet Physics)
 * Size: unknown, >= 0x98 (last proven field at 0x90, size 1 → end >= 0x91;
 *        aligned to 8 → >= 0x98)
 * Vtable at offset 0x00: btSimulationIslandManager::IslandCallback::vftable
 * Evidence: dtor @ RVA 0x7FA200
 *
 * Field layout from dtor cleanup pattern (3 identical blocks):
 *   Block 0: ptr@0x3C, capacity@0x48(param_1[9]), flag@0x50(param_1+10)
 *   Block 1: ptr@0x5C, capacity@0x68(param_1[0xd]), flag@0x70(param_1+0xe)
 *   Block 2: ptr@0x7C, capacity@0x88(param_1[0x11]), flag@0x90(param_1+0x12)
 * ======================================================================== */
typedef struct __attribute__((packed)) InplaceSolverIslandCallback {
    void *vtable;          /* 0x00 - btSimulationIslandManager::IslandCallback::vftable */
    uint8_t _pad_08[0x34]; /* 0x08 - 0x3B: unknown base class / padding */
    void *array_ptr_0;     /* 0x3C - freed ptr (block 0 data) */
    uint8_t _pad_44[0x04]; /* 0x44 */
    uint64_t capacity_0;   /* 0x48 - array capacity (param_1[9]) */
    uint8_t owned_flag_0;  /* 0x50 - if set, calls btAlignedFreeInternal */
    uint8_t _pad_51[0x0B]; /* 0x51 */
    void *array_ptr_1;     /* 0x5C - freed ptr (block 1 data) */
    uint8_t _pad_64[0x04]; /* 0x64 */
    uint64_t capacity_1;   /* 0x68 - array capacity (param_1[0xd]) */
    uint8_t owned_flag_1;  /* 0x70 - if set, calls btAlignedFreeInternal */
    uint8_t _pad_71[0x0B]; /* 0x71 */
    void *array_ptr_2;     /* 0x7C - freed ptr (block 2 data) */
    uint8_t _pad_84[0x04]; /* 0x84 */
    uint64_t capacity_2;   /* 0x88 - array capacity (param_1[0x11]) */
    uint8_t owned_flag_2;  /* 0x90 - if set, calls btAlignedFreeInternal */
    /* size unknown, >= 0x91; padded to 0x98 */
} InplaceSolverIslandCallback;

static_assert(offsetof(InplaceSolverIslandCallback, vtable) == 0x00, "IPC.vtable");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_0) == 0x3C, "IPC.array_ptr_0");
static_assert(offsetof(InplaceSolverIslandCallback, capacity_0) == 0x48, "IPC.capacity_0");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_0) == 0x50, "IPC.owned_flag_0");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_1) == 0x5C, "IPC.array_ptr_1");
static_assert(offsetof(InplaceSolverIslandCallback, capacity_1) == 0x68, "IPC.capacity_1");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_1) == 0x70, "IPC.owned_flag_1");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_2) == 0x7C, "IPC.array_ptr_2");
static_assert(offsetof(InplaceSolverIslandCallback, capacity_2) == 0x88, "IPC.capacity_2");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_2) == 0x90, "IPC.owned_flag_2");

/* ========================================================================
 * math: no instance state
 * The "math" class in this group's coverage list is actually the math
 * namespace containing only free (non-member) operator* overloads.
 * None of these functions have a this pointer or access instance fields;
 * they operate entirely on their explicit parameters.
 * Evidence (all s3 PC RVAs, decompiled signatures confirm no this):
 *   math::operator* @ 0x175A30 - undefined8*(undefined8*,float*,float*)
 *   math::operator* @ 0x175C20 - float*(float*,float*,float*)
 *   math::operator* @ 0x175CE0 - float*(float*,float*,float*)
 *   math::operator* @ 0x6AA9B0 - void(longlong) (matrix multiply helper)
 * No struct, vtable, or allocation site exists for a "math" object.
 * ======================================================================== */

#endif /* CMN22_S3_H */
