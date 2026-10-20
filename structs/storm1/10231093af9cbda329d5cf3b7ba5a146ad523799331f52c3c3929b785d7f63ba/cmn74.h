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
#pragma pack(push, 1)
struct nummDynamicVertexBufferBase {
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
#pragma pack(pop)
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, vtable) == 0x00, "vtable");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, _pad_08) == 0x08, "_pad_08");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_begin) == 0x10, "block_array_begin");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_end_unused) == 0x20, "block_array_end_unused");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, _pad_28) == 0x28, "_pad_28");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_begin_1) == 0x30, "block_array_begin_1");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, block_array_end_1) == 0x38, "block_array_end_1");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase, _pad_40) == 0x40, "_pad_40");
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
#pragma pack(push, 1)
struct nummDynamicVertexBufferBase_Block {
    /* +0x00 */ void *vtable_or_inner_buf;             /* PRES: pointer to 0x90-byte inner buffer or vtable */
    /* +0x08 */ uint8_t _pad_08[0x08];                 /* UNKNOWN */
    /* +0x10 */ uint32_t vertex_count;                 /* SIM: vertices in this block (from Draw iteration) */
    /* +0x14 */ uint32_t _pad_14;                      /* UNKNOWN: alignment padding */
};
#pragma pack(pop)
_Static_assert(offsetof(struct nummDynamicVertexBufferBase_Block, vtable_or_inner_buf) == 0x00, "Block.vtable_or_inner_buf");
_Static_assert(offsetof(struct nummDynamicVertexBufferBase_Block, vertex_count) == 0x10, "Block.vertex_count");
_Static_assert(sizeof(struct nummDynamicVertexBufferBase_Block) == 0x18, "Block size 0x18");

/* ========================================================================
 * nummLineMaterial
 * Size: >= 0xD8 (ctor writes param_1[0x1a] = offset 0xD0, 8 bytes → 0xD8)
 * Evidence: ctor(0x46BD10), Initialize(0x46C110), Finalize(0x46BF30)
 * Vtable: PTR_FUN_140734bd0 (set in ctor)
 * ======================================================================== */
#pragma pack(push, 1)
struct nummLineMaterial {
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
#pragma pack(pop)
_Static_assert(offsetof(struct nummLineMaterial, vtable) == 0x00, "LineMaterial.vtable");
_Static_assert(offsetof(struct nummLineMaterial, shader_vs) == 0x08, "LineMaterial.shader_vs");
_Static_assert(offsetof(struct nummLineMaterial, shader_ps) == 0x10, "LineMaterial.shader_ps");
_Static_assert(offsetof(struct nummLineMaterial, shader_pass) == 0x18, "LineMaterial.shader_pass");
_Static_assert(offsetof(struct nummLineMaterial, state_block) == 0x20, "LineMaterial.state_block");
_Static_assert(offsetof(struct nummLineMaterial, render_state) == 0x28, "LineMaterial.render_state");
_Static_assert(offsetof(struct nummLineMaterial, material_flags) == 0x30, "LineMaterial.material_flags");
_Static_assert(offsetof(struct nummLineMaterial, _pad_34) == 0x34, "LineMaterial._pad_34");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_1) == 0x40, "LineMaterial.embedded_list_1");
_Static_assert(offsetof(struct nummLineMaterial, _pad_64) == 0x64, "LineMaterial._pad_64");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_2) == 0x70, "LineMaterial.embedded_list_2");
_Static_assert(offsetof(struct nummLineMaterial, _pad_94) == 0x94, "LineMaterial._pad_94");
_Static_assert(offsetof(struct nummLineMaterial, embedded_list_3) == 0xA0, "LineMaterial.embedded_list_3");
_Static_assert(offsetof(struct nummLineMaterial, _pad_C4) == 0xC4, "LineMaterial._pad_C4");
_Static_assert(offsetof(struct nummLineMaterial, sub_object) == 0xC8, "LineMaterial.sub_object");
_Static_assert(offsetof(struct nummLineMaterial, trailing_field) == 0xD0, "LineMaterial.trailing_field");

