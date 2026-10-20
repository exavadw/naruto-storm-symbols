#ifndef S3_BOSS06_H
#define S3_BOSS06_H

/*
 * s3Boss06.h - Storm 3 Full Burst HD (NSUNS3.exe) boss battle structs
 * Build: s3 (NARUTO STORM 3 Full Burst HD PC, 64-bit)
 *
 * ALL FIELDS ARE INFERRED FROM STATIC ANALYSIS (decompiled constructor + Update).
 * No runtime confirmation. Offsets and types may be wrong.
 *
 * Group: ccBoss06*, ccSceneBoss06*, ccCameraJudgeBoss06*, ccCamOpeBoss06*, ccUiBoss06*
 * Only ccBoss0610 has proven instance state (size 0x210 from CreateInstance allocator).
 * ccBoss0600 has no constructor in s3 (abstract/base or resolved to subclass);
 * other classes in the group are small helpers listed in the report.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccBoss0610
 * Object size: 0x210 (528 bytes) — from FUN_140683f70(0x210,...) in CreateInstance (RVA 0x30B31C)
 * Source: source\BossBattle\06\Battle10\ccBoss0610.cpp
 * Fields below are proven by constructor (RVA 0x30AEA8) and Update (RVA 0x30BDDC).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610 {
    /* 0x0000 */ void *vtable;               /* ctor writes PTR_FUN_1409057e8 */
    /* 0x0008 */ uint8_t base_subobj[0x90];  /* 0x0008 FUN_14030dde0(param_1+1) = sub-object init, 8 qwords = 0x40; but Update calls FUN_1402903a0(param_1+8) suggesting larger base. Proven extent: 0x08..0x97 */
    /* 0x0098 */ uint8_t subobj_0098[0x68];  /* 0x0098 FUN_14030e698(param_1+0x13)=ctor sub-init; Update calls FUN_14030e7a4(param_1+0x98). Extent to 0xFF */
    /* 0x0100 */ uint64_t unk_0100;           /* 0x0100 w medium ctor param_1[0x20]=0; Update iterates param_1+0x100 as ptr array[3] */
    /* 0x0108 */ uint64_t unk_0108;           /* 0x0108 w medium ctor param_1[0x21]=0; Update array[1] */
    /* 0x0110 */ uint64_t unk_0110;           /* 0x0110 w medium ctor param_1[0x22]=0; Update array[2] */
    /* 0x0118 */ uint64_t unk_0118;           /* 0x0118 w medium ctor param_1[0x23]=0; Update null-check + vcall **(**(ptr+0x118)+0xe60) */
    /* 0x0120 */ uint64_t unk_0120;           /* 0x0120 w medium ctor param_1[0x24]=0; Update null-check + vcall */
    /* 0x0128 */ uint64_t unk_0128;           /* 0x0128 w medium ctor param_1[0x25]=0; Update null-check + vcall + nested deref *(ptr+0xb1e8) */
    /* 0x0130 */ uint64_t unk_0130;           /* 0x0130 w medium ctor param_1[0x26]=0; Update loop ptr[0] */
    /* 0x0138 */ uint64_t unk_0138;           /* 0x0138 w medium ctor param_1[0x27]=0; Update loop ptr[1] */
    /* 0x0140 */ uint64_t unk_0140;           /* 0x0140 w medium ctor param_1[0x28]=0; Update loop ptr[2] */
    /* 0x0148 */ uint64_t unk_0148;           /* 0x0148 w medium ctor param_1[0x29]=0; Update null-check -> FUN_14032877c */
    /* 0x0150 */ uint64_t unk_0150;           /* 0x0150 w medium ctor param_1[0x2a]=0 */
    /* 0x0158 */ uint64_t unk_0158;           /* 0x0158 w medium ctor param_1[0x2b]=0 */
    /* 0x0160 */ uint32_t unk_0160;           /* 0x0160 w medium ctor *(u32*)(param_1+0x2c)=0 */
    /* 0x0164 */ uint8_t pad_0164[4];         /* align to 0x0168 */
    /* 0x0168 */ uint64_t unk_0168;           /* 0x0168 w medium ctor param_1[0x2d]=0; Update null-check paired with 0x170 */
    /* 0x0170 */ uint32_t unk_0170;           /* 0x0170 w medium ctor *(u32*)(param_1+0x2e)=0; Update reads as int guard */
    /* 0x0174 */ uint64_t field_0174;         /* 0x0174 w high ctor *(u64*)(param_1+0x174)=0xb (boss phase/id?) */
    /* 0x017C */ uint32_t field_017C;         /* 0x017C w high ctor *(u32*)(param_1+0x17c)=0x3f800000 (float 1.0) */
    /* 0x0180 */ uint8_t pad_0180[4];         /* align to 0x0184 */
    /* 0x0184 */ uint32_t field_0184;         /* 0x0184 w high ctor *(u32*)(param_1+0x184)=0x3f800000 (float 1.0) */
    /* 0x0188 */ uint8_t pad_0188[4];         /* align to 0x018C */
    /* 0x018C */ uint32_t unk_018C;           /* 0x018C w medium Update writes 0 conditionally */
    /* 0x0190 */ uint8_t subobj_0190[0x50];   /* 0x0190 ctor FUN_14037fc30(param_1+0x32)=sub-init; Update FUN_14038003c(param_1+400=0x190). Extent: 0x190..0x1DF */
    /* 0x01E0 */ uint8_t pad_01E0[0x28];      /* gap 0x1E0..0x207 not directly accessed in ctor/Update */
    /* 0x0208 */ uint8_t pad_0208[4];         /* align to 0x020C */
    /* 0x020C */ uint32_t unk_020C;           /* 0x020C rw medium ctor *(u32*)(param_1+0x20c)=0; Update reads+writes 0 */
} ccBoss0610;
#pragma pack(pop)

static_assert(sizeof(ccBoss0610) == 0x210, "ccBoss0610 size must be 0x210");
static_assert(offsetof(ccBoss0610, vtable) == 0x0000, "vtable @ 0x0");
static_assert(offsetof(ccBoss0610, base_subobj) == 0x0008, "base_subobj @ 0x8");
static_assert(offsetof(ccBoss0610, subobj_0098) == 0x0098, "subobj_0098 @ 0x98");
static_assert(offsetof(ccBoss0610, unk_0100) == 0x0100, "unk_0100 @ 0x100");
static_assert(offsetof(ccBoss0610, unk_0108) == 0x0108, "unk_0108 @ 0x108");
static_assert(offsetof(ccBoss0610, unk_0110) == 0x0110, "unk_0110 @ 0x110");
static_assert(offsetof(ccBoss0610, unk_0118) == 0x0118, "unk_0118 @ 0x118");
static_assert(offsetof(ccBoss0610, unk_0120) == 0x0120, "unk_0120 @ 0x120");
static_assert(offsetof(ccBoss0610, unk_0128) == 0x0128, "unk_0128 @ 0x128");
static_assert(offsetof(ccBoss0610, unk_0130) == 0x0130, "unk_0130 @ 0x130");
static_assert(offsetof(ccBoss0610, unk_0138) == 0x0138, "unk_0138 @ 0x138");
static_assert(offsetof(ccBoss0610, unk_0140) == 0x0140, "unk_0140 @ 0x140");
static_assert(offsetof(ccBoss0610, unk_0148) == 0x0148, "unk_0148 @ 0x148");
static_assert(offsetof(ccBoss0610, unk_0150) == 0x0150, "unk_0150 @ 0x150");
static_assert(offsetof(ccBoss0610, unk_0158) == 0x0158, "unk_0158 @ 0x158");
static_assert(offsetof(ccBoss0610, unk_0160) == 0x0160, "unk_0160 @ 0x160");
static_assert(offsetof(ccBoss0610, unk_0168) == 0x0168, "unk_0168 @ 0x168");
static_assert(offsetof(ccBoss0610, unk_0170) == 0x0170, "unk_0170 @ 0x170");
static_assert(offsetof(ccBoss0610, field_0174) == 0x0174, "field_0174 @ 0x174");
static_assert(offsetof(ccBoss0610, field_017C) == 0x017C, "field_017C @ 0x17C");
static_assert(offsetof(ccBoss0610, field_0184) == 0x0184, "field_0184 @ 0x184");
static_assert(offsetof(ccBoss0610, unk_018C) == 0x018C, "unk_018C @ 0x18C");
static_assert(offsetof(ccBoss0610, subobj_0190) == 0x0190, "subobj_0190 @ 0x190");
static_assert(offsetof(ccBoss0610, unk_020C) == 0x020C, "unk_020C @ 0x20C");

#endif /* S3_BOSS06_H */
/* ============================================================
 * Coverage batch 1 — auto-generated from the decompiler cache state_surface
 * Build: s3 (NSUNS3.exe 64-bit), Date: 2026-10-19
 * ALL FIELDS INFERRED. No runtime confirmation.
 * ============================================================ */

/*
 * ccBoss0610Tsunade
 * Methods: 54
 * Object size: >= 0xB2A0 (45728 bytes) — >= 0xB2A0 (max accessed), aligned 0xB2A0
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610Tsunade {
    /* 0x0000 */ uint8_t pad_0000[512];
    /* 0x0200 */ uint64_t field_0200;
    /* 0x0208 */ uint8_t pad_0208[56];
    /* 0x0240 */ uint64_t field_0240;
    /* 0x0248 */ uint8_t pad_0248[1896];
    /* 0x09B0 */ uint32_t field_09B0;
    /* 0x09B4 */ uint32_t field_09B4;
    /* 0x09B8 */ uint8_t pad_09B8[9224];
    /* 0x2DC0 */ uint64_t field_2DC0;
    /* 0x2DC8 */ uint8_t pad_2DC8[16056];
    /* 0x6C80 */ uint64_t field_6C80;
    /* 0x6C88 */ uint8_t pad_6C88[120];
    /* 0x6D00 */ uint64_t field_6D00;
    /* 0x6D08 */ uint8_t pad_6D08[504];
    /* 0x6F00 */ uint64_t field_6F00;
    /* 0x6F08 */ uint8_t pad_6F08[440];
    /* 0x70C0 */ uint64_t field_70C0;
    /* 0x70C8 */ uint8_t pad_70C8[3904];
    /* 0x8008 */ uint64_t field_8008;
    /* 0x8010 */ uint64_t field_8010;
    /* 0x8018 */ uint8_t pad_8018[32];
    /* 0x8038 */ uint64_t field_8038;
    /* 0x8040 */ uint8_t pad_8040[16];
    /* 0x8050 */ uint64_t field_8050;
    /* 0x8058 */ uint8_t pad_8058[36];
    /* 0x807C */ uint32_t field_807C;
    /* 0x8080 */ uint8_t pad_8080[120];
    /* 0x80F8 */ float field_80F8;
    /* 0x80FC */ uint8_t pad_80FC[11796];
    /* 0xAF10 */ uint32_t field_AF10;
    /* 0xAF14 */ uint8_t pad_AF14[164];
    /* 0xAFB8 */ uint64_t field_AFB8;
    /* 0xAFC0 */ uint32_t field_AFC0;
    /* 0xAFC4 */ uint8_t pad_AFC4[140];
    /* 0xB050 */ uint32_t field_B050;
    /* 0xB054 */ uint8_t field_B054;
    /* 0xB055 */ uint8_t pad_B055[331];
    /* 0xB1A0 */ uint64_t field_B1A0;
    /* 0xB1A8 */ uint64_t field_B1A8;
    /* 0xB1B0 */ uint32_t field_B1B0;
    /* 0xB1B4 */ uint64_t field_B1B4;
    /* 0xB1BC */ uint8_t pad_B1BC[28];
    /* 0xB1D8 */ uint64_t field_B1D8;
    /* 0xB1E0 */ uint8_t pad_B1E0[80];
    /* 0xB230 */ float field_B230;
    /* 0xB234 */ uint64_t field_B234;
    /* 0xB23C */ uint8_t pad_B23C[4];
    /* 0xB240 */ uint64_t field_B240;
    /* 0xB248 */ uint8_t pad_B248[4];
    /* 0xB24C */ uint64_t field_B24C;
    /* 0xB254 */ uint32_t field_B254;
    /* 0xB258 */ uint64_t field_B258;
    /* 0xB260 */ uint8_t pad_B260[4];
    /* 0xB264 */ uint64_t field_B264;
    /* 0xB26C */ uint64_t field_B26C;
    /* 0xB274 */ uint64_t field_B274;
    /* 0xB27C */ uint64_t field_B27C;
    /* 0xB284 */ uint64_t field_B284;
    /* 0xB28C */ uint64_t field_B28C;
    /* 0xB294 */ uint32_t field_B294;
    /* 0xB298 */ uint32_t field_B298;
    /* 0xB29C */ float field_B29C;
} ccBoss0610Tsunade;

#pragma pack(pop)

