/* st3a10.h - Storm 3 Full Burst HD PC (s3) adventure/story struct layouts
 * ALL RESULTS INFERRED, NOT CONFIRMED.
 * Generated from state_surface + constructor/destructor decomp analysis.
 * PC offsets only (image base 0x140000000). Own-game names only.
 */
#ifndef ST3A10_H
#define ST3A10_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccAdvCtrlStateMachine: 24 fields, size=0x1010, proof: LoadTh(0x1010, "ccAdvCtrlStateMachine.h", 0x1b4) in FUN_14018bcbc */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x70];
    void* vtable_nuccFileLoadList;
    uint8_t nuccFileLoadList_body[0x8];
    void* vtable_ccAdvObjectStateList;
    uint8_t ccAdvObjectStateList_body[0x3C0];
    void* vtable_ccAdvScreenEffect;
    uint8_t ccAdvScreenEffect_body[0x860];
    uint8_t blockAlloc_0[0x38];
    uint8_t blockAlloc_1[0x38];
    uint8_t blockAlloc_2[0x38];
    uint8_t blockAlloc_3[0x38];
    int32_t field_e28;
    int32_t field_e2c;
    int64_t field_e30;
    int32_t field_e38;
    int64_t field_e3c;
    int64_t field_e44;
    uint8_t _pad_e4c[0x4];
    uint8_t ccStageLightParam[0x130];
    uint8_t ccAdvFileLoadList_embed[0x40];
    uint8_t ccDuelPlayerLoader[0x50];
} ccAdvCtrlStateMachine;
static_assert(offsetof(ccAdvCtrlStateMachine, vtable) == 0x0, "ccAdvCtrlStateMachine.vtable offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, base_GameActor) == 0x8, "ccAdvCtrlStateMachine.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, vtable_ccTaskBase) == 0x90, "ccAdvCtrlStateMachine.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, ccTaskBase_body) == 0x98, "ccAdvCtrlStateMachine.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, vtable_nuccFileLoadList) == 0x108, "ccAdvCtrlStateMachine.vtable_nuccFileLoadList offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, nuccFileLoadList_body) == 0x110, "ccAdvCtrlStateMachine.nuccFileLoadList_body offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, vtable_ccAdvObjectStateList) == 0x118, "ccAdvCtrlStateMachine.vtable_ccAdvObjectStateList offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, ccAdvObjectStateList_body) == 0x120, "ccAdvCtrlStateMachine.ccAdvObjectStateList_body offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, vtable_ccAdvScreenEffect) == 0x4E0, "ccAdvCtrlStateMachine.vtable_ccAdvScreenEffect offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, ccAdvScreenEffect_body) == 0x4E8, "ccAdvCtrlStateMachine.ccAdvScreenEffect_body offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, blockAlloc_0) == 0xD48, "ccAdvCtrlStateMachine.blockAlloc_0 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, blockAlloc_1) == 0xD80, "ccAdvCtrlStateMachine.blockAlloc_1 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, blockAlloc_2) == 0xDB8, "ccAdvCtrlStateMachine.blockAlloc_2 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, blockAlloc_3) == 0xDF0, "ccAdvCtrlStateMachine.blockAlloc_3 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, field_e28) == 0xE28, "ccAdvCtrlStateMachine.field_e28 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, field_e2c) == 0xE2C, "ccAdvCtrlStateMachine.field_e2c offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, field_e30) == 0xE30, "ccAdvCtrlStateMachine.field_e30 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, field_e38) == 0xE38, "ccAdvCtrlStateMachine.field_e38 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, field_e3c) == 0xE3C, "ccAdvCtrlStateMachine.field_e3c offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, field_e44) == 0xE44, "ccAdvCtrlStateMachine.field_e44 offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, _pad_e4c) == 0xE4C, "ccAdvCtrlStateMachine._pad_e4c offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, ccStageLightParam) == 0xE50, "ccAdvCtrlStateMachine.ccStageLightParam offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, ccAdvFileLoadList_embed) == 0xF80, "ccAdvCtrlStateMachine.ccAdvFileLoadList_embed offset mismatch");
static_assert(offsetof(ccAdvCtrlStateMachine, ccDuelPlayerLoader) == 0xFC0, "ccAdvCtrlStateMachine.ccDuelPlayerLoader offset mismatch");
static_assert(sizeof(ccAdvCtrlStateMachine) == 0x1010, "ccAdvCtrlStateMachine size mismatch");

