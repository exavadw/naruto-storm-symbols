/* st3a15.h - ccSceneAdv* struct layouts for NSUNS3.exe (s3 build)
 * Generated from symbolized decompilations. All offsets INFERRED.
 * Sizes are NOT proven from allocator; structs end at last known field.
 */
#ifndef ST3A15_H
#define ST3A15_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccSceneAdvMissionOutline - 2 methods: Execute, Initialize */
/* size unknown, >= 0x130 */
typedef struct __attribute__((packed)) ccSceneAdvMissionOutline {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int64_t field_0x128; /* 0x128 [r] INFERRED from ccSceneAdvMissionOutline::Execute */
} ccSceneAdvMissionOutline;

static_assert(offsetof(ccSceneAdvMissionOutline, field_0x128) == 0x128, "ccSceneAdvMissionOutline::field_0x128 offset mismatch");

/* ccSceneAdvMissionResult - 3 methods: Capture, Execute, Finalize */
/* size unknown, >= 0x148 */
typedef struct __attribute__((packed)) ccSceneAdvMissionResult {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int64_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvMissionResult::Execute */
  uint64_t field_0x130; /* 0x130 [rw] INFERRED from ccSceneAdvMissionResult::Capture */
  uint32_t field_0x138; /* 0x138 [rw] INFERRED from ccSceneAdvMissionResult::Capture */
  uint32_t advMissionResult; /* 0x13C [rw] HIGH from ccSceneAdvMissionResult::Capture */
  int64_t field_0x140; /* 0x140 [rw] INFERRED from ccSceneAdvMissionResult::Execute */
} ccSceneAdvMissionResult;

static_assert(offsetof(ccSceneAdvMissionResult, field_0x128) == 0x128, "ccSceneAdvMissionResult::field_0x128 offset mismatch");
static_assert(offsetof(ccSceneAdvMissionResult, field_0x130) == 0x130, "ccSceneAdvMissionResult::field_0x130 offset mismatch");
static_assert(offsetof(ccSceneAdvMissionResult, field_0x138) == 0x138, "ccSceneAdvMissionResult::field_0x138 offset mismatch");
static_assert(offsetof(ccSceneAdvMissionResult, advMissionResult) == 0x13C, "ccSceneAdvMissionResult::advMissionResult offset mismatch");
static_assert(offsetof(ccSceneAdvMissionResult, field_0x140) == 0x140, "ccSceneAdvMissionResult::field_0x140 offset mismatch");

/* ccSceneAdvPreBattleLoad: no instance state recovered from 2 methods (Execute, Initialize) */

/* ccSceneAdvPrevBattleInterval - 2 methods: Activated, Initialize */
/* size unknown, >= 0x1DC */
typedef struct __attribute__((packed)) ccSceneAdvPrevBattleInterval {
  uint8_t _base_pad[0x178]; /* 0x0..0x177: ccScene base */
  int32_t field_0x178; /* 0x178 [w] INFERRED from ccSceneAdvPrevBattleInterval::Activated */
  uint32_t field_0x17C; /* 0x17C [rw] INFERRED from ccSceneAdvPrevBattleInterval::Activated */
  uint8_t _pad_0x180[0x8];
  uint32_t field_0x188; /* 0x188 [rw] INFERRED from ccSceneAdvPrevBattleInterval::Activated */
  uint8_t _pad_0x18C[0xC];
  int64_t field_0x198; /* 0x198 [r] INFERRED from ccSceneAdvPrevBattleInterval::Activated */
  uint8_t _pad_0x1A0[0x30];
  uint32_t field_0x1D0; /* 0x1D0 [w] INFERRED from ccSceneAdvPrevBattleInterval::Activated */
  uint8_t _pad_0x1D4[0x4];
  uint32_t advBtlSelParam; /* 0x1D8 [rw] HIGH from ccSceneAdvPrevBattleInterval::Initialize */
} ccSceneAdvPrevBattleInterval;

