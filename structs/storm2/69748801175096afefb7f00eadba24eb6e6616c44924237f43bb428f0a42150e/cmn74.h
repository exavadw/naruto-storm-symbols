/* cmn74.h — struct group cmn74 for build s2 (NSUNS2.exe)
 * INFERRED from static decompilation. Not CONFIRMED by runtime.
 * All offsets derived from PC x64 decompile (image base 0x140000000).
 * Own-game names only (Storm 2 sources).
 */
#ifndef CMN74_S2_H
#define CMN74_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nummDynamicVertexBufferBase
 * Size: unknown, >= 0x70 (no constructor/allocator found; global singleton
 * used by render pipeline)
 * Evidence: Reset(0x56EB60), AllocateBuffer(0x56DDA0), Lock(0x56E730),
 * Unlock(0x56EE50), ExpandBlock(0x56E480), Draw(0x56E210/0x56E380),
 * SetOffsetInfo(0x56D820/0x56EC10/0x56ED30)
 * Vtable: not recovered (vtable ptr at +0x00 assumed)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct nummDynamicVertexBufferBase {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x08];
    /* 0x10 */ void *block_array_begin[2];
    /* 0x20 */ void *block_array_end_unused;
    /* 0x28 */ uint8_t _pad_28[0x08];
    /* 0x30 */ void *block_array_begin_1;
    /* 0x38 */ void *block_array_end_1;
    /* 0x40 */ uint8_t _pad_40[0x10];
    /* 0x50 */ uint32_t total_vertices;
    /* 0x54 */ uint32_t max_vertex_size;
    /* 0x58 */ uint32_t active_buffer_index;
    /* 0x5c */ uint32_t block_count;
    /* 0x60 */ void *lock_param;
    /* 0x68 */ void *cleanup_dispatch;
} nummDynamicVertexBufferBase;
#pragma pack(pop)

static_assert(sizeof(nummDynamicVertexBufferBase) >= 0x70, "nummDynamicVertexBufferBase size");
static_assert(offsetof(nummDynamicVertexBufferBase, vtable) == 0x00, "nummDynamicVertexBufferBase::vtable");
static_assert(offsetof(nummDynamicVertexBufferBase, _pad_08) == 0x08, "nummDynamicVertexBufferBase::_pad_08");
static_assert(offsetof(nummDynamicVertexBufferBase, block_array_begin) == 0x10, "nummDynamicVertexBufferBase::block_array_begin");
static_assert(offsetof(nummDynamicVertexBufferBase, block_array_end_unused) == 0x20, "nummDynamicVertexBufferBase::block_array_end_unused");
static_assert(offsetof(nummDynamicVertexBufferBase, _pad_28) == 0x28, "nummDynamicVertexBufferBase::_pad_28");
static_assert(offsetof(nummDynamicVertexBufferBase, block_array_begin_1) == 0x30, "nummDynamicVertexBufferBase::block_array_begin_1");
static_assert(offsetof(nummDynamicVertexBufferBase, block_array_end_1) == 0x38, "nummDynamicVertexBufferBase::block_array_end_1");
static_assert(offsetof(nummDynamicVertexBufferBase, _pad_40) == 0x40, "nummDynamicVertexBufferBase::_pad_40");
static_assert(offsetof(nummDynamicVertexBufferBase, total_vertices) == 0x50, "nummDynamicVertexBufferBase::total_vertices");
static_assert(offsetof(nummDynamicVertexBufferBase, max_vertex_size) == 0x54, "nummDynamicVertexBufferBase::max_vertex_size");
static_assert(offsetof(nummDynamicVertexBufferBase, active_buffer_index) == 0x58, "nummDynamicVertexBufferBase::active_buffer_index");
static_assert(offsetof(nummDynamicVertexBufferBase, block_count) == 0x5c, "nummDynamicVertexBufferBase::block_count");
static_assert(offsetof(nummDynamicVertexBufferBase, lock_param) == 0x60, "nummDynamicVertexBufferBase::lock_param");
static_assert(offsetof(nummDynamicVertexBufferBase, cleanup_dispatch) == 0x68, "nummDynamicVertexBufferBase::cleanup_dispatch");

/* ========================================================================
 * nummDynamicVertexBufferBase_Block
 * Size: 0x18 (wrapper) — ExpandBlock allocates 0x18 via operator_new(0x18)
 * Inner buffer: 0x90 bytes allocated separately via operator_new(0x90)
 * Evidence: Block::Create(0x56DFB0), ExpandBlock(0x56E480), Draw(0x56E210)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct nummDynamicVertexBufferBase_Block {
    /* 0x00 */ void *inner_buf;
    /* 0x08 */ uint8_t _pad_08[0x08];
    /* 0x10 */ uint32_t vertex_count;
    /* 0x14 */ uint32_t _pad_14;
} nummDynamicVertexBufferBase_Block;
#pragma pack(pop)

static_assert(sizeof(nummDynamicVertexBufferBase_Block) == 0x18, "nummDynamicVertexBufferBase_Block size");
static_assert(offsetof(nummDynamicVertexBufferBase_Block, inner_buf) == 0x00, "nummDynamicVertexBufferBase_Block::inner_buf");
static_assert(offsetof(nummDynamicVertexBufferBase_Block, _pad_08) == 0x08, "nummDynamicVertexBufferBase_Block::_pad_08");
static_assert(offsetof(nummDynamicVertexBufferBase_Block, vertex_count) == 0x10, "nummDynamicVertexBufferBase_Block::vertex_count");
static_assert(offsetof(nummDynamicVertexBufferBase_Block, _pad_14) == 0x14, "nummDynamicVertexBufferBase_Block::_pad_14");