/* ccAdvDropItemState: 8 fields, size=0x130, proof: LoadTh(0x130, "ccAdvDropItemState.h", 0x74) in ccAdvDropItemStateList::Add (RVA 0x1AB9D0) */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    uint8_t position_NuccVector3[0xC];
    int32_t field_11c;
    int64_t field_120;
    int64_t field_128;
} ccAdvDropItemState;
static_assert(offsetof(ccAdvDropItemState, vtable) == 0x0, "ccAdvDropItemState.vtable offset mismatch");
static_assert(offsetof(ccAdvDropItemState, base_GameActor) == 0x8, "ccAdvDropItemState.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvDropItemState, vtable_ccTaskBase) == 0x90, "ccAdvDropItemState.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvDropItemState, ccTaskBase_body) == 0x98, "ccAdvDropItemState.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvDropItemState, position_NuccVector3) == 0x110, "ccAdvDropItemState.position_NuccVector3 offset mismatch");
static_assert(offsetof(ccAdvDropItemState, field_11c) == 0x11C, "ccAdvDropItemState.field_11c offset mismatch");
static_assert(offsetof(ccAdvDropItemState, field_120) == 0x120, "ccAdvDropItemState.field_120 offset mismatch");
static_assert(offsetof(ccAdvDropItemState, field_128) == 0x128, "ccAdvDropItemState.field_128 offset mismatch");
static_assert(sizeof(ccAdvDropItemState) == 0x130, "ccAdvDropItemState size mismatch");

/* ccAdvDropItemStateParam: 21 fields, size=0xF20, proof: LoadTh(0xf20, "ccAdvDropItemState.cpp", 0x6a) in ccAdvDropItemState::Create (RVA 0x1AB03C) */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t pad_008[0x8];
    uint8_t position_NuccVector3[0xC];
    uint8_t matrix_Matrix44[0x40];
    uint8_t pad_05c[0x4];
    uint8_t blockAlloc_0[0x38];
    uint8_t blockAlloc_1[0x38];
    uint8_t pad_0d0[0x8];
    uint8_t vector4_array_32[0x800];
    uint8_t pad_8d8[0x8];
    uint8_t modelHitResultList[0x590];
    uint64_t field_e70;
    uint64_t field_e78;
    int32_t field_e80;
    int32_t field_e84;
    int32_t field_e88;
    int32_t field_e8c;
    float field_e90;
    uint32_t field_e94;
    uint64_t field_e98;
    uint8_t pad_ea0_to_end[0x80];
} ccAdvDropItemStateParam;
static_assert(offsetof(ccAdvDropItemStateParam, vtable) == 0x0, "ccAdvDropItemStateParam.vtable offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, pad_008) == 0x8, "ccAdvDropItemStateParam.pad_008 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, position_NuccVector3) == 0x10, "ccAdvDropItemStateParam.position_NuccVector3 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, matrix_Matrix44) == 0x1C, "ccAdvDropItemStateParam.matrix_Matrix44 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, pad_05c) == 0x5C, "ccAdvDropItemStateParam.pad_05c offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, blockAlloc_0) == 0x60, "ccAdvDropItemStateParam.blockAlloc_0 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, blockAlloc_1) == 0x98, "ccAdvDropItemStateParam.blockAlloc_1 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, pad_0d0) == 0xD0, "ccAdvDropItemStateParam.pad_0d0 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, vector4_array_32) == 0xD8, "ccAdvDropItemStateParam.vector4_array_32 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, pad_8d8) == 0x8D8, "ccAdvDropItemStateParam.pad_8d8 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, modelHitResultList) == 0x8E0, "ccAdvDropItemStateParam.modelHitResultList offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e70) == 0xE70, "ccAdvDropItemStateParam.field_e70 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e78) == 0xE78, "ccAdvDropItemStateParam.field_e78 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e80) == 0xE80, "ccAdvDropItemStateParam.field_e80 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e84) == 0xE84, "ccAdvDropItemStateParam.field_e84 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e88) == 0xE88, "ccAdvDropItemStateParam.field_e88 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e8c) == 0xE8C, "ccAdvDropItemStateParam.field_e8c offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e90) == 0xE90, "ccAdvDropItemStateParam.field_e90 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e94) == 0xE94, "ccAdvDropItemStateParam.field_e94 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, field_e98) == 0xE98, "ccAdvDropItemStateParam.field_e98 offset mismatch");
static_assert(offsetof(ccAdvDropItemStateParam, pad_ea0_to_end) == 0xEA0, "ccAdvDropItemStateParam.pad_ea0_to_end offset mismatch");
static_assert(sizeof(ccAdvDropItemStateParam) == 0xF20, "ccAdvDropItemStateParam size mismatch");

