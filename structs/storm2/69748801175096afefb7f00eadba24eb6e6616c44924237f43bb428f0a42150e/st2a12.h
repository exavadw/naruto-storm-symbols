/* st2a12.h -- Storm 2 (s2) story/adventure struct layouts */
/* Generated -- INFERRED, not CONFIRMED */
#ifndef ST2A12_H
#define ST2A12_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccAdvStageDraw -- 2 fields */
typedef struct __attribute__((packed)) ccAdvStageDraw {
    uint8_t _pad_0[96];
    uint64_t field_60; /* 0x60 */
    uint32_t field_68; /* 0x68 */
} ccAdvStageDraw;

static_assert(offsetof(ccAdvStageDraw,field_60)==0x60,"ccAdvStageDraw.field_60");
static_assert(offsetof(ccAdvStageDraw,field_68)==0x68,"ccAdvStageDraw.field_68");

/* ccAdvStageParam -- 9 fields */
typedef struct __attribute__((packed)) ccAdvStageParam {
    uint8_t _pad_0[88];
    uint64_t field_58; /* 0x58 */
    uint64_t field_60; /* 0x60 */
    uint8_t field_68; /* 0x68 UNKNOWN */
    uint8_t _pad_69[15];
    uint8_t field_78; /* 0x78 UNKNOWN */
    uint8_t _pad_79[7];
    uint64_t field_80; /* 0x80 */
    uint8_t _pad_88[32];
    uint8_t field_A8; /* 0xA8 UNKNOWN */
    uint8_t _pad_A9[31];
    uint64_t field_C8; /* 0xC8 */
    uint64_t field_D0; /* 0xD0 */
    uint32_t field_D8; /* 0xD8 */
} ccAdvStageParam;

static_assert(offsetof(ccAdvStageParam,field_58)==0x58,"ccAdvStageParam.field_58");
static_assert(offsetof(ccAdvStageParam,field_60)==0x60,"ccAdvStageParam.field_60");
static_assert(offsetof(ccAdvStageParam,field_68)==0x68,"ccAdvStageParam.field_68");
static_assert(offsetof(ccAdvStageParam,field_78)==0x78,"ccAdvStageParam.field_78");
static_assert(offsetof(ccAdvStageParam,field_80)==0x80,"ccAdvStageParam.field_80");
static_assert(offsetof(ccAdvStageParam,field_A8)==0xA8,"ccAdvStageParam.field_A8");
static_assert(offsetof(ccAdvStageParam,field_C8)==0xC8,"ccAdvStageParam.field_C8");
static_assert(offsetof(ccAdvStageParam,field_D0)==0xD0,"ccAdvStageParam.field_D0");
static_assert(offsetof(ccAdvStageParam,field_D8)==0xD8,"ccAdvStageParam.field_D8");

/* ccAdvSupportBehavior -- 2 fields */
typedef struct __attribute__((packed)) ccAdvSupportBehavior {
    uint8_t _pad_0[5304];
    uint64_t field_14B8; /* 0x14B8 */
    uint64_t field_14C0; /* 0x14C0 */
} ccAdvSupportBehavior;

static_assert(offsetof(ccAdvSupportBehavior,field_14B8)==0x14B8,"ccAdvSupportBehavior.field_14B8");
static_assert(offsetof(ccAdvSupportBehavior,field_14C0)==0x14C0,"ccAdvSupportBehavior.field_14C0");

/* ccAdvSupportDraw: no fields */
typedef struct ccAdvSupportDraw { uint8_t _empty; } ccAdvSupportDraw;

