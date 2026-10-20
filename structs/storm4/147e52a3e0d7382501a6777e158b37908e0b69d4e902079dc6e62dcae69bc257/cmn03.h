/* cmn03.h — Storm 4 (NSUNS4_release.exe, build s4) struct group cmn03
 * INFERRED layouts from s4 decompilation + state_surface. Not CONFIRMED at runtime.
 * All offsets proven from PC x64 code only. Sizes unproven unless noted.
 */
#ifndef CMN03_S4_H
#define CMN03_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ======================================================================
 * ccCpuCoord (7 methods: SetFromAxis, SetFromNormalDir, GetDirVector,
 * CalcDirMatrix, RotatePosition, TransWorldVec, TransLocalPos)
 * state_surface returned 0 typed fields; all 7 seeds use byte-cast access.
 * Layout carried from s3 (identical helper pattern). Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t dir_matrix[0x40];   /* +0x00 size 0x40 rw Nucc::Matrix44_MathGeo (inferred from s3) */
    uint8_t coord_data[0x40];   /* +0x40 size 0x40 w secondary matrix/scratch (inferred from s3) */
    /* size unknown, >= 0x80 */
} ccCpuCoord_s4;

_Static_assert(offsetof(ccCpuCoord_s4, dir_matrix) == 0x00, "ccCpuCoord_s4.dir_matrix");
_Static_assert(offsetof(ccCpuCoord_s4, coord_data) == 0x40, "ccCpuCoord_s4.coord_data");

/* ======================================================================
 * ccCpuProbSelect (9 methods: Init x2, SetProb, AddProb, MulProb,
 * GetProb, ctor, dtor, Select)
 * state_surface found 1 field at +0x80 (low confidence virtual dispatch).
 * s3 layout: entries ptr at +0x00, count at +0x08. Carried forward.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void *entries;              /* +0x00 size 0x08 rw ptr to {value:uint32, weight:float} array (from s3) */
    int32_t count;              /* +0x08 size 0x04 rw entry count (from s3) */
    uint8_t _pad_0C[0x74];     /* +0x0C gap to +0x80 */
    uint8_t vtable_or_data[0x08]; /* +0x80 size unk r virtual dispatch or callback; (**(code **)(*param_1 + 0x10))(param_1) */
    /* size unknown, >= 0x88 */
} ccCpuProbSelect_s4;

_Static_assert(offsetof(ccCpuProbSelect_s4, entries) == 0x00, "ccCpuProbSelect_s4.entries");
_Static_assert(offsetof(ccCpuProbSelect_s4, count) == 0x08, "ccCpuProbSelect_s4.count");
_Static_assert(offsetof(ccCpuProbSelect_s4, vtable_or_data) == 0x80, "ccCpuProbSelect_s4.vtable_or_data");

/* ======================================================================
 * ccDamageRequestMessage (11 seed methods; 7 returned byte-cast only)
 * state_surface found 6 fields across 4 seeds. Massive struct: fields span
 * from +0x24 to +0x15750. Constructor initializes 3 substructures via
 * FUN_140a046f0 and sets vtable at +0xB00, sentinel at +0x15750.
 * Size unproven; minimum >= 0x15754.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t _pad_00[0x24];     /* +0x00 gap to first proven field */
    uint8_t sub_struct_24[0x44];/* +0x24 size unk r sub-object initialized by FUN_140a046f0 in ctor */
    uint64_t zero_field_68;     /* +0x68 size 0x08 w zeroed in ctor: param_1[0xd] = 0 */
    uint8_t _pad_70[0x1C];     /* +0x70 gap */
    uint8_t sub_struct_8C[0x10];/* +0x8C size unk r second sub-object initialized by FUN_140a046f0 */
    uint8_t sub_struct_9C[0xA64];/* +0x9C size unk r third sub-object; gap extends to +0xB00 */
    void *vtable_B00;           /* +0xB00 size 0x08 w param_1[0x160] = &PTR_LAB_141082268; vtable/dispatch ptr */
    uint8_t _pad_B08[0x14C48]; /* +0xB08 gap to +0x15750 */
    uint32_t sentinel_15750;    /* +0x15750 size 0x04 w *(undefined4*)(param_1+0x2aea)=0xffffffff */
    /* size unknown, >= 0x15754 */
} ccDamageRequestMessage_s4;

