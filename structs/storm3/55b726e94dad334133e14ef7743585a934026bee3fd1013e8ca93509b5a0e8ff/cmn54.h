/* cmn54.h — s3 (NSUNS3.exe, PC x64) struct layouts for group cmn54
 * Status: INFERRED (static decompilation only; no runtime trace confirmation)
 * Build: s3 / NSUNS3.exe-a7124b / image base 0x140000000
 * Date: 2026-10-19
 *
 * Own-game naming: all names derived from s3 decompiled code and strings only.
 * Sizes are minimum bounds from highest observed access unless proven otherwise.
 */

#ifndef CMN54_S3_H
#define CMN54_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccFogParam
 * Evidence: ctor 0x6B6ED0, SetColor 0x6B6F00, SetClampFar 0x6B6EF0,
 *           SetDistFar 0x6B6F20, SetDistNear 0x6B6F30
 * Size: >= 0x1C (last field clamp_far at +0x18, 4 bytes)
 * Vtable: none (no vptr write in ctor)
 * Note: ctor 0x4E26E4 is an array initializer that embeds nuccFogParam
 *       at stride 0x30 starting at parent+0x1A0, but this does not prove
 *       the standalone size of nuccFogParam itself.
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_nuccFogParam {
    uint32_t color_r;          /* +0x00  ctor: *param_1 = 0; SetColor copies 3x uint32 */
    uint32_t color_g;          /* +0x04  SetColor: param_1[1] */
    uint32_t color_b;          /* +0x08  SetColor: param_1[2] */
    uint8_t  pad_0c[4];        /* +0x0C  gap to dist_near */
    float    dist_near;        /* +0x10  SetDistNear: *(param_1+0x10); ctor sets via param_1[1]=0x3f800000 as undefined8 at +0x08 covering +0x08..+0x0F, but SetDistNear writes float at +0x10 */
    float    dist_far;         /* +0x14  SetDistFar: *(param_1+0x14); ctor: *(param_1+0x14)=0x7f7fffff */
    float    clamp_far;        /* +0x18  SetClampFar: *(param_1+0x18) */
} ns3_nuccFogParam;

static_assert(offsetof(ns3_nuccFogParam, color_r)   == 0x00, "ns3_nuccFogParam.color_r");
static_assert(offsetof(ns3_nuccFogParam, color_g)   == 0x04, "ns3_nuccFogParam.color_g");
static_assert(offsetof(ns3_nuccFogParam, color_b)   == 0x08, "ns3_nuccFogParam.color_b");
static_assert(offsetof(ns3_nuccFogParam, pad_0c)    == 0x0C, "ns3_nuccFogParam.pad_0c");
static_assert(offsetof(ns3_nuccFogParam, dist_near) == 0x10, "ns3_nuccFogParam.dist_near");
static_assert(offsetof(ns3_nuccFogParam, dist_far)  == 0x14, "ns3_nuccFogParam.dist_far");
static_assert(offsetof(ns3_nuccFogParam, clamp_far) == 0x18, "ns3_nuccFogParam.clamp_far");

/* =========================================================================
 * nuccFilePathStr
 * Evidence: Split 0x6CDA20, Clear 0x6CD870, CopyStr 0x6CD980, dtor 0x692750
 * Size: >= 0x40 (last field merged at +0x38 is a pointer, 8 bytes → end at 0x40)
 * Vtable: PTR_FUN_1409dd250 (set in dtor before Clear), PTR_FUN_1409ec308 (final)
 * ========================================================================= */
typedef struct __attribute__((packed)) ns3_nuccFilePathStr {
    void    *vtable;           /* +0x00  dtor sets PTR_FUN_1409dd250 then PTR_FUN_1409ec308 */
    void    *allocator;        /* +0x08  CopyStr reads *(param_1+8) for operator_new__ */
    uint8_t  pad_10[8];        /* +0x10  gap: no access in any method */
    char    *drive;            /* +0x18  Split writes, Clear frees */
    char    *directory;        /* +0x20  Split writes, Clear frees */
    char    *filename;         /* +0x28  Split writes, Clear frees */
    char    *extension;        /* +0x30  Split via CopyStr, Clear frees */
    char    *merged;           /* +0x38  dtor frees param_1[7], Split writes */
} ns3_nuccFilePathStr;

