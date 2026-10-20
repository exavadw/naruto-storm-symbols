/*
 * cmn34 struct group — Build s4 (NSUNS4_release.exe, NARUTO STORM 4 PC 1.09)
 * Reconstructed from static decompilation only. All layouts are INFERRED.
 * Offsets derived from s4 x64 code (image base 0x140000000).
 * Names from s4 symbols/strings only (own-game naming rule).
 * Packed layout with explicit padding; static_assert for every field.
 */

#ifndef CMN34_S4_H
#define CMN34_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmVertexDataBase
 * Base class with multiple embedded sub-objects (linked lists, allocators).
 * Evidence: ctor 0x18E390 (34 accesses), ctor 0x9F8BC0 (13 accesses).
 * Size = 0x138 (proven by _aligned_malloc(0x138,0x10) in QuadRenderer::Initialize 0x18EB50
 * and mmVertexData::CreateData 0x19A990).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x14];       /* 0x00 - vtable + header (not resolved) */
    uint8_t field_0x14;           /* 0x14 - byte, zeroed in ctor 0x18E390 */
    uint8_t pad_0x15[0x43];       /* 0x15 */
    uint32_t field_0x58;          /* 0x58 - zeroed in ctor [0xb] */
    uint8_t pad_0x5c[0x04];       /* 0x5c - align to 0x60 */
    uint64_t sub_list_a_head;     /* 0x60 - zeroed [0xc] */
    uint64_t sub_list_a_tail;     /* 0x68 - zeroed [0xd] */
    uint64_t sub_list_b_prev;     /* 0x70 - not directly accessed */
    uint64_t sub_list_b_next;     /* 0x78 - rw, zeroed then self-linked [0xf] */
    uint64_t sub_list_b_sentinel; /* 0x80 - zeroed [0x10] */
    uint64_t sub_list_b_end;      /* 0x88 - PTR_LAB_1412f85f0 sentinel [0x11] */
    uint64_t field_0x90;          /* 0x90 - rw, mixed 1/8 byte writes [0x12] */
    uint32_t field_0x98;          /* 0x98 - zeroed [0x13] */
    uint8_t pad_0x9c[0x04];       /* 0x9c - align to 0xa0 */
    uint64_t sub_list_c_ptr;      /* 0xa0 - rw, address-taken [0x14] */
    uint64_t sub_list_c_head;     /* 0xa8 - zeroed [0x15] */
    uint64_t sub_list_c_tail;     /* 0xb0 - zeroed [0x16] */
    uint64_t sub_list_c_sentinel; /* 0xb8 - zeroed [0x17] */
    uint32_t field_0xc0;          /* 0xc0 - zeroed [0x18] */
    uint8_t pad_0xc4[0x04];       /* 0xc4 - align to 0xc8 */
    uint64_t sub_list_d_prev;     /* 0xc8 - PTR_LAB_1412f85f0 [0x19] */
    uint64_t sub_list_d_next;     /* 0xd0 - copies field_0x90 [0x1a] */
    uint64_t field_0xd8;          /* 0xd8 - zeroed [0x1b] */
    uint32_t field_0xe0;          /* 0xe0 - zeroed [0x1c] */
    uint8_t pad_0xe4[0x04];       /* 0xe4 - align to 0xe8 */
    uint64_t sub_list_e_sentinel; /* 0xe8 - PTR_LAB_1412f85f0 [0x1d] */
    uint64_t field_0xf0;          /* 0xf0 - zeroed [0x1e] */
    uint8_t pad_0xf8[0x08];       /* 0xf8 - align to 0x100 */
    uint64_t field_0x100;         /* 0x100 - read-only, address-taken [0x20] */
    uint64_t field_0x108;         /* 0x108 - zeroed [0x21] */
    uint64_t field_0x110;         /* 0x110 - zeroed [0x22] */
    uint64_t field_0x118;         /* 0x118 - zeroed [0x23] */
    uint32_t field_0x120;         /* 0x120 - zeroed [0x24] */
    uint8_t pad_0x124[0x04];      /* 0x124 - align to 0x128 */
    uint64_t sub_list_f_sentinel; /* 0x128 - PTR_LAB_1412f85f0 [0x25] */
    uint64_t field_0x130;         /* 0x130 - zeroed [0x26] */
} mmVertexDataBase_s4;

