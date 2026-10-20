/* cmn02.h — Storm 4 (s4 / NSUNS4_release.exe 1.09) struct group cmn02
 * INFERRED layouts from x64 decompiled pseudocode. Not CONFIRMED.
 * Own-game names only (no ns3:: prefix carry). PC offsets only.
 * Sizes proven from allocator arguments where available.
 */
#ifndef CMN02_S4_H
#define CMN02_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * s4_ccCmnFade — size >= 0x58
 * vtable = PTR_FUN_141118c50 (ctor @ RVA 0xB089E0)
 * Ctor (undefined8* param_1):
 *   *param_1 = &PTR_FUN_141118c50           // 0x00 vtable
 *   param_1[3..6] = 0                       // 0x18,0x20,0x28,0x30
 *   *(uint32*)(param_1+7) = 0               // 0x38 low half
 *   *(uint32*)(param_1+8) = 0               // 0x40 low half
 *   *(uint32*)((ll)p+0x44) = 0              // 0x44
 *   param_1[9] = 0                          // 0x48
 *   *(uint32*)((ll)p+0x4c) = 0              // 0x4c
 *   *(uint32*)((ll)p+0x54) = 1              // 0x54
 *   param_1[10] = DefaultFadeTime()         // 0x50
 * Initialize @ 0xB08AA0:
 *   param_1[5] = render_obj (alloc 0x190=400) // 0x28
 *   reads vtable+8 virtual call             // 0x00 vtable dispatch
 * Finalize @ 0x5452D0:
 *   reads param_1[0xd] => 0x68 rw          // render_obj cleanup
 *   reads vtable+0x10 virtual call         // 0x00 vtable dispatch
 * state_surface fields: 0x68 rw, 0x44 w, 0x4C w, 0x54 w, 0x80 r(vtable)
 * ========================================================================= */
typedef struct __attribute__((packed)) s4_ccCmnFade {
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
} s4_ccCmnFade;

static_assert(offsetof(s4_ccCmnFade, vtable) == 0x00, "s4_ccCmnFade.vtable");
static_assert(offsetof(s4_ccCmnFade, base_field_0x08) == 0x08, "s4_ccCmnFade.base_field_0x08");
static_assert(offsetof(s4_ccCmnFade, base_field_0x10) == 0x10, "s4_ccCmnFade.base_field_0x10");
static_assert(offsetof(s4_ccCmnFade, field_0x18) == 0x18, "s4_ccCmnFade.field_0x18");
static_assert(offsetof(s4_ccCmnFade, field_0x20) == 0x20, "s4_ccCmnFade.field_0x20");
static_assert(offsetof(s4_ccCmnFade, render_obj) == 0x28, "s4_ccCmnFade.render_obj");
static_assert(offsetof(s4_ccCmnFade, field_0x30) == 0x30, "s4_ccCmnFade.field_0x30");
static_assert(offsetof(s4_ccCmnFade, inv_fade_time) == 0x38, "s4_ccCmnFade.inv_fade_time");
static_assert(offsetof(s4_ccCmnFade, field_0x40) == 0x40, "s4_ccCmnFade.field_0x40");
static_assert(offsetof(s4_ccCmnFade, fade_state) == 0x44, "s4_ccCmnFade.fade_state");
static_assert(offsetof(s4_ccCmnFade, field_0x48) == 0x48, "s4_ccCmnFade.field_0x48");
static_assert(offsetof(s4_ccCmnFade, default_fade_time) == 0x50, "s4_ccCmnFade.default_fade_time");
static_assert(offsetof(s4_ccCmnFade, active_flag) == 0x54, "s4_ccCmnFade.active_flag");
static_assert(sizeof(s4_ccCmnFade) == 0x58, "s4_ccCmnFade size");

