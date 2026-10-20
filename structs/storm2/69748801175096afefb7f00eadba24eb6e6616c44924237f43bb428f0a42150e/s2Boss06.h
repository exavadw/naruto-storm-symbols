#ifndef S2_BOSS06_H
#define S2_BOSS06_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * s2Boss06 - Storm 2 (NSUNS2.exe) boss battle structs
 * Build: s2 (sha 697488011750...)
 * All fields INFERRED from static analysis (state_surface).
 * Object size 0x15D10 from ccBoss06Kzu03::Create -> LoadTh(0x15d10).
 * Packed struct: no implicit padding, all offsets exact.
 */

#pragma pack(push, 1)
typedef struct ccBoss06Kzu03 {
    uint64_t vtable;                              /* 0x0000 */
    uint8_t pad_0008[156];        /* 0x0008 (156 bytes) */
    uint64_t copy_src_qword_0;                  /* 0x00A4 */
    uint32_t copy_src_dword_1;                  /* 0x00AC */
    uint64_t copy_src_qword_2;                  /* 0x00B0 */
    uint32_t copy_src_dword_3;                  /* 0x00B8 */
    uint64_t copy_src_qword_4;                  /* 0x00BC */
    uint32_t copy_src_dword_5;                  /* 0x00C4 */
    uint8_t pad_00C8[336];        /* 0x00C8 (336 bytes) */
    uint64_t head_bone_handle;                  /* 0x0218 */
    uint8_t pad_0220[992];        /* 0x0220 (992 bytes) */
    uint32_t weak_point_id;                     /* 0x0600 */
    uint8_t pad_0604[720];        /* 0x0604 (720 bytes) */
    uint32_t timer_base;                        /* 0x08D4 */
    uint32_t unk_08D8;                          /* 0x08D8 */
    uint32_t timer_offset;                      /* 0x08DC */
    uint8_t pad_08E0[22032];      /* 0x08E0 (22032 bytes) */
    uint64_t unk_5EF0;                          /* 0x5EF0 */
    uint8_t pad_5EF8[88];         /* 0x5EF8 (88 bytes) */
    uint64_t unk_5F50;                          /* 0x5F50 */
    uint64_t unk_5F58;                          /* 0x5F58 */
    uint8_t pad_5F60[120];        /* 0x5F60 (120 bytes) */
    uint64_t unk_5FD8;                          /* 0x5FD8 */
    uint64_t unk_5FE0;                          /* 0x5FE0 */
    uint8_t pad_5FE8[436];        /* 0x5FE8 (436 bytes) */
    uint32_t effect_id_0;                       /* 0x619C */
    uint8_t pad_61A0[44];         /* 0x61A0 (44 bytes) */
    uint32_t effect_id_1;                       /* 0x61CC */
    uint8_t pad_61D0[2212];       /* 0x61D0 (2212 bytes) */
    uint64_t ctrl_copy_qword_0;                 /* 0x6A74 */
    uint32_t ctrl_copy_dword_1;                 /* 0x6A7C */
    uint64_t ctrl_copy_qword_2;                 /* 0x6A80 */
    uint32_t ctrl_copy_dword_3;                 /* 0x6A88 */
    uint32_t ctrl_zero_field;                   /* 0x6A8C */
    uint8_t pad_6A90[1552];       /* 0x6A90 (1552 bytes) */
    uint64_t draw_param_buf_ptr;                /* 0x70A0 */
    uint32_t kzu_draw_param_idx;                /* 0x70A8 */
    uint64_t cd210_out_ptr;                     /* 0x70AC */
    float turn_interp_float;                    /* 0x70B4 */
    uint8_t pad_70B8[88];         /* 0x70B8 (88 bytes) */
    uint64_t unk_7110;                          /* 0x7110 */
    uint64_t unk_7118;                          /* 0x7118 */
    uint8_t pad_7120[4];          /* 0x7120 (4 bytes) */
    uint32_t e23_int_copy;                      /* 0x7124 */
    uint8_t pad_7128[152];        /* 0x7128 (152 bytes) */
    uint32_t flags;                             /* 0x71C0 */
    uint32_t init_flag_01;                      /* 0x71C4 */
    uint32_t phase_or_state;                    /* 0x71C8 */
    uint8_t pad_71CC[4];          /* 0x71CC (4 bytes) */
    float float_42480000;                       /* 0x71D0 */
    uint8_t pad_71D4[8];          /* 0x71D4 (8 bytes) */
    uint32_t zero_init_0;                       /* 0x71DC */
    uint8_t pad_71E0[4];          /* 0x71E0 (4 bytes) */
    uint32_t unk_neg1_field;                    /* 0x71E4 */
    uint64_t unk_71E8;                          /* 0x71E8 */
    uint32_t zero_init_1;                       /* 0x71F0 */
    uint8_t pad_71F4[12];         /* 0x71F4 (12 bytes) */
    uint32_t zero_init_2;                       /* 0x7200 */
    uint8_t pad_7204[8];          /* 0x7204 (8 bytes) */
    uint32_t super_armor_timer;                 /* 0x720C */
    uint32_t const_8_field;                     /* 0x7210 */
    uint8_t pad_7214[8];          /* 0x7214 (8 bytes) */
    uint32_t stun_counter;                      /* 0x721C */
    uint8_t pad_7220[59952];      /* 0x7220 (59952 bytes) */
    uint64_t pu5_ptr;                           /* 0x15C50 */
    uint64_t zero_init_tail_0;                  /* 0x15C58 */
    uint64_t tail_counter;                      /* 0x15C60 */
    uint8_t pad_15C68[64];        /* 0x15C68 (64 bytes) */
    uint64_t zero_init_tail_1;                  /* 0x15CA8 */
    uint8_t pad_15CB0[32];        /* 0x15CB0 (32 bytes) */
    uint64_t zero_init_tail_2;                  /* 0x15CD0 */
    uint8_t pad_15CD8[40];        /* 0x15CD8 (40 bytes) */
    uint64_t zero_init_tail_3;                  /* 0x15D00 */
    uint8_t pad_15D08[8];         /* 0x15D08 to 0x15D10 (8 bytes) */
} ccBoss06Kzu03;
#pragma pack(pop)

static_assert(sizeof(ccBoss06Kzu03) == 0x15D10, "ccBoss06Kzu03 size mismatch");

