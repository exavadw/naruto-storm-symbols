/* cmn54.h — Storm 1 (s1) struct group cmn54
 * INFERRED from static decompilation of NSUNS1.exe (PC x64, image base 0x140000000).
 * NOT CONFIRMED by runtime trace. All field names derived from s1 code/strings only.
 * Sizes proven from game code where noted; otherwise "size unknown, >= 0xN".
 */
#ifndef CMN54_H
#define CMN54_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccFogParam
 * Size: 0x30 (proven: embedded at +0x1a0 in nuccSys, next field at +0x1d0)
 * Vtable: none found (no vptr write in ctor)
 * Fields from: nuccFogParam::nuccFogParam (0x4BA2A0), SetColor (0x4BA2D0/0x144B70),
 *              SetClampFar (0x4BA2C0), SetDistFar (0x4BA2F0), SetDistNear (0x4BA300)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFogParam {
    /* 0x00 */ uint32_t color_r;          /* PRES: SetColor writes param_1[0] */
    /* 0x04 */ uint32_t color_g;          /* PRES: SetColor writes param_1[1] */
    /* 0x08 */ uint32_t color_b;          /* PRES: SetColor writes param_1[2] */
    /* 0x0C */ uint32_t pad_0c;           /* UNKNOWN: padding to align 0x10 */
    /* 0x10 */ float dist_near;           /* PRES: SetDistNear writes *(param_1+0x10) */
    /* 0x14 */ float dist_far;            /* PRES: SetDistFar writes *(param_1+0x14); ctor sets 0x7f7fffff */
    /* 0x18 */ uint32_t clamp_far;        /* PRES: SetClampFar writes *(param_1+0x18) */
    /* 0x1C */ uint32_t pad_1c;           /* UNKNOWN: padding to reach size 0x30 */
    /* 0x20 */ uint8_t reserved[0x10];    /* UNKNOWN: gap 0x20..0x2F within proven size 0x30 */
} nuccFogParam;

static_assert(offsetof(nuccFogParam, color_r) == 0x00, "nuccFogParam.color_r");
static_assert(offsetof(nuccFogParam, color_g) == 0x04, "nuccFogParam.color_g");
static_assert(offsetof(nuccFogParam, color_b) == 0x08, "nuccFogParam.color_b");
static_assert(offsetof(nuccFogParam, pad_0c) == 0x0C, "nuccFogParam.pad_0c");
static_assert(offsetof(nuccFogParam, dist_near) == 0x10, "nuccFogParam.dist_near");
static_assert(offsetof(nuccFogParam, dist_far) == 0x14, "nuccFogParam.dist_far");
static_assert(offsetof(nuccFogParam, clamp_far) == 0x18, "nuccFogParam.clamp_far");
static_assert(offsetof(nuccFogParam, pad_1c) == 0x1C, "nuccFogParam.pad_1c");
static_assert(offsetof(nuccFogParam, reserved) == 0x20, "nuccFogParam.reserved");
static_assert(sizeof(nuccFogParam) == 0x30, "nuccFogParam size proven from nuccSys embedding");

/* =========================================================================
 * nuccFilePathStr
 * Size unknown, >= 0x40 (last accessed field at +0x38 is a pointer; dtor accesses param_1[7]=+0x38)
 * Vtable: PTR_FUN_1406584d0 (set in ctor 0x14DC9C and dtor 0x14E884)
 * Fields from: Split (0x483040), Clear (0x482D00), Merge (0x482EB0), CopyStr (0x482E10),
 *              ctor (0x14DC9C), dtor (0x14E884)
 * Layout: vptr + allocator ptr at +0x08, then 5 string pointers at +0x18,+0x20,+0x28,+0x30,+0x38
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFilePathStr {
    /* 0x00 */ void *vtable;              /* PRES: PTR_FUN_1406584d0 set in ctor/dtor */
    /* 0x08 */ void *allocator;           /* PRES: passed as 2nd arg to operator_new__ in CopyStr/Merge */
    /* 0x10 */ uint8_t pad_10[0x08];      /* UNKNOWN: gap before first string ptr */
    /* 0x18 */ char *drive;               /* PRES: Split copies drive prefix (before ':') here */
    /* 0x20 */ char *directory;           /* PRES: Split copies path (after '/', before ext) here */
    /* 0x28 */ char *filename;            /* PRES: Split copies name (before '.') here */
    /* 0x30 */ char *extension;           /* PRES: Split copies extension (from '.') here */
    /* 0x38 */ char *merged;              /* PRES: Merge result stored here; cleared in Clear/dtor */
} nuccFilePathStr;

