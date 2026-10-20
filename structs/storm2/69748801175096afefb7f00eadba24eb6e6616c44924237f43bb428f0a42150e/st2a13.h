/*
 * st2a13.h — Story progression structs for NARUTO STORM 2 (s2, NSUNS2.exe)
 *
 * All layouts INFERRED from static analysis of s2 build (SHA 697488011750).
 * PC x64 offsets only (image base 0x140000000). Not CONFIRMED by runtime trace.
 * Sizes proven from game code where possible; otherwise noted as minimum.
 *
 * Build: s2 Program: /NSUNS2.exe-abf2b6
 */
#ifndef ST2A13_H
#define ST2A13_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================= */
/* ccAdvUiTargetManager                                                      */
/* ctor RVA 0x1E8590, vtable 0x14079F600                                     */
/* Size INFERRED >= 0x40 (last field ccBuildUniqueId at +0x38)               */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccAdvUiTargetManager {
    /* +0x00 */ void     *vtable;       /* 0x14079F600 */
    /* +0x08 */ uint32_t  pad_0x08;     /* zeroed in ctor */
    /* +0x0C */ uint32_t  field_0x0C;   /* surface: write-only, set to 1 in ctor */
    /* +0x10 */ uint8_t   embedded_obj[0x28]; /* FUN_1401e8524(param_1+2) */
    /* +0x38 */ uint8_t   uniqueId[8];  /* ccBuildUniqueId ctor at param_1+7, size unproven */
} ns2_ccAdvUiTargetManager;

static_assert(offsetof(ns2_ccAdvUiTargetManager, vtable)       == 0x00, "ccAdvUiTargetManager.vtable");
static_assert(offsetof(ns2_ccAdvUiTargetManager, pad_0x08)     == 0x08, "ccAdvUiTargetManager.pad_0x08");
static_assert(offsetof(ns2_ccAdvUiTargetManager, field_0x0C)   == 0x0C, "ccAdvUiTargetManager.field_0x0C");
static_assert(offsetof(ns2_ccAdvUiTargetManager, embedded_obj) == 0x10, "ccAdvUiTargetManager.embedded_obj");
static_assert(offsetof(ns2_ccAdvUiTargetManager, uniqueId)     == 0x38, "ccAdvUiTargetManager.uniqueId");

/* ========================================================================= */
/* ccAdvWindowManager                                                        */
/* ctor RVA 0x66E1D0                                                         */
/* Size INFERRED >= 0x78 (last surface field at +0x70, 8 bytes)              */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccAdvWindowManager {
    /* +0x00 */ void     *vtable;
    /* +0x08 */ uint32_t  field_0x08;       /* 0xFFFFFFFF in ctor (param_1[1]) */
    /* +0x0C */ uint32_t  field_0x0C;       /* surface sz=4 */
    /* +0x10 */ uint64_t  field_0x10;       /* zeroed */
    /* +0x18 */ uint64_t  field_0x18;       /* zeroed */
    /* +0x20 */ uint64_t  field_0x20;       /* zeroed */
    /* +0x28 */ uint64_t  field_0x28;       /* zeroed */
    /* +0x30 */ uint64_t  blockAllocator;   /* surface sz=8, BlockAllocator */
    /* +0x38 */ uint8_t   pad_0x38[0x10];
    /* +0x48 */ uint32_t  field_0x48;       /* surface sz=4 */
    /* +0x4C */ uint8_t   pad_0x4C[4];
    /* +0x50 */ uint64_t  field_0x50;       /* surface sz=8, ptr */
    /* +0x58 */ uint8_t   field_0x58;       /* surface sz=1, byte flag */
    /* +0x59 */ uint8_t   pad_0x59[3];
    /* +0x5C */ uint32_t  field_0x5C;       /* surface sz=4, value 0x450 */
    /* +0x60 */ uint64_t  field_0x60;       /* surface sz=8 */
    /* +0x68 */ uint64_t  field_0x68;       /* surface sz=8 */
    /* +0x70 */ uint64_t  field_0x70;       /* surface sz=8 */
} ns2_ccAdvWindowManager;

