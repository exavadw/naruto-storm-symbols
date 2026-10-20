/* cmn06.h — Storm 1 (NSUNS1.exe, s1) struct layouts for group cmn06
 * INFERRED from static analysis. Not CONFIRMED by runtime trace.
 * All offsets proven from decompiled code; sizes proven where allocator/ctor evidence exists.
 * Own-game names only (Storm 1 strings/code). PC x64 offsets (image base 0x140000000).
 */
#ifndef CMN06_H
#define CMN06_H

#include <stdint.h>
#include <stddef.h>

/* ========================================================================
 * ccSaveLoad
 * Size proven >= 0x98 from ctor at 0x39168C (writes +0x90 as uint64).
 * Ctor at 0x2FB358 is a secondary/base ctor (writes +0x90 critsec).
 * Embedded nuccCriticalSection at +0x20 (dtor confirms).
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccSaveLoad {
    /* 0x00 */ uint8_t _vtable_or_base[8];
    /* 0x08 */ uint8_t _pad_08[4];
    /* 0x0C */ uint32_t state;
    /* 0x10 */ uint8_t _pad_10[0x10];
    /* 0x20 */ uint8_t critical_section[0x28];
    /* 0x48 */ uint8_t _pad_48[0x28];
    /* 0x70 */ uint32_t field_70;
    /* 0x74 */ uint8_t _pad_74[4];
    /* 0x78 */ uint64_t field_78;
    /* 0x80 */ uint64_t field_80;
    /* 0x88 */ uint64_t field_88;
    /* 0x90 */ uint64_t field_90;
} ns1_ccSaveLoad;
_Static_assert(offsetof(ns1_ccSaveLoad, state) == 0x0C, "ccSaveLoad.state");
_Static_assert(offsetof(ns1_ccSaveLoad, critical_section) == 0x20, "ccSaveLoad.critical_section");
_Static_assert(offsetof(ns1_ccSaveLoad, field_70) == 0x70, "ccSaveLoad.field_70");
_Static_assert(offsetof(ns1_ccSaveLoad, field_78) == 0x78, "ccSaveLoad.field_78");
_Static_assert(offsetof(ns1_ccSaveLoad, field_80) == 0x80, "ccSaveLoad.field_80");
_Static_assert(offsetof(ns1_ccSaveLoad, field_88) == 0x88, "ccSaveLoad.field_88");
_Static_assert(offsetof(ns1_ccSaveLoad, field_90) == 0x90, "ccSaveLoad.field_90");
_Static_assert(sizeof(ns1_ccSaveLoad) == 0x98, "ccSaveLoad size");

/* ========================================================================
 * ccSaveManager
 * Size proven >= 0x168 from surface max offset 0x160 + 8B access.
 * Init (0x391F50) allocates 0x1550 via MallocCore, stores ptr at +0x10.
 * Initialize (0x54E3A0) stores ccSaveThread ptr at param_1[3] = +0x18.
 * Dtor frees ptr at +0x10.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccSaveManager {
    /* 0x00 */ uint8_t _vtable[8];
    /* 0x08 */ uint8_t _pad_08[8];
    /* 0x10 */ uint64_t alloc_block;
    /* 0x18 */ uint64_t save_thread;
    /* 0x20 */ uint8_t _pad_20[0x40];
    /* 0x60 */ uint64_t field_60;
    /* 0x68 */ uint8_t _pad_68[0x10];
    /* 0x78 */ uint64_t field_78;
    /* 0x80 */ uint64_t field_80;
    /* 0x88 */ uint8_t _pad_88[0x30];
    /* 0xB8 */ uint64_t field_B8;
    /* 0xC0 */ uint8_t _pad_C0[0x48];
    /* 0x108 */ uint32_t field_108;
    /* 0x10C */ uint8_t _pad_10C[4];
    /* 0x110 */ uint64_t field_110;
    /* 0x118 */ uint8_t _pad_118[0x20];
    /* 0x138 */ uint64_t field_138;
    /* 0x140 */ uint8_t _pad_140[0x20];
    /* 0x160 */ uint64_t field_160;
} ns1_ccSaveManager;
_Static_assert(offsetof(ns1_ccSaveManager, alloc_block) == 0x10, "ccSaveManager.alloc_block");
_Static_assert(offsetof(ns1_ccSaveManager, save_thread) == 0x18, "ccSaveManager.save_thread");
_Static_assert(offsetof(ns1_ccSaveManager, field_60) == 0x60, "ccSaveManager.field_60");
_Static_assert(offsetof(ns1_ccSaveManager, field_78) == 0x78, "ccSaveManager.field_78");
_Static_assert(offsetof(ns1_ccSaveManager, field_80) == 0x80, "ccSaveManager.field_80");
_Static_assert(offsetof(ns1_ccSaveManager, field_B8) == 0xB8, "ccSaveManager.field_B8");
_Static_assert(offsetof(ns1_ccSaveManager, field_108) == 0x108, "ccSaveManager.field_108");
_Static_assert(offsetof(ns1_ccSaveManager, field_110) == 0x110, "ccSaveManager.field_110");
_Static_assert(offsetof(ns1_ccSaveManager, field_138) == 0x138, "ccSaveManager.field_138");
_Static_assert(offsetof(ns1_ccSaveManager, field_160) == 0x160, "ccSaveManager.field_160");
_Static_assert(sizeof(ns1_ccSaveManager) == 0x168, "ccSaveManager size");

