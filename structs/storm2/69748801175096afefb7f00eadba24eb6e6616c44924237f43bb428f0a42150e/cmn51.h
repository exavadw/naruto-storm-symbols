/* cmn51.h — struct group cmn51 for build s2 (NSUNS2.exe)
 * INFERRED from static analysis. Not CONFIRMED.
 * Generated 2026-10-19.
 */
#ifndef CMN51_S2_H
#define CMN51_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccDecryptor
 * Size: 0x14 (proven: ctor writes param_1[4]=0 at offset 0x10, then param_1[0..3])
 * No vtable, no heap alloc. Simple PRNG state used by XOR stream cipher.
 * All methods are effectively static.
 * s2 change: size grew from 0x10 (s1) to 0x14 due to extra counter/index field.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccDecryptor {
    uint32_t state[4];          /* +0x00, size 0x10 — PRNG chain */
    uint32_t index;             /* +0x10, size 0x04 — zeroed first in ctor */
} nuccDecryptor;

_Static_assert(offsetof(nuccDecryptor, state) == 0x00, "nuccDecryptor.state");
_Static_assert(offsetof(nuccDecryptor, index) == 0x10, "nuccDecryptor.index");
_Static_assert(sizeof(nuccDecryptor) == 0x14, "nuccDecryptor size == 0x14");

/* =========================================================================
 * nuccCoord
 * Size: 0x128 (proven: ccFileLoadListForUi::LoadTh(0x128,...) in ccBaseCoord::Create @0x1ED7BC)
 * Vtable: PTR_FUN_1408913b8 at +0x00 (s1 was PTR_FUN_140737500)
 * Base class of nuccClump (embedded at offset 0).
 * Fields inferred from ctors (0x59FB50, 0x59FD80) and state_surface.
 *
 * Layout (all offsets verified against s2 ctor decompile):
 *   +0x00  vtable (uint64*)
 *   +0x08  BlockAllocator region (inherited)
 *   +0x18  field_18 (param_1[3]=0)
 *   +0x20  field_20 (param_1[4]=0)
 *   +0x28  field_28 (param_1[5]=0)
 *   +0x30  parent_coord ptr (param_1[6])
 *   +0x38  diff_scale (float 1.0, *(uint32*)(param_1+7))
 *   +0x3C  local_matrix (Matrix44_MathGeo, 0x40 bytes)
 *   +0x7C  world_matrix_0 (Matrix44_MathGeo, identity loop stride 0x40)
 *   +0xBC  world_matrix_1 (Matrix44_MathGeo)
 *   +0xFC  name_region (two DName ctors at +0xFC and +0x108, total 0x1C bytes to +0x118)
 *   +0x118 field_118 (param_1[0x23]=0)
 *   +0x120 flags (uint32, 0x1010000; high word at +0x122 set in copy ctor)
 *   +0x124 field_124 (uint16, 0)
 *   +0x126 field_126 (uint8, 1)
 *   +0x127 padding to 0x128
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccCoord {
    void     *vtable;           /* +0x00 */
    uint8_t   block_alloc[0x10];/* +0x08 inherited BlockAllocator */
    uint64_t  field_18;         /* +0x18 */
    uint64_t  field_20;         /* +0x20 */
    uint64_t  field_28;         /* +0x28 */
    uint64_t  parent_coord;     /* +0x30 */
    float     diff_scale;       /* +0x38 */
    uint8_t   local_matrix[0x40]; /* +0x3C Matrix44_MathGeo */
    uint8_t   world_matrix_0[0x40]; /* +0x7C */
    uint8_t   world_matrix_1[0x40]; /* +0xBC */
    uint8_t   name_region[0x1C];    /* +0xFC two DName objects */
    uint64_t  field_118;        /* +0x118 */
    uint32_t  flags;            /* +0x120 (high word at +0x122 set in copy ctor) */
    uint16_t  field_124;        /* +0x124 */
    uint8_t   field_126;        /* +0x126 */
    uint8_t   _pad_127;         /* +0x127 */
} nuccCoord;

