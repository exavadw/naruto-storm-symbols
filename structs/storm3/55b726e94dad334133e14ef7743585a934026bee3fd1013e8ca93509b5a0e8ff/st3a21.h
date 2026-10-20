// st3a21 — Storm 3 challenge mission UI structs (NSUNS3.exe, build s3)
// Reconstructed from Ghidra decompilation of ctors, dtors, factories.
// Confidence: INFERRED (static analysis only; verify with replay trace before CONFIRMED)
// Generated: 2026-10-19

#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

// ============================================================================
// Forward declarations / opaque types
// ============================================================================

// Opaque sub-object used in PanelSP and QuestLogItem classes.
// Pattern: vtable at +0x00, initialized via FUN_140684c60/FUN_140684bc0,
// cleaned up via FUN_14020e3a0. Size varies by context.
typedef struct ccUiSubObject {
    void*    vtable;            // 0x00
    uint8_t  _body[0x20];      // 0x08 opaque body (size depends on subclass)
} ccUiSubObject;

// ============================================================================
// ccUiChallengeMissionFreeCursor
// ============================================================================
// Size: 0x98 (from FUN_1403de1a0: operator new(0x98))
// Vtable: 0x950D78 (set in ctor FUN_1403e3c04)
// Base dtor: FUN_1403e3cb4 → calls FUN_1402acab4, FUN_14020e3a0(+0x68),
//           resets sub-vtable at +0x80 to PTR_FUN_1409ec308
// Factory chain: EnterSelMission → FUN_1403de690 → FUN_1403de1a0 → ctor

struct ccUiChallengeMissionFreeCursor {
    void*    vtable;            // 0x00  PTR_FUN_140950d78
    uint8_t  _base_08[0x30];   // 0x08  base class fields (FUN_14075c590 init)
    uint64_t field_38;          // 0x38  zeroed in ctor
    uint64_t field_40;          // 0x40  FUN_1406a9340 init (sub-object or ptr)
    uint64_t field_48;          // 0x48  FUN_1406a9340 init (sub-object or ptr)
    uint64_t field_50;          // 0x50  set to 1 in ctor
    uint64_t field_58;          // 0x58  FUN_1406843d0(FUN_140684ac0()) init
    uint64_t field_60;          // 0x60  (implicit padding / unused)
    uint64_t field_68;          // 0x68  cleaned by FUN_14020e3a0 in dtor
    uint64_t field_70;          // 0x70  zeroed in ctor
    uint64_t field_78;          // 0x78  zeroed in ctor
    void*    sub_vtable_80;     // 0x80  PTR_FUN_1409ec308 (sub-object vtable)
    uint8_t  _pad_88[0x10];    // 0x88  tail padding to 0x98
};

_Static_assert(sizeof(struct ccUiChallengeMissionFreeCursor) == 0x98,
               "sizeof_ccUiChallengeMissionFreeCursor");
_Static_assert(offsetof(struct ccUiChallengeMissionFreeCursor, vtable) == 0x00,
               "FreeCursor_vtable");
_Static_assert(offsetof(struct ccUiChallengeMissionFreeCursor, field_38) == 0x38,
               "FreeCursor_field_38");
_Static_assert(offsetof(struct ccUiChallengeMissionFreeCursor, field_68) == 0x68,
               "FreeCursor_field_68");
_Static_assert(offsetof(struct ccUiChallengeMissionFreeCursor, sub_vtable_80) == 0x80,
               "FreeCursor_sub_vtable_80");

// ============================================================================
// ccUiChallengeMissionPanelSP sub-object (image panel)
// ============================================================================
// Size: 0x48 (from Initialize: operator new(0x48))
// Vtable: 0x9511C0 (set in sub-ctor FUN_1403e5510)
// Used at PanelSP offsets +0x80 and +0x88

struct ccUiChallengeMissionPanelSP_ImagePanel {
    void*    vtable;            // 0x00  PTR_FUN_1409511c0
    uint8_t  _base_08[0x30];   // 0x08  base class (FUN_14075c590 init)
    uint64_t field_38;          // 0x38  zeroed in sub-ctor
    uint32_t field_40;          // 0x40  zeroed (uint32) in sub-ctor
    uint8_t  _pad_44[0x04];    // 0x44  padding to 0x48
};

