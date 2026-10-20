/*
 * cmn04.h — Storm 2 (s2) struct group cmn04
 * Build: s2 / NSUNS2.exe-abf2b6 / sha 697488011750
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Sizes are proven from ctor/allocator code where possible; otherwise noted.
 * Own-game names only (Storm 2 / ns2::).
 */
#ifndef CMN04_S2_H
#define CMN04_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccLightManager
 * ---------------
 * Vtable: PTR_FUN_140867478 (set in ctor 0x537D80)
 * Embedded sub-objects at +0x98 and +0xC0 initialised via FUN_1405ccf60
 *   (ctor calls with counts 8 and 4 respectively; dtor 0x537EF8 tears down).
 * Six additional sub-objects at +0xF0..+0x140 via FUN_14058ee60.
 * RW fields at +0x150/+0x15C/+0x168 via FUN_140580a40; write-only uint32
 *   at +0x158/+0x164/+0x170.
 * Size: unknown, >= 0x174 (last proven write at +0x170, uint32).
 */
typedef struct __attribute__((packed)) ccLightManager {
    /* 0x000 */ void *vtable;                       /* PTR_FUN_140867478 */
    /* 0x008 */ uint8_t _pad_08[0x90];              /* gap to first sub-object */
    /* 0x098 */ uint8_t sub_light_tbl_a[0x28];      /* 8 elements via FUN_1405ccf60 */
    /* 0x0C0 */ uint8_t sub_light_tbl_b[0x30];      /* 4 elements via FUN_1405ccf60 */
    /* 0x0F0 */ uint8_t sub_light_0f0[0x10];        /* FUN_14058ee60 */
    /* 0x100 */ uint8_t sub_light_100[0x10];        /* FUN_14058ee60 */
    /* 0x110 */ uint8_t sub_light_110[0x10];        /* FUN_14058ee60 */
    /* 0x120 */ uint8_t sub_light_120[0x10];        /* FUN_14058ee60 */
    /* 0x130 */ uint8_t sub_light_130[0x10];        /* FUN_14058ee60 */
    /* 0x140 */ uint8_t sub_light_140[0x10];        /* FUN_14058ee60 */
    /* 0x150 */ uint64_t field_150;                 /* rw via FUN_140580a40 */
    /* 0x158 */ uint32_t field_158;                 /* write-only in ctor */
    /* 0x15C */ uint64_t field_15c;                 /* rw via FUN_140580a40 */
    /* 0x164 */ uint32_t field_164;                 /* write-only in ctor */
    /* 0x168 */ uint64_t field_168;                 /* rw via FUN_140580a40 */
    /* 0x170 */ uint32_t field_170;                 /* write-only in ctor */
} ccLightManager;

static_assert(offsetof(ccLightManager, vtable)          == 0x000, "ccLightManager::vtable");
static_assert(offsetof(ccLightManager, sub_light_tbl_a) == 0x098, "ccLightManager::sub_light_tbl_a");
static_assert(offsetof(ccLightManager, sub_light_tbl_b) == 0x0C0, "ccLightManager::sub_light_tbl_b");
static_assert(offsetof(ccLightManager, sub_light_0f0)   == 0x0F0, "ccLightManager::sub_light_0f0");
static_assert(offsetof(ccLightManager, sub_light_100)   == 0x100, "ccLightManager::sub_light_100");
static_assert(offsetof(ccLightManager, sub_light_110)   == 0x110, "ccLightManager::sub_light_110");
static_assert(offsetof(ccLightManager, sub_light_120)   == 0x120, "ccLightManager::sub_light_120");
static_assert(offsetof(ccLightManager, sub_light_130)   == 0x130, "ccLightManager::sub_light_130");
static_assert(offsetof(ccLightManager, sub_light_140)   == 0x140, "ccLightManager::sub_light_140");
static_assert(offsetof(ccLightManager, field_150)       == 0x150, "ccLightManager::field_150");
static_assert(offsetof(ccLightManager, field_158)       == 0x158, "ccLightManager::field_158");
static_assert(offsetof(ccLightManager, field_15c)       == 0x15C, "ccLightManager::field_15c");
static_assert(offsetof(ccLightManager, field_164)       == 0x164, "ccLightManager::field_164");
static_assert(offsetof(ccLightManager, field_168)       == 0x168, "ccLightManager::field_168");
static_assert(offsetof(ccLightManager, field_170)       == 0x170, "ccLightManager::field_170");


