#ifndef S3_BOSS07_H
#define S3_BOSS07_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s3Boss07 - Storm 3 Full Burst HD (NSUNS3.exe) boss battle structs
 * Build: s3 (sha 55b726e94dad)
 * All fields INFERRED from static analysis (state_surface + decomp).
 * Cross-referenced with s2Boss06.h layout patterns.
 */

/* ccBoss0700PlayerBase: Storm 3 boss battle class */
/* Object size 0xAFC8 from allocator (FUN_140683f70) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerBase {
    uint8_t pad_0000[112];                    /* 0x0000 */
    uint8_t      unk_0070                      ; /* 0x0070 low AfterCharacterCollision; CtrlAct_PL_ACT_BOSS_FUNC_05 */
    uint8_t pad_0071[7];                    /* 0x0071 */
    uint64_t     unk_0078                      ; /* 0x0078 low AfterCharacterCollision; CtrlInputPad */
    uint8_t pad_0080[16];                    /* 0x0080 */
    uint8_t      unk_0090                      ; /* 0x0090 low AfterCharacterCollision */
    uint8_t pad_0091[7];                    /* 0x0091 */
    uint64_t     unk_0098                      ; /* 0x0098 medium AfterCharacterCollision */
    uint8_t pad_00A0[20];                    /* 0x00A0 */
    uint64_t     unk_00B4                      ; /* 0x00B4 medium CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t     unk_00BC                      ; /* 0x00BC medium CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t      unk_00C0                      ; /* 0x00C0 low RegisterTask */
    uint8_t pad_00C1[71];                    /* 0x00C1 */
    uint8_t      unk_0108                      ; /* 0x0108 low AfterCharacterCollision */
    uint8_t pad_0109[63];                    /* 0x0109 */
    uint8_t      unk_0148                      ; /* 0x0148 low AfterCharacterCollision */
    uint8_t pad_0149[7];                    /* 0x0149 */
    uint32_t     unk_0150                      ; /* 0x0150 high AfterCharacterCollision */
    uint8_t pad_0154[4];                    /* 0x0154 */
    uint32_t     unk_0158                      ; /* 0x0158 medium OnDamageCleanHit */
    uint32_t     unk_015C                      ; /* 0x015C high AfterCharacterCollision; OnDamageCleanHit */
    uint8_t pad_0160[12];                    /* 0x0160 */
    uint32_t     unk_016C                      ; /* 0x016C medium AfterCharacterCollision */
    uint8_t pad_0170[72];                    /* 0x0170 */
    uint32_t     unk_01B8                      ; /* 0x01B8 low AfterCharacterCollision */
    uint8_t pad_01BC[68];                    /* 0x01BC */
    uint64_t     unk_0200                      ; /* 0x0200 low AfterCharacterCollision; CtrlAct_PL_ACT_BOSS_IA_SIGN */
    uint8_t pad_0208[8];                    /* 0x0208 */
    uint8_t      unk_0210                      ; /* 0x0210 low CtrlInputPad; OnDamageCleanHit */
    uint8_t pad_0211[175];                    /* 0x0211 */
    uint8_t      unk_02C0                      ; /* 0x02C0 low OnDamageCleanHit */
    uint8_t pad_02C1[383];                    /* 0x02C1 */
    uint8_t      unk_0440                      ; /* 0x0440 low MoveToPartnerFB */
    uint8_t pad_0441[63];                    /* 0x0441 */
    uint8_t      unk_0480                      ; /* 0x0480 low CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_0481[695];                    /* 0x0481 */
    uint64_t     unk_0738                      ; /* 0x0738 high OnDamageCleanHit; RegisterTask */
    uint8_t pad_0740[628];                    /* 0x0740 */
    uint32_t     unk_09B4                      ; /* 0x09B4 medium AfterCharacterCollision; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_09B8[28];                    /* 0x09B8 */
    uint32_t     unk_09D4                      ; /* 0x09D4 high AfterCharacterCollision; RecoverSleep */
    uint8_t pad_09D8[4];                    /* 0x09D8 */
    uint32_t     unk_09DC                      ; /* 0x09DC medium AfterCharacterCollision */
    uint8_t pad_09E0[12];                    /* 0x09E0 */
    uint32_t     unk_09EC                      ; /* 0x09EC medium AfterCharacterCollision; CtrlInputPad */
    uint8_t pad_09F0[4];                    /* 0x09F0 */
    uint32_t     unk_09F4                      ; /* 0x09F4 medium PostCtrlImpl */
    uint64_t     unk_09F8                      ; /* 0x09F8 high CtrlAct_PL_ACT_BOSS_FUNC_04; CtrlAct_PL_ACT_BOSS_FUNC_05 */
    uint32_t     unk_0A00                      ; /* 0x0A00 high CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint32_t     unk_0A04                      ; /* 0x0A04 high CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_0A08[12];                    /* 0x0A08 */
    uint32_t     unk_0A14                      ; /* 0x0A14 medium OnDamageCleanHit */
    uint8_t pad_0A18[124];                    /* 0x0A18 */
    uint32_t     unk_0A94                      ; /* 0x0A94 medium OnDamageCleanHit; SetActionRequest */
    uint8_t pad_0A98[528];                    /* 0x0A98 */
    uint64_t     unk_0CA8                      ; /* 0x0CA8 medium CtrlAct_PL_ACT_SUP_DASH_CUT; RegisterTask */
    uint8_t pad_0CB0[60];                    /* 0x0CB0 */
    uint32_t     unk_0CEC                      ; /* 0x0CEC medium AfterCharacterCollision */
    uint8_t pad_0CF0[4];                    /* 0x0CF0 */
    uint32_t     unk_0CF4                      ; /* 0x0CF4 medium RecoverSleep */
    uint8_t pad_0CF8[16];                    /* 0x0CF8 */
    uint64_t     unk_0D08                      ; /* 0x0D08 medium AfterCharacterCollision */
    uint8_t pad_0D10[4];                    /* 0x0D10 */
    uint8_t      unk_0D14                      ; /* 0x0D14 low OnDamageCleanHit */
    uint8_t pad_0D15[8107];                    /* 0x0D15 */
    uint8_t      unk_2CC0                      ; /* 0x2CC0 low OnDamageCleanHit */
    uint8_t pad_2CC1[63];                    /* 0x2CC1 */
    uint8_t      unk_2D00                      ; /* 0x2D00 low OnDamageCleanHit */
    uint8_t pad_2D01[255];                    /* 0x2D01 */
    uint8_t      unk_2E00                      ; /* 0x2E00 low OnDamageCleanHit */
    uint8_t pad_2E01[127];                    /* 0x2E01 */
    uint8_t      unk_2E80                      ; /* 0x2E80 low OnDamageCleanHit */
    uint8_t pad_2E81[63];                    /* 0x2E81 */
    uint8_t      unk_2EC0                      ; /* 0x2EC0 low OnDamageCleanHit */
    uint8_t pad_2EC1[447];                    /* 0x2EC1 */
    uint8_t      unk_3080                      ; /* 0x3080 low CtrlInputPad */
    uint8_t pad_3081[63];                    /* 0x3081 */
    uint8_t      unk_30C0                      ; /* 0x30C0 low CtrlInputPad */
    uint8_t pad_30C1[319];                    /* 0x30C1 */
    uint8_t      unk_3200                      ; /* 0x3200 low OnDamageCleanHit */
    uint8_t pad_3201[575];                    /* 0x3201 */
    uint8_t      unk_3440                      ; /* 0x3440 low AutoExecuteSupportAction; CtrlCounterSimulImpl */
    uint8_t pad_3441[127];                    /* 0x3441 */
    uint8_t      unk_34C0                      ; /* 0x34C0 low OnDamageCleanHit; RegisterTask */
    uint8_t pad_34C1[63];                    /* 0x34C1 */
    uint8_t      unk_3500                      ; /* 0x3500 low RegisterTask */
    uint8_t pad_3501[767];                    /* 0x3501 */
    uint8_t      unk_3800                      ; /* 0x3800 low Reset */
    uint8_t pad_3801[63];                    /* 0x3801 */
    uint8_t      unk_3840                      ; /* 0x3840 low CtrlAct_PL_ACT_BOSS_FUNC_05; RecoverSleep */
    uint8_t pad_3841[63];                    /* 0x3841 */
    uint8_t      unk_3880                      ; /* 0x3880 low CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_3881[191];                    /* 0x3881 */
    uint8_t      unk_3940                      ; /* 0x3940 low CtrlAct_PL_ACT_BOSS_IA_SIGN; CtrlAct_PL_ACT_SUP_EXIT */
    uint8_t pad_3941[63];                    /* 0x3941 */
    uint8_t      unk_3980                      ; /* 0x3980 low CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_3981[63];                    /* 0x3981 */
    uint8_t      unk_39C0                      ; /* 0x39C0 low CtrlAct_PL_ACT_BOSS_FUNC_03; CtrlAct_PL_ACT_BOSS_IA_SIGN */
    uint8_t pad_39C1[255];                    /* 0x39C1 */
    uint8_t      unk_3AC0                      ; /* 0x3AC0 low IsSpSklInvokeOk; OnDamageCleanHit */
    uint8_t pad_3AC1[255];                    /* 0x3AC1 */
    uint8_t      unk_3BC0                      ; /* 0x3BC0 low RecoverSleep */
    uint8_t pad_3BC1[191];                    /* 0x3BC1 */
    uint8_t      unk_3C80                      ; /* 0x3C80 low CtrlAct_PL_ACT_SUP_EXIT; RecoverSleep */
    uint8_t pad_3C81[63];                    /* 0x3C81 */
    uint8_t      unk_3CC0                      ; /* 0x3CC0 low CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_3CC1[1599];                    /* 0x3CC1 */
    uint8_t      unk_4300                      ; /* 0x4300 low AfterCharacterCollision */
    uint8_t pad_4301[63];                    /* 0x4301 */
    uint8_t      unk_4340                      ; /* 0x4340 low OnDamageCleanHit */
    uint8_t pad_4341[63];                    /* 0x4341 */
    uint8_t      unk_4380                      ; /* 0x4380 low OnDamageCleanHit */
    uint8_t pad_4381[63];                    /* 0x4381 */
    uint8_t      unk_43C0                      ; /* 0x43C0 low OnDamageCleanHit */
    uint8_t pad_43C1[191];                    /* 0x43C1 */
    uint8_t      unk_4480                      ; /* 0x4480 low AfterCharacterCollision */
    uint8_t pad_4481[511];                    /* 0x4481 */
    uint8_t      unk_4680                      ; /* 0x4680 low RequestSupportAction_ */
    uint8_t pad_4681[511];                    /* 0x4681 */
    uint8_t      unk_4880                      ; /* 0x4880 low OnDamageCleanHit */
    uint8_t pad_4881[1663];                    /* 0x4881 */
    uint8_t      unk_4F00                      ; /* 0x4F00 low CtrlInputPad */
    uint8_t pad_4F01[191];                    /* 0x4F01 */
    uint8_t      unk_4FC0                      ; /* 0x4FC0 low CtrlInputPad */
    uint8_t pad_4FC1[63];                    /* 0x4FC1 */
    uint8_t      unk_5000                      ; /* 0x5000 low CtrlInputPad */
    uint8_t pad_5001[63];                    /* 0x5001 */
    uint8_t      unk_5040                      ; /* 0x5040 low CtrlInputPad */
    uint8_t pad_5041[191];                    /* 0x5041 */
    uint8_t      unk_5100                      ; /* 0x5100 low CtrlInputPad */
    uint8_t pad_5101[63];                    /* 0x5101 */
    uint8_t      unk_5140                      ; /* 0x5140 low CtrlInputPad */
    uint8_t pad_5141[191];                    /* 0x5141 */
    uint8_t      unk_5200                      ; /* 0x5200 low CtrlInputPad */
    uint8_t pad_5201[447];                    /* 0x5201 */
    uint8_t      unk_53C0                      ; /* 0x53C0 low CtrlInputPad */
    uint8_t pad_53C1[127];                    /* 0x53C1 */
    uint8_t      unk_5440                      ; /* 0x5440 low CtrlInputPad */
    uint8_t pad_5441[1407];                    /* 0x5441 */
    uint8_t      unk_59C0                      ; /* 0x59C0 low OnDamageCleanHit */
    uint8_t pad_59C1[575];                    /* 0x59C1 */
    uint8_t      unk_5C00                      ; /* 0x5C00 low OnDamageCleanHit */
    uint8_t pad_5C01[63];                    /* 0x5C01 */
    uint8_t      unk_5C40                      ; /* 0x5C40 low OnDamageCleanHit */
    uint8_t pad_5C41[511];                    /* 0x5C41 */
    uint8_t      unk_5E40                      ; /* 0x5E40 low CtrlInputPad */
    uint8_t pad_5E41[703];                    /* 0x5E41 */
    uint8_t      unk_6100                      ; /* 0x6100 low OnDamageCleanHit */
    uint8_t pad_6101[511];                    /* 0x6101 */
    uint8_t      unk_6300                      ; /* 0x6300 low OnDamageCleanHit; SetActionRequest */
    uint8_t pad_6301[639];                    /* 0x6301 */
    uint8_t      unk_6580                      ; /* 0x6580 low AutoExecuteSupportAction */
    uint8_t pad_6581[1471];                    /* 0x6581 */
    uint8_t      unk_6B40                      ; /* 0x6B40 low DisableDraw */
    uint8_t pad_6B41[255];                    /* 0x6B41 */
    uint8_t      unk_6C40                      ; /* 0x6C40 low CtrlInputPad */
    uint8_t pad_6C41[895];                    /* 0x6C41 */
    uint8_t      unk_6FC0                      ; /* 0x6FC0 low PostCtrlImpl */
    uint8_t pad_6FC1[4111];                    /* 0x6FC1 */
    uint32_t     unk_7FD0                      ; /* 0x7FD0 medium AfterCharacterCollision */
    uint8_t pad_7FD4[100];                    /* 0x7FD4 */
    uint8_t      unk_8038                      ; /* 0x8038 low OnDamageCleanHit */
    uint8_t pad_8039[15];                    /* 0x8039 */
    uint64_t     unk_8048                      ; /* 0x8048 medium OnDamageCleanHit */
    uint64_t     unk_8050                      ; /* 0x8050 medium OnDamageCleanHit */
    uint8_t pad_8058[8];                    /* 0x8058 */
    uint8_t      unk_8060                      ; /* 0x8060 low OnDamageCleanHit */
    uint8_t pad_8061[7];                    /* 0x8061 */
    uint32_t     unk_8068                      ; /* 0x8068 medium OnDamageCleanHit */
    uint8_t pad_806C[24];                    /* 0x806C */
    uint32_t     unk_8084                      ; /* 0x8084 medium OnDamageCleanHit */
    uint8_t pad_8088[24];                    /* 0x8088 */
    uint64_t     unk_80A0                      ; /* 0x80A0 medium OnDamageCleanHit */
    uint64_t     unk_80A8                      ; /* 0x80A8 medium OnDamageCleanHit */
    uint64_t     unk_80B0                      ; /* 0x80B0 medium OnDamageCleanHit */
    uint32_t     unk_80B8                      ; /* 0x80B8 medium OnDamageCleanHit */
    uint32_t     unk_80BC                      ; /* 0x80BC medium OnDamageCleanHit */
    uint8_t pad_80C0[32];                    /* 0x80C0 */
    uint64_t     unk_80E0                      ; /* 0x80E0 medium OnDamageCleanHit */
    uint8_t pad_80E8[260];                    /* 0x80E8 */
    uint32_t     unk_81EC                      ; /* 0x81EC medium CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint64_t     unk_81F0                      ; /* 0x81F0 medium CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_81F8[32];                    /* 0x81F8 */
    uint32_t     unk_8218                      ; /* 0x8218 high RecoverSleep; Reset */
    uint8_t pad_821C[64];                    /* 0x821C */
    uint32_t     unk_825C                      ; /* 0x825C medium CtrlInputPad */
    uint8_t pad_8260[16];                    /* 0x8260 */
    uint8_t      unk_8270                      ; /* 0x8270 low CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_8271[7815];                    /* 0x8271 */
    uint64_t     unk_A0F8                      ; /* 0xA0F8 medium OnDamageCleanHit */
    uint8_t pad_A100[12];                    /* 0xA100 */
    uint64_t     unk_A10C                      ; /* 0xA10C low AfterCharacterCollision */
    uint32_t     unk_A114                      ; /* 0xA114 high AfterCharacterCollision */
    uint8_t pad_A118[456];                    /* 0xA118 */
    uint64_t     unk_A2E0                      ; /* 0xA2E0 medium AfterCharacterCollision */
    uint8_t pad_A2E8[4];                    /* 0xA2E8 */
    uint32_t     unk_A2EC                      ; /* 0xA2EC medium AfterCharacterCollision */
    uint32_t     unk_A2F0                      ; /* 0xA2F0 medium AfterCharacterCollision */
    uint64_t     unk_A2F4                      ; /* 0xA2F4 medium AfterCharacterCollision */
    uint32_t     unk_A2FC                      ; /* 0xA2FC medium AfterCharacterCollision */
    uint64_t     unk_A300                      ; /* 0xA300 medium AfterCharacterCollision */
    uint32_t     unk_A308                      ; /* 0xA308 medium AfterCharacterCollision */
    uint32_t     unk_A30C                      ; /* 0xA30C medium AfterCharacterCollision */
    uint8_t pad_A310[4];                    /* 0xA310 */
    uint32_t     unk_A314                      ; /* 0xA314 high AfterCharacterCollision; CtrlInputPad */
    uint8_t pad_A318[2016];                    /* 0xA318 */
    uint64_t     unk_AAF8                      ; /* 0xAAF8 medium PostCtrlImpl */
    uint32_t     unk_AB00                      ; /* 0xAB00 medium PostCtrlImpl */
    uint8_t pad_AB04[188];                    /* 0xAB04 */
    uint64_t     unk_ABC0                      ; /* 0xABC0 medium AfterCharacterCollision */
    uint8_t pad_ABC8[24];                    /* 0xABC8 */
    uint64_t     unk_ABE0                      ; /* 0xABE0 medium OnDamageCleanHit; RecoverSleep */
    uint8_t pad_ABE8[272];                    /* 0xABE8 */
    uint8_t      unk_ACF8                      ; /* 0xACF8 low RequestSupportAction_ */
    uint8_t pad_ACF9[127];                    /* 0xACF9 */
    uint64_t     unk_AD78                      ; /* 0xAD78 high RequestSupportAction_ */
    uint8_t pad_AD80[40];                    /* 0xAD80 */
    uint32_t     unk_ADA8                      ; /* 0xADA8 medium RequestSupportAction_ */
    uint8_t pad_ADAC[68];                    /* 0xADAC */
    uint64_t     unk_ADF0                      ; /* 0xADF0 high AutoExecuteSupportAction; CtrlCounterSimulImpl */
    uint8_t pad_ADF8[40];                    /* 0xADF8 */
    uint32_t     unk_AE20                      ; /* 0xAE20 medium CtrlAct_PL_ACT_SUP_EXIT */
    uint8_t pad_AE24[160];                    /* 0xAE24 */
    uint32_t     unk_AEC4                      ; /* 0xAEC4 medium DisableDraw */
    uint8_t pad_AEC8[24];                    /* 0xAEC8 */
    uint32_t     unk_AEE0                      ; /* 0xAEE0 medium ccBoss0700PlayerBase */
    uint8_t pad_AEE4[164];                    /* 0xAEE4 */
    uint64_t     unk_AF88                      ; /* 0xAF88 medium CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_AF90[40];                    /* 0xAF90 */
    uint64_t     unk_AFB8                      ; /* 0xAFB8 high CtrlAct_PL_ACT_BOSS_IA_SIGN; OnDamageCleanHit */
    uint32_t     unk_AFC0                      ; /* 0xAFC0 medium ccBoss0700PlayerBase */
    uint8_t pad_AFC4[4];                    /* 0xAFC4 to 0xAFC8 */
} ccBoss0700PlayerBase;
#pragma pack(pop)

