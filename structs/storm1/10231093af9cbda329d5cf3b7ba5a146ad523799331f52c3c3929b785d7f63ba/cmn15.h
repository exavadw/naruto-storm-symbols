/* cmn15 s1: ccUiScrollBar, ccUiScrollFont struct layouts (INFERRED)
 * Build: s1 (NARUTO STORM 1 PC, NSUNS1.exe, image base 0x140000000)
 * All offsets from x64 PC decompilation. Sizes proven from allocator calls.
 * OWN-GAME NAMES only (s1 symbols/strings). Never CONFIRMED — all INFERRED.
 */
#ifndef CMN15_S1_H
#define CMN15_S1_H

#include <stdint.h>
#include <stddef.h>

/* ---- ccUiScrollBar ---------------------------------------------------- */
/* Size 0x120 proven from ccUiSelectList::CreateScrollBar (RVA 0x575680):
 *   FUN_14047ed10(0x120, ...) — operator new(0x120)
 * Vtable: PTR_FUN_140749690 (set in ctor RVA 0x587950)
 */
typedef struct __attribute__((packed)) ccUiScrollBar {
    /* 0x00 */ void *vtable;              /* PTR_FUN_140749690 */
    /* 0x08 */ uint8_t _pad_08[0x30];     /* base class data before sub-object */
    /* 0x38 */ void *bar_sprite;          /* xfbin bar asset ptr (Initialize 0x587B50) */
    /* 0x40 */ void *knob_sprite;         /* xfbin knob asset ptr */
    /* 0x48 */ void *arrow1_sprite;       /* xfbin arrow1 asset ptr */
    /* 0x50 */ void *arrow2_sprite;       /* xfbin arrow2 asset ptr */
    /* 0x58 */ uint8_t base_subobj[0x40]; /* ccUiObjectHelper base (ctor: FUN_14053e0b0 at +0xb qwords) */
    /* 0x98 */ void *field_98;            /* zeroed in ctor, deleted in Finalize */
    /* 0xA0 */ void *field_A0;            /* zeroed in ctor, deleted in Finalize; used in SetLength/SetScroll */
    /* 0xA8 */ void *field_A8;            /* zeroed in ctor */
    /* 0xB0 */ void *field_B0;            /* zeroed in ctor */
    /* 0xB8 */ void *field_B8;            /* zeroed in ctor */
    /* 0xC0 */ float visible_range;       /* SetScroll reads as max visible; Set writes here */
    /* 0xC4 */ float scroll_max;          /* 1.0f default; SetRange/SetScroll use as max */
    /* 0xC8 */ float scroll_min;          /* 1.0f default; SetRange/SetScroll use as min */
    /* 0xCC */ float scroll_pos;          /* current scroll position (SetScroll) */
    /* 0xD0 */ int64_t field_D0;          /* 1 in ctor */
    /* 0xD8 */ uint32_t field_D8;         /* zeroed in ctor */
    /* 0xDC */ uint8_t transform[0x44];   /* matrix/transform ops (SetMatrix/SetPos/Translate at +0xDC) */
} ccUiScrollBar;

