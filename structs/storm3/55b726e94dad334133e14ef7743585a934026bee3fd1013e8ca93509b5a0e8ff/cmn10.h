/* Auto-generated cmn10 struct for build s3 (NSUNS3.exe) */
/* Object size: 0x148 (328 bytes), proven from allocator call ccFileLoadListForUi::LoadTh(0x148,...) in ccUiClump::ccUiClump (RVA 0x1F4FE4) */
/* All fields INFERRED from static analysis unless noted CONFIRMED */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)
typedef struct ccUiClump {
    uint8_t vtable[8];              /* 0x000 [PRES] high - vtable ptr, vfunc+0x08 called in ctor/Initialize, vfunc+0x10 at end */
    uint8_t secondary_ptr[8];       /* 0x008 [UNKNOWN] medium - inherited ccUiObject base field */
    uint8_t base_reserved_0x10[8];  /* 0x010 [UNKNOWN] low - inherited ccUiObject base */
    uint8_t chunk_name_str[32];     /* 0x018 [PRES] high - std::string, param_1+3 in Initialize */
    uint8_t pad_0x38[4];            /* 0x038 [UNKNOWN] low */
    int32_t field_0x3C;             /* 0x03C [UNKNOWN] medium */
    uint8_t vec_local_a[12];        /* 0x040 [SIM] high - local transform vector A (from s2 layout) */
    uint8_t vec_local_b[12];        /* 0x04C [SIM] high - local transform vector B (from s2 layout) */
    uint8_t pad_0x58[8];            /* 0x058 [UNKNOWN] low */
    uint8_t ccUiObject_field_0x60[8]; /* 0x060 [UNKNOWN] low */
    uint8_t ccUiObject_field_0x68[8]; /* 0x068 [UNKNOWN] low */
    uint8_t texture_chunk_ptr[8];   /* 0x070 [PRES] medium - texture chunk from xfbin (from s2 layout) */
    uint8_t ccUiObject_field_0x78[8]; /* 0x078 [UNKNOWN] low */
    uint8_t ccUiObject_field_0x80[8]; /* 0x080 [UNKNOWN] low - vtable+0x10 dispatch site read in Initialize */
    uint8_t ccUiObject_field_0x88[8]; /* 0x088 [UNKNOWN] medium - param_1[0x11], passed to ccGetUiObjectChunk */
    int32_t ccUiObject_flag_0x90;   /* 0x090 [PRES] medium - set to 1 in Initialize (param_1+0x12) */
    uint8_t pad_0x94[4];            /* 0x094 [UNKNOWN] low */
    uint8_t texture_chunk_area[8];  /* 0x098 [PRES] medium - param_1+0x13, passed to ccGetUiObjectChunk */
    uint8_t render_object_ptr[8];   /* 0x0A0 [PRES] medium - allocated 0x340 block (from s2 layout) */
    uint8_t ccUiObject_tail_0xA8[24]; /* 0x0A8 [UNKNOWN] low */
    int32_t matrix_dirty;           /* 0x0C0 [SIM] high - set 1 in Initialize/SetMatrix, cleared 0 in _CalcWorldMatrixAll (param_1+0x18) */
    uint8_t pad_0xC4[4];            /* 0x0C4 [UNKNOWN] low */
    uint8_t nuccClump_ptr[8];       /* 0x0C8 [PRES] high - param_1[0x19], nuccChunkClump handle */
    uint8_t attachDummy_ptr[8];     /* 0x0D0 [PRES] high - param_1[0x1a], SetAttachDummy target */
    uint8_t fogParam_ptr[8];        /* 0x0D8 [PRES] high - param_1[0x1b], lazy alloc 0x10 in SetFog */
    int32_t transform_dirty;        /* 0x0E0 [SIM] high - bitfield: &1=offset_pos, &2=scale (param_1+0x1c) */
    uint8_t offset_pos[12];         /* 0x0E4 [SIM] high - Vector3::zero in Initialize, used in UpdateMatrix */
    uint8_t scale[12];              /* 0x0F0 [SIM] high - Vector3::one in Initialize, used in UpdateMatrix */
    float bbox_size_x;              /* 0x0FC [PRES] high - ABS width from SetupObjectSize */
    float bbox_size_y;              /* 0x100 [PRES] high - ABS height from SetupObjectSize */
    /* world_matrix: SetIdentity/Set3x3Part operate on param_1+0x104 as float3x4 (48 bytes).
       coord_const_ptr at 0x118 overlaps bytes [20..27] of this region (row1 col1-col2 of 3x4).
       Documented as separate fields; coord_const_ptr reuses matrix storage when clump is active. */
    uint8_t world_matrix_pre[20];   /* 0x104 [SIM] high - first 20 bytes of float3x4 matrix (rows 0-1 partial) */
    uint8_t coord_const_ptr[8];     /* 0x118 [PRES] medium - OVERLAY: GetCoordConst reads ptr here; overlaps world_matrix bytes 20-27 */
    uint8_t world_matrix_post[20];  /* 0x120 [SIM] high - remaining 20 bytes of float3x4 matrix (rows 2-3) */
    uint8_t pad_0x134[16];          /* 0x134 [UNKNOWN] low - gap between matrix end and recalc flag */
    int32_t matrix_recalc_flag;     /* 0x144 [SIM] medium - checked in _CalcWorldMatrixAll, 0=use cached */
} ccUiClump;
#pragma pack(pop)

