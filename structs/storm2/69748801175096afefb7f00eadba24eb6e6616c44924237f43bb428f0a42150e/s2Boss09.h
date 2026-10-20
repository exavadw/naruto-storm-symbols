/* s2Boss09 — Storm 2 (NSUNS2.exe) Pein rocks/finale boss-battle structs
 * Build: s2  sha256: 697488011750...
 * All layouts INFERRED from static analysis (state_surface + decompile).
 * Sizes come from ccFileLoadListForUi::LoadTh first arg or dtor vtable writes.
 */
#ifndef S2_BOSS09_H
#define S2_BOSS09_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* C11 compatibility: static_assert is C++ / C23; use _Static_assert for C11 */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/* Forward declarations for base classes not reconstructed here */
typedef struct GameActor_TestActor GameActor_TestActor;

/* ================================================================
 * ccBoss09RockManager — manages Rock actor list for Boss09
 * Size: 0xB8 (184) from LoadTh(0xb8) in ccSceneBoss09::Initialize
 * Base: contains embedded AabbCalculationCallback at +0x10
 * ================================================================ */
typedef struct ccBoss09RockManager {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t pad_08[0x08];           /* to AabbCalculationCallback */
    /* 0x10 */ uint8_t aabb_callback[0x68];    /* _btStridingMeshInterface::AabbCalculationCallback embedded */
    /* 0x78 */ void *unk_0x78;                  /* r, low — FUN_1402e8c90 reads this */
    /* 0x80 */ uint8_t pad_80[0x20];
    /* 0xA0 */ int32_t rock_count;              /* w, med — ctor: *(undefined4*)(param_1+0x14)=0; CreateRock increments */
    /* 0xA4 */ uint8_t pad_A4[0x04];
    /* 0xA8 */ int64_t unk_0xA8;                /* w, med — ctor: param_1[0x15]=0 */
    /* 0xB0 */ int32_t unk_0xB0;                /* w, med — ctor: *(undefined4*)(param_1+0x16)=0 */
    /* 0xB4 */ uint8_t pad_B4[0x04];
} ccBoss09RockManager;

static_assert(offsetof(ccBoss09RockManager, vtable) == 0x00, "ccBoss09RockManager.vtable");
static_assert(offsetof(ccBoss09RockManager, aabb_callback) == 0x10, "ccBoss09RockManager.aabb_callback");
static_assert(offsetof(ccBoss09RockManager, unk_0x78) == 0x78, "ccBoss09RockManager.unk_0x78");
static_assert(offsetof(ccBoss09RockManager, rock_count) == 0xA0, "ccBoss09RockManager.rock_count");
static_assert(offsetof(ccBoss09RockManager, unk_0xA8) == 0xA8, "ccBoss09RockManager.unk_0xA8");
static_assert(offsetof(ccBoss09RockManager, unk_0xB0) == 0xB0, "ccBoss09RockManager.unk_0xB0");
static_assert(sizeof(ccBoss09RockManager) == 0xB8, "ccBoss09RockManager size");

/* ================================================================
 * ccBoss09RockS — Small rock actor (param_2==1 in CreateRock)
 * Size: 0x1650 (5712) from LoadTh(0x1650) in factory FUN_1402e8b90
 * Base: GameActor::TestActor
 * ================================================================ */
typedef struct ccBoss09RockS {
    /* 0x0000 */ uint8_t base[0x9C];            /* GameActor::TestActor base (inferred) */
    /* 0x009C */ uint32_t unk_0x9C;             /* w — Init sets 0x40000000 or 0x3f800000 */
    /* 0x00A0 */ uint8_t pad_A0[0x04];
    /* 0x00A4 */ float speed_y;                 /* rw, high — set in FUN_1402e9f8c with FPS scaling */
    /* 0x00A8 */ uint8_t pad_A8[0x08];
    /* 0x00B0 */ int64_t unk_0xB0;              /* w */
    /* 0x00B8 */ uint8_t pad_B8[0x08];
    /* 0x00C0 */ uint8_t pad_C0[0x04];
    /* 0x00C4 */ float height_limit;            /* w — clamped to 600.0 max */
    /* 0x00C8 */ uint8_t pad_C8[0x24];
    /* 0x00EC */ uint32_t flags;                /* r — bit 0 checked in Init */
    /* 0x00F0 */ uint8_t pad_F0[0x18];
    /* 0x0108 */ uint8_t pad_108[0x13C0];       /* gap to 0x14C8 */
    /* 0x14C8 */ void *dtor_vtable_1;            /* w — dtor writes vtable */
    /* 0x14D0 */ uint8_t pad_14D0[0x120];
    /* 0x15F0 */ int64_t unk_0x15F0;            /* w, high */
    /* 0x15F8 */ uint8_t pad_15F8[0x58];        /* to end of allocated size */
} ccBoss09RockS;

