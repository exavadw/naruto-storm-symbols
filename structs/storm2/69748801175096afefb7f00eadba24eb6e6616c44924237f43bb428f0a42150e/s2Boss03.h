/* s2Boss03 struct layouts -- Storm 2 (NSUNS2.exe, build s2, sha 697488011750)
 * All fields INFERRED from static analysis (state_surface + decomp). NOT CONFIRMED.
 * Object sizes from game allocator calls where found; otherwise size unknown.
 * Generated 2026-10-19. Padding auto-computed for correct offsetof.
 */
#ifndef S2_BOSS03_H
#define S2_BOSS03_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* =========================================================================
 * ccBoss03Sasori -- Boss 03 main character (Sasori)
 * Allocation size: 0x10BF0 (68592) from FUN_140580190(0x10bf0,...)
 * Ctor RVA: 0x234054. Self-ptr pattern: 7 sub-objects stride ~0x298
 * ========================================================================= */
typedef struct ccBoss03Sasori {
    uint8_t pad_0000[0x70]; /* 0x0000 */
    uint64_t unk_070; /* 0x0070: low conf read in Ctrl */
    uint8_t pad_0078[0x1A0]; /* 0x0078 */
    uint64_t unk_218; /* 0x0218: medium conf ptr in Ctrl */
    uint8_t pad_0220[0x20]; /* 0x0220 */
    uint64_t unk_240; /* 0x0240: low conf in Ctrl */
    uint8_t pad_0248[0x138]; /* 0x0248 */
    uint64_t unk_380; /* 0x0380: low conf in Ctrl */
    uint8_t pad_0388[0x4B8]; /* 0x0388 */
    int32_t unk_840; /* 0x0840: init to 0x1e in ctor */
    int32_t unk_844; /* 0x0844: init to 1 in ctor */
    uint8_t pad_0848[0x5CC]; /* 0x0848 */
    uint64_t subobj_e14; /* 0x0E14: FUN_140237600(param_1+0xe14) in ctor */
    uint8_t pad_0e1c[0x515C]; /* 0x0E1C */
    uint64_t unk_5f78; /* 0x5F78: low conf ptr in Ctrl */
    uint8_t pad_5f80[0xB8]; /* 0x5F80 */
    int32_t unk_6038; /* 0x6038: medium conf rw in Ctrl */
    uint8_t pad_603c[0x10]; /* 0x603C */
    int32_t unk_604c; /* 0x604C: medium conf rw in Ctrl */
    uint8_t pad_6050[0x14]; /* 0x6050 */
    int16_t unk_6064; /* 0x6064: medium conf rw in Ctrl */
    uint8_t pad_6066[0xF9A]; /* 0x6066 */
    int32_t unk_7000; /* 0x7000: init to 0 in ctor */
    uint8_t pad_7004[0x9C]; /* 0x7004 */
    uint64_t unk_70a0; /* 0x70A0: low conf in Ctrl+ctor */
    uint8_t pad_70a8[0x48]; /* 0x70A8 */
    uint8_t unk_70f0_70f4_raw[0x8]; /* 0x70F0: medium conf in Ctrl (uint64 @ 0x70F0 + unaligned int32 @ 0x70F4) */
    uint8_t pad_70f8[0x1460]; /* 0x70F8 */
    uint64_t self_ptr_8558; /* 0x8558: self-ptr pattern */
    uint8_t pad_8560[0x14C0]; /* 0x8560 */
    uint64_t self_ptr_9a20; /* 0x9A20: self-ptr pattern */
    uint8_t pad_9a28[0x14B8]; /* 0x9A28 */
    uint64_t self_ptr_aee0; /* 0xAEE0: self-ptr pattern */
    uint8_t pad_aee8[0x14C0]; /* 0xAEE8 */
    uint64_t self_ptr_c3a8; /* 0xC3A8: self-ptr pattern */
    uint8_t pad_c3b0[0x14B8]; /* 0xC3B0 */
    uint64_t self_ptr_d868; /* 0xD868: self-ptr pattern */
    uint8_t pad_d870[0x14B8]; /* 0xD870 */
    uint64_t self_ptr_ed28; /* 0xED28: self-ptr pattern */
    uint8_t pad_ed30[0x1518]; /* 0xED30 */
    uint64_t self_ptr_10248; /* 0x10248: self-ptr pattern */
    uint8_t pad_10250[0x10]; /* 0x10250 */
    uint64_t unk_10260; /* 0x10260: high conf in Ctrl+ctor */
    uint8_t pad_10268[0x40]; /* 0x10268 */
    uint64_t unk_102a8; /* 0x102A8: low conf in ctor */
    uint8_t pad_102b0[0x78]; /* 0x102B0 */
    uint64_t unk_10328; /* 0x10328: low conf in ctor */
    uint8_t pad_10330[0x338]; /* 0x10330 */
    uint64_t unk_10668; /* 0x10668: high conf in Ctrl+ctor */
    int32_t unk_10670; /* 0x10670: high conf in Ctrl+ctor */
    uint8_t pad_10674[0xC]; /* 0x10674 */
    uint64_t unk_10680; /* 0x10680: medium conf in ctor */
    uint64_t unk_10688; /* 0x10688: medium conf in ctor */
    uint8_t pad_10690[0x10]; /* 0x10690 */
    uint64_t unk_106a0; /* 0x106A0: high conf in Ctrl+ctor */
    int32_t unk_106a8; /* 0x106A8: high conf in Ctrl+ctor */
    uint8_t pad_106ac[0x4]; /* 0x106AC */
    uint64_t unk_106b0; /* 0x106B0: low conf in ctor */
    uint8_t pad_106b8[0xF8]; /* 0x106B8 */
    uint64_t unk_107b0; /* 0x107B0: low conf [4,8] in Ctrl+ctor */
    int32_t unk_107b8; /* 0x107B8: high conf in Ctrl+ctor */
    uint8_t pad_107bc[0x4]; /* 0x107BC */
    uint64_t unk_107c0; /* 0x107C0: high conf in Ctrl+ctor */
    uint8_t pad_107c8[0xC]; /* 0x107C8 */
    int32_t unk_107d4; /* 0x107D4: init to 0 in ctor */
    uint8_t pad_107d8[0x8]; /* 0x107D8 */
    uint64_t unk_107e0; /* 0x107E0: low conf in ctor */
    uint8_t pad_107e8[0x20]; /* 0x107E8 */
    uint64_t unk_10808; /* 0x10808: high conf in Ctrl+ctor */
    uint64_t unk_10810; /* 0x10810: high conf in Ctrl+ctor */
    uint64_t unk_10818; /* 0x10818: medium conf in ctor */
    uint8_t pad_10820[0x3D0]; /* 0x10820: tail padding */
} ccBoss03Sasori;
static_assert(sizeof(ccBoss03Sasori) == 0x10BF0, "ccBoss03Sasori size");
static_assert(offsetof(ccBoss03Sasori, unk_070) == 0x70, "");
static_assert(offsetof(ccBoss03Sasori, unk_218) == 0x218, "");
static_assert(offsetof(ccBoss03Sasori, unk_240) == 0x240, "");
static_assert(offsetof(ccBoss03Sasori, unk_380) == 0x380, "");
static_assert(offsetof(ccBoss03Sasori, unk_840) == 0x840, "");
static_assert(offsetof(ccBoss03Sasori, unk_844) == 0x844, "");
static_assert(offsetof(ccBoss03Sasori, subobj_e14) == 0xE14, "");
static_assert(offsetof(ccBoss03Sasori, unk_5f78) == 0x5F78, "");
static_assert(offsetof(ccBoss03Sasori, unk_6038) == 0x6038, "");
static_assert(offsetof(ccBoss03Sasori, unk_604c) == 0x604C, "");
static_assert(offsetof(ccBoss03Sasori, unk_6064) == 0x6064, "");
static_assert(offsetof(ccBoss03Sasori, unk_7000) == 0x7000, "");
static_assert(offsetof(ccBoss03Sasori, unk_70a0) == 0x70A0, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_8558) == 0x8558, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_9a20) == 0x9A20, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_aee0) == 0xAEE0, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_c3a8) == 0xC3A8, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_d868) == 0xD868, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_ed28) == 0xED28, "");
static_assert(offsetof(ccBoss03Sasori, self_ptr_10248) == 0x10248, "");
static_assert(offsetof(ccBoss03Sasori, unk_10260) == 0x10260, "");
static_assert(offsetof(ccBoss03Sasori, unk_102a8) == 0x102A8, "");
static_assert(offsetof(ccBoss03Sasori, unk_10328) == 0x10328, "");
static_assert(offsetof(ccBoss03Sasori, unk_10668) == 0x10668, "");
static_assert(offsetof(ccBoss03Sasori, unk_10670) == 0x10670, "");
static_assert(offsetof(ccBoss03Sasori, unk_10680) == 0x10680, "");
static_assert(offsetof(ccBoss03Sasori, unk_10688) == 0x10688, "");
static_assert(offsetof(ccBoss03Sasori, unk_106a0) == 0x106A0, "");
static_assert(offsetof(ccBoss03Sasori, unk_106a8) == 0x106A8, "");
static_assert(offsetof(ccBoss03Sasori, unk_106b0) == 0x106B0, "");
static_assert(offsetof(ccBoss03Sasori, unk_107b0) == 0x107B0, "");
static_assert(offsetof(ccBoss03Sasori, unk_107b8) == 0x107B8, "");
static_assert(offsetof(ccBoss03Sasori, unk_107c0) == 0x107C0, "");
static_assert(offsetof(ccBoss03Sasori, unk_107d4) == 0x107D4, "");
static_assert(offsetof(ccBoss03Sasori, unk_107e0) == 0x107E0, "");
static_assert(offsetof(ccBoss03Sasori, unk_10808) == 0x10808, "");
static_assert(offsetof(ccBoss03Sasori, unk_10810) == 0x10810, "");
static_assert(offsetof(ccBoss03Sasori, unk_10818) == 0x10818, "");

