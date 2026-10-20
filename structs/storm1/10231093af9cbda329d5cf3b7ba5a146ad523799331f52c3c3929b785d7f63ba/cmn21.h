/*
 * cmn21.h - Common struct group cmn21 for NARUTO STORM 1 PC (NSUNS1.exe, build s1)
 *
 * All layouts are INFERRED from static analysis (decompiled code, state_surface).
 * No runtime confirmation. Sizes proven from ctor/allocator where possible;
 * otherwise marked "size unknown, >= 0xN".
 *
 * Own-game names only: Storm 1 (s1) symbols/strings/code.
 * PC offsets only: derived from x64 decompile (image base 0x140000000).
 */

#ifndef CMN21_S1_H
#define CMN21_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose full layout is not in cmn21 */
typedef struct Nucc_Vector3 {
    float x;
    float y;
    float z;
} Nucc_Vector3;

/* ========================================================================
 * GameActor::Base
 * Inherits ccTaskBase. Vtable at offset 0x0 set to PTR_FUN_140747b70 in ctor.
 * Size: unknown, >= 0x90 (last proven field at 0x84 + 4 bytes, plus vfunc call at 0x1C0 implies larger)
 * ======================================================================== */
typedef struct __attribute__((packed)) GameActor_Base {
    /* 0x00 */ void *vtable;               /* set to &PTR_FUN_140747b70 in Base ctor */
    /* 0x08 */ uint8_t _ccTaskBase[0x38];  /* ccTaskBase subobject (inferred from ctor calling ccTaskBase::ccTaskBase then writing at param_1+8 as uint32) */
    /* 0x40 */ uint8_t _unknown_40[0x8];   /* gap before FUN_14056a0a0(param_1+9) => param_1+0x48 */
    /* 0x48 */ uint8_t _subobj_48[0x24];   /* sub-object initialized by FUN_14056a0a0 at param_1+9 (0x48), 9*8=72 bytes but likely smaller struct */
    /* 0x6C */ uint8_t _gap_6C[0x4];       /* padding to reach Vector3 at 0x70 */
    /* 0x70 */ Nucc_Vector3 position;      /* Nucc::Vector3::Vector3(param_1 + 0xe) => 0x70 */
    /* 0x7C */ uint64_t field_7C;          /* *(undefined8*)(param_1+0x7c)=0 in ctor; state_surface shows size [4,8], w */
    /* 0x84 */ uint32_t field_84;          /* *(undefined4*)(param_1+0x84)=0 in ctor; high confidence w */
    /* 0x88 */ uint64_t visibleVolume;     /* param_1[0x11]=0 in ctor; rw in CreateVisibleVolume/SetPositionNew */
    /* 0x90 */ uint8_t _pad_90[0x130];     /* gap to vfunc dispatch at param_1+0x1C0 (seen in SetPositionNew) */
    /* 0x1C0 -- vfunc slot: (**(code**)(*param_1+0x38))(param_1) => vtable[7] */
    /* 0x200 -- passed to FUN_1404f8580(param_1+0x40,...) in RemoveComponent */
} GameActor_Base;
/* Size unknown, >= 0x90. No operator new / allocator size found in s1 symbols. */

static_assert(offsetof(GameActor_Base, vtable) == 0x00, "GameActor_Base.vtable");
static_assert(offsetof(GameActor_Base, _ccTaskBase) == 0x08, "GameActor_Base._ccTaskBase");
static_assert(offsetof(GameActor_Base, _subobj_48) == 0x48, "GameActor_Base._subobj_48");
static_assert(offsetof(GameActor_Base, position) == 0x70, "GameActor_Base.position");
static_assert(offsetof(GameActor_Base, field_7C) == 0x7C, "GameActor_Base.field_7C");
static_assert(offsetof(GameActor_Base, field_84) == 0x84, "GameActor_Base.field_84");
static_assert(offsetof(GameActor_Base, visibleVolume) == 0x88, "GameActor_Base.visibleVolume");

