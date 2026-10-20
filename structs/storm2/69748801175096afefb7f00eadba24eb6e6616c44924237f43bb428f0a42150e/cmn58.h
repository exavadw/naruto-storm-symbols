/* cmn58.h — struct group cmn58 for build s2 (NSUNS2.exe)
 * INFERRED from static analysis. Not CONFIRMED.
 * Generated 2026-10-19.
 */
#ifndef CMN58_S2_H
#define CMN58_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* nuccLayerSelOpacity — size proven 0x30 from factory FUN_1405a4ad0 (LoadTh(0x30,...))
 * vtable: PTR_FUN_140897178
 * state_surface returned 0 fields (byte-cast only accesses).
 * Layout from constructor at 0x5E5610: [0]=vtable, [8]=param_2, [16]=str1_ptr, [24]=str2_ptr, [32]=0, [40]=0
 */
typedef struct nuccLayerSelOpacity {
    uint64_t vtable;       /* +0x00 */
    uint64_t param_copy;   /* +0x08 */
    uint64_t str1_ptr;     /* +0x10 */
    uint64_t str2_ptr;     /* +0x18 */
    uint64_t zero_a;       /* +0x20 */
    uint64_t zero_b;       /* +0x28 */
} nuccLayerSelOpacity;
static_assert(sizeof(nuccLayerSelOpacity) == 0x30, "nuccLayerSelOpacity size");
static_assert(offsetof(nuccLayerSelOpacity, vtable) == 0x00, "nuccLayerSelOpacity.vtable");
static_assert(offsetof(nuccLayerSelOpacity, param_copy) == 0x08, "nuccLayerSelOpacity.param_copy");
static_assert(offsetof(nuccLayerSelOpacity, str1_ptr) == 0x10, "nuccLayerSelOpacity.str1_ptr");
static_assert(offsetof(nuccLayerSelOpacity, str2_ptr) == 0x18, "nuccLayerSelOpacity.str2_ptr");
static_assert(offsetof(nuccLayerSelOpacity, zero_a) == 0x20, "nuccLayerSelOpacity.zero_a");
static_assert(offsetof(nuccLayerSelOpacity, zero_b) == 0x28, "nuccLayerSelOpacity.zero_b");

/* nuccLayerSet — size proven >= 0x2A0 (BlockAllocator ctor at +0x298, vector fields at 0x280-0x290)
 * vtable: first PTR_FUN_140831270 (BlockAllocator), then PTR_FUN_140891608 (final)
 * Contains embedded nuccLayerList at +0x28, array of layer selectors at +0x10
 */
typedef struct nuccLayerSet {
    uint64_t vtable;              /* +0x00 */
    uint8_t _pad_08[0x08];        /* +0x08 gap to 0x10 */
    uint64_t layer_selectors[8];  /* +0x10 array of selector ptrs, stride 8, ends at 0x50 */
    uint8_t _pad_50[0x28];        /* +0x50 gap to 0x78 */
    uint64_t view_ptr;            /* +0x78 set in ctor from param_3 */
    uint8_t _pad_80[0x200];       /* +0x80 gap to 0x280 (embedded nuccLayerList region) */
    uint64_t layer_tbl_data;      /* +0x280 vector data ptr */
    uint64_t layer_tbl_end;       /* +0x288 vector end ptr */
    uint64_t layer_tbl_capacity;  /* +0x290 vector capacity */
    uint8_t block_allocator[8];   /* +0x298 BlockAllocator (size unproven, placeholder) */
} nuccLayerSet;
static_assert(sizeof(nuccLayerSet) == 0x2A0, "nuccLayerSet size");
static_assert(offsetof(nuccLayerSet, vtable) == 0x00, "nuccLayerSet.vtable");
static_assert(offsetof(nuccLayerSet, layer_selectors) == 0x10, "nuccLayerSet.layer_selectors");
static_assert(offsetof(nuccLayerSet, view_ptr) == 0x78, "nuccLayerSet.view_ptr");
static_assert(offsetof(nuccLayerSet, layer_tbl_data) == 0x280, "nuccLayerSet.layer_tbl_data");
static_assert(offsetof(nuccLayerSet, layer_tbl_end) == 0x288, "nuccLayerSet.layer_tbl_end");
static_assert(offsetof(nuccLayerSet, layer_tbl_capacity) == 0x290, "nuccLayerSet.layer_tbl_capacity");
static_assert(offsetof(nuccLayerSet, block_allocator) == 0x298, "nuccLayerSet.block_allocator");

