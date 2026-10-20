#ifndef S3_BOSS00_H
#define S3_BOSS00_H

/*
 * s3Boss00.h - Storm 3 Full Burst HD (NSUNS3.exe) boss battle structs
 * Build: s3 (NARUTO STORM 3 Full Burst HD PC, 64-bit)
 *
 * ALL FIELDS ARE INFERRED FROM STATIC ANALYSIS (state_surface).
 * No runtime confirmation. Offsets and types may be wrong.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccBoss0000
 * Object size: 0x498 (1176 bytes)
 * Fields: 15 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000 {
    uint8_t pad_0000[0x80]; /* 0x0000 */
    uint64_t unk_0080; /* 0x0080 w medium ccBoss0000::ccBoss0000 */
    uint64_t unk_0088; /* 0x0088 w medium ccBoss0000::ccBoss0000 */
    uint64_t unk_0090; /* 0x0090 w medium ccBoss0000::ccBoss0000 */
    uint64_t unk_0098; /* 0x0098 rw low ccBoss0000::ccBoss0000 */
    uint8_t pad_00A0[0x10]; /* 0x00A0 */
    uint8_t unk_00B0[0xC0]; /* 0x00B0 r low ccBoss0000::ccBoss0000 */
    uint8_t unk_0170[0xA8]; /* 0x0170 r low ccBoss0000::ccBoss0000 */
    uint64_t unk_0218; /* 0x0218 w medium ccBoss0000::ccBoss0000 */
    uint8_t unk_0220[0x78]; /* 0x0220 r low ccBoss0000::ccBoss0000 */
    uint64_t unk_0298; /* 0x0298 w medium ccBoss0000::ccBoss0000 */
    uint32_t unk_02A0; /* 0x02A0 w medium ccBoss0000::ccBoss0000 */
    uint8_t pad_02A4[0x4]; /* 0x02A4 */
    uint8_t unk_02A8[0x90]; /* 0x02A8 r low ccBoss0000::ccBoss0000 */
    uint8_t unk_0338[0x78]; /* 0x0338 r low ccBoss0000::ccBoss0000 */
    uint64_t unk_03B0; /* 0x03B0 w medium ccBoss0000::ccBoss0000 */
    uint8_t unk_03B8[0xA0]; /* 0x03B8 r low ccBoss0000::ccBoss0000 */
    uint64_t unk_0458; /* 0x0458 rw low ccBoss0000::ccBoss0000 */
    uint8_t pad_0460[0x38]; /* trailing to 0x498 */
} ccBoss0000;
#pragma pack(pop)

static_assert(sizeof(ccBoss0000) == 0x498, "ccBoss0000 size");

static_assert(offsetof(ccBoss0000, unk_0080) == 0x0080, "ccBoss0000.unk_0080 offset");
static_assert(offsetof(ccBoss0000, unk_0088) == 0x0088, "ccBoss0000.unk_0088 offset");
static_assert(offsetof(ccBoss0000, unk_0090) == 0x0090, "ccBoss0000.unk_0090 offset");
static_assert(offsetof(ccBoss0000, unk_0098) == 0x0098, "ccBoss0000.unk_0098 offset");
static_assert(offsetof(ccBoss0000, unk_00B0) == 0x00B0, "ccBoss0000.unk_00B0 offset");
static_assert(offsetof(ccBoss0000, unk_0170) == 0x0170, "ccBoss0000.unk_0170 offset");
static_assert(offsetof(ccBoss0000, unk_0218) == 0x0218, "ccBoss0000.unk_0218 offset");
static_assert(offsetof(ccBoss0000, unk_0220) == 0x0220, "ccBoss0000.unk_0220 offset");
static_assert(offsetof(ccBoss0000, unk_0298) == 0x0298, "ccBoss0000.unk_0298 offset");
static_assert(offsetof(ccBoss0000, unk_02A0) == 0x02A0, "ccBoss0000.unk_02A0 offset");
static_assert(offsetof(ccBoss0000, unk_02A8) == 0x02A8, "ccBoss0000.unk_02A8 offset");
static_assert(offsetof(ccBoss0000, unk_0338) == 0x0338, "ccBoss0000.unk_0338 offset");
static_assert(offsetof(ccBoss0000, unk_03B0) == 0x03B0, "ccBoss0000.unk_03B0 offset");
static_assert(offsetof(ccBoss0000, unk_03B8) == 0x03B8, "ccBoss0000.unk_03B8 offset");
static_assert(offsetof(ccBoss0000, unk_0458) == 0x0458, "ccBoss0000.unk_0458 offset");

/*
 * ccBoss0000EnemyState
 * Object size: unknown, >= 0xE0
 * Fields: 16 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000EnemyState {
    uint8_t pad_0000[0x54]; /* 0x0000 */
    uint32_t unk_0054; /* 0x0054 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_0058; /* 0x0058 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_005C; /* 0x005C w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_0060; /* 0x0060 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint8_t pad_0064[0x4]; /* 0x0064 */
    uint32_t unk_0068; /* 0x0068 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_006C; /* 0x006C w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint64_t unk_0070; /* 0x0070 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint8_t unk_0078[0x40]; /* 0x0078 r low ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint8_t unk_00B8[0xC]; /* 0x00B8 r low ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00C4; /* 0x00C4 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00C8; /* 0x00C8 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00CC; /* 0x00CC w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00D0; /* 0x00D0 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00D4; /* 0x00D4 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00D8; /* 0x00D8 w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
    uint32_t unk_00DC; /* 0x00DC w medium ccBoss0000EnemyState::ccBoss0000EnemyState */
} ccBoss0000EnemyState;
#pragma pack(pop)

/* ccBoss0000EnemyState size unknown, >= 0xE0 */

static_assert(offsetof(ccBoss0000EnemyState, unk_0054) == 0x0054, "ccBoss0000EnemyState.unk_0054 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_0058) == 0x0058, "ccBoss0000EnemyState.unk_0058 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_005C) == 0x005C, "ccBoss0000EnemyState.unk_005C offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_0060) == 0x0060, "ccBoss0000EnemyState.unk_0060 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_0068) == 0x0068, "ccBoss0000EnemyState.unk_0068 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_006C) == 0x006C, "ccBoss0000EnemyState.unk_006C offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_0070) == 0x0070, "ccBoss0000EnemyState.unk_0070 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_0078) == 0x0078, "ccBoss0000EnemyState.unk_0078 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00B8) == 0x00B8, "ccBoss0000EnemyState.unk_00B8 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00C4) == 0x00C4, "ccBoss0000EnemyState.unk_00C4 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00C8) == 0x00C8, "ccBoss0000EnemyState.unk_00C8 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00CC) == 0x00CC, "ccBoss0000EnemyState.unk_00CC offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00D0) == 0x00D0, "ccBoss0000EnemyState.unk_00D0 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00D4) == 0x00D4, "ccBoss0000EnemyState.unk_00D4 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00D8) == 0x00D8, "ccBoss0000EnemyState.unk_00D8 offset");
static_assert(offsetof(ccBoss0000EnemyState, unk_00DC) == 0x00DC, "ccBoss0000EnemyState.unk_00DC offset");

/*
 * ccBoss0000GameSequence
 * Object size: unknown, >= 0x88
 * Fields: 7 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000GameSequence {
    uint8_t pad_0000[0x54]; /* 0x0000 */
    uint32_t unk_0054; /* 0x0054 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
    uint64_t unk_0058; /* 0x0058 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
    uint32_t unk_0060; /* 0x0060 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
    uint8_t pad_0064[0x4]; /* 0x0064 */
    uint64_t unk_0068; /* 0x0068 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
    uint64_t unk_0070; /* 0x0070 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
    uint64_t unk_0078; /* 0x0078 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
    uint64_t unk_0080; /* 0x0080 w medium ccBoss0000GameSequence::ccBoss0000GameSequence */
} ccBoss0000GameSequence;
#pragma pack(pop)

/* ccBoss0000GameSequence size unknown, >= 0x88 */

static_assert(offsetof(ccBoss0000GameSequence, unk_0054) == 0x0054, "ccBoss0000GameSequence.unk_0054 offset");
static_assert(offsetof(ccBoss0000GameSequence, unk_0058) == 0x0058, "ccBoss0000GameSequence.unk_0058 offset");
static_assert(offsetof(ccBoss0000GameSequence, unk_0060) == 0x0060, "ccBoss0000GameSequence.unk_0060 offset");
static_assert(offsetof(ccBoss0000GameSequence, unk_0068) == 0x0068, "ccBoss0000GameSequence.unk_0068 offset");
static_assert(offsetof(ccBoss0000GameSequence, unk_0070) == 0x0070, "ccBoss0000GameSequence.unk_0070 offset");
static_assert(offsetof(ccBoss0000GameSequence, unk_0078) == 0x0078, "ccBoss0000GameSequence.unk_0078 offset");
static_assert(offsetof(ccBoss0000GameSequence, unk_0080) == 0x0080, "ccBoss0000GameSequence.unk_0080 offset");