static_assert(offsetof(ccBoss0610Tsunade, pad_0000) == 0x0000, "ccBoss0610Tsunade pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0610Tsunade, field_0200) == 0x0200, "ccBoss0610Tsunade field_0200 @ 0x0200");
static_assert(offsetof(ccBoss0610Tsunade, pad_0208) == 0x0208, "ccBoss0610Tsunade pad_0208 @ 0x0208");
static_assert(offsetof(ccBoss0610Tsunade, field_0240) == 0x0240, "ccBoss0610Tsunade field_0240 @ 0x0240");
static_assert(offsetof(ccBoss0610Tsunade, pad_0248) == 0x0248, "ccBoss0610Tsunade pad_0248 @ 0x0248");
static_assert(offsetof(ccBoss0610Tsunade, field_09B0) == 0x09B0, "ccBoss0610Tsunade field_09B0 @ 0x09B0");
static_assert(offsetof(ccBoss0610Tsunade, field_09B4) == 0x09B4, "ccBoss0610Tsunade field_09B4 @ 0x09B4");
static_assert(offsetof(ccBoss0610Tsunade, pad_09B8) == 0x09B8, "ccBoss0610Tsunade pad_09B8 @ 0x09B8");
static_assert(offsetof(ccBoss0610Tsunade, field_2DC0) == 0x2DC0, "ccBoss0610Tsunade field_2DC0 @ 0x2DC0");
static_assert(offsetof(ccBoss0610Tsunade, pad_2DC8) == 0x2DC8, "ccBoss0610Tsunade pad_2DC8 @ 0x2DC8");
static_assert(offsetof(ccBoss0610Tsunade, field_6C80) == 0x6C80, "ccBoss0610Tsunade field_6C80 @ 0x6C80");
static_assert(offsetof(ccBoss0610Tsunade, pad_6C88) == 0x6C88, "ccBoss0610Tsunade pad_6C88 @ 0x6C88");
static_assert(offsetof(ccBoss0610Tsunade, field_6D00) == 0x6D00, "ccBoss0610Tsunade field_6D00 @ 0x6D00");
static_assert(offsetof(ccBoss0610Tsunade, pad_6D08) == 0x6D08, "ccBoss0610Tsunade pad_6D08 @ 0x6D08");
static_assert(offsetof(ccBoss0610Tsunade, field_6F00) == 0x6F00, "ccBoss0610Tsunade field_6F00 @ 0x6F00");
static_assert(offsetof(ccBoss0610Tsunade, pad_6F08) == 0x6F08, "ccBoss0610Tsunade pad_6F08 @ 0x6F08");
static_assert(offsetof(ccBoss0610Tsunade, field_70C0) == 0x70C0, "ccBoss0610Tsunade field_70C0 @ 0x70C0");
static_assert(offsetof(ccBoss0610Tsunade, pad_70C8) == 0x70C8, "ccBoss0610Tsunade pad_70C8 @ 0x70C8");
static_assert(offsetof(ccBoss0610Tsunade, field_8008) == 0x8008, "ccBoss0610Tsunade field_8008 @ 0x8008");
static_assert(offsetof(ccBoss0610Tsunade, field_8010) == 0x8010, "ccBoss0610Tsunade field_8010 @ 0x8010");
static_assert(offsetof(ccBoss0610Tsunade, pad_8018) == 0x8018, "ccBoss0610Tsunade pad_8018 @ 0x8018");
static_assert(offsetof(ccBoss0610Tsunade, field_8038) == 0x8038, "ccBoss0610Tsunade field_8038 @ 0x8038");
static_assert(offsetof(ccBoss0610Tsunade, pad_8040) == 0x8040, "ccBoss0610Tsunade pad_8040 @ 0x8040");
static_assert(offsetof(ccBoss0610Tsunade, field_8050) == 0x8050, "ccBoss0610Tsunade field_8050 @ 0x8050");
static_assert(offsetof(ccBoss0610Tsunade, pad_8058) == 0x8058, "ccBoss0610Tsunade pad_8058 @ 0x8058");
static_assert(offsetof(ccBoss0610Tsunade, field_807C) == 0x807C, "ccBoss0610Tsunade field_807C @ 0x807C");
static_assert(offsetof(ccBoss0610Tsunade, pad_8080) == 0x8080, "ccBoss0610Tsunade pad_8080 @ 0x8080");
static_assert(offsetof(ccBoss0610Tsunade, field_80F8) == 0x80F8, "ccBoss0610Tsunade field_80F8 @ 0x80F8");
static_assert(offsetof(ccBoss0610Tsunade, pad_80FC) == 0x80FC, "ccBoss0610Tsunade pad_80FC @ 0x80FC");
static_assert(offsetof(ccBoss0610Tsunade, field_AF10) == 0xAF10, "ccBoss0610Tsunade field_AF10 @ 0xAF10");
static_assert(offsetof(ccBoss0610Tsunade, pad_AF14) == 0xAF14, "ccBoss0610Tsunade pad_AF14 @ 0xAF14");
static_assert(offsetof(ccBoss0610Tsunade, field_AFB8) == 0xAFB8, "ccBoss0610Tsunade field_AFB8 @ 0xAFB8");
static_assert(offsetof(ccBoss0610Tsunade, field_AFC0) == 0xAFC0, "ccBoss0610Tsunade field_AFC0 @ 0xAFC0");
static_assert(offsetof(ccBoss0610Tsunade, pad_AFC4) == 0xAFC4, "ccBoss0610Tsunade pad_AFC4 @ 0xAFC4");
static_assert(offsetof(ccBoss0610Tsunade, field_B050) == 0xB050, "ccBoss0610Tsunade field_B050 @ 0xB050");
static_assert(offsetof(ccBoss0610Tsunade, field_B054) == 0xB054, "ccBoss0610Tsunade field_B054 @ 0xB054");
static_assert(offsetof(ccBoss0610Tsunade, pad_B055) == 0xB055, "ccBoss0610Tsunade pad_B055 @ 0xB055");
static_assert(offsetof(ccBoss0610Tsunade, field_B1A0) == 0xB1A0, "ccBoss0610Tsunade field_B1A0 @ 0xB1A0");
static_assert(offsetof(ccBoss0610Tsunade, field_B1A8) == 0xB1A8, "ccBoss0610Tsunade field_B1A8 @ 0xB1A8");
static_assert(offsetof(ccBoss0610Tsunade, field_B1B0) == 0xB1B0, "ccBoss0610Tsunade field_B1B0 @ 0xB1B0");
static_assert(offsetof(ccBoss0610Tsunade, field_B1B4) == 0xB1B4, "ccBoss0610Tsunade field_B1B4 @ 0xB1B4");
static_assert(offsetof(ccBoss0610Tsunade, pad_B1BC) == 0xB1BC, "ccBoss0610Tsunade pad_B1BC @ 0xB1BC");
static_assert(offsetof(ccBoss0610Tsunade, field_B1D8) == 0xB1D8, "ccBoss0610Tsunade field_B1D8 @ 0xB1D8");
static_assert(offsetof(ccBoss0610Tsunade, pad_B1E0) == 0xB1E0, "ccBoss0610Tsunade pad_B1E0 @ 0xB1E0");
static_assert(offsetof(ccBoss0610Tsunade, field_B230) == 0xB230, "ccBoss0610Tsunade field_B230 @ 0xB230");
static_assert(offsetof(ccBoss0610Tsunade, field_B234) == 0xB234, "ccBoss0610Tsunade field_B234 @ 0xB234");
static_assert(offsetof(ccBoss0610Tsunade, pad_B23C) == 0xB23C, "ccBoss0610Tsunade pad_B23C @ 0xB23C");
static_assert(offsetof(ccBoss0610Tsunade, field_B240) == 0xB240, "ccBoss0610Tsunade field_B240 @ 0xB240");
static_assert(offsetof(ccBoss0610Tsunade, pad_B248) == 0xB248, "ccBoss0610Tsunade pad_B248 @ 0xB248");
static_assert(offsetof(ccBoss0610Tsunade, field_B24C) == 0xB24C, "ccBoss0610Tsunade field_B24C @ 0xB24C");
static_assert(offsetof(ccBoss0610Tsunade, field_B254) == 0xB254, "ccBoss0610Tsunade field_B254 @ 0xB254");
static_assert(offsetof(ccBoss0610Tsunade, field_B258) == 0xB258, "ccBoss0610Tsunade field_B258 @ 0xB258");
static_assert(offsetof(ccBoss0610Tsunade, pad_B260) == 0xB260, "ccBoss0610Tsunade pad_B260 @ 0xB260");
static_assert(offsetof(ccBoss0610Tsunade, field_B264) == 0xB264, "ccBoss0610Tsunade field_B264 @ 0xB264");
static_assert(offsetof(ccBoss0610Tsunade, field_B26C) == 0xB26C, "ccBoss0610Tsunade field_B26C @ 0xB26C");
static_assert(offsetof(ccBoss0610Tsunade, field_B274) == 0xB274, "ccBoss0610Tsunade field_B274 @ 0xB274");
static_assert(offsetof(ccBoss0610Tsunade, field_B27C) == 0xB27C, "ccBoss0610Tsunade field_B27C @ 0xB27C");
static_assert(offsetof(ccBoss0610Tsunade, field_B284) == 0xB284, "ccBoss0610Tsunade field_B284 @ 0xB284");
static_assert(offsetof(ccBoss0610Tsunade, field_B28C) == 0xB28C, "ccBoss0610Tsunade field_B28C @ 0xB28C");
static_assert(offsetof(ccBoss0610Tsunade, field_B294) == 0xB294, "ccBoss0610Tsunade field_B294 @ 0xB294");
static_assert(offsetof(ccBoss0610Tsunade, field_B298) == 0xB298, "ccBoss0610Tsunade field_B298 @ 0xB298");
static_assert(offsetof(ccBoss0610Tsunade, field_B29C) == 0xB29C, "ccBoss0610Tsunade field_B29C @ 0xB29C");


/*
 * ccBoss0610TndState
 * Methods: 30
 * Object size: >= 0xD8 (216 bytes) — >= 0xD8 (max accessed), aligned 0xD8
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610TndState {
    /* 0x0000 */ uint8_t pad_0000[84];
    /* 0x0054 */ uint32_t field_0054;
    /* 0x0058 */ uint64_t field_0058;
    /* 0x0060 */ uint32_t field_0060;
    /* 0x0064 */ uint8_t pad_0064[4];
    /* 0x0068 */ uint64_t field_0068;
    /* 0x0070 */ uint64_t field_0070;
    /* 0x0078 */ uint64_t field_0078;
    /* 0x0080 */ uint64_t field_0080;
    /* 0x0088 */ uint64_t field_0088;
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint64_t field_0098;
    /* 0x00A0 */ uint64_t field_00A0;
    /* 0x00A8 */ uint64_t field_00A8;
    /* 0x00B0 */ uint64_t field_00B0;
    /* 0x00B8 */ uint64_t field_00B8;
    /* 0x00C0 */ uint32_t field_00C0;
    /* 0x00C4 */ uint8_t pad_00C4[4];
    /* 0x00C8 */ uint64_t field_00C8;
    /* 0x00D0 */ uint32_t field_00D0;
    /* 0x00D4 */ uint32_t field_00D4;
} ccBoss0610TndState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610TndState, pad_0000) == 0x0000, "ccBoss0610TndState pad @ 0x0000");
static_assert(offsetof(ccBoss0610TndState, field_0054) == 0x0054, "ccBoss0610TndState field_0054 @ 0x0054");
static_assert(offsetof(ccBoss0610TndState, field_0058) == 0x0058, "ccBoss0610TndState field_0058 @ 0x0058");
static_assert(offsetof(ccBoss0610TndState, field_0060) == 0x0060, "ccBoss0610TndState field_0060 @ 0x0060");
static_assert(offsetof(ccBoss0610TndState, pad_0064) == 0x0064, "ccBoss0610TndState pad @ 0x0064");
static_assert(offsetof(ccBoss0610TndState, field_0068) == 0x0068, "ccBoss0610TndState field_0068 @ 0x0068");
static_assert(offsetof(ccBoss0610TndState, field_0070) == 0x0070, "ccBoss0610TndState field_0070 @ 0x0070");
static_assert(offsetof(ccBoss0610TndState, field_0078) == 0x0078, "ccBoss0610TndState field_0078 @ 0x0078");
static_assert(offsetof(ccBoss0610TndState, field_0080) == 0x0080, "ccBoss0610TndState field_0080 @ 0x0080");
static_assert(offsetof(ccBoss0610TndState, field_0088) == 0x0088, "ccBoss0610TndState field_0088 @ 0x0088");
static_assert(offsetof(ccBoss0610TndState, field_0090) == 0x0090, "ccBoss0610TndState field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610TndState, field_0098) == 0x0098, "ccBoss0610TndState field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610TndState, field_00A0) == 0x00A0, "ccBoss0610TndState field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0610TndState, field_00A8) == 0x00A8, "ccBoss0610TndState field_00A8 @ 0x00A8");
static_assert(offsetof(ccBoss0610TndState, field_00B0) == 0x00B0, "ccBoss0610TndState field_00B0 @ 0x00B0");
static_assert(offsetof(ccBoss0610TndState, field_00B8) == 0x00B8, "ccBoss0610TndState field_00B8 @ 0x00B8");
static_assert(offsetof(ccBoss0610TndState, field_00C0) == 0x00C0, "ccBoss0610TndState field_00C0 @ 0x00C0");
static_assert(offsetof(ccBoss0610TndState, pad_00C4) == 0x00C4, "ccBoss0610TndState pad @ 0x00C4");
static_assert(offsetof(ccBoss0610TndState, field_00C8) == 0x00C8, "ccBoss0610TndState field_00C8 @ 0x00C8");
static_assert(offsetof(ccBoss0610TndState, field_00D0) == 0x00D0, "ccBoss0610TndState field_00D0 @ 0x00D0");
static_assert(offsetof(ccBoss0610TndState, field_00D4) == 0x00D4, "ccBoss0610TndState field_00D4 @ 0x00D4");

/*
 * ccBoss0610MssState
 * Methods: 23
 * Object size: >= 0x98 (152 bytes) — >= 0x94 (max accessed), aligned 0x98
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610MssState {
    /* 0x0000 */ uint8_t pad_0000[84];
    /* 0x0054 */ uint32_t field_0054;
    /* 0x0058 */ uint64_t field_0058;
    /* 0x0060 */ uint32_t field_0060;
    /* 0x0064 */ uint8_t pad_0064[4];
    /* 0x0068 */ uint64_t field_0068;
    /* 0x0070 */ uint64_t field_0070;
    /* 0x0078 */ uint64_t field_0078;
    /* 0x0080 */ uint64_t field_0080;
    /* 0x0088 */ uint64_t field_0088;
    /* 0x0090 */ uint32_t field_0090;
    /* 0x0094 */ uint8_t pad_0094[4];
} ccBoss0610MssState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610MssState, pad_0000) == 0x0000, "ccBoss0610MssState pad @ 0x0000");
static_assert(offsetof(ccBoss0610MssState, field_0054) == 0x0054, "ccBoss0610MssState field_0054 @ 0x0054");
static_assert(offsetof(ccBoss0610MssState, field_0058) == 0x0058, "ccBoss0610MssState field_0058 @ 0x0058");
static_assert(offsetof(ccBoss0610MssState, field_0060) == 0x0060, "ccBoss0610MssState field_0060 @ 0x0060");
static_assert(offsetof(ccBoss0610MssState, pad_0064) == 0x0064, "ccBoss0610MssState pad @ 0x0064");
static_assert(offsetof(ccBoss0610MssState, field_0068) == 0x0068, "ccBoss0610MssState field_0068 @ 0x0068");
static_assert(offsetof(ccBoss0610MssState, field_0070) == 0x0070, "ccBoss0610MssState field_0070 @ 0x0070");
static_assert(offsetof(ccBoss0610MssState, field_0078) == 0x0078, "ccBoss0610MssState field_0078 @ 0x0078");
static_assert(offsetof(ccBoss0610MssState, field_0080) == 0x0080, "ccBoss0610MssState field_0080 @ 0x0080");
static_assert(offsetof(ccBoss0610MssState, field_0088) == 0x0088, "ccBoss0610MssState field_0088 @ 0x0088");
static_assert(offsetof(ccBoss0610MssState, field_0090) == 0x0090, "ccBoss0610MssState field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610MssState, pad_0094) == 0x0094, "ccBoss0610MssState pad @ 0x0094");

/*
 * ccBoss0610Susanoo
 * Methods: 23
 * Object size: >= 0xB388 (45960 bytes) — >= 0xB384 (max accessed), aligned 0xB388
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610Susanoo {
    /* 0x0000 */ uint8_t pad_0000[512];
    /* 0x0200 */ uint64_t field_0200;
    /* 0x0208 */ uint8_t pad_0208[1960];
    /* 0x09B0 */ uint32_t field_09B0;
    /* 0x09B4 */ uint8_t pad_09B4[25932];
    /* 0x6F00 */ uint64_t field_6F00;
    /* 0x6F08 */ uint8_t pad_6F08[4352];
    /* 0x8008 */ uint64_t field_8008;
    /* 0x8010 */ uint64_t field_8010;
    /* 0x8018 */ uint8_t pad_8018[32];
    /* 0x8038 */ uint64_t field_8038;
    /* 0x8040 */ uint8_t pad_8040[16];
    /* 0x8050 */ uint64_t field_8050;
    /* 0x8058 */ uint8_t pad_8058[36];
    /* 0x807C */ uint32_t field_807C;
    /* 0x8080 */ uint8_t pad_8080[120];
    /* 0x80F8 */ float field_80F8;
    /* 0x80FC */ uint8_t pad_80FC[12120];
    /* 0xB054 */ uint8_t field_B054;
    /* 0xB055 */ uint8_t pad_B055[331];
    /* 0xB1A0 */ uint64_t field_B1A0;
    /* 0xB1A8 */ uint8_t pad_B1A8[28];
    /* 0xB1C4 */ uint64_t field_B1C4;
    /* 0xB1CC */ uint8_t pad_B1CC[16];
    /* 0xB1DC */ uint64_t field_B1DC;
    /* 0xB1E4 */ uint8_t pad_B1E4[4];
    /* 0xB1E8 */ uint64_t field_B1E8;
    /* 0xB1F0 */ uint32_t field_B1F0;
    /* 0xB1F4 */ uint64_t field_B1F4;
    /* 0xB1FC */ uint8_t pad_B1FC[352];
    /* 0xB35C */ uint32_t field_B35C;
    /* 0xB360 */ uint64_t field_B360;
    /* 0xB368 */ uint32_t field_B368;
    /* 0xB36C */ uint32_t field_B36C;
    /* 0xB370 */ float field_B370;
    /* 0xB374 */ float field_B374;
    /* 0xB378 */ float field_B378;
    /* 0xB37C */ uint64_t field_B37C;
    /* 0xB384 */ uint8_t pad_B384[4];
} ccBoss0610Susanoo;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610Susanoo, pad_0000) == 0x0000, "ccBoss0610Susanoo pad @ 0x0000");
static_assert(offsetof(ccBoss0610Susanoo, field_0200) == 0x0200, "ccBoss0610Susanoo field_0200 @ 0x0200");
static_assert(offsetof(ccBoss0610Susanoo, pad_0208) == 0x0208, "ccBoss0610Susanoo pad @ 0x0208");
static_assert(offsetof(ccBoss0610Susanoo, field_09B0) == 0x09B0, "ccBoss0610Susanoo field_09B0 @ 0x09B0");
static_assert(offsetof(ccBoss0610Susanoo, pad_09B4) == 0x09B4, "ccBoss0610Susanoo pad @ 0x09B4");
static_assert(offsetof(ccBoss0610Susanoo, field_6F00) == 0x6F00, "ccBoss0610Susanoo field_6F00 @ 0x6F00");
static_assert(offsetof(ccBoss0610Susanoo, pad_6F08) == 0x6F08, "ccBoss0610Susanoo pad @ 0x6F08");
static_assert(offsetof(ccBoss0610Susanoo, field_8008) == 0x8008, "ccBoss0610Susanoo field_8008 @ 0x8008");
static_assert(offsetof(ccBoss0610Susanoo, field_8010) == 0x8010, "ccBoss0610Susanoo field_8010 @ 0x8010");
static_assert(offsetof(ccBoss0610Susanoo, pad_8018) == 0x8018, "ccBoss0610Susanoo pad @ 0x8018");
static_assert(offsetof(ccBoss0610Susanoo, field_8038) == 0x8038, "ccBoss0610Susanoo field_8038 @ 0x8038");
static_assert(offsetof(ccBoss0610Susanoo, pad_8040) == 0x8040, "ccBoss0610Susanoo pad @ 0x8040");
static_assert(offsetof(ccBoss0610Susanoo, field_8050) == 0x8050, "ccBoss0610Susanoo field_8050 @ 0x8050");
static_assert(offsetof(ccBoss0610Susanoo, pad_8058) == 0x8058, "ccBoss0610Susanoo pad @ 0x8058");
static_assert(offsetof(ccBoss0610Susanoo, field_807C) == 0x807C, "ccBoss0610Susanoo field_807C @ 0x807C");
static_assert(offsetof(ccBoss0610Susanoo, pad_8080) == 0x8080, "ccBoss0610Susanoo pad @ 0x8080");
static_assert(offsetof(ccBoss0610Susanoo, field_80F8) == 0x80F8, "ccBoss0610Susanoo field_80F8 @ 0x80F8");
static_assert(offsetof(ccBoss0610Susanoo, pad_80FC) == 0x80FC, "ccBoss0610Susanoo pad @ 0x80FC");
static_assert(offsetof(ccBoss0610Susanoo, field_B054) == 0xB054, "ccBoss0610Susanoo field_B054 @ 0xB054");
static_assert(offsetof(ccBoss0610Susanoo, pad_B055) == 0xB055, "ccBoss0610Susanoo pad @ 0xB055");
static_assert(offsetof(ccBoss0610Susanoo, field_B1A0) == 0xB1A0, "ccBoss0610Susanoo field_B1A0 @ 0xB1A0");
static_assert(offsetof(ccBoss0610Susanoo, pad_B1A8) == 0xB1A8, "ccBoss0610Susanoo pad @ 0xB1A8");
static_assert(offsetof(ccBoss0610Susanoo, field_B1C4) == 0xB1C4, "ccBoss0610Susanoo field_B1C4 @ 0xB1C4");
static_assert(offsetof(ccBoss0610Susanoo, pad_B1CC) == 0xB1CC, "ccBoss0610Susanoo pad @ 0xB1CC");
static_assert(offsetof(ccBoss0610Susanoo, field_B1DC) == 0xB1DC, "ccBoss0610Susanoo field_B1DC @ 0xB1DC");
static_assert(offsetof(ccBoss0610Susanoo, pad_B1E4) == 0xB1E4, "ccBoss0610Susanoo pad @ 0xB1E4");
static_assert(offsetof(ccBoss0610Susanoo, field_B1E8) == 0xB1E8, "ccBoss0610Susanoo field_B1E8 @ 0xB1E8");
static_assert(offsetof(ccBoss0610Susanoo, field_B1F0) == 0xB1F0, "ccBoss0610Susanoo field_B1F0 @ 0xB1F0");
static_assert(offsetof(ccBoss0610Susanoo, field_B1F4) == 0xB1F4, "ccBoss0610Susanoo field_B1F4 @ 0xB1F4");
static_assert(offsetof(ccBoss0610Susanoo, pad_B1FC) == 0xB1FC, "ccBoss0610Susanoo pad @ 0xB1FC");
static_assert(offsetof(ccBoss0610Susanoo, field_B35C) == 0xB35C, "ccBoss0610Susanoo field_B35C @ 0xB35C");
static_assert(offsetof(ccBoss0610Susanoo, field_B360) == 0xB360, "ccBoss0610Susanoo field_B360 @ 0xB360");
static_assert(offsetof(ccBoss0610Susanoo, field_B368) == 0xB368, "ccBoss0610Susanoo field_B368 @ 0xB368");
static_assert(offsetof(ccBoss0610Susanoo, field_B36C) == 0xB36C, "ccBoss0610Susanoo field_B36C @ 0xB36C");
static_assert(offsetof(ccBoss0610Susanoo, field_B370) == 0xB370, "ccBoss0610Susanoo field_B370 @ 0xB370");
static_assert(offsetof(ccBoss0610Susanoo, field_B374) == 0xB374, "ccBoss0610Susanoo field_B374 @ 0xB374");
static_assert(offsetof(ccBoss0610Susanoo, field_B378) == 0xB378, "ccBoss0610Susanoo field_B378 @ 0xB378");
static_assert(offsetof(ccBoss0610Susanoo, field_B37C) == 0xB37C, "ccBoss0610Susanoo field_B37C @ 0xB37C");
static_assert(offsetof(ccBoss0610Susanoo, pad_B384) == 0xB384, "ccBoss0610Susanoo pad @ 0xB384");

