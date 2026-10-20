#ifndef CCPLAYER_S3_H
#define CCPLAYER_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccPlayer struct layout for NARUTO STORM 3 Full Burst HD (NSUNS3.exe, 64-bit)
 * Build alias: s3 | SHA: 55b726e94dad
 * Allocation size: 0xAFB8 (44984 bytes)
 * Source: CreatePlayer04<ccPlayerMain> calls LoadTh(0xAFB8, ...)
 * Vtable RVA: 0x98B678
 * Generated from state_surface (418 fields) + ctor analysis
 * All fields are INFERRED from static analysis unless noted CONFIRMED.
 */

typedef struct ccPlayer {
    uint8_t vtable[0x8]; /* 0x0 [rw] high */
    uint8_t unk_0x8[0x38]; /* 0x8 [rw] low */
    uint8_t pad_state_base[0x8]; /* 0x40 [rw] medium */
    uint8_t unk_48[0x8]; /* 0x48 [r] medium */
    uint8_t unk_50[0x8]; /* 0x50 [r] medium */
    uint8_t unk_58[0x4]; /* 0x58 [r] medium */
    uint8_t pad_5c[0x14]; /* 0x5C - 0x70 */
    uint8_t anim_state[0x4]; /* 0x70 [r] low */
    uint8_t pad_74[0x4]; /* 0x74 - 0x78 */
    uint8_t unk_78[0x4]; /* 0x78 [r] medium */
    uint8_t pad_7c[0x4]; /* 0x7C - 0x80 */
    uint8_t unk_80[0x4]; /* 0x80 [w] medium */
    uint8_t pad_84[0xC]; /* 0x84 - 0x90 */
    uint8_t anim_state_1[0x8]; /* 0x90 [rw] low */
    uint8_t unk_98[0x4]; /* 0x98 [rw] high */
    uint8_t anim_state_2[0x8]; /* 0x9C [rw] low */
    uint8_t combo_throw_pos[0x4]; /* 0xA4 [w] high */
    uint8_t anim_state_3[0x8]; /* 0xA8 [r] low */
    uint8_t throw_ctrl[0x4]; /* 0xB0 [r] medium */
    uint8_t atk_ctrl[0x4]; /* 0xB4 [r] low */
    uint8_t unk_b8[0x4]; /* 0xB8 [r] medium */
    uint8_t unk_bc[0x4]; /* 0xBC [r] medium */
    uint8_t chakra_ctrl[0x8]; /* 0xC0 [rw] low */
    uint8_t unk_c8[0x4]; /* 0xC8 [w] high */
    uint8_t pad_cc[0x3C]; /* 0xCC - 0x108 */
    uint8_t anim_state_4[0x4]; /* 0x108 [r] low */
    uint8_t pad_10c[0x3C]; /* 0x10C - 0x148 */
    uint8_t unk_148[0x8]; /* 0x148 [rw] low */
    uint8_t chakra_ctrl_1[0x4]; /* 0x150 [rw] high */
    uint8_t atk_ctrl_1[0x4]; /* 0x154 [rw] low */
    uint8_t atk_ctrl_2[0x4]; /* 0x158 [rw] low */
    uint8_t atk_ctrl_3[0x4]; /* 0x15C [rw] high */
    uint8_t chakra_ctrl_2[0x4]; /* 0x160 [rw] high */
    uint8_t action_state[0x4]; /* 0x164 [rw] low */
    uint8_t unk_168[0x4]; /* 0x168 [rw] high */
    uint8_t dmg_ctrl[0x4]; /* 0x16C [rw] low */
    uint8_t unk_170[0x4]; /* 0x170 [rw] high */
    uint8_t pad_174[0x2C]; /* 0x174 - 0x1A0 */
    uint8_t combo_throw_pos_1[0x8]; /* 0x1A0 [rw] low */
    uint8_t combo_throw_pos_2[0x4]; /* 0x1A8 [w] high */
    uint8_t combo_throw_pos_3[0x8]; /* 0x1AC [rw] low */
    uint8_t combo_throw_pos_4[0x4]; /* 0x1B4 [w] high */
    uint8_t unk_1b8[0x4]; /* 0x1B8 [r] low */
    uint8_t unk_1bc[0x4]; /* 0x1BC [r] low */
    uint8_t pad_1c0[0x3C]; /* 0x1C0 - 0x1FC */
    uint8_t unk_1fc[0x4]; /* 0x1FC [w] medium */
    uint8_t action_state_1[0x8]; /* 0x200 [r] low */
    uint8_t pad_208[0x8]; /* 0x208 - 0x210 */
    uint8_t atk_ctrl_4[0x4]; /* 0x210 [r] low */
    uint8_t pad_214[0x4]; /* 0x214 - 0x218 */
    uint8_t pad_input[0x28]; /* 0x218 [rw] medium */
    uint8_t unk_240[0x4]; /* 0x240 [r] low */
    uint8_t pad_244[0x3C]; /* 0x244 - 0x280 */
    uint8_t chakra_ctrl_3[0x4]; /* 0x280 [r] low */
    uint8_t pad_284[0x3C]; /* 0x284 - 0x2C0 */
    uint8_t chakra_ctrl_4[0x4]; /* 0x2C0 [r] low */
    uint8_t pad_2c4[0xBC]; /* 0x2C4 - 0x380 */
    uint8_t chakra_ctrl_5[0x4]; /* 0x380 [r] low */
    uint8_t pad_384[0xBC]; /* 0x384 - 0x440 */
    uint8_t unk_440[0x4]; /* 0x440 [r] low */
    uint8_t pad_444[0x3C]; /* 0x444 - 0x480 */
    uint8_t unk_480[0x4]; /* 0x480 [r] low */
    uint8_t pad_484[0x3C]; /* 0x484 - 0x4C0 */
    uint8_t guard_ctrl[0x4]; /* 0x4C0 [r] low */
    uint8_t pad_4c4[0x160]; /* 0x4C4 - 0x624 */
    uint8_t atk_ctrl_5[0x8]; /* 0x624 [r] medium */
    uint8_t dmg_ctrl_1[0x4]; /* 0x62C [r] medium */
    uint8_t atk_ctrl_6[0x8]; /* 0x630 [r] medium */
    uint8_t pad_638[0xC8]; /* 0x638 - 0x700 */
    uint8_t chakra_ctrl_6[0x4]; /* 0x700 [r] low */
    uint8_t pad_704[0x34]; /* 0x704 - 0x738 */
    uint8_t unk_738[0x4]; /* 0x738 [r] medium */
    uint8_t unk_73c[0x4]; /* 0x73C [r] medium */
    uint8_t pad_740[0x238]; /* 0x740 - 0x978 */
    uint8_t unk_978[0x4]; /* 0x978 [r] low */
    uint8_t pad_97c[0x1C]; /* 0x97C - 0x998 */
    uint8_t unk_998[0x4]; /* 0x998 [r] medium */
    uint8_t unk_99c[0x4]; /* 0x99C [w] high */
    uint8_t unk_9a0[0x4]; /* 0x9A0 [rw] medium */
    uint8_t pad_9a4[0x4]; /* 0x9A4 - 0x9A8 */
    uint8_t anim_state_5[0x8]; /* 0x9A8 [r] medium */
    uint8_t unk_9b0[0x4]; /* 0x9B0 [r] medium */
    uint8_t action_state_2[0x4]; /* 0x9B4 [r] medium */
    uint8_t pad_9b8[0x4]; /* 0x9B8 - 0x9BC */
    uint8_t anim_state_6[0x4]; /* 0x9BC [r] medium */
    uint8_t unk_9c0[0x8]; /* 0x9C0 [r] medium */
    uint8_t guard_ctrl_1[0x8]; /* 0x9C8 [r] medium */
    uint8_t pad_9d0[0x4]; /* 0x9D0 - 0x9D4 */
    uint8_t unk_9d4[0x4]; /* 0x9D4 [r] medium */
    uint8_t dmg_ctrl_2[0x4]; /* 0x9D8 [w] medium */
    uint8_t unk_9dc[0x4]; /* 0x9DC [r] medium */
    uint8_t action_state_3[0x4]; /* 0x9E0 [rw] medium */
    uint8_t pad_9e4[0x4]; /* 0x9E4 - 0x9E8 */
    uint8_t anim_state_7[0x4]; /* 0x9E8 [r] medium */
    uint8_t action_state_4[0x4]; /* 0x9EC [rw] high */
    uint8_t action_state_5[0x4]; /* 0x9F0 [rw] high */
    uint8_t action_state_6[0x4]; /* 0x9F4 [rw] high */
    uint8_t action_state_7[0x4]; /* 0x9F8 [rw] high */
    uint8_t action_state_8[0x4]; /* 0x9FC [rw] high */
    uint8_t action_state_9[0x4]; /* 0xA00 [rw] high */
    uint8_t action_state_10[0x4]; /* 0xA04 [rw] high */
    uint8_t unk_a08[0x4]; /* 0xA08 [rw] high */
    uint8_t action_state_11[0x4]; /* 0xA0C [rw] high */
    uint8_t pad_a10[0x4]; /* 0xA10 - 0xA14 */
    uint8_t atk_ctrl_7[0x4]; /* 0xA14 [rw] high */
    uint8_t unk_a18[0x4]; /* 0xA18 [rw] high */
    uint8_t pad_a1c[0x10]; /* 0xA1C - 0xA2C */
    uint8_t unk_a2c[0x4]; /* 0xA2C [rw] high */
    uint8_t unk_a30[0x4]; /* 0xA30 [w] high */
    uint8_t unk_a34[0x4]; /* 0xA34 [rw] high */
    uint8_t unk_a38[0x8]; /* 0xA38 [r] medium */
    uint8_t pad_a40[0x4]; /* 0xA40 - 0xA44 */
    uint8_t dmg_ctrl_3[0x4]; /* 0xA44 [rw] high */
    uint8_t dmg_ctrl_4[0x4]; /* 0xA48 [w] high */
    uint8_t dmg_ctrl_5[0x4]; /* 0xA4C [w] high */
    uint8_t dmg_ctrl_6[0x4]; /* 0xA50 [w] high */
    uint8_t dmg_ctrl_7[0x4]; /* 0xA54 [rw] high */
    uint8_t dmg_ctrl_8[0x4]; /* 0xA58 [w] high */
    uint8_t dmg_ctrl_9[0x4]; /* 0xA5C [rw] high */
    uint8_t dmg_ctrl_10[0x4]; /* 0xA60 [r] medium */
    uint8_t dmg_ctrl_11[0x4]; /* 0xA64 [w] high */
    uint8_t pad_a68[0x14]; /* 0xA68 - 0xA7C */
    uint8_t unk_a7c[0x4]; /* 0xA7C [rw] high */
    uint8_t unk_a80[0x4]; /* 0xA80 [w] high */
    uint8_t unk_a84[0x4]; /* 0xA84 [rw] high */
    uint8_t unk_a88[0x8]; /* 0xA88 [r] medium */
    uint8_t pad_a90[0x8]; /* 0xA90 - 0xA98 */
    uint8_t anim_state_8[0x4]; /* 0xA98 [r] low */
    uint8_t pad_a9c[0xFC]; /* 0xA9C - 0xB98 */
    uint8_t unk_b98[0x8]; /* 0xB98 [r] medium */
    uint8_t pad_ba0[0x8]; /* 0xBA0 - 0xBA8 */
    uint8_t unk_ba8[0x4]; /* 0xBA8 [rw] medium */
    uint8_t unk_bac[0x4]; /* 0xBAC [rw] medium */
    uint8_t pad_bb0[0x4]; /* 0xBB0 - 0xBB4 */
    uint8_t unk_bb4[0x4]; /* 0xBB4 [r] medium */
    uint8_t unk_bb8[0x4]; /* 0xBB8 [rw] high */
    uint8_t unk_bbc[0x4]; /* 0xBBC [r] medium */
    uint8_t unk_bc0[0x4]; /* 0xBC0 [r] medium */
    uint8_t unk_bc4[0x4]; /* 0xBC4 [rw] medium */
    uint8_t unk_bc8[0x4]; /* 0xBC8 [rw] medium */
    uint8_t unk_bcc[0x4]; /* 0xBCC [r] medium */
    uint8_t unk_bd0[0x4]; /* 0xBD0 [r] medium */
    uint8_t pad_bd4[0xC]; /* 0xBD4 - 0xBE0 */
    uint8_t unk_be0[0x4]; /* 0xBE0 [rw] medium */
    uint8_t unk_be4[0x4]; /* 0xBE4 [rw] medium */
    uint8_t pad_be8[0x14]; /* 0xBE8 - 0xBFC */
    uint8_t unk_bfc[0x4]; /* 0xBFC [rw] medium */
    uint8_t unk_c00[0x4]; /* 0xC00 [rw] medium */
    uint8_t pad_c04[0x20]; /* 0xC04 - 0xC24 */
    uint8_t unk_c24[0x4]; /* 0xC24 [r] medium */
    uint8_t unk_c28[0x4]; /* 0xC28 [r] medium */
    uint8_t pad_c2c[0x8]; /* 0xC2C - 0xC34 */
    uint8_t unk_c34[0x4]; /* 0xC34 [rw] medium */
    uint8_t unk_c38[0x4]; /* 0xC38 [rw] medium */
    uint8_t unk_c3c[0x4]; /* 0xC3C [r] medium */
    uint8_t unk_c40[0x4]; /* 0xC40 [r] medium */
    uint8_t unk_c44[0x4]; /* 0xC44 [r] medium */
    uint8_t unk_c48[0x4]; /* 0xC48 [w] medium */
    uint8_t pad_c4c[0x4]; /* 0xC4C - 0xC50 */
    uint8_t unk_c50[0x4]; /* 0xC50 [rw] medium */
    uint8_t unk_c54[0x4]; /* 0xC54 [rw] medium */
    uint8_t unk_c58[0x4]; /* 0xC58 [r] medium */
    uint8_t unk_c5c[0x4]; /* 0xC5C [r] medium */
    uint8_t pad_c60[0xC]; /* 0xC60 - 0xC6C */
    uint8_t unk_c6c[0x4]; /* 0xC6C [rw] medium */
    uint8_t unk_c70[0x4]; /* 0xC70 [rw] medium */
    uint8_t pad_c74[0x14]; /* 0xC74 - 0xC88 */
    uint8_t unk_c88[0x4]; /* 0xC88 [r] medium */
    uint8_t char_id[0x4]; /* 0xC8C [rw] high */
    uint8_t pad_c90[0x8]; /* 0xC90 - 0xC98 */
    uint8_t unk_c98[0x4]; /* 0xC98 [rw] high */
    uint8_t unk_c9c[0x4]; /* 0xC9C [rw] medium */
    uint8_t unk_ca0[0x4]; /* 0xCA0 [r] medium */
    uint8_t unk_ca4[0x4]; /* 0xCA4 [rw] medium */
    uint8_t atk_ctrl_8[0x8]; /* 0xCA8 [r] low */
    uint8_t unk_cb0[0x4]; /* 0xCB0 [rw] medium */
    uint8_t pad_cb4[0x4]; /* 0xCB4 - 0xCB8 */
    uint8_t unk_cb8[0x8]; /* 0xCB8 [r] medium */
    uint8_t current_action[0x4]; /* 0xCC0 [rw] high */
    uint8_t previous_action[0x4]; /* 0xCC4 [rw] high */
    uint8_t pad_cc8[0x8]; /* 0xCC8 - 0xCD0 */
    uint8_t action_state_12[0x4]; /* 0xCD0 [w] medium */
    uint8_t anim_state_9[0x4]; /* 0xCD4 [rw] high */
    uint8_t anim_state_10[0x4]; /* 0xCD8 [rw] high */
    uint8_t anim_state_11[0x4]; /* 0xCDC [rw] high */
    uint8_t anim_state_12[0x4]; /* 0xCE0 [rw] high */
    uint8_t anim_state_13[0x4]; /* 0xCE4 [rw] high */
    uint8_t unk_ce8[0x4]; /* 0xCE8 [rw] high */
    uint8_t pad_cec[0x4]; /* 0xCEC - 0xCF0 */
    uint8_t unk_cf0[0x4]; /* 0xCF0 [rw] medium */
    uint8_t anim_state_14[0x4]; /* 0xCF4 [w] medium */
    uint8_t anim_state_15[0x4]; /* 0xCF8 [rw] high */
    uint8_t dmg_ctrl_12[0x4]; /* 0xCFC [rw] high */
    uint8_t dmg_ctrl_13[0x4]; /* 0xD00 [rw] high */
    uint8_t unk_d04[0x4]; /* 0xD04 [rw] high */
    uint8_t unk_d08[0x4]; /* 0xD08 [w] high */
    uint8_t pad_d0c[0x4]; /* 0xD0C - 0xD10 */
    uint8_t unk_d10[0x4]; /* 0xD10 [w] medium */
    uint8_t action_state_13[0x4]; /* 0xD14 [r] low */
    uint8_t pad_d18[0x140]; /* 0xD18 - 0xE58 */
    uint8_t dmg_ctrl_14[0x4]; /* 0xE58 [rw] low */
    uint8_t dmg_ctrl_15[0x4]; /* 0xE5C [w] high */
    uint8_t dmg_ctrl_16[0x4]; /* 0xE60 [w] low */
    uint8_t dmg_ctrl_17[0x4]; /* 0xE64 [w] high */
    uint8_t dmg_ctrl_18[0x4]; /* 0xE68 [w] high */
    uint8_t action_state_14[0x4]; /* 0xE6C [rw] high */
    uint8_t action_state_15[0x8]; /* 0xE70 [w] low */
    uint8_t unk_e78[0x4]; /* 0xE78 [w] high */
    uint8_t unk_e7c[0x4]; /* 0xE7C [w] high */
    uint8_t unk_e80[0x4]; /* 0xE80 [r] low */
    uint8_t pad_e84[0x2C]; /* 0xE84 - 0xEB0 */
    uint8_t unk_eb0[0x4]; /* 0xEB0 [r] low */
    uint8_t pad_eb4[0x1A4]; /* 0xEB4 - 0x1058 */
    uint8_t unk_1058[0x4]; /* 0x1058 [r] low */
    uint8_t pad_105c[0x1B24]; /* 0x105C - 0x2B80 */
    uint8_t anim_state_16[0x4]; /* 0x2B80 [r] low */
    uint8_t pad_2b84[0x3C]; /* 0x2B84 - 0x2BC0 */
    uint8_t anim_state_17[0x4]; /* 0x2BC0 [r] low */
    uint8_t pad_2bc4[0x3C]; /* 0x2BC4 - 0x2C00 */
    uint8_t anim_state_18[0x4]; /* 0x2C00 [r] low */
    uint8_t pad_2c04[0xFC]; /* 0x2C04 - 0x2D00 */
    uint8_t anim_state_19[0x4]; /* 0x2D00 [r] low */
    uint8_t pad_2d04[0x2FC]; /* 0x2D04 - 0x3000 */
    uint8_t unk_3000[0x4]; /* 0x3000 [r] low */
    uint8_t pad_3004[0x1FC]; /* 0x3004 - 0x3200 */
    uint8_t dmg_ctrl_19[0x4]; /* 0x3200 [r] low */
    uint8_t pad_3204[0x1FC]; /* 0x3204 - 0x3400 */
    uint8_t chakra_ctrl_7[0x4]; /* 0x3400 [r] low */
    uint8_t pad_3404[0x3C]; /* 0x3404 - 0x3440 */
    uint8_t anim_state_20[0x4]; /* 0x3440 [r] low */
    uint8_t pad_3444[0x7C]; /* 0x3444 - 0x34C0 */
    uint8_t action_state_16[0x4]; /* 0x34C0 [r] low */
    uint8_t pad_34c4[0x3C]; /* 0x34C4 - 0x3500 */
    uint8_t action_state_17[0x4]; /* 0x3500 [r] low */
    uint8_t pad_3504[0x33C]; /* 0x3504 - 0x3840 */
    uint8_t unk_3840[0x4]; /* 0x3840 [r] low */
    uint8_t pad_3844[0x3C]; /* 0x3844 - 0x3880 */
    uint8_t unk_3880[0x4]; /* 0x3880 [r] low */
    uint8_t pad_3884[0xBC]; /* 0x3884 - 0x3940 */
    uint8_t atk_ctrl_9[0x4]; /* 0x3940 [r] low */
    uint8_t pad_3944[0x3C]; /* 0x3944 - 0x3980 */
    uint8_t atk_ctrl_10[0x4]; /* 0x3980 [r] low */
    uint8_t pad_3984[0x3C]; /* 0x3984 - 0x39C0 */
    uint8_t dmg_ctrl_20[0x4]; /* 0x39C0 [r] low */
    uint8_t pad_39c4[0x3C]; /* 0x39C4 - 0x3A00 */
    uint8_t unk_3a00[0x4]; /* 0x3A00 [r] low */
    uint8_t pad_3a04[0x3C]; /* 0x3A04 - 0x3A40 */
    uint8_t dmg_ctrl_21[0x4]; /* 0x3A40 [r] low */
    uint8_t pad_3a44[0x3C]; /* 0x3A44 - 0x3A80 */
    uint8_t dmg_ctrl_22[0x4]; /* 0x3A80 [r] low */
    uint8_t pad_3a84[0x3C]; /* 0x3A84 - 0x3AC0 */
    uint8_t dmg_ctrl_23[0x4]; /* 0x3AC0 [r] low */
    uint8_t pad_3ac4[0x7C]; /* 0x3AC4 - 0x3B40 */
    uint8_t guard_ctrl_2[0x4]; /* 0x3B40 [r] low */
    uint8_t pad_3b44[0x7C]; /* 0x3B44 - 0x3BC0 */
    uint8_t action_state_18[0x4]; /* 0x3BC0 [r] low */
    uint8_t pad_3bc4[0x3C]; /* 0x3BC4 - 0x3C00 */
    uint8_t unk_3c00[0x4]; /* 0x3C00 [r] low */
    uint8_t pad_3c04[0x7C]; /* 0x3C04 - 0x3C80 */
    uint8_t action_state_19[0x4]; /* 0x3C80 [r] low */
    uint8_t pad_3c84[0x3C]; /* 0x3C84 - 0x3CC0 */
    uint8_t action_state_20[0x4]; /* 0x3CC0 [r] low */
    uint8_t pad_3cc4[0x7C]; /* 0x3CC4 - 0x3D40 */
    uint8_t dmg_ctrl_24[0x4]; /* 0x3D40 [r] low */
    uint8_t pad_3d44[0x3C]; /* 0x3D44 - 0x3D80 */
    uint8_t action_state_21[0x4]; /* 0x3D80 [r] low */
    uint8_t pad_3d84[0x7C]; /* 0x3D84 - 0x3E00 */
    uint8_t dmg_ctrl_25[0x4]; /* 0x3E00 [r] low */
    uint8_t pad_3e04[0x1BC]; /* 0x3E04 - 0x3FC0 */
    uint8_t unk_3fc0[0x4]; /* 0x3FC0 [r] low */
    uint8_t pad_3fc4[0x7C]; /* 0x3FC4 - 0x4040 */
    uint8_t unk_4040[0x4]; /* 0x4040 [r] low */
    uint8_t pad_4044[0x3C]; /* 0x4044 - 0x4080 */
    uint8_t unk_4080[0x4]; /* 0x4080 [r] low */
    uint8_t pad_4084[0x1FC]; /* 0x4084 - 0x4280 */
    uint8_t unk_4280[0x4]; /* 0x4280 [r] low */
    uint8_t pad_4284[0x7C]; /* 0x4284 - 0x4300 */
    uint8_t unk_4300[0x4]; /* 0x4300 [r] low */
    uint8_t pad_4304[0x17C]; /* 0x4304 - 0x4480 */
    uint8_t anim_state_21[0x4]; /* 0x4480 [r] low */
    uint8_t pad_4484[0x3C]; /* 0x4484 - 0x44C0 */
    uint8_t anim_state_22[0x4]; /* 0x44C0 [r] low */
    uint8_t pad_44c4[0x1BC]; /* 0x44C4 - 0x4680 */
    uint8_t guard_ctrl_3[0x4]; /* 0x4680 [r] low */
    uint8_t pad_4684[0x3C]; /* 0x4684 - 0x46C0 */
    uint8_t atk_ctrl_11[0x4]; /* 0x46C0 [r] low */
    uint8_t pad_46c4[0x3C]; /* 0x46C4 - 0x4700 */
    uint8_t unk_4700[0x4]; /* 0x4700 [r] low */
    uint8_t pad_4704[0x7C]; /* 0x4704 - 0x4780 */
    uint8_t action_state_22[0x4]; /* 0x4780 [r] low */
    uint8_t pad_4784[0x27C]; /* 0x4784 - 0x4A00 */
    uint8_t unk_4a00[0x4]; /* 0x4A00 [r] low */
    uint8_t pad_4a04[0x7C]; /* 0x4A04 - 0x4A80 */
    uint8_t dmg_ctrl_26[0x4]; /* 0x4A80 [r] low */
    uint8_t pad_4a84[0x3C]; /* 0x4A84 - 0x4AC0 */
    uint8_t dmg_ctrl_27[0x4]; /* 0x4AC0 [r] low */
    uint8_t pad_4ac4[0x3C]; /* 0x4AC4 - 0x4B00 */
    uint8_t unk_4b00[0x4]; /* 0x4B00 [r] low */
    uint8_t pad_4b04[0x13C]; /* 0x4B04 - 0x4C40 */
    uint8_t guard_ctrl_4[0x4]; /* 0x4C40 [r] low */
    uint8_t pad_4c44[0x3C]; /* 0x4C44 - 0x4C80 */
    uint8_t dmg_ctrl_28[0x4]; /* 0x4C80 [r] low */
    uint8_t pad_4c84[0xBC]; /* 0x4C84 - 0x4D40 */
    uint8_t unk_4d40[0x4]; /* 0x4D40 [r] low */
    uint8_t pad_4d44[0x7C]; /* 0x4D44 - 0x4DC0 */
    uint8_t unk_4dc0[0x4]; /* 0x4DC0 [r] low */
    uint8_t pad_4dc4[0x3C]; /* 0x4DC4 - 0x4E00 */
    uint8_t unk_4e00[0x4]; /* 0x4E00 [r] low */
    uint8_t pad_4e04[0x3C]; /* 0x4E04 - 0x4E40 */
    uint8_t chakra_ctrl_8[0x4]; /* 0x4E40 [r] low */
    uint8_t pad_4e44[0x3C]; /* 0x4E44 - 0x4E80 */
    uint8_t unk_4e80[0x4]; /* 0x4E80 [r] low */
    uint8_t pad_4e84[0x3C]; /* 0x4E84 - 0x4EC0 */
    uint8_t unk_4ec0[0x4]; /* 0x4EC0 [r] low */
    uint8_t pad_4ec4[0x7C]; /* 0x4EC4 - 0x4F40 */
    uint8_t unk_4f40[0x4]; /* 0x4F40 [r] low */
    uint8_t pad_4f44[0x23C]; /* 0x4F44 - 0x5180 */
    uint8_t unk_5180[0x4]; /* 0x5180 [r] low */
    uint8_t pad_5184[0xFC]; /* 0x5184 - 0x5280 */
    uint8_t unk_5280[0x4]; /* 0x5280 [r] low */
    uint8_t pad_5284[0xFC]; /* 0x5284 - 0x5380 */
    uint8_t unk_5380[0x4]; /* 0x5380 [r] low */
    uint8_t pad_5384[0x13C]; /* 0x5384 - 0x54C0 */
    uint8_t unk_54c0[0x4]; /* 0x54C0 [r] low */
    uint8_t pad_54c4[0x7C]; /* 0x54C4 - 0x5540 */
    uint8_t atk_ctrl_12[0x4]; /* 0x5540 [r] low */
    uint8_t pad_5544[0x3C]; /* 0x5544 - 0x5580 */
    uint8_t atk_ctrl_13[0x4]; /* 0x5580 [r] low */
    uint8_t pad_5584[0x3C]; /* 0x5584 - 0x55C0 */
    uint8_t atk_ctrl_14[0x4]; /* 0x55C0 [r] low */
    uint8_t pad_55c4[0x3C]; /* 0x55C4 - 0x5600 */
    uint8_t atk_ctrl_15[0x4]; /* 0x5600 [r] low */
    uint8_t pad_5604[0x27C]; /* 0x5604 - 0x5880 */
    uint8_t action_state_23[0x4]; /* 0x5880 [r] low */
    uint8_t pad_5884[0x27C]; /* 0x5884 - 0x5B00 */
    uint8_t unk_5b00[0x4]; /* 0x5B00 [r] low */
    uint8_t pad_5b04[0xFC]; /* 0x5B04 - 0x5C00 */
    uint8_t unk_5c00[0x4]; /* 0x5C00 [r] low */
    uint8_t pad_5c04[0x3C]; /* 0x5C04 - 0x5C40 */
    uint8_t dmg_ctrl_29[0x4]; /* 0x5C40 [r] low */
    uint8_t pad_5c44[0xBC]; /* 0x5C44 - 0x5D00 */
    uint8_t dmg_ctrl_30[0x4]; /* 0x5D00 [r] low */
    uint8_t pad_5d04[0x3C]; /* 0x5D04 - 0x5D40 */
    uint8_t dmg_ctrl_31[0x4]; /* 0x5D40 [r] low */
    uint8_t pad_5d44[0x3C]; /* 0x5D44 - 0x5D80 */
    uint8_t dmg_ctrl_32[0x4]; /* 0x5D80 [r] low */
    uint8_t pad_5d84[0x7C]; /* 0x5D84 - 0x5E00 */
    uint8_t unk_5e00[0x4]; /* 0x5E00 [r] low */
    uint8_t pad_5e04[0xFC]; /* 0x5E04 - 0x5F00 */
    uint8_t unk_5f00[0x4]; /* 0x5F00 [r] low */
    uint8_t pad_5f04[0x7C]; /* 0x5F04 - 0x5F80 */
    uint8_t unk_5f80[0x4]; /* 0x5F80 [r] low */
    uint8_t pad_5f84[0x3C]; /* 0x5F84 - 0x5FC0 */
    uint8_t unk_5fc0[0x4]; /* 0x5FC0 [r] low */
    uint8_t pad_5fc4[0x3C]; /* 0x5FC4 - 0x6000 */
    uint8_t unk_6000[0x4]; /* 0x6000 [r] low */
    uint8_t pad_6004[0x17C]; /* 0x6004 - 0x6180 */
    uint8_t dmg_ctrl_33[0x4]; /* 0x6180 [r] low */
    uint8_t pad_6184[0x3C]; /* 0x6184 - 0x61C0 */
    uint8_t unk_61c0[0x4]; /* 0x61C0 [r] low */
    uint8_t pad_61c4[0x3C]; /* 0x61C4 - 0x6200 */
    uint8_t unk_6200[0x4]; /* 0x6200 [r] low */
    uint8_t pad_6204[0x3C]; /* 0x6204 - 0x6240 */
    uint8_t unk_6240[0x4]; /* 0x6240 [r] low */
    uint8_t pad_6244[0x3C]; /* 0x6244 - 0x6280 */
    uint8_t unk_6280[0x4]; /* 0x6280 [r] low */
    uint8_t pad_6284[0xBC]; /* 0x6284 - 0x6340 */
    uint8_t unk_6340[0x4]; /* 0x6340 [r] low */
    uint8_t pad_6344[0x6FC]; /* 0x6344 - 0x6A40 */
    uint8_t atk_ctrl_16[0x4]; /* 0x6A40 [r] low */
    uint8_t pad_6a44[0x126C]; /* 0x6A44 - 0x7CB0 */
    uint8_t unk_7cb0[0x8]; /* 0x7CB0 [r] medium */
    uint8_t unk_7cb8[0x8]; /* 0x7CB8 [r] medium */
    uint8_t pad_7cc0[0x20]; /* 0x7CC0 - 0x7CE0 */
    uint8_t unk_7ce0[0x4]; /* 0x7CE0 [r] low */
    uint8_t pad_7ce4[0x94]; /* 0x7CE4 - 0x7D78 */
    uint8_t unk_7d78[0x4]; /* 0x7D78 [r] low */
    uint8_t pad_7d7c[0x94]; /* 0x7D7C - 0x7E10 */
    uint8_t unk_7e10[0x4]; /* 0x7E10 [rw] high */
    uint8_t pad_7e14[0x3C]; /* 0x7E14 - 0x7E50 */
    uint8_t unk_7e50[0x4]; /* 0x7E50 [r] low */
    uint8_t pad_7e54[0x94]; /* 0x7E54 - 0x7EE8 */
    uint8_t unk_7ee8[0x4]; /* 0x7EE8 [rw] high */
    uint8_t pad_7eec[0x4]; /* 0x7EEC - 0x7EF0 */
    uint8_t unk_7ef0[0x4]; /* 0x7EF0 [r] low */
    uint8_t pad_7ef4[0x94]; /* 0x7EF4 - 0x7F88 */
    uint8_t unk_7f88[0x8]; /* 0x7F88 [r] medium */
    uint8_t pad_7f90[0x20]; /* 0x7F90 - 0x7FB0 */
    uint8_t unk_7fb0[0x4]; /* 0x7FB0 [r] medium */
    uint8_t unk_7fb4[0x4]; /* 0x7FB4 [r] medium */
    uint8_t unk_7fb8[0x8]; /* 0x7FB8 [r] medium */
    uint8_t unk_7fc0[0x8]; /* 0x7FC0 [r] medium */
    uint8_t unk_7fc8[0x4]; /* 0x7FC8 [rw] high */
    uint8_t pad_7fcc[0x4]; /* 0x7FCC - 0x7FD0 */
    uint8_t unk_7fd0[0x8]; /* 0x7FD0 [r] low */
    uint8_t unk_7fd8[0x8]; /* 0x7FD8 [r] medium */
    uint8_t guard_ctrl_5[0x8]; /* 0x7FE0 [r] low */
    uint8_t unk_7fe8[0x4]; /* 0x7FE8 [rw] medium */
    uint8_t dmg_ctrl_34[0x4]; /* 0x7FEC [w] medium */
    uint8_t pad_7ff0[0x4]; /* 0x7FF0 - 0x7FF4 */
    uint8_t throw_ctrl_1[0x8]; /* 0x7FF4 [rw] low */
    uint8_t throw_ctrl_2[0x4]; /* 0x7FFC [rw] high */
    uint8_t unk_8000[0x4]; /* 0x8000 [rw] medium */
    uint8_t pad_8004[0x34]; /* 0x8004 - 0x8038 */
    uint8_t dmg_ctrl_35[0x4]; /* 0x8038 [r] low */
    uint8_t pad_803c[0xC]; /* 0x803C - 0x8048 */
    uint8_t dmg_ctrl_36[0x4]; /* 0x8048 [r] medium */
    uint8_t dmg_ctrl_37[0x4]; /* 0x804C [r] medium */
    uint8_t dmg_ctrl_38[0x4]; /* 0x8050 [r] medium */
    uint8_t dmg_ctrl_39[0x4]; /* 0x8054 [r] medium */
    uint8_t pad_8058[0x8]; /* 0x8058 - 0x8060 */
    uint8_t dmg_ctrl_40[0x8]; /* 0x8060 [rw] low */
    uint8_t dmg_ctrl_41[0x4]; /* 0x8068 [w] high */
    uint8_t pad_806c[0x34]; /* 0x806C - 0x80A0 */
    uint8_t dmg_ctrl_42[0x8]; /* 0x80A0 [r] medium */
    uint8_t pad_80a8[0x8]; /* 0x80A8 - 0x80B0 */
    uint8_t dmg_ctrl_43[0x4]; /* 0x80B0 [r] medium */
    uint8_t dmg_ctrl_44[0x4]; /* 0x80B4 [rw] high */
    uint8_t dmg_ctrl_45[0x4]; /* 0x80B8 [rw] high */
    uint8_t pad_80bc[0x2C]; /* 0x80BC - 0x80E8 */
    uint8_t dmg_ctrl_46[0x4]; /* 0x80E8 [r] medium */
    uint8_t dmg_ctrl_47[0x4]; /* 0x80EC [r] medium */
    uint8_t pad_80f0[0x70]; /* 0x80F0 - 0x8160 */
    uint8_t action_state_24[0x4]; /* 0x8160 [w] medium */
    uint8_t action_state_25[0x4]; /* 0x8164 [rw] high */
    uint8_t dmg_ctrl_48[0x4]; /* 0x8168 [rw] high */
    uint8_t unk_816c[0x4]; /* 0x816C [r] medium */
    uint8_t pad_8170[0x4]; /* 0x8170 - 0x8174 */
    uint8_t anim_state_23[0x4]; /* 0x8174 [r] medium */
    uint8_t action_state_26[0x4]; /* 0x8178 [w] medium */
    uint8_t action_state_27[0x4]; /* 0x817C [w] high */
    uint8_t action_state_28[0x4]; /* 0x8180 [w] medium */
    uint8_t pad_8184[0x4]; /* 0x8184 - 0x8188 */
    uint8_t anim_state_24[0x4]; /* 0x8188 [r] low */
    uint8_t pad_818c[0xC]; /* 0x818C - 0x8198 */
    uint8_t anim_state_25[0x8]; /* 0x8198 [rw] high */
    uint8_t anim_state_26[0x8]; /* 0x81A0 [r] medium */
    uint8_t pad_81a8[0x18]; /* 0x81A8 - 0x81C0 */
    uint8_t unk_81c0[0x4]; /* 0x81C0 [r] medium */
    uint8_t unk_81c4[0x4]; /* 0x81C4 [rw] high */
    uint8_t unk_81c8[0x4]; /* 0x81C8 [r] medium */
    uint8_t unk_81cc[0x4]; /* 0x81CC [rw] medium */
    uint8_t unk_81d0[0x4]; /* 0x81D0 [r] medium */
    uint8_t unk_81d4[0x8]; /* 0x81D4 [w] medium */
    uint8_t action_state_29[0x4]; /* 0x81DC [rw] low */
    uint8_t pad_81e0[0x10]; /* 0x81E0 - 0x81F0 */
    uint8_t anim_state_27[0x8]; /* 0x81F0 [r] low */
    uint8_t unk_81f8[0x4]; /* 0x81F8 [w] low */
    uint8_t unk_81fc[0x4]; /* 0x81FC [w] medium */
    uint8_t unk_8200[0x4]; /* 0x8200 [w] low */
    uint8_t unk_8204[0x4]; /* 0x8204 [w] medium */
    uint8_t action_state_30[0x4]; /* 0x8208 [rw] high */
    uint8_t pad_820c[0xC]; /* 0x820C - 0x8218 */
    uint8_t unk_8218[0x4]; /* 0x8218 [w] medium */
    uint8_t unk_821c[0x4]; /* 0x821C [r] low */
    uint8_t pad_8220[0x8]; /* 0x8220 - 0x8228 */
    uint8_t unk_8228[0x4]; /* 0x8228 [r] low */
    uint8_t pad_822c[0x160]; /* 0x822C - 0x838C */
    uint8_t unk_838c[0x4]; /* 0x838C [r] medium */
    uint8_t pad_8390[0x1C]; /* 0x8390 - 0x83AC */
    uint8_t chakra_ctrl_9[0x4]; /* 0x83AC [r] medium */
    uint8_t pad_83b0[0x1D48]; /* 0x83B0 - 0xA0F8 */
    uint8_t chakra_ctrl_10[0x8]; /* 0xA0F8 [r] medium */
    uint8_t pad_a100[0x8]; /* 0xA100 - 0xA108 */
    uint8_t action_state_31[0x4]; /* 0xA108 [w] medium */
    uint8_t pad_a10c[0x10]; /* 0xA10C - 0xA11C */
    uint8_t unk_a11c[0x4]; /* 0xA11C [rw] medium */
    uint8_t unk_a120[0x4]; /* 0xA120 [rw] medium */
    uint8_t unk_a124[0x4]; /* 0xA124 [r] medium */
    uint8_t unk_a128[0x4]; /* 0xA128 [rw] high */
    uint8_t unk_a12c[0x4]; /* 0xA12C [rw] medium */
    uint8_t unk_a130[0x4]; /* 0xA130 [rw] medium */
    uint8_t unk_a134[0x4]; /* 0xA134 [r] medium */
    uint8_t dmg_ctrl_49[0x4]; /* 0xA138 [rw] medium */
    uint8_t dmg_ctrl_50[0x2]; /* 0xA13C [rw] medium */
    uint8_t pad_a13e[0x2]; /* 0xA13E - 0xA140 */
    uint8_t unk_a140[0x4]; /* 0xA140 [rw] medium */
    uint8_t unk_a144[0x4]; /* 0xA144 [rw] medium */
    uint8_t unk_a148[0x4]; /* 0xA148 [r] medium */
    uint8_t unk_a14c[0x4]; /* 0xA14C [w] medium */
    uint8_t pad_a150[0x4]; /* 0xA150 - 0xA154 */
    uint8_t unk_a154[0x4]; /* 0xA154 [rw] medium */
    uint8_t unk_a158[0x4]; /* 0xA158 [w] high */
    uint8_t pad_a15c[0xC]; /* 0xA15C - 0xA168 */
    uint8_t unk_a168[0x4]; /* 0xA168 [rw] medium */
    uint8_t unk_a16c[0x4]; /* 0xA16C [r] medium */
    uint8_t atk_ctrl_17[0x4]; /* 0xA170 [rw] high */
    uint8_t unk_a174[0x4]; /* 0xA174 [r] medium */
    uint8_t unk_a178[0x4]; /* 0xA178 [r] medium */
    uint8_t atk_ctrl_18[0x4]; /* 0xA17C [rw] high */
    uint8_t unk_a180[0x8]; /* 0xA180 [rw] low */
    uint8_t unk_a188[0x8]; /* 0xA188 [w] medium */
    uint8_t unk_a190[0x8]; /* 0xA190 [w] medium */
    uint8_t unk_a198[0x8]; /* 0xA198 [w] medium */
    uint8_t unk_a1a0[0x8]; /* 0xA1A0 [w] medium */
    uint8_t unk_a1a8[0x8]; /* 0xA1A8 [w] medium */
    uint8_t unk_a1b0[0x8]; /* 0xA1B0 [w] medium */
    uint8_t unk_a1b8[0x8]; /* 0xA1B8 [w] medium */
    uint8_t atk_ctrl_19[0x2]; /* 0xA1C0 [rw] high */
    uint8_t unk_a1c2[0x2]; /* 0xA1C2 [r] medium */
    uint8_t unk_a1c4[0x4]; /* 0xA1C4 [rw] high */
    uint8_t unk_a1c8[0x4]; /* 0xA1C8 [w] medium */
    uint8_t unk_a1cc[0x4]; /* 0xA1CC [rw] high */
    uint8_t unk_a1d0[0x4]; /* 0xA1D0 [rw] high */
    uint8_t unk_a1d4[0x2]; /* 0xA1D4 [w] medium */
    uint8_t unk_a1d6[0x2]; /* 0xA1D6 [r] medium */
    uint8_t unk_a1d8[0x4]; /* 0xA1D8 [w] medium */
    uint8_t unk_a1dc[0x4]; /* 0xA1DC [rw] high */
    uint8_t unk_a1e0[0x4]; /* 0xA1E0 [rw] high */
    uint8_t pad_a1e4[0x4]; /* 0xA1E4 - 0xA1E8 */
    uint8_t unk_a1e8[0x8]; /* 0xA1E8 [w] medium */
    uint8_t pad_a1f0[0xC]; /* 0xA1F0 - 0xA1FC */
    uint8_t unk_a1fc[0x4]; /* 0xA1FC [w] medium */
    uint8_t action_state_32[0x4]; /* 0xA200 [w] medium */
    uint8_t action_state_33[0x4]; /* 0xA204 [rw] high */
    uint8_t atk_ctrl_20[0x4]; /* 0xA208 [rw] low */
    uint8_t atk_ctrl_21[0x4]; /* 0xA20C [rw] low */
    uint8_t atk_ctrl_22[0x4]; /* 0xA210 [w] high */
    uint8_t atk_ctrl_23[0x4]; /* 0xA214 [rw] high */
    uint8_t atk_ctrl_24[0x4]; /* 0xA218 [w] high */
    uint8_t action_state_34[0x4]; /* 0xA21C [w] medium */
    uint8_t pad_a220[0x8]; /* 0xA220 - 0xA228 */
    uint8_t action_state_35[0x4]; /* 0xA228 [r] low */
    uint8_t pad_a22c[0x34]; /* 0xA22C - 0xA260 */
    uint8_t action_state_36[0x4]; /* 0xA260 [rw] high */
    uint8_t unk_a264[0x4]; /* 0xA264 [r] medium */
    uint8_t pad_a268[0x4]; /* 0xA268 - 0xA26C */
    uint8_t unk_a26c[0x4]; /* 0xA26C [r] low */
    uint8_t pad_a270[0x8]; /* 0xA270 - 0xA278 */
    uint8_t unk_a278[0x4]; /* 0xA278 [w] high */
    uint8_t unk_a27c[0x4]; /* 0xA27C [w] medium */
    uint8_t pad_a280[0xC]; /* 0xA280 - 0xA28C */
    uint8_t unk_a28c[0x4]; /* 0xA28C [r] medium */
    uint8_t unk_a290[0x4]; /* 0xA290 [rw] high */
    uint8_t pad_a294[0x8]; /* 0xA294 - 0xA29C */
    uint8_t unk_a29c[0x4]; /* 0xA29C [r] medium */
    uint8_t atk_ctrl_25[0x4]; /* 0xA2A0 [w] high */
    uint8_t atk_ctrl_26[0x4]; /* 0xA2A4 [w] high */
    uint8_t action_state_37[0x4]; /* 0xA2A8 [w] high */
    uint8_t unk_a2ac[0x4]; /* 0xA2AC [r] medium */
    uint8_t unk_a2b0[0x4]; /* 0xA2B0 [r] low */
    uint8_t pad_a2b4[0x2C]; /* 0xA2B4 - 0xA2E0 */
    uint8_t unk_a2e0[0x4]; /* 0xA2E0 [rw] high */
    uint8_t unk_a2e4[0x8]; /* 0xA2E4 [rw] low */
    uint8_t unk_a2ec[0x4]; /* 0xA2EC [w] medium */
    uint8_t unk_a2f0[0x4]; /* 0xA2F0 [rw] high */
    uint8_t unk_a2f4[0x8]; /* 0xA2F4 [rw] low */
    uint8_t unk_a2fc[0x4]; /* 0xA2FC [w] medium */
    uint8_t unk_a300[0x4]; /* 0xA300 [rw] high */
    uint8_t unk_a304[0x4]; /* 0xA304 [rw] high */
    uint8_t unk_a308[0x4]; /* 0xA308 [rw] high */
    uint8_t unk_a30c[0x4]; /* 0xA30C [rw] high */
    uint8_t unk_a310[0x4]; /* 0xA310 [w] high */
    uint8_t anim_state_28[0x4]; /* 0xA314 [rw] high */
    uint8_t pad_a318[0xC]; /* 0xA318 - 0xA324 */
    uint8_t chakra_ctrl_11[0x4]; /* 0xA324 [r] low */
    uint8_t pad_a328[0x10]; /* 0xA328 - 0xA338 */
    uint8_t unk_a338[0x4]; /* 0xA338 [rw] medium */
    uint8_t pad_a33c[0x784]; /* 0xA33C - 0xAAC0 */
    uint8_t unk_aac0[0x4]; /* 0xAAC0 [r] low */
    uint8_t pad_aac4[0x2C]; /* 0xAAC4 - 0xAAF0 */
    uint8_t guard_ctrl_6[0x8]; /* 0xAAF0 [rw] high */
    uint8_t pad_aaf8[0xC]; /* 0xAAF8 - 0xAB04 */
    uint8_t unk_ab04[0x4]; /* 0xAB04 [w] medium */
    uint8_t atk_ctrl_27[0x4]; /* 0xAB08 [rw] high */
    uint8_t pad_ab0c[0x4]; /* 0xAB0C - 0xAB10 */
    uint8_t unk_ab10[0x4]; /* 0xAB10 [rw] high */
    uint8_t unk_ab14[0x8]; /* 0xAB14 [w] medium */
    uint8_t pad_ab1c[0xC]; /* 0xAB1C - 0xAB28 */
    uint8_t unk_ab28[0x4]; /* 0xAB28 [r] medium */
    uint8_t unk_ab2c[0x4]; /* 0xAB2C [r] medium */
    uint8_t pad_ab30[0x40]; /* 0xAB30 - 0xAB70 */
    uint8_t unk_ab70[0x4]; /* 0xAB70 [r] medium */
    uint8_t chakra_ctrl_12[0x4]; /* 0xAB74 [rw] high */
    uint8_t chakra_ctrl_13[0x4]; /* 0xAB78 [r] medium */
    uint8_t chakra_ctrl_14[0x4]; /* 0xAB7C [rw] low */
    uint8_t chakra_ctrl_15[0x4]; /* 0xAB80 [w] medium */
    uint8_t guard_ctrl_7[0x4]; /* 0xAB84 [rw] medium */
    uint8_t guard_ctrl_8[0x4]; /* 0xAB88 [rw] high */
    uint8_t unk_ab8c[0x4]; /* 0xAB8C [rw] high */
    uint8_t unk_ab90[0x4]; /* 0xAB90 [rw] high */
    uint8_t unk_ab94[0x4]; /* 0xAB94 [rw] high */
    uint8_t pad_ab98[0x4]; /* 0xAB98 - 0xAB9C */
    uint8_t unk_ab9c[0x4]; /* 0xAB9C [rw] high */
    uint8_t unk_aba0[0x4]; /* 0xABA0 [rw] medium */
    uint8_t unk_aba4[0x4]; /* 0xABA4 [r] medium */
    uint8_t chakra_ctrl_16[0x4]; /* 0xABA8 [w] high */
    uint8_t pad_abac[0x4]; /* 0xABAC - 0xABB0 */
    uint8_t unk_abb0[0x8]; /* 0xABB0 [r] medium */
    uint8_t pad_abb8[0x20]; /* 0xABB8 - 0xABD8 */
    uint8_t anim_state_29[0x8]; /* 0xABD8 [r] medium */
    uint8_t anim_state_30[0x8]; /* 0xABE0 [r] medium */
    uint8_t pad_abe8[0x8]; /* 0xABE8 - 0xABF0 */
    uint8_t unk_abf0[0x4]; /* 0xABF0 [w] medium */
    uint8_t action_state_38[0x4]; /* 0xABF4 [rw] high */
    uint8_t action_state_39[0x4]; /* 0xABF8 [w] high */
    uint8_t pad_abfc[0x44]; /* 0xABFC - 0xAC40 */
    uint8_t action_state_40[0x8]; /* 0xAC40 [rw] high */
    uint8_t unk_ac48[0x4]; /* 0xAC48 [r] low */
    uint8_t anim_state_31[0x8]; /* 0xAC4C [rw] high */
    uint8_t anim_state_32[0x4]; /* 0xAC54 [rw] high */
    uint8_t action_state_41[0x4]; /* 0xAC58 [w] medium */
    uint8_t pad_ac5c[0x4]; /* 0xAC5C - 0xAC60 */
    uint8_t unk_ac60[0x4]; /* 0xAC60 [r] low */
    uint8_t pad_final[0x354]; /* 0xAC64 - 0xAFB8 */
} ccPlayer_t;

