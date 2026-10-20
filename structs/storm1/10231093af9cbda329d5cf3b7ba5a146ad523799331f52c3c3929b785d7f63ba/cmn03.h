/* cmn03.h — Storm 1 (NSUNS1.exe) struct group cmn03
 * INFERRED layouts from s1 decompilation. Not CONFIRMED at runtime.
 * All offsets proven from PC x64 code only. Sizes unproven unless noted.
 */
#ifndef CMN03_H
#define CMN03_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for engine types whose size is known from other groups */
typedef struct { float x, y, z; } Nucc_Vector3;              /* 0x0C */
typedef struct { float m[16]; } Nucc_Matrix44_MathGeo;       /* 0x40 */

/* ======================================================================
 * ccCpuCoord  (4 methods: SetFromAxis, SetFromNormalDir, TransLocalPos, TransWorldVec)
 * Layout: Vector3 at +0x00, Matrix44 at +0x40. Total >= 0x80.
 * Size unproven (no operator new / allocator size found in these methods).
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    Nucc_Vector3         position;          /* +0x00  size 0x0C  rw */
    uint8_t              _pad_0C[0x34];     /* +0x0C  padding to 0x40 */
    Nucc_Matrix44_MathGeo worldMatrix;      /* +0x40  size 0x40  rw */
    /* size unknown, >= 0x80 */
} ccCpuCoord;

_Static_assert(offsetof(ccCpuCoord, position)   == 0x00, "ccCpuCoord.position");
_Static_assert(offsetof(ccCpuCoord, worldMatrix) == 0x40, "ccCpuCoord.worldMatrix");

/* ======================================================================
 * ccCpuProbSelect  (2 methods: GetProb, SetProb)
 * Only 2 methods — below threshold. Listed in report only.
 * Layout from code: param_1[0] = ptr to array of 12-byte entries,
 *                   param_1[1] = count (int).
 * This is likely a small struct with a pointer and a count.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    int32_t             *entries;           /* +0x00  size 0x08  r  pointer to array of {int id, int ?, int prob} */
    int32_t              count;             /* +0x08  size 0x04  r */
    uint8_t              _pad_0C[0x04];     /* +0x0C  padding */
    /* size unknown, >= 0x10 */
} ccCpuProbSelect;

_Static_assert(offsetof(ccCpuProbSelect, entries) == 0x00, "ccCpuProbSelect.entries");
_Static_assert(offsetof(ccCpuProbSelect, count)   == 0x08, "ccCpuProbSelect.count");

/* ======================================================================
 * ccDamageRequestMessage  (1 method: Reset)
 * Only 1 method — below threshold. Listed in report only.
 * Reset writes fields up to param_1[0x26] (= byte offset 0x98).
 * Layout inferred from Reset's zero-fill pattern.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint32_t             field_00;          /* +0x00  size 0x04  w  set to 0xFFFFFFFF */
    uint64_t             field_04;          /* +0x04  size 0x08  w  zeroed */
    uint64_t             field_0C;          /* +0x0C  size 0x08  w  zeroed */
    uint32_t             field_14;          /* +0x14  size 0x04  w  set to 0xFFFFFFFF */
    uint32_t             field_18;          /* +0x18  size 0x04  w  zeroed */
    Nucc_Vector3         direction;        /* +0x1C  size 0x0C  w  set to zAxis */
    float                field_28;          /* +0x28  size 0x04  w  -1.0f (0xBF800000) */
    float                field_2C;          /* +0x2C  size 0x04  w  -1.0f */
    float                field_30;          /* +0x30  size 0x04  w  -1.0f */
    float                field_34;          /* +0x34  size 0x04  w  1.0f */
    float                field_38;          /* +0x38  size 0x04  w  1.0f */
    uint64_t             field_3C;          /* +0x3C  size 0x08  w  zeroed */
    uint8_t              _pad_44[0x48];     /* +0x44  gap to 0x8C */
    uint64_t             field_8C;          /* +0x8C  size 0x08  w  zeroed (param_1+0x24 → byte 0x90? recheck) */
    uint64_t             field_94;          /* +0x94  size 0x08  w  zeroed (param_1+0x26 → byte 0x98) */
    /* size unknown, >= 0x9C */
} ccDamageRequestMessage;

