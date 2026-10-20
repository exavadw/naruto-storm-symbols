/* cmn49.h — nuccChunk struct layouts for Storm 4 (s4, NSUNS4_release.exe x64)
 * Generated 2026-10-19 from the decompiler cache symbolized decompilation cache.
 * All fields INFERRED from static analysis. Sizes proven from allocator calls.
 * No prefix (own-game names rule: Storm 4 has no Trilogy namespace).
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ── nuccChunkTexture ─────────────────────────────────────────────── */
/* Size ≥ 0x30: ctor writes param_1+5 (uint at 0x28), dtor frees param_1[4] */
typedef struct __attribute__((packed)) {
    uint64_t vtable;          /* 0x00 PRES init=PTR_FUN_14110e310, final=PTR_FUN_141112cf8 */
    uint8_t  _pad_08[8];      /* 0x08 UNKNOWN base class fields */
    uint16_t tex_width;       /* 0x10 SIM Parse reads ushort, endian-swapped */
    uint16_t tex_height;      /* 0x12 SIM Parse reads ushort, endian-swapped */
    uint8_t  tex_format;      /* 0x14 SIM Parse reads byte */
    uint8_t  tex_flags;       /* 0x15 SIM Parse reads byte (mipmap count) */
    uint8_t  _pad_16[2];      /* 0x16 UNKNOWN alignment */
    int32_t  texture_id;      /* 0x18 SIM Parse sets int, dtor checks ==1 for Release */
    uint8_t  _pad_1c[4];      /* 0x1c UNKNOWN alignment */
    uint64_t data_size;       /* 0x20 SIM MallocCore size arg */
    uint64_t nut_data;        /* 0x28 PRES MallocCore return stored at param_1[4], freed in dtor */
} nuccChunkTexture;
_Static_assert(offsetof(nuccChunkTexture, vtable)     == 0x00, "Texture.vtable");
_Static_assert(offsetof(nuccChunkTexture, tex_width)   == 0x10, "Texture.tex_width");
_Static_assert(offsetof(nuccChunkTexture, tex_height)  == 0x12, "Texture.tex_height");
_Static_assert(offsetof(nuccChunkTexture, tex_format)  == 0x14, "Texture.tex_format");
_Static_assert(offsetof(nuccChunkTexture, tex_flags)   == 0x15, "Texture.tex_flags");
_Static_assert(offsetof(nuccChunkTexture, texture_id)  == 0x18, "Texture.texture_id");
_Static_assert(offsetof(nuccChunkTexture, data_size)   == 0x20, "Texture.data_size");
_Static_assert(offsetof(nuccChunkTexture, nut_data)    == 0x28, "Texture.nut_data");

/* ── nuccChunkModelVertex ─────────────────────────────────────────── */
/* Size ≥ 0x88: state_surface shows accesses at 0x78 and 0x80 in dtor */
typedef struct __attribute__((packed)) {
    uint64_t vtable;          /* 0x00 PRES init=PTR_FUN_14110ea90, final=PTR_FUN_141112cf8 */
    uint8_t  _pad_08[8];      /* 0x08 UNKNOWN base class */
    uint64_t vertex_buffer;   /* 0x10 PRES MallocCore'd in Parse, FreeCore'd in dtor */
    uint32_t model_handle;    /* 0x18 PRES nummModelRelease'd in dtor (param_1+3 as uint) */
    uint8_t  _pad_1c[92];     /* 0x1c UNKNOWN gap to 0x78 */
    uint64_t field_78;        /* 0x78 PRES dtor reads param_1[0xf], checks !=0 */
    uint64_t field_80;        /* 0x80 PRES dtor passes param_1[0x10] to FUN_1406078cc */
} nuccChunkModelVertex;
_Static_assert(offsetof(nuccChunkModelVertex, vtable)        == 0x00, "ModelVertex.vtable");
_Static_assert(offsetof(nuccChunkModelVertex, vertex_buffer)  == 0x10, "ModelVertex.vertex_buffer");
_Static_assert(offsetof(nuccChunkModelVertex, model_handle)   == 0x18, "ModelVertex.model_handle");
_Static_assert(offsetof(nuccChunkModelVertex, field_78)       == 0x78, "ModelVertex.field_78");
_Static_assert(offsetof(nuccChunkModelVertex, field_80)       == 0x80, "ModelVertex.field_80");

