/*
 * s3Boss03.h — Storm 3 Full Burst HD (NSUNS3.exe, build s3) boss-battle structs
 * INFERRED from static analysis (state_surface + decompiled constructors).
 * Not CONFIRMED by runtime trace.
 *
 * Classes covered: ccBoss03Player (base), ccBoss0300Kyuubi, ccBoss0310Kyuubi,
 * ccBoss03SkillManager.
 * 550 total RVAs in namespace; all cached in the decompiler cache DB.
 */
#ifndef S3_BOSS03_H
#define S3_BOSS03_H

#include <stdint.h>
#include <stddef.h>

/* ========================================================================
 * ccBoss03Player — base class for boss-side player objects
 * Size: unknown standalone; embedded as base of ccBoss0300Kyuubi/ccBoss0310Kyuubi
 * Vtable: PTR_FUN_1408e1c48 (slot 0), PTR_LAB_1408e2aa0 (slot 300 / offset 0x960)
 * Constructor: ccBoss03Player::ccBoss03Player @ RVA 0x2A6450
 * ======================================================================== */
typedef struct ccBoss03Player {
    /* 0x0000 */ void *vtable;                          /* PTR_FUN_1408e1c48 */
    /* 0x0008 */ uint8_t pad_0008[0x0200 - 0x0008];
    /* 0x0200 */ int64_t finalize_ptr;                  /* rw, Finalize reads param_1[0x200] */
    /* 0x0208 */ uint8_t pad_0208[0x073C - 0x0208];
    /* 0x073C */ int32_t weak_point_id;                 /* w, CreateWeakPoint */
    /* 0x0740 */ uint8_t pad_0740[0xAFDC - 0x0740];
    /* 0xAFDC */ int32_t unk_AFDC;                      /* w, ctor = 0 */
    /* 0xAFE0 */ uint8_t pad_AFE0[0xB038 - 0xAFE0];
    /* 0xB038 */ int32_t unk_B038;                      /* w, ctor = -1 */
    /* 0xB03C */ int32_t unk_B03C;                      /* w, ctor = -1 */
    /* 0xB040 */ int32_t unk_B040;                      /* w, ctor = 0 */
    /* 0xB044 */ int32_t unk_B044;                      /* w, ctor = 1 */
    /* 0xB048 */ int32_t unk_B048;                      /* w, ctor = 0 */
    /* 0xB04C */ int32_t unk_B04C;                      /* w, ctor = 1 */
    /* 0xB050 */ int32_t unk_B050;                      /* w, ctor = 0 */
    /* 0xB054 */ int32_t flags_B054;                    /* w, bitfield */
    /* 0xB058 */ uint8_t pad_B058[0xB108 - 0xB058];
    /* 0xB108 */ int32_t unk_B108;                      /* w, ctor = -1 */
    /* 0xB10C */ int32_t unk_B10C;                      /* w, ctor = 0 */
    /* 0xB110 */ uint8_t pad_B110[0xB150 - 0xB110];
    /* 0xB150 */ int32_t unk_B150;                      /* w, ctor = 0 */
    /* 0xB154 */ uint8_t pad_B154[0xB194 - 0xB154];
    /* 0xB194 */ int32_t unk_B194;                      /* w, ctor = 0 */
    /* 0xB198 */ uint8_t pad_B198[0xB198 - 0xB198];     /* end of proven fields */
} ccBoss03Player;

_Static_assert(offsetof(ccBoss03Player, vtable) == 0x0000, "vtable");
_Static_assert(offsetof(ccBoss03Player, finalize_ptr) == 0x0200, "finalize_ptr");
_Static_assert(offsetof(ccBoss03Player, weak_point_id) == 0x073C, "weak_point_id");
_Static_assert(offsetof(ccBoss03Player, unk_AFDC) == 0xAFDC, "unk_AFDC");
_Static_assert(offsetof(ccBoss03Player, unk_B038) == 0xB038, "unk_B038");
_Static_assert(offsetof(ccBoss03Player, unk_B03C) == 0xB03C, "unk_B03C");
_Static_assert(offsetof(ccBoss03Player, unk_B040) == 0xB040, "unk_B040");
_Static_assert(offsetof(ccBoss03Player, unk_B044) == 0xB044, "unk_B044");
_Static_assert(offsetof(ccBoss03Player, unk_B048) == 0xB048, "unk_B048");
_Static_assert(offsetof(ccBoss03Player, unk_B04C) == 0xB04C, "unk_B04C");
_Static_assert(offsetof(ccBoss03Player, unk_B050) == 0xB050, "unk_B050");
_Static_assert(offsetof(ccBoss03Player, flags_B054) == 0xB054, "flags_B054");
_Static_assert(offsetof(ccBoss03Player, unk_B108) == 0xB108, "unk_B108");
_Static_assert(offsetof(ccBoss03Player, unk_B10C) == 0xB10C, "unk_B10C");
_Static_assert(offsetof(ccBoss03Player, unk_B150) == 0xB150, "unk_B150");
_Static_assert(offsetof(ccBoss03Player, unk_B194) == 0xB194, "unk_B194");

/* ========================================================================
 * ccBoss0300Kyuubi — Nine-Tails (Naruto) boss, battle 0300
 * Allocation size: 0xB320 (45856 bytes) via FUN_140683f70 in ccBoss0300::_Initialize
 * Vtable: PTR_FUN_1408dae88 (slot 0), PTR_LAB_1408dbce0 (slot 300 / offset 0x960)
 * Constructor: ccBoss0300Kyuubi::ccBoss0300Kyuubi @ RVA 0x28A7B0
 * Inherits: ccBoss03Player (ctor calls FUN_1402a6450 first)
 * ======================================================================== */
typedef struct ccBoss0300Kyuubi {
    /* 0x0000 */ void *vtable;                          /* PTR_FUN_1408dae88 */
    /* 0x0008 */ uint8_t pad_0008[0x09B0 - 0x0008];
    /* 0x09B0 */ int32_t init_flag_09B0;                /* w, Initialize sets */
    /* 0x09B4 */ uint8_t pad_09B4[0x8008 - 0x09B4];
    /* 0x8008 */ int64_t update_damage_ptr_8008;        /* r, UpdateDamage */
    /* 0x8010 */ int64_t update_damage_ptr_8010;        /* r, UpdateDamage */
    /* 0x8018 */ uint8_t pad_8018[0x8050 - 0x8018];
    /* 0x8050 */ int64_t update_damage_ptr_8050;        /* r, UpdateDamage */
    /* 0x8058 */ uint8_t pad_8058[0x807C - 0x8058];
    /* 0x807C */ int32_t update_damage_val_807C;        /* r, UpdateDamage */
    /* 0x8080 */ uint8_t pad_8080[0x80F8 - 0x8080];
    /* 0x80F8 */ int32_t update_damage_val_80F8;        /* r, UpdateDamage */
    /* 0x80FC */ uint8_t pad_80FC[0xABE0 - 0x80FC];
    /* 0xABE0 */ int64_t after_collision_ptr_ABE0;      /* r, AfterCollision */
    /* 0xABE8 */ uint8_t pad_ABE8[0xB050 - 0xABE8];
    /* 0xB050 */ int32_t ctor_val_B050;                 /* w, ctor */
    /* 0xB054 */ int32_t flags_B054;                    /* rw, Initialize */
    /* 0xB058 */ uint8_t pad_B058[0xB10C - 0xB058];
    /* 0xB10C */ int32_t after_collision_val_B10C;      /* r, AfterCollision */
    /* 0xB110 */ uint8_t pad_B110[0xB198 - 0xB110];
    /* 0xB198 */ int64_t init_ptr_B198;                 /* rw, Initialize */
    /* 0xB1A0 */ uint8_t pad_B1A0[0xB208 - 0xB1A0];
    /* 0xB208 */ int32_t init_val_B208;                 /* w, Initialize */
    /* 0xB20C */ uint8_t pad_B20C[0xB210 - 0xB20C];
    /* 0xB210 */ int64_t init_ptr_B210;                 /* rw, Initialize */
    /* 0xB218 */ int32_t ctor_val_B218;                 /* w, ctor */
    /* 0xB21C */ int32_t ctor_val_B21C;                 /* w, ctor = 0 */
    /* 0xB220 */ uint8_t pad_B220[0xB2D4 - 0xB220];
    /* 0xB2D4 */ int32_t ctor_val_B2D4;                 /* w, ctor = 0 */
    /* 0xB2D8 */ uint8_t pad_B2D8[0xB2E8 - 0xB2D8];
    /* 0xB2E8 */ int64_t list_head_B2E8;                /* rw, ctor = 0 */
    /* 0xB2F0 */ int64_t list_tail_B2F0;                /* w, ctor = 0 */
    /* 0xB2F8 */ int64_t list_end_B2F8;                 /* w, ctor = 0 */
    /* 0xB300 */ int64_t sub_obj_B300;                  /* rw, ctor */
    /* 0xB308 */ uint8_t pad_B308[0xB318 - 0xB308];
    /* 0xB318 */ int32_t ctor_float_B318;               /* w, ctor = -1.0f (0xBF800000) */
    /* 0xB31C */ uint8_t pad_B31C[0xB320 - 0xB31C];
} ccBoss0300Kyuubi;

_Static_assert(offsetof(ccBoss0300Kyuubi, vtable) == 0x0000, "vtable");
_Static_assert(offsetof(ccBoss0300Kyuubi, init_flag_09B0) == 0x09B0, "init_flag_09B0");
_Static_assert(offsetof(ccBoss0300Kyuubi, update_damage_ptr_8008) == 0x8008, "update_damage_ptr_8008");
_Static_assert(offsetof(ccBoss0300Kyuubi, update_damage_ptr_8010) == 0x8010, "update_damage_ptr_8010");
_Static_assert(offsetof(ccBoss0300Kyuubi, update_damage_ptr_8050) == 0x8050, "update_damage_ptr_8050");
_Static_assert(offsetof(ccBoss0300Kyuubi, update_damage_val_807C) == 0x807C, "update_damage_val_807C");
_Static_assert(offsetof(ccBoss0300Kyuubi, update_damage_val_80F8) == 0x80F8, "update_damage_val_80F8");
_Static_assert(offsetof(ccBoss0300Kyuubi, after_collision_ptr_ABE0) == 0xABE0, "after_collision_ptr_ABE0");
_Static_assert(offsetof(ccBoss0300Kyuubi, ctor_val_B050) == 0xB050, "ctor_val_B050");
_Static_assert(offsetof(ccBoss0300Kyuubi, flags_B054) == 0xB054, "flags_B054");
_Static_assert(offsetof(ccBoss0300Kyuubi, after_collision_val_B10C) == 0xB10C, "after_collision_val_B10C");
_Static_assert(offsetof(ccBoss0300Kyuubi, init_ptr_B198) == 0xB198, "init_ptr_B198");
_Static_assert(offsetof(ccBoss0300Kyuubi, init_val_B208) == 0xB208, "init_val_B208");
_Static_assert(offsetof(ccBoss0300Kyuubi, init_ptr_B210) == 0xB210, "init_ptr_B210");
_Static_assert(offsetof(ccBoss0300Kyuubi, ctor_val_B218) == 0xB218, "ctor_val_B218");
_Static_assert(offsetof(ccBoss0300Kyuubi, ctor_val_B21C) == 0xB21C, "ctor_val_B21C");
_Static_assert(offsetof(ccBoss0300Kyuubi, ctor_val_B2D4) == 0xB2D4, "ctor_val_B2D4");
_Static_assert(offsetof(ccBoss0300Kyuubi, list_head_B2E8) == 0xB2E8, "list_head_B2E8");
_Static_assert(offsetof(ccBoss0300Kyuubi, list_tail_B2F0) == 0xB2F0, "list_tail_B2F0");
_Static_assert(offsetof(ccBoss0300Kyuubi, list_end_B2F8) == 0xB2F8, "list_end_B2F8");
_Static_assert(offsetof(ccBoss0300Kyuubi, sub_obj_B300) == 0xB300, "sub_obj_B300");
_Static_assert(offsetof(ccBoss0300Kyuubi, ctor_float_B318) == 0xB318, "ctor_float_B318");
/* True allocation size is 0xB320 from FUN_140683f70(0xb320, ...) in ccBoss0300::_Initialize */

