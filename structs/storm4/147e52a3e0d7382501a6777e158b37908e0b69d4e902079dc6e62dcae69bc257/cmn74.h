/* cmn74.h — struct group cmn74 for build s4 (NSUNS4_release.exe, 64-bit)
 * INFERRED from static decompilation. Not CONFIRMED by runtime.
 * All offsets derived from PC x64 decompile (image base 0x140000000).
 * Own-game names only (Storm 4 / NSUNS4 sources via the decompiler cache nucc symbols).
 */
#ifndef CMN74_S4_H
#define CMN74_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nummDynamicVertexBufferBase
 * Size: unknown, >= 0x70 (no constructor/allocator size found; global singleton
 *       used by render pipeline; fields proven up to +0x68)
 * Evidence: Reset(0x9EEEE0), AllocateBuffer(0x9EE270), Lock(0x9EEAB0),
 *           Unlock(0x9EF1D0), ExpandBlock(0x9EE800), SetOffsetInfo(0x9EDCF0/0x9EEF90/0x9EF0B0)
 * Vtable: not recovered (no vtable ptr write found in any method)
 * ======================================================================== */
struct __attribute__((packed)) nummDynamicVertexBufferBase {
    /* +0x00 */ uint8_t _pad_00[0x10];                 /* UNKNOWN: no vtable or field access at +0x00..+0x0F */
    /* +0x10 */ void *block_array_begin;               /* PRES: eastl::vector begin ptr (stride 0x20 per buffer pair); Reset reads *(longlong**)(uVar2*0x20+0x10+param_1) */
    /* +0x18 */ void *block_array_end;                 /* PRES: eastl::vector end ptr; Reset loop condition uses +0x18 */
    /* +0x20 */ uint8_t _pad_20[0x10];                 /* UNKNOWN: gap (second buffer pair would be at +0x30/+0x38 when active_buffer_index=1) */
    /* +0x30 */ void *block_array_begin_1;             /* PRES: second buffer begin (when active_buffer_index=1, stride 0x20 → +0x30) */
    /* +0x38 */ void *block_array_end_1;               /* PRES: second buffer end */
    /* +0x40 */ uint8_t _pad_40[0x10];                 /* UNKNOWN: gap before counters */
    /* +0x50 */ uint32_t total_vertices;               /* SIM: Reset writes 0; AllocateBuffer accumulates vertex counts */
    /* +0x54 */ uint32_t max_vertex_size;              /* SIM: AllocateBuffer reads for alloc size comparison */
    /* +0x58 */ uint32_t active_buffer_index;          /* SIM: Reset toggles 1 - *(int*)(param_1+0x58); used as stride multiplier */
    /* +0x5c */ uint32_t block_count;                  /* SIM: Reset writes 0; AllocateBuffer increments */
    /* +0x60 */ void *lock_param;                      /* PRES: Lock stores param_2 at *(undefined8*)(param_1+0x60) */
    /* +0x68 */ void *critical_section;                /* PRES: AllocateBuffer/SetOffsetInfo call nummThreadCriticalSectionLock(param_1+0x68) */
} nummDynamicVertexBufferBase;
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_begin) == 0x10, "block_array_begin");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, _pad_00) == 0x00, "_pad_00");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_end) == 0x18, "block_array_end");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, _pad_20) == 0x20, "_pad_20");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_begin_1) == 0x30, "block_array_begin_1");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_end_1) == 0x38, "block_array_end_1");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, _pad_40) == 0x40, "_pad_40");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, total_vertices) == 0x50, "total_vertices");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, max_vertex_size) == 0x54, "max_vertex_size");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, active_buffer_index) == 0x58, "active_buffer_index");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_count) == 0x5c, "block_count");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, lock_param) == 0x60, "lock_param");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, critical_section) == 0x68, "critical_section");

/* ========================================================================
 * nummDynamicVertexBufferBase::Block
 * Size: 0x18 — ExpandBlock allocates via operator_new(0x18,0,0x10)
 * Inner buffer: 0x90 bytes allocated separately via operator_new(0x90,0,0x10)
 * Evidence: ExpandBlock(0x9EE800)
 * ======================================================================== */
struct __attribute__((packed)) nummDynamicVertexBufferBase_Block {
    /* +0x00 */ void *inner_buf;                       /* PRES: pointer to 0x90-byte mmVertexDataFlexible inner buffer; ExpandBlock stores at *puVar4 */
    /* +0x08 */ uint8_t _pad_08[0x08];                 /* UNKNOWN: zeroed in ExpandBlock (puVar1[1]=0) */
    /* +0x10 */ uint32_t vertex_count;                 /* SIM: read during Draw iteration at Block+0x10 */
    /* +0x14 */ uint32_t _pad_14;                      /* UNKNOWN: alignment padding to 0x18 */
} nummDynamicVertexBufferBase_Block;
_Static_assert(offsetof(struct nummDynamicVertexBufferBase_Block, inner_buf) == 0x00, "Block.inner_buf");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase_Block, vertex_count) == 0x10, "Block.vertex_count");
_Static_assert(sizeof(struct nummDynamicVertexBufferBase_Block) == 0x18, "Block size 0x18");

/* ========================================================================
 * nummLineMaterial
 * Size: >= 0xD8 (ctor writes param_1[0x1a] = offset 0xD0, 8 bytes → 0xD8)
 * Evidence: ctor(0x9ECA20), Initialize(0x9ECE20), Finalize(0x9ECC40)
 * Vtable: PTR_FUN_141101f88 (set in ctor: *param_1 = &PTR_FUN_141101f88)
 * ======================================================================== */
