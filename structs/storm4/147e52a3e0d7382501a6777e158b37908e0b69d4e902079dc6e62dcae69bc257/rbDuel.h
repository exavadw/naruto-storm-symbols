/* rbDuel s4 — NARUTO STORM 4 (NSUNS4_release.exe, 64-bit, v1.09)
 * Build: s4 / NSUNS4_release.exe
 * Date: 2026-10-19
 * Status: INFERRED (static analysis only; no runtime trace)
 *
 * All fields derived from Ghidra decompilation of s4 binary via the decompiler cache.
 * Names from s4 symbols/strings only (own-game rule).
 * Sizes are lower bounds unless proven by operator new / allocator call.
 * Cross-reference: s3/rbDuel.h for structural comparison.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccDuelJudge — duel scoring / achievement tracker
 * Evidence: ccDuelJudge::Clear (RVA 0x74CDD4)
 * Size: unknown, >= 0xD8 (last write at offset 0xD4, size 8 → end 0xDC)
 * Vtable: none (not polymorphic; initialized via Clear)
 *
 * Field layout from Clear:
 *   0x2C, 0x3C, 0x90, 0xA4: pointer reads (low confidence, loop iterators)
 *   0x74: u64 write = 0       (slot/counter reset)
 *   0x7C: u32 write = 0
 *   0x80: u32 write = 2
 *   0xAC–0xC4: five u64 writes = 0  (score/achievement slots)
 *   0xCC: u64 write = &DAT_100000001 (flag pair packed as u64)
 *   0xD4: u64 write = 1       (enable flag)
 */
typedef struct __attribute__((packed)) ccDuelJudge_s4 {
    /* 0x00 */ uint8_t pad_00[0x2C];                          /* no typed access seen */
    /* 0x2C */ uint8_t iter_region_2C[0x10];                  /* loop iterator region (ptr read in Clear) */
    /* 0x3C */ uint8_t iter_region_3C[0x38];                  /* loop iterator region (ptr read in Clear) */
    /* 0x74 */ int64_t slot_counter;                          /* Clear: *(u8*)(p+0x74)=0 */
    /* 0x7C */ int32_t field_7C;                              /* Clear: *(u4*)(p+0x7C)=0 */
    /* 0x80 */ int32_t field_80;                              /* Clear: *(u4*)(p+0x80)=2 */
    /* 0x84 */ uint8_t pad_84[0x08];                          /* gap to 0x8C */
    /* 0x8C */ uint8_t pad_8C[0x04];                          /* gap to 0x90 */
    /* 0x90 */ uint8_t iter_region_90[0x14];                  /* loop iterator region (ptr read in Clear) */
    /* 0xA4 */ uint8_t iter_region_A4[0x08];                  /* loop iterator region (ptr read in Clear) */
    /* 0xAC */ int64_t score_slot_0;                          /* Clear: *(u8*)(p+0xAC)=0 */
    /* 0xB4 */ int64_t score_slot_1;                          /* Clear: *(u8*)(p+0xB4)=0 */
    /* 0xBC */ int64_t score_slot_2;                          /* Clear: *(u8*)(p+0xBC)=0 */
    /* 0xC4 */ int64_t score_slot_3;                          /* Clear: *(u8*)(p+0xC4)=0 */
    /* 0xCC */ int64_t flag_pair;                             /* Clear: *(u8*)(p+0xCC)=&DAT_100000001 */
    /* 0xD4 */ int64_t enable_flag;                           /* Clear: *(u8*)(p+0xD4)=1 */
} ccDuelJudge_s4;

