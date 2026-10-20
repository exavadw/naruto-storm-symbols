/* cmn19 s2 — NARUTO STORM 2 PC (NSUNS2.exe, sha256 6974880...)
 * Common struct pre-decompile: cmnXmlElement, CProfileNode
 * All layouts INFERRED from static decompilation of x64 code.
 * Sizes proven from allocator constants in game code.
 * Field names carried from s1 only where s2 code confirms same offset/usage.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Ensure static_assert is available in C11 */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/* ── cmnXmlElement ────────────────────────────────────────────────
 * Size 0x48 proven: FUN_14052e4a0 calls FUN_140580190(0x48, "source\\cmnXml.cpp")
 * then passes result to cmnXmlElement::cmnXmlElement (FUN_14052e914).
 * ctor zeroes offsets 0x20..0x40 in 8-byte steps → last field ends at 0x48.
 */
typedef struct __attribute__((packed)) cmnXmlElement {
    uint8_t  vtable_ptr[8];          /* 0x00  SIM  — vtable, set by base init FUN_14058b4a0 */
    uint8_t  base_class_data[0x18];  /* 0x08  UNKNOWN — passed to FUN_14058b4a0(param,tag,0x20) */
    uint64_t attributes;             /* 0x20  SIM  — head of attribute list (alloc 0x128 nodes) */
    uint64_t attributes_meta;        /* 0x28  SIM  — freed in Clear, separate from attributes */
    uint64_t parent_element;         /* 0x30  SIM  — set by parser: *(elem+0x30)=parent_param */
    uint64_t prev_sibling;           /* 0x38  SIM  — sibling chain traversal in SearchBros/AddChild */
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
 * Size unknown, >= 0x30. No allocator constant found in s2 for this class.
 * Get_Sub_Node allocates via FUN_1405800a0() with no visible size arg.
 * Offsets 0x00, 0x08, 0x20, 0x28 confirmed from decompiled methods.
 * Gap 0x10..0x1F has no observed access in any method — left as padding.
 * s1 had fields up to 0x7C (size ≥0x80) but those accesses are not
 * reproduced in s2 decompilations; only the core tree links are confirmed.
 */
typedef struct __attribute__((packed)) CProfileNode {
    uint64_t name_key;               /* 0x00  SIM  — compared in Get_Sub_Node (*plVar2 == param_2) */
    uint64_t counter_or_time;        /* 0x08  SIM  — zeroed in Reset */
    uint8_t  gap_0x10[0x10];         /* 0x10  UNKNOWN — no accesses observed in s2 */
    uint64_t next_sibling;           /* 0x20  SIM  — chained iteration in CleanupMemory/Get_Sub_Node */
    uint64_t parent_or_aux;          /* 0x28  SIM  — freed/recursed in CleanupMemory/Reset */
} CProfileNode; /* size unknown, >= 0x30 */

static_assert(offsetof(CProfileNode, name_key)         == 0x00, "name_key offset");
static_assert(offsetof(CProfileNode, counter_or_time)  == 0x08, "counter_or_time offset");
static_assert(offsetof(CProfileNode, gap_0x10)         == 0x10, "gap_0x10 offset");
static_assert(offsetof(CProfileNode, next_sibling)     == 0x20, "next_sibling offset");
static_assert(offsetof(CProfileNode, parent_or_aux)    == 0x28, "parent_or_aux offset");
/* ── CProfileManager ──────────────────────────────────────────────
 * CProfileManager: no instance state.
 * All 5 methods are static; they operate exclusively on global data:
 *   Reset (FUN_14071e310): DAT_1409af620..640, DAT_14810f498, _DAT_14810f490
 *   Start_Profile (FUN_14071e410): DATA=1 global ref, no param_1 deref
 *   Stop_Profile (FUN_14071e460): void(void) signature, DATA=1 global ref
 *   Increment_Frame_Counter (FUN_14071e300): void(void), callers=1, no instance
 *   Increment_Frame_Counter (FUN_140005a04): thunk/alias, same behavior
 * state_surface returned 0 fields across all 5 seeds. No ctor, no allocator,
 * no vtable. This class is a static utility namespace in s2.
 */
