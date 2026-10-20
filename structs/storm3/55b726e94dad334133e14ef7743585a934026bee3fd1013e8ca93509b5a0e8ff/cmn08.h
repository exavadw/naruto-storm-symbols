/* cmn08.h -- NARUTO STORM 3 Full Burst HD (s3 / NSUNS3.exe) struct group cmn08
 * INFERRED layouts from static decompilation. Not CONFIRMED by runtime trace.
 * All offsets derived from s3 x64 decompile (image base 0x140000000).
 * Sizes proven only where operator-new / allocator argument is visible.
 */
#ifndef CMN08_S3_H
#define CMN08_S3_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct __attribute__((packed)) ccStageBaseClump_s3 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x24]; /* 0x008 gap */
    uint32_t field_2C; /* 0x02C */
    uint8_t _pad_030[0x3C]; /* 0x030 gap */
    uint32_t field_6C; /* 0x06C */
    uint8_t _pad_070[0x8]; /* 0x070 gap */
    uint32_t field_78; /* 0x078 */
    uint32_t field_7C; /* 0x07C */
    uint32_t field_80; /* 0x080 */
    uint8_t _pad_084[0x2BC]; /* 0x084 trailing pad */
} ccStageBaseClump_s3;

static_assert(offsetof(ccStageBaseClump_s3, vtable) == 0x0, "ccStageBaseClump_s3.vtable");
static_assert(offsetof(ccStageBaseClump_s3, field_2C) == 0x2C, "ccStageBaseClump_s3.field_2C");
static_assert(offsetof(ccStageBaseClump_s3, field_6C) == 0x6C, "ccStageBaseClump_s3.field_6C");
static_assert(offsetof(ccStageBaseClump_s3, field_78) == 0x78, "ccStageBaseClump_s3.field_78");
static_assert(offsetof(ccStageBaseClump_s3, field_7C) == 0x7C, "ccStageBaseClump_s3.field_7C");
static_assert(offsetof(ccStageBaseClump_s3, field_80) == 0x80, "ccStageBaseClump_s3.field_80");
static_assert(sizeof(ccStageBaseClump_s3) == 0x340, "ccStageBaseClump_s3 size proven");

typedef struct __attribute__((packed)) ccStageCollisionBase_s3 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x40]; /* 0x008 gap */
    int32_t field_48; /* 0x048 */
    uint64_t field_4C; /* 0x04C */
    int32_t field_54; /* 0x054 */
} ccStageCollisionBase_s3;

static_assert(offsetof(ccStageCollisionBase_s3, vtable) == 0x0, "ccStageCollisionBase_s3.vtable");
static_assert(offsetof(ccStageCollisionBase_s3, field_48) == 0x48, "ccStageCollisionBase_s3.field_48");
static_assert(offsetof(ccStageCollisionBase_s3, field_4C) == 0x4C, "ccStageCollisionBase_s3.field_4C");
static_assert(offsetof(ccStageCollisionBase_s3, field_54) == 0x54, "ccStageCollisionBase_s3.field_54");

typedef struct __attribute__((packed)) ccStateStaffRoll_s3 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x4C]; /* 0x008 gap */
    uint64_t field_54; /* 0x054 */
    uint32_t field_5C; /* 0x05C */
    uint32_t field_60; /* 0x060 */
    uint8_t _pad_064[0x4]; /* 0x064 gap */
    uint64_t field_68; /* 0x068 */
    uint64_t field_70; /* 0x070 */
} ccStateStaffRoll_s3;

static_assert(offsetof(ccStateStaffRoll_s3, vtable) == 0x0, "ccStateStaffRoll_s3.vtable");
static_assert(offsetof(ccStateStaffRoll_s3, field_54) == 0x54, "ccStateStaffRoll_s3.field_54");
static_assert(offsetof(ccStateStaffRoll_s3, field_5C) == 0x5C, "ccStateStaffRoll_s3.field_5C");
static_assert(offsetof(ccStateStaffRoll_s3, field_60) == 0x60, "ccStateStaffRoll_s3.field_60");
static_assert(offsetof(ccStateStaffRoll_s3, field_68) == 0x68, "ccStateStaffRoll_s3.field_68");
static_assert(offsetof(ccStateStaffRoll_s3, field_70) == 0x70, "ccStateStaffRoll_s3.field_70");

