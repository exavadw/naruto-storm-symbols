/* cmn58.h — struct group cmn58 for build s3 (NSUNS3.exe x64)
 * INFERRED from static analysis. Not CONFIRMED.
 * Generated 2026-10-19.
 */
#ifndef CMN58_S3_H
#define CMN58_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* nuccLayerSelOpacity — size proven 0x30 from FUN_140683f70(0x30,...) at RVA 0x699030
 * vtable: PTR_FUN_1409e5c68 (set in ctor at RVA 0x6F1BE0)
 * state_surface returned 0 fields (byte-cast only accesses).
 * Layout from constructor: [0]=vtable, [8]=param_copy, [16]=str1_ptr, [24]=str2_ptr, [32]=0, [40]=0
 */
typedef struct nuccLayerSelOpacity {
    uint64_t vtable;       /* +0x00 */
    uint64_t param_copy;   /* +0x08 */
    uint64_t str1_ptr;     /* +0x10 heap-allocated name via FUN_140684040 */
    uint64_t str2_ptr;     /* +0x18 heap-allocated name via FUN_140684040 */
    uint64_t zero_a;       /* +0x20 init 0 */
    uint64_t zero_b;       /* +0x28 init 0 */
} nuccLayerSelOpacity;
static_assert(sizeof(nuccLayerSelOpacity) == 0x30, "nuccLayerSelOpacity size");
static_assert(offsetof(nuccLayerSelOpacity, vtable) == 0x00, "nuccLayerSelOpacity.vtable");
static_assert(offsetof(nuccLayerSelOpacity, param_copy) == 0x08, "nuccLayerSelOpacity.param_copy");
static_assert(offsetof(nuccLayerSelOpacity, str1_ptr) == 0x10, "nuccLayerSelOpacity.str1_ptr");
static_assert(offsetof(nuccLayerSelOpacity, str2_ptr) == 0x18, "nuccLayerSelOpacity.str2_ptr");
static_assert(offsetof(nuccLayerSelOpacity, zero_a) == 0x20, "nuccLayerSelOpacity.zero_a");
static_assert(offsetof(nuccLayerSelOpacity, zero_b) == 0x28, "nuccLayerSelOpacity.zero_b");

/* nuccLayerSet — size proven 0x2B0 from FUN_140683f70(0x2b0,...) at RVA 0x799490
 * vtable: PTR_FUN_1409e0400 (final, after overwrite of PTR_FUN_1409e04c0 in ctor at RVA 0x6B77C0)
 * Contains embedded nuccLayerList at +0x28, array of layer selectors at +0x80
 * NOTE: s3 grew +0x10 from s2's 0x2A0 to 0x2B0
 */
typedef struct nuccLayerSet {
    uint64_t vtable;              /* +0x00 */
    uint8_t _pad_08[0x08];        /* +0x08 gap to 0x10 */
    uint64_t field_10;            /* +0x10 copied from param_4[-1] if valid */
    uint64_t field_18;            /* +0x18 */
    uint64_t field_20;            /* +0x20 init 0 */
    uint8_t embedded_layer_list[0x50]; /* +0x28 embedded obj init via FUN_1406b7070 */
    uint8_t _pad_78_unused[0];    /* placeholder — view_ptr IS at 0x78 */
    uint64_t view_ptr;            /* +0x78 set from param_3 in ctor */
    uint8_t layer_selector_slots[0x200]; /* +0x80 array of 0x40 selector slots */
    uint64_t layer_tbl_data;      /* +0x280 vector data ptr */
    uint64_t layer_tbl_end;       /* +0x288 vector end ptr */
    uint64_t layer_tbl_capacity;  /* +0x290 vector capacity (init 0) */
    uint64_t block_allocator_vt;  /* +0x298 BlockAllocator vtable PTR_FUN_1409ec308 */
    uint8_t _pad_2A0[0x10];       /* +0x2A0 padding to proven size 0x2B0 */
} nuccLayerSet;
static_assert(sizeof(nuccLayerSet) == 0x2B0, "nuccLayerSet size");
static_assert(offsetof(nuccLayerSet, vtable) == 0x00, "nuccLayerSet.vtable");
static_assert(offsetof(nuccLayerSet, field_10) == 0x10, "nuccLayerSet.field_10");
static_assert(offsetof(nuccLayerSet, field_18) == 0x18, "nuccLayerSet.field_18");
static_assert(offsetof(nuccLayerSet, field_20) == 0x20, "nuccLayerSet.field_20");
static_assert(offsetof(nuccLayerSet, embedded_layer_list) == 0x28, "nuccLayerSet.embedded_layer_list");
static_assert(offsetof(nuccLayerSet, view_ptr) == 0x78, "nuccLayerSet.view_ptr");
static_assert(offsetof(nuccLayerSet, layer_selector_slots) == 0x80, "nuccLayerSet.layer_selector_slots");
static_assert(offsetof(nuccLayerSet, layer_tbl_data) == 0x280, "nuccLayerSet.layer_tbl_data");
static_assert(offsetof(nuccLayerSet, layer_tbl_end) == 0x288, "nuccLayerSet.layer_tbl_end");
static_assert(offsetof(nuccLayerSet, layer_tbl_capacity) == 0x290, "nuccLayerSet.layer_tbl_capacity");
static_assert(offsetof(nuccLayerSet, block_allocator_vt) == 0x298, "nuccLayerSet.block_allocator_vt");