/* ccAdvDrawManager: 6 fields, size unknown >= 0xF0 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t sub_obj_008[0x20];
    uint8_t std_map_uint_anm[0x48];
    uint8_t std_map_uint_anm2[0x48];
    uint8_t std_vector_or_list[0x30];
    void* vtable_secondary;
} ccAdvDrawManager;
static_assert(offsetof(ccAdvDrawManager, vtable) == 0x0, "ccAdvDrawManager.vtable offset mismatch");
static_assert(offsetof(ccAdvDrawManager, sub_obj_008) == 0x8, "ccAdvDrawManager.sub_obj_008 offset mismatch");
static_assert(offsetof(ccAdvDrawManager, std_map_uint_anm) == 0x28, "ccAdvDrawManager.std_map_uint_anm offset mismatch");
static_assert(offsetof(ccAdvDrawManager, std_map_uint_anm2) == 0x70, "ccAdvDrawManager.std_map_uint_anm2 offset mismatch");
static_assert(offsetof(ccAdvDrawManager, std_vector_or_list) == 0xB8, "ccAdvDrawManager.std_vector_or_list offset mismatch");
static_assert(offsetof(ccAdvDrawManager, vtable_secondary) == 0xE8, "ccAdvDrawManager.vtable_secondary offset mismatch");
/* sizeof(ccAdvDrawManager) unproven - no static_assert on total size */

/* ccAdvDropItem: 7 fields, size unknown >= 0x120 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    int32_t field_110;
    int32_t field_114;
    int64_t field_118;
} ccAdvDropItem;
static_assert(offsetof(ccAdvDropItem, vtable) == 0x0, "ccAdvDropItem.vtable offset mismatch");
static_assert(offsetof(ccAdvDropItem, base_GameActor) == 0x8, "ccAdvDropItem.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvDropItem, vtable_ccTaskBase) == 0x90, "ccAdvDropItem.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvDropItem, ccTaskBase_body) == 0x98, "ccAdvDropItem.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvDropItem, field_110) == 0x110, "ccAdvDropItem.field_110 offset mismatch");
static_assert(offsetof(ccAdvDropItem, field_114) == 0x114, "ccAdvDropItem.field_114 offset mismatch");
static_assert(offsetof(ccAdvDropItem, field_118) == 0x118, "ccAdvDropItem.field_118 offset mismatch");
/* sizeof(ccAdvDropItem) unproven - no static_assert on total size */

/* ccAdvDropItemDraw: 5 fields, size unknown >= 0x118 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    int64_t field_110;
} ccAdvDropItemDraw;
static_assert(offsetof(ccAdvDropItemDraw, vtable) == 0x0, "ccAdvDropItemDraw.vtable offset mismatch");
static_assert(offsetof(ccAdvDropItemDraw, base_GameActor) == 0x8, "ccAdvDropItemDraw.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvDropItemDraw, vtable_ccTaskBase) == 0x90, "ccAdvDropItemDraw.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvDropItemDraw, ccTaskBase_body) == 0x98, "ccAdvDropItemDraw.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvDropItemDraw, field_110) == 0x110, "ccAdvDropItemDraw.field_110 offset mismatch");
/* sizeof(ccAdvDropItemDraw) unproven - no static_assert on total size */

