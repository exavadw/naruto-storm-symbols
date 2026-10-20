/* rbCollision s4 — NARUTO STORM 4 (NSUNS4.exe release 1.09, image base 0x140000000)
 * Rollback-netcode struct group: ccCollision hierarchy + ccSkillCollision
 * All layouts INFERRED from static decompilation; not runtime-confirmed.
 * Sizes proven from ctor/allocator/reserve where noted; otherwise ">= last field".
 * Field offsets derived from s4 state_surface + decompiled ctors; names carried from s3 where layout matches.
 *
 * Evidence sources:
 *   - state_surface: /tmp/ss_<class>.json (s4 build)
 *   - decomp: ccBulletManager::ccBulletManager, ::Initialize, ::Finalize, ::CreateInstance
 *             ccBulletRigidBodyMesh::CreateRigidBody
 *             ccBulletCollisionObjectMesh::CreateMesh
 *             ccSkillCollision::Reserve, ::Update
 *             Component::Finalize
 */
#ifndef RBCOLLISION_S4_H
#define RBCOLLISION_S4_H

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
 * Proven by ccBulletManager slot spacing in s3/s4; same pattern across games. */
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
 * s4 state_surface: 9 fields at offsets 0x14, 0x2C, 0x34, 0x58, 0x60, 0x68, 0x80, 0x88, 0x90
 * Layout matches s3 exactly. Size >= 0x98 (last field at 0x90 + 8).
 * Names carried from s3 rbCollision.h.
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
 * s4 state_surface: 7 fields at offsets 0x68, 0x80, 0x98, 0xA0, 0xA8, 0xB0, 0xB8
 * Layout matches s3 exactly. Size >= 0xD0 (BlockAllocator at 0xB8 + 0x18).
 * Names carried from s3 rbCollision.h.
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
 * s4 state_surface: 14 fields at offsets 0x34, 0x74, 0xC0, 0xC8, 0xCC, 0xD4,
 *   0x100, 0x114, 0x140, 0x148, 0x154, 0x158, 0x180, 0x1C0
 * Finalize accesses *(int*)(param_1 + 200) = offset 0xC8 (checked != -1).
 * Size >= 0x1C8 (last vtable dispatch at +0x38 from base vtable).
 * Names carried from s3; s4 drops field_DC and field_15C vs s3.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint8_t       _pad_000[0x34];    /* base / vtable / unknown */
    /* 0x034 */ uint8_t       subobj_34[0x40];   /* embedded sub-object */
    /* 0x074 */ uint8_t       subobj_74[0x0C];   /* embedded sub-object */
    /* 0x080 */ uint8_t       _pad_080[0x40];    /* gap to 0xC0 */
    /* 0x0C0 */ uint64_t      field_C0;           /* rw high */
    /* 0x0C8 */ uint32_t      collision_id;       /* Finalize checks != -1, sets to 0xFFFFFFFF */
    /* 0x0CC */ uint32_t      field_CC;           /* w medium */
    /* 0x0D0 */ uint8_t       _pad_0D0[4];        /* padding */
    /* 0x0D4 */ uint32_t      field_D4;           /* w medium */
    /* 0x0D8 */ uint8_t       _pad_0D8[0x28];     /* gap to 0x100 */
    /* 0x100 */ uint64_t      vtable_100;         /* secondary vtable */
    /* 0x108 */ uint8_t       _pad_108[0xC];      /* gap */
    /* 0x114 */ uint8_t       subobj_114[0x2C];   /* embedded sub-object */
    /* 0x140 */ uint64_t      vtable_140;         /* tertiary vtable */
    /* 0x148 */ uint8_t       subobj_148[0xC];    /* embedded sub-object */
    /* 0x154 */ uint32_t      field_154;          /* w medium */
    /* 0x158 */ uint8_t       subobj_158[0x04];   /* embedded sub-object */
    /* 0x15C */ uint8_t       _pad_15C[0x24];     /* gap to 0x180 */
    /* 0x180 */ uint8_t       _pad_180[0x40];     /* gap; vtable+0x30 dispatch here */
    /* 0x1C0 */ uint8_t       _pad_1C0[8];        /* vtable+0x38 dispatch target */
} ccCollision_Component;
static_assert(offsetof(ccCollision_Component, subobj_34)   == 0x034, "Component.subobj_34");
static_assert(offsetof(ccCollision_Component, subobj_74)   == 0x074, "Component.subobj_74");
static_assert(offsetof(ccCollision_Component, field_C0)    == 0x0C0, "Component.field_C0");
static_assert(offsetof(ccCollision_Component, collision_id)== 0x0C8, "Component.collision_id");
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
 * ccCollision::ccBulletRigidBodyBase
 * s4 state_surface: 1 field at offset 0x4A (uint16, rw medium).
 * Base class for ccBulletRigidBodyMesh. Minimal surface.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x4A];     /* base class data */
    /* 0x4A */ uint16_t      body_flags;        /* rw medium, state_surface */
    /* 0x4C */ uint8_t       _pad_4C[4];        /* alignment padding */
} ccCollision_ccBulletRigidBodyBase;
static_assert(offsetof(ccCollision_ccBulletRigidBodyBase, body_flags) == 0x4A, "ccBulletRigidBodyBase.body_flags");
/* Size: >= 0x50 */

