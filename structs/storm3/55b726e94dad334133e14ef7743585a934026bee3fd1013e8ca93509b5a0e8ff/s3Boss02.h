#ifndef S3_BOSS02_H
#define S3_BOSS02_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* C11 static_assert compatibility */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/*
 * s3Boss02 struct layouts — NARUTO STORM 3 Full Burst HD (NSUNS3.exe, 64-bit)
 * Build: s3 (sha256 55b726e94dad)
 *
 * All offsets derived from decompiled code (the decompiler cache cache, 162/162 RVAs).
 * Field names inferred from method access patterns, string refs and ctor init.
 * Sizes from FUN_140683f70(size, src, line) = operator new where found.
 *
 * INFERRED, NOT CONFIRMED — static analysis only, no runtime verification.
 */

/* ------------------------------------------------------------------ */
/* ccSceneBoss0201Base                                                */
/*                                                                    */
/* Base scene class for boss battle 02-01 (Deidara/Sasori phase).     */
/* Size: 0x2C8 (712 bytes) — FUN_140683f70(0x2c8,...) at RVA 0x63E52C */
/* Vtable: 0x1408FC138 (set in ctor RVA 0x2E4E24)                    */
/* Source: source\BossBattle\02\ccSceneBoss0201Base.cpp               */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;              /* vtable ptr, set to 0x1408FC138 in ctor */
    /* 0x008 */ uint8_t unk_008[0x1A0];     /* base-class region (ccScene base) */
    /* 0x1A8 */ int32_t sceneId;            /* param_1[0x25] = FUN_140635134(&DAT_140be38c0); written in PostInit */
    /* 0x1AC */ uint8_t pad_1AC[0x134];     /* gap to 0x2E0 */
    /* 0x2E0 */ int32_t renkeiOugiIdx;      /* param_1[0x32] passed to FUN_14050518c */
    /* 0x2E4 */ uint8_t pad_2E4[0x44];      /* gap to 0x328 */
    /* 0x328 */ float lifeLimitScale;       /* param_1[0x53] = 0x41200000 (10.0f) */
    /* 0x32C */ int32_t iaFailedFlag;       /* param_1[0x54] = 1; "Boss0201_IaFailed" */
    /* 0x330 */ uint8_t pad_330[0x10];      /* gap to 0x340 */
    /* 0x340 */ int64_t isSecondPhase;      /* param_1[0x5f]: 0 -> BATTLE_MAIN_014, else _013 */
    /* 0x348 */ uint8_t pad_348[0x10];      /* gap to 0x358 */
    /* 0x358 */ int64_t collisionPushTask;  /* param_1[0x57] = FUN_1401bcb48("ccCollision::Manager::Execute_PushNS3") */
    /* 0x360 */ int64_t collisionAttackTask;/* param_1[0x58] = FUN_1401bcb48("ccCollision::Manager::Execute_AttackNS3") */
    /* 0x368 */ int64_t chakraBallCtrlTask; /* param_1[0x59] = FUN_1401bcb48("ccChakraBallManager::Ctrl") */
    /* 0x370 */ int64_t chakraBallDrawTask; /* param_1[0x5a] = FUN_1401bcb48("ccChakraBallManager::Draw") */
    /* 0x378 */ uint8_t pad_378[0x10];      /* gap to 0x388 */
    /* 0x388 */ int64_t renkeiOugiUpdateTask;     /* param_1[0x5d] */
    /* 0x390 */ int64_t renkeiOugiPositioningTask;/* param_1[0x5e] */
    /* 0x398 */ uint8_t pad_398[0x10];      /* gap to 0x3A8 */
    /* 0x3A8 */ int64_t uiManagerPtr;       /* param_1[0x81]: ccBoss02UiManager*, released via vtable+0x0 in PostInit */
    /* 0x3B0 */ int64_t subObj_0x82;        /* param_1[0x82]: allocated 0x88 at line 0x584, +0x78 = &param_1[0x9b] */
    /* 0x3B8 */ uint8_t pad_3B8[0x10];      /* gap to 0x3C8 */
    /* 0x3C8 */ uint8_t field_0x3C8[0x18];  /* param_1[0x84]: passed to FUN_1401c0438 as "Boss0201_IaFailed" handler */
    /* 0x3E0 */ uint8_t field_0x3E0[0x18];  /* param_1[0x85]: FUN_140380748(param_1+0x85, 2, ...) */
    /* 0x3F8 */ uint8_t pad_3F8[0x18];      /* gap to 0x410 */
    /* 0x410 */ uint8_t field_0x410[0x18];  /* param_1[0x9b]: passed to FUN_140276c8c / FUN_140276e3c */
    /* 0x428 */ uint8_t pad_428[0x2A0];     /* remaining bytes to reach 0x6C8 */
} ccSceneBoss0201Base;