/* Offset verification for every field */
static_assert(offsetof(ccBoss06Kzu03, vtable) == 0x0000, "vtable offset");
static_assert(offsetof(ccBoss06Kzu03, copy_src_qword_0) == 0x00A4, "copy_src_qword_0 offset");
static_assert(offsetof(ccBoss06Kzu03, copy_src_dword_1) == 0x00AC, "copy_src_dword_1 offset");
static_assert(offsetof(ccBoss06Kzu03, copy_src_qword_2) == 0x00B0, "copy_src_qword_2 offset");
static_assert(offsetof(ccBoss06Kzu03, copy_src_dword_3) == 0x00B8, "copy_src_dword_3 offset");
static_assert(offsetof(ccBoss06Kzu03, copy_src_qword_4) == 0x00BC, "copy_src_qword_4 offset");
static_assert(offsetof(ccBoss06Kzu03, copy_src_dword_5) == 0x00C4, "copy_src_dword_5 offset");
static_assert(offsetof(ccBoss06Kzu03, head_bone_handle) == 0x0218, "head_bone_handle offset");
static_assert(offsetof(ccBoss06Kzu03, weak_point_id) == 0x0600, "weak_point_id offset");
static_assert(offsetof(ccBoss06Kzu03, timer_base) == 0x08D4, "timer_base offset");
static_assert(offsetof(ccBoss06Kzu03, unk_08D8) == 0x08D8, "unk_08D8 offset");
static_assert(offsetof(ccBoss06Kzu03, timer_offset) == 0x08DC, "timer_offset offset");
static_assert(offsetof(ccBoss06Kzu03, unk_5EF0) == 0x5EF0, "unk_5EF0 offset");
static_assert(offsetof(ccBoss06Kzu03, unk_5F50) == 0x5F50, "unk_5F50 offset");
static_assert(offsetof(ccBoss06Kzu03, unk_5F58) == 0x5F58, "unk_5F58 offset");
static_assert(offsetof(ccBoss06Kzu03, unk_5FD8) == 0x5FD8, "unk_5FD8 offset");
static_assert(offsetof(ccBoss06Kzu03, unk_5FE0) == 0x5FE0, "unk_5FE0 offset");
static_assert(offsetof(ccBoss06Kzu03, effect_id_0) == 0x619C, "effect_id_0 offset");
static_assert(offsetof(ccBoss06Kzu03, effect_id_1) == 0x61CC, "effect_id_1 offset");
static_assert(offsetof(ccBoss06Kzu03, ctrl_copy_qword_0) == 0x6A74, "ctrl_copy_qword_0 offset");
static_assert(offsetof(ccBoss06Kzu03, ctrl_copy_dword_1) == 0x6A7C, "ctrl_copy_dword_1 offset");
static_assert(offsetof(ccBoss06Kzu03, ctrl_copy_qword_2) == 0x6A80, "ctrl_copy_qword_2 offset");
static_assert(offsetof(ccBoss06Kzu03, ctrl_copy_dword_3) == 0x6A88, "ctrl_copy_dword_3 offset");
static_assert(offsetof(ccBoss06Kzu03, ctrl_zero_field) == 0x6A8C, "ctrl_zero_field offset");
static_assert(offsetof(ccBoss06Kzu03, draw_param_buf_ptr) == 0x70A0, "draw_param_buf_ptr offset");
static_assert(offsetof(ccBoss06Kzu03, kzu_draw_param_idx) == 0x70A8, "kzu_draw_param_idx offset");
static_assert(offsetof(ccBoss06Kzu03, cd210_out_ptr) == 0x70AC, "cd210_out_ptr offset");
static_assert(offsetof(ccBoss06Kzu03, turn_interp_float) == 0x70B4, "turn_interp_float offset");
static_assert(offsetof(ccBoss06Kzu03, unk_7110) == 0x7110, "unk_7110 offset");
static_assert(offsetof(ccBoss06Kzu03, unk_7118) == 0x7118, "unk_7118 offset");
static_assert(offsetof(ccBoss06Kzu03, e23_int_copy) == 0x7124, "e23_int_copy offset");
static_assert(offsetof(ccBoss06Kzu03, flags) == 0x71C0, "flags offset");
static_assert(offsetof(ccBoss06Kzu03, init_flag_01) == 0x71C4, "init_flag_01 offset");
static_assert(offsetof(ccBoss06Kzu03, phase_or_state) == 0x71C8, "phase_or_state offset");
static_assert(offsetof(ccBoss06Kzu03, float_42480000) == 0x71D0, "float_42480000 offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_0) == 0x71DC, "zero_init_0 offset");
static_assert(offsetof(ccBoss06Kzu03, unk_neg1_field) == 0x71E4, "unk_neg1_field offset");
static_assert(offsetof(ccBoss06Kzu03, unk_71E8) == 0x71E8, "unk_71E8 offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_1) == 0x71F0, "zero_init_1 offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_2) == 0x7200, "zero_init_2 offset");
static_assert(offsetof(ccBoss06Kzu03, super_armor_timer) == 0x720C, "super_armor_timer offset");
static_assert(offsetof(ccBoss06Kzu03, const_8_field) == 0x7210, "const_8_field offset");
static_assert(offsetof(ccBoss06Kzu03, stun_counter) == 0x721C, "stun_counter offset");
static_assert(offsetof(ccBoss06Kzu03, pu5_ptr) == 0x15C50, "pu5_ptr offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_tail_0) == 0x15C58, "zero_init_tail_0 offset");
static_assert(offsetof(ccBoss06Kzu03, tail_counter) == 0x15C60, "tail_counter offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_tail_1) == 0x15CA8, "zero_init_tail_1 offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_tail_2) == 0x15CD0, "zero_init_tail_2 offset");
static_assert(offsetof(ccBoss06Kzu03, zero_init_tail_3) == 0x15D00, "zero_init_tail_3 offset");

/* ccSceneBoss06Phase05: no instance state
 * 11 methods analyzed, 0 field accesses found.
 * Methods: ccSceneBoss06Phase05::FinishStepCtrl, ccSceneBoss06Phase05::StartStepCtrl, ccSceneBoss06Phase05::_Initialize, ccSceneBoss06Phase05::Initialize, ccSceneBoss06Phase05::NarutoMoveLimit...
 * Warnings: ccSceneBoss06Phase05::FinishStepCtrl: unknown param_1 element size; only byte-cast accesses used
 * Evidence: all methods use only byte-cast or no param_1 accesses.
 */

/* ccBoss06Kzu03SweepTentacle: size unknown, >= 0x204 (state_surface, 15 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03SweepTentacle {
    uint8_t pad_0000[152]; /* 0x0000 (152 bytes) */
    uint32_t field_0098; /* 0x0098 [medium] rw */
    uint32_t field_009C; /* 0x009C [low] rw */
    uint32_t field_00A0; /* 0x00A0 [medium] w */
    uint32_t field_00A4; /* 0x00A4 [low] r */
    uint8_t pad_00A8[8]; /* 0x00A8 (8 bytes) */
    uint32_t field_00B0; /* 0x00B0 [low] r */
    uint8_t pad_00B4[16]; /* 0x00B4 (16 bytes) */
    uint32_t field_00C4; /* 0x00C4 [low] r */
    uint8_t pad_00C8[64]; /* 0x00C8 (64 bytes) */
    uint64_t field_0108; /* 0x0108 [medium] r */
    uint32_t field_0110; /* 0x0110 [low] r */
    uint8_t pad_0114[8]; /* 0x0114 (8 bytes) */
    uint32_t field_011C; /* 0x011C [high] rw */
    uint64_t field_0120; /* 0x0120 [high] rw */
    uint64_t field_0128; /* 0x0128 [medium] w */
    uint64_t field_0130; /* 0x0130 [medium] w */
    uint32_t field_0138; /* 0x0138 [low] r */
    uint8_t pad_013C[84]; /* 0x013C (84 bytes) */
    uint32_t field_0190; /* 0x0190 [high] rw */
    uint8_t pad_0194[108]; /* 0x0194 (108 bytes) */
    uint32_t field_0200; /* 0x0200 [low] r */
    uint8_t pad_0204[4]; /* 0x0204 to 0x208 (4 bytes) */
} ccBoss06Kzu03SweepTentacle;
#pragma pack(pop)

