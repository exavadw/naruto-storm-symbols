/* rbFrame s4 — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, sha 147e52a3e0d7)
 * Group: nuccSys, ccTaskManager, ccWorldManager, ccStageGimmick, ccCameraCtrl
 *
 * Classes included (>=3 methods with state_surface evidence):
 *   nuccSys         — size 0xf50 proven (FUN_140a017f0(0xf50,...) in Initialize)
 *   ccStageGimmick  — base class; subclass ccStageGimmickAnm alloc 0x328,
 *                     ccStageGimmickClump alloc 0x1c8
 *
 * Classes excluded (<3 methods in this build):
 *   ccWorldManager  — only Create + Ctrl (2 seeds)
 *   ccCameraCtrl    — zero symbols in s4
 *   ccTaskManager   — 8 methods but no ctor/factory with allocation size found;
 *                     surface yielded only 1 low-confidence vtable read at +0x80
 *
 * All fields are INFERRED from static decompilation, not CONFIRMED by runtime trace.
 * Rollback tags: SIM = simulation-critical, PRES = presentation-only, UNKNOWN = needs trace.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccSys — system/render singleton, size 0xf50 (proven)
 * Evidence: FUN_140a017f0(0xf50, "nuccSys.h", 0x241) in nuccSys::Initialize
 * Vtable: PTR_FUN_1411046e8 set at +0x3F0, +0x400, +0xE20 in ctor
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* +0x000 */ void     *vtable;                   /* ctor sets &PTR_FUN_1411046e8 at +0x3f0,+0x400 */
    /* +0x008 */ uint8_t   _pad_008[0x18];
    /* +0x020 */ uint8_t   light_param[384];         /* ctor FUN_140a56d50(param_1+0x20); s3 name carry-over */
    /* +0x1A0 */ uint8_t   fog_param[48];            /* ctor FUN_140a0f460(param_1+0x1a0); s3 name carry-over */
    /* +0x1D0 */ uint32_t  field_1D0;                /* ctor =0 */
    /* +0x1D4 */ uint8_t   _pad_1D4[4];
    /* +0x1D8 */ uint32_t  language_id;              /* ctor =0; Initialize sets LCID */
    /* +0x1DC */ uint8_t   _pad_1DC[4];
    /* +0x1E0 */ uint8_t   _pad_1E0[4];              /* ctor writes +0x1e4=0; gap */
    /* +0x1E4 */ uint32_t  field_1E4;                /* ctor =0 */
    /* +0x1E8 */ uint8_t   _pad_1E8[0xCC];
    /* +0x2B4 */ uint8_t   subobj_2B4[4];            /* ctor FUN_1401bf300 (geo_sphere-like) */
    /* +0x2B8 */ uint8_t   celshade_param[8];        /* ctor FUN_140a51460 */
    /* +0x2C0 */ uint64_t  field_2C0;                /* ctor =0 */
    /* +0x2C8 */ uint32_t  field_2C8;                /* ctor =0 */
    /* +0x2CC */ float     field_2CC;                /* ctor =1.0f */
    /* +0x2D0 */ float     field_2D0;                /* ctor =1.0f */
    /* +0x2D4 */ uint8_t   _pad_2D4[0xC];
    /* +0x2E0 */ uint64_t  field_2E0;                /* ctor =0 */
    /* +0x2E8 */ uint8_t   matrix_array_2E8[272];    /* ctor loop 16x stride 0x10, identity-ish */
    /* +0x3F8 */ uint64_t  field_3F8;                /* ctor =0 */
    /* +0x400 */ void     *vtable_400;               /* ctor &PTR_FUN_1411046e8 */
    /* +0x408 */ uint8_t   _pad_408[8];
    /* +0x410 */ float     sprite_mat_410;           /* ctor/SetSpriteMatrix =1.0f; s3 name */
    /* +0x414 */ float     sprite_mat_414;           /* ctor =1.0f */
    /* +0x418 */ float     sprite_mat_418;           /* ctor =1.0f */
    /* +0x41C */ float     sprite_mat_41C;           /* ctor =1.0f */
    /* +0x420 */ float     field_420;                /* ctor =1.0f */
    /* +0x424 */ float     field_424;                /* ctor =1.0f */
    /* +0x428 */ float     field_428;                /* ctor =1.0f */
    /* +0x42C */ double    field_42C;                /* ctor =1.0 */
    /* +0x434 */ uint64_t  field_434;                /* ctor =0 */
    /* +0x43C */ float     field_43C;                /* ctor =1.0f */
    /* +0x440 */ uint64_t  render_tex_440;           /* Initialize/CreateRenderTexture =0; s3 name */
    /* +0x448 */ uint64_t  render_tex_448;           /* Initialize/CreateRenderTexture =0 */
    /* +0x450 */ uint64_t  render_tex_450;           /* Initialize/CreateRenderTexture =0 */
    /* +0x458 */ uint64_t  render_tex_458;           /* Initialize/CreateRenderTexture =0 */
    /* +0x460 */ uint8_t   _pad_460[0x40];
    /* +0x4A0 */ uint32_t  target_framerate;         /* ResetFrame (=60/param); SIM — rollback-critical */
    /* +0x4A4 */ uint8_t   _pad_4A4[2];
    /* +0x4A6 */ uint16_t  aspect_num;               /* CreateRenderTexture read; PRES */
    /* +0x4A8 */ uint16_t  aspect_den;               /* CreateRenderTexture read; PRES */
    /* +0x4AA */ uint8_t   _pad_4AA[6];
    /* +0x4B0 */ uint32_t  field_4B0;                /* CreateRenderTexture read */
    /* +0x4B4 */ uint8_t   _pad_4B4[0x9C];
    /* +0x550 */ uint8_t   resolution[40];           /* ctor FUN_140a08e10(param_1+0x550); s3 name */
    /* +0x578 */ uint64_t  rt_alias_578;             /* CreateRenderTexture write ptr; PRES */
    /* +0x580 */ uint64_t  rt_alias_580;             /* CreateRenderTexture write ptr; PRES */
    /* +0x588 */ uint64_t  rt_alias_588;             /* CreateRenderTexture write ptr; PRES */
    /* +0x590 */ uint32_t  field_590;                /* ctor =0 */
    /* +0x594 */ uint32_t  field_594;                /* ctor =1 */
    /* +0x598 */ uint64_t  field_598;                /* ctor =0 */
    /* +0x5A0 */ uint64_t  field_5A0;                /* ctor =0 */
    /* +0x5A8 */ float     field_5A8;                /* ctor =1.0f */
    /* +0x5AC */ float     field_5AC;                /* ctor =1.0f */
    /* +0x5B0 */ uint8_t   _pad_5B0[0x10];
    /* +0x5C0 */ uint8_t   _pad_5C0[0x20];
    /* +0x5E0 */ uint8_t   matrix_block_5E0[80];     /* Initialize identity-like */
    /* +0x630 */ uint16_t  initialized_flag;         /* Initialize guard, set=1 */
    /* +0x632 */ uint8_t   _pad_632[3];
    /* +0x635 */ uint8_t   flag_635;                 /* ctor =1 */
    /* +0x636 */ uint8_t   _pad_636[6];
    /* +0x63C */ uint32_t  field_63C;                /* ctor =0xFFFF0064 */
    /* +0x640 */ char     *capture_label;            /* ctor "sim:capture" ptr */
    /* +0x648 */ char     *field_648;                /* ctor &DAT_1411049f8 */
    /* +0x650 */ char     *mode_label;               /* ctor "movie" */
    /* +0x658 */ uint8_t   flag_658;                 /* ctor =0 */
    /* +0x659 */ uint8_t   _pad_659[0x107];
    /* +0x760 */ uint8_t   _pad_760[0x100];
    /* +0x860 */ uint8_t   _pad_860[0x48];
    /* +0x8A8 */ uint64_t  screen_8A8;               /* ctor zero block +0x8a8..+0x930; s3 name */
    /* +0x8B0 */ uint64_t  screen_8B0;
    /* +0x8B8 */ uint64_t  screen_8B8;
    /* +0x8C0 */ uint64_t  screen_8C0;
    /* +0x8C8 */ uint64_t  screen_8C8;
    /* +0x8D0 */ uint64_t  screen_8D0;
    /* +0x8D8 */ uint64_t  screen_8D8;
    /* +0x8E0 */ uint64_t  screen_8E0;
    /* +0x8E8 */ uint64_t  screen_8E8;
    /* +0x8F0 */ uint64_t  screen_8F0;
    /* +0x8F8 */ uint64_t  screen_8F8;
    /* +0x900 */ uint64_t  screen_900;
    /* +0x908 */ uint64_t  screen_908;
    /* +0x910 */ uint64_t  screen_910;
    /* +0x918 */ uint64_t  screen_918;
    /* +0x920 */ uint64_t  screen_920;
    /* +0x928 */ uint64_t  screen_928;
    /* +0x930 */ uint64_t  screen_930;
    /* +0x938 */ uint64_t  field_938;                /* ctor =0 */
    /* +0x940 */ uint16_t  field_940;                /* ctor =0 */
    /* +0x942 */ uint8_t   field_942;                /* ctor =0x1e */
    /* +0x943 */ uint8_t   _pad_943[5];
    /* +0x948 */ uint64_t  field_948;                /* ctor =0 */
    /* +0x950 */ uint16_t  field_950;                /* ctor =0 */
    /* +0x952 */ uint8_t   reset_frame_flag;         /* ResetFrame; SIM — rollback-critical */
    /* +0x953 */ uint8_t   _pad_953[5];
    /* +0x958 */ uint8_t   geo_sphere_958[80];       /* ctor FUN_1401bf300(param_1+0x958); s3 name */
    /* +0x9A8 */ uint8_t   crit_section_9A8[80];     /* ctor FUN_140a23260; s3 name */
    /* +0x9F8 */ uint8_t   crit_section_9F8[80];     /* ctor FUN_140a23260; s3 name */
    /* +0xA48 */ uint8_t   _pad_A48[0x18];
    /* +0xA60 */ uint8_t   block_allocator[400];     /* ctor FUN_1401ca8f8(param_1+0xa60); s3 name */
    /* +0xBF0 */ uint8_t   large_array_BF0[560];     /* ctor loop region; 0xBF0..0xE1F (0x230 bytes) */
    /* +0xE20 */ void     *vtable_E20;               /* ctor &PTR_FUN_1411046e8 */
    /* +0xE28 */ uint64_t  field_E28;                /* ctor =0 */
    /* +0xE30 */ uint64_t  field_E30;                /* ctor =0 */
    /* +0xE38 */ uint8_t   _pad_E38[0x80];
    /* +0xEB8 */ uint8_t   _pad_EB8[0x90];           /* ctor zero block near end */
    /* +0xF48 */ uint32_t  field_F48;                /* ctor =0 */
    /* +0xF4C */ uint32_t  field_F4C;                /* ctor =1 */
} nuccSys_s4;

