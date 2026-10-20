/*
 * cmn13.h — ccUiKeyHelp, ccUiKeyHelp::DefaultParam, ccUiLayout for s4 (NSUNS4_release.exe)
 * Build: s4 sha: 75912b image base: 0x140000000
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Sizes proven from operator_new calls in FUN_140af0c50 (ccUiKeyHelp) and
 * ccUiLayoutParts::CreateLayout (ccUiLayout).
 * Field names are generic (no own-game symbol mapping available for these classes in s4).
 */
#ifndef CMN13_S4_H
#define CMN13_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccUiKeyHelp::DefaultParam
 * Size: unknown, >= 0x2C (last write at +0x24 is uint64_t)
 * Only one method: DefaultParam ctor at RVA 0xB1D040.
 * Used as a global default-value struct (data xref only, no heap allocation found).
 * Ctor writes first 3 floats via Nucc::Vector3::Vector3 at +0x0,+0x4,+0x8.
 */
typedef struct __attribute__((packed)) ccUiKeyHelp_DefaultParam {
    float f0;       /* +0x00 Vector3.x = 0x44c80000 (1600.0f) */
    float f4;       /* +0x04 Vector3.y = 0x44228000 (650.0f) */
    float f8;       /* +0x08 Vector3.z = 0xc2dc0000 (-110.0f) */
    float fC;       /* +0x0C = 0xc3340000 (-180.0f) */
    float f10;      /* +0x10 = 0x42200000 (40.0f) */
    float f14;      /* +0x14 = 0x3f266666 (0.65f) */
    float f18;      /* +0x18 = 0x3f800000 (1.0f) */
    float f1C;      /* +0x1C = 0x3f800000 (1.0f) */
    float f20;      /* +0x20 = 0x3f4ccccd (0.8f) */
    uint64_t q24;   /* +0x24 = 0xff (255) */
} ccUiKeyHelp_DefaultParam;
/* size unknown, >= 0x2C — no sizeof assert */

static_assert(offsetof(ccUiKeyHelp_DefaultParam, f0) == 0x00, "DefaultParam.f0");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f4) == 0x04, "DefaultParam.f4");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f8) == 0x08, "DefaultParam.f8");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, fC) == 0x0C, "DefaultParam.fC");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f10) == 0x10, "DefaultParam.f10");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f14) == 0x14, "DefaultParam.f14");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f18) == 0x18, "DefaultParam.f18");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f1C) == 0x1C, "DefaultParam.f1C");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, f20) == 0x20, "DefaultParam.f20");
static_assert(offsetof(ccUiKeyHelp_DefaultParam, q24) == 0x24, "DefaultParam.q24");

/*
 * ccUiKeyHelp
 * Size: 0xF0 (proven by operator_new(0xf0,...) in FUN_140af0c50 @ RVA 0xAF0C50)
 * Vtable: VA 0x14111A0B0 (RVA 0x111A0B0), set in ctor at RVA 0xB1D0B0
 * Base classes: ccUiTaskBase (+0x00), ccUiOpenCloseCtrl (+0x38, param_1+7 in qword units)
 * 22 fields observed via state_surface + ctor symbolization.
 */
