/* cmn43 s3 — NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe) struct layouts
 * INFERRED from static analysis only. Not runtime-confirmed.
 * Build: s3 / NSUNS3.exe-a7124b / image base 0x140000000
 * Date: 2026-10-19
 */
#ifndef CMN43_S3_H
#define CMN43_S3_H

#include <stdint.h>
#include <stddef.h>

/* ---- nuccAnmMiddle ----
 * Inherits nuccAnmBase (0x00..0x97 opaque).
 * Size >= 0xF4 proven from ctor field writes (last write at 0xF0 + 4 bytes).
 * No standalone allocator call found; nuccAnm::nuccAnm extends beyond this.
 * Vtable at 0x00 (PTR_FUN_1409dfc40), secondary vtable-like ptr at 0xD0.
 */
typedef struct __attribute__((packed)) nuccAnmMiddle {
    uint8_t  base[0x98];              /* 0x00  nuccAnmBase (opaque)        */
    uint64_t vtbl_or_handler_0x98;    /* 0x98  rw8  PTR_FUN_140989ed8     */
    uint8_t  pad_0xA0[0x10];          /* 0xA0  gap                        */
    uint64_t field_0xB0;              /* 0xB0  w8   zeroed in ctor         */
    uint32_t field_0xB8;              /* 0xB8  w4   zeroed in ctor         */
    uint8_t  pad_0xBC[4];             /* 0xBC  padding                    */
    uint64_t field_0xC0;              /* 0xC0  w8   zeroed in ctor         */
    uint32_t field_0xC8;              /* 0xC8  w4   0xFFFFFFFF            */
    uint32_t field_0xCC;              /* 0xCC  w4   1                     */
    uint64_t vtbl_secondary_0xD0;     /* 0xD0  w8   PTR_FUN_1409dfc10     */
    uint64_t self_ptr_0xD8;           /* 0xD8  w8   = this                */
    uint32_t field_0xE0;              /* 0xE0  w4   0xFFFFFFFF            */
    uint32_t field_0xE4;              /* 0xE4  w4   1                     */
    uint32_t field_0xE8;              /* 0xE8  w4   0xFFFFFFFF            */
    uint8_t  field_0xEC;              /* 0xEC  w1   zeroed                */
    uint8_t  pad_0xED[3];             /* 0xED  padding                    */
    uint32_t field_0xF0;              /* 0xF0  w4   1.0f (0x3F800000)     */
    /* size unknown, >= 0xF4 */
} nuccAnmMiddle;

_Static_assert(offsetof(nuccAnmMiddle, vtbl_or_handler_0x98) == 0x98, "nuccAnmMiddle.vtbl_or_handler_0x98");
_Static_assert(offsetof(nuccAnmMiddle, field_0xB0) == 0xB0, "nuccAnmMiddle.field_0xB0");
_Static_assert(offsetof(nuccAnmMiddle, field_0xB8) == 0xB8, "nuccAnmMiddle.field_0xB8");
_Static_assert(offsetof(nuccAnmMiddle, field_0xC0) == 0xC0, "nuccAnmMiddle.field_0xC0");
_Static_assert(offsetof(nuccAnmMiddle, field_0xC8) == 0xC8, "nuccAnmMiddle.field_0xC8");
_Static_assert(offsetof(nuccAnmMiddle, field_0xCC) == 0xCC, "nuccAnmMiddle.field_0xCC");
_Static_assert(offsetof(nuccAnmMiddle, vtbl_secondary_0xD0) == 0xD0, "nuccAnmMiddle.vtbl_secondary_0xD0");
_Static_assert(offsetof(nuccAnmMiddle, self_ptr_0xD8) == 0xD8, "nuccAnmMiddle.self_ptr_0xD8");
_Static_assert(offsetof(nuccAnmMiddle, field_0xE0) == 0xE0, "nuccAnmMiddle.field_0xE0");
_Static_assert(offsetof(nuccAnmMiddle, field_0xE4) == 0xE4, "nuccAnmMiddle.field_0xE4");
_Static_assert(offsetof(nuccAnmMiddle, field_0xE8) == 0xE8, "nuccAnmMiddle.field_0xE8");
_Static_assert(offsetof(nuccAnmMiddle, field_0xEC) == 0xEC, "nuccAnmMiddle.field_0xEC");
_Static_assert(offsetof(nuccAnmMiddle, field_0xF0) == 0xF0, "nuccAnmMiddle.field_0xF0");

