/* cmn58.h — struct group cmn58 for build s1 (NSUNS1.exe)
 * INFERRED from static analysis. Not CONFIRMED.
 * Generated 2026-10-19.
 */
#ifndef CMN58_H
#define CMN58_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* nuccLayerSelOpacity — size proven 0x30 from factory FUN_1404d6c90 (LoadTh(0x30,...))
 * vtable: PTR_FUN_14073cc78
 * state_surface returned 0 fields (byte-cast only accesses).
 * Layout from constructor: [0]=vtable, [8]=param_2, [16]=str1_ptr, [24]=str2_ptr, [32]=0, [40]=0
 */
typedef struct nuccLayerSelOpacity {
    uint64_t vtable;      /* +0x00 */
    uint64_t param_copy;  /* +0x08 */
    uint64_t str1_ptr;    /* +0x10 */
    uint64_t str2_ptr;    /* +0x18 */
    uint64_t zero_a;      /* +0x20 */
    uint64_t zero_b;      /* +0x28 */
} nuccLayerSelOpacity;
static_assert(sizeof(nuccLayerSelOpacity) == 0x30, "nuccLayerSelOpacity size");
static_assert(offsetof(nuccLayerSelOpacity, vtable)     == 0x00, "nuccLayerSelOpacity.vtable");
static_assert(offsetof(nuccLayerSelOpacity, param_copy) == 0x08, "nuccLayerSelOpacity.param_copy");
static_assert(offsetof(nuccLayerSelOpacity, str1_ptr)   == 0x10, "nuccLayerSelOpacity.str1_ptr");
static_assert(offsetof(nuccLayerSelOpacity, str2_ptr)   == 0x18, "nuccLayerSelOpacity.str2_ptr");
static_assert(offsetof(nuccLayerSelOpacity, zero_a)     == 0x20, "nuccLayerSelOpacity.zero_a");
static_assert(offsetof(nuccLayerSelOpacity, zero_b)     == 0x28, "nuccLayerSelOpacity.zero_b");

/* nuccLayerSet — size proven >= 0x2A0 (BlockAllocator ctor at +0x298, vector fields at 0x280-0x290)
 * vtable: first PTR_FUN_1406584e8 (BlockAllocator), then PTR_FUN_140737188 (final)
 * Contains embedded nuccLayerList at +0x28, array of layer selectors at +0x10
 */
typedef struct nuccLayerSet {
    uint64_t vtable;              /* +0x00 */
    uint8_t  _pad_08[0x08];       /* +0x08 gap to 0x10 */
    uint64_t layer_selectors[8];  /* +0x10 array of selector ptrs, stride 8, ends at 0x50 */
    uint8_t  _pad_50[0x28];       /* +0x50 gap to 0x78 */
    uint64_t view_ptr;            /* +0x78 set in ctor from param_3 */
    uint8_t  _pad_80[0x200];      /* +0x80 gap to 0x280 (embedded nuccLayerList region) */
    uint64_t layer_tbl_data;      /* +0x280 vector data ptr */
    uint64_t layer_tbl_end;       /* +0x288 vector end ptr */
    uint64_t layer_tbl_capacity;  /* +0x290 vector capacity */
    uint8_t  block_allocator[8];  /* +0x298 BlockAllocator (size unproven, placeholder) */
} nuccLayerSet;
static_assert(sizeof(nuccLayerSet) == 0x2A0, "nuccLayerSet size");
static_assert(offsetof(nuccLayerSet, vtable)             == 0x00,  "nuccLayerSet.vtable");
static_assert(offsetof(nuccLayerSet, layer_selectors)    == 0x10,  "nuccLayerSet.layer_selectors");
static_assert(offsetof(nuccLayerSet, view_ptr)           == 0x78,  "nuccLayerSet.view_ptr");
static_assert(offsetof(nuccLayerSet, layer_tbl_data)     == 0x280, "nuccLayerSet.layer_tbl_data");
static_assert(offsetof(nuccLayerSet, layer_tbl_end)      == 0x288, "nuccLayerSet.layer_tbl_end");
static_assert(offsetof(nuccLayerSet, layer_tbl_capacity) == 0x290, "nuccLayerSet.layer_tbl_capacity");
static_assert(offsetof(nuccLayerSet, block_allocator)    == 0x298, "nuccLayerSet.block_allocator");

/* nuccLayerStencil — size proven 0xB0 from Create (LoadTh(0xB0,...))
 * vtable: PTR_FUN_14073fa58
 * Inherits nuccLayer base (0x58 bytes). 13 fields from state_surface.
 */
