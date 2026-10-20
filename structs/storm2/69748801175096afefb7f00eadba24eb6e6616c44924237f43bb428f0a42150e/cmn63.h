/* cmn63.h — NARUTO STORM 2 (s2) particle system struct layouts
 * INFERRED from x64 decompilation of NSUNS2.exe (image base 0x140000000).
 * NOT CONFIRMED by runtime trace. Sizes proven from FUN_140580190 allocator
 * calls in nuccParticleRootManager::EntryParticle where available;
 * otherwise "size unknown, >= 0x<N>".
 * All structs __attribute__((packed)) with explicit padding.
 */
#ifndef CMN63_S2_H
#define CMN63_S2_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nuccParticleNode
 * Base class for linked-list particle nodes. Inherits BlockAllocator pattern.
 * Vtable: PTR_FUN_14089a268 (from ctor at 0x611080)
 * Size: UNKNOWN — no heap allocator call found. Fields seen up to +0x38.
 * Last proven field at +0x38 -> size >= 0x40 (with alignment).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void *vtable;               /* PTR_FUN_14089a268 */
    /* +0x08 */ uint8_t _pad_08[0x10];      /* padding to +0x18 */
    /* +0x18 */ uint32_t flags;             /* SIM — node state flags (ctor writes param_1[3]) */
    /* +0x1C */ uint32_t id_or_type;        /* SIM — node identifier (ctor writes param_1[4]) */
    /* +0x20 */ uint8_t _pad_20[0x08];      /* padding to +0x28 */
    /* +0x28 */ struct nuccParticleNode_s2 *prev; /* SIM — doubly-linked list prev */
    /* +0x30 */ struct nuccParticleNode_s2 *next; /* SIM — doubly-linked list next */
    /* +0x38 */ uint64_t user_data;         /* UNKNOWN — seen in subclass ctors */
} nuccParticleNode_s2;
/* Size unknown, >= 0x40. No sizeof assert — unproven. */
_Static_assert(offsetof(nuccParticleNode_s2, vtable) == 0x00, "nuccParticleNode.vtable");
_Static_assert(offsetof(nuccParticleNode_s2, flags) == 0x18, "nuccParticleNode.flags");
_Static_assert(offsetof(nuccParticleNode_s2, id_or_type) == 0x1C, "nuccParticleNode.id_or_type");
_Static_assert(offsetof(nuccParticleNode_s2, prev) == 0x28, "nuccParticleNode.prev");
_Static_assert(offsetof(nuccParticleNode_s2, next) == 0x30, "nuccParticleNode.next");
_Static_assert(offsetof(nuccParticleNode_s2, user_data) == 0x38, "nuccParticleNode.user_data");

/* =========================================================================
 * nuccParticleGenParam
 * Parameter struct for particle generation. Only EndianConvert method found
 * in s2 (0x5F1B00). state_surface returned 0 fields — pure data struct
 * with no this-pointer accesses in analyzed methods.
 * Size: UNKNOWN — no allocator or sizeof evidence found.
 * Listed as present but unreconstructable from static analysis alone.
 * ========================================================================= */
/* No struct emitted — insufficient evidence for any field layout. */

/* =========================================================================
 * nuccParticleList
 * Container managing particle node pools with reuse/trash mechanism.
 * Vtable: not directly observed (virtual dispatch via +0xA8 in AddList)
 * Size: UNKNOWN — no heap allocator call found. Fields seen up to +0x140.
 * Last proven field at +0x140 -> size >= 0x148.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void *vtable;               /* inferred — virtual dispatch at +0xA8 */
    /* +0x08 */ uint8_t _pad_08[0x78];      /* padding to +0x80 */
    /* +0x80 */ void *release_func;         /* PRES — function pointer read in ReleaseNodeAll */
    /* +0x88 */ uint8_t _pad_88[0xB8];      /* padding to +0x140 */
    /* +0x140 */ int32_t count_or_flag;     /* SIM — checked != 1 in ReleaseNodeAll */
    /* +0x144 */ uint8_t _pad_144[0x04];    /* padding */
} nuccParticleList_s2;
/* Size unknown, >= 0x148. No sizeof assert — unproven. */
_Static_assert(offsetof(nuccParticleList_s2, vtable) == 0x00, "nuccParticleList.vtable");
_Static_assert(offsetof(nuccParticleList_s2, release_func) == 0x80, "nuccParticleList.release_func");
_Static_assert(offsetof(nuccParticleList_s2, count_or_flag) == 0x140, "nuccParticleList.count_or_flag");

