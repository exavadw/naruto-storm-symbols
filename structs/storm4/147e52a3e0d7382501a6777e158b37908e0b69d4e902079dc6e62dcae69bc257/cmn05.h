/* cmn05.h — Storm 4 (NSUNS4_release.exe 1.09, s4) common struct group
 * Generated from decompilation cache + state_surface + manual review.
 * All structs __attribute__((packed)), explicit padding, static_assert per field.
 * Rollback tags: SIM = simulation-critical, PRES = presentation-only, UNKNOWN = undetermined.
 * Everything static is INFERRED, not CONFIRMED.
 */
#ifndef CMN05_S4_H
#define CMN05_S4_H

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
typedef struct ccPad ccPad;
typedef struct ccPlCondition ccPlCondition;
typedef struct ccPlConditionSet ccPlConditionSet;
typedef struct ccPresenceManager ccPresenceManager;

/* ─── Nucc::Memory::BlockAllocator (embedded, size 0x10 inferred from s2/s3) ─── */
typedef struct BlockAllocator {
    uint64_t pool_ptr;      /* +0x0 */
    uint64_t alloc_state;   /* +0x8 */
} __attribute__((packed)) BlockAllocator;
CMN05_STATIC_ASSERT(sizeof(BlockAllocator) == 0x10, "BlockAllocator size");

/* ─── ccPad (size 0x108) ───
 * Evidence: ccPad::ccPad (RVA 0xAD1C30) sets vtable at +0x0, clears [0x44..0xF3]
 * in 4 iterations of 0x2c-byte blocks, sentinels at 0xF4(-1), 0xF8(0), 0x100(0), 0x104(1).
 * param_1[0x1f]=0 => +0xF8, param_1+0x20 => +0x100, param_1+3 => +0x18.
 * DisablePadAll accesses param_1[2], param_1[3], param_1[4] confirming layout.
 * Size proven by ctor extent: last write at +0x104 + 4 bytes = 0x108.
 */
struct ccPad {
    uint64_t vtable;            /* +0x00 SIM - PTR_FUN_141116148 */
    uint8_t _pad_08[0x10];     /* +0x08 BlockAllocator region (inferred) */
    uint64_t field_18;          /* +0x18 SIM - set to 1 in ctor (param_1+3) */
    uint8_t _pad_20[0x24];     /* +0x20 cleared in ctor */
    uint32_t input_state_r;     /* +0x44 SIM - read in Ctrl, cleared in loop */
    uint8_t _pad_48[0xAC];     /* +0x48 cleared region (4×0x2c blocks) */
    int32_t sentinel_neg1;      /* +0xF4 SIM - initialized to -1 */
    int32_t sentinel_zero_a;    /* +0xF8 SIM - initialized to 0 (param_1[0x1f]) */
    uint8_t _pad_FC[0x04];     /* +0xFC */
    int32_t sentinel_zero_b;    /* +0x100 SIM - initialized to 0 (param_1+0x20) */
    int32_t sentinel_one;       /* +0x104 SIM - initialized to 1 */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ccPad, vtable) == 0x00, "ccPad.vtable");
CMN05_STATIC_ASSERT(offsetof(ccPad, field_18) == 0x18, "ccPad.field_18");
CMN05_STATIC_ASSERT(offsetof(ccPad, input_state_r) == 0x44, "ccPad.input_state_r");
CMN05_STATIC_ASSERT(offsetof(ccPad, sentinel_neg1) == 0xF4, "ccPad.sentinel_neg1");
CMN05_STATIC_ASSERT(offsetof(ccPad, sentinel_zero_a) == 0xF8, "ccPad.sentinel_zero_a");
CMN05_STATIC_ASSERT(offsetof(ccPad, sentinel_zero_b) == 0x100, "ccPad.sentinel_zero_b");
CMN05_STATIC_ASSERT(offsetof(ccPad, sentinel_one) == 0x104, "ccPad.sentinel_one");
CMN05_STATIC_ASSERT(sizeof(ccPad) == 0x108, "ccPad size");

/* ─── ccPlCondition (size 0x60) ───
 * Evidence: ccPlConditionSet::Add (RVA 0x765618) allocates 0x60 via operator_new.
 * Fields initialized at +8(condition_id), +0xc(duration_copy), +0x10(duration_scaled),
 * +0x14(param_uint), +0x18(owner_ptr), +0x20(flags=5), +0x24(grp_id=-1), +0x28(=-1).
 * BlockAllocator init at puVar8+7 => +0x38 via FUN_140765538.
 * Linked-list intrusive node: next ptr at +0x0 (set to 0 in Add).
 * ccPlCondition::Ctrl reads +8(condition_id), +0x10(duration_scaled fallback at +0x14),
 * +0x18(owner_ptr) confirming layout.
 */
struct ccPlCondition {
    uint64_t next_ptr;          /* +0x00 SIM - intrusive linked list next */
    uint32_t condition_id;      /* +0x08 SIM */
    float duration_copy;        /* +0x0C SIM - copy of duration_scaled */
    float duration_scaled;      /* +0x10 SIM - frames (duration*30.0), -1.0=infinite */
    uint32_t param_uint;        /* +0x14 SIM - param_4 from Add */
    uint8_t _pad_18_unused[0x00]; /* alignment: owner_ptr at +0x18 naturally */
    uint64_t owner_ptr;         /* +0x18 SIM */
    uint32_t flags;             /* +0x20 SIM - default 5 */
    uint32_t grp_id;            /* +0x24 SIM - 0xffffffff = none */
    uint32_t field_28;          /* +0x28 SIM - initialized to 0xffffffff */
    uint8_t _pad_2C[0x0C];     /* +0x2C */
    BlockAllocator allocator;   /* +0x38 PRES - BlockAllocator embedded */
    uint8_t _pad_48[0x18];     /* +0x48 remainder to 0x60 */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, next_ptr) == 0x00, "ccPlCondition.next_ptr");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, condition_id) == 0x08, "ccPlCondition.condition_id");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, duration_copy) == 0x0C, "ccPlCondition.duration_copy");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, duration_scaled) == 0x10, "ccPlCondition.duration_scaled");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, param_uint) == 0x14, "ccPlCondition.param_uint");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, owner_ptr) == 0x18, "ccPlCondition.owner_ptr");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, flags) == 0x20, "ccPlCondition.flags");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, grp_id) == 0x24, "ccPlCondition.grp_id");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, field_28) == 0x28, "ccPlCondition.field_28");