/*
 * ccGameProperty
 * ---------------
 * Vtable: not found in s2 ctors (no dedicated ccGameProperty::ccGameProperty symbol);
 *   likely embedded or constructed inline. S1 had PTR_FUN_140678618.
 * Contains a std::list-like structure at +0x28..+0x30 (Authorize uses it as
 *   a linked list with sentinel check 0xaaaaaaaaaaaaaa9).
 * Deauthorize accesses +0x38 (allocator/mutex passed to FUN_140585990).
 * GetProperty accesses tree root at *param_1 and node internals at +0x20/+0x30/+0x38/+0x58
 *   (std::map node layout, not direct members).
 * Size: unknown, >= 0x3C (last proven access at +0x38 in Deauthorize).
 *   S1 had fields up to +0x1B8 but those were byte-cast offsets from Ghidra's
 *   undefined8* param_1 arithmetic; s2 decompile does not reproduce them.
 */
typedef struct __attribute__((packed)) ccGameProperty {
    /* 0x00 */ void *vtable_or_root;               /* tree root ptr or vtable */
    /* 0x08 */ uint8_t _pad_08[0x20];              /* gap to list head */
    /* 0x28 */ uint64_t list_head;                 /* std::list node ptr (Authorize/Deauthorize) */
    /* 0x30 */ uint64_t list_size_or_sentinel;     /* sentinel == 0xaaaaaaaaaaaaaa9 */
    /* 0x38 */ uint64_t allocator_or_mutex;        /* passed to FUN_140585990 in Deauthorize */
} ccGameProperty;

static_assert(offsetof(ccGameProperty, vtable_or_root)       == 0x00, "ccGameProperty::vtable_or_root");
static_assert(offsetof(ccGameProperty, list_head)            == 0x28, "ccGameProperty::list_head");
static_assert(offsetof(ccGameProperty, list_size_or_sentinel)== 0x30, "ccGameProperty::list_size_or_sentinel");
static_assert(offsetof(ccGameProperty, allocator_or_mutex)   == 0x38, "ccGameProperty::allocator_or_mutex");


/*
 * ccGameObjAttachDraw
 * --------------------
 * Inherits from a base class initialised by FUN_1405a0190 in ctor.
 * Base vtable: PTR_FUN_1407f2df0 (set at param_1+4, i.e. byte offset 0x10).
 * Ctor (0x334930) zeroes fields at +0x08/+0x10/+0x12/+0x0c/+0x0e/+0x02/+0x26/+0x28/+0x2a.
 * Update (0x3386F8) is the primary field accessor (40 accesses).
 * Size: unknown, >= 0xAC (last proven read at +0xA8, pointer).
 */
typedef struct __attribute__((packed)) ccGameObjAttachDraw {
    /* 0x00 */ uint32_t type_tag;                  /* set to 1 in ctor (inferred from s1) */
    /* 0x04 */ uint32_t _pad_04;                   /* alignment */
    /* 0x08 */ uint64_t parent_ptr;               /* *(longlong*)(param_1+8) */
    /* 0x10 */ void *base_vtable;                  /* PTR_FUN_1407f2df0 at param_1+4 */
    /* 0x18 */ uint64_t field_18;                  /* param_1[0x02] area */
    /* 0x20 */ uint32_t field_20;                  /* param_1[2] = 0 in ctor */
    /* 0x24 */ uint32_t _pad_24;
    /* 0x28 */ uint64_t name_buffer;               /* heap-allocated copy of name string */
    /* 0x30 */ uint64_t chunk_coord_ptr;           /* *(longlong*)(param_1+0xc) -> FUN_1405a0190 */
    /* 0x38 */ uint64_t model_handle;              /* param_1+0xe area */
    /* 0x40 */ uint64_t field_40;                  /* *(longlong*)(param_1+0x10) */
    /* 0x48 */ uint64_t sub_draw_obj_ptr;          /* *(longlong**)(param_1+0x12) */
    /* 0x50 */ uint8_t sub_draw_data[0x40];        /* param_1+0x14 area, FUN_140586cd0 */
    /* 0x90 */ uint32_t flag_90;                   /* param_1[0x24] != 0 check in Update */
    /* 0x94 */ uint32_t _pad_94;
    /* 0x98 */ uint32_t flag_98;                   /* param_1[0x26] != 0 check in Update */
    /* 0x9C */ uint32_t _pad_9c;
    /* 0xA0 */ uint32_t field_a0;                  /* param_1[0x28] = 0 in ctor */
    /* 0xA4 */ uint8_t flag_a4;                    /* rw: *(undefined1*)(param_1+0x29) in Update */
    /* 0xA5 */ uint8_t _pad_a5[3];
    /* 0xA8 */ uint64_t field_a8;                  /* *(longlong**)(param_1+0x2a) read in Update */
} ccGameObjAttachDraw;

