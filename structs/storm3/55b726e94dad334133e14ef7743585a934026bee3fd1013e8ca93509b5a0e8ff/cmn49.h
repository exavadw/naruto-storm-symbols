/* cmn49.h — nuccChunk struct layouts for Storm 3 Full Burst HD (s3, NSUNS3.exe x64)
 * Generated 2026-10-19 from the decompiler cache symbolized decompilation cache.
 * All fields INFERRED from static analysis. Sizes proven from allocator calls.
 * Prefix ns3_ (own-game names rule).
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ── nuccChunkTexture ─────────────────────────────────────────────── */
/* Size ≥ 0x30: ctor writes param_1+5 (uint at 0x28), dtor frees param_1[4] */
typedef struct __attribute__((packed)) {
    uint64_t vtable;          /* 0x00 PRES init=PTR_FUN_1409e5888, final=PTR_FUN_1409e9f98 */
    uint8_t  _pad_08[8];      /* 0x08 UNKNOWN base class fields */
    uint16_t tex_width;       /* 0x10 SIM Parse reads ushort, endian-swapped */
    uint16_t tex_height;      /* 0x12 SIM Parse reads ushort, endian-swapped */
    uint8_t  tex_format;      /* 0x14 SIM Parse reads byte (local_f8[0]) */
    uint8_t  tex_flags;       /* 0x15 SIM Parse reads byte (bVar1 = mipmap count) */
    uint8_t  _pad_16[2];      /* 0x16 UNKNOWN alignment */
    int32_t  texture_id;      /* 0x18 SIM Parse sets int, dtor checks ==1 for Release */
    uint8_t  _pad_1c[4];      /* 0x1c UNKNOWN alignment */
    uint64_t data_size;       /* 0x20 SIM MallocCore size arg (local_f0 after swap) */
    uint64_t nut_data;        /* 0x28 PRES MallocCore return stored at param_1[4], freed in dtor */
} ns3_nuccChunkTexture;
_Static_assert(offsetof(ns3_nuccChunkTexture, vtable)     == 0x00, "Texture.vtable");
_Static_assert(offsetof(ns3_nuccChunkTexture, tex_width)   == 0x10, "Texture.tex_width");
_Static_assert(offsetof(ns3_nuccChunkTexture, tex_height)  == 0x12, "Texture.tex_height");
_Static_assert(offsetof(ns3_nuccChunkTexture, tex_format)  == 0x14, "Texture.tex_format");
_Static_assert(offsetof(ns3_nuccChunkTexture, tex_flags)   == 0x15, "Texture.tex_flags");
_Static_assert(offsetof(ns3_nuccChunkTexture, texture_id)  == 0x18, "Texture.texture_id");
_Static_assert(offsetof(ns3_nuccChunkTexture, data_size)   == 0x20, "Texture.data_size");
_Static_assert(offsetof(ns3_nuccChunkTexture, nut_data)    == 0x28, "Texture.nut_data");

/* ── nuccChunkModelVertex ─────────────────────────────────────────── */
/* Size ≥ 0x20: dtor accesses param_1[3] (offset 0x18), Parse stores ptr at +0x10 */
typedef struct __attribute__((packed)) {
    uint64_t vtable;          /* 0x00 PRES */
    uint8_t  _pad_08[8];      /* 0x08 UNKNOWN base class */
    uint64_t vertex_buffer;   /* 0x10 PRES MallocCore'd in Parse, FreeCore'd in dtor */
    uint32_t global_index;    /* 0x18 SIM nummModelRelease'd in dtor */
    uint8_t  _pad_1c[4];      /* 0x1c UNKNOWN alignment */
} ns3_nuccChunkModelVertex;
_Static_assert(offsetof(ns3_nuccChunkModelVertex, vtable)        == 0x00, "ModelVertex.vtable");
_Static_assert(offsetof(ns3_nuccChunkModelVertex, vertex_buffer)  == 0x10, "ModelVertex.vertex_buffer");
_Static_assert(offsetof(ns3_nuccChunkModelVertex, global_index)   == 0x18, "ModelVertex.global_index");