/* ccAdvDropItemManager: 6 fields, size unknown >= 0x120 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    int64_t field_110;
    int64_t field_118;
} ccAdvDropItemManager;
static_assert(offsetof(ccAdvDropItemManager, vtable) == 0x0, "ccAdvDropItemManager.vtable offset mismatch");
static_assert(offsetof(ccAdvDropItemManager, base_GameActor) == 0x8, "ccAdvDropItemManager.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvDropItemManager, vtable_ccTaskBase) == 0x90, "ccAdvDropItemManager.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvDropItemManager, ccTaskBase_body) == 0x98, "ccAdvDropItemManager.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvDropItemManager, field_110) == 0x110, "ccAdvDropItemManager.field_110 offset mismatch");
static_assert(offsetof(ccAdvDropItemManager, field_118) == 0x118, "ccAdvDropItemManager.field_118 offset mismatch");
/* sizeof(ccAdvDropItemManager) unproven - no static_assert on total size */

/* ccAdvDropItemStateList: 6 fields, size unknown >= 0x148 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    uint8_t std_vector_states[0x30];
    int64_t field_140;
} ccAdvDropItemStateList;
static_assert(offsetof(ccAdvDropItemStateList, vtable) == 0x0, "ccAdvDropItemStateList.vtable offset mismatch");
static_assert(offsetof(ccAdvDropItemStateList, base_GameActor) == 0x8, "ccAdvDropItemStateList.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvDropItemStateList, vtable_ccTaskBase) == 0x90, "ccAdvDropItemStateList.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvDropItemStateList, ccTaskBase_body) == 0x98, "ccAdvDropItemStateList.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvDropItemStateList, std_vector_states) == 0x110, "ccAdvDropItemStateList.std_vector_states offset mismatch");
static_assert(offsetof(ccAdvDropItemStateList, field_140) == 0x140, "ccAdvDropItemStateList.field_140 offset mismatch");
/* sizeof(ccAdvDropItemStateList) unproven - no static_assert on total size */

/* ccAdvEffectManager: 6 fields, size unknown >= 0x150 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    uint8_t blockAlloc_0[0x38];
    int64_t field_148;
} ccAdvEffectManager;
static_assert(offsetof(ccAdvEffectManager, vtable) == 0x0, "ccAdvEffectManager.vtable offset mismatch");
static_assert(offsetof(ccAdvEffectManager, base_GameActor) == 0x8, "ccAdvEffectManager.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvEffectManager, vtable_ccTaskBase) == 0x90, "ccAdvEffectManager.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvEffectManager, ccTaskBase_body) == 0x98, "ccAdvEffectManager.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvEffectManager, blockAlloc_0) == 0x110, "ccAdvEffectManager.blockAlloc_0 offset mismatch");
static_assert(offsetof(ccAdvEffectManager, field_148) == 0x148, "ccAdvEffectManager.field_148 offset mismatch");
/* sizeof(ccAdvEffectManager) unproven - no static_assert on total size */

/* ccAdvExchangeItemParamManager: 5 fields, size unknown >= 0x118 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    int64_t field_110;
} ccAdvExchangeItemParamManager;
static_assert(offsetof(ccAdvExchangeItemParamManager, vtable) == 0x0, "ccAdvExchangeItemParamManager.vtable offset mismatch");
static_assert(offsetof(ccAdvExchangeItemParamManager, base_GameActor) == 0x8, "ccAdvExchangeItemParamManager.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvExchangeItemParamManager, vtable_ccTaskBase) == 0x90, "ccAdvExchangeItemParamManager.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvExchangeItemParamManager, ccTaskBase_body) == 0x98, "ccAdvExchangeItemParamManager.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvExchangeItemParamManager, field_110) == 0x110, "ccAdvExchangeItemParamManager.field_110 offset mismatch");
/* sizeof(ccAdvExchangeItemParamManager) unproven - no static_assert on total size */

/* ccAdvFadeStageParamManager: 6 fields, size unknown >= 0x118 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    float fade_value;
    int32_t field_114;
} ccAdvFadeStageParamManager;
static_assert(offsetof(ccAdvFadeStageParamManager, vtable) == 0x0, "ccAdvFadeStageParamManager.vtable offset mismatch");
static_assert(offsetof(ccAdvFadeStageParamManager, base_GameActor) == 0x8, "ccAdvFadeStageParamManager.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvFadeStageParamManager, vtable_ccTaskBase) == 0x90, "ccAdvFadeStageParamManager.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvFadeStageParamManager, ccTaskBase_body) == 0x98, "ccAdvFadeStageParamManager.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvFadeStageParamManager, fade_value) == 0x110, "ccAdvFadeStageParamManager.fade_value offset mismatch");
static_assert(offsetof(ccAdvFadeStageParamManager, field_114) == 0x114, "ccAdvFadeStageParamManager.field_114 offset mismatch");
/* sizeof(ccAdvFadeStageParamManager) unproven - no static_assert on total size */