static_assert(sizeof(mmVertexDataBase_s4) == 0x138, "mmVertexDataBase_s4 size");
static_assert(offsetof(mmVertexDataBase_s4, field_0x14) == 0x14, "mmVertexDataBase.field_0x14");
static_assert(offsetof(mmVertexDataBase_s4, field_0x58) == 0x58, "mmVertexDataBase.field_0x58");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_a_head) == 0x60, "mmVertexDataBase.sub_list_a_head");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_a_tail) == 0x68, "mmVertexDataBase.sub_list_a_tail");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_prev) == 0x70, "mmVertexDataBase.sub_list_b_prev");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_next) == 0x78, "mmVertexDataBase.sub_list_b_next");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_sentinel) == 0x80, "mmVertexDataBase.sub_list_b_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_end) == 0x88, "mmVertexDataBase.sub_list_b_end");
static_assert(offsetof(mmVertexDataBase_s4, field_0x90) == 0x90, "mmVertexDataBase.field_0x90");
static_assert(offsetof(mmVertexDataBase_s4, field_0x98) == 0x98, "mmVertexDataBase.field_0x98");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_ptr) == 0xa0, "mmVertexDataBase.sub_list_c_ptr");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_head) == 0xa8, "mmVertexDataBase.sub_list_c_head");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_tail) == 0xb0, "mmVertexDataBase.sub_list_c_tail");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_sentinel) == 0xb8, "mmVertexDataBase.sub_list_c_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, field_0xc0) == 0xc0, "mmVertexDataBase.field_0xc0");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_d_prev) == 0xc8, "mmVertexDataBase.sub_list_d_prev");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_d_next) == 0xd0, "mmVertexDataBase.sub_list_d_next");
static_assert(offsetof(mmVertexDataBase_s4, field_0xd8) == 0xd8, "mmVertexDataBase.field_0xd8");
static_assert(offsetof(mmVertexDataBase_s4, field_0xe0) == 0xe0, "mmVertexDataBase.field_0xe0");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_e_sentinel) == 0xe8, "mmVertexDataBase.sub_list_e_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, field_0xf0) == 0xf0, "mmVertexDataBase.field_0xf0");
static_assert(offsetof(mmVertexDataBase_s4, field_0x100) == 0x100, "mmVertexDataBase.field_0x100");
static_assert(offsetof(mmVertexDataBase_s4, field_0x108) == 0x108, "mmVertexDataBase.field_0x108");
static_assert(offsetof(mmVertexDataBase_s4, field_0x110) == 0x110, "mmVertexDataBase.field_0x110");
static_assert(offsetof(mmVertexDataBase_s4, field_0x118) == 0x118, "mmVertexDataBase.field_0x118");
static_assert(offsetof(mmVertexDataBase_s4, field_0x120) == 0x120, "mmVertexDataBase.field_0x120");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_f_sentinel) == 0x128, "mmVertexDataBase.sub_list_f_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, field_0x130) == 0x130, "mmVertexDataBase.field_0x130");

/* =========================================================================
 * mmVertexDataFlexible
 * Flexible vertex buffer with dynamic offset info linked list.
 * Evidence: CreateData 0x1969F0 (writes through param_1[0x11] at offset 0x88).
 * Size >= 0x90 (last field at 0x88, 8 bytes). No allocator size found in callers.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x14];            /* 0x00 - vtable + header */
    uint8_t field_0x14;                /* 0x14 - byte, zeroed in CreateData */
    uint8_t pad_0x15[0x17];            /* 0x15 */
    uint32_t field_0x2c;               /* 0x2c - rw, compared < 3 in SetOffsetInfo */
    uint8_t pad_0x30[0x28];            /* 0x30 */
    uint64_t field_0x58;               /* 0x58 - zeroed [0xb] */
    uint64_t offset_info_list_head;    /* 0x60 - zeroed [0xc] */
    uint64_t offset_info_list_tail;    /* 0x68 - zeroed [0xd] */
    uint64_t field_0x70;               /* 0x70 - zeroed [0xe] */
    uint64_t field_0x78;               /* 0x78 - PTR_LAB_1412f85f0 sentinel [0xf] */
    uint64_t field_0x80;               /* 0x80 - zeroed [0x10] */
    void *shadow_copy;                 /* 0x88 - optional shadow buffer [0x11] */
} mmVertexDataFlexible_s4;

