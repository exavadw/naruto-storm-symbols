/* cmn07.h -- Storm 3 Full Burst HD (s3) struct group: ccScene hierarchy + ccScriptManager
 * INFERRED from static analysis of NSUNS3.exe (sha 55b726e94dad, PC x64).
 * All offsets re-derived from s3 x64 decompile. Names from s3/Trilogy ns3:: only.
 * Sizes proven from operator_new / ctor where noted; otherwise ">= 0xN".
 * FLAT structs: child classes repeat base fields at their true offsets rather
 * than using C embedding, so sizeof is deterministic and gcc-packed layout matches.
 */
#ifndef CMN07_S3_H
#define CMN07_S3_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccSceneChangeParamBase
 * Size >= 0x14. Evidence: ctor RVA 0x74C6B0 sets vtable + scene_id + param_ptr.
 * Vtable: not directly observed in s3 decompile (inherited pattern from s2).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneChangeParamBase {
    void     *vtable;      /* +0x0000 */
    uint32_t  scene_id;    /* +0x0008: init 0xFFFFFFFF */
    uint64_t  param_ptr;   /* +0x000C: init 0 */
} ns3_ccSceneChangeParamBase;
static_assert(offsetof(ns3_ccSceneChangeParamBase, vtable)    == 0x0000, "ns3_ccSceneChangeParamBase.vtable");
static_assert(offsetof(ns3_ccSceneChangeParamBase, scene_id)  == 0x0008, "ns3_ccSceneChangeParamBase.scene_id");
static_assert(offsetof(ns3_ccSceneChangeParamBase, param_ptr) == 0x000C, "ns3_ccSceneChangeParamBase.param_ptr");

/* ========================================================================
 * ccSceneAssignment
 * Size >= 0x88. Evidence: state_surface field at +0x80 (vtable read),
 * ctor RVA 0x74C760 writes through param_1[5] (+0x28).
 * Vtable: observed via state_surface at +0x80 read.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneAssignment {
    void     *vtable;      /* +0x0000 */
    uint8_t   _pad_0008[8];/* +0x0008: gap */
    uint8_t   flag_0x10;   /* +0x0010: init 1 (byte) */
    uint8_t   _pad_0011[7];/* +0x0011: gap */
    uint64_t  field_0x18;  /* +0x0018: init 0 */
    uint32_t  field_0x20;  /* +0x0020: init 0 */
    uint8_t   _pad_0024[4];/* +0x0024: gap */
    uint64_t  field_0x28;  /* +0x0028: init 0 */
    uint8_t   _pad_0030[0x50]; /* +0x0030: gap to +0x80 */
    void     *vtable_read; /* +0x0080: vtable ptr read in state_surface */
} ns3_ccSceneAssignment;
static_assert(offsetof(ns3_ccSceneAssignment, vtable)      == 0x0000, "ns3_ccSceneAssignment.vtable");
static_assert(offsetof(ns3_ccSceneAssignment, flag_0x10)   == 0x0010, "ns3_ccSceneAssignment.flag_0x10");
static_assert(offsetof(ns3_ccSceneAssignment, field_0x18)  == 0x0018, "ns3_ccSceneAssignment.field_0x18");
static_assert(offsetof(ns3_ccSceneAssignment, field_0x20)  == 0x0020, "ns3_ccSceneAssignment.field_0x20");
static_assert(offsetof(ns3_ccSceneAssignment, field_0x28)  == 0x0028, "ns3_ccSceneAssignment.field_0x28");
static_assert(offsetof(ns3_ccSceneAssignment, vtable_read) == 0x0080, "ns3_ccSceneAssignment.vtable_read");

/* ========================================================================
 * ccScene
 * Size unknown >= 0x124. ctor RVA 0x75E6A0.
 * state_surface: memset region +0x60, fields at +0xE0,+0xE4,+0xE8,+0xF8,+0x100,+0x108,+0x120.
 * Vtable: set in ctor (pattern from s2).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccScene {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x58];  /* +0x0008: ccTaskBase base region */
    uint8_t   _pad_0060[0x80];  /* +0x0060: memset region in ctor */
    uint32_t  field_E0;         /* +0x00E0: u32 w in state_surface */
    uint8_t   field_E4;         /* +0x00E4: byte rw */
    uint8_t   _pad_00E5[3];     /* +0x00E5: gap */
    uint64_t  field_E8;         /* +0x00E8: rw in state_surface */
    uint8_t   _pad_00F0[8];     /* +0x00F0: gap */
    uint64_t  field_F8;         /* +0x00F8: u64 w */
    uint64_t  field_100;        /* +0x0100: u64 rw */
    uint64_t  field_108;        /* +0x0108: u64 rw */
    uint8_t   _pad_0110[0x10];  /* +0x0110: gap */
    uint32_t  field_120;        /* +0x0120: u32 w */
} ns3_ccScene;
static_assert(offsetof(ns3_ccScene, vtable)     == 0x0000, "ns3_ccScene.vtable");
static_assert(offsetof(ns3_ccScene, field_E0)   == 0x00E0, "ns3_ccScene.field_E0");
static_assert(offsetof(ns3_ccScene, field_E4)   == 0x00E4, "ns3_ccScene.field_E4");
static_assert(offsetof(ns3_ccScene, field_E8)   == 0x00E8, "ns3_ccScene.field_E8");
static_assert(offsetof(ns3_ccScene, field_F8)   == 0x00F8, "ns3_ccScene.field_F8");
static_assert(offsetof(ns3_ccScene, field_100)  == 0x0100, "ns3_ccScene.field_100");
static_assert(offsetof(ns3_ccScene, field_108)  == 0x0108, "ns3_ccScene.field_108");
static_assert(offsetof(ns3_ccScene, field_120)  == 0x0120, "ns3_ccScene.field_120");

