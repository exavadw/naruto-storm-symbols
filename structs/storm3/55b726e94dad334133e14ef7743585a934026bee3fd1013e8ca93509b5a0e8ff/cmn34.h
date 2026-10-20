/*
 * cmn34 struct group — Build s3 (NSUNS3.exe, NARUTO STORM 3 Full Burst HD PC)
 * Reconstructed from static decompilation only. All layouts are INFERRED.
 * Offsets derived from s3 x64 code (image base 0x140000000).
 * Names from s3 symbols/strings only (own-game naming rule).
 * Natural alignment (not packed) — explicit padding matches game layout.
 */

#ifndef CMN34_S3_H
#define CMN34_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmVertexDataBase
 * Base class with multiple embedded sub-objects (linked lists, allocators).
 * Evidence: ctor 0x13DB40 (34 accesses), ctor 0x67E440 (13 accesses).
 * Size >= 0x138 (last field at 0x130, 8 bytes).
 * ========================================================================= */
typedef struct {
    uint8_t  pad_0x00[0x14];          /* 0x00 - vtable + header (not resolved) */
    uint8_t  field_0x14;              /* 0x14 - byte, zeroed in ctor 0x13DB40 */
    uint8_t  pad_0x15[0x43];          /* 0x15 */
    uint32_t field_0x58;              /* 0x58 - zeroed in ctor [0xb] */
    uint64_t sub_list_a_head;         /* 0x60 - zeroed [0xc] */
    uint64_t sub_list_a_tail;         /* 0x68 - zeroed [0xd] */
    uint64_t sub_list_b_prev;         /* 0x70 - not directly accessed */
    uint64_t sub_list_b_next;         /* 0x78 - rw, zeroed then self-linked [0xf] */
    uint64_t sub_list_b_sentinel;     /* 0x80 - zeroed [0x10] */
    uint64_t sub_list_b_end;          /* 0x88 - PTR_LAB_140a1d290 sentinel [0x11] */
    uint64_t field_0x90;              /* 0x90 - rw, mixed 1/8 byte writes [0x12] */
    uint32_t field_0x98;              /* 0x98 - zeroed [0x13] */
    uint8_t  pad_0x9c[0x04];          /* 0x9c */
    uint64_t sub_list_c_ptr;          /* 0xa0 - rw, address-taken [0x14] */
    uint64_t sub_list_c_head;         /* 0xa8 - zeroed [0x15] */
    uint64_t sub_list_c_tail;         /* 0xb0 - zeroed [0x16] */
    uint64_t sub_list_c_sentinel;     /* 0xb8 - zeroed [0x17] */
    uint32_t field_0xc0;              /* 0xc0 - zeroed [0x18] */
    uint8_t  pad_0xc4[0x04];          /* 0xc4 */
    uint64_t sub_list_d_prev;         /* 0xc8 - PTR_LAB_140a1d290 [0x19] */
    uint64_t sub_list_d_next;         /* 0xd0 - copies field_0x90 [0x1a] */
    uint64_t field_0xd8;              /* 0xd8 - zeroed [0x1b] */
    uint32_t field_0xe0;              /* 0xe0 - zeroed [0x1c] */
    uint8_t  pad_0xe4[0x04];          /* 0xe4 */
    uint64_t sub_list_e_sentinel;     /* 0xe8 - PTR_LAB_140a1d290 [0x1d] */
    uint64_t field_0xf0;              /* 0xf0 - zeroed [0x1e] */
    uint8_t  pad_0xf8[0x08];          /* 0xf8 */
    uint64_t field_0x100;             /* 0x100 - read-only, address-taken [0x20] */
    uint64_t field_0x108;             /* 0x108 - zeroed [0x21] */
    uint64_t field_0x110;             /* 0x110 - zeroed [0x22] */
    uint64_t field_0x118;             /* 0x118 - zeroed [0x23] */
    uint32_t field_0x120;             /* 0x120 - zeroed [0x24] */
    uint8_t  pad_0x124[0x04];         /* 0x124 */
    uint64_t sub_list_f_sentinel;     /* 0x128 - PTR_LAB_140a1d290 [0x25] */
    uint64_t field_0x130;             /* 0x130 - zeroed [0x26] */
} mmVertexDataBase_s3;

