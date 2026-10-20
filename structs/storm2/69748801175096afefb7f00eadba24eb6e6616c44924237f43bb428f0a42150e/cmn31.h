/* cmn31 s2: common render/script struct layouts for NSUNS2.exe (Storm 2 PC)
 * All layouts INFERRED from static decompilation. Not CONFIRMED at runtime.
 * Field names from OWN-GAME sources only (s2 symbols/strings/ns2:: Trilogy map).
 * Sizes proven from allocator arguments or ctor initialization where noted.
 */
#ifndef CMN31_S2_H
#define CMN31_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmRenderManager_DX11
 * Size: unknown, >= 0xC08 (last proven field at 0xC00 from state_surface)
 * Vtable: yes - virtual calls at vfunc+0x800, +0x8C0, +0xBC0, +0xC00
 * Evidence: CreateDX11Device (0x15FA20), QueryDisplayMSAA (0x15F970),
 *           SetRenderStateBlend (0x1643C0), state_surface (44 fields)
 * Note: ptr_0x68 is uint32_t (not void*) because render_state_0x6C at 0x6C
 *       proves only 4 bytes exist between com_ptr_0 end (0x68) and 0x6C.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderManager_DX11 {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x3C];
    /* 0x44 */ uint32_t display_mode;
    /* 0x48 */ uint8_t _pad_48[0x10];
    /* 0x58 */ uint64_t feature_level;
    /* 0x60 */ void *com_ptr_0;
    /* 0x68 */ uint32_t ptr_0x68;
    /* 0x6C */ uint32_t render_state_0x6C;
    /* 0x70 */ uint32_t render_state_0x70;
    /* 0x74 */ uint32_t render_state_0x74;
    /* 0x78 */ uint32_t render_state_0x78;
    /* 0x7C */ uint64_t render_state_0x7C;
    /* 0x84 */ uint32_t render_state_0x84;
    /* 0x88 */ uint64_t render_target_view;
    /* 0x90 */ uint32_t viewport_width;
    /* 0x94 */ uint32_t viewport_height;
    /* 0x98 */ uint32_t render_state_0x98;
    /* 0x9C */ uint64_t render_state_0x9C;
    /* 0xA4 */ uint64_t render_state_0xA4;
    /* 0xAC */ uint8_t _pad_AC[0x4];
    /* 0xB0 */ void *com_ptr_1;
    /* 0xB8 */ void *com_ptr_2;
    /* 0xC0 */ void *com_ptr_3;
    /* 0xC8 */ uint32_t render_state_0xC8;
    /* 0xCC */ uint32_t render_state_0xCC;
    /* 0xD0 */ uint32_t render_state_0xD0;
    /* 0xD4 */ uint32_t render_state_0xD4;
    /* 0xD8 */ uint64_t render_state_0xD8;
    /* 0xE0 */ float render_state_float_0xE0;
    /* 0xE4 */ uint8_t _pad_E4[0x3C];
    /* 0x120 */ uint16_t scissor_x;
    /* 0x122 */ uint16_t scissor_y;
    /* 0x124 */ uint16_t scissor_w;
    /* 0x126 */ uint16_t scissor_h;
    /* 0x128 */ uint8_t scissor_enable;
    /* 0x129 */ uint8_t _pad_129[0xF];
    /* 0x138 */ uint8_t msaa_flag;
    /* 0x139 */ uint8_t _pad_139[0x1F];
    /* 0x158 */ void *ptr_0x158;
    /* 0x160 */ uint8_t _pad_160[0x20];
    /* 0x180 */ void *com_ptr_4;
    /* 0x188 */ void *com_ptr_5;
    /* 0x190 */ void *com_ptr_6;
    /* 0x198 */ uint8_t _pad_198[0x668];
    /* 0x800 */ uint8_t _unk_800[0xC0];
    /* 0x8C0 */ uint8_t _unk_8C0[0x300];
    /* 0xBC0 */ uint8_t _unk_BC0[0x40];
    /* 0xC00 */ uint8_t _unk_C00[0x8];
} mmRenderManager_DX11;

