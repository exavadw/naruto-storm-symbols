/* cmn43.h — nuccAnm class hierarchy for Storm 1 (s1, NSUNS1.exe)
 * Generated from the decompiler cache state_surface + decomp analysis.
 * All layouts are INFERRED (static analysis only, not runtime-confirmed).
 * Offsets derived from s1 x64 decompiled pseudocode (image base 0x140000000).
 */
#ifndef CMN43_H
#define CMN43_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccAnmMiddle — base class for middle-layer animation objects
 * 20 methods in s1. Inherits from nuccAnmBase (not reconstructed here).
 * Size unknown, >= 0xF8 (last proven field at 0xF4, size 4).
 * Vtable pointer at offset 0x00. Second vtable-like pointer at 0xD0.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccAnmMiddle {
    uint8_t  vtable_ptr[8];           /* 0x00 */
    uint8_t  base_fields[0x98 - 8];   /* 0x08 — inherited nuccAnmBase state */
    uint64_t vtbl_or_handler_0x98;    /* 0x98 — rw8, PTR_FUN_1406ee938 in ctor */
    uint8_t  pad_0xA0[0xB0 - 0xA0];  /* 0xA0 */
    uint64_t field_0xB0;              /* 0xB0 — w8, zeroed in ctor */
    uint32_t field_0xB8;              /* 0xB8 — w4, zeroed in ctor */
    uint8_t  pad_0xBC[0xC0 - 0xBC];  /* 0xBC — explicit pad to align next qword */
    uint64_t field_0xC0;              /* 0xC0 — w8, zeroed in ctor */
    uint32_t field_0xC8;              /* 0xC8 — w4, 0xFFFFFFFF in ctor */
    uint32_t field_0xCC;              /* 0xCC — w4, 1 in ctor */
    uint64_t vtbl_secondary_0xD0;     /* 0xD0 — w8, PTR_FUN_140739a18 in ctor */
    uint64_t self_ptr_0xD8;           /* 0xD8 — w8, self-ptr in ctor */
    uint32_t field_0xE0;              /* 0xE0 — w4, 0xFFFFFFFF in ctor */
    uint32_t field_0xE4;              /* 0xE4 — w4, 1 in ctor */
    uint32_t field_0xE8;              /* 0xE8 — w4, 0xFFFFFFFF in ctor */
    uint8_t  field_0xEC;              /* 0xEC — w1, zeroed in ctor */
    uint8_t  pad_0xED[0xF0 - 0xED];  /* 0xED — explicit pad */
    uint32_t field_0xF0;              /* 0xF0 — w4, 0x3F800000 (1.0f) in ctor */
    uint8_t  field_0xF4[4];           /* 0xF4 — last proven field (size 4 assumed) */
} nuccAnmMiddle;

static_assert(offsetof(nuccAnmMiddle, vtable_ptr) == 0x00, "nuccAnmMiddle.vtable_ptr");
static_assert(offsetof(nuccAnmMiddle, base_fields) == 0x08, "nuccAnmMiddle.base_fields");
static_assert(offsetof(nuccAnmMiddle, vtbl_or_handler_0x98) == 0x98, "nuccAnmMiddle.vtbl_or_handler_0x98");
static_assert(offsetof(nuccAnmMiddle, field_0xB0) == 0xB0, "nuccAnmMiddle.field_0xB0");
static_assert(offsetof(nuccAnmMiddle, field_0xB8) == 0xB8, "nuccAnmMiddle.field_0xB8");
static_assert(offsetof(nuccAnmMiddle, field_0xC0) == 0xC0, "nuccAnmMiddle.field_0xC0");
static_assert(offsetof(nuccAnmMiddle, field_0xC8) == 0xC8, "nuccAnmMiddle.field_0xC8");
static_assert(offsetof(nuccAnmMiddle, field_0xCC) == 0xCC, "nuccAnmMiddle.field_0xCC");
static_assert(offsetof(nuccAnmMiddle, vtbl_secondary_0xD0) == 0xD0, "nuccAnmMiddle.vtbl_secondary_0xD0");
static_assert(offsetof(nuccAnmMiddle, self_ptr_0xD8) == 0xD8, "nuccAnmMiddle.self_ptr_0xD8");
static_assert(offsetof(nuccAnmMiddle, field_0xE0) == 0xE0, "nuccAnmMiddle.field_0xE0");
static_assert(offsetof(nuccAnmMiddle, field_0xE4) == 0xE4, "nuccAnmMiddle.field_0xE4");
static_assert(offsetof(nuccAnmMiddle, field_0xE8) == 0xE8, "nuccAnmMiddle.field_0xE8");
static_assert(offsetof(nuccAnmMiddle, field_0xEC) == 0xEC, "nuccAnmMiddle.field_0xEC");
static_assert(offsetof(nuccAnmMiddle, field_0xF0) == 0xF0, "nuccAnmMiddle.field_0xF0");
static_assert(offsetof(nuccAnmMiddle, field_0xF4) == 0xF4, "nuccAnmMiddle.field_0xF4");

