#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* st4a12 — Storm 4 ccAdv* struct group
 * Generated from decompiled NSUNS4_release.exe (sha256:147e52a3)
 * All offsets inferred from Ghidra decompilation; confirm at runtime before use.
 * Sizes computed as next_offset - this_offset to avoid TSV overlap artifacts.
 */

#pragma pack(push, 1)

/* ── ccAdvSaveData ─────────────────────────────────────────────── */
typedef struct ccAdvSaveData {
    uint8_t _pad_0000[0x08];          /* +0x00 vtable/unknown */
    uint32_t flags;                    /* +0x08 Init=0 */
    uint8_t _pad_000c[0x10c];          /* gap to +0x118 */
    uint32_t version;                  /* +0x118 Init=0x10001 */
    uint8_t _pad_011c[0x24];           /* gap to +0x140 */
    uint64_t field_140;                /* +0x140 Init=0x21a0000 */
    int32_t field_148;                 /* +0x148 Init=-1 */
    uint32_t field_14c;                /* +0x14c Init=0 */
    int32_t handle;                    /* +0x150 Init(3996ec)=-1 */
    uint8_t _pad_0154[0x4];            /* gap to +0x158 */
    uint8_t array_158[0xf98];          /* +0x158 memset(0), ends at 0x10f0 */
    uint8_t sentLetters[0x4520];       /* +0x10f0 GetSentLetter stride=0x20 x 0x80 */
    int32_t possessItemCount;          /* +0x5610 InitPossessItem */
    uint8_t _pad_5614[0x4];            /* gap to +0x5618 */
    uint8_t possessItems[0xc80];       /* +0x5618 stride=0x10 x 0x800 */
    uint8_t possessItemsEnd[0xa8c];    /* +0x6298 end marker region */
    uint8_t field_6d24[0x84];          /* +0x6d24 memset(0) */
    uint8_t letterSlots[0x10c];        /* +0x6da8 stride=0x2c x 6 */
    uint32_t field_6eb4;               /* +0x6eb4 Init=0 */
    uint8_t _pad_6eb8_pre[0x0];        /* field_6eb8 is uint64 but only 4B gap; see note */
    uint32_t field_6eb8_lo;            /* +0x6eb8 low 32 bits (packed) */
    uint16_t field_6ebc;               /* +0x6ebc Init=0x101 */
    uint8_t field_6ebe_and_pad[0x82ae]; /* +0x6ebe Init=1, includes gap to +0xf16c */
    int32_t extraItemCount;            /* +0xf16c count-200 */
    uint8_t _pad_f170[0x6f90];         /* gap to +0x16100 */
    uint8_t sub_16100[0xd88];          /* +0x16100 thunk init */
    uint8_t sub_16e88[0xd48];          /* +0x16e88 FUN_140734b9c */
    uint8_t array_17bd0[0x6fda];       /* +0x17bd0 stride=0x20 x 0x200 */
    uint8_t array_1ebaa[0x77];         /* +0x1ebaa memset(0) */
    uint16_t field_1ec21;              /* +0x1ec21 Init=0 */
    uint8_t field_1ec23;               /* +0x1ec23 Init=0 */
    uint8_t field_1ec24[0xf7c];        /* +0x1ec24 memset(0), ends at 0x1fba0 */
    uint64_t field_1fba0;              /* +0x1fba0 Init=0 */
} ccAdvSaveData;

