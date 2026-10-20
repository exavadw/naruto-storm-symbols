/* cmn17.h — NARUTO STORM 2 PC (s2/NSUNS2.exe) struct reconstruction
 * Group: ccUiSprite, ccUiStaffRoll, ccUiTaskBase, ccUiTaskBaseList, ccUiUtilSound
 * All results are INFERRED from static analysis (Ghidra decompile + state_surface).
 * Own-game names only (ns2:: namespace).
 * PC offsets re-derived from x64 decompile; never copied from other builds.
 */
#ifndef CMN17_S2_H
#define CMN17_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here */
typedef struct { float x, y, z; } ns2_Vector3; /* 12 bytes */
typedef struct { float x, y; } ns2_Vector2; /* 8 bytes */
typedef struct { float m[16]; } ns2_Matrix44; /* 64 bytes */
typedef struct { float r, g, b, a; } ns2_Color; /* 16 bytes */

/* ========================================================================
 * ccUiObject (base class) — size >= 0xC0 from ctor field accesses
 * Vtable: PTR_FUN_1408a0390 (inherited by ccUiSprite)
 * Not reconstructed standalone; included as base of ccUiSprite.
 * ======================================================================== */

/* ========================================================================
 * ccUiSprite — size = 400 (0x190)
 * Proven by: ccFileLoadListForUi::LoadTh(400, ...) in s2 Initialize (0x41DFAC)
 * Vtable: PTR_FUN_1408a0390 (0x1408A0390)
 * Methods cached: 15 seeds, all ok
 * Fields: 17 total (8 writable scalars, 9 read-only embedded sub-objects)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
 /* 0x000 - ccUiObject base (vptr at +0x00) */
 uint64_t vptr; /* 0x000 */
 uint8_t _base_pad[0xC0 - 8]; /* 0x008..0x0BF ccUiObject body */

 /* Writable scalar fields from state_surface */
 uint32_t field_C0; /* 0x0C0 write u32, ctor init=0 */
 uint8_t _pad_C4[4]; /* 0x0C4 gap to 0x0C8 */
 uint64_t field_C8; /* 0x0C8 write u64, ctor init=0 */
 uint32_t field_D0; /* 0x0D0 write u32, ctor init=0 */

 /* Embedded sub-objects initialized in ctor (read-only access pattern) */
 ns2_Vector3 pos; /* 0x0D4 Vector3 ctor */
 ns2_Vector3 field_E0; /* 0x0E0 Vector3 ctor */
 ns2_Vector2 scale_default; /* 0x0EC Vector2(1.0,1.0) */
 ns2_Vector2 size; /* 0x0F4 Vector2(100.0,100.0) */
 ns2_Vector3 field_FC; /* 0x0FC Vector3 from DAT_14088f6a8 */
 ns2_Vector2 uv_offset; /* 0x108 Vector2(0,0) */
 ns2_Vector2 field_110; /* 0x110 Vector2 copy of size */
 ns2_Matrix44 transform; /* 0x118 Matrix44 ctor */

 uint32_t field_158; /* 0x158 write u32, ctor init=0 */
 uint8_t _pad_15C[4]; /* 0x15C gap to 0x160 */
 ns2_Color color; /* 0x160 nuccCOLOR(1,1,1,1) */
 uint64_t field_170; /* 0x170 write u64, ctor=0x10000001 */
 uint32_t field_178; /* 0x178 write u32, ctor init=3 */
 uint32_t field_17C; /* 0x17C write u32, ctor=0x20061 */
 uint64_t field_180; /* 0x180 write u64, ctor init=0 */
 uint8_t _tail_pad[0x190 - 0x188];/* 0x188..0x18F pad to size 400 */
} ns2_ccUiSprite;

