/* s2BossFramework.h — Storm 2 (NSUNS2.exe) boss-battle framework structs
 * Build: s2 / NSUNS2.exe-abf2b6 / sha256 697488011750...
 * All layouts INFERRED from static analysis (state_surface + ctor decompiles).
 * NOT CONFIRMED at runtime. Field names are best-effort from method context.
 *
 * Classes covered (full layout from initial pass):
 * ccSceneBossBattleUiManager (22 fields, size >= 0x108)
 * ccBossBattleCommandObject (13 fields, size >= 0x4DC)
 * ccSceneBossBattleIA (18 fields, size >= 0x508)
 * ccUiDuelBossGauge (6 fields, size >= 0x9B8)
 * ccBossTargetCursor (6 fields, embedded in ccBoss04Sight at +0xD0)
 * ccBossStage (3 fields, inherits ccBossBattleObjectBase)
 * ccBossBattleIaLoader (1 field + 8 ccBaseCoord array)
 *
 * Classes with partial layouts (extended decompilation pass):
 * ccBossBattleCaptionManager (size 0x18 exact, singleton)
 * ccBossBattleUi (>= 0x40, sub-object allocations)
 * ccSceneBossBattleLoading (>= 0x138, ccScene base + state/sub-obj)
 * ccSceneBossBattleRetryMenu (>= 0x140, ccUiSelectWindow at +0x138)
 * ccSceneBossBattleRoot (>= 0x130, boss dispatch by name)
 * ccScenePlayBossBattle (>= 0x138, state machine + sub-obj)
 * ccSceneBossBattleResult (>= 0x150, ccUiDuelReward at +0x148)
 * ccUiCollectionModeBossBattle (>= 0x138, list iteration)
 *
 * Classes listed only (insufficient data for struct layout):
 * ccBossBattleObjectManager (49 methods, template factory — no this-fields)
 * ccBossBattleState (9 methods, 0 fields)
 * ccBossBattleManager (9 methods, singleton ms_instance)
 * ccSceneBossFreeBattleBase, ccSceneChangeParamBossBattleUtil,
 * ccSceneGroupBattleLoadBoss, ccBoss00 — no symbols found in s2 build
 */
#ifndef S2_BOSS_FRAMEWORK_H
#define S2_BOSS_FRAMEWORK_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccSceneBossBattleUiManager
 * Ctor RVA: 0x448780 | vtable: 0x140835c38
 * Size: unknown, >= 0x108 (last proven write at +0x100, 4 bytes)
 * Embedded at param_1+0x50 inside ccSceneBoss01
 * ======================================================================== */
typedef struct ccSceneBossBattleUiManager {
    /* 0x00 */ void *vtable;              /* PTR_FUN_140835c38 */
    /* 0x08 */ uint64_t unk_08;           /* zeroed in ctor */
    /* 0x10 */ uint32_t unk_10;           /* zeroed in ctor */
    /* 0x14 */ uint32_t pad_14;
    /* 0x18 */ uint8_t detector_18[0xA8]; /* btBoxBoxDetector(param_1+3,0); gap to 0xC0 */
    /* 0xC0 */ uint32_t unk_C0;           /* zeroed in ctor */
    /* 0xC4 */ int32_t field_C4;          /* = 0xFFFFFFFF (-1), likely "no selection" sentinel */
    /* 0xC8 */ uint64_t unk_C8;           /* zeroed */
    /* 0xD0 */ uint64_t unk_D0;           /* zeroed */
    /* 0xD8 */ uint64_t unk_D8;           /* zeroed */
    /* 0xE0 */ uint32_t unk_E0;           /* zeroed */
    /* 0xE4 */ uint32_t pad_E4;
    /* 0xE8 */ uint64_t unk_E8;           /* zeroed */
    /* 0xF0 */ uint64_t unk_F0;           /* read in ctor (low conf) */
    /* 0xF8 */ uint32_t pad_F8;
    /* 0xFC */ int32_t field_FC;          /* = 0xFFFFFFFF (-1), likely "no selection" sentinel */
    /* 0x100 */ uint32_t unk_100;         /* zeroed in ctor */
    /* 0x104 */ uint32_t pad_104;
    /* Size unknown, >= 0x108 */
} ccSceneBossBattleUiManager;

static_assert(offsetof(ccSceneBossBattleUiManager, vtable)      == 0x00,  "vtable");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_08)      == 0x08,  "unk_08");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_10)      == 0x10,  "unk_10");
static_assert(offsetof(ccSceneBossBattleUiManager, detector_18) == 0x18,  "detector_18");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_C0)      == 0xC0,  "unk_C0");
static_assert(offsetof(ccSceneBossBattleUiManager, field_C4)    == 0xC4,  "field_C4");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_C8)      == 0xC8,  "unk_C8");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_D0)      == 0xD0,  "unk_D0");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_D8)      == 0xD8,  "unk_D8");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_E0)      == 0xE0,  "unk_E0");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_E8)      == 0xE8,  "unk_E8");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_F0)      == 0xF0,  "unk_F0");
static_assert(offsetof(ccSceneBossBattleUiManager, field_FC)    == 0xFC,  "field_FC");
static_assert(offsetof(ccSceneBossBattleUiManager, unk_100)     == 0x100, "unk_100");