_Static_assert(offsetof(ccAdvSaveData, flags) == 0x08, "ccAdvSaveData.flags");
_Static_assert(offsetof(ccAdvSaveData, version) == 0x118, "ccAdvSaveData.version");
_Static_assert(offsetof(ccAdvSaveData, field_140) == 0x140, "ccAdvSaveData.field_140");
_Static_assert(offsetof(ccAdvSaveData, field_148) == 0x148, "ccAdvSaveData.field_148");
_Static_assert(offsetof(ccAdvSaveData, field_14c) == 0x14c, "ccAdvSaveData.field_14c");
_Static_assert(offsetof(ccAdvSaveData, handle) == 0x150, "ccAdvSaveData.handle");
_Static_assert(offsetof(ccAdvSaveData, array_158) == 0x158, "ccAdvSaveData.array_158");
_Static_assert(offsetof(ccAdvSaveData, sentLetters) == 0x10f0, "ccAdvSaveData.sentLetters");
_Static_assert(offsetof(ccAdvSaveData, possessItemCount) == 0x5610, "ccAdvSaveData.possessItemCount");
_Static_assert(offsetof(ccAdvSaveData, possessItems) == 0x5618, "ccAdvSaveData.possessItems");
_Static_assert(offsetof(ccAdvSaveData, possessItemsEnd) == 0x6298, "ccAdvSaveData.possessItemsEnd");
_Static_assert(offsetof(ccAdvSaveData, field_6d24) == 0x6d24, "ccAdvSaveData.field_6d24");
_Static_assert(offsetof(ccAdvSaveData, letterSlots) == 0x6da8, "ccAdvSaveData.letterSlots");
_Static_assert(offsetof(ccAdvSaveData, field_6eb4) == 0x6eb4, "ccAdvSaveData.field_6eb4");
_Static_assert(offsetof(ccAdvSaveData, field_6eb8_lo) == 0x6eb8, "ccAdvSaveData.field_6eb8");
_Static_assert(offsetof(ccAdvSaveData, field_6ebc) == 0x6ebc, "ccAdvSaveData.field_6ebc");
_Static_assert(offsetof(ccAdvSaveData, field_6ebe_and_pad) == 0x6ebe, "ccAdvSaveData.field_6ebe");
_Static_assert(offsetof(ccAdvSaveData, extraItemCount) == 0xf16c, "ccAdvSaveData.extraItemCount");
_Static_assert(offsetof(ccAdvSaveData, sub_16100) == 0x16100, "ccAdvSaveData.sub_16100");
_Static_assert(offsetof(ccAdvSaveData, sub_16e88) == 0x16e88, "ccAdvSaveData.sub_16e88");
_Static_assert(offsetof(ccAdvSaveData, array_17bd0) == 0x17bd0, "ccAdvSaveData.array_17bd0");
_Static_assert(offsetof(ccAdvSaveData, array_1ebaa) == 0x1ebaa, "ccAdvSaveData.array_1ebaa");
_Static_assert(offsetof(ccAdvSaveData, field_1ec21) == 0x1ec21, "ccAdvSaveData.field_1ec21");
_Static_assert(offsetof(ccAdvSaveData, field_1ec23) == 0x1ec23, "ccAdvSaveData.field_1ec23");
_Static_assert(offsetof(ccAdvSaveData, field_1ec24) == 0x1ec24, "ccAdvSaveData.field_1ec24");
_Static_assert(offsetof(ccAdvSaveData, field_1fba0) == 0x1fba0, "ccAdvSaveData.field_1fba0");

/* ── ccAdvPlayerUiManager ──────────────────────────────────────── */
typedef struct ccAdvPlayerUiManager {
    uint8_t _pad_00[0x10];             /* +0x00 vtable/unknown */
    uint8_t areaName[0xb4];            /* +0x10 std::string */
    uint32_t areaNameId;               /* +0xc4 SetAreaName param_3 */
} ccAdvPlayerUiManager;

_Static_assert(offsetof(ccAdvPlayerUiManager, areaName) == 0x10, "ccAdvPlayerUiManager.areaName");
_Static_assert(offsetof(ccAdvPlayerUiManager, areaNameId) == 0xc4, "ccAdvPlayerUiManager.areaNameId");

/* ── ccAdvNavigator ────────────────────────────────────────────── */
typedef struct ccAdvNavigator {
    uint8_t _pad_00[0x48];             /* +0x00 base */
    uint8_t stagePath[0x18];           /* +0x48 std::string */
    size_t stagePathLen;               /* +0x60 length check */
    uint8_t _pad_68[0x18];             /* gap to +0x80 */
    int32_t field_80;                  /* +0x80 AreaChanged -1 */
} ccAdvNavigator;

