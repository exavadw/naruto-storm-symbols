/* st4c04.h — Story cutscene/event struct layouts for Storm 4 PC (s4, 1.09) */
/* Auto-generated from decompiled code. All layouts INFERRED, not CONFIRMED. */
/* Sizes are lower bounds (max observed offset + field size). No allocator proof found. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccEventPostEffectState: 16 fields, size unknown >= 0x2B0 */
typedef struct __attribute__((packed)) ccEventPostEffectState {
    uint8_t _pad_000[84];       /* 0x000..0x053 */
    uint32_t stateTimer;        /* 0x054 */
    int32_t enterFrame;         /* 0x058 */
    uint8_t _pad_05c[4];        /* 0x05C..0x05F */
    uint32_t stateId;           /* 0x060 */
    uint8_t _pad_064[4];        /* 0x064..0x067 */
    int64_t fadeParam;          /* 0x068 */
    uint8_t _pad_070[36];       /* 0x070..0x093 */
    int32_t frameCounter;       /* 0x094 */
    uint8_t _pad_098[4];        /* 0x098..0x09B */
    int32_t captureFlag;        /* 0x09C */
    uint8_t _pad_0a0[16];       /* 0x0A0..0x0AF */
    int64_t obj3dPtr;           /* 0x0B0 */
    uint64_t obj3dData;         /* 0x0B8 */
    uint32_t createState;       /* 0x0C0 */
    uint32_t objId;             /* 0x0C4 */
    uint8_t _pad_0c8[376];      /* 0x0C8..0x23F */
    uint32_t obj3dFlag;         /* 0x240 */
    int32_t obj3dType;          /* 0x244 */
    uint8_t _pad_248[24];       /* 0x248..0x25F */
    int32_t obj3dId;            /* 0x260 */
    int32_t obj3dFrame;         /* 0x264 */
    uint8_t _pad_268[56];       /* 0x268..0x29F */
    uint64_t tblDataPtr0;       /* 0x2A0 */
    uint64_t tblDataPtr1;       /* 0x2A8 */
} ccEventPostEffectState;       /* min size 0x2B0 */

static_assert(offsetof(ccEventPostEffectState, stateTimer) == 0x054, "ccEventPostEffectState::stateTimer offset mismatch");
static_assert(offsetof(ccEventPostEffectState, enterFrame) == 0x058, "ccEventPostEffectState::enterFrame offset mismatch");
static_assert(offsetof(ccEventPostEffectState, stateId) == 0x060, "ccEventPostEffectState::stateId offset mismatch");
static_assert(offsetof(ccEventPostEffectState, fadeParam) == 0x068, "ccEventPostEffectState::fadeParam offset mismatch");
static_assert(offsetof(ccEventPostEffectState, frameCounter) == 0x094, "ccEventPostEffectState::frameCounter offset mismatch");
static_assert(offsetof(ccEventPostEffectState, captureFlag) == 0x09C, "ccEventPostEffectState::captureFlag offset mismatch");
static_assert(offsetof(ccEventPostEffectState, obj3dPtr) == 0x0B0, "ccEventPostEffectState::obj3dPtr offset mismatch");
static_assert(offsetof(ccEventPostEffectState, obj3dData) == 0x0B8, "ccEventPostEffectState::obj3dData offset mismatch");
static_assert(offsetof(ccEventPostEffectState, createState) == 0x0C0, "ccEventPostEffectState::createState offset mismatch");
static_assert(offsetof(ccEventPostEffectState, objId) == 0x0C4, "ccEventPostEffectState::objId offset mismatch");
static_assert(offsetof(ccEventPostEffectState, obj3dFlag) == 0x240, "ccEventPostEffectState::obj3dFlag offset mismatch");
static_assert(offsetof(ccEventPostEffectState, obj3dType) == 0x244, "ccEventPostEffectState::obj3dType offset mismatch");
static_assert(offsetof(ccEventPostEffectState, obj3dId) == 0x260, "ccEventPostEffectState::obj3dId offset mismatch");
static_assert(offsetof(ccEventPostEffectState, obj3dFrame) == 0x264, "ccEventPostEffectState::obj3dFrame offset mismatch");
static_assert(offsetof(ccEventPostEffectState, tblDataPtr0) == 0x2A0, "ccEventPostEffectState::tblDataPtr0 offset mismatch");
static_assert(offsetof(ccEventPostEffectState, tblDataPtr1) == 0x2A8, "ccEventPostEffectState::tblDataPtr1 offset mismatch");

