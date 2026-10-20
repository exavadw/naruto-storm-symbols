/* st2c04.h - Storm 2 (NSUNS2.exe) cutscene/event playback structs
 * Build: s2 (NSUNS2.exe-abf2b6, sha 697488011750)
 * Group: st2c04 - Story CUTSCENE / EVENT playback (tier 1)
 * All results are INFERRED from static analysis, not CONFIRMED.
 * Own-game names only (ns2:: namespace for s2).
 * PC offsets from x64 decompile (image base 0x140000000).
 */

#ifndef ST2C04_H
#define ST2C04_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Skipped classes (< 3 methods in this build):
 *   ccEventSpriteBaseCtrl (2 methods)
 *   ccEventSpritePosCtrl (2 methods)
 *   ccEventSpriteRotCtrl (2 methods)
 *   ccEventSpriteScaleCtrl (1 method)
 *   ccIaCaption (2 methods)
 */

/* ============================================================================
 * ccEventSpriteColorCtrl - Sprite color controller (embedded in ccEventSpriteState)
 * Vtable: PTR_FUN_1407f25f0 (RVA 0x7f25f0)
 * Size: 0x38 (from ctor field assignments: param_1[2..6], qword indices)
 * Evidence: ctor at 0x32fdf4 sets param_1[2]=0, [3]=0, [4]=0, [5]=0, *(param_1+6)=0
 * Rollback: PRES (visual state, not simulation)
 * ============================================================================ */
typedef struct __attribute__((packed)) ns2_ccEventSpriteColorCtrl {
    /* 0x00 */ void *vtable;                    /* PTR_FUN_1407f25f0 */
    /* 0x08 */ uint8_t _pad_0x08[0x08];         /* base class data from FUN_14032fdb0 */
    /* 0x10 */ uint64_t color_r;                /* param_1[2] = 0 */
    /* 0x18 */ uint64_t color_g;                /* param_1[3] = 0 */
    /* 0x20 */ uint64_t color_b;                /* param_1[4] = 0 */
    /* 0x28 */ uint64_t color_a;                /* param_1[5] = 0 */
    /* 0x30 */ uint32_t flags;                  /* *(param_1+6) = 0 */
    /* 0x34 */ uint8_t _pad_0x34[0x04];         /* padding to 0x38 */
} ns2_ccEventSpriteColorCtrl;

static_assert(offsetof(ns2_ccEventSpriteColorCtrl, vtable) == 0x00, "ccEventSpriteColorCtrl.vtable");
static_assert(offsetof(ns2_ccEventSpriteColorCtrl, color_r) == 0x10, "ccEventSpriteColorCtrl.color_r");
static_assert(offsetof(ns2_ccEventSpriteColorCtrl, color_g) == 0x18, "ccEventSpriteColorCtrl.color_g");
static_assert(offsetof(ns2_ccEventSpriteColorCtrl, color_b) == 0x20, "ccEventSpriteColorCtrl.color_b");
static_assert(offsetof(ns2_ccEventSpriteColorCtrl, color_a) == 0x28, "ccEventSpriteColorCtrl.color_a");
static_assert(offsetof(ns2_ccEventSpriteColorCtrl, flags) == 0x30, "ccEventSpriteColorCtrl.flags");
static_assert(sizeof(ns2_ccEventSpriteColorCtrl) == 0x38, "ccEventSpriteColorCtrl size");

/* ============================================================================
 * ccEventSpriteState - Sprite state for cutscene rendering
 * Vtable: PTR_FUN_1407f2660 (RVA 0x7f2660)
 * Size: unknown, >= 0x148 (last field at 0x140 + estimated sub-object)
 * Evidence: ctor at 0x330304, Create at 0x33049c accesses up to 0xb0
 * Embedded sub-objects at offsets: +0x50 (base), +0x58 (pos), +0x5c (rot),
 *   +0x70 (scale?), +0x88 (?), +0xa0 (?), +0xc8 (ccEventSpriteColorCtrl)
 * Rollback: PRES (visual state)
 * ============================================================================ */
