#ifndef CCPLAYER_S4_H
#define CCPLAYER_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccPlayer struct layout for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, 64-bit)
 * Build alias: s4 | SHA: 147e52a3e0d7
 * Base allocation size: 0x15760 (87904 bytes) — most common
 * Max allocation size: 0x19a50 (105040 bytes) — boss characters
 * Source: ccPlayer::CreatePartner factory with per-character-ID sizing
 * Vtable RVA: 0x76EFF8
 * Generated from state_surface (556 fields) + ctor analysis
 * All fields are INFERRED from static analysis unless noted CONFIRMED.
 */

typedef struct ccPlayer {
    uint8_t pad_0[0x40]; /* 0x0 - 0x40 */
    uint8_t unk_40[0x8]; /* 0x40 [w] medium (intended uint64_t) */
    uint8_t unk_48[0x8]; /* 0x48 [r] medium (intended uint64_t) */
    uint8_t unk_50[0x8]; /* 0x50 [r] medium (intended uint64_t) */
    uint8_t unk_58[0x18]; /* 0x58 [r] medium */
    uint8_t anim_state[0x4]; /* 0x70 [r] low (intended uint32_t) */
    uint8_t unk_74[0x4]; /* 0x74 [r] medium (intended uint32_t) */
    uint8_t unk_78[0x8]; /* 0x78 [r] low (intended uint64_t) */
    uint8_t unk_80[0x10]; /* 0x80 [r] low */
    uint8_t anim_state_1[0x8]; /* 0x90 [rw] low (intended uint64_t) */
    uint8_t unk_98[0x4]; /* 0x98 [rw] high (intended uint32_t) */
    uint8_t anim_state_2[0x4]; /* 0x9C [rw] low (intended uint32_t) */
    uint8_t unk_a0[0x4]; /* 0xA0 [r] medium (intended uint32_t) */
    uint8_t combo_throw_pos[0x4]; /* 0xA4 [w] high (intended uint32_t) */
    uint8_t anim_state_3[0x8]; /* 0xA8 [r] low (intended uint64_t) */
    uint8_t throw_ctrl[0x4]; /* 0xB0 [r] medium (intended uint32_t) */
    uint8_t atk_ctrl[0x4]; /* 0xB4 [r] low (intended uint32_t) */
    uint8_t unk_b8[0x4]; /* 0xB8 [r] low (intended uint32_t) */
    uint8_t unk_bc[0x4]; /* 0xBC [r] medium (intended uint32_t) */
    uint8_t unk_c0[0x8]; /* 0xC0 [rw] low (intended uint64_t) */
    uint8_t unk_c8[0x4]; /* 0xC8 [rw] high (intended uint32_t) */
    uint8_t unk_cc[0x8]; /* 0xCC [w] medium (intended uint64_t) */
    uint8_t unk_d4[0x8]; /* 0xD4 [w] medium (intended uint64_t) */
    uint8_t unk_dc[0x8]; /* 0xDC [w] medium (intended uint64_t) */
    uint8_t unk_e4[0x8]; /* 0xE4 [w] medium (intended uint64_t) */
    uint8_t unk_ec[0x8]; /* 0xEC [w] medium (intended uint64_t) */
    uint8_t unk_f4[0x8]; /* 0xF4 [w] medium (intended uint64_t) */
    uint8_t unk_fc[0x8]; /* 0xFC [w] medium (intended uint64_t) */
    uint8_t unk_104[0x4]; /* 0x104 [w] medium (intended uint32_t) */
    uint8_t anim_state_4[0x40]; /* 0x108 [r] low */
    uint8_t unk_148[0x8]; /* 0x148 [rw] low (intended uint64_t) */
    uint8_t chakra_ctrl_1[0x4]; /* 0x150 [rw] high (intended uint32_t) */
    uint8_t atk_ctrl_1[0x4]; /* 0x154 [rw] low (intended uint32_t) */
    uint8_t unk_158[0x4]; /* 0x158 [rw] low (intended uint32_t) */
    uint8_t chakra_ctrl_2[0x4]; /* 0x15C [rw] medium (intended uint32_t) */
    uint8_t unk_160[0x4]; /* 0x160 [rw] high (intended uint32_t) */
    uint8_t action_state[0x4]; /* 0x164 [rw] low (intended uint32_t) */
    uint8_t unk_168[0x4]; /* 0x168 [rw] high (intended uint32_t) */
    uint8_t unk_16c[0x4]; /* 0x16C [rw] high (intended uint32_t) */
    uint8_t unk_170[0x4]; /* 0x170 [rw] high (intended uint32_t) */
    uint8_t unk_174[0x8]; /* 0x174 [w] medium (intended uint64_t) */
    uint8_t unk_17c[0x8]; /* 0x17C [w] medium (intended uint64_t) */
    uint8_t unk_184[0x4]; /* 0x184 [w] medium (intended uint32_t) */
    uint8_t unk_188[0x4]; /* 0x188 [w] medium (intended uint32_t) */
    uint8_t unk_18c[0x4]; /* 0x18C [w] medium (intended uint32_t) */
    uint8_t unk_190[0x4]; /* 0x190 [w] medium (intended uint32_t) */
    uint8_t unk_194[0x8]; /* 0x194 [w] medium (intended uint64_t) */
    uint8_t unk_19c[0x4]; /* 0x19C [w] medium (intended uint32_t) */
    uint8_t combo_throw_pos_1[0x8]; /* 0x1A0 [rw] low (intended uint64_t) */
    uint8_t combo_throw_pos_2[0x4]; /* 0x1A8 [w] high (intended uint32_t) */
    uint8_t combo_throw_pos_3[0x8]; /* 0x1AC [rw] low (intended uint64_t) */
    uint8_t combo_throw_pos_4[0x4]; /* 0x1B4 [w] high (intended uint32_t) */
    uint8_t unk_1b8[0x8]; /* 0x1B8 [r] low (intended uint64_t) */
    uint8_t unk_1c0[0x40]; /* 0x1C0 [r] low */
    uint8_t action_state_1[0x8]; /* 0x200 [rw] low (intended uint64_t) */
    uint8_t atk_ctrl_4[0x10]; /* 0x208 [r] low */
    uint8_t unk_218[0x28]; /* 0x218 [r] low */
    uint8_t unk_240[0x40]; /* 0x240 [r] low */
    uint8_t unk_280[0x40]; /* 0x280 [r] low */
    uint8_t unk_2c0[0xc0]; /* 0x2C0 [r] low */
    uint8_t unk_380[0xc0]; /* 0x380 [r] low */
    uint8_t unk_440[0x40]; /* 0x440 [r] low */
    uint8_t unk_480[0x40]; /* 0x480 [r] low */
    uint8_t unk_4c0[0x16c]; /* 0x4C0 [r] low */
    uint8_t dmg_ctrl_1[0x8]; /* 0x62C [r] medium (intended uint64_t) */
    uint8_t unk_634[0x2ac]; /* 0x634 [r] medium */
    uint8_t unk_8e0[0x220]; /* 0x8E0 [r] medium */
    uint8_t action_state_11[0x18]; /* 0xB00 [r] medium */
    uint8_t anim_state_8[0x20]; /* 0xB18 [r] low */
    uint8_t unk_b38[0xc0]; /* 0xB38 [w] medium */
    uint8_t unk_bf8[0x8]; /* 0xBF8 [r] medium (intended uint64_t) */
    uint8_t unk_c00[0x74]; /* 0xC00 [r] low */
    uint8_t unk_c74[0x8]; /* 0xC74 [r] medium (intended uint64_t) */
    uint8_t unk_c7c[0xc]; /* 0xC7C [rw] medium */
    uint8_t unk_c88[0x4]; /* 0xC88 [r] medium (intended uint32_t) */
    uint8_t unk_c8c[0x8]; /* 0xC8C [r] medium (intended uint64_t) */
    uint8_t unk_c94[0xc]; /* 0xC94 [r] medium */
    uint8_t unk_ca0[0x8]; /* 0xCA0 [r] medium (intended uint64_t) */
    uint8_t unk_ca8[0x4]; /* 0xCA8 [r] medium (intended uint32_t) */
    uint8_t unk_cac[0x4]; /* 0xCAC [w] medium (intended uint32_t) */
    uint8_t unk_cb0[0x4]; /* 0xCB0 [r] medium (intended uint32_t) */
    uint8_t unk_cb4[0x8]; /* 0xCB4 [rw] medium (intended uint64_t) */
    uint8_t unk_cbc[0x4]; /* 0xCBC [r] medium (intended uint32_t) */
    uint8_t anim_state_9[0x4]; /* 0xCC0 [rw] medium (intended uint32_t) */
    uint8_t unk_cc4[0x4]; /* 0xCC4 [rw] high (intended uint32_t) */
    uint8_t dmg_ctrl_12[0x4]; /* 0xCC8 [rw] medium (intended uint32_t) */
    uint8_t unk_ccc[0x4]; /* 0xCCC [rw] high (intended uint32_t) */
    uint8_t action_state_12[0x4]; /* 0xCD0 [rw] medium (intended uint32_t) */
    uint8_t unk_cd4[0x4]; /* 0xCD4 [rw] high (intended uint32_t) */
    uint8_t unk_cd8[0x4]; /* 0xCD8 [rw] high (intended uint32_t) */
    uint8_t action_state_13[0x18]; /* 0xCDC [rw] low */
    uint8_t unk_cf4[0x4]; /* 0xCF4 [rw] high (intended uint32_t) */
    uint8_t unk_cf8[0x4]; /* 0xCF8 [w] high (intended uint32_t) */
    uint8_t unk_cfc[0xc]; /* 0xCFC [r] medium */
    uint8_t unk_d08[0x4]; /* 0xD08 [rw] high (intended uint32_t) */
    uint8_t unk_d0c[0x4]; /* 0xD0C [w] high (intended uint32_t) */
    uint8_t unk_d10[0x4]; /* 0xD10 [w] high (intended uint32_t) */
    uint8_t unk_d14[0x4]; /* 0xD14 [w] high (intended uint32_t) */
    uint8_t unk_d18[0x4]; /* 0xD18 [rw] high (intended uint32_t) */
    uint8_t unk_d1c[0x4]; /* 0xD1C [w] high (intended uint32_t) */
    uint8_t unk_d20[0x4]; /* 0xD20 [r] medium (intended uint32_t) */
    uint8_t unk_d24[0x18]; /* 0xD24 [w] high */
    uint8_t unk_d3c[0x4]; /* 0xD3C [rw] high (intended uint32_t) */
    uint8_t unk_d40[0x4]; /* 0xD40 [w] high (intended uint32_t) */
    uint8_t unk_d44[0xc]; /* 0xD44 [r] medium */
    uint8_t unk_d50[0x4]; /* 0xD50 [r] medium (intended uint32_t) */
    uint8_t unk_d54[0x4]; /* 0xD54 [rw] high (intended uint32_t) */
    uint8_t unk_d58[0x4]; /* 0xD58 [rw] high (intended uint32_t) */
    uint8_t unk_d5c[0x8]; /* 0xD5C [w] high (intended uint64_t) */
    uint8_t unk_d64[0x200]; /* 0xD64 [r] low */
    uint8_t unk_f64[0x10]; /* 0xF64 [r] medium */
    uint8_t unk_f74[0x8]; /* 0xF74 [rw] medium (intended uint64_t) */
    uint8_t unk_f7c[0x4]; /* 0xF7C [r] medium (intended uint32_t) */
    uint8_t unk_f80[0x4]; /* 0xF80 [rw] high (intended uint32_t) */
    uint8_t unk_f84[0x4]; /* 0xF84 [r] medium (intended uint32_t) */
    uint8_t unk_f88[0x4]; /* 0xF88 [r] medium (intended uint32_t) */
    uint8_t unk_f8c[0x4]; /* 0xF8C [rw] medium (intended uint32_t) */
    uint8_t unk_f90[0x4]; /* 0xF90 [r] medium (intended uint32_t) */
    uint8_t unk_f94[0x10]; /* 0xF94 [r] medium */
    uint8_t unk_fa4[0x8]; /* 0xFA4 [rw] medium (intended uint64_t) */
    uint8_t unk_fac[0x4]; /* 0xFAC [r] medium (intended uint32_t) */
    uint8_t unk_fb0[0xc]; /* 0xFB0 [r] medium */
    uint8_t unk_fbc[0x4]; /* 0xFBC [rw] medium (intended uint32_t) */
    uint8_t unk_fc0[0x1c]; /* 0xFC0 [r] medium */
    uint8_t unk_fdc[0x4]; /* 0xFDC [r] medium (intended uint32_t) */
    uint8_t unk_fe0[0xc]; /* 0xFE0 [r] medium */
    uint8_t unk_fec[0x4]; /* 0xFEC [rw] medium (intended uint32_t) */
    uint8_t unk_ff0[0x4]; /* 0xFF0 [r] medium (intended uint32_t) */
    uint8_t unk_ff4[0x4]; /* 0xFF4 [r] medium (intended uint32_t) */
    uint8_t unk_ff8[0x4]; /* 0xFF8 [r] medium (intended uint32_t) */
    uint8_t unk_ffc[0x8]; /* 0xFFC [w] medium (intended uint64_t) */
    uint8_t unk_1004[0x4]; /* 0x1004 [rw] medium (intended uint32_t) */
    uint8_t unk_1008[0x4]; /* 0x1008 [r] medium (intended uint32_t) */
    uint8_t unk_100c[0x10]; /* 0x100C [r] medium */
    uint8_t unk_101c[0x8]; /* 0x101C [rw] medium (intended uint64_t) */
    uint8_t unk_1024[0x10]; /* 0x1024 [r] medium */
    uint8_t unk_1034[0x4]; /* 0x1034 [r] medium (intended uint32_t) */
    uint8_t unk_1038[0xc]; /* 0x1038 [r] medium */
    uint8_t unk_1044[0x4]; /* 0x1044 [rw] high (intended uint32_t) */
    uint8_t unk_1048[0x8]; /* 0x1048 [r] medium (intended uint64_t) */
    uint8_t unk_1050[0x8]; /* 0x1050 [r] low (intended uint64_t) */
    uint8_t unk_1058[0x8]; /* 0x1058 [rw] medium (intended uint64_t) */
    uint8_t unk_1060[0x8]; /* 0x1060 [r] medium (intended uint64_t) */
    uint8_t unk_1068[0x10]; /* 0x1068 [r] medium */
    uint8_t unk_1078[0x4]; /* 0x1078 [w] medium (intended uint32_t) */
    uint8_t unk_107c[0x4]; /* 0x107C [rw] medium (intended uint32_t) */
    uint8_t unk_1080[0x4]; /* 0x1080 [r] medium (intended uint32_t) */
    uint8_t unk_1084[0x4]; /* 0x1084 [r] medium (intended uint32_t) */
    uint8_t unk_1088[0x4]; /* 0x1088 [r] medium (intended uint32_t) */
    uint8_t unk_108c[0x4]; /* 0x108C [r] medium (intended uint32_t) */
    uint8_t unk_1090[0xc]; /* 0x1090 [rw] high */
    uint8_t unk_109c[0x4]; /* 0x109C [rw] high (intended uint32_t) */
    uint8_t unk_10a0[0x4]; /* 0x10A0 [w] medium (intended uint32_t) */
    uint8_t unk_10a4[0x8]; /* 0x10A4 [rw] high (intended uint64_t) */
    uint8_t unk_10ac[0x4]; /* 0x10AC [rw] high (intended uint32_t) */
    uint8_t unk_10b0[0x4]; /* 0x10B0 [rw] high (intended uint32_t) */
    uint8_t unk_10b4[0x8]; /* 0x10B4 [w] medium (intended uint64_t) */
    uint8_t unk_10bc[0x4]; /* 0x10BC [w] medium (intended uint32_t) */
    uint8_t unk_10c0[0x480]; /* 0x10C0 [r] low */
    uint8_t unk_1540[0xd4]; /* 0x1540 [r] low */
    uint8_t unk_1614[0x168]; /* 0x1614 [r] low */
    uint8_t unk_177c[0x28]; /* 0x177C [r] low */
    uint8_t unk_17a4[0x4]; /* 0x17A4 [rw] high (intended uint32_t) */
    uint8_t unk_17a8[0x8]; /* 0x17A8 [w] low (intended uint64_t) */
    uint8_t unk_17b0[0x4]; /* 0x17B0 [w] high (intended uint32_t) */
    uint8_t unk_17b4[0x4]; /* 0x17B4 [w] high (intended uint32_t) */
    uint8_t unk_17b8[0x30]; /* 0x17B8 [r] low */
    uint8_t unk_17e8[0x19c]; /* 0x17E8 [r] low */
    uint8_t unk_1984[0x7fc]; /* 0x1984 [r] low */
    uint8_t unk_2180[0x3740]; /* 0x2180 [r] low */
    uint8_t unk_58c0[0x1c0]; /* 0x58C0 [r] low */
    uint8_t unk_5a80[0x80]; /* 0x5A80 [r] low */
    uint8_t unk_5b00[0x80]; /* 0x5B00 [r] low */
    uint8_t unk_5b80[0x80]; /* 0x5B80 [r] low */
    uint8_t unk_5c00[0x40]; /* 0x5C00 [r] low */
    uint8_t unk_5c40[0x40]; /* 0x5C40 [r] low */
    uint8_t unk_5c80[0x40]; /* 0x5C80 [r] low */
    uint8_t unk_5cc0[0xc0]; /* 0x5CC0 [r] low */
    uint8_t unk_5d80[0xc0]; /* 0x5D80 [r] low */
    uint8_t unk_5e40[0x40]; /* 0x5E40 [r] low */
    uint8_t unk_5e80[0x40]; /* 0x5E80 [r] low */
    uint8_t unk_5ec0[0x180]; /* 0x5EC0 [r] low */
    uint8_t unk_6040[0x40]; /* 0x6040 [r] low */
    uint8_t unk_6080[0x40]; /* 0x6080 [r] low */
    uint8_t unk_60c0[0x40]; /* 0x60C0 [r] low */
    uint8_t unk_6100[0x80]; /* 0x6100 [r] low */
    uint8_t unk_6180[0x40]; /* 0x6180 [r] low */
    uint8_t unk_61c0[0x40]; /* 0x61C0 [r] low */
    uint8_t unk_6200[0x40]; /* 0x6200 [r] low */
    uint8_t unk_6240[0x40]; /* 0x6240 [r] low */
    uint8_t unk_6280[0x80]; /* 0x6280 [r] low */
    uint8_t unk_6300[0x80]; /* 0x6300 [r] low */
    uint8_t unk_6380[0x80]; /* 0x6380 [r] low */
    uint8_t unk_6400[0x80]; /* 0x6400 [r] low */
    uint8_t unk_6480[0x40]; /* 0x6480 [r] low */
    uint8_t unk_64c0[0x80]; /* 0x64C0 [r] low */
    uint8_t unk_6540[0x80]; /* 0x6540 [r] low */
    uint8_t unk_65c0[0x80]; /* 0x65C0 [r] low */
    uint8_t unk_6640[0x40]; /* 0x6640 [r] low */
    uint8_t unk_6680[0x80]; /* 0x6680 [r] low */
    uint8_t unk_6700[0x280]; /* 0x6700 [r] low */
    uint8_t unk_6980[0x140]; /* 0x6980 [r] low */
    uint8_t unk_6ac0[0x180]; /* 0x6AC0 [r] low */
    uint8_t unk_6c40[0x80]; /* 0x6C40 [r] low */
    uint8_t unk_6cc0[0x80]; /* 0x6CC0 [r] low */
    uint8_t unk_6d40[0x40]; /* 0x6D40 [r] low */
    uint8_t unk_6d80[0x40]; /* 0x6D80 [r] low */
    uint8_t unk_6dc0[0x240]; /* 0x6DC0 [r] low */
    uint8_t unk_7000[0x40]; /* 0x7000 [r] low */
    uint8_t unk_7040[0x80]; /* 0x7040 [r] low */
    uint8_t unk_70c0[0x40]; /* 0x70C0 [r] low */
    uint8_t unk_7100[0x280]; /* 0x7100 [r] low */
    uint8_t unk_7380[0x280]; /* 0x7380 [r] low */
    uint8_t unk_7600[0x100]; /* 0x7600 [r] low */
    uint8_t unk_7700[0x180]; /* 0x7700 [r] low */
    uint8_t unk_7880[0x80]; /* 0x7880 [r] low */
    uint8_t unk_7900[0x40]; /* 0x7900 [r] low */
    uint8_t unk_7940[0x40]; /* 0x7940 [r] low */
    uint8_t unk_7980[0x40]; /* 0x7980 [r] low */
    uint8_t unk_79c0[0x80]; /* 0x79C0 [r] low */
    uint8_t unk_7a40[0x40]; /* 0x7A40 [r] low */
    uint8_t unk_7a80[0x80]; /* 0x7A80 [r] low */
    uint8_t unk_7b00[0x40]; /* 0x7B00 [r] low */
    uint8_t unk_7b40[0x40]; /* 0x7B40 [r] low */
    uint8_t unk_7b80[0x40]; /* 0x7B80 [r] low */
    uint8_t unk_7bc0[0x240]; /* 0x7BC0 [r] low */
    uint8_t unk_7e00[0x80]; /* 0x7E00 [r] low */
    uint8_t unk_7e80[0x40]; /* 0x7E80 [r] low */
    uint8_t unk_7ec0[0xc0]; /* 0x7EC0 [r] low */
    uint8_t unk_7f80[0x80]; /* 0x7F80 [r] low */
    uint8_t throw_ctrl_2[0x40]; /* 0x8000 [r] medium */
    uint8_t unk_8040[0x80]; /* 0x8040 [r] low */
    uint8_t dmg_ctrl_39[0x40]; /* 0x80C0 [r] low */
    uint8_t action_state_24[0x80]; /* 0x8100 [r] low */
    uint8_t unk_8180[0x80]; /* 0x8180 [r] low */
    uint8_t action_state_30[0x100]; /* 0x8200 [r] medium */
    uint8_t unk_8300[0x80]; /* 0x8300 [r] low */
    uint8_t unk_8380[0x140]; /* 0x8380 [r] low */
    uint8_t unk_84c0[0x40]; /* 0x84C0 [r] low */
    uint8_t unk_8500[0x40]; /* 0x8500 [r] low */
    uint8_t unk_8540[0x40]; /* 0x8540 [r] low */
    uint8_t unk_8580[0x100]; /* 0x8580 [r] low */
    uint8_t unk_8680[0x80]; /* 0x8680 [r] low */
    uint8_t unk_8700[0x40]; /* 0x8700 [r] low */
    uint8_t unk_8740[0x80]; /* 0x8740 [r] low */
    uint8_t unk_87c0[0x40]; /* 0x87C0 [r] low */
    uint8_t unk_8800[0x180]; /* 0x8800 [r] low */
    uint8_t unk_8980[0x80]; /* 0x8980 [r] low */
    uint8_t unk_8a00[0x80]; /* 0x8A00 [r] low */
    uint8_t unk_8a80[0x180]; /* 0x8A80 [r] low */
    uint8_t unk_8c00[0x80]; /* 0x8C00 [r] low */
    uint8_t unk_8c80[0x140]; /* 0x8C80 [r] low */
    uint8_t unk_8dc0[0x40]; /* 0x8DC0 [r] low */
    uint8_t unk_8e00[0x100]; /* 0x8E00 [r] low */
    uint8_t unk_8f00[0x40]; /* 0x8F00 [r] low */
    uint8_t unk_8f40[0xc0]; /* 0x8F40 [r] low */
    uint8_t unk_9000[0x40]; /* 0x9000 [r] low */
    uint8_t unk_9040[0x40]; /* 0x9040 [r] low */
    uint8_t unk_9080[0x140]; /* 0x9080 [r] low */
    uint8_t unk_91c0[0x80]; /* 0x91C0 [r] low */
    uint8_t unk_9240[0x40]; /* 0x9240 [r] low */
    uint8_t unk_9280[0x80]; /* 0x9280 [r] low */
    uint8_t unk_9300[0x40]; /* 0x9300 [r] low */
    uint8_t unk_9340[0xc0]; /* 0x9340 [r] low */
    uint8_t unk_9400[0x280]; /* 0x9400 [r] low */
    uint8_t unk_9680[0x80]; /* 0x9680 [r] low */
    uint8_t unk_9700[0x40]; /* 0x9700 [r] low */
    uint8_t unk_9740[0x80]; /* 0x9740 [r] low */
    uint8_t unk_97c0[0x40]; /* 0x97C0 [r] low */
    uint8_t unk_9800[0xc0]; /* 0x9800 [r] low */
    uint8_t unk_98c0[0x1c0]; /* 0x98C0 [r] low */
    uint8_t unk_9a80[0x40]; /* 0x9A80 [r] low */
    uint8_t unk_9ac0[0xc0]; /* 0x9AC0 [r] low */
    uint8_t unk_9b80[0x40]; /* 0x9B80 [r] low */
    uint8_t unk_9bc0[0xc0]; /* 0x9BC0 [r] low */
    uint8_t unk_9c80[0x80]; /* 0x9C80 [r] low */
    uint8_t unk_9d00[0x240]; /* 0x9D00 [r] low */
    uint8_t unk_9f40[0x140]; /* 0x9F40 [r] low */
    uint8_t unk_a080[0x40]; /* 0xA080 [r] low */
    uint8_t unk_a0c0[0x80]; /* 0xA0C0 [r] low */
    uint8_t atk_ctrl_17[0x40]; /* 0xA140 [r] medium */
    uint8_t unk_a180[0x80]; /* 0xA180 [r] low */
    uint8_t unk_a200[0x40]; /* 0xA200 [r] low */
    uint8_t unk_a240[0x100]; /* 0xA240 [r] low */
    uint8_t unk_a340[0x240]; /* 0xA340 [r] low */
    uint8_t unk_a580[0x40]; /* 0xA580 [r] low */
    uint8_t unk_a5c0[0x100]; /* 0xA5C0 [r] low */
    uint8_t unk_a6c0[0xc0]; /* 0xA6C0 [r] low */
    uint8_t unk_a780[0xc0]; /* 0xA780 [r] low */
    uint8_t unk_a840[0x40]; /* 0xA840 [r] low */
    uint8_t unk_a880[0x280]; /* 0xA880 [r] low */
    uint8_t unk_ab00[0x40]; /* 0xAB00 [r] low */
    uint8_t unk_ab40[0xd80]; /* 0xAB40 [r] low */
    uint8_t unk_b8c0[0x8c0]; /* 0xB8C0 [r] low */
    uint8_t unk_c180[0x3268]; /* 0xC180 [r] low */
    uint8_t unk_f3e8[0x8]; /* 0xF3E8 [r] medium (intended uint64_t) */
    uint8_t unk_f3f0[0x64]; /* 0xF3F0 [r] low */
    uint8_t unk_f454[0x38c]; /* 0xF454 [r] low */
    uint8_t unk_f7e0[0x80]; /* 0xF7E0 [r] low */
    uint8_t unk_f860[0x114]; /* 0xF860 [rw] high */
    uint8_t unk_f974[0xc]; /* 0xF974 [rw] medium */
    uint8_t unk_f980[0x88]; /* 0xF980 [r] low */
    uint8_t unk_fa08[0x8]; /* 0xFA08 [rw] high (intended uint64_t) */
    uint8_t unk_fa10[0x80]; /* 0xFA10 [r] low */
    uint8_t unk_fa90[0x30]; /* 0xFA90 [r] medium */
    uint8_t unk_fac0[0x28]; /* 0xFAC0 [r] low */
    uint8_t unk_fae8[0x4]; /* 0xFAE8 [r] medium (intended uint32_t) */
    uint8_t unk_faec[0x4]; /* 0xFAEC [r] medium (intended uint32_t) */
    uint8_t unk_faf0[0x8]; /* 0xFAF0 [r] medium (intended uint64_t) */
    uint8_t unk_faf8[0x8]; /* 0xFAF8 [r] medium (intended uint64_t) */
    uint8_t unk_fb00[0x8]; /* 0xFB00 [r] low (intended uint64_t) */
    uint8_t unk_fb08[0x8]; /* 0xFB08 [r] medium (intended uint64_t) */
    uint8_t unk_fb10[0x8]; /* 0xFB10 [r] medium (intended uint64_t) */
    uint8_t unk_fb18[0xc]; /* 0xFB18 [rw] medium */
    uint8_t unk_fb24[0x8]; /* 0xFB24 [rw] low (intended uint64_t) */
    uint8_t unk_fb2c[0x4]; /* 0xFB2C [rw] high (intended uint32_t) */
    uint8_t unk_fb30[0x8]; /* 0xFB30 [rw] medium (intended uint64_t) */
    uint8_t unk_fb38[0x30]; /* 0xFB38 [r] low */
    uint8_t unk_fb68[0x8]; /* 0xFB68 [r] low (intended uint64_t) */
    uint8_t unk_fb70[0x4]; /* 0xFB70 [r] medium (intended uint32_t) */
    uint8_t unk_fb74[0x4]; /* 0xFB74 [rw] high (intended uint32_t) */
    uint8_t unk_fb78[0x4]; /* 0xFB78 [r] medium (intended uint32_t) */
    uint8_t unk_fb7c[0x4]; /* 0xFB7C [r] medium (intended uint32_t) */
    uint8_t unk_fb80[0x4]; /* 0xFB80 [r] medium (intended uint32_t) */
    uint8_t unk_fb84[0x8]; /* 0xFB84 [r] medium (intended uint64_t) */
    uint8_t unk_fb8c[0x8]; /* 0xFB8C [rw] low (intended uint64_t) */
    uint8_t unk_fb94[0x14]; /* 0xFB94 [rw] high */
    uint8_t unk_fba8[0x8]; /* 0xFBA8 [r] medium (intended uint64_t) */
    uint8_t unk_fbb0[0x4]; /* 0xFBB0 [r] low (intended uint32_t) */
    uint8_t unk_fbb4[0x4]; /* 0xFBB4 [r] medium (intended uint32_t) */
    uint8_t unk_fbb8[0x8]; /* 0xFBB8 [r] medium (intended uint64_t) */
    uint8_t unk_fbc0[0x10]; /* 0xFBC0 [r] medium */
    uint8_t unk_fbd0[0x10]; /* 0xFBD0 [rw] high */
    uint8_t unk_fbe0[0x4]; /* 0xFBE0 [r] medium (intended uint32_t) */
    uint8_t unk_fbe4[0x4]; /* 0xFBE4 [rw] high (intended uint32_t) */
    uint8_t unk_fbe8[0x4]; /* 0xFBE8 [rw] high (intended uint32_t) */
    uint8_t unk_fbec[0x4]; /* 0xFBEC [r] medium (intended uint32_t) */
    uint8_t unk_fbf0[0x4]; /* 0xFBF0 [rw] medium (intended uint32_t) */
    uint8_t unk_fbf4[0x8]; /* 0xFBF4 [rw] low (intended uint64_t) */
    uint8_t unk_fbfc[0x4]; /* 0xFBFC [w] medium (intended uint32_t) */
    uint8_t unk_fc00[0x4]; /* 0xFC00 [rw] medium (intended uint32_t) */
    uint8_t unk_fc04[0x8]; /* 0xFC04 [rw] low (intended uint64_t) */
    uint8_t unk_fc0c[0x4]; /* 0xFC0C [w] medium (intended uint32_t) */
    uint8_t unk_fc10[0x4]; /* 0xFC10 [w] medium (intended uint32_t) */
    uint8_t unk_fc14[0x4]; /* 0xFC14 [w] medium (intended uint32_t) */
    uint8_t unk_fc18[0xc]; /* 0xFC18 [r] medium */
    uint8_t unk_fc24[0x6c]; /* 0xFC24 [r] medium */
    uint8_t unk_fc90[0x10]; /* 0xFC90 [rw] high */
    uint8_t unk_fca0[0x4]; /* 0xFCA0 [r] medium (intended uint32_t) */
    uint8_t unk_fca4[0x4]; /* 0xFCA4 [r] medium (intended uint32_t) */
    uint8_t unk_fca8[0x8]; /* 0xFCA8 [r] medium (intended uint64_t) */
    uint8_t unk_fcb0[0x4]; /* 0xFCB0 [r] medium (intended uint32_t) */
    uint8_t unk_fcb4[0x4]; /* 0xFCB4 [r] medium (intended uint32_t) */
    uint8_t unk_fcb8[0x4]; /* 0xFCB8 [rw] high (intended uint32_t) */
    uint8_t unk_fcbc[0x4]; /* 0xFCBC [rw] high (intended uint32_t) */
    uint8_t unk_fcc0[0x8]; /* 0xFCC0 [r] medium (intended uint64_t) */
    uint8_t unk_fcc8[0x4]; /* 0xFCC8 [r] medium (intended uint32_t) */
    uint8_t unk_fccc[0x4]; /* 0xFCCC [w] medium (intended uint32_t) */
    uint8_t unk_fcd0[0x4]; /* 0xFCD0 [w] high (intended uint32_t) */
    uint8_t unk_fcd4[0x4]; /* 0xFCD4 [w] medium (intended uint32_t) */
    uint8_t unk_fcd8[0x10]; /* 0xFCD8 [r] low */
    uint8_t unk_fce8[0x8]; /* 0xFCE8 [w] medium (intended uint64_t) */
    uint8_t unk_fcf0[0x20]; /* 0xFCF0 [r] medium */
    uint8_t unk_fd10[0x10]; /* 0xFD10 [r] low */
    uint8_t unk_fd20[0x8]; /* 0xFD20 [w] medium (intended uint64_t) */
    uint8_t unk_fd28[0x20]; /* 0xFD28 [r] medium */
    uint8_t unk_fd48[0x4]; /* 0xFD48 [w] medium (intended uint32_t) */
    uint8_t unk_fd4c[0x4]; /* 0xFD4C [r] medium (intended uint32_t) */
    uint8_t unk_fd50[0x4]; /* 0xFD50 [rw] high (intended uint32_t) */
    uint8_t unk_fd54[0x4]; /* 0xFD54 [r] medium (intended uint32_t) */
    uint8_t unk_fd58[0x4]; /* 0xFD58 [rw] medium (intended uint32_t) */
    uint8_t unk_fd5c[0x18]; /* 0xFD5C [r] medium */
    uint8_t unk_fd74[0x4]; /* 0xFD74 [rw] medium (intended uint32_t) */
    uint8_t unk_fd78[0x4]; /* 0xFD78 [r] medium (intended uint32_t) */
    uint8_t unk_fd7c[0x14]; /* 0xFD7C [rw] low */
    uint8_t unk_fd90[0x10]; /* 0xFD90 [r] low */
    uint8_t unk_fda0[0x70]; /* 0xFDA0 [r] low */
    uint8_t unk_fe10[0x4]; /* 0xFE10 [w] medium (intended uint32_t) */
    uint8_t unk_fe14[0x4]; /* 0xFE14 [w] medium (intended uint32_t) */
    uint8_t unk_fe18[0x4]; /* 0xFE18 [w] medium (intended uint32_t) */
    uint8_t unk_fe1c[0x4]; /* 0xFE1C [w] medium (intended uint32_t) */
    uint8_t unk_fe20[0x18]; /* 0xFE20 [rw] high */
    uint8_t unk_fe38[0xc]; /* 0xFE38 [r] low */
    uint8_t unk_fe44[0x3c]; /* 0xFE44 [r] low */
    uint8_t unk_fe80[0x8]; /* 0xFE80 [w] medium (intended uint64_t) */
    uint8_t unk_fe88[0x8]; /* 0xFE88 [r] medium (intended uint64_t) */
    uint8_t unk_fe90[0x38]; /* 0xFE90 [r] low */
    uint8_t unk_fec8[0x8]; /* 0xFEC8 [r] medium (intended uint64_t) */
    uint8_t unk_fed0[0x10]; /* 0xFED0 [rw] medium */
    uint8_t unk_fee0[0x25c]; /* 0xFEE0 [r] low */
    uint8_t unk_1013c[0x20]; /* 0x1013C [r] medium */
    uint8_t unk_1015c[0x3e84]; /* 0x1015C [r] medium */
    uint8_t unk_13fe0[0x10]; /* 0x13FE0 [r] medium */
    uint8_t unk_13ff0[0x20]; /* 0x13FF0 [w] medium */
    uint8_t unk_14010[0x4]; /* 0x14010 [rw] medium (intended uint32_t) */
    uint8_t unk_14014[0xc]; /* 0x14014 [r] medium */
    uint8_t unk_14020[0x4]; /* 0x14020 [rw] medium (intended uint32_t) */
    uint8_t unk_14024[0x4]; /* 0x14024 [rw] medium (intended uint32_t) */
    uint8_t unk_14028[0x4]; /* 0x14028 [r] medium (intended uint32_t) */
    uint8_t unk_1402c[0x8]; /* 0x1402C [w] medium (intended uint64_t) */
    uint8_t unk_14034[0x18]; /* 0x14034 [rw] medium */
    uint8_t unk_1404c[0x4]; /* 0x1404C [rw] medium (intended uint32_t) */
    uint8_t unk_14050[0x4]; /* 0x14050 [r] medium (intended uint32_t) */
    uint8_t unk_14054[0x4]; /* 0x14054 [rw] high (intended uint32_t) */
    uint8_t unk_14058[0x4]; /* 0x14058 [r] medium (intended uint32_t) */
    uint8_t unk_1405c[0x4]; /* 0x1405C [r] medium (intended uint32_t) */
    uint8_t unk_14060[0x8]; /* 0x14060 [rw] low (intended uint64_t) */
    uint8_t unk_14068[0x8]; /* 0x14068 [w] medium (intended uint64_t) */
    uint8_t unk_14070[0x8]; /* 0x14070 [w] medium (intended uint64_t) */
    uint8_t unk_14078[0x8]; /* 0x14078 [w] medium (intended uint64_t) */
    uint8_t unk_14080[0x8]; /* 0x14080 [w] medium (intended uint64_t) */
    uint8_t unk_14088[0x8]; /* 0x14088 [w] medium (intended uint64_t) */
    uint8_t unk_14090[0x8]; /* 0x14090 [w] medium (intended uint64_t) */
    uint8_t unk_14098[0x8]; /* 0x14098 [w] medium (intended uint64_t) */
    uint8_t unk_140a0[0x2]; /* 0x140A0 [rw] high (intended uint16_t) */
    uint8_t unk_140a2[0x2]; /* 0x140A2 [r] medium (intended uint16_t) */
    uint8_t unk_140a4[0x2]; /* 0x140A4 [w] medium (intended uint16_t) */
    uint8_t unk_140a6[0x2]; /* 0x140A6 [r] medium (intended uint16_t) */
    uint8_t unk_140a8[0x4]; /* 0x140A8 [rw] high (intended uint32_t) */
    uint8_t unk_140ac[0x4]; /* 0x140AC [rw] high (intended uint32_t) */
    uint8_t unk_140b0[0x4]; /* 0x140B0 [rw] high (intended uint32_t) */
    uint8_t unk_140b4[0x4]; /* 0x140B4 [rw] high (intended uint32_t) */
    uint8_t unk_140b8[0x4]; /* 0x140B8 [w] medium (intended uint32_t) */
    uint8_t unk_140bc[0x4]; /* 0x140BC [rw] high (intended uint32_t) */
    uint8_t unk_140c0[0x4]; /* 0x140C0 [rw] high (intended uint32_t) */
    uint8_t unk_140c4[0x4]; /* 0x140C4 [rw] high (intended uint32_t) */
    uint8_t unk_140c8[0x10]; /* 0x140C8 [w] medium */
    uint8_t unk_140d8[0x8]; /* 0x140D8 [r] medium (intended uint64_t) */
    uint8_t unk_140e0[0xc]; /* 0x140E0 [w] medium */
    uint8_t unk_140ec[0x4]; /* 0x140EC [w] medium (intended uint32_t) */
    uint8_t unk_140f0[0x4]; /* 0x140F0 [w] medium (intended uint32_t) */
    uint8_t unk_140f4[0x4]; /* 0x140F4 [rw] high (intended uint32_t) */
    uint8_t unk_140f8[0x4]; /* 0x140F8 [rw] high (intended uint32_t) */
    uint8_t unk_140fc[0x4]; /* 0x140FC [rw] low (intended uint32_t) */
    uint8_t unk_14100[0x4]; /* 0x14100 [rw] low (intended uint32_t) */
    uint8_t unk_14104[0x4]; /* 0x14104 [w] high (intended uint32_t) */
    uint8_t unk_14108[0x4]; /* 0x14108 [rw] high (intended uint32_t) */
    uint8_t unk_1410c[0x4]; /* 0x1410C [w] high (intended uint32_t) */
    uint8_t unk_14110[0x8]; /* 0x14110 [w] medium (intended uint64_t) */
    uint8_t unk_14118[0x8]; /* 0x14118 [w] high (intended uint64_t) */
    uint8_t unk_14120[0x38]; /* 0x14120 [r] low */
    uint8_t unk_14158[0x4]; /* 0x14158 [w] medium (intended uint32_t) */
    uint8_t unk_1415c[0x8]; /* 0x1415C [r] medium (intended uint64_t) */
    uint8_t unk_14164[0xc]; /* 0x14164 [r] low */
    uint8_t unk_14170[0x18]; /* 0x14170 [rw] high */
    uint8_t unk_14188[0x4]; /* 0x14188 [r] medium (intended uint32_t) */
    uint8_t unk_1418c[0x8]; /* 0x1418C [rw] medium (intended uint64_t) */
    uint8_t unk_14194[0x8]; /* 0x14194 [w] medium (intended uint64_t) */
    uint8_t unk_1419c[0x8]; /* 0x1419C [w] medium (intended uint64_t) */
    uint8_t unk_141a4[0x4]; /* 0x141A4 [w] high (intended uint32_t) */
    uint8_t unk_141a8[0x4]; /* 0x141A8 [rw] medium (intended uint32_t) */
    uint8_t unk_141ac[0x4]; /* 0x141AC [r] medium (intended uint32_t) */
    uint8_t unk_141b0[0x4]; /* 0x141B0 [rw] high (intended uint32_t) */
    uint8_t unk_141b4[0x4]; /* 0x141B4 [rw] high (intended uint32_t) */
    uint8_t unk_141b8[0x4]; /* 0x141B8 [rw] high (intended uint32_t) */
    uint8_t unk_141bc[0x8]; /* 0x141BC [rw] low (intended uint64_t) */
    uint8_t unk_141c4[0x4]; /* 0x141C4 [w] medium (intended uint32_t) */
    uint8_t unk_141c8[0x4]; /* 0x141C8 [rw] high (intended uint32_t) */
    uint8_t unk_141cc[0x8]; /* 0x141CC [rw] low (intended uint64_t) */
    uint8_t unk_141d4[0x4]; /* 0x141D4 [w] medium (intended uint32_t) */
    uint8_t unk_141d8[0x4]; /* 0x141D8 [rw] high (intended uint32_t) */
    uint8_t unk_141dc[0x4]; /* 0x141DC [rw] high (intended uint32_t) */
    uint8_t unk_141e0[0x4]; /* 0x141E0 [rw] high (intended uint32_t) */
    uint8_t unk_141e4[0x4]; /* 0x141E4 [rw] high (intended uint32_t) */
    uint8_t unk_141e8[0x4]; /* 0x141E8 [w] high (intended uint32_t) */
    uint8_t unk_141ec[0x10]; /* 0x141EC [rw] high */
    uint8_t unk_141fc[0xc]; /* 0x141FC [r] low */
    uint8_t unk_14208[0xc]; /* 0x14208 [r] low */
    uint8_t unk_14214[0x804]; /* 0x14214 [rw] medium */
    uint8_t unk_14a18[0x8]; /* 0x14A18 [r] low (intended uint64_t) */
    uint8_t unk_14a20[0x28]; /* 0x14A20 [r] medium */
    uint8_t unk_14a48[0x8]; /* 0x14A48 [rw] high (intended uint64_t) */
    uint8_t unk_14a50[0x20]; /* 0x14A50 [rw] high */
    uint8_t unk_14a70[0x4]; /* 0x14A70 [w] medium (intended uint32_t) */
    uint8_t unk_14a74[0x4]; /* 0x14A74 [rw] high (intended uint32_t) */
    uint8_t unk_14a78[0x4]; /* 0x14A78 [w] low (intended uint32_t) */
    uint8_t unk_14a7c[0x20]; /* 0x14A7C [w] medium */
    uint8_t unk_14a9c[0x44]; /* 0x14A9C [r] medium */
    uint8_t unk_14ae0[0x4]; /* 0x14AE0 [r] medium (intended uint32_t) */
    uint8_t unk_14ae4[0x4]; /* 0x14AE4 [r] medium (intended uint32_t) */
    uint8_t unk_14ae8[0x4]; /* 0x14AE8 [r] medium (intended uint32_t) */
    uint8_t unk_14aec[0x8]; /* 0x14AEC [r] medium (intended uint64_t) */
    uint8_t unk_14af4[0x4]; /* 0x14AF4 [rw] high (intended uint32_t) */
    uint8_t unk_14af8[0x4]; /* 0x14AF8 [rw] high (intended uint32_t) */
    uint8_t unk_14afc[0x4]; /* 0x14AFC [rw] high (intended uint32_t) */
    uint8_t unk_14b00[0x4]; /* 0x14B00 [rw] high (intended uint32_t) */
    uint8_t unk_14b04[0x14]; /* 0x14B04 [rw] high */
    uint8_t unk_14b18[0x4]; /* 0x14B18 [rw] high (intended uint32_t) */
    uint8_t unk_14b1c[0x4]; /* 0x14B1C [rw] medium (intended uint32_t) */
    uint8_t unk_14b20[0x4]; /* 0x14B20 [rw] high (intended uint32_t) */
    uint8_t unk_14b24[0x10]; /* 0x14B24 [w] high */
    uint8_t unk_14b34[0x4]; /* 0x14B34 [r] medium (intended uint32_t) */
    uint8_t unk_14b38[0x28]; /* 0x14B38 [r] medium */
    uint8_t unk_14b60[0x8]; /* 0x14B60 [rw] medium (intended uint64_t) */
    uint8_t unk_14b68[0x20]; /* 0x14B68 [r] medium */
    uint8_t unk_14b88[0x4]; /* 0x14B88 [rw] low (intended uint32_t) */
    uint8_t unk_14b8c[0x14]; /* 0x14B8C [r] medium */
    uint8_t unk_14ba0[0x8]; /* 0x14BA0 [w] medium (intended uint64_t) */
    uint8_t unk_14ba8[0x4]; /* 0x14BA8 [r] medium (intended uint32_t) */
    uint8_t unk_14bac[0x64]; /* 0x14BAC [r] medium */
    uint8_t unk_14c10[0x4]; /* 0x14C10 [rw] medium (intended uint32_t) */
    uint8_t unk_14c14[0xb4]; /* 0x14C14 [rw] high */
    uint8_t unk_14cc8[0xa4]; /* 0x14CC8 [r] medium */
    uint8_t unk_14d6c[0x4]; /* 0x14D6C [rw] high (intended uint32_t) */
    uint8_t unk_14d70[0x4]; /* 0x14D70 [w] medium (intended uint32_t) */
    uint8_t unk_14d74[0x44]; /* 0x14D74 [w] high */
    uint8_t unk_14db8[0x8]; /* 0x14DB8 [rw] high (intended uint64_t) */
    uint8_t unk_14dc0[0x4]; /* 0x14DC0 [r] low (intended uint32_t) */
    uint8_t unk_14dc4[0x8]; /* 0x14DC4 [rw] high (intended uint64_t) */
    uint8_t unk_14dcc[0x4]; /* 0x14DCC [rw] high (intended uint32_t) */
    uint8_t unk_14dd0[0x8]; /* 0x14DD0 [w] medium (intended uint64_t) */
    uint8_t unk_14dd8[0x40]; /* 0x14DD8 [w] medium */
    uint8_t unk_14e18[0x8]; /* 0x14E18 [r] medium (intended uint64_t) */
    uint8_t unk_14e20[0x188]; /* 0x14E20 [w] medium */
    uint8_t unk_14fa8[0x170]; /* 0x14FA8 [r] medium */
    uint8_t unk_15118[0x8]; /* 0x15118 [r] medium (intended uint64_t) */
    uint8_t unk_15120[0x8]; /* 0x15120 [r] medium (intended uint64_t) */
    uint8_t unk_15128[0x8]; /* 0x15128 [r] medium (intended uint64_t) */
    uint8_t unk_15130[0x78]; /* 0x15130 [r] medium */
    uint8_t unk_151a8[0x8]; /* 0x151A8 [r] medium (intended uint64_t) */
    uint8_t unk_151b0[0x8]; /* 0x151B0 [r] medium (intended uint64_t) */
    uint8_t unk_151b8[0x20]; /* 0x151B8 [r] medium */
    uint8_t unk_151d8[0x8]; /* 0x151D8 [r] medium (intended uint64_t) */
    uint8_t unk_151e0[0x8]; /* 0x151E0 [r] medium (intended uint64_t) */
    uint8_t unk_151e8[0x8]; /* 0x151E8 [r] medium (intended uint64_t) */
    uint8_t unk_151f0[0x10]; /* 0x151F0 [r] medium */
    uint8_t unk_15200[0x8]; /* 0x15200 [r] medium (intended uint64_t) */
    uint8_t unk_15208[0x8]; /* 0x15208 [r] medium (intended uint64_t) */
    uint8_t unk_15210[0x10]; /* 0x15210 [r] medium */
    uint8_t unk_15220[0xf0]; /* 0x15220 [r] medium */
    uint8_t unk_15310[0x440]; /* 0x15310 [r] low */
    uint8_t unk_15750[0x4]; /* 0x15750 [rw] high (intended uint32_t) */
    uint8_t unk_15754[0x4]; /* 0x15754 [r] medium (intended uint32_t) */
    uint8_t unk_15758[0x8]; /* 0x15758 [r] low (intended uint64_t) */
} ccPlayer_t;

