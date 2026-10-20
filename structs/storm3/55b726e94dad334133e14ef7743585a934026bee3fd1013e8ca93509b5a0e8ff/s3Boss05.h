/* s3Boss05.h - Storm 3 Full Burst HD boss battle structs (INFERRED, static analysis only)
 * Generated from state_surface data for build s3 (NSUNS3.exe 64-bit)
 * All fields use uint8_t arrays to guarantee exact offset matching.
 * Overlapping state_surface entries deduplicated (earlier field wins).
 */
#ifndef S3BOSS05_H
#define S3BOSS05_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccBoss05Player - 113 seed methods, 131 fields, size >= 0xC44 */
typedef struct __attribute__((packed)) ccBoss05Player {
    uint8_t _pad0[0x90]; /* fill to 0x0090 */
    uint8_t unk_0090[8]; /* +0x0090 type=uint64_t rw high */
    uint8_t init_unk_0098[8]; /* +0x0098 type=int64_t w high */
    uint8_t unk_00A0[4]; /* +0x00A0 type=int32_t rw high */
    uint8_t init_unk_00A4[4]; /* +0x00A4 type=uint32_t rw high */
    uint8_t init_unk_00A8[4]; /* +0x00A8 type=int32_t w low */
    uint8_t init_unk_00AC[4]; /* +0x00AC type=uint32_t rw high */
    uint8_t init_unk_00B0[4]; /* +0x00B0 type=int32_t rw low */
    uint8_t init_unk_00B4[4]; /* +0x00B4 type=uint32_t w medium */
    uint8_t init_unk_00B8[4]; /* +0x00B8 type=int32_t w medium */
    uint8_t init_unk_00BC[4]; /* +0x00BC type=uint32_t w medium */
    uint8_t hp_related_00C0[8]; /* +0x00C0 type=uint64_t rw high */
    uint8_t init_unk_00C8[8]; /* +0x00C8 type=uint64_t w high */
    uint8_t init_unk_00D0[8]; /* +0x00D0 type=uint64_t w high */
    uint8_t init_unk_00D8[8]; /* +0x00D8 type=uint64_t w high */
    uint8_t init_unk_00E0[8]; /* +0x00E0 type=uint64_t w high */
    uint8_t init_unk_00E8[8]; /* +0x00E8 type=uint64_t w high */
    uint8_t anim_unk_00F0[8]; /* +0x00F0 type=uint64_t rw high */
    uint8_t anim_unk_00F8[4]; /* +0x00F8 type=float rw high */
    uint8_t init_unk_00FC[4]; /* +0x00FC type=uint32_t w low */
    uint8_t input_unk_0100[8]; /* +0x0100 type=uint64_t rw high */
    uint8_t init_unk_0108[8]; /* +0x0108 type=uint64_t w high */
    uint8_t unk_0110[8]; /* +0x0110 type=uint64_t rw high */
    uint8_t _pad1[0x52C]; /* fill to 0x0644 */
    uint8_t damage_unk_0644[8]; /* +0x0644 type=int64_t w high */
    uint8_t init_unk_064C[8]; /* +0x064C type=int64_t rw low */
    uint8_t anim_unk_0654[4]; /* +0x0654 type=uint32_t rw high */
    uint8_t init_unk_0658[8]; /* +0x0658 type=int64_t rw low */
    uint8_t init_unk_0660[4]; /* +0x0660 type=int32_t w medium */
    uint8_t init_unk_0664[8]; /* +0x0664 type=int64_t rw low */
    uint8_t init_unk_066C[4]; /* +0x066C type=uint32_t w medium */
    uint8_t init_unk_0670[8]; /* +0x0670 type=int64_t rw low */
    uint8_t init_unk_0678[4]; /* +0x0678 type=int32_t w medium */
    uint8_t init_unk_067C[8]; /* +0x067C type=int64_t rw low */
    uint8_t init_unk_0684[4]; /* +0x0684 type=uint32_t w medium */
    uint8_t _pad2[0x10]; /* fill to 0x0698 */
    uint8_t damage_unk_0698[4]; /* +0x0698 type=uint32_t w high */
    uint8_t _pad3[0x4]; /* fill to 0x06A0 */
    uint8_t damage_unk_06A0[4]; /* +0x06A0 type=uint32_t w high */
    uint8_t _pad4[0x10]; /* fill to 0x06B4 */
    uint8_t init_unk_06B4[4]; /* +0x06B4 type=uint32_t w high */
    uint8_t init_unk_06B8[8]; /* +0x06B8 type=int64_t rw low */
    uint8_t init_unk_06C0[4]; /* +0x06C0 type=int32_t w high */
    uint8_t unk_06C4[8]; /* +0x06C4 type=int64_t rw low */
    uint8_t init_unk_06CC[4]; /* +0x06CC type=uint32_t w high */
    uint8_t init_unk_06D0[8]; /* +0x06D0 type=int64_t rw low */
    uint8_t init_unk_06D8[4]; /* +0x06D8 type=int32_t w high */
    uint8_t init_unk_06DC[8]; /* +0x06DC type=int64_t w high */
    uint8_t init_unk_06E4[4]; /* +0x06E4 type=uint32_t w high */
    uint8_t init_unk_06E8[4]; /* +0x06E8 type=uint32_t w medium */
    uint8_t input_unk_06EC[8]; /* +0x06EC type=int64_t rw high */
    uint8_t _pad5[0x4]; /* fill to 0x06F8 */
    uint8_t init_unk_06F8[8]; /* +0x06F8 type=uint64_t w high */
    uint8_t unk_0700[8]; /* +0x0700 type=int64_t rw low */
    uint8_t init_unk_0708[4]; /* +0x0708 type=int32_t w high */
    uint8_t init_unk_070C[4]; /* +0x070C type=uint32_t w high */
    uint8_t init_unk_0710[4]; /* +0x0710 type=uint32_t w high */
    uint8_t unk_0714[8]; /* +0x0714 type=int64_t rw high */
    uint8_t init_unk_071C[4]; /* +0x071C type=uint32_t w medium */
    uint8_t init_unk_0720[4]; /* +0x0720 type=uint32_t w high */
    uint8_t unk_0724[4]; /* +0x0724 type=uint32_t rw high */
    uint8_t init_unk_0728[4]; /* +0x0728 type=uint32_t w high */
    uint8_t init_unk_072C[4]; /* +0x072C type=uint32_t w high */
    uint8_t init_unk_0730[4]; /* +0x0730 type=uint32_t w high */
    uint8_t init_unk_0734[4]; /* +0x0734 type=uint32_t w high */
    uint8_t anim_unk_0738[4]; /* +0x0738 type=float rw high */
    uint8_t init_unk_073C[4]; /* +0x073C type=uint32_t w high */
    uint8_t unk_0740[4]; /* +0x0740 type=uint32_t w high */
    uint8_t _pad6[0x4]; /* fill to 0x0748 */
    uint8_t damage_unk_0748[8]; /* +0x0748 type=int64_t r low */
    uint8_t _pad7[0x14]; /* fill to 0x0764 */
    uint8_t unk_0764[4]; /* +0x0764 type=uint32_t r medium */
    uint8_t _pad8[0x18]; /* fill to 0x0780 */
    uint8_t unk_0780[4]; /* +0x0780 type=uint32_t w high */
    uint8_t _pad9[0x4]; /* fill to 0x0788 */
    uint8_t input_unk_0788[8]; /* +0x0788 type=uint64_t r medium */
    uint8_t _pad10[0x18]; /* fill to 0x07A8 */
    uint8_t input_unk_07A8[8]; /* +0x07A8 type=uint64_t r medium */
    uint8_t _pad11[0x10]; /* fill to 0x07C0 */
    uint8_t input_unk_07C0[8]; /* +0x07C0 type=uint64_t rw low */
    uint8_t unk_07C8[8]; /* +0x07C8 type=int64_t rw high */
    uint8_t damage_unk_07D0[8]; /* +0x07D0 type=int64_t rw low */
    uint8_t _pad12[0x1C]; /* fill to 0x07F4 */
    uint8_t damage_unk_07F4[4]; /* +0x07F4 type=float r medium */
    uint8_t damage_unk_07F8[8]; /* +0x07F8 type=uint64_t r medium */
    uint8_t damage_unk_0800[8]; /* +0x0800 type=uint64_t r medium */
    uint8_t _pad13[0xC]; /* fill to 0x0814 */
    uint8_t damage_unk_0814[4]; /* +0x0814 type=int32_t r medium */
    uint8_t damage_unk_0818[8]; /* +0x0818 type=uint64_t r medium */
    uint8_t damage_unk_0820[8]; /* +0x0820 type=uint64_t r medium */
    uint8_t damage_unk_0828[8]; /* +0x0828 type=uint64_t r medium */
    uint8_t damage_unk_0830[8]; /* +0x0830 type=uint64_t rw low */
    uint8_t damage_unk_0838[8]; /* +0x0838 type=int64_t r medium */
    uint8_t damage_unk_0840[8]; /* +0x0840 type=int64_t r low */
    uint8_t _pad14[0x1C]; /* fill to 0x0864 */
    uint8_t damage_unk_0864[4]; /* +0x0864 type=int32_t r medium */
    uint8_t _pad15[0x4]; /* fill to 0x086C */
    uint8_t damage_unk_086C[4]; /* +0x086C type=uint32_t rw medium */
    uint8_t damage_unk_0870[4]; /* +0x0870 type=int32_t rw medium */
    uint8_t hp_related_0874[4]; /* +0x0874 type=uint32_t r medium */
    uint8_t _pad16[0x1C]; /* fill to 0x0894 */
    uint8_t damage_unk_0894[4]; /* +0x0894 type=int32_t r medium */
    uint8_t damage_unk_0898[8]; /* +0x0898 type=uint64_t r medium */
    uint8_t damage_unk_08A0[8]; /* +0x08A0 type=int64_t r medium */
    uint8_t init_unk_08A8[8]; /* +0x08A8 type=uint64_t w high */
    uint8_t init_unk_08B0[8]; /* +0x08B0 type=uint64_t w high */
    uint8_t init_unk_08B8[8]; /* +0x08B8 type=uint64_t w high */
    uint8_t unk_08C0[4]; /* +0x08C0 type=int32_t rw high */
    uint8_t unk_08C4[4]; /* +0x08C4 type=int32_t w low */
    uint8_t unk_08C8[4]; /* +0x08C8 type=uint32_t w high */
    uint8_t unk_08CC[4]; /* +0x08CC type=uint32_t w high */
    uint8_t unk_08D0[4]; /* +0x08D0 type=uint32_t rw high */
    uint8_t unk_08D4[4]; /* +0x08D4 type=uint32_t w high */
    uint8_t unk_08D8[4]; /* +0x08D8 type=uint32_t rw high */
    uint8_t unk_08DC[4]; /* +0x08DC type=float rw high */
    uint8_t unk_08E0[8]; /* +0x08E0 type=uint64_t w low */
    uint8_t unk_08E8[4]; /* +0x08E8 type=uint32_t rw high */
    uint8_t _pad17[0x4]; /* fill to 0x08F0 */
    uint8_t init_unk_08F0[8]; /* +0x08F0 type=uint64_t w high */
    uint8_t unk_08F8[8]; /* +0x08F8 type=uint64_t w low */
    uint8_t init_unk_0900[8]; /* +0x0900 type=uint64_t w high */
    uint8_t input_unk_0908[8]; /* +0x0908 type=uint64_t rw low */
    uint8_t damage_unk_0910[4]; /* +0x0910 type=float rw high */
    uint8_t _pad18[0x4]; /* fill to 0x0918 */
    uint8_t unk_0918[8]; /* +0x0918 type=int64_t rw high */
    uint8_t init_unk_0920[8]; /* +0x0920 type=uint64_t rw high */
    uint8_t init_unk_0928[8]; /* +0x0928 type=uint64_t rw high */
    uint8_t damage_unk_0930[8]; /* +0x0930 type=uint64_t rw high */
    uint8_t init_unk_0938[8]; /* +0x0938 type=uint64_t rw high */
    uint8_t init_unk_0940[8]; /* +0x0940 type=uint64_t rw high */
    uint8_t damage_unk_0948[4]; /* +0x0948 type=int32_t rw high */
    uint8_t _pad19[0x4]; /* fill to 0x0950 */
    uint8_t unk_0950[8]; /* +0x0950 type=uint64_t rw high */
    uint8_t _pad20[0xA0]; /* fill to 0x09F8 */
    uint8_t init_unk_09F8[8]; /* +0x09F8 type=uint64_t w low */
    uint8_t _pad21[0xA0]; /* fill to 0x0AA0 */
    uint8_t init_unk_0AA0[8]; /* +0x0AA0 type=uint64_t w low */
    uint8_t _pad22[0xA0]; /* fill to 0x0B48 */
    uint8_t init_unk_0B48[8]; /* +0x0B48 type=uint64_t w low */
    uint8_t init_unk_0B50[8]; /* +0x0B50 type=int64_t rw low */
    uint8_t init_unk_0B58[4]; /* +0x0B58 type=int32_t w high */
    uint8_t init_unk_0B5C[8]; /* +0x0B5C type=int64_t rw low */
    uint8_t init_unk_0B64[4]; /* +0x0B64 type=uint32_t w high */
    uint8_t init_unk_0B68[8]; /* +0x0B68 type=uint64_t w high */
    uint8_t init_unk_0B70[4]; /* +0x0B70 type=uint32_t w low */
    uint8_t init_unk_0B74[4]; /* +0x0B74 type=uint32_t w high */
    uint8_t damage_unk_0B78[8]; /* +0x0B78 type=int64_t rw high */
    uint8_t init_unk_0B80[8]; /* +0x0B80 type=uint64_t rw high */
    uint8_t anim_unk_0B88[8]; /* +0x0B88 type=uint64_t rw high */
    uint8_t init_unk_0B90[8]; /* +0x0B90 type=int64_t rw low */
    uint8_t init_unk_0B98[4]; /* +0x0B98 type=int32_t w high */
    uint8_t init_unk_0B9C[4]; /* +0x0B9C type=uint32_t w high */
    uint8_t _pad23[0x80]; /* fill to 0x0C20 */
    uint8_t init_unk_0C20[4]; /* +0x0C20 type=uint32_t w high */
    uint8_t _pad24[0x1C]; /* fill to 0x0C40 */
    uint8_t unk_0C40[4]; /* +0x0C40 type=float rw high */
} ccBoss05Player;

