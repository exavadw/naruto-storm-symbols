/* cmn05 s1: ccMessageManager, ccMovie, ccPad, ccPlCondition, ccPlConditionSet, ccPresenceManager
 * Build: s1 (NSUNS1.exe-a9fe00)
 * All layouts INFERRED from static analysis; not CONFIRMED at runtime.
 * Sizes proven from game code where noted; otherwise "size unknown, >= 0x<N>".
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* === ccPad ===
 * Size: 0x108 (proven: ccFileLoadListForUi::LoadTh(0x108,...) in ccUiManager::Initialize, ccUiSelect::CreatePad)
 * state_surface found 5 fields; constructor writes up to offset 0x104.
 */
typedef struct __attribute__((packed)) ccPad {
    uint8_t _pad_0x00[0x44];           /* 0x00 - vtable ptr + unknown */
    uint8_t field_0x44[0xB0];          /* 0x44 - read access (low confidence), extent to 0xF4 */
    int32_t field_0xF4;                /* 0xF4 - written = 0xffffffff in ctor */
    int64_t field_0xF8;                /* 0xF8 - written = 0 in ctor */
    int32_t field_0x100;               /* 0x100 - written = 0 in ctor */
    int32_t field_0x104;               /* 0x104 - written = 1 in ctor */
} ccPad;
static_assert(offsetof(ccPad, field_0x44) == 0x44, "ccPad.field_0x44");
static_assert(offsetof(ccPad, field_0xF4) == 0xF4, "ccPad.field_0xF4");
static_assert(offsetof(ccPad, field_0xF8) == 0xF8, "ccPad.field_0xF8");
static_assert(offsetof(ccPad, field_0x100) == 0x100, "ccPad.field_0x100");
static_assert(offsetof(ccPad, field_0x104) == 0x104, "ccPad.field_0x104");
static_assert(sizeof(ccPad) == 0x108, "ccPad size == 0x108");

/* === ccPlCondition ===
 * Size: 0x70 (proven: ccFileLoadListForUi::LoadTh(0x70,...) in ccPlConditionSet::Add)
 * Linked-list node: offset 0x0 = next ptr, offset 0x8 = condition id.
 * BlockAllocator embedded at offset 0x38 (plVar7+7).
 * Fields initialized in Add: 0x0, 0x8, 0xC, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x38.
 * Ctrl reads floats at 0x10, 0x18 (via indirection); OnBegin reads 0x8, 0x18.
 */
typedef struct __attribute__((packed)) ccPlCondition {
    struct ccPlCondition *next;        /* 0x00 - linked list next pointer */
    int32_t condition_id;              /* 0x08 - condition type id */
    float duration_scaled;             /* 0x0C - duration * fps_factor */
    float param_float;                 /* 0x10 - per-condition float param */
    int32_t field_0x14;                /* 0x14 - unknown int */
    int32_t field_0x18;                /* 0x18 - flags / sub-type */
    int32_t field_0x1C;                /* 0x1C - unknown */
    int64_t owner_ptr;                 /* 0x20 - pointer to owning object (ccPlayer?) */
    int32_t tex_param;                 /* 0x28 - texture/effect param, init 0xffffffff */
    uint8_t _pad_0x2C[0xC];            /* 0x2C - padding to BlockAllocator */
    uint8_t block_allocator[0x30];     /* 0x38 - Nucc::Memory::BlockAllocator (plVar7+7) */
    uint8_t _tail[0x08];               /* 0x68 - trailing bytes to reach 0x70 */
} ccPlCondition;
static_assert(offsetof(ccPlCondition, next) == 0x00, "ccPlCondition.next");
static_assert(offsetof(ccPlCondition, condition_id) == 0x08, "ccPlCondition.condition_id");
static_assert(offsetof(ccPlCondition, duration_scaled) == 0x0C, "ccPlCondition.duration_scaled");
static_assert(offsetof(ccPlCondition, param_float) == 0x10, "ccPlCondition.param_float");
static_assert(offsetof(ccPlCondition, field_0x14) == 0x14, "ccPlCondition.field_0x14");
static_assert(offsetof(ccPlCondition, field_0x18) == 0x18, "ccPlCondition.field_0x18");
static_assert(offsetof(ccPlCondition, owner_ptr) == 0x20, "ccPlCondition.owner_ptr");
static_assert(offsetof(ccPlCondition, tex_param) == 0x28, "ccPlCondition.tex_param");
static_assert(offsetof(ccPlCondition, block_allocator) == 0x38, "ccPlCondition.block_allocator");
static_assert(sizeof(ccPlCondition) == 0x70, "ccPlCondition size == 0x70");

/* === ccPlConditionSet ===
 * Size unknown, >= 0x28 (embedded in ccPlayer at offset 0x8a8; fields at +0x8, +0x10, +0x18, +0x20).
 * Linked list head at +0x8, tail at +0x10, count at +0x18, durable_per_ptr at +0x20.
 * Not heap-allocated; always embedded.
 */
typedef struct __attribute__((packed)) ccPlConditionSet {
    uint8_t _vtable_or_pad[0x08];      /* 0x00 - possible vtable or padding */
    ccPlCondition *head;               /* 0x08 - linked list head */
    ccPlCondition *tail;               /* 0x10 - linked list tail */
    int32_t count;                     /* 0x18 - number of active conditions */
    uint8_t _pad_0x1C[0x04];           /* 0x1C - padding to align durable_per_ptr */
    int64_t durable_per_ptr;           /* 0x20 - pointer to durable percentage source */
} ccPlConditionSet;
static_assert(offsetof(ccPlConditionSet, head) == 0x08, "ccPlConditionSet.head");
static_assert(offsetof(ccPlConditionSet, tail) == 0x10, "ccPlConditionSet.tail");
static_assert(offsetof(ccPlConditionSet, count) == 0x18, "ccPlConditionSet.count");
static_assert(offsetof(ccPlConditionSet, durable_per_ptr) == 0x20, "ccPlConditionSet.durable_per_ptr");
/* No sizeof assert: size unknown, >= 0x28 */

/* === ccMessageManager ===
 * Size unknown. state_surface found 0 direct field accesses (all via indirection through param_1[0]).
 * Create/SetMessageParam operate on an opaque handle; likely a singleton or global.
 */
/* No struct emitted: insufficient field evidence for layout reconstruction. */

/* === ccMovie ===
 * Size unknown. state_surface found 0 direct field accesses (byte-cast only).
 * Setup/Ctrl/Stop operate on global pointers (DAT_140c82ac8, DAT_1408c6040).
 * Likely a singleton managed by CRI Sofdec2 middleware.
 */
/* No struct emitted: insufficient field evidence for layout reconstruction. */

/* === ccPresenceManager ===
 * Size unknown, >= 0x10. Wraps an Impl pointer at offset +0x8.
 * Initialize/Finalize delegate to Impl; Clear writes at impl+0x10.
 */
typedef struct __attribute__((packed)) ccPresenceManager {
    uint8_t _pad_0x00[0x08];           /* 0x00 - possible vtable */
    void *impl;                        /* 0x08 - pointer to Impl object */
} ccPresenceManager;
static_assert(offsetof(ccPresenceManager, impl) == 0x08, "ccPresenceManager.impl");
/* No sizeof assert: size unknown, >= 0x10 */