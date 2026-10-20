/* cmn53 s2 — NARUTO STORM 2 PC (NSUNS2.exe, sha abf2b6)
 * Struct layouts INFERRED from static analysis; not CONFIRMED at runtime.
 * All offsets are PC x64 (image base 0x140000000).
 * Own-game names only (ns2:: namespace / Storm 2 strings).
 */

#ifndef CMN53_S2_H
#define CMN53_S2_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nuccEffectSimpleAnm
 * Size: 0x1A8 (proven by ccFileLoadListForUi::LoadTh(0x1a8,...) at RVA 0x5C8030)
 * Vtable: 0x1408947c0 (set in ctor at RVA 0x5C7F20)
 * Base class: nuccEffectRoot (inferred from ctor calling nuccEffectRoot::nuccEffectRoot())
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccEffectSimpleAnm {
    /* 0x000 */ void *vtable;              /* = 0x1408947c0 */
    /* 0x008 */ uint8_t base_block[0x138]; /* nuccEffectRoot base (opaque) */
    /* 0x140 */ int32_t field_0x140;       /* state_surface read in Ctrl */
    /* 0x144 */ uint8_t pad_0x144[8];      /* gap to 0x14C */
    /* 0x14C */ int32_t field_0x14c;       /* state_surface read in Ctrl */
    /* 0x150 */ uint8_t pad_0x150[0x10];   /* gap to 0x160 */
    /* 0x160 */ int64_t field_0x160;       /* state_surface */
    /* 0x168 */ int64_t anm_data_ptr;      /* SIM: pointer to animation data */
    /* 0x170 */ int64_t field_0x170;       /* state_surface */
    /* 0x178 */ uint8_t pad_0x178[4];      /* gap to 0x17C */
    /* 0x17C */ float scale_factor;        /* ctor writes 0x3f800000 (1.0f) */
    /* 0x180 */ float time_delta;          /* state_surface */
    /* 0x184 */ float time_accumulator;    /* state_surface read in Ctrl */
    /* 0x188 */ int32_t enable_flag;       /* state_surface */
    /* 0x18C */ uint8_t pad_0x18c[4];      /* gap to 0x190 */
    /* 0x190 */ int64_t field_0x190;       /* state_surface */
    /* 0x198 */ int64_t field_0x198;       /* state_surface */
    /* 0x1A0 */ int64_t field_0x1a0;       /* state_surface */
} ns2_nuccEffectSimpleAnm;

_Static_assert(sizeof(ns2_nuccEffectSimpleAnm) == 0x1A8, "ns2_nuccEffectSimpleAnm size must be 0x1A8");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, vtable) == 0x000, "vtable offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, base_block) == 0x008, "base_block offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x140) == 0x140, "field_0x140 offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x14c) == 0x14C, "field_0x14c offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x160) == 0x160, "field_0x160 offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, anm_data_ptr) == 0x168, "anm_data_ptr offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x170) == 0x170, "field_0x170 offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, scale_factor) == 0x17C, "scale_factor offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, time_delta) == 0x180, "time_delta offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, time_accumulator) == 0x184, "time_accumulator offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, enable_flag) == 0x188, "enable_flag offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x190) == 0x190, "field_0x190 offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x198) == 0x198, "field_0x198 offset");
_Static_assert(offsetof(ns2_nuccEffectSimpleAnm, field_0x1a0) == 0x1A0, "field_0x1a0 offset");

/* =========================================================================
 * nuccFCurveManager
 * Size: 0x28 (proven by ccFileLoadListForUi::LoadTh(0x28,...) at RVA 0x5C8740)
 * Vtable: 0x140894960 (set in Create at RVA 0x5C8740)
 * Fields: 5 total, fully covers 0x00–0x27
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccFCurveManager {
    /* 0x00 */ void *vtable;         /* = 0x140894960 */
    /* 0x08 */ int32_t fcurve_index; /* init 0xFFFFFFFF in Create */
    /* 0x0C */ uint32_t pad_0x0c;
    /* 0x10 */ void *fcurve_obj_1;   /* zeroed in Create */
    /* 0x18 */ void *fcurve_obj_2;   /* zeroed in Create */
    /* 0x20 */ void *fcurve_obj_3;   /* zeroed in Create */
} ns2_nuccFCurveManager;

