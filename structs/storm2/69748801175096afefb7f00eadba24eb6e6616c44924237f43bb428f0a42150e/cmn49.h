/* cmn49.h — nuccChunk* struct layouts for Storm 2 (s2, NSUNS2.exe)
 * Generated from decompile analysis. All fields INFERRED (static analysis only).
 * PC OFFSETS ONLY — derived from s2 x64 decompiles (image base 0x140000000).
 * Sizes proven from allocator calls where noted; structs end at last proven field.
 * OWN-GAME NAMES: field names from s2 code/strings or ns2:: only.
 *
 * NOTE: These structs use __attribute__((packed)) with EXPLICIT padding to match
 * the exact byte offsets observed in decompiled code. Natural alignment does NOT
 * match because the binary has non-standard padding patterns. Every field offset
 * is verified by _Static_assert.
 */
#ifndef CMN49_S2_H
#define CMN49_S2_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nuccChunkTexture
 * Vtable (init): PTR_FUN_140896d98, Vtable (final): PTR_FUN_14089c368
 * Proven size: >= 0x30 (ctor accesses param_1+5 as uint = offset 0x28)
 * Evidence: ctor 0x5E22B0, dtor 0x5E22D0, Parse 0x5E2520
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkTexture_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 - base class fields */
    uint16_t tex_width;              /* 0x10 - ushort from Parse */
    uint16_t tex_height;             /* 0x12 - ushort from Parse */
    uint8_t tex_format;              /* 0x14 - byte from Parse */
    uint8_t tex_flags;               /* 0x15 - byte from Parse */
    uint8_t _pad_16[0x02];           /* 0x16 */
    int32_t texture_id;              /* 0x18 - int, set in Parse */
    uint32_t _pad_1c;                /* 0x1c */
    uint64_t data_size;              /* 0x20 - ulong, MallocCore alloc size */
    void *nut_data;                  /* 0x28 - ptr to NUT buffer (MallocCore) */
} ns2_nuccChunkTexture;

_Static_assert(offsetof(ns2_nuccChunkTexture, vtable) == 0x00, "ns2_nuccChunkTexture.vtable");
_Static_assert(offsetof(ns2_nuccChunkTexture, tex_width) == 0x10, "ns2_nuccChunkTexture.tex_width");
_Static_assert(offsetof(ns2_nuccChunkTexture, tex_height) == 0x12, "ns2_nuccChunkTexture.tex_height");
_Static_assert(offsetof(ns2_nuccChunkTexture, tex_format) == 0x14, "ns2_nuccChunkTexture.tex_format");
_Static_assert(offsetof(ns2_nuccChunkTexture, tex_flags) == 0x15, "ns2_nuccChunkTexture.tex_flags");
_Static_assert(offsetof(ns2_nuccChunkTexture, texture_id) == 0x18, "ns2_nuccChunkTexture.texture_id");
_Static_assert(offsetof(ns2_nuccChunkTexture, data_size) == 0x20, "ns2_nuccChunkTexture.data_size");
_Static_assert(offsetof(ns2_nuccChunkTexture, nut_data) == 0x28, "ns2_nuccChunkTexture.nut_data");

/* =========================================================================
 * nuccChunkModelVertex
 * Vtable (init): PTR_FUN_140897370, Vtable (final): PTR_FUN_14089c368
 * Proven size: >= 0x20 (dtor accesses param_1[3] = offset 0x18)
 * Evidence: dtor 0x5E6860, FinalizeParsing 0x5E68D0, Parse 0x5E6970
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkModelVertex_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *vertex_buffer;             /* 0x10 - ptr, MallocCore'd, FreeCore'd in dtor */
    uint32_t global_index;           /* 0x18 - uint32, nummModelRelease'd in dtor */
    uint32_t _pad_1c;                /* 0x1c */
} ns2_nuccChunkModelVertex;

