/* cmn05.h — Storm 3 Full Burst HD (NSUNS3.exe-a7124b) common struct group
 * Generated from decompilation cache + state_surface + manual review.
 * All structs __attribute__((packed)), explicit padding, static_assert per field.
 * Rollback tags: SIM = simulation-critical, PRES = presentation-only, UNKNOWN = undetermined.
 * Everything static is INFERRED, not CONFIRMED.
 */
#ifndef CMN05_S3_H
#define CMN05_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* C11 _Static_assert wrapper; C++ uses static_assert natively */
#ifdef __cplusplus
#define CMN05_STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
#define CMN05_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ─── Forward declarations ─── */
typedef struct ns3_ccPad ns3_ccPad;
typedef struct ns3_ccPlCondition ns3_ccPlCondition;
typedef struct ns3_ccPlConditionSet ns3_ccPlConditionSet;
typedef struct ns3_ccPresenceManager ns3_ccPresenceManager;

/* ─── Nucc::Memory::BlockAllocator (embedded, size 0x10 inferred from s2) ─── */
typedef struct ns3_BlockAllocator {
    uint64_t pool_ptr;      /* +0x0 */
    uint64_t alloc_state;   /* +0x8 */
} __attribute__((packed)) ns3_BlockAllocator;
CMN05_STATIC_ASSERT(sizeof(ns3_BlockAllocator) == 0x10, "ns3_BlockAllocator size");

/* ─── ccPad (size 0x108) ───
 * Evidence: ccPad::ccPad (RVA 0x77C3C0) sets vtable at +0x0, clears [0x44..0xF3]
 * in 4 iterations of 0x2c-byte blocks, sentinels at 0xF4(-1), 0xF8(0), 0x100(0), 0x104(1).
 * param_1[0x1f]=0 => +0xF8, param_1+0x20 => +0x100, param_1+3 => +0x18.
 * State surface: r@0x44, w@0xF4,0xF8,0x100,0x104. Size proven by ctor extent.
 */
struct ns3_ccPad {
    uint64_t vtable;            /* +0x00 SIM - PTR_FUN_1409ee500 */
    uint8_t  _pad_08[0x10];     /* +0x08 BlockAllocator region (inferred) */
    uint64_t field_18;          /* +0x18 SIM - set to 1 in ctor (param_1+3) */
    uint8_t  _pad_20[0x24];     /* +0x20 cleared in ctor */
    uint32_t input_state_r;     /* +0x44 SIM - read in Ctrl, cleared in loop */
    uint8_t  _pad_48[0xAC];     /* +0x48 cleared region (4×0x2c blocks) */
    int32_t  sentinel_neg1;     /* +0xF4 SIM - initialized to -1 */
    int32_t  sentinel_zero_a;   /* +0xF8 SIM - initialized to 0 (param_1[0x1f]) */
    uint8_t  _pad_FC[0x04];     /* +0xFC */
    int32_t  sentinel_zero_b;   /* +0x100 SIM - initialized to 0 (param_1+0x20) */
    int32_t  sentinel_one;      /* +0x104 SIM - initialized to 1 */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, vtable)          == 0x00, "ccPad.vtable");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, field_18)        == 0x18, "ccPad.field_18");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, input_state_r)   == 0x44, "ccPad.input_state_r");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, sentinel_neg1)   == 0xF4, "ccPad.sentinel_neg1");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, sentinel_zero_a) == 0xF8, "ccPad.sentinel_zero_a");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, sentinel_zero_b) == 0x100, "ccPad.sentinel_zero_b");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPad, sentinel_one)    == 0x104, "ccPad.sentinel_one");
CMN05_STATIC_ASSERT(sizeof(ns3_ccPad) == 0x108, "ns3_ccPad size");

/* ─── ccPlCondition (size 0x60) ───
 * Evidence: ccPlConditionSet::Add (RVA 0x4FE2F8) allocates 0x60 via LoadTh.
 * Fields initialized at +8(condition_id), +0xc(duration), +0x10(param_float),
 * +0x18(owner_ptr), +0x20(flags=5), +0x24(grp_id=-1), +0x28(=-1).
 * BlockAllocator init at lVar3+0x38 via FUN_1404fe218.
 * Linked-list intrusive node: next ptr at +0x0 (list traversal in Add).
 * ccPlCondition::Ctrl reads +8, +0xc, +0x10, +0x18 confirming layout.
 */
