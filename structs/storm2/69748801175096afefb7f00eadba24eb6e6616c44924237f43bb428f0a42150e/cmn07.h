/* cmn07.h -- Storm 2 (s2) struct group: ccScene hierarchy + ccScriptManager
 * INFERRED from static analysis of NSUNS2.exe (sha abf2b6, PC x64).
 * All offsets re-derived from s2 x64 decompile. Names from s2/Trilogy ns2:: only.
 * Sizes proven from operator_new / ctor where noted; otherwise ">= 0xN".
 * FLAT structs: child classes repeat base fields at their true offsets rather
 * than using C embedding, so sizeof is deterministic and gcc-packed layout matches.
 */
#ifndef CMN07_S2_H
#define CMN07_S2_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccSceneChangeParamBase
 * Size >= 0x14. Evidence: ctor RVA 0x656590.
 * Vtable: PTR_LAB_14089f568
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneChangeParamBase {
    void     *vtable;      /* +0x0000: PTR_LAB_14089f568 */
    uint32_t  scene_id;    /* +0x0008: init 0xFFFFFFFF */
    uint64_t  param_ptr;   /* +0x000C: init 0 */
} ccSceneChangeParamBase;
static_assert(offsetof(ccSceneChangeParamBase, vtable)    == 0x0000, "ccSceneChangeParamBase.vtable");
static_assert(offsetof(ccSceneChangeParamBase, scene_id)  == 0x0008, "ccSceneChangeParamBase.scene_id");
static_assert(offsetof(ccSceneChangeParamBase, param_ptr) == 0x000C, "ccSceneChangeParamBase.param_ptr");

/* ========================================================================
 * ccSceneAssignment
 * Size >= 0x30. Evidence: ctor RVA 0x651080 writes through param_1[5] (+0x28).
 * Vtable: PTR_FUN_14089f1f8. Embeds BlockAllocator at +0x00 (before vtable set).
 * ctor: BlockAllocator(); *param_1=vtable; *(byte*)(p+2)=1; p[3]=0; *(u32*)(p+4)=0; p[5]=0
 * param_1 is undefined8*, so p+2 = +0x10, p[3]=+0x18, *(u32*)(p+4)=+0x20, p[5]=+0x28
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneAssignment {
    void     *vtable;      /* +0x0000: PTR_FUN_14089f1f8 */
    uint8_t   _pad_0008[8];/* +0x0008: gap */
    uint8_t   flag_0x10;   /* +0x0010: init 1 (byte, *(undefined1*)(param_1+2)) */
    uint8_t   _pad_0011[7];/* +0x0011: gap */
    uint64_t  field_0x18;  /* +0x0018: init 0 (param_1[3]) */
    uint32_t  field_0x20;  /* +0x0020: init 0 (*(undefined4*)(param_1+4)) */
    uint8_t   _pad_0024[4];/* +0x0024: gap */
    uint64_t  field_0x28;  /* +0x0028: init 0 (param_1[5]) */
} ccSceneAssignment;
static_assert(offsetof(ccSceneAssignment, vtable)    == 0x0000, "ccSceneAssignment.vtable");
static_assert(offsetof(ccSceneAssignment, flag_0x10) == 0x0010, "ccSceneAssignment.flag_0x10");
static_assert(offsetof(ccSceneAssignment, field_0x18)== 0x0018, "ccSceneAssignment.field_0x18");
static_assert(offsetof(ccSceneAssignment, field_0x20)== 0x0020, "ccSceneAssignment.field_0x20");
static_assert(offsetof(ccSceneAssignment, field_0x28)== 0x0028, "ccSceneAssignment.field_0x28");

