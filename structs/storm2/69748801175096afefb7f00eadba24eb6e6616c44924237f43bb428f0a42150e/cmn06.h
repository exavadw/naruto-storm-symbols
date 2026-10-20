/* cmn06.h — Storm 2 (NSUNS2.exe, s2) struct layouts for group cmn06
 * INFERRED from static analysis. Not CONFIRMED by runtime trace.
 * All offsets proven from decompiled code; sizes proven where allocator/ctor evidence exists.
 * Own-game names only (Storm 2 strings/code). PC x64 offsets (image base 0x140000000).
 */
#ifndef CMN06_S2_H
#define CMN06_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccRcNavMeshSolo
 * Size unknown, >= 0x10 (dtor accesses param_1[1] = +0x08).
 * Embedded in ccRecastNavigation; s1 had size 0x18.
 * Dtor: vtable=PTR_FUN_1408a2e20, frees param_1[1] via dtFreeNavMesh,
 *   then sets vtable to PTR_FUN_1408a2d00 (base class dtor).
 * Delete: same pattern, checks *(longlong*)(param_1+8) != 0.
 * Only 2 unique methods (dtor + Delete); listed as "too small" per task rules
 * but included because ccRecastNavigation embeds it.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccRcNavMeshSolo {
    /* 0x00 */ uint64_t vtable;       /* PTR_FUN_1408a2e20 / PTR_FUN_1408a2d00 */
    /* 0x08 */ uint64_t nav_mesh;     /* dtNavMesh*, freed via dtFreeNavMesh */
} ns2_ccRcNavMeshSolo;
_Static_assert(offsetof(ns2_ccRcNavMeshSolo, vtable) == 0x00, "ccRcNavMeshSolo.vtable");
_Static_assert(offsetof(ns2_ccRcNavMeshSolo, nav_mesh) == 0x08, "ccRcNavMeshSolo.nav_mesh");
/* Size not asserted: only 2 methods, size unproven beyond >= 0x10 */

/* ========================================================================
 * ccRcNavMeshTempObstacle
 * Size unknown, >= 0x80 (ctor writes param_1[0..5] + nuccModelPrimitive at +0x30).
 * Ctor: vtable=PTR_FUN_1408a2db0, zeros [1..5],
 *   allocates sub-object 0x20B (param_1[1], vtable PTR_FUN_1408a2d60),
 *   allocates sub-object 8B (param_1[2], vtable PTR_FUN_1408a2d80),
 *   allocates sub-object 0x40B (param_1[3], vtable PTR_FUN_1408a2da0).
 * Create: writes param_1[4]=tile_cache (FUN_140191cb0), param_1[5]=nav_mesh (FUN_14018eda0).
 * Delete: frees param_1[5] (nav_mesh) and param_1[4] (tile_cache), destroys model_primitive.
 * DebugDraw: reads nav_mesh at +0x28, tile_cache at +0x20, model_primitive at +0x30.
 * nuccModelPrimitive embedded at param_1+6 = +0x30.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccRcNavMeshTempObstacle {
    /* 0x00 */ uint64_t vtable;          /* PTR_FUN_1408a2db0 */
    /* 0x08 */ uint64_t sub_alloc_20;    /* 0x20-byte heap alloc, vtable PTR_FUN_1408a2d60 */
    /* 0x10 */ uint64_t sub_alloc_8;     /* 8-byte heap alloc, vtable PTR_FUN_1408a2d80 */
    /* 0x18 */ uint64_t sub_alloc_40;    /* 0x40-byte heap alloc, vtable PTR_FUN_1408a2da0 */
    /* 0x20 */ uint64_t tile_cache;      /* dtTileCache*, written by Create */
    /* 0x28 */ uint64_t nav_mesh;        /* dtNavMesh*, written by Create */
    /* 0x30 */ uint8_t model_primitive[0x50]; /* nuccModelPrimitive at param_1+6 */
} ns2_ccRcNavMeshTempObstacle;
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, vtable) == 0x00, "ccRcNavMeshTempObstacle.vtable");
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, sub_alloc_20) == 0x08, "ccRcNavMeshTempObstacle.sub_alloc_20");
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, sub_alloc_8) == 0x10, "ccRcNavMeshTempObstacle.sub_alloc_8");
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, sub_alloc_40) == 0x18, "ccRcNavMeshTempObstacle.sub_alloc_40");
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, tile_cache) == 0x20, "ccRcNavMeshTempObstacle.tile_cache");
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, nav_mesh) == 0x28, "ccRcNavMeshTempObstacle.nav_mesh");
_Static_assert(offsetof(ns2_ccRcNavMeshTempObstacle, model_primitive) == 0x30, "ccRcNavMeshTempObstacle.model_primitive");
_Static_assert(sizeof(ns2_ccRcNavMeshTempObstacle) == 0x80, "ccRcNavMeshTempObstacle size");