static_assert(offsetof(mmVertexDataBase_s3, field_0x14) == 0x14, "mmVertexDataBase.field_0x14");
static_assert(offsetof(mmVertexDataBase_s3, field_0x58) == 0x58, "mmVertexDataBase.field_0x58");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_a_head) == 0x60, "mmVertexDataBase.sub_list_a_head");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_a_tail) == 0x68, "mmVertexDataBase.sub_list_a_tail");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_b_prev) == 0x70, "mmVertexDataBase.sub_list_b_prev");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_b_next) == 0x78, "mmVertexDataBase.sub_list_b_next");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_b_sentinel) == 0x80, "mmVertexDataBase.sub_list_b_sentinel");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_b_end) == 0x88, "mmVertexDataBase.sub_list_b_end");
static_assert(offsetof(mmVertexDataBase_s3, field_0x90) == 0x90, "mmVertexDataBase.field_0x90");
static_assert(offsetof(mmVertexDataBase_s3, field_0x98) == 0x98, "mmVertexDataBase.field_0x98");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_c_ptr) == 0xa0, "mmVertexDataBase.sub_list_c_ptr");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_c_head) == 0xa8, "mmVertexDataBase.sub_list_c_head");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_c_tail) == 0xb0, "mmVertexDataBase.sub_list_c_tail");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_c_sentinel) == 0xb8, "mmVertexDataBase.sub_list_c_sentinel");
static_assert(offsetof(mmVertexDataBase_s3, field_0xc0) == 0xc0, "mmVertexDataBase.field_0xc0");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_d_prev) == 0xc8, "mmVertexDataBase.sub_list_d_prev");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_d_next) == 0xd0, "mmVertexDataBase.sub_list_d_next");
static_assert(offsetof(mmVertexDataBase_s3, field_0xd8) == 0xd8, "mmVertexDataBase.field_0xd8");
static_assert(offsetof(mmVertexDataBase_s3, field_0xe0) == 0xe0, "mmVertexDataBase.field_0xe0");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_e_sentinel) == 0xe8, "mmVertexDataBase.sub_list_e_sentinel");
static_assert(offsetof(mmVertexDataBase_s3, field_0xf0) == 0xf0, "mmVertexDataBase.field_0xf0");
static_assert(offsetof(mmVertexDataBase_s3, field_0x100) == 0x100, "mmVertexDataBase.field_0x100");
static_assert(offsetof(mmVertexDataBase_s3, field_0x108) == 0x108, "mmVertexDataBase.field_0x108");
static_assert(offsetof(mmVertexDataBase_s3, field_0x110) == 0x110, "mmVertexDataBase.field_0x110");
static_assert(offsetof(mmVertexDataBase_s3, field_0x118) == 0x118, "mmVertexDataBase.field_0x118");
static_assert(offsetof(mmVertexDataBase_s3, field_0x120) == 0x120, "mmVertexDataBase.field_0x120");
static_assert(offsetof(mmVertexDataBase_s3, sub_list_f_sentinel) == 0x128, "mmVertexDataBase.sub_list_f_sentinel");
static_assert(offsetof(mmVertexDataBase_s3, field_0x130) == 0x130, "mmVertexDataBase.field_0x130");

/* =========================================================================
 * mmVertexDataFlexible
 * Flexible vertex buffer with dynamic offset info linked list.
 * Evidence: CreateData 0x1469A0 (9 accesses).
 * Size >= 0x90 (last field at 0x88, 8 bytes).
 * ========================================================================= */
typedef struct {
    uint8_t  pad_0x00[0x14];          /* 0x00 - vtable + header */
    uint8_t  field_0x14;              /* 0x14 - byte, zeroed in CreateData */
    uint8_t  pad_0x15[0x43];          /* 0x15 */
    uint64_t field_0x58;              /* 0x58 - zeroed [0xb] */
    uint64_t offset_info_list_head;   /* 0x60 - zeroed [0xc] */
    uint64_t offset_info_list_tail;   /* 0x68 - zeroed [0xd] */
    uint64_t field_0x70;              /* 0x70 - zeroed [0xe] */
    uint64_t field_0x78;              /* 0x78 - PTR_LAB_140a1d290 sentinel [0xf] */
    uint64_t field_0x80;              /* 0x80 - zeroed [0x10] */
    void    *shadow_copy;             /* 0x88 - optional shadow buffer [0x11] */
} mmVertexDataFlexible_s3;