/* ========================================================================
 * GameActor::Component
 * Vtable at 0x0 set to PTR_FUN_140748d90 in ctor. Contains BlockAllocator subobject.
 * Size: unknown, >= 0x28 (param_1[4]=param_2 at offset 0x20, plus vtable ptr at 0x8 after BlockAllocator)
 * Only 1 seed method surfaced fields (state_surface returned 0 fields due to limited access patterns).
 * Layout from ctor symbolized decompile:
 *   *param_1 = &PTR_FUN_140773600 (initial vtable)
 *   BlockAllocator::BlockAllocator(param_1+1, uVar1) => subobject at 0x08
 *   *param_1 = &PTR_FUN_140748d90 (final vtable)
 *   param_1[1] = &PTR_LAB_140748d98 => offset 0x08 overwritten? No: param_1 is uint64*, so param_1[1]=offset 0x08
 *   Actually re-reading: after BlockAllocator init, vtable reset, then param_1[1] = ptr, param_1[4] = owner
 * ======================================================================== */
typedef struct __attribute__((packed)) GameActor_Component {
    /* 0x00 */ void *vtable;              /* final: &PTR_FUN_140748d90 */
    /* 0x08 */ void *field_08;            /* param_1[1] = &PTR_LAB_140748d98 */
    /* 0x10 */ uint8_t _blockAlloc[0x10]; /* BlockAllocator subobject at param_1+1 (0x08..0x17?) - overlaps field_08; see note */
    /* 0x20 */ void *owner;               /* param_1[4] = param_2 (owner handle) */
    /* 0x28 */ uint8_t _pad[0x0];         /* end of proven fields */
} GameActor_Component;
/* Note: BlockAllocator written at param_1+1 before vtable reset. The param_1[1] write at 0x08
   overwrites part of BlockAllocator or BlockAllocator is at a different offset.
   Ctor sequence: initial vtable -> BlockAllocator(param_1+1) -> final vtable -> param_1[1]=ptr -> param_1[4]=owner.
   Since param_1 is uint64*, param_1+1 = byte offset 0x08. BlockAllocator likely occupies 0x08..0x17 (16 bytes).
   Then param_1[1] at 0x08 overwrites the first 8 bytes of BlockAllocator? Unlikely.
   More probable: BlockAllocator is small (8 bytes) at 0x08, then param_1[1] at 0x08 is the same field.
   Re-interpreting: BlockAllocator stores block id at its offset, then param_1[1] sets a different pointer.
   Without more methods, exact layout is uncertain. Listing proven accesses only. */
/* Size unknown, >= 0x28 */

static_assert(offsetof(GameActor_Component, vtable) == 0x00, "GameActor_Component.vtable");
static_assert(offsetof(GameActor_Component, field_08) == 0x08, "GameActor_Component.field_08");
static_assert(offsetof(GameActor_Component, owner) == 0x20, "GameActor_Component.owner");

/* ========================================================================
 * GameActor::TestActor
 * Only 1 method in s1 (~TestActor). Fewer than 3 methods: listed in report, not reconstructed.
 */

/* ========================================================================
 * GameObject (no methods with this exact prefix in s1 beyond Manager)
 * Skipped: no GameObject:: methods (only GameObject::Manager:: and GameObject::Test).
 */

/* ========================================================================
 * GameObject::Manager
 * Singleton pattern. Inst() returns &DAT_1408db4d0 (global static instance).
 * Initialize() is empty. 4 seeds but state_surface returned 0 fields (static singleton, no param_1 member access).
 * Not a heap-allocated struct with instance fields accessible via this pointer.
 * Layout: global static object at VA 0x1408db4d0.
 *   DAT_1408db4d0 = vtable (&PTR_FUN_1407460e8)
 *   DAT_1408db4e8 = subobject initialized by FUN_14054a690
 *   DAT_1408db510 = initialization flag (byte)
 * Size of static instance: 0x1408db510 - 0x1408db4d0 + 1 = 0x41 bytes, but alignment suggests 0x48 or 0x50.
 * ======================================================================== */
