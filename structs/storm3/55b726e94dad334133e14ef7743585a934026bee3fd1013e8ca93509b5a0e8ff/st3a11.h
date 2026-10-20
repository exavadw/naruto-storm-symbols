#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* st3a11 group — NARUTO STORM 3 Full Burst HD (s3, NSUNS3.exe x64)
 * All layouts INFERRED from static analysis. Not CONFIRMED.
 * Sizes are unproven unless noted; no sizeof asserts.
 */

/* ccAdvFriendshipWindowState: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvGameStatus: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvJumpCamera: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvLetterSystemManager: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

typedef struct __attribute__((packed)) ccAdvManager {
    uint8_t _pad_0000[76];
    void* field_004C; /* +0x4C */
    uint32_t field_0054; /* +0x54 */
    uint32_t field_0058; /* +0x58 */
    uint32_t field_005C; /* +0x5C */
    uint64_t field_0060; /* +0x60 */
    uint64_t field_0068; /* +0x68 */
    uint8_t field_0070[16]; /* +0x70 (gap=16, natural=8) */
    void* field_0080; /* +0x80 */
    uint64_t field_0088; /* +0x88 */
    uint64_t field_0090; /* +0x90 */
    uint64_t field_0098; /* +0x98 */
    uint8_t field_00A0[24]; /* +0xA0 (gap=24, natural=8) */
    uint64_t field_00B8; /* +0xB8 */
    uint64_t field_00C0; /* +0xC0 */
    uint64_t field_00C8; /* +0xC8 */
    uint8_t field_00D0[24]; /* +0xD0 (gap=24, natural=8) */
    uint8_t field_00E8[20]; /* +0xE8 */
    uint32_t field_00FC; /* +0xFC */
    uint8_t field_0100[3]; /* +0x100 */
    uint8_t field_0103[13]; /* +0x103 (gap=13, natural=1) */
    uint8_t field_0110[40]; /* +0x110 */
    uint64_t field_0138; /* +0x138 */
    uint64_t field_0140; /* +0x140 */
    uint8_t field_0148[56]; /* +0x148 */
    uint8_t field_0180[56]; /* +0x180 */
    uint8_t field_01B8[8]; /* +0x1B8 (gap=8, natural=4) */
    uint64_t field_01C0; /* +0x1C0 */
    uint8_t field_01C8[40]; /* +0x1C8 (gap=40, natural=8) */
    uint8_t field_01F0[232]; /* +0x1F0 */
    uint8_t field_02D8[1688]; /* +0x2D8 (gap=1688, natural=4) */
    uint8_t field_0970[152]; /* +0x970 */
    uint64_t field_0A08; /* +0xA08 */
    uint64_t field_0A10; /* +0xA10 */
    uint64_t field_0A18; /* +0xA18 */
    uint8_t field_0A20[1808]; /* +0xA20 (gap=1808, natural=8) */
    uint8_t field_1130[920]; /* +0x1130 */
    uint8_t field_14C8[96]; /* +0x14C8 */
    uint8_t field_1528[56]; /* +0x1528 */
    uint8_t field_1560[576]; /* +0x1560 */
    uint8_t field_17A0[112]; /* +0x17A0 */
    uint8_t field_1810[64]; /* +0x1810 */
    uint8_t field_1850[96]; /* +0x1850 */
    uint8_t field_18B0[96]; /* +0x18B0 */
    uint8_t field_1910[64]; /* +0x1910 */
    uint8_t field_1950[56]; /* +0x1950 */
    uint8_t field_1988[56]; /* +0x1988 */
    uint8_t field_19C0[48]; /* +0x19C0 */
    uint8_t field_19F0[56]; /* +0x19F0 */
    uint8_t field_1A28[56]; /* +0x1A28 */
    uint8_t field_1A60[152]; /* +0x1A60 */
    uint8_t field_1AF8[216]; /* +0x1AF8 */
    uint8_t field_1BD0[144]; /* +0x1BD0 */
    uint8_t field_1C60[88]; /* +0x1C60 */
    uint64_t field_1CB8; /* +0x1CB8 */
    uint8_t field_1CC0[296]; /* +0x1CC0 */
    uint64_t field_1DE8; /* +0x1DE8 */
    uint64_t field_1DF0; /* +0x1DF0 */
    uint64_t field_1DF8; /* +0x1DF8 */
    uint64_t field_1E00; /* +0x1E00 */
    uint8_t field_1E08[64]; /* +0x1E08 */
    uint8_t field_1E48[64]; /* +0x1E48 */
    uint64_t field_1E88; /* +0x1E88 */
    uint64_t field_1E90; /* +0x1E90 */
    uint64_t field_1E98; /* +0x1E98 */
    uint8_t field_1EA0[32]; /* +0x1EA0 (gap=32, natural=8) */
    uint8_t field_1EC0[56]; /* +0x1EC0 */
    uint8_t field_1EF8[104]; /* +0x1EF8 */
    uint8_t field_1F60[656]; /* +0x1F60 */
    uint8_t field_21F0[48]; /* +0x21F0 */
    uint8_t field_2220[48]; /* +0x2220 */
    uint8_t field_2250[48]; /* +0x2250 */
    uint8_t field_2280[64]; /* +0x2280 */
    uint8_t field_22C0[8]; /* +0x22C0 (gap=8, natural=4) */
    uint8_t field_22C8[104]; /* +0x22C8 */
    void* field_2330; /* +0x2330 */
} ccAdvManager;
static_assert(offsetof(ccAdvManager, field_004C) == 0x4C, "ccAdvManager.field_004C offset mismatch");
static_assert(offsetof(ccAdvManager, field_0054) == 0x54, "ccAdvManager.field_0054 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0058) == 0x58, "ccAdvManager.field_0058 offset mismatch");
static_assert(offsetof(ccAdvManager, field_005C) == 0x5C, "ccAdvManager.field_005C offset mismatch");
static_assert(offsetof(ccAdvManager, field_0060) == 0x60, "ccAdvManager.field_0060 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0068) == 0x68, "ccAdvManager.field_0068 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0070) == 0x70, "ccAdvManager.field_0070 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0080) == 0x80, "ccAdvManager.field_0080 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0088) == 0x88, "ccAdvManager.field_0088 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0090) == 0x90, "ccAdvManager.field_0090 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0098) == 0x98, "ccAdvManager.field_0098 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00A0) == 0xA0, "ccAdvManager.field_00A0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00B8) == 0xB8, "ccAdvManager.field_00B8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00C0) == 0xC0, "ccAdvManager.field_00C0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00C8) == 0xC8, "ccAdvManager.field_00C8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00D0) == 0xD0, "ccAdvManager.field_00D0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00E8) == 0xE8, "ccAdvManager.field_00E8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_00FC) == 0xFC, "ccAdvManager.field_00FC offset mismatch");
static_assert(offsetof(ccAdvManager, field_0100) == 0x100, "ccAdvManager.field_0100 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0103) == 0x103, "ccAdvManager.field_0103 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0110) == 0x110, "ccAdvManager.field_0110 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0138) == 0x138, "ccAdvManager.field_0138 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0140) == 0x140, "ccAdvManager.field_0140 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0148) == 0x148, "ccAdvManager.field_0148 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0180) == 0x180, "ccAdvManager.field_0180 offset mismatch");
static_assert(offsetof(ccAdvManager, field_01B8) == 0x1B8, "ccAdvManager.field_01B8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_01C0) == 0x1C0, "ccAdvManager.field_01C0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_01C8) == 0x1C8, "ccAdvManager.field_01C8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_01F0) == 0x1F0, "ccAdvManager.field_01F0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_02D8) == 0x2D8, "ccAdvManager.field_02D8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0970) == 0x970, "ccAdvManager.field_0970 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0A08) == 0xA08, "ccAdvManager.field_0A08 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0A10) == 0xA10, "ccAdvManager.field_0A10 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0A18) == 0xA18, "ccAdvManager.field_0A18 offset mismatch");
static_assert(offsetof(ccAdvManager, field_0A20) == 0xA20, "ccAdvManager.field_0A20 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1130) == 0x1130, "ccAdvManager.field_1130 offset mismatch");
static_assert(offsetof(ccAdvManager, field_14C8) == 0x14C8, "ccAdvManager.field_14C8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1528) == 0x1528, "ccAdvManager.field_1528 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1560) == 0x1560, "ccAdvManager.field_1560 offset mismatch");
static_assert(offsetof(ccAdvManager, field_17A0) == 0x17A0, "ccAdvManager.field_17A0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1810) == 0x1810, "ccAdvManager.field_1810 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1850) == 0x1850, "ccAdvManager.field_1850 offset mismatch");
static_assert(offsetof(ccAdvManager, field_18B0) == 0x18B0, "ccAdvManager.field_18B0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1910) == 0x1910, "ccAdvManager.field_1910 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1950) == 0x1950, "ccAdvManager.field_1950 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1988) == 0x1988, "ccAdvManager.field_1988 offset mismatch");
static_assert(offsetof(ccAdvManager, field_19C0) == 0x19C0, "ccAdvManager.field_19C0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_19F0) == 0x19F0, "ccAdvManager.field_19F0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1A28) == 0x1A28, "ccAdvManager.field_1A28 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1A60) == 0x1A60, "ccAdvManager.field_1A60 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1AF8) == 0x1AF8, "ccAdvManager.field_1AF8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1BD0) == 0x1BD0, "ccAdvManager.field_1BD0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1C60) == 0x1C60, "ccAdvManager.field_1C60 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1CB8) == 0x1CB8, "ccAdvManager.field_1CB8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1CC0) == 0x1CC0, "ccAdvManager.field_1CC0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1DE8) == 0x1DE8, "ccAdvManager.field_1DE8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1DF0) == 0x1DF0, "ccAdvManager.field_1DF0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1DF8) == 0x1DF8, "ccAdvManager.field_1DF8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1E00) == 0x1E00, "ccAdvManager.field_1E00 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1E08) == 0x1E08, "ccAdvManager.field_1E08 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1E48) == 0x1E48, "ccAdvManager.field_1E48 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1E88) == 0x1E88, "ccAdvManager.field_1E88 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1E90) == 0x1E90, "ccAdvManager.field_1E90 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1E98) == 0x1E98, "ccAdvManager.field_1E98 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1EA0) == 0x1EA0, "ccAdvManager.field_1EA0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1EC0) == 0x1EC0, "ccAdvManager.field_1EC0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1EF8) == 0x1EF8, "ccAdvManager.field_1EF8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_1F60) == 0x1F60, "ccAdvManager.field_1F60 offset mismatch");
static_assert(offsetof(ccAdvManager, field_21F0) == 0x21F0, "ccAdvManager.field_21F0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_2220) == 0x2220, "ccAdvManager.field_2220 offset mismatch");
static_assert(offsetof(ccAdvManager, field_2250) == 0x2250, "ccAdvManager.field_2250 offset mismatch");
static_assert(offsetof(ccAdvManager, field_2280) == 0x2280, "ccAdvManager.field_2280 offset mismatch");
static_assert(offsetof(ccAdvManager, field_22C0) == 0x22C0, "ccAdvManager.field_22C0 offset mismatch");
static_assert(offsetof(ccAdvManager, field_22C8) == 0x22C8, "ccAdvManager.field_22C8 offset mismatch");
static_assert(offsetof(ccAdvManager, field_2330) == 0x2330, "ccAdvManager.field_2330 offset mismatch");
/* ccAdvManager: size unknown, >= 0x2338 (75 fields) */

/* ccAdvMiniMapManager: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobAnmDraw: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobClumpDraw: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobInfoDataList: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobInfoManager: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobDraw: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobEffect: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobHeadCtrl: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

/* ccAdvMobHeadState: no fields recovered (seeds had byte-cast-only accesses or <3 methods) */

