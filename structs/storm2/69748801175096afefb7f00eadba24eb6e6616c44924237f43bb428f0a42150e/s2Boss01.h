#ifndef S2_BOSS01_H
#define S2_BOSS01_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s2Boss01 - Storm 2 (NSUNS2.exe) boss battle structs
 * Build: s2 (sha 697488011750...)
 * All fields INFERRED from static analysis (state_surface + decomp).
 *
 * Classes reconstructed:
 *   ccBoss01Kakashi       - main Kakashi boss (43 methods), inherits ccPlayerLeader
 *                           size 0x86E0 from LoadTh(0x86e0) in Create factory
 *   ccBoss01Suiryu        - Suiryu/dragon boss (20 methods), inherits ccBossBattleObjectBase
 *                           size 0x1D88 from LoadTh(0x1d88) in Create factory
 *   ccBoss01SupportSakura - support Sakura (inherits ccPlayerLeader, fields start at 0x7100)
 *                           size 0x8A48 from LoadTh(0x8a48) in Create factory
 */

/* Helper types (sizes verified by static_assert below) */
typedef struct Nucc_Vector3 {
    float x;
    float y;
    float z;
} Nucc_Vector3;
static_assert(sizeof(Nucc_Vector3) == 12, "Nucc_Vector3 size");

typedef struct ccCmnRotate {
    float m[4];
} ccCmnRotate;
static_assert(sizeof(ccCmnRotate) == 16, "ccCmnRotate size");

typedef struct ccSkillLoader {
    uint64_t a;
    uint64_t b;
} ccSkillLoader;
static_assert(sizeof(ccSkillLoader) == 16, "ccSkillLoader size");

typedef struct ccBoss01Suiryu {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a4dd8 */
    uint8_t pad_0008[0x90]; /* 0x0008 */
    uint64_t unk_0098; /* 0x0098 - read in dtor */
    uint8_t pad_00A0[0x1418]; /* 0x00A0 */
    uint64_t base_vtable; /* 0x14B8 - PTR_LAB_1407a4e28 */
    uint8_t pad_14C0[0x98]; /* 0x14C0 */
    Nucc_Vector3 vec_1558; /* 0x1558 - Vector3 ctor */
    Nucc_Vector3 vec_1564; /* 0x1564 - Vector3 ctor */
    Nucc_Vector3 vec_1570; /* 0x1570 - Vector3 ctor */
    uint8_t pad_157C[0x4]; /* 0x157C */
    ccCmnRotate rotate_1580; /* 0x1580 - ccCmnRotate ctor */
    uint8_t pad_1590[0x4C]; /* 0x1590 */
    uint32_t unk_15DC; /* 0x15DC - zeroed in ctor */
    uint8_t pad_15E0[0x4]; /* 0x15E0 */
    Nucc_Vector3 vec_15E4; /* 0x15E4 - Vector3 ctor */
    uint8_t pad_15F0[0x8]; /* 0x15F0 */
    float float_15F8; /* 0x15F8 - 1.0f */
    uint8_t pad_15FC[0x4]; /* 0x15FC */
    Nucc_Vector3 vec_1600; /* 0x1600 - Vector3 ctor */
    uint8_t pad_160C[0x4]; /* 0x160C */
    uint64_t unk_1610; /* 0x1610 - zeroed */
    float float_1618; /* 0x1618 - 0.01f */
    uint8_t pad_161C[0x12C]; /* 0x161C */
    ccSkillLoader skills[72]; /* 0x1748 - 72 skill loaders */
    uint8_t pad_1BC8[0x10]; /* 0x1BC8 */
    ccCmnRotate rotates[2]; /* 0x1BD8 - 2 rotation helpers */
    uint8_t pad_1BF8[0xF8]; /* 0x1BF8 */
    uint32_t phase_flags[6]; /* 0x1CF0 - initialized to 0 */
    uint8_t pad_1D08[0x18]; /* 0x1D08 */
    Nucc_Vector3 phase_vecs[6]; /* 0x1D20 - 6 Vector3 entries */
    uint8_t pad_1D68[0x4]; /* 0x1D68 */
    uint32_t unk_1D6C; /* 0x1D6C - zeroed */
    int32_t neg1_array[5]; /* 0x1D70 - initialized to -1 */
    uint8_t pad_1D84[0x4]; /* 0x1D84 to 0x1D88 */
} __attribute__((packed)) ccBoss01Suiryu;

static_assert(sizeof(ccBoss01Suiryu) == 0x1D88, "ccBoss01Suiryu size");
static_assert(offsetof(ccBoss01Suiryu, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccBoss01Suiryu, unk_0098) == 0x0098, "unk_0098");
static_assert(offsetof(ccBoss01Suiryu, base_vtable) == 0x14B8, "base_vtable");
static_assert(offsetof(ccBoss01Suiryu, vec_1558) == 0x1558, "vec_1558");
static_assert(offsetof(ccBoss01Suiryu, vec_1564) == 0x1564, "vec_1564");
static_assert(offsetof(ccBoss01Suiryu, vec_1570) == 0x1570, "vec_1570");
static_assert(offsetof(ccBoss01Suiryu, rotate_1580) == 0x1580, "rotate_1580");
static_assert(offsetof(ccBoss01Suiryu, unk_15DC) == 0x15DC, "unk_15DC");
static_assert(offsetof(ccBoss01Suiryu, vec_15E4) == 0x15E4, "vec_15E4");
static_assert(offsetof(ccBoss01Suiryu, float_15F8) == 0x15F8, "float_15F8");
static_assert(offsetof(ccBoss01Suiryu, vec_1600) == 0x1600, "vec_1600");
static_assert(offsetof(ccBoss01Suiryu, unk_1610) == 0x1610, "unk_1610");
static_assert(offsetof(ccBoss01Suiryu, float_1618) == 0x1618, "float_1618");
static_assert(offsetof(ccBoss01Suiryu, skills) == 0x1748, "skills");
static_assert(offsetof(ccBoss01Suiryu, rotates) == 0x1BD8, "rotates");
static_assert(offsetof(ccBoss01Suiryu, phase_flags) == 0x1CF0, "phase_flags");
static_assert(offsetof(ccBoss01Suiryu, phase_vecs) == 0x1D20, "phase_vecs");
static_assert(offsetof(ccBoss01Suiryu, unk_1D6C) == 0x1D6C, "unk_1D6C");
static_assert(offsetof(ccBoss01Suiryu, neg1_array) == 0x1D70, "neg1_array");

