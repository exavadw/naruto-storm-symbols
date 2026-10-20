/*
 * cmn21.h - Common struct group cmn21 for NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, build s3)
 *
 * All layouts are INFERRED from static analysis (decompiled code, state_surface).
 * No runtime confirmation. Sizes proven from ctor/allocator where possible;
 * otherwise marked "size unknown, >= 0xN".
 *
 * Own-game names only: Storm 3 (s3) symbols/strings/code.
 * PC offsets only: derived from x64 decompile (image base 0x140000000).
 */

#ifndef CMN21_S3_H
#define CMN21_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * GameActor::Base
 * Vtable at offset 0x0 set to PTR_FUN_1409eb650 initially, then PTR_FUN_1409eb678 finally.
 * Inherits ccTaskBase subobject. Vector3 at param_1+0xe (offset 0x70).
 * Layout from ctor + state_surface (8 fields). Largest offset 0x1C0 => size >= 0x1C8.
 * ======================================================================== */
typedef struct __attribute__((packed)) GameActor_Base {
/* 0x0000 */ void *vtable; /* initial: PTR_FUN_1409eb650, final: PTR_FUN_1409eb678 */
/* 0x0008 */ uint8_t _ccTaskBase[0x68]; /* inherited ccTaskBase subobject (ctor calls ccTaskBase::ccTaskBase) */
/* 0x0070 */ uint8_t _vector3[0xC]; /* Nucc::Vector3 at param_1+0xe = byte 0x70 */
/* 0x007C */ uint64_t field_7C; /* zeroed in ctor as *(undefined8*)(param_1+0x7c)=0 */
/* 0x0084 */ uint32_t field_84; /* zeroed in ctor as *(undefined4*)(param_1+0x84)=0 */
/* 0x0088 */ uint64_t field_88; /* rw, high conf from state_surface */
/* 0x0090 */ uint8_t _gap_90[0x130]; /* gap to 0x1C0 */
/* 0x01C0 */ uint64_t field_1C0; /* read via vfunc dispatch in SetPositionNew */
} GameActor_Base;
/* Size: unknown, >= 0x1C8 (last field at 0x1C0 + 8) */

static_assert(offsetof(GameActor_Base, vtable) == 0x0000, "GameActor_Base.vtable");
static_assert(offsetof(GameActor_Base, _ccTaskBase) == 0x0008, "GameActor_Base._ccTaskBase");
static_assert(offsetof(GameActor_Base, _vector3) == 0x0070, "GameActor_Base._vector3");
static_assert(offsetof(GameActor_Base, field_7C) == 0x007C, "GameActor_Base.field_7C");
static_assert(offsetof(GameActor_Base, field_84) == 0x0084, "GameActor_Base.field_84");
static_assert(offsetof(GameActor_Base, field_88) == 0x0088, "GameActor_Base.field_88");
static_assert(offsetof(GameActor_Base, _gap_90) == 0x0090, "GameActor_Base._gap_90");
static_assert(offsetof(GameActor_Base, field_1C0) == 0x01C0, "GameActor_Base.field_1C0");

/* ========================================================================
 * GameActor::Component
 * Vtable at 0x0 set to PTR_FUN_1409daf00 initially, then PTR_FUN_1409ec9f8 finally.
 * BlockAllocator subobject at param_1+1 (offset 0x08). Owner handle at param_1[4] = offset 0x20.
 * Layout from ctor symbolized decompile (state_surface returned 0 fields).
 * Size: unknown, >= 0x28.
 * ======================================================================== */
typedef struct __attribute__((packed)) GameActor_Component {
/* 0x00 */ void *vtable; /* final: &PTR_FUN_1409ec9f8 */
/* 0x08 */ uint8_t _blockAlloc[0x10]; /* BlockAllocator subobject at param_1+1 */
/* 0x18 */ void *field_18; /* PTR_LAB_1409eca00 set in ctor */
/* 0x20 */ void *owner; /* param_1[4] = owner handle */
} GameActor_Component;
/* Size: unknown, >= 0x28 */

static_assert(offsetof(GameActor_Component, vtable) == 0x00, "GameActor_Component.vtable");
static_assert(offsetof(GameActor_Component, _blockAlloc) == 0x08, "GameActor_Component._blockAlloc");
static_assert(offsetof(GameActor_Component, field_18) == 0x18, "GameActor_Component.field_18");
static_assert(offsetof(GameActor_Component, owner) == 0x20, "GameActor_Component.owner");