/* ========================================================================
 * ccBossBattleCommandObject
 * Ctor RVA: 0x2EFD1C | vtable: 0x1407eadc0
 * Size: unknown, >= 0x4DC (last proven write at +0x4D8, 4 bytes)
 * Contains: Nucc::Vector3 at +0x2C, ccCmnRotate at +0x38, two btBoxBoxDetector,
 * ccUiScalePerspective2d at +0xC8, ccPlayerPad at +0x108
 *
 * Layout note: ptr_or_ref_28 is uint32 (not uint64) so that position can
 * start at 0x2C without overlap. The low-conf read that suggested a 64-bit
 * value at 0x28 may have been reading across two adjacent 32-bit fields.
 * ======================================================================== */
typedef struct ccBossBattleCommandObject {
    /* 0x00 */ void *vtable;              /* PTR_FUN_1407eadc0 */
    /* 0x08 */ uint64_t unk_08;           /* zeroed (param_1[1]) */
    /* 0x10 */ uint64_t unk_10;           /* zeroed (param_1[2]) */
    /* 0x18 */ uint64_t unk_18;           /* zeroed (param_1[3]) */
    /* 0x20 */ uint32_t unk_20;           /* zeroed (param_1[4]) */
    /* 0x24 */ uint32_t pad_24;
    /* 0x28 */ uint32_t ptr_or_ref_28;    /* rw low-conf, possibly parent ptr (uint32 to avoid overlap with position at 0x2C) */
    /* 0x2C */ uint8_t position[0x0C];    /* Nucc::Vector3 at +0x2C (12 bytes: x,y,z float) */
    /* 0x38 */ uint8_t rotation[0x58];    /* ccCmnRotate at +0x38; size inferred from gap to 0x90 */
    /* 0x90 */ uint32_t unk_90;           /* zeroed */
    /* 0x94 */ uint32_t unk_94;           /* zeroed */
    /* 0x98 */ uint32_t unk_98;           /* zeroed */
    /* 0x9C */ uint32_t pad_9C;
    /* 0xA0 */ uint64_t unk_A0;           /* read low-conf */
    /* 0xA8 */ uint64_t unk_A8;
    /* 0xB0 */ uint64_t unk_B0;           /* read low-conf */
    /* 0xB8 */ uint64_t unk_B8;
    /* 0xC0 */ uint32_t unk_C0;           /* zeroed */
    /* 0xC4 */ uint32_t unk_C4;           /* zeroed */
    /* 0xC8 */ uint8_t ui_scale[0x38];    /* ccUiScalePerspective2d at +0xC8; size inferred from gap to 0x100 */
    /* 0x100 */ int32_t field_100;        /* high-conf rw, Initialize writes here */
    /* 0x104 */ uint32_t pad_104;
    /* 0x108 */ uint8_t player_pad[0x3D0]; /* ccPlayerPad at +0x108; size inferred from gap to 0x4D8 */
    /* 0x4D8 */ uint32_t unk_4D8;         /* zeroed in ctor */
    /* 0x4DC */ uint32_t pad_4DC;
    /* Size unknown, >= 0x4E0 */
} ccBossBattleCommandObject;

static_assert(offsetof(ccBossBattleCommandObject, vtable)         == 0x00,  "vtable");
static_assert(offsetof(ccBossBattleCommandObject, unk_08)         == 0x08,  "unk_08");
static_assert(offsetof(ccBossBattleCommandObject, unk_10)         == 0x10,  "unk_10");
static_assert(offsetof(ccBossBattleCommandObject, unk_18)         == 0x18,  "unk_18");
static_assert(offsetof(ccBossBattleCommandObject, unk_20)         == 0x20,  "unk_20");
static_assert(offsetof(ccBossBattleCommandObject, ptr_or_ref_28)  == 0x28,  "ptr_or_ref_28");
static_assert(offsetof(ccBossBattleCommandObject, position)       == 0x2C,  "position");
static_assert(offsetof(ccBossBattleCommandObject, rotation)       == 0x38,  "rotation");
static_assert(offsetof(ccBossBattleCommandObject, unk_90)         == 0x90,  "unk_90");
static_assert(offsetof(ccBossBattleCommandObject, unk_94)         == 0x94,  "unk_94");
static_assert(offsetof(ccBossBattleCommandObject, unk_98)         == 0x98,  "unk_98");
static_assert(offsetof(ccBossBattleCommandObject, unk_A0)         == 0xA0,  "unk_A0");
static_assert(offsetof(ccBossBattleCommandObject, unk_A8)         == 0xA8,  "unk_A8");
static_assert(offsetof(ccBossBattleCommandObject, unk_B0)         == 0xB0,  "unk_B0");
static_assert(offsetof(ccBossBattleCommandObject, unk_B8)         == 0xB8,  "unk_B8");
static_assert(offsetof(ccBossBattleCommandObject, unk_C0)         == 0xC0,  "unk_C0");
static_assert(offsetof(ccBossBattleCommandObject, unk_C4)         == 0xC4,  "unk_C4");
static_assert(offsetof(ccBossBattleCommandObject, ui_scale)       == 0xC8,  "ui_scale");
static_assert(offsetof(ccBossBattleCommandObject, field_100)      == 0x100, "field_100");
static_assert(offsetof(ccBossBattleCommandObject, player_pad)     == 0x108, "player_pad");
static_assert(offsetof(ccBossBattleCommandObject, unk_4D8)        == 0x4D8, "unk_4D8");

