/* cmn05.h — Storm 2 (NSUNS2.exe-abf2b6) common struct group
 * Generated from decompilation cache + state_surface + manual review.
 * All structs __attribute__((packed)), explicit padding, static_assert per field.
 * Rollback tags: SIM = simulation-critical, PRES = presentation-only, UNKNOWN = undetermined.
 */
#ifndef CMN05_S2_H
#define CMN05_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* C11 _Static_assert wrapper; C++ uses static_assert natively */
#ifdef __cplusplus
#define CMN05_STATIC_ASSERT(cond, msg) CMN05_STATIC_ASSERT(cond, msg)
#else
#define CMN05_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ─── Forward declarations ─── */
typedef struct ns2_ccPad ns2_ccPad;
typedef struct ns2_ccPlCondition ns2_ccPlCondition;
typedef struct ns2_ccPlConditionSet ns2_ccPlConditionSet;
typedef struct ns2_ccPresenceManager ns2_ccPresenceManager;

/* ─── Nucc::Memory::BlockAllocator (embedded, size 0x10 from s1) ─── */
typedef struct ns2_BlockAllocator {
    uint64_t pool_ptr;      /* +0x0 */
    uint64_t alloc_state;   /* +0x8 */
} __attribute__((packed)) ns2_BlockAllocator;
CMN05_STATIC_ASSERT(sizeof(ns2_BlockAllocator) == 0x10, "ns2_BlockAllocator size");

/* ─── ccPad (size 0x108) ───
 * Evidence: ccPad::ccPad (0x667810) clears [0x44..0xF3], sets sentinels at 0xF4/0xF8/0x100/0x104.
 * Callers allocate 0x108. State surface: r@0x44, w@0xF4,0xF8,0x100,0x104.
 */
struct ns2_ccPad {
    uint64_t vtable;            /* +0x00 SIM */
    uint8_t  _pad_08[0x3C];     /* +0x08 */
    uint32_t input_state_r;     /* +0x44 SIM - read in Ctrl */
    uint8_t  _pad_48[0xAC];     /* +0x48 cleared region */
    int32_t  sentinel_neg1;     /* +0xF4 SIM - initialized to -1 */
    int32_t  sentinel_zero_a;   /* +0xF8 SIM - initialized to 0 */
    uint8_t  _pad_FC[0x04];     /* +0xFC */
    int32_t  sentinel_zero_b;   /* +0x100 SIM - initialized to 0 */
    int32_t  sentinel_one;      /* +0x104 SIM - initialized to 1 */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns2_ccPad, vtable)          == 0x00, "ccPad.vtable");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPad, input_state_r)   == 0x44, "ccPad.input_state_r");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPad, sentinel_neg1)   == 0xF4, "ccPad.sentinel_neg1");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPad, sentinel_zero_a) == 0xF8, "ccPad.sentinel_zero_a");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPad, sentinel_zero_b) == 0x100, "ccPad.sentinel_zero_b");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPad, sentinel_one)    == 0x104, "ccPad.sentinel_one");
CMN05_STATIC_ASSERT(sizeof(ns2_ccPad) == 0x108, "ns2_ccPad size");

/* ─── ccPlCondition (size 0x70) ───
 * Evidence: ccPlConditionSet::Add allocates 0x70 for each node.
 * ccPlCondition::Ctrl reads +0x8 (condition_id), +0xc (duration_scaled),
 * +0x10 (param_float), +0x18 (owner_ptr double-indirect).
 * Linked-list intrusive node: next ptr at +0x0.
 * BlockAllocator embedded at +0x38.
 */
