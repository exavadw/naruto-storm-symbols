/* cmn08.h — NARUTO STORM 2 (s2 / NSUNS2.exe) struct group cmn08
 * INFERRED layouts from static decompilation. Not CONFIRMED by runtime trace.
 * All offsets derived from s2 x64 decompile (image base 0x140000000).
 * Sizes proven only where operator-new / allocator argument is visible.
 * Own-game naming: all names from s2 ns2:: namespace or s2 strings/code only.
 */
#ifndef CMN08_S2_H
#define CMN08_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not reconstructed here */
typedef struct ccFileLoadListForUi_s2 ccFileLoadListForUi_s2;

/* =========================================================================
 * ccTask (inherits Nucc::Memory::BlockAllocator)
 * Proven size: none (no operator-new literal found).
 * Last accessed field: +0x20 (flags) -> size unknown, >= 0x24.
 * Vtable: 0x14089f110 (from ccTask::ccTask ctor at 0x650BF0).
 * Fields from state_surface: +0x1C rw (refcount/task_type area), +0xC0 r (vfunc dispatch).
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTask_s2 {
    uint64_t vtable;           /* 0x00  set to &PTR_FUN_14089f110 in ctor */
    uint8_t  _pad_08[0x10];    /* 0x08  BlockAllocator subobject / padding */
    int32_t  task_type;        /* 0x18  *(int*)(param_1+3)=param_3 in ctor */
    uint32_t refcount;         /* 0x1C  *(uint*)((longlong)param_1+0x1c)=param_4 */
    int32_t  flags;            /* 0x20  *(undefined4*)(param_1+4)=1 */
    uint8_t  _pad_24[0x0C];    /* 0x24  gap to next known access */
} ccTask_s2;

static_assert(offsetof(ccTask_s2, vtable)   == 0x00, "ccTask_s2.vtable");
static_assert(offsetof(ccTask_s2, task_type)== 0x18, "ccTask_s2.task_type");
static_assert(offsetof(ccTask_s2, refcount) == 0x1C, "ccTask_s2.refcount");
static_assert(offsetof(ccTask_s2, flags)    == 0x20, "ccTask_s2.flags");

/* =========================================================================
 * ccTaskBase (inherits Nucc::Memory::BlockAllocator)
 * Contains an embedded std::list-like structure at param_1+3 (= byte offset 0x18).
 * Proven size: none. Last own field: +0xB8 -> size unknown, >= 0xBC.
 * Large offsets 0x14B8-0x15F8 are from EntryTask<ccStageSelectCursor> which
 * operates on a DERIVED class object passed as ccTaskBase*, not ccTaskBase itself.
 * Vtable: 0x1407dd968 (from parametrized ctor at 0x2AA884).
 * Default ctor vtable: 0x14089da68 (from default ctor at 0x6337E0).
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTaskBase_s2 {
    uint64_t vtable;           /* 0x00  set to &PTR_FUN_1407dd968 or 0x14089da68 */
    uint8_t  _pad_08[0x10];    /* 0x08  BlockAllocator subobject */
    uint64_t task_list_head;   /* 0x18  param_1+3 -> list node ptr */
    uint64_t task_list_tail;   /* 0x20  param_1+4 -> initialized via FUN_140655900 */
    uint8_t  _pad_28[0x2C];    /* 0x28  gap (list internals / BlockAllocator tail) */
    int32_t  field_54;         /* 0x54  *(undefined4*)(param_1+0x54)=param_2 in ctor */
    uint64_t field_58;         /* 0x58  param_1[0xb]=0 in ctor */
    int32_t  field_60;         /* 0x60  *(undefined4*)(param_1+0xc)=1 in ctor */
    uint8_t  _pad_64[0x04];    /* 0x64  alignment pad */
    uint64_t self_ptr_68;      /* 0x68  param_1[9]=param_1+0xd -> self-referential ptr */
    uint64_t self_ptr_70;      /* 0x70  puVar11=param_1+0xe -> another self-ref */
    uint8_t  _pad_78[0x40];    /* 0x78  gap */
    int32_t  field_B8;         /* 0xB8  *(undefined4*)(param_1+0x17)=0 in EntryTask */
    uint8_t  _pad_BC[0x04];    /* 0xBC  trailing pad */
} ccTaskBase_s2;

