#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* st3a17 s3 - Story progression structs (INFERRED, not CONFIRMED)
 * Build: s3 (NSUNS3.exe 64-bit, Storm 3 Full Burst HD PC)
 * Sizes are lower bounds from max observed field offset + field size.
 * No operator-new evidence found; sizes marked with >= below.
 * Field types from decompiled param_1 accesses; addrof/array kinds
 * use uint8_t as placeholder (actual size unknown).
 * All layouts INFERRED from static analysis. static_assert offsets
 * verify the reconstructed layout matches the decompiler output,
 * not runtime-confirmed ground truth.
 *
 * Fields use uint8_t[N] sized by inter-field gaps to guarantee
 * gcc offsetof matches the decompiler's byte offsets. The documented
 * C type appears in a trailing comment per field.
 */

/* ccStageAdvGimmickSearchPoint: 9 fields, size >= 0x100 (unproven) */
typedef struct {
    uint8_t _pad_000[11];
    uint8_t f_00b[5]; /* uint8_t */
    uint8_t f_010[152]; /* uint8_t */
    uint8_t f_0a8[8]; /* int64_t * */
    uint8_t f_0b0[8]; /* int64_t * */
    uint8_t f_0b8[8]; /* uint64_t * */
    uint8_t f_0c0[24]; /* uint64_t * */
    uint8_t f_0d8[28]; /* uint64_t * */
    uint8_t f_0f4[4]; /* int32_t * */
    uint8_t f_0f8[1]; /* uint8_t */
    uint8_t _pad_trail[7];
} struct_ccStageAdvGimmickSearchPoint_t;

static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_00b) == 0xB, "ccStageAdvGimmickSearchPoint::f_00b offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_010) == 0x10, "ccStageAdvGimmickSearchPoint::f_010 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0a8) == 0xA8, "ccStageAdvGimmickSearchPoint::f_0a8 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0b0) == 0xB0, "ccStageAdvGimmickSearchPoint::f_0b0 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0b8) == 0xB8, "ccStageAdvGimmickSearchPoint::f_0b8 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0c0) == 0xC0, "ccStageAdvGimmickSearchPoint::f_0c0 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0d8) == 0xD8, "ccStageAdvGimmickSearchPoint::f_0d8 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0f4) == 0xF4, "ccStageAdvGimmickSearchPoint::f_0f4 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint_t, f_0f8) == 0xF8, "ccStageAdvGimmickSearchPoint::f_0f8 offset mismatch");

/* ccStageAdvGimmickSearchPoint2: 11 fields, size >= 0x100 (unproven) */
typedef struct {
    uint8_t f_000[1]; /* void * */
    uint8_t f_001[10]; /* uint8_t */
    uint8_t f_00b[5]; /* uint8_t */
    uint8_t f_010[4]; /* uint8_t */
    uint8_t f_014[1]; /* uint8_t */
    uint8_t f_015[139]; /* uint8_t */
    uint8_t f_0a0[8]; /* uint32_t * */
    uint8_t f_0a8[16]; /* int64_t * */
    uint8_t f_0b8[8]; /* uint64_t * */
    uint8_t f_0c0[56]; /* uint64_t * */
    uint8_t f_0f8[1]; /* uint8_t */
    uint8_t _pad_trail[7];
} struct_ccStageAdvGimmickSearchPoint2_t;

static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_000) == 0x0, "ccStageAdvGimmickSearchPoint2::f_000 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_001) == 0x1, "ccStageAdvGimmickSearchPoint2::f_001 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_00b) == 0xB, "ccStageAdvGimmickSearchPoint2::f_00b offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_010) == 0x10, "ccStageAdvGimmickSearchPoint2::f_010 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_014) == 0x14, "ccStageAdvGimmickSearchPoint2::f_014 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_015) == 0x15, "ccStageAdvGimmickSearchPoint2::f_015 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_0a0) == 0xA0, "ccStageAdvGimmickSearchPoint2::f_0a0 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_0a8) == 0xA8, "ccStageAdvGimmickSearchPoint2::f_0a8 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_0b8) == 0xB8, "ccStageAdvGimmickSearchPoint2::f_0b8 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_0c0) == 0xC0, "ccStageAdvGimmickSearchPoint2::f_0c0 offset mismatch");
static_assert(offsetof(struct_ccStageAdvGimmickSearchPoint2_t, f_0f8) == 0xF8, "ccStageAdvGimmickSearchPoint2::f_0f8 offset mismatch");

