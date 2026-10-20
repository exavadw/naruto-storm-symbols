/* rbProjectile struct group — Storm 1 (NSUNS1.exe, s1)
 * Reconstructed from decompiled code. All sizes proven from allocator calls
 * unless noted. Everything static is INFERRED.
 * Build: s1 SHA256: 10231093af9cbda329d5cf3b7ba5a146ad523799331f52c3c3929b785d7f63ba
 * Image base: 0x140000000
 */
#ifndef RBPROJECTILE_S1_H
#define RBPROJECTILE_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- ccSkillBase ----
 * Size proven: 0x220 (FUN_1403cc648 allocates 0x220, calls FUN_1403cb44c)
 * Vtable: PTR_FUN_1406f3430 (set in ctor FUN_1403cb44c)
 *
 * Layout:
 *   +0x000 vtable (8)
 *   +0x008 _pad (0x204)
 *   +0x20C field_20c (4)
 *   +0x210 _pad (8)
 *   +0x218 field_218 (4)
 *   +0x21C _pad (4)
 *   total = 8 + 0x204 + 4 + 8 + 4 + 4 = 0x220
 */
typedef struct __attribute__((packed)) ccSkillBase {
    void     *vtable;      /* +0x000 PTR_FUN_1406f3430 */
    uint8_t   _pad_008[0x204]; /* +0x008 unknown base fields */
    int32_t   field_20c;   /* +0x20C init 0 in ctor */
    uint8_t   _pad_210[8]; /* +0x210 */
    int32_t   field_218;   /* +0x218 init from param_1[0x43] */
    uint8_t   _pad_21c[4]; /* +0x21C pad to 0x220 */
} ccSkillBase;

static_assert(sizeof(ccSkillBase) == 0x220, "ccSkillBase size");
static_assert(offsetof(ccSkillBase, vtable)   == 0x000, "ccSkillBase::vtable");
static_assert(offsetof(ccSkillBase, field_20c)== 0x20C, "ccSkillBase::field_20c");
static_assert(offsetof(ccSkillBase, field_218)== 0x218, "ccSkillBase::field_218");

/* ---- ccSkillBulletBase ----
 * Inherits ccSkillBase. Ctor FUN_1403f4954 writes fields up to +0x29c.
 * Own size not directly allocated; smallest known subclass is
 * ccSkillFireArmBullet at 0x330 (FUN_1402bc938).
 * Vtable: PTR_FUN_14069da68
 *
 * Absolute offsets (from object start):
 *   +0x000 base ccSkillBase (0x220)
 *   +0x220 _pad (0x54)
 *   +0x274 field_274 (4)
 *   +0x278 _pad (0xC)
 *   +0x284 field_284 (4)
 *   +0x288 _pad (4)
 *   +0x28C field_28c (4)
 *   +0x290 _pad (0xC)
 *   +0x29C field_29c (4)
 *   +0x2A0 _pad (0x90) to reach subclass min 0x330
 *   total = 0x220+0x54+4+0xC+4+4+4+0xC+4+0x90 = 0x330
 */
typedef struct __attribute__((packed)) ccSkillBulletBase {
    ccSkillBase base;          /* +0x000 sizeof=0x220 */
    uint8_t     _pad_220[0x54];/* +0x220 */
    int32_t     field_274;     /* +0x274 init 0 */
    uint8_t     _pad_278[0x0C];/* +0x278 */
    int32_t     field_284;     /* +0x284 init 0 */
    uint8_t     _pad_288[4];   /* +0x288 gap before field_28c */
    int32_t     field_28c;     /* +0x28C init 0 */
    uint8_t     _pad_290[0x0C];/* +0x290 */
    int32_t     field_29c;     /* +0x29C init 0 */
    uint8_t     _pad_2a0[0x90];/* +0x2A0 to reach subclass min 0x330 */
} ccSkillBulletBase;

