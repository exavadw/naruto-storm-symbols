/* cmn63.h — NARUTO STORM 4 PC 1.09 (s4) particle system struct layouts
 * INFERRED from x64 decompilation of NSUNS4_release.exe (image base 0x140000000).
 * NOT CONFIRMED by runtime trace. Sizes proven from FUN_140a017f0 allocator
 * calls in FUN_140a06050 where available; otherwise "size unknown, >= 0x<N>".
 * All structs __attribute__((packed)) with explicit padding.
 */
#ifndef CMN63_S4_H
#define CMN63_S4_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nuccParticleNode
 * Base class for linked-list particle nodes. Inherits BlockAllocator pattern.
 * Vtable: PTR_FUN_141112188 set in ctor (0xA9F0D0).
 * Size: UNKNOWN — no heap allocator call found. Fields seen up to +0x38
 * from manual decompile of ctor/AddNode/DelNode.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* +0x00 */ void *vtable;           /* vtable = PTR_FUN_141112188 in ctor */
/* +0x08 */ uint8_t _pad_08[0x10];  /* padding to +0x18 */
/* +0x18 */ uint32_t flags;         /* SIM — node state flags, cleared in ctor */
/* +0x1C */ uint32_t id_or_type;    /* SIM — node identifier, cleared in ctor */
/* +0x20 */ uint8_t _pad_20[0x08];  /* padding to +0x28 */
/* +0x28 */ struct nuccParticleNode_s4 *prev; /* SIM — doubly-linked list prev */
/* +0x30 */ struct nuccParticleNode_s4 *next; /* SIM — doubly-linked list next */
/* +0x38 */ uint64_t user_data;     /* UNKNOWN — cleared in ctor */
} nuccParticleNode_s4;
/* Size unknown, >= 0x40. No sizeof assert — unproven. */
_Static_assert(offsetof(nuccParticleNode_s4, vtable) == 0x00, "nuccParticleNode.vtable");
_Static_assert(offsetof(nuccParticleNode_s4, flags) == 0x18, "nuccParticleNode.flags");
_Static_assert(offsetof(nuccParticleNode_s4, id_or_type) == 0x1C, "nuccParticleNode.id_or_type");
_Static_assert(offsetof(nuccParticleNode_s4, prev) == 0x28, "nuccParticleNode.prev");
_Static_assert(offsetof(nuccParticleNode_s4, next) == 0x30, "nuccParticleNode.next");
_Static_assert(offsetof(nuccParticleNode_s4, user_data) == 0x38, "nuccParticleNode.user_data");

/* =========================================================================
 * nuccParticleGenParam
 * Parameter struct for particle generation. Only EndianConvert method found
 * in s4. state_surface returned 0 fields — pure data struct with no
 * this-pointer accesses in analyzed methods.
 * Size: UNKNOWN — no allocator or sizeof evidence found.
 * Listed as present but unreconstructable from static analysis alone.
 * ========================================================================= */
/* No struct emitted — insufficient evidence for any field layout. */

/* =========================================================================
 * nuccParticleList
 * Container managing particle node pools with reuse/trash mechanism.
 * Vtable: inferred from virtual dispatch patterns.
 * Size: UNKNOWN — no heap allocator call found. Fields seen up to +0x540.
 * Last proven field at +0x540 -> size >= 0x548.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* +0x00 */ void *vtable;           /* inferred — virtual dispatch */
/* +0x08 */ uint8_t _pad_08[0x78];  /* padding to +0x80 */
/* +0x80 */ void *release_func;     /* PRES — function pointer read in ReleaseNodeAll */
/* +0x88 */ uint8_t _pad_88[0xB8];  /* padding to +0x140 */
/* +0x140 */ int32_t count_or_flag; /* SIM — checked != 1 in ReleaseNodeAll */
/* +0x144 */ uint8_t _pad_144[0x3FC]; /* padding to +0x540 */
/* +0x540 */ int32_t field_540;     /* UNKNOWN — accessed in AddList */
/* +0x544 */ uint8_t _pad_544[0x04]; /* padding */
} nuccParticleList_s4;
/* Size unknown, >= 0x548. No sizeof assert — unproven. */
_Static_assert(offsetof(nuccParticleList_s4, vtable) == 0x00, "nuccParticleList.vtable");
_Static_assert(offsetof(nuccParticleList_s4, release_func) == 0x80, "nuccParticleList.release_func");
_Static_assert(offsetof(nuccParticleList_s4, count_or_flag) == 0x140, "nuccParticleList.count_or_flag");
_Static_assert(offsetof(nuccParticleList_s4, field_540) == 0x540, "nuccParticleList.field_540");

/* =========================================================================
 * nuccParticleGenerator
 * Core particle emitter with timer/state/emission logic.
 * Vtable: not directly named in s4 state_surface (byte-cast warnings).
 * Size: 0x430 — PROVEN from FUN_140a017f0(0x430,...) in FUN_140a06050 (s4).
 * Embeds nuccParticleNodeList at +0x00 (base class).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* --- Embedded nuccParticleNodeList / nuccParticleNode base --- */