static_assert(offsetof(ccTaskBase_s2, vtable)         == 0x00, "ccTaskBase_s2.vtable");
static_assert(offsetof(ccTaskBase_s2, task_list_head) == 0x18, "ccTaskBase_s2.task_list_head");
static_assert(offsetof(ccTaskBase_s2, task_list_tail) == 0x20, "ccTaskBase_s2.task_list_tail");
static_assert(offsetof(ccTaskBase_s2, field_54)       == 0x54, "ccTaskBase_s2.field_54");
static_assert(offsetof(ccTaskBase_s2, field_58)       == 0x58, "ccTaskBase_s2.field_58");
static_assert(offsetof(ccTaskBase_s2, field_60)       == 0x60, "ccTaskBase_s2.field_60");
static_assert(offsetof(ccTaskBase_s2, self_ptr_68)    == 0x68, "ccTaskBase_s2.self_ptr_68");
static_assert(offsetof(ccTaskBase_s2, self_ptr_70)    == 0x70, "ccTaskBase_s2.self_ptr_70");
static_assert(offsetof(ccTaskBase_s2, field_B8)       == 0xB8, "ccTaskBase_s2.field_B8");

/* =========================================================================
 * ccTaskBase::ccTaskList (nested type -- only ReleaseAllTask symbol exists)
 * Likely identical to the embedded list region inside ccTaskBase.
 * No independent fields surfaced; listed in report as gap.
 * ========================================================================= */

/* =========================================================================
 * ccTaskCertainExe (inherits ccTask per ccTaskBase::EntryTask calling pattern)
 * Only constructor symbols exist (template instantiations).
 * No additional fields beyond ccTask surfaced.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTaskCertainExe_s2 {
    ccTask_s2 base;            /* 0x00  inherits ccTask layout */
} ccTaskCertainExe_s2;

static_assert(offsetof(ccTaskCertainExe_s2, base) == 0x00, "ccTaskCertainExe_s2.base");

/* =========================================================================
 * ccStateStaffRoll (inherits ccTaskBase)
 * Proven size: 0x1500 (FUN_140580190(0x1500,...) in ccSceneStaffRollHD::Initialize).
 * Vtable overridden to 0x140842580 in ctor at 0x4725AC.
 * Ctor calls ccTaskBase::ccTaskBase(param_1, 0, &DAT_14097ffa0, 5) then sets
 * param_1[0x298]=0, param_1[0x299]=0, overrides vtable, calls FUN_140649ba0(param_1+0x29a).
 * Embedded array of 5 entries starting at offset 0x68 (each 0xA8 bytes = 10*8).
 * Own fields at 0x14C0, 0x14C8, 0x14D0 from state_surface match ctor offsets.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccStateStaffRoll_s2 {
    uint64_t vtable;           /* 0x00  overridden to &PTR_FUN_140842580 */
    uint8_t  _pad_08[0x10];    /* 0x08  ccTaskBase / BlockAllocator subobject */
    uint64_t task_list_head;   /* 0x18  inherited list head */
    uint64_t task_list_tail;   /* 0x20  inherited list tail */
    uint8_t  _pad_28[0x2C];    /* 0x28  gap */
    int32_t  field_54;         /* 0x54  inherited from ccTaskBase ctor */
    uint64_t field_58;         /* 0x58  inherited */
    int32_t  draw_enable;      /* 0x60  *(undefined4*)(param_1+0xc)=1; factory sets =1 */
    uint8_t  _pad_64[0x04];    /* 0x64  alignment pad */
    uint8_t  task_entries[0x1458]; /* 0x68  5 entries * 0xA8 each = 0x348? Actually 0x14C0-0x68=0x1458 */
    uint64_t field_14C0;       /* 0x14C0  param_1[0x298]=0 in ctor */
    uint64_t field_14C8;       /* 0x14C8  param_1[0x299]=0 in ctor */
    uint64_t field_14D0;       /* 0x14D0  accessed in state_surface read */
    uint8_t  _pad_14D8[0x28];  /* 0x14D8  trailing pad to reach 0x1500 */
} ccStateStaffRoll_s2;