/*
 * ccBoss0600ActionState
 * Methods: 21
 * Object size: >= 0xB0 (176 bytes) — >= 0xAC (max accessed), aligned 0xB0
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0600ActionState {
    /* 0x0000 */ uint8_t pad_0000[84];
    /* 0x0054 */ uint32_t field_0054;
    /* 0x0058 */ uint64_t field_0058;
    /* 0x0060 */ uint32_t field_0060;
    /* 0x0064 */ uint8_t pad_0064[4];
    /* 0x0068 */ uint64_t field_0068;
    /* 0x0070 */ uint64_t field_0070;
    /* 0x0078 */ uint8_t pad_0078[4];
    /* 0x007C */ uint64_t field_007C;
    /* 0x0084 */ uint32_t field_0084;
    /* 0x0088 */ uint64_t field_0088;
    /* 0x0090 */ uint32_t field_0090;
    /* 0x0094 */ uint64_t field_0094;
    /* 0x009C */ uint64_t field_009C;
    /* 0x00A4 */ uint64_t field_00A4;
    /* 0x00AC */ uint8_t pad_00AC[4];
} ccBoss0600ActionState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0600ActionState, pad_0000) == 0x0000, "ccBoss0600ActionState pad @ 0x0000");
static_assert(offsetof(ccBoss0600ActionState, field_0054) == 0x0054, "ccBoss0600ActionState field_0054 @ 0x0054");
static_assert(offsetof(ccBoss0600ActionState, field_0058) == 0x0058, "ccBoss0600ActionState field_0058 @ 0x0058");
static_assert(offsetof(ccBoss0600ActionState, field_0060) == 0x0060, "ccBoss0600ActionState field_0060 @ 0x0060");
static_assert(offsetof(ccBoss0600ActionState, pad_0064) == 0x0064, "ccBoss0600ActionState pad @ 0x0064");
static_assert(offsetof(ccBoss0600ActionState, field_0068) == 0x0068, "ccBoss0600ActionState field_0068 @ 0x0068");
static_assert(offsetof(ccBoss0600ActionState, field_0070) == 0x0070, "ccBoss0600ActionState field_0070 @ 0x0070");
static_assert(offsetof(ccBoss0600ActionState, pad_0078) == 0x0078, "ccBoss0600ActionState pad @ 0x0078");
static_assert(offsetof(ccBoss0600ActionState, field_007C) == 0x007C, "ccBoss0600ActionState field_007C @ 0x007C");
static_assert(offsetof(ccBoss0600ActionState, field_0084) == 0x0084, "ccBoss0600ActionState field_0084 @ 0x0084");
static_assert(offsetof(ccBoss0600ActionState, field_0088) == 0x0088, "ccBoss0600ActionState field_0088 @ 0x0088");
static_assert(offsetof(ccBoss0600ActionState, field_0090) == 0x0090, "ccBoss0600ActionState field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0600ActionState, field_0094) == 0x0094, "ccBoss0600ActionState field_0094 @ 0x0094");
static_assert(offsetof(ccBoss0600ActionState, field_009C) == 0x009C, "ccBoss0600ActionState field_009C @ 0x009C");
static_assert(offsetof(ccBoss0600ActionState, field_00A4) == 0x00A4, "ccBoss0600ActionState field_00A4 @ 0x00A4");
static_assert(offsetof(ccBoss0600ActionState, pad_00AC) == 0x00AC, "ccBoss0600ActionState pad @ 0x00AC");

/*
 * ccBoss0610SupportBase
 * Methods: 20
 * Object size: >= 0xB498 (46232 bytes) — >= 0xB498 (max accessed), aligned 0xB498
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610SupportBase {
    /* 0x0000 */ uint8_t pad_0000[2524];
    /* 0x09DC */ uint32_t field_09DC;
    /* 0x09E0 */ uint8_t pad_09E0[26528];
    /* 0x7180 */ uint64_t field_7180;
    /* 0x7188 */ uint8_t pad_7188[56];
    /* 0x71C0 */ uint64_t field_71C0;
    /* 0x71C8 */ uint8_t pad_71C8[696];
    /* 0x7480 */ uint64_t field_7480;
    /* 0x7488 */ uint8_t pad_7488[56];
    /* 0x74C0 */ uint64_t field_74C0;
    /* 0x74C8 */ uint8_t pad_74C8[376];
    /* 0x7640 */ uint64_t field_7640;
    /* 0x7648 */ uint8_t pad_7648[56];
    /* 0x7680 */ uint64_t field_7680;
    /* 0x7688 */ uint8_t pad_7688[56];
    /* 0x76C0 */ uint64_t field_76C0;
    /* 0x76C8 */ uint8_t pad_76C8[14576];
    /* 0xAFB8 */ uint64_t field_AFB8;
    /* 0xAFC0 */ uint8_t pad_AFC0[144];
    /* 0xB050 */ uint32_t field_B050;
    /* 0xB054 */ uint8_t pad_B054[184];
    /* 0xB10C */ uint32_t field_B10C;
    /* 0xB110 */ uint8_t pad_B110[656];
    /* 0xB3A0 */ uint32_t field_B3A0;
    /* 0xB3A4 */ uint8_t pad_B3A4[4];
    /* 0xB3A8 */ uint64_t field_B3A8;
    /* 0xB3B0 */ uint8_t pad_B3B0[80];
    /* 0xB400 */ uint64_t field_B400;
    /* 0xB408 */ uint8_t pad_B408[80];
    /* 0xB458 */ uint64_t field_B458;
    /* 0xB460 */ uint8_t pad_B460[4];
    /* 0xB464 */ uint32_t field_B464;
    /* 0xB468 */ uint64_t field_B468;
    /* 0xB470 */ uint8_t pad_B470[4];
    /* 0xB474 */ uint64_t field_B474;
    /* 0xB47C */ uint8_t pad_B47C[4];
    /* 0xB480 */ uint32_t field_B480;
    /* 0xB484 */ uint64_t field_B484;
    /* 0xB48C */ uint8_t pad_B48C[4];
    /* 0xB490 */ uint32_t field_B490;
    /* 0xB494 */ uint32_t field_B494;
} ccBoss0610SupportBase;

#pragma pack(pop)

static_assert(offsetof(ccBoss0610SupportBase, pad_0000) == 0x0000, "ccBoss0610SupportBase pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0610SupportBase, field_09DC) == 0x09DC, "ccBoss0610SupportBase field_09DC @ 0x09DC");
static_assert(offsetof(ccBoss0610SupportBase, pad_09E0) == 0x09E0, "ccBoss0610SupportBase pad_09E0 @ 0x09E0");
static_assert(offsetof(ccBoss0610SupportBase, field_7180) == 0x7180, "ccBoss0610SupportBase field_7180 @ 0x7180");
static_assert(offsetof(ccBoss0610SupportBase, pad_7188) == 0x7188, "ccBoss0610SupportBase pad_7188 @ 0x7188");
static_assert(offsetof(ccBoss0610SupportBase, field_71C0) == 0x71C0, "ccBoss0610SupportBase field_71C0 @ 0x71C0");
static_assert(offsetof(ccBoss0610SupportBase, pad_71C8) == 0x71C8, "ccBoss0610SupportBase pad_71C8 @ 0x71C8");
static_assert(offsetof(ccBoss0610SupportBase, field_7480) == 0x7480, "ccBoss0610SupportBase field_7480 @ 0x7480");
static_assert(offsetof(ccBoss0610SupportBase, pad_7488) == 0x7488, "ccBoss0610SupportBase pad_7488 @ 0x7488");
static_assert(offsetof(ccBoss0610SupportBase, field_74C0) == 0x74C0, "ccBoss0610SupportBase field_74C0 @ 0x74C0");
static_assert(offsetof(ccBoss0610SupportBase, pad_74C8) == 0x74C8, "ccBoss0610SupportBase pad_74C8 @ 0x74C8");
static_assert(offsetof(ccBoss0610SupportBase, field_7640) == 0x7640, "ccBoss0610SupportBase field_7640 @ 0x7640");
static_assert(offsetof(ccBoss0610SupportBase, pad_7648) == 0x7648, "ccBoss0610SupportBase pad_7648 @ 0x7648");
static_assert(offsetof(ccBoss0610SupportBase, field_7680) == 0x7680, "ccBoss0610SupportBase field_7680 @ 0x7680");
static_assert(offsetof(ccBoss0610SupportBase, pad_7688) == 0x7688, "ccBoss0610SupportBase pad_7688 @ 0x7688");
static_assert(offsetof(ccBoss0610SupportBase, field_76C0) == 0x76C0, "ccBoss0610SupportBase field_76C0 @ 0x76C0");
static_assert(offsetof(ccBoss0610SupportBase, pad_76C8) == 0x76C8, "ccBoss0610SupportBase pad_76C8 @ 0x76C8");
static_assert(offsetof(ccBoss0610SupportBase, field_AFB8) == 0xAFB8, "ccBoss0610SupportBase field_AFB8 @ 0xAFB8");
static_assert(offsetof(ccBoss0610SupportBase, pad_AFC0) == 0xAFC0, "ccBoss0610SupportBase pad_AFC0 @ 0xAFC0");
static_assert(offsetof(ccBoss0610SupportBase, field_B050) == 0xB050, "ccBoss0610SupportBase field_B050 @ 0xB050");
static_assert(offsetof(ccBoss0610SupportBase, pad_B054) == 0xB054, "ccBoss0610SupportBase pad_B054 @ 0xB054");
static_assert(offsetof(ccBoss0610SupportBase, field_B10C) == 0xB10C, "ccBoss0610SupportBase field_B10C @ 0xB10C");
static_assert(offsetof(ccBoss0610SupportBase, pad_B110) == 0xB110, "ccBoss0610SupportBase pad_B110 @ 0xB110");
static_assert(offsetof(ccBoss0610SupportBase, field_B3A0) == 0xB3A0, "ccBoss0610SupportBase field_B3A0 @ 0xB3A0");
static_assert(offsetof(ccBoss0610SupportBase, pad_B3A4) == 0xB3A4, "ccBoss0610SupportBase pad_B3A4 @ 0xB3A4");
static_assert(offsetof(ccBoss0610SupportBase, field_B3A8) == 0xB3A8, "ccBoss0610SupportBase field_B3A8 @ 0xB3A8");
static_assert(offsetof(ccBoss0610SupportBase, pad_B3B0) == 0xB3B0, "ccBoss0610SupportBase pad_B3B0 @ 0xB3B0");
static_assert(offsetof(ccBoss0610SupportBase, field_B400) == 0xB400, "ccBoss0610SupportBase field_B400 @ 0xB400");
static_assert(offsetof(ccBoss0610SupportBase, pad_B408) == 0xB408, "ccBoss0610SupportBase pad_B408 @ 0xB408");
static_assert(offsetof(ccBoss0610SupportBase, field_B458) == 0xB458, "ccBoss0610SupportBase field_B458 @ 0xB458");
static_assert(offsetof(ccBoss0610SupportBase, pad_B460) == 0xB460, "ccBoss0610SupportBase pad_B460 @ 0xB460");
static_assert(offsetof(ccBoss0610SupportBase, field_B464) == 0xB464, "ccBoss0610SupportBase field_B464 @ 0xB464");
static_assert(offsetof(ccBoss0610SupportBase, field_B468) == 0xB468, "ccBoss0610SupportBase field_B468 @ 0xB468");
static_assert(offsetof(ccBoss0610SupportBase, pad_B470) == 0xB470, "ccBoss0610SupportBase pad_B470 @ 0xB470");
static_assert(offsetof(ccBoss0610SupportBase, field_B474) == 0xB474, "ccBoss0610SupportBase field_B474 @ 0xB474");
static_assert(offsetof(ccBoss0610SupportBase, pad_B47C) == 0xB47C, "ccBoss0610SupportBase pad_B47C @ 0xB47C");
static_assert(offsetof(ccBoss0610SupportBase, field_B480) == 0xB480, "ccBoss0610SupportBase field_B480 @ 0xB480");
static_assert(offsetof(ccBoss0610SupportBase, field_B484) == 0xB484, "ccBoss0610SupportBase field_B484 @ 0xB484");
static_assert(offsetof(ccBoss0610SupportBase, pad_B48C) == 0xB48C, "ccBoss0610SupportBase pad_B48C @ 0xB48C");
static_assert(offsetof(ccBoss0610SupportBase, field_B490) == 0xB490, "ccBoss0610SupportBase field_B490 @ 0xB490");
static_assert(offsetof(ccBoss0610SupportBase, field_B494) == 0xB494, "ccBoss0610SupportBase field_B494 @ 0xB494");


/*
 * ccBoss0610Madara
 * Methods: 20
 * Object size: >= 0xB1C0 (45504 bytes) — >= 0xB1C0 (max accessed), aligned 0xB1C0
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610Madara {
    /* 0x0000 */ uint8_t pad_0000[512];
    /* 0x0200 */ uint64_t field_0200;
    /* 0x0208 */ uint8_t pad_0208[1960];
    /* 0x09B0 */ uint32_t field_09B0;
    /* 0x09B4 */ uint32_t field_09B4;
    /* 0x09B8 */ uint8_t pad_09B8[25928];
    /* 0x6F00 */ uint64_t field_6F00;
    /* 0x6F08 */ uint8_t pad_6F08[120];
    /* 0x6F80 */ uint64_t field_6F80;
    /* 0x6F88 */ uint8_t pad_6F88[312];
    /* 0x70C0 */ uint64_t field_70C0;
    /* 0x70C8 */ uint8_t pad_70C8[56];
    /* 0x7100 */ uint64_t field_7100;
    /* 0x7108 */ uint8_t pad_7108[16204];
    /* 0xB054 */ uint8_t field_B054;
    /* 0xB055 */ uint8_t pad_B055[331];
    /* 0xB1A0 */ uint64_t field_B1A0;
    /* 0xB1A8 */ uint32_t field_B1A8;
    /* 0xB1AC */ uint64_t field_B1AC;
    /* 0xB1B4 */ uint32_t field_B1B4;
    /* 0xB1B8 */ uint32_t field_B1B8;
    /* 0xB1BC */ uint32_t field_B1BC;
} ccBoss0610Madara;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610Madara, pad_0000) == 0x0000, "ccBoss0610Madara pad @ 0x0000");
static_assert(offsetof(ccBoss0610Madara, field_0200) == 0x0200, "ccBoss0610Madara field_0200 @ 0x0200");
static_assert(offsetof(ccBoss0610Madara, pad_0208) == 0x0208, "ccBoss0610Madara pad @ 0x0208");
static_assert(offsetof(ccBoss0610Madara, field_09B0) == 0x09B0, "ccBoss0610Madara field_09B0 @ 0x09B0");
static_assert(offsetof(ccBoss0610Madara, field_09B4) == 0x09B4, "ccBoss0610Madara field_09B4 @ 0x09B4");
static_assert(offsetof(ccBoss0610Madara, pad_09B8) == 0x09B8, "ccBoss0610Madara pad @ 0x09B8");
static_assert(offsetof(ccBoss0610Madara, field_6F00) == 0x6F00, "ccBoss0610Madara field_6F00 @ 0x6F00");
static_assert(offsetof(ccBoss0610Madara, pad_6F08) == 0x6F08, "ccBoss0610Madara pad @ 0x6F08");
static_assert(offsetof(ccBoss0610Madara, field_6F80) == 0x6F80, "ccBoss0610Madara field_6F80 @ 0x6F80");
static_assert(offsetof(ccBoss0610Madara, pad_6F88) == 0x6F88, "ccBoss0610Madara pad @ 0x6F88");
static_assert(offsetof(ccBoss0610Madara, field_70C0) == 0x70C0, "ccBoss0610Madara field_70C0 @ 0x70C0");
static_assert(offsetof(ccBoss0610Madara, pad_70C8) == 0x70C8, "ccBoss0610Madara pad @ 0x70C8");
static_assert(offsetof(ccBoss0610Madara, field_7100) == 0x7100, "ccBoss0610Madara field_7100 @ 0x7100");
static_assert(offsetof(ccBoss0610Madara, pad_7108) == 0x7108, "ccBoss0610Madara pad @ 0x7108");
static_assert(offsetof(ccBoss0610Madara, field_B054) == 0xB054, "ccBoss0610Madara field_B054 @ 0xB054");
static_assert(offsetof(ccBoss0610Madara, pad_B055) == 0xB055, "ccBoss0610Madara pad @ 0xB055");
static_assert(offsetof(ccBoss0610Madara, field_B1A0) == 0xB1A0, "ccBoss0610Madara field_B1A0 @ 0xB1A0");
static_assert(offsetof(ccBoss0610Madara, field_B1A8) == 0xB1A8, "ccBoss0610Madara field_B1A8 @ 0xB1A8");
static_assert(offsetof(ccBoss0610Madara, field_B1AC) == 0xB1AC, "ccBoss0610Madara field_B1AC @ 0xB1AC");
static_assert(offsetof(ccBoss0610Madara, field_B1B4) == 0xB1B4, "ccBoss0610Madara field_B1B4 @ 0xB1B4");
static_assert(offsetof(ccBoss0610Madara, field_B1B8) == 0xB1B8, "ccBoss0610Madara field_B1B8 @ 0xB1B8");
static_assert(offsetof(ccBoss0610Madara, field_B1BC) == 0xB1BC, "ccBoss0610Madara field_B1BC @ 0xB1BC");