/* =========================================================================
 * ccBoss03SasoriWire -- Sasori wire/puppet weapon object
 * Size unknown; fields from state_surface only.
 * ========================================================================= */
typedef struct ccBoss03SasoriWire {
    uint8_t pad_0000[0x14B8]; /* 0x0000 */
    uint64_t unk_14b8; /* 0x14B8: low conf in ctor */
    uint8_t pad_14c0[0x90]; /* 0x14C0 */
    uint64_t unk_1550; /* 0x1550: medium conf in ctor */
    uint8_t pad_1558[0xC]; /* 0x1558 */
    uint64_t unk_1564; /* 0x1564: low conf in ctor */
    uint8_t pad_156c[0x4]; /* 0x156C */
    uint64_t unk_1570; /* 0x1570: medium conf back-ptr */
    uint64_t unk_1578; /* 0x1578: medium conf in ctor */
    uint64_t unk_1580; /* 0x1580: medium conf in ctor */
} ccBoss03SasoriWire;
/* size unknown, >= 0x1588 -- no allocator call found */
static_assert(offsetof(ccBoss03SasoriWire, unk_14b8) == 0x14B8, "");
static_assert(offsetof(ccBoss03SasoriWire, unk_1550) == 0x1550, "");
static_assert(offsetof(ccBoss03SasoriWire, unk_1564) == 0x1564, "");
static_assert(offsetof(ccBoss03SasoriWire, unk_1570) == 0x1570, "");
static_assert(offsetof(ccBoss03SasoriWire, unk_1578) == 0x1578, "");
static_assert(offsetof(ccBoss03SasoriWire, unk_1580) == 0x1580, "");

