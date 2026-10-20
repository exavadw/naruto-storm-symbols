/* cmn02.h — Storm 3 Full Burst HD (s3 / NSUNS3.exe) struct group cmn02
 * INFERRED layouts from x64 decompiled pseudocode. Not CONFIRMED.
 * Own-game names only (ns3::). PC offsets only.
 * Sizes proven from allocator arguments where available.
 */
#ifndef CMN02_S3_H
#define CMN02_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ns3_ccCmnFade — size >= 0x58
 * vtable = PTR_FUN_1409ece20 (ctor @ RVA 0x758D20)
 * Ctor (undefined8* param_1):
 *   *param_1 = &PTR_FUN_1409ece20           // 0x00
 *   param_1[3..6] = 0                       // 0x18,0x20,0x28,0x30
 *   *(uint32*)(param_1+7) = 0               // 0x38 low half
 *   *(uint32*)(param_1+8) = 0               // 0x40 low half
 *   *(uint32*)((ll)p+0x44) = 0              // 0x44
 *   param_1[9] = 0                          // 0x48
 *   *(uint32*)((ll)p+0x4c) = 0              // 0x4c (high half of qword 9)
 *   *(uint32*)((ll)p+0x54) = 1              // 0x54
 *   param_1[10] = DefaultFadeTime()         // 0x50
 * Initialize @ 0x758DE0:
 *   param_1[5] = render_obj (alloc 0x190)   // 0x28
 *   *(float*)(param_1+7) = inv_fade_time    // 0x38
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_ccCmnFade {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint64_t base_field_0x08;
    /* 0x10 */ uint64_t base_field_0x10;
    /* 0x18 */ uint64_t field_0x18;
    /* 0x20 */ uint64_t field_0x20;
    /* 0x28 */ void *render_obj;
    /* 0x30 */ uint64_t field_0x30;
    /* 0x38 */ float inv_fade_time;
    /* 0x3c */ uint32_t _pad_3c;
    /* 0x40 */ uint32_t field_0x40;
    /* 0x44 */ uint32_t fade_state;
    /* 0x48 */ uint64_t field_0x48;
    /* 0x50 */ uint32_t default_fade_time;
    /* 0x54 */ uint32_t active_flag;
} ns3_ccCmnFade;

static_assert(offsetof(ns3_ccCmnFade, vtable) == 0x00, "ns3_ccCmnFade.vtable");
static_assert(offsetof(ns3_ccCmnFade, base_field_0x08) == 0x08, "ns3_ccCmnFade.base_field_0x08");
static_assert(offsetof(ns3_ccCmnFade, base_field_0x10) == 0x10, "ns3_ccCmnFade.base_field_0x10");
static_assert(offsetof(ns3_ccCmnFade, field_0x18) == 0x18, "ns3_ccCmnFade.field_0x18");
static_assert(offsetof(ns3_ccCmnFade, field_0x20) == 0x20, "ns3_ccCmnFade.field_0x20");
static_assert(offsetof(ns3_ccCmnFade, render_obj) == 0x28, "ns3_ccCmnFade.render_obj");
static_assert(offsetof(ns3_ccCmnFade, field_0x30) == 0x30, "ns3_ccCmnFade.field_0x30");
static_assert(offsetof(ns3_ccCmnFade, inv_fade_time) == 0x38, "ns3_ccCmnFade.inv_fade_time");
static_assert(offsetof(ns3_ccCmnFade, field_0x40) == 0x40, "ns3_ccCmnFade.field_0x40");
static_assert(offsetof(ns3_ccCmnFade, fade_state) == 0x44, "ns3_ccCmnFade.fade_state");
static_assert(offsetof(ns3_ccCmnFade, field_0x48) == 0x48, "ns3_ccCmnFade.field_0x48");
static_assert(offsetof(ns3_ccCmnFade, default_fade_time) == 0x50, "ns3_ccCmnFade.default_fade_time");
static_assert(offsetof(ns3_ccCmnFade, active_flag) == 0x54, "ns3_ccCmnFade.active_flag");
static_assert(sizeof(ns3_ccCmnFade) == 0x58, "ns3_ccCmnFade size");

/* =========================================================================
 * ns3_ccCmnLightManager — size = 0x98
 * vtable = PTR_FUN_1409effb8 (ctor @ RVA 0x7999A0)
 * Three embedded std::list-like containers at qword offsets +3,+8,+0xd
 * => byte offsets 0x18, 0x40, 0x68. Each 0x28 bytes.
 * Guard value 0xaaaaaaaaaaaaaa9 at byte 0x70 (within list_point).
 * ctor writes param_1[0x12]=0 => byte 0x90.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_ccCmnLightManager {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x10];
    /* 0x18 */ uint8_t list_ambient[0x28];
    /* 0x40 */ uint8_t list_direct[0x28];
    /* 0x68 */ uint8_t list_point[0x28];
    /* 0x90 */ uint64_t light_count;
} ns3_ccCmnLightManager;

static_assert(offsetof(ns3_ccCmnLightManager, vtable) == 0x00, "ns3_ccCmnLightManager.vtable");
static_assert(offsetof(ns3_ccCmnLightManager, list_ambient) == 0x18, "ns3_ccCmnLightManager.list_ambient");
static_assert(offsetof(ns3_ccCmnLightManager, list_direct) == 0x40, "ns3_ccCmnLightManager.list_direct");
static_assert(offsetof(ns3_ccCmnLightManager, list_point) == 0x68, "ns3_ccCmnLightManager.list_point");
static_assert(offsetof(ns3_ccCmnLightManager, light_count) == 0x90, "ns3_ccCmnLightManager.light_count");
static_assert(sizeof(ns3_ccCmnLightManager) == 0x98, "ns3_ccCmnLightManager size");