static_assert(sizeof(ccBoss0700PlayerBase) == 0xAFC8, "ccBoss0700PlayerBase size mismatch");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0070) == 0x70, "ccBoss0700PlayerBase.unk_0070 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0078) == 0x78, "ccBoss0700PlayerBase.unk_0078 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0090) == 0x90, "ccBoss0700PlayerBase.unk_0090 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0098) == 0x98, "ccBoss0700PlayerBase.unk_0098 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_00B4) == 0xB4, "ccBoss0700PlayerBase.unk_00B4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_00BC) == 0xBC, "ccBoss0700PlayerBase.unk_00BC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_00C0) == 0xC0, "ccBoss0700PlayerBase.unk_00C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0108) == 0x108, "ccBoss0700PlayerBase.unk_0108 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0148) == 0x148, "ccBoss0700PlayerBase.unk_0148 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0150) == 0x150, "ccBoss0700PlayerBase.unk_0150 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0158) == 0x158, "ccBoss0700PlayerBase.unk_0158 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_015C) == 0x15C, "ccBoss0700PlayerBase.unk_015C offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_016C) == 0x16C, "ccBoss0700PlayerBase.unk_016C offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_01B8) == 0x1B8, "ccBoss0700PlayerBase.unk_01B8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0200) == 0x200, "ccBoss0700PlayerBase.unk_0200 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0210) == 0x210, "ccBoss0700PlayerBase.unk_0210 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_02C0) == 0x2C0, "ccBoss0700PlayerBase.unk_02C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0440) == 0x440, "ccBoss0700PlayerBase.unk_0440 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0480) == 0x480, "ccBoss0700PlayerBase.unk_0480 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0738) == 0x738, "ccBoss0700PlayerBase.unk_0738 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_09B4) == 0x9B4, "ccBoss0700PlayerBase.unk_09B4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_09D4) == 0x9D4, "ccBoss0700PlayerBase.unk_09D4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_09DC) == 0x9DC, "ccBoss0700PlayerBase.unk_09DC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_09EC) == 0x9EC, "ccBoss0700PlayerBase.unk_09EC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_09F4) == 0x9F4, "ccBoss0700PlayerBase.unk_09F4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_09F8) == 0x9F8, "ccBoss0700PlayerBase.unk_09F8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0A00) == 0xA00, "ccBoss0700PlayerBase.unk_0A00 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0A04) == 0xA04, "ccBoss0700PlayerBase.unk_0A04 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0A14) == 0xA14, "ccBoss0700PlayerBase.unk_0A14 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0A94) == 0xA94, "ccBoss0700PlayerBase.unk_0A94 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0CA8) == 0xCA8, "ccBoss0700PlayerBase.unk_0CA8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0CEC) == 0xCEC, "ccBoss0700PlayerBase.unk_0CEC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0CF4) == 0xCF4, "ccBoss0700PlayerBase.unk_0CF4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0D08) == 0xD08, "ccBoss0700PlayerBase.unk_0D08 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_0D14) == 0xD14, "ccBoss0700PlayerBase.unk_0D14 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_2CC0) == 0x2CC0, "ccBoss0700PlayerBase.unk_2CC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_2D00) == 0x2D00, "ccBoss0700PlayerBase.unk_2D00 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_2E00) == 0x2E00, "ccBoss0700PlayerBase.unk_2E00 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_2E80) == 0x2E80, "ccBoss0700PlayerBase.unk_2E80 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_2EC0) == 0x2EC0, "ccBoss0700PlayerBase.unk_2EC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3080) == 0x3080, "ccBoss0700PlayerBase.unk_3080 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_30C0) == 0x30C0, "ccBoss0700PlayerBase.unk_30C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3200) == 0x3200, "ccBoss0700PlayerBase.unk_3200 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3440) == 0x3440, "ccBoss0700PlayerBase.unk_3440 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_34C0) == 0x34C0, "ccBoss0700PlayerBase.unk_34C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3500) == 0x3500, "ccBoss0700PlayerBase.unk_3500 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3800) == 0x3800, "ccBoss0700PlayerBase.unk_3800 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3840) == 0x3840, "ccBoss0700PlayerBase.unk_3840 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3880) == 0x3880, "ccBoss0700PlayerBase.unk_3880 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3940) == 0x3940, "ccBoss0700PlayerBase.unk_3940 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3980) == 0x3980, "ccBoss0700PlayerBase.unk_3980 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_39C0) == 0x39C0, "ccBoss0700PlayerBase.unk_39C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3AC0) == 0x3AC0, "ccBoss0700PlayerBase.unk_3AC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3BC0) == 0x3BC0, "ccBoss0700PlayerBase.unk_3BC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3C80) == 0x3C80, "ccBoss0700PlayerBase.unk_3C80 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_3CC0) == 0x3CC0, "ccBoss0700PlayerBase.unk_3CC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4300) == 0x4300, "ccBoss0700PlayerBase.unk_4300 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4340) == 0x4340, "ccBoss0700PlayerBase.unk_4340 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4380) == 0x4380, "ccBoss0700PlayerBase.unk_4380 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_43C0) == 0x43C0, "ccBoss0700PlayerBase.unk_43C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4480) == 0x4480, "ccBoss0700PlayerBase.unk_4480 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4680) == 0x4680, "ccBoss0700PlayerBase.unk_4680 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4880) == 0x4880, "ccBoss0700PlayerBase.unk_4880 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4F00) == 0x4F00, "ccBoss0700PlayerBase.unk_4F00 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_4FC0) == 0x4FC0, "ccBoss0700PlayerBase.unk_4FC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5000) == 0x5000, "ccBoss0700PlayerBase.unk_5000 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5040) == 0x5040, "ccBoss0700PlayerBase.unk_5040 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5100) == 0x5100, "ccBoss0700PlayerBase.unk_5100 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5140) == 0x5140, "ccBoss0700PlayerBase.unk_5140 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5200) == 0x5200, "ccBoss0700PlayerBase.unk_5200 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_53C0) == 0x53C0, "ccBoss0700PlayerBase.unk_53C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5440) == 0x5440, "ccBoss0700PlayerBase.unk_5440 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_59C0) == 0x59C0, "ccBoss0700PlayerBase.unk_59C0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5C00) == 0x5C00, "ccBoss0700PlayerBase.unk_5C00 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5C40) == 0x5C40, "ccBoss0700PlayerBase.unk_5C40 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_5E40) == 0x5E40, "ccBoss0700PlayerBase.unk_5E40 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_6100) == 0x6100, "ccBoss0700PlayerBase.unk_6100 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_6300) == 0x6300, "ccBoss0700PlayerBase.unk_6300 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_6580) == 0x6580, "ccBoss0700PlayerBase.unk_6580 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_6B40) == 0x6B40, "ccBoss0700PlayerBase.unk_6B40 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_6C40) == 0x6C40, "ccBoss0700PlayerBase.unk_6C40 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_6FC0) == 0x6FC0, "ccBoss0700PlayerBase.unk_6FC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_7FD0) == 0x7FD0, "ccBoss0700PlayerBase.unk_7FD0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8038) == 0x8038, "ccBoss0700PlayerBase.unk_8038 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8048) == 0x8048, "ccBoss0700PlayerBase.unk_8048 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8050) == 0x8050, "ccBoss0700PlayerBase.unk_8050 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8060) == 0x8060, "ccBoss0700PlayerBase.unk_8060 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8068) == 0x8068, "ccBoss0700PlayerBase.unk_8068 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8084) == 0x8084, "ccBoss0700PlayerBase.unk_8084 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_80A0) == 0x80A0, "ccBoss0700PlayerBase.unk_80A0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_80A8) == 0x80A8, "ccBoss0700PlayerBase.unk_80A8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_80B0) == 0x80B0, "ccBoss0700PlayerBase.unk_80B0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_80B8) == 0x80B8, "ccBoss0700PlayerBase.unk_80B8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_80BC) == 0x80BC, "ccBoss0700PlayerBase.unk_80BC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_80E0) == 0x80E0, "ccBoss0700PlayerBase.unk_80E0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_81EC) == 0x81EC, "ccBoss0700PlayerBase.unk_81EC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_81F0) == 0x81F0, "ccBoss0700PlayerBase.unk_81F0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8218) == 0x8218, "ccBoss0700PlayerBase.unk_8218 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_825C) == 0x825C, "ccBoss0700PlayerBase.unk_825C offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_8270) == 0x8270, "ccBoss0700PlayerBase.unk_8270 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A0F8) == 0xA0F8, "ccBoss0700PlayerBase.unk_A0F8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A10C) == 0xA10C, "ccBoss0700PlayerBase.unk_A10C offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A114) == 0xA114, "ccBoss0700PlayerBase.unk_A114 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A2E0) == 0xA2E0, "ccBoss0700PlayerBase.unk_A2E0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A2EC) == 0xA2EC, "ccBoss0700PlayerBase.unk_A2EC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A2F0) == 0xA2F0, "ccBoss0700PlayerBase.unk_A2F0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A2F4) == 0xA2F4, "ccBoss0700PlayerBase.unk_A2F4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A2FC) == 0xA2FC, "ccBoss0700PlayerBase.unk_A2FC offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A300) == 0xA300, "ccBoss0700PlayerBase.unk_A300 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A308) == 0xA308, "ccBoss0700PlayerBase.unk_A308 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A30C) == 0xA30C, "ccBoss0700PlayerBase.unk_A30C offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_A314) == 0xA314, "ccBoss0700PlayerBase.unk_A314 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AAF8) == 0xAAF8, "ccBoss0700PlayerBase.unk_AAF8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AB00) == 0xAB00, "ccBoss0700PlayerBase.unk_AB00 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_ABC0) == 0xABC0, "ccBoss0700PlayerBase.unk_ABC0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_ABE0) == 0xABE0, "ccBoss0700PlayerBase.unk_ABE0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_ACF8) == 0xACF8, "ccBoss0700PlayerBase.unk_ACF8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AD78) == 0xAD78, "ccBoss0700PlayerBase.unk_AD78 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_ADA8) == 0xADA8, "ccBoss0700PlayerBase.unk_ADA8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_ADF0) == 0xADF0, "ccBoss0700PlayerBase.unk_ADF0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AE20) == 0xAE20, "ccBoss0700PlayerBase.unk_AE20 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AEC4) == 0xAEC4, "ccBoss0700PlayerBase.unk_AEC4 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AEE0) == 0xAEE0, "ccBoss0700PlayerBase.unk_AEE0 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AF88) == 0xAF88, "ccBoss0700PlayerBase.unk_AF88 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AFB8) == 0xAFB8, "ccBoss0700PlayerBase.unk_AFB8 offset");
static_assert(offsetof(ccBoss0700PlayerBase, unk_AFC0) == 0xAFC0, "ccBoss0700PlayerBase.unk_AFC0 offset");

/* ccBoss0700SequenceBase: Storm 3 boss battle class */
/* Size unknown, >= 0x90 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700SequenceBase {
    uint8_t pad_0000[84];                    /* 0x0000 */
    uint32_t     unk_0054                      ; /* 0x0054 medium ccBoss0700SequenceBase */
    uint64_t     unk_0058                      ; /* 0x0058 medium ccBoss0700SequenceBase */
    uint32_t     unk_0060                      ; /* 0x0060 medium ccBoss0700SequenceBase */
    uint8_t pad_0064[4];                    /* 0x0064 */
    uint64_t     unk_0068                      ; /* 0x0068 medium ccBoss0700SequenceBase */
    uint64_t     unk_0070                      ; /* 0x0070 medium ccBoss0700SequenceBase */
    uint64_t     unk_0078                      ; /* 0x0078 medium ccBoss0700SequenceBase */
    uint32_t     unk_0080                      ; /* 0x0080 medium ccBoss0700SequenceBase */
    uint8_t pad_0084[4];                    /* 0x0084 */
    uint64_t     unk_0088                      ; /* 0x0088 medium ccBoss0700SequenceBase */
} ccBoss0700SequenceBase;
#pragma pack(pop)

static_assert(offsetof(ccBoss0700SequenceBase, unk_0054) == 0x54, "ccBoss0700SequenceBase.unk_0054 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0058) == 0x58, "ccBoss0700SequenceBase.unk_0058 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0060) == 0x60, "ccBoss0700SequenceBase.unk_0060 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0068) == 0x68, "ccBoss0700SequenceBase.unk_0068 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0070) == 0x70, "ccBoss0700SequenceBase.unk_0070 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0078) == 0x78, "ccBoss0700SequenceBase.unk_0078 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0080) == 0x80, "ccBoss0700SequenceBase.unk_0080 offset");
static_assert(offsetof(ccBoss0700SequenceBase, unk_0088) == 0x88, "ccBoss0700SequenceBase.unk_0088 offset");

/* ccBoss0710: Storm 3 boss battle class */
/* Size unknown, >= 0x318 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0710 {
    uint8_t pad_0000[152];                    /* 0x0000 */
    uint8_t      unk_0098                      ; /* 0x0098 low ccBoss0710 */
    uint8_t pad_0099[39];                    /* 0x0099 */
    uint8_t      unk_00C0                      ; /* 0x00C0 low _Initialize */
    uint8_t pad_00C1[55];                    /* 0x00C1 */
    uint64_t     unk_00F8                      ; /* 0x00F8 medium ccBoss0710 */
    uint64_t     unk_0100                      ; /* 0x0100 low _Initialize; ccBoss0710 */
    uint64_t     unk_0108                      ; /* 0x0108 medium ccBoss0710 */
    uint64_t     unk_0110                      ; /* 0x0110 medium ccBoss0710 */
    uint64_t     unk_0118                      ; /* 0x0118 medium ccBoss0710 */
    uint32_t     unk_0120                      ; /* 0x0120 medium ccBoss0710 */
    uint32_t     unk_0124                      ; /* 0x0124 medium ccBoss0710 */
    uint32_t     unk_0128                      ; /* 0x0128 medium ccBoss0710 */
    uint8_t pad_012C[4];                    /* 0x012C */
    uint32_t     unk_0130                      ; /* 0x0130 medium ccBoss0710 */
    uint32_t     unk_0134                      ; /* 0x0134 medium ccBoss0710 */
    uint8_t      unk_0138                      ; /* 0x0138 low ccBoss0710 */
    uint8_t pad_0139[119];                    /* 0x0139 */
    uint32_t     unk_01B0                      ; /* 0x01B0 medium ccBoss0710 */
    uint32_t     unk_01B4                      ; /* 0x01B4 medium ccBoss0710 */
    uint32_t     unk_01B8                      ; /* 0x01B8 medium ccBoss0710 */
    uint32_t     unk_01BC                      ; /* 0x01BC medium ccBoss0710 */
    uint8_t pad_01C0[200];                    /* 0x01C0 */
    uint8_t      unk_0288                      ; /* 0x0288 low _Initialize */
    uint8_t pad_0289[111];                    /* 0x0289 */
    uint32_t     unk_02F8                      ; /* 0x02F8 medium _Initialize */
    uint32_t     unk_02FC                      ; /* 0x02FC medium _Initialize */
    uint64_t     unk_0300                      ; /* 0x0300 medium _Initialize */
    uint8_t pad_0308[8];                    /* 0x0308 */
    uint64_t     unk_0310                      ; /* 0x0310 low _Initialize */
} ccBoss0710;
#pragma pack(pop)

