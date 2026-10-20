#ifndef ST3C02_S3_H
#define ST3C02_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* NARUTO STORM 3 Full Burst HD (NSUNS3.exe 64-bit) — st3c02 group: Story CUTSCENE/EVENT classes.
 * All fields INFERRED from static analysis (state_surface), not CONFIRMED at runtime.
 * Packed structs with explicit padding; every field has a static_assert for offset verification.
 */

/* ---- ccAdvTalkWindowList (size=0x40, base_end=0x54) ---- */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccAdvTalkWindowList_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccAdvTalkWindowList_s3;
static_assert(sizeof(ccAdvTalkWindowList_s3) == 0x40, "ccAdvTalkWindowList size mismatch");

/* ---- ccBattleSequenceSettings (size=0x40, base_end=0x54) ---- */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccBattleSequenceSettings_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccBattleSequenceSettings_s3;
static_assert(sizeof(ccBattleSequenceSettings_s3) == 0x40, "ccBattleSequenceSettings size mismatch");

/* ---- ccChakuraCharaEventParamManager (size=0x40, base_end=0x54) ---- */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccChakuraCharaEventParamManager_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccChakuraCharaEventParamManager_s3;
static_assert(sizeof(ccChakuraCharaEventParamManager_s3) == 0x40, "ccChakuraCharaEventParamManager size mismatch");

/* ---- ccCpuScriptLeader (size=0x40, base_end=0x54) ---- */
/* vtable RVA: 0x989880 */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccCpuScriptLeader_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccCpuScriptLeader_s3;
static_assert(sizeof(ccCpuScriptLeader_s3) == 0x40, "ccCpuScriptLeader size mismatch");

/* ---- ccDuelEndDemo (size=0x40, base_end=0x54) ---- */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccDuelEndDemo_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccDuelEndDemo_s3;
static_assert(sizeof(ccDuelEndDemo_s3) == 0x40, "ccDuelEndDemo size mismatch");

/* ---- ccEventBCAdjustmentsState (size=0x40, base_end=0x54) ---- */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccEventBCAdjustmentsState_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccEventBCAdjustmentsState_s3;
static_assert(sizeof(ccEventBCAdjustmentsState_s3) == 0x40, "ccEventBCAdjustmentsState size mismatch");

/* ---- ccEventCamera (size=0x40, base_end=0x54) ---- */
/* no instance state beyond base class — size=0x40 from operator new/allocator; state_surface returned zero own-fields */
typedef struct __attribute__((packed)) ccEventCamera_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_and_data[0x38];                  /* 0x008 opaque */
} ccEventCamera_s3;
static_assert(sizeof(ccEventCamera_s3) == 0x40, "ccEventCamera size mismatch");

/* ---- ccCameraOperatorGroupEvent (size=0x1E0, base_end=0x1B0) ---- */
typedef struct __attribute__((packed)) ccCameraOperatorGroupEvent_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x1A8];              /* 0x008 base class region */
    int32_t      field_1b0;                         /* 0x1B0 [medium] kind=w */
    uint64_t     field_1b4;                         /* 0x1B4 [low] kind=rw */
    int32_t      field_1bc;                         /* 0x1BC [medium] kind=w */
    int32_t      field_1c0;                         /* 0x1C0 [medium] kind=w */
    int32_t      field_1c4;                         /* 0x1C4 [medium] kind=w */
    uint64_t     field_1c8;                         /* 0x1C8 [low] kind=rw */
    int32_t      field_1d0;                         /* 0x1D0 [medium] kind=w */
    int32_t      field_1d4;                         /* 0x1D4 [medium] kind=w */
    int32_t      field_1d8;                         /* 0x1D8 [medium] kind=w */
    uint8_t pad_1dc[0x4];        /* 0x1DC trailing */
} ccCameraOperatorGroupEvent_s3;
static_assert(sizeof(ccCameraOperatorGroupEvent_s3) == 0x1E0, "ccCameraOperatorGroupEvent size mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1b0) == 0x1B0, "ccCameraOperatorGroupEvent::field_1b0 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1b4) == 0x1B4, "ccCameraOperatorGroupEvent::field_1b4 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1bc) == 0x1BC, "ccCameraOperatorGroupEvent::field_1bc offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1c0) == 0x1C0, "ccCameraOperatorGroupEvent::field_1c0 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1c4) == 0x1C4, "ccCameraOperatorGroupEvent::field_1c4 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1c8) == 0x1C8, "ccCameraOperatorGroupEvent::field_1c8 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1d0) == 0x1D0, "ccCameraOperatorGroupEvent::field_1d0 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1d4) == 0x1D4, "ccCameraOperatorGroupEvent::field_1d4 offset mismatch");
static_assert(offsetof(ccCameraOperatorGroupEvent_s3, field_1d8) == 0x1D8, "ccCameraOperatorGroupEvent::field_1d8 offset mismatch");