static_assert(offsetof(ccDuelJudge_s4, iter_region_2C) == 0x2C, "ccDuelJudge_s4.iter_region_2C");
static_assert(offsetof(ccDuelJudge_s4, iter_region_3C) == 0x3C, "ccDuelJudge_s4.iter_region_3C");
static_assert(offsetof(ccDuelJudge_s4, slot_counter) == 0x74, "ccDuelJudge_s4.slot_counter");
static_assert(offsetof(ccDuelJudge_s4, field_7C) == 0x7C, "ccDuelJudge_s4.field_7C");
static_assert(offsetof(ccDuelJudge_s4, field_80) == 0x80, "ccDuelJudge_s4.field_80");
static_assert(offsetof(ccDuelJudge_s4, iter_region_90) == 0x90, "ccDuelJudge_s4.iter_region_90");
static_assert(offsetof(ccDuelJudge_s4, iter_region_A4) == 0xA4, "ccDuelJudge_s4.iter_region_A4");
static_assert(offsetof(ccDuelJudge_s4, score_slot_0) == 0xAC, "ccDuelJudge_s4.score_slot_0");
static_assert(offsetof(ccDuelJudge_s4, score_slot_1) == 0xB4, "ccDuelJudge_s4.score_slot_1");
static_assert(offsetof(ccDuelJudge_s4, score_slot_2) == 0xBC, "ccDuelJudge_s4.score_slot_2");
static_assert(offsetof(ccDuelJudge_s4, score_slot_3) == 0xC4, "ccDuelJudge_s4.score_slot_3");
static_assert(offsetof(ccDuelJudge_s4, flag_pair) == 0xCC, "ccDuelJudge_s4.flag_pair");
static_assert(offsetof(ccDuelJudge_s4, enable_flag) == 0xD4, "ccDuelJudge_s4.enable_flag");

/* ccDuelManager — manages duel players, teams, conditions
 * Evidence: ccDuelManager::ccDuelManager (RVA 0x74CD48), Clear (0x74DC2C),
 *           CreatePlayer (0x74DDB8), SetupDuelCondition (0x74E808)
 * Vtable: at offset 0x00 (vtable+0x10 called in multiple methods)
 * Size: unknown, >= 0xF8 (last typed read at 0xF0, size 8)
 *
 * Key fields:
 *   0x3C: u32 write in ctor (player slot init)
 *   0x80: vtable+0x10 indirect call target (read in 6 functions)
 *   0xE8: sub-object passed to FUN_1407489cc (Clear + SetupDuelCondition)
 *   0xF0: u64 read in SetupDuelCondition (param index for FUN_14074d1f8)
 *   0x108: sub-object (plVar1 = p+0x21 → byte 0x108)
 *   0x170: sub-object (plVar6 = p+0x2e → byte 0x170)
 */
typedef struct __attribute__((packed)) ccDuelManager_s4 {
    /* 0x00 */ void *vtable;                                  /* vtable+0x10 called in Clear/CreatePlayer/etc */
    /* 0x08 */ uint8_t pad_08[0x34];                          /* gap to 0x3C */
    /* 0x3C */ int32_t player_slot_init;                      /* ctor: *(u4*)(p+0x3C) set */
    /* 0x40 */ uint8_t pad_40[0x40];                          /* gap to 0x80 */
    /* 0x80 */ uint8_t dispatch_region_80[0x68];              /* vtable dispatch + sub-object region */
    /* 0xE8 */ uint8_t subobj_E8[0x08];                       /* passed to FUN_1407489cc */
    /* 0xF0 */ int64_t setup_param;                           /* SetupDuelCondition: read as param index */
    /* 0xF8 */ uint8_t pad_F8[0x10];                          /* gap to 0x108 */
    /* 0x108 */ uint8_t subobj_108[0x68];                     /* plVar1 region (p+0x21) */
    /* 0x170 */ uint8_t subobj_170[0x08];                     /* plVar6 region (p+0x2e) */
} ccDuelManager_s4;

static_assert(offsetof(ccDuelManager_s4, vtable) == 0x00, "ccDuelManager_s4.vtable");
static_assert(offsetof(ccDuelManager_s4, player_slot_init) == 0x3C, "ccDuelManager_s4.player_slot_init");
static_assert(offsetof(ccDuelManager_s4, dispatch_region_80) == 0x80, "ccDuelManager_s4.dispatch_region_80");
static_assert(offsetof(ccDuelManager_s4, subobj_E8) == 0xE8, "ccDuelManager_s4.subobj_E8");
static_assert(offsetof(ccDuelManager_s4, setup_param) == 0xF0, "ccDuelManager_s4.setup_param");
static_assert(offsetof(ccDuelManager_s4, subobj_108) == 0x108, "ccDuelManager_s4.subobj_108");
static_assert(offsetof(ccDuelManager_s4, subobj_170) == 0x170, "ccDuelManager_s4.subobj_170");

