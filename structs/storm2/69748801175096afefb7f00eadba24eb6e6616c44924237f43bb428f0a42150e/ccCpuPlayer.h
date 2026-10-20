#ifndef CC_CPU_PLAYER_S2_H
#define CC_CPU_PLAYER_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* NARUTO STORM 2 (NSUNS2.exe) — ccCpuPlayer struct layout.
 * Object size: 0x1258 (4696 bytes)
 * Proven from ccPlayerLeader::RegisterCpu @ RVA 0x3A04D8:
 *   FUN_140580190(0x1258, "source\\ccPlayerLeader.cpp", 0x2f1)
 * All fields are INFERRED from static analysis, not CONFIRMED at runtime.
 */

#ifndef NUCC_VECTOR3_DEFINED
#define NUCC_VECTOR3_DEFINED
typedef struct { float x; float y; float z; } Nucc_Vector3;
#endif

typedef struct __attribute__((packed)) ccCpuPlayer {
    uint64_t vtable; /* 0x000 [high] ccCpuPlayer::ccCpuPlayer — PTR_FUN_1407f0850 */
    int32_t player_id; /* 0x008 [high] ccCpuPlayer::Update — *(undefined4 *)(param_1 + 8) */
    uint8_t pad_00c[4]; /* 0x00C [med] alignment */
    uint64_t parent_ptr; /* 0x010 [high] ccCpuPlayer::Initialize — back-ptr to ccPlayerLeader */
    uint64_t unk_018; /* 0x018 [med] ccCpuPlayer::Update — set in Update */
    int32_t think_action_idx; /* 0x020 [high] ccCpuPlayer::CtrlParallel — FUN_1403c38f0(param_1+0x20) */
    float timer_accum_024; /* 0x024 [high] s1 mapping — time delta accumulator */
    uint32_t unk_028; /* 0x028 [med] s1 mapping — cleared in Clear */
    uint32_t unk_02c; /* 0x02C [med] gap filler */
    float timer_accum_030; /* 0x030 [high] s1 mapping — second time accumulator */
    uint8_t pad_034[4]; /* 0x034 [med] gap to cooldowns */
    float cooldowns[51]; /* 0x038 [high] s1 mapping — sz=0xCC memset in Clear */
    float charge_timers[16]; /* 0x104 [high] s1 mapping — sz=0x40 memset in Clear */
    uint8_t pad_144[188]; /* 0x144 [med] misc scalars region */
    uint32_t ai_weight_0; /* 0x200 [high] s1 mapping — CtrlThink weight param */
    float ai_weight_1; /* 0x204 [high] s1 mapping — CtrlThink * 4.0 */
    float ai_weight_2; /* 0x208 [high] s1 mapping — CtrlThink multiplier */
    uint8_t pad_20c[4]; /* 0x20C [med] alignment */
    float react_cooldown_bc; /* 0x210 [high] s1 mapping — reaction cooldown */
    uint8_t subobj_214[6]; /* 0x214 [med] ccCpuPlayer::ccCpuPlayer — FUN_14031867c(param_1+0x214) */
    uint8_t subobj_21a[6]; /* 0x21A [med] ccCpuPlayer::ccCpuPlayer — FUN_14031867c(param_1+0x21a) */
    uint8_t pad_220[4]; /* 0x220 [med] gap */
    int32_t act_avail_224; /* 0x224 [high] s1 mapping — SelectAction type 2 */
    uint32_t act_avail_228; /* 0x228 [high] s1 mapping — SelectAction */
    int32_t act_avail_22c; /* 0x22C [high] s1 mapping — SelectAction */
    int32_t act_avail_230; /* 0x230 [high] s1 mapping — SelectAction type 0/3 */
    int32_t act_avail_234; /* 0x234 [high] s1 mapping — SelectAction type 4 */
    int32_t act_avail_238; /* 0x238 [high] s1 mapping — SelectAction type 5/6 */
    uint32_t act_avail_23c; /* 0x23C [high] s1 mapping — SelectAction */
    int32_t act_avail_240; /* 0x240 [high] s1 mapping — SelectAction type 1 */
    uint32_t unk_244; /* 0x244 [low] - */
    uint32_t unk_248; /* 0x248 [low] - */
    uint32_t unk_24c; /* 0x24C [low] - */
    uint32_t unk_250; /* 0x250 [low] - */
    uint8_t pad_254[8]; /* 0x254 [med] gap to pos cache */
    Nucc_Vector3 cached_pos; /* 0x25C [high] s1 mapping — from parent->pos */
    float hp_ratio; /* 0x268 [high] s1 mapping — hp/max_hp */
    float chakra_ratio; /* 0x26C [high] s1 mapping — chakra/max_chakra */
    float support_ratio_0; /* 0x270 [high] s1 mapping — support gauge ratio */
    float support_ratio_1; /* 0x274 [high] s1 mapping — support gauge ratio */
    float support_ratios[2]; /* 0x278 [high] s1 mapping — per-support gauge */
    float inv_hp_ratio; /* 0x280 [high] s1 mapping — 1.0 - hp_ratio */
    uint32_t player_condition; /* 0x284 [high] s1 mapping — ccGetPlayerCondition */
    uint32_t player_action_attr; /* 0x288 [high] s1 mapping — ccGetPlayerActionAttr */
    uint8_t pad_28c[4]; /* 0x28C [med] align to uint64 */
    uint64_t leader_ptr; /* 0x290 [high] s1 mapping — team leader pointer */
    Nucc_Vector3 leader_pos; /* 0x298 [high] s1 mapping — leader position */
    Nucc_Vector3 dir_to_leader; /* 0x2A4 [high] s1 mapping — normalized dir to leader */
    float dist_to_leader; /* 0x2B0 [high] s1 mapping — distance to leader */
    uint8_t pad_2b4[4]; /* 0x2B4 [med] gap */
    float abs_dist_2b8; /* 0x2B8 [high] s1 mapping — ABS<=100 in SelectAction */
    uint8_t pad_2bc[4]; /* 0x2BC [med] gap */
    float safe_dist_threshold; /* 0x2C0 [high] s1 mapping — default 1.0 */
    uint32_t unk_2c4; /* 0x2C4 [low] - */
    uint32_t unk_2c8; /* 0x2C8 [low] - */
    uint8_t subobj_2cc[284]; /* 0x2CC [med] s1 mapping — embedded obj FUN_14034976c init */
    uint8_t pad_3e8[84]; /* 0x3E8 [med] gap to vec_43c */
    Nucc_Vector3 vec_43c; /* 0x43C [high] s1 mapping — zero-init in Clear */
    uint8_t pad_448[16]; /* 0x448 [med] gap to support ptrs */
    uint64_t support_ptrs[2]; /* 0x458 [high] s1 mapping — ccPlayer::GetSupportPtr */
    uint64_t unk_468; /* 0x468 [low] - */
    uint8_t pad_470[8]; /* 0x470 [med] gap */
    uint64_t unk_478; /* 0x478 [high] s1 mapping — from parent+0x8f8 */
    uint64_t unk_480; /* 0x480 [low] - */
    uint64_t unk_488; /* 0x488 [low] - */
    uint64_t unk_490; /* 0x490 [low] - */
    uint64_t unk_498; /* 0x498 [low] - */
    uint8_t block_4a0[40]; /* 0x4A0 [low] gap to update_timers */
    float update_timers[6]; /* 0x4C8 [high] ccCpuPlayer::Update — pfVar7 loop decrement */
    int32_t unk_4e0; /* 0x4E0 [med] ccCpuPlayer::ccCpuPlayer — init to -1 */
    uint8_t strength_block[48]; /* 0x4E4 [high] ccCpuPlayer::ccCpuPlayer — memset region */
    int32_t ai_config_514; /* 0x514 [high] ccCpuPlayer::CheckAction — weight 0x10-0x12 */
    int32_t ai_config_518; /* 0x518 [high] ccCpuPlayer::CheckAction — weight 0x13-0x14 */
    int32_t ai_config_51c; /* 0x51C [high] ccCpuPlayer::CheckAction — weight 0x15-0x18 */
    uint8_t pad_520[16]; /* 0x520 [med] gap */
    int32_t ai_strength_pct; /* 0x530 [high] ccCpuPlayer::CheckAction — *0.01 weight */
    uint8_t situation_data_534[64]; /* 0x534 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_574[64]; /* 0x574 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_5b4[64]; /* 0x5B4 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_5f4[64]; /* 0x5F4 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_634[64]; /* 0x634 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_674[64]; /* 0x674 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_6b4[64]; /* 0x6B4 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint8_t situation_data_6f4[64]; /* 0x6F4 [high] ccCpuPlayer::ccCpuPlayer — FUN_140586500 init */
    uint64_t matrix_734_lo; /* 0x734 [high] ccCpuPlayer::ccCpuPlayer — FUN_140580a40 init */
    uint32_t matrix_73c_hi; /* 0x73C [high] ccCpuPlayer::ccCpuPlayer — upper 4 bytes */
    uint8_t pad_740[4]; /* 0x740 [med] gap */
    float dist_threshold_744; /* 0x744 [high] ccCpuPlayer::CheckAction — dist check base */
    uint64_t unk_748; /* 0x748 [med] ccCpuPlayer::ccCpuPlayer — param_1[0xe9]=0 */
    uint64_t unk_750; /* 0x750 [med] ccCpuPlayer::ccCpuPlayer — param_1[0xea]=0 */
    uint32_t flags_758; /* 0x758 [high] ccCpuPlayer::CheckAction — bitfield &0x200 */
    uint32_t flags_75c; /* 0x75C [high] ccCpuPlayer::CheckAction — bitfield &0x80,&0x10 */
    uint64_t matrix_760; /* 0x760 [high] ccCpuPlayer::ccCpuPlayer — FUN_140580a40 init */
    uint32_t matrix_768_hi; /* 0x768 [high] ccCpuPlayer::ccCpuPlayer — upper 4 bytes */
    float range_base_76c; /* 0x76C [high] ccCpuPlayer::CheckAction — base range */
    float range_bonus_770; /* 0x770 [high] ccCpuPlayer::CheckAction — added to dist check */
    uint64_t unk_774; /* 0x774 [med] ccCpuPlayer::ccCpuPlayer — init to 0 */
    uint64_t unk_77c; /* 0x77C [med] ccCpuPlayer::ccCpuPlayer — init to 0 */
    uint64_t unk_784; /* 0x784 [med] ccCpuPlayer::ccCpuPlayer — init to 0 */
    uint8_t action_entries_78c[640]; /* 0x78C [high] ccCpuPlayer::Update — 0x28-byte entries */
    uint8_t pad_a0c[1608]; /* 0xA0C [med] gap to CheckReaction region */
    int32_t action_avail_counts[8]; /* 0x1054 [high] ccCpuPlayer::CheckReaction — 8 ints checked >0 */
    float distance_1074; /* 0x1074 [high] ccCpuPlayer::CheckReaction — vs 600.0, 1500.0 */
    uint8_t pad_1078[32]; /* 0x1078 [med] gap to ptr region */
    float distance_1098; /* 0x1098 [high] ccCpuPlayer::CheckAction — alt distance */
    uint8_t pad_109c[4]; /* 0x109C [med] gap */
    uint64_t list_head_10a0; /* 0x10A0 [high] ccCpuPlayer::CheckReaction — linked list head */
    uint64_t list_sentinel_10a8; /* 0x10A8 [high] ccCpuPlayer::CheckReaction — non-null guard */
    uint8_t pad_10b0[24]; /* 0x10B0 [med] gap */
    uint32_t flags_10c8; /* 0x10C8 [high] ccCpuPlayer::CheckReaction — &0x100 modifies weight */
    uint8_t pad_10cc[4]; /* 0x10CC [med] gap */
    uint64_t list_head_10d0; /* 0x10D0 [high] ccCpuPlayer::CheckReaction — second list head */
    uint64_t list_sentinel_10d8; /* 0x10D8 [high] ccCpuPlayer::CheckReaction — second list guard */
    uint8_t pad_10e0[28]; /* 0x10E0 [med] gap */
    int32_t counter_10fc; /* 0x10FC [high] ccCpuPlayer::CheckAction — < 1 triggers action 0xf */
    int32_t threshold_1100; /* 0x1100 [high] ccCpuPlayer::CheckReaction — compared threshold */
    uint8_t pad_1104[4]; /* 0x1104 [med] gap */
    uint64_t task_list_end; /* 0x1108 [high] ccCpuPlayer::CheckAction — plVar2 = param_1+0x1108 */
    uint8_t task_history[328]; /* 0x1110 [high] ccCpuPlayer::CheckAction — 7 entries of 0x30 (truncated to fit 0x1258) */
} ccCpuPlayer;

