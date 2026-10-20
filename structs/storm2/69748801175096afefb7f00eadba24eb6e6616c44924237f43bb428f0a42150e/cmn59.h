/* cmn59.h — NARUTO STORM 2 PC (NSUNS2.exe) struct group cmn59
 * Reconstructed from x64 decompile. All static analysis is INFERRED.
 * Sizes proven from game code (operator_new / LoadTh arguments), never sizeof.
 * gcc-clean: gcc -fsyntax-only -x c -std=c11 cmn59.h
 */
#ifndef CMN59_H
#define CMN59_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================== */
/* nuccLightModeTbl — embedded in ccLightManager, not heap-allocated          */
/* Size: unknown, >= 0x28 (highest proven access: param_1[4] at +0x20=count) */
/* Vtable: PTR_FUN_1408914f8 (INFERRED from ctor 0x5CCF60)                   */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccLightModeTbl {
    void     *vtable;      /* 0x00 PTR_FUN_1408914f8 */
    uint8_t   _pad_08[0x10]; /* 0x08 .. 0x17 base/allocator region */
    uint8_t  *array_ptr;   /* 0x18 param_1[3] with undefined8* = byte 0x18 */
    uint32_t  count;       /* 0x20 *(undefined4*)(param_1+4) with undefined8* = byte 0x20 */
    uint8_t   _pad_24[4];  /* 0x24 pad to 0x28 */
} nuccLightModeTbl;

static_assert(offsetof(nuccLightModeTbl, vtable)    == 0x00, "nuccLightModeTbl.vtable");
static_assert(offsetof(nuccLightModeTbl, array_ptr) == 0x18, "nuccLightModeTbl.array_ptr");
static_assert(offsetof(nuccLightModeTbl, count)     == 0x20, "nuccLightModeTbl.count");

/* ========================================================================== */
/* nuccLightParam_inner — embedded sub-object at outer+0x60                   */
/* Layout from inner ctor 0x5CD040 and setter methods                         */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccLightParam_inner {
    float ambient_color_r;    /* 0x00 Vector4.x */
    float ambient_color_g;    /* 0x04 Vector4.y */
    float ambient_color_b;    /* 0x08 Vector4.z */
    float ambient_color_a;    /* 0x0C Vector4.w */
    float dirc_base_r;        /* 0x10 second Vector4 */
    float dirc_base_g;        /* 0x14 */
    float dirc_base_b;        /* 0x18 */
    float dirc_base_a;        /* 0x1C */
    float field_0x20_r;       /* 0x20 third Vector4 */
    float field_0x24_g;       /* 0x24 */
    float field_0x28_b;       /* 0x28 */
    float field_0x2c_a;       /* 0x2C */
    uint8_t dirc_lights[0x80]; /* 0x30 loop stride 0x20, ~4 iterations */
    uint8_t point_params[0xC0]; /* 0xB0 loop stride 0x30, ~4 iterations */
    uint16_t dirc_num;         /* 0x170 *(undefined2*)(param_1+0x170) */
    uint8_t  _pad_172[0x9E];   /* 0x172 pad to end of known inner region */
} nuccLightParam_inner;

static_assert(offsetof(nuccLightParam_inner, ambient_color_r) == 0x00,  "inner.ambient_color_r");
static_assert(offsetof(nuccLightParam_inner, dirc_lights)     == 0x30,  "inner.dirc_lights");
static_assert(offsetof(nuccLightParam_inner, point_params)    == 0xB0,  "inner.point_params");
static_assert(offsetof(nuccLightParam_inner, dirc_num)        == 0x170, "inner.dirc_num");