/* ---- ccCpuPlayerGroupScript (size=0x1340, base_end=0x1300) ---- */
/* vtable RVA: 0x93A998 */
typedef struct __attribute__((packed)) ccCpuPlayerGroupScript_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x12F8];              /* 0x008 base class region */
    uint64_t     field_1300;                        /* 0x1300 [medium] kind=w */
    uint8_t field_1308[0x38];                       /* 0x1308 [low] kind=r */
} ccCpuPlayerGroupScript_s3;
static_assert(sizeof(ccCpuPlayerGroupScript_s3) == 0x1340, "ccCpuPlayerGroupScript size mismatch");
static_assert(offsetof(ccCpuPlayerGroupScript_s3, field_1300) == 0x1300, "ccCpuPlayerGroupScript::field_1300 offset mismatch");
static_assert(offsetof(ccCpuPlayerGroupScript_s3, field_1308) == 0x1308, "ccCpuPlayerGroupScript::field_1308 offset mismatch");

/* ---- ccDemoCtrl (size=0x368, base_end=0x54) ---- */
/* vtable RVA: 0x985048 */
typedef struct __attribute__((packed)) ccDemoCtrl_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x4C];              /* 0x008 base class region */
    uint64_t     field_054;                         /* 0x054 [medium] kind=w */
    int32_t      field_05c;                         /* 0x05C [medium] kind=w */
    int32_t      field_060;                         /* 0x060 [medium] kind=w */
    uint8_t pad_064[0x4];        /* 0x064 gap */
    uint64_t     field_068;                         /* 0x068 [medium] kind=w */
    uint8_t      field_070;                         /* 0x070 [low] kind=rw */
    uint8_t pad_071[0xF];        /* 0x071 gap */
    uint64_t     field_080;                         /* 0x080 [medium] kind=w */
    uint64_t     field_088;                         /* 0x088 [medium] kind=rw */
    uint64_t     field_090;                         /* 0x090 [low] kind=rw */
    uint8_t pad_098[0x10];       /* 0x098 gap */
    uint64_t     field_0a8;                         /* 0x0A8 [medium] kind=w */
    uint64_t     field_0b0;                         /* 0x0B0 [medium] kind=w */
    uint64_t     field_0b8;                         /* 0x0B8 [medium] kind=w */
    uint8_t field_0c0[0x280];                       /* 0x0C0 [low] kind=r */
    uint64_t     field_340;                         /* 0x340 [low] kind=rw */
    uint64_t     field_348;                         /* 0x348 [medium] kind=w */
    uint64_t     field_350;                         /* 0x350 [medium] kind=w */
    uint64_t     field_358;                         /* 0x358 [medium] kind=w */
    int32_t      field_360;                         /* 0x360 [medium] kind=w */
    uint8_t pad_364[0x4];        /* 0x364 trailing */
} ccDemoCtrl_s3;
static_assert(sizeof(ccDemoCtrl_s3) == 0x368, "ccDemoCtrl size mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_054) == 0x54, "ccDemoCtrl::field_054 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_05c) == 0x5C, "ccDemoCtrl::field_05c offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_060) == 0x60, "ccDemoCtrl::field_060 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_068) == 0x68, "ccDemoCtrl::field_068 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_070) == 0x70, "ccDemoCtrl::field_070 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_080) == 0x80, "ccDemoCtrl::field_080 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_088) == 0x88, "ccDemoCtrl::field_088 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_090) == 0x90, "ccDemoCtrl::field_090 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_0a8) == 0xA8, "ccDemoCtrl::field_0a8 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_0b0) == 0xB0, "ccDemoCtrl::field_0b0 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_0b8) == 0xB8, "ccDemoCtrl::field_0b8 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_0c0) == 0xC0, "ccDemoCtrl::field_0c0 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_340) == 0x340, "ccDemoCtrl::field_340 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_348) == 0x348, "ccDemoCtrl::field_348 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_350) == 0x350, "ccDemoCtrl::field_350 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_358) == 0x358, "ccDemoCtrl::field_358 offset mismatch");
static_assert(offsetof(ccDemoCtrl_s3, field_360) == 0x360, "ccDemoCtrl::field_360 offset mismatch");

