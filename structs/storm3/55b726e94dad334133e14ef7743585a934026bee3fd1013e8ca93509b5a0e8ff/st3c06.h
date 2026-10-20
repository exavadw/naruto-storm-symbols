/* Auto-generated st3c06 struct layouts for NSUNS3.exe (s3)
 * All fields INFERRED from Ghidra decompilation.
 * Sizes proven only where noted via LoadTh/factory allocators.
 * ALL fields are uint8_t[N] to guarantee exact offset matching.
 * Original C types are noted in comments for documentation.
 */
#ifndef ST3C06_H
#define ST3C06_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccScriptResource -- size unknown */
typedef struct ccScriptResource {
    uint8_t block_allocator[56]; /* 0x000 [PRES] Nucc::Memory::BlockAllocator base */
    uint8_t field_0x38[4]; /* 0x038 [UNKNOWN] ctor writes 0 at 0x7A0270 (orig:int32_t) */
    uint8_t pad_0x3c[4]; /* 0x03C [UNKNOWN] alignment */
    uint8_t field_0x40[8]; /* 0x040 [UNKNOWN] ctor writes 0 (orig:void*) */
    uint8_t field_0x48[4]; /* 0x048 [UNKNOWN] ctor writes 0 (orig:int32_t) */
} ccScriptResource;

static_assert(offsetof(ccScriptResource, block_allocator) == 0x0, "ccScriptResource.block_allocator offset mismatch");
static_assert(offsetof(ccScriptResource, field_0x38) == 0x38, "ccScriptResource.field_0x38 offset mismatch");
static_assert(offsetof(ccScriptResource, pad_0x3c) == 0x3C, "ccScriptResource.pad_0x3c offset mismatch");
static_assert(offsetof(ccScriptResource, field_0x40) == 0x40, "ccScriptResource.field_0x40 offset mismatch");
static_assert(offsetof(ccScriptResource, field_0x48) == 0x48, "ccScriptResource.field_0x48 offset mismatch");

/* ccScript -- size unknown */
typedef struct ccScript {
    uint8_t vtable_or_id[8]; /* 0x000 [PRES] ctor sets -1 then copies from ScriptParam (orig:void*) */
    uint8_t field_0x08[4]; /* 0x008 [UNKNOWN] ctor writes 0 (orig:int32_t) */
    uint8_t pad_0x0c[4]; /* 0x00C [UNKNOWN] alignment */
    uint8_t script_param_ptr[8]; /* 0x010 [PRES] param_1[2] stores ccScriptParam* (orig:void*) */
    uint8_t script_resource[56]; /* 0x018 [PRES] ccScriptResource embedded at param_1+3 */
    uint8_t field_0x50[8]; /* 0x050 [UNKNOWN] accessed in Create at 0x75AA90 (orig:void*) */
    uint8_t field_0x58[8]; /* 0x058 [UNKNOWN] accessed in Create at 0x75AA90 (orig:void*) */
} ccScript;

static_assert(offsetof(ccScript, vtable_or_id) == 0x0, "ccScript.vtable_or_id offset mismatch");
static_assert(offsetof(ccScript, field_0x08) == 0x8, "ccScript.field_0x08 offset mismatch");
static_assert(offsetof(ccScript, pad_0x0c) == 0xC, "ccScript.pad_0x0c offset mismatch");
static_assert(offsetof(ccScript, script_param_ptr) == 0x10, "ccScript.script_param_ptr offset mismatch");
static_assert(offsetof(ccScript, script_resource) == 0x18, "ccScript.script_resource offset mismatch");
static_assert(offsetof(ccScript, field_0x50) == 0x50, "ccScript.field_0x50 offset mismatch");
static_assert(offsetof(ccScript, field_0x58) == 0x58, "ccScript.field_0x58 offset mismatch");