/* ccBoss06Kzu03SweepTentacle: no sizeof assert — size unknown, >= 0x204 */

static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0098) == 0x0098, "ccBoss06Kzu03SweepTentacle::field_0098 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_009C) == 0x009C, "ccBoss06Kzu03SweepTentacle::field_009C offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_00A0) == 0x00A0, "ccBoss06Kzu03SweepTentacle::field_00A0 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_00A4) == 0x00A4, "ccBoss06Kzu03SweepTentacle::field_00A4 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_00B0) == 0x00B0, "ccBoss06Kzu03SweepTentacle::field_00B0 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_00C4) == 0x00C4, "ccBoss06Kzu03SweepTentacle::field_00C4 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0108) == 0x0108, "ccBoss06Kzu03SweepTentacle::field_0108 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0110) == 0x0110, "ccBoss06Kzu03SweepTentacle::field_0110 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_011C) == 0x011C, "ccBoss06Kzu03SweepTentacle::field_011C offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0120) == 0x0120, "ccBoss06Kzu03SweepTentacle::field_0120 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0128) == 0x0128, "ccBoss06Kzu03SweepTentacle::field_0128 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0130) == 0x0130, "ccBoss06Kzu03SweepTentacle::field_0130 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0138) == 0x0138, "ccBoss06Kzu03SweepTentacle::field_0138 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0190) == 0x0190, "ccBoss06Kzu03SweepTentacle::field_0190 offset");
static_assert(offsetof(ccBoss06Kzu03SweepTentacle, field_0200) == 0x0200, "ccBoss06Kzu03SweepTentacle::field_0200 offset");

/* ccBoss06Kzu03GroundActionState: no instance state
 * 7 methods analyzed, 0 field accesses found.
 * Methods: ccBoss06Kzu03GroundActionState::StateAngryBegin, ccBoss06Kzu03GroundActionState::StateCombo01Loop, ccBoss06Kzu03GroundActionState::EnterStunEnd, ccBoss06Kzu03GroundActionState::CreateUpthrustTentacle, ccBoss06Kzu03GroundActionState::EnterAngryEnd...
 * Warnings: ccBoss06Kzu03GroundActionState::StateAngryBegin: unknown param_1 element size; only byte-cast access
 * Evidence: all methods use only byte-cast or no param_1 accesses.
 */

/* ccBoss06Kzu03Katon00: size unknown, >= 0x15C (state_surface, 11 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03Katon00 {
    uint8_t pad_0000[152]; /* 0x0000 (152 bytes) */
    uint32_t field_0098; /* 0x0098 [low] r */
    uint8_t pad_009C[8]; /* 0x009C (8 bytes) */
    uint32_t field_00A4; /* 0x00A4 [low] r */
    uint8_t pad_00A8[8]; /* 0x00A8 (8 bytes) */
    uint32_t field_00B0; /* 0x00B0 [low] r */
    uint8_t pad_00B4[12]; /* 0x00B4 (12 bytes) */
    uint32_t field_00C0; /* 0x00C0 [low] r */
    uint8_t pad_00C4[84]; /* 0x00C4 (84 bytes) */
    uint32_t field_0118; /* 0x0118 [low] r */
    uint8_t pad_011C[20]; /* 0x011C (20 bytes) */
    uint32_t field_0130; /* 0x0130 [medium] w */
    uint8_t pad_0134[4]; /* 0x0134 (4 bytes) */
    uint64_t field_0138; /* 0x0138 [medium] w */
    uint64_t field_0140; /* 0x0140 [medium] w */
    uint64_t field_0148; /* 0x0148 [medium] w */
    uint64_t field_0150; /* 0x0150 [medium] w */
    uint32_t field_0158; /* 0x0158 [medium] w */
    uint8_t pad_015C[4]; /* 0x015C to 0x160 (4 bytes) */
} ccBoss06Kzu03Katon00;
#pragma pack(pop)

/* ccBoss06Kzu03Katon00: no sizeof assert — size unknown, >= 0x15C */

static_assert(offsetof(ccBoss06Kzu03Katon00, field_0098) == 0x0098, "ccBoss06Kzu03Katon00::field_0098 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_00A4) == 0x00A4, "ccBoss06Kzu03Katon00::field_00A4 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_00B0) == 0x00B0, "ccBoss06Kzu03Katon00::field_00B0 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_00C0) == 0x00C0, "ccBoss06Kzu03Katon00::field_00C0 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0118) == 0x0118, "ccBoss06Kzu03Katon00::field_0118 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0130) == 0x0130, "ccBoss06Kzu03Katon00::field_0130 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0138) == 0x0138, "ccBoss06Kzu03Katon00::field_0138 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0140) == 0x0140, "ccBoss06Kzu03Katon00::field_0140 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0148) == 0x0148, "ccBoss06Kzu03Katon00::field_0148 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0150) == 0x0150, "ccBoss06Kzu03Katon00::field_0150 offset");
static_assert(offsetof(ccBoss06Kzu03Katon00, field_0158) == 0x0158, "ccBoss06Kzu03Katon00::field_0158 offset");

/* ccSceneBoss06Phase01: no instance state
 * 7 methods analyzed, 0 field accesses found.
 * Methods: ccSceneBoss06Phase01::StartStepCtrl, ccSceneBoss06Phase01::_Initialize, ccSceneBoss06Phase01::Initialize, ccSceneBoss06Phase01::Execute, ccSceneBoss06Phase01::_Finalize...
 * Warnings: ccSceneBoss06Phase01::StartStepCtrl: unknown param_1 element size; only byte-cast accesses used
 * Evidence: all methods use only byte-cast or no param_1 accesses.
 */

/* ccSceneBoss06Phase03: no instance state
 * 7 methods analyzed, 0 field accesses found.
 * Methods: ccSceneBoss06Phase03::StartStepCtrl, ccSceneBoss06Phase03::_Initialize, ccSceneBoss06Phase03::Initialize, ccSceneBoss06Phase03::Execute, ccSceneBoss06Phase03::_Finalize...
 * Warnings: ccSceneBoss06Phase03::StartStepCtrl: unknown param_1 element size; only byte-cast accesses used
 * Evidence: all methods use only byte-cast or no param_1 accesses.
 */