static_assert(offsetof(mmVertexDataFlexible_s4, field_0x14) == 0x14, "mmVertexDataFlexible.field_0x14");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x2c) == 0x2c, "mmVertexDataFlexible.field_0x2c");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x58) == 0x58, "mmVertexDataFlexible.field_0x58");
static_assert(offsetof(mmVertexDataFlexible_s4, offset_info_list_head) == 0x60, "mmVertexDataFlexible.offset_info_list_head");
static_assert(offsetof(mmVertexDataFlexible_s4, offset_info_list_tail) == 0x68, "mmVertexDataFlexible.offset_info_list_tail");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x70) == 0x70, "mmVertexDataFlexible.field_0x70");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x78) == 0x78, "mmVertexDataFlexible.field_0x78");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x80) == 0x80, "mmVertexDataFlexible.field_0x80");
static_assert(offsetof(mmVertexDataFlexible_s4, shadow_copy) == 0x88, "mmVertexDataFlexible.shadow_copy");

/* =========================================================================
 * mmVertexData
 * Concrete vertex data object.
 * Evidence: ~mmVertexData dtor writes DAT globals at 0x24, 0x2c; reads 0x70.
 * Size >= 0x78 (last accessed offset 0x70, size unknown).
 * Note: mmVertexData::CreateData 0x19A990 allocates 0x138 for the base
 * mmVertexDataBase sub-object, not for mmVertexData itself.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x24];       /* 0x00 - vtable + header */
    uint64_t field_0x24;          /* 0x24 - DAT_1482d96d8 written in dtor */
    uint32_t field_0x2c;          /* 0x2c - DAT_1482d96e0 written in dtor */
    uint8_t pad_0x30[0x40];       /* 0x30 */
    uint64_t field_0x70;          /* 0x70 - read in dtor (sub-object ptr?) */
} mmVertexData_s4;

static_assert(offsetof(mmVertexData_s4, field_0x24) == 0x24, "mmVertexData.field_0x24");
static_assert(offsetof(mmVertexData_s4, field_0x2c) == 0x2c, "mmVertexData.field_0x2c");
static_assert(offsetof(mmVertexData_s4, field_0x70) == 0x70, "mmVertexData.field_0x70");

/* =========================================================================
 * mmVertexSemantic
 * Contains an embedded eastl::rbtree<mmSemantic,...> at offset 0x00.
 * Evidence: AddSemantic 0x196100 (accesses 0x08,0x18,0x28,0x38,0x40,0x70,0x74),
 * Release 0x1A36D0 (accesses 0x30,0x38,0x40,0x48,0x4c,0x54).
 * Size unknown, >= 0x78 (last field at 0x74 + 4 bytes).
 * No allocator size found in callers.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x08];       /* 0x00 - rbtree header (vtable/allocator) */
    uint64_t rbtree_root;         /* 0x08 - rbtree root node ptr [AddSemantic] */
    uint8_t pad_0x10[0x08];       /* 0x10 */
    uint64_t rbtree_end;          /* 0x18 - rbtree end sentinel [AddSemantic] */
    uint8_t pad_0x20[0x08];       /* 0x20 */
    uint32_t rbtree_count;        /* 0x28 - compared < 0x10 in AddSemantic */
    uint8_t pad_0x2c[0x04];       /* 0x2c */
    uint64_t rbtree_node_ptr;     /* 0x30 - freed in Release via DoNukeSubtree */
    int *semantic_ids_begin;      /* 0x38 - array begin, incremented in AddSemantic */
    int *semantic_ids_end;        /* 0x40 - array end, compared in AddSemantic */
    uint8_t pad_0x48[0x04];       /* 0x48 */
    uint32_t field_0x4c;          /* 0x4c - set to DAT_148d32f38 in Release */
    uint32_t field_0x50;          /* 0x50 */
    uint64_t field_0x54;          /* 0x54 - set to DAT_148d32f38 in Release */
    uint8_t pad_0x5c[0x14];       /* 0x5c */
    uint32_t node_count;          /* 0x70 - incremented in AddSemantic */
    uint32_t total_vertex_size;   /* 0x74 - accumulated semantic sizes */
} mmVertexSemantic_s4;

