/* st3c04.h - Story cutscene/event state structs for Storm 3 HD (s3, NSUNS3.exe x64)
 * Generated from the decompiler cache state_surface analysis.
 * All layouts are INFERRED from static decompilation, not CONFIRMED at runtime.
 * Build: s3 (NSUNS3.exe, SHA256 55b726e9..., base 0x140000000)
 */
#ifndef ST3C04_H
#define ST3C04_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccEventMessageState
 * Seeds analyzed: 13
 * Fields found: 14 (10 with known size)
 * Size: unknown, >= 0x1B0 (last field at 0x1A8, size 8)
 * Vtable: see constructor/destructor decompilations
 */
struct __attribute__((packed)) ccEventMessageState {
    uint8_t _pad_0x0[0x78];
    uint8_t field_0x78; /* 0x78 */
    uint8_t _pad_0x79[0xF];
    uint64_t field_0x88; /* 0x88 */
    uint64_t field_0x90; /* 0x90 */
    uint64_t field_0x98; /* 0x98 */
    uint8_t _pad_0xA0[0x48];
    uint64_t field_0xE8; /* 0xE8 */
    uint8_t _pad_0xF0[0x18];
    uint64_t field_0x108; /* 0x108 */
    uint8_t _pad_0x110[0x28];
    uint64_t field_0x138; /* 0x138 */
    uint8_t _pad_0x140[0x28];
    uint64_t field_0x168; /* 0x168 */
    uint8_t _pad_0x170[0x10];
    uint64_t field_0x180; /* 0x180 */
    uint8_t _pad_0x188[0x20];
    uint64_t field_0x1A8; /* 0x1A8 */
};
static_assert(offsetof(struct ccEventMessageState, field_0x78) == 0x78, "ccEventMessageState.field_0x78 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x88) == 0x88, "ccEventMessageState.field_0x88 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x90) == 0x90, "ccEventMessageState.field_0x90 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x98) == 0x98, "ccEventMessageState.field_0x98 offset");
static_assert(offsetof(struct ccEventMessageState, field_0xE8) == 0xE8, "ccEventMessageState.field_0xE8 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x108) == 0x108, "ccEventMessageState.field_0x108 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x138) == 0x138, "ccEventMessageState.field_0x138 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x168) == 0x168, "ccEventMessageState.field_0x168 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x180) == 0x180, "ccEventMessageState.field_0x180 offset");
static_assert(offsetof(struct ccEventMessageState, field_0x1A8) == 0x1A8, "ccEventMessageState.field_0x1A8 offset");

/* ccEventPostEffectState: no instance state fields found by state_surface
 * Evidence: 7 methods analyzed, 0 field accesses detected.
 * Warnings: ccEventPostEffectState::SetEnterFrame: unknown param_1 element size; only byte-c
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventPostEffectState {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventScreenFilterState
 * Seeds analyzed: 10
 * Fields found: 3 (2 with known size)
 * Size: unknown, >= 0xD0 (last field at 0xC8, size 8)
 * Vtable: see constructor/destructor decompilations
 */
struct __attribute__((packed)) ccEventScreenFilterState {
    uint8_t _pad_0x0[0x80];
    uint64_t field_0x80; /* 0x80 */
    uint8_t _pad_0x88[0x40];
    uint64_t field_0xC8; /* 0xC8 */
};
static_assert(offsetof(struct ccEventScreenFilterState, field_0x80) == 0x80, "ccEventScreenFilterState.field_0x80 offset");
static_assert(offsetof(struct ccEventScreenFilterState, field_0xC8) == 0xC8, "ccEventScreenFilterState.field_0xC8 offset");

/* ccEventShadowState
 * Seeds analyzed: 5
 * Fields found: 19 (16 with known size)
 * Size: unknown, >= 0x120 (last field at 0x118, size 8)
 * Vtable: see constructor/destructor decompilations
 */