static_assert(offsetof(ccBoss09RockS, unk_0x9C) == 0x009C, "ccBoss09RockS.unk_0x9C");
static_assert(offsetof(ccBoss09RockS, speed_y) == 0x00A4, "ccBoss09RockS.speed_y");
static_assert(offsetof(ccBoss09RockS, unk_0xB0) == 0x00B0, "ccBoss09RockS.unk_0xB0");
static_assert(offsetof(ccBoss09RockS, height_limit) == 0x00C4, "ccBoss09RockS.height_limit");
static_assert(offsetof(ccBoss09RockS, flags) == 0x00EC, "ccBoss09RockS.flags");
static_assert(offsetof(ccBoss09RockS, dtor_vtable_1) == 0x14C8, "ccBoss09RockS.dtor_vtable_1");
static_assert(offsetof(ccBoss09RockS, unk_0x15F0) == 0x15F0, "ccBoss09RockS.unk_0x15F0");
static_assert(sizeof(ccBoss09RockS) == 0x1650, "ccBoss09RockS size");

/* ================================================================
 * ccBoss09RockM — Medium rock actor (param_2==2 in CreateRock)
 * Size: 0x1618 (5656) from LoadTh(0x1618) in factory FUN_1402e8b2c
 * Base: GameActor::TestActor
 * ================================================================ */
typedef struct ccBoss09RockM {
    /* 0x0000 */ uint8_t base[0x9C];            /* GameActor::TestActor base */
    /* 0x009C */ float unk_0x9C;                /* w */
    /* 0x00A0 */ uint32_t unk_0xA0;             /* w — 4 or 8 byte access */
    /* 0x00A4 */ float unk_0xA4;                /* rw */
    /* 0x00A8 */ uint32_t unk_0xA8;             /* w */
    /* 0x00AC */ uint8_t pad_AC[0x04];
    /* 0x00B0 */ int64_t unk_0xB0;              /* w */
    /* 0x00B8 */ uint32_t unk_0xB8;             /* w */
    /* 0x00BC */ float unk_0xBC;                /* rw */
    /* 0x00C0 */ uint32_t unk_0xC0;             /* w */
    /* 0x00C4 */ uint32_t unk_0xC4;             /* rw, high */
    /* 0x00C8 */ uint32_t unk_0xC8;             /* rw */
    /* 0x00CC */ uint32_t unk_0xCC;             /* rw */
    /* 0x00D0 */ uint32_t unk_0xD0;             /* w */
    /* 0x00D4 */ uint8_t pad_D4[0x0C];          /* r low FUN ref */
    /* 0x00E0 */ uint32_t unk_0xE0;             /* w */
    /* 0x00E4 */ uint8_t pad_E4[0x08];
    /* 0x00EC */ uint8_t unk_0xEC;              /* r — single byte read */
    /* 0x00ED */ uint8_t pad_ED[0x23];
    /* 0x0110 */ int64_t unk_0x110;             /* rw */
    /* 0x0118 */ uint8_t pad_118[0x328];
    /* 0x0440 */ uint8_t pad_440[0x11B0];       /* vcall at +0x440 is base class dispatch */
    /* 0x15F0 */ int64_t unk_0x15F0;            /* w */
    /* 0x15F8 */ uint32_t unk_0x15F8;           /* w */
    /* 0x15FC */ uint8_t pad_15FC[0x1C];        /* to end */
} ccBoss09RockM;

