/* rbCollision s2 — NARUTO STORM 2 PC (NSUNS2.exe, image base 0x140000000)
 * Rollback-netcode struct group: ccCollision hierarchy
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Sizes proven from ctor/allocator/reserve where noted; otherwise ">= last field".
 */
#ifndef RBCOLLISION_S2_H
#define RBCOLLISION_S2_H

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
 * Proven by ccBulletManager slot spacing: param_1+0xd to param_1+0x10 = 0x18. */
typedef struct __attribute__((packed)) {
    uint64_t vtable_or_func;   /* 0x0: PTR_FUN_14089c1b8 or similar */
    uint32_t block_id;         /* 0x8: from GetBlockId */
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
 * Ctor: ccCollision::PolygonTable::PolygonTable @ RVA 0x5809B0 (inferred from state_surface seeds)
 * Vtable: at offset 0x0 (inherited pattern from s1)
 * Size proven >= 0x98 (last field at 0x90 + 8)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint64_t      vtable;              /* vtable ptr */
    /* 0x08 */ uint8_t       _pad_08[0xC];        /* gap to 0x14 */
    /* 0x14 */ Nucc_Vector3  vec_a;               /* ctor: Vector3(param_1+0x14, &DAT_14088f6a8) */
    /* 0x20 */ uint8_t       _pad_20[0xC];        /* gap to 0x2C */
    /* 0x2C */ uint64_t      field_2C;            /* = 0 */
    /* 0x34 */ uint32_t      field_34;            /* = 0 */
    /* 0x38 */ uint8_t       _pad_38[0x20];       /* gap to 0x58 */
    /* 0x58 */ uint64_t      field_58;            /* param_1[0xb] = 0 */
    /* 0x60 */ uint64_t      field_60;            /* param_1[0xc] = 0 */
    /* 0x68 */ Nucc_BlockAllocator allocator;     /* param_1+0xd, BlockAllocator init */
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
 * Methods: Add, Disable, Draw, Enable, Execute, Finalize, Initialize, IsEnable, Remove, RequestRemove
 * Vtable: dereferenced at offset 0x0 (virtual calls at +0x10)
 * Size proven >= 0xD0 (BlockAllocator at 0xB8 + 0x18)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint64_t      vtable;              /* virtual dispatch at +0x10 */
    /* 0x08 */ uint8_t       _pad_08[0x60];       /* gap: offsets 0x08-0x67 not accessed */
    /* 0x68 */ uint64_t      field_68;            /* self-ref iterator check (param_1 + 0xd) */
    /* 0x70 */ uint8_t       _pad_70[0x10];       /* gap */
    /* 0x80 */ uint64_t      vfunc_ptr_80;        /* (**(code **)(*param_1 + 0x10))(param_1) */
    /* 0x88 */ uint8_t       _pad_88[0x10];       /* gap */
    /* 0x98 */ uint64_t      heap_obj_98;         /* param_1[0x13], sub-object */
    /* 0xA0 */ uint64_t      vec_begin_A0;        /* param_1[0x14], vector begin */
    /* 0xA8 */ uint64_t      vec_end_A8;          /* param_1[0x15], vector end */
    /* 0xB0 */ uint64_t      vec_cap_B0;          /* param_1[0x16], vector capacity */
    /* 0xB8 */ Nucc_BlockAllocator allocator;     /* param_1+0x17, BlockAllocator */
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
 * Template class with many specializations; large object (fields up to 0x1C0+)
 * Contains embedded sub-objects at 0x34, 0x74, 0x114, 0x148, 0x158
 * Size proven >= 0x1C8 (last virtual call at offset 0x1C0 via vtable+0x38)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint8_t       _pad_000[0x34];    /* base / vtable / unknown */
    /* 0x034 */ uint8_t       subobj_34[0x40];   /* FUN_140586500(param_1 + 0x34) */
    /* 0x074 */ uint8_t       subobj_74[0x4C];   /* FUN_140580a40(param_1 + 0x74) */
    /* 0x0C0 */ uint64_t      field_C0;           /* param_1[0x18], rw high */
    /* 0x0C8 */ uint32_t      field_C8;           /* param_1+0x19, checked != -1 */
    /* 0x0CC */ uint32_t      field_CC;           /* = param_5 */
    /* 0x0D0 */ uint8_t       _pad_0D0[4];        /* padding */
    /* 0x0D4 */ uint32_t      field_D4;           /* = 4 */
    /* 0x0D8 */ uint8_t       _pad_0D8[0x28];     /* gap to 0x100 */
    /* 0x100 */ uint64_t      vtable_100;         /* = &PTR_FUN_1408cf548 */
    /* 0x108 */ uint8_t       _pad_108[0xC];      /* gap */
    /* 0x114 */ uint8_t       subobj_114[0x2C];   /* FUN_1405809b0(param_1 + 0x114) */
    /* 0x140 */ uint64_t      vtable_140;         /* = &PTR_FUN_140798d90 */
    /* 0x148 */ uint8_t       subobj_148[0xC];    /* FUN_1405809b0(param_1 + 0x29) */
    /* 0x154 */ uint32_t      field_154;          /* = 0 */
    /* 0x158 */ uint8_t       subobj_158[0x28];   /* FUN_1405809b0(param_1 + 0x2b) */
    /* 0x180 */ uint8_t       _pad_180[0x40];     /* gap; vtable+0x30 dispatch here */
    /* 0x1C0 */ uint8_t       _pad_1C0[8];        /* vtable+0x38 dispatch target */
} ccCollision_Component;
static_assert(offsetof(ccCollision_Component, subobj_34)   == 0x034, "Component.subobj_34");
static_assert(offsetof(ccCollision_Component, subobj_74)   == 0x074, "Component.subobj_74");
static_assert(offsetof(ccCollision_Component, field_C0)    == 0x0C0, "Component.field_C0");
static_assert(offsetof(ccCollision_Component, field_C8)    == 0x0C8, "Component.field_C8");
static_assert(offsetof(ccCollision_Component, field_CC)    == 0x0CC, "Component.field_CC");
static_assert(offsetof(ccCollision_Component, field_D4)    == 0x0D4, "Component.field_D4");
static_assert(offsetof(ccCollision_Component, vtable_100)  == 0x100, "Component.vtable_100");
static_assert(offsetof(ccCollision_Component, subobj_114)  == 0x114, "Component.subobj_114");
static_assert(offsetof(ccCollision_Component, vtable_140)  == 0x140, "Component.vtable_140");
static_assert(offsetof(ccCollision_Component, subobj_148)  == 0x148, "Component.subobj_148");
static_assert(offsetof(ccCollision_Component, field_154)   == 0x154, "Component.field_154");
static_assert(offsetof(ccCollision_Component, subobj_158)  == 0x158, "Component.subobj_158");
/* Size: >= 0x1C8 (last vtable dispatch at +0x38 from base vtable) */