/* ── nuccChunkMorphModel ──────────────────────────────────────────── */
/* Size ≥ 0x30: Parse accesses 0x28 (morph_weights ptr) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;          /* 0x00 PRES */
    uint8_t  _pad_08[8];      /* 0x08 UNKNOWN base class */
    uint64_t index_ptr;       /* 0x10 SIM GetIndex result stored */
    uint32_t morph_count;     /* 0x18 SIM count for both arrays */
    uint8_t  _pad_1c[4];      /* 0x1c UNKNOWN alignment */
    uint64_t morph_indices;   /* 0x20 PRES array of 8-byte elems, alloc 8*count */
    uint64_t morph_weights;   /* 0x28 PRES array of 4-byte elems, alloc 4*count */
} ns3_nuccChunkMorphModel;
_Static_assert(offsetof(ns3_nuccChunkMorphModel, vtable)        == 0x00, "MorphModel.vtable");
_Static_assert(offsetof(ns3_nuccChunkMorphModel, index_ptr)     == 0x10, "MorphModel.index_ptr");
_Static_assert(offsetof(ns3_nuccChunkMorphModel, morph_count)   == 0x18, "MorphModel.morph_count");
_Static_assert(offsetof(ns3_nuccChunkMorphModel, morph_indices) == 0x20, "MorphModel.morph_indices");
_Static_assert(offsetof(ns3_nuccChunkMorphModel, morph_weights) == 0x28, "MorphModel.morph_weights");

/* ── nuccChunkSprite ──────────────────────────────────────────────── */
/* Size ≥ 0x38: Parse accesses 0x34 (version>=0x70 field) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;           /* 0x00 PRES */
    uint8_t  _pad_08[8];       /* 0x08 UNKNOWN base class */
    uint64_t sprite_entries;   /* 0x10 PRES array of 0x30-byte entries, operator_new__ */
    uint64_t coord_array;      /* 0x18 PRES array of 4-byte coords, operator_new__ */
    uint64_t texture_indices;  /* 0x20 PRES array of 8-byte texture indices */
    uint16_t sprite_count;     /* 0x28 SIM Parse reads ushort (local_34) */
    uint16_t coord_count;      /* 0x2a SIM Parse reads ushort (local_32) */
    uint16_t texture_count;    /* 0x2c SIM Parse reads ushort (local_30) */
    int16_t  width;            /* 0x2e SIM Parse reads short */
    int16_t  height;           /* 0x30 SIM Parse reads short */
    uint16_t field_32;         /* 0x32 SIM version>=0x70 only */
    uint16_t field_34;         /* 0x34 SIM version>=0x70 only */
    uint8_t  _pad_36[2];       /* 0x36 UNKNOWN alignment */
} ns3_nuccChunkSprite;
_Static_assert(offsetof(ns3_nuccChunkSprite, vtable)          == 0x00, "Sprite.vtable");
_Static_assert(offsetof(ns3_nuccChunkSprite, sprite_entries)   == 0x10, "Sprite.sprite_entries");
_Static_assert(offsetof(ns3_nuccChunkSprite, coord_array)      == 0x18, "Sprite.coord_array");
_Static_assert(offsetof(ns3_nuccChunkSprite, texture_indices)  == 0x20, "Sprite.texture_indices");
_Static_assert(offsetof(ns3_nuccChunkSprite, sprite_count)     == 0x28, "Sprite.sprite_count");
_Static_assert(offsetof(ns3_nuccChunkSprite, coord_count)      == 0x2a, "Sprite.coord_count");
_Static_assert(offsetof(ns3_nuccChunkSprite, texture_count)    == 0x2c, "Sprite.texture_count");
_Static_assert(offsetof(ns3_nuccChunkSprite, width)            == 0x2e, "Sprite.width");
_Static_assert(offsetof(ns3_nuccChunkSprite, height)           == 0x30, "Sprite.height");
_Static_assert(offsetof(ns3_nuccChunkSprite, field_32)         == 0x32, "Sprite.field_32");
_Static_assert(offsetof(ns3_nuccChunkSprite, field_34)         == 0x34, "Sprite.field_34");