_Static_assert(offsetof(ccDamageRequestMessage, field_00)    == 0x00, "ccDamageRequestMessage.field_00");
_Static_assert(offsetof(ccDamageRequestMessage, field_04)    == 0x04, "ccDamageRequestMessage.field_04");
_Static_assert(offsetof(ccDamageRequestMessage, field_0C)    == 0x0C, "ccDamageRequestMessage.field_0C");
_Static_assert(offsetof(ccDamageRequestMessage, field_14)    == 0x14, "ccDamageRequestMessage.field_14");
_Static_assert(offsetof(ccDamageRequestMessage, field_18)    == 0x18, "ccDamageRequestMessage.field_18");
_Static_assert(offsetof(ccDamageRequestMessage, direction)   == 0x1C, "ccDamageRequestMessage.direction");
_Static_assert(offsetof(ccDamageRequestMessage, field_28)    == 0x28, "ccDamageRequestMessage.field_28");
_Static_assert(offsetof(ccDamageRequestMessage, field_2C)    == 0x2C, "ccDamageRequestMessage.field_2C");
_Static_assert(offsetof(ccDamageRequestMessage, field_30)    == 0x30, "ccDamageRequestMessage.field_30");
_Static_assert(offsetof(ccDamageRequestMessage, field_34)    == 0x34, "ccDamageRequestMessage.field_34");
_Static_assert(offsetof(ccDamageRequestMessage, field_38)    == 0x38, "ccDamageRequestMessage.field_38");
_Static_assert(offsetof(ccDamageRequestMessage, field_3C)    == 0x3C, "ccDamageRequestMessage.field_3C");
_Static_assert(offsetof(ccDamageRequestMessage, field_8C)    == 0x8C, "ccDamageRequestMessage.field_8C");
_Static_assert(offsetof(ccDamageRequestMessage, field_94)    == 0x94, "ccDamageRequestMessage.field_94");

/* ======================================================================
 * ccEffectGarSand  (2 methods: Ctrl, Init)
 * Only 2 methods — below threshold. Listed in report only.
 * Inherits from ccEffectMassProduction (Ctrl calls parent).
 * Fields seen: +0x168 (ptr), +0x184 (float), +0x1C0 (int), +0x1C4 (float).
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              _base[0x168];      /* +0x00  ccEffectMassProduction base */
    uint64_t             anmBase_ptr;       /* +0x168 size 0x08  r  passed to nuccAnmBase::SetOpacity */
    uint8_t              _pad_170[0x14];    /* +0x170 padding */
    float                timer_threshold;   /* +0x184 size 0x04  rw */
    uint8_t              _pad_188[0x38];    /* +0x188 padding */
    int32_t              player_index;      /* +0x1C0 size 0x04  r  0 or 1 */
    float                opacity;           /* +0x1C4 size 0x04  rw */
    /* size unknown, >= 0x1C8 */
} ccEffectGarSand;

_Static_assert(offsetof(ccEffectGarSand, anmBase_ptr)     == 0x168, "ccEffectGarSand.anmBase_ptr");
_Static_assert(offsetof(ccEffectGarSand, timer_threshold) == 0x184, "ccEffectGarSand.timer_threshold");
_Static_assert(offsetof(ccEffectGarSand, player_index)    == 0x1C0, "ccEffectGarSand.player_index");
_Static_assert(offsetof(ccEffectGarSand, opacity)         == 0x1C4, "ccEffectGarSand.opacity");

/* ======================================================================
 * ccEvent  (1 method: GetEventId)
 * Only 1 method — below threshold. Listed in report only.
 * GetEventId treats param_1 as a char* (string), hashes it.
 * ccEvent appears to be a thin wrapper around a name string.
 * ====================================================================== */

/* ======================================================================
 * ccEvent::Manager  (4 methods: Request, GetEvents, Update, Clear)
 * All delegate to Impl via vtable call at *(**(param_1+8)+0x20).
 * Field at +0x08 is a pointer to Impl (or factory object).
 * GetEvents returns impl_ptr + 0x68, suggesting events list lives there.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void                *vtable;            /* +0x00  size 0x08  r */
    void                *impl;              /* +0x08  size 0x08  r  pointer to Impl or factory */
    /* size unknown, >= 0x10 */
} ccEvent_Manager;