typedef struct ccBoss01Kakashi {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a3268 */
    uint8_t pad_0008[0x90]; /* 0x0008 */
    uint64_t ctrl_copy_qword_0; /* 0x0098 - w in Ctrl */
    uint32_t ctrl_field_A0; /* 0x00A0 - rw high conf */
    uint64_t ctrl_copy_A4; /* 0x00A4 - w in Ctrl */
    uint32_t ctrl_copy_AC; /* 0x00AC - w in Ctrl */
    uint64_t ctrl_copy_B0; /* 0x00B0 - w in Ctrl */
    uint32_t ctrl_copy_B8; /* 0x00B8 - w in Ctrl */
    uint64_t collision_copy_BC; /* 0x00BC - rw in CollisionCallback */
    uint32_t ctrl_copy_C4; /* 0x00C4 - w in Ctrl */
    uint8_t pad_00C8[0x100]; /* 0x00C8 */
    uint64_t bone_handle_1C8; /* 0x01C8 - rw hand bone lookup */
    uint8_t pad_01D0[0x48]; /* 0x01D0 */
    uint64_t hand_bone_218; /* 0x0218 - rw 2kks00t0 l hand */
    uint8_t pad_0220[0x3E0]; /* 0x0220 */
    uint32_t init_field_600; /* 0x0600 - w in Initialize */
    uint8_t pad_0604[0x2D0]; /* 0x0604 */
    uint32_t timer_base_8D4; /* 0x08D4 - rw timer value */
    uint32_t timer_copy_8D8; /* 0x08D8 - w copies 8D4 */
    uint32_t timer_sum_8DC; /* 0x08DC - r sum of 8D4+8D8 */
    uint8_t pad_08E0[0x1460]; /* 0x08E0 */
    uint64_t draw_param_1D40; /* 0x1D40 - r via vfunc 0x3A8 */
    uint8_t pad_1D48[0x38]; /* 0x1D48 */
    uint64_t draw_param_1D80; /* 0x1D80 - r via vfunc 0x3B0 */
    uint8_t pad_1D88[0x2B8]; /* 0x1D88 */
    uint64_t vfunc_call_2040; /* 0x2040 - r via vfunc 0x408 */
    uint8_t pad_2048[0x5E0]; /* 0x2048 */
    uint64_t field_2628; /* 0x2628 - r passed to FUN_14039b188 */
    uint8_t pad_2630[0x1290]; /* 0x2630 */
    uint64_t vfunc_ptr_38C0; /* 0x38C0 - r via vfunc 0x718 */
    uint8_t pad_38C8[0x25A8]; /* 0x38C8 */
    uint64_t sentinel_check_5E70; /* 0x5E70 - r vfunc dispatch */
    uint8_t pad_5E78[0x50]; /* 0x5E78 */
    uint64_t sentinel_ptr_5EC8; /* 0x5EC8 - r */
    uint64_t sentinel_val_5ED0; /* 0x5ED0 - rw checked == sentinel */
    uint8_t pad_5ED8[0x18]; /* 0x5ED8 */
    uint64_t sentinel_ptr_5EF0; /* 0x5EF0 - r vfunc dispatch */
    uint8_t pad_5EF8[0x58]; /* 0x5EF8 */
    uint64_t sentinel_ptr_5F50; /* 0x5F50 - r */
    uint64_t sentinel_val_5F58; /* 0x5F58 - rw checked == sentinel */
    uint8_t pad_5F60[0x18]; /* 0x5F60 */
    uint64_t init_struct_5F78; /* 0x5F78 - r passed to FUN_1401fc268 */
    uint8_t pad_5F80[0x58]; /* 0x5F80 */
    uint64_t sentinel_ptr_5FD8; /* 0x5FD8 - r */
    uint64_t sentinel_val_5FE0; /* 0x5FE0 - rw checked == sentinel */
    uint8_t pad_5FE8[0x50]; /* 0x5FE8 */
    uint32_t dmg_struct_6038; /* 0x6038 - r ptr to damage data (low32) */
    uint32_t dmg_flag_603C; /* 0x603C - r checked == 0 */
    uint8_t pad_6040[0xC]; /* 0x6040 */
    float dmg_float_604C; /* 0x604C - r checked != 0.0 */
    uint8_t pad_6050[0x14]; /* 0x6050 */
    uint16_t dmg_id_6064; /* 0x6064 - r 2-byte id */
    uint8_t pad_6066[0x2]; /* 0x6066 */
    uint32_t dmg_result_6068; /* 0x6068 - w damage output */
    uint8_t pad_606C[0x9B4]; /* 0x606C */
    uint32_t ninja_move_idx_6A20; /* 0x6A20 - r index * 5 stride */
    uint32_t ninja_move_flags_6A24; /* 0x6A24 - rw bitfield & 1 */
    uint8_t pad_6A28[0x48]; /* 0x6A28 */
    uint32_t ctrl_state_6A70; /* 0x6A70 - rw set to 2 */
    uint64_t ctrl_copy_6A74; /* 0x6A74 - rw */
    uint32_t ctrl_copy_6A7C; /* 0x6A7C - w */
    uint64_t ctrl_copy_6A80; /* 0x6A80 - w */
    uint32_t ctrl_copy_6A88; /* 0x6A88 - w */
    uint32_t ctrl_zero_6A8C; /* 0x6A8C - rw zeroed */
    uint8_t pad_6A90[0x4D8]; /* 0x6A90 */
    uint32_t ctrl_loop_flag_6F68; /* 0x6F68 - rw checked == 0 */
    uint8_t pad_6F6C[0x134]; /* 0x6F6C */
    uint64_t task_sub_70A0; /* 0x70A0 - rw FUN_140217494 target */
    uint8_t pad_70A8[0x48]; /* 0x70A8 */
    uint32_t collision_check_70F0; /* 0x70F0 - r checked != 0x1f */
    uint32_t ctrl_const_70F4; /* 0x70F4 - w set to 10 */
    uint8_t pad_70F8[0x8]; /* 0x70F8 */
    uint32_t ctrl_init_7100; /* 0x7100 - w set to 1 */
    uint8_t pad_7104[0x1454]; /* 0x7104 */
    Nucc_Vector3 vec_8558; /* 0x8558 - Vector3 collision related */
    Nucc_Vector3 vec_8564; /* 0x8564 - Vector3 ctor */
    Nucc_Vector3 vec_8570; /* 0x8570 - Vector3 ctor */
    Nucc_Vector3 vec_857C; /* 0x857C - Vector3 ctor site */
    uint32_t dmg_reaction_zero_8588; /* 0x8588 - w zeroed */
    uint8_t pad_858C[0x4]; /* 0x858C */
    uint64_t ctrl_struct_8590; /* 0x8590 - r FUN_1402075a4 arg */
    uint8_t pad_8598[0xC]; /* 0x8598 */
    uint64_t ctrl_buf_85A4; /* 0x85A4 - r FUN_140586540 target */
    uint8_t pad_85AC[0x3C]; /* 0x85AC */
    ccCmnRotate rotate_85E8; /* 0x85E8 - ccCmnRotate ctor */
    uint8_t pad_85F8[0x48]; /* 0x85F8 */
    uint32_t collision_counter_8640; /* 0x8640 - rw collision count */
    uint32_t ninja_move_phase_8644; /* 0x8644 - rw phase check */
    uint32_t goukakyu_index_8648; /* 0x8648 - rw fireball index */
    uint32_t collision_field_864C; /* 0x864C - r */
    uint32_t init_zero_8650; /* 0x8650 - w zeroed */
    uint32_t ctrl_damage_arg_8654; /* 0x8654 - rw */
    uint32_t dmg_reaction_idx_8658; /* 0x8658 - rw */
    uint32_t dmg_reaction_copy_865C; /* 0x865C - rw */
    float dmg_reaction_ratio_8660; /* 0x8660 - rw float ratio */
    uint32_t dmg_reaction_zero_8664; /* 0x8664 - rw zeroed */
    uint32_t dmg_reaction_enter_8668; /* 0x8668 - w zeroed */
    float ctrl_damage_float_866C; /* 0x866C - rw */
    uint8_t pad_8670[0xC]; /* 0x8670 */
    uint32_t dmg_reaction_copy_867C; /* 0x867C - rw */
    uint8_t pad_8680[0x4]; /* 0x8680 */
    uint32_t ctrl_zero_8684; /* 0x8684 - rw zeroed */
    uint32_t ctrl_copy_8688; /* 0x8688 - w */
    uint64_t ninja_move_copy_868C; /* 0x868C - w */
    uint64_t ninja_move_copy2_8694; /* 0x8694 - w */
    uint64_t ninja_move_copy3_869C; /* 0x869C - w */
    uint8_t pad_86A4[0x4]; /* 0x86A4 */
    uint32_t init_neg1_86A8; /* 0x86A8 - w 0xFFFFFFFF */
    float dmg_reaction_1f_86AC; /* 0x86AC - w 1.0f */
    float dmg_reaction_check_86B0; /* 0x86B0 - rw checked <= 1.0 */
    float dmg_reaction_small_86B4; /* 0x86B4 - w 0.15f */
    uint32_t collision_zero_86B8; /* 0x86B8 - rw zeroed */
    uint32_t dmg_reaction_int_86BC; /* 0x86BC - w */
    uint32_t collision_count_86C0; /* 0x86C0 - rw checked > 0 */
    uint32_t ctrl_damage_copy_86C4; /* 0x86C4 - rw */
    float ctrl_3_5f_86C8; /* 0x86C8 - w 3.5f */
    float ctrl_0_15f_86CC; /* 0x86CC - w 0.15f */
    uint64_t ctor_zero_86D0; /* 0x86D0 - w zeroed */
    uint32_t ctrl_damage_check_86D8; /* 0x86D8 - rw */
    uint8_t pad_86DC[0x4]; /* 0x86DC to 0x86E0 */
} __attribute__((packed)) ccBoss01Kakashi;