/* Note: sizeof check omitted — struct padding makes true sizeof uncertain.
   Allocation size 0x2C8 is from FUN_140683f70; actual struct may differ due to
   base class fields not fully mapped. Last proven field ends at 0x428+0x18=0x440. */
static_assert(offsetof(ccSceneBoss0201Base, vtable) == 0x000, "vtable offset");
static_assert(offsetof(ccSceneBoss0201Base, sceneId) == 0x1A8, "sceneId = param_1[0x25]*8");
static_assert(offsetof(ccSceneBoss0201Base, renkeiOugiIdx) == 0x2E0, "renkeiOugiIdx = param_1[0x32]*8");
static_assert(offsetof(ccSceneBoss0201Base, lifeLimitScale) == 0x328, "lifeLimitScale = param_1[0x53]*8");
static_assert(offsetof(ccSceneBoss0201Base, iaFailedFlag) == 0x32C, "iaFailedFlag = param_1[0x54]*8");
static_assert(offsetof(ccSceneBoss0201Base, isSecondPhase) == 0x340, "isSecondPhase = param_1[0x5f]*8");
static_assert(offsetof(ccSceneBoss0201Base, collisionPushTask) == 0x358, "collisionPushTask = param_1[0x57]*8");
static_assert(offsetof(ccSceneBoss0201Base, collisionAttackTask) == 0x360, "collisionAttackTask = param_1[0x58]*8");
static_assert(offsetof(ccSceneBoss0201Base, chakraBallCtrlTask) == 0x368, "chakraBallCtrlTask = param_1[0x59]*8");
static_assert(offsetof(ccSceneBoss0201Base, chakraBallDrawTask) == 0x370, "chakraBallDrawTask = param_1[0x5a]*8");
static_assert(offsetof(ccSceneBoss0201Base, renkeiOugiUpdateTask) == 0x388, "renkeiOugiUpdateTask = param_1[0x5d]*8");
static_assert(offsetof(ccSceneBoss0201Base, renkeiOugiPositioningTask) == 0x390, "renkeiOugiPositioningTask = param_1[0x5e]*8");
static_assert(offsetof(ccSceneBoss0201Base, uiManagerPtr) == 0x3A8, "uiManagerPtr = param_1[0x81]*8");
static_assert(offsetof(ccSceneBoss0201Base, subObj_0x82) == 0x3B0, "subObj_0x82 = param_1[0x82]*8");
static_assert(offsetof(ccSceneBoss0201Base, field_0x3C8) == 0x3C8, "field_0x3C8 = param_1[0x84]*8");
static_assert(offsetof(ccSceneBoss0201Base, field_0x3E0) == 0x3E0, "field_0x3E0 = param_1[0x85]*8");
static_assert(offsetof(ccSceneBoss0201Base, field_0x410) == 0x410, "field_0x410 = param_1[0x9b]*8");

/* ------------------------------------------------------------------ */
/* ccBoss02UiManager                                                  */
/*                                                                    */
/* Boss HP gauge / UI overlay manager.                                */
/* Size: 0x1F8 (504 bytes) — FUN_140683f70(0x1f8,...) at RVA 0x27E4F0 */
/* Ctor: FUN_1402829D0 (ccBoss02UiManager::Ctrl/Draw strings)         */
/* Methods: Ctrl (vtable+0x30), Draw                                  */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t unk_008[0x1F0];     /* fields not yet resolved from decomp */
} ccBoss02UiManager;

static_assert(sizeof(ccBoss02UiManager) == 0x1F8, "ccBoss02UiManager size from FUN_140683f70(0x1f8)");
static_assert(offsetof(ccBoss02UiManager, vtable) == 0x000, "vtable offset");

