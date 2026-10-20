/*
 * cmn34 struct group — Build s2 (NSUNS2.exe, NARUTO STORM 2 PC)
 * Reconstructed from static decompilation only. All layouts are INFERRED.
 * Offsets derived from s2 x64 code (image base 0x140000000).
 * Names from s2 symbols/strings only (own-game naming rule).
 */

#ifndef CMN34_S2_H
#define CMN34_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmVertexSemantic
 * Tree-based semantic map. Evidence: AddSemantic 0x16C450,
 * GetSemanticSize 0x16C5E0, GetSemanticOffset 0x16C650.
 * Size unknown, >= 0x78.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x08];          /* 0x00 */
    uint64_t tree_sentinel_left;      /* 0x08 - left child / sentinel */
    uint8_t  pad_0x10[0x08];          /* 0x10 */
    uint64_t tree_root;               /* 0x18 - root pointer */
    uint8_t  pad_0x20[0x08];          /* 0x20 */
    uint32_t tree_size;               /* 0x28 - element count */
    uint8_t  pad_0x2c[0x04];          /* 0x2c */
    uint64_t semantic_ids_begin;      /* 0x30 - begin of ID array */
    uint64_t semantic_ids_end;        /* 0x38 - end of ID array */
    uint8_t  pad_0x40[0x10];          /* 0x40 */
    uint64_t semantic_types_begin;    /* 0x50 - begin of type array */
    uint64_t semantic_types_end;      /* 0x58 - end of type array */
    uint8_t  pad_0x60[0x10];          /* 0x60 */
    uint32_t semantic_count;          /* 0x70 - count of semantics */
    uint32_t semantic_size_accum;     /* 0x74 - accumulated size */
} mmVertexSemantic_s2;

static_assert(offsetof(mmVertexSemantic_s2, tree_sentinel_left) == 0x08, "mmVertexSemantic.tree_sentinel_left");
static_assert(offsetof(mmVertexSemantic_s2, tree_root) == 0x18, "mmVertexSemantic.tree_root");
static_assert(offsetof(mmVertexSemantic_s2, tree_size) == 0x28, "mmVertexSemantic.tree_size");
static_assert(offsetof(mmVertexSemantic_s2, semantic_ids_begin) == 0x30, "mmVertexSemantic.semantic_ids_begin");
static_assert(offsetof(mmVertexSemantic_s2, semantic_ids_end) == 0x38, "mmVertexSemantic.semantic_ids_end");
static_assert(offsetof(mmVertexSemantic_s2, semantic_types_begin) == 0x50, "mmVertexSemantic.semantic_types_begin");
static_assert(offsetof(mmVertexSemantic_s2, semantic_types_end) == 0x58, "mmVertexSemantic.semantic_types_end");
static_assert(offsetof(mmVertexSemantic_s2, semantic_count) == 0x70, "mmVertexSemantic.semantic_count");
static_assert(offsetof(mmVertexSemantic_s2, semantic_size_accum) == 0x74, "mmVertexSemantic.semantic_size_accum");

/* =========================================================================
 * mmVBRenderInfoList
 * Tree-based render info lookup. Evidence: Add 0x163080, Add variant 0x16CAD0,
 * iterator 0x170650.
 * Size unknown, >= 0x68.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x20];          /* 0x00 */
    uint64_t tree_sentinel;           /* 0x20 - sentinel node */
    uint8_t  pad_0x28[0x10];          /* 0x28 */
    uint64_t tree_root;               /* 0x38 - root pointer */
    uint64_t tree_right;              /* 0x40 - right child */
    uint64_t render_info_data;        /* 0x48 - data passed to add callback */
    uint8_t  pad_0x50[0x18];          /* 0x50 */
    uint32_t field_0x68;              /* 0x68 - accessed in iterator */
} mmVBRenderInfoList_s2;

