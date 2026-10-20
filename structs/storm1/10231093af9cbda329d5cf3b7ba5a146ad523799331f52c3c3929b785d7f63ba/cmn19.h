/* cmn19.h - Struct group cmn19 for NARUTO STORM 1 PC (NSUNS1.exe, build s1)
 * Generated: 2026-10-19
 * All layouts INFERRED from static decompilation, not CONFIRMED by runtime.
 * PC offsets only (image base 0x140000000). Names from Storm 1 symbols/strings.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * cmnXmlElement - XML element node in the engine's DOM-like structure.
 * Size: 0x48 (proven from factory FUN_14047ed10(0x48, "source\\Cmn\\Xml\\cmnXml.cpp")
 *        called in FUN_140182afc, which constructs cmnXmlElement via ctor at 0x183014).
 * Vtable: data ref at 0x1413d1e54 (PTR_FUN_140745358 set in ctor via base init FUN_140482ce0).
 */
typedef struct __attribute__((packed)) cmnXmlElement {
    uint8_t  vtable_ptr[8];          /* 0x00 - vtable/base class ptr (set by FUN_140482ce0) */
    uint8_t  base_class_data[0x18];  /* 0x08 - base class fields (size 0x20 total from ctor arg) */
    uint64_t attributes;             /* 0x20 - attribute list ptr (alloc'd in AddAttribute via FUN_140182dd0) */
    uint64_t attributes_meta;        /* 0x28 - attribute metadata/list ptr (freed in Clear via FUN_140182f14) */
    uint64_t field_0x30;             /* 0x30 - zeroed in ctor, purpose unknown */
    uint64_t prev_sibling;           /* 0x38 - previous sibling ptr (linked-list traversal in Clear/AddChild) */
    uint64_t first_child;            /* 0x40 - first child element ptr (AddChild appends here) */
} cmnXmlElement;

static_assert(offsetof(cmnXmlElement, vtable_ptr)     == 0x00, "cmnXmlElement.vtable_ptr");
static_assert(offsetof(cmnXmlElement, base_class_data) == 0x08, "cmnXmlElement.base_class_data");
static_assert(offsetof(cmnXmlElement, attributes)      == 0x20, "cmnXmlElement.attributes");
static_assert(offsetof(cmnXmlElement, attributes_meta) == 0x28, "cmnXmlElement.attributes_meta");
static_assert(offsetof(cmnXmlElement, field_0x30)      == 0x30, "cmnXmlElement.field_0x30");
static_assert(offsetof(cmnXmlElement, prev_sibling)    == 0x38, "cmnXmlElement.prev_sibling");
static_assert(offsetof(cmnXmlElement, first_child)     == 0x40, "cmnXmlElement.first_child");
static_assert(sizeof(cmnXmlElement)                    == 0x48, "cmnXmlElement.size");

/*
 * CProfileNode - Profiler tree node (hierarchical timing).
 * Size: unknown, >= 0x80 (last proven field at 0x78 is uint32, so >= 0x7C; rounded to 0x80).
 * Allocator FUN_14047ec20 takes a dynamic size parameter; no fixed allocation found in callers.
 * No vtable identified (methods operate on raw pointers without vptr dispatch).
 */
typedef struct __attribute__((packed)) CProfileNode {
    uint64_t name_key;               /* 0x00 - profile node name/key (compared in Get_Sub_Node) */
    uint64_t counter_or_time;        /* 0x08 - zeroed in Reset(0x5FDFA0), likely call count or accumulator */
    uint64_t first_child;            /* 0x10 - first child node (recursed in Reset/CleanupMemory) */
    uint8_t  padding_0x18[8];        /* 0x18 - gap (no accesses observed) */
    uint64_t next_sibling;           /* 0x20 - next sibling (iter'd in CleanupMemory, Reset chains) */
    uint64_t parent_or_aux;          /* 0x28 - parent ptr or aux link (Reset follows this chain) */
    uint8_t  padding_0x30[0x48];     /* 0x30 - gap (no accesses observed between 0x30..0x78) */
    uint32_t frame_counter;          /* 0x78 - per-frame counter (zeroed in Reset(0x17F76C)) */
    uint8_t  padding_0x7C[4];        /* 0x7C - alignment pad to 0x80 */
} CProfileNode;

static_assert(offsetof(CProfileNode, name_key)         == 0x00, "CProfileNode.name_key");
static_assert(offsetof(CProfileNode, counter_or_time)  == 0x08, "CProfileNode.counter_or_time");
static_assert(offsetof(CProfileNode, first_child)      == 0x10, "CProfileNode.first_child");
static_assert(offsetof(CProfileNode, padding_0x18)     == 0x18, "CProfileNode.padding_0x18");
static_assert(offsetof(CProfileNode, next_sibling)     == 0x20, "CProfileNode.next_sibling");
static_assert(offsetof(CProfileNode, parent_or_aux)    == 0x28, "CProfileNode.parent_or_aux");
static_assert(offsetof(CProfileNode, padding_0x30)     == 0x30, "CProfileNode.padding_0x30");
static_assert(offsetof(CProfileNode, frame_counter)    == 0x78, "CProfileNode.frame_counter");
static_assert(offsetof(CProfileNode, padding_0x7C)     == 0x7C, "CProfileNode.padding_0x7C");
/* Size not asserted: unproven beyond 0x80 */

/*
 * CProfileManager: no instance state
 * Evidence: the decompiler cache state_surface reports 0 field accesses across all 5 methods:
 *   Reset              @ RVA 0x5FDEE0 (0 accesses)
 *   Stop_Profile       @ RVA 0x5FE030 (0 accesses)
 *   Start_Profile      @ RVA 0x5FDFE0 (0 accesses)
 *   Increment_Frame_Counter @ RVA 0x5B88  (0 accesses)
 *   Increment_Frame_Counter @ RVA 0x5FDED0 (0 accesses)
 * All methods operate on global/module-level state; no this pointer observed.
 */

/*
 * Classes with < 3 methods in this build (listed in REPORT.md, no struct emitted):
 *   cmnXmlContent (2 methods) - size >= 0x108, field at 0x8c and 0x100
 *   Concurrency::SchedulerPolicy (1 method) - MSVC PPL ctor
 *   Concurrency::agent (1 method) - status query
 *   Concurrency::details::InternalContextBase (1 method) - VP id getter
 *   Concurrency::details::SchedulerResourceManagement (1 method) - completion list setter
 *   Concurrency::details::SingleWaitBlock (1 method) - wait node sweep
 *   Concurrency::details::ThreadScheduler (2 methods) - policy/stats getters
 *   Concurrency::details::_AsyncTaskCollection (1 method) - scalar deleting dtor
 *   Concurrency::details::_ReentrantPPLLock (1 method) - lock release
 */