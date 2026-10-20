/* cmn19 s3 — NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, sha256 55b726e94dad...)
 * Common struct pre-decompile: cmnXmlElement, CProfileNode
 * All layouts INFERRED from static decompilation of x64 code.
 * Sizes proven from allocator constants in game code where available.
 * Field names carried from s2 only where s3 code confirms same offset/usage.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Ensure static_assert is available in C11 */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/* ── cmnXmlElement ────────────────────────────────────────────────
 * Size 0x48 proven: FUN_140644790 calls ccFileLoadListForUi::LoadTh(0x48,
 * "source\\Cmn\\Xml\\cmnXml.cpp") then passes result to
 * cmnXmlElement::cmnXmlElement (FUN_140644CA8).
 * ctor zeroes offsets 0x20..0x40 in 8-byte steps → last field ends at 0x48.
 */
typedef struct __attribute__((packed)) cmnXmlElement {
    uint8_t  vtable_ptr[8];          /* 0x00  SIM  — vtable, set by base init (nuccStrCpy copies tag into 0x00..0x1F) */
    uint8_t  base_class_data[0x18];  /* 0x08  UNKNOWN — nuccStrCpy(param_1, param_2, 0x20) covers 0x00..0x1F */
    uint64_t attributes;             /* 0x20  SIM  — head of attribute list (alloc 0x128 nodes via LoadTh) */
    uint64_t attributes_meta;        /* 0x28  SIM  — freed in Clear via cmnXmlContent::Clear, separate from attributes */
    uint64_t parent_element;         /* 0x30  SIM  — set by parser FUN_140644790: *(elem+0x30)=parent_param */
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
 * Size unknown, >= 0x38. No allocator constant found in s3 for this class.
 * Get_Sub_Node allocates via operator_new() with no visible size arg,
 * but initializes plVar1[0..6] (offsets 0x00..0x30) → minimum 0x38 bytes.
 * Start_Profile/Stop_Profile access offsets 0x08, 0x0C, 0x10, 0x14, 0x18
 * on the node pointed to by PTR_PTR_140b71270, confirming these fields.
 * Gap 0x04..0x07 and 0x1C..0x1F have no observed access — left as padding.
 */
typedef struct __attribute__((packed)) CProfileNode {
    uint64_t name_key;               /* 0x00  SIM  — compared in Get_Sub_Node (*plVar2 == param_2) */
    uint32_t call_count;             /* 0x08  SIM  — incremented in Start_Profile (*(node+8) += 1) */
    float    accumulated_time_ms;    /* 0x0C  SIM  — accumulated in Stop_Profile as float ms */
    uint32_t start_time_us;          /* 0x10  SIM  — set by btClock::getTimeMicroseconds in Start_Profile */
    uint32_t recursion_depth;        /* 0x14  SIM  — depth counter, checked/decremented in Stop_Profile */
    uint64_t parent_node;            /* 0x18  SIM  — plVar1[3]=param_1 in Get_Sub_Node; used to pop stack in Stop_Profile */
    uint64_t first_child;            /* 0x20  SIM  — chained iteration in CleanupMemory/Get_Sub_Node (plVar1[5]) */
    uint64_t next_sibling;           /* 0x28  SIM  — plVar1[5] link in Get_Sub_Node; recursed in CleanupMemory */
    uint64_t unused_or_padding;      /* 0x30  UNKNOWN — plVar1[6]=0 in Get_Sub_Node; no other access observed */
} CProfileNode; /* size unknown, >= 0x38 */

static_assert(offsetof(CProfileNode, name_key)           == 0x00, "name_key offset");
static_assert(offsetof(CProfileNode, call_count)         == 0x08, "call_count offset");
static_assert(offsetof(CProfileNode, accumulated_time_ms)== 0x0C, "accumulated_time_ms offset");
static_assert(offsetof(CProfileNode, start_time_us)      == 0x10, "start_time_us offset");
static_assert(offsetof(CProfileNode, recursion_depth)    == 0x14, "recursion_depth offset");
static_assert(offsetof(CProfileNode, parent_node)        == 0x18, "parent_node offset");
static_assert(offsetof(CProfileNode, first_child)        == 0x20, "first_child offset");
static_assert(offsetof(CProfileNode, next_sibling)       == 0x28, "next_sibling offset");
static_assert(offsetof(CProfileNode, unused_or_padding)  == 0x30, "unused_or_padding offset");