static_assert(offsetof(mmVertexSemantic_s4, pad_0x00) == 0x00, "mmVertexSemantic.pad_0x00");
static_assert(offsetof(mmVertexSemantic_s4, rbtree_root) == 0x08, "mmVertexSemantic.rbtree_root");
static_assert(offsetof(mmVertexSemantic_s4, pad_0x10) == 0x10, "mmVertexSemantic.pad_0x10");
static_assert(offsetof(mmVertexSemantic_s4, rbtree_end) == 0x18, "mmVertexSemantic.rbtree_end");
static_assert(offsetof(mmVertexSemantic_s4, pad_0x20) == 0x20, "mmVertexSemantic.pad_0x20");
static_assert(offsetof(mmVertexSemantic_s4, rbtree_count) == 0x28, "mmVertexSemantic.rbtree_count");
static_assert(offsetof(mmVertexSemantic_s4, pad_0x2c) == 0x2c, "mmVertexSemantic.pad_0x2c");
static_assert(offsetof(mmVertexSemantic_s4, rbtree_node_ptr) == 0x30, "mmVertexSemantic.rbtree_node_ptr");
static_assert(offsetof(mmVertexSemantic_s4, semantic_ids_begin) == 0x38, "mmVertexSemantic.semantic_ids_begin");
static_assert(offsetof(mmVertexSemantic_s4, semantic_ids_end) == 0x40, "mmVertexSemantic.semantic_ids_end");
static_assert(offsetof(mmVertexSemantic_s4, pad_0x48) == 0x48, "mmVertexSemantic.pad_0x48");
static_assert(offsetof(mmVertexSemantic_s4, field_0x4c) == 0x4c, "mmVertexSemantic.field_0x4c");
static_assert(offsetof(mmVertexSemantic_s4, field_0x50) == 0x50, "mmVertexSemantic.field_0x50");
static_assert(offsetof(mmVertexSemantic_s4, field_0x54) == 0x54, "mmVertexSemantic.field_0x54");
static_assert(offsetof(mmVertexSemantic_s4, pad_0x5c) == 0x5c, "mmVertexSemantic.pad_0x5c");
static_assert(offsetof(mmVertexSemantic_s4, node_count) == 0x70, "mmVertexSemantic.node_count");
static_assert(offsetof(mmVertexSemantic_s4, total_vertex_size) == 0x74, "mmVertexSemantic.total_vertex_size");

/* =========================================================================
 * mmVBRenderInfoList
 * Contains an embedded eastl::rbtree at offset 0x20 and a sub-object at 0x10.
 * Evidence: Add 0x196780 (accesses param_4+0x38,0x48 for rbtree; param_1+0x10),
 * Add 0x19A300 (accesses param_1+0x20,0x28,0x30,0x58,0x5c,0x60),
 * Add 0x18A010 (accesses param_1+0x40).
 * Size unknown, >= 0x68 (last field at 0x60 + 8 bytes).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x10];       /* 0x00 - vtable + header */
    uint64_t field_0x10;          /* 0x10 - sub-object passed to FUN_14018acf0 */
    uint8_t pad_0x18[0x08];       /* 0x18 */
    uint64_t rbtree_header;       /* 0x20 - rbtree embedded start */
    uint64_t rbtree_root;         /* 0x28 - rbtree root node */
    uint64_t rbtree_end;          /* 0x30 - rbtree end sentinel */
    uint8_t pad_0x38[0x08];       /* 0x38 */
    uint64_t field_0x40;          /* 0x40 - passed to BuildRenderInfoList */
    uint8_t pad_0x48[0x10];       /* 0x48 */
    uint32_t field_0x58;          /* 0x58 - stride/offset base */
    uint32_t field_0x5c;          /* 0x5c - offset component */
    uint64_t field_0x60;          /* 0x60 - offset component */
} mmVBRenderInfoList_s4;