/* ========================================================================
 * ccBoss0310Kyuubi — Nine-Tails (Madara/Kushina) boss, battle 0310
 * Allocation size: 0xB310 (45840 bytes) via FUN_140683f70 in ccBoss0310::_Initialize
 * Vtable: PTR_FUN_1408def20 (slot 0), PTR_LAB_1408dfd78 (slot 300 / offset 0x960)
 * Constructor: ccBoss0310Kyuubi::ccBoss0310Kyuubi @ RVA 0x29BED4
 * Inherits: ccBoss03Player (ctor calls FUN_1402a6450 first)
 * ======================================================================== */
typedef struct ccBoss0310Kyuubi {
    /* 0x0000 */ void *vtable;                          /* PTR_FUN_1408def20 */
    /* 0x0008 */ uint8_t pad_0008[0x09B0 - 0x0008];
    /* 0x09B0 */ int32_t init_flag_09B0;                /* w, Initialize sets */
    /* 0x09B4 */ uint8_t pad_09B4[0x09DC - 0x09B4];
    /* 0x09DC */ int32_t collision_flag_09DC;           /* r, AfterCollision checks != 0 */
    /* 0x09E0 */ uint8_t pad_09E0[0x8008 - 0x09E0];
    /* 0x8008 */ int64_t update_damage_ptr_8008;        /* r, UpdateDamage */
    /* 0x8010 */ int64_t update_damage_ptr_8010;        /* r, UpdateDamage */
    /* 0x8018 */ uint8_t pad_8018[0x8050 - 0x8018];
    /* 0x8050 */ int64_t update_damage_ptr_8050;        /* r, UpdateDamage */
    /* 0x8058 */ uint8_t pad_8058[0x807C - 0x8058];
    /* 0x807C */ int32_t update_damage_val_807C;        /* r, UpdateDamage */
    /* 0x8080 */ uint8_t pad_8080[0x80F8 - 0x8080];
    /* 0x80F8 */ int32_t update_damage_val_80F8;        /* r, UpdateDamage */
    /* 0x80FC */ uint8_t pad_80FC[0xABE0 - 0x80FC];
    /* 0xABE0 */ int64_t after_collision_ptr_ABE0;      /* r, AfterCollision */
    /* 0xABE8 */ uint8_t pad_ABE8[0xB054 - 0xABE8];
    /* 0xB054 */ int32_t flags_B054;                    /* rw, Initialize */
    /* 0xB058 */ uint8_t pad_B058[0xB10C - 0xB058];
    /* 0xB10C */ int32_t after_collision_val_B10C;      /* r, AfterCollision */
    /* 0xB110 */ uint8_t pad_B110[0xB198 - 0xB110];
    /* 0xB198 */ int64_t init_ptr_B198;                 /* rw, Initialize */
    /* 0xB1A0 */ int64_t init_ptr_B1A0;                 /* rw, Initialize */
    /* 0xB1A8 */ int32_t ctor_val_B1A8;                 /* w, ctor */
    /* 0xB1AC */ int32_t ctor_val_B1AC;                 /* w, ctor = 0 */
    /* 0xB1B0 */ uint8_t pad_B1B0[0xB24C - 0xB1B0];
    /* 0xB24C */ int32_t ctor_val_B24C;                 /* w, ctor = 0 */
    /* 0xB250 */ int32_t update_float_B250;             /* rw, Update writes */
    /* 0xB254 */ uint8_t pad_B254[0xB260 - 0xB254];
    /* 0xB260 */ int64_t init_ptr_B260;                 /* rw, Initialize */
    /* 0xB268 */ int64_t init_ptr_B268;                 /* r, Initialize */
    /* 0xB270 */ uint8_t pad_B270[0xB2A0 - 0xB270];
    /* 0xB2A0 */ int32_t ctor_val_B2A0;                 /* w, ctor */
    /* 0xB2A4 */ uint8_t pad_B2A4[0xB308 - 0xB2A4];
    /* 0xB308 */ int32_t init_const_B308;               /* w, Initialize = 0x4E39 (20025) */
    /* 0xB30C */ uint8_t pad_B30C[0xB310 - 0xB30C];
} ccBoss0310Kyuubi;

_Static_assert(offsetof(ccBoss0310Kyuubi, vtable) == 0x0000, "vtable");
_Static_assert(offsetof(ccBoss0310Kyuubi, init_flag_09B0) == 0x09B0, "init_flag_09B0");
_Static_assert(offsetof(ccBoss0310Kyuubi, collision_flag_09DC) == 0x09DC, "collision_flag_09DC");
_Static_assert(offsetof(ccBoss0310Kyuubi, update_damage_ptr_8008) == 0x8008, "update_damage_ptr_8008");
_Static_assert(offsetof(ccBoss0310Kyuubi, update_damage_ptr_8010) == 0x8010, "update_damage_ptr_8010");
_Static_assert(offsetof(ccBoss0310Kyuubi, update_damage_ptr_8050) == 0x8050, "update_damage_ptr_8050");
_Static_assert(offsetof(ccBoss0310Kyuubi, update_damage_val_807C) == 0x807C, "update_damage_val_807C");
_Static_assert(offsetof(ccBoss0310Kyuubi, update_damage_val_80F8) == 0x80F8, "update_damage_val_80F8");
_Static_assert(offsetof(ccBoss0310Kyuubi, after_collision_ptr_ABE0) == 0xABE0, "after_collision_ptr_ABE0");
_Static_assert(offsetof(ccBoss0310Kyuubi, flags_B054) == 0xB054, "flags_B054");
_Static_assert(offsetof(ccBoss0310Kyuubi, after_collision_val_B10C) == 0xB10C, "after_collision_val_B10C");
_Static_assert(offsetof(ccBoss0310Kyuubi, init_ptr_B198) == 0xB198, "init_ptr_B198");
_Static_assert(offsetof(ccBoss0310Kyuubi, init_ptr_B1A0) == 0xB1A0, "init_ptr_B1A0");
_Static_assert(offsetof(ccBoss0310Kyuubi, ctor_val_B1A8) == 0xB1A8, "ctor_val_B1A8");
_Static_assert(offsetof(ccBoss0310Kyuubi, ctor_val_B1AC) == 0xB1AC, "ctor_val_B1AC");
_Static_assert(offsetof(ccBoss0310Kyuubi, ctor_val_B24C) == 0xB24C, "ctor_val_B24C");
_Static_assert(offsetof(ccBoss0310Kyuubi, update_float_B250) == 0xB250, "update_float_B250");
_Static_assert(offsetof(ccBoss0310Kyuubi, init_ptr_B260) == 0xB260, "init_ptr_B260");
_Static_assert(offsetof(ccBoss0310Kyuubi, init_ptr_B268) == 0xB268, "init_ptr_B268");
_Static_assert(offsetof(ccBoss0310Kyuubi, ctor_val_B2A0) == 0xB2A0, "ctor_val_B2A0");
_Static_assert(offsetof(ccBoss0310Kyuubi, init_const_B308) == 0xB308, "init_const_B308");
/* True allocation size: 0xB310 from FUN_140683f70(0xb310, ...) in ccBoss0310::_Initialize */

/* ========================================================================
 * ccBoss03SkillManager — skill/effect dispatch manager (singleton)
 * Allocation size: 0x108 (264 bytes) via FUN_140683f70 in CreateInstance
 * Vtable: PTR_FUN_1408e3ca0 (slot 0)
 * Constructor: ccBoss03SkillManager::ccBoss03SkillManager @ RVA 0x2A8E50
 * Global instance: DAT_140b9d2b0
 * ======================================================================== */
typedef struct ccBoss03SkillManager {
    /* 0x0000 */ void *vtable;                          /* PTR_FUN_1408e3ca0 */
    /* 0x0008 */ uint8_t pad_0008[0x0078 - 0x0008];
    /* 0x0078 */ int64_t owner_ptr;                     /* w, CreateInstance sets */
    /* 0x0080 */ int64_t list_begin;                    /* rw, RequestRemoveAll */
    /* 0x0088 */ int64_t list_end;                      /* rw, RequestRemoveAll */
    /* 0x0090 */ int64_t list_capacity;                 /* w, ctor = 0 */
    /* 0x0098 */ int64_t skill_container;               /* rw, RequestRemoveAll */
    /* 0x00A0 */ uint8_t pad_00A0[0x0108 - 0x00A0];
} ccBoss03SkillManager;

_Static_assert(sizeof(ccBoss03SkillManager) == 0x108, "ccBoss03SkillManager size == 0x108");
_Static_assert(offsetof(ccBoss03SkillManager, vtable) == 0x0000, "vtable");
_Static_assert(offsetof(ccBoss03SkillManager, owner_ptr) == 0x0078, "owner_ptr");
_Static_assert(offsetof(ccBoss03SkillManager, list_begin) == 0x0080, "list_begin");
_Static_assert(offsetof(ccBoss03SkillManager, list_end) == 0x0088, "list_end");
_Static_assert(offsetof(ccBoss03SkillManager, list_capacity) == 0x0090, "list_capacity");
_Static_assert(offsetof(ccBoss03SkillManager, skill_container) == 0x0098, "skill_container");


/* === Batch 1 coverage additions === */

/* ========================================================================
 * ccBoss0300KyuubiState
 * Size: unknown, >= 0xD4
 * Vtable: none found (state_surface only)
 * Fields: 17 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0300KyuubiState {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0300kyuubistat_0x0054;
    /* 0x0058 */ int64_t ccboss0300kyuubistat_0x0058;
    /* 0x0060 */ int32_t ccboss0300kyuubistat_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int64_t ccboss0300kyuubistat_0x0068;
    /* 0x0070 */ int64_t ccboss0300kyuubistat_0x0070;
    /* 0x0078 */ int32_t ccboss0300kyuubistat_0x0078;
    /* 0x007C */ uint8_t pad_007C[0x0080 - 0x007C];
    /* 0x0080 */ int64_t ccboss0300kyuubistat_0x0080;
    /* 0x0088 */ int64_t ccboss0300kyuubistat_0x0088;
    /* 0x0090 */ int64_t ccboss0300kyuubistat_0x0090;
    /* 0x0098 */ int64_t ccboss0300kyuubistat_0x0098;
    /* 0x00A0 */ int64_t ccboss0300kyuubistat_0x00A0;
    /* 0x00A8 */ int64_t ccboss0300kyuubistat_0x00A8;
    /* 0x00B0 */ int64_t ccboss0300kyuubistat_0x00B0;
    /* 0x00B8 */ int64_t ccboss0300kyuubistat_0x00B8;
    /* 0x00C0 */ int64_t ccboss0300kyuubistat_0x00C0;
    /* 0x00C8 */ int64_t ccboss0300kyuubistat_0x00C8;
    /* 0x00D0 */ int32_t ccboss0300kyuubistat_0x00D0;
} ccBoss0300KyuubiState;

_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0054) == 0x0054, "ccboss0300kyuubistat_0x0054");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0058) == 0x0058, "ccboss0300kyuubistat_0x0058");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0060) == 0x0060, "ccboss0300kyuubistat_0x0060");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0068) == 0x0068, "ccboss0300kyuubistat_0x0068");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0070) == 0x0070, "ccboss0300kyuubistat_0x0070");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0078) == 0x0078, "ccboss0300kyuubistat_0x0078");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0080) == 0x0080, "ccboss0300kyuubistat_0x0080");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0088) == 0x0088, "ccboss0300kyuubistat_0x0088");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0090) == 0x0090, "ccboss0300kyuubistat_0x0090");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x0098) == 0x0098, "ccboss0300kyuubistat_0x0098");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00A0) == 0x00A0, "ccboss0300kyuubistat_0x00A0");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00A8) == 0x00A8, "ccboss0300kyuubistat_0x00A8");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00B0) == 0x00B0, "ccboss0300kyuubistat_0x00B0");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00B8) == 0x00B8, "ccboss0300kyuubistat_0x00B8");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00C0) == 0x00C0, "ccboss0300kyuubistat_0x00C0");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00C8) == 0x00C8, "ccboss0300kyuubistat_0x00C8");
_Static_assert(offsetof(ccBoss0300KyuubiState, ccboss0300kyuubistat_0x00D0) == 0x00D0, "ccboss0300kyuubistat_0x00D0");
/* Size unknown, >= 0xD4 — no allocation site found */

