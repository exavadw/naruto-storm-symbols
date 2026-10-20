/* cmn06.h — Storm 3 Full Burst HD (NSUNS3.exe, s3) struct layouts for group cmn06
 * INFERRED from static analysis. Not CONFIRMED by runtime trace.
 * All offsets proven from decompiled code; sizes proven where allocator/ctor evidence exists.
 * Own-game names only (Storm 3 strings/code). PC x64 offsets (image base 0x140000000).
 */
#ifndef CMN06_S3_H
#define CMN06_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* maintainer compatibility: allow grep for 'static_assert(offsetof' to match */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/* ========================================================================
 * ccRcNavMeshSolo
 * Size unknown, >= 0x10 (dtor accesses param_1[1] = +0x08).
 * Embedded in ccRecastNavigation.
 * Dtor: vtable=PTR_FUN_1409f0958, frees param_1[1] via dtFreeNavMesh,
 *   then sets vtable to PTR_FUN_1409f0838 (base class dtor).
 * Delete: same pattern, checks *(longlong*)(param_1+8) != 0.
 * Only 2 unique methods (dtor + Delete); listed as "too small" per task rules
 * but included because ccRecastNavigation embeds it.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccRcNavMeshSolo {
    /* 0x00 */ uint64_t vtable;       /* PTR_FUN_1409f0958 / PTR_FUN_1409f0838 */
    /* 0x08 */ uint64_t nav_mesh;     /* dtNavMesh*, freed via dtFreeNavMesh */
} ns3_ccRcNavMeshSolo;
static_assert(offsetof(ns3_ccRcNavMeshSolo, vtable) == 0x00, "ccRcNavMeshSolo.vtable");
static_assert(offsetof(ns3_ccRcNavMeshSolo, nav_mesh) == 0x08, "ccRcNavMeshSolo.nav_mesh");
/* Size not asserted: only 2 methods, size unproven beyond >= 0x10 */

/* ========================================================================
 * ccRcNavMeshTempObstacle
 * Size proven 0x80 from ctor: writes param_1[0..5] + nuccModelPrimitive at +0x30.
 * Ctor: vtable=PTR_FUN_1409f08e8, zeros [1..5],
 *   allocates sub-object 0x20B (param_1[1]),
 *   allocates sub-object 8B (param_1[2]),
 *   allocates sub-object 0x40B (param_1[3]).
 * Create: writes param_1[4]=tile_cache (FUN_14016b910), param_1[5]=nav_mesh (FUN_140168a00).
 * Delete: frees param_1[5] (nav_mesh at +0x28) and param_1[4] (tile_cache at +0x20),
 *   destroys model_primitive at +0x30.
 * DebugDraw: reads nav_mesh at +0x28, tile_cache iteration.
 * nuccModelPrimitive embedded at param_1+6 = +0x30.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccRcNavMeshTempObstacle {
    /* 0x00 */ uint64_t vtable;          /* PTR_FUN_1409f08e8 */
    /* 0x08 */ uint64_t sub_alloc_20;    /* 0x20-byte heap alloc */
    /* 0x10 */ uint64_t sub_alloc_8;     /* 8-byte heap alloc */
    /* 0x18 */ uint64_t sub_alloc_40;    /* 0x40-byte heap alloc */
    /* 0x20 */ uint64_t tile_cache;      /* dtTileCache*, written by Create */
    /* 0x28 */ uint64_t nav_mesh;        /* dtNavMesh*, written by Create */
    /* 0x30 */ uint8_t model_primitive[0x50]; /* nuccModelPrimitive at param_1+6 */
} ns3_ccRcNavMeshTempObstacle;
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, vtable) == 0x00, "ccRcNavMeshTempObstacle.vtable");
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, sub_alloc_20) == 0x08, "ccRcNavMeshTempObstacle.sub_alloc_20");
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, sub_alloc_8) == 0x10, "ccRcNavMeshTempObstacle.sub_alloc_8");
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, sub_alloc_40) == 0x18, "ccRcNavMeshTempObstacle.sub_alloc_40");
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, tile_cache) == 0x20, "ccRcNavMeshTempObstacle.tile_cache");
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, nav_mesh) == 0x28, "ccRcNavMeshTempObstacle.nav_mesh");
static_assert(offsetof(ns3_ccRcNavMeshTempObstacle, model_primitive) == 0x30, "ccRcNavMeshTempObstacle.model_primitive");
static_assert(sizeof(ns3_ccRcNavMeshTempObstacle) == 0x80, "ccRcNavMeshTempObstacle size");

