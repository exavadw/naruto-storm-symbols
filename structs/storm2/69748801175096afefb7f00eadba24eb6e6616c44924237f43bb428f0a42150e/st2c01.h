/* st2c01.h — Story CUTSCENE / EVENT playback structs for NARUTO STORM 2 PC (s2)
 * All layouts INFERRED from static decompilation of NSUNS2.exe (sha 697488011750).
 * NOT CONFIRMED by runtime trace. Field names from s2 symbols/strings only.
 * Image base: 0x140000000.
 */
#ifndef ST2C01_H
#define ST2C01_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- ccAdvEventManager ----
 * Size: unknown, >= 0x80 (dtor touches +0x78; Finalize is a global singleton)
 * Vtable: not directly set in ctor (singleton pattern via DAT_1409da0c0)
 * Fields from: Action, GetMobStateSearchName, AddMobState, ~ccAdvEventManager, Finalize
 */
typedef struct __attribute__((packed)) ccAdvEventManager {
    /* +0x00 */ void *current_mob_state;          /* Action: *param_1 = param_2 */
    /* +0x08 */ uint64_t mob_states_vec_begin;     /* AddMobState: vector begin at +8 */
    /* +0x10 */ uint64_t mob_states_vec_end;       /* GetMobStateSearchName: *(param_1+0x10) - *(param_1+8) >> 3 */
    /* +0x18 */ uint8_t _pad_18[0x08];             /* gap to +0x20 */
    /* +0x20 */ uint64_t block_alloc_id_20;        /* dtor: BlockAllocator::GetBlockId(param_1+0x20) */
    /* +0x28 */ uint8_t _pad_28[0x10];             /* gap to +0x38 */
    /* +0x38 */ uint64_t mutex_or_vec_begin_38;    /* dtor: mmMutex(param_1+0x38) */
    /* +0x40 */ uint64_t mutex_or_vec_end_40;      /* dtor: *(param_1+0x40) = *(param_1+0x38) */
    /* +0x48 */ uint8_t _pad_48[0x08];             /* gap to +0x50 */
    /* +0x50 */ uint64_t block_alloc_id_50;        /* dtor: BlockAllocator::GetBlockId(param_1+0x50) */
    /* +0x58 */ uint8_t _pad_58[0x20];             /* gap to +0x78 */
    /* +0x78 */ uint64_t sub_object_78;            /* dtor: FUN_1401d47fc(param_1+0x78) */
} ccAdvEventManager;

static_assert(offsetof(ccAdvEventManager, current_mob_state) == 0x00, "ccAdvEventManager.current_mob_state");
static_assert(offsetof(ccAdvEventManager, mob_states_vec_begin) == 0x08, "ccAdvEventManager.mob_states_vec_begin");
static_assert(offsetof(ccAdvEventManager, mob_states_vec_end) == 0x10, "ccAdvEventManager.mob_states_vec_end");
static_assert(offsetof(ccAdvEventManager, block_alloc_id_20) == 0x20, "ccAdvEventManager.block_alloc_id_20");
static_assert(offsetof(ccAdvEventManager, mutex_or_vec_begin_38) == 0x38, "ccAdvEventManager.mutex_or_vec_begin_38");
static_assert(offsetof(ccAdvEventManager, mutex_or_vec_end_40) == 0x40, "ccAdvEventManager.mutex_or_vec_end_40");
static_assert(offsetof(ccAdvEventManager, block_alloc_id_50) == 0x50, "ccAdvEventManager.block_alloc_id_50");
static_assert(offsetof(ccAdvEventManager, sub_object_78) == 0x78, "ccAdvEventManager.sub_object_78");

/* ---- ccAdvLivetalkActor ----
 * Size: 0x1668 (from ccFileLoadListForUi::LoadTh(0x1668,...) in ccAdvCharaState::CreateUiObject)
 * Vtable: 0x14079C210 (set in ctor: *param_1 = &PTR_FUN_14079c210)
 * Inherits ccWindowTalkEx at +0x68 (ctor calls ccWindowTalkEx::ccWindowTalkEx(param_1+0xd*8=0x68))
 * Fields from: ctor, Ctrl, ChangeLocalSequence
 */