/* ccStateAdvCheckUnlockCollectionItems: 11 fields, size >= 0xC8 (unproven) */
typedef struct {
    uint8_t _pad_000[7];
    uint8_t f_007[77]; /* uint8_t */
    uint8_t f_054[12]; /* uint32_t * */
    uint8_t f_060[16]; /* uint32_t * */
    uint8_t f_070[4]; /* int32_t * */
    uint8_t f_074[4]; /* int32_t * */
    uint8_t f_078[4]; /* int32_t * */
    uint8_t f_07c[12]; /* int32_t * */
    uint8_t f_088[48]; /* int64_t * */
    uint8_t f_0b8[4]; /* int32_t * */
    uint8_t f_0bc[4]; /* int32_t * */
    uint8_t f_0c0[8]; /* int32_t * */
} struct_ccStateAdvCheckUnlockCollectionItems_t;

static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_007) == 0x7, "ccStateAdvCheckUnlockCollectionItems::f_007 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_054) == 0x54, "ccStateAdvCheckUnlockCollectionItems::f_054 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_060) == 0x60, "ccStateAdvCheckUnlockCollectionItems::f_060 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_070) == 0x70, "ccStateAdvCheckUnlockCollectionItems::f_070 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_074) == 0x74, "ccStateAdvCheckUnlockCollectionItems::f_074 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_078) == 0x78, "ccStateAdvCheckUnlockCollectionItems::f_078 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_07c) == 0x7C, "ccStateAdvCheckUnlockCollectionItems::f_07c offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_088) == 0x88, "ccStateAdvCheckUnlockCollectionItems::f_088 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_0b8) == 0xB8, "ccStateAdvCheckUnlockCollectionItems::f_0b8 offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_0bc) == 0xBC, "ccStateAdvCheckUnlockCollectionItems::f_0bc offset mismatch");
static_assert(offsetof(struct_ccStateAdvCheckUnlockCollectionItems_t, f_0c0) == 0xC0, "ccStateAdvCheckUnlockCollectionItems::f_0c0 offset mismatch");

/* ccStateAdvMiniMap: 6 fields, size >= 0xF0 (unproven) */
typedef struct {
    uint8_t _pad_000[84];
    uint8_t f_054[12]; /* uint32_t * */
    uint8_t f_060[16]; /* uint32_t * */
    uint8_t f_070[8]; /* uint64_t ** */
    uint8_t f_078[48]; /* uint8_t */
    uint8_t f_0a8[64]; /* uint8_t */
    uint8_t f_0e8[1]; /* uint8_t */
    uint8_t _pad_trail[7];
} struct_ccStateAdvMiniMap_t;

static_assert(offsetof(struct_ccStateAdvMiniMap_t, f_054) == 0x54, "ccStateAdvMiniMap::f_054 offset mismatch");
static_assert(offsetof(struct_ccStateAdvMiniMap_t, f_060) == 0x60, "ccStateAdvMiniMap::f_060 offset mismatch");
static_assert(offsetof(struct_ccStateAdvMiniMap_t, f_070) == 0x70, "ccStateAdvMiniMap::f_070 offset mismatch");
static_assert(offsetof(struct_ccStateAdvMiniMap_t, f_078) == 0x78, "ccStateAdvMiniMap::f_078 offset mismatch");
static_assert(offsetof(struct_ccStateAdvMiniMap_t, f_0a8) == 0xA8, "ccStateAdvMiniMap::f_0a8 offset mismatch");
static_assert(offsetof(struct_ccStateAdvMiniMap_t, f_0e8) == 0xE8, "ccStateAdvMiniMap::f_0e8 offset mismatch");

/* ccStateAdvStaffRoll: 18 fields, size >= 0x368 (unproven) */
typedef struct {
    uint8_t _pad_000[7];
    uint8_t f_007[1]; /* uint8_t */
    uint8_t f_008[3]; /* uint8_t */
    uint8_t f_00b[41]; /* uint8_t */
    uint8_t f_034[32]; /* uint8_t */
    uint8_t f_054[12]; /* uint32_t * */
    uint8_t f_060[16]; /* uint32_t * */
    uint8_t f_070[8]; /* uint64_t ** */
    uint8_t f_078[8]; /* uint64_t * */
    uint8_t f_080[8]; /* uint64_t * */
    uint8_t f_088[40]; /* uint64_t * */
    uint8_t f_0b0[4]; /* int32_t * */
    uint8_t f_0b4[4]; /* uint32_t * */
    uint8_t f_0b8[8]; /* int32_t * */
    uint8_t f_0c0[640]; /* uint8_t */
    uint8_t f_340[12]; /* uint64_t * */
    uint8_t f_34c[4]; /* uint32_t * */
    uint8_t f_350[16]; /* int32_t * */
    uint8_t f_360[8]; /* int32_t * */
} struct_ccStateAdvStaffRoll_t;

