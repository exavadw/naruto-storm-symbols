/* cmn15 s3 — ccUiScrollBar, ccUiScrollFont (INFERRED)
 * Build: s3 (NARUTO STORM 3 Full Burst HD PC, NSUNS3.exe, image base 0x140000000)
 * Date: 2026-10-19
 * All results INFERRED from static decompilation. Nothing is CONFIRMED by runtime trace.
 */

#ifndef CMN15_S3_H
#define CMN15_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccUiScrollBar — size 0x120 (proven by ccUiSelectList::CreateScrollBar, RVA 0x75FD90,
 *   ccFileLoadListForUi::LoadTh(0x120,...))
 * Vtable: PTR_FUN_1409ee0e8 (from ctor RVA 0x774E70)
 * Base sub-object: ccUiObjectContainer at offset 0x58 (size 0x40)
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void *vtable;               /* PRES: PTR_FUN_1409ee0e8 */
    /* 0x08 */ uint8_t _pad_08[0x30];      /* UNKNOWN: inherited ccUiTaskBase fields */
    /* 0x38 */ void *bar_sprite;           /* PRES: xfbin bar clump (Initialize) */
    /* 0x40 */ void *knob_sprite;          /* PRES: xfbin knob clump (Initialize) */
    /* 0x48 */ void *arrow1_sprite;        /* PRES: xfbin arrow1 anim (GetArrowAnmTime) */
    /* 0x50 */ void *arrow2_sprite;        /* PRES: xfbin arrow2 anim (GetArrowAnmTime) */
    /* 0x58 */ uint8_t base_subobj[0x40];  /* PRES: ccUiObjectContainer (ctor calls param_1+0xb) */
    /* 0x98 */ void *split_parts_bar;      /* PRES: ccUiSplitParts* (Initialize, dtor checks) */
    /* 0xA0 */ void *split_parts_knob;     /* PRES: ccUiSplitParts* (SetLength/SetRange) */
    /* 0xA8 */ void *field_A8;             /* UNKNOWN: zeroed in ctor */
    /* 0xB0 */ void *field_B0;             /* UNKNOWN: zeroed in ctor */
    /* 0xB8 */ void *field_B8;             /* UNKNOWN: zeroed in ctor */
    /* 0xC0 */ float visible_range;        /* SIM: scroll visible range (SetScroll, SetRange) */
    /* 0xC4 */ float scroll_max;           /* SIM: max scroll value, default 1.0f (ctor, SetRange) */
    /* 0xC8 */ float scroll_min;           /* SIM: min scroll value, default 0.0f (ctor stores as longlong) */
    /* 0xCC */ float scroll_pos;           /* SIM: current scroll position (SetScroll, SetMatrix, Translate) */
    /* 0xD0 */ int32_t ctrl_enable;        /* PRES: gate for Ctrl processing, set 1 in ctor */
    /* 0xD4 */ int32_t arrow_anim_flag;    /* PRES: arrow animation active flag (Ctrl) */
    /* 0xD8 */ uint32_t arrow_timeline;    /* PRES: cached arrow timeline value (Ctrl) */
    /* 0xDC */ uint8_t transform[0x44];    /* PRES: Nucc::Matrix44_MathGeo (SetMatrix, SetPos, Translate) */
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
static_assert(offsetof(ccUiScrollBar, field_B0) == 0xB0, "field_B0 @ 0xB0");
static_assert(offsetof(ccUiScrollBar, field_B8) == 0xB8, "field_B8 @ 0xB8");
static_assert(offsetof(ccUiScrollBar, visible_range) == 0xC0, "visible_range @ 0xC0");
static_assert(offsetof(ccUiScrollBar, scroll_max) == 0xC4, "scroll_max @ 0xC4");
static_assert(offsetof(ccUiScrollBar, scroll_min) == 0xC8, "scroll_min @ 0xC8");
static_assert(offsetof(ccUiScrollBar, scroll_pos) == 0xCC, "scroll_pos @ 0xCC");
static_assert(offsetof(ccUiScrollBar, ctrl_enable) == 0xD0, "ctrl_enable @ 0xD0");
static_assert(offsetof(ccUiScrollBar, arrow_anim_flag) == 0xD4, "arrow_anim_flag @ 0xD4");
static_assert(offsetof(ccUiScrollBar, arrow_timeline) == 0xD8, "arrow_timeline @ 0xD8");
static_assert(offsetof(ccUiScrollBar, transform) == 0xDC, "transform @ 0xDC");