/* =========================================================================
 * ccSceneBoss03Phase03 -- Boss 03 Phase 03 scene controller
 * Size unknown. Fields from state_surface + factory decomp (RVA 0x426C18).
 * ========================================================================= */
typedef struct ccSceneBoss03Phase03 {
    uint8_t pad_0000[0x50]; /* 0x0000 */
    uint64_t unk_050; /* 0x0050: passed to FUN_1404262a8 */
    uint8_t pad_0058[0xD0]; /* 0x0058 */
    uint64_t unk_128; /* 0x0128: medium conf ptr in Phase03 ctor */
    uint64_t unk_130; /* 0x0130: medium conf ptr in Phase03 ctor */
    uint64_t unk_138; /* 0x0138: medium conf ptr in Phase03 ctor */
    uint8_t pad_0140[0x14B8]; /* 0x0140 */
    uint64_t unk_15f8; /* 0x15F8: medium conf ptr in Phase03 */
    uint8_t pad_1600[0x14C0]; /* 0x1600 */
    uint64_t unk_2ac0; /* 0x2AC0: medium conf ptr in Phase03 */
    uint8_t pad_2ac8[0x14E8]; /* 0x2AC8 */
    uint64_t unk_3fb0; /* 0x3FB0: medium conf ptr in Phase03 */
    uint64_t unk_3fb8; /* 0x3FB8: medium conf ptr in Phase03 */
    int32_t unk_3fc0; /* 0x3FC0: medium conf int32 in Phase03 */
} ccSceneBoss03Phase03;
/* size unknown, >= 0x3FC4 -- no allocator call found */
static_assert(offsetof(ccSceneBoss03Phase03, unk_050) == 0x50, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_128) == 0x128, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_130) == 0x130, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_138) == 0x138, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_15f8) == 0x15F8, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_2ac0) == 0x2AC0, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_3fb0) == 0x3FB0, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_3fb8) == 0x3FB8, "");
static_assert(offsetof(ccSceneBoss03Phase03, unk_3fc0) == 0x3FC0, "");