_Static_assert(sizeof(ccUiScrollBar) == 0x120, "ccUiScrollBar size must be 0x120");
_Static_assert(offsetof(ccUiScrollBar, vtable) == 0x00, "vtable @ 0x00");
_Static_assert(offsetof(ccUiScrollBar, bar_sprite) == 0x38, "bar_sprite @ 0x38");
_Static_assert(offsetof(ccUiScrollBar, knob_sprite) == 0x40, "knob_sprite @ 0x40");
_Static_assert(offsetof(ccUiScrollBar, arrow1_sprite) == 0x48, "arrow1_sprite @ 0x48");
_Static_assert(offsetof(ccUiScrollBar, arrow2_sprite) == 0x50, "arrow2_sprite @ 0x50");
_Static_assert(offsetof(ccUiScrollBar, base_subobj) == 0x58, "base_subobj @ 0x58");
_Static_assert(offsetof(ccUiScrollBar, field_98) == 0x98, "field_98 @ 0x98");
_Static_assert(offsetof(ccUiScrollBar, field_A0) == 0xA0, "field_A0 @ 0xA0");
_Static_assert(offsetof(ccUiScrollBar, field_A8) == 0xA8, "field_A8 @ 0xA8");
_Static_assert(offsetof(ccUiScrollBar, field_B0) == 0xB0, "field_B0 @ 0xB0");
_Static_assert(offsetof(ccUiScrollBar, field_B8) == 0xB8, "field_B8 @ 0xB8");
_Static_assert(offsetof(ccUiScrollBar, visible_range) == 0xC0, "visible_range @ 0xC0");
_Static_assert(offsetof(ccUiScrollBar, scroll_max) == 0xC4, "scroll_max @ 0xC4");
_Static_assert(offsetof(ccUiScrollBar, scroll_min) == 0xC8, "scroll_min @ 0xC8");
_Static_assert(offsetof(ccUiScrollBar, scroll_pos) == 0xCC, "scroll_pos @ 0xCC");
_Static_assert(offsetof(ccUiScrollBar, field_D0) == 0xD0, "field_D0 @ 0xD0");
_Static_assert(offsetof(ccUiScrollBar, field_D8) == 0xD8, "field_D8 @ 0xD8");
_Static_assert(offsetof(ccUiScrollBar, transform) == 0xDC, "transform @ 0xDC");


/* ---- ccUiScrollFont --------------------------------------------------- */
/* Size 0x1D8 proven from ccUiSelectList::CreateScrollFont (RVA 0x575830):
 *   FUN_14047ed10(0x1d8, ...) — operator new(0x1d8)
 * Primary vtable: PTR_FUN_140749528 (ctor RVA 0x585810)
 * Secondary vtable at +0x38: PTR_LAB_140749558
 */