/* ccBoss06Kzu03ActionState: size unknown, >= 0xBFEC (state_surface, 11 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03ActionState {
    uint8_t pad_0000[5304]; /* 0x0000 (5304 bytes) */
    uint64_t field_14B8; /* 0x14B8 [low] rw */
    uint8_t pad_14C0[968]; /* 0x14C0 (968 bytes) */
    uint64_t field_1888; /* 0x1888 [low] rw */
    uint8_t pad_1890[96]; /* 0x1890 (96 bytes) */
    uint32_t field_18F0; /* 0x18F0 [low] r */
    uint8_t pad_18F4[5316]; /* 0x18F4 (5316 bytes) */
    uint32_t field_2DB8; /* 0x2DB8 [low] r */
    uint8_t pad_2DBC[5316]; /* 0x2DBC (5316 bytes) */
    uint32_t field_4280; /* 0x4280 [low] r */
    uint8_t pad_4284[5316]; /* 0x4284 (5316 bytes) */
    uint32_t field_5748; /* 0x5748 [low] r */
    uint8_t pad_574C[5316]; /* 0x574C (5316 bytes) */
    uint32_t field_6C10; /* 0x6C10 [low] r */
    uint8_t pad_6C14[5316]; /* 0x6C14 (5316 bytes) */
    uint32_t field_80D8; /* 0x80D8 [low] r */
    uint8_t pad_80DC[5316]; /* 0x80DC (5316 bytes) */
    uint32_t field_95A0; /* 0x95A0 [low] r */
    uint8_t pad_95A4[5500]; /* 0x95A4 (5500 bytes) */
    uint32_t field_AB20; /* 0xAB20 [low] r */
    uint8_t pad_AB24[5316]; /* 0xAB24 (5316 bytes) */
    uint32_t field_BFE8; /* 0xBFE8 [low] r */
    uint8_t pad_BFEC[4]; /* 0xBFEC to 0xBFF0 (4 bytes) */
} ccBoss06Kzu03ActionState;
#pragma pack(pop)

/* ccBoss06Kzu03ActionState: no sizeof assert — size unknown, >= 0xBFEC */

static_assert(offsetof(ccBoss06Kzu03ActionState, field_14B8) == 0x14B8, "ccBoss06Kzu03ActionState::field_14B8 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_1888) == 0x1888, "ccBoss06Kzu03ActionState::field_1888 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_18F0) == 0x18F0, "ccBoss06Kzu03ActionState::field_18F0 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_2DB8) == 0x2DB8, "ccBoss06Kzu03ActionState::field_2DB8 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_4280) == 0x4280, "ccBoss06Kzu03ActionState::field_4280 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_5748) == 0x5748, "ccBoss06Kzu03ActionState::field_5748 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_6C10) == 0x6C10, "ccBoss06Kzu03ActionState::field_6C10 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_80D8) == 0x80D8, "ccBoss06Kzu03ActionState::field_80D8 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_95A0) == 0x95A0, "ccBoss06Kzu03ActionState::field_95A0 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_AB20) == 0xAB20, "ccBoss06Kzu03ActionState::field_AB20 offset");
static_assert(offsetof(ccBoss06Kzu03ActionState, field_BFE8) == 0xBFE8, "ccBoss06Kzu03ActionState::field_BFE8 offset");

/* ccBoss06Kzu03Beam: size unknown, >= 0x204 (state_surface, 13 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03Beam {
    uint8_t pad_0000[152]; /* 0x0000 (152 bytes) */
    uint64_t field_0098; /* 0x0098 [low] rw */
    uint32_t field_00A0; /* 0x00A0 [medium] w */
    uint32_t field_00A4; /* 0x00A4 [low] r */
    uint8_t pad_00A8[8]; /* 0x00A8 (8 bytes) */
    uint32_t field_00B0; /* 0x00B0 [low] r */
    uint8_t pad_00B4[12]; /* 0x00B4 (12 bytes) */
    uint32_t field_00C0; /* 0x00C0 [medium] w */
    uint32_t field_00C4; /* 0x00C4 [low] r */
    uint8_t pad_00C8[68]; /* 0x00C8 (68 bytes) */
    uint32_t field_010C; /* 0x010C [high] rw */
    uint64_t field_0110; /* 0x0110 [high] rw */
    uint64_t field_0118; /* 0x0118 [medium] w */
    uint64_t field_0120; /* 0x0120 [medium] w */
    uint32_t field_0128; /* 0x0128 [low] r */
    uint8_t pad_012C[156]; /* 0x012C (156 bytes) */
    uint32_t field_01C8; /* 0x01C8 [high] rw */
    uint8_t pad_01CC[52]; /* 0x01CC (52 bytes) */
    uint32_t field_0200; /* 0x0200 [low] r */
    uint8_t pad_0204[4]; /* 0x0204 to 0x208 (4 bytes) */
} ccBoss06Kzu03Beam;
#pragma pack(pop)

/* ccBoss06Kzu03Beam: no sizeof assert — size unknown, >= 0x204 */

static_assert(offsetof(ccBoss06Kzu03Beam, field_0098) == 0x0098, "ccBoss06Kzu03Beam::field_0098 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_00A0) == 0x00A0, "ccBoss06Kzu03Beam::field_00A0 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_00A4) == 0x00A4, "ccBoss06Kzu03Beam::field_00A4 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_00B0) == 0x00B0, "ccBoss06Kzu03Beam::field_00B0 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_00C0) == 0x00C0, "ccBoss06Kzu03Beam::field_00C0 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_00C4) == 0x00C4, "ccBoss06Kzu03Beam::field_00C4 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_010C) == 0x010C, "ccBoss06Kzu03Beam::field_010C offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_0110) == 0x0110, "ccBoss06Kzu03Beam::field_0110 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_0118) == 0x0118, "ccBoss06Kzu03Beam::field_0118 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_0120) == 0x0120, "ccBoss06Kzu03Beam::field_0120 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_0128) == 0x0128, "ccBoss06Kzu03Beam::field_0128 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_01C8) == 0x01C8, "ccBoss06Kzu03Beam::field_01C8 offset");
static_assert(offsetof(ccBoss06Kzu03Beam, field_0200) == 0x0200, "ccBoss06Kzu03Beam::field_0200 offset");

/* ccBoss06Kzu03GroundAI: no instance state
 * 6 methods analyzed, 0 field accesses found.
 * Methods: ccBoss06Kzu03GroundAI::SetKakuzuAction, ccBoss06Kzu03GroundAI::Initialize, ccBoss06Kzu03GroundAI::SelectAttackAction, ccBoss06Kzu03GroundAI::SelectGetAwayAction, ccBoss06Kzu03GroundAI::CallNormalAction...
 * Warnings: ccBoss06Kzu03GroundAI::SetKakuzuAction: unknown param_1 element size; only byte-cast accesses used
 * Evidence: all methods use only byte-cast or no param_1 accesses.
 */

/* ccBoss06Kzu03Huuton00: size unknown, >= 0x13C (state_surface, 10 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03Huuton00 {
    uint8_t pad_0000[152]; /* 0x0000 (152 bytes) */
    uint32_t field_0098; /* 0x0098 [low] r */
    uint8_t pad_009C[8]; /* 0x009C (8 bytes) */
    uint32_t field_00A4; /* 0x00A4 [low] r */
    uint8_t pad_00A8[8]; /* 0x00A8 (8 bytes) */
    uint32_t field_00B0; /* 0x00B0 [low] r */
    uint8_t pad_00B4[84]; /* 0x00B4 (84 bytes) */
    uint32_t field_0108; /* 0x0108 [low] r */
    uint8_t pad_010C[8]; /* 0x010C (8 bytes) */
    uint32_t field_0114; /* 0x0114 [medium] w */
    uint64_t field_0118; /* 0x0118 [medium] w */
    uint64_t field_0120; /* 0x0120 [medium] w */
    uint64_t field_0128; /* 0x0128 [medium] w */
    uint64_t field_0130; /* 0x0130 [medium] w */
    uint32_t field_0138; /* 0x0138 [medium] w */
    uint8_t pad_013C[4]; /* 0x013C to 0x140 (4 bytes) */
} ccBoss06Kzu03Huuton00;
#pragma pack(pop)