static_assert(offsetof(mmRenderManager_DX11, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderManager_DX11, display_mode) == 0x44, "display_mode");
static_assert(offsetof(mmRenderManager_DX11, feature_level) == 0x58, "feature_level");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_0) == 0x60, "com_ptr_0");
static_assert(offsetof(mmRenderManager_DX11, ptr_0x68) == 0x68, "ptr_0x68");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x6C) == 0x6C, "render_state_0x6C");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x70) == 0x70, "render_state_0x70");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x74) == 0x74, "render_state_0x74");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x78) == 0x78, "render_state_0x78");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x7C) == 0x7C, "render_state_0x7C");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x84) == 0x84, "render_state_0x84");
static_assert(offsetof(mmRenderManager_DX11, render_target_view) == 0x88, "render_target_view");
static_assert(offsetof(mmRenderManager_DX11, viewport_width) == 0x90, "viewport_width");
static_assert(offsetof(mmRenderManager_DX11, viewport_height) == 0x94, "viewport_height");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x98) == 0x98, "render_state_0x98");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x9C) == 0x9C, "render_state_0x9C");
static_assert(offsetof(mmRenderManager_DX11, render_state_0xA4) == 0xA4, "render_state_0xA4");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_1) == 0xB0, "com_ptr_1");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_2) == 0xB8, "com_ptr_2");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_3) == 0xC0, "com_ptr_3");
static_assert(offsetof(mmRenderManager_DX11, render_state_0xC8) == 0xC8, "render_state_0xC8");
static_assert(offsetof(mmRenderManager_DX11, render_state_0xCC) == 0xCC, "render_state_0xCC");
static_assert(offsetof(mmRenderManager_DX11, render_state_0xD0) == 0xD0, "render_state_0xD0");
static_assert(offsetof(mmRenderManager_DX11, render_state_0xD4) == 0xD4, "render_state_0xD4");
static_assert(offsetof(mmRenderManager_DX11, render_state_0xD8) == 0xD8, "render_state_0xD8");
static_assert(offsetof(mmRenderManager_DX11, render_state_float_0xE0) == 0xE0, "render_state_float_0xE0");
static_assert(offsetof(mmRenderManager_DX11, scissor_x) == 0x120, "scissor_x");
static_assert(offsetof(mmRenderManager_DX11, scissor_y) == 0x122, "scissor_y");
static_assert(offsetof(mmRenderManager_DX11, scissor_w) == 0x124, "scissor_w");
static_assert(offsetof(mmRenderManager_DX11, scissor_h) == 0x126, "scissor_h");
static_assert(offsetof(mmRenderManager_DX11, scissor_enable) == 0x128, "scissor_enable");
static_assert(offsetof(mmRenderManager_DX11, msaa_flag) == 0x138, "msaa_flag");
static_assert(offsetof(mmRenderManager_DX11, ptr_0x158) == 0x158, "ptr_0x158");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_4) == 0x180, "com_ptr_4");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_5) == 0x188, "com_ptr_5");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_6) == 0x190, "com_ptr_6");
static_assert(offsetof(mmRenderManager_DX11, _unk_800) == 0x800, "_unk_800");
static_assert(offsetof(mmRenderManager_DX11, _unk_8C0) == 0x8C0, "_unk_8C0");
static_assert(offsetof(mmRenderManager_DX11, _unk_BC0) == 0xBC0, "_unk_BC0");
static_assert(offsetof(mmRenderManager_DX11, _unk_C00) == 0xC00, "_unk_C00");