static_assert(offsetof(mmVBRenderInfoList_s4, pad_0x00) == 0x00, "mmVBRenderInfoList.pad_0x00");
static_assert(offsetof(mmVBRenderInfoList_s4, field_0x10) == 0x10, "mmVBRenderInfoList.field_0x10");
static_assert(offsetof(mmVBRenderInfoList_s4, pad_0x18) == 0x18, "mmVBRenderInfoList.pad_0x18");
static_assert(offsetof(mmVBRenderInfoList_s4, rbtree_header) == 0x20, "mmVBRenderInfoList.rbtree_header");
static_assert(offsetof(mmVBRenderInfoList_s4, rbtree_root) == 0x28, "mmVBRenderInfoList.rbtree_root");
static_assert(offsetof(mmVBRenderInfoList_s4, rbtree_end) == 0x30, "mmVBRenderInfoList.rbtree_end");
static_assert(offsetof(mmVBRenderInfoList_s4, pad_0x38) == 0x38, "mmVBRenderInfoList.pad_0x38");
static_assert(offsetof(mmVBRenderInfoList_s4, field_0x40) == 0x40, "mmVBRenderInfoList.field_0x40");
static_assert(offsetof(mmVBRenderInfoList_s4, pad_0x48) == 0x48, "mmVBRenderInfoList.pad_0x48");
static_assert(offsetof(mmVBRenderInfoList_s4, field_0x58) == 0x58, "mmVBRenderInfoList.field_0x58");
static_assert(offsetof(mmVBRenderInfoList_s4, field_0x5c) == 0x5c, "mmVBRenderInfoList.field_0x5c");
static_assert(offsetof(mmVBRenderInfoList_s4, field_0x60) == 0x60, "mmVBRenderInfoList.field_0x60");

/* =========================================================================
 * mmVertexShader
 * Contains an eastl::basic_string at 0xc8 and a shader object ptr at 0xf0.
 * Evidence: LoadFromCompiledFile 0x1951C0 (accesses 0xc8 via string append,
 * 0xf0 checked/set), LoadFromCompiledMemory 0x195310 (same pattern).
 * Size unknown, >= 0xf8 (last field at 0xf0 + 8 bytes).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0xc8];       /* 0x00 - vtable + header + unknown fields */
    uint64_t shader_name_str[4];  /* 0xc8 - eastl::basic_string (32 bytes typical) */
    uint8_t pad_0xe8[0x08];       /* 0xe8 */
    uint64_t shader_object;       /* 0xf0 - allocated ptr, checked != 0 before load */
} mmVertexShader_s4;

static_assert(offsetof(mmVertexShader_s4, pad_0x00) == 0x00, "mmVertexShader.pad_0x00");
static_assert(offsetof(mmVertexShader_s4, shader_name_str) == 0xc8, "mmVertexShader.shader_name_str");
static_assert(offsetof(mmVertexShader_s4, pad_0xe8) == 0xe8, "mmVertexShader.pad_0xe8");
static_assert(offsetof(mmVertexShader_s4, shader_object) == 0xf0, "mmVertexShader.shader_object");

