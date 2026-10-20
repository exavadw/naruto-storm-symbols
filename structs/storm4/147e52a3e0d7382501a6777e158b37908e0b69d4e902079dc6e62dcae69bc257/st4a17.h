/*
 * st4a17.h — Story UI adventure structs for NARUTO STORM 4 PC 1.09 (s4)
 *
 * INFERRED from static decompilation only. Not CONFIRMED at runtime.
 * All offsets derived from NSUNS4_release.exe x64 (image base 0x140000000).
 * No cross-game names used; Storm 4 has no Trilogy namespace.
 *
 * Classes with >= 3 methods in s4: ccUiAdvRecoveryWindow (3), ccUiAdvStartMenuItemList (6)
 * Classes with < 3 methods (skipped for layout): ccUiAdvMissionOutline (1),
 *   ccUiAdvStartMenuQuestLog (2), ccUiAdvStartMenuTutorial (1), ccUiAdvSummary (1),
 *   ccUiAdvSummaryCheck (1), ccUiAdvSummaryCheckCtrl (2), ccUiAdvTeamOrganizeState (1),
 *   ccUiChallengeMissionBattleDetailWindow (1), ccUiFlashAdvSuddenBattleCondWindow (1),
 *   ccUiFlashAdvSuddenBattleResultWindow (1), ccUiTargetAdvCommon (1)
 */

#ifndef ST4A17_H
#define ST4A17_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccUiAdvRecoveryWindow
 *
 * Inherits ccUiTaskBase (base size unproven; first class-specific field at +0x68).
 * Size: unknown, >= 0xDA0 (last proven field strMotionCode ends at +0xDA0).
 * Vtable: not found in symbol table (no dtor symbol); set via base class ctor.
 * Evidence: Initialize@0x53F194, Initialize@0x53C084, SetPlayerData@0x53D490
 * ======================================================================== */
typedef struct __attribute__((packed)) ccUiAdvRecoveryWindow {
    /* 0x00 - 0x67: ccUiTaskBase base class (size unproven) */
    uint8_t base_ccUiTaskBase[0x68];

    /* 0x68: pointer to allocated sub-object (operator_new(0xD50) in Initialize@0x53F194) */
    uint64_t pSubObject;

    /* 0x70: std::map<std::string, ccCmnProperty> (find call in Initialize@0x53F194) */
    uint8_t mapProperties[0x18];

    /* 0x88: std::string (SSO size check at 0xF in Initialize@0x53F194) */
    uint8_t strUnk88[0x20];

    /* 0xA8: hash from Nucc::CalcHashFromStr (uint32, Initialize@0x53F194) */
    uint32_t hashCharId;

    /* 0xAC: padding */
    uint8_t pad_AC[0x10];

    /* 0xBC: copy of hashCharId (uint32, Initialize@0x53F194) */
    uint32_t hashCharIdCopy;

    /* 0xC0: pointer from map lookup result (Initialize@0x53F194) */
    uint64_t pMapResult;

    /* 0xC8 - 0x207: gap (no observed accesses) */
    uint8_t gap_C8[0x140];

    /* 0x208: pointer to ccGameObjSubDraw target (SetPlayerData@0x53D490) */
    uint64_t pGameObjSubDraw;

    /* 0x210 - 0xAFF: gap */
    uint8_t gap_210[0x8F0];

    /* 0xB00: charId (int, Initialize@0x53C084) */
    int32_t charId;

    /* 0xB04: costumeId (int, Initialize@0x53C084) */
    int32_t costumeId;

    /* 0xB08 - 0xCE7: gap */
    uint8_t gap_B08[0x1E0];

    /* 0xCE8: pointer to sub-object (operator_new(0x58) in Initialize@0x53C084) */
    uint64_t pEventCharaState;

    /* 0xCF0 - 0xD1F: gap */
    uint8_t gap_CF0[0x30];

    /* 0xD20: pointer to ccEventLipSyncState (operator_new(0x180) in Initialize@0x53F194) */
    uint64_t pLipSyncState;

    /* 0xD28 - 0xD47: gap */
    uint8_t gap_D28[0x20];

    /* 0xD48: std::string model code (grow_by_and_replace in Initialize@0x53F194) */
    uint8_t strModelCode[0x20];

    /* 0xD68 - 0xD7F: gap */
    uint8_t gap_D68[0x18];

    /* 0xD80: std::string motion code (grow_by_and_replace in Initialize@0x53F194) */
    uint8_t strMotionCode[0x20];

    /* End of proven fields at 0xDA0. Size unknown, >= 0xDA0 */
} ccUiAdvRecoveryWindow;

