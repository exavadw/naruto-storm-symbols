#ifndef RBFRAME_S2_H
#define RBFRAME_S2_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * rbFrame struct group for Storm 2 (NSUNS2.exe, build s2)
 * Image base: 0x140000000
 * All layouts INFERRED from static decompilation; not CONFIRMED by runtime trace.
 * Absent classes in s2: ccWorldManager, ccStageGimmick, ccCameraCtrl
 */

typedef struct __attribute__((packed)) {
    void *vtable;                    // +0x0
    uint8_t _pad_8[0x4];             // +0x8
    int32_t field_C;                 // +0xC   rw  nummRenderTextureRelease
    uint8_t _pad_10[0x1];            // +0x10
    uint8_t flag_11;                 // +0x11  r   nummRenderTextureRelease
    uint8_t _pad_12[0xE];            // +0x12
    uint8_t light_param[0x180];      // +0x20  ctor FUN_1405cd040
    uint8_t fog_param[0x114];        // +0x1A0 ctor FUN_1405abc00
    uint8_t subobj_2B4[0x4];         // +0x2B4 geo_sphere ctor FUN_1401994b0
    uint8_t celshade_param[0x298];   // +0x2B8 ctor FUN_1405c9340
    /* celshade_param spans +0x2B8..+0x54F; target_framerate at +0x4A0 is inside it.
     * We emit it as a separate field below for rollback snapshot clarity,
     * but note the overlap. The packed layout uses the array above. */
    uint8_t resolution[0x28];        // +0x550 init FUN_140581210
    uint64_t render_tex_578;         // +0x578 rw  CreateRenderTexture
    uint64_t render_tex_580;         // +0x580 rw  CreateRenderTexture
    uint64_t render_tex_588;         // +0x588 rw  CreateRenderTexture
    uint8_t _pad_590[0x30];          // +0x590
    float sprite_mat_5C0;            // +0x5C0 SetSpriteMatrix
    float sprite_mat_5C4;            // +0x5C4 SetSpriteMatrix
    uint8_t _pad_5C8[0x4];           // +0x5C8
    float sprite_mat_5CC;            // +0x5CC SetSpriteMatrix
    uint8_t _pad_5D0[0x10];          // +0x5D0
    uint8_t matrix_block_5E0[0x48];  // +0x5E0
    uint8_t _pad_628[0x8];           // +0x628
    uint8_t initialized_flag;        // +0x630 rw  Initialize
    uint8_t _pad_631[0x23B];         // +0x631
    float screen_86C;                // +0x86C Initialize
    float screen_870;                // +0x870 Initialize
    float screen_874;                // +0x874 Initialize
    float screen_878;                // +0x878 Initialize
    float screen_87C;                // +0x87C Initialize
    float screen_880;                // +0x880 Initialize
    float screen_884;                // +0x884 Initialize
    float screen_888;                // +0x888 Initialize
    float screen_88C;                // +0x88C Initialize
    uint8_t _pad_890[0x44];          // +0x890
    float screen_8D4;                // +0x8D4 Initialize
    uint8_t _pad_8D8[0x1C];          // +0x8D8
    float screen_8F4;                // +0x8F4 Initialize
    uint8_t _pad_8F8[0x2C];          // +0x8F8
    float screen_924;                // +0x924 Initialize
    uint8_t _pad_928[0x2A];          // +0x928
    uint8_t reset_frame_flag;        // +0x952 SIM  ResetFrame
    uint8_t _pad_953[0x15];          // +0x953
    uint8_t geo_sphere_968[0x50];    // +0x968 ctor FUN_1401994b0
    uint8_t crit_section_9B8[0x50];  // +0x9B8 init FUN_1405ac080
    uint8_t crit_section_A08[0x50];  // +0xA08 init FUN_1405ac080
    uint8_t _pad_A58[0x18];          // +0xA58
    uint8_t block_allocator[0x190];  // +0xA70 init FUN_1401afc0c
    uint8_t large_array_C00[0x2300]; // +0xC00 32 entries x 0x118 stride
    /* field_F58 (+0xF58) and field_F5C (+0xF5C) are inside large_array_C00
     * (which spans +0xC00..+0x2EFF). Documented in TSV for rollback reference
     * but excluded from the C struct to avoid overlapping members. */
} nuccSys;

static_assert(offsetof(nuccSys, field_C) == 0xC, "nuccSys::field_C");
static_assert(offsetof(nuccSys, flag_11) == 0x11, "nuccSys::flag_11");
static_assert(offsetof(nuccSys, light_param) == 0x20, "nuccSys::light_param");
static_assert(offsetof(nuccSys, fog_param) == 0x1A0, "nuccSys::fog_param");
static_assert(offsetof(nuccSys, subobj_2B4) == 0x2B4, "nuccSys::subobj_2B4");
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
static_assert(offsetof(nuccSys, screen_86C) == 0x86C, "nuccSys::screen_86C");
static_assert(offsetof(nuccSys, screen_870) == 0x870, "nuccSys::screen_870");
static_assert(offsetof(nuccSys, screen_874) == 0x874, "nuccSys::screen_874");
static_assert(offsetof(nuccSys, screen_878) == 0x878, "nuccSys::screen_878");
static_assert(offsetof(nuccSys, screen_87C) == 0x87C, "nuccSys::screen_87C");
static_assert(offsetof(nuccSys, screen_880) == 0x880, "nuccSys::screen_880");
static_assert(offsetof(nuccSys, screen_884) == 0x884, "nuccSys::screen_884");
static_assert(offsetof(nuccSys, screen_888) == 0x888, "nuccSys::screen_888");
static_assert(offsetof(nuccSys, screen_88C) == 0x88C, "nuccSys::screen_88C");
static_assert(offsetof(nuccSys, screen_8D4) == 0x8D4, "nuccSys::screen_8D4");
static_assert(offsetof(nuccSys, screen_8F4) == 0x8F4, "nuccSys::screen_8F4");
static_assert(offsetof(nuccSys, screen_924) == 0x924, "nuccSys::screen_924");
static_assert(offsetof(nuccSys, reset_frame_flag) == 0x952, "nuccSys::reset_frame_flag");
static_assert(offsetof(nuccSys, geo_sphere_968) == 0x968, "nuccSys::geo_sphere_968");
static_assert(offsetof(nuccSys, crit_section_9B8) == 0x9B8, "nuccSys::crit_section_9B8");
static_assert(offsetof(nuccSys, crit_section_A08) == 0xA08, "nuccSys::crit_section_A08");
static_assert(offsetof(nuccSys, block_allocator) == 0xA70, "nuccSys::block_allocator");
static_assert(offsetof(nuccSys, large_array_C00) == 0xC00, "nuccSys::large_array_C00");

typedef struct __attribute__((packed)) {
    void *vtable;                    // +0x0
    uint8_t _pad_8[0x10];            // +0x8
    uint8_t task_lists[0x1400];      // +0x18  128 slots x 0x28 stride, SIM
} ccTaskManager;

static_assert(offsetof(ccTaskManager, task_lists) == 0x18, "ccTaskManager::task_lists");

#endif /* RBFRAME_S2_H */