_Static_assert(offsetof(ccAdvNavigator, stagePath) == 0x48, "ccAdvNavigator.stagePath");
_Static_assert(offsetof(ccAdvNavigator, stagePathLen) == 0x60, "ccAdvNavigator.stagePathLen");
_Static_assert(offsetof(ccAdvNavigator, field_80) == 0x80, "ccAdvNavigator.field_80");

/* ── ccAdvObjectiveParamManager ────────────────────────────────── */
typedef struct ccAdvObjectiveParamManager {
    uint8_t _pad_00[0x08];             /* +0x00 vtable */
    uint8_t objectiveMap[0x20];        /* +0x08 unordered_map */
} ccAdvObjectiveParamManager;

_Static_assert(offsetof(ccAdvObjectiveParamManager, objectiveMap) == 0x08, "ccAdvObjectiveParamManager.objectiveMap");

/* ── ccAdvObjectStateList ──────────────────────────────────────── */
typedef struct ccAdvObjectStateList {
    uint8_t vtable_base[0x18];         /* +0x00 vtable/base */
    uint8_t trailRender[0x18];         /* +0x18 mmEngineFree target */
    uint8_t subWorker[0x18];           /* +0x30 FinalizeBase target */
} ccAdvObjectStateList;

_Static_assert(offsetof(ccAdvObjectStateList, vtable_base) == 0x00, "ccAdvObjectStateList.vtable_base");
_Static_assert(offsetof(ccAdvObjectStateList, trailRender) == 0x18, "ccAdvObjectStateList.trailRender");
_Static_assert(offsetof(ccAdvObjectStateList, subWorker) == 0x30, "ccAdvObjectStateList.subWorker");

/* ── ccAdvStageDraw ────────────────────────────────────────────── */
typedef struct ccAdvStageDraw {
    uint8_t clumps[0x18];              /* +0x00 std::vector */
    uint8_t alloc1[0x18];              /* +0x18 BlockAllocator */
    uint8_t alloc2[0x18];              /* +0x30 BlockAllocator */
    uint8_t nearClumps[0x18];          /* +0x48 std::vector */
} ccAdvStageDraw;

_Static_assert(offsetof(ccAdvStageDraw, clumps) == 0x00, "ccAdvStageDraw.clumps");
_Static_assert(offsetof(ccAdvStageDraw, alloc1) == 0x18, "ccAdvStageDraw.alloc1");
_Static_assert(offsetof(ccAdvStageDraw, alloc2) == 0x30, "ccAdvStageDraw.alloc2");
_Static_assert(offsetof(ccAdvStageDraw, nearClumps) == 0x48, "ccAdvStageDraw.nearClumps");

/* ── ccAdvStageDrawList ────────────────────────────────────────── */
typedef struct ccAdvStageDrawList {
    uint8_t _pad_00[0x28];             /* +0x00 base */
    uint8_t stageBoardMap[0x20];       /* +0x28 std::map */
} ccAdvStageDrawList;

_Static_assert(offsetof(ccAdvStageDrawList, stageBoardMap) == 0x28, "ccAdvStageDrawList.stageBoardMap");

/* ── ccAdvSpriteScDraw ─────────────────────────────────────────── */
typedef struct ccAdvSpriteScDraw {
    uint8_t _pad_00[0x188];            /* +0x00 base */
    int32_t *spriteStatePtr;           /* +0x188 vector begin */
    uint8_t _pad_190[0x10];            /* gap to +0x1a0 */
    int32_t *spriteStateEnd;           /* +0x1a0 vector end */
    uint8_t field_1a8[0x38];           /* +0x1a8 std::string (includes 8B pad) */
    uint8_t field_1e0[0x38];           /* +0x1e0 std::string (includes 8B pad) */
    uint8_t field_218[0x30];           /* +0x218 std::string */
} ccAdvSpriteScDraw;

