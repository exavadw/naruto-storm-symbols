/* cmn74.h — struct group cmn74 for build s1 (NSUNS1.exe)
 * INFERRED from static decompilation. Not CONFIRMED by runtime.
 * All offsets derived from PC x64 decompile (image base 0x140000000).
 * Own-game names only (Storm 1 sources).
 */
#ifndef CMN74_S1_H
#define CMN74_S1_H

#include <stdint.h>
#include <stddef.h>

/* ========================================================================
 * nummDynamicVertexBufferBase
 * Size: unknown, >= 0x70 (no constructor/allocator found; global singleton
 *       at DAT_1408833c8 used by nummRender::WaitVSync)
 * Evidence: Reset(0x46E1B0), AllocateBuffer(0x46D540), Lock(0x46DD80),
 *           Unlock(0x46E4A0), ExpandBlock(0x46DAD0), Draw(0x46D860),
 *           SetOffsetInfo(0x46E260)
 * Vtable: not recovered (vtable ptr at +0x00 assumed)
 * ======================================================================== */
struct __attribute__((packed)) nummDynamicVertexBufferBase {
    /* +0x00 */ void *vtable;                          /* PRES: vtable pointer (assumed) */
    /* +0x08 */ uint8_t _pad_08[0x08];                 /* UNKNOWN: gap before block arrays */
    /* +0x10 */ void *block_array_begin[2];            /* PRES: eastl::vector begin ptrs, stride 0x20 per buffer pair */
    /* +0x20 */ void *block_array_end_unused;           /* PRES: inferred end ptr slot (stride alignment) */
    /* +0x28 */ uint8_t _pad_28[0x08];                 /* UNKNOWN: gap */
    /* +0x30 */ void *block_array_begin_1;              /* PRES: second buffer begin (inferred from +0x10 stride 0x20) */
    /* +0x38 */ void *block_array_end_1;                /* PRES: second buffer end (inferred) */
    /* +0x40 */ uint8_t _pad_40[0x10];                 /* UNKNOWN: gap before counters */
    /* +0x50 */ uint32_t total_vertices;               /* SIM: vertex count across all blocks */
    /* +0x54 */ uint32_t max_vertex_size;              /* SIM: max vertex size for allocation */
    /* +0x58 */ uint32_t active_buffer_index;          /* SIM: toggles 0/1 for double-buffering */
    /* +0x5c */ uint32_t block_count;                  /* SIM: number of allocated blocks */
    /* +0x60 */ void *lock_param;                      /* PRES: parameter passed during Lock */
    /* +0x68 */ void *cleanup_dispatch;                /* PRES: cleanup/dispatch function pointer */
};
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, vtable) == 0x00, "vtable");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_begin) == 0x10, "block_array_begin");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_begin_1) == 0x30, "block_array_begin_1");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_end_1) == 0x38, "block_array_end_1");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, total_vertices) == 0x50, "total_vertices");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, max_vertex_size) == 0x54, "max_vertex_size");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, active_buffer_index) == 0x58, "active_buffer_index");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_count) == 0x5c, "block_count");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, lock_param) == 0x60, "lock_param");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, cleanup_dispatch) == 0x68, "cleanup_dispatch");

/* ========================================================================
 * nummDynamicVertexBufferBase::Block
 * Size: 0x18 (wrapper) — ExpandBlock allocates 0x18 via FUN_1400fdd60
 * Inner buffer: 0x90 bytes allocated separately via FUN_140118910
 * Evidence: Block::Create(0x46D750), ExpandBlock(0x46DAD0), Draw(0x46D860)
 * ======================================================================== */
struct __attribute__((packed)) nummDynamicVertexBufferBase_Block {
    /* +0x00 */ void *vtable_or_inner_buf;             /* PRES: pointer to 0x90-byte inner buffer or vtable */
    /* +0x08 */ uint8_t _pad_08[0x08];                 /* UNKNOWN */
    /* +0x10 */ uint32_t vertex_count;                 /* SIM: vertices in this block (from Draw iteration) */
    /* +0x14 */ uint32_t _pad_14;                      /* UNKNOWN: alignment padding */
};
_Static_assert(offsetof(struct nummDynamicVertexBufferBase_Block, vtable_or_inner_buf) == 0x00, "Block.vtable_or_inner_buf");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase_Block, vertex_count) == 0x10, "Block.vertex_count");
_Static_assert(sizeof(struct nummDynamicVertexBufferBase_Block) == 0x18, "Block size 0x18");

