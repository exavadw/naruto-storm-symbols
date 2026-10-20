/*
 * cmn20 s1 — struct layouts (INFERRED, not CONFIRMED)
 * Build: s1 (NSUNS1.exe, PC x64, image base 0x140000000)
 * Source: the decompiler cache state_surface + constructor pseudocode
 * Sizes are unproven unless noted; no sizeof asserts on incomplete structs.
 * All offsets from this PC build only. Names from Storm 1 (ns1::/strings) only.
 */

#include <stdint.h>
#include <stddef.h>

/* ---- GameActor::Base ----
 * Base class: ccTaskBase (inherited, layout unknown here)
 * Vtable: PTR_FUN_140747b70 (final, set at end of Base ctor)
 * Size: unknown, >= 0x90 (last proven field at 0x88, size 8)
 * Note: surface also saw reads at 0x1C0 and 0x200 but with null size;
 *       those may be embedded sub-objects or array bases, not scalar fields.
 */
struct __attribute__((packed)) ns1_GameActor_Base {
    /* 0x00 */ void *vtable;
    /* 0x08..0x47: ccTaskBase body (not reconstructed here) */
    uint8_t _pad_ccTaskBase[0x40];
    /* 0x48 */ void *nummModelManager;          /* FUN_14056a0a0(param_1 + 9); param_1+9 = +0x48 */
    /* 0x50 */ uint8_t _pad_50[0x08];
    /* 0x58 */ void *blockAllocator;            /* GetBlockId(param_1 + 0xb); 0xb*8 = 0x58 */
    /* 0x60 */ uint8_t _pad_60[0x10];
    /* 0x70 */ float position_x;                /* Nucc::Vector3 embedded at param_1+0xe = +0x70 */
    /* 0x74 */ float position_y;
    /* 0x78 */ float position_z;
    /* 0x7C */ int32_t field_7C;                /* *(undefined4 *)(param_1 + 0x7c) = 0 */
    /* 0x80 */ int32_t componentCount;          /* *(undefined4 *)(param_1 + 0x10) = param_3; 0x10*8=0x80 */
    /* 0x84 */ int32_t field_84;                /* *(undefined4 *)(param_1 + 0x84) = 0 */
    /* 0x88 */ void *componentList;             /* param_1[0x11]; 0x11*8 = 0x88 */
};

_Static_assert(offsetof(struct ns1_GameActor_Base, vtable)           == 0x00, "GameActor::Base vtable");
_Static_assert(offsetof(struct ns1_GameActor_Base, nummModelManager) == 0x48, "GameActor::Base nummModelManager");
_Static_assert(offsetof(struct ns1_GameActor_Base, blockAllocator)   == 0x58, "GameActor::Base blockAllocator");
_Static_assert(offsetof(struct ns1_GameActor_Base, position_x)       == 0x70, "GameActor::Base position_x");
_Static_assert(offsetof(struct ns1_GameActor_Base, position_y)       == 0x74, "GameActor::Base position_y");
_Static_assert(offsetof(struct ns1_GameActor_Base, position_z)       == 0x78, "GameActor::Base position_z");
_Static_assert(offsetof(struct ns1_GameActor_Base, field_7C)         == 0x7C, "GameActor::Base field_7C");
_Static_assert(offsetof(struct ns1_GameActor_Base, componentCount)   == 0x80, "GameActor::Base componentCount");
_Static_assert(offsetof(struct ns1_GameActor_Base, field_84)         == 0x84, "GameActor::Base field_84");
_Static_assert(offsetof(struct ns1_GameActor_Base, componentList)    == 0x88, "GameActor::Base componentList");

/* ---- Framework ----
 * Base class: Nucc::Memory::BlockAllocator (inherited, layout unknown here)
 * Vtable: PTR_FUN_14072b268
 * HullDesc embedded at +0x3C (size unknown; treated as opaque blob)
 * memset(param_1 + 0xc, 0, 0x28) proves 0x28 bytes from +0x60 are valid
 * Size: unknown, >= 0xC0 (last proven write at 0xBC, size 4 → next aligned = 0xC0)
 */