static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_007) == 0x7, "ccStateAdvStaffRoll::f_007 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_008) == 0x8, "ccStateAdvStaffRoll::f_008 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_00b) == 0xB, "ccStateAdvStaffRoll::f_00b offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_034) == 0x34, "ccStateAdvStaffRoll::f_034 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_054) == 0x54, "ccStateAdvStaffRoll::f_054 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_060) == 0x60, "ccStateAdvStaffRoll::f_060 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_070) == 0x70, "ccStateAdvStaffRoll::f_070 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_078) == 0x78, "ccStateAdvStaffRoll::f_078 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_080) == 0x80, "ccStateAdvStaffRoll::f_080 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_088) == 0x88, "ccStateAdvStaffRoll::f_088 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_0b0) == 0xB0, "ccStateAdvStaffRoll::f_0b0 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_0b4) == 0xB4, "ccStateAdvStaffRoll::f_0b4 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_0b8) == 0xB8, "ccStateAdvStaffRoll::f_0b8 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_0c0) == 0xC0, "ccStateAdvStaffRoll::f_0c0 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_340) == 0x340, "ccStateAdvStaffRoll::f_340 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_34c) == 0x34C, "ccStateAdvStaffRoll::f_34c offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_350) == 0x350, "ccStateAdvStaffRoll::f_350 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStaffRoll_t, f_360) == 0x360, "ccStateAdvStaffRoll::f_360 offset mismatch");

/* ccStateAdvStartMenuChronology: 5 fields, size >= 0xB0 (unproven) */
typedef struct {
    uint8_t _pad_000[84];
    uint8_t f_054[12]; /* uint32_t * */
    uint8_t f_060[16]; /* uint32_t * */
    uint8_t f_070[48]; /* uint8_t */
    uint8_t f_0a0[4]; /* uint32_t * */
    uint8_t f_0a4[8]; /* int32_t * */
    uint8_t _pad_trail[4];
} struct_ccStateAdvStartMenuChronology_t;

static_assert(offsetof(struct_ccStateAdvStartMenuChronology_t, f_054) == 0x54, "ccStateAdvStartMenuChronology::f_054 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuChronology_t, f_060) == 0x60, "ccStateAdvStartMenuChronology::f_060 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuChronology_t, f_070) == 0x70, "ccStateAdvStartMenuChronology::f_070 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuChronology_t, f_0a0) == 0xA0, "ccStateAdvStartMenuChronology::f_0a0 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuChronology_t, f_0a4) == 0xA4, "ccStateAdvStartMenuChronology::f_0a4 offset mismatch");

/* ccStateAdvStartMenuQuestLog: 12 fields, size >= 0x80 (unproven) */
typedef struct {
    uint8_t f_000[7]; /* void * */
    uint8_t f_007[5]; /* uint8_t */
    uint8_t f_00c[1]; /* uint32_t * */
    uint8_t f_00d[1]; /* uint8_t */
    uint8_t f_00e[1]; /* uint8_t */
    uint8_t f_00f[57]; /* uint32_t * */
    uint8_t f_048[12]; /* void * */
    uint8_t f_054[8]; /* uint32_t * */
    uint8_t f_05c[4]; /* uint8_t */
    uint8_t f_060[16]; /* uint32_t * */
    uint8_t f_070[8]; /* int64_t * */
    uint8_t f_078[8]; /* uint32_t * */
} struct_ccStateAdvStartMenuQuestLog_t;

static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_000) == 0x0, "ccStateAdvStartMenuQuestLog::f_000 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_007) == 0x7, "ccStateAdvStartMenuQuestLog::f_007 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_00c) == 0xC, "ccStateAdvStartMenuQuestLog::f_00c offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_00d) == 0xD, "ccStateAdvStartMenuQuestLog::f_00d offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_00e) == 0xE, "ccStateAdvStartMenuQuestLog::f_00e offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_00f) == 0xF, "ccStateAdvStartMenuQuestLog::f_00f offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_048) == 0x48, "ccStateAdvStartMenuQuestLog::f_048 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_054) == 0x54, "ccStateAdvStartMenuQuestLog::f_054 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_05c) == 0x5C, "ccStateAdvStartMenuQuestLog::f_05c offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_060) == 0x60, "ccStateAdvStartMenuQuestLog::f_060 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_070) == 0x70, "ccStateAdvStartMenuQuestLog::f_070 offset mismatch");
static_assert(offsetof(struct_ccStateAdvStartMenuQuestLog_t, f_078) == 0x78, "ccStateAdvStartMenuQuestLog::f_078 offset mismatch");

