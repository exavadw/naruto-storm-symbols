/* rbCollision s3 — NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, image base 0x140000000)
 * Rollback-netcode struct group: ccCollision hierarchy + ccSkillCollision
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Sizes proven from ctor/allocator/reserve where noted; otherwise ">= last field".
 * Field offsets derived from s3 state_surface; names carried from s2 where layout matches.
 */
#ifndef RBCOLLISION_S3_H
#define RBCOLLISION_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---------- common embedded types ---------- */

/* Nucc::Vector3 — 12 bytes, no padding in packed context */
typedef struct __attribute__((packed)) {
    float x;
    float y;
    float z;
} Nucc_Vector3;
static_assert(sizeof(Nucc_Vector3) == 12, "Nucc_Vector3 size");

/* Nucc::Memory::BlockAllocator — observed as 0x18 bytes (vtable ptr + id + bookkeeping)
 * Proven by ccBulletManager slot spacing in s2; same pattern in s3. */
typedef struct __attribute__((packed)) {
    uint64_t vtable_or_func;   /* 0x0 */
    uint32_t block_id;         /* 0x8 */
    uint8_t  _pad_0C[4];       /* 0xC: alignment padding */
    uint64_t internal_ptr;     /* 0x10: allocator internal state */
} Nucc_BlockAllocator;
static_assert(sizeof(Nucc_BlockAllocator) == 0x18, "Nucc_BlockAllocator size");

/* std::vector<T*> — 24 bytes (begin, end, capacity) */
typedef struct __attribute__((packed)) {
    uint64_t begin;
    uint64_t end;
    uint64_t capacity;
} StdVectorPtr;
static_assert(sizeof(StdVectorPtr) == 0x18, "StdVectorPtr size");

/* math::float3x3 — 36 bytes (9 floats), used by Component */
typedef struct __attribute__((packed)) {
    float m[9];
} MathFloat3x3;
static_assert(sizeof(MathFloat3x3) == 36, "MathFloat3x3 size");

/* ================================================================
 * ccCollision::PolygonTable
 * s3 state_surface: 9 fields (offsets 0x14, 0x2C, 0x34, 0x58, 0x60, 0x68, 0x80, 0x88, 0x90)
 * Layout matches s2 exactly. Size >= 0x98 (last field at 0x90 + 8).
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint64_t      vtable;              /* vtable ptr */
    /* 0x08 */ uint8_t       _pad_08[0xC];        /* gap to 0x14 */
    /* 0x14 */ Nucc_Vector3  vec_a;               /* ctor: Vector3(param_1+0x14) */
    /* 0x20 */ uint8_t       _pad_20[0xC];        /* gap to 0x2C */
    /* 0x2C */ uint64_t      field_2C;            /* = 0 */
    /* 0x34 */ uint32_t      field_34;            /* = 0 */
    /* 0x38 */ uint8_t       _pad_38[0x20];       /* gap to 0x58 */
    /* 0x58 */ uint64_t      field_58;            /* param_1[0xb] = 0 */
    /* 0x60 */ uint64_t      field_60;            /* param_1[0xc] = 0 */
    /* 0x68 */ Nucc_BlockAllocator allocator;     /* BlockAllocator init at param_1+0xd */
    /* 0x80 */ uint32_t      field_80;            /* = 0xffffffff */
    /* 0x84 */ uint8_t       _pad_84[4];          /* explicit padding */
    /* 0x88 */ uint64_t      field_88;            /* param_1[0x11] = 0 */
    /* 0x90 */ uint64_t      field_90;            /* param_1[0x12] = 0 */
} ccCollision_PolygonTable;
static_assert(offsetof(ccCollision_PolygonTable, vtable)     == 0x00, "PolygonTable.vtable");
static_assert(offsetof(ccCollision_PolygonTable, vec_a)      == 0x14, "PolygonTable.vec_a");
static_assert(offsetof(ccCollision_PolygonTable, field_2C)   == 0x2C, "PolygonTable.field_2C");
static_assert(offsetof(ccCollision_PolygonTable, field_34)   == 0x34, "PolygonTable.field_34");
static_assert(offsetof(ccCollision_PolygonTable, field_58)   == 0x58, "PolygonTable.field_58");
static_assert(offsetof(ccCollision_PolygonTable, field_60)   == 0x60, "PolygonTable.field_60");
static_assert(offsetof(ccCollision_PolygonTable, allocator)  == 0x68, "PolygonTable.allocator");
static_assert(offsetof(ccCollision_PolygonTable, field_80)   == 0x80, "PolygonTable.field_80");
static_assert(offsetof(ccCollision_PolygonTable, field_88)   == 0x88, "PolygonTable.field_88");
static_assert(offsetof(ccCollision_PolygonTable, field_90)   == 0x90, "PolygonTable.field_90");
/* Size: >= 0x98 (no operator new found; last written field ends at 0x98) */

