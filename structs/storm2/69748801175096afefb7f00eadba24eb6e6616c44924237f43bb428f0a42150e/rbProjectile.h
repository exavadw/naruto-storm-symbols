/* rbProjectile struct group — Storm 2 (NSUNS2.exe, s2)
 * Reconstructed from decompiled code + state_surface. All sizes proven from
 * allocator calls unless noted. Everything static is INFERRED.
 * Build: s2 SHA256: 697488011750...
 * Image base: 0x140000000
 *
 * Absent from s2: ccHitGroup, ccHitSphereGroup (zero symbols in DB).
 * Storm 2 is data-driven: ccGameObjectSkill replaces s1's class-per-technique.
 */
#ifndef RBPROJECTILE_S2_H
#define RBPROJECTILE_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- ccGameObjectSkill ----
 * Size proven: 0x1F0 (FUN_140580190(0x1f0,...) in factory FUN_140480200)
 * Vtable: PTR_FUN_1407f29c0 (set in ctor FUN_1403318a8)
 * Ctor writes fields up to offset 0x1E8.
 * State surface found 50 access sites; only those within [0, 0x1F0) are
 * real object fields. Offset 0x280 is beyond the allocation (sub-object).
 *
 * Layout derived from ctor FUN_1403318a8 decompile (param_1 = undefined8*):
 *   param_1[0]       = vtable           -> +0x000
 *   *(u4*)(p+0x12)   = 0                -> +0x090
 *   p[0x13]          = 0                -> +0x098
 *   FUN(p+0x14,...)                     -> +0x0A0 sub-obj init
 *   FUN((ll)p+0xac,..)                  -> +0x0AC sub-obj init
 *   *(u4*)((ll)p+0xec)=0               -> +0x0EC
 *   *(u4*)((ll)p+0x114)=-1             -> +0x114
 *   *(u4*)(p+0x1e)   = -1              -> +0x0F0
 *   *(u8*)((ll)p+0xf4)=0               -> +0x0F4
 *   p[0x20]=0, p[0x21]=0               -> +0x100, +0x108
 *   *(u4*)(p+0x22)   = -1              -> +0x110
 *   p[0x23]=0, p[0x24]=0               -> +0x118, +0x120
 *   *(u4*)(p+0x25)   = 1               -> +0x128
 *   p[0x26]=0                            -> +0x130
 *   *(u4*)(p+0x27)   = 0               -> +0x138
 *   *(u1*)(p+0x2c)   = 0               -> +0x160
 *   sprintf((char*)((ll)p+0x164),"none")-> +0x164 (char buf)
 *   *(u2*)((ll)p+0x1a4)=0xffff         -> +0x1A4
 *   *(u8*)((ll)p+0x1a6)=0              -> +0x1A6
 *   *(u2*)((ll)p+0x1ae)=0              -> +0x1AE
 *   p[0x37]          = 1               -> +0x1B8
 *   *(u4*)(p+0x36)   = 0x3f800000      -> +0x1B0 (float 1.0)
 *   *(u4*)(p+0x38)   = 0x3f800000      -> +0x1C0 (float 1.0)
 *   *(u4*)((ll)p+0x1b4)=0x3f800000     -> +0x1B4 (float 1.0)
 *   *(u8*)((ll)p+0x1c4)=0              -> +0x1C4
 *   *(u8*)((ll)p+0x1cc)=1              -> +0x1CC
 *   *(u8*)((ll)p+0x1d4)=0x3f800000     -> +0x1D4 (double? or u64 holding float bits)
 *   *(u4*)((ll)p+0x1dc)=0x3f800000     -> +0x1DC (float 1.0)
 *   *(u4*)(p+0x3c)   = -1              -> +0x1E0
 *   *(u4*)((ll)p+0x1e4)=-1             -> +0x1E4
 *   *(u4*)(p+0x3d)   = 0               -> +0x1E8
 *   p[0x2a]=0, p[0x2b]=0               -> +0x150, +0x158
 *   loop: puVar2 starts at (ll)p+0x144, clears 3 u4 pairs -> +0x134..+0x14C
 *
 * Factory FUN_140480200 also writes: +0x1C4, +0x1D4, +0x1DC, +0x1E4, +0x1E8
 */
