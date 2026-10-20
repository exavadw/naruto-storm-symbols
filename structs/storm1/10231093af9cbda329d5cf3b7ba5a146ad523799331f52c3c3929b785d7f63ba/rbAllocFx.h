#pragma once
/* rbAllocFx s1 — Nucc::Memory::BlockAllocator, nuccEffectManager, nuccParticleRootManager
 * Build: s1 (NSUNS1.exe, PC x64, image base 0x140000000)
 * All layouts INFERRED from Ghidra state_surface; not CONFIRMED.
 * Object sizes are lower bounds only — no sizeof asserts.
 * Generated 2026-10-19.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct __attribute__((packed)) {
    uint8_t _pad_0x00[0x10]; /* 0x00 */
    uint32_t field_0x10; /* 0x10 */
    uint32_t field_0x14; /* 0x14 */
    uint32_t field_0x18; /* 0x18 */
    uint32_t field_0x1C; /* 0x1C */
    uint64_t field_0x20; /* 0x20 */
    uint8_t _gap_0x28[0x4]; /* 0x28 */
    uint64_t field_0x2C; /* 0x2C */
    uint32_t field_0x34; /* 0x34 */
    uint8_t _gap_0x38[0xC]; /* 0x38 */
    uint32_t field_0x44; /* 0x44 */
    uint8_t _gap_0x48[0xC]; /* 0x48 */
    uint32_t field_0x54; /* 0x54 */
    uint32_t field_0x58; /* 0x58 */
    uint32_t field_0x5C; /* 0x5C */
    uint8_t copy_sub_0x60[0x180]; /* 0x60 */
    uint32_t field_0x1E0; /* 0x1E0 */
    uint8_t _gap_0x1E4[0xC]; /* 0x1E4 */
    uint64_t field_0x1F0; /* 0x1F0 */
    uint64_t field_0x1F8; /* 0x1F8 */
    uint64_t field_0x200; /* 0x200 */
    uint64_t field_0x208; /* 0x208 */
    uint64_t vtable_or_func_0x210; /* 0x210 */
    uint32_t field_0x218; /* 0x218 */
    uint32_t field_0x21C; /* 0x21C */
    uint64_t vtable_or_func_0x220; /* 0x220 */
    uint8_t _gap_0x228[0x8]; /* 0x228 */
    uint64_t field_0x230; /* 0x230 */
    uint64_t field_0x238; /* 0x238 */
    uint64_t field_0x240; /* 0x240 */
    uint64_t field_0x248; /* 0x248 */
    uint64_t field_0x250; /* 0x250 */
    uint32_t field_0x258; /* 0x258 */
    uint32_t field_0x25C; /* 0x25C */
    uint64_t field_0x260; /* 0x260 */
    uint64_t field_0x268; /* 0x268 */
    uint64_t field_0x270; /* 0x270 */
    uint64_t field_0x278; /* 0x278 */
    uint64_t field_0x280; /* 0x280 */
    uint64_t field_0x288; /* 0x288 */
    uint8_t field_0x290; /* 0x290 */
    uint8_t _gap_0x291[0x3]; /* 0x291 */
    uint32_t field_0x294; /* 0x294 */
    uint32_t field_0x298; /* 0x298 */
    uint32_t field_0x29C; /* 0x29C */
    uint8_t copy_sub_0x2A0[0x8]; /* 0x2A0 */
} Nucc_Memory_BlockAllocator_s1;

static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x10) == 0x10, "field_0x10");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x14) == 0x14, "field_0x14");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x18) == 0x18, "field_0x18");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x1C) == 0x1C, "field_0x1C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x20) == 0x20, "field_0x20");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x2C) == 0x2C, "field_0x2C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x34) == 0x34, "field_0x34");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x44) == 0x44, "field_0x44");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x54) == 0x54, "field_0x54");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x58) == 0x58, "field_0x58");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x5C) == 0x5C, "field_0x5C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, copy_sub_0x60) == 0x60, "copy_sub_0x60");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x1E0) == 0x1E0, "field_0x1E0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x1F0) == 0x1F0, "field_0x1F0");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x1F8) == 0x1F8, "field_0x1F8");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x200) == 0x200, "field_0x200");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x208) == 0x208, "field_0x208");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, vtable_or_func_0x210) == 0x210, "vtable_or_func_0x210");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x218) == 0x218, "field_0x218");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x21C) == 0x21C, "field_0x21C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, vtable_or_func_0x220) == 0x220, "vtable_or_func_0x220");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x230) == 0x230, "field_0x230");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x238) == 0x238, "field_0x238");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x240) == 0x240, "field_0x240");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x248) == 0x248, "field_0x248");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x250) == 0x250, "field_0x250");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x258) == 0x258, "field_0x258");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x25C) == 0x25C, "field_0x25C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x260) == 0x260, "field_0x260");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x268) == 0x268, "field_0x268");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x270) == 0x270, "field_0x270");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x278) == 0x278, "field_0x278");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x280) == 0x280, "field_0x280");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x288) == 0x288, "field_0x288");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x290) == 0x290, "field_0x290");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x294) == 0x294, "field_0x294");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x298) == 0x298, "field_0x298");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, field_0x29C) == 0x29C, "field_0x29C");
static_assert(offsetof(Nucc_Memory_BlockAllocator_s1, copy_sub_0x2A0) == 0x2A0, "copy_sub_0x2A0");

