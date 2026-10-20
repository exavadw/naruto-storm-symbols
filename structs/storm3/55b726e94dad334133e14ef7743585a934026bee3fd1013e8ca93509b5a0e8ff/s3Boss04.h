/* s3Boss04.h - Storm 3 Full Burst HD boss battle structs (INFERRED, static analysis only)
 * Generated from state_surface + decompilation data for build s3 (NSUNS3.exe 64-bit)
 * Group: ccBoss04*, ccSceneBoss04*, ccCameraJudgeBoss04*, ccCamOpeBoss04*, ccUiBoss04*
 * All fields are INFERRED unless marked CONFIRMED.
 * Uses #pragma pack(1) to match binary layout exactly (no implicit alignment padding).
 * Overlapping sub-fields from state_surface are deduplicated (larger field wins).
 */
#ifndef S3BOSS04_H
#define S3BOSS04_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccBoss0401 - 32 seed methods, 6 surface fields
 * Size: unknown, >= 0x134 (from constructor/destructor field access)
 * Base: ccBossBattleSituationVoice
 * Main boss battle controller for Battle01. Embedded ccBossBattleSituationVoice at +0x10.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401 {
    uint8_t pad_0000[0xD8]; /* 0x0000-0x00D8 */
    int64_t unk_00D8; /* +0x00D8 rw medium */
    int64_t unk_00E0; /* +0x00E0 rw medium */
    uint8_t pad_00E8[0x8]; /* 0x00E8-0x00F0 */
    uint8_t unk_00F0; /* +0x00F0 rw medium */
    uint8_t pad_00F1[0xF]; /* 0x00F1-0x0100 */
    int64_t unk_0100; /* +0x0100 w medium */
    int64_t unk_0108; /* +0x0108 rw medium */
    int64_t unk_0110; /* +0x0110 rw low */
    uint8_t pad_0118[0x1C]; /* 0x0118-0x0134 */
} ccBoss0401;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401, unk_00D8) == 0xD8, "ccBoss0401.unk_00D8 offset mismatch");
static_assert(offsetof(ccBoss0401, unk_00E0) == 0xE0, "ccBoss0401.unk_00E0 offset mismatch");
static_assert(offsetof(ccBoss0401, unk_00F0) == 0xF0, "ccBoss0401.unk_00F0 offset mismatch");
static_assert(offsetof(ccBoss0401, unk_0100) == 0x100, "ccBoss0401.unk_0100 offset mismatch");
static_assert(offsetof(ccBoss0401, unk_0108) == 0x108, "ccBoss0401.unk_0108 offset mismatch");
static_assert(offsetof(ccBoss0401, unk_0110) == 0x110, "ccBoss0401.unk_0110 offset mismatch");
/* sizeof(ccBoss0401) not asserted: true size unknown, >= 0x134 */

/* ccBoss0402 - 24 seed methods, 17 surface fields
 * Size: 0xF440 (62528 bytes) from allocation
 * Boss battle controller for Battle02. Allocation size 0xF440 from Create().
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0402 {
    uint8_t pad_0000[0x54]; /* 0x0000-0x0054 */
    int64_t unk_0054; /* +0x0054 w medium */
    int32_t unk_005C; /* +0x005C w medium */
    int32_t unk_0060; /* +0x0060 w medium */
    uint8_t pad_0064[0x4]; /* 0x0064-0x0068 */
    int64_t unk_0068; /* +0x0068 w medium */
    int32_t unk_0070; /* +0x0070 w medium */
    int32_t unk_0074; /* +0x0074 w medium */
    uint8_t unk_0078; /* +0x0078 r low */
    uint8_t pad_0079[0xF317]; /* 0x0079-0xF390 */
    int32_t unk_F390; /* +0xF390 w medium */
    int64_t unk_F394; /* +0xF394 w medium */
    int32_t unk_F39C; /* +0xF39C w medium */
    int32_t unk_F3A0; /* +0xF3A0 w medium */
    int32_t unk_F3A4; /* +0xF3A4 w medium */
    int64_t unk_F3A8; /* +0xF3A8 w medium */
    int64_t unk_F3B0; /* +0xF3B0 w medium */
    uint8_t unk_F3B8; /* +0xF3B8 r low */
    uint8_t pad_F3B9[0x77]; /* 0xF3B9-0xF430 */
    int64_t unk_F430; /* +0xF430 w medium */
    int32_t unk_F438; /* +0xF438 w medium */
    uint8_t pad_F43C[0x4]; /* 0xF43C-0xF440 */
} ccBoss0402;
#pragma pack(pop)

static_assert(offsetof(ccBoss0402, unk_0054) == 0x54, "ccBoss0402.unk_0054 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_005C) == 0x5C, "ccBoss0402.unk_005C offset mismatch");
static_assert(offsetof(ccBoss0402, unk_0060) == 0x60, "ccBoss0402.unk_0060 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_0068) == 0x68, "ccBoss0402.unk_0068 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_0070) == 0x70, "ccBoss0402.unk_0070 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_0074) == 0x74, "ccBoss0402.unk_0074 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_0078) == 0x78, "ccBoss0402.unk_0078 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F390) == 0xF390, "ccBoss0402.unk_F390 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F394) == 0xF394, "ccBoss0402.unk_F394 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F39C) == 0xF39C, "ccBoss0402.unk_F39C offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F3A0) == 0xF3A0, "ccBoss0402.unk_F3A0 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F3A4) == 0xF3A4, "ccBoss0402.unk_F3A4 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F3A8) == 0xF3A8, "ccBoss0402.unk_F3A8 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F3B0) == 0xF3B0, "ccBoss0402.unk_F3B0 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F3B8) == 0xF3B8, "ccBoss0402.unk_F3B8 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F430) == 0xF430, "ccBoss0402.unk_F430 offset mismatch");
static_assert(offsetof(ccBoss0402, unk_F438) == 0xF438, "ccBoss0402.unk_F438 offset mismatch");
static_assert(sizeof(ccBoss0402) == 0xF440, "ccBoss0402 size mismatch");