/*
 * ccBoss0610MadaraFlame
 * Methods: 19
 * Object size: >= 0x2F8 (760 bytes) — >= 0x2F4 (max accessed), aligned 0x2F8
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610MadaraFlame {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint8_t pad_0098[56];
    /* 0x00D0 */ uint32_t field_00D0;
    /* 0x00D4 */ uint8_t pad_00D4[4];
    /* 0x00D8 */ uint64_t field_00D8;
    /* 0x00E0 */ uint32_t field_00E0;
    /* 0x00E4 */ uint32_t field_00E4;
    /* 0x00E8 */ uint32_t field_00E8;
    /* 0x00EC */ uint32_t field_00EC;
    /* 0x00F0 */ uint32_t field_00F0;
    /* 0x00F4 */ uint8_t pad_00F4[4];
    /* 0x00F8 */ uint32_t field_00F8;
    /* 0x00FC */ uint32_t field_00FC;
    /* 0x0100 */ uint64_t field_0100;
    /* 0x0108 */ uint64_t field_0108;
    /* 0x0110 */ uint8_t pad_0110[8];
    /* 0x0118 */ uint64_t field_0118;
    /* 0x0120 */ uint8_t pad_0120[80];
    /* 0x0170 */ uint64_t field_0170;
    /* 0x0178 */ uint8_t pad_0178[4];
    /* 0x017C */ uint64_t field_017C;
    /* 0x0184 */ uint8_t pad_0184[4];
    /* 0x0188 */ uint32_t field_0188;
    /* 0x018C */ uint32_t field_018C;
    /* 0x0190 */ uint32_t field_0190;
    /* 0x0194 */ uint32_t field_0194;
    /* 0x0198 */ uint64_t field_0198;
    /* 0x01A0 */ uint8_t pad_01A0[200];
    /* 0x0268 */ uint64_t field_0268;
    /* 0x0270 */ uint8_t pad_0270[128];
    /* 0x02F0 */ uint32_t field_02F0;
    /* 0x02F4 */ uint8_t pad_02F4[4];
} ccBoss0610MadaraFlame;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610MadaraFlame, pad_0000) == 0x0000, "ccBoss0610MadaraFlame pad @ 0x0000");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0090) == 0x0090, "ccBoss0610MadaraFlame field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_0098) == 0x0098, "ccBoss0610MadaraFlame pad @ 0x0098");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00D0) == 0x00D0, "ccBoss0610MadaraFlame field_00D0 @ 0x00D0");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_00D4) == 0x00D4, "ccBoss0610MadaraFlame pad @ 0x00D4");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00D8) == 0x00D8, "ccBoss0610MadaraFlame field_00D8 @ 0x00D8");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00E0) == 0x00E0, "ccBoss0610MadaraFlame field_00E0 @ 0x00E0");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00E4) == 0x00E4, "ccBoss0610MadaraFlame field_00E4 @ 0x00E4");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00E8) == 0x00E8, "ccBoss0610MadaraFlame field_00E8 @ 0x00E8");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00EC) == 0x00EC, "ccBoss0610MadaraFlame field_00EC @ 0x00EC");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00F0) == 0x00F0, "ccBoss0610MadaraFlame field_00F0 @ 0x00F0");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_00F4) == 0x00F4, "ccBoss0610MadaraFlame pad @ 0x00F4");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00F8) == 0x00F8, "ccBoss0610MadaraFlame field_00F8 @ 0x00F8");
static_assert(offsetof(ccBoss0610MadaraFlame, field_00FC) == 0x00FC, "ccBoss0610MadaraFlame field_00FC @ 0x00FC");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0100) == 0x0100, "ccBoss0610MadaraFlame field_0100 @ 0x0100");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0108) == 0x0108, "ccBoss0610MadaraFlame field_0108 @ 0x0108");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_0110) == 0x0110, "ccBoss0610MadaraFlame pad @ 0x0110");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0118) == 0x0118, "ccBoss0610MadaraFlame field_0118 @ 0x0118");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_0120) == 0x0120, "ccBoss0610MadaraFlame pad @ 0x0120");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0170) == 0x0170, "ccBoss0610MadaraFlame field_0170 @ 0x0170");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_0178) == 0x0178, "ccBoss0610MadaraFlame pad @ 0x0178");
static_assert(offsetof(ccBoss0610MadaraFlame, field_017C) == 0x017C, "ccBoss0610MadaraFlame field_017C @ 0x017C");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_0184) == 0x0184, "ccBoss0610MadaraFlame pad @ 0x0184");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0188) == 0x0188, "ccBoss0610MadaraFlame field_0188 @ 0x0188");
static_assert(offsetof(ccBoss0610MadaraFlame, field_018C) == 0x018C, "ccBoss0610MadaraFlame field_018C @ 0x018C");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0190) == 0x0190, "ccBoss0610MadaraFlame field_0190 @ 0x0190");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0194) == 0x0194, "ccBoss0610MadaraFlame field_0194 @ 0x0194");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0198) == 0x0198, "ccBoss0610MadaraFlame field_0198 @ 0x0198");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_01A0) == 0x01A0, "ccBoss0610MadaraFlame pad @ 0x01A0");
static_assert(offsetof(ccBoss0610MadaraFlame, field_0268) == 0x0268, "ccBoss0610MadaraFlame field_0268 @ 0x0268");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_0270) == 0x0270, "ccBoss0610MadaraFlame pad @ 0x0270");
static_assert(offsetof(ccBoss0610MadaraFlame, field_02F0) == 0x02F0, "ccBoss0610MadaraFlame field_02F0 @ 0x02F0");
static_assert(offsetof(ccBoss0610MadaraFlame, pad_02F4) == 0x02F4, "ccBoss0610MadaraFlame pad @ 0x02F4");

/* ccBoss0600: no instance state detected (0 fields from state_surface) */

/*
 * ccBoss0610SupportTRKG
 * Methods: 13
 * Object size: >= 0xB4B8 (46264 bytes) — >= 0xB4B8 (max accessed), aligned 0xB4B8
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610SupportTRKG {
    /* 0x0000 */ uint8_t pad_0000[2524];
    /* 0x09DC */ uint32_t field_09DC;
    /* 0x09E0 */ uint8_t pad_09E0[25888];
    /* 0x6F00 */ uint64_t field_6F00;
    /* 0x6F08 */ uint8_t pad_6F08[1912];
    /* 0x7680 */ uint64_t field_7680;
    /* 0x7688 */ uint8_t pad_7688[56];
    /* 0x76C0 */ uint64_t field_76C0;
    /* 0x76C8 */ uint8_t pad_76C8[1560];
    /* 0x7CE0 */ uint64_t field_7CE0;
    /* 0x7CE8 */ uint8_t pad_7CE8[360];
    /* 0x7E50 */ uint64_t field_7E50;
    /* 0x7E58 */ uint8_t pad_7E58[12640];
    /* 0xAFB8 */ uint64_t field_AFB8;
    /* 0xAFC0 */ uint8_t pad_AFC0[120];
    /* 0xB038 */ uint64_t field_B038;
    /* 0xB040 */ uint8_t pad_B040[204];
    /* 0xB10C */ uint32_t field_B10C;
    /* 0xB110 */ uint8_t pad_B110[140];
    /* 0xB19C */ float field_B19C;
    /* 0xB1A0 */ uint8_t pad_B1A0[256];
    /* 0xB2A0 */ uint64_t field_B2A0;
    /* 0xB2A8 */ uint8_t pad_B2A8[248];
    /* 0xB3A0 */ uint64_t field_B3A0;
    /* 0xB3A8 */ uint8_t pad_B3A8[240];
    /* 0xB498 */ uint64_t field_B498;
    /* 0xB4A0 */ uint32_t field_B4A0;
    /* 0xB4A4 */ uint64_t field_B4A4;
    /* 0xB4AC */ uint32_t field_B4AC;
    /* 0xB4B0 */ uint32_t field_B4B0;
    /* 0xB4B4 */ uint32_t field_B4B4;
} ccBoss0610SupportTRKG;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610SupportTRKG, pad_0000) == 0x0000, "ccBoss0610SupportTRKG pad @ 0x0000");
static_assert(offsetof(ccBoss0610SupportTRKG, field_09DC) == 0x09DC, "ccBoss0610SupportTRKG field_09DC @ 0x09DC");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_09E0) == 0x09E0, "ccBoss0610SupportTRKG pad @ 0x09E0");
static_assert(offsetof(ccBoss0610SupportTRKG, field_6F00) == 0x6F00, "ccBoss0610SupportTRKG field_6F00 @ 0x6F00");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_6F08) == 0x6F08, "ccBoss0610SupportTRKG pad @ 0x6F08");
static_assert(offsetof(ccBoss0610SupportTRKG, field_7680) == 0x7680, "ccBoss0610SupportTRKG field_7680 @ 0x7680");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_7688) == 0x7688, "ccBoss0610SupportTRKG pad @ 0x7688");
static_assert(offsetof(ccBoss0610SupportTRKG, field_76C0) == 0x76C0, "ccBoss0610SupportTRKG field_76C0 @ 0x76C0");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_76C8) == 0x76C8, "ccBoss0610SupportTRKG pad @ 0x76C8");
static_assert(offsetof(ccBoss0610SupportTRKG, field_7CE0) == 0x7CE0, "ccBoss0610SupportTRKG field_7CE0 @ 0x7CE0");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_7CE8) == 0x7CE8, "ccBoss0610SupportTRKG pad @ 0x7CE8");
static_assert(offsetof(ccBoss0610SupportTRKG, field_7E50) == 0x7E50, "ccBoss0610SupportTRKG field_7E50 @ 0x7E50");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_7E58) == 0x7E58, "ccBoss0610SupportTRKG pad @ 0x7E58");
static_assert(offsetof(ccBoss0610SupportTRKG, field_AFB8) == 0xAFB8, "ccBoss0610SupportTRKG field_AFB8 @ 0xAFB8");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_AFC0) == 0xAFC0, "ccBoss0610SupportTRKG pad @ 0xAFC0");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B038) == 0xB038, "ccBoss0610SupportTRKG field_B038 @ 0xB038");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_B040) == 0xB040, "ccBoss0610SupportTRKG pad @ 0xB040");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B10C) == 0xB10C, "ccBoss0610SupportTRKG field_B10C @ 0xB10C");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_B110) == 0xB110, "ccBoss0610SupportTRKG pad @ 0xB110");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B19C) == 0xB19C, "ccBoss0610SupportTRKG field_B19C @ 0xB19C");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_B1A0) == 0xB1A0, "ccBoss0610SupportTRKG pad @ 0xB1A0");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B2A0) == 0xB2A0, "ccBoss0610SupportTRKG field_B2A0 @ 0xB2A0");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_B2A8) == 0xB2A8, "ccBoss0610SupportTRKG pad @ 0xB2A8");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B3A0) == 0xB3A0, "ccBoss0610SupportTRKG field_B3A0 @ 0xB3A0");
static_assert(offsetof(ccBoss0610SupportTRKG, pad_B3A8) == 0xB3A8, "ccBoss0610SupportTRKG pad @ 0xB3A8");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B498) == 0xB498, "ccBoss0610SupportTRKG field_B498 @ 0xB498");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B4A0) == 0xB4A0, "ccBoss0610SupportTRKG field_B4A0 @ 0xB4A0");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B4A4) == 0xB4A4, "ccBoss0610SupportTRKG field_B4A4 @ 0xB4A4");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B4AC) == 0xB4AC, "ccBoss0610SupportTRKG field_B4AC @ 0xB4AC");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B4B0) == 0xB4B0, "ccBoss0610SupportTRKG field_B4B0 @ 0xB4B0");
static_assert(offsetof(ccBoss0610SupportTRKG, field_B4B4) == 0xB4B4, "ccBoss0610SupportTRKG field_B4B4 @ 0xB4B4");