typedef struct __attribute__((packed)) ccTask_s3 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x10]; /* 0x008 gap */
    int32_t task_type; /* 0x018 */
    uint32_t refcount; /* 0x01C */
    int32_t flags; /* 0x020 */
    uint8_t _pad_024[0xC]; /* 0x024 trailing pad */
} ccTask_s3;

static_assert(offsetof(ccTask_s3, vtable) == 0x0, "ccTask_s3.vtable");
static_assert(offsetof(ccTask_s3, task_type) == 0x18, "ccTask_s3.task_type");
static_assert(offsetof(ccTask_s3, refcount) == 0x1C, "ccTask_s3.refcount");
static_assert(offsetof(ccTask_s3, flags) == 0x20, "ccTask_s3.flags");

typedef struct __attribute__((packed)) ccTaskBase_s3 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x10]; /* 0x008 gap */
    uint64_t task_list_head; /* 0x018 */
    uint64_t task_list_tail; /* 0x020 */
    uint8_t _pad_028[0x2C]; /* 0x028 gap */
    int32_t field_54; /* 0x054 */
    uint32_t field_58; /* 0x058 */
    int32_t field_5C; /* 0x05C */
    uint32_t field_60; /* 0x060 */
    uint8_t _pad_064[0x4]; /* 0x064 gap */
    uint64_t field_68; /* 0x068 */
    uint64_t field_70; /* 0x070 */
    uint32_t field_78; /* 0x078 */
    uint32_t field_7C; /* 0x07C */
    uint64_t field_80; /* 0x080 */
    uint8_t _pad_088[0x8]; /* 0x088 gap */
    uint64_t field_90; /* 0x090 */
    uint8_t _pad_098[0x8]; /* 0x098 gap */
    uint64_t field_A0; /* 0x0A0 */
    uint8_t _pad_0A8[0x28]; /* 0x0A8 gap */
    uint32_t field_D0_lo; /* 0x0D0 */
    uint32_t field_D4; /* 0x0D4 */
    uint32_t field_D8; /* 0x0D8 */
    uint32_t field_DC; /* 0x0DC */
    uint8_t _pad_0E0[0x30]; /* 0x0E0 gap */
    uint32_t field_110; /* 0x110 */
    uint32_t field_114; /* 0x114 */
    uint64_t field_118; /* 0x118 */
    uint32_t field_120; /* 0x120 */
    uint32_t field_124; /* 0x124 */
    uint32_t field_128; /* 0x128 */
    uint8_t _pad_12C[0x100]; /* 0x12C gap */
    uint32_t field_22C; /* 0x22C */
    uint64_t field_230; /* 0x230 */
    uint64_t field_238; /* 0x238 */
    uint8_t _pad_240[0x70]; /* 0x240 gap */
    uint64_t field_2B0; /* 0x2B0 */
    uint32_t field_2B8; /* 0x2B8 */
} ccTaskBase_s3;

