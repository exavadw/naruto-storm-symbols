/* cmn02 group: ccCmnFade, ccCmnLightManager, ccCmnRotate, ccCmnScreen,
 * ccCmnScreenManager, ccCollectionModePad::CollectionModeTouchStick
 * Build: s1 (NSUNS1.exe, NARUTO STORM 1 PC)
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Field names derived from s1 code/strings only (own-game rule).
 */
#ifndef CMN02_S1_H
#define CMN02_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccCmnFade
 * Size proven: 0x60 (FUN_14047ed10(0x60,...) in ccFramework ctor at 0x53ba20)
 * Vtable: PTR_FUN_140747980 (set in ctor at 0x567510)
 * Methods: 7 (ctor, Initialize, SetPosZ, SetColor, SetColorDefault,
 *              RequestCancel, DefaultFadeTime)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnFade {
    /* 0x00 */ void *vtable;                          /* PRES: PTR_FUN_140747980 */
    /* 0x08 */ uint8_t _pad_08[0x20];                 /* UNKNOWN: base class / unused */
    /* 0x28 */ void *render_obj;                      /* PRES: sub-object ptr, checked != NULL before use */
    /* 0x30 */ uint32_t cancel_flag;                  /* SIM: set 0 in RequestCancel */
    /* 0x34 */ uint32_t cancel_state;                 /* SIM: set 0 in RequestCancel */
    /* 0x38 */ uint8_t _pad_38[0x08];                 /* UNKNOWN */
    /* 0x40 */ uint64_t color_lo;                     /* PRES: written by SetColor(param_2[0]) */
    /* 0x48 */ uint64_t color_hi;                     /* PRES: written by SetColor(param_2[1]) */
    /* 0x50 */ uint32_t fade_time;                    /* SIM: initialized to DefaultFadeTime() in ctor */
    /* 0x54 */ uint32_t active_flag;                  /* SIM: 1=active (ctor), 0=cancelled (RequestCancel) */
    /* 0x58 */ float inv_fade_time;                   /* SIM: 1.0/fade_time or 1.0 if <=1.0 (Initialize) */
    /* 0x5C */ uint8_t _pad_5c[0x04];                 /* UNKNOWN: padding to 0x60 */
} ccCmnFade;

static_assert(sizeof(ccCmnFade) == 0x60, "ccCmnFade size must be 0x60");
static_assert(offsetof(ccCmnFade, vtable) == 0x00, "ccCmnFade::vtable offset");
static_assert(offsetof(ccCmnFade, render_obj) == 0x28, "ccCmnFade::render_obj offset");
static_assert(offsetof(ccCmnFade, cancel_flag) == 0x30, "ccCmnFade::cancel_flag offset");
static_assert(offsetof(ccCmnFade, cancel_state) == 0x34, "ccCmnFade::cancel_state offset");
static_assert(offsetof(ccCmnFade, color_lo) == 0x40, "ccCmnFade::color_lo offset");
static_assert(offsetof(ccCmnFade, color_hi) == 0x48, "ccCmnFade::color_hi offset");
static_assert(offsetof(ccCmnFade, fade_time) == 0x50, "ccCmnFade::fade_time offset");
static_assert(offsetof(ccCmnFade, active_flag) == 0x54, "ccCmnFade::active_flag offset");
static_assert(offsetof(ccCmnFade, inv_fade_time) == 0x58, "ccCmnFade::inv_fade_time offset");

/* =========================================================================
 * ccCmnLightManager
 * Size unknown, >= 0x98 (last proven field at 0x90 is 8 bytes wide)
 * The outer wrapper ccLightManager allocates more, but ccCmnLightManager
 * itself has no direct operator-new evidence in s1.
 * Vtable: PTR_FUN_140746450 (set in ctor at 0x54C5D0)
 * Contains three embedded std::list-like containers at offsets 0x18, 0x40, 0x68
 *   (each initialized via FUN_14054de00/14054de70/14054dee0 in ctor)
 * Methods: 11 (ctor, dtor, Update, Clear, ReleaseDirect, ReleasePoint,
 *               ReleaseAmbient, GetAmbients, GetDirects, GetPoints)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnLightManager_std_list {
    /* Embedded list node header (inferred from Clear/Release patterns):
     * +0x00: sentinel next ptr
     * +0x08: sentinel prev ptr
     * +0x10: size/count (checked against 0xaaaaaaaaaaaaaa9 guard)
     * +0x18: allocator/tail state
     */
    uint8_t data[0x28];
} ccCmnLightManager_std_list;