/* ccStateChallengeMission: 35 fields, size >= 0x148 (unproven) */
typedef struct {
    uint8_t _pad_000[7];
    uint8_t f_007[3]; /* uint8_t */
    uint8_t f_00a[1]; /* uint8_t */
    uint8_t f_00b[6]; /* uint8_t */
    uint8_t f_011[1]; /* uint8_t */
    uint8_t f_012[66]; /* uint8_t */
    uint8_t f_054[12]; /* uint32_t * */
    uint8_t f_060[16]; /* uint32_t * */
    uint8_t f_070[4]; /* int32_t * */
    uint8_t f_074[4]; /* uint32_t * */
    uint8_t f_078[8]; /* uint32_t * */
    uint8_t f_080[8]; /* uint64_t * */
    uint8_t f_088[4]; /* int32_t * */
    uint8_t f_08c[4]; /* int32_t * */
    uint8_t f_090[4]; /* uint32_t * */
    uint8_t f_094[4]; /* uint32_t * */
    uint8_t f_098[4]; /* uint32_t * */
    uint8_t f_09c[4]; /* uint32_t * */
    uint8_t f_0a0[4]; /* uint32_t * */
    uint8_t f_0a4[4]; /* int32_t * */
    uint8_t f_0a8[4]; /* uint32_t * */
    uint8_t f_0ac[4]; /* uint32_t * */
    uint8_t f_0b0[4]; /* uint32_t * */
    uint8_t f_0b4[8]; /* int32_t * */
    uint8_t f_0bc[4]; /* int32_t * */
    uint8_t f_0c0[4]; /* uint32_t * */
    uint8_t f_0c4[12]; /* uint32_t * */
    uint8_t f_0d0[56]; /* uint8_t */
    uint8_t f_108[8]; /* uint32_t * */
    uint8_t f_110[8]; /* uint64_t * */
    uint8_t f_118[8]; /* int64_t * */
    uint8_t f_120[8]; /* uint64_t * */
    uint8_t f_128[8]; /* int64_t ** */
    uint8_t f_130[8]; /* uint64_t * */
    uint8_t f_138[8]; /* int64_t ** */
    uint8_t f_140[8]; /* int64_t ** */
} struct_ccStateChallengeMission_t;

static_assert(offsetof(struct_ccStateChallengeMission_t, f_007) == 0x7, "ccStateChallengeMission::f_007 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_00a) == 0xA, "ccStateChallengeMission::f_00a offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_00b) == 0xB, "ccStateChallengeMission::f_00b offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_011) == 0x11, "ccStateChallengeMission::f_011 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_012) == 0x12, "ccStateChallengeMission::f_012 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_054) == 0x54, "ccStateChallengeMission::f_054 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_060) == 0x60, "ccStateChallengeMission::f_060 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_070) == 0x70, "ccStateChallengeMission::f_070 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_074) == 0x74, "ccStateChallengeMission::f_074 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_078) == 0x78, "ccStateChallengeMission::f_078 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_080) == 0x80, "ccStateChallengeMission::f_080 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_088) == 0x88, "ccStateChallengeMission::f_088 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_08c) == 0x8C, "ccStateChallengeMission::f_08c offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_090) == 0x90, "ccStateChallengeMission::f_090 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_094) == 0x94, "ccStateChallengeMission::f_094 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_098) == 0x98, "ccStateChallengeMission::f_098 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_09c) == 0x9C, "ccStateChallengeMission::f_09c offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0a0) == 0xA0, "ccStateChallengeMission::f_0a0 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0a4) == 0xA4, "ccStateChallengeMission::f_0a4 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0a8) == 0xA8, "ccStateChallengeMission::f_0a8 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0ac) == 0xAC, "ccStateChallengeMission::f_0ac offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0b0) == 0xB0, "ccStateChallengeMission::f_0b0 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0b4) == 0xB4, "ccStateChallengeMission::f_0b4 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0bc) == 0xBC, "ccStateChallengeMission::f_0bc offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0c0) == 0xC0, "ccStateChallengeMission::f_0c0 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0c4) == 0xC4, "ccStateChallengeMission::f_0c4 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_0d0) == 0xD0, "ccStateChallengeMission::f_0d0 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_108) == 0x108, "ccStateChallengeMission::f_108 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_110) == 0x110, "ccStateChallengeMission::f_110 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_118) == 0x118, "ccStateChallengeMission::f_118 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_120) == 0x120, "ccStateChallengeMission::f_120 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_128) == 0x128, "ccStateChallengeMission::f_128 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_130) == 0x130, "ccStateChallengeMission::f_130 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_138) == 0x138, "ccStateChallengeMission::f_138 offset mismatch");
static_assert(offsetof(struct_ccStateChallengeMission_t, f_140) == 0x140, "ccStateChallengeMission::f_140 offset mismatch");