static_assert(offsetof(ccBoss0710, unk_0098) == 0x98, "ccBoss0710.unk_0098 offset");
static_assert(offsetof(ccBoss0710, unk_00C0) == 0xC0, "ccBoss0710.unk_00C0 offset");
static_assert(offsetof(ccBoss0710, unk_00F8) == 0xF8, "ccBoss0710.unk_00F8 offset");
static_assert(offsetof(ccBoss0710, unk_0100) == 0x100, "ccBoss0710.unk_0100 offset");
static_assert(offsetof(ccBoss0710, unk_0108) == 0x108, "ccBoss0710.unk_0108 offset");
static_assert(offsetof(ccBoss0710, unk_0110) == 0x110, "ccBoss0710.unk_0110 offset");
static_assert(offsetof(ccBoss0710, unk_0118) == 0x118, "ccBoss0710.unk_0118 offset");
static_assert(offsetof(ccBoss0710, unk_0120) == 0x120, "ccBoss0710.unk_0120 offset");
static_assert(offsetof(ccBoss0710, unk_0124) == 0x124, "ccBoss0710.unk_0124 offset");
static_assert(offsetof(ccBoss0710, unk_0128) == 0x128, "ccBoss0710.unk_0128 offset");
static_assert(offsetof(ccBoss0710, unk_0130) == 0x130, "ccBoss0710.unk_0130 offset");
static_assert(offsetof(ccBoss0710, unk_0134) == 0x134, "ccBoss0710.unk_0134 offset");
static_assert(offsetof(ccBoss0710, unk_0138) == 0x138, "ccBoss0710.unk_0138 offset");
static_assert(offsetof(ccBoss0710, unk_01B0) == 0x1B0, "ccBoss0710.unk_01B0 offset");
static_assert(offsetof(ccBoss0710, unk_01B4) == 0x1B4, "ccBoss0710.unk_01B4 offset");
static_assert(offsetof(ccBoss0710, unk_01B8) == 0x1B8, "ccBoss0710.unk_01B8 offset");
static_assert(offsetof(ccBoss0710, unk_01BC) == 0x1BC, "ccBoss0710.unk_01BC offset");
static_assert(offsetof(ccBoss0710, unk_0288) == 0x288, "ccBoss0710.unk_0288 offset");
static_assert(offsetof(ccBoss0710, unk_02F8) == 0x2F8, "ccBoss0710.unk_02F8 offset");
static_assert(offsetof(ccBoss0710, unk_02FC) == 0x2FC, "ccBoss0710.unk_02FC offset");
static_assert(offsetof(ccBoss0710, unk_0300) == 0x300, "ccBoss0710.unk_0300 offset");
static_assert(offsetof(ccBoss0710, unk_0310) == 0x310, "ccBoss0710.unk_0310 offset");

/* ccBoss0720: Storm 3 boss battle class */
/* Size unknown, >= 0x43C (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720 {
    uint8_t pad_0000[344];                    /* 0x0000 */
    uint8_t      unk_0158                      ; /* 0x0158 low ~ccBoss0720 */
    uint8_t pad_0159[167];                    /* 0x0159 */
    uint8_t      unk_0200                      ; /* 0x0200 low ~ccBoss0720 */
    uint8_t pad_0201[127];                    /* 0x0201 */
    uint8_t      unk_0280                      ; /* 0x0280 low ~ccBoss0720 */
    uint8_t pad_0281[7];                    /* 0x0281 */
    uint8_t      unk_0288                      ; /* 0x0288 low ccBoss0720 */
    uint8_t pad_0289[95];                    /* 0x0289 */
    uint64_t     unk_02E8                      ; /* 0x02E8 medium ccBoss0720 */
    uint64_t     unk_02F0                      ; /* 0x02F0 medium ccBoss0720 */
    uint32_t     unk_02F8                      ; /* 0x02F8 medium ccBoss0720 */
    uint32_t     unk_02FC                      ; /* 0x02FC medium ccBoss0720 */
    uint64_t     unk_0300                      ; /* 0x0300 medium ccBoss0720 */
    uint64_t     unk_0308                      ; /* 0x0308 medium ccBoss0720 */
    uint8_t      unk_0310                      ; /* 0x0310 low ccBoss0720 */
    uint8_t pad_0311[55];                    /* 0x0311 */
    uint64_t     unk_0348                      ; /* 0x0348 medium ccBoss0720 */
    uint32_t     unk_0350                      ; /* 0x0350 medium ccBoss0720 */
    uint8_t pad_0354[4];                    /* 0x0354 */
    uint8_t      unk_0358                      ; /* 0x0358 low ccBoss0720 */
    uint8_t pad_0359[223];                    /* 0x0359 */
    uint32_t     unk_0438                      ; /* 0x0438 medium ccBoss0720 */
} ccBoss0720;
#pragma pack(pop)

static_assert(offsetof(ccBoss0720, unk_0158) == 0x158, "ccBoss0720.unk_0158 offset");
static_assert(offsetof(ccBoss0720, unk_0200) == 0x200, "ccBoss0720.unk_0200 offset");
static_assert(offsetof(ccBoss0720, unk_0280) == 0x280, "ccBoss0720.unk_0280 offset");
static_assert(offsetof(ccBoss0720, unk_0288) == 0x288, "ccBoss0720.unk_0288 offset");
static_assert(offsetof(ccBoss0720, unk_02E8) == 0x2E8, "ccBoss0720.unk_02E8 offset");
static_assert(offsetof(ccBoss0720, unk_02F0) == 0x2F0, "ccBoss0720.unk_02F0 offset");
static_assert(offsetof(ccBoss0720, unk_02F8) == 0x2F8, "ccBoss0720.unk_02F8 offset");
static_assert(offsetof(ccBoss0720, unk_02FC) == 0x2FC, "ccBoss0720.unk_02FC offset");
static_assert(offsetof(ccBoss0720, unk_0300) == 0x300, "ccBoss0720.unk_0300 offset");
static_assert(offsetof(ccBoss0720, unk_0308) == 0x308, "ccBoss0720.unk_0308 offset");
static_assert(offsetof(ccBoss0720, unk_0310) == 0x310, "ccBoss0720.unk_0310 offset");
static_assert(offsetof(ccBoss0720, unk_0348) == 0x348, "ccBoss0720.unk_0348 offset");
static_assert(offsetof(ccBoss0720, unk_0350) == 0x350, "ccBoss0720.unk_0350 offset");
static_assert(offsetof(ccBoss0720, unk_0358) == 0x358, "ccBoss0720.unk_0358 offset");
static_assert(offsetof(ccBoss0720, unk_0438) == 0x438, "ccBoss0720.unk_0438 offset");

/* ccBoss07BaseCharacter: Storm 3 boss battle class */
/* Object size 0xAFC8 from allocator (FUN_140683f70) */
#pragma pack(push, 1)
typedef struct ccBoss07BaseCharacter {
    uint8_t pad_0000[17536];                    /* 0x0000 */
    uint8_t      unk_4480                      ; /* 0x4480 low SetCpuThinkEscape */
    uint8_t pad_4481[27447];                    /* 0x4481 */
    uint8_t      unk_AFB8                      ; /* 0xAFB8 low ccBoss07BaseCharacter */
    uint8_t pad_AFB9[11];                    /* 0xAFB9 */
    uint8_t      unk_AFC4                      ; /* 0xAFC4 low ccBoss07BaseCharacter */
    uint8_t pad_AFC5[3];                    /* 0xAFC5 to 0xAFC8 */
} ccBoss07BaseCharacter;
#pragma pack(pop)

static_assert(sizeof(ccBoss07BaseCharacter) == 0xAFC8, "ccBoss07BaseCharacter size mismatch");
static_assert(offsetof(ccBoss07BaseCharacter, unk_4480) == 0x4480, "ccBoss07BaseCharacter.unk_4480 offset");
static_assert(offsetof(ccBoss07BaseCharacter, unk_AFB8) == 0xAFB8, "ccBoss07BaseCharacter.unk_AFB8 offset");
static_assert(offsetof(ccBoss07BaseCharacter, unk_AFC4) == 0xAFC4, "ccBoss07BaseCharacter.unk_AFC4 offset");

/* ccBoss07HugeCharacter: Storm 3 boss battle class */
/* Object size 0xB020 from allocator (FUN_140683f70) */
#pragma pack(push, 1)
typedef struct ccBoss07HugeCharacter {
    uint8_t pad_0000[328];                    /* 0x0000 */
    uint8_t      unk_0148                      ; /* 0x0148 low PostCtrlImpl */
    uint8_t pad_0149[15];                    /* 0x0149 */
    uint32_t     unk_0158                      ; /* 0x0158 medium CtrlAct_PL_ACT_BOSS_FUNC_05 */
    uint8_t pad_015C[160];                    /* 0x015C */
    uint32_t     unk_01FC                      ; /* 0x01FC medium Create */
    uint64_t     unk_0200                      ; /* 0x0200 low CtrlAct_PL_ACT_BOSS_FUNC_02; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_0208[568];                    /* 0x0208 */
    uint8_t      unk_0440                      ; /* 0x0440 low PostCtrlImpl */
    uint8_t pad_0441[63];                    /* 0x0441 */
    uint8_t      unk_0480                      ; /* 0x0480 low CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_0481[1371];                    /* 0x0481 */
    uint32_t     unk_09DC                      ; /* 0x09DC medium IsEnableLockOn */
    uint8_t pad_09E0[12];                    /* 0x09E0 */
    uint32_t     unk_09EC                      ; /* 0x09EC medium IsEnableLockOn; PostCtrlImpl */
    uint8_t pad_09F0[12];                    /* 0x09F0 */
    uint32_t     unk_09FC                      ; /* 0x09FC medium CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_02 */
    uint8_t pad_0A00[11328];                    /* 0x0A00 */
    uint8_t      unk_3640                      ; /* 0x3640 low Awake */
    uint8_t pad_3641[63];                    /* 0x3641 */
    uint8_t      unk_3680                      ; /* 0x3680 low Sleep */
    uint8_t pad_3681[383];                    /* 0x3681 */
    uint8_t      unk_3800                      ; /* 0x3800 low Awake */
    uint8_t pad_3801[63];                    /* 0x3801 */
    uint8_t      unk_3840                      ; /* 0x3840 low Awake */
    uint8_t pad_3841[63];                    /* 0x3841 */
    uint8_t      unk_3880                      ; /* 0x3880 low Create; Sleep */
    uint8_t pad_3881[191];                    /* 0x3881 */
    uint8_t      unk_3940                      ; /* 0x3940 low ActionExit; CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t pad_3941[127];                    /* 0x3941 */
    uint8_t      unk_39C0                      ; /* 0x39C0 low CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t pad_39C1[255];                    /* 0x39C1 */
    uint8_t      unk_3AC0                      ; /* 0x3AC0 low IsEnableLockOn; PreCtrlImpl */
    uint8_t pad_3AC1[255];                    /* 0x3AC1 */
    uint8_t      unk_3BC0                      ; /* 0x3BC0 low CtrlAct_PL_ACT_BOSS_FUNC_02 */
    uint8_t pad_3BC1[63];                    /* 0x3BC1 */
    uint8_t      unk_3C00                      ; /* 0x3C00 low Create; CtrlAct_PL_ACT_BOSS_FUNC_02 */
    uint8_t pad_3C01[127];                    /* 0x3C01 */
    uint8_t      unk_3C80                      ; /* 0x3C80 low CtrlAct_PL_ACT_BOSS_FUNC_02 */
    uint8_t pad_3C81[63];                    /* 0x3C81 */
    uint8_t      unk_3CC0                      ; /* 0x3CC0 low Create; CtrlAct_PL_ACT_BOSS_FUNC_02 */
    uint8_t pad_3CC1[13183];                    /* 0x3CC1 */
    uint8_t      unk_7040                      ; /* 0x7040 low CtrlAct_PL_ACT_BOSS_FUNC_00; CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint8_t pad_7041[63];                    /* 0x7041 */
    uint8_t      unk_7080                      ; /* 0x7080 low CtrlAct_PL_ACT_BOSS_FUNC_06 */
    uint8_t pad_7081[4459];                    /* 0x7081 */
    uint32_t     unk_81EC                      ; /* 0x81EC medium Create */
    uint8_t pad_81F0[8380];                    /* 0x81F0 */
    uint32_t     unk_A2AC                      ; /* 0xA2AC medium Create */
    uint8_t pad_A2B0[3336];                    /* 0xA2B0 */
    uint64_t     unk_AFB8                      ; /* 0xAFB8 low CtrlAct_PL_ACT_BOSS_FUNC_02; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint32_t     unk_AFC0                      ; /* 0xAFC0 medium CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t      unk_AFC4                      ; /* 0xAFC4 low CtrlAct_PL_ACT_BOSS_FUNC_02; CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_AFC5[15];                    /* 0xAFC5 */
    uint32_t     unk_AFD4                      ; /* 0xAFD4 medium PreCtrlImpl */
    uint8_t      unk_AFD8                      ; /* 0xAFD8 low ccBoss07HugeCharacter */
    uint8_t pad_AFD9[71];                    /* 0xAFD9 to 0xB020 */
} ccBoss07HugeCharacter;
#pragma pack(pop)

static_assert(sizeof(ccBoss07HugeCharacter) == 0xB020, "ccBoss07HugeCharacter size mismatch");
static_assert(offsetof(ccBoss07HugeCharacter, unk_0148) == 0x148, "ccBoss07HugeCharacter.unk_0148 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_0158) == 0x158, "ccBoss07HugeCharacter.unk_0158 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_01FC) == 0x1FC, "ccBoss07HugeCharacter.unk_01FC offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_0200) == 0x200, "ccBoss07HugeCharacter.unk_0200 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_0440) == 0x440, "ccBoss07HugeCharacter.unk_0440 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_0480) == 0x480, "ccBoss07HugeCharacter.unk_0480 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_09DC) == 0x9DC, "ccBoss07HugeCharacter.unk_09DC offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_09EC) == 0x9EC, "ccBoss07HugeCharacter.unk_09EC offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_09FC) == 0x9FC, "ccBoss07HugeCharacter.unk_09FC offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3640) == 0x3640, "ccBoss07HugeCharacter.unk_3640 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3680) == 0x3680, "ccBoss07HugeCharacter.unk_3680 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3800) == 0x3800, "ccBoss07HugeCharacter.unk_3800 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3840) == 0x3840, "ccBoss07HugeCharacter.unk_3840 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3880) == 0x3880, "ccBoss07HugeCharacter.unk_3880 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3940) == 0x3940, "ccBoss07HugeCharacter.unk_3940 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_39C0) == 0x39C0, "ccBoss07HugeCharacter.unk_39C0 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3AC0) == 0x3AC0, "ccBoss07HugeCharacter.unk_3AC0 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3BC0) == 0x3BC0, "ccBoss07HugeCharacter.unk_3BC0 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3C00) == 0x3C00, "ccBoss07HugeCharacter.unk_3C00 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3C80) == 0x3C80, "ccBoss07HugeCharacter.unk_3C80 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_3CC0) == 0x3CC0, "ccBoss07HugeCharacter.unk_3CC0 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_7040) == 0x7040, "ccBoss07HugeCharacter.unk_7040 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_7080) == 0x7080, "ccBoss07HugeCharacter.unk_7080 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_81EC) == 0x81EC, "ccBoss07HugeCharacter.unk_81EC offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_A2AC) == 0xA2AC, "ccBoss07HugeCharacter.unk_A2AC offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_AFB8) == 0xAFB8, "ccBoss07HugeCharacter.unk_AFB8 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_AFC0) == 0xAFC0, "ccBoss07HugeCharacter.unk_AFC0 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_AFC4) == 0xAFC4, "ccBoss07HugeCharacter.unk_AFC4 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_AFD4) == 0xAFD4, "ccBoss07HugeCharacter.unk_AFD4 offset");
static_assert(offsetof(ccBoss07HugeCharacter, unk_AFD8) == 0xAFD8, "ccBoss07HugeCharacter.unk_AFD8 offset");

