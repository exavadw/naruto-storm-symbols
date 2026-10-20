/* cmn43 s4 — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe) struct layouts
 * INFERRED from static analysis only. Not runtime-confirmed.
 * Build: s4 / NSUNS4_release.exe-75912b / SHA 147e52a3e0d7 / image base 0x140000000
 * Date: 2026-10-19
 */
#ifndef CMN43_S4_H
#define CMN43_S4_H

#include <stdint.h>
#include <stddef.h>

/* ---- nuccAnmMiddle ----
 * Inherits nuccAnmBase (0x00..0x97 opaque).
 * Size >= 0xF4 proven from ctor field writes (last write at 0xF0 + 4 bytes).
 * No standalone allocator call found; all callers are nuccAnm subclasses.
 * Vtable at 0x00 (PTR_FUN_141106b08), secondary vtable-like ptr at 0xD0.
 */
typedef struct __attribute__((packed)) nuccAnmMiddle {
    uint8_t  base[0x98];              /* 0x00 nuccAnmBase (opaque) */
    uint64_t vtbl_or_handler_0x98;    /* 0x98 rw8 PTR_FUN_14101b328 */
    uint8_t  pad_0xA0[0x10];          /* 0xA0 gap */
    uint64_t field_0xB0;              /* 0xB0 w8 zeroed in ctor */
    uint32_t field_0xB8;              /* 0xB8 w4 zeroed in ctor */
    uint8_t  pad_0xBC[4];             /* 0xBC padding */
    uint64_t field_0xC0;              /* 0xC0 w8 zeroed in ctor */
    uint32_t field_0xC8;              /* 0xC8 w4 0xFFFFFFFF */
    uint32_t field_0xCC;              /* 0xCC w4 1 */
    uint64_t vtbl_secondary_0xD0;     /* 0xD0 w8 PTR_FUN_141106ad8 */
    uint64_t self_ptr_0xD8;           /* 0xD8 w8 = this */
    uint32_t field_0xE0;              /* 0xE0 w4 0xFFFFFFFF */
    uint32_t field_0xE4;              /* 0xE4 w4 1 */
    uint32_t field_0xE8;              /* 0xE8 w4 0xFFFFFFFF */
    uint8_t  field_0xEC;              /* 0xEC w1 zeroed */
    uint8_t  pad_0xED[3];             /* 0xED padding */
    uint32_t field_0xF0;              /* 0xF0 w4 1.0f (0x3F800000) */
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
 * Size proven = 0xF8 from nuccEffectSimpleAnm::CreateAnm (RVA 0xA4E800):
 *   FUN_140a017f0(0xf8, "...nuccEffectSimpleAnm.cpp")
 * Note: size changed from 0x100 in s3 to 0xF8 in s4.
 * Vtable at 0x00 (PTR_FUN_141110488).
 */
typedef struct __attribute__((packed)) nuccAnmEffect {
    uint8_t  base[0xF8];              /* 0x00 nuccAnmMiddle (flat) */
    /* size = 0xF8 proven */
} nuccAnmEffect;

/* ---- nuccAnmUi ----
 * Inherits nuccAnmBase (NOT nuccAnmMiddle).
 * Size proven = 0xB8 from ccUiAnm::Initialize (RVA 0xACE720):
 *   FUN_140a017f0(0xb8, "...ccUiAnm.cpp")
 * Vtable at 0x00 (PTR_FUN_14110b2e8), secondary init sets PTR_FUN_141115ee0.
 */
typedef struct __attribute__((packed)) nuccAnmUi {
    uint8_t  base[0x44];              /* 0x00 nuccAnmBase (opaque) */
    uint32_t field_0x44;              /* 0x44 r4 UNKNOWN */
    uint8_t  pad_0x48[0x48];          /* 0x48 gap */
    uint64_t field_0x90;              /* 0x90 r8 UNKNOWN */
    uint8_t  pad_0x98[0x14];          /* 0x98 gap */
    uint32_t field_0xAC;              /* 0xAC w4 -1.0f (0xBF800000) */
    uint32_t field_0xB0;              /* 0xB0 w4 masked uint16 */
    uint8_t  pad_0xB4[4];             /* 0xB4 padding to 0xB8 */
    /* size = 0xB8 proven */
} nuccAnmUi;

_Static_assert(offsetof(nuccAnmUi, field_0x44) == 0x44, "nuccAnmUi.field_0x44");
_Static_assert(offsetof(nuccAnmUi, field_0x90) == 0x90, "nuccAnmUi.field_0x90");
_Static_assert(offsetof(nuccAnmUi, field_0xAC) == 0xAC, "nuccAnmUi.field_0xAC");
_Static_assert(offsetof(nuccAnmUi, field_0xB0) == 0xB0, "nuccAnmUi.field_0xB0");

/* ---- nuccAnmKey ----
 * Single proven field at 0x58 (w8, ctrl pointer written by CreateKeyCtrl).
 * Size unknown, >= 0x60. CreateKeyCtrl is a factory that sets up
 * matrix/quaternion state but does not allocate; callers allocate per type.
 * Vtable at 0x00 (set by subclass ctors).
 */
typedef struct __attribute__((packed)) nuccAnmKey {
    uint8_t  base[0x58];              /* 0x00 opaque base */
    uint64_t ctrl_0x58;               /* 0x58 w8 key controller ptr */
    /* size unknown, >= 0x60 */
} nuccAnmKey;

_Static_assert(offsetof(nuccAnmKey, ctrl_0x58) == 0x58, "nuccAnmKey.ctrl_0x58");

/* ---- nuccAnmKey_EulerInterpolate ----
 * No instance state detected by state_surface (byte-cast-only accesses).
 * Listed as comment-only per TASK.md rules.
 * Methods: GetKeyQuat2New, GetKeyQuatNew, i_SlerpQuat.
 */

/* ---- nuccAnmKey_QuaternionLiner ----
 * No instance state detected by state_surface (byte-cast-only accesses).
 * i_LerpQuat (0xA3C580) failed decompilation — symbol not found (inline/stripped).
 * Methods: Set, GetKeyQuatNew, i_LerpQuat (failed).
 */

/* ---- nuccAnmKey_QuaternionTbl ----
 * Only 2 methods in s4 (below threshold).
 * i_LookupQuat (0xA3C700) failed decompilation — symbol not found (inline/stripped).
 */

/* ---- nuccAnmKey_QuaternionI16TblBase ----
 * No instance state detected by state_surface (byte-cast-only accesses).
 * Listed as comment-only, same as s3.
 */

/* ---- nuccAnmKey_Vector3I16Liner ----
 * Only 1 method in s4 (below threshold). No struct.
 */

/* ---- nuccAnmKey_Vector3Liner ----
 * Only 1 method in s4 (below threshold). No struct.
 */

/* ---- nuccAnmMiddle::ParticleHandler ----
 * Only 1 method (SearchCoord) in s4 (below threshold). No struct.
 */

#endif /* CMN43_S4_H */