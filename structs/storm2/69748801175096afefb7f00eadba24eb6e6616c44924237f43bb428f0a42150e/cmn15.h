/* cmn15 s2 — ccUiScrollBar, ccUiScrollFont (INFERRED)
 * Build: s2 (NARUTO STORM 2 PC, NSUNS2.exe, image base 0x140000000)
 * Date: 2026-10-19
 * All results INFERRED from static decompilation. Nothing is CONFIRMED by runtime trace.
 */

#ifndef CMN15_S2_H
#define CMN15_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccUiScrollBar — size 0x120 (proven by ccUiSelectList::CreateScrollBar, RVA 0x699B60)
 * Vtable: PTR_FUN_1408a2ca8 (from ctor RVA 0x69FF80)
 * Base sub-object: ccUiObjectContainer at offset 0x58 (size 0x40)
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void       *vtable;            /* PRES: PTR_FUN_1408a2ca8 */
    /* 0x08 */ uint8_t     _pad_08[0x30];    /* UNKNOWN: inherited ccUiTaskBase fields */
    /* 0x38 */ void       *bar_sprite;        /* PRES: xfbin bar clump (Initialize 0x6A0180) */
    /* 0x40 */ void       *knob_sprite;       /* PRES: xfbin knob clump (Initialize 0x6A0180) */
    /* 0x48 */ void       *arrow1_sprite;     /* PRES: xfbin arrow1 anim (Initialize 0x6A0180, GetArrowAnmTime 0x6A11D0) */
    /* 0x50 */ void       *arrow2_sprite;     /* PRES: xfbin arrow2 anim (Initialize 0x6A0180, GetArrowAnmTime 0x6A11D0) */
    /* 0x58 */ uint8_t     base_subobj[0x40]; /* PRES: ccUiObjectContainer (ctor calls ccUiObjectContainer::ccUiObjectContainer(param_1+0x58)) */
    /* 0x98 */ void       *split_parts_bar;   /* PRES: ccUiSplitParts* created in Initialize(0x128) at 0x98 */
    /* 0xA0 */ void       *split_parts_knob;  /* PRES: ccUiSplitParts* created in Initialize(0x128) at 0xA0; used in SetLength/SetRange */
    /* 0xA8 */ void       *field_A8;          /* UNKNOWN: zeroed in ctor, checked != 0 in Ctrl for CtrlAttach gate */
    /* 0xB0 */ uint8_t     _pad_B0[0x10];    /* UNKNOWN: gap fill */
    /* 0xC0 */ float       visible_range;     /* SIM: scroll visible range (SetScroll 0x6A0630, SetRange 0x6A0780) */
    /* 0xC4 */ float       scroll_max;        /* SIM: max scroll value, default 1.0f (ctor, SetRange 0x6A0780) */
    /* 0xC8 */ float       scroll_min;        /* SIM: min scroll value, default 0.0f (ctor, SetRange stores fVar3 here) */
    /* 0xCC */ float       scroll_pos;        /* SIM: current scroll position (SetScroll 0x6A0630, SetMatrix/SetPos/Translate) */
    /* 0xD0 */ int32_t     ctrl_enable;       /* PRES: gate for Ctrl processing, set 1 in ctor (Ctrl 0x6A0430) */
    /* 0xD4 */ int32_t     arrow_anim_flag;   /* PRES: arrow animation active flag (Ctrl 0x6A0430) */
    /* 0xD8 */ uint32_t    arrow_timeline;    /* PRES: cached arrow timeline value (Ctrl 0x6A0430) */
    /* 0xDC */ uint8_t     transform[0x44];   /* PRES: Nucc::Matrix44_MathGeo (SetMatrix 0x6A0890, SetPos 0x6A0970, Translate 0x6A0AC0) */
} ccUiScrollBar;

