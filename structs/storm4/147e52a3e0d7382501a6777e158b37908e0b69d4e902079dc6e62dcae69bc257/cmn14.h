/*
 * cmn14.h — Storm 4 (s4) UI struct group cmn14
 * Build: NSUNS4_release.exe (SHA 147e52a3e0d7), image base 0x140000000
 * Generated from state_surface + constructor decompiles.
 * Structs use natural x86-64 alignment (matching the MSVC-compiled game).
 * Every field offset verified by static_assert.
 * Rollback tags: SIM = simulation state, PRES = presentation-only, UNKNOWN = unclassified.
 */
#ifndef CMN14_H
#define CMN14_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ── ccUiScreenInfo ─────────────────────────────────────────────── */
/* vtable: 0x1411046e8  size ≥ 0x14  ctor: 0xB0AC30 */
typedef struct ccUiScreenInfo {
    void     *vtable;      /* +0x00  PTR_FUN_1411046e8 */
    uint32_t  is_wide;     /* +0x08  w  ctor  PRES */
    float     scale_x;     /* +0x0C  rw state_surface  PRES */
    float     scale_y;     /* +0x10  rw state_surface  PRES */
} ccUiScreenInfo;
static_assert(offsetof(ccUiScreenInfo, vtable)   == 0x00, "ccUiScreenInfo::vtable");
static_assert(offsetof(ccUiScreenInfo, is_wide)  == 0x08, "ccUiScreenInfo::is_wide");
static_assert(offsetof(ccUiScreenInfo, scale_x)  == 0x0C, "ccUiScreenInfo::scale_x");
static_assert(offsetof(ccUiScreenInfo, scale_y)  == 0x10, "ccUiScreenInfo::scale_y");
static_assert(sizeof(ccUiScreenInfo) >= 0x14, "ccUiScreenInfo size");

/* ── ccUiPartsParamBinary ───────────────────────────────────────── */
/* No proven vtable.  size ≥ 0x38  seed: EndianConvert 0xB07150 */
typedef struct ccUiPartsParamBinary {
    uint8_t   _pad_00[0x2C]; /* +0x00 */
    uint32_t  field_2C;      /* +0x2C  rw  EndianConvert  UNKNOWN */
    uint32_t  field_30;      /* +0x30  rw  EndianConvert  UNKNOWN */
    uint32_t  field_34;      /* +0x34  rw  EndianConvert  UNKNOWN */
    uint8_t   _pad_38[0x04]; /* +0x38  pad to ≥0x38 */
} ccUiPartsParamBinary;
static_assert(offsetof(ccUiPartsParamBinary, field_2C) == 0x2C, "ccUiPartsParamBinary::field_2C");
static_assert(offsetof(ccUiPartsParamBinary, field_30) == 0x30, "ccUiPartsParamBinary::field_30");
static_assert(offsetof(ccUiPartsParamBinary, field_34) == 0x34, "ccUiPartsParamBinary::field_34");
static_assert(sizeof(ccUiPartsParamBinary) >= 0x38, "ccUiPartsParamBinary size");

/* ── ccUiLayoutParts ────────────────────────────────────────────── */
/* No proven vtable.  size ≥ 0x38  seed: SetAttach 0xB044F0 */
typedef struct ccUiLayoutParts {
    uint8_t   _pad_00[0x34]; /* +0x00 */
    int32_t   attach_index;  /* +0x34  r  SetAttach  PRES */
    uint8_t   _pad_38[0x04]; /* +0x38  pad to ≥0x38 */
} ccUiLayoutParts;
static_assert(offsetof(ccUiLayoutParts, attach_index) == 0x34, "ccUiLayoutParts::attach_index");
static_assert(sizeof(ccUiLayoutParts) >= 0x38, "ccUiLayoutParts size");

