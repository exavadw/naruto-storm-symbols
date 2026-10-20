/* st3a16.h - Story progression struct layouts for NARUTO STORM 3 Full Burst HD (s3/NSUNS3.exe x64)
 *
 * All layouts are INFERRED from static decompilation, not CONFIRMED at runtime.
 * Object sizes are unproven unless noted; structs end at last known field.
 * Generated from the decompiler cache state_surface + manual field extraction.
 */

#ifndef ST3A16_H
#define ST3A16_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* cc_scene_adv_start_menu_tutorial_t: no instance state detected — all 4 methods use only
 * local variables or pass param_1 through without offset dereferences.
 * Evidence: state_surface returned 0 fields; field-extract grep found 0 param_1+offset patterns.
 */
typedef struct cc_scene_adv_start_menu_tutorial_t { uint8_t _placeholder; } cc_scene_adv_start_menu_tutorial_t;

/* ccSceneAdvTeamOrganize — inferred layout, size unknown >= 0x130 */
typedef struct cc_scene_adv_team_organize_t {
    uint8_t _pad_0x0[296];
    uint64_t field_0x128; /* 0x128 */
} cc_scene_adv_team_organize_t;

static_assert(offsetof(cc_scene_adv_team_organize_t, field_0x128) == 0x128, "cc_scene_adv_team_organize_t.field_0x128 offset mismatch");

/* ccSceneAdvVSLoading — inferred layout, size unknown >= 0x7A8 */
typedef struct cc_scene_adv_vs_loading_t {
    uint8_t _pad_0x0[1952];
    uint64_t field_0x7A0; /* 0x7A0 */
} cc_scene_adv_vs_loading_t;

static_assert(offsetof(cc_scene_adv_vs_loading_t, field_0x7A0) == 0x7A0, "cc_scene_adv_vs_loading_t.field_0x7A0 offset mismatch");

/* ccSceneChallengeMission — inferred layout, size unknown >= 0x134 */
typedef struct cc_scene_challenge_mission_t {
    uint8_t _pad_0x0[296];
    uint64_t field_0x128; /* 0x128 */
    uint32_t field_0x130; /* 0x130 */
} cc_scene_challenge_mission_t;

static_assert(offsetof(cc_scene_challenge_mission_t, field_0x128) == 0x128, "cc_scene_challenge_mission_t.field_0x128 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_t, field_0x130) == 0x130, "cc_scene_challenge_mission_t.field_0x130 offset mismatch");

/* ccSceneChallengeMissionCharacterSelect — inferred layout, size unknown >= 0x218 */
typedef struct cc_scene_challenge_mission_character_select_t {
    uint8_t _pad_0x0[528];
    uint64_t field_0x210; /* 0x210 */
} cc_scene_challenge_mission_character_select_t;

static_assert(offsetof(cc_scene_challenge_mission_character_select_t, field_0x210) == 0x210, "cc_scene_challenge_mission_character_select_t.field_0x210 offset mismatch");

/* ccSceneChallengeMissionRoot — inferred layout, size unknown >= 0x6DC */
typedef struct cc_scene_challenge_mission_root_t {
    uint8_t _pad_0x0[1384];
    uint32_t field_0x568; /* 0x568 */
    uint8_t _pad_0x56C[180];
    uint64_t field_0x620; /* 0x620 */
    uint64_t field_0x628; /* 0x628 */
    uint64_t field_0x630; /* 0x630 */
    uint64_t field_0x638; /* 0x638 */
    uint8_t _pad_0x640[80];
    uint64_t field_0x690; /* 0x690 */
    uint64_t field_0x698; /* 0x698 */
    uint8_t _pad_0x6A0[56];
    uint32_t field_0x6D8; /* 0x6D8 */
} cc_scene_challenge_mission_root_t;

static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x568) == 0x568, "cc_scene_challenge_mission_root_t.field_0x568 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x620) == 0x620, "cc_scene_challenge_mission_root_t.field_0x620 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x628) == 0x628, "cc_scene_challenge_mission_root_t.field_0x628 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x630) == 0x630, "cc_scene_challenge_mission_root_t.field_0x630 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x638) == 0x638, "cc_scene_challenge_mission_root_t.field_0x638 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x690) == 0x690, "cc_scene_challenge_mission_root_t.field_0x690 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x698) == 0x698, "cc_scene_challenge_mission_root_t.field_0x698 offset mismatch");
static_assert(offsetof(cc_scene_challenge_mission_root_t, field_0x6D8) == 0x6D8, "cc_scene_challenge_mission_root_t.field_0x6D8 offset mismatch");