/*
 * ccBoss0000Player
 * Object size: 0xB038 (45112 bytes)
 * Fields: 53 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000Player {
    uint8_t pad_0000[0xB4]; /* 0x0000 */
    uint64_t unk_00B4; /* 0x00B4 r medium ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_00BC; /* 0x00BC r medium ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t pad_00C0[0x98]; /* 0x00C0 */
    uint32_t unk_0158; /* 0x0158 w high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_02 */
    uint8_t pad_015C[0xA4]; /* 0x015C */
    uint64_t unk_0200; /* 0x0200 r low ccBoss0000Player::InitializeParam */
    uint8_t pad_0208[0x8]; /* 0x0208 */
    uint8_t unk_0210[0x230]; /* 0x0210 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t unk_0440[0x40]; /* 0x0440 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t unk_0480[0x56C]; /* 0x0480 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_09EC; /* 0x09EC r medium ccBoss0000Player::PostCtrlImpl */
    uint8_t pad_09F0[0xC]; /* 0x09F0 */
    uint32_t unk_09FC; /* 0x09FC r medium ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t pad_0A00[0x2040]; /* 0x0A00 */
    uint8_t unk_2A40[0x280]; /* 0x2A40 r low ccBoss0000Player::_Initialize */
    uint8_t unk_2CC0[0x400]; /* 0x2CC0 r low ccBoss0000Player::PostCtrlImpl */
    uint8_t unk_30C0[0x500]; /* 0x30C0 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t unk_35C0[0x40]; /* 0x35C0 r low ccBoss0000Player::InitializeParam */
    uint8_t unk_3600[0x340]; /* 0x3600 r low ccBoss0000Player::_Finalize */
    uint8_t unk_3940[0x140]; /* 0x3940 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t unk_3A80[0x140]; /* 0x3A80 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t unk_3BC0[0x40]; /* 0x3BC0 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t unk_3C00[0x80]; /* 0x3C00 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t unk_3C80[0x3C0]; /* 0x3C80 r low ccBoss0000Player::InitializeParam */
    uint8_t unk_4040[0x5C0]; /* 0x4040 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_04 */
    uint8_t unk_4600[0xC00]; /* 0x4600 r low ccBoss0000Player::InitializeParam */
    uint8_t unk_5200[0x2DF4]; /* 0x5200 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint64_t unk_7FF4; /* 0x7FF4 rw low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint32_t unk_7FFC; /* 0x7FFC w medium ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_8000[0x1F0]; /* 0x8000 */
    uint64_t unk_81F0; /* 0x81F0 r low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_03 */
    uint8_t pad_81F8[0x64]; /* 0x81F8 */
    uint32_t unk_825C; /* 0x825C r medium ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_8260; /* 0x8260 w medium ccBoss0000Player::InitializeParam */
    uint8_t pad_8264[0x2044]; /* 0x8264 */
    uint32_t unk_A2A8; /* 0xA2A8 w high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint8_t pad_A2AC[0x68]; /* 0xA2AC */
    uint32_t unk_A314; /* 0xA314 r medium ccBoss0000Player::PostCtrlImpl */
    uint8_t pad_A318[0x7EC]; /* 0xA318 */
    uint32_t unk_AB04; /* 0xAB04 w medium ccBoss0000Player::InitializeParam */
    uint8_t pad_AB08[0x4B0]; /* 0xAB08 */
    uint32_t unk_AFB8; /* 0xAFB8 rw medium ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFBC; /* 0xAFBC rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint64_t unk_AFC0; /* 0xAFC0 rw low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFC8; /* 0xAFC8 rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint64_t unk_AFCC; /* 0xAFCC rw low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFD4; /* 0xAFD4 w high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFD8; /* 0xAFD8 rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFDC; /* 0xAFDC rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFE0; /* 0xAFE0 w high ccBoss0000Player::PreCtrlImpl */
    uint32_t unk_AFE4; /* 0xAFE4 rw high ccBoss0000Player::PreCtrlImpl */
    uint64_t unk_AFE8; /* 0xAFE8 rw low ccBoss0000Player::PreCtrlImpl */
    uint32_t unk_AFF0; /* 0xAFF0 w high ccBoss0000Player::PreCtrlImpl */
    uint32_t unk_AFF4; /* 0xAFF4 rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFF8; /* 0xAFF8 rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_AFFC; /* 0xAFFC rw high ccBoss0000Player::InitializeParam */
    uint32_t unk_B000; /* 0xB000 rw high ccBoss0000Player::InitializeParam */
    uint8_t pad_B004[0x4]; /* 0xB004 */
    uint64_t unk_B008; /* 0xB008 rw high ccBoss0000Player::InitializeParam */
    uint64_t unk_B010; /* 0xB010 rw high ccBoss0000Player::InitializeParam */
    uint64_t unk_B018; /* 0xB018 rw high ccBoss0000Player::InitializeParam */
    uint32_t unk_B020; /* 0xB020 rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint64_t unk_B024; /* 0xB024 rw low ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_B02C; /* 0xB02C rw high ccBoss0000Player::CtrlAct_PL_ACT_BOSS_FUNC_00 */
    uint32_t unk_B030; /* 0xB030 w high ccBoss0000Player::InitializeParam */
    uint8_t pad_B034[0x4]; /* trailing to 0xB038 */
} ccBoss0000Player;
#pragma pack(pop)

static_assert(sizeof(ccBoss0000Player) == 0xB038, "ccBoss0000Player size");