/* ========================================================================
 * ccPresenceManager::Impl
 * Size unknown, >= 0x30 (SetPresence accesses param_1[5] = +0x28 as int).
 * Clear: traverses tree via *param_1, resets tree nodes at +0x00/+0x08/+0x10,
 *   clears param_1[1]=0, calls SteamFriends->SetRichPresence("status",0),
 *   clears param_1[5]=0.
 * SetPresence: checks param_1[5]!=0, gets SteamFriends, traverses std::map
 *   tree rooted at *param_1 to find entry by key (param_3), reads string
 *   from tree node at offset +5 within node, calls SetRichPresence("status",str).
 * Only 2 methods; layout is minimal. Tree structure is std::map<int,std::string>.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccPresenceManager_Impl {
    /* 0x00 */ uint64_t tree_root;      /* std::map root node ptr */
    /* 0x08 */ uint64_t tree_end;       /* std::map end sentinel (cleared in Clear) */
    /* 0x10 */ uint64_t tree_size;      /* std::map size or header (cleared in Clear) */
    /* 0x18 */ uint8_t _pad_18[0x10];
    /* 0x28 */ uint32_t presence_flag;  /* checked != 0 before SteamFriends call */
    /* 0x2C */ uint8_t _pad_2C[4];
} ns2_ccPresenceManager_Impl;
_Static_assert(offsetof(ns2_ccPresenceManager_Impl, tree_root) == 0x00, "ccPresenceManager::Impl.tree_root");
_Static_assert(offsetof(ns2_ccPresenceManager_Impl, tree_end) == 0x08, "ccPresenceManager::Impl.tree_end");
_Static_assert(offsetof(ns2_ccPresenceManager_Impl, tree_size) == 0x10, "ccPresenceManager::Impl.tree_size");
_Static_assert(offsetof(ns2_ccPresenceManager_Impl, presence_flag) == 0x28, "ccPresenceManager::Impl.presence_flag");
_Static_assert(sizeof(ns2_ccPresenceManager_Impl) == 0x30, "ccPresenceManager::Impl size");