/* ========================================================================
 * ccBoss0310: no instance state
 * state_surface returned 0 data fields across all seed methods.
 * All methods are dispatch/pure-virtual or operate on other objects.
 * ======================================================================== */

/* ========================================================================
 * ccBoss0310KyuubiTail00
 * Size: unknown, >= 0x2CC
 * Vtable: none found (state_surface only)
 * Fields: 13 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0310KyuubiTail00 {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0310kyuubitail_0x0054;
    /* 0x0058 */ int64_t ccboss0310kyuubitail_0x0058;
    /* 0x0060 */ int32_t ccboss0310kyuubitail_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int64_t ccboss0310kyuubitail_0x0068;
    /* 0x0070 */ int64_t ccboss0310kyuubitail_0x0070;
    /* 0x0078 */ int64_t ccboss0310kyuubitail_0x0078;
    /* 0x0080 */ int64_t ccboss0310kyuubitail_0x0080;
    /* 0x0088 */ int64_t ccboss0310kyuubitail_0x0088;
    /* 0x0090 */ int32_t ccboss0310kyuubitail_0x0090;
    /* 0x0094 */ uint8_t pad_0094[0x00F8 - 0x0094];
    /* 0x00F8 */ int32_t ccboss0310kyuubitail_0x00F8;
    /* 0x00FC */ int64_t ccboss0310kyuubitail_0x00FC;
    /* 0x0104 */ int64_t ccboss0310kyuubitail_0x0104;
    /* 0x010C */ uint8_t pad_010C[0x02C8 - 0x010C];
    /* 0x02C8 */ int32_t ccboss0310kyuubitail_0x02C8;
} ccBoss0310KyuubiTail00;

_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0054) == 0x0054, "ccboss0310kyuubitail_0x0054");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0058) == 0x0058, "ccboss0310kyuubitail_0x0058");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0060) == 0x0060, "ccboss0310kyuubitail_0x0060");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0068) == 0x0068, "ccboss0310kyuubitail_0x0068");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0070) == 0x0070, "ccboss0310kyuubitail_0x0070");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0078) == 0x0078, "ccboss0310kyuubitail_0x0078");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0080) == 0x0080, "ccboss0310kyuubitail_0x0080");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0088) == 0x0088, "ccboss0310kyuubitail_0x0088");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0090) == 0x0090, "ccboss0310kyuubitail_0x0090");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x00F8) == 0x00F8, "ccboss0310kyuubitail_0x00F8");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x00FC) == 0x00FC, "ccboss0310kyuubitail_0x00FC");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x0104) == 0x0104, "ccboss0310kyuubitail_0x0104");
_Static_assert(offsetof(ccBoss0310KyuubiTail00, ccboss0310kyuubitail_0x02C8) == 0x02C8, "ccboss0310kyuubitail_0x02C8");
/* Size unknown, >= 0x2CC — no allocation site found */

/* ========================================================================
 * ccBoss0310KyuubiState
 * Size: unknown, >= 0xE8
 * Vtable: none found (state_surface only)
 * Fields: 20 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0310KyuubiState {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0310kyuubistat_0x0054;
    /* 0x0058 */ int64_t ccboss0310kyuubistat_0x0058;
    /* 0x0060 */ int32_t ccboss0310kyuubistat_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int64_t field_rw_0x0068;
    /* 0x0070 */ int64_t ccboss0310kyuubistat_0x0070;
    /* 0x0078 */ int64_t ccboss0310kyuubistat_0x0078;
    /* 0x0080 */ int32_t field_rw_0x0080;
    /* 0x0084 */ uint8_t pad_0084[0x0088 - 0x0084];
    /* 0x0088 */ int64_t ccboss0310kyuubistat_0x0088;
    /* 0x0090 */ int64_t ccboss0310kyuubistat_0x0090;
    /* 0x0098 */ void* requestactioncancel_0x0098;
    /* 0x00A0 */ int64_t ccboss0310kyuubistat_0x00A0;
    /* 0x00A8 */ int64_t ccboss0310kyuubistat_0x00A8;
    /* 0x00B0 */ int64_t ccboss0310kyuubistat_0x00B0;
    /* 0x00B8 */ int64_t ccboss0310kyuubistat_0x00B8;
    /* 0x00C0 */ int64_t ccboss0310kyuubistat_0x00C0;
    /* 0x00C8 */ int64_t ccboss0310kyuubistat_0x00C8;
    /* 0x00D0 */ int64_t ccboss0310kyuubistat_0x00D0;
    /* 0x00D8 */ int32_t ccboss0310kyuubistat_0x00D8;
    /* 0x00DC */ int64_t ccboss0310kyuubistat_0x00DC;
    /* 0x00E4 */ int32_t ccboss0310kyuubistat_0x00E4;
} ccBoss0310KyuubiState;

_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0054) == 0x0054, "ccboss0310kyuubistat_0x0054");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0058) == 0x0058, "ccboss0310kyuubistat_0x0058");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0060) == 0x0060, "ccboss0310kyuubistat_0x0060");
_Static_assert(offsetof(ccBoss0310KyuubiState, field_rw_0x0068) == 0x0068, "field_rw_0x0068");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0070) == 0x0070, "ccboss0310kyuubistat_0x0070");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0078) == 0x0078, "ccboss0310kyuubistat_0x0078");
_Static_assert(offsetof(ccBoss0310KyuubiState, field_rw_0x0080) == 0x0080, "field_rw_0x0080");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0088) == 0x0088, "ccboss0310kyuubistat_0x0088");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x0090) == 0x0090, "ccboss0310kyuubistat_0x0090");
_Static_assert(offsetof(ccBoss0310KyuubiState, requestactioncancel_0x0098) == 0x0098, "requestactioncancel_0x0098");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00A0) == 0x00A0, "ccboss0310kyuubistat_0x00A0");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00A8) == 0x00A8, "ccboss0310kyuubistat_0x00A8");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00B0) == 0x00B0, "ccboss0310kyuubistat_0x00B0");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00B8) == 0x00B8, "ccboss0310kyuubistat_0x00B8");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00C0) == 0x00C0, "ccboss0310kyuubistat_0x00C0");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00C8) == 0x00C8, "ccboss0310kyuubistat_0x00C8");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00D0) == 0x00D0, "ccboss0310kyuubistat_0x00D0");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00D8) == 0x00D8, "ccboss0310kyuubistat_0x00D8");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00DC) == 0x00DC, "ccboss0310kyuubistat_0x00DC");
_Static_assert(offsetof(ccBoss0310KyuubiState, ccboss0310kyuubistat_0x00E4) == 0x00E4, "ccboss0310kyuubistat_0x00E4");
/* Size unknown, >= 0xE8 — no allocation site found */

/* ========================================================================
 * ccBoss0310EventState
 * Size: unknown, >= 0x90
 * Vtable: none found (state_surface only)
 * Fields: 10 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0310EventState {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0310eventstate_0x0054;
    /* 0x0058 */ int32_t ccboss0310eventstate_0x0058;
    /* 0x005C */ int32_t ccboss0310eventstate_0x005C;
    /* 0x0060 */ int32_t ccboss0310eventstate_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int32_t ccboss0310eventstate_0x0068;
    /* 0x006C */ int32_t ccboss0310eventstate_0x006C;
    /* 0x0070 */ int64_t ccboss0310eventstate_0x0070;
    /* 0x0078 */ uint8_t pad_0078[0x0084 - 0x0078];
    /* 0x0084 */ int32_t ccboss0310eventstate_0x0084;
    /* 0x0088 */ int32_t ccboss0310eventstate_0x0088;
    /* 0x008C */ int32_t ccboss0310eventstate_0x008C;
} ccBoss0310EventState;

_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0054) == 0x0054, "ccboss0310eventstate_0x0054");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0058) == 0x0058, "ccboss0310eventstate_0x0058");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x005C) == 0x005C, "ccboss0310eventstate_0x005C");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0060) == 0x0060, "ccboss0310eventstate_0x0060");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0068) == 0x0068, "ccboss0310eventstate_0x0068");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x006C) == 0x006C, "ccboss0310eventstate_0x006C");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0070) == 0x0070, "ccboss0310eventstate_0x0070");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0084) == 0x0084, "ccboss0310eventstate_0x0084");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x0088) == 0x0088, "ccboss0310eventstate_0x0088");
_Static_assert(offsetof(ccBoss0310EventState, ccboss0310eventstate_0x008C) == 0x008C, "ccboss0310eventstate_0x008C");
/* Size unknown, >= 0x90 — no allocation site found */

/* ========================================================================
 * ccBoss0310KyuubiBeam
 * Size: unknown, >= 0x20C
 * Vtable: none found (state_surface only)
 * Fields: 8 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0310KyuubiBeam {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0310kyuubibeam_0x0054;
    /* 0x0058 */ int32_t ccboss0310kyuubibeam_0x0058;
    /* 0x005C */ int32_t ccboss0310kyuubibeam_0x005C;
    /* 0x0060 */ int32_t ccboss0310kyuubibeam_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int32_t ccboss0310kyuubibeam_0x0068;
    /* 0x006C */ int32_t ccboss0310kyuubibeam_0x006C;
    /* 0x0070 */ uint8_t pad_0070[0x00D8 - 0x0070];
    /* 0x00D8 */ int32_t ccboss0310kyuubibeam_0x00D8;
    /* 0x00DC */ uint8_t pad_00DC[0x0208 - 0x00DC];
    /* 0x0208 */ int32_t ccboss0310kyuubibeam_0x0208;
} ccBoss0310KyuubiBeam;

_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x0054) == 0x0054, "ccboss0310kyuubibeam_0x0054");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x0058) == 0x0058, "ccboss0310kyuubibeam_0x0058");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x005C) == 0x005C, "ccboss0310kyuubibeam_0x005C");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x0060) == 0x0060, "ccboss0310kyuubibeam_0x0060");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x0068) == 0x0068, "ccboss0310kyuubibeam_0x0068");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x006C) == 0x006C, "ccboss0310kyuubibeam_0x006C");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x00D8) == 0x00D8, "ccboss0310kyuubibeam_0x00D8");
_Static_assert(offsetof(ccBoss0310KyuubiBeam, ccboss0310kyuubibeam_0x0208) == 0x0208, "ccboss0310kyuubibeam_0x0208");
/* Size unknown, >= 0x20C — no allocation site found */

/* ========================================================================
 * ccBoss0300: no instance state
 * state_surface returned 0 data fields across all seed methods.
 * All methods are dispatch/pure-virtual or operate on other objects.
 * ======================================================================== */

/* ========================================================================
 * ccBoss0300KybActRush
 * Size: unknown, >= 0x1E0
 * Vtable: none found (state_surface only)
 * Fields: 15 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0300KybActRush {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0300kybactrush_0x0054;
    /* 0x0058 */ int32_t ccboss0300kybactrush_0x0058;
    /* 0x005C */ int32_t ccboss0300kybactrush_0x005C;
    /* 0x0060 */ int32_t ccboss0300kybactrush_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int32_t ccboss0300kybactrush_0x0068;
    /* 0x006C */ int32_t ccboss0300kybactrush_0x006C;
    /* 0x0070 */ int32_t ccboss0300kybactrush_0x0070;
    /* 0x0074 */ int32_t ccboss0300kybactrush_0x0074;
    /* 0x0078 */ int32_t ccboss0300kybactrush_0x0078;
    /* 0x007C */ int32_t ccboss0300kybactrush_0x007C;
    /* 0x0080 */ int32_t ccboss0300kybactrush_0x0080;
    /* 0x0084 */ uint8_t pad_0084[0x0088 - 0x0084];
    /* 0x0088 */ int64_t field_rw_0x0088;
    /* 0x0090 */ void* ccboss0300kybactrush_0x0090;
    /* 0x0098 */ uint8_t pad_0098[0x01C8 - 0x0098];
    /* 0x01C8 */ void* ccboss0300kybactrush_0x01C8;
    /* 0x01D0 */ uint8_t pad_01D0[0x01DC - 0x01D0];
    /* 0x01DC */ int32_t ccboss0300kybactrush_0x01DC;
} ccBoss0300KybActRush;