/* ccSimpleScript -- size unknown */
typedef struct ccSimpleScript {
    uint8_t vtable[8]; /* 0x000 [PRES] Init calls vfunc+8 (orig:void*) */
    uint8_t data_ptr[8]; /* 0x008 [PRES] Init sets param_1[1] (orig:void*) */
    uint8_t field_0x10[4]; /* 0x010 [UNKNOWN] Init sets param_1+2 as u4 (orig:int32_t) */
    uint8_t field_0x14[8]; /* 0x014 [UNKNOWN] Init clears (orig:uint64_t) */
    uint8_t field_0x1c[8]; /* 0x01C [UNKNOWN] Init clears (orig:uint64_t) */
    uint8_t field_0x24[2]; /* 0x024 [UNKNOWN] Init clears as u16 (orig:uint16_t) */
    uint8_t pad_0x26[2]; /* 0x026 [UNKNOWN] alignment */
    uint8_t process_array[32]; /* 0x028 [UNKNOWN] Init loop clears 8xu32 (orig:uint32_t) */
    uint8_t index_array[16]; /* 0x048 [UNKNOWN] Init loop clears 8xu16 (orig:uint16_t) */
    uint8_t field_0x58[4]; /* 0x058 [UNKNOWN] Init clears param_1+0xb (orig:int32_t) */
} ccSimpleScript;

static_assert(offsetof(ccSimpleScript, vtable) == 0x0, "ccSimpleScript.vtable offset mismatch");
static_assert(offsetof(ccSimpleScript, data_ptr) == 0x8, "ccSimpleScript.data_ptr offset mismatch");
static_assert(offsetof(ccSimpleScript, field_0x10) == 0x10, "ccSimpleScript.field_0x10 offset mismatch");
static_assert(offsetof(ccSimpleScript, field_0x14) == 0x14, "ccSimpleScript.field_0x14 offset mismatch");
static_assert(offsetof(ccSimpleScript, field_0x1c) == 0x1C, "ccSimpleScript.field_0x1c offset mismatch");
static_assert(offsetof(ccSimpleScript, field_0x24) == 0x24, "ccSimpleScript.field_0x24 offset mismatch");
static_assert(offsetof(ccSimpleScript, pad_0x26) == 0x26, "ccSimpleScript.pad_0x26 offset mismatch");
static_assert(offsetof(ccSimpleScript, process_array) == 0x28, "ccSimpleScript.process_array offset mismatch");
static_assert(offsetof(ccSimpleScript, index_array) == 0x48, "ccSimpleScript.index_array offset mismatch");
static_assert(offsetof(ccSimpleScript, field_0x58) == 0x58, "ccSimpleScript.field_0x58 offset mismatch");

/* ccSimpleScriptDataBin -- size unknown */
typedef struct ccSimpleScriptDataBin {
    uint8_t vtable[8]; /* 0x000 [PRES] inferred (orig:void*) */
    uint8_t entry_count[4]; /* 0x008 [PRES] Create sets from input (orig:uint32_t) */
    uint8_t pad_0x0c[4]; /* 0x00C [UNKNOWN] alignment */
    uint8_t data_buffer[8]; /* 0x010 [PRES] Create allocates and stores (orig:void*) */
    uint8_t pad_0x18[8]; /* 0x018 [UNKNOWN] gap */
    uint8_t field_0x20[8]; /* 0x020 [UNKNOWN] Delete accesses (orig:void*) */
    uint8_t pad_0x28[16]; /* 0x028 [UNKNOWN] gap */
    uint8_t field_0x38[8]; /* 0x038 [UNKNOWN] Delete accesses (orig:void*) */
} ccSimpleScriptDataBin;

static_assert(offsetof(ccSimpleScriptDataBin, vtable) == 0x0, "ccSimpleScriptDataBin.vtable offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, entry_count) == 0x8, "ccSimpleScriptDataBin.entry_count offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, pad_0x0c) == 0xC, "ccSimpleScriptDataBin.pad_0x0c offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, data_buffer) == 0x10, "ccSimpleScriptDataBin.data_buffer offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, pad_0x18) == 0x18, "ccSimpleScriptDataBin.pad_0x18 offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, field_0x20) == 0x20, "ccSimpleScriptDataBin.field_0x20 offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, pad_0x28) == 0x28, "ccSimpleScriptDataBin.pad_0x28 offset mismatch");
static_assert(offsetof(ccSimpleScriptDataBin, field_0x38) == 0x38, "ccSimpleScriptDataBin.field_0x38 offset mismatch");

/* ccSceneDemo -- size unknown */
typedef struct ccSceneDemo {
    uint8_t vtable[8]; /* 0x000 [PRES] inferred scene base (orig:void*) */
    uint8_t base_scene_data[288]; /* 0x008 [PRES] gap to first known field */
    uint8_t field_0x128[8]; /* 0x128 [UNKNOWN] Initialize/Execute access (orig:void*) */
    uint8_t pad_0x130[72]; /* 0x130 [UNKNOWN] gap */
    uint8_t field_0x178[8]; /* 0x178 [UNKNOWN] Execute accesses (orig:void*) */
} ccSceneDemo;