_Static_assert(sizeof(struct ccUiChallengeMissionPanelSP_ImagePanel) == 0x48,
               "sizeof_PanelSP_ImagePanel");

// ============================================================================
// ccUiChallengeMissionPanelSP
// ============================================================================
// Size: 0xA0 (from FUN_1403de350: operator new(0xa0))
// Vtable: 0x951330 (set in ctor FUN_1403e5d28)
// Sub-object at +0x38 constructed by FUN_14073d400, then overwritten with
//   PTR_LAB_140951358 (likely a specialized sub-vtable for the main panel host)
// Main panel allocated at +0x78 (size 0x148, loaded from cmission00.xfbin)
// Image panels allocated at +0x80 and +0x88 (each size 0x48)
// Factory chain: EnterSelMission → FUN_1403de7d0 → FUN_1403de350 → ctor

struct ccUiChallengeMissionPanelSP {
    void*    vtable;            // 0x00  PTR_FUN_140951330
    uint8_t  _base_08[0x30];   // 0x08  base class fields (FUN_14075c590 init)
    void*    sub_vtable_38;     // 0x38  PTR_LAB_140951358 (overwritten after FUN_14073d400)
    uint8_t  _field_40[0x38];  // 0x40  gap (part of sub-object or base extension)
    uint64_t main_panel_ptr;    // 0x78  ptr to heap-allocated main panel (size 0x148)
    uint64_t image_panel_ptr_0; // 0x80  ptr to heap-allocated ImagePanel (size 0x48)
    uint64_t image_panel_ptr_1; // 0x88  ptr to heap-allocated ImagePanel (size 0x48)
    uint64_t field_90;          // 0x90  set to 1 in ctor
    uint8_t  _pad_98[0x08];    // 0x98  padding to 0xA0
};

_Static_assert(sizeof(struct ccUiChallengeMissionPanelSP) == 0xA0,
               "sizeof_ccUiChallengeMissionPanelSP");
_Static_assert(offsetof(struct ccUiChallengeMissionPanelSP, vtable) == 0x00,
               "PanelSP_vtable");
_Static_assert(offsetof(struct ccUiChallengeMissionPanelSP, sub_vtable_38) == 0x38,
               "PanelSP_sub_vtable_38");
_Static_assert(offsetof(struct ccUiChallengeMissionPanelSP, main_panel_ptr) == 0x78,
               "PanelSP_main_panel_ptr");
_Static_assert(offsetof(struct ccUiChallengeMissionPanelSP, image_panel_ptr_0) == 0x80,
               "PanelSP_image_panel_ptr_0");
_Static_assert(offsetof(struct ccUiChallengeMissionPanelSP, image_panel_ptr_1) == 0x88,
               "PanelSP_image_panel_ptr_1");
_Static_assert(offsetof(struct ccUiChallengeMissionPanelSP, field_90) == 0x90,
               "PanelSP_field_90");

// ============================================================================
// ccUiQuestLogItemBase (base class for all quest log items)
// ============================================================================
// Constructed by FUN_14022b0e0
// Vtable: 0x8BDC70
// Fields: 0x38..0x48 zeroed, 0x50 (uint32) zeroed, string hash arrays at
//         0x90..0xB8, 0xB8..0xD4, 0xD8..0xEC, sub-object at 0x58 (FUN_14073b140),
//         0x88 zeroed, 0xF0 zeroed

struct ccUiQuestLogItemBase {
    void*    vtable;            // 0x00  PTR_FUN_1408bdc70
    uint8_t  _base_08[0x30];   // 0x08  base class (FUN_14075c3b0 init)
    uint64_t field_38;          // 0x38  zeroed
    uint64_t field_40;          // 0x40  zeroed
    uint64_t field_48;          // 0x48  zeroed
    uint32_t field_50;          // 0x50  zeroed (uint32)
    uint8_t  _pad_54[0x04];    // 0x54  padding
    uint8_t  sub_obj_58[0x30]; // 0x58  FUN_14073b140 init (sub-object)
    uint64_t field_88;          // 0x88  zeroed
    uint8_t  string_hashes_90[0x60]; // 0x90  string hash arrays (3 blocks)
    uint64_t field_f0;          // 0xF0  zeroed
    uint8_t  _pad_f8[0x08];    // 0xF8  padding to 0x100
};

