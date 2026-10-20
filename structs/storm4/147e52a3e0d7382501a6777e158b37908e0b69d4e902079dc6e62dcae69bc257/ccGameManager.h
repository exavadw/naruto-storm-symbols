/*
 * ccGameManager struct layout — Storm 4 (NSUNS4_release.exe, build s4)
 * SHA256: 147e52a3e0d7382501a6777e158b37908e0b69d4e902079dc6e62dcae69bc257
 *
 * INFERRED from static decompilation of ccGameManager::ReplaceLoadPath (0x85A9F8),
 * ccGameManager::InitInstances #2 (0x8575C0), and ccSceneGameRoot::Initialize (0x863B48).
 * NOT CONFIRMED at runtime. All field names are descriptive; Storm 4 has no Trilogy namespace.
 *
 * Object size: UNKNOWN (no operator new / allocator size found).
 * Minimum proven extent: >= 0x26F0 (bitfield at 0x26D0, 0x100 bits = 0x20 bytes).
 * No sizeof static_assert.
 *
 * ccGameManager is embedded inside ccSceneGameRoot (not separately heap-allocated).
 * SceneGameRoot::Initialize passes (param_1 + 0x25) as ccGameManager base to InitInstances2,
 * meaning ccGameManager starts at offset 0x128 within ccSceneGameRoot.
 *
 * NOTE on the dense pointer cluster (0x958–0x996):
 * ReplaceLoadPath writes 8-byte pointers at 2-byte-spaced offsets (0x958, 0x95a, 0x95c...).
 * These overlap if treated as individual uint64 fields. This indicates the region is either
 * an array of pointers accessed with computed indices, or Ghidra's decompiler is misrepresenting
 * the access pattern. We model it as a single opaque byte region until disassembly confirms
 * the true structure. The same applies to 0xBC2/0xBC6 (4-byte gap between 8-byte stores).
 *
 * PACKED: This struct uses __attribute__((packed)) because several proven field offsets
 * (0x914, 0x9AE, 0xBC2) are not naturally aligned for uint64_t. The game accesses these
 * via unaligned loads/stores on x86-64 where that is legal.
 */