static_assert(offsetof(ccSceneDemo, vtable) == 0x0, "ccSceneDemo.vtable offset mismatch");
static_assert(offsetof(ccSceneDemo, base_scene_data) == 0x8, "ccSceneDemo.base_scene_data offset mismatch");
static_assert(offsetof(ccSceneDemo, field_0x128) == 0x128, "ccSceneDemo.field_0x128 offset mismatch");
static_assert(offsetof(ccSceneDemo, pad_0x130) == 0x130, "ccSceneDemo.pad_0x130 offset mismatch");
static_assert(offsetof(ccSceneDemo, field_0x178) == 0x178, "ccSceneDemo.field_0x178 offset mismatch");

/* ccSceneDemoState -- size 0x350 */
typedef struct ccSceneDemoState {
    uint8_t vtable[8]; /* 0x000 [PRES] ctor sets PTR_FUN_14094bf98 (orig:void*) */
    uint8_t task_state[4]; /* 0x008 [PRES] ctor sets 0xf (orig:int32_t) */
    uint8_t field_0x0c[4]; /* 0x00C [UNKNOWN] ctor sets 1 (orig:int32_t) */
    uint8_t field_0x10[8]; /* 0x010 [UNKNOWN] param_1[0xd]=0 (orig:void*) */
    uint8_t field_0x18[8]; /* 0x018 [UNKNOWN] param_1[0xe]=0 (orig:void*) */
    uint8_t field_0x20[8]; /* 0x020 [UNKNOWN] param_1[0xf]=0 (orig:void*) */
    uint8_t field_0x28[8]; /* 0x028 [UNKNOWN] param_1[0x10]=0 (orig:void*) */
    uint8_t field_0x30[8]; /* 0x030 [UNKNOWN] param_1[0x11]=0 (orig:void*) */
    uint8_t field_0x38[8]; /* 0x038 [UNKNOWN] gap before task ptr (orig:void*) */
    uint8_t field_0x40[8]; /* 0x040 [UNKNOWN] gap (orig:void*) */
    uint8_t task_data_ptr[8]; /* 0x048 [PRES] param_1[9]=PTR_DAT_140af86d0 (orig:void*) */
    uint8_t task_id[4]; /* 0x050 [PRES] param_1+10=-1 byte 0x50 (orig:int32_t) */
    uint8_t demo_scene_ptr[8]; /* 0x054 [PRES] ctor clears states read/write (orig:void*) */
    uint8_t field_0x5c[4]; /* 0x05C [UNKNOWN] ctor clears (orig:int32_t) */
    uint8_t field_0x60[8]; /* 0x060 [UNKNOWN] states access (orig:void*) */
    uint8_t field_0x68[8]; /* 0x068 [UNKNOWN] gap (orig:void*) */
    uint8_t script_or_state_ptr[8]; /* 0x070 [PRES] many states access (orig:void*) */
    uint8_t field_0x78[8]; /* 0x078 [UNKNOWN] states access (orig:void*) */
    uint8_t field_0x80[8]; /* 0x080 [UNKNOWN] states access (orig:void*) */
    uint8_t field_0x88[8]; /* 0x088 [UNKNOWN] EnterUnlockCollection (orig:void*) */
    uint8_t field_0x90[8]; /* 0x090 [UNKNOWN] SetDemoSelectSceneToDemoScene (orig:void*) */
    uint8_t pad_0x98[16]; /* 0x098 [UNKNOWN] gap */
    uint8_t field_0xa8[8]; /* 0x0A8 [UNKNOWN] SetDemoSelectSceneToDemoScene (orig:void*) */
    uint8_t embedded_allocators_and_scripts[80]; /* 0x0B0 [PRES] BlockAllocators + ccScripts */
    uint8_t field_0x100[8]; /* 0x100 [UNKNOWN] StartExecScript (orig:void*) */
    uint8_t pad_0x108[16]; /* 0x108 [UNKNOWN] gap */
    uint8_t field_0x118[8]; /* 0x118 [UNKNOWN] StartExecScript (orig:void*) */
    uint8_t pad_0x120[24]; /* 0x120 [UNKNOWN] gap */
    uint8_t embedded_ccScript_1[56]; /* 0x138 [PRES] ccScript at param_1+0x27 */
    uint8_t pad_0x170[48]; /* 0x170 [UNKNOWN] gap */
    uint8_t embedded_ccScript_2[56]; /* 0x1A0 [PRES] ccScript at param_1+0x34 */
    uint8_t pad_0x1d8[48]; /* 0x1D8 [UNKNOWN] gap */
    uint8_t field_0x208[4]; /* 0x208 [UNKNOWN] param_1[0x41]=0 (orig:int32_t) */
    uint8_t exec_state[4]; /* 0x20C [PRES] EnterExec/StateExec (orig:int32_t) */
    uint8_t field_0x210[8]; /* 0x210 [UNKNOWN] StateExec (orig:void*) */
    uint8_t skip_or_capture_ptr[8]; /* 0x218 [PRES] EnterSkipWait/StateCapture (orig:void*) */
    uint8_t field_0x220[8]; /* 0x220 [UNKNOWN] EnterExec/StateCapture (orig:void*) */
    uint8_t tail_pad[296]; /* 0x228 [UNKNOWN] to 0x350 */
} ccSceneDemoState;