/* +0x00 */ void *vtable;
/* +0x08 */ uint8_t _pad_08[0x98];  /* base class fields (NodeList) to +0xA0 */

/* --- nuccParticleGenerator own fields --- */
/* +0xA0 */ uint64_t init_ptr;      /* PRES — set =0 in ctor */
/* +0xA8 */ uint32_t field_a8;      /* UNKNOWN — rw, mixed 4/8 access */
/* +0xAC */ uint32_t active_flag_ctrl; /* SIM — set =1 in Ctrl */
/* +0xB0 */ uint32_t field_b0;      /* SIM — set from param in ctor */
/* +0xB4 */ uint32_t field_b4;      /* SIM — set =0xffffffff in ctor */
/* +0xB8 */ int32_t emit_count;     /* SIM — param copy in ctor, read in Ctrl */
/* +0xBC */ int32_t emit_count_copy;/* SIM — mirrored from param_1[0x17] */
/* +0xC0 */ uint32_t timer_or_counter; /* SIM — cleared in Ctrl */
/* +0xC4 */ uint32_t field_c4;      /* UNKNOWN — rw, mixed 4/8 access */
/* +0xC8 */ uint64_t resource_ptr;  /* PRES — checked != 0 in Ctrl */
/* +0xD0 */ uint8_t _pad_d0[0x04];  /* padding */
/* +0xD4 */ int32_t duration_flag;  /* SIM — checked != 0 in Ctrl/ctor */
/* +0xD8 */ uint64_t duration_or_lifetime; /* SIM — set =1 in ctor */
/* +0xE0 */ float speed_multiplier; /* SIM — scaled in Ctrl */
/* +0xE4 */ uint8_t _pad_e4[0x04];  /* padding */
/* +0xE8 */ uint64_t pos_node_list; /* PRES — checked != 0 in ctor/Ctrl */
/* +0xF0 */ uint64_t force_field_list; /* PRES — checked != 0 in ctor/Ctrl */
/* +0xF8 */ void *core_func_table;  /* PRES — vfunc dispatch in dtor/Ctrl */
/* +0x100 */ uint8_t _pad_100[0x40]; /* padding to +0x140 */
/* +0x140 */ uint64_t spawn_params; /* SIM — checked in Ctrl */
/* +0x148 */ uint8_t _pad_148[0xF8]; /* padding to +0x240 */
/* +0x240 */ uint64_t particle_core_cache; /* PRES — cleanup in dtor/Ctrl */
/* +0x248 */ uint8_t _pad_248[0x38]; /* padding to +0x280 */
/* +0x280 */ uint64_t vfunc_dispatch_ptr; /* PRES — virtual call site */
/* +0x288 */ uint8_t _pad_288[0x60]; /* padding to +0x2E8 */
/* +0x2E8 */ uint64_t pos_list_cache; /* PRES — cleanup in dtor/ctor */
/* +0x2F0 */ uint8_t _pad_2f0[0x98]; /* padding to +0x388 */
/* +0x388 */ uint64_t force_field_cache; /* PRES — cleanup in Ctrl */
/* +0x390 */ uint8_t _pad_390[0x40]; /* padding to +0x3D0 */
/* +0x3D0 */ uint64_t extra_resource; /* PRES — checked in Ctrl */
/* +0x3D8 */ uint8_t _pad_3d8[0x50]; /* padding to +0x428 */
/* +0x428 */ uint64_t owner_or_parent; /* UNKNOWN — set from param_3 in EntryParticle */
} nuccParticleGenerator_s4;
_Static_assert(sizeof(nuccParticleGenerator_s4) == 0x430, "nuccParticleGenerator size proven by FUN_140a06050(0x430)");
_Static_assert(offsetof(nuccParticleGenerator_s4, vtable) == 0x000, "nuccParticleGenerator.vtable");
_Static_assert(offsetof(nuccParticleGenerator_s4, init_ptr) == 0x0A0, "nuccParticleGenerator.init_ptr");
_Static_assert(offsetof(nuccParticleGenerator_s4, field_a8) == 0x0A8, "nuccParticleGenerator.field_a8");
_Static_assert(offsetof(nuccParticleGenerator_s4, active_flag_ctrl) == 0x0AC, "nuccParticleGenerator.active_flag_ctrl");
_Static_assert(offsetof(nuccParticleGenerator_s4, field_b0) == 0x0B0, "nuccParticleGenerator.field_b0");
_Static_assert(offsetof(nuccParticleGenerator_s4, field_b4) == 0x0B4, "nuccParticleGenerator.field_b4");
_Static_assert(offsetof(nuccParticleGenerator_s4, emit_count) == 0x0B8, "nuccParticleGenerator.emit_count");
_Static_assert(offsetof(nuccParticleGenerator_s4, emit_count_copy) == 0x0BC, "nuccParticleGenerator.emit_count_copy");
_Static_assert(offsetof(nuccParticleGenerator_s4, timer_or_counter) == 0x0C0, "nuccParticleGenerator.timer_or_counter");
_Static_assert(offsetof(nuccParticleGenerator_s4, field_c4) == 0x0C4, "nuccParticleGenerator.field_c4");
_Static_assert(offsetof(nuccParticleGenerator_s4, resource_ptr) == 0x0C8, "nuccParticleGenerator.resource_ptr");
_Static_assert(offsetof(nuccParticleGenerator_s4, duration_flag) == 0x0D4, "nuccParticleGenerator.duration_flag");
_Static_assert(offsetof(nuccParticleGenerator_s4, duration_or_lifetime) == 0x0D8, "nuccParticleGenerator.duration_or_lifetime");
_Static_assert(offsetof(nuccParticleGenerator_s4, speed_multiplier) == 0x0E0, "nuccParticleGenerator.speed_multiplier");
_Static_assert(offsetof(nuccParticleGenerator_s4, pos_node_list) == 0x0E8, "nuccParticleGenerator.pos_node_list");
_Static_assert(offsetof(nuccParticleGenerator_s4, force_field_list) == 0x0F0, "nuccParticleGenerator.force_field_list");
_Static_assert(offsetof(nuccParticleGenerator_s4, core_func_table) == 0x0F8, "nuccParticleGenerator.core_func_table");
_Static_assert(offsetof(nuccParticleGenerator_s4, spawn_params) == 0x140, "nuccParticleGenerator.spawn_params");
_Static_assert(offsetof(nuccParticleGenerator_s4, particle_core_cache) == 0x240, "nuccParticleGenerator.particle_core_cache");
_Static_assert(offsetof(nuccParticleGenerator_s4, vfunc_dispatch_ptr) == 0x280, "nuccParticleGenerator.vfunc_dispatch_ptr");
_Static_assert(offsetof(nuccParticleGenerator_s4, pos_list_cache) == 0x2E8, "nuccParticleGenerator.pos_list_cache");
_Static_assert(offsetof(nuccParticleGenerator_s4, force_field_cache) == 0x388, "nuccParticleGenerator.force_field_cache");
_Static_assert(offsetof(nuccParticleGenerator_s4, extra_resource) == 0x3D0, "nuccParticleGenerator.extra_resource");
_Static_assert(offsetof(nuccParticleGenerator_s4, owner_or_parent) == 0x428, "nuccParticleGenerator.owner_or_parent");

