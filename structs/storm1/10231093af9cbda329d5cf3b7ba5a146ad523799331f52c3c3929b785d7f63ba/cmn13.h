/*
 * cmn13.h — ccUiKeyHelp, ccUiKeyHelp::DefaultParam, ccUiLayout for s1 (NSUNS1.exe)
 * Build: s1 sha: 10231093af9c image base: 0x140000000
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Sizes proven from allocator calls in factory functions.
 * Field names are generic (no own-game symbol mapping succeeded for s1).
 */
#ifndef CMN13_S1_H
#define CMN13_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccUiKeyHelp::DefaultParam
 * Size: unknown, >= 0x2C (last write at +0x24 is uint64_t)
 * Only one method: DefaultParam ctor at RVA 0x58BBD0.
 * Used as a global default-value struct (data xref only, no heap allocation found).
 * FUN_14047f8e0 writes first 3 floats at +0x0,+0x4,+0x8.
 */
typedef struct __attribute__((packed)) ccUiKeyHelp_DefaultParam {
    float f0;       /* +0x00 FUN_14047f8e0 arg1 = 0x44c80000 (1600.0f) */
    float f4;       /* +0x04 FUN_14047f8e0 arg2 = 0x44228000 (650.0f) */
    float f8;       /* +0x08 FUN_14047f8e0 arg3 = 0xc2dc0000 (-110.0f) */
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
 * Size: 0xF0 (proven by FUN_14047ed10(0xf0,...) in ccUiSelectWindow::CreateKeyHelp @ RVA 0x577450)
 * Vtable: VA 0x140749AD8 (RVA 0x749AD8), set in ctor at RVA 0x58BC40
 * 16 fields observed via state_surface; base class occupies +0x00..+0x77 (inferred).
 */
typedef struct __attribute__((packed)) ccUiKeyHelp {
    /* +0x00 */ void *vtable;         /* vptr = &PTR_FUN_140749ad8 */
    /* +0x08 */ uint8_t base[0x70];   /* base class / padding, +0x08..+0x77 */
    /* +0x78 */ uint64_t field_78;    /* read in DeleteHelp,ccUiKeyHelp; pointer-like */
    /* +0x80 */ uint64_t field_80;    /* rw; vfunc dispatch (**(code**)(*param_1+0x10))(param_1) */
    /* +0x88 */ uint8_t field_88[0x18]; /* read via FUN_14047f280(param_1+0x11); opaque sub-struct */
    /* +0xA0 */ uint64_t field_A0;    /* w in ctor; = 0 */
    /* +0xA8 */ uint8_t field_A8[0x0C]; /* read via FUN_14047f8a0(param_1+0x15,&DAT); opaque */
    /* +0xB4 */ uint32_t field_B4;    /* w; = 1 in ctor/CreateData/DeleteHelp */
    /* +0xB8 */ uint32_t field_B8;    /* rw; copied from param in CreateData */
    /* +0xBC */ uint32_t field_BC;    /* rw; = 6 in ctor; passed to FUN_140591020 */
    /* +0xC0 */ uint64_t field_C0;    /* w in ctor; = 0 */
    /* +0xC8 */ uint32_t field_C8;    /* w in ctor; = DAT_1408dd3c4 */
    /* +0xCC */ uint32_t field_CC;    /* w in ctor; = DAT_1408dd3b0 */
    /* +0xD0 */ float field_D0;       /* rw; scale factor, multiplied in CreateData */
    /* +0xD4 */ uint32_t field_D4;    /* w in ctor; = 3 */
    /* +0xD8 */ uint64_t field_D8;    /* w in ctor; = 0 */
    /* +0xE0 */ uint64_t field_E0;    /* w in ctor; = 0 */
    /* +0xE8 */ uint8_t field_E8;     /* w in ctor; = 0 (byte) */
    /* +0xE9 */ uint8_t pad_E9[7];   /* padding to 0xF0 */
} ccUiKeyHelp;

static_assert(sizeof(ccUiKeyHelp) == 0xF0, "ccUiKeyHelp size must be 0xF0");
static_assert(offsetof(ccUiKeyHelp, vtable) == 0x00, "ccUiKeyHelp.vtable");
static_assert(offsetof(ccUiKeyHelp, base) == 0x08, "ccUiKeyHelp.base");
static_assert(offsetof(ccUiKeyHelp, field_78)== 0x78, "ccUiKeyHelp.field_78");
static_assert(offsetof(ccUiKeyHelp, field_80)== 0x80, "ccUiKeyHelp.field_80");
static_assert(offsetof(ccUiKeyHelp, field_88)== 0x88, "ccUiKeyHelp.field_88");
static_assert(offsetof(ccUiKeyHelp, field_A0)== 0xA0, "ccUiKeyHelp.field_A0");
static_assert(offsetof(ccUiKeyHelp, field_A8)== 0xA8, "ccUiKeyHelp.field_A8");
static_assert(offsetof(ccUiKeyHelp, field_B4)== 0xB4, "ccUiKeyHelp.field_B4");
static_assert(offsetof(ccUiKeyHelp, field_B8)== 0xB8, "ccUiKeyHelp.field_B8");
static_assert(offsetof(ccUiKeyHelp, field_BC)== 0xBC, "ccUiKeyHelp.field_BC");
static_assert(offsetof(ccUiKeyHelp, field_C0)== 0xC0, "ccUiKeyHelp.field_C0");
static_assert(offsetof(ccUiKeyHelp, field_C8)== 0xC8, "ccUiKeyHelp.field_C8");
static_assert(offsetof(ccUiKeyHelp, field_CC)== 0xCC, "ccUiKeyHelp.field_CC");
static_assert(offsetof(ccUiKeyHelp, field_D0)== 0xD0, "ccUiKeyHelp.field_D0");
static_assert(offsetof(ccUiKeyHelp, field_D4)== 0xD4, "ccUiKeyHelp.field_D4");
static_assert(offsetof(ccUiKeyHelp, field_D8)== 0xD8, "ccUiKeyHelp.field_D8");
static_assert(offsetof(ccUiKeyHelp, field_E0)== 0xE0, "ccUiKeyHelp.field_E0");
static_assert(offsetof(ccUiKeyHelp, field_E8)== 0xE8, "ccUiKeyHelp.field_E8");
static_assert(offsetof(ccUiKeyHelp, pad_E9) == 0xE9, "ccUiKeyHelp.pad_E9");

/*
 * ccUiLayout
 * Size: 0x148 (proven by FUN_14047ed10(0x148,...) in ccUiLayoutParts::CreateLayout @ RVA 0x56DC40)
 * Vtable: VA 0x140748278 (RVA 0x748278), set in ctor at RVA 0x56A990
 * 12 fields observed via state_surface at offsets:
 *   0x78, 0xA0, 0xA8, 0xB0, 0xB8, 0xD0, 0x108, 0x110, 0x118, 0x120, 0x128, 0x140
 * Ctor also writes *(uint32*)(param_1+9)=1 which is offset 0x48 (9*8=0x48 with uint64*).
 */
typedef struct __attribute__((packed)) ccUiLayout {
    /* +0x000 */ void *vtable;          /* vptr = &PTR_FUN_140748278 */
    /* +0x008 */ uint8_t base[0x40];    /* base class / padding, +0x08..+0x47 */
    /* +0x048 */ uint32_t field_48;     /* w in ctor; = 1 (param_1[9] with uint32*) */
    /* +0x04C */ uint8_t pad_4C[4];     /* alignment to +0x50 */
    /* +0x050 */ uint8_t gap_50[0x28];  /* +0x50..+0x77: initialized by FUN_140570630/FUN_1405705c0 */
    /* +0x078 */ uint8_t field_78[0x28];/* r via FUN_1405705c0(param_1+0xf); opaque sub-object */
    /* +0x0A0 */ uint64_t field_A0;     /* w in ctor; = 0 */
    /* +0x0A8 */ uint64_t field_A8;     /* w in ctor; = 0 */
    /* +0x0B0 */ uint64_t field_B0;     /* w in ctor; = 0 */
    /* +0x0B8 */ uint64_t field_B8;     /* rw; init via FUN_14047f1e0(param_1+0x17,uVar1) */
    /* +0x0C0 */ uint8_t gap_C0[0x10];  /* +0xC0..+0xCF: not observed */
    /* +0x0D0 */ uint8_t field_D0[0x38];/* r via FUN_14014d0a8(param_1+0x1a,puVar2); opaque */
    /* +0x108 */ uint64_t field_108;    /* w in ctor; = param_3 */
    /* +0x110 */ uint64_t field_110;    /* w in ctor; = 0 */
    /* +0x118 */ uint64_t field_118;    /* w in ctor; = 0 */
    /* +0x120 */ uint64_t field_120;    /* w in ctor; = 0 */
    /* +0x128 */ uint64_t field_128;    /* rw; init via FUN_14047f1e0(param_1+0x25,uVar1) */
    /* +0x130 */ uint8_t gap_130[0x10]; /* +0x130..+0x13F: not observed */
    /* +0x140 */ uint32_t field_140;    /* w in ctor; = 0 */
    /* +0x144 */ uint8_t pad_144[4];    /* padding to 0x148 */
} ccUiLayout;

static_assert(sizeof(ccUiLayout) == 0x148, "ccUiLayout size must be 0x148");
static_assert(offsetof(ccUiLayout, vtable) == 0x000, "ccUiLayout.vtable");
static_assert(offsetof(ccUiLayout, base) == 0x008, "ccUiLayout.base");
static_assert(offsetof(ccUiLayout, field_48) == 0x048, "ccUiLayout.field_48");
static_assert(offsetof(ccUiLayout, pad_4C) == 0x04C, "ccUiLayout.pad_4C");
static_assert(offsetof(ccUiLayout, gap_50) == 0x050, "ccUiLayout.gap_50");
static_assert(offsetof(ccUiLayout, field_78) == 0x078, "ccUiLayout.field_78");
static_assert(offsetof(ccUiLayout, field_A0) == 0x0A0, "ccUiLayout.field_A0");
static_assert(offsetof(ccUiLayout, field_A8) == 0x0A8, "ccUiLayout.field_A8");
static_assert(offsetof(ccUiLayout, field_B0) == 0x0B0, "ccUiLayout.field_B0");
static_assert(offsetof(ccUiLayout, field_B8) == 0x0B8, "ccUiLayout.field_B8");
static_assert(offsetof(ccUiLayout, gap_C0) == 0x0C0, "ccUiLayout.gap_C0");
static_assert(offsetof(ccUiLayout, field_D0) == 0x0D0, "ccUiLayout.field_D0");
static_assert(offsetof(ccUiLayout, field_108)== 0x108, "ccUiLayout.field_108");
static_assert(offsetof(ccUiLayout, field_110)== 0x110, "ccUiLayout.field_110");
static_assert(offsetof(ccUiLayout, field_118)== 0x118, "ccUiLayout.field_118");
static_assert(offsetof(ccUiLayout, field_120)== 0x120, "ccUiLayout.field_120");
static_assert(offsetof(ccUiLayout, field_128)== 0x128, "ccUiLayout.field_128");
static_assert(offsetof(ccUiLayout, gap_130) == 0x130, "ccUiLayout.gap_130");
static_assert(offsetof(ccUiLayout, field_140)== 0x140, "ccUiLayout.field_140");
static_assert(offsetof(ccUiLayout, pad_144) == 0x144, "ccUiLayout.pad_144");

#endif /* CMN13_S1_H */