/* nuccLayerSetInfo — small value type, no vtable (not heap-allocated)
 * Size >= 0x10 from ctor at 0x5A5BC0 and accessor reads at +0x08.
 * Layout: [0]=uint16(0xffff), [1]=uint8 index, [8]=nuccLayerSet ptr
 */
typedef struct nuccLayerSetInfo {
    uint16_t flags;          /* +0x00 init 0xffff */
    uint8_t  layer_index;    /* +0x02 init 0xff */
    uint8_t  _pad_03[5];     /* +0x03 padding to 0x08 */
    uint64_t layer_set_ptr;  /* +0x08 nuccLayerSet* from accessors */
} nuccLayerSetInfo;
static_assert(sizeof(nuccLayerSetInfo) == 0x10, "nuccLayerSetInfo size");
static_assert(offsetof(nuccLayerSetInfo, flags) == 0x00, "nuccLayerSetInfo.flags");
static_assert(offsetof(nuccLayerSetInfo, layer_index) == 0x02, "nuccLayerSetInfo.layer_index");
static_assert(offsetof(nuccLayerSetInfo, layer_set_ptr) == 0x08, "nuccLayerSetInfo.layer_set_ptr");

/* nuccLayerSetParam — size >= 0x58 (two 0x28 sub-objects + byte at +0x50, aligned)
 * No vtable found in ctor; contains two BlockAllocator-based sub-objects.
 * Base sub-object at +0x00 (FUN_1405e1a30), second at +0x28 (FUN_1405e19c0), flag at +0x50.
 */
typedef struct nuccLayerSetParam {
    uint8_t base_subobject[0x28];  /* +0x00 BlockAllocator sub-object (FUN_1405e1a30) */
    uint8_t param_subobject[0x28]; /* +0x28 BlockAllocator sub-object (FUN_1405e19c0) */
    uint8_t  flag;                 /* +0x50 init 0 */
    uint8_t  _pad_51[7];           /* +0x51 alignment padding to 0x58 */
} nuccLayerSetParam;
static_assert(sizeof(nuccLayerSetParam) == 0x58, "nuccLayerSetParam size");
static_assert(offsetof(nuccLayerSetParam, base_subobject) == 0x00, "nuccLayerSetParam.base_subobject");
static_assert(offsetof(nuccLayerSetParam, param_subobject) == 0x28, "nuccLayerSetParam.param_subobject");
static_assert(offsetof(nuccLayerSetParam, flag) == 0x50, "nuccLayerSetParam.flag");

/* nuccLayerStencil — size proven 0xB0 from Create factory FUN_14058d470 (LoadTh(0xB0,...))
 * vtable: PTR_FUN_1408971d8
 * Inherits nuccLayer base (0x58 bytes). 13 fields from state_surface.
 */
typedef struct nuccLayerStencil {
    uint64_t vtable;        /* +0x00 inherited nuccLayer vtable */
    uint8_t _base[0x50];    /* +0x08 nuccLayer base fields (unreconstructed) */
    float stencil_value;    /* +0x58 high conf write in ctor */
    uint32_t _gap_5C;       /* +0x5C padding */
    uint64_t field_60;      /* +0x60 medium conf write */
    float field_68;         /* +0x68 medium conf write */
    float field_6C;         /* +0x6C medium conf write */
    float field_70;         /* +0x70 medium conf write */
    uint32_t field_74;      /* +0x74 medium conf write */
    uint32_t _gap_78;       /* +0x78 padding */
    uint64_t field_7C;      /* +0x7C medium conf write */
    uint64_t field_84;      /* +0x84 medium conf write */
    float field_8C;         /* +0x8C medium conf write */
    uint32_t field_90;      /* +0x90 medium conf write */
    uint32_t field_94;      /* +0x94 medium conf write */
    uint8_t _pad_98[8];     /* +0x98 padding to 0xA0 */
    uint64_t field_A0;      /* +0xA0 high conf write in ctor */
    uint32_t field_A8;      /* +0xA8 medium conf write */
    uint8_t _pad_AC[4];     /* +0xAC padding to 0xB0 */
} nuccLayerStencil;
static_assert(sizeof(nuccLayerStencil) == 0xB0, "nuccLayerStencil size");
static_assert(offsetof(nuccLayerStencil, vtable) == 0x00, "nuccLayerStencil.vtable");
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

