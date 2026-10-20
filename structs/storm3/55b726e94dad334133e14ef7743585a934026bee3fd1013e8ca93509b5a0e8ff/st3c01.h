/*
 * st3c01.h — Story cutscene/event classes for NARUTO STORM 3 Full Burst HD (s3, NSUNS3.exe x64)
 *
 * INFERRED layout from static decompilation of build s3. NOT CONFIRMED at runtime.
 * All offsets derived from PC x64 code (image base 0x140000000).
 * Sizes proven only where operator-new / factory LoadTh argument was found.
 *
 * Rollback tags: PRES = preserved across rollback snapshot; SIM = simulated; UNKNOWN = no evidence.
 */
#ifndef ST3C01_H
#define ST3C01_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Minimal std::string layout for MSVC x64 (SSO 16 bytes inline) */
typedef struct __attribute__((packed)) st3c01_std_string {
    char   inline_buf[16]; /* 0x00 */
    size_t size;           /* 0x10 */
    size_t capacity;       /* 0x18 */
} st3c01_std_string;

/* Minimal Vector3 (Nucc::Vector3) */
typedef struct __attribute__((packed)) st3c01_vector3 {
    float x; /* 0x00 */
    float y; /* 0x04 */
    float z; /* 0x08 */
} st3c01_vector3;

/* Block allocator placeholder (16 bytes, internal cc2 engine structure) */
typedef struct __attribute__((packed)) st3c01_block_alloc {
    uint8_t data[16];
} st3c01_block_alloc;

/* vector<int32> placeholder (24 bytes: begin, end, capacity) */
typedef struct __attribute__((packed)) st3c01_vector_int32 {
    int32_t *begin;    /* 0x00 */
    int32_t *end;      /* 0x08 */
    int32_t *capacity; /* 0x10 */
} st3c01_vector_int32;

/* ========================================================================
 * ccAdvBattleEndSequence
 * Size: unknown, >= 0x10
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvBattleEndSequence {
    uint8_t vtable_or_base[8]; /* 0x0000 — vptr or base class data */
    void   *pInner;            /* 0x0008 — ptr, read in IsEnd */
    /* end of proven fields */
} st3c01_ccAdvBattleEndSequence;

static_assert(offsetof(st3c01_ccAdvBattleEndSequence, pInner) == 0x0008,
              "ccAdvBattleEndSequence::pInner offset");

/* ========================================================================
 * ccAdvLiveTalkActor
 * Size: unknown, >= 0x6C
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvLiveTalkActor {
    uint8_t          vtable_or_base[8]; /* 0x0000 */
    int32_t          chapter;           /* 0x0008 — rw, Ctrl compares */
    int32_t          field_0C;          /* 0x000C — rw, cleared in Ctrl */
    st3c01_std_string areaName;         /* 0x0010 — rw, std::string (24 bytes) */
    /* areaName.capacity is at 0x0028 inside the embedded std_string */
    uint8_t          pad_0030[24];      /* 0x0030 — gap to 0x0048 */
    int32_t          param_2_store;     /* 0x0048 — w, stores ctor/Ctrl arg */
    uint8_t          pad_004C[12];      /* 0x004C — gap to 0x0058 */
    int32_t          field_58;          /* 0x0058 — w, cleared */
    int32_t          field_5C;          /* 0x005C — rw, cleared */
    float            timer;             /* 0x0060 — rw, float timer */
    int32_t          field_64;          /* 0x0064 — w, cleared */
    int32_t          field_68;          /* 0x0068 — w, cleared */
    /* end of proven fields at 0x6C */
} st3c01_ccAdvLiveTalkActor;

