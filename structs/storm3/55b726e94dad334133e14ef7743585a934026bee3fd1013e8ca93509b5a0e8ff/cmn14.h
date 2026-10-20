/* cmn14.h — NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, build s3)
 * Struct group: ccUiLayoutParts, ccUiLoader, ccUiManager, ccUiObject,
 *               ccUiObjectContainer, ccUiOpenCloseCtrl, ccUiPartsParamBinary,
 *               ccUiScreenInfo
 *
 * All layouts INFERRED from static decompilation of s3 x64 binary.
 * Sizes are UNPROVEN unless noted; no sizeof asserts on incomplete structs.
 * Field names carried from s2 where offsets match; re-verified in s3 code.
 * Rollback tags: SIM = simulation state, PRES = presentation-only, UNKNOWN.
 */
#ifndef CMN14_H
#define CMN14_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- ccUiScreenInfo ----
 * Constructor @0x778100 writes vtable PTR_FUN_1409daf00 at +0x0,
 * Vector2 at +0xC via FUN_140483d40, uint is_wide at +0x8.
 * Size unknown, >= 0x14.
 */
typedef struct __attribute__((packed)) ccUiScreenInfo {
    /* 0x00 */ void *vtable;              /* PTR_FUN_1409daf00 */
    /* 0x08 */ uint32_t is_wide;          /* (uint)(1280.0 < screen_width) */
    /* 0x0C */ float scale_x;             /* Vector2::one() x */
    /* 0x10 */ float scale_y;             /* Vector2::one() y */
} ccUiScreenInfo;

static_assert(offsetof(ccUiScreenInfo, vtable)   == 0x00, "ccUiScreenInfo.vtable");
static_assert(offsetof(ccUiScreenInfo, is_wide)  == 0x08, "ccUiScreenInfo.is_wide");
static_assert(offsetof(ccUiScreenInfo, scale_x)  == 0x0C, "ccUiScreenInfo.scale_x");
static_assert(offsetof(ccUiScreenInfo, scale_y)  == 0x10, "ccUiScreenInfo.scale_y");

/* ---- ccUiManager ----
 * Constructor @0x7781B0. Inherits BlockAllocator base (FUN_140684bc0 init).
 * Loop initializes 10 entries starting at param_1+3 (+0x18), each 5 qwords (0x28 bytes).
 * 10*0x28 = 0x190, ending at +0x1A8. Then param_1[0x35]=+0x1A8, [0x36]=+0x1B0, [0x37]=+0x1B8.
 * Vector2 at +0x1C4 via FUN_140483d40, is_wide at +0x1C0.
 * Vtable: PTR_FUN_1409ee390 (main), PTR_FUN_1409ec308 (loop sub-entries),
 *         PTR_FUN_1409daf00 (field_1b8_vtable).
 * Size unknown, >= 0x1CC.
 */
typedef struct __attribute__((packed)) ccUiManager {
    /* 0x000 */ void *vtable;              /* PTR_FUN_1409ee390 */
    /* 0x008 */ uint8_t _base_block_allocator[0x1A0]; /* BlockAllocator base */
    /* 0x1A8 */ uint64_t field_1a8;        /* rw in Initialize/ctor */
    /* 0x1B0 */ uint64_t field_1b0;        /* w in ctor, zeroed */
    /* 0x1B8 */ void *field_1b8_vtable;    /* PTR_FUN_1409daf00 */
    /* 0x1C0 */ uint32_t is_wide;          /* (uint)(1280.0 < ...) */
    /* 0x1C4 */ float vec_scale_x;         /* Vector2::one() x */
    /* 0x1C8 */ float vec_scale_y;         /* Vector2::one() y */
} ccUiManager;

