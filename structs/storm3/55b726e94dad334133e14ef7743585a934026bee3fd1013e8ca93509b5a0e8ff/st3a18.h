/* st3a18.h — Storm 3 (NSUNS3.exe x64, build s3) adventure/UI struct layouts
 * Generated 2026-10-19 from decompiled ctors/Initialize/methods.
 * All layouts INFERRED from static analysis; not runtime-confirmed.
 * Sizes proven only where allocator/ctor evidence exists; otherwise ">= last field".
 * Own-game names only (Storm 3 symbols/strings). PC offsets only (image base 0x140000000).
 */
#ifndef ST3A18_H
#define ST3A18_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- forward declarations for embedded types whose size is unproven ---- */
typedef void* ccUiAdvVtablePtr;

/* ======================================================================
 * ccUiAdvBattleConditionWindow
 * Evidence: Initialize@0x1F5498 writes +0xb0 (ptr deref), +0x100, +0x1f4(=500), +0x2d4
 *           ctor not found directly; Initialize is the effective init.
 * Size: unknown, >= 0x2D8
 * Vtable: not resolved (no vtable write in Initialize)
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvBattleConditionWindow {
    uint8_t _base[0xB0];              /* 0x000 - base class / vtable region */
    int64_t window_obj_ptr;           /* 0x0B0 - ptr dereferenced in Initialize (*(param_1+0xB0)+200) */
    uint8_t _pad_B8[0x48];            /* 0x0B8 */
    int32_t field_0x100;              /* 0x100 - set to 1 in Initialize */
    uint8_t _pad_104[0xF0];           /* 0x104 */
    int32_t condition_count;          /* 0x1F4 (=500) - FUN_1404e1f9c result */
    uint8_t _pad_1F8[0xDC];           /* 0x1F8 */
    int32_t stamp_flag;               /* 0x2D4 - set to 0 when param_2 != 0 */
    uint8_t _pad_2D8[0x8];            /* 0x2D8 - padding to alignment */
} ccUiAdvBattleConditionWindow;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvBattleConditionWindow, window_obj_ptr) == 0x0B0, "ccUiAdvBattleConditionWindow.window_obj_ptr");
static_assert(offsetof(ccUiAdvBattleConditionWindow, field_0x100) == 0x100, "ccUiAdvBattleConditionWindow.field_0x100");
static_assert(offsetof(ccUiAdvBattleConditionWindow, condition_count) == 0x1F4, "ccUiAdvBattleConditionWindow.condition_count");
static_assert(offsetof(ccUiAdvBattleConditionWindow, stamp_flag) == 0x2D4, "ccUiAdvBattleConditionWindow.stamp_flag");

/* ======================================================================
 * ccUiAdvBattleGardenSelect
 * Evidence: ctor@0x2327CC sets vtable=PTR_FUN_1408beee8, fields at indices 7-0x12
 *           Draw caller@0x1BD09C stores sprite ptr at +0x128
 * Size: unknown, >= 0x130
 * Vtable: 0x1408beee8 (PTR_FUN_1408beee8)
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvBattleGardenSelect {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408beee8 */
    uint8_t _pad_008[0x30];           /* 0x008 */
    int64_t field_0x38;               /* 0x038 - index 7, set to 0 in ctor */
    int64_t field_0x40;               /* 0x040 - index 8 */
    int64_t field_0x48;               /* 0x048 - index 9 */
    int32_t field_0x50;               /* 0x050 - index 10 (int) */
    uint8_t _pad_054[0x1C];           /* 0x054 */
    int32_t field_0x70;               /* 0x070 - index 0xe */
    int32_t field_0x74;               /* 0x074 */
    int32_t field_0x78;               /* 0x078 - index 0xf, set to -1 */
    uint8_t _pad_07C[0x4];            /* 0x07C */
    int64_t field_0x80;               /* 0x080 - index 0x10 */
    int64_t field_0x88;               /* 0x088 - index 0x11 */
    int32_t asset_hash;               /* 0x090 - index 0x12, FUN_140684d80("ADV_CRSEL_BATTLEGARDEN") */
    uint8_t _pad_094[0x94];           /* 0x094 */
    int64_t sprite_ptr;               /* 0x128 - set by Draw caller */
    uint8_t _pad_130[0x8];            /* 0x130 */
} ccUiAdvBattleGardenSelect;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvBattleGardenSelect, vtable) == 0x000, "ccUiAdvBattleGardenSelect.vtable");
static_assert(offsetof(ccUiAdvBattleGardenSelect, field_0x38) == 0x038, "ccUiAdvBattleGardenSelect.field_0x38");
static_assert(offsetof(ccUiAdvBattleGardenSelect, asset_hash) == 0x090, "ccUiAdvBattleGardenSelect.asset_hash");
static_assert(offsetof(ccUiAdvBattleGardenSelect, sprite_ptr) == 0x128, "ccUiAdvBattleGardenSelect.sprite_ptr");

