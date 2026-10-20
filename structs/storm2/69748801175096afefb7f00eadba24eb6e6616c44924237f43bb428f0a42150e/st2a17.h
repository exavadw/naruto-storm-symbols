/* st2a17.h — Storm 2 (s2) adventure UI struct layouts */
/* AUTO-GENERATED from decompiled pseudocode. All sizes INFERRED unless noted. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ccUiAdvLetterCheck — 9 methods, size 0x1660 */
/* vtable: 0x14084ea00 */
typedef struct {
    void* vtable; /* 0x0, 8 bytes */
    uint8_t _pad_0008[52]; /* padding to 0x3C */
    uint64_t init_sentinel; /* 0x3C, 8 bytes */
    uint8_t _pad_0044[4]; /* padding to 0x48 */
    uint8_t embedded_checkBox[5640]; /* 0x48, 5640 bytes */
    void* text_xfbin; /* 0x1650, 8 bytes */
    void* keyhelp_ptr; /* 0x1658, 8 bytes */
} __attribute__((packed)) ccUiAdvLetterCheck;

/* ccUiAdvLetterCheckBox — 18 methods, size unknown (>= 0x1600 (max field 0x15F0+8)) */
typedef struct {
    uint8_t _pad_0000[84]; /* padding to 0x54 */
    uint32_t field_0x54; /* 0x54, 4 bytes */
    uint8_t _pad_0058[8]; /* padding to 0x60 */
    uint32_t field_0x60; /* 0x60, 4 bytes */
    uint8_t _pad_0064[5264]; /* padding to 0x14F4 */
    uint32_t disp_item_count; /* 0x14F4, 4 bytes */
    uint8_t _pad_14F8[24]; /* padding to 0x1510 */
    void* disp_item_buf; /* 0x1510, 8 bytes */
    uint8_t _pad_1518[216]; /* padding to 0x15F0 */
    void* parent_ptr; /* 0x15F0, 8 bytes */
} __attribute__((packed)) ccUiAdvLetterCheckBox;

/* ccUiAdvLetterCheckDetail — 15 methods, size unknown (>= 0x1538 (max field 0x1530+8)) */
typedef struct {
    uint8_t _pad_0000[5328]; /* padding to 0x14D0 */
    void* bg_font; /* 0x14D0, 8 bytes */
    uint8_t _pad_14D8[8]; /* padding to 0x14E0 */
    void* bin_font_0; /* 0x14E0, 8 bytes */
    void* bin_font_1; /* 0x14E8, 8 bytes */
    void* bin00_font; /* 0x14F0, 8 bytes */
    void* ruby_font; /* 0x14F8, 8 bytes */
    uint8_t _pad_1500[24]; /* padding to 0x1518 */
    void* select_window; /* 0x1518, 8 bytes */
    void* msg_dialog; /* 0x1520, 8 bytes */
    void* init_param_2; /* 0x1528, 8 bytes */
    void* init_param_3; /* 0x1530, 8 bytes */
} __attribute__((packed)) ccUiAdvLetterCheckDetail;

/* ccUiAdvLetterCheckItemDisp — 6 methods, size unknown (>= 0x368 (max field 0x360+8)) */
typedef struct {
    uint8_t _pad_0000[8]; /* padding to 0x8 */
    void* font_ptr; /* 0x8, 8 bytes */
    void* parent_ptr; /* 0x10, 8 bytes */
    uint8_t item_array[840]; /* 0x18, 840 bytes */
    void* font_object; /* 0x360, 8 bytes */
} __attribute__((packed)) ccUiAdvLetterCheckItemDisp;

/* ccUiAdvLifeRecoveryCutIn — 15 methods, size unknown (>= 0x178 (max field 0x174+4)) */
typedef struct {
    uint8_t _pad_0000[56]; /* padding to 0x38 */
    void* anim_ptr; /* 0x38, 8 bytes */
    uint8_t _pad_0040[288]; /* padding to 0x160 */
    void* msg_dialog; /* 0x160, 8 bytes */
    uint8_t _pad_0168[4]; /* padding to 0x16C */
    uint32_t flag_0x16c; /* 0x16C, 4 bytes */
    int32_t state; /* 0x170, 4 bytes */
    int32_t timer; /* 0x174, 4 bytes */
} __attribute__((packed)) ccUiAdvLifeRecoveryCutIn;

/* ccUiAdvMissionHelp — 15 methods, size unknown (>= 0x880 (max field 0x878+8)) */
typedef struct {
    uint8_t _pad_0000[88]; /* padding to 0x58 */
    void* open_close_ctrl; /* 0x58, 8 bytes */
    uint8_t _pad_0060[2072]; /* padding to 0x878 */
    void* ui_obj_list; /* 0x878, 8 bytes */
} __attribute__((packed)) ccUiAdvMissionHelp;