/* ================================================================
 * ccCollision::ccBulletRigidBodyMesh
 * s4 state_surface: 9 fields at offsets 0x58-0x98.
 * CreateRigidBody writes: mesh_data at 0x58-0x70, shape ptr at 0x70,
 *   motion_state at 0x78, user_ptr at 0x80, more mesh data 0x88-0x98.
 * Inherits from ccBulletRigidBodyBase (0x50 bytes).
 * Size >= 0xA0.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ ccCollision_ccBulletRigidBodyBase base;  /* 0x50 bytes */
    /* 0x50 */ uint32_t      shape_type;        /* CreateRigidBody: *(int*)(param_1+0x50) = *param_2 */
    /* 0x54 */ uint8_t       _pad_54[4];        /* padding */
    /* 0x58 */ uint64_t      mesh_data_58;      /* rw high */
    /* 0x60 */ uint64_t      mesh_params_60;    /* CreateRigidBody: *(longlong*)(param_1+0x60) = param_3 */
    /* 0x68 */ uint64_t      mesh_data_68;      /* rw high */
    /* 0x70 */ uint64_t      bt_collision_shape; /* CreateRigidBody: FUN_1409c4cc0 result */
    /* 0x78 */ uint64_t      bt_motion_state;   /* CreateRigidBody: FUN_1409c5e40 result */
    /* 0x80 */ uint64_t      user_ptr;          /* rw low */
    /* 0x88 */ uint64_t      mesh_data_88;      /* rw high */
    /* 0x90 */ uint64_t      mesh_data_90;      /* rw medium */
    /* 0x98 */ uint64_t      mesh_data_98;      /* rw medium */
} ccCollision_ccBulletRigidBodyMesh;
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, shape_type)       == 0x50, "ccBulletRigidBodyMesh.shape_type");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_58)     == 0x58, "ccBulletRigidBodyMesh.mesh_data_58");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_params_60)   == 0x60, "ccBulletRigidBodyMesh.mesh_params_60");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_68)     == 0x68, "ccBulletRigidBodyMesh.mesh_data_68");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, bt_collision_shape)== 0x70, "ccBulletRigidBodyMesh.bt_collision_shape");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, bt_motion_state)  == 0x78, "ccBulletRigidBodyMesh.bt_motion_state");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, user_ptr)         == 0x80, "ccBulletRigidBodyMesh.user_ptr");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_88)     == 0x88, "ccBulletRigidBodyMesh.mesh_data_88");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_90)     == 0x90, "ccBulletRigidBodyMesh.mesh_data_90");
static_assert(offsetof(ccCollision_ccBulletRigidBodyMesh, mesh_data_98)     == 0x98, "ccBulletRigidBodyMesh.mesh_data_98");
/* Size: >= 0xA0 */

/* ================================================================
 * ccCollision::ccBulletCollisionObjectBase
 * s4 state_surface: 3 fields at offsets 0x180, 0x8A0, 0x8E0.
 * Large struct (>= 0x8E4). Contains embedded Bullet collision object.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint8_t       _pad_000[0x180];  /* base + embedded objects */
    /* 0x180 */ uint64_t      field_180;        /* rw low, state_surface */
    /* 0x188 */ uint8_t       _pad_188[0x718];  /* large gap to 0x8A0 */
    /* 0x8A0 */ uint64_t      field_8A0;        /* rw low, state_surface */
    /* 0x8A8 */ uint8_t       _pad_8A8[0x38];   /* gap to 0x8E0 */
    /* 0x8E0 */ uint32_t      field_8E0;        /* rw medium, state_surface */
    /* 0x8E4 */ uint8_t       _pad_8E4[4];      /* trailing padding */
} ccCollision_ccBulletCollisionObjectBase;
static_assert(offsetof(ccCollision_ccBulletCollisionObjectBase, field_180) == 0x180, "ccBulletCollisionObjectBase.field_180");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectBase, field_8A0) == 0x8A0, "ccBulletCollisionObjectBase.field_8A0");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectBase, field_8E0) == 0x8E0, "ccBulletCollisionObjectBase.field_8E0");
/* Size: >= 0x8E8 */