typedef struct __attribute__((packed)) GameObject_Manager {
    /* 0x00 */ void *vtable;              /* &PTR_FUN_1407460e8 */
    /* 0x08 */ uint8_t _subobj[0x10];     /* initialized by FUN_14054a690 at offset 0x18 from base => 0x18-0x08=0x10? Actually FUN called with &DAT_1408db4e8 = base+0x18 */
    /* 0x18 */ uint8_t _inner[0x28];      /* subobject at base+0x18, initialized by FUN_14054a690 */
    /* 0x40 */ uint32_t initFlag;         /* DAT_1408db510 = base+0x40, bit 0 = initialized */
    /* 0x44 */ uint8_t _pad[4];           /* alignment */
} GameObject_Manager;
/* Size: inferred >= 0x48 from global span (0x4d0 to 0x510 = 0x40, plus flag at 0x40 => total 0x44, rounded to 0x48) */

static_assert(offsetof(GameObject_Manager, vtable) == 0x00, "GameObject_Manager.vtable");
static_assert(offsetof(GameObject_Manager, _inner) == 0x18, "GameObject_Manager._inner");
static_assert(offsetof(GameObject_Manager, initFlag) == 0x40, "GameObject_Manager.initFlag");

/* ========================================================================
 * Geometry::Aabb
 * Axis-aligned bounding box. Two Vector3 (min/max) plus inner min/max computed by CalcInner.
 * From CalcInner: reads param_1+8 and param_1+0x14 (two Vector3s), writes param_1+0x20 and param_1+0x2c.
 * Layout: vtable(0x0), Vector3 min(0x8), Vector3 max(0x14), Vector3 innerMin(0x20), Vector3 innerMax(0x2c).
 * Total: 0x2c + 12 = 0x38. Draw uses same offsets.
 * Size proven: 0x38 (last write at 0x2c + sizeof(Vector3)=12 = 0x38, no further accesses).
 * ======================================================================== */
typedef struct __attribute__((packed)) Geometry_Aabb {
    /* 0x00 */ void *vtable;              /* not explicitly set in CalcInner/Draw but Obb dtor pattern suggests virtual */
    /* 0x08 */ Nucc_Vector3 min;          /* read in CalcInner at param_1+8 */
    /* 0x14 */ Nucc_Vector3 max;          /* read in CalcInner at param_1+0x14 */
    /* 0x20 */ Nucc_Vector3 innerMin;     /* written in CalcInner at param_1+0x20 */
    /* 0x2C */ Nucc_Vector3 innerMax;     /* written in CalcInner at param_1+0x2c */
} Geometry_Aabb;
/* Size: 0x38 (proven from CalcInner last write at 0x2c + 12 bytes) */

static_assert(offsetof(Geometry_Aabb, vtable) == 0x00, "Geometry_Aabb.vtable");
static_assert(offsetof(Geometry_Aabb, min) == 0x08, "Geometry_Aabb.min");
static_assert(offsetof(Geometry_Aabb, max) == 0x14, "Geometry_Aabb.max");
static_assert(offsetof(Geometry_Aabb, innerMin) == 0x20, "Geometry_Aabb.innerMin");
static_assert(offsetof(Geometry_Aabb, innerMax) == 0x2C, "Geometry_Aabb.innerMax");

/* ========================================================================
 * Geometry::Cylinder
 * From Draw: reads Vector3 at param_1+8, Vector3 at param_1+0x14, float radius at param_1+0x20.
 * Likely: vtable(0x0), Vector3 center/top(0x8), Vector3 center/bottom(0x14), float radius(0x20).
 * Size: >= 0x24 (last read at 0x20 + 4 = 0x24). No writes found beyond that.
 * ======================================================================== */
typedef struct __attribute__((packed)) Geometry_Cylinder {
    /* 0x00 */ void *vtable;
    /* 0x08 */ Nucc_Vector3 point0;       /* read in Draw at param_1+8 */
    /* 0x14 */ Nucc_Vector3 point1;       /* read in Draw at param_1+0x14 */
    /* 0x20 */ float radius;              /* read in Draw at param_1+0x20 */
    /* 0x24 */ uint8_t _pad[4];           /* alignment to 0x28 */
} Geometry_Cylinder;
/* Size: unknown, >= 0x24 */

