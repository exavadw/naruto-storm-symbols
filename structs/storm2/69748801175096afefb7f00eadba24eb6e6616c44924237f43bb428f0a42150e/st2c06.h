/* st2c06.h — Story CUTSCENE / EVENT playback structs for s2 (NSUNS2.exe)
 * Build: s2  sha 697488011750  image base 0x140000000
 * Group: ccUiCommonScriptObject, ccUiMessage, ccUiPuppetDemoSelect,
 *        ccUiSecretFactorCaption, ccUiSelectCaptionWindow, ccUiTaskMessage,
 *        ccWindowTalk, ccWindowTalkEx, ccWindowTalkFix, ccWindowTalkHandler,
 *        ccWindowTalkManager, mmScriptNodeXML
 *
 * All fields INFERRED from static analysis (state_surface + ctor decompile).
 * Sizes proven from LoadTh() first arg or last field offset; unproven sizes
 * are noted with "size unknown, >= 0xN" and no sizeof assert.
 * Own-game names only (s2 = ns2:: namespace). PC offsets only.
 */

#ifndef ST2C06_H
#define ST2C06_H

#include <stdint.h>
#include <stddef.h>

#include <assert.h>
/* Forward declarations for embedded subobjects whose layout is not in this group */
typedef struct Nucc_Memory_BlockAllocator {
    uint8_t data[0x38]; /* placeholder: BlockAllocator internal state */
} Nucc_Memory_BlockAllocator;

typedef struct Nucc_Vector2 {
    float x;
    float y;
} Nucc_Vector2;

typedef struct cmnXml {
    uint8_t data[0x20]; /* placeholder */
} cmnXml;

typedef struct btBoxBoxDetector {
    uint8_t data[0x10]; /* placeholder */
} btBoxBoxDetector;

typedef struct nuccPostEffectDOF_CameraParam {
    uint8_t data[0x28]; /* placeholder */
} nuccPostEffectDOF_CameraParam;

typedef struct ccBuildUniqueId {
    uint8_t data[0x34]; /* placeholder: ends at offset 0x60 based on ctor */
} ccBuildUniqueId;

typedef struct ccFileLoadListForUi {
    uint8_t data[0x60]; /* placeholder */
} ccFileLoadListForUi;

typedef struct ccScriptUiPair {
    uint8_t data[0x10]; /* placeholder */
} ccScriptUiPair;

/* ========================================================================
 * ccUiCommonScriptObject
 * Vtable: PTR_FUN_140853a90 (VA 0x140853a90)
 * Base: ccUiCancelDraw (constructed at offset 0x00 before vtable write)
 * Size: >= 0x118 (last surfaced field at 0x110, sz=None means access beyond)
 *       Proven from ctor: 3 BlockAllocators at +0x40,+0x78,+0xB0; fields to 0x110
 * Fields: 16 surfaced
 * Rollback: mostly PRES (script/UI state)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccUiCommonScriptObject {
    /* 0x00 */ void *vtable;                          /* PTR_FUN_140853a90 */
    /* 0x08 */ uint8_t _base_ccUiCancelDraw[0x50];    /* base class (inferred) */
    /* 0x58 */ uint64_t field_0x58;                   /* surfaced, rw */
    /* 0x60 */ uint64_t field_0x60;                   /* surfaced, rw */
    /* 0x68 */ uint8_t _pad_0x68[0x10];
    /* 0x78 */ uint8_t field_0x78;                    /* surfaced, sz=1 */
    /* 0x79 */ uint8_t _pad_0x79[0x0F];
    /* 0x88 */ uint64_t field_0x88;                   /* surfaced */
    /* 0x90 */ uint64_t field_0x90;                   /* surfaced */
    /* 0x98 */ uint64_t field_0x98;                   /* surfaced */
    /* 0xA0 */ uint8_t _pad_0xA0[0x10];
    /* 0xB0 */ uint8_t field_0xB0;                    /* surfaced, sz=1 */
    /* 0xB1 */ uint8_t _pad_0xB1[0x0F];
    /* 0xC0 */ uint64_t field_0xC0;                   /* surfaced */
    /* 0xC8 */ uint64_t field_0xC8;                   /* surfaced */
    /* 0xD0 */ uint64_t field_0xD0;                   /* surfaced */
    /* 0xD8 */ uint8_t _pad_0xD8[0x10];
    /* 0xE8 */ uint64_t field_0xE8;                   /* surfaced */
    /* 0xF0 */ uint32_t field_0xF0;                   /* surfaced, sz=4 */
    /* 0xF4 */ uint8_t _pad_0xF4[0x04];
    /* 0xF8 */ uint64_t field_0xF8;                   /* surfaced */
    /* 0x100 */ uint64_t field_0x100;                 /* surfaced */
    /* 0x108 */ uint64_t field_0x108;                 /* surfaced */
    /* 0x110 */ uint8_t field_0x110[0x08];            /* surfaced, sz=None → min 8 bytes access */
} ccUiCommonScriptObject;

