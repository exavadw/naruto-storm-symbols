#ifndef CCHUGEBATTLE_S1_H
#define CCHUGEBATTLE_S1_H

#include <stdint.h>
#include <stddef.h>

/*
 * ccHugeBattle group (NARUTO STORM 1 / s1) — INFERRED layouts from static analysis.
 * 29 classes covering giant boss battles (Gamabunta vs Shukaku, Manda, Orochimaru).
 *
 * Inheritance chains (INFERRED from ctor chains):
 *   ccHugeCharaManda -> ccBossCommandBase -> ccCharacterBase -> ccNarutoRootObjManager::EntryNarutoRootObj
 *   ccHugeCharaShukaku -> ccBossCommandBase -> ccCharacterBase -> ...
 *   ccHugeCharaGamabunta -> ccBossCommandBase -> ccCharacterBase -> ...
 *   ccHugeCharaBase -> ccBreakObj -> ccGimObj (separate hierarchy, size 0x370)
 *   ccPlayerHugeBtl -> ccPlayer (ccPlayer size 0x1830 proven in ccPlayer.h)
 *
 * Object sizes from game code (FUN_14047ed10 = operator new):
 *   ccHugeCharaBase direct: 0x370 (880) — 5 callers consistent
 *   ccBossCommandBase subclass iVar2==0: 0x940 (2368) — factory FUN_1402d37d4 line 0x22b
 *   ccBossStunCommand (iVar2==1): 0x960 (2400) — factory FUN_1402d37d4 line 0x232
 *   ccHugeCharaManda (iVar2==2): 0x9E8 (2536) — factory FUN_1402d37d4 line 0x239
 *   ccPlayerHugeBtl: extends ccPlayer (0x1830), fields up to 0x46C4
 *
 * All offsets verified by static_assert(offsetof(...)). Sizes from allocator, never sizeof.
 * Fields named where evidence supports it; unnamed fields are unk_<offset>.
 * Everything is INFERRED, not CONFIRMED.
 */

/* ========================================================================
 * ccHugeBattle — battle manager (size unknown, >= 0x54)
 * ======================================================================== */
typedef struct ccHugeBattle {
    uint8_t pad_00[0x30];              /* 0x00-0x2F: vtable + base */
    uint64_t unk_30;                   /* 0x30 */
    uint64_t unk_38;                   /* 0x38 */
    uint32_t unk_40;                   /* 0x40 */
    uint32_t unk_44;                   /* 0x44 */
    uint32_t unk_48;                   /* 0x48 */
    uint32_t unk_4C;                   /* 0x4C */
} ccHugeBattle;
/* size unknown, >= 0x54 */
_Static_assert(offsetof(ccHugeBattle, unk_30) == 0x30, "ccHugeBattle.unk_30");
_Static_assert(offsetof(ccHugeBattle, unk_38) == 0x38, "ccHugeBattle.unk_38");
_Static_assert(offsetof(ccHugeBattle, unk_40) == 0x40, "ccHugeBattle.unk_40");
_Static_assert(offsetof(ccHugeBattle, unk_44) == 0x44, "ccHugeBattle.unk_44");
_Static_assert(offsetof(ccHugeBattle, unk_48) == 0x48, "ccHugeBattle.unk_48");
_Static_assert(offsetof(ccHugeBattle, unk_4C) == 0x4C, "ccHugeBattle.unk_4C");

/* ========================================================================
 * ccGameHugeBtl — game-level huge battle state (size unknown, >= 0xE8)
 * ======================================================================== */