static_assert(offsetof(st3c01_ccAdvLiveTalkActor, chapter) == 0x0008,
              "ccAdvLiveTalkActor::chapter offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, field_0C) == 0x000C,
              "ccAdvLiveTalkActor::field_0C offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, areaName) == 0x0010,
              "ccAdvLiveTalkActor::areaName offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, param_2_store) == 0x0048,
              "ccAdvLiveTalkActor::param_2_store offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, field_58) == 0x0058,
              "ccAdvLiveTalkActor::field_58 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, field_5C) == 0x005C,
              "ccAdvLiveTalkActor::field_5C offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, timer) == 0x0060,
              "ccAdvLiveTalkActor::timer offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, field_64) == 0x0064,
              "ccAdvLiveTalkActor::field_64 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkActor, field_68) == 0x0068,
              "ccAdvLiveTalkActor::field_68 offset");

/* ========================================================================
 * ccAdvMotionEvent
 * Size: unknown, >= 0x30
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvMotionEvent {
    uint8_t vtable_or_base[8]; /* 0x0000 */
    uint32_t field_08;         /* 0x0008 — rw, byteswapped in Parse */
    uint32_t field_0C;         /* 0x000C — rw, byteswapped in Parse */
    uint32_t entrySize;        /* 0x0010 — rw, byteswapped in Parse */
    int32_t  entryCount;       /* 0x0014 — rw, cleared in Clear */
    void    *entries;          /* 0x0018 — ptr, freed in Clear */
    int32_t  field_20;         /* 0x0020 — w, cleared in Clear */
    uint8_t  pad_0024[4];      /* 0x0024 — alignment */
    void    *binaryData;       /* 0x0028 — ptr, freed in Clear */
    /* end of proven fields at 0x30 */
} st3c01_ccAdvMotionEvent;

static_assert(offsetof(st3c01_ccAdvMotionEvent, field_08) == 0x0008,
              "ccAdvMotionEvent::field_08 offset");
static_assert(offsetof(st3c01_ccAdvMotionEvent, field_0C) == 0x000C,
              "ccAdvMotionEvent::field_0C offset");
static_assert(offsetof(st3c01_ccAdvMotionEvent, entrySize) == 0x0010,
              "ccAdvMotionEvent::entrySize offset");
static_assert(offsetof(st3c01_ccAdvMotionEvent, entryCount) == 0x0014,
              "ccAdvMotionEvent::entryCount offset");
static_assert(offsetof(st3c01_ccAdvMotionEvent, entries) == 0x0018,
              "ccAdvMotionEvent::entries offset");
static_assert(offsetof(st3c01_ccAdvMotionEvent, field_20) == 0x0020,
              "ccAdvMotionEvent::field_20 offset");
static_assert(offsetof(st3c01_ccAdvMotionEvent, binaryData) == 0x0028,
              "ccAdvMotionEvent::binaryData offset");

/* ========================================================================
 * ccAdvMotionEventCategory
 * Size: unknown, >= 0x20
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvMotionEventCategory {
    uint8_t  vtable_or_base[8]; /* 0x0000 */
    void    *rawData;           /* 0x0008 — ptr, memcpy in Parse */
    int32_t  dataCount;         /* 0x0010 — rw, byteswapped in Parse */
    uint8_t  pad_0014[4];       /* 0x0014 — alignment */
    void   **dataArray;         /* 0x0018 — ptr to array, parsed loop */
    /* end of proven fields at 0x20 */
} st3c01_ccAdvMotionEventCategory;

static_assert(offsetof(st3c01_ccAdvMotionEventCategory, rawData) == 0x0008,
              "ccAdvMotionEventCategory::rawData offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCategory, dataCount) == 0x0010,
              "ccAdvMotionEventCategory::dataCount offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCategory, dataArray) == 0x0018,
              "ccAdvMotionEventCategory::dataArray offset");