/* ccUiAdvMissionIndex — 5 methods, size unknown (>= 0xF0 (max field 0xe8+8)) */
typedef struct {
    uint8_t _pad_0000[56]; /* padding to 0x38 */
    void* obj_vec_begin; /* 0x38, 8 bytes */
    void* obj_vec_end; /* 0x40, 8 bytes */
    uint8_t _pad_0048[32]; /* padding to 0x68 */
    void* anim_0; /* 0x68, 8 bytes */
    void* anim_1; /* 0x70, 8 bytes */
    float lerp_value; /* 0x78, 4 bytes */
    uint8_t _pad_007C[4]; /* padding to 0x80 */
    void* index_items_begin; /* 0x80, 8 bytes */
    void* index_items_end; /* 0x88, 8 bytes */
    uint8_t _pad_0090[32]; /* padding to 0xB0 */
    void* cursor_anim; /* 0xB0, 8 bytes */
    void* cursor_clump; /* 0xB8, 8 bytes */
    void* cursor_font; /* 0xC0, 8 bytes */
    uint8_t _pad_00C8[8]; /* padding to 0xD0 */
    int32_t scroll_pos; /* 0xD0, 4 bytes */
    int32_t scroll_offset; /* 0xD4, 4 bytes */
    int32_t visible_count; /* 0xD8, 4 bytes */
    int32_t total_count; /* 0xDC, 4 bytes */
    void* speaker_array; /* 0xE0, 8 bytes */
    void* position_data; /* 0xE8, 8 bytes */
} __attribute__((packed)) ccUiAdvMissionIndex;

/* ccUiAdvPauseMenuCard — 4 methods, size unknown (>= 0x70 (7 ptrs at +0x38..+0x68)) */
typedef struct {
    uint8_t _pad_0000[56]; /* padding to 0x38 */
    void* card_party; /* 0x38, 8 bytes */
    void* card_itemlist; /* 0x40, 8 bytes */
    void* card_quest; /* 0x48, 8 bytes */
    void* card_help; /* 0x50, 8 bytes */
    void* card_4; /* 0x58, 8 bytes */
    void* card_5; /* 0x60, 8 bytes */
    void* card_6; /* 0x68, 8 bytes */
} __attribute__((packed)) ccUiAdvPauseMenuCard;

/* ccUiAdvPauseMenuFrame — 28 methods, size unknown (>= 0x118 (max field 0x114+4)) */
typedef struct {
    uint8_t _pad_0000[56]; /* padding to 0x38 */
    void* sound_0; /* 0x38, 8 bytes */
    uint8_t _pad_0040[8]; /* padding to 0x48 */
    void* scene_anim; /* 0x48, 8 bytes */
    uint8_t _pad_0050[8]; /* padding to 0x58 */
    void* sound_conditional; /* 0x58, 8 bytes */
    void* sound_1; /* 0x60, 8 bytes */
    void* sound_2; /* 0x68, 8 bytes */
    void* sound_3; /* 0x70, 8 bytes */
    uint8_t _pad_0078[88]; /* padding to 0xD0 */
    void* alpha_font; /* 0xD0, 8 bytes */
    uint8_t _pad_00D8[8]; /* padding to 0xE0 */
    void* menu_data_ptr; /* 0xE0, 8 bytes */
    uint8_t _pad_00E8[40]; /* padding to 0x110 */
    uint32_t menu_index; /* 0x110, 4 bytes */
    uint32_t scene_state; /* 0x114, 4 bytes */
} __attribute__((packed)) ccUiAdvPauseMenuFrame;

/* ccUiAdvResultSuccess — 5 methods, size unknown (>= 0x70 (max field 0x68+8)) */
typedef struct {
    uint8_t _pad_0000[56]; /* padding to 0x38 */
    uint32_t active_nrt_idx; /* 0x38, 4 bytes */
    uint8_t _pad_003C[12]; /* padding to 0x48 */
    void* back_font; /* 0x48, 8 bytes */
    void* obj_font; /* 0x50, 8 bytes */
    void* nrt_anm_0; /* 0x58, 8 bytes */
    void* nrt_anm_1; /* 0x60, 8 bytes */
    void* nrt_anm_2; /* 0x68, 8 bytes */
} __attribute__((packed)) ccUiAdvResultSuccess;

