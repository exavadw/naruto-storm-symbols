/* st4c01 — Story CUTSCENE / EVENT playback structs for NARUTO STORM 4 PC 1.09 (s4)
 * All layouts INFERRED from static decompilation of NSUNS4_release.exe (sha 147e52a3e0d7).
 * Sizes are unproven unless noted; no sizeof asserts on incomplete types.
 * Own-game names only (Storm 4 symbols/strings). Cross-game references marked.
 */
#ifndef ST4C01_H
#define ST4C01_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* --------------------------------------------------------------------------
 * ccAdvEventManager
 * Evidence: StartTimeCount (0x503D00), SetTimeupDoScriptName (0x503DB8),
 *           callers FUN_1404e5448 (0x4E5448), FUN_1404e5520 (0x4E5520)
 * Size: unknown, >= 0x160 (last proven field at 0x158 is std::string capacity)
 * Vtable: not found in analyzed methods (no virtual calls on param_1)
 * -------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) ccAdvEventManager {
    uint8_t _pad_0x00[0x54];                          /* 0x00 */
    int32_t state_or_type;                            /* 0x54 - set to 2 in caller */
    uint8_t _pad_0x58[0x08];                          /* 0x58 */
    int32_t active_flag;                              /* 0x60 - set to 1 in caller */
    uint8_t _pad_0x64[0x1C];                          /* 0x64 */
    /* std::string at 0x80: script name (StartTimeCount) */
    char*   script_name_ptr;                          /* 0x80 */
    uint64_t script_name_size;                        /* 0x88 */
    uint64_t script_name_cap;                         /* 0x90 - checked >0xf */
    uint64_t script_name_alloc;                       /* 0x98 - capacity threshold */
    uint8_t _pad_0xA0[0x50];                          /* 0xA0 */
    uint32_t flags_f0;                                /* 0xF0 - bitmask from caller */
    int32_t field_f4;                                 /* 0xF4 - param_6 in caller */
    uint32_t field_f8;                                /* 0xF8 - set to 0 */
    uint8_t _pad_0xFC[0x04];                          /* 0xFC */
    uint64_t vec2_or_val_100;                         /* 0x100 - Vector2.x or packed */
    uint8_t _pad_0x108[0x38];                         /* 0x108 */
    /* std::string at 0x140: timeup script name (SetTimeupDoScriptName) */
    char*   timeup_script_ptr;                        /* 0x140 */
    uint64_t timeup_script_size;                      /* 0x148 */
    uint64_t timeup_script_cap;                       /* 0x150 - set to 0 then grown */
    uint64_t timeup_script_alloc;                     /* 0x158 - capacity threshold */
} ccAdvEventManager;

static_assert(offsetof(ccAdvEventManager, state_or_type) == 0x54, "ccAdvEventManager.state_or_type");
static_assert(offsetof(ccAdvEventManager, active_flag) == 0x60, "ccAdvEventManager.active_flag");
static_assert(offsetof(ccAdvEventManager, script_name_ptr) == 0x80, "ccAdvEventManager.script_name_ptr");
static_assert(offsetof(ccAdvEventManager, script_name_size) == 0x88, "ccAdvEventManager.script_name_size");
static_assert(offsetof(ccAdvEventManager, script_name_cap) == 0x90, "ccAdvEventManager.script_name_cap");
static_assert(offsetof(ccAdvEventManager, script_name_alloc) == 0x98, "ccAdvEventManager.script_name_alloc");
static_assert(offsetof(ccAdvEventManager, flags_f0) == 0xF0, "ccAdvEventManager.flags_f0");
static_assert(offsetof(ccAdvEventManager, field_f4) == 0xF4, "ccAdvEventManager.field_f4");
static_assert(offsetof(ccAdvEventManager, field_f8) == 0xF8, "ccAdvEventManager.field_f8");
static_assert(offsetof(ccAdvEventManager, vec2_or_val_100) == 0x100, "ccAdvEventManager.vec2_or_val_100");
static_assert(offsetof(ccAdvEventManager, timeup_script_ptr) == 0x140, "ccAdvEventManager.timeup_script_ptr");
static_assert(offsetof(ccAdvEventManager, timeup_script_size) == 0x148, "ccAdvEventManager.timeup_script_size");
static_assert(offsetof(ccAdvEventManager, timeup_script_cap) == 0x150, "ccAdvEventManager.timeup_script_cap");
static_assert(offsetof(ccAdvEventManager, timeup_script_alloc) == 0x158, "ccAdvEventManager.timeup_script_alloc");