static_assert(offsetof(mmVertexDataFlexible_s3, field_0x14) == 0x14, "mmVertexDataFlexible.field_0x14");
static_assert(offsetof(mmVertexDataFlexible_s3, field_0x58) == 0x58, "mmVertexDataFlexible.field_0x58");
static_assert(offsetof(mmVertexDataFlexible_s3, offset_info_list_head) == 0x60, "mmVertexDataFlexible.offset_info_list_head");
static_assert(offsetof(mmVertexDataFlexible_s3, offset_info_list_tail) == 0x68, "mmVertexDataFlexible.offset_info_list_tail");
static_assert(offsetof(mmVertexDataFlexible_s3, field_0x70) == 0x70, "mmVertexDataFlexible.field_0x70");
static_assert(offsetof(mmVertexDataFlexible_s3, field_0x78) == 0x78, "mmVertexDataFlexible.field_0x78");
static_assert(offsetof(mmVertexDataFlexible_s3, field_0x80) == 0x80, "mmVertexDataFlexible.field_0x80");
static_assert(offsetof(mmVertexDataFlexible_s3, shadow_copy) == 0x88, "mmVertexDataFlexible.shadow_copy");

/* =========================================================================
 * mmVertexData
 * Concrete vertex data object.
 * Evidence: ~mmVertexData 0x14A8C0 (3 accesses).
 * Size >= 0x78 (last accessed offset 0x70, size unknown).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t  pad_0x00[0x24];          /* 0x00 - vtable + header */
    uint64_t field_0x24;              /* 0x24 - DAT_1482d96d8 written in dtor */
    uint32_t field_0x2c;              /* 0x2c - DAT_1482d96e0 written in dtor */
    uint8_t  pad_0x30[0x40];          /* 0x30 */
    uint64_t field_0x70;              /* 0x70 - read in dtor (sub-object ptr?) */
} mmVertexData_s3;

static_assert(offsetof(mmVertexData_s3, field_0x24) == 0x24, "mmVertexData.field_0x24");
static_assert(offsetof(mmVertexData_s3, field_0x2c) == 0x2c, "mmVertexData.field_0x2c");
static_assert(offsetof(mmVertexData_s3, field_0x70) == 0x70, "mmVertexData.field_0x70");

/* =========================================================================
 * mmVertexSemantic_s3
 * Semantic map with intrusive tree + flat arrays for lookup.
 * Evidence: AddSemantic 0x1460B0, GetSemanticSize 0x146240,
 *           GetSemanticOffset 0x1462B0.
 * Size >= 0x78 (last field at 0x74, 4 bytes).
 * INFERRED from static decompilation only.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct {
    uint8_t  pad_0x00[0x08];          /* 0x00 - vtable/header */
    uint64_t tree_root;               /* 0x08 - tree root ptr [AddSemantic] */
    uint8_t  pad_0x10[0x08];          /* 0x10 */
    uint64_t tree_end_sentinel;       /* 0x18 - tree end sentinel [AddSemantic/GetSemanticSize] */
    uint8_t  pad_0x20[0x08];          /* 0x20 */
    uint32_t field_0x28;              /* 0x28 - threshold/count check [AddSemantic] */
    uint8_t  pad_0x2c[0x04];          /* 0x2c */
    uint64_t semantic_ids_base;       /* 0x30 - base ptr for id array [GetSemanticOffset] */
    uint64_t semantic_ids_end;        /* 0x38 - end ptr for id array [AddSemantic/GetSemanticOffset] */
    uint8_t  pad_0x40[0x10];          /* 0x40 */
    uint64_t semantic_sizes_base;     /* 0x50 - base ptr for size array [GetSemanticOffset] */
    uint8_t  pad_0x58[0x18];          /* 0x58 */
    uint32_t semantic_count;          /* 0x70 - incremented in AddSemantic */
    uint32_t total_size_bytes;        /* 0x74 - accumulated size [AddSemantic] */
} mmVertexSemantic_s3;
#pragma pack(pop)