static_assert(offsetof(ccSceneDemoState, vtable) == 0x0, "ccSceneDemoState.vtable offset mismatch");
static_assert(offsetof(ccSceneDemoState, task_state) == 0x8, "ccSceneDemoState.task_state offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x0c) == 0xC, "ccSceneDemoState.field_0x0c offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x10) == 0x10, "ccSceneDemoState.field_0x10 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x18) == 0x18, "ccSceneDemoState.field_0x18 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x20) == 0x20, "ccSceneDemoState.field_0x20 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x28) == 0x28, "ccSceneDemoState.field_0x28 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x30) == 0x30, "ccSceneDemoState.field_0x30 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x38) == 0x38, "ccSceneDemoState.field_0x38 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x40) == 0x40, "ccSceneDemoState.field_0x40 offset mismatch");
static_assert(offsetof(ccSceneDemoState, task_data_ptr) == 0x48, "ccSceneDemoState.task_data_ptr offset mismatch");
static_assert(offsetof(ccSceneDemoState, task_id) == 0x50, "ccSceneDemoState.task_id offset mismatch");
static_assert(offsetof(ccSceneDemoState, demo_scene_ptr) == 0x54, "ccSceneDemoState.demo_scene_ptr offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x5c) == 0x5C, "ccSceneDemoState.field_0x5c offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x60) == 0x60, "ccSceneDemoState.field_0x60 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x68) == 0x68, "ccSceneDemoState.field_0x68 offset mismatch");
static_assert(offsetof(ccSceneDemoState, script_or_state_ptr) == 0x70, "ccSceneDemoState.script_or_state_ptr offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x78) == 0x78, "ccSceneDemoState.field_0x78 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x80) == 0x80, "ccSceneDemoState.field_0x80 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x88) == 0x88, "ccSceneDemoState.field_0x88 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x90) == 0x90, "ccSceneDemoState.field_0x90 offset mismatch");
static_assert(offsetof(ccSceneDemoState, pad_0x98) == 0x98, "ccSceneDemoState.pad_0x98 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0xa8) == 0xA8, "ccSceneDemoState.field_0xa8 offset mismatch");
static_assert(offsetof(ccSceneDemoState, embedded_allocators_and_scripts) == 0xB0, "ccSceneDemoState.embedded_allocators_and_scripts offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x100) == 0x100, "ccSceneDemoState.field_0x100 offset mismatch");
static_assert(offsetof(ccSceneDemoState, pad_0x108) == 0x108, "ccSceneDemoState.pad_0x108 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x118) == 0x118, "ccSceneDemoState.field_0x118 offset mismatch");
static_assert(offsetof(ccSceneDemoState, pad_0x120) == 0x120, "ccSceneDemoState.pad_0x120 offset mismatch");
static_assert(offsetof(ccSceneDemoState, embedded_ccScript_1) == 0x138, "ccSceneDemoState.embedded_ccScript_1 offset mismatch");
static_assert(offsetof(ccSceneDemoState, pad_0x170) == 0x170, "ccSceneDemoState.pad_0x170 offset mismatch");
static_assert(offsetof(ccSceneDemoState, embedded_ccScript_2) == 0x1A0, "ccSceneDemoState.embedded_ccScript_2 offset mismatch");
static_assert(offsetof(ccSceneDemoState, pad_0x1d8) == 0x1D8, "ccSceneDemoState.pad_0x1d8 offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x208) == 0x208, "ccSceneDemoState.field_0x208 offset mismatch");
static_assert(offsetof(ccSceneDemoState, exec_state) == 0x20C, "ccSceneDemoState.exec_state offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x210) == 0x210, "ccSceneDemoState.field_0x210 offset mismatch");
static_assert(offsetof(ccSceneDemoState, skip_or_capture_ptr) == 0x218, "ccSceneDemoState.skip_or_capture_ptr offset mismatch");
static_assert(offsetof(ccSceneDemoState, field_0x220) == 0x220, "ccSceneDemoState.field_0x220 offset mismatch");
static_assert(offsetof(ccSceneDemoState, tail_pad) == 0x228, "ccSceneDemoState.tail_pad offset mismatch");

/* ccSceneGroupBattleLoDemo -- size 0x328 */
typedef struct ccSceneGroupBattleLoDemo {
    uint8_t vtable[8]; /* 0x000 [PRES] ctor sets PTR_FUN_140945fe8 (orig:void*) */
    uint8_t ccScene_base[184]; /* 0x008 [PRES] ccScene::ccScene() base */
    uint8_t pad_0xc0[104]; /* 0x0C0 [UNKNOWN] gap to load_data */
    uint8_t load_data_ptr[8]; /* 0x128 [PRES] Ctrl_LOAD/Initialize (orig:void*) */
    uint8_t field_0x130[8]; /* 0x130 [UNKNOWN] Ctrl_LOAD/Initialize (orig:void*) */
    uint8_t resource_handle[8]; /* 0x138 [PRES] Ctrl_LOAD/Finalize/Initialize (orig:void*) */
    uint8_t demo_param_and_objects[376]; /* 0x140 [PRES] ccDemoParamManager+ccStageObjectManager region */
    uint8_t main_ctrl_ptr[8]; /* 0x2B8 [PRES] Ctrl_MAIN/Finalize/Initialize (orig:void*) */
    uint8_t pad_0x2c0[88]; /* 0x2C0 [UNKNOWN] gap */
    uint8_t field_0x318[8]; /* 0x318 [PRES] Ctrl_MAIN/Finalize param_1[99] (orig:void*) */
    uint8_t field_0x320[4]; /* 0x320 [UNKNOWN] param_1[100]=0 (orig:int32_t) */
    uint8_t tail_pad[4]; /* 0x324 [UNKNOWN] to 0x328 */
} ccSceneGroupBattleLoDemo;

static_assert(offsetof(ccSceneGroupBattleLoDemo, vtable) == 0x0, "ccSceneGroupBattleLoDemo.vtable offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, ccScene_base) == 0x8, "ccSceneGroupBattleLoDemo.ccScene_base offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, pad_0xc0) == 0xC0, "ccSceneGroupBattleLoDemo.pad_0xc0 offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, load_data_ptr) == 0x128, "ccSceneGroupBattleLoDemo.load_data_ptr offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, field_0x130) == 0x130, "ccSceneGroupBattleLoDemo.field_0x130 offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, resource_handle) == 0x138, "ccSceneGroupBattleLoDemo.resource_handle offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, demo_param_and_objects) == 0x140, "ccSceneGroupBattleLoDemo.demo_param_and_objects offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, main_ctrl_ptr) == 0x2B8, "ccSceneGroupBattleLoDemo.main_ctrl_ptr offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, pad_0x2c0) == 0x2C0, "ccSceneGroupBattleLoDemo.pad_0x2c0 offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, field_0x318) == 0x318, "ccSceneGroupBattleLoDemo.field_0x318 offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, field_0x320) == 0x320, "ccSceneGroupBattleLoDemo.field_0x320 offset mismatch");
static_assert(offsetof(ccSceneGroupBattleLoDemo, tail_pad) == 0x324, "ccSceneGroupBattleLoDemo.tail_pad offset mismatch");