/* Size unknown; >= 0x2A0 proven from ctor field writes.
 * Subclass ccSkillFireArmBullet = 0x330. */
static_assert(offsetof(ccSkillBulletBase, field_274) == 0x274, "ccSkillBulletBase::field_274");
static_assert(offsetof(ccSkillBulletBase, field_284) == 0x284, "ccSkillBulletBase::field_284");
static_assert(offsetof(ccSkillBulletBase, field_28c) == 0x28C, "ccSkillBulletBase::field_28c");
static_assert(offsetof(ccSkillBulletBase, field_29c) == 0x29C, "ccSkillBulletBase::field_29c");

/* ---- ccSkillRollBulletBase ----
 * Inherits ccSkillBulletBase. Ctor FUN_1403f4c08 writes fields up to +0x31c.
 * Size proven: 0x350 (FUN_1404086e0 allocates 0x350, calls FUN_1403f4c08)
 * Vtable: PTR_FUN_14070bc10
 *
 * The TSV records fields at offsets relative to ccSkillBulletBase:
 * field_2d4 = BulletBase+0x2D4 => absolute 0x2D4 (but BulletBase is only
 * defined up to 0x330 via subclass; the ACTUAL offset in the
 * full object is what matters).
 * The TSV says ccSkillRollBulletBase base is 0x2A0 (the proven minimum
 * of BulletBase), NOT 0x330. So RollBulletBase fields are at:
 *   +0x000 base (0x2A0 — BulletBase proven portion)
 *   +0x2A0 _pad to 0x2D4 = 0x34
 *   +0x2D4 field_2d4 (16 bytes, vec3/transform)
 *   +0x2E4 _pad to 0x314 = 0x30
 *   +0x314 field_314 (8 bytes)
 *   +0x31C field_31c (4 bytes)
 *   +0x320 _pad to 0x350 = 0x30
 *   total = 0x2A0 + 0x34 + 16 + 0x30 + 8 + 4 + 0x30 = 0x350
 */
typedef struct __attribute__((packed)) ccSkillRollBulletBase {
    uint8_t _base_2a0[0x2A0]; /* +0x000 ccSkillBulletBase proven portion */
    uint8_t _pad_2a0[0x34];   /* +0x2A0 gap to field_2d4 */
    uint8_t field_2d4[16];    /* +0x2D4 vec3/transform init via FUN_140480da0 */
    uint8_t _pad_2e4[0x30];   /* +0x2E4 gap to field_314 */
    uint8_t field_314[8];     /* +0x314 init via FUN_14047f900 */
    int32_t field_31c;        /* +0x31C init from FUN_14047ffa0 */
    uint8_t _pad_320[0x30];   /* +0x320 pad to 0x350 */
} ccSkillRollBulletBase;

static_assert(sizeof(ccSkillRollBulletBase) == 0x350, "ccSkillRollBulletBase size");
static_assert(offsetof(ccSkillRollBulletBase, field_2d4) == 0x2D4, "ccSkillRollBulletBase::field_2d4");
static_assert(offsetof(ccSkillRollBulletBase, field_314) == 0x314, "ccSkillRollBulletBase::field_314");
static_assert(offsetof(ccSkillRollBulletBase, field_31c) == 0x31C, "ccSkillRollBulletBase::field_31c");

/* ---- ccSkillBoobyTrapTrap ----
 * Inherits ccSkillRollBulletBase prefix. Ctor FUN_1403d39ec writes +0x344=0.
 * Size proven: 0x348 (FUN_1403d4bbc allocates 0x348, calls FUN_1403d39ec)
 * Note: 0x348 < sizeof(ccSkillRollBulletBase)=0x350. BoobyTrapTrap shares the
 * same ctor chain but its factory allocates less. We embed only the shared
 * prefix (up to +0x344) rather than the full RollBulletBase.
 * Vtable: PTR_FUN_140700bf0
 */
