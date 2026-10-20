/* cmn54.h — Storm 4 (s4) struct group cmn54
 * Auto-reconstructed from NSUNS4_release.exe (PC 1.09, image base 0x140000000).
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Sizes proven only where operator_new / allocator argument is visible in code.
 * Field names carried forward from s3 via storm_map where s4 symbols are absent.
 */
#ifndef CMN54_H
#define CMN54_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── nuccFogParam ────────────────────────────────────────────────
 * Evidence: ctor 0xA0F460, full ctor 0x226DB0, SetColor 0x1BDE50,
 *           SetDistNear 0xA0F4C0, SetDistFar 0xA0F4B0, SetClampFar 0xA0F480,
 *           i_InitializeZero 0xA32DF0.
 * Size: unknown, >= 0xA4 (last write at +0xA0 in full ctor).
 * Embedded sub-FogParam at +0x10 confirmed by ctor call FUN_140a0f460(param_1+0x10).
 */
typedef struct __attribute__((packed)) s4_nuccFogParam {
    /* +0x00 */ float    color_r;          /* SetColor: *param_1 = r              */
    /* +0x04 */ float    color_g;          /* SetColor: param_1[1] = g            */
    /* +0x08 */ float    color_b;          /* SetColor: param_1[2] = b            */
    /* +0x0C */ uint32_t pad_0c;           /* gap                                 */
    /* +0x10 */ float    dist_near;        /* SetDistNear: *(param_1+0x10)        */
    /* +0x14 */ float    dist_far;         /* SetDistFar / ctor: 0x7f7fffff       */
    /* +0x18 */ float    clamp_far;        /* SetClampFar: *(param_1+0x18)        */
    /* +0x1C */ uint8_t  embedded_vector3[12]; /* Vector3 ctor at +0x1C           */
    /* +0x28 */ uint8_t  embedded_matrix44[64]; /* Matrix44_MathGeo at +0x28      */
    /* +0x68 */ uint32_t field_68;         /* ctor: 0xffffffff                    */
    /* +0x6C */ uint32_t field_6c;         /* ctor: 0xffffffff                    */
    /* +0x70 */ uint32_t field_70;         /* ctor: 0xffffffff                    */
    /* +0x74 */ uint8_t  pad_74[44];       /* gap to +0xA0                        */
    /* +0xA0 */ uint32_t field_a0;         /* ctor: 0x3f800000 (1.0f)             */
} s4_nuccFogParam;

static_assert(offsetof(s4_nuccFogParam, color_r) == 0x00, "color_r");
static_assert(offsetof(s4_nuccFogParam, color_g) == 0x04, "color_g");
static_assert(offsetof(s4_nuccFogParam, color_b) == 0x08, "color_b");
static_assert(offsetof(s4_nuccFogParam, pad_0c) == 0x0C, "pad_0c");
static_assert(offsetof(s4_nuccFogParam, dist_near) == 0x10, "dist_near");
static_assert(offsetof(s4_nuccFogParam, dist_far) == 0x14, "dist_far");
static_assert(offsetof(s4_nuccFogParam, clamp_far) == 0x18, "clamp_far");
static_assert(offsetof(s4_nuccFogParam, embedded_vector3) == 0x1C, "embedded_vector3");
static_assert(offsetof(s4_nuccFogParam, embedded_matrix44) == 0x28, "embedded_matrix44");
static_assert(offsetof(s4_nuccFogParam, field_68) == 0x68, "field_68");
static_assert(offsetof(s4_nuccFogParam, field_6c) == 0x6C, "field_6c");
static_assert(offsetof(s4_nuccFogParam, field_70) == 0x70, "field_70");
static_assert(offsetof(s4_nuccFogParam, pad_74) == 0x74, "pad_74");
static_assert(offsetof(s4_nuccFogParam, field_a0) == 0xA0, "field_a0");

/* ─── nuccFilePathStr ─────────────────────────────────────────────
 * Evidence: Split 0xA36E40, Clear 0xA36B00, CopyStr 0xA36C10,
 *           Split(ctor) 0x46E770, dtor 0x46E830.
 * Size: unknown, >= 0x40 (last field merged at +0x38, 8 bytes).
 * vtable: PTR_FUN_140fffb78 (Split ctor), overridden to PTR_FUN_1410075d8 (dtor).
 */
