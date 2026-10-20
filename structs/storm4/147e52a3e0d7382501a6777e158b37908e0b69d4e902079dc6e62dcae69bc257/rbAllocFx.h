#pragma once
/* rbAllocFx s4 — Nucc::Memory::BlockAllocator, nuccEffectManager, nuccParticleRootManager
 * Build: s4 (NSUNS4_release.exe, PC x64, image base 0x140000000)
 * All layouts INFERRED from Ghidra state_surface + decompilation; not CONFIRMED.
 * Object sizes are lower bounds only — no sizeof asserts.
 * Generated 2026-10-19.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Memory::BlockAllocator (s4)
 * Size: unknown, >= 0x2A8 (last proven field copy_sub_0x2A0 + 8 bytes)
 * Vtable/dispatch sites: 0x80 (vtable ptr from ctor param_1[4]=&PTR_FUN_1410075d8)
 * Fields: 78 from state_surface (20 seeds), all real (<0x1000)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x00[0x10]; /* 0x00 */
    uint32_t field_0x10; /* 0x10 - w, high conf, BlockAllocator ctor (ambiguous [4,8], u32 fits next) */
    uint32_t field_0x14; /* 0x14 - rw, low conf, ambiguous [4,8] */
    uint8_t _pad_0x18[0x4]; /* 0x18 */
    uint32_t field_0x1C; /* 0x1C - w, medium, ~BlockAllocator */
    uint64_t field_0x20; /* 0x20 - rw, low, FUN_140a01cc0 init */
    uint8_t _pad_0x28[0x4]; /* 0x28 */
    uint32_t field_0x2C; /* 0x2C - w, medium, ~BlockAllocator (ambiguous [4,8], u32 fits next) */
    uint8_t _pad_0x30[0x4]; /* 0x30 */
    uint32_t field_0x34; /* 0x34 - w, medium, ~BlockAllocator */
    uint8_t _pad_0x38[0xC]; /* 0x38 */
    uint32_t field_0x44; /* 0x44 - w, medium, ~BlockAllocator */
    uint8_t _pad_0x48[0xC]; /* 0x48 */
    uint32_t field_0x54; /* 0x54 - w, low, ambiguous [4,8], u32 fits next */
    uint32_t field_0x58; /* 0x58 - w, medium */
    uint32_t field_0x5C; /* 0x5C - w, high */
    uint32_t field_0x60; /* 0x60 - rw, low */
    uint8_t _pad_0x64[0x4]; /* 0x64 */
    uint64_t field_0x68; /* 0x68 - w, medium */
    uint64_t field_0x70; /* 0x70 - w, medium */
    uint64_t field_0x78; /* 0x78 - w, medium */
    uint64_t vtable_ptr_0x80; /* 0x80 - rw, vtable dispatch + ctor sets PTR_FUN_1410075d8 */
    uint64_t field_0x88; /* 0x88 - w, medium */
    uint64_t field_0x90; /* 0x90 - w, medium */
    uint64_t field_0x98; /* 0x98 - w, medium */
    uint64_t field_0xA0; /* 0xA0 - w, medium */
    uint64_t field_0xA8; /* 0xA8 - w, medium */
    uint64_t field_0xB0; /* 0xB0 - w, medium */
    uint64_t field_0xB8; /* 0xB8 - w, medium */
    uint64_t field_0xC0; /* 0xC0 - w, medium */
    uint64_t field_0xC8; /* 0xC8 - w, medium */
    uint64_t field_0xD0; /* 0xD0 - w, medium */
    uint64_t field_0xD8; /* 0xD8 - w, medium */
    uint64_t field_0xE0; /* 0xE0 - w, medium */
    uint64_t field_0xE8; /* 0xE8 - w, medium */
    uint64_t field_0xF0; /* 0xF0 - w, medium */
    uint64_t field_0xF8; /* 0xF8 - w, medium */
    uint64_t field_0x100; /* 0x100 - w, medium */
    uint64_t field_0x108; /* 0x108 - w, medium */
    uint64_t field_0x110; /* 0x110 - w, medium */
    uint64_t field_0x118; /* 0x118 - w, medium */
    uint64_t field_0x120; /* 0x120 - r, low */
    uint64_t field_0x128; /* 0x128 - w, medium */
    uint64_t field_0x130; /* 0x130 - rw, medium */
    uint64_t field_0x138; /* 0x138 - rw, low, FUN_140a01cc0 */
    uint8_t _pad_0x140[0x10]; /* 0x140 */
    uint64_t field_0x150; /* 0x150 - w, medium */
    uint64_t field_0x158; /* 0x158 - w, medium */
    uint64_t field_0x160; /* 0x160 - w, medium */
    uint64_t field_0x168; /* 0x168 - rw, low, FUN_140a01cc0 */
    uint8_t _pad_0x170[0x10]; /* 0x170 */
    uint64_t field_0x180; /* 0x180 - r, low */
    uint64_t field_0x188; /* 0x188 - w, medium */
    uint64_t field_0x190; /* 0x190 - rw, medium */
    uint64_t field_0x198; /* 0x198 - rw, low, FUN_140a01cc0 */
    uint8_t _pad_0x1A0[0x10]; /* 0x1A0 */
    uint64_t field_0x1B0; /* 0x1B0 - r, low, FUN_140560148 */
    uint8_t _pad_0x1B8[0x28]; /* 0x1B8 */
    uint32_t field_0x1E0; /* 0x1E0 - w, medium, copy from param_2+0x1E0 */
    uint8_t _pad_0x1E4[0xC]; /* 0x1E4 */
    uint64_t field_0x1F0; /* 0x1F0 - w, high */
    uint64_t field_0x1F8; /* 0x1F8 - rw, high */
    uint64_t field_0x200; /* 0x200 - rw, low, FUN_140a01cc0 */
    uint64_t field_0x208; /* 0x208 - w, medium */
    uint64_t vtable_or_func_0x210; /* 0x210 - w, medium, &PTR_FUN_1411046e8 */
    uint32_t field_0x218; /* 0x218 - rw, low */
    uint32_t field_0x21C; /* 0x21C - w, medium, copy from param_2+0x21C */
    uint64_t field_0x220; /* 0x220 - w, high */
    uint64_t field_0x228; /* 0x228 - rw, medium */
    uint64_t field_0x230; /* 0x230 - rw, low, FUN_140a01cc0 */
    uint64_t field_0x238; /* 0x238 - w, medium */
    uint64_t field_0x240; /* 0x240 - w, medium, copy from param_2+0x240 */
    uint32_t field_0x248; /* 0x248 - w, low, ambiguous [4,8] */
    uint8_t _pad_0x24C[0x4]; /* 0x24C */
    uint64_t field_0x250; /* 0x250 - w, medium, copy from param_2+0x250 */
    uint32_t field_0x258; /* 0x258 - w, high */
    uint32_t field_0x25C; /* 0x25C - w, high, =0xFFFFFFFF */
    uint64_t field_0x260; /* 0x260 - w, high */
    uint64_t field_0x268; /* 0x268 - w, high */
    uint64_t field_0x270; /* 0x270 - w, high */
    uint64_t field_0x278; /* 0x278 - w, high */
    uint32_t field_0x280; /* 0x280 - w, low, ambiguous [4,8] */
    uint8_t _pad_0x284[0x4]; /* 0x284 */
    uint64_t field_0x288; /* 0x288 - w, medium */
    uint8_t field_0x290; /* 0x290 - w, medium, byte copy from param_2+0x290 */
    uint8_t _pad_0x291[0x3]; /* 0x291 */
    uint32_t field_0x294; /* 0x294 - w, medium, copy from param_2+0x294 */
    uint32_t field_0x298; /* 0x298 - w, medium, copy from param_2+0x298 */
    uint32_t field_0x29C; /* 0x29C - w, medium, copy from param_2+0x29C */
    uint8_t copy_sub_0x2A0[8]; /* 0x2A0 - subobject, FUN_140a30aa0 copy */
} Nucc_Memory_BlockAllocator_s4;

