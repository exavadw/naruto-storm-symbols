/* cmn08.h — NARUTO STORM 1 (s1 / NSUNS1.exe) struct group cmn08
 * INFERRED layouts from static decompilation. Not CONFIRMED by runtime trace.
 * All offsets derived from s1 x64 decompile (image base 0x140000000).
 * Sizes proven only where operator-new / allocator argument is visible.
 */
#ifndef CMN08_H
#define CMN08_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not reconstructed here */
typedef struct Nucc_Memory_BlockAllocator Nucc_Memory_BlockAllocator;
typedef struct ccFileLoadListForUi ccFileLoadListForUi;

/* =========================================================================
 * Nucc::Memory::BlockAllocator  (base class, layout from ccTask/ctor pattern)
 * Offset 0x00: vtable ptr (8 bytes)
 * This is a common base; we model only the vtable slot.
 * ========================================================================= */
typedef struct __attribute__((packed)) Nucc_Memory_BlockAllocator {
    uint64_t vtable;           /* 0x00 */
} Nucc_Memory_BlockAllocator;

static_assert(offsetof(Nucc_Memory_BlockAllocator, vtable) == 0x00,
              "Nucc_Memory_BlockAllocator.vtable");

/* =========================================================================
 * ccTask  (inherits Nucc::Memory::BlockAllocator)
 * Proven size: none (no operator-new literal found).
 * Last accessed field: +0x1C → size unknown, >= 0x20.
 * Vtable: 0x1407455a8 (from ctor).
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTask {
    uint64_t vtable;           /* 0x00  set to &PTR_FUN_1407455a8 in ctor */
    uint8_t  _pad_08[0x10];    /* 0x08  BlockAllocator subobject / padding */
    int32_t  task_type;        /* 0x18  param_3 stored as int */
    int32_t  refcount;         /* 0x1C  *(uint*)(param_1+0x1c)=param_4; also read in Execute */
    int32_t  flags;            /* 0x20  *(undefined4*)(param_1+4)=1 → offset 0x20 */
    uint8_t  _pad_24[0x0C];    /* 0x24  gap to next known access */
    uint64_t exec_func_ptr;    /* 0x30  inferred: (**(code**)(*param_1+0x18))() → vfunc at slot 3 */
} ccTask;

static_assert(offsetof(ccTask, vtable)       == 0x00, "ccTask.vtable");
static_assert(offsetof(ccTask, task_type)     == 0x18, "ccTask.task_type");
static_assert(offsetof(ccTask, refcount)     == 0x1C, "ccTask.refcount");
static_assert(offsetof(ccTask, flags)        == 0x20, "ccTask.flags");
static_assert(offsetof(ccTask, exec_func_ptr)== 0x30, "ccTask.exec_func_ptr");

/* =========================================================================
 * ccTaskBase  (inherits Nucc::Memory::BlockAllocator)
 * Contains an embedded std::list<ccTask*> at param_1+3 (= byte offset 0x18).
 * Proven size: none.  Last accessed field: +0x18 (list head) → >= 0x28.
 * Vtable: 0x140745618 (from ctor).
 * Vtable slots observed: +0x08 (dtor-like), +0x10 (dispatch in EntryTask/Finalize).
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTaskBase {
    uint64_t vtable;           /* 0x00  set to &PTR_FUN_140745618 */
    uint8_t  _pad_08[0x10];    /* 0x08  BlockAllocator subobject */
    uint64_t task_list_head;   /* 0x18  std::list node ptr (param_1+3) */
    uint64_t task_list_size;   /* 0x20  param_1[4] — list length sentinel */
} ccTaskBase;

static_assert(offsetof(ccTaskBase, vtable)          == 0x00, "ccTaskBase.vtable");
static_assert(offsetof(ccTaskBase, task_list_head)  == 0x18, "ccTaskBase.task_list_head");
static_assert(offsetof(ccTaskBase, task_list_size)  == 0x20, "ccTaskBase.task_list_size");

/* =========================================================================
 * ccTaskBase::ccTaskList  (nested type — only ReleaseAllTask symbol exists)
 * Likely identical to the embedded list region inside ccTaskBase.
 * No independent fields surfaced; listed in report as gap.
 * ========================================================================= */