/* ccBoss0401PlayerBase - 22 seed methods, 60 surface fields
 * Size: unknown, >= 0xB324 (from constructor/destructor field access)
 * Base: ccPlayerGroupBattle
 * Base player class for Boss04 Battle01. Embedded ccBoss0401OffScreenOrbit at +0x1617, ccBoss0401CrashGroundShockWave at +0x1657.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401PlayerBase {
    uint8_t pad_0000[0x70]; /* 0x0000-0x0070 */
    uint8_t unk_0070; /* +0x0070 r low */
    uint8_t pad_0071[0x2B]; /* 0x0071-0x009C */
    int64_t unk_009C; /* +0x009C w medium */
    int32_t unk_00A4; /* +0x00A4 w medium */
    uint8_t pad_00A8[0x60]; /* 0x00A8-0x0108 */
    uint8_t unk_0108; /* +0x0108 r low */
    uint8_t pad_0109[0x97]; /* 0x0109-0x01A0 */
    int64_t unk_01A0; /* +0x01A0 w medium */
    int32_t unk_01A8; /* +0x01A8 w medium */
    int64_t unk_01AC; /* +0x01AC w medium */
    int32_t unk_01B4; /* +0x01B4 w medium */
    uint8_t pad_01B8[0x48]; /* 0x01B8-0x0200 */
    int64_t unk_0200; /* +0x0200 r low */
    uint8_t pad_0208[0x8]; /* 0x0208-0x0210 */
    uint8_t unk_0210; /* +0x0210 r low */
    uint8_t pad_0211[0x1EF]; /* 0x0211-0x0400 */
    uint8_t unk_0400; /* +0x0400 r low */
    uint8_t pad_0401[0x3F]; /* 0x0401-0x0440 */
    uint8_t unk_0440; /* +0x0440 r low */
    uint8_t pad_0441[0x3F]; /* 0x0441-0x0480 */
    uint8_t unk_0480; /* +0x0480 r low */
    uint8_t pad_0481[0x2B7]; /* 0x0481-0x0738 */
    int64_t unk_0738; /* +0x0738 r medium */
    uint8_t pad_0740[0x274]; /* 0x0740-0x09B4 */
    int32_t unk_09B4; /* +0x09B4 r medium */
    uint8_t pad_09B8[0x3C]; /* 0x09B8-0x09F4 */
    int32_t unk_09F4; /* +0x09F4 r medium */
    int32_t unk_09F8; /* +0x09F8 rw high */
    int32_t unk_09FC; /* +0x09FC rw high */
    int32_t unk_0A00; /* +0x0A00 rw high */
    int32_t unk_0A04; /* +0x0A04 w high */
    uint8_t pad_0A08[0x2278]; /* 0x0A08-0x2C80 */
    uint8_t unk_2C80; /* +0x2C80 r low */
    uint8_t pad_2C81[0x7F]; /* 0x2C81-0x2D00 */
    uint8_t unk_2D00; /* +0x2D00 r low */
    uint8_t pad_2D01[0x3F]; /* 0x2D01-0x2D40 */
    uint8_t unk_2D40; /* +0x2D40 r low */
    uint8_t pad_2D41[0x6FF]; /* 0x2D41-0x3440 */
    uint8_t unk_3440; /* +0x3440 r low */
    uint8_t pad_3441[0x3FF]; /* 0x3441-0x3840 */
    uint8_t unk_3840; /* +0x3840 r low */
    uint8_t pad_3841[0x3F]; /* 0x3841-0x3880 */
    uint8_t unk_3880; /* +0x3880 r low */
    uint8_t pad_3881[0xBF]; /* 0x3881-0x3940 */
    uint8_t unk_3940; /* +0x3940 r low */
    uint8_t pad_3941[0x3F]; /* 0x3941-0x3980 */
    uint8_t unk_3980; /* +0x3980 r low */
    uint8_t pad_3981[0x3F]; /* 0x3981-0x39C0 */
    uint8_t unk_39C0; /* +0x39C0 r low */
    uint8_t pad_39C1[0x1FF]; /* 0x39C1-0x3BC0 */
    uint8_t unk_3BC0; /* +0x3BC0 r low */
    uint8_t pad_3BC1[0xBF]; /* 0x3BC1-0x3C80 */
    uint8_t unk_3C80; /* +0x3C80 r low */
    uint8_t pad_3C81[0x3F]; /* 0x3C81-0x3CC0 */
    uint8_t unk_3CC0; /* +0x3CC0 r low */
    uint8_t pad_3CC1[0x5BF]; /* 0x3CC1-0x4280 */
    uint8_t unk_4280; /* +0x4280 r low */
    uint8_t pad_4281[0x237F]; /* 0x4281-0x6600 */
    uint8_t unk_6600; /* +0x6600 r low */
    uint8_t pad_6601[0x14BF]; /* 0x6601-0x7AC0 */
    uint8_t unk_7AC0; /* +0x7AC0 r low */
    uint8_t pad_7AC1[0x3F]; /* 0x7AC1-0x7B00 */
    uint8_t unk_7B00; /* +0x7B00 r low */
    uint8_t pad_7B01[0x6EF]; /* 0x7B01-0x81F0 */
    int64_t unk_81F0; /* +0x81F0 r medium */
    uint8_t pad_81F8[0x2074]; /* 0x81F8-0xA26C */
    int64_t unk_A26C; /* +0xA26C w medium */
    int32_t unk_A274; /* +0xA274 w medium */
    uint8_t pad_A278[0x9C]; /* 0xA278-0xA314 */
    int32_t unk_A314; /* +0xA314 w medium */
    uint8_t pad_A318[0x7E0]; /* 0xA318-0xAAF8 */
    uint8_t unk_AAF8; /* +0xAAF8 r low */
    uint8_t pad_AAF9[0x13]; /* 0xAAF9-0xAB0C */
    int32_t unk_AB0C; /* +0xAB0C w medium */
    uint8_t pad_AB10[0xD0]; /* 0xAB10-0xABE0 */
    int64_t unk_ABE0; /* +0xABE0 r medium */
    uint8_t pad_ABE8[0x3EC]; /* 0xABE8-0xAFD4 */
    int32_t unk_AFD4; /* +0xAFD4 rw medium */
    int32_t unk_AFD8; /* +0xAFD8 w medium */
    uint8_t pad_AFDC[0xB8]; /* 0xAFDC-0xB094 */
    int32_t unk_B094; /* +0xB094 rw medium */
    uint8_t pad_B098[0x20]; /* 0xB098-0xB0B8 */
    int64_t unk_B0B8; /* +0xB0B8 r low */
    uint8_t pad_B0C0[0x8]; /* 0xB0C0-0xB0C8 */
    int64_t unk_B0C8; /* +0xB0C8 r medium */
    int64_t unk_B0D0; /* +0xB0D0 r medium */
    uint8_t pad_B0D8[0x40]; /* 0xB0D8-0xB118 */
    int32_t unk_B118; /* +0xB118 w high */
    uint8_t pad_B11C[0x16C]; /* 0xB11C-0xB288 */
    int32_t unk_B288; /* +0xB288 rw high */
    uint8_t pad_B28C[0xC]; /* 0xB28C-0xB298 */
    int32_t unk_B298; /* +0xB298 w high */
    uint8_t pad_B29C[0x8]; /* 0xB29C-0xB2A4 */
    int32_t unk_B2A4; /* +0xB2A4 rw medium */
    int32_t unk_B2A8; /* +0xB2A8 rw high */
    int32_t unk_B2AC; /* +0xB2AC rw high */
    int32_t unk_B2B0; /* +0xB2B0 rw high */
    uint8_t pad_B2B4[0x4]; /* 0xB2B4-0xB2B8 */
    uint8_t unk_B2B8; /* +0xB2B8 r low */
    uint8_t pad_B2B9[0x57]; /* 0xB2B9-0xB310 */
    int32_t unk_B310; /* +0xB310 rw high */
    int64_t unk_B314; /* +0xB314 w medium */
    int32_t unk_B31C; /* +0xB31C w low */
    uint8_t pad_B320[0x4]; /* 0xB320-0xB324 */
} ccBoss0401PlayerBase;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401PlayerBase, unk_0070) == 0x70, "ccBoss0401PlayerBase.unk_0070 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_009C) == 0x9C, "ccBoss0401PlayerBase.unk_009C offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_00A4) == 0xA4, "ccBoss0401PlayerBase.unk_00A4 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0108) == 0x108, "ccBoss0401PlayerBase.unk_0108 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_01A0) == 0x1A0, "ccBoss0401PlayerBase.unk_01A0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_01A8) == 0x1A8, "ccBoss0401PlayerBase.unk_01A8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_01AC) == 0x1AC, "ccBoss0401PlayerBase.unk_01AC offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_01B4) == 0x1B4, "ccBoss0401PlayerBase.unk_01B4 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0200) == 0x200, "ccBoss0401PlayerBase.unk_0200 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0210) == 0x210, "ccBoss0401PlayerBase.unk_0210 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0400) == 0x400, "ccBoss0401PlayerBase.unk_0400 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0440) == 0x440, "ccBoss0401PlayerBase.unk_0440 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0480) == 0x480, "ccBoss0401PlayerBase.unk_0480 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0738) == 0x738, "ccBoss0401PlayerBase.unk_0738 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_09B4) == 0x9B4, "ccBoss0401PlayerBase.unk_09B4 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_09F4) == 0x9F4, "ccBoss0401PlayerBase.unk_09F4 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_09F8) == 0x9F8, "ccBoss0401PlayerBase.unk_09F8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_09FC) == 0x9FC, "ccBoss0401PlayerBase.unk_09FC offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0A00) == 0xA00, "ccBoss0401PlayerBase.unk_0A00 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_0A04) == 0xA04, "ccBoss0401PlayerBase.unk_0A04 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_2C80) == 0x2C80, "ccBoss0401PlayerBase.unk_2C80 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_2D00) == 0x2D00, "ccBoss0401PlayerBase.unk_2D00 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_2D40) == 0x2D40, "ccBoss0401PlayerBase.unk_2D40 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3440) == 0x3440, "ccBoss0401PlayerBase.unk_3440 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3840) == 0x3840, "ccBoss0401PlayerBase.unk_3840 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3880) == 0x3880, "ccBoss0401PlayerBase.unk_3880 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3940) == 0x3940, "ccBoss0401PlayerBase.unk_3940 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3980) == 0x3980, "ccBoss0401PlayerBase.unk_3980 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_39C0) == 0x39C0, "ccBoss0401PlayerBase.unk_39C0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3BC0) == 0x3BC0, "ccBoss0401PlayerBase.unk_3BC0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3C80) == 0x3C80, "ccBoss0401PlayerBase.unk_3C80 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_3CC0) == 0x3CC0, "ccBoss0401PlayerBase.unk_3CC0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_4280) == 0x4280, "ccBoss0401PlayerBase.unk_4280 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_6600) == 0x6600, "ccBoss0401PlayerBase.unk_6600 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_7AC0) == 0x7AC0, "ccBoss0401PlayerBase.unk_7AC0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_7B00) == 0x7B00, "ccBoss0401PlayerBase.unk_7B00 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_81F0) == 0x81F0, "ccBoss0401PlayerBase.unk_81F0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_A26C) == 0xA26C, "ccBoss0401PlayerBase.unk_A26C offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_A274) == 0xA274, "ccBoss0401PlayerBase.unk_A274 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_A314) == 0xA314, "ccBoss0401PlayerBase.unk_A314 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_AAF8) == 0xAAF8, "ccBoss0401PlayerBase.unk_AAF8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_AB0C) == 0xAB0C, "ccBoss0401PlayerBase.unk_AB0C offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_ABE0) == 0xABE0, "ccBoss0401PlayerBase.unk_ABE0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_AFD4) == 0xAFD4, "ccBoss0401PlayerBase.unk_AFD4 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_AFD8) == 0xAFD8, "ccBoss0401PlayerBase.unk_AFD8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B094) == 0xB094, "ccBoss0401PlayerBase.unk_B094 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B0B8) == 0xB0B8, "ccBoss0401PlayerBase.unk_B0B8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B0C8) == 0xB0C8, "ccBoss0401PlayerBase.unk_B0C8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B0D0) == 0xB0D0, "ccBoss0401PlayerBase.unk_B0D0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B118) == 0xB118, "ccBoss0401PlayerBase.unk_B118 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B288) == 0xB288, "ccBoss0401PlayerBase.unk_B288 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B298) == 0xB298, "ccBoss0401PlayerBase.unk_B298 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B2A4) == 0xB2A4, "ccBoss0401PlayerBase.unk_B2A4 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B2A8) == 0xB2A8, "ccBoss0401PlayerBase.unk_B2A8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B2AC) == 0xB2AC, "ccBoss0401PlayerBase.unk_B2AC offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B2B0) == 0xB2B0, "ccBoss0401PlayerBase.unk_B2B0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B2B8) == 0xB2B8, "ccBoss0401PlayerBase.unk_B2B8 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B310) == 0xB310, "ccBoss0401PlayerBase.unk_B310 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B314) == 0xB314, "ccBoss0401PlayerBase.unk_B314 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerBase, unk_B31C) == 0xB31C, "ccBoss0401PlayerBase.unk_B31C offset mismatch");
/* sizeof(ccBoss0401PlayerBase) not asserted: true size unknown, >= 0xB324 */

