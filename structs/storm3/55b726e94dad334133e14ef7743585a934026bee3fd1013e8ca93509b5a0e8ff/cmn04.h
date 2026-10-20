/*
 * cmn04.h — Storm 3 Full Burst (s3) struct group cmn04
 * Build: s3 / NSUNS3.exe-a7124b / sha 55b726e94dad
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Sizes are proven from ctor/allocator code where possible; otherwise noted.
 * Own-game names only (Storm 3 / ns3::).
 */
#ifndef CMN04_S3_H
#define CMN04_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccLightManager
 * ---------------
 * Vtable: PTR_FUN_1409d5520 (set in ctor 0x6451DC)
 * Embedded sub-objects at +0x98 and +0xC0 initialised via FUN_1406d3010
 *   (ctor calls with counts 8 and 4 respectively).
 * Six additional sub-objects at +0xF0..+0x140 via FUN_1406a4700.
 * RW fields at +0x150/+0x15C/+0x168 via FUN_1406a2bb0; write-only uint32
 *   at +0x158/+0x164/+0x170.
 * Size: unknown, >= 0x174 (last proven write at +0x170, uint32).
 */
typedef struct __attribute__((packed)) ccLightManager {
    /* 0x000 */ void *vtable;                       /* PTR_FUN_1409d5520 */
    /* 0x008 */ uint8_t _pad_08[0x90];              /* gap to first sub-object */
    /* 0x098 */ uint8_t sub_light_tbl_a[0x28];      /* 8 elements via FUN_1406d3010 */
    /* 0x0C0 */ uint8_t sub_light_tbl_b[0x30];      /* 4 elements via FUN_1406d3010 */
    /* 0x0F0 */ uint8_t sub_light_0f0[0x10];        /* FUN_1406a4700 */
    /* 0x100 */ uint8_t sub_light_100[0x10];        /* FUN_1406a4700 */
    /* 0x110 */ uint8_t sub_light_110[0x10];        /* FUN_1406a4700 */
    /* 0x120 */ uint8_t sub_light_120[0x10];        /* FUN_1406a4700 */
    /* 0x130 */ uint8_t sub_light_130[0x10];        /* FUN_1406a4700 */
    /* 0x140 */ uint8_t sub_light_140[0x10];        /* FUN_1406a4700 */
    /* 0x150 */ uint64_t field_150;                 /* rw via FUN_1406a2bb0 */
    /* 0x158 */ uint32_t field_158;                 /* write-only in ctor */
    /* 0x15C */ uint64_t field_15c;                 /* rw via FUN_1406a2bb0 */
    /* 0x164 */ uint32_t field_164;                 /* write-only in ctor */
    /* 0x168 */ uint64_t field_168;                 /* rw via FUN_1406a2bb0 */
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
 * Vtable: not found in s3 ctors (no dedicated ccGameProperty::ccGameProperty symbol);
 *   likely embedded or constructed inline.
 * state_surface returned 0 fields (byte-cast only access pattern).
 * Layout carried from s2 with offsets re-verified against s3 Authorize/Deauthorize.
 * Size: unknown, >= 0x3C (last proven access at +0x38 in Deauthorize).
 */
typedef struct __attribute__((packed)) ccGameProperty {
    /* 0x00 */ void *vtable_or_root;               /* tree root ptr or vtable */
    /* 0x08 */ uint8_t _pad_08[0x20];              /* gap to list head */
    /* 0x28 */ uint64_t list_head;                 /* std::list node ptr (Authorize/Deauthorize) */
    /* 0x30 */ uint64_t list_size_or_sentinel;     /* sentinel value */
    /* 0x38 */ uint64_t allocator_or_mutex;        /* passed to cleanup fn in Deauthorize */
} ccGameProperty;

static_assert(offsetof(ccGameProperty, vtable_or_root)       == 0x00, "ccGameProperty::vtable_or_root");
static_assert(offsetof(ccGameProperty, list_head)            == 0x28, "ccGameProperty::list_head");
static_assert(offsetof(ccGameProperty, list_size_or_sentinel)== 0x30, "ccGameProperty::list_size_or_sentinel");
static_assert(offsetof(ccGameProperty, allocator_or_mutex)   == 0x38, "ccGameProperty::allocator_or_mutex");


/*
 * ccGameObjAttachDraw
 * --------------------
 * Ctor param is undefined4*; indices are 4-byte units.
 * Base class initialised by FUN_140684c10 at param_1+4 (byte 0x10).
 * Vtable: PTR_FUN_140989f08 (set at *(param_1+4), byte offset 0x10).
 * Ctor (0x4F767C) zeroes many fields; Update (0x4FC8CC) is primary accessor.
 * Size: unknown, >= 0xB0 (last proven access at +0xAC, float read).
 */
typedef struct __attribute__((packed)) ccGameObjAttachDraw {
    /* 0x00 */ uint32_t type_tag;                  /* set to 1 in ctor */
    /* 0x04 */ uint32_t _pad_04;                   /* alignment */
    /* 0x08 */ uint64_t parent_ptr;               /* embedded base sub-object area */
    /* 0x10 */ void *base_vtable;                  /* PTR_FUN_140989f08 */
    /* 0x18 */ uint64_t field_18;                  /* zeroed in ctor */
    /* 0x20 */ uint32_t field_20;                  /* zeroed in ctor */
    /* 0x24 */ uint32_t _pad_24;
    /* 0x28 */ uint64_t name_buffer;               /* heap-allocated name string copy */
    /* 0x30 */ uint64_t chunk_coord_ptr;           /* ptr at param_1+0xc */
    /* 0x38 */ uint64_t model_handle;              /* param_1+0xe area */
    /* 0x40 */ uint64_t field_40;                  /* *(longlong*)(param_1+0x10) */
    /* 0x48 */ uint64_t sub_draw_obj_ptr;          /* *(longlong**)(param_1+0x12) */
    /* 0x50 */ uint8_t sub_draw_data[0x40];        /* param_1+0x14 area, FUN_1406856b0 */
    /* 0x90 */ uint32_t flag_90;                   /* param_1[0x24] != 0 check in Update */
    /* 0x94 */ uint32_t _pad_94;
    /* 0x98 */ uint32_t flag_98;                   /* param_1[0x26] != 0 check in Update */
    /* 0x9C */ uint32_t _pad_9c;
    /* 0xA0 */ uint32_t field_a0;                  /* param_1[0x28] = 0 in ctor */
    /* 0xA4 */ uint8_t flag_a4;                    /* rw: param_1[0x29] in Update */
    /* 0xA5 */ uint8_t _pad_a5[3];
    /* 0xA8 */ uint64_t field_a8;                  /* *(longlong**)(param_1+0x2c) read in Update */
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
 * Plain struct, no vtable. Ctor (0x5016C4): *param_1=0, param_1[1]=0,
 *   param_1[2]=0x43800000 (float 256.0 as uint64 bits).
 * state_surface returned 0 fields (byte-cast only).
 * Layout inferred from ctor: three uint64_t fields.
 * Size: unknown, >= 0x18 (3 * sizeof(uint64_t)).
 */
typedef struct __attribute__((packed)) ccFlexCnt {
    /* 0x00 */ uint64_t field_00;                  /* *param_1 = 0 in ctor */
    /* 0x08 */ uint64_t field_08;                  /* param_1[1] = 0 in ctor */
    /* 0x10 */ uint64_t capacity;                  /* param_1[2] = 0x43800000 in ctor */
} ccFlexCnt;

static_assert(offsetof(ccFlexCnt, field_00) == 0x00, "ccFlexCnt::field_00");
static_assert(offsetof(ccFlexCnt, field_08) == 0x08, "ccFlexCnt::field_08");
static_assert(offsetof(ccFlexCnt, capacity) == 0x10, "ccFlexCnt::capacity");


/*
 * ccGamePropertyPermit
 * ---------------------
 * Plain struct, no vtable. Ctor (0x7A01C0): *param_1=0, *(uint64*)(param_1+2)=0.
 * state_surface returned 0 fields (byte-cast only).
 * Dtor accesses param_1+0x178 (int check != 0) — same as s2.
 * Size: unknown, >= 0x17C (last proven access at +0x178, int).
 */
typedef struct __attribute__((packed)) ccGamePropertyPermit {
    /* 0x000 */ uint64_t field_00;                 /* *param_1 = 0 in ctor */
    /* 0x008 */ uint64_t _pad_08;                  /* alignment */
    /* 0x010 */ uint64_t field_10;                 /* *(uint64*)(param_1+2) = 0 in ctor */
    /* 0x018 */ uint8_t _pad_18[0x160];            /* gap to dtor-accessed field */
    /* 0x178 */ int32_t field_178;                 /* checked != 0 in dtor */
    /* 0x17C */ uint32_t _pad_17c;                 /* padding to proven boundary */
} ccGamePropertyPermit;

static_assert(offsetof(ccGamePropertyPermit, field_00)  == 0x000, "ccGamePropertyPermit::field_00");
static_assert(offsetof(ccGamePropertyPermit, field_10)  == 0x010, "ccGamePropertyPermit::field_10");
static_assert(offsetof(ccGamePropertyPermit, field_178) == 0x178, "ccGamePropertyPermit::field_178");


/*
 * ccFwInitParam
 * --------------
 * Vtable: PTR_FUN_140938c68 (set in ctor 0x385510).
 * Ctor (undefined8* param): param_1[1]=0, *(uint32*)(param_1+2)=0xffffffff,
 *   *param_1 = &PTR_FUN_140938c68, FUN(param_1+3), param_1[0x14]=0.
 * state_surface found 1 field at +0xA0 (write-only).
 * Size: unknown, >= 0xA8 (last proven write at +0xA0, uint64).
 */
typedef struct __attribute__((packed)) ccFwInitParam {
    /* 0x00 */ void *vtable;                       /* PTR_FUN_140938c68 */
    /* 0x08 */ uint64_t field_08;                  /* param_1[1] = 0 */
    /* 0x10 */ uint32_t field_10;                  /* 0xffffffff */
    /* 0x14 */ uint32_t _pad_14;
    /* 0x18 */ uint8_t sub_param[0x88];            /* FUN_1405b38e0 init area */
    /* 0xA0 */ uint64_t field_a0;                  /* param_1[0x14] = 0 */
} ccFwInitParam;

static_assert(offsetof(ccFwInitParam, vtable)  == 0x00, "ccFwInitParam::vtable");
static_assert(offsetof(ccFwInitParam, field_08)== 0x08, "ccFwInitParam::field_08");
static_assert(offsetof(ccFwInitParam, field_10)== 0x10, "ccFwInitParam::field_10");
static_assert(offsetof(ccFwInitParam, sub_param)==0x18, "ccFwInitParam::sub_param");
static_assert(offsetof(ccFwInitParam, field_a0)== 0xA0, "ccFwInitParam::field_a0");

/*
 * ccFramework::Internal::ccNetServiceManager_NX
 * ----------------------------------------------
 * No vtable found. No ctor symbol in s3.
 * Three methods recovered:
 *   Instance        (0x7A61D0) — reads *(uint64*)(param_1 + 0x18)
 *   DispatchPiaProtocolReception (0x637380) — writes uint32 at
 *       param_1 + 0x890 + idx*0x30, idx < 2
 *   Instance        (0x636D28) — writes uint32 at
 *       param_1 + 0x830 + idx*0x30, idx < 2
 * Size: unknown, >= 0x8C0 (last proven write at +0x8B0, uint32,
 *   DispatchPiaProtocolReception idx=1 → 0x890+0x30=0x8C0 boundary).
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 */
#pragma pack(push,1)
typedef struct ccFramework_Internal_ccNetServiceManager_NX {
    /* 0x000 */ uint8_t _pad_00[0x18];              /* gap to first proven field */
    /* 0x018 */ uint64_t field_18;                  /* read in Instance 0x7A61D0 */
    /* 0x020 */ uint8_t _pad_20[0x810];             /* gap to dispatch table A */
    /* 0x830 */ uint8_t dispatch_tbl_a[0x60];       /* 2 x 0x30, written in 0x636D28 */
    /* 0x890 */ uint8_t dispatch_tbl_b[0x60];       /* 2 x 0x30, written in 0x637380 */
} ccFramework_Internal_ccNetServiceManager_NX;
#pragma pack(pop)

static_assert(offsetof(ccFramework_Internal_ccNetServiceManager_NX, _pad_00)         == 0x000, "ccNetServiceManager_NX::_pad_00");
static_assert(offsetof(ccFramework_Internal_ccNetServiceManager_NX, _pad_20)         == 0x020, "ccNetServiceManager_NX::_pad_20");
static_assert(offsetof(ccFramework_Internal_ccNetServiceManager_NX, field_18)        == 0x018, "ccNetServiceManager_NX::field_18");
static_assert(offsetof(ccFramework_Internal_ccNetServiceManager_NX, dispatch_tbl_a)  == 0x830, "ccNetServiceManager_NX::dispatch_tbl_a");
static_assert(offsetof(ccFramework_Internal_ccNetServiceManager_NX, dispatch_tbl_b)  == 0x890, "ccNetServiceManager_NX::dispatch_tbl_b");

#endif /* CMN04_S3_H */