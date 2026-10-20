/*
 * cmn04.h — Storm 4 (s4) struct group cmn04
 * Build: s4 / NSUNS4_release.exe-75912b / sha 75912b
 * All layouts INFERRED from static decompilation; not CONFIRMED at runtime.
 * Sizes are proven from ctor/allocator code where possible; otherwise noted.
 * Own-game names only (Storm 4 symbols/strings).
 */
#ifndef CMN04_S4_H
#define CMN04_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccFlexCnt
 * ----------
 * Plain struct, no vtable. Ctor (0x76B22C): *param_1=0, param_1[1]=0,
 * param_1[2]=0x100 (uint64 indices on undefined8*).
 * state_surface returned 0 fields (byte-cast only).
 * Layout inferred from ctor: three uint64_t fields.
 * Size: unknown, >= 0x18 (3 * sizeof(uint64_t)).
 */
typedef struct __attribute__((packed)) ccFlexCnt {
    /* 0x00 */ uint64_t field_00;   /* *param_1 = 0 in ctor */
    /* 0x08 */ uint64_t field_08;   /* param_1[1] = 0 in ctor */
    /* 0x10 */ uint64_t capacity;   /* param_1[2] = 0x100 in ctor */
} ccFlexCnt;

static_assert(offsetof(ccFlexCnt, field_00) == 0x00, "ccFlexCnt::field_00");
static_assert(offsetof(ccFlexCnt, field_08) == 0x08, "ccFlexCnt::field_08");
static_assert(offsetof(ccFlexCnt, capacity) == 0x10, "ccFlexCnt::capacity");


/*
 * ccFwInitParam
 * --------------
 * Vtable: PTR_FUN_1410f05d0 (set in ctor 0x887DA0).
 * Ctor (undefined8* param): *(uint32*)(param_1+1)=1 (byte 0x08),
 * *(uint32*)(param_1+2)=1 (byte 0x10), param_1[3]=0 (byte 0x18),
 * calls ccCollision::ManagerInitParam::ManagerInitParam(param_1+4) (byte 0x20).
 * ParseCore (0xB0E430) accesses embedded sub-object fields.
 * Size: unknown, >= 0xA8 (carried from s3; s4 ctor proves fields to +0x20+).
 */
typedef struct __attribute__((packed)) ccFwInitParam {
    /* 0x00 */ void    *vtable;              /* PTR_FUN_1410f05d0 */
    /* 0x08 */ uint32_t field_08;             /* *(uint32*)(param_1+1) = 1 */
    /* 0x0C */ uint32_t _pad_0c;
    /* 0x10 */ uint32_t field_10;             /* *(uint32*)(param_1+2) = 1 */
    /* 0x14 */ uint32_t _pad_14;
    /* 0x18 */ uint64_t field_18;             /* param_1[3] = 0 */
    /* 0x20 */ uint8_t  sub_collision_param[0x88]; /* ccCollision::ManagerInitParam at param_1+4 */
} ccFwInitParam;

static_assert(offsetof(ccFwInitParam, vtable) == 0x00, "ccFwInitParam::vtable");
static_assert(offsetof(ccFwInitParam, field_08) == 0x08, "ccFwInitParam::field_08");
static_assert(offsetof(ccFwInitParam, field_10) == 0x10, "ccFwInitParam::field_10");
static_assert(offsetof(ccFwInitParam, field_18) == 0x18, "ccFwInitParam::field_18");
static_assert(offsetof(ccFwInitParam, sub_collision_param) == 0x20, "ccFwInitParam::sub_collision_param");


/*
 * ccGameObjAttachDraw
 * --------------------
 * Vtable: PTR_FUN_14101b398 (set in ctor 0x552C48).
 * Ctor (0x552C48) initialises sub-objects: BlockAllocator at +0x28,
 * Matrix44 at +0x68, Vector3 at +0x118/+0x124/+0x130, Matrix44 at +0x13C.
 * Create (0x554E84) writes +0x20,+0x40,+0x48,+0x50,+0x60,+0xb0.
 * Update (0x55AB20) reads +0x18,+0x48,+0x68,+0xa8,+0xb0,+0x13c,+0x17c,+0x180.
 * IsAttach (0x558F2C) reads +0xc4,+0xb4,+0xbc,+0xc0,+0x188,+0xc8(int at 200=0xc8).
 * SetMatrixPosRot (0x55A95C) writes Matrix44 at +0x68.
 * Size: unknown, >= 0x18C (last proven access at +0x188 in IsAttach).
 */