/* ========================================================================
 * ccSaveManager::ccSaveThread
 * Size proven >= 0x168 from ctor (0x54EA60): last write at +0x2c*8=0x160+8B.
 * Inherits nuccThread base, embeds BlockAllocator at +0x60, critsec at +0xB8.
 * Vtable: PTR_FUN_140746588.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccSaveManager_ccSaveThread {
    /* 0x00 */ uint64_t vtable;
    /* 0x08 */ uint8_t _nucc_thread_base[0x58];
    /* 0x60 */ uint64_t block_allocator;
    /* 0x68 */ uint8_t _pad_68[0x50];
    /* 0xB8 */ uint64_t critical_section;
    /* 0xC0 */ uint8_t _pad_C0[0x48];
    /* 0x108 */ uint32_t field_108;
    /* 0x10C */ uint8_t _pad_10C[4];
    /* 0x110 */ uint64_t field_110;
    /* 0x118 */ uint8_t _pad_118[0x20];
    /* 0x138 */ uint64_t field_138;
    /* 0x140 */ uint8_t _pad_140[0x20];
    /* 0x160 */ uint64_t field_160;
} ns1_ccSaveManager_ccSaveThread;
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, vtable) == 0x00, "ccSaveThread.vtable");
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, block_allocator) == 0x60, "ccSaveThread.block_allocator");
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, critical_section) == 0xB8, "ccSaveThread.critical_section");
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, field_108) == 0x108, "ccSaveThread.field_108");
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, field_110) == 0x110, "ccSaveThread.field_110");
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, field_138) == 0x138, "ccSaveThread.field_138");
_Static_assert(offsetof(ns1_ccSaveManager_ccSaveThread, field_160) == 0x160, "ccSaveThread.field_160");
_Static_assert(sizeof(ns1_ccSaveManager_ccSaveThread) == 0x168, "ccSaveThread size");

