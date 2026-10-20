/* cmn61.h — struct group cmn61 for build s2 (NSUNS2.exe)
 * INFERRED layout from static analysis. Not CONFIRMED.
 * All offsets/sizes from PC x64 decompilation (image base 0x140000000).
 * Sizes proven from FUN_140580190 allocator calls or ctor zero-init.
 */
#ifndef CMN61_S2_H
#define CMN61_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* C11 static_assert compatibility */
#if __STDC_VERSION__ >= 201112L
#define CMN61_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#else
#define CMN61_STATIC_ASSERT(cond, msg) typedef char _cmn61_sa_##__LINE__[(cond) ? 1 : -1]
#endif

#pragma pack(push, 1)

/* =========================================================================
 * nuccModelPrimitive — size 0x120 (proven: FUN_140580190(0x120) in FUN_140302584)
 * vtable: PTR_FUN_1408921f8 (set in ctor 0x5AC180)
 * 15 fields from state_surface + manual ctor analysis
 * ========================================================================= */
typedef struct nuccModelPrimitive {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_1408921f8, set in ctor 0x5AC180 */
    /* +0x08 */ uint8_t _pad_08[0x22];                /* gap to +0x2A */
    /* +0x2A */ uint32_t field_2A;                     /* w, ctor sets 0 */
    /* +0x2E */ uint8_t _pad_2E[0x52];                /* gap to +0x80 */
    /* +0x80 */ void *primitive_ptr;                   /* rw, Primitive sub-object ptr (ctor+SetColor) */
    /* +0x88 */ void *field_88;                        /* w, ctor sets 0 */
    /* +0x90 */ void *field_90;                        /* w, ctor sets 0 */
    /* +0x98 */ void *block_allocator;                 /* rw, BlockAllocator at +0x13*8 (ctor+dtor) */
    /* +0xA0 */ uint8_t _pad_A0[0x10];                /* gap to +0xB0 */
    /* +0xB0 */ void *field_B0;                        /* w, ctor sets 0 */
    /* +0xB8 */ uint32_t field_B8;                     /* w, ctor sets 0 */
    /* +0xBC */ uint8_t _pad_BC[0x04];                /* gap to +0xC0 */
    /* +0xC0 */ uint16_t field_C0;                     /* w, ctor sets 0 */
    /* +0xC2 */ uint8_t _pad_C2[0x02];                /* gap to +0xC4 */
    /* +0xC4 */ uint8_t matrix44[0x40];               /* r, Matrix44 passed to FUN_140586500 in ctor */
    /* +0x104 */ float field_104;                      /* w, ctor sets 0x3f400000 (0.75f) */
    /* +0x108 */ float field_108;                      /* w, ctor sets 0x3f800000 (1.0f) */
    /* +0x10C */ uint8_t _pad_10C[0x04];              /* gap to +0x110 */
    /* +0x110 */ uint32_t field_110;                   /* w, Create sets 1 */
    /* +0x114 */ uint8_t field_114;                    /* w, ctor sets 0 */
    /* +0x115 */ uint8_t _pad_115[0x03];              /* gap to +0x118 */
    /* +0x118 */ uint32_t field_118;                   /* w, ctor sets 0xffffffff (-1) */
    /* +0x11C */ uint8_t _pad_11C[0x04];              /* trailing pad to 0x120 */
} nuccModelPrimitive;

CMN61_STATIC_ASSERT(sizeof(nuccModelPrimitive) == 0x120, "nuccModelPrimitive size");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, vtable) == 0x00, "nuccModelPrimitive::vtable");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_2A) == 0x2A, "nuccModelPrimitive::field_2A");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, primitive_ptr) == 0x80, "nuccModelPrimitive::primitive_ptr");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_88) == 0x88, "nuccModelPrimitive::field_88");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_90) == 0x90, "nuccModelPrimitive::field_90");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, block_allocator) == 0x98, "nuccModelPrimitive::block_allocator");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_B0) == 0xB0, "nuccModelPrimitive::field_B0");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_B8) == 0xB8, "nuccModelPrimitive::field_B8");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_C0) == 0xC0, "nuccModelPrimitive::field_C0");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, matrix44) == 0xC4, "nuccModelPrimitive::matrix44");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_104) == 0x104, "nuccModelPrimitive::field_104");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_108) == 0x108, "nuccModelPrimitive::field_108");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_110) == 0x110, "nuccModelPrimitive::field_110");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_114) == 0x114, "nuccModelPrimitive::field_114");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_118) == 0x118, "nuccModelPrimitive::field_118");

/* =========================================================================
 * nuccModelPrimitiveBatch — size 0x170 (proven: FUN_140580190(0x170) in CreateInstance 0x5B6180)
 * vtable: PTR_FUN_140892678 (set in ctor 0x5B5E50)
 * 17 fields from state_surface + manual ctor analysis
 * ========================================================================= */
