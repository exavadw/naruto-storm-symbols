/* cmn03.h — Storm 3 (NSUNS3.exe-a7124b) struct group cmn03
 * INFERRED layouts from s3 decompilation + state_surface. Not CONFIRMED at runtime.
 * All offsets proven from PC x64 code only. Sizes unproven unless noted.
 */
#ifndef CMN03_S3_H
#define CMN03_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for engine types whose size is known from other groups */
typedef struct { float x, y, z; } Nucc_Vector3;              /* 0x0C */
typedef struct { float m[16]; } Nucc_Matrix44_MathGeo;       /* 0x40 */

/* ======================================================================
 * ccCpuCoord  (7 methods: SetFromAxis, SetFromNormalDir, GetDirVector,
 *              CalcDirMatrix, RotatePosition, TransWorldVec, TransLocalPos)
 * Layout: embedded Nucc::Matrix44_MathGeo at +0x00 (64 bytes), secondary
 * matrix/scratch at +0x40. All access via Nucc math helpers; state_surface
 * returned 0 typed fields.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              dir_matrix[0x40];  /* +0x00  size 0x40  rw  Nucc::Matrix44_MathGeo; passed to SetTranslatePart/Matrix44 copy */
    uint8_t              coord_data[0x40];  /* +0x40  size 0x40  w   secondary matrix or scratch; written by FUN_140686070 result copy */
    /* size unknown, >= 0x80 */
} ccCpuCoord_s3;

_Static_assert(offsetof(ccCpuCoord_s3, dir_matrix) == 0x00, "ccCpuCoord_s3.dir_matrix");
_Static_assert(offsetof(ccCpuCoord_s3, coord_data) == 0x40, "ccCpuCoord_s3.coord_data");

/* ======================================================================
 * ccCpuProbSelect  (10 methods: Init x2, SetProb, ConvertRatio, InverseRatio,
 *                   AddProb, MulProb, GetProb, ctor, dtor)
 * Layout: pointer to array of {uint32 value, float weight} pairs at +0x00,
 *         count at +0x08. Each entry is 8 bytes. state_surface returned 0
 *         typed fields (raw longlong* access); layout from manual decomp.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void                *entries;           /* +0x00  size 0x08  rw  ptr to allocated array of {value:uint32, weight:float} pairs */
    int32_t              count;             /* +0x08  size 0x04  rw  entry count; stored as int in qword slot */
    uint8_t              _pad_0C[0x04];     /* +0x0C  padding to align */
    /* size unknown, >= 0x10 */
} ccCpuProbSelect_s3;

_Static_assert(offsetof(ccCpuProbSelect_s3, entries) == 0x00, "ccCpuProbSelect_s3.entries");
_Static_assert(offsetof(ccCpuProbSelect_s3, count)   == 0x08, "ccCpuProbSelect_s3.count");

/* ======================================================================
 * ccDamageRequestMessage  (10 seed methods; 8 returned byte-cast only)
 * Encapsulates battle damage request. Constructor initializes 3 substructures
 * via FUN_140684430 and zeroes +0x68. Most fields hidden behind byte-cast
 * access patterns. Size unproven; minimum >= 0xA4.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              _pad_00[0x34];     /* +0x00  gap to first proven field */
    uint8_t              sub_struct_34[0x34];/* +0x34  size unk  r  sub-object initialized by FUN_140684430 in ctor */
    uint8_t              _pad_68_pre[0x00]; /* alignment */
    uint64_t             zero_field_68;     /* +0x68  size 0x08  w  zeroed in ctor: param_1[0xd] = 0 */
    uint8_t              _pad_70[0x1C];     /* +0x70  gap */
    uint8_t              sub_struct_8C[0x10];/* +0x8C  size unk  r  second sub-object initialized by FUN_140684430 */
    uint8_t              sub_struct_9C[0x08];/* +0x9C  size unk  r  third sub-object initialized by FUN_140684430 */
    /* size unknown, >= 0xA4 */
} ccDamageRequestMessage_s3;

