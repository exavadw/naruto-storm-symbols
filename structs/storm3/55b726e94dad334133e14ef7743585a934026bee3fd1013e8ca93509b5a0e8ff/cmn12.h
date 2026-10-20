/*
 * cmn12.h — struct group cmn12 for build s3 (NARUTO STORM 3 Full Burst HD PC, NSUNS3.exe)
 *
 * Classes: ccUiFontCustom, ccUiKeyDisp
 * Skipped: ccUiFont::_Command (only 1 method in this build, <3 threshold)
 *
 * All layouts are INFERRED from static decompilation of s3 x64 code.
 * Sizes proven from operator new / allocator calls in factory functions.
 * Field names derived from s3 strings/code and Storm 3 symbols only.
 *
 * Build: s3 (sha 55b726e94dad334133e14ef7743585a934026bee3fd1013e8ca93509b5a0e8ff)
 * Image base: 0x140000000
 */

#ifndef CMN12_S3_H
#define CMN12_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccUiFontCustom — custom font renderer with icon support
 *
 * Size: 0x180 (proven from ccFileLoadListForUi::LoadTh(0x180, "source\\ui\\ccUiFont.cpp")
 *   in ccUiFont::Initialize @ RVA 0x76CF00)
 * Vtable: PTR_FUN_1409ef738 (set in ctor @ RVA 0x792340)
 * Parent chain: ccUiFontCustom -> nuccFontTag -> ... (base vtable set by nuccFontTag ctor)
 */
typedef struct __attribute__((packed)) ccUiFontCustom {
    /* +0x000 */ void *vtable;              /* PRES: PTR_FUN_1409ef738 after ctor */
    /* +0x008 */ uint8_t _base_0x008[0x54]; /* UNKNOWN: inherited fields 0x08-0x5B */
    /* +0x05C */ float color_alpha_mul;     /* PRES: read in SetColor 0x7925F0, multiplied by 255 */
    /* +0x060 */ uint8_t _pad_0x060[0x08];  /* UNKNOWN: gap 0x60-0x67 */
    /* +0x068 */ uint32_t draw_color_flags; /* PRES: passed as arg in DrawCustom 0x7923E0 */
    /* +0x06C */ uint8_t _pad_0x06C[0x08];  /* UNKNOWN: gap 0x6C-0x73 */
    /* +0x074 */ uint8_t draw_pos[0x08];    /* PRES: Nucc::Vector2 copy in DrawCustom 0x7923E0 */
    /* +0x07C */ float draw_scale_y;        /* PRES: *(float*)(p+0x78) in DrawCustom 0x7923E0 */
    /* +0x080 */ uint8_t _inherited_0x080[0xA4]; /* UNKNOWN: inherited fields 0x80-0x123 */
    /* +0x124 */ uint32_t parent_flag_1;    /* PRES: =1 from parent FUN equiv */
    /* +0x128 */ uint8_t _pad_0x128[0x0C];  /* UNKNOWN: gap 0x128-0x133 */
    /* +0x134 */ float scale_x;             /* PRES: =1.0f from parent */
    /* +0x138 */ uint8_t _pad_0x138[0x04];  /* UNKNOWN: gap 0x138-0x13B */
    /* +0x13C */ float scale_y;             /* PRES: =1.0f from parent */
    /* +0x140 */ uint8_t _pad_0x140[0x04];  /* UNKNOWN: gap 0x140-0x143 */
    /* +0x144 */ uint32_t parent_flag_0;    /* PRES: =0 from parent */
    /* +0x148 */ uint64_t subobj_148;       /* PRES: initialized by parent */
    /* +0x150 */ uint64_t subobj_150;       /* PRES: initialized by parent */
    /* +0x158 */ uint32_t parent_flag_1b;   /* PRES: =1 from parent param_1[0x2b] */
    /* +0x15C */ uint32_t parent_flag_1c;   /* PRES: =1 from parent */
    /* +0x160 */ uint32_t font_tag;         /* PRES: =5 in ctor 0x792340 */
    /* +0x164 */ uint64_t draw_enabled;     /* SIM: =1 in ctor, checked !=0 in DrawCustom 0x7923E0 */
    /* +0x16C */ uint32_t _pad_0x16C;       /* UNKNOWN: alignment padding */
    /* +0x170 */ void *icon_font_data;      /* SIM: ptr at param_1[0x2e], alloc/free in GetIcon/dtor */
    /* +0x178 */ uint8_t _pad_0x178[0x08];  /* UNKNOWN: tail padding to 0x180 */
} ccUiFontCustom;

static_assert(sizeof(ccUiFontCustom) == 0x180, "ccUiFontCustom size must be 0x180");
static_assert(offsetof(ccUiFontCustom, vtable) == 0x000, "ccUiFontCustom::vtable");
static_assert(offsetof(ccUiFontCustom, color_alpha_mul) == 0x05C, "ccUiFontCustom::color_alpha_mul");
static_assert(offsetof(ccUiFontCustom, draw_color_flags) == 0x068, "ccUiFontCustom::draw_color_flags");
static_assert(offsetof(ccUiFontCustom, draw_pos) == 0x074, "ccUiFontCustom::draw_pos");
static_assert(offsetof(ccUiFontCustom, draw_scale_y) == 0x07C, "ccUiFontCustom::draw_scale_y");
static_assert(offsetof(ccUiFontCustom, parent_flag_1) == 0x124, "ccUiFontCustom::parent_flag_1");
static_assert(offsetof(ccUiFontCustom, scale_x) == 0x134, "ccUiFontCustom::scale_x");
static_assert(offsetof(ccUiFontCustom, scale_y) == 0x13C, "ccUiFontCustom::scale_y");
static_assert(offsetof(ccUiFontCustom, parent_flag_0) == 0x144, "ccUiFontCustom::parent_flag_0");
static_assert(offsetof(ccUiFontCustom, subobj_148) == 0x148, "ccUiFontCustom::subobj_148");
static_assert(offsetof(ccUiFontCustom, subobj_150) == 0x150, "ccUiFontCustom::subobj_150");
static_assert(offsetof(ccUiFontCustom, parent_flag_1b) == 0x158, "ccUiFontCustom::parent_flag_1b");
static_assert(offsetof(ccUiFontCustom, parent_flag_1c) == 0x15C, "ccUiFontCustom::parent_flag_1c");
static_assert(offsetof(ccUiFontCustom, font_tag) == 0x160, "ccUiFontCustom::font_tag");
static_assert(offsetof(ccUiFontCustom, draw_enabled) == 0x164, "ccUiFontCustom::draw_enabled");
static_assert(offsetof(ccUiFontCustom, icon_font_data) == 0x170, "ccUiFontCustom::icon_font_data");