_Static_assert(offsetof(nuccCoord, vtable) == 0x00, "nuccCoord.vtable");
_Static_assert(offsetof(nuccCoord, block_alloc) == 0x08, "nuccCoord.block_alloc");
_Static_assert(offsetof(nuccCoord, field_18) == 0x18, "nuccCoord.field_18");
_Static_assert(offsetof(nuccCoord, field_20) == 0x20, "nuccCoord.field_20");
_Static_assert(offsetof(nuccCoord, field_28) == 0x28, "nuccCoord.field_28");
_Static_assert(offsetof(nuccCoord, parent_coord) == 0x30, "nuccCoord.parent_coord");
_Static_assert(offsetof(nuccCoord, diff_scale) == 0x38, "nuccCoord.diff_scale");
_Static_assert(offsetof(nuccCoord, local_matrix) == 0x3C, "nuccCoord.local_matrix");
_Static_assert(offsetof(nuccCoord, world_matrix_0) == 0x7C, "nuccCoord.world_matrix_0");
_Static_assert(offsetof(nuccCoord, world_matrix_1) == 0xBC, "nuccCoord.world_matrix_1");
_Static_assert(offsetof(nuccCoord, name_region) == 0xFC, "nuccCoord.name_region");
_Static_assert(offsetof(nuccCoord, field_118) == 0x118, "nuccCoord.field_118");
_Static_assert(offsetof(nuccCoord, flags) == 0x120, "nuccCoord.flags");
_Static_assert(offsetof(nuccCoord, field_124) == 0x124, "nuccCoord.field_124");
_Static_assert(offsetof(nuccCoord, field_126) == 0x126, "nuccCoord.field_126");
_Static_assert(sizeof(nuccCoord) == 0x128, "nuccCoord size == 0x128");

/* =========================================================================
 * nuccDrawCommandBuffer
 * Size unknown, >= 0x64 (fields proven up to +0x18 + nuccCriticalSection ~0x4C)
 * No direct operator new found; object is embedded in parent classes
 * (e.g. nuccLoadBankManager via nuccDrawEnv::Initialize).
 * Fields from Create (0x5D7C40), Alloc (0x5D7BD0), FreeAll (0x5D7C90), dtor (0x5D7B80).
 *
 * s2 layout changes vs s1:
 *   - crit_section at +0x18 (was +0x28 in s1); no init_flag or _reserved_18 visible
 *   - nuccCriticalSection is ~0x4C (vtable + NUMM_THREAD_CRITICAL_SECTION_CONTEXT + flag@+0x48)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccDrawCommandBuffer {
    void     *buffer_ptr;       /* +0x00 MallocCore result in Create */
    int32_t   buffer_capacity;  /* +0x08 *(int*)(param_1+1) in Create */
    uint32_t  write_offset;     /* +0x0C zeroed in Create; swapped in FreeAll */
    uint32_t  swap_offset;      /* +0x10 swapped with +0x0C in FreeAll */
    uint32_t  _pad_14;          /* +0x14 alignment padding */
    uint8_t   crit_section[0x4C]; /* +0x18 nuccCriticalSection (vtable+context+flag) */
} nuccDrawCommandBuffer;

_Static_assert(offsetof(nuccDrawCommandBuffer, buffer_ptr) == 0x00, "nuccDrawCommandBuffer.buffer_ptr");
_Static_assert(offsetof(nuccDrawCommandBuffer, buffer_capacity) == 0x08, "nuccDrawCommandBuffer.buffer_capacity");
_Static_assert(offsetof(nuccDrawCommandBuffer, write_offset) == 0x0C, "nuccDrawCommandBuffer.write_offset");
_Static_assert(offsetof(nuccDrawCommandBuffer, swap_offset) == 0x10, "nuccDrawCommandBuffer.swap_offset");
_Static_assert(offsetof(nuccDrawCommandBuffer, crit_section) == 0x18, "nuccDrawCommandBuffer.crit_section");
/* No sizeof assert: total size unproven (embedded, no standalone allocator call found) */

#endif /* CMN51_S2_H */