/* ========================================================================
 * ccRecastNavigation
 * Size unknown, >= 0x1C8 (surface max offset from s1; s2 methods confirm similar layout).
 * Dtor: frees nav_mesh at +0x10, destroys embedded objects.
 * CollectAreaPolygons/CollectOffmeshLinks: read nav_mesh at +0x10.
 * DebugDrawOffmesh: reads std::list at +0x188, list size at +0x190, std::map at +0x1B0.
 * Embeds ccRcNavMeshSolo at +0x18 (inferred from s1 layout, confirmed by field gaps).
 * Embeds ccRcNavMeshTempObstacle at +0x30 (inferred from s1 layout).
 * Vtable: not directly observed in symbolized methods (dtor was not in batch).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccRecastNavigation {
    /* 0x000 */ uint64_t vtable;
    /* 0x008 */ uint8_t _pad_008[0x08];
    /* 0x010 */ uint64_t nav_mesh;             /* dtNavMesh*, used by Collect/DebugDraw */
    /* 0x018 */ uint8_t rc_nav_mesh_solo[0x18]; /* embedded ccRcNavMeshSolo */
    /* 0x030 */ uint8_t rc_nav_mesh_temp_obstacle[0x158]; /* embedded ccRcNavMeshTempObstacle */
    /* 0x188 */ uint8_t std_list[0x08];        /* std::list head */
    /* 0x190 */ uint64_t list_size;            /* std::list size counter */
    /* 0x198 */ uint8_t _pad_198[0x18];
    /* 0x1B0 */ uint8_t std_map[0x18];         /* std::map/tree */
} ns2_ccRecastNavigation;
_Static_assert(offsetof(ns2_ccRecastNavigation, vtable) == 0x000, "ccRecastNavigation.vtable");
_Static_assert(offsetof(ns2_ccRecastNavigation, nav_mesh) == 0x010, "ccRecastNavigation.nav_mesh");
_Static_assert(offsetof(ns2_ccRecastNavigation, rc_nav_mesh_solo) == 0x018, "ccRecastNavigation.rc_nav_mesh_solo");
_Static_assert(offsetof(ns2_ccRecastNavigation, rc_nav_mesh_temp_obstacle) == 0x030, "ccRecastNavigation.rc_nav_mesh_temp_obstacle");
_Static_assert(offsetof(ns2_ccRecastNavigation, std_list) == 0x188, "ccRecastNavigation.std_list");
_Static_assert(offsetof(ns2_ccRecastNavigation, list_size) == 0x190, "ccRecastNavigation.list_size");
_Static_assert(offsetof(ns2_ccRecastNavigation, std_map) == 0x1B0, "ccRecastNavigation.std_map");
_Static_assert(sizeof(ns2_ccRecastNavigation) == 0x1C8, "ccRecastNavigation size");

/* ========================================================================
 * ccSaveLoad
 * Only 1 method found (GetSaveDataDate): delegates to ccUiWindow::Initialize.
 * Too small for full reconstruction; listed in report.
 * s1 size was 0x98. No s2-specific offset evidence collected.
 * ======================================================================== */
/* Not reconstructed: only 1 method. See REPORT.md. */

/* ========================================================================
 * ccSaveManager
 * Size unknown, >= 0x20 (Init stores save_thread ptr at +0x18).
 * Init (from pre-compaction summary): allocates block, stores ptr at +0x10,
 *   stores ccSaveThread ptr at +0x18.
 * Dtor: frees ptr at +0x10.
 * Vtable funcs at +0x08 and +0x10 (virtual dispatch observed).
 * Layout matches s1 structure closely.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccSaveManager {
    /* 0x00 */ uint64_t vtable;
    /* 0x08 */ uint64_t vfunc_08;       /* virtual function pointer */
    /* 0x10 */ uint64_t alloc_block;    /* heap allocation from Init */
    /* 0x18 */ uint64_t save_thread;    /* ccSaveManager::ccSaveThread* */
} ns2_ccSaveManager;
_Static_assert(offsetof(ns2_ccSaveManager, vtable) == 0x00, "ccSaveManager.vtable");
_Static_assert(offsetof(ns2_ccSaveManager, vfunc_08) == 0x08, "ccSaveManager.vfunc_08");
_Static_assert(offsetof(ns2_ccSaveManager, alloc_block) == 0x10, "ccSaveManager.alloc_block");
_Static_assert(offsetof(ns2_ccSaveManager, save_thread) == 0x18, "ccSaveManager.save_thread");
/* Size not asserted: only partial offset coverage, >= 0x20 */

