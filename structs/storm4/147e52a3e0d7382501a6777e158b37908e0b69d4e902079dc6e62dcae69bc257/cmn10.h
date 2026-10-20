/* cmn10 s4 — ccUiClump struct layout (NARUTO STORM 4 PC 1.09, NSUNS4_release.exe)
 * All results INFERRED from static analysis unless noted CONFIRMED.
 * Size 0x148 proven by operator_new(0x148) in ccUiClump::ccUiClump (RVA 0x8247CC).
 * Offsets verified against s4 decompiled code; names carried from s3 with s4 re-verification.
 */
#ifndef CMN10_S4_H
#define CMN10_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ccUiClump {
    /* 0x000 */ void     *vtable;                /* PRES: vfunc+0x08 cleanup, vfunc+0x10 virtual hook */
    /* 0x008 */ void     *secondary_ptr;         /* UNKNOWN: inherited ccUiObject base */
    /* 0x010 */ uint64_t  base_reserved_0x10;    /* UNKNOWN: inherited ccUiObject base */
    /* 0x018 */ char      chunk_name_str[32];    /* PRES: std::string at param_1+3 in Initialize */
    /* 0x038 */ uint8_t   pad_0x38[4];           /* UNKNOWN: alignment */
    /* 0x03C */ int32_t   field_0x3C;            /* UNKNOWN: s3 carry-over, no direct s4 access */
    /* 0x040 */ float     vec_local_a[3];        /* SIM: local transform vector A (s3 carry-over) */
    /* 0x04C */ float     vec_local_b[3];        /* SIM: local transform vector B (s3 carry-over) */
    /* 0x058 */ uint8_t   pad_0x58[8];           /* UNKNOWN: gap to ccUiObject fields */
    /* 0x060 */ uint64_t  ccUiObject_field_0x60; /* UNKNOWN: inherited */
    /* 0x068 */ uint64_t  ccUiObject_field_0x68; /* UNKNOWN: inherited */
    /* 0x070 */ void     *texture_chunk_ptr;     /* PRES: texture chunk from xfbin (s3 carry-over) */
    /* 0x078 */ uint64_t  ccUiObject_field_0x78; /* UNKNOWN: inherited */
    /* 0x080 */ uint64_t  ccUiObject_field_0x80; /* UNKNOWN: vtable+0x10 dispatch site in Initialize */
    /* 0x088 */ void     *ccUiObject_field_0x88; /* UNKNOWN: param_1[0x11] in Initialize */
    /* 0x090 */ int32_t   ccUiObject_flag_0x90;  /* PRES: set to 1 in Initialize (param_1+0x12) */
    /* 0x094 */ uint8_t   pad_0x94[4];           /* UNKNOWN: alignment after i32 */
    /* 0x098 */ void     *texture_chunk_area;    /* PRES: param_1+0x13 in Initialize */
    /* 0x0A0 */ void     *render_object_ptr;     /* PRES: 0x340-byte alloc in Initialize */
    /* 0x0A8 */ uint8_t   ccUiObject_tail_0xA8[24]; /* UNKNOWN: tail of ccUiObject base */
    /* 0x0C0 */ int32_t   matrix_dirty;          /* SIM: set 1 in Init/SetMatrix, cleared 0 in _CalcWorldMatrixAll */
    /* 0x0C4 */ uint8_t   pad_0xC4[4];           /* UNKNOWN: alignment before ptr */
    /* 0x0C8 */ void     *nuccClump_ptr;         /* PRES: param_1[0x19] in Initialize */
    /* 0x0D0 */ void     *attachDummy_ptr;       /* PRES: param_1[0x1a], lazy alloc 0x80 in SetAttachDummy */
    /* 0x0D8 */ void     *fogParam_ptr;          /* PRES: param_1[0x1b], lazy alloc 0x10 in SetFog */
    /* 0x0E0 */ uint32_t  transform_dirty;       /* SIM: bitfield &1=offset_pos, &2=scale */
    /* 0x0E4 */ float     offset_pos[3];         /* SIM: Vector3::zero in Initialize, used when dirty&1 */
    /* 0x0F0 */ float     scale[3];              /* SIM: Vector3::one in Initialize, used when dirty&2 */
    /* 0x0FC */ float     bbox_size_x;           /* PRES: ABS width in SetupObjectSize */
    /* 0x100 */ float     bbox_size_y;           /* PRES: ABS height in SetupObjectSize */
    /* 0x104 */ uint8_t   world_matrix_pre[20];  /* SIM: first 20 bytes of float3x4 at param_1+0x104 */
    /* 0x118 */ void     *coord_const_ptr;       /* PRES: OVERLAY on world_matrix bytes 20-27, read in GetCoordConst */
    /* 0x120 */ uint8_t   world_matrix_post[20]; /* SIM: remaining 20 bytes of float3x4 matrix */
    /* 0x134 */ uint8_t   pad_0x134[16];         /* UNKNOWN: gap between matrix end and recalc flag */
    /* 0x144 */ uint32_t  matrix_recalc_flag;    /* SIM: 0=use cached world_matrix in _CalcWorldMatrixAll */
} __attribute__((packed)) ccUiClump;