/* ccUiAdvResultSuccess_NrtAnm — 3 methods, size unknown (>= 0xD0 (ccUiObject base + ctor fields)) */
/* vtable: 0x14084fdb0 */
typedef struct {
    void* vtable; /* 0x0, 8 bytes */
    uint8_t _pad_0008[16]; /* padding to 0x18 */
    void* dtor_ptr; /* 0x18, 8 bytes */
    uint8_t field_0x20; /* 0x20, 1 bytes */
    void* field_0x21; /* 0x21, 8 bytes */
} __attribute__((packed)) ccUiAdvResultSuccess_NrtAnm;

/* ccUiAdvStageName — 4 methods, size unknown (>= 0x890 (max field 0x878+24 vector)) */
typedef struct {
    uint8_t _pad_0000[56]; /* padding to 0x38 */
    uint32_t field_0x38; /* 0x38, 4 bytes */
    uint32_t field_0x3c; /* 0x3C, 4 bytes */
    int32_t stage_type; /* 0x40, 4 bytes */
    uint8_t _pad_0044[4]; /* padding to 0x48 */
    void* name_array_size; /* 0x48, 8 bytes */
    void* name_array; /* 0x50, 8 bytes */
    void* field_0x58; /* 0x58, 8 bytes */
    void* selected_name; /* 0x60, 8 bytes */
    uint8_t _pad_0068[2008]; /* padding to 0x840 */
    uint32_t pos_flag_0; /* 0x840, 4 bytes */
    uint32_t pos_flag_1; /* 0x844, 4 bytes */
    double pos_y; /* 0x848, 8 bytes */
    double pos_zero; /* 0x850, 8 bytes */
    uint8_t _pad_0858[8]; /* padding to 0x860 */
    void* stageline_anim; /* 0x860, 8 bytes */
    void* satageline_anim; /* 0x868, 8 bytes */
    void* font_ns2; /* 0x870, 8 bytes */
    uint8_t obj_vector[24]; /* 0x878, 24 bytes */
} __attribute__((packed)) ccUiAdvStageName;

/* ccUiAdvSummary — 14 methods, size unknown (>= 0x70 (max field 0x68+8)) */
typedef struct {
    uint8_t _pad_0000[40]; /* padding to 0x28 */
    void* obj_0x28; /* 0x28, 8 bytes */
    void* title_font; /* 0x30, 8 bytes */
    float alpha; /* 0x38, 4 bytes */
    uint8_t _pad_003C[36]; /* padding to 0x60 */
    void* check_bar_begin; /* 0x60, 8 bytes */
    void* check_bar_end; /* 0x68, 8 bytes */
} __attribute__((packed)) ccUiAdvSummary;

#pragma pack(pop)

