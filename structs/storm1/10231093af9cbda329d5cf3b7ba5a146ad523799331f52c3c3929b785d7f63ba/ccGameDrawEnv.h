// ccGameDrawEnv (NSUNS1.exe, build s1) — reconstructed from Ghidra decompilation
// Global singleton; size >= 0x4F8 bytes (highest proven access: +0x4F0 in ctor)
// Confidence: INFERRED (static analysis only; verify with replay trace before CONFIRMED)
// Generated: 2026-10-19
#pragma once
#include <stdint.h>
#include <stddef.h>

// Forward declarations for pointer-typed sub-objects (opaque; not embedded)
typedef struct ccLightManager ccLightManager;   // light management sub-object at +0x388
typedef struct ccShadowManager ccShadowManager; // shadow management sub-object at +0x3C0

struct ccGameDrawEnv {
    // --- 0x000-0x00F: Base / vtable / unknown ---
    uint8_t _pad_000[0x10];         // 0x000 likely vtable ptr + base class data

    // --- 0x010-0x02F: Core pointers ---
    uint64_t unkPtr_010;            // 0x010 ctor zeroes
    uint64_t unkPtr_018;            // 0x018 ctor zeroes
    uint64_t unkPtr_020;            // 0x020 ctor zeroes
    uint64_t unkPtr_028;            // 0x028 ctor zeroes

    // --- 0x030-0x047: Draw state ---
    uint32_t layerIndex;            // 0x030 BeginScreen writes param_2 here; used as array index
    uint32_t drawMode;              // 0x034 checked == 0 in BeginScreen for layer selection
    uint64_t activeLayerPtr;        // 0x038 points to current layer
    uint32_t layerCount;            // 0x040 ctor zeroes
    uint8_t _pad_044[4];            // 0x044

    // --- 0x048-0x12F: Camera/render sub-object ---
    uint8_t cameraRenderObj[0xE8];  // 0x048 InitCamera/ExitCamera operate here; ctor calls FUN_1402ea21c

    // --- 0x130-0x15F: Render params ---
    float renderScale;              // 0x130 ctor sets = 1.0f (0x3f800000); multiplied into blur
    uint8_t _pad_134[4];            // 0x134
    uint64_t unk_138;               // 0x138
    uint8_t postEffectStack_140[0xC];// 0x140 ctor calls FUN_14047f900
    uint8_t _pad_14C[4];            // 0x14C
    uint32_t blurParams[4];         // 0x150 ctor loops FUN_1404ba310 x4

    // --- 0x160-0x1BF: Layer draw params (stride 0x30, 2 entries) ---
    uint8_t layerDrawParams[0x60];  // 0x160 ctor memset(0, 0x60); accessed via layerIndex*0x30

    // --- 0x1C0-0x1FF: Cached layer state ---
    uint64_t cachedLayerState_0;    // 0x1C0 copied from layerDrawParams in BeginScreen
    uint64_t cachedLayerState_1;    // 0x1C8
    uint32_t cachedBlurParam_0;     // 0x1D0
    uint32_t cachedBlurParam_1;     // 0x1D4
    float cachedBlurScale;          // 0x1D8 multiplied by renderScale
    uint32_t cachedBlurParam_3;     // 0x1DC
    uint8_t layerStateBlock[0x20];  // 0x1E0 ctor memset(0, 0x20); dtor cleanup

    // --- 0x200-0x387: Per-layer effect arrays (indexed by layerIndex) ---
    uint8_t perLayerEffects[0x188]; // 0x200 large block of per-layer indexed data

    // --- 0x388-0x3BF: Light manager sub-object ---
    ccLightManager* lightManager;   // 0x388 ctor/dtor call FUN_1402516a0/FUN_14014dd0c
    uint8_t _pad_390[0x10];         // 0x390
    uint64_t lightManagerVtable;    // 0x3A0 set to PTR_FUN_140658748 in ctor
    uint8_t _pad_3A8[0x18];         // 0x3A8

    // --- 0x3C0-0x3E7: Shadow manager sub-object ---
    ccShadowManager* shadowManager; // 0x3C0 ctor/dtor call FUN_1402600ec/FUN_14025d710
    uint64_t shadowManagerVtable;   // 0x3C8 set to PTR_FUN_140688700 in ctor
    uint64_t shadowUnk_3D0;         // 0x3D0 ctor zeroes
    uint64_t shadowUnk_3D8;         // 0x3D8 ctor zeroes

    // --- 0x3E0-0x3E7: Shadow flags ---
    uint16_t shadowFlags_3E0;       // 0x3E0 ctor zeroes
    uint8_t _pad_3E2[6];            // 0x3E2

    // --- 0x3E8-0x49F: Post-effect param stack (opaque, size inferred from gap) ---
    uint8_t postEffectStack[0xB8];  // 0x3E8 Push/PopPostEffectParam; ctor/dtor init/cleanup

    // --- 0x4A0-0x4DF: Unknown sub-object ---
    uint8_t unkSubObj_4A0[0x40];    // 0x4A0 ctor calls FUN_140480da0

    // --- 0x4E0-0x4F7: Tail fields ---
    uint64_t unkTail_4E0;           // 0x4E0 ctor zeroes
    uint64_t unkTail_4E8;           // 0x4E8 ctor zeroes
    uint64_t unkTail_4F0;           // 0x4F0 ctor zeroes (highest proven access)
};

// Compile-time offset checks (INFERRED from decompiler output)
_Static_assert(offsetof(struct ccGameDrawEnv, layerIndex) == 0x030, "layerIndex");
_Static_assert(offsetof(struct ccGameDrawEnv, drawMode) == 0x034, "drawMode");
_Static_assert(offsetof(struct ccGameDrawEnv, activeLayerPtr) == 0x038, "activeLayerPtr");
_Static_assert(offsetof(struct ccGameDrawEnv, layerCount) == 0x040, "layerCount");
_Static_assert(offsetof(struct ccGameDrawEnv, cameraRenderObj) == 0x048, "cameraRenderObj");
_Static_assert(offsetof(struct ccGameDrawEnv, renderScale) == 0x130, "renderScale");
_Static_assert(offsetof(struct ccGameDrawEnv, layerDrawParams) == 0x160, "layerDrawParams");
_Static_assert(offsetof(struct ccGameDrawEnv, cachedLayerState_0) == 0x1C0, "cachedLayerState_0");
_Static_assert(offsetof(struct ccGameDrawEnv, cachedLayerState_1) == 0x1C8, "cachedLayerState_1");
_Static_assert(offsetof(struct ccGameDrawEnv, cachedBlurParam_0) == 0x1D0, "cachedBlurParam_0");
_Static_assert(offsetof(struct ccGameDrawEnv, cachedBlurScale) == 0x1D8, "cachedBlurScale");
_Static_assert(offsetof(struct ccGameDrawEnv, perLayerEffects) == 0x200, "perLayerEffects");
_Static_assert(offsetof(struct ccGameDrawEnv, lightManager) == 0x388, "lightManager");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowManager) == 0x3C0, "shadowManager");
_Static_assert(offsetof(struct ccGameDrawEnv, postEffectStack) == 0x3E8, "postEffectStack");
_Static_assert(offsetof(struct ccGameDrawEnv, unkSubObj_4A0) == 0x4A0, "unkSubObj_4A0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkTail_4E0) == 0x4E0, "unkTail_4E0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkTail_4E8) == 0x4E8, "unkTail_4E8");
_Static_assert(offsetof(struct ccGameDrawEnv, unkTail_4F0) == 0x4F0, "unkTail_4F0");
// Size not asserted: true size unknown, >= 0x4F8