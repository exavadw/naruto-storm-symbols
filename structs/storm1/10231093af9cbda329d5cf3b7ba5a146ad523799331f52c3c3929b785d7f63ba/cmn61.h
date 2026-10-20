/* cmn61.h — struct group cmn61 for build s1 (NSUNS1.exe)
 * INFERRED layout from static analysis. Not CONFIRMED.
 * All offsets/sizes from PC x64 decompilation (image base 0x140000000).
 * Sizes proven from ccFileLoadListForUi::LoadTh allocator calls or ctor zero-init.
 */
#ifndef CMN61_H
#define CMN61_H

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
 * nuccModelPrimitive — size 0x120 (proven: LoadTh(0x120) in FUN_1402e8ba0)
 * vtable: PTR_FUN_1407398f8
 * 14 fields from state_surface + manual ctor analysis
 * ========================================================================= */
typedef struct nuccModelPrimitive {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_1407398f8, set in ctor 0x4B1770 */
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
    /* +0xC4 */ uint8_t matrix44[0x40];               /* r, Matrix44 passed to FUN_140480da0 in ctor */
    /* +0x104 */ float field_104;                      /* w, ctor sets 0x3f400000 (0.75f) */
    /* +0x108 */ void *field_108;                      /* w, ctor sets 0x3f800000 (1.0f as ptr-sized) */
    /* +0x110 */ uint32_t field_110;                   /* w, ctor sets 0 */
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
 * nuccModelPrimitiveBatch — size 0x170 (proven: LoadTh(0x170) in CreateInstance 0x4C87D0)
 * vtable: PTR_FUN_14073b058
 * 17 fields from state_surface
 * ========================================================================= */
typedef struct nuccModelPrimitiveBatch {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_14073b058, set in ctor 0x4C84A0 */
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
 * nuccMorphModel — size 0x50 (proven: LoadTh(0x50) in CreateInstance 0x52A5E0)
 * vtable: PTR_FUN_140744848
 * 0 state_surface fields (param_1 element size unknown); dtor accesses +0x40,+0x48
 * ========================================================================= */
typedef struct nuccMorphModel {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_140744848 */
    /* +0x08 */ uint8_t _pad_08[0x38];                /* unknown interior */
    /* +0x40 */ void *field_40;                        /* accessed in dtor 0x52A510 (param_1[8]) */
    /* +0x48 */ void *field_48;                        /* accessed in dtor 0x52A510 (param_1[9]) */
} nuccMorphModel;

CMN61_STATIC_ASSERT(sizeof(nuccMorphModel) == 0x50, "nuccMorphModel size");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, vtable) == 0x00, "nuccMorphModel::vtable");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_40) == 0x40, "nuccMorphModel::field_40");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_48) == 0x48, "nuccMorphModel::field_48");

/* =========================================================================
 * nuccMorphPrimitive — size 0x70 (proven: LoadTh(0x70) in nuccChunkMorphPrimitive::Create 0x52A0A0)
 * vtable: PTR_FUN_1407447b0
 * Below 3-method threshold (2 methods); partial layout from Create + Initialize
 * ========================================================================= */
typedef struct nuccMorphPrimitive {
    /* +0x00 */ void *vtable;                          /* PTR_FUN_1407447b0, set in Create */
    /* +0x08 */ uint8_t _pad_08[0x10];                /* gap to +0x18 */
    /* +0x18 */ void *field_18;                        /* w, Initialize writes */
    /* +0x20 */ uint8_t _pad_20[0x10];                /* gap to +0x30 */
    /* +0x30 */ void *ptr_30;                          /* Create sets puVar1[6] = PTR_LAB_1407447e8 */
    /* +0x38 */ uint8_t _pad_38[0x08];                /* gap to +0x40 */
    /* +0x40 */ void *ptr_40;                          /* Create sets puVar1[5] = PTR_LAB_1407447d0 */
    /* +0x48 */ void *field_48;                        /* w, Initialize writes */
    /* +0x50 */ void *field_50;                        /* w, Initialize writes */
    /* +0x58 */ void *field_58;                        /* w, Initialize writes */
    /* +0x60 */ void *field_60;                        /* w, Initialize writes */
    /* +0x68 */ void *field_68;                        /* w, Initialize writes; dtor reads */
} nuccMorphPrimitive;