/* offsetof assertions for ccBoss05Player */
static_assert(offsetof(ccBoss05Player, unk_0090) == 0x0090, "ccBoss05Player.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0098) == 0x0098, "ccBoss05Player.init_unk_0098 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_00A0) == 0x00A0, "ccBoss05Player.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00A4) == 0x00A4, "ccBoss05Player.init_unk_00A4 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00A8) == 0x00A8, "ccBoss05Player.init_unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00AC) == 0x00AC, "ccBoss05Player.init_unk_00AC offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00B0) == 0x00B0, "ccBoss05Player.init_unk_00B0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00B4) == 0x00B4, "ccBoss05Player.init_unk_00B4 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00B8) == 0x00B8, "ccBoss05Player.init_unk_00B8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00BC) == 0x00BC, "ccBoss05Player.init_unk_00BC offset mismatch");
static_assert(offsetof(ccBoss05Player, hp_related_00C0) == 0x00C0, "ccBoss05Player.hp_related_00C0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00C8) == 0x00C8, "ccBoss05Player.init_unk_00C8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00D0) == 0x00D0, "ccBoss05Player.init_unk_00D0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00D8) == 0x00D8, "ccBoss05Player.init_unk_00D8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00E0) == 0x00E0, "ccBoss05Player.init_unk_00E0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00E8) == 0x00E8, "ccBoss05Player.init_unk_00E8 offset mismatch");
static_assert(offsetof(ccBoss05Player, anim_unk_00F0) == 0x00F0, "ccBoss05Player.anim_unk_00F0 offset mismatch");
static_assert(offsetof(ccBoss05Player, anim_unk_00F8) == 0x00F8, "ccBoss05Player.anim_unk_00F8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_00FC) == 0x00FC, "ccBoss05Player.init_unk_00FC offset mismatch");
static_assert(offsetof(ccBoss05Player, input_unk_0100) == 0x0100, "ccBoss05Player.input_unk_0100 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0108) == 0x0108, "ccBoss05Player.init_unk_0108 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0110) == 0x0110, "ccBoss05Player.unk_0110 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0644) == 0x0644, "ccBoss05Player.damage_unk_0644 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_064C) == 0x064C, "ccBoss05Player.init_unk_064C offset mismatch");
static_assert(offsetof(ccBoss05Player, anim_unk_0654) == 0x0654, "ccBoss05Player.anim_unk_0654 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0658) == 0x0658, "ccBoss05Player.init_unk_0658 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0660) == 0x0660, "ccBoss05Player.init_unk_0660 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0664) == 0x0664, "ccBoss05Player.init_unk_0664 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_066C) == 0x066C, "ccBoss05Player.init_unk_066C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0670) == 0x0670, "ccBoss05Player.init_unk_0670 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0678) == 0x0678, "ccBoss05Player.init_unk_0678 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_067C) == 0x067C, "ccBoss05Player.init_unk_067C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0684) == 0x0684, "ccBoss05Player.init_unk_0684 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0698) == 0x0698, "ccBoss05Player.damage_unk_0698 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_06A0) == 0x06A0, "ccBoss05Player.damage_unk_06A0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06B4) == 0x06B4, "ccBoss05Player.init_unk_06B4 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06B8) == 0x06B8, "ccBoss05Player.init_unk_06B8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06C0) == 0x06C0, "ccBoss05Player.init_unk_06C0 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_06C4) == 0x06C4, "ccBoss05Player.unk_06C4 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06CC) == 0x06CC, "ccBoss05Player.init_unk_06CC offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06D0) == 0x06D0, "ccBoss05Player.init_unk_06D0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06D8) == 0x06D8, "ccBoss05Player.init_unk_06D8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06DC) == 0x06DC, "ccBoss05Player.init_unk_06DC offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06E4) == 0x06E4, "ccBoss05Player.init_unk_06E4 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06E8) == 0x06E8, "ccBoss05Player.init_unk_06E8 offset mismatch");
static_assert(offsetof(ccBoss05Player, input_unk_06EC) == 0x06EC, "ccBoss05Player.input_unk_06EC offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_06F8) == 0x06F8, "ccBoss05Player.init_unk_06F8 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0700) == 0x0700, "ccBoss05Player.unk_0700 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0708) == 0x0708, "ccBoss05Player.init_unk_0708 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_070C) == 0x070C, "ccBoss05Player.init_unk_070C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0710) == 0x0710, "ccBoss05Player.init_unk_0710 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0714) == 0x0714, "ccBoss05Player.unk_0714 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_071C) == 0x071C, "ccBoss05Player.init_unk_071C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0720) == 0x0720, "ccBoss05Player.init_unk_0720 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0724) == 0x0724, "ccBoss05Player.unk_0724 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0728) == 0x0728, "ccBoss05Player.init_unk_0728 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_072C) == 0x072C, "ccBoss05Player.init_unk_072C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0730) == 0x0730, "ccBoss05Player.init_unk_0730 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0734) == 0x0734, "ccBoss05Player.init_unk_0734 offset mismatch");
static_assert(offsetof(ccBoss05Player, anim_unk_0738) == 0x0738, "ccBoss05Player.anim_unk_0738 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_073C) == 0x073C, "ccBoss05Player.init_unk_073C offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0740) == 0x0740, "ccBoss05Player.unk_0740 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0748) == 0x0748, "ccBoss05Player.damage_unk_0748 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0764) == 0x0764, "ccBoss05Player.unk_0764 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0780) == 0x0780, "ccBoss05Player.unk_0780 offset mismatch");
static_assert(offsetof(ccBoss05Player, input_unk_0788) == 0x0788, "ccBoss05Player.input_unk_0788 offset mismatch");
static_assert(offsetof(ccBoss05Player, input_unk_07A8) == 0x07A8, "ccBoss05Player.input_unk_07A8 offset mismatch");
static_assert(offsetof(ccBoss05Player, input_unk_07C0) == 0x07C0, "ccBoss05Player.input_unk_07C0 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_07C8) == 0x07C8, "ccBoss05Player.unk_07C8 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_07D0) == 0x07D0, "ccBoss05Player.damage_unk_07D0 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_07F4) == 0x07F4, "ccBoss05Player.damage_unk_07F4 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_07F8) == 0x07F8, "ccBoss05Player.damage_unk_07F8 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0800) == 0x0800, "ccBoss05Player.damage_unk_0800 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0814) == 0x0814, "ccBoss05Player.damage_unk_0814 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0818) == 0x0818, "ccBoss05Player.damage_unk_0818 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0820) == 0x0820, "ccBoss05Player.damage_unk_0820 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0828) == 0x0828, "ccBoss05Player.damage_unk_0828 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0830) == 0x0830, "ccBoss05Player.damage_unk_0830 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0838) == 0x0838, "ccBoss05Player.damage_unk_0838 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0840) == 0x0840, "ccBoss05Player.damage_unk_0840 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0864) == 0x0864, "ccBoss05Player.damage_unk_0864 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_086C) == 0x086C, "ccBoss05Player.damage_unk_086C offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0870) == 0x0870, "ccBoss05Player.damage_unk_0870 offset mismatch");
static_assert(offsetof(ccBoss05Player, hp_related_0874) == 0x0874, "ccBoss05Player.hp_related_0874 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0894) == 0x0894, "ccBoss05Player.damage_unk_0894 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0898) == 0x0898, "ccBoss05Player.damage_unk_0898 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_08A0) == 0x08A0, "ccBoss05Player.damage_unk_08A0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_08A8) == 0x08A8, "ccBoss05Player.init_unk_08A8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_08B0) == 0x08B0, "ccBoss05Player.init_unk_08B0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_08B8) == 0x08B8, "ccBoss05Player.init_unk_08B8 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08C0) == 0x08C0, "ccBoss05Player.unk_08C0 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08C4) == 0x08C4, "ccBoss05Player.unk_08C4 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08C8) == 0x08C8, "ccBoss05Player.unk_08C8 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08CC) == 0x08CC, "ccBoss05Player.unk_08CC offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08D0) == 0x08D0, "ccBoss05Player.unk_08D0 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08D4) == 0x08D4, "ccBoss05Player.unk_08D4 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08D8) == 0x08D8, "ccBoss05Player.unk_08D8 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08DC) == 0x08DC, "ccBoss05Player.unk_08DC offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08E0) == 0x08E0, "ccBoss05Player.unk_08E0 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08E8) == 0x08E8, "ccBoss05Player.unk_08E8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_08F0) == 0x08F0, "ccBoss05Player.init_unk_08F0 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_08F8) == 0x08F8, "ccBoss05Player.unk_08F8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0900) == 0x0900, "ccBoss05Player.init_unk_0900 offset mismatch");
static_assert(offsetof(ccBoss05Player, input_unk_0908) == 0x0908, "ccBoss05Player.input_unk_0908 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0910) == 0x0910, "ccBoss05Player.damage_unk_0910 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0918) == 0x0918, "ccBoss05Player.unk_0918 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0920) == 0x0920, "ccBoss05Player.init_unk_0920 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0928) == 0x0928, "ccBoss05Player.init_unk_0928 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0930) == 0x0930, "ccBoss05Player.damage_unk_0930 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0938) == 0x0938, "ccBoss05Player.init_unk_0938 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0940) == 0x0940, "ccBoss05Player.init_unk_0940 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0948) == 0x0948, "ccBoss05Player.damage_unk_0948 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0950) == 0x0950, "ccBoss05Player.unk_0950 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_09F8) == 0x09F8, "ccBoss05Player.init_unk_09F8 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0AA0) == 0x0AA0, "ccBoss05Player.init_unk_0AA0 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B48) == 0x0B48, "ccBoss05Player.init_unk_0B48 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B50) == 0x0B50, "ccBoss05Player.init_unk_0B50 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B58) == 0x0B58, "ccBoss05Player.init_unk_0B58 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B5C) == 0x0B5C, "ccBoss05Player.init_unk_0B5C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B64) == 0x0B64, "ccBoss05Player.init_unk_0B64 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B68) == 0x0B68, "ccBoss05Player.init_unk_0B68 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B70) == 0x0B70, "ccBoss05Player.init_unk_0B70 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B74) == 0x0B74, "ccBoss05Player.init_unk_0B74 offset mismatch");
static_assert(offsetof(ccBoss05Player, damage_unk_0B78) == 0x0B78, "ccBoss05Player.damage_unk_0B78 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B80) == 0x0B80, "ccBoss05Player.init_unk_0B80 offset mismatch");
static_assert(offsetof(ccBoss05Player, anim_unk_0B88) == 0x0B88, "ccBoss05Player.anim_unk_0B88 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B90) == 0x0B90, "ccBoss05Player.init_unk_0B90 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B98) == 0x0B98, "ccBoss05Player.init_unk_0B98 offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0B9C) == 0x0B9C, "ccBoss05Player.init_unk_0B9C offset mismatch");
static_assert(offsetof(ccBoss05Player, init_unk_0C20) == 0x0C20, "ccBoss05Player.init_unk_0C20 offset mismatch");
static_assert(offsetof(ccBoss05Player, unk_0C40) == 0x0C40, "ccBoss05Player.unk_0C40 offset mismatch");

/* ccBoss05PlayerState - 60 seed methods, 10 fields, size >= 0x74 */
typedef struct __attribute__((packed)) ccBoss05PlayerState {
    uint8_t _pad0[0x1C]; /* fill to 0x001C */
    uint8_t unk_001C[4]; /* +0x001C type=uint32_t w medium */
    uint8_t _pad1[0x4]; /* fill to 0x0024 */
    uint8_t unk_0024[8]; /* +0x0024 type=int64_t w medium */
    uint8_t unk_002C[4]; /* +0x002C type=uint32_t w medium */
    uint8_t _pad2[0xC]; /* fill to 0x003C */
    uint8_t unk_003C[4]; /* +0x003C type=uint32_t w medium */
    uint8_t _pad3[0x4]; /* fill to 0x0044 */
    uint8_t unk_0044[8]; /* +0x0044 type=int64_t w medium */
    uint8_t unk_004C[8]; /* +0x004C type=int64_t w medium */
    uint8_t unk_0054[4]; /* +0x0054 type=uint32_t w medium */
    uint8_t unk_0058[4]; /* +0x0058 type=uint32_t w medium */
    uint8_t unk_005C[8]; /* +0x005C type=int64_t w medium */
    uint8_t _pad4[0x8]; /* fill to 0x006C */
    uint8_t unk_006C[8]; /* +0x006C type=int64_t w medium */
} ccBoss05PlayerState;

/* offsetof assertions for ccBoss05PlayerState */
static_assert(offsetof(ccBoss05PlayerState, unk_001C) == 0x001C, "ccBoss05PlayerState.unk_001C offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_0024) == 0x0024, "ccBoss05PlayerState.unk_0024 offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_002C) == 0x002C, "ccBoss05PlayerState.unk_002C offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_003C) == 0x003C, "ccBoss05PlayerState.unk_003C offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_0044) == 0x0044, "ccBoss05PlayerState.unk_0044 offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_004C) == 0x004C, "ccBoss05PlayerState.unk_004C offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_0054) == 0x0054, "ccBoss05PlayerState.unk_0054 offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_0058) == 0x0058, "ccBoss05PlayerState.unk_0058 offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_005C) == 0x005C, "ccBoss05PlayerState.unk_005C offset mismatch");
static_assert(offsetof(ccBoss05PlayerState, unk_006C) == 0x006C, "ccBoss05PlayerState.unk_006C offset mismatch");