typedef struct __attribute__((packed)) ccAdvLivetalkActor {
    /* +0x00 */ void *vtable;                      /* ctor: *param_1 = &PTR_FUN_14079c210 */
    /* +0x08 */ uint64_t sequence_id;              /* Ctrl: *(param_1+0x8) = GetSequence() */
    /* +0x10 */ uint64_t area_name_str_ptr;        /* Ctrl: string ptr at +0x10 (std::string inline) */
    /* +0x18 */ uint64_t area_name_str_capacity;   /* Ctrl: capacity check at +0x28 for SSO threshold */
    /* +0x20 */ uint8_t _pad_20[0x08];             /* gap */
    /* +0x28 */ uint64_t area_name_str_size;       /* Ctrl: 0xf < *(param_1+0x28) SSO check */
    /* +0x30 */ uint8_t _pad_30[0x08];             /* gap */
    /* +0x38 */ int32_t local_seq_flag;            /* ChangeLocalSequence: *(param_1+0x38) = 1 */
    /* +0x3C */ int32_t local_seq_reset;           /* ChangeLocalSequence: *(param_1+0x3c) = 0 */
    /* +0x40 */ uint8_t _pad_40[0x08];             /* gap */
    /* +0x48 */ int32_t talk_param;                /* Ctrl: *(param_1+0x48) = param_2 */
    /* +0x4C */ uint8_t char_code[4];              /* CreateUiObject copies char code to +0x4c..0x4f */
    /* +0x50 */ int32_t ctrl_counter;              /* Ctrl: incremented each call */
    /* +0x54 */ int32_t timer_54;                  /* Ctrl: cleared when timer_58 < 1 */
    /* +0x58 */ int32_t timer_countdown_58;        /* Ctrl: decremented each call */
    /* +0x5C */ uint64_t livetalk_cue_id;          /* Ctrl: compared with data entry field */
    /* +0x64 */ uint8_t _pad_64[0x04];             /* gap */
    /* +0x68 */ uint8_t window_talk_ex[0x268];     /* ccWindowTalkEx embedded (size inferred from Vector2 at +0x2cb) */
    /* +0x2D0 */ uint8_t _pad_2d0[0x1390];         /* gap to +0x1660 */
    /* +0x1660 */ int32_t frame_timer;             /* Ctrl: countdown timer, set from fps scaling */
    /* +0x1664 */ uint8_t _pad_1664[0x04];         /* padding to 0x1668 */
} ccAdvLivetalkActor;

static_assert(offsetof(ccAdvLivetalkActor, vtable) == 0x00, "ccAdvLivetalkActor.vtable");
static_assert(offsetof(ccAdvLivetalkActor, sequence_id) == 0x08, "ccAdvLivetalkActor.sequence_id");
static_assert(offsetof(ccAdvLivetalkActor, area_name_str_ptr) == 0x10, "ccAdvLivetalkActor.area_name_str_ptr");
static_assert(offsetof(ccAdvLivetalkActor, area_name_str_size) == 0x28, "ccAdvLivetalkActor.area_name_str_size");
static_assert(offsetof(ccAdvLivetalkActor, local_seq_flag) == 0x38, "ccAdvLivetalkActor.local_seq_flag");
static_assert(offsetof(ccAdvLivetalkActor, local_seq_reset) == 0x3C, "ccAdvLivetalkActor.local_seq_reset");
static_assert(offsetof(ccAdvLivetalkActor, talk_param) == 0x48, "ccAdvLivetalkActor.talk_param");
static_assert(offsetof(ccAdvLivetalkActor, char_code) == 0x4C, "ccAdvLivetalkActor.char_code");
static_assert(offsetof(ccAdvLivetalkActor, ctrl_counter) == 0x50, "ccAdvLivetalkActor.ctrl_counter");
static_assert(offsetof(ccAdvLivetalkActor, timer_54) == 0x54, "ccAdvLivetalkActor.timer_54");
static_assert(offsetof(ccAdvLivetalkActor, timer_countdown_58) == 0x58, "ccAdvLivetalkActor.timer_countdown_58");
static_assert(offsetof(ccAdvLivetalkActor, livetalk_cue_id) == 0x5C, "ccAdvLivetalkActor.livetalk_cue_id");
static_assert(offsetof(ccAdvLivetalkActor, window_talk_ex) == 0x68, "ccAdvLivetalkActor.window_talk_ex");
static_assert(offsetof(ccAdvLivetalkActor, frame_timer) == 0x1660, "ccAdvLivetalkActor.frame_timer");
static_assert(sizeof(ccAdvLivetalkActor) == 0x1668, "ccAdvLivetalkActor size == 0x1668");

/* ---- ccAdvMotionEventActor ----
 * Size: unknown, >= 0x14C0 (dtor reads +0x14b8 pointer; UpdateAttr writes +0x130)
 * No named ctor found in s2; likely allocated as part of a larger container.
 * Fields from: ~ccAdvMotionEventActor, SetCategory, SetMotion, Update, UpdateAttr, FootEvent
 */
