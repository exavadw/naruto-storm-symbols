/* rbProjectile s3 — NARUTO STORM 3 Full Burst HD (NSUNS3.exe, 64-bit)
 * Image base: 0x140000000
 * Generated: 2026-10-19
 * All layouts INFERRED from static analysis (state_surface + ctor/factory decompilation).
 * Sizes proven only where allocator/ctor/factory evidence exists.
 * Own-game naming only (ns3:: / Storm 3 strings/code).
 */
#ifndef RBPROJECTILE_S3_H
#define RBPROJECTILE_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Embedded types whose full layout is not reconstructed here are represented as
 * fixed-size byte arrays to keep this header self-contained and compilable.
 * Sizes are INFERRED from ctor/factory access patterns, not proven. */
#define NS3_DNAME_SIZE          0x28  /* hash(u32) + flags(u8) + pad(3) + str_ptr(u64) + len(u64) */
#define NS3_VECTOR3_SIZE        0x0C  /* x,y,z float */
#define NS3_MATRIX44_SIZE       0x40
#define NS3_QUAT_SIZE           0x10
#define NS3_BLOCKALLOCATOR_SIZE 0x30  /* vtable ptr + internal state */
#define NS3_CCIATIMER_SIZE      0x18
#define NS3_BVSPHEREGROUP_SIZE  0x68  /* inferred: field_078 at +0x078 minus base +0x010 */