_Static_assert(sizeof(struct ccUiQuestLogItemBase) == 0x100,
               "sizeof_ccUiQuestLogItemBase");
_Static_assert(offsetof(struct ccUiQuestLogItemBase, vtable) == 0x00,
               "QLIBase_vtable");
_Static_assert(offsetof(struct ccUiQuestLogItemBase, field_38) == 0x38,
               "QLIBase_field_38");
_Static_assert(offsetof(struct ccUiQuestLogItemBase, sub_obj_58) == 0x58,
               "QLIBase_sub_obj_58");
_Static_assert(offsetof(struct ccUiQuestLogItemBase, string_hashes_90) == 0x90,
               "QLIBase_string_hashes");

// ============================================================================
// ccUiQuestLogItemMission
// ============================================================================
// Size: 0x158 (from InitializeItem factory FUN_14022a828, param_2==1)
// Vtable: 0x8BE4E0 (set in ctor wrapper FUN_14022eccc)
// Inherits: ccUiQuestLogItemBase (vtable 0x8BDC70, overridden to 0x8BE4E0)
// Base dtor: FUN_14022edc0 → Finalize(0x22EF40) → FUN_14020e3a0(+0x128) →
//           reset sub-vtable at +0x140 → call QuestLogItemBase base dtor
// Initialize: FUN_14022ef94 → FUN_14022bef0(param_1,1,param_1+0x128),
//             sets +0x118=0, iterates array at +0x108 stride 0x28 count at +0x100

struct ccUiQuestLogItemMission {
    // --- ccUiQuestLogItemBase (0x100 bytes) ---
    void*    vtable;            // 0x00  PTR_FUN_1408be4e0 (overrides base 0x8BDC70)
    uint8_t  _base_08[0x30];   // 0x08  base class (FUN_14075c3b0 init)
    uint64_t field_38;          // 0x38  zeroed (from base ctor)
    uint64_t field_40;          // 0x40  zeroed
    uint64_t field_48;          // 0x48  zeroed
    uint32_t field_50;          // 0x50  zeroed
    uint8_t  _pad_54[0x04];    // 0x54
    uint8_t  sub_obj_58[0x30]; // 0x58  FUN_14073b140 init
    uint64_t field_88;          // 0x88  zeroed
    uint8_t  string_hashes_90[0x60]; // 0x90  string hash arrays
    uint64_t field_f0;          // 0xF0  zeroed
    uint8_t  _pad_f8[0x08];    // 0xF8

    // --- ccUiQuestLogItemMission own fields ---
    uint64_t field_100;         // 0x100  array count (iterated in Initialize)
    uint64_t field_108;         // 0x108  array ptr (stride 0x28, iterated in Initialize)
    uint8_t  _field_110[0x08]; // 0x110  unknown
    uint64_t field_118;         // 0x118  set to 0 in Initialize
    uint8_t  _field_120[0x08]; // 0x120  unknown
    uint8_t  sub_obj_128[0x18];// 0x128  cleaned by FUN_14020e3a0 in dtor
    uint8_t  field_140[0x18];  // 0x140  sub-vtable region (reset to PTR_FUN_1409ec308)
};

_Static_assert(sizeof(struct ccUiQuestLogItemMission) == 0x158,
               "sizeof_ccUiQuestLogItemMission");
_Static_assert(offsetof(struct ccUiQuestLogItemMission, vtable) == 0x00,
               "QLIMission_vtable");
_Static_assert(offsetof(struct ccUiQuestLogItemMission, field_100) == 0x100,
               "QLIMission_array_count");
_Static_assert(offsetof(struct ccUiQuestLogItemMission, field_108) == 0x108,
               "QLIMission_array_ptr");
_Static_assert(offsetof(struct ccUiQuestLogItemMission, field_118) == 0x118,
               "QLIMission_field_118");
_Static_assert(offsetof(struct ccUiQuestLogItemMission, sub_obj_128) == 0x128,
               "QLIMission_sub_obj_128");
_Static_assert(offsetof(struct ccUiQuestLogItemMission, field_140) == 0x140,
               "QLIMission_sub_vtable_140");