static_assert(offsetof(ccBoss0000Player, unk_00B4) == 0x00B4, "ccBoss0000Player.unk_00B4 offset");
static_assert(offsetof(ccBoss0000Player, unk_00BC) == 0x00BC, "ccBoss0000Player.unk_00BC offset");
static_assert(offsetof(ccBoss0000Player, unk_0158) == 0x0158, "ccBoss0000Player.unk_0158 offset");
static_assert(offsetof(ccBoss0000Player, unk_0200) == 0x0200, "ccBoss0000Player.unk_0200 offset");
static_assert(offsetof(ccBoss0000Player, unk_0210) == 0x0210, "ccBoss0000Player.unk_0210 offset");
static_assert(offsetof(ccBoss0000Player, unk_0440) == 0x0440, "ccBoss0000Player.unk_0440 offset");
static_assert(offsetof(ccBoss0000Player, unk_0480) == 0x0480, "ccBoss0000Player.unk_0480 offset");
static_assert(offsetof(ccBoss0000Player, unk_09EC) == 0x09EC, "ccBoss0000Player.unk_09EC offset");
static_assert(offsetof(ccBoss0000Player, unk_09FC) == 0x09FC, "ccBoss0000Player.unk_09FC offset");
static_assert(offsetof(ccBoss0000Player, unk_2A40) == 0x2A40, "ccBoss0000Player.unk_2A40 offset");
static_assert(offsetof(ccBoss0000Player, unk_2CC0) == 0x2CC0, "ccBoss0000Player.unk_2CC0 offset");
static_assert(offsetof(ccBoss0000Player, unk_30C0) == 0x30C0, "ccBoss0000Player.unk_30C0 offset");
static_assert(offsetof(ccBoss0000Player, unk_35C0) == 0x35C0, "ccBoss0000Player.unk_35C0 offset");
static_assert(offsetof(ccBoss0000Player, unk_3600) == 0x3600, "ccBoss0000Player.unk_3600 offset");
static_assert(offsetof(ccBoss0000Player, unk_3940) == 0x3940, "ccBoss0000Player.unk_3940 offset");
static_assert(offsetof(ccBoss0000Player, unk_3A80) == 0x3A80, "ccBoss0000Player.unk_3A80 offset");
static_assert(offsetof(ccBoss0000Player, unk_3BC0) == 0x3BC0, "ccBoss0000Player.unk_3BC0 offset");
static_assert(offsetof(ccBoss0000Player, unk_3C00) == 0x3C00, "ccBoss0000Player.unk_3C00 offset");
static_assert(offsetof(ccBoss0000Player, unk_3C80) == 0x3C80, "ccBoss0000Player.unk_3C80 offset");
static_assert(offsetof(ccBoss0000Player, unk_4040) == 0x4040, "ccBoss0000Player.unk_4040 offset");
static_assert(offsetof(ccBoss0000Player, unk_4600) == 0x4600, "ccBoss0000Player.unk_4600 offset");
static_assert(offsetof(ccBoss0000Player, unk_5200) == 0x5200, "ccBoss0000Player.unk_5200 offset");
static_assert(offsetof(ccBoss0000Player, unk_7FF4) == 0x7FF4, "ccBoss0000Player.unk_7FF4 offset");
static_assert(offsetof(ccBoss0000Player, unk_7FFC) == 0x7FFC, "ccBoss0000Player.unk_7FFC offset");
static_assert(offsetof(ccBoss0000Player, unk_81F0) == 0x81F0, "ccBoss0000Player.unk_81F0 offset");
static_assert(offsetof(ccBoss0000Player, unk_825C) == 0x825C, "ccBoss0000Player.unk_825C offset");
static_assert(offsetof(ccBoss0000Player, unk_8260) == 0x8260, "ccBoss0000Player.unk_8260 offset");
static_assert(offsetof(ccBoss0000Player, unk_A2A8) == 0xA2A8, "ccBoss0000Player.unk_A2A8 offset");
static_assert(offsetof(ccBoss0000Player, unk_A314) == 0xA314, "ccBoss0000Player.unk_A314 offset");
static_assert(offsetof(ccBoss0000Player, unk_AB04) == 0xAB04, "ccBoss0000Player.unk_AB04 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFB8) == 0xAFB8, "ccBoss0000Player.unk_AFB8 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFBC) == 0xAFBC, "ccBoss0000Player.unk_AFBC offset");
static_assert(offsetof(ccBoss0000Player, unk_AFC0) == 0xAFC0, "ccBoss0000Player.unk_AFC0 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFC8) == 0xAFC8, "ccBoss0000Player.unk_AFC8 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFCC) == 0xAFCC, "ccBoss0000Player.unk_AFCC offset");
static_assert(offsetof(ccBoss0000Player, unk_AFD4) == 0xAFD4, "ccBoss0000Player.unk_AFD4 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFD8) == 0xAFD8, "ccBoss0000Player.unk_AFD8 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFDC) == 0xAFDC, "ccBoss0000Player.unk_AFDC offset");
static_assert(offsetof(ccBoss0000Player, unk_AFE0) == 0xAFE0, "ccBoss0000Player.unk_AFE0 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFE4) == 0xAFE4, "ccBoss0000Player.unk_AFE4 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFE8) == 0xAFE8, "ccBoss0000Player.unk_AFE8 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFF0) == 0xAFF0, "ccBoss0000Player.unk_AFF0 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFF4) == 0xAFF4, "ccBoss0000Player.unk_AFF4 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFF8) == 0xAFF8, "ccBoss0000Player.unk_AFF8 offset");
static_assert(offsetof(ccBoss0000Player, unk_AFFC) == 0xAFFC, "ccBoss0000Player.unk_AFFC offset");
static_assert(offsetof(ccBoss0000Player, unk_B000) == 0xB000, "ccBoss0000Player.unk_B000 offset");
static_assert(offsetof(ccBoss0000Player, unk_B008) == 0xB008, "ccBoss0000Player.unk_B008 offset");
static_assert(offsetof(ccBoss0000Player, unk_B010) == 0xB010, "ccBoss0000Player.unk_B010 offset");
static_assert(offsetof(ccBoss0000Player, unk_B018) == 0xB018, "ccBoss0000Player.unk_B018 offset");
static_assert(offsetof(ccBoss0000Player, unk_B020) == 0xB020, "ccBoss0000Player.unk_B020 offset");
static_assert(offsetof(ccBoss0000Player, unk_B024) == 0xB024, "ccBoss0000Player.unk_B024 offset");
static_assert(offsetof(ccBoss0000Player, unk_B02C) == 0xB02C, "ccBoss0000Player.unk_B02C offset");
static_assert(offsetof(ccBoss0000Player, unk_B030) == 0xB030, "ccBoss0000Player.unk_B030 offset");

/*
 * ccBoss0000Enemy
 * Object size: 0xB1F0 (45552 bytes)
 * Fields: 58 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000Enemy {
    uint8_t pad_0000[0xC0]; /* 0x0000 */
    uint8_t unk_00C0[0x3C0]; /* 0x00C0 r low ccBoss0000Enemy::InitializeGameObject */
    uint8_t unk_0480[0x2B8]; /* 0x0480 r low ccBoss0000Enemy::IsInsideCircle */
    uint32_t unk_0738; /* 0x0738 w medium ccBoss0000Enemy::InitializeGameObject */
    uint32_t unk_073C; /* 0x073C w medium ccBoss0000Enemy::InitializeGameObject */
    uint8_t pad_0740[0x29C]; /* 0x0740 */
    uint32_t unk_09DC; /* 0x09DC r medium ccBoss0000Enemy::Update */
    uint8_t pad_09E0[0x2320]; /* 0x09E0 */
    uint8_t unk_2D00[0x40]; /* 0x2D00 r low ccBoss0000Enemy::UpdateDamage */
    uint8_t unk_2D40[0x880]; /* 0x2D40 r low ccBoss0000Enemy::UpdateDamage */
    uint8_t unk_35C0[0x40]; /* 0x35C0 r low ccBoss0000Enemy::_Initialize */
    uint8_t unk_3600[0xD00]; /* 0x3600 r low ccBoss0000Enemy::_Finalize */
    uint8_t unk_4300[0x1F80]; /* 0x4300 r low ccBoss0000Enemy::Update */
    uint8_t unk_6280[0x380]; /* 0x6280 r low ccBoss0000Enemy::Update */
    uint8_t unk_6600[0x19C0]; /* 0x6600 r low ccBoss0000Enemy::UpdateDamage */
    uint64_t unk_7FC0; /* 0x7FC0 rw high ccBoss0000Enemy::_Finalize */
    uint8_t pad_7FC8[0x8]; /* 0x7FC8 */
    uint64_t unk_7FD0; /* 0x7FD0 rw high ccBoss0000Enemy::Update */
    uint64_t unk_7FD8; /* 0x7FD8 rw high ccBoss0000Enemy::_Finalize */
    uint64_t unk_7FE0; /* 0x7FE0 rw high ccBoss0000Enemy::_Finalize */
    uint32_t unk_7FE8; /* 0x7FE8 w medium ccBoss0000Enemy::_Initialize */
    uint8_t pad_7FEC[0x1C]; /* 0x7FEC */
    uint64_t unk_8008; /* 0x8008 r low ccBoss0000Enemy::UpdateDamage */
    uint64_t unk_8010; /* 0x8010 r medium ccBoss0000Enemy::UpdateDamage */
    uint8_t pad_8018[0x20]; /* 0x8018 */
    uint8_t unk_8038[0x10]; /* 0x8038 r low ccBoss0000Enemy::UpdateDamage */
    uint64_t unk_8048; /* 0x8048 r medium ccBoss0000Enemy::UpdateDamage */
    uint32_t unk_8050; /* 0x8050 r medium ccBoss0000Enemy::UpdateDamage */
    uint32_t unk_8054; /* 0x8054 r medium ccBoss0000Enemy::UpdateDamage */
    uint8_t pad_8058[0x14]; /* 0x8058 */
    uint8_t unk_806C[0x10]; /* 0x806C r low ccBoss0000Enemy::UpdateDamage */
    uint32_t unk_807C; /* 0x807C r medium ccBoss0000Enemy::UpdateDamage */
    uint8_t pad_8080[0x78]; /* 0x8080 */
    uint32_t unk_80F8; /* 0x80F8 r medium ccBoss0000Enemy::UpdateDamage */
    uint8_t pad_80FC[0x2EBC]; /* 0x80FC */
    uint64_t unk_AFB8; /* 0xAFB8 r low ccBoss0000Enemy::Update */
    uint64_t unk_AFC0; /* 0xAFC0 r medium ccBoss0000Enemy::Update */
    uint64_t unk_AFC8; /* 0xAFC8 rw low ccBoss0000Enemy::Update */
    uint8_t pad_AFD0[0xC]; /* 0xAFD0 */
    uint8_t unk_AFDC[0x44]; /* 0xAFDC r low ccBoss0000Enemy::Update */
    uint8_t unk_B020[0x54]; /* 0xB020 r low ccBoss0000Enemy::Update */
    uint32_t unk_B074; /* 0xB074 w high ccBoss0000Enemy::UpdateDamage */
    uint8_t pad_B078[0x8]; /* 0xB078 */
    uint32_t unk_B080; /* 0xB080 w high ccBoss0000Enemy::UpdateDamage */
    uint8_t pad_B084[0x24]; /* 0xB084 */
    uint8_t unk_B0A8[0x50]; /* 0xB0A8 r low ccBoss0000Enemy::Update */
    uint32_t unk_B0F8; /* 0xB0F8 r low ccBoss0000Enemy::Update */
    uint32_t unk_B0FC; /* 0xB0FC w high ccBoss0000Enemy::ChangeArea */
    uint8_t pad_B100[0x8]; /* 0xB100 */
    uint32_t unk_B108; /* 0xB108 w high ccBoss0000Enemy::ChangeArea */
    uint8_t pad_B10C[0x4]; /* 0xB10C */
    uint32_t unk_B110; /* 0xB110 r medium ccBoss0000Enemy::Update */
    uint8_t pad_B114[0xC]; /* 0xB114 */
    uint8_t unk_B120[0x64]; /* 0xB120 r low ccBoss0000Enemy::ChangeArea */
    uint32_t unk_B184; /* 0xB184 rw medium ccBoss0000Enemy::UpdateDamage */
    uint32_t unk_B188; /* 0xB188 w medium ccBoss0000Enemy::ccBoss0000Enemy */
    uint32_t unk_B18C; /* 0xB18C w medium ccBoss0000Enemy::ccBoss0000Enemy */
    uint32_t unk_B190; /* 0xB190 w medium ccBoss0000Enemy::ccBoss0000Enemy */
    uint32_t unk_B194; /* 0xB194 rw high ccBoss0000Enemy::Update */
    uint8_t unk_B198[0xC]; /* 0xB198 r low ccBoss0000Enemy::ccBoss0000Enemy */
    uint8_t unk_B1A4[0xC]; /* 0xB1A4 r low ccBoss0000Enemy::ccBoss0000Enemy */
    uint64_t unk_B1B0; /* 0xB1B0 w medium ccBoss0000Enemy::ccBoss0000Enemy */
    uint64_t unk_B1B8; /* 0xB1B8 r low ccBoss0000Enemy::Update */
    uint32_t unk_B1C0; /* 0xB1C0 r low ccBoss0000Enemy::Update */
    uint64_t unk_B1C4; /* 0xB1C4 rw low ccBoss0000Enemy::Update */
    uint32_t unk_B1CC; /* 0xB1CC w medium ccBoss0000Enemy::Update */
    uint64_t unk_B1D0; /* 0xB1D0 r low ccBoss0000Enemy::Update */
    uint32_t unk_B1D8; /* 0xB1D8 w high ccBoss0000Enemy::Update */
    uint32_t unk_B1DC; /* 0xB1DC rw low ccBoss0000Enemy::UpdateDamage */
    uint32_t unk_B1E0; /* 0xB1E0 rw high ccBoss0000Enemy::UpdateDamage */
    uint32_t unk_B1E4; /* 0xB1E4 w low ccBoss0000Enemy::Update */
    uint32_t unk_B1E8; /* 0xB1E8 rw high ccBoss0000Enemy::Update */
    uint32_t unk_B1EC; /* 0xB1EC w medium ccBoss0000Enemy::ccBoss0000Enemy */
} ccBoss0000Enemy;
#pragma pack(pop)