/* ccEventScreenFilterState: 7 fields, size unknown >= 0xB0 */
typedef struct __attribute__((packed)) ccEventScreenFilterState {
    uint8_t _pad_000[84];       /* 0x000..0x053 */
    uint32_t stateTimer;        /* 0x054 */
    uint8_t _pad_058[8];        /* 0x058..0x05F */
    uint32_t stateId;           /* 0x060 */
    uint8_t _pad_064[4];        /* 0x064..0x067 */
    int64_t param68;            /* 0x068 */
    int32_t field_070;          /* 0x070 */
    uint8_t _pad_074[28];       /* 0x074..0x08F */
    int32_t filterType;         /* 0x090 */
    uint8_t _pad_094[20];       /* 0x094..0x0A7 */
    int32_t objPtr;             /* 0x0A8 */
    uint32_t noizeState;        /* 0x0AC */
} ccEventScreenFilterState;     /* min size 0xB0 */

static_assert(offsetof(ccEventScreenFilterState, stateTimer) == 0x054, "ccEventScreenFilterState::stateTimer offset mismatch");
static_assert(offsetof(ccEventScreenFilterState, stateId) == 0x060, "ccEventScreenFilterState::stateId offset mismatch");
static_assert(offsetof(ccEventScreenFilterState, param68) == 0x068, "ccEventScreenFilterState::param68 offset mismatch");
static_assert(offsetof(ccEventScreenFilterState, field_070) == 0x070, "ccEventScreenFilterState::field_070 offset mismatch");
static_assert(offsetof(ccEventScreenFilterState, filterType) == 0x090, "ccEventScreenFilterState::filterType offset mismatch");
static_assert(offsetof(ccEventScreenFilterState, objPtr) == 0x0A8, "ccEventScreenFilterState::objPtr offset mismatch");
static_assert(offsetof(ccEventScreenFilterState, noizeState) == 0x0AC, "ccEventScreenFilterState::noizeState offset mismatch");

/* ccEventShadowState: 11 fields, size unknown >= 0x9C */
typedef struct __attribute__((packed)) ccEventShadowState {
    uint8_t _pad_000[12];       /* 0x000..0x00B */
    uint32_t shadowInit0;       /* 0x00C */
    uint8_t _pad_010[4];        /* 0x010..0x013 */
    uint32_t shadowInit1;       /* 0x014 */
    uint8_t _pad_018[60];       /* 0x018..0x053 */
    uint32_t stateTimer;        /* 0x054 */
    int32_t enterFrame;         /* 0x058 */
    uint8_t _pad_05c[4];        /* 0x05C..0x05F */
    uint32_t stateId;           /* 0x060 */
    uint8_t _pad_064[12];       /* 0x064..0x06F */
    uint32_t shadowParam0;      /* 0x070 */
    uint32_t shadowParam1;      /* 0x074 */
    uint32_t shadowParam2;      /* 0x078 */
    uint32_t shadowParam3;      /* 0x07C */
    uint8_t _pad_080[16];       /* 0x080..0x08F */
    int32_t filterType;         /* 0x090 */
    uint8_t _pad_094[4];        /* 0x094..0x097 */
    uint32_t field_098;         /* 0x098 */
} ccEventShadowState;           /* min size 0x9C */

static_assert(offsetof(ccEventShadowState, shadowInit0) == 0x00C, "ccEventShadowState::shadowInit0 offset mismatch");
static_assert(offsetof(ccEventShadowState, shadowInit1) == 0x014, "ccEventShadowState::shadowInit1 offset mismatch");
static_assert(offsetof(ccEventShadowState, stateTimer) == 0x054, "ccEventShadowState::stateTimer offset mismatch");
static_assert(offsetof(ccEventShadowState, enterFrame) == 0x058, "ccEventShadowState::enterFrame offset mismatch");
static_assert(offsetof(ccEventShadowState, stateId) == 0x060, "ccEventShadowState::stateId offset mismatch");
static_assert(offsetof(ccEventShadowState, shadowParam0) == 0x070, "ccEventShadowState::shadowParam0 offset mismatch");
static_assert(offsetof(ccEventShadowState, shadowParam1) == 0x074, "ccEventShadowState::shadowParam1 offset mismatch");
static_assert(offsetof(ccEventShadowState, shadowParam2) == 0x078, "ccEventShadowState::shadowParam2 offset mismatch");
static_assert(offsetof(ccEventShadowState, shadowParam3) == 0x07C, "ccEventShadowState::shadowParam3 offset mismatch");
static_assert(offsetof(ccEventShadowState, filterType) == 0x090, "ccEventShadowState::filterType offset mismatch");
static_assert(offsetof(ccEventShadowState, field_098) == 0x098, "ccEventShadowState::field_098 offset mismatch");