static_assert(offsetof(mmVBRenderInfoList_s2, tree_sentinel) == 0x20, "mmVBRenderInfoList.tree_sentinel");
static_assert(offsetof(mmVBRenderInfoList_s2, tree_root) == 0x38, "mmVBRenderInfoList.tree_root");
static_assert(offsetof(mmVBRenderInfoList_s2, tree_right) == 0x40, "mmVBRenderInfoList.tree_right");
static_assert(offsetof(mmVBRenderInfoList_s2, render_info_data) == 0x48, "mmVBRenderInfoList.render_info_data");
static_assert(offsetof(mmVBRenderInfoList_s2, field_0x68) == 0x68, "mmVBRenderInfoList.field_0x68");

/* =========================================================================
 * mmVertexDataFlexible
 * Flexible vertex buffer with dynamic offset info linked list.
 * Evidence: CreateData 0x16CD40, CreateData w/shadow 0x16CFD0,
 * SetOffsetInfo 0x16D090/0x16D1F0.
 * Vtable: PTR_FUN_14088d888 at offset 0x00.
 * Size unknown, >= 0x90.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;                  /* 0x00 - PTR_FUN_14088d888 */
    uint64_t field_0x08;              /* 0x08 - zeroed in ctor */
    uint32_t field_0x10;              /* 0x10 - zeroed in ctor */
    uint8_t  pad_0x14[0x04];          /* 0x14 */
    uint64_t allocator_ptr;           /* 0x18 - zeroed in ctor */
    uint64_t field_0x20;              /* 0x20 - zeroed in ctor */
    uint64_t field_0x28;              /* 0x28 - zeroed in ctor */
    void    *data_buffer;             /* 0x30 - allocated buffer ptr [6] */
    void    *data_buffer_end;         /* 0x38 - buffer end [7] */
    uint64_t field_0x40;              /* 0x40 - zeroed after alloc [8] */
    uint64_t capacity;                /* 0x48 - aligned size [9] */
    uint64_t alignment;               /* 0x50 - always 0x10 [10] */
    uint64_t field_0x58;              /* 0x58 - zeroed [0xb] */
    uint64_t offset_info_list_head;   /* 0x60 - head of offset info list */
    uint64_t offset_info_list_tail;   /* 0x68 - tail of offset info list */
    uint64_t field_0x70;              /* 0x70 - zeroed [0xe] */
    uint64_t field_0x78;              /* 0x78 - PTR_LAB_1408cfae8 pattern */
    uint64_t field_0x80;              /* 0x80 - zeroed [0x10] */
    void    *shadow_copy;             /* 0x88 - optional shadow buffer [0x11] */
} mmVertexDataFlexible_s2;

static_assert(offsetof(mmVertexDataFlexible_s2, vtable) == 0x00, "mmVertexDataFlexible.vtable");
static_assert(offsetof(mmVertexDataFlexible_s2, field_0x08) == 0x08, "mmVertexDataFlexible.field_0x08");
static_assert(offsetof(mmVertexDataFlexible_s2, field_0x10) == 0x10, "mmVertexDataFlexible.field_0x10");
static_assert(offsetof(mmVertexDataFlexible_s2, allocator_ptr) == 0x18, "mmVertexDataFlexible.allocator_ptr");
static_assert(offsetof(mmVertexDataFlexible_s2, data_buffer) == 0x30, "mmVertexDataFlexible.data_buffer");
static_assert(offsetof(mmVertexDataFlexible_s2, data_buffer_end) == 0x38, "mmVertexDataFlexible.data_buffer_end");
static_assert(offsetof(mmVertexDataFlexible_s2, capacity) == 0x48, "mmVertexDataFlexible.capacity");
static_assert(offsetof(mmVertexDataFlexible_s2, alignment) == 0x50, "mmVertexDataFlexible.alignment");
static_assert(offsetof(mmVertexDataFlexible_s2, offset_info_list_head) == 0x60, "mmVertexDataFlexible.offset_info_list_head");
static_assert(offsetof(mmVertexDataFlexible_s2, offset_info_list_tail) == 0x68, "mmVertexDataFlexible.offset_info_list_tail");
static_assert(offsetof(mmVertexDataFlexible_s2, shadow_copy) == 0x88, "mmVertexDataFlexible.shadow_copy");

