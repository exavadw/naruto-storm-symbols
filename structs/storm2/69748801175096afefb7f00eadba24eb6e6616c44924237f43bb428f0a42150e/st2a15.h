/*
 * st2a15.h — Story progression structs for NARUTO STORM 2 (s2, NSUNS2.exe)
 * Group: ccSceneMissionWindow, ccSceneMissionWindowNoSelect, ccUiAdvActionDisplay,
 *        ccUiAdvActionDisplayHeadLock, ccUiAdvActionDisplayPosAdjust,
 *        ccUiAdvBattleAchievement, ccUiAdvBirdIcon, ccUiAdvBirdInfo,
 *        ccUiAdvBirdSelect, ccUiAdvCharaStatus, ccUiAdvCompanionCheckFrame,
 *        ccUiAdvFriendShipCheck, ccUiAdvFriendShipUp, ccUiAdvFriendShipUpView
 *
 * All layouts INFERRED from static decompilation of s2 build abf2b6.
 * NOT CONFIRMED by runtime trace. Offsets are PC x64 (image base 0x140000000).
 */

#ifndef ST2A15_H
#define ST2A15_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose size is unproven */
typedef struct ccUiKeyHelpNS2 ccUiKeyHelpNS2;
typedef struct ccUiFontNS2 ccUiFontNS2;
typedef struct ccUiAdvCharaStatus ccUiAdvCharaStatus;
typedef struct ccUiDuelAchievementList ccUiDuelAchievementList;

/* ================================================================
 * ccUiAdvActionDisplayPosAdjust
 * Small helper struct for UI position clamping.
 * Fields extracted from ccUiAdvActionDisplayPosAdjust::Calc (0x491EF8)
 * Size: >= 0x24 (last field at +0x20 is float, 4 bytes)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    uint8_t  _pad_0x00[8];           /* +0x00 vtable or base */
    int32_t  enabled;                /* +0x08 int flag checked in Calc */
    float    pos_x;                  /* +0x0C Vector2.x (base position) */
    float    pos_y;                  /* +0x10 Vector2.y */
    float    adjusted_x;            /* +0x14 output adjusted pos (written back) */
    float    adjusted_y;            /* +0x18 */
    float    half_width;             /* +0x1C half-size for clamp range */
    float    half_height;           /* +0x20 */
} ccUiAdvActionDisplayPosAdjust_s2;

static_assert(offsetof(ccUiAdvActionDisplayPosAdjust_s2, enabled) == 0x08, "ccUiAdvActionDisplayPosAdjust.enabled");
static_assert(offsetof(ccUiAdvActionDisplayPosAdjust_s2, pos_x) == 0x0C, "ccUiAdvActionDisplayPosAdjust.pos_x");
static_assert(offsetof(ccUiAdvActionDisplayPosAdjust_s2, pos_y) == 0x10, "ccUiAdvActionDisplayPosAdjust.pos_y");
static_assert(offsetof(ccUiAdvActionDisplayPosAdjust_s2, adjusted_x) == 0x14, "ccUiAdvActionDisplayPosAdjust.adjusted_x");
static_assert(offsetof(ccUiAdvActionDisplayPosAdjust_s2, half_width) == 0x1C, "ccUiAdvActionDisplayPosAdjust.half_width");
static_assert(offsetof(ccUiAdvActionDisplayPosAdjust_s2, half_height) == 0x20, "ccUiAdvActionDisplayPosAdjust.half_height");

/* ================================================================
 * ccUiAdvActionDisplayHeadLock
 * Locks a UI element to a character's head bone position.
 * Fields from IsEqualsMobId (0x492690), SetHeadHeight (0x4927CC)
 * Size: >= 0xC (last proven field at +0x08)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    int64_t  mob_id;                 /* +0x00 compared in IsEqualsMobId */
    float    head_height_delta;      /* +0x08 computed height difference */
} ccUiAdvActionDisplayHeadLock_s2;

