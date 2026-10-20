#ifndef S2_BOSS07_H
#define S2_BOSS07_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s2Boss07 - Storm 2 (NSUNS2.exe) boss battle structs for Itachi/Sasuke Susanoo fight
 * Build: s2 (sha 697488011750...)
 * All fields INFERRED from static analysis (state_surface).
 * ccBoss07Player size 0x8750 from factory FUN_1402b658c -> LoadTh(0x8750).
 * ccBoss0703Itachi inherits ccBoss07Player, same size 0x8750.
 * ccBoss0705Sasuke likely inherits ccBoss07Player, same size 0x8750.
 * ccBoss0703SusanooRockObject size 0x1658 from factory FUN_140287358 -> LoadTh(0x1658).
 * Packed struct: no implicit padding, all offsets exact.
 */

#pragma pack(push, 1)

/*
 * ccBoss07Player - base class for Boss 07 (Itachi/Sasuke Susanoo)
 * Object size: 0x8750 bytes
 */
typedef struct ccBoss07Player {
    uint64_t vtable;              /* 0x0000 */
    uint8_t  pad_0008[0x7098];    /* 0x0008 - 0x709F */

    uint64_t vec_field_70A0;      /* 0x70A0 sz=8 rw low */
    uint32_t vec_field_70A8;      /* 0x70A8 sz=4 w medium */
    uint64_t vec_field_70AC;      /* 0x70AC sz=8 rw low */
    uint32_t vec_field_70B4;      /* 0x70B4 sz=4 w medium */
    uint64_t vec_field_70B8;      /* 0x70B8 sz=8 rw low */
    uint32_t vec_field_70C0;      /* 0x70C0 sz=4 w medium */
    uint64_t vec_field_70C4;      /* 0x70C4 sz=8 rw low */
    uint32_t vec_field_70CC;      /* 0x70CC sz=4 w medium */
    uint32_t zero_field_70D0;     /* 0x70D0 sz=4 w medium */
    uint8_t  pad_70D4[4];         /* 0x70D4 */
    uint64_t unk_70D8;            /* 0x70D8 r low */
    uint8_t  pad_70E0[0x50];      /* 0x70E0 - 0x712F */
    uint32_t flags_7130;          /* 0x7130 sz=4 w medium */
    uint8_t  pad_7134[4];         /* 0x7134 */
    uint64_t matrix_field_7138;   /* 0x7138 r low */
    uint8_t  pad_7140[0x38];      /* 0x7140 - 0x7177 */
    uint64_t unk_7178;            /* 0x7178 r low */
    uint8_t  pad_7180[0x50];      /* 0x7180 - 0x71CF */
    uint32_t float_71D0;          /* 0x71D0 sz=4 w medium */
    uint8_t  pad_71D4[4];         /* 0x71D4 */
    uint64_t matrix_field_71D8;   /* 0x71D8 r low */
    uint8_t  pad_71E0[0x38];      /* 0x71E0 - 0x7217 */
    uint64_t unk_7218;            /* 0x7218 r low */
    uint8_t  pad_7220[0x50];      /* 0x7220 - 0x726F */
    uint32_t field_7270;          /* 0x7270 sz=4 w medium */
    uint8_t  remaining_pad[0x14DC]; /* 0x7274 - 0x874F */
} ccBoss07Player;

static_assert(sizeof(ccBoss07Player) == 0x8750, "ccBoss07Player size");
static_assert(offsetof(ccBoss07Player, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccBoss07Player, vec_field_70A0) == 0x70A0, "vec_field_70A0");
static_assert(offsetof(ccBoss07Player, vec_field_70A8) == 0x70A8, "vec_field_70A8");
static_assert(offsetof(ccBoss07Player, vec_field_70AC) == 0x70AC, "vec_field_70AC");
static_assert(offsetof(ccBoss07Player, vec_field_70B4) == 0x70B4, "vec_field_70B4");
static_assert(offsetof(ccBoss07Player, vec_field_70B8) == 0x70B8, "vec_field_70B8");
static_assert(offsetof(ccBoss07Player, vec_field_70C0) == 0x70C0, "vec_field_70C0");
static_assert(offsetof(ccBoss07Player, vec_field_70C4) == 0x70C4, "vec_field_70C4");
static_assert(offsetof(ccBoss07Player, vec_field_70CC) == 0x70CC, "vec_field_70CC");
static_assert(offsetof(ccBoss07Player, zero_field_70D0) == 0x70D0, "zero_field_70D0");
static_assert(offsetof(ccBoss07Player, unk_70D8) == 0x70D8, "unk_70D8");
static_assert(offsetof(ccBoss07Player, flags_7130) == 0x7130, "flags_7130");
static_assert(offsetof(ccBoss07Player, matrix_field_7138) == 0x7138, "matrix_field_7138");
static_assert(offsetof(ccBoss07Player, unk_7178) == 0x7178, "unk_7178");
static_assert(offsetof(ccBoss07Player, float_71D0) == 0x71D0, "float_71D0");
static_assert(offsetof(ccBoss07Player, matrix_field_71D8) == 0x71D8, "matrix_field_71D8");
static_assert(offsetof(ccBoss07Player, unk_7218) == 0x7218, "unk_7218");
static_assert(offsetof(ccBoss07Player, field_7270) == 0x7270, "field_7270");

/*
 * ccBoss0703Itachi - Itachi-specific fields
 * Object size: 0x8750 (inherits ccBoss07Player allocation)
 */