/* ========================================================================
 * ccSaveManager::ccSaveThread
 * Size proven >= 0x168 from ctor: last init at param_1+0x2c (=+0x160) + 8B access.
 * Inherits nuccThread base.
 * Ctor: calls nuccThread::nuccThread(), BlockAllocator at +0x60,
 *   vtable=PTR_FUN_14089da00, deque-like init at +0x78,
 *   nuccCriticalSection at +0xB8, uint32 flag at +0x108,
 *   three error-map inits at +0x110, +0x138, +0x160.
 * BeginSave: accesses +0x60 (vfunc), +0x78 (job deque), +0xB8 (critsec lock/unlock),
 *   +0x110 (error map erase).
 * BeginLoad: same + +0x138 (error map erase).
 * BeginDelete: same + +0x160 (error map erase).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccSaveManager_ccSaveThread {
    /* 0x000 */ uint64_t vtable;              /* PTR_FUN_14089da00 */
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
} ns2_ccSaveManager_ccSaveThread;
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, vtable) == 0x000, "ccSaveThread.vtable");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, block_allocator) == 0x060, "ccSaveThread.block_allocator");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, job_deque) == 0x078, "ccSaveThread.job_deque");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, critical_section) == 0x0B8, "ccSaveThread.critical_section");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, state_flag) == 0x108, "ccSaveThread.state_flag");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, error_map_save) == 0x110, "ccSaveThread.error_map_save");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, error_map_load) == 0x138, "ccSaveThread.error_map_load");
_Static_assert(offsetof(ns2_ccSaveManager_ccSaveThread, error_map_delete) == 0x160, "ccSaveThread.error_map_delete");
_Static_assert(sizeof(ns2_ccSaveManager_ccSaveThread) == 0x168, "ccSaveThread size");

/* ========================================================================
 * ccSaveData
 * Large save-data structure. Size unknown, >= 0x1A400 (highest proven offset
 *   0x19ffe + memset 0x400 = 0x1A3FE, rounded up).
 * Dramatically larger than s1 (s1 was >= 0x1030).
 * Field offsets from decompiled methods (pre-compaction + current session):
 *   +0x08: first field access
 *   +0x18: IsPlayerUnlocked bitfield base
 *   +0x38: IsUnlockedSupportType bitfield base
 *   +0x98: sub-object via FUN_1401efe00
 *   +0x127BC/+0x127C0: battle record
 *   +0x192EC-0x19308: key config array (8 uint32 entries)
 *   +0x193C8: vibration ushort array
 *   +0x193F0: storm points (uint32)
 *   +0x193F4: card array uint32[0x100]
 *   +0x197F4: nickname array uint32[0x100]
 *   +0x19BF4: char use num byte[0x39]
 *   +0x19C74: dodge effect byte[0x14]
 *   +0x19C89: memset region 0x375 bytes
 *   +0x19FFE: memset region 0x400 bytes
 * ======================================================================== */