static_assert(offsetof(ccSceneAdvPrevBattleInterval, field_0x178) == 0x178, "ccSceneAdvPrevBattleInterval::field_0x178 offset mismatch");
static_assert(offsetof(ccSceneAdvPrevBattleInterval, field_0x17C) == 0x17C, "ccSceneAdvPrevBattleInterval::field_0x17C offset mismatch");
static_assert(offsetof(ccSceneAdvPrevBattleInterval, field_0x188) == 0x188, "ccSceneAdvPrevBattleInterval::field_0x188 offset mismatch");
static_assert(offsetof(ccSceneAdvPrevBattleInterval, field_0x198) == 0x198, "ccSceneAdvPrevBattleInterval::field_0x198 offset mismatch");
static_assert(offsetof(ccSceneAdvPrevBattleInterval, field_0x1D0) == 0x1D0, "ccSceneAdvPrevBattleInterval::field_0x1D0 offset mismatch");
static_assert(offsetof(ccSceneAdvPrevBattleInterval, advBtlSelParam) == 0x1D8, "ccSceneAdvPrevBattleInterval::advBtlSelParam offset mismatch");

/* ccSceneAdvRecollectionScreen - 5 methods: CreateTexture, CtrlScreen, DeleteTexture, Finalize, Initialize */
/* size unknown, >= 0x144 */
typedef struct __attribute__((packed)) ccSceneAdvRecollectionScreen {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  uint64_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvRecollectionScreen::CreateTexture */
  uint64_t field_0x130; /* 0x130 [rw] INFERRED from ccSceneAdvRecollectionScreen::CreateTexture */
  uint64_t field_0x138; /* 0x138 [rw] INFERRED from ccSceneAdvRecollectionScreen::CreateTexture */
  uint32_t field_0x140; /* 0x140 [rw] INFERRED from ccSceneAdvRecollectionScreen::CreateTexture */
} ccSceneAdvRecollectionScreen;

static_assert(offsetof(ccSceneAdvRecollectionScreen, field_0x128) == 0x128, "ccSceneAdvRecollectionScreen::field_0x128 offset mismatch");
static_assert(offsetof(ccSceneAdvRecollectionScreen, field_0x130) == 0x130, "ccSceneAdvRecollectionScreen::field_0x130 offset mismatch");
static_assert(offsetof(ccSceneAdvRecollectionScreen, field_0x138) == 0x138, "ccSceneAdvRecollectionScreen::field_0x138 offset mismatch");
static_assert(offsetof(ccSceneAdvRecollectionScreen, field_0x140) == 0x140, "ccSceneAdvRecollectionScreen::field_0x140 offset mismatch");

/* ccSceneAdvRoot - 6 methods: Activated, Deactivated, Execute, Finalize, Idling, Initialize */
/* size unknown, >= 0xF64 */
typedef struct __attribute__((packed)) ccSceneAdvRoot {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int64_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvRoot::Execute */
  uint8_t _pad_0x130[0xA8];
  uint32_t advMenuName; /* 0x1D8 [rw] HIGH from ccSceneAdvRoot::Initialize */
  uint8_t _pad_0x1DC[0x3C];
  uint32_t advBtlSelParam; /* 0x218 [rw] HIGH from ccSceneAdvRoot::Initialize */
  uint8_t _pad_0x21C[0xCB4];
  uint32_t advBtlFieldId; /* 0xED0 [rw] HIGH from ccSceneAdvRoot::Initialize */
  uint32_t advMenuState; /* 0xED4 [rw] HIGH from ccSceneAdvRoot::Initialize */
  uint32_t advShopType; /* 0xED8 [rw] HIGH from ccSceneAdvRoot::Initialize */
  uint32_t advDemoNextState; /* 0xEDC [rw] HIGH from ccSceneAdvRoot::Initialize */
  uint32_t advWaitEnd; /* 0xEE0 [rw] HIGH from ccSceneAdvRoot::Initialize */
  int32_t field_0xEE4; /* 0xEE4 [rw] INFERRED from ccSceneAdvRoot::Finalize */
  uint8_t _pad_0xEE8[0x70];
  uint32_t chronologyParamSave; /* 0xF58 [w] HIGH from ccSceneAdvRoot::Finalize */
  uint32_t field_0xF5C; /* 0xF5C [w] INFERRED from ccSceneAdvRoot::Finalize */
  uint32_t field_0xF60; /* 0xF60 [w] INFERRED from ccSceneAdvRoot::Finalize */
} ccSceneAdvRoot;