/*
 * ccUiKeyDisp — key/button display widget (shows button prompts on screen)
 *
 * Size: 0x58 (proven from ccFileLoadListForUi::LoadTh(0x58, "source\\ui\\ccUiKeyHelp.cpp", 0x38b)
 *   in ccUiKeyHelp::CreateData @ RVA 0x7515F0)
 * Vtable: PTR_FUN_1409eea58 (set in ctor @ RVA 0x77E480)
 * Parent: FUN equiv (sets base fields at +0x08,+0x10,+0x14)
 */
typedef struct __attribute__((packed)) ccUiKeyDisp {
    /* +0x00 */ void *vtable;           /* PRES: PTR_FUN_1409eea58 after ctor */
    /* +0x08 */ uint64_t base_field_08; /* PRES: inherited from parent */
    /* +0x10 */ uint16_t base_flag_10;  /* PRES: =1 from parent */
    /* +0x12 */ uint8_t _pad_0x12[0x02]; /* UNKNOWN: alignment */
    /* +0x14 */ uint32_t base_field_14; /* PRES: =0 from parent */
    /* +0x18 */ void *font_ptr;         /* PRES: cleared in Initialize/Finalize, set in SetFontButton */
    /* +0x20 */ void *font_obj_a;       /* PRES: deleted in Finalize, checked in GetWidth/SetPos/SetOpacity */
    /* +0x28 */ void *font_obj_b;       /* PRES: deleted in Finalize, vfunc+0x38 in SetPos */
    /* +0x30 */ void *font_obj_c;       /* PRES: deleted in Finalize, created in SetFontButton via LoadTh(0x1e8) */
    /* +0x38 */ float scale;            /* PRES: set in SetScale/SetScaleXForFont, read in GetWidth as scale*48.0 */
    /* +0x3C */ uint32_t opacity_color; /* PRES: from DAT_140b6da74 in ctor */
    /* +0x40 */ uint32_t visibility;    /* PRES: =1 in ctor and Initialize */
    /* +0x44 */ uint32_t button_id;     /* PRES: 0xffffffff in ctor, set from ccGetDependButtonId in Initialize */
    /* +0x48 */ uint32_t field_48;      /* PRES: set in Initialize from param_3 */
    /* +0x4C */ uint32_t font_type_tag; /* PRES: =5 in ctor, set in Initialize from param_5 */
    /* +0x50 */ uint8_t state;          /* PRES: 0=uninit, 1=initialized, 2=finalized */
    /* +0x51 */ uint8_t _pad_0x51[0x07]; /* UNKNOWN: tail padding to 0x58 */
} ccUiKeyDisp;

static_assert(sizeof(ccUiKeyDisp) == 0x58, "ccUiKeyDisp size must be 0x58");
static_assert(offsetof(ccUiKeyDisp, vtable) == 0x00, "ccUiKeyDisp::vtable");
static_assert(offsetof(ccUiKeyDisp, base_field_08) == 0x08, "ccUiKeyDisp::base_field_08");
static_assert(offsetof(ccUiKeyDisp, base_flag_10) == 0x10, "ccUiKeyDisp::base_flag_10");
static_assert(offsetof(ccUiKeyDisp, base_field_14) == 0x14, "ccUiKeyDisp::base_field_14");
static_assert(offsetof(ccUiKeyDisp, font_ptr) == 0x18, "ccUiKeyDisp::font_ptr");
static_assert(offsetof(ccUiKeyDisp, font_obj_a) == 0x20, "ccUiKeyDisp::font_obj_a");
static_assert(offsetof(ccUiKeyDisp, font_obj_b) == 0x28, "ccUiKeyDisp::font_obj_b");
static_assert(offsetof(ccUiKeyDisp, font_obj_c) == 0x30, "ccUiKeyDisp::font_obj_c");
static_assert(offsetof(ccUiKeyDisp, scale) == 0x38, "ccUiKeyDisp::scale");
static_assert(offsetof(ccUiKeyDisp, opacity_color) == 0x3C, "ccUiKeyDisp::opacity_color");
static_assert(offsetof(ccUiKeyDisp, visibility) == 0x40, "ccUiKeyDisp::visibility");
static_assert(offsetof(ccUiKeyDisp, button_id) == 0x44, "ccUiKeyDisp::button_id");
static_assert(offsetof(ccUiKeyDisp, field_48) == 0x48, "ccUiKeyDisp::field_48");
static_assert(offsetof(ccUiKeyDisp, font_type_tag) == 0x4C, "ccUiKeyDisp::font_type_tag");
static_assert(offsetof(ccUiKeyDisp, state) == 0x50, "ccUiKeyDisp::state");

#endif /* CMN12_S3_H */