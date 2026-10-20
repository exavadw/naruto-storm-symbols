/* cmn54.h — Storm 2 (s2) struct group cmn54
 * INFERRED from static decompilation of NSUNS2.exe (PC x64, image base 0x140000000).
 * NOT CONFIRMED by runtime trace. All field names derived from s2 code/strings only.
 * Sizes proven from game code where noted; otherwise "size unknown, >= 0xN".
 */
#ifndef CMN54_H
#define CMN54_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccFogParam
 * Size unknown, >= 0x1C (last accessed field at +0x18 in SetClampFar)
 * Vtable: none found (no vptr write in ctor)
 * Fields from: nuccFogParam::nuccFogParam (0x5ABC00), SetColor (0x5ABC30),
 * SetClampFar (0x5ABC20), SetDistFar (0x5ABC50), SetDistNear (0x5ABC60)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFogParam {
/* 0x00 */ uint32_t color_r;      /* PRES: SetColor writes param_1[0] as uint32 */
/* 0x04 */ uint32_t color_g;      /* PRES: SetColor writes param_1[1] as uint32 */
/* 0x08 */ uint32_t color_b;      /* PRES: SetColor writes param_1[2] as uint32 */
/* 0x0C */ uint32_t pad_0c;       /* UNKNOWN: padding to align 0x10 */
/* 0x10 */ float dist_near;       /* PRES: SetDistNear writes *(param_1+0x10); ctor sets FLT_MAX */
/* 0x14 */ float dist_far;        /* PRES: SetDistFar writes *(param_1+0x14); ctor sets FLT_MAX */
/* 0x18 */ uint32_t clamp_far;    /* PRES: SetClampFar writes *(param_1+0x18) */
} nuccFogParam;

static_assert(offsetof(nuccFogParam, color_r) == 0x00, "nuccFogParam.color_r");
static_assert(offsetof(nuccFogParam, color_g) == 0x04, "nuccFogParam.color_g");
static_assert(offsetof(nuccFogParam, color_b) == 0x08, "nuccFogParam.color_b");
static_assert(offsetof(nuccFogParam, pad_0c) == 0x0C, "nuccFogParam.pad_0c");
static_assert(offsetof(nuccFogParam, dist_near) == 0x10, "nuccFogParam.dist_near");
static_assert(offsetof(nuccFogParam, dist_far) == 0x14, "nuccFogParam.dist_far");
static_assert(offsetof(nuccFogParam, clamp_far) == 0x18, "nuccFogParam.clamp_far");
/* No sizeof assert: size not proven beyond >= 0x1C */

/* =========================================================================
 * nuccFilePathStr
 * Size unknown, >= 0x40 (last accessed field at +0x38 is a pointer; dtor/Clear access param_1+0x38)
 * Vtable: PTR_FUN_140890cc8 (set in dtor 0x58FD40); also PTR_FUN_14089c1b8 (final vtable after dtor)
 * Fields from: Split (0x5A40E0), Clear (0x5A3F30), CopyStr (0x5A4040),
 * dtor (0x58FD40)
 * Layout: vptr + allocator ptr at +0x08, then 5 string pointers at +0x18,+0x20,+0x28,+0x30,+0x38
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFilePathStr {
/* 0x00 */ void *vtable;          /* PRES: PTR_FUN_140890cc8 set in dtor */
/* 0x08 */ void *allocator;       /* PRES: passed as 2nd arg to operator_new__ in CopyStr */
/* 0x10 */ uint8_t pad_10[0x08];  /* UNKNOWN: gap before first string ptr */
/* 0x18 */ char *drive;           /* PRES: Split copies drive prefix (before ':') here */
/* 0x20 */ char *directory;       /* PRES: Split copies path (after '/', before ext) here */
/* 0x28 */ char *filename;        /* PRES: Split copies name (before '.') here */
/* 0x30 */ char *extension;       /* PRES: Split copies extension (from '.') here */
/* 0x38 */ char *merged;          /* PRES: Split result stored here; cleared in Clear/dtor */
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
 * nuccFileLoadList
 * Size unknown, >= 0xE4 (ctor accesses up to +0xE0; Update accesses +0xE0)
 * Vtable: PTR_FUN_14086c878 (set in ctor 0x539AF0)
 * Fields from: nuccFileLoadList::nuccFileLoadList (0x539AF0), GetData (0x59CE20),
 * Update (0x539C10), state_surface analysis
 * Contains std::__tree (map) at +0x18 and additional state fields.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFileLoadList {
/* 0x00 */ void *vtable;              /* PRES: PTR_FUN_14086c878 set in ctor */
/* 0x08 */ uint8_t base_fields[0x10]; /* UNKNOWN: inherited/base class fields (FUN_14059cd40) */
/* 0x18 */ uint8_t tree_map[0x30];    /* PRES: std::__tree for map; GetData reads tree at +0x18 */
/* 0x48 */ void *data_ptr;            /* PRES: Update checks != NULL at +0x48 */
/* 0x50 */ int32_t count;             /* PRES: Update loops while iVar < *(int*)(+0x50) */
/* 0x54 */ int32_t field_54;          /* PRES: ctor sets 0xffffffff; Update compares == 0x26 */
/* 0x58 */ int32_t field_58;          /* PRES: ctor sets 0xffffffff */
/* 0x5C */ int32_t field_5c;          /* PRES: ctor sets 0xffffffff */
/* 0x60 */ uint8_t gap_60[0x28];      /* UNKNOWN: no direct access observed */
/* 0x88 */ int32_t field_88;          /* PRES: Update checks != 1 at +0x88 */
/* 0x8C */ uint32_t pad_8c;           /* UNKNOWN: padding */
/* 0x90 */ void *timer_array;         /* PRES: Update reads ptr at +0x90 */
/* 0x98 */ void *float_array;         /* PRES: Update reads ptr at +0x98 */
/* 0xA0 */ uint8_t index_array[0x14]; /* PRES: Update writes int at +0xA0 + idx*4 (5 entries) */
/* 0xB4 */ uint32_t handle_ids[5];    /* PRES: ctor inits 10 uint32s at +0xB4; Update uses pairs */
/* 0xC8 */ uint32_t handle_vals[5];   /* PRES: ctor inits; Update writes at +0xB8 + idx*8 */
/* 0xDC */ int32_t active_slot;       /* PRES: ctor sets 0; Update writes slot index */
/* 0xE0 */ int32_t field_e0;          /* PRES: ctor sets 0xffffffff; Update checks == 1 */
} nuccFileLoadList;