/* =========================================================================
 * ccSceneBoss03Phase01 -- Boss 03 Phase 01 scene controller
 * Size unknown; minimal fields from state_surface.
 * ========================================================================= */
typedef struct ccSceneBoss03Phase01 {
    uint8_t pad_0000[0x128]; /* 0x0000 */
    uint64_t unk_128; /* 0x0128: medium conf in ctor */
    uint8_t pad_0130[0x8]; /* 0x0130 */
    uint64_t unk_138; /* 0x0138: low conf in ctor */
    uint8_t pad_0140[0x14B0]; /* 0x0140 */
    uint64_t unk_15f0; /* 0x15F0: low conf in ctor */
} ccSceneBoss03Phase01;
/* size unknown, >= 0x15F8 -- no allocator call found */
static_assert(offsetof(ccSceneBoss03Phase01, unk_128) == 0x128, "");
static_assert(offsetof(ccSceneBoss03Phase01, unk_138) == 0x138, "");
static_assert(offsetof(ccSceneBoss03Phase01, unk_15f0) == 0x15F0, "");

/* =========================================================================
 * ccBoss03SasoriHyakkiAuto -- Hyakki puppet auto-controller
 * Size unknown; fields from state_surface.
 * ========================================================================= */
typedef struct ccBoss03SasoriHyakkiAuto {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    int32_t unk_098; /* 0x0098: medium conf in ctor */
    uint8_t pad_009c[0xC]; /* 0x009C */
    uint64_t unk_0a8; /* 0x00A8: low conf in ctor */
    uint8_t pad_00b0[0x4]; /* 0x00B0 */
    uint64_t unk_0b4; /* 0x00B4: low conf in ctor */
    uint8_t pad_00bc[0x3C]; /* 0x00BC */
    uint64_t unk_0f8; /* 0x00F8: medium conf in ctor */
    uint8_t pad_0100[0x10]; /* 0x0100 */
    uint64_t unk_110; /* 0x0110: medium conf in ctor */
    uint8_t pad_0118[0x28]; /* 0x0118 */
    int32_t unk_140; /* 0x0140: medium conf in ctor */
    int32_t unk_144; /* 0x0144: medium conf in ctor */
    uint64_t unk_148; /* 0x0148: medium conf in ctor */
} ccBoss03SasoriHyakkiAuto;
/* size unknown, >= 0x150 -- no allocator call found */
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_098) == 0x98, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_0a8) == 0xA8, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_0b4) == 0xB4, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_0f8) == 0xF8, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_110) == 0x110, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_140) == 0x140, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_144) == 0x144, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto, unk_148) == 0x148, "");

/* =========================================================================
 * ccBoss03SasoriHyakkiAuto2 -- Hyakki puppet auto-controller variant
 * Size unknown; fields from state_surface.
 * ========================================================================= */