typedef struct __attribute__((packed)) ns2_ccEventSpriteState {
    /* 0x00 */ void *vtable;                    /* PTR_FUN_1407f2660 */
    /* 0x08 */ uint8_t _pad_0x08[0x08];         /* reserved */
    /* 0x10 */ uint8_t base_obj[0x40];          /* FUN_1401a1160 base init at param_1+2 (0x10) */
    /* 0x50 */ uint32_t field_0x50;             /* *(param_1+9) = 0 */
    /* 0x54 */ uint8_t _pad_0x54[0x04];
    /* 0x58 */ uint8_t pos_ctrl[0x08];          /* FUN_1404832a0 at param_1+10 (0x58) */
    /* 0x60 */ uint8_t _pad_0x60[0x10];
    /* 0x70 */ uint64_t scale_val;              /* FUN_1405805f0 at param_1+0x16 (0x70), 0x3f800000 = 1.0f */
    /* 0x78 */ uint8_t rot_ctrl[0x28];          /* FUN_14032ff4c at param_1+0x17 (0x78) */
    /* 0xA0 */ uint8_t field_0xa0[0x28];        /* FUN_140330094 at param_1+0x1c (0xa0) */
    /* 0xC8 */ uint8_t field_0xc8[0x28];        /* FUN_140330208 at param_1+0x22 (0xc8) */
    /* 0xF0 */ ns2_ccEventSpriteColorCtrl color_ctrl; /* FUN_14032fdf4 at param_1+0x28 (0xf0) */
    /* 0x128 */ uint8_t _pad_0x128[0x20];       /* padding/unknown fields */
    /* 0x148 */ uint8_t _end_marker[0];         /* size unknown, >= 0x148 */
} ns2_ccEventSpriteState;

static_assert(offsetof(ns2_ccEventSpriteState, vtable) == 0x00, "ccEventSpriteState.vtable");
static_assert(offsetof(ns2_ccEventSpriteState, base_obj) == 0x10, "ccEventSpriteState.base_obj");
static_assert(offsetof(ns2_ccEventSpriteState, field_0x50) == 0x50, "ccEventSpriteState.field_0x50");
static_assert(offsetof(ns2_ccEventSpriteState, pos_ctrl) == 0x58, "ccEventSpriteState.pos_ctrl");
static_assert(offsetof(ns2_ccEventSpriteState, scale_val) == 0x70, "ccEventSpriteState.scale_val");
static_assert(offsetof(ns2_ccEventSpriteState, rot_ctrl) == 0x78, "ccEventSpriteState.rot_ctrl");
static_assert(offsetof(ns2_ccEventSpriteState, color_ctrl) == 0xF0, "ccEventSpriteState.color_ctrl");

/* ============================================================================
 * ccEventStageState - Stage/background state for cutscenes
 * Vtable: PTR_FUN_1407f27e0 (RVA 0x7f27e0)
 * Size: 0x1628 (from FUN_140580190(0x1628,...) in ccLoDemoStateMachine::Create)
 * Evidence: ctor at 0x3306b8, Create at 0x330768 accesses param_1+0x14b8
 * Rollback: PRES (visual state)
 * ============================================================================ */
typedef struct __attribute__((packed)) ns2_ccEventStageState {
    /* 0x0000 */ void *vtable;                  /* PTR_FUN_1407f27e0 */
    /* 0x0008 */ uint8_t base_data[0x14B0];     /* FUN_1402aa884 base init */
    /* 0x14B8 */ uint8_t stage_subobj[0x170];   /* FUN_14048764c at param_1+0x297 (0x14b8) */
    /* 0x1628 */ uint8_t _end_marker[0];        /* proven size 0x1628 */
} ns2_ccEventStageState;

static_assert(offsetof(ns2_ccEventStageState, vtable) == 0x0000, "ccEventStageState.vtable");
static_assert(offsetof(ns2_ccEventStageState, base_data) == 0x0008, "ccEventStageState.base_data");
static_assert(offsetof(ns2_ccEventStageState, stage_subobj) == 0x14B8, "ccEventStageState.stage_subobj");
static_assert(sizeof(ns2_ccEventStageState) == 0x1628, "ccEventStageState size");

/* ============================================================================
 * ccEventStringState - String/text display state for cutscenes
 * Vtable: PTR_FUN_1407f2860 (RVA 0x7f2860)
 * Size: unknown, >= 0x11C (last field at 0x114 + alignment)
 * Evidence: ctor at 0x330958, Create at 0x330c74
 * Font loaded: "data/ui/LANG_FONT/xfgame_cmn.fnt.xfbin"
 * SSO threshold: 0x100 (string buffer inline if < 256 bytes)
 * Rollback: PRES (UI text state)
 * ============================================================================ */