/* ========================================================================== */
/* nuccLightParam — stack-allocated composite                                 */
/* Size: unknown, >= 0x284 (highest write at +0x280, 4 bytes)                 */
/* Outer ctor embeds inner at +0x60, nuccCelshadeParam at +0x1E0              */
/* Vtable: PTR_FUN_1408934a8 (INFERRED from outer ctor 0x5C0570)             */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccLightParam {
    void     *vtable;           /* 0x000 PTR_FUN_1408934a8 */
    uint8_t   _pad_008[0x58];   /* 0x008 .. 0x05F base init region */
    nuccLightParam_inner inner; /* 0x060 embedded inner ctor at param_1+0xc (undefined8*) = byte 0x60 */
    /* inner ends at 0x060 + 0x210 = 0x270. CelshadeParam at byte 0x1E0 overlaps inner tail. */
    uint8_t   tail[0x10];       /* 0x270 .. 0x27F gap to last proven write */
    uint32_t  field_0x280;      /* 0x280 last proven write (float 1.0f) */
} nuccLightParam;

static_assert(offsetof(nuccLightParam, vtable)     == 0x000, "nuccLightParam.vtable");
static_assert(offsetof(nuccLightParam, inner)      == 0x060, "nuccLightParam.inner");
static_assert(offsetof(nuccLightParam, field_0x280)== 0x280, "nuccLightParam.field_0x280");

/* ========================================================================== */
/* nuccLightPoint — inherits nuccLight, heap-allocated                        */
/* Size: 0x90 (proven from LoadTh(0x90,...) in nuccChunkLightPoint::Create 0x5E6560) */
/* Vtable: PTR_FUN_140894ca8 (INFERRED from ctor 0x5CC840)                   */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccLightPoint {
    void     *vtable;          /* 0x00 PTR_FUN_140894ca8 (nuccLight base vtable) */
    uint8_t   base_fields[0x48]; /* 0x08 .. 0x4F nuccLight base members */
    float     color_vec4[4];   /* 0x50 SetStrmFrame writes Vector4 here (param_1+10, longlong*) */
    uint32_t  strm_frame;      /* 0x60 SetStrmFrame writes uint (param_1+0xc, longlong*) */
    uint8_t   _pad_64[0x0C];   /* 0x64 .. 0x6F */
    uint8_t   position[12];    /* 0x70 Vector3 (SetStrmFrame param_1[0xe]=byte 0x70) */
    uint32_t  field_0x7c;      /* 0x7C Calc writes position data here */
    uint32_t  field_0x80;      /* 0x80 padding/unused */
    uint32_t  field_0x84;      /* 0x84 w, local_10 in ctor/Calc */
    uint32_t  field_0x88;      /* 0x88 w, uVar6 in ctor/SetStrmFrame */
    uint32_t  field_0x8C;      /* 0x8C w, uVar7 in ctor/SetStrmFrame */
} nuccLightPoint;

static_assert(sizeof(nuccLightPoint) == 0x90, "nuccLightPoint size == 0x90");
static_assert(offsetof(nuccLightPoint, vtable)     == 0x00, "nuccLightPoint.vtable");
static_assert(offsetof(nuccLightPoint, color_vec4) == 0x50, "nuccLightPoint.color_vec4");
static_assert(offsetof(nuccLightPoint, strm_frame) == 0x60, "nuccLightPoint.strm_frame");
static_assert(offsetof(nuccLightPoint, position)   == 0x70, "nuccLightPoint.position");
static_assert(offsetof(nuccLightPoint, field_0x7c) == 0x7C, "nuccLightPoint.field_0x7c");
static_assert(offsetof(nuccLightPoint, field_0x84) == 0x84, "nuccLightPoint.field_0x84");
static_assert(offsetof(nuccLightPoint, field_0x88) == 0x88, "nuccLightPoint.field_0x88");
static_assert(offsetof(nuccLightPoint, field_0x8C) == 0x8C, "nuccLightPoint.field_0x8C");

/* ========================================================================== */
/* nuccLoadBankManager — heap-allocated                                       */
/* Size: 0x68 (proven from operator_new(0x68,...) in nuccDrawEnv::Initialize 0x5A67C0) */
/* Vtable: none found (no virtual methods detected)                           */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccLoadBankManager {
    uint32_t  bitmap[8];              /* 0x00 256-bit bank bitmap, Entry scans [0..7]×4 */
    uint8_t   critical_section[0x28]; /* 0x20 nuccCriticalSection, Entry Lock/Unlock at +0x20 */
    uint8_t   _pad_48[0x20];          /* 0x48 gap to proven size 0x68 */
} nuccLoadBankManager;