static_assert(sizeof(ccBoss0000Enemy) == 0xB1F0, "ccBoss0000Enemy size");

static_assert(offsetof(ccBoss0000Enemy, unk_00C0) == 0x00C0, "ccBoss0000Enemy.unk_00C0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_0480) == 0x0480, "ccBoss0000Enemy.unk_0480 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_0738) == 0x0738, "ccBoss0000Enemy.unk_0738 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_073C) == 0x073C, "ccBoss0000Enemy.unk_073C offset");
static_assert(offsetof(ccBoss0000Enemy, unk_09DC) == 0x09DC, "ccBoss0000Enemy.unk_09DC offset");
static_assert(offsetof(ccBoss0000Enemy, unk_2D00) == 0x2D00, "ccBoss0000Enemy.unk_2D00 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_2D40) == 0x2D40, "ccBoss0000Enemy.unk_2D40 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_35C0) == 0x35C0, "ccBoss0000Enemy.unk_35C0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_3600) == 0x3600, "ccBoss0000Enemy.unk_3600 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_4300) == 0x4300, "ccBoss0000Enemy.unk_4300 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_6280) == 0x6280, "ccBoss0000Enemy.unk_6280 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_6600) == 0x6600, "ccBoss0000Enemy.unk_6600 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_7FC0) == 0x7FC0, "ccBoss0000Enemy.unk_7FC0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_7FD0) == 0x7FD0, "ccBoss0000Enemy.unk_7FD0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_7FD8) == 0x7FD8, "ccBoss0000Enemy.unk_7FD8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_7FE0) == 0x7FE0, "ccBoss0000Enemy.unk_7FE0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_7FE8) == 0x7FE8, "ccBoss0000Enemy.unk_7FE8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_8008) == 0x8008, "ccBoss0000Enemy.unk_8008 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_8010) == 0x8010, "ccBoss0000Enemy.unk_8010 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_8038) == 0x8038, "ccBoss0000Enemy.unk_8038 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_8048) == 0x8048, "ccBoss0000Enemy.unk_8048 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_8050) == 0x8050, "ccBoss0000Enemy.unk_8050 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_8054) == 0x8054, "ccBoss0000Enemy.unk_8054 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_806C) == 0x806C, "ccBoss0000Enemy.unk_806C offset");
static_assert(offsetof(ccBoss0000Enemy, unk_807C) == 0x807C, "ccBoss0000Enemy.unk_807C offset");
static_assert(offsetof(ccBoss0000Enemy, unk_80F8) == 0x80F8, "ccBoss0000Enemy.unk_80F8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_AFB8) == 0xAFB8, "ccBoss0000Enemy.unk_AFB8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_AFC0) == 0xAFC0, "ccBoss0000Enemy.unk_AFC0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_AFC8) == 0xAFC8, "ccBoss0000Enemy.unk_AFC8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_AFDC) == 0xAFDC, "ccBoss0000Enemy.unk_AFDC offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B020) == 0xB020, "ccBoss0000Enemy.unk_B020 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B074) == 0xB074, "ccBoss0000Enemy.unk_B074 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B080) == 0xB080, "ccBoss0000Enemy.unk_B080 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B0A8) == 0xB0A8, "ccBoss0000Enemy.unk_B0A8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B0F8) == 0xB0F8, "ccBoss0000Enemy.unk_B0F8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B0FC) == 0xB0FC, "ccBoss0000Enemy.unk_B0FC offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B108) == 0xB108, "ccBoss0000Enemy.unk_B108 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B110) == 0xB110, "ccBoss0000Enemy.unk_B110 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B120) == 0xB120, "ccBoss0000Enemy.unk_B120 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B184) == 0xB184, "ccBoss0000Enemy.unk_B184 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B188) == 0xB188, "ccBoss0000Enemy.unk_B188 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B18C) == 0xB18C, "ccBoss0000Enemy.unk_B18C offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B190) == 0xB190, "ccBoss0000Enemy.unk_B190 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B194) == 0xB194, "ccBoss0000Enemy.unk_B194 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B198) == 0xB198, "ccBoss0000Enemy.unk_B198 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1A4) == 0xB1A4, "ccBoss0000Enemy.unk_B1A4 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1B0) == 0xB1B0, "ccBoss0000Enemy.unk_B1B0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1B8) == 0xB1B8, "ccBoss0000Enemy.unk_B1B8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1C0) == 0xB1C0, "ccBoss0000Enemy.unk_B1C0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1C4) == 0xB1C4, "ccBoss0000Enemy.unk_B1C4 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1CC) == 0xB1CC, "ccBoss0000Enemy.unk_B1CC offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1D0) == 0xB1D0, "ccBoss0000Enemy.unk_B1D0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1D8) == 0xB1D8, "ccBoss0000Enemy.unk_B1D8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1DC) == 0xB1DC, "ccBoss0000Enemy.unk_B1DC offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1E0) == 0xB1E0, "ccBoss0000Enemy.unk_B1E0 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1E4) == 0xB1E4, "ccBoss0000Enemy.unk_B1E4 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1E8) == 0xB1E8, "ccBoss0000Enemy.unk_B1E8 offset");
static_assert(offsetof(ccBoss0000Enemy, unk_B1EC) == 0xB1EC, "ccBoss0000Enemy.unk_B1EC offset");

/* ============================================================
 * Batch 3: additional s3Boss00 classes (state_surface)
 * Generated 2026-10-19 — INFERRED, no runtime confirmation
 * ============================================================ */


/*
 * ccSceneBoss0010: no instance state
 * Evidence: state_surface returned no fields
 */