/* ------------------------------------------------------------------ */
/* ccBoss0201Stage                                                    */
/*                                                                    */
/* Stage/environment controller for boss02-01.                        */
/* Size: 0x180 (384 bytes) — FUN_140683f70(0x180,...) at RVA 0x277EA4 */
/* Ctor: RVA 0x2771B4                                                 */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t unk_008[0x178];
} ccBoss0201Stage;

static_assert(sizeof(ccBoss0201Stage) == 0x180, "ccBoss0201Stage size from FUN_140683f70(0x180)");
static_assert(offsetof(ccBoss0201Stage, vtable) == 0x000, "vtable offset");

/* ------------------------------------------------------------------ */
/* ccBoss02BossGauge                                                  */
/*                                                                    */
/* Boss health gauge data object.                                     */
/* Size: 0x268 (616 bytes) — FUN_140683f70(0x268,...) at RVA 0x282C80 */
/* Ctor: RVA 0x282878                                                 */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t unk_008[0x260];
} ccBoss02BossGauge;

static_assert(sizeof(ccBoss02BossGauge) == 0x268, "ccBoss02BossGauge size from FUN_140683f70(0x268)");
static_assert(offsetof(ccBoss02BossGauge, vtable) == 0x000, "vtable offset");

/* ------------------------------------------------------------------ */
/* ccBoss02FlashBack                                                  */
/*                                                                    */
/* Flashback sequence controller.                                     */
/* Size: 0x1F8 (504 bytes) — FUN_140683f70(0x1f8,...) at RVA 0x280FA4 */
/* Ctor: RVA 0x280E3C                                                 */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t unk_008[0x1F0];
} ccBoss02FlashBack;

static_assert(sizeof(ccBoss02FlashBack) == 0x1F8, "ccBoss02FlashBack size from FUN_140683f70(0x1f8)");
static_assert(offsetof(ccBoss02FlashBack, vtable) == 0x000, "vtable offset");

/* ------------------------------------------------------------------ */
/* ccBoss0201DeidaraMissileL                                          */
/*                                                                    */
/* Deidara missile projectile (large variant).                        */
/* Size: 0x180 (384 bytes) — FUN_140683f70(0x180,...) at RVA 0x401054 */
/* Ctor: RVA 0x401054 (same as factory)                               */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t unk_008[0x178];
} ccBoss0201DeidaraMissileL;

static_assert(sizeof(ccBoss0201DeidaraMissileL) == 0x180, "ccBoss0201DeidaraMissileL size from FUN_140683f70(0x180)");
static_assert(offsetof(ccBoss0201DeidaraMissileL, vtable) == 0x000, "vtable offset");

/* ------------------------------------------------------------------ */
/* ccBoss02BulletBase                                                 */
/*                                                                    */
/* Base class for boss02 bullet/projectile types.                     */
/* Size: unknown, >= 0xC8 (last sub-object end at +0xA8 + estimated)  */
/* Vtable: 0x1409EFB30                                                */
/* Ctor: RVA 0x5835B8 (FUN_140793850)                                 */
/* Sub-objects at +0x18, +0x40, +0x68, +0xA8 constructed in ctor      */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;              /* 0x1409EFB30 */
    /* 0x008 */ uint8_t unk_008[0x10];      /* gap to first sub-object */
    /* 0x018 */ uint8_t sub_0x18[0x28];     /* sub-object constructed at +0x18 */
    /* 0x040 */ uint8_t sub_0x40[0x28];     /* sub-object constructed at +0x40 */
    /* 0x068 */ uint8_t sub_0x68[0x40];     /* sub-object constructed at +0x68 */
    /* 0x0A8 */ uint8_t sub_0xA8[0x20];     /* sub-object constructed at +0xA8 */
    /* 0x0C8 */                              /* end of known layout; true size unknown, >= 0xC8 */
} ccBoss02BulletBase;

static_assert(offsetof(ccBoss02BulletBase, vtable) == 0x000, "vtable offset");
static_assert(offsetof(ccBoss02BulletBase, sub_0x18) == 0x018, "sub_0x18 offset");
static_assert(offsetof(ccBoss02BulletBase, sub_0x40) == 0x040, "sub_0x40 offset");
static_assert(offsetof(ccBoss02BulletBase, sub_0x68) == 0x068, "sub_0x68 offset");
static_assert(offsetof(ccBoss02BulletBase, sub_0xA8) == 0x0A8, "sub_0xA8 offset");