/* nuccLayerSetInfo — value type, no vtable (not heap-allocated as standalone)
 * Size proven 0x10 from FUN_140683f70(0x10,...) at RVA 0x799490 in ccCmnScreen::ccCmnScreen
 * Layout: [0]=uint16(0xffff), [2]=uint8(0xff), [8]=nuccLayerSet ptr
 */
typedef struct nuccLayerSetInfo {
    uint16_t flags;          /* +0x00 init 0xffff */
    uint8_t  layer_index;    /* +0x02 init 0xff */
    uint8_t  _pad_03[5];     /* +0x03 padding to 0x08 */
    uint64_t layer_set_ptr;  /* +0x08 nuccLayerSet* */
} nuccLayerSetInfo;
static_assert(sizeof(nuccLayerSetInfo) == 0x10, "nuccLayerSetInfo size");
static_assert(offsetof(nuccLayerSetInfo, flags) == 0x00, "nuccLayerSetInfo.flags");
static_assert(offsetof(nuccLayerSetInfo, layer_index) == 0x02, "nuccLayerSetInfo.layer_index");
static_assert(offsetof(nuccLayerSetInfo, layer_set_ptr) == 0x08, "nuccLayerSetInfo.layer_set_ptr");

/* nuccLayerSetParam — size proven 0x58 from FUN_140683f70(0x58,...) at RVA 0x699410
 * No vtable (composite type with sub-objects that have their own vtables).
 * Two 0x28 BlockAllocator-based sub-objects + flag byte at +0x50.
 */
typedef struct nuccLayerSetParam {
    uint8_t base_subobject[0x28];  /* +0x00 BlockAllocator sub-object (FUN_1406edd40) */
    uint8_t param_subobject[0x28]; /* +0x28 BlockAllocator sub-object (FUN_1406edcd0) */
    uint8_t  flag;                 /* +0x50 init 0 */
    uint8_t  _pad_51[7];           /* +0x51 alignment padding to 0x58 */
} nuccLayerSetParam;
static_assert(sizeof(nuccLayerSetParam) == 0x58, "nuccLayerSetParam size");
static_assert(offsetof(nuccLayerSetParam, base_subobject) == 0x00, "nuccLayerSetParam.base_subobject");
static_assert(offsetof(nuccLayerSetParam, param_subobject) == 0x28, "nuccLayerSetParam.param_subobject");
static_assert(offsetof(nuccLayerSetParam, flag) == 0x50, "nuccLayerSetParam.flag");

/* nuccLayerStencil — size proven 0xB0 from FUN_140683f70(0xb0,...) at RVA 0x6990C0
 * vtable: PTR_FUN_1409e5cc8 (set in ctor at RVA 0x6F1F50)
 * Inherits nuccLayer base (0x58 bytes unreconstructed). 13 fields from state_surface.
 */
