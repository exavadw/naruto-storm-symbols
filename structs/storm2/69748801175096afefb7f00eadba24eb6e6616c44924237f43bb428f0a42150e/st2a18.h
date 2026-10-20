/* st2a18.h — Story progression UI structs for NARUTO STORM 2 (NSUNS2.exe, build s2)
 *
 * All layouts are INFERRED from static analysis (constructors + state_surface).
 * No runtime confirmation. Sizes are minimum bounds from highest observed field
 * offset; actual allocations may be larger. Where no operator-new size was found,
 * size is marked "unknown, >= 0x<N>" with no sizeof assert.
 *
 * Build: s2 / NSUNS2.exe-abf2b6 / sha256 697488...
 * Generated: 2026-10-19
 */

#ifndef ST2A18_H
#define ST2A18_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccUiMissionBattleSelect
 * vtable: 0x14085DBF8
 * Inherits: ccUiTaskBase -> ccUiObjectContainer (at +0x18, +0x20)
 * Size: unknown, >= 0x188 (highest field at 0x180, sz=4)
 * Methods: 13
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiMissionBattleSelect {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x34];             /* 0x008 - base class fields */
    int32_t field_03C;                  /* 0x03C - initialized to -1 */
    uint8_t _pad_040[0x0C];             /* 0x040 */
    uint64_t field_04C;                 /* 0x04C */
    uint8_t _pad_054[0x04];             /* 0x054 */
    uint64_t field_058;                 /* 0x058 */
    uint64_t field_060;                 /* 0x060 */
    uint64_t field_068;                 /* 0x068 */
    uint64_t field_070;                 /* 0x070 */
    uint64_t field_078;                 /* 0x078 */
    uint64_t field_080;                 /* 0x080 */
    uint64_t field_088;                 /* 0x088 */
    uint8_t _pad_090[0x10];             /* 0x090 */
    uint64_t field_0A0;                 /* 0x0A0 */
    uint64_t field_0A8;                 /* 0x0A8 */
    uint8_t _pad_0B0[0xA0];             /* 0x0B0 */
    uint64_t field_150;                 /* 0x150 */
    uint64_t field_158;                 /* 0x158 */
    uint64_t field_160;                 /* 0x160 */
    uint64_t field_168_rw;              /* 0x168 - rw, low confidence */
    uint8_t _pad_170[0x10];             /* 0x170 */
    int32_t field_180;                  /* 0x180 */
    uint8_t _pad_184[0x04];             /* 0x184 */
} ccUiMissionBattleSelect;

static_assert(offsetof(ccUiMissionBattleSelect, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiMissionBattleSelect, field_03C) == 0x03C, "field_03C");
static_assert(offsetof(ccUiMissionBattleSelect, field_04C) == 0x04C, "field_04C");
static_assert(offsetof(ccUiMissionBattleSelect, field_058) == 0x058, "field_058");
static_assert(offsetof(ccUiMissionBattleSelect, field_060) == 0x060, "field_060");
static_assert(offsetof(ccUiMissionBattleSelect, field_068) == 0x068, "field_068");
static_assert(offsetof(ccUiMissionBattleSelect, field_070) == 0x070, "field_070");
static_assert(offsetof(ccUiMissionBattleSelect, field_078) == 0x078, "field_078");
static_assert(offsetof(ccUiMissionBattleSelect, field_080) == 0x080, "field_080");
static_assert(offsetof(ccUiMissionBattleSelect, field_088) == 0x088, "field_088");
static_assert(offsetof(ccUiMissionBattleSelect, field_0A0) == 0x0A0, "field_0A0");
static_assert(offsetof(ccUiMissionBattleSelect, field_0A8) == 0x0A8, "field_0A8");
static_assert(offsetof(ccUiMissionBattleSelect, field_150) == 0x150, "field_150");
static_assert(offsetof(ccUiMissionBattleSelect, field_158) == 0x158, "field_158");
static_assert(offsetof(ccUiMissionBattleSelect, field_160) == 0x160, "field_160");
static_assert(offsetof(ccUiMissionBattleSelect, field_168_rw) == 0x168, "field_168_rw");
static_assert(offsetof(ccUiMissionBattleSelect, field_180) == 0x180, "field_180");