/* ccBoss06Kzu03Huuton00: no sizeof assert — size unknown, >= 0x13C */

static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0098) == 0x0098, "ccBoss06Kzu03Huuton00::field_0098 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_00A4) == 0x00A4, "ccBoss06Kzu03Huuton00::field_00A4 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_00B0) == 0x00B0, "ccBoss06Kzu03Huuton00::field_00B0 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0108) == 0x0108, "ccBoss06Kzu03Huuton00::field_0108 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0114) == 0x0114, "ccBoss06Kzu03Huuton00::field_0114 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0118) == 0x0118, "ccBoss06Kzu03Huuton00::field_0118 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0120) == 0x0120, "ccBoss06Kzu03Huuton00::field_0120 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0128) == 0x0128, "ccBoss06Kzu03Huuton00::field_0128 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0130) == 0x0130, "ccBoss06Kzu03Huuton00::field_0130 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton00, field_0138) == 0x0138, "ccBoss06Kzu03Huuton00::field_0138 offset");

/* ccBoss06Kzu03Huuton01: size unknown, >= 0x204 (state_surface, 13 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03Huuton01 {
    uint8_t pad_0000[152]; /* 0x0000 (152 bytes) */
    uint32_t field_0098; /* 0x0098 [low] r */
    uint8_t pad_009C[4]; /* 0x009C (4 bytes) */
    uint32_t field_00A0; /* 0x00A0 [medium] w */
    uint32_t field_00A4; /* 0x00A4 [low] r */
    uint8_t pad_00A8[8]; /* 0x00A8 (8 bytes) */
    uint32_t field_00B0; /* 0x00B0 [low] r */
    uint8_t pad_00B4[16]; /* 0x00B4 (16 bytes) */
    uint32_t field_00C4; /* 0x00C4 [low] r */
    uint8_t pad_00C8[64]; /* 0x00C8 (64 bytes) */
    float field_0108; /* 0x0108 [high] rw */
    uint8_t pad_010C[4]; /* 0x010C (4 bytes) */
    uint64_t field_0110; /* 0x0110 [high] rw */
    uint64_t field_0118; /* 0x0118 [medium] w */
    uint64_t field_0120; /* 0x0120 [medium] w */
    uint64_t field_0128; /* 0x0128 [medium] w */
    uint64_t field_0130; /* 0x0130 [medium] w */
    uint32_t field_0138; /* 0x0138 [high] rw */
    uint8_t pad_013C[196]; /* 0x013C (196 bytes) */
    uint32_t field_0200; /* 0x0200 [low] r */
    uint8_t pad_0204[4]; /* 0x0204 to 0x208 (4 bytes) */
} ccBoss06Kzu03Huuton01;
#pragma pack(pop)

/* ccBoss06Kzu03Huuton01: no sizeof assert — size unknown, >= 0x204 */

static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0098) == 0x0098, "ccBoss06Kzu03Huuton01::field_0098 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_00A0) == 0x00A0, "ccBoss06Kzu03Huuton01::field_00A0 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_00A4) == 0x00A4, "ccBoss06Kzu03Huuton01::field_00A4 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_00B0) == 0x00B0, "ccBoss06Kzu03Huuton01::field_00B0 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_00C4) == 0x00C4, "ccBoss06Kzu03Huuton01::field_00C4 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0108) == 0x0108, "ccBoss06Kzu03Huuton01::field_0108 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0110) == 0x0110, "ccBoss06Kzu03Huuton01::field_0110 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0118) == 0x0118, "ccBoss06Kzu03Huuton01::field_0118 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0120) == 0x0120, "ccBoss06Kzu03Huuton01::field_0120 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0128) == 0x0128, "ccBoss06Kzu03Huuton01::field_0128 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0130) == 0x0130, "ccBoss06Kzu03Huuton01::field_0130 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0138) == 0x0138, "ccBoss06Kzu03Huuton01::field_0138 offset");
static_assert(offsetof(ccBoss06Kzu03Huuton01, field_0200) == 0x0200, "ccBoss06Kzu03Huuton01::field_0200 offset");

/* ccBoss06Kzu03TentacleActionState: size unknown, >= 0x5324 (state_surface, 4 fields inferred) */
#pragma pack(push, 1)
typedef struct ccBoss06Kzu03TentacleActionState {
    uint8_t pad_0000[5304]; /* 0x0000 (5304 bytes) */
    uint32_t field_14B8; /* 0x14B8 [low] r */
    uint8_t pad_14BC[5316]; /* 0x14BC (5316 bytes) */
    uint32_t field_2980; /* 0x2980 [low] r */
    uint8_t pad_2984[5316]; /* 0x2984 (5316 bytes) */
    uint32_t field_3E48; /* 0x3E48 [low] r */
    uint8_t pad_3E4C[5332]; /* 0x3E4C (5332 bytes) */
    uint32_t field_5320; /* 0x5320 [low] r */
    uint8_t pad_5324[4]; /* 0x5324 to 0x5328 (4 bytes) */
} ccBoss06Kzu03TentacleActionState;
#pragma pack(pop)

/* ccBoss06Kzu03TentacleActionState: no sizeof assert — size unknown, >= 0x5324 */

static_assert(offsetof(ccBoss06Kzu03TentacleActionState, field_14B8) == 0x14B8, "ccBoss06Kzu03TentacleActionState::field_14B8 offset");
static_assert(offsetof(ccBoss06Kzu03TentacleActionState, field_2980) == 0x2980, "ccBoss06Kzu03TentacleActionState::field_2980 offset");
static_assert(offsetof(ccBoss06Kzu03TentacleActionState, field_3E48) == 0x3E48, "ccBoss06Kzu03TentacleActionState::field_3E48 offset");
static_assert(offsetof(ccBoss06Kzu03TentacleActionState, field_5320) == 0x5320, "ccBoss06Kzu03TentacleActionState::field_5320 offset");


