/*
 * cmn21.h - Common struct group cmn21 for NARUTO STORM 2 PC (NSUNS2.exe, build s2)
 *
 * All layouts are INFERRED from static analysis (decompiled code, state_surface).
 * No runtime confirmation. Sizes proven from ctor/allocator where possible;
 * otherwise marked "size unknown, >= 0xN".
 *
 * Own-game names only: Storm 2 (s2) symbols/strings/code.
 * PC offsets only: derived from x64 decompile (image base 0x140000000).
 */

#ifndef CMN21_S2_H
#define CMN21_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose full layout is not in cmn21 */
typedef struct Nucc_Vector3 {
    float x;
    float y;
    float z;
} Nucc_Vector3;

/* ========================================================================
 * GameActor::Base
 * Vtable at offset 0x0 set to PTR_FUN_1408918e8 in ctor (inferred from Component ctor pattern).
 * state_surface returned 55 fields. Largest offset 0x6FA8 + 8 = size >= 0x6FB0.
 * Vtable ptrs seen: 0x8F0 (PTR_FUN_1408918e8), 0x27B0 (PTR_FUN_14089c1b8).
 * ======================================================================== */
typedef struct __attribute__((packed)) GameActor_Base {
    /* 0x0000 */ void *vtable;                /* set in ctor; PTR_FUN_1408918e8 */
    /* 0x0008 */ uint8_t _base_subobj[0x50];  /* inherited subobject (ccTaskBase or similar) */
    /* 0x0058 */ uint64_t field_58;           /* low conf, size unknown */
    /* 0x0060 */ uint8_t _gap_60[0x10];       /* padding */
    /* 0x0070 */ uint64_t field_70;           /* low conf */
    /* 0x0078 */ uint32_t field_78;           /* medium conf */
    /* 0x007C */ uint32_t field_7C;           /* low conf, size [4,8] but next at 0x80 => 4 */
    /* 0x0080 */ uint32_t field_80;           /* low conf */
    /* 0x0084 */ uint32_t field_84;           /* high conf */
    /* 0x0088 */ uint64_t field_88;           /* high conf */
    /* 0x0090 */ uint8_t _gap_90[0x130];      /* large gap to 0x1C0 */
    /* 0x01C0 */ uint64_t field_1C0;          /* low conf */
    /* 0x01C8 */ uint8_t _gap_1C8[0x50];      /* gap to 0x218 */
    /* 0x0218 */ uint64_t field_218;          /* medium conf */
    /* 0x0220 */ uint8_t _gap_220[0x6D0];     /* gap to 0x8F0 */
    /* 0x08F0 */ void *vtable_secondary;      /* PTR_FUN_1408918e8 (secondary vtable slot) */
    /* 0x08F8 */ uint64_t field_8F8;          /* medium conf */
    /* 0x0900 */ uint64_t field_900;          /* medium conf */
    /* 0x0908 */ uint32_t field_908;          /* medium conf */
    /* 0x090C */ uint8_t _gap_90C[0xC];       /* padding to 0x918 */
    /* 0x0918 */ uint64_t field_918;          /* low conf */
    /* 0x0920 */ uint8_t _gap_920[0x1CA0];    /* gap to 0x25C0 */
    /* 0x25C0 */ uint64_t field_25C0;         /* medium conf */
    /* 0x25C8 */ uint8_t _gap_25C8[0x8];      /* padding */
    /* 0x25D0 */ uint64_t field_25D0;         /* medium conf */
    /* 0x25D8 */ uint8_t _gap_25D8[0x8];      /* padding */
    /* 0x25E0 */ uint64_t field_25E0;         /* medium conf */
    /* 0x25E8 */ uint8_t _gap_25E8[0x1B0];    /* gap to 0x2798 */
    /* 0x2798 */ uint64_t field_2798;         /* low conf */
    /* 0x27A0 */ uint8_t _gap_27A0[0x10];     /* padding */
    /* 0x27B0 */ void *vtable_tertiary;       /* PTR_FUN_14089c1b8 */
    /* 0x27B8 */ uint8_t _gap_27B8[0x10];     /* padding */
    /* 0x27C8 */ uint64_t field_27C8;         /* low conf */
    /* 0x27D0 */ uint8_t _gap_27D0[0x8];      /* padding */
    /* 0x27D8 */ uint64_t field_27D8;         /* low conf */
    /* 0x27E0 */ uint8_t _gap_27E0[0x3610];   /* gap to 0x5DF0 */
    /* 0x5DF0 */ uint64_t field_5DF0;         /* low conf */
    /* 0x5DF8 */ uint64_t field_5DF8;         /* low conf */
    /* 0x5E00 */ uint8_t _gap_5E00[0x38];     /* gap to 0x5E38 */
    /* 0x5E38 */ uint8_t field_5E38;          /* medium conf, size 1 */
    /* 0x5E39 */ uint8_t _gap_5E39[0xF];      /* padding */
    /* 0x5E48 */ uint64_t field_5E48;         /* medium conf */
    /* 0x5E50 */ uint64_t field_5E50;         /* medium conf */
    /* 0x5E58 */ uint64_t field_5E58;         /* low conf */
    /* 0x5E60 */ uint8_t _gap_5E60[0x10];     /* padding */
    /* 0x5E70 */ uint64_t field_5E70;         /* low conf */
    /* 0x5E78 */ uint8_t _gap_5E78[0x50];     /* gap to 0x5EC8 */
    /* 0x5EC8 */ uint64_t field_5EC8;         /* low conf */
    /* 0x5ED0 */ uint8_t _gap_5ED0[0x8];      /* padding */
    /* 0x5ED8 */ uint64_t field_5ED8;         /* low conf */
    /* 0x5EE0 */ uint8_t _gap_5EE0[0x10];     /* padding */
    /* 0x5EF0 */ uint64_t field_5EF0;         /* low conf */
    /* 0x5EF8 */ uint8_t _gap_5EF8[0x58];     /* gap to 0x5F50 */
    /* 0x5F50 */ uint64_t field_5F50;         /* low conf */
    /* 0x5F58 */ uint8_t _gap_5F58[0x8];      /* padding */
    /* 0x5F60 */ uint64_t field_5F60;         /* low conf */
    /* 0x5F68 */ uint8_t _gap_5F68[0x10];     /* padding */
    /* 0x5F78 */ uint64_t field_5F78;         /* low conf */
    /* 0x5F80 */ uint8_t _gap_5F80[0x58];     /* gap to 0x5FD8 */
    /* 0x5FD8 */ uint64_t field_5FD8;         /* low conf */
    /* 0x5FE0 */ uint8_t _gap_5FE0[0x8];      /* padding */
    /* 0x5FE8 */ uint64_t field_5FE8;         /* low conf */
    /* 0x5FF0 */ uint8_t _gap_5FF0[0x10];     /* padding */
    /* 0x6000 */ uint64_t field_6000;         /* medium conf */
    /* 0x6008 */ uint64_t field_6008;         /* medium conf */
    /* 0x6010 */ uint64_t field_6010;         /* medium conf */
    /* 0x6018 */ uint64_t field_6018;         /* medium conf */
    /* 0x6020 */ uint8_t _gap_6020[0xC0];     /* gap to 0x60E0 */
    /* 0x60E0 */ uint8_t field_60E0;          /* medium conf, size 1 */
    /* 0x60E1 */ uint8_t _gap_60E1[0xF];      /* padding */
    /* 0x60F0 */ uint64_t field_60F0;         /* medium conf */
    /* 0x60F8 */ uint64_t field_60F8;         /* medium conf */
    /* 0x6100 */ uint64_t field_6100;         /* low conf */
    /* 0x6108 */ uint8_t _gap_6108[0x1B0];    /* gap to 0x62B8 */
    /* 0x62B8 */ uint64_t field_62B8;         /* low conf */
    /* 0x62C0 */ uint8_t _gap_62C0[0x5B0];    /* gap to 0x6870 */
    /* 0x6870 */ uint64_t field_6870;         /* low conf */
    /* 0x6878 */ uint8_t _gap_6878[0x6B8];    /* gap to 0x6F30 */
    /* 0x6F30 */ uint32_t field_6F30;         /* medium conf */
    /* 0x6F34 */ uint8_t _gap_6F34[0x4];      /* padding */
    /* 0x6F38 */ uint64_t field_6F38;         /* low conf */
    /* 0x6F40 */ uint8_t _gap_6F40[0x10];     /* padding */
    /* 0x6F50 */ uint64_t field_6F50;         /* medium conf */
    /* 0x6F58 */ uint64_t field_6F58;         /* medium conf */
    /* 0x6F60 */ uint64_t field_6F60;         /* medium conf */
    /* 0x6F68 */ uint8_t _gap_6F68[0x20];     /* gap to 0x6F88 */
    /* 0x6F88 */ uint8_t field_6F88;          /* medium conf, size 1 */
    /* 0x6F89 */ uint8_t _gap_6F89[0xF];      /* padding */
    /* 0x6F98 */ uint64_t field_6F98;         /* medium conf */
    /* 0x6FA0 */ uint64_t field_6FA0;         /* medium conf */
    /* 0x6FA8 */ uint64_t field_6FA8;         /* low conf */
} GameActor_Base;
/* Size: unknown, >= 0x6FB0 (last field at 0x6FA8 + 8) */

