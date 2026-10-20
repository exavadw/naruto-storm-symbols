/* cmn49.h — nuccChunk* struct layouts for Storm 1 (s1, NSUNS1.exe)
 * Generated from decompile analysis. All fields INFERRED (static analysis only).
 * PC OFFSETS ONLY — derived from s1 x64 decompiles (image base 0x140000000).
 * Sizes unproven unless noted; structs end at last proven field.
 * OWN-GAME NAMES: field names from s1 code/strings or Switch Trilogy ns1:: only.
 *
 * NOTE: These structs use __attribute__((packed)) with EXPLICIT padding to match
 * the exact byte offsets observed in decompiled code. Natural alignment does NOT
 * match because the binary has non-standard padding patterns (e.g., 6-byte gaps
 * after uint16_t fields). Every field offset is verified by _Static_assert.
 */
#ifndef CMN49_H
#define CMN49_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nuccChunkParticle
 * Vtable (init): 0x14073e380, Vtable (final): 0x140744780
 * Size: unknown, >= 0x68 (last freed ptr at param_1[0xc] = offset 0x60 + 8)
 * Evidence: FUN_1404e27c0 (cleanup), FUN_1404e2ee0 (Parse)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkParticle_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 - unknown base fields */
    void *parse_buf;                 /* 0x10 - read buffer (0x28 bytes via FUN_1404838b0) */
    uint16_t count_0;               /* 0x18 - first array element count */
    uint8_t _pad_1a[0x02];          /* 0x1a */
    uint32_t _field_1c;             /* 0x1c - unknown */
    uint16_t count_1;               /* 0x20 - second array element count */
    uint8_t _pad_22[0x02];          /* 0x22 */
    uint32_t _field_24;             /* 0x24 - unknown */
    uint16_t count_2;               /* 0x28 - third array element count */
    uint8_t _pad_2a[0x06];          /* 0x2a */
    void *array_0;                   /* 0x30 - first allocated array (elem size 0xe0) */
    void *array_1;                   /* 0x38 - second allocated array (elem size 0x30) */
    void *array_2;                   /* 0x40 - third allocated array (elem size 0x48) */
    void *ptr_48;                    /* 0x48 - freed in cleanup */
    void *ptr_50;                    /* 0x50 - freed in cleanup */
    void *ptr_58;                    /* 0x58 - freed in cleanup */
    void *ptr_60;                    /* 0x60 - freed in cleanup */
} nuccChunkParticle;

_Static_assert(offsetof(nuccChunkParticle, vtable) == 0x00, "nuccChunkParticle.vtable");
_Static_assert(offsetof(nuccChunkParticle, parse_buf) == 0x10, "nuccChunkParticle.parse_buf");
_Static_assert(offsetof(nuccChunkParticle, count_0) == 0x18, "nuccChunkParticle.count_0");
_Static_assert(offsetof(nuccChunkParticle, count_1) == 0x20, "nuccChunkParticle.count_1");
_Static_assert(offsetof(nuccChunkParticle, count_2) == 0x28, "nuccChunkParticle.count_2");
_Static_assert(offsetof(nuccChunkParticle, array_0) == 0x30, "nuccChunkParticle.array_0");
_Static_assert(offsetof(nuccChunkParticle, array_1) == 0x38, "nuccChunkParticle.array_1");
_Static_assert(offsetof(nuccChunkParticle, array_2) == 0x40, "nuccChunkParticle.array_2");
_Static_assert(offsetof(nuccChunkParticle, ptr_48) == 0x48, "nuccChunkParticle.ptr_48");
_Static_assert(offsetof(nuccChunkParticle, ptr_50) == 0x50, "nuccChunkParticle.ptr_50");
_Static_assert(offsetof(nuccChunkParticle, ptr_58) == 0x58, "nuccChunkParticle.ptr_58");
_Static_assert(offsetof(nuccChunkParticle, ptr_60) == 0x60, "nuccChunkParticle.ptr_60");