/* =========================================================================
 * ccUiChapterSelect
 * vtable: 0x1408516E8
 * Inherits: ccUiTaskBase
 * Size: unknown, >= 0xA0 (highest read at 0x98)
 * Methods: 8
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiChapterSelect {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x50];             /* 0x008 - base class fields */
    uint64_t field_058;                 /* 0x058 */
    uint64_t field_060_rw;              /* 0x060 - rw, low confidence */
    uint8_t _pad_068[0x30];             /* 0x068 */
    uint64_t field_098_r;               /* 0x098 - read-only */
    uint8_t _pad_0A0[0x00];             /* end */
} ccUiChapterSelect;

static_assert(offsetof(ccUiChapterSelect, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiChapterSelect, field_058) == 0x058, "field_058");
static_assert(offsetof(ccUiChapterSelect, field_060_rw) == 0x060, "field_060_rw");
static_assert(offsetof(ccUiChapterSelect, field_098_r) == 0x098, "field_098_r");

/* =========================================================================
 * ccUiMissionBattleDetail
 * vtable: 0x14085D728
 * Inherits: ccUiTaskBase
 * Contains: ccDuelSettingInfo at +0x48 (param_1+9 in ctor), linked lists at +0x210/+0x240
 * Size: unknown, >= 0x2C0 (highest read at 0x2B8)
 * Methods: 7
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiMissionBattleDetail {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x40];             /* 0x008 - base class fields */
    uint8_t duel_setting_info[0x1C8];   /* 0x048 - ccDuelSettingInfo (Clear called) */
    uint64_t field_210_r;               /* 0x210 - read-only */
    uint8_t _pad_218[0x28];             /* 0x218 */
    uint64_t field_240_r;               /* 0x240 - read-only */
    uint8_t _pad_248[0x30];             /* 0x248 */
    uint64_t field_278_r;               /* 0x278 - read-only */
    uint8_t _pad_280[0x38];             /* 0x280 */
    uint64_t field_2B8_r;               /* 0x2B8 - read-only */
} ccUiMissionBattleDetail;

static_assert(offsetof(ccUiMissionBattleDetail, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiMissionBattleDetail, duel_setting_info) == 0x048, "duel_setting_info");
static_assert(offsetof(ccUiMissionBattleDetail, field_210_r) == 0x210, "field_210_r");
static_assert(offsetof(ccUiMissionBattleDetail, field_240_r) == 0x240, "field_240_r");
static_assert(offsetof(ccUiMissionBattleDetail, field_278_r) == 0x278, "field_278_r");
static_assert(offsetof(ccUiMissionBattleDetail, field_2B8_r) == 0x2B8, "field_2B8_r");

/* =========================================================================
 * ccUiLoadingStory
 * vtable: 0x14085CAD8
 * Inherits: ccUiLoadingBase
 * Contains: ccUiObjectContainer at +0xA0, btConvexHullInternal::Vertex at +0xE0
 * Size: unknown, >= 0xE8 (highest read at 0xE0)
 * Methods: 8
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiLoadingStory {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x40];             /* 0x008 */
    void *secondary_vtable;             /* 0x048 - PTR_FUN_1408918e8 */
    uint8_t _pad_050[0x20];             /* 0x050 */
    uint64_t field_070;                 /* 0x070 */
    uint64_t field_078;                 /* 0x078 */
    uint8_t _pad_080[0x18];             /* 0x080 */
    uint64_t field_098;                 /* 0x098 */
    uint64_t field_0A0_r;               /* 0x0A0 - read-only */
    uint8_t _pad_0A8[0x38];             /* 0x0A8 */
    uint64_t field_0E0_r;               /* 0x0E0 - read-only */
} ccUiLoadingStory;

