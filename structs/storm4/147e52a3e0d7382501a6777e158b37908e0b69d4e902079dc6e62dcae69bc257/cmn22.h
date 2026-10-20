/* cmn22.h — struct group cmn22 for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 * All layouts INFERRED from static decompilation. Not CONFIRMED.
 * Offsets derived from s4 x64 decompile only. Names from s4 symbols/strings.
 */
#ifndef CMN22_S4_H
#define CMN22_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * math::float2
 * Size: 0x8 (proven by operator+=: param_1[0] and param_1[1] as float*)
 * Evidence: math::float2::operator+= @ RVA 0x1C0E90
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float2 {
    float x;                            /* 0x00 */
    float y;                            /* 0x04 */
} math_float2;

static_assert(offsetof(math_float2, x) == 0x00, "math_float2.x");
static_assert(offsetof(math_float2, y) == 0x04, "math_float2.y");

/* ========================================================================
 * math::float3
 * Size: 0xC (proven by ctor: 3x undefined4 writes at [0],[1],[2])
 * Evidence: math::float3::float3 @ RVA 0x1BD650
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float3 {
    float x;                            /* 0x00 */
    float y;                            /* 0x04 */
    float z;                            /* 0x08 */
} math_float3;

static_assert(offsetof(math_float3, x) == 0x00, "math_float3.x");
static_assert(offsetof(math_float3, y) == 0x04, "math_float3.y");
static_assert(offsetof(math_float3, z) == 0x08, "math_float3.z");

/* ========================================================================
 * math::float3x3
 * Size: 0x24 (36 bytes, proven by Inverse reading 9 floats 0x00..0x20)
 * 3x3 matrix stored row-major as 9 floats.
 * Evidence: Inverse @ RVA 0x1BE210, operator= @ RVA 0x1BE1D0
 * ======================================================================== */
typedef struct __attribute__((packed)) math_float3x3 {
    float m[3][3];                      /* 0x00 - 0x20, row-major: m[row][col] */
} math_float3x3;

static_assert(offsetof(math_float3x3, m) == 0x00, "math_float3x3.m");
/* Individual element offsets verified by Inverse:
 * m[0][0]=0x00, m[0][1]=0x04, m[0][2]=0x08
 * m[1][0]=0x0C, m[1][1]=0x10, m[1][2]=0x14
 * m[2][0]=0x18, m[2][1]=0x1C, m[2][2]=0x20
 */

/* ========================================================================
 * InplaceSolverIslandCallback (Bullet Physics)
 * Size: unknown, >= 0x98 (last proven field owned_flag_2 at 0x90, size 1;
 * aligned to 8 -> >= 0x98). No allocator call with size found.
 * Vtable at offset 0x00: btSimulationIslandManager::IslandCallback::vftable
 * Evidence: dtor @ RVA 0xDFE1F0, processConstraints @ RVA 0xE01E80,
 *           processIsland @ RVA 0xE020C0
 *
 * s4 adds base-class fields not present in s3:
 *   ptr@0x08, ptr@0x10, ptr@0x18, int@0x20, ptr@0x28, ptr@0x30
 * Then 3 identical cleanup blocks (from dtor):
 *   Block 0: int_size@0x3C, int_cap@0x40, ptr@0x48, flag@0x50
 *   Block 1: int_size@0x5C, int_cap@0x60, ptr@0x68, flag@0x70
 *   Block 2: int_size@0x7C, int_cap@0x80, ptr@0x88, flag@0x90
 * ======================================================================== */