static_assert(offsetof(ccBoss09RockM, unk_0x9C) == 0x009C, "ccBoss09RockM.unk_0x9C");
static_assert(offsetof(ccBoss09RockM, unk_0xA0) == 0x00A0, "ccBoss09RockM.unk_0xA0");
static_assert(offsetof(ccBoss09RockM, unk_0xA4) == 0x00A4, "ccBoss09RockM.unk_0xA4");
static_assert(offsetof(ccBoss09RockM, unk_0xA8) == 0x00A8, "ccBoss09RockM.unk_0xA8");
static_assert(offsetof(ccBoss09RockM, unk_0xB0) == 0x00B0, "ccBoss09RockM.unk_0xB0");
static_assert(offsetof(ccBoss09RockM, unk_0xB8) == 0x00B8, "ccBoss09RockM.unk_0xB8");
static_assert(offsetof(ccBoss09RockM, unk_0xBC) == 0x00BC, "ccBoss09RockM.unk_0xBC");
static_assert(offsetof(ccBoss09RockM, unk_0xC0) == 0x00C0, "ccBoss09RockM.unk_0xC0");
static_assert(offsetof(ccBoss09RockM, unk_0xC4) == 0x00C4, "ccBoss09RockM.unk_0xC4");
static_assert(offsetof(ccBoss09RockM, unk_0xC8) == 0x00C8, "ccBoss09RockM.unk_0xC8");
static_assert(offsetof(ccBoss09RockM, unk_0xCC) == 0x00CC, "ccBoss09RockM.unk_0xCC");
static_assert(offsetof(ccBoss09RockM, unk_0xD0) == 0x00D0, "ccBoss09RockM.unk_0xD0");
static_assert(offsetof(ccBoss09RockM, unk_0xE0) == 0x00E0, "ccBoss09RockM.unk_0xE0");
static_assert(offsetof(ccBoss09RockM, unk_0xEC) == 0x00EC, "ccBoss09RockM.unk_0xEC");
static_assert(offsetof(ccBoss09RockM, unk_0x110) == 0x0110, "ccBoss09RockM.unk_0x110");
static_assert(offsetof(ccBoss09RockM, unk_0x15F0) == 0x15F0, "ccBoss09RockM.unk_0x15F0");
static_assert(offsetof(ccBoss09RockM, unk_0x15F8) == 0x15F8, "ccBoss09RockM.unk_0x15F8");
static_assert(sizeof(ccBoss09RockM) == 0x1618, "ccBoss09RockM size");

/* ================================================================
 * ccBoss09RockL — Large rock actor (param_2!=1&&!=2 in CreateRock)
 * Size: 0x1628 (5672) from LoadTh(0x1628) in factory FUN_1402e8bf4
 * Base: GameActor::TestActor
 * ================================================================ */
typedef struct ccBoss09RockL {
    /* 0x0000 */ uint8_t base[0x9C];            /* GameActor::TestActor base */
    /* 0x009C */ uint32_t unk_0x9C;             /* w */
    /* 0x00A0 */ uint32_t unk_0xA0;             /* w */
    /* 0x00A4 */ uint32_t unk_0xA4;             /* w, high */
    /* 0x00A8 */ uint8_t pad_A8[0x14];
    /* 0x00BC */ uint8_t pad_BC[0x04];          /* r low */
    /* 0x00C0 */ uint32_t unk_0xC0;             /* w */
    /* 0x00C4 */ uint32_t unk_0xC4;             /* w, high */
    /* 0x00C8 */ uint8_t pad_C8[0x48];
    /* 0x0110 */ int64_t unk_0x110;             /* rw */
    /* 0x0118 */ uint8_t pad_118[0x14D8];       /* to 0x15F0 */
    /* 0x15F0 */ int64_t unk_0x15F0;            /* w, high */
    /* 0x15F8 */ uint8_t pad_15F8[0x30];        /* to end */
} ccBoss09RockL;

