/*
 * cmn04.h — Storm 1 (s1) struct group cmn04
 * Build: s1 / NSUNS1.exe-a9fe00 / sha 10231093af9c
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Sizes are proven from ctor/allocator code where possible; otherwise noted.
 * Own-game names only (Storm 1 / ns1:: / Switch Trilogy).
 */
#ifndef CMN04_S1_H
#define CMN04_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccLightManager
 * ---------------
 * Vtable: PTR_FUN_1406c6750 (set in ctor 0x2EA21C and dtor 0x2EA260)
 * Embedded sub-objects at +0x98 and +0xC0 initialised via FUN_1404cd410
 *   (ctor calls with counts 8 and 2 respectively; dtor tears down via
 *    thunk_FUN_14049f820 in reverse order).
 * Size: unknown, >= 0xD0 (last proven access is the sub-object at +0xC0,
 *   whose internal size is not determined here).
 * Fields at +0x98/+0xC0 are embedded opaque sub-structures; their internals
 * are not surfaced by any cmn04 method.
 */
typedef struct __attribute__((packed)) ccLightManager {
    /* 0x00 */ void *vtable;                       /* PTR_FUN_1406c6750 */
    /* 0x08 */ uint8_t _pad_08[0x90];              /* gap to first sub-object */
    /* 0x98 */ uint8_t sub_light_tbl_a[0x28];      /* 8 elements, element size unknown */
    /* 0xC0 */ uint8_t sub_light_tbl_b[0x10];      /* 2 elements, element size unknown */
} ccLightManager;

static_assert(offsetof(ccLightManager, vtable)          == 0x00, "ccLightManager::vtable");
static_assert(offsetof(ccLightManager, sub_light_tbl_a) == 0x98, "ccLightManager::sub_light_tbl_a");
static_assert(offsetof(ccLightManager, sub_light_tbl_b) == 0xC0, "ccLightManager::sub_light_tbl_b");


/*
 * ccGameProperty
 * ---------------
 * Vtable: PTR_FUN_140678618 (set in ctor-like init at 0x22A000)
 * Contains a std::list-like structure at +0x28..+0x30 (Authorize uses it as
 *   a linked list with sentinel check 0xaaaaaaaaaaaaaa9).
 * Ctor initialises fields at +0x31, +0x35, +0x36, +0x37 (byte offsets within
 *   the undefined8*-typed param_1 pointer arithmetic used by Ghidra).
 * Size: unknown, >= 0x1B8 (last proven write at byte offset 0x1B8 = param_1[0x37]).
 */
typedef struct __attribute__((packed)) ccGameProperty {
    /* 0x00 */ void *vtable;                       /* PTR_FUN_140678618 */
    /* 0x08 */ uint8_t _pad_08[0x20];              /* gap to list head */
    /* 0x28 */ uint64_t list_head;                 /* std::list node ptr (Authorize reads/writes) */
    /* 0x30 */ uint64_t list_size_or_sentinel;     /* Authorize checks == 0xaaaaaaaaaaaaaa9 */
    /* 0x38 */ uint8_t _pad_38[0x170];             /* gap to ctor-init region */
    /* 0x1A8 */ uint32_t field_1a8;                /* *(uint32*)(param_1+0x35)=0xffffffff in ctor */
    /* 0x1AC */ uint32_t field_1ac;                /* *(uint32*)(param_1+0x35) second write */
    /* 0x1B0 */ uint64_t field_1b0;                /* param_1[0x36]=0 in ctor */
    /* 0x1B8 */ uint64_t field_1b8;                /* param_1[0x37]=0 in ctor */
} ccGameProperty;

static_assert(offsetof(ccGameProperty, vtable)             == 0x00,  "ccGameProperty::vtable");
static_assert(offsetof(ccGameProperty, list_head)          == 0x28,  "ccGameProperty::list_head");
static_assert(offsetof(ccGameProperty, list_size_or_sentinel) == 0x30, "ccGameProperty::list_size_or_sentinel");
static_assert(offsetof(ccGameProperty, field_1a8)          == 0x1A8, "ccGameProperty::field_1a8");
static_assert(offsetof(ccGameProperty, field_1ac)          == 0x1AC, "ccGameProperty::field_1ac");
static_assert(offsetof(ccGameProperty, field_1b0)          == 0x1B0, "ccGameProperty::field_1b0");
static_assert(offsetof(ccGameProperty, field_1b8)          == 0x1B8, "ccGameProperty::field_1b8");


/*
 * ccGameObjAttachDraw
 * --------------------
 * Inherits from a base class initialised by FUN_14047f230(param_1+4) in ctor.
 * Vtable of base: PTR_FUN_14068a1d0 (set at param_1+4, i.e. byte offset 0x10).
 * Own vtable/base pointer at +0x00 set to 1 in ctor (likely a type tag or refcount).
 * Create (0x2826BC) accesses up to +0x90 (writes uint32 1 there).
 * Size: unknown, >= 0x94 (last proven write at +0x90, uint32).
 * Sub-object at +0x48 initialised via FUN_140480da0; further ops via FUN_140480ba0.
 * Field at +0x28 holds a heap-allocated name buffer (strdup-like in Create).
 */