/* ccUiAdv::SelPlate: 2 fields, size >= 0x10 (unproven) */
typedef struct {
    uint8_t f_000[8]; /* void * */
    uint8_t f_008[8]; /* void * */
} struct_ccUiAdv__SelPlate_t;

static_assert(offsetof(struct_ccUiAdv__SelPlate_t, f_000) == 0x0, "ccUiAdv::SelPlate::f_000 offset mismatch");
static_assert(offsetof(struct_ccUiAdv__SelPlate_t, f_008) == 0x8, "ccUiAdv::SelPlate::f_008 offset mismatch");

/* ccUiAdv::SelectedPanel: 1 fields, size >= 0x8 (unproven) */
typedef struct {
    uint8_t f_000[8]; /* void * */
} struct_ccUiAdv__SelectedPanel_t;

static_assert(offsetof(struct_ccUiAdv__SelectedPanel_t, f_000) == 0x0, "ccUiAdv::SelectedPanel::f_000 offset mismatch");

/* ccUiAdvActionCommand: 10 fields, size >= 0xB0 (unproven) */
typedef struct {
    uint8_t f_000[10]; /* void * */
    uint8_t f_00a[7]; /* uint8_t */
    uint8_t f_011[1]; /* uint32_t * */
    uint8_t f_012[38]; /* uint8_t */
    uint8_t f_038[8]; /* int64_t * */
    uint8_t f_040[8]; /* int64_t * */
    uint8_t f_048[64]; /* uint8_t */
    uint8_t f_088[8]; /* int32_t * */
    uint8_t f_090[24]; /* uint8_t */
    uint8_t f_0a8[8]; /* uint64_t * */
} struct_ccUiAdvActionCommand_t;

static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_000) == 0x0, "ccUiAdvActionCommand::f_000 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_00a) == 0xA, "ccUiAdvActionCommand::f_00a offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_011) == 0x11, "ccUiAdvActionCommand::f_011 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_012) == 0x12, "ccUiAdvActionCommand::f_012 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_038) == 0x38, "ccUiAdvActionCommand::f_038 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_040) == 0x40, "ccUiAdvActionCommand::f_040 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_048) == 0x48, "ccUiAdvActionCommand::f_048 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_088) == 0x88, "ccUiAdvActionCommand::f_088 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_090) == 0x90, "ccUiAdvActionCommand::f_090 offset mismatch");
static_assert(offsetof(struct_ccUiAdvActionCommand_t, f_0a8) == 0xA8, "ccUiAdvActionCommand::f_0a8 offset mismatch");

/* ccUiAdvBalloonIcon: 6 fields, size >= 0x2D8 (unproven) */
typedef struct {
    uint8_t _pad_000[4];
    uint8_t f_004[52]; /* uint8_t */
    uint8_t f_038[8]; /* int64_t * */
    uint8_t f_040[4]; /* float * */
    uint8_t f_044[44]; /* float * */
    uint8_t f_070[608]; /* int64_t * */
    uint8_t f_2d0[8]; /* uint64_t ** */
} struct_ccUiAdvBalloonIcon_t;

static_assert(offsetof(struct_ccUiAdvBalloonIcon_t, f_004) == 0x4, "ccUiAdvBalloonIcon::f_004 offset mismatch");
static_assert(offsetof(struct_ccUiAdvBalloonIcon_t, f_038) == 0x38, "ccUiAdvBalloonIcon::f_038 offset mismatch");
static_assert(offsetof(struct_ccUiAdvBalloonIcon_t, f_040) == 0x40, "ccUiAdvBalloonIcon::f_040 offset mismatch");
static_assert(offsetof(struct_ccUiAdvBalloonIcon_t, f_044) == 0x44, "ccUiAdvBalloonIcon::f_044 offset mismatch");
static_assert(offsetof(struct_ccUiAdvBalloonIcon_t, f_070) == 0x70, "ccUiAdvBalloonIcon::f_070 offset mismatch");
static_assert(offsetof(struct_ccUiAdvBalloonIcon_t, f_2d0) == 0x2D0, "ccUiAdvBalloonIcon::f_2d0 offset mismatch");