/* ---- ccDemoLoad (size=0x170, base_end=0x148) ---- */
typedef struct __attribute__((packed)) ccDemoLoad_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x140];              /* 0x008 base class region */
    uint8_t      field_148;                         /* 0x148 [medium] kind=rw */
    uint8_t pad_149[0xF];        /* 0x149 gap */
    uint64_t     field_158;                         /* 0x158 [medium] kind=w */
    uint64_t     field_160;                         /* 0x160 [medium] kind=rw */
    uint64_t     field_168;                         /* 0x168 [low] kind=rw */
} ccDemoLoad_s3;
static_assert(sizeof(ccDemoLoad_s3) == 0x170, "ccDemoLoad size mismatch");
static_assert(offsetof(ccDemoLoad_s3, field_148) == 0x148, "ccDemoLoad::field_148 offset mismatch");
static_assert(offsetof(ccDemoLoad_s3, field_158) == 0x158, "ccDemoLoad::field_158 offset mismatch");
static_assert(offsetof(ccDemoLoad_s3, field_160) == 0x160, "ccDemoLoad::field_160 offset mismatch");
static_assert(offsetof(ccDemoLoad_s3, field_168) == 0x168, "ccDemoLoad::field_168 offset mismatch");

/* ---- ccDemoParamManager (size=0x150, base_end=0x148) ---- */
typedef struct __attribute__((packed)) ccDemoParamManager_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x140];              /* 0x008 base class region */
    uint64_t     field_148;                         /* 0x148 [low] kind=r */
} ccDemoParamManager_s3;
static_assert(sizeof(ccDemoParamManager_s3) == 0x150, "ccDemoParamManager size mismatch");
static_assert(offsetof(ccDemoParamManager_s3, field_148) == 0x148, "ccDemoParamManager::field_148 offset mismatch");