static_assert(offsetof(mmVertexSemantic_s3, pad_0x00) == 0x00, "mmVertexSemantic.pad_0x00");
static_assert(offsetof(mmVertexSemantic_s3, tree_root) == 0x08, "mmVertexSemantic.tree_root");
static_assert(offsetof(mmVertexSemantic_s3, pad_0x10) == 0x10, "mmVertexSemantic.pad_0x10");
static_assert(offsetof(mmVertexSemantic_s3, tree_end_sentinel) == 0x18, "mmVertexSemantic.tree_end_sentinel");
static_assert(offsetof(mmVertexSemantic_s3, pad_0x20) == 0x20, "mmVertexSemantic.pad_0x20");
static_assert(offsetof(mmVertexSemantic_s3, field_0x28) == 0x28, "mmVertexSemantic.field_0x28");
static_assert(offsetof(mmVertexSemantic_s3, pad_0x2c) == 0x2c, "mmVertexSemantic.pad_0x2c");
static_assert(offsetof(mmVertexSemantic_s3, semantic_ids_base) == 0x30, "mmVertexSemantic.semantic_ids_base");
static_assert(offsetof(mmVertexSemantic_s3, semantic_ids_end) == 0x38, "mmVertexSemantic.semantic_ids_end");
static_assert(offsetof(mmVertexSemantic_s3, pad_0x40) == 0x40, "mmVertexSemantic.pad_0x40");
static_assert(offsetof(mmVertexSemantic_s3, semantic_sizes_base) == 0x50, "mmVertexSemantic.semantic_sizes_base");
static_assert(offsetof(mmVertexSemantic_s3, pad_0x58) == 0x58, "mmVertexSemantic.pad_0x58");
static_assert(offsetof(mmVertexSemantic_s3, semantic_count) == 0x70, "mmVertexSemantic.semantic_count");
static_assert(offsetof(mmVertexSemantic_s3, total_size_bytes) == 0x74, "mmVertexSemantic.total_size_bytes");

/* =========================================================================
 * mmVBRenderInfoList_s3
 * Render info list with two intrusive trees and metadata fields.
 * Evidence: Add 0x146730 (param_1+0x10), Add 0x14A2B0 (0x20..0x60),
 *           Add 0x13CCE0 (param_1+0x40).
 * Size >= 0x68 (last field at 0x60, 8 bytes).
 * INFERRED from static decompilation only.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct {
    uint8_t  pad_0x00[0x10];          /* 0x00 - vtable/header */
    uint64_t field_0x10;              /* 0x10 - passed to sub-call [Add 0x146730] */
    uint8_t  pad_0x18[0x08];          /* 0x18 */
    uint64_t tree_a_head;             /* 0x20 - first tree head [Add 0x14A2B0] */
    uint64_t tree_a_node;             /* 0x28 - first tree current node [Add 0x14A2B0] */
    uint64_t tree_b_head;             /* 0x30 - second tree head [Add 0x14A2B0] */
    uint8_t  pad_0x38[0x08];          /* 0x38 */
    uint64_t field_0x40;              /* 0x40 - passed to FUN_14013d7c0 [Add 0x13CCE0] */
    uint8_t  pad_0x48[0x10];          /* 0x48 */
    uint32_t field_0x58;              /* 0x58 - added to node offset [Add 0x14A2B0] */
    uint32_t field_0x5c;              /* 0x5c - metadata word [Add 0x14A2B0] */
    uint32_t field_0x60;              /* 0x60 - metadata word [Add 0x14A2B0] */
    uint8_t  pad_0x64[0x04];          /* 0x64 */
} mmVBRenderInfoList_s3;
#pragma pack(pop)