static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x10) == 0x10, "field_0x10");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x14) == 0x14, "field_0x14");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x1C) == 0x1C, "field_0x1C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x20) == 0x20, "field_0x20");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x2C) == 0x2C, "field_0x2C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x34) == 0x34, "field_0x34");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x44) == 0x44, "field_0x44");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x54) == 0x54, "field_0x54");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x58) == 0x58, "field_0x58");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x5C) == 0x5C, "field_0x5C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x60) == 0x60, "field_0x60");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x68) == 0x68, "field_0x68");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x70) == 0x70, "field_0x70");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x78) == 0x78, "field_0x78");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, vtable_ptr_0x80) == 0x80, "vtable_ptr_0x80");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x88) == 0x88, "field_0x88");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x90) == 0x90, "field_0x90");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x98) == 0x98, "field_0x98");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xA0) == 0xA0, "field_0xA0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xA8) == 0xA8, "field_0xA8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xB0) == 0xB0, "field_0xB0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xB8) == 0xB8, "field_0xB8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xC0) == 0xC0, "field_0xC0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xC8) == 0xC8, "field_0xC8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xD0) == 0xD0, "field_0xD0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xD8) == 0xD8, "field_0xD8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xE0) == 0xE0, "field_0xE0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xE8) == 0xE8, "field_0xE8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xF0) == 0xF0, "field_0xF0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0xF8) == 0xF8, "field_0xF8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x100) == 0x100, "field_0x100");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x108) == 0x108, "field_0x108");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x110) == 0x110, "field_0x110");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x118) == 0x118, "field_0x118");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x120) == 0x120, "field_0x120");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x128) == 0x128, "field_0x128");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x130) == 0x130, "field_0x130");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x138) == 0x138, "field_0x138");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x150) == 0x150, "field_0x150");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x158) == 0x158, "field_0x158");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x160) == 0x160, "field_0x160");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x168) == 0x168, "field_0x168");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x180) == 0x180, "field_0x180");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x188) == 0x188, "field_0x188");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x190) == 0x190, "field_0x190");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x198) == 0x198, "field_0x198");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x1B0) == 0x1B0, "field_0x1B0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x1E0) == 0x1E0, "field_0x1E0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x1F0) == 0x1F0, "field_0x1F0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x1F8) == 0x1F8, "field_0x1F8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x200) == 0x200, "field_0x200");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x208) == 0x208, "field_0x208");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, vtable_or_func_0x210) == 0x210, "vtable_or_func_0x210");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x218) == 0x218, "field_0x218");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x21C) == 0x21C, "field_0x21C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x220) == 0x220, "field_0x220");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x228) == 0x228, "field_0x228");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x230) == 0x230, "field_0x230");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x238) == 0x238, "field_0x238");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x240) == 0x240, "field_0x240");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x248) == 0x248, "field_0x248");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x250) == 0x250, "field_0x250");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x258) == 0x258, "field_0x258");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x25C) == 0x25C, "field_0x25C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x260) == 0x260, "field_0x260");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x268) == 0x268, "field_0x268");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x270) == 0x270, "field_0x270");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x278) == 0x278, "field_0x278");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x280) == 0x280, "field_0x280");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x288) == 0x288, "field_0x288");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x290) == 0x290, "field_0x290");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x294) == 0x294, "field_0x294");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x298) == 0x298, "field_0x298");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, field_0x29C) == 0x29C, "field_0x29C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s4, copy_sub_0x2A0) == 0x2A0, "copy_sub_0x2A0");

