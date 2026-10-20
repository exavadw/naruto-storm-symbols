/*
 * rbDuel.h - Duel/match struct layouts for NARUTO STORM 2 PC (build s2)
 *
 * INFERRED from static analysis (decompilation + state_surface).
 * All fields are INFERRED unless marked CONFIRMED by runtime trace.
 * Sizes proven from game code where possible; otherwise ">= 0x<N>".
 * Classes absent from s2: ccGameDuel, ccGameDuelJudge, ccGameDuelSetting.
 */

#ifndef RBDUEL_S2_H
#define RBDUEL_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccDuelJudge — duel scoring/judgement state.
 * Size unknown, >= 0x6C. No standalone ctor found; initialized via
 * ccDuelJudge::Clear (RVA 0x324BCC), called from ccDuelManager ctor.
 * Fields derived from Clear's write pattern on undefined4* param_1.
 */
typedef struct __attribute__((packed)) ccDuelJudge {
    uint8_t pad_00[0x08];       /* 0x00 [UNKNOWN] gap before loop1 region */
    int32_t slot_id_0;          /* 0x08 [SIM] Clear loop1: =0xffffffff */
    int32_t slot_val_0;         /* 0x0C [SIM] Clear loop1: =0 */
    int32_t slot_id_1;          /* 0x10 [SIM] Clear loop1: =0xffffffff */
    int32_t slot_val_1;         /* 0x14 [SIM] Clear loop1: =0 */
    int32_t slot_id_2;          /* 0x18 [SIM] Clear loop1: =0xffffffff */
    int32_t slot_val_2;         /* 0x1C [SIM] Clear loop1: =0 */
    int32_t counter;            /* 0x20 [SIM] Clear: param_1[8]=0 */
    int32_t achievement_id_0;   /* 0x24 [SIM] Clear loop2: =0xffffffff */
    int32_t achievement_val_0;  /* 0x28 [SIM] Clear loop2: =0 */
    int32_t achievement_id_1;   /* 0x2C [SIM] Clear loop2: =0xffffffff */
    int32_t achievement_val_1;  /* 0x30 [SIM] Clear loop2: =0 */
    int32_t achievement_id_2;   /* 0x34 [SIM] Clear loop2: =0xffffffff */
    int32_t achievement_val_2;  /* 0x38 [SIM] Clear loop2: =0 */
    int64_t time_count;         /* 0x3C [SIM] Clear: =0; SetTimeCount writes */
    int64_t count;              /* 0x44 [SIM] Clear: =2; SetCount writes */
    int64_t field_4c;           /* 0x4C [SIM] Clear: =0 */
    int64_t field_54;           /* 0x54 [SIM] Clear: =0 */
    int64_t field_5c;           /* 0x5C [SIM] Clear: =0 */
    int64_t field_64;           /* 0x64 [SIM] Clear: =0 */
} ccDuelJudge;

static_assert(offsetof(ccDuelJudge, pad_00) == 0x00, "ccDuelJudge.pad_00");
static_assert(offsetof(ccDuelJudge, slot_id_0) == 0x08, "ccDuelJudge.slot_id_0");
static_assert(offsetof(ccDuelJudge, slot_val_0) == 0x0C, "ccDuelJudge.slot_val_0");
static_assert(offsetof(ccDuelJudge, slot_id_1) == 0x10, "ccDuelJudge.slot_id_1");
static_assert(offsetof(ccDuelJudge, slot_val_1) == 0x14, "ccDuelJudge.slot_val_1");
static_assert(offsetof(ccDuelJudge, slot_id_2) == 0x18, "ccDuelJudge.slot_id_2");
static_assert(offsetof(ccDuelJudge, slot_val_2) == 0x1C, "ccDuelJudge.slot_val_2");
static_assert(offsetof(ccDuelJudge, counter) == 0x20, "ccDuelJudge.counter");
static_assert(offsetof(ccDuelJudge, achievement_id_0) == 0x24, "ccDuelJudge.achievement_id_0");
static_assert(offsetof(ccDuelJudge, achievement_val_0) == 0x28, "ccDuelJudge.achievement_val_0");
static_assert(offsetof(ccDuelJudge, achievement_id_1) == 0x2C, "ccDuelJudge.achievement_id_1");
static_assert(offsetof(ccDuelJudge, achievement_val_1) == 0x30, "ccDuelJudge.achievement_val_1");
static_assert(offsetof(ccDuelJudge, achievement_id_2) == 0x34, "ccDuelJudge.achievement_id_2");
static_assert(offsetof(ccDuelJudge, achievement_val_2) == 0x38, "ccDuelJudge.achievement_val_2");
static_assert(offsetof(ccDuelJudge, time_count) == 0x3C, "ccDuelJudge.time_count");
static_assert(offsetof(ccDuelJudge, count) == 0x44, "ccDuelJudge.count");
static_assert(offsetof(ccDuelJudge, field_4c) == 0x4C, "ccDuelJudge.field_4c");
static_assert(offsetof(ccDuelJudge, field_54) == 0x54, "ccDuelJudge.field_54");
static_assert(offsetof(ccDuelJudge, field_5c) == 0x5C, "ccDuelJudge.field_5c");
static_assert(offsetof(ccDuelJudge, field_64) == 0x64, "ccDuelJudge.field_64");
/* sizeof not asserted: size unknown, >= 0x6C */