/* =========================================================================
 * ns3_ccCmnRotate — size = 0x54
 * vtable = PTR_FUN_1409daf00 (ctor @ RVA 0x74BEA0)
 * CalculateZXY @ 0x74BF20 reads angles at +0x08,+0x0c,+0x10 as int32,
 * writes matrix at +0x14 via FUN_1406856f0.
 * Matrix init from identity DAT_1409dec20 in ctor.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_ccCmnRotate {
    /* 0x00 */ void *vtable;
    /* 0x08 */ int32_t angle_x;
    /* 0x0c */ int32_t angle_y;
    /* 0x10 */ int32_t angle_z;
    /* 0x14 */ uint8_t matrix[0x40];
} ns3_ccCmnRotate;

static_assert(offsetof(ns3_ccCmnRotate, vtable) == 0x00, "ns3_ccCmnRotate.vtable");
static_assert(offsetof(ns3_ccCmnRotate, angle_x) == 0x08, "ns3_ccCmnRotate.angle_x");
static_assert(offsetof(ns3_ccCmnRotate, angle_y) == 0x0c, "ns3_ccCmnRotate.angle_y");
static_assert(offsetof(ns3_ccCmnRotate, angle_z) == 0x10, "ns3_ccCmnRotate.angle_z");
static_assert(offsetof(ns3_ccCmnRotate, matrix) == 0x14, "ns3_ccCmnRotate.matrix");
static_assert(sizeof(ns3_ccCmnRotate) == 0x54, "ns3_ccCmnRotate size");

/* =========================================================================
 * ns3_ccCmnScreen — size = 0x30
 * Size proven: allocator FUN_140683f70(0x30,...) in ccCmnScreenManager::Initialize
 * Ctor @ 0x799490 (undefined4* param_1):
 *   *param_1 = 1                            // 0x00
 *   param_1[1] = screen_id                  // 0x04
 *   *(undefined8*)(param_1+2) = view        // 0x08 (alloc 0x2d0)
 *   *(undefined8*)(param_1+4) = camera_dir  // 0x10 (alloc 0x80)
 *   *(undefined1*)(param_1+6) = 1           // 0x18
 *   *(undefined8*)(param_1+8) = layer_info  // 0x20 (alloc 0x10)
 *   *(undefined8*)(param_1+10) = -1         // 0x28
 * Draw @ 0x799640 reads +0x20, +0x08
 * Build @ 0x799680 reads +0x10, +0x08
 * SetScreen @ 0x7996E0 reads +0x20, +0x28, +0x2c
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_ccCmnScreen {
    /* 0x00 */ uint32_t screen_flag;
    /* 0x04 */ uint32_t screen_id;
    /* 0x08 */ void *view;
    /* 0x10 */ void *camera_director;
    /* 0x18 */ uint8_t active_flag;
    /* 0x19 */ uint8_t _pad_19[7];
    /* 0x20 */ void *layer_set_info;
    /* 0x28 */ uint64_t field_0x28;
} ns3_ccCmnScreen;

static_assert(offsetof(ns3_ccCmnScreen, screen_flag) == 0x00, "ns3_ccCmnScreen.screen_flag");
static_assert(offsetof(ns3_ccCmnScreen, screen_id) == 0x04, "ns3_ccCmnScreen.screen_id");
static_assert(offsetof(ns3_ccCmnScreen, view) == 0x08, "ns3_ccCmnScreen.view");
static_assert(offsetof(ns3_ccCmnScreen, camera_director) == 0x10, "ns3_ccCmnScreen.camera_director");
static_assert(offsetof(ns3_ccCmnScreen, active_flag) == 0x18, "ns3_ccCmnScreen.active_flag");
static_assert(offsetof(ns3_ccCmnScreen, layer_set_info) == 0x20, "ns3_ccCmnScreen.layer_set_info");
static_assert(offsetof(ns3_ccCmnScreen, field_0x28) == 0x28, "ns3_ccCmnScreen.field_0x28");
static_assert(sizeof(ns3_ccCmnScreen) == 0x30, "ns3_ccCmnScreen size");

/* =========================================================================
 * ns3_ccCmnScreenManager — variable-length (header + screen pointer array)
 * No vtable observed (not polymorphic).
 * Ctor @ 0x73CA70: zeros param_1[0..9] as undefined8* => 0x00-0x4f
 * Initialize @ 0x73CAC0: writes screen_count at *(uint*)(param_1+4),
 *   allocates ccCmnScreen objects (0x30 each) into screens[] at +0x10.
 * Finalize @ 0x73CB30: iterates screens[i] at param_1+i*8+0x10.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_ccCmnScreenManager {
    /* 0x00 */ uint32_t field_0x00;
    /* 0x04 */ uint32_t screen_count;
    /* 0x08 */ int32_t active_screen_id;
    /* 0x0c */ uint32_t _pad_0c;
    /* 0x10 */ void *screens[1];
} ns3_ccCmnScreenManager;

static_assert(offsetof(ns3_ccCmnScreenManager, field_0x00) == 0x00, "ns3_ccCmnScreenManager.field_0x00");
static_assert(offsetof(ns3_ccCmnScreenManager, screen_count) == 0x04, "ns3_ccCmnScreenManager.screen_count");
static_assert(offsetof(ns3_ccCmnScreenManager, active_screen_id) == 0x08, "ns3_ccCmnScreenManager.active_screen_id");
static_assert(offsetof(ns3_ccCmnScreenManager, screens) == 0x10, "ns3_ccCmnScreenManager.screens");

/* ccCollectionModePad::CollectionModeTouchStick — below 3-method threshold.
 * Layout not reconstructed. */

#endif /* CMN02_S3_H */