static_assert(sizeof(ccBoss01Kakashi) == 0x86E0, "ccBoss01Kakashi size");
static_assert(offsetof(ccBoss01Kakashi, vtable) == 0x0000, "vtable");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_qword_0) == 0x0098, "ctrl_copy_qword_0");
static_assert(offsetof(ccBoss01Kakashi, ctrl_field_A0) == 0x00A0, "ctrl_field_A0");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_A4) == 0x00A4, "ctrl_copy_A4");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_AC) == 0x00AC, "ctrl_copy_AC");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_B0) == 0x00B0, "ctrl_copy_B0");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_B8) == 0x00B8, "ctrl_copy_B8");
static_assert(offsetof(ccBoss01Kakashi, collision_copy_BC) == 0x00BC, "collision_copy_BC");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_C4) == 0x00C4, "ctrl_copy_C4");
static_assert(offsetof(ccBoss01Kakashi, bone_handle_1C8) == 0x01C8, "bone_handle_1C8");
static_assert(offsetof(ccBoss01Kakashi, hand_bone_218) == 0x0218, "hand_bone_218");
static_assert(offsetof(ccBoss01Kakashi, init_field_600) == 0x0600, "init_field_600");
static_assert(offsetof(ccBoss01Kakashi, timer_base_8D4) == 0x08D4, "timer_base_8D4");
static_assert(offsetof(ccBoss01Kakashi, timer_copy_8D8) == 0x08D8, "timer_copy_8D8");
static_assert(offsetof(ccBoss01Kakashi, timer_sum_8DC) == 0x08DC, "timer_sum_8DC");
static_assert(offsetof(ccBoss01Kakashi, draw_param_1D40) == 0x1D40, "draw_param_1D40");
static_assert(offsetof(ccBoss01Kakashi, draw_param_1D80) == 0x1D80, "draw_param_1D80");
static_assert(offsetof(ccBoss01Kakashi, vfunc_call_2040) == 0x2040, "vfunc_call_2040");
static_assert(offsetof(ccBoss01Kakashi, field_2628) == 0x2628, "field_2628");
static_assert(offsetof(ccBoss01Kakashi, vfunc_ptr_38C0) == 0x38C0, "vfunc_ptr_38C0");
static_assert(offsetof(ccBoss01Kakashi, sentinel_check_5E70) == 0x5E70, "sentinel_check_5E70");
static_assert(offsetof(ccBoss01Kakashi, sentinel_ptr_5EC8) == 0x5EC8, "sentinel_ptr_5EC8");
static_assert(offsetof(ccBoss01Kakashi, sentinel_val_5ED0) == 0x5ED0, "sentinel_val_5ED0");
static_assert(offsetof(ccBoss01Kakashi, sentinel_ptr_5EF0) == 0x5EF0, "sentinel_ptr_5EF0");
static_assert(offsetof(ccBoss01Kakashi, sentinel_ptr_5F50) == 0x5F50, "sentinel_ptr_5F50");
static_assert(offsetof(ccBoss01Kakashi, sentinel_val_5F58) == 0x5F58, "sentinel_val_5F58");
static_assert(offsetof(ccBoss01Kakashi, init_struct_5F78) == 0x5F78, "init_struct_5F78");
static_assert(offsetof(ccBoss01Kakashi, sentinel_ptr_5FD8) == 0x5FD8, "sentinel_ptr_5FD8");
static_assert(offsetof(ccBoss01Kakashi, sentinel_val_5FE0) == 0x5FE0, "sentinel_val_5FE0");
static_assert(offsetof(ccBoss01Kakashi, dmg_struct_6038) == 0x6038, "dmg_struct_6038");
static_assert(offsetof(ccBoss01Kakashi, dmg_flag_603C) == 0x603C, "dmg_flag_603C");
static_assert(offsetof(ccBoss01Kakashi, dmg_float_604C) == 0x604C, "dmg_float_604C");
static_assert(offsetof(ccBoss01Kakashi, dmg_id_6064) == 0x6064, "dmg_id_6064");
static_assert(offsetof(ccBoss01Kakashi, dmg_result_6068) == 0x6068, "dmg_result_6068");
static_assert(offsetof(ccBoss01Kakashi, ninja_move_idx_6A20) == 0x6A20, "ninja_move_idx_6A20");
static_assert(offsetof(ccBoss01Kakashi, ninja_move_flags_6A24) == 0x6A24, "ninja_move_flags_6A24");
static_assert(offsetof(ccBoss01Kakashi, ctrl_state_6A70) == 0x6A70, "ctrl_state_6A70");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_6A74) == 0x6A74, "ctrl_copy_6A74");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_6A7C) == 0x6A7C, "ctrl_copy_6A7C");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_6A80) == 0x6A80, "ctrl_copy_6A80");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_6A88) == 0x6A88, "ctrl_copy_6A88");
static_assert(offsetof(ccBoss01Kakashi, ctrl_zero_6A8C) == 0x6A8C, "ctrl_zero_6A8C");
static_assert(offsetof(ccBoss01Kakashi, ctrl_loop_flag_6F68) == 0x6F68, "ctrl_loop_flag_6F68");
static_assert(offsetof(ccBoss01Kakashi, task_sub_70A0) == 0x70A0, "task_sub_70A0");
static_assert(offsetof(ccBoss01Kakashi, collision_check_70F0) == 0x70F0, "collision_check_70F0");
static_assert(offsetof(ccBoss01Kakashi, ctrl_const_70F4) == 0x70F4, "ctrl_const_70F4");
static_assert(offsetof(ccBoss01Kakashi, ctrl_init_7100) == 0x7100, "ctrl_init_7100");
static_assert(offsetof(ccBoss01Kakashi, vec_8558) == 0x8558, "vec_8558");
static_assert(offsetof(ccBoss01Kakashi, vec_8564) == 0x8564, "vec_8564");
static_assert(offsetof(ccBoss01Kakashi, vec_8570) == 0x8570, "vec_8570");
static_assert(offsetof(ccBoss01Kakashi, vec_857C) == 0x857C, "vec_857C");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_zero_8588) == 0x8588, "dmg_reaction_zero_8588");
static_assert(offsetof(ccBoss01Kakashi, ctrl_struct_8590) == 0x8590, "ctrl_struct_8590");
static_assert(offsetof(ccBoss01Kakashi, ctrl_buf_85A4) == 0x85A4, "ctrl_buf_85A4");
static_assert(offsetof(ccBoss01Kakashi, rotate_85E8) == 0x85E8, "rotate_85E8");
static_assert(offsetof(ccBoss01Kakashi, collision_counter_8640) == 0x8640, "collision_counter_8640");
static_assert(offsetof(ccBoss01Kakashi, ninja_move_phase_8644) == 0x8644, "ninja_move_phase_8644");
static_assert(offsetof(ccBoss01Kakashi, goukakyu_index_8648) == 0x8648, "goukakyu_index_8648");
static_assert(offsetof(ccBoss01Kakashi, collision_field_864C) == 0x864C, "collision_field_864C");
static_assert(offsetof(ccBoss01Kakashi, init_zero_8650) == 0x8650, "init_zero_8650");
static_assert(offsetof(ccBoss01Kakashi, ctrl_damage_arg_8654) == 0x8654, "ctrl_damage_arg_8654");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_idx_8658) == 0x8658, "dmg_reaction_idx_8658");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_copy_865C) == 0x865C, "dmg_reaction_copy_865C");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_ratio_8660) == 0x8660, "dmg_reaction_ratio_8660");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_zero_8664) == 0x8664, "dmg_reaction_zero_8664");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_enter_8668) == 0x8668, "dmg_reaction_enter_8668");
static_assert(offsetof(ccBoss01Kakashi, ctrl_damage_float_866C) == 0x866C, "ctrl_damage_float_866C");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_copy_867C) == 0x867C, "dmg_reaction_copy_867C");
static_assert(offsetof(ccBoss01Kakashi, ctrl_zero_8684) == 0x8684, "ctrl_zero_8684");
static_assert(offsetof(ccBoss01Kakashi, ctrl_copy_8688) == 0x8688, "ctrl_copy_8688");
static_assert(offsetof(ccBoss01Kakashi, ninja_move_copy_868C) == 0x868C, "ninja_move_copy_868C");
static_assert(offsetof(ccBoss01Kakashi, ninja_move_copy2_8694) == 0x8694, "ninja_move_copy2_8694");
static_assert(offsetof(ccBoss01Kakashi, ninja_move_copy3_869C) == 0x869C, "ninja_move_copy3_869C");
static_assert(offsetof(ccBoss01Kakashi, init_neg1_86A8) == 0x86A8, "init_neg1_86A8");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_1f_86AC) == 0x86AC, "dmg_reaction_1f_86AC");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_check_86B0) == 0x86B0, "dmg_reaction_check_86B0");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_small_86B4) == 0x86B4, "dmg_reaction_small_86B4");
static_assert(offsetof(ccBoss01Kakashi, collision_zero_86B8) == 0x86B8, "collision_zero_86B8");
static_assert(offsetof(ccBoss01Kakashi, dmg_reaction_int_86BC) == 0x86BC, "dmg_reaction_int_86BC");
static_assert(offsetof(ccBoss01Kakashi, collision_count_86C0) == 0x86C0, "collision_count_86C0");
static_assert(offsetof(ccBoss01Kakashi, ctrl_damage_copy_86C4) == 0x86C4, "ctrl_damage_copy_86C4");
static_assert(offsetof(ccBoss01Kakashi, ctrl_3_5f_86C8) == 0x86C8, "ctrl_3_5f_86C8");
static_assert(offsetof(ccBoss01Kakashi, ctrl_0_15f_86CC) == 0x86CC, "ctrl_0_15f_86CC");
static_assert(offsetof(ccBoss01Kakashi, ctor_zero_86D0) == 0x86D0, "ctor_zero_86D0");
static_assert(offsetof(ccBoss01Kakashi, ctrl_damage_check_86D8) == 0x86D8, "ctrl_damage_check_86D8");