/* =========================================================================
 * nuccModelPrimitiveBatch (aka nuccChunkModelPrimitiveBatch)
 * Vtable (init): 0x14073b058, Vtable (mid): 0x14073b0c0, Vtable (final): 0x140775578
 * Size: unknown, >= 0xb0 (param_1[0x15] = offset 0xa8 + 8)
 * Evidence: FUN_1404c8610 (destructor body), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccModelPrimitiveBatch_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - Parse offset 0x10 */
    void *field_18;                  /* 0x18 - Parse offset 0x18 */
    void *field_20;                  /* 0x20 - Parse offset 0x20 */
    void *field_28;                  /* 0x28 - Parse offset 0x28 */
    void *field_30;                  /* 0x30 - Parse offset 0x30 */
    uint16_t field_38;               /* 0x38 - ushort from Parse */
    uint16_t field_3a;               /* 0x3a - ushort from Parse */
    uint16_t field_3c;               /* 0x3c - ushort from Parse */
    uint16_t field_3e;               /* 0x3e - ushort from Parse */
    uint64_t field_40;               /* 0x40 - ulong from Parse */
    uint32_t field_48;               /* 0x48 - uint from Parse */
    uint32_t field_4c;               /* 0x4c - padding/unknown */
    void *obj_ptr;                   /* 0x50 - param_1[7] in dtor, has vcall */
    void *field_58;                  /* 0x58 - Parse offset 0x58 */
    uint32_t field_60;               /* 0x60 - Parse offset 0x5c */
    uint32_t field_64;               /* 0x64 - decimal 100 from Parse */
    void *field_68;                  /* 0x68 - Parse offset 0x68 */
    uint32_t field_70;               /* 0x70 - Parse offset 0x6c */
    uint8_t _pad_74[0x14];          /* 0x74 */
    void *ptr_d;                     /* 0x88 - param_1[0xd], freed in dtor */
    uint8_t _pad_90[0x08];          /* 0x90 */
    void *ptr_9;                     /* 0x98 - param_1[9], complex free in dtor */
    void *field_a0;                  /* 0xa0 - param_1[10] check */
    void *ptr_11;                    /* 0xa8 - param_1[0x11], freed in dtor */
    void *ptr_12;                    /* 0xb0 - param_1[0x12], freed in dtor */
    void *ptr_13;                    /* 0xb8 - param_1[0x13], freed via FUN_14047efc0 */
    uint8_t _pad_c0[0x08];          /* 0xc0 */
    void *ptr_15;                    /* 0xc8 - param_1[0x15], freed in dtor */
} nuccModelPrimitiveBatch;

_Static_assert(offsetof(nuccModelPrimitiveBatch, vtable) == 0x00, "nuccModelPrimitiveBatch.vtable");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_10) == 0x10, "nuccModelPrimitiveBatch.field_10");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_18) == 0x18, "nuccModelPrimitiveBatch.field_18");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_20) == 0x20, "nuccModelPrimitiveBatch.field_20");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_28) == 0x28, "nuccModelPrimitiveBatch.field_28");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_30) == 0x30, "nuccModelPrimitiveBatch.field_30");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_38) == 0x38, "nuccModelPrimitiveBatch.field_38");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_3a) == 0x3a, "nuccModelPrimitiveBatch.field_3a");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_3c) == 0x3c, "nuccModelPrimitiveBatch.field_3c");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_3e) == 0x3e, "nuccModelPrimitiveBatch.field_3e");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_40) == 0x40, "nuccModelPrimitiveBatch.field_40");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_48) == 0x48, "nuccModelPrimitiveBatch.field_48");
_Static_assert(offsetof(nuccModelPrimitiveBatch, obj_ptr) == 0x50, "nuccModelPrimitiveBatch.obj_ptr");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_58) == 0x58, "nuccModelPrimitiveBatch.field_58");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_64) == 0x64, "nuccModelPrimitiveBatch.field_64");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_68) == 0x68, "nuccModelPrimitiveBatch.field_68");
_Static_assert(offsetof(nuccModelPrimitiveBatch, ptr_d) == 0x88, "nuccModelPrimitiveBatch.ptr_d");
_Static_assert(offsetof(nuccModelPrimitiveBatch, ptr_9) == 0x98, "nuccModelPrimitiveBatch.ptr_9");
_Static_assert(offsetof(nuccModelPrimitiveBatch, ptr_11) == 0xa8, "nuccModelPrimitiveBatch.ptr_11");
_Static_assert(offsetof(nuccModelPrimitiveBatch, ptr_12) == 0xb0, "nuccModelPrimitiveBatch.ptr_12");
_Static_assert(offsetof(nuccModelPrimitiveBatch, ptr_13) == 0xb8, "nuccModelPrimitiveBatch.ptr_13");
_Static_assert(offsetof(nuccModelPrimitiveBatch, ptr_15) == 0xc8, "nuccModelPrimitiveBatch.ptr_15");

