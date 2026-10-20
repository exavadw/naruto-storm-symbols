/* cmn61.h — NARUTO STORM 4 (s4 / NSUNS4_release.exe 1.09) common struct group cmn61
 * Reconstructed from decompiled code. All layouts INFERRED (static analysis only).
 * Sizes proven from allocator calls or ctor zero-init ranges.
 * Build: s4  sha256: 147e52a3e0d7382501a6777e158b37908e0b69d4e902079dc6e62dcae69bc257
 */
#ifndef CMN61_H
#define CMN61_H

#include <stdint.h>
#include <stddef.h>

#pragma pack(push, 1)

/* nuccModelPrimitive — min proven size 0x11C (ctor writes up to +0x118, 4 bytes)
 * No allocator call found; object may be embedded or stack-allocated.
 * Vtable: PTR_FUN_141106740 (ctor 0xA219D0)
 * Secondary vtable: PTR_FUN_141108b68 at offset 0x98
 */
typedef struct __attribute__((packed)) nuccModelPrimitive {
    void     *vtable;              /* 0x00 SIM  PTR_FUN_141106740 */
    uint8_t   pad_08[8];           /* 0x08 */
    uint8_t   pad_10[8];           /* 0x10 */
    void     *field_18;            /* 0x18 UNKNOWN ctor sets 0 */
    void     *field_20;            /* 0x20 UNKNOWN ctor sets 0 */
    uint16_t  field_28;            /* 0x28 UNKNOWN ctor sets 0 */
    uint32_t  field_2A;            /* 0x2A UNKNOWN ctor sets 0 */
    uint8_t   pad_2E[2];           /* 0x2E */
    uint32_t  prim_type;           /* 0x30 SIM  Create param_5 */
    uint32_t  prim_subtype;        /* 0x34 SIM  Create param_6 */
    uint32_t  field_38;            /* 0x38 UNKNOWN Create sets 0x20 */
    uint8_t   pad_3C[4];           /* 0x3C */
    uint64_t  field_40;            /* 0x40 UNKNOWN Create sets 0x10000001 */
    uint64_t  field_48;            /* 0x48 UNKNOWN Create sets 0 */
    uint32_t  field_50;            /* 0x50 UNKNOWN Create sets 0 */
    uint8_t   pad_54[44];          /* 0x54 gap to 0x80 */
    void     *primitive_data;      /* 0x80 SIM  Primitive::Create target */
    void     *field_88;            /* 0x88 UNKNOWN ctor sets 0 */
    void     *field_90;            /* 0x90 UNKNOWN ctor sets 0 */
    void     *secondary_vtable;    /* 0x98 SIM  PTR_FUN_141108b68 */
    uint8_t   pad_A0[16];          /* 0xA0 gap to 0xB0 */
    void     *field_B0;            /* 0xB0 UNKNOWN ctor sets 0 */
    uint32_t  field_B8;            /* 0xB8 UNKNOWN ctor sets 0 */
    uint8_t   pad_BC[4];           /* 0xBC */
    uint16_t  field_C0;            /* 0xC0 UNKNOWN Create param_2 */
    uint8_t   pad_C2[2];           /* 0xC2 */
    uint8_t   matrix44[64];        /* 0xC4 SIM  Matrix44 identity init */
    float     field_104;           /* 0x104 UNKNOWN 0.75f */
    float     field_108;           /* 0x108 UNKNOWN 1.0f */
    uint8_t   pad_10C[4];          /* 0x10C */
    uint32_t  field_110;           /* 0x110 UNKNOWN Create sets 1 */
    uint8_t   field_114;           /* 0x114 UNKNOWN ctor sets 0 */
    uint8_t   pad_115[3];          /* 0x115 */
    uint32_t  field_118;           /* 0x118 UNKNOWN ctor sets -1 */
} nuccModelPrimitive;