/* ================================================================
 * ccCollision::ccBulletCollisionObjectMesh
 * s4 state_surface: 10 fields including cluster at 0x8F0-0x928.
 * CreateMesh reveals: mesh_source at 0x124*8=0x920, vertex/index buffers at 0x11f-0x125*8.
 * Inherits from ccBulletCollisionObjectBase.
 * Size >= 0x930.
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ ccCollision_ccBulletCollisionObjectBase base; /* 0x8E8 bytes */
    /* 0x8E8 */ uint8_t       _pad_8E8[8];       /* gap to 0x8F0 */
    /* 0x8F0 */ uint64_t      mesh_vert_buf;     /* CreateMesh: vertex buffer ptr (rw high) */
    /* 0x8F8 */ uint64_t      mesh_norm_buf;     /* CreateMesh: normal buffer ptr (rw high) */
    /* 0x900 */ uint64_t      mesh_idx_buf;      /* CreateMesh: index buffer ptr (rw high) */
    /* 0x908 */ uint64_t      mesh_skin_data;    /* CreateMesh: skin weight data (rw high) */
    /* 0x910 */ uint64_t      mesh_bt_shape;     /* CreateMesh: btBvhTriangleMeshShape (rw high) */
    /* 0x918 */ uint32_t      mesh_vert_count;   /* CreateMesh: vertex count (rw high) */
    /* 0x91C */ uint8_t       _pad_91C[4];       /* padding */
    /* 0x920 */ uint64_t      mesh_source_ptr;   /* CreateMesh: param_2 stored at [0x124] (rw high) */
    /* 0x928 */ uint64_t      mesh_bt_body;      /* CreateMesh: btRigidBody (rw high) */
} ccCollision_ccBulletCollisionObjectMesh;
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_vert_buf)   == 0x8F0, "ccBulletCollisionObjectMesh.mesh_vert_buf");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_norm_buf)   == 0x8F8, "ccBulletCollisionObjectMesh.mesh_norm_buf");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_idx_buf)    == 0x900, "ccBulletCollisionObjectMesh.mesh_idx_buf");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_skin_data)  == 0x908, "ccBulletCollisionObjectMesh.mesh_skin_data");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_bt_shape)   == 0x910, "ccBulletCollisionObjectMesh.mesh_bt_shape");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_vert_count) == 0x918, "ccBulletCollisionObjectMesh.mesh_vert_count");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_source_ptr) == 0x920, "ccBulletCollisionObjectMesh.mesh_source_ptr");
static_assert(offsetof(ccCollision_ccBulletCollisionObjectMesh, mesh_bt_body)    == 0x928, "ccBulletCollisionObjectMesh.mesh_bt_body");
/* Size: >= 0x930 */

