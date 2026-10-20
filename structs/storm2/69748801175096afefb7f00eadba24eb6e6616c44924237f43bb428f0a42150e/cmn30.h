/*
 * cmn30.h — Storm 2 (s2, NSUNS2.exe) common engine structs
 * Build: s2  sha256=abf2b6  image_base=0x140000000
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Field names from s2 symbols/strings only (own-game rule).
 */
#ifndef CMN30_S2_H
#define CMN30_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * mmMutex — thin wrapper around a heap-allocated CRITICAL_SECTION.
 * Ctor (0x1532B0) allocates 0x28 bytes (_aligned_malloc(0x28,0x10)),
 *   stores pointer at offset 0x00, calls InitializeCriticalSection.
 * Second ctor (0x3D6BE4, 157 callers) uses Nucc::Memory::BlockAllocator:
 *   reads param_1+3 for BlockId, frees *param_1 via FreealignCore,
 *   zeroes param_1[0..2].
 * Lock/Unlock dereference param_1[0] as LPCRITICAL_SECTION.
 * Dtor (0x1A4D14) frees param_1[3] via FreeCore if non-null,
 *   clears *(uint32*)(param_1+4)=0 at offset 0x20, sets vtable.
 * Object size proven = 0x28 from _aligned_malloc(0x28,0x10) in ctor.
 * Vtables: PTR_FUN_1407f2db8 (active), PTR_FUN_14089c1b8 (dtor final).
 */
typedef struct __attribute__((packed)) mmMutex {
    void *critical_section;           /* +0x00  ptr to heap CRITICAL_SECTION (0x28 alloc) */
    uint64_t field_08;                /* +0x08  zeroed in second ctor, purpose unknown */
    uint64_t field_10;                /* +0x10  zeroed in second ctor, purpose unknown */
    void *allocator_or_block;         /* +0x18  param_1[3], freed in dtor if non-null */
    uint32_t field_20;                /* +0x20  cleared in dtor */
    uint32_t _pad_24;                 /* +0x24  pad to 0x28 */
} mmMutex;
static_assert(offsetof(mmMutex, critical_section) == 0x00, "mmMutex.critical_section");
static_assert(offsetof(mmMutex, field_08) == 0x08, "mmMutex.field_08");
static_assert(offsetof(mmMutex, field_10) == 0x10, "mmMutex.field_10");
static_assert(offsetof(mmMutex, allocator_or_block) == 0x18, "mmMutex.allocator_or_block");
static_assert(offsetof(mmMutex, field_20) == 0x20, "mmMutex.field_20");
static_assert(sizeof(mmMutex) == 0x28, "mmMutex.size");

/*
 * mmPlane — 4-float plane equation (normal.xyz + distance).
 * Construct (0x158650) writes param_1[0..3]: copies normal from param_2,
 *   computes distance = -dot(normal, point).
 * GetDistance (0x1586A0) returns dot(normal, point) + distance.
 * Normalize (0x1586D0) normalizes param_1[0..3] by sqrt(sum of squares).
 * Size proven = 0x10 (4 x float, no further accesses in any method).
 */
typedef struct __attribute__((packed)) mmPlane {
    float normal_x;                   /* +0x00 */
    float normal_y;                   /* +0x04 */
    float normal_z;                   /* +0x08 */
    float distance;                   /* +0x0C */
} mmPlane;
static_assert(offsetof(mmPlane, normal_x) == 0x00, "mmPlane.normal_x");
static_assert(offsetof(mmPlane, normal_y) == 0x04, "mmPlane.normal_y");
static_assert(offsetof(mmPlane, normal_z) == 0x08, "mmPlane.normal_z");
static_assert(offsetof(mmPlane, distance) == 0x0C, "mmPlane.distance");
static_assert(sizeof(mmPlane) == 0x10, "mmPlane.size");

/*
 * mmPixelShader — shader object with eastl::string name and device ptr.
 * LoadFromCompiledFile (0x16BA10): checks param_1+0xF0 != 0 (already loaded),
 *   allocates 8 bytes for device shader ptr, stores at +0xF0,
 *   calls vfunc+0x20 on it. On success appends path via
 *   eastl::basic_string::append(param_1+200,...) → string storage at +0xC8.
 * LoadFromCompiledMemory (0x16BB60): same pattern, vfunc+0x28,
 *   appends "ShaderCompiledFromMemory.fx" at +0xC8.
 * LoadFromCompiledFile wrapper (0x16BC70): builds path, calls 0x16BA10.
 * Size unknown, >= 0xF8 (last proven access at +0xF0, 8-byte pointer).
 */
typedef struct __attribute__((packed)) mmPixelShader {
    uint8_t _base[0xC8];              /* +0x00  unknown base / vtable region */
    uint8_t shader_name_storage[0x28];/* +0xC8  eastl::basic_string (40 bytes typical) */
    void *device_shader;              /* +0xF0  allocated 8-byte ptr */
    uint8_t _tail[0x08];              /* +0xF8  pad to >= 0x100 */
} mmPixelShader;
static_assert(offsetof(mmPixelShader, _base) == 0x00, "mmPixelShader._base");
static_assert(offsetof(mmPixelShader, shader_name_storage) == 0xC8, "mmPixelShader.shader_name_storage");
static_assert(offsetof(mmPixelShader, device_shader) == 0xF0, "mmPixelShader.device_shader");
static_assert(offsetof(mmPixelShader, _tail) == 0xF8, "mmPixelShader._tail");
/* size unknown, >= 0xF8 */

