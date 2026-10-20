/* cmn61.h — struct group cmn61 for build s3 (NSUNS3.exe, Storm 3 Full Burst HD)
 * INFERRED layout from static analysis. Not CONFIRMED.
 * All offsets/sizes from PC x64 decompilation (image base 0x140000000).
 * Sizes proven from allocator calls (LoadTh size args) or ctor zero-init range.
 */
#ifndef CMN61_S3_H
#define CMN61_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#if __STDC_VERSION__ >= 201112L
#define CMN61_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#else
#define CMN61_STATIC_ASSERT(cond, msg) typedef char _cmn61_sa_##__LINE__[(cond) ? 1 : -1]
#endif

#pragma pack(push, 1)

/* =========================================================================
 * nuccModelPrimitive — size 0x120
 * Size evidence: memset(param_1+0x30, 0, 0x50) in Create covers +0x30..+0x7F;
 *   last field at +0x118 (uint32) + pad = 0x120; matches s2 size.
 * vtable: PTR_FUN_1409def38 (ctor 0x6A3100)
 * ========================================================================= */
typedef struct nuccModelPrimitive {
/* +0x00 */ void *vtable;
/* +0x08 */ uint8_t _pad_08[0x10];
/* +0x18 */ void *field_18;
/* +0x20 */ void *field_20;
/* +0x28 */ uint16_t field_28;
/* +0x2A */ uint32_t field_2A;
/* +0x2E */ uint8_t _pad_2E[0x02];
/* +0x30 */ uint32_t prim_type;
/* +0x34 */ uint32_t prim_subtype;
/* +0x38 */ uint32_t field_38;
/* +0x3C */ uint8_t _pad_3C[0x04];
/* +0x40 */ uint64_t field_40;
/* +0x48 */ uint64_t field_48;
/* +0x50 */ uint32_t field_50;
/* +0x54 */ uint8_t _pad_54[0x2C];
/* +0x80 */ void *primitive_data;
/* +0x88 */ void *field_88;
/* +0x90 */ void *field_90;
/* +0x98 */ void *block_allocator;
/* +0xA0 */ uint8_t _pad_A0[0x10];
/* +0xB0 */ void *field_B0;
/* +0xB8 */ uint32_t field_B8;
/* +0xBC */ uint8_t _pad_BC[0x04];
/* +0xC0 */ uint16_t field_C0;
/* +0xC2 */ uint8_t _pad_C2[0x02];
/* +0xC4 */ uint8_t matrix44[0x40];
/* +0x104 */ float field_104;
/* +0x108 */ float field_108;
/* +0x10C */ uint8_t _pad_10C[0x04];
/* +0x110 */ uint32_t field_110;
/* +0x114 */ uint8_t field_114;
/* +0x115 */ uint8_t _pad_115[0x03];
/* +0x118 */ uint32_t field_118;
/* +0x11C */ uint8_t _pad_11C[0x04];
} nuccModelPrimitive;

CMN61_STATIC_ASSERT(sizeof(nuccModelPrimitive) == 0x120, "nuccModelPrimitive size");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, vtable) == 0x00, "vtable");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_18) == 0x18, "field_18");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_20) == 0x20, "field_20");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_28) == 0x28, "field_28");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_2A) == 0x2A, "field_2A");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, prim_type) == 0x30, "prim_type");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, prim_subtype) == 0x34, "prim_subtype");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_38) == 0x38, "field_38");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_40) == 0x40, "field_40");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_48) == 0x48, "field_48");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_50) == 0x50, "field_50");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, primitive_data) == 0x80, "primitive_data");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_88) == 0x88, "field_88");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_90) == 0x90, "field_90");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, block_allocator) == 0x98, "block_allocator");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_B0) == 0xB0, "field_B0");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_B8) == 0xB8, "field_B8");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_C0) == 0xC0, "field_C0");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, matrix44) == 0xC4, "matrix44");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_104) == 0x104, "field_104");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_108) == 0x108, "field_108");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_110) == 0x110, "field_110");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_114) == 0x114, "field_114");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitive, field_118) == 0x118, "field_118");

/* =========================================================================
 * nuccModelPrimitiveBatch — size 0x170
 * Size evidence: LoadTh(0x170,...) in CreateInstance 0x6C67D0
 * vtable: PTR_FUN_1409e21a8 (ctor 0x6C64A0)
 * Secondary ptr: PTR_LAB_1409e2210 at +0x30
 * ========================================================================= */