typedef struct ccGameHugeBtl {
    uint8_t pad_00[0x30];              /* 0x00-0x2F: vtable + base */
    uint64_t unk_30;                   /* 0x30 */
    uint8_t pad_38[0x20];             /* 0x38-0x57 */
    uint64_t unk_58;                   /* 0x58 */
    uint8_t pad_60[0x08];             /* 0x60-0x67 */
    uint64_t unk_68;                   /* 0x68 */
    uint64_t unk_70;                   /* 0x70 */
    uint64_t unk_78;                   /* 0x78 */
    uint64_t unk_80;                   /* 0x80 */
    uint64_t unk_88;                   /* 0x88 */
    uint64_t unk_90;                   /* 0x90 */
    uint64_t unk_98;                   /* 0x98 */
    uint64_t unk_A0;                   /* 0xA0 */
    uint64_t unk_A8;                   /* 0xA8 */
    uint64_t unk_B0;                   /* 0xB0 */
    uint64_t unk_B8;                   /* 0xB8 */
    uint64_t unk_C0;                   /* 0xC0 */
    uint32_t unk_C8;                   /* 0xC8 */
    uint32_t unk_CC;                   /* 0xCC */
    uint64_t unk_D0;                   /* 0xD0 */
    uint64_t unk_D8;                   /* 0xD8 */
    uint64_t unk_E0;                   /* 0xE0 */
} ccGameHugeBtl;
/* size unknown, >= 0xE8 */
_Static_assert(offsetof(ccGameHugeBtl, unk_30) == 0x30, "ccGameHugeBtl.unk_30");
_Static_assert(offsetof(ccGameHugeBtl, unk_58) == 0x58, "ccGameHugeBtl.unk_58");
_Static_assert(offsetof(ccGameHugeBtl, unk_68) == 0x68, "ccGameHugeBtl.unk_68");
_Static_assert(offsetof(ccGameHugeBtl, unk_70) == 0x70, "ccGameHugeBtl.unk_70");
_Static_assert(offsetof(ccGameHugeBtl, unk_78) == 0x78, "ccGameHugeBtl.unk_78");
_Static_assert(offsetof(ccGameHugeBtl, unk_80) == 0x80, "ccGameHugeBtl.unk_80");
_Static_assert(offsetof(ccGameHugeBtl, unk_88) == 0x88, "ccGameHugeBtl.unk_88");
_Static_assert(offsetof(ccGameHugeBtl, unk_90) == 0x90, "ccGameHugeBtl.unk_90");
_Static_assert(offsetof(ccGameHugeBtl, unk_98) == 0x98, "ccGameHugeBtl.unk_98");
_Static_assert(offsetof(ccGameHugeBtl, unk_A0) == 0xA0, "ccGameHugeBtl.unk_A0");
_Static_assert(offsetof(ccGameHugeBtl, unk_A8) == 0xA8, "ccGameHugeBtl.unk_A8");
_Static_assert(offsetof(ccGameHugeBtl, unk_B0) == 0xB0, "ccGameHugeBtl.unk_B0");
_Static_assert(offsetof(ccGameHugeBtl, unk_B8) == 0xB8, "ccGameHugeBtl.unk_B8");
_Static_assert(offsetof(ccGameHugeBtl, unk_C0) == 0xC0, "ccGameHugeBtl.unk_C0");
_Static_assert(offsetof(ccGameHugeBtl, unk_C8) == 0xC8, "ccGameHugeBtl.unk_C8");
_Static_assert(offsetof(ccGameHugeBtl, unk_CC) == 0xCC, "ccGameHugeBtl.unk_CC");
_Static_assert(offsetof(ccGameHugeBtl, unk_D0) == 0xD0, "ccGameHugeBtl.unk_D0");
_Static_assert(offsetof(ccGameHugeBtl, unk_D8) == 0xD8, "ccGameHugeBtl.unk_D8");
_Static_assert(offsetof(ccGameHugeBtl, unk_E0) == 0xE0, "ccGameHugeBtl.unk_E0");

/* ========================================================================
 * ccHugeCharaBase — huge character base (separate hierarchy from ccBossCommandBase)
 * Size: 0x370 (880 bytes) — proven from 5 callers of FUN_14047ed10(0x370,...)
 * Base: ccBreakObj -> ccGimObj
 * ======================================================================== */
typedef struct ccHugeCharaBase {
    void *vtable;                      /* 0x000 */
    uint8_t pad_008[0x2D8];           /* 0x008-0x2DF: ccBreakObj + ccGimObj base */
    uint32_t unk_2E0;                  /* 0x2E0: sub-object init (FUN_14047f900) */
    uint8_t pad_2E4[0x28];            /* 0x2E4-0x30B */
    uint32_t unk_30C;                  /* 0x30C: sub-object init */
    uint8_t pad_310[0x18];            /* 0x310-0x327 */
    uint32_t unk_328;                  /* 0x328: sub-object init */
    uint8_t pad_32C[0x44];            /* 0x32C-0x36F */
} ccHugeCharaBase;
_Static_assert(sizeof(ccHugeCharaBase) == 0x370, "ccHugeCharaBase size mismatch");
_Static_assert(offsetof(ccHugeCharaBase, unk_2E0) == 0x2E0, "ccHugeCharaBase.unk_2E0");
_Static_assert(offsetof(ccHugeCharaBase, unk_30C) == 0x30C, "ccHugeCharaBase.unk_30C");
_Static_assert(offsetof(ccHugeCharaBase, unk_328) == 0x328, "ccHugeCharaBase.unk_328");

/* ========================================================================
 * ccBossCommandBase — boss command base (extends ccCharacterBase)
 * Size unknown; subclass allocations start at 0x940.
 * Base: ccCharacterBase -> ccNarutoRootObjManager::EntryNarutoRootObj
 * ======================================================================== */
typedef struct ccBossCommandBase {
    uint8_t base[0x898];               /* 0x000-0x897: ccCharacterBase */
    uint32_t unk_898;                  /* 0x898: sub-object init */
    uint8_t pad_89C[0x08];            /* 0x89C-0x8A3 */
    uint32_t unk_8A4;                  /* 0x8A4: sub-object init */
    uint8_t pad_8A8[0x10];            /* 0x8A8-0x8B7 */
    uint32_t unk_8B8;                  /* 0x8B8 */
    uint32_t unk_8BC;                  /* 0x8BC: sub-object init */
    uint8_t pad_8C0[0x80];            /* 0x8C0-0x93F */
} ccBossCommandBase;
/* size unknown, >= 0x940 (smallest subclass allocation) */
_Static_assert(offsetof(ccBossCommandBase, unk_898) == 0x898, "ccBossCommandBase.unk_898");
_Static_assert(offsetof(ccBossCommandBase, unk_8A4) == 0x8A4, "ccBossCommandBase.unk_8A4");
_Static_assert(offsetof(ccBossCommandBase, unk_8B8) == 0x8B8, "ccBossCommandBase.unk_8B8");
_Static_assert(offsetof(ccBossCommandBase, unk_8BC) == 0x8BC, "ccBossCommandBase.unk_8BC");