/* =========================================================================
 * mmVertexDataBase
 * Base class with multiple embedded sub-objects (linked lists, allocators).
 * Evidence: ctor 0x163EE0, ReleaseBase 0x165440.
 * Vtable: PTR_FUN_1408cf4e0 at offset 0x00.
 * Size unknown, >= 0x138.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;                  /* 0x00 - PTR_FUN_1408cf4e0 */
    uint16_t flags;                   /* 0x08 - low bits */
    uint8_t  pad_0x0a[0x04];          /* 0x0a */
    uint32_t refcount_or_flags;       /* 0x0e - sub-object at param_1+6 */
    uint8_t  pad_0x12[0x06];          /* 0x12 */
    uint64_t field_0x18;              /* 0x18 - zeroed [3] */
    uint64_t field_0x20;              /* 0x20 - zeroed [4] */
    uint64_t field_0x28;              /* 0x28 - zeroed [5] */
    uint64_t allocator_vtable;        /* 0x30 - dispatch via *(param_1+0x30)+0x10 */
    uint8_t  pad_0x38[0x08];          /* 0x38 */
    uint64_t list_node_0x40;          /* 0x40 - self-linked list node [8] */
    uint64_t list_node_0x48;          /* 0x48 - [9] */
    uint64_t list_node_0x50;          /* 0x50 - [10] */
    uint32_t field_0x58;              /* 0x58 - zeroed [0xb] */
    uint8_t  pad_0x5c[0x04];          /* 0x5c */
    uint64_t sub_list_a_head;         /* 0x60 - PTR_LAB_1408cfae8 sentinel */
    uint64_t sub_list_a_tail;         /* 0x68 - zeroed [0xd] */
    uint8_t  pad_0x70[0x08];          /* 0x70 */
    uint64_t sub_list_b_prev;         /* 0x78 - zeroed [0xf] */
    uint64_t sub_list_b_next;         /* 0x80 - self-link [0x10] */
    uint64_t sub_list_b_sentinel;     /* 0x88 - PTR_LAB_1408cfae8 */
    uint64_t field_0x90;              /* 0x90 - zeroed [0x12] */
    uint8_t  pad_0x98[0x10];          /* 0x98 */
    uint64_t sub_list_c_head;         /* 0xa8 - self-link ptr [0x15] */
    uint64_t sub_list_c_tail;         /* 0xb0 - zeroed [0x16] */
    uint64_t sub_list_c_sentinel;     /* 0xb8 - zeroed [0x17] */
    uint8_t  pad_0xc0[0x08];          /* 0xc0 */
    uint64_t sub_list_d_prev;         /* 0xc8 - PTR_LAB_1408cfae8 */
    uint64_t sub_list_d_next;         /* 0xd0 - copies 0x12 */
    uint64_t field_0xd8;              /* 0xd8 - zeroed [0x1b] */
    uint8_t  pad_0xe0[0x08];          /* 0xe0 */
    uint64_t sub_list_e_sentinel;     /* 0xe8 - PTR_LAB_1408cfae8 */
    uint64_t field_0xf0;              /* 0xf0 - zeroed [0x1e] */
    uint8_t  pad_0xf8[0x10];          /* 0xf8 */
    uint64_t field_0x108;             /* 0x108 - zeroed [0x21] */
    uint64_t field_0x110;             /* 0x110 - zeroed [0x22] */
    uint64_t field_0x118;             /* 0x118 - zeroed [0x23] */
    uint8_t  pad_0x120[0x08];         /* 0x120 */
    uint64_t sub_list_f_sentinel;     /* 0x128 - PTR_LAB_1408cfae8 */
    uint64_t field_0x130;             /* 0x130 - zeroed [0x26] */
} mmVertexDataBase_s2;