typedef struct __attribute__((packed)) ccUiKeyHelp {
    /* +0x00 */ void *vtable;           /* vptr = &PTR_FUN_14111a0b0 */
    /* +0x08 */ uint8_t base_task[0x30]; /* ccUiTaskBase region, +0x08..+0x37 */
    /* +0x38 */ uint8_t base_openclose[0x1C]; /* ccUiOpenCloseCtrl partial, +0x38..+0x53 */
    /* +0x54 */ uint64_t field_54;      /* w in ctor; = 0 */
    /* +0x5C */ uint32_t field_5C;      /* w in ctor; = 0 */
    /* +0x60 */ uint32_t field_60;      /* w in ctor; = 1 (param_1+0xc in qword) */
    /* +0x64 */ uint8_t gap_64[4];     /* padding */
    /* +0x68 */ uint32_t field_68;      /* w in ctor; = 0xffffffff */
    /* +0x6C */ uint8_t gap_6C[4];     /* padding */
    /* +0x70 */ uint64_t field_70;      /* w in ctor; = 0 (param_1[0xe]) */
    /* +0x78 */ uint64_t field_78;      /* r in DeleteHelp; pointer-like (param_1[0xf]) */
    /* +0x80 */ uint64_t field_80;      /* rw; vfunc dispatch (**(code**)(*param_1+0x10))(param_1) */
    /* +0x88 */ uint64_t field_88;      /* rw; FUN_140a01d60(param_1+0x11) */
    /* +0x90 */ uint64_t field_90;      /* rw; FUN_140a01cc0(param_1+0x12) */
    /* +0x98 */ uint8_t gap_98[8];     /* padding to 0xA0 */
    /* +0xA0 */ uint64_t field_A0;      /* w in ctor; = 0 (param_1[0x14]) */
    /* +0xA8 */ uint8_t field_A8[0x0C]; /* DName sub-object at param_1+0x15, init with &DAT_1416c1d90 */
    /* +0xB4 */ uint32_t field_B4;      /* w; = 1 in ctor/CreateData/DeleteHelp */
    /* +0xB8 */ uint32_t field_B8;      /* rw; copied from param in CreateData (param_1[0x17]) */
    /* +0xBC */ uint32_t field_BC;      /* rw; = 6 in ctor; passed to FUN_140b2aad0 */
    /* +0xC0 */ uint64_t field_C0;      /* w in ctor; = 0 (param_1[0x18]) */
    /* +0xC8 */ uint32_t field_C8;      /* w in ctor; = DAT_1416c1db4 */
    /* +0xCC */ uint32_t field_CC;      /* w in ctor; = DAT_1416c1da0 */
    /* +0xD0 */ float field_D0;         /* rw; scale factor, multiplied in CreateData (param_1+0x1a) */
    /* +0xD4 */ uint32_t field_D4;      /* w in ctor; = 3 */
    /* +0xD8 */ uint64_t field_D8;      /* w in ctor; = 0 (param_1[0x1b]) */
    /* +0xE0 */ uint64_t field_E0;      /* w in ctor; = 0 (param_1[0x1c]) */
    /* +0xE8 */ uint8_t field_E8;       /* w in ctor; = 0 (byte, param_1+0x1d) */
    /* +0xE9 */ uint8_t pad_E9[7];     /* padding to 0xF0 */
} ccUiKeyHelp;