static_assert(sizeof(ccCpuPlayer) == 0x1258, "ccCpuPlayer size must be 0x1258");

static_assert(offsetof(ccCpuPlayer, vtable) == 0x000, "vtable offset mismatch");
static_assert(offsetof(ccCpuPlayer, player_id) == 0x008, "player_id offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_00c) == 0x00C, "pad_00c offset mismatch");
static_assert(offsetof(ccCpuPlayer, parent_ptr) == 0x010, "parent_ptr offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_018) == 0x018, "unk_018 offset mismatch");
static_assert(offsetof(ccCpuPlayer, think_action_idx) == 0x020, "think_action_idx offset mismatch");
static_assert(offsetof(ccCpuPlayer, timer_accum_024) == 0x024, "timer_accum_024 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_028) == 0x028, "unk_028 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_02c) == 0x02C, "unk_02c offset mismatch");
static_assert(offsetof(ccCpuPlayer, timer_accum_030) == 0x030, "timer_accum_030 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_034) == 0x034, "pad_034 offset mismatch");
static_assert(offsetof(ccCpuPlayer, cooldowns) == 0x038, "cooldowns offset mismatch");
static_assert(offsetof(ccCpuPlayer, charge_timers) == 0x104, "charge_timers offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_144) == 0x144, "pad_144 offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_weight_0) == 0x200, "ai_weight_0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_weight_1) == 0x204, "ai_weight_1 offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_weight_2) == 0x208, "ai_weight_2 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_20c) == 0x20C, "pad_20c offset mismatch");
static_assert(offsetof(ccCpuPlayer, react_cooldown_bc) == 0x210, "react_cooldown_bc offset mismatch");
static_assert(offsetof(ccCpuPlayer, subobj_214) == 0x214, "subobj_214 offset mismatch");
static_assert(offsetof(ccCpuPlayer, subobj_21a) == 0x21A, "subobj_21a offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_220) == 0x220, "pad_220 offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_224) == 0x224, "act_avail_224 offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_228) == 0x228, "act_avail_228 offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_22c) == 0x22C, "act_avail_22c offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_230) == 0x230, "act_avail_230 offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_234) == 0x234, "act_avail_234 offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_238) == 0x238, "act_avail_238 offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_23c) == 0x23C, "act_avail_23c offset mismatch");
static_assert(offsetof(ccCpuPlayer, act_avail_240) == 0x240, "act_avail_240 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_244) == 0x244, "unk_244 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_248) == 0x248, "unk_248 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_24c) == 0x24C, "unk_24c offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_250) == 0x250, "unk_250 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_254) == 0x254, "pad_254 offset mismatch");
static_assert(offsetof(ccCpuPlayer, cached_pos) == 0x25C, "cached_pos offset mismatch");
static_assert(offsetof(ccCpuPlayer, hp_ratio) == 0x268, "hp_ratio offset mismatch");
static_assert(offsetof(ccCpuPlayer, chakra_ratio) == 0x26C, "chakra_ratio offset mismatch");
static_assert(offsetof(ccCpuPlayer, support_ratio_0) == 0x270, "support_ratio_0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, support_ratio_1) == 0x274, "support_ratio_1 offset mismatch");
static_assert(offsetof(ccCpuPlayer, support_ratios) == 0x278, "support_ratios offset mismatch");
static_assert(offsetof(ccCpuPlayer, inv_hp_ratio) == 0x280, "inv_hp_ratio offset mismatch");
static_assert(offsetof(ccCpuPlayer, player_condition) == 0x284, "player_condition offset mismatch");
static_assert(offsetof(ccCpuPlayer, player_action_attr) == 0x288, "player_action_attr offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_28c) == 0x28C, "pad_28c offset mismatch");
static_assert(offsetof(ccCpuPlayer, leader_ptr) == 0x290, "leader_ptr offset mismatch");
static_assert(offsetof(ccCpuPlayer, leader_pos) == 0x298, "leader_pos offset mismatch");
static_assert(offsetof(ccCpuPlayer, dir_to_leader) == 0x2A4, "dir_to_leader offset mismatch");
static_assert(offsetof(ccCpuPlayer, dist_to_leader) == 0x2B0, "dist_to_leader offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_2b4) == 0x2B4, "pad_2b4 offset mismatch");
static_assert(offsetof(ccCpuPlayer, abs_dist_2b8) == 0x2B8, "abs_dist_2b8 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_2bc) == 0x2BC, "pad_2bc offset mismatch");
static_assert(offsetof(ccCpuPlayer, safe_dist_threshold) == 0x2C0, "safe_dist_threshold offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_2c4) == 0x2C4, "unk_2c4 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_2c8) == 0x2C8, "unk_2c8 offset mismatch");
static_assert(offsetof(ccCpuPlayer, subobj_2cc) == 0x2CC, "subobj_2cc offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_3e8) == 0x3E8, "pad_3e8 offset mismatch");
static_assert(offsetof(ccCpuPlayer, vec_43c) == 0x43C, "vec_43c offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_448) == 0x448, "pad_448 offset mismatch");
static_assert(offsetof(ccCpuPlayer, support_ptrs) == 0x458, "support_ptrs offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_468) == 0x468, "unk_468 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_470) == 0x470, "pad_470 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_478) == 0x478, "unk_478 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_480) == 0x480, "unk_480 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_488) == 0x488, "unk_488 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_490) == 0x490, "unk_490 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_498) == 0x498, "unk_498 offset mismatch");
static_assert(offsetof(ccCpuPlayer, block_4a0) == 0x4A0, "block_4a0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, update_timers) == 0x4C8, "update_timers offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_4e0) == 0x4E0, "unk_4e0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, strength_block) == 0x4E4, "strength_block offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_config_514) == 0x514, "ai_config_514 offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_config_518) == 0x518, "ai_config_518 offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_config_51c) == 0x51C, "ai_config_51c offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_520) == 0x520, "pad_520 offset mismatch");
static_assert(offsetof(ccCpuPlayer, ai_strength_pct) == 0x530, "ai_strength_pct offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_534) == 0x534, "situation_data_534 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_574) == 0x574, "situation_data_574 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_5b4) == 0x5B4, "situation_data_5b4 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_5f4) == 0x5F4, "situation_data_5f4 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_634) == 0x634, "situation_data_634 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_674) == 0x674, "situation_data_674 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_6b4) == 0x6B4, "situation_data_6b4 offset mismatch");
static_assert(offsetof(ccCpuPlayer, situation_data_6f4) == 0x6F4, "situation_data_6f4 offset mismatch");
static_assert(offsetof(ccCpuPlayer, matrix_734_lo) == 0x734, "matrix_734_lo offset mismatch");
static_assert(offsetof(ccCpuPlayer, matrix_73c_hi) == 0x73C, "matrix_73c_hi offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_740) == 0x740, "pad_740 offset mismatch");
static_assert(offsetof(ccCpuPlayer, dist_threshold_744) == 0x744, "dist_threshold_744 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_748) == 0x748, "unk_748 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_750) == 0x750, "unk_750 offset mismatch");
static_assert(offsetof(ccCpuPlayer, flags_758) == 0x758, "flags_758 offset mismatch");
static_assert(offsetof(ccCpuPlayer, flags_75c) == 0x75C, "flags_75c offset mismatch");
static_assert(offsetof(ccCpuPlayer, matrix_760) == 0x760, "matrix_760 offset mismatch");
static_assert(offsetof(ccCpuPlayer, matrix_768_hi) == 0x768, "matrix_768_hi offset mismatch");
static_assert(offsetof(ccCpuPlayer, range_base_76c) == 0x76C, "range_base_76c offset mismatch");
static_assert(offsetof(ccCpuPlayer, range_bonus_770) == 0x770, "range_bonus_770 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_774) == 0x774, "unk_774 offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_77c) == 0x77C, "unk_77c offset mismatch");
static_assert(offsetof(ccCpuPlayer, unk_784) == 0x784, "unk_784 offset mismatch");
static_assert(offsetof(ccCpuPlayer, action_entries_78c) == 0x78C, "action_entries_78c offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_a0c) == 0xA0C, "pad_a0c offset mismatch");
static_assert(offsetof(ccCpuPlayer, action_avail_counts) == 0x1054, "action_avail_counts offset mismatch");
static_assert(offsetof(ccCpuPlayer, distance_1074) == 0x1074, "distance_1074 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_1078) == 0x1078, "pad_1078 offset mismatch");
static_assert(offsetof(ccCpuPlayer, distance_1098) == 0x1098, "distance_1098 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_109c) == 0x109C, "pad_109c offset mismatch");
static_assert(offsetof(ccCpuPlayer, list_head_10a0) == 0x10A0, "list_head_10a0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, list_sentinel_10a8) == 0x10A8, "list_sentinel_10a8 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_10b0) == 0x10B0, "pad_10b0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, flags_10c8) == 0x10C8, "flags_10c8 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_10cc) == 0x10CC, "pad_10cc offset mismatch");
static_assert(offsetof(ccCpuPlayer, list_head_10d0) == 0x10D0, "list_head_10d0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, list_sentinel_10d8) == 0x10D8, "list_sentinel_10d8 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_10e0) == 0x10E0, "pad_10e0 offset mismatch");
static_assert(offsetof(ccCpuPlayer, counter_10fc) == 0x10FC, "counter_10fc offset mismatch");
static_assert(offsetof(ccCpuPlayer, threshold_1100) == 0x1100, "threshold_1100 offset mismatch");
static_assert(offsetof(ccCpuPlayer, pad_1104) == 0x1104, "pad_1104 offset mismatch");
static_assert(offsetof(ccCpuPlayer, task_list_end) == 0x1108, "task_list_end offset mismatch");
static_assert(offsetof(ccCpuPlayer, task_history) == 0x1110, "task_history offset mismatch");

#endif /* CC_CPU_PLAYER_S2_H */