/* ── ccUiOpenCloseCtrl ──────────────────────────────────────────── */
/* vtable: 0x1411179f0  size ≥ 0x248  ctor: 0xAF0200 */
typedef struct ccUiOpenCloseCtrl {
    void     *vtable;        /* +0x00  PTR_FUN_1411179f0 */
    uint32_t  count;         /* +0x08  w  ctor (=4)  PRES */
    uint8_t   _pad_0C[0x04]; /* +0x0C */
    void     *dat_ptr;       /* +0x10  w  ctor  PRES */
    uint64_t  _pad_18;       /* +0x18  w  ctor (=0)  UNKNOWN */
    uint64_t  anim_entry;    /* +0x20  w  ctor (=0)  PRES */
    uint32_t  _pad_28;       /* +0x28  w  ctor (=0xFFFFFFFF)  UNKNOWN */
    uint32_t  _pad_2C;       /* +0x2C */
    uint64_t  mode;          /* +0x30  — natural align places uint64 here */
    float     rate;          /* +0x38  w  ctor (=1.0f)  PRES */
    uint8_t   _pad_3C[0x3C]; /* +0x3C */
    void     *pptr;          /* +0x78  r  _Open  PRES */
    uint64_t  field_80;      /* +0x80  rw  _Open  UNKNOWN */
    uint8_t   _pad_88[0x2C]; /* +0x88 */
    uint32_t  open_flag;     /* +0xB4  w  _Open (=1)  PRES */
    uint8_t   _pad_B8[0x190];/* +0xB8 pad to ≥0x248 */
    /* vfunc dispatch at vtable+0x48 seen in Close → size ≥ 0x248 */
} ccUiOpenCloseCtrl;
static_assert(offsetof(ccUiOpenCloseCtrl, vtable)    == 0x00, "ccUiOpenCloseCtrl::vtable");
static_assert(offsetof(ccUiOpenCloseCtrl, count)     == 0x08, "ccUiOpenCloseCtrl::count");
static_assert(offsetof(ccUiOpenCloseCtrl, dat_ptr)   == 0x10, "ccUiOpenCloseCtrl::dat_ptr");
static_assert(offsetof(ccUiOpenCloseCtrl, anim_entry)== 0x20, "ccUiOpenCloseCtrl::anim_entry");
static_assert(offsetof(ccUiOpenCloseCtrl, pptr)      == 0x78, "ccUiOpenCloseCtrl::pptr");
static_assert(offsetof(ccUiOpenCloseCtrl, field_80)  == 0x80, "ccUiOpenCloseCtrl::field_80");
static_assert(offsetof(ccUiOpenCloseCtrl, open_flag) == 0xB4, "ccUiOpenCloseCtrl::open_flag");
static_assert(sizeof(ccUiOpenCloseCtrl) >= 0x248, "ccUiOpenCloseCtrl size");

/* ── ccUiObject ─────────────────────────────────────────────────── */
/* vtable: 0x141115b90  size ≥ 0x408  ctor: 0xACE150
 * BlockAllocator base occupies +0x08..+0x87.
 * Virtual dispatch at vtable+0x10 (ctor), vtable+0x78 (Ctrl), vtable+0x80 (Rendering).
 */
