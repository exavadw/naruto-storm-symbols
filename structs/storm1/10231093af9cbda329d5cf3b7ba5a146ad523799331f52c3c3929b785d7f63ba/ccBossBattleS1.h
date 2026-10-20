#ifndef CC_BOSS_BATTLE_S1_H
#define CC_BOSS_BATTLE_S1_H

#include <stdint.h>
#include <stddef.h>

/*
 * ccBossBattleS1 — Storm 1 (NSUNS1.exe) boss-battle and skill-hit-demo structs.
 * All layouts INFERRED from static analysis (state_surface + decomp samples).
 * Object sizes come from game code where found; otherwise stated as >= last proven field end.
 * Carried names from nucc pipeline are used as-is; see ccBossBattleS1-namecheck.tsv for
 * verdicts on mislabels (many ccBoss0x* names are S3 artifacts).
 */

/* ccBoss01PlayVoiceState — voice state manager (size unknown, >= 0x88) */
typedef struct ccBoss01PlayVoiceState {
    uint8_t pad_00[0x80];              /* 0x00-0x7F: vtable + unknown base */
    void   *unk_80;                    /* 0x80: read in PlayVoiceTable (vfunc dispatch ptr) */
} ccBoss01PlayVoiceState;
/* size unknown, >= 0x88 */
_Static_assert(offsetof(ccBoss01PlayVoiceState, unk_80) == 0x80, "ccBoss01PlayVoiceState.unk_80");

/* ccBoss0401FormationBase — multi-entity formation maintainer (size unknown, >= 0x80) */
typedef struct ccBoss0401FormationBase {
    uint8_t pad_00[0x58];              /* 0x00-0x57: base class */
    void   *unk_58;                    /* 0x58: read in dtor */
    uint8_t pad_60[0x10];             /* 0x60-0x6F */
    void   *unk_70;                    /* 0x70: rw in dtor */
    void   *unk_78;                    /* 0x78: written in dtor */
} ccBoss0401FormationBase;
/* size unknown, >= 0x80 */
_Static_assert(offsetof(ccBoss0401FormationBase, unk_58) == 0x58, "ccBoss0401FormationBase.unk_58");
_Static_assert(offsetof(ccBoss0401FormationBase, unk_70) == 0x70, "ccBoss0401FormationBase.unk_70");
_Static_assert(offsetof(ccBoss0401FormationBase, unk_78) == 0x78, "ccBoss0401FormationBase.unk_78");

/* ccBoss07HugeCharacterSyncEff — large character effect sync with two mutexes (size unknown, >= 0x70) */
typedef struct ccBoss07HugeCharacterSyncEff {
    uint8_t pad_00[0x58];              /* 0x00-0x57: 8 zeroed qwords in ctor */
    void   *mutex_ptr_58;              /* 0x58: first mmMutex region (read) */
    void   *mutex_ptr_60;              /* 0x60: first mmMutex ctor target (write) */
    void   *mutex_ptr_68;              /* 0x68: second mmMutex region (read) */
} ccBoss07HugeCharacterSyncEff;
/* size unknown, >= 0x70 */
_Static_assert(offsetof(ccBoss07HugeCharacterSyncEff, mutex_ptr_58) == 0x58, "ccBoss07HugeCharacterSyncEff.mutex_ptr_58");
_Static_assert(offsetof(ccBoss07HugeCharacterSyncEff, mutex_ptr_60) == 0x60, "ccBoss07HugeCharacterSyncEff.mutex_ptr_60");
_Static_assert(offsetof(ccBoss07HugeCharacterSyncEff, mutex_ptr_68) == 0x68, "ccBoss07HugeCharacterSyncEff.mutex_ptr_68");

