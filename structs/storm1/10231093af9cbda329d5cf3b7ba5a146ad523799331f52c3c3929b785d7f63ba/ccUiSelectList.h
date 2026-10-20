/* ccUiSelectList — NARUTO STORM 1 (NSUNS1.exe, build s1)
 * Reconstructed layout. ALL fields are INFERRED from static analysis.
 * Object size: 0x1B0 (432 bytes), from ccFileLoadListForUi::LoadTh(0x1b0,...).
 * Hierarchy: ccUiSelectList -> ccUiSelect -> Nucc::Memory::BlockAllocator
 * Vtable: PTR_FUN_1407486b0 (ccUiSelectList), PTR_FUN_140748578 (ccUiSelect)
 */
#ifndef CC_UI_SELECT_LIST_S1_H
#define CC_UI_SELECT_LIST_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Placeholder for MSVC x64 std::deque<T>: 0x40 bytes. */
typedef struct { uint8_t data[0x40]; } std_deque_placeholder;

typedef struct ccUiSelectList {
    /* === Nucc::Memory::BlockAllocator base (0x00-0x0F) === */
    void *vtable;               /* 0x00 */
    void *allocator_ptr;        /* 0x08 */

    /* === ccUiSelect fields (0x10-0x4F) === */
    uint8_t pad_10[0x08];      /* 0x10 */
    int32_t help_text_id;       /* 0x18 - SetSelect -> SetHelpText */
    int32_t visible_count;      /* 0x1C - Ctrl/DrawList bounds check */
    int32_t select_offset;      /* 0x20 - DrawList: *(0x18)-*(0x20) */
    uint8_t pad_24[0x08];      /* 0x24 */
    int32_t active_flag;        /* 0x2C - Ctrl checks !=0 */
    uint8_t pad_30[0x08];      /* 0x30 */
    void *unk_38;               /* 0x38 - ccUiSelect ctor global ptr */
    int32_t unk_40;             /* 0x40 - ccUiSelect ctor: set to 0 */
    uint8_t pad_44[0x0C];      /* 0x44 */

    /* === ccUiSelectList own fields (0x50-0x1AF) === */
    void *font;                 /* 0x50 - SetColor/DrawList: ccUiFont ops */
    void *unk_58;               /* 0x58 - Finalize: vtable delete */
    void *unk_60;               /* 0x60 - Finalize: vtable delete */
    void *scroll_font;          /* 0x68 - Clear: ccUiScrollFont::SetText */
    int32_t enabled;            /* 0x70 - ctor: set to 1; Ctrl checks */
    int32_t has_sub_object;     /* 0x74 - Finalize/Ctrl guard */
    uint8_t pad_78[0x08];      /* 0x78 */
    float line_spacing;         /* 0x80 - DrawList; factory=12.0f */
    int32_t draw_mode;          /* 0x84 - DrawList: 0=vert, 1=pos-list */
    uint32_t color_flags;       /* 0x88 - DrawList bits 2,3 */
    int32_t sentinel_8c;        /* 0x8C - ctor/Clear: 0xFFFFFFFE */
    int32_t cancel_button;      /* 0x90 - ctor: ccPad_GetInputButtonCancel */
    uint8_t pad_94[0x14];      /* 0x94 - Clear zeroes 0x94..0xA7 (8+4+8 bytes) */
    float blink_timer;          /* 0xA8 - DrawList: 500ms blink cycle */
    uint8_t pad_ac[0x04];      /* 0xAC */
    void *unk_b0;               /* 0xB0 - Finalize: vtable delete */
    void *unk_b8;               /* 0xB8 - ctor: set to 0 */
    int32_t scroll_pos;         /* 0xC0 - Clear: reset to 0 */
    uint8_t pad_c4[0x04];      /* 0xC4 */

    /* Embedded std::deque #1 (0xC8) */
    std_deque_placeholder deque_items;       /* 0xC8 */
    /* Embedded std::deque #2 (0x108) — Nucc::Vector2 positions */
    std_deque_placeholder deque_positions;   /* 0x108 */
    /* Embedded std::deque #3 (0x148) — SelectDataImpl */
    std_deque_placeholder deque_select_data; /* 0x148 */

    /* nummModelManager (0x188) */
    uint8_t numm_model_mgr[0x10];           /* 0x188 */

    /* BlockAllocator tail (0x198) */
    void *block_allocator_vtable;           /* 0x198 */
    uint8_t pad_1a0[0x10];                  /* 0x1A0 */
} ccUiSelectList;