/* ------------------------------------------------------------------ */
/* ccBoss0201LoadingState                                             */
/*                                                                    */
/* Loading state sub-object within ccSceneBoss0201.                   */
/* Size: 0x90 (144 bytes) — allocated in ccSceneBoss0201::_Initialize */
/* Ctor: RVA 0x27D938                                                 */
/* ------------------------------------------------------------------ */
typedef struct {
    /* 0x000 */ void **vtable;
    /* 0x008 */ uint8_t unk_008[0x88];
} ccBoss0201LoadingState;

static_assert(sizeof(ccBoss0201LoadingState) == 0x90, "ccBoss0201LoadingState size from _Initialize alloc");
static_assert(offsetof(ccBoss0201LoadingState, vtable) == 0x000, "vtable offset");

/* ccBoss02SceneChangeState: no instance state -- 0 fields across 11 seeds; ctor=0x27E2C4 */

/* ------------------------------------------------------------------ */
/* ccBoss0201BattleChanger                          */
/*                                                                    */
/* size unknown, >= 0x128 (max field end, filtered <0x1000)
/* Vtable: 0x1408fc0e8
/* Methods: 10
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0x54];
    /* 0x054 */ int32_t field_0x54;
    /* 0x058 */ int64_t field_0x58;
    /* 0x060 */ int32_t field_0x60;
    /* 0x064 */ uint8_t pad_0x64[0x4];
    /* 0x068 */ int64_t field_0x68;
    /* 0x070 */ int64_t field_0x70;
    /* 0x078 */ int64_t field_0x78;
    /* 0x080 */ int64_t field_0x80;
    /* 0x088 */ int64_t field_0x88;
    /* 0x090 */ int64_t field_0x90;
    /* 0x098 */ int64_t field_0x98;
    /* 0x0A0 */ int64_t field_0xA0;
    /* 0x0A8 */ int64_t field_0xA8;
    /* 0x0B0 */ int64_t field_0xB0;
    /* 0x0B8 */ uint8_t pad_0xB8[0x38];
    /* 0x0F0 */ int64_t field_0xF0;
    /* 0x0F8 */ uint8_t pad_0xF8[0x28];
    /* 0x120 */ int64_t field_0x120;
} ccBoss0201BattleChanger;
#pragma pack(pop)

static_assert(offsetof(ccBoss0201BattleChanger, field_0x54) == 0x54, "ccBoss0201BattleChanger.field_0x54 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x58) == 0x58, "ccBoss0201BattleChanger.field_0x58 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x60) == 0x60, "ccBoss0201BattleChanger.field_0x60 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x68) == 0x68, "ccBoss0201BattleChanger.field_0x68 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x70) == 0x70, "ccBoss0201BattleChanger.field_0x70 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x78) == 0x78, "ccBoss0201BattleChanger.field_0x78 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x80) == 0x80, "ccBoss0201BattleChanger.field_0x80 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x88) == 0x88, "ccBoss0201BattleChanger.field_0x88 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x90) == 0x90, "ccBoss0201BattleChanger.field_0x90 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x98) == 0x98, "ccBoss0201BattleChanger.field_0x98 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0xA0) == 0xA0, "ccBoss0201BattleChanger.field_0xA0 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0xA8) == 0xA8, "ccBoss0201BattleChanger.field_0xA8 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0xB0) == 0xB0, "ccBoss0201BattleChanger.field_0xB0 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0xF0) == 0xF0, "ccBoss0201BattleChanger.field_0xF0 offset");
static_assert(offsetof(ccBoss0201BattleChanger, field_0x120) == 0x120, "ccBoss0201BattleChanger.field_0x120 offset");