/* ccAdvSupportParam -- 17 fields */
typedef struct __attribute__((packed)) ccAdvSupportParam {
    uint8_t _pad_0[20];
    uint32_t field_14; /* 0x14 */
    uint8_t _pad_18[12];
    uint8_t field_24; /* 0x24 UNKNOWN */
    uint8_t _pad_25[2083];
    uint8_t field_848; /* 0x848 UNKNOWN */
    uint8_t _pad_849[1423];
    uint64_t field_DD8; /* 0xDD8 */
    uint8_t field_DE0; /* 0xDE0 UNKNOWN */
    uint8_t _pad_DE1[1423];
    uint64_t field_1370; /* 0x1370 */
    uint32_t field_1378; /* 0x1378 */
    uint8_t field_137C; /* 0x137C UNKNOWN */
    uint8_t _pad_137D[11];
    uint8_t field_1388; /* 0x1388 UNKNOWN */
    uint8_t _pad_1389[39];
    uint8_t field_13B0; /* 0x13B0 UNKNOWN */
    uint8_t _pad_13B1[239];
    uint8_t field_14A0; /* 0x14A0 UNKNOWN */
    uint8_t _pad_14A1[11];
    uint32_t field_14AC; /* 0x14AC */
    uint64_t field_14B0; /* 0x14B0 */
    uint64_t field_14B8; /* 0x14B8 */
    uint64_t field_14C0; /* 0x14C0 */
    uint64_t field_14C8; /* 0x14C8 */
    uint8_t _pad_14D0[16];
    uint32_t field_14E0; /* 0x14E0 */
} ccAdvSupportParam;

static_assert(offsetof(ccAdvSupportParam,field_14)==0x14,"ccAdvSupportParam.field_14");
static_assert(offsetof(ccAdvSupportParam,field_24)==0x24,"ccAdvSupportParam.field_24");
static_assert(offsetof(ccAdvSupportParam,field_848)==0x848,"ccAdvSupportParam.field_848");
static_assert(offsetof(ccAdvSupportParam,field_DD8)==0xDD8,"ccAdvSupportParam.field_DD8");
static_assert(offsetof(ccAdvSupportParam,field_DE0)==0xDE0,"ccAdvSupportParam.field_DE0");
static_assert(offsetof(ccAdvSupportParam,field_1370)==0x1370,"ccAdvSupportParam.field_1370");
static_assert(offsetof(ccAdvSupportParam,field_1378)==0x1378,"ccAdvSupportParam.field_1378");
static_assert(offsetof(ccAdvSupportParam,field_137C)==0x137C,"ccAdvSupportParam.field_137C");
static_assert(offsetof(ccAdvSupportParam,field_1388)==0x1388,"ccAdvSupportParam.field_1388");
static_assert(offsetof(ccAdvSupportParam,field_13B0)==0x13B0,"ccAdvSupportParam.field_13B0");
static_assert(offsetof(ccAdvSupportParam,field_14A0)==0x14A0,"ccAdvSupportParam.field_14A0");
static_assert(offsetof(ccAdvSupportParam,field_14AC)==0x14AC,"ccAdvSupportParam.field_14AC");
static_assert(offsetof(ccAdvSupportParam,field_14B0)==0x14B0,"ccAdvSupportParam.field_14B0");
static_assert(offsetof(ccAdvSupportParam,field_14B8)==0x14B8,"ccAdvSupportParam.field_14B8");
static_assert(offsetof(ccAdvSupportParam,field_14C0)==0x14C0,"ccAdvSupportParam.field_14C0");
static_assert(offsetof(ccAdvSupportParam,field_14C8)==0x14C8,"ccAdvSupportParam.field_14C8");
static_assert(offsetof(ccAdvSupportParam,field_14E0)==0x14E0,"ccAdvSupportParam.field_14E0");