/* ── nuccChunkSprite2 ─────────────────────────────────────────────── */
/* Size ≥ 0xf8: FinalizeParsing accesses 0xf0 (material_capacity) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;             /* 0x00 PRES */
    uint8_t  _pad_08[8];         /* 0x08 UNKNOWN base class */
    uint64_t field_10;           /* 0x10 SIM Parse reads ulong */
    uint64_t field_18;           /* 0x18 SIM Parse reads ulong */
    int32_t  entry_count;        /* 0x20 SIM count of 0x24-byte entries */
    uint8_t  _pad_24[4];         /* 0x24 UNKNOWN alignment */
    uint64_t entries_begin;      /* 0x28 PRES vector begin for 0x24-byte entries */
    uint64_t entries_end;        /* 0x30 PRES vector end */
    uint64_t entries_capacity;   /* 0x38 PRES vector capacity */
    uint8_t  bulk_data[40];      /* 0x40 SIM bulk read 0x28 bytes from Parse */
    int32_t  uint_count;         /* 0x68 SIM count for uint vector */
    uint32_t field_6c;           /* 0x6c SIM Parse reads int */
    uint64_t uint_vec_begin;     /* 0x70 PRES vector begin for uint entries */
    uint64_t uint_vec_end;       /* 0x78 PRES vector end */
    uint64_t uint_vec_capacity;  /* 0x80 PRES vector capacity */
    int32_t  complex_count;      /* 0x88 SIM count of 0x58-byte complex entries */
    uint8_t  _pad_8c[4];         /* 0x8c UNKNOWN alignment */
    uint64_t complex_begin;      /* 0x90 PRES vector begin for complex entries */
    uint64_t complex_end;        /* 0x98 PRES vector end */
    uint64_t complex_capacity;   /* 0xa0 PRES vector capacity */
    uint8_t  _pad_a8[56];        /* 0xa8 UNKNOWN gap to material vectors */
    uint64_t material_begin;     /* 0xe0 PRES vector begin for nuccMaterial ptrs */
    uint64_t material_end;       /* 0xe8 PRES vector end */
    uint64_t material_capacity;  /* 0xf0 PRES vector capacity */
} ns3_nuccChunkSprite2;
_Static_assert(offsetof(ns3_nuccChunkSprite2, vtable)            == 0x00, "Sprite2.vtable");
_Static_assert(offsetof(ns3_nuccChunkSprite2, field_10)           == 0x10, "Sprite2.field_10");
_Static_assert(offsetof(ns3_nuccChunkSprite2, field_18)           == 0x18, "Sprite2.field_18");
_Static_assert(offsetof(ns3_nuccChunkSprite2, entry_count)        == 0x20, "Sprite2.entry_count");
_Static_assert(offsetof(ns3_nuccChunkSprite2, entries_begin)      == 0x28, "Sprite2.entries_begin");
_Static_assert(offsetof(ns3_nuccChunkSprite2, entries_end)        == 0x30, "Sprite2.entries_end");
_Static_assert(offsetof(ns3_nuccChunkSprite2, entries_capacity)   == 0x38, "Sprite2.entries_capacity");
_Static_assert(offsetof(ns3_nuccChunkSprite2, bulk_data)          == 0x40, "Sprite2.bulk_data");
_Static_assert(offsetof(ns3_nuccChunkSprite2, uint_count)         == 0x68, "Sprite2.uint_count");
_Static_assert(offsetof(ns3_nuccChunkSprite2, field_6c)           == 0x6c, "Sprite2.field_6c");
_Static_assert(offsetof(ns3_nuccChunkSprite2, uint_vec_begin)     == 0x70, "Sprite2.uint_vec_begin");
_Static_assert(offsetof(ns3_nuccChunkSprite2, uint_vec_end)       == 0x78, "Sprite2.uint_vec_end");
_Static_assert(offsetof(ns3_nuccChunkSprite2, uint_vec_capacity)  == 0x80, "Sprite2.uint_vec_capacity");
_Static_assert(offsetof(ns3_nuccChunkSprite2, complex_count)      == 0x88, "Sprite2.complex_count");
_Static_assert(offsetof(ns3_nuccChunkSprite2, complex_begin)      == 0x90, "Sprite2.complex_begin");
_Static_assert(offsetof(ns3_nuccChunkSprite2, complex_end)        == 0x98, "Sprite2.complex_end");
_Static_assert(offsetof(ns3_nuccChunkSprite2, complex_capacity)   == 0xa0, "Sprite2.complex_capacity");
_Static_assert(offsetof(ns3_nuccChunkSprite2, material_begin)     == 0xe0, "Sprite2.material_begin");
_Static_assert(offsetof(ns3_nuccChunkSprite2, material_end)       == 0xe8, "Sprite2.material_end");
_Static_assert(offsetof(ns3_nuccChunkSprite2, material_capacity)  == 0xf0, "Sprite2.material_capacity");

