/* cmn34.h — Common engine struct group for NSUNS1 (build s1)
 * INFERRED from static decompilation of NSUNS1.exe (sha 10231093af9c).
 * All offsets derived from PC x64 code (image base 0x140000000).
 * Field names from Switch Trilogy ns1:: symbols via storm_map where available;
 * unnamed fields use descriptive placeholders.
 * Tag legend: SIM = simulation state, PRES = presentation/render-only, UNKNOWN = unclear purpose.
 */
#ifndef CMN34_H
#define CMN34_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations */
typedef struct mmVertexSemantic mmVertexSemantic;
typedef struct mmVBRenderInfoList mmVBRenderInfoList;
typedef struct mmVertexDataFlexible mmVertexDataFlexible;
typedef struct mmVertexDataBase mmVertexDataBase;
typedef struct mmVertexData mmVertexData;
typedef struct mmVertexDataStream mmVertexDataStream;
typedef struct mmVertexShader mmVertexShader;
typedef struct mmXMLSerializeReader mmXMLSerializeReader;
typedef struct mmXMLSerializeWriter mmXMLSerializeWriter;

/* ========================================================================
 * mmVertexSemantic — vertex attribute semantic map (tree-based)
 * Size unknown, >= 0x58. Vtable not found in this build's methods.
 * Layout inferred from AddSemantic (0x118020), GetSemanticSize (0x1181B0),
 * GetSemanticOffset (0x118220).
 * ======================================================================== */
struct __attribute__((packed)) mmVertexSemantic {
    uint8_t _pad_0x00[8];             /* 0x00: unknown / possible vtable or parent ptr */
    uint64_t tree_sentinel_left;      /* 0x08: left child / sentinel (param_1 + 8) */
    uint8_t _pad_0x10[8];             /* 0x10: padding */
    uint64_t tree_root;               /* 0x18: tree root pointer (param_1 + 0x18) */
    uint8_t _pad_0x20[8];             /* 0x20: padding */
    uint32_t tree_size;               /* 0x28: element count threshold (< 0x10 inline) */
    uint8_t _pad_0x2C[4];             /* 0x2C: padding */
    uint64_t semantic_ids_begin;      /* 0x30: begin of semantic ID array */
    uint64_t semantic_ids_end;        /* 0x38: end of semantic ID array */
    uint8_t _pad_0x40[0x10];          /* 0x40: padding */
    uint64_t semantic_sizes;          /* 0x50: pointer to size table (DAT_14076ebb0 indexed) */
};
static_assert(offsetof(mmVertexSemantic, tree_sentinel_left) == 0x08, "mmVertexSemantic.tree_sentinel_left");
static_assert(offsetof(mmVertexSemantic, tree_root) == 0x18, "mmVertexSemantic.tree_root");
static_assert(offsetof(mmVertexSemantic, tree_size) == 0x28, "mmVertexSemantic.tree_size");
static_assert(offsetof(mmVertexSemantic, semantic_ids_begin) == 0x30, "mmVertexSemantic.semantic_ids_begin");
static_assert(offsetof(mmVertexSemantic, semantic_ids_end) == 0x38, "mmVertexSemantic.semantic_ids_end");
static_assert(offsetof(mmVertexSemantic, semantic_sizes) == 0x50, "mmVertexSemantic.semantic_sizes");

/* ========================================================================
 * mmVBRenderInfoList — render info list with tree-based lookup
 * Size unknown, >= 0x48. Vtable not directly set in observed methods.
 * Layout from Add variants (0x10F480, 0x1186A0, 0x11C220).
 * ======================================================================== */