typedef struct __attribute__((packed)) ccGameObjectSkill {
    void     *vtable;           /* +0x000 PTR_FUN_1407f29c0 */
    uint8_t   _pad_008[0x88];   /* +0x008 */
    int32_t   field_090;        /* +0x090 init 0 (p+0x12 as u4) */
    uint8_t   _pad_094[0x4];    /* +0x094 */
    uint64_t  field_098;        /* +0x098 init 0 (p[0x13]) */
    uint8_t   sub_obj_a0[0x8];  /* +0x0A0 sub-obj init FUN(p+0x14), 8b placeholder */
    uint8_t   _pad_0a8[0x4];    /* +0x0A8 */
    uint64_t  field_0ac;        /* +0x0AC sub-obj init FUN((ll)p+0xac) */
    uint8_t   _pad_0b4[0x38];   /* +0x0B4 */
    int32_t   field_0ec;        /* +0x0EC init 0 */
    int32_t   field_0f0;        /* +0x0F0 init -1 (p+0x1e as u4) */
    uint64_t  field_0f4;        /* +0x0F4 init 0 (*(u8*)((ll)p+0xf4)) */
    uint8_t   _pad_0fc[0x4];    /* +0x0FC */
    uint64_t  field_100;        /* +0x100 init 0 (p[0x20]) */
    uint64_t  field_108;        /* +0x108 init 0 (p[0x21]) */
    int32_t   field_110;        /* +0x110 init -1 (p+0x22 as u4) */
    int32_t   field_114;        /* +0x114 init -1 */
    uint64_t  field_118;        /* +0x118 init 0 (p[0x23]) */
    uint64_t  field_120;        /* +0x120 init 0 (p[0x24]) */
    int32_t   field_128;        /* +0x128 init 1 (p+0x25 as u4) */
    uint8_t   _pad_12c[0x4];    /* +0x12C */
    uint64_t  field_130;        /* +0x130 init 0 (p[0x26]) */
    int32_t   field_138;        /* +0x138 init 0 (p+0x27 as u4) */
    uint8_t   _pad_13c[0x14];   /* +0x13C loop-init region */
    uint64_t  field_150;        /* +0x150 init 0 (p[0x2a]), loop-cleared */
    uint64_t  field_158;        /* +0x158 init 0 (p[0x2b]), loop-cleared */
    uint8_t   field_160;        /* +0x160 init 0 (byte, p+0x2c as u1) */
    uint8_t   _pad_161[0x3];    /* +0x161 */
    char      name_buf[0x40];   /* +0x164 sprintf "none" (64 bytes) */
    uint16_t  field_1a4;        /* +0x1A4 init 0xffff */
    uint64_t  field_1a6;        /* +0x1A6 init 0 */
    uint16_t  field_1ae;        /* +0x1AE init 0 */
    float     field_1b0;        /* +0x1B0 init 1.0f (p+0x36 as u4) */
    float     field_1b4;        /* +0x1B4 init 1.0f */
    uint64_t  field_1b8;        /* +0x1B8 init 1 (p[0x37], u64) */
    float     field_1c0;        /* +0x1C0 init 1.0f (p+0x38 as u4) */
    uint64_t  field_1c4;        /* +0x1C4 init 0 */
    uint64_t  field_1cc;        /* +0x1CC init 1 */
    uint64_t  field_1d4;        /* +0x1D4 init 1.0f bits */
    int32_t   field_1dc;        /* +0x1DC init 1.0f */
    int32_t   field_1e0;        /* +0x1E0 init -1 (p+0x3c as u4) */
    int32_t   field_1e4;        /* +0x1E4 init -1 */
    int32_t   field_1e8;        /* +0x1E8 init 0 (p+0x3d as u4) */
    uint8_t   _pad_1ec[0x4];    /* +0x1EC pad to 0x1F0 */
} ccGameObjectSkill;