/* ========================================================================
 * ccAdvMotionEventCommand
 * Size: unknown, >= 0x44
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvMotionEventCommand {
    uint8_t          vtable_or_base[8]; /* 0x0000 */
    float            time;              /* 0x0008 — rw, float from Parse */
    int32_t          hasSound;          /* 0x000C — rw */
    int32_t          seCode;            /* 0x0010 — rw, ccSoundTable::GetSeCode */
    uint8_t          pad_0014[4];       /* 0x0014 — alignment */
    void            *motionName;        /* 0x0018 — ptr */
    uint32_t         flags;             /* 0x0020 — rw */
    uint8_t          pad_0024[4];       /* 0x0024 — alignment */
    void            *field_28;          /* 0x0028 — ptr */
    void            *field_30;          /* 0x0030 — ptr */
    st3c01_vector3   position;          /* 0x0038 — Vector3 (12 bytes, x/y/z) */
    /* field_40 at 0x0040 overlaps position.z (0x38+8); decompiler reads it as int32
       separately but it occupies the same memory. Not duplicated here. */
    /* end of proven fields at 0x44 */
} st3c01_ccAdvMotionEventCommand;

static_assert(offsetof(st3c01_ccAdvMotionEventCommand, time) == 0x0008,
              "ccAdvMotionEventCommand::time offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, hasSound) == 0x000C,
              "ccAdvMotionEventCommand::hasSound offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, seCode) == 0x0010,
              "ccAdvMotionEventCommand::seCode offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, motionName) == 0x0018,
              "ccAdvMotionEventCommand::motionName offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, flags) == 0x0020,
              "ccAdvMotionEventCommand::flags offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, field_28) == 0x0028,
              "ccAdvMotionEventCommand::field_28 offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, field_30) == 0x0030,
              "ccAdvMotionEventCommand::field_30 offset");
static_assert(offsetof(st3c01_ccAdvMotionEventCommand, position) == 0x0038,
              "ccAdvMotionEventCommand::position offset");

/* ========================================================================
 * ccAdvMotionEventData
 * Size: unknown, >= 0x20
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvMotionEventData {
    uint8_t  vtable_or_base[8]; /* 0x0000 */
    void    *rawName;           /* 0x0008 — ptr, memcpy in Parse */
    int32_t  commandCount;      /* 0x0010 — rw, byteswapped */
    uint8_t  pad_0014[4];       /* 0x0014 — alignment */
    void   **commands;          /* 0x0018 — ptr to array, stride 0x48 */
    /* end of proven fields at 0x20 */
} st3c01_ccAdvMotionEventData;

static_assert(offsetof(st3c01_ccAdvMotionEventData, rawName) == 0x0008,
              "ccAdvMotionEventData::rawName offset");
static_assert(offsetof(st3c01_ccAdvMotionEventData, commandCount) == 0x0010,
              "ccAdvMotionEventData::commandCount offset");
static_assert(offsetof(st3c01_ccAdvMotionEventData, commands) == 0x0018,
              "ccAdvMotionEventData::commands offset");

/* ========================================================================
 * ccAdvEventManager
 * Size: 0x268 (proven via LoadTh(0x268) in ccAdvManager::CreateGameManager)
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvEventManager {
    uint8_t base[0x70];         /* 0x0000 — base class / vtable region */
    int64_t field_70;           /* 0x0070 — w, zeroed in ctor */
    uint8_t pad_0078[296];      /* 0x0078 — gap to 0x01A0 (0x1A0-0x78=0x128=296) */
    uint8_t flag_1A0;           /* 0x01A0 — rw byte flag */
    uint8_t pad_01A1[15];       /* 0x01A1 — gap to 0x01B0 (0x1B0-0x1A1=15) */
    int64_t field_1B0;          /* 0x01B0 — w, zeroed in dtor */
    int64_t field_1B8;          /* 0x01B8 — rw, capacity check in dtor */
    void   *field_1C0;          /* 0x01C0 — ptr, freed in dtor */
    uint8_t pad_01C8[120];      /* 0x01C8 — gap to 0x0240 (0x240-0x1C8=0x78=120) */
    int64_t field_240;          /* 0x0240 — w, zeroed in ctor */
    int64_t field_248;          /* 0x0248 — rw, CheckSpecialMissionBird */
    int32_t field_250;          /* 0x0250 — w, zeroed in ctor */
    int64_t field_254;          /* 0x0254 — w, set to 1 in ctor (packed, unaligned) */
    uint8_t pad_025C[4];        /* 0x025C — gap to 0x0260 (0x260-0x25C=4) */
    int64_t field_260;          /* 0x0260 — rw, high confidence */
} st3c01_ccAdvEventManager;