static_assert(offsetof(ns2_ccAdvWindowManager, vtable)         == 0x00, "ccAdvWindowManager.vtable");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x08)     == 0x08, "ccAdvWindowManager.field_0x08");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x0C)     == 0x0C, "ccAdvWindowManager.field_0x0C");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x10)     == 0x10, "ccAdvWindowManager.field_0x10");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x18)     == 0x18, "ccAdvWindowManager.field_0x18");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x20)     == 0x20, "ccAdvWindowManager.field_0x20");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x28)     == 0x28, "ccAdvWindowManager.field_0x28");
static_assert(offsetof(ns2_ccAdvWindowManager, blockAllocator) == 0x30, "ccAdvWindowManager.blockAllocator");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x48)     == 0x48, "ccAdvWindowManager.field_0x48");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x50)     == 0x50, "ccAdvWindowManager.field_0x50");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x58)     == 0x58, "ccAdvWindowManager.field_0x58");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x5C)     == 0x5C, "ccAdvWindowManager.field_0x5C");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x60)     == 0x60, "ccAdvWindowManager.field_0x60");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x68)     == 0x68, "ccAdvWindowManager.field_0x68");
static_assert(offsetof(ns2_ccAdvWindowManager, field_0x70)     == 0x70, "ccAdvWindowManager.field_0x70");

/* ========================================================================= */
/* ccAdvWindowManager::Item                                                  */
/* ctor RVA 0x1EA168, vtable 0x14079FC50                                     */
/* Size INFERRED >= 0x20                                                     */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccAdvWindowManager_Item {
    /* +0x00 */ void     *vtable;            /* 0x14079FC50 */
    /* +0x08 */ void     *ccWindowItem_ptr;  /* zeroed */
    /* +0x10 */ void     *ccWindowItemList_ptr; /* zeroed */
    /* +0x18 */ uint32_t  field_0x18;        /* zeroed */
    /* +0x1C */ uint8_t   pad_0x1C[4];
} ns2_ccAdvWindowManager_Item;

static_assert(offsetof(ns2_ccAdvWindowManager_Item, vtable)             == 0x00, "Item.vtable");
static_assert(offsetof(ns2_ccAdvWindowManager_Item, ccWindowItem_ptr)   == 0x08, "Item.ccWindowItem_ptr");
static_assert(offsetof(ns2_ccAdvWindowManager_Item, ccWindowItemList_ptr) == 0x10, "Item.ccWindowItemList_ptr");
static_assert(offsetof(ns2_ccAdvWindowManager_Item, field_0x18)         == 0x18, "Item.field_0x18");

/* ========================================================================= */
/* ccAdvWindowManager::Select                                                */
/* No constructor/Initialize found with field writes. Minimal placeholder.   */
/* Size UNKNOWN, >= 0x8                                                      */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccAdvWindowManager_Select {
    /* +0x00 */ void *vtable;
} ns2_ccAdvWindowManager_Select;

static_assert(offsetof(ns2_ccAdvWindowManager_Select, vtable) == 0x00, "Select.vtable");