typedef struct nuccModelPrimitiveBatch {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_140892678, set in ctor 0x5B5E50 */
    /* +0x08 */ uint8_t _pad_08[0x22];                /* gap to +0x2A */
    /* +0x2A */ uint32_t field_2A;                     /* w, ctor sets 0 */
    /* +0x2E */ uint8_t _pad_2E[0x26];                /* gap to +0x54 */
    /* +0x54 */ float field_54;                        /* w, ctor sets 0x3f800000 (1.0f) */
    /* +0x58 */ uint16_t field_58;                     /* w, ctor sets 0 */
    /* +0x5A */ uint8_t _pad_5A[0x06];                /* gap to +0x60 */
    /* +0x60 */ void *field_60;                        /* w, ctor sets 0 */
    /* +0x68 */ void *field_68;                        /* rw, ctor+dtor check non-null */
    /* +0x70 */ void *field_70;                        /* w, ctor sets 0 */
    /* +0x78 */ uint32_t field_78;                     /* w, ctor sets 0 */
    /* +0x7C */ uint8_t field_7C;                      /* w, ctor sets 0 */
    /* +0x7D */ uint8_t _pad_7D[0x03];                /* gap to +0x80 */
    /* +0x80 */ uint32_t field_80;                     /* w, ctor sets 0 */
    /* +0x84 */ uint8_t _pad_84[0x04];                /* gap to +0x88 */
    /* +0x88 */ void *field_88;                        /* rw, ctor+dtor check non-null */
    /* +0x90 */ void *field_90;                        /* rw, ctor+dtor check non-null */
    /* +0x98 */ void *field_98;                        /* rw, ctor+dtor check non-null */
    /* +0xA0 */ uint32_t field_A0;                     /* w, ctor sets 0 */
    /* +0xA4 */ uint8_t _pad_A4[0x04];                /* gap to +0xA8 */
    /* +0xA8 */ void *field_A8;                        /* rw, ctor+dtor check non-null */
    /* +0xB0 */ uint8_t _pad_B0[0xA0];                /* gap to +0x150 */
    /* +0x150 */ void *field_150;                      /* w, ctor sets 0 */
    /* +0x158 */ void *field_158;                      /* w, ctor sets 0 */
    /* +0x160 */ void *field_160;                      /* w, ctor sets 0 */
    /* +0x168 */ uint8_t _pad_168[0x08];              /* trailing pad to 0x170 */
} nuccModelPrimitiveBatch;

CMN61_STATIC_ASSERT(sizeof(nuccModelPrimitiveBatch) == 0x170, "nuccModelPrimitiveBatch size");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, vtable) == 0x00, "nuccModelPrimitiveBatch::vtable");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_2A) == 0x2A, "nuccModelPrimitiveBatch::field_2A");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_54) == 0x54, "nuccModelPrimitiveBatch::field_54");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_58) == 0x58, "nuccModelPrimitiveBatch::field_58");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_60) == 0x60, "nuccModelPrimitiveBatch::field_60");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_68) == 0x68, "nuccModelPrimitiveBatch::field_68");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_70) == 0x70, "nuccModelPrimitiveBatch::field_70");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_78) == 0x78, "nuccModelPrimitiveBatch::field_78");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_7C) == 0x7C, "nuccModelPrimitiveBatch::field_7C");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_80) == 0x80, "nuccModelPrimitiveBatch::field_80");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_88) == 0x88, "nuccModelPrimitiveBatch::field_88");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_90) == 0x90, "nuccModelPrimitiveBatch::field_90");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_98) == 0x98, "nuccModelPrimitiveBatch::field_98");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_A0) == 0xA0, "nuccModelPrimitiveBatch::field_A0");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_A8) == 0xA8, "nuccModelPrimitiveBatch::field_A8");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_150) == 0x150, "nuccModelPrimitiveBatch::field_150");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_158) == 0x158, "nuccModelPrimitiveBatch::field_158");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_160) == 0x160, "nuccModelPrimitiveBatch::field_160");

/* =========================================================================
 * nuccMorphModel — size 0x50 (proven: FUN_140580190(0x50) in CreateInstance 0x622340)
 * vtable: PTR_FUN_14089c430 (set in CreateInstance 0x622340)
 * 3 fields from manual CreateInstance analysis (state_surface returned 0)
 * ========================================================================= */
typedef struct nuccMorphModel {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_14089c430, set in CreateInstance */
    /* +0x08 */ uint8_t _pad_08[0x18];                /* gap to +0x20 */
    /* +0x20 */ void *field_20;                        /* w, CreateInstance sets PTR_LAB_14089c450 */
    /* +0x28 */ uint8_t _pad_28[0x08];                /* gap to +0x30 */
    /* +0x30 */ void *field_30;                        /* w, CreateInstance sets PTR_LAB_14089c460 */
    /* +0x38 */ uint32_t field_38;                     /* w, CreateInstance sets 0 */
    /* +0x3C */ uint8_t _pad_3C[0x04];                /* gap to +0x40 */
    /* +0x40 */ void *field_40;                        /* rw, dtor reads param_1[8] */
    /* +0x48 */ void *field_48;                        /* rw, dtor reads param_1[9] */
} nuccMorphModel;