struct __attribute__((packed)) mmVBRenderInfoList {
    uint8_t _pad_0x00[0x20];          /* 0x00: unknown header */
    uint64_t tree_sentinel;           /* 0x20: tree sentinel node (param_1 + 0x20) */
    uint64_t tree_right;              /* 0x28: right child pointer */
    uint64_t tree_root;               /* 0x30: tree root (null-checked) */
    uint8_t _pad_0x38[8];             /* 0x38: padding */
    uint64_t render_info_data;        /* 0x40: passed to FUN_14010ff60 */
};
static_assert(offsetof(mmVBRenderInfoList, tree_sentinel) == 0x20, "mmVBRenderInfoList.tree_sentinel");
static_assert(offsetof(mmVBRenderInfoList, tree_right) == 0x28, "mmVBRenderInfoList.tree_right");
static_assert(offsetof(mmVBRenderInfoList, tree_root) == 0x30, "mmVBRenderInfoList.tree_root");
static_assert(offsetof(mmVBRenderInfoList, render_info_data) == 0x40, "mmVBRenderInfoList.render_info_data");

/* ========================================================================
 * mmVertexDataFlexible — flexible vertex buffer with dynamic offset info
 * Size unknown, >= 0x90. Vtable: PTR_FUN_140774bf0 at offset 0x00.
 * Layout from CreateData (0x118910, 0x118BA0), SetOffsetInfo (0x118C60, 0x118DC0).
 * Inherits from mmVertexDataBase pattern but has its own vtable.
 * ======================================================================== */
struct __attribute__((packed)) mmVertexDataFlexible {
    uint64_t *vtable;                 /* 0x00: PTR_FUN_140774bf0 */
    uint64_t field_0x08;              /* 0x08: param_1[1], zeroed in ctor */
    uint32_t field_0x10;              /* 0x10: *(uint32*)(param_1+2), zeroed */
    uint8_t _pad_0x14[4];             /* 0x14: padding to 0x18 */
    uint64_t allocator_ptr;           /* 0x18: param_1[3], zeroed */
    uint64_t field_0x20;              /* 0x20: param_1[4], zeroed */
    uint64_t field_0x28;              /* 0x28: param_1[5], zeroed */
    void *data_buffer;                /* 0x30: param_1[6], allocated buffer ptr */
    void *data_buffer_end;            /* 0x38: param_1[7], buffer end */
    uint64_t field_0x40;              /* 0x40: param_1[8], zeroed after alloc */
    uint64_t capacity;                /* 0x48: param_1[9], aligned size */
    uint64_t alignment;               /* 0x50: param_1[10], always 0x10 */
    uint64_t field_0x58;              /* 0x58: param_1[0xb], zeroed */
    uint64_t offset_info_list_head;   /* 0x60: head of offset info linked list */
    uint64_t offset_info_list_tail;   /* 0x68: tail of offset info linked list */
    uint64_t field_0x70;              /* 0x70: param_1[0xe], zeroed */
    uint64_t field_0x78;              /* 0x78: param_1[0xf], PTR_LAB_1407744b8 */
    uint64_t field_0x80;              /* 0x80: param_1[0x10], zeroed */
    void *shadow_copy;                /* 0x88: param_1[0x11], optional shadow buffer */
};
static_assert(offsetof(mmVertexDataFlexible, vtable) == 0x00, "mmVertexDataFlexible.vtable");
static_assert(offsetof(mmVertexDataFlexible, field_0x08) == 0x08, "mmVertexDataFlexible.field_0x08");
static_assert(offsetof(mmVertexDataFlexible, field_0x10) == 0x10, "mmVertexDataFlexible.field_0x10");
static_assert(offsetof(mmVertexDataFlexible, allocator_ptr) == 0x18, "mmVertexDataFlexible.allocator_ptr");
static_assert(offsetof(mmVertexDataFlexible, data_buffer) == 0x30, "mmVertexDataFlexible.data_buffer");
static_assert(offsetof(mmVertexDataFlexible, data_buffer_end) == 0x38, "mmVertexDataFlexible.data_buffer_end");
static_assert(offsetof(mmVertexDataFlexible, capacity) == 0x48, "mmVertexDataFlexible.capacity");
static_assert(offsetof(mmVertexDataFlexible, alignment) == 0x50, "mmVertexDataFlexible.alignment");
static_assert(offsetof(mmVertexDataFlexible, offset_info_list_head) == 0x60, "mmVertexDataFlexible.offset_info_list_head");
static_assert(offsetof(mmVertexDataFlexible, offset_info_list_tail) == 0x68, "mmVertexDataFlexible.offset_info_list_tail");
static_assert(offsetof(mmVertexDataFlexible, shadow_copy) == 0x88, "mmVertexDataFlexible.shadow_copy");