#ifndef CCGAME_MANAGER_S4_H
#define CCGAME_MANAGER_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct __attribute__((packed)) ccGameManager {
    /* ---- 0x000 .. 0x003: param_1[0] written as 0 (uint32 via undefined4* base) ---- */
    /* ReplaceLoadPath: *param_1 = 0; */
    uint32_t field_0x00;                          /* 0x000 */

    /* ---- 0x004: param_1[1] = 0x3f800000 (float 1.0f as uint32) ---- */
    /* ReplaceLoadPath: param_1[1] = 0x3f800000; */
    uint32_t field_0x04_float1;                   /* 0x004 */

    /* ---- 0x008 .. 0x117: unproven region ---- */
    uint8_t pad_008[0x118 - 0x008];               /* 0x008 */

    /* ---- 0x118: state machine path string pointer ---- */
    /* InitInstances2: if (*(longlong*)(param_1+0x118)==0) allocate via FUN_140607740 */
    uint64_t statemachine_path_ptr;               /* 0x118 */

    /* ---- 0x120 .. 0x913: large unproven gap ---- */
    uint8_t pad_120[0x914 - 0x120];               /* 0x120 */

    /* ---- 0x914: load-path source pointer (read as undefined8*) ---- */
    /* ReplaceLoadPath: FUN_140ab47e0(*(undefined8*)(param_1+0x914), 5) */
    uint64_t loadpath_source_ptr;                 /* 0x914 */

    /* ---- 0x91C .. 0x957: gap before dense cluster ---- */
    uint8_t pad_91C[0x958 - 0x91C];               /* 0x91C */

    /*
     * ===================================================================
     * DENSE SUB-OBJECT POINTER CLUSTER: 0x958 .. 0x9A3
     * ReplaceLoadPath writes 8-byte pointers at 2-byte intervals here.
     * These accesses OVERLAP if modeled as individual uint64 fields.
     * Modeled as opaque byte region. True structure requires disassembly.
     * Allocation sizes observed: 0x208, 0xd8, 0xa0, 0xb8, 0x30, 0x78,
     * 0x78, 0x80, 0x1224b0, 0x70, 0x48, 0x78, 0x210, 0xe0, 0x30,
     * 0x08, 0x78, 0x5e8, 0x08, 0x78, 0x50, 0x640, 0xc0, 0x78, 0x40
     * Constructors called after each allocation suggest distinct sub-system types.
     * ===================================================================
     */
    uint8_t subsys_cluster[0x9A4 - 0x958];        /* 0x958, size 0x4C (76 bytes) */

    /* ---- 0x9A4: alloc 0x2F8 bytes, ctor FUN_14066db3c ---- */
    /* ReplaceLoadPath: *(undefined8**)(param_1+0x9a4) = puVar9; non-overlapping */
    uint64_t subsys_2F8_ptr;                      /* 0x9A4 */

    /* ---- 0x9AC: gap ---- */
    uint8_t pad_9AC[0x9AE - 0x9AC];               /* 0x9AC */

    /* ---- 0x9AE: sub-object address passed to FUN_140a01d60 ---- */
    /* ReplaceLoadPath: uVar4 = FUN_140a01d60(param_1 + 0x9ae); */
    /* Size unknown; next proven field is at 0xBC2, so region is 0x214 bytes */
    uint8_t field_9AE_region[0xBC2 - 0x9AE];      /* 0x9AE, size 0x214 (532 bytes) */

    /* ---- 0xBC2: alloc 0x70 bytes, ctor FUN_1406c8174 ---- */
    /* ReplaceLoadPath: *(undefined8**)(param_1+0xbc2) = puVar9; */
    /* Note: 0xBC6 store overlaps with this if both are uint64. Modeled together. */
    uint8_t late_subsys_cluster[0xBCE - 0xBC2];   /* 0xBC2, size 0xC (covers 0xBC2+0xBC6) */

    /* ---- 0xBCE .. 0x26CF: large unproven gap ---- */
    uint8_t pad_BCE[0x26D0 - 0xBCE];              /* 0xBCE */

    /*
     * ===================================================================
     * BITFIELD REGION: 0x26D0 .. 0x26EF (0x100 bits = 32 bytes = 0x20)
     * ReplaceLoadPath iterates i=0..0xFF, computing byte_index = i>>3, bit = i&7,
     * and reads/writes param_1[0x26D0 + byte_index].
     * Source bitmap at DAT_14163bdf4 determines set vs clear.
     * ===================================================================
     */
    uint8_t flags_bitfield[0x20];                 /* 0x26D0 */

    /* 0x26F0: end of proven data. True object size unknown (>= 0x26F0). */
} ccGameManager;

/* ---- offsetof assertions for every named field ---- */
static_assert(offsetof(ccGameManager, field_0x00)             == 0x0000, "field_0x00");
static_assert(offsetof(ccGameManager, field_0x04_float1)      == 0x0004, "field_0x04_float1");
static_assert(offsetof(ccGameManager, statemachine_path_ptr)  == 0x0118, "statemachine_path_ptr");
static_assert(offsetof(ccGameManager, loadpath_source_ptr)    == 0x0914, "loadpath_source_ptr");
static_assert(offsetof(ccGameManager, subsys_cluster)         == 0x0958, "subsys_cluster");
static_assert(offsetof(ccGameManager, subsys_2F8_ptr)         == 0x09A4, "subsys_2F8_ptr");
static_assert(offsetof(ccGameManager, field_9AE_region)       == 0x09AE, "field_9AE_region");
static_assert(offsetof(ccGameManager, late_subsys_cluster)    == 0x0BC2, "late_subsys_cluster");
static_assert(offsetof(ccGameManager, flags_bitfield)         == 0x26D0, "flags_bitfield");

/* NOTE: no sizeof assertion — true object size not found in binary.
 * Minimum proven extent: >= 0x26F0 (end of 0x100-bit field at 0x26D0).
 * ccGameManager is embedded in ccSceneGameRoot at offset 0x128. */

#endif /* CCGAME_MANAGER_S4_H */