typedef struct __attribute__((packed)) ccAdvMotionEventActor {
    /* +0x00 */ void *vtable;                      /* implied by virtual dtor call (**(code**)(*plVar1+8)) */
    /* +0x08 */ int32_t current_frame;             /* Update: *(param_1+8) = iVar12 (frame counter) */
    /* +0x0C */ uint8_t _pad_0c[0x04];             /* gap */
    /* +0x10 */ void *motion_event_category;       /* SetCategory: *(param_1+0x10) = SearchCategory() */
    /* +0x18 */ void *motion_event_data;           /* SetMotion: *(param_1+0x18) = SearchMotion() */
    /* +0x20 */ char motion_name[0x100];           /* SetMotion: nuccStrCpy(param_1+0x20, ..., 0x100) */
    /* +0x120 */ int32_t ground_hit_flag;          /* FootEvent/UpdateAttr: read/write */
    /* +0x124 */ float hit_pos_x;                  /* UpdateAttr: Nucc::Vector3::Set(param_1+0x124,...) */
    /* +0x128 */ float hit_pos_y;                  /* UpdateAttr: Vector3 y component */
    /* +0x12C */ float hit_pos_z;                  /* UpdateAttr: Vector3 z component */
    /* +0x130 */ uint8_t _pad_130[0x1388];         /* gap to +0x14b8 */
    /* +0x14B8 */ void *sprite_or_model_ptr;       /* dtor: (**(code**)(*plVar1+8))(plVar1,1) then null */
} ccAdvMotionEventActor;

static_assert(offsetof(ccAdvMotionEventActor, vtable) == 0x00, "ccAdvMotionEventActor.vtable");
static_assert(offsetof(ccAdvMotionEventActor, current_frame) == 0x08, "ccAdvMotionEventActor.current_frame");
static_assert(offsetof(ccAdvMotionEventActor, motion_event_category) == 0x10, "ccAdvMotionEventActor.motion_event_category");
static_assert(offsetof(ccAdvMotionEventActor, motion_event_data) == 0x18, "ccAdvMotionEventActor.motion_event_data");
static_assert(offsetof(ccAdvMotionEventActor, motion_name) == 0x20, "ccAdvMotionEventActor.motion_name");
static_assert(offsetof(ccAdvMotionEventActor, ground_hit_flag) == 0x120, "ccAdvMotionEventActor.ground_hit_flag");
static_assert(offsetof(ccAdvMotionEventActor, hit_pos_x) == 0x124, "ccAdvMotionEventActor.hit_pos_x");
static_assert(offsetof(ccAdvMotionEventActor, sprite_or_model_ptr) == 0x14B8, "ccAdvMotionEventActor.sprite_or_model_ptr");

/* ---- ccAdvMotionEventManager ----
 * Size: unknown, >= 0x68 (base 8 + 2 slots * 0x30 = 0x68)
 * Contains 2 fixed ccAdvMotionEvent slots at +0x08 and +0x38 (stride 0x30).
 * Fields from: CreateMotionEvent, DeleteMotionEvent, SearchCategory
 */
typedef struct __attribute__((packed)) ccAdvMotionEventManager {
    /* +0x00 */ uint64_t base_field;               /* implicit this pointer area */
    /* +0x08 */ uint8_t motion_event_slot_0[0x30]; /* CreateMotionEvent: param_1+8+(0)*0x30 */
    /* +0x38 */ uint8_t motion_event_slot_1[0x30]; /* CreateMotionEvent: param_1+8+(1)*0x30 */
} ccAdvMotionEventManager;

static_assert(offsetof(ccAdvMotionEventManager, base_field) == 0x00, "ccAdvMotionEventManager.base_field");
static_assert(offsetof(ccAdvMotionEventManager, motion_event_slot_0) == 0x08, "ccAdvMotionEventManager.motion_event_slot_0");
static_assert(offsetof(ccAdvMotionEventManager, motion_event_slot_1) == 0x38, "ccAdvMotionEventManager.motion_event_slot_1");

/* ---- ccAdvStandDemoCamera ----
 * Size: 0x240 (from ccFileLoadListForUi::LoadTh(0x240,...) in ccAdvCameraState::Create)
 * Vtable: 0x14079EB30 (set in ctor after ccCmnCameraOperator base init)
 * Inherits ccCmnCameraOperator (base class, vtable overwritten)
 * Fields from: ctor, Ctrl, MoveCalcRate, SetStartData
 */