/*
 * ccSceneBoss0000
 * Object size: size unknown
 * Fields: 2 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccSceneBoss0000 {
    uint8_t pad_0000[0x308]; /* 0x0000 */
    uint8_t unk_0308[0x78]; /* 0x0308 r low  */
    uint64_t unk_0380; /* 0x0380 r medium  */
} ccSceneBoss0000;
#pragma pack(pop)


static_assert(offsetof(ccSceneBoss0000, unk_0308) == 0x0308, "ccSceneBoss0000.unk_0308 offset");
static_assert(offsetof(ccSceneBoss0000, unk_0380) == 0x0380, "ccSceneBoss0000.unk_0380 offset");


/*
 * ccBoss0000Mob
 * Object size: size unknown
 * Fields: 39 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000Mob {
    uint8_t pad_0000[0x90]; /* 0x0000 */
    uint64_t unk_0090; /* 0x0090 r low  */
    uint8_t pad_0098[0x38]; /* 0x0098 */
    uint32_t unk_00D0; /* 0x00D0 r medium  */
    uint8_t pad_00D4[0x4]; /* 0x00D4 */
    uint64_t unk_00D8; /* 0x00D8 r medium  */
    uint32_t unk_00E0; /* 0x00E0 r medium  */
    uint32_t unk_00E4; /* 0x00E4 r medium  */
    uint32_t unk_00E8; /* 0x00E8 r medium  */
    uint32_t unk_00EC; /* 0x00EC r medium  */
    uint32_t unk_00F0; /* 0x00F0 r medium  */
    uint8_t pad_00F4[0x4]; /* 0x00F4 */
    uint32_t unk_00F8; /* 0x00F8 r medium  */
    uint32_t unk_00FC; /* 0x00FC r medium  */
    uint32_t unk_0100; /* 0x0100 r medium  */
    uint8_t unk_0104[0xC]; /* 0x0104 r low  */
    uint8_t unk_0110[0x40]; /* 0x0110 r low  */
    uint64_t unk_0150; /* 0x0150 r medium  */
    uint32_t unk_0158; /* 0x0158 r medium  */
    uint32_t unk_015C; /* 0x015C r medium  */
    uint8_t unk_0160[0xC]; /* 0x0160 r low  */
    uint8_t unk_016C[0xC]; /* 0x016C r low  */
    uint64_t unk_0178; /* 0x0178 r medium  */
    uint8_t unk_0180[0x10]; /* 0x0180 r low  */
    uint32_t unk_0190; /* 0x0190 r medium  */
    uint8_t unk_0194[0x100]; /* 0x0194 r low  */
    uint8_t unk_0294[0x100]; /* 0x0294 r low  */
    uint64_t unk_0394; /* 0x0394 r medium  */
    uint64_t unk_039C; /* 0x039C r medium  */
    uint64_t unk_03A4; /* 0x03A4 r medium  */
    uint64_t unk_03AC; /* 0x03AC r medium  */
    uint8_t pad_03B4[0x4]; /* 0x03B4 */
    uint64_t unk_03B8; /* 0x03B8 r medium  */
    uint32_t unk_03C0; /* 0x03C0 r medium  */
    uint32_t unk_03C4; /* 0x03C4 r medium  */
    uint32_t unk_03C8; /* 0x03C8 r medium  */
    uint8_t pad_03CC[0x4]; /* 0x03CC */
    uint8_t unk_03D0[0x30]; /* 0x03D0 r low  */
    uint64_t unk_0400; /* 0x0400 r medium  */
    uint64_t unk_0408; /* 0x0408 r medium  */
    uint64_t unk_0410; /* 0x0410 r medium  */
    uint32_t unk_0418; /* 0x0418 r medium  */
    uint8_t unk_041C[0xC]; /* 0x041C r low  */
    uint8_t unk_0428[0xC]; /* 0x0428 r low  */
    uint8_t unk_0434; /* 0x0434 r low  */
} ccBoss0000Mob;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000Mob, unk_0090) == 0x0090, "ccBoss0000Mob.unk_0090 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00D0) == 0x00D0, "ccBoss0000Mob.unk_00D0 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00D8) == 0x00D8, "ccBoss0000Mob.unk_00D8 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00E0) == 0x00E0, "ccBoss0000Mob.unk_00E0 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00E4) == 0x00E4, "ccBoss0000Mob.unk_00E4 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00E8) == 0x00E8, "ccBoss0000Mob.unk_00E8 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00EC) == 0x00EC, "ccBoss0000Mob.unk_00EC offset");
static_assert(offsetof(ccBoss0000Mob, unk_00F0) == 0x00F0, "ccBoss0000Mob.unk_00F0 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00F8) == 0x00F8, "ccBoss0000Mob.unk_00F8 offset");
static_assert(offsetof(ccBoss0000Mob, unk_00FC) == 0x00FC, "ccBoss0000Mob.unk_00FC offset");
static_assert(offsetof(ccBoss0000Mob, unk_0100) == 0x0100, "ccBoss0000Mob.unk_0100 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0104) == 0x0104, "ccBoss0000Mob.unk_0104 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0110) == 0x0110, "ccBoss0000Mob.unk_0110 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0150) == 0x0150, "ccBoss0000Mob.unk_0150 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0158) == 0x0158, "ccBoss0000Mob.unk_0158 offset");
static_assert(offsetof(ccBoss0000Mob, unk_015C) == 0x015C, "ccBoss0000Mob.unk_015C offset");
static_assert(offsetof(ccBoss0000Mob, unk_0160) == 0x0160, "ccBoss0000Mob.unk_0160 offset");
static_assert(offsetof(ccBoss0000Mob, unk_016C) == 0x016C, "ccBoss0000Mob.unk_016C offset");
static_assert(offsetof(ccBoss0000Mob, unk_0178) == 0x0178, "ccBoss0000Mob.unk_0178 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0180) == 0x0180, "ccBoss0000Mob.unk_0180 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0190) == 0x0190, "ccBoss0000Mob.unk_0190 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0194) == 0x0194, "ccBoss0000Mob.unk_0194 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0294) == 0x0294, "ccBoss0000Mob.unk_0294 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0394) == 0x0394, "ccBoss0000Mob.unk_0394 offset");
static_assert(offsetof(ccBoss0000Mob, unk_039C) == 0x039C, "ccBoss0000Mob.unk_039C offset");
static_assert(offsetof(ccBoss0000Mob, unk_03A4) == 0x03A4, "ccBoss0000Mob.unk_03A4 offset");
static_assert(offsetof(ccBoss0000Mob, unk_03AC) == 0x03AC, "ccBoss0000Mob.unk_03AC offset");
static_assert(offsetof(ccBoss0000Mob, unk_03B8) == 0x03B8, "ccBoss0000Mob.unk_03B8 offset");
static_assert(offsetof(ccBoss0000Mob, unk_03C0) == 0x03C0, "ccBoss0000Mob.unk_03C0 offset");
static_assert(offsetof(ccBoss0000Mob, unk_03C4) == 0x03C4, "ccBoss0000Mob.unk_03C4 offset");
static_assert(offsetof(ccBoss0000Mob, unk_03C8) == 0x03C8, "ccBoss0000Mob.unk_03C8 offset");
static_assert(offsetof(ccBoss0000Mob, unk_03D0) == 0x03D0, "ccBoss0000Mob.unk_03D0 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0400) == 0x0400, "ccBoss0000Mob.unk_0400 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0408) == 0x0408, "ccBoss0000Mob.unk_0408 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0410) == 0x0410, "ccBoss0000Mob.unk_0410 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0418) == 0x0418, "ccBoss0000Mob.unk_0418 offset");
static_assert(offsetof(ccBoss0000Mob, unk_041C) == 0x041C, "ccBoss0000Mob.unk_041C offset");
static_assert(offsetof(ccBoss0000Mob, unk_0428) == 0x0428, "ccBoss0000Mob.unk_0428 offset");
static_assert(offsetof(ccBoss0000Mob, unk_0434) == 0x0434, "ccBoss0000Mob.unk_0434 offset");


/*
 * ccBoss00OpeningManager: no instance state
 * Evidence: state_surface returned no fields
 */


/*
 * ccUiBoss00Opening: no instance state
 * Evidence: state_surface returned no fields
 */


/*
 * ccSceneBoss0010Root: no instance state
 * Evidence: state_surface returned no fields
 */