/* ========================================================================
 * nummFileManager::Descriptor
 * Size: >= 0x10 (ctor calls FUN_14005dab0(param_1+1) then sets *param_1=0)
 * Evidence: Descriptor::Descriptor(0x7A960)
 * Minimal struct — likely a file handle wrapper.
 * ======================================================================== */
#pragma pack(push, 1)
struct nummFileManager_Descriptor {
    /* +0x00 */ uint64_t handle_or_vtable;             /* UNKNOWN: set to 0 in ctor */
    /* +0x08 */ uint64_t inner_state;                  /* UNKNOWN: initialized by FUN_14005dab0 */
};
#pragma pack(pop)
_Static_assert(offsetof(struct nummFileManager_Descriptor, handle_or_vtable) == 0x00, "Descriptor.handle");
_Static_assert(sizeof(struct nummFileManager_Descriptor) == 0x10, "Descriptor size 0x10");

/* ========================================================================
 * nummInputManager
 * Size: >= 0xF0 (ctor writes up to +0xE8, 4 bytes -> 0xEC; padded to 0xF0)
 * Full dtor chain (0x3063E0->0x306108->0x159C24) destroys sub-objects
 * up to +0x1D0, so runtime size >= 0x1D8.
 * Vtable: DAT_140b8d0a0 (set in ctor 0x11AD60); dtors overwrite with
 * PTR_FUN_1406c8bb8 / PTR_FUN_1406c8bf8 during teardown.
 * Evidence: mmAllocatorBase::Construct<nummInputManager>(0x11AD60),
 * ~nummInputManager(0x159C24, 0x306108, 0x3063E0)
 * Layout: 3 header pointers + 5 repeating sub-object groups of stride 0x28
 * starting at +0x18. Sub-obj 0 has unique vtable/func ptrs at +0x18/+0x20.
 * Each group: {ptr(+0x00), uint64=1(+0x08 from group base after gap),
 * float32=1.0(+0x10), uint64(+0x14), uint32=0(+0x1C)}
 * ======================================================================== */