/* ========================================================================
 * ccScene
 * Size unknown >= 0x124. ctor RVA 0x66B200: memset(+0xC,0,0x80), highest write +0x120.
 * Vtable: PTR_FUN_1408a0478. Embeds ccGamePropertyPermit at +0x50,
 * BlockAllocator at +0xE8.
 * ctor: ccTaskBase(); *p=vtable; p[9]=1; p[8]=&FUN; ccGamePropertyPermit(p+10=+0x50);
 *       memset(p+0xc,0,0x80); *(u32*)(p+0x1c)=0xFFFFFFFF → +0xE0; *(u8*)(p+0xe4)=0;
 *       BlockAllocator(p+0x1d=+0xE8); *(u32*)(p+0x24)=0 → +0x120
 * ======================================================================== */
typedef struct __attribute__((packed)) ccScene {
    void     *vtable;           /* +0x0000: PTR_FUN_1408a0478 */
    uint8_t   _pad_0008[0x48];  /* +0x0008: ccTaskBase base region */
    uint8_t   game_prop_permit[0x10]; /* +0x0050: ccGamePropertyPermit (ctor p+10) */
    uint8_t   _pad_0060[0x80];  /* +0x0060: memset region (+0xC..+0x8C in ctor = +0x60..+0xDC flat) */
    uint32_t  field_E0;         /* +0x00E0: init 0xFFFFFFFF (ctor *(u32*)(p+0x1c)) */
    uint8_t   field_E4;         /* +0x00E4: init 0 (byte) */
    uint8_t   _pad_00E5[3];     /* +0x00E5: gap */
    uint8_t   block_allocator[0x38]; /* +0x00E8: Nucc::Memory::BlockAllocator (ctor p+0x1d) */
    uint32_t  field_120;        /* +0x0120: init 0 (ctor *(u32*)(p+0x24)) */
} ccScene;
static_assert(offsetof(ccScene, vtable)            == 0x0000, "ccScene.vtable");
static_assert(offsetof(ccScene, game_prop_permit)  == 0x0050, "ccScene.game_prop_permit");
static_assert(offsetof(ccScene, field_E0)          == 0x00E0, "ccScene.field_E0");
static_assert(offsetof(ccScene, field_E4)          == 0x00E4, "ccScene.field_E4");
static_assert(offsetof(ccScene, block_allocator)   == 0x00E8, "ccScene.block_allocator");
static_assert(offsetof(ccScene, field_120)         == 0x0120, "ccScene.field_120");

/* ========================================================================
 * ccSceneGameRoot
 * Inherits ccScene. Extension starts at +0x128. Size >= 0x470.
 * Vtable: PTR_FUN_14083ba18. ctor RVA 0x456F10.
 * ctor: ccScene(); *p=vtable; ccBaseCoord(p+0x25=+0x128); ccFileLoadListForUi(p+0x2d=+0x168);
 *       *(u32*)(p+0x33)=0 → +0x198; p[0x34]=0 → +0x1A0; BlockAllocator(p+0x35=+0x1A8);
 *       ccBattleSelResult(p+0x3c=+0x1E0); p[0x8d]=0 → +0x468
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneGameRoot {
    void     *vtable;           /* +0x0000: PTR_FUN_14083ba18 */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
    uint8_t   base_coord[0x40]; /* +0x0128: ccBaseCoord (ctor p+0x25) */
    uint8_t   file_load_list[0x30]; /* +0x0168: ccFileLoadListForUi (ctor p+0x2d) */
    uint32_t  field_198;        /* +0x0198: init 0 (ctor *(u32*)(p+0x33)) */
    uint8_t   _pad_019C[4];     /* +0x019C: gap */
    uint64_t  field_1A0;        /* +0x01A0: init 0 (ctor p[0x34]) */
    uint8_t   block_allocator[0x38]; /* +0x01A8: BlockAllocator (ctor p+0x35) */
    uint8_t   battle_sel_result[0x288]; /* +0x01E0: ccBattleSelResult (ctor p+0x3c, to +0x468) */
    uint64_t  field_468;        /* +0x0468: init 0 (ctor p[0x8d]) */
} ccSceneGameRoot;
static_assert(offsetof(ccSceneGameRoot, vtable)            == 0x0000, "ccSceneGameRoot.vtable");
static_assert(offsetof(ccSceneGameRoot, base_coord)        == 0x0128, "ccSceneGameRoot.base_coord");
static_assert(offsetof(ccSceneGameRoot, file_load_list)    == 0x0168, "ccSceneGameRoot.file_load_list");
static_assert(offsetof(ccSceneGameRoot, field_198)         == 0x0198, "ccSceneGameRoot.field_198");
static_assert(offsetof(ccSceneGameRoot, field_1A0)         == 0x01A0, "ccSceneGameRoot.field_1A0");
static_assert(offsetof(ccSceneGameRoot, block_allocator)   == 0x01A8, "ccSceneGameRoot.block_allocator");
static_assert(offsetof(ccSceneGameRoot, battle_sel_result) == 0x01E0, "ccSceneGameRoot.battle_sel_result");
static_assert(offsetof(ccSceneGameRoot, field_468)         == 0x0468, "ccSceneGameRoot.field_468");

