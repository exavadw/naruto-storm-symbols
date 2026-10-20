#ifndef RBFRAME_H
#define RBFRAME_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct __attribute__((packed)) {
    void *vtable; // +0x0
    uint8_t _pad_8[0x4];
    int32_t field_C; // +0xC
    uint8_t _pad_10[0x10];
    uint8_t light_param[0x180]; // +0x20
    uint8_t fog_param[0x114]; // +0x1A0
    uint8_t geo_sphere_2B4[0x4]; // +0x2B4
    uint8_t celshade_param[0x298]; // +0x2B8
    uint8_t resolution[0x18]; // +0x550
    uint8_t _pad_568[0x10];
    uint64_t render_tex_578; // +0x578
    uint64_t render_tex_580; // +0x580
    uint64_t render_tex_588; // +0x588
    uint8_t _pad_590[0x30];
    float sprite_mat_5C0; // +0x5C0
    float sprite_mat_5C4; // +0x5C4
    uint8_t _pad_5C8[0x4];
    float sprite_mat_5CC; // +0x5CC
    uint8_t _pad_5D0[0x10];
    uint8_t matrix_block_5E0[0x48]; // +0x5E0
    uint8_t _pad_628[0x8];
    uint8_t initialized_flag[0x1]; // +0x630
    uint8_t _pad_631[0x23B];
    float field_86C; // +0x86C
    float field_870; // +0x870
    float field_874; // +0x874
    float field_878; // +0x878
    float field_87C; // +0x87C
    float field_880; // +0x880
    float field_884; // +0x884
    float field_888; // +0x888
    float field_88C; // +0x88C
    uint8_t _pad_890[0x44];
    float field_8D4; // +0x8D4
    uint8_t _pad_8D8[0x1C];
    float field_8F4; // +0x8F4
    uint8_t _pad_8F8[0x2C];
    float field_924; // +0x924
    uint8_t _pad_928[0x2A];
    uint8_t reset_frame_flag[0x1]; // +0x952
    uint8_t _pad_953[0x15];
    uint8_t geo_sphere_968[0x50]; // +0x968
    uint8_t crit_section_9B8[0x50]; // +0x9B8
    uint8_t crit_section_A08[0x50]; // +0xA08
    uint8_t _pad_A58[0x18];
    uint8_t block_allocator[0x190]; // +0xA70
} nuccSys;