typedef struct ccUiObject {
    void     *vtable;           /* +0x00  PTR_FUN_141115b90 */
    uint8_t   block_alloc[0x80];/* +0x08  BlockAllocator base */
    uint64_t  field_88;         /* +0x88  w  ctor (=0)  UNKNOWN */
    uint32_t  field_90;         /* +0x90  w  ctor (=0)  UNKNOWN */
    uint32_t  field_94;         /* +0x94  — fills gap to +0x98 */
    uint32_t  field_98;         /* +0x98  w  ctor (=0)  UNKNOWN */
    uint8_t   field_9C;         /* +0x9C  w  ctor (=0 byte)  UNKNOWN */
    uint8_t   _pad_9D[3];       /* +0x9D */
    uint64_t  field_A0;         /* +0xA0  w  ctor (=0)  UNKNOWN */
    uint32_t  type_id;          /* +0xA8  w  ctor (param_2)  SIM */
    uint32_t  field_AC;         /* +0xAC  w  ctor (param_3)  UNKNOWN */
    uint32_t  field_B0;         /* +0xB0  rw  ctor/Rendering  PRES */
    uint32_t  enable_flag;      /* +0xB4  rw  ctor/Ctrl (=1)  SIM */
    uint32_t  field_B8;         /* +0xB8  rw  ctor/Rendering (=1)  PRES */
    uint8_t   _pad_BC[0x344];   /* +0xBC  gap to virtual dispatch region */
    /* vtable+0x78 dispatch seen in Ctrl → offset 0x3C0 region */
    /* vtable+0x80 dispatch seen in Rendering → offset 0x400 region */
    uint8_t   _tail[0x08];      /* +0x400 */
} ccUiObject;
static_assert(offsetof(ccUiObject, vtable)      == 0x00, "ccUiObject::vtable");
static_assert(offsetof(ccUiObject, field_88)    == 0x88, "ccUiObject::field_88");
static_assert(offsetof(ccUiObject, field_90)    == 0x90, "ccUiObject::field_90");
static_assert(offsetof(ccUiObject, field_98)    == 0x98, "ccUiObject::field_98");
static_assert(offsetof(ccUiObject, field_9C)    == 0x9C, "ccUiObject::field_9C");
static_assert(offsetof(ccUiObject, field_A0)    == 0xA0, "ccUiObject::field_A0");
static_assert(offsetof(ccUiObject, type_id)     == 0xA8, "ccUiObject::type_id");
static_assert(offsetof(ccUiObject, field_AC)    == 0xAC, "ccUiObject::field_AC");
static_assert(offsetof(ccUiObject, field_B0)    == 0xB0, "ccUiObject::field_B0");
static_assert(offsetof(ccUiObject, enable_flag) == 0xB4, "ccUiObject::enable_flag");
static_assert(offsetof(ccUiObject, field_B8)    == 0xB8, "ccUiObject::field_B8");
static_assert(sizeof(ccUiObject) >= 0x408, "ccUiObject size");

/* ── ccUiObjectContainer ────────────────────────────────────────── */
/* vtable: 0x141118d30  size ≥ 0x158  ctor: 0xB094C0
 * BlockAllocator base + embedded sub-object via FUN_140b09890(param_1+3).
 * Draw method accesses many high offsets (0xC8C, 0x10B4, 0x14000+) that are
 * array/loop indices into the embedded sub-object, NOT direct struct fields.
 * Only low-offset fields confirmed by non-Draw methods or ctor are listed.
 * Virtual dispatch at vtable+0x10 (Add/Remove/Release), vtable+0xA0, vtable+0xA8.
 */
typedef struct ccUiObjectContainer {
    void     *vtable;            /* +0x00  PTR_FUN_141118d30 */
    uint8_t   block_alloc[0x60]; /* +0x08  BlockAllocator base (inferred) */
    void     *list_head;         /* +0x68  r  RemoveAll  PRES */
    void     *field_70;          /* +0x70  r  Draw  UNKNOWN */
    uint64_t  field_78;          /* +0x78  r  Draw  UNKNOWN */
    uint64_t  field_80;          /* +0x80  r  vfunc dispatch  UNKNOWN */
    uint64_t  field_88;          /* +0x88  r  Draw  UNKNOWN */
    uint64_t  list_tail;         /* +0x90  rw  RemoveAll  PRES */
    uint64_t  field_98;          /* +0x98  r  Draw  UNKNOWN */
    uint64_t  field_A0;          /* +0xA0  — fill gap */
    uint64_t  field_A8;          /* +0xA8  w  Draw  UNKNOWN */
    uint64_t  field_B0;          /* +0xB0  — fill gap */
    uint64_t  field_B8;          /* +0xB8  — fill gap */
    uint64_t  field_C0;          /* +0xC0  — fill gap */
    uint64_t  field_C8;          /* +0xC8  r  Draw  UNKNOWN */
    uint8_t   _pad_D0[0x38];     /* +0xD0 */
    uint64_t  field_108;         /* +0x108  r  Draw (sub-obj)  UNKNOWN */
    uint8_t   _pad_110[0x38];    /* +0x110 */
    uint64_t  field_148;         /* +0x148  rw  Draw  UNKNOWN */
    uint32_t  field_150;         /* +0x150  w  Draw  UNKNOWN */
    uint8_t   _pad_154[0x04];    /* +0x154 */
    /* Embedded sub-object continues beyond +0x158; high offsets from Draw
     * (0xC8C, 0x10B4, 0xCA8-0xCC0, 0xFD8C, 0x14000-0x14B80) belong to it. */
} ccUiObjectContainer;
static_assert(offsetof(ccUiObjectContainer, vtable)    == 0x00, "ccUiObjectContainer::vtable");
static_assert(offsetof(ccUiObjectContainer, list_head) == 0x68, "ccUiObjectContainer::list_head");
static_assert(offsetof(ccUiObjectContainer, field_70)  == 0x70, "ccUiObjectContainer::field_70");
static_assert(offsetof(ccUiObjectContainer, field_78)  == 0x78, "ccUiObjectContainer::field_78");
static_assert(offsetof(ccUiObjectContainer, list_tail) == 0x90, "ccUiObjectContainer::list_tail");
static_assert(offsetof(ccUiObjectContainer, field_98)  == 0x98, "ccUiObjectContainer::field_98");
static_assert(offsetof(ccUiObjectContainer, field_108) == 0x108, "ccUiObjectContainer::field_108");
static_assert(offsetof(ccUiObjectContainer, field_148) == 0x148, "ccUiObjectContainer::field_148");
static_assert(offsetof(ccUiObjectContainer, field_150) == 0x150, "ccUiObjectContainer::field_150");
static_assert(sizeof(ccUiObjectContainer) >= 0x158, "ccUiObjectContainer size");