/* ========================================================================
 * nuccEffectManager (s4)
 * Size: unknown, >= 0xC0 (last proven field 0xBC + 4 bytes)
 * Init allocates 0x3200-byte internal buffer at param_1[0xf] (offset 0x78)
 * Vtable/dispatch site: 0x80 (8 functions call *param_1+0x10)
 * Fields: 7 real (<0x1000), 3 suspicious array-index offsets excluded
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x00[0x68]; /* 0x00 */
    uint64_t effect_list_ptr; /* 0x68 - rw, high, EntryEffect/Init */
    uint32_t effect_count; /* 0x70 - rw, high, EntryEffect/Init/ReleaseInfo */
    uint32_t max_effects; /* 0x74 - w, medium, Init sets =100 */
    uint64_t active_flag; /* 0x78 - rw, high, 7 functions access */
    uint64_t vtable_dispatch_0x80; /* 0x80 - r, vtable call (*param_1+0x10) */
    uint8_t _pad_0x88[0x2C]; /* 0x88 */
    uint64_t field_0xB4; /* 0xB4 - r, medium, ReleaseInfo */
    uint32_t field_0xBC; /* 0xBC - r, medium, ReleaseInfo */
} nuccEffectManager_s4;

static_assert(offsetof(nuccEffectManager_s4, effect_list_ptr) == 0x68, "effect_list_ptr");
static_assert(offsetof(nuccEffectManager_s4, effect_count) == 0x70, "effect_count");
static_assert(offsetof(nuccEffectManager_s4, max_effects) == 0x74, "max_effects");
static_assert(offsetof(nuccEffectManager_s4, active_flag) == 0x78, "active_flag");
static_assert(offsetof(nuccEffectManager_s4, vtable_dispatch_0x80) == 0x80, "vtable_dispatch_0x80");
static_assert(offsetof(nuccEffectManager_s4, field_0xB4) == 0xB4, "field_0xB4");
static_assert(offsetof(nuccEffectManager_s4, field_0xBC) == 0xBC, "field_0xBC");