/* ccStageGimmickExplodeEvent -- size 0x1A8 */
typedef struct ccStageGimmickExplodeEvent {
    uint8_t vtable[8]; /* 0x000 [PRES] inherits ccStageGimmickExplode (orig:void*) */
    uint8_t parent_base[296]; /* 0x008 [PRES] ccStageGimmickExplode base */
    uint8_t bounding_box[64]; /* 0x130 [PRES] Matrix44 translate at +0x130 */
    uint8_t field_0x170[4]; /* 0x170 [UNKNOWN] Create writes 0 (orig:int32_t) */
    uint8_t tail_pad[52]; /* 0x174 [UNKNOWN] to 0x1A8 */
} ccStageGimmickExplodeEvent;

static_assert(offsetof(ccStageGimmickExplodeEvent, vtable) == 0x0, "ccStageGimmickExplodeEvent.vtable offset mismatch");
static_assert(offsetof(ccStageGimmickExplodeEvent, parent_base) == 0x8, "ccStageGimmickExplodeEvent.parent_base offset mismatch");
static_assert(offsetof(ccStageGimmickExplodeEvent, bounding_box) == 0x130, "ccStageGimmickExplodeEvent.bounding_box offset mismatch");
static_assert(offsetof(ccStageGimmickExplodeEvent, field_0x170) == 0x170, "ccStageGimmickExplodeEvent.field_0x170 offset mismatch");
static_assert(offsetof(ccStageGimmickExplodeEvent, tail_pad) == 0x174, "ccStageGimmickExplodeEvent.tail_pad offset mismatch");