/* ccBoss05PlayerAtk - 12 seed methods, 8 fields, size >= 0x428 */
typedef struct __attribute__((packed)) ccBoss05PlayerAtk {
    uint8_t _pad0[0x90]; /* fill to 0x0090 */
    uint8_t unk_0090[8]; /* +0x0090 type=uint64_t r medium */
    uint8_t _pad1[0x8]; /* fill to 0x00A0 */
    uint8_t unk_00A0[8]; /* +0x00A0 type=uint64_t r medium */
    uint8_t _pad2[0x20]; /* fill to 0x00C8 */
    uint8_t unk_00C8[4]; /* +0x00C8 type=uint32_t w medium */
    uint8_t _pad3[0xA4]; /* fill to 0x0170 */
    uint8_t unk_0170[8]; /* +0x0170 type=int64_t r medium */
    uint8_t unk_0178[8]; /* +0x0178 type=int64_t rw high */
    uint8_t _pad4[0x24]; /* fill to 0x01A4 */
    uint8_t unk_01A4[4]; /* +0x01A4 type=int32_t r medium */
    uint8_t _pad5[0x268]; /* fill to 0x0410 */
    uint8_t unk_0410[8]; /* +0x0410 type=int64_t r medium */
    uint8_t _pad6[0x8]; /* fill to 0x0420 */
    uint8_t unk_0420[8]; /* +0x0420 type=uint64_t r medium */
} ccBoss05PlayerAtk;

/* offsetof assertions for ccBoss05PlayerAtk */
static_assert(offsetof(ccBoss05PlayerAtk, unk_0090) == 0x0090, "ccBoss05PlayerAtk.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_00A0) == 0x00A0, "ccBoss05PlayerAtk.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_00C8) == 0x00C8, "ccBoss05PlayerAtk.unk_00C8 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_0170) == 0x0170, "ccBoss05PlayerAtk.unk_0170 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_0178) == 0x0178, "ccBoss05PlayerAtk.unk_0178 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_01A4) == 0x01A4, "ccBoss05PlayerAtk.unk_01A4 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_0410) == 0x0410, "ccBoss05PlayerAtk.unk_0410 offset mismatch");
static_assert(offsetof(ccBoss05PlayerAtk, unk_0420) == 0x0420, "ccBoss05PlayerAtk.unk_0420 offset mismatch");

/* ccBoss05PlayerAtkBase - 4 seed methods, 1 fields, size >= 0xA8 */
typedef struct __attribute__((packed)) ccBoss05PlayerAtkBase {
    uint8_t _pad0[0xA0]; /* fill to 0x00A0 */
    uint8_t unk_00A0[8]; /* +0x00A0 type=int64_t r medium */
} ccBoss05PlayerAtkBase;

/* offsetof assertions for ccBoss05PlayerAtkBase */
static_assert(offsetof(ccBoss05PlayerAtkBase, unk_00A0) == 0x00A0, "ccBoss05PlayerAtkBase.unk_00A0 offset mismatch");

/* ccBoss0510 - 24 seed methods, 20 fields, size >= 0x1A58 */
typedef struct __attribute__((packed)) ccBoss0510 {
    uint8_t _pad0[0x90]; /* fill to 0x0090 */
    uint8_t unk_0090[8]; /* +0x0090 type=uint64_t w medium */
    uint8_t unk_0098[8]; /* +0x0098 type=uint64_t w medium */
    uint8_t unk_00A0[8]; /* +0x00A0 type=uint64_t w medium */
    uint8_t unk_00A8[8]; /* +0x00A8 type=uint64_t rw low */
    uint8_t _pad1[0x278]; /* fill to 0x0328 */
    uint8_t unk_0328[8]; /* +0x0328 type=uint64_t w medium */
    uint8_t unk_0330[8]; /* +0x0330 type=uint64_t rw low */
    uint8_t _pad2[0x10]; /* fill to 0x0348 */
    uint8_t unk_0348[8]; /* +0x0348 type=uint64_t w medium */
    uint8_t unk_0350[8]; /* +0x0350 type=uint64_t w medium */
    uint8_t unk_0358[8]; /* +0x0358 type=uint64_t w medium */
    uint8_t unk_0360[8]; /* +0x0360 type=uint64_t rw low */
    uint8_t _pad3[0xC50]; /* fill to 0x0FB8 */
    uint8_t unk_0FB8[8]; /* +0x0FB8 type=uint64_t w medium */
    uint8_t _pad4[0x970]; /* fill to 0x1930 */
    uint8_t unk_1930[8]; /* +0x1930 type=uint64_t w medium */
    uint8_t unk_1938[8]; /* +0x1938 type=uint64_t w medium */
    uint8_t unk_1940[8]; /* +0x1940 type=uint64_t w medium */
    uint8_t unk_1948[4]; /* +0x1948 type=uint32_t w medium */
    uint8_t _pad5[0x4]; /* fill to 0x1950 */
    uint8_t unk_1950[8]; /* +0x1950 type=uint64_t w medium */
    uint8_t unk_1958[4]; /* +0x1958 type=uint32_t w medium */
    uint8_t _pad6[0x4]; /* fill to 0x1960 */
    uint8_t unk_1960[8]; /* +0x1960 type=uint64_t rw low */
    uint8_t _pad7[0x70]; /* fill to 0x19D8 */
    uint8_t unk_19D8[8]; /* +0x19D8 type=uint64_t rw low */
    uint8_t _pad8[0x70]; /* fill to 0x1A50 */
    uint8_t unk_1A50[8]; /* +0x1A50 type=uint64_t rw low */
} ccBoss0510;

/* offsetof assertions for ccBoss0510 */
static_assert(offsetof(ccBoss0510, unk_0090) == 0x0090, "ccBoss0510.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0098) == 0x0098, "ccBoss0510.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_00A0) == 0x00A0, "ccBoss0510.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_00A8) == 0x00A8, "ccBoss0510.unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0328) == 0x0328, "ccBoss0510.unk_0328 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0330) == 0x0330, "ccBoss0510.unk_0330 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0348) == 0x0348, "ccBoss0510.unk_0348 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0350) == 0x0350, "ccBoss0510.unk_0350 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0358) == 0x0358, "ccBoss0510.unk_0358 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0360) == 0x0360, "ccBoss0510.unk_0360 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_0FB8) == 0x0FB8, "ccBoss0510.unk_0FB8 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1930) == 0x1930, "ccBoss0510.unk_1930 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1938) == 0x1938, "ccBoss0510.unk_1938 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1940) == 0x1940, "ccBoss0510.unk_1940 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1948) == 0x1948, "ccBoss0510.unk_1948 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1950) == 0x1950, "ccBoss0510.unk_1950 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1958) == 0x1958, "ccBoss0510.unk_1958 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1960) == 0x1960, "ccBoss0510.unk_1960 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_19D8) == 0x19D8, "ccBoss0510.unk_19D8 offset mismatch");
static_assert(offsetof(ccBoss0510, unk_1A50) == 0x1A50, "ccBoss0510.unk_1A50 offset mismatch");

/* ccBoss0510Gedo - 41 seed methods, 41 fields, size >= 0x326C */
typedef struct __attribute__((packed)) ccBoss0510Gedo {
    uint8_t _pad0[0x90]; /* fill to 0x0090 */
    uint8_t unk_0090[4]; /* +0x0090 type=uint32_t r medium */
    uint8_t _pad1[0x10]; /* fill to 0x00A4 */
    uint8_t unk_00A4[4]; /* +0x00A4 type=int32_t r medium */
    uint8_t _pad2[0x18]; /* fill to 0x00C0 */
    uint8_t unk_00C0[8]; /* +0x00C0 type=uint64_t r medium */
    uint8_t unk_00C8[8]; /* +0x00C8 type=uint64_t r medium */
    uint8_t _pad3[0x28]; /* fill to 0x00F8 */
    uint8_t unk_00F8[4]; /* +0x00F8 type=float w medium */
    uint8_t unk_00FC[4]; /* +0x00FC type=uint32_t w high */
    uint8_t _pad4[0x594]; /* fill to 0x0694 */
    uint8_t unk_0694[4]; /* +0x0694 type=float w high */
    uint8_t unk_0698[4]; /* +0x0698 type=uint32_t w high */
    uint8_t _pad5[0x4]; /* fill to 0x06A0 */
    uint8_t unk_06A0[4]; /* +0x06A0 type=uint32_t w high */
    uint8_t _pad6[0x3C]; /* fill to 0x06E0 */
    uint8_t unk_06E0[4]; /* +0x06E0 type=uint32_t w medium */
    uint8_t unk_06E4[4]; /* +0x06E4 type=uint32_t w high */
    uint8_t _pad7[0x4]; /* fill to 0x06EC */
    uint8_t unk_06EC[4]; /* +0x06EC type=uint32_t r medium */
    uint8_t unk_06F0[4]; /* +0x06F0 type=uint32_t w medium */
    uint8_t _pad8[0x4]; /* fill to 0x06F8 */
    uint8_t unk_06F8[8]; /* +0x06F8 type=int64_t rw high */
    uint8_t unk_0700[8]; /* +0x0700 type=int64_t rw low */
    uint8_t unk_0708[4]; /* +0x0708 type=uint32_t w high */
    uint8_t _pad9[0xC]; /* fill to 0x0718 */
    uint8_t unk_0718[8]; /* +0x0718 type=uint64_t r medium */
    uint8_t _pad10[0x18]; /* fill to 0x0738 */
    uint8_t unk_0738[4]; /* +0x0738 type=uint32_t w high */
    uint8_t _pad11[0x54]; /* fill to 0x0790 */
    uint8_t unk_0790[4]; /* +0x0790 type=int32_t rw high */
    uint8_t unk_0794[4]; /* +0x0794 type=float rw high */
    uint8_t _pad12[0x120]; /* fill to 0x08B8 */
    uint8_t unk_08B8[8]; /* +0x08B8 type=uint64_t r medium */
    uint8_t _pad13[0x3C]; /* fill to 0x08FC */
    uint8_t unk_08FC[4]; /* +0x08FC type=uint32_t w high */
    uint8_t _pad14[0x30]; /* fill to 0x0930 */
    uint8_t unk_0930[8]; /* +0x0930 type=uint64_t r low */
    uint8_t _pad15[0x240]; /* fill to 0x0B78 */
    uint8_t unk_0B78[8]; /* +0x0B78 type=uint64_t r medium */
    uint8_t _pad16[0xA8]; /* fill to 0x0C28 */
    uint8_t unk_0C28[8]; /* +0x0C28 type=uint64_t r medium */
    uint8_t _pad17[0x18]; /* fill to 0x0C48 */
    uint8_t unk_0C48[4]; /* +0x0C48 type=float rw medium */
    uint8_t unk_0C4C[4]; /* +0x0C4C type=float rw high */
    uint8_t unk_0C50[4]; /* +0x0C50 type=uint32_t rw high */
    uint8_t _pad18[0x18]; /* fill to 0x0C6C */
    uint8_t unk_0C6C[4]; /* +0x0C6C type=uint32_t rw high */
    uint8_t unk_0C70[4]; /* +0x0C70 type=float rw high */
    uint8_t unk_0C74[4]; /* +0x0C74 type=float rw high */
    uint8_t _pad19[0x10]; /* fill to 0x0C88 */
    uint8_t unk_0C88[4]; /* +0x0C88 type=uint32_t w medium */
    uint8_t unk_0C8C[4]; /* +0x0C8C type=uint32_t w medium */
    uint8_t unk_0C90[4]; /* +0x0C90 type=uint32_t w medium */
    uint8_t unk_0C94[4]; /* +0x0C94 type=uint32_t w medium */
    uint8_t unk_0C98[4]; /* +0x0C98 type=uint32_t w medium */
    uint8_t unk_0C9C[4]; /* +0x0C9C type=uint32_t w medium */
    uint8_t unk_0CA0[4]; /* +0x0CA0 type=uint32_t w medium */
    uint8_t _pad20[0x24F8]; /* fill to 0x319C */
    uint8_t unk_319C[4]; /* +0x319C type=uint32_t r medium */
    uint8_t _pad21[0x18]; /* fill to 0x31B8 */
    uint8_t unk_31B8[8]; /* +0x31B8 type=uint64_t w medium */
    uint8_t _pad22[0xA8]; /* fill to 0x3268 */
    uint8_t unk_3268[4]; /* +0x3268 type=uint32_t w medium */
} ccBoss0510Gedo;