/* ccEventSoftFocusState: 9 fields, size unknown >= 0x8C */
typedef struct __attribute__((packed)) ccEventSoftFocusState {
    uint8_t _pad_000[12];       /* 0x000..0x00B */
    uint32_t sfInit;            /* 0x00C */
    uint8_t _pad_010[68];       /* 0x010..0x053 */
    uint32_t stateTimer;        /* 0x054 */
    int32_t enterFrame;         /* 0x058 */
    uint8_t _pad_05c[4];        /* 0x05C..0x05F */
    uint32_t stateId;           /* 0x060 */
    uint8_t _pad_064[4];        /* 0x064..0x067 */
    float param68;              /* 0x068 */
    float focusRadius;          /* 0x06C */
    int32_t focusMode;          /* 0x070 */
    uint8_t _pad_074[4];        /* 0x074..0x077 */
    int32_t focusParam0;        /* 0x078 */
    uint8_t _pad_07c[12];       /* 0x07C..0x087 */
    int32_t focusParam1;        /* 0x088 */
} ccEventSoftFocusState;        /* min size 0x8C */

static_assert(offsetof(ccEventSoftFocusState, sfInit) == 0x00C, "ccEventSoftFocusState::sfInit offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, stateTimer) == 0x054, "ccEventSoftFocusState::stateTimer offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, enterFrame) == 0x058, "ccEventSoftFocusState::enterFrame offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, stateId) == 0x060, "ccEventSoftFocusState::stateId offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, param68) == 0x068, "ccEventSoftFocusState::param68 offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, focusRadius) == 0x06C, "ccEventSoftFocusState::focusRadius offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, focusMode) == 0x070, "ccEventSoftFocusState::focusMode offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, focusParam0) == 0x078, "ccEventSoftFocusState::focusParam0 offset mismatch");
static_assert(offsetof(ccEventSoftFocusState, focusParam1) == 0x088, "ccEventSoftFocusState::focusParam1 offset mismatch");

/* ccEventSpritePosCtrl: 4 fields, size unknown >= 0x24 */
typedef struct __attribute__((packed)) ccEventSpritePosCtrl {
    uint8_t _pad_000[12];       /* 0x000..0x00B */
    uint32_t posInit;           /* 0x00C */
    uint64_t posTarget;         /* 0x010 */
    uint64_t posCurrent;        /* 0x018 */
    uint32_t posCtrlFlag;       /* 0x020 */
} ccEventSpritePosCtrl;         /* min size 0x24 */

static_assert(offsetof(ccEventSpritePosCtrl, posInit) == 0x00C, "ccEventSpritePosCtrl::posInit offset mismatch");
static_assert(offsetof(ccEventSpritePosCtrl, posTarget) == 0x010, "ccEventSpritePosCtrl::posTarget offset mismatch");
static_assert(offsetof(ccEventSpritePosCtrl, posCurrent) == 0x018, "ccEventSpritePosCtrl::posCurrent offset mismatch");
static_assert(offsetof(ccEventSpritePosCtrl, posCtrlFlag) == 0x020, "ccEventSpritePosCtrl::posCtrlFlag offset mismatch");

/* ccEventSpriteState: 20 fields, size unknown >= 0x2B0 */
typedef struct __attribute__((packed)) ccEventSpriteState {
    uint8_t _pad_000[11];       /* 0x000..0x00A */
    uint8_t field_00b;          /* 0x00B */
    uint32_t field_00c;         /* 0x00C */
    uint8_t _pad_010[4];        /* 0x010..0x013 */
    uint32_t field_014;         /* 0x014 */
    uint8_t _pad_018[25];       /* 0x018..0x030 */
    uint32_t field_031;         /* 0x031 */
    uint8_t _pad_035[31];       /* 0x035..0x053 */
    uint32_t stateTimer;        /* 0x054 */
    uint8_t _pad_058[8];        /* 0x058..0x05F */
    uint32_t stateId;           /* 0x060 */
    uint8_t _pad_064[60];       /* 0x064..0x09F */
    uint32_t createFlag;        /* 0x0A0 */
    uint8_t _pad_0a4[4];        /* 0x0A4..0x0A7 */
    int64_t spriteHandle;       /* 0x0A8 */
    uint8_t _pad_0b0[112];      /* 0x0B0..0x11F */
    int64_t *deleteTarget;      /* 0x120 */
    int64_t deleteRef;          /* 0x128 */
    uint8_t _pad_130[88];       /* 0x130..0x187 */
    int32_t ctrlIndex;          /* 0x188 */
    int32_t tblDataIdx;         /* 0x18C */
    uint8_t _pad_190[16];       /* 0x190..0x19F */
    int32_t animIndex;          /* 0x1A0 */
    int32_t fadeAlpha;          /* 0x1A4 */
    uint8_t _pad_1a8[200];      /* 0x1A8..0x26F */
    uint32_t colorR;            /* 0x270 */
    uint32_t colorG;            /* 0x274 */
    uint32_t colorB;            /* 0x278 */
    uint32_t colorA;            /* 0x27C */
    uint8_t _pad_280[32];       /* 0x280..0x29F */
    int64_t tblDataPtr0;        /* 0x2A0 */
    int64_t tblDataPtr1;        /* 0x2A8 */
} ccEventSpriteState;           /* min size 0x2B0 */