/* ========================================================================
 * ccSceneBossBattleIA
 * Ctor RVA: 0x445840 | vtable: 0x140835668
 * Inherits: ccScene (ccScene::ccScene() called first)
 * Size: unknown, >= 0x508 (last proven access at +0x500 in ExitState)
 * Contains: ccIaStage at +0x348, two 0x100-byte string buffers
 *
 * Layout note: ia_stage is sized to fill the gap from 0x348 to 0x480 (0x138
 * bytes) so that subsequent uint64 fields land at their proven offsets.
 * field_4C4 is placed at 0x4C8 because the preceding uint64 at 0x4C0 ends
 * at 0x4C8 with natural alignment; the state_surface offset 0x4C4 likely
 * reflects a misaligned read or a sub-field within a larger register op.
 * ======================================================================== */
typedef struct ccSceneBossBattleIA {
    /* 0x000 */ uint8_t ccScene_base[0x128]; /* ccScene base class placeholder */
    /* 0x128 */ uint32_t unk_128;            /* *(param_1+0x25)=0 => offset 0x128 */
    /* 0x12C */ uint32_t unk_12C;            /* *(param_1+300)=0 => offset 0x12C */
    /* 0x130 */ uint32_t field_130;          /* Execute reads/writes, medium conf */
    /* 0x134 */ int32_t boss_id;             /* = param_2, boss identifier */
    /* 0x138 */ char ia_name[0x100];         /* nuccStrCpy(param_1+0x27, param_4, 0x100) => byte 0x138 */
    /* 0x238 */ char scene_name[0x100];      /* nuccStrCpy(param_1+0x47, param_5, 0x100) => byte 0x238 */
    /* 0x338 */ uint32_t field_338;          /* = param_6 */
    /* 0x33C */ int32_t field_33C;           /* = param_7, medium conf write */
    /* 0x340 */ uint32_t field_340;          /* = param_8 */
    /* 0x344 */ uint32_t unk_344;            /* zeroed in ctor */
    /* 0x348 */ uint8_t ia_stage[0x138];     /* ccIaStage at +0x348; fills gap to 0x480 */
    /* 0x480 */ uint64_t unk_480;            /* EnterState reads, low conf */
    /* 0x488 */ uint64_t unk_488;
    /* 0x490 */ uint64_t unk_490;
    /* 0x498 */ uint64_t unk_498;
    /* 0x4A0 */ uint64_t unk_4A0;
    /* 0x4A8 */ uint64_t unk_4A8;
    /* 0x4B0 */ uint64_t unk_4B0;
    /* 0x4B8 */ uint64_t unk_4B8;
    /* 0x4C0 */ uint64_t unk_4C0;            /* UpdateState+_Finalize read, low conf */
    /* 0x4C8 */ uint32_t field_4C4;          /* zeroed in ctor, medium conf; at 0x4C8 after uint64 alignment */
    /* 0x4CC */ uint32_t pad_4CC;
    /* 0x4D0 */ uint64_t unk_4D0;
    /* 0x4D8 */ uint64_t unk_4D8;
    /* 0x4E0 */ uint64_t unk_4E0;
    /* 0x4E8 */ uint64_t unk_4E8;
    /* 0x4F0 */ uint64_t unk_4F0;
    /* 0x4F8 */ uint64_t unk_4F8;
    /* 0x500 */ uint64_t unk_500;            /* ExitState reads, low conf */
    /* Size unknown, >= 0x508 */
} ccSceneBossBattleIA;