_Static_assert(offsetof(ccAdvSpriteScDraw, spriteStatePtr) == 0x188, "ccAdvSpriteScDraw.spriteStatePtr");
_Static_assert(offsetof(ccAdvSpriteScDraw, spriteStateEnd) == 0x1a0, "ccAdvSpriteScDraw.spriteStateEnd");
_Static_assert(offsetof(ccAdvSpriteScDraw, field_1a8) == 0x1a8, "ccAdvSpriteScDraw.field_1a8");
_Static_assert(offsetof(ccAdvSpriteScDraw, field_1e0) == 0x1e0, "ccAdvSpriteScDraw.field_1e0");
_Static_assert(offsetof(ccAdvSpriteScDraw, field_218) == 0x218, "ccAdvSpriteScDraw.field_218");

/* ── ccAdvScreenEffect ─────────────────────────────────────────── */
typedef struct ccAdvScreenEffect {
    uint8_t _pad_00[0x1c];             /* +0x00 base */
    float vec_1c[3];                   /* +0x1c Vector3 */
    float vec_28[3];                   /* +0x28 Vector3 */
    float vec_34[3];                   /* +0x34 Vector3 */
    float mat_40[16];                  /* +0x40 Matrix44 */
    float vec_80[3];                   /* +0x80 Vector3 */
    float vec_8c[3];                   /* +0x8c Vector3 */
    float vec_98[3];                   /* +0x98 Vector3 */
    uint8_t _pad_a4[0x50];             /* gap to +0xf4 */
    float mat_f4[16];                  /* +0xf4 Matrix44 */
} ccAdvScreenEffect;

_Static_assert(offsetof(ccAdvScreenEffect, vec_1c) == 0x1c, "ccAdvScreenEffect.vec_1c");
_Static_assert(offsetof(ccAdvScreenEffect, vec_28) == 0x28, "ccAdvScreenEffect.vec_28");
_Static_assert(offsetof(ccAdvScreenEffect, vec_34) == 0x34, "ccAdvScreenEffect.vec_34");
_Static_assert(offsetof(ccAdvScreenEffect, mat_40) == 0x40, "ccAdvScreenEffect.mat_40");
_Static_assert(offsetof(ccAdvScreenEffect, vec_80) == 0x80, "ccAdvScreenEffect.vec_80");
_Static_assert(offsetof(ccAdvScreenEffect, vec_8c) == 0x8c, "ccAdvScreenEffect.vec_8c");
_Static_assert(offsetof(ccAdvScreenEffect, vec_98) == 0x98, "ccAdvScreenEffect.vec_98");
_Static_assert(offsetof(ccAdvScreenEffect, mat_f4) == 0xf4, "ccAdvScreenEffect.mat_f4");

/* ── ccAdvSaveState ────────────────────────────────────────────── */
typedef struct ccAdvSaveState {
    uint8_t _pad_00[0x268];            /* +0x00 base */
    void *callback;                    /* +0x268 func ptr */
    uint32_t field_270;                /* +0x270 EnterSave=0 */
} ccAdvSaveState;

_Static_assert(offsetof(ccAdvSaveState, callback) == 0x268, "ccAdvSaveState.callback");
_Static_assert(offsetof(ccAdvSaveState, field_270) == 0x270, "ccAdvSaveState.field_270");

/* ── ccAdvPrevBattleIntervalUi ─────────────────────────────────── */
typedef struct ccAdvPrevBattleIntervalUi {
    uint8_t _pad_00[0x70];             /* +0x00 base */
    void *uiWindow;                    /* +0x70 operator_new(0x220) */
    uint8_t _pad_78[0x18];             /* gap to +0x90 */
    void *resultWindow;                /* +0x90 operator_new(0x90) */
    uint8_t _pad_98[0x34];             /* gap to +0xcc */
    int32_t initialized;               /* +0xcc check==0 */
} ccAdvPrevBattleIntervalUi;

_Static_assert(offsetof(ccAdvPrevBattleIntervalUi, uiWindow) == 0x70, "ccAdvPrevBattleIntervalUi.uiWindow");
_Static_assert(offsetof(ccAdvPrevBattleIntervalUi, resultWindow) == 0x90, "ccAdvPrevBattleIntervalUi.resultWindow");
_Static_assert(offsetof(ccAdvPrevBattleIntervalUi, initialized) == 0xcc, "ccAdvPrevBattleIntervalUi.initialized");

#pragma pack(pop)