/* ================================================================
 * ccCollision::ccBulletRigidBodyMesh
 * CreateMesh + dtor evidence from state_surface (9 fields, high confidence)
 * Vtable: inherited from ccBulletRigidBodyBase
 * Size proven >= 0xA0 (last field at 0x98 + 8)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x58];     /* base class ccBulletRigidBodyBase */
    /* 0x58 */ uint64_t      mesh_data_58;      /* param_1[0xb], rw high */
    /* 0x60 */ uint64_t      mesh_data_60;      /* param_1[0xc], rw high */
    /* 0x68 */ uint64_t      mesh_data_68;      /* param_1[0xd], rw high */
    /* 0x70 */ uint64_t      mesh_data_70;      /* param_1[0xe], rw high */
    /* 0x78 */ uint32_t      field_78;          /* param_1+0xf = 0 */
    /* 0x7C */ uint8_t       _pad_7C[4];        /* padding */
    /* 0x80 */ uint64_t      user_ptr_80;       /* param_1[0x10] = param_2, rw low */
    /* 0x88 */ uint64_t      mesh_data_88;      /* param_1[0x11], rw high */
    /* 0x90 */ uint64_t      mesh_data_90;      /* param_1[0x12], rw high */
    /* 0x98 */ uint64_t      mesh_data_98;      /* param_1[0x13], rw high */
} ccCollision_ccBulletRigidBodyMesh;
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_58) == 0x58, "ccBulletRigidBodyMesh.mesh_data_58");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_60) == 0x60, "ccBulletRigidBodyMesh.mesh_data_60");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_68) == 0x68, "ccBulletRigidBodyMesh.mesh_data_68");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_70) == 0x70, "ccBulletRigidBodyMesh.mesh_data_70");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, field_78)     == 0x78, "ccBulletRigidBodyMesh.field_78");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, user_ptr_80)  == 0x80, "ccBulletRigidBodyMesh.user_ptr_80");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_88) == 0x88, "ccBulletRigidBodyMesh.mesh_data_88");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_90) == 0x90, "ccBulletRigidBodyMesh.mesh_data_90");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_98) == 0x98, "ccBulletRigidBodyMesh.mesh_data_98");
/* Size: >= 0xA0 */