/* =========================================================================
 * mmRenderManager_NX
 * Size: unknown, >= 0x148 (state_surface last field at 0x140)
 * Inner object size: 0xD8 (proven from _aligned_malloc(0xd8,0x10) in Initialize)
 * Vtable: yes - PTR_FUN_1407dc598 set in dtor at offset 0xD0
 * Evidence: Initialize (0x175070), Finalize (0x1750F0), state_surface (18 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderManager_NX {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x24];
    /* 0x2C */ uint32_t init_field_0x2C;
    /* 0x30 */ uint32_t init_field_0x30;
    /* 0x34 */ uint32_t init_field_0x34;
    /* 0x38 */ uint32_t init_field_0x38;
    /* 0x3C */ uint32_t init_field_0x3C;
    /* 0x40 */ uint32_t init_field_0x40;
    /* 0x44 */ uint32_t init_field_0x44;
    /* 0x48 */ uint32_t init_field_0x48;
    /* 0x4C */ uint32_t init_field_0x4C;
    /* 0x50 */ uint64_t init_field_0x50;
    /* 0x58 */ uint8_t _subobj_0x58[0x40];
    /* 0x98 */ uint8_t _subobj_0x98[0x38];
    /* 0xD0 */ void *dtor_vtable;
    /* 0xD8 */ uint8_t _pad_D8[0x58];
    /* 0x130 */ uint64_t field_0x130;
    /* 0x138 */ uint32_t field_0x138;
    /* 0x13C */ uint8_t _pad_13C[4];
    /* 0x140 */ uint64_t field_0x140;
} mmRenderManager_NX;

static_assert(offsetof(mmRenderManager_NX, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderManager_NX, init_field_0x2C) == 0x2C, "init_field_0x2C");
static_assert(offsetof(mmRenderManager_NX, init_field_0x30) == 0x30, "init_field_0x30");
static_assert(offsetof(mmRenderManager_NX, init_field_0x34) == 0x34, "init_field_0x34");
static_assert(offsetof(mmRenderManager_NX, init_field_0x38) == 0x38, "init_field_0x38");
static_assert(offsetof(mmRenderManager_NX, init_field_0x3C) == 0x3C, "init_field_0x3C");
static_assert(offsetof(mmRenderManager_NX, init_field_0x40) == 0x40, "init_field_0x40");
static_assert(offsetof(mmRenderManager_NX, init_field_0x44) == 0x44, "init_field_0x44");
static_assert(offsetof(mmRenderManager_NX, init_field_0x48) == 0x48, "init_field_0x48");
static_assert(offsetof(mmRenderManager_NX, init_field_0x4C) == 0x4C, "init_field_0x4C");
static_assert(offsetof(mmRenderManager_NX, init_field_0x50) == 0x50, "init_field_0x50");
static_assert(offsetof(mmRenderManager_NX, _subobj_0x58) == 0x58, "_subobj_0x58");
static_assert(offsetof(mmRenderManager_NX, _subobj_0x98) == 0x98, "_subobj_0x98");
static_assert(offsetof(mmRenderManager_NX, dtor_vtable) == 0xD0, "dtor_vtable");
static_assert(offsetof(mmRenderManager_NX, field_0x130) == 0x130, "field_0x130");
static_assert(offsetof(mmRenderManager_NX, field_0x138) == 0x138, "field_0x138");
static_assert(offsetof(mmRenderManager_NX, field_0x140) == 0x140, "field_0x140");

/* =========================================================================
 * mmRenderState
 * Size: unknown, >= 0xD8 (inner GPU ptr at 0xD0 from _aligned_malloc(8,0x10))
 * Vtable: no direct evidence (byte-cast accesses only in state_surface)
 * Evidence: UpdateRenderState (0x167370, 0x1643C0), state_surface (0 typed fields)
 * Note: state_surface returned 0 typed fields due to byte-cast-only accesses;
 *       layout carried from s1 with s2 size confirmation.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderState {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x50];
    /* 0x58 */ uint64_t state_field_0x58;
    /* 0x60 */ uint64_t state_field_0x60;
    /* 0x68 */ uint64_t state_field_0x68;
    /* 0x70 */ uint64_t state_field_0x70;
    /* 0x78 */ uint64_t state_field_0x78;
    /* 0x80 */ uint64_t state_field_0x80;
    /* 0x88 */ uint64_t state_field_0x88;
    /* 0x90 */ uint64_t state_field_0x90;
    /* 0x98 */ uint64_t state_field_0x98;
    /* 0xA0 */ uint64_t state_field_0xA0;
    /* 0xA8 */ uint64_t state_field_0xA8;
    /* 0xB0 */ uint64_t state_field_0xB0;
    /* 0xB8 */ uint64_t state_field_0xB8;
    /* 0xC0 */ uint64_t state_field_0xC0;
    /* 0xC8 */ uint64_t state_field_0xC8;
    /* 0xD0 */ void *gpu_render_state;
} mmRenderState;