/* ── nuccChunkMorphModel ──────────────────────────────────────────── */
/* Size ≥ 0x30: Parse accesses 0x28 (morph_weights ptr) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;          /* 0x00 PRES */
    uint8_t  _pad_08[8];      /* 0x08 UNKNOWN base class */
    uint64_t chunk_index;     /* 0x10 PRES GetIndex result stored */
    uint32_t morph_count;     /* 0x18 PRES count for both arrays (param_1+0x18) */
    uint8_t  _pad_1c[4];      /* 0x1c UNKNOWN alignment */
    uint64_t morph_targets;   /* 0x20 PRES array of 8-byte elems, alloc 8*count */
    uint64_t morph_weights;   /* 0x28 PRES array of 4-byte elems, alloc 4*count */
} nuccChunkMorphModel;
_Static_assert(offsetof(nuccChunkMorphModel, vtable)        == 0x00, "MorphModel.vtable");
_Static_assert(offsetof(nuccChunkMorphModel, chunk_index)   == 0x10, "MorphModel.chunk_index");
_Static_assert(offsetof(nuccChunkMorphModel, morph_count)   == 0x18, "MorphModel.morph_count");
_Static_assert(offsetof(nuccChunkMorphModel, morph_targets) == 0x20, "MorphModel.morph_targets");
_Static_assert(offsetof(nuccChunkMorphModel, morph_weights) == 0x28, "MorphModel.morph_weights");

/* ── nuccChunkMorphPrimitive ──────────────────────────────────────── */
/* Size = 0x70: Create calls operator_new(0x70). Parse writes up to +0x30. */
typedef struct __attribute__((packed)) {
    uint64_t vtable;           /* 0x00 PRES Create sets PTR_FUN_141112d28 */
    uint8_t  _pad_08[8];       /* 0x08 UNKNOWN base class (BlockAllocator) */
    uint64_t model_vertex_idx; /* 0x10 PRES GetIndex result from Parse */
    uint32_t target_count;     /* 0x18 PRES Parse stores ushort, Create inits puVar1[3]=0 */
    uint8_t  _pad_1c[4];       /* 0x1c UNKNOWN alignment */
    uint64_t target_indices;   /* 0x20 PRES array of 8-byte indices, alloc 8*count */
    uint64_t target_weights;   /* 0x28 PRES array of 4-byte weights, alloc 4*count */
    uint32_t target_num;       /* 0x30 PRES GetTargetNum returns *(uint*)(param_1+0x30) */
    uint8_t  _pad_34[60];      /* 0x34 UNKNOWN gap to end of 0x70 allocation */
} nuccChunkMorphPrimitive;
_Static_assert(offsetof(nuccChunkMorphPrimitive, vtable)           == 0x00, "MorphPrim.vtable");
_Static_assert(offsetof(nuccChunkMorphPrimitive, model_vertex_idx) == 0x10, "MorphPrim.model_vertex_idx");
_Static_assert(offsetof(nuccChunkMorphPrimitive, target_count)     == 0x18, "MorphPrim.target_count");
_Static_assert(offsetof(nuccChunkMorphPrimitive, target_indices)   == 0x20, "MorphPrim.target_indices");
_Static_assert(offsetof(nuccChunkMorphPrimitive, target_weights)   == 0x28, "MorphPrim.target_weights");
_Static_assert(offsetof(nuccChunkMorphPrimitive, target_num)       == 0x30, "MorphPrim.target_num");