static_assert(offsetof(ccUiLoadingStory, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiLoadingStory, secondary_vtable) == 0x048, "secondary_vtable");
static_assert(offsetof(ccUiLoadingStory, field_070) == 0x070, "field_070");
static_assert(offsetof(ccUiLoadingStory, field_078) == 0x078, "field_078");
static_assert(offsetof(ccUiLoadingStory, field_098) == 0x098, "field_098");
static_assert(offsetof(ccUiLoadingStory, field_0A0_r) == 0x0A0, "field_0A0_r");
static_assert(offsetof(ccUiLoadingStory, field_0E0_r) == 0x0E0, "field_0E0_r");

/* =========================================================================
 * ccUiMissionCheck
 * vtable: 0x14085DCC8
 * Inherits: ccUiTaskBase
 * Size: unknown, >= 0x90 (highest write at 0x8C)
 * Methods: 6
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiMissionCheck {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x84];             /* 0x008 - base class + BlockAllocator */
    int32_t field_08C;                  /* 0x08C - initialized to 0 */
    uint8_t _pad_090[0x00];             /* end */
} ccUiMissionCheck;

static_assert(offsetof(ccUiMissionCheck, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiMissionCheck, field_08C) == 0x08C, "field_08C");

/* =========================================================================
 * ccUiTargetAdvCommon
 * No ctor found in s2 symbols.
 * Size: unknown, >= 0x1C8 (highest read at 0x1C0)
 * Methods: 9 (Finalize is primary seed)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiTargetAdvCommon {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x78];             /* 0x008 */
    int32_t field_080;                  /* 0x080 */
    uint8_t _pad_084[0x5C];             /* 0x084 */
    uint64_t field_0E0;                 /* 0x0E0 */
    uint64_t field_0E8;                 /* 0x0E8 */
    uint64_t field_0F0;                 /* 0x0F0 */
    uint64_t field_0F8;                 /* 0x0F8 */
    int32_t field_100;                  /* 0x100 */
    uint8_t _pad_104[0xBC];             /* 0x104 */
    uint64_t field_1C0_r;               /* 0x1C0 - read-only */
} ccUiTargetAdvCommon;

static_assert(offsetof(ccUiTargetAdvCommon, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiTargetAdvCommon, field_080) == 0x080, "field_080");
static_assert(offsetof(ccUiTargetAdvCommon, field_0E0) == 0x0E0, "field_0E0");
static_assert(offsetof(ccUiTargetAdvCommon, field_0E8) == 0x0E8, "field_0E8");
static_assert(offsetof(ccUiTargetAdvCommon, field_0F0) == 0x0F0, "field_0F0");
static_assert(offsetof(ccUiTargetAdvCommon, field_0F8) == 0x0F8, "field_0F8");
static_assert(offsetof(ccUiTargetAdvCommon, field_100) == 0x100, "field_100");
static_assert(offsetof(ccUiTargetAdvCommon, field_1C0_r) == 0x1C0, "field_1C0_r");

/* =========================================================================
 * ccUiAdvSummaryCheckCtrl
 * vtable: 0x140850698
 * Inherits: ccTaskBase (NOT ccUiTaskBase)
 * Size: unknown, >= 0x1688 (highest rw field at 0x1680)
 * Methods: 15
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiAdvSummaryCheckCtrl {
    void *vtable;                       /* 0x0000 */
    uint8_t _pad_0008[0x14B0];          /* 0x0008 - large base class region */
    uint64_t field_14B8;                /* 0x14B8 */
    uint64_t field_14C0;                /* 0x14C0 */
    uint64_t field_14C8;                /* 0x14C8 */
    uint8_t _pad_14D0[0x188];           /* 0x14D0 */
    uint64_t field_1658;                /* 0x1658 */
    uint64_t field_1660;                /* 0x1660 */
    uint64_t field_1668;                /* 0x1668 */
    uint64_t field_1670;                /* 0x1670 */
    uint64_t field_1678;                /* 0x1678 */
    uint64_t field_1680_rw;             /* 0x1680 - rw, low confidence */
} ccUiAdvSummaryCheckCtrl;

