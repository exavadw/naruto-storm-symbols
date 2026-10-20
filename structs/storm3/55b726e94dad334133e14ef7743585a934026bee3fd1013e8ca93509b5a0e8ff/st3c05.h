/*
 * st3c05.h — Struct group st3c05 for NSUNS3.exe (s3, x64, imagebase 0x140000000)
 *
 * Classes: ccEventStringScaleCtrl, ccEventStringState, ccGroupBattleEventBoot,
 *          ccGroupBattleEventBootCheckerScript, ccGroupBattleEventCtrlScript,
 *          ccGroupBattleEventManager, ccGroupBattleScriptManager,
 *          ccLoDemoEventLoadState, ccLoDemoEventState, ccLoDemoLipSync,
 *          ccLoDemoWaitButton, ccLoDemoWaitStick, ccLoDemoWaitTime,
 *          ccSceneChronologyEventRoot
 *
 * All structs __attribute__((packed)). Sizes are lower bounds proven from
 * ctor/dtor/method field accesses unless noted PROVEN.
 * Rollback tags: SIM = simulation-critical, PRES = presentation-only, UNKNOWN.
 *
 * Generated 2026-10-19 from the decompiler cache decomp cache + state_surface JSONs.
 */

#ifndef ST3C05_H
#define ST3C05_H

#include <stdint.h>
#include <stddef.h>

/* ------------------------------------------------------------------ */
/* ccEventStringScaleCtrl                                             */
/* Small helper: vtable + 2 floats.                                   */
/* Size: unknown, >= 0x18                                             */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccEventStringScaleCtrl {
    void       *vtable;           /* 0x00 */
    float       scale_x;          /* 0x08 */
    float       scale_y;          /* 0x0C */
    uint8_t     _pad_10[0x8];     /* 0x10 */
} ns3_ccEventStringScaleCtrl;
_Static_assert(offsetof(ns3_ccEventStringScaleCtrl, vtable)  == 0x00, "");
_Static_assert(offsetof(ns3_ccEventStringScaleCtrl, scale_x) == 0x08, "");
_Static_assert(offsetof(ns3_ccEventStringScaleCtrl, scale_y) == 0x0C, "");