typedef struct __attribute__((packed)) ccAdvStandDemoCamera {
    /* +0x00 */ void *vtable;                      /* ctor: *param_1 = &PTR_FUN_14079eb30 */
    /* +0x08 */ uint8_t cmn_camera_operator[0x38]; /* ccCmnCameraOperator base (inferred from LookAtNew at +0x40) */
    /* +0x40 */ void *camera_vtable;               /* Ctrl: plVar1 = param_1+0x40; (**(code**)(*plVar1+0x28)) */
    /* +0x48 */ uint8_t _pad_48[0x08];             /* gap */
    /* +0x50 */ uint8_t camera_data[0x18];         /* gap to Vector3 fields */
    /* +0x68 */ uint8_t _pad_68[0x04];             /* gap */
    /* +0x6C */ float fov_or_zoom;                 /* Ctrl: *(param_1+0x6c) = *(param_1+0x1c8) */
    /* +0x70 */ uint8_t _pad_70[0x140];            /* gap to +0x1b0 */
    /* +0x1B0 */ float eye_pos_x;                  /* Ctrl/MoveCalcRate: interpolated eye position */
    /* +0x1B4 */ float eye_pos_y;                  /* Ctrl/MoveCalcRate */
    /* +0x1B8 */ float eye_pos_z;                  /* Ctrl/MoveCalcRate */
    /* +0x1BC */ float target_pos_x;               /* Ctrl/MoveCalcRate: interpolated target */
    /* +0x1C0 */ float target_pos_y;               /* Ctrl/MoveCalcRate */
    /* +0x1C4 */ float target_pos_z;               /* Ctrl/MoveCalcRate */
    /* +0x1C8 */ float current_fov;                /* Ctrl: accumulated FOV value */
    /* +0x1CC */ float rotation_y;                 /* Ctrl: Y rotation for matrix */
    /* +0x1D0 */ float eye_vel_x;                  /* Ctrl: velocity/interpolation state */
    /* +0x1D4 */ float eye_vel_y;                  /* Ctrl */
    /* +0x1D8 */ float eye_vel_z;                  /* Ctrl */
    /* +0x1DC */ float target_vel_x;               /* Ctrl: target velocity */
    /* +0x1E0 */ float target_vel_y;               /* Ctrl */
    /* +0x1E4 */ float target_vel_z;               /* Ctrl */
    /* +0x1E8 */ float target_fov;                 /* Ctrl/MoveCalcRate: target FOV */
    /* +0x1EC */ float dest_eye_x;                 /* Ctrl: destination eye position */
    /* +0x1F0 */ float dest_eye_y;                 /* Ctrl */
    /* +0x1F4 */ float dest_eye_z;                 /* Ctrl */
    /* +0x1F8 */ float dest_target_x;              /* Ctrl: destination target */
    /* +0x1FC */ float dest_target_y;              /* Ctrl */
    /* +0x200 */ float dest_target_z;              /* Ctrl */
    /* +0x204 */ float fov_delta;                  /* Ctrl: FOV change per frame */
    /* +0x208 */ float start_eye_x;                /* MoveCalcRate/SetStartData: start eye pos */
    /* +0x20C */ float start_eye_y;                /* MoveCalcRate/SetStartData */
    /* +0x210 */ float start_eye_z;                /* MoveCalcRate/SetStartData */
    /* +0x214 */ float start_target_x;             /* MoveCalcRate/SetStartData: start target */
    /* +0x218 */ float start_target_y;             /* MoveCalcRate/SetStartData */
    /* +0x21C */ float start_target_z;             /* MoveCalcRate/SetStartData */
    /* +0x220 */ float start_fov;                  /* MoveCalcRate/SetStartData */
    /* +0x224 */ int32_t eye_reached;              /* Ctrl/MoveCalcRate: flag, set to 1 when done */
    /* +0x228 */ int32_t target_reached;           /* Ctrl/MoveCalcRate: flag */
    /* +0x22C */ int32_t fov_reached;              /* Ctrl/MoveCalcRate: flag */
    /* +0x230 */ int32_t quake_done;               /* Ctrl: set to 1 when quake ends */
    /* +0x234 */ int32_t move_rate_id;             /* MoveCalcRate: ccGetEventMoveRate arg */
    /* +0x238 */ int32_t move_duration;            /* MoveCalcRate: compared with frame param */
    /* +0x23C */ uint8_t _pad_23c[0x04];           /* padding to 0x240 */
} ccAdvStandDemoCamera;