/* ccBoss0401PlayerCpu - 21 seed methods, 21 surface fields
 * Size: unknown, >= 0x13BC (from constructor/destructor field access)
 * Base: ccCpuPlayerGroupCMN
 * CPU player for Boss04 Battle01.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401PlayerCpu {
    uint8_t pad_0000[0x180]; /* 0x0000-0x0180 */
    uint8_t unk_0180; /* +0x0180 r low */
    uint8_t pad_0181[0x3F]; /* 0x0181-0x01C0 */
    uint8_t unk_01C0; /* +0x01C0 r low */
    uint8_t pad_01C1[0x3B7]; /* 0x01C1-0x0578 */
    int32_t unk_0578; /* +0x0578 w medium */
    uint8_t pad_057C[0x280]; /* 0x057C-0x07FC */
    int32_t unk_07FC; /* +0x07FC r medium */
    uint8_t pad_0800[0x54]; /* 0x0800-0x0854 */
    uint8_t unk_0854; /* +0x0854 r low */
    uint8_t pad_0855[0x8C7]; /* 0x0855-0x111C */
    int32_t unk_111C; /* +0x111C r medium */
    uint8_t pad_1120[0x1E0]; /* 0x1120-0x1300 */
    int32_t unk_1300; /* +0x1300 rw low */
    int32_t unk_1304; /* +0x1304 rw low */
    uint8_t pad_1308[0x8]; /* 0x1308-0x1310 */
    int32_t unk_1310; /* +0x1310 rw low */
    uint8_t pad_1314[0xC]; /* 0x1314-0x1320 */
    uint8_t unk_1320; /* +0x1320 r low */
    uint8_t pad_1321[0x3]; /* 0x1321-0x1324 */
    int32_t unk_1324; /* +0x1324 r medium */
    uint8_t pad_1328[0x4]; /* 0x1328-0x132C */
    int32_t unk_132C; /* +0x132C r medium */
    int64_t unk_1330; /* +0x1330 r medium */
    int64_t unk_1338; /* +0x1338 r medium */
    int64_t unk_1340; /* +0x1340 w medium */
    int64_t unk_1348; /* +0x1348 w medium */
    int64_t unk_1350; /* +0x1350 rw low */
    int64_t unk_1358; /* +0x1358 w medium */
    int32_t unk_1360; /* +0x1360 rw high */
    int32_t unk_1364; /* +0x1364 rw high */
    uint8_t pad_1368[0x50]; /* 0x1368-0x13B8 */
    int32_t unk_13B8; /* +0x13B8 rw high */
} ccBoss0401PlayerCpu;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401PlayerCpu, unk_0180) == 0x180, "ccBoss0401PlayerCpu.unk_0180 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_01C0) == 0x1C0, "ccBoss0401PlayerCpu.unk_01C0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_0578) == 0x578, "ccBoss0401PlayerCpu.unk_0578 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_07FC) == 0x7FC, "ccBoss0401PlayerCpu.unk_07FC offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_0854) == 0x854, "ccBoss0401PlayerCpu.unk_0854 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_111C) == 0x111C, "ccBoss0401PlayerCpu.unk_111C offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1300) == 0x1300, "ccBoss0401PlayerCpu.unk_1300 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1304) == 0x1304, "ccBoss0401PlayerCpu.unk_1304 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1310) == 0x1310, "ccBoss0401PlayerCpu.unk_1310 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1320) == 0x1320, "ccBoss0401PlayerCpu.unk_1320 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1324) == 0x1324, "ccBoss0401PlayerCpu.unk_1324 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_132C) == 0x132C, "ccBoss0401PlayerCpu.unk_132C offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1330) == 0x1330, "ccBoss0401PlayerCpu.unk_1330 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1338) == 0x1338, "ccBoss0401PlayerCpu.unk_1338 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1340) == 0x1340, "ccBoss0401PlayerCpu.unk_1340 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1348) == 0x1348, "ccBoss0401PlayerCpu.unk_1348 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1350) == 0x1350, "ccBoss0401PlayerCpu.unk_1350 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1358) == 0x1358, "ccBoss0401PlayerCpu.unk_1358 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1360) == 0x1360, "ccBoss0401PlayerCpu.unk_1360 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_1364) == 0x1364, "ccBoss0401PlayerCpu.unk_1364 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerCpu, unk_13B8) == 0x13B8, "ccBoss0401PlayerCpu.unk_13B8 offset mismatch");
/* sizeof(ccBoss0401PlayerCpu) not asserted: true size unknown, >= 0x13BC */