/* ========================================================================
 * GameObject::Manager
 * Singleton at DAT_140c7bff0. Vtable PTR_FUN_1409ec1f8.
 * List iteration at param_1+0x18 in Exist/GetBase. Container at 0x68, flag at 0x70.
 * Layout from Inst/Exist/GetBase/Remove symbolized decompiles (state_surface returned 0).
 * Size: unknown, >= 0x74.
 * ======================================================================== */
typedef struct __attribute__((packed)) GameObject_Manager {
/* 0x00 */ void *vtable; /* &PTR_FUN_1409ec1f8 */
/* 0x08 */ uint8_t _subobj[0x10]; /* initialized subobject */
/* 0x18 */ uint64_t list_head; /* list iteration target in Exist/GetBase */
/* 0x20 */ uint8_t _inner[0x48]; /* inner data up to container */
/* 0x68 */ uint64_t container; /* passed to destroy in Remove */
/* 0x70 */ uint32_t flag; /* written =1 in Remove */
} GameObject_Manager;
/* Size: unknown, >= 0x74 */

static_assert(offsetof(GameObject_Manager, vtable) == 0x00, "GameObject_Manager.vtable");
static_assert(offsetof(GameObject_Manager, _subobj) == 0x08, "GameObject_Manager._subobj");
static_assert(offsetof(GameObject_Manager, list_head) == 0x18, "GameObject_Manager.list_head");
static_assert(offsetof(GameObject_Manager, _inner) == 0x20, "GameObject_Manager._inner");
static_assert(offsetof(GameObject_Manager, container) == 0x68, "GameObject_Manager.container");
static_assert(offsetof(GameObject_Manager, flag) == 0x70, "GameObject_Manager.flag");

/* ========================================================================
 * gjkepa2_impl::EPA
 * Expanding Polytope Algorithm solver. 13 fields surfaced from state_surface.
 * Fields at 0x2C..0x50 are scalars; fields at 0x3860..0x3880 are counters/indices.
 * Size: unknown, >= 0x3884 (last field at 0x3880 + 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_EPA {
/* 0x0000 */ uint8_t _header[0x2C]; /* header/init area */
/* 0x002C */ float field_2C; /* high conf, write-only in Evaluate */
/* 0x0030 */ float field_30; /* medium conf, write-only */
/* 0x0034 */ uint8_t _gap_34[4]; /* padding */
/* 0x0038 */ int32_t field_38; /* high conf, write-only */
/* 0x003C */ uint8_t _gap_3C[4]; /* padding */
/* 0x0040 */ float field_40; /* low conf, rw */
/* 0x0044 */ float field_44; /* high conf, rw */
/* 0x0048 */ float field_48; /* low conf, rw */
/* 0x004C */ float field_4C; /* high conf, write-only */
/* 0x0050 */ float field_50; /* high conf, write-only */
/* 0x0054 */ uint8_t _body[0x380C]; /* large internal array storage */
/* 0x3860 */ int32_t field_3860; /* high conf, rw counter/index */
/* 0x3864 */ uint8_t _gap_3864[4]; /* padding */
/* 0x3868 */ int64_t field_3868; /* high conf, rw */
/* 0x3870 */ int32_t field_3870; /* high conf, rw */
/* 0x3874 */ uint8_t _gap_3874[4]; /* padding */
/* 0x3878 */ int64_t field_3878; /* high conf, rw */
/* 0x3880 */ int32_t field_3880; /* high conf, rw */
} gjkepa2_impl_EPA;
/* Size: unknown, >= 0x3884 */