static_assert(offsetof(nuccFilePathStr, vtable) == 0x00, "nuccFilePathStr.vtable");
static_assert(offsetof(nuccFilePathStr, allocator) == 0x08, "nuccFilePathStr.allocator");
static_assert(offsetof(nuccFilePathStr, pad_10) == 0x10, "nuccFilePathStr.pad_10");
static_assert(offsetof(nuccFilePathStr, drive) == 0x18, "nuccFilePathStr.drive");
static_assert(offsetof(nuccFilePathStr, directory) == 0x20, "nuccFilePathStr.directory");
static_assert(offsetof(nuccFilePathStr, filename) == 0x28, "nuccFilePathStr.filename");
static_assert(offsetof(nuccFilePathStr, extension) == 0x30, "nuccFilePathStr.extension");
static_assert(offsetof(nuccFilePathStr, merged) == 0x38, "nuccFilePathStr.merged");
/* No sizeof assert: size not proven beyond >= 0x40 */

/* =========================================================================
 * nuccFCurveThermal2
 * Size unknown, >= 0x48 (ParseParam passes param_1+0x48 to nuccFCurveList::Add)
 * Only 1 method in s1 (ParseParam); listed in report as below threshold.
 * No fields reconstructed beyond the fcurve list anchor.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveThermal2 {
    /* 0x00 */ uint8_t unknown[0x48];     /* UNKNOWN: no field-level access in s1 methods */
    /* 0x48 */ uint8_t fcurve_list[0x08]; /* PRES: passed to nuccFCurveList_nuccTypeThermal_::Add */
} nuccFCurveThermal2;

static_assert(offsetof(nuccFCurveThermal2, unknown) == 0x00, "nuccFCurveThermal2.unknown");
static_assert(offsetof(nuccFCurveThermal2, fcurve_list) == 0x48, "nuccFCurveThermal2.fcurve_list");
/* No sizeof assert: size not proven beyond >= 0x50 */

/* =========================================================================
 * nuccFCurveThermal
 * Size unknown, >= 0x48 (ParseParam passes param_1+0x48 to nuccFCurveList::Add)
 * Only 1 method in s1 (ParseParam); listed in report as below threshold.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveThermal {
    /* 0x00 */ uint8_t unknown[0x48];     /* UNKNOWN: no field-level access in s1 methods */
    /* 0x48 */ uint8_t fcurve_list[0x08]; /* PRES: passed to nuccFCurveList_nuccTypeThermal_::Add */
} nuccFCurveThermal;

static_assert(offsetof(nuccFCurveThermal, unknown) == 0x00, "nuccFCurveThermal.unknown");
static_assert(offsetof(nuccFCurveThermal, fcurve_list) == 0x48, "nuccFCurveThermal.fcurve_list");
/* No sizeof assert: size not proven beyond >= 0x50 */

/* =========================================================================
 * nuccFCurveThermalDeform
 * Size unknown, >= 0x30 (ParseParam passes param_1+0x30 to nuccFCurveList::Add)
 * Only 1 method in s1 (ParseParam); listed in report as below threshold.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveThermalDeform {
    /* 0x00 */ uint8_t unknown[0x30];     /* UNKNOWN: no field-level access in s1 methods */
    /* 0x30 */ uint8_t fcurve_list[0x08]; /* PRES: passed to nuccFCurveList_nuccTypeThermalDeform_::Add */
} nuccFCurveThermalDeform;

static_assert(offsetof(nuccFCurveThermalDeform, unknown) == 0x00, "nuccFCurveThermalDeform.unknown");
static_assert(offsetof(nuccFCurveThermalDeform, fcurve_list) == 0x30, "nuccFCurveThermalDeform.fcurve_list");
/* No sizeof assert: size not proven beyond >= 0x38 */

/* =========================================================================
 * nuccFileLoadList
 * Size unknown, >= 0x40 (UnloadAll accesses +0x18,+0x20,+0x28; Unload accesses param_1[8]=+0x40)
 * Only 2 methods in s1 (Unload, UnloadAll); listed in report as below threshold.
 * Contains std::__tree (map) at +0x18 and additional state.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFileLoadList {
    /* 0x00 */ uint8_t unknown[0x18];     /* UNKNOWN: possible vtable or header */
    /* 0x18 */ uint8_t tree_map[0x20];    /* PRES: std::__tree for map<uint,nuccFileLoad>; UnloadAll iterates */
    /* 0x38 */ uint8_t pad_38[0x08];      /* UNKNOWN: gap */
    /* 0x40 */ uint8_t extra_state[0x08]; /* PRES: Unload reads param_1[8]; purpose unclear */
} nuccFileLoadList;

static_assert(offsetof(nuccFileLoadList, unknown) == 0x00, "nuccFileLoadList.unknown");
static_assert(offsetof(nuccFileLoadList, tree_map) == 0x18, "nuccFileLoadList.tree_map");
static_assert(offsetof(nuccFileLoadList, pad_38) == 0x38, "nuccFileLoadList.pad_38");
static_assert(offsetof(nuccFileLoadList, extra_state) == 0x40, "nuccFileLoadList.extra_state");
/* No sizeof assert: size not proven beyond >= 0x48 */

#endif /* CMN54_H */