static_assert(offsetof(GameActor_Base, vtable) == 0x0000, "GameActor_Base.vtable");
static_assert(offsetof(GameActor_Base, field_58) == 0x0058, "GameActor_Base.field_58");
static_assert(offsetof(GameActor_Base, field_70) == 0x0070, "GameActor_Base.field_70");
static_assert(offsetof(GameActor_Base, field_78) == 0x0078, "GameActor_Base.field_78");
static_assert(offsetof(GameActor_Base, field_7C) == 0x007C, "GameActor_Base.field_7C");
static_assert(offsetof(GameActor_Base, field_80) == 0x0080, "GameActor_Base.field_80");
static_assert(offsetof(GameActor_Base, field_84) == 0x0084, "GameActor_Base.field_84");
static_assert(offsetof(GameActor_Base, field_88) == 0x0088, "GameActor_Base.field_88");
static_assert(offsetof(GameActor_Base, field_1C0) == 0x01C0, "GameActor_Base.field_1C0");
static_assert(offsetof(GameActor_Base, field_218) == 0x0218, "GameActor_Base.field_218");
static_assert(offsetof(GameActor_Base, vtable_secondary) == 0x08F0, "GameActor_Base.vtable_secondary");
static_assert(offsetof(GameActor_Base, field_8F8) == 0x08F8, "GameActor_Base.field_8F8");
static_assert(offsetof(GameActor_Base, field_900) == 0x0900, "GameActor_Base.field_900");
static_assert(offsetof(GameActor_Base, field_908) == 0x0908, "GameActor_Base.field_908");
static_assert(offsetof(GameActor_Base, field_918) == 0x0918, "GameActor_Base.field_918");
static_assert(offsetof(GameActor_Base, field_25C0) == 0x25C0, "GameActor_Base.field_25C0");
static_assert(offsetof(GameActor_Base, field_25D0) == 0x25D0, "GameActor_Base.field_25D0");
static_assert(offsetof(GameActor_Base, field_25E0) == 0x25E0, "GameActor_Base.field_25E0");
static_assert(offsetof(GameActor_Base, field_2798) == 0x2798, "GameActor_Base.field_2798");
static_assert(offsetof(GameActor_Base, vtable_tertiary) == 0x27B0, "GameActor_Base.vtable_tertiary");
static_assert(offsetof(GameActor_Base, field_27C8) == 0x27C8, "GameActor_Base.field_27C8");
static_assert(offsetof(GameActor_Base, field_27D8) == 0x27D8, "GameActor_Base.field_27D8");
static_assert(offsetof(GameActor_Base, field_5DF0) == 0x5DF0, "GameActor_Base.field_5DF0");
static_assert(offsetof(GameActor_Base, field_5DF8) == 0x5DF8, "GameActor_Base.field_5DF8");
static_assert(offsetof(GameActor_Base, field_5E38) == 0x5E38, "GameActor_Base.field_5E38");
static_assert(offsetof(GameActor_Base, field_5E48) == 0x5E48, "GameActor_Base.field_5E48");
static_assert(offsetof(GameActor_Base, field_5E50) == 0x5E50, "GameActor_Base.field_5E50");
static_assert(offsetof(GameActor_Base, field_5E58) == 0x5E58, "GameActor_Base.field_5E58");
static_assert(offsetof(GameActor_Base, field_5E70) == 0x5E70, "GameActor_Base.field_5E70");
static_assert(offsetof(GameActor_Base, field_5EC8) == 0x5EC8, "GameActor_Base.field_5EC8");
static_assert(offsetof(GameActor_Base, field_5ED8) == 0x5ED8, "GameActor_Base.field_5ED8");
static_assert(offsetof(GameActor_Base, field_5EF0) == 0x5EF0, "GameActor_Base.field_5EF0");
static_assert(offsetof(GameActor_Base, field_5F50) == 0x5F50, "GameActor_Base.field_5F50");
static_assert(offsetof(GameActor_Base, field_5F60) == 0x5F60, "GameActor_Base.field_5F60");
static_assert(offsetof(GameActor_Base, field_5F78) == 0x5F78, "GameActor_Base.field_5F78");
static_assert(offsetof(GameActor_Base, field_5FD8) == 0x5FD8, "GameActor_Base.field_5FD8");
static_assert(offsetof(GameActor_Base, field_5FE8) == 0x5FE8, "GameActor_Base.field_5FE8");
static_assert(offsetof(GameActor_Base, field_6000) == 0x6000, "GameActor_Base.field_6000");
static_assert(offsetof(GameActor_Base, field_6008) == 0x6008, "GameActor_Base.field_6008");
static_assert(offsetof(GameActor_Base, field_6010) == 0x6010, "GameActor_Base.field_6010");
static_assert(offsetof(GameActor_Base, field_6018) == 0x6018, "GameActor_Base.field_6018");
static_assert(offsetof(GameActor_Base, field_60E0) == 0x60E0, "GameActor_Base.field_60E0");
static_assert(offsetof(GameActor_Base, field_60F0) == 0x60F0, "GameActor_Base.field_60F0");
static_assert(offsetof(GameActor_Base, field_60F8) == 0x60F8, "GameActor_Base.field_60F8");
static_assert(offsetof(GameActor_Base, field_6100) == 0x6100, "GameActor_Base.field_6100");
static_assert(offsetof(GameActor_Base, field_62B8) == 0x62B8, "GameActor_Base.field_62B8");
static_assert(offsetof(GameActor_Base, field_6870) == 0x6870, "GameActor_Base.field_6870");
static_assert(offsetof(GameActor_Base, field_6F30) == 0x6F30, "GameActor_Base.field_6F30");
static_assert(offsetof(GameActor_Base, field_6F38) == 0x6F38, "GameActor_Base.field_6F38");
static_assert(offsetof(GameActor_Base, field_6F50) == 0x6F50, "GameActor_Base.field_6F50");
static_assert(offsetof(GameActor_Base, field_6F58) == 0x6F58, "GameActor_Base.field_6F58");
static_assert(offsetof(GameActor_Base, field_6F60) == 0x6F60, "GameActor_Base.field_6F60");
static_assert(offsetof(GameActor_Base, field_6F88) == 0x6F88, "GameActor_Base.field_6F88");
static_assert(offsetof(GameActor_Base, field_6F98) == 0x6F98, "GameActor_Base.field_6F98");
static_assert(offsetof(GameActor_Base, field_6FA0) == 0x6FA0, "GameActor_Base.field_6FA0");
static_assert(offsetof(GameActor_Base, field_6FA8) == 0x6FA8, "GameActor_Base.field_6FA8");