static_assert(offsetof(mmRenderState, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderState, state_field_0x58) == 0x58, "state_field_0x58");
static_assert(offsetof(mmRenderState, state_field_0x60) == 0x60, "state_field_0x60");
static_assert(offsetof(mmRenderState, state_field_0x68) == 0x68, "state_field_0x68");
static_assert(offsetof(mmRenderState, state_field_0x70) == 0x70, "state_field_0x70");
static_assert(offsetof(mmRenderState, state_field_0x78) == 0x78, "state_field_0x78");
static_assert(offsetof(mmRenderState, state_field_0x80) == 0x80, "state_field_0x80");
static_assert(offsetof(mmRenderState, state_field_0x88) == 0x88, "state_field_0x88");
static_assert(offsetof(mmRenderState, state_field_0x90) == 0x90, "state_field_0x90");
static_assert(offsetof(mmRenderState, state_field_0x98) == 0x98, "state_field_0x98");
static_assert(offsetof(mmRenderState, state_field_0xA0) == 0xA0, "state_field_0xA0");
static_assert(offsetof(mmRenderState, state_field_0xA8) == 0xA8, "state_field_0xA8");
static_assert(offsetof(mmRenderState, state_field_0xB0) == 0xB0, "state_field_0xB0");
static_assert(offsetof(mmRenderState, state_field_0xB8) == 0xB8, "state_field_0xB8");
static_assert(offsetof(mmRenderState, state_field_0xC0) == 0xC0, "state_field_0xC0");
static_assert(offsetof(mmRenderState, state_field_0xC8) == 0xC8, "state_field_0xC8");
static_assert(offsetof(mmRenderState, gpu_render_state) == 0xD0, "gpu_render_state");

/* =========================================================================
 * mmRenderStateData
 * Size: unknown, >= 0xC8 (last field at 0xC8 from state_surface Merge seed)
 * Vtable: no direct evidence
 * Evidence: Initialize (0x167000), Merge (0x167090), state_surface (17 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderStateData {
    /* 0x00 */ uint8_t _pad_00[0x24];
    /* 0x24 */ uint16_t blend_mode;
    /* 0x26 */ uint32_t rasterizer_mode;
    /* 0x2A */ uint8_t _pad_2A[0x2E];
    /* 0x58 */ uint64_t gpu_state_0x58;
    /* 0x60 */ uint64_t gpu_state_0x60;
    /* 0x68 */ uint64_t gpu_state_0x68;
    /* 0x70 */ uint64_t gpu_state_0x70;
    /* 0x78 */ uint64_t gpu_state_0x78;
    /* 0x80 */ uint64_t gpu_state_0x80;
    /* 0x88 */ uint64_t gpu_state_0x88;
    /* 0x90 */ uint64_t gpu_state_0x90;
    /* 0x98 */ uint64_t gpu_state_0x98;
    /* 0xA0 */ uint64_t gpu_state_0xA0;
    /* 0xA8 */ uint64_t gpu_state_0xA8;
    /* 0xB0 */ uint64_t gpu_state_0xB0;
    /* 0xB8 */ uint32_t gpu_state_count;
    /* 0xBC */ uint8_t _pad_BC[4];
    /* 0xC0 */ uint64_t gpu_state_0xC0;
    /* 0xC8 */ uint64_t gpu_state_0xC8;
} mmRenderStateData;

