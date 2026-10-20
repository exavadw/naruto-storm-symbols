/* cmn31 s1: common render/script struct layouts for NSUNS1.exe (Storm 1 PC)
 * All layouts INFERRED from static decompilation. Not CONFIRMED at runtime.
 * Field names from OWN-GAME sources only (s1 symbols/strings/ns1:: Trilogy map).
 * Sizes proven from allocator arguments or ctor initialization where noted.
 */
#ifndef CMN31_S1_H
#define CMN31_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmRenderManager_DX11
 * Size: unknown, >= 0xC08 (last proven field at 0xC00 from state_surface)
 * Vtable: yes - virtual calls at vfunc+0x100, +0x118, +0x178, +0x180
 * Evidence: CreateDX11Device (0x11F070), QueryDisplayMSAA (0x11EFE0),
 *           SetRenderStateBlend (0x120DA0), state_surface (44 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderManager_DX11 {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x3C];
    /* 0x44 */ uint32_t display_mode;
    /* 0x48 */ void *d3d11_device;
    /* 0x50 */ void *d3d11_context;
    /* 0x58 */ uint64_t feature_level;
    /* 0x60 */ void *com_ptr_0;
    /* 0x68 */ uint8_t _pad_68[4];
    /* 0x6C */ uint32_t render_state_blend;
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
    /* 0xAC */ uint8_t _pad_AC[4];
    /* 0xB0 */ void *com_ptr_1;
    /* 0xB8 */ void *com_ptr_2;
    /* 0xC0 */ void *com_ptr_3;
    /* 0xC8 */ uint32_t render_state_0xC8;
    /* 0xCC */ uint32_t render_state_0xCC;
    /* 0xD0 */ uint32_t render_state_0xD0;
    /* 0xD4 */ uint32_t render_state_0xD4;
    /* 0xD8 */ uint64_t render_state_0xD8;
    /* 0xE0 */ uint32_t render_state_0xE0;
    /* 0xE4 */ uint8_t _pad_E4[4];
    /* 0xE8 */ uint8_t _unk_E8[0x38];
    /* 0x120 */ uint16_t scissor_x;
    /* 0x122 */ uint16_t scissor_y;
    /* 0x124 */ uint16_t scissor_w;
    /* 0x126 */ uint16_t scissor_h;
    /* 0x128 */ uint8_t scissor_enable;
    /* 0x129 */ uint8_t _pad_129[7];
    /* 0x130 */ uint8_t _unk_130[8];
    /* 0x138 */ uint8_t msaa_flag;
    /* 0x139 */ uint8_t _pad_139[7];
    /* 0x140 */ uint8_t msaa_modes[0x34];
    /* 0x174 */ uint8_t _pad_174[4];
    /* 0x178 */ uint8_t _unk_178[8];
    /* 0x180 */ void *com_ptr_4;
    /* 0x188 */ void *com_ptr_5;
    /* 0x190 */ void *com_ptr_6;
    /* 0x198 */ uint8_t _pad_198[0x668];
    /* 0x800 */ uint8_t _unk_800[0xC0];
    /* 0x8C0 */ uint8_t _unk_8C0[0x300];
    /* 0xBC0 */ uint8_t _unk_BC0[0x40];
    /* 0xC00 */ uint8_t _unk_C00[8];
} mmRenderManager_DX11;

static_assert(offsetof(mmRenderManager_DX11, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderManager_DX11, display_mode) == 0x44, "display_mode");
static_assert(offsetof(mmRenderManager_DX11, d3d11_device) == 0x48, "d3d11_device");
static_assert(offsetof(mmRenderManager_DX11, d3d11_context) == 0x50, "d3d11_context");
static_assert(offsetof(mmRenderManager_DX11, feature_level) == 0x58, "feature_level");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_0) == 0x60, "com_ptr_0");
static_assert(offsetof(mmRenderManager_DX11, render_state_blend) == 0x6C, "render_state_blend");
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
static_assert(offsetof(mmRenderManager_DX11, render_state_0xE0) == 0xE0, "render_state_0xE0");
static_assert(offsetof(mmRenderManager_DX11, scissor_x) == 0x120, "scissor_x");
static_assert(offsetof(mmRenderManager_DX11, scissor_y) == 0x122, "scissor_y");
static_assert(offsetof(mmRenderManager_DX11, scissor_w) == 0x124, "scissor_w");
static_assert(offsetof(mmRenderManager_DX11, scissor_h) == 0x126, "scissor_h");
static_assert(offsetof(mmRenderManager_DX11, scissor_enable) == 0x128, "scissor_enable");
static_assert(offsetof(mmRenderManager_DX11, msaa_flag) == 0x138, "msaa_flag");
static_assert(offsetof(mmRenderManager_DX11, msaa_modes) == 0x140, "msaa_modes");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_4) == 0x180, "com_ptr_4");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_5) == 0x188, "com_ptr_5");
static_assert(offsetof(mmRenderManager_DX11, com_ptr_6) == 0x190, "com_ptr_6");
static_assert(offsetof(mmRenderManager_DX11, _unk_800) == 0x800, "_unk_800");
static_assert(offsetof(mmRenderManager_DX11, _unk_8C0) == 0x8C0, "_unk_8C0");
static_assert(offsetof(mmRenderManager_DX11, _unk_BC0) == 0xBC0, "_unk_BC0");
static_assert(offsetof(mmRenderManager_DX11, _unk_C00) == 0xC00, "_unk_C00");

/* =========================================================================
 * mmRenderManager_NX
 * Size: unknown, >= 0x138 (last proven field at 0x130 from Initialize)
 * Inner object size: 0xD8 (proven from _aligned_malloc(0xd8,0x10) in Initialize)
 * Vtable: no direct evidence found
 * Evidence: Initialize (0x11F810), state_surface (4 fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmRenderManager_NX {
    /* 0x00 */ void *vtable;
    /* 0x08 */ void *inner_render_state;
    /* 0x10 */ uint8_t _pad_10[0x120];
    /* 0x130 */ uint64_t init_timestamp_us;
    /* 0x138 */ uint8_t _pad_138[8];
} mmRenderManager_NX;

static_assert(offsetof(mmRenderManager_NX, vtable) == 0x00, "vtable");
static_assert(offsetof(mmRenderManager_NX, inner_render_state) == 0x08, "inner_render_state");
static_assert(offsetof(mmRenderManager_NX, init_timestamp_us) == 0x130, "init_timestamp_us");

/* =========================================================================
 * mmRenderState
 * Size: unknown, >= 0xD8 (last proven field at 0xD0 from UpdateRenderState)
 * Inner GPU state ptr at 0xD0 allocated as 8 bytes (_aligned_malloc(8,0x10))
 * Vtable: no direct evidence
 * Evidence: UpdateRenderState (0x113740), state_surface (16 fields)
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
 * mmScriptParserXML
 * Size: unknown, >= 0x110 (ctor writes up to param_1[0x21] = offset 0x108)
 * Vtable: yes - vtable ptr set at offset 0x00 in ctor (PTR_FUN_1407755d8)
 * Evidence: mmScriptParserXML ctor (0x12EBB0), Initialize (0x12EC90),
 *           CreateScriptNodeXML (0x12F3B0), state_surface (7 fields)
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
 * Vtable: no direct evidence
 * Evidence: CheckEssentialList (0x1315A0), ProcessNode (0x131BB0),
 *           TranslateAttribute (0x131CF0), state_surface (0 fields)
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

#endif /* CMN31_S1_H */