/* ccStageAdvGimmick — inferred layout, size unknown >= 0x100 */
typedef struct cc_stage_adv_gimmick_t {
    uint8_t _pad_0x0[168];
    uint64_t field_0xA8; /* 0xA8 */
    uint64_t field_0xB0; /* 0xB0 */
    uint64_t field_0xB8; /* 0xB8 */
    uint64_t field_0xC0; /* 0xC0 */
    uint32_t field_0xC8; /* 0xC8 */
    uint8_t _pad_0xCC[4];
    uint64_t field_0xD0; /* 0xD0 */
    uint64_t field_0xD8; /* 0xD8 */
    uint64_t field_0xE0; /* 0xE0 */
    uint64_t field_0xE8; /* 0xE8 */
    uint32_t field_0xF0; /* 0xF0 */
    uint32_t field_0xF4; /* 0xF4 */
    uint64_t field_0xF8; /* 0xF8 */
} cc_stage_adv_gimmick_t;

static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xA8) == 0xA8, "cc_stage_adv_gimmick_t.field_0xA8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xB0) == 0xB0, "cc_stage_adv_gimmick_t.field_0xB0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xC0) == 0xC0, "cc_stage_adv_gimmick_t.field_0xC0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xC8) == 0xC8, "cc_stage_adv_gimmick_t.field_0xC8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xD0) == 0xD0, "cc_stage_adv_gimmick_t.field_0xD0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xD8) == 0xD8, "cc_stage_adv_gimmick_t.field_0xD8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xE0) == 0xE0, "cc_stage_adv_gimmick_t.field_0xE0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xE8) == 0xE8, "cc_stage_adv_gimmick_t.field_0xE8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xF0) == 0xF0, "cc_stage_adv_gimmick_t.field_0xF0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xF4) == 0xF4, "cc_stage_adv_gimmick_t.field_0xF4 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_t, field_0xF8) == 0xF8, "cc_stage_adv_gimmick_t.field_0xF8 offset mismatch");

/* ccStageAdvGimmickActionObj — inferred layout, size unknown >= 0x120 */
typedef struct cc_stage_adv_gimmick_action_obj_t {
    uint8_t _pad_0x0[184];
    uint64_t field_0xB8; /* 0xB8 */
    uint64_t field_0xC0; /* 0xC0 */
    uint32_t field_0xC8; /* 0xC8 */
    uint8_t _pad_0xCC[44];
    uint8_t field_0xF8; /* 0xF8 */
    uint8_t _pad_0xF9[15];
    uint64_t field_0x108; /* 0x108 */
    uint64_t field_0x110; /* 0x110 */
    uint64_t field_0x118; /* 0x118 */
} cc_stage_adv_gimmick_action_obj_t;

static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_action_obj_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0xC0) == 0xC0, "cc_stage_adv_gimmick_action_obj_t.field_0xC0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0xC8) == 0xC8, "cc_stage_adv_gimmick_action_obj_t.field_0xC8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0xF8) == 0xF8, "cc_stage_adv_gimmick_action_obj_t.field_0xF8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0x108) == 0x108, "cc_stage_adv_gimmick_action_obj_t.field_0x108 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0x110) == 0x110, "cc_stage_adv_gimmick_action_obj_t.field_0x110 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_obj_t, field_0x118) == 0x118, "cc_stage_adv_gimmick_action_obj_t.field_0x118 offset mismatch");