/* ========================================================================
 * ccSceneRoot
 * Inherits ccScene. Extension at +0x128. Size >= 0x13C.
 * Initialize RVA 0x52EFC0 writes +0x128, +0x12C(=300), +0x130, +0x134, +0x138.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneRoot {
    void     *vtable;           /* +0x0000: not directly observed */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
    uint32_t  field_128;        /* +0x0128: init 0 */
    uint32_t  field_12C;        /* +0x012C: init 0 (param_1+300) */
    uint32_t  field_130;        /* +0x0130: init 0 */
    uint32_t  field_134;        /* +0x0134: init 0 */
    uint32_t  field_138;        /* +0x0138: init 0 */
} ccSceneRoot;
static_assert(offsetof(ccSceneRoot, vtable)    == 0x0000, "ccSceneRoot.vtable");
static_assert(offsetof(ccSceneRoot, field_128) == 0x0128, "ccSceneRoot.field_128");
static_assert(offsetof(ccSceneRoot, field_12C) == 0x012C, "ccSceneRoot.field_12C");
static_assert(offsetof(ccSceneRoot, field_130) == 0x0130, "ccSceneRoot.field_130");
static_assert(offsetof(ccSceneRoot, field_134) == 0x0134, "ccSceneRoot.field_134");
static_assert(offsetof(ccSceneRoot, field_138) == 0x0138, "ccSceneRoot.field_138");

/* ========================================================================
 * ccSceneStaffRollHD
 * Inherits ccScene. Extension at +0x128. Size >= 0x130.
 * Vtable: PTR_FUN_1408425d0 (dtor RVA 0x472630 sets before ~ccScene).
 * state_surface returned 0 fields (byte-cast only); no extension fields proven.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneStaffRollHD {
    void     *vtable;           /* +0x0000: PTR_FUN_1408425d0 */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
} ccSceneStaffRollHD;
static_assert(offsetof(ccSceneStaffRollHD, vtable) == 0x0000, "ccSceneStaffRollHD.vtable");

/* ========================================================================
 * ccSceneSystemDialogInvited
 * Inherits ccScene. Extension fields at +0x128, +0x138, +0x248, +0x250.
 * Size >= 0x258. state_surface from ShowInvitedDialog.
 * Initialize writes +0x128=0, +0x12C(=300)=0, +0x130 from global.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneSystemDialogInvited {
    void     *vtable;           /* +0x0000: inherits ccScene vtable */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
    uint32_t  field_128;        /* +0x0128: init 0 in Initialize */
    uint8_t   _pad_012C[0xC];   /* +0x012C: gap */
    uint64_t  field_138;        /* +0x0138: rw in ShowInvitedDialog */
    uint8_t   _pad_0140[0x108]; /* +0x0140: gap */
    uint64_t  field_248;        /* +0x0248: w in ShowInvitedDialog */
    uint64_t  field_250;        /* +0x0250: rw in ShowInvitedDialog */
} ccSceneSystemDialogInvited;
static_assert(offsetof(ccSceneSystemDialogInvited, vtable)    == 0x0000, "ccSceneSystemDialogInvited.vtable");
static_assert(offsetof(ccSceneSystemDialogInvited, field_128) == 0x0128, "ccSceneSystemDialogInvited.field_128");
static_assert(offsetof(ccSceneSystemDialogInvited, field_138) == 0x0138, "ccSceneSystemDialogInvited.field_138");
static_assert(offsetof(ccSceneSystemDialogInvited, field_248) == 0x0248, "ccSceneSystemDialogInvited.field_248");
static_assert(offsetof(ccSceneSystemDialogInvited, field_250) == 0x0250, "ccSceneSystemDialogInvited.field_250");