/*
 * ccBoss0610MagatamaManager
 * Methods: 13
 * Object size: >= 0x138 (312 bytes) — >= 0x134 (max accessed), aligned 0x138
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610MagatamaManager {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint8_t pad_0098[56];
    /* 0x00D0 */ uint32_t field_00D0;
    /* 0x00D4 */ uint8_t pad_00D4[4];
    /* 0x00D8 */ uint64_t field_00D8;
    /* 0x00E0 */ uint32_t field_00E0;
    /* 0x00E4 */ uint32_t field_00E4;
    /* 0x00E8 */ uint32_t field_00E8;
    /* 0x00EC */ uint32_t field_00EC;
    /* 0x00F0 */ uint32_t field_00F0;
    /* 0x00F4 */ uint8_t pad_00F4[4];
    /* 0x00F8 */ uint32_t field_00F8;
    /* 0x00FC */ uint32_t field_00FC;
    /* 0x0100 */ uint64_t field_0100;
    /* 0x0108 */ uint32_t field_0108;
    /* 0x010C */ uint64_t field_010C;
    /* 0x0114 */ uint8_t pad_0114[4];
    /* 0x0118 */ uint64_t field_0118;
    /* 0x0120 */ uint8_t pad_0120[4];
    /* 0x0124 */ uint32_t field_0124;
    /* 0x0128 */ uint32_t field_0128;
    /* 0x012C */ uint8_t pad_012C[4];
    /* 0x0130 */ uint32_t field_0130;
    /* 0x0134 */ uint8_t pad_0134[4];
    /* 0x0138 */ uint8_t pad_0138[448];
    /* 0x02F8 */ uint64_t field_02F8;
    /* 0x0300 */ uint64_t field_0300;
    /* 0x0308 */ uint8_t pad_0308[136];
    /* 0x0390 */ uint64_t field_0390;
    /* 0x0398 */ uint64_t field_0398;
    /* 0x03A0 */ uint8_t pad_03A0[1480];
    /* 0x0968 */ uint64_t field_0968;
    /* 0x0970 */ uint64_t field_0970;
    /* 0x0978 */ uint64_t field_0978;
    /* 0x0980 */ uint32_t field_0980;
    /* 0x0984 */ uint64_t field_0984;
    /* 0x098C */ uint8_t pad_098C[4];
    /* 0x0990 */ uint64_t field_0990;
    /* 0x0998 */ uint8_t pad_0998[4];
    /* 0x099C */ uint64_t field_099C;
    /* 0x09A4 */ uint8_t pad_09A4[4];
    /* 0x09A8 */ uint64_t field_09A8;
    /* 0x09B0 */ uint8_t pad_09B0[80];
    /* 0x0A00 */ uint64_t field_0A00;
    /* 0x0A08 */ uint8_t pad_0A08[80];
    /* 0x0A58 */ uint64_t field_0A58;
    /* 0x0A60 */ uint8_t pad_0A60[4];
    /* 0x0A64 */ uint64_t field_0A64;
    /* 0x0A6C */ uint8_t pad_0A6C[4];
    /* 0x0A70 */ uint64_t field_0A70;
    /* 0x0A78 */ uint8_t pad_0A78[4];
    /* 0x0A7C */ uint32_t field_0A7C;
    /* 0x0A80 */ uint32_t field_0A80;
    /* 0x0A84 */ uint32_t field_0A84;
    /* 0x0A88 */ uint64_t field_0A88;
    /* 0x0A90 */ uint64_t field_0A90;
    /* 0x0A98 */ uint32_t field_0A98;
    /* 0x0A9C */ uint32_t field_0A9C;
    /* 0x0AA0 */ uint64_t field_0AA0;
} ccBoss0610Magatama;

#pragma pack(pop)

static_assert(offsetof(ccBoss0610Magatama, pad_0000) == 0x0000, "ccBoss0610Magatama pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0610Magatama, field_0090) == 0x0090, "ccBoss0610Magatama field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610Magatama, pad_0098) == 0x0098, "ccBoss0610Magatama pad_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610Magatama, field_00D0) == 0x00D0, "ccBoss0610Magatama field_00D0 @ 0x00D0");
static_assert(offsetof(ccBoss0610Magatama, pad_00D4) == 0x00D4, "ccBoss0610Magatama pad_00D4 @ 0x00D4");
static_assert(offsetof(ccBoss0610Magatama, field_00D8) == 0x00D8, "ccBoss0610Magatama field_00D8 @ 0x00D8");
static_assert(offsetof(ccBoss0610Magatama, field_00E0) == 0x00E0, "ccBoss0610Magatama field_00E0 @ 0x00E0");
static_assert(offsetof(ccBoss0610Magatama, field_00E4) == 0x00E4, "ccBoss0610Magatama field_00E4 @ 0x00E4");
static_assert(offsetof(ccBoss0610Magatama, field_00E8) == 0x00E8, "ccBoss0610Magatama field_00E8 @ 0x00E8");
static_assert(offsetof(ccBoss0610Magatama, field_00EC) == 0x00EC, "ccBoss0610Magatama field_00EC @ 0x00EC");
static_assert(offsetof(ccBoss0610Magatama, field_00F0) == 0x00F0, "ccBoss0610Magatama field_00F0 @ 0x00F0");
static_assert(offsetof(ccBoss0610Magatama, pad_00F4) == 0x00F4, "ccBoss0610Magatama pad_00F4 @ 0x00F4");
static_assert(offsetof(ccBoss0610Magatama, field_00F8) == 0x00F8, "ccBoss0610Magatama field_00F8 @ 0x00F8");
static_assert(offsetof(ccBoss0610Magatama, field_00FC) == 0x00FC, "ccBoss0610Magatama field_00FC @ 0x00FC");
static_assert(offsetof(ccBoss0610Magatama, field_0100) == 0x0100, "ccBoss0610Magatama field_0100 @ 0x0100");
static_assert(offsetof(ccBoss0610Magatama, field_0108) == 0x0108, "ccBoss0610Magatama field_0108 @ 0x0108");
static_assert(offsetof(ccBoss0610Magatama, field_010C) == 0x010C, "ccBoss0610Magatama field_010C @ 0x010C");
static_assert(offsetof(ccBoss0610Magatama, pad_0114) == 0x0114, "ccBoss0610Magatama pad_0114 @ 0x0114");
static_assert(offsetof(ccBoss0610Magatama, field_0118) == 0x0118, "ccBoss0610Magatama field_0118 @ 0x0118");
static_assert(offsetof(ccBoss0610Magatama, pad_0120) == 0x0120, "ccBoss0610Magatama pad_0120 @ 0x0120");
static_assert(offsetof(ccBoss0610Magatama, field_0124) == 0x0124, "ccBoss0610Magatama field_0124 @ 0x0124");
static_assert(offsetof(ccBoss0610Magatama, field_0128) == 0x0128, "ccBoss0610Magatama field_0128 @ 0x0128");
static_assert(offsetof(ccBoss0610Magatama, pad_012C) == 0x012C, "ccBoss0610Magatama pad_012C @ 0x012C");
static_assert(offsetof(ccBoss0610Magatama, field_0130) == 0x0130, "ccBoss0610Magatama field_0130 @ 0x0130");
static_assert(offsetof(ccBoss0610Magatama, pad_0134) == 0x0134, "ccBoss0610Magatama pad_0134 @ 0x0134");
static_assert(offsetof(ccBoss0610Magatama, pad_0138) == 0x0138, "ccBoss0610Magatama pad @ 0x0138");
static_assert(offsetof(ccBoss0610Magatama, field_02F8) == 0x02F8, "ccBoss0610Magatama field_02F8 @ 0x02F8");
static_assert(offsetof(ccBoss0610Magatama, field_0300) == 0x0300, "ccBoss0610Magatama field_0300 @ 0x0300");
static_assert(offsetof(ccBoss0610Magatama, pad_0308) == 0x0308, "ccBoss0610Magatama pad_0308 @ 0x0308");
static_assert(offsetof(ccBoss0610Magatama, field_0390) == 0x0390, "ccBoss0610Magatama field_0390 @ 0x0390");
static_assert(offsetof(ccBoss0610Magatama, field_0398) == 0x0398, "ccBoss0610Magatama field_0398 @ 0x0398");
static_assert(offsetof(ccBoss0610Magatama, pad_03A0) == 0x03A0, "ccBoss0610Magatama pad @ 0x03A0");
static_assert(offsetof(ccBoss0610Magatama, field_0968) == 0x0968, "ccBoss0610Magatama field_0968 @ 0x0968");
static_assert(offsetof(ccBoss0610Magatama, field_0970) == 0x0970, "ccBoss0610Magatama field_0970 @ 0x0970");
static_assert(offsetof(ccBoss0610Magatama, field_0978) == 0x0978, "ccBoss0610Magatama field_0978 @ 0x0978");
static_assert(offsetof(ccBoss0610Magatama, field_0980) == 0x0980, "ccBoss0610Magatama field_0980 @ 0x0980");
static_assert(offsetof(ccBoss0610Magatama, field_0984) == 0x0984, "ccBoss0610Magatama field_0984 @ 0x0984");
static_assert(offsetof(ccBoss0610Magatama, pad_098C) == 0x098C, "ccBoss0610Magatama pad @ 0x098C");
static_assert(offsetof(ccBoss0610Magatama, field_0990) == 0x0990, "ccBoss0610Magatama field_0990 @ 0x0990");
static_assert(offsetof(ccBoss0610Magatama, pad_0998) == 0x0998, "ccBoss0610Magatama pad @ 0x0998");
static_assert(offsetof(ccBoss0610Magatama, field_099C) == 0x099C, "ccBoss0610Magatama field_099C @ 0x099C");
static_assert(offsetof(ccBoss0610Magatama, pad_09A4) == 0x09A4, "ccBoss0610Magatama pad @ 0x09A4");
static_assert(offsetof(ccBoss0610Magatama, field_09A8) == 0x09A8, "ccBoss0610Magatama field_09A8 @ 0x09A8");
static_assert(offsetof(ccBoss0610Magatama, pad_09B0) == 0x09B0, "ccBoss0610Magatama pad @ 0x09B0");
static_assert(offsetof(ccBoss0610Magatama, field_0A00) == 0x0A00, "ccBoss0610Magatama field_0A00 @ 0x0A00");
static_assert(offsetof(ccBoss0610Magatama, pad_0A08) == 0x0A08, "ccBoss0610Magatama pad @ 0x0A08");
static_assert(offsetof(ccBoss0610Magatama, field_0A58) == 0x0A58, "ccBoss0610Magatama field_0A58 @ 0x0A58");
static_assert(offsetof(ccBoss0610Magatama, pad_0A60) == 0x0A60, "ccBoss0610Magatama pad @ 0x0A60");
static_assert(offsetof(ccBoss0610Magatama, field_0A64) == 0x0A64, "ccBoss0610Magatama field_0A64 @ 0x0A64");
static_assert(offsetof(ccBoss0610Magatama, pad_0A6C) == 0x0A6C, "ccBoss0610Magatama pad @ 0x0A6C");
static_assert(offsetof(ccBoss0610Magatama, field_0A70) == 0x0A70, "ccBoss0610Magatama field_0A70 @ 0x0A70");
static_assert(offsetof(ccBoss0610Magatama, pad_0A78) == 0x0A78, "ccBoss0610Magatama pad @ 0x0A78");
static_assert(offsetof(ccBoss0610Magatama, field_0A7C) == 0x0A7C, "ccBoss0610Magatama field_0A7C @ 0x0A7C");
static_assert(offsetof(ccBoss0610Magatama, field_0A80) == 0x0A80, "ccBoss0610Magatama field_0A80 @ 0x0A80");
static_assert(offsetof(ccBoss0610Magatama, field_0A84) == 0x0A84, "ccBoss0610Magatama field_0A84 @ 0x0A84");
static_assert(offsetof(ccBoss0610Magatama, field_0A88) == 0x0A88, "ccBoss0610Magatama field_0A88 @ 0x0A88");
static_assert(offsetof(ccBoss0610Magatama, field_0A90) == 0x0A90, "ccBoss0610Magatama field_0A90 @ 0x0A90");
static_assert(offsetof(ccBoss0610Magatama, field_0A98) == 0x0A98, "ccBoss0610Magatama field_0A98 @ 0x0A98");
static_assert(offsetof(ccBoss0610Magatama, field_0A9C) == 0x0A9C, "ccBoss0610Magatama field_0A9C @ 0x0A9C");
static_assert(offsetof(ccBoss0610Magatama, field_0AA0) == 0x0AA0, "ccBoss0610Magatama field_0AA0 @ 0x0AA0");



/*
 * ccBoss0600ExSupportRKG
 * Methods: 10
 * Object size: >= 0xB1C0 (45504 bytes) — >= 0xB1C0 (max accessed), aligned 0xB1C0
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0600ExSupportRKG {
    /* 0x0000 */ uint8_t pad_0000[45472];
    /* 0xB1A0 */ uint32_t field_B1A0;
    /* 0xB1A4 */ uint8_t pad_B1A4[4];
    /* 0xB1A8 */ uint64_t field_B1A8;
    /* 0xB1B0 */ uint32_t field_B1B0;
    /* 0xB1B4 */ uint8_t pad_B1B4[4];
    /* 0xB1B8 */ uint64_t field_B1B8;
    /* 0xB1C0 */ uint64_t field_B1C0;
} ccBoss0600ExSupportRKG;

#pragma pack(pop)

static_assert(offsetof(ccBoss0600ExSupportRKG, pad_0000) == 0x0000, "ccBoss0600ExSupportRKG pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0600ExSupportRKG, field_B1A0) == 0xB1A0, "ccBoss0600ExSupportRKG field_B1A0 @ 0xB1A0");
static_assert(offsetof(ccBoss0600ExSupportRKG, pad_B1A4) == 0xB1A4, "ccBoss0600ExSupportRKG pad_B1A4 @ 0xB1A4");
static_assert(offsetof(ccBoss0600ExSupportRKG, field_B1A8) == 0xB1A8, "ccBoss0600ExSupportRKG field_B1A8 @ 0xB1A8");
static_assert(offsetof(ccBoss0600ExSupportRKG, field_B1B0) == 0xB1B0, "ccBoss0600ExSupportRKG field_B1B0 @ 0xB1B0");
static_assert(offsetof(ccBoss0600ExSupportRKG, pad_B1B4) == 0xB1B4, "ccBoss0600ExSupportRKG pad_B1B4 @ 0xB1B4");
static_assert(offsetof(ccBoss0600ExSupportRKG, field_B1B8) == 0xB1B8, "ccBoss0600ExSupportRKG field_B1B8 @ 0xB1B8");
static_assert(offsetof(ccBoss0600ExSupportRKG, field_B1C0) == 0xB1C0, "ccBoss0600ExSupportRKG field_B1C0 @ 0xB1C0");



/*
 * ccBoss0610SkillSuiryuu
 * Methods: 10
 * Object size: >= 0x380 (896 bytes) — >= 0x380 (max accessed), aligned 0x380
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610SkillSuiryuu {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint64_t field_0098;
    /* 0x00A0 */ uint64_t field_00A0;
    /* 0x00A8 */ uint32_t field_00A8;
    /* 0x00AC */ uint64_t field_00AC;
    /* 0x00B4 */ uint32_t field_00B4;
    /* 0x00B8 */ uint32_t field_00B8;
    /* 0x00BC */ uint32_t field_00BC;
    /* 0x00C0 */ uint32_t field_00C0;
    /* 0x00C4 */ uint8_t pad_00C4[4];
    /* 0x00C8 */ uint64_t field_00C8;
    /* 0x00D0 */ uint8_t pad_00D0[80];
    /* 0x0120 */ uint32_t field_0120;
    /* 0x0124 */ uint32_t field_0124;
    /* 0x0128 */ uint64_t field_0128;
    /* 0x0130 */ uint64_t field_0130;
    /* 0x0138 */ uint32_t field_0138;
    /* 0x013C */ uint32_t field_013C;
    /* 0x0140 */ uint64_t field_0140;
    /* 0x0148 */ uint32_t field_0148;
    /* 0x014C */ uint32_t field_014C;
    /* 0x0150 */ uint32_t field_0150;
    /* 0x0154 */ uint64_t field_0154;
    /* 0x015C */ uint32_t field_015C;
    /* 0x0160 */ uint32_t field_0160;
    /* 0x0164 */ uint32_t field_0164;
    /* 0x0168 */ uint32_t field_0168;
    /* 0x016C */ uint32_t field_016C;
    /* 0x0170 */ uint8_t pad_0170[464];
    /* 0x0340 */ uint64_t field_0340;
    /* 0x0348 */ uint8_t pad_0348[56];
    /* 0x0380 */ uint64_t field_0380;
} ccBoss0610SkillSuiryuu;

#pragma pack(pop)

static_assert(offsetof(ccBoss0610SkillSuiryuu, pad_0000) == 0x0000, "ccBoss0610SkillSuiryuu pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0090) == 0x0090, "ccBoss0610SkillSuiryuu field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0098) == 0x0098, "ccBoss0610SkillSuiryuu field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00A0) == 0x00A0, "ccBoss0610SkillSuiryuu field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00A8) == 0x00A8, "ccBoss0610SkillSuiryuu field_00A8 @ 0x00A8");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00AC) == 0x00AC, "ccBoss0610SkillSuiryuu field_00AC @ 0x00AC");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00B4) == 0x00B4, "ccBoss0610SkillSuiryuu field_00B4 @ 0x00B4");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00B8) == 0x00B8, "ccBoss0610SkillSuiryuu field_00B8 @ 0x00B8");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00BC) == 0x00BC, "ccBoss0610SkillSuiryuu field_00BC @ 0x00BC");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00C0) == 0x00C0, "ccBoss0610SkillSuiryuu field_00C0 @ 0x00C0");
static_assert(offsetof(ccBoss0610SkillSuiryuu, pad_00C4) == 0x00C4, "ccBoss0610SkillSuiryuu pad_00C4 @ 0x00C4");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_00C8) == 0x00C8, "ccBoss0610SkillSuiryuu field_00C8 @ 0x00C8");
static_assert(offsetof(ccBoss0610SkillSuiryuu, pad_00D0) == 0x00D0, "ccBoss0610SkillSuiryuu pad @ 0x00D0");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0120) == 0x0120, "ccBoss0610SkillSuiryuu field_0120 @ 0x0120");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0124) == 0x0124, "ccBoss0610SkillSuiryuu field_0124 @ 0x0124");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0128) == 0x0128, "ccBoss0610SkillSuiryuu field_0128 @ 0x0128");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0130) == 0x0130, "ccBoss0610SkillSuiryuu field_0130 @ 0x0130");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0138) == 0x0138, "ccBoss0610SkillSuiryuu field_0138 @ 0x0138");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_013C) == 0x013C, "ccBoss0610SkillSuiryuu field_013C @ 0x013C");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0140) == 0x0140, "ccBoss0610SkillSuiryuu field_0140 @ 0x0140");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0148) == 0x0148, "ccBoss0610SkillSuiryuu field_0148 @ 0x0148");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_014C) == 0x014C, "ccBoss0610SkillSuiryuu field_014C @ 0x014C");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0150) == 0x0150, "ccBoss0610SkillSuiryuu field_0150 @ 0x0150");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0154) == 0x0154, "ccBoss0610SkillSuiryuu field_0154 @ 0x0154");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_015C) == 0x015C, "ccBoss0610SkillSuiryuu field_015C @ 0x015C");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0160) == 0x0160, "ccBoss0610SkillSuiryuu field_0160 @ 0x0160");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0164) == 0x0164, "ccBoss0610SkillSuiryuu field_0164 @ 0x0164");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0168) == 0x0168, "ccBoss0610SkillSuiryuu field_0168 @ 0x0168");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_016C) == 0x016C, "ccBoss0610SkillSuiryuu field_016C @ 0x016C");
static_assert(offsetof(ccBoss0610SkillSuiryuu, pad_0170) == 0x0170, "ccBoss0610SkillSuiryuu pad_0170 @ 0x0170");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0340) == 0x0340, "ccBoss0610SkillSuiryuu field_0340 @ 0x0340");
static_assert(offsetof(ccBoss0610SkillSuiryuu, pad_0348) == 0x0348, "ccBoss0610SkillSuiryuu pad @ 0x0348");
static_assert(offsetof(ccBoss0610SkillSuiryuu, field_0380) == 0x0380, "ccBoss0610SkillSuiryuu field_0380 @ 0x0380");