typedef struct __attribute__((packed)) ccGameObjAttachDraw {
    /* 0x000 */ void    *vtable;              /* PTR_FUN_14101b398 */
    /* 0x008 */ uint8_t  _pad_008[0x10];      /* gap to base sub-object area */
    /* 0x018 */ int32_t  coord_mode;          /* read in Update: 0/1/2 switch */
    /* 0x01C */ uint32_t _pad_01c;
    /* 0x020 */ uint64_t chunk_data_ptr;      /* written in Create */
    /* 0x028 */ uint8_t  sub_block_allocator[0x18]; /* BlockAllocator init in ctor */
    /* 0x040 */ uint64_t name_str_ptr;        /* heap-allocated name copy in Create */
    /* 0x048 */ uint64_t nucc_coord_ptr;      /* GetWorldPosNew arg in Update */
    /* 0x050 */ uint64_t anm_base_ptr;        /* nuccAnmBase::GetInstance result in Create */
    /* 0x058 */ uint8_t  _pad_058[0x10];
    /* 0x068 */ uint8_t  sub_matrix44_a[0x40]; /* Matrix44_MathGeo in ctor/SetMatrixPosRot */
    /* 0x0A8 */ int32_t  heap_flag;           /* *(int*)(param_1+0xa8) != 0 check in Update */
    /* 0x0AC */ uint32_t _pad_0ac;
    /* 0x0B0 */ int32_t  attach_count;        /* *(int*)(param_1+0xb0) in Update/Create */
    /* 0x0B4 */ int32_t  flag_b4;             /* checked in IsAttach modes 1,2 */
    /* 0x0B8 */ uint32_t _pad_0b8;
    /* 0x0BC */ int32_t  flag_bc;             /* checked in IsAttach mode 3 */
    /* 0x0C0 */ int32_t  flag_c0;             /* checked in IsAttach mode 4 */
    /* 0x0C4 */ int32_t  flag_c4;             /* checked in IsAttach mode 5 */
    /* 0x0C8 */ int32_t  mode_tag;            /* *(int*)(param_1+200)=0xc8 in IsAttach */
    /* 0x0CC */ uint32_t _pad_0cc;
    /* 0x0D0 */ uint64_t xfbin_doc_ptr;       /* accessed in ctor 0x4FC7B0 */
    /* 0x0D8 */ uint8_t  _pad_0d8[0x40]; /* gap to Vector3 region */
    /* 0x118 */ uint8_t  sub_vector3_a[0x0C]; /* Vector3 in ctor */
    /* 0x124 */ uint8_t  sub_vector3_b[0x0C]; /* Vector3 in ctor */
    /* 0x130 */ uint8_t  sub_vector3_c[0x0C]; /* Vector3 in ctor */
    /* 0x13C */ uint8_t  sub_matrix44_b[0x40]; /* Matrix44_MathGeo in ctor/Update */
    /* 0x17C */ float    blend_factor;        /* *(float*)(param_1+0x17c) in Update */
    /* 0x180 */ int32_t  effect_init_flag;    /* set to 1 in Update when blend>=0.6 */
    /* 0x184 */ uint32_t _pad_184;
    /* 0x188 */ int32_t  extended_mode;       /* checked ==6..10 in IsAttach */
    /* 0x18C */ uint32_t _pad_18c;
} ccGameObjAttachDraw;