CMN61_STATIC_ASSERT(sizeof(nuccMorphModel) == 0x50, "nuccMorphModel size");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, vtable) == 0x00, "nuccMorphModel::vtable");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_20) == 0x20, "nuccMorphModel::field_20");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_30) == 0x30, "nuccMorphModel::field_30");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_38) == 0x38, "nuccMorphModel::field_38");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_40) == 0x40, "nuccMorphModel::field_40");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_48) == 0x48, "nuccMorphModel::field_48");

/* =========================================================================
 * nuccNudInfo — size 0x40 (proven: SetInfo writes param_1[0..7], dtor checks param_1[0])
 * No vtable (data struct, no virtual methods)
 * 8 fields from SetInfo 0x60D780 + dtor 0x60D6F0 analysis
 * ========================================================================= */
typedef struct nuccNudInfo {
    /* +0x00 */ void *field_00;                        /* rw, dtor checks non-null + frees */
    /* +0x08 */ uint8_t _pad_08[0x10];                /* gap to +0x18 */
    /* +0x18 */ void *field_18;                        /* rw, SetInfo writes param_1[3] = nud+0x30 */
    /* +0x20 */ void *field_20;                        /* rw, SetInfo writes param_1[4] */
    /* +0x28 */ void *field_28;                        /* rw, SetInfo writes param_1[5] */
    /* +0x30 */ void *field_30;                        /* rw, SetInfo writes param_1[6] */
    /* +0x38 */ void *field_38;                        /* rw, SetInfo writes param_1[7] */
} nuccNudInfo;

CMN61_STATIC_ASSERT(sizeof(nuccNudInfo) == 0x40, "nuccNudInfo size");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_00) == 0x00, "nuccNudInfo::field_00");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_18) == 0x18, "nuccNudInfo::field_18");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_20) == 0x20, "nuccNudInfo::field_20");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_28) == 0x28, "nuccNudInfo::field_28");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_30) == 0x30, "nuccNudInfo::field_30");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_38) == 0x38, "nuccNudInfo::field_38");

/* =========================================================================
 * nuccNutPictureInfo — size 0x38 (proven: GetInfo writes param_1[0..6])
 * No vtable (data struct)
 * 7 fields from GetInfo 0x61ED90 analysis
 * ========================================================================= */
typedef struct nuccNutPictureInfo {
    /* +0x00 */ void *field_00;                        /* w, GetInfo sets param_1[0] = nut base */
    /* +0x08 */ void *field_08;                        /* w, GetInfo sets param_1[1] = end of headers */
    /* +0x10 */ void *field_10;                        /* w, GetInfo sets param_1[2] = material data */
    /* +0x18 */ void *field_18;                        /* w, GetInfo sets param_1[3] = texture data */
    /* +0x20 */ void *field_20;                        /* w, GetInfo sets param_1[4] */
    /* +0x28 */ void *field_28;                        /* w, GetInfo sets param_1[5] */
    /* +0x30 */ void *field_30;                        /* w, GetInfo sets param_1[6] */
} nuccNutPictureInfo;

CMN61_STATIC_ASSERT(sizeof(nuccNutPictureInfo) == 0x38, "nuccNutPictureInfo size");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_00) == 0x00, "nuccNutPictureInfo::field_00");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_08) == 0x08, "nuccNutPictureInfo::field_08");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_10) == 0x10, "nuccNutPictureInfo::field_10");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_18) == 0x18, "nuccNutPictureInfo::field_18");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_20) == 0x20, "nuccNutPictureInfo::field_20");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_28) == 0x28, "nuccNutPictureInfo::field_28");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_30) == 0x30, "nuccNutPictureInfo::field_30");

#pragma pack(pop)

#endif /* CMN61_S2_H */
/* =========================================================================
 * nuccModelPrimitive::Primitive: no instance state
 * All 5 methods are static allocators/accessors operating on heap buffers
 * passed via param_1 (output pointer) or dereferenced from parent struct.
 * No vtable, no ctor, no this-pointer field access.
 * Evidence:
 *   Create    0x5AC2F0 - allocates buffer via FUN_140580510, writes to *param_1
 *   SetColor  0x5ACD20 - writes color to heap buffer at stride-based offset
 *   SetColor  0x30357C - reads parent fields (+0x3c,+0x70,+0xd0), calls 0x5ACD20
 *   SetUV     0x5ACD90 - writes UV to heap buffer at stride-based offset
 *   SetVertex 0x5ACF60 - writes vertex to heap buffer at stride-based offset
 * Buffer element sizes vary by type param: 0x40 (type 0), 0x30 (type 1/2), 0x20 (type 3)
 * ========================================================================= */