static_assert(offsetof(ccUiCommonScriptObject, vtable)     == 0x000, "ccUiCommonScriptObject.vtable");
static_assert(offsetof(ccUiCommonScriptObject, field_0x58) == 0x058, "ccUiCommonScriptObject.field_0x58");
static_assert(offsetof(ccUiCommonScriptObject, field_0x60) == 0x060, "ccUiCommonScriptObject.field_0x60");
static_assert(offsetof(ccUiCommonScriptObject, field_0x78) == 0x078, "ccUiCommonScriptObject.field_0x78");
static_assert(offsetof(ccUiCommonScriptObject, field_0x88) == 0x088, "ccUiCommonScriptObject.field_0x88");
static_assert(offsetof(ccUiCommonScriptObject, field_0x90) == 0x090, "ccUiCommonScriptObject.field_0x90");
static_assert(offsetof(ccUiCommonScriptObject, field_0x98) == 0x098, "ccUiCommonScriptObject.field_0x98");
static_assert(offsetof(ccUiCommonScriptObject, field_0xB0) == 0x0B0, "ccUiCommonScriptObject.field_0xB0");
static_assert(offsetof(ccUiCommonScriptObject, field_0xC0) == 0x0C0, "ccUiCommonScriptObject.field_0xC0");
static_assert(offsetof(ccUiCommonScriptObject, field_0xC8) == 0x0C8, "ccUiCommonScriptObject.field_0xC8");
static_assert(offsetof(ccUiCommonScriptObject, field_0xD0) == 0x0D0, "ccUiCommonScriptObject.field_0xD0");
static_assert(offsetof(ccUiCommonScriptObject, field_0xE8) == 0x0E8, "ccUiCommonScriptObject.field_0xE8");
static_assert(offsetof(ccUiCommonScriptObject, field_0xF0) == 0x0F0, "ccUiCommonScriptObject.field_0xF0");
static_assert(offsetof(ccUiCommonScriptObject, field_0xF8) == 0x0F8, "ccUiCommonScriptObject.field_0xF8");
static_assert(offsetof(ccUiCommonScriptObject, field_0x100)== 0x100, "ccUiCommonScriptObject.field_0x100");
static_assert(offsetof(ccUiCommonScriptObject, field_0x108)== 0x108, "ccUiCommonScriptObject.field_0x108");
static_assert(offsetof(ccUiCommonScriptObject, field_0x110)== 0x110, "ccUiCommonScriptObject.field_0x110");

/* ========================================================================
 * ccUiMessage
 * Vtable: not found (ctor at 0x1BCD2C is a lookup/factory, not a real ctor)
 * Size: unknown — 0 surfaced fields, ctor returns handle not object pointer
 * Skip: class has 4 methods but ctor is actually GetHandleByName wrapper
 * ======================================================================== */
/* No struct emitted — insufficient evidence for layout */