/* ========================================================================
 * ccSceneTitle
 * Inherits ccScene. Extension at +0x12C..+0x608. Size >= 0x60C.
 * Initialize RVA 0x476800: *(u32*)(p+300)=2 → +0x12C; *(u32*)(p+0x3dc)=1;
 *   ccModeSelectDrawEnvSetupper::Create(p+0x188); CreateAnmCamera(p);
 *   ccModeSelectCameraAssigner::Create(p+0x328); ccTitleBGController::Create(p+0x138);
 *   ccModeSelectAnmController::Create(p+0x198); *(u32*)(p+0x608)=flag
 * CtrlUI RVA 0x45A938: p+0x170=keyhelp; p+0x178=scrollfont; p+0x180,0x188=ui;
 *   p+0x140=xfbin array; p+0x1d8=loop target
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneTitle {
    void     *vtable;           /* +0x0000: inherits ccScene vtable */
    uint8_t   _pad_0008[0x124]; /* +0x0008: ccScene base */
    uint32_t  field_12C;        /* +0x012C: init 2 (Initialize *(u32*)(p+300)) */
    uint8_t   _pad_0130[0x8];   /* +0x0130: gap */
    uint8_t   title_bg_ctrl[0x50]; /* +0x0138: ccTitleBGController (Create at +0x138) */
    uint8_t   _pad_0188[0x0];   /* placeholder alignment */
    uint8_t   mode_select_draw[0x10]; /* +0x0188: ccModeSelectDrawEnvSetupper (partial) */
    uint8_t   mode_select_anm[0x90];  /* +0x0198: ccModeSelectAnmController (Create at +0x198) */
    uint8_t   _pad_0228[0x100]; /* +0x0228: gap */
    uint8_t   mode_select_cam[0x40];  /* +0x0328: ccModeSelectCameraAssigner (Create at +0x328) */
    uint8_t   _pad_0368[0x74];  /* +0x0368: gap */
    uint32_t  field_3DC;        /* +0x03DC: init 1 */
    uint8_t   _pad_03E0[0x228]; /* +0x03E0: gap */
    uint32_t  field_608;        /* +0x0608: steam/input flag */
} ccSceneTitle;
static_assert(offsetof(ccSceneTitle, vtable)          == 0x0000, "ccSceneTitle.vtable");
static_assert(offsetof(ccSceneTitle, field_12C)       == 0x012C, "ccSceneTitle.field_12C");
static_assert(offsetof(ccSceneTitle, title_bg_ctrl)   == 0x0138, "ccSceneTitle.title_bg_ctrl");
static_assert(offsetof(ccSceneTitle, mode_select_draw)== 0x0188, "ccSceneTitle.mode_select_draw");
static_assert(offsetof(ccSceneTitle, mode_select_anm) == 0x0198, "ccSceneTitle.mode_select_anm");
static_assert(offsetof(ccSceneTitle, mode_select_cam) == 0x0328, "ccSceneTitle.mode_select_cam");
static_assert(offsetof(ccSceneTitle, field_3DC)       == 0x03DC, "ccSceneTitle.field_3DC");
static_assert(offsetof(ccSceneTitle, field_608)       == 0x0608, "ccSceneTitle.field_608");

