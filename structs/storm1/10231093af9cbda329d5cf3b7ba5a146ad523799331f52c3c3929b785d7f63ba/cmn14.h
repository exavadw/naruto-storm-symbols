/* cmn14.h — NARUTO STORM 1 PC (NSUNS1.exe, build s1)
 * Struct group: ccUiLayoutParts, ccUiLoader, ccUiManager, ccUiObject,
 *               ccUiObjectContainer, ccUiOpenCloseCtrl, ccUiPartsParamBinary,
 *               ccUiScreenInfo
 *
 * All layouts INFERRED from static decompilation of s1 x64 binary.
 * Sizes are UNPROVEN unless noted; no sizeof asserts on incomplete structs.
 * Field names from s1 symbols/strings only (own-game rule).
 * Rollback tags: SIM = simulation state, PRES = presentation-only, UNKNOWN.
 */
#ifndef CMN14_H
#define CMN14_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- ccUiScreenInfo ----
 * Constructor @0x53D320 writes vtable at +0x0, Vector2 at +0xC, uint flag at +0x4.
 * Size unknown, >= 0x14.
 */
typedef struct __attribute__((packed)) ccUiScreenInfo {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint32_t is_wide;          /* (uint)(1280.0 < screen_width), ctor */
    /* 0x0C */ float scale_x;             /* Vector2::one() x component */
    /* 0x10 */ float scale_y;             /* Vector2::one() y component */
} ccUiScreenInfo;

static_assert(offsetof(ccUiScreenInfo, vtable) == 0x00, "ccUiScreenInfo.vtable");
static_assert(offsetof(ccUiScreenInfo, is_wide) == 0x08, "ccUiScreenInfo.is_wide");
static_assert(offsetof(ccUiScreenInfo, scale_x) == 0x0C, "ccUiScreenInfo.scale_x");
static_assert(offsetof(ccUiScreenInfo, scale_y) == 0x10, "ccUiScreenInfo.scale_y");

/* ---- ccUiManager ----
 * Constructor @0x53D3D0. Inherits BlockAllocator base (vtable +0x0, block fields).
 * Fields proven by ctor writes: +0x1A8 (qword rw), +0x1B0 (qword w), +0x1B8 (vtable ptr w),
 * +0x1C0 (uint w), +0x1C4 (Vector2 via Nucc::Vector2::Vector2).
 * Size unknown, >= 0x1CC.
 */
typedef struct __attribute__((packed)) ccUiManager {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint8_t _base_block_allocator[0x1A0]; /* BlockAllocator base, layout not reconstructed */
    /* 0x1A8 */ uint64_t field_1a8;                   /* rw in Initialize/ctor */
    /* 0x1B0 */ uint64_t field_1b0;                   /* w in ctor, zeroed */
    /* 0x1B8 */ void *field_1b8_vtable;               /* w in ctor, PTR_FUN_140773600 */
    /* 0x1C0 */ uint32_t is_wide;                     /* w in ctor, (uint)(1280.0 < ...) */
    /* 0x1C4 */ float vec_scale_x;                    /* Vector2::one() via Nucc::Vector2::Vector2 */
    /* 0x1C8 */ float vec_scale_y;                    /* Vector2::one() */
} ccUiManager;

static_assert(offsetof(ccUiManager, vtable) == 0x000, "ccUiManager.vtable");
static_assert(offsetof(ccUiManager, field_1a8) == 0x1A8, "ccUiManager.field_1a8");
static_assert(offsetof(ccUiManager, field_1b0) == 0x1B0, "ccUiManager.field_1b0");
static_assert(offsetof(ccUiManager, field_1b8_vtable) == 0x1B8, "ccUiManager.field_1b8_vtable");
static_assert(offsetof(ccUiManager, is_wide) == 0x1C0, "ccUiManager.is_wide");
static_assert(offsetof(ccUiManager, vec_scale_x) == 0x1C4, "ccUiManager.vec_scale_x");
static_assert(offsetof(ccUiManager, vec_scale_y) == 0x1C8, "ccUiManager.vec_scale_y");

/* ---- ccUiObject ----
 * Constructor @0x546F50. Inherits BlockAllocator base.
 * Proven fields: +0x88 (qword w), +0x90 (dword w), +0x98 (dword w), +0x9C (byte w),
 * +0xA0 (qword w), +0xA8 (dword w, param_2), +0xAC (dword w, param_3),
 * +0xB0 (dword w), +0xB4 (dword rw), +0xB8 (dword w).
 * Vtable deref at +0x80 (read), virtual call at +0x3C0 (read).
 * Size unknown, >= 0x3C8.
 */