/* ========================================================================
 * ccUiPuppetDemoSelect
 * Vtable: PTR_FUN_14085ffb0 (VA 0x14085ffb0)
 * Base: ccUiTaskBase → ccUiObjectContainer at +0x34*8=0x1A0? No: param_1+0x34 as qword ptr
 *   Actually: ccUiObjectContainer(param_1 + 0x34) means offset 0x34*sizeof(qword)=0x1A0?
 *   No — param_1 is undefined8*, so param_1+0x34 = byte offset 0x34*8 = 0x1A0. But that's huge.
 *   Re-check: ctor says ccUiObjectContainer::ccUiObjectContainer(param_1 + 0x34) where param_1 is undefined8*.
 *   So byte offset = 0x34 * 8 = 0x1A0. But surfaced fields start at 0x58 which is before 0x1A0.
 *   This means ccUiTaskBase is the base at offset 0, and ccUiObjectContainer is embedded at 0x1A0.
 *   Wait — re-read: param_1[0x3c] = 0 means byte 0x3c*8=0x1E0. That matches surfaced field at 0x1E0.
 *   So the object is large. Let me recalculate with proper scaling.
 *
 *   Actually the decompiler uses undefined8* param_1, so param_1[N] = byte offset N*8.
 *   ccUiObjectContainer(param_1 + 0x34) → byte offset 0x34*8 = 0x1A0
 *   But surfaced fields at 0x58, 0x60, 0x68 are BEFORE 0x1A0, meaning they belong to ccUiTaskBase base.
 *   The fields at 0x1E0+ belong to ccUiPuppetDemoSelect's own members after the embedded container.
 *
 * Size: >= 0x200 (last field at 0x1F8 + 8 bytes)
 * Allocation: LoadTh size not directly visible in factory; inferred from field extent
 * Fields: 10 surfaced
 * ======================================================================== */
typedef struct __attribute__((packed)) ccUiPuppetDemoSelect {
    /* 0x000 */ void *vtable;                         /* PTR_FUN_14085ffb0 */
    /* 0x008 */ uint8_t _base_ccUiTaskBase[0x50];     /* base class up to 0x58 */
    /* 0x058 */ uint64_t field_0x58;                  /* surfaced */
    /* 0x060 */ uint64_t field_0x60;                  /* surfaced */
    /* 0x068 */ uint64_t field_0x68;                  /* surfaced */
    /* 0x070 */ uint8_t _pad_0x070[0x28];
    /* 0x098 */ uint8_t field_0x98[0x08];             /* surfaced, sz=None */
    /* 0x0A0 */ uint8_t _pad_0x0A0[0x48];
    /* 0x0E8 */ uint8_t field_0xE8[0x08];             /* surfaced, sz=None */
    /* 0x0F0 */ uint8_t _pad_0x0F0[0xB0];
    /* 0x1A0 */ uint8_t _embedded_ccUiObjectContainer[0x40]; /* ccUiObjectContainer subobject */
    /* 0x1E0 */ uint64_t field_0x1E0;                 /* surfaced */
    /* 0x1E8 */ uint64_t field_0x1E8;                 /* surfaced */
    /* 0x1F0 */ uint64_t field_0x1F0;                 /* surfaced */
    /* 0x1F8 */ uint64_t field_0x1F8;                 /* surfaced */
} ccUiPuppetDemoSelect;

static_assert(offsetof(ccUiPuppetDemoSelect, vtable)      == 0x000, "ccUiPuppetDemoSelect.vtable");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x58)  == 0x058, "ccUiPuppetDemoSelect.field_0x58");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x60)  == 0x060, "ccUiPuppetDemoSelect.field_0x60");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x68)  == 0x068, "ccUiPuppetDemoSelect.field_0x68");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x98)  == 0x098, "ccUiPuppetDemoSelect.field_0x98");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0xE8)  == 0x0E8, "ccUiPuppetDemoSelect.field_0xE8");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x1E0) == 0x1E0, "ccUiPuppetDemoSelect.field_0x1E0");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x1E8) == 0x1E8, "ccUiPuppetDemoSelect.field_0x1E8");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x1F0) == 0x1F0, "ccUiPuppetDemoSelect.field_0x1F0");
static_assert(offsetof(ccUiPuppetDemoSelect, field_0x1F8) == 0x1F8, "ccUiPuppetDemoSelect.field_0x1F8");