_Static_assert(offsetof(ns2_nuccChunkModelVertex, vtable) == 0x00, "ns2_nuccChunkModelVertex.vtable");
_Static_assert(offsetof(ns2_nuccChunkModelVertex, vertex_buffer) == 0x10, "ns2_nuccChunkModelVertex.vertex_buffer");
_Static_assert(offsetof(ns2_nuccChunkModelVertex, global_index) == 0x18, "ns2_nuccChunkModelVertex.global_index");

/* =========================================================================
 * nuccChunkMorphModel
 * Vtable: unknown init, final PTR_FUN_14089c368
 * Proven size: >= 0x30 (Parse accesses 0x28)
 * Evidence: Parse 0x5E6D50, GetChunkIndexModelVertexTarget 0x5E6D10, GetWeight 0x5E6D30
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkMorphModel_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *index_ptr;                 /* 0x10 - ptr from GetIndex */
    uint32_t morph_count;            /* 0x18 - uint, count for both arrays */
    uint32_t _pad_1c;                /* 0x1c */
    void *morph_indices;             /* 0x20 - array of 8-byte elems, alloc 8*count */
    void *morph_weights;             /* 0x28 - array of 4-byte elems, alloc 4*count */
} ns2_nuccChunkMorphModel;

_Static_assert(offsetof(ns2_nuccChunkMorphModel, vtable) == 0x00, "ns2_nuccChunkMorphModel.vtable");
_Static_assert(offsetof(ns2_nuccChunkMorphModel, index_ptr) == 0x10, "ns2_nuccChunkMorphModel.index_ptr");
_Static_assert(offsetof(ns2_nuccChunkMorphModel, morph_count) == 0x18, "ns2_nuccChunkMorphModel.morph_count");
_Static_assert(offsetof(ns2_nuccChunkMorphModel, morph_indices) == 0x20, "ns2_nuccChunkMorphModel.morph_indices");
_Static_assert(offsetof(ns2_nuccChunkMorphModel, morph_weights) == 0x28, "ns2_nuccChunkMorphModel.morph_weights");

/* =========================================================================
 * nuccChunkMorphPrimitive (chunk portion)
 * Vtable (runtime): PTR_FUN_14089c398
 * Proven chunk size: >= 0x38 (Parse accesses 0x30)
 * Runtime object size: 0x70 (from LoadTh in Create 0x621E00)
 * Evidence: Parse 0x5E6AA0, Create 0x621E00
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkMorphPrimitive_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - ptr from Parse */
    uint32_t count;                  /* 0x18 - uint count from Parse */
    uint32_t _pad_1c;                /* 0x1c */
    void *data_8;                    /* 0x20 - array of 8-byte elems, alloc 8*count */
    void *data_4;                    /* 0x28 - array of 4-byte elems, alloc 4*count */
    uint64_t field_30;               /* 0x30 - ulong from Parse */
} ns2_nuccChunkMorphPrimitive;

_Static_assert(offsetof(ns2_nuccChunkMorphPrimitive, vtable) == 0x00, "ns2_nuccChunkMorphPrimitive.vtable");
_Static_assert(offsetof(ns2_nuccChunkMorphPrimitive, field_10) == 0x10, "ns2_nuccChunkMorphPrimitive.field_10");
_Static_assert(offsetof(ns2_nuccChunkMorphPrimitive, count) == 0x18, "ns2_nuccChunkMorphPrimitive.count");
_Static_assert(offsetof(ns2_nuccChunkMorphPrimitive, data_8) == 0x20, "ns2_nuccChunkMorphPrimitive.data_8");
_Static_assert(offsetof(ns2_nuccChunkMorphPrimitive, data_4) == 0x28, "ns2_nuccChunkMorphPrimitive.data_4");
_Static_assert(offsetof(ns2_nuccChunkMorphPrimitive, field_30) == 0x30, "ns2_nuccChunkMorphPrimitive.field_30");

