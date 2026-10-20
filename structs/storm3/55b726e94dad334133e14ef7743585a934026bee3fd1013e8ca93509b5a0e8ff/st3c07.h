/* st3c07.h - Story cutscene/event UI structs for NSUNS3.exe (s3) */
/* Generated from the decompiler cache state_surface; all layouts INFERRED, not CONFIRMED. */
#ifndef ST3C07_H
#define ST3C07_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct __attribute__((packed)) ccUiAdvEventTimer {
    uint8_t _pad_0x0[136];
    uint64_t field_0x88; /* 0x88 */
} ccUiAdvEventTimer; /* size unknown, >= 0x90 */
static_assert(offsetof(ccUiAdvEventTimer, field_0x88) == 0x88, "ccUiAdvEventTimer.field_0x88 offset");

/* ccUiAdvTalkWindow: no instance state discovered (seeds=0, ok=False) */
/*   warning: json parse error: Expecting ',' delimiter: line 188 column 6 (char 3655) */

typedef struct __attribute__((packed)) ccUiBattleEndDemo {
    uint8_t _pad_0x0[144];
    uint8_t field_0x90; /* 0x90 */
    uint8_t _pad_0x91[11];
    uint8_t field_0x9c; /* 0x9c */
} ccUiBattleEndDemo; /* size unknown, >= 0x9d */
static_assert(offsetof(ccUiBattleEndDemo, field_0x90) == 0x90, "ccUiBattleEndDemo.field_0x90 offset");
static_assert(offsetof(ccUiBattleEndDemo, field_0x9c) == 0x9c, "ccUiBattleEndDemo.field_0x9c offset");

/* ccUiBoss0700GuideMessage: no state_surface data available in this build */

/* ccUiGroupBattleEventScroll: no state_surface data available in this build */

typedef struct __attribute__((packed)) ccUiGroupBattleGuideMessage {
    uint8_t _pad_0x0[88];
    uint32_t field_0x58; /* 0x58 */
    uint8_t _pad_0x5c[4];
    uint64_t field_0x60; /* 0x60 */
    uint8_t _pad_0x68[408];
    uint8_t field_0x200; /* 0x200 */
} ccUiGroupBattleGuideMessage; /* size unknown, >= 0x201 */
static_assert(offsetof(ccUiGroupBattleGuideMessage, field_0x58) == 0x58, "ccUiGroupBattleGuideMessage.field_0x58 offset");
static_assert(offsetof(ccUiGroupBattleGuideMessage, field_0x60) == 0x60, "ccUiGroupBattleGuideMessage.field_0x60 offset");
static_assert(offsetof(ccUiGroupBattleGuideMessage, field_0x200) == 0x200, "ccUiGroupBattleGuideMessage.field_0x200 offset");

/* ccUiOptionItemSubtitle: no state_surface data available in this build */

/* ccUiPauseMenuDemo: no state_surface data available in this build */

typedef struct __attribute__((packed)) ccUiQuestLogItemMainEvent {
    uint8_t _pad_0x0[256];
    uint64_t field_0x100; /* 0x100 */
    uint64_t field_0x108; /* 0x108 */
    uint64_t field_0x110; /* 0x110 */
    uint64_t field_0x118; /* 0x118 */
    uint32_t field_0x120; /* 0x120 */
    uint8_t _pad_0x124[4];
    uint8_t field_0x128; /* 0x128 */
} ccUiQuestLogItemMainEvent; /* size unknown, >= 0x129 */
static_assert(offsetof(ccUiQuestLogItemMainEvent, field_0x100) == 0x100, "ccUiQuestLogItemMainEvent.field_0x100 offset");
static_assert(offsetof(ccUiQuestLogItemMainEvent, field_0x108) == 0x108, "ccUiQuestLogItemMainEvent.field_0x108 offset");
static_assert(offsetof(ccUiQuestLogItemMainEvent, field_0x110) == 0x110, "ccUiQuestLogItemMainEvent.field_0x110 offset");
static_assert(offsetof(ccUiQuestLogItemMainEvent, field_0x118) == 0x118, "ccUiQuestLogItemMainEvent.field_0x118 offset");
static_assert(offsetof(ccUiQuestLogItemMainEvent, field_0x120) == 0x120, "ccUiQuestLogItemMainEvent.field_0x120 offset");
static_assert(offsetof(ccUiQuestLogItemMainEvent, field_0x128) == 0x128, "ccUiQuestLogItemMainEvent.field_0x128 offset");

/* ccUiSubtitle: no instance state discovered (seeds=0, ok=False) */
/*   warning: json parse error: Expecting ',' delimiter: line 196 column 6 (char 3826) */

/* mmScriptNodeXML: no state_surface data available in this build */

/* mmStatMemoryEvent: no state_surface data available in this build */

/* nuccIpcMessage: no state_surface data available in this build */

/* TrophyUnlockEvent: no instance state discovered (seeds=9, ok=True) */
/*   seeds analyzed: TrophyUnlockEvent::SuccessSecretAction, TrophyUnlockEvent::UnlockChronology, TrophyUnlockEvent::TotalMoneyEarned, TrophyUnlockEvent::UnlockSecretFactor, TrophyUnlockEvent::ChallengeMissionClear */
/*   warning: TrophyUnlockEvent::TotalMoneyEarned: unknown param_1 element size; only byte-cast accesses used */

#endif /* ST3C07_H */