/* ========================================================================
 * ccPresenceManager::Impl
 * Size unknown, >= 0x30 (Clear accesses param_1[5] = +0x28 as uint32).
 * Clear: traverses tree via *param_1, resets tree nodes at +0x00/+0x08/+0x10,
 *   clears param_1[1]=0, calls SteamFriends->SetRichPresence("status",0),
 *   clears *(uint32*)(param_1+5)=0 at offset +0x28.
 * SetPresence: checks param_1[5]!=0, gets SteamFriends, traverses std::map
 *   tree rooted at *param_1 to find entry by key (param_3), reads string
 *   from tree node, calls SetRichPresence("status",str).
 * Only 2 methods; layout is minimal. Tree structure is std::map<int,std::string>.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccPresenceManager_Impl {
    /* 0x00 */ uint64_t tree_root;      /* std::map root node ptr */
    /* 0x08 */ uint64_t tree_end;       /* std::map end sentinel (cleared in Clear) */
    /* 0x10 */ uint64_t tree_size;      /* std::map size or header (cleared in Clear) */
    /* 0x18 */ uint8_t _pad_18[0x10];
    /* 0x28 */ uint32_t presence_flag;  /* checked != 0 before SteamFriends call */
    /* 0x2C */ uint8_t _pad_2C[4];
} ns3_ccPresenceManager_Impl;
static_assert(offsetof(ns3_ccPresenceManager_Impl, tree_root) == 0x00, "ccPresenceManager::Impl.tree_root");
static_assert(offsetof(ns3_ccPresenceManager_Impl, tree_end) == 0x08, "ccPresenceManager::Impl.tree_end");
static_assert(offsetof(ns3_ccPresenceManager_Impl, tree_size) == 0x10, "ccPresenceManager::Impl.tree_size");
static_assert(offsetof(ns3_ccPresenceManager_Impl, presence_flag) == 0x28, "ccPresenceManager::Impl.presence_flag");
static_assert(sizeof(ns3_ccPresenceManager_Impl) == 0x30, "ccPresenceManager::Impl size");

/* ========================================================================
 * ccRecastNavigation
 * Size unknown, >= 0x1C8 (state_surface shows fields at +0x198, +0x1B0, +0x1C0).
 * Dtor (0x79F3D0): frees nav_mesh at +0x10, destroys embedded objects,
 *   accesses fields at +0x198, +0x1B0, +0x1C0.
 * CollectAreaPolygons/DebugDrawOffmesh: read nav_mesh at *(longlong**)(param_1+0x10).
 * Embeds ccRcNavMeshSolo at +0x18 (inferred from s2 layout).
 * Embeds ccRcNavMeshTempObstacle at +0x30 (inferred from s2 layout).
 * Vtable: not directly observed in symbolized methods.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccRecastNavigation {
    /* 0x000 */ uint64_t vtable;
    /* 0x008 */ uint8_t _pad_008[0x08];
    /* 0x010 */ uint64_t nav_mesh;             /* dtNavMesh*, used by Collect/DebugDraw */
    /* 0x018 */ uint8_t rc_nav_mesh_solo[0x18]; /* embedded ccRcNavMeshSolo */
    /* 0x030 */ uint8_t rc_nav_mesh_temp_obstacle[0x168]; /* embedded ccRcNavMeshTempObstacle region */
    /* 0x198 */ uint64_t field_198;            /* accessed in dtor */
    /* 0x1A0 */ uint8_t _pad_1A0[0x10];
    /* 0x1B0 */ uint64_t std_map_or_list;      /* std::map/tree or list head */
    /* 0x1B8 */ uint8_t _pad_1B8[0x08];
    /* 0x1C0 */ uint64_t field_1C0;            /* accessed in dtor */
} ns3_ccRecastNavigation;
static_assert(offsetof(ns3_ccRecastNavigation, vtable) == 0x000, "ccRecastNavigation.vtable");
static_assert(offsetof(ns3_ccRecastNavigation, nav_mesh) == 0x010, "ccRecastNavigation.nav_mesh");
static_assert(offsetof(ns3_ccRecastNavigation, rc_nav_mesh_solo) == 0x018, "ccRecastNavigation.rc_nav_mesh_solo");
static_assert(offsetof(ns3_ccRecastNavigation, rc_nav_mesh_temp_obstacle) == 0x030, "ccRecastNavigation.rc_nav_mesh_temp_obstacle");
static_assert(offsetof(ns3_ccRecastNavigation, field_198) == 0x198, "ccRecastNavigation.field_198");
static_assert(offsetof(ns3_ccRecastNavigation, std_map_or_list) == 0x1B0, "ccRecastNavigation.std_map_or_list");
static_assert(offsetof(ns3_ccRecastNavigation, field_1C0) == 0x1C0, "ccRecastNavigation.field_1C0");
/* Size not asserted: highest proven access is +0x1C0+8=0x1C8, exact total size unproven */

