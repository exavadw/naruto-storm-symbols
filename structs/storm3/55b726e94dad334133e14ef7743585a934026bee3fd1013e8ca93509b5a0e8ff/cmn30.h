/*
 * cmn30.h — S3 (NSUNS3.exe) cmn30 struct group, pre-decompile layout
 * Build: s3 / NSUNS3.exe-a7124b / sha256 55b726e94dad
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Object sizes proven from allocator/ctor code, never from sizeof reconstruction.
 */
#ifndef CMN30_S3_H
#define CMN30_S3_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

/* ------------------------------------------------------------------ */
/* mmMutex — size 0x28 (proven: _aligned_malloc(0x28, 0x10) in ctor) */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) s3_mmMutex {
    /* 0x00 */ void    *critical_section;   /* CRITICAL_SECTION*, allocated separately */
    /* 0x08 */ uint8_t  _pad_08[0x18];     /* 0x08..0x1F reserved / alignment */
    /* 0x20 */ uint32_t block_id;          /* cleared to 0 in dtor; set via FUN_140684c60 in ctor2 */
    /* 0x24 */ uint32_t _pad_24;           /* padding to reach 0x28 */
} s3_mmMutex;

static_assert(sizeof(s3_mmMutex) == 0x28, "s3_mmMutex size");
static_assert(offsetof(s3_mmMutex, critical_section) == 0x00, "mmMutex.critical_section");
static_assert(offsetof(s3_mmMutex, block_id)         == 0x20, "mmMutex.block_id");

/* ------------------------------------------------------------------ */
/* mmPlane — size 0x10 (4 floats: normal.xyz + distance)             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) s3_mmPlane {
    /* 0x00 */ float nx;       /* normal X */
    /* 0x04 */ float ny;       /* normal Y */
    /* 0x08 */ float nz;       /* normal Z */
    /* 0x0C */ float d;        /* plane distance (computed in Construct) */
} s3_mmPlane;

static_assert(sizeof(s3_mmPlane) == 0x10, "s3_mmPlane size");
static_assert(offsetof(s3_mmPlane, nx) == 0x00, "mmPlane.nx");
static_assert(offsetof(s3_mmPlane, ny) == 0x04, "mmPlane.ny");
static_assert(offsetof(s3_mmPlane, nz) == 0x08, "mmPlane.nz");
static_assert(offsetof(s3_mmPlane, d)  == 0x0C, "mmPlane.d");

/* ------------------------------------------------------------------ */
/* mmPixelShader — size >= 0xF8 (proven: field at param_1+0xF0)      */
/* Only two fields recovered from decompilation; rest is opaque.     */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) s3_mmPixelShader {
    /* 0x00 */ uint8_t  _opaque_00[0xC8];  /* 0x00..0xC7 unknown (base class / vtable etc.) */
    /* 0xC8 */ char     name_buf[0x28];    /* shader name string buffer (param_1+200, 40 bytes) */
    /* 0xF0 */ void    *compiled_shader;   /* ptr allocated via _aligned_malloc(8,0x10) or pool */
    /* 0xF8 */ uint8_t  _tail[0];          /* end marker; actual object may be larger */
} s3_mmPixelShader;

static_assert(offsetof(s3_mmPixelShader, name_buf)        == 0xC8, "mmPixelShader.name_buf");
static_assert(offsetof(s3_mmPixelShader, compiled_shader) == 0xF0, "mmPixelShader.compiled_shader");

/* ------------------------------------------------------------------ */
/* mmRenderManager — size >= 0x98 (proven: field at param_1[0x12]    */
/* = offset 0x90). Vtable-dispatch offsets 0xD0/0xD8/0xE0/0xE8 are   */
/* virtual method slots, not data fields.                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) s3_mmRenderManager {
    /* 0x00 */ void    *vtable;            /* PTR_FUN_1409dcf48 (active) / PTR_FUN_1409ec308 (base) */
    /* 0x08 */ void    *saved_state_ptr;   /* param_1[1]: pointer to saved render state block */
    /* 0x10 */ void    *texture_or_sampler;/* param_1[2]: compared against state+0x20 */
    /* 0x18 */ void    *blend_state_buf;   /* param_1[3]: 9×uint64 blend/rasterizer state cache */
    /* 0x20 */ void    *viewport_buf;      /* param_1[4]: viewport/scissor rect cache */
    /* 0x28 */ uint8_t  render_flag;       /* param_1+5 byte: compared against state+0x80 */
    /* 0x29 */ uint8_t  _pad_29[3];       /* align to 0x2C */
    /* 0x2C */ uint32_t rasterizer_state;  /* written by SetRenderState, read by Recover */
    /* 0x30 */ uint32_t _field_30;         /* part of state cache array (param_1+6 as u32) */
    /* 0x34 */ uint32_t depth_stencil;     /* written by SetRenderState, read by Recover */
    /* 0x38 */ uint32_t _field_38;         /* part of state cache array (param_1+7 as u32) */
    /* 0x3C */ uint32_t flags_or_counter;  /* cleared to 0 in dtor */
    /* 0x40 */ uint8_t  _pad_40[0x50];    /* 0x40..0x8F gap (no accesses seen) */
    /* 0x90 */ void    *resource_handle;   /* param_1[0x12]: freed via FUN_140684050 in dtor */
    /* 0x98 */ uint8_t  _tail[0];          /* end marker; actual object may be larger */
} s3_mmRenderManager;

static_assert(offsetof(s3_mmRenderManager, vtable)            == 0x00, "mmRenderManager.vtable");
static_assert(offsetof(s3_mmRenderManager, saved_state_ptr)   == 0x08, "mmRenderManager.saved_state_ptr");
static_assert(offsetof(s3_mmRenderManager, texture_or_sampler)== 0x10, "mmRenderManager.texture_or_sampler");
static_assert(offsetof(s3_mmRenderManager, blend_state_buf)   == 0x18, "mmRenderManager.blend_state_buf");
static_assert(offsetof(s3_mmRenderManager, viewport_buf)      == 0x20, "mmRenderManager.viewport_buf");
static_assert(offsetof(s3_mmRenderManager, render_flag)       == 0x28, "mmRenderManager.render_flag");
static_assert(offsetof(s3_mmRenderManager, rasterizer_state)  == 0x2C, "mmRenderManager.rasterizer_state");
static_assert(offsetof(s3_mmRenderManager, _field_30)         == 0x30, "mmRenderManager._field_30");
static_assert(offsetof(s3_mmRenderManager, depth_stencil)     == 0x34, "mmRenderManager.depth_stencil");
static_assert(offsetof(s3_mmRenderManager, _field_38)         == 0x38, "mmRenderManager._field_38");
static_assert(offsetof(s3_mmRenderManager, flags_or_counter)  == 0x3C, "mmRenderManager.flags_or_counter");
static_assert(offsetof(s3_mmRenderManager, resource_handle)   == 0x90, "mmRenderManager.resource_handle");

#endif /* CMN30_S3_H */