/*
 * ccPlayerPad — NARUTO STORM 2 (s2) struct layout
 * Build: s2 (NSUNS2.exe, SHA256 abf2b6...)
 * Status: INFERRED (static analysis only; no runtime confirmation)
 * Date: 2026-10-19
 *
 * Embedded in ccCharacterBase at offset 0x228 (param_1+0x45 as undefined8*).
 * Next sibling sub-object at ccCharacterBase+0x608 → upper bound size = 0x3E0.
 * Highest confirmed field access: 0x3C8 (Init). Last byte of buffer_334: 0x39B.
 * Size is NOT asserted via sizeof because exact allocation size is unconfirmed;
 * upper bound from embedding context is 0x3E0 (992 bytes).
 */

#ifndef CCPLAYERPAD_S2_H
#define CCPLAYERPAD_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ccPlayerPad {
    /* 0x000 */ void *vtable;                          /* PTR_FUN_1408918e8 set by ctor */

    /* --- Stick 0 (offset 0x008, stride 0x90) --- */
    /* 0x008 */ float stick0_analog_pow;               /* GetAnalogPow reads +0x8 + idx*0x90 */
    /* 0x00C */ float stick0_field_00C;                /* Clear: *(lVar2-4)=0 where lVar2=base+0xC */
    /* 0x010 */ float stick0_field_010;                /* Clear: *(lVar2+4)=0 */
    /* 0x014 */ uint32_t stick0_history_prev[15];      /* Ctrl: puVar4[-2]=puVar4[-3] shift chain, base+0x14 */
    /* 0x050 */ uint32_t stick0_history_curr[15];      /* Ctrl: inner array at stick+0x50 (=base+0x14+0x3C) */
    /* 0x08C */ uint32_t stick0_pad_08C[1];            /* padding to next stick field */
    /* 0x090 */ uint8_t stick0_trailing_pad[8];        /* gap between stick0 end (0x90) and stick1 start (0x98) */

    /* --- Stick 1 (offset 0x098, stride 0x90) --- */
    /* 0x098 */ float stick1_analog_pow;               /* GetAnalogPow: +0x8 + 1*0x90 = 0x98 */
    /* 0x09C */ float stick1_field_09C;                /* Clear: second iteration lVar2-4 */
    /* 0x0A0 */ float stick1_field_0A0;                /* Clear: second iteration lVar2+4 */
    /* 0x0A4 */ uint32_t stick1_history_prev[15];      /* Ctrl: second stick puVar4[-2] chain */
    /* 0x0E0 */ uint32_t stick1_history_curr[15];      /* Ctrl: second stick inner array */
    /* 0x11C */ uint32_t stick1_pad_11C[1];            /* padding */

    /* --- Post-stick scalars --- */
    /* 0x120 */ uint32_t unk_120;                      /* not directly accessed; gap fill */
    /* 0x124 */ uint32_t unk_124;                      /* gap fill */

    /* --- Command history buffer (60 pairs, 0x3C iterations) --- */
    /* 0x128 */ uint32_t cmd_history_keys[60];         /* Clear/Ctrl/CommandFunc: key slot, init=0 */
    /* 0x218 */ uint32_t cmd_history_values[60];       /* Clear/Ctrl/CommandFunc: value slot, init=0xFFFFFFFF */

    /* --- Command match tracking --- */
    /* 0x308 */ int32_t pad_index;                     /* Init: from param_2 or -1; Ctrl: if >= 0 process input */
    /* 0x30C */ uint32_t button_mask;                  /* Init: 0xFFFFFFFF; Ctrl: AND with network pad */
    /* 0x310 */ uint32_t pressed_buttons;              /* Ctrl: masked button state; Clear/Reset: zeroed */
    /* 0x314 */ uint32_t pressed_buttons_314;          /* Ctrl: puVar2[2] & mask */
    /* 0x318 */ uint32_t pressed_buttons_318;          /* Ctrl: puVar2[1] & mask; Clear: zeroed */
    /* 0x31C */ int32_t active_cmd_slot;               /* Init/Clear/PreCtrl: 0xFFFFFFFF = none */
    /* 0x320 */ uint64_t axis_x_lo;                    /* Clear: from Nucc::Vector3::xAxis() lo 8 bytes */
    /* 0x328 */ uint32_t axis_x_hi;                    /* Clear: from xAxis hi word */
    /* 0x32C */ uint32_t unk_32C;                      /* Clear/PreCtrl: zeroed */
    /* 0x330 */ uint32_t cmd_match_counter;            /* CommandFunc: incremented on match, reset on mismatch */
    /* 0x334 */ uint8_t buffer_334[104];               /* Clear/PreCtrl: memset 0x68 bytes */

    /* --- Config / mapping region (set by Init) --- */
    /* 0x39C */ uint32_t config_39C;                   /* Init: FUN_14053303c(...,1) */
    /* 0x3A0 */ uint32_t attack_button_mask;           /* Init: FUN_14053303c(...,0); IsAttack uses this */
    /* 0x3A4 */ uint32_t config_3A4;                   /* Init: FUN_14053303c(...,3) */
    /* 0x3A8 */ uint32_t config_3A8;                   /* Init: FUN_14053303c(...,2) */
    /* 0x3AC */ uint32_t config_3AC;                   /* Init: FUN_14053303c(...,7) */
    /* 0x3B0 */ uint32_t unk_3B0;                      /* gap between 0x3AC and 0x3B4 */
    /* 0x3B4 */ uint32_t threshold_low;                /* Init: 0x100 or 0x400 based on flag 0x400 */
    /* 0x3B8 */ uint32_t threshold_high;               /* Init: 0x200 or 0x800 based on flag 0x400 */
    /* 0x3BC */ uint32_t config_3BC;                   /* Init: 0x80 */
    /* 0x3C0 */ uint32_t config_3C0;                   /* Init: 0x10 */
    /* 0x3C4 */ uint32_t config_3C4;                   /* Init: 0x20 */
    /* 0x3C8 */ uint32_t config_3C8;                   /* Init: 0x40 */

    /* 0x3CC */ uint8_t pad_3CC[20];                   /* padding to reach embedding upper bound 0x3E0 */
} ccPlayerPad;