/* ccStageAdvGimmickActionState — inferred layout, size unknown >= 0x1D8 */
typedef struct cc_stage_adv_gimmick_action_state_t {
    uint8_t _pad_0x0[144];
    uint64_t field_0x90; /* 0x90 */
    uint64_t field_0x98; /* 0x98 */
    uint8_t _pad_0xA0[184];
    uint32_t field_0x158; /* 0x158 */
    uint8_t _pad_0x15C[116];
    uint64_t field_0x1D0; /* 0x1D0 */
} cc_stage_adv_gimmick_action_state_t;

static_assert(offsetof(cc_stage_adv_gimmick_action_state_t, field_0x90) == 0x90, "cc_stage_adv_gimmick_action_state_t.field_0x90 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_state_t, field_0x98) == 0x98, "cc_stage_adv_gimmick_action_state_t.field_0x98 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_state_t, field_0x158) == 0x158, "cc_stage_adv_gimmick_action_state_t.field_0x158 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_action_state_t, field_0x1D0) == 0x1D0, "cc_stage_adv_gimmick_action_state_t.field_0x1D0 offset mismatch");

/* ccStageAdvGimmickBreakObj — inferred layout, size unknown >= 0x1BC */
typedef struct cc_stage_adv_gimmick_break_obj_t {
    uint8_t _pad_0x0[160];
    uint32_t field_0xA0; /* 0xA0 */
    uint8_t _pad_0xA4[4];
    uint64_t field_0xA8; /* 0xA8 */
    uint64_t field_0xB0; /* 0xB0 */
    uint64_t field_0xB8; /* 0xB8 */
    uint64_t field_0xC0; /* 0xC0 */
    uint8_t _pad_0xC8[8];
    uint64_t field_0xD0; /* 0xD0 */
    uint64_t field_0xD8; /* 0xD8 */
    uint64_t field_0xE0; /* 0xE0 */
    uint8_t _pad_0xE8[72];
    uint64_t field_0x130; /* 0x130 */
    uint8_t _pad_0x138[16];
    uint64_t field_0x148; /* 0x148 */
    uint8_t _pad_0x150[24];
    uint64_t field_0x168; /* 0x168 */
    uint8_t _pad_0x170[16];
    uint64_t field_0x180; /* 0x180 */
    uint8_t _pad_0x188[24];
    uint64_t field_0x1A0; /* 0x1A0 */
    uint64_t field_0x1A8; /* 0x1A8 */
    uint64_t field_0x1B0; /* 0x1B0 */
    uint32_t field_0x1B8; /* 0x1B8 */
} cc_stage_adv_gimmick_break_obj_t;

static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xA0) == 0xA0, "cc_stage_adv_gimmick_break_obj_t.field_0xA0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xA8) == 0xA8, "cc_stage_adv_gimmick_break_obj_t.field_0xA8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xB0) == 0xB0, "cc_stage_adv_gimmick_break_obj_t.field_0xB0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_break_obj_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xC0) == 0xC0, "cc_stage_adv_gimmick_break_obj_t.field_0xC0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xD0) == 0xD0, "cc_stage_adv_gimmick_break_obj_t.field_0xD0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xD8) == 0xD8, "cc_stage_adv_gimmick_break_obj_t.field_0xD8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0xE0) == 0xE0, "cc_stage_adv_gimmick_break_obj_t.field_0xE0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x130) == 0x130, "cc_stage_adv_gimmick_break_obj_t.field_0x130 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x148) == 0x148, "cc_stage_adv_gimmick_break_obj_t.field_0x148 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x168) == 0x168, "cc_stage_adv_gimmick_break_obj_t.field_0x168 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x180) == 0x180, "cc_stage_adv_gimmick_break_obj_t.field_0x180 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x1A0) == 0x1A0, "cc_stage_adv_gimmick_break_obj_t.field_0x1A0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x1A8) == 0x1A8, "cc_stage_adv_gimmick_break_obj_t.field_0x1A8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x1B0) == 0x1B0, "cc_stage_adv_gimmick_break_obj_t.field_0x1B0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_break_obj_t, field_0x1B8) == 0x1B8, "cc_stage_adv_gimmick_break_obj_t.field_0x1B8 offset mismatch");