typedef struct nuccLayerStencil {
    uint64_t vtable;        /* +0x00 inherited nuccLayer vtable */
    uint8_t _base[0x48];    /* +0x08 nuccLayer base fields (unreconstructed, 0x48 bytes to reach 0x50) */
    uint64_t texture_chunk; /* +0x50 texture chunk ptr from FUN_14069e450("celshade") */
    float stencil_value;    /* +0x58 high conf: 0x43960000 (~300.0f) */
    uint32_t _gap_5C;       /* +0x5C padding */
    uint64_t field_60;      /* +0x60 init 0 */
    float field_68;         /* +0x68 from global DAT_140c24578+0x4aa */
    float field_6C;         /* +0x6C from global DAT_140c24578+0x4ac */
    float field_70;         /* +0x70 init 1.0f */
    uint32_t field_74;      /* +0x74 packed float store */
    uint32_t _gap_78;       /* +0x78 padding */
    uint64_t field_7C;      /* +0x7C init 0 */
    uint64_t field_84;      /* +0x84 init 0 */
    float field_8C;         /* +0x8C init 1.0f */
    uint32_t field_90;      /* +0x90 init 1.0f (0x3f800000) */
    uint32_t field_94;      /* +0x94 copied from texture chunk +0x18 */
    uint8_t _pad_98[8];     /* +0x98 padding to 0xA0 */
    uint64_t field_A0;      /* +0xA0 high conf: texture chunk ptr (stored twice?) */
    uint32_t field_A8;      /* +0xA8 init 0 */
    uint8_t _pad_AC[4];     /* +0xAC padding to 0xB0 */
} nuccLayerStencil;
static_assert(sizeof(nuccLayerStencil) == 0xB0, "nuccLayerStencil size");
static_assert(offsetof(nuccLayerStencil, vtable) == 0x00, "nuccLayerStencil.vtable");
static_assert(offsetof(nuccLayerStencil, texture_chunk) == 0x50, "nuccLayerStencil.texture_chunk");
static_assert(offsetof(nuccLayerStencil, stencil_value) == 0x58, "nuccLayerStencil.stencil_value");
static_assert(offsetof(nuccLayerStencil, field_60) == 0x60, "nuccLayerStencil.field_60");
static_assert(offsetof(nuccLayerStencil, field_68) == 0x68, "nuccLayerStencil.field_68");
static_assert(offsetof(nuccLayerStencil, field_6C) == 0x6C, "nuccLayerStencil.field_6C");
static_assert(offsetof(nuccLayerStencil, field_70) == 0x70, "nuccLayerStencil.field_70");
static_assert(offsetof(nuccLayerStencil, field_74) == 0x74, "nuccLayerStencil.field_74");
static_assert(offsetof(nuccLayerStencil, field_7C) == 0x7C, "nuccLayerStencil.field_7C");
static_assert(offsetof(nuccLayerStencil, field_84) == 0x84, "nuccLayerStencil.field_84");
static_assert(offsetof(nuccLayerStencil, field_8C) == 0x8C, "nuccLayerStencil.field_8C");
static_assert(offsetof(nuccLayerStencil, field_90) == 0x90, "nuccLayerStencil.field_90");
static_assert(offsetof(nuccLayerStencil, field_94) == 0x94, "nuccLayerStencil.field_94");
static_assert(offsetof(nuccLayerStencil, field_A0) == 0xA0, "nuccLayerStencil.field_A0");
static_assert(offsetof(nuccLayerStencil, field_A8) == 0xA8, "nuccLayerStencil.field_A8");

/* nuccLight — abstract base class, size UNPROVEN (only subclasses are heap-allocated)
 * Inferred minimum size >= 0x68 from highest field write at offset 0x64 in default ctor.
 * vtable: PTR_FUN_1409e3668 (set in both ctors at RVA 0x6D9330 and 0x6D93F0)
 * Fields from state_surface: 0x54(w), 0x58(w), 0x5C(w), 0x60(w).
 * This struct is provided for reference only; use subclass structs for allocation.
 */
