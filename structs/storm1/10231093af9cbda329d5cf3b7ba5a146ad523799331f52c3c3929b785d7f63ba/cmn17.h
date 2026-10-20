/* cmn17.h — NARUTO STORM 1 PC (s1/NSUNS1.exe) struct reconstruction
 * Group: ccUiSprite, ccUiStaffRoll, ccUiTaskBase, ccUiTaskBaseList, ccUiUtilSound
 * All results are INFERRED from static analysis (Ghidra decompile + state_surface).
 * Own-game names only (ns1:: namespace via Switch Trilogy mapping).
 * PC offsets re-derived from x64 decompile; never copied from arm64.
 */
#ifndef CMN17_H
#define CMN17_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here */
typedef struct { float x, y, z; } ns1_Vector3;   /* 12 bytes */
typedef struct { float x, y; }     ns1_Vector2;   /* 8 bytes */
typedef struct { float m[16]; }    ns1_Matrix44;  /* 64 bytes */
typedef struct { float r, g, b, a; } ns1_Color;   /* 16 bytes */

/* ========================================================================
 * ccUiObject (base class) — size >= 0xC0 from ctor field accesses
 * Vtable: PTR_FUN_140745bf8 (0x140745BF8)
 * Not reconstructed standalone; included as base of ccUiSprite.
 * ======================================================================== */

/* ========================================================================
 * ccUiSprite — size = 400 (0x190)
 * Proven by: ccFileLoadListForUi::LoadTh(400, ...) in s1
 * Vtable: PTR_FUN_140745ca0 (0x140745CA0)
 * Methods cached: 15 seeds, all ok
 * Fields: 17 total (8 writable, 9 read-only)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* 0x000 - ccUiObject base (vptr at +0x00) */
    uint64_t vptr;                    /* 0x000 */
    uint8_t  _base_pad[0xC0 - 8];     /* 0x008..0x0BF ccUiObject body */

    /* Writable scalar fields from state_surface */
    uint32_t field_C0;                /* 0x0C0 write u32, ctor init=0 */
    uint8_t  _pad_C4[4];              /* 0x0C4 gap to 0x0C8 */
    uint64_t field_C8;                /* 0x0C8 write u64, ctor init=0 */
    uint32_t field_D0;                /* 0x0D0 write u32, ctor init=0 */

    /* Embedded sub-objects initialized in ctor (read-only access pattern) */
    ns1_Vector3 pos;                  /* 0x0D4 Vector3 ctor */
    ns1_Vector3 field_E0;             /* 0x0E0 Vector3 ctor */
    ns1_Vector2 scale_default;        /* 0x0EC Vector2(1.0,1.0) */
    ns1_Vector2 size;                 /* 0x0F4 Vector2(100.0,100.0) */
    ns1_Vector3 field_FC;             /* 0x0FC Vector3 from DAT_1407368d8 */
    ns1_Vector2 uv_offset;            /* 0x108 Vector2(0,0) */
    ns1_Vector2 field_110;            /* 0x110 Vector2 copy of size */
    ns1_Matrix44 transform;           /* 0x118 Matrix44 ctor */

    uint32_t field_158;               /* 0x158 write u32, ctor init=0 */
    uint8_t  _pad_15C[4];             /* 0x15C gap to 0x160 */
    ns1_Color color;                  /* 0x160 nuccCOLOR(1,1,1,1) */
    uint64_t field_170;               /* 0x170 write u64, ctor=0x10000001 */
    uint32_t field_178;               /* 0x178 write u32, ctor init=3 */
    uint32_t field_17C;               /* 0x17C write u32, ctor=0x20061 */
    uint64_t field_180;               /* 0x180 write u64, ctor init=0 */
    uint8_t  _tail_pad[0x190 - 0x188];/* 0x188..0x18F pad to size 400 */
} ns1_ccUiSprite;