/*
 * ccBoss0000EffectBeam
 * Object size: size unknown
 * Fields: 5 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000EffectBeam {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint64_t unk_0098; /* 0x0098 r medium  */
    uint8_t unk_00A0[0xC]; /* 0x00A0 r low  */
    uint8_t unk_00AC[0xC]; /* 0x00AC r low  */
    uint32_t unk_00B8; /* 0x00B8 r medium  */
    uint8_t pad_00BC[0x4]; /* 0x00BC */
    uint64_t unk_00C0; /* 0x00C0 r medium  */
} ccBoss0000EffectBeam;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectBeam, unk_0098) == 0x0098, "ccBoss0000EffectBeam.unk_0098 offset");
static_assert(offsetof(ccBoss0000EffectBeam, unk_00A0) == 0x00A0, "ccBoss0000EffectBeam.unk_00A0 offset");
static_assert(offsetof(ccBoss0000EffectBeam, unk_00AC) == 0x00AC, "ccBoss0000EffectBeam.unk_00AC offset");
static_assert(offsetof(ccBoss0000EffectBeam, unk_00B8) == 0x00B8, "ccBoss0000EffectBeam.unk_00B8 offset");
static_assert(offsetof(ccBoss0000EffectBeam, unk_00C0) == 0x00C0, "ccBoss0000EffectBeam.unk_00C0 offset");


/*
 * ccBoss0000EventTriggerEffect
 * Object size: size unknown
 * Fields: 6 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000EventTriggerEffect {
    uint8_t pad_0000[0x54]; /* 0x0000 */
    uint32_t unk_0054; /* 0x0054 r medium  */
    uint64_t unk_0058; /* 0x0058 r medium  */
    uint32_t unk_0060; /* 0x0060 r medium  */
    uint8_t pad_0064[0x4]; /* 0x0064 */
    uint64_t unk_0068; /* 0x0068 r medium  */
    uint64_t unk_0070; /* 0x0070 r medium  */
    uint8_t unk_0078; /* 0x0078 r low  */
} ccBoss0000EventTriggerEffect;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EventTriggerEffect, unk_0054) == 0x0054, "ccBoss0000EventTriggerEffect.unk_0054 offset");
static_assert(offsetof(ccBoss0000EventTriggerEffect, unk_0058) == 0x0058, "ccBoss0000EventTriggerEffect.unk_0058 offset");
static_assert(offsetof(ccBoss0000EventTriggerEffect, unk_0060) == 0x0060, "ccBoss0000EventTriggerEffect.unk_0060 offset");
static_assert(offsetof(ccBoss0000EventTriggerEffect, unk_0068) == 0x0068, "ccBoss0000EventTriggerEffect.unk_0068 offset");
static_assert(offsetof(ccBoss0000EventTriggerEffect, unk_0070) == 0x0070, "ccBoss0000EventTriggerEffect.unk_0070 offset");
static_assert(offsetof(ccBoss0000EventTriggerEffect, unk_0078) == 0x0078, "ccBoss0000EventTriggerEffect.unk_0078 offset");


/*
 * ccBoss0000Camera
 * Object size: size unknown
 * Fields: 2 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000Camera {
    uint8_t pad_0000[0x6C]; /* 0x0000 */
    uint32_t unk_006C; /* 0x006C r medium  */
    uint8_t pad_0070[0x1D0]; /* 0x0070 */
    uint8_t unk_0240; /* 0x0240 r low  */
} ccBoss0000Camera;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000Camera, unk_006C) == 0x006C, "ccBoss0000Camera.unk_006C offset");
static_assert(offsetof(ccBoss0000Camera, unk_0240) == 0x0240, "ccBoss0000Camera.unk_0240 offset");


/*
 * ccBoss0000EffectAsh
 * Object size: size unknown
 * Fields: 1 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000EffectAsh {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint64_t unk_0098; /* 0x0098 r medium  */
} ccBoss0000EffectAsh;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectAsh, unk_0098) == 0x0098, "ccBoss0000EffectAsh.unk_0098 offset");


/*
 * ccBoss0000EffectBeamBlast
 * Object size: size unknown
 * Fields: 3 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000EffectBeamBlast {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint64_t unk_0098; /* 0x0098 r medium  */
    uint8_t unk_00A0[0x10]; /* 0x00A0 r low  */
    uint64_t unk_00B0; /* 0x00B0 r medium  */
} ccBoss0000EffectBeamBlast;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectBeamBlast, unk_0098) == 0x0098, "ccBoss0000EffectBeamBlast.unk_0098 offset");
static_assert(offsetof(ccBoss0000EffectBeamBlast, unk_00A0) == 0x00A0, "ccBoss0000EffectBeamBlast.unk_00A0 offset");
static_assert(offsetof(ccBoss0000EffectBeamBlast, unk_00B0) == 0x00B0, "ccBoss0000EffectBeamBlast.unk_00B0 offset");


/*
 * ccBoss0000EffectBuilding
 * Object size: size unknown
 * Fields: 10 (all INFERRED)
 */
#pragma pack(push, 1)
typedef struct ccBoss0000EffectBuilding {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint64_t unk_0098; /* 0x0098 r medium  */
    uint8_t unk_00A0[0xC]; /* 0x00A0 r low  */
    uint8_t unk_00AC[0x40]; /* 0x00AC r low  */
    uint8_t unk_00EC[0xC]; /* 0x00EC r low  */
    uint32_t unk_00F8; /* 0x00F8 r medium  */
    uint32_t unk_00FC; /* 0x00FC r medium  */
    uint64_t unk_0100; /* 0x0100 r medium  */
    uint64_t unk_0108; /* 0x0108 r medium  */
    uint32_t unk_0110; /* 0x0110 r medium  */
    uint32_t unk_0114; /* 0x0114 r medium  */
} ccBoss0000EffectBuilding;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectBuilding, unk_0098) == 0x0098, "ccBoss0000EffectBuilding.unk_0098 offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_00A0) == 0x00A0, "ccBoss0000EffectBuilding.unk_00A0 offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_00AC) == 0x00AC, "ccBoss0000EffectBuilding.unk_00AC offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_00EC) == 0x00EC, "ccBoss0000EffectBuilding.unk_00EC offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_00F8) == 0x00F8, "ccBoss0000EffectBuilding.unk_00F8 offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_00FC) == 0x00FC, "ccBoss0000EffectBuilding.unk_00FC offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_0100) == 0x0100, "ccBoss0000EffectBuilding.unk_0100 offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_0108) == 0x0108, "ccBoss0000EffectBuilding.unk_0108 offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_0110) == 0x0110, "ccBoss0000EffectBuilding.unk_0110 offset");
static_assert(offsetof(ccBoss0000EffectBuilding, unk_0114) == 0x0114, "ccBoss0000EffectBuilding.unk_0114 offset");




/* === Batch 4: Coverage expansion (2026-10-19) === */

#pragma pack(push, 1)
typedef struct ccBoss0000Bg {
    uint8_t pad_0000[0x60]; /* 0x0000 */
    uint64_t unk_0060; /* 0x0060 w medium  */
    uint64_t unk_0068; /* 0x0068 w medium  */
    uint64_t unk_0070; /* 0x0070 w medium  */
    uint64_t unk_0078; /* 0x0078 rw low  */
    uint8_t pad_0080[0x10]; /* 0x0080 */
    uint64_t unk_0090; /* 0x0090 w medium  */
    uint32_t unk_0098; /* 0x0098 w medium  */
    uint32_t unk_009C; /* 0x009C w medium  */
    uint8_t unk_00A0[0x10]; /* 0x00A0 r low  */
    uint64_t unk_00B0; /* 0x00B0 w medium  */
    uint32_t unk_00B8; /* 0x00B8 w medium  */
} ccBoss0000Bg;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000Bg, unk_0060) == 0x0060, "ccBoss0000Bg.unk_0060 offset");
static_assert(offsetof(ccBoss0000Bg, unk_0068) == 0x0068, "ccBoss0000Bg.unk_0068 offset");
static_assert(offsetof(ccBoss0000Bg, unk_0070) == 0x0070, "ccBoss0000Bg.unk_0070 offset");
static_assert(offsetof(ccBoss0000Bg, unk_0078) == 0x0078, "ccBoss0000Bg.unk_0078 offset");
static_assert(offsetof(ccBoss0000Bg, unk_0090) == 0x0090, "ccBoss0000Bg.unk_0090 offset");
static_assert(offsetof(ccBoss0000Bg, unk_0098) == 0x0098, "ccBoss0000Bg.unk_0098 offset");
static_assert(offsetof(ccBoss0000Bg, unk_009C) == 0x009C, "ccBoss0000Bg.unk_009C offset");
static_assert(offsetof(ccBoss0000Bg, unk_00A0) == 0x00A0, "ccBoss0000Bg.unk_00A0 offset");
static_assert(offsetof(ccBoss0000Bg, unk_00B0) == 0x00B0, "ccBoss0000Bg.unk_00B0 offset");
static_assert(offsetof(ccBoss0000Bg, unk_00B8) == 0x00B8, "ccBoss0000Bg.unk_00B8 offset");