/* nuccLightDirc — size >= 0xC0 (last field strm_frame at 0xB8 is uint32, inherits nuccLight 0x70)
 * vtable: PTR_FUN_140894c70
 * Inherits nuccLight (0x70). Matrix44 at +0x70 (0x40), Vector3 at +0xB0 (0x08), strm_frame at +0xB8.
 * Note: nuccLight itself has only 2 methods in s2 (below threshold); listed as report-only.
 */
typedef struct nuccLightDirc {
    uint8_t base[0x70];       /* +0x00 inherits nuccLight (0x70, unreconstructed in s2) */
    uint8_t matrix44[0x40];   /* +0x70 Nucc::Matrix44_MathGeo (size inferred from s1) */
    uint8_t vector3[0x08];    /* +0xB0 Nucc::Vector3 (partial, size inferred from s1) */
    uint32_t strm_frame;      /* +0xB8 stream frame index */
    uint8_t _pad_BC[4];       /* +0xBC padding */
} nuccLightDirc;
static_assert(sizeof(nuccLightDirc) == 0xC0, "nuccLightDirc size");
static_assert(offsetof(nuccLightDirc, base) == 0x00, "nuccLightDirc.base");
static_assert(offsetof(nuccLightDirc, matrix44) == 0x70, "nuccLightDirc.matrix44");
static_assert(offsetof(nuccLightDirc, vector3) == 0xB0, "nuccLightDirc.vector3");
static_assert(offsetof(nuccLightDirc, strm_frame) == 0xB8, "nuccLightDirc.strm_frame");

/* nuccLight — size 0x70 (proven by nuccLightDirc ctor at 0x5CC590: matrix44 at param_1+0xe=0x70)
 * vtable: PTR_FUN_140898a70
 * Base class for nuccLightDirc. Inherits BlockAllocator.
 * Fields from ctors at 0x601660 and 0x601720. All INFERRED.
 */
typedef struct nuccLight {
    uint64_t vtable;          /* +0x00 PTR_FUN_140898a70 */
    uint8_t _base_08[0x10];   /* +0x08 BlockAllocator base (inherited) */
    uint64_t field_18;        /* +0x18 from param_2+8 in main ctor */
    uint8_t _pad_20[0x20];    /* +0x20 gap to 0x40 */
    uint32_t field_40;        /* +0x40 from param_2+0x10 in main ctor */
    uint8_t _pad_44[0x0C];    /* +0x44 gap to 0x50 */
    uint8_t field_50[8];      /* +0x50 two packed floats (0x3f8000003f800000 in copy ctor) */
    uint32_t field_58;        /* +0x58 from param_2+0x2c */
    uint32_t field_5C;        /* +0x5C from param_2+0x2c */
    uint32_t field_60;        /* +0x60 from param_2+0x30 (1.0f default) */
    uint32_t field_64;        /* +0x64 from param_2+0x34 (0xffffffff default) */
    uint8_t _pad_68[0x08];    /* +0x68 padding to 0x70 (confirmed by subclass layout) */
} nuccLight;
static_assert(sizeof(nuccLight) == 0x70, "nuccLight size");
static_assert(offsetof(nuccLight, vtable) == 0x00, "nuccLight.vtable");
static_assert(offsetof(nuccLight, _base_08) == 0x08, "nuccLight._base_08");
static_assert(offsetof(nuccLight, _pad_20) == 0x20, "nuccLight._pad_20");
static_assert(offsetof(nuccLight, _pad_44) == 0x44, "nuccLight._pad_44");
static_assert(offsetof(nuccLight, _pad_68) == 0x68, "nuccLight._pad_68");
static_assert(offsetof(nuccLight, field_18) == 0x18, "nuccLight.field_18");
static_assert(offsetof(nuccLight, field_40) == 0x40, "nuccLight.field_40");
static_assert(offsetof(nuccLight, field_50) == 0x50, "nuccLight.field_50");
static_assert(offsetof(nuccLight, field_58) == 0x58, "nuccLight.field_58");
static_assert(offsetof(nuccLight, field_5C) == 0x5C, "nuccLight.field_5C");
static_assert(offsetof(nuccLight, field_60) == 0x60, "nuccLight.field_60");
static_assert(offsetof(nuccLight, field_64) == 0x64, "nuccLight.field_64");

#pragma pack(pop)

#endif /* CMN58_S2_H */
