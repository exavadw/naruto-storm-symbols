/* cmn08.h -- NARUTO STORM 4 PC 1.09 (s4 / NSUNS4_release.exe) struct group cmn08
 * INFERRED layouts from static decompilation. Not CONFIRMED by runtime trace.
 * All offsets derived from s4 x64 decompile (image base 0x140000000).
 * Sizes proven only where operator-new / allocator argument is visible.
 */
#ifndef CMN08_S4_H
#define CMN08_S4_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccStageBaseClump_s4 -- size PROVEN 0x340 via FUN_140a017f0(0x340,"...ccStageBaseClump.cpp",0x59) at RVA 0xADCE70 */
typedef struct __attribute__((packed)) ccStageBaseClump_s4 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x8]; /* 0x008 gap */
    uint32_t field_10; /* 0x010 */
    uint8_t _pad_014[0x4]; /* 0x014 gap */
    uint64_t field_18; /* 0x018 */
    uint32_t field_20; /* 0x020 */
    uint32_t field_24; /* 0x024 */
    uint32_t field_28; /* 0x028 */
    uint8_t _pad_02C[0x40]; /* 0x02C gap */
    uint32_t field_6C; /* 0x06C */
    uint32_t field_70; /* 0x070 */
    uint32_t field_74; /* 0x074 */
    uint32_t field_78; /* 0x078 */
    uint32_t field_7C; /* 0x07C */
    uint32_t field_80; /* 0x080 */
    uint8_t _pad_084[0x14]; /* 0x084 gap */
    uint64_t field_98; /* 0x098 */
    uint8_t _pad_0A0[0x2A0]; /* 0x0A0 trailing pad to 0x340 */
} ccStageBaseClump_s4;

static_assert(offsetof(ccStageBaseClump_s4, vtable) == 0x000, "ccStageBaseClump_s4.vtable");
static_assert(offsetof(ccStageBaseClump_s4, field_10) == 0x010, "ccStageBaseClump_s4.field_10");
static_assert(offsetof(ccStageBaseClump_s4, field_18) == 0x018, "ccStageBaseClump_s4.field_18");
static_assert(offsetof(ccStageBaseClump_s4, field_20) == 0x020, "ccStageBaseClump_s4.field_20");
static_assert(offsetof(ccStageBaseClump_s4, field_24) == 0x024, "ccStageBaseClump_s4.field_24");
static_assert(offsetof(ccStageBaseClump_s4, field_28) == 0x028, "ccStageBaseClump_s4.field_28");
static_assert(offsetof(ccStageBaseClump_s4, field_6C) == 0x06C, "ccStageBaseClump_s4.field_6C");
static_assert(offsetof(ccStageBaseClump_s4, field_70) == 0x070, "ccStageBaseClump_s4.field_70");
static_assert(offsetof(ccStageBaseClump_s4, field_74) == 0x074, "ccStageBaseClump_s4.field_74");
static_assert(offsetof(ccStageBaseClump_s4, field_78) == 0x078, "ccStageBaseClump_s4.field_78");
static_assert(offsetof(ccStageBaseClump_s4, field_7C) == 0x07C, "ccStageBaseClump_s4.field_7C");
static_assert(offsetof(ccStageBaseClump_s4, field_80) == 0x080, "ccStageBaseClump_s4.field_80");
static_assert(offsetof(ccStageBaseClump_s4, field_98) == 0x098, "ccStageBaseClump_s4.field_98");
static_assert(sizeof(ccStageBaseClump_s4) == 0x340, "ccStageBaseClump_s4 size proven 0x340");

/* ccStageCollisionBase_s4 -- size unknown, >= 0x78 (last field at 0x70, 8 bytes) */
typedef struct __attribute__((packed)) ccStageCollisionBase_s4 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x8]; /* 0x008 gap */
    uint32_t field_10; /* 0x010 */
    uint8_t _pad_014[0x2C]; /* 0x014 gap */
    uint32_t field_40; /* 0x040 */
    uint8_t _pad_044[0x4]; /* 0x044 gap */
    uint64_t field_48; /* 0x048 */
    uint8_t _pad_050[0x20]; /* 0x050 gap */
    uint64_t field_70; /* 0x070 */
} ccStageCollisionBase_s4;