static_assert(sizeof(st3c01_ccAdvEventManager) == 0x268,
              "ccAdvEventManager size must be 0x268");
static_assert(offsetof(st3c01_ccAdvEventManager, field_70) == 0x0070,
              "ccAdvEventManager::field_70 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, flag_1A0) == 0x01A0,
              "ccAdvEventManager::flag_1A0 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_1B0) == 0x01B0,
              "ccAdvEventManager::field_1B0 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_1B8) == 0x01B8,
              "ccAdvEventManager::field_1B8 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_1C0) == 0x01C0,
              "ccAdvEventManager::field_1C0 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_240) == 0x0240,
              "ccAdvEventManager::field_240 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_248) == 0x0248,
              "ccAdvEventManager::field_248 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_250) == 0x0250,
              "ccAdvEventManager::field_250 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_254) == 0x0254,
              "ccAdvEventManager::field_254 offset");
static_assert(offsetof(st3c01_ccAdvEventManager, field_260) == 0x0260,
              "ccAdvEventManager::field_260 offset");

/* ========================================================================
 * ccAdvLiveTalkManager
 * Size: unknown (embedded subobject, no standalone alloc found)
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvLiveTalkManager {
    uint8_t base[0x308];        /* 0x0000 — base class region */
    int64_t field_308;          /* 0x0308 — w, zeroed in ctor */
    int64_t field_310;          /* 0x0310 — rw */
    uint8_t pad_0318[24];       /* 0x0318 — gap to 0x0330 */
    int64_t field_330;          /* 0x0330 — w, zeroed in ctor */
    int64_t field_338;          /* 0x0338 — w, zeroed in ctor */
    int64_t field_340;          /* 0x0340 — w, zeroed in ctor */
    void   *field_348;          /* 0x0348 — ptr, FUN_140684bc0 in ctor */
    uint8_t pad_0350[16];       /* 0x0350 — gap to 0x0360 */
    int64_t field_360;          /* 0x0360 — w, zeroed in ctor */
    int64_t field_368;          /* 0x0368 — w, zeroed in ctor */
    int64_t field_370;          /* 0x0370 — w, zeroed in ctor */
    void   *field_378;          /* 0x0378 — ptr, FUN_140684bc0 in ctor */
    uint8_t pad_0380[16];       /* 0x0380 — gap to 0x0390 */
    int64_t field_390;          /* 0x0390 — w, zeroed in ctor */
    /* end of proven fields; total size unknown */
} st3c01_ccAdvLiveTalkManager;

static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_308) == 0x0308,
              "ccAdvLiveTalkManager::field_308 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_310) == 0x0310,
              "ccAdvLiveTalkManager::field_310 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_330) == 0x0330,
              "ccAdvLiveTalkManager::field_330 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_338) == 0x0338,
              "ccAdvLiveTalkManager::field_338 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_340) == 0x0340,
              "ccAdvLiveTalkManager::field_340 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_348) == 0x0348,
              "ccAdvLiveTalkManager::field_348 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_360) == 0x0360,
              "ccAdvLiveTalkManager::field_360 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_368) == 0x0368,
              "ccAdvLiveTalkManager::field_368 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_370) == 0x0370,
              "ccAdvLiveTalkManager::field_370 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_378) == 0x0378,
              "ccAdvLiveTalkManager::field_378 offset");
static_assert(offsetof(st3c01_ccAdvLiveTalkManager, field_390) == 0x0390,
              "ccAdvLiveTalkManager::field_390 offset");