static_assert(offsetof(mmRenderStateData, blend_mode) == 0x24, "blend_mode");
static_assert(offsetof(mmRenderStateData, rasterizer_mode) == 0x26, "rasterizer_mode");
static_assert(offsetof(mmRenderStateData, gpu_state_0x58) == 0x58, "gpu_state_0x58");
static_assert(offsetof(mmRenderStateData, gpu_state_0x60) == 0x60, "gpu_state_0x60");
static_assert(offsetof(mmRenderStateData, gpu_state_0x68) == 0x68, "gpu_state_0x68");
static_assert(offsetof(mmRenderStateData, gpu_state_0x70) == 0x70, "gpu_state_0x70");
static_assert(offsetof(mmRenderStateData, gpu_state_0x78) == 0x78, "gpu_state_0x78");
static_assert(offsetof(mmRenderStateData, gpu_state_0x80) == 0x80, "gpu_state_0x80");
static_assert(offsetof(mmRenderStateData, gpu_state_0x88) == 0x88, "gpu_state_0x88");
static_assert(offsetof(mmRenderStateData, gpu_state_0x90) == 0x90, "gpu_state_0x90");
static_assert(offsetof(mmRenderStateData, gpu_state_0x98) == 0x98, "gpu_state_0x98");
static_assert(offsetof(mmRenderStateData, gpu_state_0xA0) == 0xA0, "gpu_state_0xA0");
static_assert(offsetof(mmRenderStateData, gpu_state_0xA8) == 0xA8, "gpu_state_0xA8");
static_assert(offsetof(mmRenderStateData, gpu_state_0xB0) == 0xB0, "gpu_state_0xB0");
static_assert(offsetof(mmRenderStateData, gpu_state_count) == 0xB8, "gpu_state_count");
static_assert(offsetof(mmRenderStateData, gpu_state_0xC0) == 0xC0, "gpu_state_0xC0");
static_assert(offsetof(mmRenderStateData, gpu_state_0xC8) == 0xC8, "gpu_state_0xC8");

/* =========================================================================
 * mmRenderStateManager
 * Size: unknown, >= 0x130 (last access param_1[0x25] = byte 0x128 in dtor)
 * Contains 6 eastl::rbtree at offsets 0x20, 0x50, 0x80, 0xB0, 0xE0, 0x110
 * Contains 3 NUMM_THREAD_CRITICAL_SECTION_CONTEXT at offsets 0x08, 0x10, 0x18
 * Vtable: yes - PTR_FUN_1408cf340 then PTR_FUN_1408918e8 in dtor
 * Evidence: ~mmRenderStateManager (0x15F970), state_surface not run (complex dtor)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderStateManager {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t critical_section_0[8];
    /* 0x10 */ uint8_t critical_section_1[8];
    /* 0x18 */ uint8_t critical_section_2[8];
    /* 0x20 */ uint8_t rbtree_0[0x30];
    /* 0x50 */ uint8_t rbtree_1[0x30];
    /* 0x80 */ uint8_t rbtree_2[0x30];
    /* 0xB0 */ uint8_t rbtree_3[0x30];
    /* 0xE0 */ uint8_t rbtree_4[0x30];
    /* 0x110 */ uint8_t rbtree_5[0x30];
} mmRenderStateManager;

static_assert(offsetof(mmRenderStateManager, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderStateManager, critical_section_0) == 0x08, "critical_section_0");
static_assert(offsetof(mmRenderStateManager, critical_section_1) == 0x10, "critical_section_1");
static_assert(offsetof(mmRenderStateManager, critical_section_2) == 0x18, "critical_section_2");
static_assert(offsetof(mmRenderStateManager, rbtree_0) == 0x20, "rbtree_0");
static_assert(offsetof(mmRenderStateManager, rbtree_1) == 0x50, "rbtree_1");
static_assert(offsetof(mmRenderStateManager, rbtree_2) == 0x80, "rbtree_2");
static_assert(offsetof(mmRenderStateManager, rbtree_3) == 0xB0, "rbtree_3");
static_assert(offsetof(mmRenderStateManager, rbtree_4) == 0xE0, "rbtree_4");
static_assert(offsetof(mmRenderStateManager, rbtree_5) == 0x110, "rbtree_5");