static_assert(offsetof(ccGameObjAttachDraw, type_tag)         == 0x00, "ccGameObjAttachDraw::type_tag");
static_assert(offsetof(ccGameObjAttachDraw, parent_ptr)       == 0x08, "ccGameObjAttachDraw::parent_ptr");
static_assert(offsetof(ccGameObjAttachDraw, base_vtable)      == 0x10, "ccGameObjAttachDraw::base_vtable");
static_assert(offsetof(ccGameObjAttachDraw, field_18)         == 0x18, "ccGameObjAttachDraw::field_18");
static_assert(offsetof(ccGameObjAttachDraw, field_20)         == 0x20, "ccGameObjAttachDraw::field_20");
static_assert(offsetof(ccGameObjAttachDraw, name_buffer)      == 0x28, "ccGameObjAttachDraw::name_buffer");
static_assert(offsetof(ccGameObjAttachDraw, chunk_coord_ptr)  == 0x30, "ccGameObjAttachDraw::chunk_coord_ptr");
static_assert(offsetof(ccGameObjAttachDraw, model_handle)     == 0x38, "ccGameObjAttachDraw::model_handle");
static_assert(offsetof(ccGameObjAttachDraw, field_40)         == 0x40, "ccGameObjAttachDraw::field_40");
static_assert(offsetof(ccGameObjAttachDraw, sub_draw_obj_ptr) == 0x48, "ccGameObjAttachDraw::sub_draw_obj_ptr");
static_assert(offsetof(ccGameObjAttachDraw, sub_draw_data)    == 0x50, "ccGameObjAttachDraw::sub_draw_data");
static_assert(offsetof(ccGameObjAttachDraw, flag_90)          == 0x90, "ccGameObjAttachDraw::flag_90");
static_assert(offsetof(ccGameObjAttachDraw, flag_98)          == 0x98, "ccGameObjAttachDraw::flag_98");
static_assert(offsetof(ccGameObjAttachDraw, field_a0)         == 0xA0, "ccGameObjAttachDraw::field_a0");
static_assert(offsetof(ccGameObjAttachDraw, flag_a4)          == 0xA4, "ccGameObjAttachDraw::flag_a4");
static_assert(offsetof(ccGameObjAttachDraw, field_a8)         == 0xA8, "ccGameObjAttachDraw::field_a8");


/*
 * ccFlexCnt
 * ----------
 * Plain struct, no vtable. Ctor (0x39AFC0): *param_1=0, param_1[1]=0, param_1[2]=0x100.
 * Set/SetAll/_Ctrl methods exist but state_surface found 0 fields (byte-cast only).
 * Layout inferred from ctor: three uint64_t fields.
 * Size: unknown, >= 0x18 (3 * sizeof(uint64_t)).
 */
typedef struct __attribute__((packed)) ccFlexCnt {
    /* 0x00 */ uint64_t field_00;                  /* *param_1 = 0 in ctor */
    /* 0x08 */ uint64_t field_08;                  /* param_1[1] = 0 in ctor */
    /* 0x10 */ uint64_t capacity;                  /* param_1[2] = 0x100 in ctor */
} ccFlexCnt;

static_assert(offsetof(ccFlexCnt, field_00) == 0x00, "ccFlexCnt::field_00");
static_assert(offsetof(ccFlexCnt, field_08) == 0x08, "ccFlexCnt::field_08");
static_assert(offsetof(ccFlexCnt, capacity) == 0x10, "ccFlexCnt::capacity");


/*
 * ccGamePropertyPermit
 * ---------------------
 * Plain struct, no vtable. Ctor (0x685900): *param_1=0, *(param_1+2)=0.
 * Dtor (0x47728C) accesses param_1+0x178 (int check != 0).
 * Size: unknown, >= 0x17C (last proven access at +0x178, int).
 */
typedef struct __attribute__((packed)) ccGamePropertyPermit {
    /* 0x000 */ uint64_t field_00;                 /* *param_1 = 0 in ctor */
    /* 0x008 */ uint64_t _pad_08;                  /* alignment */
    /* 0x010 */ uint64_t field_10;                 /* *(param_1+2) = 0 in ctor */
    /* 0x018 */ uint8_t _pad_18[0x160];            /* gap to dtor-accessed field */
    /* 0x178 */ int32_t field_178;                 /* checked != 0 in dtor */
    /* 0x17C */ uint32_t _pad_17c;                 /* padding to proven boundary */
} ccGamePropertyPermit;

static_assert(offsetof(ccGamePropertyPermit, field_00)  == 0x000, "ccGamePropertyPermit::field_00");
static_assert(offsetof(ccGamePropertyPermit, field_10)  == 0x010, "ccGamePropertyPermit::field_10");
static_assert(offsetof(ccGamePropertyPermit, field_178) == 0x178, "ccGamePropertyPermit::field_178");

#endif /* CMN04_S2_H */