typedef struct __attribute__((packed)) ns2_ccEventStringState {
    /* 0x00 */ void *vtable;                    /* PTR_FUN_1407f2860 */
    /* 0x08 */ uint8_t _pad_0x08[0x08];
    /* 0x10 */ uint8_t base_str[0x38];          /* FUN_1401afc0c base at param_1+2 (0x10) */
    /* 0x48 */ uint32_t str_hash;               /* *(param_1+9) = 0, then set by Create */
    /* 0x4C */ uint8_t _pad_0x4c[0x04];
    /* 0x50 */ void *font_xfbin;                /* param_1[10] = font handle */
    /* 0x58 */ uint32_t field_0x58;             /* surface offset 0x58, size 4 */
    /* 0x5C */ uint8_t _pad_0x5c[0x04];
    /* 0x60 */ uint64_t field_0x60;             /* surface offset 0x60 */
    /* 0x68 */ uint8_t _pad_0x68[0x08];
    /* 0x70 */ uint64_t field_0x70;             /* surface offset 0x70 */
    /* 0x78 */ uint8_t _pad_0x78[0x08];
    /* 0x80 */ uint32_t field_0x80;             /* surface offset 0x80 */
    /* 0x84 */ uint32_t field_0x84;             /* surface offset 0x84, init 0xffffffff */
    /* 0x88 */ uint32_t field_0x88;             /* surface offset 0x88 */
    /* 0x8C */ uint8_t _pad_0x8c[0x04];
    /* 0x90 */ uint64_t field_0x90;             /* surface offset 0x90 */
    /* 0x98 */ uint64_t field_0x98;             /* surface offset 0x98 */
    /* 0xA0 */ uint64_t field_0xa0;             /* surface offset 0xa0 */
    /* 0xA8 */ uint64_t field_0xa8;             /* surface offset 0xa8 */
    /* 0xB0 */ uint64_t field_0xb0;             /* surface offset 0xb0 */
    /* 0xB8 */ uint64_t field_0xb8;             /* surface offset 0xb8 */
    /* 0xC0 */ uint64_t field_0xc0;             /* surface offset 0xc0 */
    /* 0xC8 */ uint32_t field_0xc8;             /* surface offset 0xc8 */
    /* 0xCC */ uint32_t field_0xcc;             /* surface offset 0xcc, init 0xffffffff */
    /* 0xD0 */ uint32_t field_0xd0;             /* surface offset 0xd0 */
    /* 0xD4 */ uint8_t subobj_0xd4[0x08];       /* FUN_140580630 at 0xd4 */
    /* 0xDC */ uint8_t subobj_0xdc[0x08];       /* FUN_140580630 at 0xdc */
    /* 0xE4 */ uint8_t subobj_0xe4[0x08];       /* FUN_140580630 at 0xe4 */
    /* 0xEC */ uint8_t _pad_0xec[0x04];
    /* 0xF0 */ uint64_t field_0xf0;             /* surface offset 0xf0 */
    /* 0xF8 */ uint32_t field_0xf8;             /* surface offset 0xf8 */
    /* 0xFC */ uint32_t field_0xfc;             /* surface offset 0xfc, init 0xffffffff */
    /* 0x100 */ uint32_t field_0x100;           /* surface offset 0x100 */
    /* 0x104 */ uint64_t scale_x;               /* surface offset 0x104, init 1.0f via FUN_1405805f0 */
    /* 0x10C */ uint64_t scale_y;               /* surface offset 0x10c, init 1.0f via FUN_1405805f0 */
    /* 0x114 */ uint8_t subobj_0x114[0x08];     /* FUN_140580630 at 0x114 */
    /* 0x11C */ uint8_t _end_marker[0];         /* size unknown, >= 0x11C */
} ns2_ccEventStringState;