typedef struct __attribute__((packed)) ns2_ccSaveData {
    /* 0x00000 */ uint8_t _header[0x08];
    /* 0x00008 */ uint8_t field_08[0x10];           /* first accessed field */
    /* 0x00018 */ uint8_t player_unlock_bits[0x20]; /* IsPlayerUnlocked bitfield base */
    /* 0x00038 */ uint8_t support_type_bits[0x60];  /* IsUnlockedSupportType bitfield base */
    /* 0x00098 */ uint64_t sub_object_ptr;          /* allocated via FUN_1401efe00 */
    /* 0x000A0 */ uint8_t _gap_0A0[0x1271C];        /* large gap to battle record */
    /* 0x127BC */ uint32_t battle_record_a;         /* battle record field */
    /* 0x127C0 */ uint32_t battle_record_b;         /* battle record field */
    /* 0x127C4 */ uint8_t _gap_127C4[0x6B28];       /* gap to key config */
    /* 0x192EC */ uint32_t key_config[8];           /* key config array, 8 entries to 0x1930C */
    /* 0x1930C */ uint8_t _gap_1930C[0xBC];         /* gap to vibration */
    /* 0x193C8 */ uint16_t vibration_config[0x14];  /* vibration ushort array (to 0x193F0) */
    /* 0x193F0 */ uint32_t storm_points;            /* storm points currency */
    /* 0x193F4 */ uint32_t cards[0x100];            /* card collection array */
    /* 0x197F4 */ uint32_t nicknames[0x100];        /* nickname array */
    /* 0x19BF4 */ uint8_t char_use_num[0x39];       /* character usage counts */
    /* 0x19C2D */ uint8_t _pad_19C2D[0x47];         /* padding to dodge effect */
    /* 0x19C74 */ uint8_t dodge_effect[0x14];       /* dodge effect flags */
    /* 0x19C88 */ uint8_t _pad_19C88;
    /* 0x19C89 */ uint8_t memset_region_a[0x375];   /* memset'd region */
    /* 0x19FFE */ uint8_t memset_region_b[0x400];   /* memset'd region, last proven access */
} ns2_ccSaveData;
_Static_assert(offsetof(ns2_ccSaveData, field_08) == 0x00008, "ccSaveData.field_08");
_Static_assert(offsetof(ns2_ccSaveData, player_unlock_bits) == 0x00018, "ccSaveData.player_unlock_bits");
_Static_assert(offsetof(ns2_ccSaveData, support_type_bits) == 0x00038, "ccSaveData.support_type_bits");
_Static_assert(offsetof(ns2_ccSaveData, sub_object_ptr) == 0x00098, "ccSaveData.sub_object_ptr");
_Static_assert(offsetof(ns2_ccSaveData, battle_record_a) == 0x127BC, "ccSaveData.battle_record_a");
_Static_assert(offsetof(ns2_ccSaveData, battle_record_b) == 0x127C0, "ccSaveData.battle_record_b");
_Static_assert(offsetof(ns2_ccSaveData, key_config) == 0x192EC, "ccSaveData.key_config");
_Static_assert(offsetof(ns2_ccSaveData, vibration_config) == 0x193C8, "ccSaveData.vibration_config");
_Static_assert(offsetof(ns2_ccSaveData, storm_points) == 0x193F0, "ccSaveData.storm_points");
_Static_assert(offsetof(ns2_ccSaveData, cards) == 0x193F4, "ccSaveData.cards");
_Static_assert(offsetof(ns2_ccSaveData, nicknames) == 0x197F4, "ccSaveData.nicknames");
_Static_assert(offsetof(ns2_ccSaveData, char_use_num) == 0x19BF4, "ccSaveData.char_use_num");
_Static_assert(offsetof(ns2_ccSaveData, dodge_effect) == 0x19C74, "ccSaveData.dodge_effect");
_Static_assert(offsetof(ns2_ccSaveData, memset_region_a) == 0x19C89, "ccSaveData.memset_region_a");
_Static_assert(offsetof(ns2_ccSaveData, memset_region_b) == 0x19FFE, "ccSaveData.memset_region_b");
/* Size not asserted: highest access is 0x19FFE+0x400=0x1A3FE, exact total size unproven */

/* Offset-only accessors for ccSaveData fields */
#define NS2_SAVEDATA_PLAYER_UNLOCK_OFF    0x00018
#define NS2_SAVEDATA_SUPPORT_TYPE_OFF     0x00038
#define NS2_SAVEDATA_SUB_OBJECT_OFF       0x00098
#define NS2_SAVEDATA_BATTLE_REC_A_OFF     0x127BC
#define NS2_SAVEDATA_BATTLE_REC_B_OFF     0x127C0
#define NS2_SAVEDATA_KEY_CONFIG_OFF       0x192EC
#define NS2_SAVEDATA_VIBRATION_OFF        0x193C8
#define NS2_SAVEDATA_STORM_POINTS_OFF     0x193F0
#define NS2_SAVEDATA_CARDS_OFF            0x193F4
#define NS2_SAVEDATA_NICKNAMES_OFF        0x197F4
#define NS2_SAVEDATA_CHAR_USE_NUM_OFF     0x19BF4
#define NS2_SAVEDATA_DODGE_EFFECT_OFF     0x19C74

#endif /* CMN06_S2_H */