static_assert(offsetof(ccStageCollisionBase_s4, vtable) == 0x000, "ccStageCollisionBase_s4.vtable");
static_assert(offsetof(ccStageCollisionBase_s4, field_10) == 0x010, "ccStageCollisionBase_s4.field_10");
static_assert(offsetof(ccStageCollisionBase_s4, field_40) == 0x040, "ccStageCollisionBase_s4.field_40");
static_assert(offsetof(ccStageCollisionBase_s4, field_48) == 0x048, "ccStageCollisionBase_s4.field_48");
static_assert(offsetof(ccStageCollisionBase_s4, field_70) == 0x070, "ccStageCollisionBase_s4.field_70");

/* ccStateStaffRoll_s4 -- size unknown, >= 0xA8 (last field at 0xA0, 8 bytes)
 * Vtable PTR_FUN_141063768 set in wrapper at 0x5a77dc. */
typedef struct __attribute__((packed)) ccStateStaffRoll_s4 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x3]; /* 0x008 gap */
    uint8_t field_0B; /* 0x00B */
    uint32_t field_0C; /* 0x00C */
    uint8_t _pad_010[0x38]; /* 0x010 gap */
    uint64_t field_48; /* 0x048 */
    uint8_t _pad_050[0x4]; /* 0x050 gap */
    uint32_t field_54; /* 0x054 */
    uint8_t _pad_058[0x4]; /* 0x058 gap */
    uint32_t field_5C; /* 0x05C */
    uint8_t _pad_060[0x8]; /* 0x060 gap */
    uint64_t field_68; /* 0x068 */
    uint8_t _pad_070[0x30]; /* 0x070 gap */
    uint64_t field_A0; /* 0x0A0 */
} ccStateStaffRoll_s4;

static_assert(offsetof(ccStateStaffRoll_s4, vtable) == 0x000, "ccStateStaffRoll_s4.vtable");
static_assert(offsetof(ccStateStaffRoll_s4, field_0B) == 0x00B, "ccStateStaffRoll_s4.field_0B");
static_assert(offsetof(ccStateStaffRoll_s4, field_0C) == 0x00C, "ccStateStaffRoll_s4.field_0C");
static_assert(offsetof(ccStateStaffRoll_s4, field_48) == 0x048, "ccStateStaffRoll_s4.field_48");
static_assert(offsetof(ccStateStaffRoll_s4, field_54) == 0x054, "ccStateStaffRoll_s4.field_54");
static_assert(offsetof(ccStateStaffRoll_s4, field_5C) == 0x05C, "ccStateStaffRoll_s4.field_5C");
static_assert(offsetof(ccStateStaffRoll_s4, field_68) == 0x068, "ccStateStaffRoll_s4.field_68");
static_assert(offsetof(ccStateStaffRoll_s4, field_A0) == 0x0A0, "ccStateStaffRoll_s4.field_A0");

/* ccTask_s4 -- size unknown, >= 0x30 (last field at 0x28, 8 bytes). Vtable PTR_FUN_141114618. */
typedef struct __attribute__((packed)) ccTask_s4 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x14]; /* 0x008 gap */
    uint32_t refcount; /* 0x01C */
    uint64_t field_20; /* 0x020 */
    uint64_t field_28; /* 0x028 */
} ccTask_s4;

static_assert(offsetof(ccTask_s4, vtable) == 0x000, "ccTask_s4.vtable");
static_assert(offsetof(ccTask_s4, refcount) == 0x01C, "ccTask_s4.refcount");
static_assert(offsetof(ccTask_s4, field_20) == 0x020, "ccTask_s4.field_20");
static_assert(offsetof(ccTask_s4, field_28) == 0x028, "ccTask_s4.field_28");