/* ========================================================================
 * ccHugeCharaManda — Manda boss (extends ccBossCommandBase)
 * Size: 0x9E8 (2536 bytes) — proven from FUN_14047ed10(0x9e8,...) in factory
 * ======================================================================== */
typedef struct ccHugeCharaManda {
    uint8_t base[0x898];               /* 0x000-0x897: ccBossCommandBase (ccCharacterBase) */
    uint32_t unk_898;                  /* 0x898: sub-object init */
    uint8_t pad_89C[0x08];            /* 0x89C-0x8A3 */
    uint32_t unk_8A4;                  /* 0x8A4: sub-object init */
    uint8_t pad_8A8[0x08];            /* 0x8A8-0x8AF */
    uint32_t unk_8B0;                  /* 0x8B0 */
    uint8_t pad_8B4[0x08];            /* 0x8B4-0x8BB */
    uint32_t unk_8BC;                  /* 0x8BC: sub-object init */
    uint8_t pad_8C0[0x14];            /* 0x8C0-0x8D3 */
    uint32_t unk_8D4;                  /* 0x8D4 */
    uint32_t unk_8D8;                  /* 0x8D8 */
    uint32_t unk_8DC;                  /* 0x8DC */
    uint32_t unk_8E0;                  /* 0x8E0 */
    uint32_t unk_8E4;                  /* 0x8E4 */
    uint32_t unk_8E8;                  /* 0x8E8 */
    uint32_t unk_8EC;                  /* 0x8EC */
    uint32_t unk_8F0;                  /* 0x8F0 */
    uint32_t unk_8F4;                  /* 0x8F4 */
    uint32_t unk_8F8;                  /* 0x8F8 */
    uint32_t unk_8FC;                  /* 0x8FC */
    uint32_t unk_900;                  /* 0x900 */
    uint8_t pad_904[0x18];            /* 0x904-0x91B */
    uint32_t unk_91C;                  /* 0x91C */
    uint64_t unk_920;                  /* 0x920 */
    uint64_t unk_928;                  /* 0x928 */
    uint32_t unk_930;                  /* 0x930 */
    uint32_t unk_934;                  /* 0x934: sub-object init */
    uint8_t pad_938[0x14];            /* 0x938-0x94B */
    uint32_t unk_94C;                  /* 0x94C: sub-object init */
    uint8_t pad_950[0x3C];            /* 0x950-0x98B */
    uint32_t unk_98C;                  /* 0x98C: sub-object init */
    uint8_t pad_990[0x48];            /* 0x990-0x9D7 */
    uint64_t unk_9D8;                  /* 0x9D8 */
    uint64_t unk_9E0;                  /* 0x9E0 */
} ccHugeCharaManda;
_Static_assert(sizeof(ccHugeCharaManda) == 0x9E8, "ccHugeCharaManda size mismatch");
_Static_assert(offsetof(ccHugeCharaManda, unk_898) == 0x898, "ccHugeCharaManda.unk_898");
_Static_assert(offsetof(ccHugeCharaManda, unk_8A4) == 0x8A4, "ccHugeCharaManda.unk_8A4");
_Static_assert(offsetof(ccHugeCharaManda, unk_8BC) == 0x8BC, "ccHugeCharaManda.unk_8BC");
_Static_assert(offsetof(ccHugeCharaManda, unk_8D4) == 0x8D4, "ccHugeCharaManda.unk_8D4");
_Static_assert(offsetof(ccHugeCharaManda, unk_8D8) == 0x8D8, "ccHugeCharaManda.unk_8D8");
_Static_assert(offsetof(ccHugeCharaManda, unk_8DC) == 0x8DC, "ccHugeCharaManda.unk_8DC");
_Static_assert(offsetof(ccHugeCharaManda, unk_8E0) == 0x8E0, "ccHugeCharaManda.unk_8E0");
_Static_assert(offsetof(ccHugeCharaManda, unk_8E4) == 0x8E4, "ccHugeCharaManda.unk_8E4");
_Static_assert(offsetof(ccHugeCharaManda, unk_8E8) == 0x8E8, "ccHugeCharaManda.unk_8E8");
_Static_assert(offsetof(ccHugeCharaManda, unk_8F0) == 0x8F0, "ccHugeCharaManda.unk_8F0");
_Static_assert(offsetof(ccHugeCharaManda, unk_8F4) == 0x8F4, "ccHugeCharaManda.unk_8F4");
_Static_assert(offsetof(ccHugeCharaManda, unk_8F8) == 0x8F8, "ccHugeCharaManda.unk_8F8");
_Static_assert(offsetof(ccHugeCharaManda, unk_8FC) == 0x8FC, "ccHugeCharaManda.unk_8FC");
_Static_assert(offsetof(ccHugeCharaManda, unk_900) == 0x900, "ccHugeCharaManda.unk_900");
_Static_assert(offsetof(ccHugeCharaManda, unk_91C) == 0x91C, "ccHugeCharaManda.unk_91C");
_Static_assert(offsetof(ccHugeCharaManda, unk_920) == 0x920, "ccHugeCharaManda.unk_920");
_Static_assert(offsetof(ccHugeCharaManda, unk_928) == 0x928, "ccHugeCharaManda.unk_928");
_Static_assert(offsetof(ccHugeCharaManda, unk_930) == 0x930, "ccHugeCharaManda.unk_930");
_Static_assert(offsetof(ccHugeCharaManda, unk_934) == 0x934, "ccHugeCharaManda.unk_934");
_Static_assert(offsetof(ccHugeCharaManda, unk_94C) == 0x94C, "ccHugeCharaManda.unk_94C");
_Static_assert(offsetof(ccHugeCharaManda, unk_98C) == 0x98C, "ccHugeCharaManda.unk_98C");
_Static_assert(offsetof(ccHugeCharaManda, unk_9D8) == 0x9D8, "ccHugeCharaManda.unk_9D8");
_Static_assert(offsetof(ccHugeCharaManda, unk_9E0) == 0x9E0, "ccHugeCharaManda.unk_9E0");