/* ========================================================================
 * mmVertexDataBase — base class for vertex data objects
 * Size unknown, >= 0x138. Vtable: PTR_FUN_140774d68 at offset 0x00.
 * Layout from ctors (0x1102E0, 0x47A6C0), ReleaseBase (0x111840, 0x11C660).
 * Contains multiple embedded sub-objects (linked lists, allocators).
 * ======================================================================== */
struct __attribute__((packed)) mmVertexDataBase {
    uint64_t *vtable;                 /* 0x00: PTR_FUN_140774d68 */
    uint16_t flags;                   /* 0x08: *(uint16*)(param_1+2 area), low bits */
    uint8_t _pad_0x0A[4];             /* 0x0A: padding to 0x0E */
    uint32_t refcount_or_flags;       /* 0x0E: sub-object at param_1+6, FUN_14011c370 */
    uint8_t _pad_0x12[6];             /* 0x12: padding to 0x18 */
    uint64_t field_0x18;              /* 0x18: param_1[3], zeroed */
    uint64_t field_0x20;              /* 0x20: param_1[4], zeroed */
    uint64_t field_0x28;              /* 0x28: param_1[5], zeroed */
    uint64_t allocator_vtable;        /* 0x30: vtable ptr for sub-allocator */
    uint64_t field_0x38;              /* 0x38: padding / sub-object continuation */
    uint64_t list_node_0x40;          /* 0x40: param_1[8], self-linked list node */
    uint64_t list_node_0x48;          /* 0x48: param_1[9] */
    uint64_t list_node_0x50;          /* 0x50: param_1[10] */
    uint32_t field_0x58;              /* 0x58: param_1[0xb], zeroed */
    uint8_t _pad_0x5C[4];             /* 0x5C: padding to 0x60 */
    uint64_t sub_list_a_head;         /* 0x60: param_1[0xc], PTR_LAB_1407744b8 sentinel */
    uint64_t sub_list_a_tail;         /* 0x68: param_1[0xd], zeroed */
    uint64_t field_0x70;              /* 0x70: padding */
    uint64_t sub_list_b_prev;         /* 0x78: param_1[0xf], zeroed */
    uint64_t sub_list_b_next;         /* 0x80: param_1[0x10], self-link */
    uint64_t sub_list_b_sentinel;     /* 0x88: param_1[0x11], PTR_LAB_1407744b8 */
    uint64_t field_0x90;              /* 0x90: param_1[0x12], zeroed */
    uint8_t _pad_0x98[0x10];          /* 0x98: padding to 0xA8 */
    uint64_t sub_list_c_head;         /* 0xA8: param_1[0x15], self-link ptr */
    uint64_t sub_list_c_tail;         /* 0xB0: param_1[0x16], zeroed */
    uint64_t sub_list_c_sentinel;     /* 0xB8: param_1[0x17], zeroed */
    uint8_t _pad_0xC0[8];             /* 0xC0: padding to 0xC8 */
    uint64_t sub_list_d_prev;         /* 0xC8: param_1[0x19], PTR_LAB_1407744b8 */
    uint64_t sub_list_d_next;         /* 0xD0: param_1[0x1a], copies 0x12 */
    uint64_t field_0xD8;              /* 0xD8: param_1[0x1b], zeroed */
    uint8_t _pad_0xE0[8];             /* 0xE0: padding to 0xE8 */
    uint64_t sub_list_e_sentinel;     /* 0xE8: param_1[0x1d], PTR_LAB_1407744b8 */
    uint64_t field_0xF0;              /* 0xF0: param_1[0x1e], zeroed */
    uint8_t _pad_0xF8[0x10];          /* 0xF8: padding to 0x108 */
    uint64_t field_0x108;             /* 0x108: param_1[0x21], zeroed */
    uint64_t field_0x110;             /* 0x110: param_1[0x22], zeroed */
    uint64_t field_0x118;             /* 0x118: param_1[0x23], zeroed */
    uint8_t _pad_0x120[8];            /* 0x120: padding to 0x128 */
    uint64_t sub_list_f_sentinel;     /* 0x128: param_1[0x25], PTR_LAB_1407744b8 */
    uint64_t field_0x130;             /* 0x130: param_1[0x26], zeroed */
};
static_assert(offsetof(mmVertexDataBase, vtable) == 0x00, "mmVertexDataBase.vtable");
static_assert(offsetof(mmVertexDataBase, flags) == 0x08, "mmVertexDataBase.flags");
static_assert(offsetof(mmVertexDataBase, refcount_or_flags) == 0x0E, "mmVertexDataBase.refcount_or_flags");
static_assert(offsetof(mmVertexDataBase, field_0x18) == 0x18, "mmVertexDataBase.field_0x18");
static_assert(offsetof(mmVertexDataBase, allocator_vtable) == 0x30, "mmVertexDataBase.allocator_vtable");
static_assert(offsetof(mmVertexDataBase, list_node_0x40) == 0x40, "mmVertexDataBase.list_node_0x40");
static_assert(offsetof(mmVertexDataBase, sub_list_a_head) == 0x60, "mmVertexDataBase.sub_list_a_head");
static_assert(offsetof(mmVertexDataBase, sub_list_c_head) == 0xA8, "mmVertexDataBase.sub_list_c_head");
static_assert(offsetof(mmVertexDataBase, sub_list_e_sentinel) == 0xE8, "mmVertexDataBase.sub_list_e_sentinel");
static_assert(offsetof(mmVertexDataBase, field_0x130) == 0x130, "mmVertexDataBase.field_0x130");

