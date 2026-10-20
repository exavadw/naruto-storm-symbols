/*
 * cmn20 s2 — struct layouts (INFERRED, not CONFIRMED)
 * Build: s2 (NSUNS2.exe, PC x64, image base 0x140000000)
 * Source: the decompiler cache state_surface + constructor pseudocode
 * Sizes are unproven unless noted; no sizeof asserts on incomplete structs.
 * All offsets from this PC build only. Names from Storm 2 (ns2::/strings) only.
 */

#include <stdint.h>
#include <stddef.h>

/* ---- GameActor::Base ----
 * Base class: ccTaskBase (inherited, layout unknown here)
 * Vtable: PTR_FUN_14089e268 (final, set at end of Base ctor RVA 0x641E60)
 * Initial vtable during ctor: PTR_FUN_14089de48
 * Size: unknown, >= 0x90 (last proven field at 0x88, size 8)
 * Surface also saw fields at 0x218+ from DeleteComponents (RVA 0x374758);
 * those are embedded sub-object cleanup sites, not scalar Base fields.
 * Fields 0x58, 0x70, 0x7C, 0x80, 0x84, 0x88 confirmed from both ctor and surface.
 */
#pragma pack(push,1)
typedef struct ns2_GameActor_Base {
    /* 0x00 */ void *vtable;
    /* 0x08..0x3F: ccTaskBase body (not reconstructed here) */
    uint8_t _pad_ccTaskBase[0x38];
    /* 0x40 */ int32_t field_40;           /* *(undefined4 *)(param_1 + 8) = uVar1; 8*8=0x40 */
    /* 0x44 */ uint8_t _pad_44[0x04];
    /* 0x48 */ void *nummModelManager;     /* FUN_140643120(param_1 + 9); 9*8=0x48 */
    /* 0x50 */ uint8_t _pad_50[0x08];
    /* 0x58 */ void *blockAllocator;       /* surface: param_1[0xb] in RemoveComponent/~TestActor; 0xb*8=0x58 */
    /* 0x60 */ uint8_t _pad_60[0x10];
    /* 0x70 */ float position_x;           /* FUN_140580a40(param_1 + 0xe); 0xe*8=0x70; SetPositionNew writes here */
    /* 0x74 */ float position_y;
    /* 0x78 */ float position_z;           /* *(int *)(param_1 + 0xf) = (int)param_2[1]; 0xf*8=0x78 */
    /* 0x7C */ int32_t field_7C;           /* *(undefined4 *)((longlong)param_1 + 0x7c) = 0 */
    /* 0x80 */ int32_t componentCount;     /* surface rw4 from AddComponent/CreateVisibleVolume/etc */
    /* 0x84 */ int32_t field_84;           /* *(undefined4 *)((longlong)param_1 + 0x84) = 0 */
    /* 0x88 */ void *componentList;        /* param_1[0x11] = 0 in ctor; 0x11*8=0x88 */
} ns2_GameActor_Base;
#pragma pack(pop)

_Static_assert(offsetof(ns2_GameActor_Base, vtable) == 0x00, "GameActor::Base vtable");
_Static_assert(offsetof(ns2_GameActor_Base, _pad_ccTaskBase) == 0x08, "GameActor::Base _pad_ccTaskBase");
_Static_assert(offsetof(ns2_GameActor_Base, field_40) == 0x40, "GameActor::Base field_40");
_Static_assert(offsetof(ns2_GameActor_Base, _pad_44) == 0x44, "GameActor::Base _pad_44");
_Static_assert(offsetof(ns2_GameActor_Base, nummModelManager) == 0x48, "GameActor::Base nummModelManager");
_Static_assert(offsetof(ns2_GameActor_Base, _pad_50) == 0x50, "GameActor::Base _pad_50");
_Static_assert(offsetof(ns2_GameActor_Base, blockAllocator) == 0x58, "GameActor::Base blockAllocator");
_Static_assert(offsetof(ns2_GameActor_Base, _pad_60) == 0x60, "GameActor::Base _pad_60");
_Static_assert(offsetof(ns2_GameActor_Base, position_x) == 0x70, "GameActor::Base position_x");
_Static_assert(offsetof(ns2_GameActor_Base, position_y) == 0x74, "GameActor::Base position_y");
_Static_assert(offsetof(ns2_GameActor_Base, position_z) == 0x78, "GameActor::Base position_z");
_Static_assert(offsetof(ns2_GameActor_Base, field_7C) == 0x7C, "GameActor::Base field_7C");
_Static_assert(offsetof(ns2_GameActor_Base, componentCount) == 0x80, "GameActor::Base componentCount");
_Static_assert(offsetof(ns2_GameActor_Base, field_84) == 0x84, "GameActor::Base field_84");
_Static_assert(offsetof(ns2_GameActor_Base, componentList) == 0x88, "GameActor::Base componentList");

