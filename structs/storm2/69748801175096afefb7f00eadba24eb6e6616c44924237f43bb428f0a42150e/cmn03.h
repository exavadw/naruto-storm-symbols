/* cmn03.h — Storm 2 (NSUNS2.exe) struct group cmn03
 * INFERRED layouts from s2 decompilation. Not CONFIRMED at runtime.
 * All offsets proven from PC x64 code only. Sizes unproven unless noted.
 */
#ifndef CMN03_S2_H
#define CMN03_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for engine types whose size is known from other groups */
typedef struct { float x, y, z; } Nucc_Vector3;              /* 0x0C */
typedef struct { float m[16]; } Nucc_Matrix44_MathGeo;       /* 0x40 */

/* ======================================================================
 * ccCpuCoord  (7 methods: SetFromAxis, SetFromNormalDir, GetDirVector,
 *              CalcDirMatrix, RotatePosition, TransWorldVec, TransLocalPos)
 * Layout: direction matrix region at +0x00 (64 bytes), coord data at +0x40.
 * Size unproven (no operator new / allocator size found in these methods).
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              dir_matrix[0x40];  /* +0x00  size 0x40  rw  matrix/quaternion region passed to math helpers */
    uint8_t              coord_data[0x40];  /* +0x40  size 0x40  rw  written by FUN_140586540 after FUN_140586bd0 */
    /* size unknown, >= 0x80 */
} ccCpuCoord_s2;

_Static_assert(offsetof(ccCpuCoord_s2, dir_matrix) == 0x00, "ccCpuCoord_s2.dir_matrix");
_Static_assert(offsetof(ccCpuCoord_s2, coord_data) == 0x40, "ccCpuCoord_s2.coord_data");

/* ======================================================================
 * ccCpuProbSelect  (10 methods: Init, SetProb, ConvertRatio, InverseRatio,
 *                   AddProb, MulProb, GetProb, ctor, dtor)
 * Layout: pointer to array of {int32 id, float prob} pairs at +0x00,
 *         count at +0x08. Each entry is 8 bytes (stride piVar3 += 2 ints).
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    int32_t             *entries;           /* +0x00  size 0x08  rw  ptr to array of {id:int32, prob:float} pairs */
    int32_t              count;             /* +0x08  size 0x04  rw  entry count; loop bound in SetProb/GetProb */
    uint8_t              _pad_0C[0x04];     /* +0x0C  padding to align */
    /* size unknown, >= 0x10 */
} ccCpuProbSelect_s2;

_Static_assert(offsetof(ccCpuProbSelect_s2, entries) == 0x00, "ccCpuProbSelect_s2.entries");
_Static_assert(offsetof(ccCpuProbSelect_s2, count)   == 0x08, "ccCpuProbSelect_s2.count");

/* ======================================================================
 * ccDamageRequestMessage  (below threshold in s2 — see report)
 * No s2 methods found with >= 3. Listed in report only.
 * ====================================================================== */

/* ======================================================================
 * ccEffectGarSand  (below threshold in s2 — see report)
 * No s2 methods found with >= 3. Listed in report only.
 * ====================================================================== */

/* ======================================================================
 * ccEvent::Manager  (7 methods: Update, Request, Clear, GetEvents,
 *                    Impl::Update, Impl::InsertRequest, Impl::Clear)
 * Wraps Impl; fields come from Impl analysis. Manager itself has a vtable
 * and an impl pointer. Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void                *vtable;            /* +0x00  size 0x08  r  vtable dispatch */
    void                *impl;              /* +0x08  size 0x08  r  GetEvents returns impl+0x68 */
    /* size unknown, >= 0x10 */
} ccEvent_Manager_s2;

_Static_assert(offsetof(ccEvent_Manager_s2, vtable) == 0x00, "ccEvent_Manager_s2.vtable");
_Static_assert(offsetof(ccEvent_Manager_s2, impl)   == 0x08, "ccEvent_Manager_s2.impl");

/* ======================================================================
 * ccEvent::Manager::Impl  (3 seed methods: Update, InsertRequest, Clear)
 * Fields from state_surface + manual decomp analysis.
 * Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              _pad_00[0x68];     /* +0x00  gap to first proven field */
    uint64_t             current_tick;      /* +0x68  size 0x08  r  param_1[0xd] copied to [0xe] */
    uint64_t             prev_tick;         /* +0x70  size 0x08  w  param_1[0xe] = [0xd] in Update/Clear */
    uint8_t              _pad_78[0x08];     /* +0x78  gap */
    uint64_t             sub_container_80;  /* +0x80  size 0x08  r  passed to FUN_140585990(param_1+0x10) */
    uint8_t              _pad_88[0x10];     /* +0x88  gap */
    uint64_t             lock_obj;          /* +0x98  size 0x08  r  param_1[0x13] passed to FUN_14065f480 */
    uint32_t             request_counter;   /* +0xA0  size 0x04  rw incremented in InsertRequest, cleared in Update */
    uint8_t              _pad_A4[0x04];     /* +0xA4  gap */
    uint8_t              crit_section[0x28];/* +0xA8  size 0x28  r  nuccCriticalSection via FUN_1405ac160(param_1+0x15) */
    /* size unknown, >= 0xD0 */
} ccEvent_Manager_Impl_s2;