/* ------------------------------------------------------------------ */
/* ccEventStringState                                                 */
/* Large string-rendering state. Fields from manual decomp of all 11  */
/* methods (state_surface returned 0 due to byte-cast).               */
/* Max proven offset: 0x508 (vector end ptr in SetTblData).           */
/* Size: unknown, >= 0x510                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccEventStringState {
    /* 0x000 */ void       *vtable;
    /* 0x008 */ uint8_t     _gap_008[0x4C];
    /* 0x054 */ int32_t     id;                 /* SetTblData writes puVar3[0x2c] */
    /* 0x058 */ uint8_t     _gap_058[0x8];
    /* 0x060 */ int32_t     active_flag;        /* SetTblData sets =1 */
    /* 0x064 */ uint8_t     _gap_064[0xC];
    /* 0x070 */ uint8_t     font_name[0x38];    /* FUN_14017d4a0(param_1+0x70) */
    /* 0x0A8 */ int32_t     font_hash;          /* *(param_1+0xa8)=uVar2 */
    /* 0x0AC */ uint8_t     _gap_0AC[0x4];
    /* 0x0B0 */ uint8_t     font_chunk_b0[0x18];/* sub-object for font rendering */
    /* 0x0C8 */ void       *font_data_c8;       /* *(param_1+200)=lVar3 → 0xC8 */
    /* 0x0D0 */ uint8_t     _gap_0D0[0x30];
    /* 0x100 */ uint8_t     color_subobj_100[0x10]; /* color sub-object A */
    /* 0x110 */ uint8_t     pos_subobj_110[0x14];   /* SetPosition target A */
    /* 0x124 */ uint8_t     scale_subobj_124[0x18]; /* SetScale target A */
    /* 0x13C */ int32_t     flag_13c;           /* *(param_1+0x13c)=1 */
    /* 0x140 */ uint8_t     _gap_140[0xE4];
    /* 0x224 */ void       *subobj_224;         /* font data duplicate ptr */
    /* 0x22C */ uint8_t     _gap_22C[0x44];
    /* 0x270 */ uint8_t     pos_subobj_270[0x14];   /* SetPosition target B */
    /* 0x284 */ uint8_t     scale_subobj_284[0x8];  /* SetScale target B */
    /* 0x28C */ uint8_t     subobj_28c[0x10];       /* sub-object C */
    /* 0x29C */ int32_t     flag_29c;           /* parallel to 0x13C */
    /* 0x2A0 */ uint8_t     _gap_2A0[0xD0];
    /* 0x370 */ uint8_t     text_buf_370[0x18]; /* std::string text content */
    /* 0x388 */ uint64_t    text_capacity;      /* SSO capacity / heap size */
    /* 0x390 */ uint8_t     _gap_390[0x18];
    /* 0x3A8 */ int32_t     draw_mode;          /* Draw checks ==1 */
    /* 0x3AC */ uint8_t     _gap_3AC[0x2C];
    /* 0x3D8 */ uint8_t     color_subobj_3D8[0x28]; /* Scale passes param_1+0x3d8 */
    /* 0x400 */ uint8_t     color_subobj_400[0x40]; /* Color passes param_1+0x400 */
    /* 0x440 */ float       anim_timer;         /* StateCreate reads/writes */
    /* 0x444 */ float       anim_timer_pad;     /* SetTblData copies puVar3[1] */
    /* 0x448 */ uint8_t     text_str_448[0x18]; /* std::string (begin/end/cap) */
    /* 0x460 */ uint64_t    text_str_cap;       /* SSO threshold check 0xf < */
    /* 0x468 */ uint8_t     _gap_468[0x18];
    /* 0x480 */ uint8_t     shadow_str_480[0x38]; /* second std::string */
    /* 0x4B8 */ uint64_t    field_4b8;
    /* 0x4C0 */ uint64_t    field_4c0;
    /* 0x4C8 */ uint8_t     _gap_4C8[0x8];
    /* 0x4D0 */ uint64_t    field_4d0;
    /* 0x4D8 */ uint64_t    field_4d8;
    /* 0x4E0 */ int32_t     field_4e0;
    /* 0x4E4 */ int32_t     field_4e4;
    /* 0x4E8 */ int32_t     field_4e8;
    /* 0x4EC */ int32_t     field_4ec;
    /* 0x4F0 */ float       anim_limit;         /* StateCreate compares timer < limit */
    /* 0x4F4 */ int32_t     tbl_index;          /* vector subscript index */
    /* 0x4F8 */ void       *tbl_vec_begin;      /* vector begin ptr */
    /* 0x500 */ void       *tbl_vec_end;        /* vector end ptr */
    /* 0x508 */ uint8_t     _gap_508[0x8];      /* pad to 0x510 */
} ns3_ccEventStringState;
_Static_assert(offsetof(ns3_ccEventStringState, vtable)          == 0x000, "");
_Static_assert(offsetof(ns3_ccEventStringState, id)              == 0x054, "");
_Static_assert(offsetof(ns3_ccEventStringState, active_flag)     == 0x060, "");
_Static_assert(offsetof(ns3_ccEventStringState, font_name)       == 0x070, "");
_Static_assert(offsetof(ns3_ccEventStringState, font_hash)       == 0x0A8, "");
_Static_assert(offsetof(ns3_ccEventStringState, font_chunk_b0)   == 0x0B0, "");
_Static_assert(offsetof(ns3_ccEventStringState, font_data_c8)    == 0x0C8, "");
_Static_assert(offsetof(ns3_ccEventStringState, color_subobj_100)== 0x100, "");
_Static_assert(offsetof(ns3_ccEventStringState, pos_subobj_110)  == 0x110, "");
_Static_assert(offsetof(ns3_ccEventStringState, scale_subobj_124)== 0x124, "");
_Static_assert(offsetof(ns3_ccEventStringState, flag_13c)        == 0x13C, "");
_Static_assert(offsetof(ns3_ccEventStringState, subobj_224)      == 0x224, "");
_Static_assert(offsetof(ns3_ccEventStringState, pos_subobj_270)  == 0x270, "");
_Static_assert(offsetof(ns3_ccEventStringState, scale_subobj_284)== 0x284, "");
_Static_assert(offsetof(ns3_ccEventStringState, subobj_28c)      == 0x28C, "");
_Static_assert(offsetof(ns3_ccEventStringState, flag_29c)        == 0x29C, "");
_Static_assert(offsetof(ns3_ccEventStringState, text_buf_370)    == 0x370, "");
_Static_assert(offsetof(ns3_ccEventStringState, text_capacity)   == 0x388, "");
_Static_assert(offsetof(ns3_ccEventStringState, draw_mode)       == 0x3A8, "");
_Static_assert(offsetof(ns3_ccEventStringState, color_subobj_3D8)== 0x3D8, "");
_Static_assert(offsetof(ns3_ccEventStringState, color_subobj_400)== 0x400, "");
_Static_assert(offsetof(ns3_ccEventStringState, anim_timer)      == 0x440, "");
_Static_assert(offsetof(ns3_ccEventStringState, text_str_448)    == 0x448, "");
_Static_assert(offsetof(ns3_ccEventStringState, text_str_cap)    == 0x460, "");
_Static_assert(offsetof(ns3_ccEventStringState, shadow_str_480)  == 0x480, "");
_Static_assert(offsetof(ns3_ccEventStringState, anim_limit)      == 0x4F0, "");
_Static_assert(offsetof(ns3_ccEventStringState, tbl_index)       == 0x4F4, "");
_Static_assert(offsetof(ns3_ccEventStringState, tbl_vec_begin)   == 0x4F8, "");
_Static_assert(offsetof(ns3_ccEventStringState, tbl_vec_end)     == 0x500, "");