static_assert(offsetof(ccUiAdvActionDisplayHeadLock_s2, mob_id) == 0x00, "ccUiAdvActionDisplayHeadLock.mob_id");
static_assert(offsetof(ccUiAdvActionDisplayHeadLock_s2, head_height_delta) == 0x08, "ccUiAdvActionDisplayHeadLock.head_height_delta");

/* ================================================================
 * ccUiAdvFriendShipUp
 * Single friendship-up animation entry (one per character slot).
 * Fields from Entry (0x498528), Ctrl (0x497F58), StateIn (0x4987B0)
 * Size: >= 0x30 (last proven field at +0x28)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    uint8_t  _pad_0x00[8];           /* +0x00 vtable */
    int32_t  state;                  /* +0x08 Ctrl state machine (0/1/2/3) */
    int32_t  timer;                  /* +0x0C frame counter in StateIn */
    int32_t  chara_id;               /* +0x10 set from Entry param_4 */
    uint8_t  _pad_0x14[4];           /* +0x14 padding */
    int64_t  anm_frd_up;             /* +0x18 ccUiFontNS2* adv_frd_up anim */
    int64_t  anm_up_eff;             /* +0x20 ccUiFontNS2* adv_up_eff anim */
    int64_t  chara_status;           /* +0x28 ccUiAdvCharaStatus* */
} ccUiAdvFriendShipUp_s2;

static_assert(offsetof(ccUiAdvFriendShipUp_s2, state) == 0x08, "ccUiAdvFriendShipUp.state");
static_assert(offsetof(ccUiAdvFriendShipUp_s2, timer) == 0x0C, "ccUiAdvFriendShipUp.timer");
static_assert(offsetof(ccUiAdvFriendShipUp_s2, chara_id) == 0x10, "ccUiAdvFriendShipUp.chara_id");
static_assert(offsetof(ccUiAdvFriendShipUp_s2, anm_frd_up) == 0x18, "ccUiAdvFriendShipUp.anm_frd_up");
static_assert(offsetof(ccUiAdvFriendShipUp_s2, anm_up_eff) == 0x20, "ccUiAdvFriendShipUp.anm_up_eff");
static_assert(offsetof(ccUiAdvFriendShipUp_s2, chara_status) == 0x28, "ccUiAdvFriendShipUp.chara_status");

/* ================================================================
 * ccUiAdvFriendShipUpView
 * Container managing deque of ccUiAdvFriendShipUp entries.
 * Fields from Initialize (0x498690), Ctrl (0x4980F8), Draw (0x498498)
 * Contains std::deque-like structure at +0xC8 and array of per-char data at +0x38.
 * Size: >= 0x100 (deque internals extend past +0xE8)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    uint8_t  _pad_0x00[8];           /* +0x00 vtable */
    uint8_t  _base_0x08[0x30];       /* +0x08 base class fields (unknown) */
    /* Per-character friendship data array: 8 ints per char, starting at +0x38 */
    int32_t  char_friendship[8][2];  /* +0x38 [char_idx][0]=level, [1]=event_flag */
    uint8_t  _pad_0x78[0x50];        /* +0x78 gap to deque */
    /* std::deque<ccUiAdvFriendShipUp*> internals */
    int64_t  deque_map_ptr;          /* +0xC8 map pointer (checked != 0) */
    uint8_t  _deque_0xD0[0x10];      /* +0xD0 deque bookkeeping */
    uint64_t deque_size;             /* +0xE0 element count (bit-packed index) */
    int64_t  deque_end_sentinel;     /* +0xE8 end check */
    uint8_t  _pad_0xF0[0x10];        /* +0xF0 tail padding */
} ccUiAdvFriendShipUpView_s2;

static_assert(offsetof(ccUiAdvFriendShipUpView_s2, char_friendship) == 0x38, "ccUiAdvFriendShipUpView.char_friendship");
static_assert(offsetof(ccUiAdvFriendShipUpView_s2, deque_map_ptr) == 0xC8, "ccUiAdvFriendShipUpView.deque_map_ptr");
static_assert(offsetof(ccUiAdvFriendShipUpView_s2, deque_size) == 0xE0, "ccUiAdvFriendShipUpView.deque_size");
static_assert(offsetof(ccUiAdvFriendShipUpView_s2, deque_end_sentinel) == 0xE8, "ccUiAdvFriendShipUpView.deque_end_sentinel");