struct __attribute__((packed)) nummLineMaterial {
    /* +0x00 */ void *vtable;                          /* PRES: PTR_FUN_141101f88 set in ctor */
    /* +0x08 */ void *shader_vs;                       /* PRES: VS shader object; Initialize stores operator_new(0xf8) at param_1+8 */
    /* +0x10 */ void *shader_ps;                       /* PRES: PS shader object; Initialize stores operator_new(0xf8) at param_1+0x10 */
    /* +0x18 */ void *shader_pass;                     /* PRES: additional pass shader; Initialize stores operator_new(0xf8) at param_1+0x18 */
    /* +0x20 */ void *state_block;                     /* PRES: 0x30-byte constant buffer; Finalize releases at param_1+0x20 */
    /* +0x28 */ void *render_state;                    /* PRES: 0x10-byte shared render state; Initialize stores at param_1+0x28 */
    /* +0x30 */ uint32_t material_flags;               /* SIM: ctor sets *(undefined4*)(param_1+6)=7 → offset 0x30 */
    /* +0x34 */ uint8_t _pad_34[0x0C];                 /* UNKNOWN: padding to +0x40 */
    /* +0x40 */ uint8_t embedded_list_1[0x24];         /* PRES: eastl::list-like sentinel; ctor self-ref init at param_1+8 (=+0x40) */
    /* +0x64 */ uint8_t _pad_64[0x0C];                 /* UNKNOWN: padding to +0x70 */
    /* +0x70 */ uint8_t embedded_list_2[0x24];         /* PRES: eastl::list-like sentinel; ctor self-ref init at param_1+0xe (=+0x70) */
    /* +0x94 */ uint8_t _pad_94[0x0C];                 /* UNKNOWN: padding to +0xA0 */
    /* +0xA0 */ uint8_t embedded_list_3[0x24];         /* PRES: eastl::list-like sentinel; ctor self-ref init at param_1+0x14 (=+0xA0) */
    /* +0xC4 */ uint8_t _pad_C4[0x04];                 /* UNKNOWN: padding to +0xC8 */
    /* +0xC8 */ uint8_t sub_object[0x08];              /* PRES: mmMutex-initialized sub-object; ctor calls FUN_14017d1d0(param_1+0x19) → +0xC8 */
    /* +0xD0 */ uint64_t trailing_field;               /* UNKNOWN: ctor sets param_1[0x1a]=0 → offset 0xD0; last write before size ≥0xD8 */
} nummLineMaterial;
_Static_assert(offsetof(struct nummLineMaterial, vtable) == 0x00, "LineMaterial.vtable");
_Static_assert(offsetof(struct nummLineMaterial, shader_vs) == 0x08, "LineMaterial.shader_vs");
_Static_assert(offsetof(struct nummLineMaterial, shader_ps) == 0x10, "LineMaterial.shader_ps");
_Static_assert(offsetof(struct nummLineMaterial, shader_pass) == 0x18, "LineMaterial.shader_pass");
_Static_assert(offsetof(struct nummLineMaterial, state_block) == 0x20, "LineMaterial.state_block");
_Static_assert(offsetof(struct nummLineMaterial, render_state) == 0x28, "LineMaterial.render_state");
_Static_assert(offsetof(struct nummLineMaterial, material_flags) == 0x30, "LineMaterial.material_flags");
_Static_assert(offsetof(struct nummLineMaterial, _pad_34) == 0x34, "_pad_34");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_1) == 0x40, "LineMaterial.embedded_list_1");
_Static_assert(offsetof(struct nummLineMaterial, _pad_64) == 0x64, "_pad_64");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_2) == 0x70, "LineMaterial.embedded_list_2");
_Static_assert(offsetof(struct nummLineMaterial, _pad_94) == 0x94, "_pad_94");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_3) == 0xA0, "LineMaterial.embedded_list_3");
_Static_assert(offsetof(struct nummLineMaterial, _pad_C4) == 0xC4, "_pad_C4");
_Static_assert(offsetof(struct nummLineMaterial, sub_object) == 0xC8, "LineMaterial.sub_object");
_Static_assert(offsetof(struct nummLineMaterial, trailing_field) == 0xD0, "LineMaterial.trailing_field");

/* ========================================================================
 * nummFileManager::Descriptor
 * Size: 0x10 — ctor calls FUN_140062060(param_1+1) then sets *param_1=0;
 *       param_1+1 = +0x08, so total = 0x10
 * Evidence: Descriptor::Descriptor(0x7AFE0)
 * Minimal struct — file handle wrapper with STL container base.
 * ======================================================================== */
struct __attribute__((packed)) nummFileManager_Descriptor {
    /* +0x00 */ uint64_t handle_or_vtable;             /* UNKNOWN: set to 0 in ctor (*param_1=0) */
    /* +0x08 */ uint64_t container_base;               /* UNKNOWN: std::_Container_base12 region (FUN_140062060 called on param_1+1) */
} nummFileManager_Descriptor;
_Static_assert(offsetof(struct nummFileManager_Descriptor, handle_or_vtable) == 0x00, "Descriptor.handle");
_Static_assert(sizeof(struct nummFileManager_Descriptor) == 0x10, "Descriptor size 0x10");

/* ========================================================================
 * Classes with < 3 methods — NOT reconstructed (listed in report):
 *   nummDrawSpriteBase::TLS (2 methods)
 *   nummDrawSpriteBatchContext (1 method)
 *   nummDrawSpritePart (2 methods)
 *   nummDrawSpritePoly (1 method)
 *   nummDynamicVertexBufferSkin (2 methods)
 *   nummLineManager (2 methods)
 *
 * Static/global-dispatch classes — no meaningful instance layout:
 *   nummFileManager (5 methods, all static/global dispatch; Mount takes no this ptr)
 *   nummInputManager (1 method, operates on global state)
 * ======================================================================== */

#endif /* CMN74_S4_H */