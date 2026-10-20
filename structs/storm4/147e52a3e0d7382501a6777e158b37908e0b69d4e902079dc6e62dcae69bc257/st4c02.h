/*
 * st4c02.h — Story cutscene/event struct layouts for NARUTO STORM 4 PC 1.09 (s4)
 *
 * All layouts are INFERRED from static analysis (decompilation + state_surface).
 * No runtime confirmation. Sizes are lower bounds unless proven by operator new.
 * Field names come from Storm 4 symbols/strings only (own-game rule).
 *
 * Build: s4 / NSUNS4_release.exe-75912b / sha256 147e52a3e0d7...
 * Image base: 0x140000000
 */

#ifndef ST4C02_H
#define ST4C02_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* Common engine types (size-only, no field layout assumed)           */
/* ------------------------------------------------------------------ */

typedef struct { float x, y, z; } st4c02_Vector3; /* 12 bytes */

/* Memory::BlockAllocator — opaque, 0x28 bytes inferred from usage patterns */
typedef struct { uint8_t _data[0x28]; } st4c02_BlockAllocator;

/* ------------------------------------------------------------------ */
/* ccCameraOperatorGroupEvent                                         */
/* Parent: ccCmnCameraOperator                                        */
/* Vtable: PTR_FUN_140ff56d8                                          */
/* Size: unknown, >= 0x1DC                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t              parent_ccCmnCameraOperator[0x1B0]; /* 0x000 */
    int32_t              field_1B0;                          /* 0x1B0 */
    st4c02_Vector3       vec_1B4;                            /* 0x1B4 */
    uint32_t             pad_1C0;                            /* 0x1C0 */
    uint32_t             pad_1C4;                            /* 0x1C4 */
    st4c02_Vector3       vec_1C8;                            /* 0x1C8 */
    uint32_t             field_1D4;                          /* 0x1D4 */
    uint32_t             field_1D8;                          /* 0x1D8 */
} st4c02_ccCameraOperatorGroupEvent;

static_assert(offsetof(st4c02_ccCameraOperatorGroupEvent, field_1B0) == 0x1B0, "ccCameraOperatorGroupEvent.field_1B0");
static_assert(offsetof(st4c02_ccCameraOperatorGroupEvent, vec_1B4)   == 0x1B4, "ccCameraOperatorGroupEvent.vec_1B4");
static_assert(offsetof(st4c02_ccCameraOperatorGroupEvent, vec_1C8)   == 0x1C8, "ccCameraOperatorGroupEvent.vec_1C8");
static_assert(offsetof(st4c02_ccCameraOperatorGroupEvent, field_1D4) == 0x1D4, "ccCameraOperatorGroupEvent.field_1D4");
static_assert(offsetof(st4c02_ccCameraOperatorGroupEvent, field_1D8) == 0x1D8, "ccCameraOperatorGroupEvent.field_1D8");

/* ------------------------------------------------------------------ */
/* ccCpuPlayerGroupScript                                             */
/* Parent: ccCpuPlayer                                                */
/* Vtable: PTR_FUN_140ff6d78                                          */
/* Size: unknown, >= 0x1990                                           */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t               parent_ccCpuPlayer[0x1980];        /* 0x0000 */
    int32_t               field_1980;                         /* 0x1980 */
    uint32_t              pad_1984;                           /* 0x1984 */
    st4c02_BlockAllocator blockAlloc_1988;                    /* 0x1988 */
} st4c02_ccCpuPlayerGroupScript;

static_assert(offsetof(st4c02_ccCpuPlayerGroupScript, field_1980)    == 0x1980, "ccCpuPlayerGroupScript.field_1980");
static_assert(offsetof(st4c02_ccCpuPlayerGroupScript, blockAlloc_1988) == 0x1988, "ccCpuPlayerGroupScript.blockAlloc_1988");

/* ------------------------------------------------------------------ */
/* ccEventAnmState                                                    */
/* Parent: ccTaskBase                                                 */
/* Vtable: PTR_FUN_1410097d8                                          */
/* Size: unknown, >= 0x500                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_ccTaskBase[0x68];                        /* 0x000 */
    int32_t  field_68;                                       /* 0x068 */
    uint32_t pad_6C;                                         /* 0x06C */
    int64_t  field_70;                                       /* 0x070 */
    uint8_t  gap_78[0x30];                                   /* 0x078 */
    int64_t  field_A8;                                       /* 0x0A8 */
    uint8_t  gap_B0[0x158];                                  /* 0x0B0 */
    int32_t  field_208;                                      /* 0x208 */
    uint8_t  gap_20C[0x1C];                                  /* 0x20C */
    uint8_t  memset_region_228[0x90];                        /* 0x228 - cleared in ctor */
    uint8_t  gap_2B8[0x240];                                 /* 0x2B8 */
    int32_t  field_4F8;                                      /* 0x4F8 */
    uint32_t pad_4FC;                                        /* 0x4FC */
} st4c02_ccEventAnmState;