static_assert(offsetof(ccAdvStandDemoCamera, vtable) == 0x00, "ccAdvStandDemoCamera.vtable");
static_assert(offsetof(ccAdvStandDemoCamera, cmn_camera_operator) == 0x08, "ccAdvStandDemoCamera.cmn_camera_operator");
static_assert(offsetof(ccAdvStandDemoCamera, camera_vtable) == 0x40, "ccAdvStandDemoCamera.camera_vtable");
static_assert(offsetof(ccAdvStandDemoCamera, fov_or_zoom) == 0x6C, "ccAdvStandDemoCamera.fov_or_zoom");
static_assert(offsetof(ccAdvStandDemoCamera, eye_pos_x) == 0x1B0, "ccAdvStandDemoCamera.eye_pos_x");
static_assert(offsetof(ccAdvStandDemoCamera, target_pos_x) == 0x1BC, "ccAdvStandDemoCamera.target_pos_x");
static_assert(offsetof(ccAdvStandDemoCamera, current_fov) == 0x1C8, "ccAdvStandDemoCamera.current_fov");
static_assert(offsetof(ccAdvStandDemoCamera, rotation_y) == 0x1CC, "ccAdvStandDemoCamera.rotation_y");
static_assert(offsetof(ccAdvStandDemoCamera, eye_vel_x) == 0x1D0, "ccAdvStandDemoCamera.eye_vel_x");
static_assert(offsetof(ccAdvStandDemoCamera, target_vel_x) == 0x1DC, "ccAdvStandDemoCamera.target_vel_x");
static_assert(offsetof(ccAdvStandDemoCamera, target_fov) == 0x1E8, "ccAdvStandDemoCamera.target_fov");
static_assert(offsetof(ccAdvStandDemoCamera, dest_eye_x) == 0x1EC, "ccAdvStandDemoCamera.dest_eye_x");
static_assert(offsetof(ccAdvStandDemoCamera, dest_target_x) == 0x1F8, "ccAdvStandDemoCamera.dest_target_x");
static_assert(offsetof(ccAdvStandDemoCamera, fov_delta) == 0x204, "ccAdvStandDemoCamera.fov_delta");
static_assert(offsetof(ccAdvStandDemoCamera, start_eye_x) == 0x208, "ccAdvStandDemoCamera.start_eye_x");
static_assert(offsetof(ccAdvStandDemoCamera, start_target_x) == 0x214, "ccAdvStandDemoCamera.start_target_x");
static_assert(offsetof(ccAdvStandDemoCamera, start_fov) == 0x220, "ccAdvStandDemoCamera.start_fov");
static_assert(offsetof(ccAdvStandDemoCamera, eye_reached) == 0x224, "ccAdvStandDemoCamera.eye_reached");
static_assert(offsetof(ccAdvStandDemoCamera, target_reached) == 0x228, "ccAdvStandDemoCamera.target_reached");
static_assert(offsetof(ccAdvStandDemoCamera, fov_reached) == 0x22C, "ccAdvStandDemoCamera.fov_reached");
static_assert(offsetof(ccAdvStandDemoCamera, quake_done) == 0x230, "ccAdvStandDemoCamera.quake_done");
static_assert(offsetof(ccAdvStandDemoCamera, move_rate_id) == 0x234, "ccAdvStandDemoCamera.move_rate_id");
static_assert(offsetof(ccAdvStandDemoCamera, move_duration) == 0x238, "ccAdvStandDemoCamera.move_duration");
static_assert(sizeof(ccAdvStandDemoCamera) == 0x240, "ccAdvStandDemoCamera size == 0x240");

/* ---- ccAdvSubEventManager ----
 * Size: unknown, >= 0x38 (GetParam reads tree node at +0x30)
 * Contains a tree/map structure at +0x30 for parameter lookup.
 * Fields from: Create, GetParam
 */
typedef struct __attribute__((packed)) ccAdvSubEventManager {
    /* +0x00 */ uint64_t base_field;               /* implicit this pointer area */
    /* +0x08 */ uint64_t entries_container;        /* Create: FUN_1401e03a8(param_1+8,...) */
    /* +0x10 */ uint8_t _pad_10[0x20];             /* gap to +0x30 */
    /* +0x30 */ void *param_tree_root;             /* GetParam: **(param_1+0x30) iterates tree nodes */
} ccAdvSubEventManager;

static_assert(offsetof(ccAdvSubEventManager, base_field) == 0x00, "ccAdvSubEventManager.base_field");
static_assert(offsetof(ccAdvSubEventManager, entries_container) == 0x08, "ccAdvSubEventManager.entries_container");
static_assert(offsetof(ccAdvSubEventManager, param_tree_root) == 0x30, "ccAdvSubEventManager.param_tree_root");

#endif /* ST2C01_H */