/*
 * ccDuelManager — manages duel players and judge state.
 * Ctor at RVA 0x324B40 sets vtable PTR_FUN_1408918e8, initializes two
 * 3-slot arrays (0x0C-0x1C and 0x24-0x3C), then calls ccDuelJudge::Clear
 * on itself, meaning ccDuelJudge fields are embedded at the same base.
 * Size unknown, >= 0x6C (at least covers ccDuelJudge layout).
 */
typedef struct __attribute__((packed)) ccDuelManager {
    void* vtable;               /* 0x00 [PRES] PTR_FUN_1408918e8 */
    uint8_t pad_08[0x04];      /* 0x08 [UNKNOWN] gap */
    int32_t player_slot_id_0;   /* 0x0C [SIM] ctor loop1: =0xffffffff */
    int32_t player_slot_ptr_0;  /* 0x10 [SIM] ctor loop1: =0 */
    int32_t player_slot_id_1;   /* 0x14 [SIM] ctor loop1: =0xffffffff */
    int32_t player_slot_ptr_1;  /* 0x18 [SIM] ctor loop1: =0 */
    int32_t player_slot_id_2;   /* 0x1C [SIM] ctor loop1: =0xffffffff */
    uint8_t pad_20[0x04];      /* 0x20 [UNKNOWN] gap between loops */
    int32_t team_slot_id_0;     /* 0x24 [SIM] ctor loop2: =0xffffffff */
    int32_t team_slot_val_0;    /* 0x28 [SIM] ctor loop2: =0 */
    int32_t team_slot_id_1;     /* 0x2C [SIM] ctor loop2: =0xffffffff */
    int32_t team_slot_val_1;    /* 0x30 [SIM] ctor loop2: =0 */
    int32_t team_slot_id_2;     /* 0x34 [SIM] ctor loop2: =0xffffffff */
    int32_t team_slot_val_2;    /* 0x38 [SIM] ctor loop2: =0 */
    /* ccDuelJudge::Clear writes continue at 0x3C+ (see ccDuelJudge) */
    int64_t judge_time_count;   /* 0x3C [SIM] Clear: =0 */
    int64_t judge_count;        /* 0x44 [SIM] Clear: =2 */
    int64_t judge_field_4c;     /* 0x4C [SIM] Clear: =0 */
    int64_t judge_field_54;     /* 0x54 [SIM] Clear: =0 */
    int64_t judge_field_5c;     /* 0x5C [SIM] Clear: =0 */
    int64_t judge_field_64;     /* 0x64 [SIM] Clear: =0 */
} ccDuelManager;

static_assert(offsetof(ccDuelManager, vtable) == 0x00, "ccDuelManager.vtable");
static_assert(offsetof(ccDuelManager, pad_08) == 0x08, "ccDuelManager.pad_08");
static_assert(offsetof(ccDuelManager, player_slot_id_0) == 0x0C, "ccDuelManager.player_slot_id_0");
static_assert(offsetof(ccDuelManager, player_slot_ptr_0) == 0x10, "ccDuelManager.player_slot_ptr_0");
static_assert(offsetof(ccDuelManager, player_slot_id_1) == 0x14, "ccDuelManager.player_slot_id_1");
static_assert(offsetof(ccDuelManager, player_slot_ptr_1) == 0x18, "ccDuelManager.player_slot_ptr_1");
static_assert(offsetof(ccDuelManager, player_slot_id_2) == 0x1C, "ccDuelManager.player_slot_id_2");
static_assert(offsetof(ccDuelManager, pad_20) == 0x20, "ccDuelManager.pad_20");
static_assert(offsetof(ccDuelManager, team_slot_id_0) == 0x24, "ccDuelManager.team_slot_id_0");
static_assert(offsetof(ccDuelManager, team_slot_val_0) == 0x28, "ccDuelManager.team_slot_val_0");
static_assert(offsetof(ccDuelManager, team_slot_id_1) == 0x2C, "ccDuelManager.team_slot_id_1");
static_assert(offsetof(ccDuelManager, team_slot_val_1) == 0x30, "ccDuelManager.team_slot_val_1");
static_assert(offsetof(ccDuelManager, team_slot_id_2) == 0x34, "ccDuelManager.team_slot_id_2");
static_assert(offsetof(ccDuelManager, team_slot_val_2) == 0x38, "ccDuelManager.team_slot_val_2");
static_assert(offsetof(ccDuelManager, judge_time_count) == 0x3C, "ccDuelManager.judge_time_count");
static_assert(offsetof(ccDuelManager, judge_count) == 0x44, "ccDuelManager.judge_count");
static_assert(offsetof(ccDuelManager, judge_field_4c) == 0x4C, "ccDuelManager.judge_field_4c");
static_assert(offsetof(ccDuelManager, judge_field_54) == 0x54, "ccDuelManager.judge_field_54");
static_assert(offsetof(ccDuelManager, judge_field_5c) == 0x5C, "ccDuelManager.judge_field_5c");
static_assert(offsetof(ccDuelManager, judge_field_64) == 0x64, "ccDuelManager.judge_field_64");
/* sizeof not asserted: size unknown, >= 0x6C */