/* ------------------------------------------------------------------ */
/* ccGroupBattleEventBoot                                             */
/* Contains std::list at 0x10. Evidence: push_back at 0x39C518,      */
/* iteration at 0x39C5C0.                                             */
/* Size: unknown, >= 0x20 (vtable + 8 + list<24>)                     */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccGroupBattleEventBoot {
    void       *vtable;           /* 0x00 */
    uint8_t     _gap_08[0x8];     /* 0x08 */
    void       *list_sentinel;    /* 0x10 — list head/sentinel */
    uint64_t    list_size;        /* 0x18 — element count */
} ns3_ccGroupBattleEventBoot;
_Static_assert(offsetof(ns3_ccGroupBattleEventBoot, vtable)        == 0x00, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventBoot, list_sentinel) == 0x10, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventBoot, list_size)     == 0x18, "");

/* ------------------------------------------------------------------ */
/* ccGroupBattleEventBootCheckerScript                                */
/* Heap-allocated child at offset 0x8. Evidence: dtor 0x39C74C,      */
/* setter 0x39C7B4, tick 0x39C818.                                    */
/* Size: unknown, >= 0x10 (vtable + ptr)                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccGroupBattleEventBootCheckerScript {
    void       *vtable;           /* 0x00 */
    void       *child_ptr;        /* 0x08 — heap-allocated checker */
} ns3_ccGroupBattleEventBootCheckerScript;
_Static_assert(offsetof(ns3_ccGroupBattleEventBootCheckerScript, vtable)    == 0x00, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventBootCheckerScript, child_ptr) == 0x08, "");