/* ccBoss0402PlayerZBZ - 14 seed methods, 52 surface fields
 * Size: unknown, >= 0xA218 (from constructor/destructor field access)
 * Base: ccPlayer
 * Zabuza player for Boss04 Battle02. Fields at +0xAFB8..+0xAFD0 hold xfbin chunk pointers.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0402PlayerZBZ {
    uint8_t pad_0000[0x70]; /* 0x0000-0x0070 */
    uint8_t unk_0070; /* +0x0070 r low */
    uint8_t pad_0071[0x43]; /* 0x0071-0x00B4 */
    uint8_t unk_00B4; /* +0x00B4 r low */
    uint8_t pad_00B5[0x14B]; /* 0x00B5-0x0200 */
    uint8_t unk_0200; /* +0x0200 r low */
    uint8_t pad_0201[0xBF]; /* 0x0201-0x02C0 */
    uint8_t unk_02C0; /* +0x02C0 r low */
    uint8_t pad_02C1[0x1BF]; /* 0x02C1-0x0480 */
    uint8_t unk_0480; /* +0x0480 r low */
    uint8_t pad_0481[0x537]; /* 0x0481-0x09B8 */
    int64_t unk_09B8; /* +0x09B8 r medium */
    uint8_t pad_09C0[0x2C]; /* 0x09C0-0x09EC */
    int32_t unk_09EC; /* +0x09EC r medium */
    uint8_t pad_09F0[0x8]; /* 0x09F0-0x09F8 */
    int32_t unk_09F8; /* +0x09F8 rw high */
    int32_t unk_09FC; /* +0x09FC rw high */
    int32_t unk_0A00; /* +0x0A00 rw high */
    int32_t unk_0A04; /* +0x0A04 w high */
    uint8_t pad_0A08[0x28F8]; /* 0x0A08-0x3300 */
    uint8_t unk_3300; /* +0x3300 r low */
    uint8_t pad_3301[0x1BF]; /* 0x3301-0x34C0 */
    uint8_t unk_34C0; /* +0x34C0 r low */
    uint8_t pad_34C1[0x47F]; /* 0x34C1-0x3940 */
    uint8_t unk_3940; /* +0x3940 r low */
    uint8_t pad_3941[0x13F]; /* 0x3941-0x3A80 */
    uint8_t unk_3A80; /* +0x3A80 r low */
    uint8_t pad_3A81[0x1FF]; /* 0x3A81-0x3C80 */
    uint8_t unk_3C80; /* +0x3C80 r low */
    uint8_t pad_3C81[0x3F]; /* 0x3C81-0x3CC0 */
    uint8_t unk_3CC0; /* +0x3CC0 r low */
    uint8_t pad_3CC1[0x7F]; /* 0x3CC1-0x3D40 */
    uint8_t unk_3D40; /* +0x3D40 r low */
    uint8_t pad_3D41[0x3F]; /* 0x3D41-0x3D80 */
    uint8_t unk_3D80; /* +0x3D80 r low */
    uint8_t pad_3D81[0x4FF]; /* 0x3D81-0x4280 */
    uint8_t unk_4280; /* +0x4280 r low */
    uint8_t pad_4281[0x1FF]; /* 0x4281-0x4480 */
    uint8_t unk_4480; /* +0x4480 r low */
    uint8_t pad_4481[0x13F]; /* 0x4481-0x45C0 */
    uint8_t unk_45C0; /* +0x45C0 r low */
    uint8_t pad_45C1[0x371F]; /* 0x45C1-0x7CE0 */
    uint8_t unk_7CE0; /* +0x7CE0 r low */
    uint8_t pad_7CE1[0x57B]; /* 0x7CE1-0x825C */
    int32_t unk_825C; /* +0x825C r medium */
    uint8_t pad_8260[0xC]; /* 0x8260-0x826C */
    int32_t unk_826C; /* +0x826C w medium */
    uint8_t pad_8270[0x8]; /* 0x8270-0x8278 */
    int64_t unk_8278; /* +0x8278 r medium */
    uint8_t pad_8280[0x1F00]; /* 0x8280-0xA180 */
    int64_t unk_A180; /* +0xA180 w medium */
    int64_t unk_A188; /* +0xA188 w medium */
    int64_t unk_A190; /* +0xA190 w medium */
    int64_t unk_A198; /* +0xA198 w medium */
    int64_t unk_A1A0; /* +0xA1A0 w medium */
    int64_t unk_A1A8; /* +0xA1A8 w medium */
    int64_t unk_A1B0; /* +0xA1B0 w medium */
    int64_t unk_A1B8; /* +0xA1B8 w medium */
    int32_t unk_A1C0; /* +0xA1C0 w medium */
    int32_t unk_A1C4; /* +0xA1C4 w medium */
    int32_t unk_A1C8; /* +0xA1C8 w medium */
    int32_t unk_A1CC; /* +0xA1CC w medium */
    int32_t unk_A1D0; /* +0xA1D0 w medium */
    int32_t unk_A1D4; /* +0xA1D4 w medium */
    int32_t unk_A1D8; /* +0xA1D8 w medium */
    int32_t unk_A1DC; /* +0xA1DC w medium */
    uint8_t pad_A1E0[0x2C]; /* 0xA1E0-0xA20C */
    int64_t unk_A20C; /* +0xA20C w high */
    int32_t unk_A214; /* +0xA214 w high */
    uint8_t pad_A218[0x10]; /* 0xA218-0xA228 */
    uint8_t unk_A228; /* +0xA228 r low */
    uint8_t pad_A229[0x993]; /* 0xA229-0xABBC */
    int32_t unk_ABBC; /* +0xABBC r medium */
    uint8_t pad_ABC0[0x20]; /* 0xABC0-0xABE0 */
    int64_t unk_ABE0; /* +0xABE0 r medium */
    uint8_t pad_ABE8[0x3D0]; /* 0xABE8-0xAFB8 */
    int64_t unk_AFB8; /* +0xAFB8 rw high */
    int64_t unk_AFC0; /* +0xAFC0 rw high */
    int64_t unk_AFC8; /* +0xAFC8 rw high */
    int64_t unk_AFD0; /* +0xAFD0 rw high */
    int32_t unk_AFD8; /* +0xAFD8 rw high */
} ccBoss0402PlayerZBZ;
#pragma pack(pop)