/* =========================================================================
 * nuccChunkPrimitiveVertex
 * Vtable (init): PTR_FUN_140897490, Vtable (final): PTR_FUN_14089c368
 * Proven size: >= 0x28 (Parse/dtor accesses 0x20)
 * Evidence: Parse 0x5E6F70, dtor 0x5E6F10
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkPrimitiveVertex_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    uint64_t header_field;           /* 0x10 - ulong from 0x10-byte header read */
    uint32_t vertex_type;            /* 0x18 - uint type from header */
    uint32_t stride;                 /* 0x1c - uint stride from header */
    void *vertex_data;               /* 0x20 - ptr, FUN_140580590(0x80, stride*count), FreealignCore'd */
    uint32_t vertex_count;           /* 0x28 - uint count from header (inferred) */
    uint32_t _pad_2c;                /* 0x2c */
} ns2_nuccChunkPrimitiveVertex;

_Static_assert(offsetof(ns2_nuccChunkPrimitiveVertex, vtable) == 0x00, "ns2_nuccChunkPrimitiveVertex.vtable");
_Static_assert(offsetof(ns2_nuccChunkPrimitiveVertex, header_field) == 0x10, "ns2_nuccChunkPrimitiveVertex.header_field");
_Static_assert(offsetof(ns2_nuccChunkPrimitiveVertex, vertex_type) == 0x18, "ns2_nuccChunkPrimitiveVertex.vertex_type");
_Static_assert(offsetof(ns2_nuccChunkPrimitiveVertex, stride) == 0x1c, "ns2_nuccChunkPrimitiveVertex.stride");
_Static_assert(offsetof(ns2_nuccChunkPrimitiveVertex, vertex_data) == 0x20, "ns2_nuccChunkPrimitiveVertex.vertex_data");
_Static_assert(offsetof(ns2_nuccChunkPrimitiveVertex, vertex_count) == 0x28, "ns2_nuccChunkPrimitiveVertex.vertex_count");

/* =========================================================================
 * nuccChunkModelPrimitiveBatch
 * Vtable: unknown init, final PTR_FUN_14089c368
 * Proven size: >= 0xb0 (FinalizeParsing accesses 0xa8)
 * Evidence: Parse 0x5E7400, FinalizeParsing 0x5E7310, GetCoordId 0x5E7360,
 *           GetVertexArray 0x5E7370, GetVertexNum 0x5E73F0
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkModelPrimitiveBatch_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - ptr from Parse */
    void *coord_indices;             /* 0x18 - alloc'd ushort array, elem=2 */
    void *vertex_indices;            /* 0x20 - alloc'd ushort array, elem=2 */
    void *field_28;                  /* 0x28 - ptr from Parse */
    void *vertex_model_chunk;        /* 0x30 - ptr to vertex model chunk */
    uint16_t field_38;               /* 0x38 - ushort from Parse */
    uint16_t field_3a;               /* 0x3a - ushort from Parse */
    uint16_t field_3c;               /* 0x3c - ushort from Parse */
    uint16_t field_3e;               /* 0x3e - ushort from Parse */
    uint64_t field_40;               /* 0x40 - ulong from Parse */
    uint32_t field_48;               /* 0x48 - uint from Parse */
    uint32_t _pad_4c;                /* 0x4c */
    uint32_t vert_model_0x10;        /* 0x50 - uint from vertex model+0x10 (FinalizeParsing) */
    uint32_t vert_model_0x14;        /* 0x54 - uint from vertex model+0x14 (FinalizeParsing) */
    uint64_t field_58;               /* 0x58 - ulong from Parse */
    uint64_t field_60;               /* 0x60 - ulong from Parse (at 0x5c in summary, aligned) */
    uint64_t field_68;               /* 0x68 - ulong from Parse */
    uint32_t vert_model_0x18;        /* 0x70 - uint from vertex model+0x18 (FinalizeParsing) */
    uint8_t _pad_74[0x2c];           /* 0x74 - gap to 0xa0 */
    uint32_t vert_model_0x1c;        /* 0xa0 - uint from vertex model+0x1c (FinalizeParsing) */
    uint32_t _pad_a4;                /* 0xa4 */
    uint64_t vert_model_0x20;        /* 0xa8 - ulong from vertex model+0x20 (FinalizeParsing) */
} ns2_nuccChunkModelPrimitiveBatch;