static_assert(sizeof(ccGameObjectSkill) == 0x1F0, "ccGameObjectSkill size");
static_assert(offsetof(ccGameObjectSkill, vtable)    == 0x000, "ccGameObjectSkill::vtable");
static_assert(offsetof(ccGameObjectSkill, field_090) == 0x090, "ccGameObjectSkill::field_090");
static_assert(offsetof(ccGameObjectSkill, field_098) == 0x098, "ccGameObjectSkill::field_098");
static_assert(offsetof(ccGameObjectSkill, sub_obj_a0)== 0x0A0, "ccGameObjectSkill::sub_obj_a0");
static_assert(offsetof(ccGameObjectSkill, field_0ac) == 0x0AC, "ccGameObjectSkill::field_0ac");
static_assert(offsetof(ccGameObjectSkill, field_0ec) == 0x0EC, "ccGameObjectSkill::field_0ec");
static_assert(offsetof(ccGameObjectSkill, field_0f0) == 0x0F0, "ccGameObjectSkill::field_0f0");
static_assert(offsetof(ccGameObjectSkill, field_0f4) == 0x0F4, "ccGameObjectSkill::field_0f4");
static_assert(offsetof(ccGameObjectSkill, field_100) == 0x100, "ccGameObjectSkill::field_100");
static_assert(offsetof(ccGameObjectSkill, field_108) == 0x108, "ccGameObjectSkill::field_108");
static_assert(offsetof(ccGameObjectSkill, field_110) == 0x110, "ccGameObjectSkill::field_110");
static_assert(offsetof(ccGameObjectSkill, field_114) == 0x114, "ccGameObjectSkill::field_114");
static_assert(offsetof(ccGameObjectSkill, field_118) == 0x118, "ccGameObjectSkill::field_118");
static_assert(offsetof(ccGameObjectSkill, field_120) == 0x120, "ccGameObjectSkill::field_120");
static_assert(offsetof(ccGameObjectSkill, field_128) == 0x128, "ccGameObjectSkill::field_128");
static_assert(offsetof(ccGameObjectSkill, field_130) == 0x130, "ccGameObjectSkill::field_130");
static_assert(offsetof(ccGameObjectSkill, field_138) == 0x138, "ccGameObjectSkill::field_138");
static_assert(offsetof(ccGameObjectSkill, field_150) == 0x150, "ccGameObjectSkill::field_150");
static_assert(offsetof(ccGameObjectSkill, field_158) == 0x158, "ccGameObjectSkill::field_158");
static_assert(offsetof(ccGameObjectSkill, field_160) == 0x160, "ccGameObjectSkill::field_160");
static_assert(offsetof(ccGameObjectSkill, name_buf)  == 0x164, "ccGameObjectSkill::name_buf");
static_assert(offsetof(ccGameObjectSkill, field_1a4) == 0x1A4, "ccGameObjectSkill::field_1a4");
static_assert(offsetof(ccGameObjectSkill, field_1a6) == 0x1A6, "ccGameObjectSkill::field_1a6");
static_assert(offsetof(ccGameObjectSkill, field_1ae) == 0x1AE, "ccGameObjectSkill::field_1ae");
static_assert(offsetof(ccGameObjectSkill, field_1b0) == 0x1B0, "ccGameObjectSkill::field_1b0");
static_assert(offsetof(ccGameObjectSkill, field_1b4) == 0x1B4, "ccGameObjectSkill::field_1b4");
static_assert(offsetof(ccGameObjectSkill, field_1b8) == 0x1B8, "ccGameObjectSkill::field_1b8");
static_assert(offsetof(ccGameObjectSkill, field_1c0) == 0x1C0, "ccGameObjectSkill::field_1c0");
static_assert(offsetof(ccGameObjectSkill, field_1c4) == 0x1C4, "ccGameObjectSkill::field_1c4");
static_assert(offsetof(ccGameObjectSkill, field_1cc) == 0x1CC, "ccGameObjectSkill::field_1cc");
static_assert(offsetof(ccGameObjectSkill, field_1d4) == 0x1D4, "ccGameObjectSkill::field_1d4");
static_assert(offsetof(ccGameObjectSkill, field_1dc) == 0x1DC, "ccGameObjectSkill::field_1dc");
static_assert(offsetof(ccGameObjectSkill, field_1e0) == 0x1E0, "ccGameObjectSkill::field_1e0");
static_assert(offsetof(ccGameObjectSkill, field_1e4) == 0x1E4, "ccGameObjectSkill::field_1e4");
static_assert(offsetof(ccGameObjectSkill, field_1e8) == 0x1E8, "ccGameObjectSkill::field_1e8");