_Static_assert(offsetof(ccDamageRequestMessage_s4, sub_struct_24) == 0x24, "ccDamageRequestMessage_s4.sub_struct_24");
_Static_assert(offsetof(ccDamageRequestMessage_s4, zero_field_68) == 0x68, "ccDamageRequestMessage_s4.zero_field_68");
_Static_assert(offsetof(ccDamageRequestMessage_s4, sub_struct_8C) == 0x8C, "ccDamageRequestMessage_s4.sub_struct_8C");
_Static_assert(offsetof(ccDamageRequestMessage_s4, sub_struct_9C) == 0x9C, "ccDamageRequestMessage_s4.sub_struct_9C");
_Static_assert(offsetof(ccDamageRequestMessage_s4, vtable_B00) == 0xB00, "ccDamageRequestMessage_s4.vtable_B00");
_Static_assert(offsetof(ccDamageRequestMessage_s4, sentinel_15750) == 0x15750, "ccDamageRequestMessage_s4.sentinel_15750");

/* ======================================================================
 * ccEvent::Manager (8 seed methods; wrapper delegating to Impl)
 * state_surface found same 6 fields as Impl (Manager passes through).
 * Manager itself has vtable + impl pointer (inferred from s3 pattern).
 * See ccEvent_Manager_Impl_s4 for actual field semantics.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void *vtable;               /* +0x00 size 0x08 r vtable dispatch (inferred from s3) */
    void *impl;                 /* +0x08 size 0x08 r pointer to Impl (inferred from s3) */
    uint8_t _pad_10[0x58];     /* +0x10 gap to Impl-mirrored fields */
    uint64_t current_tick;      /* +0x68 size 0x08 r delegated to Impl */
    uint64_t prev_tick;         /* +0x70 size 0x08 w delegated to Impl */
    uint8_t _pad_78[0x08];     /* +0x78 gap */
    uint64_t sub_container_80;  /* +0x80 size 0x08 r delegated to Impl */
    uint8_t _pad_88[0x10];     /* +0x88 gap */
    uint64_t lock_obj;          /* +0x98 size 0x08 r delegated to Impl */
    uint32_t request_counter;   /* +0xA0 size 0x04 rw delegated to Impl */
    uint8_t _pad_A4[0x04];     /* +0xA4 gap */
    uint8_t crit_section[0x28];/* +0xA8 size 0x28 r delegated to Impl */
    /* size unknown, >= 0xD0 */
} ccEvent_Manager_s4;

_Static_assert(offsetof(ccEvent_Manager_s4, vtable) == 0x00, "ccEvent_Manager_s4.vtable");
_Static_assert(offsetof(ccEvent_Manager_s4, impl) == 0x08, "ccEvent_Manager_s4.impl");
_Static_assert(offsetof(ccEvent_Manager_s4, current_tick) == 0x68, "ccEvent_Manager_s4.current_tick");
_Static_assert(offsetof(ccEvent_Manager_s4, prev_tick) == 0x70, "ccEvent_Manager_s4.prev_tick");
_Static_assert(offsetof(ccEvent_Manager_s4, sub_container_80) == 0x80, "ccEvent_Manager_s4.sub_container_80");
_Static_assert(offsetof(ccEvent_Manager_s4, lock_obj) == 0x98, "ccEvent_Manager_s4.lock_obj");
_Static_assert(offsetof(ccEvent_Manager_s4, request_counter) == 0xA0, "ccEvent_Manager_s4.request_counter");
_Static_assert(offsetof(ccEvent_Manager_s4, crit_section) == 0xA8, "ccEvent_Manager_s4.crit_section");

/* ======================================================================
 * ccEvent::Manager::Impl (3 seed methods: Update, InsertRequest, Clear)
 * Fields from state_surface (6 fields across 3 seeds). Identical offsets
 * to s3. Manages event request insertion, update ticks, and clearing.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t _pad_00[0x68];     /* +0x00 gap to first proven field */
    uint64_t current_tick;      /* +0x68 size 0x08 r param_1[0xd]; source of iterator copy */
    uint64_t prev_tick;         /* +0x70 size 0x08 w param_1[0xe] = [0xd] in Update/Clear */
    uint8_t _pad_78[0x08];     /* +0x78 gap */
    uint64_t sub_container_80;  /* +0x80 size 0x08 r passed to FUN_140a01d60(param_1+0x10) */
    uint8_t _pad_88[0x10];     /* +0x88 gap */
    uint64_t lock_obj;          /* +0x98 size 0x08 r param_1[0x13]; dereferenced for dispatch */
    uint32_t request_counter;   /* +0xA0 size 0x04 rw read qword in Update, write dword in InsertRequest */
    uint8_t _pad_A4[0x04];     /* +0xA4 gap */
    uint8_t crit_section[0x28];/* +0xA8 size 0x28 r passed to FUN_140a23340(param_1+0x15) */
    /* size unknown, >= 0xD0 */
} ccEvent_Manager_Impl_s4;