static_assert(offsetof(ccSceneBossBattleIA, ccScene_base) == 0x000, "ccScene_base");
static_assert(offsetof(ccSceneBossBattleIA, unk_128)      == 0x128, "unk_128");
static_assert(offsetof(ccSceneBossBattleIA, unk_12C)      == 0x12C, "unk_12C");
static_assert(offsetof(ccSceneBossBattleIA, field_130)    == 0x130, "field_130");
static_assert(offsetof(ccSceneBossBattleIA, boss_id)      == 0x134, "boss_id");
static_assert(offsetof(ccSceneBossBattleIA, ia_name)      == 0x138, "ia_name");
static_assert(offsetof(ccSceneBossBattleIA, scene_name)   == 0x238, "scene_name");
static_assert(offsetof(ccSceneBossBattleIA, field_338)    == 0x338, "field_338");
static_assert(offsetof(ccSceneBossBattleIA, field_33C)    == 0x33C, "field_33C");
static_assert(offsetof(ccSceneBossBattleIA, field_340)    == 0x340, "field_340");
static_assert(offsetof(ccSceneBossBattleIA, unk_344)      == 0x344, "unk_344");
static_assert(offsetof(ccSceneBossBattleIA, ia_stage)     == 0x348, "ia_stage");
static_assert(offsetof(ccSceneBossBattleIA, unk_480)      == 0x480, "unk_480");
static_assert(offsetof(ccSceneBossBattleIA, unk_4C0)      == 0x4C0, "unk_4C0");
static_assert(offsetof(ccSceneBossBattleIA, field_4C4)    == 0x4C8, "field_4C4_at_4C8");
static_assert(offsetof(ccSceneBossBattleIA, unk_500)      == 0x500, "unk_500");

/* ========================================================================
 * ccUiDuelBossGauge
 * Ctor RVA: 0x4C7648 | Dtor RVA: 0x4C78AC
 * Inherits: ccUiTaskMessage (memset at +0x4C for 0x28 bytes)
 * Size: >= 0x9B8 (from state_surface: last field at 0x93C + BlockAllocator at 0x9A0)
 * ======================================================================== */
typedef struct ccUiDuelBossGauge {
    /* 0x00 */ uint8_t ccUiTaskMessage_base[0x4C];  /* ccUiTaskMessage base class */
    /* 0x4C */ uint8_t memset_region[0x8EC];        /* zeroed region from ctor memset + subsequent init */
    /* 0x938 */ uint64_t unk_938;
    /* 0x940 */ uint64_t unk_940;
    /* 0x948 */ uint64_t unk_948;
    /* 0x950 */ uint64_t unk_950;
    /* 0x958 */ uint64_t unk_958;
    /* 0x960 */ uint64_t unk_960;
    /* 0x968 */ uint64_t unk_968;
    /* 0x970 */ uint64_t unk_970;
    /* 0x978 */ uint64_t unk_978;
    /* 0x980 */ uint64_t unk_980;
    /* 0x988 */ uint64_t unk_988;
    /* 0x990 */ uint64_t unk_990;
    /* 0x998 */ uint64_t unk_998;
    /* 0x9A0 */ uint64_t block_allocator_ptr;       /* BlockAllocator at param_1+0x134 => byte 0x9A0 */
    /* 0x9A8 */ uint8_t pad_9A8[0x10];
    /* Size >= 0x9B8 */
} ccUiDuelBossGauge;

static_assert(offsetof(ccUiDuelBossGauge, ccUiTaskMessage_base) == 0x00,  "base");
static_assert(offsetof(ccUiDuelBossGauge, memset_region)        == 0x4C,  "memset_region");
static_assert(offsetof(ccUiDuelBossGauge, unk_938)              == 0x938, "unk_938");
static_assert(offsetof(ccUiDuelBossGauge, block_allocator_ptr)  == 0x9A0, "block_allocator");

/* ========================================================================
 * ccBossTargetCursor
 * Ctor RVA: 0x2F456C | vtable: 0x1407eb9f8
 * Inherits: ccTaskBase (ccTaskBase ctor called first with &DAT_140a00d50, priority 5)
 * EMBEDDED inside ccBoss04Sight at offset 0xD0 (param_1+0x1a => byte 0xD0)
 * Offsets below are CONTAINER-RELATIVE (as reported by state_surface on ccBoss04Sight).
 * ======================================================================== */
typedef struct ccBossTargetCursor {
    /* 0x0000 */ uint8_t ccTaskBase_base[0x14B8]; /* ccTaskBase + padding to first known field */
    /* 0x14B8 */ uint64_t unk_14B8;               /* read in ctor, low conf */
    /* 0x14C0 */ uint64_t cursor_pos_x;            /* written in ctor, medium conf */
    /* 0x14C8 */ uint64_t cursor_pos_y;            /* written in ctor, medium conf */
    /* 0x14D0 */ uint64_t cursor_target_x;         /* written in ctor, medium conf */
    /* 0x14D8 */ uint64_t cursor_target_y;         /* written in ctor, medium conf */
    /* 0x14E0 */ uint32_t cursor_active;           /* written in ctor, medium conf */
    /* 0x14E4 */ uint32_t pad_14E4;
} ccBossTargetCursor;

