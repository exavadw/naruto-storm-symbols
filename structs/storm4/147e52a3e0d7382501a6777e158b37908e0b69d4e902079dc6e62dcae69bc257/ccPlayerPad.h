/*
 * ccPlayerPad — NARUTO STORM 4 (s4) struct layout
 * Build: s4 (NSUNS4_release.exe, 64-bit, SHA256 147e52a3...)
 * Status: INFERRED (static analysis only; no runtime confirmation)
 * Date: 2026-10-19
 *
 * Stick stride: 0x108 (2 sticks). Command history: 60 interleaved pairs at 0x218.
 * Highest confirmed field: clear_flag at offset 0xCAC (uint32_t, ends at 0xCB0).
 * Size NOT asserted via sizeof; exact allocation size unconfirmed.
 * Lower bound: >= 0xCB0 bytes.
 *
 * NOTE: vtable is 8 bytes on x64. First stick field (analog_pow) is at 0x008.
 * Offset 0x004 is inside the vtable pointer and has no known field.
 *
 * s4 vs s3 changes:
 * - Button mapping config moved from 0x4F4..0x520 to 0x584..0x5B0
 * - New fields: unk_494, unk_5b8 (vfunc ptr), unk_5d0, unk_6ac, unk_6bc, clear_flag (0xCAC)
 * - requested_commands region expanded (memset 0x15C = 348 bytes in PreCtrl vs 0xCC in ResetReqCmd)
 * - Ctrl at 0x6592F8 is MISATTRIBUTED (std::string fields, "CloseWindow" — likely UI class)
 * - Real ccPlayerPad::Ctrl is at 0x7C03F0
 */