/* ========================================================================= */
/* ccMenuAdvCharacterSelect                                                  */
/* Initialize RVA 0x34A9A4                                                   */
/* Size INFERRED >= 0x1A0 (fileLoadList region at +0x180)                    */
/* Offsets verified: memberCharIds at +0x40 (4x int32), memberCount at +0x50 */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccMenuAdvCharacterSelect {
    /* +0x00 */ void     *vtable;
    /* +0x08 */ uint32_t  field_0x08;           /* 0xFFFFFFFF at end of Init */
    /* +0x0C */ uint32_t  field_0x0C;           /* zeroed */
    /* +0x10 */ uint8_t   pad_0x10[4];
    /* +0x14 */ uint64_t  field_0x14;           /* set to 1 */
    /* +0x1C */ uint64_t  field_0x1C;           /* zeroed */
    /* +0x24 */ uint8_t   pad_0x24[0x1C];
    /* +0x40 */ int32_t   memberCharIds[4];     /* 4 member char ids */
    /* +0x50 */ uint32_t  memberCount;          /* counted non-zero entries */
    /* +0x54 */ uint8_t   pad_0x54[4];
    /* +0x58 */ void     *adv_cmn_xfbin;
    /* +0x60 */ void     *adv_cmn_text_xfbin;
    /* +0x68 */ void     *adv_face_handles[4];
    /* +0x88 */ uint8_t   pad_0x88[0x30];       /* gap to +0xB8 */
    /* +0xB8 */ void     *adv_sel_csr;
    /* +0xC0 */ void     *adv_csricon_handles[4];
    /* +0xE0 */ void     *adv_sel_spt_win;
    /* +0xE8 */ void     *adv_sel_csr_l;
    /* +0xF0 */ void     *adv_spttype_handles2[3];
    /* +0x108 */ uint8_t  pad_0x108[0x28];
    /* +0x130 */ void    *adv_mark02_handles[2];
    /* +0x140 */ uint8_t  pad_0x140[0x40];
    /* +0x180 */ uint8_t  fileLoadList[0x20];   /* ccFileLoadListForUi region */
} ns2_ccMenuAdvCharacterSelect;

static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, vtable)             == 0x00,  "MenuAdvCharSel.vtable");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, field_0x08)         == 0x08,  "MenuAdvCharSel.field_0x08");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, field_0x0C)         == 0x0C,  "MenuAdvCharSel.field_0x0C");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, field_0x14)         == 0x14,  "MenuAdvCharSel.field_0x14");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, field_0x1C)         == 0x1C,  "MenuAdvCharSel.field_0x1C");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, memberCharIds)      == 0x40,  "MenuAdvCharSel.memberCharIds");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, memberCount)        == 0x50,  "MenuAdvCharSel.memberCount");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_cmn_xfbin)      == 0x58,  "MenuAdvCharSel.adv_cmn_xfbin");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_cmn_text_xfbin) == 0x60,  "MenuAdvCharSel.adv_cmn_text_xfbin");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_face_handles)   == 0x68,  "MenuAdvCharSel.adv_face_handles");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_sel_csr)        == 0xB8,  "MenuAdvCharSel.adv_sel_csr");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_csricon_handles)== 0xC0,  "MenuAdvCharSel.adv_csricon_handles");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_sel_spt_win)    == 0xE0,  "MenuAdvCharSel.adv_sel_spt_win");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_sel_csr_l)      == 0xE8,  "MenuAdvCharSel.adv_sel_csr_l");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, adv_mark02_handles) == 0x130, "MenuAdvCharSel.adv_mark02_handles");
static_assert(offsetof(ns2_ccMenuAdvCharacterSelect, fileLoadList)       == 0x180, "MenuAdvCharSel.fileLoadList");

/* ========================================================================= */
/* ccMenuDuelResultHeadValue                                                 */
/* ctor RVA 0x3507C0, vtable 0x1407FA590                                     */
/* Size INFERRED >= 0x140 (embedded ccCameraManipulator at +0x100)           */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccMenuDuelResultHeadValue {
    /* +0x00 */ void    *vtable;           /* 0x1407FA590 */
    /* +0x08 */ uint8_t  pad_0x08[0xF8];
    /* +0x100 */ uint8_t cameraManip[0x40]; /* ccCameraManipulator, size unproven */
} ns2_ccMenuDuelResultHeadValue;

static_assert(offsetof(ns2_ccMenuDuelResultHeadValue, vtable)      == 0x00,  "DuelResultHeadValue.vtable");
static_assert(offsetof(ns2_ccMenuDuelResultHeadValue, cameraManip) == 0x100, "DuelResultHeadValue.cameraManip");