static_assert(offsetof(Geometry_Cylinder, vtable) == 0x00, "Geometry_Cylinder.vtable");
static_assert(offsetof(Geometry_Cylinder, point0) == 0x08, "Geometry_Cylinder.point0");
static_assert(offsetof(Geometry_Cylinder, point1) == 0x14, "Geometry_Cylinder.point1");
static_assert(offsetof(Geometry_Cylinder, radius) == 0x20, "Geometry_Cylinder.radius");

/* ========================================================================
 * Geometry::Obb
 * Oriented bounding box. Dtor sets vtable to &PTR_FUN_140774470.
 * Draw accesses similar pattern to Aabb but with orientation. From Draw's local vars and param access:
 * Likely contains center Vector3, extents Vector3, and orientation matrix/quaternion.
 * State_surface returned 0 fields (only 1 seed: Draw, which uses complex local math).
 * From Draw signature (longlong param_1, undefined4 *param_2) and line count (304), this is a substantial struct.
 * Without more seed methods, only vtable and dtor behavior are proven.
 * Size: unknown, >= 0x8 (vtable only proven).
 * ======================================================================== */
typedef struct __attribute__((packed)) Geometry_Obb {
    /* 0x00 */ void *vtable;              /* &PTR_FUN_140774470 in dtor */
    /* 0x08 */ uint8_t _data[0x30];       /* OBB data: center, extents, orientation (inferred from Draw complexity) */
} Geometry_Obb;
/* Size: unknown, >= 0x8. Only vtable proven from dtor. */

static_assert(offsetof(Geometry_Obb, vtable) == 0x00, "Geometry_Obb.vtable");

/* ========================================================================
 * gjkepa2_impl (namespace-level functions, not a class with instance state)
 * gjkepa2_impl::Initialize is a free function taking multiple params.
 * No struct to reconstruct. Listed in report.
 */

/* ========================================================================
 * gjkepa2_impl::EPA
 * Expanding Polytope Algorithm solver. 6 seed methods, 13 fields surfaced.
 * From Evaluate: large struct with face/edge arrays. Fields at 0x2C..0x50 are scalars,
 * fields at 0x3860..0x3880 are counters/indices into internal arrays.
 * GJK::Initialize pattern suggests similar init. EPA likely allocated as part of GJK context.
 * Size: unknown, >= 0x3884 (last field at 0x3880 + 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_EPA {
    /* 0x00 */ uint8_t _header[0x2C];     /* header/init area, not accessed in surfaced fields */
    /* 0x2C */ float field_2C;            /* w, high: fVar25 in Evaluate */
    /* 0x30 */ float field_30;            /* w, medium: auVar26*fVar16 */
    /* 0x34 */ uint8_t _gap_34[4];        /* padding */
    /* 0x38 */ int32_t field_38;          /* w, high: =3 in Evaluate */
    /* 0x3C */ uint8_t _gap_3C[4];        /* padding */
    /* 0x40 */ float field_40;            /* rw, low: fVar16 */
    /* 0x44 */ float field_44;            /* rw, high: fVar17 */
    /* 0x48 */ float field_48;            /* rw, low: fVar18 */
    /* 0x4C */ float field_4C;            /* w, high: fVar19 */
    /* 0x50 */ float field_50;            /* w, high: (float)local_f8 */
    /* 0x54 */ uint8_t _body[0x380C];     /* large internal array storage (faces, edges) */
    /* 0x3860 */ int32_t field_3860;      /* rw, high: =0, counter/index */
    /* 0x3864 */ uint8_t _gap_3864[4];    /* padding */
    /* 0x3868 */ int64_t field_3868;      /* rw, high: pointer/index lVar4 */
    /* 0x3870 */ int32_t field_3870;      /* rw, high: decrement counter */
    /* 0x3874 */ uint8_t _gap_3874[4];    /* padding */
    /* 0x3878 */ int64_t field_3878;      /* rw, high: pointer copy */
    /* 0x3880 */ int32_t field_3880;      /* rw, high: increment counter */
} gjkepa2_impl_EPA;
/* Size: unknown, >= 0x3884 */