/* offsetof assertions for ccBoss0510Gedo */
static_assert(offsetof(ccBoss0510Gedo, unk_0090) == 0x0090, "ccBoss0510Gedo.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_00A4) == 0x00A4, "ccBoss0510Gedo.unk_00A4 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_00C0) == 0x00C0, "ccBoss0510Gedo.unk_00C0 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_00C8) == 0x00C8, "ccBoss0510Gedo.unk_00C8 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_00F8) == 0x00F8, "ccBoss0510Gedo.unk_00F8 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_00FC) == 0x00FC, "ccBoss0510Gedo.unk_00FC offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0694) == 0x0694, "ccBoss0510Gedo.unk_0694 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0698) == 0x0698, "ccBoss0510Gedo.unk_0698 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_06A0) == 0x06A0, "ccBoss0510Gedo.unk_06A0 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_06E0) == 0x06E0, "ccBoss0510Gedo.unk_06E0 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_06E4) == 0x06E4, "ccBoss0510Gedo.unk_06E4 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_06EC) == 0x06EC, "ccBoss0510Gedo.unk_06EC offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_06F0) == 0x06F0, "ccBoss0510Gedo.unk_06F0 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_06F8) == 0x06F8, "ccBoss0510Gedo.unk_06F8 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0700) == 0x0700, "ccBoss0510Gedo.unk_0700 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0708) == 0x0708, "ccBoss0510Gedo.unk_0708 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0718) == 0x0718, "ccBoss0510Gedo.unk_0718 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0738) == 0x0738, "ccBoss0510Gedo.unk_0738 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0790) == 0x0790, "ccBoss0510Gedo.unk_0790 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0794) == 0x0794, "ccBoss0510Gedo.unk_0794 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_08B8) == 0x08B8, "ccBoss0510Gedo.unk_08B8 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_08FC) == 0x08FC, "ccBoss0510Gedo.unk_08FC offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0930) == 0x0930, "ccBoss0510Gedo.unk_0930 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0B78) == 0x0B78, "ccBoss0510Gedo.unk_0B78 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C28) == 0x0C28, "ccBoss0510Gedo.unk_0C28 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C48) == 0x0C48, "ccBoss0510Gedo.unk_0C48 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C4C) == 0x0C4C, "ccBoss0510Gedo.unk_0C4C offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C50) == 0x0C50, "ccBoss0510Gedo.unk_0C50 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C6C) == 0x0C6C, "ccBoss0510Gedo.unk_0C6C offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C70) == 0x0C70, "ccBoss0510Gedo.unk_0C70 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C74) == 0x0C74, "ccBoss0510Gedo.unk_0C74 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C88) == 0x0C88, "ccBoss0510Gedo.unk_0C88 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C8C) == 0x0C8C, "ccBoss0510Gedo.unk_0C8C offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C90) == 0x0C90, "ccBoss0510Gedo.unk_0C90 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C94) == 0x0C94, "ccBoss0510Gedo.unk_0C94 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C98) == 0x0C98, "ccBoss0510Gedo.unk_0C98 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0C9C) == 0x0C9C, "ccBoss0510Gedo.unk_0C9C offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_0CA0) == 0x0CA0, "ccBoss0510Gedo.unk_0CA0 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_319C) == 0x319C, "ccBoss0510Gedo.unk_319C offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_31B8) == 0x31B8, "ccBoss0510Gedo.unk_31B8 offset mismatch");
static_assert(offsetof(ccBoss0510Gedo, unk_3268) == 0x3268, "ccBoss0510Gedo.unk_3268 offset mismatch");

/* ccBoss0510GedoCpu - 11 seed methods, 21 fields, size >= 0x24C */
typedef struct __attribute__((packed)) ccBoss0510GedoCpu {
    uint8_t _pad0[0x1C]; /* fill to 0x001C */
    uint8_t unk_001C[8]; /* +0x001C type=int64_t w medium */
    uint8_t unk_0024[4]; /* +0x0024 type=uint32_t w high */
    uint8_t _pad1[0x4]; /* fill to 0x002C */
    uint8_t unk_002C[8]; /* +0x002C type=int64_t w medium */
    uint8_t unk_0034[8]; /* +0x0034 type=int64_t w medium */
    uint8_t unk_003C[4]; /* +0x003C type=uint32_t w medium */
    uint8_t _pad2[0x90]; /* fill to 0x00D0 */
    uint8_t unk_00D0[8]; /* +0x00D0 type=uint64_t w medium */
    uint8_t unk_00D8[4]; /* +0x00D8 type=uint32_t w medium */
    uint8_t _pad3[0x4]; /* fill to 0x00E0 */
    uint8_t unk_00E0[8]; /* +0x00E0 type=uint64_t w medium */
    uint8_t unk_00E8[8]; /* +0x00E8 type=uint64_t w medium */
    uint8_t _pad4[0x30]; /* fill to 0x0120 */
    uint8_t unk_0120[4]; /* +0x0120 type=uint32_t w medium */
    uint8_t _pad5[0xA0]; /* fill to 0x01C4 */
    uint8_t unk_01C4[8]; /* +0x01C4 type=int64_t w medium */
    uint8_t unk_01CC[8]; /* +0x01CC type=int64_t w medium */
    uint8_t unk_01D4[4]; /* +0x01D4 type=uint32_t w medium */
    uint8_t unk_01D8[8]; /* +0x01D8 type=uint64_t w medium */
    uint8_t unk_01E0[4]; /* +0x01E0 type=uint32_t w medium */
    uint8_t _pad6[0x40]; /* fill to 0x0224 */
    uint8_t unk_0224[8]; /* +0x0224 type=int64_t w medium */
    uint8_t unk_022C[8]; /* +0x022C type=int64_t w medium */
    uint8_t unk_0234[8]; /* +0x0234 type=int64_t w medium */
    uint8_t unk_023C[8]; /* +0x023C type=int64_t w medium */
    uint8_t unk_0244[4]; /* +0x0244 type=uint32_t w medium */
    uint8_t unk_0248[4]; /* +0x0248 type=uint32_t w medium */
} ccBoss0510GedoCpu;

/* offsetof assertions for ccBoss0510GedoCpu */
static_assert(offsetof(ccBoss0510GedoCpu, unk_001C) == 0x001C, "ccBoss0510GedoCpu.unk_001C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0024) == 0x0024, "ccBoss0510GedoCpu.unk_0024 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_002C) == 0x002C, "ccBoss0510GedoCpu.unk_002C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0034) == 0x0034, "ccBoss0510GedoCpu.unk_0034 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_003C) == 0x003C, "ccBoss0510GedoCpu.unk_003C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_00D0) == 0x00D0, "ccBoss0510GedoCpu.unk_00D0 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_00D8) == 0x00D8, "ccBoss0510GedoCpu.unk_00D8 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_00E0) == 0x00E0, "ccBoss0510GedoCpu.unk_00E0 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_00E8) == 0x00E8, "ccBoss0510GedoCpu.unk_00E8 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0120) == 0x0120, "ccBoss0510GedoCpu.unk_0120 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_01C4) == 0x01C4, "ccBoss0510GedoCpu.unk_01C4 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_01CC) == 0x01CC, "ccBoss0510GedoCpu.unk_01CC offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_01D4) == 0x01D4, "ccBoss0510GedoCpu.unk_01D4 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_01D8) == 0x01D8, "ccBoss0510GedoCpu.unk_01D8 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_01E0) == 0x01E0, "ccBoss0510GedoCpu.unk_01E0 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0224) == 0x0224, "ccBoss0510GedoCpu.unk_0224 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_022C) == 0x022C, "ccBoss0510GedoCpu.unk_022C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0234) == 0x0234, "ccBoss0510GedoCpu.unk_0234 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_023C) == 0x023C, "ccBoss0510GedoCpu.unk_023C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0244) == 0x0244, "ccBoss0510GedoCpu.unk_0244 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpu, unk_0248) == 0x0248, "ccBoss0510GedoCpu.unk_0248 offset mismatch");

/* ccBoss0510GedoCpuAction - 10 seed methods, 9 fields, size >= 0xD8 */
typedef struct __attribute__((packed)) ccBoss0510GedoCpuAction {
    uint8_t _pad0[0xC]; /* fill to 0x000C */
    uint8_t unk_000C[4]; /* +0x000C type=float r medium */
    uint8_t _pad1[0x4]; /* fill to 0x0014 */
    uint8_t unk_0014[8]; /* +0x0014 type=int64_t w low */
    uint8_t unk_001C[4]; /* +0x001C type=uint32_t w high */
    uint8_t _pad2[0x4]; /* fill to 0x0024 */
    uint8_t unk_0024[4]; /* +0x0024 type=uint32_t rw high */
    uint8_t _pad3[0x4]; /* fill to 0x002C */
    uint8_t unk_002C[4]; /* +0x002C type=float rw high */
    uint8_t _pad4[0x4]; /* fill to 0x0034 */
    uint8_t unk_0034[4]; /* +0x0034 type=uint32_t rw high */
    uint8_t _pad5[0x4]; /* fill to 0x003C */
    uint8_t unk_003C[4]; /* +0x003C type=uint32_t rw high */
    uint8_t _pad6[0x88]; /* fill to 0x00C8 */
    uint8_t init_unk_00C8[4]; /* +0x00C8 type=uint32_t w medium */
    uint8_t _pad7[0x4]; /* fill to 0x00D0 */
    uint8_t unk_00D0[8]; /* +0x00D0 type=uint64_t rw high */
} ccBoss0510GedoCpuAction;

/* offsetof assertions for ccBoss0510GedoCpuAction */
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_000C) == 0x000C, "ccBoss0510GedoCpuAction.unk_000C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_0014) == 0x0014, "ccBoss0510GedoCpuAction.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_001C) == 0x001C, "ccBoss0510GedoCpuAction.unk_001C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_0024) == 0x0024, "ccBoss0510GedoCpuAction.unk_0024 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_002C) == 0x002C, "ccBoss0510GedoCpuAction.unk_002C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_0034) == 0x0034, "ccBoss0510GedoCpuAction.unk_0034 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_003C) == 0x003C, "ccBoss0510GedoCpuAction.unk_003C offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, init_unk_00C8) == 0x00C8, "ccBoss0510GedoCpuAction.init_unk_00C8 offset mismatch");
static_assert(offsetof(ccBoss0510GedoCpuAction, unk_00D0) == 0x00D0, "ccBoss0510GedoCpuAction.unk_00D0 offset mismatch");

/* ccBoss0510GedoElectric - 3 seed methods, 7 fields, size >= 0x5C */
typedef struct __attribute__((packed)) ccBoss0510GedoElectric {
    uint8_t _pad0[0xC]; /* fill to 0x000C */
    uint8_t unk_000C[4]; /* +0x000C type=uint32_t w medium */
    uint8_t _pad1[0x4]; /* fill to 0x0014 */
    uint8_t unk_0014[4]; /* +0x0014 type=uint32_t w medium */
    uint8_t _pad2[0x1C]; /* fill to 0x0034 */
    uint8_t unk_0034[4]; /* +0x0034 type=uint32_t w medium */
    uint8_t _pad3[0x4]; /* fill to 0x003C */
    uint8_t unk_003C[4]; /* +0x003C type=uint32_t w medium */
    uint8_t _pad4[0x4]; /* fill to 0x0044 */
    uint8_t unk_0044[4]; /* +0x0044 type=uint32_t w medium */
    uint8_t _pad5[0x4]; /* fill to 0x004C */
    uint8_t unk_004C[4]; /* +0x004C type=uint32_t w medium */
    uint8_t _pad6[0x8]; /* fill to 0x0058 */
    uint8_t unk_0058[4]; /* +0x0058 type=uint32_t w medium */
} ccBoss0510GedoElectric;

/* offsetof assertions for ccBoss0510GedoElectric */
static_assert(offsetof(ccBoss0510GedoElectric, unk_000C) == 0x000C, "ccBoss0510GedoElectric.unk_000C offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectric, unk_0014) == 0x0014, "ccBoss0510GedoElectric.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectric, unk_0034) == 0x0034, "ccBoss0510GedoElectric.unk_0034 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectric, unk_003C) == 0x003C, "ccBoss0510GedoElectric.unk_003C offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectric, unk_0044) == 0x0044, "ccBoss0510GedoElectric.unk_0044 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectric, unk_004C) == 0x004C, "ccBoss0510GedoElectric.unk_004C offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectric, unk_0058) == 0x0058, "ccBoss0510GedoElectric.unk_0058 offset mismatch");

/* ccBoss0510GedoElectricManager - 9 seed methods, 8 fields, size >= 0x1260 */
typedef struct __attribute__((packed)) ccBoss0510GedoElectricManager {
    uint8_t _pad0[0x1210]; /* fill to 0x1210 */
    uint8_t unk_1210[8]; /* +0x1210 type=uint64_t w medium */
    uint8_t unk_1218[8]; /* +0x1218 type=uint64_t w medium */
    uint8_t unk_1220[8]; /* +0x1220 type=uint64_t w medium */
    uint8_t unk_1228[8]; /* +0x1228 type=uint64_t rw low */
    uint8_t _pad1[0x10]; /* fill to 0x1240 */
    uint8_t unk_1240[8]; /* +0x1240 type=uint64_t w medium */
    uint8_t unk_1248[8]; /* +0x1248 type=uint64_t w medium */
    uint8_t unk_1250[8]; /* +0x1250 type=uint64_t w medium */
    uint8_t unk_1258[8]; /* +0x1258 type=uint64_t rw low */
} ccBoss0510GedoElectricManager;

/* offsetof assertions for ccBoss0510GedoElectricManager */
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1210) == 0x1210, "ccBoss0510GedoElectricManager.unk_1210 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1218) == 0x1218, "ccBoss0510GedoElectricManager.unk_1218 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1220) == 0x1220, "ccBoss0510GedoElectricManager.unk_1220 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1228) == 0x1228, "ccBoss0510GedoElectricManager.unk_1228 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1240) == 0x1240, "ccBoss0510GedoElectricManager.unk_1240 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1248) == 0x1248, "ccBoss0510GedoElectricManager.unk_1248 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1250) == 0x1250, "ccBoss0510GedoElectricManager.unk_1250 offset mismatch");
static_assert(offsetof(ccBoss0510GedoElectricManager, unk_1258) == 0x1258, "ccBoss0510GedoElectricManager.unk_1258 offset mismatch");

