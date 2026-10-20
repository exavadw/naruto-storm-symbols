/* rbDuel s3 — NARUTO STORM 3 Full Burst HD (NSUNS3.exe, 64-bit)
 * Build: s3 / NSUNS3.exe-a7124b
 * Date: 2026-10-19
 * Status: INFERRED (static analysis only; no runtime trace)
 *
 * All fields derived from Ghidra decompilation of s3 binary.
 * Names from s3 symbols/strings only (own-game rule).
 * Sizes are lower bounds unless proven by operator new / allocator call.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccDuelJudge — duel scoring / achievement tracker
 * Evidence: ccDuelJudge::Clear (RVA 0x4E1C94)
 * Size: unknown, >= 0x88 (last write at byte offset 0x80, size 8)
 * Vtable: none (not polymorphic; initialized via Clear)
 */
typedef struct __attribute__((packed)) ccDuelJudge {
    /* 0x00 */ uint8_t pad_00[0x08];                          /* no access seen */
    /* 0x08 */ int32_t slot_id_0;                             /* Clear: puVar1[2]=0xffffffff, loop iter 0 */
    /* 0x0C */ int32_t slot_val_0;                            /* Clear: puVar1[3]=0, loop iter 0 */
    /* 0x10 */ int32_t slot_id_1;                             /* Clear: puVar1[2]=0xffffffff, loop iter 1 */
    /* 0x14 */ int32_t slot_val_1;                            /* Clear: puVar1[3]=0, loop iter 1 */
    /* 0x18 */ int32_t slot_id_2;                             /* Clear: puVar1[2]=0xffffffff, loop iter 2 */
    /* 0x1C */ int32_t slot_val_2;                            /* Clear: puVar1[3]=0, loop iter 2 */
    /* 0x20 */ int32_t counter;                               /* Clear: param_1[8]=0 */
    /* 0x24 */ int32_t achievement_id_0;                      /* Clear: *puVar2=0, loop2 iter 0 */
    /* 0x28 */ int32_t achievement_val_0;                     /* Clear: puVar2[1]=0, loop2 iter 0 */
    /* 0x2C */ int32_t achievement_id_1;                      /* Clear: *puVar2=0xffffffff, loop2 iter 1 */
    /* 0x30 */ int32_t achievement_val_1;                     /* Clear: puVar2[1]=0, loop2 iter 1 */
    /* 0x34 */ int32_t achievement_id_2;                      /* Clear: *puVar2=0xffffffff, loop2 iter 2 */
    /* 0x38 */ int32_t achievement_val_2;                     /* Clear: puVar2[1]=0, loop2 iter 2 */
    /* 0x3C */ uint8_t pad_3C[0x0C];                         /* gap to 0x48 */
    /* 0x48 */ int64_t field_48;                              /* Clear: *(u8*)(p+0x12)=0 */
    /* 0x50 */ int64_t field_50;                              /* Clear: *(u8*)(p+0x14)=2 */
    /* 0x58 */ int64_t field_58;                              /* Clear: *(u8*)(p+0x16)=0 */
    /* 0x60 */ int64_t field_60;                              /* Clear: *(u8*)(p+0x18)=0 */
    /* 0x68 */ int64_t field_68;                              /* Clear: *(u8*)(p+0x1a)=0 */
    /* 0x70 */ int64_t field_70;                              /* Clear: *(u8*)(p+0x1c)=0 */
    /* 0x78 */ int64_t field_78;                              /* Clear: *(u8*)(p+0x1e)=0x100000001 */
    /* 0x80 */ int64_t field_80;                              /* Clear: *(u8*)(p+0x20)=1 */
} ccDuelJudge;

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
static_assert(offsetof(ccDuelJudge, field_48) == 0x48, "ccDuelJudge.field_48");
static_assert(offsetof(ccDuelJudge, field_50) == 0x50, "ccDuelJudge.field_50");
static_assert(offsetof(ccDuelJudge, field_58) == 0x58, "ccDuelJudge.field_58");
static_assert(offsetof(ccDuelJudge, field_60) == 0x60, "ccDuelJudge.field_60");
static_assert(offsetof(ccDuelJudge, field_68) == 0x68, "ccDuelJudge.field_68");
static_assert(offsetof(ccDuelJudge, field_70) == 0x70, "ccDuelJudge.field_70");
static_assert(offsetof(ccDuelJudge, field_78) == 0x78, "ccDuelJudge.field_78");
static_assert(offsetof(ccDuelJudge, field_80) == 0x80, "ccDuelJudge.field_80");