/* ========================================================================
 * mmVertexData — concrete vertex data (inherits mmVertexDataBase pattern)
 * Size unknown, >= 0xA8. Vtable: PTR_FUN_140774d68 at offset 0x00.
 * Layout from ~mmVertexData (0x11C830), CreateData (0x11C8B0), Release (0x11CB10).
 * ======================================================================== */
struct __attribute__((packed)) mmVertexData {
    uint64_t *vtable;                 /* 0x00: PTR_FUN_140774d68 */
    void *vertex_buffer;              /* 0x08: param_1[1], freed in dtor/Release */
    uint64_t field_0x10;              /* 0x10: param_1[2], zeroed in dtor */
    uint64_t field_0x18;              /* 0x18: param_1[3], DAT_140b8e4e8 in dtor */
    uint32_t field_0x20;              /* 0x20: part of param_1[4] area */
    uint64_t field_0x24;              /* 0x24: DAT_140b8e4e8 written at 0x24 in dtor */
    uint32_t field_0x2C;              /* 0x2C: DAT_140b8e4f0 written at 0x2c in dtor */
    uint8_t _pad_0x30[8];             /* 0x30: padding to 0x38 */
    uint64_t render_info_tree_base;   /* 0x38: tree sentinel for render info lookup */
    uint64_t render_info_tree_right;  /* 0x40: right child */
    uint64_t render_info_tree_root;   /* 0x48: root ptr (param_1[9]) */
    uint8_t field_0x50;               /* 0x50: byte flag, zeroed in Release */
    uint8_t _pad_0x51[7];             /* 0x51: padding to 0x58 */
    uint32_t field_0x58;              /* 0x58: zeroed in Release */
    uint8_t _pad_0x5C[4];             /* 0x5C: padding to 0x60 */
    uint64_t field_0x60;              /* 0x60: padding */
    uint64_t field_0x68;              /* 0x68: padding */
    uint64_t sub_obj_0x70;            /* 0x70: sub-object, FUN_140111840 target */
    uint64_t sub_list_sentinel;       /* 0x78: self-linked list sentinel */
    uint64_t sub_list_head;           /* 0x80: list head ptr */
    uint64_t sub_list_nodes;          /* 0x88: linked list of nodes, walked in Release */
    uint8_t field_0x90;               /* 0x90: byte flag, zeroed in Release */
    uint8_t _pad_0x91[7];             /* 0x91: padding to 0x98 */
    uint32_t field_0x98;              /* 0x98: zeroed in Release */
    uint8_t _pad_0x9C[4];             /* 0x9C: padding to 0xA0 */
    uint64_t allocator_vtable;        /* 0xA0: vtable for node allocator (**(...+0x10)) */
};
static_assert(offsetof(mmVertexData, vtable) == 0x00, "mmVertexData.vtable");
static_assert(offsetof(mmVertexData, vertex_buffer) == 0x08, "mmVertexData.vertex_buffer");
static_assert(offsetof(mmVertexData, field_0x18) == 0x18, "mmVertexData.field_0x18");
static_assert(offsetof(mmVertexData, render_info_tree_base) == 0x38, "mmVertexData.render_info_tree_base");
static_assert(offsetof(mmVertexData, render_info_tree_root) == 0x48, "mmVertexData.render_info_tree_root");
static_assert(offsetof(mmVertexData, sub_obj_0x70) == 0x70, "mmVertexData.sub_obj_0x70");
static_assert(offsetof(mmVertexData, allocator_vtable) == 0xA0, "mmVertexData.allocator_vtable");