static_assert(offsetof(nuccSys, field_C) == 0xC, "nuccSys::field_C");
static_assert(offsetof(nuccSys, light_param) == 0x20, "nuccSys::light_param");
static_assert(offsetof(nuccSys, fog_param) == 0x1A0, "nuccSys::fog_param");
static_assert(offsetof(nuccSys, geo_sphere_2B4) == 0x2B4, "nuccSys::geo_sphere_2B4");
static_assert(offsetof(nuccSys, celshade_param) == 0x2B8, "nuccSys::celshade_param");
static_assert(offsetof(nuccSys, resolution) == 0x550, "nuccSys::resolution");
static_assert(offsetof(nuccSys, render_tex_578) == 0x578, "nuccSys::render_tex_578");
static_assert(offsetof(nuccSys, render_tex_580) == 0x580, "nuccSys::render_tex_580");
static_assert(offsetof(nuccSys, render_tex_588) == 0x588, "nuccSys::render_tex_588");
static_assert(offsetof(nuccSys, sprite_mat_5C0) == 0x5C0, "nuccSys::sprite_mat_5C0");
static_assert(offsetof(nuccSys, sprite_mat_5C4) == 0x5C4, "nuccSys::sprite_mat_5C4");
static_assert(offsetof(nuccSys, sprite_mat_5CC) == 0x5CC, "nuccSys::sprite_mat_5CC");
static_assert(offsetof(nuccSys, matrix_block_5E0) == 0x5E0, "nuccSys::matrix_block_5E0");
static_assert(offsetof(nuccSys, initialized_flag) == 0x630, "nuccSys::initialized_flag");
static_assert(offsetof(nuccSys, field_86C) == 0x86C, "nuccSys::field_86C");
static_assert(offsetof(nuccSys, field_870) == 0x870, "nuccSys::field_870");
static_assert(offsetof(nuccSys, field_874) == 0x874, "nuccSys::field_874");
static_assert(offsetof(nuccSys, field_878) == 0x878, "nuccSys::field_878");
static_assert(offsetof(nuccSys, field_87C) == 0x87C, "nuccSys::field_87C");
static_assert(offsetof(nuccSys, field_880) == 0x880, "nuccSys::field_880");
static_assert(offsetof(nuccSys, field_884) == 0x884, "nuccSys::field_884");
static_assert(offsetof(nuccSys, field_888) == 0x888, "nuccSys::field_888");
static_assert(offsetof(nuccSys, field_88C) == 0x88C, "nuccSys::field_88C");
static_assert(offsetof(nuccSys, field_8D4) == 0x8D4, "nuccSys::field_8D4");
static_assert(offsetof(nuccSys, field_8F4) == 0x8F4, "nuccSys::field_8F4");
static_assert(offsetof(nuccSys, field_924) == 0x924, "nuccSys::field_924");
static_assert(offsetof(nuccSys, reset_frame_flag) == 0x952, "nuccSys::reset_frame_flag");
static_assert(offsetof(nuccSys, geo_sphere_968) == 0x968, "nuccSys::geo_sphere_968");
static_assert(offsetof(nuccSys, crit_section_9B8) == 0x9B8, "nuccSys::crit_section_9B8");
static_assert(offsetof(nuccSys, crit_section_A08) == 0xA08, "nuccSys::crit_section_A08");
static_assert(offsetof(nuccSys, block_allocator) == 0xA70, "nuccSys::block_allocator");

typedef struct __attribute__((packed)) {
    void *vtable; // +0x0
    uint64_t camera_list_head; // +0x8
    uint64_t field_10; // +0x10
    uint64_t camera_ptr; // +0x18
    int32_t active_camera_count; // +0x20
    int32_t camera_mode; // +0x24
    uint64_t field_28; // +0x28
} ccCameraCtrl;

static_assert(offsetof(ccCameraCtrl, camera_list_head) == 0x8, "ccCameraCtrl::camera_list_head");
static_assert(offsetof(ccCameraCtrl, field_10) == 0x10, "ccCameraCtrl::field_10");
static_assert(offsetof(ccCameraCtrl, camera_ptr) == 0x18, "ccCameraCtrl::camera_ptr");
static_assert(offsetof(ccCameraCtrl, active_camera_count) == 0x20, "ccCameraCtrl::active_camera_count");
static_assert(offsetof(ccCameraCtrl, camera_mode) == 0x24, "ccCameraCtrl::camera_mode");
static_assert(offsetof(ccCameraCtrl, field_28) == 0x28, "ccCameraCtrl::field_28");

typedef struct __attribute__((packed)) {
    void *vtable; // +0x0
    uint8_t _pad_8[0x8];
    uint8_t navi_manager[0x20]; // +0x10
    uint64_t core_ptr; // +0x30
    uint8_t _pad_38[0xDC18];
    uint8_t stage_mgr_block[0x100]; // +0xDC50
} ccWorldManager;

static_assert(offsetof(ccWorldManager, navi_manager) == 0x10, "ccWorldManager::navi_manager");
static_assert(offsetof(ccWorldManager, core_ptr) == 0x30, "ccWorldManager::core_ptr");
static_assert(offsetof(ccWorldManager, stage_mgr_block) == 0xDC50, "ccWorldManager::stage_mgr_block");

typedef struct __attribute__((packed)) {
    void *vtable; // +0x0
    uint8_t _pad_8[0x10];
    uint8_t task_lists[0x1400]; // +0x18
} ccTaskManager;

static_assert(offsetof(ccTaskManager, task_lists) == 0x18, "ccTaskManager::task_lists");