/* ------------------------------------------------------------------ */
/* ccGroupBattleEventCtrlScript                                       */
/* Script controller. Fields from state_surface (4 fields).           */
/* Size: unknown, >= 0xC8 (vtable + fields up to 0xC0 vcall slot)    */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccGroupBattleEventCtrlScript {
    /* 0x00 */ void       *vtable;
    /* 0x08 */ uint8_t     _gap_08[0x4];
    /* 0x0C */ int32_t     mode;               /* Ctrl sets =3 */
    /* 0x10 */ uint8_t     _gap_10[0x44];
    /* 0x54 */ float       timer;              /* rw: accumulated delta */
    /* 0x58 */ uint8_t     _gap_58[0x70];
    /* 0xC8 — end of known fields */
} ns3_ccGroupBattleEventCtrlScript;
_Static_assert(offsetof(ns3_ccGroupBattleEventCtrlScript, vtable) == 0x00, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventCtrlScript, mode)   == 0x0C, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventCtrlScript, timer)  == 0x54, "");

/* ------------------------------------------------------------------ */
/* ccGroupBattleEventManager                                          */
/* Manager with embedded 0x400-byte buffer at 0x8C.                   */
/* memset(param_1+0x8C, 0, 0x400) in ctor → size >= 0x48C            */
/* Size: unknown, >= 0x48C                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccGroupBattleEventManager {
    /* 0x000 */ void       *vtable;
    /* 0x008 */ uint8_t     _gap_008[0x4];
    /* 0x00C */ int32_t     init_flag;          /* ctor sets =1 */
    /* 0x010 */ uint8_t     _gap_010[0x60];
    /* 0x070 */ void       *ptr_070;            /* ctor zeroes */
    /* 0x078 */ void       *ptr_078;            /* ctor zeroes */
    /* 0x080 */ void       *ptr_080;            /* ctor zeroes */
    /* 0x088 */ int32_t     count_088;          /* ctor zeroes */
    /* 0x08C */ uint8_t     event_buffer[0x400];/* memset 0x400 bytes */
    /* 0x48C — end of known fields */
} ns3_ccGroupBattleEventManager;
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, vtable)       == 0x000, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, init_flag)    == 0x00C, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, ptr_070)      == 0x070, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, ptr_078)      == 0x078, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, ptr_080)      == 0x080, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, count_088)    == 0x088, "");
_Static_assert(offsetof(ns3_ccGroupBattleEventManager, event_buffer) == 0x08C, "");

/* ------------------------------------------------------------------ */
/* ccGroupBattleScriptManager                                         */
/* Factory: CreateScript calls FUN_140683f70(0x68,...) → PROVEN 0x68  */
/* Size: PROVEN 0x68                                                  */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccGroupBattleScriptManager {
    /* 0x00 */ void       *vtable;
    /* 0x08 */ uint8_t     _data[0x60];        /* opaque internals */
    /* 0x68 — PROVEN size */
} ns3_ccGroupBattleScriptManager;
_Static_assert(sizeof(ns3_ccGroupBattleScriptManager) == 0x68, "PROVEN from FUN_140683f70(0x68)");