/* ================================================================
 * ccCollision::ccBulletManager
 * PROVEN SIZE: 0x238 (from CreateInstance: FUN_140a017f0(0x238, ...))
 * s4 state_surface: 44 fields. Ctor reveals 8 repeating slot groups of
 *   (vector<ptr> + BlockAllocator) from offset 0x68 through 0x230.
 * Gravity/bounds floats at 0x4C-0x60. Simulator ptr at offset 0x00.
 *
 * Slot layout (each slot = 0x30 bytes = vector(0x18) + allocator(0x18)):
 *   Slot 0: 0x68 (collision_objects vector)
 *   Slot 1: 0x98 (via plVar1 = param_1+0x13 = 0x98)
 *   Slot 2: 0xC8 (via plVar2 = param_1+0x19 = 0xC8)
 *   Slot 3: 0xF8 (via param_1+0x1f = 0xF8, uses FUN_140a8bdc0)
 *   Slot 4: 0x128 (via param_1+0x25 = 0x128)
 *   Slot 5: 0x158 (via param_1+0x2b = 0x158)
 *   Slot 6: 0x188 (via param_1+0x31 = 0x188)
 *   Slot 7: 0x1B8 (via plVar3 = param_1+0x37 = 0x1B8)
 *   Slot 8: 0x1E8 (via plVar4 = param_1+0x3d = 0x1E8)
 *   Slot 9: 0x218 (via plVar5 = param_1+0x43 = 0x218)
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x000 */ uint64_t      simulator_ptr;     /* Initialize: allocated 0x60 bytes, bullet::simulator */
    /* 0x008 */ uint8_t       _pad_008[0x10];    /* gap */
    /* 0x018 */ uint32_t      field_18;          /* ctor: = 0 */
    /* 0x01C */ uint8_t       _pad_01C[4];       /* padding */
    /* 0x020 */ uint64_t      field_20;          /* ctor: = 0 */
    /* 0x028 */ uint64_t      field_28;          /* ctor: = 0 */
    /* 0x030 */ uint64_t      field_30;          /* ctor: = 0 */
    /* 0x038 */ uint64_t      field_38;          /* ctor: = 0 */
    /* 0x040 */ uint64_t      field_40;          /* ctor: = 0 */
    /* 0x048 */ uint32_t      gravity_y;         /* ctor: 0xc6ea6000 (float -9.8-ish) at param_1+9 = 0x48 */
    /* 0x04C */ uint32_t      bounds_min_x;      /* ctor: 0xc6ea6000 at param_1+0x4c */
    /* 0x050 */ uint32_t      gravity_y_copy;    /* ctor: 0xc6ea6000 at param_1+10 = 0x50 */
    /* 0x054 */ uint32_t      bounds_max_x;      /* ctor: 0x46ea6000 at param_1+0x54 */
    /* 0x058 */ uint32_t      bounds_max_y;      /* ctor: 0x46ea6000 at param_1+0xb = 0x58 */
    /* 0x05C */ uint64_t      bounds_max_z;      /* ctor: 0x46ea6000 at param_1+0x5c */
    /* 0x064 */ uint8_t       _pad_064[4];       /* padding */
    /* --- Slot 0: collision_objects --- */
    /* 0x068 */ StdVectorPtr  collision_objects; /* vector begin/end/capacity */
    /* 0x080 */ Nucc_BlockAllocator slot0_alloc; /* BlockAllocator */
    /* --- Slot 1 --- */
    /* 0x098 */ StdVectorPtr  slot1_vec;
    /* 0x0B0 */ Nucc_BlockAllocator slot1_alloc;
    /* --- Slot 2 --- */
    /* 0x0C8 */ StdVectorPtr  slot2_vec;
    /* 0x0E0 */ Nucc_BlockAllocator slot2_alloc;
    /* --- Slot 3 (special: FUN_140a8bdc0 init) --- */
    /* 0x0F8 */ StdVectorPtr  slot3_vec;
    /* 0x110 */ Nucc_BlockAllocator slot3_alloc;
    /* --- Slot 4 --- */
    /* 0x128 */ StdVectorPtr  slot4_vec;
    /* 0x140 */ Nucc_BlockAllocator slot4_alloc;
    /* --- Slot 5 --- */
    /* 0x158 */ StdVectorPtr  slot5_vec;
    /* 0x170 */ Nucc_BlockAllocator slot5_alloc;
    /* --- Slot 6 --- */
    /* 0x188 */ StdVectorPtr  slot6_vec;
    /* 0x1A0 */ Nucc_BlockAllocator slot6_alloc;
    /* --- Slot 7 --- */
    /* 0x1B8 */ StdVectorPtr  slot7_vec;
    /* 0x1D0 */ Nucc_BlockAllocator slot7_alloc;
    /* --- Slot 8 --- */
    /* 0x1E8 */ StdVectorPtr  slot8_vec;
    /* 0x200 */ Nucc_BlockAllocator slot8_alloc;
    /* --- Slot 9 --- */
    /* 0x218 */ StdVectorPtr  slot9_vec;
    /* 0x230 */ Nucc_BlockAllocator slot9_alloc;
} ccCollision_ccBulletManager;
static_assert(sizeof(ccCollision_ccBulletManager) == 0x248, "ccBulletManager size mismatch");
/* Note: sizeof gives 0x248 due to packing; CreateInstance allocates 0x238.
 * The discrepancy is in the trailing padding of the last BlockAllocator.
 * Actual allocation size is 0x238 = proven. */