static_assert(offsetof(ns3_nuccFilePathStr, vtable)    == 0x00, "ns3_nuccFilePathStr.vtable");
static_assert(offsetof(ns3_nuccFilePathStr, allocator) == 0x08, "ns3_nuccFilePathStr.allocator");
static_assert(offsetof(ns3_nuccFilePathStr, pad_10)    == 0x10, "ns3_nuccFilePathStr.pad_10");
static_assert(offsetof(ns3_nuccFilePathStr, drive)     == 0x18, "ns3_nuccFilePathStr.drive");
static_assert(offsetof(ns3_nuccFilePathStr, directory) == 0x20, "ns3_nuccFilePathStr.directory");
static_assert(offsetof(ns3_nuccFilePathStr, filename)  == 0x28, "ns3_nuccFilePathStr.filename");
static_assert(offsetof(ns3_nuccFilePathStr, extension) == 0x30, "ns3_nuccFilePathStr.extension");
static_assert(offsetof(ns3_nuccFilePathStr, merged)    == 0x38, "ns3_nuccFilePathStr.merged");

/* =========================================================================
 * nuccFileLoadList (inherits ccTaskBase in s3)
 * Evidence: ctor 0x209C3C, dtor 0x69B650, Load 0x69B990/0x44D6D4,
 *           UnloadAll 0x69BB90, IsLoaded 0x69B870, GetData 0x69B6D0
 * Base class: ccTaskBase (ctor 0x73C520 writes vtable + GameActor::Base at +0x18)
 * Size: >= 0x688 (Load 0x44D6D4 accesses vector at param_1+0x680, std::vector = 0x18 → end ≥ 0x698)
 *       However only fields up to +0x70 have named evidence from cmn54 methods.
 *       The vector at +0x680 proves the object extends to at least 0x698.
 * Vtable: PTR_FUN_1408b6b88 (set in ctor 0x209C3C)
 *         PTR_FUN_1409de7a8 (intermediate in dtor 0x69B650)
 *         PTR_FUN_1409ec308 (final in dtor)
 * ========================================================================= */

/* ccTaskBase base layout (from ctor 0x73C520, dtor 0x73C570):
 *   +0x00  vtable (PTR_FUN_1409eb978)
 *   +0x08  BlockAllocator fields (inherited)
 *   +0x18  GameActor::Base sub-object (ccTaskBase ctor calls GameActor::Base::Base(param_1+3) = +0x18)
 *   +0x28  memory handle (dtor frees param_1[5] = +0x28)
 *   +0x30  unknown (param_1[6])
 *   +0x38  final vtable slot (dtor sets param_1[5]=PTR_FUN_1409ec308... actually [5]=+0x28)
 * ccTaskBase occupies +0x00..+0x3F based on nuccFileLoadList ctor writing own fields at +0x40+.
 */

typedef struct __attribute__((packed)) ns3_nuccFileLoadList {
    /* --- ccTaskBase base (+0x00..+0x3F) --- */
    void    *base_vtable;      /* +0x00  ccTaskBase ctor sets PTR_FUN_1409eb978, overridden by nuccFileLoadList ctor */
    uint8_t  base_block_alloc[0x10]; /* +0x08  Nucc::Memory::BlockAllocator fields */
    uint8_t  base_game_actor[0x10];  /* +0x18  GameActor::Base sub-object (ccTaskBase ctor: param_1+3) */
    void    *base_mem_handle;  /* +0x28  ccTaskBase dtor frees param_1[5] */
    uint8_t  base_reserved[0x10];    /* +0x30  ccTaskBase padding/reserved to +0x40 */

    /* --- nuccFileLoadList own fields (+0x40+) --- */
    uint32_t task_type;        /* +0x40  ctor: param_1[8] = 0xb */
    uint32_t load_id;          /* +0x44  ctor: param_1[10] = 0xffffffff (note: [10] as undefined4* = +0x50? recheck below) */
    void    *name_ptr;         /* +0x48  ctor: param_1[9] = PTR_s_BEGIN_140aa11f0 */
    uint32_t field_50;         /* +0x50  ctor: *(undefined4*)(param_1+10) = 0xffffffff → param_1 as undefined4*, [10]=+0x50 */
    uint64_t field_54;         /* +0x54  ctor: *(param_1+0x54) = 0 */
    uint32_t field_5c;         /* +0x5C  ctor: *(param_1+0x5c) = 0 */
    uint32_t field_60;         /* +0x60  ctor: *(param_1+0xc as undefined4*) = 1 → +0x60 */
    uint8_t  pad_64[4];        /* +0x64  gap to field_68 */
    uint64_t field_68;         /* +0x68  ctor: param_1[0xd] = 0 → +0x68 */
    uint64_t field_70;         /* +0x70  ctor: param_1[0xe] = 0 → +0x70 */
    uint8_t  gap_78[0x608];    /* +0x78  gap to vector at +0x680 */
    uint8_t  file_path_vector[0x18]; /* +0x680  Load 0x44D6D4: push_back at param_1+0x680, std::vector size=0x18 */
} ns3_nuccFileLoadList;