static_assert(sizeof(ccPlayer_t) == 0xAFB8, "ccPlayer size must be 0xAFB8");

/* Offset assertions for named fields */
static_assert(offsetof(ccPlayer_t, vtable) == 0x0, "vtable offset");
static_assert(offsetof(ccPlayer_t, pad_state_base) == 0x40, "pad_state_base offset");
static_assert(offsetof(ccPlayer_t, anim_state) == 0x70, "anim_state offset");
static_assert(offsetof(ccPlayer_t, anim_state_1) == 0x90, "anim_state_1 offset");
static_assert(offsetof(ccPlayer_t, anim_state_2) == 0x9C, "anim_state_2 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos) == 0xA4, "combo_throw_pos offset");
static_assert(offsetof(ccPlayer_t, anim_state_3) == 0xA8, "anim_state_3 offset");
static_assert(offsetof(ccPlayer_t, throw_ctrl) == 0xB0, "throw_ctrl offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl) == 0xB4, "atk_ctrl offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl) == 0xC0, "chakra_ctrl offset");
static_assert(offsetof(ccPlayer_t, anim_state_4) == 0x108, "anim_state_4 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_1) == 0x150, "chakra_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_1) == 0x154, "atk_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_2) == 0x158, "atk_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_3) == 0x15C, "atk_ctrl_3 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_2) == 0x160, "chakra_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, action_state) == 0x164, "action_state offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl) == 0x16C, "dmg_ctrl offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_1) == 0x1A0, "combo_throw_pos_1 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_2) == 0x1A8, "combo_throw_pos_2 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_3) == 0x1AC, "combo_throw_pos_3 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_4) == 0x1B4, "combo_throw_pos_4 offset");
static_assert(offsetof(ccPlayer_t, action_state_1) == 0x200, "action_state_1 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_4) == 0x210, "atk_ctrl_4 offset");
static_assert(offsetof(ccPlayer_t, pad_input) == 0x218, "pad_input offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_3) == 0x280, "chakra_ctrl_3 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_4) == 0x2C0, "chakra_ctrl_4 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_5) == 0x380, "chakra_ctrl_5 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl) == 0x4C0, "guard_ctrl offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_5) == 0x624, "atk_ctrl_5 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_1) == 0x62C, "dmg_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_6) == 0x630, "atk_ctrl_6 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_6) == 0x700, "chakra_ctrl_6 offset");
static_assert(offsetof(ccPlayer_t, anim_state_5) == 0x9A8, "anim_state_5 offset");
static_assert(offsetof(ccPlayer_t, action_state_2) == 0x9B4, "action_state_2 offset");
static_assert(offsetof(ccPlayer_t, anim_state_6) == 0x9BC, "anim_state_6 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_1) == 0x9C8, "guard_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_2) == 0x9D8, "dmg_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, action_state_3) == 0x9E0, "action_state_3 offset");
static_assert(offsetof(ccPlayer_t, anim_state_7) == 0x9E8, "anim_state_7 offset");
static_assert(offsetof(ccPlayer_t, action_state_4) == 0x9EC, "action_state_4 offset");
static_assert(offsetof(ccPlayer_t, action_state_5) == 0x9F0, "action_state_5 offset");
static_assert(offsetof(ccPlayer_t, action_state_6) == 0x9F4, "action_state_6 offset");
static_assert(offsetof(ccPlayer_t, action_state_7) == 0x9F8, "action_state_7 offset");
static_assert(offsetof(ccPlayer_t, action_state_8) == 0x9FC, "action_state_8 offset");
static_assert(offsetof(ccPlayer_t, action_state_9) == 0xA00, "action_state_9 offset");
static_assert(offsetof(ccPlayer_t, action_state_10) == 0xA04, "action_state_10 offset");
static_assert(offsetof(ccPlayer_t, action_state_11) == 0xA0C, "action_state_11 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_7) == 0xA14, "atk_ctrl_7 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_3) == 0xA44, "dmg_ctrl_3 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_4) == 0xA48, "dmg_ctrl_4 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_5) == 0xA4C, "dmg_ctrl_5 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_6) == 0xA50, "dmg_ctrl_6 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_7) == 0xA54, "dmg_ctrl_7 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_8) == 0xA58, "dmg_ctrl_8 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_9) == 0xA5C, "dmg_ctrl_9 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_10) == 0xA60, "dmg_ctrl_10 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_11) == 0xA64, "dmg_ctrl_11 offset");
static_assert(offsetof(ccPlayer_t, anim_state_8) == 0xA98, "anim_state_8 offset");
static_assert(offsetof(ccPlayer_t, char_id) == 0xC8C, "char_id offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_8) == 0xCA8, "atk_ctrl_8 offset");
static_assert(offsetof(ccPlayer_t, current_action) == 0xCC0, "current_action offset");
static_assert(offsetof(ccPlayer_t, previous_action) == 0xCC4, "previous_action offset");
static_assert(offsetof(ccPlayer_t, action_state_12) == 0xCD0, "action_state_12 offset");
static_assert(offsetof(ccPlayer_t, anim_state_9) == 0xCD4, "anim_state_9 offset");
static_assert(offsetof(ccPlayer_t, anim_state_10) == 0xCD8, "anim_state_10 offset");
static_assert(offsetof(ccPlayer_t, anim_state_11) == 0xCDC, "anim_state_11 offset");
static_assert(offsetof(ccPlayer_t, anim_state_12) == 0xCE0, "anim_state_12 offset");
static_assert(offsetof(ccPlayer_t, anim_state_13) == 0xCE4, "anim_state_13 offset");
static_assert(offsetof(ccPlayer_t, anim_state_14) == 0xCF4, "anim_state_14 offset");
static_assert(offsetof(ccPlayer_t, anim_state_15) == 0xCF8, "anim_state_15 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_12) == 0xCFC, "dmg_ctrl_12 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_13) == 0xD00, "dmg_ctrl_13 offset");
static_assert(offsetof(ccPlayer_t, action_state_13) == 0xD14, "action_state_13 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_14) == 0xE58, "dmg_ctrl_14 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_15) == 0xE5C, "dmg_ctrl_15 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_16) == 0xE60, "dmg_ctrl_16 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_17) == 0xE64, "dmg_ctrl_17 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_18) == 0xE68, "dmg_ctrl_18 offset");
static_assert(offsetof(ccPlayer_t, action_state_14) == 0xE6C, "action_state_14 offset");
static_assert(offsetof(ccPlayer_t, action_state_15) == 0xE70, "action_state_15 offset");
static_assert(offsetof(ccPlayer_t, anim_state_16) == 0x2B80, "anim_state_16 offset");
static_assert(offsetof(ccPlayer_t, anim_state_17) == 0x2BC0, "anim_state_17 offset");
static_assert(offsetof(ccPlayer_t, anim_state_18) == 0x2C00, "anim_state_18 offset");
static_assert(offsetof(ccPlayer_t, anim_state_19) == 0x2D00, "anim_state_19 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_19) == 0x3200, "dmg_ctrl_19 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_7) == 0x3400, "chakra_ctrl_7 offset");
static_assert(offsetof(ccPlayer_t, anim_state_20) == 0x3440, "anim_state_20 offset");
static_assert(offsetof(ccPlayer_t, action_state_16) == 0x34C0, "action_state_16 offset");
static_assert(offsetof(ccPlayer_t, action_state_17) == 0x3500, "action_state_17 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_9) == 0x3940, "atk_ctrl_9 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_10) == 0x3980, "atk_ctrl_10 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_20) == 0x39C0, "dmg_ctrl_20 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_21) == 0x3A40, "dmg_ctrl_21 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_22) == 0x3A80, "dmg_ctrl_22 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_23) == 0x3AC0, "dmg_ctrl_23 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_2) == 0x3B40, "guard_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, action_state_18) == 0x3BC0, "action_state_18 offset");
static_assert(offsetof(ccPlayer_t, action_state_19) == 0x3C80, "action_state_19 offset");
static_assert(offsetof(ccPlayer_t, action_state_20) == 0x3CC0, "action_state_20 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_24) == 0x3D40, "dmg_ctrl_24 offset");
static_assert(offsetof(ccPlayer_t, action_state_21) == 0x3D80, "action_state_21 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_25) == 0x3E00, "dmg_ctrl_25 offset");
static_assert(offsetof(ccPlayer_t, anim_state_21) == 0x4480, "anim_state_21 offset");
static_assert(offsetof(ccPlayer_t, anim_state_22) == 0x44C0, "anim_state_22 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_3) == 0x4680, "guard_ctrl_3 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_11) == 0x46C0, "atk_ctrl_11 offset");
static_assert(offsetof(ccPlayer_t, action_state_22) == 0x4780, "action_state_22 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_26) == 0x4A80, "dmg_ctrl_26 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_27) == 0x4AC0, "dmg_ctrl_27 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_4) == 0x4C40, "guard_ctrl_4 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_28) == 0x4C80, "dmg_ctrl_28 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_8) == 0x4E40, "chakra_ctrl_8 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_12) == 0x5540, "atk_ctrl_12 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_13) == 0x5580, "atk_ctrl_13 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_14) == 0x55C0, "atk_ctrl_14 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_15) == 0x5600, "atk_ctrl_15 offset");
static_assert(offsetof(ccPlayer_t, action_state_23) == 0x5880, "action_state_23 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_29) == 0x5C40, "dmg_ctrl_29 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_30) == 0x5D00, "dmg_ctrl_30 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_31) == 0x5D40, "dmg_ctrl_31 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_32) == 0x5D80, "dmg_ctrl_32 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_33) == 0x6180, "dmg_ctrl_33 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_16) == 0x6A40, "atk_ctrl_16 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_5) == 0x7FE0, "guard_ctrl_5 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_34) == 0x7FEC, "dmg_ctrl_34 offset");
static_assert(offsetof(ccPlayer_t, throw_ctrl_1) == 0x7FF4, "throw_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, throw_ctrl_2) == 0x7FFC, "throw_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_35) == 0x8038, "dmg_ctrl_35 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_36) == 0x8048, "dmg_ctrl_36 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_37) == 0x804C, "dmg_ctrl_37 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_38) == 0x8050, "dmg_ctrl_38 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_39) == 0x8054, "dmg_ctrl_39 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_40) == 0x8060, "dmg_ctrl_40 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_41) == 0x8068, "dmg_ctrl_41 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_42) == 0x80A0, "dmg_ctrl_42 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_43) == 0x80B0, "dmg_ctrl_43 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_44) == 0x80B4, "dmg_ctrl_44 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_45) == 0x80B8, "dmg_ctrl_45 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_46) == 0x80E8, "dmg_ctrl_46 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_47) == 0x80EC, "dmg_ctrl_47 offset");
static_assert(offsetof(ccPlayer_t, action_state_24) == 0x8160, "action_state_24 offset");
static_assert(offsetof(ccPlayer_t, action_state_25) == 0x8164, "action_state_25 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_48) == 0x8168, "dmg_ctrl_48 offset");
static_assert(offsetof(ccPlayer_t, anim_state_23) == 0x8174, "anim_state_23 offset");
static_assert(offsetof(ccPlayer_t, action_state_26) == 0x8178, "action_state_26 offset");
static_assert(offsetof(ccPlayer_t, action_state_27) == 0x817C, "action_state_27 offset");
static_assert(offsetof(ccPlayer_t, action_state_28) == 0x8180, "action_state_28 offset");
static_assert(offsetof(ccPlayer_t, anim_state_24) == 0x8188, "anim_state_24 offset");
static_assert(offsetof(ccPlayer_t, anim_state_25) == 0x8198, "anim_state_25 offset");
static_assert(offsetof(ccPlayer_t, anim_state_26) == 0x81A0, "anim_state_26 offset");
static_assert(offsetof(ccPlayer_t, action_state_29) == 0x81DC, "action_state_29 offset");
static_assert(offsetof(ccPlayer_t, anim_state_27) == 0x81F0, "anim_state_27 offset");
static_assert(offsetof(ccPlayer_t, action_state_30) == 0x8208, "action_state_30 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_9) == 0x83AC, "chakra_ctrl_9 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_10) == 0xA0F8, "chakra_ctrl_10 offset");
static_assert(offsetof(ccPlayer_t, action_state_31) == 0xA108, "action_state_31 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_49) == 0xA138, "dmg_ctrl_49 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_50) == 0xA13C, "dmg_ctrl_50 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_17) == 0xA170, "atk_ctrl_17 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_18) == 0xA17C, "atk_ctrl_18 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_19) == 0xA1C0, "atk_ctrl_19 offset");
static_assert(offsetof(ccPlayer_t, action_state_32) == 0xA200, "action_state_32 offset");
static_assert(offsetof(ccPlayer_t, action_state_33) == 0xA204, "action_state_33 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_20) == 0xA208, "atk_ctrl_20 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_21) == 0xA20C, "atk_ctrl_21 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_22) == 0xA210, "atk_ctrl_22 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_23) == 0xA214, "atk_ctrl_23 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_24) == 0xA218, "atk_ctrl_24 offset");
static_assert(offsetof(ccPlayer_t, action_state_34) == 0xA21C, "action_state_34 offset");
static_assert(offsetof(ccPlayer_t, action_state_35) == 0xA228, "action_state_35 offset");
static_assert(offsetof(ccPlayer_t, action_state_36) == 0xA260, "action_state_36 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_25) == 0xA2A0, "atk_ctrl_25 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_26) == 0xA2A4, "atk_ctrl_26 offset");
static_assert(offsetof(ccPlayer_t, action_state_37) == 0xA2A8, "action_state_37 offset");
static_assert(offsetof(ccPlayer_t, anim_state_28) == 0xA314, "anim_state_28 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_11) == 0xA324, "chakra_ctrl_11 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_6) == 0xAAF0, "guard_ctrl_6 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_27) == 0xAB08, "atk_ctrl_27 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_12) == 0xAB74, "chakra_ctrl_12 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_13) == 0xAB78, "chakra_ctrl_13 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_14) == 0xAB7C, "chakra_ctrl_14 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_15) == 0xAB80, "chakra_ctrl_15 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_7) == 0xAB84, "guard_ctrl_7 offset");
static_assert(offsetof(ccPlayer_t, guard_ctrl_8) == 0xAB88, "guard_ctrl_8 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_16) == 0xABA8, "chakra_ctrl_16 offset");
static_assert(offsetof(ccPlayer_t, anim_state_29) == 0xABD8, "anim_state_29 offset");
static_assert(offsetof(ccPlayer_t, anim_state_30) == 0xABE0, "anim_state_30 offset");
static_assert(offsetof(ccPlayer_t, action_state_38) == 0xABF4, "action_state_38 offset");
static_assert(offsetof(ccPlayer_t, action_state_39) == 0xABF8, "action_state_39 offset");
static_assert(offsetof(ccPlayer_t, action_state_40) == 0xAC40, "action_state_40 offset");
static_assert(offsetof(ccPlayer_t, anim_state_31) == 0xAC4C, "anim_state_31 offset");
static_assert(offsetof(ccPlayer_t, anim_state_32) == 0xAC54, "anim_state_32 offset");
static_assert(offsetof(ccPlayer_t, action_state_41) == 0xAC58, "action_state_41 offset");

#endif /* CCPLAYER_S3_H */