typedef struct __attribute__((packed)) ccGameObjAttachDraw {
    /* 0x00 */ uint32_t type_tag;                  /* set to 1 in ctor */
    /* 0x04 */ uint32_t _pad_04;                   /* alignment */
    /* 0x08 */ uint64_t parent_ptr;               /* set in Create: *(longlong*)(param_1+8)=param_3 */
    /* 0x10 */ void *base_vtable;                  /* PTR_FUN_14068a1d0, set at param_1+4 (byte 0x10) */
    /* 0x18 */ uint64_t allocator_handle;          /* param_1[0x8c] area, used by Create for alloc */
    /* 0x20 */ uint32_t field_20;                  /* param_1[2]=0 in ctor (byte 0x08? recheck) */
    /* 0x24 */ uint32_t _pad_24;
    /* 0x28 */ uint64_t name_buffer;               /* heap-allocated copy of name string */
    /* 0x30 */ uint64_t chunk_coord_ptr;           /* *(longlong*)(param_1+0x30) = nuccChunkCoord lookup */
    /* 0x38 */ uint64_t model_handle;              /* (**(code**)param_2)(param_2,0) result */
    /* 0x40 */ uint64_t field_40;                  /* param_1[0x10]=0 in ctor */
    /* 0x48 */ uint8_t sub_draw_obj[0x40];         /* FUN_140480da0/FUN_140480ba0 managed sub-object */
    /* 0x88 */ uint32_t flag_88;                   /* param_1[0x22], checked !=0 in Update */
    /* 0x8C */ uint32_t flag_8c;                   /* param_1[0x23]=1 in ctor */
    /* 0x90 */ uint32_t active_flag;               /* param_1[0x24], checked !=0 in Update; Create sets =1 */
    /* 0x94 */ uint32_t _pad_94;                   /* padding to proven boundary */
} ccGameObjAttachDraw;

static_assert(offsetof(ccGameObjAttachDraw, type_tag)         == 0x00, "ccGameObjAttachDraw::type_tag");
static_assert(offsetof(ccGameObjAttachDraw, parent_ptr)       == 0x08, "ccGameObjAttachDraw::parent_ptr");
static_assert(offsetof(ccGameObjAttachDraw, base_vtable)      == 0x10, "ccGameObjAttachDraw::base_vtable");
static_assert(offsetof(ccGameObjAttachDraw, allocator_handle) == 0x18, "ccGameObjAttachDraw::allocator_handle");
static_assert(offsetof(ccGameObjAttachDraw, name_buffer)      == 0x28, "ccGameObjAttachDraw::name_buffer");
static_assert(offsetof(ccGameObjAttachDraw, chunk_coord_ptr)  == 0x30, "ccGameObjAttachDraw::chunk_coord_ptr");
static_assert(offsetof(ccGameObjAttachDraw, model_handle)     == 0x38, "ccGameObjAttachDraw::model_handle");
static_assert(offsetof(ccGameObjAttachDraw, field_40)         == 0x40, "ccGameObjAttachDraw::field_40");
static_assert(offsetof(ccGameObjAttachDraw, sub_draw_obj)     == 0x48, "ccGameObjAttachDraw::sub_draw_obj");
static_assert(offsetof(ccGameObjAttachDraw, flag_88)          == 0x88, "ccGameObjAttachDraw::flag_88");
static_assert(offsetof(ccGameObjAttachDraw, flag_8c)          == 0x8C, "ccGameObjAttachDraw::flag_8c");
static_assert(offsetof(ccGameObjAttachDraw, active_flag)      == 0x90, "ccGameObjAttachDraw::active_flag");

/*
 * ccGamePropertyPermit
 * --------------------
 * Vtable: none observed (no vtable assignment in ctor or any method).
 * Ctor (0x553B00): *param_1 = 0; *(undefined8*)(param_1+2) = 0 → fields at
 *   byte offset 0x00 (uint32) and 0x08 (uint64).
 * Deauthorized (0x553B50): identical writes to 0x00 and 0x08.
 * Deleting dtor (0x194830): reads *(int*)(param_1+8) != 0 before calling
 *   ccDiagramManager::Ctrl — confirms field at 0x08 is also read as int32.
 * Non-deleting dtor (0x553B20): empty body (return only).
 * Size: >= 0x10 (last proven access: uint64 write at byte offset 0x08).
 * Layout INFERRED from static decompilation; not CONFIRMED at runtime.
 */
typedef struct __attribute__((packed)) ccGamePropertyPermit {
    /* 0x00 */ uint32_t field_00;                  /* zeroed by ctor and Deauthorized */
    /* 0x04 */ uint32_t _pad_04;                   /* alignment gap to 0x08 */
    /* 0x08 */ uint64_t field_08;                  /* zeroed by ctor/Deauthorized; dtor reads as int32 */
} ccGamePropertyPermit;

static_assert(offsetof(ccGamePropertyPermit, field_00) == 0x00, "ccGamePropertyPermit::field_00");
static_assert(offsetof(ccGamePropertyPermit, _pad_04)  == 0x04, "ccGamePropertyPermit::_pad_04");
static_assert(offsetof(ccGamePropertyPermit, field_08) == 0x08, "ccGamePropertyPermit::field_08");

#endif /* CMN04_S1_H */