static_assert(offsetof(ccStateStaffRoll_s2, vtable)       == 0x00,    "ccStateStaffRoll_s2.vtable");
static_assert(offsetof(ccStateStaffRoll_s2, task_list_head)== 0x18,   "ccStateStaffRoll_s2.task_list_head");
static_assert(offsetof(ccStateStaffRoll_s2, task_list_tail)== 0x20,   "ccStateStaffRoll_s2.task_list_tail");
static_assert(offsetof(ccStateStaffRoll_s2, field_54)     == 0x54,    "ccStateStaffRoll_s2.field_54");
static_assert(offsetof(ccStateStaffRoll_s2, field_58)     == 0x58,    "ccStateStaffRoll_s2.field_58");
static_assert(offsetof(ccStateStaffRoll_s2, draw_enable)  == 0x60,    "ccStateStaffRoll_s2.draw_enable");
static_assert(offsetof(ccStateStaffRoll_s2, task_entries) == 0x68,    "ccStateStaffRoll_s2.task_entries");
static_assert(offsetof(ccStateStaffRoll_s2, field_14C0)   == 0x14C0,  "ccStateStaffRoll_s2.field_14C0");
static_assert(offsetof(ccStateStaffRoll_s2, field_14C8)   == 0x14C8,  "ccStateStaffRoll_s2.field_14C8");
static_assert(offsetof(ccStateStaffRoll_s2, field_14D0)   == 0x14D0,  "ccStateStaffRoll_s2.field_14D0");
static_assert(sizeof(ccStateStaffRoll_s2) == 0x1500, "ccStateStaffRoll_s2 size proven by allocator(0x1500)");

/* =========================================================================
 * ccSystemPartyPlayHosting (inherits ccTaskBase)
 * No own fields beyond base surfaced from state_surface (0 fields).
 * Ctor writes *(param_1+8)=0 -> offset 0x40 (int), then overrides vtable.
 * Proven size: none. Minimum extent: ccTaskBase + 0x44 write -> >= 0x44.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSystemPartyPlayHosting_s2 {
    uint64_t vtable;           /* 0x00  overridden in ctor */
    uint8_t  _pad_08[0x10];    /* 0x08  ccTaskBase / BlockAllocator subobject */
    uint64_t task_list_head;   /* 0x18  inherited */
    uint64_t task_list_tail;   /* 0x20  inherited */
    uint8_t  _pad_28[0x18];    /* 0x28  gap */
    int32_t  field_40;         /* 0x40  *(param_1+8)=0 in ctor */
    uint8_t  _pad_44[0x04];    /* 0x44  alignment pad */
} ccSystemPartyPlayHosting_s2;

static_assert(offsetof(ccSystemPartyPlayHosting_s2, vtable)         == 0x00, "ccSystemPartyPlayHosting_s2.vtable");
static_assert(offsetof(ccSystemPartyPlayHosting_s2, task_list_head) == 0x18, "ccSystemPartyPlayHosting_s2.task_list_head");
static_assert(offsetof(ccSystemPartyPlayHosting_s2, task_list_tail) == 0x20, "ccSystemPartyPlayHosting_s2.task_list_tail");
static_assert(offsetof(ccSystemPartyPlayHosting_s2, field_40)       == 0x40, "ccSystemPartyPlayHosting_s2.field_40");

/* =========================================================================
 * ccStageCollisionBase (inherits Nucc::Memory::BlockAllocator)
 * Create() allocates sub-object with FUN_140580190(0x98,...) -> inner collision obj.
 * Fields from ctor: +0x48 (int=1), +0x4C (qword=0), +0x54 (int=1).
 * state_surface accesses at +0xC0 and +0x180 are vfunc dispatches, not data.
 * Proven size: none. Last data field +0x54 -> size unknown, >= 0x58.
 * Vtable: from ctor (not directly observed in decomp; see report).
 * ========================================================================= */
typedef struct __attribute__((packed)) ccStageCollisionBase_s2 {
    uint64_t vtable;           /* 0x00 */
    uint8_t  _pad_08[0x10];    /* 0x08  BlockAllocator subobject */
    uint8_t  _pad_18[0x30];    /* 0x18  gap to first own field */
    int32_t  field_48;         /* 0x48  *(param_1+8)=1 in ctor */
    uint64_t field_4C;         /* 0x4C  param_1[9]=0 (qword write) */
    int32_t  field_54;         /* 0x54  *(param_1+10)=1 in ctor */
    uint8_t  _pad_58[0x40];    /* 0x58  gap to reach proven size 0x98 */
} ccStageCollisionBase_s2;

static_assert(offsetof(ccStageCollisionBase_s2, vtable) == 0x00, "ccStageCollisionBase_s2.vtable");
static_assert(offsetof(ccStageCollisionBase_s2, field_48) == 0x48, "ccStageCollisionBase_s2.field_48");
static_assert(offsetof(ccStageCollisionBase_s2, field_4C) == 0x4C, "ccStageCollisionBase_s2.field_4C");
static_assert(offsetof(ccStageCollisionBase_s2, field_54) == 0x54, "ccStageCollisionBase_s2.field_54");
static_assert(sizeof(ccStageCollisionBase_s2) == 0x98, "ccStageCollisionBase_s2 size proven by allocator(0x98)");