_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0054) == 0x0054, "ccboss0300kybactrush_0x0054");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0058) == 0x0058, "ccboss0300kybactrush_0x0058");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x005C) == 0x005C, "ccboss0300kybactrush_0x005C");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0060) == 0x0060, "ccboss0300kybactrush_0x0060");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0068) == 0x0068, "ccboss0300kybactrush_0x0068");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x006C) == 0x006C, "ccboss0300kybactrush_0x006C");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0070) == 0x0070, "ccboss0300kybactrush_0x0070");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0074) == 0x0074, "ccboss0300kybactrush_0x0074");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0078) == 0x0078, "ccboss0300kybactrush_0x0078");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x007C) == 0x007C, "ccboss0300kybactrush_0x007C");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0080) == 0x0080, "ccboss0300kybactrush_0x0080");
_Static_assert(offsetof(ccBoss0300KybActRush, field_rw_0x0088) == 0x0088, "field_rw_0x0088");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x0090) == 0x0090, "ccboss0300kybactrush_0x0090");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x01C8) == 0x01C8, "ccboss0300kybactrush_0x01C8");
_Static_assert(offsetof(ccBoss0300KybActRush, ccboss0300kybactrush_0x01DC) == 0x01DC, "ccboss0300kybactrush_0x01DC");
/* Size unknown, >= 0x1E0 — no allocation site found */

/* ========================================================================
 * ccBoss0310KyuubiTail01
 * Size: unknown, >= 0x17C
 * Vtable: none found (state_surface only)
 * Fields: 12 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0310KyuubiTail01 {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0310kyuubitail_0x0054;
    /* 0x0058 */ int64_t ccboss0310kyuubitail_0x0058;
    /* 0x0060 */ int32_t ccboss0310kyuubitail_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int64_t ccboss0310kyuubitail_0x0068;
    /* 0x0070 */ int64_t ccboss0310kyuubitail_0x0070;
    /* 0x0078 */ uint8_t pad_0078[0x009C - 0x0078];
    /* 0x009C */ int32_t ccboss0310kyuubitail_0x009C;
    /* 0x00A0 */ uint8_t pad_00A0[0x00F8 - 0x00A0];
    /* 0x00F8 */ int64_t ccboss0310kyuubitail_0x00F8;
    /* 0x0100 */ int64_t ccboss0310kyuubitail_0x0100;
    /* 0x0108 */ uint8_t pad_0108[0x0114 - 0x0108];
    /* 0x0114 */ int64_t ccboss0310kyuubitail_0x0114;
    /* 0x011C */ int64_t ccboss0310kyuubitail_0x011C;
    /* 0x0124 */ int32_t ccboss0310kyuubitail_0x0124;
    /* 0x0128 */ uint8_t pad_0128[0x0178 - 0x0128];
    /* 0x0178 */ int32_t ccboss0310kyuubitail_0x0178;
} ccBoss0310KyuubiTail01;

_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0054) == 0x0054, "ccboss0310kyuubitail_0x0054");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0058) == 0x0058, "ccboss0310kyuubitail_0x0058");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0060) == 0x0060, "ccboss0310kyuubitail_0x0060");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0068) == 0x0068, "ccboss0310kyuubitail_0x0068");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0070) == 0x0070, "ccboss0310kyuubitail_0x0070");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x009C) == 0x009C, "ccboss0310kyuubitail_0x009C");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x00F8) == 0x00F8, "ccboss0310kyuubitail_0x00F8");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0100) == 0x0100, "ccboss0310kyuubitail_0x0100");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0114) == 0x0114, "ccboss0310kyuubitail_0x0114");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x011C) == 0x011C, "ccboss0310kyuubitail_0x011C");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0124) == 0x0124, "ccboss0310kyuubitail_0x0124");
_Static_assert(offsetof(ccBoss0310KyuubiTail01, ccboss0310kyuubitail_0x0178) == 0x0178, "ccboss0310kyuubitail_0x0178");
/* Size unknown, >= 0x17C — no allocation site found */

/* ========================================================================
 * ccBoss0300KybActRun: no instance state
 * state_surface returned 0 data fields across all seed methods.
 * All methods are dispatch/pure-virtual or operate on other objects.
 * ======================================================================== */

/* ========================================================================
 * ccBoss03EffectManager: no instance state
 * state_surface returned 0 data fields across all seed methods.
 * All methods are dispatch/pure-virtual or operate on other objects.
 * ======================================================================== */

/* ========================================================================
 * ccBoss0300SupportState
 * Size: unknown, >= 0x16C
 * Vtable: none found (state_surface only)
 * Fields: 13 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0300SupportState {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ int32_t ccboss0300supportsta_0x0054;
    /* 0x0058 */ int64_t ccboss0300supportsta_0x0058;
    /* 0x0060 */ int32_t ccboss0300supportsta_0x0060;
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ int64_t ccboss0300supportsta_0x0068;
    /* 0x0070 */ int64_t ccboss0300supportsta_0x0070;
    /* 0x0078 */ int64_t ccboss0300supportsta_0x0078;
    /* 0x0080 */ int64_t ccboss0300supportsta_0x0080;
    /* 0x0088 */ uint8_t pad_0088[0x00B0 - 0x0088];
    /* 0x00B0 */ int32_t ccboss0300supportsta_0x00B0;
    /* 0x00B4 */ int32_t ccboss0300supportsta_0x00B4;
    /* 0x00B8 */ uint8_t pad_00B8[0x00C4 - 0x00B8];
    /* 0x00C4 */ int32_t ccboss0300supportsta_0x00C4;
    /* 0x00C8 */ uint8_t pad_00C8[0x0120 - 0x00C8];
    /* 0x0120 */ int32_t ccboss0300supportsta_0x0120;
    /* 0x0124 */ int32_t ccboss0300supportsta_0x0124;
    /* 0x0128 */ uint8_t pad_0128[0x0168 - 0x0128];
    /* 0x0168 */ int32_t ccboss0300supportsta_0x0168;
} ccBoss0300SupportState;

_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0054) == 0x0054, "ccboss0300supportsta_0x0054");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0058) == 0x0058, "ccboss0300supportsta_0x0058");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0060) == 0x0060, "ccboss0300supportsta_0x0060");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0068) == 0x0068, "ccboss0300supportsta_0x0068");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0070) == 0x0070, "ccboss0300supportsta_0x0070");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0078) == 0x0078, "ccboss0300supportsta_0x0078");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0080) == 0x0080, "ccboss0300supportsta_0x0080");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x00B0) == 0x00B0, "ccboss0300supportsta_0x00B0");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x00B4) == 0x00B4, "ccboss0300supportsta_0x00B4");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x00C4) == 0x00C4, "ccboss0300supportsta_0x00C4");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0120) == 0x0120, "ccboss0300supportsta_0x0120");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0124) == 0x0124, "ccboss0300supportsta_0x0124");
_Static_assert(offsetof(ccBoss0300SupportState, ccboss0300supportsta_0x0168) == 0x0168, "ccboss0300supportsta_0x0168");
/* Size unknown, >= 0x16C — no allocation site found */

/* ========================================================================
 * ccBoss03Effect
 * Size: unknown, >= 0x90
 * Vtable: none found (state_surface only)
 * Fields: 2 proven data accesses
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss03Effect {
    /* 0x0000 */ uint8_t pad_0000[0x0088 - 0x0000];
    /* 0x0088 */ int32_t ccboss03effect_0x0088;           /* w, = 0xffffffff */
    /* 0x008C */ int32_t ccboss03effect_0x008C;           /* w, = 0 */
} ccBoss03Effect;

_Static_assert(offsetof(ccBoss03Effect, ccboss03effect_0x0088) == 0x0088, "ccboss03effect_0x0088");
_Static_assert(offsetof(ccBoss03Effect, ccboss03effect_0x008C) == 0x008C, "ccboss03effect_0x008C");
/* Size unknown, >= 0x90 — no allocation site found */

/* ========================================================================
 * ccBoss0310SkillSlash
 * Size: unknown, >= 0x16C
 * Vtable: none found (state_surface only)
 * Fields: 8 proven data accesses (high+medium confidence writes)
 * INFERRED from static analysis; not CONFIRMED by runtime trace.
 * ======================================================================== */
typedef struct __attribute__((packed)) ccBoss0310SkillSlash {
    /* 0x0000 */ uint8_t pad_0000[0x0090 - 0x0000];
    /* 0x0090 */ int64_t ccboss0310skillslash_0x0090;     /* w, = param_2 */
    /* 0x0098 */ int64_t ccboss0310skillslash_0x0098;     /* rw, ptr check */
    /* 0x00A0 */ int64_t ccboss0310skillslash_0x00A0;     /* w, = *param_3 */
    /* 0x00A8 */ int32_t ccboss0310skillslash_0x00A8;     /* w, = param_3[1] */
    /* 0x00AC */ uint8_t pad_00AC[0x00B4 - 0x00AC];
    /* 0x00B4 */ int32_t ccboss0310skillslash_0x00B4;     /* w, = *(param_4+1) */
    /* 0x00B8 */ uint8_t pad_00B8[0x0120 - 0x00B8];
    /* 0x0120 */ int32_t ccboss0310skillslash_0x0120;     /* w, = 0x42c80000 (100.0f) */
    /* 0x0124 */ int32_t ccboss0310skillslash_0x0124;     /* w, = 0x42700000 (60.0f) */
    /* 0x0128 */ uint8_t pad_0128[0x0168 - 0x0128];
    /* 0x0168 */ int32_t ccboss0310skillslash_0x0168;     /* w, = 0 */
} ccBoss0310SkillSlash;

_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x0090) == 0x0090, "ccboss0310skillslash_0x0090");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x0098) == 0x0098, "ccboss0310skillslash_0x0098");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x00A0) == 0x00A0, "ccboss0310skillslash_0x00A0");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x00A8) == 0x00A8, "ccboss0310skillslash_0x00A8");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x00B4) == 0x00B4, "ccboss0310skillslash_0x00B4");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x0120) == 0x0120, "ccboss0310skillslash_0x0120");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x0124) == 0x0124, "ccboss0310skillslash_0x0124");
_Static_assert(offsetof(ccBoss0310SkillSlash, ccboss0310skillslash_0x0168) == 0x0168, "ccboss0310skillslash_0x0168");
/* Size unknown, >= 0x16C — no allocation site found */

/* ========================================================================
 * ccBoss0310Chain: insufficient instance state
 * state_surface returned only 1 low-confidence read (vfunc dispatch at +0x24).
 * No struct generated; needs more seed methods or runtime trace.
 * ======================================================================== */

/* ========================================================================
 * ccBoss0310SupportKSNState: no instance state
 * state_surface returned 0 data fields across all seed methods.
 * All methods are dispatch/pure-virtual or operate on other objects.
 * ======================================================================== */

/* --- ccBoss0300KybActCombo (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ uint32_t ccboss0300kybactcombo_0x0054;  /* w, conf=medium */
    /* 0x0058 */ uint64_t ccboss0300kybactcombo_0x0058;  /* w, conf=medium */
    /* 0x0060 */ uint32_t ccboss0300kybactcombo_0x0060;  /* w, conf=medium */
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ uint64_t ccboss0300kybactcombo_0x0068;  /* w, conf=medium */
    /* 0x0070 */ uint64_t ccboss0300kybactcombo_0x0070;  /* w, conf=medium */
    /* 0x0078 */ uint64_t ccboss0300kybactcombo_0x0078;  /* w, conf=medium */
    /* 0x0080 */ uint64_t ccboss0300kybactcombo_0x0080;  /* w, conf=medium */
    /* 0x0088 */ uint64_t ccboss0300kybactcombo_0x0088;  /* rw, conf=low */
    /* 0x0090 */ uint64_t ccboss0300kybactcombo_0x0090;  /* w, conf=medium */
    /* 0x0098 */ uint8_t pad_0098[0x01C8 - 0x0098];
    /* 0x01C8 */ uint64_t ccboss0300kybactcombo_0x01C8;  /* w, conf=medium */
    /* 0x01D0 */ uint8_t pad_01d0[0x01DC - 0x01D0];
    /* 0x01DC */ uint32_t ccboss0300kybactcombo_0x01DC;  /* w, conf=medium */
    /* 0x01E0 */ uint8_t pad_01e0[0x01F0 - 0x01E0];
    /* 0x01F0 */ uint32_t ccboss0300kybactcombo_0x01F0;  /* w, conf=medium */
} ccBoss0300KybActCombo;