#pragma pack(push, 1)
struct nummInputManager {
    /* +0x00 */ void *vtable;               /* PRES: DAT_140b8d0a0 in ctor */
    /* +0x08 */ void *field_0x08;           /* UNKNOWN: DAT_140b8d0a0 in ctor */
    /* +0x10 */ void *field_0x10;           /* UNKNOWN: DAT_140b8d0a1 in ctor */
    /* --- sub-object 0 @ +0x18 (unique vtable/func) --- */
    /* +0x18 */ void *sub0_vtable_or_ptr;   /* PRES: PTR_LAB_1407755c0 */
    /* +0x20 */ void *sub0_func_or_ptr;     /* PRES: PTR_FUN_140773df8 */
    /* +0x28 */ uint8_t _pad_28[0x08];      /* UNKNOWN: gap before shared fields */
    /* +0x30 */ void *sub0_data_ptr;        /* PRES: DAT_14085ce10 */
    /* +0x38 */ uint64_t sub0_flag;         /* SIM: initialized to 1 */
    /* +0x40 */ float sub0_float_val;       /* SIM: 1.0f (0x3f800000) */
    /* +0x44 */ uint32_t _pad_44;           /* UNKNOWN: upper half of 0x40000000 write */
    /* +0x48 */ uint32_t sub0_zero;         /* SIM: initialized to 0 */
    /* +0x4C */ uint8_t _pad_4c[0x04];      /* UNKNOWN: alignment to next group */
    /* --- sub-object 1 @ +0x50 --- */
    /* +0x50 */ uint8_t _pad_50[0x08];      /* UNKNOWN: gap (no ctor write at +0x50) */
    /* +0x58 */ void *sub1_data_ptr;        /* PRES: DAT_14085ce10 */
    /* +0x60 */ uint64_t sub1_flag;         /* SIM: initialized to 1 */
    /* +0x68 */ float sub1_float_val;       /* SIM: 1.0f */
    /* +0x6C */ uint32_t _pad_6c;           /* UNKNOWN: upper half of 0x40000000 write */
    /* +0x70 */ uint32_t sub1_zero;         /* SIM: initialized to 0 */
    /* +0x74 */ uint8_t _pad_74[0x0C];      /* UNKNOWN: gap to next group */
    /* --- sub-object 2 @ +0x80 --- */
    /* +0x80 */ void *sub2_data_ptr;        /* PRES: DAT_14085ce10 */
    /* +0x88 */ uint64_t sub2_flag;         /* SIM: initialized to 1 */
    /* +0x90 */ float sub2_float_val;       /* SIM: 1.0f */
    /* +0x94 */ uint32_t _pad_94;           /* UNKNOWN: upper half of 0x40000000 write */
    /* +0x98 */ uint32_t sub2_zero;         /* SIM: initialized to 0 */
    /* +0x9C */ uint8_t _pad_9c[0x0C];      /* UNKNOWN: gap to next group */
    /* --- sub-object 3 @ +0xA8 --- */
    /* +0xA8 */ void *sub3_data_ptr;        /* PRES: DAT_14085ce10 */
    /* +0xB0 */ uint64_t sub3_flag;         /* SIM: initialized to 1 */
    /* +0xB8 */ float sub3_float_val;       /* SIM: 1.0f */
    /* +0xBC */ uint32_t _pad_bc;           /* UNKNOWN: upper half of 0x40000000 write */
    /* +0xC0 */ uint32_t sub3_zero;         /* SIM: initialized to 0 */
    /* +0xC4 */ uint8_t _pad_c4[0x0C];      /* UNKNOWN: gap to next group */
    /* --- sub-object 4 @ +0xD0 --- */
    /* +0xD0 */ void *sub4_data_ptr;        /* PRES: DAT_14085ce10 */
    /* +0xD8 */ uint64_t sub4_flag;         /* SIM: initialized to 1 */
    /* +0xE0 */ float sub4_float_val;       /* SIM: 1.0f */
    /* +0xE4 */ uint32_t _pad_e4;           /* UNKNOWN: upper half of 0x40000000 write */
    /* +0xE8 */ uint32_t sub4_zero;         /* SIM: initialized to 0 */
    /* +0xEC */ uint8_t _pad_ec[0x04];      /* UNKNOWN: end of ctor-proven region */
};
#pragma pack(pop)
_Static_assert(offsetof(struct nummInputManager, vtable) == 0x00, "InputManager.vtable");
_Static_assert(offsetof(struct nummInputManager, field_0x08) == 0x08, "InputManager.field_0x08");
_Static_assert(offsetof(struct nummInputManager, field_0x10) == 0x10, "InputManager.field_0x10");
_Static_assert(offsetof(struct nummInputManager, sub0_vtable_or_ptr) == 0x18, "InputManager.sub0_vtable_or_ptr");
_Static_assert(offsetof(struct nummInputManager, sub0_func_or_ptr) == 0x20, "InputManager.sub0_func_or_ptr");
_Static_assert(offsetof(struct nummInputManager, _pad_28) == 0x28, "InputManager._pad_28");
_Static_assert(offsetof(struct nummInputManager, sub0_data_ptr) == 0x30, "InputManager.sub0_data_ptr");
_Static_assert(offsetof(struct nummInputManager, sub0_flag) == 0x38, "InputManager.sub0_flag");
_Static_assert(offsetof(struct nummInputManager, sub0_float_val) == 0x40, "InputManager.sub0_float_val");
_Static_assert(offsetof(struct nummInputManager, _pad_44) == 0x44, "InputManager._pad_44");
_Static_assert(offsetof(struct nummInputManager, sub0_zero) == 0x48, "InputManager.sub0_zero");
_Static_assert(offsetof(struct nummInputManager, _pad_4c) == 0x4c, "InputManager._pad_4c");
_Static_assert(offsetof(struct nummInputManager, _pad_50) == 0x50, "InputManager._pad_50");
_Static_assert(offsetof(struct nummInputManager, sub1_data_ptr) == 0x58, "InputManager.sub1_data_ptr");
_Static_assert(offsetof(struct nummInputManager, sub1_flag) == 0x60, "InputManager.sub1_flag");
_Static_assert(offsetof(struct nummInputManager, sub1_float_val) == 0x68, "InputManager.sub1_float_val");
_Static_assert(offsetof(struct nummInputManager, _pad_6c) == 0x6c, "InputManager._pad_6c");
_Static_assert(offsetof(struct nummInputManager, sub1_zero) == 0x70, "InputManager.sub1_zero");
_Static_assert(offsetof(struct nummInputManager, _pad_74) == 0x74, "InputManager._pad_74");
_Static_assert(offsetof(struct nummInputManager, sub2_data_ptr) == 0x80, "InputManager.sub2_data_ptr");
_Static_assert(offsetof(struct nummInputManager, sub2_flag) == 0x88, "InputManager.sub2_flag");
_Static_assert(offsetof(struct nummInputManager, sub2_float_val) == 0x90, "InputManager.sub2_float_val");
_Static_assert(offsetof(struct nummInputManager, _pad_94) == 0x94, "InputManager._pad_94");
_Static_assert(offsetof(struct nummInputManager, sub2_zero) == 0x98, "InputManager.sub2_zero");
_Static_assert(offsetof(struct nummInputManager, _pad_9c) == 0x9c, "InputManager._pad_9c");
_Static_assert(offsetof(struct nummInputManager, sub3_data_ptr) == 0xA8, "InputManager.sub3_data_ptr");
_Static_assert(offsetof(struct nummInputManager, sub3_flag) == 0xB0, "InputManager.sub3_flag");
_Static_assert(offsetof(struct nummInputManager, sub3_float_val) == 0xB8, "InputManager.sub3_float_val");
_Static_assert(offsetof(struct nummInputManager, _pad_bc) == 0xbc, "InputManager._pad_bc");
_Static_assert(offsetof(struct nummInputManager, sub3_zero) == 0xC0, "InputManager.sub3_zero");
_Static_assert(offsetof(struct nummInputManager, _pad_c4) == 0xc4, "InputManager._pad_c4");
_Static_assert(offsetof(struct nummInputManager, sub4_data_ptr) == 0xD0, "InputManager.sub4_data_ptr");
_Static_assert(offsetof(struct nummInputManager, sub4_flag) == 0xD8, "InputManager.sub4_flag");
_Static_assert(offsetof(struct nummInputManager, sub4_float_val) == 0xE0, "InputManager.sub4_float_val");
_Static_assert(offsetof(struct nummInputManager, _pad_e4) == 0xe4, "InputManager._pad_e4");
_Static_assert(offsetof(struct nummInputManager, sub4_zero) == 0xE8, "InputManager.sub4_zero");
_Static_assert(offsetof(struct nummInputManager, _pad_ec) == 0xec, "InputManager._pad_ec");

/* ========================================================================
 * nummFileManager: no instance state
 * All methods dispatch through vtable of a Descriptor/handle object passed
 * as param_1. Write(0x102860), Read(0x1028B0), Seek(0x102870), Close(0x102880)
 * each perform (**(code **)(*(longlong *)*param_1 + offset))() -- pure vtable
 * dispatch on the pointed-to object, not on a nummFileManager instance.
 * Mount(0x5E9270) and GetInformation(0x5E9010) are static/global dispatchers.
 * No constructor or allocation site found for a nummFileManager object.
 * ======================================================================== */

/* ========================================================================
 * Classes with < 3 methods -- NOT reconstructed (listed in report):
 *   nummDrawSpriteBase::TLS (2 methods)
 *   nummDrawSpriteBatchContext (1 method)
 *   nummDrawSpritePart (2 methods)
 *   nummDrawSpritePoly (1 method)
 *   nummDynamicVertexBufferSkin (2 methods)
 *   nummLineManager (2 methods)
 * ======================================================================== */

/* Revision: 2026-10-19T23:06 — pathspec-clean recommit */
#endif /* CMN74_S1_H */