/* cmn22.h — struct group cmn22 for NARUTO STORM 1 PC (NSUNS1.exe, build s1)
 * All layouts INFERRED from static decompilation. Not CONFIRMED.
 * Offsets derived from s1 x64 decompile only. Names from s1 symbols/strings.
 */
#ifndef CMN22_S1_H
#define CMN22_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * math::float2
 * Size: 0x8 (proven by ctor: param_1[0]=x, param_1[1]=y as undefined4*)
 * Note: math::float2::operator+ at RVA 0x4D00A0 is mislabeled (string func).
 *       Real float2 ops use SSE; state_surface found 0 pointer-based fields.
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
 * Evidence: math::float3::float3 @ 0x144590, math::float3::operator*= @ 0x144C60
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
 * Evidence: ScaleRow @ 0x481AF0, Inverse @ 0x145350, ctor @ 0x148850
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float3x3 {
    float m[3][3]; /* 0x00 - 0x20, row-major: m[row][col] */
} math_float3x3;

static_assert(offsetof(math_float3x3, m) == 0x00, "math_float3x3.m");
/* Individual element offsets verified by Inverse/ScaleRow:
 *   m[0][0]=0x00, m[0][1]=0x04, m[0][2]=0x08
 *   m[1][0]=0x0C, m[1][1]=0x10, m[1][2]=0x14
 *   m[2][0]=0x18, m[2][1]=0x1C, m[2][2]=0x20
 */

/* ========================================================================
 * InplaceSolverIslandCallback (Bullet Physics)
 * Size: unknown, >= 0x98 (last proven field at 0x90, size 1 → end >= 0x91;
 *        aligned to 8 → >= 0x98)
 * Vtable at offset 0x00: btSimulationIslandManager::IslandCallback::vftable
 * Evidence: dtor @ 0x5D3720, scalar_deleting_destructor @ 0x5D39B0
 *
 * Field layout from dtor cleanup pattern (3 identical blocks):
 *   Block 1: ptr@0x3C, flag@0x70(byte), capacity@0x68(qword)
 *   Block 2: ptr@0x5C, flag@0x70(byte reused? no — see below), ...
 *   Block 3: ptr@0x7C, flag@0x90(byte), capacity@0x88(qword)
 *
 * Re-analysis of dtor with undefined8* indexing:
 *   param_1[9]  = offset 0x48 → ptr (but state_surface says 0x3C?)
 *   Actually: undefined8* means param_1[N] = base + N*8
 *   param_1[0x11] = base + 0x88 (capacity qword)
 *   param_1 + 0x12 = base + 0x90 (flag byte)
 *   param_1[0xd]  = base + 0x68 (capacity qword)
 *   param_1 + 0xe = base + 0x70 (flag byte)
 *   param_1[9]    = base + 0x48 (capacity qword)
 *   param_1 + 10  = base + 0x50 (flag byte)
 *   *(longlong)(param_1 + 0x3c) = base + 0x3C (ptr, zeroed)
 *   *(longlong)(param_1 + 0x5c) = base + 0x5C (ptr, zeroed)
 *   *(longlong)(param_1 + 0x7c) = base + 0x7C (ptr, zeroed)
 * ======================================================================== */
typedef struct __attribute__((packed)) InplaceSolverIslandCallback {
    void *vtable;          /* 0x00 - btSimulationIslandManager::IslandCallback::vftable */
    uint8_t _pad_08[0x34]; /* 0x08 - 0x3B: unknown base class / padding */
    void *array_ptr_0;     /* 0x3C - freed ptr (block 0 data) */
    uint8_t _pad_44[0x04]; /* 0x44 */
    void *array_ptr_1;     /* 0x48 - capacity/ptr (state_surface 0x48 via param_1[9]) */
    uint8_t owned_flag_0;  /* 0x50 - if set, calls btAlignedFreeInternal */
    uint8_t _pad_51[0x0B]; /* 0x51 */
    void *array_ptr_2;     /* 0x5C - freed ptr (block 1 data) */
    uint8_t _pad_64[0x04]; /* 0x64 */
    uint64_t capacity_0;   /* 0x68 - array capacity (param_1[0xd]) */
    uint8_t owned_flag_1;  /* 0x70 - if set, calls btAlignedFreeInternal */
    uint8_t _pad_71[0x0B]; /* 0x71 */
    void *array_ptr_3;     /* 0x7C - freed ptr (block 2 data) */
    uint8_t _pad_84[0x04]; /* 0x84 */
    uint64_t capacity_1;   /* 0x88 - array capacity (param_1[0x11]) */
    uint8_t owned_flag_2;  /* 0x90 - if set, calls btAlignedFreeInternal */
    /* size unknown, >= 0x91; padded to 0x98 */
} InplaceSolverIslandCallback;

static_assert(offsetof(InplaceSolverIslandCallback, vtable) == 0x00, "IPC.vtable");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_0) == 0x3C, "IPC.array_ptr_0");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_1) == 0x48, "IPC.array_ptr_1");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_0) == 0x50, "IPC.owned_flag_0");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_2) == 0x5C, "IPC.array_ptr_2");
static_assert(offsetof(InplaceSolverIslandCallback, capacity_0) == 0x68, "IPC.capacity_0");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_1) == 0x70, "IPC.owned_flag_1");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_3) == 0x7C, "IPC.array_ptr_3");
static_assert(offsetof(InplaceSolverIslandCallback, capacity_1) == 0x88, "IPC.capacity_1");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_2) == 0x90, "IPC.owned_flag_2");

#endif /* CMN22_S1_H */