#ifndef S3_BOSS08_H
#define S3_BOSS08_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s3Boss08 - Storm 3 Full Burst HD (NSUNS3.exe 64-bit) boss battle structs
 * Build: s3 (sha 55b726e94dad)
 * All fields INFERRED from static analysis (state_surface + decomp).
 * Object sizes from FUN_140683f70 (allocator/operator new) first argument.
 */

/* ========================================================================
 * ccBoss08PlayerKBX
 * Object size 0xB098 from allocator (FUN_140683f70)
 * All fields INFERRED from static analysis.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccBoss08PlayerKBX {
    uint8_t pad_0000[112]; /* 0x0000 */
    double   unk_0070; /* 0x0070 low r CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint32_t unk_0078; /* 0x0078 low r CtrlAct_PL_ACT_BOSS_FUNC_04; CtrlAct_PL_ACT_BOSS_FUNC_05 */
    uint8_t pad_007C[20]; /* 0x007C */
    uint64_t unk_0090; /* 0x0090 high rw CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint32_t unk_0098; /* 0x0098 high rw CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_009C[24]; /* 0x009C */
    uint64_t unk_00B4; /* 0x00B4 medium r CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint32_t unk_00BC; /* 0x00BC medium r CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint8_t pad_00C0[72]; /* 0x00C0 */
    uint32_t unk_0108; /* 0x0108 low r CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint8_t pad_010C[76]; /* 0x010C */
    uint32_t unk_0158; /* 0x0158 high rw CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_01 */
    uint8_t pad_015C[164]; /* 0x015C */
    float    unk_0200; /* 0x0200 low r CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_0204[2024]; /* 0x0204 */
    uint32_t unk_09EC; /* 0x09EC medium r CtrlAct_PL_ACT_BOSS_FUNC_08; CtrlCounter */
    uint8_t pad_09F0[12]; /* 0x09F0 */
    uint32_t unk_09FC; /* 0x09FC medium rw CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint32_t unk_0A00; /* 0x0A00 medium rw CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint32_t unk_0A04; /* 0x0A04 medium rw CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_0A08[8952]; /* 0x0A08 */
    float    unk_2D00; /* 0x2D00 low r CtrlAct_PL_ACT_BOSS_FUNC_08; CtrlCounter */
    uint8_t pad_2D04[60]; /* 0x2D04 */
    float    unk_2D40; /* 0x2D40 low r CtrlAct_PL_ACT_BOSS_FUNC_08; CtrlCounter */
    uint8_t pad_2D44[572]; /* 0x2D44 */
    uint32_t unk_2F80; /* 0x2F80 low r CtrlAct_PL_ACT_BOSS_FUNC_06; CtrlAct_PL_ACT_BOSS_FUNC_08 */
    uint8_t pad_2F84[2492]; /* 0x2F84 */
    uint32_t unk_3940; /* 0x3940 low r CtrlAct_PL_ACT_BOSS_FUNC_01; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_3944[2876]; /* 0x3944 */
    uint32_t unk_4480; /* 0x4480 low r ChooseOptimalScriptbyDistance; CtrlCounter */
    uint8_t pad_4484[15164]; /* 0x4484 */
    uint64_t unk_7FC0; /* 0x7FC0 medium r CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t pad_7FC8[552]; /* 0x7FC8 */
    uint64_t unk_81F0; /* 0x81F0 medium r CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint8_t pad_81F8[8476]; /* 0x81F8 */
    uint32_t unk_A314; /* 0xA314 high rw CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint8_t pad_A318[2176]; /* 0xA318 */
    uint32_t unk_AB98; /* 0xAB98 high rw CtrlAct_PL_ACT_BOSS_FUNC_06; CtrlAct_PL_ACT_BOSS_FUNC_08 */
    uint8_t pad_AB9C[1004]; /* 0xAB9C */
    double   unk_AF88; /* 0xAF88 medium r CtrlCounter */
    uint8_t pad_AF90[104]; /* 0xAF90 */
    uint64_t unk_AFF8; /* 0xAFF8 high rw CtrlCounter; ccBoss08PlayerKBX */
    float    unk_B000; /* 0xB000 low rw CtrlCounter; ccBoss08PlayerKBX */
    uint32_t unk_B004; /* 0xB004 medium rw CtrlAct_PL_ACT_BOSS_FUNC_08 */
    float    unk_B008; /* 0xB008 high rw CtrlCounter; ccBoss08PlayerKBX */
    uint32_t unk_B00C; /* 0xB00C high rw CtrlAct_PL_ACT_BOSS_FUNC_08 */
    float    unk_B010; /* 0xB010 low rw CtrlCounter; ccBoss08PlayerKBX */
    float    unk_B014; /* 0xB014 high rw ChooseOptimalScriptbyDistance; CtrlCounter */
    float    unk_B018; /* 0xB018 low rw CtrlCounter; ccBoss08PlayerKBX */
    uint8_t pad_B01C[4]; /* 0xB01C */
    uint64_t unk_B020; /* 0xB020 medium r CtrlCounter */
    uint32_t unk_B028; /* 0xB028 high rw CtrlAct_PL_ACT_BOSS_FUNC_01; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint32_t unk_B02C; /* 0xB02C low rw CtrlCounter; EndSpecialSkill */
    uint32_t unk_B030; /* 0xB030 high rw CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint32_t unk_B034; /* 0xB034 low rw ChooseOptimalScriptbyDistance; EndSpecialSkill */
    uint32_t unk_B038; /* 0xB038 high rw CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint32_t unk_B03C; /* 0xB03C low rw CtrlAct_PL_ACT_BOSS_FUNC_00; ccBoss08PlayerKBX */
    uint32_t unk_B040; /* 0xB040 medium rw CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint32_t unk_B044; /* 0xB044 low rw CtrlAct_PL_ACT_BOSS_FUNC_04; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint32_t unk_B048; /* 0xB048 medium rw CtrlAct_PL_ACT_BOSS_FUNC_05 */
    uint32_t unk_B04C; /* 0xB04C high rw CtrlAct_PL_ACT_BOSS_FUNC_07; ccBoss08PlayerKBX */
    uint32_t unk_B050; /* 0xB050 high rw CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint32_t unk_B054; /* 0xB054 high rw CtrlAct_PL_ACT_BOSS_FUNC_04; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint32_t unk_B058; /* 0xB058 high rw CtrlAct_PL_ACT_BOSS_FUNC_04; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint64_t unk_B05C; /* 0xB05C low r CtrlAct_PL_ACT_BOSS_FUNC_06; ccBoss08PlayerKBX */
    uint32_t unk_B064; /* 0xB064 high rw CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint32_t unk_B068; /* 0xB068 medium rw CtrlAct_PL_ACT_BOSS_FUNC_07 */
    uint64_t unk_B06C; /* 0xB06C high rw CtrlCounter; ccBoss08PlayerKBX */
    uint32_t unk_B074; /* 0xB074 low rw CtrlAct_PL_ACT_BOSS_FUNC_06; CtrlAct_PL_ACT_BOSS_FUNC_08 */
    uint64_t unk_B078; /* 0xB078 medium r CtrlCounter */
    uint64_t unk_B080; /* 0xB080 high rw CtrlAct_PL_ACT_BOSS_FUNC_07; ccBoss08PlayerKBX */
    uint64_t unk_B088; /* 0xB088 high rw CtrlAct_PL_ACT_BOSS_FUNC_07; ccBoss08PlayerKBX */
    uint64_t unk_B090; /* 0xB090 medium rw ccBoss08PlayerKBX */
} ccBoss08PlayerKBX;
#pragma pack(pop)
/* ========================================================================
 * ccSceneBoss0810
 * Object size 0x400 from allocator (FUN_140683f70)
 * All fields INFERRED from static analysis.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccSceneBoss0810 {
    uint8_t pad_0000[296]; /* 0x0000 */
    uint32_t unk_0128; /* 0x0128 medium rw PostInitialize */
    uint8_t pad_012C[4]; /* 0x012C */
    uint64_t unk_0130; /* 0x0130 medium rw PostInitialize */
    uint32_t unk_0138; /* 0x0138 low r PostInitialize */
    uint8_t pad_013C[84]; /* 0x013C */
    uint32_t unk_0190; /* 0x0190 low r PostInitialize */
    uint8_t pad_0194[244]; /* 0x0194 */
    uint64_t unk_0288; /* 0x0288 medium rw PostInitialize */
    uint8_t pad_0290[8]; /* 0x0290 */
    uint32_t unk_0298; /* 0x0298 medium rw PostInitialize */
    uint8_t pad_029C[4]; /* 0x029C */
    uint32_t unk_02A0; /* 0x02A0 medium rw PostInitialize */
    uint8_t pad_02A4[4]; /* 0x02A4 */
    uint32_t unk_02A8; /* 0x02A8 medium rw PostInitialize */
    uint8_t pad_02AC[12]; /* 0x02AC */
    uint64_t unk_02B8; /* 0x02B8 medium rw PostInitialize */
    uint64_t unk_02C0; /* 0x02C0 medium rw PostInitialize */
    uint64_t unk_02C8; /* 0x02C8 medium rw PostInitialize */
    uint64_t unk_02D0; /* 0x02D0 medium rw PostInitialize */
    uint64_t unk_02D8; /* 0x02D8 medium rw PostInitialize */
    uint64_t unk_02E0; /* 0x02E0 medium rw PostInitialize */
    uint64_t unk_02E8; /* 0x02E8 medium rw PostInitialize */
    uint64_t unk_02F0; /* 0x02F0 medium rw PostInitialize */
    uint32_t unk_02F8; /* 0x02F8 low r ccSceneBoss0810 */
    uint8_t pad_02FC[132]; /* 0x02FC */
    uint32_t unk_0380; /* 0x0380 low r PostInitialize; ccSceneBoss0810 */
    uint8_t pad_0384[116]; /* 0x0384 */
    uint32_t unk_03F8; /* 0x03F8 low rw PostInitialize; ccSceneBoss0810 */
    uint32_t unk_03FC; /* 0x03FC medium rw ccSceneBoss0810 */
} ccSceneBoss0810;
#pragma pack(pop)
/* ========================================================================
 * ccBoss08SkillTYYGhost
 * Object size 0x280 from allocator (FUN_140683f70)
 * All fields INFERRED from static analysis.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccBoss08SkillTYYGhost {
    uint8_t pad_0000[12]; /* 0x0000 */
    uint32_t unk_000C; /* 0x000C medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0010[20]; /* 0x0010 */
    uint64_t unk_0024; /* 0x0024 low r ccBoss08SkillTYYGhost */
    uint32_t unk_002C; /* 0x002C medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0030[12]; /* 0x0030 */
    uint64_t unk_003C; /* 0x003C low rw ccBoss08SkillTYYGhost */
    uint32_t unk_0044; /* 0x0044 medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0048[20]; /* 0x0048 */
    float    unk_005C; /* 0x005C medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0060[12]; /* 0x0060 */
    uint32_t unk_006C; /* 0x006C medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0070[4]; /* 0x0070 */
    uint32_t unk_0074; /* 0x0074 medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0078[4]; /* 0x0078 */
    uint32_t unk_007C; /* 0x007C medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0080[4]; /* 0x0080 */
    uint32_t unk_0084; /* 0x0084 medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0088[20]; /* 0x0088 */
    uint32_t unk_009C; /* 0x009C medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_00A0[92]; /* 0x00A0 */
    uint32_t unk_00FC; /* 0x00FC low r ccBoss08SkillTYYGhost */
    uint8_t pad_0100[356]; /* 0x0100 */
    uint32_t unk_0264; /* 0x0264 medium rw ccBoss08SkillTYYGhost */
    uint8_t pad_0268[24]; /* 0x0268 tail pad */
} ccBoss08SkillTYYGhost;
#pragma pack(pop)
/* ========================================================================
 * ccBoss08AutoSupport
 * Object size 0xAFC0 from allocator (FUN_140683f70)
 * All fields INFERRED from static analysis.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccBoss08AutoSupport {
    uint8_t pad_0000[2516]; /* 0x0000 */
    uint32_t unk_09D4; /* 0x09D4 medium rw RequestSupportAction */
    uint8_t pad_09D8[12136]; /* 0x09D8 */
    uint32_t unk_3940; /* 0x3940 low r RequestSupportAction */
    uint8_t pad_3944[380]; /* 0x3944 */
    uint32_t unk_3AC0; /* 0x3AC0 low r RequestSupportAction */
    uint8_t pad_3AC4[3004]; /* 0x3AC4 */
    uint32_t unk_4680; /* 0x4680 low r RequestSupportAction */
    uint8_t pad_4684[7804]; /* 0x4684 */
    uint32_t unk_6500; /* 0x6500 low r CheckAutoExecSupport */
    uint8_t pad_6504[18420]; /* 0x6504 */
    uint32_t unk_ACF8; /* 0xACF8 low r RequestSupportAction */
    uint8_t pad_ACFC[124]; /* 0xACFC */
    uint32_t unk_AD78; /* 0xAD78 high rw RequestSupportAction */
    uint32_t unk_AD7C; /* 0xAD7C high rw RequestSupportAction */
    uint8_t pad_AD80[40]; /* 0xAD80 */
    uint32_t unk_ADA8; /* 0xADA8 medium rw RequestSupportAction */
    uint8_t pad_ADAC[524]; /* 0xADAC */
    uint32_t unk_AFB8; /* 0xAFB8 high rw CheckAutoExecSupport; ccBoss08AutoSupport */
    uint32_t unk_AFBC; /* 0xAFBC high rw CheckAutoExecSupport; ccBoss08AutoSupport */
} ccBoss08AutoSupport;
#pragma pack(pop)