_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0054) == 0x0054, "ccboss0300kybactcombo_0x0054");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0058) == 0x0058, "ccboss0300kybactcombo_0x0058");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0060) == 0x0060, "ccboss0300kybactcombo_0x0060");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0068) == 0x0068, "ccboss0300kybactcombo_0x0068");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0070) == 0x0070, "ccboss0300kybactcombo_0x0070");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0078) == 0x0078, "ccboss0300kybactcombo_0x0078");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0080) == 0x0080, "ccboss0300kybactcombo_0x0080");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0088) == 0x0088, "ccboss0300kybactcombo_0x0088");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x0090) == 0x0090, "ccboss0300kybactcombo_0x0090");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x01C8) == 0x01C8, "ccboss0300kybactcombo_0x01C8");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x01DC) == 0x01DC, "ccboss0300kybactcombo_0x01DC");
_Static_assert(offsetof(ccBoss0300KybActCombo, ccboss0300kybactcombo_0x01F0) == 0x01F0, "ccboss0300kybactcombo_0x01F0");
/* Size unknown, >= 0x1F4 — no allocation site found */


/* ========================================================================
 * ccBoss0300SequenceState: no instance state
 * state_surface returned 0 data fields across 10 seed methods.
 * All methods are dispatch/pure-virtual or operate on other objects.
 * ======================================================================== */

/* --- ccBoss0310EventTrigger (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x002C - 0x0000];
    /* 0x002C */ uint32_t ccboss0310eventtrigger_0x002C; /* w, conf=medium */
    /* 0x0030 */ uint8_t pad_0030[0x0044 - 0x0030];
    /* 0x0044 */ uint32_t ccboss0310eventtrigger_0x0044; /* w, conf=medium */
} ccBoss0310EventTrigger;

_Static_assert(offsetof(ccBoss0310EventTrigger, ccboss0310eventtrigger_0x002C) == 0x002C, "ccboss0310eventtrigger_0x002C");
_Static_assert(offsetof(ccBoss0310EventTrigger, ccboss0310eventtrigger_0x0044) == 0x0044, "ccboss0310eventtrigger_0x0044");
/* Size unknown, >= 0x48 — no allocation site found */


/* --- ccBoss0310KybActGroundCrash (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ uint32_t ccboss0310kybactgroundcrash_0x0054; /* w, conf=medium */
    /* 0x0058 */ uint64_t ccboss0310kybactgroundcrash_0x0058; /* w, conf=medium */
    /* 0x0060 */ uint32_t ccboss0310kybactgroundcrash_0x0060; /* w, conf=medium */
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ uint64_t ccboss0310kybactgroundcrash_0x0068; /* w, conf=medium */
    /* 0x0070 */ uint32_t ccboss0310kybactgroundcrash_0x0070; /* w, conf=medium */
    /* 0x0074 */ uint32_t ccboss0310kybactgroundcrash_0x0074; /* w, conf=medium */
} ccBoss0310KybActGroundCrash;

_Static_assert(offsetof(ccBoss0310KybActGroundCrash, ccboss0310kybactgroundcrash_0x0054) == 0x0054, "ccboss0310kybactgroundcrash_0x0054");
_Static_assert(offsetof(ccBoss0310KybActGroundCrash, ccboss0310kybactgroundcrash_0x0058) == 0x0058, "ccboss0310kybactgroundcrash_0x0058");
_Static_assert(offsetof(ccBoss0310KybActGroundCrash, ccboss0310kybactgroundcrash_0x0060) == 0x0060, "ccboss0310kybactgroundcrash_0x0060");
_Static_assert(offsetof(ccBoss0310KybActGroundCrash, ccboss0310kybactgroundcrash_0x0068) == 0x0068, "ccboss0310kybactgroundcrash_0x0068");
_Static_assert(offsetof(ccBoss0310KybActGroundCrash, ccboss0310kybactgroundcrash_0x0070) == 0x0070, "ccboss0310kybactgroundcrash_0x0070");
_Static_assert(offsetof(ccBoss0310KybActGroundCrash, ccboss0310kybactgroundcrash_0x0074) == 0x0074, "ccboss0310kybactgroundcrash_0x0074");
/* Size unknown, >= 0x78 — no allocation site found */


/* --- ccBoss0310KybActTailThrust (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ uint32_t ccboss0310kybacttailthrust_0x0054; /* w, conf=medium */
    /* 0x0058 */ uint64_t ccboss0310kybacttailthrust_0x0058; /* w, conf=medium */
    /* 0x0060 */ uint32_t ccboss0310kybacttailthrust_0x0060; /* w, conf=medium */
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ uint64_t ccboss0310kybacttailthrust_0x0068; /* w, conf=medium */
    /* 0x0070 */ uint8_t pad_0070[0x00B8 - 0x0070];
    /* 0x00B8 */ uint64_t ccboss0310kybacttailthrust_0x00B8; /* w, conf=medium */
    /* 0x00C0 */ uint32_t ccboss0310kybacttailthrust_0x00C0; /* w, conf=medium */
} ccBoss0310KybActTailThrust;

_Static_assert(offsetof(ccBoss0310KybActTailThrust, ccboss0310kybacttailthrust_0x0054) == 0x0054, "ccboss0310kybacttailthrust_0x0054");
_Static_assert(offsetof(ccBoss0310KybActTailThrust, ccboss0310kybacttailthrust_0x0058) == 0x0058, "ccboss0310kybacttailthrust_0x0058");
_Static_assert(offsetof(ccBoss0310KybActTailThrust, ccboss0310kybacttailthrust_0x0060) == 0x0060, "ccboss0310kybacttailthrust_0x0060");
_Static_assert(offsetof(ccBoss0310KybActTailThrust, ccboss0310kybacttailthrust_0x0068) == 0x0068, "ccboss0310kybacttailthrust_0x0068");
_Static_assert(offsetof(ccBoss0310KybActTailThrust, ccboss0310kybacttailthrust_0x00B8) == 0x00B8, "ccboss0310kybacttailthrust_0x00B8");
_Static_assert(offsetof(ccBoss0310KybActTailThrust, ccboss0310kybacttailthrust_0x00C0) == 0x00C0, "ccboss0310kybacttailthrust_0x00C0");
/* Size unknown, >= 0xC4 — no allocation site found */


/* --- ccBoss03PlayerLeaderNRX (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x09EC - 0x0000];
    /* 0x09EC */ uint32_t ccboss03playerleadernrx_0x09EC; /* r, conf=medium */
    /* 0x09F0 */ uint8_t pad_09f0[0x09F4 - 0x09F0];
    /* 0x09F4 */ uint32_t ccboss03playerleadernrx_0x09F4; /* r, conf=medium */
    /* 0x09F8 */ uint8_t pad_09f8[0x8050 - 0x09F8];
    /* 0x8050 */ uint64_t ccboss03playerleadernrx_0x8050; /* r, conf=medium */
    /* 0x8058 */ uint8_t pad_8058[0x80A0 - 0x8058];
    /* 0x80A0 */ uint64_t ccboss03playerleadernrx_0x80A0; /* r, conf=medium */
    /* 0x80A8 */ uint8_t pad_80a8[0x825C - 0x80A8];
    /* 0x825C */ uint32_t ccboss03playerleadernrx_0x825C; /* r, conf=medium */
    /* 0x8260 */ uint8_t pad_8260[0xA314 - 0x8260];
    /* 0xA314 */ uint32_t ccboss03playerleadernrx_0xA314; /* r, conf=medium */
    /* 0xA318 */ uint8_t pad_a318[0xABE0 - 0xA318];
    /* 0xABE0 */ uint64_t ccboss03playerleadernrx_0xABE0; /* r, conf=medium */
    /* 0xABE8 */ uint8_t pad_abe8[0xAEA0 - 0xABE8];
    /* 0xAEA0 */ uint32_t ccboss03playerleadernrx_0xAEA0; /* r, conf=medium */
    /* 0xAEA4 */ uint8_t pad_aea4[0xAFB8 - 0xAEA4];
    /* 0xAFB8 */ uint32_t ccboss03playerleadernrx_0xAFB8; /* w, conf=medium */
    /* 0xAFBC */ uint32_t ccboss03playerleadernrx_0xAFBC; /* w, conf=medium */
} ccBoss03PlayerLeaderNRX;

_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0x09EC) == 0x09EC, "ccboss03playerleadernrx_0x09EC");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0x09F4) == 0x09F4, "ccboss03playerleadernrx_0x09F4");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0x8050) == 0x8050, "ccboss03playerleadernrx_0x8050");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0x80A0) == 0x80A0, "ccboss03playerleadernrx_0x80A0");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0x825C) == 0x825C, "ccboss03playerleadernrx_0x825C");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0xA314) == 0xA314, "ccboss03playerleadernrx_0xA314");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0xABE0) == 0xABE0, "ccboss03playerleadernrx_0xABE0");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0xAEA0) == 0xAEA0, "ccboss03playerleadernrx_0xAEA0");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0xAFB8) == 0xAFB8, "ccboss03playerleadernrx_0xAFB8");
_Static_assert(offsetof(ccBoss03PlayerLeaderNRX, ccboss03playerleadernrx_0xAFBC) == 0xAFBC, "ccboss03playerleadernrx_0xAFBC");
/* Size unknown, >= 0xAFC0 — no allocation site found */


/* --- ccBoss0300KyuubiCpuState (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ uint32_t ccboss0300kyuubicpustate_0x0054; /* w, conf=medium */
    /* 0x0058 */ uint64_t ccboss0300kyuubicpustate_0x0058; /* w, conf=medium */
    /* 0x0060 */ uint32_t ccboss0300kyuubicpustate_0x0060; /* w, conf=medium */
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ uint64_t ccboss0300kyuubicpustate_0x0068; /* w, conf=medium */
    /* 0x0070 */ uint64_t ccboss0300kyuubicpustate_0x0070; /* w, conf=medium */
    /* 0x0078 */ uint64_t ccboss0300kyuubicpustate_0x0078; /* w, conf=medium */
    /* 0x0080 */ uint32_t ccboss0300kyuubicpustate_0x0080; /* w, conf=medium */
    /* 0x0084 */ uint32_t ccboss0300kyuubicpustate_0x0084; /* w, conf=medium */
    /* 0x0088 */ uint32_t ccboss0300kyuubicpustate_0x0088; /* w, conf=medium */
    /* 0x008C */ uint64_t ccboss0300kyuubicpustate_0x008C; /* w, conf=medium */
    /* 0x0094 */ uint64_t ccboss0300kyuubicpustate_0x0094; /* w, conf=medium */
    /* 0x009C */ uint64_t ccboss0300kyuubicpustate_0x009C; /* w, conf=medium */
    /* 0x00A4 */ uint8_t pad_00a4[0x00A8 - 0x00A4];
    /* 0x00A8 */ uint64_t ccboss0300kyuubicpustate_0x00A8; /* w, conf=medium */
    /* 0x00B0 */ uint32_t ccboss0300kyuubicpustate_0x00B0; /* w, conf=medium */
    /* 0x00B4 */ uint64_t ccboss0300kyuubicpustate_0x00B4; /* w, conf=medium */
} ccBoss0300KyuubiCpuState;

_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0054) == 0x0054, "ccboss0300kyuubicpustate_0x0054");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0058) == 0x0058, "ccboss0300kyuubicpustate_0x0058");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0060) == 0x0060, "ccboss0300kyuubicpustate_0x0060");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0068) == 0x0068, "ccboss0300kyuubicpustate_0x0068");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0070) == 0x0070, "ccboss0300kyuubicpustate_0x0070");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0078) == 0x0078, "ccboss0300kyuubicpustate_0x0078");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0080) == 0x0080, "ccboss0300kyuubicpustate_0x0080");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0084) == 0x0084, "ccboss0300kyuubicpustate_0x0084");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0088) == 0x0088, "ccboss0300kyuubicpustate_0x0088");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x008C) == 0x008C, "ccboss0300kyuubicpustate_0x008C");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x0094) == 0x0094, "ccboss0300kyuubicpustate_0x0094");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x009C) == 0x009C, "ccboss0300kyuubicpustate_0x009C");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x00A8) == 0x00A8, "ccboss0300kyuubicpustate_0x00A8");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x00B0) == 0x00B0, "ccboss0300kyuubicpustate_0x00B0");
_Static_assert(offsetof(ccBoss0300KyuubiCpuState, ccboss0300kyuubicpustate_0x00B4) == 0x00B4, "ccboss0300kyuubicpustate_0x00B4");
/* Size unknown, >= 0xBC — no allocation site found */