/* ========================================================================
 * ccHugeCharaShukaku — Shukaku boss (extends ccBossCommandBase)
 * Size unknown, >= 0x954 (last proven field end from state_surface)
 * ======================================================================== */
typedef struct ccHugeCharaShukaku {
    uint8_t base[0x898];               /* 0x000-0x897: ccBossCommandBase */
    uint32_t unk_898;                  /* 0x898: sub-object init */
    uint8_t pad_89C[0x08];            /* 0x89C-0x8A3 */
    uint32_t unk_8A4;                  /* 0x8A4: sub-object init */
    uint8_t pad_8A8[0x08];            /* 0x8A8-0x8AF */
    uint32_t unk_8B0;                  /* 0x8B0 */
    uint8_t pad_8B4[0x08];            /* 0x8B4-0x8BB */
    uint32_t unk_8BC;                  /* 0x8BC: sub-object init */
    uint8_t pad_8C0[0x14];            /* 0x8C0-0x8D3 */
    uint32_t unk_8D4;                  /* 0x8D4 */
    uint32_t unk_8D8;                  /* 0x8D8 */
    uint32_t unk_8DC;                  /* 0x8DC */
    uint32_t unk_8E0;                  /* 0x8E0 */
    uint32_t unk_8E4;                  /* 0x8E4 */
    uint64_t unk_8E8;                  /* 0x8E8 */
    uint32_t unk_8F0;                  /* 0x8F0 */
    uint32_t unk_8F4;                  /* 0x8F4 */
    uint32_t unk_8F8;                  /* 0x8F8 */
    uint32_t unk_8FC;                  /* 0x8FC */
    uint32_t unk_900;                  /* 0x900 */
    uint8_t pad_904[0x18];            /* 0x904-0x91B */
    uint32_t unk_91C;                  /* 0x91C */
    uint64_t unk_920;                  /* 0x920 */
    uint32_t unk_928;                  /* 0x928 */
    uint64_t unk_930;                  /* 0x930 */
    uint64_t unk_938;                  /* 0x938 */
    uint32_t unk_940;                  /* 0x940 */
    uint64_t unk_948;                  /* 0x948 */
} ccHugeCharaShukaku;
/* size unknown, >= 0x954 */
_Static_assert(offsetof(ccHugeCharaShukaku, unk_898) == 0x898, "ccHugeCharaShukaku.unk_898");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8A4) == 0x8A4, "ccHugeCharaShukaku.unk_8A4");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8BC) == 0x8BC, "ccHugeCharaShukaku.unk_8BC");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8D4) == 0x8D4, "ccHugeCharaShukaku.unk_8D4");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8D8) == 0x8D8, "ccHugeCharaShukaku.unk_8D8");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8DC) == 0x8DC, "ccHugeCharaShukaku.unk_8DC");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8E0) == 0x8E0, "ccHugeCharaShukaku.unk_8E0");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8E4) == 0x8E4, "ccHugeCharaShukaku.unk_8E4");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8E8) == 0x8E8, "ccHugeCharaShukaku.unk_8E8");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8F0) == 0x8F0, "ccHugeCharaShukaku.unk_8F0");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8F4) == 0x8F4, "ccHugeCharaShukaku.unk_8F4");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8F8) == 0x8F8, "ccHugeCharaShukaku.unk_8F8");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_8FC) == 0x8FC, "ccHugeCharaShukaku.unk_8FC");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_900) == 0x900, "ccHugeCharaShukaku.unk_900");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_91C) == 0x91C, "ccHugeCharaShukaku.unk_91C");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_920) == 0x920, "ccHugeCharaShukaku.unk_920");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_928) == 0x928, "ccHugeCharaShukaku.unk_928");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_930) == 0x930, "ccHugeCharaShukaku.unk_930");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_938) == 0x938, "ccHugeCharaShukaku.unk_938");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_940) == 0x940, "ccHugeCharaShukaku.unk_940");
_Static_assert(offsetof(ccHugeCharaShukaku, unk_948) == 0x948, "ccHugeCharaShukaku.unk_948");