static_assert(sizeof(nuccLoadBankManager) == 0x68, "nuccLoadBankManager size == 0x68");
static_assert(offsetof(nuccLoadBankManager, bitmap)           == 0x00, "nuccLoadBankManager.bitmap");
static_assert(offsetof(nuccLoadBankManager, critical_section) == 0x20, "nuccLoadBankManager.critical_section");

/* ========================================================================== */
/* nuccLoadRequest — inherits nuccRequest, heap-allocated                     */
/* Size: 0xa8 (proven from LoadTh(0xa8,...) in nuccXfbinDocManager::LoadThRequest 0x593D00) */
/* Vtable: PTR_FUN_1408932b0 (INFERRED from ctor 0x5BEAE0)                   */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccLoadRequest {
    void     *vtable;              /* 0x00 PTR_FUN_1408932b0 (nuccRequest base) */
    uint8_t   base_fields[0x08];   /* 0x08 nuccRequest base */
    uint8_t   block_allocator[0x18]; /* 0x10 BlockAllocator at param_1+2 (undefined8*) = byte 0x10 */
    uint8_t   _pad_28[0x30];       /* 0x28 .. 0x57 zeroed region (param_1[2]..param_1[10]) */
    uint8_t   critical_section[0x28]; /* 0x58 nuccCriticalSection at param_1+0xb (undefined8*) = byte 0x58 */
    uint8_t   _pad_80[0x28];       /* 0x80 gap to proven size 0xa8 */
} nuccLoadRequest;

static_assert(sizeof(nuccLoadRequest) == 0xa8, "nuccLoadRequest size == 0xa8");
static_assert(offsetof(nuccLoadRequest, vtable)           == 0x00, "nuccLoadRequest.vtable");
static_assert(offsetof(nuccLoadRequest, block_allocator)  == 0x10, "nuccLoadRequest.block_allocator");
static_assert(offsetof(nuccLoadRequest, critical_section) == 0x58, "nuccLoadRequest.critical_section");

/* ========================================================================== */
/* nuccMakeNut — stack-allocated                                              */
/* Size: unknown, >= 0x5C (highest rw access at +0x58, 4 bytes)               */
/* No vtable (stack object, no virtual dispatch)                              */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccMakeNut {
    uint8_t   magic[4];          /* 0x00 NTP3/NTXR/NTWD magic, CreatePass1 writes */
    uint16_t  version;           /* 0x04 uint16 version = 1 */
    uint8_t   _pad_06[0x0A];     /* 0x06 .. 0x0F */
    uint32_t  field_0x10;        /* 0x10 w, 0x745865 in CreatePass1 */
    uint32_t  field_0x14;        /* 0x14 w, 0x20 in CreatePass1 */
    uint32_t  field_0x18;        /* 0x18 w, 0x10 in CreatePass1 */
    uint8_t   _pad_1c[0x04];     /* 0x1C .. 0x1F */
    uint64_t  vec_begin;         /* 0x20 vector<ptr> begin */
    uint64_t  vec_end;           /* 0x28 vector<ptr> end */
    uint64_t  vec_capacity;      /* 0x30 vector<ptr> capacity (inferred) */
    uint8_t   block_alloc[0x18]; /* 0x38 .. 0x4F BlockAllocator region */
    uint32_t  alloc_count;       /* 0x50 rw, total size in CreatePass1 */
    uint32_t  format;            /* 0x54 rw, 0=NTP3 1=NTXR 2=NTWD */
    uint32_t  flags;             /* 0x58 rw, checked != 0 in Create */
} nuccMakeNut;