/* ========================================================================= */
/* ccMenuMissionSelect                                                       */
/* Initialize RVA 0x355968                                                   */
/* Size INFERRED >= 0xA8 (last access at param_1+0xA0)                       */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccMenuMissionSelect {
    /* +0x00 */ void     *vtable;
    /* +0x08 */ uint32_t  field_0x08;           /* zeroed */
    /* +0x0C */ uint32_t  field_0x0C;           /* set to 1 */
    /* +0x10 */ uint64_t  field_0x10;           /* zeroed */
    /* +0x18 */ uint32_t  field_0x18;           /* zeroed */
    /* +0x1C */ int32_t   missionBattleIds[8];  /* up to 8 entries */
    /* +0x3C */ uint8_t   pad_0x3C[4];
    /* +0x40 */ uint32_t  missionBattleCount;
    /* +0x44 */ uint8_t   pad_0x44[4];
    /* +0x48 */ uint32_t  field_0x48;           /* zeroed */
    /* +0x4C */ uint8_t   pad_0x4C[4];
    /* +0x50 */ void     *uiSelectWindow;       /* ccUiSelectWindowNS2* */
    /* +0x58 */ void     *uiMenuIndex;          /* ccUiMenuIndex* */
    /* +0x60 */ void     *uiChapterSelect;      /* ccUiChapterSelect* */
    /* +0x68 */ void     *uiMissionBattleSelect;  /* ccUiMissionBattleSelect* */
    /* +0x70 */ void     *uiMissionBattleDetail;  /* ccUiMissionBattleDetail* */
    /* +0x78 */ uint8_t   pad_0x78[0x14];
    /* +0x8C */ float     opacity;              /* 0x3F800000 = 1.0f */
    /* +0x90 */ void     *menuBackClump;        /* xfbin handle */
    /* +0x98 */ void     *bgObjClump;           /* xfbin handle */
    /* +0xA0 */ uint8_t   fileLoadList[0x38];   /* ccFileLoadListForUi region */
} ns2_ccMenuMissionSelect;

static_assert(offsetof(ns2_ccMenuMissionSelect, vtable)                == 0x00, "MenuMissionSel.vtable");
static_assert(offsetof(ns2_ccMenuMissionSelect, field_0x08)            == 0x08, "MenuMissionSel.field_0x08");
static_assert(offsetof(ns2_ccMenuMissionSelect, field_0x0C)            == 0x0C, "MenuMissionSel.field_0x0C");
static_assert(offsetof(ns2_ccMenuMissionSelect, field_0x10)            == 0x10, "MenuMissionSel.field_0x10");
static_assert(offsetof(ns2_ccMenuMissionSelect, field_0x18)            == 0x18, "MenuMissionSel.field_0x18");
static_assert(offsetof(ns2_ccMenuMissionSelect, missionBattleIds)      == 0x1C, "MenuMissionSel.missionBattleIds");
static_assert(offsetof(ns2_ccMenuMissionSelect, missionBattleCount)    == 0x40, "MenuMissionSel.missionBattleCount");
static_assert(offsetof(ns2_ccMenuMissionSelect, field_0x48)            == 0x48, "MenuMissionSel.field_0x48");
static_assert(offsetof(ns2_ccMenuMissionSelect, uiSelectWindow)        == 0x50, "MenuMissionSel.uiSelectWindow");
static_assert(offsetof(ns2_ccMenuMissionSelect, uiMenuIndex)           == 0x58, "MenuMissionSel.uiMenuIndex");
static_assert(offsetof(ns2_ccMenuMissionSelect, uiChapterSelect)       == 0x60, "MenuMissionSel.uiChapterSelect");
static_assert(offsetof(ns2_ccMenuMissionSelect, uiMissionBattleSelect) == 0x68, "MenuMissionSel.uiMissionBattleSelect");
static_assert(offsetof(ns2_ccMenuMissionSelect, uiMissionBattleDetail) == 0x70, "MenuMissionSel.uiMissionBattleDetail");
static_assert(offsetof(ns2_ccMenuMissionSelect, opacity)               == 0x8C, "MenuMissionSel.opacity");
static_assert(offsetof(ns2_ccMenuMissionSelect, menuBackClump)         == 0x90, "MenuMissionSel.menuBackClump");
static_assert(offsetof(ns2_ccMenuMissionSelect, bgObjClump)            == 0x98, "MenuMissionSel.bgObjClump");
static_assert(offsetof(ns2_ccMenuMissionSelect, fileLoadList)          == 0xA0, "MenuMissionSel.fileLoadList");