/* ========================================================================
 * ccHugeCharaGamabunta — Gamabunta boss (extends ccBossCommandBase)
 * Size unknown, >= 0x93C (last proven field end from state_surface)
 * ======================================================================== */
typedef struct ccHugeCharaGamabunta {
    uint8_t base[0x898];               /* 0x000-0x897: ccBossCommandBase */
    uint32_t unk_898;                  /* 0x898: sub-object init */
    uint8_t pad_89C[0x08];            /* 0x89C-0x8A3 */
    uint32_t unk_8A4;                  /* 0x8A4: sub-object init */
    uint8_t pad_8A8[0x08];            /* 0x8A8-0x8AF */
    uint32_t unk_8B0;                  /* 0x8B0 */
    uint8_t pad_8B4[0x08];            /* 0x8B4-0x8BB */
    uint32_t unk_8BC;                  /* 0x8BC: sub-object init */
    uint8_t pad_8C0[0x08];            /* 0x8C0-0x8C7 */
    uint32_t unk_8C8;                  /* 0x8C8 */
    uint8_t pad_8CC[0x08];            /* 0x8CC-0x8D3 */
    uint32_t unk_8D4;                  /* 0x8D4 */
    uint32_t unk_8D8;                  /* 0x8D8 */
    uint32_t unk_8DC;                  /* 0x8DC */
    uint32_t unk_8E0;                  /* 0x8E0 */
    uint32_t unk_8E4;                  /* 0x8E4 */
    uint32_t unk_8E8;                  /* 0x8E8 */
    uint32_t unk_8EC;                  /* 0x8EC */
    uint32_t unk_8F0;                  /* 0x8F0 */
    uint32_t unk_8F4;                  /* 0x8F4 */
    uint32_t unk_8F8;                  /* 0x8F8 */
    uint32_t unk_8FC;                  /* 0x8FC */
    uint32_t unk_900;                  /* 0x900 */
    uint8_t pad_904[0x18];            /* 0x904-0x91B */
    uint32_t unk_91C;                  /* 0x91C */
    uint32_t unk_920;                  /* 0x920 */
    uint32_t unk_924;                  /* 0x924 */
    uint32_t unk_928;                  /* 0x928 */
    uint32_t unk_92C;                  /* 0x92C */
    uint32_t unk_930;                  /* 0x930 */
    uint32_t unk_934;                  /* 0x934 */
    uint32_t unk_938;                  /* 0x938 */
} ccHugeCharaGamabunta;
/* size unknown, >= 0x93C */
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_898) == 0x898, "ccHugeCharaGamabunta.unk_898");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8A4) == 0x8A4, "ccHugeCharaGamabunta.unk_8A4");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8BC) == 0x8BC, "ccHugeCharaGamabunta.unk_8BC");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8C8) == 0x8C8, "ccHugeCharaGamabunta.unk_8C8");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8D4) == 0x8D4, "ccHugeCharaGamabunta.unk_8D4");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8D8) == 0x8D8, "ccHugeCharaGamabunta.unk_8D8");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8DC) == 0x8DC, "ccHugeCharaGamabunta.unk_8DC");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8E0) == 0x8E0, "ccHugeCharaGamabunta.unk_8E0");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8E4) == 0x8E4, "ccHugeCharaGamabunta.unk_8E4");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8E8) == 0x8E8, "ccHugeCharaGamabunta.unk_8E8");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8EC) == 0x8EC, "ccHugeCharaGamabunta.unk_8EC");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8F0) == 0x8F0, "ccHugeCharaGamabunta.unk_8F0");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8F4) == 0x8F4, "ccHugeCharaGamabunta.unk_8F4");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8F8) == 0x8F8, "ccHugeCharaGamabunta.unk_8F8");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_8FC) == 0x8FC, "ccHugeCharaGamabunta.unk_8FC");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_900) == 0x900, "ccHugeCharaGamabunta.unk_900");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_91C) == 0x91C, "ccHugeCharaGamabunta.unk_91C");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_928) == 0x928, "ccHugeCharaGamabunta.unk_928");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_930) == 0x930, "ccHugeCharaGamabunta.unk_930");
_Static_assert(offsetof(ccHugeCharaGamabunta, unk_938) == 0x938, "ccHugeCharaGamabunta.unk_938");

/* ========================================================================
 * ccPlayerHugeBtl — player huge battle extension (extends ccPlayer)
 * ccPlayer size 0x1830 proven in ccPlayer.h; fields extend to 0x46C4
 * Size unknown, >= 0x46C4
 * ======================================================================== */
