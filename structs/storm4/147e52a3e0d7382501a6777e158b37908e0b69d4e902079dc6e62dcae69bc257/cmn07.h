/* cmn07.h — Storm 4 (s4, NSUNS4_release.exe 1.09) struct group cmn07
 * INFERRED from static analysis only. Not CONFIRMED at runtime.
 * Own-game names: no ns3:: prefix; cross-game names marked as such.
 * All offsets re-derived from s4 x64 decompile (image base 0x140000000).
 *
 * POINTER ARITHMETIC KEY:
 * When param_1 is typed as undefined8*, `param_1 + N` = byte offset N*8.
 * When cast to (longlong)param_1 + 0xNN, that is a direct byte offset.
 * This file uses the BYTE offsets as struct field positions.
 */
#ifndef CMN07_S4_H
#define CMN07_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * ccSceneChangeParamBase
 * Size: >= 0x14 (ctor writes qword at byte +0xC; vtable at +0x0)
 * Vtable: PTR_LAB_141114748 (set in ctor 0xABA060)
 * Ctor evidence (0xABA060, param_1 is undefined8*):
 *   *(undefined4 *)(param_1 + 1) = 0xffffffff;  // +1 as u8* = byte +0x08
 *   *param_1 = &PTR_LAB_141114748;              // byte +0x00
 *   *(undefined8 *)((longlong)param_1 + 0xc) = 0; // byte +0x0C
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneChangeParamBase {
    void     *vtable;      /* +0x00: PTR_LAB_141114748 */
    uint32_t  field_0x08;  /* +0x08: init 0xFFFFFFFF */
    uint64_t  param_ptr;   /* +0x0C: zero-init via (longlong) cast */
} ccSceneChangeParamBase;
static_assert(offsetof(ccSceneChangeParamBase, vtable)     == 0x00, "ccSceneChangeParamBase.vtable");
static_assert(offsetof(ccSceneChangeParamBase, field_0x08) == 0x08, "ccSceneChangeParamBase.field_0x08");
static_assert(offsetof(ccSceneChangeParamBase, param_ptr)  == 0x0C, "ccSceneChangeParamBase.param_ptr");

/* =========================================================================
 * ccSceneAssignment
 * Size: >= 0x88 (state_surface field at +0x80 = vtable dispatch)
 * Vtable: PTR_FUN_141114340 (set in ctor 0xAB5040)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneAssignment {
    void     *vtable;          /* +0x00: PTR_FUN_141114340 */
    uint8_t   _pad_08[0x14];   /* +0x08 */
    uint32_t  flag_0x1C;       /* +0x1C */
    uint8_t   _pad_20[0x60];   /* +0x20 */
    void     *vtable_dispatch; /* +0x80 */
} ccSceneAssignment;
static_assert(offsetof(ccSceneAssignment, vtable)          == 0x00, "ccSceneAssignment.vtable");
static_assert(offsetof(ccSceneAssignment, flag_0x1C)       == 0x1C, "ccSceneAssignment.flag_0x1C");
static_assert(offsetof(ccSceneAssignment, vtable_dispatch) == 0x80, "ccSceneAssignment.vtable_dispatch");

/* =========================================================================
 * ccScene
 * Size: >= 0x158C0 (highest field at +0x158B8 is qword)
 * Vtable: PTR_FUN_1411140e8 (ctor 0xAB4360 / dtor 0xAB4400)
 * Secondary vtable: PTR_FUN_1411140d8
 * ========================================================================= */