/* Offset verification — compile-time checks for every field */
/* offsetof */
static_assert(offsetof(ccUiAdvLetterCheck, vtable) == 0x0, "ccUiAdvLetterCheck.vtable offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheck, init_sentinel) == 0x3C, "ccUiAdvLetterCheck.init_sentinel offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheck, embedded_checkBox) == 0x48, "ccUiAdvLetterCheck.embedded_checkBox offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheck, text_xfbin) == 0x1650, "ccUiAdvLetterCheck.text_xfbin offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheck, keyhelp_ptr) == 0x1658, "ccUiAdvLetterCheck.keyhelp_ptr offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckBox, field_0x54) == 0x54, "ccUiAdvLetterCheckBox.field_0x54 offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckBox, field_0x60) == 0x60, "ccUiAdvLetterCheckBox.field_0x60 offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckBox, disp_item_count) == 0x14F4, "ccUiAdvLetterCheckBox.disp_item_count offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckBox, disp_item_buf) == 0x1510, "ccUiAdvLetterCheckBox.disp_item_buf offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckBox, parent_ptr) == 0x15F0, "ccUiAdvLetterCheckBox.parent_ptr offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, bg_font) == 0x14D0, "ccUiAdvLetterCheckDetail.bg_font offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, bin_font_0) == 0x14E0, "ccUiAdvLetterCheckDetail.bin_font_0 offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, bin_font_1) == 0x14E8, "ccUiAdvLetterCheckDetail.bin_font_1 offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, bin00_font) == 0x14F0, "ccUiAdvLetterCheckDetail.bin00_font offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, ruby_font) == 0x14F8, "ccUiAdvLetterCheckDetail.ruby_font offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, select_window) == 0x1518, "ccUiAdvLetterCheckDetail.select_window offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, msg_dialog) == 0x1520, "ccUiAdvLetterCheckDetail.msg_dialog offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, init_param_2) == 0x1528, "ccUiAdvLetterCheckDetail.init_param_2 offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckDetail, init_param_3) == 0x1530, "ccUiAdvLetterCheckDetail.init_param_3 offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckItemDisp, font_ptr) == 0x8, "ccUiAdvLetterCheckItemDisp.font_ptr offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckItemDisp, parent_ptr) == 0x10, "ccUiAdvLetterCheckItemDisp.parent_ptr offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckItemDisp, item_array) == 0x18, "ccUiAdvLetterCheckItemDisp.item_array offset mismatch");
static_assert(offsetof(ccUiAdvLetterCheckItemDisp, font_object) == 0x360, "ccUiAdvLetterCheckItemDisp.font_object offset mismatch");
static_assert(offsetof(ccUiAdvLifeRecoveryCutIn, anim_ptr) == 0x38, "ccUiAdvLifeRecoveryCutIn.anim_ptr offset mismatch");
static_assert(offsetof(ccUiAdvLifeRecoveryCutIn, msg_dialog) == 0x160, "ccUiAdvLifeRecoveryCutIn.msg_dialog offset mismatch");
static_assert(offsetof(ccUiAdvLifeRecoveryCutIn, flag_0x16c) == 0x16C, "ccUiAdvLifeRecoveryCutIn.flag_0x16c offset mismatch");
static_assert(offsetof(ccUiAdvLifeRecoveryCutIn, state) == 0x170, "ccUiAdvLifeRecoveryCutIn.state offset mismatch");
static_assert(offsetof(ccUiAdvLifeRecoveryCutIn, timer) == 0x174, "ccUiAdvLifeRecoveryCutIn.timer offset mismatch");
static_assert(offsetof(ccUiAdvMissionHelp, open_close_ctrl) == 0x58, "ccUiAdvMissionHelp.open_close_ctrl offset mismatch");
static_assert(offsetof(ccUiAdvMissionHelp, ui_obj_list) == 0x878, "ccUiAdvMissionHelp.ui_obj_list offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, obj_vec_begin) == 0x38, "ccUiAdvMissionIndex.obj_vec_begin offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, obj_vec_end) == 0x40, "ccUiAdvMissionIndex.obj_vec_end offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, anim_0) == 0x68, "ccUiAdvMissionIndex.anim_0 offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, anim_1) == 0x70, "ccUiAdvMissionIndex.anim_1 offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, lerp_value) == 0x78, "ccUiAdvMissionIndex.lerp_value offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, index_items_begin) == 0x80, "ccUiAdvMissionIndex.index_items_begin offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, index_items_end) == 0x88, "ccUiAdvMissionIndex.index_items_end offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, cursor_anim) == 0xB0, "ccUiAdvMissionIndex.cursor_anim offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, cursor_clump) == 0xB8, "ccUiAdvMissionIndex.cursor_clump offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, cursor_font) == 0xC0, "ccUiAdvMissionIndex.cursor_font offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, scroll_pos) == 0xD0, "ccUiAdvMissionIndex.scroll_pos offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, scroll_offset) == 0xD4, "ccUiAdvMissionIndex.scroll_offset offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, visible_count) == 0xD8, "ccUiAdvMissionIndex.visible_count offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, total_count) == 0xDC, "ccUiAdvMissionIndex.total_count offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, speaker_array) == 0xE0, "ccUiAdvMissionIndex.speaker_array offset mismatch");
static_assert(offsetof(ccUiAdvMissionIndex, position_data) == 0xE8, "ccUiAdvMissionIndex.position_data offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_party) == 0x38, "ccUiAdvPauseMenuCard.card_party offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_itemlist) == 0x40, "ccUiAdvPauseMenuCard.card_itemlist offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_quest) == 0x48, "ccUiAdvPauseMenuCard.card_quest offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_help) == 0x50, "ccUiAdvPauseMenuCard.card_help offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_4) == 0x58, "ccUiAdvPauseMenuCard.card_4 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_5) == 0x60, "ccUiAdvPauseMenuCard.card_5 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuCard, card_6) == 0x68, "ccUiAdvPauseMenuCard.card_6 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, sound_0) == 0x38, "ccUiAdvPauseMenuFrame.sound_0 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, scene_anim) == 0x48, "ccUiAdvPauseMenuFrame.scene_anim offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, sound_conditional) == 0x58, "ccUiAdvPauseMenuFrame.sound_conditional offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, sound_1) == 0x60, "ccUiAdvPauseMenuFrame.sound_1 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, sound_2) == 0x68, "ccUiAdvPauseMenuFrame.sound_2 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, sound_3) == 0x70, "ccUiAdvPauseMenuFrame.sound_3 offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, alpha_font) == 0xD0, "ccUiAdvPauseMenuFrame.alpha_font offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, menu_data_ptr) == 0xE0, "ccUiAdvPauseMenuFrame.menu_data_ptr offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, menu_index) == 0x110, "ccUiAdvPauseMenuFrame.menu_index offset mismatch");
static_assert(offsetof(ccUiAdvPauseMenuFrame, scene_state) == 0x114, "ccUiAdvPauseMenuFrame.scene_state offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess, active_nrt_idx) == 0x38, "ccUiAdvResultSuccess.active_nrt_idx offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess, back_font) == 0x48, "ccUiAdvResultSuccess.back_font offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess, obj_font) == 0x50, "ccUiAdvResultSuccess.obj_font offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess, nrt_anm_0) == 0x58, "ccUiAdvResultSuccess.nrt_anm_0 offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess, nrt_anm_1) == 0x60, "ccUiAdvResultSuccess.nrt_anm_1 offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess, nrt_anm_2) == 0x68, "ccUiAdvResultSuccess.nrt_anm_2 offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess_NrtAnm, vtable) == 0x0, "ccUiAdvResultSuccess_NrtAnm.vtable offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess_NrtAnm, dtor_ptr) == 0x18, "ccUiAdvResultSuccess_NrtAnm.dtor_ptr offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess_NrtAnm, field_0x20) == 0x20, "ccUiAdvResultSuccess_NrtAnm.field_0x20 offset mismatch");
static_assert(offsetof(ccUiAdvResultSuccess_NrtAnm, field_0x21) == 0x21, "ccUiAdvResultSuccess_NrtAnm.field_0x21 offset mismatch");
static_assert(offsetof(ccUiAdvStageName, field_0x38) == 0x38, "ccUiAdvStageName.field_0x38 offset mismatch");
static_assert(offsetof(ccUiAdvStageName, field_0x3c) == 0x3C, "ccUiAdvStageName.field_0x3c offset mismatch");
static_assert(offsetof(ccUiAdvStageName, stage_type) == 0x40, "ccUiAdvStageName.stage_type offset mismatch");
static_assert(offsetof(ccUiAdvStageName, name_array_size) == 0x48, "ccUiAdvStageName.name_array_size offset mismatch");
static_assert(offsetof(ccUiAdvStageName, name_array) == 0x50, "ccUiAdvStageName.name_array offset mismatch");
static_assert(offsetof(ccUiAdvStageName, field_0x58) == 0x58, "ccUiAdvStageName.field_0x58 offset mismatch");
static_assert(offsetof(ccUiAdvStageName, selected_name) == 0x60, "ccUiAdvStageName.selected_name offset mismatch");
static_assert(offsetof(ccUiAdvStageName, pos_flag_0) == 0x840, "ccUiAdvStageName.pos_flag_0 offset mismatch");
static_assert(offsetof(ccUiAdvStageName, pos_flag_1) == 0x844, "ccUiAdvStageName.pos_flag_1 offset mismatch");
static_assert(offsetof(ccUiAdvStageName, pos_y) == 0x848, "ccUiAdvStageName.pos_y offset mismatch");
static_assert(offsetof(ccUiAdvStageName, pos_zero) == 0x850, "ccUiAdvStageName.pos_zero offset mismatch");
static_assert(offsetof(ccUiAdvStageName, stageline_anim) == 0x860, "ccUiAdvStageName.stageline_anim offset mismatch");
static_assert(offsetof(ccUiAdvStageName, satageline_anim) == 0x868, "ccUiAdvStageName.satageline_anim offset mismatch");
static_assert(offsetof(ccUiAdvStageName, font_ns2) == 0x870, "ccUiAdvStageName.font_ns2 offset mismatch");
static_assert(offsetof(ccUiAdvStageName, obj_vector) == 0x878, "ccUiAdvStageName.obj_vector offset mismatch");
static_assert(offsetof(ccUiAdvSummary, obj_0x28) == 0x28, "ccUiAdvSummary.obj_0x28 offset mismatch");
static_assert(offsetof(ccUiAdvSummary, title_font) == 0x30, "ccUiAdvSummary.title_font offset mismatch");
static_assert(offsetof(ccUiAdvSummary, alpha) == 0x38, "ccUiAdvSummary.alpha offset mismatch");
static_assert(offsetof(ccUiAdvSummary, check_bar_begin) == 0x60, "ccUiAdvSummary.check_bar_begin offset mismatch");
static_assert(offsetof(ccUiAdvSummary, check_bar_end) == 0x68, "ccUiAdvSummary.check_bar_end offset mismatch");