typedef struct nuccLayerStencil {
    uint64_t vtable;         /* +0x00 inherited nuccLayer vtable */
    uint8_t  _base[0x50];    /* +0x08 nuccLayer base fields (unreconstructed) */
    float    stencil_value;  /* +0x58 init 0x43960000 = 300.0f */
    uint32_t _gap_5C;        /* +0x5C padding */
    uint64_t field_60;       /* +0x60 init 0 */
    float    field_68;       /* +0x68 from DAT_140884af8+0x4aa */
    float    field_6C;       /* +0x6C from uVar2 */
    float    field_70;       /* +0x70 init 1.0f (0x3f800000) */
    uint32_t field_74;       /* +0x74 */
    uint32_t _gap_78;        /* +0x78 padding */
    uint64_t field_7C;       /* +0x7C init 0 */
    uint64_t field_84;       /* +0x84 init 0 */
    float    field_8C;       /* +0x8C init 1.0f */
    uint32_t field_90;       /* +0x90 init 0x1000ee0 */
    uint32_t field_94;       /* +0x94 from lVar3+0x18 */
    uint8_t  _pad_98[8];     /* +0x98 padding to 0xA0 */
    uint64_t field_A0;       /* +0xA0 init 0 */
    uint32_t field_A8;       /* +0xA8 init 0 */
    uint8_t  _pad_AC[4];     /* +0xAC padding to 0xB0 */
} nuccLayerStencil;
static_assert(sizeof(nuccLayerStencil) == 0xB0, "nuccLayerStencil size");
static_assert(offsetof(nuccLayerStencil, vtable)        == 0x00, "nuccLayerStencil.vtable");
static_assert(offsetof(nuccLayerStencil, stencil_value) == 0x58, "nuccLayerStencil.stencil_value");
static_assert(offsetof(nuccLayerStencil, field_60)      == 0x60, "nuccLayerStencil.field_60");
static_assert(offsetof(nuccLayerStencil, field_68)      == 0x68, "nuccLayerStencil.field_68");
static_assert(offsetof(nuccLayerStencil, field_6C)      == 0x6C, "nuccLayerStencil.field_6C");
static_assert(offsetof(nuccLayerStencil, field_70)      == 0x70, "nuccLayerStencil.field_70");
static_assert(offsetof(nuccLayerStencil, field_74)      == 0x74, "nuccLayerStencil.field_74");
static_assert(offsetof(nuccLayerStencil, field_7C)      == 0x7C, "nuccLayerStencil.field_7C");
static_assert(offsetof(nuccLayerStencil, field_84)      == 0x84, "nuccLayerStencil.field_84");
static_assert(offsetof(nuccLayerStencil, field_8C)      == 0x8C, "nuccLayerStencil.field_8C");
static_assert(offsetof(nuccLayerStencil, field_90)      == 0x90, "nuccLayerStencil.field_90");
static_assert(offsetof(nuccLayerStencil, field_94)      == 0x94, "nuccLayerStencil.field_94");
static_assert(offsetof(nuccLayerStencil, field_A0)      == 0xA0, "nuccLayerStencil.field_A0");
static_assert(offsetof(nuccLayerStencil, field_A8)      == 0xA8, "nuccLayerStencil.field_A8");

/* nuccLight — size proven 0x70 from ccCollectionDiorama::EntryLight (LoadTh(0x70,...))
 * vtable: PTR_FUN_140737428
 * 4 fields from state_surface at offsets 0x54, 0x58, 0x5C, 0x60
 */
typedef struct nuccLight {
    uint64_t vtable;       /* +0x00 */
    uint8_t  _base[0x4C];  /* +0x08 base fields (unreconstructed) */
    uint32_t field_54;     /* +0x54 from uVar1 in ctor */
    uint32_t field_58;     /* +0x58 ambiguous 4/8 byte write */
    uint32_t field_5C;     /* +0x5C from uVar4 in ctor */
    uint32_t intensity;    /* +0x60 copied from param_2+0x30 */
    uint8_t  _pad_64[0xC]; /* +0x64 padding to 0x70 */
} nuccLight;
static_assert(sizeof(nuccLight) == 0x70, "nuccLight size");
static_assert(offsetof(nuccLight, vtable)    == 0x00, "nuccLight.vtable");
static_assert(offsetof(nuccLight, field_54)  == 0x54, "nuccLight.field_54");
static_assert(offsetof(nuccLight, field_58)  == 0x58, "nuccLight.field_58");
static_assert(offsetof(nuccLight, field_5C)  == 0x5C, "nuccLight.field_5C");
static_assert(offsetof(nuccLight, intensity) == 0x60, "nuccLight.intensity");

/* nuccLightDirc — size >= 0xC0 (last field strm_frame at 0xB8 is uint32)
 * Inherits nuccLight (0x70). vtable: PTR_FUN_140739ad8
 * Matrix44_MathGeo at +0x70 (size 0x40), Vector3 at +0xB0 (size 0x08), strm_frame at +0xB8
 */
typedef struct nuccLightDirc {
    nuccLight base;          /* +0x00 inherits nuccLight (0x70) */
    uint8_t   matrix44[0x40];/* +0x70 Nucc::Matrix44_MathGeo (size inferred) */
    uint8_t   vector3[0x08]; /* +0xB0 Nucc::Vector3 (partial, size inferred) */
    uint32_t  strm_frame;    /* +0xB8 stream frame index */
    uint8_t   _pad_BC[4];    /* +0xBC padding */
} nuccLightDirc;
static_assert(sizeof(nuccLightDirc) == 0xC0, "nuccLightDirc size");
static_assert(offsetof(nuccLightDirc, base)       == 0x00, "nuccLightDirc.base");
static_assert(offsetof(nuccLightDirc, matrix44)   == 0x70, "nuccLightDirc.matrix44");
static_assert(offsetof(nuccLightDirc, vector3)    == 0xB0, "nuccLightDirc.vector3");
static_assert(offsetof(nuccLightDirc, strm_frame) == 0xB8, "nuccLightDirc.strm_frame");

#pragma pack(pop)

#endif /* CMN58_H */