/* ================================================================
 * ccCollision::Manager
 * s3 state_surface: 7 fields (offsets 0x68, 0x80, 0x98, 0xA0, 0xA8, 0xB0, 0xB8)
 * Layout matches s2 exactly. Size >= 0xD0 (BlockAllocator at 0xB8 + 0x18).
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint64_t      vtable;              /* virtual dispatch at +0x10 */
    /* 0x08 */ uint8_t       _pad_08[0x60];       /* gap: offsets 0x08-0x67 not accessed */
    /* 0x68 */ uint64_t      field_68;            /* self-ref iterator check */
    /* 0x70 */ uint8_t       _pad_70[0x10];       /* gap */
    /* 0x80 */ uint64_t      vfunc_ptr_80;        /* (**(code **)(*param_1 + 0x10))(param_1) */
    /* 0x88 */ uint8_t       _pad_88[0x10];       /* gap */
    /* 0x98 */ uint64_t      heap_obj_98;         /* sub-object pointer */
    /* 0xA0 */ uint64_t      vec_begin_A0;        /* vector begin */
    /* 0xA8 */ uint64_t      vec_end_A8;          /* vector end */
    /* 0xB0 */ uint64_t      vec_cap_B0;          /* vector capacity */
    /* 0xB8 */ Nucc_BlockAllocator allocator;     /* BlockAllocator */
} ccCollision_Manager;
static_assert(offsetof(ccCollision_Manager, vtable)       == 0x00, "Manager.vtable");
static_assert(offsetof(ccCollision_Manager, field_68)     == 0x68, "Manager.field_68");
static_assert(offsetof(ccCollision_Manager, vfunc_ptr_80) == 0x80, "Manager.vfunc_ptr_80");
static_assert(offsetof(ccCollision_Manager, heap_obj_98)  == 0x98, "Manager.heap_obj_98");
static_assert(offsetof(ccCollision_Manager, vec_begin_A0) == 0xA0, "Manager.vec_begin_A0");
static_assert(offsetof(ccCollision_Manager, vec_end_A8)   == 0xA8, "Manager.vec_end_A8");
static_assert(offsetof(ccCollision_Manager, vec_cap_B0)   == 0xB0, "Manager.vec_cap_B0");
static_assert(offsetof(ccCollision_Manager, allocator)    == 0xB8, "Manager.allocator");
/* Size: >= 0xD0 (0xB8 + sizeof(Nucc_BlockAllocator)=0x18) */

