/* cmn53.h — Storm 1 (s1) struct group cmn53
 * Reconstructed from NSUNS1.exe x64 decompilation.
 * All layouts INFERRED from static analysis; not CONFIRMED at runtime.
 * Field names from decompiled ctor/method evidence only (no reliable Trilogy BSim match).
 * PC offsets only; Switch Trilogy used for name hints only.
 */
#ifndef CMN53_S1_H
#define CMN53_S1_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nuccEffectSimpleAnm
 * Size: 0x1A8 (proven by ccFileLoadListForUi::LoadTh(0x1a8,...) in factory 0x4B8D10)
 * Vtable: 0x14073a418 (set in ctor 0x4B8B40)
 * Base: nuccEffectRoot
 * Methods: 12
 * Fields: 16 from state_surface + ctor analysis
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccEffectSimpleAnm {
    /* 0x000 */ void *vtable;                    /* vtable ptr, set to 0x14073a418 in ctor */
    /* 0x008 */ uint8_t base[0x138];             /* nuccEffectRoot base class (inferred, size from offset gap) */
    /* 0x140 */ uint32_t flags;                  /* rw, Init sets bit 0x10000; offset 0x140 from state_surface */
    /* 0x144 */ uint8_t pad_144[8];              /* padding to 0x14C */
    /* 0x14C */ int32_t anm_id;                  /* r, compared against field_0x178 in Ctrl */
    /* 0x150 */ uint8_t pad_150[12];             /* padding to 0x15C */
    /* 0x15C */ uint8_t pad_15c[4];              /* padding to 0x160 */
    /* 0x160 */ uint64_t field_0x160;            /* w-only, zeroed in ctor (param_1[0x2c]=0) */
    /* 0x168 */ uint64_t anm_data_ptr;           /* rw, pointer checked for null in Ctrl/CreateAnm */
    /* 0x170 */ uint64_t field_0x170;            /* rw, set in CreateAnm (param_1[0x2e]) */
    /* 0x178 */ int32_t current_anm_id;          /* rw, compared with anm_id in Ctrl */
    /* 0x17C */ float scale_factor;              /* w, initialized to 1.0f (0x3f800000) in ctor */
    /* 0x180 */ float time_delta;                /* rw, float arithmetic in Ctrl */
    /* 0x184 */ float time_accumulator;          /* r, subtracted from time_delta in Ctrl */
    /* 0x188 */ uint64_t enable_flag;            /* rw, tested != 0 in Ctrl (param_1[0x31]) */
    /* 0x190 */ uint32_t field_0x190;            /* w, zeroed in ctor (param_1[0x32]=0) */
    /* 0x194 */ uint8_t pad_194[4];              /* padding to 0x198 */
    /* 0x198 */ uint64_t field_0x198;            /* w, zeroed in ctor (param_1[0x33]=0) */
    /* 0x1A0 */ uint64_t field_0x1a0;            /* w, zeroed in ctor (param_1[0x34]=0) */
    /* Total: 0x1A8 */
} nuccEffectSimpleAnm;

_Static_assert(offsetof(nuccEffectSimpleAnm, vtable) == 0x000, "nuccEffectSimpleAnm::vtable");
_Static_assert(offsetof(nuccEffectSimpleAnm, flags) == 0x140, "nuccEffectSimpleAnm::flags");
_Static_assert(offsetof(nuccEffectSimpleAnm, anm_id) == 0x14C, "nuccEffectSimpleAnm::anm_id");
_Static_assert(offsetof(nuccEffectSimpleAnm, field_0x160) == 0x160, "nuccEffectSimpleAnm::field_0x160");
_Static_assert(offsetof(nuccEffectSimpleAnm, anm_data_ptr) == 0x168, "nuccEffectSimpleAnm::anm_data_ptr");
_Static_assert(offsetof(nuccEffectSimpleAnm, field_0x170) == 0x170, "nuccEffectSimpleAnm::field_0x170");
_Static_assert(offsetof(nuccEffectSimpleAnm, current_anm_id) == 0x178, "nuccEffectSimpleAnm::current_anm_id");
_Static_assert(offsetof(nuccEffectSimpleAnm, scale_factor) == 0x17C, "nuccEffectSimpleAnm::scale_factor");
_Static_assert(offsetof(nuccEffectSimpleAnm, time_delta) == 0x180, "nuccEffectSimpleAnm::time_delta");
_Static_assert(offsetof(nuccEffectSimpleAnm, time_accumulator) == 0x184, "nuccEffectSimpleAnm::time_accumulator");
_Static_assert(offsetof(nuccEffectSimpleAnm, enable_flag) == 0x188, "nuccEffectSimpleAnm::enable_flag");
_Static_assert(offsetof(nuccEffectSimpleAnm, field_0x190) == 0x190, "nuccEffectSimpleAnm::field_0x190");
_Static_assert(offsetof(nuccEffectSimpleAnm, field_0x198) == 0x198, "nuccEffectSimpleAnm::field_0x198");
_Static_assert(offsetof(nuccEffectSimpleAnm, field_0x1a0) == 0x1A0, "nuccEffectSimpleAnm::field_0x1a0");
_Static_assert(sizeof(nuccEffectSimpleAnm) == 0x1A8, "nuccEffectSimpleAnm size");

