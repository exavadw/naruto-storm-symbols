#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((packed)) {
    void * vtable;                            // +0x0 ctor
    uint8_t _pad_8[0x18];                     // +0x8
    uint8_t light_param[384];                 // +0x20 ctor FUN_14069d040 (opaque)
    uint8_t fog_param[48];                    // +0x1A0 ctor FUN_14069abc00 (opaque)
    uint32_t field_1D0;                       // +0x1D0 Initialize (set via helper)
    uint8_t _pad_1D4[0x4];                    // +0x1D4
    uint32_t language_id;                     // +0x1D8 Initialize (LCID / Steam lang)
    uint8_t _pad_1DC[0x4];                    // +0x1DC
    uint32_t field_1E0;                       // +0x1E0 ctor (=0)
    uint8_t _pad_1E4[0xD0];                   // +0x1E4
    uint8_t subobj_2B4[4];                    // +0x2B4 geo_sphere ctor
    uint8_t celshade_param[8];                // +0x2B8 ctor FUN_14069c9340 (opaque start)
    uint64_t field_2C0;                       // +0x2C0 ctor (=0)
    uint32_t field_2C8;                       // +0x2C8 ctor (=0)
    float field_2CC;                          // +0x2CC ctor (=1.0f)
    float field_2D0;                          // +0x2D0 ctor (=1.0f)
    uint8_t _pad_2D4[0xC];                    // +0x2D4
    uint64_t field_2E0;                       // +0x2E0 ctor (=0)
    uint8_t matrix_array_2E8[272];            // +0x2E8 ctor loop 16x stride 0x10
    uint64_t field_3F8;                       // +0x3F8 ctor (=0)
    void * vtable_400;                        // +0x400 ctor (&PTR_FUN_1409daf00)
    uint8_t _pad_408[0x8];                    // +0x408
    float sprite_mat_410;                     // +0x410 SetSpriteMatrix/ctor (=1.0f)
    float sprite_mat_414;                     // +0x414 SetSpriteMatrix/ctor (=1.0f)
    float sprite_mat_418;                     // +0x418 SetSpriteMatrix/ctor (=1.0f)
    float sprite_mat_41C;                     // +0x41C SetSpriteMatrix/ctor (=1.0f)
    float field_420;                          // +0x420 ctor (=1.0f)
    float field_424;                          // +0x424 ctor (=1.0f)
    float field_428;                          // +0x428 ctor (=1.0f)
    double field_42C;                         // +0x42C ctor (=1.0)
    uint64_t field_434;                       // +0x434 ctor (=0)
    float field_43C;                          // +0x43C ctor (=1.0f)
    uint64_t render_tex_440;                  // +0x440 Initialize (=0)
    uint64_t render_tex_448;                  // +0x448 Initialize (=0)
    uint64_t render_tex_450;                  // +0x450 Initialize (=0)
    uint64_t render_tex_458;                  // +0x458 Initialize (=0)
    uint8_t _pad_460[0x40];                   // +0x460
    uint32_t target_framerate;                // +0x4A0 ResetFrame (=60/param_2) SIM
    uint8_t _pad_4A4[0x2];                    // +0x4A4
    uint16_t aspect_num;                      // +0x4A6 CreateRenderTexture
    uint16_t aspect_den;                      // +0x4A8 CreateRenderTexture
    uint8_t _pad_4AA[0x6];                    // +0x4AA
    uint32_t field_4B0;                       // +0x4B0 CreateRenderTexture
    uint8_t _pad_4B4[0x9C];                   // +0x4B4
    uint8_t resolution[40];                   // +0x550 init FUN_140681210
    uint8_t _pad_578[0x18];                   // +0x578
    uint32_t field_590;                       // +0x590 ctor (=0)
    uint32_t field_594;                       // +0x594 ctor (=1)
    uint64_t field_598;                       // +0x598 ctor (=0)
    uint32_t field_5A0;                       // +0x5A0 ctor (=0xFFFFFFFF)
    uint64_t field_5A4;                       // +0x5A4 ctor (=0)
    float field_5AC;                          // +0x5AC ctor (=1.0f)
    float field_5B0;                          // +0x5B0 ctor (=1.0f)
    uint8_t _pad_5B4[0xC];                    // +0x5B4
    float sprite_mat_5C0;                     // +0x5C0 Initialize/SetSpriteMatrix (=1.0f)
    float sprite_mat_5C4;                     // +0x5C4 Initialize (=0x49000000 as f32)
    uint8_t _pad_5C8[0x4];                    // +0x5C8
    float sprite_mat_5CC;                     // +0x5CC Initialize (=1.0f)
    uint8_t _pad_5D0[0x10];                   // +0x5D0
    uint8_t matrix_block_5E0[80];             // +0x5E0 Initialize (identity-like)
    uint16_t initialized_flag;                // +0x630 Initialize (guard, set=1)
    uint8_t _pad_632[0x3];                    // +0x632
    uint8_t flag_635;                         // +0x635 ctor (=1)
    uint8_t _pad_636[0x6];                    // +0x636
    uint16_t field_63C;                       // +0x63C ctor (=0)
    uint16_t field_63E;                       // +0x63E ctor (=0)
    uint8_t _pad_640[0x4];                    // +0x640
    uint32_t field_644;                       // +0x644 ctor (=0)
    uint32_t field_648;                       // +0x648 ctor (=0xFFFF)
    uint32_t field_64C;                       // +0x64C ctor (=0xFFFF0064)
    char * capture_label;                     // +0x650 ctor ("sim_capture")
    char * field_658;                         // +0x658 ctor (&DAT_1409dd594)
    char * mode_label;                        // +0x660 ctor ("movie")
    uint8_t _pad_668[0x100];                  // +0x668
    uint8_t flag_768;                         // +0x768 ctor (=0)
    uint8_t _pad_769[0x103];                  // +0x769
    int32_t screen_86C;                       // +0x86C Initialize (param_2[4])
    int32_t screen_870;                       // +0x870 Initialize (param_2[5])
    int32_t screen_874;                       // +0x874 Initialize (param_2[0x1b])
    int32_t screen_878;                       // +0x878 Initialize (=0)
    int32_t screen_87C;                       // +0x87C Initialize (sum)
    int32_t screen_880;                       // +0x880 Initialize (sum)
    int32_t screen_884;                       // +0x884 Initialize (param_2[0x1a])
    int32_t screen_888;                       // +0x888 Initialize (param_2[8])
    int32_t screen_88C;                       // +0x88C Initialize (param_2[8])
    uint8_t _pad_890[0x44];                   // +0x890
    int32_t screen_8D4;                       // +0x8D4 Initialize (param_2[10])
    uint8_t _pad_8D8[0x1C];                   // +0x8D8
    int32_t screen_8F4;                       // +0x8F4 Initialize (param_2[0xc])
    uint8_t _pad_8F8[0x2C];                   // +0x8F8
    int32_t screen_924;                       // +0x924 Initialize (param_2[0xe])
    uint8_t _pad_928[0x20];                   // +0x928
    uint64_t field_948;                       // +0x948 ctor (=0)
    uint16_t field_950;                       // +0x950 ctor (=0)
    uint8_t reset_frame_flag;                 // +0x952 ResetFrame SIM
    uint8_t _pad_953[0x15];                   // +0x953
    uint8_t geo_sphere_968[80];               // +0x968 ctor MathGeoSphere
    uint8_t crit_section_9B8[80];             // +0x9B8 init FUN_1406c0040
    uint8_t crit_section_A08[80];             // +0xA08 init FUN_1406c0040
    uint8_t _pad_A58[0x18];                   // +0xA58
    uint8_t block_allocator[400];             // +0xA70 init FUN_14017d4a0
    uint8_t large_array_C00[8960];            // +0xC00 32 entries x 0x118 stride
} nuccSys;