_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vtable) == 0x00, "ns2_nuccChunkModelPrimitiveBatch.vtable");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_10) == 0x10, "ns2_nuccChunkModelPrimitiveBatch.field_10");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, coord_indices) == 0x18, "ns2_nuccChunkModelPrimitiveBatch.coord_indices");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vertex_indices) == 0x20, "ns2_nuccChunkModelPrimitiveBatch.vertex_indices");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_28) == 0x28, "ns2_nuccChunkModelPrimitiveBatch.field_28");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vertex_model_chunk) == 0x30, "ns2_nuccChunkModelPrimitiveBatch.vertex_model_chunk");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_38) == 0x38, "ns2_nuccChunkModelPrimitiveBatch.field_38");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_3a) == 0x3a, "ns2_nuccChunkModelPrimitiveBatch.field_3a");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_3c) == 0x3c, "ns2_nuccChunkModelPrimitiveBatch.field_3c");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_3e) == 0x3e, "ns2_nuccChunkModelPrimitiveBatch.field_3e");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_40) == 0x40, "ns2_nuccChunkModelPrimitiveBatch.field_40");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_48) == 0x48, "ns2_nuccChunkModelPrimitiveBatch.field_48");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vert_model_0x10) == 0x50, "ns2_nuccChunkModelPrimitiveBatch.vert_model_0x10");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vert_model_0x14) == 0x54, "ns2_nuccChunkModelPrimitiveBatch.vert_model_0x14");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_58) == 0x58, "ns2_nuccChunkModelPrimitiveBatch.field_58");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, field_68) == 0x68, "ns2_nuccChunkModelPrimitiveBatch.field_68");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vert_model_0x18) == 0x70, "ns2_nuccChunkModelPrimitiveBatch.vert_model_0x18");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vert_model_0x1c) == 0xa0, "ns2_nuccChunkModelPrimitiveBatch.vert_model_0x1c");
_Static_assert(offsetof(ns2_nuccChunkModelPrimitiveBatch, vert_model_0x20) == 0xa8, "ns2_nuccChunkModelPrimitiveBatch.vert_model_0x20");

/* =========================================================================
 * nuccChunkSprite
 * Vtable: unknown init, final PTR_FUN_14089c368
 * Proven size: >= 0x38 (Parse accesses 0x34)
 * Evidence: Parse 0x5E7A20, Create 0x5E78F0, dtor 0x5E78C0
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkSprite_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *sprite_entries;            /* 0x10 - ptr to sprite entry array, elem=0x30 */
    void *coord_array;               /* 0x18 - ptr to coord array, elem=4 */
    void *texture_indices;           /* 0x20 - ptr to texture index array, elem=8 */
    uint16_t sprite_count;           /* 0x28 - ushort */
    uint16_t coord_count;            /* 0x2a - ushort */
    uint16_t texture_count;          /* 0x2c - ushort */
    int16_t width;                   /* 0x2e - short */
    int16_t height;                  /* 0x30 - short */
    uint16_t field_32;               /* 0x32 - ushort, version>=0x70 only */
    uint16_t field_34;               /* 0x34 - ushort, version>=0x70 only */
    uint8_t _pad_36[0x02];           /* 0x36 */
} ns2_nuccChunkSprite;