/* ccStateAdvBattleEndSequence -- size 0xD0 */
typedef struct ccStateAdvBattleEndSequence {
    uint8_t vtable[8]; /* 0x000 [PRES] inferred (orig:void*) */
    uint8_t base_state[76]; /* 0x008 [PRES] state machine base */
    uint8_t field_0x54[8]; /* 0x054 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0x5c[4]; /* 0x05C [UNKNOWN] state_surface (orig:int32_t) */
    uint8_t field_0x60[4]; /* 0x060 [UNKNOWN] state_surface (orig:int32_t) */
    uint8_t pad_0x64[4]; /* 0x064 [UNKNOWN] alignment */
    uint8_t field_0x68[8]; /* 0x068 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0x70[8]; /* 0x070 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0x78[8]; /* 0x078 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0x80[8]; /* 0x080 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0x88[8]; /* 0x088 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0x90[8]; /* 0x090 [UNKNOWN] state_surface (orig:void*) */
    uint8_t pad_0x98[8]; /* 0x098 [UNKNOWN] gap */
    uint8_t field_0xa0[8]; /* 0x0A0 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0xa8[8]; /* 0x0A8 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0xb0[8]; /* 0x0B0 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0xb8[8]; /* 0x0B8 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0xc0[8]; /* 0x0C0 [UNKNOWN] state_surface (orig:void*) */
    uint8_t field_0xc8[4]; /* 0x0C8 [UNKNOWN] state_surface last (orig:int32_t) */
    uint8_t tail_pad[4]; /* 0x0CC [UNKNOWN] to 0xD0 */
} ccStateAdvBattleEndSequence;

static_assert(offsetof(ccStateAdvBattleEndSequence, vtable) == 0x0, "ccStateAdvBattleEndSequence.vtable offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, base_state) == 0x8, "ccStateAdvBattleEndSequence.base_state offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x54) == 0x54, "ccStateAdvBattleEndSequence.field_0x54 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x5c) == 0x5C, "ccStateAdvBattleEndSequence.field_0x5c offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x60) == 0x60, "ccStateAdvBattleEndSequence.field_0x60 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, pad_0x64) == 0x64, "ccStateAdvBattleEndSequence.pad_0x64 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x68) == 0x68, "ccStateAdvBattleEndSequence.field_0x68 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x70) == 0x70, "ccStateAdvBattleEndSequence.field_0x70 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x78) == 0x78, "ccStateAdvBattleEndSequence.field_0x78 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x80) == 0x80, "ccStateAdvBattleEndSequence.field_0x80 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x88) == 0x88, "ccStateAdvBattleEndSequence.field_0x88 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0x90) == 0x90, "ccStateAdvBattleEndSequence.field_0x90 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, pad_0x98) == 0x98, "ccStateAdvBattleEndSequence.pad_0x98 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0xa0) == 0xA0, "ccStateAdvBattleEndSequence.field_0xa0 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0xa8) == 0xA8, "ccStateAdvBattleEndSequence.field_0xa8 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0xb0) == 0xB0, "ccStateAdvBattleEndSequence.field_0xb0 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0xb8) == 0xB8, "ccStateAdvBattleEndSequence.field_0xb8 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0xc0) == 0xC0, "ccStateAdvBattleEndSequence.field_0xc0 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, field_0xc8) == 0xC8, "ccStateAdvBattleEndSequence.field_0xc8 offset mismatch");
static_assert(offsetof(ccStateAdvBattleEndSequence, tail_pad) == 0xCC, "ccStateAdvBattleEndSequence.tail_pad offset mismatch");

