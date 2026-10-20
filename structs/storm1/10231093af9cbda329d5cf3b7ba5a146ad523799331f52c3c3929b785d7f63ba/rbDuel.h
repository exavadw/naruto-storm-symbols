/*
 * rbDuel.h - ccGameDuel struct layout for NARUTO STORM 1 PC (build s1)
 *
 * INFERRED from static analysis (decompilation + state_surface).
 * Object size 0x450 proven from FUN_14047ed10(0x450,...) in FUN_140250640.
 * All fields are INFERRED unless marked CONFIRMED by runtime trace.
 */

#ifndef RBDUEL_H
#define RBDUEL_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef struct __attribute__((packed)) ccGameDuel {
    int32_t state; /* 0x000 [SIM] Main dispatches; ctor=1, Init sets 2+ */
    uint32_t pad_04; /* 0x004 [PRES] alignment padding after state */
    int64_t field_08; /* 0x008 [SIM] ctor param_1[1]=1 */
    void* subobj_listHead; /* 0x010 [SIM] linked list head, FUN_140266d80 init */
    int64_t subobj_countOrFlag; /* 0x018 [SIM] param_1[3], cleared after sub-obj init */
    int32_t field_20; /* 0x020 [SIM] ctor param_1[4]=0xffffffff */
    uint32_t pad_24; /* 0x024 [PRES] alignment */
    uint8_t field_28[0x68]; /* 0x028 [UNKNOWN] gap before vtable region */
    void* vtable_primary; /* 0x090 [PRES] PTR_FUN_1406878e8 */
    void* demoObjPtr; /* 0x098 [PRES] DemoMain dereferences as function ptr */
    void* vtable_secondary; /* 0x0A0 [PRES] PTR_FUN_1406878d0 */
    uint8_t pad_a8[0x08]; /* 0x0A8 [PRES] gap */
    uint8_t field_b0[0x28]; /* 0x0B0 [UNKNOWN] gap between vtables and demoDataPtr */
    void* demoDataPtr; /* 0x0D8 [PRES] DemoMain null-checks */
    uint8_t pad_e0[0x08]; /* 0x0E0 [PRES] gap */
    uint8_t field_e8[0x08]; /* 0x0E8 [UNKNOWN] gap before demoCounter */
    int32_t demoCounter; /* 0x0F0 [PRES] DemoMain increments */
    uint32_t pad_f4; /* 0x0F4 [PRES] alignment */
    int32_t exitFlag1; /* 0x0F8 [SIM] Exit clears */
    int32_t exitFlag2; /* 0x0FC [SIM] Exit clears */
    int32_t vfunc_0x20_result; /* 0x100 [SIM] virtual call via vtable+0x20 */
    int32_t exitFlag3; /* 0x104 [SIM] Exit clears */
    int32_t demoActiveFlag; /* 0x108 [PRES] DemoMain checks ==0 */
    uint32_t pad_10c; /* 0x10C [PRES] alignment */
    uint8_t container_44[0x18]; /* 0x110 [SIM] FUN_1401e7fbc at param_1+0x44 */
    void* charaObjPtr1; /* 0x128 [SIM] Chara/CharaCtrl dereference */
    uint8_t pad_130[0x10]; /* 0x130 [SIM] gap */
    uint8_t subobj_50[0x18]; /* 0x140 [SIM] FUN_140265798 at param_1+0x50 */
    uint8_t subobj_56[0x18]; /* 0x158 [SIM] FUN_140265678 at param_1+0x56 */
    uint8_t subobj_5c[0x18]; /* 0x170 [SIM] FUN_14027f910 at param_1+0x5c */
    int32_t ninjaSongFlag; /* 0x188 [SIM] Init/NinjaSong clear */
    uint32_t pad_18c; /* 0x18C [PRES] alignment */
    uint8_t pad_190[0x18]; /* 0x190 [UNKNOWN] gap */
    uint8_t subobj_6a[0x18]; /* 0x1A8 [SIM] FUN_1401c6d00 at param_1+0x6a */
    uint8_t subobj_70[0x18]; /* 0x1C0 [SIM] FUN_1401c6d00 at param_1+0x70 */
    uint8_t subobj_76[0x18]; /* 0x1D8 [SIM] FUN_1401c6d00 at param_1+0x76 */
    uint8_t subobj_7c[0x18]; /* 0x1F0 [SIM] FUN_1401c6d00 at param_1+0x7c */
    uint8_t subobj_82[0x18]; /* 0x208 [SIM] FUN_1401c6d00 at param_1+0x82 */
    uint8_t resultSubobj_88[0x18]; /* 0x220 [SIM] FUN_1401c6d00 at param_1+0x88 */
    void* processMenuPtr; /* 0x238 [SIM] Init/NinjaSong/ProcessStartMenu null-check */
    uint8_t pad_240[0x10]; /* 0x240 [SIM] gap */
    uint8_t container_94[0x18]; /* 0x250 [SIM] FUN_1403baef0 at param_1+0x94 */
    uint8_t subobj_9a[0x18]; /* 0x268 [SIM] FUN_1401eb498 at param_1+0x9a */
    uint8_t subobj_a0[0x18]; /* 0x280 [SIM] FUN_1401eb498 at param_1+0xa0 */
    uint8_t subobj_a6[0x18]; /* 0x298 [SIM] FUN_1401eb498 at param_1+0xa6 */
    uint8_t subobj_ac[0x18]; /* 0x2B0 [SIM] FUN_1401eb498 at param_1+0xac */
    uint8_t subobj_b2[0x18]; /* 0x2C8 [SIM] FUN_1401eb498 at param_1+0xb2 */
    uint8_t subobj_b8[0x18]; /* 0x2E0 [SIM] FUN_1401eb498 at param_1+0xb8 */
    int32_t settleFlag; /* 0x2F8 [SIM] DemoMain/Init/Settled clear */
    int32_t initFlag1; /* 0x2FC [SIM] Init clears */
    int32_t resultFadeFlag; /* 0x300 [PRES] ResultFade checks ==0 */
    uint32_t pad_304; /* 0x304 [PRES] alignment */
    uint8_t resultStepObj[0x30]; /* 0x308 [PRES] FUN_1403092fc at param_1+0xc2 */
    uint8_t container_ce[0x18]; /* 0x338 [SIM] FUN_1401e7fbc at param_1+0xce */
    uint8_t subobj_d4[0x18]; /* 0x350 [SIM] FUN_14027f910 at param_1+0xd4 */
    uint8_t subobj_da[0x18]; /* 0x368 [SIM] FUN_14027f910 at param_1+0xda */
    uint8_t subobj_e0[0x18]; /* 0x380 [SIM] FUN_14027f910 at param_1+0xe0 */
    uint8_t subobj_e6[0x18]; /* 0x398 [SIM] FUN_14027f910 at param_1+0xe6 */
    uint8_t subobj_ec[0x18]; /* 0x3B0 [SIM] FUN_14027f910 at param_1+0xec */
    uint8_t subobj_f2[0x18]; /* 0x3C8 [SIM] FUN_14027f910 at param_1+0xf2 */
    int32_t signalFlag; /* 0x3E0 [SIM] Init/NinjaSong/ResultSignal clear */
    uint32_t pad_3e4; /* 0x3E4 [PRES] alignment */
    uint8_t subobj_fa[0x18]; /* 0x3E8 [SIM] FUN_1401c6d00 at param_1+0xfa */
    int32_t loadSetupFlag; /* 0x400 [SIM] Exit/Init/LoadSetup clear */
    int32_t charaCtrlFlag; /* 0x404 [SIM] CharaCtrl/Exit/Init clear */
    void* heapObj_102; /* 0x408 [SIM] ptr at param_1+0x102, alloc 0x30 */
    uint8_t pad_410[0x10]; /* 0x410 [SIM] gap */
    void* heapComparePtr1; /* 0x420 [SIM] Exit/Load compare */
    void* heapComparePtr2; /* 0x428 [SIM] Load compare */
    uint8_t pad_430[0x08]; /* 0x430 [PRES] gap */
    int32_t exitFadeFlag; /* 0x438 [PRES] ExitFade checks ==0 */
    int32_t initFlag2; /* 0x43C [SIM] Init clears */
    int32_t setupValue; /* 0x440 [SIM] LoadSetup writes uVar3 */
    int32_t field_444; /* 0x444 [SIM] ctor sets to 0xffffffff */
    int32_t stageCtrlFlag; /* 0x448 [SIM] CharaCtrl/Init/Stage clear */
    uint32_t pad_44c; /* 0x44C [PRES] trailing alignment to 0x450 */
} ccGameDuel;