/* Size verification */
static_assert(sizeof(ccUiSelectList) == 0x1B0, "size must be 0x1B0");

/* Base class offsets */
static_assert(offsetof(ccUiSelectList, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(ccUiSelectList, allocator_ptr) == 0x08, "allocator_ptr @ 0x08");

/* ccUiSelect fields */
static_assert(offsetof(ccUiSelectList, help_text_id) == 0x18, "help_text_id @ 0x18");
static_assert(offsetof(ccUiSelectList, visible_count) == 0x1C, "visible_count @ 0x1C");
static_assert(offsetof(ccUiSelectList, select_offset) == 0x20, "select_offset @ 0x20");
static_assert(offsetof(ccUiSelectList, active_flag) == 0x2C, "active_flag @ 0x2C");
static_assert(offsetof(ccUiSelectList, unk_38) == 0x38, "unk_38 @ 0x38");
static_assert(offsetof(ccUiSelectList, unk_40) == 0x40, "unk_40 @ 0x40");

/* ccUiSelectList own fields */
static_assert(offsetof(ccUiSelectList, font) == 0x50, "font @ 0x50");
static_assert(offsetof(ccUiSelectList, unk_58) == 0x58, "unk_58 @ 0x58");
static_assert(offsetof(ccUiSelectList, unk_60) == 0x60, "unk_60 @ 0x60");
static_assert(offsetof(ccUiSelectList, scroll_font) == 0x68, "scroll_font @ 0x68");
static_assert(offsetof(ccUiSelectList, enabled) == 0x70, "enabled @ 0x70");
static_assert(offsetof(ccUiSelectList, has_sub_object) == 0x74, "has_sub_object @ 0x74");
static_assert(offsetof(ccUiSelectList, line_spacing) == 0x80, "line_spacing @ 0x80");
static_assert(offsetof(ccUiSelectList, draw_mode) == 0x84, "draw_mode @ 0x84");
static_assert(offsetof(ccUiSelectList, color_flags) == 0x88, "color_flags @ 0x88");
static_assert(offsetof(ccUiSelectList, sentinel_8c) == 0x8C, "sentinel_8c @ 0x8C");
static_assert(offsetof(ccUiSelectList, cancel_button) == 0x90, "cancel_button @ 0x90");
static_assert(offsetof(ccUiSelectList, blink_timer) == 0xA8, "blink_timer @ 0xA8");
static_assert(offsetof(ccUiSelectList, unk_b0) == 0xB0, "unk_b0 @ 0xB0");
static_assert(offsetof(ccUiSelectList, unk_b8) == 0xB8, "unk_b8 @ 0xB8");
static_assert(offsetof(ccUiSelectList, scroll_pos) == 0xC0, "scroll_pos @ 0xC0");
static_assert(offsetof(ccUiSelectList, deque_items) == 0xC8, "deque_items @ 0xC8");
static_assert(offsetof(ccUiSelectList, deque_positions) == 0x108, "deque_positions @ 0x108");
static_assert(offsetof(ccUiSelectList, deque_select_data) == 0x148, "deque_select_data @ 0x148");
static_assert(offsetof(ccUiSelectList, numm_model_mgr) == 0x188, "numm_model_mgr @ 0x188");
static_assert(offsetof(ccUiSelectList, block_allocator_vtable) == 0x198, "block_allocator_vtable @ 0x198");

#endif /* CC_UI_SELECT_LIST_S1_H */