/* ========================================================================= */
/* ccMissionParamManager                                                     */
/* Create RVA 0x361070 (factory, not a traditional ctor)                     */
/* This is a std::vector-like container of mission param hashes.             */
/* Size INFERRED >= 0x20 (vector header: data ptr + size + capacity)         */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccMissionParamManager {
    /* +0x00 */ void     *data_ptr;  /* pointer to array of param entries */
    /* +0x08 */ uint64_t  size;      /* number of entries */
    /* +0x10 */ uint64_t  capacity;  /* allocated capacity */
    /* +0x18 */ uint8_t   pad_0x18[8];
} ns2_ccMissionParamManager;

static_assert(offsetof(ns2_ccMissionParamManager, data_ptr) == 0x00, "MissionParamMgr.data_ptr");
static_assert(offsetof(ns2_ccMissionParamManager, size)     == 0x08, "MissionParamMgr.size");
static_assert(offsetof(ns2_ccMissionParamManager, capacity) == 0x10, "MissionParamMgr.capacity");

/* ========================================================================= */
/* ccSceneAdvBattlePrevItemMenu                                              */
/* ctor RVA 0x40EACC, vtable 0x14082C368                                     */
/* Inherits ccScene (base ctor called first)                                 */
/* Size INFERRED >= 0x1B0 (surface fields through +0x1A8, last +0x1A8+8)     */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccSceneAdvBattlePrevItemMenu {
    /* +0x00 */ void     *vtable;           /* 0x14082C368, overrides ccScene vtable */
    /* +0x08 */ uint8_t   ccScene_base[0x120]; /* ccScene base class (size inferred) */
    /* +0x128 */ uint8_t  fileLoadList[0x30];  /* ccFileLoadListForUi at param_1+0x25 */
    /* +0x158 */ uint64_t  field_0x158;        /* surface sz=8, zeroed */
    /* +0x160 */ uint32_t  field_0x160;        /* surface sz=4, zeroed */
    /* +0x164 */ uint8_t   pad_0x164[4];
    /* +0x168 */ uint64_t  field_0x168;        /* surface sz=8, zeroed */
    /* +0x170 */ uint64_t  field_0x170;        /* surface sz=8, zeroed */
    /* +0x178 */ uint8_t   vector3_field[12];  /* Vector3 ctor, 3 floats = 12 bytes */
    /* +0x184 */ uint32_t  field_0x184;        /* surface sz=4, zeroed */
    /* +0x188 */ uint64_t  field_0x188;        /* surface sz=8, zeroed */
    /* +0x190 */ uint64_t  field_0x190;        /* surface sz=8, zeroed */
    /* +0x198 */ uint64_t  field_0x198;        /* surface sz=8, zeroed */
    /* +0x1A0 */ uint64_t  field_0x1A0;        /* surface sz=8, zeroed */
    /* +0x1A8 */ uint64_t  field_0x1A8;        /* surface sz=8, zeroed */
} ns2_ccSceneAdvBattlePrevItemMenu;