/* ========================================================================
 * ccSceneGameRoot
 * Inherits ccScene. Only 1 method in s3 (Initialize RVA 0x629D0C).
 * Skipped for state_surface (< 3 methods). Size/layout carried from s2
 * with offsets re-verified where possible. Size >= 0x470 (s2 evidence).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneGameRoot {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
    uint8_t   base_coord[0x40]; /* +0x0128: ccBaseCoord */
    uint8_t   file_load_list[0x30]; /* +0x0168: ccFileLoadListForUi */
    uint32_t  field_198;        /* +0x0198 */
    uint8_t   _pad_019C[4];     /* +0x019C: gap */
    uint64_t  field_1A0;        /* +0x01A0 */
    uint8_t   block_allocator[0x38]; /* +0x01A8: BlockAllocator */
    uint8_t   battle_sel_result[0x288]; /* +0x01E0: ccBattleSelResult */
    uint64_t  field_468;        /* +0x0468 */
} ns3_ccSceneGameRoot;
static_assert(offsetof(ns3_ccSceneGameRoot, vtable)            == 0x0000, "ns3_ccSceneGameRoot.vtable");
static_assert(offsetof(ns3_ccSceneGameRoot, base_coord)        == 0x0128, "ns3_ccSceneGameRoot.base_coord");
static_assert(offsetof(ns3_ccSceneGameRoot, file_load_list)    == 0x0168, "ns3_ccSceneGameRoot.file_load_list");
static_assert(offsetof(ns3_ccSceneGameRoot, field_198)         == 0x0198, "ns3_ccSceneGameRoot.field_198");
static_assert(offsetof(ns3_ccSceneGameRoot, field_1A0)         == 0x01A0, "ns3_ccSceneGameRoot.field_1A0");
static_assert(offsetof(ns3_ccSceneGameRoot, block_allocator)   == 0x01A8, "ns3_ccSceneGameRoot.block_allocator");
static_assert(offsetof(ns3_ccSceneGameRoot, battle_sel_result) == 0x01E0, "ns3_ccSceneGameRoot.battle_sel_result");
static_assert(offsetof(ns3_ccSceneGameRoot, field_468)         == 0x0468, "ns3_ccSceneGameRoot.field_468");

/* ========================================================================
 * ccSceneRoot
 * Inherits ccScene. Initialize RVA 0x62A854 uses globals only (no this ptr).
 * state_surface returned 0 fields (byte-cast only). No extension fields
 * proven in s3. Size >= 0x124 (ccScene base only).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneRoot {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x11C]; /* +0x0008: ccScene base (to 0x124) */
} ns3_ccSceneRoot;
static_assert(offsetof(ns3_ccSceneRoot, vtable) == 0x0000, "ns3_ccSceneRoot.vtable");

/* ========================================================================
 * ccSceneStaffRollHD
 * Inherits ccScene. Extension at +0x128. Size >= 0x130.
 * Initialize RVA 0x459C10: allocates 0xa8 bytes, stores ptr at +0x128.
 * Vtable: not directly observed.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneStaffRollHD {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
    void     *staff_roll_state; /* +0x0128: allocated 0xa8 bytes (Initialize) */
} ns3_ccSceneStaffRollHD;
static_assert(offsetof(ns3_ccSceneStaffRollHD, vtable)           == 0x0000, "ns3_ccSceneStaffRollHD.vtable");
static_assert(offsetof(ns3_ccSceneStaffRollHD, staff_roll_state) == 0x0128, "ns3_ccSceneStaffRollHD.staff_roll_state");