/* ccBossPreBattleIntevalState — pre-battle transition state (size unknown, >= 0x2B0) */
typedef struct ccBossPreBattleIntevalState {
    uint8_t pad_00[0xF0];              /* 0x00-0xEF */
    void   *unk_F0;                    /* 0xF0: read in dtor */
    uint8_t pad_F8[0x1B0];            /* 0xF8-0x2A7 */
    void   *unk_2A8;                   /* 0x2A8: rw in dtor */
} ccBossPreBattleIntevalState;
/* size unknown, >= 0x2B0 */
_Static_assert(offsetof(ccBossPreBattleIntevalState, unk_F0) == 0xF0, "ccBossPreBattleIntevalState.unk_F0");
_Static_assert(offsetof(ccBossPreBattleIntevalState, unk_2A8) == 0x2A8, "ccBossPreBattleIntevalState.unk_2A8");

/* ccSceneBoss07Phase03 — boss phase management scene object (size unknown, >= 0x22C) */
typedef struct ccSceneBoss07Phase03 {
    uint8_t pad_00[0x18];              /* 0x00-0x17: ctor zeroes array of 0x100 at +0x18 */
    uint8_t array_18[0x100];           /* 0x18-0x117: first 0x100-byte array */
    uint8_t array_118[0x100];          /* 0x118-0x217: second 0x100-byte array (memset in ctor) */
    float   float_218;                 /* 0x218: set to 1.0f in ctor */
    int32_t int_21C;                   /* 0x21C: set to -1 in ctor (param_1[5]) */
    uint8_t pad_220[8];               /* 0x220-0x227: includes alignment padding */
    void   *unk_228;                   /* 0x228: ptr written in ctor (aligned from decomp 0x224) */
} ccSceneBoss07Phase03;
/* size unknown, >= 0x230 */
_Static_assert(offsetof(ccSceneBoss07Phase03, array_18) == 0x18, "ccSceneBoss07Phase03.array_18");
_Static_assert(offsetof(ccSceneBoss07Phase03, array_118) == 0x118, "ccSceneBoss07Phase03.array_118");
_Static_assert(offsetof(ccSceneBoss07Phase03, float_218) == 0x218, "ccSceneBoss07Phase03.float_218");
_Static_assert(offsetof(ccSceneBoss07Phase03, int_21C) == 0x21C, "ccSceneBoss07Phase03.int_21C");
_Static_assert(offsetof(ccSceneBoss07Phase03, unk_228) == 0x228, "ccSceneBoss07Phase03.unk_228");

/* ccSkillHitDemoBase — base class for secret technique hit demo cut-ins (size unknown, >= 0x10C8) */
typedef struct ccSkillHitDemoBase {
    uint8_t pad_00[0x58];              /* 0x00-0x57: vtable + base */
    void   *state_ptr_58;              /* 0x58: main state pointer (rw in Ctrl/Init) */
    void   *unk_60;                    /* 0x60: read in Init */
    uint8_t pad_68[0x198];            /* 0x68-0x1FF */
    void   *unk_200;                   /* 0x200: rw in Ctrl */
    uint8_t pad_208[0x7F8];           /* 0x208-0x9FF */
    void   *demo_obj_A00;              /* 0xA00: demo object reference (read in Ctrl) */
    uint8_t pad_A08[0x678];           /* 0xA08-0x107F */
    void   *unk_1080;                  /* 0x1080: read in Init */
    uint8_t pad_1088[0x38];          /* 0x1088-0x10BF */
    void   *unk_10C0;                  /* 0x10C0: read in Init */
} ccSkillHitDemoBase;
/* size unknown, >= 0x10C8 */
_Static_assert(offsetof(ccSkillHitDemoBase, state_ptr_58) == 0x58, "ccSkillHitDemoBase.state_ptr_58");
_Static_assert(offsetof(ccSkillHitDemoBase, unk_60) == 0x60, "ccSkillHitDemoBase.unk_60");
_Static_assert(offsetof(ccSkillHitDemoBase, unk_200) == 0x200, "ccSkillHitDemoBase.unk_200");
_Static_assert(offsetof(ccSkillHitDemoBase, demo_obj_A00) == 0xA00, "ccSkillHitDemoBase.demo_obj_A00");
_Static_assert(offsetof(ccSkillHitDemoBase, unk_1080) == 0x1080, "ccSkillHitDemoBase.unk_1080");
_Static_assert(offsetof(ccSkillHitDemoBase, unk_10C0) == 0x10C0, "ccSkillHitDemoBase.unk_10C0");