_Static_assert(sizeof(nuccModelPrimitive) == 0x11C, "nuccModelPrimitive size");
_Static_assert(offsetof(nuccModelPrimitive, vtable) == 0x00, "nuccModelPrimitive.vtable");
_Static_assert(offsetof(nuccModelPrimitive, field_18) == 0x18, "nuccModelPrimitive.field_18");
_Static_assert(offsetof(nuccModelPrimitive, field_20) == 0x20, "nuccModelPrimitive.field_20");
_Static_assert(offsetof(nuccModelPrimitive, field_28) == 0x28, "nuccModelPrimitive.field_28");
_Static_assert(offsetof(nuccModelPrimitive, field_2A) == 0x2A, "nuccModelPrimitive.field_2A");
_Static_assert(offsetof(nuccModelPrimitive, prim_type) == 0x30, "nuccModelPrimitive.prim_type");
_Static_assert(offsetof(nuccModelPrimitive, prim_subtype) == 0x34, "nuccModelPrimitive.prim_subtype");
_Static_assert(offsetof(nuccModelPrimitive, field_38) == 0x38, "nuccModelPrimitive.field_38");
_Static_assert(offsetof(nuccModelPrimitive, field_40) == 0x40, "nuccModelPrimitive.field_40");
_Static_assert(offsetof(nuccModelPrimitive, field_48) == 0x48, "nuccModelPrimitive.field_48");
_Static_assert(offsetof(nuccModelPrimitive, field_50) == 0x50, "nuccModelPrimitive.field_50");
_Static_assert(offsetof(nuccModelPrimitive, primitive_data) == 0x80, "nuccModelPrimitive.primitive_data");
_Static_assert(offsetof(nuccModelPrimitive, field_88) == 0x88, "nuccModelPrimitive.field_88");
_Static_assert(offsetof(nuccModelPrimitive, field_90) == 0x90, "nuccModelPrimitive.field_90");
_Static_assert(offsetof(nuccModelPrimitive, secondary_vtable) == 0x98, "nuccModelPrimitive.secondary_vtable");
_Static_assert(offsetof(nuccModelPrimitive, field_B0) == 0xB0, "nuccModelPrimitive.field_B0");
_Static_assert(offsetof(nuccModelPrimitive, field_B8) == 0xB8, "nuccModelPrimitive.field_B8");
_Static_assert(offsetof(nuccModelPrimitive, field_C0) == 0xC0, "nuccModelPrimitive.field_C0");
_Static_assert(offsetof(nuccModelPrimitive, matrix44) == 0xC4, "nuccModelPrimitive.matrix44");
_Static_assert(offsetof(nuccModelPrimitive, field_104) == 0x104, "nuccModelPrimitive.field_104");
_Static_assert(offsetof(nuccModelPrimitive, field_108) == 0x108, "nuccModelPrimitive.field_108");
_Static_assert(offsetof(nuccModelPrimitive, field_110) == 0x110, "nuccModelPrimitive.field_110");
_Static_assert(offsetof(nuccModelPrimitive, field_114) == 0x114, "nuccModelPrimitive.field_114");
_Static_assert(offsetof(nuccModelPrimitive, field_118) == 0x118, "nuccModelPrimitive.field_118");

/* nuccModelPrimitiveBatch — size 0x170 proven by CreateInstance allocator FUN_140a017f0(0x170,...)
 * Vtable: PTR_FUN_14110aaa8 (ctor 0xA4EEB0)
 * Secondary vtable: PTR_LAB_14110ab10 at offset 0x30
 */