static_assert(offsetof(nuccMakeNut, magic)        == 0x00, "nuccMakeNut.magic");
static_assert(offsetof(nuccMakeNut, version)      == 0x04, "nuccMakeNut.version");
static_assert(offsetof(nuccMakeNut, field_0x10)   == 0x10, "nuccMakeNut.field_0x10");
static_assert(offsetof(nuccMakeNut, field_0x14)   == 0x14, "nuccMakeNut.field_0x14");
static_assert(offsetof(nuccMakeNut, field_0x18)   == 0x18, "nuccMakeNut.field_0x18");
static_assert(offsetof(nuccMakeNut, vec_begin)    == 0x20, "nuccMakeNut.vec_begin");
static_assert(offsetof(nuccMakeNut, vec_end)      == 0x28, "nuccMakeNut.vec_end");
static_assert(offsetof(nuccMakeNut, vec_capacity) == 0x30, "nuccMakeNut.vec_capacity");
static_assert(offsetof(nuccMakeNut, block_alloc)  == 0x38, "nuccMakeNut.block_alloc");
static_assert(offsetof(nuccMakeNut, alloc_count)  == 0x50, "nuccMakeNut.alloc_count");
static_assert(offsetof(nuccMakeNut, format)       == 0x54, "nuccMakeNut.format");
static_assert(offsetof(nuccMakeNut, flags)        == 0x58, "nuccMakeNut.flags");

/* ========================================================================== */
/* nuccMaterial — heap-allocated                                              */
/* Size: 0x88 (proven from LoadTh(0x88,...) in nuccChunkMaterial::Create 0x5F3D20) */
/* Vtable: PTR_FUN_140831270 (INFERRED from ctor 0x5AD7B0)                   */
/* ========================================================================== */
typedef struct __attribute__((packed)) nuccMaterial {
    void     *vtable;            /* 0x00 PTR_FUN_140831270 */
    uint8_t   _pad_08[0x10];     /* 0x08 .. 0x17 */
    void     *shader_vtable;     /* 0x18 Init dereferences vtable here */
    uint8_t   _pad_20[0x10];     /* 0x20 .. 0x2F */
    uint32_t  field_0x30;        /* 0x30 Init copies uint32 from shader */
    uint32_t  field_0x34;        /* 0x34 Init copies uint32 from shader */
    float     texcoord_0_u;      /* 0x38 Vector2 #1 */
    float     texcoord_0_v;      /* 0x3C */
    float     texcoord_1_u;      /* 0x40 Vector2 #2 */
    float     texcoord_1_v;      /* 0x44 */
    float     texcoord_2_u;      /* 0x48 Vector2 #3 */
    float     texcoord_2_v;      /* 0x4C */
    float     texcoord_3_u;      /* 0x50 Vector2 #4 */
    float     texcoord_3_v;      /* 0x54 */
    float     texcoord_4_u;      /* 0x58 Vector2 #5 */
    float     texcoord_4_v;      /* 0x5C */
    float     texcoord_5_u;      /* 0x60 Vector2 #6 */
    float     texcoord_5_v;      /* 0x64 */
    float     screen_offset_x;   /* 0x68 GetShaderParam_screenOffset reads */
    float     screen_offset_y;   /* 0x6C */
    float     screen_offset_z;   /* 0x70 */
    float     screen_offset_w;   /* 0x74 */
    uint32_t  field_0x78;        /* 0x78 Init copies uint32 */
    uint32_t  field_0x7c;        /* 0x7C Init copies uint32 */
    uint32_t  field_0x80;        /* 0x80 SetShaderParam reads */
    uint32_t  field_0x84;        /* 0x84 SetShaderParam reads float/255.0 */
} nuccMaterial;

static_assert(sizeof(nuccMaterial) == 0x88, "nuccMaterial size == 0x88");
static_assert(offsetof(nuccMaterial, vtable)          == 0x00, "nuccMaterial.vtable");
static_assert(offsetof(nuccMaterial, shader_vtable)   == 0x18, "nuccMaterial.shader_vtable");
static_assert(offsetof(nuccMaterial, field_0x30)      == 0x30, "nuccMaterial.field_0x30");
static_assert(offsetof(nuccMaterial, texcoord_0_u)    == 0x38, "nuccMaterial.texcoord_0_u");
static_assert(offsetof(nuccMaterial, screen_offset_x) == 0x68, "nuccMaterial.screen_offset_x");
static_assert(offsetof(nuccMaterial, field_0x78)      == 0x78, "nuccMaterial.field_0x78");
static_assert(offsetof(nuccMaterial, field_0x84)      == 0x84, "nuccMaterial.field_0x84");

#endif /* CMN59_H */