/* ========================================================================
 * GameActor::Component
 * Vtable at 0x0 set to PTR_FUN_1408918e8 initially, then PTR_FUN_14089e3e8 finally.
 * Contains BlockAllocator subobject. Owner handle at param_1[4] = offset 0x20.
 * Layout from ctor/dtor symbolized decompile (state_surface returned 0 fields).
 * Size: unknown, >= 0x28.
 * ======================================================================== */
typedef struct __attribute__((packed)) GameActor_Component {
    /* 0x00 */ void *vtable;              /* final: &PTR_FUN_14089e3e8 */
    /* 0x08 */ void *field_08;            /* PTR_LAB_14089e3f0 in dtor */
    /* 0x10 */ uint8_t _blockAlloc[0x10]; /* BlockAllocator subobject */
    /* 0x20 */ void *owner;               /* param_1[4] = param_2 (owner handle) */
} GameActor_Component;
/* Size: unknown, >= 0x28 */

static_assert(offsetof(GameActor_Component, vtable) == 0x00, "GameActor_Component.vtable");
static_assert(offsetof(GameActor_Component, field_08) == 0x08, "GameActor_Component.field_08");
static_assert(offsetof(GameActor_Component, owner) == 0x20, "GameActor_Component.owner");

/* ========================================================================
 * GameObject::Manager
 * Singleton at DAT_140ab4680. Vtable PTR_FUN_14089dde8.
 * List iteration at param_1+0x18 in Exist/GetBase. Container at 0x68, flag at 0x70.
 * Layout from Inst/Exist/GetBase/Remove symbolized decompiles (state_surface returned 0).
 * Size: unknown, >= 0x74.
 * ======================================================================== */