/* ccBoss06Kzu03Tentacle00: size unknown, >= 0xC468 */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03Tentacle00 {
    uint8_t pad_0x0000[0x6FD8]; /* padding to 0x6FD8 */
    uint8_t sub_obj_0x6FD8; /* size unknown at 0x6FD8 */
    uint8_t pad_0x6FD9[0xB]; /* padding to 0x6FE4 */
    uint8_t sub_obj_0x6FE4; /* size unknown at 0x6FE4 */
    uint8_t pad_0x6FE5[0xB]; /* padding to 0x6FF0 */
    uint8_t sub_obj_0x6FF0; /* size unknown at 0x6FF0 */
    uint8_t pad_0x6FF1[0xF]; /* padding to 0x7000 */
    uint8_t sub_obj_0x7000; /* size unknown at 0x7000 */
    uint8_t pad_0x7001[0x57]; /* padding to 0x7058 */
    uint8_t sub_obj_0x7058; /* size unknown at 0x7058 */
    uint8_t pad_0x7059[0x3F]; /* padding to 0x7098 */
    uint32_t field_0x7098;
    uint32_t field_0x709C;
    uint8_t pad_0x70A0[0x8]; /* padding to 0x70A8 */
    uint8_t sub_obj_0x70A8; /* size unknown at 0x70A8 */
    uint8_t pad_0x70A9[0x539F]; /* padding to 0xC448 */
    uint64_t field_0xC448;
    uint64_t field_0xC450;
    uint64_t field_0xC458;
    uint64_t field_0xC460;
} ns2_ccBoss06Kzu03Tentacle00;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, sub_obj_0x6FD8) == 0x6FD8, "ccBoss06Kzu03Tentacle00.sub_obj_0x6FD8");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, sub_obj_0x6FE4) == 0x6FE4, "ccBoss06Kzu03Tentacle00.sub_obj_0x6FE4");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, sub_obj_0x6FF0) == 0x6FF0, "ccBoss06Kzu03Tentacle00.sub_obj_0x6FF0");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, sub_obj_0x7000) == 0x7000, "ccBoss06Kzu03Tentacle00.sub_obj_0x7000");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, sub_obj_0x7058) == 0x7058, "ccBoss06Kzu03Tentacle00.sub_obj_0x7058");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, field_0x7098) == 0x7098, "ccBoss06Kzu03Tentacle00.field_0x7098");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, field_0x709C) == 0x709C, "ccBoss06Kzu03Tentacle00.field_0x709C");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, sub_obj_0x70A8) == 0x70A8, "ccBoss06Kzu03Tentacle00.sub_obj_0x70A8");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, field_0xC448) == 0xC448, "ccBoss06Kzu03Tentacle00.field_0xC448");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, field_0xC450) == 0xC450, "ccBoss06Kzu03Tentacle00.field_0xC450");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, field_0xC458) == 0xC458, "ccBoss06Kzu03Tentacle00.field_0xC458");
static_assert(offsetof(ns2_ccBoss06Kzu03Tentacle00, field_0xC460) == 0xC460, "ccBoss06Kzu03Tentacle00.field_0xC460");


/* ccBoss06Kzu03UpthrustTentacle: size unknown, >= 0x208 */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03UpthrustTentacle {
    uint8_t pad_0x0000[0x98]; /* padding to 0x98 */
    uint8_t sub_obj_0x0098; /* size unknown at 0x98 */
    uint8_t pad_0x0099[0xB]; /* padding to 0xA4 */
    uint8_t sub_obj_0x00A4; /* size unknown at 0xA4 */
    uint8_t pad_0x00A5[0xB]; /* padding to 0xB0 */
    uint8_t sub_obj_0x00B0; /* size unknown at 0xB0 */
    uint8_t pad_0x00B1[0x13]; /* padding to 0xC4 */
    uint8_t sub_obj_0x00C4; /* size unknown at 0xC4 */
    uint8_t pad_0x00C5[0x43]; /* padding to 0x108 */
    uint32_t field_0x0108;
    uint32_t field_0x010C;
    uint64_t sub_obj_0x0110;
    uint32_t field_0x0118;
    uint8_t pad_0x011C[0x4]; /* padding to 0x120 */
    uint64_t field_0x0120;
    uint64_t field_0x0128;
    uint64_t field_0x0130;
    uint64_t field_0x0138;
    uint64_t field_0x0140;
    uint64_t field_0x0148;
    uint32_t field_0x0150;
    uint8_t pad_0x0154[0xAC]; /* padding to 0x200 */
    uint8_t vfunc_0x0200; /* size unknown at 0x200 */
} ns2_ccBoss06Kzu03UpthrustTentacle;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, sub_obj_0x0098) == 0x98, "ccBoss06Kzu03UpthrustTentacle.sub_obj_0x0098");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, sub_obj_0x00A4) == 0xA4, "ccBoss06Kzu03UpthrustTentacle.sub_obj_0x00A4");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, sub_obj_0x00B0) == 0xB0, "ccBoss06Kzu03UpthrustTentacle.sub_obj_0x00B0");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, sub_obj_0x00C4) == 0xC4, "ccBoss06Kzu03UpthrustTentacle.sub_obj_0x00C4");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0108) == 0x108, "ccBoss06Kzu03UpthrustTentacle.field_0x0108");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x010C) == 0x10C, "ccBoss06Kzu03UpthrustTentacle.field_0x010C");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, sub_obj_0x0110) == 0x110, "ccBoss06Kzu03UpthrustTentacle.sub_obj_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0118) == 0x118, "ccBoss06Kzu03UpthrustTentacle.field_0x0118");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0120) == 0x120, "ccBoss06Kzu03UpthrustTentacle.field_0x0120");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0128) == 0x128, "ccBoss06Kzu03UpthrustTentacle.field_0x0128");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0130) == 0x130, "ccBoss06Kzu03UpthrustTentacle.field_0x0130");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0138) == 0x138, "ccBoss06Kzu03UpthrustTentacle.field_0x0138");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0140) == 0x140, "ccBoss06Kzu03UpthrustTentacle.field_0x0140");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0148) == 0x148, "ccBoss06Kzu03UpthrustTentacle.field_0x0148");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, field_0x0150) == 0x150, "ccBoss06Kzu03UpthrustTentacle.field_0x0150");
static_assert(offsetof(ns2_ccBoss06Kzu03UpthrustTentacle, vfunc_0x0200) == 0x200, "ccBoss06Kzu03UpthrustTentacle.vfunc_0x0200");


/* ccBoss06Kzu03HuutonManager: no instance state (0 field accesses across 5 methods) */