struct ns2_ccPlCondition {
    uint64_t next_ptr;          /* +0x00 SIM - intrusive linked list next */
    uint32_t condition_id;      /* +0x08 SIM */
    float    duration_scaled;   /* +0x0C SIM - frames (duration*30.0) */
    float    param_float;       /* +0x10 SIM */
    uint8_t  _pad_14[0x04];     /* +0x14 */
    uint64_t owner_ptr_ptr;     /* +0x18 SIM - **(longlong**)(this+0x18) */
    uint32_t flags;             /* +0x20 SIM */
    uint32_t grp_id;            /* +0x24 SIM - 0xffffffff = none */
    uint8_t  _pad_28[0x10];     /* +0x28 */
    ns2_BlockAllocator allocator; /* +0x38 PRES */
    uint8_t  _pad_48[0x28];     /* +0x48 remainder to 0x70 */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, next_ptr)        == 0x00, "ccPlCondition.next_ptr");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, condition_id)    == 0x08, "ccPlCondition.condition_id");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, duration_scaled) == 0x0C, "ccPlCondition.duration_scaled");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, param_float)     == 0x10, "ccPlCondition.param_float");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, owner_ptr_ptr)   == 0x18, "ccPlCondition.owner_ptr_ptr");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, flags)           == 0x20, "ccPlCondition.flags");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, grp_id)          == 0x24, "ccPlCondition.grp_id");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlCondition, allocator)       == 0x38, "ccPlCondition.allocator");
CMN05_STATIC_ASSERT(sizeof(ns2_ccPlCondition) == 0x70, "ns2_ccPlCondition size");

/* ─── ccPlConditionSet (size >= 0x28) ───
 * Evidence: ccPlConditionSet::Add accesses head at +0x8, tail at +0x10,
 * count at +0x18, durable_per_ptr at +0x20. No constructor found; size lower bound.
 */
struct ns2_ccPlConditionSet {
    uint64_t vtable_or_pad;     /* +0x00 UNKNOWN */
    uint64_t head_ptr;          /* +0x08 SIM - first ccPlCondition node */
    uint64_t tail_ptr;          /* +0x10 SIM - last ccPlCondition node */
    uint64_t count;             /* +0x18 SIM - number of active conditions */
    uint64_t durable_per_ptr;   /* +0x20 SIM - durability percentage ptr */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlConditionSet, vtable_or_pad)   == 0x00, "ccPlConditionSet.vtable_or_pad");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlConditionSet, head_ptr)        == 0x08, "ccPlConditionSet.head_ptr");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlConditionSet, tail_ptr)        == 0x10, "ccPlConditionSet.tail_ptr");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlConditionSet, count)           == 0x18, "ccPlConditionSet.count");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPlConditionSet, durable_per_ptr) == 0x20, "ccPlConditionSet.durable_per_ptr");
CMN05_STATIC_ASSERT(sizeof(ns2_ccPlConditionSet) >= 0x28, "ns2_ccPlConditionSet min size");

/* ─── ccPresenceManager (size >= 0x10) ───
 * Evidence: Pimpl pattern. Impl* at +0x8. Clear writes *(this+0x8)+0x10.
 * Initialize/Finalize are thin wrappers. Size lower bound from impl access.
 */
struct ns2_ccPresenceManager {
    uint64_t vtable_or_pad;     /* +0x00 UNKNOWN */
    uint64_t impl_ptr;          /* +0x08 PRES - ccPresenceManager::Impl* */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns2_ccPresenceManager, vtable_or_pad) == 0x00, "ccPresenceManager.vtable_or_pad");
CMN05_STATIC_ASSERT(offsetof(ns2_ccPresenceManager, impl_ptr)      == 0x08, "ccPresenceManager.impl_ptr");
CMN05_STATIC_ASSERT(sizeof(ns2_ccPresenceManager) >= 0x10, "ns2_ccPresenceManager min size");

#ifdef __cplusplus
}
#endif

#endif /* CMN05_S2_H */
/* ─── ccMovie: no instance state ───
 * All 9 methods (Ctrl@0x5389E8, PauseRenderLayer@0x538AA4, RecoverRenderLayer@0x538B04,
 * Close@0x5389AC, StopAndWaitCompletion@0x538DA8, GetFrame@0x538A20, IsEnd@0x538A6C,
 * GetMovieFileName@0x538A3C, GetMovieVoiceFlag@0x538A54) operate on global/singleton state.
 * state_surface returned 0 fields across all seeds. No struct emitted.
 */

/* ─── ccMessageManager: no instance state ───
 * All 4 methods (SetMessageParam@0x664A20, GetMessageParam@0x664FE0, Create@0x6645F0,
 * GetMessageParam@0x664FB0) operate on global/singleton state.
 * state_surface returned 0 fields across all seeds. No struct emitted.
 */