static_assert(offsetof(ccSceneAdvRoot, field_0x128) == 0x128, "ccSceneAdvRoot::field_0x128 offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advMenuName) == 0x1D8, "ccSceneAdvRoot::advMenuName offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advBtlSelParam) == 0x218, "ccSceneAdvRoot::advBtlSelParam offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advBtlFieldId) == 0xED0, "ccSceneAdvRoot::advBtlFieldId offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advMenuState) == 0xED4, "ccSceneAdvRoot::advMenuState offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advShopType) == 0xED8, "ccSceneAdvRoot::advShopType offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advDemoNextState) == 0xEDC, "ccSceneAdvRoot::advDemoNextState offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, advWaitEnd) == 0xEE0, "ccSceneAdvRoot::advWaitEnd offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, field_0xEE4) == 0xEE4, "ccSceneAdvRoot::field_0xEE4 offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, chronologyParamSave) == 0xF58, "ccSceneAdvRoot::chronologyParamSave offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, field_0xF5C) == 0xF5C, "ccSceneAdvRoot::field_0xF5C offset mismatch");
static_assert(offsetof(ccSceneAdvRoot, field_0xF60) == 0xF60, "ccSceneAdvRoot::field_0xF60 offset mismatch");

/* ccSceneAdvSave - 1 methods: Activated */
/* size unknown, >= 0x18C */
typedef struct __attribute__((packed)) ccSceneAdvSave {
  uint8_t _base_pad[0x178]; /* 0x0..0x177: ccScene base */
  int32_t field_0x178; /* 0x178 [w] INFERRED from ccSceneAdvSave::Activated */
  uint32_t field_0x17C; /* 0x17C [w] INFERRED from ccSceneAdvSave::Activated */
  uint8_t _pad_0x180[0x8];
  uint32_t field_0x188; /* 0x188 [w] INFERRED from ccSceneAdvSave::Activated */
} ccSceneAdvSave;

static_assert(offsetof(ccSceneAdvSave, field_0x178) == 0x178, "ccSceneAdvSave::field_0x178 offset mismatch");
static_assert(offsetof(ccSceneAdvSave, field_0x17C) == 0x17C, "ccSceneAdvSave::field_0x17C offset mismatch");
static_assert(offsetof(ccSceneAdvSave, field_0x188) == 0x188, "ccSceneAdvSave::field_0x188 offset mismatch");

/* ccSceneAdvStaffRoll - 1 methods: Initialize */
/* size unknown, >= 0x130 */
typedef struct __attribute__((packed)) ccSceneAdvStaffRoll {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int64_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvStaffRoll::Initialize */
} ccSceneAdvStaffRoll;

static_assert(offsetof(ccSceneAdvStaffRoll, field_0x128) == 0x128, "ccSceneAdvStaffRoll::field_0x128 offset mismatch");

/* ccSceneAdvStartMenu - 6 methods: Activated, Deactivated, FadeOutCtrl, Finalize, Initialize, NormalCtrl */
/* size unknown, >= 0x160 */
typedef struct __attribute__((packed)) ccSceneAdvStartMenu {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int32_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvStartMenu::NormalCtrl */
  uint8_t _pad_0x12C[0x4];
  int64_t field_0x130; /* 0x130 [r] INFERRED from ccSceneAdvStartMenu::NormalCtrl */
  int64_t field_0x138; /* 0x138 [rw] INFERRED from ccSceneAdvStartMenu::Activated */
  uint8_t _pad_0x140[0x18];
  uint64_t field_0x158; /* 0x158 [r] INFERRED from ccSceneAdvStartMenu::FadeOutCtrl */
} ccSceneAdvStartMenu;

static_assert(offsetof(ccSceneAdvStartMenu, field_0x128) == 0x128, "ccSceneAdvStartMenu::field_0x128 offset mismatch");
static_assert(offsetof(ccSceneAdvStartMenu, field_0x130) == 0x130, "ccSceneAdvStartMenu::field_0x130 offset mismatch");
static_assert(offsetof(ccSceneAdvStartMenu, field_0x138) == 0x138, "ccSceneAdvStartMenu::field_0x138 offset mismatch");
static_assert(offsetof(ccSceneAdvStartMenu, field_0x158) == 0x158, "ccSceneAdvStartMenu::field_0x158 offset mismatch");