static_assert(offsetof(ccUiManager, vtable)           == 0x000, "ccUiManager.vtable");
static_assert(offsetof(ccUiManager, field_1a8)        == 0x1A8, "ccUiManager.field_1a8");
static_assert(offsetof(ccUiManager, field_1b0)        == 0x1B0, "ccUiManager.field_1b0");
static_assert(offsetof(ccUiManager, field_1b8_vtable) == 0x1B8, "ccUiManager.field_1b8_vtable");
static_assert(offsetof(ccUiManager, is_wide)          == 0x1C0, "ccUiManager.is_wide");
static_assert(offsetof(ccUiManager, vec_scale_x)      == 0x1C4, "ccUiManager.vec_scale_x");
static_assert(offsetof(ccUiManager, vec_scale_y)      == 0x1C8, "ccUiManager.vec_scale_y");

/* ---- ccUiObject ----
 * Constructor @0x740EA0(longlong *param_1, undefined4 param_2, undefined4 param_3).
 * Inherits BlockAllocator base (FUN_140684c10 init).
 * FUN_140191324(param_1+3)=+0x18, FUN_140191324(param_1+10)=+0x50.
 * param_1[0x11]=+0x88, [0x12]=+0x90, [0x13]=+0x98, byte at +0x9C,
 * [0x14]=+0xA0, dword at +0xA8 (param_2=type_id), dword at +0xAC (param_3),
 * [0x16]=+0xB0, dword at +0xB4 (=1, enable_flag), dword at +0xB8 (=1).
 * Virtual dispatch: vtable+0x08 call, vtable+0x10 call.
 * state_surface: virtual call site reads +0x3C0.
 * Vtable: PTR_FUN_1409ebd30.
 * Size unknown, >= 0x3C8.
 */
typedef struct __attribute__((packed)) ccUiObject {
    /* 0x000 */ void *vtable;              /* PTR_FUN_1409ebd30 */
    /* 0x008 */ uint8_t _base_block_allocator[0x80]; /* BlockAllocator base */
    /* 0x088 */ uint64_t field_088;        /* w in ctor, zeroed */
    /* 0x090 */ uint32_t field_090;        /* w in ctor, zeroed */
    /* 0x094 */ uint8_t _pad_094[4];
    /* 0x098 */ uint32_t field_098;        /* w in ctor, zeroed */
    /* 0x09C */ uint8_t field_09c;         /* w in ctor, byte zeroed */
    /* 0x09D */ uint8_t _pad_09d[3];
    /* 0x0A0 */ uint64_t field_0a0;        /* w in ctor, zeroed */
    /* 0x0A8 */ uint32_t type_id;          /* w in ctor, param_2 */
    /* 0x0AC */ uint32_t field_0ac;        /* w in ctor, param_3 */
    /* 0x0B0 */ uint32_t field_0b0;        /* w in ctor, zeroed */
    /* 0x0B4 */ uint32_t enable_flag;      /* rw in Ctrl/ctor, init 1 */
    /* 0x0B8 */ uint32_t field_0b8;        /* w in ctor, init 1 */
    /* 0x0BC */ uint8_t _gap_0bc[0x304];   /* gap to 0x3C0 virtual call site */
} ccUiObject;

static_assert(offsetof(ccUiObject, vtable)      == 0x000, "ccUiObject.vtable");
static_assert(offsetof(ccUiObject, field_088)   == 0x088, "ccUiObject.field_088");
static_assert(offsetof(ccUiObject, field_090)   == 0x090, "ccUiObject.field_090");
static_assert(offsetof(ccUiObject, field_098)   == 0x098, "ccUiObject.field_098");
static_assert(offsetof(ccUiObject, field_09c)   == 0x09C, "ccUiObject.field_09c");
static_assert(offsetof(ccUiObject, field_0a0)   == 0x0A0, "ccUiObject.field_0a0");
static_assert(offsetof(ccUiObject, type_id)     == 0x0A8, "ccUiObject.type_id");
static_assert(offsetof(ccUiObject, field_0ac)   == 0x0AC, "ccUiObject.field_0ac");
static_assert(offsetof(ccUiObject, field_0b0)   == 0x0B0, "ccUiObject.field_0b0");
static_assert(offsetof(ccUiObject, enable_flag) == 0x0B4, "ccUiObject.enable_flag");
static_assert(offsetof(ccUiObject, field_0b8)   == 0x0B8, "ccUiObject.field_0b8");