/* =========================================================================
 * nuccFCurveSceneEffect
 * Size: unknown, >= 0x154 (ctor writes uint32 at offset 0x150; no allocator size found)
 * Vtable: 0x14073a0e0 (set in ctor 0x4B48C0)
 * Methods: 11
 * Fields: 2 from state_surface + ctor loop analysis
 * Ctor clears 0x29 uint32s starting at +0x8 (offsets 0x08..0xAC), then writes param_2 at +0x150
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveSceneEffect {
    /* 0x000 */ void *vtable;                    /* vtable ptr, set to 0x14073a0e0 in ctor */
    /* 0x008 */ uint32_t fcurve_values[0x29];    /* cleared to 0xFFFFFFFF in ctor loop, then alternating 0xFFFFFFFF/1 pattern */
    /* 0x0AC */ uint8_t pad_0ac[0xA4];           /* gap between loop end and field_0x150 */
    /* 0x150 */ uint32_t scene_effect_type;      /* w, set from ctor param_2 */
    /* Total: >= 0x154 (size unproven beyond this point) */
} nuccFCurveSceneEffect;

_Static_assert(offsetof(nuccFCurveSceneEffect, vtable) == 0x000, "nuccFCurveSceneEffect::vtable");
_Static_assert(offsetof(nuccFCurveSceneEffect, fcurve_values) == 0x008, "nuccFCurveSceneEffect::fcurve_values");
_Static_assert(offsetof(nuccFCurveSceneEffect, scene_effect_type) == 0x150, "nuccFCurveSceneEffect::scene_effect_type");
/* No sizeof assert: size unproven beyond 0x154 */

/* =========================================================================
 * nuccFCurveManager
 * Size: 0x28 (proven by ccFileLoadListForUi::LoadTh(0x28,...) in Create 0x4B9790)
 * Vtable: 0x14073a618 (set in Create 0x4B9790)
 * Methods: 4
 * Fields: 4 from Create decompilation
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveManager {
    /* 0x00 */ void *vtable;                     /* vtable ptr, set to 0x14073a618 */
    /* 0x08 */ uint32_t fcurve_index;            /* initialized to 0xFFFFFFFF in Create */
    /* 0x0C */ uint8_t pad_0c[4];                /* padding to 0x10 */
    /* 0x10 */ uint64_t fcurve_obj_1;            /* zeroed in Create (puVar1[2]=0) */
    /* 0x18 */ uint64_t fcurve_obj_2;            /* zeroed in Create (puVar1[3]=0) */
    /* 0x20 */ uint64_t fcurve_obj_3;            /* zeroed in Create (puVar1[4]=0) */
    /* Total: 0x28 */
} nuccFCurveManager;

_Static_assert(offsetof(nuccFCurveManager, vtable) == 0x00, "nuccFCurveManager::vtable");
_Static_assert(offsetof(nuccFCurveManager, fcurve_index) == 0x08, "nuccFCurveManager::fcurve_index");
_Static_assert(offsetof(nuccFCurveManager, fcurve_obj_1) == 0x10, "nuccFCurveManager::fcurve_obj_1");
_Static_assert(offsetof(nuccFCurveManager, fcurve_obj_2) == 0x18, "nuccFCurveManager::fcurve_obj_2");
_Static_assert(offsetof(nuccFCurveManager, fcurve_obj_3) == 0x20, "nuccFCurveManager::fcurve_obj_3");
_Static_assert(sizeof(nuccFCurveManager) == 0x28, "nuccFCurveManager size");

#endif /* CMN53_S1_H */