static_assert(sizeof(ns2_ccUiSprite) == 400, "ns2_ccUiSprite size must be 400");
static_assert(offsetof(ns2_ccUiSprite, vptr) == 0x000, "vptr offset");
static_assert(offsetof(ns2_ccUiSprite, field_C0) == 0x0C0, "field_C0 offset");
static_assert(offsetof(ns2_ccUiSprite, field_C8) == 0x0C8, "field_C8 offset");
static_assert(offsetof(ns2_ccUiSprite, field_D0) == 0x0D0, "field_D0 offset");
static_assert(offsetof(ns2_ccUiSprite, pos) == 0x0D4, "pos offset");
static_assert(offsetof(ns2_ccUiSprite, field_E0) == 0x0E0, "field_E0 offset");
static_assert(offsetof(ns2_ccUiSprite, scale_default) == 0x0EC, "scale_default offset");
static_assert(offsetof(ns2_ccUiSprite, size) == 0x0F4, "size offset");
static_assert(offsetof(ns2_ccUiSprite, field_FC) == 0x0FC, "field_FC offset");
static_assert(offsetof(ns2_ccUiSprite, uv_offset) == 0x108, "uv_offset offset");
static_assert(offsetof(ns2_ccUiSprite, field_110) == 0x110, "field_110 offset");
static_assert(offsetof(ns2_ccUiSprite, transform) == 0x118, "transform offset");
static_assert(offsetof(ns2_ccUiSprite, field_158) == 0x158, "field_158 offset");
static_assert(offsetof(ns2_ccUiSprite, color) == 0x160, "color offset");
static_assert(offsetof(ns2_ccUiSprite, field_170) == 0x170, "field_170 offset");
static_assert(offsetof(ns2_ccUiSprite, field_178) == 0x178, "field_178 offset");
static_assert(offsetof(ns2_ccUiSprite, field_17C) == 0x17C, "field_17C offset");
static_assert(offsetof(ns2_ccUiSprite, field_180) == 0x180, "field_180 offset");

/* ========================================================================
 * ccUiTaskBase — size = 0x38 (56 bytes)
 * Size lower bound: ctor writes at +0x34 require >= 0x38.
 * dtor accesses param_1[3] (0x18) and param_1[4] (0x20) confirming ptrs.
 * No LoadTh size proof found in s2 for this class directly.
 * Vtable: PTR_FUN_14089fe88 (0x14089FE88)
 * Methods cached: 7 seeds (3 ctors, dtor, 3 SetEnable*), all ok
 * Fields: 5 named (2 task ptrs, 2 writable u32, 1 pad)
 * Note: subclass ctor at 0x4FCB68 uses different vtable PTR_FUN_14085e9b8
 * and writes at 0x4C and 0xD0 — those belong to the subclass, not ccUiTaskBase.
 * ======================================================================== */
typedef struct __attribute__((packed)) {
 uint64_t vptr; /* 0x000 */
 uint8_t _pad_008[0x18 - 8]; /* 0x008..0x017 ccUiObject base body */
 uint64_t ctrl_task_ptr; /* 0x018 from ctor/dtor/SetEnableCtrlTask */
 uint64_t draw_task_ptr; /* 0x020 from ctor/dtor/SetEnableDrawTask */
 uint8_t _pad_028[4]; /* 0x028 gap */
 uint32_t field_2C; /* 0x02C write u32, param_7 in ctor */
 uint32_t field_30; /* 0x030 gap/filler */
 uint32_t field_34; /* 0x034 write u32, param_4 in ctor */
} ns2_ccUiTaskBase;

static_assert(sizeof(ns2_ccUiTaskBase) == 0x38, "ns2_ccUiTaskBase size must be 0x38");
static_assert(offsetof(ns2_ccUiTaskBase, vptr) == 0x000, "vptr offset");
static_assert(offsetof(ns2_ccUiTaskBase, ctrl_task_ptr) == 0x018, "ctrl_task_ptr offset");
static_assert(offsetof(ns2_ccUiTaskBase, draw_task_ptr) == 0x020, "draw_task_ptr offset");
static_assert(offsetof(ns2_ccUiTaskBase, field_2C) == 0x02C, "field_2C offset");
static_assert(offsetof(ns2_ccUiTaskBase, field_34) == 0x034, "field_34 offset");