/* ── nuccChunkSprite ──────────────────────────────────────────────── */
/* Size ≥ 0x38: Parse accesses 0x34 (version>=0x70 field) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;           /* 0x00 PRES */
    uint8_t  _pad_08[8];       /* 0x08 UNKNOWN base class */
    uint64_t sprite_entries;   /* 0x10 PRES array of 0x30-byte entries, operator_new__ */
    uint64_t coord_array;      /* 0x18 PRES array of 4-byte coords, operator_new__ */
    uint8_t  _pad_20[14];      /* 0x20 UNKNOWN gap to width/height */
    int16_t  width;            /* 0x2e SIM Parse reads short */
    int16_t  height;           /* 0x30 SIM Parse reads short */
    uint32_t field_32;         /* 0x32 SIM version>=0x70 only (undefined4) */
    uint16_t field_36;         /* 0x36 SIM version>=0x70 only (ushort) */
} nuccChunkSprite;
_Static_assert(offsetof(nuccChunkSprite, vtable)          == 0x00, "Sprite.vtable");
_Static_assert(offsetof(nuccChunkSprite, sprite_entries)   == 0x10, "Sprite.sprite_entries");
_Static_assert(offsetof(nuccChunkSprite, coord_array)      == 0x18, "Sprite.coord_array");
_Static_assert(offsetof(nuccChunkSprite, width)            == 0x2e, "Sprite.width");
_Static_assert(offsetof(nuccChunkSprite, height)           == 0x30, "Sprite.height");
_Static_assert(offsetof(nuccChunkSprite, field_32)         == 0x32, "Sprite.field_32");
_Static_assert(offsetof(nuccChunkSprite, field_36)         == 0x36, "Sprite.field_36");

/* ── nuccChunkSprite2 ─────────────────────────────────────────────── */
/* Size ≥ 0xf8: Parse accesses vectors up to 0xc0+, complex entries 0xe8 each */
typedef struct __attribute__((packed)) {
    uint64_t vtable;             /* 0x00 PRES */
    uint8_t  _pad_08[8];         /* 0x08 UNKNOWN base class */
    uint64_t field_10;           /* 0x10 SIM Parse reads ulong (8 bytes) */
    uint32_t entry_count;        /* 0x18 SIM Parse reads uint (4 bytes) */
    uint8_t  _pad_1c[4];         /* 0x1c UNKNOWN alignment */
    uint64_t entries_begin;      /* 0x20 PRES vector begin for 0x24-byte entries */
    uint64_t entries_end;        /* 0x28 PRES vector end */
    uint64_t entries_capacity;   /* 0x30 PRES vector capacity */
    uint8_t  bulk_data[40];      /* 0x38 SIM bulk read 0x28 bytes from Parse */
    uint64_t uint_vec_begin;     /* 0x60 PRES vector begin for uint entries */
    uint64_t uint_vec_end;       /* 0x68 PRES vector end */
    uint64_t uint_vec_capacity;  /* 0x70 PRES vector capacity */
    uint32_t complex_count;      /* 0x78 SIM count of 0xe8-byte complex entries */
    uint8_t  _pad_7c[4];         /* 0x7c UNKNOWN alignment */
    uint64_t complex_begin;      /* 0x80 PRES vector begin for complex entries */
    uint64_t complex_end;        /* 0x88 PRES vector end */
    uint64_t complex_capacity;   /* 0x90 PRES vector capacity */
    uint8_t  _pad_98[104];       /* 0x98 UNKNOWN gap to end of known layout */
} nuccChunkSprite2;
_Static_assert(offsetof(nuccChunkSprite2, vtable)            == 0x00, "Sprite2.vtable");
_Static_assert(offsetof(nuccChunkSprite2, field_10)           == 0x10, "Sprite2.field_10");
_Static_assert(offsetof(nuccChunkSprite2, entry_count)        == 0x18, "Sprite2.entry_count");
_Static_assert(offsetof(nuccChunkSprite2, entries_begin)      == 0x20, "Sprite2.entries_begin");
_Static_assert(offsetof(nuccChunkSprite2, entries_end)        == 0x28, "Sprite2.entries_end");
_Static_assert(offsetof(nuccChunkSprite2, entries_capacity)   == 0x30, "Sprite2.entries_capacity");
_Static_assert(offsetof(nuccChunkSprite2, bulk_data)          == 0x38, "Sprite2.bulk_data");
_Static_assert(offsetof(nuccChunkSprite2, uint_vec_begin)     == 0x60, "Sprite2.uint_vec_begin");
_Static_assert(offsetof(nuccChunkSprite2, uint_vec_end)       == 0x68, "Sprite2.uint_vec_end");
_Static_assert(offsetof(nuccChunkSprite2, uint_vec_capacity)  == 0x70, "Sprite2.uint_vec_capacity");
_Static_assert(offsetof(nuccChunkSprite2, complex_count)      == 0x78, "Sprite2.complex_count");
_Static_assert(offsetof(nuccChunkSprite2, complex_begin)      == 0x80, "Sprite2.complex_begin");
_Static_assert(offsetof(nuccChunkSprite2, complex_end)        == 0x88, "Sprite2.complex_end");
_Static_assert(offsetof(nuccChunkSprite2, complex_capacity)   == 0x90, "Sprite2.complex_capacity");

