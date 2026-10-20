/* cmn31 s4: common render/script struct layouts for NSUNS4_release.exe (Storm 4 PC 1.09)
 * All layouts INFERRED from static decompilation. Not CONFIRMED at runtime.
 * Field names from OWN-GAME sources only (s4 symbols/strings).
 * Sizes proven from allocator arguments or ctor initialization where noted.
 * Build: s4 /NSUNS4_release.exe-75912b
 */
#ifndef CMN31_S4_H
#define CMN31_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmRenderManager_DX11
 * Size: unknown, >= 0xC08 (last proven field at 0xC00 from state_surface vcall)
 * Vtable: yes - virtual calls at vfunc+0x100 (0x800), +0x118 (0x8C0), +0x178 (0xBC0), +0x180 (0xC00)
 * Evidence: CreateDX11Device (0x19CBA0), state_surface (44 fields)
 * Note: D3D11CreateDevice writes feature_level at param_1+0x44, device ptr at param_1+0x50
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderManager_DX11 {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x3C];
    /* 0x44 */ uint32_t feature_level;
    /* 0x48 */ uint8_t _pad_48[0x8];
    /* 0x50 */ void *d3d11_device;
    /* 0x58 */ uint8_t _pad_58[0x8];
    /* 0x60 */ void *com_ptr_0;
    /* 0x68 */ uint8_t _pad_68[0x4];
    /* 0x6C */ uint32_t render_state_0x6C;
    /* 0x70 */ uint64_t render_state_0x70;
    /* 0x78 */ uint64_t render_state_0x78;
    /* 0x80 */ uint64_t render_state_0x80;
    /* 0x88 */ uint64_t render_target_view;
    /* 0x90 */ uint32_t viewport_width;
    /* 0x94 */ uint64_t render_state_0x94;
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
static_assert(offsetof(mmRenderManager_DX11, feature_level) == 0x44, "feature_level");
static_assert(offsetof(mmRenderManager_DX11, d3d11_device) == 0x50, "d3d11_device");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_0) == 0x60, "com_ptr_0");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x6C) == 0x6C, "render_state_0x6C");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x70) == 0x70, "render_state_0x70");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x78) == 0x78, "render_state_0x78");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x80) == 0x80, "render_state_0x80");
static_assert(offsetof(mmRenderManager_DX11, render_target_view) == 0x88, "render_target_view");
static_assert(offsetof(mmRenderManager_DX11, viewport_width) == 0x90, "viewport_width");
static_assert(offsetof(mmRenderManager_DX11, render_state_0x94) == 0x94, "render_state_0x94");
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
 * Size: unknown, >= 0x408 (state_surface last field at 0x400)
 * Inner object size: 0xD8 (proven from _aligned_malloc(0xd8,0x10) in s3 Initialize)
 * Vtable: yes - PTR_FUN set at offset 0xD0 in dtor
 * Evidence: ~mmRenderManager_NX, FrameStart, state_surface (4 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderManager_NX {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x90];
    /* 0x98 */ uint8_t _subobj_0x98[0x38];
    /* 0xD0 */ void *dtor_vtable;
    /* 0xD8 */ uint8_t _pad_D8[0x228];
    /* 0x300 */ uint8_t _unk_300[0x100];
    /* 0x400 */ uint8_t _unk_400[0x8];
} mmRenderManager_NX;

static_assert(offsetof(mmRenderManager_NX, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderManager_NX, _subobj_0x98) == 0x98, "_subobj_0x98");
static_assert(offsetof(mmRenderManager_NX, dtor_vtable) == 0xD0, "dtor_vtable");
static_assert(offsetof(mmRenderManager_NX, _unk_300) == 0x300, "_unk_300");
static_assert(offsetof(mmRenderManager_NX, _unk_400) == 0x400, "_unk_400");