static_assert(offsetof(ccBoss09RockL, unk_0x9C) == 0x009C, "ccBoss09RockL.unk_0x9C");
static_assert(offsetof(ccBoss09RockL, unk_0xA0) == 0x00A0, "ccBoss09RockL.unk_0xA0");
static_assert(offsetof(ccBoss09RockL, unk_0xA4) == 0x00A4, "ccBoss09RockL.unk_0xA4");
static_assert(offsetof(ccBoss09RockL, unk_0xC0) == 0x00C0, "ccBoss09RockL.unk_0xC0");
static_assert(offsetof(ccBoss09RockL, unk_0xC4) == 0x00C4, "ccBoss09RockL.unk_0xC4");
static_assert(offsetof(ccBoss09RockL, unk_0x110) == 0x0110, "ccBoss09RockL.unk_0x110");
static_assert(offsetof(ccBoss09RockL, unk_0x15F0) == 0x15F0, "ccBoss09RockL.unk_0x15F0");
static_assert(sizeof(ccBoss09RockL) == 0x1628, "ccBoss09RockL size");

/* ================================================================
 * ccBoss09RockCmn — Common rock base (dtor only, no separate allocation found)
 * Size unknown, >= 0x7220 (last vtable write at 0x7218 + 8)
 * Base: GameActor::TestActor
 * Note: likely an abstract base; concrete RockS/M/L inherit from it.
 * ================================================================ */
typedef struct ccBoss09RockCmn {
    /* 0x0000 */ uint8_t base[0x70D8];          /* GameActor::TestActor + members */
    /* 0x70D8 */ void *vtable_slot_1;           /* w — dtor writes PTR_FUN_1408918e8 */
    /* 0x70E0 */ uint8_t pad_70E0[0x98];
    /* 0x7178 */ void *vtable_slot_2;           /* w — dtor writes PTR_FUN_1408918e8 */
    /* 0x7180 */ uint8_t pad_7180[0x98];
    /* 0x7218 */ void *vtable_slot_3;           /* w — dtor writes PTR_FUN_1408918e8 */
    /* 0x7220 */ uint8_t pad_7220[];            /* size unknown beyond this point */
} ccBoss09RockCmn;

static_assert(offsetof(ccBoss09RockCmn, vtable_slot_1) == 0x70D8, "ccBoss09RockCmn.vtable_slot_1");
static_assert(offsetof(ccBoss09RockCmn, vtable_slot_2) == 0x7178, "ccBoss09RockCmn.vtable_slot_2");
static_assert(offsetof(ccBoss09RockCmn, vtable_slot_3) == 0x7218, "ccBoss09RockCmn.vtable_slot_3");
/* No sizeof assert: true size not found from allocator */

/* ================================================================
 * ccBoss09PeinActionState — Pein AI action state machine
 * Size unknown, >= 0x2D9C (last field at 0x2D98 + 4)
 * ================================================================ */
typedef struct ccBoss09PeinActionState {
    /* 0x0000 */ uint8_t base[0x14B8];          /* base class */
    /* 0x14B8 */ uint8_t pad_14B8[0x3D0];       /* r low FUN ref at 0x14B8 */
    /* 0x1888 */ int64_t slot_0;                /* w — array slot 0 */
    /* 0x1890 */ int64_t slot_1;                /* w — array slot 1 */
    /* 0x1898 */ int64_t slot_2;                /* w — array slot 2 */
    /* 0x18A0 */ int64_t slot_3;                /* w — array slot 3 */
    /* 0x18A8 */ int64_t slot_4;                /* w — array slot 4 */
    /* 0x18B0 */ int64_t slot_5;                /* w — array slot 5 */
    /* 0x18B8 */ int64_t slot_6;                /* w — array slot 6 */
    /* 0x18C0 */ int64_t slot_7;                /* w — array slot 7 */
    /* 0x18C8 */ uint32_t unk_0x18C8;           /* w */
    /* 0x18CC */ uint8_t pad_18CC[0x14CC];      /* to 0x2D98 */
    /* 0x2D98 */ uint8_t pad_2D98[0x04];        /* r low FUN param_1+0x5b3 */
} ccBoss09PeinActionState;