typedef struct __attribute__((packed)) ccCmnLightManager {
    /* 0x00 */ void *vtable;                          /* PRES: PTR_FUN_140746450 */
    /* 0x08 */ uint8_t _pad_08[0x10];                 /* UNKNOWN: base class */
    /* 0x18 */ ccCmnLightManager_std_list ambient_list; /* PRES: init FUN_14054de00, iterated in GetAmbients(+0x18) */
    /* 0x40 */ ccCmnLightManager_std_list direct_list;  /* PRES: init FUN_14054de70, iterated in GetDirects(+0x40) */
    /* 0x68 */ ccCmnLightManager_std_list point_list;   /* PRES: init FUN_14054dee0, iterated in Update(+0x68) */
    /* 0x90 */ uint64_t update_counter;                /* SIM: param_1[0x12]=0 in ctor, accessed as qword */
    /* 0x98 */ /* end of proven fields; size unknown >= 0x98 */
} ccCmnLightManager;

static_assert(offsetof(ccCmnLightManager, vtable) == 0x00, "ccCmnLightManager::vtable offset");
static_assert(offsetof(ccCmnLightManager, ambient_list) == 0x18, "ccCmnLightManager::ambient_list offset");
static_assert(offsetof(ccCmnLightManager, direct_list) == 0x40, "ccCmnLightManager::direct_list offset");
static_assert(offsetof(ccCmnLightManager, point_list) == 0x68, "ccCmnLightManager::point_list offset");
static_assert(offsetof(ccCmnLightManager, update_counter) == 0x90, "ccCmnLightManager::update_counter offset");

/* =========================================================================
 * ccCmnRotate
 * Only 1 method in s1 (ctor). Below threshold for full reconstruction.
 * Layout inferred from ctor at 0x561410 only.
 * Size unknown, >= 0x20 (last write at param_1+7 = int32 at byte 0x1C)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnRotate {
    /* 0x00 */ uint32_t flags;                        /* SIM: *param_1 = 0 in ctor */
    /* 0x04 */ uint8_t matrix_or_data[0x0C];          /* PRES: FUN_14047f850 writes 12 bytes from DAT_1407368d8 */
    /* 0x10 */ uint64_t reserved;                     /* SIM: *(param_1+4) = 0 */
    /* 0x18 */ uint32_t index_a;                      /* SIM: param_1[6] = 0 */
    /* 0x1C */ uint32_t index_b;                      /* SIM: param_1[7] = 0xFFFFFFFF */
} ccCmnRotate;

static_assert(offsetof(ccCmnRotate, flags) == 0x00, "ccCmnRotate::flags offset");
static_assert(offsetof(ccCmnRotate, matrix_or_data) == 0x04, "ccCmnRotate::matrix_or_data offset");
static_assert(offsetof(ccCmnRotate, reserved) == 0x10, "ccCmnRotate::reserved offset");
static_assert(offsetof(ccCmnRotate, index_a) == 0x18, "ccCmnRotate::index_a offset");
static_assert(offsetof(ccCmnRotate, index_b) == 0x1C, "ccCmnRotate::index_b offset");

/* =========================================================================
 * ccCmnScreen
 * Only 1 method in s1 (Build). Below threshold for full reconstruction.
 * Fields observed: +0x58 (ptr passed to FUN_14019da10), +0x108 (ptr passed
 * to FUN_14039090c). No allocation size found.
 * ========================================================================= */
/* Not reconstructed: insufficient methods (< 3). See REPORT.md. */

/* =========================================================================
 * ccCmnScreenManager
 * Only 1 method in s1 (GetScreen). Below threshold.
 * GetScreen reads *(param_1 + 0xD68C + param_2 * 4), implying an array
 * of uint32 screen IDs starting at offset 0xD68C.
 * ========================================================================= */
/* Not reconstructed: insufficient methods (< 3). See REPORT.md. */

/* =========================================================================
 * ccCollectionModePad::CollectionModeTouchStick
 * Only 1 method in s1 (OnChangeState). Below threshold.
 * OnChangeState calls FUN_1404ae160 then FUN_1404ada70(param_1, 0).
 * No field accesses visible in this single method.
 * ========================================================================= */
/* Not reconstructed: insufficient methods (< 3). See REPORT.md. */

#endif /* CMN02_S1_H */