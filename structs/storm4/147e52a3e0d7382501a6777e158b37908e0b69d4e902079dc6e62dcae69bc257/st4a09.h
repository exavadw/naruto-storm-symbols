/* st4a09.h — Story/adventure struct layouts for NARUTO STORM 4 PC 1.09 (s4)
 *
 * ALL LAYOUTS ARE INFERRED FROM STATIC DECOMPILATION, NOT CONFIRMED AT RUNTIME.
 * PC offsets only (image base 0x140000000). Own-game names only for s4.
 *
 * Generated: 2026-10-19
 * Task: st4a09
 */

#ifndef ST4A09_H
#define ST4A09_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * ccAdvBaseAnm — animation controller for adventure objects
 * Size: >= 0xB0 (proven by operator_new(0xb0) in ccAdvMobObject::Create)
 * Vtable: PTR_LAB_141002060 (set in ctor at 0x47E260)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccAdvBaseAnm {
    /* +0x00 */ void *vtable;              /* PTR_LAB_141002060 */
    /* +0x08 */ void *nucc_anm;            /* ptr to nuccAnm (alloc 0x1c0 in Create) */
    /* +0x10 */ uint64_t block_alloc_0;    /* BlockAllocator field param_1[2] */
    /* +0x18 */ uint64_t block_alloc_1;    /* BlockAllocator field param_1[3] */
    /* +0x20 */ uint64_t block_alloc_2;    /* BlockAllocator field param_1[4] */
    /* +0x28 */ uint64_t block_alloc_3;    /* BlockAllocator field param_1[5] */
    /* +0x30 */ uint8_t _pad_30[0x10];     /* gap to Vector3 at +0x40 */
    /* +0x40 */ float position[3];         /* Nucc::Vector3 (12 bytes) */
    /* +0x4C */ uint32_t _pad_4c;          /* padding before Matrix44 */
    /* +0x50 */ float matrix[16];          /* Nucc::Matrix44_MathGeo (64 bytes) */
    /* +0x90 */ float scale[3];            /* Nucc::Vector3 scale, default 1,1,1 */
    /* +0x9C */ uint32_t _pad_9c;          /* padding */
    /* +0xA0 */ uint32_t flag_a0;          /* set to 0 in Create */
    /* +0xA4 */ uint32_t flag_a4;          /* set to 0 in ctor */
    /* +0xA8 */ uint64_t handle_a8;        /* set to 0xFFFFFFFFFFFFFFFF in ctor */
} ccAdvBaseAnm;

_Static_assert(offsetof(ccAdvBaseAnm, vtable) == 0x00, "ccAdvBaseAnm.vtable");
_Static_assert(offsetof(ccAdvBaseAnm, nucc_anm) == 0x08, "ccAdvBaseAnm.nucc_anm");
_Static_assert(offsetof(ccAdvBaseAnm, block_alloc_0) == 0x10, "ccAdvBaseAnm.block_alloc_0");
_Static_assert(offsetof(ccAdvBaseAnm, block_alloc_1) == 0x18, "ccAdvBaseAnm.block_alloc_1");
_Static_assert(offsetof(ccAdvBaseAnm, block_alloc_2) == 0x20, "ccAdvBaseAnm.block_alloc_2");
_Static_assert(offsetof(ccAdvBaseAnm, block_alloc_3) == 0x28, "ccAdvBaseAnm.block_alloc_3");
_Static_assert(offsetof(ccAdvBaseAnm, position) == 0x40, "ccAdvBaseAnm.position");
_Static_assert(offsetof(ccAdvBaseAnm, matrix) == 0x50, "ccAdvBaseAnm.matrix");
_Static_assert(offsetof(ccAdvBaseAnm, scale) == 0x90, "ccAdvBaseAnm.scale");
_Static_assert(offsetof(ccAdvBaseAnm, flag_a0) == 0xA0, "ccAdvBaseAnm.flag_a0");
_Static_assert(offsetof(ccAdvBaseAnm, flag_a4) == 0xA4, "ccAdvBaseAnm.flag_a4");
_Static_assert(offsetof(ccAdvBaseAnm, handle_a8) == 0xA8, "ccAdvBaseAnm.handle_a8");