/* ========================================================================
 * nummLineMaterial
 * Size: >= 0xD8 (ctor writes param_1[0x1a] = offset 0xD0, 8 bytes → 0xD8)
 * Evidence: ctor(0x46BD10), Initialize(0x46C110), Finalize(0x46BF30)
 * Vtable: PTR_FUN_140734bd0 (set in ctor)
 * ======================================================================== */
struct __attribute__((packed)) nummLineMaterial {
    /* +0x00 */ void *vtable;                          /* PRES: PTR_FUN_140734bd0 */
    /* +0x08 */ void *shader_vs;                       /* PRES: VS_3D shader object (Initialize 0xf8 alloc) */
    /* +0x10 */ void *shader_ps;                       /* PRES: pixel shader object (Initialize 0xf8 alloc) */
    /* +0x18 */ void *shader_pass;                     /* PRES: additional pass shader (Initialize 0xf8 alloc) */
    /* +0x20 */ void *state_block;                     /* PRES: 0x30-byte state block (Initialize) */
    /* +0x28 */ void *render_state;                    /* PRES: 0x10-byte render state (Initialize) */
    /* +0x30 */ uint32_t material_flags;               /* SIM: initialized to 7 in ctor */
    /* +0x34 */ uint8_t _pad_34[0x0C];                 /* UNKNOWN: padding to +0x40 */
    /* +0x40 */ uint8_t embedded_list_1[0x24];         /* PRES: eastl::list-like sentinel (ctor self-ref init) */
    /* +0x64 */ uint8_t _pad_64[0x0C];                 /* UNKNOWN: padding to +0x70 */
    /* +0x70 */ uint8_t embedded_list_2[0x24];         /* PRES: eastl::list-like sentinel */
    /* +0x94 */ uint8_t _pad_94[0x0C];                 /* UNKNOWN: padding to +0xA0 */
    /* +0xA0 */ uint8_t embedded_list_3[0x24];         /* PRES: eastl::list-like sentinel */
    /* +0xC4 */ uint8_t _pad_C4[0x04];                 /* UNKNOWN: padding to +0xC8 */
    /* +0xC8 */ uint8_t sub_object[0x08];              /* PRES: FUN_1400fec60-initialized sub-object */
    /* +0xD0 */ uint64_t trailing_field;               /* UNKNOWN: zeroed in ctor */
};
_Static_assert(offsetof(struct nummLineMaterial, vtable) == 0x00, "LineMaterial.vtable");
_Static_assert(offsetof(struct nummLineMaterial, shader_vs) == 0x08, "LineMaterial.shader_vs");
_Static_assert(offsetof(struct nummLineMaterial, shader_ps) == 0x10, "LineMaterial.shader_ps");
_Static_assert(offsetof(struct nummLineMaterial, shader_pass) == 0x18, "LineMaterial.shader_pass");
_Static_assert(offsetof(struct nummLineMaterial, state_block) == 0x20, "LineMaterial.state_block");
_Static_assert(offsetof(struct nummLineMaterial, render_state) == 0x28, "LineMaterial.render_state");
_Static_assert(offsetof(struct nummLineMaterial, material_flags) == 0x30, "LineMaterial.material_flags");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_1) == 0x40, "LineMaterial.embedded_list_1");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_2) == 0x70, "LineMaterial.embedded_list_2");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_3) == 0xA0, "LineMaterial.embedded_list_3");
_Static_assert(offsetof(struct nummLineMaterial, sub_object) == 0xC8, "LineMaterial.sub_object");
_Static_assert(offsetof(struct nummLineMaterial, trailing_field) == 0xD0, "LineMaterial.trailing_field");

/* ========================================================================
 * nummFileManager::Descriptor
 * Size: >= 0x10 (ctor calls FUN_14005dab0(param_1+1) then sets *param_1=0)
 * Evidence: Descriptor::Descriptor(0x7A960)
 * Minimal struct — likely a file handle wrapper.
 * ======================================================================== */
struct __attribute__((packed)) nummFileManager_Descriptor {
    /* +0x00 */ uint64_t handle_or_vtable;             /* UNKNOWN: set to 0 in ctor */
    /* +0x08 */ uint64_t inner_state;                  /* UNKNOWN: initialized by FUN_14005dab0 */
};
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
 * Static/singleton classes — no meaningful instance layout:
 *   nummFileManager (7 methods, all static/global dispatch)
 *   nummInputManager (4 methods, operates on global DAT_140b8e580)
 * ======================================================================== */

#endif /* CMN74_S1_H */