_Static_assert(sizeof(ns2_nuccFCurveManager) == 0x28, "ns2_nuccFCurveManager size must be 0x28");
_Static_assert(offsetof(ns2_nuccFCurveManager, vtable) == 0x00, "vtable offset");
_Static_assert(offsetof(ns2_nuccFCurveManager, fcurve_index) == 0x08, "fcurve_index offset");
_Static_assert(offsetof(ns2_nuccFCurveManager, fcurve_obj_1) == 0x10, "fcurve_obj_1 offset");
_Static_assert(offsetof(ns2_nuccFCurveManager, fcurve_obj_2) == 0x18, "fcurve_obj_2 offset");
_Static_assert(offsetof(ns2_nuccFCurveManager, fcurve_obj_3) == 0x20, "fcurve_obj_3 offset");

/* =========================================================================
 * nuccFCurveSceneEffect
 * Size: unknown, >= 0x154 (ctor writes uint32 at offset 0x150; no allocator size found)
 * Vtable: 0x1408921b0 (set in ctor at RVA 0x5ABC70)
 * Fields: 3 named; large gap between fcurve_values end (0xAC) and scene_effect_type (0x150)
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccFCurveSceneEffect {
    /* 0x000 */ void *vtable;                /* = 0x1408921b0 */
    /* 0x008 */ int32_t fcurve_values[0x29]; /* cleared/init loop in ctor, 0x29 slots */
    /* 0x0AC */ uint8_t gap_0xac[0xA4];      /* unaccounted 0xA4 bytes */
    /* 0x150 */ int32_t scene_effect_type;   /* written as *(param_1+0x2a)=param_2 in ctor */
    /* 0x154 */ uint8_t tail_unknown[0];     /* size beyond 0x154 unproven */
} ns2_nuccFCurveSceneEffect;

/* No sizeof assert: size is unproven beyond 0x154 */
_Static_assert(offsetof(ns2_nuccFCurveSceneEffect, vtable) == 0x000, "vtable offset");
_Static_assert(offsetof(ns2_nuccFCurveSceneEffect, fcurve_values) == 0x008, "fcurve_values offset");
_Static_assert(offsetof(ns2_nuccFCurveSceneEffect, gap_0xac) == 0x0AC, "gap_0xac offset");
_Static_assert(offsetof(ns2_nuccFCurveSceneEffect, scene_effect_type) == 0x150, "scene_effect_type offset");

/* =========================================================================
 * nuccFCurveBase
 * Size: 0xA0 (proven by ccFileLoadListForUi::LoadTh(0xa0,...) in factory at RVA 0x613840)
 * Vtable: 0x14089b758 (set in factory at RVA 0x613840)
 * Base class: none identified (root of FCurve hierarchy)
 * Fields: 3 named + padding; covers full 0xA0
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ns2_nuccFCurveBase {
    /* 0x00 */ void *vtable;            /* = 0x14089b758 */
    /* 0x08 */ uint32_t fcurve_type;    /* init 0xFFFFFFFF in factory; ParseBasicParam reads via vtable+0x18 */
    /* 0x0C */ int32_t version;         /* ParseBasicParam writes atoi("ver_N") here */
    /* 0x10 */ uint8_t pad_0x10[0x90]; /* gap to end of 0xA0 allocation */
} ns2_nuccFCurveBase;
#pragma pack(pop)

_Static_assert(sizeof(ns2_nuccFCurveBase) == 0xA0, "ns2_nuccFCurveBase size must be 0xA0");
_Static_assert(offsetof(ns2_nuccFCurveBase, vtable) == 0x00, "vtable offset");
_Static_assert(offsetof(ns2_nuccFCurveBase, fcurve_type) == 0x08, "fcurve_type offset");
_Static_assert(offsetof(ns2_nuccFCurveBase, version) == 0x0C, "version offset");
_Static_assert(offsetof(ns2_nuccFCurveBase, pad_0x10) == 0x10, "pad_0x10 offset");

#endif /* CMN53_S2_H */