typedef struct ccBoss0703Itachi {
    uint64_t vtable;              /* 0x0000 */
    uint8_t  pad_0008[0x7268];    /* 0x0008 - 0x726F */

    uint32_t field_7270;          /* 0x7270 sz=4 w medium */
    uint32_t damage_flag_7274;    /* 0x7274 sz=4 rw high */
    uint64_t field_7278;          /* 0x7278 sz=8 rw high */
    uint32_t field_7280;          /* 0x7280 sz=4 w high */
    uint32_t field_7284;          /* 0x7284 sz=4 w medium */
    uint32_t field_7288;          /* 0x7288 sz=4 w medium */
    uint64_t vec_728C;            /* 0x728C sz=8 rw low */
    uint32_t vec_7294;            /* 0x7294 sz=4 rw high */
    uint32_t field_7298;          /* 0x7298 sz=4 rw high */
    uint32_t field_729C;          /* 0x729C sz=4 w high */
    uint32_t collision_field_72A0;/* 0x72A0 sz=4 w high */
    uint64_t field_72A4;          /* 0x72A4 sz=8 rw medium */
    uint32_t field_72AC;          /* 0x72AC sz=4 w high */
    uint32_t field_72B0;          /* 0x72B0 sz=4 w high */
    uint8_t  remaining_to_size[0x149C]; /* 0x72B4 - 0x874F */
} ccBoss0703Itachi;

static_assert(sizeof(ccBoss0703Itachi) == 0x8750, "ccBoss0703Itachi size");
static_assert(offsetof(ccBoss0703Itachi, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccBoss0703Itachi, field_7270) == 0x7270, "field_7270");
static_assert(offsetof(ccBoss0703Itachi, damage_flag_7274) == 0x7274, "damage_flag_7274");
static_assert(offsetof(ccBoss0703Itachi, field_7278) == 0x7278, "field_7278");
static_assert(offsetof(ccBoss0703Itachi, field_7280) == 0x7280, "field_7280");
static_assert(offsetof(ccBoss0703Itachi, field_7284) == 0x7284, "field_7284");
static_assert(offsetof(ccBoss0703Itachi, field_7288) == 0x7288, "field_7288");
static_assert(offsetof(ccBoss0703Itachi, vec_728C) == 0x728C, "vec_728C");
static_assert(offsetof(ccBoss0703Itachi, vec_7294) == 0x7294, "vec_7294");
static_assert(offsetof(ccBoss0703Itachi, field_7298) == 0x7298, "field_7298");
static_assert(offsetof(ccBoss0703Itachi, field_729C) == 0x729C, "field_729C");
static_assert(offsetof(ccBoss0703Itachi, collision_field_72A0) == 0x72A0, "collision_field_72A0");
static_assert(offsetof(ccBoss0703Itachi, field_72A4) == 0x72A4, "field_72A4");
static_assert(offsetof(ccBoss0703Itachi, field_72AC) == 0x72AC, "field_72AC");
static_assert(offsetof(ccBoss0703Itachi, field_72B0) == 0x72B0, "field_72B0");

/*
 * ccBoss0705Sasuke - Sasuke-specific fields
 * Object size: 0x8750 (inherits ccBoss07Player allocation)
 */
typedef struct ccBoss0705Sasuke {
    uint64_t vtable;              /* 0x0000 */
    uint8_t  pad_0008[0x7268];    /* 0x0008 - 0x726F */

    uint32_t field_7270;          /* 0x7270 sz=4 w medium */
    uint32_t ctrl_flag_7274;      /* 0x7274 sz=4 w high */
    uint64_t field_7278;          /* 0x7278 sz=8 rw high */
    uint8_t  sasuke_remaining[0x14D0]; /* 0x7280 - 0x874F */
} ccBoss0705Sasuke;

static_assert(sizeof(ccBoss0705Sasuke) == 0x8750, "ccBoss0705Sasuke size");
static_assert(offsetof(ccBoss0705Sasuke, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccBoss0705Sasuke, field_7270) == 0x7270, "field_7270");
static_assert(offsetof(ccBoss0705Sasuke, ctrl_flag_7274) == 0x7274, "ctrl_flag_7274");
static_assert(offsetof(ccBoss0705Sasuke, field_7278) == 0x7278, "field_7278");

/*
 * ccBoss0703SusanooRockObject - smaller object for Susanoo rock mechanics
 * Object size: 0x1658 bytes
 */
typedef struct ccBoss0703SusanooRockObject {
    uint64_t vtable;              /* 0x0000 */
    uint8_t  pad_0008[0x14B0];    /* 0x0008 - 0x14B7 */

    uint64_t field_14B8;          /* 0x14B8 sz=8 rw low */
    uint8_t  pad_14C0[0x90];      /* 0x14C0 - 0x154F */

    uint64_t field_1550;          /* 0x1550 sz=8 w medium */
    uint64_t field_1558;          /* 0x1558 sz=8 w medium */
    uint64_t field_1560;          /* 0x1560 sz=8 rw low */
    uint32_t field_1568;          /* 0x1568 sz=4 w medium */
    uint32_t unk_156C;            /* 0x156C r low */
    uint8_t  pad_1570[8];         /* 0x1570 */
    uint64_t field_1578;          /* 0x1578 sz=8 rw low */
    uint32_t field_1580;          /* 0x1580 sz=4 w medium */
    uint32_t unk_1584;            /* 0x1584 r low */
    uint8_t  pad_1588[0xB0];      /* 0x1588 - 0x1637 */

    uint32_t field_1638;          /* 0x1638 sz=4 w medium */
    uint32_t field_163C;          /* 0x163C sz=4 w medium */
    uint32_t field_1640;          /* 0x1640 sz=4 w medium */
    uint32_t field_1644;          /* 0x1644 sz=4 w medium */
    uint64_t field_1648;          /* 0x1648 sz=8 w medium */
    uint32_t field_1650;          /* 0x1650 sz=4 w medium */
    uint8_t  final_pad[4];        /* 0x1654 - 0x1657 */
} ccBoss0703SusanooRockObject;