/* ccBoss07QTE: Storm 3 boss battle class */
/* Size unknown, >= 0xD0 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss07QTE {
    uint8_t pad_0000[84];                    /* 0x0000 */
    uint32_t     unk_0054                      ; /* 0x0054 medium ccBoss07QTE */
    uint32_t     unk_0058                      ; /* 0x0058 medium ccBoss07QTE */
    uint32_t     unk_005C                      ; /* 0x005C medium ccBoss07QTE */
    uint32_t     unk_0060                      ; /* 0x0060 medium ccBoss07QTE */
    uint8_t pad_0064[4];                    /* 0x0064 */
    uint32_t     unk_0068                      ; /* 0x0068 medium ccBoss07QTE */
    uint32_t     unk_006C                      ; /* 0x006C medium ccBoss07QTE */
    uint64_t     unk_0070                      ; /* 0x0070 medium ccBoss07QTE */
    uint32_t     unk_0078                      ; /* 0x0078 medium ccBoss07QTE */
    uint8_t pad_007C[4];                    /* 0x007C */
    uint64_t     unk_0080                      ; /* 0x0080 medium ccBoss07QTE */
    uint8_t      unk_0088                      ; /* 0x0088 low ccBoss07QTE */
    uint8_t pad_0089[39];                    /* 0x0089 */
    uint8_t      unk_00B0                      ; /* 0x00B0 low ccBoss07QTE */
    uint8_t pad_00B1[7];                    /* 0x00B1 */
    uint64_t     unk_00B8                      ; /* 0x00B8 medium ccBoss07QTE */
    uint64_t     unk_00C0                      ; /* 0x00C0 medium ccBoss07QTE */
    uint64_t     unk_00C8                      ; /* 0x00C8 low ccBoss07QTE */
} ccBoss07QTE;
#pragma pack(pop)

static_assert(offsetof(ccBoss07QTE, unk_0054) == 0x54, "ccBoss07QTE.unk_0054 offset");
static_assert(offsetof(ccBoss07QTE, unk_0058) == 0x58, "ccBoss07QTE.unk_0058 offset");
static_assert(offsetof(ccBoss07QTE, unk_005C) == 0x5C, "ccBoss07QTE.unk_005C offset");
static_assert(offsetof(ccBoss07QTE, unk_0060) == 0x60, "ccBoss07QTE.unk_0060 offset");
static_assert(offsetof(ccBoss07QTE, unk_0068) == 0x68, "ccBoss07QTE.unk_0068 offset");
static_assert(offsetof(ccBoss07QTE, unk_006C) == 0x6C, "ccBoss07QTE.unk_006C offset");
static_assert(offsetof(ccBoss07QTE, unk_0070) == 0x70, "ccBoss07QTE.unk_0070 offset");
static_assert(offsetof(ccBoss07QTE, unk_0078) == 0x78, "ccBoss07QTE.unk_0078 offset");
static_assert(offsetof(ccBoss07QTE, unk_0080) == 0x80, "ccBoss07QTE.unk_0080 offset");
static_assert(offsetof(ccBoss07QTE, unk_0088) == 0x88, "ccBoss07QTE.unk_0088 offset");
static_assert(offsetof(ccBoss07QTE, unk_00B0) == 0xB0, "ccBoss07QTE.unk_00B0 offset");
static_assert(offsetof(ccBoss07QTE, unk_00B8) == 0xB8, "ccBoss07QTE.unk_00B8 offset");
static_assert(offsetof(ccBoss07QTE, unk_00C0) == 0xC0, "ccBoss07QTE.unk_00C0 offset");
static_assert(offsetof(ccBoss07QTE, unk_00C8) == 0xC8, "ccBoss07QTE.unk_00C8 offset");



/* ccBoss0710Sequence: Storm 3 boss battle class */
/* Size unknown, >= 0x79 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0710Sequence {
    uint8_t pad_0000[120];                  /* 0x0000 */
    uint8_t      unk_0078                   ; /* 0x0078 inferred ccBoss0710Sequence */
} ccBoss0710Sequence;
#pragma pack(pop)

/* ccBoss0720Sequence: Storm 3 boss battle class */
/* Size unknown, >= 0x1F9 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720Sequence {
    uint8_t pad_0000[84];                   /* 0x0000 */
    uint32_t     unk_0054                   ; /* 0x0054 inferred ccBoss0720Sequence */
    uint32_t     unk_0058                   ; /* 0x0058 inferred ccBoss0720Sequence */
    uint32_t     unk_005C                   ; /* 0x005C inferred ccBoss0720Sequence */
    uint32_t     unk_0060                   ; /* 0x0060 inferred ccBoss0720Sequence */
    uint8_t pad_0064[4];                    /* 0x0064 */
    uint32_t     unk_0068                   ; /* 0x0068 inferred ccBoss0720Sequence */
    uint32_t     unk_006C                   ; /* 0x006C inferred ccBoss0720Sequence */
    uint64_t     unk_0070                   ; /* 0x0070 inferred ccBoss0720Sequence */
    uint64_t     unk_0078                   ; /* 0x0078 inferred ccBoss0720Sequence */
    uint64_t     unk_0080                   ; /* 0x0080 inferred ccBoss0720Sequence */
    uint64_t     unk_0088                   ; /* 0x0088 inferred ccBoss0720Sequence */
    uint64_t     unk_0090                   ; /* 0x0090 inferred ccBoss0720Sequence */
    uint8_t pad_0098[16];                   /* 0x0098 */
    uint32_t     unk_00A8                   ; /* 0x00A8 inferred ccBoss0720Sequence */
    uint32_t     unk_00AC                   ; /* 0x00AC inferred ccBoss0720Sequence */
    uint64_t     unk_00B0                   ; /* 0x00B0 inferred ccBoss0720Sequence */
    uint8_t pad_00B8[64];                   /* 0x00B8 */
    uint8_t      unk_00F8                   ; /* 0x00F8 inferred ccBoss0720Sequence */
    uint8_t pad_00F9[255];                  /* 0x00F9 */
    uint8_t      unk_01F8                   ; /* 0x01F8 inferred ccBoss0720Sequence */
} ccBoss0720Sequence;
#pragma pack(pop)

/* ccBoss0700PlayerNRT: Storm 3 boss battle class */
/* Size unknown, >= 0xAFC8 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerNRT {
    uint8_t pad_0000[344];                  /* 0x0000 */
    uint32_t     unk_0158                   ; /* 0x0158 inferred ccBoss0700PlayerNRT */
    uint8_t pad_015C[164];                  /* 0x015C */
    uint8_t      unk_0200                   ; /* 0x0200 inferred ccBoss0700PlayerNRT */
    uint8_t pad_0201[15];                   /* 0x0201 */
    uint8_t      unk_0210                   ; /* 0x0210 inferred ccBoss0700PlayerNRT */
    uint8_t pad_0211[1955];                 /* 0x0211 */
    uint32_t     unk_09B4                   ; /* 0x09B4 inferred ccBoss0700PlayerNRT */
    uint8_t pad_09B8[4];                    /* 0x09B8 */
    uint32_t     unk_09BC                   ; /* 0x09BC inferred ccBoss0700PlayerNRT */
    uint8_t pad_09C0[24];                   /* 0x09C0 */
    uint32_t     unk_09D8                   ; /* 0x09D8 inferred ccBoss0700PlayerNRT */
    uint8_t pad_09DC[32];                   /* 0x09DC */
    uint32_t     unk_09FC                   ; /* 0x09FC inferred ccBoss0700PlayerNRT */
    uint8_t pad_0A00[680];                  /* 0x0A00 */
    uint64_t     unk_0CA8                   ; /* 0x0CA8 inferred ccBoss0700PlayerNRT */
    uint8_t pad_0CB0[84];                   /* 0x0CB0 */
    uint32_t     unk_0D04                   ; /* 0x0D04 inferred ccBoss0700PlayerNRT */
    uint8_t pad_0D08[11064];                /* 0x0D08 */
    uint8_t      unk_3840                   ; /* 0x3840 inferred ccBoss0700PlayerNRT */
    uint8_t pad_3841[63];                   /* 0x3841 */
    uint8_t      unk_3880                   ; /* 0x3880 inferred ccBoss0700PlayerNRT */
    uint8_t pad_3881[127];                  /* 0x3881 */
    uint8_t      unk_3900                   ; /* 0x3900 inferred ccBoss0700PlayerNRT */
    uint8_t pad_3901[63];                   /* 0x3901 */
    uint8_t      unk_3940                   ; /* 0x3940 inferred ccBoss0700PlayerNRT */
    uint8_t pad_3941[319];                  /* 0x3941 */
    uint8_t      unk_3A80                   ; /* 0x3A80 inferred ccBoss0700PlayerNRT */
    uint8_t pad_3A81[63];                   /* 0x3A81 */
    uint8_t      unk_3AC0                   ; /* 0x3AC0 inferred ccBoss0700PlayerNRT */
    uint8_t pad_3AC1[2431];                 /* 0x3AC1 */
    uint8_t      unk_4440                   ; /* 0x4440 inferred ccBoss0700PlayerNRT */
    uint8_t pad_4441[7871];                 /* 0x4441 */
    uint8_t      unk_6300                   ; /* 0x6300 inferred ccBoss0700PlayerNRT */
    uint8_t pad_6301[7919];                 /* 0x6301 */
    uint64_t     unk_81F0                   ; /* 0x81F0 inferred ccBoss0700PlayerNRT */
    uint8_t pad_81F8[10520];                /* 0x81F8 */
    uint32_t     unk_AB10                   ; /* 0xAB10 inferred ccBoss0700PlayerNRT */
    uint8_t pad_AB14[184];                  /* 0xAB14 */
    uint32_t     unk_ABCC                   ; /* 0xABCC inferred ccBoss0700PlayerNRT */
    uint64_t     unk_ABD0                   ; /* 0xABD0 inferred ccBoss0700PlayerNRT */
    uint32_t     unk_ABD8                   ; /* 0xABD8 inferred ccBoss0700PlayerNRT */
    uint8_t pad_ABDC[4];                    /* 0xABDC */
    uint64_t     unk_ABE0                   ; /* 0xABE0 inferred ccBoss0700PlayerNRT */
    uint8_t pad_ABE8[756];                  /* 0xABE8 */
    uint32_t     unk_AEDC                   ; /* 0xAEDC inferred ccBoss0700PlayerNRT */
    uint8_t pad_AEE0[4];                    /* 0xAEE0 */
    uint32_t     unk_AEE4                   ; /* 0xAEE4 inferred ccBoss0700PlayerNRT */
    uint8_t pad_AEE8[12];                   /* 0xAEE8 */
    uint32_t     unk_AEF4                   ; /* 0xAEF4 inferred ccBoss0700PlayerNRT */
    uint32_t     unk_AEF8                   ; /* 0xAEF8 inferred ccBoss0700PlayerNRT */
    uint32_t     unk_AEFC                   ; /* 0xAEFC inferred ccBoss0700PlayerNRT */
    uint8_t pad_AF00[184];                  /* 0xAF00 */
    uint64_t     unk_AFB8                   ; /* 0xAFB8 inferred ccBoss0700PlayerNRT */
    uint32_t     unk_AFC0                   ; /* 0xAFC0 inferred ccBoss0700PlayerNRT */
    uint32_t     unk_AFC4                   ; /* 0xAFC4 inferred ccBoss0700PlayerNRT */
} ccBoss0700PlayerNRT;
#pragma pack(pop)

/* ccBoss0720CharacterNRT: Storm 3 boss battle class */
/* Size unknown, >= 0xAFCC (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720CharacterNRT {
    uint8_t pad_0000[180];                  /* 0x0000 */
    uint8_t      unk_00B4                   ; /* 0x00B4 inferred ccBoss0720CharacterNRT */
    uint8_t pad_00B5[331];                  /* 0x00B5 */
    uint64_t     unk_0200                   ; /* 0x0200 inferred ccBoss0720CharacterNRT */
    uint8_t pad_0208[632];                  /* 0x0208 */
    uint8_t      unk_0480                   ; /* 0x0480 inferred ccBoss0720CharacterNRT */
    uint8_t pad_0481[13503];                /* 0x0481 */
    uint8_t      unk_3940                   ; /* 0x3940 inferred ccBoss0720CharacterNRT */
    uint8_t pad_3941[383];                  /* 0x3941 */
    uint8_t      unk_3AC0                   ; /* 0x3AC0 inferred ccBoss0720CharacterNRT */
    uint8_t pad_3AC1[319];                  /* 0x3AC1 */
    uint8_t      unk_3C00                   ; /* 0x3C00 inferred ccBoss0720CharacterNRT */
    uint8_t pad_3C01[2559];                 /* 0x3C01 */
    uint8_t      unk_4600                   ; /* 0x4600 inferred ccBoss0720CharacterNRT */
    uint8_t pad_4601[15019];                /* 0x4601 */
    uint32_t     unk_80AC                   ; /* 0x80AC inferred ccBoss0720CharacterNRT */
    uint8_t pad_80B0[204];                  /* 0x80B0 */
    uint32_t     unk_817C                   ; /* 0x817C inferred ccBoss0720CharacterNRT */
    uint8_t pad_8180[108];                  /* 0x8180 */
    uint32_t     unk_81EC                   ; /* 0x81EC inferred ccBoss0720CharacterNRT */
    uint64_t     unk_81F0                   ; /* 0x81F0 inferred ccBoss0720CharacterNRT */
    uint8_t pad_81F8[8232];                 /* 0x81F8 */
    uint32_t     unk_A220                   ; /* 0xA220 inferred ccBoss0720CharacterNRT */
    uint8_t pad_A224[136];                  /* 0xA224 */
    uint32_t     unk_A2AC                   ; /* 0xA2AC inferred ccBoss0720CharacterNRT */
    uint8_t pad_A2B0[100];                  /* 0xA2B0 */
    uint32_t     unk_A314                   ; /* 0xA314 inferred ccBoss0720CharacterNRT */
    uint8_t pad_A318[3232];                 /* 0xA318 */
    uint64_t     unk_AFB8                   ; /* 0xAFB8 inferred ccBoss0720CharacterNRT */
    uint32_t     unk_AFC0                   ; /* 0xAFC0 inferred ccBoss0720CharacterNRT */
    uint32_t     unk_AFC4                   ; /* 0xAFC4 inferred ccBoss0720CharacterNRT */
    uint32_t     unk_AFC8                   ; /* 0xAFC8 inferred ccBoss0720CharacterNRT */
} ccBoss0720CharacterNRT;
#pragma pack(pop)

/* ccBoss0700PlayerNYG: Storm 3 boss battle class */
/* Size unknown, >= 0xB019 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerNYG {
    uint8_t pad_0000[180];                  /* 0x0000 */
    uint64_t     unk_00B4                   ; /* 0x00B4 inferred ccBoss0700PlayerNYG */
    uint32_t     unk_00BC                   ; /* 0x00BC inferred ccBoss0700PlayerNYG */
    uint8_t pad_00C0[320];                  /* 0x00C0 */
    uint64_t     unk_0200                   ; /* 0x0200 inferred ccBoss0700PlayerNYG */
    uint8_t pad_0208[184];                  /* 0x0208 */
    uint8_t      unk_02C0                   ; /* 0x02C0 inferred ccBoss0700PlayerNYG */
    uint8_t pad_02C1[255];                  /* 0x02C1 */
    uint8_t      unk_03C0                   ; /* 0x03C0 inferred ccBoss0700PlayerNYG */
    uint8_t pad_03C1[1527];                 /* 0x03C1 */
    uint64_t     unk_09B8                   ; /* 0x09B8 inferred ccBoss0700PlayerNYG */
    uint8_t pad_09C0[56];                   /* 0x09C0 */
    uint32_t     unk_09F8                   ; /* 0x09F8 inferred ccBoss0700PlayerNYG */
    uint32_t     unk_09FC                   ; /* 0x09FC inferred ccBoss0700PlayerNYG */
    uint32_t     unk_0A00                   ; /* 0x0A00 inferred ccBoss0700PlayerNYG */
    uint32_t     unk_0A04                   ; /* 0x0A04 inferred ccBoss0700PlayerNYG */
    uint8_t pad_0A08[12152];                /* 0x0A08 */
    uint8_t      unk_3980                   ; /* 0x3980 inferred ccBoss0700PlayerNYG */
    uint8_t pad_3981[18539];                /* 0x3981 */
    uint32_t     unk_81EC                   ; /* 0x81EC inferred ccBoss0700PlayerNYG */
    uint64_t     unk_81F0                   ; /* 0x81F0 inferred ccBoss0700PlayerNYG */
    uint8_t pad_81F8[116];                  /* 0x81F8 */
    uint32_t     unk_826C                   ; /* 0x826C inferred ccBoss0700PlayerNYG */
    uint8_t pad_8270[20];                   /* 0x8270 */
    uint32_t     unk_8284                   ; /* 0x8284 inferred ccBoss0700PlayerNYG */
    uint8_t pad_8288[180];                  /* 0x8288 */
    uint32_t     unk_833C                   ; /* 0x833C inferred ccBoss0700PlayerNYG */
    uint8_t pad_8340[7608];                 /* 0x8340 */
    uint64_t     unk_A0F8                   ; /* 0xA0F8 inferred ccBoss0700PlayerNYG */
    uint8_t pad_A100[2784];                 /* 0xA100 */
    uint64_t     unk_ABE0                   ; /* 0xABE0 inferred ccBoss0700PlayerNYG */
    uint8_t pad_ABE8[1000];                 /* 0xABE8 */
    uint32_t     unk_AFD0                   ; /* 0xAFD0 inferred ccBoss0700PlayerNYG */
    uint8_t pad_AFD4[28];                   /* 0xAFD4 */
    uint32_t     unk_AFF0                   ; /* 0xAFF0 inferred ccBoss0700PlayerNYG */
    uint64_t     unk_AFF4                   ; /* 0xAFF4 inferred ccBoss0700PlayerNYG */
    uint32_t     unk_AFFC                   ; /* 0xAFFC inferred ccBoss0700PlayerNYG */
    uint8_t pad_B000[4];                    /* 0xB000 */
    uint32_t     unk_B004                   ; /* 0xB004 inferred ccBoss0700PlayerNYG */
    uint32_t     unk_B008                   ; /* 0xB008 inferred ccBoss0700PlayerNYG */
    uint64_t     unk_B00C                   ; /* 0xB00C inferred ccBoss0700PlayerNYG */
    uint32_t     unk_B014                   ; /* 0xB014 inferred ccBoss0700PlayerNYG */
    uint8_t      unk_B018                   ; /* 0xB018 inferred ccBoss0700PlayerNYG */
} ccBoss0700PlayerNYG;
#pragma pack(pop)