static_assert(offsetof(ns2_ccEventStringState, vtable) == 0x00, "ccEventStringState.vtable");
static_assert(offsetof(ns2_ccEventStringState, base_str) == 0x10, "ccEventStringState.base_str");
static_assert(offsetof(ns2_ccEventStringState, str_hash) == 0x48, "ccEventStringState.str_hash");
static_assert(offsetof(ns2_ccEventStringState, font_xfbin) == 0x50, "ccEventStringState.font_xfbin");
static_assert(offsetof(ns2_ccEventStringState, field_0x58) == 0x58, "ccEventStringState.field_0x58");
static_assert(offsetof(ns2_ccEventStringState, field_0x84) == 0x84, "ccEventStringState.field_0x84");
static_assert(offsetof(ns2_ccEventStringState, subobj_0xd4) == 0xD4, "ccEventStringState.subobj_0xd4");
static_assert(offsetof(ns2_ccEventStringState, scale_x) == 0x104, "ccEventStringState.scale_x");
static_assert(offsetof(ns2_ccEventStringState, scale_y) == 0x10C, "ccEventStringState.scale_y");
static_assert(offsetof(ns2_ccEventStringState, subobj_0x114) == 0x114, "ccEventStringState.subobj_0x114");

/* ============================================================================
 * ccLoDemoEvent - Demo event handler (cutscene driver)
 * Vtable: unknown (no ctor found in cache)
 * Size: unknown
 * Methods: 6 in this build
 * Rollback: SIM (drives cutscene state machine)
 * ============================================================================ */
/* Struct layout not reconstructed: no ctor or state_surface fields found.
 * Marked as gap in report. */

/* ============================================================================
 * ccLoDemoEventLoadState - Demo event loading state
 * Vtable: unknown (no ctor found in cache)
 * Size: unknown
 * Methods: 5 in this build
 * Rollback: PRES (loading state, not simulation)
 * ============================================================================ */
/* Struct layout not reconstructed: no ctor or state_surface fields found.
 * Marked as gap in report. */

/* ============================================================================
 * ccLoDemoLipSync - Lip sync controller for cutscenes
 * Vtable: unknown (no ctor found in cache)
 * Size: unknown
 * Methods: 4 in this build
 * Evidence: Create at 0x348644 uses FUN_140594110/FUN_140591ca0 for chunk loading
 * Rollback: PRES (visual/audio sync state)
 * ============================================================================ */
/* Struct layout not reconstructed: no ctor or state_surface fields found.
 * Marked as gap in report. */

/* ============================================================================
 * ccLoDemoStateMachine - Main cutscene/demo state machine
 * Vtable: unknown (complex multi-state object)
 * Size: 0x16A0 (derived from max offset 0x169c + alignment in Create)
 * Evidence: Create at 0x3462a8 allocates sub-objects via FUN_140580190:
 *   0x1628 -> ccEventStageState at param_1+0x1620
 *   0x1570 -> ccLoDemoEvent at param_1+0x1630
 *   0x15b0 -> ? at param_1+0x1638
 *   0x15b0 -> ? at param_1+0x1640
 *   0x14f0 -> ? at param_1+0x1648
 *   0x14c8 -> ? at param_1+0x1650
 *   0x14e0 -> ? at param_1+0x1658
 *   0x14c8 -> ? at param_1+0x1660
 *   0x14d8 -> ? at param_1+0x1668
 *   0x14e0 -> ? at param_1+0x1670
 *   0x14f0 -> ? at param_1+0x1678
 *   0x1510 -> ? at param_1+0x1680
 *   0x10 -> ? at param_1+0x1688
 *   0x14700 -> large buffer at param_1+0x1690
 *   0x1578 -> ? at param_1+0x1510
 *   0x90 -> ? at param_1+0x1518
 * Rollback: SIM (state machine drives cutscene progression)
 * ============================================================================ */