static_assert(sizeof(ccBoss0703SusanooRockObject) == 0x1658, "ccBoss0703SusanooRockObject size");
static_assert(offsetof(ccBoss0703SusanooRockObject, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_14B8) == 0x14B8, "field_14B8");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1550) == 0x1550, "field_1550");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1558) == 0x1558, "field_1558");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1560) == 0x1560, "field_1560");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1568) == 0x1568, "field_1568");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1578) == 0x1578, "field_1578");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1580) == 0x1580, "field_1580");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1638) == 0x1638, "field_1638");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_163C) == 0x163C, "field_163C");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1640) == 0x1640, "field_1640");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1644) == 0x1644, "field_1644");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1648) == 0x1648, "field_1648");
static_assert(offsetof(ccBoss0703SusanooRockObject, field_1650) == 0x1650, "field_1650");


/* ============================================================
 * Batch 2 — Additional structs from manual decompile parsing
 * Extracted 2026-10-19 via param_1 byte-offset pattern scan
 * ============================================================ */

/*
 * ccBoss0703Susanoo
 * Object size: 0x72c8 bytes
 * Fields: 22 from decompile analysis
 */
typedef struct ccBoss0703Susanoo {
    uint8_t pad_0000[536]; /* 0x0 - 0x217 */
    uint8_t field_0x218; /* 0x218 refs=24 */
    uint8_t pad_0219[23727]; /* 0x219 - 0x5ec7 */
    uint8_t field_0x5ec8; /* 0x5ec8 refs=1 */
    uint8_t pad_5EC9[7]; /* 0x5ec9 - 0x5ecf */
    uint8_t field_0x5ed0; /* 0x5ed0 refs=3 */
    uint8_t pad_5ED1[127]; /* 0x5ed1 - 0x5f4f */
    uint8_t field_0x5f50; /* 0x5f50 refs=1 */
    uint8_t pad_5F51[7]; /* 0x5f51 - 0x5f57 */
    uint8_t field_0x5f58; /* 0x5f58 refs=3 */
    uint8_t pad_5F59[31]; /* 0x5f59 - 0x5f77 */
    uint8_t field_0x5f78; /* 0x5f78 refs=3 */
    uint8_t pad_5F79[95]; /* 0x5f79 - 0x5fd7 */
    uint8_t field_0x5fd8; /* 0x5fd8 refs=1 */
    uint8_t pad_5FD9[7]; /* 0x5fd9 - 0x5fdf */
    uint8_t field_0x5fe0; /* 0x5fe0 refs=3 */
    uint8_t pad_5FE1[4287]; /* 0x5fe1 - 0x709f */
    uint8_t field_0x70a0; /* 0x70a0 refs=3 */
    uint8_t pad_70A1[3]; /* 0x70a1 - 0x70a3 */
    uint8_t field_0x70a4; /* 0x70a4 refs=2 */
    uint8_t pad_70A5[3]; /* 0x70a5 - 0x70a7 */
    uint8_t field_0x70a8; /* 0x70a8 refs=4 */
    uint8_t pad_70A9[135]; /* 0x70a9 - 0x712f */
    uint8_t field_0x7130; /* 0x7130 refs=15 */
    uint8_t pad_7131[327]; /* 0x7131 - 0x7277 */
    uint8_t field_0x7278; /* 0x7278 refs=4 */
    uint8_t pad_7279[7]; /* 0x7279 - 0x727f */
    uint8_t field_0x7280; /* 0x7280 refs=5 */
    uint8_t pad_7281[7]; /* 0x7281 - 0x7287 */
    uint8_t field_0x7288; /* 0x7288 refs=6 */
    uint8_t pad_7289[7]; /* 0x7289 - 0x728f */
    uint8_t field_0x7290; /* 0x7290 refs=4 */
    uint8_t pad_7291[7]; /* 0x7291 - 0x7297 */
    uint8_t field_0x7298; /* 0x7298 refs=6 */
    uint8_t pad_7299[3]; /* 0x7299 - 0x729b */
    uint8_t field_0x729c; /* 0x729c refs=7 */
    uint8_t pad_729D[3]; /* 0x729d - 0x729f */
    uint8_t field_0x72a0; /* 0x72a0 refs=6 */
    uint8_t pad_72A1[15]; /* 0x72a1 - 0x72af */
    uint8_t field_0x72b0; /* 0x72b0 refs=3 */
    uint8_t pad_72B1[3]; /* 0x72b1 - 0x72b3 */
    uint8_t field_0x72b4; /* 0x72b4 refs=3 */
    uint8_t pad_72B5[3]; /* 0x72b5 - 0x72b7 */
    uint8_t field_0x72b8; /* 0x72b8 refs=1 */
    uint8_t trailing_pad[15]; /* 0x72b9 - 0x72c7 */
} ccBoss0703Susanoo;

static_assert(sizeof(ccBoss0703Susanoo) == 0x72c8, "ccBoss0703Susanoo size");

/*
 * ccBoss0703ItachiActionState
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 8 from decompile analysis
 */
