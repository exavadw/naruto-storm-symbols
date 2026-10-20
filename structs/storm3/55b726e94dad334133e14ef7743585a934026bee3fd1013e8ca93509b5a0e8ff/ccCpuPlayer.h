#ifndef CC_CPU_PLAYER_S3_H
#define CC_CPU_PLAYER_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* NARUTO STORM 3 Full Burst HD (NSUNS3.exe 64-bit) — ccCpuPlayer struct layout.
 * Base class is abstract; no direct allocation. Subclass sizes from allocator:
 *   ccCpuPlayerLeader:      0x1438 (ccPlayerLeader::RegisterCpu @ RVA 0x550B84)
 *   ccBoss0401PlayerCpu:    0x13C0 (ccBoss0401::updateEnemyReinforcement @ RVA 0x2B0550)
 *   ccCpuPlayerGroupScript: 0x1340 (ccCreateCpuGroup @ RVA 0x389B90)
 * All fields are INFERRED from static analysis, not CONFIRMED at runtime.
 * Cross-referenced with s2 header (s2/ccCpuPlayer.h, size 0x1258).
 */

#ifndef NUCC_VECTOR3_DEFINED
#define NUCC_VECTOR3_DEFINED
typedef struct { float x; float y; float z; } Nucc_Vector3;
#endif