typedef struct __attribute__((packed)) nuccModelPrimitiveBatch {
    void     *vtable;              /* 0x00 SIM  PTR_FUN_14110aaa8 */
    uint8_t   pad_08[8];           /* 0x08 */
    uint8_t   pad_10[8];           /* 0x10 */
    void     *field_18;            /* 0x18 UNKNOWN ctor sets 0 */
    void     *field_20;            /* 0x20 UNKNOWN ctor sets 0 */
    uint16_t  field_28;            /* 0x28 UNKNOWN ctor sets 0 */
    uint32_t  field_2A;            /* 0x2A UNKNOWN ctor sets 0 */
    uint8_t   pad_2E[2];           /* 0x2E */
    void     *secondary_vtable;    /* 0x30 SIM  PTR_LAB_14110ab10 */
    void     *field_38;            /* 0x38 UNKNOWN ctor sets 0 */
    void     *field_40;            /* 0x40 UNKNOWN ctor sets 0 */
    void     *instance_list_ptr;   /* 0x48 PRES ctor sets 0; CreateInstance reads */
    uint32_t  field_50;            /* 0x50 UNKNOWN ctor sets 0 */
    float     field_54;            /* 0x54 UNKNOWN ctor sets 1.0f */
    uint16_t  field_58;            /* 0x58 UNKNOWN ctor sets 0 */
    uint8_t   pad_5A[6];           /* 0x5A */
    void     *field_60;            /* 0x60 UNKNOWN ctor sets 0 */
    void     *resource_ptr;        /* 0x68 PRES dtor frees via FreeCore */
    void     *field_70;            /* 0x70 UNKNOWN ctor sets 0 */
    uint32_t  field_78;            /* 0x78 UNKNOWN ctor sets 0 */
    uint8_t   field_7C;            /* 0x7C UNKNOWN ctor sets 0 */
    uint8_t   pad_7D[3];           /* 0x7D */
    uint32_t  field_80;            /* 0x80 UNKNOWN ctor sets 0 */
    uint8_t   pad_84[4];           /* 0x84 */
    void     *resource_ptr2;       /* 0x88 PRES dtor frees via FreealignCore */
    void     *resource_ptr3;       /* 0x90 PRES dtor frees via FreeCore */
    void     *resource_ptr4;       /* 0x98 PRES dtor frees via FreealignCore */
    uint32_t  field_A0;            /* 0xA0 UNKNOWN ctor sets 0 */
    uint8_t   pad_A4[4];           /* 0xA4 */
    void     *resource_ptr5;       /* 0xA8 PRES dtor frees via FreeCore */
    uint8_t   pad_B0[160];         /* 0xB0 gap to 0x150 */
    void     *field_150;           /* 0x150 UNKNOWN ctor sets 0 */
    void     *field_158;           /* 0x158 UNKNOWN ctor sets 0 */
    void     *field_160;           /* 0x160 UNKNOWN ctor sets 0 */
    uint8_t   pad_168[8];          /* 0x168 trailing pad to 0x170 */
} nuccModelPrimitiveBatch;

_Static_assert(sizeof(nuccModelPrimitiveBatch) == 0x170, "nuccModelPrimitiveBatch size");
_Static_assert(offsetof(nuccModelPrimitiveBatch, vtable) == 0x00, "nuccModelPrimitiveBatch.vtable");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_18) == 0x18, "nuccModelPrimitiveBatch.field_18");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_20) == 0x20, "nuccModelPrimitiveBatch.field_20");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_28) == 0x28, "nuccModelPrimitiveBatch.field_28");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_2A) == 0x2A, "nuccModelPrimitiveBatch.field_2A");
_Static_assert(offsetof(nuccModelPrimitiveBatch, secondary_vtable) == 0x30, "nuccModelPrimitiveBatch.secondary_vtable");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_38) == 0x38, "nuccModelPrimitiveBatch.field_38");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_40) == 0x40, "nuccModelPrimitiveBatch.field_40");
_Static_assert(offsetof(nuccModelPrimitiveBatch, instance_list_ptr) == 0x48, "nuccModelPrimitiveBatch.instance_list_ptr");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_50) == 0x50, "nuccModelPrimitiveBatch.field_50");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_54) == 0x54, "nuccModelPrimitiveBatch.field_54");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_58) == 0x58, "nuccModelPrimitiveBatch.field_58");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_60) == 0x60, "nuccModelPrimitiveBatch.field_60");
_Static_assert(offsetof(nuccModelPrimitiveBatch, resource_ptr) == 0x68, "nuccModelPrimitiveBatch.resource_ptr");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_70) == 0x70, "nuccModelPrimitiveBatch.field_70");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_78) == 0x78, "nuccModelPrimitiveBatch.field_78");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_7C) == 0x7C, "nuccModelPrimitiveBatch.field_7C");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_80) == 0x80, "nuccModelPrimitiveBatch.field_80");
_Static_assert(offsetof(nuccModelPrimitiveBatch, resource_ptr2) == 0x88, "nuccModelPrimitiveBatch.resource_ptr2");
_Static_assert(offsetof(nuccModelPrimitiveBatch, resource_ptr3) == 0x90, "nuccModelPrimitiveBatch.resource_ptr3");
_Static_assert(offsetof(nuccModelPrimitiveBatch, resource_ptr4) == 0x98, "nuccModelPrimitiveBatch.resource_ptr4");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_A0) == 0xA0, "nuccModelPrimitiveBatch.field_A0");
_Static_assert(offsetof(nuccModelPrimitiveBatch, resource_ptr5) == 0xA8, "nuccModelPrimitiveBatch.resource_ptr5");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_150) == 0x150, "nuccModelPrimitiveBatch.field_150");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_158) == 0x158, "nuccModelPrimitiveBatch.field_158");
_Static_assert(offsetof(nuccModelPrimitiveBatch, field_160) == 0x160, "nuccModelPrimitiveBatch.field_160");