typedef struct ccBoss0703ItachiActionState {
    uint8_t pad_0000[80]; /* 0x0 - 0x4f */
    uint8_t field_0x50; /* 0x50 refs=2 */
    uint8_t pad_0051[3]; /* 0x51 - 0x53 */
    uint8_t field_0x54; /* 0x54 refs=14 */
    uint8_t pad_0055[3]; /* 0x55 - 0x57 */
    uint8_t field_0x58; /* 0x58 refs=2 */
    uint8_t pad_0059[7]; /* 0x59 - 0x5f */
    uint8_t field_0x60; /* 0x60 refs=5 */
    uint8_t pad_0061[566]; /* 0x61 - 0x296 */
    uint8_t field_0x297; /* 0x297 refs=1 */
    uint8_t pad_0298[122]; /* 0x298 - 0x311 */
    uint8_t field_0x312; /* 0x312 refs=2 */
    uint8_t pad_0313[4517]; /* 0x313 - 0x14b7 */
    uint8_t field_0x14b8; /* 0x14b8 refs=3 */
    uint8_t pad_14B9[983]; /* 0x14b9 - 0x188f */
    uint8_t field_0x1890; /* 0x1890 refs=4 */
} ccBoss0703ItachiActionState;

/*
 * ccSceneBoss0701DemoChanger
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 9 from decompile analysis
 */
typedef struct ccSceneBoss0701DemoChanger {
    uint8_t pad_0000[80]; /* 0x0 - 0x4f */
    uint8_t field_0x50; /* 0x50 refs=2 */
    uint8_t pad_0051[3]; /* 0x51 - 0x53 */
    uint8_t field_0x54; /* 0x54 refs=3 */
    uint8_t pad_0055[11]; /* 0x55 - 0x5f */
    uint8_t field_0x60; /* 0x60 refs=3 */
    uint8_t pad_0061[5207]; /* 0x61 - 0x14b7 */
    uint8_t field_0x14b8; /* 0x14b8 refs=1 */
    uint8_t pad_14B9[7]; /* 0x14b9 - 0x14bf */
    uint8_t field_0x14c0; /* 0x14c0 refs=3 */
    uint8_t pad_14C1[31]; /* 0x14c1 - 0x14df */
    uint8_t field_0x14e0; /* 0x14e0 refs=1 */
    uint8_t pad_14E1[7]; /* 0x14e1 - 0x14e7 */
    uint8_t field_0x14e8; /* 0x14e8 refs=3 */
    uint8_t pad_14E9[3]; /* 0x14e9 - 0x14eb */
    uint8_t field_0x14ec; /* 0x14ec refs=7 */
    uint8_t pad_14ED[3]; /* 0x14ed - 0x14ef */
    uint8_t field_0x14f0; /* 0x14f0 refs=1 */
} ccSceneBoss0701DemoChanger;

/*
 * ccSceneBoss07Phase03
 * Object size: 0x70a0 bytes
 * Fields: 19 from decompile analysis
 */
typedef struct ccSceneBoss07Phase03 {
    uint8_t pad_0000[135]; /* 0x0 - 0x86 */
    uint8_t field_0x87; /* 0x87 refs=1 */
    uint8_t pad_0088[160]; /* 0x88 - 0x127 */
    uint8_t field_0x128; /* 0x128 refs=3 */
    uint8_t pad_0129[7]; /* 0x129 - 0x12f */
    uint8_t field_0x130; /* 0x130 refs=3 */
    uint8_t pad_0131[7]; /* 0x131 - 0x137 */
    uint8_t field_0x138; /* 0x138 refs=7 */
    uint8_t pad_0139[7]; /* 0x139 - 0x13f */
    uint8_t field_0x140; /* 0x140 refs=3 */
    uint8_t pad_0141[7]; /* 0x141 - 0x147 */
    uint8_t field_0x148; /* 0x148 refs=7 */
    uint8_t pad_0149[7]; /* 0x149 - 0x14f */
    uint8_t field_0x150; /* 0x150 refs=5 */
    uint8_t pad_0151[7]; /* 0x151 - 0x157 */
    uint8_t field_0x158; /* 0x158 refs=13 */
    uint8_t pad_0159[7]; /* 0x159 - 0x15f */
    uint8_t field_0x160; /* 0x160 refs=8 */
    uint8_t pad_0161[7]; /* 0x161 - 0x167 */
    uint8_t field_0x168; /* 0x168 refs=8 */
    uint8_t pad_0169[7]; /* 0x169 - 0x16f */
    uint8_t field_0x170; /* 0x170 refs=6 */
    uint8_t pad_0171[7]; /* 0x171 - 0x177 */
    uint8_t field_0x178; /* 0x178 refs=5 */
    uint8_t pad_0179[7]; /* 0x179 - 0x17f */
    uint8_t field_0x180; /* 0x180 refs=6 */
    uint8_t pad_0181[7]; /* 0x181 - 0x187 */
    uint8_t field_0x188; /* 0x188 refs=4 */
    uint8_t pad_0189[15]; /* 0x189 - 0x197 */
    uint8_t field_0x198; /* 0x198 refs=6 */
    uint8_t pad_0199[7]; /* 0x199 - 0x19f */
    uint8_t field_0x1a0; /* 0x1a0 refs=6 */
    uint8_t pad_01A1[3]; /* 0x1a1 - 0x1a3 */
    uint8_t field_0x1a4; /* 0x1a4 refs=3 */
    uint8_t pad_01A5[3]; /* 0x1a5 - 0x1a7 */
    uint8_t field_0x1a8; /* 0x1a8 refs=3 */
    uint8_t pad_01A9[3]; /* 0x1a9 - 0x1ab */
    uint8_t field_0x1ac; /* 0x1ac refs=4 */
    uint8_t trailing_pad[28403]; /* 0x1ad - 0x709f */
} ccSceneBoss07Phase03;

