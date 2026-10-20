/* cmn42 s1 — INFERRED struct layouts for nuccAnm* classes (NSUNS1.exe, build s1)
 * All offsets derived from PC x64 decompile of s1 constructors/methods.
 * Sizes are INFERRED unless proven by operator_new__ or allocator call.
 * Field names from Switch Trilogy ns1:: namespace where mapped; otherwise generic.
 * Tag: SIM = simulation state, PRES = presentation/render, UNKNOWN = unclear role.
 */
#ifndef CMN42_S1_H
#define CMN42_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccAnmBase — base animation object
 * Ctor at 0x4B25C0. Vtable PTR_FUN_140739990.
 * Size unknown, >= 0x98 (last field param_1[0x12] at offset 0x90, 8 bytes).
 * Inherits Nucc::Memory::BlockAllocator (ctor called first).
 *
 * Byte offset derivation from ctor (param_1 is undefined8*):
 *   param_1[3]=0          -> byte 0x18
 *   param_1[4]=0          -> byte 0x20
 *   param_1[5]=0          -> byte 0x28
 *   param_1[6]=0          -> byte 0x30
 *   *(uint16*)(param_1+7) -> byte 0x38
 *   *(uint64*)(param_1+0x3C) -> byte 0x3C
 *   *(uint32*)(param_1+0x44)=1 -> byte 0x44
 *   *(uint32*)(param_1+9)=0x3f800000 -> byte 0x48 (1.0f)
 *   *(uint32*)(param_1+0x4C)=0x3f800000 -> byte 0x4C (1.0f)
 *   Nucc::Matrix44_MathGeo(param_1+10) -> byte 0x50, size 0x40 inferred
 *   param_1[0x12]         -> byte 0x90
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmBase {
    /* 0x00 */ void     *vtable;          /* PRES: &PTR_FUN_140739990 */
    /* 0x08 */ uint8_t   _base_init[0x10];/* UNKNOWN: BlockAllocator + early ctor inits */
    /* 0x18 */ uint64_t  field_0x18;      /* PRES: param_1[3] = 0 */
    /* 0x20 */ uint64_t  field_0x20;      /* PRES: param_1[4] = 0 */
    /* 0x28 */ uint64_t  field_0x28;      /* PRES: param_1[5] = 0 */
    /* 0x30 */ uint64_t  field_0x30;      /* PRES: param_1[6] = 0 */
    /* 0x38 */ uint16_t  field_0x38;      /* PRES: *(uint16*)(param_1+7) = 0 */
    /* 0x3A */ uint8_t   _pad_0x3A[2];    /* padding */
    /* 0x3C */ uint64_t  field_0x3C;      /* PRES: *(uint64*)(param_1+0x3C) = 0 */
    /* 0x44 */ uint32_t  field_0x44;      /* PRES: *(uint32*)(param_1+0x44) = 1 */
    /* 0x48 */ uint32_t  field_0x48;      /* PRES: 1.0f (0x3f800000) */
    /* 0x4C */ uint32_t  field_0x4C;      /* PRES: 1.0f (0x3f800000) */
    /* 0x50 */ uint8_t   matrix44[0x40];  /* PRES: Nucc::Matrix44_MathGeo, size inferred */
    /* 0x90 */ uint64_t  instance_list;   /* PRES: param_1[0x12], nuccInstanceList ptr or 0 */
} nuccAnmBase;

static_assert(offsetof(nuccAnmBase, vtable)       == 0x00, "nuccAnmBase.vtable");
static_assert(offsetof(nuccAnmBase, _base_init)    == 0x08, "nuccAnmBase._base_init");
static_assert(offsetof(nuccAnmBase, field_0x18)    == 0x18, "nuccAnmBase.field_0x18");
static_assert(offsetof(nuccAnmBase, field_0x20)    == 0x20, "nuccAnmBase.field_0x20");
static_assert(offsetof(nuccAnmBase, field_0x28)    == 0x28, "nuccAnmBase.field_0x28");
static_assert(offsetof(nuccAnmBase, field_0x30)    == 0x30, "nuccAnmBase.field_0x30");
static_assert(offsetof(nuccAnmBase, field_0x38)    == 0x38, "nuccAnmBase.field_0x38");
static_assert(offsetof(nuccAnmBase, field_0x3C)    == 0x3C, "nuccAnmBase.field_0x3C");
static_assert(offsetof(nuccAnmBase, field_0x44)    == 0x44, "nuccAnmBase.field_0x44");
static_assert(offsetof(nuccAnmBase, field_0x48)    == 0x48, "nuccAnmBase.field_0x48");
static_assert(offsetof(nuccAnmBase, field_0x4C)    == 0x4C, "nuccAnmBase.field_0x4C");
static_assert(offsetof(nuccAnmBase, matrix44)      == 0x50, "nuccAnmBase.matrix44");
static_assert(offsetof(nuccAnmBase, instance_list) == 0x90, "nuccAnmBase.instance_list");