/*
 * ccDuelRule — duel rule parameters.
 * Initialize (RVA 0x6055C0) copies 4 × int32 from param_2 to offsets
 * 0x3C, 0x40, 0x44, 0x48. Size unknown, >= 0x4C.
 */
typedef struct __attribute__((packed)) ccDuelRule {
    uint8_t pad_00[0x3C];      /* 0x00 [UNKNOWN] gap before known fields */
    int32_t rule_param_0;       /* 0x3C [SIM] Initialize: =param_2[0] */
    int32_t rule_param_1;       /* 0x40 [SIM] Initialize: =param_2[1] */
    int32_t rule_param_2;       /* 0x44 [SIM] Initialize: =param_2[2] */
    int32_t rule_param_3;       /* 0x48 [SIM] Initialize: =param_2[3] */
} ccDuelRule;

static_assert(offsetof(ccDuelRule, pad_00) == 0x00, "ccDuelRule.pad_00");
static_assert(offsetof(ccDuelRule, rule_param_0) == 0x3C, "ccDuelRule.rule_param_0");
static_assert(offsetof(ccDuelRule, rule_param_1) == 0x40, "ccDuelRule.rule_param_1");
static_assert(offsetof(ccDuelRule, rule_param_2) == 0x44, "ccDuelRule.rule_param_2");
static_assert(offsetof(ccDuelRule, rule_param_3) == 0x48, "ccDuelRule.rule_param_3");
/* sizeof not asserted: size unknown, >= 0x4C */

/*
 * ccDuelSettingInfo — duel setting parameter container.
 * Clear (RVA 0x327420) writes int32=0 at offset 0x78.
 * Size unknown, >= 0x7C.
 */
typedef struct __attribute__((packed)) ccDuelSettingInfo {
    uint8_t pad_00[0x78];      /* 0x00 [UNKNOWN] gap before known field */
    int32_t clear_field;        /* 0x78 [SIM] Clear: =0 */
} ccDuelSettingInfo;

static_assert(offsetof(ccDuelSettingInfo, pad_00) == 0x00, "ccDuelSettingInfo.pad_00");
static_assert(offsetof(ccDuelSettingInfo, clear_field) == 0x78, "ccDuelSettingInfo.clear_field");
/* sizeof not asserted: size unknown, >= 0x7C */

/*
 * ccDuelSituation — large composite holding entire duel situation state.
 * Ctor at RVA 0x324EE4 sets vtable PTR_FUN_1407f1480 and initializes
 * many sub-objects. Largest accessed offset ~0x55fa.
 * Size unknown, >= 0x5600. Only sub-object anchor points listed.
 */
