/* cmn42 s2 — INFERRED struct layouts for nuccAnm* classes (NSUNS2.exe, build s2)
 * All offsets derived from PC x64 decompile of s2 constructors/methods.
 * Sizes are INFERRED unless proven by operator_new__ or allocator call.
 * Field names from s2 decompiled code; cross-referenced with s1 layout where identical.
 * Tag: SIM = simulation state, PRES = presentation/render, UNKNOWN = unclear role.
 */
#ifndef CMN42_S2_H
#define CMN42_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccAnmBase — base animation object
 * Ctor at 0x58B4F0. Vtable set by parent (BlockAllocator).
 * Size unknown, >= 0x98 (last field param_1[0x12] at offset 0x90, 8 bytes).
 * Fields from state_surface + ctor analysis.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmBase {
    /* 0x00 */ void     *vtable;          /* PRES: set by parent ctor */
    /* 0x08 */ uint8_t   _base_init[0x10];/* UNKNOWN: BlockAllocator + early ctor inits */
    /* 0x18 */ uint64_t  field_0x18;      /* PRES: param_1[3] = 0 in ctor */
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
 * Ctor at 0x58CA30. No vtable set in ctor (inherits from parent?).
 * Fields: +0x08 allocator ptr (read for operator_new__), +0x18 data ptr, +0x20 count.
 * Size unknown, >= 0x28 (last proven field at 0x20, 4 bytes + padding).
 * Element stride 0x18 (btNullPairCache, 6 ints each).
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
 * Ctor at 0x601810. Vtable PTR_FUN_140898b18 (first sub), parent vtable not directly set.
 * Contains 4 sub-controllers (translate/rotate/scale/opacity) each with own vtable.
 * Layout: 4 pointers at [1],[2],[3],[4] pointing to embedded sub-objects.
 * Embedded sub-objects start at 0x60 with 0x60 stride.
 * Size unknown, >= 0x1E0 (last sub at 0x180 + 0x60).
 * Vtables from ctor: translate=&PTR_FUN_140898b18, rotate=&PTR_FUN_140898b98,
 *   scale=&PTR_FUN_140898b18, opacity=&PTR_FUN_140898b58.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlInterpCoord {
    /* 0x00 */ void *vtable;                          /* PRES: parent vtable */
    /* 0x08 */ nuccAnmCtrlInterpCoord_sub *sub_translate; /* PRES: ptr to embedded +0x60 */
    /* 0x10 */ nuccAnmCtrlInterpCoord_sub *sub_rotate;    /* PRES: ptr to embedded +0xC0 */
    /* 0x18 */ nuccAnmCtrlInterpCoord_sub *sub_scale;     /* PRES: ptr to embedded +0x120 */
    /* 0x20 */ nuccAnmCtrlInterpCoord_sub *sub_opacity;   /* PRES: ptr to embedded +0x180 */
    /* 0x28 */ uint64_t field_0x28;                   /* PRES: param_1[5] = 0 */
    /* 0x30 */ uint8_t  _gap_0x30[0x30];              /* UNKNOWN: gap before embedded sub-objects */
    /* 0x60 */ nuccAnmCtrlInterpCoord_sub sub_obj_translate; /* PRES: vtable=&PTR_FUN_140898b18 */
    /* 0xC0 */ nuccAnmCtrlInterpCoord_sub sub_obj_rotate;    /* PRES: vtable=&PTR_FUN_140898b98 */
    /* 0x120 */ nuccAnmCtrlInterpCoord_sub sub_obj_scale;    /* PRES: vtable=&PTR_FUN_140898b18 */
    /* 0x180 */ nuccAnmCtrlInterpCoord_sub sub_obj_opacity;  /* PRES: vtable=&PTR_FUN_140898b58 */
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
 * Ctor at 0x62DFA0. Vtable PTR_FUN_14089cfc0.
 * 3 key ctrl pointers (position, rotation, fov/target).
 * Size unknown, >= 0x20 (last field param_1[3] at offset 0x18, 8 bytes).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlCamera {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_14089cfc0 */
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
 * Ctor at 0x62EA00. Vtable PTR_FUN_14089d3b8.
 * 3 key ctrl pointers (direction, color, intensity).
 * Size unknown, >= 0x20.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlLightDirc {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_14089d3b8 */
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
 * Ctor at 0x62EC10. Vtable PTR_FUN_14089d3d8.
 * 5 key ctrl pointers (position, color, range, falloff, intensity).
 * Size unknown, >= 0x30 (last field param_1[5] at offset 0x28, 8 bytes).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlLightPoint {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_14089d3d8 */
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
 * Ctor at 0x62EEB0. Vtable PTR_FUN_14089d3f8.
 * 2 key ctrl pointers (color, intensity).
 * Size unknown, >= 0x18 (last field param_1[2] at offset 0x10, 8 bytes).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlAmbient {
    /* 0x00 */ void *vtable;      /* PRES: &PTR_FUN_14089d3f8 */
    /* 0x08 */ void *key_ctrl_0;  /* PRES */
    /* 0x10 */ void *key_ctrl_1;  /* PRES */
} nuccAnmCtrlAmbient;

static_assert(offsetof(nuccAnmCtrlAmbient, vtable)     == 0x00, "nuccAnmCtrlAmbient.vtable");
static_assert(offsetof(nuccAnmCtrlAmbient, key_ctrl_0) == 0x08, "nuccAnmCtrlAmbient.key_ctrl_0");
static_assert(offsetof(nuccAnmCtrlAmbient, key_ctrl_1) == 0x10, "nuccAnmCtrlAmbient.key_ctrl_1");

/* ========================================================================
 * nuccAnmCtrlMaterial — material animation controller
 * Ctor at 0x62F050. Vtable PTR_FUN_14089d418.
 * 18 key ctrl pointers for various material properties.
 * Size unknown, >= 0x98 (last field param_1[0x12] at offset 0x90, 8 bytes).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlMaterial {
    /* 0x00 */ void *vtable;       /* PRES: &PTR_FUN_14089d418 */
    /* 0x08 */ void *key_ctrl[18]; /* PRES: 18 key ctrl pointers */
} nuccAnmCtrlMaterial;

static_assert(offsetof(nuccAnmCtrlMaterial, vtable)   == 0x00, "nuccAnmCtrlMaterial.vtable");
static_assert(offsetof(nuccAnmCtrlMaterial, key_ctrl) == 0x08, "nuccAnmCtrlMaterial.key_ctrl");

/* ========================================================================
 * nuccAnmCtrlMorph — morph target animation controller
 * Ctor at 0x62F620. Vtable PTR_FUN_14089d438.
 * Dynamic array of weight key ctrls allocated via operator_new__.
 * Size unknown, >= 0x18 (weight_count at +0x10, 4 bytes + padding).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmCtrlMorph {
    /* 0x00 */ void    *vtable;       /* PRES: &PTR_FUN_14089d438 */
    /* 0x08 */ void   **weight_keys;  /* PRES: dynamically allocated array of key ctrl ptrs */
    /* 0x10 */ uint32_t weight_count; /* PRES: from nuccChunkAnmCtrlMorph::GetWeightNum */
    /* 0x14 */ uint8_t  _pad_0x14[4]; /* padding */
} nuccAnmCtrlMorph;

static_assert(offsetof(nuccAnmCtrlMorph, vtable)       == 0x00, "nuccAnmCtrlMorph.vtable");
static_assert(offsetof(nuccAnmCtrlMorph, weight_keys)  == 0x08, "nuccAnmCtrlMorph.weight_keys");
static_assert(offsetof(nuccAnmCtrlMorph, weight_count) == 0x10, "nuccAnmCtrlMorph.weight_count");

#endif /* CMN42_S2_H */