/* ccBoss0700SkillRUS: Storm 3 boss battle class */
/* Size unknown, >= 0xD1 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700SkillRUS {
    uint8_t pad_0000[160];                  /* 0x0000 */
    uint32_t     unk_00A0                   ; /* 0x00A0 inferred ccBoss0700SkillRUS */
    uint8_t pad_00A4[4];                    /* 0x00A4 */
    uint64_t     unk_00A8                   ; /* 0x00A8 inferred ccBoss0700SkillRUS */
    uint8_t      unk_00B0                   ; /* 0x00B0 inferred ccBoss0700SkillRUS */
    uint8_t pad_00B1[11];                   /* 0x00B1 */
    uint32_t     unk_00BC                   ; /* 0x00BC inferred ccBoss0700SkillRUS */
    uint32_t     unk_00C0                   ; /* 0x00C0 inferred ccBoss0700SkillRUS */
    uint32_t     unk_00C4                   ; /* 0x00C4 inferred ccBoss0700SkillRUS */
    uint32_t     unk_00C8                   ; /* 0x00C8 inferred ccBoss0700SkillRUS */
    uint8_t pad_00CC[4];                    /* 0x00CC */
    uint8_t      unk_00D0                   ; /* 0x00D0 inferred ccBoss0700SkillRUS */
} ccBoss0700SkillRUS;
#pragma pack(pop)

/* ccBoss0720CharacterHAN: Storm 3 boss battle class */
/* Size unknown, >= 0xB14C (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720CharacterHAN {
    uint8_t pad_0000[180];                  /* 0x0000 */
    uint8_t      unk_00B4                   ; /* 0x00B4 inferred ccBoss0720CharacterHAN */
    uint8_t pad_00B5[163];                  /* 0x00B5 */
    uint32_t     unk_0158                   ; /* 0x0158 inferred ccBoss0720CharacterHAN */
    uint8_t pad_015C[160];                  /* 0x015C */
    uint32_t     unk_01FC                   ; /* 0x01FC inferred ccBoss0720CharacterHAN */
    uint64_t     unk_0200                   ; /* 0x0200 inferred ccBoss0720CharacterHAN */
    uint8_t pad_0208[632];                  /* 0x0208 */
    uint8_t      unk_0480                   ; /* 0x0480 inferred ccBoss0720CharacterHAN */
    uint8_t pad_0481[1403];                 /* 0x0481 */
    uint32_t     unk_09FC                   ; /* 0x09FC inferred ccBoss0720CharacterHAN */
    uint8_t pad_0A00[12096];                /* 0x0A00 */
    uint8_t      unk_3940                   ; /* 0x3940 inferred ccBoss0720CharacterHAN */
    uint8_t pad_3941[17311];                /* 0x3941 */
    uint8_t      unk_7CE0                   ; /* 0x7CE0 inferred ccBoss0720CharacterHAN */
    uint8_t pad_7CE1[1295];                 /* 0x7CE1 */
    uint64_t     unk_81F0                   ; /* 0x81F0 inferred ccBoss0720CharacterHAN */
    uint8_t pad_81F8[8072];                 /* 0x81F8 */
    uint64_t     unk_A180                   ; /* 0xA180 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A188                   ; /* 0xA188 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A190                   ; /* 0xA190 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A198                   ; /* 0xA198 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A1A0                   ; /* 0xA1A0 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A1A8                   ; /* 0xA1A8 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A1B0                   ; /* 0xA1B0 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_A1B8                   ; /* 0xA1B8 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1C0                   ; /* 0xA1C0 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1C4                   ; /* 0xA1C4 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1C8                   ; /* 0xA1C8 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1CC                   ; /* 0xA1CC inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1D0                   ; /* 0xA1D0 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1D4                   ; /* 0xA1D4 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1D8                   ; /* 0xA1D8 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_A1DC                   ; /* 0xA1DC inferred ccBoss0720CharacterHAN */
    uint8_t pad_A1E0[72];                   /* 0xA1E0 */
    uint8_t      unk_A228                   ; /* 0xA228 inferred ccBoss0720CharacterHAN */
    uint8_t pad_A229[235];                  /* 0xA229 */
    uint32_t     unk_A314                   ; /* 0xA314 inferred ccBoss0720CharacterHAN */
    uint8_t pad_A318[3464];                 /* 0xA318 */
    uint64_t     unk_B0A0                   ; /* 0xB0A0 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_B0A8                   ; /* 0xB0A8 inferred ccBoss0720CharacterHAN */
    uint8_t pad_B0AC[132];                  /* 0xB0AC */
    uint32_t     unk_B130                   ; /* 0xB130 inferred ccBoss0720CharacterHAN */
    uint8_t pad_B134[4];                    /* 0xB134 */
    uint64_t     unk_B138                   ; /* 0xB138 inferred ccBoss0720CharacterHAN */
    uint64_t     unk_B140                   ; /* 0xB140 inferred ccBoss0720CharacterHAN */
    uint32_t     unk_B148                   ; /* 0xB148 inferred ccBoss0720CharacterHAN */
} ccBoss0720CharacterHAN;
#pragma pack(pop)

/* ccSceneBoss0730: Storm 3 boss battle class */
/* Size unknown, >= 0x47C (last field end) */
#pragma pack(push, 1)
typedef struct ccSceneBoss0730 {
    uint8_t pad_0000[760];                  /* 0x0000 */
    uint64_t     unk_02F8                   ; /* 0x02F8 inferred ccSceneBoss0730 */
    uint8_t      unk_0300                   ; /* 0x0300 inferred ccSceneBoss0730 */
    uint8_t pad_0301[239];                  /* 0x0301 */
    uint8_t      unk_03F0                   ; /* 0x03F0 inferred ccSceneBoss0730 */
    uint8_t pad_03F1[135];                  /* 0x03F1 */
    uint32_t     unk_0478                   ; /* 0x0478 inferred ccSceneBoss0730 */
} ccSceneBoss0730;
#pragma pack(pop)

static_assert(offsetof(ccBoss0710Sequence, unk_0078) == 0x78, "ccBoss0710Sequence.unk_0078 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0054) == 0x54, "ccBoss0720Sequence.unk_0054 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0058) == 0x58, "ccBoss0720Sequence.unk_0058 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_005C) == 0x5C, "ccBoss0720Sequence.unk_005C offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0060) == 0x60, "ccBoss0720Sequence.unk_0060 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0068) == 0x68, "ccBoss0720Sequence.unk_0068 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_006C) == 0x6C, "ccBoss0720Sequence.unk_006C offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0070) == 0x70, "ccBoss0720Sequence.unk_0070 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0078) == 0x78, "ccBoss0720Sequence.unk_0078 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0080) == 0x80, "ccBoss0720Sequence.unk_0080 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0088) == 0x88, "ccBoss0720Sequence.unk_0088 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_0090) == 0x90, "ccBoss0720Sequence.unk_0090 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_00A8) == 0xA8, "ccBoss0720Sequence.unk_00A8 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_00AC) == 0xAC, "ccBoss0720Sequence.unk_00AC offset");
static_assert(offsetof(ccBoss0720Sequence, unk_00B0) == 0xB0, "ccBoss0720Sequence.unk_00B0 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_00F8) == 0xF8, "ccBoss0720Sequence.unk_00F8 offset");
static_assert(offsetof(ccBoss0720Sequence, unk_01F8) == 0x1F8, "ccBoss0720Sequence.unk_01F8 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_0158) == 0x158, "ccBoss0700PlayerNRT.unk_0158 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_0200) == 0x200, "ccBoss0700PlayerNRT.unk_0200 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_0210) == 0x210, "ccBoss0700PlayerNRT.unk_0210 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_09B4) == 0x9B4, "ccBoss0700PlayerNRT.unk_09B4 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_09BC) == 0x9BC, "ccBoss0700PlayerNRT.unk_09BC offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_09D8) == 0x9D8, "ccBoss0700PlayerNRT.unk_09D8 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_09FC) == 0x9FC, "ccBoss0700PlayerNRT.unk_09FC offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_0CA8) == 0xCA8, "ccBoss0700PlayerNRT.unk_0CA8 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_0D04) == 0xD04, "ccBoss0700PlayerNRT.unk_0D04 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_3840) == 0x3840, "ccBoss0700PlayerNRT.unk_3840 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_3880) == 0x3880, "ccBoss0700PlayerNRT.unk_3880 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_3900) == 0x3900, "ccBoss0700PlayerNRT.unk_3900 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_3940) == 0x3940, "ccBoss0700PlayerNRT.unk_3940 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_3A80) == 0x3A80, "ccBoss0700PlayerNRT.unk_3A80 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_3AC0) == 0x3AC0, "ccBoss0700PlayerNRT.unk_3AC0 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_4440) == 0x4440, "ccBoss0700PlayerNRT.unk_4440 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_6300) == 0x6300, "ccBoss0700PlayerNRT.unk_6300 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_81F0) == 0x81F0, "ccBoss0700PlayerNRT.unk_81F0 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AB10) == 0xAB10, "ccBoss0700PlayerNRT.unk_AB10 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_ABCC) == 0xABCC, "ccBoss0700PlayerNRT.unk_ABCC offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_ABD0) == 0xABD0, "ccBoss0700PlayerNRT.unk_ABD0 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_ABD8) == 0xABD8, "ccBoss0700PlayerNRT.unk_ABD8 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_ABE0) == 0xABE0, "ccBoss0700PlayerNRT.unk_ABE0 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AEDC) == 0xAEDC, "ccBoss0700PlayerNRT.unk_AEDC offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AEE4) == 0xAEE4, "ccBoss0700PlayerNRT.unk_AEE4 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AEF4) == 0xAEF4, "ccBoss0700PlayerNRT.unk_AEF4 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AEF8) == 0xAEF8, "ccBoss0700PlayerNRT.unk_AEF8 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AEFC) == 0xAEFC, "ccBoss0700PlayerNRT.unk_AEFC offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AFB8) == 0xAFB8, "ccBoss0700PlayerNRT.unk_AFB8 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AFC0) == 0xAFC0, "ccBoss0700PlayerNRT.unk_AFC0 offset");
static_assert(offsetof(ccBoss0700PlayerNRT, unk_AFC4) == 0xAFC4, "ccBoss0700PlayerNRT.unk_AFC4 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_00B4) == 0xB4, "ccBoss0720CharacterNRT.unk_00B4 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_0200) == 0x200, "ccBoss0720CharacterNRT.unk_0200 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_0480) == 0x480, "ccBoss0720CharacterNRT.unk_0480 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_3940) == 0x3940, "ccBoss0720CharacterNRT.unk_3940 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_3AC0) == 0x3AC0, "ccBoss0720CharacterNRT.unk_3AC0 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_3C00) == 0x3C00, "ccBoss0720CharacterNRT.unk_3C00 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_4600) == 0x4600, "ccBoss0720CharacterNRT.unk_4600 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_80AC) == 0x80AC, "ccBoss0720CharacterNRT.unk_80AC offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_817C) == 0x817C, "ccBoss0720CharacterNRT.unk_817C offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_81EC) == 0x81EC, "ccBoss0720CharacterNRT.unk_81EC offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_81F0) == 0x81F0, "ccBoss0720CharacterNRT.unk_81F0 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_A220) == 0xA220, "ccBoss0720CharacterNRT.unk_A220 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_A2AC) == 0xA2AC, "ccBoss0720CharacterNRT.unk_A2AC offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_A314) == 0xA314, "ccBoss0720CharacterNRT.unk_A314 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_AFB8) == 0xAFB8, "ccBoss0720CharacterNRT.unk_AFB8 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_AFC0) == 0xAFC0, "ccBoss0720CharacterNRT.unk_AFC0 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_AFC4) == 0xAFC4, "ccBoss0720CharacterNRT.unk_AFC4 offset");
static_assert(offsetof(ccBoss0720CharacterNRT, unk_AFC8) == 0xAFC8, "ccBoss0720CharacterNRT.unk_AFC8 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_00B4) == 0xB4, "ccBoss0700PlayerNYG.unk_00B4 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_00BC) == 0xBC, "ccBoss0700PlayerNYG.unk_00BC offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_0200) == 0x200, "ccBoss0700PlayerNYG.unk_0200 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_02C0) == 0x2C0, "ccBoss0700PlayerNYG.unk_02C0 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_03C0) == 0x3C0, "ccBoss0700PlayerNYG.unk_03C0 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_09B8) == 0x9B8, "ccBoss0700PlayerNYG.unk_09B8 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_09F8) == 0x9F8, "ccBoss0700PlayerNYG.unk_09F8 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_09FC) == 0x9FC, "ccBoss0700PlayerNYG.unk_09FC offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_0A00) == 0xA00, "ccBoss0700PlayerNYG.unk_0A00 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_0A04) == 0xA04, "ccBoss0700PlayerNYG.unk_0A04 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_3980) == 0x3980, "ccBoss0700PlayerNYG.unk_3980 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_81EC) == 0x81EC, "ccBoss0700PlayerNYG.unk_81EC offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_81F0) == 0x81F0, "ccBoss0700PlayerNYG.unk_81F0 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_826C) == 0x826C, "ccBoss0700PlayerNYG.unk_826C offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_8284) == 0x8284, "ccBoss0700PlayerNYG.unk_8284 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_833C) == 0x833C, "ccBoss0700PlayerNYG.unk_833C offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_A0F8) == 0xA0F8, "ccBoss0700PlayerNYG.unk_A0F8 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_ABE0) == 0xABE0, "ccBoss0700PlayerNYG.unk_ABE0 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_AFD0) == 0xAFD0, "ccBoss0700PlayerNYG.unk_AFD0 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_AFF0) == 0xAFF0, "ccBoss0700PlayerNYG.unk_AFF0 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_AFF4) == 0xAFF4, "ccBoss0700PlayerNYG.unk_AFF4 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_AFFC) == 0xAFFC, "ccBoss0700PlayerNYG.unk_AFFC offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_B004) == 0xB004, "ccBoss0700PlayerNYG.unk_B004 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_B008) == 0xB008, "ccBoss0700PlayerNYG.unk_B008 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_B00C) == 0xB00C, "ccBoss0700PlayerNYG.unk_B00C offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_B014) == 0xB014, "ccBoss0700PlayerNYG.unk_B014 offset");
static_assert(offsetof(ccBoss0700PlayerNYG, unk_B018) == 0xB018, "ccBoss0700PlayerNYG.unk_B018 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00A0) == 0xA0, "ccBoss0700SkillRUS.unk_00A0 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00A8) == 0xA8, "ccBoss0700SkillRUS.unk_00A8 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00B0) == 0xB0, "ccBoss0700SkillRUS.unk_00B0 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00BC) == 0xBC, "ccBoss0700SkillRUS.unk_00BC offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00C0) == 0xC0, "ccBoss0700SkillRUS.unk_00C0 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00C4) == 0xC4, "ccBoss0700SkillRUS.unk_00C4 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00C8) == 0xC8, "ccBoss0700SkillRUS.unk_00C8 offset");
static_assert(offsetof(ccBoss0700SkillRUS, unk_00D0) == 0xD0, "ccBoss0700SkillRUS.unk_00D0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_00B4) == 0xB4, "ccBoss0720CharacterHAN.unk_00B4 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_0158) == 0x158, "ccBoss0720CharacterHAN.unk_0158 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_01FC) == 0x1FC, "ccBoss0720CharacterHAN.unk_01FC offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_0200) == 0x200, "ccBoss0720CharacterHAN.unk_0200 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_0480) == 0x480, "ccBoss0720CharacterHAN.unk_0480 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_09FC) == 0x9FC, "ccBoss0720CharacterHAN.unk_09FC offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_3940) == 0x3940, "ccBoss0720CharacterHAN.unk_3940 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_7CE0) == 0x7CE0, "ccBoss0720CharacterHAN.unk_7CE0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_81F0) == 0x81F0, "ccBoss0720CharacterHAN.unk_81F0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A180) == 0xA180, "ccBoss0720CharacterHAN.unk_A180 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A188) == 0xA188, "ccBoss0720CharacterHAN.unk_A188 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A190) == 0xA190, "ccBoss0720CharacterHAN.unk_A190 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A198) == 0xA198, "ccBoss0720CharacterHAN.unk_A198 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1A0) == 0xA1A0, "ccBoss0720CharacterHAN.unk_A1A0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1A8) == 0xA1A8, "ccBoss0720CharacterHAN.unk_A1A8 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1B0) == 0xA1B0, "ccBoss0720CharacterHAN.unk_A1B0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1B8) == 0xA1B8, "ccBoss0720CharacterHAN.unk_A1B8 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1C0) == 0xA1C0, "ccBoss0720CharacterHAN.unk_A1C0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1C4) == 0xA1C4, "ccBoss0720CharacterHAN.unk_A1C4 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1C8) == 0xA1C8, "ccBoss0720CharacterHAN.unk_A1C8 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1CC) == 0xA1CC, "ccBoss0720CharacterHAN.unk_A1CC offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1D0) == 0xA1D0, "ccBoss0720CharacterHAN.unk_A1D0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1D4) == 0xA1D4, "ccBoss0720CharacterHAN.unk_A1D4 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1D8) == 0xA1D8, "ccBoss0720CharacterHAN.unk_A1D8 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A1DC) == 0xA1DC, "ccBoss0720CharacterHAN.unk_A1DC offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A228) == 0xA228, "ccBoss0720CharacterHAN.unk_A228 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_A314) == 0xA314, "ccBoss0720CharacterHAN.unk_A314 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_B0A0) == 0xB0A0, "ccBoss0720CharacterHAN.unk_B0A0 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_B0A8) == 0xB0A8, "ccBoss0720CharacterHAN.unk_B0A8 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_B130) == 0xB130, "ccBoss0720CharacterHAN.unk_B130 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_B138) == 0xB138, "ccBoss0720CharacterHAN.unk_B138 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_B140) == 0xB140, "ccBoss0720CharacterHAN.unk_B140 offset");
static_assert(offsetof(ccBoss0720CharacterHAN, unk_B148) == 0xB148, "ccBoss0720CharacterHAN.unk_B148 offset");
static_assert(offsetof(ccSceneBoss0730, unk_02F8) == 0x2F8, "ccSceneBoss0730.unk_02F8 offset");
static_assert(offsetof(ccSceneBoss0730, unk_0300) == 0x300, "ccSceneBoss0730.unk_0300 offset");
static_assert(offsetof(ccSceneBoss0730, unk_03F0) == 0x3F0, "ccSceneBoss0730.unk_03F0 offset");
static_assert(offsetof(ccSceneBoss0730, unk_0478) == 0x478, "ccSceneBoss0730.unk_0478 offset");