static_assert(offsetof(ccBoss09PeinActionState, slot_0) == 0x1888, "ccBoss09PeinActionState.slot_0");
static_assert(offsetof(ccBoss09PeinActionState, slot_1) == 0x1890, "ccBoss09PeinActionState.slot_1");
static_assert(offsetof(ccBoss09PeinActionState, slot_2) == 0x1898, "ccBoss09PeinActionState.slot_2");
static_assert(offsetof(ccBoss09PeinActionState, slot_3) == 0x18A0, "ccBoss09PeinActionState.slot_3");
static_assert(offsetof(ccBoss09PeinActionState, slot_4) == 0x18A8, "ccBoss09PeinActionState.slot_4");
static_assert(offsetof(ccBoss09PeinActionState, slot_5) == 0x18B0, "ccBoss09PeinActionState.slot_5");
static_assert(offsetof(ccBoss09PeinActionState, slot_6) == 0x18B8, "ccBoss09PeinActionState.slot_6");
static_assert(offsetof(ccBoss09PeinActionState, slot_7) == 0x18C0, "ccBoss09PeinActionState.slot_7");
static_assert(offsetof(ccBoss09PeinActionState, unk_0x18C8) == 0x18C8, "ccBoss09PeinActionState.unk_0x18C8");
/* No sizeof assert: true size not found */

/* ================================================================
 * ccBoss09PeinRockAtkActionState — Pein rock attack sub-state
 * Size unknown; state_surface returned 0 fields
 * ================================================================ */
typedef struct ccBoss09PeinRockAtkActionState {
    uint8_t _opaque[1]; /* no fields recovered */
} ccBoss09PeinRockAtkActionState;

/* ================================================================
 * ccBoss09RokuBeam — Roku (Six Paths) beam projectile
 * Size unknown, >= 0xDC (last field at 0xD8 + 4)
 * ================================================================ */
typedef struct ccBoss09RokuBeam {
    /* 0x00 */ uint8_t base[0xC0];              /* base class */
    /* 0xC0 */ uint8_t pad_C0[0x0C];            /* r low — FUN_140580a40(param_1+0x18) in ctor */
    /* 0xCC */ uint8_t pad_CC[0x0C];            /* r low — FUN_140580a40((longlong)param_1+0xcc) in ctor */
    /* 0xD8 */ uint8_t pad_D8[0x04];            /* r low — FUN_140580a40(param_1+0x1b) in ctor */
} ccBoss09RokuBeam;

static_assert(offsetof(ccBoss09RokuBeam, pad_C0) == 0xC0, "ccBoss09RokuBeam.pad_C0");
static_assert(offsetof(ccBoss09RokuBeam, pad_CC) == 0xCC, "ccBoss09RokuBeam.pad_CC");
static_assert(offsetof(ccBoss09RokuBeam, pad_D8) == 0xD8, "ccBoss09RokuBeam.pad_D8");
/* No sizeof assert: true size not found */

/* ================================================================
 * ccBoss09CamOpeType04 — Camera operation type 04 for Boss09
 * Size unknown, >= 0x348 (last field at 0x340 + 8)
 * ================================================================ */
typedef struct ccBoss09CamOpeType04 {
    /* 0x000 */ uint8_t base[0xB0];             /* base class */
    /* 0x0B0 */ uint8_t unk_0xB0[0x0C];         /* r low — passed to FUN_140580ac0 */
    /* 0x0BC */ uint8_t unk_0xBC[0x04];         /* r low — passed to FUN_140580ac0 */
    /* 0x0C0 */ uint8_t pad_0C0[0xF0];
    /* 0x1B0 */ float unk_0x1B0;                /* rw, high — FPS-scaled timer */
    /* 0x1B4 */ uint8_t pad_1B4[0x08];
    /* 0x1BC */ int32_t unk_0x1BC;              /* rw, high — set in Ctrl and ctor */
    /* 0x1C0 */ uint8_t unk_0x1C0[0x04];        /* part of 0x1C4 region; see below */
    /* 0x1C4 */ uint8_t unk_0x1C4[0x08];        /* rw, low — FUN_140580a40 init (unaligned int64 via byte ptr) */
    /* 0x1CC */ uint8_t unk_0x1CC[0x04];        /* w, med — copied from param (unaligned uint32) */
    /* 0x1D0 */ uint8_t unk_0x1D0[0x08];        /* rw, low — FUN_140580a40 init (unaligned int64) */
    /* 0x1D8 */ uint8_t unk_0x1D8[0x04];        /* w, med (unaligned uint32) */
    /* 0x1DC */ uint8_t pad_1DC[0x04];
    /* 0x1E0 */ uint8_t unk_0x1E0[0x04];        /* r — byte/bitfield access (+0x20 & 0x40) */
    /* 0x1E4 */ uint8_t pad_1E4[0x08];
    /* 0x1EC */ uint8_t unk_0x1EC[0x04];        /* r low — FUN_140580a40 init */
    /* 0x1F0 */ uint8_t pad_1F0[0x150];
    /* 0x340 */ uint8_t unk_0x340[0x08];        /* r low — vcall *param_1+0x68 */
} ccBoss09CamOpeType04;