/* ========================================================================
 * ccUiSecretFactorCaption
 * Vtable: PTR_FUN_1408608c0 (VA 0x1408608c0)
 * Base: none visible (no base ctor call in decompile)
 * Size: >= 0x28 (field at 0x24 sz=4, plus alignment)
 * Allocation: embedded in parent ccUiSecretFactor (not standalone heap alloc)
 * Fields: 1 surfaced
 * ======================================================================== */
typedef struct __attribute__((packed)) ccUiSecretFactorCaption {
    /* 0x00 */ void *vtable;                          /* PTR_FUN_1408608c0 */
    /* 0x08 */ uint64_t field_0x08;                   /* zeroed in ctor */
    /* 0x10 */ uint64_t field_0x10;                   /* zeroed in ctor */
    /* 0x18 */ uint64_t field_0x18;                   /* zeroed in ctor */
    /* 0x20 */ int32_t field_0x20;                    /* set to -1 in ctor */
    /* 0x24 */ int32_t field_0x24;                    /* surfaced, set to -1 in ctor */
} ccUiSecretFactorCaption;

static_assert(offsetof(ccUiSecretFactorCaption, vtable)   == 0x00, "ccUiSecretFactorCaption.vtable");
static_assert(offsetof(ccUiSecretFactorCaption, field_0x24)== 0x24, "ccUiSecretFactorCaption.field_0x24");

/* ========================================================================
 * ccUiSelectCaptionWindow
 * Vtable: PTR_FUN_140860980 (VA 0x140860980)
 * Base: ccUiTaskBase (constructed first in ctor)
 * Size: >= 0x1A0 (last surfaced field at 0x198 sz=None → at least 0x1A0)
 * Allocation: via ccFileLoadListForUi::LoadTh(0x1a0,...) in factory → PROVEN size 0x1A0
 * Fields: 32 surfaced
 * Contains: 3 BlockAllocator subobjects, 1 cmnXml subobject
 * ======================================================================== */
typedef struct __attribute__((packed)) ccUiSelectCaptionWindow {
    /* 0x000 */ void *vtable;                         /* PTR_FUN_140860980 */
    /* 0x008 */ uint8_t _base_ccUiTaskBase[0x60];     /* base class */
    /* 0x068 */ uint64_t field_0x68;                  /* surfaced */
    /* 0x070 */ uint8_t _pad_0x070[0x08];
    /* 0x078 */ uint64_t field_0x78;                  /* surfaced */
    /* 0x080 */ uint64_t field_0x80;                  /* surfaced */
    /* 0x088 */ uint64_t field_0x88;                  /* surfaced */
    /* 0x090 */ uint32_t field_0x90;                  /* surfaced, sz=4 */
    /* 0x094 */ uint32_t field_0x94;                  /* surfaced, sz=4 */
    /* 0x098 */ uint32_t field_0x98;                  /* surfaced, sz=4 */
    /* 0x09C */ uint32_t field_0x9C;                  /* surfaced, sz=4 (set to 0xfffffffe) */
    /* 0x0A0 */ uint32_t field_0xA0;                  /* surfaced, sz=4 */
    /* 0x0A4 */ uint8_t _pad_0x0A4[0x04];
    /* 0x0A8 */ uint8_t field_0xA8;                   /* surfaced, sz=1 */
    /* 0x0A9 */ uint8_t _pad_0x0A9[0x0F];
    /* 0x0B8 */ uint64_t field_0xB8;                  /* surfaced */
    /* 0x0C0 */ uint64_t field_0xC0;                  /* surfaced */
    /* 0x0C8 */ uint64_t field_0xC8;                  /* surfaced */
    /* 0x0D0 */ uint8_t _pad_0x0D0[0x10];
    /* 0x0E0 */ uint8_t field_0xE0;                   /* surfaced, sz=1 */
    /* 0x0E1 */ uint8_t _pad_0x0E1[0x0F];
    /* 0x0F0 */ uint64_t field_0xF0;                  /* surfaced */
    /* 0x0F8 */ uint64_t field_0xF8;                  /* surfaced */
    /* 0x100 */ uint64_t field_0x100;                 /* surfaced */
    /* 0x108 */ uint8_t _pad_0x108[0x10];
    /* 0x118 */ uint64_t field_0x118;                 /* surfaced */
    /* 0x120 */ uint32_t field_0x120;                 /* surfaced, sz=4 */
    /* 0x124 */ uint32_t field_0x124;                 /* surfaced, sz=4 (set to 1) */
    /* 0x128 */ uint8_t field_0x128[0x08];            /* surfaced, sz=None */
    /* 0x130 */ uint64_t field_0x130;                 /* surfaced */
    /* 0x138 */ uint64_t field_0x138;                 /* surfaced */
    /* 0x140 */ uint64_t field_0x140;                 /* surfaced */
    /* 0x148 */ uint8_t _pad_0x148[0x10];
    /* 0x158 */ uint8_t field_0x158[0x08];            /* surfaced, sz=None */
    /* 0x160 */ uint64_t field_0x160;                 /* surfaced */
    /* 0x168 */ uint32_t field_0x168;                 /* surfaced, sz=4 */
    /* 0x16C */ uint64_t field_0x16C;                 /* surfaced (float 0x43af0000 = 350.0f) */
    /* 0x174 */ uint8_t _pad_0x174[0x0C];
    /* 0x180 */ uint8_t field_0x180[0x08];            /* surfaced, sz=None */
    /* 0x188 */ uint8_t field_0x188[0x08];            /* surfaced, sz=None */
    /* 0x190 */ uint8_t field_0x190[0x08];            /* surfaced, sz=None */
    /* 0x198 */ uint8_t field_0x198[0x08];            /* surfaced, sz=None */
} ccUiSelectCaptionWindow;