typedef struct ccBoss01SupportSakura {
    uint8_t pad_0000[0x7100]; /* 0x0000 */
    uint64_t init_sub_7100; /* 0x7100 - rw initialized with type=7 */
    uint8_t pad_7108[0x14B0]; /* 0x7108 */
    ccCmnRotate rotate_85B8; /* 0x85B8 - FUN_1403c2f44 */
    uint8_t pad_85C8[0x3C0]; /* 0x85C8 */
    Nucc_Vector3 vec_8988; /* 0x8988 - Vector3 ctor */
    Nucc_Vector3 vec_8994; /* 0x8994 - Vector3 ctor */
    Nucc_Vector3 vec_89A0; /* 0x89A0 - Vector3 ctor */
    uint8_t pad_89AC[0x4]; /* 0x89AC */
    ccCmnRotate rotate_89B0; /* 0x89B0 - ccCmnRotate ctor */
    uint8_t pad_89C0[0x48]; /* 0x89C0 */
    uint32_t sakura_zero_8A08; /* 0x8A08 - w zeroed */
    uint32_t sakura_neg1_8A0C; /* 0x8A0C - w 0xFFFFFFFF */
    uint32_t sakura_one_8A10; /* 0x8A10 - w set to 1 */
    uint8_t pad_8A14[0xC]; /* 0x8A14 */
    Nucc_Vector3 vec_8A20; /* 0x8A20 - Vector3 ctor */
    Nucc_Vector3 vec_8A2C; /* 0x8A2C - Vector3 ctor */
    uint8_t pad_8A38[0x10]; /* 0x8A38 to 0x8A48 */
} __attribute__((packed)) ccBoss01SupportSakura;