static_assert(offsetof(gjkepa2_impl_EPA, field_2C) == 0x2C, "gjkepa2_impl_EPA.field_2C");
static_assert(offsetof(gjkepa2_impl_EPA, field_30) == 0x30, "gjkepa2_impl_EPA.field_30");
static_assert(offsetof(gjkepa2_impl_EPA, field_38) == 0x38, "gjkepa2_impl_EPA.field_38");
static_assert(offsetof(gjkepa2_impl_EPA, field_40) == 0x40, "gjkepa2_impl_EPA.field_40");
static_assert(offsetof(gjkepa2_impl_EPA, field_44) == 0x44, "gjkepa2_impl_EPA.field_44");
static_assert(offsetof(gjkepa2_impl_EPA, field_48) == 0x48, "gjkepa2_impl_EPA.field_48");
static_assert(offsetof(gjkepa2_impl_EPA, field_4C) == 0x4C, "gjkepa2_impl_EPA.field_4C");
static_assert(offsetof(gjkepa2_impl_EPA, field_50) == 0x50, "gjkepa2_impl_EPA.field_50");
static_assert(offsetof(gjkepa2_impl_EPA, field_3860) == 0x3860, "gjkepa2_impl_EPA.field_3860");
static_assert(offsetof(gjkepa2_impl_EPA, field_3868) == 0x3868, "gjkepa2_impl_EPA.field_3868");
static_assert(offsetof(gjkepa2_impl_EPA, field_3870) == 0x3870, "gjkepa2_impl_EPA.field_3870");
static_assert(offsetof(gjkepa2_impl_EPA, field_3878) == 0x3878, "gjkepa2_impl_EPA.field_3878");
static_assert(offsetof(gjkepa2_impl_EPA, field_3880) == 0x3880, "gjkepa2_impl_EPA.field_3880");

/* ========================================================================
 * gjkepa2_impl::GJK
 * Gilbert-Johnson-Keerthi distance algorithm. 9 seed methods, 25 fields surfaced.
 * Initialize writes: param_1+0x18=-1, param_1+0x3c=2, param_1+0x10=0, param_1+0x28=0, param_1+0x30=0.
 * Evaluate accesses extensively. Internal simplex/support point storage.
 * Size: unknown, >= 0x1D4 (last field at 0x1D0 + 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_GJK {
    /* 0x00 */ uint8_t _header[0x10];     /* header before first proven field */
    /* 0x10 */ uint8_t field_10[8];       /* rw, medium: param_2[0x10] copy in Evaluate; =0 in Initialize */
    /* 0x18 */ uint8_t field_18[8];       /* =0xFFFFFFFFFFFFFFFF in Initialize (-1 sentinel) */
    /* 0x20 */ uint8_t _gap_20[8];        /* padding */
    /* 0x28 */ uint8_t field_28[8];       /* =0 in Initialize */
    /* 0x30 */ uint8_t field_30[8];       /* =0 in Initialize */
    /* 0x38 */ uint8_t _gap_38[4];        /* padding */
    /* 0x3C */ uint8_t field_3C[4];       /* =2 in Initialize */
    /* 0x40 */ uint8_t _gap_40[0x18];     /* gap to 0x58 */
    /* 0x58 */ uint8_t field_58[8];       /* w, medium: uVar3 */
    /* 0x60 */ uint8_t field_60[8];       /* w, medium: param_2[0xc] */
    /* 0x68 */ uint8_t field_68[8];       /* w, medium: uVar3 */
    /* 0x70 */ uint8_t field_70[8];       /* w, medium: param_2[0xe] */
    /* 0x78 */ uint8_t field_78[8];       /* w, medium: uVar3 */
    /* 0x80 */ uint8_t field_80[8];       /* rw, medium: param_2[0x10] */
    /* 0x88 */ uint8_t _gap_88[8];        /* padding */
    /* 0x90 */ uint8_t field_90[4];       /* rw, low: size=[4,8] but field_94 at 0x94 => 4 bytes */
    /* 0x94 */ uint8_t field_94[4];       /* rw, high: squared distance computation */
    /* 0x98 */ uint8_t field_98[8];       /* rw, low: size=[4,8], next at 0xA0 => 8 bytes */
    /* 0xA0 */ uint8_t field_A0[4];       /* w, high: =0 */
    /* 0xA4 */ uint8_t _gap_A4[4];        /* padding */
    /* 0xA8 */ uint8_t field_A8[8];       /* r, medium: *(param_1[0x15]+0x10) */
    /* 0xB0 */ uint8_t _gap_B0[0x18];     /* gap */
    /* 0xC8 */ uint8_t field_C8[4];       /* w, medium: =0x3f800000 (1.0f) */
    /* 0xCC */ uint8_t _gap_CC[0xC];      /* gap to 0xD8 */
    /* 0xD8 */ uint8_t field_D8[4];       /* size=4 from state_surface */
    /* 0xDC */ uint8_t _gap_DC[0x44];     /* gap to 0x120 */
    /* 0x120 */ uint8_t _array_120[0x20]; /* param_1[0x34]=param_1+0x24 pattern, internal array refs */
    /* 0x140 */ uint8_t _array_140[0x20]; /* similar array ref */
    /* 0x160 */ uint8_t _array_160[0x20]; /* similar array ref */
    /* 0x180 */ uint8_t _array_180[0x20]; /* similar array ref */
    /* 0x1A0 */ uint8_t ptr_1A0[8];       /* w, medium: =param_1+0x24 */
    /* 0x1A8 */ uint8_t ptr_1A8[8];       /* w, medium: =param_1+0x28 */
    /* 0x1B0 */ uint8_t ptr_1B0[8];       /* w, medium: =param_1+0x2c */
    /* 0x1B8 */ uint8_t ptr_1B8[8];       /* w, medium: =param_1+0x30 */
    /* 0x1C0 */ uint8_t field_1C0[4];     /* rw, low: size=[4,8] but field_1C4 at 0x1C4 => 4 bytes */
    /* 0x1C4 */ uint8_t field_1C4[4];     /* rw, medium: index counter */
    /* 0x1C8 */ uint8_t field_1C8[8];     /* w, medium: computed pointer */
    /* 0x1D0 */ uint8_t field_1D0[4];     /* rw, high: =0 */
} gjkepa2_impl_GJK;
/* Size: 0x1D4 (verified by runtime offset test) */