static_assert(sizeof(ccSceneBoss07Phase03) == 0x70a0, "ccSceneBoss07Phase03 size");

/*
 * ccSceneBoss07Phase05
 * Object size: 0x14c8 bytes
 * Fields: 24 from decompile analysis
 */
typedef struct ccSceneBoss07Phase05 {
    uint8_t pad_0000[296]; /* 0x0 - 0x127 */
    uint8_t field_0x128; /* 0x128 refs=7 */
    uint8_t pad_0129[7]; /* 0x129 - 0x12f */
    uint8_t field_0x130; /* 0x130 refs=5 */
    uint8_t pad_0131[7]; /* 0x131 - 0x137 */
    uint8_t field_0x138; /* 0x138 refs=15 */
    uint8_t pad_0139[7]; /* 0x139 - 0x13f */
    uint8_t field_0x140; /* 0x140 refs=20 */
    uint8_t pad_0141[7]; /* 0x141 - 0x147 */
    uint8_t field_0x148; /* 0x148 refs=11 */
    uint8_t pad_0149[7]; /* 0x149 - 0x14f */
    uint8_t field_0x150; /* 0x150 refs=5 */
    uint8_t pad_0151[7]; /* 0x151 - 0x157 */
    uint8_t field_0x158; /* 0x158 refs=12 */
    uint8_t pad_0159[7]; /* 0x159 - 0x15f */
    uint8_t field_0x160; /* 0x160 refs=3 */
    uint8_t pad_0161[7]; /* 0x161 - 0x167 */
    uint8_t field_0x168; /* 0x168 refs=3 */
    uint8_t pad_0169[7]; /* 0x169 - 0x16f */
    uint8_t field_0x170; /* 0x170 refs=3 */
    uint8_t pad_0171[7]; /* 0x171 - 0x177 */
    uint8_t field_0x178; /* 0x178 refs=3 */
    uint8_t pad_0179[7]; /* 0x179 - 0x17f */
    uint8_t field_0x180; /* 0x180 refs=4 */
    uint8_t pad_0181[7]; /* 0x181 - 0x187 */
    uint8_t field_0x188; /* 0x188 refs=4 */
    uint8_t pad_0189[15]; /* 0x189 - 0x197 */
    uint8_t field_0x198; /* 0x198 refs=3 */
    uint8_t pad_0199[7]; /* 0x199 - 0x19f */
    uint8_t field_0x1a0; /* 0x1a0 refs=5 */
    uint8_t pad_01A1[7]; /* 0x1a1 - 0x1a7 */
    uint8_t field_0x1a8; /* 0x1a8 refs=5 */
    uint8_t pad_01A9[7]; /* 0x1a9 - 0x1af */
    uint8_t field_0x1b0; /* 0x1b0 refs=1 */
    uint8_t pad_01B1[3]; /* 0x1b1 - 0x1b3 */
    uint8_t field_0x1b4; /* 0x1b4 refs=1 */
    uint8_t pad_01B5[3]; /* 0x1b5 - 0x1b7 */
    uint8_t field_0x1b8; /* 0x1b8 refs=1 */
    uint8_t pad_01B9[3]; /* 0x1b9 - 0x1bb */
    uint8_t field_0x1bc; /* 0x1bc refs=1 */
    uint8_t pad_01BD[3]; /* 0x1bd - 0x1bf */
    uint8_t field_0x1c0; /* 0x1c0 refs=9 */
    uint8_t pad_01C1[39]; /* 0x1c1 - 0x1e7 */
    uint8_t field_0x1e8; /* 0x1e8 refs=4 */
    uint8_t pad_01E9[3]; /* 0x1e9 - 0x1eb */
    uint8_t field_0x1ec; /* 0x1ec refs=4 */
    uint8_t pad_01ED[3]; /* 0x1ed - 0x1ef */
    uint8_t field_0x1f0; /* 0x1f0 refs=3 */
    uint8_t trailing_pad[4823]; /* 0x1f1 - 0x14c7 */
} ccSceneBoss07Phase05;

static_assert(sizeof(ccSceneBoss07Phase05) == 0x14c8, "ccSceneBoss07Phase05 size");

/*
 * ccBoss0703SusanooActionState
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 10 from decompile analysis
 */
typedef struct ccBoss0703SusanooActionState {
    uint8_t pad_0000[80]; /* 0x0 - 0x4f */
    uint8_t field_0x50; /* 0x50 refs=1 */
    uint8_t pad_0051[3]; /* 0x51 - 0x53 */
    uint8_t field_0x54; /* 0x54 refs=13 */
    uint8_t pad_0055[3]; /* 0x55 - 0x57 */
    uint8_t field_0x58; /* 0x58 refs=1 */
    uint8_t pad_0059[7]; /* 0x59 - 0x5f */
    uint8_t field_0x60; /* 0x60 refs=3 */
    uint8_t pad_0061[10527]; /* 0x61 - 0x297f */
    uint8_t field_0x2980; /* 0x2980 refs=2 */
    uint8_t pad_2981[5331]; /* 0x2981 - 0x3e53 */
    uint8_t field_0x3e54; /* 0x3e54 refs=2 */
    uint8_t pad_3E55[15967]; /* 0x3e55 - 0x7cb3 */
    uint8_t field_0x7cb4; /* 0x7cb4 refs=2 */
    uint8_t pad_7CB5[11]; /* 0x7cb5 - 0x7cbf */
    uint8_t field_0x7cc0; /* 0x7cc0 refs=3 */
    uint8_t pad_7CC1[7]; /* 0x7cc1 - 0x7cc7 */
    uint8_t field_0x7cc8; /* 0x7cc8 refs=5 */
    uint8_t pad_7CC9[3]; /* 0x7cc9 - 0x7ccb */
    uint8_t field_0x7ccc; /* 0x7ccc refs=7 */
} ccBoss0703SusanooActionState;