/* ccBoss0700PlayerRUS: Storm 3 boss battle class */
/* Size unknown, >= 0xB000 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerRUS {
    uint8_t pad_0000[180];                     /* 0x0000 */
    uint8_t    unk_00B4                 ; /* 0x00B4 inferred ccBoss0700PlayerRUS */
    uint8_t pad_00B5[331];                     /* 0x00B5 */
    uint64_t   unk_0200                 ; /* 0x0200 inferred ccBoss0700PlayerRUS */
    uint8_t pad_0208[184];                     /* 0x0208 */
    uint8_t    unk_02C0                 ; /* 0x02C0 inferred ccBoss0700PlayerRUS */
    uint8_t pad_02C1[1783];                    /* 0x02C1 */
    uint64_t   unk_09B8                 ; /* 0x09B8 inferred ccBoss0700PlayerRUS */
    uint8_t pad_09C0[60];                      /* 0x09C0 */
    uint32_t   unk_09FC                 ; /* 0x09FC inferred ccBoss0700PlayerRUS */
    uint8_t pad_0A00[10816];                   /* 0x0A00 */
    uint8_t    unk_3440                 ; /* 0x3440 inferred ccBoss0700PlayerRUS */
    uint8_t pad_3441[1279];                    /* 0x3441 */
    uint8_t    unk_3940                 ; /* 0x3940 inferred ccBoss0700PlayerRUS */
    uint8_t pad_3941[63];                      /* 0x3941 */
    uint8_t    unk_3980                 ; /* 0x3980 inferred ccBoss0700PlayerRUS */
    uint8_t pad_3981[18879];                   /* 0x3981 */
    uint64_t   unk_8340                 ; /* 0x8340 inferred ccBoss0700PlayerRUS */
    uint8_t pad_8348[7600];                    /* 0x8348 */
    uint64_t   unk_A0F8                 ; /* 0xA0F8 inferred ccBoss0700PlayerRUS */
    uint8_t pad_A100[3792];                    /* 0xA100 */
    uint64_t   unk_AFD0                 ; /* 0xAFD0 inferred ccBoss0700PlayerRUS */
    uint8_t pad_AFD8[24];                      /* 0xAFD8 */
    uint32_t   unk_AFF0                 ; /* 0xAFF0 inferred ccBoss0700PlayerRUS */
    uint64_t   unk_AFF4                 ; /* 0xAFF4 inferred ccBoss0700PlayerRUS */
    uint32_t   unk_AFFC                 ; /* 0xAFFC inferred ccBoss0700PlayerRUS */
} ccBoss0700PlayerRUS;
#pragma pack(pop)

/* ccBoss0720CharacterWHO: Storm 3 boss battle class */
/* Size unknown, >= 0xB171 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720CharacterWHO {
    uint8_t pad_0000[180];                     /* 0x0000 */
    uint8_t    unk_00B4                 ; /* 0x00B4 inferred ccBoss0720CharacterWHO */
    uint8_t pad_00B5[159];                     /* 0x00B5 */
    uint32_t   unk_0154                 ; /* 0x0154 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_0158                 ; /* 0x0158 inferred ccBoss0720CharacterWHO */
    uint8_t pad_015C[160];                     /* 0x015C */
    uint32_t   unk_01FC                 ; /* 0x01FC inferred ccBoss0720CharacterWHO */
    uint64_t   unk_0200                 ; /* 0x0200 inferred ccBoss0720CharacterWHO */
    uint8_t pad_0208[632];                     /* 0x0208 */
    uint8_t    unk_0480                 ; /* 0x0480 inferred ccBoss0720CharacterWHO */
    uint8_t pad_0481[1403];                    /* 0x0481 */
    uint32_t   unk_09FC                 ; /* 0x09FC inferred ccBoss0720CharacterWHO */
    uint8_t pad_0A00[12096];                   /* 0x0A00 */
    uint8_t    unk_3940                 ; /* 0x3940 inferred ccBoss0720CharacterWHO */
    uint8_t pad_3941[17311];                   /* 0x3941 */
    uint8_t    unk_7CE0                 ; /* 0x7CE0 inferred ccBoss0720CharacterWHO */
    uint8_t pad_7CE1[1295];                    /* 0x7CE1 */
    uint64_t   unk_81F0                 ; /* 0x81F0 inferred ccBoss0720CharacterWHO */
    uint8_t pad_81F8[8072];                    /* 0x81F8 */
    uint64_t   unk_A180                 ; /* 0xA180 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A188                 ; /* 0xA188 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A190                 ; /* 0xA190 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A198                 ; /* 0xA198 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A1A0                 ; /* 0xA1A0 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A1A8                 ; /* 0xA1A8 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A1B0                 ; /* 0xA1B0 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A1B8                 ; /* 0xA1B8 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A1C0                 ; /* 0xA1C0 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_A1C8                 ; /* 0xA1C8 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_A1D0                 ; /* 0xA1D0 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_A1D4                 ; /* 0xA1D4 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_A1D8                 ; /* 0xA1D8 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_A1DC                 ; /* 0xA1DC inferred ccBoss0720CharacterWHO */
    uint8_t pad_A1E0[72];                      /* 0xA1E0 */
    uint8_t    unk_A228                 ; /* 0xA228 inferred ccBoss0720CharacterWHO */
    uint8_t pad_A229[3703];                    /* 0xA229 */
    uint64_t   unk_B0A0                 ; /* 0xB0A0 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_B0A8                 ; /* 0xB0A8 inferred ccBoss0720CharacterWHO */
    uint64_t   unk_B0AC                 ; /* 0xB0AC inferred ccBoss0720CharacterWHO */
    uint32_t   unk_B0B4                 ; /* 0xB0B4 inferred ccBoss0720CharacterWHO */
    uint32_t   unk_B0B8                 ; /* 0xB0B8 inferred ccBoss0720CharacterWHO */
    uint8_t pad_B0BC[124];                     /* 0xB0BC */
    uint64_t   unk_B138                 ; /* 0xB138 inferred ccBoss0720CharacterWHO */
    uint8_t    unk_B140                 ; /* 0xB140 inferred ccBoss0720CharacterWHO */
    uint8_t pad_B141[47];                      /* 0xB141 */
    uint8_t    unk_B170                 ; /* 0xB170 inferred ccBoss0720CharacterWHO */
} ccBoss0720CharacterWHO;
#pragma pack(pop)

/* ccSceneBoss0700State: Storm 3 boss battle class */
/* Size unknown, >= 0x90 (last field end) */
#pragma pack(push, 1)
typedef struct ccSceneBoss0700State {
    uint8_t pad_0000[112];                     /* 0x0000 */
    uint64_t   unk_0070                 ; /* 0x0070 inferred ccSceneBoss0700State */
    uint64_t   unk_0078                 ; /* 0x0078 inferred ccSceneBoss0700State */
    uint8_t pad_0080[8];                       /* 0x0080 */
    uint64_t   unk_0088                 ; /* 0x0088 inferred ccSceneBoss0700State */
} ccSceneBoss0700State;
#pragma pack(pop)

/* ccUiBoss0700Manager: Storm 3 boss battle class */
/* Size unknown, >= 0xC1 (last field end) */
#pragma pack(push, 1)
typedef struct ccUiBoss0700Manager {
    uint8_t pad_0000[88];                      /* 0x0000 */
    uint64_t   unk_0058                 ; /* 0x0058 inferred ccUiBoss0700Manager */
    uint64_t   unk_0060                 ; /* 0x0060 inferred ccUiBoss0700Manager */
    uint64_t   unk_0068                 ; /* 0x0068 inferred ccUiBoss0700Manager */
    uint64_t   unk_0070                 ; /* 0x0070 inferred ccUiBoss0700Manager */
    uint64_t   unk_0078                 ; /* 0x0078 inferred ccUiBoss0700Manager */
    uint64_t   unk_0080                 ; /* 0x0080 inferred ccUiBoss0700Manager */
    uint64_t   unk_0088                 ; /* 0x0088 inferred ccUiBoss0700Manager */
    uint64_t   unk_0090                 ; /* 0x0090 inferred ccUiBoss0700Manager */
    uint32_t   unk_0098                 ; /* 0x0098 inferred ccUiBoss0700Manager */
    uint8_t pad_009C[36];                      /* 0x009C */
    uint8_t    unk_00C0                 ; /* 0x00C0 inferred ccUiBoss0700Manager */
} ccUiBoss0700Manager;
#pragma pack(pop)

/* ccBoss0700: Storm 3 boss battle class — no instance state found */
/* Seeds: ccBoss0700::Update, ccBoss0700::CtrlCharacter, ccBoss0700::DisableCtrlAll... */

/* ccBoss0700Target: Storm 3 boss battle class — no instance state found */
/* Seeds: ccBoss0700Target::Ctrl, ccBoss0700Target::RequestLockonChange, ccBoss0700Target::Initialize... */

/* ccSceneBoss0720: Storm 3 boss battle class — no instance state found */
/* Seeds: ccSceneBoss0720::ChangeLayerPriority, ccSceneBoss0720::Initialize, ccSceneBoss0720::ResetLayerPriority... */

/* ccBoss0710EnemyController: Storm 3 boss battle class — no instance state found */
/* Seeds: ccBoss0710EnemyController::B0711BattleBeginOnState, ccBoss0710EnemyController::B0710BattlePhaseExitOnState, ccBoss0710EnemyController::B0711BattleBegin2OnState... */

/* ccBoss0700CamOpeType01: Storm 3 boss battle class — no instance state found */
/* Seeds: ccBoss0700CamOpeType01::Ctrl, ccBoss0700CamOpeType01::CalcHAN, ccBoss0700CamOpeType01::Calc... */

/* ccBoss0700VoiceManager: Storm 3 boss battle class — no instance state found */
/* Seeds: ccBoss0700VoiceManager::Update, ccBoss0700VoiceManager::Initialize, ccBoss0700VoiceManager::GetWarmUpVoiceId... */

/* ccBoss0710VoiceController: Storm 3 boss battle class — no instance state found */
/* Seeds: ccBoss0710VoiceController::State8700, ccBoss0710VoiceController::State8800, ccBoss0710VoiceController::State8900... */

/* ccSceneBoss0710: Storm 3 boss battle class — no instance state found */
/* Seeds: ccSceneBoss0710::Execute, ccSceneBoss0710::Finalize, ccSceneBoss0710::Load... */

/* ccBoss0710SupportState: Storm 3 boss battle class — no instance state found */
/* Seeds: 6 seeds analyzed */
/* ccBoss0700CamOpeType02: Storm 3 boss battle class — no instance state found */
/* Seeds: 4 seeds analyzed */
/* ccBoss0700EnemyLoaderState: Storm 3 boss battle class — no instance state found */
/* Seeds: 4 seeds analyzed */

/* ccBoss0720Acid: Storm 3 boss battle class */
/* Size unknown, >= 0x40 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720Acid {
    uint8_t pad_0000[60];                     /* 0x0000 */
    uint32_t    unk_003C                ; /* 0x003C inferred ccBoss0720Acid */
} ccBoss0720Acid;
#pragma pack(pop)

/* ccBoss0700PlayerKLB: Storm 3 boss battle class */
/* Size unknown, >= 0xADF4 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerKLB {
    uint8_t pad_0000[2516];                     /* 0x0000 */
    uint32_t    unk_09D4                ; /* 0x09D4 inferred ccBoss0700PlayerKLB */
    uint8_t pad_09D8[41752];                     /* 0x09D8 */
    uint32_t    unk_ACF0                ; /* 0xACF0 inferred ccBoss0700PlayerKLB */
    uint32_t    unk_ACF4                ; /* 0xACF4 inferred ccBoss0700PlayerKLB */
    uint8_t pad_ACF8[248];                     /* 0xACF8 */
    uint32_t    unk_ADF0                ; /* 0xADF0 inferred ccBoss0700PlayerKLB */
} ccBoss0700PlayerKLB;
#pragma pack(pop)

/* ccBoss0710CharacterKLB: Storm 3 boss battle class */
/* Size unknown, >= 0xB114 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0710CharacterKLB {
    uint8_t pad_0000[2516];                     /* 0x0000 */
    uint32_t    unk_09D4                ; /* 0x09D4 inferred ccBoss0710CharacterKLB */
    uint8_t pad_09D8[42708];                     /* 0x09D8 */
    uint32_t    unk_B0AC                ; /* 0xB0AC inferred ccBoss0710CharacterKLB */
    uint8_t pad_B0B0[96];                     /* 0xB0B0 */
    uint32_t    unk_B110                ; /* 0xB110 inferred ccBoss0710CharacterKLB */
} ccBoss0710CharacterKLB;
#pragma pack(pop)

/* ccBoss0720Lava: Storm 3 boss battle class */
/* Size unknown, >= 0x48 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0720Lava {
    uint8_t pad_0000[60];                     /* 0x0000 */
    uint32_t    unk_003C                ; /* 0x003C inferred ccBoss0720Lava */
    uint8_t pad_0040[4];                     /* 0x0040 */
    uint32_t    unk_0044                ; /* 0x0044 inferred ccBoss0720Lava */
} ccBoss0720Lava;
#pragma pack(pop)

/* ccUiBoss0710Manager: Storm 3 boss battle class */
/* Size unknown, >= 0xC0 (last field end) */
#pragma pack(push, 1)
typedef struct ccUiBoss0710Manager {
    uint8_t pad_0000[120];                     /* 0x0000 */
    uint64_t    unk_0078                ; /* 0x0078 inferred ccUiBoss0710Manager */
    uint8_t pad_0080[8];                     /* 0x0080 */
    uint64_t    unk_0088                ; /* 0x0088 inferred ccUiBoss0710Manager */
    uint64_t    unk_0090                ; /* 0x0090 inferred ccUiBoss0710Manager */
    uint64_t    unk_0098                ; /* 0x0098 inferred ccUiBoss0710Manager */
    uint64_t    unk_00A0                ; /* 0x00A0 inferred ccUiBoss0710Manager */
    uint8_t pad_00A8[16];                     /* 0x00A8 */
    uint64_t    unk_00B8                ; /* 0x00B8 inferred ccUiBoss0710Manager */
} ccUiBoss0710Manager;
#pragma pack(pop)

/* ccUiBoss0711Manager: Storm 3 boss battle class */
/* Size unknown, >= 0xF0 (last field end) */
#pragma pack(push, 1)
typedef struct ccUiBoss0711Manager {
    uint8_t pad_0000[120];                     /* 0x0000 */
    uint64_t    unk_0078                ; /* 0x0078 inferred ccUiBoss0711Manager */
    uint8_t pad_0080[8];                     /* 0x0080 */
    uint64_t    unk_0088                ; /* 0x0088 inferred ccUiBoss0711Manager */
    uint8_t pad_0090[56];                     /* 0x0090 */
    uint64_t    unk_00C8                ; /* 0x00C8 inferred ccUiBoss0711Manager */
    uint64_t    unk_00D0                ; /* 0x00D0 inferred ccUiBoss0711Manager */
    uint32_t    unk_00D8                ; /* 0x00D8 inferred ccUiBoss0711Manager */
    uint8_t pad_00DC[4];                     /* 0x00DC */
    uint64_t    unk_00E0                ; /* 0x00E0 inferred ccUiBoss0711Manager */
    uint64_t    unk_00E8                ; /* 0x00E8 inferred ccUiBoss0711Manager */
} ccUiBoss0711Manager;
#pragma pack(pop)