typedef struct __attribute__((packed)) ccUiScrollFont {
    /* 0x00 */ void *vtable;              /* PTR_FUN_140749528 */
    /* 0x08 */ uint8_t _pad_08[0x30];     /* base class / sub-init region (FUN_140588c50 at +7 qwords = 0x38) */
    /* 0x38 */ void *secondary_vtable;    /* PTR_LAB_140749558 set in ctor */
    /* 0x40 */ uint64_t field_40;         /* count or capacity (Ctrl checks != 0) */
    /* 0x48 */ void *field_48;            /* array ptr (Ctrl iterates with stride 0x28) */
    /* 0x50 */ void *field_50;            /* ptr checked for type==1 in Ctrl */
    /* 0x58 */ void *field_58;            /* ptr checked for type==3 in Ctrl; set in Initialize */
    /* 0x60 */ uint8_t _pad_60[0x18];     /* gap to base sub-object */
    /* 0x78 */ uint8_t base_subobj[0x40]; /* ccUiObjectHelper base (ctor: FUN_14053e0b0 at +0xf qwords) */
    /* 0xB8 */ void *font_object;         /* font resource ptr (GetFont returns this; SetText uses) */
    /* 0xC0 */ void *scroll_helper;       /* helper object (Initialize creates 0x148-sized obj) */
    /* 0xC8 */ uint32_t field_C8;         /* value 5 in ctor */
    /* 0xCC */ uint32_t _pad_CC;          /* alignment padding */
    /* 0xD0 */ uint8_t text_buffer[0x18]; /* std::string-like (SetText copies into +0xD0, heap ptr if >0x10) */
    /* 0xE8 */ uint64_t text_capacity;    /* SSO threshold check (< 0x10 = inline) */
    /* 0xF0 */ uint8_t _pad_F0[0x18];     /* gap */
    /* 0x108 */ uint32_t line_count;      /* SetText stores result of FUN_1404ada10 */
    /* 0x10C */ uint32_t field_10C;       /* zeroed by SetText; compared to draw_width in CtrlScroll */
    /* 0x110 */ uint8_t pos_data[0x08];   /* SetPos calls FUN_14047fdf0 on this */
    /* 0x118 */ uint32_t field_118;       /* passed to FUN_14047f8e0 in SetPos */
    /* 0x11C */ uint32_t _pad_11C;        /* alignment */
    /* 0x120 */ void *attach_dummy;       /* SetAttachDummy stores result here */
    /* 0x128 */ uint32_t attach_flag1;    /* param_6 in SetAttachDummy; checked in CtrlAttach */
    /* 0x12C */ uint32_t attach_flag2;    /* param_7 (offset 300 = 0x12C); checked in CtrlAttach */
    /* 0x130 */ uint32_t preset_field_130;/* SetPresetStatus from DAT_1408dd150 */
    /* 0x134 */ uint32_t preset_field_134;/* SetPresetStatus from DAT_1408dd154 */
    /* 0x138 */ float draw_width;         /* SetDrawWidth computes ABS diff; SetPresetStatus sets */
    /* 0x13C */ uint32_t char_index;      /* CtrlScroll increments; DrawScroll passes to render */
    /* 0x140 */ uint32_t preset_field_140;/* SetPresetStatus from DAT_1408dd160 */
    /* 0x144 */ float scroll_offset;      /* CtrlScroll modifies; DrawScroll reads */
    /* 0x148 */ uint32_t _pad_148;        /* alignment */
    /* 0x14C */ float scroll_speed;       /* CtrlScroll checks != 0.0 */
    /* 0x150 */ uint32_t preset_field_150;/* SetPresetStatus from DAT_1408dd158; CtrlScroll compares */
    /* 0x154 */ uint32_t timer_accum;     /* CtrlScroll accumulates delta ticks */
    /* 0x158 */ uint32_t field_158;       /* zeroed in ctor */
    /* 0x15C */ uint32_t scroll_enable;   /* 1 in ctor; CtrlScroll checks != 0 */
    /* 0x160 */ uint32_t calc_pending;    /* Initialize sets 1; Ctrl checks to call CalcScrollText */
    /* 0x164 */ uint32_t recalc_flag;     /* CalcScrollText clears; state_surface shows w4 */
    /* 0x168 */ uint32_t ctrl_active;     /* Ctrl checks != 0 before processing */
    /* 0x16C */ uint32_t _pad_16C;        /* alignment */
    /* 0x170 */ uint8_t draw_state[0x18]; /* DrawScroll writes render params here (passed to 0x587080/0x587290) */
    /* 0x188 */ uint8_t render_obj1[0x18];/* ctor: FUN_14047f1e0 at +0x31 qwords */
    /* 0x1A0 */ uint8_t _pad_1A0[0x18];   /* gap */
    /* 0x1B8 */ uint8_t render_obj2[0x18];/* ctor: FUN_14047f1e0 at +0x37 qwords */
    /* 0x1D0 */ uint32_t field_1D0;       /* 1 in ctor */
    /* 0x1D4 */ uint32_t ruby_enable;     /* 1 in ctor; SetRubyEnable writes; SetText checks */
} ccUiScrollFont;