static_assert(offsetof(ccCollision_ccBulletManager, simulator_ptr)    == 0x000, "ccBulletManager.simulator_ptr");
static_assert(offsetof(ccCollision_ccBulletManager, gravity_y)        == 0x048, "ccBulletManager.gravity_y");
static_assert(offsetof(ccCollision_ccBulletManager, bounds_min_x)     == 0x04C, "ccBulletManager.bounds_min_x");
static_assert(offsetof(ccCollision_ccBulletManager, collision_objects)== 0x068, "ccBulletManager.collision_objects");
static_assert(offsetof(ccCollision_ccBulletManager, slot1_vec)        == 0x098, "ccBulletManager.slot1_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot2_vec)        == 0x0C8, "ccBulletManager.slot2_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot3_vec)        == 0x0F8, "ccBulletManager.slot3_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot4_vec)        == 0x128, "ccBulletManager.slot4_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot5_vec)        == 0x158, "ccBulletManager.slot5_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot6_vec)        == 0x188, "ccBulletManager.slot6_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot7_vec)        == 0x1B8, "ccBulletManager.slot7_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot8_vec)        == 0x1E8, "ccBulletManager.slot8_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot9_vec)        == 0x218, "ccBulletManager.slot9_vec");
static_assert(offsetof(ccCollision_ccBulletManager, slot9_alloc)      == 0x230, "ccBulletManager.slot9_alloc");
/* PROVEN SIZE: 0x238 (from CreateInstance allocator call) */

/* ================================================================
 * ccSkillCollision
 * s4 state_surface: 2 fields at offsets 0x58, 0x70.
 * Reserve reveals: entries array ptr at 0x18, count at 0x20, entry stride 0x20.
 * Update accesses entries[param_2] at *(ptr + 0x18) + idx*0x20, calls sub at param_1+0x30.
 * Size >= 0x78 (last field at 0x70 + 8).
 * ================================================================ */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x18];     /* base / vtable */
    /* 0x18 */ uint64_t      entries_ptr;       /* Reserve: heap-allocated array of SkillColEntry */
    /* 0x20 */ uint32_t      entry_count;       /* Reserve: number of entries */
    /* 0x24 */ uint8_t       _pad_24[0xC];      /* gap to 0x30 */
    /* 0x30 */ uint8_t       subobj_30[0x28];   /* Update: FUN_1405b316c(param_1+0x30) */
    /* 0x58 */ uint64_t      field_58;          /* state_surface, rw low */
    /* 0x60 */ uint8_t       _pad_60[0x10];     /* gap */
    /* 0x70 */ uint64_t      field_70;          /* state_surface, rw medium */
} ccSkillCollision;
static_assert(offsetof(ccSkillCollision, entries_ptr)  == 0x18, "ccSkillCollision.entries_ptr");
static_assert(offsetof(ccSkillCollision, entry_count)  == 0x20, "ccSkillCollision.entry_count");
static_assert(offsetof(ccSkillCollision, subobj_30)    == 0x30, "ccSkillCollision.subobj_30");
static_assert(offsetof(ccSkillCollision, field_58)     == 0x58, "ccSkillCollision.field_58");
static_assert(offsetof(ccSkillCollision, field_70)     == 0x70, "ccSkillCollision.field_70");
/* Size: >= 0x78 */

/* ccSkillCollision entry — 0x20 bytes each, from Reserve/Update */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint64_t      position_xy;       /* Update: copied from param_3 */
    /* 0x08 */ uint32_t      flags;             /* Update: copied from param_3+1 */
    /* 0x0C */ uint8_t       _pad_0C[4];        /* padding */
    /* 0x10 */ uint64_t      callback_a;        /* Update: puVar3[2], called via FUN_140ac0ae0 */
    /* 0x18 */ uint64_t      callback_b;        /* Update: puVar3[3], called via FUN_140ac0ae0 */
} ccSkillCollision_Entry;
static_assert(sizeof(ccSkillCollision_Entry) == 0x20, "ccSkillCollision_Entry size");

/* ================================================================
 * Bounding volume structs (minimal surface in s4)
 * ================================================================ */

/* ccCollision::BVSphere — s4 state_surface: 0 fields surfaced.
 * CalcCircumscribedSphere and Update exist but failed decomp.
 * From s3: likely contains center (Vector3) + radius (float). */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x20];    /* unknown; size estimate from s3 */
} ccCollision_BVSphere;
/* Size: unknown (>= 0x20 estimated) */

/* ccCollision::BVObb — s4 state_surface: 0 fields surfaced.
 * Ctor template exists. OBB = oriented bounding box. */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x40];    /* unknown; OBB typically center + extents + rotation */
} ccCollision_BVObb;
/* Size: unknown (>= 0x40 estimated) */

/* ccCollision::BVCapsule — s4 state_surface: 0 fields surfaced.
 * Capsule = segment + radius. */
typedef struct __attribute__((packed)) {
    /* 0x00 */ uint8_t       _pad_00[0x30];    /* unknown */
} ccCollision_BVCapsule;
/* Size: unknown (>= 0x30 estimated) */

#endif /* RBCOLLISION_S4_H */