typedef struct __attribute__((packed)) ccSkillBoobyTrapTrap {
    uint8_t _shared_prefix[0x344]; /* +0x000 shared with RollBulletBase up to +0x344 */
    int32_t field_344;             /* +0x344 init 0 */
} ccSkillBoobyTrapTrap;

static_assert(sizeof(ccSkillBoobyTrapTrap) == 0x348, "ccSkillBoobyTrapTrap size");
static_assert(offsetof(ccSkillBoobyTrapTrap, field_344) == 0x344, "ccSkillBoobyTrapTrap::field_344");

/* ---- ccHitGroup ----
 * Size proven: 0x88 (FUN_14028a480 and FUN_140291cac both allocate 0x88)
 * Ctor: FUN_1402d0860, vtable: PTR_FUN_14069e550
 * Fields accessed up to +0x4c in ctor.
 */
typedef struct __attribute__((packed)) ccHitGroup {
    void    *vtable;       /* +0x00 PTR_FUN_14069e550 */
    uint8_t  _pad_08[0x44];/* +0x08 unknown hit-group state */
    int32_t  field_4c;     /* +0x4C last field written in ctor */
    uint8_t  _pad_50[0x38];/* +0x50 pad to 0x88 */
} ccHitGroup;

static_assert(sizeof(ccHitGroup) == 0x88, "ccHitGroup size");
static_assert(offsetof(ccHitGroup, vtable)  == 0x00, "ccHitGroup::vtable");
static_assert(offsetof(ccHitGroup, field_4c)== 0x4C, "ccHitGroup::field_4c");

/* ---- ccEffectMassProduction ----
 * No explicit ctor symbol found. Size NOT directly proven from allocator.
 * Minimum size > 0x1C8 from ccEffectGarSand::Ctrl field accesses (+0x1c4).
 * Inner effect object (at +0x1b0): size 0x158, vtable PTR_FUN_14065be68,
 * ctor FUN_1404b48c0.
 * Marking size as unknown >= 0x1C8.
 */
typedef struct __attribute__((packed)) ccEffectMassProduction {
    void    *vtable;         /* +0x000 */
    uint8_t  _pad_008[0x160];/* +0x008 */
    void    *field_168;      /* +0x168 passed to FUN_1404b35a0 */
    uint8_t  _pad_170[0x014];/* +0x170 */
    float    field_184;      /* +0x184 timer/duration */
    uint8_t  _pad_188[0x024];/* +0x188 */
    int32_t  field_1ac;      /* +0x1AC -1 sentinel check */
    void    *inner_effect;   /* +0x1B0 ptr to 0x158 obj */
    void   **param2_ptr;     /* +0x1B8 stores param_2 */
    int32_t  field_1c0;      /* +0x1C0 mode flag */
    float    field_1c4;      /* +0x1C4 progress/timer */
    /* Size unknown >= 0x1C8; no trailing pad asserted */
} ccEffectMassProduction;

/* No sizeof assert -- size unproven */
static_assert(offsetof(ccEffectMassProduction, field_168)    == 0x168, "ccEffectMassProduction::field_168");
static_assert(offsetof(ccEffectMassProduction, field_184)    == 0x184, "ccEffectMassProduction::field_184");
static_assert(offsetof(ccEffectMassProduction, field_1ac)    == 0x1AC, "ccEffectMassProduction::field_1ac");
static_assert(offsetof(ccEffectMassProduction, inner_effect) == 0x1B0, "ccEffectMassProduction::inner_effect");
static_assert(offsetof(ccEffectMassProduction, param2_ptr)   == 0x1B8, "ccEffectMassProduction::param2_ptr");
static_assert(offsetof(ccEffectMassProduction, field_1c0)    == 0x1C0, "ccEffectMassProduction::field_1c0");
static_assert(offsetof(ccEffectMassProduction, field_1c4)    == 0x1C4, "ccEffectMassProduction::field_1c4");

#endif /* RBPROJECTILE_S1_H */