static_assert(offsetof(ccUiSelectCaptionWindow, vtable)    == 0x000, "ccUiSelectCaptionWindow.vtable");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x68) == 0x068, "ccUiSelectCaptionWindow.field_0x68");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x78) == 0x078, "ccUiSelectCaptionWindow.field_0x78");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x90) == 0x090, "ccUiSelectCaptionWindow.field_0x90");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x9C) == 0x09C, "ccUiSelectCaptionWindow.field_0x9C");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0xB8) == 0x0B8, "ccUiSelectCaptionWindow.field_0xB8");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x124)== 0x124, "ccUiSelectCaptionWindow.field_0x124");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x16C)== 0x16C, "ccUiSelectCaptionWindow.field_0x16C");
static_assert(offsetof(ccUiSelectCaptionWindow, field_0x198)== 0x198, "ccUiSelectCaptionWindow.field_0x198");

/* ========================================================================
 * ccWindowTalk
 * Vtable: PTR_FUN_140863428 (VA 0x140863428)
 * Base: ccTaskBase(param_1, 0, &DAT_140a55c30, 4)
 * Size: >= 0x1568 (last surfaced field at 0x1560 + 8)
 * Allocation: LoadTh(0x1568,...) in FUN_1401ea390 → PROVEN size 0x1568
 * Fields: 22 surfaced (all at high offsets 0x14B8+, indicating ~5KB base class)
 * Contains: 7 Nucc::Vector2 subobjects at 0x14E8–0x1520
 * ======================================================================== */