typedef struct __attribute__((packed)) GameObject_Manager {
    /* 0x00 */ void *vtable;              /* &PTR_FUN_14089dde8 */
    /* 0x08 */ uint8_t _subobj[0x10];     /* initialized subobject */
    /* 0x18 */ uint64_t list_head;        /* list iteration target in Exist/GetBase */
    /* 0x20 */ uint8_t _inner[0x48];      /* inner data up to container */
    /* 0x68 */ uint64_t container;        /* passed to destroy in Remove */
    /* 0x70 */ uint32_t flag;             /* written =1 in Remove */
} GameObject_Manager;
/* Size: unknown, >= 0x74 */

static_assert(offsetof(GameObject_Manager, vtable) == 0x00, "GameObject_Manager.vtable");
static_assert(offsetof(GameObject_Manager, list_head) == 0x18, "GameObject_Manager.list_head");
static_assert(offsetof(GameObject_Manager, container) == 0x68, "GameObject_Manager.container");
static_assert(offsetof(GameObject_Manager, flag) == 0x70, "GameObject_Manager.flag");

/* ========================================================================
 * gjkepa2_impl::EPA
 * Expanding Polytope Algorithm solver. 13 fields surfaced from state_surface.
 * Fields at 0x2C..0x50 are scalars; fields at 0x3860..0x3880 are counters/indices.
 * Size: unknown, >= 0x3884 (last field at 0x3880 + 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_EPA {
    /* 0x0000 */ uint8_t _header[0x2C];     /* header/init area */
    /* 0x002C */ float field_2C;            /* high conf */
    /* 0x0030 */ float field_30;            /* medium conf */
    /* 0x0034 */ uint8_t _gap_34[4];        /* padding */
    /* 0x0038 */ int32_t field_38;          /* high conf */
    /* 0x003C */ uint8_t _gap_3C[4];        /* padding */
    /* 0x0040 */ float field_40;            /* low conf, size [4,8] but next at 0x44 => 4 */
    /* 0x0044 */ float field_44;            /* high conf */
    /* 0x0048 */ float field_48;            /* low conf, size [4,8] but next at 0x4C => 4 */
    /* 0x004C */ float field_4C;            /* high conf */
    /* 0x0050 */ float field_50;            /* high conf */
    /* 0x0054 */ uint8_t _body[0x380C];     /* large internal array storage */
    /* 0x3860 */ int32_t field_3860;        /* high conf, counter/index */
    /* 0x3864 */ uint8_t _gap_3864[4];      /* padding */
    /* 0x3868 */ int64_t field_3868;        /* high conf */
    /* 0x3870 */ int32_t field_3870;        /* high conf */
    /* 0x3874 */ uint8_t _gap_3874[4];      /* padding */
    /* 0x3878 */ int64_t field_3878;        /* high conf */
    /* 0x3880 */ int32_t field_3880;        /* high conf */
} gjkepa2_impl_EPA;
/* Size: unknown, >= 0x3884 */