/* ========================================================================
 * nummLineMaterial
 * Size: >= 0xD8 (ctor writes param_1[0x1a] = offset 0xD0, 8 bytes → 0xD8)
 * Evidence: ctor(0x56C550), Initialize(0x56C950), Finalize(0x56C770)
 * Vtable: PTR_FUN_14088d388 (set in ctor)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct nummLineMaterial {
    /* 0x00 */ void *vtable;
    /* 0x08 */ void *shader_vs;
    /* 0x10 */ void *shader_ps;
    /* 0x18 */ void *shader_pass;
    /* 0x20 */ void *state_block;
    /* 0x28 */ void *render_state;
    /* 0x30 */ uint32_t material_flags;
    /* 0x34 */ uint8_t _pad_34[0x0C];
    /* 0x40 */ uint8_t embedded_list_1[0x24];
    /* 0x64 */ uint8_t _pad_64[0x0C];
    /* 0x70 */ uint8_t embedded_list_2[0x24];
    /* 0x94 */ uint8_t _pad_94[0x0C];
    /* 0xA0 */ uint8_t embedded_list_3[0x24];
    /* 0xC4 */ uint8_t _pad_C4[0x04];
    /* 0xC8 */ uint8_t sub_object[0x08];
    /* 0xD0 */ uint64_t trailing_field;
} nummLineMaterial;
#pragma pack(pop)

static_assert(sizeof(nummLineMaterial) >= 0xD8, "nummLineMaterial size");
static_assert(offsetof(nummLineMaterial, vtable) == 0x00, "nummLineMaterial::vtable");
static_assert(offsetof(nummLineMaterial, shader_vs) == 0x08, "nummLineMaterial::shader_vs");
static_assert(offsetof(nummLineMaterial, shader_ps) == 0x10, "nummLineMaterial::shader_ps");
static_assert(offsetof(nummLineMaterial, shader_pass) == 0x18, "nummLineMaterial::shader_pass");
static_assert(offsetof(nummLineMaterial, state_block) == 0x20, "nummLineMaterial::state_block");
static_assert(offsetof(nummLineMaterial, render_state) == 0x28, "nummLineMaterial::render_state");
static_assert(offsetof(nummLineMaterial, material_flags) == 0x30, "nummLineMaterial::material_flags");
static_assert(offsetof(nummLineMaterial, _pad_34) == 0x34, "nummLineMaterial::_pad_34");
static_assert(offsetof(nummLineMaterial, embedded_list_1) == 0x40, "nummLineMaterial::embedded_list_1");
static_assert(offsetof(nummLineMaterial, _pad_64) == 0x64, "nummLineMaterial::_pad_64");
static_assert(offsetof(nummLineMaterial, embedded_list_2) == 0x70, "nummLineMaterial::embedded_list_2");
static_assert(offsetof(nummLineMaterial, _pad_94) == 0x94, "nummLineMaterial::_pad_94");
static_assert(offsetof(nummLineMaterial, embedded_list_3) == 0xA0, "nummLineMaterial::embedded_list_3");
static_assert(offsetof(nummLineMaterial, _pad_C4) == 0xC4, "nummLineMaterial::_pad_C4");
static_assert(offsetof(nummLineMaterial, sub_object) == 0xC8, "nummLineMaterial::sub_object");
static_assert(offsetof(nummLineMaterial, trailing_field) == 0xD0, "nummLineMaterial::trailing_field");

/* ========================================================================
 * nummFileManager_Descriptor
 * Size: >= 0x10 (ctor calls std::_Container_base12::~_Container_base12(param_1+1)
 * then sets *param_1=0; param_1+1 = +0x08, so total >= 0x10)
 * Evidence: Descriptor::Descriptor(0x7A960)
 * Minimal struct — likely a file handle wrapper with STL container base.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct nummFileManager_Descriptor {
    /* 0x00 */ uint64_t handle_or_vtable;
    /* 0x08 */ uint64_t container_base;
} nummFileManager_Descriptor;
#pragma pack(pop)

static_assert(sizeof(nummFileManager_Descriptor) == 0x10, "nummFileManager_Descriptor size");
static_assert(offsetof(nummFileManager_Descriptor, handle_or_vtable) == 0x00, "nummFileManager_Descriptor::handle_or_vtable");
static_assert(offsetof(nummFileManager_Descriptor, container_base) == 0x08, "nummFileManager_Descriptor::container_base");

/* ========================================================================
 * Classes with < 3 methods — NOT reconstructed (listed in report):
 * nummDrawSpriteBase::TLS (2 methods)
 * nummDrawSpriteBatchContext (1 method)
 * nummDrawSpritePart (2 methods)
 * nummDrawSpritePoly (1 method)
 * nummDynamicVertexBufferSkin (2 methods)
 * nummLineManager (2 methods)
 *
 * nummFileManager: no instance state
 * Evidence: state_surface returned 0 direct field accesses across 6 seeds
 * (GetInformation 0x55C3C0, Mount 0x55C620, ~nummFileManager 0x1CD97C,
 * Descriptor::Descriptor 0x7A960, Close 0x155AB0, Seek 0x155AA0).
 * The two reported offsets (0x100, 0x140) are vtable dispatches on an inner
 * object (**(code **)(*(longlong *)*param_1 + 0x20/0x28)), not instance fields.
 * All methods are static or operate on global data; no ctor/allocator found.
 *
 * Static/singleton classes — no meaningful instance layout:
 * nummInputManager (1 method, operates on global state)
 * ======================================================================== */

#endif /* CMN74_S2_H */