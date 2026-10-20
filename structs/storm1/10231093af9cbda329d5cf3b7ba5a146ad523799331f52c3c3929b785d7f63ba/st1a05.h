/* st1a05.h — Story progression structs for NARUTO STORM 1 (s1, NSUNS1.exe)
 *
 * INFERRED from static analysis (state_surface). NOT CONFIRMED at runtime.
 * All offsets are PC x64 RVAs relative to object base (param_1).
 * Build: s1 (modded NSUNS1.exe)
 *
 * Classes with 0 recovered fields are listed as opaque stubs.
 * Sizes are proven only where ctor/allocator evidence exists;
 * otherwise 'size unknown, >= 0x<N>' is noted.
 *
 * NOTE: Some fields from state_surface overlap (same offset range claimed
 * by multiple accesses). Overlapping fields are truncated or skipped to
 * maintain valid C struct layout with correct static_assert offsets.
 */

#ifndef ST1A05_H
#define ST1A05_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccDispMissionBreak — no instance state proven (all seeds had unknown param_1 element size) */
struct ccDispMissionBreak {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccDispMissionCategory — no instance state proven (all seeds had unknown param_1 element size) */
struct ccDispMissionCategory {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccDispMissionCollect — INFERRED layout from state_surface (build s1) */
struct ccDispMissionCollect {
    uint8_t _pad_0x0[68];
    float field_44; /* 0x44 [w] medium */
    uint8_t _pad_0x48[4];
    float field_4c; /* 0x4c [w] medium */
    uint8_t _pad_0x50[16];
    int64_t field_60; /* 0x60 [rw] medium */
    uint8_t _pad_0x68[8];
    int64_t field_70; /* 0x70 [w] medium */
    int64_t field_78; /* 0x78 [w] medium */
    int64_t field_80; /* 0x80 [rw] medium */
    uint8_t _pad_0x88[36];
    uint8_t field_ac[68]; /* 0xac [r] low — size inferred 68 from next field */
    int32_t field_f0; /* 0xf0 [rw] low */
    uint8_t _pad_0xf4[12];
    uint8_t field_100[88]; /* 0x100 [r] low — size inferred 88 from next field */
    int32_t field_158; /* 0x158 [w] high */
    uint8_t _pad_0x15c[100];
    int32_t field_1c0; /* 0x1c0 [w] high */
    uint8_t _pad_0x1c4[100];
    int32_t field_228; /* 0x228 [w] high */
    uint8_t _pad_0x22c[100];
    int32_t field_290; /* 0x290 [w] high */
    uint8_t _pad_0x294[100];
    int32_t field_2f8; /* 0x2f8 [w] high */
    uint8_t _pad_0x2fc[100];
    int32_t field_360; /* 0x360 [w] high */
    uint8_t _pad_0x364[100];
    int32_t field_3c8; /* 0x3c8 [w] medium */
    uint8_t _pad_0x3cc[100];
    int32_t field_430; /* 0x430 [w] medium */
    uint8_t _pad_0x434[212];
    int64_t field_508; /* 0x508 [rw] medium */
    int64_t field_510; /* 0x510 [w] medium */
    int64_t field_518; /* 0x518 [w] medium */
    int64_t field_520; /* 0x520 [w] medium */
    int64_t field_528; /* 0x528 [w] medium */
    int64_t field_530; /* 0x530 [w] medium */
    int64_t field_538; /* 0x538 [w] medium */
    uint8_t _pad_0x540[4];
    int32_t field_544; /* 0x544 [rw] high */
} __attribute__((packed));

static_assert(offsetof(struct ccDispMissionCollect, field_44) == 0x44, "ccDispMissionCollect.field_44 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_4c) == 0x4c, "ccDispMissionCollect.field_4c offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_60) == 0x60, "ccDispMissionCollect.field_60 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_70) == 0x70, "ccDispMissionCollect.field_70 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_78) == 0x78, "ccDispMissionCollect.field_78 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_80) == 0x80, "ccDispMissionCollect.field_80 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_ac) == 0xac, "ccDispMissionCollect.field_ac offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_f0) == 0xf0, "ccDispMissionCollect.field_f0 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_100) == 0x100, "ccDispMissionCollect.field_100 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_158) == 0x158, "ccDispMissionCollect.field_158 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_1c0) == 0x1c0, "ccDispMissionCollect.field_1c0 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_228) == 0x228, "ccDispMissionCollect.field_228 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_290) == 0x290, "ccDispMissionCollect.field_290 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_2f8) == 0x2f8, "ccDispMissionCollect.field_2f8 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_360) == 0x360, "ccDispMissionCollect.field_360 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_3c8) == 0x3c8, "ccDispMissionCollect.field_3c8 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_430) == 0x430, "ccDispMissionCollect.field_430 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_508) == 0x508, "ccDispMissionCollect.field_508 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_510) == 0x510, "ccDispMissionCollect.field_510 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_518) == 0x518, "ccDispMissionCollect.field_518 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_520) == 0x520, "ccDispMissionCollect.field_520 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_528) == 0x528, "ccDispMissionCollect.field_528 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_530) == 0x530, "ccDispMissionCollect.field_530 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_538) == 0x538, "ccDispMissionCollect.field_538 offset mismatch");
static_assert(offsetof(struct ccDispMissionCollect, field_544) == 0x544, "ccDispMissionCollect.field_544 offset mismatch");