/* ccStateOpeningMovie -- size unknown */
typedef struct ccStateOpeningMovie {
    uint8_t vtable[8]; /* 0x000 [PRES] inferred state base (orig:void*) */
    uint8_t base_state[76]; /* 0x008 [PRES] state machine base */
    uint8_t field_0x54[8]; /* 0x054 [UNKNOWN] StateLoad/StateExec access (orig:void*) */
    uint8_t pad_0x5c[4]; /* 0x05C [UNKNOWN] alignment */
    uint8_t field_0x60[8]; /* 0x060 [UNKNOWN] StateLoad/StateExec access (orig:void*) */
    uint8_t pad_0x68[8]; /* 0x068 [UNKNOWN] gap */
    uint8_t field_0x70[8]; /* 0x070 [UNKNOWN] StateExec access (orig:void*) */
    uint8_t field_0x78[8]; /* 0x078 [UNKNOWN] StateExec access (orig:void*) */
} ccStateOpeningMovie;

static_assert(offsetof(ccStateOpeningMovie, vtable) == 0x0, "ccStateOpeningMovie.vtable offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, base_state) == 0x8, "ccStateOpeningMovie.base_state offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, field_0x54) == 0x54, "ccStateOpeningMovie.field_0x54 offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, pad_0x5c) == 0x5C, "ccStateOpeningMovie.pad_0x5c offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, field_0x60) == 0x60, "ccStateOpeningMovie.field_0x60 offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, pad_0x68) == 0x68, "ccStateOpeningMovie.pad_0x68 offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, field_0x70) == 0x70, "ccStateOpeningMovie.field_0x70 offset mismatch");
static_assert(offsetof(ccStateOpeningMovie, field_0x78) == 0x78, "ccStateOpeningMovie.field_0x78 offset mismatch");

/* ccTalkState -- size unknown */
typedef struct ccTalkState {
    uint8_t vtable[8]; /* 0x000 [PRES] inferred state base (orig:void*) */
    uint8_t base_state[76]; /* 0x008 [PRES] state machine base */
    uint8_t field_0x54[4]; /* 0x054 [UNKNOWN] Entry writes 2 (orig:int32_t) */
    uint8_t pad_0x58[8]; /* 0x058 [UNKNOWN] gap */
    uint8_t field_0x60[4]; /* 0x060 [UNKNOWN] Entry writes 1 (orig:int32_t) */
    uint8_t pad_0x64[4]; /* 0x064 [UNKNOWN] alignment */
    uint8_t pad_0x68[8]; /* 0x068 [UNKNOWN] gap */
    uint8_t field_0x70[4]; /* 0x070 [UNKNOWN] Entry sets from param_3 (orig:int32_t) */
    uint8_t field_0x74[4]; /* 0x074 [UNKNOWN] Entry sets from param_2 (orig:int32_t) */
    uint8_t tail_pad[88]; /* 0x078 [UNKNOWN] gap to end */
} ccTalkState;

static_assert(offsetof(ccTalkState, vtable) == 0x0, "ccTalkState.vtable offset mismatch");
static_assert(offsetof(ccTalkState, base_state) == 0x8, "ccTalkState.base_state offset mismatch");
static_assert(offsetof(ccTalkState, field_0x54) == 0x54, "ccTalkState.field_0x54 offset mismatch");
static_assert(offsetof(ccTalkState, pad_0x58) == 0x58, "ccTalkState.pad_0x58 offset mismatch");
static_assert(offsetof(ccTalkState, field_0x60) == 0x60, "ccTalkState.field_0x60 offset mismatch");
static_assert(offsetof(ccTalkState, pad_0x64) == 0x64, "ccTalkState.pad_0x64 offset mismatch");
static_assert(offsetof(ccTalkState, pad_0x68) == 0x68, "ccTalkState.pad_0x68 offset mismatch");
static_assert(offsetof(ccTalkState, field_0x70) == 0x70, "ccTalkState.field_0x70 offset mismatch");
static_assert(offsetof(ccTalkState, field_0x74) == 0x74, "ccTalkState.field_0x74 offset mismatch");
static_assert(offsetof(ccTalkState, tail_pad) == 0x78, "ccTalkState.tail_pad offset mismatch");

#endif /* ST3C06_H */
