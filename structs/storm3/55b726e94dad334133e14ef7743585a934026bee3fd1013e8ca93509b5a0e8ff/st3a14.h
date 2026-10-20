/*
 * st3a14.h — Story progression structs for NSUNS3.exe (s3, PC x64)
 *
 * All offsets derived from NSUNS3.exe (build s3, image base 0x140000000).
 * All field names are own-game (Storm 3) only.
 * Static analysis only — INFERRED, not CONFIRMED.
 *
 * Classes with no proven instance state are documented as comments.
 */

#ifndef ST3A14_H
#define ST3A14_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccAdvWindowManager
 * Size: 0x78 (proven by allocator call FUN_140683f70(0x78, ...) at RVA 0x480D10)
 * Vtable: set at offset 0x50 (PTR_LAB_1409ef0f0 in ctor at RVA 0x787D40)
 * Evidence: ctor RVA 0x787D40, caller RVA 0x480D10
 */
typedef struct __attribute__((packed)) ccAdvWindowManager {
    uint32_t field_0x00;          /* 0x00: *(param_1) = 0 in ctor */
    uint32_t field_0x04;          /* 0x04: param_1[1] = 0xffffffff in ctor */
    uint64_t field_0x08;          /* 0x08: *(undefined8*)(param_1+2) = 0 */
    uint32_t field_0x10;          /* 0x10: param_1[4] = 0 */
    uint8_t  pad_0x14[4];         /* 0x14: padding to align 0x18 */
    uint64_t field_0x18;          /* 0x18: *(undefined8*)(param_1+6) */
    uint64_t field_0x20;          /* 0x20: *(undefined8*)(param_1+8) */
    uint64_t field_0x28;          /* 0x28: *(undefined8*)(param_1+10) */
    void    *field_0x30;          /* 0x30: ptr set via FUN_140684bc0, then overwritten with PTR_FUN_1409ec308 */
    uint8_t  pad_0x38[16];        /* 0x38: gap to 0x48 */
    uint32_t field_0x48;          /* 0x48: param_1[0x12] = 0; read as *(uint*)(obj+0x48) in caller 0x480D10 */
    uint8_t  pad_0x4C[4];         /* 0x4C: padding to align 0x50 */
    void    *vtable_0x50;         /* 0x50: *(undefined***)(param_1+0x14) = &PTR_LAB_1409ef0f0 */
    uint8_t  pad_0x58[8];         /* 0x58: includes *(undefined1*)(param_1+0x16)=0 at byte 0x58; rest unknown */
    uint64_t field_0x60;          /* 0x60: *(undefined8*)(param_1+0x18) = 0 */
    uint64_t field_0x68;          /* 0x68: *(undefined8*)(param_1+0x1a) = 0 */
    uint64_t field_0x70;          /* 0x70: *(undefined8*)(param_1+0x1c) = 0 */
} ccAdvWindowManager;
/* Total: 0x78 bytes, matches allocation size */

static_assert(offsetof(ccAdvWindowManager, field_0x00) == 0x00, "ccAdvWindowManager.field_0x00");
static_assert(offsetof(ccAdvWindowManager, field_0x04) == 0x04, "ccAdvWindowManager.field_0x04");
static_assert(offsetof(ccAdvWindowManager, field_0x08) == 0x08, "ccAdvWindowManager.field_0x08");
static_assert(offsetof(ccAdvWindowManager, field_0x10) == 0x10, "ccAdvWindowManager.field_0x10");
static_assert(offsetof(ccAdvWindowManager, field_0x18) == 0x18, "ccAdvWindowManager.field_0x18");
static_assert(offsetof(ccAdvWindowManager, field_0x20) == 0x20, "ccAdvWindowManager.field_0x20");
static_assert(offsetof(ccAdvWindowManager, field_0x28) == 0x28, "ccAdvWindowManager.field_0x28");
static_assert(offsetof(ccAdvWindowManager, field_0x30) == 0x30, "ccAdvWindowManager.field_0x30");
static_assert(offsetof(ccAdvWindowManager, field_0x48) == 0x48, "ccAdvWindowManager.field_0x48");
static_assert(offsetof(ccAdvWindowManager, vtable_0x50) == 0x50, "ccAdvWindowManager.vtable_0x50");
static_assert(offsetof(ccAdvWindowManager, field_0x60) == 0x60, "ccAdvWindowManager.field_0x60");
static_assert(offsetof(ccAdvWindowManager, field_0x68) == 0x68, "ccAdvWindowManager.field_0x68");
static_assert(offsetof(ccAdvWindowManager, field_0x70) == 0x70, "ccAdvWindowManager.field_0x70");
static_assert(sizeof(ccAdvWindowManager) == 0x78, "ccAdvWindowManager size == 0x78");

/*
 * ccAdvWindowManager::Dialog
 * No instance state proven: all 5 seed methods (Exec, SetItemGetMessage,
 * SetMessage, SetMessageId, SetEnableCancelButton) produced "unknown param_1
 * element size; only byte-cast accesses used" — surface found 0 fields.
 * Methods exist (decomp cached) but no field offsets could be derived.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccAdvWindowManager::Select
 * No instance state proven: all 10 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccChallengeMissionSaveData
 * No instance state proven: all 8 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccDebugSceneAdventure
 * No instance state proven: all 4 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccMissionInfoManager
 * No instance state proven: all 3 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccMissionObjectiveParamManager
 * Only 1 method found (Create at RVA 0x1AEFA0). Below threshold of >= 3 methods.
 * Skipped per task rules.
 */
/* skipped: < 3 methods in this build */

/*
 * ccMissionParamManager
 * Only 2 methods found (Create at RVA 0x1B05A8, GetRewardItem at RVA 0x1B0778).
 * Below threshold of >= 3 methods. Skipped per task rules.
 */
/* skipped: < 3 methods in this build */

/*
 * ccSceneAdvBattleMap
 * No instance state proven: all 19 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccSceneAdvBattleRoot
 * No instance state proven: all 5 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccSceneAdvBtlMemberSelect
 * Only 2 methods found (Execute at RVA 0x1C03E0, dtor at RVA 0x26B560).
 * Below threshold of >= 3 methods. Skipped per task rules.
 */
/* skipped: < 3 methods in this build */

/*
 * ccSceneAdvDecision
 * No instance state proven: all 7 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

/*
 * ccSceneAdvFellowList
 * Only 1 method found (Initialize at RVA 0x2027A0). Below threshold.
 * Skipped per task rules.
 */
/* skipped: < 3 methods in this build */

/*
 * ccSceneAdvMiddleMap
 * No instance state proven: all 4 seed methods produced "unknown param_1
 * element size" warnings — surface found 0 fields.
 */
/* no instance state — see st3a14-REPORT.md for evidence */

#endif /* ST3A14_H */