/* Size assertion — proven by operator_new(0x148) in ccUiClump::ccUiClump (0x8247CC) */
static_assert(sizeof(ccUiClump) == 0x148, "ccUiClump size must be 0x148");

/* Field offset assertions — one per field */
static_assert(offsetof(ccUiClump, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiClump, secondary_ptr) == 0x008, "secondary_ptr");
static_assert(offsetof(ccUiClump, base_reserved_0x10) == 0x010, "base_reserved_0x10");
static_assert(offsetof(ccUiClump, chunk_name_str) == 0x018, "chunk_name_str");
static_assert(offsetof(ccUiClump, pad_0x38) == 0x038, "pad_0x38");
static_assert(offsetof(ccUiClump, field_0x3C) == 0x03C, "field_0x3C");
static_assert(offsetof(ccUiClump, vec_local_a) == 0x040, "vec_local_a");
static_assert(offsetof(ccUiClump, vec_local_b) == 0x04C, "vec_local_b");
static_assert(offsetof(ccUiClump, pad_0x58) == 0x058, "pad_0x58");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x60) == 0x060, "ccUiObject_field_0x60");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x68) == 0x068, "ccUiObject_field_0x68");
static_assert(offsetof(ccUiClump, texture_chunk_ptr) == 0x070, "texture_chunk_ptr");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x78) == 0x078, "ccUiObject_field_0x78");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x80) == 0x080, "ccUiObject_field_0x80");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x88) == 0x088, "ccUiObject_field_0x88");
static_assert(offsetof(ccUiClump, ccUiObject_flag_0x90) == 0x090, "ccUiObject_flag_0x90");
static_assert(offsetof(ccUiClump, pad_0x94) == 0x094, "pad_0x94");
static_assert(offsetof(ccUiClump, texture_chunk_area) == 0x098, "texture_chunk_area");
static_assert(offsetof(ccUiClump, render_object_ptr) == 0x0A0, "render_object_ptr");
static_assert(offsetof(ccUiClump, ccUiObject_tail_0xA8) == 0x0A8, "ccUiObject_tail_0xA8");
static_assert(offsetof(ccUiClump, matrix_dirty) == 0x0C0, "matrix_dirty");
static_assert(offsetof(ccUiClump, pad_0xC4) == 0x0C4, "pad_0xC4");
static_assert(offsetof(ccUiClump, nuccClump_ptr) == 0x0C8, "nuccClump_ptr");
static_assert(offsetof(ccUiClump, attachDummy_ptr) == 0x0D0, "attachDummy_ptr");
static_assert(offsetof(ccUiClump, fogParam_ptr) == 0x0D8, "fogParam_ptr");
static_assert(offsetof(ccUiClump, transform_dirty) == 0x0E0, "transform_dirty");
static_assert(offsetof(ccUiClump, offset_pos) == 0x0E4, "offset_pos");
static_assert(offsetof(ccUiClump, scale) == 0x0F0, "scale");
static_assert(offsetof(ccUiClump, bbox_size_x) == 0x0FC, "bbox_size_x");
static_assert(offsetof(ccUiClump, bbox_size_y) == 0x100, "bbox_size_y");
static_assert(offsetof(ccUiClump, world_matrix_pre) == 0x104, "world_matrix_pre");
static_assert(offsetof(ccUiClump, coord_const_ptr) == 0x118, "coord_const_ptr");
static_assert(offsetof(ccUiClump, world_matrix_post) == 0x120, "world_matrix_post");
static_assert(offsetof(ccUiClump, pad_0x134) == 0x134, "pad_0x134");
static_assert(offsetof(ccUiClump, matrix_recalc_flag) == 0x144, "matrix_recalc_flag");

#endif /* CMN10_S4_H */