static_assert(sizeof(ccBoss01SupportSakura) == 0x8A48, "ccBoss01SupportSakura size");
static_assert(offsetof(ccBoss01SupportSakura, init_sub_7100) == 0x7100, "init_sub_7100");
static_assert(offsetof(ccBoss01SupportSakura, rotate_85B8) == 0x85B8, "rotate_85B8");
static_assert(offsetof(ccBoss01SupportSakura, vec_8988) == 0x8988, "vec_8988");
static_assert(offsetof(ccBoss01SupportSakura, vec_8994) == 0x8994, "vec_8994");
static_assert(offsetof(ccBoss01SupportSakura, vec_89A0) == 0x89A0, "vec_89A0");
static_assert(offsetof(ccBoss01SupportSakura, rotate_89B0) == 0x89B0, "rotate_89B0");
static_assert(offsetof(ccBoss01SupportSakura, sakura_zero_8A08) == 0x8A08, "sakura_zero_8A08");
static_assert(offsetof(ccBoss01SupportSakura, sakura_neg1_8A0C) == 0x8A0C, "sakura_neg1_8A0C");
static_assert(offsetof(ccBoss01SupportSakura, sakura_one_8A10) == 0x8A10, "sakura_one_8A10");
static_assert(offsetof(ccBoss01SupportSakura, vec_8A20) == 0x8A20, "vec_8A20");
static_assert(offsetof(ccBoss01SupportSakura, vec_8A2C) == 0x8A2C, "vec_8A2C");