static_assert(offsetof(gjkepa2_impl_EPA, _header) == 0x0000, "gjkepa2_impl_EPA._header");
static_assert(offsetof(gjkepa2_impl_EPA, field_2C) == 0x002C, "gjkepa2_impl_EPA.field_2C");
static_assert(offsetof(gjkepa2_impl_EPA, field_30) == 0x0030, "gjkepa2_impl_EPA.field_30");
static_assert(offsetof(gjkepa2_impl_EPA, _gap_34) == 0x0034, "gjkepa2_impl_EPA._gap_34");
static_assert(offsetof(gjkepa2_impl_EPA, field_38) == 0x0038, "gjkepa2_impl_EPA.field_38");
static_assert(offsetof(gjkepa2_impl_EPA, _gap_3C) == 0x003C, "gjkepa2_impl_EPA._gap_3C");
static_assert(offsetof(gjkepa2_impl_EPA, field_40) == 0x0040, "gjkepa2_impl_EPA.field_40");
static_assert(offsetof(gjkepa2_impl_EPA, field_44) == 0x0044, "gjkepa2_impl_EPA.field_44");
static_assert(offsetof(gjkepa2_impl_EPA, field_48) == 0x0048, "gjkepa2_impl_EPA.field_48");
static_assert(offsetof(gjkepa2_impl_EPA, field_4C) == 0x004C, "gjkepa2_impl_EPA.field_4C");
static_assert(offsetof(gjkepa2_impl_EPA, field_50) == 0x0050, "gjkepa2_impl_EPA.field_50");
static_assert(offsetof(gjkepa2_impl_EPA, _body) == 0x0054, "gjkepa2_impl_EPA._body");
static_assert(offsetof(gjkepa2_impl_EPA, field_3860) == 0x3860, "gjkepa2_impl_EPA.field_3860");
static_assert(offsetof(gjkepa2_impl_EPA, _gap_3864) == 0x3864, "gjkepa2_impl_EPA._gap_3864");
static_assert(offsetof(gjkepa2_impl_EPA, field_3868) == 0x3868, "gjkepa2_impl_EPA.field_3868");
static_assert(offsetof(gjkepa2_impl_EPA, field_3870) == 0x3870, "gjkepa2_impl_EPA.field_3870");
static_assert(offsetof(gjkepa2_impl_EPA, _gap_3874) == 0x3874, "gjkepa2_impl_EPA._gap_3874");
static_assert(offsetof(gjkepa2_impl_EPA, field_3878) == 0x3878, "gjkepa2_impl_EPA.field_3878");
static_assert(offsetof(gjkepa2_impl_EPA, field_3880) == 0x3880, "gjkepa2_impl_EPA.field_3880");

/* ========================================================================
 * gjkepa2_impl::GJK
 * Gilbert-Johnson-Keerthi distance algorithm. 25 fields surfaced.
 * Internal simplex/support point storage. Arrays at 0x120/0x140/0x160/0x180.
 * Size: unknown, >= 0x1D4 (last field at 0x1D0 + 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_GJK {
/* 0x000 */ uint8_t _header[0x58]; /* header before first surfaced field */
/* 0x058 */ uint64_t field_58; /* medium conf, write-only */
/* 0x060 */ uint64_t field_60; /* medium conf, write-only */
/* 0x068 */ uint64_t field_68; /* medium conf, write-only */
/* 0x070 */ uint64_t field_70; /* medium conf, write-only */
/* 0x078 */ uint64_t field_78; /* medium conf, write-only */
/* 0x080 */ uint64_t field_80; /* medium conf, rw */
/* 0x088 */ uint8_t _gap_88[8]; /* padding */
/* 0x090 */ uint32_t field_90; /* low conf, rw */
/* 0x094 */ uint32_t field_94; /* high conf, rw */
/* 0x098 */ uint64_t field_98; /* low conf, rw */
/* 0x0A0 */ uint32_t field_A0; /* high conf, write-only */
/* 0x0A4 */ uint8_t _gap_A4[4]; /* padding */
/* 0x0A8 */ uint64_t field_A8; /* medium conf, read-only */
/* 0x0B0 */ uint8_t _gap_B0[0x18]; /* gap */
/* 0x0C8 */ uint32_t field_C8; /* medium conf, write-only */
/* 0x0CC */ uint8_t _gap_CC[0xC]; /* gap */
/* 0x0D8 */ uint32_t field_D8; /* high conf, rw */
/* 0x0DC */ uint8_t _gap_DC[0x44]; /* gap */
/* 0x120 */ uint8_t _array_120[0x20]; /* internal array ref */
/* 0x140 */ uint8_t _array_140[0x20]; /* internal array ref */
/* 0x160 */ uint8_t _array_160[0x20]; /* internal array ref */
/* 0x180 */ uint8_t _array_180[0x20]; /* internal array ref */
/* 0x1A0 */ uint64_t ptr_1A0; /* medium conf, write-only */
/* 0x1A8 */ uint64_t ptr_1A8; /* medium conf, write-only */
/* 0x1B0 */ uint64_t ptr_1B0; /* medium conf, write-only */
/* 0x1B8 */ uint64_t ptr_1B8; /* medium conf, write-only */
/* 0x1C0 */ uint32_t field_1C0; /* low conf, rw */
/* 0x1C4 */ uint32_t field_1C4; /* medium conf, rw */
/* 0x1C8 */ uint64_t field_1C8; /* medium conf, write-only */
/* 0x1D0 */ uint32_t field_1D0; /* high conf, rw */
} gjkepa2_impl_GJK;
/* Size: unknown, >= 0x1D4 */