static_assert(offsetof(ccUiAdvSummaryCheckCtrl, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_14B8) == 0x14B8, "field_14B8");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_14C0) == 0x14C0, "field_14C0");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_14C8) == 0x14C8, "field_14C8");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_1658) == 0x1658, "field_1658");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_1660) == 0x1660, "field_1660");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_1668) == 0x1668, "field_1668");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_1670) == 0x1670, "field_1670");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_1678) == 0x1678, "field_1678");
static_assert(offsetof(ccUiAdvSummaryCheckCtrl, field_1680_rw) == 0x1680, "field_1680_rw");

/* =========================================================================
 * ccUiAdvSummaryCheckMainBar
 * vtable: 0x140850798
 * Size: unknown, >= 0x90 (highest write at 0x8C, sz=4)
 * Methods: 11
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiAdvSummaryCheckMainBar {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x58];             /* 0x008 */
    uint64_t field_060_r;               /* 0x060 - read-only */
    uint64_t field_068;                 /* 0x068 */
    uint64_t field_070;                 /* 0x070 */
    uint8_t _pad_078[0x04];             /* 0x078 */
    uint64_t field_07C;                 /* 0x07C */
    uint64_t field_084;                 /* 0x084 */
    int32_t field_08C;                  /* 0x08C - initialized to 1 */
    uint8_t _pad_090[0x00];             /* end */
} ccUiAdvSummaryCheckMainBar;

static_assert(offsetof(ccUiAdvSummaryCheckMainBar, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiAdvSummaryCheckMainBar, field_060_r) == 0x060, "field_060_r");
static_assert(offsetof(ccUiAdvSummaryCheckMainBar, field_068) == 0x068, "field_068");
static_assert(offsetof(ccUiAdvSummaryCheckMainBar, field_070) == 0x070, "field_070");
static_assert(offsetof(ccUiAdvSummaryCheckMainBar, field_07C) == 0x07C, "field_07C");
static_assert(offsetof(ccUiAdvSummaryCheckMainBar, field_084) == 0x084, "field_084");
static_assert(offsetof(ccUiAdvSummaryCheckMainBar, field_08C) == 0x08C, "field_08C");

/* =========================================================================
 * ccUiAdvWorldMapMenu
 * vtable: 0x140850DB0
 * Inherits: ccUiTaskBase
 * Contains: nuccPostEffectDOF::ComputeCameraParam at +0xC8 (param_1+0x19)
 *           Nucc::Vector2 at +0x18C
 * Size: unknown, >= 0x194 (highest field at 0x18C, sz=8)
 * Methods: 23
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiAdvWorldMapMenu {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x58];             /* 0x008 - base class + memset(param_1+7,0,0x28) covers 0x38-0x5F */
    uint64_t field_060;                 /* 0x060 */
    uint64_t field_068;                 /* 0x068 */
    uint64_t field_070;                 /* 0x070 */
    uint64_t field_078;                 /* 0x078 */
    uint64_t field_080;                 /* 0x080 */
    uint64_t field_088;                 /* 0x088 */
    uint64_t field_090;                 /* 0x090 */
    uint64_t field_098;                 /* 0x098 */
    uint64_t field_0A0;                 /* 0x0A0 */
    uint64_t field_0A8;                 /* 0x0A8 */
    uint64_t field_0B0;                 /* 0x0B0 */
    uint64_t field_0B8;                 /* 0x0B8 */
    uint64_t field_0C0;                 /* 0x0C0 */
    uint64_t field_0C8_r;               /* 0x0C8 - read-only (camera param region) */
    uint8_t _pad_0D0[0x20];             /* 0x0D0 */
    uint64_t field_0F0;                 /* 0x0F0 */
    int32_t field_0F8;                  /* 0x0F8 */
    uint8_t _pad_0FC[0x80];             /* 0x0FC */
    uint64_t field_17C;                 /* 0x17C */
    int32_t field_184;                  /* 0x184 */
    int32_t field_188;                  /* 0x188 */
    uint64_t field_18C_rw;              /* 0x18C - rw (Nucc::Vector2) */
} ccUiAdvWorldMapMenu;