/* ── nuccChunkSpriteAnm ───────────────────────────────────────────── */
/* Size ≥ 0x50: Parse accesses 0x4c (max_keyframes_x100) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;              /* 0x00 PRES final via scalar deleting dtor */
    uint8_t  _pad_08[8];          /* 0x08 UNKNOWN base class */
    uint64_t frame_data_buf;      /* 0x10 PRES MallocCore'd, size=ushort_2 */
    uint64_t sprite_chunk_ref;    /* 0x18 PRES GetIndex result, indirect call confirms ptr-to-chunk */
    uint64_t field_20;            /* 0x20 SIM operator_new__ with frame_count */
    uint8_t  _pad_28[16];         /* 0x28 UNKNOWN gap to frame_array */
    uint64_t frame_array;         /* 0x38 PRES array of 0x78-byte frame records */
    uint16_t header_ushort;       /* 0x40 SIM from Parse header */
    uint8_t  _pad_42[6];          /* 0x42 UNKNOWN alignment */
    uint32_t max_keyframes_x100;  /* 0x48 SIM max_keyframes*100 from Parse */
    uint8_t  _pad_4c[4];          /* 0x4c UNKNOWN alignment */
} ns3_nuccChunkSpriteAnm;
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, vtable)              == 0x00, "SpriteAnm.vtable");
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, frame_data_buf)      == 0x10, "SpriteAnm.frame_data_buf");
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, sprite_chunk_ref)    == 0x18, "SpriteAnm.sprite_chunk_ref");
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, field_20)            == 0x20, "SpriteAnm.field_20");
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, frame_array)         == 0x38, "SpriteAnm.frame_array");
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, header_ushort)       == 0x40, "SpriteAnm.header_ushort");
_Static_assert(offsetof(ns3_nuccChunkSpriteAnm, max_keyframes_x100)  == 0x48, "SpriteAnm.max_keyframes_x100");

/* ── nuccChunkParticle ────────────────────────────────────────────── */
/* Size ≥ 0x60: GetTimeParam accesses 0x58 (time_param_access ptr) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;              /* 0x00 PRES final via scalar deleting dtor */
    uint8_t  _pad_08[8];          /* 0x08 UNKNOWN base class */
    uint8_t  parse_header[40];    /* 0x10 SIM bulk read 0x28 bytes with counts */
    uint64_t gen_params;          /* 0x38 PRES array of 0xe0-byte gen params, operator_new__ */
    uint64_t documents;           /* 0x40 PRES array of 0x30-byte documents, operator_new__ */
    uint64_t time_params;         /* 0x48 PRES array of 0x48-byte time params, operator_new__ */
    uint8_t  _pad_50[8];          /* 0x50 UNKNOWN gap between time_params and time_param_access */
    uint64_t time_param_access;   /* 0x58 PRES GetTimeParam uses stride 0x10 on this ptr */
} ns3_nuccChunkParticle;
_Static_assert(offsetof(ns3_nuccChunkParticle, vtable)              == 0x00, "Particle.vtable");
_Static_assert(offsetof(ns3_nuccChunkParticle, parse_header)       == 0x10, "Particle.parse_header");
_Static_assert(offsetof(ns3_nuccChunkParticle, gen_params)          == 0x38, "Particle.gen_params");
_Static_assert(offsetof(ns3_nuccChunkParticle, documents)           == 0x40, "Particle.documents");
_Static_assert(offsetof(ns3_nuccChunkParticle, time_params)         == 0x48, "Particle.time_params");
_Static_assert(offsetof(ns3_nuccChunkParticle, time_param_access)   == 0x58, "Particle.time_param_access");