/* ccDispMissionGauge — no instance state proven (all seeds had unknown param_1 element size) */
struct ccDispMissionGauge {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccDispMissionGoalGuide — INFERRED layout from state_surface (build s1) */
struct ccDispMissionGoalGuide {
    uint8_t _pad_0x0[52];
    uint8_t field_34; /* 0x34 [r] low — size unknown, min 1 byte */
} __attribute__((packed));

static_assert(offsetof(struct ccDispMissionGoalGuide, field_34) == 0x34, "ccDispMissionGoalGuide.field_34 offset mismatch");

/* ccDispMissionLimitCount — INFERRED layout from state_surface (build s1) */
struct ccDispMissionLimitCount {
    uint8_t _pad_0x0[52];
    uint8_t field_34[8]; /* 0x34 [r] low — size inferred 8 from next field */
    uint8_t field_3c[8]; /* 0x3c [r] low — size inferred 8 from next field */
    int64_t field_44; /* 0x44 [w] medium */
    int64_t field_4c; /* 0x4c [w] medium */
    int32_t field_54; /* 0x54 [w] medium — truncated from 8 to 4 (overlap) */
    int64_t field_58; /* 0x58 [w] medium */
    int64_t field_60; /* 0x60 [w] high */
    int64_t field_68; /* 0x68 [w] medium */
    int64_t field_70; /* 0x70 [w] medium */
    int64_t field_78; /* 0x78 [w] medium */
    int64_t field_80; /* 0x80 [w] medium */
    int64_t field_88; /* 0x88 [w] medium */
    int64_t field_90; /* 0x90 [w] medium */
    int64_t field_98; /* 0x98 [w] medium */
    int64_t field_a0; /* 0xa0 [w] medium */
    int64_t field_a8; /* 0xa8 [w] medium */
    int64_t field_b0; /* 0xb0 [w] medium */
    int64_t field_b8; /* 0xb8 [w] medium */
    int64_t field_c0; /* 0xc0 [w] medium */
    uint8_t _pad_0xc8[56];
    uint8_t field_100[56]; /* 0x100 [r] low — size inferred 56 from next field */
    int64_t field_138; /* 0x138 [w] medium */
    int64_t field_140; /* 0x140 [w] medium */
    int64_t field_148; /* 0x148 [w] medium */
    int64_t field_150; /* 0x150 [w] medium */
    int64_t field_158; /* 0x158 [w] medium */
    int64_t field_160; /* 0x160 [w] medium */
    int64_t field_168; /* 0x168 [w] medium */
    int64_t field_170; /* 0x170 [w] medium */
    int64_t field_178; /* 0x178 [w] medium */
    int64_t field_180; /* 0x180 [w] medium */
    uint8_t field_188; /* 0x188 [r] low — size unknown, min 1 byte */
} __attribute__((packed));

static_assert(offsetof(struct ccDispMissionLimitCount, field_34) == 0x34, "ccDispMissionLimitCount.field_34 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_3c) == 0x3c, "ccDispMissionLimitCount.field_3c offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_44) == 0x44, "ccDispMissionLimitCount.field_44 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_4c) == 0x4c, "ccDispMissionLimitCount.field_4c offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_54) == 0x54, "ccDispMissionLimitCount.field_54 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_58) == 0x58, "ccDispMissionLimitCount.field_58 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_60) == 0x60, "ccDispMissionLimitCount.field_60 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_68) == 0x68, "ccDispMissionLimitCount.field_68 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_70) == 0x70, "ccDispMissionLimitCount.field_70 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_78) == 0x78, "ccDispMissionLimitCount.field_78 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_80) == 0x80, "ccDispMissionLimitCount.field_80 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_88) == 0x88, "ccDispMissionLimitCount.field_88 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_90) == 0x90, "ccDispMissionLimitCount.field_90 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_98) == 0x98, "ccDispMissionLimitCount.field_98 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_a0) == 0xa0, "ccDispMissionLimitCount.field_a0 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_a8) == 0xa8, "ccDispMissionLimitCount.field_a8 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_b0) == 0xb0, "ccDispMissionLimitCount.field_b0 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_b8) == 0xb8, "ccDispMissionLimitCount.field_b8 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_c0) == 0xc0, "ccDispMissionLimitCount.field_c0 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_100) == 0x100, "ccDispMissionLimitCount.field_100 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_138) == 0x138, "ccDispMissionLimitCount.field_138 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_140) == 0x140, "ccDispMissionLimitCount.field_140 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_148) == 0x148, "ccDispMissionLimitCount.field_148 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_150) == 0x150, "ccDispMissionLimitCount.field_150 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_158) == 0x158, "ccDispMissionLimitCount.field_158 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_160) == 0x160, "ccDispMissionLimitCount.field_160 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_168) == 0x168, "ccDispMissionLimitCount.field_168 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_170) == 0x170, "ccDispMissionLimitCount.field_170 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_178) == 0x178, "ccDispMissionLimitCount.field_178 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_180) == 0x180, "ccDispMissionLimitCount.field_180 offset mismatch");
static_assert(offsetof(struct ccDispMissionLimitCount, field_188) == 0x188, "ccDispMissionLimitCount.field_188 offset mismatch");

