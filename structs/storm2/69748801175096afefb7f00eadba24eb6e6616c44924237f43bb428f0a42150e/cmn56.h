/* cmn56.h — s2 (NSUNS2.exe) nucc* struct layouts
 * Generated from Ghidra decompilation (the decompiler cache cache).
 * All fields INFERRED, not CONFIRMED. PC offsets only.
 * Own-game namespace: ns2::
 * Build: s2 / NSUNS2.exe-abf2b6 / sha 697488011750
 */

#ifndef CMN56_S2_H
#define CMN56_S2_H

#include <stdint.h>
#include <stddef.h>

/* ── nuccLayerBase ───────────────────────────────────────────────
 * Vtable: 0x140898aa8 (from ctor PTR_FUN_140898aa8)
 * Size: >= 0x28 (no operator-new proof found)
 * Evidence: nuccLayerBase::nuccLayerBase @ 0x601CA0
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void *vtable;             /* set to &PTR_FUN_140898aa8 in ctor */
    /* +0x08 */ char name[16];            /* string copy loop in ctor, null-terminated */
    /* +0x18 */ uint32_t type_id;         /* *(param_1+3) = param_3 */
    /* +0x1C */ uint16_t field_1C;        /* zeroed in ctor */
    /* +0x1E */ uint8_t field_1E;         /* zeroed in ctor */
    /* +0x1F */ uint8_t _pad_1F[5];      /* gap to +0x24 */
    /* +0x24 */ uint32_t field_24;        /* set to 1 in ctor */
} ns2_nuccLayerBase;

_Static_assert(offsetof(ns2_nuccLayerBase, vtable) == 0x00, "ns2_nuccLayerBase.vtable");
_Static_assert(offsetof(ns2_nuccLayerBase, name) == 0x08, "ns2_nuccLayerBase.name");
_Static_assert(offsetof(ns2_nuccLayerBase, type_id) == 0x18, "ns2_nuccLayerBase.type_id");
_Static_assert(offsetof(ns2_nuccLayerBase, field_1C) == 0x1C, "ns2_nuccLayerBase.field_1C");
_Static_assert(offsetof(ns2_nuccLayerBase, field_1E) == 0x1E, "ns2_nuccLayerBase.field_1E");
_Static_assert(offsetof(ns2_nuccLayerBase, field_24) == 0x24, "ns2_nuccLayerBase.field_24");
_Static_assert(sizeof(ns2_nuccLayerBase) == 0x28, "ns2_nuccLayerBase size");

/* ── nuccLayer ───────────────────────────────────────────────────
 * Inherits nuccLayerBase (ctor calls base with type_id=2).
 * Vtable: 0x140894df8 (overrides base vtable)
 * Size: >= 0x50 (no operator-new proof found)
 * Evidence: nuccLayer::nuccLayer @ 0x5CDE60
 * s2-specific: field at +0x3C written conditionally in ctor
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ ns2_nuccLayerBase base;   /* inherits base layout */
    /* +0x28 */ void *field_28;           /* param_1[5] = param_3 */
    /* +0x30 */ uint32_t field_30;        /* param_1[6], zeroed twice */
    /* +0x34 */ int32_t field_34;         /* read in ctor: if(*(int*)(p+0x34)==0) */
    /* +0x38 */ uint32_t field_38_lo;     /* low half of param_1[7], zeroed */
    /* +0x3C */ uint32_t field_3C;        /* NEW in s2: conditional write uVar2 */
    /* +0x40 */ void *field_40;           /* puVar1 = param_1+8, *puVar1=0 */
    /* +0x48 */ void *field_48;           /* param_1[9] = puVar1 (self-ptr to +0x40) */
} ns2_nuccLayer;

_Static_assert(offsetof(ns2_nuccLayer, base) == 0x00, "ns2_nuccLayer.base");
_Static_assert(offsetof(ns2_nuccLayer, field_28) == 0x28, "ns2_nuccLayer.field_28");
_Static_assert(offsetof(ns2_nuccLayer, field_30) == 0x30, "ns2_nuccLayer.field_30");
_Static_assert(offsetof(ns2_nuccLayer, field_34) == 0x34, "ns2_nuccLayer.field_34");
_Static_assert(offsetof(ns2_nuccLayer, field_38_lo) == 0x38, "ns2_nuccLayer.field_38_lo");
_Static_assert(offsetof(ns2_nuccLayer, field_3C) == 0x3C, "ns2_nuccLayer.field_3C");
_Static_assert(offsetof(ns2_nuccLayer, field_40) == 0x40, "ns2_nuccLayer.field_40");
_Static_assert(offsetof(ns2_nuccLayer, field_48) == 0x48, "ns2_nuccLayer.field_48");
_Static_assert(sizeof(ns2_nuccLayer) == 0x50, "ns2_nuccLayer size");