typedef struct __attribute__((packed)) ns2_ccLoDemoStateMachine {
    /* 0x0000 */ uint8_t base_data[0x14B8];     /* base class data */
    /* 0x14B8 */ uint8_t field_0x14b8[0x18];    /* initialized in Create */
    /* 0x14D0 */ uint8_t flag_0x14d0;           /* surface offset 0x14d0, size 1 */
    /* 0x14D1 */ uint8_t _pad_0x14d1[0x0F];
    /* 0x14E0 */ uint64_t ptr_0x14e0;           /* surface offset 0x14e0 */
    /* 0x14E8 */ uint64_t ptr_0x14e8;           /* surface offset 0x14e8 */
    /* 0x14F0 */ uint64_t ptr_0x14f0;           /* surface offset 0x14f0 */
    /* 0x14F8 */ uint8_t _pad_0x14f8[0x18];
    /* 0x1510 */ void *subobj_0x1510;           /* allocated 0x1578 bytes, FUN_14052b190 */
    /* 0x1518 */ void *subobj_0x1518;           /* allocated 0x90 bytes, FUN_1404b6124 */
    /* 0x1520 */ void *draw_caption;            /* set by FUN_140420b04("DRAW CAPTION",...) */
    /* 0x1528 */ uint8_t _pad_0x1528[0x08];
    /* 0x1530 */ uint8_t chara_list[0x30];      /* surface offset 0x1530, FUN_14034841c */
    /* 0x1560 */ uint8_t field_0x1560[0x30];    /* surface offset 0x1560 */
    /* 0x1590 */ uint8_t field_0x1590[0x30];    /* surface offset 0x1590 */
    /* 0x15C0 */ uint8_t sprite_list[0x30];     /* surface offset 0x15c0, FUN_140348498 */
    /* 0x15F0 */ uint8_t string_list[0x18];     /* surface offset 0x15f0, FUN_140348514 */
    /* 0x1608 */ uint64_t ptr_0x1608;           /* surface offset 0x1608 */
    /* 0x1610 */ uint8_t _pad_0x1610[0x10];
    /* 0x1620 */ ns2_ccEventStageState *stage_state; /* allocated 0x1628 bytes */
    /* 0x1628 */ void *staffroll;               /* allocated 0x98 bytes, FUN_14051b874 */
    /* 0x1630 */ void *demo_event;              /* allocated 0x1570 bytes, ccLoDemoEvent */
    /* 0x1638 */ void *subobj_0x1638;           /* allocated 0x15b0 bytes */
    /* 0x1640 */ void *subobj_0x1640;           /* allocated 0x15b0 bytes */
    /* 0x1648 */ void *subobj_0x1648;           /* allocated 0x14f0 bytes */
    /* 0x1650 */ void *subobj_0x1650;           /* allocated 0x14c8 bytes */
    /* 0x1658 */ void *subobj_0x1658;           /* allocated 0x14e0 bytes */
    /* 0x1660 */ void *subobj_0x1660;           /* allocated 0x14c8 bytes */
    /* 0x1668 */ void *subobj_0x1668;           /* allocated 0x14d8 bytes */
    /* 0x1670 */ void *subobj_0x1670;           /* allocated 0x14e0 bytes */
    /* 0x1678 */ void *subobj_0x1678;           /* allocated 0x14f0 bytes */
    /* 0x1680 */ void *subobj_0x1680;           /* allocated 0x1510 bytes */
    /* 0x1688 */ void *subobj_0x1688;           /* allocated 0x10 bytes */
    /* 0x1690 */ void *large_buffer;            /* allocated 0x14700 bytes */
    /* 0x1698 */ uint8_t _pad_0x1698[0x04];     /* padding to reach 0x169c */
    /* 0x169C */ uint32_t field_0x169c;         /* checked in Create: *(int*)(param_1+0x169c) */
    /* 0x16A0 */ uint8_t _end_marker[0];        /* proven size 0x16A0 */
} ns2_ccLoDemoStateMachine;

static_assert(offsetof(ns2_ccLoDemoStateMachine, base_data) == 0x0000, "ccLoDemoStateMachine.base_data");
static_assert(offsetof(ns2_ccLoDemoStateMachine, flag_0x14d0) == 0x14D0, "ccLoDemoStateMachine.flag_0x14d0");
static_assert(offsetof(ns2_ccLoDemoStateMachine, ptr_0x14e0) == 0x14E0, "ccLoDemoStateMachine.ptr_0x14e0");
static_assert(offsetof(ns2_ccLoDemoStateMachine, subobj_0x1510) == 0x1510, "ccLoDemoStateMachine.subobj_0x1510");
static_assert(offsetof(ns2_ccLoDemoStateMachine, draw_caption) == 0x1520, "ccLoDemoStateMachine.draw_caption");
static_assert(offsetof(ns2_ccLoDemoStateMachine, chara_list) == 0x1530, "ccLoDemoStateMachine.chara_list");
static_assert(offsetof(ns2_ccLoDemoStateMachine, sprite_list) == 0x15C0, "ccLoDemoStateMachine.sprite_list");
static_assert(offsetof(ns2_ccLoDemoStateMachine, string_list) == 0x15F0, "ccLoDemoStateMachine.string_list");
static_assert(offsetof(ns2_ccLoDemoStateMachine, stage_state) == 0x1620, "ccLoDemoStateMachine.stage_state");
static_assert(offsetof(ns2_ccLoDemoStateMachine, demo_event) == 0x1630, "ccLoDemoStateMachine.demo_event");
static_assert(offsetof(ns2_ccLoDemoStateMachine, large_buffer) == 0x1690, "ccLoDemoStateMachine.large_buffer");
static_assert(offsetof(ns2_ccLoDemoStateMachine, field_0x169c) == 0x169C, "ccLoDemoStateMachine.field_0x169c");
static_assert(sizeof(ns2_ccLoDemoStateMachine) == 0x16A0, "ccLoDemoStateMachine size");