/* ---- ccSkill ----
 * Vtable: PTR_FUN_140843e60 (set in ctor FUN_14047b780)
 * Size NOT directly proven from allocator. Ctor does:
 *   memset(param_1+1, 0, 0x40)          -> covers 0x08..0x48
 *   *(u4*)(param_1+0x4c) = 0            -> 0x4C
 *   *(u8*)(param_1+0x54) = 0            -> 0x54
 *   *(u8*)(param_1+0x5c) = 0            -> 0x5C
 *   memset(param_1+100, 0, 0x400)       -> 0x320..0x720 (u8*: 100*8=0x320)
 *   *(u4*)(param_1+0x464) = 0           -> 0x464
 *   memset(param_1+0x8d, 0, 0x48)       -> 0x468..0x4B0 (u8*: 0x8d*8=0x468)
 *   FUN_14059cd40(param_1+0x96)         -> 0x4B0 (u8*: 0x96*8=0x4B0)
 * Object extends at least to 0x4B0 + sizeof(sub-object at 0x4B0).
 * Marking size unknown >= 0x4B0.
 */
typedef struct __attribute__((packed)) ccSkill {
    void     *vtable;           /* +0x000 PTR_FUN_140843e60 */
    uint8_t   _pad_008[0x44];   /* +0x008 zeroed by memset(0x40) */
    int32_t   field_04c;        /* +0x04C init 0 */
    uint8_t   _pad_050[4];      /* +0x050 */
    uint64_t  field_054;        /* +0x054 init 0 */
    uint64_t  field_05c;        /* +0x05C init 0 */
    uint8_t   _pad_064[0x2BC];  /* +0x064 gap to 0x320 */
    uint8_t   large_zero[0x144];/* +0x320 part of 0x400-byte memset (to 0x464) */
    int32_t   field_464;        /* +0x464 init 0 */
    uint8_t   _pad_468[0x48];   /* +0x468 zeroed by memset(0x48) */
    /* +0x4B0: sub-object init via FUN_14059cd40; size unknown */
    /* Size unknown >= 0x4B0; no trailing pad asserted */
} ccSkill;

/* No sizeof assert -- size unproven */
static_assert(offsetof(ccSkill, vtable)    == 0x000, "ccSkill::vtable");
static_assert(offsetof(ccSkill, field_04c) == 0x04C, "ccSkill::field_04c");
static_assert(offsetof(ccSkill, field_054) == 0x054, "ccSkill::field_054");
static_assert(offsetof(ccSkill, field_05c) == 0x05C, "ccSkill::field_05c");
static_assert(offsetof(ccSkill, field_464) == 0x464, "ccSkill::field_464");