/* ========================================================================
 * ccScreenInputSet
 * Size >= 0x58. CreateProperty RVA 0x5DDD70.
 * operator_new(0xB8) for physics allocator, operator_new(0x50) for collision,
 * operator_new(0x2918) for dynamics world.
 * param_1[0xc] checked == 1 → +0x60? No: param_1 is longlong*, so param_1[0xc]=+0x60.
 * But s1 had mode_flag at +0x28. Re-check: "(int)param_1[0xc] != 1" — that's +0x60.
 * Actually wait: in s1 the field was at +0x28 with "param_1[0xc] >> checked == 1".
 * In s2 CreateProperty: param_1 is longlong*, param_1[0xc] = +0x60.
 * But param_1[5]=+0x28 (physics_alloc), param_1[6]=+0x30 (dynamics_world).
 * Let me re-examine: the s2 decomp says "(int)param_1[0xc] != 1" which is offset +0x60.
 * And param_1[5] = +0x28, param_1[6] = +0x30.
 * Also: local_38 = (u32)param_1[9] → +0x48; local_34 = *(u32*)(p+0x4c) → +0x4C.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccScreenInputSet {
    void     *vtable;           /* +0x0000: */
    uint8_t   _pad_0008[0x20];  /* +0x0008: gap */
    uint64_t  physics_alloc;    /* +0x0028: operator_new(0xB8) result (param_1[5]) */
    uint64_t  dynamics_world;   /* +0x0030: plCreateDynamicsWorld result (param_1[6]) */
    uint8_t   _pad_0038[0x10];  /* +0x0038: gap */
    uint32_t  field_48;         /* +0x0048: param_1[9] read */
    uint32_t  field_4C;         /* +0x004C: *(u32*)(p+0x4c) read */
    uint8_t   _pad_0050[0x10];  /* +0x0050: gap */
    uint32_t  mode_flag;        /* +0x0060: param_1[0xc] checked == 1 */
} ccScreenInputSet;
static_assert(offsetof(ccScreenInputSet, vtable)        == 0x0000, "ccScreenInputSet.vtable");
static_assert(offsetof(ccScreenInputSet, physics_alloc) == 0x0028, "ccScreenInputSet.physics_alloc");
static_assert(offsetof(ccScreenInputSet, dynamics_world)== 0x0030, "ccScreenInputSet.dynamics_world");
static_assert(offsetof(ccScreenInputSet, field_48)      == 0x0048, "ccScreenInputSet.field_48");
static_assert(offsetof(ccScreenInputSet, field_4C)      == 0x004C, "ccScreenInputSet.field_4C");
static_assert(offsetof(ccScreenInputSet, mode_flag)     == 0x0060, "ccScreenInputSet.mode_flag");

/* ========================================================================
 * ccScriptManager
 * Size >= 0x1048. Create RVA 0x653A10: MallocCore(param_1+9, 0x1000) → +0x48.
 * lua_State* at param_1[3] → +0x18. Vtable call at param_1[0]+8 → +0x00.
 * param_1 is longlong*, so param_1[3]=+0x18, param_1+9=+0x48.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccScriptManager {
    void     *vtable;           /* +0x0000: vtable call at *param_1+8 */
    uint8_t   _pad_0008[0x10];  /* +0x0008: gap */
    void     *lua_state;        /* +0x0018: lua_newstate result (param_1[3]) */
    uint8_t   _pad_0020[0x28];  /* +0x0020: gap */
    uint8_t   script_buffer[0x1000]; /* +0x0048: MallocCore(param_1+9, 0x1000) */
} ccScriptManager;
static_assert(offsetof(ccScriptManager, vtable)        == 0x0000, "ccScriptManager.vtable");
static_assert(offsetof(ccScriptManager, lua_state)     == 0x0018, "ccScriptManager.lua_state");
static_assert(offsetof(ccScriptManager, script_buffer) == 0x0048, "ccScriptManager.script_buffer");

#endif /* CMN07_S2_H */