/* ccDuelSettingInfo — duel parameter configuration
 * Evidence: ccDuelSettingInfo::Clear (RVA 0x748A20)
 * Size: unknown, >= 0xA4 (last write at 0xA0, size 4)
 *
 * Clear writes:
 *   0x60: u32 = 0
 *   0xA0: u32 = 0
 *   0x68: memset(p+0x68, 0, 0x38) → clears 0x68..0x9F
 */
typedef struct __attribute__((packed)) ccDuelSettingInfo_s4 {
    /* 0x00 */ uint8_t pad_00[0x60];                          /* no typed access seen */
    /* 0x60 */ int32_t basic_param_count;                     /* Clear: *(u4*)(p+0x60)=0 */
    /* 0x64 */ uint8_t pad_64[0x04];                          /* gap */
    /* 0x68 */ uint8_t params_block[0x38];                    /* Clear: memset(p+0x68,0,0x38) */
    /* 0xA0 */ int32_t special_param_count;                   /* Clear: *(u4*)(p+0xA0)=0 */
} ccDuelSettingInfo_s4;

static_assert(offsetof(ccDuelSettingInfo_s4, basic_param_count) == 0x60, "ccDuelSettingInfo_s4.basic_param_count");
static_assert(offsetof(ccDuelSettingInfo_s4, params_block) == 0x68, "ccDuelSettingInfo_s4.params_block");
static_assert(offsetof(ccDuelSettingInfo_s4, special_param_count) == 0xA0, "ccDuelSettingInfo_s4.special_param_count");

/* ccDuelSituation — composite duel state container
 * Evidence: ccDuelSituation::ccDuelSituation (RVA 0x74D7D8)
 * Vtable: at offset 0x00 (inferred from s3 pattern)
 * Size: unknown, >= 0x258 (last sub-object at p+0x4a → byte 0x250, size unknown)
 *
 * Ctor sub-object layout (param_1 is undefined8*):
 *   0xE8: FUN_140748960(p+0x1d) → byte offset 0xE8
 *   0x108: p+0x21 → byte offset 0x108 (sub-object)
 *   0x170: FUN_14074cd48(p+0x2e) → byte offset 0x170
 *   0x250: p+0x4a → byte offset 0x250 (sub-object)
 */
typedef struct __attribute__((packed)) ccDuelSituation_s4 {
    /* 0x000 */ void *vtable;                                 /* inferred from s3 pattern */
    /* 0x008 */ uint8_t pad_008[0xE0];                        /* gap to 0xE8 */
    /* 0x0E8 */ uint8_t subobj_E8[0x20];                      /* FUN_140748960 at p+0x1d */
    /* 0x108 */ uint8_t subobj_108[0x68];                     /* p+0x21 region */
    /* 0x170 */ uint8_t subobj_170[0xE0];                     /* FUN_14074cd48 at p+0x2e */
    /* 0x250 */ uint8_t subobj_250[0x08];                     /* p+0x4a region */
} ccDuelSituation_s4;

static_assert(offsetof(ccDuelSituation_s4, vtable) == 0x000, "ccDuelSituation_s4.vtable");
static_assert(offsetof(ccDuelSituation_s4, subobj_E8) == 0x0E8, "ccDuelSituation_s4.subobj_E8");
static_assert(offsetof(ccDuelSituation_s4, subobj_108) == 0x108, "ccDuelSituation_s4.subobj_108");
static_assert(offsetof(ccDuelSituation_s4, subobj_170) == 0x170, "ccDuelSituation_s4.subobj_170");
static_assert(offsetof(ccDuelSituation_s4, subobj_250) == 0x250, "ccDuelSituation_s4.subobj_250");