/* ---- ccEventAnmState (size=0x430, base_end=0x54) ---- */
/* vtable RVA: 0x983CC0 */
typedef struct __attribute__((packed)) ccEventAnmState_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x4C];              /* 0x008 base class region */
    uint64_t     field_054;                         /* 0x054 [medium] kind=w */
    int32_t      field_05c;                         /* 0x05C [medium] kind=w */
    int32_t      field_060;                         /* 0x060 [medium] kind=w */
    uint8_t pad_064[0x4];        /* 0x064 gap */
    uint64_t     field_068;                         /* 0x068 [medium] kind=w */
    uint64_t     field_070;                         /* 0x070 [medium] kind=w */
    uint8_t field_078[0x38];                        /* 0x078 [low] kind=r */
    int32_t      field_0b0;                         /* 0x0B0 [medium] kind=w */
    uint8_t field_0b4[0xC];                         /* 0x0B4 [low] kind=r */
    uint8_t field_0c0[0xC];                         /* 0x0C0 [low] kind=r */
    uint64_t     field_0cc;                         /* 0x0CC [medium] kind=w */
    uint8_t pad_0d4[0x4];        /* 0x0D4 gap */
    uint8_t field_0d8[0x138];                       /* 0x0D8 [low] kind=r */
    int32_t      field_210;                         /* 0x210 [medium] kind=w */
    int32_t      field_214;                         /* 0x214 [medium] kind=w */
    int32_t      field_218;                         /* 0x218 [medium] kind=w */
    uint64_t     field_21c;                         /* 0x21C [medium] kind=w */
    int32_t      field_224;                         /* 0x224 [medium] kind=w */
    uint64_t     field_228;                         /* 0x228 [medium] kind=w */
    uint8_t field_230[0x50];                        /* 0x230 [low] kind=r */
    uint8_t field_280[0xC];                         /* 0x280 [low] kind=r */
    uint8_t field_28c[0x3C];                        /* 0x28C [low] kind=r */
    uint64_t     field_2c8;                         /* 0x2C8 [low] kind=r */
    uint64_t     field_2d0;                         /* 0x2D0 [medium] kind=w */
    uint64_t     field_2d8;                         /* 0x2D8 [medium] kind=rw */
    uint64_t     field_2e0;                         /* 0x2E0 [low] kind=rw */
    uint8_t pad_2e8[0x10];       /* 0x2E8 gap */
    uint64_t     field_2f8;                         /* 0x2F8 [low] kind=r */
    uint64_t     field_300;                         /* 0x300 [medium] kind=w */
    uint64_t     field_308;                         /* 0x308 [medium] kind=rw */
    uint64_t     field_310;                         /* 0x310 [low] kind=rw */
    uint8_t pad_318[0x10];       /* 0x318 gap */
    uint64_t     field_328;                         /* 0x328 [low] kind=r */
    uint64_t     field_330;                         /* 0x330 [medium] kind=w */
    uint64_t     field_338;                         /* 0x338 [medium] kind=rw */
    uint64_t     field_340;                         /* 0x340 [low] kind=rw */
    uint8_t pad_348[0x10];       /* 0x348 gap */
    uint64_t     field_358;                         /* 0x358 [medium] kind=w */
    uint64_t     field_360;                         /* 0x360 [low] kind=r */
    uint64_t     field_368;                         /* 0x368 [medium] kind=w */
    uint64_t     field_370;                         /* 0x370 [medium] kind=rw */
    uint64_t     field_378;                         /* 0x378 [low] kind=rw */
    uint8_t pad_380[0x10];       /* 0x380 gap */
    uint64_t     field_390;                         /* 0x390 [medium] kind=w */
    uint64_t     field_398;                         /* 0x398 [medium] kind=w */
    uint64_t     field_3a0;                         /* 0x3A0 [medium] kind=w */
    uint64_t     field_3a8;                         /* 0x3A8 [medium] kind=w */
    uint64_t     field_3b0;                         /* 0x3B0 [low] kind=rw */
    uint8_t pad_3b8[0x10];       /* 0x3B8 gap */
    uint64_t     field_3c8;                         /* 0x3C8 [medium] kind=w */
    uint64_t     field_3d0;                         /* 0x3D0 [medium] kind=w */
    uint64_t     field_3d8;                         /* 0x3D8 [medium] kind=w */
    uint64_t     field_3e0;                         /* 0x3E0 [low] kind=rw */
    uint8_t pad_3e8[0x10];       /* 0x3E8 gap */
    uint64_t     field_3f8;                         /* 0x3F8 [medium] kind=w */
    uint64_t     field_400;                         /* 0x400 [low] kind=r */
    uint64_t     field_408;                         /* 0x408 [medium] kind=w */
    uint64_t     field_410;                         /* 0x410 [medium] kind=rw */
    uint64_t     field_418;                         /* 0x418 [low] kind=rw */
    uint8_t pad_420[0x10];       /* 0x420 trailing */
} ccEventAnmState_s3;
static_assert(sizeof(ccEventAnmState_s3) == 0x430, "ccEventAnmState size mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_054) == 0x54, "ccEventAnmState::field_054 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_05c) == 0x5C, "ccEventAnmState::field_05c offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_060) == 0x60, "ccEventAnmState::field_060 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_068) == 0x68, "ccEventAnmState::field_068 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_070) == 0x70, "ccEventAnmState::field_070 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_078) == 0x78, "ccEventAnmState::field_078 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_0b0) == 0xB0, "ccEventAnmState::field_0b0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_0b4) == 0xB4, "ccEventAnmState::field_0b4 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_0c0) == 0xC0, "ccEventAnmState::field_0c0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_0cc) == 0xCC, "ccEventAnmState::field_0cc offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_0d8) == 0xD8, "ccEventAnmState::field_0d8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_210) == 0x210, "ccEventAnmState::field_210 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_214) == 0x214, "ccEventAnmState::field_214 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_218) == 0x218, "ccEventAnmState::field_218 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_21c) == 0x21C, "ccEventAnmState::field_21c offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_224) == 0x224, "ccEventAnmState::field_224 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_228) == 0x228, "ccEventAnmState::field_228 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_230) == 0x230, "ccEventAnmState::field_230 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_280) == 0x280, "ccEventAnmState::field_280 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_28c) == 0x28C, "ccEventAnmState::field_28c offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_2c8) == 0x2C8, "ccEventAnmState::field_2c8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_2d0) == 0x2D0, "ccEventAnmState::field_2d0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_2d8) == 0x2D8, "ccEventAnmState::field_2d8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_2e0) == 0x2E0, "ccEventAnmState::field_2e0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_2f8) == 0x2F8, "ccEventAnmState::field_2f8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_300) == 0x300, "ccEventAnmState::field_300 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_308) == 0x308, "ccEventAnmState::field_308 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_310) == 0x310, "ccEventAnmState::field_310 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_328) == 0x328, "ccEventAnmState::field_328 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_330) == 0x330, "ccEventAnmState::field_330 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_338) == 0x338, "ccEventAnmState::field_338 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_340) == 0x340, "ccEventAnmState::field_340 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_358) == 0x358, "ccEventAnmState::field_358 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_360) == 0x360, "ccEventAnmState::field_360 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_368) == 0x368, "ccEventAnmState::field_368 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_370) == 0x370, "ccEventAnmState::field_370 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_378) == 0x378, "ccEventAnmState::field_378 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_390) == 0x390, "ccEventAnmState::field_390 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_398) == 0x398, "ccEventAnmState::field_398 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3a0) == 0x3A0, "ccEventAnmState::field_3a0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3a8) == 0x3A8, "ccEventAnmState::field_3a8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3b0) == 0x3B0, "ccEventAnmState::field_3b0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3c8) == 0x3C8, "ccEventAnmState::field_3c8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3d0) == 0x3D0, "ccEventAnmState::field_3d0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3d8) == 0x3D8, "ccEventAnmState::field_3d8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3e0) == 0x3E0, "ccEventAnmState::field_3e0 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_3f8) == 0x3F8, "ccEventAnmState::field_3f8 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_400) == 0x400, "ccEventAnmState::field_400 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_408) == 0x408, "ccEventAnmState::field_408 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_410) == 0x410, "ccEventAnmState::field_410 offset mismatch");
static_assert(offsetof(ccEventAnmState_s3, field_418) == 0x418, "ccEventAnmState::field_418 offset mismatch");