/* ccBoss0610SptTRkgState: no instance state detected (0 fields from state_surface) */


/*
 * ccBoss0610TndDmgReaction
 * Methods: 10
 * Object size: >= 0x60 (96 bytes) — >= 0x60 (max accessed), aligned 0x60
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610TndDmgReaction {
    /* 0x0000 */ uint8_t pad_0000[36];
    /* 0x0024 */ uint64_t field_0024;
    /* 0x002C */ uint32_t field_002C;
    /* 0x0030 */ uint8_t pad_0030[40];
    /* 0x0058 */ uint64_t field_0058;
} ccBoss0610TndDmgReaction;

#pragma pack(pop)

static_assert(offsetof(ccBoss0610TndDmgReaction, pad_0000) == 0x0000, "ccBoss0610TndDmgReaction pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0610TndDmgReaction, field_0024) == 0x0024, "ccBoss0610TndDmgReaction field_0024 @ 0x0024");
static_assert(offsetof(ccBoss0610TndDmgReaction, field_002C) == 0x002C, "ccBoss0610TndDmgReaction field_002C @ 0x002C");
static_assert(offsetof(ccBoss0610TndDmgReaction, pad_0030) == 0x0030, "ccBoss0610TndDmgReaction pad_0030 @ 0x0030");
static_assert(offsetof(ccBoss0610TndDmgReaction, field_0058) == 0x0058, "ccBoss0610TndDmgReaction field_0058 @ 0x0058");



/*
 * ccBoss0610TndActKickState
 * Methods: 9
 * Object size: >= 0x170 (368 bytes) — >= 0x16C (max accessed), aligned 0x170
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610TndActKickState {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint8_t pad_0098[56];
    /* 0x00D0 */ uint32_t field_00D0;
    /* 0x00D4 */ uint8_t pad_00D4[4];
    /* 0x00D8 */ uint64_t field_00D8;
    /* 0x00E0 */ uint32_t field_00E0;
    /* 0x00E4 */ uint32_t field_00E4;
    /* 0x00E8 */ uint64_t field_00E8;
    /* 0x00F0 */ uint32_t field_00F0;
    /* 0x00F4 */ uint8_t pad_00F4[4];
    /* 0x00F8 */ uint64_t field_00F8;
    /* 0x0100 */ uint64_t field_0100;
    /* 0x0108 */ uint8_t pad_0108[40];
    /* 0x0130 */ uint64_t field_0130;
    /* 0x0138 */ uint8_t pad_0138[4];
    /* 0x013C */ uint32_t field_013C;
    /* 0x0140 */ uint8_t pad_0140[8];
    /* 0x0148 */ uint64_t field_0148;
    /* 0x0150 */ uint32_t field_0150;
    /* 0x0154 */ uint32_t field_0154;
    /* 0x0158 */ uint32_t field_0158;
    /* 0x015C */ uint64_t field_015C;
    /* 0x0164 */ uint8_t pad_0164[4];
    /* 0x0168 */ uint32_t field_0168;
    /* 0x016C */ uint8_t pad_016C[4];
} ccBoss0610TndActKickState;

#pragma pack(pop)

static_assert(offsetof(ccBoss0610TndActKickState, pad_0000) == 0x0000, "ccBoss0610TndActKickState pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0610TndActKickState, field_0090) == 0x0090, "ccBoss0610TndActKickState field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610TndActKickState, pad_0098) == 0x0098, "ccBoss0610TndActKickState pad_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610TndActKickState, field_00D0) == 0x00D0, "ccBoss0610TndActKickState field_00D0 @ 0x00D0");
static_assert(offsetof(ccBoss0610TndActKickState, pad_00D4) == 0x00D4, "ccBoss0610TndActKickState pad_00D4 @ 0x00D4");
static_assert(offsetof(ccBoss0610TndActKickState, field_00D8) == 0x00D8, "ccBoss0610TndActKickState field_00D8 @ 0x00D8");
static_assert(offsetof(ccBoss0610TndActKickState, field_00E0) == 0x00E0, "ccBoss0610TndActKickState field_00E0 @ 0x00E0");
static_assert(offsetof(ccBoss0610TndActKickState, field_00E4) == 0x00E4, "ccBoss0610TndActKickState field_00E4 @ 0x00E4");
static_assert(offsetof(ccBoss0610TndActKickState, field_00E8) == 0x00E8, "ccBoss0610TndActKickState field_00E8 @ 0x00E8");
static_assert(offsetof(ccBoss0610TndActKickState, field_00F0) == 0x00F0, "ccBoss0610TndActKickState field_00F0 @ 0x00F0");
static_assert(offsetof(ccBoss0610TndActKickState, pad_00F4) == 0x00F4, "ccBoss0610TndActKickState pad_00F4 @ 0x00F4");
static_assert(offsetof(ccBoss0610TndActKickState, field_00F8) == 0x00F8, "ccBoss0610TndActKickState field_00F8 @ 0x00F8");
static_assert(offsetof(ccBoss0610TndActKickState, field_0100) == 0x0100, "ccBoss0610TndActKickState field_0100 @ 0x0100");
static_assert(offsetof(ccBoss0610TndActKickState, pad_0108) == 0x0108, "ccBoss0610TndActKickState pad @ 0x0108");
static_assert(offsetof(ccBoss0610TndActKickState, field_0130) == 0x0130, "ccBoss0610TndActKickState field_0130 @ 0x0130");
static_assert(offsetof(ccBoss0610TndActKickState, pad_0138) == 0x0138, "ccBoss0610TndActKickState pad @ 0x0138");
static_assert(offsetof(ccBoss0610TndActKickState, field_013C) == 0x013C, "ccBoss0610TndActKickState field_013C @ 0x013C");
static_assert(offsetof(ccBoss0610TndActKickState, pad_0140) == 0x0140, "ccBoss0610TndActKickState pad_0140 @ 0x0140");
static_assert(offsetof(ccBoss0610TndActKickState, field_0148) == 0x0148, "ccBoss0610TndActKickState field_0148 @ 0x0148");
static_assert(offsetof(ccBoss0610TndActKickState, field_0150) == 0x0150, "ccBoss0610TndActKickState field_0150 @ 0x0150");
static_assert(offsetof(ccBoss0610TndActKickState, field_0154) == 0x0154, "ccBoss0610TndActKickState field_0154 @ 0x0154");
static_assert(offsetof(ccBoss0610TndActKickState, field_0158) == 0x0158, "ccBoss0610TndActKickState field_0158 @ 0x0158");
static_assert(offsetof(ccBoss0610TndActKickState, field_015C) == 0x015C, "ccBoss0610TndActKickState field_015C @ 0x015C");
static_assert(offsetof(ccBoss0610TndActKickState, pad_0164) == 0x0164, "ccBoss0610TndActKickState pad @ 0x0164");
static_assert(offsetof(ccBoss0610TndActKickState, field_0168) == 0x0168, "ccBoss0610TndActKickState field_0168 @ 0x0168");
static_assert(offsetof(ccBoss0610TndActKickState, pad_016C) == 0x016C, "ccBoss0610TndActKickState pad_016C @ 0x016C");



/*
 * ccBoss06SkillManager
 * Methods: 9
 * Object size: >= 0x110 (272 bytes) — >= 0x10C (max accessed), aligned 0x110
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss06SkillManager {
    /* 0x0000 */ uint8_t pad_0000[120];
    /* 0x0078 */ uint64_t field_0078;
    /* 0x0080 */ uint64_t field_0080;
    /* 0x0088 */ uint64_t field_0088;
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint64_t field_0098;
    /* 0x00A0 */ uint8_t pad_00A0[16];
    /* 0x00B0 */ uint64_t field_00B0;
    /* 0x00B8 */ uint8_t pad_00B8[80];
    /* 0x0108 */ uint32_t field_0108;
    /* 0x010C */ uint8_t pad_010C[4];
} ccBoss06SkillManager;

#pragma pack(pop)

static_assert(offsetof(ccBoss06SkillManager, pad_0000) == 0x0000, "ccBoss06SkillManager pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss06SkillManager, field_0078) == 0x0078, "ccBoss06SkillManager field_0078 @ 0x0078");
static_assert(offsetof(ccBoss06SkillManager, field_0080) == 0x0080, "ccBoss06SkillManager field_0080 @ 0x0080");
static_assert(offsetof(ccBoss06SkillManager, field_0088) == 0x0088, "ccBoss06SkillManager field_0088 @ 0x0088");
static_assert(offsetof(ccBoss06SkillManager, field_0090) == 0x0090, "ccBoss06SkillManager field_0090 @ 0x0090");
static_assert(offsetof(ccBoss06SkillManager, field_0098) == 0x0098, "ccBoss06SkillManager field_0098 @ 0x0098");
static_assert(offsetof(ccBoss06SkillManager, pad_00A0) == 0x00A0, "ccBoss06SkillManager pad_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss06SkillManager, field_00B0) == 0x00B0, "ccBoss06SkillManager field_00B0 @ 0x00B0");
static_assert(offsetof(ccBoss06SkillManager, pad_00B8) == 0x00B8, "ccBoss06SkillManager pad @ 0x00B8");
static_assert(offsetof(ccBoss06SkillManager, field_0108) == 0x0108, "ccBoss06SkillManager field_0108 @ 0x0108");
static_assert(offsetof(ccBoss06SkillManager, pad_010C) == 0x010C, "ccBoss06SkillManager pad_010C @ 0x010C");



/* ccBoss06EffectManager: no instance state detected (0 fields from state_surface) */


/*
 * ccBoss0600CamOpeEvent00
 * Methods: 8
 * Object size: >= 0x240 (576 bytes) — >= 0x240 (max accessed), aligned 0x240
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0600CamOpeEvent00 {
    /* 0x0000 */ uint8_t pad_0000[108];
    /* 0x006C */ uint32_t field_006C;
    /* 0x0070 */ uint8_t pad_0070[144];
    /* 0x0100 */ uint64_t field_0100;
    /* 0x0108 */ uint8_t pad_0108[312];
    /* 0x0240 */ uint64_t field_0240;
} ccBoss0600CamOpeEvent00;

#pragma pack(pop)

static_assert(offsetof(ccBoss0600CamOpeEvent00, pad_0000) == 0x0000, "ccBoss0600CamOpeEvent00 pad_0000 @ 0x0000");
static_assert(offsetof(ccBoss0600CamOpeEvent00, field_006C) == 0x006C, "ccBoss0600CamOpeEvent00 field_006C @ 0x006C");
static_assert(offsetof(ccBoss0600CamOpeEvent00, pad_0070) == 0x0070, "ccBoss0600CamOpeEvent00 pad_0070 @ 0x0070");
static_assert(offsetof(ccBoss0600CamOpeEvent00, field_0100) == 0x0100, "ccBoss0600CamOpeEvent00 field_0100 @ 0x0100");
static_assert(offsetof(ccBoss0600CamOpeEvent00, pad_0108) == 0x0108, "ccBoss0600CamOpeEvent00 pad @ 0x0108");
static_assert(offsetof(ccBoss0600CamOpeEvent00, field_0240) == 0x0240, "ccBoss0600CamOpeEvent00 field_0240 @ 0x0240");



/* ccBoss0600SkillFallWood: no instance state detected (0 fields from state_surface) */


/* ccBoss0610SequenceState: no instance state detected (0 fields from state_surface) */

/* ===== BATCH 3 (coverage) ===== */


/* ccBoss0610MdrActChibakuState: no instance state detected (0 fields from state_surface, 8 methods) */


/* ccBoss0610MdrActFlameState: no instance state detected (0 fields from state_surface, 8 methods) */

/*
 * ccBoss0600ExSupportRKGState
 * Methods: 7
 * Object size: >= 0x94 (148 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0600ExSupportRKGState {
    /* 0x0000 */ uint8_t pad_0000[84];
    /* 0x0054 */ uint32_t field_0054;
    /* 0x0058 */ uint64_t field_0058;
    /* 0x0060 */ uint32_t field_0060;
    /* 0x0064 */ uint8_t pad_0064[4];
    /* 0x0068 */ uint64_t field_0068;
    /* 0x0070 */ uint64_t field_0070;
    /* 0x0078 */ uint8_t pad_0078[24];
    /* 0x0090 */ uint32_t field_0090;
} ccBoss0600ExSupportRKGState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0600ExSupportRKGState, pad_0000) == 0x0000, "ccBoss0600ExSupportRKGState pad @ 0x0000");
static_assert(offsetof(ccBoss0600ExSupportRKGState, field_0054) == 0x0054, "ccBoss0600ExSupportRKGState field_0054 @ 0x0054");
static_assert(offsetof(ccBoss0600ExSupportRKGState, field_0058) == 0x0058, "ccBoss0600ExSupportRKGState field_0058 @ 0x0058");
static_assert(offsetof(ccBoss0600ExSupportRKGState, field_0060) == 0x0060, "ccBoss0600ExSupportRKGState field_0060 @ 0x0060");
static_assert(offsetof(ccBoss0600ExSupportRKGState, pad_0064) == 0x0064, "ccBoss0600ExSupportRKGState pad @ 0x0064");
static_assert(offsetof(ccBoss0600ExSupportRKGState, field_0068) == 0x0068, "ccBoss0600ExSupportRKGState field_0068 @ 0x0068");
static_assert(offsetof(ccBoss0600ExSupportRKGState, field_0070) == 0x0070, "ccBoss0600ExSupportRKGState field_0070 @ 0x0070");
static_assert(offsetof(ccBoss0600ExSupportRKGState, pad_0078) == 0x0078, "ccBoss0600ExSupportRKGState pad @ 0x0078");
static_assert(offsetof(ccBoss0600ExSupportRKGState, field_0090) == 0x0090, "ccBoss0600ExSupportRKGState field_0090 @ 0x0090");

/*
 * ccBoss0600SkillWood
 * Methods: 7
 * Object size: >= 0x27C (636 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0600SkillWood {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint64_t field_0098;
    /* 0x00A0 */ uint64_t field_00A0;
    /* 0x00A8 */ uint32_t field_00A8;
    /* 0x00AC */ uint8_t pad_00AC[8];
    /* 0x00B4 */ uint32_t field_00B4;
    /* 0x00B8 */ uint8_t pad_00B8[28];
    /* 0x00D4 */ uint32_t field_00D4;
    /* 0x00D8 */ uint8_t pad_00D8[80];
    /* 0x0128 */ uint32_t field_0128;
    /* 0x012C */ uint8_t pad_012C[212];
    /* 0x0200 */ uint32_t field_0200;
    /* 0x0204 */ uint64_t field_0204;
    /* 0x020C */ uint32_t field_020C;
    /* 0x0210 */ uint8_t pad_0210[88];
    /* 0x0268 */ uint32_t field_0268;
    /* 0x026C */ uint32_t field_026C;
    /* 0x0270 */ uint32_t field_0270;
    /* 0x0274 */ uint32_t field_0274;
    /* 0x0278 */ uint32_t field_0278;
} ccBoss0600SkillWood;
#pragma pack(pop)