/* ------------------------------------------------------------------ */
/* ccLoDemoEventLoadState                                             */
/* Load state with sub-object ctors at 0x10/0x50/0x90/0xD0/0x100.    */
/* Max proven offset: 0x13C (ctor writes u32=1).                      */
/* Size: unknown, >= 0x140                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccLoDemoEventLoadState {
    /* 0x000 */ void       *vtable;
    /* 0x008 */ uint8_t     _gap_008[0x8];
    /* 0x010 */ uint8_t     subobj_010[0x40];   /* ctor FUN_14069b620(param_1+0x10) */
    /* 0x050 */ uint8_t     subobj_050[0x40];   /* ctor (implicit) */
    /* 0x090 */ uint8_t     subobj_090[0x40];   /* ctor (implicit) */
    /* 0x0D0 */ uint8_t     subobj_0D0[0x30];   /* ctor FUN_14073b140(param_1+0xD0) */
    /* 0x100 */ uint8_t     subobj_100[0x10];   /* ctor FUN_140191324(param_1+0x100) */
    /* 0x110 */ uint64_t    field_110;          /* dtor writes =0 */
    /* 0x118 */ uint64_t    str_or_ptr_118;     /* dtor: SSO check 0xf < */
    /* 0x120 */ uint64_t    field_120;          /* dtor: FUN_140684c60 */
    /* 0x128 */ uint8_t     _gap_128[0x10];
    /* 0x138 */ int32_t     field_138;          /* ctor writes u32=0 */
    /* 0x13C */ int32_t     field_13c;          /* ctor writes u32=1 */
    /* 0x140 — end of known fields */
} ns3_ccLoDemoEventLoadState;
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, vtable)        == 0x000, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, subobj_010)    == 0x010, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, subobj_050)    == 0x050, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, subobj_090)    == 0x090, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, subobj_0D0)    == 0x0D0, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, subobj_100)    == 0x100, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, field_110)     == 0x110, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, str_or_ptr_118)== 0x118, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, field_120)     == 0x120, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, field_138)     == 0x138, "");
_Static_assert(offsetof(ns3_ccLoDemoEventLoadState, field_13c)     == 0x13C, "");

/* ------------------------------------------------------------------ */
/* ccLoDemoEventState                                                 */
/* Large demo state with repeated sub-object pattern every 0x30 bytes */
/* from 0x140 onward (vtable ptrs set to PTR_FUN_1409ec308).          */
/* Max proven offset: 0x338 (vtable write).                           */
/* Size: unknown, >= 0x340                                            */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccLoDemoEventState {
    /* 0x000 */ void       *vtable;
    /* 0x008 */ uint8_t     _gap_008[0x70];
    /* 0x078 */ uint8_t     flag_078;           /* rw byte */
    /* 0x079 */ uint8_t     _gap_079[0xF];
    /* 0x088 */ uint64_t    field_088;          /* dtor writes =0 */
    /* 0x090 */ uint64_t    str_or_ptr_090;     /* dtor: SSO check 0xf < */
    /* 0x098 */ uint64_t    field_098;          /* dtor: FUN_140684c60 */
    /* 0x0A0 */ uint8_t     _gap_0A0[0x40];
    /* 0x0E0 */ uint8_t     flag_0E0;           /* rw byte */
    /* 0x0E1 */ uint8_t     _gap_0E1[0xF];
    /* 0x0F0 */ uint64_t    field_0F0;          /* dtor writes =0 */
    /* 0x0F8 */ uint64_t    str_or_ptr_0F8;     /* dtor: SSO check 0xf < */
    /* 0x100 */ uint64_t    field_100;          /* dtor: FUN_140684c60 */
    /* 0x108 */ uint8_t     _gap_108[0x20];
    /* 0x128 */ uint8_t     _subobj_128[0x18];  /* dtor: FUN_14020e3a0 */
    /* 0x140 */ void       *vtable_sub_140;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x148 */ uint8_t     _gap_148[0x10];
    /* 0x158 */ uint8_t     _subobj_158[0x18];  /* dtor: FUN_14020e3a0 */
    /* 0x170 */ void       *vtable_sub_170;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x178 */ uint8_t     _gap_178[0x10];
    /* 0x188 */ uint8_t     _subobj_188[0x18];  /* dtor: FUN_14020e3a0 */
    /* 0x1A0 */ void       *vtable_sub_1A0;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x1A8 */ uint8_t     _gap_1A8[0x10];
    /* 0x1B8 */ uint8_t     _subobj_1B8[0x18];  /* dtor: FUN_14020e3a0 */
    /* 0x1D0 */ void       *vtable_sub_1D0;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x1D8 */ uint8_t     _gap_1D8[0x10];
    /* 0x1E8 */ uint8_t     _subobj_1E8[0x18];  /* dtor: FUN_14020e3a0 */
    /* 0x200 */ void       *vtable_sub_200;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x208 */ uint8_t     _gap_208[0x10];
    /* 0x218 */ uint8_t     _subobj_218[0x18];  /* dtor: FUN_14020e3a0 */
    /* 0x230 */ void       *vtable_sub_230;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x238 */ uint8_t     _gap_238[0xB0];
    /* 0x2E8 */ uint8_t     _subobj_2E8[0x18];  /* dtor: FUN_1404c1588 */
    /* 0x300 */ void       *vtable_sub_300;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x308 */ uint8_t     _gap_308[0x30];
    /* 0x338 */ void       *vtable_sub_338;     /* dtor sets = PTR_FUN_1409ec308 */
    /* 0x340 — end of known fields */
} ns3_ccLoDemoEventState;
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable)          == 0x000, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, flag_078)        == 0x078, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, field_088)       == 0x088, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, str_or_ptr_090)  == 0x090, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, field_098)       == 0x098, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, flag_0E0)        == 0x0E0, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, field_0F0)       == 0x0F0, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, str_or_ptr_0F8)  == 0x0F8, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, field_100)       == 0x100, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_140)  == 0x140, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_170)  == 0x170, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_1A0)  == 0x1A0, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_1D0)  == 0x1D0, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_200)  == 0x200, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_230)  == 0x230, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_300)  == 0x300, "");
_Static_assert(offsetof(ns3_ccLoDemoEventState, vtable_sub_338)  == 0x338, "");