/* ── nuccChunkSpriteAnm ───────────────────────────────────────────── */
/* Size ≥ 0x50: Parse accesses 0x4c (max_keyframes_x100) */
typedef struct __attribute__((packed)) {
    uint64_t vtable;              /* 0x00 PRES final via scalar deleting dtor */
    uint8_t  _pad_08[8];          /* 0x08 UNKNOWN base class */
    uint64_t anim_data_buf;       /* 0x10 PRES MallocCore'd buffer */
    uint64_t sprite_chunk_ref;    /* 0x18 PRES GetIndex result */
    uint64_t frame_data;          /* 0x20 SIM operator_new__ with frame_count */
    uint8_t  _pad_28[16];         /* 0x28 UNKNOWN gap to frame_array */
    uint64_t frame_array;         /* 0x38 PRES array of 0x78-byte frame records */
    uint16_t header_ushort;       /* 0x40 SIM from Parse header (local_30) */
    uint8_t  _pad_42[6];          /* 0x42 UNKNOWN alignment */
    uint32_t max_keyframes_x100;  /* 0x48 SIM max_keyframes*100 from Parse */
    uint8_t  _pad_4c[4];          /* 0x4c UNKNOWN alignment */
} nuccChunkSpriteAnm;
_Static_assert(offsetof(nuccChunkSpriteAnm, vtable)              == 0x00, "SpriteAnm.vtable");
_Static_assert(offsetof(nuccChunkSpriteAnm, anim_data_buf)       == 0x10, "SpriteAnm.anim_data_buf");
_Static_assert(offsetof(nuccChunkSpriteAnm, sprite_chunk_ref)    == 0x18, "SpriteAnm.sprite_chunk_ref");
_Static_assert(offsetof(nuccChunkSpriteAnm, frame_data)          == 0x20, "SpriteAnm.frame_data");
_Static_assert(offsetof(nuccChunkSpriteAnm, frame_array)         == 0x38, "SpriteAnm.frame_array");
_Static_assert(offsetof(nuccChunkSpriteAnm, header_ushort)       == 0x40, "SpriteAnm.header_ushort");
_Static_assert(offsetof(nuccChunkSpriteAnm, max_keyframes_x100)  == 0x48, "SpriteAnm.max_keyframes_x100");

/* ── nuccChunkParticle ────────────────────────────────────────────── */
/* Size ≥ 0x60: Parse reads 0x28 bytes header, gen_params 0xe0 each */
typedef struct __attribute__((packed)) {
    uint64_t vtable;              /* 0x00 PRES final via scalar deleting dtor */
    uint8_t  _pad_08[8];          /* 0x08 UNKNOWN base class */
    uint8_t  parse_header[40];    /* 0x10 SIM bulk read 0x28 bytes with counts */
    uint64_t gen_params;          /* 0x38 PRES array of 0xe0-byte gen params, operator_new__ */
    uint8_t  _pad_40[24];         /* 0x40 UNKNOWN gap (documents/time_params not yet proven in s4) */
} nuccChunkParticle;
_Static_assert(offsetof(nuccChunkParticle, vtable)        == 0x00, "Particle.vtable");
_Static_assert(offsetof(nuccChunkParticle, parse_header)  == 0x10, "Particle.parse_header");
_Static_assert(offsetof(nuccChunkParticle, gen_params)     == 0x38, "Particle.gen_params");