static_assert(offsetof(mmVBRenderInfoList_s3, pad_0x00) == 0x00, "mmVBRenderInfoList.pad_0x00");
static_assert(offsetof(mmVBRenderInfoList_s3, field_0x10) == 0x10, "mmVBRenderInfoList.field_0x10");
static_assert(offsetof(mmVBRenderInfoList_s3, pad_0x18) == 0x18, "mmVBRenderInfoList.pad_0x18");
static_assert(offsetof(mmVBRenderInfoList_s3, tree_a_head) == 0x20, "mmVBRenderInfoList.tree_a_head");
static_assert(offsetof(mmVBRenderInfoList_s3, tree_a_node) == 0x28, "mmVBRenderInfoList.tree_a_node");
static_assert(offsetof(mmVBRenderInfoList_s3, tree_b_head) == 0x30, "mmVBRenderInfoList.tree_b_head");
static_assert(offsetof(mmVBRenderInfoList_s3, pad_0x38) == 0x38, "mmVBRenderInfoList.pad_0x38");
static_assert(offsetof(mmVBRenderInfoList_s3, field_0x40) == 0x40, "mmVBRenderInfoList.field_0x40");
static_assert(offsetof(mmVBRenderInfoList_s3, pad_0x48) == 0x48, "mmVBRenderInfoList.pad_0x48");
static_assert(offsetof(mmVBRenderInfoList_s3, field_0x58) == 0x58, "mmVBRenderInfoList.field_0x58");
static_assert(offsetof(mmVBRenderInfoList_s3, field_0x5c) == 0x5c, "mmVBRenderInfoList.field_0x5c");
static_assert(offsetof(mmVBRenderInfoList_s3, field_0x60) == 0x60, "mmVBRenderInfoList.field_0x60");
static_assert(offsetof(mmVBRenderInfoList_s3, pad_0x64) == 0x64, "mmVBRenderInfoList.pad_0x64");

/* =========================================================================
 * mmVertexShader_s3
 * Vertex shader wrapper holding compiled shader ptr and name string.
 * Evidence: LoadFromCompiledFile 0x145170 (0xf0, 0xc8),
 *           LoadFromCompiledMemory 0x1452C0 (0xf0, 0xc8).
 * LoadFromCompiledFile 0x1453D0 uses only stack locals (no instance state).
 * Size >= 0xF8 (last field at 0xf0, 8 bytes).
 * INFERRED from static decompilation only.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct {
    uint8_t  pad_0x00[0xC8];          /* 0x00 - header/name buffer region */
    uint64_t name_str_ptr;            /* 0xC8 - written by FUN_14012db20 [LoadFromCompiledFile/Memory] */
    uint8_t  pad_0xD0[0x20];          /* 0xD0 */
    uint64_t compiled_shader;         /* 0xF0 - allocated via _aligned_malloc, holds vtable obj */
} mmVertexShader_s3;
#pragma pack(pop)

static_assert(offsetof(mmVertexShader_s3, pad_0x00) == 0x00, "mmVertexShader.pad_0x00");
static_assert(offsetof(mmVertexShader_s3, name_str_ptr) == 0xC8, "mmVertexShader.name_str_ptr");
static_assert(offsetof(mmVertexShader_s3, pad_0xD0) == 0xD0, "mmVertexShader.pad_0xD0");
static_assert(offsetof(mmVertexShader_s3, compiled_shader) == 0xF0, "mmVertexShader.compiled_shader");

/* =========================================================================
 * mmVertexDataStream_s3
 * Vertex data stream with buffer arrays, shadow copy, and intrusive list.
 * Evidence: Release 0x153830 (0x08..0x128), CreateDataStream 0x153670 (0x30,0x78,0x80),
 *           CreateData 0x1466E0 (0x10).
 * Size >= 0x130 (last field at 0x128, 8 bytes).
 * INFERRED from static decompilation only.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct {
    uint8_t  pad_0x00[0x08];          /* 0x00 - vtable/header */
    uint64_t parent_or_ref;           /* 0x08 - freed in Release if non-null */
    uint8_t  pad_0x10[0x20];          /* 0x10 */
    uint64_t vertex_layout_ptr;       /* 0x30 - layout/format object [CreateDataStream/Release] */
    uint64_t field_0x38;              /* 0x38 - zeroed in Release */
    uint64_t field_0x40;              /* 0x40 - set to DAT_1482d96d8 in Release */
    uint32_t field_0x48;              /* 0x48 - set to DAT_1482d96e0 in Release */
    uint64_t field_0x4c;              /* 0x4c - set to DAT_1482d96d8 in Release */
    uint32_t field_0x54;              /* 0x54 - set to DAT_1482d96e0 in Release */
    uint64_t buffer_array_base;       /* 0x58 - base of buffer ptr array [Release] */
    uint64_t buffer_array_end;        /* 0x60 - end of buffer ptr array [Release] */
    uint8_t  pad_0x68[0x10];          /* 0x68 */
    uint64_t shadow_copy;             /* 0x78 - optional shadow buffer [CreateDataStream/Release] */
    uint64_t field_0x80;              /* 0x80 - written by FUN_14014a1b0 [CreateDataStream] */
    uint8_t  pad_0x88[0x70];          /* 0x88 */
    uint64_t field_0xf8;              /* 0xf8 - passed to FUN_14013f0a0 in Release loop */
    uint64_t field_0x100;             /* 0x100 - self-linked sentinel head [Release] */
    uint64_t field_0x108;             /* 0x108 - set to &field_0x100 in Release */
    uint64_t list_head;               /* 0x110 - intrusive list head [Release] */
    uint8_t  field_0x118;             /* 0x118 - byte flag, zeroed in Release */
    uint8_t  pad_0x119[0x07];         /* 0x119 */
    uint32_t field_0x120;             /* 0x120 - zeroed in Release */
    uint8_t  pad_0x124[0x04];         /* 0x124 */
    uint64_t allocator_vtable;        /* 0x128 - vtable for pool allocator [Release] */
} mmVertexDataStream_s3;
#pragma pack(pop)