static_assert(offsetof(ccBossTargetCursor, ccTaskBase_base)  == 0x0000, "ccTaskBase_base");
static_assert(offsetof(ccBossTargetCursor, unk_14B8)         == 0x14B8, "unk_14B8");
static_assert(offsetof(ccBossTargetCursor, cursor_pos_x)     == 0x14C0, "cursor_pos_x");
static_assert(offsetof(ccBossTargetCursor, cursor_pos_y)     == 0x14C8, "cursor_pos_y");
static_assert(offsetof(ccBossTargetCursor, cursor_target_x)  == 0x14D0, "cursor_target_x");
static_assert(offsetof(ccBossTargetCursor, cursor_target_y)  == 0x14D8, "cursor_target_y");
static_assert(offsetof(ccBossTargetCursor, cursor_active)    == 0x14E0, "cursor_active");

/* ========================================================================
 * ccBossStage
 * Ctor RVA: 0x2F39F4 | vtable: 0x1407eb838
 * Inherits: ccBossBattleObjectBase (ctor called first)
 * Contains: ccStageObjectList at +0x98
 * Size: unknown, >= 0x3C8 (CreateStage reads at +0x3C0)
 * ======================================================================== */
typedef struct ccBossStage {
    /* 0x00 */ uint8_t ccBossBattleObjectBase_base[0x98]; /* base class */
    /* 0x98 */ uint8_t stage_objects[0x170];              /* ccStageObjectList at +0x98; gap to 0x208 */
    /* 0x208 */ uint64_t stage_data_ptr;                  /* rw high-conf, CreateStage+ctor */
    /* 0x210 */ uint8_t pad_210[0x1B0];                   /* gap to 0x3C0 */
    /* 0x3C0 */ uint64_t unk_3C0;                         /* CreateStage reads, low conf */
    /* 0x3C8 */ uint8_t pad_3C8[8];
    /* Size unknown, >= 0x3D0 */
} ccBossStage;

static_assert(offsetof(ccBossStage, ccBossBattleObjectBase_base) == 0x00,  "base");
static_assert(offsetof(ccBossStage, stage_objects)               == 0x98,  "stage_objects");
static_assert(offsetof(ccBossStage, stage_data_ptr)              == 0x208, "stage_data_ptr");
static_assert(offsetof(ccBossStage, unk_3C0)                     == 0x3C0, "unk_3C0");

/* ========================================================================
 * ccBossBattleIaLoader
 * Ctor RVA: 0x2F24A0 | vtable: 0x1407eb758
 * Contains: ccBaseCoord at +0x08, then 8 more ccBaseCoord entries (stride 0x40 each)
 * Also: ccFileLoadListForUi embedded at param_1+9 (in factory FUN_1402f24f8)
 * ======================================================================== */
typedef struct ccBossBattleIaLoader {
    /* 0x00 */ void *vtable;            /* PTR_FUN_1407eb758 */
    /* 0x08 */ uint32_t field_08;       /* = 0xFFFFFFFF (-1), written before vtable */
    /* 0x0C */ uint32_t pad_0C;
    /* 0x10 */ uint8_t coords[0x200];   /* 8 ccBaseCoord entries at +0x10, stride 0x40 = 8*0x40 = 0x200 */
} ccBossBattleIaLoader;

static_assert(offsetof(ccBossBattleIaLoader, vtable)  == 0x00, "vtable");
static_assert(offsetof(ccBossBattleIaLoader, field_08)== 0x08, "field_08");
static_assert(offsetof(ccBossBattleIaLoader, coords)  == 0x10, "coords");

/* ========================================================================
 * PARTIAL LAYOUTS — Extended decompilation pass
 * These structs have fewer confirmed fields; sizes are lower bounds.
 * ======================================================================== */

/* ========================================================================
 * ccBossBattleCaptionManager
 * Size: 0x18 (exact — FUN_140580190(0x18,...) in CreateInstance)
 * vtable: 0x14079fc58 | Singleton at DAT_140a005f0
 * ======================================================================== */
typedef struct ccBossBattleCaptionManager {
    /* 0x00 */ void *vtable;            /* PTR_FUN_14079fc58 */
    /* 0x08 */ uint64_t field_08;       /* uint64, purpose unknown */
    /* 0x10 */ uint32_t field_10;       /* uint32 */
    /* 0x14 */ int32_t field_14;        /* initialized to 1 in ctor */
} ccBossBattleCaptionManager;

static_assert(sizeof(ccBossBattleCaptionManager) == 0x18, "ccBossBattleCaptionManager_size");
static_assert(offsetof(ccBossBattleCaptionManager, vtable)  == 0x00, "vtable");
static_assert(offsetof(ccBossBattleCaptionManager, field_08)== 0x08, "field_08");
static_assert(offsetof(ccBossBattleCaptionManager, field_10)== 0x10, "field_10");
static_assert(offsetof(ccBossBattleCaptionManager, field_14)== 0x14, "field_14");