_Static_assert(sizeof(nuccSys_s4) == 0xF50, "nuccSys_s4 size must be 0xF50");
_Static_assert(offsetof(nuccSys_s4, vtable) == 0x0, "nuccSys::vtable");
_Static_assert(offsetof(nuccSys_s4, light_param) == 0x20, "nuccSys::light_param");
_Static_assert(offsetof(nuccSys_s4, fog_param) == 0x1A0, "nuccSys::fog_param");
_Static_assert(offsetof(nuccSys_s4, field_1D0) == 0x1D0, "nuccSys::field_1D0");
_Static_assert(offsetof(nuccSys_s4, language_id) == 0x1D8, "nuccSys::language_id");
_Static_assert(offsetof(nuccSys_s4, field_1E4) == 0x1E4, "nuccSys::field_1E4");
_Static_assert(offsetof(nuccSys_s4, subobj_2B4) == 0x2B4, "nuccSys::subobj_2B4");
_Static_assert(offsetof(nuccSys_s4, celshade_param) == 0x2B8, "nuccSys::celshade_param");
_Static_assert(offsetof(nuccSys_s4, field_2C0) == 0x2C0, "nuccSys::field_2C0");
_Static_assert(offsetof(nuccSys_s4, field_2C8) == 0x2C8, "nuccSys::field_2C8");
_Static_assert(offsetof(nuccSys_s4, field_2CC) == 0x2CC, "nuccSys::field_2CC");
_Static_assert(offsetof(nuccSys_s4, field_2D0) == 0x2D0, "nuccSys::field_2D0");
_Static_assert(offsetof(nuccSys_s4, field_2E0) == 0x2E0, "nuccSys::field_2E0");
_Static_assert(offsetof(nuccSys_s4, matrix_array_2E8) == 0x2E8, "nuccSys::matrix_array_2E8");
_Static_assert(offsetof(nuccSys_s4, field_3F8) == 0x3F8, "nuccSys::field_3F8");
_Static_assert(offsetof(nuccSys_s4, vtable_400) == 0x400, "nuccSys::vtable_400");
_Static_assert(offsetof(nuccSys_s4, sprite_mat_410) == 0x410, "nuccSys::sprite_mat_410");
_Static_assert(offsetof(nuccSys_s4, sprite_mat_414) == 0x414, "nuccSys::sprite_mat_414");
_Static_assert(offsetof(nuccSys_s4, sprite_mat_418) == 0x418, "nuccSys::sprite_mat_418");
_Static_assert(offsetof(nuccSys_s4, sprite_mat_41C) == 0x41C, "nuccSys::sprite_mat_41C");
_Static_assert(offsetof(nuccSys_s4, field_420) == 0x420, "nuccSys::field_420");
_Static_assert(offsetof(nuccSys_s4, field_424) == 0x424, "nuccSys::field_424");
_Static_assert(offsetof(nuccSys_s4, field_428) == 0x428, "nuccSys::field_428");
_Static_assert(offsetof(nuccSys_s4, field_42C) == 0x42C, "nuccSys::field_42C");
_Static_assert(offsetof(nuccSys_s4, field_434) == 0x434, "nuccSys::field_434");
_Static_assert(offsetof(nuccSys_s4, field_43C) == 0x43C, "nuccSys::field_43C");
_Static_assert(offsetof(nuccSys_s4, render_tex_440) == 0x440, "nuccSys::render_tex_440");
_Static_assert(offsetof(nuccSys_s4, render_tex_448) == 0x448, "nuccSys::render_tex_448");
_Static_assert(offsetof(nuccSys_s4, render_tex_450) == 0x450, "nuccSys::render_tex_450");
_Static_assert(offsetof(nuccSys_s4, render_tex_458) == 0x458, "nuccSys::render_tex_458");
_Static_assert(offsetof(nuccSys_s4, target_framerate) == 0x4A0, "nuccSys::target_framerate");
_Static_assert(offsetof(nuccSys_s4, aspect_num) == 0x4A6, "nuccSys::aspect_num");
_Static_assert(offsetof(nuccSys_s4, aspect_den) == 0x4A8, "nuccSys::aspect_den");
_Static_assert(offsetof(nuccSys_s4, field_4B0) == 0x4B0, "nuccSys::field_4B0");
_Static_assert(offsetof(nuccSys_s4, resolution) == 0x550, "nuccSys::resolution");
_Static_assert(offsetof(nuccSys_s4, rt_alias_578) == 0x578, "nuccSys::rt_alias_578");
_Static_assert(offsetof(nuccSys_s4, rt_alias_580) == 0x580, "nuccSys::rt_alias_580");
_Static_assert(offsetof(nuccSys_s4, rt_alias_588) == 0x588, "nuccSys::rt_alias_588");
_Static_assert(offsetof(nuccSys_s4, field_590) == 0x590, "nuccSys::field_590");
_Static_assert(offsetof(nuccSys_s4, field_594) == 0x594, "nuccSys::field_594");
_Static_assert(offsetof(nuccSys_s4, field_598) == 0x598, "nuccSys::field_598");
_Static_assert(offsetof(nuccSys_s4, field_5A0) == 0x5A0, "nuccSys::field_5A0");
_Static_assert(offsetof(nuccSys_s4, field_5A8) == 0x5A8, "nuccSys::field_5A8");
_Static_assert(offsetof(nuccSys_s4, field_5AC) == 0x5AC, "nuccSys::field_5AC");
_Static_assert(offsetof(nuccSys_s4, matrix_block_5E0) == 0x5E0, "nuccSys::matrix_block_5E0");
_Static_assert(offsetof(nuccSys_s4, initialized_flag) == 0x630, "nuccSys::initialized_flag");
_Static_assert(offsetof(nuccSys_s4, flag_635) == 0x635, "nuccSys::flag_635");
_Static_assert(offsetof(nuccSys_s4, field_63C) == 0x63C, "nuccSys::field_63C");
_Static_assert(offsetof(nuccSys_s4, capture_label) == 0x640, "nuccSys::capture_label");
_Static_assert(offsetof(nuccSys_s4, field_648) == 0x648, "nuccSys::field_648");
_Static_assert(offsetof(nuccSys_s4, mode_label) == 0x650, "nuccSys::mode_label");
_Static_assert(offsetof(nuccSys_s4, flag_658) == 0x658, "nuccSys::flag_658");
_Static_assert(offsetof(nuccSys_s4, screen_8A8) == 0x8A8, "nuccSys::screen_8A8");
_Static_assert(offsetof(nuccSys_s4, screen_930) == 0x930, "nuccSys::screen_930");
_Static_assert(offsetof(nuccSys_s4, field_938) == 0x938, "nuccSys::field_938");
_Static_assert(offsetof(nuccSys_s4, field_940) == 0x940, "nuccSys::field_940");
_Static_assert(offsetof(nuccSys_s4, field_942) == 0x942, "nuccSys::field_942");
_Static_assert(offsetof(nuccSys_s4, field_948) == 0x948, "nuccSys::field_948");
_Static_assert(offsetof(nuccSys_s4, field_950) == 0x950, "nuccSys::field_950");
_Static_assert(offsetof(nuccSys_s4, reset_frame_flag) == 0x952, "nuccSys::reset_frame_flag");
_Static_assert(offsetof(nuccSys_s4, geo_sphere_958) == 0x958, "nuccSys::geo_sphere_958");
_Static_assert(offsetof(nuccSys_s4, crit_section_9A8) == 0x9A8, "nuccSys::crit_section_9A8");
_Static_assert(offsetof(nuccSys_s4, crit_section_9F8) == 0x9F8, "nuccSys::crit_section_9F8");
_Static_assert(offsetof(nuccSys_s4, block_allocator) == 0xA60, "nuccSys::block_allocator");
_Static_assert(offsetof(nuccSys_s4, large_array_BF0) == 0xBF0, "nuccSys::large_array_BF0");
_Static_assert(offsetof(nuccSys_s4, vtable_E20) == 0xE20, "nuccSys::vtable_E20");
_Static_assert(offsetof(nuccSys_s4, field_E28) == 0xE28, "nuccSys::field_E28");
_Static_assert(offsetof(nuccSys_s4, field_E30) == 0xE30, "nuccSys::field_E30");
_Static_assert(offsetof(nuccSys_s4, field_F48) == 0xF48, "nuccSys::field_F48");
_Static_assert(offsetof(nuccSys_s4, field_F4C) == 0xF4C, "nuccSys::field_F4C");