/* ========================================================================
 * mmVertexDataStream — streaming vertex data buffer
 * Size unknown, >= 0x80. Vtable not observed in methods.
 * Layout from CreateData (0x118650), CreateDataStream (0x1255E0), Release (0x1257A0).
 * ======================================================================== */
struct __attribute__((packed)) mmVertexDataStream {
    uint8_t _pad_0x00[0x10];          /* 0x00: unknown header, sub-object at +0x10 */
    uint64_t sub_object;              /* 0x10: sub-object passed to mmVBRenderInfoList::Add */
    uint8_t _pad_0x18[0x18];          /* 0x18: padding */
    uint64_t parent_or_config;        /* 0x30: parent/config ptr (CreateDataStream reads this) */
    uint8_t _pad_0x38[0x20];          /* 0x38: padding */
    uint64_t stream_array_begin;      /* 0x58: begin of stream entry array (stride 0x20) */
    uint64_t stream_array_end;        /* 0x60: end of stream entry array */
    uint8_t _pad_0x68[0x10];          /* 0x68: padding */
    void *shadow_buffer;              /* 0x78: optional shadow copy, freed in Release */
};
static_assert(offsetof(mmVertexDataStream, sub_object) == 0x10, "mmVertexDataStream.sub_object");
static_assert(offsetof(mmVertexDataStream, parent_or_config) == 0x30, "mmVertexDataStream.parent_or_config");
static_assert(offsetof(mmVertexDataStream, stream_array_begin) == 0x58, "mmVertexDataStream.stream_array_begin");
static_assert(offsetof(mmVertexDataStream, stream_array_end) == 0x60, "mmVertexDataStream.stream_array_end");
static_assert(offsetof(mmVertexDataStream, shadow_buffer) == 0x78, "mmVertexDataStream.shadow_buffer");

/* ========================================================================
 * mmVertexShader — compiled vertex shader object
 * Size unknown, >= 0xF8. Vtable not set in observed methods.
 * Layout from LoadFromCompiledFile (0x1170E0, 0x117340), LoadFromCompiledMemory (0x117230).
 * ======================================================================== */
struct __attribute__((packed)) mmVertexShader {
    uint8_t _pad_0x00[0xC8];          /* 0x00: large header, includes debug string ref at 0xC8 */
    uint64_t debug_string_ref;        /* 0xC8: "ShaderCompiledFromMemory.fx" context */
    uint8_t _pad_0xD0[0x20];          /* 0xD0: padding */
    void *compiled_shader_blob;       /* 0xF0: compiled shader data ptr, null-checked */
};
static_assert(offsetof(mmVertexShader, debug_string_ref) == 0xC8, "mmVertexShader.debug_string_ref");
static_assert(offsetof(mmVertexShader, compiled_shader_blob) == 0xF0, "mmVertexShader.compiled_shader_blob");