/* ========================================================================
 * ccRecastNavigation
 * Size unknown, >= 0x1C8 (surface max offset 0x1C0 + 8B).
 * Embeds ccRcNavMeshSolo at +0x18, ccRcNavMeshTempObstacle at +0x30.
 * Vtable: PTR_FUN_1407479a8. std::map at +0x1B0. nummModelManager at +0x188.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccRecastNavigation {
    /* 0x00 */ uint64_t vtable;
    /* 0x08 */ uint8_t _pad_08[0x10];
    /* 0x18 */ uint8_t rc_nav_mesh_solo[0x18];
    /* 0x30 */ uint8_t rc_nav_mesh_temp_obstacle[0x158];
    /* 0x188 */ uint64_t model_manager;
    /* 0x190 */ uint8_t _pad_190[8];
    /* 0x198 */ uint64_t field_198;
    /* 0x1A0 */ uint8_t _pad_1A0[0x10];
    /* 0x1B0 */ uint64_t std_map;
    /* 0x1B8 */ uint8_t _pad_1B8[8];
    /* 0x1C0 */ uint64_t field_1C0;
} ns1_ccRecastNavigation;
_Static_assert(offsetof(ns1_ccRecastNavigation, vtable) == 0x00, "ccRecastNavigation.vtable");
_Static_assert(offsetof(ns1_ccRecastNavigation, rc_nav_mesh_solo) == 0x18, "ccRecastNavigation.rc_nav_mesh_solo");
_Static_assert(offsetof(ns1_ccRecastNavigation, rc_nav_mesh_temp_obstacle) == 0x30, "ccRecastNavigation.rc_nav_mesh_temp_obstacle");
_Static_assert(offsetof(ns1_ccRecastNavigation, model_manager) == 0x188, "ccRecastNavigation.model_manager");
_Static_assert(offsetof(ns1_ccRecastNavigation, field_198) == 0x198, "ccRecastNavigation.field_198");
_Static_assert(offsetof(ns1_ccRecastNavigation, std_map) == 0x1B0, "ccRecastNavigation.std_map");
_Static_assert(offsetof(ns1_ccRecastNavigation, field_1C0) == 0x1C0, "ccRecastNavigation.field_1C0");
_Static_assert(sizeof(ns1_ccRecastNavigation) == 0x1C8, "ccRecastNavigation size");

/* ========================================================================
 * ccRcNavMeshTempObstacle
 * Size unknown, >= 0x80 (ctor writes param_1[0..5] + calls FUN_1404b1770(param_1+6)).
 * Ctor (0x5830A0): vtable=PTR_FUN_140749280, zeros [1..5],
 * calls FUN_1404b1770(param_1 + 6) => nuccModelPrimitive at +0x30.
 * Allocates sub-object of 0x20 bytes (param_1[1]), another of 8 bytes (param_1[2]),
 * and one of 0x40 bytes (param_1[3]).
 * Create (0x5832A0): reads vfunc at +0x10, writes param_1[4] and param_1[5].
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccRcNavMeshTempObstacle {
    /* 0x00 */ uint64_t vtable;          /* PTR_FUN_140749280 */
    /* 0x08 */ uint64_t sub_alloc_20;    /* 0x20-byte heap alloc from ctor */
    /* 0x10 */ uint64_t sub_alloc_8;     /* 8-byte heap alloc from ctor */
    /* 0x18 */ uint64_t sub_alloc_40;    /* 0x40-byte heap alloc from ctor */
    /* 0x20 */ uint64_t field_20;        /* written by Create (param_1[4]) */
    /* 0x28 */ uint64_t field_28;        /* written by Create (param_1[5]) */
    /* 0x30 */ uint8_t model_primitive[0x50]; /* nuccModelPrimitive at param_1+6 */
} ns1_ccRcNavMeshTempObstacle;
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, vtable) == 0x00, "ccRcNavMeshTempObstacle.vtable");
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, sub_alloc_20) == 0x08, "ccRcNavMeshTempObstacle.sub_alloc_20");
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, sub_alloc_8) == 0x10, "ccRcNavMeshTempObstacle.sub_alloc_8");
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, sub_alloc_40) == 0x18, "ccRcNavMeshTempObstacle.sub_alloc_40");
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, field_20) == 0x20, "ccRcNavMeshTempObstacle.field_20");
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, field_28) == 0x28, "ccRcNavMeshTempObstacle.field_28");
_Static_assert(offsetof(ns1_ccRcNavMeshTempObstacle, model_primitive) == 0x30, "ccRcNavMeshTempObstacle.model_primitive");
_Static_assert(sizeof(ns1_ccRcNavMeshTempObstacle) == 0x80, "ccRcNavMeshTempObstacle size");