typedef struct __attribute__((packed)) s4_nuccFilePathStr {
    /* +0x00 */ void*    vtable;           /* Split ctor / dtor                   */
    /* +0x08 */ void*    allocator;        /* CopyStr: *(param_1+8)               */
    /* +0x10 */ uint8_t  pad_10[8];        /* no access in any method             */
    /* +0x18 */ char*    drive;            /* Split writes, Clear frees           */
    /* +0x20 */ char*    directory;        /* Split writes, Clear frees           */
    /* +0x28 */ char*    filename;         /* Split writes, Clear frees           */
    /* +0x30 */ char*    extension;        /* Split/CopyStr, Clear frees          */
    /* +0x38 */ char*    merged;           /* dtor frees param_1[7], Split writes */
} s4_nuccFilePathStr;

static_assert(offsetof(s4_nuccFilePathStr, vtable) == 0x00, "vtable");
static_assert(offsetof(s4_nuccFilePathStr, allocator) == 0x08, "allocator");
static_assert(offsetof(s4_nuccFilePathStr, pad_10) == 0x10, "pad_10");
static_assert(offsetof(s4_nuccFilePathStr, drive) == 0x18, "drive");
static_assert(offsetof(s4_nuccFilePathStr, directory) == 0x20, "directory");
static_assert(offsetof(s4_nuccFilePathStr, filename) == 0x28, "filename");
static_assert(offsetof(s4_nuccFilePathStr, extension) == 0x30, "extension");
static_assert(offsetof(s4_nuccFilePathStr, merged) == 0x38, "merged");

/* ─── nuccFileLoadList ────────────────────────────────────────────
 * Evidence: ctor 0xA050E0, IsLoaded 0xA05330, UnloadAll 0xA05830,
 *           GetData 0xA05190, GetProgress 0x647034, Load 0xA054F0,
 *           dtor 0xA05110.
 * Size: unknown, >= 0x50 (last proven field at +0x48).
 * NOTE: s4 inherits ccGamePropertyPermit (not ccTaskBase as in s3).
 *       Base layout differs from s3; fields below are s4-specific.
 * vtable: PTR_FUN_1411044c8 (ctor sets).
 */
typedef struct __attribute__((packed)) s4_nuccFileLoadList {
    /* +0x00 */ void*    vtable;           /* ctor: PTR_FUN_1411044c8             */
    /* +0x08 */ uint8_t  base_block[16];   /* ccGamePropertyPermit base           */
    /* +0x18 */ void*    tree_ptr;         /* IsLoaded/GetData/UnloadAll: *(param_1+0x18) */
    /* +0x20 */ uint8_t  base_reserved[8]; /* padding                             */
    /* +0x28 */ uint8_t  pad_28[8];        /* gap                                 */
    /* +0x30 */ void*    node_cleanup;     /* dtor: free param_1[3] → actually +0x18 area */
    /* +0x38 */ uint8_t  pad_38[8];        /* gap                                 */
    /* +0x40 */ uint32_t field_40;         /* UnloadAll: resets param_1[4]=0 → +0x40? */
    /* +0x44 */ uint32_t pad_44;           /* alignment                           */
    /* +0x48 */ void*    progress_str;     /* GetProgress: *(param_1+0x48)        */
} s4_nuccFileLoadList;

static_assert(offsetof(s4_nuccFileLoadList, vtable) == 0x00, "vtable");
static_assert(offsetof(s4_nuccFileLoadList, base_block) == 0x08, "base_block");
static_assert(offsetof(s4_nuccFileLoadList, tree_ptr) == 0x18, "tree_ptr");
static_assert(offsetof(s4_nuccFileLoadList, base_reserved) == 0x20, "base_reserved");
static_assert(offsetof(s4_nuccFileLoadList, pad_28) == 0x28, "pad_28");
static_assert(offsetof(s4_nuccFileLoadList, node_cleanup) == 0x30, "node_cleanup");
static_assert(offsetof(s4_nuccFileLoadList, pad_38) == 0x38, "pad_38");
static_assert(offsetof(s4_nuccFileLoadList, field_40) == 0x40, "field_40");
static_assert(offsetof(s4_nuccFileLoadList, pad_44) == 0x44, "pad_44");
static_assert(offsetof(s4_nuccFileLoadList, progress_str) == 0x48, "progress_str");

#endif /* CMN54_H */