static_assert(offsetof(ccBoss0402PlayerZBZ, unk_0070) == 0x70, "ccBoss0402PlayerZBZ.unk_0070 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_00B4) == 0xB4, "ccBoss0402PlayerZBZ.unk_00B4 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_0200) == 0x200, "ccBoss0402PlayerZBZ.unk_0200 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_02C0) == 0x2C0, "ccBoss0402PlayerZBZ.unk_02C0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_0480) == 0x480, "ccBoss0402PlayerZBZ.unk_0480 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_09B8) == 0x9B8, "ccBoss0402PlayerZBZ.unk_09B8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_09EC) == 0x9EC, "ccBoss0402PlayerZBZ.unk_09EC offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_09F8) == 0x9F8, "ccBoss0402PlayerZBZ.unk_09F8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_09FC) == 0x9FC, "ccBoss0402PlayerZBZ.unk_09FC offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_0A00) == 0xA00, "ccBoss0402PlayerZBZ.unk_0A00 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_0A04) == 0xA04, "ccBoss0402PlayerZBZ.unk_0A04 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3300) == 0x3300, "ccBoss0402PlayerZBZ.unk_3300 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_34C0) == 0x34C0, "ccBoss0402PlayerZBZ.unk_34C0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3940) == 0x3940, "ccBoss0402PlayerZBZ.unk_3940 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3A80) == 0x3A80, "ccBoss0402PlayerZBZ.unk_3A80 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3C80) == 0x3C80, "ccBoss0402PlayerZBZ.unk_3C80 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3CC0) == 0x3CC0, "ccBoss0402PlayerZBZ.unk_3CC0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3D40) == 0x3D40, "ccBoss0402PlayerZBZ.unk_3D40 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_3D80) == 0x3D80, "ccBoss0402PlayerZBZ.unk_3D80 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_4280) == 0x4280, "ccBoss0402PlayerZBZ.unk_4280 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_4480) == 0x4480, "ccBoss0402PlayerZBZ.unk_4480 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_45C0) == 0x45C0, "ccBoss0402PlayerZBZ.unk_45C0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_7CE0) == 0x7CE0, "ccBoss0402PlayerZBZ.unk_7CE0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_825C) == 0x825C, "ccBoss0402PlayerZBZ.unk_825C offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_826C) == 0x826C, "ccBoss0402PlayerZBZ.unk_826C offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_8278) == 0x8278, "ccBoss0402PlayerZBZ.unk_8278 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A180) == 0xA180, "ccBoss0402PlayerZBZ.unk_A180 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A188) == 0xA188, "ccBoss0402PlayerZBZ.unk_A188 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A190) == 0xA190, "ccBoss0402PlayerZBZ.unk_A190 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A198) == 0xA198, "ccBoss0402PlayerZBZ.unk_A198 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1A0) == 0xA1A0, "ccBoss0402PlayerZBZ.unk_A1A0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1A8) == 0xA1A8, "ccBoss0402PlayerZBZ.unk_A1A8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1B0) == 0xA1B0, "ccBoss0402PlayerZBZ.unk_A1B0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1B8) == 0xA1B8, "ccBoss0402PlayerZBZ.unk_A1B8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1C0) == 0xA1C0, "ccBoss0402PlayerZBZ.unk_A1C0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1C4) == 0xA1C4, "ccBoss0402PlayerZBZ.unk_A1C4 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1C8) == 0xA1C8, "ccBoss0402PlayerZBZ.unk_A1C8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1CC) == 0xA1CC, "ccBoss0402PlayerZBZ.unk_A1CC offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1D0) == 0xA1D0, "ccBoss0402PlayerZBZ.unk_A1D0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1D4) == 0xA1D4, "ccBoss0402PlayerZBZ.unk_A1D4 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1D8) == 0xA1D8, "ccBoss0402PlayerZBZ.unk_A1D8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A1DC) == 0xA1DC, "ccBoss0402PlayerZBZ.unk_A1DC offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A20C) == 0xA20C, "ccBoss0402PlayerZBZ.unk_A20C offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A214) == 0xA214, "ccBoss0402PlayerZBZ.unk_A214 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_A228) == 0xA228, "ccBoss0402PlayerZBZ.unk_A228 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_ABBC) == 0xABBC, "ccBoss0402PlayerZBZ.unk_ABBC offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_ABE0) == 0xABE0, "ccBoss0402PlayerZBZ.unk_ABE0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_AFB8) == 0xAFB8, "ccBoss0402PlayerZBZ.unk_AFB8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_AFC0) == 0xAFC0, "ccBoss0402PlayerZBZ.unk_AFC0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_AFC8) == 0xAFC8, "ccBoss0402PlayerZBZ.unk_AFC8 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_AFD0) == 0xAFD0, "ccBoss0402PlayerZBZ.unk_AFD0 offset mismatch");
static_assert(offsetof(ccBoss0402PlayerZBZ, unk_AFD8) == 0xAFD8, "ccBoss0402PlayerZBZ.unk_AFD8 offset mismatch");
/* sizeof(ccBoss0402PlayerZBZ) not asserted: true size unknown, >= 0xA218 */