_Static_assert(offsetof(ccEvent_Manager, vtable) == 0x00, "ccEvent_Manager.vtable");
_Static_assert(offsetof(ccEvent_Manager, impl)   == 0x08, "ccEvent_Manager.impl");

/* ======================================================================
 * ccEvent::Manager::Impl  (3 methods: Update, InsertRequest, Clear)
 * longlong* param_1 — offsets are byte-scaled (param_1[N] = byte N*8).
 * Fields from decompilation:
 *   +0x00 (vtable/lock fn ptrs): *param_1+8, *param_1+0x10 are virtual calls
 *   param_1[3]  = +0x18: std::tree (events map) — 24 bytes
 *   param_1[4]  = +0x20: count/flag
 *   param_1[8]  = +0x40: another tree/map ptr
 *   param_1[9]  = +0x48: count for above
 *   param_1[0xd]= +0x68: counter/tick (copied to [0xe])
 *   param_1[0xe]= +0x70: previous tick
 *   param_1[0x13]=+0x98: lock object ptr
 *   param_1[0x14]=+0xA0: request counter (int, incremented)
 *   param_1[0x15]=+0xA8: critical section (nuccCriticalSection)
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void               *lock_fn;            /* +0x00  size 0x08  r  vtable-like: +8 = unlock, +0x10 = signal */
    void               *unlock_fn;          /* +0x08  size 0x08  r */
    void               *signal_fn;          /* +0x10  size 0x08  r */
    uint8_t             events_tree[0x18];  /* +0x18  size 0x18  rw std::tree/multimap */
    uint64_t            event_count;        /* +0x30  size 0x08  rw param_1[4] */
    uint8_t             _pad_38[0x08];      /* +0x38  gap */
    uint64_t            error_map_ptr;      /* +0x40  size 0x08  r  param_1[8] */
    uint64_t            error_map_count;    /* +0x48  size 0x08  r  param_1[9] */
    uint8_t             _pad_50[0x18];      /* +0x50  gap to 0x68 */
    uint64_t            current_tick;       /* +0x68  size 0x08  rw param_1[0xd] */
    uint64_t            prev_tick;          /* +0x70  size 0x08  w  param_1[0xe] = [0xd] */
    uint8_t             _pad_78[0x20];      /* +0x78  gap to 0x98 */
    uint64_t            lock_obj;           /* +0x98  size 0x08  r  param_1[0x13] */
    uint32_t            request_counter;    /* +0xA0  size 0x04  rw param_1[0x14] */
    uint8_t             _pad_A4[0x04];      /* +0xA4  padding */
    uint8_t             crit_section[0x28]; /* +0xA8  size ?    rw param_1[0x15], nuccCriticalSection */
    /* size unknown, >= 0xD0 */
} ccEvent_Manager_Impl;

_Static_assert(offsetof(ccEvent_Manager_Impl, lock_fn)          == 0x00, "ccEvent_Manager_Impl.lock_fn");
_Static_assert(offsetof(ccEvent_Manager_Impl, unlock_fn)        == 0x08, "ccEvent_Manager_Impl.unlock_fn");
_Static_assert(offsetof(ccEvent_Manager_Impl, signal_fn)        == 0x10, "ccEvent_Manager_Impl.signal_fn");
_Static_assert(offsetof(ccEvent_Manager_Impl, events_tree)      == 0x18, "ccEvent_Manager_Impl.events_tree");
_Static_assert(offsetof(ccEvent_Manager_Impl, event_count)      == 0x30, "ccEvent_Manager_Impl.event_count");
_Static_assert(offsetof(ccEvent_Manager_Impl, error_map_ptr)    == 0x40, "ccEvent_Manager_Impl.error_map_ptr");
_Static_assert(offsetof(ccEvent_Manager_Impl, error_map_count)  == 0x48, "ccEvent_Manager_Impl.error_map_count");
_Static_assert(offsetof(ccEvent_Manager_Impl, current_tick)     == 0x68, "ccEvent_Manager_Impl.current_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl, prev_tick)        == 0x70, "ccEvent_Manager_Impl.prev_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl, lock_obj)         == 0x98, "ccEvent_Manager_Impl.lock_obj");
_Static_assert(offsetof(ccEvent_Manager_Impl, request_counter)  == 0xA0, "ccEvent_Manager_Impl.request_counter");
_Static_assert(offsetof(ccEvent_Manager_Impl, crit_section)     == 0xA8, "ccEvent_Manager_Impl.crit_section");