/* ======================================================================
 * ccUiAdvBattleMap
 * Evidence: ctor@0x1F6420 sets vtable=PTR_FUN_1408b3df8, memset(+0x10..+0x160, 0, 0x150)
 *           CreateUi@0x1BDB5C stores sub-objects at +0x128, +0x138, +0x140
 *           ctor sets fields at indices 7, 0x3a-0x44
 * Size: unknown, >= 0x228 (last ctor write at +0x224 as int32)
 * Vtable: 0x1408b3df8
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvBattleMap {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408b3df8 */
    uint8_t _pad_008[0x30];           /* 0x008 */
    int64_t field_0x38;               /* 0x038 - index 7, set to 0 */
    uint8_t embedded_0x40[0x190];     /* 0x040 - embedded obj initialized by FUN_140767700 + FUN_140684bc0 */
    int32_t field_0x1D0;              /* 0x1D0 - index 0x3a, set to -1 */
    int32_t field_0x1D4;              /* 0x1D4 - set to -1 */
    int64_t field_0x1D8;              /* 0x1D8 - index 0x3b */
    int64_t field_0x1E0;              /* 0x1E0 - index 0x3c */
    int64_t field_0x1E8;              /* 0x1E8 - index 0x3d */
    int64_t field_0x1F0;              /* 0x1F0 - index 0x3e */
    int64_t field_0x1F8;              /* 0x1F8 - index 0x3f */
    int64_t field_0x200;              /* 0x200 - index 0x40, vtable PTR_FUN_1409ec308 */
    int32_t field_0x208;              /* 0x208 - part of index 0x40 area */
    uint8_t _pad_20C[0x10];           /* 0x20C */
    int32_t field_0x21C;              /* 0x21C - set to 0 */
    uint8_t _pad_220[0x4];            /* 0x220 */
    int32_t field_0x224;              /* 0x224 - set to 0 */
    int32_t field_0x228;              /* 0x228 - index 0x43, set to 2 */
    int32_t field_0x22C;              /* 0x22C - index 0x44, set to -2 */
    uint8_t _pad_230[0x8];            /* 0x230 */
    int64_t ui_main_ptr;              /* 0x238 - stored by CreateUi at +0x128 offset from scene */
    int64_t keyhelp_ptr;              /* 0x240 - stored at +0x138 */
    int64_t scrollhelp_ptr;           /* 0x248 - stored at +0x140 */
    uint8_t _pad_250[0x8];            /* 0x250 */
} ccUiAdvBattleMap;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvBattleMap, vtable) == 0x000, "ccUiAdvBattleMap.vtable");
static_assert(offsetof(ccUiAdvBattleMap, field_0x38) == 0x038, "ccUiAdvBattleMap.field_0x38");
static_assert(offsetof(ccUiAdvBattleMap, field_0x1D4) == 0x1D4, "ccUiAdvBattleMap.field_0x1D4");
static_assert(offsetof(ccUiAdvBattleMap, field_0x21C) == 0x21C, "ccUiAdvBattleMap.field_0x21C");
static_assert(offsetof(ccUiAdvBattleMap, field_0x228) == 0x228, "ccUiAdvBattleMap.field_0x228");