/* ---- Framework ----
 * Base class: Nucc::Memory::BlockAllocator (inherited, layout unknown here)
 * Vtable: PTR_FUN_14079fdc8 (set in ctor RVA 0x1EC4A4)
 * HullDesc embedded at +0x3C (size unknown; treated as opaque blob until +0x60)
 * memset(param_1 + 0xc, 0, 0x28) proves 0x28 bytes from +0x60 are valid
 * Size: unknown, >= 0xAC (last proven write at 0xA8, size 4 → next aligned = 0xAC)
 */
#pragma pack(push,1)
typedef struct ns2_Framework {
    /* 0x00 */ void *vtable;
    /* 0x08..0x1F: BlockAllocator body (not reconstructed here) */
    uint8_t _pad_BlockAllocator[0x18];
    /* 0x20 */ void *field_20;             /* param_1[4] = 0; 4*8=0x20 */
    /* 0x28 */ void *field_28;             /* param_1[5] = 0; 5*8=0x28 */
    /* 0x30 */ uint8_t _pad_30[0x04];
    /* 0x34 */ int32_t field_34;           /* *(undefined4 *)((longlong)param_1 + 0x34) = 0 */
    /* 0x38 */ int32_t field_38;           /* *(undefined4 *)(param_1 + 7) = 0; 7*8=0x38 */
    /* 0x3C */ uint8_t hullDesc[0x24];     /* FUN_1401ebe94((longlong)param_1 + 0x3c); HullDesc init */
    /* 0x60 */ uint8_t memsetRegion[0x28]; /* memset(param_1 + 0xc, 0, 0x28); 0xc*8=0x60, len=0x28 */
    /* 0x88 */ int32_t field_88;           /* *(undefined4 *)(param_1 + 0x11) = 0; 0x11*8=0x88 */
    /* 0x8C */ uint8_t _pad_8C[0x04];
    /* 0x90 */ int64_t field_90;           /* param_1[0x12] = 0; 0x12*8=0x90 */
    /* 0x98 */ uint8_t _pad_98[0x04];
    /* 0x9C */ int32_t field_9C;           /* *(undefined4 *)((longlong)param_1 + 0x9c) = 0 */
    /* 0xA0 */ int32_t field_A0;           /* *(undefined4 *)(param_1 + 0x14) = 0; 0x14*8=0xA0 */
    /* 0xA4 */ int32_t field_A4;           /* *(undefined4 *)((longlong)param_1 + 0xa4) = 0xffffffff */
    /* 0xA8 */ int32_t field_A8;           /* *(undefined4 *)(param_1 + 0x15) = 0; 0x15*8=0xA8 */
} ns2_Framework;
#pragma pack(pop)

_Static_assert(offsetof(ns2_Framework, vtable) == 0x00, "Framework vtable");
_Static_assert(offsetof(ns2_Framework, _pad_BlockAllocator) == 0x08, "Framework _pad_BlockAllocator");
_Static_assert(offsetof(ns2_Framework, field_20) == 0x20, "Framework field_20");
_Static_assert(offsetof(ns2_Framework, field_28) == 0x28, "Framework field_28");
_Static_assert(offsetof(ns2_Framework, _pad_30) == 0x30, "Framework _pad_30");
_Static_assert(offsetof(ns2_Framework, field_34) == 0x34, "Framework field_34");
_Static_assert(offsetof(ns2_Framework, field_38) == 0x38, "Framework field_38");
_Static_assert(offsetof(ns2_Framework, hullDesc) == 0x3C, "Framework hullDesc");
_Static_assert(offsetof(ns2_Framework, memsetRegion) == 0x60, "Framework memsetRegion");
_Static_assert(offsetof(ns2_Framework, field_88) == 0x88, "Framework field_88");
_Static_assert(offsetof(ns2_Framework, _pad_8C) == 0x8C, "Framework _pad_8C");
_Static_assert(offsetof(ns2_Framework, field_90) == 0x90, "Framework field_90");
_Static_assert(offsetof(ns2_Framework, _pad_98) == 0x98, "Framework _pad_98");
_Static_assert(offsetof(ns2_Framework, field_9C) == 0x9C, "Framework field_9C");
_Static_assert(offsetof(ns2_Framework, field_A0) == 0xA0, "Framework field_A0");
_Static_assert(offsetof(ns2_Framework, field_A4) == 0xA4, "Framework field_A4");
_Static_assert(offsetof(ns2_Framework, field_A8) == 0xA8, "Framework field_A8");

/*
 * Classes with 0 proven fields or < 3 methods (no struct emitted):
 * - DebugDrawcallback: 0 fields from surface
 * - dm: 0 fields from surface
 * - DName: < 3 methods (skipped per threshold)
 * - dtNavMesh: 0 fields from surface
 * - dtTileCache: 0 fields from surface
 * - eastl (non-template): 0 fields from surface
 * - eastl::allocator: 0 fields from surface
 * - eastl::prime_rehash_policy: 0 fields from surface
 * - fwccDtTileCacheAlloc: 0 fields from surface
 * These are listed in cmn20-REPORT.md.
 */