typedef struct __attribute__((packed)) ccScene {
    void     *vtable;           /* +0x00 */
    uint8_t   _pad_08[0x38];    /* +0x08 */
    void     *secondary_vtbl;   /* +0x40 */
    uint64_t  field_0x48;       /* +0x48 */
    uint8_t   _pad_50[0x10];    /* +0x50 */
    uint8_t   memset_region[0x80]; /* +0x60 */
    uint32_t  field_0xE0;       /* +0xE0 */
    uint8_t   flag_0xE4;        /* +0xE4 */
    uint8_t   _pad_E5[3];       /* +0xE5 */
    void     *field_0xE8;       /* +0xE8 */
    uint8_t   _pad_F0[8];       /* +0xF0 */
    void     *field_0xF8;       /* +0xF8 */
    uint64_t  field_0x100;      /* +0x100 */
    uint64_t  field_0x108;      /* +0x108 */
    uint8_t   _pad_110[0x10];   /* +0x110 */
    uint32_t  field_0x120;      /* +0x120 */
    uint8_t   _pad_124[0xE4];   /* +0x124 */
    uint64_t  field_0x208;      /* +0x208 */
    uint8_t   _pad_210[0x15650];/* +0x210 */
    uint32_t  field_0x15860;    /* +0x15860 */
    uint8_t   _pad_15864[4];    /* +0x15864 */
    uint64_t  field_0x15868;    /* +0x15868 */
    uint64_t  field_0x15870;    /* +0x15870 */
    uint8_t   _pad_15878[0x40]; /* +0x15878 */
    uint64_t  field_0x158B8;    /* +0x158B8 */
} ccScene;
static_assert(offsetof(ccScene, vtable)         == 0x00,    "ccScene.vtable");
static_assert(offsetof(ccScene, secondary_vtbl) == 0x40,    "ccScene.secondary_vtbl");
static_assert(offsetof(ccScene, field_0x48)     == 0x48,    "ccScene.field_0x48");
static_assert(offsetof(ccScene, memset_region)  == 0x60,    "ccScene.memset_region");
static_assert(offsetof(ccScene, field_0xE0)     == 0xE0,    "ccScene.field_0xE0");
static_assert(offsetof(ccScene, flag_0xE4)      == 0xE4,    "ccScene.flag_0xE4");
static_assert(offsetof(ccScene, field_0xE8)     == 0xE8,    "ccScene.field_0xE8");
static_assert(offsetof(ccScene, field_0xF8)     == 0xF8,    "ccScene.field_0xF8");
static_assert(offsetof(ccScene, field_0x100)    == 0x100,   "ccScene.field_100");
static_assert(offsetof(ccScene, field_0x108)    == 0x108,   "ccScene.field_108");
static_assert(offsetof(ccScene, field_0x120)    == 0x120,   "ccScene.field_120");
static_assert(offsetof(ccScene, field_0x208)    == 0x208,   "ccScene.field_208");
static_assert(offsetof(ccScene, field_0x15860)  == 0x15860, "ccScene.field_15860");
static_assert(offsetof(ccScene, field_0x15868)  == 0x15868, "ccScene.field_15868");
static_assert(offsetof(ccScene, field_0x15870)  == 0x15870, "ccScene.field_15870");
static_assert(offsetof(ccScene, field_0x158B8)  == 0x158B8, "ccScene.field_158B8");

/* =========================================================================
 * ccSceneGameRoot
 * Size: >= 0x2D0 (highest field at +0x2CC is uint32)
 * FLAT pattern: ccScene base fields repeated at true offsets
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneGameRoot {
    void     *vtable;           /* +0x00 */
    uint8_t   _pad_08[0x38];    /* +0x08 */
    void     *secondary_vtbl;   /* +0x40 */
    uint64_t  field_0x48;       /* +0x48 */
    uint8_t   _pad_50[0x10];    /* +0x50 */
    uint8_t   base_memset[0x80];/* +0x60 */
    uint8_t   _pad_E0[0x48];    /* +0xE0 */
    void     *base_coord;       /* +0x128 */
    uint8_t   _pad_130[0x198];  /* +0x130 */
    uint32_t  dlc_cmn_param;    /* +0x2C8: IsClearDlcCmnParam output (int) */
    uint32_t  r2b_contents;     /* +0x2CC: IsEnableR2bContents output */
} ccSceneGameRoot;
static_assert(offsetof(ccSceneGameRoot, vtable)         == 0x00,  "ccSceneGameRoot.vtable");
static_assert(offsetof(ccSceneGameRoot, secondary_vtbl) == 0x40,  "ccSceneGameRoot.secondary_vtbl");
static_assert(offsetof(ccSceneGameRoot, base_memset)    == 0x60,  "ccSceneGameRoot.base_memset");
static_assert(offsetof(ccSceneGameRoot, base_coord)     == 0x128, "ccSceneGameRoot.base_coord");
static_assert(offsetof(ccSceneGameRoot, dlc_cmn_param)  == 0x2C8, "ccSceneGameRoot.dlc_cmn_param");
static_assert(offsetof(ccSceneGameRoot, r2b_contents)   == 0x2CC, "ccSceneGameRoot.r2b_contents");

/* =========================================================================
 * ccSceneRoot
 * Size: unknown, >= 0x10 (vtable only; all methods operate on globals)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneRoot {
    void    *vtable;       /* +0x00: inferred */
    uint8_t  _unknown[0x10]; /* +0x08: placeholder */
} ccSceneRoot;
static_assert(offsetof(ccSceneRoot, vtable) == 0x00, "ccSceneRoot.vtable");