/* ========================================================================
 * ccGameObjectSkill — in-world skill/projectile object
 * Size: 0x4F0 PROVEN (ccFileLoadListForUi::LoadTh(0x4f0,...) in ccSkillObjectFactory::Create @ 0x585918)
 * Vtable: PTR_FUN_1409a47c0 (set in ctor @ 0x57F1FC)
 * Base: GameActor::Base
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ns3_ccGameObjectSkill {
    /* +0x000 */ void *vtable;                          /* PTR_FUN_1409a47c0 */
    /* +0x008 */ uint8_t _pad_008[0x088];              /* GameActor::Base fields (not reconstructed) */
    /* +0x090 */ int32_t field_090;                     /* w, ctor init -1; state_surface medium */
    /* +0x094 */ uint8_t _pad_094[4];
    /* +0x098 */ uint64_t field_098;                    /* rw, CollisionCallback+ctor; high conf */
    /* +0x0A0 */ uint8_t _pad_0a0[0x04C];
    /* +0x0EC */ int32_t field_0ec;                     /* w, ctor init 0 */
    /* +0x0F0 */ int32_t field_0f0;                     /* w, ctor init 0xffffffff */
    /* +0x0F4 */ uint64_t field_0f4;                    /* rw, CollisionCallback+ctor; high conf */
    /* +0x0FC */ uint8_t _pad_0fc[4];
    /* +0x100 */ uint64_t field_100;                    /* w, ctor init 0 */
    /* +0x108 */ uint64_t field_108;                    /* rw, CollisionCallback+ctor; high conf */
    /* +0x110 */ int32_t field_110;                     /* rw, CollisionCallback+ctor; high conf */
    /* +0x114 */ int32_t field_114;                     /* rw, ctor init -1; high conf */
    /* +0x118 */ uint64_t field_118;                    /* rw, CollisionCallback+ctor; high conf */
    /* +0x120 */ uint8_t _pad_120[0x020];
    /* +0x140 */ uint64_t field_140;                    /* r, CollisionCallback; medium conf */
    /* +0x148 */ uint8_t _pad_148[0x050];
    /* +0x198 */ uint64_t field_198;                    /* w, ctor */
    /* +0x1A0 */ int32_t field_1a0;                     /* rw, CollisionCallback+ctor; high conf */
    /* +0x1A4 */ uint32_t field_1a4;                    /* w, ctor loop init 0 */
    /* +0x1A8 */ uint32_t field_1a8;                    /* w, ctor loop init 0 */
    /* +0x1AC */ uint32_t field_1ac;                    /* w, ctor loop init 0 */
    /* +0x1B0 */ uint32_t field_1b0;                    /* w, ctor loop init 0 */
    /* +0x1B4 */ uint8_t field_1b4;                     /* w, ctor init 0 */
    /* +0x1B5 */ uint8_t _pad_1b5[3];
    /* +0x1B8 */ int32_t field_1b8;                     /* w, ctor init 0x3f800000 (1.0f) */
    /* +0x1BC */ int32_t field_1bc;                     /* factory writes from param_1+0x124 */
    /* +0x1C0 */ uint8_t _pad_1c0[0x010];
    /* +0x1D0 */ uint64_t field_1d0;                    /* r, CollisionCallback+ctor; low conf */
    /* +0x1D8 */ uint64_t field_1d8;                    /* r, CollisionCallback; medium conf */
    /* +0x1E0 */ uint64_t field_1e0;                    /* r, CollisionCallback; medium conf */
    /* +0x1E8 */ uint64_t field_1e8;                    /* r, CollisionCallback; medium conf */
    /* +0x1F0 */ uint64_t field_1f0;                    /* r, CollisionCallback; medium conf */
    /* +0x1F8 */ uint64_t field_1f8;                    /* r, CollisionCallback; medium conf */
    /* +0x200 */ uint64_t field_200;                    /* r, CollisionCallback; medium conf */
    /* +0x208 */ uint64_t field_208;                    /* r, CollisionCallback; medium conf */
    /* +0x210 */ uint16_t field_210;                    /* rw, CollisionCallback+ctor; high conf */
    /* +0x212 */ uint64_t field_212;                    /* w, ctor init 0 */
    /* +0x21A */ uint16_t field_21a;                    /* w, ctor init 0 */
    /* +0x21C */ int32_t field_21c;                     /* rw, ctor init 0x3f800000 (1.0f); high conf */
    /* +0x220 */ int32_t field_220;                     /* rw, CollisionCallback+ctor; high conf */
    /* +0x224 */ uint64_t field_224;                    /* w, ctor init 1 */
    /* +0x22C */ int32_t field_22c;                     /* rw, ctor init 0x3f800000 (1.0f); high conf */
    /* +0x230 */ uint64_t field_230;                    /* rw, CollisionCallback+ctor; high conf */
    /* +0x238 */ uint64_t field_238;                    /* w, ctor */
    /* +0x240 */ int32_t field_240;                     /* w, ctor */
    /* +0x244 */ uint8_t _pad_244[4];
    /* +0x248 */ uint64_t field_248;                    /* r, CollisionCallback+ctor; low conf */
    /* +0x250 */ uint8_t _pad_250[0x00C];
    /* +0x25C */ int32_t field_25c;                     /* r, CollisionCallback; medium conf */
    /* +0x260 */ uint8_t _pad_260[0x01C];
    /* +0x27C */ uint64_t field_27c;                    /* r, CollisionCallback; medium conf */
    /* +0x284 */ int32_t field_284;                     /* r, CollisionCallback; medium conf */
    /* +0x288 */ uint8_t _pad_288[0x070];
    /* +0x2F8 */ uint64_t field_2f8;                    /* rw, ctor */
    /* +0x300 */ uint64_t field_300;                    /* w, ctor; high conf */
    /* +0x308 */ uint64_t field_308;                    /* w, ctor */
    /* +0x310 */ uint64_t field_310;                    /* rw, ctor; low conf */
    /* +0x318 */ uint8_t _pad_318[0x0A0];
    /* +0x3B8 */ int32_t field_3b8;                     /* rw, CollisionCallback+ctor; low conf */
    /* +0x3BC */ int32_t field_3bc;                     /* w, CollisionCallback */
    /* +0x3C0 */ uint8_t _pad_3c0[4];
    /* +0x3C4 */ int32_t field_3c4;                     /* r, CollisionCallback+ctor; low conf */
    /* +0x3C8 */ uint64_t field_3c8;                    /* r, CollisionCallback; medium conf */
    /* +0x3D0 */ int32_t field_3d0;                     /* w, ctor */
    /* +0x3D4 */ float field_3d4;                       /* factory: 30.0/fps */
    /* +0x3D8 */ uint64_t field_3d8;                    /* w, ctor */
    /* +0x3E0 */ uint64_t field_3e0;                    /* w, ctor */
    /* +0x3E8 */ uint64_t field_3e8;                    /* w, ctor */
    /* +0x3F0 */ uint64_t field_3f0;                    /* rw, ctor; low conf */
    /* +0x3F8 */ uint8_t _pad_3f8[0x010];
    /* +0x408 */ uint64_t field_408;                    /* w, ctor */
    /* +0x410 */ uint64_t field_410;                    /* w, ctor */
    /* +0x418 */ uint64_t field_418;                    /* w, ctor */
    /* +0x420 */ uint64_t field_420;                    /* rw, ctor; low conf */
    /* +0x428 */ uint8_t _pad_428[0x010];
    /* +0x438 */ uint64_t field_438;                    /* w, ctor */
    /* +0x440 */ uint64_t field_440;                    /* w, ctor */
    /* +0x448 */ uint64_t field_448;                    /* w, ctor */
    /* +0x450 */ uint64_t field_450;                    /* rw, ctor; low conf */
    /* +0x458 */ uint8_t _pad_458[0x010];
    /* +0x468 */ uint64_t field_468;                    /* w, ctor */
    /* +0x470 */ uint64_t field_470;                    /* w, ctor */
    /* +0x478 */ uint64_t field_478;                    /* w, ctor */
    /* +0x480 */ uint64_t field_480;                    /* rw, ctor; low conf */
    /* +0x488 */ uint8_t _pad_488[0x010];
    /* +0x498 */ uint64_t field_498;                    /* w, ctor */
    /* +0x4A0 */ uint64_t field_4a0;                    /* w, ctor */
    /* +0x4A8 */ uint64_t field_4a8;                    /* w, ctor */
    /* +0x4B0 */ uint64_t field_4b0;                    /* rw, ctor; low conf */
    /* +0x4B8 */ uint8_t _pad_4b8[0x010];
    /* +0x4C8 */ uint64_t field_4c8;                    /* rw, ctor; low conf */
    /* +0x4D0 */ uint8_t _pad_4d0[0x010];
    /* +0x4E0 */ uint64_t field_4e0;                    /* w, ctor */
    /* +0x4E8 */ int32_t field_4e8;                     /* w, ctor */
    /* +0x4EC */ uint8_t _pad_4ec[4];                   /* padding to 0x4F0 */
} ns3_ccGameObjectSkill;
#pragma pack(pop)