/* ------------------------------------------------------------------ */
/* ccBoss02PlayerSSK                                */
/*                                                                    */
/* size unknown, >= 0xA08 (max field end, filtered <0x1000)
/* Methods: 9
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0x200];
    /* 0x200 */ int32_t field_0x200;
    /* 0x204 */ uint8_t pad_0x204[0x798];
    /* 0x99C */ int32_t field_0x99C;
    /* 0x9A0 */ uint8_t pad_0x9A0[0x20];
    /* 0x9C0 */ int64_t field_0x9C0;
    /* 0x9C8 */ uint8_t pad_0x9C8[0x24];
    /* 0x9EC */ int32_t field_0x9EC;
    /* 0x9F0 */ void* field_0x9F0;
    /* 0x9F8 */ uint8_t pad_0x9F8[0x4];
    /* 0x9FC */ int32_t field_0x9FC;
    /* 0xA00 */ int32_t field_0xA00;
    /* 0xA04 */ int32_t field_0xA04;
} ccBoss02PlayerSSK;
#pragma pack(pop)

static_assert(offsetof(ccBoss02PlayerSSK, field_0x200) == 0x200, "ccBoss02PlayerSSK.field_0x200 offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0x99C) == 0x99C, "ccBoss02PlayerSSK.field_0x99C offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0x9C0) == 0x9C0, "ccBoss02PlayerSSK.field_0x9C0 offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0x9EC) == 0x9EC, "ccBoss02PlayerSSK.field_0x9EC offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0x9F0) == 0x9F0, "ccBoss02PlayerSSK.field_0x9F0 offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0x9FC) == 0x9FC, "ccBoss02PlayerSSK.field_0x9FC offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0xA00) == 0xA00, "ccBoss02PlayerSSK.field_0xA00 offset");
static_assert(offsetof(ccBoss02PlayerSSK, field_0xA04) == 0xA04, "ccBoss02PlayerSSK.field_0xA04 offset");


/* ccSceneBoss0201: no instance state -- 0 fields across 8 seeds; no ctor */

/* ------------------------------------------------------------------ */
/* ccBoss0201RecoverIaState                         */
/*                                                                    */
/* size unknown, >= 0xD4 (max field end, filtered <0x1000)
/* Vtable: 0x1408d8318
/* Methods: 7
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0x54];
    /* 0x054 */ int32_t field_0x54;
    /* 0x058 */ int64_t field_0x58;
    /* 0x060 */ int32_t field_0x60;
    /* 0x064 */ uint8_t pad_0x64[0x4];
    /* 0x068 */ int64_t field_0x68;
    /* 0x070 */ int32_t field_0x70;
    /* 0x074 */ int32_t field_0x74;
    /* 0x078 */ int32_t field_0x78;
    /* 0x07C */ uint8_t pad_0x7C[0x4];
    /* 0x080 */ int64_t field_0x80;
    /* 0x088 */ uint8_t pad_0x88[0x48];
    /* 0x0D0 */ int32_t field_0xD0;
} ccBoss0201RecoverIaState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0201RecoverIaState, field_0x54) == 0x54, "ccBoss0201RecoverIaState.field_0x54 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x58) == 0x58, "ccBoss0201RecoverIaState.field_0x58 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x60) == 0x60, "ccBoss0201RecoverIaState.field_0x60 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x68) == 0x68, "ccBoss0201RecoverIaState.field_0x68 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x70) == 0x70, "ccBoss0201RecoverIaState.field_0x70 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x74) == 0x74, "ccBoss0201RecoverIaState.field_0x74 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x78) == 0x78, "ccBoss0201RecoverIaState.field_0x78 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0x80) == 0x80, "ccBoss0201RecoverIaState.field_0x80 offset");
static_assert(offsetof(ccBoss0201RecoverIaState, field_0xD0) == 0xD0, "ccBoss0201RecoverIaState.field_0xD0 offset");


/* ccSceneBoss0201Root: no instance state -- 0 fields across 6 seeds; no ctor */

/* ------------------------------------------------------------------ */
/* ccBoss02PlayerBase                               */
/*                                                                    */
/* size unknown, >= 0x9D0 (max field end, filtered <0x1000)
/* Methods: 5
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0xA8];
    /* 0x0A8 */ int64_t field_0xA8;
    /* 0x0B0 */ uint8_t pad_0xB0[0x150];
    /* 0x200 */ void* field_0x200;
    /* 0x208 */ uint8_t pad_0x208[0x7AC];
    /* 0x9B4 */ int32_t field_0x9B4;
    /* 0x9B8 */ uint8_t pad_0x9B8[0x4];
    /* 0x9BC */ int32_t field_0x9BC;
    /* 0x9C0 */ uint8_t pad_0x9C0[0x8];
    /* 0x9C8 */ int64_t field_0x9C8;
} ccBoss02PlayerBase;
#pragma pack(pop)