/*
 * mmRenderManager — render state cache with vtable and sub-object pointers.
 * SetRenderState (0x171980) accesses:
 *   param_1[0] = vtable ptr (vfunc+0xD0,+0xD8,+0xE0,+0xE8)
 *   param_1[1] = saved-state sub-object ptr (unused in Set, used in Recover)
 *   param_1[2] = current render-state ptr (uint64 at +0x10, compared vs src+0x20)
 *   param_1[3] = blend/raster state array ptr (8 x uint64 copied from src+0x28..0x68)
 *   param_1[4] = depth-stencil state ptr (2 x uint64 from src+0x70..0x7C)
 *   param_1[5] = byte flag at +0x28 (blend enable, compared vs src+0x80)
 *   byte+0x2C..+0x3B = 16-byte state block copied from src+0x88..0x94
 * RecoverRenderState (0x171AE0): reads saved_state->+0xD0, restores all fields.
 * Dtor (0x58B7E0): sets vtable PTR_FUN_14088fa80, calls nuccAnmBase::ClearClumpData,
 *   destroys param_1[6] (nuccAnmCtrlTrack*), clears param_1[3]=0,
 *   clears *(uint32*)(param_1+0x3C)=0, destroys param_1[0x12] (nuccInstanceList*),
 *   sets final vtable PTR_FUN_14089c1b8.
 * Size proven >= 0x98 (param_1[0x12] accessed at offset 0x90, 8-byte ptr → ends 0x98).
 * Vtables: PTR_FUN_14088fa80 (dtor entry), PTR_FUN_14089c1b8 (dtor final/base).
 */
typedef struct __attribute__((packed)) mmRenderManager {
    void **vtable;                    /* +0x00  vfunc at +0xD0,+0xD8,+0xE0,+0xE8 */
    void *saved_state;                /* +0x08  sub-object, deref+0xD0 in Recover */
    uint64_t current_render_state;    /* +0x10  compared/set vs src+0x20 */
    uint64_t *state_array;            /* +0x18  ptr to 8xuint64 blend/raster block */
    uint64_t *depth_stencil;          /* +0x20  ptr to 2xuint64+float DS block */
    uint8_t blend_flag;               /* +0x28  byte flag, compared vs src+0x80 */
    uint8_t _pad_29[3];               /* +0x29  alignment */
    uint64_t state_block_lo;          /* +0x2C  16-byte block from src+0x88 */
    uint64_t state_block_hi;          /* +0x34  ...continued */
    uint32_t field_3C;                /* +0x3C  cleared in dtor */
    uint32_t _pad_40;                 /* +0x40  alignment to reach 0x48 */
    uint8_t _gap_44[4];               /* +0x44  pad to 0x48 */
    uint64_t field_48;                /* +0x48  unknown, between 0x3C and anm_track */
    void *anm_ctrl_track;             /* +0x50  param_1[6], nuccAnmCtrlTrack* destroyed in dtor */
    uint8_t _gap_58[0x38];            /* +0x58  gap to instance_list at +0x90 */
    void *instance_list;              /* +0x90  param_1[0x12], nuccInstanceList* freed in dtor */
} mmRenderManager;
static_assert(offsetof(mmRenderManager, vtable) == 0x00, "mmRenderManager.vtable");
static_assert(offsetof(mmRenderManager, saved_state) == 0x08, "mmRenderManager.saved_state");
static_assert(offsetof(mmRenderManager, current_render_state) == 0x10, "mmRenderManager.current_render_state");
static_assert(offsetof(mmRenderManager, state_array) == 0x18, "mmRenderManager.state_array");
static_assert(offsetof(mmRenderManager, depth_stencil) == 0x20, "mmRenderManager.depth_stencil");
static_assert(offsetof(mmRenderManager, blend_flag) == 0x28, "mmRenderManager.blend_flag");
static_assert(offsetof(mmRenderManager, state_block_lo) == 0x2C, "mmRenderManager.state_block_lo");
static_assert(offsetof(mmRenderManager, state_block_hi) == 0x34, "mmRenderManager.state_block_hi");
static_assert(offsetof(mmRenderManager, field_3C) == 0x3C, "mmRenderManager.field_3C");
static_assert(offsetof(mmRenderManager, field_48) == 0x48, "mmRenderManager.field_48");
static_assert(offsetof(mmRenderManager, anm_ctrl_track) == 0x50, "mmRenderManager.anm_ctrl_track");
static_assert(offsetof(mmRenderManager, instance_list) == 0x90, "mmRenderManager.instance_list");
/* size unknown, >= 0x98 */

#endif /* CMN30_S2_H */