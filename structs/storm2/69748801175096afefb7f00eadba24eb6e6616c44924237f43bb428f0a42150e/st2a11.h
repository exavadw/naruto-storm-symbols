/* st2a11.h — Story struct group for NARUTO STORM 2 PC (NSUNS2.exe, build s2)
 * Generated from storm_state_surface analysis. All layouts INFERRED (static only).
 * Sizes proven from operator new / allocator where noted; otherwise ">= last field".
 * Own-game names only (ns2:: / Storm 2 strings). No cross-game name leakage.
 */
#ifndef ST2A11_H
#define ST2A11_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ------------------------------------------------------------------ */
/* ccAdvSpriteScDraw                                                   */
/* Size: unknown, >= 0x74 (last field at 0x70, sz=4)                  */
/* Evidence: ccAdvSpriteScDraw ctor writes undefined4 at +0x70         */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAdvSpriteScDraw {
    uint8_t _pad_0x00[0x70];              /* 0x00 - 0x6F */
    uint32_t field_0x70;                  /* 0x70, sz=4, w, high confidence */
} ccAdvSpriteScDraw;
static_assert(offsetof(ccAdvSpriteScDraw, field_0x70) == 0x70, "ccAdvSpriteScDraw.field_0x70");

/* ------------------------------------------------------------------ */
/* ccAdvRoofCamera                                                     */
/* Size: unknown, >= 0x1C0 (from LoadTh size in summary context)       */
/* Last observed field at 0x1B8                                        */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAdvRoofCamera {
    uint8_t _pad_0x00[0x1B0];             /* 0x00 - 0x1AF */
    uint64_t field_0x1B0;                 /* 0x1B0, sz=8, w, medium */
    uint8_t _pad_0x1B8[0x8];              /* 0x1B8 read-only ref, not a stored field */
} ccAdvRoofCamera;
static_assert(offsetof(ccAdvRoofCamera, field_0x1B0) == 0x1B0, "ccAdvRoofCamera.field_0x1B0");

/* ------------------------------------------------------------------ */
/* ccAdvScDraw                                                         */
/* Size: unknown, >= 0x2C4 (last write at 0x2C0, sz=4)                */
/* Note: fields at 0x14B8/0x14C0 appear shared with ccAdvPlayerUiMgr   */
/*       (same offset pattern); likely base-class or union overlap.    */
/*       Treating as independent class per state_surface output.        */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAdvScDraw {
    uint8_t _pad_0x00[0x14B8];            /* 0x00 - 0x14B7 */
    uint64_t field_0x14B8;                /* 0x14B8, sz=8, w, medium */
    uint64_t field_0x14C0;                /* 0x14C0, sz=8, w, medium */
    uint8_t _pad_0x14C8[0x138];           /* 0x14C8 read ref, gap to 0x1600 */
    uint32_t field_0x1600;                /* 0x1600, sz=4, w, medium */
} ccAdvScDraw;
static_assert(offsetof(ccAdvScDraw, field_0x14B8) == 0x14B8, "ccAdvScDraw.field_0x14B8");
static_assert(offsetof(ccAdvScDraw, field_0x14C0) == 0x14C0, "ccAdvScDraw.field_0x14C0");
static_assert(offsetof(ccAdvScDraw, field_0x1600) == 0x1600, "ccAdvScDraw.field_0x1600");