/* ccBoss06Kzu03ReturnTentacle: size unknown, >= 0x208 */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03ReturnTentacle {
    uint8_t pad_0x0000[0x98]; /* padding to 0x98 */
    uint8_t sub_obj_0x0098; /* size unknown at 0x98 */
    uint8_t pad_0x0099[0xF]; /* padding to 0xA8 */
    uint8_t sub_obj_0x00A8; /* size unknown at 0xA8 */
    uint8_t pad_0x00A9[0x13]; /* padding to 0xBC */
    uint8_t sub_obj_0x00BC; /* size unknown at 0xBC */
    uint8_t pad_0x00BD[0x43]; /* padding to 0x100 */
    uint32_t field_0x0100;
    uint8_t pad_0x0104[0x4]; /* padding to 0x108 */
    uint64_t sub_obj_0x0108;
    uint64_t field_0x0110;
    uint64_t field_0x0118;
    uint8_t pad_0x0120; /* size unknown at 0x120 */
    uint8_t pad_0x0121[0x27]; /* padding to 0x148 */
    uint32_t field_0x0148;
    uint8_t pad_0x014C[0xB4]; /* padding to 0x200 */
    uint8_t vfunc_0x0200; /* size unknown at 0x200 */
} ns2_ccBoss06Kzu03ReturnTentacle;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, sub_obj_0x0098) == 0x98, "ccBoss06Kzu03ReturnTentacle.sub_obj_0x0098");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, sub_obj_0x00A8) == 0xA8, "ccBoss06Kzu03ReturnTentacle.sub_obj_0x00A8");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, sub_obj_0x00BC) == 0xBC, "ccBoss06Kzu03ReturnTentacle.sub_obj_0x00BC");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, field_0x0100) == 0x100, "ccBoss06Kzu03ReturnTentacle.field_0x0100");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, sub_obj_0x0108) == 0x108, "ccBoss06Kzu03ReturnTentacle.sub_obj_0x0108");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, field_0x0110) == 0x110, "ccBoss06Kzu03ReturnTentacle.field_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, field_0x0118) == 0x118, "ccBoss06Kzu03ReturnTentacle.field_0x0118");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, pad_0x0120) == 0x120, "ccBoss06Kzu03ReturnTentacle.pad_0x0120");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, field_0x0148) == 0x148, "ccBoss06Kzu03ReturnTentacle.field_0x0148");
static_assert(offsetof(ns2_ccBoss06Kzu03ReturnTentacle, vfunc_0x0200) == 0x200, "ccBoss06Kzu03ReturnTentacle.vfunc_0x0200");


/* ccBoss06Kzu03UpthrustActionState: no instance state (0 field accesses across 5 methods) */


/* ccBoss06Kzu03KatonManager: no instance state (0 field accesses across 4 methods) */


/* ccBoss06Kzu03SceneChangeState: size unknown, >= 0x14CC */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03SceneChangeState {
    uint8_t pad_0x0000[0x14B8]; /* padding to 0x14B8 */
    uint64_t field_0x14B8;
    uint64_t field_0x14C0;
    uint32_t field_0x14C8;
} ns2_ccBoss06Kzu03SceneChangeState;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03SceneChangeState, field_0x14B8) == 0x14B8, "ccBoss06Kzu03SceneChangeState.field_0x14B8");
static_assert(offsetof(ns2_ccBoss06Kzu03SceneChangeState, field_0x14C0) == 0x14C0, "ccBoss06Kzu03SceneChangeState.field_0x14C0");
static_assert(offsetof(ns2_ccBoss06Kzu03SceneChangeState, field_0x14C8) == 0x14C8, "ccBoss06Kzu03SceneChangeState.field_0x14C8");


/* ccBoss06Kzu03SlamTentacle: size unknown, >= 0x18C */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03SlamTentacle {
    uint8_t pad_0x0000[0xA8]; /* padding to 0xA8 */
    uint8_t sub_obj_0x00A8; /* size unknown at 0xA8 */
    uint8_t pad_0x00A9[0xF]; /* padding to 0xB8 */
    uint8_t sub_obj_0x00B8; /* size unknown at 0xB8 */
    uint8_t pad_0x00B9[0x57]; /* padding to 0x110 */
    uint32_t field_0x0110;
    uint8_t pad_0x0114[0x4]; /* padding to 0x118 */
    uint64_t field_0x0118;
    uint64_t field_0x0120;
    uint64_t field_0x0128;
    uint8_t pad_0x0130; /* size unknown at 0x130 */
    uint8_t pad_0x0131[0x57]; /* padding to 0x188 */
    uint32_t field_0x0188;
} ns2_ccBoss06Kzu03SlamTentacle;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, sub_obj_0x00A8) == 0xA8, "ccBoss06Kzu03SlamTentacle.sub_obj_0x00A8");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, sub_obj_0x00B8) == 0xB8, "ccBoss06Kzu03SlamTentacle.sub_obj_0x00B8");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, field_0x0110) == 0x110, "ccBoss06Kzu03SlamTentacle.field_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, field_0x0118) == 0x118, "ccBoss06Kzu03SlamTentacle.field_0x0118");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, field_0x0120) == 0x120, "ccBoss06Kzu03SlamTentacle.field_0x0120");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, field_0x0128) == 0x128, "ccBoss06Kzu03SlamTentacle.field_0x0128");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, pad_0x0130) == 0x130, "ccBoss06Kzu03SlamTentacle.pad_0x0130");
static_assert(offsetof(ns2_ccBoss06Kzu03SlamTentacle, field_0x0188) == 0x188, "ccBoss06Kzu03SlamTentacle.field_0x0188");


/* ccBoss06Kzu03StingTentacle: size unknown, >= 0x1F4 */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03StingTentacle {
    uint8_t pad_0x0000[0x98]; /* padding to 0x98 */
    uint8_t sub_obj_0x0098; /* size unknown at 0x98 */
    uint8_t pad_0x0099[0xB]; /* padding to 0xA4 */
    uint8_t sub_obj_0x00A4; /* size unknown at 0xA4 */
    uint8_t pad_0x00A5[0xB]; /* padding to 0xB0 */
    uint8_t sub_obj_0x00B0; /* size unknown at 0xB0 */
    uint8_t pad_0x00B1[0x5F]; /* padding to 0x110 */
    uint32_t field_0x0110;
    uint8_t pad_0x0114[0xC]; /* padding to 0x120 */
    uint64_t field_0x0120;
    uint8_t pad_0x0128[0x98]; /* padding to 0x1C0 */
    uint64_t field_0x01C0;
    uint64_t field_0x01C8;
    uint64_t field_0x01D0;
    uint64_t field_0x01D8;
    uint64_t field_0x01E0;
    uint64_t field_0x01E8;
    uint32_t field_0x01F0;
} ns2_ccBoss06Kzu03StingTentacle;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, sub_obj_0x0098) == 0x98, "ccBoss06Kzu03StingTentacle.sub_obj_0x0098");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, sub_obj_0x00A4) == 0xA4, "ccBoss06Kzu03StingTentacle.sub_obj_0x00A4");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, sub_obj_0x00B0) == 0xB0, "ccBoss06Kzu03StingTentacle.sub_obj_0x00B0");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x0110) == 0x110, "ccBoss06Kzu03StingTentacle.field_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x0120) == 0x120, "ccBoss06Kzu03StingTentacle.field_0x0120");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01C0) == 0x1C0, "ccBoss06Kzu03StingTentacle.field_0x01C0");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01C8) == 0x1C8, "ccBoss06Kzu03StingTentacle.field_0x01C8");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01D0) == 0x1D0, "ccBoss06Kzu03StingTentacle.field_0x01D0");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01D8) == 0x1D8, "ccBoss06Kzu03StingTentacle.field_0x01D8");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01E0) == 0x1E0, "ccBoss06Kzu03StingTentacle.field_0x01E0");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01E8) == 0x1E8, "ccBoss06Kzu03StingTentacle.field_0x01E8");
static_assert(offsetof(ns2_ccBoss06Kzu03StingTentacle, field_0x01F0) == 0x1F0, "ccBoss06Kzu03StingTentacle.field_0x01F0");