/* ================================================================
 * ccCollision::Component
 * s3 state_surface: 17 fields (offsets 0x34, 0x74, 0x80, 0xC0, 0xC8, 0xCC, 0xD4,
 *   0xDC, 0x100, 0x114, 0x140, 0x148, 0x154, 0x158, 0x15C, 0x180, 0x1C0)
 * Layout matches s2 with additional field at 0xDC and 0x15C.
 * Size >= 0x1C8 (last access at 0x1C0).
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint8_t       _pad_000[0x34];    /* base / vtable / unknown */
    /* 0x034 */ uint8_t       subobj_34[0x40];   /* embedded sub-object */
    /* 0x074 */ uint8_t       subobj_74[0x0C];   /* embedded sub-object (smaller than s2's 0x4C) */
    /* 0x080 */ uint8_t       _pad_080[0x40];    /* gap to 0xC0 */
    /* 0x0C0 */ uint64_t      field_C0;           /* rw high */
    /* 0x0C8 */ uint32_t      field_C8;           /* rw high, checked != -1 */
    /* 0x0CC */ uint32_t      field_CC;           /* w high */
    /* 0x0D0 */ uint8_t       _pad_0D0[4];        /* padding */
    /* 0x0D4 */ uint32_t      field_D4;           /* w high */
    /* 0x0D8 */ uint8_t       _pad_0D8[4];        /* padding */
    /* 0x0DC */ uint32_t      field_DC;           /* w high (new in s3 vs s2) */
    /* 0x0E0 */ uint8_t       _pad_0E0[0x20];     /* gap to 0x100 */
    /* 0x100 */ uint64_t      vtable_100;         /* secondary vtable */
    /* 0x108 */ uint8_t       _pad_108[0xC];      /* gap */
    /* 0x114 */ uint8_t       subobj_114[0x2C];   /* embedded sub-object */
    /* 0x140 */ uint64_t      vtable_140;         /* tertiary vtable */
    /* 0x148 */ uint8_t       subobj_148[0xC];    /* embedded sub-object */
    /* 0x154 */ uint32_t      field_154;          /* w medium */
    /* 0x158 */ uint8_t       subobj_158[0x04];   /* embedded sub-object (smaller than s2's 0x28) */
    /* 0x15C */ uint32_t      field_15C;          /* w high (new in s3 vs s2) */
    /* 0x160 */ uint8_t       _pad_160[0x20];     /* gap to 0x180 */
    /* 0x180 */ uint8_t       _pad_180[0x40];     /* gap; vtable+0x30 dispatch here */
    /* 0x1C0 */ uint8_t       _pad_1C0[8];        /* vtable+0x38 dispatch target */
} ccCollision_Component;
static_assert(offsetof(ccCollision_Component, subobj_34)   == 0x034, "Component.subobj_34");
static_assert(offsetof(ccCollision_Component, subobj_74)   == 0x074, "Component.subobj_74");
static_assert(offsetof(ccCollision_Component, field_C0)    == 0x0C0, "Component.field_C0");
static_assert(offsetof(ccCollision_Component, field_C8)    == 0x0C8, "Component.field_C8");
static_assert(offsetof(ccCollision_Component, field_CC)    == 0x0CC, "Component.field_CC");
static_assert(offsetof(ccCollision_Component, field_D4)    == 0x0D4, "Component.field_D4");
static_assert(offsetof(ccCollision_Component, field_DC)    == 0x0DC, "Component.field_DC");
static_assert(offsetof(ccCollision_Component, vtable_100)  == 0x100, "Component.vtable_100");
static_assert(offsetof(ccCollision_Component, subobj_114)  == 0x114, "Component.subobj_114");
static_assert(offsetof(ccCollision_Component, vtable_140)  == 0x140, "Component.vtable_140");
static_assert(offsetof(ccCollision_Component, subobj_148)  == 0x148, "Component.subobj_148");
static_assert(offsetof(ccCollision_Component, field_154)   == 0x154, "Component.field_154");
static_assert(offsetof(ccCollision_Component, subobj_158)  == 0x158, "Component.subobj_158");
static_assert(offsetof(ccCollision_Component, field_15C)   == 0x15C, "Component.field_15C");
/* Size: >= 0x1C8 (last vtable dispatch at +0x38 from base vtable) */

/* ================================================================
 * ccCollision::ccBulletRigidBodyMesh
 * s3 state_surface: 8 fields (offsets 0x58, 0x60, 0x68, 0x70, 0x80, 0x88, 0x90, 0x98)
 * Layout matches s2 minus field_78 (not surfaced in s3). Size >= 0xA0.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x58];     /* base class ccBulletRigidBodyBase */
    /* 0x58 */ uint64_t      mesh_data_58;      /* rw high */
    /* 0x60 */ uint64_t      mesh_data_60;      /* rw high */
    /* 0x68 */ uint64_t      mesh_data_68;      /* rw high */
    /* 0x70 */ uint64_t      mesh_data_70;      /* rw high */
    /* 0x78 */ uint8_t       _pad_78[8];        /* gap (field_78 not surfaced in s3) */
    /* 0x80 */ uint64_t      user_ptr_80;       /* rw low */
    /* 0x88 */ uint64_t      mesh_data_88;      /* rw high */
    /* 0x90 */ uint64_t      mesh_data_90;      /* rw medium */
    /* 0x98 */ uint64_t      mesh_data_98;      /* rw medium */
} ccCollision_ccBulletRigidBodyMesh;
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_58) == 0x58, "ccBulletRigidBodyMesh.mesh_data_58");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_60) == 0x60, "ccBulletRigidBodyMesh.mesh_data_60");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_68) == 0x68, "ccBulletRigidBodyMesh.mesh_data_68");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_70) == 0x70, "ccBulletRigidBodyMesh.mesh_data_70");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, user_ptr_80)  == 0x80, "ccBulletRigidBodyMesh.user_ptr_80");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_88) == 0x88, "ccBulletRigidBodyMesh.mesh_data_88");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_90) == 0x90, "ccBulletRigidBodyMesh.mesh_data_90");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_98) == 0x98, "ccBulletRigidBodyMesh.mesh_data_98");
/* Size: >= 0xA0 */