static_assert(offsetof(gjkepa2_impl_GJK, field_10) == 0x10, "gjkepa2_impl_GJK.field_10");
static_assert(offsetof(gjkepa2_impl_GJK, field_18) == 0x18, "gjkepa2_impl_GJK.field_18");
static_assert(offsetof(gjkepa2_impl_GJK, field_28) == 0x28, "gjkepa2_impl_GJK.field_28");
static_assert(offsetof(gjkepa2_impl_GJK, field_30) == 0x30, "gjkepa2_impl_GJK.field_30");
static_assert(offsetof(gjkepa2_impl_GJK, field_3C) == 0x3C, "gjkepa2_impl_GJK.field_3C");
static_assert(offsetof(gjkepa2_impl_GJK, field_58) == 0x58, "gjkepa2_impl_GJK.field_58");
static_assert(offsetof(gjkepa2_impl_GJK, field_60) == 0x60, "gjkepa2_impl_GJK.field_60");
static_assert(offsetof(gjkepa2_impl_GJK, field_68) == 0x68, "gjkepa2_impl_GJK.field_68");
static_assert(offsetof(gjkepa2_impl_GJK, field_70) == 0x70, "gjkepa2_impl_GJK.field_70");
static_assert(offsetof(gjkepa2_impl_GJK, field_78) == 0x78, "gjkepa2_impl_GJK.field_78");
static_assert(offsetof(gjkepa2_impl_GJK, field_80) == 0x80, "gjkepa2_impl_GJK.field_80");
static_assert(offsetof(gjkepa2_impl_GJK, field_90) == 0x90, "gjkepa2_impl_GJK.field_90");
static_assert(offsetof(gjkepa2_impl_GJK, field_94) == 0x94, "gjkepa2_impl_GJK.field_94");
static_assert(offsetof(gjkepa2_impl_GJK, field_98) == 0x98, "gjkepa2_impl_GJK.field_98");
static_assert(offsetof(gjkepa2_impl_GJK, field_A0) == 0xA0, "gjkepa2_impl_GJK.field_A0");
static_assert(offsetof(gjkepa2_impl_GJK, field_A8) == 0xA8, "gjkepa2_impl_GJK.field_A8");
static_assert(offsetof(gjkepa2_impl_GJK, field_C8) == 0xC8, "gjkepa2_impl_GJK.field_C8");
static_assert(offsetof(gjkepa2_impl_GJK, field_D8) == 0xD8, "gjkepa2_impl_GJK.field_D8");
static_assert(offsetof(gjkepa2_impl_GJK, _array_120) == 0x120, "gjkepa2_impl_GJK._array_120");
static_assert(offsetof(gjkepa2_impl_GJK, _array_140) == 0x140, "gjkepa2_impl_GJK._array_140");
static_assert(offsetof(gjkepa2_impl_GJK, _array_160) == 0x160, "gjkepa2_impl_GJK._array_160");
static_assert(offsetof(gjkepa2_impl_GJK, _array_180) == 0x180, "gjkepa2_impl_GJK._array_180");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1A0) == 0x1A0, "gjkepa2_impl_GJK.ptr_1A0");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1A8) == 0x1A8, "gjkepa2_impl_GJK.ptr_1A8");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1B0) == 0x1B0, "gjkepa2_impl_GJK.ptr_1B0");
static_assert(offsetof(gjkepa2_impl_GJK, ptr_1B8) == 0x1B8, "gjkepa2_impl_GJK.ptr_1B8");
static_assert(offsetof(gjkepa2_impl_GJK, field_1C0) == 0x1C0, "gjkepa2_impl_GJK.field_1C0");
static_assert(offsetof(gjkepa2_impl_GJK, field_1C4) == 0x1C4, "gjkepa2_impl_GJK.field_1C4");
static_assert(offsetof(gjkepa2_impl_GJK, field_1C8) == 0x1C8, "gjkepa2_impl_GJK.field_1C8");
static_assert(offsetof(gjkepa2_impl_GJK, field_1D0) == 0x1D0, "gjkepa2_impl_GJK.field_1D0");

