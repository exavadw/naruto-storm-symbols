/* cmn02.h — Storm 2 (s2 / NSUNS2.exe) struct group cmn02
 * INFERRED layouts from x64 decompiled pseudocode. Not CONFIRMED.
 * Own-game names only (ns2:: / Storm 2 strings). PC offsets only.
 * Sizes proven from LoadTh allocator arguments where available.
 */
#ifndef CMN02_S2_H
#define CMN02_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccCmnFade — size = 0x60 (proven: Framework::Initialize LoadTh(0x60,...))
 * vtable = PTR_FUN_14089f4a8 (set in ctor @ 0x655A60)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnFade {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x10];
    /* 0x18 */ uint64_t field_0x18;
    /* 0x20 */ uint64_t field_0x20;
    /* 0x28 */ void *render_obj;
    /* 0x30 */ int32_t fade_state;
    /* 0x34 */ float fade_progress;
    /* 0x38 */ float inv_fade_time;
    /* 0x3c */ uint8_t _pad_3c[4];
    /* 0x40 */ uint64_t color_lo;
    /* 0x48 */ uint64_t color_hi;
    /* 0x50 */ float default_fade_time;
    /* 0x54 */ int32_t active_flag;
    /* 0x58 */ uint8_t _pad_58[8];
} ccCmnFade;

static_assert(offsetof(ccCmnFade, vtable) == 0x00, "ccCmnFade.vtable");
static_assert(offsetof(ccCmnFade, field_0x18) == 0x18, "ccCmnFade.field_0x18");
static_assert(offsetof(ccCmnFade, field_0x20) == 0x20, "ccCmnFade.field_0x20");
static_assert(offsetof(ccCmnFade, render_obj) == 0x28, "ccCmnFade.render_obj");
static_assert(offsetof(ccCmnFade, fade_state) == 0x30, "ccCmnFade.fade_state");
static_assert(offsetof(ccCmnFade, fade_progress) == 0x34, "ccCmnFade.fade_progress");
static_assert(offsetof(ccCmnFade, inv_fade_time) == 0x38, "ccCmnFade.inv_fade_time");
static_assert(offsetof(ccCmnFade, color_lo) == 0x40, "ccCmnFade.color_lo");
static_assert(offsetof(ccCmnFade, color_hi) == 0x48, "ccCmnFade.color_hi");
static_assert(offsetof(ccCmnFade, default_fade_time) == 0x50, "ccCmnFade.default_fade_time");
static_assert(offsetof(ccCmnFade, active_flag) == 0x54, "ccCmnFade.active_flag");
static_assert(sizeof(ccCmnFade) == 0x60, "ccCmnFade size");

/* =========================================================================
 * ccCmnLightManager — size >= 0x98 (INFERRED: ctor writes param_1[0x12]=0
 * as undefined8* => byte offset 0x90, plus 8 bytes for that field)
 * vtable = PTR_FUN_1408a1e78 (set in ctor @ 0x68E340)
 * Three embedded std::list-like containers at qword offsets +3,+8,+0xd
 * => byte offsets 0x18, 0x40, 0x68
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnLightManager {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x10];
    /* 0x18 */ uint8_t list_a[0x28];
    /* 0x40 */ uint8_t list_b[0x28];
    /* 0x68 */ uint8_t list_c[0x28];
    /* 0x90 */ uint32_t count;
    /* 0x94 */ uint8_t _pad_94[4];
} ccCmnLightManager;

static_assert(offsetof(ccCmnLightManager, vtable) == 0x00, "ccCmnLightManager.vtable");
static_assert(offsetof(ccCmnLightManager, list_a) == 0x18, "ccCmnLightManager.list_a");
static_assert(offsetof(ccCmnLightManager, list_b) == 0x40, "ccCmnLightManager.list_b");
static_assert(offsetof(ccCmnLightManager, list_c) == 0x68, "ccCmnLightManager.list_c");
static_assert(offsetof(ccCmnLightManager, count) == 0x90, "ccCmnLightManager.count");
static_assert(sizeof(ccCmnLightManager) == 0x98, "ccCmnLightManager size >= 0x98");