/* ccCameraJudgeBoss06Kzu03: size unknown, >= 0x108 */
#pragma pack(push, 1)
typedef struct ns2_ccCameraJudgeBoss06Kzu03 {
    uint8_t pad_0x0000[0x100]; /* padding to 0x100 */
    uint8_t vfunc_0x0100; /* size unknown at 0x100 */
} ns2_ccCameraJudgeBoss06Kzu03;
#pragma pack(pop)

static_assert(offsetof(ns2_ccCameraJudgeBoss06Kzu03, vfunc_0x0100) == 0x100, "ccCameraJudgeBoss06Kzu03.vfunc_0x0100");


/* ccBoss06Kzu03GroundEffect: size unknown, >= 0x208 */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03GroundEffect {
    uint8_t pad_0x0000[0x98]; /* padding to 0x98 */
    uint8_t sub_obj_0x0098; /* size unknown at 0x98 */
    uint8_t pad_0x0099[0x7]; /* padding to 0xA0 */
    uint32_t field_0x00A0;
    uint8_t pad_0x00A4[0x4]; /* padding to 0xA8 */
    uint8_t sub_obj_0x00A8; /* size unknown at 0xA8 */
    uint8_t pad_0x00A9[0x13]; /* padding to 0xBC */
    uint8_t sub_obj_0x00BC; /* size unknown at 0xBC */
    uint8_t pad_0x00BD[0x43]; /* padding to 0x100 */
    uint32_t field_0x0100;
    uint8_t pad_0x0104[0x4]; /* padding to 0x108 */
    uint64_t field_0x0108;
    uint64_t field_0x0110;
    uint64_t field_0x0118;
    uint8_t pad_0x0120[0xE0]; /* padding to 0x200 */
    uint8_t vfunc_0x0200; /* size unknown at 0x200 */
} ns2_ccBoss06Kzu03GroundEffect;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, sub_obj_0x0098) == 0x98, "ccBoss06Kzu03GroundEffect.sub_obj_0x0098");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, field_0x00A0) == 0xA0, "ccBoss06Kzu03GroundEffect.field_0x00A0");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, sub_obj_0x00A8) == 0xA8, "ccBoss06Kzu03GroundEffect.sub_obj_0x00A8");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, sub_obj_0x00BC) == 0xBC, "ccBoss06Kzu03GroundEffect.sub_obj_0x00BC");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, field_0x0100) == 0x100, "ccBoss06Kzu03GroundEffect.field_0x0100");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, field_0x0108) == 0x108, "ccBoss06Kzu03GroundEffect.field_0x0108");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, field_0x0110) == 0x110, "ccBoss06Kzu03GroundEffect.field_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, field_0x0118) == 0x118, "ccBoss06Kzu03GroundEffect.field_0x0118");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundEffect, vfunc_0x0200) == 0x200, "ccBoss06Kzu03GroundEffect.vfunc_0x0200");


/* ccBoss06Kzu03GroundRaisingTentacle: size unknown, >= 0x13C */
#pragma pack(push, 1)
typedef struct ns2_ccBoss06Kzu03GroundRaisingTentacle {
    uint8_t pad_0x0000[0x98]; /* padding to 0x98 */
    uint8_t sub_obj_0x0098; /* size unknown at 0x98 */
    uint8_t pad_0x0099[0xB]; /* padding to 0xA4 */
    uint8_t sub_obj_0x00A4; /* size unknown at 0xA4 */
    uint8_t pad_0x00A5[0xB]; /* padding to 0xB0 */
    uint8_t sub_obj_0x00B0; /* size unknown at 0xB0 */
    uint8_t pad_0x00B1[0x57]; /* padding to 0x108 */
    uint32_t field_0x0108;
    uint8_t pad_0x010C[0x4]; /* padding to 0x110 */
    uint64_t field_0x0110;
    uint32_t field_0x0118;
    uint8_t pad_0x011C[0x4]; /* padding to 0x120 */
    uint64_t field_0x0120;
    uint64_t field_0x0128;
    uint64_t field_0x0130;
    uint32_t field_0x0138;
} ns2_ccBoss06Kzu03GroundRaisingTentacle;
#pragma pack(pop)

static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, sub_obj_0x0098) == 0x98, "ccBoss06Kzu03GroundRaisingTentacle.sub_obj_0x0098");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, sub_obj_0x00A4) == 0xA4, "ccBoss06Kzu03GroundRaisingTentacle.sub_obj_0x00A4");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, sub_obj_0x00B0) == 0xB0, "ccBoss06Kzu03GroundRaisingTentacle.sub_obj_0x00B0");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0108) == 0x108, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0108");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0110) == 0x110, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0118) == 0x118, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0118");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0120) == 0x120, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0120");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0128) == 0x128, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0128");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0130) == 0x130, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0130");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundRaisingTentacle, field_0x0138) == 0x138, "ccBoss06Kzu03GroundRaisingTentacle.field_0x0138");

/* ccBoss06VoicePlayer: no instance state found.
 * state_surface over ccBoss06VoicePlayer::ccBoss06VoicePlayer,
 * ccBoss06VoicePlayer::~ccBoss06VoicePlayer, ccBoss06VoicePlayer::Play
 * returned 0 field accesses. Class is likely a static/singleton voice dispatcher. */

#pragma pack(push, 1)
typedef struct {
    uint8_t pad_0x0000[0x98];
    void *sub_obj_0x0098;
    uint8_t pad_0x00A0[4];
    void *sub_obj_0x00A4;
    uint8_t pad_0x00AC[4];
    void *sub_obj_0x00B0;
    uint8_t pad_0x00B8[0x50];
    uint64_t field_0x0108;
    uint64_t field_0x0110;
    uint64_t field_0x0118;
    uint64_t field_0x0120;
    uint64_t field_0x0128;
    uint64_t field_0x0130;
    uint64_t field_0x0138;
    uint64_t field_0x0140;
    uint32_t field_0x0148;
    uint8_t pad_0x014C[4];
} ns2_ccBoss06Kzu03GroundUpthrustTentacle;
#pragma pack(pop)

static_assert(sizeof(ns2_ccBoss06Kzu03GroundUpthrustTentacle) == 0x150, "ccBoss06Kzu03GroundUpthrustTentacle size");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, sub_obj_0x0098) == 0x98, "ccBoss06Kzu03GroundUpthrustTentacle.sub_obj_0x0098");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, sub_obj_0x00A4) == 0xA4, "ccBoss06Kzu03GroundUpthrustTentacle.sub_obj_0x00A4");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, sub_obj_0x00B0) == 0xB0, "ccBoss06Kzu03GroundUpthrustTentacle.sub_obj_0x00B0");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0108) == 0x108, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0108");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0110) == 0x110, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0110");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0118) == 0x118, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0118");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0120) == 0x120, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0120");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0128) == 0x128, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0128");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0130) == 0x130, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0130");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0138) == 0x138, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0138");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0140) == 0x140, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0140");
static_assert(offsetof(ns2_ccBoss06Kzu03GroundUpthrustTentacle, field_0x0148) == 0x148, "ccBoss06Kzu03GroundUpthrustTentacle.field_0x0148");

#endif /* S2_BOSS06_H */