struct ns3_ccPlCondition {
    uint64_t next_ptr;          /* +0x00 SIM - intrusive linked list next */
    uint32_t condition_id;      /* +0x08 SIM */
    float    duration_scaled;   /* +0x0C SIM - frames (duration*30.0), -1.0=infinite */
    float    param_float;       /* +0x10 SIM */
    uint8_t  _pad_14[0x04];     /* +0x14 */
    uint64_t owner_ptr;         /* +0x18 SIM */
    uint32_t flags;             /* +0x20 SIM - default 5 */
    uint32_t grp_id;            /* +0x24 SIM - 0xffffffff = none */
    uint32_t field_28;          /* +0x28 SIM - initialized to 0xffffffff */
    uint8_t  _pad_2C[0x0C];     /* +0x2C */
    ns3_BlockAllocator allocator; /* +0x38 PRES - BlockAllocator embedded */
    uint8_t  _pad_48[0x18];     /* +0x48 remainder to 0x60 */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, next_ptr)        == 0x00, "ccPlCondition.next_ptr");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, condition_id)    == 0x08, "ccPlCondition.condition_id");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, duration_scaled) == 0x0C, "ccPlCondition.duration_scaled");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, param_float)     == 0x10, "ccPlCondition.param_float");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, owner_ptr)       == 0x18, "ccPlCondition.owner_ptr");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, flags)           == 0x20, "ccPlCondition.flags");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, grp_id)          == 0x24, "ccPlCondition.grp_id");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, field_28)        == 0x28, "ccPlCondition.field_28");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlCondition, allocator)       == 0x38, "ccPlCondition.allocator");
CMN05_STATIC_ASSERT(sizeof(ns3_ccPlCondition) == 0x60, "ns3_ccPlCondition size");

/* ─── ccPlConditionSet (size >= 0xa164) ───
 * Evidence: ccPlConditionSet::Ctrl (RVA 0x4FEC70) writes *(undefined4*)(*param_1 + 0xa160) = 0,
 * proving size >= 0xa164. Linked list head at param_1[1] (+0x8).
 * state_surface: r@0x210, w@0x9D8, r@0x3940.
 * Only first few fields named from list structure; rest is opaque.
 */
struct ns3_ccPlConditionSet {
    uint64_t vtable_or_pad;     /* +0x0000 UNKNOWN */
    uint64_t head_ptr;          /* +0x0008 SIM - first ccPlCondition node (list sentinel) */
    uint8_t  _pad_10[0x200];    /* +0x0010 gap to first state_surface field */
    uint32_t field_210;         /* +0x0210 SIM - read in state_surface */
    uint8_t  _pad_214[0x7C4];   /* +0x0214 gap */
    uint32_t field_9D8;         /* +0x09D8 SIM - written in state_surface */
    uint8_t  _pad_9DC[0x2F64];  /* +0x09DC gap */
    uint32_t field_3940;        /* +0x3940 SIM - read in state_surface */
    uint8_t  _pad_3944[0x681C]; /* +0x3944 gap to proven extent */
    uint32_t field_a160;        /* +0xA160 SIM - written zero in Ctrl */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlConditionSet, vtable_or_pad) == 0x0000, "ccPlConditionSet.vtable_or_pad");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlConditionSet, head_ptr)      == 0x0008, "ccPlConditionSet.head_ptr");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlConditionSet, field_210)     == 0x0210, "ccPlConditionSet.field_210");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlConditionSet, field_9D8)     == 0x09D8, "ccPlConditionSet.field_9D8");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlConditionSet, field_3940)    == 0x3940, "ccPlConditionSet.field_3940");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPlConditionSet, field_a160)    == 0xA160, "ccPlConditionSet.field_a160");
CMN05_STATIC_ASSERT(sizeof(ns3_ccPlConditionSet) >= 0xa164, "ns3_ccPlConditionSet min size");

/* ─── ccPresenceManager (size >= 0x10) ───
 * Evidence: Pimpl pattern. Initialize (RVA 0x798150) reads impl_ptr at param_1+8,
 * accesses impl+0x28 flag. Clear writes *(this+0x8)+0x10.
 * Size lower bound from impl_ptr access; actual object may be larger.
 */
struct ns3_ccPresenceManager {
    uint64_t vtable_or_pad;     /* +0x00 UNKNOWN */
    uint64_t impl_ptr;          /* +0x08 PRES - ccPresenceManager::Impl* */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ns3_ccPresenceManager, vtable_or_pad) == 0x00, "ccPresenceManager.vtable_or_pad");
CMN05_STATIC_ASSERT(offsetof(ns3_ccPresenceManager, impl_ptr)      == 0x08, "ccPresenceManager.impl_ptr");
CMN05_STATIC_ASSERT(sizeof(ns3_ccPresenceManager) >= 0x10, "ns3_ccPresenceManager min size");

/* ─── Static/singleton classes (no reconstructible instance fields) ───
 * ccMovie: all methods use global DAT_140c65ec0. StopAndWaitCompletion writes
 *   *param_1 = 0xffffffff (state at offset 0), Close does the same.
 *   No operator new or ctor found; pure static dispatch.
 * ccPauseTaskAccessor: PopPause/PushPause call ccTaskManager with global DAT_*.
 *   GetPauseType takes no param_1. Pure static accessor.
 * ccMessageManager: Create is a static factory calling SetMessageParam.
 *   GetMessageParam/SetMessageParam operate on global state.
 * ccPartyPlayParam: RequestAppCallback and SetAppCallbackFunc are thin wrappers.
 *   No instance field access detected.
 * These classes are listed in the report but have no struct definition here.
 */

#ifdef __cplusplus
}
#endif

#endif /* CMN05_S3_H */