/* ---- ccUiObjectContainer ----
 * Constructor @0x767700. Inherits BlockAllocator base (FUN_140684bc0 init).
 * Calls FUN_140767ad0(param_1+3) = +0x18 sub-init.
 * state_surface: vtable dispatch reads +0x80 in Add/Remove/Release/ReleaseAll.
 * Vtable: PTR_FUN_1409edba8.
 * Size unknown, >= 0x88.
 */
typedef struct __attribute__((packed)) ccUiObjectContainer {
    /* 0x00 */ void *vtable;              /* PTR_FUN_1409edba8 */
    /* 0x08 */ uint8_t _base_block_allocator[0x78]; /* BlockAllocator base */
    /* 0x80 */ void *_vfunc_ptr;          /* read via (*param_1 + 0x10) dispatch */
} ccUiObjectContainer;

static_assert(offsetof(ccUiObjectContainer, vtable)      == 0x00, "ccUiObjectContainer.vtable");
static_assert(offsetof(ccUiObjectContainer, _vfunc_ptr)  == 0x80, "ccUiObjectContainer._vfunc_ptr");

/* ---- ccUiOpenCloseCtrl ----
 * Constructor @0x73D400. Does NOT inherit BlockAllocator (no GetBlockManager call).
 * param_1[1]=+0x08 (=4), param_1[2]=+0x10 (DAT_1409ebac0 ptr), param_1[3]=+0x18 (=0),
 * *(uint*)(param_1+5)=+0x28 (=0xffffffff), *(uint*)(param_1+6)=+0x30 (=0),
 * *(qword*)(param_1+0x34)=+0x34 (=5), *(float*)(param_1+0x3c)=+0x3C (=1.0f),
 * param_1[4]=+0x20 (=0, then set to table entry ptr).
 * state_surface: +0x78 r (dereferenced ptr), +0x80 rw, +0x88 r, +0xB4 w,
 *                vtable dispatches at +0x240/+0x280/+0x340.
 * Vtable: PTR_FUN_1408b4c50.
 * Size unknown, >= 0x348 (last dispatch at +0x340 implies 8-byte slot).
 */
typedef struct __attribute__((packed)) ccUiOpenCloseCtrl {
    /* 0x000 */ void *vtable;              /* PTR_FUN_1408b4c50 */
    /* 0x008 */ uint64_t count;            /* ctor sets to 4 */
    /* 0x010 */ void *dat_ptr_010;         /* ctor: &DAT_1409ebac0 */
    /* 0x018 */ uint64_t field_018;        /* ctor: 0 */
    /* 0x020 */ uint64_t anim_entry;       /* ctor: 0, then table entry ptr */
    /* 0x028 */ uint32_t field_028;        /* ctor: 0xffffffff */
    /* 0x02C */ uint8_t _pad_02c[4];
    /* 0x030 */ uint32_t field_030;        /* ctor: 0 */
    /* 0x034 */ uint64_t mode;             /* ctor: 5 */
    /* 0x03C */ float rate;                /* ctor: 0x3f800000 = 1.0f */
    /* 0x040 */ uint8_t _gap_040[0x38];    /* gap to 0x78 */
    /* 0x078 */ void **field_078_pptr;     /* r in _Open, dereferenced */
    /* 0x080 */ uint64_t field_080;        /* rw in _Open, zeroed then set */
    /* 0x088 */ uint8_t _gap_088[0x2C];    /* gap to 0xB4 */
    /* 0x0B4 */ uint64_t open_flag;        /* w in _Open, set to 1 */
    /* 0x0BC */ uint8_t _gap_0bc[0x284];   /* gap to 0x340 last vtable dispatch */
} ccUiOpenCloseCtrl;