/* ------------------------------------------------------------------ */
/* ccAdvObjectStateList                                                */
/* Size: unknown, >= 0x1720 (last field access at 0x1718+8)           */
/* Contains two parallel array-pointer pairs (vector-like):            */
/*   [0x15F0] r-only ptr, [0x16D0..0x16E8] rw pair                   */
/*   [0x1700] r-only ptr, [0x1708..0x1718] rw pair                   */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAdvObjectStateList {
    uint8_t _pad_0x00[0x15F0];            /* 0x00 - 0x15EF */
    uint64_t ptr_0x15F0;                  /* 0x15F0, r, low — array base ptr */
    uint8_t _pad_0x15F8[0xD8];            /* 0x15F8 - 0x16CF */
    uint64_t arr_begin_0x16D0;            /* 0x16D0, r, low — vector begin */
    uint64_t arr_end_0x16D8;              /* 0x16D8, sz=8, rw, medium — vector end */
    uint8_t _pad_0x16E0[0x8];             /* 0x16E0 - 0x16E7 */
    uint64_t field_0x16E8;                /* 0x16E8, sz=8, rw, low */
    uint8_t _pad_0x16F0[0x10];            /* 0x16F0 - 0x16FF */
    uint64_t ptr_0x1700;                  /* 0x1700, r, low — second array base */
    uint64_t arr2_begin_0x1708;           /* 0x1708, sz=8, rw, medium */
    uint8_t _pad_0x1710[0x8];             /* 0x1710 - 0x1717 */
    uint64_t field_0x1718;                /* 0x1718, sz=8, rw, low */
} ccAdvObjectStateList;
static_assert(offsetof(ccAdvObjectStateList, ptr_0x15F0) == 0x15F0, "ccAdvObjectStateList.ptr_0x15F0");
static_assert(offsetof(ccAdvObjectStateList, arr_begin_0x16D0) == 0x16D0, "ccAdvObjectStateList.arr_begin_0x16D0");
static_assert(offsetof(ccAdvObjectStateList, arr_end_0x16D8) == 0x16D8, "ccAdvObjectStateList.arr_end_0x16D8");
static_assert(offsetof(ccAdvObjectStateList, field_0x16E8) == 0x16E8, "ccAdvObjectStateList.field_0x16E8");
static_assert(offsetof(ccAdvObjectStateList, ptr_0x1700) == 0x1700, "ccAdvObjectStateList.ptr_0x1700");
static_assert(offsetof(ccAdvObjectStateList, arr2_begin_0x1708) == 0x1708, "ccAdvObjectStateList.arr2_begin_0x1708");
static_assert(offsetof(ccAdvObjectStateList, field_0x1718) == 0x1718, "ccAdvObjectStateList.field_0x1718");