/* Offset assertions */
static_assert(offsetof(ccUiClump, vtable) == 0x000, "vtable offset mismatch");
static_assert(offsetof(ccUiClump, secondary_ptr) == 0x008, "secondary_ptr offset mismatch");
static_assert(offsetof(ccUiClump, base_reserved_0x10) == 0x010, "base_reserved_0x10 offset mismatch");
static_assert(offsetof(ccUiClump, chunk_name_str) == 0x018, "chunk_name_str offset mismatch");
static_assert(offsetof(ccUiClump, pad_0x38) == 0x038, "pad_0x38 offset mismatch");
static_assert(offsetof(ccUiClump, field_0x3C) == 0x03C, "field_0x3C offset mismatch");
static_assert(offsetof(ccUiClump, vec_local_a) == 0x040, "vec_local_a offset mismatch");
static_assert(offsetof(ccUiClump, vec_local_b) == 0x04C, "vec_local_b offset mismatch");
static_assert(offsetof(ccUiClump, pad_0x58) == 0x058, "pad_0x58 offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x60) == 0x060, "ccUiObject_field_0x60 offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x68) == 0x068, "ccUiObject_field_0x68 offset mismatch");
static_assert(offsetof(ccUiClump, texture_chunk_ptr) == 0x070, "texture_chunk_ptr offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x78) == 0x078, "ccUiObject_field_0x78 offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x80) == 0x080, "ccUiObject_field_0x80 offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_field_0x88) == 0x088, "ccUiObject_field_0x88 offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_flag_0x90) == 0x090, "ccUiObject_flag_0x90 offset mismatch");
static_assert(offsetof(ccUiClump, pad_0x94) == 0x094, "pad_0x94 offset mismatch");
static_assert(offsetof(ccUiClump, texture_chunk_area) == 0x098, "texture_chunk_area offset mismatch");
static_assert(offsetof(ccUiClump, render_object_ptr) == 0x0A0, "render_object_ptr offset mismatch");
static_assert(offsetof(ccUiClump, ccUiObject_tail_0xA8) == 0x0A8, "ccUiObject_tail_0xA8 offset mismatch");
static_assert(offsetof(ccUiClump, matrix_dirty) == 0x0C0, "matrix_dirty offset mismatch");
static_assert(offsetof(ccUiClump, pad_0xC4) == 0x0C4, "pad_0xC4 offset mismatch");
static_assert(offsetof(ccUiClump, nuccClump_ptr) == 0x0C8, "nuccClump_ptr offset mismatch");
static_assert(offsetof(ccUiClump, attachDummy_ptr) == 0x0D0, "attachDummy_ptr offset mismatch");
static_assert(offsetof(ccUiClump, fogParam_ptr) == 0x0D8, "fogParam_ptr offset mismatch");
static_assert(offsetof(ccUiClump, transform_dirty) == 0x0E0, "transform_dirty offset mismatch");
static_assert(offsetof(ccUiClump, offset_pos) == 0x0E4, "offset_pos offset mismatch");
static_assert(offsetof(ccUiClump, scale) == 0x0F0, "scale offset mismatch");
static_assert(offsetof(ccUiClump, bbox_size_x) == 0x0FC, "bbox_size_x offset mismatch");
static_assert(offsetof(ccUiClump, bbox_size_y) == 0x100, "bbox_size_y offset mismatch");
static_assert(offsetof(ccUiClump, world_matrix_pre) == 0x104, "world_matrix_pre offset mismatch");
static_assert(offsetof(ccUiClump, coord_const_ptr) == 0x118, "coord_const_ptr offset mismatch");
static_assert(offsetof(ccUiClump, world_matrix_post) == 0x120, "world_matrix_post offset mismatch");
static_assert(offsetof(ccUiClump, matrix_recalc_flag) == 0x144, "matrix_recalc_flag offset mismatch");
static_assert(sizeof(ccUiClump) == 0x148, "ccUiClump size mismatch");