static_assert(offsetof(ccUiOpenCloseCtrl, vtable)        == 0x000, "ccUiOpenCloseCtrl.vtable");
static_assert(offsetof(ccUiOpenCloseCtrl, count)         == 0x008, "ccUiOpenCloseCtrl.count");
static_assert(offsetof(ccUiOpenCloseCtrl, dat_ptr_010)   == 0x010, "ccUiOpenCloseCtrl.dat_ptr_010");
static_assert(offsetof(ccUiOpenCloseCtrl, field_018)     == 0x018, "ccUiOpenCloseCtrl.field_018");
static_assert(offsetof(ccUiOpenCloseCtrl, anim_entry)    == 0x020, "ccUiOpenCloseCtrl.anim_entry");
static_assert(offsetof(ccUiOpenCloseCtrl, field_028)     == 0x028, "ccUiOpenCloseCtrl.field_028");
static_assert(offsetof(ccUiOpenCloseCtrl, field_030)     == 0x030, "ccUiOpenCloseCtrl.field_030");
static_assert(offsetof(ccUiOpenCloseCtrl, mode)          == 0x034, "ccUiOpenCloseCtrl.mode");
static_assert(offsetof(ccUiOpenCloseCtrl, rate)          == 0x03C, "ccUiOpenCloseCtrl.rate");
static_assert(offsetof(ccUiOpenCloseCtrl, field_078_pptr)== 0x078, "ccUiOpenCloseCtrl.field_078_pptr");
static_assert(offsetof(ccUiOpenCloseCtrl, field_080)     == 0x080, "ccUiOpenCloseCtrl.field_080");
static_assert(offsetof(ccUiOpenCloseCtrl, open_flag)     == 0x0B4, "ccUiOpenCloseCtrl.open_flag");

/* ---- ccUiLayoutParts ----
 * No constructor found in s3 symbols. state_surface found one field:
 * +0x34 (int r in SetAttach). Methods present but most use byte-cast access.
 * Size unknown, >= 0x38.
 */
typedef struct __attribute__((packed)) ccUiLayoutParts {
    /* 0x00 */ uint8_t _unknown[0x34];    /* no ctor/vtable evidence yet */
    /* 0x34 */ int32_t attach_index;      /* r in SetAttach */
} ccUiLayoutParts;

static_assert(offsetof(ccUiLayoutParts, attach_index) == 0x34, "ccUiLayoutParts.attach_index");

/* ---- ccUiPartsParamBinary ----
 * Single method EndianConvert @0x613A94. state_surface in s2 found 3 fields:
 * +0x2C (rw, _byteswap_ulong), +0x30 (rw), +0x34 (rw).
 * Only 1 method in s3 (< 3 threshold); layout carried from s2, not re-verified.
 * Size unknown, >= 0x38.
 */
typedef struct __attribute__((packed)) ccUiPartsParamBinary {
    /* 0x00 */ uint8_t _unknown[0x2C];    /* no ctor evidence */
    /* 0x2C */ uint32_t field_02c;        /* rw in EndianConvert, byteswap */
    /* 0x30 */ uint32_t field_030;        /* rw in EndianConvert, byteswap */
    /* 0x34 */ uint32_t field_034;        /* rw in EndianConvert, byteswap */
} ccUiPartsParamBinary;

static_assert(offsetof(ccUiPartsParamBinary, field_02c) == 0x2C, "ccUiPartsParamBinary.field_02c");
static_assert(offsetof(ccUiPartsParamBinary, field_030) == 0x30, "ccUiPartsParamBinary.field_030");
static_assert(offsetof(ccUiPartsParamBinary, field_034) == 0x34, "ccUiPartsParamBinary.field_034");

/* ---- ccUiLoader ----
 * ccUiLoader: no instance state.
 * All 6 methods are static/singleton accessors operating on global data:
 *   Load @0x77FC40 void(void)
 *   Unload @0x77FC70 void(void)
 *   IsLoaded @0x77FCA0 void(void)
 *   GetLoadProgress @0x77FD00 undefined8(void)
 *   GetLoadFileNum @0x77FD70 undefined8(void)
 *   GetUiLoader @0x77FE10 undefined8(char *key) — looks up global std::map
 *     at DAT_140c7da58 by string key; returns *(node+0x40). No this-pointer.
 * state_surface returned 0 fields across all 6 seeds. No ctor, no vtable,
 * no allocation site found. INFERRED from static decompilation only.
 */

#endif /* CMN14_H */