/* ccSkillHitDemoStartBase — start sequence for hit demos (extends ccSkillHitDemoBase, size unknown, >= 0x1208) */
typedef struct ccSkillHitDemoStartBase {
    uint8_t pad_00[0xC];               /* 0x00-0x0B */
    int32_t msg_id_C;                  /* 0x0C: message dispatch id (rw in Ctrl/MessageDispatcher) */
    uint8_t pad_10[0x48];             /* 0x10-0x57 */
    void   *state_ptr_58;              /* 0x58: inherited state pointer (rw in Ctrl/InitActProc) */
    void   *unk_60;                    /* 0x60: read in InitActProc */
    uint8_t pad_68[0x80];             /* 0x68-0xE7 */
    void   *unk_E8;                    /* 0xE8: read in Ctrl */
    uint8_t pad_F0[0x118];            /* 0xF0-0x207 */
    int32_t flag_208;                  /* 0x208: init flag (rw in Ctrl/Init) */
    int32_t flag_20C;                  /* 0x20C: rw in Ctrl */
    int32_t flag_210;                  /* 0x210: rw in Ctrl */
    uint8_t pad_214[0x1EC];           /* 0x214-0x3FF */
    void   *unk_400;                   /* 0x400: read in MessageDispatcher */
    uint8_t pad_408[0x5F8];           /* 0x408-0x9FF */
    void   *demo_obj_A00;              /* 0xA00: demo object reference */
    uint8_t pad_A08[0x638];           /* 0xA08-0x103F */
    void   *unk_1040;                  /* 0x1040: read in InitActProc */
    uint8_t pad_1048[0x138];          /* 0x1048-0x117F */
    void   *unk_1180;                  /* 0x1180: read in Ctrl */
    uint8_t pad_1188[0x78];          /* 0x1188-0x11FF */
    void   *unk_1200;                  /* 0x1200: read in Ctrl */
} ccSkillHitDemoStartBase;
/* size unknown, >= 0x1208 */
_Static_assert(offsetof(ccSkillHitDemoStartBase, msg_id_C) == 0xC, "ccSkillHitDemoStartBase.msg_id_C");
_Static_assert(offsetof(ccSkillHitDemoStartBase, state_ptr_58) == 0x58, "ccSkillHitDemoStartBase.state_ptr_58");
_Static_assert(offsetof(ccSkillHitDemoStartBase, unk_60) == 0x60, "ccSkillHitDemoStartBase.unk_60");
_Static_assert(offsetof(ccSkillHitDemoStartBase, unk_E8) == 0xE8, "ccSkillHitDemoStartBase.unk_E8");
_Static_assert(offsetof(ccSkillHitDemoStartBase, flag_208) == 0x208, "ccSkillHitDemoStartBase.flag_208");
_Static_assert(offsetof(ccSkillHitDemoStartBase, flag_20C) == 0x20C, "ccSkillHitDemoStartBase.flag_20C");
_Static_assert(offsetof(ccSkillHitDemoStartBase, flag_210) == 0x210, "ccSkillHitDemoStartBase.flag_210");
_Static_assert(offsetof(ccSkillHitDemoStartBase, unk_400) == 0x400, "ccSkillHitDemoStartBase.unk_400");
_Static_assert(offsetof(ccSkillHitDemoStartBase, demo_obj_A00) == 0xA00, "ccSkillHitDemoStartBase.demo_obj_A00");
_Static_assert(offsetof(ccSkillHitDemoStartBase, unk_1040) == 0x1040, "ccSkillHitDemoStartBase.unk_1040");
_Static_assert(offsetof(ccSkillHitDemoStartBase, unk_1180) == 0x1180, "ccSkillHitDemoStartBase.unk_1180");
_Static_assert(offsetof(ccSkillHitDemoStartBase, unk_1200) == 0x1200, "ccSkillHitDemoStartBase.unk_1200");