static_assert(offsetof(ccBoss0600SkillWood, pad_0000) == 0x0000, "ccBoss0600SkillWood pad @ 0x0000");
static_assert(offsetof(ccBoss0600SkillWood, field_0090) == 0x0090, "ccBoss0600SkillWood field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0600SkillWood, field_0098) == 0x0098, "ccBoss0600SkillWood field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0600SkillWood, field_00A0) == 0x00A0, "ccBoss0600SkillWood field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0600SkillWood, field_00A8) == 0x00A8, "ccBoss0600SkillWood field_00A8 @ 0x00A8");
static_assert(offsetof(ccBoss0600SkillWood, pad_00AC) == 0x00AC, "ccBoss0600SkillWood pad @ 0x00AC");
static_assert(offsetof(ccBoss0600SkillWood, field_00B4) == 0x00B4, "ccBoss0600SkillWood field_00B4 @ 0x00B4");
static_assert(offsetof(ccBoss0600SkillWood, pad_00B8) == 0x00B8, "ccBoss0600SkillWood pad @ 0x00B8");
static_assert(offsetof(ccBoss0600SkillWood, field_00D4) == 0x00D4, "ccBoss0600SkillWood field_00D4 @ 0x00D4");
static_assert(offsetof(ccBoss0600SkillWood, pad_00D8) == 0x00D8, "ccBoss0600SkillWood pad @ 0x00D8");
static_assert(offsetof(ccBoss0600SkillWood, field_0128) == 0x0128, "ccBoss0600SkillWood field_0128 @ 0x0128");
static_assert(offsetof(ccBoss0600SkillWood, pad_012C) == 0x012C, "ccBoss0600SkillWood pad @ 0x012C");
static_assert(offsetof(ccBoss0600SkillWood, field_0200) == 0x0200, "ccBoss0600SkillWood field_0200 @ 0x0200");
static_assert(offsetof(ccBoss0600SkillWood, field_0204) == 0x0204, "ccBoss0600SkillWood field_0204 @ 0x0204");
static_assert(offsetof(ccBoss0600SkillWood, field_020C) == 0x020C, "ccBoss0600SkillWood field_020C @ 0x020C");
static_assert(offsetof(ccBoss0600SkillWood, pad_0210) == 0x0210, "ccBoss0600SkillWood pad @ 0x0210");
static_assert(offsetof(ccBoss0600SkillWood, field_0268) == 0x0268, "ccBoss0600SkillWood field_0268 @ 0x0268");
static_assert(offsetof(ccBoss0600SkillWood, field_026C) == 0x026C, "ccBoss0600SkillWood field_026C @ 0x026C");
static_assert(offsetof(ccBoss0600SkillWood, field_0270) == 0x0270, "ccBoss0600SkillWood field_0270 @ 0x0270");
static_assert(offsetof(ccBoss0600SkillWood, field_0274) == 0x0274, "ccBoss0600SkillWood field_0274 @ 0x0274");
static_assert(offsetof(ccBoss0600SkillWood, field_0278) == 0x0278, "ccBoss0600SkillWood field_0278 @ 0x0278");

/*
 * ccBoss0610CamOpeEvent00
 * Methods: 7
 * Object size: >= 0x1B8 (440 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610CamOpeEvent00 {
    /* 0x0000 */ uint8_t pad_0000[108];
    /* 0x006C */ uint32_t field_006C;
    /* 0x0070 */ uint8_t pad_0070[324];
    /* 0x01B4 */ uint32_t field_01B4;
} ccBoss0610CamOpeEvent00;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610CamOpeEvent00, pad_0000) == 0x0000, "ccBoss0610CamOpeEvent00 pad @ 0x0000");
static_assert(offsetof(ccBoss0610CamOpeEvent00, field_006C) == 0x006C, "ccBoss0610CamOpeEvent00 field_006C @ 0x006C");
static_assert(offsetof(ccBoss0610CamOpeEvent00, pad_0070) == 0x0070, "ccBoss0610CamOpeEvent00 pad @ 0x0070");
static_assert(offsetof(ccBoss0610CamOpeEvent00, field_01B4) == 0x01B4, "ccBoss0610CamOpeEvent00 field_01B4 @ 0x01B4");


/* ccBoss0610EnemyCpu: no instance state detected (0 fields from state_surface, 7 methods) */

/*
 * ccBoss0610PlayerBase
 * Methods: 7
 * Object size: >= 0x9E0 (2528 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610PlayerBase {
    /* 0x0000 */ uint8_t pad_0000[512];
    /* 0x0200 */ uint64_t field_0200;
    /* 0x0208 */ uint8_t pad_0208[2004];
    /* 0x09DC */ uint32_t field_09DC;
} ccBoss0610PlayerBase;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610PlayerBase, pad_0000) == 0x0000, "ccBoss0610PlayerBase pad @ 0x0000");
static_assert(offsetof(ccBoss0610PlayerBase, field_0200) == 0x0200, "ccBoss0610PlayerBase field_0200 @ 0x0200");
static_assert(offsetof(ccBoss0610PlayerBase, pad_0208) == 0x0208, "ccBoss0610PlayerBase pad @ 0x0208");
static_assert(offsetof(ccBoss0610PlayerBase, field_09DC) == 0x09DC, "ccBoss0610PlayerBase field_09DC @ 0x09DC");

/*
 * ccBoss0610MdrSkillChibaku
 * Methods: 7
 * Object size: >= 0x17C (380 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610MdrSkillChibaku {
    /* 0x0000 */ uint8_t pad_0000[348];
    /* 0x015C */ uint64_t field_015C;
    /* 0x0164 */ uint8_t pad_0164[4];
    /* 0x0168 */ uint64_t field_0168;
    /* 0x0170 */ uint64_t field_0170;
    /* 0x0178 */ uint32_t field_0178;
} ccBoss0610MdrSkillChibaku;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610MdrSkillChibaku, pad_0000) == 0x0000, "ccBoss0610MdrSkillChibaku pad @ 0x0000");
static_assert(offsetof(ccBoss0610MdrSkillChibaku, field_015C) == 0x015C, "ccBoss0610MdrSkillChibaku field_015C @ 0x015C");
static_assert(offsetof(ccBoss0610MdrSkillChibaku, pad_0164) == 0x0164, "ccBoss0610MdrSkillChibaku pad @ 0x0164");
static_assert(offsetof(ccBoss0610MdrSkillChibaku, field_0168) == 0x0168, "ccBoss0610MdrSkillChibaku field_0168 @ 0x0168");
static_assert(offsetof(ccBoss0610MdrSkillChibaku, field_0170) == 0x0170, "ccBoss0610MdrSkillChibaku field_0170 @ 0x0170");
static_assert(offsetof(ccBoss0610MdrSkillChibaku, field_0178) == 0x0178, "ccBoss0610MdrSkillChibaku field_0178 @ 0x0178");

/*
 * ccBoss0610MdrState
 * Methods: 7
 * Object size: >= 0xB0 (176 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610MdrState {
    /* 0x0000 */ uint8_t pad_0000[84];
    /* 0x0054 */ uint32_t field_0054;
    /* 0x0058 */ uint64_t field_0058;
    /* 0x0060 */ uint32_t field_0060;
    /* 0x0064 */ uint8_t pad_0064[4];
    /* 0x0068 */ uint64_t field_0068;
    /* 0x0070 */ uint64_t field_0070;
    /* 0x0078 */ uint64_t field_0078;
    /* 0x0080 */ uint64_t field_0080;
    /* 0x0088 */ uint64_t field_0088;
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint64_t field_0098;
    /* 0x00A0 */ uint64_t field_00A0;
    /* 0x00A8 */ uint64_t field_00A8;
} ccBoss0610MdrState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610MdrState, pad_0000) == 0x0000, "ccBoss0610MdrState pad @ 0x0000");
static_assert(offsetof(ccBoss0610MdrState, field_0054) == 0x0054, "ccBoss0610MdrState field_0054 @ 0x0054");
static_assert(offsetof(ccBoss0610MdrState, field_0058) == 0x0058, "ccBoss0610MdrState field_0058 @ 0x0058");
static_assert(offsetof(ccBoss0610MdrState, field_0060) == 0x0060, "ccBoss0610MdrState field_0060 @ 0x0060");
static_assert(offsetof(ccBoss0610MdrState, pad_0064) == 0x0064, "ccBoss0610MdrState pad @ 0x0064");
static_assert(offsetof(ccBoss0610MdrState, field_0068) == 0x0068, "ccBoss0610MdrState field_0068 @ 0x0068");
static_assert(offsetof(ccBoss0610MdrState, field_0070) == 0x0070, "ccBoss0610MdrState field_0070 @ 0x0070");
static_assert(offsetof(ccBoss0610MdrState, field_0078) == 0x0078, "ccBoss0610MdrState field_0078 @ 0x0078");
static_assert(offsetof(ccBoss0610MdrState, field_0080) == 0x0080, "ccBoss0610MdrState field_0080 @ 0x0080");
static_assert(offsetof(ccBoss0610MdrState, field_0088) == 0x0088, "ccBoss0610MdrState field_0088 @ 0x0088");
static_assert(offsetof(ccBoss0610MdrState, field_0090) == 0x0090, "ccBoss0610MdrState field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610MdrState, field_0098) == 0x0098, "ccBoss0610MdrState field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610MdrState, field_00A0) == 0x00A0, "ccBoss0610MdrState field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0610MdrState, field_00A8) == 0x00A8, "ccBoss0610MdrState field_00A8 @ 0x00A8");


/* ccBoss0610TndActChakraChargeState: no instance state detected (0 fields from state_surface, 7 methods) */

/*
 * ccBoss0610TndActComboState
 * Methods: 7
 * Object size: >= 0x144 (324 bytes) — inferred from max field offset+size
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610TndActComboState {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint8_t pad_0098[56];
    /* 0x00D0 */ uint32_t field_00D0;
    /* 0x00D4 */ uint8_t pad_00D4[4];
    /* 0x00D8 */ uint64_t field_00D8;
    /* 0x00E0 */ uint32_t field_00E0;
    /* 0x00E4 */ uint32_t field_00E4;
    /* 0x00E8 */ uint64_t field_00E8;
    /* 0x00F0 */ uint32_t field_00F0;
    /* 0x00F4 */ uint8_t pad_00F4[4];
    /* 0x00F8 */ uint64_t field_00F8;
    /* 0x0100 */ uint64_t field_0100;
    /* 0x0108 */ uint64_t field_0108;
    /* 0x0110 */ uint8_t pad_0110[24];
    /* 0x0128 */ uint64_t field_0128;
    /* 0x0130 */ uint64_t field_0130;
    /* 0x0138 */ uint64_t field_0138;
    /* 0x0140 */ uint32_t field_0140;
} ccBoss0610TndActComboState;
#pragma pack(pop)

static_assert(offsetof(ccBoss0610TndActComboState, pad_0000) == 0x0000, "ccBoss0610TndActComboState pad @ 0x0000");
static_assert(offsetof(ccBoss0610TndActComboState, field_0090) == 0x0090, "ccBoss0610TndActComboState field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610TndActComboState, pad_0098) == 0x0098, "ccBoss0610TndActComboState pad @ 0x0098");
static_assert(offsetof(ccBoss0610TndActComboState, field_00D0) == 0x00D0, "ccBoss0610TndActComboState field_00D0 @ 0x00D0");
static_assert(offsetof(ccBoss0610TndActComboState, pad_00D4) == 0x00D4, "ccBoss0610TndActComboState pad @ 0x00D4");
static_assert(offsetof(ccBoss0610TndActComboState, field_00D8) == 0x00D8, "ccBoss0610TndActComboState field_00D8 @ 0x00D8");
static_assert(offsetof(ccBoss0610TndActComboState, field_00E0) == 0x00E0, "ccBoss0610TndActComboState field_00E0 @ 0x00E0");
static_assert(offsetof(ccBoss0610TndActComboState, field_00E4) == 0x00E4, "ccBoss0610TndActComboState field_00E4 @ 0x00E4");
static_assert(offsetof(ccBoss0610TndActComboState, field_00E8) == 0x00E8, "ccBoss0610TndActComboState field_00E8 @ 0x00E8");
static_assert(offsetof(ccBoss0610TndActComboState, field_00F0) == 0x00F0, "ccBoss0610TndActComboState field_00F0 @ 0x00F0");
static_assert(offsetof(ccBoss0610TndActComboState, pad_00F4) == 0x00F4, "ccBoss0610TndActComboState pad @ 0x00F4");
static_assert(offsetof(ccBoss0610TndActComboState, field_00F8) == 0x00F8, "ccBoss0610TndActComboState field_00F8 @ 0x00F8");
static_assert(offsetof(ccBoss0610TndActComboState, field_0100) == 0x0100, "ccBoss0610TndActComboState field_0100 @ 0x0100");
static_assert(offsetof(ccBoss0610TndActComboState, field_0108) == 0x0108, "ccBoss0610TndActComboState field_0108 @ 0x0108");
static_assert(offsetof(ccBoss0610TndActComboState, pad_0110) == 0x0110, "ccBoss0610TndActComboState pad @ 0x0110");
static_assert(offsetof(ccBoss0610TndActComboState, field_0128) == 0x0128, "ccBoss0610TndActComboState field_0128 @ 0x0128");
static_assert(offsetof(ccBoss0610TndActComboState, field_0130) == 0x0130, "ccBoss0610TndActComboState field_0130 @ 0x0130");
static_assert(offsetof(ccBoss0610TndActComboState, field_0138) == 0x0138, "ccBoss0610TndActComboState field_0138 @ 0x0138");
static_assert(offsetof(ccBoss0610TndActComboState, field_0140) == 0x0140, "ccBoss0610TndActComboState field_0140 @ 0x0140");


/* ccBoss0610TndActGuardState: no instance state detected (0 fields from state_surface, 7 methods) */


/* ============================================================ */
/* Batch 4 coverage — 12 classes                                */
/* ============================================================ */

/* ccBoss06 batch 4: ccBoss0610SkillShotBase — INFERRED from state_surface (12 fields, 6 methods) */
#pragma pack(push, 1)
typedef struct ccBoss0610SkillShotBase {
/* 0x0000 */ uint8_t pad_0000[144];
/* 0x0090 */ uint64_t field_0090;
/* 0x0098 */ uint8_t pad_0098[8];
/* 0x00A0 */ uint64_t field_00A0;
/* 0x00A8 */ uint32_t field_00A8;
/* 0x00AC */ uint8_t pad_00AC[8];
/* 0x00B4 */ uint32_t field_00B4;
/* 0x00B8 */ uint8_t pad_00B8[104];
/* 0x0120 */ uint32_t field_0120;
/* 0x0124 */ uint32_t field_0124;
/* 0x0128 */ uint8_t pad_0128[8];
/* 0x0130 */ uint64_t field_0130;
/* 0x0138 */ uint32_t field_0138;
/* 0x013C */ uint32_t field_013C;
/* 0x0140 */ uint32_t field_0140;
/* 0x0144 */ uint32_t field_0144;
/* 0x0148 */ uint32_t field_0148;
} ccBoss0610SkillShotBase;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610SkillShotBase, field_0090) == 0x0090, "ccBoss0610SkillShotBase.field_0090");
static_assert(offsetof(ccBoss0610SkillShotBase, field_00A0) == 0x00A0, "ccBoss0610SkillShotBase.field_00A0");
static_assert(offsetof(ccBoss0610SkillShotBase, field_00A8) == 0x00A8, "ccBoss0610SkillShotBase.field_00A8");
static_assert(offsetof(ccBoss0610SkillShotBase, field_00B4) == 0x00B4, "ccBoss0610SkillShotBase.field_00B4");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0120) == 0x0120, "ccBoss0610SkillShotBase.field_0120");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0124) == 0x0124, "ccBoss0610SkillShotBase.field_0124");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0130) == 0x0130, "ccBoss0610SkillShotBase.field_0130");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0138) == 0x0138, "ccBoss0610SkillShotBase.field_0138");
static_assert(offsetof(ccBoss0610SkillShotBase, field_013C) == 0x013C, "ccBoss0610SkillShotBase.field_013C");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0140) == 0x0140, "ccBoss0610SkillShotBase.field_0140");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0144) == 0x0144, "ccBoss0610SkillShotBase.field_0144");
static_assert(offsetof(ccBoss0610SkillShotBase, field_0148) == 0x0148, "ccBoss0610SkillShotBase.field_0148");

/* ccBoss0610SptMkgState: no instance state detected (0 fields from state_surface, 6 methods) */

/* ccBoss0610TndActFallState: no instance state detected (0 fields from state_surface, 6 methods) */

/* ccBoss0610TndDmgSmashState: no instance state detected (0 fields from state_surface, 6 methods) */

/* ccBoss06 batch 4: ccBoss0600PlayerMDR — INFERRED from state_surface (1 fields, 6 methods) */
#pragma pack(push, 1)
typedef struct ccBoss0600PlayerMDR {
/* 0x0000 */ uint8_t pad_0000[44984];
/* 0xAFB8 */ uint32_t field_AFB8;
} ccBoss0600PlayerMDR;
#pragma pack(pop)
static_assert(offsetof(ccBoss0600PlayerMDR, field_AFB8) == 0xAFB8, "ccBoss0600PlayerMDR.field_AFB8");

/* ccSceneBoss0610: no instance state detected (0 fields from state_surface, 6 methods) */

