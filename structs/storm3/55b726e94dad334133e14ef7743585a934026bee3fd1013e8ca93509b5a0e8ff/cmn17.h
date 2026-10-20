/* cmn17.h — NARUTO STORM 3 Full Burst HD PC (s3/NSUNS3.exe) struct reconstruction
 * Group: ccUiSprite, ccUiStaffRoll, ccUiTaskBase, ccUiTaskBaseList, ccUiUtilSound
 * All results are INFERRED from static analysis (Ghidra decompile + state_surface).
 * Own-game names only (ns3:: namespace).
 * PC offsets re-derived from s3 x64 decompile; never copied from other builds.
 */
#ifndef CMN17_S3_H
#define CMN17_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here */
typedef struct { float x, y, z; } ns3_Vector3; /* 12 bytes */
typedef struct { float x, y; } ns3_Vector2; /* 8 bytes */
typedef struct { float m[16]; } ns3_Matrix44; /* 64 bytes */
typedef struct { float r, g, b, a; } ns3_Color; /* 16 bytes */

/* ========================================================================
 * ccUiObject (base class) — size >= 0xC0 from ctor field accesses
 * Vtable: PTR_FUN_1409ecf80 (inherited by ccUiSprite)
 * Not reconstructed standalone; included as base of ccUiSprite.
 * ======================================================================== */

/* ========================================================================
 * ccUiSprite — size = 400 (0x190)
 * Size lower bound: ctor writes at +0x180 require >= 0x188; matches s2 LoadTh(400).
 * Vtable: PTR_FUN_1409ecf80 (0x1409ECF80)
 * Methods cached: 15 seeds, all ok
 * Fields: 18 total (vptr + 8 writable scalars + 9 read-only embedded sub-objects)
 * Evidence: ccUiSprite::ccUiSprite (0x75AD10), state_surface JSON
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* 0x000 - ccUiObject base (vptr at +0x00) */
    uint64_t vptr;                    /* 0x000 */
    uint8_t _base_pad[0xC0 - 8];      /* 0x008..0x0BF ccUiObject body */

    /* Writable scalar fields from ctor/state_surface */
    uint32_t field_C0;                /* 0x0C0 write u32, ctor init=0 */
    uint8_t _pad_C4[4];               /* 0x0C4 gap to 0x0C8 */
    uint64_t field_C8;                /* 0x0C8 write u64, ctor init=0 */
    uint32_t field_D0;                /* 0x0D0 write u32, ctor init=0 */

    /* Embedded sub-objects initialized in ctor (read-only access pattern) */
    ns3_Vector3 pos;                  /* 0x0D4 Vector3 ctor */
    ns3_Vector3 field_E0;             /* 0x0E0 Vector3 ctor */
    ns3_Vector2 scale_default;        /* 0x0EC Vector2(1.0,1.0) */
    ns3_Vector2 size;                 /* 0x0F4 Vector2(100.0,100.0) */
    ns3_Vector3 field_FC;             /* 0x0FC Vector3 from DAT_1409deaf8 */
    ns3_Vector2 uv_offset;            /* 0x108 Vector2(0,0) */
    ns3_Vector2 field_110;            /* 0x110 Vector2 copy of size */
    ns3_Matrix44 transform;           /* 0x118 Matrix44 ctor */

    uint32_t field_158;               /* 0x158 write u32, ctor init=0 */
    uint8_t _pad_15C[4];              /* 0x15C gap to 0x160 */
    ns3_Color color;                  /* 0x160 nuccCOLOR(1,1,1,1) */
    uint64_t field_170;               /* 0x170 write u64, ctor=0x10000001 */
    uint32_t field_178;               /* 0x178 write u32, ctor init=3 */
    uint32_t field_17C;               /* 0x17C write u32, ctor=0x20061 */
    uint64_t field_180;               /* 0x180 write u64, ctor init=0 */
    uint8_t _tail_pad[0x190 - 0x188]; /* 0x188..0x18F pad to size 400 */
} ns3_ccUiSprite;