_Static_assert(offsetof(ccEvent_Manager_Impl_s2, current_tick)     == 0x68, "ccEvent_Manager_Impl_s2.current_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl_s2, prev_tick)        == 0x70, "ccEvent_Manager_Impl_s2.prev_tick");
_Static_assert(offsetof(ccEvent_Manager_Impl_s2, sub_container_80) == 0x80, "ccEvent_Manager_Impl_s2.sub_container_80");
_Static_assert(offsetof(ccEvent_Manager_Impl_s2, lock_obj)         == 0x98, "ccEvent_Manager_Impl_s2.lock_obj");
_Static_assert(offsetof(ccEvent_Manager_Impl_s2, request_counter)  == 0xA0, "ccEvent_Manager_Impl_s2.request_counter");
_Static_assert(offsetof(ccEvent_Manager_Impl_s2, crit_section)     == 0xA8, "ccEvent_Manager_Impl_s2.crit_section");

/* ======================================================================
 * ccFCurveSceneEffectGame  (4 seed methods: Enable x2, Disable, dtor)
 * Fields from state_surface. Large class with many FCurve IDs and enable flags.
 * Size unproven; last proven field at +0x900 (vtable call).
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t              _pad_00[0x168];    /* +0x00  gap to first proven field */
    uint32_t             fcurve_flag_168;   /* +0x168 size 0x04  r  param_1[0x2d] checked in Enable */
    uint8_t              _pad_16C[0x40];    /* +0x16C gap */
    uint32_t             fcurve_id_1AC;     /* +0x1AC size 0x04  r  compared to -1 in Enable */
    uint8_t              _pad_1B0[0x00];    /* alignment */
    uint64_t             fcurve_ptr_1B0;    /* +0x1B0 size 0x08  r  param_1[0x36] checked in Enable */
    uint8_t              _pad_1B8[0x748];   /* +0x1B8 gap to vtable call site */
    /* vtable at +0x00 implied by (**(code **)(*param_1 + 0x120)) virtual call */
    /* size unknown, >= 0x908 */
} ccFCurveSceneEffectGame_s2;

_Static_assert(offsetof(ccFCurveSceneEffectGame_s2, fcurve_flag_168) == 0x168, "ccFCurveSceneEffectGame_s2.fcurve_flag_168");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s2, fcurve_id_1AC)  == 0x1AC, "ccFCurveSceneEffectGame_s2.fcurve_id_1AC");
_Static_assert(offsetof(ccFCurveSceneEffectGame_s2, fcurve_ptr_1B0) == 0x1B0, "ccFCurveSceneEffectGame_s2.fcurve_ptr_1B0");

/* ======================================================================
 * ccFileLoadListForUi  (16 seed methods: LoadTh, Unload, UnloadAll, ctor,
 *                       dtor, IsFind, IsLoaded, GetData, GetLoadedFileNum,
 *                       Reserve, ClearReserve, GetLoadFileNum)
 * Fields from manual decomp analysis (state_surface returned 0 due to
 * byte-cast access pattern). Size unproven.
 * ====================================================================== */
typedef struct __attribute__((packed)) {
    void                *vtable;            /* +0x00  size 0x08  rw  vtable ptr */
    uint8_t              _pad_08[0x10];     /* +0x08  gap */
    uint32_t             init_flag;         /* +0x18  size 0x04  rw  0->1 on first LoadTh */
    uint8_t              _pad_1C[0x04];     /* +0x1C  alignment */
    void                *file_list;         /* +0x20  size 0x08  rw  std::list head ptr */
    void                *pool_allocator;    /* +0x28  size 0x08  rw  nuccPoolAllocation ptr */
    /* size unknown, >= 0x30 */
} ccFileLoadListForUi_s2;

_Static_assert(offsetof(ccFileLoadListForUi_s2, vtable)         == 0x00, "ccFileLoadListForUi_s2.vtable");
_Static_assert(offsetof(ccFileLoadListForUi_s2, init_flag)      == 0x18, "ccFileLoadListForUi_s2.init_flag");
_Static_assert(offsetof(ccFileLoadListForUi_s2, file_list)      == 0x20, "ccFileLoadListForUi_s2.file_list");
_Static_assert(offsetof(ccFileLoadListForUi_s2, pool_allocator) == 0x28, "ccFileLoadListForUi_s2.pool_allocator");

#endif /* CMN03_S2_H */