/* =========================================================================
 * nuccAnmEffect — effect animation object, inherits nuccAnmMiddle
 * 6 methods in s1. Adds fields beyond nuccAnmMiddle base.
 * Size unknown, >= 0xFC (last proven writable at 0xF8, size 4).
 * Own writable fields: 0xC0 (w8), 0xF8 (w4).
 * Read fields at 0x44, 0x90, 0xB0 may be inherited from base.
 * Virtual dispatch offsets: 0x280, 0x3C0 (low confidence).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccAnmEffect {
    uint8_t  vtable_ptr[8];           /* 0x00 */
    uint8_t  base_to_0x44[0x44 - 8];  /* 0x08 */
    uint32_t field_0x44;              /* 0x44 — r4, read in SetAnm */
    uint8_t  pad_0x48[0x90 - 0x48];  /* 0x48 */
    uint64_t field_0x90;              /* 0x90 — r8, read in SetAnm */
    uint8_t  pad_0x98[0xB0 - 0x98];  /* 0x98 */
    uint64_t field_0xB0;              /* 0xB0 — r8, read in SetAnm */
    uint8_t  pad_0xB8[0xC0 - 0xB8];  /* 0xB8 */
    uint64_t data_0xC0;               /* 0xC0 — w8, written in SetAnm */
    uint8_t  pad_0xC8[0xF8 - 0xC8];  /* 0xC8 */
    uint32_t flags_0xF8;              /* 0xF8 — w4, zeroed in ctor */
} nuccAnmEffect;

static_assert(offsetof(nuccAnmEffect, vtable_ptr) == 0x00, "nuccAnmEffect.vtable_ptr");
static_assert(offsetof(nuccAnmEffect, field_0x44) == 0x44, "nuccAnmEffect.field_0x44");
static_assert(offsetof(nuccAnmEffect, field_0x90) == 0x90, "nuccAnmEffect.field_0x90");
static_assert(offsetof(nuccAnmEffect, field_0xB0) == 0xB0, "nuccAnmEffect.field_0xB0");
static_assert(offsetof(nuccAnmEffect, data_0xC0) == 0xC0, "nuccAnmEffect.data_0xC0");
static_assert(offsetof(nuccAnmEffect, flags_0xF8) == 0xF8, "nuccAnmEffect.flags_0xF8");

/* =========================================================================
 * nuccAnmUi — UI animation object, inherits nuccAnmBase (NOT nuccAnmMiddle)
 * 4 methods in s1. Ctor calls nuccAnmBase::nuccAnmBase() then SetAnm.
 * Size unknown, >= 0x98 (last proven read at 0x90, size 8).
 * Virtual dispatch at offset 0x280 (low confidence).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccAnmUi {
    uint8_t  vtable_ptr[8];           /* 0x00 */
    uint8_t  base_to_0x44[0x44 - 8];  /* 0x08 */
    uint32_t field_0x44;              /* 0x44 — r4, read in SetAnm */
    uint8_t  pad_0x48[0x90 - 0x48];  /* 0x48 */
    uint64_t field_0x90;              /* 0x90 — r8, read in SetAnm */
} nuccAnmUi;

static_assert(offsetof(nuccAnmUi, vtable_ptr) == 0x00, "nuccAnmUi.vtable_ptr");
static_assert(offsetof(nuccAnmUi, field_0x44) == 0x44, "nuccAnmUi.field_0x44");
static_assert(offsetof(nuccAnmUi, field_0x90) == 0x90, "nuccAnmUi.field_0x90");

/* =========================================================================
 * nuccAnmKey — keyframe data container
 * 3 methods in s1 (CreateKeyCtrl overloads).
 * Only one proven field at 0x58 (w8, written in CreateKeyCtrl@0x50AF40).
 * Size unknown, >= 0x60.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccAnmKey {
    uint8_t  vtable_ptr[8];           /* 0x00 */
    uint8_t  base_to_0x58[0x58 - 8];  /* 0x08 */
    uint64_t ctrl_0x58;               /* 0x58 — w8, set in CreateKeyCtrl */
} nuccAnmKey;

static_assert(offsetof(nuccAnmKey, vtable_ptr) == 0x00, "nuccAnmKey.vtable_ptr");
static_assert(offsetof(nuccAnmKey, ctrl_0x58) == 0x58, "nuccAnmKey.ctrl_0x58");

/* =========================================================================
 * nuccAnmKey_QuaternionI16TblBase — quaternion interpolation table base
 * 3 methods in s1 (Normalize, IsNormalized + 1 other).
 * No instance state detected by state_surface: all accesses were byte-cast
 * only (unknown element size). This class may be a pure interface or its
 * fields are accessed only through typed casts that static analysis cannot
 * resolve. Listed as no-instance-state per TASK.md rules.
 * Evidence: state_surface returned 0 fields, warnings: "unknown param_1
 * element size; only byte-cast accesses used" for Normalize and IsNormalized.
 * ========================================================================= */
/* nuccAnmKey_QuaternionI16TblBase: no instance state detected (see above) */

#endif /* CMN43_H */