/* ======================================================================
 * ccUiAdvBtlMemberSelect
 * Evidence: ctor@0x1F7B5C sets vtable=PTR_FUN_1408b3ea0
 *           EnterSelectMenu@0x1BF718 stores sprite at +0x70
 *           ctor loops over 2 entries at +0x98..+0xC8 (3 dwords each)
 *           ctor loops 4x over +0x58..+0x68 and +0x7C..+0x88
 * Size: unknown, >= 0x98
 * Vtable: 0x1408b3ea0
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvBtlMemberSelect {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408b3ea0 */
    uint8_t _pad_008[0x30];           /* 0x008 */
    int64_t field_0x38;               /* 0x038 - index 7 */
    int64_t field_0x40;               /* 0x040 - index 8 */
    int64_t field_0x48;               /* 0x048 - index 9 */
    int32_t field_0x50;               /* 0x050 - index 10 */
    uint8_t _pad_054[0x4];            /* 0x054 */
    int32_t member_ids[4];            /* 0x058 - loop: 4x int32 at +0x58,+0x5C,+0x60,+0x64 */
    int32_t member_slots[4];          /* 0x068 - loop: 4x int32 at +0x68,+0x6C,+0x70,+0x74 (set -1) */
    int32_t field_0x78;               /* 0x078 - index 0xf */
    uint8_t _pad_07C[0x4];            /* 0x07C */
    int64_t sprite_ptr;               /* 0x080 - stored by EnterSelectMenu at +0x70 from state */
    int32_t field_0x88;               /* 0x088 - index 0x11 area */
    int32_t asset_hash;               /* 0x08C - index 0x1c, FUN_140684d80("ADV_CRSEL") */
    uint8_t _pad_090[0x8];            /* 0x090 */
    int64_t select_entries[2][3];     /* 0x098 - 2 entries x 3 qwords (loop in ctor) */
    uint8_t _pad_0C8[0x8];            /* 0x0C8 */
} ccUiAdvBtlMemberSelect;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvBtlMemberSelect, vtable) == 0x000, "ccUiAdvBtlMemberSelect.vtable");
static_assert(offsetof(ccUiAdvBtlMemberSelect, member_ids) == 0x058, "ccUiAdvBtlMemberSelect.member_ids");
static_assert(offsetof(ccUiAdvBtlMemberSelect, asset_hash) == 0x08C, "ccUiAdvBtlMemberSelect.asset_hash");
static_assert(offsetof(ccUiAdvBtlMemberSelect, select_entries) == 0x098, "ccUiAdvBtlMemberSelect.select_entries");

/* ======================================================================
 * ccUiAdvCmnCharPlate
 * Evidence: ctor@0x1F94B0 sets vtable=PTR_FUN_1409daf00, stores param_2 at index 1 (+0x8)
 *           SelPlate wrapper@0x1F7A18 stores parent ptr at index 0, count at +0x10
 * Size: unknown, >= 0x18
 * Vtable: 0x1409daf00
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvCmnCharPlate {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1409daf00 */
    int64_t parent_or_data_ptr;       /* 0x008 - index 1, set from param_2 in ctor */
    int64_t sub_object_ptr;           /* 0x010 - set by FUN_1401f9530 */
    uint8_t _pad_018[0x8];            /* 0x018 */
} ccUiAdvCmnCharPlate;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvCmnCharPlate, vtable) == 0x000, "ccUiAdvCmnCharPlate.vtable");
static_assert(offsetof(ccUiAdvCmnCharPlate, parent_or_data_ptr) == 0x008, "ccUiAdvCmnCharPlate.parent_or_data_ptr");
static_assert(offsetof(ccUiAdvCmnCharPlate, sub_object_ptr) == 0x010, "ccUiAdvCmnCharPlate.sub_object_ptr");

/* ======================================================================
 * ccUiAdvCmnFrogStone
 * Evidence: ctor@0x1F9A2C sets vtable=PTR_FUN_1408b42e0, indices 7,8,9 = 0
 *           SetFrogStoneModel@0x20176C reads +0x78, +0x90, +0x120, +0x124
 * Size: unknown, >= 0x128
 * Vtable: 0x1408b42e0
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvCmnFrogStone {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408b42e0 */
    uint8_t _pad_008[0x30];           /* 0x008 */
    int64_t field_0x38;               /* 0x038 - index 7 */
    int64_t field_0x40;               /* 0x040 - index 8 */
    int64_t field_0x48;               /* 0x048 - index 9 */
    uint8_t _pad_050[0x28];           /* 0x050 */
    int64_t model_data_ptr;           /* 0x078 - read in SetFrogStoneModel */
    uint8_t _pad_080[0x10];           /* 0x080 */
    int64_t sprite_or_effect_ptr;     /* 0x090 - read/write in SetFrogStoneModel */
    uint8_t _pad_098[0x88];           /* 0x098 */
    int32_t stone_id;                 /* 0x120 - read in SetFrogStoneModel */
    int32_t stone_variant;            /* 0x124 - read in SetFrogStoneModel */
    uint8_t _pad_128[0x8];            /* 0x128 */
} ccUiAdvCmnFrogStone;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvCmnFrogStone, vtable) == 0x000, "ccUiAdvCmnFrogStone.vtable");
static_assert(offsetof(ccUiAdvCmnFrogStone, model_data_ptr) == 0x078, "ccUiAdvCmnFrogStone.model_data_ptr");
static_assert(offsetof(ccUiAdvCmnFrogStone, sprite_or_effect_ptr) == 0x090, "ccUiAdvCmnFrogStone.sprite_or_effect_ptr");
static_assert(offsetof(ccUiAdvCmnFrogStone, stone_id) == 0x120, "ccUiAdvCmnFrogStone.stone_id");
static_assert(offsetof(ccUiAdvCmnFrogStone, stone_variant) == 0x124, "ccUiAdvCmnFrogStone.stone_variant");