_Static_assert(offsetof(ccEvent_Manager_Impl_s4, current_tick) == 0x68, "ccEvent_Manager_Impl_s4.current_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl_s4, prev_tick) == 0x70, "ccEvent_Manager_Impl_s4.prev_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl_s4, sub_container_80) == 0x80, "ccEvent_Manager_Impl_s4.sub_container_80");
_Static_assert(offsetof(ccEvent_Manager_Impl_s4, lock_obj) == 0x98, "ccEvent_Manager_Impl_s4.lock_obj");
_Static_assert(offsetof(ccEvent_Manager_Impl_s4, request_counter) == 0xA0, "ccEvent_Manager_Impl_s4.request_counter");
_Static_assert(offsetof(ccEvent_Manager_Impl_s4, crit_section) == 0xA8, "ccEvent_Manager_Impl_s4.crit_section");

/* ======================================================================
 * ccFCurveSceneEffectGame (4 seed methods: Enable, Disable, ctor, dtor)
 * state_surface returned 0 typed fields; all 4 seeds use byte-cast access.
 * Layout carried from s3 (vtable at +0x00 implied by virtual call pattern).
 * Size unproven; s3 had last proven access at +0x900.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t _pad_00[0xFC];     /* +0x00 gap to first proven field (from s3) */
    uint32_t init_flag_FC;      /* +0xFC size 0x04 w zeroed in ctor (from s3) */
    uint8_t _pad_100[0x68];    /* +0x100 gap */
    uint32_t fcurve_flag_168;   /* +0x168 size 0x04 r checked in Enable (from s3) */
    uint8_t _pad_16C[0x40];    /* +0x16C gap */
    uint32_t fcurve_id_1AC;     /* +0x1AC size 0x04 r compared to -1 sentinel (from s3) */
    uint8_t _pad_1B0[0x08];    /* +0x1B0 gap */
    uint64_t fcurve_ptr_1B8;    /* +0x1B8 size 0x08 r null-checked in Enable (from s3) */
    uint8_t _pad_1C0[0x740];   /* +0x1C0 gap to vtable call site */
    /* vtable at +0x00 implied by (**(code **)(*param_1 + 0x120)) virtual call */
    /* size unknown, >= 0x908 */
} ccFCurveSceneEffectGame_s4;

_Static_assert(offsetof(ccFCurveSceneEffectGame_s4, init_flag_FC) == 0xFC, "ccFCurveSceneEffectGame_s4.init_flag_FC");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s4, fcurve_flag_168) == 0x168, "ccFCurveSceneEffectGame_s4.fcurve_flag_168");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s4, fcurve_id_1AC) == 0x1AC, "ccFCurveSceneEffectGame_s4.fcurve_id_1AC");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s4, fcurve_ptr_1B8) == 0x1B8, "ccFCurveSceneEffectGame_s4.fcurve_ptr_1B8");

/* ======================================================================
 * ccFileLoadListForUi (16 seed methods; all returned byte-cast only)
 * state_surface found 1 field at +0x80 (low confidence virtual dispatch).
 * s3 layout: vtable at +0x00, init_flag at +0x18, file_list at +0x20,
 * secondary_ptr at +0x28. Carried forward. Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void *vtable;               /* +0x00 size 0x08 w vtable ptr set in ctor (from s3) */
    uint8_t _pad_08[0x10];     /* +0x08 gap */
    uint32_t init_flag;         /* +0x18 size 0x04 w zeroed in ctor (from s3) */
    uint8_t _pad_1C[0x04];     /* +0x1C alignment */
    void *file_list;            /* +0x20 size 0x08 rw container ptr (from s3) */
    void *secondary_ptr;        /* +0x28 size 0x08 w zeroed in ctor (from s3) */
    uint8_t _pad_30[0x50];     /* +0x30 gap to +0x80 */
    uint8_t vtable_or_data[0x08]; /* +0x80 size unk r virtual dispatch; (**(code **)(*param_1 + 0x10))(param_1) */
    /* size unknown, >= 0x88 */
} ccFileLoadListForUi_s4;

_Static_assert(offsetof(ccFileLoadListForUi_s4, vtable) == 0x00, "ccFileLoadListForUi_s4.vtable");
_Static_assert(offsetof(ccFileLoadListForUi_s4, init_flag) == 0x18, "ccFileLoadListForUi_s4.init_flag");
_Static_assert(offsetof(ccFileLoadListForUi_s4, file_list) == 0x20, "ccFileLoadListForUi_s4.file_list");
_Static_assert(offsetof(ccFileLoadListForUi_s4, secondary_ptr) == 0x28, "ccFileLoadListForUi_s4.secondary_ptr");
_Static_assert(offsetof(ccFileLoadListForUi_s4, vtable_or_data) == 0x80, "ccFileLoadListForUi_s4.vtable_or_data");

#endif /* CMN03_S4_H */