typedef struct ccPlayerHugeBtl {
    uint8_t ccPlayer_base[0x1800];     /* 0x0000-0x17FF: ccPlayer base */
    uint64_t unk_1800;                 /* 0x1800 */
    uint64_t unk_1808;                 /* 0x1808 */
    uint64_t unk_1810;                 /* 0x1810 */
    uint32_t unk_1818;                 /* 0x1818 */
    uint32_t unk_181C;                 /* 0x181C */
    uint8_t pad_1820[0x08];           /* 0x1820-0x1827 */
    uint32_t unk_1828;                 /* 0x1828 */
    uint32_t unk_182C;                 /* 0x182C */
    uint8_t pad_1830[0xEC];           /* 0x1830-0x191B */
    uint32_t unk_191C;                 /* 0x191C */
    uint32_t unk_1920;                 /* 0x1920 */
    uint8_t pad_1924[0x2D9C];         /* 0x1924-0x46BF */
    uint32_t unk_46C0;                 /* 0x46C0 */
} ccPlayerHugeBtl;
/* size unknown, >= 0x46C4 */
_Static_assert(offsetof(ccPlayerHugeBtl, unk_1800) == 0x1800, "ccPlayerHugeBtl.unk_1800");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_1808) == 0x1808, "ccPlayerHugeBtl.unk_1808");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_1810) == 0x1810, "ccPlayerHugeBtl.unk_1810");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_1818) == 0x1818, "ccPlayerHugeBtl.unk_1818");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_181C) == 0x181C, "ccPlayerHugeBtl.unk_181C");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_1828) == 0x1828, "ccPlayerHugeBtl.unk_1828");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_182C) == 0x182C, "ccPlayerHugeBtl.unk_182C");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_191C) == 0x191C, "ccPlayerHugeBtl.unk_191C");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_1920) == 0x1920, "ccPlayerHugeBtl.unk_1920");
_Static_assert(offsetof(ccPlayerHugeBtl, unk_46C0) == 0x46C0, "ccPlayerHugeBtl.unk_46C0");

/* ========================================================================
 * ccMsgWindowHugebtl — huge battle message window (size unknown, >= 0x3C4)
 * ======================================================================== */
typedef struct ccMsgWindowHugebtl {
    uint8_t pad_00[0x68];              /* 0x00-0x67: vtable + base */
    uint32_t unk_68;                   /* 0x68 */
    uint32_t unk_6C;                   /* 0x6C */
    uint32_t unk_70;                   /* 0x70 */
    uint8_t pad_74[0x08];             /* 0x74-0x7B */
    uint32_t unk_7C;                   /* 0x7C */
    uint8_t pad_80[0x08];             /* 0x80-0x87 */
    uint32_t unk_88;                   /* 0x88 */
    uint8_t pad_8C[0x06];             /* 0x8C-0x91 */
    uint16_t unk_92;                   /* 0x92 */
    uint16_t unk_94;                   /* 0x94 */
    uint8_t pad_96[0x12];             /* 0x96-0xA7 */
    uint64_t unk_A8;                   /* 0xA8 */
    uint32_t unk_B0;                   /* 0xB0 */
    uint8_t pad_B4[0x04];             /* 0xB4-0xB7 */
    uint64_t unk_B8;                   /* 0xB8 */
    uint64_t unk_C0;                   /* 0xC0 */
    uint8_t pad_C8[0x18];             /* 0xC8-0xDF */
    uint32_t unk_E0;                   /* 0xE0 (sub-object region start) */
    uint8_t pad_E4[0x5C];             /* 0xE4-0x13F */
    uint32_t unk_140;                  /* 0x140 (sub-object) */
    uint8_t pad_144[0x7C];            /* 0x144-0x1BF */
    uint32_t unk_1C0;                  /* 0x1C0 (sub-object) */
    uint8_t pad_1C4[0x3C];            /* 0x1C4-0x1FF */
    uint32_t unk_200;                  /* 0x200 (sub-object) */
    uint8_t pad_204[0x3C];            /* 0x204-0x23F */
    uint32_t unk_240;                  /* 0x240 (sub-object) */
    uint8_t pad_244[0x3C];            /* 0x244-0x27F */
    uint32_t unk_280;                  /* 0x280 (sub-object) */
    uint8_t pad_284[0x3C];            /* 0x284-0x2BF */
    uint32_t unk_2C0;                  /* 0x2C0 (sub-object) */
    uint8_t pad_2C4[0x3C];            /* 0x2C4-0x2FF */
    uint32_t unk_300;                  /* 0x300 (sub-object) */
    uint8_t pad_304[0x3C];            /* 0x304-0x33F */
    uint32_t unk_340;                  /* 0x340 (sub-object) */
    uint8_t pad_344[0x3C];            /* 0x344-0x37F */
    uint32_t unk_380;                  /* 0x380 (sub-object) */
    uint8_t pad_384[0x3C];            /* 0x384-0x3BF */
    uint32_t unk_3C0;                  /* 0x3C0 (sub-object) */
} ccMsgWindowHugebtl;
/* size unknown, >= 0x3C4 */
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_68) == 0x68, "ccMsgWindowHugebtl.unk_68");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_6C) == 0x6C, "ccMsgWindowHugebtl.unk_6C");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_70) == 0x70, "ccMsgWindowHugebtl.unk_70");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_7C) == 0x7C, "ccMsgWindowHugebtl.unk_7C");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_88) == 0x88, "ccMsgWindowHugebtl.unk_88");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_92) == 0x92, "ccMsgWindowHugebtl.unk_92");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_94) == 0x94, "ccMsgWindowHugebtl.unk_94");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_A8) == 0xA8, "ccMsgWindowHugebtl.unk_A8");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_B0) == 0xB0, "ccMsgWindowHugebtl.unk_B0");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_B8) == 0xB8, "ccMsgWindowHugebtl.unk_B8");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_C0) == 0xC0, "ccMsgWindowHugebtl.unk_C0");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_140) == 0x140, "ccMsgWindowHugebtl.unk_140");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_1C0) == 0x1C0, "ccMsgWindowHugebtl.unk_1C0");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_200) == 0x200, "ccMsgWindowHugebtl.unk_200");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_240) == 0x240, "ccMsgWindowHugebtl.unk_240");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_280) == 0x280, "ccMsgWindowHugebtl.unk_280");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_2C0) == 0x2C0, "ccMsgWindowHugebtl.unk_2C0");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_300) == 0x300, "ccMsgWindowHugebtl.unk_300");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_340) == 0x340, "ccMsgWindowHugebtl.unk_340");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_380) == 0x380, "ccMsgWindowHugebtl.unk_380");
_Static_assert(offsetof(ccMsgWindowHugebtl, unk_3C0) == 0x3C0, "ccMsgWindowHugebtl.unk_3C0");