/* ======================================================================
 * ccUiAdvCmnHud
 * Evidence: ctor@0x1FFEF8 sets vtable=PTR_FUN_1408b5290, many string-hash fields
 *           CreateHud@0x1F358C stores ptr at +0x8, sets +0x20
 *           ctor writes indices 7, 0xf-0x16, 0x1d-0x1e, 0x1f-0x28, 0x26-0x28
 * Size: unknown, >= 0x140 (last ctor write at +0x13C)
 * Vtable: 0x1408b5290
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvCmnHud {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408b5290 */
    uint8_t _pad_008[0x30];           /* 0x008 */
    int64_t embedded_base;            /* 0x038 - index 7, FUN_14073d400 init */
    uint8_t _pad_040[0x30];           /* 0x040 */
    int32_t field_0x70;               /* 0x070 - index 0xe area */
    uint8_t _pad_074[0x4];            /* 0x074 */
    int64_t field_0x78;               /* 0x078 - index 0xf */
    int64_t field_0x80;               /* 0x080 - index 0x10 */
    int64_t field_0x88;               /* 0x088 - index 0x11 */
    int64_t field_0x90;               /* 0x090 - index 0x12 */
    int64_t field_0x98;               /* 0x098 - index 0x13 */
    int32_t field_0xA0;               /* 0x0A0 - index 0x14, set to -1 */
    int32_t field_0xA4;               /* 0x0A4 - set to 1 */
    int32_t field_0xA8;               /* 0x0A8 - index 0x15, set to 1 */
    int32_t field_0xAC;               /* 0x0AC - set to 1 */
    uint8_t embedded_0xB0[0x38];      /* 0x0B0 - index 0x16, FUN_140191324 init */
    int32_t field_0xE8;               /* 0x0E8 - index 0x1d */
    int32_t field_0xEC;               /* 0x0EC - index 0x1e area */
    int64_t field_0xF0;               /* 0x0F0 - index 0x1e */
    int32_t hash_mission_03;          /* 0x0F8 - index 0x1f */
    int32_t hash_adv_cmn_menu_in;     /* 0x0FC - index 0x20 (was 0x1f+4) */
    int32_t hash_money_text_00;       /* 0x100 */
    int32_t hash_mission_success;     /* 0x104 */
    int32_t hash_lunch;               /* 0x108 */
    int32_t hash_lunch_icon;          /* 0x10C */
    int32_t hash_lunch_text;          /* 0x110 */
    int32_t hash_mission_text;        /* 0x114 */
    int32_t hash_main_mission_in00;   /* 0x118 */
    int32_t hash_main_mission_in01;   /* 0x11C */
    int32_t hash_sub_mission_in00;    /* 0x120 */
    int32_t hash_kawazu_window;       /* 0x124 */
    int32_t hash_kawazu_icon;         /* 0x128 */
    int32_t hash_kawazu_text;         /* 0x12C */
    int32_t hash_kawazu_eff;          /* 0x130 */
    int32_t hash_money;               /* 0x134 - index 0x26 area */
    int32_t hash_money_text_00b;      /* 0x138 */
    int32_t hash_money_text_01;       /* 0x13C */
    uint8_t _pad_140[0x8];            /* 0x140 */
} ccUiAdvCmnHud;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvCmnHud, vtable) == 0x000, "ccUiAdvCmnHud.vtable");
static_assert(offsetof(ccUiAdvCmnHud, embedded_base) == 0x038, "ccUiAdvCmnHud.embedded_base");
static_assert(offsetof(ccUiAdvCmnHud, field_0xA4) == 0x0A4, "ccUiAdvCmnHud.field_0xA4");
static_assert(offsetof(ccUiAdvCmnHud, hash_mission_03) == 0x0F8, "ccUiAdvCmnHud.hash_mission_03");
static_assert(offsetof(ccUiAdvCmnHud, hash_kawazu_eff) == 0x130, "ccUiAdvCmnHud.hash_kawazu_eff");
static_assert(offsetof(ccUiAdvCmnHud, hash_money_text_01) == 0x13C, "ccUiAdvCmnHud.hash_money_text_01");