/* ---- ccSkillObjectFactory ----
 * Vtable: PTR_FUN_1408918e8 (set in ctor FUN_140480180)
 * Ctor takes 6 params, writes fields. param_1 is undefined8*:
 *   *(u4*)(p+1)  = param_2              -> +0x08
 *   *(u4*)((ll)p+0xc) = param_3         -> +0x0C
 *   *p           = vtable               -> +0x00
 *   FUN(p+2, param_4)                   -> +0x10 sub-obj
 *   FUN((ll)p+0x1c, param_5)            -> +0x1C sub-obj
 *   FUN(p+5, param_6)                   -> +0x28 sub-obj
 *   *(u4*)((ll)p+0x34) = -1             -> +0x34
 *   *(u1*)(p+7) = 0                     -> +0x38
 *   p[8]=0, p[9]=0                      -> +0x40, +0x48
 *   *(u4*)(p+0xc) = -1                  -> +0x0C (overwrite)
 *   *(u8*)((ll)p+0x54) = 0x3f800000     -> +0x54 (float 1.0 as u64)
 *   *(u4*)((ll)p+0x5c) = 0x3f800000     -> +0x5C (float 1.0)
 *   *(u4*)(p+10) = 0                    -> +0x50
 *   *(u4*)(p+0xd) = 0                   -> +0x68
 *   *(u4*)((ll)p+100) = -1              -> +0x320 (u8*: 100*8=0x320... wait)
 * Actually param_1 is undefined8*, so p+100 = byte offset 0x320.
 * But state_surface shows fields at 0xC, 0x1C, 0x24, 0x34, 0x54, 0x5C, 0x60, 0x68.
 * The ctor write at p+100 as u4 = byte 0x320 seems too far for this small factory obj.
 * Likely the factory object is embedded in a larger structure, or param_1 typing is off.
 * Using state_surface fields + ctor evidence for layout.
 * Size unknown >= 0x70 (last named field at 0x68 + 8).
 */
typedef struct __attribute__((packed)) ccSkillObjectFactory {
    void     *vtable;           /* +0x00 PTR_FUN_1408918e8 */
    int32_t   field_08;         /* +0x08 param_2 */
    int32_t   field_0c;         /* +0x0C param_3, then overwritten -1 */
    uint8_t   sub_obj_10[0x0C]; /* +0x10 sub-object via FUN_1405809e0 */
    uint64_t  field_1c;         /* +0x1C sub-object via FUN_1405809e0 */
    uint32_t  field_24;         /* +0x24 from state_surface */
    uint8_t   _pad_28[0x0C];    /* +0x28 sub-object via FUN_1405809e0 (p+5) */
    int32_t   field_34;         /* +0x34 init -1 */
    uint8_t   field_38;         /* +0x38 init 0 (byte) */
    uint8_t   _pad_39[7];       /* +0x39 */
    uint64_t  field_40;         /* +0x40 init 0 (p[8]) */
    uint64_t  field_48;         /* +0x48 init 0 (p[9]) */
    uint32_t  field_50;         /* +0x50 init 0 (p+10 as u4) */
    float     field_54;         /* +0x54 init float 1.0 bits */
    float     field_58;         /* +0x58 (gap between 0x54 and 0x5C) */
    int32_t   field_5c;         /* +0x5C init float 1.0 bits */
    uint32_t  field_60;         /* +0x60 from state_surface */
    uint32_t  field_64;         /* +0x64 from state_surface */
    uint32_t  field_68;         /* +0x68 init 0 (p+0xd as u4) */
    uint8_t   _pad_6c[4];       /* +0x6C pad to 0x70 */
    /* Size unknown >= 0x70 */
} ccSkillObjectFactory;

/* No sizeof assert -- size unproven */
static_assert(offsetof(ccSkillObjectFactory, vtable)   == 0x00, "ccSkillObjectFactory::vtable");
static_assert(offsetof(ccSkillObjectFactory, field_08) == 0x08, "ccSkillObjectFactory::field_08");
static_assert(offsetof(ccSkillObjectFactory, field_0c) == 0x0C, "ccSkillObjectFactory::field_0c");
static_assert(offsetof(ccSkillObjectFactory, field_1c) == 0x1C, "ccSkillObjectFactory::field_1c");
static_assert(offsetof(ccSkillObjectFactory, field_34) == 0x34, "ccSkillObjectFactory::field_34");
static_assert(offsetof(ccSkillObjectFactory, field_38) == 0x38, "ccSkillObjectFactory::field_38");
static_assert(offsetof(ccSkillObjectFactory, field_40) == 0x40, "ccSkillObjectFactory::field_40");
static_assert(offsetof(ccSkillObjectFactory, field_48) == 0x48, "ccSkillObjectFactory::field_48");
static_assert(offsetof(ccSkillObjectFactory, field_54) == 0x54, "ccSkillObjectFactory::field_54");
static_assert(offsetof(ccSkillObjectFactory, field_5c) == 0x5C, "ccSkillObjectFactory::field_5c");
static_assert(offsetof(ccSkillObjectFactory, field_68) == 0x68, "ccSkillObjectFactory::field_68");