/* nuccMorphModel — size 0x50 proven by CreateInstance allocator FUN_140a017f0(0x50,...)
 * Vtable: PTR_FUN_141112e00 (CreateInstance 0xAA62D0)
 * Secondary ptrs: PTR_LAB_141112e20 at 0x28, PTR_LAB_141112e30 at 0x30
 */
typedef struct __attribute__((packed)) nuccMorphModel {
    void     *vtable;              /* 0x00 SIM  PTR_FUN_141112e00 */
    uint8_t   pad_08[8];           /* 0x08 */
    uint8_t   pad_10[8];           /* 0x10 */
    void     *field_18;            /* 0x18 UNKNOWN CreateInstance sets 0 */
    void     *field_20;            /* 0x20 SIM  CreateInstance sets 0 */
    void     *secondary_ptr1;      /* 0x28 SIM  PTR_LAB_141112e20 */
    void     *secondary_ptr2;      /* 0x30 SIM  PTR_LAB_141112e30 */
    uint32_t  field_38;            /* 0x38 UNKNOWN CreateInstance sets 0 */
    uint8_t   pad_3C[4];           /* 0x3C */
    void     *field_40;            /* 0x40 PRES dtor checks + FreeCore */
    void     *field_48;            /* 0x48 PRES dtor checks + FreeCore */
} nuccMorphModel;

_Static_assert(sizeof(nuccMorphModel) == 0x50, "nuccMorphModel size");
_Static_assert(offsetof(nuccMorphModel, vtable) == 0x00, "nuccMorphModel.vtable");
_Static_assert(offsetof(nuccMorphModel, field_18) == 0x18, "nuccMorphModel.field_18");
_Static_assert(offsetof(nuccMorphModel, field_20) == 0x20, "nuccMorphModel.field_20");
_Static_assert(offsetof(nuccMorphModel, secondary_ptr1) == 0x28, "nuccMorphModel.secondary_ptr1");
_Static_assert(offsetof(nuccMorphModel, secondary_ptr2) == 0x30, "nuccMorphModel.secondary_ptr2");
_Static_assert(offsetof(nuccMorphModel, field_38) == 0x38, "nuccMorphModel.field_38");
_Static_assert(offsetof(nuccMorphModel, field_40) == 0x40, "nuccMorphModel.field_40");
_Static_assert(offsetof(nuccMorphModel, field_48) == 0x48, "nuccMorphModel.field_48");

/* nuccNudInfo — size 0x40 inferred from SetInfo max write param_1[7] at offset 0x38 + 8 = 0x40
 * No vtable found (dtor does not set one; may be plain struct or vtable at offset 0 overwritten).
 * No allocator call found.
 */
typedef struct __attribute__((packed)) nuccNudInfo {
    void     *alloc_ptr;           /* 0x00 PRES dtor checks + FreeCore */
    uint8_t   pad_08[8];           /* 0x08 */
    uint8_t   pad_10[8];           /* 0x10 */
    void     *nud_objects_ptr;     /* 0x18 PRES SetInfo writes nud+0x30 */
    void     *field_20;            /* 0x20 PRES SetInfo writes */
    void     *field_28;            /* 0x28 PRES SetInfo writes */
    void     *field_30;            /* 0x30 PRES SetInfo writes */
    void     *field_38;            /* 0x38 PRES SetInfo writes */
} nuccNudInfo;

_Static_assert(sizeof(nuccNudInfo) == 0x40, "nuccNudInfo size");
_Static_assert(offsetof(nuccNudInfo, alloc_ptr) == 0x00, "nuccNudInfo.alloc_ptr");
_Static_assert(offsetof(nuccNudInfo, nud_objects_ptr) == 0x18, "nuccNudInfo.nud_objects_ptr");
_Static_assert(offsetof(nuccNudInfo, field_20) == 0x20, "nuccNudInfo.field_20");
_Static_assert(offsetof(nuccNudInfo, field_28) == 0x28, "nuccNudInfo.field_28");
_Static_assert(offsetof(nuccNudInfo, field_30) == 0x30, "nuccNudInfo.field_30");
_Static_assert(offsetof(nuccNudInfo, field_38) == 0x38, "nuccNudInfo.field_38");

#pragma pack(pop)

#endif /* CMN61_H */