/* ccBoss06 batch 4: ccUiBoss0600PlayerGauge — INFERRED from state_surface (7 fields, 6 methods) */
#pragma pack(push, 1)
typedef struct ccUiBoss0600PlayerGauge {
/* 0x0000 */ uint8_t pad_0000[44];
/* 0x002C */ uint32_t field_002C;
/* 0x0030 */ uint32_t field_0030;
/* 0x0034 */ uint32_t field_0034;
/* 0x0038 */ uint64_t field_0038;
/* 0x0040 */ uint8_t pad_0040[480];
/* 0x0220 */ uint64_t field_0220;
/* 0x0228 */ uint64_t field_0228;
/* 0x0230 */ uint64_t field_0230;
} ccUiBoss0600PlayerGauge;
#pragma pack(pop)
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_002C) == 0x002C, "ccUiBoss0600PlayerGauge.field_002C");
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_0030) == 0x0030, "ccUiBoss0600PlayerGauge.field_0030");
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_0034) == 0x0034, "ccUiBoss0600PlayerGauge.field_0034");
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_0038) == 0x0038, "ccUiBoss0600PlayerGauge.field_0038");
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_0220) == 0x0220, "ccUiBoss0600PlayerGauge.field_0220");
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_0228) == 0x0228, "ccUiBoss0600PlayerGauge.field_0228");
static_assert(offsetof(ccUiBoss0600PlayerGauge, field_0230) == 0x0230, "ccUiBoss0600PlayerGauge.field_0230");

/* ccBoss06 batch 4: ccBoss0600SceneChangeState — INFERRED from state_surface (8 fields, 5 methods) */
#pragma pack(push, 1)
typedef struct ccBoss0600SceneChangeState {
/* 0x0000 */ uint8_t pad_0000[84];
/* 0x0054 */ uint32_t field_0054;
/* 0x0058 */ uint64_t field_0058;
/* 0x0060 */ uint32_t field_0060;
/* 0x0064 */ uint8_t pad_0064[4];
/* 0x0068 */ uint64_t field_0068;
/* 0x0070 */ uint64_t field_0070;
/* 0x0078 */ uint64_t field_0078;
/* 0x0080 */ uint64_t field_0080;
/* 0x0088 */ uint32_t field_0088;
} ccBoss0600SceneChangeState;
#pragma pack(pop)
static_assert(offsetof(ccBoss0600SceneChangeState, field_0054) == 0x0054, "ccBoss0600SceneChangeState.field_0054");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0058) == 0x0058, "ccBoss0600SceneChangeState.field_0058");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0060) == 0x0060, "ccBoss0600SceneChangeState.field_0060");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0068) == 0x0068, "ccBoss0600SceneChangeState.field_0068");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0070) == 0x0070, "ccBoss0600SceneChangeState.field_0070");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0078) == 0x0078, "ccBoss0600SceneChangeState.field_0078");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0080) == 0x0080, "ccBoss0600SceneChangeState.field_0080");
static_assert(offsetof(ccBoss0600SceneChangeState, field_0088) == 0x0088, "ccBoss0600SceneChangeState.field_0088");

/* ccBoss06 batch 4: ccBoss0610BossDmgReaction — INFERRED from state_surface (4 fields, 5 methods) */
#pragma pack(push, 1)
typedef struct ccBoss0610BossDmgReaction {
/* 0x0000 */ uint8_t pad_0000[28];
/* 0x001C */ uint32_t field_001C;
/* 0x0020 */ uint8_t pad_0020[4];
/* 0x0024 */ uint32_t field_0024;
/* 0x0028 */ uint8_t pad_0028[4];
/* 0x002C */ uint32_t field_002C;
/* 0x0030 */ uint8_t pad_0030[12];
/* 0x003C */ uint32_t field_003C;
} ccBoss0610BossDmgReaction;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610BossDmgReaction, field_001C) == 0x001C, "ccBoss0610BossDmgReaction.field_001C");
static_assert(offsetof(ccBoss0610BossDmgReaction, field_0024) == 0x0024, "ccBoss0610BossDmgReaction.field_0024");
static_assert(offsetof(ccBoss0610BossDmgReaction, field_002C) == 0x002C, "ccBoss0610BossDmgReaction.field_002C");
static_assert(offsetof(ccBoss0610BossDmgReaction, field_003C) == 0x003C, "ccBoss0610BossDmgReaction.field_003C");

/* ccBoss06 batch 4: ccBoss0610MdrSkillMeteor — INFERRED from state_surface (4 fields, 5 methods) */
#pragma pack(push, 1)
typedef struct ccBoss0610MdrSkillMeteor {
/* 0x0000 */ uint8_t pad_0000[152];
/* 0x0098 */ uint64_t field_0098;
/* 0x00A0 */ uint8_t pad_00A0[8];
/* 0x00A8 */ uint32_t field_00A8;
/* 0x00AC */ uint8_t pad_00AC[124];
/* 0x0128 */ uint32_t field_0128;
/* 0x012C */ uint8_t pad_012C[60];
/* 0x0168 */ uint32_t field_0168;
} ccBoss0610MdrSkillMeteor;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610MdrSkillMeteor, field_0098) == 0x0098, "ccBoss0610MdrSkillMeteor.field_0098");
static_assert(offsetof(ccBoss0610MdrSkillMeteor, field_00A8) == 0x00A8, "ccBoss0610MdrSkillMeteor.field_00A8");
static_assert(offsetof(ccBoss0610MdrSkillMeteor, field_0128) == 0x0128, "ccBoss0610MdrSkillMeteor.field_0128");
static_assert(offsetof(ccBoss0610MdrSkillMeteor, field_0168) == 0x0168, "ccBoss0610MdrSkillMeteor.field_0168");

/* ccBoss0610SptGarState: no instance state detected (0 fields from state_surface, 5 methods) */

/* ccSceneBoss0600Root: no instance state detected (0 fields from state_surface, 5 methods) */

/* ============================================================ */
/* ccBoss06 batch 5 — coverage completion (12 classes)          */
/* ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).  */
/* ============================================================ */

/*
 * ccUiBoss0600PlayerGauge::SpSupport
 * Methods: 5
 * Object size: >= 0x40 (state_surface field extent) — INFERRED
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccUiBoss0600PlayerGauge__SpSupport {
    /* 0x0000 */ uint8_t pad_0000[44];
    /* 0x002C */ uint32_t field_002C;
    /* 0x0030 */ uint32_t field_0030;
    /* 0x0034 */ uint32_t field_0034;
    /* 0x0038 */ uint64_t field_0038;
} ccUiBoss0600PlayerGauge__SpSupport;
#pragma pack(pop)
static_assert(offsetof(ccUiBoss0600PlayerGauge__SpSupport, field_002C) == 0x002C, "ccUiBoss0600PlayerGauge__SpSupport field_002C @ 0x002C");
static_assert(offsetof(ccUiBoss0600PlayerGauge__SpSupport, field_0030) == 0x0030, "ccUiBoss0600PlayerGauge__SpSupport field_0030 @ 0x0030");
static_assert(offsetof(ccUiBoss0600PlayerGauge__SpSupport, field_0034) == 0x0034, "ccUiBoss0600PlayerGauge__SpSupport field_0034 @ 0x0034");
static_assert(offsetof(ccUiBoss0600PlayerGauge__SpSupport, field_0038) == 0x0038, "ccUiBoss0600PlayerGauge__SpSupport field_0038 @ 0x0038");

/*
 * ccBoss0600SkillGroundWood
 * Methods: 4
 * Object size: >= 0x168 (state_surface field extent) — INFERRED
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0600SkillGroundWood {
    /* 0x0000 */ uint8_t pad_0000[144];
    /* 0x0090 */ uint64_t field_0090;
    /* 0x0098 */ uint64_t field_0098;
    /* 0x00A0 */ uint64_t field_00A0;
    /* 0x00A8 */ uint32_t field_00A8;
    /* 0x00AC */ uint8_t pad_00AC[124];
    /* 0x0128 */ uint32_t field_0128;
    /* 0x012C */ uint8_t pad_012C[4];
    /* 0x0130 */ uint32_t field_0130;
    /* 0x0134 */ uint8_t pad_0134[48];
    /* 0x0164 */ uint32_t field_0164;
} ccBoss0600SkillGroundWood;
#pragma pack(pop)
static_assert(offsetof(ccBoss0600SkillGroundWood, field_0090) == 0x0090, "ccBoss0600SkillGroundWood field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0600SkillGroundWood, field_0098) == 0x0098, "ccBoss0600SkillGroundWood field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0600SkillGroundWood, field_00A0) == 0x00A0, "ccBoss0600SkillGroundWood field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0600SkillGroundWood, field_00A8) == 0x00A8, "ccBoss0600SkillGroundWood field_00A8 @ 0x00A8");
static_assert(offsetof(ccBoss0600SkillGroundWood, field_0128) == 0x0128, "ccBoss0600SkillGroundWood field_0128 @ 0x0128");
static_assert(offsetof(ccBoss0600SkillGroundWood, field_0130) == 0x0130, "ccBoss0600SkillGroundWood field_0130 @ 0x0130");
static_assert(offsetof(ccBoss0600SkillGroundWood, field_0164) == 0x0164, "ccBoss0600SkillGroundWood field_0164 @ 0x0164");

/* ccBoss0610SupportMKG: no instance state detected (0 fields from state_surface, 4 methods) */

/* ccBoss0610TndActDashState: no instance state detected (0 fields from state_surface, 4 methods) */

/* ccBoss0600EventSupport: no instance state detected (0 fields from state_surface, 3 methods) */

/* ccBoss0610CamOpeType00: no instance state detected (0 fields from state_surface, 3 methods) */

/*
 * ccBoss0610Stage
 * Methods: 3
 * Object size: >= 0x64 (state_surface field extent) — INFERRED
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610Stage {
    /* 0x0000 */ uint8_t pad_0000[96];
    /* 0x0060 */ uint32_t field_0060;
} ccBoss0610Stage;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610Stage, field_0060) == 0x0060, "ccBoss0610Stage field_0060 @ 0x0060");

/*
 * ccBoss0610MdrSkillShot10
 * Methods: 3
 * Object size: >= 0x15D (state_surface field extent) — INFERRED
 * ALL FIELDS INFERRED from the decompiler cache state_surface (build s3).
 */
#pragma pack(push, 1)
typedef struct ccBoss0610MdrSkillShot10 {
    /* 0x0000 */ uint8_t pad_0000[336];
    /* 0x0150 */ uint8_t field_0150;
    /* 0x0151 */ uint8_t pad_0151[11];
    /* 0x015C */ uint8_t field_015C;
} ccBoss0610MdrSkillShot10;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610MdrSkillShot10, field_0150) == 0x0150, "ccBoss0610MdrSkillShot10 field_0150 @ 0x0150");
static_assert(offsetof(ccBoss0610MdrSkillShot10, field_015C) == 0x015C, "ccBoss0610MdrSkillShot10 field_015C @ 0x015C");

/* ccBoss0610SptSkillSarou: no instance state detected (0 fields from state_surface, 3 methods) */

/* ccBoss0610SupportGAR: no instance state detected (0 fields from state_surface, 3 methods) */

/* ccBoss0610TndActCombo: no instance state detected (0 fields from state_surface, 3 methods) */

/* ccBoss0610TndActMoveState: no instance state detected (0 fields from state_surface, 3 methods) */

/* ========================================================================
 * Batch 6 — coverage expansion (2026-10-19)
 * Classes: ccBoss0610TndActShot10State, ccBoss0610TndSkillShot00,
 *          ccBoss0610TndSkillShot10, ccBoss0610SouzouState,
 *          ccBoss0600PlayerTND, ccUiBoss0610PlayerGauge
 * All fields INFERRED from the decompiler cache state_surface (static analysis).
 * ======================================================================== */

/* ccBoss0610TndActShot10State: no instance state detected (0 fields from state_surface, 3 methods) */

#pragma pack(push, 1)
typedef struct {
    /* 0x0000 */ uint8_t pad_0000[0x90];
    /* 0x0090 */ uint64_t field_0090;           /* w medium Initialize */
    /* 0x0098 */ uint64_t field_0098;           /* rw high Initialize */
    /* 0x00A0 */ uint64_t field_00A0;           /* w medium Initialize */
    /* 0x00A8 */ uint32_t field_00A8;           /* w medium Initialize */
    /* 0x00AC */ uint8_t pad_00AC[8];           /* r low (pointer-sized access, size unknown) */
    /* 0x00B4 */ uint32_t field_00B4;           /* w medium Initialize */
    /* 0x00B8 */ uint8_t pad_00B8[0x68];
    /* 0x0120 */ uint32_t field_0120;           /* w medium Initialize */
    /* 0x0124 */ uint32_t field_0124;           /* w medium Initialize */
    /* 0x0128 */ uint8_t pad_0128[0x258];
    /* 0x0380 */ uint8_t field_0380;            /* r low (vfunc call site, size unknown) */
} ccBoss0610TndSkillShot00;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610TndSkillShot00, field_0090) == 0x0090, "ccBoss0610TndSkillShot00 field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_0098) == 0x0098, "ccBoss0610TndSkillShot00 field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_00A0) == 0x00A0, "ccBoss0610TndSkillShot00 field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_00A8) == 0x00A8, "ccBoss0610TndSkillShot00 field_00A8 @ 0x00A8");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_00B4) == 0x00B4, "ccBoss0610TndSkillShot00 field_00B4 @ 0x00B4");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_0120) == 0x0120, "ccBoss0610TndSkillShot00 field_0120 @ 0x0120");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_0124) == 0x0124, "ccBoss0610TndSkillShot00 field_0124 @ 0x0124");
static_assert(offsetof(ccBoss0610TndSkillShot00, field_0380) == 0x0380, "ccBoss0610TndSkillShot00 field_0380 @ 0x0380");

#pragma pack(push, 1)
typedef struct {
    /* 0x0000 */ uint8_t pad_0000[0x90];
    /* 0x0090 */ uint64_t field_0090;           /* w medium Initialize */
    /* 0x0098 */ uint64_t field_0098;           /* rw high Initialize */
    /* 0x00A0 */ uint64_t field_00A0;           /* w medium Initialize */
    /* 0x00A8 */ uint32_t field_00A8;           /* w medium Initialize */
    /* 0x00AC */ uint8_t pad_00AC[8];           /* r low (pointer-sized access, size unknown) */
    /* 0x00B4 */ uint32_t field_00B4;           /* w medium Initialize */
    /* 0x00B8 */ uint8_t pad_00B8[0x68];
    /* 0x0120 */ uint32_t field_0120;           /* w medium Initialize */
    /* 0x0124 */ uint32_t field_0124;           /* w medium Initialize */
    /* 0x0128 */ uint8_t pad_0128[0x14];
    /* 0x013C */ uint32_t field_013C;           /* w medium Initialize */
    /* 0x0140 */ uint32_t field_0140;           /* w medium Initialize */
    /* 0x0144 */ uint32_t field_0144;           /* w medium Initialize */
    /* 0x0148 */ uint8_t pad_0148[0x238];
    /* 0x0380 */ uint8_t field_0380;            /* r low (vfunc call site, size unknown) */
} ccBoss0610TndSkillShot10;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0090) == 0x0090, "ccBoss0610TndSkillShot10 field_0090 @ 0x0090");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0098) == 0x0098, "ccBoss0610TndSkillShot10 field_0098 @ 0x0098");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_00A0) == 0x00A0, "ccBoss0610TndSkillShot10 field_00A0 @ 0x00A0");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_00A8) == 0x00A8, "ccBoss0610TndSkillShot10 field_00A8 @ 0x00A8");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_00B4) == 0x00B4, "ccBoss0610TndSkillShot10 field_00B4 @ 0x00B4");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0120) == 0x0120, "ccBoss0610TndSkillShot10 field_0120 @ 0x0120");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0124) == 0x0124, "ccBoss0610TndSkillShot10 field_0124 @ 0x0124");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_013C) == 0x013C, "ccBoss0610TndSkillShot10 field_013C @ 0x013C");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0140) == 0x0140, "ccBoss0610TndSkillShot10 field_0140 @ 0x0140");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0144) == 0x0144, "ccBoss0610TndSkillShot10 field_0144 @ 0x0144");
static_assert(offsetof(ccBoss0610TndSkillShot10, field_0380) == 0x0380, "ccBoss0610TndSkillShot10 field_0380 @ 0x0380");

#pragma pack(push, 1)
typedef struct {
    /* 0x0000 */ void* vtable;                  /* dtor sets *param_1 = &PTR_FUN_14092de90 */
    /* 0x0008 */ uint8_t pad_0008[0x68];
    /* 0x0070 */ uint64_t field_0070;           /* w medium ~ccBoss0610SouzouState */
} ccBoss0610SouzouState;
#pragma pack(pop)
static_assert(offsetof(ccBoss0610SouzouState, vtable) == 0x0000, "ccBoss0610SouzouState vtable @ 0x0000");
static_assert(offsetof(ccBoss0610SouzouState, field_0070) == 0x0070, "ccBoss0610SouzouState field_0070 @ 0x0070");

/* ccBoss0600PlayerTND: no instance state detected (0 fields from state_surface, 3 methods) */

/* ccUiBoss0610PlayerGauge: no instance state detected (0 fields from state_surface, 3 methods) */