/* ------------------------------------------------------------------ */
/* ccLoDemoLipSync                                                    */
/* Lip-sync data holder. state_surface returned 0 fields.             */
/* Size: unknown, >= 0x8 (vtable only proven)                         */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccLoDemoLipSync {
    void       *vtable;           /* 0x00 */
} ns3_ccLoDemoLipSync;
_Static_assert(offsetof(ns3_ccLoDemoLipSync, vtable) == 0x00, "");

/* ------------------------------------------------------------------ */
/* ccLoDemoWaitButton                                                 */
/* Button-wait command. No state_surface JSON available.              */
/* Minimal layout from class hierarchy (inherits ccLoDemoWaitBase).   */
/* Size: unknown, >= 0x8                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccLoDemoWaitButton {
    void       *vtable;           /* 0x00 */
} ns3_ccLoDemoWaitButton;
_Static_assert(offsetof(ns3_ccLoDemoWaitButton, vtable) == 0x00, "");

/* ------------------------------------------------------------------ */
/* ccLoDemoWaitStick                                                  */
/* Stick-wait command. No state_surface JSON available.               */
/* Size: unknown, >= 0x8                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccLoDemoWaitStick {
    void       *vtable;           /* 0x00 */
} ns3_ccLoDemoWaitStick;
_Static_assert(offsetof(ns3_ccLoDemoWaitStick, vtable) == 0x00, "");

/* ------------------------------------------------------------------ */
/* ccLoDemoWaitTime                                                   */
/* Time-wait command. No state_surface JSON available.                */
/* Size: unknown, >= 0x8                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccLoDemoWaitTime {
    void       *vtable;           /* 0x00 */
} ns3_ccLoDemoWaitTime;
_Static_assert(offsetof(ns3_ccLoDemoWaitTime, vtable) == 0x00, "");

/* ------------------------------------------------------------------ */
/* ccSceneChronologyEventRoot                                         */
/* Chronology event root. state_surface returned 0 typed fields       */
/* (byte-cast warnings only).                                         */
/* Size: unknown, >= 0x8                                              */
/* ------------------------------------------------------------------ */
typedef struct __attribute__((packed)) ns3_ccSceneChronologyEventRoot {
    void       *vtable;           /* 0x00 */
} ns3_ccSceneChronologyEventRoot;
_Static_assert(offsetof(ns3_ccSceneChronologyEventRoot, vtable) == 0x00, "");

#endif /* ST3C05_H */