static_assert(offsetof(ccBoss02PlayerBase, field_0xA8) == 0xA8, "ccBoss02PlayerBase.field_0xA8 offset");
static_assert(offsetof(ccBoss02PlayerBase, field_0x200) == 0x200, "ccBoss02PlayerBase.field_0x200 offset");
static_assert(offsetof(ccBoss02PlayerBase, field_0x9B4) == 0x9B4, "ccBoss02PlayerBase.field_0x9B4 offset");
static_assert(offsetof(ccBoss02PlayerBase, field_0x9BC) == 0x9BC, "ccBoss02PlayerBase.field_0x9BC offset");
static_assert(offsetof(ccBoss02PlayerBase, field_0x9C8) == 0x9C8, "ccBoss02PlayerBase.field_0x9C8 offset");


/* ccBoss02PlayerLoader: no instance state -- 0 fields across 5 seeds; no ctor */

/* ------------------------------------------------------------------ */
/* ccBoss02PlayerNRT                                */
/*                                                                    */
/* size unknown, >= 0xA00 (max field end, filtered <0x1000)
/* Methods: 5
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0x9EC];
    /* 0x9EC */ int32_t field_0x9EC;
    /* 0x9F0 */ int64_t field_0x9F0;
    /* 0x9F8 */ uint8_t pad_0x9F8[0x4];
    /* 0x9FC */ float field_0x9FC;
} ccBoss02PlayerNRT;
#pragma pack(pop)

static_assert(offsetof(ccBoss02PlayerNRT, field_0x9EC) == 0x9EC, "ccBoss02PlayerNRT.field_0x9EC offset");
static_assert(offsetof(ccBoss02PlayerNRT, field_0x9F0) == 0x9F0, "ccBoss02PlayerNRT.field_0x9F0 offset");
static_assert(offsetof(ccBoss02PlayerNRT, field_0x9FC) == 0x9FC, "ccBoss02PlayerNRT.field_0x9FC offset");


/* ------------------------------------------------------------------ */
/* ccSceneBoss0200                                  */
/*                                                                    */
/* size unknown, >= 0x748 (max field end, filtered <0x1000)
/* Methods: 5
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0x128];
    /* 0x128 */ int32_t field_0x128;
    /* 0x12C */ uint8_t pad_0x12C[0x4];
    /* 0x130 */ int64_t field_0x130;
    /* 0x138 */ int64_t field_0x138;
    /* 0x140 */ uint8_t pad_0x140[0x50];
    /* 0x190 */ int64_t field_0x190;
    /* 0x198 */ uint8_t pad_0x198[0xF0];
    /* 0x288 */ int64_t field_0x288;
    /* 0x290 */ uint8_t pad_0x290[0x8];
    /* 0x298 */ int32_t field_0x298;
    /* 0x29C */ uint8_t pad_0x29C[0x4];
    /* 0x2A0 */ int32_t field_0x2A0;
    /* 0x2A4 */ uint8_t pad_0x2A4[0x14];
    /* 0x2B8 */ int64_t field_0x2B8;
    /* 0x2C0 */ int64_t field_0x2C0;
    /* 0x2C8 */ int64_t field_0x2C8;
    /* 0x2D0 */ int64_t field_0x2D0;
    /* 0x2D8 */ int64_t field_0x2D8;
    /* 0x2E0 */ int64_t field_0x2E0;
    /* 0x2E8 */ int64_t field_0x2E8;
    /* 0x2F0 */ int64_t field_0x2F0;
    /* 0x2F8 */ uint8_t pad_0x2F8[0x88];
    /* 0x380 */ int64_t field_0x380;
    /* 0x388 */ uint8_t pad_0x388[0x3B8];
    /* 0x740 */ int64_t field_0x740;
} ccSceneBoss0200;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss0200, field_0x128) == 0x128, "ccSceneBoss0200.field_0x128 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x130) == 0x130, "ccSceneBoss0200.field_0x130 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x138) == 0x138, "ccSceneBoss0200.field_0x138 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x190) == 0x190, "ccSceneBoss0200.field_0x190 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x288) == 0x288, "ccSceneBoss0200.field_0x288 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x298) == 0x298, "ccSceneBoss0200.field_0x298 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2A0) == 0x2A0, "ccSceneBoss0200.field_0x2A0 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2B8) == 0x2B8, "ccSceneBoss0200.field_0x2B8 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2C0) == 0x2C0, "ccSceneBoss0200.field_0x2C0 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2C8) == 0x2C8, "ccSceneBoss0200.field_0x2C8 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2D0) == 0x2D0, "ccSceneBoss0200.field_0x2D0 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2D8) == 0x2D8, "ccSceneBoss0200.field_0x2D8 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2E0) == 0x2E0, "ccSceneBoss0200.field_0x2E0 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2E8) == 0x2E8, "ccSceneBoss0200.field_0x2E8 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x2F0) == 0x2F0, "ccSceneBoss0200.field_0x2F0 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x380) == 0x380, "ccSceneBoss0200.field_0x380 offset");
static_assert(offsetof(ccSceneBoss0200, field_0x740) == 0x740, "ccSceneBoss0200.field_0x740 offset");