#ifndef CCPLAYERPAD_S4_H
#define CCPLAYERPAD_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ccPlayerPad {
    /* 0x000 */ void *vtable;               /* high: ccPlayerPad::ccPlayerPad — PTR_FUN_140ff6800 */
    /* 0x008 */ float stick0_analog_pow;    /* high: GetAnalogPow idx*0x108+8; RequestAnalogStickL writes */
    /* 0x00C */ float stick0_field_00C;     /* medium: Clear zeros 8 bytes at base+0x08 covers this */
    /* 0x010 */ float stick0_analog_ang;    /* high: GetAnalogAng idx*0x108+0x10; RequestAnalogStickL writes */
    /* 0x014 */ float stick0_field_014;     /* medium: Clear zeros 8 bytes at base+0x10 covers this */
    /* 0x018 */ float stick0_field_018;     /* medium: Ctrl sets *(lVar2+0xC)=1.0f where lVar2=base+0xC → base+0x18 */
    /* 0x01C */ float stick0_field_01C;     /* medium: Ctrl sets 8 bytes at base+0x18 covers this too */
    /* 0x020 */ uint32_t stick0_history_lower[30]; /* high: Ctrl puVar6[-0x1E]..puVar6[-1] shifted; 30 entries */
    /* 0x098 */ uint32_t stick0_history_upper[30]; /* high: Ctrl puVar6[0]..puVar6[29] shifted; 30 entries */
    /* 0x110: stick0 ends here (0x098 + 30*4 = 0x110). Next: stick1 starts at 0x110 */

    /* --- Stick 1 region (stride 0x108, offsets 0x110..0x217 relative to base) --- */
    /* 0x110 */ float stick1_analog_pow;    /* high: GetAnalogPow 1*0x108+8=0x110; Reset zeros */
    /* 0x114 */ float stick1_field_114;     /* medium: Clear second iter *(lVar2-4) where lVar2=base+0x114 */
    /* 0x118 */ float stick1_analog_ang;    /* high: GetAnalogAng 1*0x108+0x10=0x118; Reset zeros */
    /* 0x11C */ float stick1_field_11C;     /* medium: Clear second iter *(lVar2+4) */
    /* 0x120 */ float stick1_field_120;     /* medium: Clear second iter *(lVar2+0xC)=1.0f */
    /* 0x124 */ float stick1_field_124;     /* medium: Clear second iter 8-byte write covers this */
    /* 0x128 */ uint32_t stick1_history_lower[30]; /* high: Ctrl second iter puVar6[-0x1E] shifted */
    /* 0x1A0 */ uint32_t stick1_history_upper[30]; /* high: Ctrl second iter puVar6[0] shifted */
    /* 0x218: stick1 ends here (0x1A0 + 30*4 = 0x218). Next: cmd_history starts at 0x218 */

    /* --- Command history (60 interleaved pairs: uint32 key + float value, 8 bytes each) --- */
    /* Layout: [key0][val0][key1][val1]...[key59][val59]. Total 60*8 = 0x1E0 = 480 bytes */
    /* 0x218 */ uint32_t cmd_history_key0;  /* high: CommandFunc reads/writes; Clear/Ctrl access */
    /* 0x21C */ uint32_t cmd_history_val0;  /* high: CommandFunc increments match count */
    /* 0x220 */ uint8_t cmd_history_rest[472]; /* high: remaining 59 pairs; CommandFunc shifts array */
    /* 0x3F8: cmd_history ends (0x218 + 0x1E0 = 0x3F8). Next: pad_index */

    /* --- Post-history scalars --- */
    /* 0x3F8 */ int32_t pad_index;          /* high: Init from param_3 or -1; Ctrl checks >=0 */
    /* 0x3FC */ uint32_t button_mask;       /* high: Init=0xFFFFFFFF; Ctrl ANDs network pad with this */
    /* 0x400 */ int32_t unk_400;            /* medium: Ctrl reads as iVar5; ctor *(param_1+0x80)=0 (undefined8* arith → 0x400) */
    /* 0x404 */ uint32_t pressed_buttons;   /* high: Ctrl masked state; Is/Request read; Clear/Reset zero */
    /* 0x408 */ uint32_t held_buttons;      /* high: Ctrl "On" state; IsAttackOn/IsGuardOn check */
    /* 0x40C */ uint32_t released_buttons;  /* high: IsAttackRelease; Clear/Reset zero */
    /* 0x410 */ int32_t lever_random_score; /* high: SetLeverRandomScore writes; Init/ResetReqCmd=0xFFFFFFFF */
    /* 0x414 */ uint8_t move_direction[12]; /* high: Nucc::Vector3; ctor calls Vector3(); RequestMove writes 12 bytes */
    /* 0x420 */ uint32_t move_active;       /* high: RequestMove sets=1; Clear sets=0 */
    /* 0x424 */ uint32_t success_command;   /* high: IsSuccessCommand reads; CommandFunc/Clear reset */
    /* 0x428 */ uint32_t requested_commands[87]; /* high: RequestCommand[idx]=1; PreCtrl memset 0x15C=348 bytes; ResetReqCmd memset 0xC0=192 */
    /* 0x584: requested_commands region ends (0x428 + 87*4 = 0x584). Next: button masks */

    /* --- Button mapping config (set by Init via FUN_140865ec4) --- */
    /* 0x584 */ uint32_t jump_button_mask;  /* high: Init FUN(...,1); IsJump uses */
    /* 0x588 */ uint32_t attack_button_mask;/* high: Init FUN(...,0); IsAttack/IsAttackOn/RequestAttack use */
    /* 0x58C */ uint32_t firearm_button_mask;/* high: Init FUN(...,3); IsFireArm uses */
    /* 0x590 */ uint32_t chakra_button_mask;/* high: Init FUN(...,2); IsChakra uses */
    /* 0x594 */ uint32_t guard_button_mask; /* high: Init FUN(...,7); IsGuardOn/RequestGuard/IsCommandButtonShiftMove use */
    /* 0x598 */ uint32_t dodge_button_mask; /* high: Init FUN(...,6); IsSuccessTimingDodge uses */
    /* 0x59C */ uint32_t supportL_button_mask;/* high: Init FUN(...,4); IsSupportL uses */
    /* 0x5A0 */ uint32_t supportR_button_mask;/* high: Init FUN(...,5); IsSupportR uses */
    /* 0x5A4 */ uint32_t config_5a4;        /* medium: Init sets 0x80 */
    /* 0x5A8 */ uint32_t config_5a8;        /* medium: Init sets 0x10 */
    /* 0x5AC */ uint32_t config_5ac;        /* medium: Init sets 0x20 */
    /* 0x5B0 */ uint32_t config_5b0;        /* medium: Init sets 0x40 */
    /* 0x5B4 */ uint8_t pad_5b4[4];         /* padding to align 0x5B8 */
    /* 0x5B8 */ void *unk_5b8_vtable;       /* high: Ctrl dereferences *(code**)(*(longlong*)(param_1+0x5B8)+0x20); Init reads */
    /* 0x5C0 */ uint8_t pad_5c0[16];        /* gap: 0x5C0..0x5CF unused in known methods */
    /* 0x5D0 */ int32_t unk_5d0;            /* medium: Init sets=0 when pad_index==-1 */
    /* 0x5D4 */ uint8_t pad_5d4[4];         /* padding */
    /* 0x5D8 */ uint32_t ctrl_state_d8;     /* high: Ctrl reads into local_68 */
    /* 0x5DC */ uint32_t ctrl_state_dc;     /* high: Ctrl reads into uStack_64 */
    /* 0x5E0 */ uint32_t ctrl_state_e0;     /* high: Ctrl reads into uStack_60 */
    /* 0x5E4 */ uint32_t ctrl_state_e4;     /* high: Ctrl reads into uStack_5c */
    /* 0x5E8 */ uint32_t ctrl_state_e8;     /* high: Ctrl reads into local_58 */
    /* 0x5EC */ uint32_t ctrl_state_ec_lo;  /* high: Ctrl reads into uStack_54 (low 32 bits) */
    /* 0x5F0 */ uint32_t ctrl_state_ec_hi;  /* high: Ctrl reads into uStack_54 (high 32 bits) */
    /* 0x5F4 */ uint32_t ctrl_state_f4_lo;  /* high: Ctrl reads into uStack_4c (low 32 bits) */
    /* 0x5F8 */ uint32_t ctrl_state_f4_hi;  /* high: Ctrl reads into uStack_4c (high 32 bits) */
    /* 0x5FC */ uint8_t pad_5fc[172];       /* gap: 0x5FC..0x6A7 unused in known methods */
    /* 0x6A8 */ uint8_t pad_6a8[4];         /* padding to align 0x6AC */
    /* 0x6AC */ int32_t init_pad_index_copy;/* medium: Init copies pad_index here when pad_index>=0 */
    /* 0x6B0 */ uint8_t pad_6b0[12];        /* gap: 0x6B0..0x6BB */
    /* 0x6BC */ int32_t init_config_6bc;    /* medium: Init sets=0 */
    /* 0x6C0 */ uint8_t pad_6c0[1516];      /* gap: 0x6C0..0xCAB unused in known methods */
    /* 0xCAC */ uint32_t clear_flag;        /* high: Clear sets=1 when param_2!=0 */
} ccPlayerPad;