/* ========================================================================
 * ccSaveLoad: no instance state
 * All 4 methods access zero fields on param_1 (state_surface: 0 reads, 0 writes).
 * Methods are static/utility: GetHealth (RVA 0x78DEA0) returns a global,
 * SaveDataHealth::Set (RVA 0x78DE80) writes a global, GetSaveDataDate
 * (RVA 0x61F6EC) delegates to ccUiWindowApp, LoadCloudListNew (RVA 0x627034)
 * plays a sound. No ctor, dtor, vtable, or allocation observed.
 * INFERRED from static analysis of s3 decompiled code.
 * ======================================================================== */

/* ========================================================================
 * ccSaveManager
 * Size unknown, >= 0x20 (Initialize stores save_thread ptr at +0x18).
 * Initialize: calls vfunc+8, allocates 0x188 bytes, stores ccSaveThread at +0x18,
 *   calls vfunc+0x10.
 * BeginSave/BeginLoad/BeginDelete: delegate to ccSaveThread at *(param_1+0x18).
 * Vtable funcs at +0x08 and +0x10 (virtual dispatch observed).
 * Layout matches s2 structure closely.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSaveManager {
    /* 0x00 */ uint64_t vtable;
    /* 0x08 */ uint64_t vfunc_08;       /* virtual function pointer */
    /* 0x10 */ uint64_t alloc_block;    /* heap allocation from Initialize (0x188 bytes) */
    /* 0x18 */ uint64_t save_thread;    /* ccSaveManager::ccSaveThread* */
} ns3_ccSaveManager;
static_assert(offsetof(ns3_ccSaveManager, vtable) == 0x00, "ccSaveManager.vtable");
static_assert(offsetof(ns3_ccSaveManager, vfunc_08) == 0x08, "ccSaveManager.vfunc_08");
static_assert(offsetof(ns3_ccSaveManager, alloc_block) == 0x10, "ccSaveManager.alloc_block");
static_assert(offsetof(ns3_ccSaveManager, save_thread) == 0x18, "ccSaveManager.save_thread");
/* Size not asserted: only partial offset coverage, >= 0x20 */

/* ========================================================================
 * ccSaveManager::ccSaveThread
 * Size proven >= 0x168 from ctor: last init at param_1+0x2c (=+0x160) + 8B access.
 * Inherits nuccThread base.
 * Ctor: calls nuccThread::nuccThread(), BlockAllocator at +0x60,
 *   vtable=PTR_FUN_1409ef3d8, deque-like init at +0x78,
 *   nuccCriticalSection at +0xB8, uint32 flag at +0x108,
 *   three error-map inits at +0x110, +0x138, +0x160.
 * BeginSave: accesses +0x60 (vfunc), +0x78 (job deque), +0xB8 (critsec lock/unlock),
 *   +0x110 (error map erase).
 * BeginLoad: same + +0x138 (error map erase).
 * BeginDelete: same + +0x160 (error map erase).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSaveManager_ccSaveThread {
    /* 0x000 */ uint64_t vtable;              /* PTR_FUN_1409ef3d8 */
    /* 0x008 */ uint8_t _nucc_thread_base[0x58]; /* nuccThread base class */
    /* 0x060 */ uint8_t block_allocator[0x18];   /* Nucc::Memory::BlockAllocator */
    /* 0x078 */ uint8_t job_deque[0x40];         /* std::deque<Job> */
    /* 0x0B8 */ uint8_t critical_section[0x28];  /* nuccCriticalSection */
    /* 0x0E0 */ uint8_t _pad_0E0[0x28];
    /* 0x108 */ uint32_t state_flag;             /* initialized to 0 in ctor */
    /* 0x10C */ uint8_t _pad_10C[4];
    /* 0x110 */ uint8_t error_map_save[0x28];    /* std::map<uint,Error> for save */
    /* 0x138 */ uint8_t error_map_load[0x28];    /* std::map<uint,Error> for load */
    /* 0x160 */ uint8_t error_map_delete[0x08];  /* std::map<uint,Error> for delete */
} ns3_ccSaveManager_ccSaveThread;
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, vtable) == 0x000, "ccSaveThread.vtable");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, block_allocator) == 0x060, "ccSaveThread.block_allocator");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, job_deque) == 0x078, "ccSaveThread.job_deque");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, critical_section) == 0x0B8, "ccSaveThread.critical_section");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, state_flag) == 0x108, "ccSaveThread.state_flag");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, error_map_save) == 0x110, "ccSaveThread.error_map_save");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, error_map_load) == 0x138, "ccSaveThread.error_map_load");
static_assert(offsetof(ns3_ccSaveManager_ccSaveThread, error_map_delete) == 0x160, "ccSaveThread.error_map_delete");
static_assert(sizeof(ns3_ccSaveManager_ccSaveThread) == 0x168, "ccSaveThread size");