/* ccBoss0510Tyo - 33 seed methods, 17 fields, size >= 0xC64 */
typedef struct __attribute__((packed)) ccBoss0510Tyo {
    uint8_t _pad0[0xC0]; /* fill to 0x00C0 */
    uint8_t unk_00C0[8]; /* +0x00C0 type=uint64_t r medium */
    uint8_t _pad1[0x5A8]; /* fill to 0x0670 */
    uint8_t unk_0670[8]; /* +0x0670 type=uint64_t r medium */
    uint8_t unk_0678[8]; /* +0x0678 type=uint64_t r medium */
    uint8_t _pad2[0x34]; /* fill to 0x06B4 */
    uint8_t unk_06B4[4]; /* +0x06B4 type=float w high */
    uint8_t unk_06B8[8]; /* +0x06B8 type=int64_t w medium */
    uint8_t unk_06C0[4]; /* +0x06C0 type=int32_t w medium */
    uint8_t _pad3[0x1C]; /* fill to 0x06E0 */
    uint8_t unk_06E0[4]; /* +0x06E0 type=uint32_t w medium */
    uint8_t _pad4[0x14]; /* fill to 0x06F8 */
    uint8_t unk_06F8[8]; /* +0x06F8 type=int64_t w medium */
    uint8_t unk_0700[8]; /* +0x0700 type=int64_t rw low */
    uint8_t unk_0708[4]; /* +0x0708 type=uint32_t w medium */
    uint8_t _pad5[0x28]; /* fill to 0x0734 */
    uint8_t unk_0734[4]; /* +0x0734 type=float r medium */
    uint8_t _pad6[0x178]; /* fill to 0x08B0 */
    uint8_t unk_08B0[4]; /* +0x08B0 type=float r medium */
    uint8_t unk_08B4[4]; /* +0x08B4 type=float rw medium */
    uint8_t _pad7[0x390]; /* fill to 0x0C48 */
    uint8_t unk_0C48[8]; /* +0x0C48 type=uint64_t w medium */
    uint8_t unk_0C50[4]; /* +0x0C50 type=uint32_t w medium */
    uint8_t _pad8[0x4]; /* fill to 0x0C58 */
    uint8_t unk_0C58[8]; /* +0x0C58 type=uint64_t w medium */
    uint8_t unk_0C60[4]; /* +0x0C60 type=int32_t rw medium */
} ccBoss0510Tyo;

/* offsetof assertions for ccBoss0510Tyo */
static_assert(offsetof(ccBoss0510Tyo, unk_00C0) == 0x00C0, "ccBoss0510Tyo.unk_00C0 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0670) == 0x0670, "ccBoss0510Tyo.unk_0670 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0678) == 0x0678, "ccBoss0510Tyo.unk_0678 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_06B4) == 0x06B4, "ccBoss0510Tyo.unk_06B4 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_06B8) == 0x06B8, "ccBoss0510Tyo.unk_06B8 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_06C0) == 0x06C0, "ccBoss0510Tyo.unk_06C0 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_06E0) == 0x06E0, "ccBoss0510Tyo.unk_06E0 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_06F8) == 0x06F8, "ccBoss0510Tyo.unk_06F8 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0700) == 0x0700, "ccBoss0510Tyo.unk_0700 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0708) == 0x0708, "ccBoss0510Tyo.unk_0708 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0734) == 0x0734, "ccBoss0510Tyo.unk_0734 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_08B0) == 0x08B0, "ccBoss0510Tyo.unk_08B0 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_08B4) == 0x08B4, "ccBoss0510Tyo.unk_08B4 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0C48) == 0x0C48, "ccBoss0510Tyo.unk_0C48 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0C50) == 0x0C50, "ccBoss0510Tyo.unk_0C50 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0C58) == 0x0C58, "ccBoss0510Tyo.unk_0C58 offset mismatch");
static_assert(offsetof(ccBoss0510Tyo, unk_0C60) == 0x0C60, "ccBoss0510Tyo.unk_0C60 offset mismatch");

/* ccBoss0510Mob - 7 seed methods, 10 fields, size >= 0x160 */
typedef struct __attribute__((packed)) ccBoss0510Mob {
    uint8_t _pad0[0x90]; /* fill to 0x0090 */
    uint8_t unk_0090[8]; /* +0x0090 type=uint64_t w medium */
    uint8_t unk_0098[8]; /* +0x0098 type=uint64_t w medium */
    uint8_t unk_00A0[4]; /* +0x00A0 type=uint32_t w medium */
    uint8_t unk_00A4[4]; /* +0x00A4 type=uint32_t w medium */
    uint8_t unk_00A8[4]; /* +0x00A8 type=uint32_t w medium */
    uint8_t unk_00AC[4]; /* +0x00AC type=uint32_t w medium */
    uint8_t _pad1[0x98]; /* fill to 0x0148 */
    uint8_t unk_0148[4]; /* +0x0148 type=uint32_t w medium */
    uint8_t unk_014C[4]; /* +0x014C type=uint32_t w medium */
    uint8_t unk_0150[4]; /* +0x0150 type=uint32_t w medium */
    uint8_t _pad2[0x4]; /* fill to 0x0158 */
    uint8_t unk_0158[8]; /* +0x0158 type=uint64_t w medium */
} ccBoss0510Mob;

/* offsetof assertions for ccBoss0510Mob */
static_assert(offsetof(ccBoss0510Mob, unk_0090) == 0x0090, "ccBoss0510Mob.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_0098) == 0x0098, "ccBoss0510Mob.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_00A0) == 0x00A0, "ccBoss0510Mob.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_00A4) == 0x00A4, "ccBoss0510Mob.unk_00A4 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_00A8) == 0x00A8, "ccBoss0510Mob.unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_00AC) == 0x00AC, "ccBoss0510Mob.unk_00AC offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_0148) == 0x0148, "ccBoss0510Mob.unk_0148 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_014C) == 0x014C, "ccBoss0510Mob.unk_014C offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_0150) == 0x0150, "ccBoss0510Mob.unk_0150 offset mismatch");
static_assert(offsetof(ccBoss0510Mob, unk_0158) == 0x0158, "ccBoss0510Mob.unk_0158 offset mismatch");

/* ccBoss0510MobAttack - 6 seed methods, 7 fields, size >= 0x60 */
typedef struct __attribute__((packed)) ccBoss0510MobAttack {
    uint8_t _pad0[0xC]; /* fill to 0x000C */
    uint8_t unk_000C[4]; /* +0x000C type=uint32_t w medium */
    uint8_t _pad1[0x4]; /* fill to 0x0014 */
    uint8_t unk_0014[4]; /* +0x0014 type=uint32_t w medium */
    uint8_t _pad2[0x24]; /* fill to 0x003C */
    uint8_t unk_003C[4]; /* +0x003C type=uint32_t w medium */
    uint8_t _pad3[0x4]; /* fill to 0x0044 */
    uint8_t unk_0044[4]; /* +0x0044 type=uint32_t w medium */
    uint8_t _pad4[0x4]; /* fill to 0x004C */
    uint8_t unk_004C[4]; /* +0x004C type=uint32_t w medium */
    uint8_t _pad5[0x8]; /* fill to 0x0058 */
    uint8_t unk_0058[4]; /* +0x0058 type=uint32_t w medium */
    uint8_t unk_005C[4]; /* +0x005C type=uint32_t w medium */
} ccBoss0510MobAttack;

/* offsetof assertions for ccBoss0510MobAttack */
static_assert(offsetof(ccBoss0510MobAttack, unk_000C) == 0x000C, "ccBoss0510MobAttack.unk_000C offset mismatch");
static_assert(offsetof(ccBoss0510MobAttack, unk_0014) == 0x0014, "ccBoss0510MobAttack.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss0510MobAttack, unk_003C) == 0x003C, "ccBoss0510MobAttack.unk_003C offset mismatch");
static_assert(offsetof(ccBoss0510MobAttack, unk_0044) == 0x0044, "ccBoss0510MobAttack.unk_0044 offset mismatch");
static_assert(offsetof(ccBoss0510MobAttack, unk_004C) == 0x004C, "ccBoss0510MobAttack.unk_004C offset mismatch");
static_assert(offsetof(ccBoss0510MobAttack, unk_0058) == 0x0058, "ccBoss0510MobAttack.unk_0058 offset mismatch");
static_assert(offsetof(ccBoss0510MobAttack, unk_005C) == 0x005C, "ccBoss0510MobAttack.unk_005C offset mismatch");

/* ccBoss0510MobAttackManager - 5 seed methods, 4 fields, size >= 0xC30 */
typedef struct __attribute__((packed)) ccBoss0510MobAttackManager {
    uint8_t _pad0[0xC10]; /* fill to 0x0C10 */
    uint8_t unk_0C10[8]; /* +0x0C10 type=uint64_t w medium */
    uint8_t unk_0C18[8]; /* +0x0C18 type=uint64_t w medium */
    uint8_t unk_0C20[8]; /* +0x0C20 type=uint64_t w medium */
    uint8_t unk_0C28[8]; /* +0x0C28 type=uint64_t rw low */
} ccBoss0510MobAttackManager;

/* offsetof assertions for ccBoss0510MobAttackManager */
static_assert(offsetof(ccBoss0510MobAttackManager, unk_0C10) == 0x0C10, "ccBoss0510MobAttackManager.unk_0C10 offset mismatch");
static_assert(offsetof(ccBoss0510MobAttackManager, unk_0C18) == 0x0C18, "ccBoss0510MobAttackManager.unk_0C18 offset mismatch");
static_assert(offsetof(ccBoss0510MobAttackManager, unk_0C20) == 0x0C20, "ccBoss0510MobAttackManager.unk_0C20 offset mismatch");
static_assert(offsetof(ccBoss0510MobAttackManager, unk_0C28) == 0x0C28, "ccBoss0510MobAttackManager.unk_0C28 offset mismatch");

/* ccBoss0510RkitAttack - 5 seed methods, 7 fields, size >= 0x5C */
typedef struct __attribute__((packed)) ccBoss0510RkitAttack {
    uint8_t _pad0[0xC]; /* fill to 0x000C */
    uint8_t unk_000C[4]; /* +0x000C type=uint32_t w medium */
    uint8_t _pad1[0x4]; /* fill to 0x0014 */
    uint8_t unk_0014[4]; /* +0x0014 type=uint32_t w medium */
    uint8_t _pad2[0x1C]; /* fill to 0x0034 */
    uint8_t unk_0034[4]; /* +0x0034 type=uint32_t w medium */
    uint8_t _pad3[0x4]; /* fill to 0x003C */
    uint8_t unk_003C[4]; /* +0x003C type=uint32_t w medium */
    uint8_t _pad4[0x4]; /* fill to 0x0044 */
    uint8_t unk_0044[4]; /* +0x0044 type=uint32_t w medium */
    uint8_t _pad5[0x4]; /* fill to 0x004C */
    uint8_t unk_004C[4]; /* +0x004C type=uint32_t w medium */
    uint8_t _pad6[0x8]; /* fill to 0x0058 */
    uint8_t unk_0058[4]; /* +0x0058 type=uint32_t w medium */
} ccBoss0510RkitAttack;

/* offsetof assertions for ccBoss0510RkitAttack */
static_assert(offsetof(ccBoss0510RkitAttack, unk_000C) == 0x000C, "ccBoss0510RkitAttack.unk_000C offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttack, unk_0014) == 0x0014, "ccBoss0510RkitAttack.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttack, unk_0034) == 0x0034, "ccBoss0510RkitAttack.unk_0034 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttack, unk_003C) == 0x003C, "ccBoss0510RkitAttack.unk_003C offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttack, unk_0044) == 0x0044, "ccBoss0510RkitAttack.unk_0044 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttack, unk_004C) == 0x004C, "ccBoss0510RkitAttack.unk_004C offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttack, unk_0058) == 0x0058, "ccBoss0510RkitAttack.unk_0058 offset mismatch");

/* ccBoss0510RkitAttackManager - 7 seed methods, 7 fields, size >= 0x958 */
typedef struct __attribute__((packed)) ccBoss0510RkitAttackManager {
    uint8_t _pad0[0x910]; /* fill to 0x0910 */
    uint8_t unk_0910[8]; /* +0x0910 type=uint64_t w medium */
    uint8_t unk_0918[8]; /* +0x0918 type=uint64_t w medium */
    uint8_t unk_0920[8]; /* +0x0920 type=uint64_t w medium */
    uint8_t unk_0928[8]; /* +0x0928 type=uint64_t rw low */
    uint8_t _pad1[0x10]; /* fill to 0x0940 */
    uint8_t unk_0940[8]; /* +0x0940 type=uint64_t w medium */
    uint8_t unk_0948[8]; /* +0x0948 type=uint64_t w medium */
    uint8_t unk_0950[8]; /* +0x0950 type=uint64_t w medium */
} ccBoss0510RkitAttackManager;

/* offsetof assertions for ccBoss0510RkitAttackManager */
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0910) == 0x0910, "ccBoss0510RkitAttackManager.unk_0910 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0918) == 0x0918, "ccBoss0510RkitAttackManager.unk_0918 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0920) == 0x0920, "ccBoss0510RkitAttackManager.unk_0920 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0928) == 0x0928, "ccBoss0510RkitAttackManager.unk_0928 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0940) == 0x0940, "ccBoss0510RkitAttackManager.unk_0940 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0948) == 0x0948, "ccBoss0510RkitAttackManager.unk_0948 offset mismatch");
static_assert(offsetof(ccBoss0510RkitAttackManager, unk_0950) == 0x0950, "ccBoss0510RkitAttackManager.unk_0950 offset mismatch");