/* ======================================================================
 * ccFCurveSceneEffectGame  (3 methods: ~dtor, Enable, Disable)
 * Inherits from nuccFCurveSceneEffect (dtor calls parent).
 * Enable/Disable access many FCurve IDs stored as uint32 at sequential offsets.
 * Pattern: *(uint32*)(param_1 + 0x08 + i*4) = FCurve ID for effect i.
 * Effect enable flags at param_1+0xAC, 0xB0, 0xB4, ... (each 4 bytes).
 * DrawEnv index at param_1+0x150.
 * Arrays of FCurve IDs:
 *   +0x08..+0x38: individual effect FCurve IDs (DoF, Blur, Softfocus, ..., Fog)
 *   +0x3C..+0x43: 2-element array (light-related)
 *   +0x44..+0x4B: 2-element array
 *   +0x4C..+0x57: 3-element array
 *   +0x60, +0x68, +0x6C, +0x70..+0x8C, +0x98..+0xA8: more IDs
 *   +0xAC: DoF enable flag
 *   +0xB0: Blur enable flag
 *   +0xB4: Softfocus enable flag
 *   +0xB8: ? enable flag
 *   +0xBC: Glare enable flag
 *   +0xC0: Shadow enable flag
 *   +0xC4: ShadowDist enable flag
 *   +0xC8: ShadowDirc enable flag (param_1+200 = 0xC8)
 *   +0xCC: ColorConv enable flag
 *   +0x150: drawEnv index
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t             _base[0x08];        /* +0x00  nuccFCurveSceneEffect base (vtable etc.) */
    uint32_t            fcurve_dof;         /* +0x08  size 0x04  r  FCurve ID for DoF */
    uint32_t            fcurve_blur;        /* +0x0C  size 0x04  r */
    uint32_t            fcurve_softfocus;   /* +0x10  size 0x04  r */
    uint32_t            fcurve_unk14;       /* +0x14  size 0x04  r */
    uint32_t            fcurve_glare;       /* +0x18  size 0x04  r */
    uint32_t            fcurve_shadow;      /* +0x1C  size 0x04  r */
    uint32_t            fcurve_shadow_dist; /* +0x20  size 0x04  r */
    uint32_t            fcurve_shadow_dirc; /* +0x24  size 0x04  r */
    uint32_t            fcurve_colorconv;   /* +0x28  size 0x04  r */
    uint32_t            fcurve_fog;         /* +0x2C  size 0x04  r  (inferred from Disable sequence) */
    uint8_t             _pad_30[0x0C];      /* +0x30  gap */
    uint32_t            fcurve_light[2];    /* +0x3C  size 0x08  r  2-element loop */
    uint32_t            fcurve_unk44[2];    /* +0x44  size 0x08  r  2-element loop */
    uint32_t            fcurve_unk4c[3];    /* +0x4C  size 0x0C  r  3-element loop */
    uint8_t             _pad_58[0x08];      /* +0x58  gap */
    uint32_t            fcurve_unk60;       /* +0x60  size 0x04  r */
    uint32_t            fcurve_unk64;       /* +0x64  size 0x04  r  (gap filler) */
    uint32_t            fcurve_unk68;       /* +0x68  size 0x04  r */
    uint32_t            fcurve_unk6c;       /* +0x6C  size 0x04  r */
    uint32_t            fcurve_unk70;       /* +0x70  size 0x04  r */
    uint32_t            fcurve_unk74;       /* +0x74  size 0x04  r */
    uint32_t            fcurve_unk78;       /* +0x78  size 0x04  r */
    uint32_t            fcurve_unk7c;       /* +0x7C  size 0x04  r */
    uint32_t            fcurve_unk80;       /* +0x80  size 0x04  r */
    uint32_t            fcurve_unk84;       /* +0x84  size 0x04  r */
    uint32_t            fcurve_unk88;       /* +0x88  size 0x04  r  (guarded by +0x12C flag) */
    uint32_t            fcurve_unk8c;       /* +0x8C  size 0x04  r */
    uint8_t             _pad_90[0x08];      /* +0x90  gap */
    uint32_t            fcurve_unk98;       /* +0x98  size 0x04  r */
    uint32_t            fcurve_unk9c;       /* +0x9C  size 0x04  r */
    uint32_t            fcurve_unka0;       /* +0xA0  size 0x04  r */
    uint32_t            fcurve_unka4;       /* +0xA4  size 0x04  r */
    uint32_t            fcurve_unka8;       /* +0xA8  size 0x04  r */
    uint32_t            enable_dof;         /* +0xAC  size 0x04  r  non-zero = DoF active */
    uint32_t            enable_blur;        /* +0xB0  size 0x04  r */
    uint32_t            enable_softfocus;   /* +0xB4  size 0x04  r */
    uint32_t            enable_unkb8;       /* +0xB8  size 0x04  r */
    uint32_t            enable_glare;       /* +0xBC  size 0x04  r */
    uint32_t            enable_shadow;      /* +0xC0  size 0x04  r */
    uint32_t            enable_shadow_dist; /* +0xC4  size 0x04  r */
    uint32_t            enable_shadow_dirc; /* +0xC8  size 0x04  r  (param_1+200) */
    uint32_t            enable_colorconv;   /* +0xCC  size 0x04  r  (inferred) */
    uint8_t             _pad_D0[0x20];      /* +0xD0  gap */
    uint32_t            enable_unk88_flag;  /* +0xF0  size 0x04  r  (param_1+300=0x12C) guards fcurve_unk88 */
    uint8_t             _pad_F4[0x5C];      /* +0xF4  gap to 0x150 */
    uint32_t            drawenv_index;      /* +0x150 size 0x04  r  passed to ccGameDrawEnv::* */
    /* size unknown, >= 0x154 */
} ccFCurveSceneEffectGame;