/* =========================================================================
 * ccTaskCertainExe  (inherits ccTask per ccTaskBase::EntryTask calling pattern)
 * Only constructor symbols exist (template instantiations).
 * No additional fields beyond ccTask surfaced.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTaskCertainExe {
    ccTask base;               /* 0x00  inherits ccTask layout */
} ccTaskCertainExe;

static_assert(offsetof(ccTaskCertainExe, base) == 0x00, "ccTaskCertainExe.base");

/* =========================================================================
 * ccStateStaffRoll  (inherits ccTaskBase)
 * Proven size: 0xB0 (ccFileLoadListForUi::LoadTh(0xb0,...) in factory).
 * Vtable overridden to 0x14065a750 in ctor.
 * Embedded ccFileLoadListForUi at param_1+0xf (= byte 0x78).
 * ========================================================================= */
typedef struct __attribute__((packed)) ccStateStaffRoll {
    uint64_t vtable;           /* 0x00  overridden to &PTR_FUN_14065a750 */
    uint8_t  _pad_08[0x10];    /* 0x08  ccTaskBase / BlockAllocator subobject */
    uint64_t task_list_head;   /* 0x18  inherited list head */
    uint64_t task_list_size;   /* 0x20  inherited list size */
    uint8_t  _pad_28[0x24];    /* 0x28  gap (ccTaskBase tail → first own field) */
    int32_t  state_id;         /* 0x4C  *(param_1+10)=0xffffffff → offset 0x4C (was -1) */
    int32_t  field_50;         /* 0x50  *(param_1+0xa)=0 → offset 0x50 */
    int32_t  update_flag;      /* 0x54  written 0 then 1 in factory */
    int32_t  field_58;         /* 0x58  *(param_1+0xb)=0 */
    int32_t  field_5C;         /* 0x5C  *(param_1+0x5c)=0 */
    int32_t  draw_enable;      /* 0x60  *(param_1+0xc)=1; factory sets =1 */
    uint8_t  _pad_64[0x0C];    /* 0x64  gap */
    uint64_t state_name_ptr;   /* 0x70  param_1[0xe]=&PTR_s_STATE_NONE */
    uint8_t  file_load_list[0x30]; /* 0x78  ccFileLoadListForUi(param_1+0xf); size=0x30 inferred from 0xB0-0x78-0x08 */
    int32_t  field_A8;         /* 0xA8  *(param_1+0x15)=0 */
    uint8_t  _pad_AC[0x04];    /* 0xAC  trailing pad to reach 0xB0 */
} ccStateStaffRoll;

static_assert(offsetof(ccStateStaffRoll, vtable)         == 0x00, "ccStateStaffRoll.vtable");
static_assert(offsetof(ccStateStaffRoll, task_list_head) == 0x18, "ccStateStaffRoll.task_list_head");
static_assert(offsetof(ccStateStaffRoll, task_list_size) == 0x20, "ccStateStaffRoll.task_list_size");
static_assert(offsetof(ccStateStaffRoll, state_id)       == 0x4C, "ccStateStaffRoll.state_id");
static_assert(offsetof(ccStateStaffRoll, field_50)       == 0x50, "ccStateStaffRoll.field_50");
static_assert(offsetof(ccStateStaffRoll, update_flag)    == 0x54, "ccStateStaffRoll.update_flag");
static_assert(offsetof(ccStateStaffRoll, field_58)       == 0x58, "ccStateStaffRoll.field_58");
static_assert(offsetof(ccStateStaffRoll, field_5C)       == 0x5C, "ccStateStaffRoll.field_5C");
static_assert(offsetof(ccStateStaffRoll, draw_enable)    == 0x60, "ccStateStaffRoll.draw_enable");
static_assert(offsetof(ccStateStaffRoll, state_name_ptr) == 0x70, "ccStateStaffRoll.state_name_ptr");
static_assert(offsetof(ccStateStaffRoll, file_load_list) == 0x78, "ccStateStaffRoll.file_load_list");
static_assert(offsetof(ccStateStaffRoll, field_A8)       == 0xA8, "ccStateStaffRoll.field_A8");
static_assert(sizeof(ccStateStaffRoll) == 0xB0, "ccStateStaffRoll size proven by LoadTh(0xb0)");

