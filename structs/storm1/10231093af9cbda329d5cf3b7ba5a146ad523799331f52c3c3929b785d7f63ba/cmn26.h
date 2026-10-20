/*
 * cmn26.h - mmDrawCommand group structs for NARUTO STORM 1 PC (NSUNS1.exe, s1)
 *
 * INFERRED from static decompilation only. No runtime confirmation.
 * No class in this group has >= 3 methods in s1, so state_surface
 * reconstruction was not performed. Layouts below are partial observations
 * from Execute/Set/GetShortName decompilations.
 *
 * Build: s1 (sha 10231093af9c)
 * Image base: 0x140000000
 *
 * NOTE: All field offsets are absolute from param_1 (this pointer).
 * Sizes are NOT proven from allocator calls (these are command objects
 * constructed inline or via factories not visible in the decompiled methods).
 * All sizes listed as "unknown, >= 0xN".
 */

#ifndef CMN26_H
#define CMN26_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Common mmDrawCommand base class (INFERRED).
 * All mmDrawCommand_* subclasses share this layout prefix.
 * Evidence: GetShortName calls vfunc at *this+0x178, uses this[10] (0x50)
 * as render manager ptr. Destructor sets vtable at offsets 0x00, 0x38, 0x70.
 * Size unknown, >= 0x180 based on vtable entry at +0x178.
 */
typedef struct __attribute__((packed)) mmDrawCommand_Base {
    /* 0x00 */ void *vtable;              /* primary vtable ptr */
    /* 0x08 */ uint8_t _pad_08[0x28];    /* base class data, uncharacterized */
    /* 0x30 */ uint32_t cmd_type;         /* command type / flags (Clear, BindConstantBuffer) */
    /* 0x34 */ uint16_t slot_index;       /* bind slot (BindConstantBuffer, BindTexture) */
    /* 0x36 */ uint8_t _pad_36[0x2];
    /* 0x38 */ void *resource_ptr;        /* bound resource (cb, texture, shader pass) */
    /* 0x40 */ uint8_t _pad_40[0x10];
    /* 0x50 */ void *render_manager;      /* this[10], used by GetShortName */
    /* 0x58 */ uint8_t _pad_58[0x120];   /* rest of base up to vtable call region */
    /* 0x178 */ /* vtable entries referenced: +0x178 (GetShortName name), +0x180 (end) */
} mmDrawCommand_Base;

static_assert(offsetof(mmDrawCommand_Base, vtable) == 0x00, "vtable at 0x00");
static_assert(offsetof(mmDrawCommand_Base, cmd_type) == 0x30, "cmd_type at 0x30");
static_assert(offsetof(mmDrawCommand_Base, slot_index) == 0x34, "slot_index at 0x34");
static_assert(offsetof(mmDrawCommand_Base, resource_ptr) == 0x38, "resource_ptr at 0x38");
static_assert(offsetof(mmDrawCommand_Base, render_manager) == 0x50, "render_manager at 0x50");

/*
 * mmDrawCommand_Clear (INFERRED, 2 methods: ClearEntire, ClearViewport)
 * Size unknown, >= 0x78 based on ClearEntire accessing param_1+0x70.
 */
typedef struct __attribute__((packed)) mmDrawCommand_Clear {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ int32_t clear_type;       /* 0=color-only, 1=color+depth */
    /* 0x34 */ uint8_t _pad_34[0x4];
    /* 0x38 */ uint32_t clear_flags;     /* color/depth/stencil mask bits */
    /* 0x3C */ uint8_t clear_color[16];  /* RGBA float4 */
    /* 0x4C */ uint32_t depth_value;     /* depth clear value */
    /* 0x50 */ uint8_t stencil_value;    /* stencil clear value */
    /* 0x51 */ uint8_t _pad_51[0x3];
    /* 0x54 */ int32_t viewport_x;       /* ClearViewport rect */
    /* 0x58 */ int32_t viewport_y;
    /* 0x5C */ int32_t viewport_w;
    /* 0x60 */ int32_t viewport_h;
    /* 0x64 */ uint8_t _pad_64[0xC];
    /* 0x70 */ void *depth_target;       /* depth buffer for type==1 */
    /* 0x78 */ /* size unknown, >= 0x78 */
} mmDrawCommand_Clear;