static_assert(offsetof(gjkepa2_impl_EPA, field_2C) == 0x002C, "gjkepa2_impl_EPA.field_2C");
static_assert(offsetof(gjkepa2_impl_EPA, field_30) == 0x0030, "gjkepa2_impl_EPA.field_30");
static_assert(offsetof(gjkepa2_impl_EPA, field_38) == 0x0038, "gjkepa2_impl_EPA.field_38");
static_assert(offsetof(gjkepa2_impl_EPA, field_40) == 0x0040, "gjkepa2_impl_EPA.field_40");
static_assert(offsetof(gjkepa2_impl_EPA, field_44) == 0x0044, "gjkepa2_impl_EPA.field_44");
static_assert(offsetof(gjkepa2_impl_EPA, field_48) == 0x0048, "gjkepa2_impl_EPA.field_48");
static_assert(offsetof(gjkepa2_impl_EPA, field_4C) == 0x004C, "gjkepa2_impl_EPA.field_4C");
static_assert(offsetof(gjkepa2_impl_EPA, field_50) == 0x0050, "gjkepa2_impl_EPA.field_50");
static_assert(offsetof(gjkepa2_impl_EPA, field_3860) == 0x3860, "gjkepa2_impl_EPA.field_3860");
static_assert(offsetof(gjkepa2_impl_EPA, field_3868) == 0x3868, "gjkepa2_impl_EPA.field_3868");
static_assert(offsetof(gjkepa2_impl_EPA, field_3870) == 0x3870, "gjkepa2_impl_EPA.field_3870");
static_assert(offsetof(gjkepa2_impl_EPA, field_3878) == 0x3878, "gjkepa2_impl_EPA.field_3878");
static_assert(offsetof(gjkepa2_impl_EPA, field_3880) == 0x3880, "gjkepa2_impl_EPA.field_3880");