/* ========================================================================
 * ccRcNavMeshSolo
 * Size unknown, >= 0x18 (embedded at +0x18 in ccRecastNavigation, next field at +0x30).
 * Dtor (0x583BB0): vtable=PTR_FUN_1407492f0 then PTR_FUN_1407491d0.
 * param_1[1] is a heap pointer freed via FUN_14013a9e0 if non-null.
 * Minimal layout: vtable + one managed pointer.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccRcNavMeshSolo {
    /* 0x00 */ uint64_t vtable;       /* PTR_FUN_1407492f0 / PTR_FUN_1407491d0 */
    /* 0x08 */ uint64_t managed_ptr;  /* heap pointer freed in dtor */
    /* 0x10 */ uint8_t _pad_10[8];   /* padding to reach 0x18 embedded size */
} ns1_ccRcNavMeshSolo;
_Static_assert(offsetof(ns1_ccRcNavMeshSolo, vtable) == 0x00, "ccRcNavMeshSolo.vtable");
_Static_assert(offsetof(ns1_ccRcNavMeshSolo, managed_ptr) == 0x08, "ccRcNavMeshSolo.managed_ptr");
_Static_assert(sizeof(ns1_ccRcNavMeshSolo) == 0x18, "ccRcNavMeshSolo size");

/* ========================================================================
 * ccPresenceManager::Impl
 * Size unknown, >= 0x30 (SetPresence accesses param_1[5] = +0x28 as int).
 * SetPresence (0x54C080): checks param_1[5] != 0, reads *param_1 (vtable-like ptr),
 * traverses tree structure via param_1[0]->[1] chain.
 * Only one method found; layout is minimal.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccPresenceManager_Impl {
    /* 0x00 */ uint64_t tree_root;     /* pointer to tree node, dereferenced in SetPresence */
    /* 0x08 */ uint8_t _pad_08[0x20];
    /* 0x28 */ uint32_t presence_flag; /* checked != 0 before SteamFriends call */
    /* 0x2C */ uint8_t _pad_2C[4];
} ns1_ccPresenceManager_Impl;
_Static_assert(offsetof(ns1_ccPresenceManager_Impl, tree_root) == 0x00, "ccPresenceManager::Impl.tree_root");
_Static_assert(offsetof(ns1_ccPresenceManager_Impl, presence_flag) == 0x28, "ccPresenceManager::Impl.presence_flag");
_Static_assert(sizeof(ns1_ccPresenceManager_Impl) == 0x30, "ccPresenceManager::Impl size");

/* ========================================================================
 * ccSaveData
 * Large save-data structure. Size unknown, >= 0x1030 (InitGameSection writes +0x102C).
 * Field offsets from decompiled methods:
 *   InitGameSection (0x390FF4): +0x18 byte, +0x1A memset 0x32C, +0x346 memset 0x196,
 *     +0x4DC uint16[20], +0x504 byte[20], +0xF18-F7C various, +0x102C uint32.
 *   IsMainFlagOn (0x3913F4): bitfield at +0x538, indexed by (id>>5)*4.
 *   IsPlayerUnlocked (0x39142C): player unlock bits at +0x998, indexed by (id>>3).
 *   GetButtonId (0x390DF0): key config array at +0xE30, stride 0x18*4=0x60 per entry.
 *   InitSystemSection (0x3912C4): +0xE18 uint32=1, +0xE1C uint32=0, +0xE20 uint32=0.
 *   SetMoney (0x391640): money at +0xF1C uint32.
 *
 * Linear layout with correct ordering of proven offsets.
 * ======================================================================== */