/* --- ccBoss0300SkillBijuShot10 (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0090 - 0x0000];
    /* 0x0090 */ uint64_t ccboss0300skillbijushot10_0x0090; /* w, conf=medium */
    /* 0x0098 */ uint64_t ccboss0300skillbijushot10_0x0098; /* rw, conf=high */
    /* 0x00A0 */ uint64_t ccboss0300skillbijushot10_0x00A0; /* rw, conf=low */
    /* 0x00A8 */ uint32_t ccboss0300skillbijushot10_0x00A8; /* rw, conf=high */
    /* 0x00AC */ uint64_t ccboss0300skillbijushot10_0x00AC; /* rw, conf=low */
    /* 0x00B4 */ uint32_t ccboss0300skillbijushot10_0x00B4; /* w, conf=medium */
    /* 0x00B8 */ uint64_t ccboss0300skillbijushot10_0x00B8; /* rw, conf=low */
    /* 0x00C0 */ uint32_t ccboss0300skillbijushot10_0x00C0; /* w, conf=medium */
    /* 0x00C4 */ uint8_t pad_00c4[0x0120 - 0x00C4];
    /* 0x0120 */ uint32_t ccboss0300skillbijushot10_0x0120; /* rw, conf=high */
    /* 0x0124 */ uint32_t ccboss0300skillbijushot10_0x0124; /* rw, conf=high */
    /* 0x0128 */ uint32_t ccboss0300skillbijushot10_0x0128; /* rw, conf=high */
    /* 0x012C */ uint8_t pad_012c[0x0130 - 0x012C];
    /* 0x0130 */ uint32_t ccboss0300skillbijushot10_0x0130; /* w, conf=high */
    /* 0x0134 */ uint8_t pad_0134[0x0138 - 0x0134];
    /* 0x0138 */ uint64_t ccboss0300skillbijushot10_0x0138; /* rw, conf=high */
    /* 0x0140 */ uint64_t ccboss0300skillbijushot10_0x0140; /* rw, conf=low */
    /* 0x0148 */ uint32_t ccboss0300skillbijushot10_0x0148; /* w, conf=high */
    /* 0x014C */ uint32_t ccboss0300skillbijushot10_0x014C; /* rw, conf=low */
    /* 0x0150 */ uint32_t ccboss0300skillbijushot10_0x0150; /* rw, conf=high */
    /* 0x0154 */ uint64_t ccboss0300skillbijushot10_0x0154; /* w, conf=medium */
    /* 0x015C */ uint32_t ccboss0300skillbijushot10_0x015C; /* rw, conf=high */
    /* 0x0160 */ uint64_t ccboss0300skillbijushot10_0x0160; /* rw, conf=low */
    /* 0x0168 */ uint64_t ccboss0300skillbijushot10_0x0168; /* w, conf=medium */
    /* 0x0170 */ uint8_t pad_0170[0x02A0 - 0x0170];
    /* 0x02A0 */ uint64_t ccboss0300skillbijushot10_0x02A0; /* w, conf=medium */
    /* 0x02A8 */ uint8_t pad_02a8[0x02B4 - 0x02A8];
    /* 0x02B4 */ uint32_t ccboss0300skillbijushot10_0x02B4; /* w, conf=medium */
    /* 0x02B8 */ uint8_t pad_02b8[0x02C8 - 0x02B8];
    /* 0x02C8 */ uint64_t ccboss0300skillbijushot10_0x02C8; /* w, conf=low */
    /* 0x02D0 */ uint32_t ccboss0300skillbijushot10_0x02D0; /* rw, conf=high */
} ccBoss0300SkillBijuShot10;

_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0090) == 0x0090, "ccboss0300skillbijushot10_0x0090");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0098) == 0x0098, "ccboss0300skillbijushot10_0x0098");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x00A0) == 0x00A0, "ccboss0300skillbijushot10_0x00A0");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x00A8) == 0x00A8, "ccboss0300skillbijushot10_0x00A8");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x00AC) == 0x00AC, "ccboss0300skillbijushot10_0x00AC");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x00B4) == 0x00B4, "ccboss0300skillbijushot10_0x00B4");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x00B8) == 0x00B8, "ccboss0300skillbijushot10_0x00B8");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x00C0) == 0x00C0, "ccboss0300skillbijushot10_0x00C0");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0120) == 0x0120, "ccboss0300skillbijushot10_0x0120");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0124) == 0x0124, "ccboss0300skillbijushot10_0x0124");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0128) == 0x0128, "ccboss0300skillbijushot10_0x0128");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0130) == 0x0130, "ccboss0300skillbijushot10_0x0130");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0138) == 0x0138, "ccboss0300skillbijushot10_0x0138");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0140) == 0x0140, "ccboss0300skillbijushot10_0x0140");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0148) == 0x0148, "ccboss0300skillbijushot10_0x0148");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x014C) == 0x014C, "ccboss0300skillbijushot10_0x014C");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0150) == 0x0150, "ccboss0300skillbijushot10_0x0150");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0154) == 0x0154, "ccboss0300skillbijushot10_0x0154");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x015C) == 0x015C, "ccboss0300skillbijushot10_0x015C");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0160) == 0x0160, "ccboss0300skillbijushot10_0x0160");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x0168) == 0x0168, "ccboss0300skillbijushot10_0x0168");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x02A0) == 0x02A0, "ccboss0300skillbijushot10_0x02A0");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x02B4) == 0x02B4, "ccboss0300skillbijushot10_0x02B4");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x02C8) == 0x02C8, "ccboss0300skillbijushot10_0x02C8");
_Static_assert(offsetof(ccBoss0300SkillBijuShot10, ccboss0300skillbijushot10_0x02D0) == 0x02D0, "ccboss0300skillbijushot10_0x02D0");
/* Size unknown, >= 0x2D4 — no allocation site found */


/* --- ccBoss0310KybActBeam (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ uint32_t ccboss0310kybactbeam_0x0054;   /* w, conf=medium */
    /* 0x0058 */ uint32_t ccboss0310kybactbeam_0x0058;   /* w, conf=medium */
    /* 0x005C */ uint32_t ccboss0310kybactbeam_0x005C;   /* w, conf=medium */
    /* 0x0060 */ uint32_t ccboss0310kybactbeam_0x0060;   /* w, conf=medium */
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ uint32_t ccboss0310kybactbeam_0x0068;   /* w, conf=medium */
    /* 0x006C */ uint32_t ccboss0310kybactbeam_0x006C;   /* w, conf=medium */
    /* 0x0070 */ uint32_t ccboss0310kybactbeam_0x0070;   /* w, conf=medium */
    /* 0x0074 */ uint32_t ccboss0310kybactbeam_0x0074;   /* w, conf=medium */
    /* 0x0078 */ uint64_t ccboss0310kybactbeam_0x0078;   /* w, conf=medium */
    /* 0x0080 */ uint8_t pad_0080[0x008C - 0x0080];
    /* 0x008C */ uint32_t ccboss0310kybactbeam_0x008C;   /* w, conf=medium */
    /* 0x0090 */ uint32_t ccboss0310kybactbeam_0x0090;   /* w, conf=medium */
    /* 0x0094 */ uint32_t ccboss0310kybactbeam_0x0094;   /* w, conf=medium */
    /* 0x0098 */ uint32_t ccboss0310kybactbeam_0x0098;   /* w, conf=medium */
} ccBoss0310KybActBeam;

_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0054) == 0x0054, "ccboss0310kybactbeam_0x0054");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0058) == 0x0058, "ccboss0310kybactbeam_0x0058");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x005C) == 0x005C, "ccboss0310kybactbeam_0x005C");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0060) == 0x0060, "ccboss0310kybactbeam_0x0060");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0068) == 0x0068, "ccboss0310kybactbeam_0x0068");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x006C) == 0x006C, "ccboss0310kybactbeam_0x006C");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0070) == 0x0070, "ccboss0310kybactbeam_0x0070");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0074) == 0x0074, "ccboss0310kybactbeam_0x0074");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0078) == 0x0078, "ccboss0310kybactbeam_0x0078");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x008C) == 0x008C, "ccboss0310kybactbeam_0x008C");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0090) == 0x0090, "ccboss0310kybactbeam_0x0090");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0094) == 0x0094, "ccboss0310kybactbeam_0x0094");
_Static_assert(offsetof(ccBoss0310KybActBeam, ccboss0310kybactbeam_0x0098) == 0x0098, "ccboss0310kybactbeam_0x0098");
/* Size unknown, >= 0x9C — no allocation site found */


/* --- ccBoss0310KybActTailCrash (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0054 - 0x0000];
    /* 0x0054 */ uint32_t ccboss0310kybacttailcrash_0x0054; /* w, conf=medium */
    /* 0x0058 */ uint64_t ccboss0310kybacttailcrash_0x0058; /* w, conf=medium */
    /* 0x0060 */ uint32_t ccboss0310kybacttailcrash_0x0060; /* w, conf=medium */
    /* 0x0064 */ uint8_t pad_0064[0x0068 - 0x0064];
    /* 0x0068 */ uint64_t ccboss0310kybacttailcrash_0x0068; /* w, conf=medium */
    /* 0x0070 */ uint8_t pad_0070[0x00B8 - 0x0070];
    /* 0x00B8 */ uint32_t ccboss0310kybacttailcrash_0x00B8; /* w, conf=medium */
} ccBoss0310KybActTailCrash;

_Static_assert(offsetof(ccBoss0310KybActTailCrash, ccboss0310kybacttailcrash_0x0054) == 0x0054, "ccboss0310kybacttailcrash_0x0054");
_Static_assert(offsetof(ccBoss0310KybActTailCrash, ccboss0310kybacttailcrash_0x0058) == 0x0058, "ccboss0310kybacttailcrash_0x0058");
_Static_assert(offsetof(ccBoss0310KybActTailCrash, ccboss0310kybacttailcrash_0x0060) == 0x0060, "ccboss0310kybacttailcrash_0x0060");
_Static_assert(offsetof(ccBoss0310KybActTailCrash, ccboss0310kybacttailcrash_0x0068) == 0x0068, "ccboss0310kybacttailcrash_0x0068");
_Static_assert(offsetof(ccBoss0310KybActTailCrash, ccboss0310kybacttailcrash_0x00B8) == 0x00B8, "ccboss0310kybacttailcrash_0x00B8");
/* Size unknown, >= 0xBC — no allocation site found */


/* --- ccBoss03SkillBijuShot00 (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0098 - 0x0000];
    /* 0x0098 */ uint64_t ccboss03skillbijushot00_0x0098; /* r, conf=medium */
    /* 0x00A0 */ uint8_t pad_00a0[0x00A8 - 0x00A0];
    /* 0x00A8 */ uint32_t ccboss03skillbijushot00_0x00A8; /* r, conf=medium */
    /* 0x00AC */ uint8_t pad_00ac[0x00B8 - 0x00AC];
    /* 0x00B8 */ uint64_t ccboss03skillbijushot00_0x00B8; /* rw, conf=low */
    /* 0x00C0 */ uint32_t ccboss03skillbijushot00_0x00C0; /* w, conf=medium */
    /* 0x00C4 */ uint8_t pad_00c4[0x0120 - 0x00C4];
    /* 0x0120 */ uint32_t ccboss03skillbijushot00_0x0120; /* rw, conf=high */
    /* 0x0124 */ uint32_t ccboss03skillbijushot00_0x0124; /* rw, conf=high */
    /* 0x0128 */ uint32_t ccboss03skillbijushot00_0x0128; /* rw, conf=medium */
    /* 0x012C */ uint8_t pad_012c[0x0130 - 0x012C];
    /* 0x0130 */ uint64_t ccboss03skillbijushot00_0x0130; /* rw, conf=low */
    /* 0x0138 */ uint64_t ccboss03skillbijushot00_0x0138; /* w, conf=medium */
    /* 0x0140 */ uint8_t pad_0140[0x0270 - 0x0140];
    /* 0x0270 */ uint64_t ccboss03skillbijushot00_0x0270; /* w, conf=medium */
    /* 0x0278 */ uint8_t pad_0278[0x0284 - 0x0278];
    /* 0x0284 */ uint32_t ccboss03skillbijushot00_0x0284; /* w, conf=medium */
    /* 0x0288 */ uint8_t pad_0288[0x0298 - 0x0288];
    /* 0x0298 */ uint32_t ccboss03skillbijushot00_0x0298; /* w, conf=medium */
    /* 0x029C */ uint8_t pad_029c[0x02A0 - 0x029C];
    /* 0x02A0 */ uint64_t ccboss03skillbijushot00_0x02A0; /* rw, conf=high */
    /* 0x02A8 */ uint64_t ccboss03skillbijushot00_0x02A8; /* rw, conf=high */
    /* 0x02B0 */ uint32_t ccboss03skillbijushot00_0x02B0; /* rw, conf=high */
    /* 0x02B4 */ uint32_t ccboss03skillbijushot00_0x02B4; /* rw, conf=high */
    /* 0x02B8 */ uint32_t ccboss03skillbijushot00_0x02B8; /* rw, conf=high */
} ccBoss03SkillBijuShot00;