/* =========================================================================
 * ccCmnRotate — size >= 0x54 (INFERRED: Matrix44 ends at 0x14+0x40=0x54)
 * Stack-allocated; no heap size proof found.
 * vtable = PTR_FUN_1408918e8 (set in both ctors @ 0x65FD90, 0x65FDD0)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnRotate {
    /* 0x00 */ void *vtable;
    /* 0x08 */ int32_t angle_x;
    /* 0x0c */ int32_t angle_y;
    /* 0x10 */ int32_t angle_z;
    /* 0x14 */ uint8_t matrix[0x40];
} ccCmnRotate;

static_assert(offsetof(ccCmnRotate, vtable) == 0x00, "ccCmnRotate.vtable");
static_assert(offsetof(ccCmnRotate, angle_x) == 0x08, "ccCmnRotate.angle_x");
static_assert(offsetof(ccCmnRotate, angle_y) == 0x0c, "ccCmnRotate.angle_y");
static_assert(offsetof(ccCmnRotate, angle_z) == 0x10, "ccCmnRotate.angle_z");
static_assert(offsetof(ccCmnRotate, matrix) == 0x14, "ccCmnRotate.matrix");
static_assert(sizeof(ccCmnRotate) == 0x54, "ccCmnRotate size >= 0x54");

/* =========================================================================
 * ccCmnScreen — size = 0x30 (proven: ccCmnScreenManager::Initialize LoadTh(0x30,...))
 * Ctor uses undefined4* param_1: param_1+2 => byte 0x08, param_1+4 => 0x10, etc.
 * No vtable set in ctor (not polymorphic or set by base)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnScreen {
    /* 0x00 */ uint32_t screen_id_or_flag;
    /* 0x04 */ uint32_t screen_id;
    /* 0x08 */ void *view;
    /* 0x10 */ void *camera_director;
    /* 0x18 */ uint8_t flag_byte;
    /* 0x19 */ uint8_t _pad_19[7];
    /* 0x20 */ void *layer_set_info;
    /* 0x28 */ uint64_t field_0x28;
} ccCmnScreen;

static_assert(offsetof(ccCmnScreen, screen_id_or_flag) == 0x00, "ccCmnScreen.screen_id_or_flag");
static_assert(offsetof(ccCmnScreen, screen_id) == 0x04, "ccCmnScreen.screen_id");
static_assert(offsetof(ccCmnScreen, view) == 0x08, "ccCmnScreen.view");
static_assert(offsetof(ccCmnScreen, camera_director) == 0x10, "ccCmnScreen.camera_director");
static_assert(offsetof(ccCmnScreen, flag_byte) == 0x18, "ccCmnScreen.flag_byte");
static_assert(offsetof(ccCmnScreen, layer_set_info) == 0x20, "ccCmnScreen.layer_set_info");
static_assert(offsetof(ccCmnScreen, field_0x28) == 0x28, "ccCmnScreen.field_0x28");
static_assert(sizeof(ccCmnScreen) == 0x30, "ccCmnScreen size");

/* =========================================================================
 * ccCmnScreenManager_header — size unknown, >= 0x50 (ctor zeros 10 qwords)
 * Variable-length: header + num_screens * 8 pointer array
 * No vtable observed (not polymorphic)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccCmnScreenManager_header {
    /* 0x00 */ uint32_t field_0x00;
    /* 0x04 */ uint32_t screen_count;
    /* 0x08 */ int32_t active_screen_id;
    /* 0x0c */ uint32_t _pad_0c;
    /* 0x10 */ void *screens[1];
} ccCmnScreenManager_header;

static_assert(offsetof(ccCmnScreenManager_header, field_0x00) == 0x00, "ccCmnScreenManager.field_0x00");
static_assert(offsetof(ccCmnScreenManager_header, screen_count) == 0x04, "ccCmnScreenManager.screen_count");
static_assert(offsetof(ccCmnScreenManager_header, active_screen_id) == 0x08, "ccCmnScreenManager.active_screen_id");
static_assert(offsetof(ccCmnScreenManager_header, screens) == 0x10, "ccCmnScreenManager.screens");

/* ccCollectionModePad::CollectionModeTouchStick — below 3-method threshold.
 * Only OnChangeState (0x6841424) found; calls nuccFont2::Print/GetLineWidth.
 * Layout not reconstructed. */

#endif /* CMN02_S2_H */