static_assert(sizeof(ccUiScrollBar) == 0x120, "ccUiScrollBar size must be 0x120");
static_assert(offsetof(ccUiScrollBar, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(ccUiScrollBar, bar_sprite) == 0x38, "bar_sprite @ 0x38");
static_assert(offsetof(ccUiScrollBar, knob_sprite) == 0x40, "knob_sprite @ 0x40");
static_assert(offsetof(ccUiScrollBar, arrow1_sprite) == 0x48, "arrow1_sprite @ 0x48");
static_assert(offsetof(ccUiScrollBar, arrow2_sprite) == 0x50, "arrow2_sprite @ 0x50");
static_assert(offsetof(ccUiScrollBar, base_subobj) == 0x58, "base_subobj @ 0x58");
static_assert(offsetof(ccUiScrollBar, split_parts_bar) == 0x98, "split_parts_bar @ 0x98");
static_assert(offsetof(ccUiScrollBar, split_parts_knob) == 0xA0, "split_parts_knob @ 0xA0");
static_assert(offsetof(ccUiScrollBar, field_A8) == 0xA8, "field_A8 @ 0xA8");
static_assert(offsetof(ccUiScrollBar, visible_range) == 0xC0, "visible_range @ 0xC0");
static_assert(offsetof(ccUiScrollBar, scroll_max) == 0xC4, "scroll_max @ 0xC4");
static_assert(offsetof(ccUiScrollBar, scroll_min) == 0xC8, "scroll_min @ 0xC8");
static_assert(offsetof(ccUiScrollBar, scroll_pos) == 0xCC, "scroll_pos @ 0xCC");
static_assert(offsetof(ccUiScrollBar, ctrl_enable) == 0xD0, "ctrl_enable @ 0xD0");
static_assert(offsetof(ccUiScrollBar, arrow_anim_flag) == 0xD4, "arrow_anim_flag @ 0xD4");
static_assert(offsetof(ccUiScrollBar, arrow_timeline) == 0xD8, "arrow_timeline @ 0xD8");
static_assert(offsetof(ccUiScrollBar, transform) == 0xDC, "transform @ 0xDC");

/* ccUiScrollFont — size 0x1D8 (proven by ccUiSelectList::CreateScrollFont, RVA 0x699D10)
 * Primary vtable: PTR_FUN_1408a2988 (from ctor RVA 0x69BC40)
 * Secondary vtable: PTR_LAB_1408a29b0 at offset 0x38 (from ctor)
 * Base sub-object: ccUiOpenCloseCtrl at offset 0x40 (via ccClassFnManager), ccUiObjectContainer at 0x78
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void       *vtable;             /* PRES: PTR_FUN_1408a2988 */
    /* 0x08 */ uint8_t     _pad_08[0x30];     /* UNKNOWN: inherited ccUiTaskBase fields */
    /* 0x38 */ void       *secondary_vtable;   /* PRES: PTR_LAB_1408a29b0 (ctor assigns param_1[7]) */
    /* 0x40 */ uint64_t    child_count;        /* PRES: count for array iteration in Ctrl/Initialize (stride 0x28) */
    /* 0x48 */ void       *child_array;        /* PRES: pointer to child objects array (stride 0x28, type checks in Ctrl) */
    /* 0x50 */ void       *field_50;           /* PRES: type==1 check target in Ctrl */
    /* 0x58 */ void       *field_58;           /* PRES: type==3 search result in Initialize */
    /* 0x60 */ uint8_t     _pad_60[0x18];     /* UNKNOWN: gap to base sub-object */
    /* 0x78 */ uint8_t     base_subobj[0x40]; /* PRES: ccUiObjectContainer (FUN_14069de50 init in ctor) */
    /* 0xB8 */ void       *font_object;        /* PRES: ccUiFont* (Initialize creates, GetFont/SetText/CtrlScroll use) */
    /* 0xC0 */ void       *scroll_helper;      /* PRES: 0x148-sized helper clump (SetPresetStatus creates via LoadTh) */
    /* 0xC8 */ uint32_t    field_C8;           /* UNKNOWN: value 5 in ctor */
    /* 0xCC */ uint32_t    _pad_CC;            /* alignment padding */
    /* 0xD0 */ uint8_t     text_buffer[0x18]; /* PRES: std::string SSO buffer (SetText 0x69E7E0) */
    /* 0xE8 */ uint64_t    text_capacity;      /* PRES: SSO threshold (<0x10 = inline) (SetText 0x69E7E0) */
    /* 0xF0 */ uint8_t     _pad_F0[0x18];     /* UNKNOWN: gap */
    /* 0x108 */ uint32_t   line_count;         /* SIM: character count from nuccFont2::GetLength (SetText 0x69E7E0) */
    /* 0x10C */ uint32_t   text_width;         /* SIM: pixel width from ccUiFont::GetWidth (SetText, CtrlScroll comparison) */
    /* 0x110 */ float      pos_x;              /* PRES: X position (SetPresetStatus Nucc::Vector3::Set, DrawScroll ccUiFont::SetPos) */
    /* 0x114 */ float      pos_y;              /* PRES: Y position (DrawScroll ccUiFont::SetPos) */
    /* 0x118 */ float      pos_z;              /* PRES: Z position (DrawScroll ccUiFont::SetPos uses - 0.1) */
    /* 0x11C */ uint32_t    _pad_11C;          /* alignment padding */
    /* 0x120 */ void       *attach_dummy;       /* PRES: attached object ptr (SetAttachDummy, CtrlAttach) */
    /* 0x128 */ uint32_t    attach_flag1;       /* PRES: param_6 flag (SetAttachDummy, CtrlAttach) */
    /* 0x12C */ uint32_t    attach_flag2;       /* PRES: param_7 flag (SetAttachDummy, CtrlAttach) */
    /* 0x130 */ uint32_t    preset_field_130;   /* PRES: from DAT_140ab8b70 table (SetPresetStatus 0x69EB90) */
    /* 0x134 */ uint32_t    preset_line_mult;   /* PRES: line multiplier from preset table (SetPresetStatus, CtrlScroll) */
    /* 0x138 */ float       draw_width;         /* SIM: computed draw width (SetDrawWidth 0x69EA70, CalcScrollText, CtrlScroll) */
    /* 0x13C */ uint32_t    char_index;         /* SIM: current character index in scroll (CtrlScroll 0x69F490, DrawScroll) */
    /* 0x140 */ float       preset_field_140;   /* PRES: margin/padding from preset table (CalcScrollText subtracts *2.0) */
    /* 0x144 */ float       scroll_offset;      /* SIM: current pixel offset for scroll rendering (CtrlScroll modifies) */
    /* 0x148 */ uint32_t    _pad_148;           /* alignment padding */
    /* 0x14C */ float       scroll_speed;       /* SIM: scroll animation speed (CtrlScroll checks != 0.0) */
    /* 0x150 */ uint32_t    preset_field_150;   /* PRES: timer threshold from preset table (CtrlScroll compares to timer_accum) */
    /* 0x154 */ uint32_t    timer_accum;        /* SIM: accumulated timer ticks (CtrlScroll increments by SpeedRate2AnmTime) */
    /* 0x158 */ float       pos_offset_x;       /* PRES: X offset applied in DrawScroll (subtracted from pos_x) */
    /* 0x15C */ uint32_t    scroll_enable;      /* SIM: scroll animation on/off (CalcScrollText sets, CtrlScroll gates) */
    /* 0x160 */ uint32_t    calc_pending;       /* PRES: triggers CalcScrollText when set (Initialize sets 1, Ctrl checks) */
    /* 0x164 */ uint32_t    recalc_flag;        /* PRES: cleared after CalcScrollText runs (SetText sets 1, CalcScrollText clears) */
    /* 0x168 */ uint32_t    ctrl_active;        /* PRES: gate for Ctrl processing (Ctrl 0x69E710 checks != 0) */
    /* 0x16C */ uint32_t    _pad_16C;           /* alignment padding */
    /* 0x170 */ uint8_t     draw_state1[0x30]; /* PRES: render params for first draw pass (DrawScroll FUN_14069fa10/FUN_14069fc20) */
    /* 0x1A0 */ uint8_t     draw_state2[0x30]; /* PRES: render params for second draw pass (DrawScroll) */
    /* 0x1D0 */ uint32_t    field_1D0;          /* UNKNOWN: value 1 in ctor */
    /* 0x1D4 */ uint32_t    ruby_enable;        /* PRES: ruby/furigana toggle (SetRubyEnable, SetText checks) */
} ccUiScrollFont;

