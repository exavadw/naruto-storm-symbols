/*
 * cmn53 s4 — Struct layouts for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe)
 * Build: s4 (sha 147e52a3e0d7 / 75912b)
 * Date: 2026-10-19
 * All layouts INFERRED from static analysis; not CONFIRMED at runtime.
 *
 * Group: nuccEffectSimpleAnm, nuccExtObj, nuccFCurveBase,
 *        nuccFCurveColorFilterDirectional, nuccFCurveColorFilterRadial,
 *        nuccFCurveControlBlock, nuccFCurveFog, nuccFCurveManager,
 *        nuccFCurveOMB, nuccFCurveOutlineGlare2, nuccFCurveSceneEffect,
 *        nuccFCurveStepConv
 */

#ifndef CMN53_S4_H
#define CMN53_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccFCurveManager
 * Size: 0x28 (proven by FUN_140a017f0(0x28,...) in both Create overloads
 *        at RVA 0xA511B0 and 0xA51280)
 * Vtable: 0x14110acc8 (set in Create at RVA 0xA511B0/0xA51280)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveManager {
    uint64_t vtable;            /* 0x00 */
    uint32_t fcurve_index;      /* 0x08 - init 0xFFFFFFFF */
    uint32_t _pad_0c;           /* 0x0C */
    uint64_t fcurve_obj;        /* 0x10 - nuccFcvCreateFCurve result */
    uint64_t parent_ptr;        /* 0x18 - param_1 + 0x30 */
    uint64_t manager_backref;   /* 0x20 - *(param_1 + 0x50) */
} nuccFCurveManager;

static_assert(sizeof(nuccFCurveManager) == 0x28, "nuccFCurveManager size");
static_assert(offsetof(nuccFCurveManager, vtable) == 0x00, "nuccFCurveManager::vtable");
static_assert(offsetof(nuccFCurveManager, fcurve_index) == 0x08, "nuccFCurveManager::fcurve_index");
static_assert(offsetof(nuccFCurveManager, _pad_0c) == 0x0C, "nuccFCurveManager::_pad_0c");
static_assert(offsetof(nuccFCurveManager, fcurve_obj) == 0x10, "nuccFCurveManager::fcurve_obj");
static_assert(offsetof(nuccFCurveManager, parent_ptr) == 0x18, "nuccFCurveManager::parent_ptr");
static_assert(offsetof(nuccFCurveManager, manager_backref) == 0x20, "nuccFCurveManager::manager_backref");

/* =========================================================================
 * nuccEffectSimpleAnm
 * Size: 0x1A8 (proven by FUN_140a017f0(0x1a8,...) in factory at RVA 0xA4E770)
 * Vtable: 0x141109b18 (set in ctor at RVA 0xA4E690)
 * Base class: nuccEffectRoot (inferred from ctor chain)
 * Fields below start after base class layout (0x00-0x15F opaque).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccEffectSimpleAnm {
    uint8_t  base_block[0x160];     /* 0x000 - nuccEffectRoot base (opaque) */
    uint64_t field_0x160;           /* 0x160 - zeroed in ctor */
    uint64_t anm_data_ptr;          /* 0x168 - SIM: animation data ptr */
    uint64_t field_0x170;           /* 0x170 - zeroed in ctor */
    int32_t  field_0x178;           /* 0x178 - init 0xFFFFFFFF (-1) */
    float    scale_factor;          /* 0x17C - init 1.0 (0x3f800000) */
    float    time_delta;            /* 0x180 - init 1.0 (0x3f800000) */
    uint32_t _pad_0x184;            /* 0x184 */
    uint64_t enable_flag;           /* 0x188 - init 1 */
    uint32_t field_0x190;           /* 0x190 - zeroed in ctor */
    uint32_t _pad_0x194;            /* 0x194 */
    uint64_t field_0x198;           /* 0x198 - zeroed in ctor */
    uint64_t field_0x1a0;           /* 0x1A0 - zeroed in ctor */
} nuccEffectSimpleAnm;

