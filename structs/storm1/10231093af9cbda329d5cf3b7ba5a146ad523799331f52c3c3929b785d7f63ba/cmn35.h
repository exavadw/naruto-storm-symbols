#ifndef CMN35_S1_H
#define CMN35_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* cmn35 group (NARUTO STORM 1 / s1) — INFERRED layouts from static analysis.
 * All structs are packed with explicit padding. Field names derived from
 * method names and decompiled access patterns; no Switch Trilogy map candidates
 * exist for these Nucc:: engine classes.
 * Sizes proven from game code where possible; otherwise noted as >= N.
 */

/* =========================================================================
 * Nucc::MathGeoSphere — bounding sphere (center + radius)
 * Size: 0x10 (proven: TranslateAbs copies 16 bytes via two uint64 moves)
 * No vtable — pure value type, default ctor at 0x144CD0 is identity.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoSphere {
    uint8_t center_x[4];   /* 0x00 f32 — written by ctor 0x4DB820 via FUN_140144590 */
    uint8_t center_y[4];   /* 0x04 f32 */
    uint8_t center_z[4];   /* 0x08 f32 */
    uint8_t radius[4];     /* 0x0C f32 — read by Radius(), written by ExpandRadius() */
} Nucc_MathGeoSphere;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoSphere, center_x) == 0x00, "MathGeoSphere.center_x");
static_assert(offsetof(Nucc_MathGeoSphere, center_y) == 0x04, "MathGeoSphere.center_y");
static_assert(offsetof(Nucc_MathGeoSphere, center_z) == 0x08, "MathGeoSphere.center_z");
static_assert(offsetof(Nucc_MathGeoSphere, radius)   == 0x0C, "MathGeoSphere.radius");
static_assert(sizeof(Nucc_MathGeoSphere) == 0x10, "MathGeoSphere size");

/* =========================================================================
 * Nucc::MathGeoAABB — axis-aligned bounding box (min + max vectors)
 * Size: 0x18 (proven: ctor writes through param_1+0x14, i.e. 6 floats)
 * No vtable — pure value type.
 * Layout: min.xyz at +0x0, max.xyz at +0xC (from ctor param ordering).
 * CenterPoint/MaxPoint/MinPoint all pass (this+0xC, this) to FUN_1401483c0
 * which constructs a local AABB from the two halves.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_MathGeoAABB {
    uint8_t min_x[4];      /* 0x00 f32 — set by ctor from param_3 */
    uint8_t min_y[4];      /* 0x04 f32 */
    uint8_t min_z[4];      /* 0x08 f32 */
    uint8_t max_x[4];      /* 0x0C f32 — set by ctor from param_2 */
    uint8_t max_y[4];      /* 0x10 f32 */
    uint8_t max_z[4];      /* 0x14 f32 */
} Nucc_MathGeoAABB;
#pragma pack(pop)

static_assert(offsetof(Nucc_MathGeoAABB, min_x) == 0x00, "MathGeoAABB.min_x");
static_assert(offsetof(Nucc_MathGeoAABB, min_y) == 0x04, "MathGeoAABB.min_y");
static_assert(offsetof(Nucc_MathGeoAABB, min_z) == 0x08, "MathGeoAABB.min_z");
static_assert(offsetof(Nucc_MathGeoAABB, max_x) == 0x0C, "MathGeoAABB.max_x");
static_assert(offsetof(Nucc_MathGeoAABB, max_y) == 0x10, "MathGeoAABB.max_y");
static_assert(offsetof(Nucc_MathGeoAABB, max_z) == 0x14, "MathGeoAABB.max_z");
static_assert(sizeof(Nucc_MathGeoAABB) == 0x18, "MathGeoAABB size");