/* ================================================================
 * ccCollision::ccBulletManager
 * s3 state_surface: 44 fields — matches s2 slot pattern exactly.
 * Offsets confirmed: gravity/bounds at 0x4C-0x60, collision_objects at 0x68,
 * 8 repeating (vector + allocator) slots from 0x80 through 0x230.
 * Size >= 0x238 (last field at 0x230 + 8).
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint64_t      vtable;                /* vtable ptr */
    /* 0x008 */ uint8_t       _pad_008[0x10];        /* gap */
    /* 0x018 */ uint32_t      field_18;              /* = 0 */
    /* 0x01C */ uint8_t       _pad_01C[4];           /* padding */
    /* 0x020 */ uint64_t      field_20;              /* = 0 */
    /* 0x028 */ uint64_t      field_28;              /* = 0 */
    /* 0x030 */ uint64_t      field_30;              /* = 0 */
    /* 0x038 */ uint64_t      field_38;              /* = 0 */
    /* 0x040 */ uint64_t      field_40;              /* = 0 */
    /* 0x048 */ uint8_t       _pad_048[4];           /* gap (gravity fields start at 0x4C in s3) */
    /* 0x04C */ float         gravity_neg;           /* -30000.0f */
    /* 0x050 */ uint8_t       _pad_050[4];           /* gap */
    /* 0x054 */ float         gravity_pos;           /* 30000.0f */
    /* 0x058 */ float         bound_max;             /* 30000.0f */
    /* 0x05C */ float         bound_max_5C;          /* 30000.0f */
    /* 0x060 */ uint32_t      field_60;              /* = 0 */
    /* 0x064 */ uint8_t       _pad_064[4];           /* padding */
    /* 0x068 */ StdVectorPtr  collision_objects;     /* reserve(0x200) */
    /* 0x080 */ Nucc_BlockAllocator alloc_coll;      /* BlockAllocator */
    /* 0x098 */ uint8_t       _pad_098[8];           /* gap (s3 surface shows 0xA0 next) */
    /* 0x0A0 */ uint64_t      field_A0;              /* w medium (new in s3?) */
    /* 0x0A8 */ uint64_t      field_A8;              /* rw medium */
    /* 0x0B0 */ Nucc_BlockAllocator alloc_rb1;       /* BlockAllocator */
    /* 0x0C8 */ uint8_t       _pad_0C8[8];           /* gap */
    /* 0x0D0 */ uint64_t      field_D0;              /* w medium */
    /* 0x0D8 */ uint64_t      field_D8;              /* rw medium */
    /* 0x0E0 */ Nucc_BlockAllocator alloc_rb2;       /* BlockAllocator */
    /* 0x0F8 */ uint8_t       contact_callback[0x10];/* ccBulletRigidbodyContactResultCallback */
    /* 0x108 */ uint64_t      field_108;             /* w medium */
    /* 0x110 */ Nucc_BlockAllocator alloc_slot3;     /* BlockAllocator */
    /* 0x128 */ uint8_t       _pad_128[0x18];        /* gap to next slot */
    /* 0x140 */ StdVectorPtr  slot4_vec;             /* vector */
    /* 0x158 */ Nucc_BlockAllocator alloc_slot4;     /* BlockAllocator */
    /* 0x170 */ StdVectorPtr  slot5_vec;             /* vector */
    /* 0x188 */ Nucc_BlockAllocator alloc_slot5;     /* BlockAllocator */
    /* 0x1A0 */ StdVectorPtr  slot6_vec;             /* vector */
    /* 0x1B8 */ Nucc_BlockAllocator alloc_slot6;     /* BlockAllocator */
    /* 0x1D0 */ StdVectorPtr  slot7_vec;             /* vector */
    /* 0x1E8 */ Nucc_BlockAllocator alloc_slot7;     /* BlockAllocator */
    /* 0x200 */ StdVectorPtr  slot8_vec;             /* vector */
    /* 0x218 */ Nucc_BlockAllocator alloc_slot8;     /* BlockAllocator */
    /* 0x230 */ uint64_t      field_230;             /* = 0 */
} ccCollision_ccBulletManager;
static_assert(offsetof(ccCollision_ccBulletManager, vtable)            == 0x000, "ccBulletManager.vtable");
static_assert(offsetof(ccCollision_ccBulletManager, field_18)          == 0x018, "ccBulletManager.field_18");
static_assert(offsetof(ccCollision_ccBulletManager, field_20)          == 0x020, "ccBulletManager.field_20");
static_assert(offsetof(ccCollision_ccBulletManager, field_28)          == 0x028, "ccBulletManager.field_28");
static_assert(offsetof(ccCollision_ccBulletManager, field_30)          == 0x030, "ccBulletManager.field_30");
static_assert(offsetof(ccCollision_ccBulletManager, field_38)          == 0x038, "ccBulletManager.field_38");
static_assert(offsetof(ccCollision_ccBulletManager, field_40)          == 0x040, "ccBulletManager.field_40");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_neg)       == 0x04C, "ccBulletManager.gravity_neg");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_pos)       == 0x054, "ccBulletManager.gravity_pos");
static_assert(offsetof(ccCollision_ccBulletManager, bound_max)         == 0x058, "ccBulletManager.bound_max");
static_assert(offsetof(ccCollision_ccBulletManager, bound_max_5C)      == 0x05C, "ccBulletManager.bound_max_5C");
static_assert(offsetof(ccCollision_ccBulletManager, field_60)          == 0x060, "ccBulletManager.field_60");
static_assert(offsetof(ccCollision_ccBulletManager, collision_objects) == 0x068, "ccBulletManager.collision_objects");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_coll)        == 0x080, "ccBulletManager.alloc_coll");
static_assert(offsetof(ccCollision_ccBulletManager, field_A0)          == 0x0A0, "ccBulletManager.field_A0");
static_assert(offsetof(ccCollision_ccBulletManager, field_A8)          == 0x0A8, "ccBulletManager.field_A8");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_rb1)         == 0x0B0, "ccBulletManager.alloc_rb1");
static_assert(offsetof(ccCollision_ccBulletManager, field_D0)          == 0x0D0, "ccBulletManager.field_D0");
static_assert(offsetof(ccCollision_ccBulletManager, field_D8)          == 0x0D8, "ccBulletManager.field_D8");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_rb2)         == 0x0E0, "ccBulletManager.alloc_rb2");
static_assert(offsetof(ccCollision_ccBulletManager, contact_callback)  == 0x0F8, "ccBulletManager.contact_callback");
static_assert(offsetof(ccCollision_ccBulletManager, field_108)         == 0x108, "ccBulletManager.field_108");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_slot3)       == 0x110, "ccBulletManager.alloc_slot3");
static_assert(offsetof(ccCollision_ccBulletManager, slot4_vec)         == 0x140, "ccBulletManager.slot4_vec");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_slot4)       == 0x158, "ccBulletManager.alloc_slot4");
static_assert(offsetof(ccCollision_ccBulletManager, slot5_vec)         == 0x170, "ccBulletManager.slot5_vec");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_slot5)       == 0x188, "ccBulletManager.alloc_slot5");
static_assert(offsetof(ccCollision_ccBulletManager, slot6_vec)         == 0x1A0, "ccBulletManager.slot6_vec");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_slot6)       == 0x1B8, "ccBulletManager.alloc_slot6");
static_assert(offsetof(ccCollision_ccBulletManager, slot7_vec)         == 0x1D0, "ccBulletManager.slot7_vec");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_slot7)       == 0x1E8, "ccBulletManager.alloc_slot7");
static_assert(offsetof(ccCollision_ccBulletManager, slot8_vec)         == 0x200, "ccBulletManager.slot8_vec");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_slot8)       == 0x218, "ccBulletManager.alloc_slot8");
static_assert(offsetof(ccCollision_ccBulletManager, field_230)         == 0x230, "ccBulletManager.field_230");
/* Size: >= 0x238 */

/* ================================================================
 * ccSkillCollision
 * s3 state_surface: 1 field at 0x60 (vtable write in ctor).
 * Layout matches s2. Size >= 0x68.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x60];     /* base / unknown */
    /* 0x60 */ uint64_t      vtable;            /* vtable ptr */
} ccSkillCollision;
static_assert(offsetof(ccSkillCollision, vtable) == 0x60, "ccSkillCollision.vtable");
/* Size: >= 0x68 */

#endif /* RBCOLLISION_S3_H */