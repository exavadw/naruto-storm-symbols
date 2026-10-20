/* st2a14.h — Story struct group st2a14 for build s2 (NSUNS2.exe)
 * Generated 2026-10-19. All layouts INFERRED from static decompilation.
 * Sizes proven only where CreateScene factory LoadTh argument was found.
 * Own-game names only (ns2:: / Storm 2 symbols and strings).
 * PC offsets only (image base 0x140000000).
 */
#ifndef ST2A14_H
#define ST2A14_H

#include <stdint.h>
#include <stddef.h>

/* Forward declarations for embedded types whose full layout is not in this group.
 * Sizes are INFERRED from allocation sizes seen in constructors. */

/* ccFileLoadListForUi: allocated at 0x30 in ccSceneAdvWorldMapMenu ctor (Reserve(8) after embed).
 * Actual size unknown; placeholder covers the embedded region. */
typedef struct ns2_ccFileLoadListForUi {
    uint8_t _data[0x30]; /* INFERRED size, unproven */
} ns2_ccFileLoadListForUi;

/* ccBaseCoord: embedded at +0x130 in ccSceneMissionSelect, next field at +0x170 => size 0x40. */
typedef struct ns2_ccBaseCoord {
    uint8_t _data[0x40]; /* INFERRED size from field spacing */
} ns2_ccBaseCoord;

/* ccUiSelectWindowNS2: heap-allocated via LoadTh(0x198); pointer stored in parent. */
typedef struct ns2_ccUiSelectWindowNS2 ns2_ccUiSelectWindowNS2;

/* ccUiKeyHelpNS2: heap-allocated via LoadTh(0xb8); pointer stored in parent. */
typedef struct ns2_ccUiKeyHelpNS2 ns2_ccUiKeyHelpNS2;

/* ccUiAdvMissionIndex: heap-allocated via LoadTh(0xf8); pointer stored in parent. */
typedef struct ns2_ccUiAdvMissionIndex ns2_ccUiAdvMissionIndex;

/* ccMsgDialog: heap-allocated via LoadTh(0x88); pointer stored in parent. */
typedef struct ns2_ccMsgDialog ns2_ccMsgDialog;

/* ccUiFontNS2: heap-allocated; pointer stored in parent. */
typedef struct ns2_ccUiFontNS2 ns2_ccUiFontNS2;

/* ccUiAdvResultSuccess: heap-allocated via LoadTh(0x70); pointer stored in parent. */
typedef struct ns2_ccUiAdvResultSuccess ns2_ccUiAdvResultSuccess;

/* Opaque menu object returned by FUN_140355550 in ccSceneMissionSelect. */
typedef struct ns2_ccMenuMissionSelect ns2_ccMenuMissionSelect;

/* --- Reconstructed classes ------------------------------------------------ */

/* ccSceneAdvWorldMapMenu
 * PROVEN size = 0x180 (CreateScene<ccSceneAdvWorldMapMenu> LoadTh(0x180))
 * Vtable: PTR_FUN_14082d898 (assigned in ctor RVA 0x4137D8)
 * Base: ccScene (0x128 bytes assumed from first custom field at +0x128)
 */
typedef struct __attribute__((packed)) ns2_ccSceneAdvWorldMapMenu {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    uint64_t field_0x128;                     /* zeroed in ctor, type unknown */
    uint64_t field_0x130;                     /* zeroed in ctor, type unknown */
    uint64_t field_0x138;                     /* zeroed in ctor, type unknown */
    uint64_t field_0x140;                     /* zeroed in ctor, type unknown */
    uint64_t field_0x148;                     /* set to 1 in ctor */
    ns2_ccFileLoadListForUi file_load_list;   /* +0x150, embedded, ctor calls ccFileLoadListForUi::Reserve(8) */
    uint8_t _pad_0x180[0x180 - 0x150 - 0x30]; /* pad to proven size */
} ns2_ccSceneAdvWorldMapMenu;

_Static_assert(offsetof(ns2_ccSceneAdvWorldMapMenu, field_0x128) == 0x128, "field_0x128 offset");
_Static_assert(offsetof(ns2_ccSceneAdvWorldMapMenu, field_0x130) == 0x130, "field_0x130 offset");
_Static_assert(offsetof(ns2_ccSceneAdvWorldMapMenu, field_0x138) == 0x138, "field_0x138 offset");
_Static_assert(offsetof(ns2_ccSceneAdvWorldMapMenu, field_0x140) == 0x140, "field_0x140 offset");
_Static_assert(offsetof(ns2_ccSceneAdvWorldMapMenu, field_0x148) == 0x148, "field_0x148 offset");
_Static_assert(offsetof(ns2_ccSceneAdvWorldMapMenu, file_load_list) == 0x150, "file_load_list offset");
_Static_assert(sizeof(ns2_ccSceneAdvWorldMapMenu) == 0x180, "ccSceneAdvWorldMapMenu proven size");

/* ccSceneMissionSelect
 * PROVEN size = 0x1b8 (CreateScene<ccSceneMissionSelect> LoadTh(0x1b8))
 * Vtable: PTR_FUN_14083ee38 (assigned in ctor RVA 0x45E038)
 * Base: ccScene
 */