/* =========================================================================
 * nuccParticleGenerator
 * Core particle emitter with timer/state/emission logic.
 * Vtable: PTR_FUN_1408987e8 (from ctor at 0x5FE230)
 * Size: 0x430 — PROVEN from FUN_140580190(0x430,...) in
 *   nuccParticleRootManager::EntryParticle (0x59DE30, line 0x217)
 * Embeds nuccParticleNodeList at +0x00 (base class).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* --- Embedded nuccParticleNodeList / nuccParticleNode base --- */
    /* +0x00 */ void *vtable;               /* PTR_FUN_1408987e8 */
    /* +0x08 */ uint8_t _pad_08[0xB0];      /* base class fields (NodeList) */

    /* --- nuccParticleGenerator own fields --- */
    /* +0xB8 */ int32_t emit_count;         /* SIM — param copy in ctor */
    /* +0xBC */ int32_t emit_count_copy;    /* SIM — mirrored in ctor */
    /* +0xC0 */ float emission_rate;        /* SIM — set in Ctrl */
    /* +0xC4 */ uint32_t timer_or_counter;  /* SIM — cleared in ctor and Ctrl */
    /* +0xC8 */ uint64_t resource_ptr;      /* PRES — checked != 0 in Ctrl */
    /* +0xD0 */ uint8_t _pad_d0[0x04];      /* padding */
    /* +0xD4 */ int32_t active_flag;        /* SIM — checked != 0 in Ctrl */
    /* +0xD8 */ uint64_t duration_or_lifetime; /* SIM — set in ctor */
    /* +0xE0 */ float speed_multiplier;     /* SIM — scaled in Ctrl */
    /* +0xE4 */ uint8_t _pad_e4[0x04];      /* padding */
    /* +0xE8 */ uint64_t pos_node_list;     /* PRES — checked != 0 in ctor/Ctrl */
    /* +0xF0 */ uint64_t force_field_list;  /* PRES — checked != 0 in ctor/Ctrl */
    /* +0xF8 */ void *core_func_table;      /* PRES — vfunc dispatch in dtor */
    /* +0x100 */ uint8_t _pad_100[0x40];    /* padding to +0x140 */
    /* +0x140 */ uint64_t spawn_params;     /* SIM — checked in Ctrl */
    /* +0x148 */ uint8_t _pad_148[0xF8];    /* padding to +0x240 */
    /* +0x240 */ uint64_t particle_core_cache; /* PRES — cleanup in dtor */
    /* +0x248 */ uint8_t _pad_248[0xA0];    /* padding to +0x2E8 */
    /* +0x2E8 */ uint64_t pos_list_cache;   /* PRES — cleanup in dtor */
    /* +0x2F0 */ uint8_t _pad_2f0[0x98];    /* padding to +0x388 */
    /* +0x388 */ uint64_t force_field_cache; /* PRES — cleanup in Ctrl */
    /* +0x390 */ uint8_t _pad_390[0x40];    /* padding to +0x3D0 */
    /* +0x3D0 */ uint64_t extra_resource;   /* PRES — checked in Ctrl */
    /* +0x3D8 */ uint8_t _pad_3d8[0x50];    /* padding to +0x428 */
    /* +0x428 */ uint64_t owner_or_parent;  /* UNKNOWN — set from param_3 in EntryParticle */
} nuccParticleGenerator_s2;
_Static_assert(sizeof(nuccParticleGenerator_s2) == 0x430, "nuccParticleGenerator size proven by LoadTh(0x430)");
_Static_assert(offsetof(nuccParticleGenerator_s2, vtable) == 0x000, "nuccParticleGenerator.vtable");
_Static_assert(offsetof(nuccParticleGenerator_s2, emit_count) == 0x0B8, "nuccParticleGenerator.emit_count");
_Static_assert(offsetof(nuccParticleGenerator_s2, emit_count_copy) == 0x0BC, "nuccParticleGenerator.emit_count_copy");
_Static_assert(offsetof(nuccParticleGenerator_s2, emission_rate) == 0x0C0, "nuccParticleGenerator.emission_rate");
_Static_assert(offsetof(nuccParticleGenerator_s2, timer_or_counter) == 0x0C4, "nuccParticleGenerator.timer_or_counter");
_Static_assert(offsetof(nuccParticleGenerator_s2, resource_ptr) == 0x0C8, "nuccParticleGenerator.resource_ptr");
_Static_assert(offsetof(nuccParticleGenerator_s2, active_flag) == 0x0D4, "nuccParticleGenerator.active_flag");
_Static_assert(offsetof(nuccParticleGenerator_s2, duration_or_lifetime) == 0x0D8, "nuccParticleGenerator.duration_or_lifetime");
_Static_assert(offsetof(nuccParticleGenerator_s2, speed_multiplier) == 0x0E0, "nuccParticleGenerator.speed_multiplier");
_Static_assert(offsetof(nuccParticleGenerator_s2, pos_node_list) == 0x0E8, "nuccParticleGenerator.pos_node_list");
_Static_assert(offsetof(nuccParticleGenerator_s2, force_field_list) == 0x0F0, "nuccParticleGenerator.force_field_list");
_Static_assert(offsetof(nuccParticleGenerator_s2, core_func_table) == 0x0F8, "nuccParticleGenerator.core_func_table");
_Static_assert(offsetof(nuccParticleGenerator_s2, spawn_params) == 0x140, "nuccParticleGenerator.spawn_params");
_Static_assert(offsetof(nuccParticleGenerator_s2, particle_core_cache) == 0x240, "nuccParticleGenerator.particle_core_cache");
_Static_assert(offsetof(nuccParticleGenerator_s2, pos_list_cache) == 0x2E8, "nuccParticleGenerator.pos_list_cache");
_Static_assert(offsetof(nuccParticleGenerator_s2, force_field_cache) == 0x388, "nuccParticleGenerator.force_field_cache");
_Static_assert(offsetof(nuccParticleGenerator_s2, extra_resource) == 0x3D0, "nuccParticleGenerator.extra_resource");
_Static_assert(offsetof(nuccParticleGenerator_s2, owner_or_parent) == 0x428, "nuccParticleGenerator.owner_or_parent");