/* ========================================================================
 * nuccParticleRootManager (s4)
 * Size: unknown, >= 0x670 (last proven field 0x668 + 8 bytes)
 * Init allocates sub-buffers: 0x20@0x118, 0x20@0x120, 0x20@0x128,
 *   dynamic 0x10*count@0x130, dynamic 0xA0*count@0x138
 * Vtable/dispatch sites: 0x80 (base), 0x200 (ReleaseManagerAll),
 *   0x440 (Ctrl_), 0x540 (EntryParticle), 0x5C0 (Exit)
 * Fields: 26 real (<0x1000), 1 suspicious (0x1D318) excluded
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x00[0x68]; /* 0x00 */
    uint64_t lock_draw_ptr; /* 0x68 - rw, medium, LockDraw */
    uint8_t _pad_0x70[0x10]; /* 0x70 */
    uint64_t vtable_base_0x80; /* 0x80 - r, vtable call (*param_1+0x10), 12 functions */
    uint8_t _pad_0x88[0x18]; /* 0x88 */
    uint64_t draw_mgr_sub_0xA0; /* 0xA0 - r, low, DrawManagerAnotherThread passes param_1+0x14 */
    uint8_t _pad_0xA8[0x48]; /* 0xA8 */
    uint32_t field_0xF0; /* 0xF0 - w, medium, ctor sets =0x20 */
    uint32_t particle_count; /* 0xF4 - rw, high, EntryParticle/Init check !=1 */
    uint64_t float_1_0; /* 0xF8 - w, medium, Init sets =0x3f800000 (1.0f as u32 in u64 slot) */
    uint32_t manager_state; /* 0x100 - rw, low, ambiguous [4,8], ReleaseManager/ctor */
    uint32_t ctrl_flag; /* 0x104 - w, medium, Ctrl sets =1 */
    uint32_t entry_flag; /* 0x108 - rw, high, EntryParticle/ctor */
    uint64_t init_counter; /* 0x10C - w, medium, ctor sets =1 (u64 per state_surface) */
    uint8_t byte_field_0x114; /* 0x114 - w, high, EntryParticle/ctor set =0 */
    uint8_t _pad_0x115[0x3]; /* 0x115 */
    uint64_t ff_cache_world; /* 0x118 - rw, high, Exit/Init/ReleaseForceFieldCache */
    uint64_t ff_cache_anime; /* 0x120 - rw, high, EntryAnimeFFCache/Exit/Init */
    uint64_t ff_cache_generator; /* 0x128 - rw, high, EntryGeneratorFFCache/Exit/Init */
    uint64_t ff_cache_0x130; /* 0x130 - rw, high, Exit/Init (dynamic array ptr) */
    uint64_t ff_cache_0x138; /* 0x138 - rw, high, Exit/Init (dynamic array ptr) */
    uint32_t array_count_0x140; /* 0x140 - rw, high, Exit/Init sets =0x80 (u32 fits next field) */
    uint32_t field_0x144; /* 0x144 - w, medium, Init sets =0 */
    uint8_t _pad_0x148[0x10]; /* 0x148 */
    uint64_t field_0x158; /* 0x158 - w, medium, ctor */
    uint32_t field_0x160; /* 0x160 - w, medium, ctor */
    uint32_t field_0x164; /* 0x164 - w, medium, ctor */
    uint8_t _pad_0x168[0x98]; /* 0x168 */
    uint64_t vfunc_dispatch_0x200; /* 0x200 - r, low, ReleaseManagerAll (*param_1+0x40) */
    uint8_t _pad_0x208[0x238]; /* 0x208 */
    uint64_t vfunc_dispatch_0x440; /* 0x440 - r, low, Ctrl_ (*param_1+0x88) */
    uint8_t _pad_0x448[0xF8]; /* 0x448 */
    uint64_t vfunc_dispatch_0x540; /* 0x540 - r, low, EntryParticle (*param_1+0xa8) */
    uint8_t _pad_0x548[0x78]; /* 0x548 */
    uint64_t vfunc_dispatch_0x5C0; /* 0x5C0 - r, low, Exit (*param_1+0xb8) */
    uint8_t _pad_0x5C8[0xA0]; /* 0x5C8 */
    uint64_t field_0x668; /* 0x668 - r, medium, Ctrl_ checks ==0 */
} nuccParticleRootManager_s4;