/* ccDuelTeam — team state (life, chakra, support gauge, items, players)
 * Evidence: ccDuelTeam::ccDuelTeam (RVA 0x74ABC8), ConvPlayerRole2Support (0x7B03B4),
 *           GetSupportGaugeValue (0x7E4E84)
 * Vtable: at offset 0x00 (vtable+0x10 and vtable+0x40 called)
 * Size: unknown, >= 0x14A38 (last access at 0x14A30, ptr read)
 *
 * This is a LARGE struct (~84KB). Key typed fields:
 *   0x34: u32 write = 0 in ctor
 *   0x58: u64 write in ctor (CONCAT44 pair)
 *   0x60: u64 write in ctor
 *   0x80: vtable+0x10 dispatch
 *   0x200: vtable+0x40 dispatch (GetSupportGaugeValue)
 *   0xB00: u64 read (sub-object ptr, vtable+0x10 called on it)
 *   0x14A18: u64 read (iterator end ptr for player list)
 *   0x14A20: u64 rw (iterator current ptr for player list)
 *   0x14A30: sub-object passed to FUN_140a01d60
 */
typedef struct __attribute__((packed)) ccDuelTeam_s4 {
    /* 0x00000 */ void *vtable;                               /* vtable+0x10, vtable+0x40 called */
    /* 0x00008 */ uint8_t pad_008[0x2C];                      /* gap to 0x34 */
    /* 0x00034 */ int32_t field_34;                           /* ctor: *(u4*)(p+0x34)=0 */
    /* 0x00038 */ uint8_t pad_038[0x20];                      /* gap to 0x58 */
    /* 0x00058 */ int64_t field_58;                           /* ctor: CONCAT44 pair */
    /* 0x00060 */ int64_t field_60;                           /* ctor: u64 write */
    /* 0x00068 */ uint8_t pad_068[0x18];                      /* gap to 0x80 */
    /* 0x00080 */ uint8_t dispatch_80[0x180];                 /* vtable dispatch region */
    /* 0x00200 */ uint8_t dispatch_200[0x900];                /* vtable+0x40 region to 0xB00 */
    /* 0x00B00 */ int64_t support_gauge_obj;                  /* GetSupportGaugeValue: ptr, vtable+0x10 called */
    /* 0x00B08 */ uint8_t pad_B08[0x13F10];                   /* large gap to player list region */
    /* 0x14A18 */ int64_t player_list_end;                    /* ConvPlayerRole2Support: iterator end */
    /* 0x14A20 */ int64_t player_list_current;                /* ConvPlayerRole2Support: iterator current (rw) */
    /* 0x14A28 */ uint8_t pad_14A28[0x08];                    /* gap */
    /* 0x14A30 */ uint8_t subobj_14A30[0x08];                 /* passed to FUN_140a01d60 */
} ccDuelTeam_s4;

static_assert(offsetof(ccDuelTeam_s4, vtable) == 0x00000, "ccDuelTeam_s4.vtable");
static_assert(offsetof(ccDuelTeam_s4, field_34) == 0x00034, "ccDuelTeam_s4.field_34");
static_assert(offsetof(ccDuelTeam_s4, field_58) == 0x00058, "ccDuelTeam_s4.field_58");
static_assert(offsetof(ccDuelTeam_s4, field_60) == 0x00060, "ccDuelTeam_s4.field_60");
static_assert(offsetof(ccDuelTeam_s4, dispatch_80) == 0x00080, "ccDuelTeam_s4.dispatch_80");
static_assert(offsetof(ccDuelTeam_s4, dispatch_200) == 0x00200, "ccDuelTeam_s4.dispatch_200");
static_assert(offsetof(ccDuelTeam_s4, support_gauge_obj) == 0x00B00, "ccDuelTeam_s4.support_gauge_obj");
static_assert(offsetof(ccDuelTeam_s4, player_list_end) == 0x14A18, "ccDuelTeam_s4.player_list_end");
static_assert(offsetof(ccDuelTeam_s4, player_list_current) == 0x14A20, "ccDuelTeam_s4.player_list_current");
static_assert(offsetof(ccDuelTeam_s4, subobj_14A30) == 0x14A30, "ccDuelTeam_s4.subobj_14A30");