/* =========================================================================
 * nuccParticleManager
 * Top-level manager embedding a Generator at +0xB0 and managing frame timing.
 * Vtable: not directly named in s4 state_surface (byte-cast warnings).
 * Size: 0x4F8 — PROVEN from FUN_140a017f0(0x4f8,...) in FUN_140a06050 (s4).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
/* +0x00 */ void *vtable;
/* +0x08 */ uint8_t _pad_08[0x98];  /* base/padding to +0xA0 */
/* +0xA0 */ int32_t init_flag;      /* SIM — set =1 in ctor */
/* +0xA4 */ float default_scale;    /* PRES — 1.0f (0x3f800000) in ctor */
/* +0xA8 */ uint8_t _pad_a8[0x08];  /* padding to +0xB0 */
/* +0xB0 */ nuccParticleGenerator_s4 generator; /* EMBEDDED — ctor calls Generator(param_1+0xB0) */
/* NOTE: generator ends at 0xB0+0x430 = 0x4E0 */
/* +0x4E0 */ float global_speed;   /* SIM — 1.0f (0x3f800000) in ctor */
/* +0x4E4 */ uint8_t _pad_4e4[0x04]; /* padding */
/* +0x4E8 */ int32_t frame_counter; /* SIM — cleared in ctor */
/* +0x4EC */ int32_t max_particles; /* SIM — 0xffffffff in ctor */
/* +0x4F0 */ int32_t active_generator_count; /* SIM — cleared in ctor */
/* +0x4F4 */ int32_t enabled_flag;  /* SIM — 1 in ctor */
} nuccParticleManager_s4;
_Static_assert(sizeof(nuccParticleManager_s4) == 0x4F8, "nuccParticleManager size proven by FUN_140a06050(0x4f8)");
_Static_assert(offsetof(nuccParticleManager_s4, vtable) == 0x000, "nuccParticleManager.vtable");
_Static_assert(offsetof(nuccParticleManager_s4, init_flag) == 0x0A0, "nuccParticleManager.init_flag");
_Static_assert(offsetof(nuccParticleManager_s4, default_scale) == 0x0A4, "nuccParticleManager.default_scale");
_Static_assert(offsetof(nuccParticleManager_s4, generator) == 0x0B0, "nuccParticleManager.generator");
_Static_assert(offsetof(nuccParticleManager_s4, global_speed) == 0x4E0, "nuccParticleManager.global_speed");
_Static_assert(offsetof(nuccParticleManager_s4, frame_counter) == 0x4E8, "nuccParticleManager.frame_counter");
_Static_assert(offsetof(nuccParticleManager_s4, max_particles) == 0x4EC, "nuccParticleManager.max_particles");
_Static_assert(offsetof(nuccParticleManager_s4, active_generator_count) == 0x4F0, "nuccParticleManager.active_generator_count");
_Static_assert(offsetof(nuccParticleManager_s4, enabled_flag) == 0x4F4, "nuccParticleManager.enabled_flag");

#endif /* CMN63_S4_H */