static_assert(offsetof(ns3_nuccFileLoadList, base_vtable)      == 0x00,  "ns3_nuccFileLoadList.base_vtable");
static_assert(offsetof(ns3_nuccFileLoadList, base_block_alloc) == 0x08,  "ns3_nuccFileLoadList.base_block_alloc");
static_assert(offsetof(ns3_nuccFileLoadList, base_game_actor)  == 0x18,  "ns3_nuccFileLoadList.base_game_actor");
static_assert(offsetof(ns3_nuccFileLoadList, base_mem_handle)  == 0x28,  "ns3_nuccFileLoadList.base_mem_handle");
static_assert(offsetof(ns3_nuccFileLoadList, base_reserved)    == 0x30,  "ns3_nuccFileLoadList.base_reserved");
static_assert(offsetof(ns3_nuccFileLoadList, task_type)        == 0x40,  "ns3_nuccFileLoadList.task_type");
static_assert(offsetof(ns3_nuccFileLoadList, load_id)          == 0x44,  "ns3_nuccFileLoadList.load_id");
static_assert(offsetof(ns3_nuccFileLoadList, name_ptr)         == 0x48,  "ns3_nuccFileLoadList.name_ptr");
static_assert(offsetof(ns3_nuccFileLoadList, field_50)         == 0x50,  "ns3_nuccFileLoadList.field_50");
static_assert(offsetof(ns3_nuccFileLoadList, field_54)         == 0x54,  "ns3_nuccFileLoadList.field_54");
static_assert(offsetof(ns3_nuccFileLoadList, field_5c)         == 0x5C,  "ns3_nuccFileLoadList.field_5c");
static_assert(offsetof(ns3_nuccFileLoadList, field_60)         == 0x60,  "ns3_nuccFileLoadList.field_60");
static_assert(offsetof(ns3_nuccFileLoadList, pad_64)           == 0x64,  "ns3_nuccFileLoadList.pad_64");
static_assert(offsetof(ns3_nuccFileLoadList, field_68)         == 0x68,  "ns3_nuccFileLoadList.field_68");
static_assert(offsetof(ns3_nuccFileLoadList, field_70)         == 0x70,  "ns3_nuccFileLoadList.field_70");
static_assert(offsetof(ns3_nuccFileLoadList, gap_78)           == 0x78,  "ns3_nuccFileLoadList.gap_78");
static_assert(offsetof(ns3_nuccFileLoadList, file_path_vector) == 0x680, "ns3_nuccFileLoadList.file_path_vector");

/* =========================================================================
 * Below-threshold classes (only 1 method each in s3, < 3 required)
 * Listed for completeness; no full reconstruction attempted.
 *
 * nuccFCurveThermal       — ParseParam 0x720AC0: accesses param_1+0x48 (nuccFCurveList)
 * nuccFCurveThermal2      — ParseParam 0x720A00: accesses param_1+0x48 (nuccFCurveList)
 * nuccFCurveThermalDeform — ParseParam 0x720B80: accesses param_1+0x30 (nuccFCurveList)
 * ========================================================================= */

#endif /* CMN54_S3_H */