static_assert(offsetof(ccBoss09CamOpeType04, unk_0xB0) == 0x0B0, "ccBoss09CamOpeType04.unk_0xB0");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0xBC) == 0x0BC, "ccBoss09CamOpeType04.unk_0xBC");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1B0) == 0x1B0, "ccBoss09CamOpeType04.unk_0x1B0");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1BC) == 0x1BC, "ccBoss09CamOpeType04.unk_0x1BC");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1C4) == 0x1C4, "ccBoss09CamOpeType04.unk_0x1C4");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1CC) == 0x1CC, "ccBoss09CamOpeType04.unk_0x1CC");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1D0) == 0x1D0, "ccBoss09CamOpeType04.unk_0x1D0");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1D8) == 0x1D8, "ccBoss09CamOpeType04.unk_0x1D8");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1E0) == 0x1E0, "ccBoss09CamOpeType04.unk_0x1E0");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x1EC) == 0x1EC, "ccBoss09CamOpeType04.unk_0x1EC");
static_assert(offsetof(ccBoss09CamOpeType04, unk_0x340) == 0x340, "ccBoss09CamOpeType04.unk_0x340");
/* No sizeof assert: true size not found */

/* ================================================================
 * ccSceneBoss09 — Boss09 scene controller
 * Size unknown, >= 0x170 (last known field at 0x168 + 8)
 * ================================================================ */
typedef struct ccSceneBoss09 {
    /* 0x000 */ uint8_t base[0x50];             /* base scene class */
    /* 0x050 */ uint8_t property_base[0xD8];    /* property block */
    /* 0x128 */ int64_t cam_step;               /* rw — camera step index */
    /* 0x130 */ int64_t unk_0x130;              /* rw */
    /* 0x138 */ void *ui_mgr;                   /* ptr — ccSceneBossBattleUiManager*, LoadTh(0x108) */
    /* 0x140 */ ccBoss09RockManager *rock_mgr;  /* ptr — LoadTh(0xb8) */
    /* 0x148 */ void *limit_life;               /* ptr — LimitationLife-related, LoadTh(0x18) */
    /* 0x150 */ void *skill_loader;             /* ptr — ccSkillLoader, LoadTh(0x10) */
    /* 0x158 */ uint8_t pad_158[0x10];
    /* 0x168 */ void *task_entry;               /* ptr */
} ccSceneBoss09;

static_assert(offsetof(ccSceneBoss09, cam_step) == 0x128, "ccSceneBoss09.cam_step");
static_assert(offsetof(ccSceneBoss09, unk_0x130) == 0x130, "ccSceneBoss09.unk_0x130");
static_assert(offsetof(ccSceneBoss09, ui_mgr) == 0x138, "ccSceneBoss09.ui_mgr");
static_assert(offsetof(ccSceneBoss09, rock_mgr) == 0x140, "ccSceneBoss09.rock_mgr");
static_assert(offsetof(ccSceneBoss09, limit_life) == 0x148, "ccSceneBoss09.limit_life");
static_assert(offsetof(ccSceneBoss09, skill_loader) == 0x150, "ccSceneBoss09.skill_loader");
static_assert(offsetof(ccSceneBoss09, task_entry) == 0x168, "ccSceneBoss09.task_entry");
/* No sizeof assert: true size not found */

/* ================================================================
 * ccSceneBoss09Phase01 — Phase 01 sub-scene
 * Size unknown, >= 0x138
 * ================================================================ */
typedef struct ccSceneBoss09Phase01 {
    /* 0x000 */ uint8_t base[0x128];
    /* 0x128 */ int64_t unk_0x128;              /* rw */
    /* 0x130 */ int64_t unk_0x130;              /* rw */
} ccSceneBoss09Phase01;