typedef struct __attribute__((packed)) ccUiObject {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint8_t _base_block_allocator[0x80]; /* BlockAllocator base */
    /* 0x088 */ uint64_t field_088;                  /* w in ctor, zeroed */
    /* 0x090 */ uint32_t field_090;                  /* w in ctor, zeroed */
    /* 0x094 */ uint8_t _pad_094[4];                 /* explicit padding */
    /* 0x098 */ uint32_t field_098;                  /* w in ctor, zeroed */
    /* 0x09C */ uint8_t field_09c;                   /* w in ctor, byte zeroed */
    /* 0x09D */ uint8_t _pad_09d[3];                 /* explicit padding */
    /* 0x0A0 */ uint64_t field_0a0;                  /* w in ctor, zeroed */
    /* 0x0A8 */ uint32_t type_id;                    /* w in ctor, param_2 */
    /* 0x0AC */ uint32_t field_0ac;                  /* w in ctor, param_3 */
    /* 0x0B0 */ uint32_t field_0b0;                  /* w in ctor, zeroed */
    /* 0x0B4 */ uint32_t enable_flag;                /* rw in Ctrl/ctor, init 1 */
    /* 0x0B8 */ uint32_t field_0b8;                  /* w in ctor, init 1 */
    /* 0x0BC */ uint8_t _pad_0bc[0x304];             /* gap to 0x3C0 virtual call site */
} ccUiObject;

static_assert(offsetof(ccUiObject, vtable) == 0x000, "ccUiObject.vtable");
static_assert(offsetof(ccUiObject, field_088) == 0x088, "ccUiObject.field_088");
static_assert(offsetof(ccUiObject, field_090) == 0x090, "ccUiObject.field_090");
static_assert(offsetof(ccUiObject, field_098) == 0x098, "ccUiObject.field_098");
static_assert(offsetof(ccUiObject, field_09c) == 0x09C, "ccUiObject.field_09c");
static_assert(offsetof(ccUiObject, field_0a0) == 0x0A0, "ccUiObject.field_0a0");
static_assert(offsetof(ccUiObject, type_id) == 0x0A8, "ccUiObject.type_id");
static_assert(offsetof(ccUiObject, field_0ac) == 0x0AC, "ccUiObject.field_0ac");
static_assert(offsetof(ccUiObject, field_0b0) == 0x0B0, "ccUiObject.field_0b0");
static_assert(offsetof(ccUiObject, enable_flag) == 0x0B4, "ccUiObject.enable_flag");
static_assert(offsetof(ccUiObject, field_0b8) == 0x0B8, "ccUiObject.field_0b8");

/* ---- ccUiObjectContainer ----
 * Constructor @0x53E0B0. Inherits BlockAllocator base.
 * Only proven field: vtable read at +0x80 (virtual dispatch in Add/Remove/Release/ReleaseAll).
 * Size unknown, >= 0x88.
 */
typedef struct __attribute__((packed)) ccUiObjectContainer {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _base_block_allocator[0x78]; /* BlockAllocator base */
    /* 0x80 */ void *_vfunc_ptr;                    /* read via (*param_1 + 0x10) dispatch */
} ccUiObjectContainer;

static_assert(offsetof(ccUiObjectContainer, vtable) == 0x00, "ccUiObjectContainer.vtable");
static_assert(offsetof(ccUiObjectContainer, _vfunc_ptr) == 0x80, "ccUiObjectContainer._vfunc_ptr");

/* ---- ccUiOpenCloseCtrl ----
 * Constructor @0x588C50. Does NOT inherit BlockAllocator (no GetBlockManager call).
 * Proven fields: +0x08 (qword, set to 4), +0x18 (qword, DAT ptr), +0x20 (dword, 0xffffffff),
 * +0x28 (qword, DAT ptr), +0x30 (dword, zeroed), +0x34 (qword, 5), +0x3C (float, 1.0f),
 * +0x40 (qword, zeroed), +0x78 (qword read, ptr deref in _Open), +0x80 (qword rw in _Open),
 * +0xB4 (qword w in _Open), +0x240 (vtable+0x48 dispatch in Close).
 * Size unknown, >= 0x248.
 */