/* ========================================================================
 * ccBossBattleUi
 * Size: unknown, >= 0x40 (last field at +0x38)
 * Sub-object allocations: +0x28 array of 0x18-byte entries,
 *   +0x30 = 0x1530 bytes (ccBossBattleCaption main),
 *   +0x38 = 0x1558 bytes (ccBossBattleCaption secondary)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBossBattleUi {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint32_t count;          /* entry count for array at +0x28 */
    /* 0x0C */ float field_0C;
    /* 0x10 */ int32_t field_10;
    /* 0x14 */ int32_t field_14;
    /* 0x18 */ int32_t field_18;
    /* 0x1C */ uint64_t field_1C;
    /* 0x24 */ uint32_t field_24;
    /* 0x28 */ uint64_t array_ptr;      /* ptr to count x 0x18 caption entries */
    /* 0x30 */ uint64_t caption_main;   /* ptr to 0x1530-byte ccBossBattleCaption */
    /* 0x38 */ uint64_t caption_secondary; /* ptr to 0x1558-byte ccBossBattleCaption (when param_5 != -1) */
    /* Size unknown, >= 0x40 */
} ccBossBattleUi;

static_assert(offsetof(ccBossBattleUi, vtable)           == 0x00, "vtable");
static_assert(offsetof(ccBossBattleUi, count)            == 0x08, "count");
static_assert(offsetof(ccBossBattleUi, field_0C)         == 0x0C, "field_0C");
static_assert(offsetof(ccBossBattleUi, field_10)         == 0x10, "field_10");
static_assert(offsetof(ccBossBattleUi, field_14)         == 0x14, "field_14");
static_assert(offsetof(ccBossBattleUi, field_18)         == 0x18, "field_18");
static_assert(offsetof(ccBossBattleUi, field_1C)         == 0x1C, "field_1C");
static_assert(offsetof(ccBossBattleUi, field_24)         == 0x24, "field_24");
static_assert(offsetof(ccBossBattleUi, array_ptr)        == 0x28, "array_ptr");
static_assert(offsetof(ccBossBattleUi, caption_main)     == 0x30, "caption_main");
static_assert(offsetof(ccBossBattleUi, caption_secondary)== 0x38, "caption_secondary");

/* ========================================================================
 * ccSceneBossBattleLoading
 * Inherits: ccScene (base 0x128)
 * Size: unknown, >= 0x138 (last field at +0x130, ptr)
 * Execute reads/writes +0x128 state, +0x130 sub-obj with vtable call at +0x18
 * ======================================================================== */
typedef struct ccSceneBossBattleLoading {
    /* 0x000 */ uint8_t ccScene_base[0x128]; /* ccScene base class */
    /* 0x128 */ int32_t state_int;           /* Execute dispatches on this */
    /* 0x12C */ uint32_t pad_12C;
    /* 0x130 */ uint64_t sub_obj_ptr;        /* sub-object with vtable calls at +0x18 */
    /* Size unknown, >= 0x138 */
} ccSceneBossBattleLoading;

static_assert(offsetof(ccSceneBossBattleLoading, ccScene_base) == 0x000, "ccScene_base");
static_assert(offsetof(ccSceneBossBattleLoading, state_int)    == 0x128, "state_int");
static_assert(offsetof(ccSceneBossBattleLoading, sub_obj_ptr)  == 0x130, "sub_obj_ptr");

/* ========================================================================
 * ccSceneBossBattleRetryMenu
 * Inherits: ccScene (base 0x128)
 * Size: unknown, >= 0x140 (last field at +0x138, ptr)
 * CtrlPhase_MENU allocates ccUiSelectWindow via FUN_140580190(0x198,...)
 * ======================================================================== */
typedef struct ccSceneBossBattleRetryMenu {
    /* 0x000 */ uint8_t ccScene_base[0x128]; /* ccScene base class */
    /* 0x128 */ uint8_t pad_128[8];          /* gap from base to first known field */
    /* 0x130 */ int32_t field_130;
    /* 0x134 */ int32_t selected_index;      /* menu selection index */
    /* 0x138 */ uint64_t select_window_ptr;  /* ptr to 0x198-byte ccUiSelectWindow */
    /* Size unknown, >= 0x140 */
} ccSceneBossBattleRetryMenu;

static_assert(offsetof(ccSceneBossBattleRetryMenu, ccScene_base)     == 0x000, "ccScene_base");
static_assert(offsetof(ccSceneBossBattleRetryMenu, field_130)        == 0x130, "field_130");
static_assert(offsetof(ccSceneBossBattleRetryMenu, selected_index)   == 0x134, "selected_index");
static_assert(offsetof(ccSceneBossBattleRetryMenu, select_window_ptr)== 0x138, "select_window_ptr");

/* ========================================================================
 * ccSceneBossBattleRoot
 * Inherits: ccScene (base 0x128)
 * Size: unknown, >= 0x130 (last field at +0x128, int)
 * Execute dispatches by boss scene name (ccSceneBoss01-09) via FUN_1402f3038
 * with boss IDs 0x22-0x3a (stride 6)
 * ======================================================================== */
typedef struct ccSceneBossBattleRoot {
    /* 0x000 */ uint8_t ccScene_base[0x128]; /* ccScene base class */
    /* 0x128 */ int32_t state_int;           /* dispatch state */
    /* 0x12C */ uint32_t pad_12C;
    /* Size unknown, >= 0x130 */
} ccSceneBossBattleRoot;