/* =========================================================================
 * ccAdvBaseCoord — coordinate/matrix holder for adventure objects
 * Size: 0x48 (8 vtable + 64 matrix, proven by ctor layout at 0x47F2DC)
 * Vtable: set in ctor at 0x47F2DC
 * ========================================================================= */
typedef struct __attribute__((packed)) ccAdvBaseCoord {
    /* +0x00 */ void *vtable;
    /* +0x08 */ float local_matrix[16];   /* Nucc::Matrix44_MathGeo identity (64 bytes) */
} ccAdvBaseCoord;

_Static_assert(offsetof(ccAdvBaseCoord, vtable) == 0x00, "ccAdvBaseCoord.vtable");
_Static_assert(offsetof(ccAdvBaseCoord, local_matrix) == 0x08, "ccAdvBaseCoord.local_matrix");


/* =========================================================================
 * ccAdvCalc3dNormalCameraPos — 3D normal camera position calculator
 * Size: >= 0xE0 (last field at +0xDC, rounded up)
 * No named constructor found; Init at 0x482CE8 provides field layout.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccAdvCalc3dNormalCameraPos {
    /* +0x00 */ void *vtable;             /* implied */
    /* +0x08 */ uint64_t target_ptr;      /* from param_2[0] */
    /* +0x10 */ uint32_t target_field;    /* from param_2[1] low */
    /* +0x14 */ uint64_t source_ptr;      /* from param_3[0] */
    /* +0x1C */ uint32_t source_field;    /* from param_3[1] low */
    /* +0x20 */ float height;             /* clamped >= 120.0, scaled from chara */
    /* +0x24 */ float default_val;        /* default 0xC0200000 (-2.5f) */
    /* +0x28 */ uint32_t zero_28;         /* set to 0 */
    /* +0x2C */ uint32_t _pad_2c;
    /* +0x30 */ uint8_t cmn_rotate[0x58]; /* ccCmnRotate embedded (SetAngleXYZ/InterpTurnZ/X/CalculateZXY) */
    /* +0x88 */ float direction[3];       /* Nucc::Vector3 result */
    /* +0x94 */ uint32_t dir_w;           /* Vector3 W component / padding */
    /* +0x98 */ uint8_t _pad_98[0x08];
    /* +0xA0 */ uint32_t zero_a0;         /* set to 0 */
    /* +0xA4 */ uint8_t _pad_a4[0x0C];
    /* +0xB0 */ uint8_t _gap_b0[0x20];    /* gap to 0xD0 */
    /* +0xD0 */ uint32_t flag_d0;         /* set based on DAT_14161ffcc */
    /* +0xD4 */ uint32_t flag_d4;         /* set based on DAT_14161ffcc */
    /* +0xD8 */ uint32_t _pad_d8;
    /* +0xDC */ uint32_t one_dc;          /* set to 1 */
} ccAdvCalc3dNormalCameraPos;

_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, vtable) == 0x00, "ccAdvCalc3dNormalCameraPos.vtable");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, target_ptr) == 0x08, "ccAdvCalc3dNormalCameraPos.target_ptr");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, target_field) == 0x10, "ccAdvCalc3dNormalCameraPos.target_field");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, source_ptr) == 0x14, "ccAdvCalc3dNormalCameraPos.source_ptr");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, source_field) == 0x1C, "ccAdvCalc3dNormalCameraPos.source_field");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, height) == 0x20, "ccAdvCalc3dNormalCameraPos.height");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, default_val) == 0x24, "ccAdvCalc3dNormalCameraPos.default_val");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, zero_28) == 0x28, "ccAdvCalc3dNormalCameraPos.zero_28");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, cmn_rotate) == 0x30, "ccAdvCalc3dNormalCameraPos.cmn_rotate");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, direction) == 0x88, "ccAdvCalc3dNormalCameraPos.direction");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, dir_w) == 0x94, "ccAdvCalc3dNormalCameraPos.dir_w");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, zero_a0) == 0xA0, "ccAdvCalc3dNormalCameraPos.zero_a0");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, flag_d0) == 0xD0, "ccAdvCalc3dNormalCameraPos.flag_d0");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, flag_d4) == 0xD4, "ccAdvCalc3dNormalCameraPos.flag_d4");
_Static_assert(offsetof(ccAdvCalc3dNormalCameraPos, one_dc) == 0xDC, "ccAdvCalc3dNormalCameraPos.one_dc");