/* ccSceneBattle — battle scene lifecycle manager
 * Evidence: ccSceneBattle::Initialize (RVA 0x621380), Finalize (0x6D8554),
 *           CreateBattleObject (0x6D7964), DeleteBattleObject (0x6D8144)
 * Vtable: at offset 0x00 (vtable+0x10 called in Create/Delete/Finalize)
 * Size: unknown, >= 0x490 (last write at 0x480 region, read at 0x480)
 *
 * Initialize writes many fields:
 *   0x150, 0x158: u64 = 0
 *   0x198: u64 rw (= 0)
 *   0x1A0, 0x1A8: u64 = 0
 *   0x1B0: u64 rw (passed to FUN_140a01cc0)
 *   0x1C8, 0x1CC, 0x1D0: u32 = 0xFFFFFFFF (sentinel values)
 *   0x1D4: u64 = 0 (also written as u32 in some paths)
 *   0x1D8, 0x1DC, 0x1E4, 0x1EC: u64 = 0
 *   0x1D8: u32 from global DAT_1416663c8+0x1e0
 * Finalize reads:
 *   0x128: sub-object (thunk_FUN_14076e86c)
 *   0x2C0: vtable+0x58 dispatch
 *   0x464: u32 read (flag check)
 *   0x478: u64 rw (ptr null-check before free)
 *   0x480: u64 read (int cast, non-zero check)
 */
typedef struct __attribute__((packed)) ccSceneBattle_s4 {
    /* 0x000 */ void *vtable;                                 /* vtable+0x10, vtable+0x58 called */
    /* 0x008 */ uint8_t pad_008[0x120];                       /* gap to 0x128 */
    /* 0x128 */ uint8_t subobj_128[0x28];                     /* Finalize: thunk_FUN_14076e86c */
    /* 0x150 */ int64_t init_field_150;                       /* Initialize: = 0 */
    /* 0x158 */ int64_t init_field_158;                       /* Initialize: = 0 */
    /* 0x160 */ uint8_t subobj_160[0x38];                     /* Initialize: FUN_1401ca8f8(p+0x2c) */
    /* 0x198 */ int64_t init_field_198;                       /* Initialize: rw = 0 */
    /* 0x1A0 */ int64_t init_field_1A0;                       /* Initialize: = 0 */
    /* 0x1A8 */ int64_t init_field_1A8;                       /* Initialize: = 0 */
    /* 0x1B0 */ int64_t init_field_1B0;                       /* Initialize: rw, passed to FUN_140a01cc0 */
    /* 0x1B8 */ uint8_t pad_1B8[0x10];                        /* gap to 0x1C8 */
    /* 0x1C8 */ int32_t sentinel_1C8;                         /* Initialize: = 0xFFFFFFFF */
    /* 0x1CC */ int32_t sentinel_1CC;                         /* Initialize: = 0xFFFFFFFF */
    /* 0x1D0 */ int32_t sentinel_1D0;                         /* Initialize: = 0xFFFFFFFF */
    /* 0x1D4 */ int64_t init_field_1D4;                       /* Initialize: = 0 (u64 or u32) */
    /* 0x1DC */ int64_t init_field_1DC;                       /* Initialize: = 0 */
    /* 0x1E4 */ int64_t init_field_1E4;                       /* Initialize: = 0 */
    /* 0x1EC */ int64_t init_field_1EC;                       /* Initialize: = 0 */
    /* 0x1F4 */ uint8_t pad_1F4[0xCC];                        /* gap to 0x2C0 */
    /* 0x2C0 */ uint8_t dispatch_2C0[0x1A4];                  /* vtable+0x58 dispatch region */
    /* 0x464 */ int32_t finalize_flag;                        /* Finalize: u32 read, flag check */
    /* 0x468 */ uint8_t pad_468[0x10];                        /* gap to 0x478 */
    /* 0x478 */ int64_t battle_object_ptr;                    /* Finalize: rw, null-check before free */
    /* 0x480 */ int64_t finalize_check;                       /* Finalize: u64 read, int cast != 0 */
} ccSceneBattle_s4;