struct __attribute__((packed)) ns1_Framework {
    /* 0x00 */ void *vtable;
    /* 0x08..0x1F: BlockAllocator body (not reconstructed here) */
    uint8_t _pad_BlockAllocator[0x18];
    /* 0x20 */ void *field_20;                  /* param_1[4] = 0; 4*8 = 0x20 */
    /* 0x28 */ uint8_t _pad_28[0x0C];
    /* 0x34 */ int32_t field_34;                /* *(undefined4 *)(param_1 + 0x34) = 0 */
    /* 0x38 */ int32_t field_38;                /* *(undefined4 *)(param_1 + 7) = 0; 7*8=0x38? Actually byte offset: ctor says param_1+7 which is ambiguous. Surface shows 0x38 w4. Treating as separate from HullDesc. */
    /* 0x3C */ uint8_t hullDesc[0x24];          /* HullDesc embedded; size unknown, placeholder until +0x60 */
    /* 0x60 */ uint8_t memsetRegion[0x28];      /* memset(param_1 + 0xc, 0, 0x28); 0xc*8=0x60, len=0x28 */
    /* 0x88 */ int32_t field_88;                /* *(undefined4 *)(param_1 + 0x11) = 0; 0x11*8=0x88 */
    /* 0x8C */ uint8_t _pad_8C[0x04];
    /* 0x90 */ int64_t field_90;                /* param_1[0x12] = 0; 0x12*8 = 0x90 */
    /* 0x98 */ uint8_t _pad_98[0x04];
    /* 0x9C */ int32_t field_9C;                /* *(undefined4 *)(param_1 + 0x9c) = 0 */
    /* 0xA0 */ int32_t field_A0;                /* *(undefined4 *)(param_1 + 0x14) = 1; 0x14*8=0xA0 */
    /* 0xA4 */ int32_t field_A4;                /* *(undefined4 *)(param_1 + 0xa4) = 1 */
    /* 0xA8 */ int32_t field_A8;                /* *(undefined4 *)(param_1 + 0x15) = 0; 0x15*8=0xA8 */
    /* 0xAC */ int32_t field_AC;                /* *(undefined4 *)(param_1 + 0xac) = 1 */
    /* 0xB0 */ int32_t field_B0;                /* *(undefined4 *)(param_1 + 0x16) = 1; 0x16*8=0xB0 */
    /* 0xB4 */ int32_t field_B4;                /* *(undefined4 *)(param_1 + 0xb4) = 0 */
    /* 0xB8 */ int32_t field_B8;                /* *(undefined4 *)(param_1 + 0x17) = 0xffffffff; 0x17*8=0xB8 */
    /* 0xBC */ int32_t field_BC;                /* *(undefined4 *)(param_1 + 0xbc) = 0 */
};

_Static_assert(offsetof(struct ns1_Framework, vtable)        == 0x00, "Framework vtable");
_Static_assert(offsetof(struct ns1_Framework, field_20)      == 0x20, "Framework field_20");
_Static_assert(offsetof(struct ns1_Framework, field_34)      == 0x34, "Framework field_34");
_Static_assert(offsetof(struct ns1_Framework, field_38)      == 0x38, "Framework field_38");
_Static_assert(offsetof(struct ns1_Framework, hullDesc)      == 0x3C, "Framework hullDesc");
_Static_assert(offsetof(struct ns1_Framework, memsetRegion)  == 0x60, "Framework memsetRegion");
_Static_assert(offsetof(struct ns1_Framework, field_88)      == 0x88, "Framework field_88");
_Static_assert(offsetof(struct ns1_Framework, field_90)      == 0x90, "Framework field_90");
_Static_assert(offsetof(struct ns1_Framework, field_9C)      == 0x9C, "Framework field_9C");
_Static_assert(offsetof(struct ns1_Framework, field_A0)      == 0xA0, "Framework field_A0");
_Static_assert(offsetof(struct ns1_Framework, field_A4)      == 0xA4, "Framework field_A4");
_Static_assert(offsetof(struct ns1_Framework, field_A8)      == 0xA8, "Framework field_A8");
_Static_assert(offsetof(struct ns1_Framework, field_AC)      == 0xAC, "Framework field_AC");
_Static_assert(offsetof(struct ns1_Framework, field_B0)      == 0xB0, "Framework field_B0");
_Static_assert(offsetof(struct ns1_Framework, field_B4)      == 0xB4, "Framework field_B4");
_Static_assert(offsetof(struct ns1_Framework, field_B8)      == 0xB8, "Framework field_B8");
_Static_assert(offsetof(struct ns1_Framework, field_BC)      == 0xBC, "Framework field_BC");

/* ---- eastl::hashtable (template instantiation) ----
 * From hashtable<int,pair<int_const,nummShader*>,...>::erase (0x455800)
 * This is ONE template instantiation; other instantiations may differ in layout.
 * Size: unknown, >= 0x40 (last field at 0x38, size 8)
 * Not a user-facing class; included for completeness of cmn20 group.
 */
struct __attribute__((packed)) ns1_eastl_hashtable_int_nummShader {
    /* 0x00 */ void *vtable_or_buckets_ptr;     /* first member of hashtable */
    /* 0x08 */ void *buckets;
    /* 0x10 */ void *nodeAllocator;
    /* 0x18 */ size_t elementCount;
    /* 0x20 */ void *hashFunction;
    /* 0x28 */ void *keyEqual;
    /* 0x30 */ void *rehashPolicy;
    /* 0x38 */ void *extractor;
};

_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, vtable_or_buckets_ptr) == 0x00, "eastl hashtable vtable/buckets");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, buckets)               == 0x08, "eastl hashtable buckets");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, nodeAllocator)          == 0x10, "eastl hashtable nodeAllocator");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, elementCount)           == 0x18, "eastl hashtable elementCount");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, hashFunction)           == 0x20, "eastl hashtable hashFunction");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, keyEqual)               == 0x28, "eastl hashtable keyEqual");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, rehashPolicy)           == 0x30, "eastl hashtable rehashPolicy");
_Static_assert(offsetof(struct ns1_eastl_hashtable_int_nummShader, extractor)              == 0x38, "eastl hashtable extractor");

/*
 * Classes with 0 proven fields (state_surface returned nothing):
 *   DebugDrawcallback, dm, dtNavMesh, dtTileCache, fwccDtTileCacheAlloc
 * DName has only 1 method (< 3 threshold) — skipped.
 * These are listed in cmn20-REPORT.md but have no struct here.
 */