/* ccBoss0700Stage: Storm 3 boss battle class */
/* Size unknown, >= 0x258 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700Stage {
    uint8_t pad_0000[184];                     /* 0x0000 */
    uint64_t    unk_00B8                ; /* 0x00B8 inferred ccBoss0700Stage */
    uint64_t    unk_00C0                ; /* 0x00C0 inferred ccBoss0700Stage */
    uint64_t    unk_00C8                ; /* 0x00C8 inferred ccBoss0700Stage */
    uint64_t    unk_00D0                ; /* 0x00D0 inferred ccBoss0700Stage */
    uint64_t    unk_00D8                ; /* 0x00D8 inferred ccBoss0700Stage */
    uint8_t pad_00E0[16];                     /* 0x00E0 */
    uint64_t    unk_00F0                ; /* 0x00F0 inferred ccBoss0700Stage */
    uint32_t    unk_00F8                ; /* 0x00F8 inferred ccBoss0700Stage */
    uint8_t pad_00FC[4];                     /* 0x00FC */
    uint64_t    unk_0100                ; /* 0x0100 inferred ccBoss0700Stage */
    uint64_t    unk_0108                ; /* 0x0108 inferred ccBoss0700Stage */
    uint32_t    unk_0110                ; /* 0x0110 inferred ccBoss0700Stage */
    uint8_t pad_0114[4];                     /* 0x0114 */
    uint64_t    unk_0118                ; /* 0x0118 inferred ccBoss0700Stage */
    uint64_t    unk_0120                ; /* 0x0120 inferred ccBoss0700Stage */
    uint64_t    unk_0128                ; /* 0x0128 inferred ccBoss0700Stage */
    uint32_t    unk_0130                ; /* 0x0130 inferred ccBoss0700Stage */
    uint8_t pad_0134[284];                     /* 0x0134 */
    uint32_t    unk_0250                ; /* 0x0250 inferred ccBoss0700Stage */
    uint32_t    unk_0254                ; /* 0x0254 inferred ccBoss0700Stage */
} ccBoss0700Stage;
#pragma pack(pop)

/* ccBoss0700PlayerJoinComboBase: Storm 3 boss battle class */
/* Size unknown, >= 0xAFC4 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerJoinComboBase {
    uint8_t pad_0000[144];                     /* 0x0000 */
    uint64_t    unk_0090                ; /* 0x0090 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_0098                ; /* 0x0098 inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_009C[12];                     /* 0x009C */
    uint64_t    unk_00A8                ; /* 0x00A8 inferred ccBoss0700PlayerJoinComboBase */
    uint64_t    unk_00B0                ; /* 0x00B0 inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_00B8[328];                     /* 0x00B8 */
    uint32_t    unk_0200                ; /* 0x0200 inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_0204[2024];                     /* 0x0204 */
    uint32_t    unk_09EC                ; /* 0x09EC inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_09F0                ; /* 0x09F0 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_09F4                ; /* 0x09F4 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_09F8                ; /* 0x09F8 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_09FC                ; /* 0x09FC inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_0A00                ; /* 0x0A00 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_0A04                ; /* 0x0A04 inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_0A08[4];                     /* 0x0A08 */
    uint32_t    unk_0A0C                ; /* 0x0A0C inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_0A10[664];                     /* 0x0A10 */
    uint64_t    unk_0CA8                ; /* 0x0CA8 inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_0CB0[29508];                     /* 0x0CB0 */
    uint64_t    unk_7FF4                ; /* 0x7FF4 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_7FFC                ; /* 0x7FFC inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_8000[8716];                     /* 0x8000 */
    uint32_t    unk_A20C                ; /* 0xA20C inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_A210[2784];                     /* 0xA210 */
    uint32_t    unk_ACF0                ; /* 0xACF0 inferred ccBoss0700PlayerJoinComboBase */
    uint32_t    unk_ACF4                ; /* 0xACF4 inferred ccBoss0700PlayerJoinComboBase */
    uint8_t pad_ACF8[712];                     /* 0xACF8 */
    uint32_t    unk_AFC0                ; /* 0xAFC0 inferred ccBoss0700PlayerJoinComboBase */
} ccBoss0700PlayerJoinComboBase;
#pragma pack(pop)

/* ccBoss0700PlayerHAN: Storm 3 boss battle class */
/* Size unknown, >= 0xA318 (last field end) */
#pragma pack(push, 1)
typedef struct ccBoss0700PlayerHAN {
    uint8_t pad_0000[340];                     /* 0x0000 */
    uint32_t    unk_0154                ; /* 0x0154 inferred ccBoss0700PlayerHAN */
    uint32_t    unk_0158                ; /* 0x0158 inferred ccBoss0700PlayerHAN */
    uint8_t pad_015C[4];                     /* 0x015C */
    uint32_t    unk_0160                ; /* 0x0160 inferred ccBoss0700PlayerHAN */
    uint8_t pad_0164[156];                     /* 0x0164 */
    uint64_t    unk_0200                ; /* 0x0200 inferred ccBoss0700PlayerHAN */
    uint8_t pad_0208[1940];                     /* 0x0208 */
    uint32_t    unk_099C                ; /* 0x099C inferred ccBoss0700PlayerHAN */
    uint8_t pad_09A0[24];                     /* 0x09A0 */
    uint64_t    unk_09B8                ; /* 0x09B8 inferred ccBoss0700PlayerHAN */
    uint8_t pad_09C0[56];                     /* 0x09C0 */
    uint32_t    unk_09F8                ; /* 0x09F8 inferred ccBoss0700PlayerHAN */
    uint32_t    unk_09FC                ; /* 0x09FC inferred ccBoss0700PlayerHAN */
    uint32_t    unk_0A00                ; /* 0x0A00 inferred ccBoss0700PlayerHAN */
    uint32_t    unk_0A04                ; /* 0x0A04 inferred ccBoss0700PlayerHAN */
    uint8_t pad_0A08[400];                     /* 0x0A08 */
    uint32_t    unk_0B98                ; /* 0x0B98 inferred ccBoss0700PlayerHAN */
    uint8_t pad_0B9C[12];                     /* 0x0B9C */
    uint32_t    unk_0BA8                ; /* 0x0BA8 inferred ccBoss0700PlayerHAN */
    uint8_t pad_0BAC[24];                     /* 0x0BAC */
    uint32_t    unk_0BC4                ; /* 0x0BC4 inferred ccBoss0700PlayerHAN */
    uint8_t pad_0BC8[30384];                     /* 0x0BC8 */
    uint64_t    unk_8278                ; /* 0x8278 inferred ccBoss0700PlayerHAN */
    uint8_t pad_8280[7800];                     /* 0x8280 */
    uint64_t    unk_A0F8                ; /* 0xA0F8 inferred ccBoss0700PlayerHAN */
    uint8_t pad_A100[532];                     /* 0xA100 */
    uint32_t    unk_A314                ; /* 0xA314 inferred ccBoss0700PlayerHAN */
} ccBoss0700PlayerHAN;
#pragma pack(pop)

static_assert(offsetof(ccBoss0700PlayerRUS, unk_0200) == 0x200, "ccBoss0700PlayerRUS.unk_0200 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_02C0) == 0x2C0, "ccBoss0700PlayerRUS.unk_02C0 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_09B8) == 0x9B8, "ccBoss0700PlayerRUS.unk_09B8 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_09FC) == 0x9FC, "ccBoss0700PlayerRUS.unk_09FC offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_3440) == 0x3440, "ccBoss0700PlayerRUS.unk_3440 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_3940) == 0x3940, "ccBoss0700PlayerRUS.unk_3940 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_3980) == 0x3980, "ccBoss0700PlayerRUS.unk_3980 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_8340) == 0x8340, "ccBoss0700PlayerRUS.unk_8340 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_A0F8) == 0xA0F8, "ccBoss0700PlayerRUS.unk_A0F8 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_AFD0) == 0xAFD0, "ccBoss0700PlayerRUS.unk_AFD0 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_AFF0) == 0xAFF0, "ccBoss0700PlayerRUS.unk_AFF0 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_AFF4) == 0xAFF4, "ccBoss0700PlayerRUS.unk_AFF4 offset");
static_assert(offsetof(ccBoss0700PlayerRUS, unk_AFFC) == 0xAFFC, "ccBoss0700PlayerRUS.unk_AFFC offset");

static_assert(offsetof(ccBoss0720CharacterWHO, unk_00B4) == 0xB4, "ccBoss0720CharacterWHO.unk_00B4 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_0154) == 0x154, "ccBoss0720CharacterWHO.unk_0154 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_0158) == 0x158, "ccBoss0720CharacterWHO.unk_0158 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_01FC) == 0x1FC, "ccBoss0720CharacterWHO.unk_01FC offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_0200) == 0x200, "ccBoss0720CharacterWHO.unk_0200 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_0480) == 0x480, "ccBoss0720CharacterWHO.unk_0480 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_09FC) == 0x9FC, "ccBoss0720CharacterWHO.unk_09FC offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_3940) == 0x3940, "ccBoss0720CharacterWHO.unk_3940 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_7CE0) == 0x7CE0, "ccBoss0720CharacterWHO.unk_7CE0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_81F0) == 0x81F0, "ccBoss0720CharacterWHO.unk_81F0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A180) == 0xA180, "ccBoss0720CharacterWHO.unk_A180 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A188) == 0xA188, "ccBoss0720CharacterWHO.unk_A188 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A190) == 0xA190, "ccBoss0720CharacterWHO.unk_A190 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A198) == 0xA198, "ccBoss0720CharacterWHO.unk_A198 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1A0) == 0xA1A0, "ccBoss0720CharacterWHO.unk_A1A0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1A8) == 0xA1A8, "ccBoss0720CharacterWHO.unk_A1A8 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1B0) == 0xA1B0, "ccBoss0720CharacterWHO.unk_A1B0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1B8) == 0xA1B8, "ccBoss0720CharacterWHO.unk_A1B8 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1C0) == 0xA1C0, "ccBoss0720CharacterWHO.unk_A1C0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1C8) == 0xA1C8, "ccBoss0720CharacterWHO.unk_A1C8 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1D0) == 0xA1D0, "ccBoss0720CharacterWHO.unk_A1D0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1D4) == 0xA1D4, "ccBoss0720CharacterWHO.unk_A1D4 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1D8) == 0xA1D8, "ccBoss0720CharacterWHO.unk_A1D8 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A1DC) == 0xA1DC, "ccBoss0720CharacterWHO.unk_A1DC offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_A228) == 0xA228, "ccBoss0720CharacterWHO.unk_A228 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B0A0) == 0xB0A0, "ccBoss0720CharacterWHO.unk_B0A0 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B0A8) == 0xB0A8, "ccBoss0720CharacterWHO.unk_B0A8 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B0AC) == 0xB0AC, "ccBoss0720CharacterWHO.unk_B0AC offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B0B4) == 0xB0B4, "ccBoss0720CharacterWHO.unk_B0B4 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B0B8) == 0xB0B8, "ccBoss0720CharacterWHO.unk_B0B8 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B138) == 0xB138, "ccBoss0720CharacterWHO.unk_B138 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B140) == 0xB140, "ccBoss0720CharacterWHO.unk_B140 offset");
static_assert(offsetof(ccBoss0720CharacterWHO, unk_B170) == 0xB170, "ccBoss0720CharacterWHO.unk_B170 offset");

static_assert(offsetof(ccSceneBoss0700State, unk_0070) == 0x70, "ccSceneBoss0700State.unk_0070 offset");
static_assert(offsetof(ccSceneBoss0700State, unk_0078) == 0x78, "ccSceneBoss0700State.unk_0078 offset");
static_assert(offsetof(ccSceneBoss0700State, unk_0088) == 0x88, "ccSceneBoss0700State.unk_0088 offset");

static_assert(offsetof(ccUiBoss0700Manager, unk_0058) == 0x58, "ccUiBoss0700Manager.unk_0058 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0060) == 0x60, "ccUiBoss0700Manager.unk_0060 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0068) == 0x68, "ccUiBoss0700Manager.unk_0068 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0070) == 0x70, "ccUiBoss0700Manager.unk_0070 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0078) == 0x78, "ccUiBoss0700Manager.unk_0078 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0080) == 0x80, "ccUiBoss0700Manager.unk_0080 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0088) == 0x88, "ccUiBoss0700Manager.unk_0088 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0090) == 0x90, "ccUiBoss0700Manager.unk_0090 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_0098) == 0x98, "ccUiBoss0700Manager.unk_0098 offset");
static_assert(offsetof(ccUiBoss0700Manager, unk_00C0) == 0xC0, "ccUiBoss0700Manager.unk_00C0 offset");

static_assert(offsetof(ccBoss0720Acid, unk_003C) == 0x3C, "ccBoss0720Acid.unk_003C offset");
static_assert(offsetof(ccBoss0700PlayerKLB, unk_09D4) == 0x9D4, "ccBoss0700PlayerKLB.unk_09D4 offset");
static_assert(offsetof(ccBoss0700PlayerKLB, unk_ACF0) == 0xACF0, "ccBoss0700PlayerKLB.unk_ACF0 offset");
static_assert(offsetof(ccBoss0700PlayerKLB, unk_ACF4) == 0xACF4, "ccBoss0700PlayerKLB.unk_ACF4 offset");
static_assert(offsetof(ccBoss0700PlayerKLB, unk_ADF0) == 0xADF0, "ccBoss0700PlayerKLB.unk_ADF0 offset");
static_assert(offsetof(ccBoss0710CharacterKLB, unk_09D4) == 0x9D4, "ccBoss0710CharacterKLB.unk_09D4 offset");
static_assert(offsetof(ccBoss0710CharacterKLB, unk_B0AC) == 0xB0AC, "ccBoss0710CharacterKLB.unk_B0AC offset");
static_assert(offsetof(ccBoss0710CharacterKLB, unk_B110) == 0xB110, "ccBoss0710CharacterKLB.unk_B110 offset");
static_assert(offsetof(ccBoss0720Lava, unk_003C) == 0x3C, "ccBoss0720Lava.unk_003C offset");
static_assert(offsetof(ccBoss0720Lava, unk_0044) == 0x44, "ccBoss0720Lava.unk_0044 offset");
static_assert(offsetof(ccUiBoss0710Manager, unk_0078) == 0x78, "ccUiBoss0710Manager.unk_0078 offset");
static_assert(offsetof(ccUiBoss0710Manager, unk_0088) == 0x88, "ccUiBoss0710Manager.unk_0088 offset");
static_assert(offsetof(ccUiBoss0710Manager, unk_0090) == 0x90, "ccUiBoss0710Manager.unk_0090 offset");
static_assert(offsetof(ccUiBoss0710Manager, unk_0098) == 0x98, "ccUiBoss0710Manager.unk_0098 offset");
static_assert(offsetof(ccUiBoss0710Manager, unk_00A0) == 0xA0, "ccUiBoss0710Manager.unk_00A0 offset");
static_assert(offsetof(ccUiBoss0710Manager, unk_00B8) == 0xB8, "ccUiBoss0710Manager.unk_00B8 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_0078) == 0x78, "ccUiBoss0711Manager.unk_0078 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_0088) == 0x88, "ccUiBoss0711Manager.unk_0088 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_00C8) == 0xC8, "ccUiBoss0711Manager.unk_00C8 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_00D0) == 0xD0, "ccUiBoss0711Manager.unk_00D0 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_00D8) == 0xD8, "ccUiBoss0711Manager.unk_00D8 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_00E0) == 0xE0, "ccUiBoss0711Manager.unk_00E0 offset");
static_assert(offsetof(ccUiBoss0711Manager, unk_00E8) == 0xE8, "ccUiBoss0711Manager.unk_00E8 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00B8) == 0xB8, "ccBoss0700Stage.unk_00B8 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00C0) == 0xC0, "ccBoss0700Stage.unk_00C0 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00C8) == 0xC8, "ccBoss0700Stage.unk_00C8 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00D0) == 0xD0, "ccBoss0700Stage.unk_00D0 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00D8) == 0xD8, "ccBoss0700Stage.unk_00D8 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00F0) == 0xF0, "ccBoss0700Stage.unk_00F0 offset");
static_assert(offsetof(ccBoss0700Stage, unk_00F8) == 0xF8, "ccBoss0700Stage.unk_00F8 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0100) == 0x100, "ccBoss0700Stage.unk_0100 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0108) == 0x108, "ccBoss0700Stage.unk_0108 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0110) == 0x110, "ccBoss0700Stage.unk_0110 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0118) == 0x118, "ccBoss0700Stage.unk_0118 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0120) == 0x120, "ccBoss0700Stage.unk_0120 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0128) == 0x128, "ccBoss0700Stage.unk_0128 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0130) == 0x130, "ccBoss0700Stage.unk_0130 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0250) == 0x250, "ccBoss0700Stage.unk_0250 offset");
static_assert(offsetof(ccBoss0700Stage, unk_0254) == 0x254, "ccBoss0700Stage.unk_0254 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0090) == 0x90, "ccBoss0700PlayerJoinComboBase.unk_0090 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0098) == 0x98, "ccBoss0700PlayerJoinComboBase.unk_0098 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_00A8) == 0xA8, "ccBoss0700PlayerJoinComboBase.unk_00A8 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_00B0) == 0xB0, "ccBoss0700PlayerJoinComboBase.unk_00B0 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0200) == 0x200, "ccBoss0700PlayerJoinComboBase.unk_0200 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_09EC) == 0x9EC, "ccBoss0700PlayerJoinComboBase.unk_09EC offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_09F0) == 0x9F0, "ccBoss0700PlayerJoinComboBase.unk_09F0 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_09F4) == 0x9F4, "ccBoss0700PlayerJoinComboBase.unk_09F4 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_09F8) == 0x9F8, "ccBoss0700PlayerJoinComboBase.unk_09F8 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_09FC) == 0x9FC, "ccBoss0700PlayerJoinComboBase.unk_09FC offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0A00) == 0xA00, "ccBoss0700PlayerJoinComboBase.unk_0A00 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0A04) == 0xA04, "ccBoss0700PlayerJoinComboBase.unk_0A04 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0A0C) == 0xA0C, "ccBoss0700PlayerJoinComboBase.unk_0A0C offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_0CA8) == 0xCA8, "ccBoss0700PlayerJoinComboBase.unk_0CA8 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_7FF4) == 0x7FF4, "ccBoss0700PlayerJoinComboBase.unk_7FF4 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_7FFC) == 0x7FFC, "ccBoss0700PlayerJoinComboBase.unk_7FFC offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_A20C) == 0xA20C, "ccBoss0700PlayerJoinComboBase.unk_A20C offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_ACF0) == 0xACF0, "ccBoss0700PlayerJoinComboBase.unk_ACF0 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_ACF4) == 0xACF4, "ccBoss0700PlayerJoinComboBase.unk_ACF4 offset");
static_assert(offsetof(ccBoss0700PlayerJoinComboBase, unk_AFC0) == 0xAFC0, "ccBoss0700PlayerJoinComboBase.unk_AFC0 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0154) == 0x154, "ccBoss0700PlayerHAN.unk_0154 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0158) == 0x158, "ccBoss0700PlayerHAN.unk_0158 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0160) == 0x160, "ccBoss0700PlayerHAN.unk_0160 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0200) == 0x200, "ccBoss0700PlayerHAN.unk_0200 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_099C) == 0x99C, "ccBoss0700PlayerHAN.unk_099C offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_09B8) == 0x9B8, "ccBoss0700PlayerHAN.unk_09B8 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_09F8) == 0x9F8, "ccBoss0700PlayerHAN.unk_09F8 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_09FC) == 0x9FC, "ccBoss0700PlayerHAN.unk_09FC offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0A00) == 0xA00, "ccBoss0700PlayerHAN.unk_0A00 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0A04) == 0xA04, "ccBoss0700PlayerHAN.unk_0A04 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0B98) == 0xB98, "ccBoss0700PlayerHAN.unk_0B98 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0BA8) == 0xBA8, "ccBoss0700PlayerHAN.unk_0BA8 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_0BC4) == 0xBC4, "ccBoss0700PlayerHAN.unk_0BC4 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_8278) == 0x8278, "ccBoss0700PlayerHAN.unk_8278 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_A0F8) == 0xA0F8, "ccBoss0700PlayerHAN.unk_A0F8 offset");
static_assert(offsetof(ccBoss0700PlayerHAN, unk_A314) == 0xA314, "ccBoss0700PlayerHAN.unk_A314 offset");