/* ── nuccChunkModelPrimitiveBatch ─────────────────────────────────── */
/* Size ≥ 0xb0: FinalizeParsing accesses 0xa8 (vert_model_0x20) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;              /* 0x00 PRES */
    uint8_t  _pad_08[8];          /* 0x08 UNKNOWN base class */
    uint64_t field_10;            /* 0x10 SIM Parse stores ptr */
    uint64_t coord_indices;       /* 0x18 PRES alloc'd ushort array, elem=2 */
    uint64_t vertex_indices;      /* 0x20 PRES alloc'd ushort array, elem=2 */
    uint64_t field_28;            /* 0x28 SIM Parse stores ptr */
    uint64_t vertex_model_chunk;  /* 0x30 PRES ptr to vertex model chunk */
    uint16_t field_38;            /* 0x38 SIM Parse reads ushort */
    uint16_t field_3a;            /* 0x3a SIM Parse reads ushort */
    uint16_t field_3c;            /* 0x3c SIM Parse reads ushort */
    uint16_t field_3e;            /* 0x3e SIM Parse reads ushort */
    uint64_t field_40;            /* 0x40 SIM Parse reads ulong */
    uint32_t field_48;            /* 0x48 SIM Parse reads uint */
    uint8_t  _pad_4c[4];          /* 0x4c UNKNOWN alignment */
    uint32_t vert_model_0x10;     /* 0x50 SIM FinalizeParsing copies from vertex model+0x10 */
    uint32_t vert_model_0x14;     /* 0x54 SIM FinalizeParsing copies from vertex model+0x14 */
    uint64_t field_58;            /* 0x58 SIM Parse reads ulong */
    uint64_t field_60;            /* 0x60 SIM Parse reads ulong */
    uint64_t field_68;            /* 0x68 SIM Parse reads ulong */
    uint32_t vert_model_0x18;     /* 0x70 SIM FinalizeParsing copies from vertex model+0x18 */
    uint8_t  _pad_74[44];         /* 0x74 UNKNOWN gap to 0xa0 */
    uint32_t vert_model_0x1c;     /* 0xa0 SIM FinalizeParsing copies from vertex model+0x1c */
    uint8_t  _pad_a4[4];          /* 0xa4 UNKNOWN alignment before ulong */
    uint64_t vert_model_0x20;     /* 0xa8 SIM FinalizeParsing copies from vertex model+0x20 */
} ns3_nuccChunkModelPrimitiveBatch;
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vtable)              == 0x00, "ModelPrimBatch.vtable");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_10)            == 0x10, "ModelPrimBatch.field_10");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, coord_indices)       == 0x18, "ModelPrimBatch.coord_indices");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vertex_indices)      == 0x20, "ModelPrimBatch.vertex_indices");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_28)            == 0x28, "ModelPrimBatch.field_28");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vertex_model_chunk)  == 0x30, "ModelPrimBatch.vertex_model_chunk");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_38)            == 0x38, "ModelPrimBatch.field_38");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_3a)            == 0x3a, "ModelPrimBatch.field_3a");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_3c)            == 0x3c, "ModelPrimBatch.field_3c");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_3e)            == 0x3e, "ModelPrimBatch.field_3e");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_40)            == 0x40, "ModelPrimBatch.field_40");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_48)            == 0x48, "ModelPrimBatch.field_48");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vert_model_0x10)     == 0x50, "ModelPrimBatch.vert_model_0x10");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vert_model_0x14)     == 0x54, "ModelPrimBatch.vert_model_0x14");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_58)            == 0x58, "ModelPrimBatch.field_58");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_60)            == 0x60, "ModelPrimBatch.field_60");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, field_68)            == 0x68, "ModelPrimBatch.field_68");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vert_model_0x18)     == 0x70, "ModelPrimBatch.vert_model_0x18");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vert_model_0x1c)     == 0xa0, "ModelPrimBatch.vert_model_0x1c");
_Static_assert(offsetof(ns3_nuccChunkModelPrimitiveBatch, vert_model_0x20)     == 0xa8, "ModelPrimBatch.vert_model_0x20");

/* ── Classes with <3 methods (not reconstructed, listed in report) ── */
/* nuccChunkMorphPrimitive: 2 methods (Parse, dtor) — chunk ≥0x38, runtime 0x70 */
/* nuccChunkPrimitiveVertex: 2 methods (Parse, dtor) — size ≥0x28 */
/* nuccChunkNub: 2 methods (Parse, dtor) — size ≥0x20 */
/* nuccChunkPage: 1 method (Parse) — no instance state beyond base class (size 0x10) */