/* ================================================================
 * ccUiAdvBattleAchievement
 * Wraps ccUiDuelAchievementList + ccUiKeyHelpNS2 sub-objects.
 * Fields from Initialize (0x492E04), Execute (0x492D28)
 * Size: >= 0x18 (last proven field at +0x10)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    uint8_t  _pad_0x00[8];           /* +0x00 vtable */
    int64_t  achievement_list;       /* +0x08 ccUiDuelAchievementList* */
    int64_t  key_help;               /* +0x10 ccUiKeyHelpNS2* */
} ccUiAdvBattleAchievement_s2;

static_assert(offsetof(ccUiAdvBattleAchievement_s2, achievement_list) == 0x08, "ccUiAdvBattleAchievement.achievement_list");
static_assert(offsetof(ccUiAdvBattleAchievement_s2, key_help) == 0x10, "ccUiAdvBattleAchievement.key_help");

/* ================================================================
 * ccSceneMissionWindow
 * Mission selection window with opacity fade and reward dialog.
 * Fields from Initialize (0x45EB68), Execute (0x45EA24)
 * Inherits from ccUiMissionWindow (fields at +0x130 used via SetOpacity).
 * Size: >= 0x144 (last proven field at +0x140)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    uint8_t  _base_0x00[0x128];      /* +0x00 base class (ccUiMissionWindow?) */
    int64_t  key_help;               /* +0x128 ccUiKeyHelpNS2* */
    int64_t  mission_window;         /* +0x130 passed to SetOpacity */
    int32_t  reward_init_state;      /* +0x138 flag: reward dialog initialized */
    float    opacity_current;        /* +0x13C lerped opacity value */
    float    opacity_target;         /* +0x140 target opacity for lerp */
} ccSceneMissionWindow_s2;

static_assert(offsetof(ccSceneMissionWindow_s2, key_help) == 0x128, "ccSceneMissionWindow.key_help");
static_assert(offsetof(ccSceneMissionWindow_s2, mission_window) == 0x130, "ccSceneMissionWindow.mission_window");
static_assert(offsetof(ccSceneMissionWindow_s2, reward_init_state) == 0x138, "ccSceneMissionWindow.reward_init_state");
static_assert(offsetof(ccSceneMissionWindow_s2, opacity_current) == 0x13C, "ccSceneMissionWindow.opacity_current");
static_assert(offsetof(ccSceneMissionWindow_s2, opacity_target) == 0x140, "ccSceneMissionWindow.opacity_target");

/* ================================================================
 * ccSceneMissionWindowNoSelect
 * Variant without selection; only fades out.
 * Fields from Execute (0x45ED48). Shares layout with ccSceneMissionWindow
 * at offsets +0x130, +0x138, +0x13C but no reward dialog or key_help.
 * Size: >= 0x140
 * ================================================================ */
typedef struct __attribute__((packed)) {
    uint8_t  _base_0x00[0x130];      /* +0x00 base class */
    int64_t  mission_window;         /* +0x130 passed to SetOpacity */
    float    opacity_current;        /* +0x138 lerped opacity */
    float    opacity_target;         /* +0x13C target (set to 0 on trigger) */
} ccSceneMissionWindowNoSelect_s2;

static_assert(offsetof(ccSceneMissionWindowNoSelect_s2, mission_window) == 0x130, "ccSceneMissionWindowNoSelect.mission_window");
static_assert(offsetof(ccSceneMissionWindowNoSelect_s2, opacity_current) == 0x138, "ccSceneMissionWindowNoSelect.opacity_current");
static_assert(offsetof(ccSceneMissionWindowNoSelect_s2, opacity_target) == 0x13C, "ccSceneMissionWindowNoSelect.opacity_target");

#endif /* ST2A15_H */