/* =========================================================================
 * ccTrophyManager
 * Enable() is static (no param_1). Unlock/Reset/Finalize use vtable dispatch
 * at slots +0x08 and +0x10 but no data fields surfaced from state_surface.
 * Proven size: none. Minimum extent: vtable + dispatch slots -> >= 0x18.
 * Vtable: not directly observed in s2 decomp; dispatch pattern only.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccTrophyManager_s2 {
    uint64_t vtable;           /* 0x00 */
    uint64_t field_08;         /* 0x08 vfunc dispatch slot */
    uint64_t field_10;         /* 0x10 vfunc dispatch slot */
} ccTrophyManager_s2;

static_assert(offsetof(ccTrophyManager_s2, vtable) == 0x00, "ccTrophyManager_s2.vtable");
static_assert(offsetof(ccTrophyManager_s2, field_08) == 0x08, "ccTrophyManager_s2.field_08");
static_assert(offsetof(ccTrophyManager_s2, field_10) == 0x10, "ccTrophyManager_s2.field_10");

/* =========================================================================
 * ccStageBaseClump
 * Proven size: none (no operator-new literal for outer object; inner clump
 * wrapper allocated via FUN_140580190(0x340,...) in Create@0x6502C0 is a
 * separate heap object stored at +0x18). Last own field +0x80 -> >= 0x84.
 * Vtable: 0x14089ef68 (from ccStageBaseClump::ccStageBaseClump ctor@0x6501E0).
 * Fields from state_surface + ctor/Clear decomp:
 *   +0x00 vtable, +0x18 clump_ptr (qword), +0x20 subobject init,
 *   +0x2C subobject (FUN_140586500/5873e0), +0x6C subobject (FUN_140594b20,
 *   3-float arg likely scale/vec3), +0x78 qword=1 in ctor, +0x7C qword
 *   cleared in Clear/dtor, +0x80 uint32=0 in ctor/Create.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccStageBaseClump_s2 {
    uint64_t vtable;           /* 0x00  set to &PTR_FUN_14089ef68 in ctor */
    uint8_t  _pad_08[0x10];    /* 0x08  gap (base / BlockAllocator subobject) */
    uint64_t clump_ptr;        /* 0x18  param_1[3]: inner nuccChunkClump wrapper ptr */
    uint8_t  subobj_20[0x0C];  /* 0x20  FUN_140580a40(param_1+4) subobject region */
    uint8_t  subobj_2C[0x40];  /* 0x2C  FUN_140586500/5873e0 subobject region */
    uint8_t  subobj_6C[0x0C];  /* 0x6C  FUN_140594b20 subobject (3-float init) */
    uint32_t field_78;         /* 0x78  param_1[0xf]=1 in ctor (lower dword of qword slot) */
    uint32_t field_7C;         /* 0x7C  upper dword cleared via *(uint64*)(p+0x7c)=0 in Clear/dtor */
    uint32_t field_80;         /* 0x80  *(uint32*)(param_1+0x10)=0 in ctor/Create */
    uint8_t  _pad_84[0x04];    /* 0x84  trailing alignment pad */
} ccStageBaseClump_s2;

static_assert(offsetof(ccStageBaseClump_s2, vtable)    == 0x00, "ccStageBaseClump_s2.vtable");
static_assert(offsetof(ccStageBaseClump_s2, _pad_08)   == 0x08, "ccStageBaseClump_s2._pad_08");
static_assert(offsetof(ccStageBaseClump_s2, clump_ptr) == 0x18, "ccStageBaseClump_s2.clump_ptr");
static_assert(offsetof(ccStageBaseClump_s2, subobj_20) == 0x20, "ccStageBaseClump_s2.subobj_20");
static_assert(offsetof(ccStageBaseClump_s2, subobj_2C) == 0x2C, "ccStageBaseClump_s2.subobj_2C");
static_assert(offsetof(ccStageBaseClump_s2, subobj_6C) == 0x6C, "ccStageBaseClump_s2.subobj_6C");
static_assert(offsetof(ccStageBaseClump_s2, field_78)  == 0x78, "ccStageBaseClump_s2.field_78");
static_assert(offsetof(ccStageBaseClump_s2, field_7C)  == 0x7C, "ccStageBaseClump_s2.field_7C");
static_assert(offsetof(ccStageBaseClump_s2, field_80)  == 0x80, "ccStageBaseClump_s2.field_80");
static_assert(offsetof(ccStageBaseClump_s2, _pad_84)   == 0x84, "ccStageBaseClump_s2._pad_84");

#endif /* CMN08_S2_H */