typedef struct __attribute__((packed)) ns1_ccSaveData {
    /* 0x000 */ uint8_t _header[0x18];
    /* 0x018 */ uint8_t game_flags;              /* InitGameSection: *(byte*)(this+0x18)=0 */
    /* 0x019 */ uint8_t _pad_019;
    /* 0x01A */ uint8_t game_data[0x32C];        /* InitGameSection: memset(this+0x1A, 0, 0x32C) */
    /* 0x346 */ uint8_t mission_data[0x196];     /* InitGameSection: memset(this+0x346, 0, 0x196) */
    /* 0x4DC */ uint16_t field_4DC[20];          /* InitGameSection: loop zeroing uint16[20] */
    /* 0x504 */ uint8_t field_504[0x34];         /* InitGameSection: loop zeroing byte[20] + pad to 0x538 */
    /* 0x538 */ uint32_t main_flags[32];         /* IsMainFlagOn: bitfield[this+0x538+(id>>5)*4] */
    /* 0x5B8 */ uint8_t _pad_5B8[0x3E0];         /* gap to player_unlock_bits at 0x998 */
    /* 0x998 */ uint8_t player_unlock_bits[64];  /* IsPlayerUnlocked: byte[this+0x998+(id>>3)] */
    /* 0x9D8 */ uint8_t _pad_9D8[0x440];         /* gap to system settings at 0xE18 */
    /* 0xE18 */ uint32_t system_setting_1;       /* InitSystemSection: *(uint32*)(this+0xE18)=1 */
    /* 0xE1C */ uint32_t system_setting_2;       /* InitSystemSection: *(uint32*)(this+0xE1C)=0 */
    /* 0xE20 */ uint32_t system_setting_3;       /* InitSystemSection: *(uint32*)(this+0xE20)=0 */
    /* 0xE24 */ uint8_t _pad_E24[0xC];           /* gap to key_config at 0xE30 */
    /* 0xE30 */ uint32_t key_config[96];         /* GetButtonId: int[this+0xE30+(p3+p2*0x18)*4], 96 entries covers to 0xFB0 */
    /* 0xFB0 */ uint8_t _pad_FB0[0x68];          /* gap to money region */
    /* 0x1018 */ uint8_t _pad_1018[0x14];        /* gap to field_102C */
    /* 0x102C */ uint32_t field_102C;            /* InitGameSection: *(uint32*)(this+0x102C)=0 */
} ns1_ccSaveData;
_Static_assert(offsetof(ns1_ccSaveData, game_flags) == 0x018, "ccSaveData.game_flags");
_Static_assert(offsetof(ns1_ccSaveData, game_data) == 0x01A, "ccSaveData.game_data");
_Static_assert(offsetof(ns1_ccSaveData, mission_data) == 0x346, "ccSaveData.mission_data");
_Static_assert(offsetof(ns1_ccSaveData, field_4DC) == 0x4DC, "ccSaveData.field_4DC");
_Static_assert(offsetof(ns1_ccSaveData, field_504) == 0x504, "ccSaveData.field_504");
_Static_assert(offsetof(ns1_ccSaveData, main_flags) == 0x538, "ccSaveData.main_flags");
_Static_assert(offsetof(ns1_ccSaveData, player_unlock_bits) == 0x998, "ccSaveData.player_unlock_bits");
_Static_assert(offsetof(ns1_ccSaveData, system_setting_1) == 0xE18, "ccSaveData.system_setting_1");
_Static_assert(offsetof(ns1_ccSaveData, system_setting_2) == 0xE1C, "ccSaveData.system_setting_2");
_Static_assert(offsetof(ns1_ccSaveData, system_setting_3) == 0xE20, "ccSaveData.system_setting_3");
_Static_assert(offsetof(ns1_ccSaveData, key_config) == 0xE30, "ccSaveData.key_config");
_Static_assert(offsetof(ns1_ccSaveData, field_102C) == 0x102C, "ccSaveData.field_102C");

/* Offset-only accessors for ccSaveData fields not directly in struct
 * (money at 0xF1C falls within key_config[] padding region above) */
#define NS1_SAVEDATA_MONEY_OFF          0xF1C
#define NS1_SAVEDATA_MAIN_FLAGS_OFF     0x538
#define NS1_SAVEDATA_PLAYER_UNLOCK_OFF  0x998
#define NS1_SAVEDATA_SYSTEM_SET1_OFF    0xE18
#define NS1_SAVEDATA_SYSTEM_SET2_OFF    0xE1C
#define NS1_SAVEDATA_SYSTEM_SET3_OFF    0xE20
#define NS1_SAVEDATA_KEY_CONFIG_OFF     0xE30
#define NS1_SAVEDATA_FIELD_102C_OFF     0x102C
#define NS1_SAVEDATA_GAME_FLAGS_OFF     0x018
#define NS1_SAVEDATA_GAME_DATA_OFF      0x01A
#define NS1_SAVEDATA_MISSION_DATA_OFF   0x346

#endif /* CMN06_H */