/* =========================================================================
 * nuccChunkSpriteAnm
 * Vtable: set by FUN_14049f890 (base ctor), final via FUN_14047edf0
 * Size: unknown, >= 0x50 (Parse shows ptr at 0x38 + stride 0x78 array)
 * Evidence: FUN_14049fa70 (dtor), FUN_1404fec70 (Parse)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkSpriteAnm_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - ptr from Parse */
    void *field_18;                  /* 0x18 - ptr from Parse */
    uint8_t embedded_struct[0x18];   /* 0x20 - embedded struct (24 bytes) */
    void *sprite_array;              /* 0x38 - ptr to array, stride 0x78 */
    uint8_t _pad_40[0x08];          /* 0x40 */
    uint16_t sprite_count;           /* 0x48 - ushort from Parse */
    uint8_t _pad_4a[0x06];          /* 0x4a */
} nuccChunkSpriteAnm;

_Static_assert(offsetof(nuccChunkSpriteAnm, vtable) == 0x00, "nuccChunkSpriteAnm.vtable");
_Static_assert(offsetof(nuccChunkSpriteAnm, field_10) == 0x10, "nuccChunkSpriteAnm.field_10");
_Static_assert(offsetof(nuccChunkSpriteAnm, field_18) == 0x18, "nuccChunkSpriteAnm.field_18");
_Static_assert(offsetof(nuccChunkSpriteAnm, embedded_struct) == 0x20, "nuccChunkSpriteAnm.embedded_struct");
_Static_assert(offsetof(nuccChunkSpriteAnm, sprite_array) == 0x38, "nuccChunkSpriteAnm.sprite_array");
_Static_assert(offsetof(nuccChunkSpriteAnm, sprite_count) == 0x48, "nuccChunkSpriteAnm.sprite_count");

/* =========================================================================
 * nuccMorphModel (aka nuccChunkMorphModel)
 * Vtable chain: 0x140744848 -> 0x140745358 (final)
 * Size: unknown, >= 0x50 (param_1[9] = offset 0x48 + 8)
 * Evidence: FUN_14052a510 (dtor), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccMorphModel_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - ptr from Parse */
    uint32_t morph_count;            /* 0x18 - uint count from Parse */
    uint32_t _pad_1c;                /* 0x1c */
    void *morph_data_8;              /* 0x20 - ptr, 8-byte elements from Parse */
    void *morph_data_4;              /* 0x28 - ptr, 4-byte elements from Parse */
    uint8_t _pad_30[0x10];          /* 0x30 */
    void *field_40;                  /* 0x40 - param_1[8], freed in dtor */
    void *field_48;                  /* 0x48 - param_1[9], freed in dtor */
} nuccMorphModel;