/* ========================================================================
 * gjkepa2_impl::GJK
 * Gilbert-Johnson-Keerthi distance algorithm. 25 fields surfaced.
 * Internal simplex/support point storage. Arrays at 0x120/0x140/0x160/0x180.
 * Size: unknown, >= 0x1D4 (last field at 0x1D0 + 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_GJK {
    /* 0x000 */ uint8_t _header[0x58];     /* header before first surfaced field */
    /* 0x058 */ uint64_t field_58;         /* medium conf */
    /* 0x060 */ uint64_t field_60;         /* medium conf */
    /* 0x068 */ uint64_t field_68;         /* medium conf */
    /* 0x070 */ uint64_t field_70;         /* medium conf */
    /* 0x078 */ uint64_t field_78;         /* medium conf */
    /* 0x080 */ uint64_t field_80;         /* medium conf */
    /* 0x088 */ uint8_t _gap_88[8];        /* padding */
    /* 0x090 */ uint32_t field_90;         /* low conf, size [4,8] but next at 0x94 => 4 */
    /* 0x094 */ uint32_t field_94;         /* high conf */
    /* 0x098 */ uint64_t field_98;         /* low conf, size [4,8], next at 0xA0 => 8 */
    /* 0x0A0 */ uint32_t field_A0;         /* high conf */
    /* 0x0A4 */ uint8_t _gap_A4[4];        /* padding */
    /* 0x0A8 */ uint64_t field_A8;         /* medium conf */
    /* 0x0B0 */ uint8_t _gap_B0[0x18];     /* gap */
    /* 0x0C8 */ uint32_t field_C8;         /* medium conf */
    /* 0x0CC */ uint8_t _gap_CC[0xC];      /* gap */
    /* 0x0D8 */ uint32_t field_D8;         /* high conf */
    /* 0x0DC */ uint8_t _gap_DC[0x44];     /* gap */
    /* 0x120 */ uint8_t _array_120[0x20];  /* internal array ref */
    /* 0x140 */ uint8_t _array_140[0x20];  /* internal array ref */
    /* 0x160 */ uint8_t _array_160[0x20];  /* internal array ref */
    /* 0x180 */ uint8_t _array_180[0x20];  /* internal array ref */
    /* 0x1A0 */ uint64_t ptr_1A0;          /* medium conf */
    /* 0x1A8 */ uint64_t ptr_1A8;          /* medium conf */
    /* 0x1B0 */ uint64_t ptr_1B0;          /* medium conf */
    /* 0x1B8 */ uint64_t ptr_1B8;          /* medium conf */
    /* 0x1C0 */ uint32_t field_1C0;        /* low conf, size [4,8] but next at 0x1C4 => 4 */
    /* 0x1C4 */ uint32_t field_1C4;        /* medium conf */
    /* 0x1C8 */ uint64_t field_1C8;        /* medium conf */
    /* 0x1D0 */ uint32_t field_1D0;        /* high conf */
} gjkepa2_impl_GJK;
/* Size: unknown, >= 0x1D4 */