/* Offset assertions */
static_assert(sizeof(ccBoss08PlayerKBX) == 0xB098, "ccBoss08PlayerKBX size");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0070) == 0x0070, "ccBoss08PlayerKBX.unk_0070");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0078) == 0x0078, "ccBoss08PlayerKBX.unk_0078");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0090) == 0x0090, "ccBoss08PlayerKBX.unk_0090");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0098) == 0x0098, "ccBoss08PlayerKBX.unk_0098");
static_assert(offsetof(ccBoss08PlayerKBX, unk_00B4) == 0x00B4, "ccBoss08PlayerKBX.unk_00B4");
static_assert(offsetof(ccBoss08PlayerKBX, unk_00BC) == 0x00BC, "ccBoss08PlayerKBX.unk_00BC");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0108) == 0x0108, "ccBoss08PlayerKBX.unk_0108");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0158) == 0x0158, "ccBoss08PlayerKBX.unk_0158");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0200) == 0x0200, "ccBoss08PlayerKBX.unk_0200");
static_assert(offsetof(ccBoss08PlayerKBX, unk_09EC) == 0x09EC, "ccBoss08PlayerKBX.unk_09EC");
static_assert(offsetof(ccBoss08PlayerKBX, unk_09FC) == 0x09FC, "ccBoss08PlayerKBX.unk_09FC");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0A00) == 0x0A00, "ccBoss08PlayerKBX.unk_0A00");
static_assert(offsetof(ccBoss08PlayerKBX, unk_0A04) == 0x0A04, "ccBoss08PlayerKBX.unk_0A04");
static_assert(offsetof(ccBoss08PlayerKBX, unk_2D00) == 0x2D00, "ccBoss08PlayerKBX.unk_2D00");
static_assert(offsetof(ccBoss08PlayerKBX, unk_2D40) == 0x2D40, "ccBoss08PlayerKBX.unk_2D40");
static_assert(offsetof(ccBoss08PlayerKBX, unk_2F80) == 0x2F80, "ccBoss08PlayerKBX.unk_2F80");
static_assert(offsetof(ccBoss08PlayerKBX, unk_3940) == 0x3940, "ccBoss08PlayerKBX.unk_3940");
static_assert(offsetof(ccBoss08PlayerKBX, unk_4480) == 0x4480, "ccBoss08PlayerKBX.unk_4480");
static_assert(offsetof(ccBoss08PlayerKBX, unk_7FC0) == 0x7FC0, "ccBoss08PlayerKBX.unk_7FC0");
static_assert(offsetof(ccBoss08PlayerKBX, unk_81F0) == 0x81F0, "ccBoss08PlayerKBX.unk_81F0");
static_assert(offsetof(ccBoss08PlayerKBX, unk_A314) == 0xA314, "ccBoss08PlayerKBX.unk_A314");
static_assert(offsetof(ccBoss08PlayerKBX, unk_AB98) == 0xAB98, "ccBoss08PlayerKBX.unk_AB98");
static_assert(offsetof(ccBoss08PlayerKBX, unk_AF88) == 0xAF88, "ccBoss08PlayerKBX.unk_AF88");
static_assert(offsetof(ccBoss08PlayerKBX, unk_AFF8) == 0xAFF8, "ccBoss08PlayerKBX.unk_AFF8");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B000) == 0xB000, "ccBoss08PlayerKBX.unk_B000");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B004) == 0xB004, "ccBoss08PlayerKBX.unk_B004");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B008) == 0xB008, "ccBoss08PlayerKBX.unk_B008");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B00C) == 0xB00C, "ccBoss08PlayerKBX.unk_B00C");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B010) == 0xB010, "ccBoss08PlayerKBX.unk_B010");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B014) == 0xB014, "ccBoss08PlayerKBX.unk_B014");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B018) == 0xB018, "ccBoss08PlayerKBX.unk_B018");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B020) == 0xB020, "ccBoss08PlayerKBX.unk_B020");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B028) == 0xB028, "ccBoss08PlayerKBX.unk_B028");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B02C) == 0xB02C, "ccBoss08PlayerKBX.unk_B02C");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B030) == 0xB030, "ccBoss08PlayerKBX.unk_B030");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B034) == 0xB034, "ccBoss08PlayerKBX.unk_B034");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B038) == 0xB038, "ccBoss08PlayerKBX.unk_B038");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B03C) == 0xB03C, "ccBoss08PlayerKBX.unk_B03C");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B040) == 0xB040, "ccBoss08PlayerKBX.unk_B040");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B044) == 0xB044, "ccBoss08PlayerKBX.unk_B044");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B048) == 0xB048, "ccBoss08PlayerKBX.unk_B048");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B04C) == 0xB04C, "ccBoss08PlayerKBX.unk_B04C");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B050) == 0xB050, "ccBoss08PlayerKBX.unk_B050");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B054) == 0xB054, "ccBoss08PlayerKBX.unk_B054");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B058) == 0xB058, "ccBoss08PlayerKBX.unk_B058");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B05C) == 0xB05C, "ccBoss08PlayerKBX.unk_B05C");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B064) == 0xB064, "ccBoss08PlayerKBX.unk_B064");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B068) == 0xB068, "ccBoss08PlayerKBX.unk_B068");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B06C) == 0xB06C, "ccBoss08PlayerKBX.unk_B06C");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B074) == 0xB074, "ccBoss08PlayerKBX.unk_B074");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B078) == 0xB078, "ccBoss08PlayerKBX.unk_B078");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B080) == 0xB080, "ccBoss08PlayerKBX.unk_B080");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B088) == 0xB088, "ccBoss08PlayerKBX.unk_B088");
static_assert(offsetof(ccBoss08PlayerKBX, unk_B090) == 0xB090, "ccBoss08PlayerKBX.unk_B090");
static_assert(sizeof(ccSceneBoss0810) == 0x400, "ccSceneBoss0810 size");
static_assert(offsetof(ccSceneBoss0810, unk_0128) == 0x0128, "ccSceneBoss0810.unk_0128");
static_assert(offsetof(ccSceneBoss0810, unk_0130) == 0x0130, "ccSceneBoss0810.unk_0130");
static_assert(offsetof(ccSceneBoss0810, unk_0138) == 0x0138, "ccSceneBoss0810.unk_0138");
static_assert(offsetof(ccSceneBoss0810, unk_0190) == 0x0190, "ccSceneBoss0810.unk_0190");
static_assert(offsetof(ccSceneBoss0810, unk_0288) == 0x0288, "ccSceneBoss0810.unk_0288");
static_assert(offsetof(ccSceneBoss0810, unk_0298) == 0x0298, "ccSceneBoss0810.unk_0298");
static_assert(offsetof(ccSceneBoss0810, unk_02A0) == 0x02A0, "ccSceneBoss0810.unk_02A0");
static_assert(offsetof(ccSceneBoss0810, unk_02A8) == 0x02A8, "ccSceneBoss0810.unk_02A8");
static_assert(offsetof(ccSceneBoss0810, unk_02B8) == 0x02B8, "ccSceneBoss0810.unk_02B8");
static_assert(offsetof(ccSceneBoss0810, unk_02C0) == 0x02C0, "ccSceneBoss0810.unk_02C0");
static_assert(offsetof(ccSceneBoss0810, unk_02C8) == 0x02C8, "ccSceneBoss0810.unk_02C8");
static_assert(offsetof(ccSceneBoss0810, unk_02D0) == 0x02D0, "ccSceneBoss0810.unk_02D0");
static_assert(offsetof(ccSceneBoss0810, unk_02D8) == 0x02D8, "ccSceneBoss0810.unk_02D8");
static_assert(offsetof(ccSceneBoss0810, unk_02E0) == 0x02E0, "ccSceneBoss0810.unk_02E0");
static_assert(offsetof(ccSceneBoss0810, unk_02E8) == 0x02E8, "ccSceneBoss0810.unk_02E8");
static_assert(offsetof(ccSceneBoss0810, unk_02F0) == 0x02F0, "ccSceneBoss0810.unk_02F0");
static_assert(offsetof(ccSceneBoss0810, unk_02F8) == 0x02F8, "ccSceneBoss0810.unk_02F8");
static_assert(offsetof(ccSceneBoss0810, unk_0380) == 0x0380, "ccSceneBoss0810.unk_0380");
static_assert(offsetof(ccSceneBoss0810, unk_03F8) == 0x03F8, "ccSceneBoss0810.unk_03F8");
static_assert(offsetof(ccSceneBoss0810, unk_03FC) == 0x03FC, "ccSceneBoss0810.unk_03FC");
static_assert(sizeof(ccBoss08SkillTYYGhost) == 0x280, "ccBoss08SkillTYYGhost size");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_000C) == 0x000C, "ccBoss08SkillTYYGhost.unk_000C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_0024) == 0x0024, "ccBoss08SkillTYYGhost.unk_0024");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_002C) == 0x002C, "ccBoss08SkillTYYGhost.unk_002C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_003C) == 0x003C, "ccBoss08SkillTYYGhost.unk_003C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_0044) == 0x0044, "ccBoss08SkillTYYGhost.unk_0044");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_005C) == 0x005C, "ccBoss08SkillTYYGhost.unk_005C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_006C) == 0x006C, "ccBoss08SkillTYYGhost.unk_006C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_0074) == 0x0074, "ccBoss08SkillTYYGhost.unk_0074");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_007C) == 0x007C, "ccBoss08SkillTYYGhost.unk_007C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_0084) == 0x0084, "ccBoss08SkillTYYGhost.unk_0084");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_009C) == 0x009C, "ccBoss08SkillTYYGhost.unk_009C");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_00FC) == 0x00FC, "ccBoss08SkillTYYGhost.unk_00FC");
static_assert(offsetof(ccBoss08SkillTYYGhost, unk_0264) == 0x0264, "ccBoss08SkillTYYGhost.unk_0264");
static_assert(sizeof(ccBoss08AutoSupport) == 0xAFC0, "ccBoss08AutoSupport size");
static_assert(offsetof(ccBoss08AutoSupport, unk_09D4) == 0x09D4, "ccBoss08AutoSupport.unk_09D4");
static_assert(offsetof(ccBoss08AutoSupport, unk_3940) == 0x3940, "ccBoss08AutoSupport.unk_3940");
static_assert(offsetof(ccBoss08AutoSupport, unk_3AC0) == 0x3AC0, "ccBoss08AutoSupport.unk_3AC0");
static_assert(offsetof(ccBoss08AutoSupport, unk_4680) == 0x4680, "ccBoss08AutoSupport.unk_4680");
static_assert(offsetof(ccBoss08AutoSupport, unk_6500) == 0x6500, "ccBoss08AutoSupport.unk_6500");
static_assert(offsetof(ccBoss08AutoSupport, unk_ACF8) == 0xACF8, "ccBoss08AutoSupport.unk_ACF8");
static_assert(offsetof(ccBoss08AutoSupport, unk_AD78) == 0xAD78, "ccBoss08AutoSupport.unk_AD78");
static_assert(offsetof(ccBoss08AutoSupport, unk_AD7C) == 0xAD7C, "ccBoss08AutoSupport.unk_AD7C");
static_assert(offsetof(ccBoss08AutoSupport, unk_ADA8) == 0xADA8, "ccBoss08AutoSupport.unk_ADA8");
static_assert(offsetof(ccBoss08AutoSupport, unk_AFB8) == 0xAFB8, "ccBoss08AutoSupport.unk_AFB8");
static_assert(offsetof(ccBoss08AutoSupport, unk_AFBC) == 0xAFBC, "ccBoss08AutoSupport.unk_AFBC");

#endif /* S3_BOSS08_H */