struct __attribute__((packed)) ccEventShadowState {
    uint8_t _pad_0x0[0x54];
    uint64_t vtable_or_base_0x54; /* 0x54 */
    uint32_t flags_0x5C; /* 0x5C */
    uint32_t field_0x60; /* 0x60 */
    uint8_t _pad_0x64[0x4];
    uint64_t field_0x68; /* 0x68 */
    uint64_t field_0x70; /* 0x70 */
    uint64_t field_0x78; /* 0x78 */
    uint64_t field_0x80; /* 0x80 */
    uint64_t field_0x88; /* 0x88 */
    uint64_t field_0x90; /* 0x90 */
    uint8_t _pad_0x98[0x4];
    uint32_t field_0x9C; /* 0x9C */
    uint8_t _pad_0xA0[0x10];
    uint64_t field_0xB0; /* 0xB0 */
    uint8_t _pad_0xB8[0x18];
    uint64_t field_0xD0; /* 0xD0 */
    uint64_t field_0xD8; /* 0xD8 */
    uint8_t _pad_0xE0[0x28];
    uint64_t field_0x108; /* 0x108 */
    uint64_t field_0x110; /* 0x110 */
    uint64_t field_0x118; /* 0x118 */
};
static_assert(offsetof(struct ccEventShadowState, vtable_or_base_0x54) == 0x54, "ccEventShadowState.vtable_or_base_0x54 offset");
static_assert(offsetof(struct ccEventShadowState, flags_0x5C) == 0x5C, "ccEventShadowState.flags_0x5C offset");
static_assert(offsetof(struct ccEventShadowState, field_0x60) == 0x60, "ccEventShadowState.field_0x60 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x68) == 0x68, "ccEventShadowState.field_0x68 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x70) == 0x70, "ccEventShadowState.field_0x70 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x78) == 0x78, "ccEventShadowState.field_0x78 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x80) == 0x80, "ccEventShadowState.field_0x80 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x88) == 0x88, "ccEventShadowState.field_0x88 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x90) == 0x90, "ccEventShadowState.field_0x90 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x9C) == 0x9C, "ccEventShadowState.field_0x9C offset");
static_assert(offsetof(struct ccEventShadowState, field_0xB0) == 0xB0, "ccEventShadowState.field_0xB0 offset");
static_assert(offsetof(struct ccEventShadowState, field_0xD0) == 0xD0, "ccEventShadowState.field_0xD0 offset");
static_assert(offsetof(struct ccEventShadowState, field_0xD8) == 0xD8, "ccEventShadowState.field_0xD8 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x108) == 0x108, "ccEventShadowState.field_0x108 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x110) == 0x110, "ccEventShadowState.field_0x110 offset");
static_assert(offsetof(struct ccEventShadowState, field_0x118) == 0x118, "ccEventShadowState.field_0x118 offset");

/* ccEventSoftFocusState
 * Seeds analyzed: 4
 * Fields found: 12 (12 with known size)
 * Size: unknown, >= 0xB0 (last field at 0xA8, size 8)
 * Vtable: see constructor/destructor decompilations
 */
struct __attribute__((packed)) ccEventSoftFocusState {
    uint8_t _pad_0x0[0x54];
    uint64_t vtable_or_base_0x54; /* 0x54 */
    uint32_t flags_0x5C; /* 0x5C */
    uint32_t field_0x60; /* 0x60 */
    uint8_t _pad_0x64[0x4];
    uint64_t field_0x68; /* 0x68 */
    uint64_t field_0x70; /* 0x70 */
    uint64_t field_0x78; /* 0x78 */
    uint64_t field_0x80; /* 0x80 */
    uint64_t field_0x88; /* 0x88 */
    uint64_t field_0x90; /* 0x90 */
    uint64_t field_0x98; /* 0x98 */
    uint64_t field_0xA0; /* 0xA0 */
    uint64_t field_0xA8; /* 0xA8 */
};
static_assert(offsetof(struct ccEventSoftFocusState, vtable_or_base_0x54) == 0x54, "ccEventSoftFocusState.vtable_or_base_0x54 offset");
static_assert(offsetof(struct ccEventSoftFocusState, flags_0x5C) == 0x5C, "ccEventSoftFocusState.flags_0x5C offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x60) == 0x60, "ccEventSoftFocusState.field_0x60 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x68) == 0x68, "ccEventSoftFocusState.field_0x68 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x70) == 0x70, "ccEventSoftFocusState.field_0x70 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x78) == 0x78, "ccEventSoftFocusState.field_0x78 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x80) == 0x80, "ccEventSoftFocusState.field_0x80 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x88) == 0x88, "ccEventSoftFocusState.field_0x88 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x90) == 0x90, "ccEventSoftFocusState.field_0x90 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0x98) == 0x98, "ccEventSoftFocusState.field_0x98 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0xA0) == 0xA0, "ccEventSoftFocusState.field_0xA0 offset");
static_assert(offsetof(struct ccEventSoftFocusState, field_0xA8) == 0xA8, "ccEventSoftFocusState.field_0xA8 offset");

/* ccEventSoundState: no instance state fields found by state_surface
 * Evidence: 1 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventSoundState {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventSpriteKeepParam::ccSpriteParam: no instance state fields found by state_surface
 * Evidence: 1 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventSpriteKeepParam_ccSpriteParam {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventSpritePosCtrl: no instance state fields found by state_surface
 * Evidence: 2 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventSpritePosCtrl {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventSpriteRotCtrl: no instance state fields found by state_surface
 * Evidence: 2 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventSpriteRotCtrl {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventSpriteScaleCtrl: no instance state fields found by state_surface
 * Evidence: 1 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventSpriteScaleCtrl {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventSpriteState
 * Seeds analyzed: 17
 * Fields found: 18 (12 with known size)
 * Size: unknown, >= 0x2C0 (last field at 0x2B8, size 8)
 * Vtable: see constructor/destructor decompilations
 */