static_assert(sizeof(ns1_ccUiSprite) == 400, "ns1_ccUiSprite size must be 400");
static_assert(offsetof(ns1_ccUiSprite, vptr)          == 0x000, "vptr offset");
static_assert(offsetof(ns1_ccUiSprite, field_C0)      == 0x0C0, "field_C0 offset");
static_assert(offsetof(ns1_ccUiSprite, field_C8)      == 0x0C8, "field_C8 offset");
static_assert(offsetof(ns1_ccUiSprite, field_D0)      == 0x0D0, "field_D0 offset");
static_assert(offsetof(ns1_ccUiSprite, pos)           == 0x0D4, "pos offset");
static_assert(offsetof(ns1_ccUiSprite, field_E0)      == 0x0E0, "field_E0 offset");
static_assert(offsetof(ns1_ccUiSprite, scale_default) == 0x0EC, "scale_default offset");
static_assert(offsetof(ns1_ccUiSprite, size)          == 0x0F4, "size offset");
static_assert(offsetof(ns1_ccUiSprite, field_FC)      == 0x0FC, "field_FC offset");
static_assert(offsetof(ns1_ccUiSprite, uv_offset)     == 0x108, "uv_offset offset");
static_assert(offsetof(ns1_ccUiSprite, field_110)     == 0x110, "field_110 offset");
static_assert(offsetof(ns1_ccUiSprite, transform)     == 0x118, "transform offset");
static_assert(offsetof(ns1_ccUiSprite, field_158)     == 0x158, "field_158 offset");
static_assert(offsetof(ns1_ccUiSprite, color)         == 0x160, "color offset");
static_assert(offsetof(ns1_ccUiSprite, field_170)     == 0x170, "field_170 offset");
static_assert(offsetof(ns1_ccUiSprite, field_178)     == 0x178, "field_178 offset");
static_assert(offsetof(ns1_ccUiSprite, field_17C)     == 0x17C, "field_17C offset");
static_assert(offsetof(ns1_ccUiSprite, field_180)     == 0x180, "field_180 offset");

/* ========================================================================
 * ccUiTaskBase — size >= 0x38 (lower bound from ctor field at +0x34)
 * LoadTh(0x30,...) may allocate base only; ctor writes at +0x34 require 0x38.
 * Vtable: PTR_FUN_140745738 (0x140745738)
 * Methods cached: 4 seeds, all ok
 * Fields: 5 total (2 writable scalars, 2 task ptrs, 1 vfunc read)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vptr;                    /* 0x000 */
    uint8_t  _pad_008[0x18 - 8];      /* 0x008..0x017 */
    uint64_t task_ptr_1;              /* 0x018 from ctor (+0x18) */
    uint64_t task_ptr_2;              /* 0x020 from ctor (+0x20) */
    uint8_t  _pad_028[4];             /* 0x028 gap */
    uint32_t field_2C;                /* 0x02C write u32, param_7 */
    uint32_t field_30;                /* 0x030 gap/filler */
    uint32_t field_34;                /* 0x034 write u32, param_4 */
    uint8_t  _tail_pad[0x38 - 0x38];  /* pad to 0x38 minimum */
} ns1_ccUiTaskBase;

static_assert(sizeof(ns1_ccUiTaskBase) == 0x38, "ns1_ccUiTaskBase size must be 0x38");
static_assert(offsetof(ns1_ccUiTaskBase, vptr)       == 0x000, "vptr offset");
static_assert(offsetof(ns1_ccUiTaskBase, task_ptr_1) == 0x018, "task_ptr_1 offset");
static_assert(offsetof(ns1_ccUiTaskBase, task_ptr_2) == 0x020, "task_ptr_2 offset");
static_assert(offsetof(ns1_ccUiTaskBase, field_2C)   == 0x02C, "field_2C offset");
static_assert(offsetof(ns1_ccUiTaskBase, field_34)   == 0x034, "field_34 offset");

#endif /* CMN17_H */