/* ======================================================================
 * ccUiAdvFacilityBar
 * Evidence: ctor@0x1F9DAC sets vtable=PTR_FUN_1408b4340, index 7=0, index 8=hash
 *           Draw@0x1F3A64 checks +0x30, +0x10, +0x34; stores sprite at +0x10
 * Size: unknown, >= 0x48
 * Vtable: 0x1408b4340
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvFacilityBar {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408b4340 */
    uint8_t _pad_008[0x8];            /* 0x008 */
    int64_t sprite_ptr;               /* 0x010 - stored by Draw */
    uint8_t _pad_018[0x18];           /* 0x018 */
    int32_t visibility_flag;          /* 0x030 - checked in Draw */
    int32_t field_0x34;               /* 0x034 - checked in Draw */
    uint8_t _pad_038[0x8];            /* 0x038 */
    int64_t field_0x40;               /* 0x040 - index 7 area */
    int32_t asset_hash;               /* 0x048 - index 8, FUN_140684d80("ADV_PLACE_BAR") */
    uint8_t _pad_04C[0x4];            /* 0x04C */
} ccUiAdvFacilityBar;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvFacilityBar, vtable) == 0x000, "ccUiAdvFacilityBar.vtable");
static_assert(offsetof(ccUiAdvFacilityBar, sprite_ptr) == 0x010, "ccUiAdvFacilityBar.sprite_ptr");
static_assert(offsetof(ccUiAdvFacilityBar, visibility_flag) == 0x030, "ccUiAdvFacilityBar.visibility_flag");
static_assert(offsetof(ccUiAdvFacilityBar, asset_hash) == 0x048, "ccUiAdvFacilityBar.asset_hash");

/* ======================================================================
 * ccUiAdvFellowList
 * Evidence: Initialize@0x2036B0 writes +0x250, +0x258, +0x38, +0x120..+0x24C (many hashes)
 *           Calls FUN_140205610(param_1+0x38, param_1) — embedded state machine at +0x38
 * Size: unknown, >= 0x260
 * Vtable: not resolved (no vtable write in Initialize)
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvFellowList {
    uint8_t _base[0x38];              /* 0x000 - base / vtable region */
    uint8_t embedded_state_machine[0xE8]; /* 0x038 - FUN_140205610 target, ends before +0x120 */
    int32_t hash_array_start[24];     /* 0x120 - loop fills 24 hashes from string table */
    uint8_t _pad_180[0x70];           /* 0x180 - gap between hash array and named hash fields */
    int32_t hash_let01_lay;           /* 0x1F0 */
    uint8_t _pad_1F4[0x4];            /* 0x1F4 */
    int32_t hash_let01_play;          /* 0x1F8 */
    int32_t hash_let01_bg;            /* 0x1FC */
    int32_t hash_adv_support_gauge;   /* 0x200 */
    int32_t hash_let01_p00;           /* 0x204 */
    int32_t hash_let_ctxt;            /* 0x208 */
    int32_t hash_let_icon00;          /* 0x20C */
    int32_t hash_let_icon01;          /* 0x210 */
    int32_t hash_let_icon02;          /* 0x214 */
    int32_t hash_adv_menu_mdsel_friend; /* 0x218 */
    int32_t hash_adv_support_gauge2;  /* 0x21C */
    int32_t hash_life_frame_bar;      /* 0x220 */
    int32_t hash_life_dark_bar;       /* 0x224 */
    int32_t hash_life_bar02;          /* 0x228 */
    int32_t hash_support_panel1;      /* 0x22C */
    int32_t hash_support1_panel_frame;/* 0x230 */
    int32_t hash_support1_panel_bg;   /* 0x234 */
    int32_t hash_support1_panel_face; /* 0x238 */
    int32_t hash_let_cur;             /* 0x23C */
    int32_t hash_lettre_win00;        /* 0x240 */
    int32_t hash_lettre_sato_txt;     /* 0x244 */
    int32_t hash_lettre_sato_icon00;  /* 0x248 */
    int32_t hash_lettre_sato_icon01;  /* 0x24C */
    int64_t field_0x250;              /* 0x250 - set to 0x12 */
    int64_t field_0x258;              /* 0x258 - set to 0 */
    uint8_t _pad_260[0x8];            /* 0x260 */
} ccUiAdvFellowList;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvFellowList, embedded_state_machine) == 0x038, "ccUiAdvFellowList.embedded_state_machine");
static_assert(offsetof(ccUiAdvFellowList, hash_array_start) == 0x120, "ccUiAdvFellowList.hash_array_start");
static_assert(offsetof(ccUiAdvFellowList, hash_let01_lay) == 0x1F0, "ccUiAdvFellowList.hash_let01_lay");
static_assert(offsetof(ccUiAdvFellowList, field_0x250) == 0x250, "ccUiAdvFellowList.field_0x250");