#pragma pack(push, 1)
typedef struct ccBoss0000EventTrigger {
    uint8_t pad_0000[0x54]; /* 0x0000 */
    uint32_t unk_0054; /* 0x0054 w medium  */
    uint32_t unk_0058; /* 0x0058 w medium  */
    uint32_t unk_005C; /* 0x005C w medium  */
    uint32_t unk_0060; /* 0x0060 w medium  */
    uint8_t pad_0064[0x4]; /* 0x0064 */
    uint32_t unk_0068; /* 0x0068 w medium  */
    uint32_t unk_006C; /* 0x006C w medium  */
    uint8_t unk_0070[0x40]; /* 0x0070 r low  */
    uint64_t unk_00B0; /* 0x00B0 w medium  */
    uint8_t unk_00B8[0xC]; /* 0x00B8 r low  */
    uint8_t unk_00C4[0xC]; /* 0x00C4 r low  */
    uint8_t unk_00D0[0xC]; /* 0x00D0 r low  */
    uint32_t unk_00DC; /* 0x00DC w medium  */
    uint8_t unk_00E0[0x58]; /* 0x00E0 r low  */
    uint32_t unk_0138; /* 0x0138 w medium  */
    uint32_t unk_013C; /* 0x013C w medium  */
    uint8_t unk_0140[0xB8]; /* 0x0140 r low  */
    uint32_t unk_01F8; /* 0x01F8 w medium  */
} ccBoss0000EventTrigger;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EventTrigger, unk_0054) == 0x0054, "ccBoss0000EventTrigger.unk_0054 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_0058) == 0x0058, "ccBoss0000EventTrigger.unk_0058 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_005C) == 0x005C, "ccBoss0000EventTrigger.unk_005C offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_0060) == 0x0060, "ccBoss0000EventTrigger.unk_0060 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_0068) == 0x0068, "ccBoss0000EventTrigger.unk_0068 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_006C) == 0x006C, "ccBoss0000EventTrigger.unk_006C offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_0070) == 0x0070, "ccBoss0000EventTrigger.unk_0070 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_00B0) == 0x00B0, "ccBoss0000EventTrigger.unk_00B0 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_00B8) == 0x00B8, "ccBoss0000EventTrigger.unk_00B8 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_00C4) == 0x00C4, "ccBoss0000EventTrigger.unk_00C4 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_00D0) == 0x00D0, "ccBoss0000EventTrigger.unk_00D0 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_00DC) == 0x00DC, "ccBoss0000EventTrigger.unk_00DC offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_00E0) == 0x00E0, "ccBoss0000EventTrigger.unk_00E0 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_0138) == 0x0138, "ccBoss0000EventTrigger.unk_0138 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_013C) == 0x013C, "ccBoss0000EventTrigger.unk_013C offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_0140) == 0x0140, "ccBoss0000EventTrigger.unk_0140 offset");
static_assert(offsetof(ccBoss0000EventTrigger, unk_01F8) == 0x01F8, "ccBoss0000EventTrigger.unk_01F8 offset");


#pragma pack(push, 1)
typedef struct ccBoss0000EnemyCpuState {
    uint8_t pad_0000[0x54]; /* 0x0000 */
    uint32_t unk_0054; /* 0x0054 w medium  */
    uint64_t unk_0058; /* 0x0058 w medium  */
    uint32_t unk_0060; /* 0x0060 w medium  */
    uint8_t pad_0064[0x4]; /* 0x0064 */
    uint64_t unk_0068; /* 0x0068 w medium  */
    uint8_t pad_0070[0x8]; /* 0x0070 */
    uint8_t unk_0078; /* 0x0078 w medium  */
    uint8_t pad_0079[0x3]; /* 0x0079 */
    uint64_t unk_007C; /* 0x007C w medium  */
    uint32_t unk_0084; /* 0x0084 w medium  */
} ccBoss0000EnemyCpuState;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EnemyCpuState, unk_0054) == 0x0054, "ccBoss0000EnemyCpuState.unk_0054 offset");
static_assert(offsetof(ccBoss0000EnemyCpuState, unk_0058) == 0x0058, "ccBoss0000EnemyCpuState.unk_0058 offset");
static_assert(offsetof(ccBoss0000EnemyCpuState, unk_0060) == 0x0060, "ccBoss0000EnemyCpuState.unk_0060 offset");
static_assert(offsetof(ccBoss0000EnemyCpuState, unk_0068) == 0x0068, "ccBoss0000EnemyCpuState.unk_0068 offset");
static_assert(offsetof(ccBoss0000EnemyCpuState, unk_0078) == 0x0078, "ccBoss0000EnemyCpuState.unk_0078 offset");
static_assert(offsetof(ccBoss0000EnemyCpuState, unk_007C) == 0x007C, "ccBoss0000EnemyCpuState.unk_007C offset");
static_assert(offsetof(ccBoss0000EnemyCpuState, unk_0084) == 0x0084, "ccBoss0000EnemyCpuState.unk_0084 offset");


#pragma pack(push, 1)
typedef struct ccUiBoss00Target {
    uint8_t pad_0000[0x3C]; /* 0x0000 */
    uint32_t unk_003C; /* 0x003C rw high  */
    uint8_t pad_0040[0x40]; /* 0x0040 */
    uint64_t unk_0080; /* 0x0080 rw high  */
    uint64_t unk_0088; /* 0x0088 rw high  */
    uint64_t unk_0090; /* 0x0090 rw high  */
    uint64_t unk_0098; /* 0x0098 rw high  */
    uint8_t pad_00A0[0xE0]; /* 0x00A0 */
    uint8_t unk_0180; /* 0x0180 r low  */
} ccUiBoss00Target;
#pragma pack(pop)


static_assert(offsetof(ccUiBoss00Target, unk_003C) == 0x003C, "ccUiBoss00Target.unk_003C offset");
static_assert(offsetof(ccUiBoss00Target, unk_0080) == 0x0080, "ccUiBoss00Target.unk_0080 offset");
static_assert(offsetof(ccUiBoss00Target, unk_0088) == 0x0088, "ccUiBoss00Target.unk_0088 offset");
static_assert(offsetof(ccUiBoss00Target, unk_0090) == 0x0090, "ccUiBoss00Target.unk_0090 offset");
static_assert(offsetof(ccUiBoss00Target, unk_0098) == 0x0098, "ccUiBoss00Target.unk_0098 offset");
static_assert(offsetof(ccUiBoss00Target, unk_0180) == 0x0180, "ccUiBoss00Target.unk_0180 offset");


#pragma pack(push, 1)
typedef struct ccBoss0000RootObjects {
    uint8_t pad_0000[0xC0]; /* 0x0000 */
    uint8_t unk_00C0; /* 0x00C0 r low  */
} ccBoss0000RootObjects;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000RootObjects, unk_00C0) == 0x00C0, "ccBoss0000RootObjects.unk_00C0 offset");


#pragma pack(push, 1)
typedef struct ccBoss0000SupportLauncher {
    uint8_t pad_0000[0x90]; /* 0x0000 */
    uint64_t unk_0090; /* 0x0090 w medium  */
    uint8_t pad_0098[0x38]; /* 0x0098 */
    uint32_t unk_00D0; /* 0x00D0 w medium  */
    uint8_t pad_00D4[0x4]; /* 0x00D4 */
    uint64_t unk_00D8; /* 0x00D8 w medium  */
    uint32_t unk_00E0; /* 0x00E0 w medium  */
    uint64_t unk_00E4; /* 0x00E4 w medium  */
    uint32_t unk_00EC; /* 0x00EC w medium  */
    uint32_t unk_00F0; /* 0x00F0 w medium  */
    uint8_t pad_00F4[0x4]; /* 0x00F4 */
    uint64_t unk_00F8; /* 0x00F8 w medium  */
    uint64_t unk_0100; /* 0x0100 w medium  */
    uint8_t unk_0108; /* 0x0108 r low  */
} ccBoss0000SupportLauncher;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000SupportLauncher, unk_0090) == 0x0090, "ccBoss0000SupportLauncher.unk_0090 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00D0) == 0x00D0, "ccBoss0000SupportLauncher.unk_00D0 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00D8) == 0x00D8, "ccBoss0000SupportLauncher.unk_00D8 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00E0) == 0x00E0, "ccBoss0000SupportLauncher.unk_00E0 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00E4) == 0x00E4, "ccBoss0000SupportLauncher.unk_00E4 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00EC) == 0x00EC, "ccBoss0000SupportLauncher.unk_00EC offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00F0) == 0x00F0, "ccBoss0000SupportLauncher.unk_00F0 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_00F8) == 0x00F8, "ccBoss0000SupportLauncher.unk_00F8 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_0100) == 0x0100, "ccBoss0000SupportLauncher.unk_0100 offset");
static_assert(offsetof(ccBoss0000SupportLauncher, unk_0108) == 0x0108, "ccBoss0000SupportLauncher.unk_0108 offset");