/* =========================================================================
 * ccAdvCalcCameraPos — base camera position calculator
 * Size: >= 0x20 (last proven field at +0x18, 8-byte ptr)
 * Ctor at 0x235770, Init at 0x48387C.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccAdvCalcCameraPos {
    /* +0x00 */ void *vtable;
    /* +0x08 */ uint64_t zero_08;         /* zeroed in ctor */
    /* +0x10 */ void *owner;              /* param_2 in ctor */
    /* +0x18 */ void *nucc_anm_base;      /* from Init param */
} ccAdvCalcCameraPos;

_Static_assert(offsetof(ccAdvCalcCameraPos, vtable) == 0x00, "ccAdvCalcCameraPos.vtable");
_Static_assert(offsetof(ccAdvCalcCameraPos, zero_08) == 0x08, "ccAdvCalcCameraPos.zero_08");
_Static_assert(offsetof(ccAdvCalcCameraPos, owner) == 0x10, "ccAdvCalcCameraPos.owner");
_Static_assert(offsetof(ccAdvCalcCameraPos, nucc_anm_base) == 0x18, "ccAdvCalcCameraPos.nucc_anm_base");


/* =========================================================================
 * ccAdvCameraCtrl — adventure camera controller
 * Size: >= 0xF0 (last field at +0xEC, rounded up)
 * Init at 0x481094 provides field layout.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccAdvCameraCtrl {
    /* +0x00 */ uint8_t _base[0x54];      /* base class / padding before first seen field */
    /* +0x54 */ uint32_t flag_54;         /* set to 1 or 0 */
    /* +0x58 */ uint8_t _pad_58[0x08];
    /* +0x60 */ uint32_t flag_60;         /* set to 1 */
    /* +0x64 */ uint32_t _pad_64;
    /* +0x68 */ void *param_ptr;          /* param_3 in Init */
    /* +0x70 */ uint8_t _gap_70[0x08];
    /* +0x78 */ uint64_t field_78;        /* from param_2 */
    /* +0x80 */ uint32_t field_80;
    /* +0x84 */ uint64_t camera_pos_84;
    /* +0x8C */ uint32_t field_8c;
    /* +0x90 */ uint64_t field_90;
    /* +0x98 */ uint32_t field_98;
    /* +0x9C */ uint64_t field_9c;
    /* +0xA4 */ uint32_t field_a4;
    /* +0xA8 */ uint8_t _gap_a8[0x30];    /* gap to 0xD8 */
    /* +0xD8 */ uint32_t field_d8;
    /* +0xDC */ uint32_t _pad_dc;
    /* +0xE0 */ int32_t param4_e0;        /* param_4 in Init */
    /* +0xE4 */ int32_t param4_e4;        /* param_4 in Init */
    /* +0xE8 */ uint32_t _pad_e8;
    /* +0xEC */ uint32_t zero_ec;         /* set to 0 */
} ccAdvCameraCtrl;

_Static_assert(offsetof(ccAdvCameraCtrl, flag_54) == 0x54, "ccAdvCameraCtrl.flag_54");
_Static_assert(offsetof(ccAdvCameraCtrl, flag_60) == 0x60, "ccAdvCameraCtrl.flag_60");
_Static_assert(offsetof(ccAdvCameraCtrl, param_ptr) == 0x68, "ccAdvCameraCtrl.param_ptr");
_Static_assert(offsetof(ccAdvCameraCtrl, field_78) == 0x78, "ccAdvCameraCtrl.field_78");
_Static_assert(offsetof(ccAdvCameraCtrl, field_80) == 0x80, "ccAdvCameraCtrl.field_80");
_Static_assert(offsetof(ccAdvCameraCtrl, camera_pos_84) == 0x84, "ccAdvCameraCtrl.camera_pos_84");
_Static_assert(offsetof(ccAdvCameraCtrl, field_8c) == 0x8C, "ccAdvCameraCtrl.field_8c");
_Static_assert(offsetof(ccAdvCameraCtrl, field_90) == 0x90, "ccAdvCameraCtrl.field_90");
_Static_assert(offsetof(ccAdvCameraCtrl, field_98) == 0x98, "ccAdvCameraCtrl.field_98");
_Static_assert(offsetof(ccAdvCameraCtrl, field_9c) == 0x9C, "ccAdvCameraCtrl.field_9c");
_Static_assert(offsetof(ccAdvCameraCtrl, field_a4) == 0xA4, "ccAdvCameraCtrl.field_a4");
_Static_assert(offsetof(ccAdvCameraCtrl, field_d8) == 0xD8, "ccAdvCameraCtrl.field_d8");
_Static_assert(offsetof(ccAdvCameraCtrl, param4_e0) == 0xE0, "ccAdvCameraCtrl.param4_e0");
_Static_assert(offsetof(ccAdvCameraCtrl, param4_e4) == 0xE4, "ccAdvCameraCtrl.param4_e4");
_Static_assert(offsetof(ccAdvCameraCtrl, zero_ec) == 0xEC, "ccAdvCameraCtrl.zero_ec");