/* ccBoss0510CutinRkit - 5 seed methods, 4 fields, size >= 0x1A8 */
typedef struct __attribute__((packed)) ccBoss0510CutinRkit {
    uint8_t _pad0[0x58]; /* fill to 0x0058 */
    uint8_t unk_0058[8]; /* +0x0058 type=uint64_t w medium */
    uint8_t unk_0060[8]; /* +0x0060 type=uint64_t w medium */
    uint8_t _pad1[0x130]; /* fill to 0x0198 */
    uint8_t unk_0198[4]; /* +0x0198 type=uint32_t w medium */
    uint8_t _pad2[0x4]; /* fill to 0x01A0 */
    uint8_t unk_01A0[8]; /* +0x01A0 type=uint64_t w medium */
} ccBoss0510CutinRkit;

/* offsetof assertions for ccBoss0510CutinRkit */
static_assert(offsetof(ccBoss0510CutinRkit, unk_0058) == 0x0058, "ccBoss0510CutinRkit.unk_0058 offset mismatch");
static_assert(offsetof(ccBoss0510CutinRkit, unk_0060) == 0x0060, "ccBoss0510CutinRkit.unk_0060 offset mismatch");
static_assert(offsetof(ccBoss0510CutinRkit, unk_0198) == 0x0198, "ccBoss0510CutinRkit.unk_0198 offset mismatch");
static_assert(offsetof(ccBoss0510CutinRkit, unk_01A0) == 0x01A0, "ccBoss0510CutinRkit.unk_01A0 offset mismatch");

/* ccBoss0510StageObject - 7 seed methods, 13 fields, size >= 0x170 */
typedef struct __attribute__((packed)) ccBoss0510StageObject {
    uint8_t _pad0[0x90]; /* fill to 0x0090 */
    uint8_t unk_0090[8]; /* +0x0090 type=uint64_t w medium */
    uint8_t unk_0098[8]; /* +0x0098 type=uint64_t w medium */
    uint8_t unk_00A0[4]; /* +0x00A0 type=uint32_t w medium */
    uint8_t unk_00A4[4]; /* +0x00A4 type=uint32_t w medium */
    uint8_t unk_00A8[4]; /* +0x00A8 type=uint32_t w medium */
    uint8_t unk_00AC[4]; /* +0x00AC type=uint32_t w medium */
    uint8_t unk_00B0[4]; /* +0x00B0 type=uint32_t w medium */
    uint8_t unk_00B4[4]; /* +0x00B4 type=uint32_t w medium */
    uint8_t unk_00B8[4]; /* +0x00B8 type=uint32_t w medium */
    uint8_t unk_00BC; /* +0x00BC type=uint8_t w medium */
    uint8_t _pad1[0x9B]; /* fill to 0x0158 */
    uint8_t unk_0158[4]; /* +0x0158 type=uint32_t w medium */
    uint8_t unk_015C[8]; /* +0x015C type=int64_t w medium */
    uint8_t _pad2[0x4]; /* fill to 0x0168 */
    uint8_t unk_0168[8]; /* +0x0168 type=uint64_t w medium */
} ccBoss0510StageObject;

/* offsetof assertions for ccBoss0510StageObject */
static_assert(offsetof(ccBoss0510StageObject, unk_0090) == 0x0090, "ccBoss0510StageObject.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_0098) == 0x0098, "ccBoss0510StageObject.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00A0) == 0x00A0, "ccBoss0510StageObject.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00A4) == 0x00A4, "ccBoss0510StageObject.unk_00A4 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00A8) == 0x00A8, "ccBoss0510StageObject.unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00AC) == 0x00AC, "ccBoss0510StageObject.unk_00AC offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00B0) == 0x00B0, "ccBoss0510StageObject.unk_00B0 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00B4) == 0x00B4, "ccBoss0510StageObject.unk_00B4 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00B8) == 0x00B8, "ccBoss0510StageObject.unk_00B8 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_00BC) == 0x00BC, "ccBoss0510StageObject.unk_00BC offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_0158) == 0x0158, "ccBoss0510StageObject.unk_0158 offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_015C) == 0x015C, "ccBoss0510StageObject.unk_015C offset mismatch");
static_assert(offsetof(ccBoss0510StageObject, unk_0168) == 0x0168, "ccBoss0510StageObject.unk_0168 offset mismatch");

/* ccBoss0510MessageForcusBlur - 4 seed methods, 1 fields, size >= 0x28 */
typedef struct __attribute__((packed)) ccBoss0510MessageForcusBlur {
    uint8_t _pad0[0x24]; /* fill to 0x0024 */
    uint8_t unk_0024[4]; /* +0x0024 type=uint32_t w medium */
} ccBoss0510MessageForcusBlur;

/* offsetof assertions for ccBoss0510MessageForcusBlur */
static_assert(offsetof(ccBoss0510MessageForcusBlur, unk_0024) == 0x0024, "ccBoss0510MessageForcusBlur.unk_0024 offset mismatch");

/* ccBoss05Effect - 16 seed methods, 6 fields, size >= 0x1B0 */
typedef struct __attribute__((packed)) ccBoss05Effect {
    uint8_t _pad0[0x1C]; /* fill to 0x001C */
    uint8_t unk_001C[8]; /* +0x001C type=int64_t w medium */
    uint8_t _pad1[0x34]; /* fill to 0x0058 */
    uint8_t unk_0058[4]; /* +0x0058 type=uint32_t w medium */
    uint8_t _pad2[0x4]; /* fill to 0x0060 */
    uint8_t unk_0060[8]; /* +0x0060 type=uint64_t w medium */
    uint8_t unk_0068[8]; /* +0x0068 type=uint64_t w medium */
    uint8_t _pad3[0x130]; /* fill to 0x01A0 */
    uint8_t unk_01A0[4]; /* +0x01A0 type=uint32_t w medium */
    uint8_t _pad4[0x4]; /* fill to 0x01A8 */
    uint8_t unk_01A8[8]; /* +0x01A8 type=uint64_t w medium */
} ccBoss05Effect;

/* offsetof assertions for ccBoss05Effect */
static_assert(offsetof(ccBoss05Effect, unk_001C) == 0x001C, "ccBoss05Effect.unk_001C offset mismatch");
static_assert(offsetof(ccBoss05Effect, unk_0058) == 0x0058, "ccBoss05Effect.unk_0058 offset mismatch");
static_assert(offsetof(ccBoss05Effect, unk_0060) == 0x0060, "ccBoss05Effect.unk_0060 offset mismatch");
static_assert(offsetof(ccBoss05Effect, unk_0068) == 0x0068, "ccBoss05Effect.unk_0068 offset mismatch");
static_assert(offsetof(ccBoss05Effect, unk_01A0) == 0x01A0, "ccBoss05Effect.unk_01A0 offset mismatch");
static_assert(offsetof(ccBoss05Effect, unk_01A8) == 0x01A8, "ccBoss05Effect.unk_01A8 offset mismatch");

/* ccBoss05EffectCharge - 5 seed methods, 3 fields, size >= 0x30 */
typedef struct __attribute__((packed)) ccBoss05EffectCharge {
    uint8_t _pad0[0x14]; /* fill to 0x0014 */
    uint8_t unk_0014[4]; /* +0x0014 type=int32_t rw high */
    uint8_t _pad1[0xC]; /* fill to 0x0024 */
    uint8_t unk_0024[4]; /* +0x0024 type=float rw medium */
    uint8_t _pad2[0x4]; /* fill to 0x002C */
    uint8_t unk_002C[4]; /* +0x002C type=uint32_t rw low */
} ccBoss05EffectCharge;