/* =========================================================================
 * s4_ccCmnLightManager — size = 0x98
 * vtable = PTR_FUN_141119200 (ctor @ RVA 0xB0C3D0)
 * Three embedded std::list-like containers at qword offsets +3,+8,+0xd
 * => byte offsets 0x18, 0x40, 0x68. Each 0x28 bytes.
 * ctor writes param_1[0x12]=0 => byte 0x90.
 * state_surface fields: 0x78 rw, 0x70 rw, 0x90 w, 0x68 r, 0x80 r(vtable)
 * ReleaseAmbient reads param_1[0xe] (0x70) as refcount, param_1[0xd] (0x68) as list ptr
 * ========================================================================= */
typedef struct __attribute__((packed)) s4_ccCmnLightManager {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t _pad_08[0x10];
    /* 0x18 */ uint8_t list_ambient[0x28];
    /* 0x40 */ uint8_t list_direct[0x28];
    /* 0x68 */ uint8_t list_point[0x28];
    /* 0x90 */ uint64_t light_count;
} s4_ccCmnLightManager;

static_assert(offsetof(s4_ccCmnLightManager, vtable) == 0x00, "s4_ccCmnLightManager.vtable");
static_assert(offsetof(s4_ccCmnLightManager, list_ambient) == 0x18, "s4_ccCmnLightManager.list_ambient");
static_assert(offsetof(s4_ccCmnLightManager, list_direct) == 0x40, "s4_ccCmnLightManager.list_direct");
static_assert(offsetof(s4_ccCmnLightManager, list_point) == 0x68, "s4_ccCmnLightManager.list_point");
static_assert(offsetof(s4_ccCmnLightManager, light_count) == 0x90, "s4_ccCmnLightManager.light_count");
static_assert(sizeof(s4_ccCmnLightManager) == 0x98, "s4_ccCmnLightManager size");

/* =========================================================================
 * s4_ccCmnRotate — size = 0x54
 * vtable = PTR_FUN_1411046e8 (ctor @ RVA 0xAC0F00)
 * Ctor (undefined8* param_1, uint32 x, uint32 z, uint32 y):
 *   *param_1 = &PTR_FUN_1411046e8           // 0x00 vtable
 *   FUN_140a0d640(param_1+0x14, identity)   // 0x14 matrix init
 *   *(uint32*)(param_1+1) = x               // 0x08 angle_x
 *   *(uint32*)(param_1+2) = z               // 0x10 angle_z
 *   *(uint32*)((ll)p+0xc) = y               // 0x0c angle_y
 * CalculateZXY @ 0xAC0F80:
 *   reads int32 at +0x10 (angle_z), +0x0c (angle_y), +0x08 (angle_x)
 *   converts to radians (* 6.2831855 * 1.5258789e-05 = *2pi/65536)
 *   writes matrix at +0x14 via FUN_140a0d850
 * Matrix is 0x40 bytes (4x4 float matrix)
 * ========================================================================= */
typedef struct __attribute__((packed)) s4_ccCmnRotate {
    /* 0x00 */ void *vtable;
    /* 0x08 */ int32_t angle_x;
    /* 0x0c */ int32_t angle_y;
    /* 0x10 */ int32_t angle_z;
    /* 0x14 */ uint8_t matrix[0x40];
} s4_ccCmnRotate;

static_assert(offsetof(s4_ccCmnRotate, vtable) == 0x00, "s4_ccCmnRotate.vtable");
static_assert(offsetof(s4_ccCmnRotate, angle_x) == 0x08, "s4_ccCmnRotate.angle_x");
static_assert(offsetof(s4_ccCmnRotate, angle_y) == 0x0c, "s4_ccCmnRotate.angle_y");
static_assert(offsetof(s4_ccCmnRotate, angle_z) == 0x10, "s4_ccCmnRotate.angle_z");
static_assert(offsetof(s4_ccCmnRotate, matrix) == 0x14, "s4_ccCmnRotate.matrix");
static_assert(sizeof(s4_ccCmnRotate) == 0x54, "s4_ccCmnRotate size");

