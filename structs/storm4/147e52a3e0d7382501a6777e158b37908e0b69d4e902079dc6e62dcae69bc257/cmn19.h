/* cmn19 s4 — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, sha256 147e52a3e0d7...)
 * Common struct pre-decompile: cmnXmlElement, CProfileNode
 * All layouts INFERRED from static decompilation of x64 code.
 * Sizes proven from allocator constants in game code where available.
 * Field names carried from s3 only where s4 code confirms same offset/usage.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Ensure static_assert is available in C11 */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/* ── cmnXmlElement ────────────────────────────────────────────────
 * Size 0x48 proven: ctor (FUN_1404b6890) calls FUN_140a02710(param_1, param_2, 0x20)
 * then zeroes offsets 0x20..0x40 in 8-byte steps → last field ends at 0x48.
 * AddAttribute allocates attribute nodes at 0x128 via FUN_140a017f0.
 * Layout identical to s3; field names carried forward with s4 evidence.
 */
typedef struct __attribute__((packed)) cmnXmlElement {
    uint8_t  vtable_ptr[8];          /* 0x00  SIM  — vtable, set by base init FUN_140a02710 */
    uint8_t  base_class_data[0x18];  /* 0x08  UNKNOWN — base init covers 0x00..0x1F via nuccStrCpy-like copy */
    uint64_t attributes;             /* 0x20  SIM  — head of attribute list (alloc 0x128 nodes via AddAttribute) */
    uint64_t attributes_meta;        /* 0x28  SIM  — freed in Clear via separate path, distinct from attributes */
    uint64_t parent_element;         /* 0x30  SIM  — zeroed in ctor; set by parser (inferred from s3) */
    uint64_t prev_sibling;           /* 0x38  SIM  — sibling chain link used in AddChild traversal */
    uint64_t first_child;            /* 0x40  SIM  — child list head in AddChild/SearchChild */
} cmnXmlElement; /* size 0x48 */

static_assert(sizeof(cmnXmlElement) == 0x48, "cmnXmlElement size must be 0x48");
static_assert(offsetof(cmnXmlElement, vtable_ptr)      == 0x00, "vtable_ptr offset");
static_assert(offsetof(cmnXmlElement, base_class_data)  == 0x08, "base_class_data offset");
static_assert(offsetof(cmnXmlElement, attributes)       == 0x20, "attributes offset");
static_assert(offsetof(cmnXmlElement, attributes_meta)  == 0x28, "attributes_meta offset");
static_assert(offsetof(cmnXmlElement, parent_element)   == 0x30, "parent_element offset");
static_assert(offsetof(cmnXmlElement, prev_sibling)     == 0x38, "prev_sibling offset");
static_assert(offsetof(cmnXmlElement, first_child)      == 0x40, "first_child offset");


/* ── CProfileNode ─────────────────────────────────────────────────
 * Size unknown, >= 0x30. No allocator constant found in s4 for this class.
 * Get_Sub_Node (FUN_140e51a00) allocates via FUN_140a01700() with no visible
 * size arg, but initializes plVar1[0..6] (offsets 0x00..0x30) → minimum 0x30 bytes.
 * Start_Profile/Stop_Profile access offsets 0x08, 0x0C, 0x10, 0x14, 0x18
 * on PTR_PTR_1415af790, confirming these fields.
 * CleanupMemory recurses through 0x20 (first_child) and 0x28 (next_sibling).
 * Gap 0x04..0x07 has no observed access — left as padding.
 */
typedef struct __attribute__((packed)) CProfileNode {
    uint64_t name_key;               /* 0x00  SIM  — compared in Get_Sub_Node (*plVar2 == param_2) */
    uint32_t call_count;             /* 0x08  SIM  — incremented in Start_Profile (*(node+8) += 1) */
    float    accumulated_time_ms;    /* 0x0C  SIM  — accumulated in Stop_Profile as float ms */
    uint32_t start_time_us;          /* 0x10  SIM  — set by FUN_140e51c40 in Start_Profile when depth==0 */
    uint32_t recursion_depth;        /* 0x14  SIM  — depth counter, checked/decremented in Stop_Profile */
    uint64_t parent_node;            /* 0x18  SIM  — plVar1[3]=param_1 in Get_Sub_Node; popped in Stop_Profile */
    uint64_t first_child;            /* 0x20  SIM  — chained iteration in CleanupMemory/Get_Sub_Node (plVar1[4]) */
    uint64_t next_sibling;           /* 0x28  SIM  — plVar1[5] link in Get_Sub_Node; recursed in CleanupMemory */
} CProfileNode; /* size unknown, >= 0x30 */

static_assert(offsetof(CProfileNode, name_key)           == 0x00, "name_key offset");
static_assert(offsetof(CProfileNode, call_count)         == 0x08, "call_count offset");
static_assert(offsetof(CProfileNode, accumulated_time_ms)== 0x0C, "accumulated_time_ms offset");
static_assert(offsetof(CProfileNode, start_time_us)      == 0x10, "start_time_us offset");
static_assert(offsetof(CProfileNode, recursion_depth)    == 0x14, "recursion_depth offset");
static_assert(offsetof(CProfileNode, parent_node)        == 0x18, "parent_node offset");
static_assert(offsetof(CProfileNode, first_child)        == 0x20, "first_child offset");
static_assert(offsetof(CProfileNode, next_sibling)       == 0x28, "next_sibling offset");


/* ── CProfileManager: no instance state ───────────────────────────
 * All 5 methods are STATIC — they operate exclusively on global data,
 * never on a `this` pointer or any instance allocation.
 * Evidence (state_surface --json, 5 seeds, 0 fields):
 *   - Reset             (FUN_140e51a90)  accesses 0 instance offsets
 *   - Stop_Profile      (FUN_140e51be0)  accesses 0 instance offsets
 *   - Start_Profile     (FUN_140e51b90)  accesses 0 instance offsets
 *   - Increment_Frame_Counter (FUN_140006294) accesses 0 instance offsets
 *   - Increment_Frame_Counter (FUN_140e51a80) accesses 0 instance offsets
 * Globals used: PTR_PTR_1415af790 (current node), DAT_1415af7a0..7c0
 * (frame counters/depth/trees), _DAT_148d30390 (global frame counter).
 * No ctor, vtable, or heap allocation exists for this class.
 */