static_assert(sizeof(ccPlayer_t) == 0x15760, "ccPlayer base size");

static_assert(offsetof(ccPlayer_t, unk_40) == 0x40, "unk_40 offset");
static_assert(offsetof(ccPlayer_t, unk_48) == 0x48, "unk_48 offset");
static_assert(offsetof(ccPlayer_t, unk_50) == 0x50, "unk_50 offset");
static_assert(offsetof(ccPlayer_t, unk_58) == 0x58, "unk_58 offset");
static_assert(offsetof(ccPlayer_t, anim_state) == 0x70, "anim_state offset");
static_assert(offsetof(ccPlayer_t, unk_74) == 0x74, "unk_74 offset");
static_assert(offsetof(ccPlayer_t, unk_78) == 0x78, "unk_78 offset");
static_assert(offsetof(ccPlayer_t, unk_80) == 0x80, "unk_80 offset");
static_assert(offsetof(ccPlayer_t, anim_state_1) == 0x90, "anim_state_1 offset");
static_assert(offsetof(ccPlayer_t, unk_98) == 0x98, "unk_98 offset");
static_assert(offsetof(ccPlayer_t, anim_state_2) == 0x9C, "anim_state_2 offset");
static_assert(offsetof(ccPlayer_t, unk_a0) == 0xA0, "unk_a0 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos) == 0xA4, "combo_throw_pos offset");
static_assert(offsetof(ccPlayer_t, anim_state_3) == 0xA8, "anim_state_3 offset");
static_assert(offsetof(ccPlayer_t, throw_ctrl) == 0xB0, "throw_ctrl offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl) == 0xB4, "atk_ctrl offset");
static_assert(offsetof(ccPlayer_t, unk_b8) == 0xB8, "unk_b8 offset");
static_assert(offsetof(ccPlayer_t, unk_bc) == 0xBC, "unk_bc offset");
static_assert(offsetof(ccPlayer_t, unk_c0) == 0xC0, "unk_c0 offset");
static_assert(offsetof(ccPlayer_t, unk_c8) == 0xC8, "unk_c8 offset");
static_assert(offsetof(ccPlayer_t, unk_cc) == 0xCC, "unk_cc offset");
static_assert(offsetof(ccPlayer_t, unk_d4) == 0xD4, "unk_d4 offset");
static_assert(offsetof(ccPlayer_t, unk_dc) == 0xDC, "unk_dc offset");
static_assert(offsetof(ccPlayer_t, unk_e4) == 0xE4, "unk_e4 offset");
static_assert(offsetof(ccPlayer_t, unk_ec) == 0xEC, "unk_ec offset");
static_assert(offsetof(ccPlayer_t, unk_f4) == 0xF4, "unk_f4 offset");
static_assert(offsetof(ccPlayer_t, unk_fc) == 0xFC, "unk_fc offset");
static_assert(offsetof(ccPlayer_t, unk_104) == 0x104, "unk_104 offset");
static_assert(offsetof(ccPlayer_t, anim_state_4) == 0x108, "anim_state_4 offset");
static_assert(offsetof(ccPlayer_t, unk_148) == 0x148, "unk_148 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_1) == 0x150, "chakra_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_1) == 0x154, "atk_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, unk_158) == 0x158, "unk_158 offset");
static_assert(offsetof(ccPlayer_t, chakra_ctrl_2) == 0x15C, "chakra_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, unk_160) == 0x160, "unk_160 offset");
static_assert(offsetof(ccPlayer_t, action_state) == 0x164, "action_state offset");
static_assert(offsetof(ccPlayer_t, unk_168) == 0x168, "unk_168 offset");
static_assert(offsetof(ccPlayer_t, unk_16c) == 0x16C, "unk_16c offset");
static_assert(offsetof(ccPlayer_t, unk_170) == 0x170, "unk_170 offset");
static_assert(offsetof(ccPlayer_t, unk_174) == 0x174, "unk_174 offset");
static_assert(offsetof(ccPlayer_t, unk_17c) == 0x17C, "unk_17c offset");
static_assert(offsetof(ccPlayer_t, unk_184) == 0x184, "unk_184 offset");
static_assert(offsetof(ccPlayer_t, unk_188) == 0x188, "unk_188 offset");
static_assert(offsetof(ccPlayer_t, unk_18c) == 0x18C, "unk_18c offset");
static_assert(offsetof(ccPlayer_t, unk_190) == 0x190, "unk_190 offset");
static_assert(offsetof(ccPlayer_t, unk_194) == 0x194, "unk_194 offset");
static_assert(offsetof(ccPlayer_t, unk_19c) == 0x19C, "unk_19c offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_1) == 0x1A0, "combo_throw_pos_1 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_2) == 0x1A8, "combo_throw_pos_2 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_3) == 0x1AC, "combo_throw_pos_3 offset");
static_assert(offsetof(ccPlayer_t, combo_throw_pos_4) == 0x1B4, "combo_throw_pos_4 offset");
static_assert(offsetof(ccPlayer_t, unk_1b8) == 0x1B8, "unk_1b8 offset");
static_assert(offsetof(ccPlayer_t, unk_1c0) == 0x1C0, "unk_1c0 offset");
static_assert(offsetof(ccPlayer_t, action_state_1) == 0x200, "action_state_1 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_4) == 0x208, "atk_ctrl_4 offset");
static_assert(offsetof(ccPlayer_t, unk_218) == 0x218, "unk_218 offset");
static_assert(offsetof(ccPlayer_t, unk_240) == 0x240, "unk_240 offset");
static_assert(offsetof(ccPlayer_t, unk_280) == 0x280, "unk_280 offset");
static_assert(offsetof(ccPlayer_t, unk_2c0) == 0x2C0, "unk_2c0 offset");
static_assert(offsetof(ccPlayer_t, unk_380) == 0x380, "unk_380 offset");
static_assert(offsetof(ccPlayer_t, unk_440) == 0x440, "unk_440 offset");
static_assert(offsetof(ccPlayer_t, unk_480) == 0x480, "unk_480 offset");
static_assert(offsetof(ccPlayer_t, unk_4c0) == 0x4C0, "unk_4c0 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_1) == 0x62C, "dmg_ctrl_1 offset");
static_assert(offsetof(ccPlayer_t, unk_634) == 0x634, "unk_634 offset");
static_assert(offsetof(ccPlayer_t, unk_8e0) == 0x8E0, "unk_8e0 offset");
static_assert(offsetof(ccPlayer_t, action_state_11) == 0xB00, "action_state_11 offset");
static_assert(offsetof(ccPlayer_t, anim_state_8) == 0xB18, "anim_state_8 offset");
static_assert(offsetof(ccPlayer_t, unk_b38) == 0xB38, "unk_b38 offset");
static_assert(offsetof(ccPlayer_t, unk_bf8) == 0xBF8, "unk_bf8 offset");
static_assert(offsetof(ccPlayer_t, unk_c00) == 0xC00, "unk_c00 offset");
static_assert(offsetof(ccPlayer_t, unk_c74) == 0xC74, "unk_c74 offset");
static_assert(offsetof(ccPlayer_t, unk_c7c) == 0xC7C, "unk_c7c offset");
static_assert(offsetof(ccPlayer_t, unk_c88) == 0xC88, "unk_c88 offset");
static_assert(offsetof(ccPlayer_t, unk_c8c) == 0xC8C, "unk_c8c offset");
static_assert(offsetof(ccPlayer_t, unk_c94) == 0xC94, "unk_c94 offset");
static_assert(offsetof(ccPlayer_t, unk_ca0) == 0xCA0, "unk_ca0 offset");
static_assert(offsetof(ccPlayer_t, unk_ca8) == 0xCA8, "unk_ca8 offset");
static_assert(offsetof(ccPlayer_t, unk_cac) == 0xCAC, "unk_cac offset");
static_assert(offsetof(ccPlayer_t, unk_cb0) == 0xCB0, "unk_cb0 offset");
static_assert(offsetof(ccPlayer_t, unk_cb4) == 0xCB4, "unk_cb4 offset");
static_assert(offsetof(ccPlayer_t, unk_cbc) == 0xCBC, "unk_cbc offset");
static_assert(offsetof(ccPlayer_t, anim_state_9) == 0xCC0, "anim_state_9 offset");
static_assert(offsetof(ccPlayer_t, unk_cc4) == 0xCC4, "unk_cc4 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_12) == 0xCC8, "dmg_ctrl_12 offset");
static_assert(offsetof(ccPlayer_t, unk_ccc) == 0xCCC, "unk_ccc offset");
static_assert(offsetof(ccPlayer_t, action_state_12) == 0xCD0, "action_state_12 offset");
static_assert(offsetof(ccPlayer_t, unk_cd4) == 0xCD4, "unk_cd4 offset");
static_assert(offsetof(ccPlayer_t, unk_cd8) == 0xCD8, "unk_cd8 offset");
static_assert(offsetof(ccPlayer_t, action_state_13) == 0xCDC, "action_state_13 offset");
static_assert(offsetof(ccPlayer_t, unk_cf4) == 0xCF4, "unk_cf4 offset");
static_assert(offsetof(ccPlayer_t, unk_cf8) == 0xCF8, "unk_cf8 offset");
static_assert(offsetof(ccPlayer_t, unk_cfc) == 0xCFC, "unk_cfc offset");
static_assert(offsetof(ccPlayer_t, unk_d08) == 0xD08, "unk_d08 offset");
static_assert(offsetof(ccPlayer_t, unk_d0c) == 0xD0C, "unk_d0c offset");
static_assert(offsetof(ccPlayer_t, unk_d10) == 0xD10, "unk_d10 offset");
static_assert(offsetof(ccPlayer_t, unk_d14) == 0xD14, "unk_d14 offset");
static_assert(offsetof(ccPlayer_t, unk_d18) == 0xD18, "unk_d18 offset");
static_assert(offsetof(ccPlayer_t, unk_d1c) == 0xD1C, "unk_d1c offset");
static_assert(offsetof(ccPlayer_t, unk_d20) == 0xD20, "unk_d20 offset");
static_assert(offsetof(ccPlayer_t, unk_d24) == 0xD24, "unk_d24 offset");
static_assert(offsetof(ccPlayer_t, unk_d3c) == 0xD3C, "unk_d3c offset");
static_assert(offsetof(ccPlayer_t, unk_d40) == 0xD40, "unk_d40 offset");
static_assert(offsetof(ccPlayer_t, unk_d44) == 0xD44, "unk_d44 offset");
static_assert(offsetof(ccPlayer_t, unk_d50) == 0xD50, "unk_d50 offset");
static_assert(offsetof(ccPlayer_t, unk_d54) == 0xD54, "unk_d54 offset");
static_assert(offsetof(ccPlayer_t, unk_d58) == 0xD58, "unk_d58 offset");
static_assert(offsetof(ccPlayer_t, unk_d5c) == 0xD5C, "unk_d5c offset");
static_assert(offsetof(ccPlayer_t, unk_d64) == 0xD64, "unk_d64 offset");
static_assert(offsetof(ccPlayer_t, unk_f64) == 0xF64, "unk_f64 offset");
static_assert(offsetof(ccPlayer_t, unk_f74) == 0xF74, "unk_f74 offset");
static_assert(offsetof(ccPlayer_t, unk_f7c) == 0xF7C, "unk_f7c offset");
static_assert(offsetof(ccPlayer_t, unk_f80) == 0xF80, "unk_f80 offset");
static_assert(offsetof(ccPlayer_t, unk_f84) == 0xF84, "unk_f84 offset");
static_assert(offsetof(ccPlayer_t, unk_f88) == 0xF88, "unk_f88 offset");
static_assert(offsetof(ccPlayer_t, unk_f8c) == 0xF8C, "unk_f8c offset");
static_assert(offsetof(ccPlayer_t, unk_f90) == 0xF90, "unk_f90 offset");
static_assert(offsetof(ccPlayer_t, unk_f94) == 0xF94, "unk_f94 offset");
static_assert(offsetof(ccPlayer_t, unk_fa4) == 0xFA4, "unk_fa4 offset");
static_assert(offsetof(ccPlayer_t, unk_fac) == 0xFAC, "unk_fac offset");
static_assert(offsetof(ccPlayer_t, unk_fb0) == 0xFB0, "unk_fb0 offset");
static_assert(offsetof(ccPlayer_t, unk_fbc) == 0xFBC, "unk_fbc offset");
static_assert(offsetof(ccPlayer_t, unk_fc0) == 0xFC0, "unk_fc0 offset");
static_assert(offsetof(ccPlayer_t, unk_fdc) == 0xFDC, "unk_fdc offset");
static_assert(offsetof(ccPlayer_t, unk_fe0) == 0xFE0, "unk_fe0 offset");
static_assert(offsetof(ccPlayer_t, unk_fec) == 0xFEC, "unk_fec offset");
static_assert(offsetof(ccPlayer_t, unk_ff0) == 0xFF0, "unk_ff0 offset");
static_assert(offsetof(ccPlayer_t, unk_ff4) == 0xFF4, "unk_ff4 offset");
static_assert(offsetof(ccPlayer_t, unk_ff8) == 0xFF8, "unk_ff8 offset");
static_assert(offsetof(ccPlayer_t, unk_ffc) == 0xFFC, "unk_ffc offset");
static_assert(offsetof(ccPlayer_t, unk_1004) == 0x1004, "unk_1004 offset");
static_assert(offsetof(ccPlayer_t, unk_1008) == 0x1008, "unk_1008 offset");
static_assert(offsetof(ccPlayer_t, unk_100c) == 0x100C, "unk_100c offset");
static_assert(offsetof(ccPlayer_t, unk_101c) == 0x101C, "unk_101c offset");
static_assert(offsetof(ccPlayer_t, unk_1024) == 0x1024, "unk_1024 offset");
static_assert(offsetof(ccPlayer_t, unk_1034) == 0x1034, "unk_1034 offset");
static_assert(offsetof(ccPlayer_t, unk_1038) == 0x1038, "unk_1038 offset");
static_assert(offsetof(ccPlayer_t, unk_1044) == 0x1044, "unk_1044 offset");
static_assert(offsetof(ccPlayer_t, unk_1048) == 0x1048, "unk_1048 offset");
static_assert(offsetof(ccPlayer_t, unk_1050) == 0x1050, "unk_1050 offset");
static_assert(offsetof(ccPlayer_t, unk_1058) == 0x1058, "unk_1058 offset");
static_assert(offsetof(ccPlayer_t, unk_1060) == 0x1060, "unk_1060 offset");
static_assert(offsetof(ccPlayer_t, unk_1068) == 0x1068, "unk_1068 offset");
static_assert(offsetof(ccPlayer_t, unk_1078) == 0x1078, "unk_1078 offset");
static_assert(offsetof(ccPlayer_t, unk_107c) == 0x107C, "unk_107c offset");
static_assert(offsetof(ccPlayer_t, unk_1080) == 0x1080, "unk_1080 offset");
static_assert(offsetof(ccPlayer_t, unk_1084) == 0x1084, "unk_1084 offset");
static_assert(offsetof(ccPlayer_t, unk_1088) == 0x1088, "unk_1088 offset");
static_assert(offsetof(ccPlayer_t, unk_108c) == 0x108C, "unk_108c offset");
static_assert(offsetof(ccPlayer_t, unk_1090) == 0x1090, "unk_1090 offset");
static_assert(offsetof(ccPlayer_t, unk_109c) == 0x109C, "unk_109c offset");
static_assert(offsetof(ccPlayer_t, unk_10a0) == 0x10A0, "unk_10a0 offset");
static_assert(offsetof(ccPlayer_t, unk_10a4) == 0x10A4, "unk_10a4 offset");
static_assert(offsetof(ccPlayer_t, unk_10ac) == 0x10AC, "unk_10ac offset");
static_assert(offsetof(ccPlayer_t, unk_10b0) == 0x10B0, "unk_10b0 offset");
static_assert(offsetof(ccPlayer_t, unk_10b4) == 0x10B4, "unk_10b4 offset");
static_assert(offsetof(ccPlayer_t, unk_10bc) == 0x10BC, "unk_10bc offset");
static_assert(offsetof(ccPlayer_t, unk_10c0) == 0x10C0, "unk_10c0 offset");
static_assert(offsetof(ccPlayer_t, unk_1540) == 0x1540, "unk_1540 offset");
static_assert(offsetof(ccPlayer_t, unk_1614) == 0x1614, "unk_1614 offset");
static_assert(offsetof(ccPlayer_t, unk_177c) == 0x177C, "unk_177c offset");
static_assert(offsetof(ccPlayer_t, unk_17a4) == 0x17A4, "unk_17a4 offset");
static_assert(offsetof(ccPlayer_t, unk_17a8) == 0x17A8, "unk_17a8 offset");
static_assert(offsetof(ccPlayer_t, unk_17b0) == 0x17B0, "unk_17b0 offset");
static_assert(offsetof(ccPlayer_t, unk_17b4) == 0x17B4, "unk_17b4 offset");
static_assert(offsetof(ccPlayer_t, unk_17b8) == 0x17B8, "unk_17b8 offset");
static_assert(offsetof(ccPlayer_t, unk_17e8) == 0x17E8, "unk_17e8 offset");
static_assert(offsetof(ccPlayer_t, unk_1984) == 0x1984, "unk_1984 offset");
static_assert(offsetof(ccPlayer_t, unk_2180) == 0x2180, "unk_2180 offset");
static_assert(offsetof(ccPlayer_t, unk_58c0) == 0x58C0, "unk_58c0 offset");
static_assert(offsetof(ccPlayer_t, unk_5a80) == 0x5A80, "unk_5a80 offset");
static_assert(offsetof(ccPlayer_t, unk_5b00) == 0x5B00, "unk_5b00 offset");
static_assert(offsetof(ccPlayer_t, unk_5b80) == 0x5B80, "unk_5b80 offset");
static_assert(offsetof(ccPlayer_t, unk_5c00) == 0x5C00, "unk_5c00 offset");
static_assert(offsetof(ccPlayer_t, unk_5c40) == 0x5C40, "unk_5c40 offset");
static_assert(offsetof(ccPlayer_t, unk_5c80) == 0x5C80, "unk_5c80 offset");
static_assert(offsetof(ccPlayer_t, unk_5cc0) == 0x5CC0, "unk_5cc0 offset");
static_assert(offsetof(ccPlayer_t, unk_5d80) == 0x5D80, "unk_5d80 offset");
static_assert(offsetof(ccPlayer_t, unk_5e40) == 0x5E40, "unk_5e40 offset");
static_assert(offsetof(ccPlayer_t, unk_5e80) == 0x5E80, "unk_5e80 offset");
static_assert(offsetof(ccPlayer_t, unk_5ec0) == 0x5EC0, "unk_5ec0 offset");
static_assert(offsetof(ccPlayer_t, unk_6040) == 0x6040, "unk_6040 offset");
static_assert(offsetof(ccPlayer_t, unk_6080) == 0x6080, "unk_6080 offset");
static_assert(offsetof(ccPlayer_t, unk_60c0) == 0x60C0, "unk_60c0 offset");
static_assert(offsetof(ccPlayer_t, unk_6100) == 0x6100, "unk_6100 offset");
static_assert(offsetof(ccPlayer_t, unk_6180) == 0x6180, "unk_6180 offset");
static_assert(offsetof(ccPlayer_t, unk_61c0) == 0x61C0, "unk_61c0 offset");
static_assert(offsetof(ccPlayer_t, unk_6200) == 0x6200, "unk_6200 offset");
static_assert(offsetof(ccPlayer_t, unk_6240) == 0x6240, "unk_6240 offset");
static_assert(offsetof(ccPlayer_t, unk_6280) == 0x6280, "unk_6280 offset");
static_assert(offsetof(ccPlayer_t, unk_6300) == 0x6300, "unk_6300 offset");
static_assert(offsetof(ccPlayer_t, unk_6380) == 0x6380, "unk_6380 offset");
static_assert(offsetof(ccPlayer_t, unk_6400) == 0x6400, "unk_6400 offset");
static_assert(offsetof(ccPlayer_t, unk_6480) == 0x6480, "unk_6480 offset");
static_assert(offsetof(ccPlayer_t, unk_64c0) == 0x64C0, "unk_64c0 offset");
static_assert(offsetof(ccPlayer_t, unk_6540) == 0x6540, "unk_6540 offset");
static_assert(offsetof(ccPlayer_t, unk_65c0) == 0x65C0, "unk_65c0 offset");
static_assert(offsetof(ccPlayer_t, unk_6640) == 0x6640, "unk_6640 offset");
static_assert(offsetof(ccPlayer_t, unk_6680) == 0x6680, "unk_6680 offset");
static_assert(offsetof(ccPlayer_t, unk_6700) == 0x6700, "unk_6700 offset");
static_assert(offsetof(ccPlayer_t, unk_6980) == 0x6980, "unk_6980 offset");
static_assert(offsetof(ccPlayer_t, unk_6ac0) == 0x6AC0, "unk_6ac0 offset");
static_assert(offsetof(ccPlayer_t, unk_6c40) == 0x6C40, "unk_6c40 offset");
static_assert(offsetof(ccPlayer_t, unk_6cc0) == 0x6CC0, "unk_6cc0 offset");
static_assert(offsetof(ccPlayer_t, unk_6d40) == 0x6D40, "unk_6d40 offset");
static_assert(offsetof(ccPlayer_t, unk_6d80) == 0x6D80, "unk_6d80 offset");
static_assert(offsetof(ccPlayer_t, unk_6dc0) == 0x6DC0, "unk_6dc0 offset");
static_assert(offsetof(ccPlayer_t, unk_7000) == 0x7000, "unk_7000 offset");
static_assert(offsetof(ccPlayer_t, unk_7040) == 0x7040, "unk_7040 offset");
static_assert(offsetof(ccPlayer_t, unk_70c0) == 0x70C0, "unk_70c0 offset");
static_assert(offsetof(ccPlayer_t, unk_7100) == 0x7100, "unk_7100 offset");
static_assert(offsetof(ccPlayer_t, unk_7380) == 0x7380, "unk_7380 offset");
static_assert(offsetof(ccPlayer_t, unk_7600) == 0x7600, "unk_7600 offset");
static_assert(offsetof(ccPlayer_t, unk_7700) == 0x7700, "unk_7700 offset");
static_assert(offsetof(ccPlayer_t, unk_7880) == 0x7880, "unk_7880 offset");
static_assert(offsetof(ccPlayer_t, unk_7900) == 0x7900, "unk_7900 offset");
static_assert(offsetof(ccPlayer_t, unk_7940) == 0x7940, "unk_7940 offset");
static_assert(offsetof(ccPlayer_t, unk_7980) == 0x7980, "unk_7980 offset");
static_assert(offsetof(ccPlayer_t, unk_79c0) == 0x79C0, "unk_79c0 offset");
static_assert(offsetof(ccPlayer_t, unk_7a40) == 0x7A40, "unk_7a40 offset");
static_assert(offsetof(ccPlayer_t, unk_7a80) == 0x7A80, "unk_7a80 offset");
static_assert(offsetof(ccPlayer_t, unk_7b00) == 0x7B00, "unk_7b00 offset");
static_assert(offsetof(ccPlayer_t, unk_7b40) == 0x7B40, "unk_7b40 offset");
static_assert(offsetof(ccPlayer_t, unk_7b80) == 0x7B80, "unk_7b80 offset");
static_assert(offsetof(ccPlayer_t, unk_7bc0) == 0x7BC0, "unk_7bc0 offset");
static_assert(offsetof(ccPlayer_t, unk_7e00) == 0x7E00, "unk_7e00 offset");
static_assert(offsetof(ccPlayer_t, unk_7e80) == 0x7E80, "unk_7e80 offset");
static_assert(offsetof(ccPlayer_t, unk_7ec0) == 0x7EC0, "unk_7ec0 offset");
static_assert(offsetof(ccPlayer_t, unk_7f80) == 0x7F80, "unk_7f80 offset");
static_assert(offsetof(ccPlayer_t, throw_ctrl_2) == 0x8000, "throw_ctrl_2 offset");
static_assert(offsetof(ccPlayer_t, unk_8040) == 0x8040, "unk_8040 offset");
static_assert(offsetof(ccPlayer_t, dmg_ctrl_39) == 0x80C0, "dmg_ctrl_39 offset");
static_assert(offsetof(ccPlayer_t, action_state_24) == 0x8100, "action_state_24 offset");
static_assert(offsetof(ccPlayer_t, unk_8180) == 0x8180, "unk_8180 offset");
static_assert(offsetof(ccPlayer_t, action_state_30) == 0x8200, "action_state_30 offset");
static_assert(offsetof(ccPlayer_t, unk_8300) == 0x8300, "unk_8300 offset");
static_assert(offsetof(ccPlayer_t, unk_8380) == 0x8380, "unk_8380 offset");
static_assert(offsetof(ccPlayer_t, unk_84c0) == 0x84C0, "unk_84c0 offset");
static_assert(offsetof(ccPlayer_t, unk_8500) == 0x8500, "unk_8500 offset");
static_assert(offsetof(ccPlayer_t, unk_8540) == 0x8540, "unk_8540 offset");
static_assert(offsetof(ccPlayer_t, unk_8580) == 0x8580, "unk_8580 offset");
static_assert(offsetof(ccPlayer_t, unk_8680) == 0x8680, "unk_8680 offset");
static_assert(offsetof(ccPlayer_t, unk_8700) == 0x8700, "unk_8700 offset");
static_assert(offsetof(ccPlayer_t, unk_8740) == 0x8740, "unk_8740 offset");
static_assert(offsetof(ccPlayer_t, unk_87c0) == 0x87C0, "unk_87c0 offset");
static_assert(offsetof(ccPlayer_t, unk_8800) == 0x8800, "unk_8800 offset");
static_assert(offsetof(ccPlayer_t, unk_8980) == 0x8980, "unk_8980 offset");
static_assert(offsetof(ccPlayer_t, unk_8a00) == 0x8A00, "unk_8a00 offset");
static_assert(offsetof(ccPlayer_t, unk_8a80) == 0x8A80, "unk_8a80 offset");
static_assert(offsetof(ccPlayer_t, unk_8c00) == 0x8C00, "unk_8c00 offset");
static_assert(offsetof(ccPlayer_t, unk_8c80) == 0x8C80, "unk_8c80 offset");
static_assert(offsetof(ccPlayer_t, unk_8dc0) == 0x8DC0, "unk_8dc0 offset");
static_assert(offsetof(ccPlayer_t, unk_8e00) == 0x8E00, "unk_8e00 offset");
static_assert(offsetof(ccPlayer_t, unk_8f00) == 0x8F00, "unk_8f00 offset");
static_assert(offsetof(ccPlayer_t, unk_8f40) == 0x8F40, "unk_8f40 offset");
static_assert(offsetof(ccPlayer_t, unk_9000) == 0x9000, "unk_9000 offset");
static_assert(offsetof(ccPlayer_t, unk_9040) == 0x9040, "unk_9040 offset");
static_assert(offsetof(ccPlayer_t, unk_9080) == 0x9080, "unk_9080 offset");
static_assert(offsetof(ccPlayer_t, unk_91c0) == 0x91C0, "unk_91c0 offset");
static_assert(offsetof(ccPlayer_t, unk_9240) == 0x9240, "unk_9240 offset");
static_assert(offsetof(ccPlayer_t, unk_9280) == 0x9280, "unk_9280 offset");
static_assert(offsetof(ccPlayer_t, unk_9300) == 0x9300, "unk_9300 offset");
static_assert(offsetof(ccPlayer_t, unk_9340) == 0x9340, "unk_9340 offset");
static_assert(offsetof(ccPlayer_t, unk_9400) == 0x9400, "unk_9400 offset");
static_assert(offsetof(ccPlayer_t, unk_9680) == 0x9680, "unk_9680 offset");
static_assert(offsetof(ccPlayer_t, unk_9700) == 0x9700, "unk_9700 offset");
static_assert(offsetof(ccPlayer_t, unk_9740) == 0x9740, "unk_9740 offset");
static_assert(offsetof(ccPlayer_t, unk_97c0) == 0x97C0, "unk_97c0 offset");
static_assert(offsetof(ccPlayer_t, unk_9800) == 0x9800, "unk_9800 offset");
static_assert(offsetof(ccPlayer_t, unk_98c0) == 0x98C0, "unk_98c0 offset");
static_assert(offsetof(ccPlayer_t, unk_9a80) == 0x9A80, "unk_9a80 offset");
static_assert(offsetof(ccPlayer_t, unk_9ac0) == 0x9AC0, "unk_9ac0 offset");
static_assert(offsetof(ccPlayer_t, unk_9b80) == 0x9B80, "unk_9b80 offset");
static_assert(offsetof(ccPlayer_t, unk_9bc0) == 0x9BC0, "unk_9bc0 offset");
static_assert(offsetof(ccPlayer_t, unk_9c80) == 0x9C80, "unk_9c80 offset");
static_assert(offsetof(ccPlayer_t, unk_9d00) == 0x9D00, "unk_9d00 offset");
static_assert(offsetof(ccPlayer_t, unk_9f40) == 0x9F40, "unk_9f40 offset");
static_assert(offsetof(ccPlayer_t, unk_a080) == 0xA080, "unk_a080 offset");
static_assert(offsetof(ccPlayer_t, unk_a0c0) == 0xA0C0, "unk_a0c0 offset");
static_assert(offsetof(ccPlayer_t, atk_ctrl_17) == 0xA140, "atk_ctrl_17 offset");
static_assert(offsetof(ccPlayer_t, unk_a180) == 0xA180, "unk_a180 offset");
static_assert(offsetof(ccPlayer_t, unk_a200) == 0xA200, "unk_a200 offset");
static_assert(offsetof(ccPlayer_t, unk_a240) == 0xA240, "unk_a240 offset");
static_assert(offsetof(ccPlayer_t, unk_a340) == 0xA340, "unk_a340 offset");
static_assert(offsetof(ccPlayer_t, unk_a580) == 0xA580, "unk_a580 offset");
static_assert(offsetof(ccPlayer_t, unk_a5c0) == 0xA5C0, "unk_a5c0 offset");
static_assert(offsetof(ccPlayer_t, unk_a6c0) == 0xA6C0, "unk_a6c0 offset");
static_assert(offsetof(ccPlayer_t, unk_a780) == 0xA780, "unk_a780 offset");
static_assert(offsetof(ccPlayer_t, unk_a840) == 0xA840, "unk_a840 offset");
static_assert(offsetof(ccPlayer_t, unk_a880) == 0xA880, "unk_a880 offset");
static_assert(offsetof(ccPlayer_t, unk_ab00) == 0xAB00, "unk_ab00 offset");
static_assert(offsetof(ccPlayer_t, unk_ab40) == 0xAB40, "unk_ab40 offset");
static_assert(offsetof(ccPlayer_t, unk_b8c0) == 0xB8C0, "unk_b8c0 offset");
static_assert(offsetof(ccPlayer_t, unk_c180) == 0xC180, "unk_c180 offset");
static_assert(offsetof(ccPlayer_t, unk_f3e8) == 0xF3E8, "unk_f3e8 offset");
static_assert(offsetof(ccPlayer_t, unk_f3f0) == 0xF3F0, "unk_f3f0 offset");
static_assert(offsetof(ccPlayer_t, unk_f454) == 0xF454, "unk_f454 offset");
static_assert(offsetof(ccPlayer_t, unk_f7e0) == 0xF7E0, "unk_f7e0 offset");
static_assert(offsetof(ccPlayer_t, unk_f860) == 0xF860, "unk_f860 offset");
static_assert(offsetof(ccPlayer_t, unk_f974) == 0xF974, "unk_f974 offset");
static_assert(offsetof(ccPlayer_t, unk_f980) == 0xF980, "unk_f980 offset");
static_assert(offsetof(ccPlayer_t, unk_fa08) == 0xFA08, "unk_fa08 offset");
static_assert(offsetof(ccPlayer_t, unk_fa10) == 0xFA10, "unk_fa10 offset");
static_assert(offsetof(ccPlayer_t, unk_fa90) == 0xFA90, "unk_fa90 offset");
static_assert(offsetof(ccPlayer_t, unk_fac0) == 0xFAC0, "unk_fac0 offset");
static_assert(offsetof(ccPlayer_t, unk_fae8) == 0xFAE8, "unk_fae8 offset");
static_assert(offsetof(ccPlayer_t, unk_faec) == 0xFAEC, "unk_faec offset");
static_assert(offsetof(ccPlayer_t, unk_faf0) == 0xFAF0, "unk_faf0 offset");
static_assert(offsetof(ccPlayer_t, unk_faf8) == 0xFAF8, "unk_faf8 offset");
static_assert(offsetof(ccPlayer_t, unk_fb00) == 0xFB00, "unk_fb00 offset");
static_assert(offsetof(ccPlayer_t, unk_fb08) == 0xFB08, "unk_fb08 offset");
static_assert(offsetof(ccPlayer_t, unk_fb10) == 0xFB10, "unk_fb10 offset");
static_assert(offsetof(ccPlayer_t, unk_fb18) == 0xFB18, "unk_fb18 offset");
static_assert(offsetof(ccPlayer_t, unk_fb24) == 0xFB24, "unk_fb24 offset");
static_assert(offsetof(ccPlayer_t, unk_fb2c) == 0xFB2C, "unk_fb2c offset");
static_assert(offsetof(ccPlayer_t, unk_fb30) == 0xFB30, "unk_fb30 offset");
static_assert(offsetof(ccPlayer_t, unk_fb38) == 0xFB38, "unk_fb38 offset");
static_assert(offsetof(ccPlayer_t, unk_fb68) == 0xFB68, "unk_fb68 offset");
static_assert(offsetof(ccPlayer_t, unk_fb70) == 0xFB70, "unk_fb70 offset");
static_assert(offsetof(ccPlayer_t, unk_fb74) == 0xFB74, "unk_fb74 offset");
static_assert(offsetof(ccPlayer_t, unk_fb78) == 0xFB78, "unk_fb78 offset");
static_assert(offsetof(ccPlayer_t, unk_fb7c) == 0xFB7C, "unk_fb7c offset");
static_assert(offsetof(ccPlayer_t, unk_fb80) == 0xFB80, "unk_fb80 offset");
static_assert(offsetof(ccPlayer_t, unk_fb84) == 0xFB84, "unk_fb84 offset");
static_assert(offsetof(ccPlayer_t, unk_fb8c) == 0xFB8C, "unk_fb8c offset");
static_assert(offsetof(ccPlayer_t, unk_fb94) == 0xFB94, "unk_fb94 offset");
static_assert(offsetof(ccPlayer_t, unk_fba8) == 0xFBA8, "unk_fba8 offset");
static_assert(offsetof(ccPlayer_t, unk_fbb0) == 0xFBB0, "unk_fbb0 offset");
static_assert(offsetof(ccPlayer_t, unk_fbb4) == 0xFBB4, "unk_fbb4 offset");
static_assert(offsetof(ccPlayer_t, unk_fbb8) == 0xFBB8, "unk_fbb8 offset");
static_assert(offsetof(ccPlayer_t, unk_fbc0) == 0xFBC0, "unk_fbc0 offset");
static_assert(offsetof(ccPlayer_t, unk_fbd0) == 0xFBD0, "unk_fbd0 offset");
static_assert(offsetof(ccPlayer_t, unk_fbe0) == 0xFBE0, "unk_fbe0 offset");
static_assert(offsetof(ccPlayer_t, unk_fbe4) == 0xFBE4, "unk_fbe4 offset");
static_assert(offsetof(ccPlayer_t, unk_fbe8) == 0xFBE8, "unk_fbe8 offset");
static_assert(offsetof(ccPlayer_t, unk_fbec) == 0xFBEC, "unk_fbec offset");
static_assert(offsetof(ccPlayer_t, unk_fbf0) == 0xFBF0, "unk_fbf0 offset");
static_assert(offsetof(ccPlayer_t, unk_fbf4) == 0xFBF4, "unk_fbf4 offset");
static_assert(offsetof(ccPlayer_t, unk_fbfc) == 0xFBFC, "unk_fbfc offset");
static_assert(offsetof(ccPlayer_t, unk_fc00) == 0xFC00, "unk_fc00 offset");
static_assert(offsetof(ccPlayer_t, unk_fc04) == 0xFC04, "unk_fc04 offset");
static_assert(offsetof(ccPlayer_t, unk_fc0c) == 0xFC0C, "unk_fc0c offset");
static_assert(offsetof(ccPlayer_t, unk_fc10) == 0xFC10, "unk_fc10 offset");
static_assert(offsetof(ccPlayer_t, unk_fc14) == 0xFC14, "unk_fc14 offset");
static_assert(offsetof(ccPlayer_t, unk_fc18) == 0xFC18, "unk_fc18 offset");
static_assert(offsetof(ccPlayer_t, unk_fc24) == 0xFC24, "unk_fc24 offset");
static_assert(offsetof(ccPlayer_t, unk_fc90) == 0xFC90, "unk_fc90 offset");
static_assert(offsetof(ccPlayer_t, unk_fca0) == 0xFCA0, "unk_fca0 offset");
static_assert(offsetof(ccPlayer_t, unk_fca4) == 0xFCA4, "unk_fca4 offset");
static_assert(offsetof(ccPlayer_t, unk_fca8) == 0xFCA8, "unk_fca8 offset");
static_assert(offsetof(ccPlayer_t, unk_fcb0) == 0xFCB0, "unk_fcb0 offset");
static_assert(offsetof(ccPlayer_t, unk_fcb4) == 0xFCB4, "unk_fcb4 offset");
static_assert(offsetof(ccPlayer_t, unk_fcb8) == 0xFCB8, "unk_fcb8 offset");
static_assert(offsetof(ccPlayer_t, unk_fcbc) == 0xFCBC, "unk_fcbc offset");
static_assert(offsetof(ccPlayer_t, unk_fcc0) == 0xFCC0, "unk_fcc0 offset");
static_assert(offsetof(ccPlayer_t, unk_fcc8) == 0xFCC8, "unk_fcc8 offset");
static_assert(offsetof(ccPlayer_t, unk_fccc) == 0xFCCC, "unk_fccc offset");
static_assert(offsetof(ccPlayer_t, unk_fcd0) == 0xFCD0, "unk_fcd0 offset");
static_assert(offsetof(ccPlayer_t, unk_fcd4) == 0xFCD4, "unk_fcd4 offset");
static_assert(offsetof(ccPlayer_t, unk_fcd8) == 0xFCD8, "unk_fcd8 offset");
static_assert(offsetof(ccPlayer_t, unk_fce8) == 0xFCE8, "unk_fce8 offset");
static_assert(offsetof(ccPlayer_t, unk_fcf0) == 0xFCF0, "unk_fcf0 offset");
static_assert(offsetof(ccPlayer_t, unk_fd10) == 0xFD10, "unk_fd10 offset");
static_assert(offsetof(ccPlayer_t, unk_fd20) == 0xFD20, "unk_fd20 offset");
static_assert(offsetof(ccPlayer_t, unk_fd28) == 0xFD28, "unk_fd28 offset");
static_assert(offsetof(ccPlayer_t, unk_fd48) == 0xFD48, "unk_fd48 offset");
static_assert(offsetof(ccPlayer_t, unk_fd4c) == 0xFD4C, "unk_fd4c offset");
static_assert(offsetof(ccPlayer_t, unk_fd50) == 0xFD50, "unk_fd50 offset");
static_assert(offsetof(ccPlayer_t, unk_fd54) == 0xFD54, "unk_fd54 offset");
static_assert(offsetof(ccPlayer_t, unk_fd58) == 0xFD58, "unk_fd58 offset");
static_assert(offsetof(ccPlayer_t, unk_fd5c) == 0xFD5C, "unk_fd5c offset");
static_assert(offsetof(ccPlayer_t, unk_fd74) == 0xFD74, "unk_fd74 offset");
static_assert(offsetof(ccPlayer_t, unk_fd78) == 0xFD78, "unk_fd78 offset");
static_assert(offsetof(ccPlayer_t, unk_fd7c) == 0xFD7C, "unk_fd7c offset");
static_assert(offsetof(ccPlayer_t, unk_fd90) == 0xFD90, "unk_fd90 offset");
static_assert(offsetof(ccPlayer_t, unk_fda0) == 0xFDA0, "unk_fda0 offset");
static_assert(offsetof(ccPlayer_t, unk_fe10) == 0xFE10, "unk_fe10 offset");
static_assert(offsetof(ccPlayer_t, unk_fe14) == 0xFE14, "unk_fe14 offset");
static_assert(offsetof(ccPlayer_t, unk_fe18) == 0xFE18, "unk_fe18 offset");
static_assert(offsetof(ccPlayer_t, unk_fe1c) == 0xFE1C, "unk_fe1c offset");
static_assert(offsetof(ccPlayer_t, unk_fe20) == 0xFE20, "unk_fe20 offset");
static_assert(offsetof(ccPlayer_t, unk_fe38) == 0xFE38, "unk_fe38 offset");
static_assert(offsetof(ccPlayer_t, unk_fe44) == 0xFE44, "unk_fe44 offset");
static_assert(offsetof(ccPlayer_t, unk_fe80) == 0xFE80, "unk_fe80 offset");
static_assert(offsetof(ccPlayer_t, unk_fe88) == 0xFE88, "unk_fe88 offset");
static_assert(offsetof(ccPlayer_t, unk_fe90) == 0xFE90, "unk_fe90 offset");
static_assert(offsetof(ccPlayer_t, unk_fec8) == 0xFEC8, "unk_fec8 offset");
static_assert(offsetof(ccPlayer_t, unk_fed0) == 0xFED0, "unk_fed0 offset");
static_assert(offsetof(ccPlayer_t, unk_fee0) == 0xFEE0, "unk_fee0 offset");
static_assert(offsetof(ccPlayer_t, unk_1013c) == 0x1013C, "unk_1013c offset");
static_assert(offsetof(ccPlayer_t, unk_1015c) == 0x1015C, "unk_1015c offset");
static_assert(offsetof(ccPlayer_t, unk_13fe0) == 0x13FE0, "unk_13fe0 offset");
static_assert(offsetof(ccPlayer_t, unk_13ff0) == 0x13FF0, "unk_13ff0 offset");
static_assert(offsetof(ccPlayer_t, unk_14010) == 0x14010, "unk_14010 offset");
static_assert(offsetof(ccPlayer_t, unk_14014) == 0x14014, "unk_14014 offset");
static_assert(offsetof(ccPlayer_t, unk_14020) == 0x14020, "unk_14020 offset");
static_assert(offsetof(ccPlayer_t, unk_14024) == 0x14024, "unk_14024 offset");
static_assert(offsetof(ccPlayer_t, unk_14028) == 0x14028, "unk_14028 offset");
static_assert(offsetof(ccPlayer_t, unk_1402c) == 0x1402C, "unk_1402c offset");
static_assert(offsetof(ccPlayer_t, unk_14034) == 0x14034, "unk_14034 offset");
static_assert(offsetof(ccPlayer_t, unk_1404c) == 0x1404C, "unk_1404c offset");
static_assert(offsetof(ccPlayer_t, unk_14050) == 0x14050, "unk_14050 offset");
static_assert(offsetof(ccPlayer_t, unk_14054) == 0x14054, "unk_14054 offset");
static_assert(offsetof(ccPlayer_t, unk_14058) == 0x14058, "unk_14058 offset");
static_assert(offsetof(ccPlayer_t, unk_1405c) == 0x1405C, "unk_1405c offset");
static_assert(offsetof(ccPlayer_t, unk_14060) == 0x14060, "unk_14060 offset");
static_assert(offsetof(ccPlayer_t, unk_14068) == 0x14068, "unk_14068 offset");
static_assert(offsetof(ccPlayer_t, unk_14070) == 0x14070, "unk_14070 offset");
static_assert(offsetof(ccPlayer_t, unk_14078) == 0x14078, "unk_14078 offset");
static_assert(offsetof(ccPlayer_t, unk_14080) == 0x14080, "unk_14080 offset");
static_assert(offsetof(ccPlayer_t, unk_14088) == 0x14088, "unk_14088 offset");
static_assert(offsetof(ccPlayer_t, unk_14090) == 0x14090, "unk_14090 offset");
static_assert(offsetof(ccPlayer_t, unk_14098) == 0x14098, "unk_14098 offset");
static_assert(offsetof(ccPlayer_t, unk_140a0) == 0x140A0, "unk_140a0 offset");
static_assert(offsetof(ccPlayer_t, unk_140a2) == 0x140A2, "unk_140a2 offset");
static_assert(offsetof(ccPlayer_t, unk_140a4) == 0x140A4, "unk_140a4 offset");
static_assert(offsetof(ccPlayer_t, unk_140a6) == 0x140A6, "unk_140a6 offset");
static_assert(offsetof(ccPlayer_t, unk_140a8) == 0x140A8, "unk_140a8 offset");
static_assert(offsetof(ccPlayer_t, unk_140ac) == 0x140AC, "unk_140ac offset");
static_assert(offsetof(ccPlayer_t, unk_140b0) == 0x140B0, "unk_140b0 offset");
static_assert(offsetof(ccPlayer_t, unk_140b4) == 0x140B4, "unk_140b4 offset");
static_assert(offsetof(ccPlayer_t, unk_140b8) == 0x140B8, "unk_140b8 offset");
static_assert(offsetof(ccPlayer_t, unk_140bc) == 0x140BC, "unk_140bc offset");
static_assert(offsetof(ccPlayer_t, unk_140c0) == 0x140C0, "unk_140c0 offset");
static_assert(offsetof(ccPlayer_t, unk_140c4) == 0x140C4, "unk_140c4 offset");
static_assert(offsetof(ccPlayer_t, unk_140c8) == 0x140C8, "unk_140c8 offset");
static_assert(offsetof(ccPlayer_t, unk_140d8) == 0x140D8, "unk_140d8 offset");
static_assert(offsetof(ccPlayer_t, unk_140e0) == 0x140E0, "unk_140e0 offset");
static_assert(offsetof(ccPlayer_t, unk_140ec) == 0x140EC, "unk_140ec offset");
static_assert(offsetof(ccPlayer_t, unk_140f0) == 0x140F0, "unk_140f0 offset");
static_assert(offsetof(ccPlayer_t, unk_140f4) == 0x140F4, "unk_140f4 offset");
static_assert(offsetof(ccPlayer_t, unk_140f8) == 0x140F8, "unk_140f8 offset");
static_assert(offsetof(ccPlayer_t, unk_140fc) == 0x140FC, "unk_140fc offset");
static_assert(offsetof(ccPlayer_t, unk_14100) == 0x14100, "unk_14100 offset");
static_assert(offsetof(ccPlayer_t, unk_14104) == 0x14104, "unk_14104 offset");
static_assert(offsetof(ccPlayer_t, unk_14108) == 0x14108, "unk_14108 offset");
static_assert(offsetof(ccPlayer_t, unk_1410c) == 0x1410C, "unk_1410c offset");
static_assert(offsetof(ccPlayer_t, unk_14110) == 0x14110, "unk_14110 offset");
static_assert(offsetof(ccPlayer_t, unk_14118) == 0x14118, "unk_14118 offset");
static_assert(offsetof(ccPlayer_t, unk_14120) == 0x14120, "unk_14120 offset");
static_assert(offsetof(ccPlayer_t, unk_14158) == 0x14158, "unk_14158 offset");
static_assert(offsetof(ccPlayer_t, unk_1415c) == 0x1415C, "unk_1415c offset");
static_assert(offsetof(ccPlayer_t, unk_14164) == 0x14164, "unk_14164 offset");
static_assert(offsetof(ccPlayer_t, unk_14170) == 0x14170, "unk_14170 offset");
static_assert(offsetof(ccPlayer_t, unk_14188) == 0x14188, "unk_14188 offset");
static_assert(offsetof(ccPlayer_t, unk_1418c) == 0x1418C, "unk_1418c offset");
static_assert(offsetof(ccPlayer_t, unk_14194) == 0x14194, "unk_14194 offset");
static_assert(offsetof(ccPlayer_t, unk_1419c) == 0x1419C, "unk_1419c offset");
static_assert(offsetof(ccPlayer_t, unk_141a4) == 0x141A4, "unk_141a4 offset");
static_assert(offsetof(ccPlayer_t, unk_141a8) == 0x141A8, "unk_141a8 offset");
static_assert(offsetof(ccPlayer_t, unk_141ac) == 0x141AC, "unk_141ac offset");
static_assert(offsetof(ccPlayer_t, unk_141b0) == 0x141B0, "unk_141b0 offset");
static_assert(offsetof(ccPlayer_t, unk_141b4) == 0x141B4, "unk_141b4 offset");
static_assert(offsetof(ccPlayer_t, unk_141b8) == 0x141B8, "unk_141b8 offset");
static_assert(offsetof(ccPlayer_t, unk_141bc) == 0x141BC, "unk_141bc offset");
static_assert(offsetof(ccPlayer_t, unk_141c4) == 0x141C4, "unk_141c4 offset");
static_assert(offsetof(ccPlayer_t, unk_141c8) == 0x141C8, "unk_141c8 offset");
static_assert(offsetof(ccPlayer_t, unk_141cc) == 0x141CC, "unk_141cc offset");
static_assert(offsetof(ccPlayer_t, unk_141d4) == 0x141D4, "unk_141d4 offset");
static_assert(offsetof(ccPlayer_t, unk_141d8) == 0x141D8, "unk_141d8 offset");
static_assert(offsetof(ccPlayer_t, unk_141dc) == 0x141DC, "unk_141dc offset");
static_assert(offsetof(ccPlayer_t, unk_141e0) == 0x141E0, "unk_141e0 offset");
static_assert(offsetof(ccPlayer_t, unk_141e4) == 0x141E4, "unk_141e4 offset");
static_assert(offsetof(ccPlayer_t, unk_141e8) == 0x141E8, "unk_141e8 offset");
static_assert(offsetof(ccPlayer_t, unk_141ec) == 0x141EC, "unk_141ec offset");
static_assert(offsetof(ccPlayer_t, unk_141fc) == 0x141FC, "unk_141fc offset");
static_assert(offsetof(ccPlayer_t, unk_14208) == 0x14208, "unk_14208 offset");
static_assert(offsetof(ccPlayer_t, unk_14214) == 0x14214, "unk_14214 offset");
static_assert(offsetof(ccPlayer_t, unk_14a18) == 0x14A18, "unk_14a18 offset");
static_assert(offsetof(ccPlayer_t, unk_14a20) == 0x14A20, "unk_14a20 offset");
static_assert(offsetof(ccPlayer_t, unk_14a48) == 0x14A48, "unk_14a48 offset");
static_assert(offsetof(ccPlayer_t, unk_14a50) == 0x14A50, "unk_14a50 offset");
static_assert(offsetof(ccPlayer_t, unk_14a70) == 0x14A70, "unk_14a70 offset");
static_assert(offsetof(ccPlayer_t, unk_14a74) == 0x14A74, "unk_14a74 offset");
static_assert(offsetof(ccPlayer_t, unk_14a78) == 0x14A78, "unk_14a78 offset");
static_assert(offsetof(ccPlayer_t, unk_14a7c) == 0x14A7C, "unk_14a7c offset");
static_assert(offsetof(ccPlayer_t, unk_14a9c) == 0x14A9C, "unk_14a9c offset");
static_assert(offsetof(ccPlayer_t, unk_14ae0) == 0x14AE0, "unk_14ae0 offset");
static_assert(offsetof(ccPlayer_t, unk_14ae4) == 0x14AE4, "unk_14ae4 offset");
static_assert(offsetof(ccPlayer_t, unk_14ae8) == 0x14AE8, "unk_14ae8 offset");
static_assert(offsetof(ccPlayer_t, unk_14aec) == 0x14AEC, "unk_14aec offset");
static_assert(offsetof(ccPlayer_t, unk_14af4) == 0x14AF4, "unk_14af4 offset");
static_assert(offsetof(ccPlayer_t, unk_14af8) == 0x14AF8, "unk_14af8 offset");
static_assert(offsetof(ccPlayer_t, unk_14afc) == 0x14AFC, "unk_14afc offset");
static_assert(offsetof(ccPlayer_t, unk_14b00) == 0x14B00, "unk_14b00 offset");
static_assert(offsetof(ccPlayer_t, unk_14b04) == 0x14B04, "unk_14b04 offset");
static_assert(offsetof(ccPlayer_t, unk_14b18) == 0x14B18, "unk_14b18 offset");
static_assert(offsetof(ccPlayer_t, unk_14b1c) == 0x14B1C, "unk_14b1c offset");
static_assert(offsetof(ccPlayer_t, unk_14b20) == 0x14B20, "unk_14b20 offset");
static_assert(offsetof(ccPlayer_t, unk_14b24) == 0x14B24, "unk_14b24 offset");
static_assert(offsetof(ccPlayer_t, unk_14b34) == 0x14B34, "unk_14b34 offset");
static_assert(offsetof(ccPlayer_t, unk_14b38) == 0x14B38, "unk_14b38 offset");
static_assert(offsetof(ccPlayer_t, unk_14b60) == 0x14B60, "unk_14b60 offset");
static_assert(offsetof(ccPlayer_t, unk_14b68) == 0x14B68, "unk_14b68 offset");
static_assert(offsetof(ccPlayer_t, unk_14b88) == 0x14B88, "unk_14b88 offset");
static_assert(offsetof(ccPlayer_t, unk_14b8c) == 0x14B8C, "unk_14b8c offset");
static_assert(offsetof(ccPlayer_t, unk_14ba0) == 0x14BA0, "unk_14ba0 offset");
static_assert(offsetof(ccPlayer_t, unk_14ba8) == 0x14BA8, "unk_14ba8 offset");
static_assert(offsetof(ccPlayer_t, unk_14bac) == 0x14BAC, "unk_14bac offset");
static_assert(offsetof(ccPlayer_t, unk_14c10) == 0x14C10, "unk_14c10 offset");
static_assert(offsetof(ccPlayer_t, unk_14c14) == 0x14C14, "unk_14c14 offset");
static_assert(offsetof(ccPlayer_t, unk_14cc8) == 0x14CC8, "unk_14cc8 offset");
static_assert(offsetof(ccPlayer_t, unk_14d6c) == 0x14D6C, "unk_14d6c offset");
static_assert(offsetof(ccPlayer_t, unk_14d70) == 0x14D70, "unk_14d70 offset");
static_assert(offsetof(ccPlayer_t, unk_14d74) == 0x14D74, "unk_14d74 offset");
static_assert(offsetof(ccPlayer_t, unk_14db8) == 0x14DB8, "unk_14db8 offset");
static_assert(offsetof(ccPlayer_t, unk_14dc0) == 0x14DC0, "unk_14dc0 offset");
static_assert(offsetof(ccPlayer_t, unk_14dc4) == 0x14DC4, "unk_14dc4 offset");
static_assert(offsetof(ccPlayer_t, unk_14dcc) == 0x14DCC, "unk_14dcc offset");
static_assert(offsetof(ccPlayer_t, unk_14dd0) == 0x14DD0, "unk_14dd0 offset");
static_assert(offsetof(ccPlayer_t, unk_14dd8) == 0x14DD8, "unk_14dd8 offset");
static_assert(offsetof(ccPlayer_t, unk_14e18) == 0x14E18, "unk_14e18 offset");
static_assert(offsetof(ccPlayer_t, unk_14e20) == 0x14E20, "unk_14e20 offset");
static_assert(offsetof(ccPlayer_t, unk_14fa8) == 0x14FA8, "unk_14fa8 offset");
static_assert(offsetof(ccPlayer_t, unk_15118) == 0x15118, "unk_15118 offset");
static_assert(offsetof(ccPlayer_t, unk_15120) == 0x15120, "unk_15120 offset");
static_assert(offsetof(ccPlayer_t, unk_15128) == 0x15128, "unk_15128 offset");
static_assert(offsetof(ccPlayer_t, unk_15130) == 0x15130, "unk_15130 offset");
static_assert(offsetof(ccPlayer_t, unk_151a8) == 0x151A8, "unk_151a8 offset");
static_assert(offsetof(ccPlayer_t, unk_151b0) == 0x151B0, "unk_151b0 offset");
static_assert(offsetof(ccPlayer_t, unk_151b8) == 0x151B8, "unk_151b8 offset");
static_assert(offsetof(ccPlayer_t, unk_151d8) == 0x151D8, "unk_151d8 offset");
static_assert(offsetof(ccPlayer_t, unk_151e0) == 0x151E0, "unk_151e0 offset");
static_assert(offsetof(ccPlayer_t, unk_151e8) == 0x151E8, "unk_151e8 offset");
static_assert(offsetof(ccPlayer_t, unk_151f0) == 0x151F0, "unk_151f0 offset");
static_assert(offsetof(ccPlayer_t, unk_15200) == 0x15200, "unk_15200 offset");
static_assert(offsetof(ccPlayer_t, unk_15208) == 0x15208, "unk_15208 offset");
static_assert(offsetof(ccPlayer_t, unk_15210) == 0x15210, "unk_15210 offset");
static_assert(offsetof(ccPlayer_t, unk_15220) == 0x15220, "unk_15220 offset");
static_assert(offsetof(ccPlayer_t, unk_15310) == 0x15310, "unk_15310 offset");
static_assert(offsetof(ccPlayer_t, unk_15750) == 0x15750, "unk_15750 offset");
static_assert(offsetof(ccPlayer_t, unk_15754) == 0x15754, "unk_15754 offset");
static_assert(offsetof(ccPlayer_t, unk_15758) == 0x15758, "unk_15758 offset");

/*
 * Extension fields (boss/subclass, offsets >= 0x15760):
 *   0x15764 size=4 unk_15764 [high]
 *   0x15768 size=360 unk_15768 [low]
 *   0x158D0 size=32 unk_158d0 [medium]
 *   0x158F0 size=28 unk_158f0 [low]
 *   0x1590C size=56 unk_1590c [high]
 *   0x15944 size=4 unk_15944 [medium]
 *   0x15948 size=8 unk_15948 [medium]
 *   0x15950 size=4 unk_15950 [high]
 *   0x15954 size=4 unk_15954 [high]
 *   0x15958 size=8 unk_15958 [medium]
 *   ... and 13 more
 */

#endif /* CCPLAYER_S4_H */