/* ------------------------------------------------------------------ */
/* ccAdvPlayerUiManager                                                */
/* Size: unknown, >= 0x1588 (from LoadTh size in summary context)      */
/* 20 fields observed; dense block of uint64 writes at 0x14B8-0x1510  */
/* followed by scattered accesses through 0x1580                       */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAdvPlayerUiManager {
    uint8_t _pad_0x00[0x14B8];            /* 0x00 - 0x14B7 */
    uint64_t slot_0x14B8;                 /* 0x14B8, sz=8, w, medium — param_1[0x297]=0 */
    uint64_t slot_0x14C0;                 /* 0x14C0, sz=8, w, medium — param_1[0x298]=0 */
    uint64_t slot_0x14C8;                 /* 0x14C8, sz=8, w, medium */
    uint64_t slot_0x14D0;                 /* 0x14D0, sz=8, w, medium */
    uint64_t slot_0x14D8;                 /* 0x14D8, sz=8, w, medium */
    uint64_t slot_0x14E0;                 /* 0x14E0, sz=8, w, medium */
    uint64_t slot_0x14E8;                 /* 0x14E8, sz=8, w, medium */
    uint64_t slot_0x14F0;                 /* 0x14F0, sz=8, w, medium */
    uint64_t slot_0x14F8;                 /* 0x14F8, sz=8, w, medium */
    uint64_t ptr_0x1500;                  /* 0x1500, r, low — param_1+0x2a0 */
    uint64_t slot_0x1508;                 /* 0x1508, sz=8, w, medium */
    uint64_t slot_0x1510;                 /* 0x1510, sz=8, rw, medium */
    uint64_t field_0x1518;                /* 0x1518, sz=8, rw, low */
    uint8_t _pad_0x1520[0x10];            /* 0x1520 - 0x152F */
    uint64_t ptr_0x1530;                  /* 0x1530, r, low */
    uint8_t _pad_0x1538[0x8];             /* 0x1538 - 0x153F */
    uint64_t index_0x1540;                /* 0x1540, sz=8, rw, medium — param_1[0x2a8] */
    uint64_t limit_0x1548;                /* 0x1548, sz=8, r, medium — compared < 0x21 */
    uint8_t _pad_0x1550[0x18];            /* 0x1550 - 0x1567 */
    uint64_t slot_0x1568;                 /* 0x1568, sz=8, w, medium */
    uint32_t field_0x1570;                /* 0x1570, sz=4, w, medium */
    uint8_t _pad_0x1574[0x4];             /* 0x1574 - 0x1577 */
    uint64_t ptr_0x1578;                  /* 0x1578, sz=8, w, medium */
    uint32_t field_0x1580;                /* 0x1580, sz=4, w, medium */
} ccAdvPlayerUiManager;
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14B8) == 0x14B8, "ccAdvPlayerUiManager.slot_0x14B8");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14C0) == 0x14C0, "ccAdvPlayerUiManager.slot_0x14C0");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14C8) == 0x14C8, "ccAdvPlayerUiManager.slot_0x14C8");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14D0) == 0x14D0, "ccAdvPlayerUiManager.slot_0x14D0");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14D8) == 0x14D8, "ccAdvPlayerUiManager.slot_0x14D8");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14E0) == 0x14E0, "ccAdvPlayerUiManager.slot_0x14E0");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14E8) == 0x14E8, "ccAdvPlayerUiManager.slot_0x14E8");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14F0) == 0x14F0, "ccAdvPlayerUiManager.slot_0x14F0");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x14F8) == 0x14F8, "ccAdvPlayerUiManager.slot_0x14F8");
static_assert(offsetof(ccAdvPlayerUiManager, ptr_0x1500) == 0x1500, "ccAdvPlayerUiManager.ptr_0x1500");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x1508) == 0x1508, "ccAdvPlayerUiManager.slot_0x1508");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x1510) == 0x1510, "ccAdvPlayerUiManager.slot_0x1510");
static_assert(offsetof(ccAdvPlayerUiManager, field_0x1518) == 0x1518, "ccAdvPlayerUiManager.field_0x1518");
static_assert(offsetof(ccAdvPlayerUiManager, ptr_0x1530) == 0x1530, "ccAdvPlayerUiManager.ptr_0x1530");
static_assert(offsetof(ccAdvPlayerUiManager, index_0x1540) == 0x1540, "ccAdvPlayerUiManager.index_0x1540");
static_assert(offsetof(ccAdvPlayerUiManager, limit_0x1548) == 0x1548, "ccAdvPlayerUiManager.limit_0x1548");
static_assert(offsetof(ccAdvPlayerUiManager, slot_0x1568) == 0x1568, "ccAdvPlayerUiManager.slot_0x1568");
static_assert(offsetof(ccAdvPlayerUiManager, field_0x1570) == 0x1570, "ccAdvPlayerUiManager.field_0x1570");
static_assert(offsetof(ccAdvPlayerUiManager, ptr_0x1578) == 0x1578, "ccAdvPlayerUiManager.ptr_0x1578");
static_assert(offsetof(ccAdvPlayerUiManager, field_0x1580) == 0x1580, "ccAdvPlayerUiManager.field_0x1580");