/* Offset assertions for every named field */
static_assert(offsetof(ccPlayerPad, vtable) == 0x000, "vtable");
static_assert(offsetof(ccPlayerPad, stick0_analog_pow) == 0x008, "stick0_analog_pow");
static_assert(offsetof(ccPlayerPad, stick0_field_00C) == 0x00C, "stick0_field_00C");
static_assert(offsetof(ccPlayerPad, stick0_field_010) == 0x010, "stick0_field_010");
static_assert(offsetof(ccPlayerPad, stick0_history_prev) == 0x014, "stick0_history_prev");
static_assert(offsetof(ccPlayerPad, stick0_history_curr) == 0x050, "stick0_history_curr");
static_assert(offsetof(ccPlayerPad, stick0_pad_08C) == 0x08C, "stick0_pad_08C");
static_assert(offsetof(ccPlayerPad, stick0_trailing_pad) == 0x090, "stick0_trailing_pad");
static_assert(offsetof(ccPlayerPad, stick1_analog_pow) == 0x098, "stick1_analog_pow");
static_assert(offsetof(ccPlayerPad, stick1_field_09C) == 0x09C, "stick1_field_09C");
static_assert(offsetof(ccPlayerPad, stick1_field_0A0) == 0x0A0, "stick1_field_0A0");
static_assert(offsetof(ccPlayerPad, stick1_history_prev) == 0x0A4, "stick1_history_prev");
static_assert(offsetof(ccPlayerPad, stick1_history_curr) == 0x0E0, "stick1_history_curr");
static_assert(offsetof(ccPlayerPad, stick1_pad_11C) == 0x11C, "stick1_pad_11C");
static_assert(offsetof(ccPlayerPad, unk_120) == 0x120, "unk_120");
static_assert(offsetof(ccPlayerPad, unk_124) == 0x124, "unk_124");
static_assert(offsetof(ccPlayerPad, cmd_history_keys) == 0x128, "cmd_history_keys");
static_assert(offsetof(ccPlayerPad, cmd_history_values) == 0x218, "cmd_history_values");
static_assert(offsetof(ccPlayerPad, pad_index) == 0x308, "pad_index");
static_assert(offsetof(ccPlayerPad, button_mask) == 0x30C, "button_mask");
static_assert(offsetof(ccPlayerPad, pressed_buttons) == 0x310, "pressed_buttons");
static_assert(offsetof(ccPlayerPad, pressed_buttons_314) == 0x314, "pressed_buttons_314");
static_assert(offsetof(ccPlayerPad, pressed_buttons_318) == 0x318, "pressed_buttons_318");
static_assert(offsetof(ccPlayerPad, active_cmd_slot) == 0x31C, "active_cmd_slot");
static_assert(offsetof(ccPlayerPad, axis_x_lo) == 0x320, "axis_x_lo");
static_assert(offsetof(ccPlayerPad, axis_x_hi) == 0x328, "axis_x_hi");
static_assert(offsetof(ccPlayerPad, unk_32C) == 0x32C, "unk_32C");
static_assert(offsetof(ccPlayerPad, cmd_match_counter) == 0x330, "cmd_match_counter");
static_assert(offsetof(ccPlayerPad, buffer_334) == 0x334, "buffer_334");
static_assert(offsetof(ccPlayerPad, config_39C) == 0x39C, "config_39C");
static_assert(offsetof(ccPlayerPad, attack_button_mask) == 0x3A0, "attack_button_mask");
static_assert(offsetof(ccPlayerPad, config_3A4) == 0x3A4, "config_3A4");
static_assert(offsetof(ccPlayerPad, config_3A8) == 0x3A8, "config_3A8");
static_assert(offsetof(ccPlayerPad, config_3AC) == 0x3AC, "config_3AC");
static_assert(offsetof(ccPlayerPad, unk_3B0) == 0x3B0, "unk_3B0");
static_assert(offsetof(ccPlayerPad, threshold_low) == 0x3B4, "threshold_low");
static_assert(offsetof(ccPlayerPad, threshold_high) == 0x3B8, "threshold_high");
static_assert(offsetof(ccPlayerPad, config_3BC) == 0x3BC, "config_3BC");
static_assert(offsetof(ccPlayerPad, config_3C0) == 0x3C0, "config_3C0");
static_assert(offsetof(ccPlayerPad, config_3C4) == 0x3C4, "config_3C4");
static_assert(offsetof(ccPlayerPad, config_3C8) == 0x3C8, "config_3C8");
static_assert(offsetof(ccPlayerPad, pad_3CC) == 0x3CC, "pad_3CC");

/* Size is NOT asserted: upper bound 0x3E0 from ccCharacterBase embedding,
   but exact allocation size has not been confirmed from operator new or factory.
   Highest confirmed field ends at 0x3CC. */

#endif /* CCPLAYERPAD_S2_H */