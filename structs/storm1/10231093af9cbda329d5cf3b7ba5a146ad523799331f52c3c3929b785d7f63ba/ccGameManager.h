// ccGameManager (NSUNS1.exe, build s1) — reconstructed from Ghidra decompilation
// Global singleton; size >= 0x1330 bytes (highest proven access: +0x1318 in RegistShurikenBreakCounter)
// Confidence: INFERRED (static analysis only; verify with replay trace before CONFIRMED)
// Generated: 2026-10-19

#pragma once
#include <stdint.h>
#include <stddef.h>

// Forward declarations for embedded/opaque types (typedef so pointer fields compile standalone)
typedef struct ccSelCharaOptionManager ccSelCharaOptionManager; // lazy-allocated via FUN_140393f6c at +0x8E8
typedef struct ccPauseStack ccPauseStack;                       // std::list-like pause level stack at +0x1C0

// 0x18-byte counter struct at +0x1300/+0x1318 (RegistShurikenBreakCounter writes 3×int64 or similar)
typedef struct ccShurikenBreakCounter {
    uint8_t data[0x18];
} ccShurikenBreakCounter;

struct ccGameManager {
    // --- 0x000-0x02F: Base / vtable / unknown ---
    uint8_t _pad_000[0x30];             // 0x000 likely vtable ptr + base class data

    // --- 0x030-0x04F: Core state machine ---
    int32_t requestExitFlag;            // 0x030 RequestExitGame sets =1
    int32_t gameState;                  // 0x034 main state enum
    int32_t playSubState;               // 0x038 sub-state within Play
    int32_t _unk_03C;                   // 0x03C
    int32_t transitionCounter;          // 0x040
    int32_t exitDelayCounter;           // 0x044 ExitToPlay delay counter
    uint8_t stateFlags;                 // 0x048 bitfield (bit0=stage_change_pending)
    uint8_t _pad_049[3];                // 0x049
    int32_t nextGameState;              // 0x04C queued state for ExitToPlay
    int32_t _unk_050;                   // 0x050

    // --- 0x054-0x157: Gap ---
    uint8_t _pad_054[0x104];            // 0x054

    // --- 0x158-0x15B: Goal scene ---
    int32_t goalScene;                  // 0x158 ClearGoalScene writes 0

    // --- 0x15C-0x187: Pause/draw level values ---
    int32_t pauseLv;                    // 0x15C PushPauseLv reads this
    int32_t drawPauseLv;                // 0x160 SetDrawPauseLv target
    int32_t drawPauseLv_alt;            // 0x164 SetDrawPauseLv writes here
    float drawPauseAnim_168;            // 0x168 GetNowDrawPauseLv case 10/11
    float drawPauseAnim_16C;            // 0x16C GetNowDrawPauseLv case 1/8
    float drawPauseAnim_170;            // 0x170 GetNowDrawPauseLv case 5-7
    uint8_t _pad_174[4];                // 0x174

    // --- 0x178-0x187: Demo msg pointers ---
    uint64_t demoMsgPtr_0;              // 0x178 SetDemoMsg idx=0
    uint64_t demoMsgPtr_1;              // 0x180 SetDemoMsg idx=1

    // --- 0x188-0x1BF: Capture / duel result ---
    int32_t captureFrameBufferFlag;     // 0x188 CaptureFrameBuffer sets =1
    int32_t duelResultDelay;            // 0x18C Get/SetDuelResultDelay
    uint8_t _pad_190[0x2C];             // 0x190

    // --- 0x1BC-0x1F7: Pause stacks ---
    int16_t pauseStackCount;            // 0x1BC PopPauseLv checks !=0
    uint8_t _pad_1BE[2];                // 0x1BE
    ccPauseStack* pauseStack;           // 0x1C0 PopPauseLv uses param_1+0x188 → adjusted
    uint8_t _pad_1C8[0x28];             // 0x1C8
    int16_t drawPauseStackCount;        // 0x1F0 PopDrawPauseLv checks !=0
    uint8_t _pad_1F2[6];                // 0x1F2

    // --- 0x1F8-0x21B: AddPauseLv list head ---
    int64_t addPauseLvListHead;         // 0x1F8 AddPauseLv lazy-allocates here
    uint8_t _pad_200[0x14];             // 0x200
    int32_t hugebtlPauseCaptureFlag;    // 0x214 IsHugebtlPauseCaptureFlag
    int32_t exitRequestFlag2;           // 0x218 Main checks ==0; RequestExitGame sets =1

    // --- 0x21C-0x2AB: Gap ---
    uint8_t _pad_21C[0x90];             // 0x21C