#endif /* S3_BOSS07_H */

/* ccBoss0700Skill — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccBoss0700Skill {
    uint8_t pad_0000[144];
    uint32_t unk_0090; /* w medium */
    uint32_t unk_0094; /* w medium */
    uint32_t unk_0098; /* w medium */
} ccBoss0700Skill;
#pragma pack(pop)
/* size unknown, >= 0x9C (156 bytes) */
static_assert(offsetof(ccBoss0700Skill, unk_0090) == 0x90, "ccBoss0700Skill.unk_0090 offset");
static_assert(offsetof(ccBoss0700Skill, unk_0094) == 0x94, "ccBoss0700Skill.unk_0094 offset");
static_assert(offsetof(ccBoss0700Skill, unk_0098) == 0x98, "ccBoss0700Skill.unk_0098 offset");

/* ccBoss0700SkillManager — no instance state found (0 surface fields, batch 5) */

/* ccSceneBoss0711 — no instance state found (0 surface fields, batch 5) */

/* ccBoss0710CharacterNRT — no instance state found (0 surface fields, batch 5) */

/* ccBoss0720CharacterYGR — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccBoss0720CharacterYGR {
    uint8_t pad_0000[508];
    uint32_t unk_01FC; /* r medium */
    uint64_t unk_0200; /* r medium */
    uint8_t pad_0208[2036];
    uint32_t unk_09FC; /* r medium */
    uint8_t pad_0A00[30704];
    uint64_t unk_81F0; /* r medium */
    uint8_t pad_81F8[8072];
    uint64_t unk_A180; /* w medium */
    uint64_t unk_A188; /* w medium */
    uint64_t unk_A190; /* w medium */
    uint64_t unk_A198; /* w medium */
    uint64_t unk_A1A0; /* w medium */
    uint64_t unk_A1A8; /* w medium */
    uint64_t unk_A1B0; /* w medium */
    uint64_t unk_A1B8; /* w medium */
    uint64_t unk_A1C0; /* w medium */
    uint64_t unk_A1C8; /* w medium */
    uint64_t unk_A1D0; /* w medium */
    uint64_t unk_A1D8; /* w medium */
    uint8_t pad_A1E0[204];
    uint32_t unk_A2AC; /* r medium */
    uint8_t pad_A2B0[3696];
    uint64_t unk_B120; /* rw low */
    uint32_t unk_B128; /* w medium */
    uint32_t unk_B12C; /* rw high */
    uint32_t unk_B130; /* rw high */
    uint32_t unk_B134; /* r medium */
} ccBoss0720CharacterYGR;
#pragma pack(pop)
/* size unknown, >= 0xB138 (45368 bytes) */
static_assert(offsetof(ccBoss0720CharacterYGR, unk_01FC) == 0x1FC, "ccBoss0720CharacterYGR.unk_01FC offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_0200) == 0x200, "ccBoss0720CharacterYGR.unk_0200 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_09FC) == 0x9FC, "ccBoss0720CharacterYGR.unk_09FC offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_81F0) == 0x81F0, "ccBoss0720CharacterYGR.unk_81F0 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A180) == 0xA180, "ccBoss0720CharacterYGR.unk_A180 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A188) == 0xA188, "ccBoss0720CharacterYGR.unk_A188 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A190) == 0xA190, "ccBoss0720CharacterYGR.unk_A190 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A198) == 0xA198, "ccBoss0720CharacterYGR.unk_A198 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1A0) == 0xA1A0, "ccBoss0720CharacterYGR.unk_A1A0 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1A8) == 0xA1A8, "ccBoss0720CharacterYGR.unk_A1A8 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1B0) == 0xA1B0, "ccBoss0720CharacterYGR.unk_A1B0 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1B8) == 0xA1B8, "ccBoss0720CharacterYGR.unk_A1B8 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1C0) == 0xA1C0, "ccBoss0720CharacterYGR.unk_A1C0 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1C8) == 0xA1C8, "ccBoss0720CharacterYGR.unk_A1C8 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1D0) == 0xA1D0, "ccBoss0720CharacterYGR.unk_A1D0 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A1D8) == 0xA1D8, "ccBoss0720CharacterYGR.unk_A1D8 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_A2AC) == 0xA2AC, "ccBoss0720CharacterYGR.unk_A2AC offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_B120) == 0xB120, "ccBoss0720CharacterYGR.unk_B120 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_B128) == 0xB128, "ccBoss0720CharacterYGR.unk_B128 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_B12C) == 0xB12C, "ccBoss0720CharacterYGR.unk_B12C offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_B130) == 0xB130, "ccBoss0720CharacterYGR.unk_B130 offset");
static_assert(offsetof(ccBoss0720CharacterYGR, unk_B134) == 0xB134, "ccBoss0720CharacterYGR.unk_B134 offset");

/* ccUiBoss0720Manager — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccUiBoss0720Manager {
    uint8_t pad_0000[120];
    uint64_t unk_0078; /* r medium */
    uint8_t pad_0080[8];
    uint64_t unk_0088; /* w high */
    uint64_t unk_0090; /* w medium */
    uint64_t unk_0098; /* rw high */
    uint64_t unk_00A0; /* w high */
    uint64_t unk_00A8; /* w high */
    uint32_t unk_00B0; /* w medium */
} ccUiBoss0720Manager;
#pragma pack(pop)
/* size unknown, >= 0xB4 (180 bytes) */
static_assert(offsetof(ccUiBoss0720Manager, unk_0078) == 0x78, "ccUiBoss0720Manager.unk_0078 offset");
static_assert(offsetof(ccUiBoss0720Manager, unk_0088) == 0x88, "ccUiBoss0720Manager.unk_0088 offset");
static_assert(offsetof(ccUiBoss0720Manager, unk_0090) == 0x90, "ccUiBoss0720Manager.unk_0090 offset");
static_assert(offsetof(ccUiBoss0720Manager, unk_0098) == 0x98, "ccUiBoss0720Manager.unk_0098 offset");
static_assert(offsetof(ccUiBoss0720Manager, unk_00A0) == 0xA0, "ccUiBoss0720Manager.unk_00A0 offset");
static_assert(offsetof(ccUiBoss0720Manager, unk_00A8) == 0xA8, "ccUiBoss0720Manager.unk_00A8 offset");
static_assert(offsetof(ccUiBoss0720Manager, unk_00B0) == 0xB0, "ccUiBoss0720Manager.unk_00B0 offset");

/* ccBoss0700CameraOperator — no instance state found (0 surface fields, batch 5) */

/* ccBoss0700LoaderManager — no instance state found (0 surface fields, batch 5) */

/* ccSceneBoss0700Base — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccSceneBoss0700Base {
    uint8_t pad_0000[296];
    uint64_t unk_0128; /* rw medium */
} ccSceneBoss0700Base;
#pragma pack(pop)
/* size unknown, >= 0x130 (304 bytes) */
static_assert(offsetof(ccSceneBoss0700Base, unk_0128) == 0x128, "ccSceneBoss0700Base.unk_0128 offset");

/* ccBoss0710CharacterTOB — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccBoss0710CharacterTOB {
    uint8_t pad_0000[2540];
    uint32_t unk_09EC; /* r medium */
    uint8_t pad_09F0[42468];
    uint32_t unk_AFD4; /* rw medium */
    uint8_t pad_AFD8[64];
    uint32_t unk_B018; /* w medium */
    uint32_t unk_B01C; /* rw high */
} ccBoss0710CharacterTOB;
#pragma pack(pop)
/* size unknown, >= 0xB020 (45088 bytes) */
static_assert(offsetof(ccBoss0710CharacterTOB, unk_09EC) == 0x9EC, "ccBoss0710CharacterTOB.unk_09EC offset");
static_assert(offsetof(ccBoss0710CharacterTOB, unk_AFD4) == 0xAFD4, "ccBoss0710CharacterTOB.unk_AFD4 offset");
static_assert(offsetof(ccBoss0710CharacterTOB, unk_B018) == 0xB018, "ccBoss0710CharacterTOB.unk_B018 offset");
static_assert(offsetof(ccBoss0710CharacterTOB, unk_B01C) == 0xB01C, "ccBoss0710CharacterTOB.unk_B01C offset");

/* ccBoss0720VoiceController — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccBoss0720VoiceController {
    uint8_t pad_0000[440];
    uint64_t unk_01B8; /* w medium */
    uint64_t unk_01C0; /* w medium */
    uint8_t pad_01C8[48];
    uint32_t unk_01F8; /* w medium */
    uint8_t pad_01FC[380];
    uint64_t unk_0378; /* w medium */
    uint32_t unk_0380; /* w medium */
    uint8_t pad_0384[4];
    uint32_t unk_0388; /* w medium */
} ccBoss0720VoiceController;
#pragma pack(pop)
/* size unknown, >= 0x38C (908 bytes) */
static_assert(offsetof(ccBoss0720VoiceController, unk_01B8) == 0x1B8, "ccBoss0720VoiceController.unk_01B8 offset");
static_assert(offsetof(ccBoss0720VoiceController, unk_01C0) == 0x1C0, "ccBoss0720VoiceController.unk_01C0 offset");
static_assert(offsetof(ccBoss0720VoiceController, unk_01F8) == 0x1F8, "ccBoss0720VoiceController.unk_01F8 offset");
static_assert(offsetof(ccBoss0720VoiceController, unk_0378) == 0x378, "ccBoss0720VoiceController.unk_0378 offset");
static_assert(offsetof(ccBoss0720VoiceController, unk_0380) == 0x380, "ccBoss0720VoiceController.unk_0380 offset");
static_assert(offsetof(ccBoss0720VoiceController, unk_0388) == 0x388, "ccBoss0720VoiceController.unk_0388 offset");

/* ccBoss0720Fire — INFERRED from state_surface (s3, batch 5) */
#pragma pack(push,1)
typedef struct ccBoss0720Fire {
    uint8_t pad_0000[12];
    uint32_t unk_000C; /* w medium */
    uint8_t pad_0010[4];
    uint32_t unk_0014; /* w medium */
    uint8_t pad_0018[4];
    uint64_t unk_001C; /* w medium */
    uint32_t unk_0024; /* w medium */
} ccBoss0720Fire;
#pragma pack(pop)
/* size unknown, >= 0x28 (40 bytes) */
static_assert(offsetof(ccBoss0720Fire, unk_000C) == 0xC, "ccBoss0720Fire.unk_000C offset");
static_assert(offsetof(ccBoss0720Fire, unk_0014) == 0x14, "ccBoss0720Fire.unk_0014 offset");
static_assert(offsetof(ccBoss0720Fire, unk_001C) == 0x1C, "ccBoss0720Fire.unk_001C offset");
static_assert(offsetof(ccBoss0720Fire, unk_0024) == 0x24, "ccBoss0720Fire.unk_0024 offset");


/* ccBoss0730VoiceController — INFERRED from state_surface (s3, batch 6) */
#pragma pack(push,1)
typedef struct ccBoss0730VoiceController {
    uint8_t pad_0000[84];
    uint32_t unk_0054; /* w medium */
    uint64_t unk_0058; /* w medium */
    uint32_t unk_0060; /* w medium */
    uint8_t pad_0064[4];
    uint64_t unk_0068; /* w medium */
    uint32_t unk_0070; /* w medium */
    uint8_t pad_0074[0];
    uint64_t unk_0074; /* w medium */
    uint64_t unk_007C; /* w medium */
} ccBoss0730VoiceController;
#pragma pack(pop)
/* size unknown, >= 0x84 (132 bytes) */
static_assert(offsetof(ccBoss0730VoiceController, unk_0054) == 0x54, "ccBoss0730VoiceController.unk_0054 offset");
static_assert(offsetof(ccBoss0730VoiceController, unk_0058) == 0x58, "ccBoss0730VoiceController.unk_0058 offset");
static_assert(offsetof(ccBoss0730VoiceController, unk_0060) == 0x60, "ccBoss0730VoiceController.unk_0060 offset");
static_assert(offsetof(ccBoss0730VoiceController, unk_0068) == 0x68, "ccBoss0730VoiceController.unk_0068 offset");
static_assert(offsetof(ccBoss0730VoiceController, unk_0070) == 0x70, "ccBoss0730VoiceController.unk_0070 offset");
static_assert(offsetof(ccBoss0730VoiceController, unk_0074) == 0x74, "ccBoss0730VoiceController.unk_0074 offset");
static_assert(offsetof(ccBoss0730VoiceController, unk_007C) == 0x7C, "ccBoss0730VoiceController.unk_007C offset");

/* ccBoss07HugeCharacterSyncEff — INFERRED from state_surface (s3, batch 6) */
#pragma pack(push,1)
typedef struct ccBoss07HugeCharacterSyncEff {
    uint8_t pad_0000[52];
    uint32_t unk_0034; /* rw high */
    uint8_t pad_0038[32];
    uint64_t unk_0058; /* r low (sub-object ptr) */
    uint64_t unk_0060; /* w medium */
    uint64_t unk_0068; /* r low (sub-object ptr) */
} ccBoss07HugeCharacterSyncEff;
#pragma pack(pop)
/* size unknown, >= 0x70 (112 bytes) */
static_assert(offsetof(ccBoss07HugeCharacterSyncEff, unk_0034) == 0x34, "ccBoss07HugeCharacterSyncEff.unk_0034 offset");
static_assert(offsetof(ccBoss07HugeCharacterSyncEff, unk_0058) == 0x58, "ccBoss07HugeCharacterSyncEff.unk_0058 offset");
static_assert(offsetof(ccBoss07HugeCharacterSyncEff, unk_0060) == 0x60, "ccBoss07HugeCharacterSyncEff.unk_0060 offset");
static_assert(offsetof(ccBoss07HugeCharacterSyncEff, unk_0068) == 0x68, "ccBoss07HugeCharacterSyncEff.unk_0068 offset");