typedef struct __attribute__((packed)) {
    uint8_t _pad_0x00[0x2C]; /* 0x00 */
    uint32_t field_0x2C; /* 0x2C */
    uint8_t _gap_0x30[0x38]; /* 0x30 */
    uint64_t effect_list_ptr; /* 0x68 */
    uint32_t effect_count; /* 0x70 */
    uint32_t max_effects; /* 0x74 */
    uint64_t active_flag; /* 0x78 */
} nuccEffectManager_s1;

static_assert(offsetof(nuccEffectManager_s1, field_0x2C) == 0x2C, "field_0x2C");
static_assert(offsetof(nuccEffectManager_s1, effect_list_ptr) == 0x68, "effect_list_ptr");
static_assert(offsetof(nuccEffectManager_s1, effect_count) == 0x70, "effect_count");
static_assert(offsetof(nuccEffectManager_s1, max_effects) == 0x74, "max_effects");
static_assert(offsetof(nuccEffectManager_s1, active_flag) == 0x78, "active_flag");

typedef struct __attribute__((packed)) {
    uint8_t _pad_0x00[0xF0]; /* 0x00 */
    uint32_t field_0xF0; /* 0xF0 */
    uint32_t particle_count; /* 0xF4 */
    uint64_t float_1_0; /* 0xF8 */
    uint32_t manager_state; /* 0x100 */
    uint32_t ctrl_flag; /* 0x104 */
    uint32_t entry_flag; /* 0x108 */
    uint64_t init_counter; /* 0x10C */
    uint8_t byte_field_0x114; /* 0x114 */
    uint8_t _gap_0x115[0x3]; /* 0x115 */
    uint64_t ff_cache_world; /* 0x118 */
    uint64_t ff_cache_anime; /* 0x120 */
    uint64_t ff_cache_generator; /* 0x128 */
    uint64_t ff_cache_0x130; /* 0x130 */
    uint64_t ff_cache_0x138; /* 0x138 */
    uint32_t array_or_count_0x140; /* 0x140 */
    uint32_t field_0x144; /* 0x144 */
    uint8_t _gap_0x148[0x10]; /* 0x148 */
    uint64_t field_0x158; /* 0x158 */
    uint32_t field_0x160; /* 0x160 */
    uint32_t field_0x164; /* 0x164 */
} nuccParticleRootManager_s1;

static_assert(offsetof(nuccParticleRootManager_s1, field_0xF0) == 0xF0, "field_0xF0");
static_assert(offsetof(nuccParticleRootManager_s1, particle_count) == 0xF4, "particle_count");
static_assert(offsetof(nuccParticleRootManager_s1, float_1_0) == 0xF8, "float_1_0");
static_assert(offsetof(nuccParticleRootManager_s1, manager_state) == 0x100, "manager_state");
static_assert(offsetof(nuccParticleRootManager_s1, ctrl_flag) == 0x104, "ctrl_flag");
static_assert(offsetof(nuccParticleRootManager_s1, entry_flag) == 0x108, "entry_flag");
static_assert(offsetof(nuccParticleRootManager_s1, init_counter) == 0x10C, "init_counter");
static_assert(offsetof(nuccParticleRootManager_s1, byte_field_0x114) == 0x114, "byte_field_0x114");
static_assert(offsetof(nuccParticleRootManager_s1, ff_cache_world) == 0x118, "ff_cache_world");
static_assert(offsetof(nuccParticleRootManager_s1, ff_cache_anime) == 0x120, "ff_cache_anime");
static_assert(offsetof(nuccParticleRootManager_s1, ff_cache_generator) == 0x128, "ff_cache_generator");
static_assert(offsetof(nuccParticleRootManager_s1, ff_cache_0x130) == 0x130, "ff_cache_0x130");
static_assert(offsetof(nuccParticleRootManager_s1, ff_cache_0x138) == 0x138, "ff_cache_0x138");
static_assert(offsetof(nuccParticleRootManager_s1, array_or_count_0x140) == 0x140, "array_or_count_0x140");
static_assert(offsetof(nuccParticleRootManager_s1, field_0x144) == 0x144, "field_0x144");
static_assert(offsetof(nuccParticleRootManager_s1, field_0x158) == 0x158, "field_0x158");
static_assert(offsetof(nuccParticleRootManager_s1, field_0x160) == 0x160, "field_0x160");
static_assert(offsetof(nuccParticleRootManager_s1, field_0x164) == 0x164, "field_0x164");