/* =========================================================================
 * s4_ccCmnScreen — size = 0x30
 * Size proven: allocator FUN_140a017f0(0x30,...) in ccCmnScreenManager::Initialize
 * Ctor @ 0xABC150 (undefined4* param_1):
 *   *param_1 = 1                            // 0x00 screen_flag
 *   param_1[1] = screen_id                  // 0x04
 *   *(undefined8*)(param_1+2) = view        // 0x08 (alloc 0x2d0)
 *   *(undefined8*)(param_1+4) = camera_dir  // 0x10 (alloc 0x80)
 *   *(undefined1*)(param_1+6) = 1           // 0x18 active_flag
 *   *(undefined8*)(param_1+8) = layer_info  // 0x20 (alloc 0x10 via chain)
 *   *(undefined8*)(param_1+10) = -1         // 0x28
 * No vtable (not polymorphic).
 * state_surface returned 0 fields (all byte-cast warnings); layout from manual decomp.
 * ========================================================================= */
typedef struct __attribute__((packed)) s4_ccCmnScreen {
    /* 0x00 */ uint32_t screen_flag;
    /* 0x04 */ uint32_t screen_id;
    /* 0x08 */ void *view;
    /* 0x10 */ void *camera_director;
    /* 0x18 */ uint8_t active_flag;
    /* 0x19 */ uint8_t _pad_19[7];
    /* 0x20 */ void *layer_set_info;
    /* 0x28 */ uint64_t field_0x28;
} s4_ccCmnScreen;

static_assert(offsetof(s4_ccCmnScreen, screen_flag) == 0x00, "s4_ccCmnScreen.screen_flag");
static_assert(offsetof(s4_ccCmnScreen, screen_id) == 0x04, "s4_ccCmnScreen.screen_id");
static_assert(offsetof(s4_ccCmnScreen, view) == 0x08, "s4_ccCmnScreen.view");
static_assert(offsetof(s4_ccCmnScreen, camera_director) == 0x10, "s4_ccCmnScreen.camera_director");
static_assert(offsetof(s4_ccCmnScreen, active_flag) == 0x18, "s4_ccCmnScreen.active_flag");
static_assert(offsetof(s4_ccCmnScreen, layer_set_info) == 0x20, "s4_ccCmnScreen.layer_set_info");
static_assert(offsetof(s4_ccCmnScreen, field_0x28) == 0x28, "s4_ccCmnScreen.field_0x28");
static_assert(sizeof(s4_ccCmnScreen) == 0x30, "s4_ccCmnScreen size");

/* =========================================================================
 * s4_ccCmnScreenManager — variable-length (header + screen pointer array)
 * No vtable observed (not polymorphic).
 * Ctor @ 0xAB4680: zeros param_1[0..9] as undefined8* => 0x00-0x4f (10 qwords)
 * Initialize @ 0xAB46D0:
 *   writes screen_count at *(uint*)(param_1+4) => offset 0x04
 *   allocates ccCmnScreen objects (0x30 each) into screens[] at +0x10
 *   loop: puVar4 = (undefined8*)(param_1 + 0x10); *puVar4 = new ccCmnScreen(i)
 * Finalize/destructor iterates screens[i] at param_1+i*8+0x10
 * state_surface returned 0 fields (all byte-cast warnings); layout from manual decomp.
 * ========================================================================= */
typedef struct __attribute__((packed)) s4_ccCmnScreenManager {
    /* 0x00 */ uint32_t field_0x00;
    /* 0x04 */ uint32_t screen_count;
    /* 0x08 */ int32_t active_screen_id;
    /* 0x0c */ uint32_t _pad_0c;
    /* 0x10 */ void *screens[1];
} s4_ccCmnScreenManager;

static_assert(offsetof(s4_ccCmnScreenManager, field_0x00) == 0x00, "s4_ccCmnScreenManager.field_0x00");
static_assert(offsetof(s4_ccCmnScreenManager, screen_count) == 0x04, "s4_ccCmnScreenManager.screen_count");
static_assert(offsetof(s4_ccCmnScreenManager, active_screen_id) == 0x08, "s4_ccCmnScreenManager.active_screen_id");
static_assert(offsetof(s4_ccCmnScreenManager, screens) == 0x10, "s4_ccCmnScreenManager.screens");

/* ccCollectionModePad::CollectionModeTouchStick — below 3-method threshold.
 * Layout not reconstructed. */

#endif /* CMN02_S4_H */