static_assert(offsetof(mmVertexDataBase_s2, vtable) == 0x00, "mmVertexDataBase.vtable");
static_assert(offsetof(mmVertexDataBase_s2, flags) == 0x08, "mmVertexDataBase.flags");
static_assert(offsetof(mmVertexDataBase_s2, refcount_or_flags) == 0x0e, "mmVertexDataBase.refcount_or_flags");
static_assert(offsetof(mmVertexDataBase_s2, allocator_vtable) == 0x30, "mmVertexDataBase.allocator_vtable");
static_assert(offsetof(mmVertexDataBase_s2, list_node_0x40) == 0x40, "mmVertexDataBase.list_node_0x40");
static_assert(offsetof(mmVertexDataBase_s2, sub_list_a_head) == 0x60, "mmVertexDataBase.sub_list_a_head");
static_assert(offsetof(mmVertexDataBase_s2, sub_list_b_next) == 0x80, "mmVertexDataBase.sub_list_b_next");
static_assert(offsetof(mmVertexDataBase_s2, sub_list_c_head) == 0xa8, "mmVertexDataBase.sub_list_c_head");
static_assert(offsetof(mmVertexDataBase_s2, sub_list_d_prev) == 0xc8, "mmVertexDataBase.sub_list_d_prev");
static_assert(offsetof(mmVertexDataBase_s2, sub_list_e_sentinel) == 0xe8, "mmVertexDataBase.sub_list_e_sentinel");
static_assert(offsetof(mmVertexDataBase_s2, sub_list_f_sentinel) == 0x128, "mmVertexDataBase.sub_list_f_sentinel");
static_assert(offsetof(mmVertexDataBase_s2, field_0x130) == 0x130, "mmVertexDataBase.field_0x130");

/* =========================================================================
 * mmVertexData
 * Concrete vertex data with render info tree and sub-object list.
 * Evidence: ~mmVertexData 0x170C60, CreateData 0x170CE0, Release 0x170F40.
 * Vtable: PTR_FUN_1408cfd40 at offset 0x00.
 * Size unknown, >= 0xA8.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable;                  /* 0x00 - PTR_FUN_1408cfd40 */
    void    *vertex_buffer;           /* 0x08 - freed in dtor/Release [1] */
    uint64_t field_0x10;              /* 0x10 - zeroed in dtor [2] */
    uint64_t field_0x18;              /* 0x18 - DAT_148112028 written [3] */
    uint32_t field_0x20;              /* 0x20 - part of [4] area */
    uint32_t field_0x24;              /* 0x24 - DAT_148112030 written */
    uint64_t field_0x28;              /* 0x28 - DAT_148112028 written */
    uint32_t field_0x30;              /* 0x30 - copied from sub-obj 0x38 */
    uint32_t field_0x34;              /* 0x34 - copied from sub-obj 0x3c */
    uint64_t render_info_tree_base;   /* 0x38 - tree sentinel for render info */
    uint64_t render_info_tree_right;  /* 0x40 - right child */
    uint64_t render_info_tree_root;   /* 0x48 - root ptr [9] */
    uint8_t  field_0x50;              /* 0x50 - byte flag zeroed in Release */
    uint8_t  pad_0x51[0x07];          /* 0x51 */
    uint32_t field_0x58;              /* 0x58 - zeroed in Release */
    uint8_t  pad_0x5c[0x04];          /* 0x5c */
    uint64_t sub_obj_0x60;            /* 0x60 - FUN_14016cad0 target */
    uint64_t sub_list_sentinel;       /* 0x68 - self-linked list sentinel */
    uint64_t sub_list_head;           /* 0x70 - list head ptr */
    uint64_t sub_list_nodes;          /* 0x78 - linked list walked in Release */
    uint64_t sub_obj_0x80;            /* 0x80 - FUN_140170550 target */
    uint64_t sub_list_walk;           /* 0x88 - linked list walked in Release */
    uint8_t  field_0x90;              /* 0x90 - byte flag zeroed in Release */
    uint8_t  pad_0x91[0x07];          /* 0x91 */
    uint32_t field_0x98;              /* 0x98 - zeroed in Release */
    uint8_t  pad_0x9c[0x04];          /* 0x9c */
    uint64_t allocator_vtable;        /* 0xa0 - vtable for node allocator */
} mmVertexData_s2;