/* ---- nuccAnmEffect ----
 * Inherits nuccAnmMiddle. Own fields start after base.
 * Size proven = 0x100 from nuccEffectSimpleAnm::CreateAnm (0x6C1FB0):
 *   FUN_140683f70(0x100, "..\\source\\render\\nuccEffectSimpleAnm.cpp")
 * immediately before calling nuccAnmEffect::nuccAnmEffect.
 * Vtable at 0x00 (PTR_FUN_1409e7c78).
 */
typedef struct __attribute__((packed)) nuccAnmEffect {
    uint8_t  base[0xF8];              /* 0x00  nuccAnmMiddle (flat)       */
    uint32_t flags_0xF8;              /* 0xF8  w4   zeroed in ctor        */
    uint8_t  pad_0xFC[4];             /* 0xFC  padding to 0x100           */
    /* size = 0x100 proven */
} nuccAnmEffect;

_Static_assert(offsetof(nuccAnmEffect, flags_0xF8) == 0xF8, "nuccAnmEffect.flags_0xF8");

/* ---- nuccAnmUi ----
 * Inherits nuccAnmBase (NOT nuccAnmMiddle).
 * Size proven = 0xB8 from ccUiAnm::Initialize (0x7651F0):
 *   FUN_140683f70(0xb8, "source\\ui\\ccUiAnm.cpp")
 * before calling wrapper FUN_140766e10 which invokes nuccAnmUi::nuccAnmUi.
 * Vtable at 0x00 (PTR_FUN_140a0b680).
 */
typedef struct __attribute__((packed)) nuccAnmUi {
    uint8_t  base[0x44];              /* 0x00  nuccAnmBase (opaque)       */
    uint32_t field_0x44;              /* 0x44  r4                         */
    uint8_t  pad_0x48[0x48];          /* 0x48  gap                        */
    uint64_t field_0x90;              /* 0x90  r8                         */
    uint8_t  pad_0x98[0x14];          /* 0x98  gap                        */
    uint32_t field_0xAC;              /* 0xAC  w4   -1.0f (0xBF800000)    */
    uint32_t field_0xB0;              /* 0xB0  w4   masked uint16         */
    uint8_t  pad_0xB4[4];             /* 0xB4  padding to 0xB8            */
    /* size = 0xB8 proven */
} nuccAnmUi;

_Static_assert(offsetof(nuccAnmUi, field_0x44) == 0x44, "nuccAnmUi.field_0x44");
_Static_assert(offsetof(nuccAnmUi, field_0x90) == 0x90, "nuccAnmUi.field_0x90");
_Static_assert(offsetof(nuccAnmUi, field_0xAC) == 0xAC, "nuccAnmUi.field_0xAC");
_Static_assert(offsetof(nuccAnmUi, field_0xB0) == 0xB0, "nuccAnmUi.field_0xB0");

/* ---- nuccAnmKey ----
 * Single proven field at 0x58 (w8, ctrl pointer written by CreateKeyCtrl).
 * Size unknown, >= 0x60. CreateKeyCtrl (0x731090) is a factory that sets up
 * matrix/quaternion state but does not allocate; callers allocate per type.
 * Vtable at 0x00 (PTR_FUN_1409eab48).
 */
typedef struct __attribute__((packed)) nuccAnmKey {
    uint8_t  base[0x58];              /* 0x00  opaque base               */
    uint64_t ctrl_0x58;               /* 0x58  w8   key controller ptr    */
    /* size unknown, >= 0x60 */
} nuccAnmKey;

_Static_assert(offsetof(nuccAnmKey, ctrl_0x58) == 0x58, "nuccAnmKey.ctrl_0x58");

/* nuccAnmKey_QuaternionI16TblBase: no instance state (byte-cast-only accesses).
 * Methods: Normalize @ 0x7330E0, IsNormalized @ 0x733010, dtor @ 0x733330.
 */

#endif /* CMN43_S3_H */