/* offsetof assertions for ccBoss05EffectCharge */
static_assert(offsetof(ccBoss05EffectCharge, unk_0014) == 0x0014, "ccBoss05EffectCharge.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss05EffectCharge, unk_0024) == 0x0024, "ccBoss05EffectCharge.unk_0024 offset mismatch");
static_assert(offsetof(ccBoss05EffectCharge, unk_002C) == 0x002C, "ccBoss05EffectCharge.unk_002C offset mismatch");

/* ccBoss05EffectManager - 8 seed methods, 6 fields, size >= 0xB8 */
typedef struct __attribute__((packed)) ccBoss05EffectManager {
    uint8_t _pad0[0x14]; /* fill to 0x0014 */
    uint8_t unk_0014; /* +0x0014 type=uint8_t w medium */
    uint8_t _pad1[0x7F]; /* fill to 0x0094 */
    uint8_t unk_0094[4]; /* +0x0094 type=uint32_t w medium */
    uint8_t unk_0098[8]; /* +0x0098 type=uint64_t w medium */
    uint8_t unk_00A0[8]; /* +0x00A0 type=uint64_t w medium */
    uint8_t unk_00A8[8]; /* +0x00A8 type=uint64_t w medium */
    uint8_t unk_00B0[8]; /* +0x00B0 type=uint64_t rw low */
} ccBoss05EffectManager;

/* offsetof assertions for ccBoss05EffectManager */
static_assert(offsetof(ccBoss05EffectManager, unk_0014) == 0x0014, "ccBoss05EffectManager.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss05EffectManager, unk_0094) == 0x0094, "ccBoss05EffectManager.unk_0094 offset mismatch");
static_assert(offsetof(ccBoss05EffectManager, unk_0098) == 0x0098, "ccBoss05EffectManager.unk_0098 offset mismatch");
static_assert(offsetof(ccBoss05EffectManager, unk_00A0) == 0x00A0, "ccBoss05EffectManager.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss05EffectManager, unk_00A8) == 0x00A8, "ccBoss05EffectManager.unk_00A8 offset mismatch");
static_assert(offsetof(ccBoss05EffectManager, unk_00B0) == 0x00B0, "ccBoss05EffectManager.unk_00B0 offset mismatch");

/* ccBoss05BattleTalk - 7 seed methods, 5 fields, size >= 0x9C */
typedef struct __attribute__((packed)) ccBoss05BattleTalk {
    uint8_t _pad0[0x88]; /* fill to 0x0088 */
    uint8_t unk_0088[4]; /* +0x0088 type=int32_t rw high */
    uint8_t unk_008C[4]; /* +0x008C type=uint32_t rw high */
    uint8_t unk_0090[4]; /* +0x0090 type=int32_t rw high */
    uint8_t unk_0094[4]; /* +0x0094 type=int32_t rw high */
    uint8_t unk_0098[4]; /* +0x0098 type=uint32_t w high */
} ccBoss05BattleTalk;

/* offsetof assertions for ccBoss05BattleTalk */
static_assert(offsetof(ccBoss05BattleTalk, unk_0088) == 0x0088, "ccBoss05BattleTalk.unk_0088 offset mismatch");
static_assert(offsetof(ccBoss05BattleTalk, unk_008C) == 0x008C, "ccBoss05BattleTalk.unk_008C offset mismatch");
static_assert(offsetof(ccBoss05BattleTalk, unk_0090) == 0x0090, "ccBoss05BattleTalk.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss05BattleTalk, unk_0094) == 0x0094, "ccBoss05BattleTalk.unk_0094 offset mismatch");
static_assert(offsetof(ccBoss05BattleTalk, unk_0098) == 0x0098, "ccBoss05BattleTalk.unk_0098 offset mismatch");

/* ccBoss05EventParamSet - 4 seed methods, 6 fields, size >= 0x90 */
typedef struct __attribute__((packed)) ccBoss05EventParamSet {
    uint8_t _pad0[0x14]; /* fill to 0x0014 */
    uint8_t unk_0014[4]; /* +0x0014 type=uint32_t w medium */
    uint8_t _pad1[0x40]; /* fill to 0x0058 */
    uint8_t unk_0058[8]; /* +0x0058 type=uint64_t w medium */
    uint8_t unk_0060[8]; /* +0x0060 type=uint64_t w medium */
    uint8_t unk_0068[8]; /* +0x0068 type=uint64_t rw low */
    uint8_t _pad2[0x10]; /* fill to 0x0080 */
    uint8_t unk_0080[4]; /* +0x0080 type=uint32_t w medium */
    uint8_t _pad3[0x4]; /* fill to 0x0088 */
    uint8_t unk_0088[8]; /* +0x0088 type=uint64_t w medium */
} ccBoss05EventParamSet;

/* offsetof assertions for ccBoss05EventParamSet */
static_assert(offsetof(ccBoss05EventParamSet, unk_0014) == 0x0014, "ccBoss05EventParamSet.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss05EventParamSet, unk_0058) == 0x0058, "ccBoss05EventParamSet.unk_0058 offset mismatch");
static_assert(offsetof(ccBoss05EventParamSet, unk_0060) == 0x0060, "ccBoss05EventParamSet.unk_0060 offset mismatch");
static_assert(offsetof(ccBoss05EventParamSet, unk_0068) == 0x0068, "ccBoss05EventParamSet.unk_0068 offset mismatch");
static_assert(offsetof(ccBoss05EventParamSet, unk_0080) == 0x0080, "ccBoss05EventParamSet.unk_0080 offset mismatch");
static_assert(offsetof(ccBoss05EventParamSet, unk_0088) == 0x0088, "ccBoss05EventParamSet.unk_0088 offset mismatch");

/* ccUiBoss0510PlayerGauge - 4 seed methods, 3 fields, size >= 0x220 */
typedef struct __attribute__((packed)) ccUiBoss0510PlayerGauge {
    uint8_t _pad0[0x2C]; /* fill to 0x002C */
    uint8_t unk_002C[4]; /* +0x002C type=uint32_t w medium */
    uint8_t unk_0030[8]; /* +0x0030 type=uint64_t rw high */
    uint8_t _pad1[0x1E0]; /* fill to 0x0218 */
    uint8_t unk_0218[8]; /* +0x0218 type=uint64_t w medium */
} ccUiBoss0510PlayerGauge;

/* offsetof assertions for ccUiBoss0510PlayerGauge */
static_assert(offsetof(ccUiBoss0510PlayerGauge, unk_002C) == 0x002C, "ccUiBoss0510PlayerGauge.unk_002C offset mismatch");
static_assert(offsetof(ccUiBoss0510PlayerGauge, unk_0030) == 0x0030, "ccUiBoss0510PlayerGauge.unk_0030 offset mismatch");
static_assert(offsetof(ccUiBoss0510PlayerGauge, unk_0218) == 0x0218, "ccUiBoss0510PlayerGauge.unk_0218 offset mismatch");

/* ccUiBoss0510Target - 5 seed methods, 6 fields, size >= 0xA8 */
typedef struct __attribute__((packed)) ccUiBoss0510Target {
    uint8_t _pad0[0x3C]; /* fill to 0x003C */
    uint8_t init_unk_003C[4]; /* +0x003C type=uint32_t w medium */
    uint8_t _pad1[0x40]; /* fill to 0x0080 */
    uint8_t init_unk_0080[8]; /* +0x0080 type=uint64_t w medium */
    uint8_t init_unk_0088[8]; /* +0x0088 type=uint64_t w medium */
    uint8_t init_unk_0090[8]; /* +0x0090 type=uint64_t w medium */
    uint8_t unk_0098[8]; /* +0x0098 type=uint64_t w low */
    uint8_t init_unk_00A0[8]; /* +0x00A0 type=uint64_t w medium */
} ccUiBoss0510Target;

/* offsetof assertions for ccUiBoss0510Target */
static_assert(offsetof(ccUiBoss0510Target, init_unk_003C) == 0x003C, "ccUiBoss0510Target.init_unk_003C offset mismatch");
static_assert(offsetof(ccUiBoss0510Target, init_unk_0080) == 0x0080, "ccUiBoss0510Target.init_unk_0080 offset mismatch");
static_assert(offsetof(ccUiBoss0510Target, init_unk_0088) == 0x0088, "ccUiBoss0510Target.init_unk_0088 offset mismatch");
static_assert(offsetof(ccUiBoss0510Target, init_unk_0090) == 0x0090, "ccUiBoss0510Target.init_unk_0090 offset mismatch");
static_assert(offsetof(ccUiBoss0510Target, unk_0098) == 0x0098, "ccUiBoss0510Target.unk_0098 offset mismatch");
static_assert(offsetof(ccUiBoss0510Target, init_unk_00A0) == 0x00A0, "ccUiBoss0510Target.init_unk_00A0 offset mismatch");

#endif /* S3BOSS05_H */

/* ccBoss05EffectAtk - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss05EffectAtk {
    uint8_t _pad0[0x10]; /* fill to 0x0010 */
    uint8_t unk_0010[8]; /* +0x0010 type=uint64_t rw medium */
    uint8_t _pad1[0x1]; /* fill to 0x0019 */
    uint8_t unk_0019[4]; /* +0x0019 type=uint32_t rw medium */
    uint8_t _pad2[0x22]; /* fill to 0x003F */
    uint8_t unk_003F[4]; /* +0x003F type=uint32_t rw medium */
    uint8_t _pad3[0x4D]; /* fill to 0x0090 */
    uint8_t unk_0090[4]; /* +0x0090 type=int32_t rw medium */
    uint8_t _pad4[0xC]; /* fill to 0x00A0 */
    uint8_t unk_00A0[8]; /* +0x00A0 type=uint64_t rw medium */
    uint8_t _pad5[0x38]; /* fill to 0x00E0 */
    uint8_t unk_00E0[4]; /* +0x00E0 type=int32_t rw medium */
    uint8_t _pad6[0x24]; /* fill to 0x0108 */
    uint8_t unk_0108[4]; /* +0x0108 type=uint32_t rw medium */
    uint8_t _pad7[0x64]; /* fill to 0x0170 */
    uint8_t unk_0170[8]; /* +0x0170 type=uint64_t rw medium */
    uint8_t unk_0178[8]; /* +0x0178 type=uint64_t rw medium */
    uint8_t unk_0180[8]; /* +0x0180 type=uint64_t rw medium */
    uint8_t unk_0188[8]; /* +0x0188 type=uint64_t rw medium */
    uint8_t _pad8[0x8]; /* fill to 0x0198 */
    uint8_t unk_0198[8]; /* +0x0198 type=uint64_t rw medium */
    uint8_t unk_01A0[8]; /* +0x01A0 type=uint64_t rw medium */
    uint8_t unk_01A8[8]; /* +0x01A8 type=uint64_t rw medium */
    uint8_t unk_01B0[8]; /* +0x01B0 type=uint64_t rw medium */
    uint8_t unk_01B8[8]; /* +0x01B8 type=uint64_t rw medium */
    uint8_t unk_01C0[8]; /* +0x01C0 type=uint64_t rw medium */
    uint8_t unk_01C8[8]; /* +0x01C8 type=uint64_t rw medium */
    uint8_t unk_01D0[8]; /* +0x01D0 type=uint64_t rw medium */
    uint8_t unk_01D8[8]; /* +0x01D8 type=uint64_t rw medium */
    uint8_t unk_01E0[8]; /* +0x01E0 type=uint64_t rw medium */
    uint8_t unk_01E8[8]; /* +0x01E8 type=uint64_t rw medium */
    uint8_t unk_01F0[8]; /* +0x01F0 type=uint64_t rw medium */
    uint8_t unk_01F8[4]; /* +0x01F8 type=int32_t rw medium */
    uint8_t unk_01FC[4]; /* +0x01FC type=float rw medium */
    uint8_t unk_0200[4]; /* +0x0200 type=uint32_t rw medium */
    uint8_t unk_0204[4]; /* +0x0204 type=float rw medium */
    uint8_t unk_0208[4]; /* +0x0208 type=float rw medium */
    uint8_t unk_020C[4]; /* +0x020C type=float rw medium */
    uint8_t unk_0210[8]; /* +0x0210 type=uint64_t rw medium */
    uint8_t unk_0218[4]; /* +0x0218 type=float rw medium */
    uint8_t _pad9[0x8]; /* fill to 0x0224 */
    uint8_t unk_0224[4]; /* +0x0224 type=uint32_t rw medium */
    uint8_t _pad10[0xC]; /* fill to 0x0234 */
    uint8_t unk_0234[4]; /* +0x0234 type=uint32_t rw medium */
    uint8_t unk_0238[8]; /* +0x0238 type=uint64_t rw medium */
    uint8_t unk_0240[4]; /* +0x0240 type=int32_t rw medium */
    uint8_t unk_0244[4]; /* +0x0244 type=int32_t rw medium */
    uint8_t unk_0248[4]; /* +0x0248 type=uint32_t rw medium */
    uint8_t unk_024C[8]; /* +0x024C type=uint64_t rw medium */
    uint8_t unk_0254[4]; /* +0x0254 type=uint32_t rw medium */
    uint8_t _pad11[0x8]; /* fill to 0x0260 */
    uint8_t unk_0260[4]; /* +0x0260 type=uint32_t rw medium */
    uint8_t unk_0264[8]; /* +0x0264 type=uint64_t rw medium */
    uint8_t _pad12[0x4]; /* fill to 0x0270 */
    uint8_t unk_0270[4]; /* +0x0270 type=uint64_t rw medium */
    uint8_t _pad13[0x4]; /* fill to 0x0278 */
    uint8_t unk_0278[8]; /* +0x0278 type=uint64_t rw medium */
} ccBoss05EffectAtk;

static_assert(offsetof(ccBoss05EffectAtk, unk_0010) == 0x10, "ccBoss05EffectAtk.unk_0010");
static_assert(offsetof(ccBoss05EffectAtk, unk_0019) == 0x19, "ccBoss05EffectAtk.unk_0019");
static_assert(offsetof(ccBoss05EffectAtk, unk_003F) == 0x3F, "ccBoss05EffectAtk.unk_003F");
static_assert(offsetof(ccBoss05EffectAtk, unk_0090) == 0x90, "ccBoss05EffectAtk.unk_0090");
static_assert(offsetof(ccBoss05EffectAtk, unk_00A0) == 0xA0, "ccBoss05EffectAtk.unk_00A0");
static_assert(offsetof(ccBoss05EffectAtk, unk_00E0) == 0xE0, "ccBoss05EffectAtk.unk_00E0");
static_assert(offsetof(ccBoss05EffectAtk, unk_0108) == 0x108, "ccBoss05EffectAtk.unk_0108");
static_assert(offsetof(ccBoss05EffectAtk, unk_0170) == 0x170, "ccBoss05EffectAtk.unk_0170");
static_assert(offsetof(ccBoss05EffectAtk, unk_0178) == 0x178, "ccBoss05EffectAtk.unk_0178");
static_assert(offsetof(ccBoss05EffectAtk, unk_0180) == 0x180, "ccBoss05EffectAtk.unk_0180");
static_assert(offsetof(ccBoss05EffectAtk, unk_0188) == 0x188, "ccBoss05EffectAtk.unk_0188");
static_assert(offsetof(ccBoss05EffectAtk, unk_0198) == 0x198, "ccBoss05EffectAtk.unk_0198");
static_assert(offsetof(ccBoss05EffectAtk, unk_01A0) == 0x1A0, "ccBoss05EffectAtk.unk_01A0");
static_assert(offsetof(ccBoss05EffectAtk, unk_01A8) == 0x1A8, "ccBoss05EffectAtk.unk_01A8");
static_assert(offsetof(ccBoss05EffectAtk, unk_01B0) == 0x1B0, "ccBoss05EffectAtk.unk_01B0");
static_assert(offsetof(ccBoss05EffectAtk, unk_01B8) == 0x1B8, "ccBoss05EffectAtk.unk_01B8");
static_assert(offsetof(ccBoss05EffectAtk, unk_01C0) == 0x1C0, "ccBoss05EffectAtk.unk_01C0");
static_assert(offsetof(ccBoss05EffectAtk, unk_01C8) == 0x1C8, "ccBoss05EffectAtk.unk_01C8");
static_assert(offsetof(ccBoss05EffectAtk, unk_01D0) == 0x1D0, "ccBoss05EffectAtk.unk_01D0");
static_assert(offsetof(ccBoss05EffectAtk, unk_01D8) == 0x1D8, "ccBoss05EffectAtk.unk_01D8");
static_assert(offsetof(ccBoss05EffectAtk, unk_01E0) == 0x1E0, "ccBoss05EffectAtk.unk_01E0");
static_assert(offsetof(ccBoss05EffectAtk, unk_01E8) == 0x1E8, "ccBoss05EffectAtk.unk_01E8");
static_assert(offsetof(ccBoss05EffectAtk, unk_01F0) == 0x1F0, "ccBoss05EffectAtk.unk_01F0");
static_assert(offsetof(ccBoss05EffectAtk, unk_01F8) == 0x1F8, "ccBoss05EffectAtk.unk_01F8");
static_assert(offsetof(ccBoss05EffectAtk, unk_01FC) == 0x1FC, "ccBoss05EffectAtk.unk_01FC");
static_assert(offsetof(ccBoss05EffectAtk, unk_0200) == 0x200, "ccBoss05EffectAtk.unk_0200");
static_assert(offsetof(ccBoss05EffectAtk, unk_0204) == 0x204, "ccBoss05EffectAtk.unk_0204");
static_assert(offsetof(ccBoss05EffectAtk, unk_0208) == 0x208, "ccBoss05EffectAtk.unk_0208");
static_assert(offsetof(ccBoss05EffectAtk, unk_020C) == 0x20C, "ccBoss05EffectAtk.unk_020C");
static_assert(offsetof(ccBoss05EffectAtk, unk_0210) == 0x210, "ccBoss05EffectAtk.unk_0210");
static_assert(offsetof(ccBoss05EffectAtk, unk_0218) == 0x218, "ccBoss05EffectAtk.unk_0218");
static_assert(offsetof(ccBoss05EffectAtk, unk_0224) == 0x224, "ccBoss05EffectAtk.unk_0224");
static_assert(offsetof(ccBoss05EffectAtk, unk_0234) == 0x234, "ccBoss05EffectAtk.unk_0234");
static_assert(offsetof(ccBoss05EffectAtk, unk_0238) == 0x238, "ccBoss05EffectAtk.unk_0238");
static_assert(offsetof(ccBoss05EffectAtk, unk_0240) == 0x240, "ccBoss05EffectAtk.unk_0240");
static_assert(offsetof(ccBoss05EffectAtk, unk_0244) == 0x244, "ccBoss05EffectAtk.unk_0244");
static_assert(offsetof(ccBoss05EffectAtk, unk_0248) == 0x248, "ccBoss05EffectAtk.unk_0248");
static_assert(offsetof(ccBoss05EffectAtk, unk_024C) == 0x24C, "ccBoss05EffectAtk.unk_024C");
static_assert(offsetof(ccBoss05EffectAtk, unk_0254) == 0x254, "ccBoss05EffectAtk.unk_0254");
static_assert(offsetof(ccBoss05EffectAtk, unk_0260) == 0x260, "ccBoss05EffectAtk.unk_0260");
static_assert(offsetof(ccBoss05EffectAtk, unk_0264) == 0x264, "ccBoss05EffectAtk.unk_0264");
static_assert(offsetof(ccBoss05EffectAtk, unk_0270) == 0x270, "ccBoss05EffectAtk.unk_0270");
static_assert(offsetof(ccBoss05EffectAtk, unk_0278) == 0x278, "ccBoss05EffectAtk.unk_0278");


/* ccBoss0510Camera - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss0510Camera {
    uint8_t _pad0[0x6C]; /* fill to 0x006C */
    uint8_t unk_006C[4]; /* +0x006C type=uint32_t rw medium */
    uint8_t _pad1[0x86C]; /* fill to 0x08DC */
    uint8_t unk_08DC[4]; /* +0x08DC type=uint32_t rw medium */
    uint8_t _pad2[0x4]; /* fill to 0x08E4 */
    uint8_t unk_08E4[8]; /* +0x08E4 type=uint64_t rw medium */
    uint8_t unk_08EC[4]; /* +0x08EC type=uint32_t rw medium */
    uint8_t unk_08F0[8]; /* +0x08F0 type=uint64_t rw medium */
    uint8_t unk_08F8[4]; /* +0x08F8 type=uint32_t rw medium */
    uint8_t unk_08FC[4]; /* +0x08FC type=uint32_t rw medium */
    uint8_t unk_0900[4]; /* +0x0900 type=uint32_t rw medium */
    uint8_t unk_0904[4]; /* +0x0904 type=uint32_t rw medium */
    uint8_t unk_0908[4]; /* +0x0908 type=uint32_t rw medium */
    uint8_t unk_090C[4]; /* +0x090C type=uint32_t rw medium */
    uint8_t unk_0910[4]; /* +0x0910 type=uint32_t rw medium */
    uint8_t unk_0914[4]; /* +0x0914 type=uint32_t rw medium */
    uint8_t unk_0918[4]; /* +0x0918 type=uint32_t rw medium */
    uint8_t _pad_final[0x4]; /* fill to 0x920 */
} ccBoss0510Camera;

static_assert(offsetof(ccBoss0510Camera, unk_006C) == 0x6C, "ccBoss0510Camera.unk_006C");
static_assert(offsetof(ccBoss0510Camera, unk_08DC) == 0x8DC, "ccBoss0510Camera.unk_08DC");
static_assert(offsetof(ccBoss0510Camera, unk_08E4) == 0x8E4, "ccBoss0510Camera.unk_08E4");
static_assert(offsetof(ccBoss0510Camera, unk_08EC) == 0x8EC, "ccBoss0510Camera.unk_08EC");
static_assert(offsetof(ccBoss0510Camera, unk_08F0) == 0x8F0, "ccBoss0510Camera.unk_08F0");
static_assert(offsetof(ccBoss0510Camera, unk_08F8) == 0x8F8, "ccBoss0510Camera.unk_08F8");
static_assert(offsetof(ccBoss0510Camera, unk_08FC) == 0x8FC, "ccBoss0510Camera.unk_08FC");
static_assert(offsetof(ccBoss0510Camera, unk_0900) == 0x900, "ccBoss0510Camera.unk_0900");
static_assert(offsetof(ccBoss0510Camera, unk_0904) == 0x904, "ccBoss0510Camera.unk_0904");
static_assert(offsetof(ccBoss0510Camera, unk_0908) == 0x908, "ccBoss0510Camera.unk_0908");
static_assert(offsetof(ccBoss0510Camera, unk_090C) == 0x90C, "ccBoss0510Camera.unk_090C");
static_assert(offsetof(ccBoss0510Camera, unk_0910) == 0x910, "ccBoss0510Camera.unk_0910");
static_assert(offsetof(ccBoss0510Camera, unk_0914) == 0x914, "ccBoss0510Camera.unk_0914");
static_assert(offsetof(ccBoss0510Camera, unk_0918) == 0x918, "ccBoss0510Camera.unk_0918");


/* ccBoss0510PlayerEffect - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss0510PlayerEffect {
    uint8_t _pad0[0x20]; /* fill to 0x0020 */
    uint8_t unk_0020[4]; /* +0x0020 type=int32_t rw medium */
    uint8_t unk_0024[4]; /* +0x0024 type=int32_t rw medium */
} ccBoss0510PlayerEffect;

static_assert(offsetof(ccBoss0510PlayerEffect, unk_0020) == 0x20, "ccBoss0510PlayerEffect.unk_0020");
static_assert(offsetof(ccBoss0510PlayerEffect, unk_0024) == 0x24, "ccBoss0510PlayerEffect.unk_0024");


/* ccSceneBoss0510 - INFERRED, static analysis only */
/* ccSceneBoss0510: no instance state detected (no fields found) */


/* ccBoss05PlayerEffect - INFERRED, static analysis only */
/* ccBoss05PlayerEffect: no instance state detected (no fields found) */


/* ccBoss05HitSphereGroup - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss05HitSphereGroup {
    uint8_t _pad0[0x10]; /* fill to 0x0010 */
    uint8_t unk_0010[4]; /* +0x0010 type=int32_t rw medium */
    uint8_t _pad1[0x5C]; /* fill to 0x0070 */
    uint8_t unk_0070[8]; /* +0x0070 type=uint64_t rw medium */
    uint8_t _pad2[0x8]; /* fill to 0x0080 */
    uint8_t unk_0080[8]; /* +0x0080 type=uint64_t rw medium */
} ccBoss05HitSphereGroup;

static_assert(offsetof(ccBoss05HitSphereGroup, unk_0010) == 0x10, "ccBoss05HitSphereGroup.unk_0010");
static_assert(offsetof(ccBoss05HitSphereGroup, unk_0070) == 0x70, "ccBoss05HitSphereGroup.unk_0070");
static_assert(offsetof(ccBoss05HitSphereGroup, unk_0080) == 0x80, "ccBoss05HitSphereGroup.unk_0080");


/* ccBoss05Camera - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss05Camera {
    uint8_t _pad0[0xE0]; /* fill to 0x00E0 */
    uint8_t unk_00E0[8]; /* +0x00E0 type=uint64_t rw medium */
    uint8_t _pad1[0xC8]; /* fill to 0x01B0 */
    uint8_t unk_01B0[8]; /* +0x01B0 type=uint64_t rw medium */
} ccBoss05Camera;