/* =========================================================================
 * ccStageGimmick — base class for stage gimmicks
 * Size: base class size unproven directly; subclass ccStageGimmickAnm allocated
 *       at 0x328 (FUN_140a017f0 in ccStageGimmickParamManager::GetParam),
 *       subclass ccStageGimmickClump allocated at 0x1c8 (FUN_140a017f0 in
 *       CreateGimmick_Clump). Base is smaller than both.
 * Vtable: PTR_FUN_1410d0568 set in ctor at +0x0
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* +0x000 */ void     *vtable;                   /* ctor &PTR_FUN_1410d0568 */
    /* +0x008 */ uint8_t   _pad_008[8];
    /* +0x010 */ uint8_t   subobj_010[0x28];         /* ctor FUN_1401ca8f8(param_1+0x10); 0x10..0x37 */
    /* +0x038 */ uint8_t   _pad_038[0x80];           /* gap before memset region */
    /* +0x0B8 */ uint8_t   memset_region[0x58];      /* ctor memset(param_1+0xB8, 0, 0x58) */
    /* +0x110 */ uint64_t  gimmick_param_ptr;        /* ctor param_1[0x22]=0; factory writes here */
    /* +0x118 */ uint8_t   subobj_118[0x28];         /* ctor FUN_140a33040(param_1+0x118); 0x118..0x13F */
    /* +0x140 */ uint8_t   _pad_140[0x1E8];          /* remainder to reach subclass min 0x328 */
} ccStageGimmick_s4;