typedef struct ccBoss03SasoriHyakkiAuto2 {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    int32_t unk_098; /* 0x0098: medium conf in ctor */
    uint8_t pad_009c[0xC]; /* 0x009C */
    uint64_t unk_0a8; /* 0x00A8: low conf in ctor */
    uint8_t pad_00b0[0x8]; /* 0x00B0 */
    uint64_t unk_0b8; /* 0x00B8: medium conf in ctor */
    uint64_t unk_0c0; /* 0x00C0: medium conf in ctor */
    uint8_t pad_00c8[0x28]; /* 0x00C8 */
    int32_t unk_0f0; /* 0x00F0: medium conf in ctor */
    uint8_t pad_00f4[0x44]; /* 0x00F4 */
    uint64_t unk_138; /* 0x0138: medium conf in ctor */
} ccBoss03SasoriHyakkiAuto2;
/* size unknown, >= 0x140 -- no allocator call found */
static_assert(offsetof(ccBoss03SasoriHyakkiAuto2, unk_098) == 0x98, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto2, unk_0a8) == 0xA8, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto2, unk_0b8) == 0xB8, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto2, unk_0c0) == 0xC0, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto2, unk_0f0) == 0xF0, "");
static_assert(offsetof(ccBoss03SasoriHyakkiAuto2, unk_138) == 0x138, "");

/* =========================================================================
 * ccBoss0303SupportCyb -- Support gauge / Cyb object for Boss 03
 * Size unknown; fields from state_surface.
 * ========================================================================= */
typedef struct ccBoss0303SupportCyb {
    uint8_t pad_0000[0x380]; /* 0x0000 */
    uint64_t unk_380; /* 0x0380: low conf in Ctrl */
    uint8_t pad_0388[0x4B0]; /* 0x0388 */
    int32_t unk_838; /* 0x0838: medium conf in Ctrl */
    uint8_t pad_083c[0x8]; /* 0x083C */
    int32_t unk_844; /* 0x0844: medium conf in ctor */
    uint8_t pad_0848[0x1D88]; /* 0x0848 */
    uint64_t unk_25d0; /* 0x25D0: medium conf in Ctrl */
    uint8_t pad_25d8[0x4B28]; /* 0x25D8 */
    uint64_t unk_7100; /* 0x7100: low conf in Ctrl+ctor */
    uint8_t pad_7108[0x48]; /* 0x7108 */
    uint64_t unk_7150; /* 0x7150: medium conf in Ctrl */
    uint8_t pad_7158[0x1470]; /* 0x7158 */
    uint64_t unk_85c8; /* 0x85C8: low conf in Ctrl+ctor */
    uint8_t pad_85d0[0x38]; /* 0x85D0 */
    uint64_t unk_8608; /* 0x8608: high conf in Ctrl+ctor */
} ccBoss0303SupportCyb;
/* size unknown, >= 0x8610 -- no allocator call found */
static_assert(offsetof(ccBoss0303SupportCyb, unk_380) == 0x380, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_838) == 0x838, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_844) == 0x844, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_25d0) == 0x25D0, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_7100) == 0x7100, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_7150) == 0x7150, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_85c8) == 0x85C8, "");
static_assert(offsetof(ccBoss0303SupportCyb, unk_8608) == 0x8608, "");