/* ccDuelManager — manages duel players, teams, conditions
 * Evidence: ccDuelManager::ccDuelManager (RVA 0x4E1C10)
 * Embeds ccDuelJudge at offset 0x00 (ctor calls ccDuelJudge::Clear on self)
 * Vtable: PTR_FUN_1409daf00
 * Size: unknown, >= 0x88 (same as embedded ccDuelJudge minimum)
 */
typedef struct __attribute__((packed)) ccDuelManager {
    /* 0x00 */ void *vtable;                                  /* ctor: *param_1 = &PTR_FUN_1409daf00 */
    /* 0x08 */ int32_t player_slot_0;                         /* ctor: *(u4*)(p+1)=0xffffffff, loop iter 0 */
    /* 0x0C */ int32_t field_0C;                              /* ctor: *(u4*)(p+0xc)=0, loop iter 0 */
    /* 0x10 */ int32_t player_slot_1;                         /* ctor: *(u4*)(p+1)=0xffffffff, loop iter 1 */
    /* 0x14 */ int32_t field_14;                              /* ctor: *(u4*)(p+0xc)=0, loop iter 1 */
    /* 0x18 */ int32_t team_slot_0;                           /* ctor: *(u4*)(p+1)=0xffffffff, loop2 iter 0 */
    /* 0x1C */ int32_t field_1C;                              /* ctor: *(u4*)(p+0xc)=0, loop2 iter 0 */
    /* 0x20 */ int32_t team_slot_1;                           /* ctor: *(u4*)(p+1)=0xffffffff, loop2 iter 1 */
    /* 0x24 */ int32_t field_24;                              /* ctor: *(u4*)(p+0xc)=0, loop2 iter 1 */
    /* 0x28 */ uint8_t pad_28[0x20];                          /* gap to 0x48 (rest filled by ccDuelJudge::Clear) */
    /* 0x48 -- ccDuelJudge fields continue through 0x87 */
    /* Note: ccDuelJudge::Clear writes starting at this base, overlapping above */
} ccDuelManager;

static_assert(offsetof(ccDuelManager, vtable) == 0x00, "ccDuelManager.vtable");
static_assert(offsetof(ccDuelManager, player_slot_0) == 0x08, "ccDuelManager.player_slot_0");
static_assert(offsetof(ccDuelManager, field_0C) == 0x0C, "ccDuelManager.field_0C");
static_assert(offsetof(ccDuelManager, player_slot_1) == 0x10, "ccDuelManager.player_slot_1");
static_assert(offsetof(ccDuelManager, field_14) == 0x14, "ccDuelManager.field_14");
static_assert(offsetof(ccDuelManager, team_slot_0) == 0x18, "ccDuelManager.team_slot_0");
static_assert(offsetof(ccDuelManager, field_1C) == 0x1C, "ccDuelManager.field_1C");
static_assert(offsetof(ccDuelManager, team_slot_1) == 0x20, "ccDuelManager.team_slot_1");
static_assert(offsetof(ccDuelManager, field_24) == 0x24, "ccDuelManager.field_24");