/* ccSceneAdvStartMenuChronology - 4 methods: Activated, Execute, Finalize, Initialize */
/* size unknown, >= 0x18C */
typedef struct __attribute__((packed)) ccSceneAdvStartMenuChronology {
  uint8_t _base_pad[0x178]; /* 0x0..0x177: ccScene base */
  int32_t field_0x178; /* 0x178 [rw] INFERRED from ccSceneAdvStartMenuChronology::Execute */
  uint32_t field_0x17C; /* 0x17C [w] INFERRED from ccSceneAdvStartMenuChronology::Initialize */
  uint8_t _pad_0x180[0x8];
  uint32_t field_0x188; /* 0x188 [w] INFERRED from ccSceneAdvStartMenuChronology::Initialize */
} ccSceneAdvStartMenuChronology;

static_assert(offsetof(ccSceneAdvStartMenuChronology, field_0x178) == 0x178, "ccSceneAdvStartMenuChronology::field_0x178 offset mismatch");
static_assert(offsetof(ccSceneAdvStartMenuChronology, field_0x17C) == 0x17C, "ccSceneAdvStartMenuChronology::field_0x17C offset mismatch");
static_assert(offsetof(ccSceneAdvStartMenuChronology, field_0x188) == 0x188, "ccSceneAdvStartMenuChronology::field_0x188 offset mismatch");

/* ccSceneAdvStartMenuCollection - 1 methods: Execute */
/* size unknown, >= 0x12C */
typedef struct __attribute__((packed)) ccSceneAdvStartMenuCollection {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int32_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvStartMenuCollection::Execute */
} ccSceneAdvStartMenuCollection;

static_assert(offsetof(ccSceneAdvStartMenuCollection, field_0x128) == 0x128, "ccSceneAdvStartMenuCollection::field_0x128 offset mismatch");

/* ccSceneAdvStartMenuItemList - 4 methods: Activated, Execute, Finalize, Initialize */
/* size unknown, >= 0x138 */
typedef struct __attribute__((packed)) ccSceneAdvStartMenuItemList {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int32_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvStartMenuItemList::Execute */
  uint8_t _pad_0x12C[0x4];
  int64_t field_0x130; /* 0x130 [rw] INFERRED from ccSceneAdvStartMenuItemList::Activated */
} ccSceneAdvStartMenuItemList;

static_assert(offsetof(ccSceneAdvStartMenuItemList, field_0x128) == 0x128, "ccSceneAdvStartMenuItemList::field_0x128 offset mismatch");
static_assert(offsetof(ccSceneAdvStartMenuItemList, field_0x130) == 0x130, "ccSceneAdvStartMenuItemList::field_0x130 offset mismatch");

/* ccSceneAdvStartMenuMap - 3 methods: Activated, Execute, Initialize */
/* size unknown, >= 0x130 */
typedef struct __attribute__((packed)) ccSceneAdvStartMenuMap {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int64_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvStartMenuMap::Activated */
} ccSceneAdvStartMenuMap;

static_assert(offsetof(ccSceneAdvStartMenuMap, field_0x128) == 0x128, "ccSceneAdvStartMenuMap::field_0x128 offset mismatch");

/* ccSceneAdvStartMenuQuestLog - 2 methods: Activated, Finalize */
/* size unknown, >= 0x130 */
typedef struct __attribute__((packed)) ccSceneAdvStartMenuQuestLog {
  uint8_t _base_pad[0x128]; /* 0x0..0x127: ccScene base */
  int64_t field_0x128; /* 0x128 [rw] INFERRED from ccSceneAdvStartMenuQuestLog::Activated */
} ccSceneAdvStartMenuQuestLog;

static_assert(offsetof(ccSceneAdvStartMenuQuestLog, field_0x128) == 0x128, "ccSceneAdvStartMenuQuestLog::field_0x128 offset mismatch");

#endif /* ST3A15_H */