CMN05_STATIC_ASSERT(offsetof(ccPlCondition, allocator) == 0x38, "ccPlCondition.allocator");
CMN05_STATIC_ASSERT(sizeof(ccPlCondition) == 0x60, "ccPlCondition size");

/* ─── ccPlConditionSet (size unknown, >= 0x28) ───
 * Evidence: ccPlConditionSet::Ctrl (RVA 0x765FB0) accesses std::list at param_1+0x20
 * (plVar1 = param_1+0x20, list head/sentinel). Also reads param_1+0x18 (player ptr).
 * Uses std::__ndk1::__list_imp for condition list management.
 * No large-offset write found in s4 Ctrl (unlike s3 which wrote +0xa160).
 * Minimum size from highest proven access: list at +0x20 + sizeof(std::list) ~0x18 = >= 0x38.
 * Conservative lower bound: >= 0x28 (proven by param_1+0x20 access + pointer deref).
 */
struct ccPlConditionSet {
    uint64_t vtable_or_pad;     /* +0x0000 UNKNOWN */
    uint64_t player_ptr;        /* +0x0008 SIM - ccPlayer*, read in Ctrl as *(param_1+0x18) */
    uint8_t _pad_10[0x08];     /* +0x0010 */
    uint64_t list_head;         /* +0x0018 SIM - std::list head (part of list structure) */
    uint64_t list_sentinel;     /* +0x0020 SIM - std::list sentinel/end iterator */
    uint64_t list_size;         /* +0x0028 SIM - std::list size counter */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ccPlConditionSet, vtable_or_pad) == 0x0000, "ccPlConditionSet.vtable_or_pad");
CMN05_STATIC_ASSERT(offsetof(ccPlConditionSet, player_ptr) == 0x0008, "ccPlConditionSet.player_ptr");
CMN05_STATIC_ASSERT(offsetof(ccPlConditionSet, list_head) == 0x0018, "ccPlConditionSet.list_head");
CMN05_STATIC_ASSERT(offsetof(ccPlConditionSet, list_sentinel) == 0x0020, "ccPlConditionSet.list_sentinel");
CMN05_STATIC_ASSERT(offsetof(ccPlConditionSet, list_size) == 0x0028, "ccPlConditionSet.list_size");
/* Size unknown: only first 0x30 bytes proven. Full object likely larger but no s4 evidence. */

/* ─── ccPresenceManager (size >= 0x10) ───
 * Evidence: Pimpl pattern. Initialize (RVA 0xAE7150) reads impl_ptr at param_1+8,
 * accesses impl+0x28 flag. Clear writes *(this+0x8)+0x10.
 * Size lower bound from impl_ptr access; actual object may be larger.
 */
struct ccPresenceManager {
    uint64_t vtable_or_pad;     /* +0x00 UNKNOWN */
    uint64_t impl_ptr;          /* +0x08 PRES - ccPresenceManager::Impl* */
} __attribute__((packed));
CMN05_STATIC_ASSERT(offsetof(ccPresenceManager, vtable_or_pad) == 0x00, "ccPresenceManager.vtable_or_pad");
CMN05_STATIC_ASSERT(offsetof(ccPresenceManager, impl_ptr) == 0x08, "ccPresenceManager.impl_ptr");
CMN05_STATIC_ASSERT(sizeof(ccPresenceManager) >= 0x10, "ccPresenceManager min size");

/* ─── Static/singleton classes (no reconstructible instance fields) ───
 * Verified via state_surface 2026-10-19. No struct emitted for these classes.
 *
 * ccMovie: no instance state — 8 seeds, 0 fields. SubtitleCtrl@0x8531A0,
 *   CAPTION_LINE@0x7F44C8, PauseRenderLayer@0x8532A0, RecoverRenderLayer@0x853300,
 *   Close@0x853168, StopAndWaitCompletion@0x8536B4, GetFrame@0x853234, IsEnd@0x853268.
 *   All methods use global state. Pure static dispatch through CRI Sofdec2.
 *
 * ccMessageManager: no instance state — 6 seeds, 0 fields. SetMessageParam@0xABCA90,
 *   GetMessageParam@0xABD050/0x4B9D48/0x441710/0xABD020, Create@0xABC660.
 *   Create is a static factory. GetMessageParam/SetMessageParam use globals.
 *
 * ccPauseTaskAccessor: no instance state — 4 seeds, 0 instance fields.
 *   GetPauseType@0x8241E0, PopPause@0x76C68C, PopPauseAll@0xAB91E0, PushPause@0xAB91A0.
 *   GetPauseType reads vtable at *param_1+0x10 (vcall dispatch, not data).
 *   PopPause/PushPause forward to ccTaskManager with global data pointers.
 *
 * ccPartyPlayParam: no instance state — RequestAppCallback and SetAppCallbackFunc
 *   are thin wrappers. No instance field access detected.
 */

#ifdef __cplusplus
}
#endif

#endif /* CMN05_S4_H */