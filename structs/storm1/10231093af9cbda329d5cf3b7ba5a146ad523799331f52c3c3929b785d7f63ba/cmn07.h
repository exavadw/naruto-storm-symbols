/* cmn07.h -- Storm 1 (s1) struct group: ccScene hierarchy + ccScriptManager
 * INFERRED from static analysis of NSUNS1.exe (sha 10231093af9c).
 * All offsets re-derived from s1 x64 decompile. Names from s1/Trilogy ns1:: only.
 * Sizes proven from operator_new / ctor where noted; otherwise ">= 0xN".
 * FLAT structs: child classes repeat base fields at their true offsets rather
 * than using C embedding, so sizeof is deterministic and gcc-packed layout matches.
 */
#ifndef CMN07_S1_H
#define CMN07_S1_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccSceneChangeParamBase
 * Size >= 0x14. Evidence: ctor RVA 0x5550A0.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneChangeParamBase {
    void * vtable; /* +0x0000: PTR_LAB_140746a00 */
    uint32_t scene_id; /* +0x0008: init 0xFFFFFFFF */
    uint64_t param_ptr; /* +0x000C: init 0 */
} ccSceneChangeParamBase;
static_assert(offsetof(ccSceneChangeParamBase, vtable) == 0x0000, "ccSceneChangeParamBase.vtable");
static_assert(offsetof(ccSceneChangeParamBase, scene_id) == 0x0008, "ccSceneChangeParamBase.scene_id");
static_assert(offsetof(ccSceneChangeParamBase, param_ptr) == 0x000C, "ccSceneChangeParamBase.param_ptr");

/* ========================================================================
 * ccSceneAssignment
 * Size unknown >= 0x08. Minimal; 7 methods but little self-access.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneAssignment {
    void * vtable; /* +0x0000:  */
} ccSceneAssignment;
static_assert(offsetof(ccSceneAssignment, vtable) == 0x0000, "ccSceneAssignment.vtable");

/* ========================================================================
 * ccScene
 * Size unknown >= 0x494. memset(+0xC,0,0x80) in ctor proves region. Highest write +0x490.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccScene {
    void * vtable; /* +0x0000: set by ctor */
    uint8_t _pad_0008[0x68]; /* +0x0008: gap */
    uint64_t name_ptr; /* +0x0070: SetSceneName writes ptr */
    uint32_t name_len; /* +0x0078: SetSceneName writes len */
    uint8_t _pad_007C[0x3C]; /* +0x007C: gap */
    uint64_t field_B8; /* +0x00B8: FUN_14047f900 target */
    uint32_t field_C0; /* +0x00C0: written by SetSceneName */
    uint64_t field_C4; /* +0x00C4: FUN_14047f900 target */
    uint32_t field_CC; /* +0x00CC: written by SetSceneName */
    uint8_t _pad_00D0[0x8]; /* +0x00D0: gap */
    uint32_t field_D8; /* +0x00D8: zeroed by SetSceneName */
    uint32_t field_DC; /* +0x00DC: zeroed by SetSceneName */
    uint32_t field_E0; /* +0x00E0: FUN_14047f900 target */
    uint8_t field_E4; /* +0x00E4: char flag checked in ctor/dtor */
    uint8_t _pad_00E5[0x3]; /* +0x00E5: gap */
    uint8_t field_E8; /* +0x00E8: read as byte in ctor */
    uint8_t _pad_00E9[0x3]; /* +0x00E9: gap */
    uint32_t field_EC; /* +0x00EC: zeroed by SetSceneName */
    uint64_t field_F0; /* +0x00F0: zeroed by SetSceneName */
    uint64_t field_F8; /* +0x00F8: zeroed by dtor */
    uint64_t field_100; /* +0x0100: length check in dtor (>0xF) */
    uint64_t field_108; /* +0x0108: FUN_14047f280 target in dtor */
    uint8_t _pad_0110[0x10]; /* +0x0110: gap */
    uint32_t field_120; /* +0x0120: zeroed in ctor */
    uint8_t _pad_0124[0x2A0]; /* +0x0124: gap */
    uint32_t field_3C4; /* +0x03C4: init 0xFFFFFFFF */
    uint32_t field_3C8; /* +0x03C8: zeroed */
    uint8_t _pad_03CC[0x3C]; /* +0x03CC: gap */
    uint32_t field_408; /* +0x0408: init 0xFFFFFFFF */
    uint8_t _pad_040C[0x80]; /* +0x040C: gap */
    uint32_t field_48C; /* +0x048C: zeroed */
    uint32_t field_490; /* +0x0490: zeroed */
} ccScene;
static_assert(offsetof(ccScene, vtable) == 0x0000, "ccScene.vtable");
static_assert(offsetof(ccScene, name_ptr) == 0x0070, "ccScene.name_ptr");
static_assert(offsetof(ccScene, name_len) == 0x0078, "ccScene.name_len");
static_assert(offsetof(ccScene, field_B8) == 0x00B8, "ccScene.field_B8");
static_assert(offsetof(ccScene, field_C0) == 0x00C0, "ccScene.field_C0");
static_assert(offsetof(ccScene, field_C4) == 0x00C4, "ccScene.field_C4");
static_assert(offsetof(ccScene, field_CC) == 0x00CC, "ccScene.field_CC");
static_assert(offsetof(ccScene, field_D8) == 0x00D8, "ccScene.field_D8");
static_assert(offsetof(ccScene, field_DC) == 0x00DC, "ccScene.field_DC");
static_assert(offsetof(ccScene, field_E0) == 0x00E0, "ccScene.field_E0");
static_assert(offsetof(ccScene, field_E4) == 0x00E4, "ccScene.field_E4");
static_assert(offsetof(ccScene, field_E8) == 0x00E8, "ccScene.field_E8");
static_assert(offsetof(ccScene, field_EC) == 0x00EC, "ccScene.field_EC");
static_assert(offsetof(ccScene, field_F0) == 0x00F0, "ccScene.field_F0");
static_assert(offsetof(ccScene, field_F8) == 0x00F8, "ccScene.field_F8");
static_assert(offsetof(ccScene, field_100) == 0x0100, "ccScene.field_100");
static_assert(offsetof(ccScene, field_108) == 0x0108, "ccScene.field_108");
static_assert(offsetof(ccScene, field_120) == 0x0120, "ccScene.field_120");
static_assert(offsetof(ccScene, field_3C4) == 0x03C4, "ccScene.field_3C4");
static_assert(offsetof(ccScene, field_3C8) == 0x03C8, "ccScene.field_3C8");
static_assert(offsetof(ccScene, field_408) == 0x0408, "ccScene.field_408");
static_assert(offsetof(ccScene, field_48C) == 0x048C, "ccScene.field_48C");
static_assert(offsetof(ccScene, field_490) == 0x0490, "ccScene.field_490");