/* =========================================================================
 * ccSystemPartyPlayHosting  (inherits ccTaskBase)
 * No own fields beyond base surfaced from state_surface (0 fields).
 * Ctor writes *(param_1+8)=0 → offset 0x40 (int), then overrides vtable.
 * Proven size: none.  Minimum extent: ccTaskBase + 0x44 write → >= 0x44.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSystemPartyPlayHosting {
    uint64_t vtable;           /* 0x00  overridden to &PTR_FUN_1406c7ec0 */
    uint8_t  _pad_08[0x10];    /* 0x08  ccTaskBase / BlockAllocator subobject */
    uint64_t task_list_head;   /* 0x18  inherited */
    uint64_t task_list_size;   /* 0x20  inherited */
    uint8_t  _pad_28[0x18];    /* 0x28  gap */
    int32_t  field_40;         /* 0x40  *(param_1+8)=0 in ctor */
    uint8_t  _pad_44[0x04];    /* 0x44  alignment pad */
} ccSystemPartyPlayHosting;

static_assert(offsetof(ccSystemPartyPlayHosting, vtable)         == 0x00, "ccSystemPartyPlayHosting.vtable");
static_assert(offsetof(ccSystemPartyPlayHosting, task_list_head) == 0x18, "ccSystemPartyPlayHosting.task_list_head");
static_assert(offsetof(ccSystemPartyPlayHosting, task_list_size) == 0x20, "ccSystemPartyPlayHosting.task_list_size");
static_assert(offsetof(ccSystemPartyPlayHosting, field_40)       == 0x40, "ccSystemPartyPlayHosting.field_40");

/* =========================================================================
 * ccStageCollisionBase  (inherits Nucc::Memory::BlockAllocator)
 * Vtable: 0x140749e10 (from ctor).
 * Fields: +0x48 (int=1), +0x4C (qword=0), +0x50 (int=1).
 * state_surface accesses at +0xC0 and +0x180 are vfunc dispatches, not data.
 * Proven size: none.  Last data field +0x50 → size unknown, >= 0x54.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccStageCollisionBase {
    uint64_t vtable;           /* 0x00  &PTR_FUN_140749e10 */
    uint8_t  _pad_08[0x10];    /* 0x08  BlockAllocator subobject */
    uint8_t  _pad_18[0x30];    /* 0x18  gap to first own field */
    int32_t  field_48;         /* 0x48  *(param_1+8)=1 → offset 0x48 */
    uint32_t _pad_4C;          /* 0x4C  param_1[9]=0 → qword at 0x4C, low 4 bytes */
    uint32_t field_50_hi;      /* 0x50  high dword of param_1[9]=0 */
    int32_t  field_54;         /* 0x54  *(param_1+10)=1 → offset 0x54 */
    uint8_t  _pad_58[0x08];    /* 0x58  trailing pad */
} ccStageCollisionBase;

static_assert(offsetof(ccStageCollisionBase, vtable)    == 0x00, "ccStageCollisionBase.vtable");
static_assert(offsetof(ccStageCollisionBase, field_48)  == 0x48, "ccStageCollisionBase.field_48");
static_assert(offsetof(ccStageCollisionBase, field_54)  == 0x54, "ccStageCollisionBase.field_54");

/* =========================================================================
 * ccTrophyManager  (inherits Nucc::Memory::BlockAllocator presumed)
 * Vtable dispatch at +0x08 and +0x10 seen in Finalize.
 * Enable() is a static/global function (no param_1) — not an instance method.
 * Unlock/Reset/Finalize share the same vtable-dispatch pattern.
 * Proven size: none.  Vtable implies at least 0x18.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTrophyManager {
    uint64_t vtable;           /* 0x00 */
    uint8_t  _pad_08[0x10];    /* 0x08  gap (vtable slots at +0x08,+0x10 are code ptrs) */
} ccTrophyManager;

static_assert(offsetof(ccTrophyManager, vtable) == 0x00, "ccTrophyManager.vtable");

/* =========================================================================
 * ccTrophyManager::Impl  (only UnlockThreadStart symbol, no fields surfaced)
 * Listed in report as gap — insufficient evidence for layout.
 * ========================================================================= */

/* =========================================================================
 * Classes with < 3 methods (listed in report, no struct emitted):
 *   ccStageBaseClump      — 1 method  (SetSubstitutionKey)
 *   ccSystemDialog        — 1 method  (Ctrl)
 *   ccTouchStick          — 1 method  (SetAlpha)
 *   ccTaskBase::ccTaskList — 1 method (ReleaseAllTask)
 *   ccTrophyManager::Impl — 1 method  (UnlockThreadStart)
 * ========================================================================= */

#endif /* CMN08_H */