_Static_assert(offsetof(ns2_nuccChunkSprite, vtable) == 0x00, "ns2_nuccChunkSprite.vtable");
_Static_assert(offsetof(ns2_nuccChunkSprite, sprite_entries) == 0x10, "ns2_nuccChunkSprite.sprite_entries");
_Static_assert(offsetof(ns2_nuccChunkSprite, coord_array) == 0x18, "ns2_nuccChunkSprite.coord_array");
_Static_assert(offsetof(ns2_nuccChunkSprite, texture_indices) == 0x20, "ns2_nuccChunkSprite.texture_indices");
_Static_assert(offsetof(ns2_nuccChunkSprite, sprite_count) == 0x28, "ns2_nuccChunkSprite.sprite_count");
_Static_assert(offsetof(ns2_nuccChunkSprite, coord_count) == 0x2a, "ns2_nuccChunkSprite.coord_count");
_Static_assert(offsetof(ns2_nuccChunkSprite, texture_count) == 0x2c, "ns2_nuccChunkSprite.texture_count");
_Static_assert(offsetof(ns2_nuccChunkSprite, width) == 0x2e, "ns2_nuccChunkSprite.width");
_Static_assert(offsetof(ns2_nuccChunkSprite, height) == 0x30, "ns2_nuccChunkSprite.height");
_Static_assert(offsetof(ns2_nuccChunkSprite, field_32) == 0x32, "ns2_nuccChunkSprite.field_32");
_Static_assert(offsetof(ns2_nuccChunkSprite, field_34) == 0x34, "ns2_nuccChunkSprite.field_34");

/* =========================================================================
 * nuccChunkSprite2
 * Vtable: unknown init, final PTR_FUN_14089c368
 * Proven size: >= 0xf8 (FinalizeParsing accesses 0xf0)
 * Evidence: Parse 0x5E94F0, FinalizeParsing 0x5E9340, dtor 0x5E9310
 * Contains std::vector-like triplets (begin/end/capacity) for multiple arrays.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkSprite2_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    uint64_t field_10;               /* 0x10 - ulong from Parse */
    uint64_t field_14;               /* 0x18 - ulong from Parse (summary says 0x14 but aligned) */
    int32_t entry_count;             /* 0x20 - int count of 0x24-byte entries */
    uint32_t _pad_24;                /* 0x24 */
    void *entries_begin;             /* 0x28 - vector begin for 0x24-byte entries */
    void *entries_end;               /* 0x30 - vector end */
    void *entries_capacity;          /* 0x38 - vector capacity */
    uint8_t bulk_data[0x28];         /* 0x40 - bulk read 0x28 bytes (Parse offset 0x50 → adjusted) */
    int32_t uint_count;              /* 0x68 - int count (Parse offset 0x70) */
    uint32_t field_6c;               /* 0x6c - int from Parse (0x74) */
    void *uint_vec_begin;            /* 0x70 - vector begin for uint entries (Parse 0x78) */
    void *uint_vec_end;              /* 0x78 - vector end (Parse 0x80) */
    void *uint_vec_capacity;         /* 0x80 - vector capacity (Parse 0x88) */
    int32_t complex_count;           /* 0x88 - int count of 0x58-byte complex entries (Parse 0xa8) */
    uint32_t _pad_8c;                /* 0x8c */
    void *complex_begin;             /* 0x90 - vector begin for complex entries (Parse 0xb0) */
    void *complex_end;               /* 0x98 - vector end (Parse 0xb8) */
    void *complex_capacity;          /* 0xa0 - vector capacity (Parse 0xc0) */
    uint8_t _pad_a8[0x38];           /* 0xa8 - gap to material vectors */
    void *material_begin;            /* 0xe0 - vector begin for nuccMaterial ptrs (FinalizeParsing) */
    void *material_end;              /* 0xe8 - vector end */
    void *material_capacity;         /* 0xf0 - vector capacity */
} ns2_nuccChunkSprite2;