static_assert(offsetof(st4c02_ccEventAnmState, field_68)          == 0x068, "ccEventAnmState.field_68");
static_assert(offsetof(st4c02_ccEventAnmState, field_70)          == 0x070, "ccEventAnmState.field_70");
static_assert(offsetof(st4c02_ccEventAnmState, field_A8)          == 0x0A8, "ccEventAnmState.field_A8");
static_assert(offsetof(st4c02_ccEventAnmState, field_208)         == 0x208, "ccEventAnmState.field_208");
static_assert(offsetof(st4c02_ccEventAnmState, memset_region_228) == 0x228, "ccEventAnmState.memset_region_228");
static_assert(offsetof(st4c02_ccEventAnmState, field_4F8)         == 0x4F8, "ccEventAnmState.field_4F8");

/* ------------------------------------------------------------------ */
/* ccEventCamera                                                      */
/* Parent: ccCmnCameraOperator                                        */
/* Vtable: PTR_FUN_141002298                                          */
/* Size: unknown, >= 0x2AC                                            */
/* Contains embedded ccEventCameraState at offset 0x1B0               */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_ccCmnCameraOperator[0x1B0];              /* 0x000 */
    uint8_t  embedded_ccEventCameraState[0xF8];              /* 0x1B0 - see ccEventCameraState */
    uint8_t  gap_2A8[0x04];                                  /* 0x2A8 */
} st4c02_ccEventCamera;

static_assert(offsetof(st4c02_ccEventCamera, embedded_ccEventCameraState) == 0x1B0, "ccEventCamera.embedded_ccEventCameraState");
static_assert(offsetof(st4c02_ccEventCamera, gap_2A8)                     == 0x2A8, "ccEventCamera.gap_2A8");

/* ------------------------------------------------------------------ */
/* ccEventCameraState                                                 */
/* Parent: ccTaskBase                                                 */
/* Vtable: PTR_FUN_141002358                                          */
/* Size: unknown, >= 0x158                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_ccTaskBase[0x6C];                        /* 0x000 */
    int32_t  field_6C;                                       /* 0x06C */
    uint8_t  gap_70[0x50];                                   /* 0x070 */
    uint8_t  memset_region_C0[0x90];                         /* 0x0C0 - cleared in Create (includes fov/near_clip) */
    uint8_t  gap_150[0x04];                                  /* 0x150 */
    int32_t  field_154;                                      /* 0x154 */
    uint32_t pad_158;                                        /* 0x158 */
} st4c02_ccEventCameraState;

static_assert(offsetof(st4c02_ccEventCameraState, field_6C)        == 0x06C, "ccEventCameraState.field_6C");
static_assert(offsetof(st4c02_ccEventCameraState, memset_region_C0)== 0x0C0, "ccEventCameraState.memset_region_C0");
static_assert(offsetof(st4c02_ccEventCameraState, field_154)       == 0x154, "ccEventCameraState.field_154");

/* ------------------------------------------------------------------ */
/* ccDemoCtrl                                                         */
/* Parent: unknown (likely ccTaskBase)                                */
/* Size: unknown, >= 0xAC                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_base[0x68];                              /* 0x000 */
    int32_t  field_68;                                       /* 0x068 */
    uint8_t  gap_6C[0x3C];                                   /* 0x06C */
    int32_t  field_A8;                                       /* 0x0A8 */
    uint32_t pad_AC;                                         /* 0x0AC */
} st4c02_ccDemoCtrl;

static_assert(offsetof(st4c02_ccDemoCtrl, field_68) == 0x068, "ccDemoCtrl.field_68");
static_assert(offsetof(st4c02_ccDemoCtrl, field_A8) == 0x0A8, "ccDemoCtrl.field_A8");