/* No sizeof assert: base class size not directly proven. Subclass bounds:
 *   ccStageGimmickAnm  >= 0x328
 *   ccStageGimmickClump >= 0x1c8
 * Field offsets verified against ctor decompilation. */
_Static_assert(offsetof(ccStageGimmick_s4, vtable) == 0x0, "ccStageGimmick::vtable");
_Static_assert(offsetof(ccStageGimmick_s4, subobj_010) == 0x10, "ccStageGimmick::subobj_010");
_Static_assert(offsetof(ccStageGimmick_s4, memset_region) == 0xB8, "ccStageGimmick::memset_region");
_Static_assert(offsetof(ccStageGimmick_s4, gimmick_param_ptr) == 0x110, "ccStageGimmick::gimmick_param_ptr");
_Static_assert(offsetof(ccStageGimmick_s4, subobj_118) == 0x118, "ccStageGimmick::subobj_118");

/* =========================================================================
 * ccTaskManager — task scheduling singleton (stub)
 * Size: UNKNOWN — no ctor or allocator call found in s4 symbols.
 * Likely a global/static object at DAT_1416bda20.
 * Surface analysis yielded only 1 low-confidence field (vtable dispatch at +0x80).
 * Excluded from full reconstruction per TASK.md rules (insufficient evidence).
 * ========================================================================= */
/* No struct defined. See rbFrame-fields.tsv for the single observed access. */

/* =========================================================================
 * ccWorldManager — EXCLUDED (only 2 methods: Create, Ctrl)
 * ccCameraCtrl   — EXCLUDED (0 symbols in s4)
 * ========================================================================= */