/* Offset assertions */
static_assert(offsetof(ccGameDuel, state) == 0x000, "ccGameDuel.state offset mismatch");
static_assert(offsetof(ccGameDuel, pad_04) == 0x004, "ccGameDuel.pad_04 offset mismatch");
static_assert(offsetof(ccGameDuel, field_08) == 0x008, "ccGameDuel.field_08 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_listHead) == 0x010, "ccGameDuel.subobj_listHead offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_countOrFlag) == 0x018, "ccGameDuel.subobj_countOrFlag offset mismatch");
static_assert(offsetof(ccGameDuel, field_20) == 0x020, "ccGameDuel.field_20 offset mismatch");
static_assert(offsetof(ccGameDuel, pad_24) == 0x024, "ccGameDuel.pad_24 offset mismatch");
static_assert(offsetof(ccGameDuel, field_28) == 0x028, "ccGameDuel.field_28 offset mismatch");
static_assert(offsetof(ccGameDuel, vtable_primary) == 0x090, "ccGameDuel.vtable_primary offset mismatch");
static_assert(offsetof(ccGameDuel, demoObjPtr) == 0x098, "ccGameDuel.demoObjPtr offset mismatch");
static_assert(offsetof(ccGameDuel, vtable_secondary) == 0x0A0, "ccGameDuel.vtable_secondary offset mismatch");
static_assert(offsetof(ccGameDuel, pad_a8) == 0x0A8, "ccGameDuel.pad_a8 offset mismatch");
static_assert(offsetof(ccGameDuel, field_b0) == 0x0B0, "ccGameDuel.field_b0 offset mismatch");
static_assert(offsetof(ccGameDuel, demoDataPtr) == 0x0D8, "ccGameDuel.demoDataPtr offset mismatch");
static_assert(offsetof(ccGameDuel, pad_e0) == 0x0E0, "ccGameDuel.pad_e0 offset mismatch");
static_assert(offsetof(ccGameDuel, field_e8) == 0x0E8, "ccGameDuel.field_e8 offset mismatch");
static_assert(offsetof(ccGameDuel, demoCounter) == 0x0F0, "ccGameDuel.demoCounter offset mismatch");
static_assert(offsetof(ccGameDuel, pad_f4) == 0x0F4, "ccGameDuel.pad_f4 offset mismatch");
static_assert(offsetof(ccGameDuel, exitFlag1) == 0x0F8, "ccGameDuel.exitFlag1 offset mismatch");
static_assert(offsetof(ccGameDuel, exitFlag2) == 0x0FC, "ccGameDuel.exitFlag2 offset mismatch");
static_assert(offsetof(ccGameDuel, vfunc_0x20_result) == 0x100, "ccGameDuel.vfunc_0x20_result offset mismatch");
static_assert(offsetof(ccGameDuel, exitFlag3) == 0x104, "ccGameDuel.exitFlag3 offset mismatch");
static_assert(offsetof(ccGameDuel, demoActiveFlag) == 0x108, "ccGameDuel.demoActiveFlag offset mismatch");
static_assert(offsetof(ccGameDuel, pad_10c) == 0x10C, "ccGameDuel.pad_10c offset mismatch");
static_assert(offsetof(ccGameDuel, container_44) == 0x110, "ccGameDuel.container_44 offset mismatch");
static_assert(offsetof(ccGameDuel, charaObjPtr1) == 0x128, "ccGameDuel.charaObjPtr1 offset mismatch");
static_assert(offsetof(ccGameDuel, pad_130) == 0x130, "ccGameDuel.pad_130 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_50) == 0x140, "ccGameDuel.subobj_50 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_56) == 0x158, "ccGameDuel.subobj_56 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_5c) == 0x170, "ccGameDuel.subobj_5c offset mismatch");
static_assert(offsetof(ccGameDuel, ninjaSongFlag) == 0x188, "ccGameDuel.ninjaSongFlag offset mismatch");
static_assert(offsetof(ccGameDuel, pad_18c) == 0x18C, "ccGameDuel.pad_18c offset mismatch");
static_assert(offsetof(ccGameDuel, pad_190) == 0x190, "ccGameDuel.pad_190 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_6a) == 0x1A8, "ccGameDuel.subobj_6a offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_70) == 0x1C0, "ccGameDuel.subobj_70 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_76) == 0x1D8, "ccGameDuel.subobj_76 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_7c) == 0x1F0, "ccGameDuel.subobj_7c offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_82) == 0x208, "ccGameDuel.subobj_82 offset mismatch");
static_assert(offsetof(ccGameDuel, resultSubobj_88) == 0x220, "ccGameDuel.resultSubobj_88 offset mismatch");
static_assert(offsetof(ccGameDuel, processMenuPtr) == 0x238, "ccGameDuel.processMenuPtr offset mismatch");
static_assert(offsetof(ccGameDuel, pad_240) == 0x240, "ccGameDuel.pad_240 offset mismatch");
static_assert(offsetof(ccGameDuel, container_94) == 0x250, "ccGameDuel.container_94 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_9a) == 0x268, "ccGameDuel.subobj_9a offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_a0) == 0x280, "ccGameDuel.subobj_a0 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_a6) == 0x298, "ccGameDuel.subobj_a6 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_ac) == 0x2B0, "ccGameDuel.subobj_ac offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_b2) == 0x2C8, "ccGameDuel.subobj_b2 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_b8) == 0x2E0, "ccGameDuel.subobj_b8 offset mismatch");
static_assert(offsetof(ccGameDuel, settleFlag) == 0x2F8, "ccGameDuel.settleFlag offset mismatch");
static_assert(offsetof(ccGameDuel, initFlag1) == 0x2FC, "ccGameDuel.initFlag1 offset mismatch");
static_assert(offsetof(ccGameDuel, resultFadeFlag) == 0x300, "ccGameDuel.resultFadeFlag offset mismatch");
static_assert(offsetof(ccGameDuel, pad_304) == 0x304, "ccGameDuel.pad_304 offset mismatch");
static_assert(offsetof(ccGameDuel, resultStepObj) == 0x308, "ccGameDuel.resultStepObj offset mismatch");
static_assert(offsetof(ccGameDuel, container_ce) == 0x338, "ccGameDuel.container_ce offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_d4) == 0x350, "ccGameDuel.subobj_d4 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_da) == 0x368, "ccGameDuel.subobj_da offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_e0) == 0x380, "ccGameDuel.subobj_e0 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_e6) == 0x398, "ccGameDuel.subobj_e6 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_ec) == 0x3B0, "ccGameDuel.subobj_ec offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_f2) == 0x3C8, "ccGameDuel.subobj_f2 offset mismatch");
static_assert(offsetof(ccGameDuel, signalFlag) == 0x3E0, "ccGameDuel.signalFlag offset mismatch");
static_assert(offsetof(ccGameDuel, pad_3e4) == 0x3E4, "ccGameDuel.pad_3e4 offset mismatch");
static_assert(offsetof(ccGameDuel, subobj_fa) == 0x3E8, "ccGameDuel.subobj_fa offset mismatch");
static_assert(offsetof(ccGameDuel, loadSetupFlag) == 0x400, "ccGameDuel.loadSetupFlag offset mismatch");
static_assert(offsetof(ccGameDuel, charaCtrlFlag) == 0x404, "ccGameDuel.charaCtrlFlag offset mismatch");
static_assert(offsetof(ccGameDuel, heapObj_102) == 0x408, "ccGameDuel.heapObj_102 offset mismatch");
static_assert(offsetof(ccGameDuel, pad_410) == 0x410, "ccGameDuel.pad_410 offset mismatch");
static_assert(offsetof(ccGameDuel, heapComparePtr1) == 0x420, "ccGameDuel.heapComparePtr1 offset mismatch");
static_assert(offsetof(ccGameDuel, heapComparePtr2) == 0x428, "ccGameDuel.heapComparePtr2 offset mismatch");
static_assert(offsetof(ccGameDuel, pad_430) == 0x430, "ccGameDuel.pad_430 offset mismatch");
static_assert(offsetof(ccGameDuel, exitFadeFlag) == 0x438, "ccGameDuel.exitFadeFlag offset mismatch");
static_assert(offsetof(ccGameDuel, initFlag2) == 0x43C, "ccGameDuel.initFlag2 offset mismatch");
static_assert(offsetof(ccGameDuel, setupValue) == 0x440, "ccGameDuel.setupValue offset mismatch");
static_assert(offsetof(ccGameDuel, field_444) == 0x444, "ccGameDuel.field_444 offset mismatch");
static_assert(offsetof(ccGameDuel, stageCtrlFlag) == 0x448, "ccGameDuel.stageCtrlFlag offset mismatch");
static_assert(offsetof(ccGameDuel, pad_44c) == 0x44C, "ccGameDuel.pad_44c offset mismatch");

static_assert(sizeof(ccGameDuel) == 0x450, "ccGameDuel size mismatch");

#endif /* RBDUEL_H */
