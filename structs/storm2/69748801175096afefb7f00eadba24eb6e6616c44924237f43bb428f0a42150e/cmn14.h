/* cmn14.h — NARUTO STORM 2 PC (NSUNS2.exe, build s2)
 * Struct group: ccUiLayoutParts, ccUiLoader, ccUiManager, ccUiObject,
 *               ccUiObjectContainer, ccUiOpenCloseCtrl, ccUiPartsParamBinary,
 *               ccUiScreenInfo
 *
 * All layouts INFERRED from static decompilation of s2 x64 binary.
 * Sizes are UNPROVEN unless noted; no sizeof asserts on incomplete structs.
 * Field names from s2 symbols/strings only (own-game rule).
 * Rollback tags: SIM = simulation state, PRES = presentation-only, UNKNOWN.
 */
#ifndef CMN14_H
#define CMN14_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- ccUiScreenInfo ----
 * Constructor @0x6781D0 writes vtable at +0x0, Vector2 at +0xC, uint flag at +0x8.
 * Size unknown, >= 0x14.
 */
typedef struct __attribute__((packed)) ccUiScreenInfo {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint32_t is_wide;       /* (uint)(1280.0 < screen_width), ctor */
    /* 0x0C */ float scale_x;          /* Vector2::one() x component */
    /* 0x10 */ float scale_y;          /* Vector2::one() y component */
} ccUiScreenInfo;

static_assert(offsetof(ccUiScreenInfo, vtable) == 0x00, "ccUiScreenInfo.vtable");
static_assert(offsetof(ccUiScreenInfo, is_wide) == 0x08, "ccUiScreenInfo.is_wide");
static_assert(offsetof(ccUiScreenInfo, scale_x) == 0x0C, "ccUiScreenInfo.scale_x");
static_assert(offsetof(ccUiScreenInfo, scale_y) == 0x10, "ccUiScreenInfo.scale_y");

/* ---- ccUiManager ----
 * Constructor @0x678280. Inherits BlockAllocator base (FUN_1405858f0 init).
 * Loop initializes 10 entries starting at param_1+3 (+0x18), each 5 qwords (0x28 bytes).
 * 10*0x28 = 0x190, ending at +0x1A8. Then param_1[0x35]=+0x1A8, [0x36]=+0x1B0, [0x37]=+0x1B8.
 * Vector2 at +0x1C4, uint at +0x1C0. Last access +0x1C8 (float).
 * Size unknown, >= 0x1CC.
 */
typedef struct __attribute__((packed)) ccUiManager {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint8_t _base_block_allocator[0x1A0]; /* BlockAllocator base, layout not reconstructed */
    /* 0x1A8 */ uint64_t field_1a8;     /* rw in Initialize/ctor */
    /* 0x1B0 */ uint64_t field_1b0;     /* w in ctor, zeroed */
    /* 0x1B8 */ void *field_1b8_vtable; /* w in ctor, PTR_FUN_1408918e8 */
    /* 0x1C0 */ uint32_t is_wide;       /* w in ctor, (uint)(1280.0 < ...) */
    /* 0x1C4 */ float vec_scale_x;      /* Vector2::one() via FUN_1405805e0 */
    /* 0x1C8 */ float vec_scale_y;      /* Vector2::one() */
} ccUiManager;

static_assert(offsetof(ccUiManager, vtable) == 0x000, "ccUiManager.vtable");
static_assert(offsetof(ccUiManager, field_1a8) == 0x1A8, "ccUiManager.field_1a8");
static_assert(offsetof(ccUiManager, field_1b0) == 0x1B0, "ccUiManager.field_1b0");
static_assert(offsetof(ccUiManager, field_1b8_vtable) == 0x1B8, "ccUiManager.field_1b8_vtable");
static_assert(offsetof(ccUiManager, is_wide) == 0x1C0, "ccUiManager.is_wide");
static_assert(offsetof(ccUiManager, vec_scale_x) == 0x1C4, "ccUiManager.vec_scale_x");
static_assert(offsetof(ccUiManager, vec_scale_y) == 0x1C8, "ccUiManager.vec_scale_y");

/* ---- ccUiObject ----
 * Constructor @0x64ACB0(longlong *param_1, undefined4 param_2, undefined4 param_3).
 * Inherits BlockAllocator base (FUN_140585940 init).
 * param_1+3 = +0x18 (FUN_1401afc0c), param_1+10 = +0x50 (FUN_1401afc0c).
 * param_1[0x11]=+0x88, [0x12]=+0x90, [0x13]=+0x98, byte at +0x9C,
 * [0x14]=+0xA0, [0x15]=+0xA8 (param_2), dword at +0xAC (param_3),
 * [0x16]=+0xB0, dword at +0xB4 (=1), [0x17]=+0xB8 (=1).
 * Virtual dispatch: vtable+0x08 call, vtable+0x10 call.
 * state_surface: +0x3C0 read (virtual call site).
 * Size unknown, >= 0x3C8.
 */