struct __attribute__((packed)) ccEventSpriteState {
    uint8_t _pad_0x0[0x54];
    uint64_t vtable_or_base_0x54; /* 0x54 */
    uint32_t flags_0x5C; /* 0x5C */
    uint32_t field_0x60; /* 0x60 */
    uint8_t _pad_0x64[0x4];
    uint64_t field_0x68; /* 0x68 */
    uint8_t _pad_0x70[0x38];
    uint32_t field_0xA8; /* 0xA8 */
    uint8_t _pad_0xAC[0x4];
    uint64_t field_0xB0; /* 0xB0 */
    uint8_t _pad_0xB8[0xC8];
    uint64_t field_0x180; /* 0x180 */
    uint8_t _pad_0x188[0x8];
    uint64_t field_0x190; /* 0x190 */
    uint8_t _pad_0x198[0x108];
    uint64_t field_0x2A0; /* 0x2A0 */
    uint64_t field_0x2A8; /* 0x2A8 */
    uint64_t field_0x2B0; /* 0x2B0 */
    uint64_t field_0x2B8; /* 0x2B8 */
};
static_assert(offsetof(struct ccEventSpriteState, vtable_or_base_0x54) == 0x54, "ccEventSpriteState.vtable_or_base_0x54 offset");
static_assert(offsetof(struct ccEventSpriteState, flags_0x5C) == 0x5C, "ccEventSpriteState.flags_0x5C offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x60) == 0x60, "ccEventSpriteState.field_0x60 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x68) == 0x68, "ccEventSpriteState.field_0x68 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0xA8) == 0xA8, "ccEventSpriteState.field_0xA8 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0xB0) == 0xB0, "ccEventSpriteState.field_0xB0 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x180) == 0x180, "ccEventSpriteState.field_0x180 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x190) == 0x190, "ccEventSpriteState.field_0x190 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x2A0) == 0x2A0, "ccEventSpriteState.field_0x2A0 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x2A8) == 0x2A8, "ccEventSpriteState.field_0x2A8 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x2B0) == 0x2B0, "ccEventSpriteState.field_0x2B0 offset");
static_assert(offsetof(struct ccEventSpriteState, field_0x2B8) == 0x2B8, "ccEventSpriteState.field_0x2B8 offset");

/* ccEventStageState
 * Seeds analyzed: 16
 * Fields found: 13 (11 with known size)
 * Size: unknown, >= 0x1B0 (last field at 0x1A8, size 8)
 * Vtable: see constructor/destructor decompilations
 */
struct __attribute__((packed)) ccEventStageState {
    uint8_t _pad_0x0[0xD8];
    uint8_t field_0xD8; /* 0xD8 */
    uint8_t _pad_0xD9[0xF];
    uint64_t field_0xE8; /* 0xE8 */
    uint64_t field_0xF0; /* 0xF0 */
    uint64_t field_0xF8; /* 0xF8 */
    uint8_t _pad_0x100[0x30];
    uint8_t field_0x130; /* 0x130 */
    uint8_t _pad_0x131[0xF];
    uint64_t field_0x140; /* 0x140 */
    uint64_t field_0x148; /* 0x148 */
    uint64_t field_0x150; /* 0x150 */
    uint8_t _pad_0x158[0x2C];
    uint32_t field_0x184; /* 0x184 */
    uint32_t field_0x188; /* 0x188 */
    uint8_t _pad_0x18C[0x1C];
    uint64_t field_0x1A8; /* 0x1A8 */
};
static_assert(offsetof(struct ccEventStageState, field_0xD8) == 0xD8, "ccEventStageState.field_0xD8 offset");
static_assert(offsetof(struct ccEventStageState, field_0xE8) == 0xE8, "ccEventStageState.field_0xE8 offset");
static_assert(offsetof(struct ccEventStageState, field_0xF0) == 0xF0, "ccEventStageState.field_0xF0 offset");
static_assert(offsetof(struct ccEventStageState, field_0xF8) == 0xF8, "ccEventStageState.field_0xF8 offset");
static_assert(offsetof(struct ccEventStageState, field_0x130) == 0x130, "ccEventStageState.field_0x130 offset");
static_assert(offsetof(struct ccEventStageState, field_0x140) == 0x140, "ccEventStageState.field_0x140 offset");
static_assert(offsetof(struct ccEventStageState, field_0x148) == 0x148, "ccEventStageState.field_0x148 offset");
static_assert(offsetof(struct ccEventStageState, field_0x150) == 0x150, "ccEventStageState.field_0x150 offset");
static_assert(offsetof(struct ccEventStageState, field_0x184) == 0x184, "ccEventStageState.field_0x184 offset");
static_assert(offsetof(struct ccEventStageState, field_0x188) == 0x188, "ccEventStageState.field_0x188 offset");
static_assert(offsetof(struct ccEventStageState, field_0x1A8) == 0x1A8, "ccEventStageState.field_0x1A8 offset");

/* ccEventStringColorCtrl: no instance state fields found by state_surface
 * Evidence: 1 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventStringColorCtrl {
    uint8_t _placeholder; /* no instance state */
};

/* ccEventStringPosCtrl: no instance state fields found by state_surface
 * Evidence: 2 methods analyzed, 0 field accesses detected.
 * This class may be pure-virtual or stateless in this build.
 */
struct ccEventStringPosCtrl {
    uint8_t _placeholder; /* no instance state */
};

#endif /* ST3C04_H */