/* =========================================================================
 * mmRenderTarget
 * Size: unknown, >= 0x60 (inner object: width +0x08, height +0x0C,
 *        target ptr array +0x10 indexed by param_2*8, count +0x58)
 * Vtable: no direct evidence
 * Evidence: SetRenderTarget (0x166ED0)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderTarget {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint32_t width;
    /* 0x0C */ uint32_t height;
    /* 0x10 */ void *render_target_views[9];
    /* 0x58 */ uint32_t target_count;
    /* 0x5C */ uint8_t _pad_5C[4];
} mmRenderTarget;

static_assert(offsetof(mmRenderTarget, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderTarget, width) == 0x08, "width");
static_assert(offsetof(mmRenderTarget, height) == 0x0C, "height");
static_assert(offsetof(mmRenderTarget, render_target_views) == 0x10, "render_target_views");
static_assert(offsetof(mmRenderTarget, target_count) == 0x58, "target_count");

/* =========================================================================
 * mmSampler
 * Size: unknown, >= 0x28 (GPU sampler ptr at 0x20 from _aligned_malloc(8,0x10))
 * Vtable: no direct evidence
 * Evidence: UpdateSampler (0x168090)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmSampler {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x18];
    /* 0x20 */ void *gpu_sampler_state;
} mmSampler;

static_assert(offsetof(mmSampler, vtable) == 0x00, "vtable");
static_assert(offsetof(mmSampler, gpu_sampler_state) == 0x20, "gpu_sampler_state");

/* =========================================================================
 * mmSamplerData
 * Size: unknown, >= 0x28 (proven from _aligned_malloc(0x28,0x10) in
 *        mmSamplerTranslator::Translate 0x186BD0)
 * Vtable: no direct evidence
 * Evidence: Initialize (0x168080), state_surface (1 field)
 * Layout from Translate: ptr[0]=0, *(ptr+1)u32=0, *(ptr+0xC)f32=10.0f, ptr[4]=0
 * ========================================================================= */
typedef struct __attribute__((packed)) mmSamplerData {
    /* 0x00 */ void *ptr_0x00;
    /* 0x08 */ uint32_t field_0x08;
    /* 0x0C */ float lod_bias;
    /* 0x10 */ void *ptr_0x10;
    /* 0x18 */ uint8_t _pad_18[0x10];
} mmSamplerData;

static_assert(offsetof(mmSamplerData, ptr_0x00) == 0x00, "ptr_0x00");
static_assert(offsetof(mmSamplerData, field_0x08) == 0x08, "field_0x08");
static_assert(offsetof(mmSamplerData, lod_bias) == 0x0C, "lod_bias");
static_assert(offsetof(mmSamplerData, ptr_0x10) == 0x10, "ptr_0x10");

/* =========================================================================
 * mmSamplerTranslator
 * Size: unknown (no state_surface data; factory class)
 * Vtable: likely yes (virtual Translate pattern)
 * Evidence: Translate (0x186BD0) - allocates mmSamplerData via _aligned_malloc(0x28,0x10)
 * Note: This is a translator/factory class; may have minimal instance state.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmSamplerTranslator {
    /* 0x00 */ void *vtable;
} mmSamplerTranslator;

static_assert(offsetof(mmSamplerTranslator, vtable) == 0x00, "vtable");