static_assert(offsetof(ccBoss05Camera, unk_00E0) == 0xE0, "ccBoss05Camera.unk_00E0");
static_assert(offsetof(ccBoss05Camera, unk_01B0) == 0x1B0, "ccBoss05Camera.unk_01B0");


/* ccBoss0510GedoElectricGeneratorSpecial - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss0510GedoElectricGeneratorSpecial {
    uint8_t _pad0[0x10]; /* fill to 0x0010 */
    uint8_t unk_0010[8]; /* +0x0010 type=uint64_t rw medium */
} ccBoss0510GedoElectricGeneratorSpecial;

static_assert(offsetof(ccBoss0510GedoElectricGeneratorSpecial, unk_0010) == 0x10, "ccBoss0510GedoElectricGeneratorSpecial.unk_0010");


/* ccBoss0510SequenceState - INFERRED, static analysis only */
typedef struct __attribute__((packed)) ccBoss0510SequenceState {
    uint8_t _pad0[0x54]; /* fill to 0x0054 */
    uint8_t unk_0054[4]; /* +0x0054 type=uint32_t rw medium */
    uint8_t _pad1[0x8]; /* fill to 0x0060 */
    uint8_t unk_0060[4]; /* +0x0060 type=uint32_t rw medium */
    uint8_t _pad2[0xC]; /* fill to 0x0070 */
    uint8_t unk_0070[8]; /* +0x0070 type=uint64_t rw medium */
    uint8_t unk_0078[8]; /* +0x0078 type=uint64_t rw medium */
} ccBoss0510SequenceState;

static_assert(offsetof(ccBoss0510SequenceState, unk_0054) == 0x54, "ccBoss0510SequenceState.unk_0054");
static_assert(offsetof(ccBoss0510SequenceState, unk_0060) == 0x60, "ccBoss0510SequenceState.unk_0060");
static_assert(offsetof(ccBoss0510SequenceState, unk_0070) == 0x70, "ccBoss0510SequenceState.unk_0070");
static_assert(offsetof(ccBoss0510SequenceState, unk_0078) == 0x78, "ccBoss0510SequenceState.unk_0078");


/* ccBoss0510Sequence - INFERRED, static analysis only */
/* ccBoss0510Sequence: no instance state detected (no fields found) */


/* ccBoss0510Tyo::FireArmRoc - INFERRED, static analysis only */
/* ccBoss0510Tyo::FireArmRoc: no instance state detected (no fields found) */


/* ccBoss0510Stage - 4 seed methods, 3 fields, size >= 0x68 */
typedef struct __attribute__((packed)) ccBoss0510Stage {
	uint8_t _pad0[0x8]; /* fill to 0x0008 */
	uint8_t unk_0008[8]; /* +0x0008 type=ptr rw high (stage data ptr, Initialize/Update) */
	uint8_t _pad1[0x50]; /* fill to 0x0060 (0x60 - 0x10 = 0x50) */
	uint8_t unk_0060[4]; /* +0x0060 type=float rw high (timer, Update) */
	uint8_t unk_0064[4]; /* +0x0064 type=int32_t rw high (param index, Update) */
} ccBoss0510Stage;
/* offsetof assertions for ccBoss0510Stage */
static_assert(offsetof(ccBoss0510Stage, unk_0008) == 0x0008, "ccBoss0510Stage.unk_0008");
static_assert(offsetof(ccBoss0510Stage, unk_0060) == 0x0060, "ccBoss0510Stage.unk_0060");
static_assert(offsetof(ccBoss0510Stage, unk_0064) == 0x0064, "ccBoss0510Stage.unk_0064");


/* ccBoss05CameraAnm - 3 seed methods, 7 fields, size >= 0x8FC */
typedef struct __attribute__((packed)) ccBoss05CameraAnm {
	uint8_t _pad0[0x40]; /* fill to 0x0040 */
	uint8_t unk_0040[8]; /* +0x0040 type=ptr rw high (camera matrix base, UpdateAnmCam/Manipulate) */
	uint8_t _pad1[0x24]; /* fill to 0x006C (0x6C - 0x48 = 0x24) */
	uint8_t unk_006C[4]; /* +0x006C type=int32_t rw medium (copy from target+0x2c, UpdateAnmCam) */
	uint8_t unk_0070[8]; /* +0x0070 type=ptr rw high (cam pos storage, UpdateAnmCam/Manipulate) */
	uint8_t _pad3[0x860]; /* fill to 0x08D8 (0x8D8 - 0x78 = 0x860) */
	uint8_t unk_08D8[8]; /* +0x08D8 type=ptr rw high (target object ptr, UpdateAnmCam/FlipX) */
	uint8_t unk_08E0[1]; /* +0x08E0 type=uint8_t rw high (flags byte, UpdateAnmCam/Manipulate/FlipX) */
	uint8_t _pad4[0x13]; /* fill to 0x08F4 (0x8F4 - 0x8E1 = 0x13) */
	uint8_t unk_08F4[4]; /* +0x08F4 type=float rw high (yaw rate, Manipulate) */
	uint8_t unk_08F8[4]; /* +0x08F8 type=float rw high (pitch rate, Manipulate) */
} ccBoss05CameraAnm;
/* offsetof assertions for ccBoss05CameraAnm */
static_assert(offsetof(ccBoss05CameraAnm, unk_0040) == 0x0040, "ccBoss05CameraAnm.unk_0040");
static_assert(offsetof(ccBoss05CameraAnm, unk_006C) == 0x006C, "ccBoss05CameraAnm.unk_006C");
static_assert(offsetof(ccBoss05CameraAnm, unk_0070) == 0x0070, "ccBoss05CameraAnm.unk_0070");
static_assert(offsetof(ccBoss05CameraAnm, unk_08D8) == 0x08D8, "ccBoss05CameraAnm.unk_08D8");
static_assert(offsetof(ccBoss05CameraAnm, unk_08E0) == 0x08E0, "ccBoss05CameraAnm.unk_08E0");
static_assert(offsetof(ccBoss05CameraAnm, unk_08F4) == 0x08F4, "ccBoss05CameraAnm.unk_08F4");
static_assert(offsetof(ccBoss05CameraAnm, unk_08F8) == 0x08F8, "ccBoss05CameraAnm.unk_08F8");


/* ccBoss05CollisionSphere - 3 seed methods, 3 fields, size >= 0xC0 */
typedef struct __attribute__((packed)) ccBoss05CollisionSphere {
	uint8_t _pad0[0x8]; /* fill to 0x0008 */
	uint8_t unk_0008[8]; /* +0x0008 type=ptr rw high (sphere data ptr, Update/Enable) */
	uint8_t _pad1[0x80]; /* fill to 0x0090 (0x90 - 0x10 = 0x80) */
	uint8_t unk_0090[4]; /* +0x0090 type=int32_t rw high (enabled flag, Disable sets 0) */
	uint8_t _pad2[0x1C]; /* fill to 0x00B0 (0xB0 - 0x94 = 0x1C) */
	uint8_t unk_00B0[16]; /* +0x00B0 type=ptr[2] rw high (child spheres, Disable iterates) */
} ccBoss05CollisionSphere;
/* offsetof assertions for ccBoss05CollisionSphere */
static_assert(offsetof(ccBoss05CollisionSphere, unk_0008) == 0x0008, "ccBoss05CollisionSphere.unk_0008");
static_assert(offsetof(ccBoss05CollisionSphere, unk_0090) == 0x0090, "ccBoss05CollisionSphere.unk_0090");
static_assert(offsetof(ccBoss05CollisionSphere, unk_00B0) == 0x00B0, "ccBoss05CollisionSphere.unk_00B0");


/* ccBoss05EventParamManager - 3 seed methods, 0 fields, size 0x38 (alloc in Create) */
/* ccBoss05EventParamManager: singleton manager, no instance fields beyond vtable+padding */
typedef struct __attribute__((packed)) ccBoss05EventParamManager {
	uint8_t _opaque[0x38]; /* alloc size 0x38 from Create; no field accesses found in Create/Entry/GetParamSet */
} ccBoss05EventParamManager;
static_assert(sizeof(ccBoss05EventParamManager) == 0x38, "ccBoss05EventParamManager size");