_Static_assert(offsetof(nuccMorphModel, vtable) == 0x00, "nuccMorphModel.vtable");
_Static_assert(offsetof(nuccMorphModel, field_10) == 0x10, "nuccMorphModel.field_10");
_Static_assert(offsetof(nuccMorphModel, morph_count) == 0x18, "nuccMorphModel.morph_count");
_Static_assert(offsetof(nuccMorphModel, morph_data_8) == 0x20, "nuccMorphModel.morph_data_8");
_Static_assert(offsetof(nuccMorphModel, morph_data_4) == 0x28, "nuccMorphModel.morph_data_4");
_Static_assert(offsetof(nuccMorphModel, field_40) == 0x40, "nuccMorphModel.field_40");
_Static_assert(offsetof(nuccMorphModel, field_48) == 0x48, "nuccMorphModel.field_48");

/* =========================================================================
 * nuccChunkTexture
 * Vtable (init): 0x14073f7e0, Vtable (final): 0x140744780
 * Size: unknown, >= 0x30 (param_1[5] = offset 0x28 + 8)
 * Evidence: FUN_1404f9d50 (dtor), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkTexture_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    uint16_t tex_width;              /* 0x10 - ushort from Parse */
    uint16_t tex_height;             /* 0x12 - ushort from Parse */
    uint8_t tex_format;              /* 0x14 - byte from Parse */
    uint8_t tex_flags;               /* 0x15 - byte from Parse */
    uint8_t _pad_16[0x02];          /* 0x16 */
    int32_t field_18;                /* 0x18 - int from Parse */
    uint64_t tex_data_size;          /* 0x1c - ulong from Parse (misaligned?) */
    uint8_t _pad_24[0x04];          /* 0x24 */
    uint32_t field_28;               /* 0x28 - uint=1 from Parse, also param_1[4] in dtor */
    uint32_t field_2c;               /* 0x2c - param_1[5] check == 1 triggers special free */
} nuccChunkTexture;

_Static_assert(offsetof(nuccChunkTexture, vtable) == 0x00, "nuccChunkTexture.vtable");
_Static_assert(offsetof(nuccChunkTexture, tex_width) == 0x10, "nuccChunkTexture.tex_width");
_Static_assert(offsetof(nuccChunkTexture, tex_height) == 0x12, "nuccChunkTexture.tex_height");
_Static_assert(offsetof(nuccChunkTexture, tex_format) == 0x14, "nuccChunkTexture.tex_format");
_Static_assert(offsetof(nuccChunkTexture, tex_flags) == 0x15, "nuccChunkTexture.tex_flags");
_Static_assert(offsetof(nuccChunkTexture, field_18) == 0x18, "nuccChunkTexture.field_18");
_Static_assert(offsetof(nuccChunkTexture, tex_data_size) == 0x1c, "nuccChunkTexture.tex_data_size");
_Static_assert(offsetof(nuccChunkTexture, field_28) == 0x28, "nuccChunkTexture.field_28");
_Static_assert(offsetof(nuccChunkTexture, field_2c) == 0x2c, "nuccChunkTexture.field_2c");

/* =========================================================================
 * nuccChunkSprite2
 * Vtable: set by FUN_1404ff910 (base ctor), final via FUN_14047edf0
 * Size: unknown, >= 0x78 (Parse shows ulong at 0x74 + 8)
 * Evidence: FUN_1404fff50 (dtor), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkSprite2_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    uint64_t field_10;               /* 0x10 - ulong from Parse */
    uint64_t field_18;               /* 0x18 - ulong from Parse */
    int32_t sprite_count;            /* 0x20 - int count from Parse */
    uint8_t _pad_24[0x04];          /* 0x24 */
    void *vector_begin;              /* 0x28 - vector begin ptr */
    void *vector_end;                /* 0x30 - vector end ptr */
    void *vector_capacity;           /* 0x38 - vector capacity ptr */
    uint8_t _pad_40[0x10];          /* 0x40 */
    uint8_t buffer[0x28];            /* 0x50 - 0x28 byte buffer from Parse */
    uint64_t field_78;               /* 0x78 - ulong from Parse */
    uint64_t field_80;               /* 0x80 - ulong from Parse */
} nuccChunkSprite2;