/* WARNING: 1 overlapping field(s) detected and handled: */
/*   offset 0x54 overlapped with current_pos 0x58 (field 0x54) */

/* ccDispMissionPoint — INFERRED layout from state_surface (build s1) */
struct ccDispMissionPoint {
    uint8_t _pad_0x0[88];
    int64_t field_58; /* 0x58 [w] medium */
    int64_t field_60; /* 0x60 [w] medium */
    int64_t field_68; /* 0x68 [w] medium */
    int32_t field_70; /* 0x70 [w] medium */
    int64_t field_74; /* 0x74 [w] medium */
    int32_t field_7c; /* 0x7c [w] medium */
    int32_t field_80; /* 0x80 [w] medium */
    int64_t field_84; /* 0x84 [w] medium */
    uint8_t _pad_0x8c[4];
    int64_t field_90; /* 0x90 [w] medium */
    int64_t field_98; /* 0x98 [w] medium */
    uint8_t _pad_0xa0[96];
    uint8_t field_100; /* 0x100 [r] low — size unknown, min 1 byte */
} __attribute__((packed));

static_assert(offsetof(struct ccDispMissionPoint, field_58) == 0x58, "ccDispMissionPoint.field_58 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_60) == 0x60, "ccDispMissionPoint.field_60 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_68) == 0x68, "ccDispMissionPoint.field_68 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_70) == 0x70, "ccDispMissionPoint.field_70 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_74) == 0x74, "ccDispMissionPoint.field_74 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_7c) == 0x7c, "ccDispMissionPoint.field_7c offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_80) == 0x80, "ccDispMissionPoint.field_80 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_84) == 0x84, "ccDispMissionPoint.field_84 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_90) == 0x90, "ccDispMissionPoint.field_90 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_98) == 0x98, "ccDispMissionPoint.field_98 offset mismatch");
static_assert(offsetof(struct ccDispMissionPoint, field_100) == 0x100, "ccDispMissionPoint.field_100 offset mismatch");