/*
 * ccSceneBoss07Phase01
 * Object size: 0x14f8 bytes
 * Fields: 11 from decompile analysis
 */
typedef struct ccSceneBoss07Phase01 {
    uint8_t pad_0000[296]; /* 0x0 - 0x127 */
    uint8_t field_0x128; /* 0x128 refs=7 */
    uint8_t pad_0129[7]; /* 0x129 - 0x12f */
    uint8_t field_0x130; /* 0x130 refs=6 */
    uint8_t pad_0131[7]; /* 0x131 - 0x137 */
    uint8_t field_0x138; /* 0x138 refs=5 */
    uint8_t pad_0139[7]; /* 0x139 - 0x13f */
    uint8_t field_0x140; /* 0x140 refs=6 */
    uint8_t pad_0141[7]; /* 0x141 - 0x147 */
    uint8_t field_0x148; /* 0x148 refs=5 */
    uint8_t pad_0149[7]; /* 0x149 - 0x14f */
    uint8_t field_0x150; /* 0x150 refs=3 */
    uint8_t pad_0151[3]; /* 0x151 - 0x153 */
    uint8_t field_0x154; /* 0x154 refs=4 */
    uint8_t pad_0155[3]; /* 0x155 - 0x157 */
    uint8_t field_0x158; /* 0x158 refs=4 */
    uint8_t pad_0159[3]; /* 0x159 - 0x15b */
    uint8_t field_0x15c; /* 0x15c refs=3 */
    uint8_t pad_015D[3]; /* 0x15d - 0x15f */
    uint8_t field_0x160; /* 0x160 refs=2 */
    uint8_t pad_0161[3]; /* 0x161 - 0x163 */
    uint8_t field_0x164; /* 0x164 refs=4 */
    uint8_t trailing_pad[5011]; /* 0x165 - 0x14f7 */
} ccSceneBoss07Phase01;

static_assert(sizeof(ccSceneBoss07Phase01) == 0x14f8, "ccSceneBoss07Phase01 size");

/*
 * ccBoss0701SceneChangeState
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 6 from decompile analysis
 */
typedef struct ccBoss0701SceneChangeState {
    uint8_t pad_0000[84]; /* 0x0 - 0x53 */
    uint8_t field_0x54; /* 0x54 refs=3 */
    uint8_t pad_0055[3]; /* 0x55 - 0x57 */
    uint8_t field_0x58; /* 0x58 refs=1 */
    uint8_t pad_0059[7]; /* 0x59 - 0x5f */
    uint8_t field_0x60; /* 0x60 refs=3 */
    uint8_t pad_0061[5207]; /* 0x61 - 0x14b7 */
    uint8_t field_0x14b8; /* 0x14b8 refs=2 */
    uint8_t pad_14B9[3]; /* 0x14b9 - 0x14bb */
    uint8_t field_0x14bc; /* 0x14bc refs=1 */
    uint8_t pad_14BD[7]; /* 0x14bd - 0x14c3 */
    uint8_t field_0x14c4; /* 0x14c4 refs=9 */
} ccBoss0701SceneChangeState;

/*
 * ccBoss0703SusanooShockWave
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 6 from decompile analysis
 */
typedef struct ccBoss0703SusanooShockWave {
    uint8_t pad_0000[152]; /* 0x0 - 0x97 */
    uint8_t field_0x98; /* 0x98 refs=1 */
    uint8_t pad_0099[7]; /* 0x99 - 0x9f */
    uint8_t field_0xa0; /* 0xa0 refs=1 */
    uint8_t pad_00A1[3]; /* 0xa1 - 0xa3 */
    uint8_t field_0xa4; /* 0xa4 refs=5 */
    uint8_t pad_00A5[3]; /* 0xa5 - 0xa7 */
    uint8_t field_0xa8; /* 0xa8 refs=8 */
    uint8_t pad_00A9[7]; /* 0xa9 - 0xaf */
    uint8_t field_0xb0; /* 0xb0 refs=9 */
    uint8_t pad_00B1[7]; /* 0xb1 - 0xb7 */
    uint8_t field_0xb8; /* 0xb8 refs=6 */
} ccBoss0703SusanooShockWave;

/*
 * ccBoss0705Susanoo
 * Object size: 0x7280 bytes
 * Fields: 8 from decompile analysis
 */
typedef struct ccBoss0705Susanoo {
    uint8_t pad_0000[536]; /* 0x0 - 0x217 */
    uint8_t field_0x218; /* 0x218 refs=23 */
    uint8_t pad_0219[23767]; /* 0x219 - 0x5eef */
    uint8_t field_0x5ef0; /* 0x5ef0 refs=1 */
    uint8_t pad_5EF1[95]; /* 0x5ef1 - 0x5f4f */
    uint8_t field_0x5f50; /* 0x5f50 refs=1 */
    uint8_t pad_5F51[7]; /* 0x5f51 - 0x5f57 */
    uint8_t field_0x5f58; /* 0x5f58 refs=3 */
    uint8_t pad_5F59[4423]; /* 0x5f59 - 0x709f */
    uint8_t field_0x70a0; /* 0x70a0 refs=3 */
    uint8_t pad_70A1[7]; /* 0x70a1 - 0x70a7 */
    uint8_t field_0x70a8; /* 0x70a8 refs=4 */
    uint8_t pad_70A9[135]; /* 0x70a9 - 0x712f */
    uint8_t field_0x7130; /* 0x7130 refs=4 */
    uint8_t pad_7131[327]; /* 0x7131 - 0x7277 */
    uint8_t field_0x7278; /* 0x7278 refs=3 */
    uint8_t trailing_pad[7]; /* 0x7279 - 0x727f */
} ccBoss0705Susanoo;

