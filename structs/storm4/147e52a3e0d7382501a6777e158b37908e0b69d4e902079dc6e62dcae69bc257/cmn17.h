/* cmn17.h — NARUTO STORM 4 PC 1.09 (s4/NSUNS4_release.exe) struct reconstruction
 * Group: ccUiSprite, ccUiStaffRoll, ccUiTaskBase, ccUiTaskBaseList, ccUiUtilSound
 * All results are INFERRED from static analysis (Ghidra decompile + state_surface).
 * Own-game names only (Storm 4 has no Trilogy namespace).
 * PC offsets re-derived from s4 x64 decompile; never copied from other builds.
 */
#ifndef CMN17_S4_H
#define CMN17_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here */
typedef struct { float x, y, z; } s4_Vector3;    /* 12 bytes */
typedef struct { float x, y; }     s4_Vector2;    /* 8 bytes */
typedef struct { float m[16]; }    s4_Matrix44;   /* 64 bytes */
typedef struct { float r, g, b, a; } s4_Color;    /* 16 bytes */

/* ========================================================================
 * ccUiObject (base class) — size >= 0xC0 from ctor field accesses
 * Vtable: PTR_FUN_1411166a8 (inherited by ccUiSprite)
 * Not reconstructed standalone; included as base of ccUiSprite.
 * ======================================================================== */

/* ========================================================================
 * ccUiSprite — size = 400 (0x190)
 * Size proof: operator_new(400, "ccUiObjectHelper.h", 0x8c) in Initialize@0x5F03B4
 * Vtable: PTR_FUN_1411166a8 (0x1411166A8)
 * Methods cached: 18 seeds, all ok
 * Fields: 18 total (vptr + 8 writable scalars + 9 read-only embedded sub-objects)
 * Evidence: ccUiSprite::ccUiSprite (0xADD2C0), ccUiSprite::Initialize (0x5F03B4),
 *           state_surface JSON (17 fields, 18 seeds)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* 0x000 - ccUiObject base (vptr at +0x00) */
    uint64_t vptr;                        /* 0x000 */
    uint8_t  _base_pad[0xC0 - 8];         /* 0x008..0x0BF ccUiObject body */

    /* Writable scalar fields from ctor/state_surface */
    uint32_t field_C0;                    /* 0x0C0 write u32, ctor init=0 */
    uint8_t  _pad_C4[4];                  /* 0x0C4 gap to 0x0C8 */
    uint64_t field_C8;                    /* 0x0C8 write u64, ctor init=0 */
    uint32_t field_D0;                    /* 0x0D0 write u32, ctor init=0 */

    /* Embedded sub-objects initialized in ctor (read-only access pattern) */
    s4_Vector3 pos;                       /* 0x0D4 Vector3 ctor */
    s4_Vector3 field_E0;                  /* 0x0E0 Vector3 ctor */
    s4_Vector2 scale_default;             /* 0x0EC Vector2(1.0,1.0) */
    s4_Vector2 size;                      /* 0x0F4 Vector2(100.0,100.0) */
    s4_Vector3 field_FC;                  /* 0x0FC Vector3 from DAT */
    s4_Vector2 uv_offset;                 /* 0x108 Vector2(0,0) */
    s4_Vector2 field_110;                 /* 0x110 Vector2 copy of size */
    s4_Matrix44 transform;                /* 0x118 Matrix44 ctor */

    uint32_t field_158;                   /* 0x158 write u32, ctor init=0 */
    uint8_t  _pad_15C[4];                 /* 0x15C gap to 0x160 */
    s4_Color color;                       /* 0x160 nuccCOLOR(1,1,1,1) */
    uint64_t field_170;                   /* 0x170 write u64, ctor=0x10000001 */
    uint32_t field_178;                   /* 0x178 write u32, ctor init=3 */
    uint32_t field_17C;                   /* 0x17C write u32, ctor=0x20061 */
    uint64_t field_180;                   /* 0x180 write u64, ctor init=0 */
    uint8_t  _tail_pad[0x190 - 0x188];   /* 0x188..0x18F pad to size 400 */
} s4_ccUiSprite;