/* ============================================================================
 * ccMenuPuppetDemoSelect - Puppet demo selection menu
 * Vtable: PTR_FUN_14083ead8 (RVA 0x83ead8)
 * Size: unknown, >= 0x1F0 (last field at 0x1ec + alignment)
 * Evidence: ctor at 0x45c248
 * Rollback: PRES (menu/UI state)
 * ============================================================================ */
typedef struct __attribute__((packed)) ns2_ccMenuPuppetDemoSelect {
    /* 0x000 */ void *vtable;                   /* PTR_FUN_14083ead8 */
    /* 0x008 */ uint8_t base_data[0x120];       /* FUN_14066b200 base init */
    /* 0x128 */ uint64_t field_0x128;           /* param_1[0x25] = 0 */
    /* 0x130 */ uint64_t field_0x130;           /* param_1[0x26] = 0 */
    /* 0x138 */ uint8_t _pad_0x138[0x08];
    /* 0x140 */ uint64_t field_0x140;           /* param_1[0x28] = 0 */
    /* 0x148 */ uint64_t field_0x148;           /* param_1[0x29] = 0 */
    /* 0x150 */ uint64_t field_0x150;           /* param_1[0x2a] = 0 */
    /* 0x158 */ uint8_t subobj_0x158[0x28];     /* FUN_1405858f0 at param_1+0x2b (0x158) */
    /* 0x180 */ uint64_t field_0x180;           /* param_1[0x2e] = 0 */
    /* 0x188 */ uint64_t field_0x188;           /* param_1[0x2f] = 0 */
    /* 0x190 */ uint64_t field_0x190;           /* param_1[0x30] = 0 */
    /* 0x198 */ uint8_t subobj_0x198[0x14];     /* second FUN_1405858f0 at param_1+0x31 */
    /* 0x1AC */ uint8_t subobj_0x1ac[0x40];     /* FUN_140580a40 at param_1+0x1ac */
    /* 0x1EC */ uint32_t field_0x1ec;           /* *(param_1+0x3d) = 0, *(param_1+0x1ec) = 0 */
    /* 0x1F0 */ uint8_t _end_marker[0];         /* size unknown, >= 0x1F0 */
} ns2_ccMenuPuppetDemoSelect;

static_assert(offsetof(ns2_ccMenuPuppetDemoSelect, vtable) == 0x000, "ccMenuPuppetDemoSelect.vtable");
static_assert(offsetof(ns2_ccMenuPuppetDemoSelect, base_data) == 0x008, "ccMenuPuppetDemoSelect.base_data");
static_assert(offsetof(ns2_ccMenuPuppetDemoSelect, field_0x128) == 0x128, "ccMenuPuppetDemoSelect.field_0x128");
static_assert(offsetof(ns2_ccMenuPuppetDemoSelect, subobj_0x158) == 0x158, "ccMenuPuppetDemoSelect.subobj_0x158");
static_assert(offsetof(ns2_ccMenuPuppetDemoSelect, subobj_0x1ac) == 0x1AC, "ccMenuPuppetDemoSelect.subobj_0x1ac");
static_assert(offsetof(ns2_ccMenuPuppetDemoSelect, field_0x1ec) == 0x1EC, "ccMenuPuppetDemoSelect.field_0x1ec");

#endif /* ST2C04_H */