static_assert(sizeof(ccBoss0705Susanoo) == 0x7280, "ccBoss0705Susanoo size");

/*
 * ccSceneBoss0705DemoChanger
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 5 from decompile analysis
 */
typedef struct ccSceneBoss0705DemoChanger {
    uint8_t pad_0000[84]; /* 0x0 - 0x53 */
    uint8_t field_0x54; /* 0x54 refs=3 */
    uint8_t pad_0055[11]; /* 0x55 - 0x5f */
    uint8_t field_0x60; /* 0x60 refs=3 */
    uint8_t pad_0061[5207]; /* 0x61 - 0x14b7 */
    uint8_t field_0x14b8; /* 0x14b8 refs=12 */
    uint8_t pad_14B9[3]; /* 0x14b9 - 0x14bb */
    uint8_t field_0x14bc; /* 0x14bc refs=3 */
    uint8_t pad_14BD[3]; /* 0x14bd - 0x14bf */
    uint8_t field_0x14c0; /* 0x14c0 refs=4 */
} ccSceneBoss0705DemoChanger;

/*
 * ccBoss0701CamOpeBattleStart
 * Object size: UNKNOWN (no Create/ctor allocation found)
 * Fields: 10 from decompile analysis
 */
typedef struct ccBoss0701CamOpeBattleStart {
    uint8_t pad_0000[54]; /* 0x0 - 0x35 */
    uint8_t field_0x36; /* 0x36 refs=1 */
    uint8_t field_0x37; /* 0x37 refs=3 */
    uint8_t pad_0038[11]; /* 0x38 - 0x42 */
    uint8_t field_0x43; /* 0x43 refs=1 */
    uint8_t pad_0044[40]; /* 0x44 - 0x6b */
    uint8_t field_0x6c; /* 0x6c refs=4 */
    uint8_t pad_006D[323]; /* 0x6d - 0x1af */
    uint8_t field_0x1b0; /* 0x1b0 refs=5 */
    uint8_t pad_01B1[3]; /* 0x1b1 - 0x1b3 */
    uint8_t field_0x1b4; /* 0x1b4 refs=7 */
    uint8_t pad_01B5[3]; /* 0x1b5 - 0x1b7 */
    uint8_t field_0x1b8; /* 0x1b8 refs=3 */
    uint8_t pad_01B9[23]; /* 0x1b9 - 0x1cf */
    uint8_t field_0x1d0; /* 0x1d0 refs=2 */
    uint8_t pad_01D1[71]; /* 0x1d1 - 0x217 */
    uint8_t field_0x218; /* 0x218 refs=2 */
    uint8_t pad_0219[3]; /* 0x219 - 0x21b */
    uint8_t field_0x21c; /* 0x21c refs=2 */
} ccBoss0701CamOpeBattleStart;

/* ccBoss0703SasukeAnmDemo: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss0703SusanooActionPattern: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss0705CamOpeType02: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss07Filter: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss0703SceneChangeState: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss0703SusanooRushSlash: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss0703SusanooShellAttack00: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/* ccBoss0703SusanooSwordAttackHit: no instance state found.
 * state_surface returned 0 fields across all methods;
 * only byte-cast accesses (unknown param_1 element size).
 * Likely pure-virtual dispatch helper or stateless functor. */

/*
 * ccBoss0705SasukeActionState
 * Object size: 0x56F8 (from FUN_140580190 allocation arg)
 * Fields: 6 from state_surface (all INFERRED)
 */
typedef struct ccBoss0705SasukeActionState {
    uint8_t pad_0000[5304]; /* 0x0 - 0x14B7 */
    uint64_t field_14B8; /* 0x14B8 sz=8 r conf=low */
    uint8_t pad_14C0[968]; /* 0x14C0 - 0x1887 */
    uint64_t field_1888; /* 0x1888 sz=8 r conf=low */
    uint8_t pad_1890[5320]; /* 0x1890 - 0x2D57 */
    uint64_t field_2D58; /* 0x2D58 sz=8 r conf=low */
    uint8_t pad_2D60[5320]; /* 0x2D60 - 0x4227 */
    uint64_t field_4228; /* 0x4228 sz=8 r conf=low */
    uint8_t pad_4230[5312]; /* 0x4230 - 0x56EF */
    uint32_t field_56F0; /* 0x56F0 sz=4 w conf=medium */
    uint32_t field_56F4; /* 0x56F4 sz=4 w conf=medium */
} ccBoss0705SasukeActionState;
static_assert(sizeof(ccBoss0705SasukeActionState) == 0x56F8, "ccBoss0705SasukeActionState size mismatch");
static_assert(offsetof(ccBoss0705SasukeActionState, field_14B8) == 0x14B8, "ccBoss0705SasukeActionState.field_14B8 offset");
static_assert(offsetof(ccBoss0705SasukeActionState, field_1888) == 0x1888, "ccBoss0705SasukeActionState.field_1888 offset");
static_assert(offsetof(ccBoss0705SasukeActionState, field_2D58) == 0x2D58, "ccBoss0705SasukeActionState.field_2D58 offset");
static_assert(offsetof(ccBoss0705SasukeActionState, field_4228) == 0x4228, "ccBoss0705SasukeActionState.field_4228 offset");
static_assert(offsetof(ccBoss0705SasukeActionState, field_56F0) == 0x56F0, "ccBoss0705SasukeActionState.field_56F0 offset");
static_assert(offsetof(ccBoss0705SasukeActionState, field_56F4) == 0x56F4, "ccBoss0705SasukeActionState.field_56F4 offset");