/* ======================================================================
 * ccUiAdvFellowListStateMachine
 * Evidence: EnterIn@0x20537C reads +0x70 (ptr to FellowList)
 *           Other Enter methods likely access same field.
 * Size: unknown, >= 0x78
 * Vtable: not resolved
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvFellowListStateMachine {
    uint8_t _base[0x70];              /* 0x000 - base / vtable region */
    int64_t fellow_list_ptr;          /* 0x070 - ptr to owning ccUiAdvFellowList */
    uint8_t _pad_078[0x8];            /* 0x078 */
} ccUiAdvFellowListStateMachine;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvFellowListStateMachine, fellow_list_ptr) == 0x070, "ccUiAdvFellowListStateMachine.fellow_list_ptr");

/* ======================================================================
 * ccUiAdvFriendshipWnd
 * Evidence: ctor@0x1F9F78 sets vtable=PTR_FUN_1408b43e0, indices 7-10=0, 0xb=0
 *           Caller@0x1F2CE8 stores sprite at +0x80, reads +0x70, +0x78
 *           ctor sets +0x5C = hash("ADV_HEART_UP"), +0x60 = hash("ADV_HEART_UP_EFF")
 * Size: unknown, >= 0x88
 * Vtable: 0x1408b43e0
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvFriendshipWnd {
    ccUiAdvVtablePtr vtable;          /* 0x000 - PTR_FUN_1408b43e0 */
    uint8_t _pad_008[0x30];           /* 0x008 */
    int64_t field_0x38;               /* 0x038 - index 7 */
    int64_t field_0x40;               /* 0x040 - index 8 */
    int64_t field_0x48;               /* 0x048 - index 9 */
    int64_t field_0x50;               /* 0x050 - index 10 */
    int32_t field_0x58;               /* 0x058 - index 0xb */
    int32_t hash_heart_up;            /* 0x05C - FUN_140684d80("ADV_HEART_UP") */
    int32_t hash_heart_up_eff;        /* 0x060 - index 0xc */
    uint8_t _pad_064[0xC];            /* 0x064 */
    int32_t field_0x70;               /* 0x070 - read by caller */
    uint8_t _pad_074[0x4];            /* 0x074 */
    int32_t field_0x78;               /* 0x078 - read by caller */
    uint8_t _pad_07C[0x4];            /* 0x07C */
    int64_t sprite_ptr;               /* 0x080 - stored by caller */
    uint8_t _pad_088[0x8];            /* 0x088 */
} ccUiAdvFriendshipWnd;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvFriendshipWnd, vtable) == 0x000, "ccUiAdvFriendshipWnd.vtable");
static_assert(offsetof(ccUiAdvFriendshipWnd, hash_heart_up) == 0x05C, "ccUiAdvFriendshipWnd.hash_heart_up");
static_assert(offsetof(ccUiAdvFriendshipWnd, sprite_ptr) == 0x080, "ccUiAdvFriendshipWnd.sprite_ptr");