/* =========================================================================
 * ccSceneStaffRollHD
 * Size: unknown; state_surface returned 0 fields
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneStaffRollHD {
    void    *vtable;       /* +0x00: inferred */
    uint8_t  _unknown[0x10]; /* +0x08: placeholder */
} ccSceneStaffRollHD;
static_assert(offsetof(ccSceneStaffRollHD, vtable) == 0x00, "ccSceneStaffRollHD.vtable");

/* =========================================================================
 * ccSceneSystemDialogInvited
 * Size: >= 0x88 (vtable dispatch at +0x80)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneSystemDialogInvited {
    void     *vtable;          /* +0x00 */
    uint8_t   _pad_08[0x4C];   /* +0x08 */
    uint32_t  dialog_state;    /* +0x54 */
    uint32_t  field_0x58;      /* +0x58: read as (int) cast, 4 bytes */
    uint32_t  field_0x5C;      /* +0x5C */
    uint8_t   _pad_60[0x20];   /* +0x60 */
    void     *vtable_dispatch; /* +0x80 */
} ccSceneSystemDialogInvited;
static_assert(offsetof(ccSceneSystemDialogInvited, vtable)          == 0x00, "ccSceneSystemDialogInvited.vtable");
static_assert(offsetof(ccSceneSystemDialogInvited, dialog_state)    == 0x54, "ccSceneSystemDialogInvited.dialog_state");
static_assert(offsetof(ccSceneSystemDialogInvited, field_0x58)      == 0x58, "ccSceneSystemDialogInvited.field_0x58");
static_assert(offsetof(ccSceneSystemDialogInvited, field_0x5C)      == 0x5C, "ccSceneSystemDialogInvited.field_0x5C");
static_assert(offsetof(ccSceneSystemDialogInvited, vtable_dispatch) == 0x80, "ccSceneSystemDialogInvited.vtable_dispatch");

/* =========================================================================
 * ccSceneTitle
 * Size: >= 0x140 (highest field at +0x138 is qword)
 * Vtable: inherited from ccScene base
 * ========================================================================= */
typedef struct __attribute__((packed)) ccSceneTitle {
    void     *vtable;            /* +0x00 */
    uint8_t   _pad_08[0x38];     /* +0x08 */
    void     *secondary_vtbl;    /* +0x40 */
    uint64_t  field_0x48;        /* +0x48 */
    uint8_t   _pad_50[0x10];     /* +0x50 */
    uint8_t   base_memset[0x80]; /* +0x60 */
    void     *vtable_slot_0x18;  /* +0xE0: second vtable slot (was misattributed at +0xC0) */
    uint8_t   _pad_E8[0x40];     /* +0xE8 */
    uint32_t  title_mode;        /* +0x128 */
    uint8_t   _pad_12C[4];       /* +0x12C */
    void     *state_machine;     /* +0x130 */
    void     *ui_controller;     /* +0x138 */
} ccSceneTitle;
static_assert(offsetof(ccSceneTitle, vtable)           == 0x00,  "ccSceneTitle.vtable");
static_assert(offsetof(ccSceneTitle, secondary_vtbl)   == 0x40,  "ccSceneTitle.secondary_vtbl");
static_assert(offsetof(ccSceneTitle, base_memset)      == 0x60,  "ccSceneTitle.base_memset");
static_assert(offsetof(ccSceneTitle, vtable_slot_0x18) == 0xE0,  "ccSceneTitle.vtable_slot_0x18");
static_assert(offsetof(ccSceneTitle, title_mode)       == 0x128, "ccSceneTitle.title_mode");
static_assert(offsetof(ccSceneTitle, state_machine)    == 0x130, "ccSceneTitle.state_machine");
static_assert(offsetof(ccSceneTitle, ui_controller)    == 0x138, "ccSceneTitle.ui_controller");

/* =========================================================================
 * ccScriptManager
 * Size: >= 0x1048 (script_buffer[0x1000] at +0x48 ends at +0x1048)
 * Vtable: PTR_FUN_141116880 (dtor 0xADE750)
 * ========================================================================= */
typedef struct __attribute__((packed)) ccScriptManager {
    void    *vtable;                    /* +0x00 */
    uint8_t  _pad_08[0x10];             /* +0x08 */
    void    *lua_state;                 /* +0x18 */
    uint8_t  _pad_20[0x28];             /* +0x20 */
    uint8_t  script_buffer[0x1000];     /* +0x48 */
} ccScriptManager;
static_assert(offsetof(ccScriptManager, vtable)        == 0x00, "ccScriptManager.vtable");
static_assert(offsetof(ccScriptManager, lua_state)     == 0x18, "ccScriptManager.lua_state");
static_assert(offsetof(ccScriptManager, script_buffer) == 0x48, "ccScriptManager.script_buffer");

#endif /* CMN07_S4_H */