static_assert(sizeof(nuccEffectSimpleAnm) == 0x1A8, "nuccEffectSimpleAnm size");
static_assert(offsetof(nuccEffectSimpleAnm, base_block) == 0x000, "nuccEffectSimpleAnm::base_block");
static_assert(offsetof(nuccEffectSimpleAnm, field_0x160) == 0x160, "nuccEffectSimpleAnm::field_0x160");
static_assert(offsetof(nuccEffectSimpleAnm, anm_data_ptr) == 0x168, "nuccEffectSimpleAnm::anm_data_ptr");
static_assert(offsetof(nuccEffectSimpleAnm, field_0x170) == 0x170, "nuccEffectSimpleAnm::field_0x170");
static_assert(offsetof(nuccEffectSimpleAnm, field_0x178) == 0x178, "nuccEffectSimpleAnm::field_0x178");
static_assert(offsetof(nuccEffectSimpleAnm, scale_factor) == 0x17C, "nuccEffectSimpleAnm::scale_factor");
static_assert(offsetof(nuccEffectSimpleAnm, time_delta) == 0x180, "nuccEffectSimpleAnm::time_delta");
static_assert(offsetof(nuccEffectSimpleAnm, _pad_0x184) == 0x184, "nuccEffectSimpleAnm::_pad_0x184");
static_assert(offsetof(nuccEffectSimpleAnm, enable_flag) == 0x188, "nuccEffectSimpleAnm::enable_flag");
static_assert(offsetof(nuccEffectSimpleAnm, field_0x190) == 0x190, "nuccEffectSimpleAnm::field_0x190");
static_assert(offsetof(nuccEffectSimpleAnm, _pad_0x194) == 0x194, "nuccEffectSimpleAnm::_pad_0x194");
static_assert(offsetof(nuccEffectSimpleAnm, field_0x198) == 0x198, "nuccEffectSimpleAnm::field_0x198");
static_assert(offsetof(nuccEffectSimpleAnm, field_0x1a0) == 0x1A0, "nuccEffectSimpleAnm::field_0x1a0");

/* =========================================================================
 * nuccFCurveSceneEffect
 * Size: unknown, >= 0x680 (state_surface shows rw field at offset 0x678;
 *        no allocator size found in Create/CreateSceneEffect/SearchBinary).
 * Vtable: 0x1411072b0 (set in ctor at RVA 0xA29D40)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveSceneEffect {
    uint64_t vtable;                /* 0x000 */
    uint8_t  gap_0x08[0xA4];        /* 0x008 - unaccounted gap */
    int32_t  fcurve_values[0x29];   /* 0x0AC - array cleared in ctor loop (0x29 ints) */
    uint32_t scene_effect_type;     /* 0x150 - written as param_2 in ctor */
    uint8_t  gap_0x154[0x3A4];      /* 0x154 - gap to state_surface fields */
    uint64_t field_0x4f8;           /* 0x4F8 - read in Disable<> (ptr-like) */
    uint64_t field_0x500;           /* 0x500 - end ptr for field_0x4f8 iteration */
    uint8_t  gap_0x508[0x170];      /* 0x508 - gap to last known field */
    uint64_t field_0x678;           /* 0x678 - rw, checked in CreateSceneEffect */
} nuccFCurveSceneEffect;

/* Size not proven beyond 0x680; sizeof would be misleading. No static_assert on size. */
static_assert(offsetof(nuccFCurveSceneEffect, vtable) == 0x000, "nuccFCurveSceneEffect::vtable");
static_assert(offsetof(nuccFCurveSceneEffect, gap_0x08) == 0x008, "nuccFCurveSceneEffect::gap_0x08");
static_assert(offsetof(nuccFCurveSceneEffect, fcurve_values) == 0x0AC, "nuccFCurveSceneEffect::fcurve_values");
static_assert(offsetof(nuccFCurveSceneEffect, scene_effect_type) == 0x150, "nuccFCurveSceneEffect::scene_effect_type");
static_assert(offsetof(nuccFCurveSceneEffect, gap_0x154) == 0x154, "nuccFCurveSceneEffect::gap_0x154");
static_assert(offsetof(nuccFCurveSceneEffect, field_0x4f8) == 0x4F8, "nuccFCurveSceneEffect::field_0x4f8");
static_assert(offsetof(nuccFCurveSceneEffect, field_0x500) == 0x500, "nuccFCurveSceneEffect::field_0x500");
static_assert(offsetof(nuccFCurveSceneEffect, gap_0x508) == 0x508, "nuccFCurveSceneEffect::gap_0x508");
static_assert(offsetof(nuccFCurveSceneEffect, field_0x678) == 0x678, "nuccFCurveSceneEffect::field_0x678");

/* =========================================================================
 * Classes with < 3 methods — listed only, no instance state reconstructed.
 * Evidence insufficient for field layout in this build.
 *
 * nuccFCurveBase              (2 methods) — base class for FCurve hierarchy
 * nuccExtObj                  (1 method)  — external object reference
 * nuccFCurveColorFilterDirectional (1 method) — directional color filter FCurve
 * nuccFCurveColorFilterRadial      (1 method) — radial color filter FCurve
 * nuccFCurveControlBlock           (1 method) — FCurve control block
 * nuccFCurveFog                    (1 method) — fog FCurve
 * nuccFCurveOMB                    (1 method) — OMB FCurve
 * nuccFCurveOutlineGlare2          (1 method) — outline glare FCurve variant
 * nuccFCurveStepConv               (1 method) — step conversion FCurve
 * ========================================================================= */

#endif /* CMN53_S4_H */