/* ---- ccCpuPlayer base (abstract, ends before subclass extensions) ---- */
typedef struct __attribute__((packed)) ccCpuPlayer_s3 {
    /* === Core identity (0x000–0x020) === */
    uint64_t vtable;              /* 0x000 [high] ctor RVA 0x4EB654 — PTR_FUN_1409894d8 */
    int32_t  player_id;           /* 0x008 [high] UpdateSituation — *(param_1+8)=0xffffffff in ctor */
    uint8_t  pad_00c[4];          /* 0x00C alignment */
    uint64_t parent_ptr;          /* 0x010 [high] Initialize — back-ptr to owner */
    uint64_t unk_018;             /* 0x018 [med] set in Update */
    int32_t  think_action_idx;    /* 0x020 [high] CtrlThink — FUN param_1+0x20 */

    /* === Timers & cooldowns (0x024–0x144) === */
    float    timer_accum_024;     /* 0x024 [high] s2 mapping — time delta accumulator */
    uint32_t unk_028;             /* 0x028 [med] s2 mapping */
    uint32_t unk_02c;             /* 0x02C gap filler */
    float    timer_accum_030;     /* 0x030 [high] s2 mapping — second accumulator */
    uint8_t  pad_034[4];          /* 0x034 gap to cooldowns */
    float    cooldowns[51];       /* 0x038 [high] s2 mapping — 51 floats, sz=0xCC */
    float    charge_timers[16];   /* 0x104 [high] s2 mapping — 16 floats, sz=0x40 */
    uint8_t  pad_144[188];        /* 0x144 misc scalars region */

    /* === AI weights & reaction (0x200–0x224) === */
    uint32_t ai_weight_0;         /* 0x200 [high] s2 mapping — CtrlThink weight */
    float    ai_weight_1;         /* 0x204 [high] s2 mapping — CtrlThink *4.0 */
    float    ai_weight_2;         /* 0x208 [high] s2 mapping — CtrlThink multiplier */
    uint8_t  pad_20c[4];          /* 0x20C alignment */
    float    react_cooldown_bc;   /* 0x210 [high] s2 mapping — reaction cooldown */
    uint8_t  subobj_214[6];       /* 0x214 [med] ctor — FUN_1403cbc04(param_1+0x214) equiv */
    uint8_t  subobj_21a[6];       /* 0x21A [med] ctor — second sub-object */
    uint8_t  pad_220[4];          /* 0x220 gap */

    /* === Action availability (0x224–0x254) === */
    int32_t  act_avail_224;       /* 0x224 [high] CheckAction/UpdateSituation — SelectAction type 2 */
    uint32_t act_avail_228;       /* 0x228 [high] CheckAction — *(param_1+0x228) */
    int32_t  act_avail_22c;       /* 0x22C [high] s2 mapping */
    int32_t  act_avail_230;       /* 0x230 [high] s2 mapping */
    int32_t  act_avail_234;       /* 0x234 [high] s2 mapping */
    int32_t  act_avail_238;       /* 0x238 [high] s2 mapping */
    uint32_t act_avail_23c;       /* 0x23C [high] s2 mapping */
    int32_t  act_avail_240;       /* 0x240 [high] s2 mapping */
    uint32_t unk_244;             /* 0x244 [low] */
    uint32_t unk_248;             /* 0x248 [low] */
    uint32_t unk_24c;             /* 0x24C [low] */
    uint32_t unk_250;             /* 0x250 [low] */
    uint8_t  pad_254[8];          /* 0x254 gap to pos cache */

    /* === Cached state (0x25C–0x2CC) === */
    Nucc_Vector3 cached_pos;      /* 0x25C [high] s2 mapping — from parent->pos */
    float    hp_ratio;            /* 0x268 [high] s2 mapping */
    float    chakra_ratio;        /* 0x26C [high] s2 mapping */
    float    support_ratio_0;     /* 0x270 [high] s2 mapping */
    float    support_ratio_1;     /* 0x274 [high] s2 mapping */
    float    support_ratios[2];   /* 0x278 [high] s2 mapping */
    float    inv_hp_ratio;        /* 0x280 [high] s2 mapping */
    uint32_t player_condition;    /* 0x284 [high] s2 mapping */
    uint32_t player_action_attr;  /* 0x288 [high] s2 mapping */
    uint8_t  pad_28c[4];          /* 0x28C align to uint64 */
    uint64_t leader_ptr;          /* 0x290 [high] s2 mapping */
    Nucc_Vector3 leader_pos;      /* 0x298 [high] s2 mapping */
    Nucc_Vector3 dir_to_leader;   /* 0x2A4 [high] s2 mapping */
    float    dist_to_leader;      /* 0x2B0 [high] s2 mapping */
    uint8_t  pad_2b4[4];          /* 0x2B4 gap */
    float    abs_dist_2b8;        /* 0x2B8 [high] s2 mapping */
    uint8_t  pad_2bc[4];          /* 0x2BC gap */
    float    safe_dist_threshold; /* 0x2C0 [high] s2 mapping */
    uint32_t unk_2c4;             /* 0x2C4 [low] */
    uint32_t unk_2c8;             /* 0x2C8 [low] */

    /* === Embedded sub-object (0x2CC–0x43C) === */
    uint8_t  subobj_2cc[284];     /* 0x2CC [med] s2 mapping — embedded obj init */
    uint8_t  pad_3e8[84];         /* 0x3E8 gap to vec_43c */

    /* === Vector & support pointers (0x43C–0x4C8) === */
    Nucc_Vector3 vec_43c;         /* 0x43C [high] s2 mapping */
    uint8_t  pad_448[16];         /* 0x448 gap */
    uint64_t support_ptrs[2];     /* 0x458 [high] s2 mapping */
    uint64_t unk_468;             /* 0x468 [low] */
    uint8_t  pad_470[8];          /* 0x470 gap */
    uint64_t unk_478;             /* 0x478 [high] s2 mapping */
    uint64_t unk_480;             /* 0x480 [low] */
    uint64_t unk_488;             /* 0x488 [low] */
    uint64_t unk_490;             /* 0x490 [low] */
    uint64_t unk_498;             /* 0x498 [low] */
    uint8_t  block_4a0[40];       /* 0x4A0 gap to update_timers */

    /* === Update timers & strength (0x4C8–0x534) === */
    float    update_timers[6];    /* 0x4C8 [high] Update — loop decrement */
    int32_t  unk_4e0;             /* 0x4E0 [med] ctor — init to -1 */
    uint8_t  strength_block[48];  /* 0x4E4 [high] ctor — memset region */
    int32_t  ai_config_514;       /* 0x514 [high] CheckAction */
    int32_t  ai_config_518;       /* 0x518 [high] CheckAction */
    int32_t  ai_config_51c;       /* 0x51C [high] CheckAction */
    uint8_t  pad_520[16];         /* 0x520 gap */
    int32_t  ai_strength_pct;     /* 0x530 [high] CheckAction — *0.01 weight */

    /* === Situation data blocks (0x534–0x734) — 8×64 bytes === */
    uint8_t  situation_data_534[64]; /* 0x534 [high] ctor init */
    uint8_t  situation_data_574[64]; /* 0x574 [high] ctor init */
    uint8_t  situation_data_5b4[64]; /* 0x5B4 [high] ctor init */
    uint8_t  situation_data_5f4[64]; /* 0x5F4 [high] ctor init */
    uint8_t  situation_data_634[64]; /* 0x634 [high] ctor init */
    uint8_t  situation_data_674[64]; /* 0x674 [high] ctor init */
    uint8_t  situation_data_6b4[64]; /* 0x6B4 [high] ctor init */
    uint8_t  situation_data_6f4[64]; /* 0x6F4 [high] ctor init */

    /* === Matrix / range / flags (0x734–0x78C) === */
    uint64_t matrix_734_lo;       /* 0x734 [high] ctor init */
    uint32_t matrix_73c_hi;       /* 0x73C [high] upper 4 bytes */
    uint8_t  pad_740[4];          /* 0x740 gap */
    float    dist_threshold_744;  /* 0x744 [high] CheckAction */
    uint64_t unk_748;             /* 0x748 [med] ctor */
    uint64_t unk_750;             /* 0x750 [med] ctor */
    uint32_t flags_758;           /* 0x758 [high] CheckAction — &0x200 */
    uint32_t flags_75c;           /* 0x75C [high] CheckAction — &0x80,&0x10 */
    uint64_t matrix_760;          /* 0x760 [high] ctor init */
    uint32_t matrix_768_hi;       /* 0x768 [high] upper 4 bytes */
    float    range_base_76c;      /* 0x76C [high] CheckAction */
    float    range_bonus_770;     /* 0x770 [high] CheckAction */
    uint64_t unk_774;             /* 0x774 [med] ctor init 0 */
    uint64_t unk_77c;             /* 0x77C [med] ctor init 0 */
    uint64_t unk_784;             /* 0x784 [med] ctor init 0 */

    /* === Action entries (0x78C–0xA0C) === */
    uint8_t  action_entries_78c[640]; /* 0x78C [high] Update — 0x28-byte entries */

    /* === Gap to reaction region (0xA0C–0x1054) === */
    uint8_t  pad_a0c[1608];       /* 0xA0C large unaccessed gap */

    /* === Reaction / check region (0x1054–0x1110) === */
    int32_t  action_avail_counts[8]; /* 0x1054 [high] CheckReaction — 8 ints */
    float    distance_1074;       /* 0x1074 [high] CheckReaction — vs 600/1500 */
    uint8_t  pad_1078[32];        /* 0x1078 gap */
    float    distance_1098;       /* 0x1098 [high] CheckAction */
    uint8_t  pad_109c[4];         /* 0x109C gap */
    uint64_t list_head_10a0;      /* 0x10A0 [high] CheckReaction */
    uint64_t list_sentinel_10a8;  /* 0x10A8 [high] CheckReaction */
    uint8_t  pad_10b0[24];        /* 0x10B0 gap */
    uint32_t flags_10c8;          /* 0x10C8 [high] CheckReaction — &0x100 */
    uint8_t  pad_10cc[4];         /* 0x10CC gap */
    uint64_t list_head_10d0;      /* 0x10D0 [high] CheckReaction */
    uint64_t list_sentinel_10d8;  /* 0x10D8 [high] CheckReaction */
    uint8_t  pad_10e0[24];        /* 0x10E0 gap */

    /* === Task / counter region (0x10F8–0x1110) === */
    uint32_t unk_10f8;            /* 0x10F8 [med] ctor write-only */
    int32_t  counter_10fc;        /* 0x10FC [high] CheckAction — <1 triggers 0xf */
    int32_t  threshold_1100;      /* 0x1100 [high] CheckReaction */
    uint8_t  pad_1104[4];         /* 0x1104 gap */
    uint64_t task_list_end;       /* 0x1108 [high] CheckAction */

    /* === Task history (0x1110–0x11B0) === */
    uint8_t  task_history[160];   /* 0x1110 [high] CheckAction — entries */

    /* === High-offset rw fields from state_surface (0x11B0–0x11E0) === */
    uint64_t container_11b0;      /* 0x11B0 [med] CheckAction — param_1+0x236 */
    uint64_t field_11b8;          /* 0x11B8 [med] CheckAction — arithmetic */
    uint8_t  pad_11c0[32];        /* 0x11C0 gap */
    uint64_t container_11e0;      /* 0x11E0 [low] CheckAction — FUN_140205288 */

    /* === More containers (0x11E8–0x1310) === */
    uint64_t container_11e8;      /* 0x11E8 [med] CheckAction */
    uint8_t  pad_11f0[128];       /* 0x11F0 gap */
    uint64_t container_1270;      /* 0x1270 [low] CheckAction */
    uint8_t  pad_1278[40];        /* 0x1278 gap */
    uint64_t container_12a0;      /* 0x12A0 [low] CheckAction */
    uint8_t  pad_12a8[40];        /* 0x12A8 gap */
    uint64_t container_12d0;      /* 0x12D0 [low] CheckAction */
    uint8_t  pad_12d8[40];        /* 0x12D8 gap */
    uint64_t ptr_1300;            /* 0x1300 [med] CheckAction — param_1[0x260] */
    uint64_t ptr_1308;            /* 0x1308 [med] CheckAction — non-null check */
    uint8_t  pad_1310[176];       /* 0x1310 gap to subclass region */

    /* === Subclass extension region (0x13C0–0x1438) === */
    /* These offsets are accessed by CheckReaction and subclass ctors.
     * They belong to the subclass extension beyond the base ccCpuPlayer. */
    uint32_t sub_float_13c0;      /* 0x13C0 [low] CheckReaction — FUN_1404edbc0 */
    uint32_t sub_float_13c4;      /* 0x13C4 [low] CheckReaction */
    uint32_t sub_float_13c8;      /* 0x13C8 [low] CheckReaction */
    uint32_t sub_float_13cc;      /* 0x13CC [low] CheckReaction */
    uint32_t sub_float_13d0;      /* 0x13D0 [low] CheckReaction */
    uint32_t sub_float_13d4;      /* 0x13D4 [low] CheckReaction */
    uint8_t  pad_13d8[4];         /* 0x13D8 gap to 0x13DC */
    float    sub_float_13dc;      /* 0x13DC [low] CheckReaction — 0x3fc00000 = 1.5f */
    uint8_t  pad_13e0[4];         /* 0x13E0 gap */
    uint32_t sub_readonly_13e4;   /* 0x13E4 [med] CheckAction/CheckReaction — 10 reads, *0.01 */
    uint8_t  pad_13e8[44];        /* 0x13E8 gap to 0x1414 */
    int32_t  sub_field_1414;      /* 0x1414 [med] CheckAction */
    uint32_t sub_field_1418_lo;   /* 0x1418 [med] CheckAction — low 4 bytes */
    int32_t  sub_field_141c;      /* 0x141C [med] CheckAction */
    uint8_t  pad_1420[12];        /* 0x1420 gap to 0x142C */
    uint32_t sub_field_142c;      /* 0x142C [low] filler to reach 0x1430 */
    uint64_t sub_field_1430;      /* 0x1430 [med] CheckAction/CheckReaction — *0.01 */
} ccCpuPlayer_s3;