/* ccSkillHitDemoEndBase — end sequence for hit demos (size unknown, >= 0xA08) */
typedef struct ccSkillHitDemoEndBase {
    uint8_t pad_00[0xA00];             /* 0x00-0x9FF: inherits from base */
    void   *demo_obj_A00;              /* 0xA00: demo object reference (read in Exit) */
} ccSkillHitDemoEndBase;
/* size unknown, >= 0xA08 */
_Static_assert(offsetof(ccSkillHitDemoEndBase, demo_obj_A00) == 0xA00, "ccSkillHitDemoEndBase.demo_obj_A00");

/* ccSkillHitDemoNoCutinBase — hit demo without cut-in variant (size unknown, >= 0xA08) */
typedef struct ccSkillHitDemoNoCutinBase {
    uint8_t pad_00[0xA00];             /* 0x00-0x9FF: inherits from base */
    void   *demo_obj_A00;              /* 0xA00: demo object reference (read in Exit) */
} ccSkillHitDemoNoCutinBase;
/* size unknown, >= 0xA08 */
_Static_assert(offsetof(ccSkillHitDemoNoCutinBase, demo_obj_A00) == 0xA00, "ccSkillHitDemoNoCutinBase.demo_obj_A00");

/* ccSkillHitDemoSousaiBase — clashing hit demo (size unknown, >= 0xA08) */
typedef struct ccSkillHitDemoSousaiBase {
    uint8_t pad_00[0x2C];              /* 0x00-0x2B */
    int32_t flag_2C;                   /* 0x2C: read in Ctrl */
    uint8_t pad_30[0xC];              /* 0x30-0x3B */
    int32_t flag_3C;                   /* 0x3C: read in Ctrl */
    uint8_t pad_40[0x18];             /* 0x40-0x57 */
    void   *state_ptr_58;              /* 0x58: inherited state pointer (rw in Ctrl) */
    uint8_t pad_60[0x88];             /* 0x60-0xE7 */
    void   *unk_E8;                    /* 0xE8: read in Ctrl */
    uint8_t pad_F0[0x118];            /* 0xF0-0x207 */
    void   *unk_208;                   /* 0x208: rw in Ctrl/MessageDispatcher */
    uint8_t pad_210[0x1F0];           /* 0x210-0x3FF */
    void   *unk_400;                   /* 0x400: read in MessageDispatcher */
    uint8_t pad_408[0x5F8];           /* 0x408-0x9FF */
    void   *demo_obj_A00;              /* 0xA00: demo object reference */
} ccSkillHitDemoSousaiBase;
/* size unknown, >= 0xA08 */
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, flag_2C) == 0x2C, "ccSkillHitDemoSousaiBase.flag_2C");
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, flag_3C) == 0x3C, "ccSkillHitDemoSousaiBase.flag_3C");
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, state_ptr_58) == 0x58, "ccSkillHitDemoSousaiBase.state_ptr_58");
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, unk_E8) == 0xE8, "ccSkillHitDemoSousaiBase.unk_E8");
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, unk_208) == 0x208, "ccSkillHitDemoSousaiBase.unk_208");
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, unk_400) == 0x400, "ccSkillHitDemoSousaiBase.unk_400");
_Static_assert(offsetof(ccSkillHitDemoSousaiBase, demo_obj_A00) == 0xA00, "ccSkillHitDemoSousaiBase.demo_obj_A00");

/* ccSkillKageManeHitDemo — Shadow Imitation secret technique hit demo (size unknown, >= 0xA08) */
typedef struct ccSkillKageManeHitDemo {
    uint8_t pad_00[0xA00];             /* 0x00-0x9FF: inherits from base */
    void   *demo_obj_A00;              /* 0xA00: demo object reference (read in Init) */
} ccSkillKageManeHitDemo;
/* size unknown, >= 0xA08 */
_Static_assert(offsetof(ccSkillKageManeHitDemo, demo_obj_A00) == 0xA00, "ccSkillKageManeHitDemo.demo_obj_A00");

#endif /* CC_BOSS_BATTLE_S1_H */