/* ========================================================================
 * mmXMLSerializeReader — XML deserialization reader
 * Size unknown, >= 0x1C0. Vtable not observed.
 * Layout from CheckTypeID (0x108060), LoadObject (0x108B20).
 * Shares layout prefix with mmXMLSerializeWriter.
 * ======================================================================== */
struct __attribute__((packed)) mmXMLSerializeReader {
    uint64_t *vtable_or_base;         /* 0x00: base/vtable ptr */
    uint64_t current_node;            /* 0x08: param_1[1], advanced by +0x10 per node */
    uint64_t node_end;                /* 0x10: param_1[2], bounds check */
    uint8_t _pad_0x18[8];             /* 0x18: padding */
    uint64_t data_buffer;             /* 0x20: base data buffer pointer */
    uint8_t _pad_0x28[0x20];          /* 0x28: padding */
    uint32_t current_offset;          /* 0x48: offset into data_buffer (0xFFFFFFFF = invalid) */
    uint8_t _pad_0x4C[0x34];          /* 0x4C: padding */
    uint64_t sub_object_0x80;         /* 0x80: sub-object (writer has same layout here) */
    uint8_t _pad_0x88[0x130];         /* 0x88: padding to 0x1B8 */
    uint64_t metadata_ptr;            /* 0x1B8: metadata/type-info pointer */
};
static_assert(offsetof(mmXMLSerializeReader, current_node) == 0x08, "mmXMLSerializeReader.current_node");
static_assert(offsetof(mmXMLSerializeReader, node_end) == 0x10, "mmXMLSerializeReader.node_end");
static_assert(offsetof(mmXMLSerializeReader, data_buffer) == 0x20, "mmXMLSerializeReader.data_buffer");
static_assert(offsetof(mmXMLSerializeReader, current_offset) == 0x48, "mmXMLSerializeReader.current_offset");
static_assert(offsetof(mmXMLSerializeReader, metadata_ptr) == 0x1B8, "mmXMLSerializeReader.metadata_ptr");

/* ========================================================================
 * mmXMLSerializeWriter — XML serialization writer
 * Size unknown, >= 0x1C0. Vtable not observed.
 * Layout from SaveObject<mmObject> (0x108950).
 * Shares layout prefix with mmXMLSerializeReader.
 * ======================================================================== */
struct __attribute__((packed)) mmXMLSerializeWriter {
    uint64_t *vtable_or_base;         /* 0x00: base/vtable ptr */
    uint8_t _pad_0x08[0x18];          /* 0x08: padding (reader uses 0x08-0x10 differently) */
    uint64_t data_buffer;             /* 0x20: base data buffer pointer */
    uint8_t _pad_0x28[0x20];          /* 0x28: padding */
    uint32_t current_offset;          /* 0x48: offset into data_buffer (0xFFFFFFFF = invalid) */
    uint8_t _pad_0x4C[0x34];          /* 0x4C: padding */
    uint64_t output_sub_object;       /* 0x80: output target sub-object */
    uint8_t _pad_0x88[0x130];         /* 0x88: padding to 0x1B8 */
    uint64_t metadata_ptr;            /* 0x1B8: metadata/type-info pointer */
};
static_assert(offsetof(mmXMLSerializeWriter, data_buffer) == 0x20, "mmXMLSerializeWriter.data_buffer");
static_assert(offsetof(mmXMLSerializeWriter, current_offset) == 0x48, "mmXMLSerializeWriter.current_offset");
static_assert(offsetof(mmXMLSerializeWriter, output_sub_object) == 0x80, "mmXMLSerializeWriter.output_sub_object");
static_assert(offsetof(mmXMLSerializeWriter, metadata_ptr) == 0x1B8, "mmXMLSerializeWriter.metadata_ptr");

#endif /* CMN34_H */