_Static_assert(sizeof(ccUiScrollFont) == 0x1D8, "ccUiScrollFont size must be 0x1D8");
_Static_assert(offsetof(ccUiScrollFont, vtable) == 0x00, "vtable @ 0x00");
_Static_assert(offsetof(ccUiScrollFont, secondary_vtable) == 0x38, "secondary_vtable @ 0x38");
_Static_assert(offsetof(ccUiScrollFont, field_40) == 0x40, "field_40 @ 0x40");
_Static_assert(offsetof(ccUiScrollFont, field_48) == 0x48, "field_48 @ 0x48");
_Static_assert(offsetof(ccUiScrollFont, field_50) == 0x50, "field_50 @ 0x50");
_Static_assert(offsetof(ccUiScrollFont, field_58) == 0x58, "field_58 @ 0x58");
_Static_assert(offsetof(ccUiScrollFont, base_subobj) == 0x78, "base_subobj @ 0x78");
_Static_assert(offsetof(ccUiScrollFont, font_object) == 0xB8, "font_object @ 0xB8");
_Static_assert(offsetof(ccUiScrollFont, scroll_helper) == 0xC0, "scroll_helper @ 0xC0");
_Static_assert(offsetof(ccUiScrollFont, field_C8) == 0xC8, "field_C8 @ 0xC8");
_Static_assert(offsetof(ccUiScrollFont, text_buffer) == 0xD0, "text_buffer @ 0xD0");
_Static_assert(offsetof(ccUiScrollFont, text_capacity) == 0xE8, "text_capacity @ 0xE8");
_Static_assert(offsetof(ccUiScrollFont, line_count) == 0x108, "line_count @ 0x108");
_Static_assert(offsetof(ccUiScrollFont, field_10C) == 0x10C, "field_10C @ 0x10C");
_Static_assert(offsetof(ccUiScrollFont, pos_data) == 0x110, "pos_data @ 0x110");
_Static_assert(offsetof(ccUiScrollFont, field_118) == 0x118, "field_118 @ 0x118");
_Static_assert(offsetof(ccUiScrollFont, attach_dummy) == 0x120, "attach_dummy @ 0x120");
_Static_assert(offsetof(ccUiScrollFont, attach_flag1) == 0x128, "attach_flag1 @ 0x128");
_Static_assert(offsetof(ccUiScrollFont, attach_flag2) == 0x12C, "attach_flag2 @ 0x12C");
_Static_assert(offsetof(ccUiScrollFont, preset_field_130) == 0x130, "preset_field_130 @ 0x130");
_Static_assert(offsetof(ccUiScrollFont, preset_field_134) == 0x134, "preset_field_134 @ 0x134");
_Static_assert(offsetof(ccUiScrollFont, draw_width) == 0x138, "draw_width @ 0x138");
_Static_assert(offsetof(ccUiScrollFont, char_index) == 0x13C, "char_index @ 0x13C");
_Static_assert(offsetof(ccUiScrollFont, preset_field_140) == 0x140, "preset_field_140 @ 0x140");
_Static_assert(offsetof(ccUiScrollFont, scroll_offset) == 0x144, "scroll_offset @ 0x144");
_Static_assert(offsetof(ccUiScrollFont, scroll_speed) == 0x14C, "scroll_speed @ 0x14C");
_Static_assert(offsetof(ccUiScrollFont, preset_field_150) == 0x150, "preset_field_150 @ 0x150");
_Static_assert(offsetof(ccUiScrollFont, timer_accum) == 0x154, "timer_accum @ 0x154");
_Static_assert(offsetof(ccUiScrollFont, field_158) == 0x158, "field_158 @ 0x158");
_Static_assert(offsetof(ccUiScrollFont, scroll_enable) == 0x15C, "scroll_enable @ 0x15C");
_Static_assert(offsetof(ccUiScrollFont, calc_pending) == 0x160, "calc_pending @ 0x160");
_Static_assert(offsetof(ccUiScrollFont, recalc_flag) == 0x164, "recalc_flag @ 0x164");
_Static_assert(offsetof(ccUiScrollFont, ctrl_active) == 0x168, "ctrl_active @ 0x168");
_Static_assert(offsetof(ccUiScrollFont, draw_state) == 0x170, "draw_state @ 0x170");
_Static_assert(offsetof(ccUiScrollFont, render_obj1) == 0x188, "render_obj1 @ 0x188");
_Static_assert(offsetof(ccUiScrollFont, render_obj2) == 0x1B8, "render_obj2 @ 0x1B8");
_Static_assert(offsetof(ccUiScrollFont, field_1D0) == 0x1D0, "field_1D0 @ 0x1D0");
_Static_assert(offsetof(ccUiScrollFont, ruby_enable) == 0x1D4, "ruby_enable @ 0x1D4");

#endif /* CMN15_S1_H */