static_assert(sizeof(ns3_ccGameObjectSkill) == 0x4F0, "ccGameObjectSkill size must be 0x4F0");
static_assert(offsetof(ns3_ccGameObjectSkill, vtable) == 0x000, "vtable offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_090) == 0x090, "field_090 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_098) == 0x098, "field_098 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_0ec) == 0x0EC, "field_0ec offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_0f0) == 0x0F0, "field_0f0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_0f4) == 0x0F4, "field_0f4 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_100) == 0x100, "field_100 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_108) == 0x108, "field_108 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_110) == 0x110, "field_110 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_114) == 0x114, "field_114 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_118) == 0x118, "field_118 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_140) == 0x140, "field_140 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_198) == 0x198, "field_198 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1a0) == 0x1A0, "field_1a0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1a4) == 0x1A4, "field_1a4 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1a8) == 0x1A8, "field_1a8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1ac) == 0x1AC, "field_1ac offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1b0) == 0x1B0, "field_1b0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1b4) == 0x1B4, "field_1b4 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1b8) == 0x1B8, "field_1b8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1bc) == 0x1BC, "field_1bc offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1d0) == 0x1D0, "field_1d0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1d8) == 0x1D8, "field_1d8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1e0) == 0x1E0, "field_1e0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1e8) == 0x1E8, "field_1e8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1f0) == 0x1F0, "field_1f0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_1f8) == 0x1F8, "field_1f8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_200) == 0x200, "field_200 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_208) == 0x208, "field_208 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_210) == 0x210, "field_210 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_212) == 0x212, "field_212 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_21a) == 0x21A, "field_21a offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_21c) == 0x21C, "field_21c offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_220) == 0x220, "field_220 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_224) == 0x224, "field_224 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_22c) == 0x22C, "field_22c offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_230) == 0x230, "field_230 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_238) == 0x238, "field_238 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_240) == 0x240, "field_240 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_248) == 0x248, "field_248 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_25c) == 0x25C, "field_25c offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_27c) == 0x27C, "field_27c offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_284) == 0x284, "field_284 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_2f8) == 0x2F8, "field_2f8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_300) == 0x300, "field_300 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_308) == 0x308, "field_308 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_310) == 0x310, "field_310 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3b8) == 0x3B8, "field_3b8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3bc) == 0x3BC, "field_3bc offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3c4) == 0x3C4, "field_3c4 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3c8) == 0x3C8, "field_3c8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3d0) == 0x3D0, "field_3d0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3d4) == 0x3D4, "field_3d4 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3d8) == 0x3D8, "field_3d8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3e0) == 0x3E0, "field_3e0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3e8) == 0x3E8, "field_3e8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_3f0) == 0x3F0, "field_3f0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_408) == 0x408, "field_408 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_410) == 0x410, "field_410 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_418) == 0x418, "field_418 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_420) == 0x420, "field_420 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_438) == 0x438, "field_438 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_440) == 0x440, "field_440 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_448) == 0x448, "field_448 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_450) == 0x450, "field_450 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_468) == 0x468, "field_468 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_470) == 0x470, "field_470 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_478) == 0x478, "field_478 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_480) == 0x480, "field_480 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_498) == 0x498, "field_498 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_4a0) == 0x4A0, "field_4a0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_4a8) == 0x4A8, "field_4a8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_4b0) == 0x4B0, "field_4b0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_4c8) == 0x4C8, "field_4c8 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_4e0) == 0x4E0, "field_4e0 offset");
static_assert(offsetof(ns3_ccGameObjectSkill, field_4e8) == 0x4E8, "field_4e8 offset");