/*
 * ccBoss0705Itachi
 * Object size: 0x7280 (from FUN_140580190 allocation arg)
 * Fields: 16 from state_surface (all INFERRED)
 */
typedef struct ccBoss0705Itachi {
    uint8_t pad_0000[192]; /* 0x0 - 0xBF */
    uint32_t field_00C0; /* 0xC0 sz=4 rw conf=medium */
    uint8_t pad_00C4[340]; /* 0xC4 - 0x217 */
    uint64_t field_0218; /* 0x218 sz=8 rw conf=medium */
    uint8_t pad_0220[992]; /* 0x220 - 0x5FF */
    uint32_t field_0600; /* 0x600 sz=4 rw conf=medium */
    uint8_t pad_0604[720]; /* 0x604 - 0x8D3 */
    uint32_t field_08D4; /* 0x8D4 sz=4 rw conf=medium */
    uint32_t field_08D8; /* 0x8D8 sz=4 rw conf=medium */
    uint32_t field_08DC; /* 0x8DC sz=4 rw conf=medium */
    uint8_t pad_08E0[13536]; /* 0x8E0 - 0x3DBF */
    uint32_t field_3DC0; /* 0x3DC0 sz=4 rw conf=medium */
    uint8_t pad_3DC4[60]; /* 0x3DC4 - 0x3DFF */
    uint32_t field_3E00; /* 0x3E00 sz=4 rw conf=medium */
    uint8_t pad_3E04[12956]; /* 0x3E04 - 0x709F */
    uint64_t field_70A0; /* 0x70A0 sz=8 rw conf=medium */
    uint64_t field_70A8; /* 0x70A8 sz=8 rw conf=medium */
    uint8_t pad_70B0[8]; /* 0x70B0 - 0x70B7 */
    uint64_t field_70B8; /* 0x70B8 sz=8 rw conf=medium */
    uint64_t field_70C0; /* 0x70C0 sz=8 rw conf=medium */
    uint8_t pad_70C8[16]; /* 0x70C8 - 0x70D7 */
    uint64_t field_70D8; /* 0x70D8 sz=8 r conf=low */
    uint8_t pad_70E0[12]; /* 0x70E0 - 0x70EB */
    uint32_t field_70EC; /* 0x70EC sz=4 rw conf=medium */
    uint8_t pad_70F0[64]; /* 0x70F0 - 0x712F */
    uint32_t field_7130; /* 0x7130 sz=4 rw conf=medium */
    uint8_t pad_7134[324]; /* 0x7134 - 0x7277 */
    uint64_t field_7278; /* 0x7278 sz=8 rw conf=medium */
} ccBoss0705Itachi;
static_assert(sizeof(ccBoss0705Itachi) == 0x7280, "ccBoss0705Itachi size mismatch");
static_assert(offsetof(ccBoss0705Itachi, field_00C0) == 0xC0, "ccBoss0705Itachi.field_00C0 offset");
static_assert(offsetof(ccBoss0705Itachi, field_0218) == 0x218, "ccBoss0705Itachi.field_0218 offset");
static_assert(offsetof(ccBoss0705Itachi, field_0600) == 0x600, "ccBoss0705Itachi.field_0600 offset");
static_assert(offsetof(ccBoss0705Itachi, field_08D4) == 0x8D4, "ccBoss0705Itachi.field_08D4 offset");
static_assert(offsetof(ccBoss0705Itachi, field_08D8) == 0x8D8, "ccBoss0705Itachi.field_08D8 offset");
static_assert(offsetof(ccBoss0705Itachi, field_08DC) == 0x8DC, "ccBoss0705Itachi.field_08DC offset");
static_assert(offsetof(ccBoss0705Itachi, field_3DC0) == 0x3DC0, "ccBoss0705Itachi.field_3DC0 offset");
static_assert(offsetof(ccBoss0705Itachi, field_3E00) == 0x3E00, "ccBoss0705Itachi.field_3E00 offset");
static_assert(offsetof(ccBoss0705Itachi, field_70A0) == 0x70A0, "ccBoss0705Itachi.field_70A0 offset");
static_assert(offsetof(ccBoss0705Itachi, field_70A8) == 0x70A8, "ccBoss0705Itachi.field_70A8 offset");
static_assert(offsetof(ccBoss0705Itachi, field_70B8) == 0x70B8, "ccBoss0705Itachi.field_70B8 offset");
static_assert(offsetof(ccBoss0705Itachi, field_70C0) == 0x70C0, "ccBoss0705Itachi.field_70C0 offset");
static_assert(offsetof(ccBoss0705Itachi, field_70D8) == 0x70D8, "ccBoss0705Itachi.field_70D8 offset");
static_assert(offsetof(ccBoss0705Itachi, field_70EC) == 0x70EC, "ccBoss0705Itachi.field_70EC offset");
static_assert(offsetof(ccBoss0705Itachi, field_7130) == 0x7130, "ccBoss0705Itachi.field_7130 offset");
static_assert(offsetof(ccBoss0705Itachi, field_7278) == 0x7278, "ccBoss0705Itachi.field_7278 offset");

#pragma pack(pop)

#endif /* S2_BOSS07_H */