static_assert(sizeof(ccUiKeyHelp) == 0xF0, "ccUiKeyHelp size must be 0xF0");
static_assert(offsetof(ccUiKeyHelp, vtable) == 0x00, "ccUiKeyHelp.vtable");
static_assert(offsetof(ccUiKeyHelp, base_task) == 0x08, "ccUiKeyHelp.base_task");
static_assert(offsetof(ccUiKeyHelp, base_openclose) == 0x38, "ccUiKeyHelp.base_openclose");
static_assert(offsetof(ccUiKeyHelp, field_54) == 0x54, "ccUiKeyHelp.field_54");
static_assert(offsetof(ccUiKeyHelp, field_5C) == 0x5C, "ccUiKeyHelp.field_5C");
static_assert(offsetof(ccUiKeyHelp, field_60) == 0x60, "ccUiKeyHelp.field_60");
static_assert(offsetof(ccUiKeyHelp, gap_64) == 0x64, "ccUiKeyHelp.gap_64");
static_assert(offsetof(ccUiKeyHelp, field_68) == 0x68, "ccUiKeyHelp.field_68");
static_assert(offsetof(ccUiKeyHelp, gap_6C) == 0x6C, "ccUiKeyHelp.gap_6C");
static_assert(offsetof(ccUiKeyHelp, field_70) == 0x70, "ccUiKeyHelp.field_70");
static_assert(offsetof(ccUiKeyHelp, field_78) == 0x78, "ccUiKeyHelp.field_78");
static_assert(offsetof(ccUiKeyHelp, field_80) == 0x80, "ccUiKeyHelp.field_80");
static_assert(offsetof(ccUiKeyHelp, field_88) == 0x88, "ccUiKeyHelp.field_88");
static_assert(offsetof(ccUiKeyHelp, field_90) == 0x90, "ccUiKeyHelp.field_90");
static_assert(offsetof(ccUiKeyHelp, gap_98) == 0x98, "ccUiKeyHelp.gap_98");
static_assert(offsetof(ccUiKeyHelp, field_A0) == 0xA0, "ccUiKeyHelp.field_A0");
static_assert(offsetof(ccUiKeyHelp, field_A8) == 0xA8, "ccUiKeyHelp.field_A8");
static_assert(offsetof(ccUiKeyHelp, field_B4) == 0xB4, "ccUiKeyHelp.field_B4");
static_assert(offsetof(ccUiKeyHelp, field_B8) == 0xB8, "ccUiKeyHelp.field_B8");
static_assert(offsetof(ccUiKeyHelp, field_BC) == 0xBC, "ccUiKeyHelp.field_BC");
static_assert(offsetof(ccUiKeyHelp, field_C0) == 0xC0, "ccUiKeyHelp.field_C0");
static_assert(offsetof(ccUiKeyHelp, field_C8) == 0xC8, "ccUiKeyHelp.field_C8");
static_assert(offsetof(ccUiKeyHelp, field_CC) == 0xCC, "ccUiKeyHelp.field_CC");
static_assert(offsetof(ccUiKeyHelp, field_D0) == 0xD0, "ccUiKeyHelp.field_D0");
static_assert(offsetof(ccUiKeyHelp, field_D4) == 0xD4, "ccUiKeyHelp.field_D4");
static_assert(offsetof(ccUiKeyHelp, field_D8) == 0xD8, "ccUiKeyHelp.field_D8");
static_assert(offsetof(ccUiKeyHelp, field_E0) == 0xE0, "ccUiKeyHelp.field_E0");
static_assert(offsetof(ccUiKeyHelp, field_E8) == 0xE8, "ccUiKeyHelp.field_E8");
static_assert(offsetof(ccUiKeyHelp, pad_E9) == 0xE9, "ccUiKeyHelp.pad_E9");

/*
 * ccUiLayout
 * Size: 0x148 (proven by operator_new(0x148,...) in ccUiLayoutParts::CreateLayout @ RVA 0xB04430)
 * Vtable: VA 0x141118AD0 (RVA 0x1118AD0), set in ctors at RVA 0xB01180 / 0xB034C0
 * Note: ctor at RVA 0x60EA34 uses different vtable (PTR_FUN_14106dd08) and base
 *       (ccDownloadContentsManager); this is a distinct subclass or variant.
 *       The main ccUiLayout ctors (0xB01180, 0xB034C0) use ccUiObjectContainer base.
 * Base class: ccUiObjectContainer (+0x08..+0x47 inferred)
 * 12 named fields + gaps from state_surface + ctor symbolization.
 */