static_assert(offsetof(ccUiAdvWorldMapMenu, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_060) == 0x060, "field_060");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_068) == 0x068, "field_068");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_070) == 0x070, "field_070");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_078) == 0x078, "field_078");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_080) == 0x080, "field_080");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_088) == 0x088, "field_088");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_090) == 0x090, "field_090");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_098) == 0x098, "field_098");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0A0) == 0x0A0, "field_0A0");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0A8) == 0x0A8, "field_0A8");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0B0) == 0x0B0, "field_0B0");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0B8) == 0x0B8, "field_0B8");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0C0) == 0x0C0, "field_0C0");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0C8_r) == 0x0C8, "field_0C8_r");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0F0) == 0x0F0, "field_0F0");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_0F8) == 0x0F8, "field_0F8");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_17C) == 0x17C, "field_17C");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_184) == 0x184, "field_184");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_188) == 0x188, "field_188");
static_assert(offsetof(ccUiAdvWorldMapMenu, field_18C_rw) == 0x18C, "field_18C_rw");

/* =========================================================================
 * ccUiAdvSummaryCheck
 * vtable: 0x140850550
 * Inherits: ccUiTaskBase
 * Size: unknown, >= 0x58 (last field at param_1[10] = +0x50, sz=8)
 * Methods: 6
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiAdvSummaryCheck {
    void *vtable;                       /* 0x000 */
    uint8_t _pad_008[0x30];             /* 0x008 - base class */
    int32_t field_038;                  /* 0x038 - *(undefined4*)(param_1+7) = 0 */
    uint8_t _pad_03C[0x04];             /* 0x03C */
    uint64_t field_040;                 /* 0x040 - param_1[8] */
    uint64_t field_048;                 /* 0x048 - param_1[9] */
    uint64_t field_050;                 /* 0x050 - param_1[10] */
} ccUiAdvSummaryCheck;

static_assert(offsetof(ccUiAdvSummaryCheck, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiAdvSummaryCheck, field_038) == 0x038, "field_038");
static_assert(offsetof(ccUiAdvSummaryCheck, field_040) == 0x040, "field_040");
static_assert(offsetof(ccUiAdvSummaryCheck, field_048) == 0x048, "field_048");
static_assert(offsetof(ccUiAdvSummaryCheck, field_050) == 0x050, "field_050");

/* =========================================================================
 * ccUiAdvSummaryCheckWindow
 * vtable: 0x1408918E8
 * Minimal class — no ccUiTaskBase parent visible in ctor
 * Size: unknown, >= 0x28 (param_1[4] = +0x20, sz=8)
 * Methods: 6
 * ========================================================================= */
typedef struct __attribute__((packed)) ccUiAdvSummaryCheckWindow {
    void *vtable;                       /* 0x000 */
    uint64_t field_008;                 /* 0x008 - param_1[1] */
    uint64_t field_010;                 /* 0x010 - param_1[2] */
    uint64_t field_018;                 /* 0x018 - param_1[3] */
    uint64_t field_020;                 /* 0x020 - param_1[4] */
} ccUiAdvSummaryCheckWindow;

static_assert(offsetof(ccUiAdvSummaryCheckWindow, vtable) == 0x000, "vtable");
static_assert(offsetof(ccUiAdvSummaryCheckWindow, field_008) == 0x008, "field_008");
static_assert(offsetof(ccUiAdvSummaryCheckWindow, field_010) == 0x010, "field_010");
static_assert(offsetof(ccUiAdvSummaryCheckWindow, field_018) == 0x018, "field_018");
static_assert(offsetof(ccUiAdvSummaryCheckWindow, field_020) == 0x020, "field_020");

/* =========================================================================
 * Classes with < 3 methods or no state_surface fields — SKIPPED
 *
 * ccUiMissionBattleSelectPlate: 4 methods, 0 fields (no ctor in s2)
 * ccUiMissionWindow: 5 methods, 0 state_surface fields
 * uiAdvSummaryCheck: 1 method, 0 fields
 *
 * These are either thin wrappers, pure virtual bases, or have all state
 * in embedded sub-objects not visible to state_surface.
 * ========================================================================= */

#endif /* ST2A18_H */