_Static_assert(offsetof(ccDamageRequestMessage_s3, sub_struct_34)  == 0x34, "ccDamageRequestMessage_s3.sub_struct_34");
_Static_assert(offsetof(ccDamageRequestMessage_s3, zero_field_68)  == 0x68, "ccDamageRequestMessage_s3.zero_field_68");
_Static_assert(offsetof(ccDamageRequestMessage_s3, sub_struct_8C)  == 0x8C, "ccDamageRequestMessage_s3.sub_struct_8C");
_Static_assert(offsetof(ccDamageRequestMessage_s3, sub_struct_9C)  == 0x9C, "ccDamageRequestMessage_s3.sub_struct_9C");

/* ======================================================================
 * ccEvent::Manager  (4 wrapper methods: Update, Request, Clear, GetEvents)
 * Pure delegation wrapper; all field accesses come from Impl methods.
 * Manager itself has vtable + impl pointer (inferred from s2 pattern).
 * See ccEvent_Manager_Impl_s3 for actual fields.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void                *vtable;            /* +0x00  size 0x08  r  vtable dispatch (inferred from s2) */
    void                *impl;              /* +0x08  size 0x08  r  pointer to Impl (inferred from s2) */
    /* size unknown, >= 0x10 */
} ccEvent_Manager_s3;

_Static_assert(offsetof(ccEvent_Manager_s3, vtable) == 0x00, "ccEvent_Manager_s3.vtable");
_Static_assert(offsetof(ccEvent_Manager_s3, impl)   == 0x08, "ccEvent_Manager_s3.impl");

/* ======================================================================
 * ccEvent::Manager::Impl  (3 seed methods: Update, InsertRequest, Clear)
 * Fields from state_surface (6 fields across 3 seeds). Manages event
 * request insertion, update ticks, and clearing.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              _pad_00[0x68];     /* +0x00  gap to first proven field */
    uint64_t             current_tick;      /* +0x68  size 0x08  r  param_1[0xd]; source of iterator copy in Clear/Update */
    uint64_t             prev_tick;         /* +0x70  size 0x08  w  param_1[0xe] = [0xd] in Update/Clear */
    uint8_t              _pad_78[0x08];     /* +0x78  gap */
    uint64_t             sub_container_80;  /* +0x80  size 0x08  r  passed to FUN_140684c60(param_1+0x10) */
    uint8_t              _pad_88[0x10];     /* +0x88  gap */
    uint64_t             lock_obj;          /* +0x98  size 0x08  r  param_1[0x13]; dereferenced for event dispatch */
    uint32_t             request_counter;   /* +0xA0  size 0x04  rw read as qword in Update, written as dword in InsertRequest */
    uint8_t              _pad_A4[0x04];     /* +0xA4  gap */
    uint8_t              crit_section[0x28];/* +0xA8  size 0x28  r  passed to FUN_1406c0090(param_1+0x15) */
    /* size unknown, >= 0xD0 */
} ccEvent_Manager_Impl_s3;

_Static_assert(offsetof(ccEvent_Manager_Impl_s3, current_tick)     == 0x68, "ccEvent_Manager_Impl_s3.current_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl_s3, prev_tick)        == 0x70, "ccEvent_Manager_Impl_s3.prev_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl_s3, sub_container_80) == 0x80, "ccEvent_Manager_Impl_s3.sub_container_80");
_Static_assert(offsetof(ccEvent_Manager_Impl_s3, lock_obj)         == 0x98, "ccEvent_Manager_Impl_s3.lock_obj");
_Static_assert(offsetof(ccEvent_Manager_Impl_s3, request_counter)  == 0xA0, "ccEvent_Manager_Impl_s3.request_counter");
_Static_assert(offsetof(ccEvent_Manager_Impl_s3, crit_section)     == 0xA8, "ccEvent_Manager_Impl_s3.crit_section");