_Static_assert(offsetof(nuccSys, vtable) == 0x0, "nuccSys::vtable");
_Static_assert(offsetof(nuccSys, light_param) == 0x20, "nuccSys::light_param");
_Static_assert(offsetof(nuccSys, fog_param) == 0x1A0, "nuccSys::fog_param");
_Static_assert(offsetof(nuccSys, field_1D0) == 0x1D0, "nuccSys::field_1D0");
_Static_assert(offsetof(nuccSys, language_id) == 0x1D8, "nuccSys::language_id");
_Static_assert(offsetof(nuccSys, field_1E0) == 0x1E0, "nuccSys::field_1E0");
_Static_assert(offsetof(nuccSys, subobj_2B4) == 0x2B4, "nuccSys::subobj_2B4");
_Static_assert(offsetof(nuccSys, celshade_param) == 0x2B8, "nuccSys::celshade_param");
_Static_assert(offsetof(nuccSys, field_2C0) == 0x2C0, "nuccSys::field_2C0");
_Static_assert(offsetof(nuccSys, field_2C8) == 0x2C8, "nuccSys::field_2C8");
_Static_assert(offsetof(nuccSys, field_2CC) == 0x2CC, "nuccSys::field_2CC");
_Static_assert(offsetof(nuccSys, field_2D0) == 0x2D0, "nuccSys::field_2D0");
_Static_assert(offsetof(nuccSys, field_2E0) == 0x2E0, "nuccSys::field_2E0");
_Static_assert(offsetof(nuccSys, matrix_array_2E8) == 0x2E8, "nuccSys::matrix_array_2E8");
_Static_assert(offsetof(nuccSys, field_3F8) == 0x3F8, "nuccSys::field_3F8");
_Static_assert(offsetof(nuccSys, vtable_400) == 0x400, "nuccSys::vtable_400");
_Static_assert(offsetof(nuccSys, sprite_mat_410) == 0x410, "nuccSys::sprite_mat_410");
_Static_assert(offsetof(nuccSys, sprite_mat_414) == 0x414, "nuccSys::sprite_mat_414");
_Static_assert(offsetof(nuccSys, sprite_mat_418) == 0x418, "nuccSys::sprite_mat_418");
_Static_assert(offsetof(nuccSys, sprite_mat_41C) == 0x41C, "nuccSys::sprite_mat_41C");
_Static_assert(offsetof(nuccSys, field_420) == 0x420, "nuccSys::field_420");
_Static_assert(offsetof(nuccSys, field_424) == 0x424, "nuccSys::field_424");
_Static_assert(offsetof(nuccSys, field_428) == 0x428, "nuccSys::field_428");
_Static_assert(offsetof(nuccSys, field_42C) == 0x42C, "nuccSys::field_42C");
_Static_assert(offsetof(nuccSys, field_434) == 0x434, "nuccSys::field_434");
_Static_assert(offsetof(nuccSys, field_43C) == 0x43C, "nuccSys::field_43C");
_Static_assert(offsetof(nuccSys, render_tex_440) == 0x440, "nuccSys::render_tex_440");
_Static_assert(offsetof(nuccSys, render_tex_448) == 0x448, "nuccSys::render_tex_448");
_Static_assert(offsetof(nuccSys, render_tex_450) == 0x450, "nuccSys::render_tex_450");
_Static_assert(offsetof(nuccSys, render_tex_458) == 0x458, "nuccSys::render_tex_458");
_Static_assert(offsetof(nuccSys, target_framerate) == 0x4A0, "nuccSys::target_framerate");
_Static_assert(offsetof(nuccSys, aspect_num) == 0x4A6, "nuccSys::aspect_num");
_Static_assert(offsetof(nuccSys, aspect_den) == 0x4A8, "nuccSys::aspect_den");
_Static_assert(offsetof(nuccSys, field_4B0) == 0x4B0, "nuccSys::field_4B0");
_Static_assert(offsetof(nuccSys, resolution) == 0x550, "nuccSys::resolution");
_Static_assert(offsetof(nuccSys, field_590) == 0x590, "nuccSys::field_590");
_Static_assert(offsetof(nuccSys, field_594) == 0x594, "nuccSys::field_594");
_Static_assert(offsetof(nuccSys, field_598) == 0x598, "nuccSys::field_598");
_Static_assert(offsetof(nuccSys, field_5A0) == 0x5A0, "nuccSys::field_5A0");
_Static_assert(offsetof(nuccSys, field_5A4) == 0x5A4, "nuccSys::field_5A4");
_Static_assert(offsetof(nuccSys, field_5AC) == 0x5AC, "nuccSys::field_5AC");
_Static_assert(offsetof(nuccSys, field_5B0) == 0x5B0, "nuccSys::field_5B0");
_Static_assert(offsetof(nuccSys, sprite_mat_5C0) == 0x5C0, "nuccSys::sprite_mat_5C0");
_Static_assert(offsetof(nuccSys, sprite_mat_5C4) == 0x5C4, "nuccSys::sprite_mat_5C4");
_Static_assert(offsetof(nuccSys, sprite_mat_5CC) == 0x5CC, "nuccSys::sprite_mat_5CC");
_Static_assert(offsetof(nuccSys, matrix_block_5E0) == 0x5E0, "nuccSys::matrix_block_5E0");
_Static_assert(offsetof(nuccSys, initialized_flag) == 0x630, "nuccSys::initialized_flag");
_Static_assert(offsetof(nuccSys, flag_635) == 0x635, "nuccSys::flag_635");
_Static_assert(offsetof(nuccSys, field_63C) == 0x63C, "nuccSys::field_63C");
_Static_assert(offsetof(nuccSys, field_63E) == 0x63E, "nuccSys::field_63E");
_Static_assert(offsetof(nuccSys, field_644) == 0x644, "nuccSys::field_644");
_Static_assert(offsetof(nuccSys, field_648) == 0x648, "nuccSys::field_648");
_Static_assert(offsetof(nuccSys, field_64C) == 0x64C, "nuccSys::field_64C");
_Static_assert(offsetof(nuccSys, capture_label) == 0x650, "nuccSys::capture_label");
_Static_assert(offsetof(nuccSys, field_658) == 0x658, "nuccSys::field_658");
_Static_assert(offsetof(nuccSys, mode_label) == 0x660, "nuccSys::mode_label");
_Static_assert(offsetof(nuccSys, flag_768) == 0x768, "nuccSys::flag_768");
_Static_assert(offsetof(nuccSys, screen_86C) == 0x86C, "nuccSys::screen_86C");
_Static_assert(offsetof(nuccSys, screen_870) == 0x870, "nuccSys::screen_870");
_Static_assert(offsetof(nuccSys, screen_874) == 0x874, "nuccSys::screen_874");
_Static_assert(offsetof(nuccSys, screen_878) == 0x878, "nuccSys::screen_878");
_Static_assert(offsetof(nuccSys, screen_87C) == 0x87C, "nuccSys::screen_87C");
_Static_assert(offsetof(nuccSys, screen_880) == 0x880, "nuccSys::screen_880");
_Static_assert(offsetof(nuccSys, screen_884) == 0x884, "nuccSys::screen_884");
_Static_assert(offsetof(nuccSys, screen_888) == 0x888, "nuccSys::screen_888");
_Static_assert(offsetof(nuccSys, screen_88C) == 0x88C, "nuccSys::screen_88C");
_Static_assert(offsetof(nuccSys, screen_8D4) == 0x8D4, "nuccSys::screen_8D4");
_Static_assert(offsetof(nuccSys, screen_8F4) == 0x8F4, "nuccSys::screen_8F4");
_Static_assert(offsetof(nuccSys, screen_924) == 0x924, "nuccSys::screen_924");
_Static_assert(offsetof(nuccSys, field_948) == 0x948, "nuccSys::field_948");
_Static_assert(offsetof(nuccSys, field_950) == 0x950, "nuccSys::field_950");
_Static_assert(offsetof(nuccSys, reset_frame_flag) == 0x952, "nuccSys::reset_frame_flag");
_Static_assert(offsetof(nuccSys, geo_sphere_968) == 0x968, "nuccSys::geo_sphere_968");
_Static_assert(offsetof(nuccSys, crit_section_9B8) == 0x9B8, "nuccSys::crit_section_9B8");
_Static_assert(offsetof(nuccSys, crit_section_A08) == 0xA08, "nuccSys::crit_section_A08");
_Static_assert(offsetof(nuccSys, block_allocator) == 0xA70, "nuccSys::block_allocator");
_Static_assert(offsetof(nuccSys, large_array_C00) == 0xC00, "nuccSys::large_array_C00");