/* ccUiAdvRecoveryWindow offset assertions */
static_assert(offsetof(ccUiAdvRecoveryWindow, base_ccUiTaskBase) == 0x00, "base_ccUiTaskBase");
static_assert(offsetof(ccUiAdvRecoveryWindow, pSubObject) == 0x68, "pSubObject");
static_assert(offsetof(ccUiAdvRecoveryWindow, mapProperties) == 0x70, "mapProperties");
static_assert(offsetof(ccUiAdvRecoveryWindow, strUnk88) == 0x88, "strUnk88");
static_assert(offsetof(ccUiAdvRecoveryWindow, hashCharId) == 0xA8, "hashCharId");
static_assert(offsetof(ccUiAdvRecoveryWindow, hashCharIdCopy) == 0xBC, "hashCharIdCopy");
static_assert(offsetof(ccUiAdvRecoveryWindow, pMapResult) == 0xC0, "pMapResult");
static_assert(offsetof(ccUiAdvRecoveryWindow, pGameObjSubDraw) == 0x208, "pGameObjSubDraw");
static_assert(offsetof(ccUiAdvRecoveryWindow, charId) == 0xB00, "charId");
static_assert(offsetof(ccUiAdvRecoveryWindow, costumeId) == 0xB04, "costumeId");
static_assert(offsetof(ccUiAdvRecoveryWindow, pEventCharaState) == 0xCE8, "pEventCharaState");
static_assert(offsetof(ccUiAdvRecoveryWindow, pLipSyncState) == 0xD20, "pLipSyncState");
static_assert(offsetof(ccUiAdvRecoveryWindow, strModelCode) == 0xD48, "strModelCode");
static_assert(offsetof(ccUiAdvRecoveryWindow, strMotionCode) == 0xD80, "strMotionCode");

/* ========================================================================
 * ccUiAdvStartMenuItemList
 *
 * Inherits ccUiTaskBase. Vtable: 0x14106b5c8 (dtor@0x5F04D0).
 * Size: unknown, >= 0x68 (last proven field vecItems_end ends at +0x68).
 * Evidence: dtor@0x5F04D0, Finalize@0x5F0708, ChangeOnItemUsed@0x6B293C
 *
 * Note: ChangeOnItemUsed accesses param_1[0xb] (=+0x58) and param_1[0xc] (=+0x60)
 * as begin/end pointers of a std::vector<ItemInfo> with stride 0x7C.
 * Symbol table confirms: std::vector<ccUiAdvStartMenuItemList::ItemInfo,...>
 * ======================================================================== */
typedef struct __attribute__((packed)) ccUiAdvStartMenuItemList {
    /* 0x00: vtable pointer (0x14106b5c8) */
    uint64_t vtable;

    /* 0x08 - 0x37: ccUiTaskBase remainder */
    uint8_t base_ccUiTaskBase_rest[0x30];

    /* 0x38: pointer (freed via vtable call in Finalize@0x5F0708) */
    uint64_t pUnk38;

    /* 0x40: pointer (freed via vtable call in Finalize@0x5F0708) */
    uint64_t pUnk40;

    /* 0x48: pointer (freed via vtable call in Finalize@0x5F0708) */
    uint64_t pUnk48;

    /* 0x50: pointer (freed via vtable call in Finalize@0x5F0708) */
    uint64_t pUnk50;

    /* 0x58: vector<ItemInfo> begin pointer (ChangeOnItemUsed@0x6B293C: param_1[0xb]) */
    uint64_t vecItems_begin;

    /* 0x60: vector<ItemInfo> end pointer (ChangeOnItemUsed@0x6B293C: param_1[0xc]) */
    uint64_t vecItems_end;

    /* End of proven fields at 0x68. Size unknown, >= 0x68 */
} ccUiAdvStartMenuItemList;

/* ccUiAdvStartMenuItemList offset assertions */
static_assert(offsetof(ccUiAdvStartMenuItemList, vtable) == 0x00, "vtable");
static_assert(offsetof(ccUiAdvStartMenuItemList, pUnk38) == 0x38, "pUnk38");
static_assert(offsetof(ccUiAdvStartMenuItemList, pUnk40) == 0x40, "pUnk40");
static_assert(offsetof(ccUiAdvStartMenuItemList, pUnk48) == 0x48, "pUnk48");
static_assert(offsetof(ccUiAdvStartMenuItemList, pUnk50) == 0x50, "pUnk50");
static_assert(offsetof(ccUiAdvStartMenuItemList, vecItems_begin) == 0x58, "vecItems_begin");
static_assert(offsetof(ccUiAdvStartMenuItemList, vecItems_end) == 0x60, "vecItems_end");

#endif /* ST4A17_H */