_Static_assert(offsetof(nuccChunkSprite2, vtable) == 0x00, "nuccChunkSprite2.vtable");
_Static_assert(offsetof(nuccChunkSprite2, field_10) == 0x10, "nuccChunkSprite2.field_10");
_Static_assert(offsetof(nuccChunkSprite2, field_18) == 0x18, "nuccChunkSprite2.field_18");
_Static_assert(offsetof(nuccChunkSprite2, sprite_count) == 0x20, "nuccChunkSprite2.sprite_count");
_Static_assert(offsetof(nuccChunkSprite2, vector_begin) == 0x28, "nuccChunkSprite2.vector_begin");
_Static_assert(offsetof(nuccChunkSprite2, vector_end) == 0x30, "nuccChunkSprite2.vector_end");
_Static_assert(offsetof(nuccChunkSprite2, vector_capacity) == 0x38, "nuccChunkSprite2.vector_capacity");
_Static_assert(offsetof(nuccChunkSprite2, buffer) == 0x50, "nuccChunkSprite2.buffer");
_Static_assert(offsetof(nuccChunkSprite2, field_78) == 0x78, "nuccChunkSprite2.field_78");
_Static_assert(offsetof(nuccChunkSprite2, field_80) == 0x80, "nuccChunkSprite2.field_80");

/* =========================================================================
 * nuccChunkSprite
 * Vtable: set by FUN_1404fe430 (base ctor), final via FUN_14047edf0
 * Size: unknown, >= 0x38 (last field at 0x34 + 2)
 * Evidence: FUN_1404fe500 (dtor), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkSprite_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - ptr from Parse */
    void *field_18;                  /* 0x18 - ptr from Parse */
    void *field_20;                  /* 0x20 - ptr from Parse */
    uint16_t field_28;               /* 0x28 - ushort from Parse */
    uint16_t field_2a;               /* 0x2a - ushort from Parse */
    uint16_t field_2c;               /* 0x2c - ushort from Parse */
    int16_t field_2e;                /* 0x2e - short from Parse */
    int16_t field_30;                /* 0x30 - short from Parse */
    uint16_t field_32;               /* 0x32 - ushort from Parse */
    uint16_t field_34;               /* 0x34 - ushort from Parse */
} nuccChunkSprite;

_Static_assert(offsetof(nuccChunkSprite, vtable) == 0x00, "nuccChunkSprite.vtable");
_Static_assert(offsetof(nuccChunkSprite, field_10) == 0x10, "nuccChunkSprite.field_10");
_Static_assert(offsetof(nuccChunkSprite, field_18) == 0x18, "nuccChunkSprite.field_18");
_Static_assert(offsetof(nuccChunkSprite, field_20) == 0x20, "nuccChunkSprite.field_20");
_Static_assert(offsetof(nuccChunkSprite, field_28) == 0x28, "nuccChunkSprite.field_28");
_Static_assert(offsetof(nuccChunkSprite, field_2a) == 0x2a, "nuccChunkSprite.field_2a");
_Static_assert(offsetof(nuccChunkSprite, field_2c) == 0x2c, "nuccChunkSprite.field_2c");
_Static_assert(offsetof(nuccChunkSprite, field_2e) == 0x2e, "nuccChunkSprite.field_2e");
_Static_assert(offsetof(nuccChunkSprite, field_30) == 0x30, "nuccChunkSprite.field_30");
_Static_assert(offsetof(nuccChunkSprite, field_32) == 0x32, "nuccChunkSprite.field_32");
_Static_assert(offsetof(nuccChunkSprite, field_34) == 0x34, "nuccChunkSprite.field_34");

/* =========================================================================
 * nuccChunkModelVertex
 * Vtable (init): 0x14073fbf0, Vtable (final): 0x140744780
 * Size: unknown, >= 0x20 (param_1[3] = offset 0x18 + 8)
 * Evidence: FUN_1404fd4a0 (dtor), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkModelVertex_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *vertex_data;               /* 0x10 - ptr from Parse */
    void *field_18;                  /* 0x18 - param_1[2], freed in dtor */
    uint32_t vertex_count;           /* 0x20 - *(uint*)(param_1+3) passed to FUN_14048dc00 */
    uint32_t _pad_24;                /* 0x24 */
} nuccChunkModelVertex;