/* ccSceneBoss0401SimpleDemo - 13 seed methods, 11 surface fields
 * Size: unknown, >= 0x1C8 (from constructor/destructor field access)
 * Base: ccScene
 * Simple demo scene for Boss04 Battle01. Embedded nuccAnm at +0x188 (offset 0x31*8).
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccSceneBoss0401SimpleDemo {
    uint8_t pad_0000[0x13C]; /* 0x0000-0x013C */
    int64_t unk_013C; /* +0x013C r medium */
    int64_t unk_0144; /* +0x0144 r medium */
    int64_t unk_014C; /* +0x014C r medium */
    int64_t unk_0154; /* +0x0154 r medium */
    int64_t unk_015C; /* +0x015C r medium */
    int64_t unk_0164; /* +0x0164 r medium */
    int32_t unk_016C; /* +0x016C r medium */
    int64_t unk_0170; /* +0x0170 r medium */
    int64_t unk_0178; /* +0x0178 r medium */
    uint8_t pad_0180[0x8]; /* 0x0180-0x0188 */
    uint8_t unk_0188; /* +0x0188 r low */
    uint8_t pad_0189[0x37]; /* 0x0189-0x01C0 */
    uint8_t unk_01C0; /* +0x01C0 r low */
    uint8_t pad_01C1[0x7]; /* 0x01C1-0x01C8 */
} ccSceneBoss0401SimpleDemo;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_013C) == 0x13C, "ccSceneBoss0401SimpleDemo.unk_013C offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_0144) == 0x144, "ccSceneBoss0401SimpleDemo.unk_0144 offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_014C) == 0x14C, "ccSceneBoss0401SimpleDemo.unk_014C offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_0154) == 0x154, "ccSceneBoss0401SimpleDemo.unk_0154 offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_015C) == 0x15C, "ccSceneBoss0401SimpleDemo.unk_015C offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_0164) == 0x164, "ccSceneBoss0401SimpleDemo.unk_0164 offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_016C) == 0x16C, "ccSceneBoss0401SimpleDemo.unk_016C offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_0170) == 0x170, "ccSceneBoss0401SimpleDemo.unk_0170 offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_0178) == 0x178, "ccSceneBoss0401SimpleDemo.unk_0178 offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_0188) == 0x188, "ccSceneBoss0401SimpleDemo.unk_0188 offset mismatch");
static_assert(offsetof(ccSceneBoss0401SimpleDemo, unk_01C0) == 0x1C0, "ccSceneBoss0401SimpleDemo.unk_01C0 offset mismatch");
/* sizeof(ccSceneBoss0401SimpleDemo) not asserted: true size unknown, >= 0x1C8 */

/* ccBoss0401FormationBase - 6 seed methods, 11 surface fields
 * Size: unknown, >= 0x188 (from constructor/destructor field access)
 * Base: ccCpuFormationGroup
 * Formation base for Boss04 Battle01 CPU players.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401FormationBase {
    uint8_t pad_0000[0x60]; /* 0x0000-0x0060 */
    uint8_t unk_0060; /* +0x0060 r low */
    uint8_t pad_0061[0x17]; /* 0x0061-0x0078 */
    int64_t unk_0078; /* +0x0078 rw high */
    int32_t unk_0080; /* +0x0080 rw high */
    uint8_t pad_0084[0x4]; /* 0x0084-0x0088 */
    int64_t unk_0088; /* +0x0088 w medium */
    int32_t unk_0090; /* +0x0090 w medium */
    uint8_t unk_0094; /* +0x0094 r low */
    uint8_t pad_0095[0x7]; /* 0x0095-0x009C */
    int32_t unk_009C; /* +0x009C w medium */
    int32_t unk_00A0; /* +0x00A0 rw medium */
    uint8_t pad_00A4[0x5C]; /* 0x00A4-0x0100 */
    uint8_t unk_0100; /* +0x0100 r low */
    uint8_t pad_0101[0x3F]; /* 0x0101-0x0140 */
    uint8_t unk_0140; /* +0x0140 r low */
    uint8_t pad_0141[0x3F]; /* 0x0141-0x0180 */
    uint8_t unk_0180; /* +0x0180 r low */
    uint8_t pad_0181[0x7]; /* 0x0181-0x0188 */
} ccBoss0401FormationBase;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401FormationBase, unk_0060) == 0x60, "ccBoss0401FormationBase.unk_0060 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0078) == 0x78, "ccBoss0401FormationBase.unk_0078 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0080) == 0x80, "ccBoss0401FormationBase.unk_0080 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0088) == 0x88, "ccBoss0401FormationBase.unk_0088 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0090) == 0x90, "ccBoss0401FormationBase.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0094) == 0x94, "ccBoss0401FormationBase.unk_0094 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_009C) == 0x9C, "ccBoss0401FormationBase.unk_009C offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_00A0) == 0xA0, "ccBoss0401FormationBase.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0100) == 0x100, "ccBoss0401FormationBase.unk_0100 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0140) == 0x140, "ccBoss0401FormationBase.unk_0140 offset mismatch");
static_assert(offsetof(ccBoss0401FormationBase, unk_0180) == 0x180, "ccBoss0401FormationBase.unk_0180 offset mismatch");
/* sizeof(ccBoss0401FormationBase) not asserted: true size unknown, >= 0x188 */

/* ccSceneBoss0401 - 6 seed methods, 10 surface fields
 * Size: unknown, >= 0x1A8 (from constructor/destructor field access)
 * Base: nuccFileLoadList
 * Main scene for Boss04 Battle01.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccSceneBoss0401 {
    uint8_t pad_0000[0x128]; /* 0x0000-0x0128 */
    int64_t unk_0128; /* +0x0128 w medium */
    uint8_t pad_0130[0x38]; /* 0x0130-0x0168 */
    int32_t unk_0168; /* +0x0168 w medium */
    uint8_t pad_016C[0x4]; /* 0x016C-0x0170 */
    int64_t unk_0170; /* +0x0170 w medium */
    int32_t unk_0178; /* +0x0178 w medium */
    int64_t unk_017C; /* +0x017C w medium */
    int32_t unk_0184; /* +0x0184 w medium */
    int32_t unk_0188; /* +0x0188 w medium */
    uint8_t pad_018C[0x4]; /* 0x018C-0x0190 */
    int64_t unk_0190; /* +0x0190 w medium */
    int64_t unk_0198; /* +0x0198 w medium */
    uint8_t unk_01A0; /* +0x01A0 r low */
    uint8_t pad_01A1[0x7]; /* 0x01A1-0x01A8 */
} ccSceneBoss0401;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss0401, unk_0128) == 0x128, "ccSceneBoss0401.unk_0128 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0168) == 0x168, "ccSceneBoss0401.unk_0168 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0170) == 0x170, "ccSceneBoss0401.unk_0170 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0178) == 0x178, "ccSceneBoss0401.unk_0178 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_017C) == 0x17C, "ccSceneBoss0401.unk_017C offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0184) == 0x184, "ccSceneBoss0401.unk_0184 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0188) == 0x188, "ccSceneBoss0401.unk_0188 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0190) == 0x190, "ccSceneBoss0401.unk_0190 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_0198) == 0x198, "ccSceneBoss0401.unk_0198 offset mismatch");
static_assert(offsetof(ccSceneBoss0401, unk_01A0) == 0x1A0, "ccSceneBoss0401.unk_01A0 offset mismatch");
/* sizeof(ccSceneBoss0401) not asserted: true size unknown, >= 0x1A8 */