static_assert(sizeof(s4_ccUiSprite) == 400, "s4_ccUiSprite size must be 400");
static_assert(offsetof(s4_ccUiSprite, vptr) == 0x000, "vptr offset");
static_assert(offsetof(s4_ccUiSprite, field_C0) == 0x0C0, "field_C0 offset");
static_assert(offsetof(s4_ccUiSprite, field_C8) == 0x0C8, "field_C8 offset");
static_assert(offsetof(s4_ccUiSprite, field_D0) == 0x0D0, "field_D0 offset");
static_assert(offsetof(s4_ccUiSprite, pos) == 0x0D4, "pos offset");
static_assert(offsetof(s4_ccUiSprite, field_E0) == 0x0E0, "field_E0 offset");
static_assert(offsetof(s4_ccUiSprite, scale_default) == 0x0EC, "scale_default offset");
static_assert(offsetof(s4_ccUiSprite, size) == 0x0F4, "size offset");
static_assert(offsetof(s4_ccUiSprite, field_FC) == 0x0FC, "field_FC offset");
static_assert(offsetof(s4_ccUiSprite, uv_offset) == 0x108, "uv_offset offset");
static_assert(offsetof(s4_ccUiSprite, field_110) == 0x110, "field_110 offset");
static_assert(offsetof(s4_ccUiSprite, transform) == 0x118, "transform offset");
static_assert(offsetof(s4_ccUiSprite, field_158) == 0x158, "field_158 offset");
static_assert(offsetof(s4_ccUiSprite, color) == 0x160, "color offset");
static_assert(offsetof(s4_ccUiSprite, field_170) == 0x170, "field_170 offset");
static_assert(offsetof(s4_ccUiSprite, field_178) == 0x178, "field_178 offset");
static_assert(offsetof(s4_ccUiSprite, field_17C) == 0x17C, "field_17C offset");
static_assert(offsetof(s4_ccUiSprite, field_180) == 0x180, "field_180 offset");

/* ========================================================================
 * ccUiTaskBase — size = 0x38 (56 bytes)
 * Size proof: base ctor (0xAD0FE0) writes up to +0x34, requiring >= 0x38.
 *   No direct operator_new for the base class exists; it is always allocated
 *   as part of a derived class (e.g. ccBoss0401OffScreenOrbit, ccUiScrollFont,
 *   ccUiWindow, ccUiKeyHelp, ccUiScrollBar). The base ctor field writes are
 *   the definitive size evidence for the base portion.
 *   Matches s3 ns3_ccUiTaskBase size of 0x38 exactly.
 * Vtable: PTR_FUN_141115fd8 (0x141115FD8) — set by base ctor at 0xAD0FE0
 * Methods cached: 9 seeds (multiple ctor variants + dtor + SetEnable*), all ok
 * Fields: 5 named (2 task ptrs, 2 writable u32, 1 pad)
 * Evidence: ccUiTaskBase::ccUiTaskBase (0xAD0FE0), state_surface filtered
 * NOTE: state_surface returned 29 fields including artifacts at 0xB00,
 *   0x15C90, 0x15CA0 from misattributed derived-class methods (different
 *   vtables). Only fields from the true base ctor (0xAD0FE0) are included.
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint64_t vptr;                        /* 0x000 */
    uint8_t  _pad_008[0x18 - 8];          /* 0x008..0x017 ccUiObject base body */
    uint64_t ctrl_task_ptr;               /* 0x018 from ctor param_1[3]=0 */
    uint64_t draw_task_ptr;               /* 0x020 from ctor param_1[4]=0 */
    uint8_t  _pad_028[4];                 /* 0x028 gap */
    uint32_t field_2C;                    /* 0x02C write u32, ctor init=0 */
    uint32_t field_30;                    /* 0x030 gap/filler */
    uint32_t field_34;                    /* 0x034 write u32, ctor init=0 */
} s4_ccUiTaskBase;

static_assert(sizeof(s4_ccUiTaskBase) == 0x38, "s4_ccUiTaskBase size must be 0x38");
static_assert(offsetof(s4_ccUiTaskBase, vptr) == 0x000, "vptr offset");
static_assert(offsetof(s4_ccUiTaskBase, ctrl_task_ptr) == 0x018, "ctrl_task_ptr offset");
static_assert(offsetof(s4_ccUiTaskBase, draw_task_ptr) == 0x020, "draw_task_ptr offset");
static_assert(offsetof(s4_ccUiTaskBase, field_2C) == 0x02C, "field_2C offset");
static_assert(offsetof(s4_ccUiTaskBase, field_34) == 0x034, "field_34 offset");

/* ========================================================================
 * ccUiStaffRoll — NOT RECONSTRUCTED
 * state_surface returned 0 fields with only 1 seed method.
 * Below the >= 3 methods threshold for reconstruction.
 * Known methods: Initialize (0x62569C) — accesses fields at +0x80, +0x84
 *   and allocates 0x20-byte sub-objects via operator_new.
 * Source file: ccUiFlashAdvStaffRoll.cpp
 * Gap: need additional symbolized methods or runtime trace.
 * ======================================================================== */

/* ========================================================================
 * ccUiTaskBaseList — NOT RECONSTRUCTED
 * Insufficient symbolized methods in s4 build.
 * Likely thin wrapper around ccUiTaskBase array/container (same as s3).
 * ======================================================================== */

/* ========================================================================
 * ccUiUtilSound — NOT RECONSTRUCTED
 * state_surface returned 0 fields despite 3 seed methods.
 * Ctor (0xB00CB0): BlockAllocator init, std::vector append of 0x15 (21) ints.
 * Thin sound-effect wrapper with minimal direct field evidence.
 * Gap: fields stored in std::vector, not as direct struct members.
 * ======================================================================== */

#endif /* CMN17_S4_H */