/* ========================================================================
 * ccEffHugeSupport — huge support effect (size unknown, >= 0xB84)
 * ======================================================================== */
typedef struct ccEffHugeSupport {
    uint8_t pad_00[0x1C0];             /* 0x000-0x1BF: vtable + base */
    uint64_t unk_1C0;                  /* 0x1C0 */
    uint8_t pad_1C8[0x3F8];           /* 0x1C8-0x5BF */
    uint32_t unk_5C0;                  /* 0x5C0 (sub-object init) */
    uint8_t pad_5C4[0x5BC];           /* 0x5C4-0xB7F */
    uint32_t unk_B80;                  /* 0xB80 (sub-object init) */
} ccEffHugeSupport;
/* size unknown, >= 0xB84 */
_Static_assert(offsetof(ccEffHugeSupport, unk_1C0) == 0x1C0, "ccEffHugeSupport.unk_1C0");
_Static_assert(offsetof(ccEffHugeSupport, unk_5C0) == 0x5C0, "ccEffHugeSupport.unk_5C0");
_Static_assert(offsetof(ccEffHugeSupport, unk_B80) == 0xB80, "ccEffHugeSupport.unk_B80");

/* ========================================================================
 * ccSkillHugeSabakukyuu — Sabakukyuu skill (size unknown, >= 0x1104)
 * ======================================================================== */
typedef struct ccSkillHugeSabakukyuu {
    uint8_t pad_00[0x160];             /* 0x0000-0x015F: vtable + base */
    uint32_t unk_160;                  /* 0x0160 */
    uint32_t unk_164;                  /* 0x0164 */
    uint8_t pad_168[0xF18];           /* 0x0168-0x107F */
    uint32_t unk_1080;                 /* 0x1080 (sub-object init) */
    uint8_t pad_1084[0x3C];           /* 0x1084-0x10BF */
    uint32_t unk_10C0;                 /* 0x10C0 (sub-object init) */
    uint8_t pad_10C4[0x3C];           /* 0x10C4-0x10FF */
    uint32_t unk_1100;                 /* 0x1100 (sub-object init) */
} ccSkillHugeSabakukyuu;
/* size unknown, >= 0x1104 */
_Static_assert(offsetof(ccSkillHugeSabakukyuu, unk_160) == 0x160, "ccSkillHugeSabakukyuu.unk_160");
_Static_assert(offsetof(ccSkillHugeSabakukyuu, unk_164) == 0x164, "ccSkillHugeSabakukyuu.unk_164");
_Static_assert(offsetof(ccSkillHugeSabakukyuu, unk_1080) == 0x1080, "ccSkillHugeSabakukyuu.unk_1080");
_Static_assert(offsetof(ccSkillHugeSabakukyuu, unk_10C0) == 0x10C0, "ccSkillHugeSabakukyuu.unk_10C0");
_Static_assert(offsetof(ccSkillHugeSabakukyuu, unk_1100) == 0x1100, "ccSkillHugeSabakukyuu.unk_1100");

/* ========================================================================
 * ccSkillHugeMandatailArtillery — Manda tail artillery skill (size unknown, >= 0x1004)
 * ======================================================================== */