/* =========================================================================
 * Nucc::AllocatedRingBuffer — single ring buffer with allocator
 * Size unknown, >= 0x20 (dtor accesses param_1[3] = +0x18)
 * Vtable at +0x0 (set to PTR_FUN_140658538 in dtor before base dtor call)
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_AllocatedRingBuffer {
    uint8_t vtable[8];          /* 0x00 void* vtable — PTR_FUN_140658538 */
    uint8_t allocator_ptr[8];   /* 0x08 void* — passed to FUN_14047ef90 in dtor */
    uint8_t unk_0010[8];        /* 0x10 unknown */
    uint8_t buffer_ptr[8];      /* 0x18 void* — freed in dtor if non-null */
} Nucc_AllocatedRingBuffer;
#pragma pack(pop)

static_assert(offsetof(Nucc_AllocatedRingBuffer, vtable)       == 0x00, "AllocatedRingBuffer.vtable");
static_assert(offsetof(Nucc_AllocatedRingBuffer, allocator_ptr)== 0x08, "AllocatedRingBuffer.allocator_ptr");
static_assert(offsetof(Nucc_AllocatedRingBuffer, unk_0010)     == 0x10, "AllocatedRingBuffer.unk_0010");
static_assert(offsetof(Nucc_AllocatedRingBuffer, buffer_ptr)   == 0x18, "AllocatedRingBuffer.buffer_ptr");
/* size unknown, >= 0x20 — no sizeof assert */

/* =========================================================================
 * Nucc::AllocatedRingBufferList — list of AllocatedRingBuffer instances
 * Size unknown, >= 0xB8 (ctor accesses param_1[0x16] = +0xB0)
 * Vtable at +0x0 (set to PTR_FUN_140658598 in ctor)
 * Contains embedded std::vector-like structures and sub-objects.
 * Only 1 method in s1 — layout partial.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct Nucc_AllocatedRingBufferList {
    uint8_t vtable[8];          /* 0x00 void* vtable — PTR_FUN_140658598 */
    uint8_t unk_0008[16];       /* 0x08 unknown */
    uint8_t vec_begin[8];       /* 0x18 void* — vector begin ptr (plVar1 = param_1+3) */
    uint8_t vec_end[8];         /* 0x20 void* — vector end ptr */
    uint8_t vec_cap[8];         /* 0x28 void* — vector capacity ptr */
    uint8_t unk_0030[40];       /* 0x30 sub-object at param_1+6 (FUN_14047f1e0 init) */
    uint8_t unk_0058[8];        /* 0x58 vtable ptr for sub-object */
    uint8_t sub_obj_0060[40];   /* 0x60 sub-object at param_1+9 (FUN_14014d1b4) */
    uint8_t sub_obj_0088[40];   /* 0x88 sub-object at param_1+0xE (FUN_14014d14c) */
    uint8_t unk_00B0[8];        /* 0xB0 field at param_1[0x16] */
} Nucc_AllocatedRingBufferList;
#pragma pack(pop)

static_assert(offsetof(Nucc_AllocatedRingBufferList, vtable)     == 0x00, "AllocatedRingBufferList.vtable");
static_assert(offsetof(Nucc_AllocatedRingBufferList, vec_begin)  == 0x18, "AllocatedRingBufferList.vec_begin");
static_assert(offsetof(Nucc_AllocatedRingBufferList, vec_end)    == 0x20, "AllocatedRingBufferList.vec_end");
static_assert(offsetof(Nucc_AllocatedRingBufferList, vec_cap)    == 0x28, "AllocatedRingBufferList.vec_cap");
static_assert(offsetof(Nucc_AllocatedRingBufferList, unk_0058)   == 0x58, "AllocatedRingBufferList.unk_0058");
static_assert(offsetof(Nucc_AllocatedRingBufferList, sub_obj_0060)== 0x60, "AllocatedRingBufferList.sub_obj_0060");
static_assert(offsetof(Nucc_AllocatedRingBufferList, sub_obj_0088)== 0x88, "AllocatedRingBufferList.sub_obj_0088");
static_assert(offsetof(Nucc_AllocatedRingBufferList, unk_00B0)   == 0xB0, "AllocatedRingBufferList.unk_00B0");
/* size unknown, >= 0xB8 — no sizeof assert */

#endif /* CMN35_S1_H */