typedef struct __attribute__((packed)) InplaceSolverIslandCallback {
    void     *vtable;                   /* 0x00 - btSimulationIslandManager::IslandCallback::vftable */
    void     *base_ptr_0;               /* 0x08 - from processIsland */
    void     *base_ptr_1;               /* 0x10 - from processConstraints */
    void     *base_ptr_2;               /* 0x18 - from processIsland */
    int32_t   base_count;               /* 0x20 - from processIsland */
    uint8_t   _pad_24[4];              /* 0x24 */
    void     *base_ptr_3;               /* 0x28 - from processConstraints/processIsland */
    void     *base_ptr_4;               /* 0x30 - from processConstraints/processIsland */
    uint8_t   _pad_38[4];              /* 0x38 */
    int32_t   array_size_0;             /* 0x3C - block 0 element count */
    int32_t   array_cap_0;              /* 0x40 - block 0 capacity */
    uint8_t   _pad_44[4];              /* 0x44 */
    void     *array_ptr_0;              /* 0x48 - block 0 data pointer */
    uint8_t   owned_flag_0;             /* 0x50 - if set, calls btAlignedFreeInternal */
    uint8_t   _pad_51[11];             /* 0x51 - pad to 0x5C */
    int32_t   array_size_1;             /* 0x5C - block 1 element count */
    int32_t   array_cap_1;              /* 0x60 - block 1 capacity */
    uint8_t   _pad_64[4];              /* 0x64 */
    void     *array_ptr_1;              /* 0x68 - block 1 data pointer */
    uint8_t   owned_flag_1;             /* 0x70 - if set, calls btAlignedFreeInternal */
    uint8_t   _pad_71[11];             /* 0x71 - pad to 0x7C */
    int32_t   array_size_2;             /* 0x7C - block 2 element count */
    int32_t   array_cap_2;              /* 0x80 - block 2 capacity */
    uint8_t   _pad_84[4];              /* 0x84 */
    void     *array_ptr_2;              /* 0x88 - block 2 data pointer */
    uint8_t   owned_flag_2;             /* 0x90 - if set, calls btAlignedFreeInternal */
    /* size unknown, >= 0x91; padded to 0x98 */
} InplaceSolverIslandCallback;

static_assert(offsetof(InplaceSolverIslandCallback, vtable)       == 0x00, "IPC.vtable");
static_assert(offsetof(InplaceSolverIslandCallback, base_ptr_0)   == 0x08, "IPC.base_ptr_0");
static_assert(offsetof(InplaceSolverIslandCallback, base_ptr_1)   == 0x10, "IPC.base_ptr_1");
static_assert(offsetof(InplaceSolverIslandCallback, base_ptr_2)   == 0x18, "IPC.base_ptr_2");
static_assert(offsetof(InplaceSolverIslandCallback, base_count)   == 0x20, "IPC.base_count");
static_assert(offsetof(InplaceSolverIslandCallback, base_ptr_3)   == 0x28, "IPC.base_ptr_3");
static_assert(offsetof(InplaceSolverIslandCallback, base_ptr_4)   == 0x30, "IPC.base_ptr_4");
static_assert(offsetof(InplaceSolverIslandCallback, array_size_0) == 0x3C, "IPC.array_size_0");
static_assert(offsetof(InplaceSolverIslandCallback, array_cap_0)  == 0x40, "IPC.array_cap_0");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_0)  == 0x48, "IPC.array_ptr_0");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_0) == 0x50, "IPC.owned_flag_0");
static_assert(offsetof(InplaceSolverIslandCallback, array_size_1) == 0x5C, "IPC.array_size_1");
static_assert(offsetof(InplaceSolverIslandCallback, array_cap_1)  == 0x60, "IPC.array_cap_1");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_1)  == 0x68, "IPC.array_ptr_1");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_1) == 0x70, "IPC.owned_flag_1");
static_assert(offsetof(InplaceSolverIslandCallback, array_size_2) == 0x7C, "IPC.array_size_2");
static_assert(offsetof(InplaceSolverIslandCallback, array_cap_2)  == 0x80, "IPC.array_cap_2");
static_assert(offsetof(InplaceSolverIslandCallback, array_ptr_2)  == 0x88, "IPC.array_ptr_2");
static_assert(offsetof(InplaceSolverIslandCallback, owned_flag_2) == 0x90, "IPC.owned_flag_2");

#endif /* CMN22_S4_H */