/* ccSceneBoss04FreeBattleBase - 7 seed methods, 9 surface fields
 * Size: unknown, >= 0x908 (from constructor/destructor field access)
 * Base: ccSceneBossFreeBattleBase
 * Free battle base scene for Boss04.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccSceneBoss04FreeBattleBase {
    uint8_t pad_0000[0x128]; /* 0x0000-0x0128 */
    int32_t unk_0128; /* +0x0128 w medium */
    uint8_t pad_012C[0x64]; /* 0x012C-0x0190 */
    uint8_t unk_0190; /* +0x0190 r low */
    uint8_t pad_0191[0x10F]; /* 0x0191-0x02A0 */
    int32_t unk_02A0; /* +0x02A0 w medium */
    uint8_t pad_02A4[0x49C]; /* 0x02A4-0x0740 */
    uint8_t unk_0740; /* +0x0740 r low */
    uint8_t pad_0741[0xBF]; /* 0x0741-0x0800 */
    uint8_t unk_0800; /* +0x0800 r low */
    uint8_t pad_0801[0x3F]; /* 0x0801-0x0840 */
    uint8_t unk_0840; /* +0x0840 r low */
    uint8_t pad_0841[0x3F]; /* 0x0841-0x0880 */
    uint8_t unk_0880; /* +0x0880 r low */
    uint8_t pad_0881[0x3F]; /* 0x0881-0x08C0 */
    uint8_t unk_08C0; /* +0x08C0 r low */
    uint8_t pad_08C1[0x3F]; /* 0x08C1-0x0900 */
    uint8_t unk_0900; /* +0x0900 r low */
    uint8_t pad_0901[0x7]; /* 0x0901-0x0908 */
} ccSceneBoss04FreeBattleBase;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0128) == 0x128, "ccSceneBoss04FreeBattleBase.unk_0128 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0190) == 0x190, "ccSceneBoss04FreeBattleBase.unk_0190 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_02A0) == 0x2A0, "ccSceneBoss04FreeBattleBase.unk_02A0 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0740) == 0x740, "ccSceneBoss04FreeBattleBase.unk_0740 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0800) == 0x800, "ccSceneBoss04FreeBattleBase.unk_0800 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0840) == 0x840, "ccSceneBoss04FreeBattleBase.unk_0840 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0880) == 0x880, "ccSceneBoss04FreeBattleBase.unk_0880 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_08C0) == 0x8C0, "ccSceneBoss04FreeBattleBase.unk_08C0 offset mismatch");
static_assert(offsetof(ccSceneBoss04FreeBattleBase, unk_0900) == 0x900, "ccSceneBoss04FreeBattleBase.unk_0900 offset mismatch");
/* sizeof(ccSceneBoss04FreeBattleBase) not asserted: true size unknown, >= 0x908 */

/* ccBoss0401PlayerGUY - 8 seed methods, 8 surface fields
 * Size: unknown, >= 0xAEE4 (from constructor/destructor field access)
 * Base: ccBoss0401PlayerBase
 * Guy-sensei player variant for Boss04 Battle01.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401PlayerGUY {
    uint8_t pad_0000[0x200]; /* 0x0000-0x0200 */
    uint8_t unk_0200; /* +0x0200 r low */
    uint8_t pad_0201[0x1FF]; /* 0x0201-0x0400 */
    uint8_t unk_0400; /* +0x0400 r low */
    uint8_t pad_0401[0x7F]; /* 0x0401-0x0480 */
    uint8_t unk_0480; /* +0x0480 r low */
    uint8_t pad_0481[0x2B7]; /* 0x0481-0x0738 */
    int64_t unk_0738; /* +0x0738 r medium */
    uint8_t pad_0740[0x2AC]; /* 0x0740-0x09EC */
    int32_t unk_09EC; /* +0x09EC r medium */
    uint8_t pad_09F0[0x2910]; /* 0x09F0-0x3300 */
    uint8_t unk_3300; /* +0x3300 r low */
    uint8_t pad_3301[0x1BF]; /* 0x3301-0x34C0 */
    uint8_t unk_34C0; /* +0x34C0 r low */
    uint8_t pad_34C1[0x7A1F]; /* 0x34C1-0xAEE0 */
    int32_t unk_AEE0; /* +0xAEE0 w medium */
} ccBoss0401PlayerGUY;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401PlayerGUY, unk_0200) == 0x200, "ccBoss0401PlayerGUY.unk_0200 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_0400) == 0x400, "ccBoss0401PlayerGUY.unk_0400 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_0480) == 0x480, "ccBoss0401PlayerGUY.unk_0480 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_0738) == 0x738, "ccBoss0401PlayerGUY.unk_0738 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_09EC) == 0x9EC, "ccBoss0401PlayerGUY.unk_09EC offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_3300) == 0x3300, "ccBoss0401PlayerGUY.unk_3300 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_34C0) == 0x34C0, "ccBoss0401PlayerGUY.unk_34C0 offset mismatch");
static_assert(offsetof(ccBoss0401PlayerGUY, unk_AEE0) == 0xAEE0, "ccBoss0401PlayerGUY.unk_AEE0 offset mismatch");
/* sizeof(ccBoss0401PlayerGUY) not asserted: true size unknown, >= 0xAEE4 */

/* ccUiBoss0402Manager - 8 seed methods, 5 surface fields
 * Size: unknown, >= 0x100 (from constructor/destructor field access)
 * UI manager for Boss04 Battle02.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccUiBoss0402Manager {
    uint8_t pad_0000[0x88]; /* 0x0000-0x0088 */
    int64_t unk_0088; /* +0x0088 w medium */
    int64_t unk_0090; /* +0x0090 w medium */
    int64_t unk_0098; /* +0x0098 w medium */
    uint8_t pad_00A0[0x10]; /* 0x00A0-0x00B0 */
    uint8_t unk_00B0; /* +0x00B0 r low */
    uint8_t pad_00B1[0x2F]; /* 0x00B1-0x00E0 */
    int64_t unk_00E0; /* +0x00E0 w medium */
    uint8_t pad_00E8[0x18]; /* 0x00E8-0x0100 */
} ccUiBoss0402Manager;
#pragma pack(pop)

static_assert(offsetof(ccUiBoss0402Manager, unk_0088) == 0x88, "ccUiBoss0402Manager.unk_0088 offset mismatch");
static_assert(offsetof(ccUiBoss0402Manager, unk_0090) == 0x90, "ccUiBoss0402Manager.unk_0090 offset mismatch");
static_assert(offsetof(ccUiBoss0402Manager, unk_0098) == 0x98, "ccUiBoss0402Manager.unk_0098 offset mismatch");
static_assert(offsetof(ccUiBoss0402Manager, unk_00B0) == 0xB0, "ccUiBoss0402Manager.unk_00B0 offset mismatch");
static_assert(offsetof(ccUiBoss0402Manager, unk_00E0) == 0xE0, "ccUiBoss0402Manager.unk_00E0 offset mismatch");
/* sizeof(ccUiBoss0402Manager) not asserted: true size unknown, >= 0x100 */

/* ccBoss0401OffScreenOrbit - 5 seed methods, 5 surface fields
 * Size: unknown, >= 0x40 (from constructor/destructor field access)
 * Off-screen orbit handler, embedded in ccBoss0401PlayerBase at +0x1617.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401OffScreenOrbit {
    uint8_t pad_0000[0x1D0]; /* 0x0000-0x01D0 */
    int32_t unk_01D0; /* +0x01D0 w high */
    uint8_t unk_01D4; /* +0x01D4 r low */
    uint8_t pad_01D5[0xB]; /* 0x01D5-0x01E0 */
    int64_t unk_01E0; /* +0x01E0 w medium */
    int32_t unk_01E8; /* +0x01E8 w medium */
    int64_t unk_01EC; /* +0x01EC w medium */
} ccBoss0401OffScreenOrbit;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401OffScreenOrbit, unk_01D0) == 0x1D0, "ccBoss0401OffScreenOrbit.unk_01D0 offset mismatch");
static_assert(offsetof(ccBoss0401OffScreenOrbit, unk_01D4) == 0x1D4, "ccBoss0401OffScreenOrbit.unk_01D4 offset mismatch");
static_assert(offsetof(ccBoss0401OffScreenOrbit, unk_01E0) == 0x1E0, "ccBoss0401OffScreenOrbit.unk_01E0 offset mismatch");
static_assert(offsetof(ccBoss0401OffScreenOrbit, unk_01E8) == 0x1E8, "ccBoss0401OffScreenOrbit.unk_01E8 offset mismatch");
static_assert(offsetof(ccBoss0401OffScreenOrbit, unk_01EC) == 0x1EC, "ccBoss0401OffScreenOrbit.unk_01EC offset mismatch");
/* sizeof(ccBoss0401OffScreenOrbit) not asserted: true size unknown, >= 0x40 */