/* =========================================================================
 * mmRenderState (< 3 methods in s4: carried from s3)
 * Size: unknown, >= 0xD8 (gpu_render_state ptr at 0xD0 carried from s3)
 * Vtable: no direct evidence (byte-cast accesses only)
 * Evidence: layout carried from s3 with s4 RVA verification.
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
 * mmRenderStateData (< 3 methods in s4: carried from s3)
 * Size: unknown, >= 0xC8 (last field at 0xC8 from s3 state_surface)
 * Vtable: no direct evidence
 * Evidence: layout carried from s3.
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
 * mmRenderStateManager (< 3 methods in s4: carried from s3)
 * Size: unknown, >= 0x140 (6 rbtrees ending at 0x110+0x30=0x140)
 * Contains 6 eastl::rbtree at offsets 0x20, 0x50, 0x80, 0xB0, 0xE0, 0x110
 * Vtable: yes (from s3 dtor evidence)
 * Evidence: layout carried from s3.
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
 * mmRenderTarget (< 3 methods: carried from s3)
 * Size: unknown, >= 0x60 (carried from s3)
 * Vtable: no direct evidence
 * Evidence: layout carried from s3.
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
 * mmSampler (< 3 methods: carried from s3)
 * Size: unknown, >= 0x28 (carried from s3)
 * Vtable: no direct evidence
 * Evidence: layout carried from s3.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmSampler {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x18];
    /* 0x20 */ void *gpu_sampler_state;
} mmSampler;

static_assert(offsetof(mmSampler, vtable) == 0x00, "vtable");
static_assert(offsetof(mmSampler, gpu_sampler_state) == 0x20, "gpu_sampler_state");

/* =========================================================================
 * mmSamplerData (< 3 methods: carried from s3)
 * Size: 0x28 (proven from _aligned_malloc(0x28,0x10) in s3 Translate)
 * Vtable: no direct evidence
 * Evidence: layout carried from s3.
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
 * mmSamplerTranslator (< 3 methods: carried from s3)
 * Size: unknown (factory class, minimal instance state)
 * Vtable: likely yes (virtual Translate pattern)
 * Evidence: layout carried from s3.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmSamplerTranslator {
    /* 0x00 */ void *vtable;
} mmSamplerTranslator;

static_assert(offsetof(mmSamplerTranslator, vtable) == 0x00, "vtable");

/* =========================================================================
 * mmScriptParser (< 3 methods: static methods only)
 * Size: unknown (static methods only; no this pointer usage)
 * Vtable: unknown
 * Evidence: layout carried from s3.
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
 * Vtable: yes - set at offset 0x00 in ctor
 * Evidence: ctor, Initialize, state_surface (7 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmScriptParserXML {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint64_t field_0x08;
    /* 0x10 */ uint64_t field_0x10;
    /* 0x18 */ uint8_t xml_document[0xC0];
    /* 0xD8 */ uint64_t node_count;
    /* 0xE0 */ uint8_t _pad_E0[8];
    /* 0xE8 */ uint8_t _unk_E8[8];
    /* 0xF0 */ uint64_t list_head_0xF0;
    /* 0xF8 */ uint64_t list_head_0xF8;
    /* 0x100 */ uint64_t list_head_0x100;
    /* 0x108 */ uint32_t field_0x108;
    /* 0x10C */ uint8_t _pad_10C[4];
} mmScriptParserXML;

static_assert(offsetof(mmScriptParserXML, vtable) == 0x00, "vtable");
static_assert(offsetof(mmScriptParserXML, field_0x08) == 0x08, "field_0x08");
static_assert(offsetof(mmScriptParserXML, field_0x10) == 0x10, "field_0x10");
static_assert(offsetof(mmScriptParserXML, xml_document) == 0x18, "xml_document");
static_assert(offsetof(mmScriptParserXML, node_count) == 0xD8, "node_count");
static_assert(offsetof(mmScriptParserXML, list_head_0xF0) == 0xF0, "list_head_0xF0");
static_assert(offsetof(mmScriptParserXML, list_head_0xF8) == 0xF8, "list_head_0xF8");
static_assert(offsetof(mmScriptParserXML, list_head_0x100) == 0x100, "list_head_0x100");
static_assert(offsetof(mmScriptParserXML, field_0x108) == 0x108, "field_0x108");

/* =========================================================================
 * mmScriptTranslator
 * Size: unknown, >= 0x48 (state_surface returned 0 typed fields; layout from s3)
 * Vtable: no direct evidence (byte-cast accesses only in state_surface)
 * Evidence: layout carried from s3.
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

#endif /* CMN31_S4_H */