/* ================================================================
 * Batch 2: Coverage structs for remaining s2Boss01 classes
 * ================================================================ */

/* ccBoss01KakashiAI — AI controller for Kakashi boss fight
 * Size: 0x1550 (from FUN_140580190(0x1550,...) in Phase03 _Init)
 * Vtable: PTR_FUN_1407a3e78
 * Inherits: ccTaskBase (via FUN_1402aa884 base ctor)
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a3e78 */
    uint8_t base_0008[0x14B0]; /* 0x0008 - ccTaskBase inherited fields */
    uint32_t ai_state_14B8; /* 0x14B8 - checked == 1 in Ctrl */
    uint32_t ai_index_14BC; /* 0x14BC - index into threshold table */
    uint8_t pad_14C0[0xC]; /* 0x14C0 - gap to 0x14CC */
    uint32_t ai_flags_14CC; /* 0x14CC - bitfield (&8 rock, &0x10 dive) */
    uint32_t ai_dive_14D0; /* 0x14D0 - dive state counter */
    uint32_t ai_unk_14D4; /* 0x14D4 - set to 0 on dive reset */
    uint8_t pad_14D8[0xC]; /* 0x14D8 */
    uint64_t ai_ptr_14E4; /* 0x14E4 - zeroed in ctor */
    uint32_t ai_unk_14EC; /* 0x14EC - zeroed in ctor */
    uint8_t pad_14F0[0x60]; /* 0x14F0 to 0x1550 */
} __attribute__((packed)) ccBoss01KakashiAI;

static_assert(sizeof(ccBoss01KakashiAI) == 0x1550, "ccBoss01KakashiAI size");
static_assert(offsetof(ccBoss01KakashiAI, ai_state_14B8) == 0x14B8, "ai_state_14B8");
static_assert(offsetof(ccBoss01KakashiAI, ai_index_14BC) == 0x14BC, "ai_index_14BC");
static_assert(offsetof(ccBoss01KakashiAI, ai_flags_14CC) == 0x14CC, "ai_flags_14CC");
static_assert(offsetof(ccBoss01KakashiAI, ai_dive_14D0) == 0x14D0, "ai_dive_14D0");
static_assert(offsetof(ccBoss01KakashiAI, ai_unk_14D4) == 0x14D4, "ai_unk_14D4");
static_assert(offsetof(ccBoss01KakashiAI, ai_ptr_14E4) == 0x14E4, "ai_ptr_14E4");
static_assert(offsetof(ccBoss01KakashiAI, ai_unk_14EC) == 0x14EC, "ai_unk_14EC");

/* ccBoss01StageRock — breakable stage rock object
 * Size: 0x58 (from FUN_140580190(0x58,...) in Create)
 * Vtable: PTR_FUN_1407a4bd8
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a4bd8 */
    uint64_t embedded_obj_0008; /* 0x0008 - embedded container ptr */
    uint64_t embedded_end_0010; /* 0x0010 - container end */
    uint64_t embedded_cap_0018; /* 0x0018 - container capacity */
    uint64_t sub_vtable_0020; /* 0x0020 - PTR_FUN_14089c1b8 */
    uint8_t pad_0028[0x10]; /* 0x0028 */
    uint64_t field_0038; /* 0x0038 - zeroed */
    uint64_t field_0040; /* 0x0040 - zeroed */
    uint64_t field_0048; /* 0x0048 - zeroed */
    int32_t init_neg1_0050; /* 0x0050 - initialized to -1 */
    uint32_t pad_0054; /* 0x0054 */
} __attribute__((packed)) ccBoss01StageRock;

static_assert(sizeof(ccBoss01StageRock) == 0x58, "ccBoss01StageRock size");
static_assert(offsetof(ccBoss01StageRock, init_neg1_0050) == 0x0050, "init_neg1_0050");

/* ccBoss01Foothold — stage foothold platform
 * Size: 0xC8 (from FUN_140580190(200,...) in Create)
 * Vtable: PTR_FUN_1407a2728
 * Contains 4 embedded sub-objects (each 0x28 bytes with vtable PTR_FUN_14089c1b8)
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a2728 */
    uint64_t sub1_begin_0008; /* 0x0008 - sub-object 1 begin */
    uint64_t sub1_end_0010; /* 0x0010 */
    uint64_t sub1_cap_0018; /* 0x0018 */
    uint64_t sub1_vtbl_0020; /* 0x0020 - PTR_FUN_14089c1b8 */
    uint64_t sub2_begin_0028; /* 0x0028 - sub-object 2 */
    uint64_t sub2_end_0030; /* 0x0030 */
    uint64_t sub2_cap_0038; /* 0x0038 */
    uint64_t sub2_vtbl_0040; /* 0x0040 - PTR_FUN_14089c1b8 */
    uint64_t sub3_begin_0048; /* 0x0048 - sub-object 3 */
    uint64_t sub3_end_0050; /* 0x0050 */
    uint64_t sub3_cap_0058; /* 0x0058 */
    uint64_t sub3_vtbl_0060; /* 0x0060 - PTR_FUN_14089c1b8 */
    uint64_t sub4_begin_0068; /* 0x0068 - sub-object 4 */
    uint64_t sub4_end_0070; /* 0x0070 */
    uint64_t sub4_cap_0078; /* 0x0078 */
    uint64_t sub4_vtbl_0080; /* 0x0080 - PTR_FUN_14089c1b8 */
    uint32_t array_field_0088; /* 0x0088 - first of 5-element array */
    uint32_t array_elem1_008C; /* 0x008C */
    uint32_t array_elem2_0090; /* 0x0090 */
    uint32_t array_elem3_0094; /* 0x0094 */
    uint32_t array_elem4_0098; /* 0x0098 */
    uint8_t pad_009C[0x2C]; /* 0x009C to 0xC8 */
} __attribute__((packed)) ccBoss01Foothold;