/* ccAdvSupportSensor -- 14 fields */
typedef struct __attribute__((packed)) ccAdvSupportSensor {
    uint8_t _pad_0[20];
    uint64_t field_14; /* 0x14 */
    uint8_t field_1C; /* 0x1C UNKNOWN */
    uint8_t _pad_1D[67];
    uint64_t field_60; /* 0x60 */
    uint64_t field_68; /* 0x68 */
    uint64_t field_70; /* 0x70 */
    uint64_t field_78; /* 0x78 */
    uint8_t _pad_80[16];
    uint64_t field_90; /* 0x90 */
    uint64_t field_98; /* 0x98 */
    uint64_t field_A0; /* 0xA0 */
    uint64_t field_A8; /* 0xA8 */
    uint8_t _pad_B0[16];
    uint64_t field_C0; /* 0xC0 */
    uint64_t field_C8; /* 0xC8 */
    uint64_t field_D0; /* 0xD0 */
    uint64_t field_D8; /* 0xD8 */
} ccAdvSupportSensor;

static_assert(offsetof(ccAdvSupportSensor,field_14)==0x14,"ccAdvSupportSensor.field_14");
static_assert(offsetof(ccAdvSupportSensor,field_1C)==0x1C,"ccAdvSupportSensor.field_1C");
static_assert(offsetof(ccAdvSupportSensor,field_60)==0x60,"ccAdvSupportSensor.field_60");
static_assert(offsetof(ccAdvSupportSensor,field_68)==0x68,"ccAdvSupportSensor.field_68");
static_assert(offsetof(ccAdvSupportSensor,field_70)==0x70,"ccAdvSupportSensor.field_70");
static_assert(offsetof(ccAdvSupportSensor,field_78)==0x78,"ccAdvSupportSensor.field_78");
static_assert(offsetof(ccAdvSupportSensor,field_90)==0x90,"ccAdvSupportSensor.field_90");
static_assert(offsetof(ccAdvSupportSensor,field_98)==0x98,"ccAdvSupportSensor.field_98");
static_assert(offsetof(ccAdvSupportSensor,field_A0)==0xA0,"ccAdvSupportSensor.field_A0");
static_assert(offsetof(ccAdvSupportSensor,field_A8)==0xA8,"ccAdvSupportSensor.field_A8");
static_assert(offsetof(ccAdvSupportSensor,field_C0)==0xC0,"ccAdvSupportSensor.field_C0");
static_assert(offsetof(ccAdvSupportSensor,field_C8)==0xC8,"ccAdvSupportSensor.field_C8");
static_assert(offsetof(ccAdvSupportSensor,field_D0)==0xD0,"ccAdvSupportSensor.field_D0");
static_assert(offsetof(ccAdvSupportSensor,field_D8)==0xD8,"ccAdvSupportSensor.field_D8");

/* ccAdvSupportState -- 19 fields */
typedef struct __attribute__((packed)) ccAdvSupportState {
    uint8_t _pad_0[5304];
    uint8_t field_14B8; /* 0x14B8 UNKNOWN */
    uint8_t _pad_14B9[7];
    uint64_t field_14C0; /* 0x14C0 */
    uint64_t field_14C8; /* 0x14C8 */
    uint64_t field_14D0; /* 0x14D0 */
    uint8_t _pad_14D8[16];
    uint64_t field_14E8; /* 0x14E8 */
    uint64_t field_14F0; /* 0x14F0 */
    uint64_t field_14F8; /* 0x14F8 */
    uint8_t field_1500; /* 0x1500 UNKNOWN */
    uint8_t _pad_1501[11];
    uint32_t field_150C; /* 0x150C */
    uint8_t field_1510; /* 0x1510 UNKNOWN */
    uint8_t _pad_1511[5303];
    uint64_t field_29C8; /* 0x29C8 */
    uint8_t _pad_29D0[8];
    uint8_t field_29D8; /* 0x29D8 UNKNOWN */
    uint8_t _pad_29D9[5303];
    uint64_t field_3E90; /* 0x3E90 */
    uint8_t field_3E98; /* 0x3E98 UNKNOWN */
    uint8_t _pad_3E99[5303];
    uint64_t field_5350; /* 0x5350 */
    uint32_t field_5358; /* 0x5358 */
    uint8_t _pad_535C[4];
    uint64_t field_5360; /* 0x5360 */
    uint8_t field_5368; /* 0x5368 UNKNOWN */
    uint8_t _pad_5369[15];
    uint32_t field_5378; /* 0x5378 */
} ccAdvSupportState;