typedef struct __attribute__((packed)) {
    void *vtable; // +0x0
    uint8_t _pad_8[0x24];
    uint8_t gim_2C[0x4]; // +0x2C
    uint8_t gim_30[0x4]; // +0x30
    uint8_t gim_34[0x4]; // +0x34
    uint8_t gim_38[0x4]; // +0x38
    uint8_t gim_3C[0x4]; // +0x3C
    uint8_t gim_40[0x4]; // +0x40
    uint8_t gim_44[0x4]; // +0x44
    uint8_t gim_48[0x4]; // +0x48
    uint8_t gim_4C[0x4]; // +0x4C
    uint8_t gim_50[0x4]; // +0x50
    uint8_t gim_54[0x4]; // +0x54
    uint8_t _pad_58[0x80];
    uint8_t gim_D8[0x8]; // +0xD8
    uint8_t _pad_E0[0x20];
    uint8_t gim_100[0x4]; // +0x100
    uint8_t gim_104[0x4]; // +0x104
    uint8_t gim_108[0x4]; // +0x108
    uint8_t gim_10C[0x4]; // +0x10C
    uint8_t gim_110[0x8]; // +0x110
    uint8_t _pad_118[0x38];
    uint8_t gim_150[0x4]; // +0x150
    uint8_t _pad_154[0x4C];
    uint8_t gim_1A0[0x4]; // +0x1A0
    uint8_t _pad_1A4[0x4];
    uint8_t gim_1A8[0x4]; // +0x1A8
    uint8_t _remaining[0x14]; // 20 fields omitted
} ccGimmickManager;

static_assert(offsetof(ccGimmickManager, gim_2C) == 0x2C, "ccGimmickManager::gim_2C");
static_assert(offsetof(ccGimmickManager, gim_30) == 0x30, "ccGimmickManager::gim_30");
static_assert(offsetof(ccGimmickManager, gim_34) == 0x34, "ccGimmickManager::gim_34");
static_assert(offsetof(ccGimmickManager, gim_38) == 0x38, "ccGimmickManager::gim_38");
static_assert(offsetof(ccGimmickManager, gim_3C) == 0x3C, "ccGimmickManager::gim_3C");
static_assert(offsetof(ccGimmickManager, gim_40) == 0x40, "ccGimmickManager::gim_40");
static_assert(offsetof(ccGimmickManager, gim_44) == 0x44, "ccGimmickManager::gim_44");
static_assert(offsetof(ccGimmickManager, gim_48) == 0x48, "ccGimmickManager::gim_48");
static_assert(offsetof(ccGimmickManager, gim_4C) == 0x4C, "ccGimmickManager::gim_4C");
static_assert(offsetof(ccGimmickManager, gim_50) == 0x50, "ccGimmickManager::gim_50");
static_assert(offsetof(ccGimmickManager, gim_54) == 0x54, "ccGimmickManager::gim_54");
static_assert(offsetof(ccGimmickManager, gim_D8) == 0xD8, "ccGimmickManager::gim_D8");
static_assert(offsetof(ccGimmickManager, gim_100) == 0x100, "ccGimmickManager::gim_100");
static_assert(offsetof(ccGimmickManager, gim_104) == 0x104, "ccGimmickManager::gim_104");
static_assert(offsetof(ccGimmickManager, gim_108) == 0x108, "ccGimmickManager::gim_108");
static_assert(offsetof(ccGimmickManager, gim_10C) == 0x10C, "ccGimmickManager::gim_10C");
static_assert(offsetof(ccGimmickManager, gim_110) == 0x110, "ccGimmickManager::gim_110");
static_assert(offsetof(ccGimmickManager, gim_150) == 0x150, "ccGimmickManager::gim_150");
static_assert(offsetof(ccGimmickManager, gim_1A0) == 0x1A0, "ccGimmickManager::gim_1A0");
static_assert(offsetof(ccGimmickManager, gim_1A8) == 0x1A8, "ccGimmickManager::gim_1A8");

#endif // RBFRAME_H