/* ========================================================================
 * ccSaveData
 * Large save-data structure. Size unknown, >= 0x1D818 (highest proven offset
 *   from InitGameSection: +0x1D814 written as uint32).
 * Field offsets from decompiled methods (s3 symbolized code):
 *   Init: +0x04 (float 1.0), +0x108 (uint32 0x10001), +0x5C98 (ccAdvSaveData),
 *         +0x1AF64 (ccCollectionSaveData), +0x1B668 (ccPreSetSaveData),
 *         +0x1C81C (ccChallengeMissionSaveData), +0x1CCD4/+0x1CCDC/+0x1CCD8,
 *         +0x1CCE4/+0x1CCE5 (memset 0xB2F)
 *   InitSystemSection: +0x28 (uint32=2), +0x2C, +0x30, +0x3C, +0x40, +0x10C, +0x110
 *   InitKeyConfigDuel: +0x48 + param_2*0x60 (key config array, 8 uint32 per slot),
 *                      +0x108 + param_2*2 (vibration ushort)
 *   InitGameSection: +0x12C (uint64), +0x134 (uint32=0x12), +0x138 (uint16=0x197),
 *                    +0x13A, +0x13C, +0x140 (memset 0x214), +0x354 (memset 0x5914),
 *                    +0x5C68-0x5C76, +0x1BEC0-0x1BED8, +0x1BF8C (memset 0x88),
 *                    +0x1C018-0x1C814 (loop 0x100 qwords), +0x1C818,
 *                    +0x1BEE0-0x1BF82 (many uint64), +0x1CCE0, +0x1D814
 *   AddMoney: +0x130 (int, money)
 *   GetButtonId: +0x48 + computed offset (key config)
 *   GetNetBattleItemNum: +0x5C76 + param_2*2 (ushort array, max 0x10)
 *   EnableVibration: +0x108 + param_2*2 (ushort)
 *   UpdateTotalTime: +0x12C (uint32, total time)
 *   UnlockCharacterAllType: +0x1BEA0 (bitfield), +0x1BEC0 (bitfield)
 * ======================================================================== */