/* ---- ccEventBlurState (size=0x100, base_end=0x54) ---- */
/* vtable RVA: 0x984130 */
typedef struct __attribute__((packed)) ccEventBlurState_s3 {
    uint64_t vtable;                                        /* 0x000 */
    uint8_t base_fields[0x4C];              /* 0x008 base class region */
    uint64_t     field_054;                         /* 0x054 [medium] kind=w */
    int32_t      field_05c;                         /* 0x05C [medium] kind=w */
    int32_t      field_060;                         /* 0x060 [medium] kind=w */
    uint8_t pad_064[0x4];        /* 0x064 gap */
    uint64_t     field_068;                         /* 0x068 [medium] kind=w */
    uint64_t     field_070;                         /* 0x070 [medium] kind=w */
    uint64_t     field_078;                         /* 0x078 [medium] kind=w */
    uint64_t     field_080;                         /* 0x080 [medium] kind=w */
    uint64_t     field_088;                         /* 0x088 [medium] kind=w */
    uint64_t     field_090;                         /* 0x090 [medium] kind=w */
    uint64_t     field_098;                         /* 0x098 [medium] kind=w */
    uint8_t pad_0a0[0x8];        /* 0x0A0 gap */
    uint64_t     field_0a8;                         /* 0x0A8 [medium] kind=w */
    uint8_t field_0b0[0x30];                        /* 0x0B0 [low] kind=r */
    uint64_t     field_0e0;                         /* 0x0E0 [low] kind=r */
    uint64_t     field_0e8;                         /* 0x0E8 [medium] kind=w */
    uint64_t     field_0f0;                         /* 0x0F0 [medium] kind=rw */
    uint64_t     field_0f8;                         /* 0x0F8 [low] kind=rw */
} ccEventBlurState_s3;
static_assert(sizeof(ccEventBlurState_s3) == 0x100, "ccEventBlurState size mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_054) == 0x54, "ccEventBlurState::field_054 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_05c) == 0x5C, "ccEventBlurState::field_05c offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_060) == 0x60, "ccEventBlurState::field_060 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_068) == 0x68, "ccEventBlurState::field_068 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_070) == 0x70, "ccEventBlurState::field_070 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_078) == 0x78, "ccEventBlurState::field_078 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_080) == 0x80, "ccEventBlurState::field_080 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_088) == 0x88, "ccEventBlurState::field_088 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_090) == 0x90, "ccEventBlurState::field_090 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_098) == 0x98, "ccEventBlurState::field_098 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_0a8) == 0xA8, "ccEventBlurState::field_0a8 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_0b0) == 0xB0, "ccEventBlurState::field_0b0 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_0e0) == 0xE0, "ccEventBlurState::field_0e0 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_0e8) == 0xE8, "ccEventBlurState::field_0e8 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_0f0) == 0xF0, "ccEventBlurState::field_0f0 offset mismatch");
static_assert(offsetof(ccEventBlurState_s3, field_0f8) == 0xF8, "ccEventBlurState::field_0f8 offset mismatch");

#endif /* ST3C02_S3_H */