static_assert(offsetof(gjkepa2_impl_GJK, field_58) == 0x058, "gjkepa2_impl_GJK.field_58");
static_assert(offsetof(gjkepa2_impl_GJK, field_60) == 0x060, "gjkepa2_impl_GJK.field_60");
static_assert(offsetof(gjkepa2_impl_GJK, field_68) == 0x068, "gjkepa2_impl_GJK.field_68");
static_assert(offsetof(gjkepa2_impl_GJK, field_70) == 0x070, "gjkepa2_impl_GJK.field_70");
static_assert(offsetof(gjkepa2_impl_GJK, field_78) == 0x078, "gjkepa2_impl_GJK.field_78");
static_assert(offsetof(gjkepa2_impl_GJK, field_80) == 0x080, "gjkepa2_impl_GJK.field_80");
static_assert(offsetof(gjkepa2_impl_GJK, field_90) == 0x090, "gjkepa2_impl_GJK.field_90");
static_assert(offsetof(gjkepa2_impl_GJK, field_94) == 0x094, "gjkepa2_impl_GJK.field_94");
static_assert(offsetof(gjkepa2_impl_GJK, field_98) == 0x098, "gjkepa2_impl_GJK.field_98");
static_assert(offsetof(gjkepa2_impl_GJK, field_A0) == 0x0A0, "gjkepa2_impl_GJK.field_A0");
static_assert(offsetof(gjkepa2_impl_GJK, field_A8) == 0x0A8, "gjkepa2_impl_GJK.field_A8");
static_assert(offsetof(gjkepa2_impl_GJK, field_C8) == 0x0C8, "gjkepa2_impl_GJK.field_C8");
static_assert(offsetof(gjkepa2_impl_GJK, field_D8) == 0x0D8, "gjkepa2_impl_GJK.field_D8");
static_assert(offsetof(gjkepa2_impl_GJK, _array_120) == 0x120, "gjkepa2_impl_GJK._array_120");
static_assert(offsetof(gjkepa2_impl_GJK, _array_140) == 0x140, "gjkepa2_impl_GJK._array_140");
static_assert(offsetof(gjkepa2_impl_GJK, _array_160) == 0x160, "gjkepa2_impl_GJK._array_160");
static_assert(offsetof(gjkepa2_impl_GJK, _array_180) == 0x180, "gjkepa2_impl_GJK._array_180");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1A0) == 0x1A0, "gjkepa2_impl_GJK.ptr_1A0");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1A8) == 0x1A8, "gjkepa2_impl_GJK.ptr_1A8");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1B0) == 0x1B0, "gjkepa2_impl_GJK.ptr_1B0");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1B8) == 0x1B8, "gjkepa2_impl_GJK.ptr_1B8");
static_assert(offsetof(gjkepa2_impl_GJK, field_1C0) == 0x1C0, "gjkepa2_impl_GJK.field_1C0");
static_assert(offsetof(gjkepa2_impl_GJK, field_1C4) == 0x1C4, "gjkepa2_impl_GJK.field_1C4");
static_assert(offsetof(gjkepa2_impl_GJK, field_1C8) == 0x1C8, "gjkepa2_impl_GJK.field_1C8");
static_assert(offsetof(gjkepa2_impl_GJK, field_1D0) == 0x1D0, "gjkepa2_impl_GJK.field_1D0");

/* ========================================================================
 * gjkepa2_impl::MinkowskiDiff
 * Minkowski difference support structure. 6 fields surfaced.
 * Shape data at 0x2C..0x3C (5 floats), support dispatch function pointer at 0x80.
 * Size: unknown, >= 0x88 (last field at 0x80 + 8).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_MinkowskiDiff {
    /* 0x00 */ uint8_t _shapeData[0x2C];  /* shape/matrix data */
    /* 0x2C */ float field_2C;            /* medium conf */
    /* 0x30 */ float field_30;            /* medium conf */
    /* 0x34 */ float field_34;            /* medium conf */
    /* 0x38 */ float field_38;            /* medium conf */
    /* 0x3C */ float field_3C;            /* medium conf */
    /* 0x40 */ uint8_t _gap_40[0x40];     /* gap to support dispatch */
    /* 0x80 */ void *supportDispatch;     /* medium conf, function pointer */
} gjkepa2_impl_MinkowskiDiff;
/* Size: unknown, >= 0x88 */

static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_2C) == 0x2C, "gjkepa2_impl_MinkowskiDiff.field_2C");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_30) == 0x30, "gjkepa2_impl_MinkowskiDiff.field_30");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_34) == 0x34, "gjkepa2_impl_MinkowskiDiff.field_34");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_38) == 0x38, "gjkepa2_impl_MinkowskiDiff.field_38");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_3C) == 0x3C, "gjkepa2_impl_MinkowskiDiff.field_3C");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, supportDispatch) == 0x80, "gjkepa2_impl_MinkowskiDiff.supportDispatch");

#endif /* CMN21_S2_H */