static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, vtable)         == 0x00,  "SceneAdvBattlePrevItemMenu.vtable");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, fileLoadList)    == 0x128, "SceneAdvBattlePrevItemMenu.fileLoadList");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x158)    == 0x158, "SceneAdvBattlePrevItemMenu.field_0x158");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x160)    == 0x160, "SceneAdvBattlePrevItemMenu.field_0x160");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x168)    == 0x168, "SceneAdvBattlePrevItemMenu.field_0x168");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x170)    == 0x170, "SceneAdvBattlePrevItemMenu.field_0x170");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, vector3_field)  == 0x178, "SceneAdvBattlePrevItemMenu.vector3_field");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x184)    == 0x184, "SceneAdvBattlePrevItemMenu.field_0x184");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x188)    == 0x188, "SceneAdvBattlePrevItemMenu.field_0x188");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x190)    == 0x190, "SceneAdvBattlePrevItemMenu.field_0x190");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x198)    == 0x198, "SceneAdvBattlePrevItemMenu.field_0x198");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x1A0)    == 0x1A0, "SceneAdvBattlePrevItemMenu.field_0x1A0");
static_assert(offsetof(ns2_ccSceneAdvBattlePrevItemMenu, field_0x1A8)    == 0x1A8, "SceneAdvBattlePrevItemMenu.field_0x1A8");

/* ========================================================================= */
/* ccSceneAdvCharacterSelect                                                 */
/* Initialize RVA 0x40FA9C                                                   */
/* Inherits ccScene. Size INFERRED >= 0x130                                  */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccSceneAdvCharacterSelect {
    /* +0x00 */ void    *vtable;
    /* +0x08 */ uint8_t  ccScene_base[0x120]; /* ccScene base */
    /* +0x128 */ void   *menuAdvCharSelect;   /* ccMenuAdvCharacterSelect* */
} ns2_ccSceneAdvCharacterSelect;

static_assert(offsetof(ns2_ccSceneAdvCharacterSelect, vtable)            == 0x00,  "SceneAdvCharSel.vtable");
static_assert(offsetof(ns2_ccSceneAdvCharacterSelect, menuAdvCharSelect) == 0x128, "SceneAdvCharSel.menuAdvCharSelect");

/* ========================================================================= */
/* ccSceneAdventure                                                          */
/* Initialize RVA 0x410478                                                   */
/* Inherits ccScene. Size INFERRED >= 0x1A8                                  */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccSceneAdventure {
    /* +0x00 */ void    *vtable;
    /* +0x08 */ uint8_t  ccScene_base[0x120];      /* ccScene base */
    /* +0x128 */ void   *stateMachine;             /* ccSceneAdvStateMachine* */
    /* +0x130 */ uint8_t advLoadScriptFileName[0x38]; /* std::string via GameProperty */
    /* +0x168 */ uint8_t advExecScriptFileName[0x38]; /* std::string via GameProperty */
    /* +0x1A0 */ uint32_t advZoom;                 /* unsigned int via GameProperty */
    /* +0x1A4 */ uint32_t advIsBattlePrevItemMenu; /* unsigned int via GameProperty */
} ns2_ccSceneAdventure;

static_assert(offsetof(ns2_ccSceneAdventure, vtable)                == 0x00,  "SceneAdventure.vtable");
static_assert(offsetof(ns2_ccSceneAdventure, stateMachine)          == 0x128, "SceneAdventure.stateMachine");
static_assert(offsetof(ns2_ccSceneAdventure, advLoadScriptFileName) == 0x130, "SceneAdventure.advLoadScriptFileName");
static_assert(offsetof(ns2_ccSceneAdventure, advExecScriptFileName) == 0x168, "SceneAdventure.advExecScriptFileName");
static_assert(offsetof(ns2_ccSceneAdventure, advZoom)               == 0x1A0, "SceneAdventure.advZoom");
static_assert(offsetof(ns2_ccSceneAdventure, advIsBattlePrevItemMenu) == 0x1A4, "SceneAdventure.advIsBattlePrevItemMenu");