typedef struct __attribute__((packed)) ns2_ccSceneMissionSelect {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    uint64_t menu_obj;                        /* +0x128, ptr to ccMenuMissionSelect or null */
    ns2_ccBaseCoord base_coord;               /* +0x130, embedded ccBaseCoord */
    ns2_ccFileLoadListForUi file_load_list;   /* +0x170, embedded, Reserve(0x18) */
    uint8_t _gap_0x1A0[0x1A8 - 0x1A0];       /* gap: no accesses seen between 0x1A0-0x1A7 */
    uint64_t duel_result_ptr;                 /* +0x1A8, ptr used by ccApplyDuelResult */
    uint8_t _pad_to_size[0x1B8 - 0x1B0];     /* pad to proven size */
} ns2_ccSceneMissionSelect;

_Static_assert(offsetof(ns2_ccSceneMissionSelect, menu_obj) == 0x128, "menu_obj offset");
_Static_assert(offsetof(ns2_ccSceneMissionSelect, base_coord) == 0x130, "base_coord offset");
_Static_assert(offsetof(ns2_ccSceneMissionSelect, file_load_list) == 0x170, "file_load_list offset");
_Static_assert(offsetof(ns2_ccSceneMissionSelect, duel_result_ptr) == 0x1A8, "duel_result_ptr offset");
_Static_assert(sizeof(ns2_ccSceneMissionSelect) == 0x1B8, "ccSceneMissionSelect proven size");

/* ccSceneAdvStartModeSelect
 * Size UNKNOWN, >= 0x148 (last field at +0x140 is a pointer, +8 = 0x148 minimum)
 * No CreateScene factory found; no vtable identified.
 * Fields from Initialize (RVA 0x4134E0): 3x ccUiSelectWindowNS2* + 1x ccMsgDialog*
 */
typedef struct __attribute__((packed)) ns2_ccSceneAdvStartModeSelect {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    ns2_ccUiSelectWindowNS2 *select_window_1; /* +0x128, Ctrl(1)/Draw(1) */
    ns2_ccUiSelectWindowNS2 *select_window_2; /* +0x130, Ctrl(2)/Draw(2) */
    ns2_ccUiSelectWindowNS2 *select_window_3; /* +0x138, Ctrl(3)/Draw(3) */
    ns2_ccMsgDialog *msg_dialog;              /* +0x140, ccMsgDialog */
    /* size unknown, >= 0x148 — no sizeof assert */
} ns2_ccSceneAdvStartModeSelect;

_Static_assert(offsetof(ns2_ccSceneAdvStartModeSelect, select_window_1) == 0x128, "select_window_1 offset");
_Static_assert(offsetof(ns2_ccSceneAdvStartModeSelect, select_window_2) == 0x130, "select_window_2 offset");
_Static_assert(offsetof(ns2_ccSceneAdvStartModeSelect, select_window_3) == 0x138, "select_window_3 offset");
_Static_assert(offsetof(ns2_ccSceneAdvStartModeSelect, msg_dialog) == 0x140, "msg_dialog offset");

/* ccSceneMissionCheckMenu
 * Size UNKNOWN, >= 0x1E8 (highest field access at +0x1E4 as int32, +4 = 0x1E8 minimum)
 * No CreateScene factory found; no vtable identified.
 * Fields from Initialize (RVA 0x45C6A0)
 */
typedef struct __attribute__((packed)) ns2_ccSceneMissionCheckMenu {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    ns2_ccUiKeyHelpNS2 *key_help;             /* +0x128, ccUiKeyHelpNS2* */
    ns2_ccUiFontNS2 *font;                    /* +0x130, ccUiFontNS2* */
    uint64_t field_0x138;                     /* +0x138, vtable-like ptr deref'd with +0x28 call */
    uint64_t field_0x140;                     /* +0x140, copied to +0x1D8 conditionally */
    uint8_t _gap_0x148[0x1A0 - 0x148];       /* gap: no accesses seen between 0x148-0x19F */
    uint64_t field_0x1A0;                     /* +0x1A0, data ptr block start */
    uint64_t field_0x1A8;                     /* +0x1A8 */
    uint64_t field_0x1B0;                     /* +0x1B0 */
    uint64_t field_0x1B8;                     /* +0x1B8 */
    uint64_t field_0x1C0;                     /* +0x1C0 */
    uint64_t field_0x1C8;                     /* +0x1C8, overwritten with *puVar2 */
    int32_t field_0x1D0;                      /* +0x1D0, count (iVar9) */
    uint32_t field_0x1D4_pad;                 /* padding to align */
    uint64_t field_0x1D8;                     /* +0x1D8, copy of field_0x140 or 0 */
    int32_t item_count;                       /* +0x1E0, iVar9 again */
    int32_t completion_pct;                   /* +0x1E4, float*0.25*100 cast to int */
    /* size unknown, >= 0x1E8 — no sizeof assert */
} ns2_ccSceneMissionCheckMenu;