_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_dof)          == 0x08, "ccFCurveSceneEffectGame.fcurve_dof");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_blur)         == 0x0C, "ccFCurveSceneEffectGame.fcurve_blur");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_softfocus)    == 0x10, "ccFCurveSceneEffectGame.fcurve_softfocus");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk14)        == 0x14, "ccFCurveSceneEffectGame.fcurve_unk14");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_glare)        == 0x18, "ccFCurveSceneEffectGame.fcurve_glare");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_shadow)       == 0x1C, "ccFCurveSceneEffectGame.fcurve_shadow");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_shadow_dist)  == 0x20, "ccFCurveSceneEffectGame.fcurve_shadow_dist");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_shadow_dirc)  == 0x24, "ccFCurveSceneEffectGame.fcurve_shadow_dirc");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_colorconv)    == 0x28, "ccFCurveSceneEffectGame.fcurve_colorconv");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_fog)          == 0x2C, "ccFCurveSceneEffectGame.fcurve_fog");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_light)        == 0x3C, "ccFCurveSceneEffectGame.fcurve_light");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk44)        == 0x44, "ccFCurveSceneEffectGame.fcurve_unk44");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk4c)        == 0x4C, "ccFCurveSceneEffectGame.fcurve_unk4c");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk60)        == 0x60, "ccFCurveSceneEffectGame.fcurve_unk60");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk68)        == 0x68, "ccFCurveSceneEffectGame.fcurve_unk68");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk6c)        == 0x6C, "ccFCurveSceneEffectGame.fcurve_unk6c");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk70)        == 0x70, "ccFCurveSceneEffectGame.fcurve_unk70");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk74)        == 0x74, "ccFCurveSceneEffectGame.fcurve_unk74");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk78)        == 0x78, "ccFCurveSceneEffectGame.fcurve_unk78");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk7c)        == 0x7C, "ccFCurveSceneEffectGame.fcurve_unk7c");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk80)        == 0x80, "ccFCurveSceneEffectGame.fcurve_unk80");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk84)        == 0x84, "ccFCurveSceneEffectGame.fcurve_unk84");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk88)        == 0x88, "ccFCurveSceneEffectGame.fcurve_unk88");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk8c)        == 0x8C, "ccFCurveSceneEffectGame.fcurve_unk8c");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk98)        == 0x98, "ccFCurveSceneEffectGame.fcurve_unk98");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unk9c)        == 0x9C, "ccFCurveSceneEffectGame.fcurve_unk9c");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unka0)        == 0xA0, "ccFCurveSceneEffectGame.fcurve_unka0");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unka4)        == 0xA4, "ccFCurveSceneEffectGame.fcurve_unka4");
_Static_assert(offsetof(ccFCurveSceneEffectGame, fcurve_unka8)        == 0xA8, "ccFCurveSceneEffectGame.fcurve_unka8");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_dof)          == 0xAC, "ccFCurveSceneEffectGame.enable_dof");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_blur)         == 0xB0, "ccFCurveSceneEffectGame.enable_blur");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_softfocus)    == 0xB4, "ccFCurveSceneEffectGame.enable_softfocus");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_unkb8)        == 0xB8, "ccFCurveSceneEffectGame.enable_unkb8");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_glare)        == 0xBC, "ccFCurveSceneEffectGame.enable_glare");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_shadow)       == 0xC0, "ccFCurveSceneEffectGame.enable_shadow");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_shadow_dist)  == 0xC4, "ccFCurveSceneEffectGame.enable_shadow_dist");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_shadow_dirc)  == 0xC8, "ccFCurveSceneEffectGame.enable_shadow_dirc");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_colorconv)    == 0xCC, "ccFCurveSceneEffectGame.enable_colorconv");
_Static_assert(offsetof(ccFCurveSceneEffectGame, enable_unk88_flag)   == 0xF0, "ccFCurveSceneEffectGame.enable_unk88_flag");
_Static_assert(offsetof(ccFCurveSceneEffectGame, drawenv_index)       == 0x150, "ccFCurveSceneEffectGame.drawenv_index");