/* ccAdvFileLoadList: 3 fields, size=0x40, proof: Embedded at +0xF80 in ccAdvCtrlStateMachine (size 0x40); also standalone ctor pattern */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t nuccFileLoadList_base[0x30];
    int64_t field_038;
} ccAdvFileLoadList;
static_assert(offsetof(ccAdvFileLoadList, vtable) == 0x0, "ccAdvFileLoadList.vtable offset mismatch");
static_assert(offsetof(ccAdvFileLoadList, nuccFileLoadList_base) == 0x8, "ccAdvFileLoadList.nuccFileLoadList_base offset mismatch");
static_assert(offsetof(ccAdvFileLoadList, field_038) == 0x38, "ccAdvFileLoadList.field_038 offset mismatch");
static_assert(sizeof(ccAdvFileLoadList) == 0x40, "ccAdvFileLoadList size mismatch");

/* ccAdvFixCamera: 8 fields, size unknown >= 0x130 */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    uint8_t position_NuccVector3[0xC];
    uint8_t target_NuccVector3[0xC];
    float fov;
    int32_t field_12c;
} ccAdvFixCamera;
static_assert(offsetof(ccAdvFixCamera, vtable) == 0x0, "ccAdvFixCamera.vtable offset mismatch");
static_assert(offsetof(ccAdvFixCamera, base_GameActor) == 0x8, "ccAdvFixCamera.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvFixCamera, vtable_ccTaskBase) == 0x90, "ccAdvFixCamera.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvFixCamera, ccTaskBase_body) == 0x98, "ccAdvFixCamera.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvFixCamera, position_NuccVector3) == 0x110, "ccAdvFixCamera.position_NuccVector3 offset mismatch");
static_assert(offsetof(ccAdvFixCamera, target_NuccVector3) == 0x11C, "ccAdvFixCamera.target_NuccVector3 offset mismatch");
static_assert(offsetof(ccAdvFixCamera, fov) == 0x128, "ccAdvFixCamera.fov offset mismatch");
static_assert(offsetof(ccAdvFixCamera, field_12c) == 0x12C, "ccAdvFixCamera.field_12c offset mismatch");
/* sizeof(ccAdvFixCamera) unproven - no static_assert on total size */

/* ccAdvFixCamera_LookAt: 7 fields, size unknown >= 0x12C */
typedef struct __attribute__((packed)) {
    void* vtable;
    uint8_t base_GameActor[0x88];
    void* vtable_ccTaskBase;
    uint8_t ccTaskBase_body[0x78];
    uint8_t position_NuccVector3[0xC];
    uint8_t target_NuccVector3[0xC];
    float fov;
} ccAdvFixCamera_LookAt;
static_assert(offsetof(ccAdvFixCamera_LookAt, vtable) == 0x0, "ccAdvFixCamera_LookAt.vtable offset mismatch");
static_assert(offsetof(ccAdvFixCamera_LookAt, base_GameActor) == 0x8, "ccAdvFixCamera_LookAt.base_GameActor offset mismatch");
static_assert(offsetof(ccAdvFixCamera_LookAt, vtable_ccTaskBase) == 0x90, "ccAdvFixCamera_LookAt.vtable_ccTaskBase offset mismatch");
static_assert(offsetof(ccAdvFixCamera_LookAt, ccTaskBase_body) == 0x98, "ccAdvFixCamera_LookAt.ccTaskBase_body offset mismatch");
static_assert(offsetof(ccAdvFixCamera_LookAt, position_NuccVector3) == 0x110, "ccAdvFixCamera_LookAt.position_NuccVector3 offset mismatch");
static_assert(offsetof(ccAdvFixCamera_LookAt, target_NuccVector3) == 0x11C, "ccAdvFixCamera_LookAt.target_NuccVector3 offset mismatch");
static_assert(offsetof(ccAdvFixCamera_LookAt, fov) == 0x128, "ccAdvFixCamera_LookAt.fov offset mismatch");
/* sizeof(ccAdvFixCamera_LookAt) unproven - no static_assert on total size */

#endif /* ST3A10_H */