/* ccDispMissionRank — no instance state proven (all seeds had unknown param_1 element size) */
struct ccDispMissionRank {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccDispMissionResult — no instance state proven (all seeds had unknown param_1 element size) */
struct ccDispMissionResult {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccDispMissionSelect — INFERRED layout from state_surface (build s1) */
struct ccDispMissionSelect {
    uint8_t _pad_0x0[44];
    int64_t field_2c; /* 0x2c [w] medium */
    int32_t field_34; /* 0x34 [w] medium */
    uint8_t _pad_0x38[4];
    int32_t field_3c; /* 0x3c [w] medium */
    uint8_t _pad_0x40[20];
    int32_t field_54; /* 0x54 [w] medium */
    int32_t field_58; /* 0x58 [w] medium */
    int32_t field_5c; /* 0x5c [w] medium */
    int64_t field_60; /* 0x60 [w] medium */
    int64_t field_68; /* 0x68 [w] medium */
    int64_t field_70; /* 0x70 [w] medium */
    int32_t field_78; /* 0x78 [w] medium */
    int64_t field_7c; /* 0x7c [w] medium */
    int64_t field_84; /* 0x84 [w] medium */
    int64_t field_8c; /* 0x8c [w] medium */
    uint8_t _pad_0x94[4];
    int64_t field_98; /* 0x98 [w] medium */
    int64_t field_a0; /* 0xa0 [w] medium */
    int64_t field_a8; /* 0xa8 [w] medium */
    int64_t field_b0; /* 0xb0 [w] medium */
    int64_t field_b8; /* 0xb8 [w] medium */
    int64_t field_c0; /* 0xc0 [w] medium */
    uint8_t field_c8[96]; /* 0xc8 [r] low — size inferred 96 from next field */
    int64_t field_128; /* 0x128 [w] medium */
    int64_t field_130; /* 0x130 [w] medium */
    int64_t field_138; /* 0x138 [w] medium */
    int64_t field_140; /* 0x140 [w] medium */
    int64_t field_148; /* 0x148 [w] medium */
    int64_t field_150; /* 0x150 [w] medium */
    int64_t field_158; /* 0x158 [w] medium */
    int64_t field_160; /* 0x160 [w] medium */
    int64_t field_168; /* 0x168 [w] medium */
    int64_t field_170; /* 0x170 [w] medium */
    int64_t field_178; /* 0x178 [w] medium */
    int64_t field_180; /* 0x180 [w] medium */
    int64_t field_188; /* 0x188 [w] medium */
    int64_t field_190; /* 0x190 [w] medium */
    int64_t field_198; /* 0x198 [w] medium */
    int64_t field_1a0; /* 0x1a0 [w] medium */
    int64_t field_1a8; /* 0x1a8 [w] medium */
    int64_t field_1b0; /* 0x1b0 [w] medium */
    int64_t field_1b8; /* 0x1b8 [w] medium */
    int64_t field_1c0; /* 0x1c0 [w] medium */
    int64_t field_1c8; /* 0x1c8 [w] medium */
    int64_t field_1d0; /* 0x1d0 [w] medium */
    int64_t field_1d8; /* 0x1d8 [w] medium */
    int64_t field_1e0; /* 0x1e0 [w] medium */
    int64_t field_1e8; /* 0x1e8 [w] medium */
    int64_t field_1f0; /* 0x1f0 [w] medium */
    uint8_t _pad_0x1f8[8];
    int64_t field_200; /* 0x200 [w] medium */
    int64_t field_208; /* 0x208 [w] medium */
    int64_t field_210; /* 0x210 [w] medium */
    int64_t field_218; /* 0x218 [w] medium */
    uint8_t _pad_0x220[48];
    uint8_t field_250[48]; /* 0x250 [r] low — size inferred 48 from next field */
    int64_t field_280; /* 0x280 [w] medium */
    int64_t field_288; /* 0x288 [w] medium */
    int64_t field_290; /* 0x290 [w] medium */
    int64_t field_298; /* 0x298 [w] medium */
    int64_t field_2a0; /* 0x2a0 [w] medium */
    int64_t field_2a8; /* 0x2a8 [w] medium */
    int64_t field_2b0; /* 0x2b0 [w] medium */
    int64_t field_2b8; /* 0x2b8 [w] medium */
    uint8_t _pad_0x2c0[8];
    int64_t field_2c8; /* 0x2c8 [w] medium */
    uint8_t _pad_0x2d0[16];
    uint8_t field_2e0[16]; /* 0x2e0 [r] low — size inferred 16 from next field */
    uint8_t field_2f0[8]; /* 0x2f0 [r] low — size inferred 8 from next field */
    int64_t field_2f8; /* 0x2f8 [w] medium */
    int64_t field_300; /* 0x300 [w] medium */
    int64_t field_308; /* 0x308 [w] medium */
    int64_t field_310; /* 0x310 [w] medium */
    uint8_t _pad_0x318[16];
    int64_t field_328; /* 0x328 [w] medium */
    int64_t field_330; /* 0x330 [w] medium */
    uint8_t field_338[48]; /* 0x338 [r] low — size inferred 48 from next field */
    uint8_t field_368[96]; /* 0x368 [r] low — size inferred 96 from next field */
    int64_t field_3c8; /* 0x3c8 [w] medium */
    int64_t field_3d0; /* 0x3d0 [w] medium */
} __attribute__((packed));

static_assert(offsetof(struct ccDispMissionSelect, field_2c) == 0x2c, "ccDispMissionSelect.field_2c offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_34) == 0x34, "ccDispMissionSelect.field_34 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_3c) == 0x3c, "ccDispMissionSelect.field_3c offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_54) == 0x54, "ccDispMissionSelect.field_54 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_58) == 0x58, "ccDispMissionSelect.field_58 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_5c) == 0x5c, "ccDispMissionSelect.field_5c offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_60) == 0x60, "ccDispMissionSelect.field_60 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_68) == 0x68, "ccDispMissionSelect.field_68 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_70) == 0x70, "ccDispMissionSelect.field_70 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_78) == 0x78, "ccDispMissionSelect.field_78 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_7c) == 0x7c, "ccDispMissionSelect.field_7c offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_84) == 0x84, "ccDispMissionSelect.field_84 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_8c) == 0x8c, "ccDispMissionSelect.field_8c offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_98) == 0x98, "ccDispMissionSelect.field_98 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_a0) == 0xa0, "ccDispMissionSelect.field_a0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_a8) == 0xa8, "ccDispMissionSelect.field_a8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_b0) == 0xb0, "ccDispMissionSelect.field_b0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_b8) == 0xb8, "ccDispMissionSelect.field_b8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_c0) == 0xc0, "ccDispMissionSelect.field_c0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_c8) == 0xc8, "ccDispMissionSelect.field_c8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_128) == 0x128, "ccDispMissionSelect.field_128 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_130) == 0x130, "ccDispMissionSelect.field_130 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_138) == 0x138, "ccDispMissionSelect.field_138 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_140) == 0x140, "ccDispMissionSelect.field_140 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_148) == 0x148, "ccDispMissionSelect.field_148 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_150) == 0x150, "ccDispMissionSelect.field_150 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_158) == 0x158, "ccDispMissionSelect.field_158 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_160) == 0x160, "ccDispMissionSelect.field_160 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_168) == 0x168, "ccDispMissionSelect.field_168 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_170) == 0x170, "ccDispMissionSelect.field_170 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_178) == 0x178, "ccDispMissionSelect.field_178 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_180) == 0x180, "ccDispMissionSelect.field_180 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_188) == 0x188, "ccDispMissionSelect.field_188 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_190) == 0x190, "ccDispMissionSelect.field_190 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_198) == 0x198, "ccDispMissionSelect.field_198 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1a0) == 0x1a0, "ccDispMissionSelect.field_1a0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1a8) == 0x1a8, "ccDispMissionSelect.field_1a8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1b0) == 0x1b0, "ccDispMissionSelect.field_1b0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1b8) == 0x1b8, "ccDispMissionSelect.field_1b8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1c0) == 0x1c0, "ccDispMissionSelect.field_1c0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1c8) == 0x1c8, "ccDispMissionSelect.field_1c8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1d0) == 0x1d0, "ccDispMissionSelect.field_1d0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1d8) == 0x1d8, "ccDispMissionSelect.field_1d8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1e0) == 0x1e0, "ccDispMissionSelect.field_1e0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1e8) == 0x1e8, "ccDispMissionSelect.field_1e8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_1f0) == 0x1f0, "ccDispMissionSelect.field_1f0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_200) == 0x200, "ccDispMissionSelect.field_200 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_208) == 0x208, "ccDispMissionSelect.field_208 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_210) == 0x210, "ccDispMissionSelect.field_210 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_218) == 0x218, "ccDispMissionSelect.field_218 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_250) == 0x250, "ccDispMissionSelect.field_250 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_280) == 0x280, "ccDispMissionSelect.field_280 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_288) == 0x288, "ccDispMissionSelect.field_288 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_290) == 0x290, "ccDispMissionSelect.field_290 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_298) == 0x298, "ccDispMissionSelect.field_298 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2a0) == 0x2a0, "ccDispMissionSelect.field_2a0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2a8) == 0x2a8, "ccDispMissionSelect.field_2a8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2b0) == 0x2b0, "ccDispMissionSelect.field_2b0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2b8) == 0x2b8, "ccDispMissionSelect.field_2b8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2c8) == 0x2c8, "ccDispMissionSelect.field_2c8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2e0) == 0x2e0, "ccDispMissionSelect.field_2e0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2f0) == 0x2f0, "ccDispMissionSelect.field_2f0 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_2f8) == 0x2f8, "ccDispMissionSelect.field_2f8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_300) == 0x300, "ccDispMissionSelect.field_300 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_308) == 0x308, "ccDispMissionSelect.field_308 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_310) == 0x310, "ccDispMissionSelect.field_310 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_328) == 0x328, "ccDispMissionSelect.field_328 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_330) == 0x330, "ccDispMissionSelect.field_330 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_338) == 0x338, "ccDispMissionSelect.field_338 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_368) == 0x368, "ccDispMissionSelect.field_368 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_3c8) == 0x3c8, "ccDispMissionSelect.field_3c8 offset mismatch");
static_assert(offsetof(struct ccDispMissionSelect, field_3d0) == 0x3d0, "ccDispMissionSelect.field_3d0 offset mismatch");