/* =========================================================================
 * nuccParticleManager
 * Top-level manager embedding a Generator at +0xB0 and managing frame timing.
 * Vtable: PTR_FUN_140898910 (from ctor at 0x6004E0)
 * Size: 0x4F8 — PROVEN from FUN_140580190(0x4f8,...) in
 *   nuccParticleRootManager::EntryParticle (0x59DE30, line 0x20a)
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void *vtable;               /* PTR_FUN_140898910 */
    /* +0x08 */ uint8_t _pad_08[0x98];      /* base/padding to +0xA0 */
    /* +0xA0 */ int32_t init_flag;          /* SIM — set =1 in ctor */
    /* +0xA4 */ float default_scale;        /* PRES — 1.0f in ctor */
    /* +0xA8 */ uint8_t _pad_a8[0x08];      /* padding to +0xB0 */
    /* +0xB0 */ nuccParticleGenerator_s2 generator; /* EMBEDDED — ctor calls Generator(param_1+0x16) */
    /* NOTE: generator ends at 0xB0+0x430 = 0x4E0 */
    /* +0x4E0 */ float global_speed;        /* SIM — 1.0f in ctor */
    /* +0x4E4 */ uint8_t _pad_4e4[0x04];    /* padding */
    /* +0x4E8 */ int32_t frame_counter;     /* SIM — cleared in ctor */
    /* +0x4EC */ int32_t max_particles;     /* SIM — 0xffffffff in ctor */
    /* +0x4F0 */ int32_t active_generator_count; /* SIM — cleared in ctor */
    /* +0x4F4 */ int32_t enabled_flag;      /* SIM — 1 in ctor */
} nuccParticleManager_s2;
_Static_assert(sizeof(nuccParticleManager_s2) == 0x4F8, "nuccParticleManager size proven by LoadTh(0x4f8)");
_Static_assert(offsetof(nuccParticleManager_s2, vtable) == 0x000, "nuccParticleManager.vtable");
_Static_assert(offsetof(nuccParticleManager_s2, init_flag) == 0x0A0, "nuccParticleManager.init_flag");
_Static_assert(offsetof(nuccParticleManager_s2, default_scale) == 0x0A4, "nuccParticleManager.default_scale");
_Static_assert(offsetof(nuccParticleManager_s2, generator) == 0x0B0, "nuccParticleManager.generator");
_Static_assert(offsetof(nuccParticleManager_s2, global_speed) == 0x4E0, "nuccParticleManager.global_speed");
_Static_assert(offsetof(nuccParticleManager_s2, frame_counter) == 0x4E8, "nuccParticleManager.frame_counter");
_Static_assert(offsetof(nuccParticleManager_s2, max_particles) == 0x4EC, "nuccParticleManager.max_particles");
_Static_assert(offsetof(nuccParticleManager_s2, active_generator_count) == 0x4F0, "nuccParticleManager.active_generator_count");
_Static_assert(offsetof(nuccParticleManager_s2, enabled_flag) == 0x4F4, "nuccParticleManager.enabled_flag");

#endif /* CMN63_S2_H */