static_assert(offsetof(mmVertexDataStream_s3, pad_0x00) == 0x00, "mmVertexDataStream.pad_0x00");
static_assert(offsetof(mmVertexDataStream_s3, parent_or_ref) == 0x08, "mmVertexDataStream.parent_or_ref");
static_assert(offsetof(mmVertexDataStream_s3, pad_0x10) == 0x10, "mmVertexDataStream.pad_0x10");
static_assert(offsetof(mmVertexDataStream_s3, vertex_layout_ptr) == 0x30, "mmVertexDataStream.vertex_layout_ptr");
static_assert(offsetof(mmVertexDataStream_s3, field_0x38) == 0x38, "mmVertexDataStream.field_0x38");
static_assert(offsetof(mmVertexDataStream_s3, field_0x40) == 0x40, "mmVertexDataStream.field_0x40");
static_assert(offsetof(mmVertexDataStream_s3, field_0x48) == 0x48, "mmVertexDataStream.field_0x48");
static_assert(offsetof(mmVertexDataStream_s3, field_0x4c) == 0x4c, "mmVertexDataStream.field_0x4c");
static_assert(offsetof(mmVertexDataStream_s3, field_0x54) == 0x54, "mmVertexDataStream.field_0x54");
static_assert(offsetof(mmVertexDataStream_s3, buffer_array_base) == 0x58, "mmVertexDataStream.buffer_array_base");
static_assert(offsetof(mmVertexDataStream_s3, buffer_array_end) == 0x60, "mmVertexDataStream.buffer_array_end");
static_assert(offsetof(mmVertexDataStream_s3, pad_0x68) == 0x68, "mmVertexDataStream.pad_0x68");
static_assert(offsetof(mmVertexDataStream_s3, shadow_copy) == 0x78, "mmVertexDataStream.shadow_copy");
static_assert(offsetof(mmVertexDataStream_s3, field_0x80) == 0x80, "mmVertexDataStream.field_0x80");
static_assert(offsetof(mmVertexDataStream_s3, pad_0x88) == 0x88, "mmVertexDataStream.pad_0x88");
static_assert(offsetof(mmVertexDataStream_s3, field_0xf8) == 0xf8, "mmVertexDataStream.field_0xf8");
static_assert(offsetof(mmVertexDataStream_s3, field_0x100) == 0x100, "mmVertexDataStream.field_0x100");
static_assert(offsetof(mmVertexDataStream_s3, field_0x108) == 0x108, "mmVertexDataStream.field_0x108");
static_assert(offsetof(mmVertexDataStream_s3, list_head) == 0x110, "mmVertexDataStream.list_head");
static_assert(offsetof(mmVertexDataStream_s3, field_0x118) == 0x118, "mmVertexDataStream.field_0x118");
static_assert(offsetof(mmVertexDataStream_s3, pad_0x119) == 0x119, "mmVertexDataStream.pad_0x119");
static_assert(offsetof(mmVertexDataStream_s3, field_0x120) == 0x120, "mmVertexDataStream.field_0x120");
static_assert(offsetof(mmVertexDataStream_s3, pad_0x124) == 0x124, "mmVertexDataStream.pad_0x124");
static_assert(offsetof(mmVertexDataStream_s3, allocator_vtable) == 0x128, "mmVertexDataStream.allocator_vtable");

#endif /* CMN34_S3_H */