/* ccDispMissionTimeCount — no instance state proven (all seeds had unknown param_1 element size) */
struct ccDispMissionTimeCount {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccMissionManager — no instance state proven (all seeds had unknown param_1 element size) */
struct ccMissionManager {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccSelectHistory — no instance state proven (all seeds had unknown param_1 element size) */
struct ccSelectHistory {
    uint8_t _unknown[1]; /* placeholder, size unknown */
} __attribute__((packed));

/* ccShopEternalMission — INFERRED layout from state_surface (build s1) */
struct ccShopEternalMission {
    uint8_t _pad_0x0[136];
    uint8_t field_88[16]; /* 0x88 [r] low — size inferred 16 from next field */
    uint8_t field_98[72]; /* 0x98 [r] low — size inferred 72 from next field */
    uint8_t field_e0[24]; /* 0xe0 [r] low — size inferred 24 from next field */
    uint8_t field_f8[24]; /* 0xf8 [r] low — size inferred 24 from next field */
    uint8_t field_110[24]; /* 0x110 [r] low — size inferred 24 from next field */
    uint8_t field_128[24]; /* 0x128 [r] low — size inferred 24 from next field */
    uint8_t field_140[32]; /* 0x140 [r] low — size inferred 32 from next field */
    uint8_t field_160[24]; /* 0x160 [r] low — size inferred 24 from next field */
    uint8_t field_178[24]; /* 0x178 [r] low — size inferred 24 from next field */
    uint8_t field_190[24]; /* 0x190 [r] low — size inferred 24 from next field */
    uint8_t field_1a8[24]; /* 0x1a8 [r] low — size inferred 24 from next field */
    uint8_t field_1c0[144]; /* 0x1c0 [r] low — size inferred 144 from next field */
    int32_t field_250; /* 0x250 [w] medium */
    uint8_t _pad_0x254[4];
    uint8_t field_258[224]; /* 0x258 [r] low — size inferred 224 from next field */
    uint8_t field_338[224]; /* 0x338 [r] low — size inferred 224 from next field */
    uint8_t field_418[176]; /* 0x418 [r] low — size inferred 176 from next field */
    uint8_t field_4c8[176]; /* 0x4c8 [r] low — size inferred 176 from next field */
    uint8_t field_578; /* 0x578 [r] low — size unknown, min 1 byte */
} __attribute__((packed));

static_assert(offsetof(struct ccShopEternalMission, field_88) == 0x88, "ccShopEternalMission.field_88 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_98) == 0x98, "ccShopEternalMission.field_98 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_e0) == 0xe0, "ccShopEternalMission.field_e0 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_f8) == 0xf8, "ccShopEternalMission.field_f8 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_110) == 0x110, "ccShopEternalMission.field_110 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_128) == 0x128, "ccShopEternalMission.field_128 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_140) == 0x140, "ccShopEternalMission.field_140 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_160) == 0x160, "ccShopEternalMission.field_160 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_178) == 0x178, "ccShopEternalMission.field_178 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_190) == 0x190, "ccShopEternalMission.field_190 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_1a8) == 0x1a8, "ccShopEternalMission.field_1a8 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_1c0) == 0x1c0, "ccShopEternalMission.field_1c0 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_250) == 0x250, "ccShopEternalMission.field_250 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_258) == 0x258, "ccShopEternalMission.field_258 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_338) == 0x338, "ccShopEternalMission.field_338 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_418) == 0x418, "ccShopEternalMission.field_418 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_4c8) == 0x4c8, "ccShopEternalMission.field_4c8 offset mismatch");
static_assert(offsetof(struct ccShopEternalMission, field_578) == 0x578, "ccShopEternalMission.field_578 offset mismatch");

#endif /* ST1A05_H */
