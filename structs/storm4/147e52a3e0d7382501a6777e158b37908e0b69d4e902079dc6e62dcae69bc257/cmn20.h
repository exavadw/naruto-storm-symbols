/*
 * cmn20 s4 — struct layouts (INFERRED, not CONFIRMED)
 * Build: s4 (NSUNS4_release.exe, PC x64, image base 0x140000000)
 * Source: the decompiler cache state_surface + constructor/initialize pseudocode
 * Sizes are unproven unless noted; no sizeof asserts on incomplete structs.
 * All offsets from this PC build only. Names from Storm 4 symbols/strings only.
 */

#include <stdint.h>
#include <stddef.h>

/* ---- GameActor::Base ----
 * Base class: ccTaskBase (inherited, layout unknown here)
 * Vtable: PTR_FUN_1411151d8 (final, set at end of Base ctor RVA 0xAC2E40)
 * Initial vtable during ctor: PTR_FUN_1411156d8
 * Size: unknown, >= 0x90 (last proven field at 0x88, size 8)
 * Surface also saw fields at 0x208+ from DeleteComponents;
 * those are embedded sub-object cleanup sites, not scalar Base fields.
 */
#pragma pack(push,1)
typedef struct ns4_GameActor_Base {
/* 0x00 */ void *vtable;
/* 0x08..0x3F: ccTaskBase body (not reconstructed here) */
uint8_t _pad_ccTaskBase[0x38];
/* 0x40 */ int32_t field_40; /* *(undefined4 *)(param_1 + 8) = uVar1; 8*8=0x40 */
/* 0x44 */ uint8_t _pad_44[0x04];
/* 0x48 */ void *nummModelManager; /* FUN_140ac4100(param_1 + 9); 9*8=0x48 */
/* 0x50 */ uint8_t _pad_50[0x20];
/* 0x70 */ float position_x; /* Nucc::Vector3::Vector3(param_1 + 0xe); 0xe*8=0x70 */
/* 0x74 */ float position_y;
/* 0x78 */ float position_z;
/* 0x7C */ int32_t field_7C; /* *(undefined8 *)((longlong)param_1 + 0x7c) = 0 (writes 8 bytes but only lower 4 meaningful) */
/* 0x80 */ int32_t componentCount; /* surface rw4 from AddComponent/CreateVisibleVolume/etc */
/* 0x84 */ int32_t field_84; /* *(undefined4 *)((longlong)param_1 + 0x84) = 0 */
/* 0x88 */ void *componentList; /* param_1[0x11] = 0 in ctor; 0x11*8=0x88 */
} ns4_GameActor_Base;
#pragma pack(pop)

_Static_assert(offsetof(ns4_GameActor_Base, vtable) == 0x00, "GameActor::Base vtable");
_Static_assert(offsetof(ns4_GameActor_Base, field_40) == 0x40, "GameActor::Base field_40");
_Static_assert(offsetof(ns4_GameActor_Base, nummModelManager) == 0x48, "GameActor::Base nummModelManager");
_Static_assert(offsetof(ns4_GameActor_Base, position_x) == 0x70, "GameActor::Base position_x");
_Static_assert(offsetof(ns4_GameActor_Base, position_y) == 0x74, "GameActor::Base position_y");
_Static_assert(offsetof(ns4_GameActor_Base, position_z) == 0x78, "GameActor::Base position_z");
_Static_assert(offsetof(ns4_GameActor_Base, field_7C) == 0x7C, "GameActor::Base field_7C");
_Static_assert(offsetof(ns4_GameActor_Base, componentCount) == 0x80, "GameActor::Base componentCount");
_Static_assert(offsetof(ns4_GameActor_Base, field_84) == 0x84, "GameActor::Base field_84");
_Static_assert(offsetof(ns4_GameActor_Base, componentList) == 0x88, "GameActor::Base componentList");

/* ---- Framework ----
 * Base class: Nucc::Memory::BlockAllocator (inherited, layout unknown here)
 * Vtable: not found in s4 symbol table (no explicit vtable symbol; likely set by parent ctor)
 * Size: unknown, >= 0x118 (highest proven write at 0x114, size 4 -> next aligned = 0x118)
 * Evidence: Framework::Initialize (RVA 0xAB8070) writes pointer fields at 0x48..0xC8
 * and a uint32 at 0x114. No ctor found in s4 symbol table.
 */