static_assert(offsetof(gjkepa2_impl_GJK, _header) == 0x000, "gjkepa2_impl_GJK._header");
static_assert(offsetof(gjkepa2_impl_GJK, field_58) == 0x058, "gjkepa2_impl_GJK.field_58");
static_assert(offsetof(gjkepa2_impl_GJK, field_60) == 0x060, "gjkepa2_impl_GJK.field_60");
static_assert(offsetof(gjkepa2_impl_GJK, field_68) == 0x068, "gjkepa2_impl_GJK.field_68");
static_assert(offsetof(gjkepa2_impl_GJK, field_70) == 0x070, "gjkepa2_impl_GJK.field_70");
static_assert(offsetof(gjkepa2_impl_GJK, field_78) == 0x078, "gjkepa2_impl_GJK.field_78");
static_assert(offsetof(gjkepa2_impl_GJK, field_80) == 0x080, "gjkepa2_impl_GJK.field_80");
static_assert(offsetof(gjkepa2_impl_GJK, _gap_88) == 0x088, "gjkepa2_impl_GJK._gap_88");
static_assert(offsetof(gjkepa2_impl_GJK, field_90) == 0x090, "gjkepa2_impl_GJK.field_90");
static_assert(offsetof(gjkepa2_impl_GJK, field_94) == 0x094, "gjkepa2_impl_GJK.field_94");
static_assert(offsetof(gjkepa2_impl_GJK, field_98) == 0x098, "gjkepa2_impl_GJK.field_98");
static_assert(offsetof(gjkepa2_impl_GJK, field_A0) == 0x0A0, "gjkepa2_impl_GJK.field_A0");
static_assert(offsetof(gjkepa2_impl_GJK, _gap_A4) == 0x0A4, "gjkepa2_impl_GJK._gap_A4");
static_assert(offsetof(gjkepa2_impl_GJK, field_A8) == 0x0A8, "gjkepa2_impl_GJK.field_A8");
static_assert(offsetof(gjkepa2_impl_GJK, _gap_B0) == 0x0B0, "gjkepa2_impl_GJK._gap_B0");
static_assert(offsetof(gjkepa2_impl_GJK, field_C8) == 0x0C8, "gjkepa2_impl_GJK.field_C8");
static_assert(offsetof(gjkepa2_impl_GJK, _gap_CC) == 0x0CC, "gjkepa2_impl_GJK._gap_CC");
static_assert(offsetof(gjkepa2_impl_GJK, field_D8) == 0x0D8, "gjkepa2_impl_GJK.field_D8");
static_assert(offsetof(gjkepa2_impl_GJK, _gap_DC) == 0x0DC, "gjkepa2_impl_GJK._gap_DC");
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
 * Minkowski difference support function holder. 6 fields surfaced.
 * Five float params at 0x2C..0x3C, supportDispatch ptr at 0x80.
 * Size: unknown, >= 0x88 (last field at 0x80 + 8).
 * ======================================================================== */
typedef struct __attribute__((packed)) gjkepa2_impl_MinkowskiDiff {
/* 0x00 */ uint8_t _header[0x2C]; /* header/init area */
/* 0x2C */ float field_2C; /* high conf, rw */
/* 0x30 */ float field_30; /* high conf, rw */
/* 0x34 */ float field_34; /* high conf, rw */
/* 0x38 */ float field_38; /* high conf, rw */
/* 0x3C */ float field_3C; /* high conf, rw */
/* 0x40 */ uint8_t _gap_40[0x40]; /* gap to supportDispatch */
/* 0x80 */ void *supportDispatch; /* high conf, rw, function pointer */
} gjkepa2_impl_MinkowskiDiff;
/* Size: unknown, >= 0x88 */

static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, _header) == 0x00, "gjkepa2_impl_MinkowskiDiff._header");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_2C) == 0x2C, "gjkepa2_impl_MinkowskiDiff.field_2C");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_30) == 0x30, "gjkepa2_impl_MinkowskiDiff.field_30");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_34) == 0x34, "gjkepa2_impl_MinkowskiDiff.field_34");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_38) == 0x38, "gjkepa2_impl_MinkowskiDiff.field_38");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, field_3C) == 0x3C, "gjkepa2_impl_MinkowskiDiff.field_3C");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, _gap_40) == 0x40, "gjkepa2_impl_MinkowskiDiff._gap_40");
static_assert(offsetof(gjkepa2_impl_MinkowskiDiff, supportDispatch) == 0x80, "gjkepa2_impl_MinkowskiDiff.supportDispatch");

#endif /* CMN21_S3_H */