typedef struct __attribute__((packed)) ccDuelSituation {
    void* vtable;               /* 0x0000 [PRES] PTR_FUN_1407f1480 */
    uint8_t pad_08[0x08];      /* 0x0008 [UNKNOWN] gap */
    uint8_t subobj_teamA[0x70]; /* 0x0010 [SIM] ctor: FUN_140328b2c(puVar3), stride 0xe×8=0x70, 2 iters */
    uint8_t pad_80[0x70];        /* 0x0080 [UNKNOWN] gap between teamA and subobj_0xF0 */
    uint8_t subobj_0xF0[0x28];  /* 0x00F0 [SIM] ctor: FUN_140327360(param_1+0x1e) */
    uint8_t subobj_array_0x118[0x68]; /* 0x0118 [SIM] ctor: 12×FUN_140324bc4 at param_1+0x23, stride 1 */
    uint8_t subobj_0x180[0x70]; /* 0x0180 [SIM] ctor: FUN_140324b40(param_1+0x30)=ccDuelManager sub */
    uint8_t subobj_players[0x2A6F0]; /* 0x01F0 [SIM] ctor: 6×FUN_140325f74, stride 0xe25×8=0x7128 */
    uint8_t subobj_0x2A8E0[0x358]; /* 0x2A8E0 [SIM] ctor: FUN_1403d5140(param_1+0x551c) */
    uint8_t wchar_array_0x2AC38[0x120]; /* 0x2AC38 [SIM] ctor: 6×0x18 wchar16 zeros at param_1+0x5587 */
    uint8_t subobj_0x2AD58[0xE0]; /* 0x2AD58 [SIM] ctor: 2×FUN_140328b2c at param_1+0x55ab */
    uint8_t subobj_0x2AE38[0x70]; /* 0x2AE38 [SIM] ctor: FUN_140324b40(param_1+0x55c7) */
    uint8_t wchar_array_0x2AEA8[0x128]; /* 0x2AEA8 [SIM] ctor: 6×0x18 wchar16 zeros at param_1+0x55d5 */
    uint8_t subobj_0x2AFD0[0x10]; /* 0x2AFD0 [SIM] ctor: FUN_140325034(param_1+0x55fa) */
} ccDuelSituation;

static_assert(offsetof(ccDuelSituation, vtable) == 0x0000, "ccDuelSituation.vtable");
static_assert(offsetof(ccDuelSituation, pad_08) == 0x0008, "ccDuelSituation.pad_08");
static_assert(offsetof(ccDuelSituation, subobj_teamA) == 0x0010, "ccDuelSituation.subobj_teamA");
static_assert(offsetof(ccDuelSituation, pad_80) == 0x0080, "ccDuelSituation.pad_80");
static_assert(offsetof(ccDuelSituation, subobj_0xF0) == 0x00F0, "ccDuelSituation.subobj_0xF0");
static_assert(offsetof(ccDuelSituation, subobj_array_0x118) == 0x0118, "ccDuelSituation.subobj_array_0x118");
static_assert(offsetof(ccDuelSituation, subobj_0x180) == 0x0180, "ccDuelSituation.subobj_0x180");
static_assert(offsetof(ccDuelSituation, subobj_players) == 0x01F0, "ccDuelSituation.subobj_players");
static_assert(offsetof(ccDuelSituation, subobj_0x2A8E0) == 0x2A8E0, "ccDuelSituation.subobj_0x2A8E0");
static_assert(offsetof(ccDuelSituation, wchar_array_0x2AC38) == 0x2AC38, "ccDuelSituation.wchar_array_0x2AC38");
static_assert(offsetof(ccDuelSituation, subobj_0x2AD58) == 0x2AD58, "ccDuelSituation.subobj_0x2AD58");
static_assert(offsetof(ccDuelSituation, subobj_0x2AE38) == 0x2AE38, "ccDuelSituation.subobj_0x2AE38");
static_assert(offsetof(ccDuelSituation, wchar_array_0x2AEA8) == 0x2AEA8, "ccDuelSituation.wchar_array_0x2AEA8");
static_assert(offsetof(ccDuelSituation, subobj_0x2AFD0) == 0x2AFD0, "ccDuelSituation.subobj_0x2AFD0");
/* sizeof not asserted: size unknown, >= 0x5600 */

/*
 * Stub structs for classes with no surfaced fields.
 * These exist only to document presence in the build.
 * Sizes unknown; no offsetof assertions beyond vtable.
 */

/* ccDuelTeam — 13 methods, 0 fields surfaced (all byte-cast warnings) */
typedef struct __attribute__((packed)) ccDuelTeam {
    uint8_t opaque[1]; /* placeholder; size unknown */
} ccDuelTeam;

/* ccDuelPlayerLoader — 5 methods, 0 fields surfaced */
typedef struct __attribute__((packed)) ccDuelPlayerLoader {
    uint8_t opaque[1]; /* placeholder; size unknown */
} ccDuelPlayerLoader;

/* ccDuelSettingManager — 3 methods, 0 fields surfaced */
typedef struct __attribute__((packed)) ccDuelSettingManager {
    uint8_t opaque[1]; /* placeholder; size unknown */
} ccDuelSettingManager;

/* ccSceneBattle — 7 methods, 0 fields surfaced */
typedef struct __attribute__((packed)) ccSceneBattle {
    uint8_t opaque[1]; /* placeholder; size unknown */
} ccSceneBattle;

#endif /* RBDUEL_S2_H */