#pragma pack(push,1)
typedef struct ns4_Framework {
/* 0x00 */ void *vtable;
/* 0x08..0x47: BlockAllocator body (not reconstructed here) */
uint8_t _pad_BlockAllocator[0x40];
/* 0x48 */ void *sceneManager; /* operator_new(0x1458) -> ccSceneManager::ccSceneManager */
/* 0x50 */ void *field_50; /* operator_new(0x158) -> FUN_140abe000 */
/* 0x58 */ void *field_58; /* operator_new(0x50) -> FUN_140ab7440 */
/* 0x60 */ void *field_60; /* operator_new(0x20) -> FUN_140ad9680 */
/* 0x68 */ void *field_68; /* operator_new(0x10) -> FUN_140ae7030 */
/* 0x70 */ void *saveManager; /* operator_new(0x20) -> FUN_140aedd40; ccSaveManager::Initialize */
/* 0x78 */ void *field_78; /* operator_new(0xe0) -> FUN_140ab8d50 */
/* 0x80 */ void *field_80; /* operator_new(0x10) -> FUN_140af25e0 */
/* 0x88 */ void *field_88; /* operator_new(0x10) -> FUN_140ae8480 */
/* 0x90 */ void *field_90; /* operator_new(0x28) -> FUN_140abc5d0 */
/* 0x98 */ void *field_98; /* operator_new(0x58) -> FUN_140ae0240 */
/* 0xA0 */ void *xfbinDocManager; /* operator_new(0x3f8) -> FUN_140ada6c0; ccXfbinDocManagerForUi::Initialize */
/* 0xA8 */ void *uiManager; /* operator_new(0x1d0) -> ccUiManager::ccUiManager; ccUiManager::Initialize */
/* 0xB0 */ void *cmnFade; /* operator_new(0x60) -> ccCmnFade::ccCmnFade; ccCmnFade::Initialize */
/* 0xB8 */ void *field_B8; /* operator_new(0x68) -> FUN_140ae3c40 */
/* 0xC0 */ void *field_C0; /* operator_new(0x28) -> FUN_140b16000 */
/* 0xC8 */ void *field_C8; /* operator_new(8) -> FUN_140af1600 */
/* 0xD0..0x113: gap (no proven accesses) */
uint8_t _pad_D0[0x44];
/* 0x114 */ int32_t field_114; /* *(undefined4 *)(param_1 + 0x114) = 0 */
} ns4_Framework;
#pragma pack(pop)

_Static_assert(offsetof(ns4_Framework, vtable) == 0x00, "Framework vtable");
_Static_assert(offsetof(ns4_Framework, _pad_BlockAllocator) == 0x08, "Framework _pad_BlockAllocator");
_Static_assert(offsetof(ns4_Framework, sceneManager) == 0x48, "Framework sceneManager");
_Static_assert(offsetof(ns4_Framework, field_50) == 0x50, "Framework field_50");
_Static_assert(offsetof(ns4_Framework, field_58) == 0x58, "Framework field_58");
_Static_assert(offsetof(ns4_Framework, field_60) == 0x60, "Framework field_60");
_Static_assert(offsetof(ns4_Framework, field_68) == 0x68, "Framework field_68");
_Static_assert(offsetof(ns4_Framework, saveManager) == 0x70, "Framework saveManager");
_Static_assert(offsetof(ns4_Framework, field_78) == 0x78, "Framework field_78");
_Static_assert(offsetof(ns4_Framework, field_80) == 0x80, "Framework field_80");
_Static_assert(offsetof(ns4_Framework, field_88) == 0x88, "Framework field_88");
_Static_assert(offsetof(ns4_Framework, field_90) == 0x90, "Framework field_90");
_Static_assert(offsetof(ns4_Framework, field_98) == 0x98, "Framework field_98");
_Static_assert(offsetof(ns4_Framework, xfbinDocManager) == 0xA0, "Framework xfbinDocManager");
_Static_assert(offsetof(ns4_Framework, uiManager) == 0xA8, "Framework uiManager");
_Static_assert(offsetof(ns4_Framework, cmnFade) == 0xB0, "Framework cmnFade");
_Static_assert(offsetof(ns4_Framework, field_B8) == 0xB8, "Framework field_B8");
_Static_assert(offsetof(ns4_Framework, field_C0) == 0xC0, "Framework field_C0");
_Static_assert(offsetof(ns4_Framework, field_C8) == 0xC8, "Framework field_C8");
_Static_assert(offsetof(ns4_Framework, _pad_D0) == 0xD0, "Framework _pad_D0");
_Static_assert(offsetof(ns4_Framework, field_114) == 0x114, "Framework field_114");

/* ---- eastl ----
 * eastl: no instance state
 * Non-template methods are free functions operating on node pointers, not member
 * functions with a this pointer. Template instantiations yield incoherent scattered
 * offsets that cannot be assembled into a single struct.
 * Evidence (s4 RVAs):
 * eastl::RBTreeDecrement 0x17C4F0 signature: undefined8*(undefined8* param_1)
 * eastl::RBTreeIncrement 0x9E9790 signature: undefined4(undefined8, longlong, longlong)
 * eastl::RBTreeInsert 0x17C610 signature: void(longlong*, undefined8*, undefined8*, int)
 * eastl::prime_rehash_policy::GetRehashRequired 0x17C380
 * state_surface: 50 seeds analyzed, 26 fields returned but all from disparate
 * template instantiations (hashtable, rbtree, vector, hash_map) with unknown sizes
 * and no coherent layout.
 */

/* ---- eastl::allocator ----
 * eastl::allocator: no instance state
 * Stateless allocator class. deallocate takes (param_1, param_2) but state_surface
 * found 0 accesses on param_1 across all 4 seed instances, confirming the allocator
 * object carries no mutable state.
 * Evidence (s4 RVAs):
 * eastl::allocator::deallocate 0x185C20 (also at 0x75917C, 0x87BCD0, 0x9EA2F0)
 * state_surface: 4 seeds, 0 accesses each
 */

/*
 * Classes with 0 proven fields or < 3 methods (no struct emitted):
 * - DebugDrawcallback: 4 methods, 0 fields from surface
 * - dm: 4 methods, 0 fields from surface
 * - DName: 1 method (< 3, skipped per threshold)
 * - dtNavMesh: 11 methods, 0 fields from surface (all seeds: unknown param_1 element size)
 * - dtTileCache: 4 methods, 0 fields from surface (all seeds: unknown param_1 element size)
 * - eastl::prime_rehash_policy: < 3 methods (skipped)
 * - fwccDtTileCacheAlloc: 2 methods (< 3, skipped per threshold)
 * These are listed in cmn20-REPORT.md.
 */