/* --------------------------------------------------------------------------
 * ccAdvMotionEventActor
 * Evidence: FootEvent (0x5057E8), SetCategory (0x50582C), SetMotion (0x50585C),
 *           Update (0x5058A0), caller ccEventAnmState::SetAnm (0x4C0570)
 * Size: unknown, >= 0x138 (last proven field at 0x134)
 * Vtable: not found (no vptr write in ctor-like code)
 * Note: embedded at parent+0xD0 in ccEventAnmState (see SetAnm caller)
 * -------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) ccAdvMotionEventActor {
    uint8_t _pad_0x00[0x08];                          /* 0x00 */
    int32_t current_frame;                            /* 0x08 - compared against computed frame */
    uint8_t _pad_0x0C[0x04];                          /* 0x0C */
    void*   category_ptr;                             /* 0x10 - ccAdvMotionEventCategory* */
    void*   motion_ptr;                               /* 0x18 - ccAdvMotionEventData* (from SearchMotion) */
    char    motion_name[0x100];                       /* 0x20 - nuccStrCpy dest, 256 bytes */
    uint8_t _pad_0x120_unused[0x00];                  /* placeholder alignment */
    int32_t foot_se_id;                               /* 0x120 - passed to ccSndSeOn_AdvFoot */
    uint32_t effect_id;                               /* 0x124 - passed to ccAdvCharaCreateEffect */
    uint8_t _pad_0x128[0x0C];                         /* 0x128 */
    int32_t skip_flag;                                /* 0x134 - if nonzero, Update returns early */
} ccAdvMotionEventActor;

static_assert(offsetof(ccAdvMotionEventActor, current_frame) == 0x08, "ccAdvMotionEventActor.current_frame");
static_assert(offsetof(ccAdvMotionEventActor, category_ptr) == 0x10, "ccAdvMotionEventActor.category_ptr");
static_assert(offsetof(ccAdvMotionEventActor, motion_ptr) == 0x18, "ccAdvMotionEventActor.motion_ptr");
static_assert(offsetof(ccAdvMotionEventActor, motion_name) == 0x20, "ccAdvMotionEventActor.motion_name");
static_assert(offsetof(ccAdvMotionEventActor, foot_se_id) == 0x120, "ccAdvMotionEventActor.foot_se_id");
static_assert(offsetof(ccAdvMotionEventActor, effect_id) == 0x124, "ccAdvMotionEventActor.effect_id");
static_assert(offsetof(ccAdvMotionEventActor, skip_flag) == 0x134, "ccAdvMotionEventActor.skip_flag");

/* --------------------------------------------------------------------------
 * ccAdvSubEventManager
 * Evidence: FindOrInsertParam (0x1D0A78), GetParam variants (0x1D2674, 0x483980,
 *           0x504BA4, 0x51E048)
 * Size: unknown, >= 0x20 (tree root pointer + size/count)
 * Vtable: not found
 * Structure: std::map-like red-black tree. param_1[0] = tree root node ptr,
 *            param_1[1] = end sentinel, param_1[2] = element count.
 * Node layout (from FindOrInsertParam traversal):
 *   node+0x00 = left child ptr, node+0x08 = right child ptr,
 *   node+0x10 = parent ptr, node+0x18 = color/red flag,
 *   node+0x19 = nil/is_header flag, node+0x20 = key string ptr,
 *   node+0x28 = key length, node+0x30 = value data ptr
 * -------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) ccAdvSubEventManager {
    void*   tree_root;                                /* 0x00 - first node or header */
    void*   tree_end;                                 /* 0x08 - end sentinel */
    uint64_t element_count;                           /* 0x10 - number of entries */
    uint8_t _pad_0x18[0x08];                          /* 0x18 */
} ccAdvSubEventManager;

static_assert(offsetof(ccAdvSubEventManager, tree_root) == 0x00, "ccAdvSubEventManager.tree_root");
static_assert(offsetof(ccAdvSubEventManager, tree_end) == 0x08, "ccAdvSubEventManager.tree_end");
static_assert(offsetof(ccAdvSubEventManager, element_count) == 0x10, "ccAdvSubEventManager.element_count");

#endif /* ST4C01_H */