/* ccDuelSituation — composite duel state container
 * Evidence: ccDuelSituation::ccDuelSituation (RVA 0x4E257C)
 * Vtable: PTR_FUN_140989050
 * Size: unknown, >= 0xF3A38 (last sub-object ends near param_1 + 0x1e734 * 8)
 *
 * Sub-object layout from ctor (param_1 is undefined8*):
 *   0x0010: teamA (2 × FUN_1404e0960, stride 9 u64 = 0x48 each, total 0x90)
 *   0x00A0: subobj (FUN_1404deb30, at p+0x14 → byte 0xA0)
 *   0x00C0: array of 12 sub-objects (FUN_1404e0770, stride 1 u64, 0x0C items = 0x60)
 *   0x0128: subobj (FUN_1404e1c10 = ccDuelManager ctor, at p+0x25 → byte 0x128)
 *   0x01B0: player array (32 × FUN_1404e35e0, stride 0xf17 u64 = 0x78B8 each)
 *           32 * 0x78B8 = 0xF1700, ending at 0x1B0 + 0xF1700 = 0xF18B0
 *   0xF18B0: subobj (FUN_140549d28, at p+0x1e316 → byte 0xF18B0)
 *   0xF1C40: subobj (FUN_14054a188, at p+0x1e3ca → byte 0xF1E50)
 *   0xF1E84: wchar buffers (6 × [0x34 bytes + 0x1a×u16 zeros], stride 7 u64)
 *   0xF2F38: subobj (FUN_1404e0960, 2 iters at p+0x1e6e7)
 *   0xF2FC8: subobj (FUN_1404e1c10 = ccDuelManager, at p+0x1e6f9)
 *   0xF3014: wchar buffers (6 × same pattern, at p+0x1e70a)
 *   0xF3A30: subobj (FUN_1404e26e4, at p+0x1e734)
 */
typedef struct __attribute__((packed)) ccDuelSituation {
    /* 0x00000 */ void *vtable;                                /* ctor: *param_1 = &PTR_FUN_140989050 */
    /* 0x00008 */ uint8_t pad_08[0x08];                        /* gap */
    /* 0x00010 */ uint8_t subobj_teamA[0x90];                  /* 2 × FUN_1404e0960, stride 0x48 */
    /* 0x000A0 */ uint8_t subobj_A0[0x20];                     /* FUN_1404deb30 at p+0x14 */
    /* 0x000C0 */ uint8_t subobj_array_C0[0x60];               /* 12 × FUN_1404e0770 */
    /* 0x00120 */ uint8_t pad_120[0x08];                       /* gap to 0x128 */
    /* 0x00128 */ uint8_t subobj_manager[0x88];                /* FUN_1404e1c10 (ccDuelManager-like) */
    /* 0x001B0 */ uint8_t subobj_players[0xF1700];             /* 32 × FUN_1404e35e0, stride 0x78B8 */
    /* 0xF18B0 */ uint8_t subobj_F18B0[0x3A0];                 /* FUN_140549d28 */
    /* 0xF1C50 */ uint8_t pad_F1C50[0x200];                    /* gap to F1E50 */
    /* 0xF1E50 */ uint8_t subobj_F1E50[0x34];                  /* FUN_14054a188 */
    /* 0xF1E84 */ uint8_t wchar_bufs_1[0x10B4];                /* 6 × wchar buffer blocks */
    /* 0xF2F38 */ uint8_t subobj_F2F38[0x90];                  /* 2 × FUN_1404e0960 */
    /* 0xF2FC8 */ uint8_t subobj_manager2[0x4C];               /* FUN_1404e1c10 */
    /* 0xF3014 */ uint8_t wchar_bufs_2[0xA1C];                 /* 6 × wchar buffer blocks */
    /* 0xF3A30 */ uint8_t subobj_F3A30[0x08];                  /* FUN_1404e26e4 */
} ccDuelSituation;

static_assert(offsetof(ccDuelSituation, vtable) == 0x00000, "ccDuelSituation.vtable");
static_assert(offsetof(ccDuelSituation, subobj_teamA) == 0x00010, "ccDuelSituation.subobj_teamA");
static_assert(offsetof(ccDuelSituation, subobj_A0) == 0x000A0, "ccDuelSituation.subobj_A0");
static_assert(offsetof(ccDuelSituation, subobj_array_C0) == 0x000C0, "ccDuelSituation.subobj_array_C0");
static_assert(offsetof(ccDuelSituation, subobj_manager) == 0x00128, "ccDuelSituation.subobj_manager");
static_assert(offsetof(ccDuelSituation, subobj_players) == 0x001B0, "ccDuelSituation.subobj_players");
static_assert(offsetof(ccDuelSituation, subobj_F18B0) == 0xF18B0, "ccDuelSituation.subobj_F18B0");
static_assert(offsetof(ccDuelSituation, subobj_F1E50) == 0xF1E50, "ccDuelSituation.subobj_F1E50");
static_assert(offsetof(ccDuelSituation, wchar_bufs_1) == 0xF1E84, "ccDuelSituation.wchar_bufs_1");
static_assert(offsetof(ccDuelSituation, subobj_F2F38) == 0xF2F38, "ccDuelSituation.subobj_F2F38");
static_assert(offsetof(ccDuelSituation, subobj_manager2) == 0xF2FC8, "ccDuelSituation.subobj_manager2");
static_assert(offsetof(ccDuelSituation, wchar_bufs_2) == 0xF3014, "ccDuelSituation.wchar_bufs_2");
static_assert(offsetof(ccDuelSituation, subobj_F3A30) == 0xF3A30, "ccDuelSituation.subobj_F3A30");