static_assert(offsetof(ccSceneBossBattleRoot, ccScene_base) == 0x000, "ccScene_base");
static_assert(offsetof(ccSceneBossBattleRoot, state_int)    == 0x128, "state_int");

/* ========================================================================
 * ccScenePlayBossBattle
 * Inherits: ccScene (base 0x128)
 * Size: unknown, >= 0x138 (last field at +0x130, ptr)
 * Execute reads +0x128 state machine, +0x130 sub-obj with vtable calls
 * at +8, +0x10, +0x18
 * ======================================================================== */
typedef struct ccScenePlayBossBattle {
    /* 0x000 */ uint8_t ccScene_base[0x128]; /* ccScene base class */
    /* 0x128 */ int32_t state_int;           /* state machine dispatch */
    /* 0x12C */ uint32_t pad_12C;
    /* 0x130 */ uint64_t sub_obj_ptr;        /* sub-object with vtable calls at +8,+0x10,+0x18 */
    /* Size unknown, >= 0x138 */
} ccScenePlayBossBattle;

static_assert(offsetof(ccScenePlayBossBattle, ccScene_base) == 0x000, "ccScene_base");
static_assert(offsetof(ccScenePlayBossBattle, state_int)    == 0x128, "state_int");
static_assert(offsetof(ccScenePlayBossBattle, sub_obj_ptr)  == 0x130, "sub_obj_ptr");

/* ========================================================================
 * ccSceneBossBattleResult
 * Inherits: ccScene (base 0x128)
 * Size: unknown, >= 0x150 (last field at +0x148, ptr)
 * CtrlPhase_REWARD allocates ccUiDuelReward via FUN_140580190(0xd0,...)
 * ======================================================================== */
typedef struct ccSceneBossBattleResult {
    /* 0x000 */ uint8_t ccScene_base[0x128]; /* ccScene base class */
    /* 0x128 */ uint8_t pad_128[0x20];       /* gap to reward_ui_ptr */
    /* 0x148 */ uint64_t reward_ui_ptr;      /* ptr to 0xD0-byte ccUiDuelReward */
    /* Size unknown, >= 0x150 */
} ccSceneBossBattleResult;

static_assert(offsetof(ccSceneBossBattleResult, ccScene_base)   == 0x000, "ccScene_base");
static_assert(offsetof(ccSceneBossBattleResult, reward_ui_ptr)  == 0x148, "reward_ui_ptr");

/* ========================================================================
 * ccUiCollectionModeBossBattle
 * Size: unknown, >= 0x138 (last field at +0x130, ptr)
 * Ctrl reads/writes multiple fields; list iteration at +0xA0
 * ======================================================================== */
typedef struct ccUiCollectionModeBossBattle {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint8_t pad_08[0x30];        /* gap to sub_struct */
    /* 0x38 */ uint64_t sub_struct;          /* embedded sub-struct, type unknown */
    /* 0x40 */ uint8_t pad_40[0x48];        /* gap to ptr at +0x88 */
    /* 0x88 */ uint64_t field_88;           /* ptr, purpose unknown */
    /* 0x90 */ int32_t index;               /* collection index */
    /* 0x94 */ uint32_t pad_94;
    /* 0x98 */ uint64_t pad_98;
    /* 0xA0 */ uint64_t list_ptr;           /* ptr to iterable list */
    /* 0xA8 */ uint8_t pad_A8[0x20];        /* gap to state_int */
    /* 0xC8 */ int32_t state_int;           /* Ctrl dispatch state */
    /* 0xCC */ uint32_t pad_CC;
    /* 0xD0 */ uint8_t pad_D0[0x60];        /* gap to last ptr */
    /* 0x130 */ uint64_t field_130;         /* ptr, purpose unknown */
    /* Size unknown, >= 0x138 */
} ccUiCollectionModeBossBattle;

static_assert(offsetof(ccUiCollectionModeBossBattle, vtable)     == 0x00,  "vtable");
static_assert(offsetof(ccUiCollectionModeBossBattle, sub_struct) == 0x38,  "sub_struct");
static_assert(offsetof(ccUiCollectionModeBossBattle, field_88)   == 0x88,  "field_88");
static_assert(offsetof(ccUiCollectionModeBossBattle, index)      == 0x90,  "index");
static_assert(offsetof(ccUiCollectionModeBossBattle, list_ptr)   == 0xA0,  "list_ptr");
static_assert(offsetof(ccUiCollectionModeBossBattle, state_int)  == 0xC8,  "state_int");
static_assert(offsetof(ccUiCollectionModeBossBattle, field_130)  == 0x130, "field_130");

/* ========================================================================== */
/* Coverage batch 3 — classes with no instance state or minimal fields        */
/* ========================================================================== */