static_assert(offsetof(ccSceneBattle_s4, vtable) == 0x000, "ccSceneBattle_s4.vtable");
static_assert(offsetof(ccSceneBattle_s4, subobj_128) == 0x128, "ccSceneBattle_s4.subobj_128");
static_assert(offsetof(ccSceneBattle_s4, init_field_150) == 0x150, "ccSceneBattle_s4.init_field_150");
static_assert(offsetof(ccSceneBattle_s4, init_field_158) == 0x158, "ccSceneBattle_s4.init_field_158");
static_assert(offsetof(ccSceneBattle_s4, subobj_160) == 0x160, "ccSceneBattle_s4.subobj_160");
static_assert(offsetof(ccSceneBattle_s4, init_field_198) == 0x198, "ccSceneBattle_s4.init_field_198");
static_assert(offsetof(ccSceneBattle_s4, init_field_1A0) == 0x1A0, "ccSceneBattle_s4.init_field_1A0");
static_assert(offsetof(ccSceneBattle_s4, init_field_1A8) == 0x1A8, "ccSceneBattle_s4.init_field_1A8");
static_assert(offsetof(ccSceneBattle_s4, init_field_1B0) == 0x1B0, "ccSceneBattle_s4.init_field_1B0");
static_assert(offsetof(ccSceneBattle_s4, sentinel_1C8) == 0x1C8, "ccSceneBattle_s4.sentinel_1C8");
static_assert(offsetof(ccSceneBattle_s4, sentinel_1CC) == 0x1CC, "ccSceneBattle_s4.sentinel_1CC");
static_assert(offsetof(ccSceneBattle_s4, sentinel_1D0) == 0x1D0, "ccSceneBattle_s4.sentinel_1D0");
static_assert(offsetof(ccSceneBattle_s4, init_field_1D4) == 0x1D4, "ccSceneBattle_s4.init_field_1D4");
static_assert(offsetof(ccSceneBattle_s4, init_field_1DC) == 0x1DC, "ccSceneBattle_s4.init_field_1DC");
static_assert(offsetof(ccSceneBattle_s4, init_field_1E4) == 0x1E4, "ccSceneBattle_s4.init_field_1E4");
static_assert(offsetof(ccSceneBattle_s4, init_field_1EC) == 0x1EC, "ccSceneBattle_s4.init_field_1EC");
static_assert(offsetof(ccSceneBattle_s4, dispatch_2C0) == 0x2C0, "ccSceneBattle_s4.dispatch_2C0");
static_assert(offsetof(ccSceneBattle_s4, finalize_flag) == 0x464, "ccSceneBattle_s4.finalize_flag");
static_assert(offsetof(ccSceneBattle_s4, battle_object_ptr) == 0x478, "ccSceneBattle_s4.battle_object_ptr");
static_assert(offsetof(ccSceneBattle_s4, finalize_check) == 0x480, "ccSceneBattle_s4.finalize_check");

/* Stub classes — absent or no typed fields recovered in s4 */

/* ccDuelRule — present in s4 symbol DB but no state_surface fields recovered */
typedef struct __attribute__((packed)) ccDuelRule_s4 {
    uint8_t opaque[1]; /* no typed fields recovered */
} ccDuelRule_s4;

/* ccDuelPlayerLoader — async player asset loader
 * Present in s4 symbol DB; no state_surface run yet (needs seed methods)
 * Size: unknown; placeholder only
 */
typedef struct __attribute__((packed)) ccDuelPlayerLoader_s4 {
    uint8_t opaque[1]; /* no typed fields recovered */
} ccDuelPlayerLoader_s4;

/* ccDuelSettingManager — factory for duel settings
 * Present in s4 symbol DB; no state_surface fields recovered
 * Size: unknown; placeholder only
 */
typedef struct __attribute__((packed)) ccDuelSettingManager_s4 {
    uint8_t opaque[1]; /* no typed fields recovered */
} ccDuelSettingManager_s4;

/* ccGameDuel — absent from s4 (no symbols found) */
/* ccGameDuelJudge — absent from s4 (no symbols found) */
/* ccGameDuelSetting — absent from s4 (no symbols found) */