/* =========================================================================
 * mmVertexDataStream
 * Manages GPU vertex buffers with semantic info and render info lists.
 * Evidence: CreateData 0x196730 (accesses 0x08,0x10),
 * CreateDataStream 0x1A3510 (accesses 0x08,0x30,0x38,0x3c,0x78,0x80,0xf8),
 * Release 0x1A36D0 (accesses 0x08,0x30,0x38,0x40,0x48,0x4c,0x54,0x58,0x60,0x78,0xf8,0x110).
 * Size unknown, >= 0x118 (last field at 0x110 + 8 bytes).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x08];       /* 0x00 - vtable */
    uint64_t field_0x08;          /* 0x08 - ptr dereferenced in CreateData/CreateDataStream */
    uint64_t field_0x10;          /* 0x10 - sub-object passed to mmVBRenderInfoList::Add */
    uint8_t pad_0x18[0x18];       /* 0x18 */
    uint64_t semantic_ptr;        /* 0x30 - ptr to mmVertexSemantic, read in CreateDataStream */
    uint32_t vertex_stride;       /* 0x38 - computed stride, set in CreateDataStream */
    uint32_t field_0x3c;          /* 0x3c - same value as vertex_stride */
    uint8_t pad_0x40[0x18];       /* 0x40 - zeroed/set in Release */
    uint64_t array_begin;         /* 0x58 - array begin ptr, iterated in Release */
    uint64_t array_end;           /* 0x60 - array end ptr, compared with begin */
    uint8_t pad_0x68[0x10];       /* 0x68 */
    void *shadow_buffer;          /* 0x78 - CPU copy of GPU buffer, freed in Release */
    uint8_t buffer_bind_info[0x78]; /* 0x80 - mmBufferBindInfo sub-object (0x78 bytes) */
    uint64_t field_0xf8;          /* 0xf8 - sub-object passed to mmVBRenderInfoList::Add */
    uint8_t pad_0x100[0x10];      /* 0x100 */
    uint64_t vertex_data_list;    /* 0x110 - linked list of mmVertexDataBase, walked in Release */
} mmVertexDataStream_s4;

static_assert(offsetof(mmVertexDataStream_s4, pad_0x00) == 0x00, "mmVertexDataStream.pad_0x00");
static_assert(offsetof(mmVertexDataStream_s4, field_0x08) == 0x08, "mmVertexDataStream.field_0x08");
static_assert(offsetof(mmVertexDataStream_s4, field_0x10) == 0x10, "mmVertexDataStream.field_0x10");
static_assert(offsetof(mmVertexDataStream_s4, pad_0x18) == 0x18, "mmVertexDataStream.pad_0x18");
static_assert(offsetof(mmVertexDataStream_s4, semantic_ptr) == 0x30, "mmVertexDataStream.semantic_ptr");
static_assert(offsetof(mmVertexDataStream_s4, vertex_stride) == 0x38, "mmVertexDataStream.vertex_stride");
static_assert(offsetof(mmVertexDataStream_s4, field_0x3c) == 0x3c, "mmVertexDataStream.field_0x3c");
static_assert(offsetof(mmVertexDataStream_s4, pad_0x40) == 0x40, "mmVertexDataStream.pad_0x40");
static_assert(offsetof(mmVertexDataStream_s4, array_begin) == 0x58, "mmVertexDataStream.array_begin");
static_assert(offsetof(mmVertexDataStream_s4, array_end) == 0x60, "mmVertexDataStream.array_end");
static_assert(offsetof(mmVertexDataStream_s4, pad_0x68) == 0x68, "mmVertexDataStream.pad_0x68");
static_assert(offsetof(mmVertexDataStream_s4, shadow_buffer) == 0x78, "mmVertexDataStream.shadow_buffer");
static_assert(offsetof(mmVertexDataStream_s4, buffer_bind_info) == 0x80, "mmVertexDataStream.buffer_bind_info");
static_assert(offsetof(mmVertexDataStream_s4, field_0xf8) == 0xf8, "mmVertexDataStream.field_0xf8");
static_assert(offsetof(mmVertexDataStream_s4, pad_0x100) == 0x100, "mmVertexDataStream.pad_0x100");
static_assert(offsetof(mmVertexDataStream_s4, vertex_data_list) == 0x110, "mmVertexDataStream.vertex_data_list");

/* =========================================================================
 * mmUTF8: no instance state.
 * Static utility class operating on raw byte pointers.
 * Evidence: Next 0x184800 takes byte* param_1, indexes global DAT_1412f2850.
 * GetCodePoint 0x184820 same pattern — reads *param_1, switches on lookup table.
 * Neither method reads or writes any this->field; param_1 is the UTF-8 data itself.
 * ========================================================================= */

#endif /* CMN34_S4_H */