/* ========================================================================
 * ccAdvMotionEventActor
 * Size: unknown (embedded subobject in ccEventChara)
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvMotionEventActor {
    uint8_t base[0x54];         /* 0x0000 — base class region */
    int64_t field_54;           /* 0x0054 — w, zeroed in ctor */
    int32_t field_5C;           /* 0x005C — w, zeroed in ctor */
    int32_t field_60;           /* 0x0060 — w, set to 1 in ctor */
    uint8_t pad_0064[4];        /* 0x0064 — gap to 0x0068 (0x68-0x64=4) */
    int64_t field_68;           /* 0x0068 — w, zeroed in ctor */
    int64_t field_70;           /* 0x0070 — w, zeroed in ctor */
    /* end of proven fields at 0x78 */
} st3c01_ccAdvMotionEventActor;

static_assert(offsetof(st3c01_ccAdvMotionEventActor, field_54) == 0x0054,
              "ccAdvMotionEventActor::field_54 offset");
static_assert(offsetof(st3c01_ccAdvMotionEventActor, field_5C) == 0x005C,
              "ccAdvMotionEventActor::field_5C offset");
static_assert(offsetof(st3c01_ccAdvMotionEventActor, field_60) == 0x0060,
              "ccAdvMotionEventActor::field_60 offset");
static_assert(offsetof(st3c01_ccAdvMotionEventActor, field_68) == 0x0068,
              "ccAdvMotionEventActor::field_68 offset");
static_assert(offsetof(st3c01_ccAdvMotionEventActor, field_70) == 0x0070,
              "ccAdvMotionEventActor::field_70 offset");

/* ========================================================================
 * ccAdvStandDemoCamera
 * Size: 0x240 (proven via LoadTh(0x240) in ccCreateCameraOperatorAdvStandDemoCamera)
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvStandDemoCamera {
    uint8_t base[0x1C8];        /* 0x0000 — base class region */
    float   field_1C8;          /* 0x01C8 — w, 45.0f in ctor */
    int32_t field_1CC;          /* 0x01CC — w, zeroed in ctor */
    uint8_t pad_01D0[84];       /* 0x01D0 — gap to 0x0224 */
    int32_t field_224;          /* 0x0224 — w, set to 1 in ctor */
    int32_t field_228;          /* 0x0228 — w, set to 1 in ctor */
    int32_t field_22C;          /* 0x022C — w, set to 1 in ctor */
    int32_t field_230;          /* 0x0230 — w, set to 1 in ctor */
    int32_t field_234;          /* 0x0234 — w, zeroed in ctor */
    uint8_t pad_0238[8];        /* 0x0238 — pad to 0x240 */
} st3c01_ccAdvStandDemoCamera;

static_assert(sizeof(st3c01_ccAdvStandDemoCamera) == 0x240,
              "ccAdvStandDemoCamera size must be 0x240");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_1C8) == 0x01C8,
              "ccAdvStandDemoCamera::field_1C8 offset");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_1CC) == 0x01CC,
              "ccAdvStandDemoCamera::field_1CC offset");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_224) == 0x0224,
              "ccAdvStandDemoCamera::field_224 offset");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_228) == 0x0228,
              "ccAdvStandDemoCamera::field_228 offset");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_22C) == 0x022C,
              "ccAdvStandDemoCamera::field_22C offset");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_230) == 0x0230,
              "ccAdvStandDemoCamera::field_230 offset");
static_assert(offsetof(st3c01_ccAdvStandDemoCamera, field_234) == 0x0234,
              "ccAdvStandDemoCamera::field_234 offset");

/* ========================================================================
 * ccAdvSubEventManager
 * Size: unknown, >= 0x28
 * Vtable: not resolved
 * Note: offset 0x08 holds a vector<int32> (24 bytes: begin/end/capacity).
 *       GetSubMissionEventNum reads *(int*)(this+0x10) which is the vector's
 *       'end' pointer reinterpreted as int32 — not a separate field.
 *       Layout uses opaque bytes for the vector to avoid overlap ambiguity.
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvSubEventManager {
    uint8_t vtable_or_base[8];  /* 0x0000 */
    uint8_t params_vec[24];     /* 0x0008 — vector<int32> opaque (begin/end/cap) */
    /* end of proven fields at 0x20; total size unknown, >= 0x20 */
} st3c01_ccAdvSubEventManager;