typedef struct __attribute__((packed)) ccWindowTalk {
    /* 0x0000 */ void *vtable;                        /* PTR_FUN_140863428 */
    /* 0x0008 */ uint8_t _base_ccTaskBase[0x14B0];    /* large base class (~5296 bytes) */
    /* 0x14B8 */ uint64_t field_0x14B8;               /* surfaced */
    /* 0x14C0 */ uint64_t field_0x14C0;               /* surfaced */
    /* 0x14C8 */ uint64_t field_0x14C8;               /* surfaced */
    /* 0x14D0 */ uint32_t field_0x14D0;               /* surfaced, sz=4 */
    /* 0x14D4 */ uint8_t _pad_0x14D4[0x04];
    /* 0x14D8 */ uint64_t field_0x14D8;               /* surfaced */
    /* 0x14E0 */ uint64_t field_0x14E0;               /* surfaced */
    /* 0x14E8 */ uint8_t field_0x14E8[0x08];          /* surfaced, sz=None */
    /* 0x14F0 */ uint8_t field_0x14F0[0x08];          /* surfaced, sz=None */
    /* 0x14F8 */ uint8_t field_0x14F8[0x08];          /* surfaced, sz=None */
    /* 0x1500 */ uint8_t field_0x1500[0x08];          /* surfaced, sz=None */
    /* 0x1508 */ uint8_t field_0x1508[0x08];          /* surfaced, sz=None */
    /* 0x1510 */ uint8_t field_0x1510[0x08];          /* surfaced, sz=None */
    /* 0x1518 */ uint8_t field_0x1518[0x08];          /* surfaced, sz=None */
    /* 0x1520 */ uint64_t field_0x1520;               /* surfaced */
    /* 0x1528 */ uint64_t field_0x1528;               /* surfaced */
    /* 0x1530 */ uint64_t field_0x1530;               /* surfaced */
    /* 0x1538 */ uint64_t field_0x1538;               /* surfaced */
    /* 0x1540 */ uint64_t field_0x1540;               /* surfaced */
    /* 0x1548 */ uint64_t field_0x1548;               /* surfaced */
    /* 0x1550 */ uint64_t field_0x1550;               /* surfaced */
    /* 0x1558 */ uint64_t field_0x1558;               /* surfaced */
    /* 0x1560 */ uint64_t field_0x1560;               /* surfaced */
} ccWindowTalk;

static_assert(offsetof(ccWindowTalk, vtable)      == 0x0000, "ccWindowTalk.vtable");
static_assert(offsetof(ccWindowTalk, field_0x14B8) == 0x14B8, "ccWindowTalk.field_0x14B8");
static_assert(offsetof(ccWindowTalk, field_0x14C0) == 0x14C0, "ccWindowTalk.field_0x14C0");
static_assert(offsetof(ccWindowTalk, field_0x14D0) == 0x14D0, "ccWindowTalk.field_0x14D0");
static_assert(offsetof(ccWindowTalk, field_0x1520) == 0x1520, "ccWindowTalk.field_0x1520");
static_assert(offsetof(ccWindowTalk, field_0x1560) == 0x1560, "ccWindowTalk.field_0x1560");

/* ========================================================================
 * ccWindowTalkEx
 * Vtable: PTR_FUN_1408634c0 (VA 0x1408634c0)
 * Base: ccTaskBase(param_1, 0, &DAT_140a55e20, 2)
 * Size: >= 0x15EC (last field at 0x15E8 + 4)
 * Allocation: LoadTh(0x15f8,...) in FUN_1401d48cc → PROVEN size 0x15F8
 * Fields: 7 surfaced
 * Contains: embedded ccWindowTalkHandler at +0x2b8*8=0x15C0, ccWindowCollisionHandler at +0x2ba*8=0x15D0
 * ======================================================================== */
typedef struct __attribute__((packed)) ccWindowTalkEx {
    /* 0x0000 */ void *vtable;                        /* PTR_FUN_1408634c0 */
    /* 0x0008 */ uint8_t _base_ccTaskBase[0x14B0];    /* same large base as ccWindowTalk */
    /* 0x14B8 */ uint8_t field_0x14B8[0x08];          /* surfaced, sz=None */
    /* 0x14C0 */ uint8_t _pad_0x14C0[0x78];
    /* 0x1538 */ uint8_t field_0x1538[0x08];          /* surfaced, sz=None */
    /* 0x1540 */ uint8_t _pad_0x1540[0x78];
    /* 0x15B8 */ uint8_t field_0x15B8[0x08];          /* surfaced, sz=None */
    /* 0x15C0 */ uint8_t _embedded_handler[0x10];     /* ccWindowTalkHandler subobject */
    /* 0x15D0 */ uint8_t _embedded_collision[0x14];   /* ccWindowCollisionHandler subobject */
    /* 0x15E4 */ uint32_t field_0x15E4;               /* surfaced, sz=4 (set to 1 in ctor) */
    /* 0x15E8 */ uint32_t field_0x15E8;               /* surfaced, sz=4 */
} ccWindowTalkEx;