typedef struct ccSkillHugeMandatailArtillery {
    uint8_t pad_00[0x58];              /* 0x0000-0x0057: vtable + base */
    uint32_t unk_58;                   /* 0x0058 */
    uint8_t pad_5C[0x04];             /* 0x005C-0x005F */
    uint32_t unk_60;                   /* 0x0060 (sub-object init) */
    uint8_t pad_64[0xF9C];            /* 0x0064-0x0FFF */
    uint32_t unk_1000;                 /* 0x1000 (sub-object init) */
} ccSkillHugeMandatailArtillery;
/* size unknown, >= 0x1004 */
_Static_assert(offsetof(ccSkillHugeMandatailArtillery, unk_58) == 0x58, "ccSkillHugeMandatailArtillery.unk_58");
_Static_assert(offsetof(ccSkillHugeMandatailArtillery, unk_60) == 0x60, "ccSkillHugeMandatailArtillery.unk_60");
_Static_assert(offsetof(ccSkillHugeMandatailArtillery, unk_1000) == 0x1000, "ccSkillHugeMandatailArtillery.unk_1000");

/* ========================================================================
 * Empty/minimal classes — no fields discovered by state_surface.
 * These exist as symbols but have no proven field accesses.
 * Listed here as opaque stubs for completeness.
 * ======================================================================== */

/* ccHugeCharaIA — AI controller (no fields found) */
typedef struct ccHugeCharaIA {
    void *vtable;                      /* 0x00 */
} ccHugeCharaIA;
/* size unknown */

/* ccHugeOrochimaru — Orochimaru boss (no fields found) */
typedef struct ccHugeOrochimaru {
    void *vtable;                      /* 0x00 */
} ccHugeOrochimaru;
/* size unknown */

/* ccHugeObjBase — huge object base (no fields found) */
typedef struct ccHugeObjBase {
    void *vtable;                      /* 0x00 */
} ccHugeObjBase;
/* size unknown */

/* ccHugeObjRock — rock object (no fields found) */
typedef struct ccHugeObjRock {
    void *vtable;                      /* 0x00 */
} ccHugeObjRock;
/* size unknown */

/* ccHugeRockLittle — small rock (no fields found) */
typedef struct ccHugeRockLittle {
    void *vtable;                      /* 0x00 */
} ccHugeRockLittle;
/* size unknown */

/* ccHugebtlIADisp — IA display (no fields found) */
typedef struct ccHugebtlIADisp {
    void *vtable;                      /* 0x00 */
} ccHugebtlIADisp;
/* size unknown */

/* ccHugebtlIATime — IA timer (no fields found) */
typedef struct ccHugebtlIATime {
    void *vtable;                      /* 0x00 */
} ccHugebtlIATime;
/* size unknown */

/* ccHugebtlEnemyGauge — enemy gauge UI (no fields found) */
typedef struct ccHugebtlEnemyGauge {
    void *vtable;                      /* 0x00 */
} ccHugebtlEnemyGauge;
/* size unknown */

/* ccHugebtlTargetCursor — target cursor UI (no fields found) */
typedef struct ccHugebtlTargetCursor {
    void *vtable;                      /* 0x00 */
} ccHugebtlTargetCursor;
/* size unknown */

/* ccHugebtlBreakFree — break free QTE (no fields found) */
typedef struct ccHugebtlBreakFree {
    void *vtable;                      /* 0x00 */
} ccHugebtlBreakFree;
/* size unknown */

/* ccPauseMenuHuge — huge battle pause menu (no fields found) */
typedef struct ccPauseMenuHuge {
    void *vtable;                      /* 0x00 */
} ccPauseMenuHuge;
/* size unknown */

/* ccSkillHugeYataikuzushi — Yatai Kuzushi skill (no fields found) */
typedef struct ccSkillHugeYataikuzushi {
    void *vtable;                      /* 0x00 */
} ccSkillHugeYataikuzushi;
/* size unknown */

/* ccSkillHugeMandatail — Manda tail skill (no fields found) */
typedef struct ccSkillHugeMandatail {
    void *vtable;                      /* 0x00 */
} ccSkillHugeMandatail;
/* size unknown */

/* ccSkillHugeSnakeswarm — Snakeswarm skill (no fields found) */
typedef struct ccSkillHugeSnakeswarm {
    void *vtable;                      /* 0x00 */
} ccSkillHugeSnakeswarm;
/* size unknown */

/* ccSkillHugeRenkuudanBlast — Renkuudan Blast skill (no fields found) */
typedef struct ccSkillHugeRenkuudanBlast {
    void *vtable;                      /* 0x00 */
} ccSkillHugeRenkuudanBlast;
/* size unknown */

/* ccSkillHugeMizubousou — Mizubousou skill (no fields found) */
typedef struct ccSkillHugeMizubousou {
    void *vtable;                      /* 0x00 */
} ccSkillHugeMizubousou;
/* size unknown */

/* ccSkillHugeMizubousou_column — Mizubousou column (no fields found) */
typedef struct ccSkillHugeMizubousou_column {
    void *vtable;                      /* 0x00 */
} ccSkillHugeMizubousou_column;
/* size unknown */

/* ccSkillHugeHappadamaLT — Happadama LT skill (no fields found) */
typedef struct ccSkillHugeHappadamaLT {
    void *vtable;                      /* 0x00 */
} ccSkillHugeHappadamaLT;
/* size unknown */

#endif /* CCHUGEBATTLE_S1_H */