/* ---- ccEffectMassProduction ----
 * No explicit ctor symbol found in s2. Size NOT proven from allocator.
 * State surface fields: 0x168(4b), 0x1A8(4b), 0x1AC(4b), 0x1B0(ptr), 0xB40(?).
 * Field at 0xB40 implies size >= 0xB48 but may be embedded sub-object access.
 * Marking size unknown >= 0x1B8 (last confirmed field + ptr size).
 */
typedef struct __attribute__((packed)) ccEffectMassProduction {
    uint8_t   _pad_000[0x168];  /* +0x000 unknown base */
    int32_t   field_168;        /* +0x168 */
    uint8_t   _pad_16c[0x3C];   /* +0x16C */
    int32_t   field_1a8;        /* +0x1A8 */
    int32_t   field_1ac;        /* +0x1AC */
    uint64_t  field_1b0;        /* +0x1B0 ptr/sub-object */
    /* Size unknown >= 0x1B8; field at 0xB40 likely sub-object access */
} ccEffectMassProduction;

/* No sizeof assert -- size unproven */
static_assert(offsetof(ccEffectMassProduction, field_168) == 0x168, "ccEffectMassProduction::field_168");
static_assert(offsetof(ccEffectMassProduction, field_1a8) == 0x1A8, "ccEffectMassProduction::field_1a8");
static_assert(offsetof(ccEffectMassProduction, field_1ac) == 0x1AC, "ccEffectMassProduction::field_1ac");
static_assert(offsetof(ccEffectMassProduction, field_1b0) == 0x1B0, "ccEffectMassProduction::field_1b0");

/* ---- ccSkillActorSinCurve ----
 * Motion actor class. 3 state_surface fields.
 * Size unknown >= 0x4C (field at 0x44 + possible 8 bytes).
 */
typedef struct __attribute__((packed)) ccSkillActorSinCurve {
    uint8_t   _pad_00[0x2C];    /* +0x00 base */
    uint64_t  field_2c;         /* +0x2C */
    int32_t   field_34;         /* +0x34 */
    uint8_t   _pad_38[0x0C];    /* +0x38 */
    uint64_t  field_44;         /* +0x44 */
    /* Size unknown >= 0x4C */
} ccSkillActorSinCurve;

static_assert(offsetof(ccSkillActorSinCurve, field_2c) == 0x2C, "ccSkillActorSinCurve::field_2c");
static_assert(offsetof(ccSkillActorSinCurve, field_34) == 0x34, "ccSkillActorSinCurve::field_34");
static_assert(offsetof(ccSkillActorSinCurve, field_44) == 0x44, "ccSkillActorSinCurve::field_44");

/* ---- ccSkillActorBoundBall ----
 * Motion actor class. 1 state_surface field at 0x2C.
 * Size unknown >= 0x34.
 */
typedef struct __attribute__((packed)) ccSkillActorBoundBall {
    uint8_t   _pad_00[0x2C];    /* +0x00 base */
    uint64_t  field_2c;         /* +0x2C */
    /* Size unknown >= 0x34 */
} ccSkillActorBoundBall;

static_assert(offsetof(ccSkillActorBoundBall, field_2c) == 0x2C, "ccSkillActorBoundBall::field_2c");

#endif /* RBPROJECTILE_S2_H */