typedef struct nuccLight {
    uint64_t vtable;        /* +0x00 */
    uint8_t _base_08[0x10]; /* +0x08 gap */
    uint64_t field_18;      /* +0x18 copied from param_2+0x08 */
    uint32_t light_type;    /* +0x20 from param_2+0x10 */
    uint32_t _pad_24;       /* +0x24 */
    uint64_t field_28;      /* +0x28 init 0 */
    uint64_t field_30;      /* +0x30 init 0 */
    uint64_t coord_chunk;   /* +0x38 from FUN_1406d4220 if param_3 != 0 */
    uint32_t field_40;      /* +0x40 from param_2+0x20 */
    uint32_t _pad_44;       /* +0x44 */
    uint64_t field_48;      /* +0x48 */
    uint32_t field_50;      /* +0x50 from param_2+0x28 */
    uint32_t field_54;      /* +0x54 from param_2+0x24 */
    uint32_t field_58;      /* +0x58 from param_2+0x28 (state_surface w) */
    uint32_t field_5C;      /* +0x5C from param_2+0x2c */
    uint32_t field_60;      /* +0x60 from param_2+0x30 (state_surface w, high) */
    uint32_t field_64;      /* +0x64 from param_2+0x34 */
} nuccLight;
/* No sizeof assert: size unproven for abstract base. Last known field at 0x64 => >= 0x68. */
static_assert(offsetof(nuccLight, vtable) == 0x00, "nuccLight.vtable");
static_assert(offsetof(nuccLight, field_18) == 0x18, "nuccLight.field_18");
static_assert(offsetof(nuccLight, light_type) == 0x20, "nuccLight.light_type");
static_assert(offsetof(nuccLight, field_28) == 0x28, "nuccLight.field_28");
static_assert(offsetof(nuccLight, field_30) == 0x30, "nuccLight.field_30");
static_assert(offsetof(nuccLight, coord_chunk) == 0x38, "nuccLight.coord_chunk");
static_assert(offsetof(nuccLight, field_40) == 0x40, "nuccLight.field_40");
static_assert(offsetof(nuccLight, field_48) == 0x48, "nuccLight.field_48");
static_assert(offsetof(nuccLight, field_50) == 0x50, "nuccLight.field_50");
static_assert(offsetof(nuccLight, field_54) == 0x54, "nuccLight.field_54");
static_assert(offsetof(nuccLight, field_58) == 0x58, "nuccLight.field_58");
static_assert(offsetof(nuccLight, field_5C) == 0x5C, "nuccLight.field_5C");
static_assert(offsetof(nuccLight, field_60) == 0x60, "nuccLight.field_60");
static_assert(offsetof(nuccLight, field_64) == 0x64, "nuccLight.field_64");

/* nuccLightDirc — size proven 0xC0 from FUN_140683f70(0xc0,...) at RVA 0x6F2980
 * vtable: PTR_FUN_1409e32a8 (overrides base nuccLight vtable, set in ctor at RVA 0x6D2640)
 * Inherits nuccLight base (>= 0x68). Matrix44 at +0x70 (0x40), Vector3 at +0xB0, strm_frame at +0xB8.
 * state_surface fields: 0x60(w), 0x70(r), 0xB0(r), 0x100(r virtual call).
 */
typedef struct nuccLightDirc {
    uint8_t base[0x70];       /* +0x00 inherits nuccLight (padded to 0x70 for alignment) */
    uint8_t matrix44[0x40];   /* +0x70 Nucc::Matrix44 init via FUN_1406856b0 */
    uint8_t vector3[0x08];    /* +0xB0 Nucc::Vector3 init via FUN_140684430 */
    uint32_t strm_frame;      /* +0xB8 stream frame index */
    uint8_t _pad_BC[4];       /* +0xBC padding to 0xC0 */
} nuccLightDirc;
static_assert(sizeof(nuccLightDirc) == 0xC0, "nuccLightDirc size");
static_assert(offsetof(nuccLightDirc, base) == 0x00, "nuccLightDirc.base");
static_assert(offsetof(nuccLightDirc, matrix44) == 0x70, "nuccLightDirc.matrix44");
static_assert(offsetof(nuccLightDirc, vector3) == 0xB0, "nuccLightDirc.vector3");
static_assert(offsetof(nuccLightDirc, strm_frame) == 0xB8, "nuccLightDirc.strm_frame");

#pragma pack(pop)

#endif /* CMN58_S3_H */