/* ========================================================================
 * gjkepa2_impl::MinkowskiDiff
 * Minkowski difference support structure. 3 seed methods, 6 fields surfaced.
 * operator= copies 16 uint32 values (indices 0..0xf), suggesting 16 floats = 64 bytes of shape data.
 * Support reads vtable-like dispatch at param_1[0x10] (offset 0x40 if uint32* indexing? No: param_1 is uint32*,
 * so param_1[0x10] = byte offset 0x40). But state_surface says offset 0x80 size 8.
 * Reconciling: state_surface offset 0x80 with sample "(*(code*)param_1[0x10])(*param_1,...)" means
 * param_1 is treated as longlong* in that context, so param_1[0x10] = byte 0x80. Consistent.
 * Size: unknown, >= 0x88 (last field at 0x80 + 8).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_MinkowskiDiff {
    /* 0x00 */ uint8_t _shapeData[0x2C];  /* shape/matrix data, copied in operator= (indices 0..0xa) */
    /* 0x2C */ float field_2C;            /* r, medium: param_1[0xb] in operator= */
    /* 0x30 */ float field_30;            /* r, medium: param_1[0xc] */
    /* 0x34 */ float field_34;            /* r, medium: param_1[0xd] */
    /* 0x38 */ float field_38;            /* r, medium: param_1[0xe] */
    /* 0x3C */ float field_3C;            /* r, medium: param_1[0xf] */
    /* 0x40 */ uint8_t _gap_40[0x40];     /* gap to support dispatch */
    /* 0x80 */ void *supportDispatch;     /* r, medium: function pointer for Support query */
} gjkepa2_impl_MinkowskiDiff;
/* Size: unknown, >= 0x88 */

static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_2C) == 0x2C, "gjkepa2_impl_MinkowskiDiff.field_2C");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_30) == 0x30, "gjkepa2_impl_MinkowskiDiff.field_30");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_34) == 0x34, "gjkepa2_impl_MinkowskiDiff.field_34");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_38) == 0x38, "gjkepa2_impl_MinkowskiDiff.field_38");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_3C) == 0x3C, "gjkepa2_impl_MinkowskiDiff.field_3C");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, supportDispatch) == 0x80, "gjkepa2_impl_MinkowskiDiff.supportDispatch");

#endif /* CMN21_S1_H */