/* =========================================================================
 * ccBoss03SasoriBarrier -- Boss03 group
 * Vtable: PTR_FUN_1407caca8 (from dtor pattern)
 * Size unknown, >= 0x1740 -- no allocator call found; fields extend to 0x16FC (Matrix44 in PostProcess)
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03SasoriBarrier {
    uint8_t pad_0000[0x50]; /* 0x0000 */
    int32_t unk_50; /* 0x0050: PostProcess: *(int*)(param_1+0x50) - 4U < 2 */
    uint8_t pad_0054[0x4]; /* 0x0054 */
    int32_t unk_58; /* 0x0058: PostProcess: *(int*)(param_1+0x58) * 0.25 + 1.0 */
    uint8_t pad_005c[0x14F4]; /* 0x005C */
    float pos_x; /* 0x1550: CreateHyakkiAuto/PostProcess: SetTranslatePart(param_1+0x1550) */
    float pos_y; /* 0x1554: CreateHyakkiAuto: *(undefined4*)(param_1+0x1554) */
    float pos_z; /* 0x1558: CreateHyakkiAuto: *(float*)(param_1+0x1558) + 500.0 */
    uint8_t pad_155c[0x4]; /* 0x155C */
    uint64_t hyakki_flag; /* 0x1560: CreateHyakkiAuto: if (*(longlong*)(param_1+0x1560) != 0) */
    uint64_t render_obj; /* 0x1568: PostProcess: *(longlong**)(param_1+0x1568) vtable dispatch */
    uint8_t pad_1570[0x20]; /* 0x1570 */
    uint64_t hyakki_auto_ptrs[16]; /* 0x1590: CreateHyakkiAuto: array of 16 ptrs at +0x1590..+0x160F */
    uint8_t pad_1610[0xEC]; /* 0x1610 */
    uint8_t billboard_mtx[0x40]; /* 0x16FC: PostProcess: Mul result stored at param_1+0x16fc */
} ccBoss03SasoriBarrier;
#pragma pack(pop)
/* size unknown, >= 0x1740 -- no allocator call found; fields extend to 0x16FC (Matrix44 in PostProcess) */
static_assert(offsetof(ccBoss03SasoriBarrier, unk_50) == 0x50, "");
static_assert(offsetof(ccBoss03SasoriBarrier, unk_58) == 0x58, "");
static_assert(offsetof(ccBoss03SasoriBarrier, pos_x) == 0x1550, "");
static_assert(offsetof(ccBoss03SasoriBarrier, pos_y) == 0x1554, "");
static_assert(offsetof(ccBoss03SasoriBarrier, pos_z) == 0x1558, "");
static_assert(offsetof(ccBoss03SasoriBarrier, hyakki_flag) == 0x1560, "");
static_assert(offsetof(ccBoss03SasoriBarrier, render_obj) == 0x1568, "");
static_assert(offsetof(ccBoss03SasoriBarrier, hyakki_auto_ptrs) == 0x1590, "");
static_assert(offsetof(ccBoss03SasoriBarrier, billboard_mtx) == 0x16FC, "");
/* =========================================================================
 * ccBoss03SasoriHkkMob -- Boss03 group
 * Vtable: PTR_FUN_1407caca8
 * Size unknown, >= 0xB8 -- no allocator call found
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03SasoriHkkMob {
    uint8_t pad_0000[0x14]; /* 0x0000 */
    uint32_t unk_14; /* 0x0014: state_surface: low conf read */
    uint8_t pad_0018[0x40]; /* 0x0018 */
    uint64_t unk_58; /* 0x0058: ctor write */
    uint32_t unk_60; /* 0x0060: ctor write */
    uint8_t pad_0064[0x38]; /* 0x0064 */
    uint64_t pos_a; /* 0x009C: CreateHyakkiAuto: *(lVar3+0x9c) = *puVar2 */
    uint32_t pos_a_w; /* 0x00A4: CreateHyakkiAuto: *(undefined4*)(lVar3+0xa4) */
    uint64_t pos_b; /* 0x00A8: CreateHyakkiAuto: *(lVar3+0xa8) = *puVar2 */
    uint32_t pos_b_w; /* 0x00B0: CreateHyakkiAuto: *(undefined4*)(lVar3+0xb0) */
} ccBoss03SasoriHkkMob;
#pragma pack(pop)
/* size unknown, >= 0xB8 -- no allocator call found */
static_assert(offsetof(ccBoss03SasoriHkkMob, unk_14) == 0x14, "");
static_assert(offsetof(ccBoss03SasoriHkkMob, unk_58) == 0x58, "");
static_assert(offsetof(ccBoss03SasoriHkkMob, unk_60) == 0x60, "");
static_assert(offsetof(ccBoss03SasoriHkkMob, pos_a) == 0x9C, "");
static_assert(offsetof(ccBoss03SasoriHkkMob, pos_a_w) == 0xA4, "");
static_assert(offsetof(ccBoss03SasoriHkkMob, pos_b) == 0xA8, "");
static_assert(offsetof(ccBoss03SasoriHkkMob, pos_b_w) == 0xB0, "");
/* =========================================================================
 * ccBoss03SpecialAttack -- Boss03 group
 * Base: ccTaskBase
 * Vtable: PTR_FUN_1407e2450
 * Size unknown, >= 0x14C0 -- no allocator call found; derives ccTaskBase
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03SpecialAttack {
    uint8_t pad_0000[0x14B8]; /* 0x0000 */
    uint64_t unk_14b8; /* 0x14B8: state_surface: write */
} ccBoss03SpecialAttack;
#pragma pack(pop)
/* size unknown, >= 0x14C0 -- no allocator call found; derives ccTaskBase */
static_assert(offsetof(ccBoss03SpecialAttack, unk_14b8) == 0x14B8, "");
/* =========================================================================
 * ccSceneBoss03 -- Boss03 group
 * Base: ccStageObjectManager
 * Size unknown, >= 0x158 -- no allocator call found; derives ccStageObjectManager
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccSceneBoss03 {
    uint8_t pad_0000[0x128]; /* 0x0000 */
    int32_t unk_128; /* 0x0128: Initialize write */
    int32_t unk_12c; /* 0x012C: Initialize: set to 300 */
    uint64_t skill_loader_a; /* 0x0130: Initialize: skillLoader ptr */
    uint8_t pad_0138[0x8]; /* 0x0138 */
    uint64_t skill_loader_b; /* 0x0140: Initialize: skillLoader ptr */
    uint8_t pad_0148[0x8]; /* 0x0148 */
    uint64_t unk_150; /* 0x0150: state_surface: ptr */
} ccSceneBoss03;
#pragma pack(pop)
/* size unknown, >= 0x158 -- no allocator call found; derives ccStageObjectManager */
static_assert(offsetof(ccSceneBoss03, unk_128) == 0x128, "");
static_assert(offsetof(ccSceneBoss03, unk_12c) == 0x12C, "");
static_assert(offsetof(ccSceneBoss03, skill_loader_a) == 0x130, "");
static_assert(offsetof(ccSceneBoss03, skill_loader_b) == 0x140, "");
static_assert(offsetof(ccSceneBoss03, unk_150) == 0x150, "");
/* =========================================================================
 * ccBoss03SasoriFire -- Boss03 group
 * ccBoss03SasoriFire: no instance state
 * Evidence: state_surface with all 3 methods (Initialize RVA 0x236BC4,
 *   CollisionCallback RVA 0x23D010, UpdateAnimation RVA 0x23D874) returned
 *   0 fields. Initialize decomp shows param_1+0x106B0 access = parent
 *   ccBoss03Sasori array of 32 ptrs, not own fields. No allocator call found.
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */

/* =========================================================================
 * ccBoss03SasoriActionState -- Boss03 group
 * Base: ccTaskBase
 * Vtable: PTR_FUN_1407ca200
 * Size unknown, >= 0x91C0 -- no allocator call found; derives ccTaskBase
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03SasoriActionState {
    uint8_t pad_0000[0x14B8]; /* 0x0000 */
    uint64_t unk_14b8; /* 0x14B8: state_surface: write */
    uint64_t unk_14c0; /* 0x14C0: state_surface: write */
    uint64_t unk_14c8; /* 0x14C8: state_surface: read */
    uint8_t pad_14d0[0x14B8]; /* 0x14D0 */
    uint64_t unk_2988; /* 0x2988: state_surface: read */
    uint8_t pad_2990[0x14B8]; /* 0x2990 */
    uint64_t unk_3e48; /* 0x3E48: state_surface: write */
    uint64_t unk_3e50; /* 0x3E50: state_surface: read */
    uint8_t pad_3e58[0x14B8]; /* 0x3E58 */
    uint64_t unk_5310; /* 0x5310: state_surface: read */
    uint8_t pad_5318[0x14B8]; /* 0x5318 */
    uint64_t unk_67d0; /* 0x67D0: state_surface: read */
    uint8_t pad_67d8[0x1518]; /* 0x67D8 */
    uint64_t unk_7cf0; /* 0x7CF0: state_surface: read */
    uint8_t pad_7cf8[0x14B8]; /* 0x7CF8 */
    uint64_t unk_91b0; /* 0x91B0: state_surface: write */
    uint64_t unk_91b8; /* 0x91B8: state_surface: write */
} ccBoss03SasoriActionState;
#pragma pack(pop)
/* size unknown, >= 0x91C0 -- no allocator call found; derives ccTaskBase */
static_assert(offsetof(ccBoss03SasoriActionState, unk_14b8) == 0x14B8, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_14c0) == 0x14C0, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_14c8) == 0x14C8, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_2988) == 0x2988, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_3e48) == 0x3E48, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_3e50) == 0x3E50, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_5310) == 0x5310, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_67d0) == 0x67D0, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_7cf0) == 0x7CF0, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_91b0) == 0x91B0, "");
static_assert(offsetof(ccBoss03SasoriActionState, unk_91b8) == 0x91B8, "");
/* =========================================================================
 * ccBoss03Stage00 -- Boss03 group
 * Base: ccBossStage
 * Vtable: PTR_FUN_1407cb068
 * Size: 0x218 (LoadTh(0x218,...) in Create<ccBoss03Stage00>)
 * NOTE: Field at 0x340 accessed via vtable+0x68 dispatch in Initialize (**(code**)(*param_1+0x68))(param_1,9) -- base class virtual, not own field.
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03Stage00 {
    uint8_t pad_0000[0x210]; /* 0x0000 */
    uint64_t anm_ptr; /* 0x0210: Initialize: param_1[0x42] = plVar3 (nuccAnm*) */
} ccBoss03Stage00;
#pragma pack(pop)
static_assert(sizeof(ccBoss03Stage00) == 0x218, "");
static_assert(offsetof(ccBoss03Stage00, anm_ptr) == 0x210, "");
/* =========================================================================
 * ccBoss03Stage01DamageZone -- Boss03 group
 * Size unknown, >= 0xC0 -- no allocator call found
 * NOTE: UpdateCollision reads +0x9c and +0xa8 as ptrs; +0xa8 likely part of DName or adjacent struct.
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03Stage01DamageZone {
    uint8_t pad_0000[0x98]; /* 0x0000 */
    int32_t active_flag; /* 0x0098: Ctrl: if (*(int*)(param_1+0x98) != 0) */
    uint64_t dname_ptr; /* 0x009C: Ctrl: DName::DName(local_18, param_1+0x9c) */
    uint8_t pad_00a4[0xC]; /* 0x00A4 */
    uint64_t anm_base; /* 0x00B0: Ctrl: if (*(longlong*)(param_1+0xb0) == 0) */
    int32_t timer; /* 0x00B8: Ctrl: *(int*)(param_1+0xb8) decremented each frame */
} ccBoss03Stage01DamageZone;
#pragma pack(pop)
/* size unknown, >= 0xC0 -- no allocator call found */
static_assert(offsetof(ccBoss03Stage01DamageZone, active_flag) == 0x98, "");
static_assert(offsetof(ccBoss03Stage01DamageZone, dname_ptr) == 0x9C, "");
static_assert(offsetof(ccBoss03Stage01DamageZone, anm_base) == 0xB0, "");
static_assert(offsetof(ccBoss03Stage01DamageZone, timer) == 0xB8, "");
/* =========================================================================
 * ccBoss03VoicePlayer -- Boss03 group
 * Base: ccTaskBase (inferred)
 * Size unknown, >= 0x14D0 -- no allocator call found; inner ctor pattern suggests ccTaskBase derivation
 * INFERRED -- all fields from state_surface / decompilation, not runtime-confirmed.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ccBoss03VoicePlayer {
    uint8_t pad_0000[0x297]; /* 0x0000 */
    int32_t unk_297; /* 0x0297: inner ctor write */
    uint8_t pad_029b[0x1221]; /* 0x029B */
    int32_t unk_14bc; /* 0x14BC: inner ctor write */
    uint8_t pad_14c0[0x8]; /* 0x14C0 */
    uint64_t unk_14c8; /* 0x14C8: state_surface: low conf read */
} ccBoss03VoicePlayer;
#pragma pack(pop)
/* size unknown, >= 0x14D0 -- no allocator call found; inner ctor pattern suggests ccTaskBase derivation */
static_assert(offsetof(ccBoss03VoicePlayer, unk_297) == 0x297, "");
static_assert(offsetof(ccBoss03VoicePlayer, unk_14bc) == 0x14BC, "");
static_assert(offsetof(ccBoss03VoicePlayer, unk_14c8) == 0x14C8, "");

#endif /* S2_BOSS03_H */