/* ======================================================================
 * ccFCurveSceneEffectGame  (6 seed methods; 2 returned byte-cast only)
 * FCurve-driven scene effects. Has vtable with virtual dispatch at +0x120.
 * state_surface found 5 fields across 4 seeds.
 * Size unproven; last proven access at +0x900 (vtable call).
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              _pad_00[0xFC];     /* +0x00  gap to first proven field */
    uint32_t             init_flag_FC;      /* +0xFC  size 0x04  w  zeroed in ctor: *(undefined4*)(param_1+0xfc)=0 */
    uint8_t              _pad_100[0x68];    /* +0x100 gap */
    uint32_t             fcurve_flag_168;   /* +0x168 size 0x04  r  param_1[0x2d] checked in Enable (ambiguous 4/8 byte) */
    uint8_t              _pad_16C[0x40];    /* +0x16C gap */
    uint32_t             fcurve_id_1AC;     /* +0x1AC size 0x04  r  compared to -1 sentinel in Enable */
    uint8_t              _pad_1B0[0x08];    /* +0x1B0 gap */
    uint64_t             fcurve_ptr_1B8;    /* +0x1B8 size 0x08  r  param_1[0x37] null-checked in Enable */
    uint8_t              _pad_1C0[0x740];   /* +0x1C0 gap to vtable call site */
    /* vtable at +0x00 implied by (**(code **)(*param_1 + 0x120)) virtual call */
    /* size unknown, >= 0x908 */
} ccFCurveSceneEffectGame_s3;

_Static_assert(offsetof(ccFCurveSceneEffectGame_s3, init_flag_FC)    == 0xFC,  "ccFCurveSceneEffectGame_s3.init_flag_FC");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s3, fcurve_flag_168) == 0x168, "ccFCurveSceneEffectGame_s3.fcurve_flag_168");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s3, fcurve_id_1AC)  == 0x1AC, "ccFCurveSceneEffectGame_s3.fcurve_id_1AC");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s3, fcurve_ptr_1B8)  == 0x1B8, "ccFCurveSceneEffectGame_s3.fcurve_ptr_1B8");

/* ======================================================================
 * ccFileLoadListForUi  (17 seed methods; all returned byte-cast only)
 * UI file-load list manager. Layout from manual decomp analysis.
 * Has vtable at +0x00, internal container at +0x20.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void                *vtable;            /* +0x00  size 0x08  w  vtable ptr set in ctor: *param_1 = &PTR_FUN_1409eb8c0 */
    uint8_t              _pad_08[0x10];     /* +0x08  gap */
    uint32_t             init_flag;         /* +0x18  size 0x04  w  zeroed in ctor: *(undefined4*)(param_1+3)=0 */
    uint8_t              _pad_1C[0x04];     /* +0x1C  alignment */
    void                *file_list;         /* +0x20  size 0x08  rw container ptr; **(longlong**)(param_1+0x20) in IsLoaded */
    void                *secondary_ptr;     /* +0x28  size 0x08  w  zeroed in ctor: param_1[5]=0 */
    /* size unknown, >= 0x30 */
} ccFileLoadListForUi_s3;

_Static_assert(offsetof(ccFileLoadListForUi_s3, vtable)        == 0x00, "ccFileLoadListForUi_s3.vtable");
_Static_assert(offsetof(ccFileLoadListForUi_s3, init_flag)     == 0x18, "ccFileLoadListForUi_s3.init_flag");
_Static_assert(offsetof(ccFileLoadListForUi_s3, file_list)     == 0x20, "ccFileLoadListForUi_s3.file_list");
_Static_assert(offsetof(ccFileLoadListForUi_s3, secondary_ptr) == 0x28, "ccFileLoadListForUi_s3.secondary_ptr");

#endif /* CMN03_S3_H */