/*
 * ccBossBattleObjectManager — NO INSTANCE STATE (template factory)
 *
 * All 49 methods are static template instantiations: Create<T>,
 * CreateWithParam<T,P>, CreateWithPtr<T,P>. No ctor/dtor, no vtable,
 * no this-pointer field accesses in any seed (state_surface returned
 * 0 accesses across all seeds). This class is a compile-time factory;
 * it has no runtime object representation.
 *
 * Evidence: ns2names.txt grep, the decompiler cache state_surface (all seeds = 0 accesses)
 */

/*
 * ccBossBattleState — NO INSTANCE STATE
 *
 * 18 methods (ctor, dtor, ExecDraw, ExecEnter, ExecState, PreProcess,
 * StepBattleEnter/State, StepBeginEnter/State, StepFadeEnter/State,
 * StepLoseEnter/State, StepToNextPhaseEnter/ReadyEnter/State,
 * BoundBossGauge, TransformBossGauge). state_surface returned 0 fields
 * across all 9 seeds analyzed. Methods likely operate on external state
 * passed via parameters rather than member fields.
 *
 * Evidence: the decompiler cache state_surface (9 seeds, 0 fields)
 */

/*
 * ccBossBattleCaption — NO INSTANCE STATE
 *
 * 6 methods (ctor, dtor, Ctrl, Draw, OnDestroy, SetCaption).
 * state_surface returned 0 fields across all 4 seeds analyzed.
 * Likely a thin wrapper that delegates to UI subsystem without
 * holding its own persistent state.
 *
 * Evidence: the decompiler cache state_surface (4 seeds, 0 fields)
 */

/*
 * ccBossBattleManager — PARTIAL LAYOUT (singleton, dtor-only evidence)
 *
 * Only the dtor resolves by name (RVA 0x2F2630). Initialize, Finalize,
 * LoadFileTable, UnloadAll, UnloadFileTable, IsLoaded do not resolve
 * (likely inlined or non-standard mangling). Singleton via ms_instance.
 *
 * Dtor decompilation reveals:
 *   - vtable set to PTR_FUN_1407eb760 (vtable RVA 0x3EB760)
 *   - sub-object destructor at param_1 + 0x08 (FUN_14059cd70)
 *   - sub-object destructor at param_1 + 0x48 (FUN_140649c90)
 *   - sub-object destructor at param_1 + 0x78 (FUN_1402f25cc)
 *
 * Size unknown, >= 0x80 (last access at +0x78 as uint64 ptr).
 * No struct emitted: only 3 sub-object pointers visible in dtor teardown,
 * insufficient for a meaningful layout. Fields below recorded in TSV.
 *
 * Evidence: the decompiler cache decomp dtor 0x2F2630, state_surface (1 low-conf field)
 */

#endif /* S2_BOSS_FRAMEWORK_H */
/* ========================================================================
 * ccBossBattleManager
 * Dtor RVA: 0x2F2630 | vtable: 0x1407eb760
 * Singleton via ms_instance (symbol in ns2names.txt, address unresolved)
 * Size: unknown, >= 0x80 (last access at +0x78 as uint64 ptr in dtor)
 *
 * Dtor teardown reveals three sub-object destructors:
 *   FUN_14059cd70(param_1 + 1)  => offset 0x08
 *   FUN_140649c90(param_1 + 9)  => offset 0x48
 *   FUN_1402f25cc(param_1 + 0xf) => offset 0x78
 * Initialize/Finalize/LoadFileTable/UnloadAll/UnloadFileTable/IsLoaded
 * exist in ns2names.txt but do not resolve by name (inlined or non-standard
 * mangling). Only the dtor is resolvable.
 *
 * Evidence: the decompiler cache state_surface (1 low-conf field at +0x78 from dtor),
 *           the decompiler cache decomp dtor 0x2F2630 (vtable + 3 sub-obj dtors)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBossBattleManager {
    /* 0x00 */ void *vtable;            /* PTR_FUN_1407eb760, set in dtor */
    /* 0x08 */ uint64_t sub_obj_08;     /* FUN_14059cd70(param_1+1) in dtor */
    /* 0x10 */ uint8_t pad_10[0x38];    /* gap to next known sub-object */
    /* 0x48 */ uint64_t sub_obj_48;     /* FUN_140649c90(param_1+9) in dtor */
    /* 0x50 */ uint8_t pad_50[0x28];    /* gap to next known sub-object */
    /* 0x78 */ uint64_t sub_obj_78;     /* FUN_1402f25cc(param_1+0xf) in dtor */
    /* Size unknown, >= 0x80 */
} ccBossBattleManager;

static_assert(offsetof(ccBossBattleManager, vtable)     == 0x00, "vtable");
static_assert(offsetof(ccBossBattleManager, sub_obj_08) == 0x08, "sub_obj_08");
static_assert(offsetof(ccBossBattleManager, sub_obj_48) == 0x48, "sub_obj_48");
static_assert(offsetof(ccBossBattleManager, sub_obj_78) == 0x78, "sub_obj_78");