static_assert(offsetof(mmDrawCommand_Clear, clear_type) == 0x30, "clear_type at 0x30");
static_assert(offsetof(mmDrawCommand_Clear, clear_flags) == 0x38, "clear_flags at 0x38");
static_assert(offsetof(mmDrawCommand_Clear, clear_color) == 0x3C, "clear_color at 0x3C");
static_assert(offsetof(mmDrawCommand_Clear, depth_value) == 0x4C, "depth_value at 0x4C");
static_assert(offsetof(mmDrawCommand_Clear, stencil_value) == 0x50, "stencil_value at 0x50");
static_assert(offsetof(mmDrawCommand_Clear, viewport_x) == 0x54, "viewport_x at 0x54");
static_assert(offsetof(mmDrawCommand_Clear, viewport_y) == 0x58, "viewport_y at 0x58");
static_assert(offsetof(mmDrawCommand_Clear, viewport_w) == 0x5C, "viewport_w at 0x5C");
static_assert(offsetof(mmDrawCommand_Clear, viewport_h) == 0x60, "viewport_h at 0x60");
static_assert(offsetof(mmDrawCommand_Clear, depth_target) == 0x70, "depth_target at 0x70");

/*
 * mmDrawCommand_RenderPolygon (INFERRED, 1 method: Execute)
 * Size unknown, >= 0xA0 based on param_1+0x9C access.
 */
typedef struct __attribute__((packed)) mmDrawCommand_RenderPolygon {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint8_t vertex_data[0x50]; /* inline vertex/index buffer ref */
    /* 0x80 */ uint8_t polygon_mode;      /* 0=indexed, 1=inline vertices */
    /* 0x81 */ uint8_t _pad_81[0x7];
    /* 0x88 */ void *inline_vertices;     /* inline vertex data ptr */
    /* 0x90 */ uint8_t _pad_90[0x8];
    /* 0x98 */ uint32_t prim_count;
    /* 0x9C */ uint32_t vertex_count;
    /* 0xA0 */ /* size unknown, >= 0xA0 */
} mmDrawCommand_RenderPolygon;

static_assert(offsetof(mmDrawCommand_RenderPolygon, vertex_data) == 0x30, "vertex_data at 0x30");
static_assert(offsetof(mmDrawCommand_RenderPolygon, polygon_mode) == 0x80, "polygon_mode at 0x80");
static_assert(offsetof(mmDrawCommand_RenderPolygon, inline_vertices) == 0x88, "inline_vertices at 0x88");
static_assert(offsetof(mmDrawCommand_RenderPolygon, prim_count) == 0x98, "prim_count at 0x98");
static_assert(offsetof(mmDrawCommand_RenderPolygon, vertex_count) == 0x9C, "vertex_count at 0x9C");

/*
 * mmDrawCommand_SetRenderTarget (INFERRED, 2 methods: GetShortName, SetBackBuffer)
 * Size unknown, >= 0x74 based on param_1+0x70 access.
 */
typedef struct __attribute__((packed)) mmDrawCommand_SetRenderTarget {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x18];
    /* 0x20 */ void *color_target;       /* set to 0 by SetBackBuffer */
    /* 0x28 */ uint8_t _pad_28[0x30];
    /* 0x58 */ uint8_t rt_flags;         /* read by GetShortName */
    /* 0x59 */ uint8_t _pad_59[0xF];
    /* 0x68 */ void *depth_stencil;      /* set to 0 by SetBackBuffer */
    /* 0x70 */ uint32_t scene_id;        /* from nummRender::GetSceneID */
    /* 0x74 */ /* size unknown, >= 0x74 */
} mmDrawCommand_SetRenderTarget;

static_assert(offsetof(mmDrawCommand_SetRenderTarget, color_target) == 0x20, "color_target at 0x20");
static_assert(offsetof(mmDrawCommand_SetRenderTarget, rt_flags) == 0x58, "rt_flags at 0x58");
static_assert(offsetof(mmDrawCommand_SetRenderTarget, depth_stencil) == 0x68, "depth_stencil at 0x68");
static_assert(offsetof(mmDrawCommand_SetRenderTarget, scene_id) == 0x70, "scene_id at 0x70");