static_assert(sizeof(ns3_ccUiSprite) == 400, "ns3_ccUiSprite size must be 400");
static_assert(offsetof(ns3_ccUiSprite, vptr) == 0x000, "vptr offset");
static_assert(offsetof(ns3_ccUiSprite, field_C0) == 0x0C0, "field_C0 offset");
static_assert(offsetof(ns3_ccUiSprite, field_C8) == 0x0C8, "field_C8 offset");
static_assert(offsetof(ns3_ccUiSprite, field_D0) == 0x0D0, "field_D0 offset");
static_assert(offsetof(ns3_ccUiSprite, pos) == 0x0D4, "pos offset");
static_assert(offsetof(ns3_ccUiSprite, field_E0) == 0x0E0, "field_E0 offset");
static_assert(offsetof(ns3_ccUiSprite, scale_default) == 0x0EC, "scale_default offset");
static_assert(offsetof(ns3_ccUiSprite, size) == 0x0F4, "size offset");
static_assert(offsetof(ns3_ccUiSprite, field_FC) == 0x0FC, "field_FC offset");
static_assert(offsetof(ns3_ccUiSprite, uv_offset) == 0x108, "uv_offset offset");
static_assert(offsetof(ns3_ccUiSprite, field_110) == 0x110, "field_110 offset");
static_assert(offsetof(ns3_ccUiSprite, transform) == 0x118, "transform offset");
static_assert(offsetof(ns3_ccUiSprite, field_158) == 0x158, "field_158 offset");
static_assert(offsetof(ns3_ccUiSprite, color) == 0x160, "color offset");
static_assert(offsetof(ns3_ccUiSprite, field_170) == 0x170, "field_170 offset");
static_assert(offsetof(ns3_ccUiSprite, field_178) == 0x178, "field_178 offset");
static_assert(offsetof(ns3_ccUiSprite, field_17C) == 0x17C, "field_17C offset");
static_assert(offsetof(ns3_ccUiSprite, field_180) == 0x180, "field_180 offset");

/* ========================================================================
 * ccUiTaskBase — size = 0x38 (56 bytes)
 * Size proven by: ctor LoadTh(0x30) for sub-tasks + base fields require >= 0x38.
 * dtor accesses param_1[3] (0x18) and param_1[4] (0x20) confirming ptrs.
 * Vtable: PTR_FUN_1409ed050 (0x1409ED050)
 * Methods cached: 7 seeds (3 ctors, dtor, 3 SetEnable*), all ok
 * Fields: 5 named (2 task ptrs, 2 writable u32, 1 pad)
 * Evidence: ccUiTaskBase::ccUiTaskBase (0x75C3B0), ~ccUiTaskBase (0x75C5F0)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vptr;                    /* 0x000 */
    uint8_t _pad_008[0x18 - 8];       /* 0x008..0x017 ccUiObject base body */
    uint64_t ctrl_task_ptr;           /* 0x018 from ctor/dtor/SetEnableCtrlTask */
    uint64_t draw_task_ptr;           /* 0x020 from ctor/dtor/SetEnableDrawTask */
    uint8_t _pad_028[4];              /* 0x028 gap */
    uint32_t field_2C;                /* 0x02C write u32, param_7 in ctor */
    uint32_t field_30;                /* 0x030 gap/filler */
    uint32_t field_34;                /* 0x034 write u32, param_4 in ctor */
} ns3_ccUiTaskBase;

static_assert(sizeof(ns3_ccUiTaskBase) == 0x38, "ns3_ccUiTaskBase size must be 0x38");
static_assert(offsetof(ns3_ccUiTaskBase, vptr) == 0x000, "vptr offset");
static_assert(offsetof(ns3_ccUiTaskBase, ctrl_task_ptr) == 0x018, "ctrl_task_ptr offset");
static_assert(offsetof(ns3_ccUiTaskBase, draw_task_ptr) == 0x020, "draw_task_ptr offset");
static_assert(offsetof(ns3_ccUiTaskBase, field_2C) == 0x02C, "field_2C offset");
static_assert(offsetof(ns3_ccUiTaskBase, field_34) == 0x034, "field_34 offset");

/* ========================================================================
 * ccUiStaffRoll — size unknown, >= 0xD8
 * No LoadTh size proof found in s3. AddCommand accesses fields up to 0xD4.
 * Only 1 symbolized method (AddCommand at 0x459EBC); no ctor in symbol table.
 * Base class: ccUiTaskBase (occupies 0x000..0x037)
 * Fields derived from AddCommand decompile: font_ptr at 0x38, cmd arrays at 0x80/0x88,
 * float fields at 0xBC/0xC0/0xD4.
 * NOT RECONSTRUCTED as standalone struct due to insufficient evidence.
 * Listed in report as gap.
 * ======================================================================== */

/* ========================================================================
 * ccUiTaskBaseList — NOT RECONSTRUCTED
 * Only 1 method (ReleaseUi at 0x75C240); below >= 3 methods threshold.
 * ======================================================================== */

/* ========================================================================
 * ccUiUtilSound — size unknown, >= 0x30
 * Ctor at 0x764BB0: vtable PTR_FUN_1409ec308, appends 0x15 (21) ints via std::vector.
 * 3 methods (ctor, SetFunction, Call) meets threshold but struct is thin wrapper.
 * NOT RECONSTRUCTED as standalone struct due to insufficient field evidence.
 * Listed in report as gap.
 * ======================================================================== */

#endif /* CMN17_S3_H */