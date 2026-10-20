/* cmn56.h - Common engine/UI/render struct layouts for NSUNS1.exe (s1)
 * INFERRED from static analysis only. Not CONFIRMED at runtime.
 * Build: s1 / NSUNS1.exe-a9fe00 / sha 10231093af9c
 * All offsets derived from PC x64 decompile (image base 0x140000000).
 * Sizes are unproven unless noted; no sizeof asserts for unproven sizes.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccLayerBase
 * Base class for layer hierarchy. Vtable at PTR_FUN_14073f3d8.
 * Size unknown, >= 0x28 (last proven field +0x24 is uint32).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccLayerBase {
    /* 0x00 */ void *vtable;                          /* PTR_FUN_14073f3d8, set in ctor */
    /* 0x08 */ char name[16];                         /* inline string copy loop in ctor, max ~16 bytes */
    /* 0x18 */ uint32_t type_id;                      /* param_3 written to *(param_1+3) = offset 0x18 */
    /* 0x1C */ uint16_t field_1C;                     /* zeroed in ctor */
    /* 0x1E */ uint8_t field_1E;                      /* zeroed in ctor */
    /* 0x1F */ uint8_t _pad_1F[5];                    /* explicit padding to 0x24 */
    /* 0x24 */ uint32_t field_24;                     /* set to 1 in ctor */
} nuccLayerBase;

static_assert(offsetof(nuccLayerBase, vtable) == 0x00, "nuccLayerBase.vtable");
static_assert(offsetof(nuccLayerBase, name) == 0x08, "nuccLayerBase.name");
static_assert(offsetof(nuccLayerBase, type_id) == 0x18, "nuccLayerBase.type_id");
static_assert(offsetof(nuccLayerBase, field_1C) == 0x1C, "nuccLayerBase.field_1C");
static_assert(offsetof(nuccLayerBase, field_1E) == 0x1E, "nuccLayerBase.field_1E");
static_assert(offsetof(nuccLayerBase, field_24) == 0x24, "nuccLayerBase.field_24");

/* =========================================================================
 * nuccLayer
 * Inherits nuccLayerBase. Vtable at PTR_FUN_140737470.
 * Size unknown, >= 0x50 (last proven field param_1[9] = offset 0x48 is ptr).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccLayer {
    /* --- nuccLayerBase subobject --- */
    /* 0x00 */ void *vtable;                          /* PTR_FUN_140737470, overrides base */
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t type_id;                      /* passed as 2 to base ctor */
    /* 0x1C */ uint16_t field_1C;
    /* 0x1E */ uint8_t field_1E;
    /* 0x1F */ uint8_t _pad_1F[5];
    /* 0x24 */ uint32_t field_24;
    /* --- nuccLayer fields --- */
    /* 0x28 */ void *field_28;                        /* param_1[5] = param_3 in ctor */
    /* 0x30 */ uint32_t field_30;                     /* param_1[6], written as undefined4 in ctor */
    /* 0x34 */ int32_t field_34;                      /* read in ctor conditional */
    /* 0x38 */ uint64_t field_38;                     /* param_1[7], zeroed */
    /* 0x40 */ void *field_40;                        /* param_1+8 = puVar1, self-ptr pattern */
    /* 0x48 */ void *field_48;                        /* param_1[9] = puVar1 */
} nuccLayer;

static_assert(offsetof(nuccLayer, vtable) == 0x00, "nuccLayer.vtable");
static_assert(offsetof(nuccLayer, name) == 0x08, "nuccLayer.name");
static_assert(offsetof(nuccLayer, type_id) == 0x18, "nuccLayer.type_id");
static_assert(offsetof(nuccLayer, field_1C) == 0x1C, "nuccLayer.field_1C");
static_assert(offsetof(nuccLayer, field_1E) == 0x1E, "nuccLayer.field_1E");
static_assert(offsetof(nuccLayer, field_24) == 0x24, "nuccLayer.field_24");
static_assert(offsetof(nuccLayer, field_28) == 0x28, "nuccLayer.field_28");
static_assert(offsetof(nuccLayer, field_30) == 0x30, "nuccLayer.field_30");
static_assert(offsetof(nuccLayer, field_34) == 0x34, "nuccLayer.field_34");
static_assert(offsetof(nuccLayer, field_38) == 0x38, "nuccLayer.field_38");
static_assert(offsetof(nuccLayer, field_40) == 0x40, "nuccLayer.field_40");
static_assert(offsetof(nuccLayer, field_48) == 0x48, "nuccLayer.field_48");

/* =========================================================================
 * nuccLayerList
 * Inherits nuccLayerBase. Vtable at PTR_FUN_140737088.
 * Size unknown, >= 0x28 (FUN_140488b30 called on param_1+5 = offset 0x28).
 * state_surface found vtable dispatch at +0xC0 and +0x100 but these are
 * likely embedded subobjects or array indices, not direct fields.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccLayerList {
    /* --- nuccLayerBase subobject --- */
    /* 0x00 */ void *vtable;                          /* PTR_FUN_140737088, overrides base */
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t type_id;                      /* passed as 3 to base ctor */
    /* 0x1C */ uint16_t field_1C;
    /* 0x1E */ uint8_t field_1E;
    /* 0x1F */ uint8_t _pad_1F[5];
    /* 0x24 */ uint32_t field_24;
    /* --- nuccLayerList fields --- */
    /* 0x28 */ uint8_t sub_object_at_28[1];           /* FUN_140488b30(param_1+5); size unknown */
} nuccLayerList;