static_assert(offsetof(ccSceneBoss09Phase01, unk_0x128) == 0x128, "ccSceneBoss09Phase01.unk_0x128");
static_assert(offsetof(ccSceneBoss09Phase01, unk_0x130) == 0x130, "ccSceneBoss09Phase01.unk_0x130");
/* No sizeof assert */

/* ================================================================
 * Minimal stubs for classes with < 3 methods or 0 state_surface fields
 * Listed for completeness; no layout data recovered.
 * ================================================================ */

/* --- Scene phases (ctors/factories only, no field data) --- */
typedef struct ccSceneBoss09Phase00 { uint8_t _opaque[1]; } ccSceneBoss09Phase00;
typedef struct ccSceneBoss09Phase02 { uint8_t _opaque[1]; } ccSceneBoss09Phase02;
typedef struct ccSceneBoss09Phase03 { uint8_t _opaque[1]; } ccSceneBoss09Phase03;
typedef struct ccSceneBoss09Phase04 { uint8_t _opaque[1]; } ccSceneBoss09Phase04;
typedef struct ccSceneBoss09Phase05 { uint8_t _opaque[1]; } ccSceneBoss09Phase05;
typedef struct ccSceneBoss09Phase05LoDemo { uint8_t _opaque[1]; } ccSceneBoss09Phase05LoDemo;
typedef struct ccSceneBoss09Phase06 { uint8_t _opaque[1]; } ccSceneBoss09Phase06;
typedef struct ccSceneBoss09Phase07 { uint8_t _opaque[1]; } ccSceneBoss09Phase07;
typedef struct ccSceneBoss09Phase0701 { uint8_t _opaque[1]; } ccSceneBoss09Phase0701;
typedef struct ccSceneBoss09Phase0702 { uint8_t _opaque[1]; } ccSceneBoss09Phase0702;
typedef struct ccSceneBoss09Phase08 { uint8_t _opaque[1]; } ccSceneBoss09Phase08;

/* --- Scene change states --- */
typedef struct ccSceneBoss0901SceneChangeState { uint8_t _opaque[1]; } ccSceneBoss0901SceneChangeState;
typedef struct ccSceneBoss0904SceneChangeState { uint8_t _opaque[1]; } ccSceneBoss0904SceneChangeState;
typedef struct ccSceneBoss0907SceneChangeState { uint8_t _opaque[1]; } ccSceneBoss0907SceneChangeState;

/* --- Camera operation types (ctors only, no field data) --- */
typedef struct ccBoss09CamOpeType00 { uint8_t _opaque[1]; } ccBoss09CamOpeType00;
typedef struct ccBoss09CamOpeType01 { uint8_t _opaque[1]; } ccBoss09CamOpeType01;
typedef struct ccBoss09CamOpeType03 { uint8_t _opaque[1]; } ccBoss09CamOpeType03;
typedef struct ccBoss09CamOpeType05 { uint8_t _opaque[1]; } ccBoss09CamOpeType05;
typedef struct ccBoss09CamOpeType06 { uint8_t _opaque[1]; } ccBoss09CamOpeType06;
typedef struct ccBoss09CamOpeType0701 { uint8_t _opaque[1]; } ccBoss09CamOpeType0701;

/* --- Camera judges (methods exist but < 3 per class, no field data) --- */
typedef struct ccBoss09CameraJudge { uint8_t _opaque[1]; } ccBoss09CameraJudge;
typedef struct ccBoss09CameraJudge01 { uint8_t _opaque[1]; } ccBoss09CameraJudge01;
typedef struct ccBoss09CameraJudge07 { uint8_t _opaque[1]; } ccBoss09CameraJudge07;

/* --- Bullet time manager (2 methods only) --- */
typedef struct ccBoss09BulletTimeManager { uint8_t _opaque[1]; } ccBoss09BulletTimeManager;

/* --- Pein nut action state (1 method only) --- */
typedef struct ccBoss09PeinNutActionState { uint8_t _opaque[1]; } ccBoss09PeinNutActionState;

#endif /* S2_BOSS09_H */