static_assert(offsetof(st3c01_ccAdvSubEventManager, params_vec) == 0x0008,
              "ccAdvSubEventManager::params_vec offset");

/* ========================================================================
 * ccAdvSubEventParam
 * Size: unknown, >= 0x10
 * Vtable: not resolved (value type, likely no vtable)
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvSubEventParam {
    uint32_t id;                /* 0x0000 — rw, Clear zeroes, GetIdName reads */
    int32_t  eventId;           /* 0x0004 — rw, ClearEvent sets 0x1f */
    uint8_t  stateFlags;        /* 0x0008 — rw, bitfield (OnStateFlg/OffStateFlg) */
    uint8_t  pad_0009[3];       /* 0x0009 — alignment */
    int32_t  decisionRoute;     /* 0x000C — rw, SetDecisionRoute/Clear */
    /* end of proven fields at 0x10 */
} st3c01_ccAdvSubEventParam;

static_assert(offsetof(st3c01_ccAdvSubEventParam, id) == 0x0000,
              "ccAdvSubEventParam::id offset");
static_assert(offsetof(st3c01_ccAdvSubEventParam, eventId) == 0x0004,
              "ccAdvSubEventParam::eventId offset");
static_assert(offsetof(st3c01_ccAdvSubEventParam, stateFlags) == 0x0008,
              "ccAdvSubEventParam::stateFlags offset");
static_assert(offsetof(st3c01_ccAdvSubEventParam, decisionRoute) == 0x000C,
              "ccAdvSubEventParam::decisionRoute offset");

/* ========================================================================
 * ccAdvSubEventWakeInfoList
 * Size: unknown, >= 0x88
 * Vtable: not resolved
 * ======================================================================== */
typedef struct __attribute__((packed)) st3c01_ccAdvSubEventWakeInfoList {
    uint8_t            vtable_or_base[8]; /* 0x0000 */
    void              *treeRoot;          /* 0x0008 — ptr, tree traversal in GetParam */
    uint8_t            pad_0010[32];      /* 0x0010 — gap to 0x0030 */
    int64_t            field_30;          /* 0x0030 — rw */
    int64_t            field_38;          /* 0x0038 — rw, copy of field_30 */
    uint8_t            pad_0040[8];       /* 0x0040 — gap to 0x0048 */
    st3c01_block_alloc allocator_48;      /* 0x0048 — block allocator (16 bytes) */
    uint8_t            pad_0058[8];       /* 0x0058 — gap to 0x0060 (0x60-0x58=8) */
    int64_t            field_60;          /* 0x0060 — rw */
    int64_t            field_68;          /* 0x0068 — rw, copy of field_60 */
    uint8_t            pad_0070[8];       /* 0x0070 — gap to 0x0078 */
    st3c01_block_alloc allocator_78;      /* 0x0078 — block allocator (16 bytes) */
    /* end of proven fields at 0x88 */
} st3c01_ccAdvSubEventWakeInfoList;

static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, treeRoot) == 0x0008,
              "ccAdvSubEventWakeInfoList::treeRoot offset");
static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, field_30) == 0x0030,
              "ccAdvSubEventWakeInfoList::field_30 offset");
static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, field_38) == 0x0038,
              "ccAdvSubEventWakeInfoList::field_38 offset");
static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, allocator_48) == 0x0048,
              "ccAdvSubEventWakeInfoList::allocator_48 offset");
static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, field_60) == 0x0060,
              "ccAdvSubEventWakeInfoList::field_60 offset");
static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, field_68) == 0x0068,
              "ccAdvSubEventWakeInfoList::field_68 offset");
static_assert(offsetof(st3c01_ccAdvSubEventWakeInfoList, allocator_78) == 0x0078,
              "ccAdvSubEventWakeInfoList::allocator_78 offset");

#endif /* ST3C01_H */