/* ========================================================================
 * ccSkillObjectFactory — creates ccGameObjectSkill instances
 * Size: >= 0x130 INFERRED (ctor writes up to +0x128 byte; no allocator size found)
 * Vtable: PTR_FUN_1409daf00 (set in ctor @ 0x58572C)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ns3_ccSkillObjectFactory {
    /* +0x000 */ void *vtable;                          /* PTR_FUN_1409daf00 */
    /* +0x008 */ uint8_t _pad_008[4];
    /* +0x00C */ int32_t field_00c;                     /* w, ctor param_3; high conf */
    /* +0x010 */ uint8_t dname_010[NS3_DNAME_SIZE];     /* ctor DName::DName(param_1+2); size INFERRED */
    /* +0x038 */ uint8_t _pad_038[0x014];
    /* +0x04C */ int32_t field_04c;                     /* w, ctor init -1; high conf */
    /* +0x050 */ uint8_t field_050;                     /* w, ctor init 0 */
    /* +0x051 */ uint8_t _pad_051[7];
    /* +0x058 */ uint64_t field_058;                    /* w, ctor */
    /* +0x060 */ uint64_t field_060;                    /* w, ctor */
    /* +0x068 */ uint64_t field_068;                    /* w, ctor */
    /* +0x070 */ uint8_t _pad_070[0x0B0];
    /* +0x120 */ int32_t field_120;                     /* w, ctor init 0x3f800000 (1.0f) */
    /* +0x124 */ int32_t field_124;                     /* w, ctor init 0x3f800000 (1.0f); high conf */
    /* +0x128 */ uint8_t field_128;                     /* w, ctor */
    /* +0x129 */ uint8_t _pad_129[7];                   /* padding to 0x130 */
} ns3_ccSkillObjectFactory;
#pragma pack(pop)

static_assert(offsetof(ns3_ccSkillObjectFactory, vtable) == 0x000, "vtable offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_00c) == 0x00C, "field_00c offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_04c) == 0x04C, "field_04c offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_050) == 0x050, "field_050 offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_058) == 0x058, "field_058 offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_060) == 0x060, "field_060 offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_068) == 0x068, "field_068 offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_120) == 0x120, "field_120 offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_124) == 0x124, "field_124 offset");
static_assert(offsetof(ns3_ccSkillObjectFactory, field_128) == 0x128, "field_128 offset");