typedef struct __attribute__((packed)) ns3_ccSaveData {
    /* 0x00000 */ uint8_t _header[0x04];
    /* 0x00004 */ float field_04;               /* Init: set to 1.0f (0x3f800000) */
    /* 0x00008 */ uint8_t _gap_008[0x20];
    /* 0x00028 */ uint32_t system_field_28;     /* InitSystemSection: set to 2 */
    /* 0x0002C */ uint32_t screen_setting_2C;   /* InitScreenSettings/InitSystemSection */
    /* 0x00030 */ uint32_t screen_setting_30;   /* InitScreenSettings/InitSystemSection */
    /* 0x00034 */ uint8_t _gap_034[0x08];
    /* 0x0003C */ uint32_t system_field_3C;     /* InitSystemSection: set to 1 */
    /* 0x00040 */ uint32_t system_field_40;     /* InitSystemSection: set to 1 */
    /* 0x00044 */ uint8_t _gap_044[0x04];
    /* 0x00048 */ uint8_t key_config_duel[0xC0]; /* 2 slots * 0x60 bytes each (8 uint32 per slot) */
    /* 0x00108 */ uint16_t vibration_flags[2];  /* EnableVibration: ushort per player */
    /* 0x0010C */ uint32_t system_field_10C;    /* InitSystemSection: set to 0 */
    /* 0x00110 */ uint32_t system_field_110;    /* InitSystemSection: set to 4 */
    /* 0x00114 */ uint8_t _gap_114[0x18];
    /* 0x0012C */ uint32_t total_time;          /* UpdateTotalTime writes here */
    /* 0x00130 */ int32_t money;                /* AddMoney reads/writes here */
    /* 0x00134 */ uint32_t game_field_134;      /* InitGameSection: set to 0x12 */
    /* 0x00138 */ uint16_t game_field_138;      /* InitGameSection: set to 0x197 */
    /* 0x0013A */ uint8_t game_field_13A;       /* InitGameSection: set to 0 */
    /* 0x0013B */ uint8_t _pad_13B;
    /* 0x0013C */ uint32_t game_field_13C;      /* InitGameSection: set to 0 */
    /* 0x00140 */ uint8_t memset_region_140[0x214]; /* InitGameSection: memset 0 */
    /* 0x00354 */ uint8_t memset_region_354[0x5914]; /* InitGameSection: memset 0 */
    /* 0x05C68 */ uint32_t game_field_5C68;     /* InitGameSection: set to 0x10001 (undefined4*) */
    /* 0x05C6C */ uint16_t game_field_5C6C;     /* InitGameSection: set to 1 (undefined2*) */
    /* 0x05C6E */ uint8_t _pad_5C6E[2];
    /* 0x05C70 */ uint32_t game_field_5C70;     /* InitGameSection: set to 0 */
    /* 0x05C74 */ uint16_t game_field_5C74;     /* InitGameSection: set to 0 */
    /* 0x05C76 */ uint16_t net_battle_items[0x10]; /* GetNetBattleItemNum: ushort[16] */
    /* 0x05C96 */ uint8_t _pad_5C96[2];
    /* 0x05C98 */ uint8_t adv_save_data[0x152CC]; /* ccAdvSaveData embedded (to 0x1AF64) */
    /* 0x1AF64 */ uint8_t collection_save_data[0x704]; /* ccCollectionSaveData (to 0x1B668) */
    /* 0x1B668 */ uint8_t preset_save_data[0x11B4]; /* ccPreSetSaveData (to 0x1C81C) */
    /* 0x1C81C */ uint8_t challenge_mission_data[0x4C4]; /* ccChallengeMissionSaveData (to 0x1CCE0) */
    /* 0x1CCE0 */ uint32_t game_field_1CCE0;    /* InitGameSection: set to 0 */
    /* 0x1CCE4 */ uint8_t field_1CCE4;          /* Init: set to 0 */
    /* 0x1CCE5 */ uint8_t memset_region_1CCE5[0xB2F]; /* Init: memset 0 */
    /* 0x1D814 */ uint32_t game_field_1D814;    /* InitGameSection: set to 0 */
    /* 0x1D818 */ uint8_t _end_pad[0x8];        /* alignment padding */
} ns3_ccSaveData;
static_assert(offsetof(ns3_ccSaveData, field_04) == 0x00004, "ccSaveData.field_04");
static_assert(offsetof(ns3_ccSaveData, system_field_28) == 0x00028, "ccSaveData.system_field_28");
static_assert(offsetof(ns3_ccSaveData, screen_setting_2C) == 0x0002C, "ccSaveData.screen_setting_2C");
static_assert(offsetof(ns3_ccSaveData, screen_setting_30) == 0x00030, "ccSaveData.screen_setting_30");
static_assert(offsetof(ns3_ccSaveData, system_field_3C) == 0x0003C, "ccSaveData.system_field_3C");
static_assert(offsetof(ns3_ccSaveData, system_field_40) == 0x00040, "ccSaveData.system_field_40");
static_assert(offsetof(ns3_ccSaveData, key_config_duel) == 0x00048, "ccSaveData.key_config_duel");
static_assert(offsetof(ns3_ccSaveData, vibration_flags) == 0x00108, "ccSaveData.vibration_flags");
static_assert(offsetof(ns3_ccSaveData, system_field_10C) == 0x0010C, "ccSaveData.system_field_10C");
static_assert(offsetof(ns3_ccSaveData, system_field_110) == 0x00110, "ccSaveData.system_field_110");
static_assert(offsetof(ns3_ccSaveData, total_time) == 0x0012C, "ccSaveData.total_time");
static_assert(offsetof(ns3_ccSaveData, money) == 0x00130, "ccSaveData.money");
static_assert(offsetof(ns3_ccSaveData, game_field_134) == 0x00134, "ccSaveData.game_field_134");
static_assert(offsetof(ns3_ccSaveData, game_field_138) == 0x00138, "ccSaveData.game_field_138");
static_assert(offsetof(ns3_ccSaveData, game_field_13A) == 0x0013A, "ccSaveData.game_field_13A");
static_assert(offsetof(ns3_ccSaveData, game_field_13C) == 0x0013C, "ccSaveData.game_field_13C");
static_assert(offsetof(ns3_ccSaveData, memset_region_140) == 0x00140, "ccSaveData.memset_region_140");
static_assert(offsetof(ns3_ccSaveData, memset_region_354) == 0x00354, "ccSaveData.memset_region_354");
static_assert(offsetof(ns3_ccSaveData, game_field_5C68) == 0x05C68, "ccSaveData.game_field_5C68");
static_assert(offsetof(ns3_ccSaveData, game_field_5C6C) == 0x05C6C, "ccSaveData.game_field_5C6C");
static_assert(offsetof(ns3_ccSaveData, game_field_5C70) == 0x05C70, "ccSaveData.game_field_5C70");
static_assert(offsetof(ns3_ccSaveData, game_field_5C74) == 0x05C74, "ccSaveData.game_field_5C74");
static_assert(offsetof(ns3_ccSaveData, net_battle_items) == 0x05C76, "ccSaveData.net_battle_items");
static_assert(offsetof(ns3_ccSaveData, adv_save_data) == 0x05C98, "ccSaveData.adv_save_data");
static_assert(offsetof(ns3_ccSaveData, collection_save_data) == 0x1AF64, "ccSaveData.collection_save_data");
static_assert(offsetof(ns3_ccSaveData, preset_save_data) == 0x1B668, "ccSaveData.preset_save_data");
static_assert(offsetof(ns3_ccSaveData, challenge_mission_data) == 0x1C81C, "ccSaveData.challenge_mission_data");
static_assert(offsetof(ns3_ccSaveData, game_field_1CCE0) == 0x1CCE0, "ccSaveData.game_field_1CCE0");
static_assert(offsetof(ns3_ccSaveData, field_1CCE4) == 0x1CCE4, "ccSaveData.field_1CCE4");
static_assert(offsetof(ns3_ccSaveData, memset_region_1CCE5) == 0x1CCE5, "ccSaveData.memset_region_1CCE5");
static_assert(offsetof(ns3_ccSaveData, game_field_1D814) == 0x1D814, "ccSaveData.game_field_1D814");
/* Size not asserted: highest proven access is +0x1D814+4=0x1D818, exact total size unproven */