static_assert(offsetof(ccGameObjAttachDraw, vtable) == 0x000, "ccGameObjAttachDraw::vtable");
static_assert(offsetof(ccGameObjAttachDraw, coord_mode) == 0x018, "ccGameObjAttachDraw::coord_mode");
static_assert(offsetof(ccGameObjAttachDraw, chunk_data_ptr) == 0x020, "ccGameObjAttachDraw::chunk_data_ptr");
static_assert(offsetof(ccGameObjAttachDraw, sub_block_allocator) == 0x028, "ccGameObjAttachDraw::sub_block_allocator");
static_assert(offsetof(ccGameObjAttachDraw, name_str_ptr) == 0x040, "ccGameObjAttachDraw::name_str_ptr");
static_assert(offsetof(ccGameObjAttachDraw, nucc_coord_ptr) == 0x048, "ccGameObjAttachDraw::nucc_coord_ptr");
static_assert(offsetof(ccGameObjAttachDraw, anm_base_ptr) == 0x050, "ccGameObjAttachDraw::anm_base_ptr");
static_assert(offsetof(ccGameObjAttachDraw, sub_matrix44_a) == 0x068, "ccGameObjAttachDraw::sub_matrix44_a");
static_assert(offsetof(ccGameObjAttachDraw, heap_flag) == 0x0A8, "ccGameObjAttachDraw::heap_flag");
static_assert(offsetof(ccGameObjAttachDraw, attach_count) == 0x0B0, "ccGameObjAttachDraw::attach_count");
static_assert(offsetof(ccGameObjAttachDraw, flag_b4) == 0x0B4, "ccGameObjAttachDraw::flag_b4");
static_assert(offsetof(ccGameObjAttachDraw, flag_bc) == 0x0BC, "ccGameObjAttachDraw::flag_bc");
static_assert(offsetof(ccGameObjAttachDraw, flag_c0) == 0x0C0, "ccGameObjAttachDraw::flag_c0");
static_assert(offsetof(ccGameObjAttachDraw, flag_c4) == 0x0C4, "ccGameObjAttachDraw::flag_c4");
static_assert(offsetof(ccGameObjAttachDraw, mode_tag) == 0x0C8, "ccGameObjAttachDraw::mode_tag");
static_assert(offsetof(ccGameObjAttachDraw, xfbin_doc_ptr) == 0x0D0, "ccGameObjAttachDraw::xfbin_doc_ptr");
static_assert(offsetof(ccGameObjAttachDraw, sub_vector3_a) == 0x118, "ccGameObjAttachDraw::sub_vector3_a");
static_assert(offsetof(ccGameObjAttachDraw, sub_vector3_b) == 0x124, "ccGameObjAttachDraw::sub_vector3_b");
static_assert(offsetof(ccGameObjAttachDraw, sub_vector3_c) == 0x130, "ccGameObjAttachDraw::sub_vector3_c");
static_assert(offsetof(ccGameObjAttachDraw, sub_matrix44_b) == 0x13C, "ccGameObjAttachDraw::sub_matrix44_b");
static_assert(offsetof(ccGameObjAttachDraw, blend_factor) == 0x17C, "ccGameObjAttachDraw::blend_factor");
static_assert(offsetof(ccGameObjAttachDraw, effect_init_flag) == 0x180, "ccGameObjAttachDraw::effect_init_flag");
static_assert(offsetof(ccGameObjAttachDraw, extended_mode) == 0x188, "ccGameObjAttachDraw::extended_mode");


/*
 * ccGameProperty
 * ---------------
 * Vtable: not found in s4 ctors (no dedicated ccGameProperty::ccGameProperty symbol);
 * likely embedded or constructed inline.
 * state_surface returned 0 fields (byte-cast only access pattern).
 * Layout carried from s3 with offsets re-verified against s4 Authorize/Deauthorize.
 * Authorize (0xAB75C0): list head at +0x28, sentinel at +0x30.
 * Deauthorize (0xAB7670): same +0x28/+0x30 plus allocator handle at +0x38.
 * Size: unknown, >= 0x40 (last proven access at +0x38 in Deauthorize).
 */
typedef struct __attribute__((packed)) ccGameProperty {
    /* 0x00 */ void    *vtable_or_root;       /* tree root ptr or vtable */
    /* 0x08 */ uint8_t  _pad_08[0x20];        /* gap to list head */
    /* 0x28 */ uint64_t list_head;            /* std::list node ptr (Authorize/Deauthorize) */
    /* 0x30 */ uint64_t list_size_or_sentinel; /* sentinel value 0xaaaaaaaaaaaaaa9 */
    /* 0x38 */ uint64_t allocator_or_mutex;   /* passed to cleanup fn in Deauthorize */
} ccGameProperty;

static_assert(offsetof(ccGameProperty, vtable_or_root) == 0x00, "ccGameProperty::vtable_or_root");
static_assert(offsetof(ccGameProperty, list_head) == 0x28, "ccGameProperty::list_head");
static_assert(offsetof(ccGameProperty, list_size_or_sentinel) == 0x30, "ccGameProperty::list_size_or_sentinel");
static_assert(offsetof(ccGameProperty, allocator_or_mutex) == 0x38, "ccGameProperty::allocator_or_mutex");


/*
 * ccGamePropertyPermit
 * ---------------------
 * Vtable: PTR_FUN_1410075d8 (set in ctor 0xA05070).
 * Ctor 0xA05070: *param_1=0, param_1[1]=0, param_1[2]=vtable ptr,
 *   calls BlockAllocator and GetOwnerHandle.
 * Ctor 0xB12600: *param_1=0, *(uint64*)(param_1+2)=0 (simple zero-init).
 * Dtor (0xB12620): empty body (return only).
 * Deauthorized (0xB12650): *param_1=0, *(uint64*)(param_1+2)=0.
 * Size: unknown, >= 0x18 (last proven write at +0x10 in ctor/Deauthorized).
 * Note: s3 had size >=0x17C from dtor access at +0x178; s4 dtor is empty,
 * so that field may have been removed or inlined. Using s4 evidence only.
 */
typedef struct __attribute__((packed)) ccGamePropertyPermit {
    /* 0x00 */ uint64_t field_00;             /* *param_1 = 0 in ctor */
    /* 0x08 */ uint64_t field_08;             /* param_1[1] = 0 in ctor */
    /* 0x10 */ uint64_t field_10;             /* *(uint64*)(param_1+2) = 0 or vtable */
} ccGamePropertyPermit;