typedef struct __attribute__((packed)) ccUiLayout {
    /* +0x000 */ void *vtable;          /* vptr = &PTR_FUN_141118ad0 */
    /* +0x008 */ uint8_t base[0x40];    /* ccUiObjectContainer region, +0x08..+0x47 */
    /* +0x048 */ uint32_t field_48;     /* w in ctor; = 1 (param_1+9 in qword = +0x48) */
    /* +0x04C */ uint8_t pad_4C[4];    /* padding to 0x50 */
    /* +0x050 */ uint8_t gap_50[0x28]; /* +0x50..+0x77: FUN_140b07050/FUN_140b06fe0 opaque sub-object */
    /* +0x078 */ uint64_t field_78;     /* r via FUN_140b06fe0; opaque sub-object (param_1+0xf) */
    /* +0x080 */ uint8_t gap_80[0x20]; /* +0x80..+0x9F: BlockAllocator / internal region */
    /* +0x0A0 */ uint64_t field_A0;     /* w in ctor; = 0 (param_1[0x14]) */
    /* +0x0A8 */ uint64_t field_A8;     /* w in ctor; = 0 (param_1[0x15]) */
    /* +0x0B0 */ uint64_t field_B0;     /* w in ctor; = 0 (param_1[0x16]) */
    /* +0x0B8 */ uint64_t field_B8;     /* rw; BlockAllocator init (param_1+0x17) */
    /* +0x0C0 */ uint8_t gap_C0[0x10]; /* +0xC0..+0xCF: not observed in any decompiled method */
    /* +0x0D0 */ uint64_t field_D0;     /* r via nuccPrintf(param_1+0x1a); opaque sub-object */
    /* +0x0D8 */ uint8_t gap_D8[0x30]; /* +0xD8..+0x107: BlockAllocator / internal region */
    /* +0x108 */ uint64_t field_108;    /* w in ctor; = param_3 (param_1[0x21]) */
    /* +0x110 */ uint64_t field_110;    /* w in ctor; = 0 (param_1[0x22]) */
    /* +0x118 */ uint64_t field_118;    /* w in ctor; = 0 (param_1[0x23]) */
    /* +0x120 */ uint64_t field_120;    /* w in ctor; = 0 (param_1[0x24]) */
    /* +0x128 */ uint64_t field_128;    /* rw; BlockAllocator init (param_1+0x25) */
    /* +0x130 */ uint8_t gap_130[0x10]; /* +0x130..+0x13F: not observed */
    /* +0x140 */ uint32_t field_140;    /* w in ctor; = 0 (param_1+0x28) */
    /* +0x144 */ uint8_t pad_144[4];   /* padding to 0x148 */
} ccUiLayout;

static_assert(sizeof(ccUiLayout) == 0x148, "ccUiLayout size must be 0x148");
static_assert(offsetof(ccUiLayout, vtable) == 0x000, "ccUiLayout.vtable");
static_assert(offsetof(ccUiLayout, base) == 0x008, "ccUiLayout.base");
static_assert(offsetof(ccUiLayout, field_48) == 0x048, "ccUiLayout.field_48");
static_assert(offsetof(ccUiLayout, pad_4C) == 0x04C, "ccUiLayout.pad_4C");
static_assert(offsetof(ccUiLayout, gap_50) == 0x050, "ccUiLayout.gap_50");
static_assert(offsetof(ccUiLayout, field_78) == 0x078, "ccUiLayout.field_78");
static_assert(offsetof(ccUiLayout, gap_80) == 0x080, "ccUiLayout.gap_80");
static_assert(offsetof(ccUiLayout, field_A0) == 0x0A0, "ccUiLayout.field_A0");
static_assert(offsetof(ccUiLayout, field_A8) == 0x0A8, "ccUiLayout.field_A8");
static_assert(offsetof(ccUiLayout, field_B0) == 0x0B0, "ccUiLayout.field_B0");
static_assert(offsetof(ccUiLayout, field_B8) == 0x0B8, "ccUiLayout.field_B8");
static_assert(offsetof(ccUiLayout, gap_C0) == 0x0C0, "ccUiLayout.gap_C0");
static_assert(offsetof(ccUiLayout, field_D0) == 0x0D0, "ccUiLayout.field_D0");
static_assert(offsetof(ccUiLayout, gap_D8) == 0x0D8, "ccUiLayout.gap_D8");
static_assert(offsetof(ccUiLayout, field_108) == 0x108, "ccUiLayout.field_108");
static_assert(offsetof(ccUiLayout, field_110) == 0x110, "ccUiLayout.field_110");
static_assert(offsetof(ccUiLayout, field_118) == 0x118, "ccUiLayout.field_118");
static_assert(offsetof(ccUiLayout, field_120) == 0x120, "ccUiLayout.field_120");
static_assert(offsetof(ccUiLayout, field_128) == 0x128, "ccUiLayout.field_128");
static_assert(offsetof(ccUiLayout, gap_130) == 0x130, "ccUiLayout.gap_130");
static_assert(offsetof(ccUiLayout, field_140) == 0x140, "ccUiLayout.field_140");
static_assert(offsetof(ccUiLayout, pad_144) == 0x144, "ccUiLayout.pad_144");

#endif /* CMN13_S4_H */