/* ========================================================================
 * ccSceneGameRoot
 * Inherits ccScene. Extension at +0x128. Size >= 0x138.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneGameRoot {
    void * vtable; /* +0x0000: PTR_FUN_140659c90 (dtor sets before ~ccScene) */
    uint8_t _pad_0008[0x120]; /* +0x0008: gap */
    uint64_t task_ui_begin_screen; /* +0x0128: EntryTask UiBeginScreenPers handle */
    uint64_t task_ui_end_screen; /* +0x0130: EntryTask UiEndScreenPers handle */
} ccSceneGameRoot;
static_assert(offsetof(ccSceneGameRoot, vtable) == 0x0000, "ccSceneGameRoot.vtable");
static_assert(offsetof(ccSceneGameRoot, task_ui_begin_screen) == 0x0128, "ccSceneGameRoot.task_ui_begin_screen");
static_assert(offsetof(ccSceneGameRoot, task_ui_end_screen) == 0x0130, "ccSceneGameRoot.task_ui_end_screen");

/* ========================================================================
 * ccSceneRoot
 * Inherits ccScene. Extension at +0x128. Size >= 0x12C.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneRoot {
    void * vtable; /* +0x0000: not directly observed */
    uint8_t _pad_0008[0x120]; /* +0x0008: gap */
    uint32_t title2Flag; /* +0x0128: int flag checked/set in Execute */
} ccSceneRoot;
static_assert(offsetof(ccSceneRoot, vtable) == 0x0000, "ccSceneRoot.vtable");
static_assert(offsetof(ccSceneRoot, title2Flag) == 0x0128, "ccSceneRoot.title2Flag");

/* ========================================================================
 * ccSceneStaffRollHD
 * Inherits ccScene. Extension at +0x128. Size >= 0x130.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneStaffRollHD {
    void * vtable; /* +0x0000: PTR_FUN_14065a7a0 (dtor) */
    uint8_t _pad_0008[0x120]; /* +0x0008: gap */
    void * state_staff_roll; /* +0x0128: ccStateStaffRoll* allocated in Initialize */
} ccSceneStaffRollHD;
static_assert(offsetof(ccSceneStaffRollHD, vtable) == 0x0000, "ccSceneStaffRollHD.vtable");
static_assert(offsetof(ccSceneStaffRollHD, state_staff_roll) == 0x0128, "ccSceneStaffRollHD.state_staff_roll");