/* ======================================================================
 * ccFileLoadListForUi  (10 methods)
 * ctor allocates sub-objects at param_1[4] (+0x20) and param_1[5] (+0x28).
 * Fields:
 *   +0x00: vtable ptr
 *   +0x0C (+3*4): int, initialized to 0
 *   +0x10 (+4*8): ptr to list head (std::list)
 *   +0x18 (+6*8): ptr to worker/sub-object
 *   +0x18 (byte): init flag (int at +0x18)
 *   +0x20: ptr to std::list container
 *   +0x28: ptr to pool allocator
 * Note: ctor uses undefined8* param_1, so param_1[N] = byte offset N*8.
 *   param_1[3] = +0x18 (int, but addressed as undefined4*)
 *   param_1[4] = +0x20 (ptr)
 *   param_1[5] = +0x28 (ptr)
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void               *vtable;             /* +0x00  size 0x08  rw */
    uint8_t             _pad_08[0x10];      /* +0x08  gap */
    uint32_t            init_flag;          /* +0x18  size 0x04  rw  0→1 on first LoadTh/Reserve */
    uint8_t             _pad_1C[0x04];      /* +0x1C  padding */
    void               *list_container;     /* +0x20  size 0x08  rw  std::list<ccFileLoadListForUiNode> */
    void               *pool_allocator;     /* +0x28  size 0x08  rw  nuccPoolAllocation */
    /* size unknown, >= 0x30 */
} ccFileLoadListForUi;

_Static_assert(offsetof(ccFileLoadListForUi, vtable)         == 0x00, "ccFileLoadListForUi.vtable");
_Static_assert(offsetof(ccFileLoadListForUi, init_flag)      == 0x18, "ccFileLoadListForUi.init_flag");
_Static_assert(offsetof(ccFileLoadListForUi, list_container) == 0x20, "ccFileLoadListForUi.list_container");
_Static_assert(offsetof(ccFileLoadListForUi, pool_allocator) == 0x28, "ccFileLoadListForUi.pool_allocator");

#endif /* CMN03_H */