static_assert(offsetof(mmVertexData_s2, vtable) == 0x00, "mmVertexData.vtable");
static_assert(offsetof(mmVertexData_s2, vertex_buffer) == 0x08, "mmVertexData.vertex_buffer");
static_assert(offsetof(mmVertexData_s2, field_0x10) == 0x10, "mmVertexData.field_0x10");
static_assert(offsetof(mmVertexData_s2, field_0x18) == 0x18, "mmVertexData.field_0x18");
static_assert(offsetof(mmVertexData_s2, field_0x20) == 0x20, "mmVertexData.field_0x20");
static_assert(offsetof(mmVertexData_s2, field_0x24) == 0x24, "mmVertexData.field_0x24");
static_assert(offsetof(mmVertexData_s2, field_0x28) == 0x28, "mmVertexData.field_0x28");
static_assert(offsetof(mmVertexData_s2, field_0x30) == 0x30, "mmVertexData.field_0x30");
static_assert(offsetof(mmVertexData_s2, render_info_tree_base) == 0x38, "mmVertexData.render_info_tree_base");
static_assert(offsetof(mmVertexData_s2, render_info_tree_root) == 0x48, "mmVertexData.render_info_tree_root");
static_assert(offsetof(mmVertexData_s2, field_0x50) == 0x50, "mmVertexData.field_0x50");
static_assert(offsetof(mmVertexData_s2, sub_list_sentinel) == 0x68, "mmVertexData.sub_list_sentinel");
static_assert(offsetof(mmVertexData_s2, sub_list_nodes) == 0x78, "mmVertexData.sub_list_nodes");
static_assert(offsetof(mmVertexData_s2, sub_list_walk) == 0x88, "mmVertexData.sub_list_walk");
static_assert(offsetof(mmVertexData_s2, allocator_vtable) == 0xa0, "mmVertexData.allocator_vtable");

/* =========================================================================
 * mmVertexDataStream
 * Streaming vertex data buffer with shadow copy support.
 * Evidence: CreateData 0x16CA80, CreateDataStream 0x179A10.
 * Size unknown, >= 0x80.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x10];          /* 0x00 */
    uint64_t sub_object;              /* 0x10 - sub-object passed to VBRenderInfoList::Add */
    uint8_t  pad_0x18[0x18];          /* 0x18 */
    uint64_t parent_or_config;        /* 0x30 - parent/config ptr read by CreateDataStream */
    uint8_t  pad_0x38[0x20];          /* 0x38 */
    uint64_t stream_array_begin;      /* 0x58 - begin of stream entry array stride 0x20 */
    uint64_t stream_array_end;        /* 0x60 - end of stream entry array */
    uint8_t  pad_0x68[0x10];          /* 0x68 */
    void    *shadow_buffer;           /* 0x78 - optional shadow copy freed in Release */
} mmVertexDataStream_s2;

static_assert(offsetof(mmVertexDataStream_s2, sub_object) == 0x10, "mmVertexDataStream.sub_object");
static_assert(offsetof(mmVertexDataStream_s2, parent_or_config) == 0x30, "mmVertexDataStream.parent_or_config");
static_assert(offsetof(mmVertexDataStream_s2, stream_array_begin) == 0x58, "mmVertexDataStream.stream_array_begin");
static_assert(offsetof(mmVertexDataStream_s2, stream_array_end) == 0x60, "mmVertexDataStream.stream_array_end");
static_assert(offsetof(mmVertexDataStream_s2, shadow_buffer) == 0x78, "mmVertexDataStream.shadow_buffer");

/* =========================================================================
 * mmVertexShader
 * Compiled vertex shader object. Large header before known fields.
 * Evidence: LoadFromCompiledFile 0x16B510/0x16B770, LoadFromCompiledMemory 0x16B660.
 * Size unknown, >= 0xF8.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0xC8];          /* 0x00 - large header */
    uint64_t debug_string_ref;        /* 0xC8 - "ShaderCompiledFromMemory.fx" context */
    uint8_t  pad_0xD0[0x20];          /* 0xD0 */
    void    *compiled_shader_blob;    /* 0xF0 - compiled shader data ptr null-checked */
} mmVertexShader_s2;

static_assert(offsetof(mmVertexShader_s2, debug_string_ref) == 0xC8, "mmVertexShader.debug_string_ref");
static_assert(offsetof(mmVertexShader_s2, compiled_shader_blob) == 0xF0, "mmVertexShader.compiled_shader_blob");