/*
 * mmDrawCommand_ApplyShaderPass (INFERRED, 2 methods: Execute, ~dtor)
 * Destructor shows multiple vtable pointers at offsets 0x00, 0x38, 0x70
 * (multiple inheritance or embedded bases).
 * Size unknown, >= 0xB8 based on param_1+0xB0 access in Execute.
 */
typedef struct __attribute__((packed)) mmDrawCommand_ApplyShaderPass {
    /* 0x00 */ void *vtable;             /* primary vtable */
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint8_t apply_flags;      /* char flag controlling execution path */
    /* 0x31 */ uint8_t _pad_31[0x7];
    /* 0x38 */ void *shader_pass_1;      /* first shader pass object (has vtable) */
    /* 0x40 */ uint8_t _pad_40[0x30];
    /* 0x70 */ void *shader_pass_2;      /* second shader pass object (has vtable) */
    /* 0x78 */ uint8_t _pad_78[0x38];
    /* 0xB0 */ void *shader_pass_3;      /* third shader pass object (has vtable) */
    /* 0xB8 */ /* size unknown, >= 0xB8 */
} mmDrawCommand_ApplyShaderPass;

static_assert(offsetof(mmDrawCommand_ApplyShaderPass, apply_flags) == 0x30, "apply_flags at 0x30");
static_assert(offsetof(mmDrawCommand_ApplyShaderPass, shader_pass_1) == 0x38, "shader_pass_1 at 0x38");
static_assert(offsetof(mmDrawCommand_ApplyShaderPass, shader_pass_2) == 0x70, "shader_pass_2 at 0x70");
static_assert(offsetof(mmDrawCommand_ApplyShaderPass, shader_pass_3) == 0xB0, "shader_pass_3 at 0xB0");

/*
 * mmDrawCommand_BindConstantBuffer (INFERRED, 2 methods: Execute, GetShortName)
 * Size unknown, >= 0x40 based on param_1+0x38 access.
 */
typedef struct __attribute__((packed)) mmDrawCommand_BindConstantBuffer {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint32_t slot;            /* constant buffer slot */
    /* 0x34 */ uint16_t register_index;  /* shader register */
    /* 0x36 */ uint8_t _pad_36[0x2];
    /* 0x38 */ void *constant_buffer;    /* cb resource ptr (checked for null + flag at +8) */
    /* 0x40 */ /* size unknown, >= 0x40 */
} mmDrawCommand_BindConstantBuffer;

static_assert(offsetof(mmDrawCommand_BindConstantBuffer, slot) == 0x30, "slot at 0x30");
static_assert(offsetof(mmDrawCommand_BindConstantBuffer, register_index) == 0x34, "register_index at 0x34");
static_assert(offsetof(mmDrawCommand_BindConstantBuffer, constant_buffer) == 0x38, "constant_buffer at 0x38");

/*
 * mmDrawCommand_BindTexture (INFERRED, 2 methods: Set, GetShortName)
 * Size unknown, >= 0x40 based on param_1+0x38 access.
 */
typedef struct __attribute__((packed)) mmDrawCommand_BindTexture {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint32_t bind_flags;      /* texture bind flags */
    /* 0x34 */ uint16_t slot;            /* texture slot index */
    /* 0x36 */ uint8_t _pad_36[0x2];
    /* 0x38 */ void *texture_resource;   /* texture ptr (set to 0 on null) */
    /* 0x40 */ /* size unknown, >= 0x40 */
} mmDrawCommand_BindTexture;

static_assert(offsetof(mmDrawCommand_BindTexture, bind_flags) == 0x30, "bind_flags at 0x30");
static_assert(offsetof(mmDrawCommand_BindTexture, slot) == 0x34, "slot at 0x34");
static_assert(offsetof(mmDrawCommand_BindTexture, texture_resource) == 0x38, "texture_resource at 0x38");