/* ccTaskBase_s4 -- size unknown, >= 0x15980 (field at 0x15978 read).
 * Allocator 0x30 at RVA 0xAB3FF0 is for list node, NOT ccTaskBase itself.
 * Multiple vtables: PTR_FUN_141114058 (base), PTR_FUN_140FED518, PTR_FUN_1410990F8. */
typedef struct __attribute__((packed)) ccTaskBase_s4 {
    uint64_t vtable; /* 0x000 */
    uint64_t field_08; /* 0x008 */
    uint8_t field_10; /* 0x010 */
    uint8_t _pad_011[0x7]; /* 0x011 gap */
    uint64_t task_list_head; /* 0x018 */
    uint64_t task_list_tail; /* 0x020 */
    uint32_t field_28; /* 0x028 */
    uint8_t _pad_02C[0x1C]; /* 0x02C gap */
    uint64_t field_48; /* 0x048 */
    uint8_t _pad_050[0x4]; /* 0x050 gap */
    uint32_t field_54; /* 0x054 */
    uint64_t field_58; /* 0x058 */
    uint8_t _pad_060[0x10]; /* 0x060 gap */
    uint64_t field_70; /* 0x070 */
    uint8_t _pad_078[0x6D]; /* 0x078 gap */
    uint8_t field_E5; /* 0x0E5 */
    uint8_t _pad_0E6[0x15892]; /* 0x0E6 gap */
    uint64_t field_15978; /* 0x15978 */
} ccTaskBase_s4;

static_assert(offsetof(ccTaskBase_s4, vtable) == 0x000, "ccTaskBase_s4.vtable");
static_assert(offsetof(ccTaskBase_s4, field_08) == 0x008, "ccTaskBase_s4.field_08");
static_assert(offsetof(ccTaskBase_s4, field_10) == 0x010, "ccTaskBase_s4.field_10");
static_assert(offsetof(ccTaskBase_s4, task_list_head) == 0x018, "ccTaskBase_s4.task_list_head");
static_assert(offsetof(ccTaskBase_s4, task_list_tail) == 0x020, "ccTaskBase_s4.task_list_tail");
static_assert(offsetof(ccTaskBase_s4, field_28) == 0x028, "ccTaskBase_s4.field_28");
static_assert(offsetof(ccTaskBase_s4, field_48) == 0x048, "ccTaskBase_s4.field_48");
static_assert(offsetof(ccTaskBase_s4, field_54) == 0x054, "ccTaskBase_s4.field_54");
static_assert(offsetof(ccTaskBase_s4, field_58) == 0x058, "ccTaskBase_s4.field_58");
static_assert(offsetof(ccTaskBase_s4, field_70) == 0x070, "ccTaskBase_s4.field_70");
static_assert(offsetof(ccTaskBase_s4, field_E5) == 0x0E5, "ccTaskBase_s4.field_E5");
static_assert(offsetof(ccTaskBase_s4, field_15978) == 0x15978, "ccTaskBase_s4.field_15978");

/* ccTrophyManager_Impl_s4 -- size unknown, >= 0x117C (last field at 0x1174, 8 bytes).
 * Vtable PTR_FUN_140EEF978. No allocator literal found. */