/* =========================================================================
 * ccAdvBaseMob — adventure mobile object (large composite)
 * Size: >= 0x39C (from ccAdvMobObject::Create at 0x4FC2C0)
 * Inherits ccAdvBaseCoord; contains ccAdvBaseAnm*, ccStageBaseClump*, nuccAnm*.
 * Note: this is actually ccAdvMobObject which calls ccAdvBaseMob::Create as base ctor.
 * ========================================================================= */
typedef struct __attribute__((packed)) ccAdvBaseMob {
    /* +0x000 */ ccAdvBaseCoord base_coord;     /* inherited, 0x48 bytes */
    /* +0x048 */ uint8_t _gap_48[0x70];         /* gap to 0xB8 */
    /* +0x0B8 */ void *stage_clump;             /* ccStageBaseClump* (alloc 0x88) */
    /* +0x0C0 */ void *base_anm;                /* ccAdvBaseAnm* (alloc 0xb0) */
    /* +0x0C8 */ void *nucc_anm;                /* nuccAnm* (alloc 0x1c0) */
    /* +0x0D0 */ void *field_d0;                /* param_2 stored */
    /* +0x0D8 */ void *field_d8;                /* passed to FUN_1404fa764 */
    /* +0x0E0 */ uint8_t _gap_e0[0x270];        /* large gap to 0x350 */
    /* +0x350 */ void *block_allocator;         /* BlockAllocator* (alloc 0xb0) */
    /* +0x358 */ uint8_t _gap_358[0x20];        /* gap to 0x378 */
    /* +0x378 */ void *sub_object;              /* sub-object (alloc 0x40) */
    /* +0x380 */ uint8_t _gap_380[0x08];
    /* +0x388 */ uint32_t param3_388;           /* param_3 */
    /* +0x38C */ uint8_t _pad_38c[0x0C];
    /* +0x398 */ uint32_t flag_398;             /* flag */
} ccAdvBaseMob;

_Static_assert(offsetof(ccAdvBaseMob, base_coord) == 0x000, "ccAdvBaseMob.base_coord");
_Static_assert(offsetof(ccAdvBaseMob, stage_clump) == 0x0B8, "ccAdvBaseMob.stage_clump");
_Static_assert(offsetof(ccAdvBaseMob, base_anm) == 0x0C0, "ccAdvBaseMob.base_anm");
_Static_assert(offsetof(ccAdvBaseMob, nucc_anm) == 0x0C8, "ccAdvBaseMob.nucc_anm");
_Static_assert(offsetof(ccAdvBaseMob, field_d0) == 0x0D0, "ccAdvBaseMob.field_d0");
_Static_assert(offsetof(ccAdvBaseMob, field_d8) == 0x0D8, "ccAdvBaseMob.field_d8");
_Static_assert(offsetof(ccAdvBaseMob, block_allocator) == 0x350, "ccAdvBaseMob.block_allocator");
_Static_assert(offsetof(ccAdvBaseMob, sub_object) == 0x378, "ccAdvBaseMob.sub_object");
_Static_assert(offsetof(ccAdvBaseMob, param3_388) == 0x388, "ccAdvBaseMob.param3_388");
_Static_assert(offsetof(ccAdvBaseMob, flag_398) == 0x398, "ccAdvBaseMob.flag_398");

#endif /* ST4A09_H */