/* =========================================================================
 * mmXMLSerializeReader
 * XML deserialization reader. Shares layout prefix with writer.
 * Evidence: CheckTypeID 0x15C490, LoadObject 0x15CF50.
 * Size unknown, >= 0x1D0.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable_or_base;          /* 0x00 - base/vtable ptr */
    uint64_t current_node;            /* 0x08 - advanced by +0x10 per node */
    uint64_t node_end;                /* 0x10 - bounds check */
    uint8_t  pad_0x18[0x08];          /* 0x18 */
    uint64_t data_buffer;             /* 0x20 - base data buffer pointer */
    uint8_t  pad_0x28[0x20];          /* 0x28 */
    uint32_t current_offset;          /* 0x48 - offset into data_buffer, 0xFFFFFFFF invalid */
    uint8_t  pad_0x4c[0x34];          /* 0x4c */
    uint64_t sub_object_0x80;         /* 0x80 - sub-object shared layout with writer */
    uint8_t  pad_0x88[0x130];         /* 0x88 */
    uint64_t metadata_ptr;            /* 0x1B8 - metadata/type-info pointer */
    uint64_t type_info_array;         /* 0x1C0 - type info array (reader-specific) */
    uint64_t type_info_count;         /* 0x1C8 - count of type info entries */
} mmXMLSerializeReader_s2;

static_assert(offsetof(mmXMLSerializeReader_s2, vtable_or_base) == 0x00, "mmXMLSerializeReader.vtable_or_base");
static_assert(offsetof(mmXMLSerializeReader_s2, current_node) == 0x08, "mmXMLSerializeReader.current_node");
static_assert(offsetof(mmXMLSerializeReader_s2, node_end) == 0x10, "mmXMLSerializeReader.node_end");
static_assert(offsetof(mmXMLSerializeReader_s2, data_buffer) == 0x20, "mmXMLSerializeReader.data_buffer");
static_assert(offsetof(mmXMLSerializeReader_s2, current_offset) == 0x48, "mmXMLSerializeReader.current_offset");
static_assert(offsetof(mmXMLSerializeReader_s2, sub_object_0x80) == 0x80, "mmXMLSerializeReader.sub_object_0x80");
static_assert(offsetof(mmXMLSerializeReader_s2, metadata_ptr) == 0x1B8, "mmXMLSerializeReader.metadata_ptr");
static_assert(offsetof(mmXMLSerializeReader_s2, type_info_array) == 0x1C0, "mmXMLSerializeReader.type_info_array");
static_assert(offsetof(mmXMLSerializeReader_s2, type_info_count) == 0x1C8, "mmXMLSerializeReader.type_info_count");

/* =========================================================================
 * mmXMLSerializeWriter
 * XML serialization writer. Shares layout prefix with reader.
 * Evidence: SaveObject 0x15CD80.
 * Size unknown, >= 0x1C0.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint64_t vtable_or_base;          /* 0x00 - base/vtable ptr */
    uint8_t  pad_0x08[0x18];          /* 0x08 */
    uint64_t data_buffer;             /* 0x20 - base data buffer pointer */
    uint8_t  pad_0x28[0x20];          /* 0x28 */
    uint32_t current_offset;          /* 0x48 - offset into data_buffer, 0xFFFFFFFF invalid */
    uint8_t  pad_0x4c[0x34];          /* 0x4c */
    uint64_t output_sub_object;       /* 0x80 - output target sub-object */
    uint8_t  pad_0x88[0x130];         /* 0x88 */
    uint64_t metadata_ptr;            /* 0x1B8 - metadata/type-info pointer */
} mmXMLSerializeWriter_s2;

static_assert(offsetof(mmXMLSerializeWriter_s2, vtable_or_base) == 0x00, "mmXMLSerializeWriter.vtable_or_base");
static_assert(offsetof(mmXMLSerializeWriter_s2, data_buffer) == 0x20, "mmXMLSerializeWriter.data_buffer");
static_assert(offsetof(mmXMLSerializeWriter_s2, current_offset) == 0x48, "mmXMLSerializeWriter.current_offset");
static_assert(offsetof(mmXMLSerializeWriter_s2, output_sub_object) == 0x80, "mmXMLSerializeWriter.output_sub_object");
static_assert(offsetof(mmXMLSerializeWriter_s2, metadata_ptr) == 0x1B8, "mmXMLSerializeWriter.metadata_ptr");

#endif /* CMN34_S2_H */