static_assert(offsetof(ccWindowTalkEx, vtable)      == 0x0000, "ccWindowTalkEx.vtable");
static_assert(offsetof(ccWindowTalkEx, field_0x14B8) == 0x14B8, "ccWindowTalkEx.field_0x14B8");
static_assert(offsetof(ccWindowTalkEx, field_0x1538) == 0x1538, "ccWindowTalkEx.field_0x1538");
static_assert(offsetof(ccWindowTalkEx, field_0x15B8) == 0x15B8, "ccWindowTalkEx.field_0x15B8");
static_assert(offsetof(ccWindowTalkEx, field_0x15E4) == 0x15E4, "ccWindowTalkEx.field_0x15E4");
static_assert(offsetof(ccWindowTalkEx, field_0x15E8) == 0x15E8, "ccWindowTalkEx.field_0x15E8");

/* ========================================================================
 * ccWindowTalkFix
 * Vtable: PTR_FUN_140863568 (VA 0x140863568)
 * Base: ccTaskBase(param_1, 5, &DAT_140a55fc0)
 * Size: >= 0x1578 (last field at 0x1570 + 8)
 * Allocation: LoadTh(0x1578,...) in FUN_1401ea3f8 → PROVEN size 0x1578
 * Fields: 16 surfaced
 * Contains: 2 btBoxBoxDetector subobjects, nuccPostEffectDOF::CameraParam
 * ======================================================================== */
typedef struct __attribute__((packed)) ccWindowTalkFix {
    /* 0x0000 */ void *vtable;                        /* PTR_FUN_140863568 */
    /* 0x0008 */ uint8_t _base_ccTaskBase[0x14B0];    /* same large base */
    /* 0x14B8 */ uint64_t field_0x14B8;               /* surfaced */
    /* 0x14C0 */ uint32_t field_0x14C0;               /* surfaced, sz=4 */
    /* 0x14C4 */ uint8_t _pad_0x14C4[0x04];
    /* 0x14C8 */ uint8_t field_0x14C8[0x08];          /* surfaced, sz=None */
    /* 0x14D0 */ uint8_t _pad_0x14D0[0x08];
    /* 0x14D8 */ uint8_t field_0x14D8[0x08];          /* surfaced, sz=None */
    /* 0x14E0 */ uint8_t _pad_0x14E0[0x08];
    /* 0x14E8 */ uint8_t field_0x14E8[0x08];          /* surfaced, sz=None */
    /* 0x14F0 */ uint8_t _pad_0x14F0[0x10];
    /* 0x1500 */ uint64_t field_0x1500;               /* surfaced */
    /* 0x1508 */ uint8_t field_0x1508[0x08];          /* surfaced, sz=None */
    /* 0x1510 */ uint8_t _pad_0x1510[0x20];
    /* 0x1530 */ uint32_t field_0x1530;               /* surfaced, sz=4 */
    /* 0x1534 */ uint8_t _pad_0x1534[0x04];
    /* 0x1538 */ uint64_t field_0x1538;               /* surfaced */
    /* 0x1540 */ uint64_t field_0x1540;               /* surfaced */
    /* 0x1548 */ uint64_t field_0x1548;               /* surfaced */
    /* 0x1550 */ uint64_t field_0x1550;               /* surfaced */
    /* 0x1558 */ uint64_t field_0x1558;               /* surfaced */
    /* 0x1560 */ uint64_t field_0x1560;               /* surfaced */
    /* 0x1568 */ uint64_t field_0x1568;               /* surfaced */
    /* 0x1570 */ uint64_t field_0x1570;               /* surfaced */
} ccWindowTalkFix;