typedef struct __attribute__((packed)) ccUiObject {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint8_t _base_block_allocator[0x80]; /* BlockAllocator base */
    /* 0x088 */ uint64_t field_088;     /* w in ctor, zeroed */
    /* 0x090 */ uint32_t field_090;     /* w in ctor, zeroed */
    /* 0x094 */ uint8_t _pad_094[4];
    /* 0x098 */ uint32_t field_098;     /* w in ctor, zeroed */
    /* 0x09C */ uint8_t field_09c;      /* w in ctor, byte zeroed */
    /* 0x09D */ uint8_t _pad_09d[3];
    /* 0x0A0 */ uint64_t field_0a0;     /* w in ctor, zeroed */
    /* 0x0A8 */ uint32_t type_id;       /* w in ctor, param_2 */
    /* 0x0AC */ uint32_t field_0ac;     /* w in ctor, param_3 */
    /* 0x0B0 */ uint32_t field_0b0;     /* w in ctor, zeroed */
    /* 0x0B4 */ uint32_t enable_flag;   /* rw in Ctrl/ctor, init 1 */
    /* 0x0B8 */ uint32_t field_0b8;     /* w in ctor, init 1 */
    /* 0x0BC */ uint8_t _gap_0bc[0x304]; /* gap to 0x3C0 virtual call site */
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
 * Constructor @0x669250. Inherits BlockAllocator base (FUN_1405858f0 init).
 * Calls FUN_14034b370(param_1 + 3) = +0x18 sub-init.
 * state_surface: vtable dispatch reads +0x80 in Add/Remove/Release/ReleaseAll.
 * Size unknown, >= 0x88.
 */
typedef struct __attribute__((packed)) ccUiObjectContainer {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _base_block_allocator[0x78]; /* BlockAllocator base */
    /* 0x80 */ void *_vfunc_ptr; /* read via (*param_1 + 0x10) dispatch */
} ccUiObjectContainer;

static_assert(offsetof(ccUiObjectContainer, vtable) == 0x00, "ccUiObjectContainer.vtable");
static_assert(offsetof(ccUiObjectContainer, _vfunc_ptr) == 0x80, "ccUiObjectContainer._vfunc_ptr");

/* ---- ccUiOpenCloseCtrl ----
 * Constructor @0x678860. Does NOT inherit BlockAllocator (no GetBlockManager call).
 * param_1[1]=+0x08 (=4), param_1[2]=+0x10 (DAT ptr), param_1[3]=+0x18 (=0),
 * *(uint*)(param_1+5)=+0x28 (=0xffffffff), *(uint*)(param_1+6)=+0x30 (=0),
 * *(qword*)(param_1+0x34)=+0x34 (=5), *(float*)(param_1+0x3c)=+0x3C (=1.0f),
 * param_1[4]=+0x20 (=0, then set to table entry ptr).
 * state_surface: +0x78 r, +0x80 rw, +0x88 r, +0xB4 w, +0x240 r.
 * Size unknown, >= 0x248.
 */
typedef struct __attribute__((packed)) ccUiOpenCloseCtrl {
    /* 0x000 */ void *vtable;
    /* 0x008 */ uint64_t count;         /* ctor sets to 4 */
    /* 0x010 */ void *dat_ptr_010;      /* ctor: &DAT_1408a0db0 */
    /* 0x018 */ uint64_t field_018;     /* ctor: 0 */
    /* 0x020 */ uint64_t anim_entry;    /* ctor: 0, then set to table entry ptr */
    /* 0x028 */ uint32_t field_028;     /* ctor: 0xffffffff */
    /* 0x02C */ uint8_t _pad_02c[4];
    /* 0x030 */ uint32_t field_030;     /* ctor: 0 */
    /* 0x034 */ uint64_t mode;          /* ctor: 5 */
    /* 0x03C */ float rate;             /* ctor: 0x3f800000 = 1.0f */
    /* 0x040 */ uint8_t _gap_040[0x38]; /* gap to 0x78 */
    /* 0x078 */ void **field_078_pptr;  /* r in _Open, dereferenced */
    /* 0x080 */ uint64_t field_080;     /* rw in _Open, zeroed then set */
    /* 0x088 */ uint8_t _gap_088[0x2C]; /* gap to 0xB4 */
    /* 0x0B4 */ uint64_t open_flag;     /* w in _Open, set to 1 */
    /* 0x0BC */ uint8_t _gap_0bc[0x184]; /* gap to 0x240 */
} ccUiOpenCloseCtrl;

static_assert(offsetof(ccUiOpenCloseCtrl, vtable) == 0x000, "ccUiOpenCloseCtrl.vtable");
static_assert(offsetof(ccUiOpenCloseCtrl, count) == 0x008, "ccUiOpenCloseCtrl.count");
static_assert(offsetof(ccUiOpenCloseCtrl, dat_ptr_010) == 0x010, "ccUiOpenCloseCtrl.dat_ptr_010");
static_assert(offsetof(ccUiOpenCloseCtrl, field_018) == 0x018, "ccUiOpenCloseCtrl.field_018");
static_assert(offsetof(ccUiOpenCloseCtrl, anim_entry) == 0x020, "ccUiOpenCloseCtrl.anim_entry");
static_assert(offsetof(ccUiOpenCloseCtrl, field_028) == 0x028, "ccUiOpenCloseCtrl.field_028");
static_assert(offsetof(ccUiOpenCloseCtrl, field_030) == 0x030, "ccUiOpenCloseCtrl.field_030");
static_assert(offsetof(ccUiOpenCloseCtrl, mode) == 0x034, "ccUiOpenCloseCtrl.mode");
static_assert(offsetof(ccUiOpenCloseCtrl, rate) == 0x03C, "ccUiOpenCloseCtrl.rate");
static_assert(offsetof(ccUiOpenCloseCtrl, field_078_pptr) == 0x078, "ccUiOpenCloseCtrl.field_078_pptr");
static_assert(offsetof(ccUiOpenCloseCtrl, field_080) == 0x080, "ccUiOpenCloseCtrl.field_080");
static_assert(offsetof(ccUiOpenCloseCtrl, open_flag) == 0x0B4, "ccUiOpenCloseCtrl.open_flag");

/* ---- ccUiLayoutParts ----
 * No constructor found in s2 symbols. state_surface found one field:
 * +0x34 (int r in SetAttach). Methods present but most use byte-cast access patterns.
 * Size unknown, >= 0x38.
 */
typedef struct __attribute__((packed)) ccUiLayoutParts {
    /* 0x00 */ uint8_t _unknown[0x34]; /* no ctor/vtable evidence yet */
    /* 0x34 */ int32_t attach_index;   /* r in SetAttach */
} ccUiLayoutParts;

static_assert(offsetof(ccUiLayoutParts, attach_index) == 0x34, "ccUiLayoutParts.attach_index");

/* ---- ccUiPartsParamBinary ----
 * Single method EndianConvert @0x68C790. state_surface found 3 fields:
 * +0x2C (rw, _byteswap_ulong), +0x30 (rw), +0x34 (rw).
 * Size unknown, >= 0x38.
 */
typedef struct __attribute__((packed)) ccUiPartsParamBinary {
    /* 0x00 */ uint8_t _unknown[0x2C]; /* no ctor evidence */
    /* 0x2C */ uint32_t field_02c;     /* rw in EndianConvert, byteswap */
    /* 0x30 */ uint32_t field_030;     /* rw in EndianConvert, byteswap */
    /* 0x34 */ uint32_t field_034;     /* rw in EndianConvert, byteswap */
} ccUiPartsParamBinary;

static_assert(offsetof(ccUiPartsParamBinary, field_02c) == 0x2C, "ccUiPartsParamBinary.field_02c");
static_assert(offsetof(ccUiPartsParamBinary, field_030) == 0x30, "ccUiPartsParamBinary.field_030");
static_assert(offsetof(ccUiPartsParamBinary, field_034) == 0x34, "ccUiPartsParamBinary.field_034");

/* ---- ccUiLoader ----
 * ccUiLoader: no instance state.
 * All 6 methods in s2 are static/utility functions operating on global data
 * (DAT_140ab5be8 and related globals), not on a per-instance object.
 * Evidence (all INFERRED from static decompilation):
 *   Load          @0x666390  void -> void
 *   Unload        @0x6663C0  void -> void
 *   IsLoaded      @0x6663F0  void -> void
 *   GetLoadProgress @0x666450  void -> ulonglong
 *   GetLoadFileNum  @0x6664C0  void -> undefined8
 *   GetUiLoader     @0x666560  char* -> undefined8 (string name lookup via DAT_140ab5be8)
 * No constructor, no vtable, no operator new callsite found in s2.
 * state_surface returned 0 fields across all 6 seeds.
 */

/* (ccUiLoader coverage verified 2026-10-19) */
#endif /* CMN14_H */