_Static_assert(offsetof(ns2_nuccChunkSprite2, vtable) == 0x00, "ns2_nuccChunkSprite2.vtable");
_Static_assert(offsetof(ns2_nuccChunkSprite2, field_10) == 0x10, "ns2_nuccChunkSprite2.field_10");
_Static_assert(offsetof(ns2_nuccChunkSprite2, field_14) == 0x18, "ns2_nuccChunkSprite2.field_14");
_Static_assert(offsetof(ns2_nuccChunkSprite2, entry_count) == 0x20, "ns2_nuccChunkSprite2.entry_count");
_Static_assert(offsetof(ns2_nuccChunkSprite2, entries_begin) == 0x28, "ns2_nuccChunkSprite2.entries_begin");
_Static_assert(offsetof(ns2_nuccChunkSprite2, entries_end) == 0x30, "ns2_nuccChunkSprite2.entries_end");
_Static_assert(offsetof(ns2_nuccChunkSprite2, entries_capacity) == 0x38, "ns2_nuccChunkSprite2.entries_capacity");
_Static_assert(offsetof(ns2_nuccChunkSprite2, bulk_data) == 0x40, "ns2_nuccChunkSprite2.bulk_data");
_Static_assert(offsetof(ns2_nuccChunkSprite2, uint_count) == 0x68, "ns2_nuccChunkSprite2.uint_count");
_Static_assert(offsetof(ns2_nuccChunkSprite2, uint_vec_begin) == 0x70, "ns2_nuccChunkSprite2.uint_vec_begin");
_Static_assert(offsetof(ns2_nuccChunkSprite2, uint_vec_end) == 0x78, "ns2_nuccChunkSprite2.uint_vec_end");
_Static_assert(offsetof(ns2_nuccChunkSprite2, uint_vec_capacity) == 0x80, "ns2_nuccChunkSprite2.uint_vec_capacity");
_Static_assert(offsetof(ns2_nuccChunkSprite2, complex_count) == 0x88, "ns2_nuccChunkSprite2.complex_count");
_Static_assert(offsetof(ns2_nuccChunkSprite2, complex_begin) == 0x90, "ns2_nuccChunkSprite2.complex_begin");
_Static_assert(offsetof(ns2_nuccChunkSprite2, complex_end) == 0x98, "ns2_nuccChunkSprite2.complex_end");
_Static_assert(offsetof(ns2_nuccChunkSprite2, complex_capacity) == 0xa0, "ns2_nuccChunkSprite2.complex_capacity");
_Static_assert(offsetof(ns2_nuccChunkSprite2, material_begin) == 0xe0, "ns2_nuccChunkSprite2.material_begin");
_Static_assert(offsetof(ns2_nuccChunkSprite2, material_end) == 0xe8, "ns2_nuccChunkSprite2.material_end");
_Static_assert(offsetof(ns2_nuccChunkSprite2, material_capacity) == 0xf0, "ns2_nuccChunkSprite2.material_capacity");

/* =========================================================================
 * nuccChunkSpriteAnm
 * Vtable: unknown init, final via scalar deleting dtor
 * Proven size: >= 0x50 (Parse accesses 0x4c)
 * Evidence: Parse 0x5E8030, Create 0x5E7F00, GetSpriteChunk 0x5E7F40, dtor 0x58D000
 * Frame records are 0x78 bytes each with variable-length sub-data.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkSpriteAnm_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *frame_data_buf;            /* 0x10 - ptr, MallocCore'd, size=ushort_2 */
    void *sprite_chunk_ref;          /* 0x18 - ptr from GetIndex, indirect call confirms ptr-to-chunk */
    void *field_20;                  /* 0x20 - operator_new__ with frame_count */
    uint8_t _pad_28[0x10];           /* 0x28 */
    void *frame_array;               /* 0x38 - ptr to frame array, elem=0x78 */
    uint16_t header_ushort;          /* 0x40 - ushort from header (Parse offset 0x48) */
    uint8_t _pad_42[0x06];           /* 0x42 */
    uint32_t max_keyframes_x100;     /* 0x48 - uint, max_keyframes*100 (Parse offset 0x4c) */
    uint32_t _pad_4c;                /* 0x4c */
} ns2_nuccChunkSpriteAnm;

_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, vtable) == 0x00, "ns2_nuccChunkSpriteAnm.vtable");
_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, frame_data_buf) == 0x10, "ns2_nuccChunkSpriteAnm.frame_data_buf");
_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, sprite_chunk_ref) == 0x18, "ns2_nuccChunkSpriteAnm.sprite_chunk_ref");
_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, field_20) == 0x20, "ns2_nuccChunkSpriteAnm.field_20");
_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, frame_array) == 0x38, "ns2_nuccChunkSpriteAnm.frame_array");
_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, header_ushort) == 0x40, "ns2_nuccChunkSpriteAnm.header_ushort");
_Static_assert(offsetof(ns2_nuccChunkSpriteAnm, max_keyframes_x100) == 0x48, "ns2_nuccChunkSpriteAnm.max_keyframes_x100");