_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, key_help) == 0x128, "key_help offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, font) == 0x130, "font offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x138) == 0x138, "field_0x138 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x140) == 0x140, "field_0x140 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1A0) == 0x1A0, "field_0x1A0 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1A8) == 0x1A8, "field_0x1A8 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1B0) == 0x1B0, "field_0x1B0 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1B8) == 0x1B8, "field_0x1B8 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1C0) == 0x1C0, "field_0x1C0 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1C8) == 0x1C8, "field_0x1C8 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1D0) == 0x1D0, "field_0x1D0 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, field_0x1D8) == 0x1D8, "field_0x1D8 offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, item_count) == 0x1E0, "item_count offset");
_Static_assert(offsetof(ns2_ccSceneMissionCheckMenu, completion_pct) == 0x1E4, "completion_pct offset");

/* ccSceneMissionResult
 * Size UNKNOWN, >= 0x150 (last field at +0x148 is a pointer, +8 = 0x150 minimum)
 * No CreateScene factory found; no vtable identified.
 * Fields from Initialize (RVA 0x45D184)
 */
typedef struct __attribute__((packed)) ns2_ccSceneMissionResult {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    uint8_t _gap_0x128[0x148 - 0x128];       /* gap: no accesses seen */
    ns2_ccUiKeyHelpNS2 *key_help;             /* +0x148, ccUiKeyHelpNS2* */
    /* size unknown, >= 0x150 — no sizeof assert */
} ns2_ccSceneMissionResult;

_Static_assert(offsetof(ns2_ccSceneMissionResult, key_help) == 0x148, "key_help offset");

/* ccSceneMissionResultSuccess
 * Inherits from ccSceneMissionResult (calls ccSceneMissionResult::Initialize).
 * Size UNKNOWN, >= 0x178 (last field at +0x170 is a pointer, +8 = 0x178 minimum)
 * Additional fields from Initialize (RVA 0x45D7C8) beyond inherited +0x148.
 * Note: LoadTh(param_1 + 0x178, ...) passes ADDRESS not size — not an allocation.
 */
typedef struct __attribute__((packed)) ns2_ccSceneMissionResultSuccess {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    uint8_t _gap_0x128[0x134 - 0x128];       /* gap */
    uint32_t result_flag;                     /* +0x134, set to 1 in Initialize */
    uint8_t _gap_0x138[0x148 - 0x138];       /* gap */
    ns2_ccUiKeyHelpNS2 *key_help;             /* +0x148, inherited from ccSceneMissionResult */
    uint8_t _gap_0x150[0x168 - 0x150];       /* gap */
    uint32_t softfocus_param;                 /* +0x168, from ccGameDrawEnv::GetSoftfocusParamPtr */
    uint32_t _pad_0x16C;                      /* alignment padding */
    ns2_ccUiAdvResultSuccess *result_success; /* +0x170, advResultSuccess UI object */
    /* size unknown, >= 0x178 — no sizeof assert */
} ns2_ccSceneMissionResultSuccess;

_Static_assert(offsetof(ns2_ccSceneMissionResultSuccess, result_flag) == 0x134, "result_flag offset");
_Static_assert(offsetof(ns2_ccSceneMissionResultSuccess, key_help) == 0x148, "key_help offset");
_Static_assert(offsetof(ns2_ccSceneMissionResultSuccess, softfocus_param) == 0x168, "softfocus_param offset");
_Static_assert(offsetof(ns2_ccSceneMissionResultSuccess, result_success) == 0x170, "result_success offset");

/* ccSceneMissionSelectWindow
 * Size UNKNOWN, >= 0x138 (last field at +0x130 is a pointer, +8 = 0x138 minimum)
 * No CreateScene factory found; no vtable identified.
 * Fields from Initialize (RVA 0x45E838)
 */
typedef struct __attribute__((packed)) ns2_ccSceneMissionSelectWindow {
    uint8_t base_ccScene[0x128];              /* ccScene base, INFERRED size */
    uint8_t _gap_0x128[0x130 - 0x128];       /* gap */
    ns2_ccUiAdvMissionIndex *mission_index;   /* +0x130, ccUiAdvMissionIndex* */
    /* size unknown, >= 0x138 — no sizeof assert */
} ns2_ccSceneMissionSelectWindow;

_Static_assert(offsetof(ns2_ccSceneMissionSelectWindow, mission_index) == 0x130, "mission_index offset");

/* Classes with 0 recoverable fields (state_surface returned 0 typed accesses):
 *   ccSceneAdvMmp — 5 seeds, all byte-cast only
 *   ccSceneAdvPauseMenu — 7 seeds, all byte-cast only
 *   ccSceneAdvStateMachine — 3 seeds, all byte-cast only
 * These exist in the binary but have no named/typed field evidence.
 *
 * Classes skipped (< 3 methods, per task rules):
 *   ccSceneChangeParamAdvItemMenu (1 method)
 *   ccSceneChangeParamAdvStartModeSelect (1 method)
 *   ccSceneChangeParamAdvWorldMapMenu (1 method)
 *   ccSceneChangeParamMissionSelectWindow (1 method)
 */

#endif /* ST2A14_H */