_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0098) == 0x0098, "ccboss03skillbijushot00_0x0098");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x00A8) == 0x00A8, "ccboss03skillbijushot00_0x00A8");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x00B8) == 0x00B8, "ccboss03skillbijushot00_0x00B8");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x00C0) == 0x00C0, "ccboss03skillbijushot00_0x00C0");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0120) == 0x0120, "ccboss03skillbijushot00_0x0120");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0124) == 0x0124, "ccboss03skillbijushot00_0x0124");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0128) == 0x0128, "ccboss03skillbijushot00_0x0128");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0130) == 0x0130, "ccboss03skillbijushot00_0x0130");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0138) == 0x0138, "ccboss03skillbijushot00_0x0138");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0270) == 0x0270, "ccboss03skillbijushot00_0x0270");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0284) == 0x0284, "ccboss03skillbijushot00_0x0284");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x0298) == 0x0298, "ccboss03skillbijushot00_0x0298");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x02A0) == 0x02A0, "ccboss03skillbijushot00_0x02A0");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x02A8) == 0x02A8, "ccboss03skillbijushot00_0x02A8");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x02B0) == 0x02B0, "ccboss03skillbijushot00_0x02B0");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x02B4) == 0x02B4, "ccboss03skillbijushot00_0x02B4");
_Static_assert(offsetof(ccBoss03SkillBijuShot00, ccboss03skillbijushot00_0x02B8) == 0x02B8, "ccboss03skillbijushot00_0x02B8");
/* Size unknown, >= 0x2BC — no allocation site found */


/* --- ccUiBoss03PlayerGauge (batch 3) --- */
typedef struct __attribute__((packed)) {
    /* 0x0000 */ uint8_t pad_0000[0x0030 - 0x0000];
    /* 0x0030 */ uint32_t ccuiboss03playergauge_0x0030;  /* w, conf=high */
    /* 0x0034 */ uint32_t ccuiboss03playergauge_0x0034;  /* w, conf=medium */
    /* 0x0038 */ uint32_t ccuiboss03playergauge_0x0038;  /* w, conf=medium */
    /* 0x003C */ uint32_t ccuiboss03playergauge_0x003C;  /* w, conf=medium */
    /* 0x0040 */ uint64_t ccuiboss03playergauge_0x0040;  /* rw, conf=high */
    /* 0x0048 */ uint8_t pad_0048[0x0090 - 0x0048];
    /* 0x0090 */ uint32_t ccuiboss03playergauge_0x0090;  /* w, conf=medium */
    /* 0x0094 */ uint32_t ccuiboss03playergauge_0x0094;  /* w, conf=medium */
    /* 0x0098 */ uint8_t pad_0098[0x01F0 - 0x0098];
    /* 0x01F0 */ uint32_t ccuiboss03playergauge_0x01F0;  /* w, conf=medium */
    /* 0x01F4 */ uint8_t pad_01f4[0x0218 - 0x01F4];
    /* 0x0218 */ uint64_t ccuiboss03playergauge_0x0218;  /* w, conf=medium */
} ccUiBoss03PlayerGauge;

_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0030) == 0x0030, "ccuiboss03playergauge_0x0030");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0034) == 0x0034, "ccuiboss03playergauge_0x0034");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0038) == 0x0038, "ccuiboss03playergauge_0x0038");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x003C) == 0x003C, "ccuiboss03playergauge_0x003C");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0040) == 0x0040, "ccuiboss03playergauge_0x0040");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0090) == 0x0090, "ccuiboss03playergauge_0x0090");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0094) == 0x0094, "ccuiboss03playergauge_0x0094");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x01F0) == 0x01F0, "ccuiboss03playergauge_0x01F0");
_Static_assert(offsetof(ccUiBoss03PlayerGauge, ccuiboss03playergauge_0x0218) == 0x0218, "ccuiboss03playergauge_0x0218");
/* Size unknown, >= 0x220 — no allocation site found */


/* ccBoss0300KyuubiDmgReaction — unknown, >= 0x64 — INFERRED from state_surface */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0000[20];
    uint32_t ccboss0300kyuubidmgreaction_0x0014;
    uint8_t _pad_0018[36];
    uint32_t ccboss0300kyuubidmgreaction_0x003C;
    uint8_t _pad_0040[28];
    uint64_t ccboss0300kyuubidmgreaction_0x005C;
} ccBoss0300KyuubiDmgReaction;
_Static_assert(offsetof(ccBoss0300KyuubiDmgReaction, ccboss0300kyuubidmgreaction_0x0014) == 0x14, "ccBoss0300KyuubiDmgReaction.ccboss0300kyuubidmgreaction_0x0014");
_Static_assert(offsetof(ccBoss0300KyuubiDmgReaction, ccboss0300kyuubidmgreaction_0x003C) == 0x3c, "ccBoss0300KyuubiDmgReaction.ccboss0300kyuubidmgreaction_0x003C");
_Static_assert(offsetof(ccBoss0300KyuubiDmgReaction, ccboss0300kyuubidmgreaction_0x005C) == 0x5c, "ccBoss0300KyuubiDmgReaction.ccboss0300kyuubidmgreaction_0x005C");

/* ccBoss0300SupportKRB — unknown, >= 0xAFCC — INFERRED from state_surface */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0000[2516];
    uint32_t ccboss0300supportkrb_0x09D4;
    uint8_t _pad_09D8[42464];
    uint64_t ccboss0300supportkrb_0xAFB8;
    uint32_t ccboss0300supportkrb_0xAFC0;
    uint32_t ccboss0300supportkrb_0xAFC4;
    uint32_t ccboss0300supportkrb_0xAFC8;
} ccBoss0300SupportKRB;
_Static_assert(offsetof(ccBoss0300SupportKRB, ccboss0300supportkrb_0x09D4) == 0x9d4, "ccBoss0300SupportKRB.ccboss0300supportkrb_0x09D4");
_Static_assert(offsetof(ccBoss0300SupportKRB, ccboss0300supportkrb_0xAFB8) == 0xafb8, "ccBoss0300SupportKRB.ccboss0300supportkrb_0xAFB8");
_Static_assert(offsetof(ccBoss0300SupportKRB, ccboss0300supportkrb_0xAFC0) == 0xafc0, "ccBoss0300SupportKRB.ccboss0300supportkrb_0xAFC0");
_Static_assert(offsetof(ccBoss0300SupportKRB, ccboss0300supportkrb_0xAFC4) == 0xafc4, "ccBoss0300SupportKRB.ccboss0300supportkrb_0xAFC4");
_Static_assert(offsetof(ccBoss0300SupportKRB, ccboss0300supportkrb_0xAFC8) == 0xafc8, "ccBoss0300SupportKRB.ccboss0300supportkrb_0xAFC8");

/* ccBoss0310SequenceState: no instance state found by state_surface — header-only placeholder */

/* ccBoss0300KybActJump: no instance state found by state_surface — header-only placeholder */

/* ccBoss0300KybActStepMove — unknown, >= 0x7C — INFERRED from state_surface */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0000[84];
    uint32_t ccboss0300kybactstepmove_0x0054;
    uint64_t ccboss0300kybactstepmove_0x0058;
    uint32_t ccboss0300kybactstepmove_0x0060;
    uint8_t _pad_0064[4];
    uint64_t ccboss0300kybactstepmove_0x0068;
    uint64_t ccboss0300kybactstepmove_0x0070;
    uint32_t ccboss0300kybactstepmove_0x0078;
} ccBoss0300KybActStepMove;
_Static_assert(offsetof(ccBoss0300KybActStepMove, ccboss0300kybactstepmove_0x0054) == 0x54, "ccBoss0300KybActStepMove.ccboss0300kybactstepmove_0x0054");
_Static_assert(offsetof(ccBoss0300KybActStepMove, ccboss0300kybactstepmove_0x0058) == 0x58, "ccBoss0300KybActStepMove.ccboss0300kybactstepmove_0x0058");
_Static_assert(offsetof(ccBoss0300KybActStepMove, ccboss0300kybactstepmove_0x0060) == 0x60, "ccBoss0300KybActStepMove.ccboss0300kybactstepmove_0x0060");
_Static_assert(offsetof(ccBoss0300KybActStepMove, ccboss0300kybactstepmove_0x0068) == 0x68, "ccBoss0300KybActStepMove.ccboss0300kybactstepmove_0x0068");
_Static_assert(offsetof(ccBoss0300KybActStepMove, ccboss0300kybactstepmove_0x0070) == 0x70, "ccBoss0300KybActStepMove.ccboss0300kybactstepmove_0x0070");
_Static_assert(offsetof(ccBoss0300KybActStepMove, ccboss0300kybactstepmove_0x0078) == 0x78, "ccBoss0300KybActStepMove.ccboss0300kybactstepmove_0x0078");

/* ccBoss0310KybActArmSwing: no instance state found by state_surface — header-only placeholder */

/* ccBoss0310KybActDown: no instance state found by state_surface — header-only placeholder */

/* ccBoss03BijuShot00ActState — unknown, >= 0x84 — INFERRED from state_surface */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0000[84];
    uint32_t ccboss03bijushot00actstate_0x0054;
    uint64_t ccboss03bijushot00actstate_0x0058;
    uint32_t ccboss03bijushot00actstate_0x0060;
    uint8_t _pad_0064[4];
    uint64_t ccboss03bijushot00actstate_0x0068;
    uint64_t ccboss03bijushot00actstate_0x0070;
    uint32_t ccboss03bijushot00actstate_0x0078;
    uint32_t ccboss03bijushot00actstate_0x007C;
    uint32_t ccboss03bijushot00actstate_0x0080;
} ccBoss03BijuShot00ActState;
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0054) == 0x54, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0054");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0058) == 0x58, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0058");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0060) == 0x60, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0060");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0068) == 0x68, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0068");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0070) == 0x70, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0070");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0078) == 0x78, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0078");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x007C) == 0x7c, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x007C");
_Static_assert(offsetof(ccBoss03BijuShot00ActState, ccboss03bijushot00actstate_0x0080) == 0x80, "ccBoss03BijuShot00ActState.ccboss03bijushot00actstate_0x0080");

/* ccBoss0310KyuubiCpuState: no instance state found by state_surface — header-only placeholder */

/* ccBoss0310KyuubiDmgReaction — unknown, >= 0x38 — INFERRED from state_surface */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0000[20];
    uint32_t ccboss0310kyuubidmgreaction_0x0014;
    uint8_t _pad_0018[4];
    uint64_t ccboss0310kyuubidmgreaction_0x001C;
    uint32_t ccboss0310kyuubidmgreaction_0x0024;
    uint8_t _pad_0028[12];
    uint32_t ccboss0310kyuubidmgreaction_0x0034;
} ccBoss0310KyuubiDmgReaction;
_Static_assert(offsetof(ccBoss0310KyuubiDmgReaction, ccboss0310kyuubidmgreaction_0x0014) == 0x14, "ccBoss0310KyuubiDmgReaction.ccboss0310kyuubidmgreaction_0x0014");
_Static_assert(offsetof(ccBoss0310KyuubiDmgReaction, ccboss0310kyuubidmgreaction_0x001C) == 0x1c, "ccBoss0310KyuubiDmgReaction.ccboss0310kyuubidmgreaction_0x001C");
_Static_assert(offsetof(ccBoss0310KyuubiDmgReaction, ccboss0310kyuubidmgreaction_0x0024) == 0x24, "ccBoss0310KyuubiDmgReaction.ccboss0310kyuubidmgreaction_0x0024");
_Static_assert(offsetof(ccBoss0310KyuubiDmgReaction, ccboss0310kyuubidmgreaction_0x0034) == 0x34, "ccBoss0310KyuubiDmgReaction.ccboss0310kyuubidmgreaction_0x0034");