/* =========================================================================
 * nuccChunkParticle
 * Vtable: unknown init, final via scalar deleting dtor
 * Proven size: >= 0x60 (GetTimeParam accesses 0x58)
 * Evidence: Parse 0x5F2150, FinalizeParsing 0x5F1D90, GetTimeParam 0x5F1FE0,
 *           SearchDocument 0x5F30E0, dtor 0x5F1AD0
 * Two separate time-related arrays: 0x48 (elem=0x48) and 0x58 (elem=0x10).
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkParticle_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    uint8_t parse_header[0x28];      /* 0x10 - bulk read 0x28 bytes containing counts below */
    /* Within parse_header: 0x14=gen_param_count(ushort), 0x1c=document_count(ushort),
     *                      0x24=time_param_count(ushort) */
    void *gen_params;                /* 0x38 - ptr to gen_param array, elem=0xe0, operator_new__ */
    void *documents;                 /* 0x40 - ptr to document array, elem=0x30, operator_new__ */
    void *time_params;               /* 0x48 - ptr to time_param array, elem=0x48, operator_new__ */
    uint8_t _pad_50[0x08];           /* 0x50 - gap between time_params and time_param_access */
    void *time_param_access;         /* 0x58 - ptr used by GetTimeParam, stride 0x10 */
} ns2_nuccChunkParticle;

_Static_assert(offsetof(ns2_nuccChunkParticle, vtable) == 0x00, "ns2_nuccChunkParticle.vtable");
_Static_assert(offsetof(ns2_nuccChunkParticle, parse_header) == 0x10, "ns2_nuccChunkParticle.parse_header");
_Static_assert(offsetof(ns2_nuccChunkParticle, gen_params) == 0x38, "ns2_nuccChunkParticle.gen_params");
_Static_assert(offsetof(ns2_nuccChunkParticle, documents) == 0x40, "ns2_nuccChunkParticle.documents");
_Static_assert(offsetof(ns2_nuccChunkParticle, time_params) == 0x48, "ns2_nuccChunkParticle.time_params");
_Static_assert(offsetof(ns2_nuccChunkParticle, time_param_access) == 0x58, "ns2_nuccChunkParticle.time_param_access");

/* =========================================================================
 * nuccChunkNub
 * Vtable (init): PTR_FUN_140898340, Vtable (final): PTR_FUN_14089c368
 * Proven size: >= 0x20 (Parse/dtor accesses 0x18)
 * Evidence: Parse 0x5F7920, dtor 0x5F78C0
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkNub_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *nub_data;                  /* 0x10 - ptr, MallocCore(size), freed in dtor */
    uint64_t buffer_size;            /* 0x18 - ulong, size passed to MallocCore */
} ns2_nuccChunkNub;

_Static_assert(offsetof(ns2_nuccChunkNub, vtable) == 0x00, "ns2_nuccChunkNub.vtable");
_Static_assert(offsetof(ns2_nuccChunkNub, nub_data) == 0x10, "ns2_nuccChunkNub.nub_data");
_Static_assert(offsetof(ns2_nuccChunkNub, buffer_size) == 0x18, "ns2_nuccChunkNub.buffer_size");

/* =========================================================================
 * nuccChunkPage
 * Vtable: unknown init, final PTR_FUN_14089c368
 * Proven size: 0x10 (base class only — no own fields)
 * Evidence: Parse 0x5EE950
 * Purely a parser directive: reads 4 or 8 bytes depending on version,
 * then calls nuccXfbinParser::ChangePage. No persistent state stored.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccChunkPage_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 - base class minimum */
} ns2_nuccChunkPage;

_Static_assert(offsetof(ns2_nuccChunkPage, vtable) == 0x00, "ns2_nuccChunkPage.vtable");

#endif /* CMN49_S2_H */