/* Size proven from ccPlayerLeader::RegisterCpu @ RVA 0x550B84:
 * FUN_140683f70(0x1438, "source\\ccPlayerLeader.cpp", line)
 * This is the LARGEST subclass (ccCpuPlayerLeader). The base class is abstract. */
static_assert(sizeof(ccCpuPlayer_s3) == 0x1438, "ccCpuPlayer_s3 size must be 0x1438");

/* === Offset assertions for every named field === */
static_assert(offsetof(ccCpuPlayer_s3, vtable) == 0x000, "vtable");
static_assert(offsetof(ccCpuPlayer_s3, player_id) == 0x008, "player_id");
static_assert(offsetof(ccCpuPlayer_s3, pad_00c) == 0x00C, "pad_00c");
static_assert(offsetof(ccCpuPlayer_s3, parent_ptr) == 0x010, "parent_ptr");
static_assert(offsetof(ccCpuPlayer_s3, unk_018) == 0x018, "unk_018");
static_assert(offsetof(ccCpuPlayer_s3, think_action_idx) == 0x020, "think_action_idx");
static_assert(offsetof(ccCpuPlayer_s3, timer_accum_024) == 0x024, "timer_accum_024");
static_assert(offsetof(ccCpuPlayer_s3, unk_028) == 0x028, "unk_028");
static_assert(offsetof(ccCpuPlayer_s3, unk_02c) == 0x02C, "unk_02c");
static_assert(offsetof(ccCpuPlayer_s3, timer_accum_030) == 0x030, "timer_accum_030");
static_assert(offsetof(ccCpuPlayer_s3, pad_034) == 0x034, "pad_034");
static_assert(offsetof(ccCpuPlayer_s3, cooldowns) == 0x038, "cooldowns");
static_assert(offsetof(ccCpuPlayer_s3, charge_timers) == 0x104, "charge_timers");
static_assert(offsetof(ccCpuPlayer_s3, pad_144) == 0x144, "pad_144");
static_assert(offsetof(ccCpuPlayer_s3, ai_weight_0) == 0x200, "ai_weight_0");
static_assert(offsetof(ccCpuPlayer_s3, ai_weight_1) == 0x204, "ai_weight_1");
static_assert(offsetof(ccCpuPlayer_s3, ai_weight_2) == 0x208, "ai_weight_2");
static_assert(offsetof(ccCpuPlayer_s3, pad_20c) == 0x20C, "pad_20c");
static_assert(offsetof(ccCpuPlayer_s3, react_cooldown_bc) == 0x210, "react_cooldown_bc");
static_assert(offsetof(ccCpuPlayer_s3, subobj_214) == 0x214, "subobj_214");
static_assert(offsetof(ccCpuPlayer_s3, subobj_21a) == 0x21A, "subobj_21a");
static_assert(offsetof(ccCpuPlayer_s3, pad_220) == 0x220, "pad_220");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_224) == 0x224, "act_avail_224");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_228) == 0x228, "act_avail_228");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_22c) == 0x22C, "act_avail_22c");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_230) == 0x230, "act_avail_230");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_234) == 0x234, "act_avail_234");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_238) == 0x238, "act_avail_238");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_23c) == 0x23C, "act_avail_23c");
static_assert(offsetof(ccCpuPlayer_s3, act_avail_240) == 0x240, "act_avail_240");
static_assert(offsetof(ccCpuPlayer_s3, unk_244) == 0x244, "unk_244");
static_assert(offsetof(ccCpuPlayer_s3, unk_248) == 0x248, "unk_248");
static_assert(offsetof(ccCpuPlayer_s3, unk_24c) == 0x24C, "unk_24c");
static_assert(offsetof(ccCpuPlayer_s3, unk_250) == 0x250, "unk_250");
static_assert(offsetof(ccCpuPlayer_s3, pad_254) == 0x254, "pad_254");
static_assert(offsetof(ccCpuPlayer_s3, cached_pos) == 0x25C, "cached_pos");
static_assert(offsetof(ccCpuPlayer_s3, hp_ratio) == 0x268, "hp_ratio");
static_assert(offsetof(ccCpuPlayer_s3, chakra_ratio) == 0x26C, "chakra_ratio");
static_assert(offsetof(ccCpuPlayer_s3, support_ratio_0) == 0x270, "support_ratio_0");
static_assert(offsetof(ccCpuPlayer_s3, support_ratio_1) == 0x274, "support_ratio_1");
static_assert(offsetof(ccCpuPlayer_s3, support_ratios) == 0x278, "support_ratios");
static_assert(offsetof(ccCpuPlayer_s3, inv_hp_ratio) == 0x280, "inv_hp_ratio");
static_assert(offsetof(ccCpuPlayer_s3, player_condition) == 0x284, "player_condition");
static_assert(offsetof(ccCpuPlayer_s3, player_action_attr) == 0x288, "player_action_attr");
static_assert(offsetof(ccCpuPlayer_s3, pad_28c) == 0x28C, "pad_28c");
static_assert(offsetof(ccCpuPlayer_s3, leader_ptr) == 0x290, "leader_ptr");
static_assert(offsetof(ccCpuPlayer_s3, leader_pos) == 0x298, "leader_pos");
static_assert(offsetof(ccCpuPlayer_s3, dir_to_leader) == 0x2A4, "dir_to_leader");
static_assert(offsetof(ccCpuPlayer_s3, dist_to_leader) == 0x2B0, "dist_to_leader");
static_assert(offsetof(ccCpuPlayer_s3, pad_2b4) == 0x2B4, "pad_2b4");
static_assert(offsetof(ccCpuPlayer_s3, abs_dist_2b8) == 0x2B8, "abs_dist_2b8");
static_assert(offsetof(ccCpuPlayer_s3, pad_2bc) == 0x2BC, "pad_2bc");
static_assert(offsetof(ccCpuPlayer_s3, safe_dist_threshold) == 0x2C0, "safe_dist_threshold");
static_assert(offsetof(ccCpuPlayer_s3, unk_2c4) == 0x2C4, "unk_2c4");
static_assert(offsetof(ccCpuPlayer_s3, unk_2c8) == 0x2C8, "unk_2c8");
static_assert(offsetof(ccCpuPlayer_s3, subobj_2cc) == 0x2CC, "subobj_2cc");
static_assert(offsetof(ccCpuPlayer_s3, pad_3e8) == 0x3E8, "pad_3e8");
static_assert(offsetof(ccCpuPlayer_s3, vec_43c) == 0x43C, "vec_43c");
static_assert(offsetof(ccCpuPlayer_s3, pad_448) == 0x448, "pad_448");
static_assert(offsetof(ccCpuPlayer_s3, support_ptrs) == 0x458, "support_ptrs");
static_assert(offsetof(ccCpuPlayer_s3, unk_468) == 0x468, "unk_468");
static_assert(offsetof(ccCpuPlayer_s3, pad_470) == 0x470, "pad_470");
static_assert(offsetof(ccCpuPlayer_s3, unk_478) == 0x478, "unk_478");
static_assert(offsetof(ccCpuPlayer_s3, unk_480) == 0x480, "unk_480");
static_assert(offsetof(ccCpuPlayer_s3, unk_488) == 0x488, "unk_488");
static_assert(offsetof(ccCpuPlayer_s3, unk_490) == 0x490, "unk_490");
static_assert(offsetof(ccCpuPlayer_s3, unk_498) == 0x498, "unk_498");
static_assert(offsetof(ccCpuPlayer_s3, block_4a0) == 0x4A0, "block_4a0");
static_assert(offsetof(ccCpuPlayer_s3, update_timers) == 0x4C8, "update_timers");
static_assert(offsetof(ccCpuPlayer_s3, unk_4e0) == 0x4E0, "unk_4e0");
static_assert(offsetof(ccCpuPlayer_s3, strength_block) == 0x4E4, "strength_block");
static_assert(offsetof(ccCpuPlayer_s3, ai_config_514) == 0x514, "ai_config_514");
static_assert(offsetof(ccCpuPlayer_s3, ai_config_518) == 0x518, "ai_config_518");
static_assert(offsetof(ccCpuPlayer_s3, ai_config_51c) == 0x51C, "ai_config_51c");
static_assert(offsetof(ccCpuPlayer_s3, pad_520) == 0x520, "pad_520");
static_assert(offsetof(ccCpuPlayer_s3, ai_strength_pct) == 0x530, "ai_strength_pct");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_534) == 0x534, "situation_data_534");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_574) == 0x574, "situation_data_574");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_5b4) == 0x5B4, "situation_data_5b4");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_5f4) == 0x5F4, "situation_data_5f4");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_634) == 0x634, "situation_data_634");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_674) == 0x674, "situation_data_674");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_6b4) == 0x6B4, "situation_data_6b4");
static_assert(offsetof(ccCpuPlayer_s3, situation_data_6f4) == 0x6F4, "situation_data_6f4");
static_assert(offsetof(ccCpuPlayer_s3, matrix_734_lo) == 0x734, "matrix_734_lo");
static_assert(offsetof(ccCpuPlayer_s3, matrix_73c_hi) == 0x73C, "matrix_73c_hi");
static_assert(offsetof(ccCpuPlayer_s3, pad_740) == 0x740, "pad_740");
static_assert(offsetof(ccCpuPlayer_s3, dist_threshold_744) == 0x744, "dist_threshold_744");
static_assert(offsetof(ccCpuPlayer_s3, unk_748) == 0x748, "unk_748");
static_assert(offsetof(ccCpuPlayer_s3, unk_750) == 0x750, "unk_750");
static_assert(offsetof(ccCpuPlayer_s3, flags_758) == 0x758, "flags_758");
static_assert(offsetof(ccCpuPlayer_s3, flags_75c) == 0x75C, "flags_75c");
static_assert(offsetof(ccCpuPlayer_s3, matrix_760) == 0x760, "matrix_760");
static_assert(offsetof(ccCpuPlayer_s3, matrix_768_hi) == 0x768, "matrix_768_hi");
static_assert(offsetof(ccCpuPlayer_s3, range_base_76c) == 0x76C, "range_base_76c");
static_assert(offsetof(ccCpuPlayer_s3, range_bonus_770) == 0x770, "range_bonus_770");
static_assert(offsetof(ccCpuPlayer_s3, unk_774) == 0x774, "unk_774");
static_assert(offsetof(ccCpuPlayer_s3, unk_77c) == 0x77C, "unk_77c");
static_assert(offsetof(ccCpuPlayer_s3, unk_784) == 0x784, "unk_784");
static_assert(offsetof(ccCpuPlayer_s3, action_entries_78c) == 0x78C, "action_entries_78c");
static_assert(offsetof(ccCpuPlayer_s3, pad_a0c) == 0xA0C, "pad_a0c");
static_assert(offsetof(ccCpuPlayer_s3, action_avail_counts) == 0x1054, "action_avail_counts");
static_assert(offsetof(ccCpuPlayer_s3, distance_1074) == 0x1074, "distance_1074");
static_assert(offsetof(ccCpuPlayer_s3, pad_1078) == 0x1078, "pad_1078");
static_assert(offsetof(ccCpuPlayer_s3, distance_1098) == 0x1098, "distance_1098");
static_assert(offsetof(ccCpuPlayer_s3, pad_109c) == 0x109C, "pad_109c");
static_assert(offsetof(ccCpuPlayer_s3, list_head_10a0) == 0x10A0, "list_head_10a0");
static_assert(offsetof(ccCpuPlayer_s3, list_sentinel_10a8) == 0x10A8, "list_sentinel_10a8");
static_assert(offsetof(ccCpuPlayer_s3, pad_10b0) == 0x10B0, "pad_10b0");
static_assert(offsetof(ccCpuPlayer_s3, flags_10c8) == 0x10C8, "flags_10c8");
static_assert(offsetof(ccCpuPlayer_s3, pad_10cc) == 0x10CC, "pad_10cc");
static_assert(offsetof(ccCpuPlayer_s3, list_head_10d0) == 0x10D0, "list_head_10d0");
static_assert(offsetof(ccCpuPlayer_s3, list_sentinel_10d8) == 0x10D8, "list_sentinel_10d8");
static_assert(offsetof(ccCpuPlayer_s3, pad_10e0) == 0x10E0, "pad_10e0");
static_assert(offsetof(ccCpuPlayer_s3, unk_10f8) == 0x10F8, "unk_10f8");
static_assert(offsetof(ccCpuPlayer_s3, counter_10fc) == 0x10FC, "counter_10fc");
static_assert(offsetof(ccCpuPlayer_s3, threshold_1100) == 0x1100, "threshold_1100");
static_assert(offsetof(ccCpuPlayer_s3, pad_1104) == 0x1104, "pad_1104");
static_assert(offsetof(ccCpuPlayer_s3, task_list_end) == 0x1108, "task_list_end");
static_assert(offsetof(ccCpuPlayer_s3, task_history) == 0x1110, "task_history");
static_assert(offsetof(ccCpuPlayer_s3, container_11b0) == 0x11B0, "container_11b0");
static_assert(offsetof(ccCpuPlayer_s3, field_11b8) == 0x11B8, "field_11b8");
static_assert(offsetof(ccCpuPlayer_s3, pad_11c0) == 0x11C0, "pad_11c0");
static_assert(offsetof(ccCpuPlayer_s3, container_11e0) == 0x11E0, "container_11e0");
static_assert(offsetof(ccCpuPlayer_s3, container_11e8) == 0x11E8, "container_11e8");
static_assert(offsetof(ccCpuPlayer_s3, pad_11f0) == 0x11F0, "pad_11f0");
static_assert(offsetof(ccCpuPlayer_s3, container_1270) == 0x1270, "container_1270");
static_assert(offsetof(ccCpuPlayer_s3, pad_1278) == 0x1278, "pad_1278");
static_assert(offsetof(ccCpuPlayer_s3, container_12a0) == 0x12A0, "container_12a0");
static_assert(offsetof(ccCpuPlayer_s3, pad_12a8) == 0x12A8, "pad_12a8");
static_assert(offsetof(ccCpuPlayer_s3, container_12d0) == 0x12D0, "container_12d0");
static_assert(offsetof(ccCpuPlayer_s3, pad_12d8) == 0x12D8, "pad_12d8");
static_assert(offsetof(ccCpuPlayer_s3, ptr_1300) == 0x1300, "ptr_1300");
static_assert(offsetof(ccCpuPlayer_s3, ptr_1308) == 0x1308, "ptr_1308");
static_assert(offsetof(ccCpuPlayer_s3, pad_1310) == 0x1310, "pad_1310");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13c0) == 0x13C0, "sub_float_13c0");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13c4) == 0x13C4, "sub_float_13c4");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13c8) == 0x13C8, "sub_float_13c8");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13cc) == 0x13CC, "sub_float_13cc");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13d0) == 0x13D0, "sub_float_13d0");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13d4) == 0x13D4, "sub_float_13d4");
static_assert(offsetof(ccCpuPlayer_s3, sub_float_13dc) == 0x13DC, "sub_float_13dc");
static_assert(offsetof(ccCpuPlayer_s3, pad_13e0) == 0x13E0, "pad_13e0");
static_assert(offsetof(ccCpuPlayer_s3, sub_readonly_13e4) == 0x13E4, "sub_readonly_13e4");
static_assert(offsetof(ccCpuPlayer_s3, pad_13e8) == 0x13E8, "pad_13e8");
static_assert(offsetof(ccCpuPlayer_s3, sub_field_1414) == 0x1414, "sub_field_1414");
static_assert(offsetof(ccCpuPlayer_s3, sub_field_1418_lo) == 0x1418, "sub_field_1418_lo");
static_assert(offsetof(ccCpuPlayer_s3, sub_field_141c) == 0x141C, "sub_field_141c");
static_assert(offsetof(ccCpuPlayer_s3, pad_1420) == 0x1420, "pad_1420");
static_assert(offsetof(ccCpuPlayer_s3, sub_field_142c) == 0x142C, "sub_field_142c");
static_assert(offsetof(ccCpuPlayer_s3, pad_1420) == 0x1420, "pad_1420");
static_assert(offsetof(ccCpuPlayer_s3, sub_field_1430) == 0x1430, "sub_field_1430");

#endif /* CC_CPU_PLAYER_S3_H */