/* ------------------------------------------------------------------ */
/* ccAdvSaveData                                                       */
/* Size: unknown, >= 0x12000 (max uint-indexed offset 0x47ea*4=0x11FA8*/
/*   + padding). Global singleton accessed via RestartAdvSaveData.     */
/* 56 fields observed across wide offset range (0x4004 - 0x11FDC).     */
/* Dense uint32 array at tail (0x11F54 - 0x11FA8) = 22 consecutive    */
/*   uint32 slots, likely an unlock/progression flag table.            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ccAdvSaveData {
    uint8_t _pad_0x0000[0x4004];          /* 0x0000 - 0x4003 */
    uint32_t restart_flag_0x4004;         /* 0x4004, sz=4, w, medium — [0x1001]=0 */
    uint32_t restart_flag_0x4008;         /* 0x4008, sz=4, w, medium — [0x1002]=0 */
    uint8_t _pad_0x400C[0x100];           /* 0x400C - 0x410B */
    uint8_t *ptr_0x410C;                  /* 0x410C, r, low — param_1+0x1043 */
    uint8_t _pad_0x4114[0xF8];            /* 0x4114 - 0x420B */
    uint32_t field_0x420C;                /* 0x420C, sz=4, w, medium — [0x1083]=0 */
    uint8_t memset_region_0x4210[0x80];   /* 0x4210, r, low — memset 0x80 bytes */
    uint8_t _pad_0x4290[0x4];             /* 0x4290 - 0x4293 */
    uint32_t field_0x4294;                /* 0x4294, sz=4, w, medium — [0x10a5]=0 */
    uint8_t *ptr_0x4298;                  /* 0x4298, r, low — param_1+0x10a6 */
    uint8_t _pad_0x42A0[0x90];            /* 0x42A0 - 0x432F */
    uint32_t init_val_0x4330;             /* 0x4330, sz=4, w, medium — [0x10cc]=1 */
    uint8_t _pad_0x4334[0x4];             /* 0x4334 - 0x4337 */
    uint32_t init_val_0x4338;             /* 0x4338, sz=4, w, medium — [0x10ce]=1 */
    uint8_t _pad_0x433C[0x975C];          /* 0x433C - 0xDA97 */
    uint32_t init_val_0xDA98;             /* 0xDA98, sz=4, w, medium — [0x36a6]=1 */
    uint8_t _pad_0xDA9C[0x14];            /* 0xDA9C - 0xDAaf */
    uint8_t *ptr_0xDAB0;                  /* 0xDAB0, r, low — param_1+0x36ac */
    uint8_t _pad_0xDAB8[0xC];             /* 0xDAB8 - 0xDAC3 */
    uint16_t field_0xDAC4;                /* 0xDAC4, sz=2, w, medium */
    uint8_t zero_0xDAC6[8];               /* 0xDAC6, sz=8, w, medium */
    uint8_t zero_0xDACE[8];               /* 0xDACE, sz=8, w, medium */
    uint8_t zero_0xDAD6[8];               /* 0xDAD6, sz=8, w, medium */
    uint8_t zero_0xDADE[8];               /* 0xDADE, sz=8, w, medium */
    uint8_t _pad_0xDAE6[0x2];             /* 0xDAE6 - 0xDAE7 */
    uint32_t field_0xDAE8;                /* 0xDAE8, sz=4, w, medium — [0x36ba]=0 */
    uint32_t field_0xDAEC;                /* 0xDAEC, sz=4, w, medium — [0x36bb]=0 */
    uint8_t _pad_0xDAF0[0x4];             /* 0xDAF0 - 0xDAF3 */
    uint8_t *ptr_0xDAF4;                  /* 0xDAF4, r, low — param_1+0x36bd */
    uint8_t _pad_0xDAFC[0x7F4];           /* 0xDAFC - 0xE2EF */
    uint8_t *ptr_0xE2F0;                  /* 0xE2F0, r, low — param_1+0x38bc */
    uint8_t _pad_0xE2F8[0x18];            /* 0xE2F8 - 0xE30F */
    uint32_t field_0xE310;                /* 0xE310, sz=4, w, medium — [0x38c4]=0 */
    uint8_t *ptr_0xE314;                  /* 0xE314, r, low — param_1+0x38c5 */
    uint8_t _pad_0xE31C[0xBFC];           /* 0xE31C - 0xEF17 */
    uint32_t field_0xEF18;                /* 0xEF18, sz=4, w, medium — [0x3bc6]=0 */
    uint8_t _pad_0xEF1C[0x4];             /* 0xEF1C - 0xEF1F */
    uint8_t *ptr_0xEF20;                  /* 0xEF20, r, low — param_1+0x3bc8 */
    uint8_t _pad_0xEF28[0x3F4];           /* 0xEF28 - 0xF31B */
    uint32_t field_0xF31C;                /* 0xF31C, sz=4, w, medium — [0x3cc7]=0 */
    uint8_t _pad_0xF320[0x408];           /* 0xF320 - 0xF727 */
    uint8_t *ptr_0xF728;                  /* 0xF728, r, low — param_1+0x3dca */
    uint8_t _pad_0xF730[0x7F8];           /* 0xF730 - 0xFF27 */
    uint8_t *ptr_0xFF28;                  /* 0xFF28, r, low — param_1+0x3fca */
    uint8_t _pad_0xFF30[0x1000];          /* 0xFF30 - 0x10F2F */
    uint8_t memset_region_0x10F30[0xE8];  /* 0x10F30, r, low — memset 0xe8 bytes */
    uint8_t _pad_0x11018[0x318];          /* 0x11018 - 0x1132F */
    uint32_t tail_slot_0x11330;           /* 0x11330, sz=4, w, medium — [0x44cc]=0 */
    uint32_t tail_slot_0x11334;           /* 0x11334, sz=4, w, medium — [0x44cd]=0 */
    uint32_t tail_slot_0x11338;           /* 0x11338, sz=4, w, medium — [0x44ce]=0 */
    uint32_t tail_slot_0x1133C;           /* 0x1133C, sz=4, w, medium — [0x44cf]=0 */
    uint32_t tail_slot_0x11340;           /* 0x11340, sz=4, w, medium — [0x44d0]=0 */
    uint8_t _pad_0x11344[0xC10];          /* 0x11344 - 0x11F53 */
    /* Dense uint32 progression/unlock table: 22 slots, 0x11F54 - 0x11FA8 */
    uint32_t prog_0x11F54;                /* 0x11F54, sz=4, w, medium — [0x47d5] */
    uint32_t prog_0x11F58;                /* 0x11F58, sz=4, w, high  — [0x47d6] */
    uint32_t prog_0x11F5C;                /* 0x11F5C, sz=4, w, high  — [0x47d7] */
    uint32_t prog_0x11F60;                /* 0x11F60, sz=4, w, high  — [0x47d8] */
    uint32_t prog_0x11F64;                /* 0x11F64, sz=4, w, high  — [0x47d9] */
    uint32_t prog_0x11F68;                /* 0x11F68, sz=4, w, high  — [0x47da] */
    uint32_t prog_0x11F6C;                /* 0x11F6C, sz=4, w, high  — [0x47db] */
    uint32_t prog_0x11F70;                /* 0x11F70, sz=4, w, high  — [0x47dc] */
    uint32_t prog_0x11F74;                /* 0x11F74, sz=4, w, high  — [0x47dd] */
    uint32_t prog_0x11F78;                /* 0x11F78, sz=4, w, medium — [0x47de] */
    uint32_t prog_0x11F7C;                /* 0x11F7C, sz=4, w, medium — [0x47df] */
    uint32_t prog_0x11F80;                /* 0x11F80, sz=4, w, medium — [0x47e0] */
    uint32_t prog_0x11F84;                /* 0x11F84, sz=4, w, medium — [0x47e1] */
    uint32_t prog_0x11F88;                /* 0x11F88, sz=4, w, medium — [0x47e2] */
    uint32_t prog_0x11F8C;                /* 0x11F8C, sz=4, w, medium — [0x47e3] */
    uint32_t prog_0x11F90;                /* 0x11F90, sz=4, w, medium — [0x47e4] */
    uint32_t prog_0x11F94;                /* 0x11F94, sz=4, w, medium — [0x47e5] */
    uint32_t prog_0x11F98;                /* 0x11F98, sz=4, w, medium — [0x47e6] */
    uint32_t prog_0x11F9C;                /* 0x11F9C, sz=4, w, medium — [0x47e7] */
    uint32_t prog_0x11FA0;                /* 0x11FA0, sz=4, w, medium — [0x47e8] */
    uint32_t prog_0x11FA4;                /* 0x11FA4, sz=4, w, medium — [0x47e9] */
    uint32_t prog_0x11FA8;                /* 0x11FA8, sz=4, w, medium — [0x47ea] */
    uint8_t _pad_0x11FAC[0x30];           /* 0x11FAC - 0x11FDB */
    uint8_t *ptr_0x11FDC;                 /* 0x11FDC, r, low — param_1+0x47f7 */
} ccAdvSaveData;
static_assert(offsetof(ccAdvSaveData, restart_flag_0x4004) == 0x4004, "ccAdvSaveData.restart_flag_0x4004");
static_assert(offsetof(ccAdvSaveData, restart_flag_0x4008) == 0x4008, "ccAdvSaveData.restart_flag_0x4008");
static_assert(offsetof(ccAdvSaveData, field_0x420C) == 0x420C, "ccAdvSaveData.field_0x420C");
static_assert(offsetof(ccAdvSaveData, memset_region_0x4210) == 0x4210, "ccAdvSaveData.memset_region_0x4210");
static_assert(offsetof(ccAdvSaveData, field_0x4294) == 0x4294, "ccAdvSaveData.field_0x4294");
static_assert(offsetof(ccAdvSaveData, init_val_0x4330) == 0x4330, "ccAdvSaveData.init_val_0x4330");
static_assert(offsetof(ccAdvSaveData, init_val_0x4338) == 0x4338, "ccAdvSaveData.init_val_0x4338");
static_assert(offsetof(ccAdvSaveData, init_val_0xDA98) == 0xDA98, "ccAdvSaveData.init_val_0xDA98");
static_assert(offsetof(ccAdvSaveData, field_0xDAC4) == 0xDAC4, "ccAdvSaveData.field_0xDAC4");
static_assert(offsetof(ccAdvSaveData, zero_0xDAC6) == 0xDAC6, "ccAdvSaveData.zero_0xDAC6");
static_assert(offsetof(ccAdvSaveData, zero_0xDACE) == 0xDACE, "ccAdvSaveData.zero_0xDACE");
static_assert(offsetof(ccAdvSaveData, zero_0xDAD6) == 0xDAD6, "ccAdvSaveData.zero_0xDAD6");
static_assert(offsetof(ccAdvSaveData, zero_0xDADE) == 0xDADE, "ccAdvSaveData.zero_0xDADE");
static_assert(offsetof(ccAdvSaveData, field_0xDAE8) == 0xDAE8, "ccAdvSaveData.field_0xDAE8");
static_assert(offsetof(ccAdvSaveData, field_0xDAEC) == 0xDAEC, "ccAdvSaveData.field_0xDAEC");
static_assert(offsetof(ccAdvSaveData, field_0xE310) == 0xE310, "ccAdvSaveData.field_0xE310");
static_assert(offsetof(ccAdvSaveData, field_0xEF18) == 0xEF18, "ccAdvSaveData.field_0xEF18");
static_assert(offsetof(ccAdvSaveData, field_0xF31C) == 0xF31C, "ccAdvSaveData.field_0xF31C");
static_assert(offsetof(ccAdvSaveData, memset_region_0x10F30) == 0x10F30, "ccAdvSaveData.memset_region_0x10F30");
static_assert(offsetof(ccAdvSaveData, tail_slot_0x11330) == 0x11330, "ccAdvSaveData.tail_slot_0x11330");
static_assert(offsetof(ccAdvSaveData, tail_slot_0x11334) == 0x11334, "ccAdvSaveData.tail_slot_0x11334");
static_assert(offsetof(ccAdvSaveData, tail_slot_0x11338) == 0x11338, "ccAdvSaveData.tail_slot_0x11338");
static_assert(offsetof(ccAdvSaveData, tail_slot_0x1133C) == 0x1133C, "ccAdvSaveData.tail_slot_0x1133C");
static_assert(offsetof(ccAdvSaveData, tail_slot_0x11340) == 0x11340, "ccAdvSaveData.tail_slot_0x11340");
static_assert(offsetof(ccAdvSaveData, prog_0x11F54) == 0x11F54, "ccAdvSaveData.prog_0x11F54");
static_assert(offsetof(ccAdvSaveData, prog_0x11F58) == 0x11F58, "ccAdvSaveData.prog_0x11F58");
static_assert(offsetof(ccAdvSaveData, prog_0x11F5C) == 0x11F5C, "ccAdvSaveData.prog_0x11F5C");
static_assert(offsetof(ccAdvSaveData, prog_0x11F60) == 0x11F60, "ccAdvSaveData.prog_0x11F60");
static_assert(offsetof(ccAdvSaveData, prog_0x11F64) == 0x11F64, "ccAdvSaveData.prog_0x11F64");
static_assert(offsetof(ccAdvSaveData, prog_0x11F68) == 0x11F68, "ccAdvSaveData.prog_0x11F68");
static_assert(offsetof(ccAdvSaveData, prog_0x11F6C) == 0x11F6C, "ccAdvSaveData.prog_0x11F6C");
static_assert(offsetof(ccAdvSaveData, prog_0x11F70) == 0x11F70, "ccAdvSaveData.prog_0x11F70");
static_assert(offsetof(ccAdvSaveData, prog_0x11F74) == 0x11F74, "ccAdvSaveData.prog_0x11F74");
static_assert(offsetof(ccAdvSaveData, prog_0x11F78) == 0x11F78, "ccAdvSaveData.prog_0x11F78");
static_assert(offsetof(ccAdvSaveData, prog_0x11F7C) == 0x11F7C, "ccAdvSaveData.prog_0x11F7C");
static_assert(offsetof(ccAdvSaveData, prog_0x11F80) == 0x11F80, "ccAdvSaveData.prog_0x11F80");
static_assert(offsetof(ccAdvSaveData, prog_0x11F84) == 0x11F84, "ccAdvSaveData.prog_0x11F84");
static_assert(offsetof(ccAdvSaveData, prog_0x11F88) == 0x11F88, "ccAdvSaveData.prog_0x11F88");
static_assert(offsetof(ccAdvSaveData, prog_0x11F8C) == 0x11F8C, "ccAdvSaveData.prog_0x11F8C");
static_assert(offsetof(ccAdvSaveData, prog_0x11F90) == 0x11F90, "ccAdvSaveData.prog_0x11F90");
static_assert(offsetof(ccAdvSaveData, prog_0x11F94) == 0x11F94, "ccAdvSaveData.prog_0x11F94");
static_assert(offsetof(ccAdvSaveData, prog_0x11F98) == 0x11F98, "ccAdvSaveData.prog_0x11F98");
static_assert(offsetof(ccAdvSaveData, prog_0x11F9C) == 0x11F9C, "ccAdvSaveData.prog_0x11F9C");
static_assert(offsetof(ccAdvSaveData, prog_0x11FA0) == 0x11FA0, "ccAdvSaveData.prog_0x11FA0");
static_assert(offsetof(ccAdvSaveData, prog_0x11FA4) == 0x11FA4, "ccAdvSaveData.prog_0x11FA4");
static_assert(offsetof(ccAdvSaveData, prog_0x11FA8) == 0x11FA8, "ccAdvSaveData.prog_0x11FA8");

#endif /* ST2A11_H */