/*
 * mmDrawCommand_BindShaderBuffer (INFERRED, 1 method: Set)
 * Contains eastl::RBTree structures at offsets 0x48, 0x80, 0xB8.
 * Size unknown, >= 0xC8 based on param_1+0xC8 (200 decimal) access.
 */
typedef struct __attribute__((packed)) mmDrawCommand_BindShaderBuffer {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint32_t bind_slot;
    /* 0x34 */ uint8_t _pad_34[0x14];
    /* 0x48 */ uint8_t rbtree_1[0x38];  /* eastl::RBTree node array 1 */
    /* 0x80 */ uint8_t rbtree_2[0x38];  /* eastl::RBTree node array 2 */
    /* 0xB8 */ uint8_t rbtree_3[0x10];  /* eastl::RBTree node array 3 (partial) */
    /* 0xC8 */ /* size unknown, >= 0xC8 */
} mmDrawCommand_BindShaderBuffer;

static_assert(offsetof(mmDrawCommand_BindShaderBuffer, bind_slot) == 0x30, "bind_slot at 0x30");
static_assert(offsetof(mmDrawCommand_BindShaderBuffer, rbtree_1) == 0x48, "rbtree_1 at 0x48");
static_assert(offsetof(mmDrawCommand_BindShaderBuffer, rbtree_2) == 0x80, "rbtree_2 at 0x80");
static_assert(offsetof(mmDrawCommand_BindShaderBuffer, rbtree_3) == 0xB8, "rbtree_3 at 0xB8");

/*
 * mmDrawCommand_SetRenderState (INFERRED, 1 method: Execute)
 * Size unknown, >= 0x38 based on param_1+0x30 access.
 */
typedef struct __attribute__((packed)) mmDrawCommand_SetRenderState {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint64_t render_state;    /* passed to mmRenderManager::SetRenderState */
    /* 0x38 */ /* size unknown, >= 0x38 */
} mmDrawCommand_SetRenderState;

static_assert(offsetof(mmDrawCommand_SetRenderState, render_state) == 0x30, "render_state at 0x30");

/*
 * mmDrawCommand_SetScreenViewport (INFERRED, 1 method: Execute)
 * Passes param_1+0x30 to render manager vfunc+0x100.
 * Size unknown, >= 0x30 + sizeof(viewport struct).
 */
typedef struct __attribute__((packed)) mmDrawCommand_SetScreenViewport {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint8_t viewport_data[0x20]; /* viewport params passed to render mgr */
    /* 0x50 */ /* size unknown, >= 0x50 */
} mmDrawCommand_SetScreenViewport;

static_assert(offsetof(mmDrawCommand_SetScreenViewport, viewport_data) == 0x30, "viewport_data at 0x30");

/*
 * mmDrawCommand_Dispatch (INFERRED, 1 method: GetShortName)
 * Calls render manager vfunc+0x148 with 3 params.
 * Size unknown, >= 0x08 (vtable only observed).
 */
typedef struct __attribute__((packed)) mmDrawCommand_Dispatch {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint32_t dispatch_x;
    /* 0x34 */ uint32_t dispatch_y;
    /* 0x38 */ uint32_t dispatch_z;
    /* 0x3C */ /* size unknown, >= 0x3C */
} mmDrawCommand_Dispatch;

static_assert(offsetof(mmDrawCommand_Dispatch, dispatch_x) == 0x30, "dispatch_x at 0x30");
static_assert(offsetof(mmDrawCommand_Dispatch, dispatch_y) == 0x34, "dispatch_y at 0x34");
static_assert(offsetof(mmDrawCommand_Dispatch, dispatch_z) == 0x38, "dispatch_z at 0x38");

/*
 * mmDrawCommand_BindSampler (INFERRED, 1 method: GetShortName)
 * Size unknown, >= 0x08 (vtable only observed in available methods).
 */
typedef struct __attribute__((packed)) mmDrawCommand_BindSampler {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ uint32_t sampler_slot;
    /* 0x34 */ /* size unknown, >= 0x34 */
} mmDrawCommand_BindSampler;

static_assert(offsetof(mmDrawCommand_BindSampler, sampler_slot) == 0x30, "sampler_slot at 0x30");

#endif /* CMN26_H */