typedef struct __attribute__((packed)) ccTrophyManager_Impl_s4 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x4]; /* 0x008 gap */
    uint32_t field_0C; /* 0x00C */
    uint8_t _pad_010[0xA]; /* 0x010 gap */
    uint8_t field_1A; /* 0x01A */
    uint8_t _pad_01B[0xA]; /* 0x01B gap */
    uint8_t field_25; /* 0x025 */
    uint8_t field_26; /* 0x026 */
    uint8_t _pad_027[0x4]; /* 0x027 gap */
    uint8_t field_2B; /* 0x02B */
    uint8_t _pad_02C[0x1C]; /* 0x02C gap */
    uint64_t field_48; /* 0x048 */
    uint8_t _pad_050[0x4]; /* 0x050 gap */
    uint64_t field_54; /* 0x054 */
    uint32_t field_5C; /* 0x05C */
    uint8_t _pad_060[0x8]; /* 0x060 gap */
    uint64_t field_68; /* 0x068 */
    uint64_t field_70; /* 0x070 */
    uint8_t _pad_078[0x80]; /* 0x078 gap */
    uint64_t field_F8; /* 0x0F8 */
    uint8_t _pad_100[0x8]; /* 0x100 gap */
    uint64_t field_108; /* 0x108 */
    uint8_t _pad_110[0x24]; /* 0x110 gap */
    uint64_t field_134; /* 0x134 */
    uint64_t field_13C; /* 0x13C */
    uint64_t field_144; /* 0x144 */
    uint32_t field_14C; /* 0x14C */
    uint8_t _pad_150[0xC]; /* 0x150 gap */
    uint64_t field_15C; /* 0x15C */
    uint32_t field_164; /* 0x164 */
    uint8_t _pad_168[0xC6]; /* 0x168 gap */
    uint8_t field_22E; /* 0x22E */
    uint8_t _pad_22F[0xF45]; /* 0x22F gap */
    uint64_t field_1174; /* 0x1174 */
} ccTrophyManager_Impl_s4;

static_assert(offsetof(ccTrophyManager_Impl_s4, vtable) == 0x000, "ccTrophyManager_Impl_s4.vtable");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_0C) == 0x00C, "ccTrophyManager_Impl_s4.field_0C");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_1A) == 0x01A, "ccTrophyManager_Impl_s4.field_1A");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_25) == 0x025, "ccTrophyManager_Impl_s4.field_25");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_26) == 0x026, "ccTrophyManager_Impl_s4.field_26");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_2B) == 0x02B, "ccTrophyManager_Impl_s4.field_2B");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_48) == 0x048, "ccTrophyManager_Impl_s4.field_48");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_54) == 0x054, "ccTrophyManager_Impl_s4.field_54");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_5C) == 0x05C, "ccTrophyManager_Impl_s4.field_5C");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_68) == 0x068, "ccTrophyManager_Impl_s4.field_68");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_70) == 0x070, "ccTrophyManager_Impl_s4.field_70");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_F8) == 0x0F8, "ccTrophyManager_Impl_s4.field_F8");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_108) == 0x108, "ccTrophyManager_Impl_s4.field_108");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_134) == 0x134, "ccTrophyManager_Impl_s4.field_134");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_13C) == 0x13C, "ccTrophyManager_Impl_s4.field_13C");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_144) == 0x144, "ccTrophyManager_Impl_s4.field_144");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_14C) == 0x14C, "ccTrophyManager_Impl_s4.field_14C");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_15C) == 0x15C, "ccTrophyManager_Impl_s4.field_15C");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_164) == 0x164, "ccTrophyManager_Impl_s4.field_164");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_22E) == 0x22E, "ccTrophyManager_Impl_s4.field_22E");
static_assert(offsetof(ccTrophyManager_Impl_s4, field_1174) == 0x1174, "ccTrophyManager_Impl_s4.field_1174");

/* ccTaskCertainExe_s4 -- inherits ccTask_s4. Size PROVEN 0x30 via FUN_140a017f0(0x30,"...ccTaskBase.cpp") at RVA 0xAB3FF0.
 * Vtable PTR_FUN_14101CEF0. sizeof(ccTask_s4)=0x30 covers this; no extra fields beyond base. */
typedef struct __attribute__((packed)) ccTaskCertainExe_s4 {
    ccTask_s4 base; /* 0x000 */
} ccTaskCertainExe_s4;

static_assert(offsetof(ccTaskCertainExe_s4, base) == 0x000, "ccTaskCertainExe_s4.base");
static_assert(sizeof(ccTaskCertainExe_s4) == 0x30, "ccTaskCertainExe_s4 size proven 0x30");

#endif /* CMN08_S4_H */