static_assert(offsetof(ccAdvSupportState,field_14B8)==0x14B8,"ccAdvSupportState.field_14B8");
static_assert(offsetof(ccAdvSupportState,field_14C0)==0x14C0,"ccAdvSupportState.field_14C0");
static_assert(offsetof(ccAdvSupportState,field_14C8)==0x14C8,"ccAdvSupportState.field_14C8");
static_assert(offsetof(ccAdvSupportState,field_14D0)==0x14D0,"ccAdvSupportState.field_14D0");
static_assert(offsetof(ccAdvSupportState,field_14E8)==0x14E8,"ccAdvSupportState.field_14E8");
static_assert(offsetof(ccAdvSupportState,field_14F0)==0x14F0,"ccAdvSupportState.field_14F0");
static_assert(offsetof(ccAdvSupportState,field_14F8)==0x14F8,"ccAdvSupportState.field_14F8");
static_assert(offsetof(ccAdvSupportState,field_1500)==0x1500,"ccAdvSupportState.field_1500");
static_assert(offsetof(ccAdvSupportState,field_150C)==0x150C,"ccAdvSupportState.field_150C");
static_assert(offsetof(ccAdvSupportState,field_1510)==0x1510,"ccAdvSupportState.field_1510");
static_assert(offsetof(ccAdvSupportState,field_29C8)==0x29C8,"ccAdvSupportState.field_29C8");
static_assert(offsetof(ccAdvSupportState,field_29D8)==0x29D8,"ccAdvSupportState.field_29D8");
static_assert(offsetof(ccAdvSupportState,field_3E90)==0x3E90,"ccAdvSupportState.field_3E90");
static_assert(offsetof(ccAdvSupportState,field_3E98)==0x3E98,"ccAdvSupportState.field_3E98");
static_assert(offsetof(ccAdvSupportState,field_5350)==0x5350,"ccAdvSupportState.field_5350");
static_assert(offsetof(ccAdvSupportState,field_5358)==0x5358,"ccAdvSupportState.field_5358");
static_assert(offsetof(ccAdvSupportState,field_5360)==0x5360,"ccAdvSupportState.field_5360");
static_assert(offsetof(ccAdvSupportState,field_5368)==0x5368,"ccAdvSupportState.field_5368");
static_assert(offsetof(ccAdvSupportState,field_5378)==0x5378,"ccAdvSupportState.field_5378");

/* ccAdvUi: no fields */
typedef struct ccAdvUi { uint8_t _empty; } ccAdvUi;

/* ccAdvUiAnmMobDraw: no fields */
typedef struct ccAdvUiAnmMobDraw { uint8_t _empty; } ccAdvUiAnmMobDraw;

/* ccAdvUiStatus -- 3 fields */
typedef struct __attribute__((packed)) ccAdvUiStatus {
    uint8_t _pad_0[12];
    uint32_t field_C; /* 0xC */
    uint8_t _pad_10[136];
    uint8_t field_98; /* 0x98 */
    uint8_t _pad_99[127];
    uint8_t field_118; /* 0x118 UNKNOWN */
} ccAdvUiStatus;

static_assert(offsetof(ccAdvUiStatus,field_C)==0xC,"ccAdvUiStatus.field_C");
static_assert(offsetof(ccAdvUiStatus,field_98)==0x98,"ccAdvUiStatus.field_98");
static_assert(offsetof(ccAdvUiStatus,field_118)==0x118,"ccAdvUiStatus.field_118");

/* Absent from s2: */
/* ccAdvSupportCharaLoad */
/* ccAdvSupportEmotion */
/* ccAdvSupportGimmickInfo */
/* ccAdvSupportLookAt */

#endif /* ST2A12_H */