static_assert(offsetof(ccEventSpriteState, field_00b) == 0x00B, "ccEventSpriteState::field_00b offset mismatch");
static_assert(offsetof(ccEventSpriteState, field_00c) == 0x00C, "ccEventSpriteState::field_00c offset mismatch");
static_assert(offsetof(ccEventSpriteState, field_014) == 0x014, "ccEventSpriteState::field_014 offset mismatch");
static_assert(offsetof(ccEventSpriteState, field_031) == 0x031, "ccEventSpriteState::field_031 offset mismatch");
static_assert(offsetof(ccEventSpriteState, stateTimer) == 0x054, "ccEventSpriteState::stateTimer offset mismatch");
static_assert(offsetof(ccEventSpriteState, stateId) == 0x060, "ccEventSpriteState::stateId offset mismatch");
static_assert(offsetof(ccEventSpriteState, createFlag) == 0x0A0, "ccEventSpriteState::createFlag offset mismatch");
static_assert(offsetof(ccEventSpriteState, spriteHandle) == 0x0A8, "ccEventSpriteState::spriteHandle offset mismatch");
static_assert(offsetof(ccEventSpriteState, deleteTarget) == 0x120, "ccEventSpriteState::deleteTarget offset mismatch");
static_assert(offsetof(ccEventSpriteState, deleteRef) == 0x128, "ccEventSpriteState::deleteRef offset mismatch");
static_assert(offsetof(ccEventSpriteState, ctrlIndex) == 0x188, "ccEventSpriteState::ctrlIndex offset mismatch");
static_assert(offsetof(ccEventSpriteState, tblDataIdx) == 0x18C, "ccEventSpriteState::tblDataIdx offset mismatch");
static_assert(offsetof(ccEventSpriteState, animIndex) == 0x1A0, "ccEventSpriteState::animIndex offset mismatch");
static_assert(offsetof(ccEventSpriteState, fadeAlpha) == 0x1A4, "ccEventSpriteState::fadeAlpha offset mismatch");
static_assert(offsetof(ccEventSpriteState, colorR) == 0x270, "ccEventSpriteState::colorR offset mismatch");
static_assert(offsetof(ccEventSpriteState, colorG) == 0x274, "ccEventSpriteState::colorG offset mismatch");
static_assert(offsetof(ccEventSpriteState, colorB) == 0x278, "ccEventSpriteState::colorB offset mismatch");
static_assert(offsetof(ccEventSpriteState, colorA) == 0x27C, "ccEventSpriteState::colorA offset mismatch");
static_assert(offsetof(ccEventSpriteState, tblDataPtr0) == 0x2A0, "ccEventSpriteState::tblDataPtr0 offset mismatch");
static_assert(offsetof(ccEventSpriteState, tblDataPtr1) == 0x2A8, "ccEventSpriteState::tblDataPtr1 offset mismatch");

/* ccEventStageState: 7 fields, size unknown >= 0x188 */
typedef struct __attribute__((packed)) ccEventStageState {
    uint8_t _pad_000[336];      /* 0x000..0x14F */
    uint64_t stageClear0;       /* 0x150 */
    uint64_t stageClear1;       /* 0x158 */
    uint64_t stageClear2;       /* 0x160 */
    uint64_t stageClear3;       /* 0x168 */
    uint32_t stageCreateFlag;   /* 0x170 */
    uint8_t _pad_174[4];        /* 0x174..0x177 */
    uint64_t stageCheckVal;     /* 0x178 */
    uint64_t stageClear4;       /* 0x180 */
} ccEventStageState;            /* min size 0x188 */

static_assert(offsetof(ccEventStageState, stageClear0) == 0x150, "ccEventStageState::stageClear0 offset mismatch");
static_assert(offsetof(ccEventStageState, stageClear1) == 0x158, "ccEventStageState::stageClear1 offset mismatch");
static_assert(offsetof(ccEventStageState, stageClear2) == 0x160, "ccEventStageState::stageClear2 offset mismatch");
static_assert(offsetof(ccEventStageState, stageClear3) == 0x168, "ccEventStageState::stageClear3 offset mismatch");
static_assert(offsetof(ccEventStageState, stageCreateFlag) == 0x170, "ccEventStageState::stageCreateFlag offset mismatch");
static_assert(offsetof(ccEventStageState, stageCheckVal) == 0x178, "ccEventStageState::stageCheckVal offset mismatch");
static_assert(offsetof(ccEventStageState, stageClear4) == 0x180, "ccEventStageState::stageClear4 offset mismatch");