/* ========================================================================
 * nuccAnmCtrlTrack — track-based animation controller
 * Ctor at 0x4AB210. No vtable set in ctor (inherits from parent?).
 * Fields: +0x08 allocator ptr (read for operator_new__), +0x18 data ptr, +0x20 count.
 * Size unknown, >= 0x28.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlTrack {
    /* 0x00 */ uint8_t  _base[0x08];      /* UNKNOWN: possible vtable or base class */
    /* 0x08 */ void    *allocator;        /* PRES: read for operator_new__ */
    /* 0x10 */ uint8_t  _pad_0x10[0x08];  /* UNKNOWN: gap 0x10..0x17 */
    /* 0x18 */ void    *data_ptr;         /* PRES: btNullPairCache array ptr or NULL */
    /* 0x20 */ uint32_t count;            /* PRES: element count (param_2) */
    /* 0x24 */ uint8_t  _pad_0x24[4];     /* padding to align */
} nuccAnmCtrlTrack;

static_assert(offsetof(nuccAnmCtrlTrack, allocator) == 0x08, "nuccAnmCtrlTrack.allocator");
static_assert(offsetof(nuccAnmCtrlTrack, data_ptr)  == 0x18, "nuccAnmCtrlTrack.data_ptr");
static_assert(offsetof(nuccAnmCtrlTrack, count)     == 0x20, "nuccAnmCtrlTrack.count");

/* ========================================================================
 * nuccAnmCtrlInterpCoord_sub — embedded sub-controller (translate/rotate/scale/opacity)
 * Each has a vtable (8) and a uint16 flag (2). Spacing in the parent ctor shows
 * sub-objects at 0x60, 0xC0, 0x120, 0x180 → stride 0x60 per sub-object region.
 * Visible fields occupy 10 bytes; remaining 0x56 are opaque.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlInterpCoord_sub {
    void    *vtable;          /* PRES */
    uint16_t flag;            /* PRES: zeroed in ctor */
    uint8_t  _opaque[0x56];   /* UNKNOWN: remaining sub-object data */
} nuccAnmCtrlInterpCoord_sub;

/* ========================================================================
 * nuccAnmCtrlInterpCoord — interpolation coordinate controller
 * Ctor at 0x510C10. Vtable PTR_FUN_140741338.
 * Contains 4 sub-controllers (translate/rotate/scale/opacity) each with own vtable.
 * Layout: 4 pointers at [1],[2],[3],[4] pointing to embedded sub-objects.
 * Embedded sub-objects start at 0x60 with 0x60 stride.
 * Size unknown, >= 0x1A8 (last sub at 0x180 + 0x60 - but only 0x152 proven from ctor).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlInterpCoord {
    /* 0x00 */ void *vtable;                          /* PRES: &PTR_FUN_140741338 */
    /* 0x08 */ nuccAnmCtrlInterpCoord_sub *sub_translate; /* PRES: ptr to embedded +0x60 */
    /* 0x10 */ nuccAnmCtrlInterpCoord_sub *sub_rotate;    /* PRES: ptr to embedded +0xC0 */
    /* 0x18 */ nuccAnmCtrlInterpCoord_sub *sub_scale;     /* PRES: ptr to embedded +0x120 */
    /* 0x20 */ nuccAnmCtrlInterpCoord_sub *sub_opacity;   /* PRES: ptr to embedded +0x180 */
    /* 0x28 */ uint64_t field_0x28;                   /* PRES: param_1[5] = 0 */
    /* 0x30 */ uint8_t  _gap_0x30[0x30];              /* UNKNOWN: gap before embedded sub-objects */
    /* 0x60 */ nuccAnmCtrlInterpCoord_sub sub_obj_translate; /* PRES: vtable=&PTR_FUN_140740b78 */
    /* 0xC0 */ nuccAnmCtrlInterpCoord_sub sub_obj_rotate;    /* PRES: vtable=&PTR_FUN_1407412e8 */
    /* 0x120 */ nuccAnmCtrlInterpCoord_sub sub_obj_scale;    /* PRES: vtable=&PTR_FUN_140740b78 */
    /* 0x180 */ nuccAnmCtrlInterpCoord_sub sub_obj_opacity;  /* PRES: vtable=&PTR_FUN_140740c38 */
} nuccAnmCtrlInterpCoord;