/* ========================================================================
 * ccSceneSystemDialogInvited
 * Inherits ccScene. Extension fields at +0x128, +0x130, +0x238.
 * Size >= 0x240. state_surface + Initialize RVA 0x48B910.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneSystemDialogInvited {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x120]; /* +0x0008: ccScene base */
    uint32_t  field_128;        /* +0x0128: u32 rw high-conf */
    uint8_t   _pad_012C[4];     /* +0x012C: gap */
    uint64_t  field_130;        /* +0x0130: r in state_surface */
    uint8_t   _pad_0138[0x100]; /* +0x0138: gap */
    uint64_t  field_238;        /* +0x0238: u64 rw medium-conf */
} ns3_ccSceneSystemDialogInvited;
static_assert(offsetof(ns3_ccSceneSystemDialogInvited, vtable)    == 0x0000, "ns3_ccSceneSystemDialogInvited.vtable");
static_assert(offsetof(ns3_ccSceneSystemDialogInvited, field_128) == 0x0128, "ns3_ccSceneSystemDialogInvited.field_128");
static_assert(offsetof(ns3_ccSceneSystemDialogInvited, field_130) == 0x0130, "ns3_ccSceneSystemDialogInvited.field_130");
static_assert(offsetof(ns3_ccSceneSystemDialogInvited, field_238) == 0x0238, "ns3_ccSceneSystemDialogInvited.field_238");

/* ========================================================================
 * ccSceneTitle
 * Inherits ccScene. Execute RVA 0x45605C reads/writes +0x130 (state machine).
 * state_surface returned 0 fields (byte-cast only); field at +0x130 from Execute.
 * Size >= 0x134 (last proven field + size). Layout mostly from s2 carried forward.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSceneTitle {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x128]; /* +0x0008: ccScene base */
    uint32_t  state_machine;    /* +0x0130: Execute reads/writes (1→2→3→4) */
} ns3_ccSceneTitle;
static_assert(offsetof(ns3_ccSceneTitle, vtable)        == 0x0000, "ns3_ccSceneTitle.vtable");
static_assert(offsetof(ns3_ccSceneTitle, state_machine) == 0x0130, "ns3_ccSceneTitle.state_machine");

/* ========================================================================
 * ccScreenInputSet
 * Only 1 method in s3 (CreateProperty RVA 0x6EA250).
 * Skipped for state_surface (< 3 methods). Layout carried from s2.
 * Size >= 0x68 (s2 evidence).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccScreenInputSet {
    void     *vtable;           /* +0x0000 */
    uint8_t   _pad_0008[0x20];  /* +0x0008: gap */
    uint64_t  physics_alloc;    /* +0x0028: operator_new(0xB8) result */
    uint64_t  dynamics_world;   /* +0x0030: plCreateDynamicsWorld result */
    uint8_t   _pad_0038[0x10];  /* +0x0038: gap */
    uint32_t  field_48;         /* +0x0048 */
    uint32_t  field_4C;         /* +0x004C */
    uint8_t   _pad_0050[0x10];  /* +0x0050: gap */
    uint32_t  mode_flag;        /* +0x0060: checked == 1 */
} ns3_ccScreenInputSet;
static_assert(offsetof(ns3_ccScreenInputSet, vtable)        == 0x0000, "ns3_ccScreenInputSet.vtable");
static_assert(offsetof(ns3_ccScreenInputSet, physics_alloc) == 0x0028, "ns3_ccScreenInputSet.physics_alloc");
static_assert(offsetof(ns3_ccScreenInputSet, dynamics_world)== 0x0030, "ns3_ccScreenInputSet.dynamics_world");
static_assert(offsetof(ns3_ccScreenInputSet, field_48)      == 0x0048, "ns3_ccScreenInputSet.field_48");
static_assert(offsetof(ns3_ccScreenInputSet, field_4C)      == 0x004C, "ns3_ccScreenInputSet.field_4C");
static_assert(offsetof(ns3_ccScreenInputSet, mode_flag)     == 0x0060, "ns3_ccScreenInputSet.mode_flag");

/* ========================================================================
 * ccScriptManager
 * Size >= 0x1048. Create RVA 0x759DA0: MallocCore(param_1+9, 0x1000) → +0x48.
 * lua_State* at param_1[3] → +0x18. Vtable call at *param_1+8 → +0x00.
 * Initialize RVA 0x759900: allocator size 0xe0 for the object itself.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccScriptManager {
    void     *vtable;           /* +0x0000: vtable call at *param_1+8 */
    uint8_t   _pad_0008[0x10];  /* +0x0008: gap */
    void     *lua_state;        /* +0x0018: lua_newstate result (param_1[3]) */
    uint8_t   _pad_0020[0x28];  /* +0x0020: gap */
    uint8_t   script_buffer[0x1000]; /* +0x0048: MallocCore(param_1+9, 0x1000) */
} ns3_ccScriptManager;
static_assert(offsetof(ns3_ccScriptManager, vtable)        == 0x0000, "ns3_ccScriptManager.vtable");
static_assert(offsetof(ns3_ccScriptManager, lua_state)     == 0x0018, "ns3_ccScriptManager.lua_state");
static_assert(offsetof(ns3_ccScriptManager, script_buffer) == 0x0048, "ns3_ccScriptManager.script_buffer");

#endif /* CMN07_S3_H */