static_assert(offsetof(ccGamePropertyPermit, field_00) == 0x00, "ccGamePropertyPermit::field_00");
static_assert(offsetof(ccGamePropertyPermit, field_08) == 0x08, "ccGamePropertyPermit::field_08");
static_assert(offsetof(ccGamePropertyPermit, field_10) == 0x10, "ccGamePropertyPermit::field_10");


/*
 * ccLightManager
 * ---------------
 * Vtable: PTR_FUN_1410eab40 (set in ctor 0x864D34).
 * Calls ccCmnLightManager base ctor.
 * nuccLightModeTbl at +0x98 (count 8), +0xC0 (count 4).
 * 6x nuccCOLOR at +0xF0,+0x100,+0x110,+0x120,+0x130,+0x140.
 * 3x Vector3 at +0x150,+0x15C,+0x168.
 * uint32 writes at +0x158,+0x164,+0x170.
 * CalcLightParam (0x864F14) confirms all field offsets match s3 layout.
 * Size: unknown, >= 0x174 (last proven write at +0x170, uint32).
 */
typedef struct __attribute__((packed)) ccLightManager {
    /* 0x000 */ void    *vtable;              /* PTR_FUN_1410eab40 */
    /* 0x008 */ uint8_t  _pad_08[0x90];       /* gap to first sub-object */
    /* 0x098 */ uint8_t  sub_light_tbl_a[0x28]; /* 8 elements via ctor */
    /* 0x0C0 */ uint8_t  sub_light_tbl_b[0x30]; /* 4 elements via ctor */
    /* 0x0F0 */ uint8_t  sub_light_0f0[0x10]; /* nuccCOLOR */
    /* 0x100 */ uint8_t  sub_light_100[0x10]; /* nuccCOLOR */
    /* 0x110 */ uint8_t  sub_light_110[0x10]; /* nuccCOLOR */
    /* 0x120 */ uint8_t  sub_light_120[0x10]; /* nuccCOLOR */
    /* 0x130 */ uint8_t  sub_light_130[0x10]; /* nuccCOLOR */
    /* 0x140 */ uint8_t  sub_light_140[0x10]; /* nuccCOLOR */
    /* 0x150 */ uint64_t field_150;           /* rw Vector3.xy via CalcLightParam */
    /* 0x158 */ uint32_t field_158;           /* write-only uint32 in CalcLightParam */
    /* 0x15C */ uint64_t field_15c;           /* rw Vector3.xy via CalcLightParam */
    /* 0x164 */ uint32_t field_164;           /* write-only uint32 in CalcLightParam */
    /* 0x168 */ uint64_t field_168;           /* rw Vector3.xy via CalcLightParam */
    /* 0x170 */ uint32_t field_170;           /* write-only uint32 in CalcLightParam */
} ccLightManager;

static_assert(offsetof(ccLightManager, vtable) == 0x000, "ccLightManager::vtable");
static_assert(offsetof(ccLightManager, sub_light_tbl_a) == 0x098, "ccLightManager::sub_light_tbl_a");
static_assert(offsetof(ccLightManager, sub_light_tbl_b) == 0x0C0, "ccLightManager::sub_light_tbl_b");
static_assert(offsetof(ccLightManager, sub_light_0f0) == 0x0F0, "ccLightManager::sub_light_0f0");
static_assert(offsetof(ccLightManager, sub_light_100) == 0x100, "ccLightManager::sub_light_100");
static_assert(offsetof(ccLightManager, sub_light_110) == 0x110, "ccLightManager::sub_light_110");
static_assert(offsetof(ccLightManager, sub_light_120) == 0x120, "ccLightManager::sub_light_120");
static_assert(offsetof(ccLightManager, sub_light_130) == 0x130, "ccLightManager::sub_light_130");
static_assert(offsetof(ccLightManager, sub_light_140) == 0x140, "ccLightManager::sub_light_140");
static_assert(offsetof(ccLightManager, field_150) == 0x150, "ccLightManager::field_150");
static_assert(offsetof(ccLightManager, field_158) == 0x158, "ccLightManager::field_158");
static_assert(offsetof(ccLightManager, field_15c) == 0x15C, "ccLightManager::field_15c");
static_assert(offsetof(ccLightManager, field_164) == 0x164, "ccLightManager::field_164");
static_assert(offsetof(ccLightManager, field_168) == 0x168, "ccLightManager::field_168");
static_assert(offsetof(ccLightManager, field_170) == 0x170, "ccLightManager::field_170");

#endif /* CMN04_S4_H */