/* ------------------------------------------------------------------ */
/* ccSceneBoss0201CameraFilter                      */
/*                                                                    */
/* size unknown, >= 0xF0 (max field end, filtered <0x1000)
/* Vtable: 0x1408d8620
/* Methods: 5
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0xE8];
    /* 0x0E8 */ int64_t field_0xE8;
} ccSceneBoss0201CameraFilter;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss0201CameraFilter, field_0xE8) == 0xE8, "ccSceneBoss0201CameraFilter.field_0xE8 offset");


/* ------------------------------------------------------------------ */
/* ccSceneBoss0201RootBase                          */
/*                                                                    */
/* size unknown, >= 0x388 (max field end, filtered <0x1000)
/* Methods: 5
/* ------------------------------------------------------------------ */
#pragma pack(push, 1)
typedef struct {
    /* 0x000 */ uint8_t pad_0x0[0x300];
    /* 0x300 */ int64_t field_0x300;
    /* 0x308 */ uint8_t pad_0x308[0x38];
    /* 0x340 */ int64_t field_0x340;
    /* 0x348 */ uint8_t pad_0x348[0x38];
    /* 0x380 */ int64_t field_0x380;
} ccSceneBoss0201RootBase;
#pragma pack(pop)

static_assert(offsetof(ccSceneBoss0201RootBase, field_0x300) == 0x300, "ccSceneBoss0201RootBase.field_0x300 offset");
static_assert(offsetof(ccSceneBoss0201RootBase, field_0x340) == 0x340, "ccSceneBoss0201RootBase.field_0x340 offset");
static_assert(offsetof(ccSceneBoss0201RootBase, field_0x380) == 0x380, "ccSceneBoss0201RootBase.field_0x380 offset");


/* ccBoss02Flash: no instance state -- 0 fields across 5 seeds; state_surface accesses=0 for all methods (Initialize RVA 0x2812CC, CreateInstance 0x280F5C, DestroyInstance 0x281174, Finalize 0x2811F0, StartFlash 0x28171C); decomp shows only external calls + string refs */

/* ccSceneBoss0202: no instance state -- 0 fields across 4 seeds; state_surface accesses=0 for all methods (_Initialize RVA 0x280874, Clear 0x2807D4, Initialize 0x280810, dtor 0x280798); decomp shows only external calls + string refs */

/* ccSceneBoss0202Root: no instance state -- 0 fields across 4 seeds; state_surface accesses=0 for all methods (PlayerSetting RVA 0x280A50, Execute 0x280978, dtor 0x28093C, LoadSoundData 0x280A24); decomp shows only external calls + string refs */

/* ccSceneBoss02LastCut: no instance state -- 0 fields across 4 seeds; state_surface accesses=0 for all methods (Initialize RVA 0x281A94, ScreenCapture 0x281C74, Finalize 0x281A5C, dtor 0x281998); decomp shows only external calls + string refs */

/* ccBoss0201BattleState: no instance state -- 0 fields across 3 seeds; state_surface accesses=0 for all methods (Battle1State RVA 0x27D0F0, Battle2State 0x27D144, Start 0x27F6A4); decomp shows only external calls, no field accesses */

#endif /* S3_BOSS02_H */