/* ── nuccLayerList ───────────────────────────────────────────────
 * Inherits nuccLayerBase (ctor calls base with type_id=3).
 * Vtable: 0x140898c88 (overrides base vtable)
 * Size: >= 0x28 (sub-object at +0x28 via FUN_140601d20; total size unknown)
 * Evidence: nuccLayerList::nuccLayerList @ 0x601D90
 * state_surface found vtable dispatches at +0xC0 and +0x100 in Entry/Release
 * but these are likely sub-object internal offsets, not direct fields.
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ ns2_nuccLayerBase base;
    /* +0x28 */ uint8_t sub_object[1];    /* FUN_140601d20(param_1+5); size unknown */
    /* remaining layout unknown -- vtable dispatches suggest sub-object extends far */
} ns2_nuccLayerList;

_Static_assert(offsetof(ns2_nuccLayerList, base) == 0x00, "ns2_nuccLayerList.base");
_Static_assert(offsetof(ns2_nuccLayerList, sub_object) == 0x28, "ns2_nuccLayerList.sub_object");

/* ── nuccInstanceList ────────────────────────────────────────────
 * No vtable observed (base init FUN_1405dbd20 sets no vtable).
 * Size: >= 0x48 (fields zeroed up to +0x40 inclusive = 8 bytes -> last byte at +0x47)
 * Evidence: nuccInstanceList::nuccInstanceList @ 0x5DBD90
 * s1 had field_90 at +0x90 from DeleteInstanceAll -- not yet confirmed in s2.
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ uint8_t base_data[0x28];  /* initialized by FUN_1405dbd20(), layout unknown */
    /* +0x28 */ uint64_t field_28;        /* zeroed in ctor */
    /* +0x30 */ uint64_t field_30;        /* zeroed in ctor */
    /* +0x38 */ uint64_t field_38;        /* zeroed in ctor */
    /* +0x40 */ uint64_t field_40;        /* zeroed in ctor */
} ns2_nuccInstanceList;

_Static_assert(offsetof(ns2_nuccInstanceList, base_data) == 0x00, "ns2_nuccInstanceList.base_data");
_Static_assert(offsetof(ns2_nuccInstanceList, field_28) == 0x28, "ns2_nuccInstanceList.field_28");
_Static_assert(offsetof(ns2_nuccInstanceList, field_30) == 0x30, "ns2_nuccInstanceList.field_30");
_Static_assert(offsetof(ns2_nuccInstanceList, field_38) == 0x38, "ns2_nuccInstanceList.field_38");
_Static_assert(offsetof(ns2_nuccInstanceList, field_40) == 0x40, "ns2_nuccInstanceList.field_40");
_Static_assert(sizeof(ns2_nuccInstanceList) == 0x48, "ns2_nuccInstanceList size");

/* ── nuccLayerDrawCmdExecuter ────────────────────────────────────
 * No vtable (not a polymorphic class).
 * Size: >= 0x68 (syncpoint context at +0x60 accessed in dtor/Execute)
 * Thread element stride: 0x118 (confirmed in dtor and Execute loops)
 * Evidence: ~dtor @ 0x5CDF30, Execute @ 0x5CE750
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void *thread_array;       /* *param_1, freed in dtor */
    /* +0x08 */ uint8_t thread_count;     /* *(byte*)(param_1+1), loop bound */
    /* +0x09 */ uint8_t _pad_09[3];      /* gap to +0x0C */
    /* +0x0C */ uint32_t active_mask;     /* rw bitmask in Execute, passed to syncpoint */
    /* +0x10 */ uint8_t critical_section[0x50]; /* param_1+2, FUN_1405ac130/FUN_1405ac0b0 */
    /* +0x60 */ uint8_t syncpoint_ctx[8]; /* param_1+0xc, FUN_14015b880/FUN_14055c1f0 */
} ns2_nuccLayerDrawCmdExecuter;

_Static_assert(offsetof(ns2_nuccLayerDrawCmdExecuter, thread_array) == 0x00, "ns2_nuccLayerDrawCmdExecuter.thread_array");
_Static_assert(offsetof(ns2_nuccLayerDrawCmdExecuter, thread_count) == 0x08, "ns2_nuccLayerDrawCmdExecuter.thread_count");
_Static_assert(offsetof(ns2_nuccLayerDrawCmdExecuter, active_mask) == 0x0C, "ns2_nuccLayerDrawCmdExecuter.active_mask");
_Static_assert(offsetof(ns2_nuccLayerDrawCmdExecuter, critical_section) == 0x10, "ns2_nuccLayerDrawCmdExecuter.critical_section");
_Static_assert(offsetof(ns2_nuccLayerDrawCmdExecuter, syncpoint_ctx) == 0x60, "ns2_nuccLayerDrawCmdExecuter.syncpoint_ctx");
_Static_assert(sizeof(ns2_nuccLayerDrawCmdExecuter) == 0x68, "ns2_nuccLayerDrawCmdExecuter size");

/* ── nuccFrameBufferSampling ─────────────────────────────────────
 * Singleton pattern (CreateInstance/GetInstance/DeleteInstance).
 * No instance fields observed via param_1 in any method.
 * No struct layout reconstructed.
 */

#endif /* CMN56_S2_H */