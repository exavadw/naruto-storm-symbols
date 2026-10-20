/*
 * cmn30.h — Storm 1 (s1, NSUNS1.exe) common engine structs
 * Build: s1  sha256=10231093af9c  image_base=0x140000000
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Field names from s1 symbols/strings only (own-game rule).
 */
#ifndef CMN30_S1_H
#define CMN30_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * mmMutex — thin wrapper around a heap-allocated CRITICAL_SECTION.
 * Ctor allocates 0x28 bytes (_aligned_malloc or mmTLSFMallocAlgorithm::Allocate),
 * stores pointer at offset 0x00, calls InitializeCriticalSection.
 * Lock/Unlock dereference param_1[0] as LPCRITICAL_SECTION.
 * Dtor frees via FreealignCore/FreeCore and zeroes slots 0..3.
 * Object size proven >= 0x20 (4 x uint64 accessed in dtor: param_1[0..3]).
 */
typedef struct __attribute__((packed)) mmMutex {
    void *critical_section;           /* +0x00  ptr to heap CRITICAL_SECTION (0x28 alloc) */
    uint64_t field_08;                /* +0x08  zeroed in dtor, purpose unknown */
    uint64_t field_10;                /* +0x10  zeroed in dtor, purpose unknown */
    void *allocator_or_block;         /* +0x18  param_1[3], freed in dtor if non-null */
} mmMutex;
static_assert(offsetof(mmMutex, critical_section) == 0x00, "mmMutex.critical_section");
static_assert(offsetof(mmMutex, field_08) == 0x08, "mmMutex.field_08");
static_assert(offsetof(mmMutex, field_10) == 0x10, "mmMutex.field_10");
static_assert(offsetof(mmMutex, allocator_or_block) == 0x18, "mmMutex.allocator_or_block");
/* size unknown, >= 0x20 */

/*
 * mmPlane — 4-float plane equation (normal.xyz + distance).
 * Normalize reads/writes param_1[0..3] as float.
 * Construct writes param_1[0..3]. GetDistance reads param_1[0..3].
 * Size proven = 0x10 (4 x float, no further accesses).
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
 * LoadFromCompiledMemory accesses param_1+0xF0 (device/shader ptr),
 *   allocates 8 bytes for it, calls vfunc+0x28 on it.
 * On success appends "ShaderCompiledFromMemory.fx" via
 *   eastl::basic_string::append(param_1+200,...) → string at +0xC8.
 * LoadFromCompiledFile is a path-builder wrapper (no direct this-accesses).
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
 * mmPlatformLibraryDesc — plain data descriptor initialized in ctor.
 * Ctor writes: +0x00=0xF, +0x04=200, +0x08=100, +0x10=0x2D00500,
 *   +0x18=0x13, +0x24=0xF, +0x28=0x100, +0x1C=0, +0x20=0.
 * Size proven >= 0x2A (last write at +0x28 as uint16).
 */
typedef struct __attribute__((packed)) mmPlatformLibraryDesc {
    uint32_t field_00;                /* +0x00  = 0x0F */
    uint32_t field_04;                /* +0x04  = 200 */
    uint64_t field_08;                /* +0x08  = 100 */
    uint64_t field_10;                /* +0x10  = 0x2D00500 */
    uint32_t field_18;                /* +0x18  = 0x13 */
    uint32_t field_1C;                /* +0x1C  = 0 */
    uint32_t field_20;                /* +0x20  = 0 */
    uint32_t field_24;                /* +0x24  = 0x0F */
    uint16_t field_28;                /* +0x28  = 0x100 */
    uint16_t _pad_2A;                 /* +0x2A  alignment */
} mmPlatformLibraryDesc;
static_assert(offsetof(mmPlatformLibraryDesc, field_00) == 0x00, "mmPlatformLibraryDesc.field_00");
static_assert(offsetof(mmPlatformLibraryDesc, field_04) == 0x04, "mmPlatformLibraryDesc.field_04");
static_assert(offsetof(mmPlatformLibraryDesc, field_08) == 0x08, "mmPlatformLibraryDesc.field_08");
static_assert(offsetof(mmPlatformLibraryDesc, field_10) == 0x10, "mmPlatformLibraryDesc.field_10");
static_assert(offsetof(mmPlatformLibraryDesc, field_18) == 0x18, "mmPlatformLibraryDesc.field_18");
static_assert(offsetof(mmPlatformLibraryDesc, field_1C) == 0x1C, "mmPlatformLibraryDesc.field_1C");
static_assert(offsetof(mmPlatformLibraryDesc, field_20) == 0x20, "mmPlatformLibraryDesc.field_20");
static_assert(offsetof(mmPlatformLibraryDesc, field_24) == 0x24, "mmPlatformLibraryDesc.field_24");
static_assert(offsetof(mmPlatformLibraryDesc, field_28) == 0x28, "mmPlatformLibraryDesc.field_28");
/* size unknown, >= 0x2A */

/*
 * mmRenderManager — render state cache with vtable and sub-object pointers.
 * SetRenderState/RecoverRenderState access:
 *   param_1[0] = vtable ptr (vfunc+0xD0,+0xD8,+0xE0,+0xE8)
 *   param_1[1] = saved-state sub-object ptr (deref +0xD0 in Recover)
 *   param_1[2] = current render-state ptr (uint64 at +0x10)
 *   param_1[3] = blend/raster state array ptr (8 x uint64 copied)
 *   param_1[4] = depth-stencil state ptr (2 x uint64)
 *   param_1[5] = byte flag at +0x28 (blend enable?)
 *   byte+0x2C..+0x3B = 16-byte state block copied from src+0x88
 * Size proven >= 0x3C (last write at +0x34 as uint64 → ends at +0x3C).
 */
typedef struct __attribute__((packed)) mmRenderManager {
    void **vtable;                    /* +0x00  vfunc at +0xD0,+0xD8,+0xE0,+0xE8 */
    void *saved_state;                /* +0x08  sub-object, deref+0xD0 in Recover */
    uint64_t current_render_state;    /* +0x10  compared/set vs src+0x20 */
    uint64_t *state_array;            /* +0x18  ptr to 8xuint64 blend/raster block */
    uint64_t *depth_stencil;          /* +0x20  ptr to 2xuint64 DS block */
    uint8_t blend_flag;               /* +0x28  byte flag, compared vs src+0x80 */
    uint8_t _pad_29[3];               /* +0x29  alignment */
    uint64_t state_block_lo;          /* +0x2C  16-byte block from src+0x88 */
    uint64_t state_block_hi;          /* +0x34  ...continued */
} mmRenderManager;
static_assert(offsetof(mmRenderManager, vtable) == 0x00, "mmRenderManager.vtable");
static_assert(offsetof(mmRenderManager, saved_state) == 0x08, "mmRenderManager.saved_state");
static_assert(offsetof(mmRenderManager, current_render_state) == 0x10, "mmRenderManager.current_render_state");
static_assert(offsetof(mmRenderManager, state_array) == 0x18, "mmRenderManager.state_array");
static_assert(offsetof(mmRenderManager, depth_stencil) == 0x20, "mmRenderManager.depth_stencil");
static_assert(offsetof(mmRenderManager, blend_flag) == 0x28, "mmRenderManager.blend_flag");
static_assert(offsetof(mmRenderManager, state_block_lo) == 0x2C, "mmRenderManager.state_block_lo");
static_assert(offsetof(mmRenderManager, state_block_hi) == 0x34, "mmRenderManager.state_block_hi");
/* size unknown, >= 0x3C */

#endif /* CMN30_S1_H */