static_assert(offsetof(ccTaskBase_s3, vtable) == 0x0, "ccTaskBase_s3.vtable");
static_assert(offsetof(ccTaskBase_s3, task_list_head) == 0x18, "ccTaskBase_s3.task_list_head");
static_assert(offsetof(ccTaskBase_s3, task_list_tail) == 0x20, "ccTaskBase_s3.task_list_tail");
static_assert(offsetof(ccTaskBase_s3, field_54) == 0x54, "ccTaskBase_s3.field_54");
static_assert(offsetof(ccTaskBase_s3, field_58) == 0x58, "ccTaskBase_s3.field_58");
static_assert(offsetof(ccTaskBase_s3, field_5C) == 0x5C, "ccTaskBase_s3.field_5C");
static_assert(offsetof(ccTaskBase_s3, field_60) == 0x60, "ccTaskBase_s3.field_60");
static_assert(offsetof(ccTaskBase_s3, field_68) == 0x68, "ccTaskBase_s3.field_68");
static_assert(offsetof(ccTaskBase_s3, field_70) == 0x70, "ccTaskBase_s3.field_70");
static_assert(offsetof(ccTaskBase_s3, field_78) == 0x78, "ccTaskBase_s3.field_78");
static_assert(offsetof(ccTaskBase_s3, field_7C) == 0x7C, "ccTaskBase_s3.field_7C");
static_assert(offsetof(ccTaskBase_s3, field_80) == 0x80, "ccTaskBase_s3.field_80");
static_assert(offsetof(ccTaskBase_s3, field_90) == 0x90, "ccTaskBase_s3.field_90");
static_assert(offsetof(ccTaskBase_s3, field_A0) == 0xA0, "ccTaskBase_s3.field_A0");
static_assert(offsetof(ccTaskBase_s3, field_D0_lo) == 0xD0, "ccTaskBase_s3.field_D0_lo");
static_assert(offsetof(ccTaskBase_s3, field_D4) == 0xD4, "ccTaskBase_s3.field_D4");
static_assert(offsetof(ccTaskBase_s3, field_D8) == 0xD8, "ccTaskBase_s3.field_D8");
static_assert(offsetof(ccTaskBase_s3, field_DC) == 0xDC, "ccTaskBase_s3.field_DC");
static_assert(offsetof(ccTaskBase_s3, field_110) == 0x110, "ccTaskBase_s3.field_110");
static_assert(offsetof(ccTaskBase_s3, field_114) == 0x114, "ccTaskBase_s3.field_114");
static_assert(offsetof(ccTaskBase_s3, field_118) == 0x118, "ccTaskBase_s3.field_118");
static_assert(offsetof(ccTaskBase_s3, field_120) == 0x120, "ccTaskBase_s3.field_120");
static_assert(offsetof(ccTaskBase_s3, field_124) == 0x124, "ccTaskBase_s3.field_124");
static_assert(offsetof(ccTaskBase_s3, field_128) == 0x128, "ccTaskBase_s3.field_128");
static_assert(offsetof(ccTaskBase_s3, field_22C) == 0x22C, "ccTaskBase_s3.field_22C");
static_assert(offsetof(ccTaskBase_s3, field_230) == 0x230, "ccTaskBase_s3.field_230");
static_assert(offsetof(ccTaskBase_s3, field_238) == 0x238, "ccTaskBase_s3.field_238");
static_assert(offsetof(ccTaskBase_s3, field_2B0) == 0x2B0, "ccTaskBase_s3.field_2B0");
static_assert(offsetof(ccTaskBase_s3, field_2B8) == 0x2B8, "ccTaskBase_s3.field_2B8");

typedef struct __attribute__((packed)) ccTaskCertainExe_s3 {
    ccTask_s3 base; /* 0x000 */
    uint8_t _pad_030[0x50]; /* 0x030 trailing pad */
} ccTaskCertainExe_s3;

static_assert(offsetof(ccTaskCertainExe_s3, base) == 0x0, "ccTaskCertainExe_s3.base");

typedef struct __attribute__((packed)) ccTrophyManager_Impl_s3 {
    uint64_t vtable; /* 0x000 */
    uint8_t _pad_008[0x4C]; /* 0x008 gap */
    uint64_t field_54; /* 0x054 */
    uint32_t field_5C; /* 0x05C */
    uint32_t field_60; /* 0x060 */
    uint8_t _pad_064[0x4]; /* 0x064 gap */
    uint64_t field_68; /* 0x068 */
    uint64_t field_70; /* 0x070 */
    uint8_t _pad_078[0x30]; /* 0x078 gap */
    uint32_t field_A8; /* 0x0A8 */
    uint8_t _pad_0AC[0x4]; /* 0x0AC gap */
    uint64_t field_B0; /* 0x0B0 */
    uint8_t _pad_0B8[0x158]; /* 0x0B8 gap */
    uint64_t field_210; /* 0x210 */
    uint8_t _pad_218[0x158]; /* 0x218 gap */
    uint64_t field_370; /* 0x370 */
    uint8_t _pad_378[0x30]; /* 0x378 gap */
    uint32_t field_3A8; /* 0x3A8 */
    uint8_t _pad_3AC[0x4]; /* 0x3AC gap */
    uint64_t field_3B0; /* 0x3B0 */
    uint8_t _pad_3B8[0x20]; /* 0x3B8 gap */
    uint64_t field_3D8; /* 0x3D8 */
    uint8_t _pad_3E0[0x20]; /* 0x3E0 gap */
    uint64_t field_400; /* 0x400 */
    uint8_t _pad_408[0x38]; /* 0x408 gap */
    uint64_t field_440; /* 0x440 */
    uint64_t field_448; /* 0x448 */
    uint8_t _pad_450[0x30]; /* 0x450 gap */
    uint64_t field_480; /* 0x480 */
    uint8_t _pad_488[0x30]; /* 0x488 gap */
    uint64_t field_4B8; /* 0x4B8 */
    uint64_t field_4C0; /* 0x4C0 */
    uint8_t _pad_4C8[0x8]; /* 0x4C8 gap */
    uint64_t field_4D0; /* 0x4D0 */
    uint64_t field_4D8; /* 0x4D8 */
    uint8_t _pad_4E0[0x10]; /* 0x4E0 gap */
    uint64_t field_4F0; /* 0x4F0 */
    uint64_t field_4F8; /* 0x4F8 */
    uint64_t field_500; /* 0x500 */
    uint64_t field_508; /* 0x508 */
    uint64_t field_510; /* 0x510 */
} ccTrophyManager_Impl_s3;