/* Stub classes — no typed field accesses recovered */

/* ccDuelTeam — team state (life, chakra, support gauge, items, players)
 * 43 methods decompiled; all use byte-cast pattern, no typed field access
 * GetCrashPoint/SetCrashPoint access vtable+0x40 indirect call
 * Size: unknown; placeholder only
 */
typedef struct __attribute__((packed)) ccDuelTeam {
    uint8_t opaque[1]; /* no typed fields recovered */
} ccDuelTeam;

/* ccDuelPlayerLoader — async player asset loader
 * Evidence: ctor (RVA 0x69B620) sets vtable PTR_FUN_1409de7a8, embeds BlockAllocator + ccPlayerDocSlot
 * dtor (RVA 0x4E3630) accesses sub-object at p+0xe (byte offset 0x70)
 * Size: unknown, >= 0x78
 */
typedef struct __attribute__((packed)) ccDuelPlayerLoader {
    /* 0x00 */ void *vtable;                                  /* ctor: *param_1 = &PTR_FUN_1409de7a8 */
    /* 0x08 */ uint8_t block_allocator[0x68];                 /* Nucc::Memory::BlockAllocator (inferred) */
    /* 0x70 */ uint8_t player_doc_slot[0x08];                 /* ccPlayerDocSlot at p+0xe (dtor) */
} ccDuelPlayerLoader;

static_assert(offsetof(ccDuelPlayerLoader, vtable) == 0x00, "ccDuelPlayerLoader.vtable");
static_assert(offsetof(ccDuelPlayerLoader, block_allocator) == 0x08, "ccDuelPlayerLoader.block_allocator");
static_assert(offsetof(ccDuelPlayerLoader, player_doc_slot) == 0x70, "ccDuelPlayerLoader.player_doc_slot");

/* ccDuelSettingInfo — duel parameter configuration
 * Evidence: Clear (RVA 0x4DEBEC) writes int32=0 at offset 0x78
 * Size: unknown, >= 0x7C
 */
typedef struct __attribute__((packed)) ccDuelSettingInfo {
    /* 0x00 */ uint8_t pad_00[0x78];                          /* no access seen */
    /* 0x78 */ int32_t clear_field;                           /* Clear: *(u4*)(p+0xf)=0 */
} ccDuelSettingInfo;

static_assert(offsetof(ccDuelSettingInfo, clear_field) == 0x78, "ccDuelSettingInfo.clear_field");

/* ccDuelSettingManager — factory for duel settings
 * 3 methods decompiled; no typed field access recovered
 * Size: unknown; placeholder only
 */
typedef struct __attribute__((packed)) ccDuelSettingManager {
    uint8_t opaque[1]; /* no typed fields recovered */
} ccDuelSettingManager;

/* ccSceneBattle — battle scene lifecycle manager
 * 12 methods decompiled; no typed field access recovered
 * CreateBattleObject allocates ccGameObjectWorld (0xa0), not self
 * Size: unknown; placeholder only
 */
typedef struct __attribute__((packed)) ccSceneBattle {
    uint8_t opaque[1]; /* no typed fields recovered */
} ccSceneBattle;

/* ccDuelRule — absent from s3 (no symbols or code found) */
/* ccGameDuel — absent from s3 (no symbols or code found) */
/* ccGameDuelJudge — absent from s3 (no symbols or code found) */
/* ccGameDuelSetting — absent from s3 (no symbols or code found) */