/* ccStageAdvGimmickContactAnmObj — inferred layout, size unknown >= 0x14C */
typedef struct cc_stage_adv_gimmick_contact_anm_obj_t {
    uint8_t _pad_0x0[16];
    uint64_t field_0x10; /* 0x10 */
    uint8_t _pad_0x18[136];
    uint32_t field_0xA0; /* 0xA0 */
    uint8_t _pad_0xA4[12];
    uint64_t field_0xB0; /* 0xB0 */
    uint64_t field_0xB8; /* 0xB8 */
    uint64_t field_0xC0; /* 0xC0 */
    uint8_t _pad_0xC8[104];
    uint64_t field_0x130; /* 0x130 */
    uint64_t field_0x138; /* 0x138 */
    uint64_t field_0x140; /* 0x140 */
    uint32_t field_0x148; /* 0x148 */
} cc_stage_adv_gimmick_contact_anm_obj_t;

static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0x10) == 0x10, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0x10 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0xA0) == 0xA0, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0xA0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0xB0) == 0xB0, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0xB0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0xC0) == 0xC0, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0xC0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0x130) == 0x130, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0x130 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0x138) == 0x138, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0x138 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0x140) == 0x140, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0x140 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_anm_obj_t, field_0x148) == 0x148, "cc_stage_adv_gimmick_contact_anm_obj_t.field_0x148 offset mismatch");

/* ccStageAdvGimmickContactObj — inferred layout, size unknown >= 0x1B8 */
typedef struct cc_stage_adv_gimmick_contact_obj_t {
    uint8_t _pad_0x0[160];
    uint32_t field_0xA0; /* 0xA0 */
    uint8_t _pad_0xA4[4];
    uint64_t field_0xA8; /* 0xA8 */
    uint64_t field_0xB0; /* 0xB0 */
    uint64_t field_0xB8; /* 0xB8 */
    uint64_t field_0xC0; /* 0xC0 */
    uint8_t _pad_0xC8[104];
    uint64_t field_0x130; /* 0x130 */
    uint8_t _pad_0x138[16];
    uint64_t field_0x148; /* 0x148 */
    uint8_t _pad_0x150[24];
    uint64_t field_0x168; /* 0x168 */
    uint8_t _pad_0x170[16];
    uint64_t field_0x180; /* 0x180 */
    uint8_t _pad_0x188[24];
    uint64_t field_0x1A0; /* 0x1A0 */
    uint64_t field_0x1A8; /* 0x1A8 */
    uint64_t field_0x1B0; /* 0x1B0 */
} cc_stage_adv_gimmick_contact_obj_t;

static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0xA0) == 0xA0, "cc_stage_adv_gimmick_contact_obj_t.field_0xA0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0xA8) == 0xA8, "cc_stage_adv_gimmick_contact_obj_t.field_0xA8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0xB0) == 0xB0, "cc_stage_adv_gimmick_contact_obj_t.field_0xB0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_contact_obj_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0xC0) == 0xC0, "cc_stage_adv_gimmick_contact_obj_t.field_0xC0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x130) == 0x130, "cc_stage_adv_gimmick_contact_obj_t.field_0x130 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x148) == 0x148, "cc_stage_adv_gimmick_contact_obj_t.field_0x148 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x168) == 0x168, "cc_stage_adv_gimmick_contact_obj_t.field_0x168 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x180) == 0x180, "cc_stage_adv_gimmick_contact_obj_t.field_0x180 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x1A0) == 0x1A0, "cc_stage_adv_gimmick_contact_obj_t.field_0x1A0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x1A8) == 0x1A8, "cc_stage_adv_gimmick_contact_obj_t.field_0x1A8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_contact_obj_t, field_0x1B0) == 0x1B0, "cc_stage_adv_gimmick_contact_obj_t.field_0x1B0 offset mismatch");