    // --- 0x2AC-0x2DF: Stage info block ---
    // Stored as raw bytes: binary uses unaligned uint64 access at 0x2AC (not 8-byte aligned).
    // Layout: 6×uint64 + 1×int32 = 0x34 bytes. Access via memcpy or packed overlay.
    uint8_t stageInfo_raw[0x34];        // 0x2AC SetStageInfo / ChangeStage target

    // --- 0x2E0-0x30F: Duel judge params ---
    uint8_t _pad_2E0[4];                // 0x2E0
    // Raw byte block: 5×uint64 + 1×int32 = 0x2C bytes at unaligned offset 0x2E4
    uint8_t duelJudgeParams[0x2C];      // 0x2E4 SetDuelJudgeParam writes here
    int32_t duelSpecialBgmId;           // 0x310

    // --- 0x314-0x387: Gameplay mode info ---
    int32_t hugeBtlInfo_mode;           // 0x314 SetHugeBtlInfo param1
    int32_t hugeBtlInfo_param;          // 0x318 SetHugeBtlInfo param2
    uint8_t forestRaceInfo[0x34];       // 0x31C GetForestRaceInfo returns param_1+800=0x320 → starts ~0x31C
    uint8_t _pad_350[4];                // 0x350
    // Raw byte block: 3×uint64 + 1×int32 = 0x1C bytes at unaligned offset 0x354
    uint8_t kinoboriRace_raw[0x1C];     // 0x354 KinoboriRaceInfo
    uint8_t _pad_370[0x18];             // 0x370
    int32_t duelLoadingTestEnabled;     // 0x388 IsDuelLoadingTestEnabled

    // --- 0x38C-0x44F: Gap ---
    uint8_t _pad_38C[0xC4];             // 0x38C

    // --- 0x450-0x8CF: Skill customize record (0x120 ints) ---
    int32_t skillCustomizeRecord[0x120];// 0x450 ClearSkillCustomizeRecord

    // --- 0x8D0-0x907: Xfbin restart ---
    int64_t xfbinForRestartPtr;         // 0x8D0 IsXfbinForRestartEnabled
    uint8_t _pad_8D8[0x10];             // 0x8D8

    // --- 0x8E8: SelCharaOptionManager ---
    ccSelCharaOptionManager* selCharaOptionMgr; // 0x8E8 GetSelCharaOptionManager / ClearSelCharaOptionManager

    // --- 0x8F0-0x907: Gap ---
    uint8_t _pad_8F0[0x18];             // 0x8F0

    // --- 0x908-0xB13: Subtitle info block (0x208 bytes) ---
    char subtitleStr1[0x80];            // 0x908
    char subtitleStr2[0x80];            // 0x988
    char subtitleStr3[0x80];            // 0xA08
    char subtitleStr4[0x80];            // 0xA88
    int32_t subtitleEnable;             // 0xB08 SetSubtitleEnable
    int32_t subtitleParam;              // 0xB0C SetSubtitleInfo last param
    uint8_t _pad_B10[4];                // 0xB10

    // --- 0xB14-0xCAF: Gap ---
    uint8_t _pad_B14[0x19C];            // 0xB14

    // --- 0xCB0-0xCDF: Sound handle IDs ---
    int32_t soundHandle_0;              // 0xCB0 Exit checks != -1
    int32_t soundHandle_1;              // 0xCB4 Exit checks != 0
    int32_t soundHandle_2;              // 0xCB8 Exit checks != -1
    uint8_t _pad_CBC[0x1C];             // 0xCBC
    int32_t saveMenuSw;                 // 0xCD8 IsSaveMenuActive / SetSaveMenuSw
    int32_t requestExitGameFlag;        // 0xCDC RequestExitGame sets =1
    int32_t ce0Flag;                    // 0xCE0 Load sets =1; Exit checks
    uint8_t _pad_CE4[0x1C];             // 0xCE4

    // --- 0xD00-0xD6B: Gap ---
    uint8_t _pad_D00[0x6C];             // 0xD00

    // --- 0xD6C-0xDAF: Mode-specific manager pointers ---
    int32_t d6cFlag;                    // 0xD6C Main checks ==0
    uint8_t _pad_D70[0x18];             // 0xD70
    void* duelModeManager;              // 0xD88 playSubState==6
    void* titleModeManager;             // 0xD90 playSubState==7
    void* kinoboriModeManager;          // 0xD98 playSubState==8
    uint8_t _pad_DA0[8];                // 0xDA0
    void* forestRaceManager;            // 0xDA8 playSubState==0xb/0xc
    uint8_t _pad_DB0[0x10];             // 0xDB0

    // --- 0xDC0-0x12BF: Gap ---
    uint8_t _pad_DC0[0x500];            // 0xDC0

    // --- 0x12C0-0x12FF: Thread/task object ---
    uint8_t threadObject[0x40];         // 0x12C0 Load creates; Exit cleans up