/* ======================================================================
 * ccUiAdvLetterBox
 * Evidence: Initialize@0x2061E4 writes +0x1c4, +0x1c8, +0x1cc, +0x1c0, +0x38,
 *           +0x158..+0x1A8 (many hashes), +0xd8, +0xb0, +0xb8, +0xc0, +0xe8..+0x144 (hash loop)
 * Size: unknown, >= 0x1D0
 * Vtable: not resolved
 * ====================================================================== */
#pragma pack(push, 1)
typedef struct ccUiAdvLetterBox {
    uint8_t _base[0x38];              /* 0x000 - base / vtable region */
    uint8_t embedded_state_machine[0xA0]; /* 0x038 - FUN_140205610 target */
    int64_t xfbin_loader_ptr;         /* 0x0D8 - allocated via FUN_140779b00 */
    int64_t hash_array_region[5];     /* 0x0E8 - loop fills 5-int groups from string table */
    uint8_t _pad_108[0x8];            /* 0x108 - gap after hash_array_region */
    int64_t letter_renderer_ptr;      /* 0x110 - allocated via FUN_140767c10, loads letter00.xfbin */
    int64_t text_layout_ptr;          /* 0x118 - allocated via FUN_140774e70 */
    int64_t field_0x120;              /* 0x120 - checked for null before FUN_140205a5c */
    uint8_t _pad_128[0x30];           /* 0x128 */
    int32_t hash_let02_lay;           /* 0x158 */
    int32_t hash_let02_play;          /* 0x15C */
    int32_t hash_let02_cur;           /* 0x160 */
    int32_t hash_let_soto_win00;      /* 0x164 */
    int32_t hash_lettre_win00;        /* 0x168 */
    int32_t hash_lettre_sato_icon00;  /* 0x16C */
    int32_t hash_lettre_sato_icon01;  /* 0x170 */
    int32_t hash_let_text_noting;     /* 0x174 */
    int32_t hash_let02_plate00;       /* 0x178 */
    int32_t hash_let01_icon_name00;   /* 0x17C */
    int32_t hash_adv_support_gauge;   /* 0x180 */
    int32_t hash_let01_p00;           /* 0x184 */
    int32_t hash_let_ctxt;            /* 0x188 */
    int32_t hash_let_icon00;          /* 0x18C */
    int32_t hash_let_icon01;          /* 0x190 */
    int32_t hash_let_icon02;          /* 0x194 */
    int32_t hash_support1_panel_face; /* 0x198 */
    int32_t hash_adv_support_gauge2;  /* 0x19C */
    int32_t hash_life_frame_bar;      /* 0x1A0 */
    int32_t hash_life_dark_bar;       /* 0x1A4 */
    int32_t hash_let_cur;             /* 0x1A8 */
    uint8_t _pad_1AC[0x14];           /* 0x1AC */
    int32_t field_0x1C0;              /* 0x1C0 - set to 6 */
    int32_t field_0x1C4;              /* 0x1C4 - set to 0 */
    int32_t field_0x1C8;              /* 0x1C8 - set to 0 */
    int32_t field_0x1CC;              /* 0x1CC - set to 0 */
    uint8_t _pad_1D0[0x8];            /* 0x1D0 */
} ccUiAdvLetterBox;
#pragma pack(pop)
static_assert(offsetof(ccUiAdvLetterBox, embedded_state_machine) == 0x038, "ccUiAdvLetterBox.embedded_state_machine");
static_assert(offsetof(ccUiAdvLetterBox, xfbin_loader_ptr) == 0x0D8, "ccUiAdvLetterBox.xfbin_loader_ptr");
static_assert(offsetof(ccUiAdvLetterBox, letter_renderer_ptr) == 0x110, "ccUiAdvLetterBox.letter_renderer_ptr");
static_assert(offsetof(ccUiAdvLetterBox, hash_let02_lay) == 0x158, "ccUiAdvLetterBox.hash_let02_lay");
static_assert(offsetof(ccUiAdvLetterBox, field_0x1C0) == 0x1C0, "ccUiAdvLetterBox.field_0x1C0");

/* ======================================================================
 * PLACEHOLDER STRUCTS — classes with < 3 methods or insufficient evidence
 * These are listed in TASK.md but lack enough decompiled methods for layout.
 * ====================================================================== */

/* ccUiAdvItemPalettePlate — no methods found in s3 symbol table with >= 3 entries */
/* ccUiAdvItemPaletteWindow — no methods found in s3 symbol table with >= 3 entries */

#endif /* ST3A18_H */