static_assert(offsetof(ccWindowTalkFix, vtable)      == 0x0000, "ccWindowTalkFix.vtable");
static_assert(offsetof(ccWindowTalkFix, field_0x14B8) == 0x14B8, "ccWindowTalkFix.field_0x14B8");
static_assert(offsetof(ccWindowTalkFix, field_0x14C0) == 0x14C0, "ccWindowTalkFix.field_0x14C0");
static_assert(offsetof(ccWindowTalkFix, field_0x1500) == 0x1500, "ccWindowTalkFix.field_0x1500");
static_assert(offsetof(ccWindowTalkFix, field_0x1530) == 0x1530, "ccWindowTalkFix.field_0x1530");
static_assert(offsetof(ccWindowTalkFix, field_0x1570) == 0x1570, "ccWindowTalkFix.field_0x1570");

/* ========================================================================
 * ccWindowTalkHandler
 * Vtable: PTR_FUN_140863618 (VA 0x140863618)
 * Base: none (standalone small struct)
 * Size: >= 0x10 (vtable + one int32 field at offset 0x8, zeroed in ctor)
 * Allocation: always embedded (in ccWindowTalkEx at +0x15C0), never heap-allocated alone
 * Fields: 0 surfaced (only vtable + 1 int seen in ctor)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccWindowTalkHandler {
    /* 0x00 */ void *vtable;                          /* PTR_FUN_140863618 */
    /* 0x08 */ int32_t field_0x08;                    /* zeroed in ctor */
    /* 0x0C */ uint8_t _pad_0x0C[0x04];
} ccWindowTalkHandler;

static_assert(offsetof(ccWindowTalkHandler, vtable)   == 0x00, "ccWindowTalkHandler.vtable");
static_assert(offsetof(ccWindowTalkHandler, field_0x08)== 0x08, "ccWindowTalkHandler.field_0x08");

/* ========================================================================
 * ccWindowTalkManager
 * Vtable: PTR_FUN_140863678 (VA 0x140863678)
 * Base: none visible
 * Size: >= 0x94 (ccBuildUniqueId at +0xc*8=0x60, size ~0x34 → ends at 0x94)
 * Allocation: LoadTh(0x70,...) in FUN_1401e7188 → PROVEN size 0x70 (but fields extend beyond?)
 *   Actually 0x70 = 112 bytes. ccBuildUniqueId at offset 0x60 with ~0x34 bytes would exceed.
 *   The LoadTh size 0x70 may be for a different allocation in the same function.
 *   Size unknown, >= 0x94 based on field extent.
 * Fields: 2 surfaced
 * ======================================================================== */
typedef struct __attribute__((packed)) ccWindowTalkManager {
    /* 0x00 */ void *vtable;                          /* PTR_FUN_140863678 */
    /* 0x08 */ int32_t field_0x08;                    /* zeroed in ctor */
    /* 0x0C */ uint64_t field_0x0C;                   /* surfaced, sz=8 (set to 1 in ctor) */
    /* 0x14 */ uint8_t _pad_0x14[0x14];
    /* 0x28 */ uint64_t field_0x28;                   /* zeroed (param_1[3]=0 → 0x18, [4]=0 → 0x20) */
    /* 0x30 */ uint8_t _pad_0x30[0x30];
    /* 0x60 */ uint8_t field_0x60[0x34];              /* surfaced sz=None; ccBuildUniqueId subobject */
} ccWindowTalkManager;

static_assert(offsetof(ccWindowTalkManager, vtable)   == 0x00, "ccWindowTalkManager.vtable");
static_assert(offsetof(ccWindowTalkManager, field_0x0C)== 0x0C, "ccWindowTalkManager.field_0x0C");
static_assert(offsetof(ccWindowTalkManager, field_0x60)== 0x60, "ccWindowTalkManager.field_0x60");

/* ========================================================================
 * Classes NOT reconstructed (insufficient evidence or < 3 methods):
 * - ccUiMessage: ctor is a handle lookup, not a real constructor; 0 surfaced fields
 * - ccUiTaskMessage: only 2 methods (ctor variants), below threshold
 * - mmScriptNodeXML: only 1 method (IsValid), below threshold
 * ======================================================================== */

#endif /* ST2C06_H */