/* ========================================================================
 * ccUiStaffRoll — size = 0x98 (152 bytes)
 * Proven by: ccLoDemoStateMachine::CreateStaffRoll calls LoadTh(0x98, ...)
 * Vtable: PTR_FUN_140861c00 (0x140861C00)
 * Base class: ccUiTaskBase (occupies 0x000..0x037)
 * Methods cached: 8 seeds, all ok
 * Fields: 12 named (from manual decompile + state_surface)
 * Layout derived from: ctor (0x51B874), Ctrl (0x51C868), MyCtrl (0x51BD2C),
 * AddCommand (0x51C398), Draw (0x51CA10), ~ccUiStaffRoll (0x51C368)
 *
 * Packed offset trace (verified):
 * 0x000 vptr (8) -> 0x008
 * 0x008 _base_pad (0x30) -> 0x038
 * 0x038 font_ptr (8) -> 0x040
 * 0x040 ui_object_container (8) -> 0x048
 * 0x048 cmd_array_begin (8) -> 0x050
 * 0x050 cmd_array_end (8) -> 0x058
 * 0x058 _pad (0x20) -> 0x078
 * 0x078 field_78 (4) -> 0x07C
 * 0x07C field_7C (4) -> 0x080
 * 0x080 _pad (4) -> 0x084
 * 0x084 scroll_pos (Vector2=8) -> 0x08C
 * 0x08C entry_array_begin (8) -> 0x094
 * 0x094 _tail_pad (4) -> 0x098 ✓
 *
 * Fields at 0x094+ from decompile (entry_array_end, field_B0-D8) exceed
 * the proven 0x98 allocation size. They may belong to a subclass or the
 * allocation is larger than LoadTh reports. Excluded pending runtime confirmation.
 * ======================================================================== */
typedef struct __attribute__((packed)) {
 /* ccUiTaskBase base (0x000..0x037) */
 uint64_t vptr; /* 0x000 */
 uint8_t _base_pad[0x38 - 8]; /* 0x008..0x037 ccUiTaskBase body */

 /* ccUiStaffRoll own fields */
 uint64_t font_ptr; /* 0x038 pointer, used in Draw/Ctrl */
 uint8_t ui_object_container[8]; /* 0x040 embedded ccUiObjectContainer */
 uint64_t cmd_array_begin; /* 0x048 array begin ptr (MyCtrl) */
 uint64_t cmd_array_end; /* 0x050 array end ptr (MyCtrl) */
 uint8_t _pad_058[0x78 - 0x58]; /* 0x058..0x077 gap */
 uint32_t field_78; /* 0x078 int counter (MyCtrl) */
 uint32_t field_7C; /* 0x07C int counter (MyCtrl) */
 uint8_t _pad_080[4]; /* 0x080..0x083 gap to align scroll_pos */
 ns2_Vector2 scroll_pos; /* 0x084 Vector2 from ctor (state_surface) */
 uint64_t entry_array_begin; /* 0x08C array begin ptr (Ctrl/AddCommand) */
 uint8_t _tail_pad[0x98 - 0x94]; /* 0x094..0x097 pad to size 0x98 */
} ns2_ccUiStaffRoll;

static_assert(sizeof(ns2_ccUiStaffRoll) == 0x98, "ns2_ccUiStaffRoll size must be 0x98");
static_assert(offsetof(ns2_ccUiStaffRoll, vptr) == 0x000, "vptr offset");
static_assert(offsetof(ns2_ccUiStaffRoll, font_ptr) == 0x038, "font_ptr offset");
static_assert(offsetof(ns2_ccUiStaffRoll, ui_object_container) == 0x040, "ui_object_container offset");
static_assert(offsetof(ns2_ccUiStaffRoll, cmd_array_begin) == 0x048, "cmd_array_begin offset");
static_assert(offsetof(ns2_ccUiStaffRoll, cmd_array_end) == 0x050, "cmd_array_end offset");
static_assert(offsetof(ns2_ccUiStaffRoll, field_78) == 0x078, "field_78 offset");
static_assert(offsetof(ns2_ccUiStaffRoll, field_7C) == 0x07C, "field_7C offset");
static_assert(offsetof(ns2_ccUiStaffRoll, scroll_pos) == 0x084, "scroll_pos offset");
static_assert(offsetof(ns2_ccUiStaffRoll, entry_array_begin) == 0x08C, "entry_array_begin offset");

#endif /* CMN17_S2_H */