/* Offset assertions for every named field */
static_assert(offsetof(ccPlayerPad, vtable) == 0x000, "vtable @ 0x000");
static_assert(offsetof(ccPlayerPad, stick0_analog_pow) == 0x008, "stick0_analog_pow @ 0x008");
static_assert(offsetof(ccPlayerPad, stick0_field_00C) == 0x00C, "stick0_field_00C @ 0x00C");
static_assert(offsetof(ccPlayerPad, stick0_analog_ang) == 0x010, "stick0_analog_ang @ 0x010");
static_assert(offsetof(ccPlayerPad, stick0_field_014) == 0x014, "stick0_field_014 @ 0x014");
static_assert(offsetof(ccPlayerPad, stick0_field_018) == 0x018, "stick0_field_018 @ 0x018");
static_assert(offsetof(ccPlayerPad, stick0_field_01C) == 0x01C, "stick0_field_01C @ 0x01C");
static_assert(offsetof(ccPlayerPad, stick0_history_lower) == 0x020, "stick0_history_lower @ 0x020");
static_assert(offsetof(ccPlayerPad, stick0_history_upper) == 0x098, "stick0_history_upper @ 0x098");
static_assert(offsetof(ccPlayerPad, stick1_analog_pow) == 0x110, "stick1_analog_pow @ 0x110");
static_assert(offsetof(ccPlayerPad, stick1_field_114) == 0x114, "stick1_field_114 @ 0x114");
static_assert(offsetof(ccPlayerPad, stick1_analog_ang) == 0x118, "stick1_analog_ang @ 0x118");
static_assert(offsetof(ccPlayerPad, stick1_field_11C) == 0x11C, "stick1_field_11C @ 0x11C");
static_assert(offsetof(ccPlayerPad, stick1_field_120) == 0x120, "stick1_field_120 @ 0x120");
static_assert(offsetof(ccPlayerPad, stick1_field_124) == 0x124, "stick1_field_124 @ 0x124");
static_assert(offsetof(ccPlayerPad, stick1_history_lower) == 0x128, "stick1_history_lower @ 0x128");
static_assert(offsetof(ccPlayerPad, stick1_history_upper) == 0x1A0, "stick1_history_upper @ 0x1A0");
static_assert(offsetof(ccPlayerPad, cmd_history_key0) == 0x218, "cmd_history_key0 @ 0x218");
static_assert(offsetof(ccPlayerPad, cmd_history_val0) == 0x21C, "cmd_history_val0 @ 0x21C");
static_assert(offsetof(ccPlayerPad, cmd_history_rest) == 0x220, "cmd_history_rest @ 0x220");
static_assert(offsetof(ccPlayerPad, pad_index) == 0x3F8, "pad_index @ 0x3F8");
static_assert(offsetof(ccPlayerPad, button_mask) == 0x3FC, "button_mask @ 0x3FC");
static_assert(offsetof(ccPlayerPad, unk_400) == 0x400, "unk_400 @ 0x400");
static_assert(offsetof(ccPlayerPad, pressed_buttons) == 0x404, "pressed_buttons @ 0x404");
static_assert(offsetof(ccPlayerPad, held_buttons) == 0x408, "held_buttons @ 0x408");
static_assert(offsetof(ccPlayerPad, released_buttons) == 0x40C, "released_buttons @ 0x40C");
static_assert(offsetof(ccPlayerPad, lever_random_score) == 0x410, "lever_random_score @ 0x410");
static_assert(offsetof(ccPlayerPad, move_direction) == 0x414, "move_direction @ 0x414");
static_assert(offsetof(ccPlayerPad, move_active) == 0x420, "move_active @ 0x420");
static_assert(offsetof(ccPlayerPad, success_command) == 0x424, "success_command @ 0x424");
static_assert(offsetof(ccPlayerPad, requested_commands) == 0x428, "requested_commands @ 0x428");
static_assert(offsetof(ccPlayerPad, jump_button_mask) == 0x584, "jump_button_mask @ 0x584");
static_assert(offsetof(ccPlayerPad, attack_button_mask) == 0x588, "attack_button_mask @ 0x588");
static_assert(offsetof(ccPlayerPad, firearm_button_mask) == 0x58C, "firearm_button_mask @ 0x58C");
static_assert(offsetof(ccPlayerPad, chakra_button_mask) == 0x590, "chakra_button_mask @ 0x590");
static_assert(offsetof(ccPlayerPad, guard_button_mask) == 0x594, "guard_button_mask @ 0x594");
static_assert(offsetof(ccPlayerPad, dodge_button_mask) == 0x598, "dodge_button_mask @ 0x598");
static_assert(offsetof(ccPlayerPad, supportL_button_mask) == 0x59C, "supportL_button_mask @ 0x59C");
static_assert(offsetof(ccPlayerPad, supportR_button_mask) == 0x5A0, "supportR_button_mask @ 0x5A0");
static_assert(offsetof(ccPlayerPad, config_5a4) == 0x5A4, "config_5a4 @ 0x5A4");
static_assert(offsetof(ccPlayerPad, config_5a8) == 0x5A8, "config_5a8 @ 0x5A8");
static_assert(offsetof(ccPlayerPad, config_5ac) == 0x5AC, "config_5ac @ 0x5AC");
static_assert(offsetof(ccPlayerPad, config_5b0) == 0x5B0, "config_5b0 @ 0x5B0");
static_assert(offsetof(ccPlayerPad, pad_5b4) == 0x5B4, "pad_5b4 @ 0x5B4");
static_assert(offsetof(ccPlayerPad, unk_5b8_vtable) == 0x5B8, "unk_5b8_vtable @ 0x5B8");
static_assert(offsetof(ccPlayerPad, pad_5c0) == 0x5C0, "pad_5c0 @ 0x5C0");
static_assert(offsetof(ccPlayerPad, unk_5d0) == 0x5D0, "unk_5d0 @ 0x5D0");
static_assert(offsetof(ccPlayerPad, pad_5d4) == 0x5D4, "pad_5d4 @ 0x5D4");
static_assert(offsetof(ccPlayerPad, ctrl_state_d8) == 0x5D8, "ctrl_state_d8 @ 0x5D8");
static_assert(offsetof(ccPlayerPad, ctrl_state_dc) == 0x5DC, "ctrl_state_dc @ 0x5DC");
static_assert(offsetof(ccPlayerPad, ctrl_state_e0) == 0x5E0, "ctrl_state_e0 @ 0x5E0");
static_assert(offsetof(ccPlayerPad, ctrl_state_e4) == 0x5E4, "ctrl_state_e4 @ 0x5E4");
static_assert(offsetof(ccPlayerPad, ctrl_state_e8) == 0x5E8, "ctrl_state_e8 @ 0x5E8");
static_assert(offsetof(ccPlayerPad, ctrl_state_ec_lo) == 0x5EC, "ctrl_state_ec_lo @ 0x5EC");
static_assert(offsetof(ccPlayerPad, ctrl_state_ec_hi) == 0x5F0, "ctrl_state_ec_hi @ 0x5F0");
static_assert(offsetof(ccPlayerPad, ctrl_state_f4_lo) == 0x5F4, "ctrl_state_f4_lo @ 0x5F4");
static_assert(offsetof(ccPlayerPad, ctrl_state_f4_hi) == 0x5F8, "ctrl_state_f4_hi @ 0x5F8");
static_assert(offsetof(ccPlayerPad, pad_5fc) == 0x5FC, "pad_5fc @ 0x5FC");
static_assert(offsetof(ccPlayerPad, pad_6a8) == 0x6A8, "pad_6a8 @ 0x6A8");
static_assert(offsetof(ccPlayerPad, init_pad_index_copy) == 0x6AC, "init_pad_index_copy @ 0x6AC");
static_assert(offsetof(ccPlayerPad, pad_6b0) == 0x6B0, "pad_6b0 @ 0x6B0");
static_assert(offsetof(ccPlayerPad, init_config_6bc) == 0x6BC, "init_config_6bc @ 0x6BC");
static_assert(offsetof(ccPlayerPad, pad_6c0) == 0x6C0, "pad_6c0 @ 0x6C0");
static_assert(offsetof(ccPlayerPad, clear_flag) == 0xCAC, "clear_flag @ 0xCAC");

/* Size is NOT asserted: exact allocation size has not been confirmed from
 * operator new or factory. Highest confirmed field ends at 0xCB0.
 * Lower bound: sizeof(ccPlayerPad) >= 0xCB0. */

#endif /* CCPLAYERPAD_S4_H */