#pragma pack(push, 1)
typedef struct ccBoss0000EffectEnemyCoord {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint64_t unk_0098; /* 0x0098 w medium  */
    uint8_t unk_00A0[0x38]; /* 0x00A0 r low  */
    uint8_t unk_00D8[0x40]; /* 0x00D8 r low  */
    uint32_t unk_0118; /* 0x0118 w medium  */
    uint32_t unk_011C; /* 0x011C w medium  */
} ccBoss0000EffectEnemyCoord;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectEnemyCoord, unk_0098) == 0x0098, "ccBoss0000EffectEnemyCoord.unk_0098 offset");
static_assert(offsetof(ccBoss0000EffectEnemyCoord, unk_00A0) == 0x00A0, "ccBoss0000EffectEnemyCoord.unk_00A0 offset");
static_assert(offsetof(ccBoss0000EffectEnemyCoord, unk_00D8) == 0x00D8, "ccBoss0000EffectEnemyCoord.unk_00D8 offset");
static_assert(offsetof(ccBoss0000EffectEnemyCoord, unk_0118) == 0x0118, "ccBoss0000EffectEnemyCoord.unk_0118 offset");
static_assert(offsetof(ccBoss0000EffectEnemyCoord, unk_011C) == 0x011C, "ccBoss0000EffectEnemyCoord.unk_011C offset");


#pragma pack(push, 1)
typedef struct ccBoss0000EffectMobAttack {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint32_t unk_0098; /* 0x0098 w medium  */
    uint8_t pad_009C[0x4]; /* 0x009C */
    uint64_t unk_00A0; /* 0x00A0 w medium  */
    uint8_t unk_00A8[0xC]; /* 0x00A8 r low  */
    uint8_t unk_00B4[0xC]; /* 0x00B4 r low  */
    uint32_t unk_00C0; /* 0x00C0 w medium  */
    uint8_t pad_00C4[0x4]; /* 0x00C4 */
    uint64_t unk_00C8; /* 0x00C8 w medium  */
} ccBoss0000EffectMobAttack;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectMobAttack, unk_0098) == 0x0098, "ccBoss0000EffectMobAttack.unk_0098 offset");
static_assert(offsetof(ccBoss0000EffectMobAttack, unk_00A0) == 0x00A0, "ccBoss0000EffectMobAttack.unk_00A0 offset");
static_assert(offsetof(ccBoss0000EffectMobAttack, unk_00A8) == 0x00A8, "ccBoss0000EffectMobAttack.unk_00A8 offset");
static_assert(offsetof(ccBoss0000EffectMobAttack, unk_00B4) == 0x00B4, "ccBoss0000EffectMobAttack.unk_00B4 offset");
static_assert(offsetof(ccBoss0000EffectMobAttack, unk_00C0) == 0x00C0, "ccBoss0000EffectMobAttack.unk_00C0 offset");
static_assert(offsetof(ccBoss0000EffectMobAttack, unk_00C8) == 0x00C8, "ccBoss0000EffectMobAttack.unk_00C8 offset");


#pragma pack(push, 1)
typedef struct ccBoss0000EffectStamp {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    uint64_t unk_0098; /* 0x0098 w medium  */
    uint8_t unk_00A0; /* 0x00A0 r low  */
} ccBoss0000EffectStamp;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000EffectStamp, unk_0098) == 0x0098, "ccBoss0000EffectStamp.unk_0098 offset");
static_assert(offsetof(ccBoss0000EffectStamp, unk_00A0) == 0x00A0, "ccBoss0000EffectStamp.unk_00A0 offset");


/* ========================================================================== */
/* Batch 5 — ccBoss0000SupportObj, ccBoss0000StageObject                      */
/* ========================================================================== */

/* size unknown, >= 0x98 (no allocator found; vtable refs at 0x140AAFD60/0x140AAFD68) */
#pragma pack(push, 1)
typedef struct ccBoss0000SupportObj {
    uint8_t pad_0000[0x54]; /* 0x0000 */
    uint32_t unk_0054; /* 0x0054 w medium StateSht */
    uint8_t pad_0058[0x8]; /* 0x0058 */
    uint32_t unk_0060; /* 0x0060 w medium StateSht */
    uint8_t pad_0064[0x4]; /* 0x0064 */
    float unk_0068; /* 0x0068 rw medium PostProcess */
    float unk_006C; /* 0x006C rw medium PostProcess */
    uint8_t pad_0070[0x8]; /* 0x0070 */
    uint8_t unk_0078[12]; /* 0x0078 r medium PostProcess Vector3 */
    uint8_t pad_0084[0x4]; /* 0x0084 */
    int64_t unk_0088; /* 0x0088 r medium StateSht/PostProcess ptr */
    int64_t unk_0090; /* 0x0090 rw medium EnterSht/StateSht/PostProcess ptr+vcall */
} ccBoss0000SupportObj;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000SupportObj, unk_0054) == 0x0054, "ccBoss0000SupportObj.unk_0054 offset");
static_assert(offsetof(ccBoss0000SupportObj, unk_0060) == 0x0060, "ccBoss0000SupportObj.unk_0060 offset");
static_assert(offsetof(ccBoss0000SupportObj, unk_0068) == 0x0068, "ccBoss0000SupportObj.unk_0068 offset");
static_assert(offsetof(ccBoss0000SupportObj, unk_006C) == 0x006C, "ccBoss0000SupportObj.unk_006C offset");
static_assert(offsetof(ccBoss0000SupportObj, unk_0078) == 0x0078, "ccBoss0000SupportObj.unk_0078 offset");
static_assert(offsetof(ccBoss0000SupportObj, unk_0088) == 0x0088, "ccBoss0000SupportObj.unk_0088 offset");
static_assert(offsetof(ccBoss0000SupportObj, unk_0090) == 0x0090, "ccBoss0000SupportObj.unk_0090 offset");


/* Inherits GameActor::Base; size unknown, >= 0xE8 (Create ctor receives param_1; vtable PTR_FUN_1409a7e48) */
#pragma pack(push, 1)
typedef struct ccBoss0000StageObject {
    uint8_t pad_0000[0x90]; /* 0x0000 GameActor::Base + own fields */
    int64_t unk_0090; /* 0x0090 w medium Initialize ptr */
    int64_t unk_0098; /* 0x0098 w medium Initialize passed-to-fun */
    uint8_t pad_00A0[0x28]; /* 0x00A0 */
    int32_t unk_00C8; /* 0x00C8 w medium Initialize/CollisionCallback */
    float unk_00CC; /* 0x00CC rw medium Update/CollisionCallback */
    int64_t unk_00D0; /* 0x00D0 w+r medium Initialize/Update ptr+vcall */
    uint8_t unk_00D8[8]; /* 0x00D8 rw medium Initialize/Update Vector3.xy */
    uint32_t unk_00E0; /* 0x00E0 w medium Initialize */
    int32_t unk_00E4; /* 0x00E4 rw medium Update/Initialize */
} ccBoss0000StageObject;
#pragma pack(pop)


static_assert(offsetof(ccBoss0000StageObject, unk_0090) == 0x0090, "ccBoss0000StageObject.unk_0090 offset");
static_assert(offsetof(ccBoss0000StageObject, unk_0098) == 0x0098, "ccBoss0000StageObject.unk_0098 offset");
static_assert(offsetof(ccBoss0000StageObject, unk_00C8) == 0x00C8, "ccBoss0000StageObject.unk_00C8 offset");
static_assert(offsetof(ccBoss0000StageObject, unk_00CC) == 0x00CC, "ccBoss0000StageObject.unk_00CC offset");
static_assert(offsetof(ccBoss0000StageObject, unk_00D0) == 0x00D0, "ccBoss0000StageObject.unk_00D0 offset");
static_assert(offsetof(ccBoss0000StageObject, unk_00D8) == 0x00D8, "ccBoss0000StageObject.unk_00D8 offset");
static_assert(offsetof(ccBoss0000StageObject, unk_00E0) == 0x00E0, "ccBoss0000StageObject.unk_00E0 offset");
static_assert(offsetof(ccBoss0000StageObject, unk_00E4) == 0x00E4, "ccBoss0000StageObject.unk_00E4 offset");


#endif /* S3_BOSS00_H */