static_assert(sizeof(ccBoss01Foothold) == 0xC8, "ccBoss01Foothold size");
static_assert(offsetof(ccBoss01Foothold, array_field_0088) == 0x0088, "array_field_0088");

/* ccBoss01StageSubCollision — sub-collision handler for boss stage
 * Size: 0xA0 (from FUN_140580190(0xa0,...) in Create)
 * Vtable: PTR_FUN_1407a4be0
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a4be0 */
    uint8_t base_0008[0x90]; /* 0x0008 - inherited ccBossBattleObjectBase fields */
    uint32_t sub_col_field_0098; /* 0x0098 - zeroed in ctor */
    uint8_t pad_009C[0x4]; /* 0x009C to 0xA0 */
} __attribute__((packed)) ccBoss01StageSubCollision;

static_assert(sizeof(ccBoss01StageSubCollision) == 0xA0, "ccBoss01StageSubCollision size");
static_assert(offsetof(ccBoss01StageSubCollision, sub_col_field_0098) == 0x0098, "sub_col_field_0098");

/* ccBoss01SuiryuManager — manages Suiryu water dragon summon
 * Size: 0x18 (from FUN_140580190(0x18,...) in factory)
 * Vtable: PTR_FUN_1407a5028
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a5028 */
    uint64_t suiryu_ptr_0008; /* 0x0008 - zeroed, holds Suiryu ref */
    uint64_t suiryu_flag_0010; /* 0x0010 - zeroed, enable flag */
} __attribute__((packed)) ccBoss01SuiryuManager;

static_assert(sizeof(ccBoss01SuiryuManager) == 0x18, "ccBoss01SuiryuManager size");

/* ccBoss01PlayVoiceState — voice playback state machine
 * Size: 0x14F0 (from FUN_140580190(0x14f0,...) in factory)
 * Vtable: PTR_FUN_1407e2450
 * Inherits: ccTaskBase (via FUN_1402aa884 base ctor with type=4)
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407e2450 */
    uint8_t base_0008[0x14B0]; /* 0x0008 - ccTaskBase inherited */
    uint32_t voice_base_vtbl_14B8; /* 0x14B8 - set to 0 on reset */
    uint32_t voice_group_idx_14BC; /* 0x14BC - voice group index */
    uint32_t voice_entry_14C0; /* 0x14C0 - current entry id */
    uint32_t voice_copy_14C4; /* 0x14C4 - copied from 0x58 */
    uint32_t voice_table_val_14C8; /* 0x14C8 - from table[6] */
    uint32_t voice_state_14CC; /* 0x14CC - init -1, state flags */
    uint32_t voice_unk_14D0; /* 0x14D0 - zeroed on reset */
    uint32_t voice_unk_14D4; /* 0x14D4 - init -1 */
    uint8_t pad_14D8[0xC]; /* 0x14D8 */
    uint64_t voice_ptr_14E4; /* 0x14E4 - zeroed */
    uint32_t voice_unk_14EC; /* 0x14EC - zeroed */
    uint8_t pad_14F0[0x0]; /* 0x14F0 exact end */
} __attribute__((packed)) ccBoss01PlayVoiceState;

static_assert(sizeof(ccBoss01PlayVoiceState) == 0x14F0, "ccBoss01PlayVoiceState size");
static_assert(offsetof(ccBoss01PlayVoiceState, voice_base_vtbl_14B8) == 0x14B8, "voice_base_vtbl_14B8");
static_assert(offsetof(ccBoss01PlayVoiceState, voice_group_idx_14BC) == 0x14BC, "voice_group_idx_14BC");
static_assert(offsetof(ccBoss01PlayVoiceState, voice_entry_14C0) == 0x14C0, "voice_entry_14C0");
static_assert(offsetof(ccBoss01PlayVoiceState, voice_state_14CC) == 0x14CC, "voice_state_14CC");
static_assert(offsetof(ccBoss01PlayVoiceState, voice_unk_14D4) == 0x14D4, "voice_unk_14D4");
static_assert(offsetof(ccBoss01PlayVoiceState, voice_ptr_14E4) == 0x14E4, "voice_ptr_14E4");

/* ccBoss01Electrification — electric effect controller
 * Size: 0x48 (from ctor FUN_1401faa0c: memset(param_1+2, 0, 0x28) = 0x10+0x28=0x38...
 *   actually header=8 + int@0x8=4 + pad4 + memset(0x28)=0x38 total. But Ctrl accesses
 *   5 ptrs at 0x10..0x30 + counter at 0x38 → need 0x3C+. With alignment: 0x48.)
 * Vtable: PTR_FUN_1407a24c8
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407a24c8 */
    uint32_t elect_zero_0008; /* 0x0008 - zeroed in ctor */
    uint32_t pad_000C; /* 0x000C */
    uint64_t elect_effect_ptrs[5]; /* 0x0010 - 5 effect object ptrs, iterated in Ctrl */
    uint32_t elect_counter_0038; /* 0x0038 - frame counter, modulo'd for timing */
    uint8_t pad_003C[0xC]; /* 0x003C to 0x48 */
} __attribute__((packed)) ccBoss01Electrification;

static_assert(sizeof(ccBoss01Electrification) == 0x48, "ccBoss01Electrification size");
static_assert(offsetof(ccBoss01Electrification, elect_zero_0008) == 0x0008, "elect_zero_0008");
static_assert(offsetof(ccBoss01Electrification, elect_effect_ptrs) == 0x0010, "elect_effect_ptrs");
static_assert(offsetof(ccBoss01Electrification, elect_counter_0038) == 0x0038, "elect_counter_0038");