static_assert(offsetof(nuccAnmCtrlInterpCoord, vtable)           == 0x00,  "nuccAnmCtrlInterpCoord.vtable");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_translate)    == 0x08,  "nuccAnmCtrlInterpCoord.sub_translate");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_rotate)       == 0x10,  "nuccAnmCtrlInterpCoord.sub_rotate");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_scale)        == 0x18,  "nuccAnmCtrlInterpCoord.sub_scale");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_opacity)      == 0x20,  "nuccAnmCtrlInterpCoord.sub_opacity");
static_assert(offsetof(nuccAnmCtrlInterpCoord, field_0x28)       == 0x28,  "nuccAnmCtrlInterpCoord.field_0x28");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_obj_translate)== 0x60,  "nuccAnmCtrlInterpCoord.sub_obj_translate");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_obj_rotate)   == 0xC0,  "nuccAnmCtrlInterpCoord.sub_obj_rotate");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_obj_scale)    == 0x120, "nuccAnmCtrlInterpCoord.sub_obj_scale");
static_assert(offsetof(nuccAnmCtrlInterpCoord, sub_obj_opacity)  == 0x180, "nuccAnmCtrlInterpCoord.sub_obj_opacity");

/* ========================================================================
 * nuccAnmCtrlCamera — camera animation controller
 * Ctor at 0x532190. Vtable PTR_FUN_140744fc0.
 * 3 key ctrl pointers (position, rotation, fov/target).
 * Size unknown, >= 0x20.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlCamera {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_140744fc0 */
    /* 0x08 */ void *key_ctrl_0;  /* PRES: nuccAnmKey::CreateKeyCtrl(param_2+0x18) */
    /* 0x10 */ void *key_ctrl_1;  /* PRES: nuccAnmKey::CreateKeyCtrl(param_2+0x30) */
    /* 0x18 */ void *key_ctrl_2;  /* PRES: nuccAnmKey::CreateKeyCtrl(param_2+0x48) */
} nuccAnmCtrlCamera;

static_assert(offsetof(nuccAnmCtrlCamera, vtable)     == 0x00, "nuccAnmCtrlCamera.vtable");
static_assert(offsetof(nuccAnmCtrlCamera, key_ctrl_0) == 0x08, "nuccAnmCtrlCamera.key_ctrl_0");
static_assert(offsetof(nuccAnmCtrlCamera, key_ctrl_1) == 0x10, "nuccAnmCtrlCamera.key_ctrl_1");
static_assert(offsetof(nuccAnmCtrlCamera, key_ctrl_2) == 0x18, "nuccAnmCtrlCamera.key_ctrl_2");

/* ========================================================================
 * nuccAnmCtrlLightDirc — directional light animation controller
 * Ctor at 0x5323D0. Vtable PTR_FUN_140744fe0.
 * 3 key ctrl pointers (direction, color, intensity).
 * Size unknown, >= 0x20.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlLightDirc {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_140744fe0 */
    /* 0x08 */ void *key_ctrl_0;  /* PRES */
    /* 0x10 */ void *key_ctrl_1;  /* PRES */
    /* 0x18 */ void *key_ctrl_2;  /* PRES */
} nuccAnmCtrlLightDirc;

static_assert(offsetof(nuccAnmCtrlLightDirc, vtable)     == 0x00, "nuccAnmCtrlLightDirc.vtable");
static_assert(offsetof(nuccAnmCtrlLightDirc, key_ctrl_0) == 0x08, "nuccAnmCtrlLightDirc.key_ctrl_0");
static_assert(offsetof(nuccAnmCtrlLightDirc, key_ctrl_1) == 0x10, "nuccAnmCtrlLightDirc.key_ctrl_1");
static_assert(offsetof(nuccAnmCtrlLightDirc, key_ctrl_2) == 0x18, "nuccAnmCtrlLightDirc.key_ctrl_2");