typedef struct nuccModelPrimitiveBatch {
/* +0x00 */ void *vtable;
/* +0x08 */ uint8_t _pad_08[0x10];
/* +0x18 */ void *field_18;
/* +0x20 */ void *field_20;
/* +0x28 */ uint16_t field_28;
/* +0x2A */ uint32_t field_2A;
/* +0x2E */ uint8_t _pad_2E[0x02];
/* +0x30 */ void *secondary_vtable;
/* +0x38 */ void *field_38;
/* +0x40 */ void *field_40;
/* +0x48 */ void *instance_list_ptr;
/* +0x50 */ uint32_t field_50;
/* +0x54 */ float field_54;
/* +0x58 */ uint16_t field_58;
/* +0x5A */ uint8_t _pad_5A[0x06];
/* +0x60 */ void *field_60;
/* +0x68 */ void *resource_ptr;
/* +0x70 */ void *field_70;
/* +0x78 */ uint32_t field_78;
/* +0x7C */ uint8_t field_7C;
/* +0x7D */ uint8_t _pad_7D[0x03];
/* +0x80 */ uint32_t field_80;
/* +0x84 */ uint8_t _pad_84[0x04];
/* +0x88 */ void *resource_ptr2;
/* +0x90 */ void *resource_ptr3;
/* +0x98 */ void *resource_ptr4;
/* +0xA0 */ uint8_t _pad_A0[0x08];
/* +0xA8 */ void *resource_ptr5;
/* +0xB0 */ uint8_t _pad_B0[0xA0];
/* +0x150 */ void *field_150;
/* +0x158 */ void *field_158;
/* +0x160 */ void *field_160;
/* +0x168 */ uint8_t _pad_168[0x08];
} nuccModelPrimitiveBatch;

CMN61_STATIC_ASSERT(sizeof(nuccModelPrimitiveBatch) == 0x170, "nuccModelPrimitiveBatch size");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, vtable) == 0x00, "vtable");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_18) == 0x18, "field_18");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_20) == 0x20, "field_20");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_28) == 0x28, "field_28");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_2A) == 0x2A, "field_2A");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, secondary_vtable) == 0x30, "secondary_vtable");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_38) == 0x38, "field_38");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_40) == 0x40, "field_40");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, instance_list_ptr) == 0x48, "instance_list_ptr");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_50) == 0x50, "field_50");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_54) == 0x54, "field_54");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_58) == 0x58, "field_58");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_60) == 0x60, "field_60");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, resource_ptr) == 0x68, "resource_ptr");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_70) == 0x70, "field_70");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_78) == 0x78, "field_78");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_7C) == 0x7C, "field_7C");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_80) == 0x80, "field_80");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, resource_ptr2) == 0x88, "resource_ptr2");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, resource_ptr3) == 0x90, "resource_ptr3");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, resource_ptr4) == 0x98, "resource_ptr4");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, resource_ptr5) == 0xA8, "resource_ptr5");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_150) == 0x150, "field_150");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_158) == 0x158, "field_158");
CMN61_STATIC_ASSERT(offsetof(nuccModelPrimitiveBatch, field_160) == 0x160, "field_160");

/* =========================================================================
 * nuccMorphModel — size 0x50
 * Size evidence: LoadTh(0x50,...) in CreateInstance 0x72CCF0
 * vtable: PTR_FUN_1409ea060 (CreateInstance sets *puVar1)
 * Secondary ptrs: PTR_LAB_1409ea080 at +0x28, PTR_LAB_1409ea090 at +0x30
 * ========================================================================= */
typedef struct nuccMorphModel {
/* +0x00 */ void *vtable;
/* +0x08 */ uint8_t _pad_08[0x18];
/* +0x20 */ void *field_20;
/* +0x28 */ void *secondary_ptr1;
/* +0x30 */ void *secondary_ptr2;
/* +0x38 */ uint32_t field_38;
/* +0x3C */ uint8_t _pad_3C[0x04];
/* +0x40 */ void *field_40;
/* +0x48 */ void *field_48;
} nuccMorphModel;

CMN61_STATIC_ASSERT(sizeof(nuccMorphModel) == 0x50, "nuccMorphModel size");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, vtable) == 0x00, "vtable");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_20) == 0x20, "field_20");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, secondary_ptr1) == 0x28, "secondary_ptr1");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, secondary_ptr2) == 0x30, "secondary_ptr2");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_38) == 0x38, "field_38");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_40) == 0x40, "field_40");
CMN61_STATIC_ASSERT(offsetof(nuccMorphModel, field_48) == 0x48, "field_48");

/* =========================================================================
 * nuccNudInfo — size 0x40
 * Size evidence: ctor zeroes param_1[0..6] (7 qwords = 0x38);
 *   SetInfo writes param_1[3..7] extending to 8 qwords = 0x40.
 * No vtable (plain data struct).
 * ========================================================================= */
typedef struct nuccNudInfo {
/* +0x00 */ void *field_00;
/* +0x08 */ uint8_t _pad_08[0x10];
/* +0x18 */ void *field_18;
/* +0x20 */ void *field_20;
/* +0x28 */ void *field_28;
/* +0x30 */ void *field_30;
/* +0x38 */ void *field_38;
} nuccNudInfo;

CMN61_STATIC_ASSERT(sizeof(nuccNudInfo) == 0x40, "nuccNudInfo size");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_00) == 0x00, "field_00");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_18) == 0x18, "field_18");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_20) == 0x20, "field_20");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_28) == 0x28, "field_28");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_30) == 0x30, "field_30");
CMN61_STATIC_ASSERT(offsetof(nuccNudInfo, field_38) == 0x38, "field_38");

#pragma pack(pop)

#endif /* CMN61_S3_H */