/* =========================================================================
 * mmScriptParser
 * Size: unknown (static methods only; InitializeScriptIDMap 0x17FB00 is static)
 * Vtable: unknown
 * Evidence: InitializeScriptIDMap (0x17FB00) uses FNV hash, no this pointer.
 *           FinalizeScriptIDMap (0x183AC0) has allocator/dispatcher at +0x30.
 * Note: May be a namespace-like class with static state only.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmScriptParser {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x28];
    /* 0x30 */ void *allocator_dispatcher;
} mmScriptParser;

static_assert(offsetof(mmScriptParser, vtable) == 0x00, "vtable");
static_assert(offsetof(mmScriptParser, allocator_dispatcher) == 0x30, "allocator_dispatcher");

/* =========================================================================
 * mmScriptParserXML
 * Size: unknown, >= 0x110 (ctor writes up to param_1[0x21] = offset 0x108)
 * Vtable: yes - vtable ptr set at offset 0x00 in ctor
 * Evidence: ctor (0x182FE0), Initialize (0x1830C0),
 *           CreateScriptNodeXML (0x1833C0), state_surface (7 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmScriptParserXML {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint64_t field_0x08;
    /* 0x10 */ uint64_t field_0x10;
    /* 0x18 */ uint8_t xml_document[0xC0];
    /* 0xD8 */ uint64_t node_count;
    /* 0xE0 */ uint8_t _pad_E0[8];
    /* 0xE8 */ uint8_t _unk_E8[8];
    /* 0xF0 */ uint64_t field_0xF0;
    /* 0xF8 */ uint64_t field_0xF8;
    /* 0x100 */ uint64_t field_0x100;
    /* 0x108 */ uint32_t field_0x108;
    /* 0x10C */ uint8_t _pad_10C[4];
} mmScriptParserXML;

static_assert(offsetof(mmScriptParserXML, vtable) == 0x00, "vtable");
static_assert(offsetof(mmScriptParserXML, field_0x08) == 0x08, "field_0x08");
static_assert(offsetof(mmScriptParserXML, field_0x10) == 0x10, "field_0x10");
static_assert(offsetof(mmScriptParserXML, xml_document) == 0x18, "xml_document");
static_assert(offsetof(mmScriptParserXML, node_count) == 0xD8, "node_count");
static_assert(offsetof(mmScriptParserXML, field_0xF0) == 0xF0, "field_0xF0");
static_assert(offsetof(mmScriptParserXML, field_0xF8) == 0xF8, "field_0xF8");
static_assert(offsetof(mmScriptParserXML, field_0x100) == 0x100, "field_0x100");
static_assert(offsetof(mmScriptParserXML, field_0x108) == 0x108, "field_0x108");

/* =========================================================================
 * mmScriptTranslator
 * Size: unknown, >= 0x40 (linked list heads at +0x08, +0x20, +0x38)
 * Vtable: no direct evidence (byte-cast accesses only in state_surface)
 * Evidence: CheckEssentialList (0x1859D0), ProcessNode (0x185FE0),
 *           TranslateAttribute (0x186120), state_surface (0 typed fields)
 * Note: Layout carried from s1; s2 state_surface returned 0 typed fields
 *       due to byte-cast-only accesses.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmScriptTranslator {
    /* 0x00 */ void *vtable;
    /* 0x08 */ void *essential_list_head;
    /* 0x10 */ uint8_t _pad_10[0x10];
    /* 0x20 */ void *node_list_head;
    /* 0x28 */ uint8_t _pad_28[0x10];
    /* 0x38 */ void *attr_list_head;
    /* 0x40 */ uint8_t _pad_40[8];
} mmScriptTranslator;

static_assert(offsetof(mmScriptTranslator, vtable) == 0x00, "vtable");
static_assert(offsetof(mmScriptTranslator, essential_list_head) == 0x08, "essential_list_head");
static_assert(offsetof(mmScriptTranslator, node_list_head) == 0x20, "node_list_head");
static_assert(offsetof(mmScriptTranslator, attr_list_head) == 0x38, "attr_list_head");

#endif /* CMN31_S2_H */