/* ========================================================================
 * ccSceneSystemDialogInvited
 * Inherits ccScene. No extension fields found in s1. Size = ccScene.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneSystemDialogInvited {
    void * vtable; /* +0x0000: inherits ccScene vtable */
} ccSceneSystemDialogInvited;
static_assert(offsetof(ccSceneSystemDialogInvited, vtable) == 0x0000, "ccSceneSystemDialogInvited.vtable");

/* ========================================================================
 * ccSceneTitle
 * Inherits ccScene. Extension at +0x140. Size >= 0x1D8.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneTitle {
    void * vtable; /* +0x0000: inherits ccScene vtable */
    uint8_t _pad_0008[0x138]; /* +0x0008: gap */
    uint64_t button_xfbin_ptrs[6]; /* +0x0140: array of 6 xfbin doc ptrs */
    uint8_t _pad_0170[0x8]; /* +0x0170: gap */
    uint64_t ui_keycfg_002; /* +0x0178: FUN_140171c9c result */
    uint64_t ui_keycfg_003; /* +0x0180: FUN_140171c9c result */
    uint64_t ui_elements[6]; /* +0x0188: array of 6 UI element handles */
    uint64_t ui_keycfg_001; /* +0x01B8: FUN_140171c9c result */
    uint64_t sprite_handle; /* +0x01C0: ccDispSprite::Create result */
    uint8_t _pad_01C8[0x8]; /* +0x01C8: gap */
    uint64_t ui_element_end; /* +0x01D0: last array element position */
} ccSceneTitle;
static_assert(offsetof(ccSceneTitle, vtable) == 0x0000, "ccSceneTitle.vtable");
static_assert(offsetof(ccSceneTitle, button_xfbin_ptrs) == 0x0140, "ccSceneTitle.button_xfbin_ptrs");
static_assert(offsetof(ccSceneTitle, ui_keycfg_002) == 0x0178, "ccSceneTitle.ui_keycfg_002");
static_assert(offsetof(ccSceneTitle, ui_keycfg_003) == 0x0180, "ccSceneTitle.ui_keycfg_003");
static_assert(offsetof(ccSceneTitle, ui_elements) == 0x0188, "ccSceneTitle.ui_elements");
static_assert(offsetof(ccSceneTitle, ui_keycfg_001) == 0x01B8, "ccSceneTitle.ui_keycfg_001");
static_assert(offsetof(ccSceneTitle, sprite_handle) == 0x01C0, "ccSceneTitle.sprite_handle");
static_assert(offsetof(ccSceneTitle, ui_element_end) == 0x01D0, "ccSceneTitle.ui_element_end");

/* ========================================================================
 * ccScreenInputSet
 * Size unknown >= 0x58. Only CreateProperty in s1.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccScreenInputSet {
    void * vtable; /* +0x0000:  */
    uint8_t _pad_0008[0x20]; /* +0x0008: gap */
    uint32_t mode_flag; /* +0x0028: param_1[0xc] >> checked == 1 */
    uint8_t _pad_002C[0x1C]; /* +0x002C: gap */
    void * allocator_0xB8; /* +0x0048: operator_new(0xB8) result */
    void * dynamics_world; /* +0x0050: plCreateDynamicsWorld result */
} ccScreenInputSet;
static_assert(offsetof(ccScreenInputSet, vtable) == 0x0000, "ccScreenInputSet.vtable");
static_assert(offsetof(ccScreenInputSet, mode_flag) == 0x0028, "ccScreenInputSet.mode_flag");
static_assert(offsetof(ccScreenInputSet, allocator_0xB8) == 0x0048, "ccScreenInputSet.allocator_0xB8");
static_assert(offsetof(ccScreenInputSet, dynamics_world) == 0x0050, "ccScreenInputSet.dynamics_world");

/* ========================================================================
 * ccScriptManager
 * Size unknown >= 0x228. Only Erase in s1. Base 0x00..0x187 unknown.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccScriptManager {
    uint8_t _pad_0000[0x188]; /* +0x0000: gap */
    uint8_t critical_section[80]; /* +0x0188: nuccCriticalSection (0x50 bytes) */
    uint8_t script_map_1[40]; /* +0x01D8: std::map tree (0x28 bytes) */
    uint8_t script_map_2[40]; /* +0x0200: second std::map tree (0x28 bytes) */
} ccScriptManager;
static_assert(offsetof(ccScriptManager, critical_section) == 0x0188, "ccScriptManager.critical_section");
static_assert(offsetof(ccScriptManager, script_map_1) == 0x01D8, "ccScriptManager.script_map_1");
static_assert(offsetof(ccScriptManager, script_map_2) == 0x0200, "ccScriptManager.script_map_2");
#endif /* CMN07_S1_H */