/* ccBoss0101SceneChangeState — scene transition state for boss01 cutscene
 * Size: 0x14D0 (from FUN_1401f2838: FUN_1402aa884(...,5) + writes up to param_1[0x299]=0x14C8+4=0x14CC,
 *   but also accessed at 0x14C0,0x14C4 in Step00Enter. Allocated as 0x14D0.)
 * Vtable: PTR_FUN_1407d21f0
 * Inherits: ccTaskBase (type=5)
 */
typedef struct {
    uint64_t vtable; /* 0x0000 - PTR_FUN_1407d21f0 */
    uint8_t base_0008[0x14B8]; /* 0x0008 - ccTaskBase inherited */
    uint32_t scene_float_14C0; /* 0x14C0 - float 0x40600000 (3.5f) set in Step00Enter */
    uint32_t scene_float_14C4; /* 0x14C4 - float 0x3e19999a (0.15f) set in Step00Enter */
    uint8_t pad_14C8[0x8]; /* 0x14C8 to 0x14D0 */
} __attribute__((packed)) ccBoss0101SceneChangeState;

static_assert(sizeof(ccBoss0101SceneChangeState) == 0x14D0, "ccBoss0101SceneChangeState size");
static_assert(offsetof(ccBoss0101SceneChangeState, scene_float_14C0) == 0x14C0, "scene_float_14C0");
static_assert(offsetof(ccBoss0101SceneChangeState, scene_float_14C4) == 0x14C4, "scene_float_14C4");

/* ccBoss01StageObjectItemBreak — item break effect for stage rocks
 * NO STRUCT: stateless manager pattern. Create() at 0x20A0FC delegates to
 * FUN_140209d9c(DAT_140a59158) which returns an existing global manager object.
 * No per-instance allocation via FUN_140580190. BreakRock/Initialize operate
 * on the shared manager. No unique vtable or instance state.
 */

/* ccSceneBoss01 — boss battle scene orchestrator
 * NO STRUCT: scene framework class. Initialize() at 0x41EEDC receives an
 * externally-allocated buffer and populates offsets 0x50-0x158 with sub-object
 * pointers (skill loaders, UI managers, task lists). No self-allocation found.
 * Scene classes are managed by the scene system allocator, not individually sized.
 */

/* ccSceneBoss01Phase01 — phase 1 (intro/cutscene) of boss01
 * NO STRUCT: scene phase class. Initialize/_Initialize at 0x420070/0x420268
 * populates offsets 0x128-0x158 with character refs, voice state, camera step.
 * No self-allocation; managed by scene phase framework.
 */

/* ccSceneBoss01Phase03 — phase 3 (main fight) of boss01
 * NO STRUCT: scene phase class. _Initialize at 0x4220D0 is the main setup,
 * allocating and registering all fight sub-objects (KakashiAI at 0x130,
 * Kakashi at 0x138, Sakura at 0x140, Suiryu at 0x148, StageObjectList at 0x150,
 * Foothold at 0x158, StageRock at 0x160, ItemBreak at 0x170, Electrification at 0x178,
 * VoiceState at 0x180, ItemSignal at 0x188). Writes up to offset 0x1A0.
 * No self-allocation; managed by scene phase framework.
 */

/* ========================================================================== */
/* ccBoss01SuiryuShockWave — water dragon shock wave projectile controller    */
/* Size: 0x168 (from FUN_140580190(0x168,...) in init FUN_14020fb38)          */
/* Vtable: PTR_FUN_140799438                                                  */
/* Methods: Ctrl (0x20F7B8), EnableActive (0x20F90C), DisableActive (0x20F89C)*/
/* Init: FUN_14020fb38 (references ccBoss01SuiryuShockWave.cpp)               */
/* Status: INFERRED                                                           */
/* ========================================================================== */
typedef struct __attribute__((packed)) ns2_ccBoss01SuiryuShockWave {
    /* 0x0000 */ uint64_t vtable;              /* PTR_FUN_140799438 */
    /* 0x0008 */ uint64_t base_vtable;         /* PTR_LAB_140799478 */
    /* 0x0010 */ uint8_t  pad_0010[0x88];      /* inherited base fields */
    /* 0x0098 */ uint64_t active_param;        /* w: set from param_2 in EnableActive */
    /* 0x00A0 */ uint32_t active_float;        /* w: 0xc31e0000 (-159.0f) in EnableActive */
    /* 0x00A4 */ int32_t  active_state;        /* rw: 0=disabled, 1=active; checked in Ctrl/Enable/Disable */
    /* 0x00A8 */ uint8_t  pad_00A8[0x08];      /* gap to 0xB0 */
    /* 0x00B0 */ uint64_t sub_object;          /* rw: ptr to allocated 0x168 sub-object */
    /* 0x00B8 */ uint64_t wave_ptrs[5];        /* rw: 5 effect/sub-object pointers, iterated in Ctrl/helpers */
    /* 0x00E0 */ uint8_t  pad_00E0[0x88];      /* gap to end of 0x168 */
} ns2_ccBoss01SuiryuShockWave;

static_assert(sizeof(ns2_ccBoss01SuiryuShockWave) == 0x168, "ccBoss01SuiryuShockWave size");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, vtable) == 0x0000, "ccBoss01SuiryuShockWave::vtable");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, base_vtable) == 0x0008, "ccBoss01SuiryuShockWave::base_vtable");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, active_param) == 0x0098, "ccBoss01SuiryuShockWave::active_param");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, active_float) == 0x00A0, "ccBoss01SuiryuShockWave::active_float");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, active_state) == 0x00A4, "ccBoss01SuiryuShockWave::active_state");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, sub_object) == 0x00B0, "ccBoss01SuiryuShockWave::sub_object");
static_assert(offsetof(ns2_ccBoss01SuiryuShockWave, wave_ptrs) == 0x00B8, "ccBoss01SuiryuShockWave::wave_ptrs");

#endif /* S2_BOSS01_H */