/* ccBoss0401CrashGroundShockWave - 5 seed methods, 3 surface fields
 * Size: unknown, >= 0x30 (from constructor/destructor field access)
 * Ground shockwave effect, embedded in ccBoss0401PlayerBase at +0x1657.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401CrashGroundShockWave {
    uint8_t pad_0000[0x14]; /* 0x0000-0x0014 */
    uint8_t unk_0014; /* +0x0014 r low */
    uint8_t pad_0015[0x3F]; /* 0x0015-0x0054 */
    int32_t unk_0054; /* +0x0054 rw high */
    uint8_t pad_0058[0x428]; /* 0x0058-0x0480 */
    uint8_t unk_0480; /* +0x0480 r low */
} ccBoss0401CrashGroundShockWave;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401CrashGroundShockWave, unk_0014) == 0x14, "ccBoss0401CrashGroundShockWave.unk_0014 offset mismatch");
static_assert(offsetof(ccBoss0401CrashGroundShockWave, unk_0054) == 0x54, "ccBoss0401CrashGroundShockWave.unk_0054 offset mismatch");
static_assert(offsetof(ccBoss0401CrashGroundShockWave, unk_0480) == 0x480, "ccBoss0401CrashGroundShockWave.unk_0480 offset mismatch");
/* sizeof(ccBoss0401CrashGroundShockWave) not asserted: true size unknown, >= 0x30 */

/* ccBoss0402Stage - 5 seed methods, 4 surface fields
 * Size: unknown, >= 0x80 (from constructor/destructor field access)
 * Stage manager for Boss04 Battle02.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0402Stage {
    uint8_t pad_0000[0x90]; /* 0x0000-0x0090 */
    int32_t unk_0090; /* +0x0090 w medium */
    uint8_t unk_0094; /* +0x0094 r low */
    uint8_t pad_0095[0xB]; /* 0x0095-0x00A0 */
    uint8_t unk_00A0; /* +0x00A0 r low */
    uint8_t pad_00A1[0xAF]; /* 0x00A1-0x0150 */
    uint8_t unk_0150; /* +0x0150 r low */
} ccBoss0402Stage;
#pragma pack(pop)

static_assert(offsetof(ccBoss0402Stage, unk_0090) == 0x90, "ccBoss0402Stage.unk_0090 offset mismatch");
static_assert(offsetof(ccBoss0402Stage, unk_0094) == 0x94, "ccBoss0402Stage.unk_0094 offset mismatch");
static_assert(offsetof(ccBoss0402Stage, unk_00A0) == 0xA0, "ccBoss0402Stage.unk_00A0 offset mismatch");
static_assert(offsetof(ccBoss0402Stage, unk_0150) == 0x150, "ccBoss0402Stage.unk_0150 offset mismatch");
/* sizeof(ccBoss0402Stage) not asserted: true size unknown, >= 0x80 */

/* ccBoss04BattleStatus - 3 seed methods, 1 surface fields
 * Size: unknown, >= 0x10 (from constructor/destructor field access)
 * Battle status tracker.
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss04BattleStatus {
    uint8_t pad_0000[0x2C]; /* 0x0000-0x002C */
    int32_t unk_002C; /* +0x002C rw high */
} ccBoss04BattleStatus;
#pragma pack(pop)

static_assert(offsetof(ccBoss04BattleStatus, unk_002C) == 0x2C, "ccBoss04BattleStatus.unk_002C offset mismatch");
/* sizeof(ccBoss04BattleStatus) not asserted: true size unknown, >= 0x10 */

/* ccBoss0402Changer: no instance state (state_surface returned 0 fields across 13 methods) */

/* ccSceneBoss0402 - 13 seed methods, 1 surface fields
 * Size: unknown, >= 0x9
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccSceneBoss0402 {
    int64_t unk_0000; /* +0x0000 r medium */
} ccSceneBoss0402;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss0402, unk_0000) == 0x0, "ccSceneBoss0402.unk_0000 offset mismatch");
/* sizeof(ccSceneBoss0402) not asserted: true size unknown, >= 0x9 */

/* ccBoss0401FirstSkillCamera: no instance state (state_surface returned 0 fields across 7 methods) */

/* ccSceneBoss0401ChangeBattle: no instance state (state_surface returned 0 fields across 6 methods) */

/* ccBoss0401PlayerCpuStateFormation: no instance state (state_surface returned 0 fields across 6 methods) */

/* ccSceneBoss0401GroupBattle: no instance state (state_surface returned 0 fields across 5 methods) */

/* ccBoss0401PlayerZTU - 5 seed methods, 1 surface fields
 * Size: unknown, >= 0x9
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401PlayerZTU {
    int64_t unk_0000; /* +0x0000 r medium */
} ccBoss0401PlayerZTU;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401PlayerZTU, unk_0000) == 0x0, "ccBoss0401PlayerZTU.unk_0000 offset mismatch");
/* sizeof(ccBoss0401PlayerZTU) not asserted: true size unknown, >= 0x9 */

/* ccSceneBoss0402Root: no instance state (state_surface returned 0 fields across 5 methods) */

/* ccBoss0401PlayerSKR - 4 seed methods, 1 surface fields
 * Size: unknown, >= 0x9
 * All fields INFERRED (static analysis only).
 */
#pragma pack(push, 1)
typedef struct ccBoss0401PlayerSKR {
    int64_t unk_0000; /* +0x0000 r medium */
} ccBoss0401PlayerSKR;
#pragma pack(pop)

static_assert(offsetof(ccBoss0401PlayerSKR, unk_0000) == 0x0, "ccBoss0401PlayerSKR.unk_0000 offset mismatch");
/* sizeof(ccBoss0401PlayerSKR) not asserted: true size unknown, >= 0x9 */

/* ccBoss0402CameraFilter: no instance state (state_surface returned 0 fields across 4 methods) */

/* ccSceneBoss0401Result: no instance state (state_surface returned 0 fields across 3 methods) */

/* ccBoss0401PlayerAMY: no instance state (state_surface returned 0 fields across 3 methods) */

/* ccBoss0401PlayerROC: no instance state (state_surface returned 0 fields across 3 methods) */

/* ccBoss0401PlayerCpuStateAction: no instance state (state_surface returned 0 fields across 3 methods) */

/* ccBoss0402IaActionCamera: no instance state (state_surface returned 0 fields across 3 methods) */

#endif /* S3BOSS04_H */