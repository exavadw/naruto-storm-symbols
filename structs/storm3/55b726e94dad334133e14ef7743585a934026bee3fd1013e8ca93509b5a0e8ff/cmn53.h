/*
 * cmn53 s3 — Struct layouts for NARUTO STORM 3 Full Burst HD (NSUNS3.exe, 64-bit)
 * Build: s3 (sha 55b726e94dad / a7124b)
 * Date: 2026-10-19
 * All layouts INFERRED from static analysis; not CONFIRMED at runtime.
 *
 * Group: nuccEffectSimpleAnm, nuccExtObj, nuccFCurveBase,
 *        nuccFCurveColorFilterDirectional, nuccFCurveColorFilterRadial,
 *        nuccFCurveControlBlock, nuccFCurveFog, nuccFCurveManager,
 *        nuccFCurveOMB, nuccFCurveOutlineGlare2, nuccFCurveSceneEffect,
 *        nuccFCurveStepConv
 */

#ifndef CMN53_S3_H
#define CMN53_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ns3_nuccFCurveManager
 * Size: 0x28 (proven by ccFileLoadListForUi::LoadTh(0x28,...) in both
 *        Create overloads at RVA 0x6CD5C0 and 0x6CD690)
 * Vtable: 0x1409e2f20 (set in Create at RVA 0x6CD5C0/0x6CD690)
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_nuccFCurveManager {
    uint64_t vtable;            /* 0x00 */
    uint32_t fcurve_index;      /* 0x08 - init 0xFFFFFFFF */
    uint32_t _pad_0c;           /* 0x0C */
    uint64_t fcurve_obj;        /* 0x10 - nuccFcvCreateFCurve result */
    uint64_t parent_ptr;        /* 0x18 - param_1 + 0x30 */
    uint64_t manager_backref;   /* 0x20 - *(param_1 + 0x50) */
} ns3_nuccFCurveManager;

static_assert(sizeof(ns3_nuccFCurveManager) == 0x28, "ns3_nuccFCurveManager size");
static_assert(offsetof(ns3_nuccFCurveManager, vtable) == 0x00, "ns3_nuccFCurveManager::vtable");
static_assert(offsetof(ns3_nuccFCurveManager, fcurve_index) == 0x08, "ns3_nuccFCurveManager::fcurve_index");
static_assert(offsetof(ns3_nuccFCurveManager, _pad_0c) == 0x0C, "ns3_nuccFCurveManager::_pad_0c");
static_assert(offsetof(ns3_nuccFCurveManager, fcurve_obj) == 0x10, "ns3_nuccFCurveManager::fcurve_obj");
static_assert(offsetof(ns3_nuccFCurveManager, parent_ptr) == 0x18, "ns3_nuccFCurveManager::parent_ptr");
static_assert(offsetof(ns3_nuccFCurveManager, manager_backref) == 0x20, "ns3_nuccFCurveManager::manager_backref");

/* =========================================================================
 * ns3_nuccEffectSimpleAnm
 * Size: 0x1A8 (proven by FUN_140683f70(0x1a8,...) in factory at RVA 0x6C1F20)
 * Vtable: 0x1409e0c08 (set in ctor at RVA 0x6C1E40)
 * Base class: nuccEffectRoot (inferred from ctor chain)
 * Fields below start after base class layout (0x00-0x15F opaque).
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_nuccEffectSimpleAnm {
    uint8_t  base_block[0x160];     /* 0x000 - nuccEffectRoot base (opaque) */
    uint64_t field_0x160;           /* 0x160 - zeroed in ctor */
    uint64_t anm_data_ptr;          /* 0x168 - SIM: animation data ptr, null-checked in Ctrl/CreateAnm */
    uint64_t field_0x170;           /* 0x170 */
    float    scale_factor;          /* 0x178 - init 1.0 (0x3f800000) */
    uint32_t _pad_0x17c;            /* 0x17C */
    float    time_delta;            /* 0x180 */
    float    time_accumulator;      /* 0x184 */
    uint64_t enable_flag;           /* 0x188 - init 1 */
    uint32_t field_0x190;           /* 0x190 - zeroed in ctor */
    uint32_t _pad_0x194;            /* 0x194 */
    uint64_t field_0x198;           /* 0x198 - zeroed in ctor */
    uint64_t field_0x1a0;           /* 0x1A0 - zeroed in ctor */
} ns3_nuccEffectSimpleAnm;

static_assert(sizeof(ns3_nuccEffectSimpleAnm) == 0x1A8, "ns3_nuccEffectSimpleAnm size");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, base_block) == 0x000, "ns3_nuccEffectSimpleAnm::base_block");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, field_0x160) == 0x160, "ns3_nuccEffectSimpleAnm::field_0x160");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, anm_data_ptr) == 0x168, "ns3_nuccEffectSimpleAnm::anm_data_ptr");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, field_0x170) == 0x170, "ns3_nuccEffectSimpleAnm::field_0x170");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, scale_factor) == 0x178, "ns3_nuccEffectSimpleAnm::scale_factor");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, _pad_0x17c) == 0x17C, "ns3_nuccEffectSimpleAnm::_pad_0x17c");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, time_delta) == 0x180, "ns3_nuccEffectSimpleAnm::time_delta");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, time_accumulator) == 0x184, "ns3_nuccEffectSimpleAnm::time_accumulator");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, enable_flag) == 0x188, "ns3_nuccEffectSimpleAnm::enable_flag");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, field_0x190) == 0x190, "ns3_nuccEffectSimpleAnm::field_0x190");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, _pad_0x194) == 0x194, "ns3_nuccEffectSimpleAnm::_pad_0x194");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, field_0x198) == 0x198, "ns3_nuccEffectSimpleAnm::field_0x198");
static_assert(offsetof(ns3_nuccEffectSimpleAnm, field_0x1a0) == 0x1A0, "ns3_nuccEffectSimpleAnm::field_0x1a0");

/* =========================================================================
 * ns3_nuccFCurveSceneEffect
 * Size: unknown, >= 0x154 (ctor writes uint32 at offset 0x150; no allocator
 *        size found in any factory method for the base class itself).
 * Subclass ccFCurveSceneEffectGame allocated at 0x158 (RVA 0x4FA998).
 * Vtable: 0x1409e0290 (set in ctor at RVA 0x6B6610)
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_nuccFCurveSceneEffect {
    uint64_t vtable;                /* 0x00 */
    uint8_t  gap_0x08[0xA4];        /* 0x08 - unaccounted gap */
    int32_t  fcurve_values[0x29];   /* 0xAC - array cleared in ctor loop (0x29 ints) */
    uint32_t scene_effect_type;     /* 0x150 - written as param_2 in ctor */
} ns3_nuccFCurveSceneEffect;

/* Size not proven beyond 0x154; sizeof would be misleading. No static_assert on size. */
static_assert(offsetof(ns3_nuccFCurveSceneEffect, vtable) == 0x00, "ns3_nuccFCurveSceneEffect::vtable");
static_assert(offsetof(ns3_nuccFCurveSceneEffect, gap_0x08) == 0x08, "ns3_nuccFCurveSceneEffect::gap_0x08");
static_assert(offsetof(ns3_nuccFCurveSceneEffect, fcurve_values) == 0xAC, "ns3_nuccFCurveSceneEffect::fcurve_values");
static_assert(offsetof(ns3_nuccFCurveSceneEffect, scene_effect_type) == 0x150, "ns3_nuccFCurveSceneEffect::scene_effect_type");

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

#endif /* CMN53_S3_H */