CMN61_STATIC_ASSERT(sizeof(nuccMorphPrimitive) == 0x70, "nuccMorphPrimitive size");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, vtable) == 0x00, "nuccMorphPrimitive::vtable");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, field_18) == 0x18, "nuccMorphPrimitive::field_18");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, ptr_30) == 0x30, "nuccMorphPrimitive::ptr_30");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, ptr_40) == 0x40, "nuccMorphPrimitive::ptr_40");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, field_48) == 0x48, "nuccMorphPrimitive::field_48");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, field_50) == 0x50, "nuccMorphPrimitive::field_50");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, field_58) == 0x58, "nuccMorphPrimitive::field_58");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, field_60) == 0x60, "nuccMorphPrimitive::field_60");
CMN61_STATIC_ASSERT(offsetof(nuccMorphPrimitive, field_68) == 0x68, "nuccMorphPrimitive::field_68");

/* =========================================================================
 * nuccNudInfo — size 0x38 (proven: ctor zeros 7 qwords = 0x38)
 * No vtable (plain data struct). 10 methods but state_surface returned 0 fields.
 * Layout from ctor (zero-init) + SetInfo (writes param_1[3..7]).
 * ========================================================================= */
typedef struct nuccNudInfo {
    /* +0x00 */ void *field_00;                        /* ctor zeros param_1[0] */
    /* +0x08 */ void *field_08;                        /* ctor zeros param_1[1] */
    /* +0x10 */ void *field_10;                        /* ctor zeros param_1[2] */
    /* +0x18 */ void *field_18;                        /* ctor zeros + SetInfo writes param_1[3] */
    /* +0x20 */ void *field_20;                        /* ctor zeros + SetInfo writes param_1[4] */
    /* +0x28 */ void *field_28;                        /* ctor zeros + SetInfo writes param_1[5] */
    /* +0x30 */ void *field_30;                        /* ctor zeros + SetInfo writes param_1[6] */
} nuccNudInfo;

CMN61_STATIC_ASSERT(sizeof(nuccNudInfo) == 0x38, "nuccNudInfo size");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_00) == 0x00, "nuccNudInfo::field_00");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_08) == 0x08, "nuccNudInfo::field_08");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_10) == 0x10, "nuccNudInfo::field_10");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_18) == 0x18, "nuccNudInfo::field_18");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_20) == 0x20, "nuccNudInfo::field_20");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_28) == 0x28, "nuccNudInfo::field_28");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_30) == 0x30, "nuccNudInfo::field_30");

/* =========================================================================
 * nuccNutPictureInfo — size 0x38 (proven: GetInfo writes 7 qwords)
 * Below 1-method threshold; report only. No vtable evidence.
 * ========================================================================= */
typedef struct nuccNutPictureInfo {
    /* +0x00 */ void *field_00;                        /* GetInfo writes param_1[0] */
    /* +0x08 */ void *field_08;                        /* GetInfo writes param_1[1] */
    /* +0x10 */ void *field_10;                        /* GetInfo writes param_1[2] */
    /* +0x18 */ void *field_18;                        /* GetInfo writes param_1[3] */
    /* +0x20 */ void *field_20;                        /* GetInfo writes param_1[4] */
    /* +0x28 */ void *field_28;                        /* GetInfo writes param_1[5] */
    /* +0x30 */ void *field_30;                        /* GetInfo writes param_1[6] */
} nuccNutPictureInfo;

CMN61_STATIC_ASSERT(sizeof(nuccNutPictureInfo) == 0x38, "nuccNutPictureInfo size");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_00) == 0x00, "nuccNutPictureInfo::field_00");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_08) == 0x08, "nuccNutPictureInfo::field_08");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_10) == 0x10, "nuccNutPictureInfo::field_10");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_18) == 0x18, "nuccNutPictureInfo::field_18");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_20) == 0x20, "nuccNutPictureInfo::field_20");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_28) == 0x28, "nuccNutPictureInfo::field_28");
CMN61_STATIC_ASSERT(offsetof(nuccNutPictureInfo, field_30) == 0x30, "nuccNutPictureInfo::field_30");

/* =========================================================================
 * nuccNode — size unknown, >= 0x28 (ConnectChild accesses +0x20 as 8-byte)
 * Below 2-method threshold; report only. No vtable evidence.
 * ========================================================================= */
/* Not reconstructed: below method threshold. See REPORT.md. */

/* =========================================================================
 * nuccModelPrimitive::Primitive — embedded sub-struct, not standalone
 * 4 methods. Allocated inline within nuccModelPrimitive at +0x80.
 * ========================================================================= */
/* Not reconstructed as standalone: embedded within nuccModelPrimitive. See REPORT.md. */

/* =========================================================================
 * nuccMorphPrimitiveDistortionP32N32C1UV1onPPU — static-like, no this pointer
 * 1 method (Morph). Report only.
 * ========================================================================= */
/* Not reconstructed: static function, no object layout. See REPORT.md. */

#pragma pack(pop)

#endif /* CMN61_H */