static_assert(offsetof(nuccParticleRootManager_s4, lock_draw_ptr) == 0x68, "lock_draw_ptr");
static_assert(offsetof(nuccParticleRootManager_s4, vtable_base_0x80) == 0x80, "vtable_base_0x80");
static_assert(offsetof(nuccParticleRootManager_s4, draw_mgr_sub_0xA0) == 0xA0, "draw_mgr_sub_0xA0");
static_assert(offsetof(nuccParticleRootManager_s4, field_0xF0) == 0xF0, "field_0xF0");
static_assert(offsetof(nuccParticleRootManager_s4, particle_count) == 0xF4, "particle_count");
static_assert(offsetof(nuccParticleRootManager_s4, float_1_0) == 0xF8, "float_1_0");
static_assert(offsetof(nuccParticleRootManager_s4, manager_state) == 0x100, "manager_state");
static_assert(offsetof(nuccParticleRootManager_s4, ctrl_flag) == 0x104, "ctrl_flag");
static_assert(offsetof(nuccParticleRootManager_s4, entry_flag) == 0x108, "entry_flag");
static_assert(offsetof(nuccParticleRootManager_s4, init_counter) == 0x10C, "init_counter");
static_assert(offsetof(nuccParticleRootManager_s4, byte_field_0x114) == 0x114, "byte_field_0x114");
static_assert(offsetof(nuccParticleRootManager_s4, ff_cache_world) == 0x118, "ff_cache_world");
static_assert(offsetof(nuccParticleRootManager_s4, ff_cache_anime) == 0x120, "ff_cache_anime");
static_assert(offsetof(nuccParticleRootManager_s4, ff_cache_generator) == 0x128, "ff_cache_generator");
static_assert(offsetof(nuccParticleRootManager_s4, ff_cache_0x130) == 0x130, "ff_cache_0x130");
static_assert(offsetof(nuccParticleRootManager_s4, ff_cache_0x138) == 0x138, "ff_cache_0x138");
static_assert(offsetof(nuccParticleRootManager_s4, array_count_0x140) == 0x140, "array_count_0x140");
static_assert(offsetof(nuccParticleRootManager_s4, field_0x144) == 0x144, "field_0x144");
static_assert(offsetof(nuccParticleRootManager_s4, field_0x158) == 0x158, "field_0x158");
static_assert(offsetof(nuccParticleRootManager_s4, field_0x160) == 0x160, "field_0x160");
static_assert(offsetof(nuccParticleRootManager_s4, field_0x164) == 0x164, "field_0x164");
static_assert(offsetof(nuccParticleRootManager_s4, vfunc_dispatch_0x200) == 0x200, "vfunc_dispatch_0x200");
static_assert(offsetof(nuccParticleRootManager_s4, vfunc_dispatch_0x440) == 0x440, "vfunc_dispatch_0x440");
static_assert(offsetof(nuccParticleRootManager_s4, vfunc_dispatch_0x540) == 0x540, "vfunc_dispatch_0x540");
static_assert(offsetof(nuccParticleRootManager_s4, vfunc_dispatch_0x5C0) == 0x5C0, "vfunc_dispatch_0x5C0");
static_assert(offsetof(nuccParticleRootManager_s4, field_0x668) == 0x668, "field_0x668");