/* ccSceneBoss0310: no instance state found by state_surface — header-only placeholder */

/* ccBoss0310ChainManager: no instance state found by state_surface — header-only placeholder */


/* ================================================================ */
/* Batch 5 Coverage Classes                                        */
/* ================================================================ */

/* ccBoss0310DoubleNRX: 8 data fields from state_surface (INFERRED) */
/* Size: unknown, >= 0xDC */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x000[84]; /* 0x000..0x053 */
    uint32_t field_0x54; /* 0x054 sz=4 w conf=medium */
    uint64_t field_0x58; /* 0x058 sz=8 w conf=medium */
    uint32_t field_0x60; /* 0x060 sz=4 w conf=medium */
    uint8_t _pad_0x064[4]; /* 0x064..0x067 */
    uint64_t field_0x68; /* 0x068 sz=8 w conf=medium */
    uint8_t _pad_0x070[40]; /* 0x070..0x097 */
    uint32_t field_0x98; /* 0x098 sz=4 r conf=low */
    uint8_t _pad_0x09C[36]; /* 0x09C..0x0BF */
    uint32_t field_0xC0; /* 0x0C0 sz=4 r conf=low */
    uint8_t _pad_0x0C4[16]; /* 0x0C4..0x0D3 */
    uint32_t field_0xD4; /* 0x0D4 sz=4 w conf=medium */
    uint32_t field_0xD8; /* 0x0D8 sz=4 w conf=medium */
} ns3_ccBoss0310DoubleNRX;

_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0x54) == 0x054, "ccBoss0310DoubleNRX::field_0x54");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0x58) == 0x058, "ccBoss0310DoubleNRX::field_0x58");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0x60) == 0x060, "ccBoss0310DoubleNRX::field_0x60");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0x68) == 0x068, "ccBoss0310DoubleNRX::field_0x68");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0x98) == 0x098, "ccBoss0310DoubleNRX::field_0x98");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0xC0) == 0x0C0, "ccBoss0310DoubleNRX::field_0xC0");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0xD4) == 0x0D4, "ccBoss0310DoubleNRX::field_0xD4");
_Static_assert(offsetof(ns3_ccBoss0310DoubleNRX, field_0xD8) == 0x0D8, "ccBoss0310DoubleNRX::field_0xD8");

/* ccUiBoss0310SpSkillAnnounce: 2 data fields from state_surface (INFERRED) */
/* Size: unknown, >= 0x6C */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x000[68]; /* 0x000..0x043 */
    uint32_t field_0x44; /* 0x044 sz=4 r conf=low */
    uint8_t _pad_0x048[32]; /* 0x048..0x067 */
    uint32_t field_0x68; /* 0x068 sz=4 r conf=low */
} ns3_ccUiBoss0310SpSkillAnnounce;

_Static_assert(offsetof(ns3_ccUiBoss0310SpSkillAnnounce, field_0x44) == 0x044, "ccUiBoss0310SpSkillAnnounce::field_0x44");
_Static_assert(offsetof(ns3_ccUiBoss0310SpSkillAnnounce, field_0x68) == 0x068, "ccUiBoss0310SpSkillAnnounce::field_0x68");

/* ccUiBoss03PlayerGauge::SpecialSupport: 5 data fields from state_surface (INFERRED) */
/* Size: unknown, >= 0x48 */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x000[48]; /* 0x000..0x02F */
    uint32_t field_0x30; /* 0x030 sz=4 w conf=high */
    uint32_t field_0x34; /* 0x034 sz=4 w conf=medium */
    uint32_t field_0x38; /* 0x038 sz=4 w conf=medium */
    uint32_t field_0x3C; /* 0x03C sz=4 w conf=medium */
    uint64_t field_0x40; /* 0x040 sz=8 rw conf=high */
} ns3_ccUiBoss03PlayerGauge__SpecialSupport;

_Static_assert(offsetof(ns3_ccUiBoss03PlayerGauge__SpecialSupport, field_0x30) == 0x030, "ccUiBoss03PlayerGauge__SpecialSupport::field_0x30");
_Static_assert(offsetof(ns3_ccUiBoss03PlayerGauge__SpecialSupport, field_0x34) == 0x034, "ccUiBoss03PlayerGauge__SpecialSupport::field_0x34");
_Static_assert(offsetof(ns3_ccUiBoss03PlayerGauge__SpecialSupport, field_0x38) == 0x038, "ccUiBoss03PlayerGauge__SpecialSupport::field_0x38");
_Static_assert(offsetof(ns3_ccUiBoss03PlayerGauge__SpecialSupport, field_0x3C) == 0x03C, "ccUiBoss03PlayerGauge__SpecialSupport::field_0x3C");
_Static_assert(offsetof(ns3_ccUiBoss03PlayerGauge__SpecialSupport, field_0x40) == 0x040, "ccUiBoss03PlayerGauge__SpecialSupport::field_0x40");

/* ccBoss0300KybActTurn: 11 data fields from state_surface (INFERRED) */
/* Size: unknown, >= 0x94 */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x000[84]; /* 0x000..0x053 */
    uint32_t field_0x54; /* 0x054 sz=4 w conf=medium */
    uint32_t field_0x58; /* 0x058 sz=4 w conf=medium */
    uint32_t field_0x5C; /* 0x05C sz=4 w conf=medium */
    uint32_t field_0x60; /* 0x060 sz=4 w conf=medium */
    uint8_t _pad_0x064[4]; /* 0x064..0x067 */
    uint32_t field_0x68; /* 0x068 sz=4 w conf=medium */
    uint32_t field_0x6C; /* 0x06C sz=4 w conf=medium */
    uint32_t field_0x70; /* 0x070 sz=4 r conf=low */
    uint8_t _pad_0x074[8]; /* 0x074..0x07B */
    uint32_t field_0x7C; /* 0x07C sz=4 r conf=low */
    uint8_t _pad_0x080[8]; /* 0x080..0x087 */
    uint32_t field_0x88; /* 0x088 sz=4 w conf=medium */
    uint32_t field_0x8C; /* 0x08C sz=4 w conf=medium */
    uint32_t field_0x90; /* 0x090 sz=4 w conf=medium */
} ns3_ccBoss0300KybActTurn;

_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x54) == 0x054, "ccBoss0300KybActTurn::field_0x54");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x58) == 0x058, "ccBoss0300KybActTurn::field_0x58");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x5C) == 0x05C, "ccBoss0300KybActTurn::field_0x5C");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x60) == 0x060, "ccBoss0300KybActTurn::field_0x60");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x68) == 0x068, "ccBoss0300KybActTurn::field_0x68");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x6C) == 0x06C, "ccBoss0300KybActTurn::field_0x6C");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x70) == 0x070, "ccBoss0300KybActTurn::field_0x70");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x7C) == 0x07C, "ccBoss0300KybActTurn::field_0x7C");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x88) == 0x088, "ccBoss0300KybActTurn::field_0x88");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x8C) == 0x08C, "ccBoss0300KybActTurn::field_0x8C");
_Static_assert(offsetof(ns3_ccBoss0300KybActTurn, field_0x90) == 0x090, "ccBoss0300KybActTurn::field_0x90");

/* ccBoss0300Stage: 11 data fields from state_surface (INFERRED) */
/* Size: unknown, >= 0x1A8 */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x000[160]; /* 0x000..0x09F */
    uint32_t field_0xA0; /* 0x0A0 sz=4 r conf=low */
    uint8_t _pad_0x0A4[92]; /* 0x0A4..0x0FF */
    uint64_t field_0x100; /* 0x100 sz=8 w conf=medium */
    uint64_t field_0x108; /* 0x108 sz=8 w conf=medium */
    uint64_t field_0x110; /* 0x110 sz=8 w conf=medium */
    uint32_t field_0x118; /* 0x118 sz=4 w conf=medium */
    uint32_t field_0x11C; /* 0x11C sz=4 w conf=medium */
    uint32_t field_0x120; /* 0x120 sz=4 r conf=low */
    uint8_t _pad_0x124[116]; /* 0x124..0x197 */
    uint32_t field_0x198; /* 0x198 sz=4 w conf=medium */
    uint32_t field_0x19C; /* 0x19C sz=4 w conf=medium */
    uint32_t field_0x1A0; /* 0x1A0 sz=4 w conf=medium */
    uint32_t field_0x1A4; /* 0x1A4 sz=4 w conf=medium */
} ns3_ccBoss0300Stage;

_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0xA0) == 0x0A0, "ccBoss0300Stage::field_0xA0");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x100) == 0x100, "ccBoss0300Stage::field_0x100");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x108) == 0x108, "ccBoss0300Stage::field_0x108");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x110) == 0x110, "ccBoss0300Stage::field_0x110");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x118) == 0x118, "ccBoss0300Stage::field_0x118");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x11C) == 0x11C, "ccBoss0300Stage::field_0x11C");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x120) == 0x120, "ccBoss0300Stage::field_0x120");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x198) == 0x198, "ccBoss0300Stage::field_0x198");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x19C) == 0x19C, "ccBoss0300Stage::field_0x19C");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x1A0) == 0x1A0, "ccBoss0300Stage::field_0x1A0");
_Static_assert(offsetof(ns3_ccBoss0300Stage, field_0x1A4) == 0x1A4, "ccBoss0300Stage::field_0x1A4");

/* ccBoss0300CamOpeCombo: no instance state found by state_surface — header-only placeholder */

/* ccBoss0300CamOpeType02: no instance state found by state_surface — header-only placeholder */

/* ccBoss0310CamOpeBegin: no instance state found by state_surface — header-only placeholder */

/* ccSceneBoss0300: no instance state found by state_surface — header-only placeholder */

/* ccBoss0310KybActShot: no instance state found by state_surface — header-only placeholder */

/* ccBoss0300CamOpeType00: no instance state found by state_surface — header-only placeholder */

/* ccBoss0300CamOpeType01: no instance state found by state_surface — header-only placeholder */


/* ccBoss0310CamOpeCombo: no instance state found by state_surface — header-only placeholder */

/* ccBoss0310SkillShockWave: 7 data fields from state_surface (INFERRED) */
/* Size: unknown, >= 0x2A4 */
typedef struct __attribute__((packed)) {
    uint8_t _pad_0x000[304]; /* 0x000..0x12F */
    uint64_t field_0x130; /* 0x130 sz=8 rw conf=low */
    uint64_t field_0x138; /* 0x138 sz=8 w conf=medium */
    uint8_t _pad_0x140[304]; /* 0x140..0x26F */
    uint64_t field_0x270; /* 0x270 sz=8 w conf=medium */
    uint8_t _pad_0x278[12]; /* 0x278..0x283 */
    uint32_t field_0x284; /* 0x284 sz=4 w conf=medium */
    uint8_t _pad_0x288[16]; /* 0x288..0x297 */
    uint32_t field_0x298; /* 0x298 sz=4 w conf=medium */
    uint32_t field_0x29C; /* 0x29C sz=4 w conf=medium */
    uint32_t field_0x2A0; /* 0x2A0 sz=4 w conf=medium */
} ns3_ccBoss0310SkillShockWave;

_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x130) == 0x130, "ccBoss0310SkillShockWave::field_0x130");
_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x138) == 0x138, "ccBoss0310SkillShockWave::field_0x138");
_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x270) == 0x270, "ccBoss0310SkillShockWave::field_0x270");
_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x284) == 0x284, "ccBoss0310SkillShockWave::field_0x284");
_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x298) == 0x298, "ccBoss0310SkillShockWave::field_0x298");
_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x29C) == 0x29C, "ccBoss0310SkillShockWave::field_0x29C");
_Static_assert(offsetof(ns3_ccBoss0310SkillShockWave, field_0x2A0) == 0x2A0, "ccBoss0310SkillShockWave::field_0x2A0");

/* ccUiBoss0310ChakraIncEffect: no instance state found by state_surface — header-only placeholder */

/* ccUiBoss0310SupportKSN: no instance state found by state_surface — header-only placeholder */

#endif /* S3_BOSS03_H */