/* ========================================================================
 * ccEffectMassProduction — batch effect spawner
 * Size: >= 0x1C0 INFERRED (CreateEffects writes +0x1C0 ptr; LoadTh(0x158) allocates sub-object at +0x1B8)
 * Vtable: unknown (no ctor symbol found)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ns3_ccEffectMassProduction {
    /* +0x000 */ uint8_t _pad_000[0x138];
    /* +0x138 */ int32_t field_138;                     /* w, CreateEffects sets to 1 when param_3!=0 */
    /* +0x13C */ uint8_t _pad_13c[0x02C];
    /* +0x168 */ int32_t field_168;                     /* r, MessageDispatcher; medium conf */
    /* +0x16C */ uint8_t _pad_16c[0x03C];
    /* +0x1A8 */ int32_t field_1a8;                     /* rw, MessageDispatcher; medium conf */
    /* +0x1AC */ int32_t field_1ac;                     /* w, MessageDispatcher; medium conf */
    /* +0x1B0 */ int32_t field_1b0;                     /* w, MessageDispatcher; medium conf */
    /* +0x1B4 */ uint8_t _pad_1b4[4];
    /* +0x1B8 */ uint64_t field_1b8;                    /* r, MessageDispatcher; low conf; embedded fcscene ptr */
    /* +0x1C0 */ uint8_t _pad_1c0[0];                   /* end of known layout */
} ns3_ccEffectMassProduction;
#pragma pack(pop)

static_assert(offsetof(ns3_ccEffectMassProduction, field_138) == 0x138, "field_138 offset");
static_assert(offsetof(ns3_ccEffectMassProduction, field_168) == 0x168, "field_168 offset");
static_assert(offsetof(ns3_ccEffectMassProduction, field_1a8) == 0x1A8, "field_1a8 offset");
static_assert(offsetof(ns3_ccEffectMassProduction, field_1ac) == 0x1AC, "field_1ac offset");
static_assert(offsetof(ns3_ccEffectMassProduction, field_1b0) == 0x1B0, "field_1b0 offset");
static_assert(offsetof(ns3_ccEffectMassProduction, field_1b8) == 0x1B8, "field_1b8 offset");

/* ========================================================================
 * ccHitSphereGroup — hit volume sphere group
 * Size: >= 0x080 INFERRED (state_surface field at +0x078; BVSphereGroup embedded at +0x010)
 * Vtable: unknown
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ns3_ccHitSphereGroup {
    /* +0x000 */ uint8_t _pad_000[0x010];
    /* +0x010 */ uint8_t bv_sphere_group[NS3_BVSPHEREGROUP_SIZE]; /* embedded BVSphereGroup; size INFERRED */
    /* +0x078 */ uint64_t field_078;                    /* r, Initialize; medium conf */
} ns3_ccHitSphereGroup;
#pragma pack(pop)

/* Note: NS3_BVSPHEREGROUP_SIZE is INFERRED (not proven); offsetof assert for field_078 validates layout. */
static_assert(offsetof(ns3_ccHitSphereGroup, field_078) == 0x078, "field_078 offset");

/* ========================================================================
 * ccSkillLoader — loads skill data from files
 * Size: >= 0x044 INFERRED (ctor writes at +0x040; no allocator size found)
 * Vtable: unknown
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ns3_ccSkillLoader {
    /* +0x000 */ uint8_t _pad_000[0x040];
    /* +0x040 */ int32_t field_040;                     /* w, ctor; medium conf */
    /* +0x044 */ uint8_t _pad_044[0];                   /* end of known layout */
} ns3_ccSkillLoader;
#pragma pack(pop)

static_assert(offsetof(ns3_ccSkillLoader, field_040) == 0x040, "field_040 offset");

/* ========================================================================
 * ccSkillActorBoundBall — motion actor for bound-ball skill animation
 * Size: >= 0x034 INFERRED (ctor writes at +0x02C; no allocator size found)
 * Vtable: unknown
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ns3_ccSkillActorBoundBall {
    /* +0x000 */ uint8_t _pad_000[0x02C];
    /* +0x02C */ uint64_t field_02c;                    /* w, ctor; medium conf */
    /* +0x034 */ uint8_t _pad_034[0];                   /* end of known layout */
} ns3_ccSkillActorBoundBall;
#pragma pack(pop)

static_assert(offsetof(ns3_ccSkillActorBoundBall, field_02c) == 0x02C, "field_02c offset");

#endif /* RBPROJECTILE_S3_H */