/* ── nuccChunkModelPrimitiveBatch ─────────────────────────────────── */
/* Size ≥ 0xb0: Parse accesses fields up to 0x6c, version-gated header */
typedef struct __attribute__((packed)) {
    uint64_t vtable;              /* 0x00 PRES */
    uint8_t  _pad_08[8];          /* 0x08 UNKNOWN base class */
    uint64_t vertex_model_chunk;  /* 0x10 PRES GetIndex(local_30) */
    uint64_t field_18;            /* 0x18 SIM vertex indices array (alloc 2*vcount) */
    uint64_t coord_indices;       /* 0x20 SIM coord indices array (alloc 2*vcount) */
    uint64_t field_28;            /* 0x28 PRES GetIndex(local_2c) */
    uint64_t field_30;            /* 0x30 PRES GetIndex(local_28) */
    uint16_t vertex_count;        /* 0x38 SIM Parse reads ushort */
    uint16_t flag;                /* 0x3a SIM ==1 triggers extra 8-byte read */
    uint16_t field_3c;            /* 0x3c SIM Parse reads ushort */
    uint16_t field_3e;            /* 0x3e SIM Parse reads ushort */
    uint64_t material_hash;       /* 0x40 SIM default 0xffffffff */
    uint32_t field_48;            /* 0x48 SIM from local_18 */
    uint32_t field_4c;            /* 0x4c SIM from local_18 */
    uint64_t field_50;            /* 0x50 SIM from 0xc-byte read block */
    uint64_t field_58;            /* 0x58 SIM from 0xc-byte read block */
    uint64_t field_60;            /* 0x60 SIM from 0xc-byte read block */
    uint32_t field_68;            /* 0x68 SIM local_74 */
    uint8_t  _pad_6c[68];         /* 0x6c UNKNOWN gap to end of known layout */
} nuccChunkModelPrimitiveBatch;
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, vtable)              == 0x00, "ModelPrimBatch.vtable");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, vertex_model_chunk)  == 0x10, "ModelPrimBatch.vertex_model_chunk");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_18)            == 0x18, "ModelPrimBatch.field_18");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, coord_indices)       == 0x20, "ModelPrimBatch.coord_indices");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_28)            == 0x28, "ModelPrimBatch.field_28");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_30)            == 0x30, "ModelPrimBatch.field_30");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, vertex_count)        == 0x38, "ModelPrimBatch.vertex_count");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, flag)                == 0x3a, "ModelPrimBatch.flag");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_3c)            == 0x3c, "ModelPrimBatch.field_3c");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_3e)            == 0x3e, "ModelPrimBatch.field_3e");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, material_hash)       == 0x40, "ModelPrimBatch.material_hash");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_48)            == 0x48, "ModelPrimBatch.field_48");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_4c)            == 0x4c, "ModelPrimBatch.field_4c");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_50)            == 0x50, "ModelPrimBatch.field_50");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_58)            == 0x58, "ModelPrimBatch.field_58");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_60)            == 0x60, "ModelPrimBatch.field_60");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_68)            == 0x68, "ModelPrimBatch.field_68");

/* ── Classes with <3 methods (not reconstructed, listed in report) ── */
/* nuccChunkPrimitiveVertex: 2 methods (Parse, dtor) — size ≥0x28 */
/* nuccChunkNub: 2 methods (Parse, dtor) — size ≥0x20 */
/* nuccChunkPage: 1 method (Parse) — no instance state beyond base class (size 0x10) */