/* ccUiScrollFont — size 0x1D8 (proven by ccUiSelectList::CreateScrollFont, RVA 0x75FF40,
 *   ccFileLoadListForUi::LoadTh(0x1d8,...))
 * Primary vtable: PTR_FUN_1409ed650 (from ctor RVA 0x761F20)
 * Secondary vtable: PTR_LAB_1409ed680 at offset 0x38 (from ctor)
 * Base sub-objects: ccUiOpenCloseCtrl at 0x38 (via ccClassFnManager), ccUiObjectContainer at 0x78
 */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void *vtable;               /* PRES: PTR_FUN_1409ed650 */
    /* 0x08 */ uint8_t _pad_08[0x30];      /* UNKNOWN: inherited ccUiTaskBase fields */
    /* 0x38 */ void *secondary_vtable;     /* PRES: PTR_LAB_1409ed680 (ctor assigns param_1[7]) */
    /* 0x40 */ uint64_t child_count;       /* PRES: count for array iteration in Ctrl/Initialize */
    /* 0x48 */ void *child_array;          /* PRES: pointer to child objects array (stride 0x28) */
    /* 0x50 */ void *field_50;             /* PRES: type==1 check target in Ctrl */
    /* 0x58 */ void *field_58;             /* PRES: type==3 search result in Initialize */
    /* 0x60 */ uint8_t _pad_60[0x18];      /* UNKNOWN: gap to base sub-object */
    /* 0x78 */ uint8_t base_subobj[0x40];  /* PRES: ccUiObjectContainer (FUN_140767700 init in ctor) */
    /* 0xB8 */ void *font_object;          /* PRES: ccUiFont* (Initialize creates, GetFont uses) */
    /* 0xC0 */ void *scroll_helper;        /* PRES: helper clump (SetPresetStatus creates via LoadTh) */
    /* 0xC8 */ uint32_t field_C8;          /* UNKNOWN: value 5 in ctor */
    /* 0xCC */ uint32_t _pad_CC;           /* alignment padding */
    /* 0xD0 */ uint8_t text_buffer[0x38];  /* PRES: BlockAllocator area + std::string SSO buffer */
    /* 0x108 */ uint32_t line_count;       /* SIM: character count (SetText) */
    /* 0x10C */ uint32_t text_width;       /* SIM: pixel width (SetText, CtrlScroll comparison) */
    /* 0x110 */ float pos_x;              /* PRES: X position (Vector3 init, DrawScroll) */
    /* 0x114 */ float pos_y;              /* PRES: Y position (DrawScroll) */
    /* 0x118 */ float pos_z;              /* PRES: Z position (DrawScroll uses - 0.1) */
    /* 0x11C */ uint32_t _pad_11C;        /* alignment padding */
    /* 0x120 */ void *attach_dummy;       /* PRES: attached object ptr (SetAttachDummy, CtrlAttach) */
    /* 0x128 */ uint32_t attach_flag1;    /* PRES: param_6 flag (SetAttachDummy, CtrlAttach) */
    /* 0x12C */ uint32_t attach_flag2;    /* PRES: param_7 flag (SetAttachDummy, CtrlAttach) */
    /* 0x130 */ uint32_t preset_field_130;/* PRES: from preset table (SetPresetStatus) */
    /* 0x134 */ uint32_t preset_line_mult;/* PRES: line multiplier from preset table */
    /* 0x138 */ float draw_width;         /* SIM: computed draw width (SetDrawWidth, CalcScrollText) */
    /* 0x13C */ uint32_t char_index;      /* SIM: current character index in scroll (CtrlScroll) */
    /* 0x140 */ float preset_field_140;   /* PRES: margin/padding from preset table */
    /* 0x144 */ float scroll_offset;      /* SIM: current pixel offset for scroll rendering */
    /* 0x148 */ uint32_t _pad_148;        /* alignment padding */
    /* 0x14C */ float scroll_speed;       /* SIM: scroll animation speed (CtrlScroll checks != 0.0) */
    /* 0x150 */ uint32_t preset_field_150;/* PRES: timer threshold from preset table */
    /* 0x154 */ uint32_t timer_accum;     /* SIM: accumulated timer ticks (CtrlScroll increments) */
    /* 0x158 */ float pos_offset_x;       /* PRES: X offset applied in DrawScroll */
    /* 0x15C */ uint32_t scroll_enable;   /* SIM: scroll animation on/off (CalcScrollText sets) */
    /* 0x160 */ uint32_t calc_pending;    /* PRES: triggers CalcScrollText when set */
    /* 0x164 */ uint32_t recalc_flag;     /* PRES: cleared after CalcScrollText runs */
    /* 0x168 */ uint32_t ctrl_active;     /* PRES: gate for Ctrl processing */
    /* 0x16C */ uint32_t _pad_16C;        /* alignment padding */
    /* 0x170 */ uint8_t draw_state1[0x30];/* PRES: render params for first draw pass */
    /* 0x1A0 */ uint8_t draw_state2[0x30];/* PRES: render params for second draw pass */
    /* 0x1D0 */ uint32_t field_1D0;       /* UNKNOWN: value 1 in ctor */
    /* 0x1D4 */ uint32_t ruby_enable;     /* PRES: ruby/furigana toggle (SetRubyEnable) */
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

#endif /* CMN15_S3_H */