_Static_assert(offsetof(nuccChunkModelVertex, vtable) == 0x00, "nuccChunkModelVertex.vtable");
_Static_assert(offsetof(nuccChunkModelVertex, vertex_data) == 0x10, "nuccChunkModelVertex.vertex_data");
_Static_assert(offsetof(nuccChunkModelVertex, field_18) == 0x18, "nuccChunkModelVertex.field_18");
_Static_assert(offsetof(nuccChunkModelVertex, vertex_count) == 0x20, "nuccChunkModelVertex.vertex_count");

/* =========================================================================
 * nuccChunkModelPrimitiveBatch
 * Same layout as nuccModelPrimitiveBatch; "Chunk" prefix is the xfbin chunk-type name.
 * Vtable (init): 0x14073b058, Vtable (mid): 0x14073b0c0, Vtable (final): 0x140775578
 * Size: unknown, >= 0xd0 (last freed ptr at param_1[0x15] = offset 0xc8 + 8)
 * Methods (5): Parse, GetVertexArray, FinalizeParsing, GetCoordId, GetVertexNum
 * Evidence: FUN_1404c8610 (destructor body), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkModelPrimitiveBatch_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - Parse offset 0x10 */
    void *field_18;                  /* 0x18 - Parse offset 0x18 */
    void *field_20;                  /* 0x20 - Parse offset 0x20 */
    void *field_28;                  /* 0x28 - Parse offset 0x28 */
    void *field_30;                  /* 0x30 - Parse offset 0x30 */
    uint16_t field_38;               /* 0x38 - ushort from Parse */
    uint16_t field_3a;               /* 0x3a - ushort from Parse */
    uint16_t field_3c;               /* 0x3c - ushort from Parse */
    uint16_t field_3e;               /* 0x3e - ushort from Parse */
    uint64_t field_40;               /* 0x40 - ulong from Parse */
    uint32_t field_48;               /* 0x48 - uint from Parse */
    uint32_t field_4c;               /* 0x4c - padding/unknown */
    void *obj_ptr;                   /* 0x50 - param_1[7] in dtor, has vcall */
    void *field_58;                  /* 0x58 - Parse offset 0x58 */
    uint32_t field_60;               /* 0x60 - Parse offset 0x5c */
    uint32_t field_64;               /* 0x64 - decimal 100 from Parse */
    void *field_68;                  /* 0x68 - Parse offset 0x68 */
    uint32_t field_70;               /* 0x70 - Parse offset 0x6c */
    uint8_t _pad_74[0x14];          /* 0x74 */
    void *ptr_d;                     /* 0x88 - param_1[0xd], freed in dtor */
    uint8_t _pad_90[0x08];          /* 0x90 */
    void *ptr_9;                     /* 0x98 - param_1[9], complex free in dtor */
    void *field_a0;                  /* 0xa0 - param_1[10] check */
    void *ptr_11;                    /* 0xa8 - param_1[0x11], freed in dtor */
    void *ptr_12;                    /* 0xb0 - param_1[0x12], freed in dtor */
    void *ptr_13;                    /* 0xb8 - param_1[0x13], freed via FUN_14047efc0 */
    uint8_t _pad_c0[0x08];          /* 0xc0 */
    void *ptr_15;                    /* 0xc8 - param_1[0x15], freed in dtor */
} nuccChunkModelPrimitiveBatch;