static_assert(offsetof(nuccFileLoadList, vtable) == 0x00, "nuccFileLoadList.vtable");
static_assert(offsetof(nuccFileLoadList, base_fields) == 0x08, "nuccFileLoadList.base_fields");
static_assert(offsetof(nuccFileLoadList, tree_map) == 0x18, "nuccFileLoadList.tree_map");
static_assert(offsetof(nuccFileLoadList, data_ptr) == 0x48, "nuccFileLoadList.data_ptr");
static_assert(offsetof(nuccFileLoadList, count) == 0x50, "nuccFileLoadList.count");
static_assert(offsetof(nuccFileLoadList, field_54) == 0x54, "nuccFileLoadList.field_54");
static_assert(offsetof(nuccFileLoadList, field_58) == 0x58, "nuccFileLoadList.field_58");
static_assert(offsetof(nuccFileLoadList, field_5c) == 0x5C, "nuccFileLoadList.field_5c");
static_assert(offsetof(nuccFileLoadList, gap_60) == 0x60, "nuccFileLoadList.gap_60");
static_assert(offsetof(nuccFileLoadList, field_88) == 0x88, "nuccFileLoadList.field_88");
static_assert(offsetof(nuccFileLoadList, pad_8c) == 0x8C, "nuccFileLoadList.pad_8c");
static_assert(offsetof(nuccFileLoadList, timer_array) == 0x90, "nuccFileLoadList.timer_array");
static_assert(offsetof(nuccFileLoadList, float_array) == 0x98, "nuccFileLoadList.float_array");
static_assert(offsetof(nuccFileLoadList, index_array) == 0xA0, "nuccFileLoadList.index_array");
static_assert(offsetof(nuccFileLoadList, handle_ids) == 0xB4, "nuccFileLoadList.handle_ids");
static_assert(offsetof(nuccFileLoadList, handle_vals) == 0xC8, "nuccFileLoadList.handle_vals");
static_assert(offsetof(nuccFileLoadList, active_slot) == 0xDC, "nuccFileLoadList.active_slot");
static_assert(offsetof(nuccFileLoadList, field_e0) == 0xE0, "nuccFileLoadList.field_e0");
/* No sizeof assert: size not proven beyond >= 0xE4 */

/* =========================================================================
 * nuccFCurveThermal2
 * Size unknown, >= 0x48 (only 1 method in s2; listed in report as below threshold)
 * No fields reconstructed beyond minimum size anchor.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveThermal2 {
/* 0x00 */ uint8_t unknown[0x48]; /* UNKNOWN: no field-level access in s2 methods */
} nuccFCurveThermal2;

static_assert(offsetof(nuccFCurveThermal2, unknown) == 0x00, "nuccFCurveThermal2.unknown");
/* No sizeof assert: size not proven beyond >= 0x48 */

/* =========================================================================
 * nuccFCurveThermal
 * Size unknown, >= 0x48 (only 1 method in s2; listed in report as below threshold)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveThermal {
/* 0x00 */ uint8_t unknown[0x48]; /* UNKNOWN: no field-level access in s2 methods */
} nuccFCurveThermal;

static_assert(offsetof(nuccFCurveThermal, unknown) == 0x00, "nuccFCurveThermal.unknown");
/* No sizeof assert: size not proven beyond >= 0x48 */

/* =========================================================================
 * nuccFCurveThermalDeform
 * Size unknown, >= 0x30 (only 1 method in s2; listed in report as below threshold)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFCurveThermalDeform {
/* 0x00 */ uint8_t unknown[0x30]; /* UNKNOWN: no field-level access in s2 methods */
} nuccFCurveThermalDeform;

static_assert(offsetof(nuccFCurveThermalDeform, unknown) == 0x00, "nuccFCurveThermalDeform.unknown");
/* No sizeof assert: size not proven beyond >= 0x30 */

#endif /* CMN54_H */