/* ================================================================
 * ccCollision::ccBulletManager
 * Ctor: ccCollision::ccBulletManager::ccBulletManager @ RVA 0x5DCAC0
 * Vtable: PTR_FUN_140895c58 at offset 0x0
 * Size proven >= 0x238 (last field param_1[0x46] at offset 0x230 + 8)
 * Contains 8 repeating slots of (vector<ptr> + BlockAllocator) for bullet pools
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint64_t      vtable;                /* PTR_FUN_140895c58 */
    /* 0x008 */ uint8_t       _pad_008[0x10];        /* gap */
    /* 0x018 */ uint32_t      field_18;              /* param_1+3 = 0 */
    /* 0x01C */ uint8_t       _pad_01C[4];           /* padding */
    /* 0x020 */ uint64_t      field_20;              /* param_1[4] = 0 */
    /* 0x028 */ uint64_t      field_28;              /* param_1[5] = 0 */
    /* 0x030 */ uint64_t      field_30;              /* param_1[6] = 0 */
    /* 0x038 */ uint64_t      field_38;              /* param_1[7] = 0 */
    /* 0x040 */ uint64_t      field_40;              /* param_1[8] = 0 */
    /* 0x048 */ float         gravity_neg;           /* param_1+9 = 0xc6ea6000 (-30000.0f) */
    /* 0x04C */ float         gravity_neg_4C;        /* 0xc6ea6000 */
    /* 0x050 */ float         gravity_pos;           /* param_1[10] = 0xc6ea6000 */
    /* 0x054 */ float         gravity_pos_54;        /* 0x46ea6000 (30000.0f) */
    /* 0x058 */ float         bound_max;             /* param_1[0xb] = 0x46ea6000 */
    /* 0x05C */ float         bound_max_5C;          /* 0x46ea6000 */
    /* 0x060 */ uint32_t      field_60;              /* param_1+0xc = 0 */
    /* 0x064 */ uint8_t       _pad_064[4];           /* padding */
    /* 0x068 */ StdVectorPtr  collision_objects;     /* param_1+0xd, reserve(0x200) */
    /* 0x080 */ Nucc_BlockAllocator alloc_coll;      /* param_1+0x10 */
    /* 0x098 */ StdVectorPtr  rigid_bodies_1;        /* param_1+0x13, reserve(0x800) */
    /* 0x0B0 */ Nucc_BlockAllocator alloc_rb1;       /* param_1+0x16 */
    /* 0x0C8 */ StdVectorPtr  rigid_bodies_2;        /* param_1+0x19, reserve(0x800) */
    /* 0x0E0 */ Nucc_BlockAllocator alloc_rb2;       /* param_1+0x1c */
    /* 0x0F8 */ uint8_t       contact_callback[0x10];/* param_1+0x1f, ccBulletRigidbodyContactResultCallback */
    /* 0x108 */ uint64_t      field_108;             /* param_1[0x21] = 0 */
    /* 0x110 */ Nucc_BlockAllocator alloc_slot3;     /* param_1+0x22 */
    /* 0x128 */ uint8_t       _pad_128[0x18];        /* gap to next slot */
    /* 0x140 */ StdVectorPtr  slot4_vec;             /* param_1+0x28 */
    /* 0x158 */ Nucc_BlockAllocator alloc_slot4;     /* param_1+0x2b */
    /* 0x170 */ StdVectorPtr  slot5_vec;             /* param_1+0x2e */
    /* 0x188 */ Nucc_BlockAllocator alloc_slot5;     /* param_1+0x31 */
    /* 0x1A0 */ StdVectorPtr  slot6_vec;             /* param_1+0x34 */
    /* 0x1B8 */ Nucc_BlockAllocator alloc_slot6;     /* param_1+0x37 */
    /* 0x1D0 */ StdVectorPtr  slot7_vec;             /* param_1+0x3a */
    /* 0x1E8 */ Nucc_BlockAllocator alloc_slot7;     /* param_1+0x3d */
    /* 0x200 */ StdVectorPtr  slot8_vec;             /* param_1+0x40 */
    /* 0x218 */ Nucc_BlockAllocator alloc_slot8;     /* param_1+0x43 */
    /* 0x230 */ uint64_t      field_230;             /* param_1[0x46] = 0 */
} ccCollision_ccBulletManager;
static_assert(offsetof(ccCollision_ccBulletManager, vtable)            == 0x000, "ccBulletManager.vtable");
static_assert(offsetof(ccCollision_ccBulletManager, field_18)          == 0x018, "ccBulletManager.field_18");
static_assert(offsetof(ccCollision_ccBulletManager, field_20)          == 0x020, "ccBulletManager.field_20");
static_assert(offsetof(ccCollision_ccBulletManager, field_28)          == 0x028, "ccBulletManager.field_28");
static_assert(offsetof(ccCollision_ccBulletManager, field_30)          == 0x030, "ccBulletManager.field_30");
static_assert(offsetof(ccCollision_ccBulletManager, field_38)          == 0x038, "ccBulletManager.field_38");
static_assert(offsetof(ccCollision_ccBulletManager, field_40)          == 0x040, "ccBulletManager.field_40");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_neg)       == 0x048, "ccBulletManager.gravity_neg");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_neg_4C)    == 0x04C, "ccBulletManager.gravity_neg_4C");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_pos)       == 0x050, "ccBulletManager.gravity_pos");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_pos_54)    == 0x054, "ccBulletManager.gravity_pos_54");
static_assert(offsetof(ccCollision_ccBulletManager, bound_max)         == 0x058, "ccBulletManager.bound_max");
static_assert(offsetof(ccCollision_ccBulletManager, bound_max_5C)      == 0x05C, "ccBulletManager.bound_max_5C");
static_assert(offsetof(ccCollision_ccBulletManager, field_60)          == 0x060, "ccBulletManager.field_60");
static_assert(offsetof(ccCollision_ccBulletManager, collision_objects) == 0x068, "ccBulletManager.collision_objects");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_coll)        == 0x080, "ccBulletManager.alloc_coll");
static_assert(offsetof(ccCollision_ccBulletManager, rigid_bodies_1)    == 0x098, "ccBulletManager.rigid_bodies_1");
static_assert(offsetof(ccCollision_ccBulletManager, alloc_rb1)         == 0x0B0, "ccBulletManager.alloc_rb1");
static_assert(offsetof(ccCollision_ccBulletManager, rigid_bodies_2)    == 0x0C8, "ccBulletManager.rigid_bodies_2");
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
 * Methods: CreateObjectHit, CreateWorldHit, Remove, Reserve, Update, ~ccSkillCollision
 * Only one field observed at 0x60 (vtable write in ctor)
 * Size unknown, >= 0x68
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x60];     /* base / unknown */
    /* 0x60 */ uint64_t      vtable;            /* = &PTR_FUN_14089c1b8 */
} ccSkillCollision;
static_assert(offsetof(ccSkillCollision, vtable) == 0x60, "ccSkillCollision.vtable");
/* Size: >= 0x68 */

#endif /* RBCOLLISION_S2_H */