/* ========================================================================= */
/* ccSceneAdvItemMenu                                                        */
/* Initialize RVA 0x411A30                                                   */
/* Inherits ccScene. Size INFERRED >= 0x160                                  */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccSceneAdvItemMenu {
    /* +0x00 */ void     *vtable;
    /* +0x08 */ uint8_t   ccScene_base[0x120]; /* ccScene base */
    /* +0x128 */ void    *uiAdvItemMainMenu;   /* ccUiAdvItemMainMenu* */
    /* +0x130 */ uint8_t  pad_0x130[8];
    /* +0x138 */ void    *menuIndexXfbin;      /* xfbin handle for menu_index */
    /* +0x140 */ uint8_t  pad_0x140[0x10];
    /* +0x150 */ uint32_t field_0x150;         /* zeroed */
    /* +0x154 */ uint32_t field_0x154;         /* zeroed */
    /* +0x158 */ uint8_t  pad_0x158[4];
    /* +0x15C */ uint32_t field_0x15C;         /* zeroed */
} ns2_ccSceneAdvItemMenu;

static_assert(offsetof(ns2_ccSceneAdvItemMenu, vtable)            == 0x00,  "SceneAdvItemMenu.vtable");
static_assert(offsetof(ns2_ccSceneAdvItemMenu, uiAdvItemMainMenu) == 0x128, "SceneAdvItemMenu.uiAdvItemMainMenu");
static_assert(offsetof(ns2_ccSceneAdvItemMenu, menuIndexXfbin)    == 0x138, "SceneAdvItemMenu.menuIndexXfbin");
static_assert(offsetof(ns2_ccSceneAdvItemMenu, field_0x150)       == 0x150, "SceneAdvItemMenu.field_0x150");
static_assert(offsetof(ns2_ccSceneAdvItemMenu, field_0x154)       == 0x154, "SceneAdvItemMenu.field_0x154");
static_assert(offsetof(ns2_ccSceneAdvItemMenu, field_0x15C)       == 0x15C, "SceneAdvItemMenu.field_0x15C");

/* ========================================================================= */
/* ccSceneAdvItemMenuCustomize                                               */
/* Initialize RVA 0x4121F8                                                   */
/* Inherits ccScene. Size INFERRED >= 0x130                                  */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccSceneAdvItemMenuCustomize {
    /* +0x00 */ void    *vtable;
    /* +0x08 */ uint8_t  ccScene_base[0x120]; /* ccScene base */
    /* +0x128 */ void   *uiAdvItemCustomize;  /* ccUiAdvItemCustomize* */
} ns2_ccSceneAdvItemMenuCustomize;

static_assert(offsetof(ns2_ccSceneAdvItemMenuCustomize, vtable)            == 0x00,  "SceneAdvItemMenuCustomize.vtable");
static_assert(offsetof(ns2_ccSceneAdvItemMenuCustomize, uiAdvItemCustomize) == 0x128, "SceneAdvItemMenuCustomize.uiAdvItemCustomize");

/* ========================================================================= */
/* ccSceneAdvItemUse                                                         */
/* Initialize RVA 0x41239C                                                   */
/* Inherits ccScene. Size INFERRED >= 0x130                                  */
/* ========================================================================= */
typedef struct __attribute__((packed)) ns2_ccSceneAdvItemUse {
    /* +0x00 */ void    *vtable;
    /* +0x08 */ uint8_t  ccScene_base[0x120]; /* ccScene base */
    /* +0x128 */ void   *uiAdvItemUse;        /* ccUiAdvItemUse* */
} ns2_ccSceneAdvItemUse;

static_assert(offsetof(ns2_ccSceneAdvItemUse, vtable)       == 0x00,  "SceneAdvItemUse.vtable");
static_assert(offsetof(ns2_ccSceneAdvItemUse, uiAdvItemUse) == 0x128, "SceneAdvItemUse.uiAdvItemUse");

#endif /* ST2A13_H */