/* ========================================================================
 * nuccAnmCtrlLightPoint — point light animation controller
 * Ctor at 0x5325E0. Vtable PTR_FUN_140745000.
 * 5 key ctrl pointers (position, color, range, falloff, intensity).
 * Size unknown, >= 0x30.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlLightPoint {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_140745000 */
    /* 0x08 */ void *key_ctrl_0;  /* PRES */
    /* 0x10 */ void *key_ctrl_1;  /* PRES */
    /* 0x18 */ void *key_ctrl_2;  /* PRES */
    /* 0x20 */ void *key_ctrl_3;  /* PRES */
    /* 0x28 */ void *key_ctrl_4;  /* PRES */
} nuccAnmCtrlLightPoint;

static_assert(offsetof(nuccAnmCtrlLightPoint, vtable)     == 0x00, "nuccAnmCtrlLightPoint.vtable");
static_assert(offsetof(nuccAnmCtrlLightPoint, key_ctrl_0) == 0x08, "nuccAnmCtrlLightPoint.key_ctrl_0");
static_assert(offsetof(nuccAnmCtrlLightPoint, key_ctrl_1) == 0x10, "nuccAnmCtrlLightPoint.key_ctrl_1");
static_assert(offsetof(nuccAnmCtrlLightPoint, key_ctrl_2) == 0x18, "nuccAnmCtrlLightPoint.key_ctrl_2");
static_assert(offsetof(nuccAnmCtrlLightPoint, key_ctrl_3) == 0x20, "nuccAnmCtrlLightPoint.key_ctrl_3");
static_assert(offsetof(nuccAnmCtrlLightPoint, key_ctrl_4) == 0x28, "nuccAnmCtrlLightPoint.key_ctrl_4");

/* ========================================================================
 * nuccAnmCtrlAmbient — ambient light animation controller
 * Ctor at 0x532880. Vtable PTR_FUN_140745020.
 * 2 key ctrl pointers (color, intensity).
 * Size unknown, >= 0x18.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlAmbient {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_140745020 */
    /* 0x08 */ void *key_ctrl_0;  /* PRES */
    /* 0x10 */ void *key_ctrl_1;  /* PRES */
} nuccAnmCtrlAmbient;

static_assert(offsetof(nuccAnmCtrlAmbient, vtable)     == 0x00, "nuccAnmCtrlAmbient.vtable");
static_assert(offsetof(nuccAnmCtrlAmbient, key_ctrl_0) == 0x08, "nuccAnmCtrlAmbient.key_ctrl_0");
static_assert(offsetof(nuccAnmCtrlAmbient, key_ctrl_1) == 0x10, "nuccAnmCtrlAmbient.key_ctrl_1");

/* ========================================================================
 * nuccAnmCtrlMaterial — material animation controller
 * Ctor at 0x532A20. Vtable PTR_FUN_140745040.
 * 18 key ctrl pointers for various material properties.
 * Size unknown, >= 0x98.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlMaterial {
    /* 0x00 */ void *vtable;       /* PRES: &PTR_FUN_140745040 */
    /* 0x08 */ void *key_ctrl[18]; /* PRES: 18 key ctrl pointers */
} nuccAnmCtrlMaterial;

static_assert(offsetof(nuccAnmCtrlMaterial, vtable)   == 0x00, "nuccAnmCtrlMaterial.vtable");
static_assert(offsetof(nuccAnmCtrlMaterial, key_ctrl) == 0x08, "nuccAnmCtrlMaterial.key_ctrl");

/* ========================================================================
 * nuccAnmCtrlMorph — morph target animation controller
 * Ctor at 0x4A1840. Vtable PTR_FUN_1407389a0.
 * Dynamic array of weight key ctrls allocated via operator_new__.
 * Size unknown, >= 0x18.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlMorph {
    /* 0x00 */ void    *vtable;       /* PRES: &PTR_FUN_1407389a0 */
    /* 0x08 */ void   **weight_keys;  /* PRES: dynamically allocated array of key ctrl ptrs */
    /* 0x10 */ uint32_t weight_count; /* PRES: from nuccChunkAnmCtrlMorph::GetWeightNum */
    /* 0x14 */ uint8_t  _pad_0x14[4]; /* padding */
} nuccAnmCtrlMorph;

static_assert(offsetof(nuccAnmCtrlMorph, vtable)       == 0x00, "nuccAnmCtrlMorph.vtable");
static_assert(offsetof(nuccAnmCtrlMorph, weight_keys)  == 0x08, "nuccAnmCtrlMorph.weight_keys");
static_assert(offsetof(nuccAnmCtrlMorph, weight_count) == 0x10, "nuccAnmCtrlMorph.weight_count");

#endif /* CMN42_S1_H */