static_assert(offsetof(nuccLayerList, vtable) == 0x00, "nuccLayerList.vtable");
static_assert(offsetof(nuccLayerList, name) == 0x08, "nuccLayerList.name");
static_assert(offsetof(nuccLayerList, type_id) == 0x18, "nuccLayerList.type_id");
static_assert(offsetof(nuccLayerList, field_1C) == 0x1C, "nuccLayerList.field_1C");
static_assert(offsetof(nuccLayerList, field_1E) == 0x1E, "nuccLayerList.field_1E");
static_assert(offsetof(nuccLayerList, field_24) == 0x24, "nuccLayerList.field_24");
static_assert(offsetof(nuccLayerList, sub_object_at_28) == 0x28, "nuccLayerList.sub_object_at_28");

/* =========================================================================
 * nuccInstanceList
 * No vtable observed in ctor (calls FUN_14048f6a0 first, likely base init).
 * Size unknown, >= 0x98 (state_surface found rw field at +0x90).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccInstanceList {
    /* 0x00 */ uint8_t _unknown_00[0x28];            /* before first proven field */
    /* 0x28 */ uint64_t field_28;                     /* zeroed in ctor */
    /* 0x30 */ uint64_t field_30;                     /* zeroed in ctor */
    /* 0x38 */ uint64_t field_38;                     /* zeroed in ctor */
    /* 0x40 */ uint64_t field_40;                     /* zeroed in ctor */
    /* 0x48 */ uint8_t _unknown_48[0x48];            /* gap to +0x90 */
    /* 0x90 */ void *field_90;                        /* rw in DeleteInstanceAll */
} nuccInstanceList;

static_assert(offsetof(nuccInstanceList, field_28) == 0x28, "nuccInstanceList.field_28");
static_assert(offsetof(nuccInstanceList, field_30) == 0x30, "nuccInstanceList.field_30");
static_assert(offsetof(nuccInstanceList, field_38) == 0x38, "nuccInstanceList.field_38");
static_assert(offsetof(nuccInstanceList, field_40) == 0x40, "nuccInstanceList.field_40");
static_assert(offsetof(nuccInstanceList, field_90) == 0x90, "nuccInstanceList.field_90");

/* =========================================================================
 * nuccLayerDrawCmdExecuter
 * Contains embedded nuccCriticalSection (+0x10), NUMM_THREAD_SYNCPOINT_CONTEXT (+0x60),
 * thread array pointer (*param_1), thread count (param_1[1]).
 * Size unknown, >= 0x68 (embedded syncpoint at +0x60).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccLayerDrawCmdExecuter {
    /* 0x00 */ void *thread_array;                    /* *param_1, freed in dtor */
    /* 0x08 */ uint8_t thread_count;                  /* param_1[1], byte-sized loop bound */
    /* 0x09 */ uint8_t _pad_09[7];                    /* padding to 0x10 */
    /* 0x10 */ uint8_t critical_section[0x50];        /* nuccCriticalSection at param_1+2 = +0x10 */
    /* 0x60 */ uint8_t syncpoint_context[8];          /* NUMM_THREAD_SYNCPOINT_CONTEXT at param_1+0xc = +0x60 */
} nuccLayerDrawCmdExecuter;

static_assert(offsetof(nuccLayerDrawCmdExecuter, thread_array) == 0x00, "nuccLayerDrawCmdExecuter.thread_array");
static_assert(offsetof(nuccLayerDrawCmdExecuter, thread_count) == 0x08, "nuccLayerDrawCmdExecuter.thread_count");
static_assert(offsetof(nuccLayerDrawCmdExecuter, critical_section) == 0x10, "nuccLayerDrawCmdExecuter.critical_section");
static_assert(offsetof(nuccLayerDrawCmdExecuter, syncpoint_context) == 0x60, "nuccLayerDrawCmdExecuter.syncpoint_context");

/* =========================================================================
 * nuccFrameBufferSampling
 * Singleton pattern: CreateInstance/DeleteInstance/GetInstance.
 * No instance fields accessed via param_1 in any method.
 * Likely all-static or opaque handle. No struct layout reconstructed.
 * ========================================================================= */

/* =========================================================================
 * Classes with < 3 methods (listed in report, not reconstructed):
 *   nuccGameDataManager_Android (1 method: GetDriveName)
 *   nuccGameDataMounter_NX (2 methods: Mount, ~dtor)
 *   nuccInitParam (1 method: ctor)
 *   nuccInitParamCmnNumm (1 method: ctor)
 *   nuccJudgeCallApplet (1 method: AppletExit)
 *   nuccLayerAfterImage (1 method: Draw)
 * ========================================================================= */