typedef struct __attribute__((packed)) ccUiOpenCloseCtrl {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint64_t count;                     /* ctor sets to 4 */
    /* 0x010 */ uint8_t _pad_010[8];                /* explicit padding */
    /* 0x018 */ void *dat_ptr_018;                  /* ctor: &DAT_1407496e0 */
    /* 0x020 */ uint32_t field_020;                 /* ctor: 0xffffffff */
    /* 0x024 */ uint8_t _pad_024[4];                /* explicit padding */
    /* 0x028 */ void *dat_ptr_028;                  /* ctor: &DAT_1407496e0 */
    /* 0x030 */ uint32_t field_030;                 /* ctor: 0 */
    /* 0x034 */ uint64_t mode;                      /* ctor: 5 */
    /* 0x03C */ float rate;                         /* ctor: 0x3f800000 = 1.0f */
    /* 0x040 */ uint64_t anim_entry;                /* ctor: 0, set to table entry ptr */
    /* 0x048 */ uint8_t _gap_048[0x30];             /* gap to 0x78 */
    /* 0x078 */ void **field_078_pptr;              /* r in _Open, dereferenced */
    /* 0x080 */ uint64_t field_080;                 /* rw in _Open, zeroed then set */
    /* 0x088 */ uint8_t _gap_088[0x2C];             /* gap to 0xB4 */
    /* 0x0B4 */ uint64_t open_flag;                 /* w in _Open, set to 1 */
    /* 0x0BC */ uint8_t _gap_0bc[0x184];            /* gap to 0x240 */
} ccUiOpenCloseCtrl;

static_assert(offsetof(ccUiOpenCloseCtrl, vtable) == 0x000, "ccUiOpenCloseCtrl.vtable");
static_assert(offsetof(ccUiOpenCloseCtrl, count) == 0x008, "ccUiOpenCloseCtrl.count");
static_assert(offsetof(ccUiOpenCloseCtrl, dat_ptr_018) == 0x018, "ccUiOpenCloseCtrl.dat_ptr_018");
static_assert(offsetof(ccUiOpenCloseCtrl, field_020) == 0x020, "ccUiOpenCloseCtrl.field_020");
static_assert(offsetof(ccUiOpenCloseCtrl, dat_ptr_028) == 0x028, "ccUiOpenCloseCtrl.dat_ptr_028");
static_assert(offsetof(ccUiOpenCloseCtrl, field_030) == 0x030, "ccUiOpenCloseCtrl.field_030");
static_assert(offsetof(ccUiOpenCloseCtrl, mode) == 0x034, "ccUiOpenCloseCtrl.mode");
static_assert(offsetof(ccUiOpenCloseCtrl, rate) == 0x03C, "ccUiOpenCloseCtrl.rate");
static_assert(offsetof(ccUiOpenCloseCtrl, anim_entry) == 0x040, "ccUiOpenCloseCtrl.anim_entry");
static_assert(offsetof(ccUiOpenCloseCtrl, field_078_pptr) == 0x078, "ccUiOpenCloseCtrl.field_078_pptr");
static_assert(offsetof(ccUiOpenCloseCtrl, field_080) == 0x080, "ccUiOpenCloseCtrl.field_080");
static_assert(offsetof(ccUiOpenCloseCtrl, open_flag) == 0x0B4, "ccUiOpenCloseCtrl.open_flag");

/* ---- ccUiLayoutParts ----
 * No constructor found in s1 symbols. state_surface found one field:
 * +0x34 (int r in SetAttach). 14 methods present but most use byte-cast access patterns.
 * Size unknown, >= 0x38.
 */
typedef struct __attribute__((packed)) ccUiLayoutParts {
    /* 0x00 */ uint8_t _unknown[0x34];      /* no ctor/vtable evidence yet */
    /* 0x34 */ int32_t attach_index;        /* r in SetAttach */
} ccUiLayoutParts;

static_assert(offsetof(ccUiLayoutParts, attach_index) == 0x34, "ccUiLayoutParts.attach_index");

/* ---- ccUiLoader ----
 * Only 3 methods in s1: GetLoadFileNum, GetLoadProgress, GetUiLoader.
 * state_surface returned 0 fields (all byte-cast or indirect).
 * Not enough evidence for struct layout; listed in report as skipped.
 */

/* ---- ccUiPartsParamBinary ----
 * Only 1 method in s1: EndianConvert.
 * Not enough evidence for struct layout; listed in report as skipped.
 */

#endif /* CMN14_H */