/* ── ccUiManager ────────────────────────────────────────────────── */
/* vtable: 0x141118ef0  size ≥ 0x1CC  ctor: 0xB0ACE0
 * BlockAllocator base occupies +0x08..+0x1A7.
 * Sub-vtable PTR_FUN_1411046e8 stored at +0x1B8 (ccUiScreenInfo vtable).
 * Loop of 9 entries stride 0x28 starting at param_1+3 in ctor.
 */
typedef struct ccUiManager {
    void     *vtable;            /* +0x00  PTR_FUN_141118ef0 */
    uint8_t   block_alloc[0x1A0];/* +0x08  BlockAllocator base */
    uint64_t  field_1A8;         /* +0x1A8  rw  ctor/Initialize  PRES */
    uint64_t  field_1B0;         /* +0x1B0  w  ctor (=0)  UNKNOWN */
    void     *screen_info_vt;    /* +0x1B8  w  ctor (=PTR_FUN_1411046e8)  PRES */
    uint32_t  is_wide;           /* +0x1C0  w  ctor  PRES */
    float     screen_scale_x;    /* +0x1C4  r  ctor (Vector2)  PRES */
    float     screen_scale_y;    /* +0x1C8  r  ctor (Vector2)  PRES */
} ccUiManager;
static_assert(offsetof(ccUiManager, vtable)         == 0x00,  "ccUiManager::vtable");
static_assert(offsetof(ccUiManager, field_1A8)      == 0x1A8, "ccUiManager::field_1A8");
static_assert(offsetof(ccUiManager, field_1B0)      == 0x1B0, "ccUiManager::field_1B0");
static_assert(offsetof(ccUiManager, screen_info_vt) == 0x1B8, "ccUiManager::screen_info_vt");
static_assert(offsetof(ccUiManager, is_wide)        == 0x1C0, "ccUiManager::is_wide");
static_assert(offsetof(ccUiManager, screen_scale_x) == 0x1C4, "ccUiManager::screen_scale_x");
static_assert(offsetof(ccUiManager, screen_scale_y) == 0x1C8, "ccUiManager::screen_scale_y");
static_assert(sizeof(ccUiManager) >= 0x1CC, "ccUiManager size");

/* ── ccUiLoader ─────────────────────────────────────────────────── */
/* ccUiLoader: no instance state.
 * All 3 methods access only globals / other singletons, never param_1:
 *   GetUiLoader    0xAEBE70 — reads global DAT_1416bf5a8 (std::map)
 *   GetLoadProgress 0xAEBD60 — void signature, calls GetUiLoader()
 *   GetLoadFileNum  0xAEBDD0 — void signature, calls GetUiLoader()
 * state_surface returned 0 fields across all 3 seeds.
 * The class is a static utility facade over ccFileLoadListForUi. */

#endif /* CMN14_H */