static_assert(sizeof(ccUiScrollFont) == 0x1D8, "ccUiScrollFont size must be 0x1D8");
static_assert(offsetof(ccUiScrollFont, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(ccUiScrollFont, secondary_vtable) == 0x38, "secondary_vtable @ 0x38");
static_assert(offsetof(ccUiScrollFont, child_count) == 0x40, "child_count @ 0x40");
static_assert(offsetof(ccUiScrollFont, child_array) == 0x48, "child_array @ 0x48");
static_assert(offsetof(ccUiScrollFont, field_50) == 0x50, "field_50 @ 0x50");
static_assert(offsetof(ccUiScrollFont, field_58) == 0x58, "field_58 @ 0x58");
static_assert(offsetof(ccUiScrollFont, base_subobj) == 0x78, "base_subobj @ 0x78");
static_assert(offsetof(ccUiScrollFont, font_object) == 0xB8, "font_object @ 0xB8");
static_assert(offsetof(ccUiScrollFont, scroll_helper) == 0xC0, "scroll_helper @ 0xC0");
static_assert(offsetof(ccUiScrollFont, field_C8) == 0xC8, "field_C8 @ 0xC8");
static_assert(offsetof(ccUiScrollFont, text_buffer) == 0xD0, "text_buffer @ 0xD0");
static_assert(offsetof(ccUiScrollFont, text_capacity) == 0xE8, "text_capacity @ 0xE8");
static_assert(offsetof(ccUiScrollFont, line_count) == 0x108, "line_count @ 0x108");
static_assert(offsetof(ccUiScrollFont, text_width) == 0x10C, "text_width @ 0x10C");
static_assert(offsetof(ccUiScrollFont, pos_x) == 0x110, "pos_x @ 0x110");
static_assert(offsetof(ccUiScrollFont, pos_y) == 0x114, "pos_y @ 0x114");
static_assert(offsetof(ccUiScrollFont, pos_z) == 0x118, "pos_z @ 0x118");
static_assert(offsetof(ccUiScrollFont, attach_dummy) == 0x120, "attach_dummy @ 0x120");
static_assert(offsetof(ccUiScrollFont, attach_flag1) == 0x128, "attach_flag1 @ 0x128");
static_assert(offsetof(ccUiScrollFont, attach_flag2) == 0x12C, "attach_flag2 @ 0x12C");
static_assert(offsetof(ccUiScrollFont, preset_field_130) == 0x130, "preset_field_130 @ 0x130");
static_assert(offsetof(ccUiScrollFont, preset_line_mult) == 0x134, "preset_line_mult @ 0x134");
static_assert(offsetof(ccUiScrollFont, draw_width) == 0x138, "draw_width @ 0x138");
static_assert(offsetof(ccUiScrollFont, char_index) == 0x13C, "char_index @ 0x13C");
static_assert(offsetof(ccUiScrollFont, preset_field_140) == 0x140, "preset_field_140 @ 0x140");
static_assert(offsetof(ccUiScrollFont, scroll_offset) == 0x144, "scroll_offset @ 0x144");
static_assert(offsetof(ccUiScrollFont, scroll_speed) == 0x14C, "scroll_speed @ 0x14C");
static_assert(offsetof(ccUiScrollFont, preset_field_150) == 0x150, "preset_field_150 @ 0x150");
static_assert(offsetof(ccUiScrollFont, timer_accum) == 0x154, "timer_accum @ 0x154");
static_assert(offsetof(ccUiScrollFont, pos_offset_x) == 0x158, "pos_offset_x @ 0x158");
static_assert(offsetof(ccUiScrollFont, scroll_enable) == 0x15C, "scroll_enable @ 0x15C");
static_assert(offsetof(ccUiScrollFont, calc_pending) == 0x160, "calc_pending @ 0x160");
static_assert(offsetof(ccUiScrollFont, recalc_flag) == 0x164, "recalc_flag @ 0x164");
static_assert(offsetof(ccUiScrollFont, ctrl_active) == 0x168, "ctrl_active @ 0x168");
static_assert(offsetof(ccUiScrollFont, draw_state1) == 0x170, "draw_state1 @ 0x170");
static_assert(offsetof(ccUiScrollFont, draw_state2) == 0x1A0, "draw_state2 @ 0x1A0");
static_assert(offsetof(ccUiScrollFont, field_1D0) == 0x1D0, "field_1D0 @ 0x1D0");
static_assert(offsetof(ccUiScrollFont, ruby_enable) == 0x1D4, "ruby_enable @ 0x1D4");

#endif /* CMN15_S2_H */