static_assert(offsetof(ccTrophyManager_Impl_s3, vtable) == 0x0, "ccTrophyManager_Impl_s3.vtable");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_54) == 0x54, "ccTrophyManager_Impl_s3.field_54");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_5C) == 0x5C, "ccTrophyManager_Impl_s3.field_5C");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_60) == 0x60, "ccTrophyManager_Impl_s3.field_60");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_68) == 0x68, "ccTrophyManager_Impl_s3.field_68");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_70) == 0x70, "ccTrophyManager_Impl_s3.field_70");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_A8) == 0xA8, "ccTrophyManager_Impl_s3.field_A8");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_B0) == 0xB0, "ccTrophyManager_Impl_s3.field_B0");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_210) == 0x210, "ccTrophyManager_Impl_s3.field_210");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_370) == 0x370, "ccTrophyManager_Impl_s3.field_370");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_3A8) == 0x3A8, "ccTrophyManager_Impl_s3.field_3A8");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_3B0) == 0x3B0, "ccTrophyManager_Impl_s3.field_3B0");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_3D8) == 0x3D8, "ccTrophyManager_Impl_s3.field_3D8");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_400) == 0x400, "ccTrophyManager_Impl_s3.field_400");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_440) == 0x440, "ccTrophyManager_Impl_s3.field_440");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_448) == 0x448, "ccTrophyManager_Impl_s3.field_448");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_480) == 0x480, "ccTrophyManager_Impl_s3.field_480");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_4B8) == 0x4B8, "ccTrophyManager_Impl_s3.field_4B8");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_4C0) == 0x4C0, "ccTrophyManager_Impl_s3.field_4C0");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_4D0) == 0x4D0, "ccTrophyManager_Impl_s3.field_4D0");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_4D8) == 0x4D8, "ccTrophyManager_Impl_s3.field_4D8");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_4F0) == 0x4F0, "ccTrophyManager_Impl_s3.field_4F0");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_4F8) == 0x4F8, "ccTrophyManager_Impl_s3.field_4F8");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_500) == 0x500, "ccTrophyManager_Impl_s3.field_500");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_508) == 0x508, "ccTrophyManager_Impl_s3.field_508");
static_assert(offsetof(ccTrophyManager_Impl_s3, field_510) == 0x510, "ccTrophyManager_Impl_s3.field_510");

/* ccTrophyManager: no instance state in s3.
 * All 3 outer methods are static/thunk wrappers with no this-pointer field access:
 *   Enable    @ 0x698950 — reads/writes global DAT_140c24578 only
 *   Finalize  @ 0x7970D0 — vtable dispatch thunk (**(param_1+8))(), (**(param_1+0x10))(param_1)
 *   Unlock    @ 0x797110 — reads *(param_1+0x18) (Impl ptr) and forwards to FUN_140797890
 * Instance state lives in ccTrophyManager_Impl_s3 (vtable 0x140984e40).
 * INFERRED from static decompilation; not CONFIRMED by runtime trace.
 */

#endif /* CMN08_S3_H */