    // --- 0x1300-0x132F: Shuriken break counters ---
    ccShurikenBreakCounter shurikenBreak_0; // 0x1300 RegistShurikenBreakCounter
    ccShurikenBreakCounter shurikenBreak_1; // 0x1318 RegistShurikenBreakCounter
};

// Compile-time offset checks (INFERRED from decompiler output)
_Static_assert(offsetof(struct ccGameManager, gameState) == 0x034, "gameState");
_Static_assert(offsetof(struct ccGameManager, playSubState) == 0x038, "playSubState");
_Static_assert(offsetof(struct ccGameManager, stateFlags) == 0x048, "stateFlags");
_Static_assert(offsetof(struct ccGameManager, goalScene) == 0x158, "goalScene");
_Static_assert(offsetof(struct ccGameManager, pauseLv) == 0x15C, "pauseLv");
_Static_assert(offsetof(struct ccGameManager, demoMsgPtr_0) == 0x178, "demoMsgPtr_0");
_Static_assert(offsetof(struct ccGameManager, captureFrameBufferFlag) == 0x188, "captureFrameBufferFlag");
_Static_assert(offsetof(struct ccGameManager, pauseStackCount) == 0x1BC, "pauseStackCount");
_Static_assert(offsetof(struct ccGameManager, pauseStack) == 0x1C0, "pauseStack");
_Static_assert(offsetof(struct ccGameManager, drawPauseStackCount) == 0x1F0, "drawPauseStackCount");
_Static_assert(offsetof(struct ccGameManager, addPauseLvListHead) == 0x1F8, "addPauseLvListHead");
_Static_assert(offsetof(struct ccGameManager, hugebtlPauseCaptureFlag) == 0x214, "hugebtlPauseCaptureFlag");
_Static_assert(offsetof(struct ccGameManager, exitRequestFlag2) == 0x218, "exitRequestFlag2");
_Static_assert(offsetof(struct ccGameManager, stageInfo_raw) == 0x2AC, "stageInfo_raw");
_Static_assert(offsetof(struct ccGameManager, duelJudgeParams) == 0x2E4, "duelJudgeParams");
_Static_assert(offsetof(struct ccGameManager, duelSpecialBgmId) == 0x310, "duelSpecialBgmId");
_Static_assert(offsetof(struct ccGameManager, hugeBtlInfo_mode) == 0x314, "hugeBtlInfo_mode");
_Static_assert(offsetof(struct ccGameManager, forestRaceInfo) == 0x31C, "forestRaceInfo");
_Static_assert(offsetof(struct ccGameManager, kinoboriRace_raw) == 0x354, "kinoboriRace_raw");
_Static_assert(offsetof(struct ccGameManager, duelLoadingTestEnabled) == 0x388, "duelLoadingTestEnabled");
_Static_assert(offsetof(struct ccGameManager, skillCustomizeRecord) == 0x450, "skillCustomizeRecord");
_Static_assert(offsetof(struct ccGameManager, xfbinForRestartPtr) == 0x8D0, "xfbinForRestartPtr");
_Static_assert(offsetof(struct ccGameManager, selCharaOptionMgr) == 0x8E8, "selCharaOptionMgr");
_Static_assert(offsetof(struct ccGameManager, subtitleStr1) == 0x908, "subtitleStr1");
_Static_assert(offsetof(struct ccGameManager, subtitleParam) == 0xB0C, "subtitleParam");
_Static_assert(offsetof(struct ccGameManager, soundHandle_0) == 0xCB0, "soundHandle_0");
_Static_assert(offsetof(struct ccGameManager, saveMenuSw) == 0xCD8, "saveMenuSw");
_Static_assert(offsetof(struct ccGameManager, requestExitGameFlag) == 0xCDC, "requestExitGameFlag");
_Static_assert(offsetof(struct ccGameManager, ce0Flag) == 0xCE0, "ce0Flag");
_Static_assert(offsetof(struct ccGameManager, duelModeManager) == 0xD88, "duelModeManager");
_Static_assert(offsetof(struct ccGameManager, titleModeManager) == 0xD90, "titleModeManager");
_Static_assert(offsetof(struct ccGameManager, kinoboriModeManager) == 0xD98, "kinoboriModeManager");
_Static_assert(offsetof(struct ccGameManager, forestRaceManager) == 0xDA8, "forestRaceManager");
_Static_assert(offsetof(struct ccGameManager, threadObject) == 0x12C0, "threadObject");
_Static_assert(offsetof(struct ccGameManager, shurikenBreak_0) == 0x1300, "shurikenBreak_0");
_Static_assert(offsetof(struct ccGameManager, shurikenBreak_1) == 0x1318, "shurikenBreak_1");
_Static_assert(sizeof(struct ccGameManager) == 0x1330, "sizeof_ccGameManager");