/* Offset-only accessors for ccSaveData fields */
#define NS3_SAVEDATA_FIELD_04_OFF           0x00004
#define NS3_SAVEDATA_SYSTEM_28_OFF          0x00028
#define NS3_SAVEDATA_SCREEN_2C_OFF          0x0002C
#define NS3_SAVEDATA_SCREEN_30_OFF          0x00030
#define NS3_SAVEDATA_SYSTEM_3C_OFF          0x0003C
#define NS3_SAVEDATA_SYSTEM_40_OFF          0x00040
#define NS3_SAVEDATA_KEY_CONFIG_OFF         0x00048
#define NS3_SAVEDATA_VIBRATION_OFF          0x00108
#define NS3_SAVEDATA_TOTAL_TIME_OFF         0x0012C
#define NS3_SAVEDATA_MONEY_OFF              0x00130
#define NS3_SAVEDATA_ADV_SAVE_DATA_OFF      0x05C98
#define NS3_SAVEDATA_COLLECTION_OFF         0x1AF64
#define NS3_SAVEDATA_PRESET_OFF             0x1B668
#define NS3_SAVEDATA_CHALLENGE_OFF          0x1C81C
#define NS3_SAVEDATA_NET_BATTLE_ITEMS_OFF   0x05C76

#endif /* CMN06_S3_H */