/* ------------------------------------------------------------------ */
/* ccDemoParamManager                                                 */
/* Parent: unknown                                                    */
/* Size: unknown, >= 0x34                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_base[0x08];                              /* 0x000 */
    int64_t  xfbin_ptr_8;                                    /* 0x008 - CalcAddressNew result */
    uint8_t  gap_10[0x20];                                   /* 0x010 */
    int32_t  field_30;                                       /* 0x030 */
    uint32_t pad_34;                                         /* 0x034 */
} st4c02_ccDemoParamManager;

static_assert(offsetof(st4c02_ccDemoParamManager, xfbin_ptr_8) == 0x008, "ccDemoParamManager.xfbin_ptr_8");
static_assert(offsetof(st4c02_ccDemoParamManager, field_30)    == 0x030, "ccDemoParamManager.field_30");

/* ------------------------------------------------------------------ */
/* ccDuelEndDemo                                                      */
/* Parent: unknown                                                    */
/* Size: unknown, >= 0x4C                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_base[0x08];                              /* 0x000 */
    int32_t  field_8;                                        /* 0x008 - set to -1 in Initialize */
    uint32_t pad_C;                                          /* 0x00C */
    uint8_t  gap_10[0x10];                                   /* 0x010 */
    int64_t  field_20;                                       /* 0x020 */
    int64_t  field_28;                                       /* 0x028 */
    int64_t  field_30;                                       /* 0x030 - passed to ccUiBattleEndDemo ctor */
    int64_t  field_38;                                       /* 0x038 */
    int64_t  field_40;                                       /* 0x040 */
    int64_t  field_48;                                       /* 0x048 - FUN_140740954 result */
} st4c02_ccDuelEndDemo;

static_assert(offsetof(st4c02_ccDuelEndDemo, field_8)  == 0x008, "ccDuelEndDemo.field_8");
static_assert(offsetof(st4c02_ccDuelEndDemo, field_20) == 0x020, "ccDuelEndDemo.field_20");
static_assert(offsetof(st4c02_ccDuelEndDemo, field_28) == 0x028, "ccDuelEndDemo.field_28");
static_assert(offsetof(st4c02_ccDuelEndDemo, field_30) == 0x030, "ccDuelEndDemo.field_30");
static_assert(offsetof(st4c02_ccDuelEndDemo, field_38) == 0x038, "ccDuelEndDemo.field_38");
static_assert(offsetof(st4c02_ccDuelEndDemo, field_48) == 0x048, "ccDuelEndDemo.field_48");

/* ------------------------------------------------------------------ */
/* ccEventBlurState                                                   */
/* Parent: unknown (likely ccTaskBase)                                */
/* Size: unknown, >= 0xD0                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) {
    uint8_t  parent_base[0x7C];                              /* 0x000 */
    int32_t  blur_param_7C;                                  /* 0x07C - SetParameter arg */
    int32_t  blur_saved_80;                                  /* 0x080 - saved CmnBlurParam+0x14 */
    uint8_t  gap_84[0xC];                                    /* 0x084 */
    int32_t  field_90;                                       /* 0x090 - written in StateMotionBlur */
    int32_t  threshold_94;                                   /* 0x094 - compared against field_A8 */
    uint8_t  gap_98[0x10];                                   /* 0x098 */
    int32_t  field_A8;                                       /* 0x0A8 - loop bound */
    uint8_t  gap_AC[0x20];                                   /* 0x0AC */
    int32_t  mot_blur_enable_CC;                             /* 0x0CC - SetMotBlurEnable arg */
    uint32_t pad_D0;                                         /* 0x0D0 */
} st4c02_ccEventBlurState;

static_assert(offsetof(st4c02_ccEventBlurState, blur_param_7C)      == 0x07C, "ccEventBlurState.blur_param_7C");
static_assert(offsetof(st4c02_ccEventBlurState, blur_saved_80)      == 0x080, "ccEventBlurState.blur_saved_80");
static_assert(offsetof(st4c02_ccEventBlurState, field_90)           == 0x090, "ccEventBlurState.field_90");
static_assert(offsetof(st4c02_ccEventBlurState, threshold_94)       == 0x094, "ccEventBlurState.threshold_94");
static_assert(offsetof(st4c02_ccEventBlurState, field_A8)           == 0x0A8, "ccEventBlurState.field_A8");
static_assert(offsetof(st4c02_ccEventBlurState, mot_blur_enable_CC) == 0x0CC, "ccEventBlurState.mot_blur_enable_CC");

#endif /* ST4C02_H */