_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, vtable) == 0x00, "nuccChunkModelPrimitiveBatch.vtable");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_10) == 0x10, "nuccChunkModelPrimitiveBatch.field_10");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_18) == 0x18, "nuccChunkModelPrimitiveBatch.field_18");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_20) == 0x20, "nuccChunkModelPrimitiveBatch.field_20");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_28) == 0x28, "nuccChunkModelPrimitiveBatch.field_28");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_30) == 0x30, "nuccChunkModelPrimitiveBatch.field_30");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_38) == 0x38, "nuccChunkModelPrimitiveBatch.field_38");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_3a) == 0x3a, "nuccChunkModelPrimitiveBatch.field_3a");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_3c) == 0x3c, "nuccChunkModelPrimitiveBatch.field_3c");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_3e) == 0x3e, "nuccChunkModelPrimitiveBatch.field_3e");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_40) == 0x40, "nuccChunkModelPrimitiveBatch.field_40");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_48) == 0x48, "nuccChunkModelPrimitiveBatch.field_48");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, obj_ptr) == 0x50, "nuccChunkModelPrimitiveBatch.obj_ptr");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_58) == 0x58, "nuccChunkModelPrimitiveBatch.field_58");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_64) == 0x64, "nuccChunkModelPrimitiveBatch.field_64");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, field_68) == 0x68, "nuccChunkModelPrimitiveBatch.field_68");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, ptr_d) == 0x88, "nuccChunkModelPrimitiveBatch.ptr_d");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, ptr_9) == 0x98, "nuccChunkModelPrimitiveBatch.ptr_9");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, ptr_11) == 0xa8, "nuccChunkModelPrimitiveBatch.ptr_11");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, ptr_12) == 0xb0, "nuccChunkModelPrimitiveBatch.ptr_12");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, ptr_13) == 0xb8, "nuccChunkModelPrimitiveBatch.ptr_13");
_Static_assert(offsetof(nuccChunkModelPrimitiveBatch, ptr_15) == 0xc8, "nuccChunkModelPrimitiveBatch.ptr_15");

/* =========================================================================
 * nuccChunkMorphModel
 * Same layout as nuccMorphModel; "Chunk" prefix is the xfbin chunk-type name.
 * Vtable chain: 0x140744848 -> 0x140745358 (final)
 * Size: unknown, >= 0x50 (param_1[9] = offset 0x48 + 8)
 * Methods (4): Parse, GetChunkIndexModelBase, GetChunkIndexModelVertexTarget, GetWeight
 * Evidence: FUN_14052a510 (dtor), Parse offsets from summary
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccChunkMorphModel_s {
    void *vtable;                    /* 0x00 */
    uint8_t _pad_08[0x08];           /* 0x08 */
    void *field_10;                  /* 0x10 - ptr from Parse */
    uint32_t morph_count;            /* 0x18 - uint count from Parse */
    uint32_t _pad_1c;                /* 0x1c */
    void *morph_data_8;              /* 0x20 - ptr, 8-byte elements from Parse */
    void *morph_data_4;              /* 0x28 - ptr, 4-byte elements from Parse */
    uint8_t _pad_30[0x10];          /* 0x30 */
    void *field_40;                  /* 0x40 - param_1[8], freed in dtor */
    void *field_48;                  /* 0x48 - param_1[9], freed in dtor */
} nuccChunkMorphModel;

_Static_assert(offsetof(nuccChunkMorphModel, vtable) == 0x00, "nuccChunkMorphModel.vtable");
_Static_assert(offsetof(nuccChunkMorphModel, field_10) == 0x10, "nuccChunkMorphModel.field_10");
_Static_assert(offsetof(nuccChunkMorphModel, morph_count) == 0x18, "nuccChunkMorphModel.morph_count");
_Static_assert(offsetof(nuccChunkMorphModel, morph_data_8) == 0x20, "nuccChunkMorphModel.morph_data_8");
_Static_assert(offsetof(nuccChunkMorphModel, morph_data_4) == 0x28, "nuccChunkMorphModel.morph_data_4");
_Static_assert(offsetof(nuccChunkMorphModel, field_40) == 0x40, "nuccChunkMorphModel.field_40");
_Static_assert(offsetof(nuccChunkMorphModel, field_48) == 0x48, "nuccChunkMorphModel.field_48");

#endif /* CMN49_H */