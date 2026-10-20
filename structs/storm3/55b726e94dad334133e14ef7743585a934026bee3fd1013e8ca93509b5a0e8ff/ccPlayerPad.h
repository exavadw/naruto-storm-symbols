/*
 * ccPlayerPad — NARUTO STORM 3 Full Burst HD (s3) struct layout
 * Build: s3 (NSUNS3.exe, 64-bit, SHA256 a7124b...)
 * Status: INFERRED (static analysis only; no runtime confirmation)
 * Date: 2026-10-19
 *
 * Stick stride: 0x108 (2 sticks). Command history: 60 interleaved pairs at 0x218.
 * Highest confirmed field: config_520 at offset 0x520.
 * Size NOT asserted via sizeof; exact allocation size unconfirmed.
 * Lower bound: >= 0x524 bytes.
 *
 * NOTE: vtable is 8 bytes on x64. First stick field (analog_pow) is at 0x008.
 * Offset 0x004 is inside the vtable pointer and has no known field.
 */

#ifndef CCPLAYERPAD_S3_H
#define CCPLAYERPAD_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct ccPlayerPad {
    /* 0x000 */ void *vtable;               /* high: ccPlayerPad::ccPlayerPad — PTR_FUN_1409daf00 */
    /* 0x008 */ float stick0_analog_pow;    /* high: GetAnalogPow idx*0x108+8; RequestAnalogStickL writes */
    /* 0x00C */ float stick0_field_00C;     /* medium: Clear zeros 8 bytes at base+0x08 covers this */
    /* 0x010 */ float stick0_analog_ang;    /* high: GetAnalogAng idx*0x108+0x10; RequestAnalogStickL writes */
    /* 0x014 */ float stick0_field_014;     /* medium: Clear zeros 8 bytes at base+0x10 covers this */
    /* 0x018 */ float stick0_field_018;     /* medium: Clear sets *(lVar2+0xC)=1.0f where lVar2=base+0xC → base+0x18 */
    /* 0x01C */ float stick0_field_01C;     /* medium: Clear sets 8 bytes at base+0x18 covers this too */
    /* 0x020 */ uint32_t stick0_history_lower[30]; /* high: Clear puVar3[-0x1E]..puVar3[-1] zeroed; puVar3=lVar2+0x8C=base+0x98 → base+0x20..0x94 */
    /* 0x098 */ uint32_t stick0_history_upper[30]; /* high: Clear puVar3[0]..puVar3[29] zeroed; base+0x98..0x10C */
    /* 0x110: stick0 ends here (0x098 + 30*4 = 0x110). Next: stick1 starts at 0x110 */

    /* --- Stick 1 region (stride 0x108, offsets 0x110..0x217 relative to base) --- */
    /* 0x110 */ float stick1_analog_pow;    /* high: GetAnalogPow 1*0x108+8=0x110; Reset zeros */
    /* 0x114 */ float stick1_field_114;     /* medium: Clear second iter *(lVar2-4) where lVar2=base+0x114 */
    /* 0x118 */ float stick1_analog_ang;    /* high: GetAnalogAng 1*0x108+0x10=0x118; Reset zeros */
    /* 0x11C */ float stick1_field_11C;     /* medium: Clear second iter *(lVar2+4) */
    /* 0x120 */ float stick1_field_120;     /* medium: Clear second iter *(lVar2+0xC)=1.0f */
    /* 0x124 */ float stick1_field_124;     /* medium: Clear second iter 8-byte write covers this */
    /* 0x128 */ uint32_t stick1_history_lower[30]; /* high: Clear second iter puVar3[-0x1E] zeroed */
    /* 0x1A0 */ uint32_t stick1_history_upper[30]; /* high: Clear second iter puVar3[0] zeroed */
    /* 0x218: stick1 ends here (0x1A0 + 30*4 = 0x218). Next: cmd_history starts at 0x218 */

    /* --- Command history (60 interleaved pairs: uint32 key + float value, 8 bytes each) --- */
    /* Layout: [key0][val0][key1][val1]...[key59][val59]. Total 60*8 = 0x1E0 = 480 bytes */
    /* 0x218 */ uint8_t cmd_history[480];   /* high: Clear/Ctrl/CommandFunc; 60 pairs interleaved */
    /* 0x3F8: cmd_history ends (0x218 + 0x1E0 = 0x3F8). Next: pad_index */

    /* --- Post-history scalars --- */
    /* 0x3F8 */ int32_t pad_index;          /* high: Init from param_3 or -1; Ctrl checks >=0 */
    /* 0x3FC */ uint32_t button_mask;       /* high: Init=0xFFFFFFFF; Ctrl ANDs network pad with this */
    /* 0x400 */ int32_t unk_400;            /* medium: Ctrl reads as iVar6; ctor *(param_1+0x80)=0 (undefined8* arith → 0x400) */
    /* 0x404 */ uint32_t pressed_buttons;   /* high: Ctrl masked state; Is/Request read; Clear/Reset zero */
    /* 0x408 */ uint32_t held_buttons;      /* high: Ctrl "On" state; IsAttackOn/IsChakraOn/IsGuardOn check */
    /* 0x40C */ uint32_t released_buttons;  /* high: IsAttackRelease; Clear/Reset zero */
    /* 0x410 */ int32_t lever_random_score; /* high: SetLeverRandomScore writes; Init/ResetReqCmd=0xFFFFFFFF */
    /* 0x414 */ uint8_t move_direction[12]; /* high: Nucc::Vector3; ctor calls Vector3(); RequestMove writes 12 bytes */
    /* 0x420 */ uint32_t move_active;       /* high: RequestMove sets=1; Clear sets=0 */
    /* 0x424 */ uint32_t success_command;   /* high: IsSuccessCommand reads; CommandFunc/Clear reset */
    /* 0x428 */ uint32_t requested_commands[51]; /* high: RequestCommand[idx]=1; ResetReqCmd memset 0xCC=204 bytes */
    /* 0x4F4: requested_commands ends (0x428 + 51*4 = 0x428 + 0xCC = 0x4F4). Next: button masks */

    /* --- Button mapping config (set by Init via FUN_140484438) --- */
    /* 0x4F4 */ uint32_t jump_button_mask;  /* high: Init FUN(...,1); IsJump uses */
    /* 0x4F8 */ uint32_t attack_button_mask;/* high: Init FUN(...,0); IsAttack/IsAttackOn/RequestAttack use */
    /* 0x4FC */ uint32_t firearm_button_mask;/* high: Init FUN(...,3); IsFireArm uses */
    /* 0x500 */ uint32_t chakra_button_mask;/* high: Init FUN(...,2); IsChakra uses */
    /* 0x504 */ uint32_t guard_button_mask; /* high: Init FUN(...,7); IsGuard/IsGuardOn/RequestGuard use */
    /* 0x508 */ uint32_t dodge_button_mask; /* high: Init FUN(...,6); IsDodge/IsSuccessTimingDodge use */
    /* 0x50C */ uint32_t supportL_button_mask;/* high: Init FUN(...,4); IsSupportL/RequestSupportL use */
    /* 0x510 */ uint32_t supportR_button_mask;/* high: Init FUN(...,5); IsSupportR/RequestSupportR use */
    /* 0x514 */ uint32_t config_514;        /* medium: Init sets 0x80 */
    /* 0x518 */ uint32_t config_518;        /* medium: Init sets 0x10 */
    /* 0x51C */ uint32_t config_51C;        /* medium: Init sets 0x20 */
    /* 0x520 */ uint32_t config_520;        /* medium: Init sets 0x40 */
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
static_assert(offsetof(ccPlayerPad, cmd_history) == 0x218, "cmd_history @ 0x218");
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
static_assert(offsetof(ccPlayerPad, jump_button_mask) == 0x4F4, "jump_button_mask @ 0x4F4");
static_assert(offsetof(ccPlayerPad, attack_button_mask) == 0x4F8, "attack_button_mask @ 0x4F8");
static_assert(offsetof(ccPlayerPad, firearm_button_mask) == 0x4FC, "firearm_button_mask @ 0x4FC");
static_assert(offsetof(ccPlayerPad, chakra_button_mask) == 0x500, "chakra_button_mask @ 0x500");
static_assert(offsetof(ccPlayerPad, guard_button_mask) == 0x504, "guard_button_mask @ 0x504");
static_assert(offsetof(ccPlayerPad, dodge_button_mask) == 0x508, "dodge_button_mask @ 0x508");
static_assert(offsetof(ccPlayerPad, supportL_button_mask) == 0x50C, "supportL_button_mask @ 0x50C");
static_assert(offsetof(ccPlayerPad, supportR_button_mask) == 0x510, "supportR_button_mask @ 0x510");
static_assert(offsetof(ccPlayerPad, config_514) == 0x514, "config_514 @ 0x514");
static_assert(offsetof(ccPlayerPad, config_518) == 0x518, "config_518 @ 0x518");
static_assert(offsetof(ccPlayerPad, config_51C) == 0x51C, "config_51C @ 0x51C");
static_assert(offsetof(ccPlayerPad, config_520) == 0x520, "config_520 @ 0x520");

/* Size is NOT asserted: exact allocation size has not been confirmed from
 * operator new or factory. Highest confirmed field ends at 0x524.
 * Lower bound: sizeof(ccPlayerPad) >= 0x524. */

#endif /* CCPLAYERPAD_S3_H */