/* ccStageAdvGimmickEscapeAnimal — inferred layout, size unknown >= 0x208 */
typedef struct cc_stage_adv_gimmick_escape_animal_t {
    uint8_t _pad_0x0[16];
    uint64_t field_0x10; /* 0x10 */
    uint8_t _pad_0x18[160];
    uint64_t field_0xB8; /* 0xB8 */
    uint8_t _pad_0xC0[112];
    uint64_t field_0x130; /* 0x130 */
    uint8_t _pad_0x138[16];
    uint64_t field_0x148; /* 0x148 */
    uint8_t _pad_0x150[24];
    uint64_t field_0x168; /* 0x168 */
    uint8_t _pad_0x170[16];
    uint64_t field_0x180; /* 0x180 */
    uint8_t _pad_0x188[24];
    uint64_t field_0x1A0; /* 0x1A0 */
    uint8_t _pad_0x1A8[16];
    uint64_t field_0x1B8; /* 0x1B8 */
    uint8_t _pad_0x1C0[24];
    uint32_t field_0x1D8; /* 0x1D8 */
    uint64_t field_0x1DC; /* 0x1DC */
    uint32_t field_0x1E4; /* 0x1E4 */
    uint64_t field_0x1E8; /* 0x1E8 */
    uint32_t field_0x1F0; /* 0x1F0 */
    uint8_t _pad_0x1F4[8];
    uint64_t field_0x1FC; /* 0x1FC */
    uint32_t field_0x204; /* 0x204 */
} cc_stage_adv_gimmick_escape_animal_t;

static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x10) == 0x10, "cc_stage_adv_gimmick_escape_animal_t.field_0x10 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_escape_animal_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x130) == 0x130, "cc_stage_adv_gimmick_escape_animal_t.field_0x130 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x148) == 0x148, "cc_stage_adv_gimmick_escape_animal_t.field_0x148 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x168) == 0x168, "cc_stage_adv_gimmick_escape_animal_t.field_0x168 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x180) == 0x180, "cc_stage_adv_gimmick_escape_animal_t.field_0x180 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1A0) == 0x1A0, "cc_stage_adv_gimmick_escape_animal_t.field_0x1A0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1B8) == 0x1B8, "cc_stage_adv_gimmick_escape_animal_t.field_0x1B8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1D8) == 0x1D8, "cc_stage_adv_gimmick_escape_animal_t.field_0x1D8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1DC) == 0x1DC, "cc_stage_adv_gimmick_escape_animal_t.field_0x1DC offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1E4) == 0x1E4, "cc_stage_adv_gimmick_escape_animal_t.field_0x1E4 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1E8) == 0x1E8, "cc_stage_adv_gimmick_escape_animal_t.field_0x1E8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1F0) == 0x1F0, "cc_stage_adv_gimmick_escape_animal_t.field_0x1F0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x1FC) == 0x1FC, "cc_stage_adv_gimmick_escape_animal_t.field_0x1FC offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_escape_animal_t, field_0x204) == 0x204, "cc_stage_adv_gimmick_escape_animal_t.field_0x204 offset mismatch");

/* ccStageAdvGimmickSave — inferred layout, size unknown >= 0xC8 */
typedef struct cc_stage_adv_gimmick_save_t {
    uint8_t _pad_0x0[16];
    uint64_t field_0x10; /* 0x10 */
    uint8_t _pad_0x18[136];
    uint32_t field_0xA0; /* 0xA0 */
    uint8_t _pad_0xA4[4];
    uint64_t field_0xA8; /* 0xA8 */
    uint8_t _pad_0xB0[8];
    uint64_t field_0xB8; /* 0xB8 */
    uint64_t field_0xC0; /* 0xC0 */
} cc_stage_adv_gimmick_save_t;

static_assert(offsetof(cc_stage_adv_gimmick_save_t, field_0x10) == 0x10, "cc_stage_adv_gimmick_save_t.field_0x10 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_save_t, field_0xA0) == 0xA0, "cc_stage_adv_gimmick_save_t.field_0xA0 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_save_t, field_0xA8) == 0xA8, "cc_stage_adv_gimmick_save_t.field_0xA8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_save_t, field_0xB8) == 0xB8, "cc_stage_adv_gimmick_save_t.field_0xB8 offset mismatch");
static_assert(offsetof(cc_stage_adv_gimmick_save_t, field_0xC0) == 0xC0, "cc_stage_adv_gimmick_save_t.field_0xC0 offset mismatch");

#pragma pack(pop)

#endif /* ST3A16_H */
