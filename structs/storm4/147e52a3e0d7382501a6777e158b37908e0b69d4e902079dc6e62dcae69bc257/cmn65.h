/* cmn65.h -- NARUTO STORM 4 PC (s4, NSUNS4_release.exe 1.09)
 * Struct group: nuccPostEffectCompositeMotionBlur, nuccPostEffectCompositeReduction,
 *               nuccPostEffectDecal, nuccPostEffectDOF, nuccPostEffectGlare
 *
 * Generated from the decompiler cache state_surface + manual decompile inspection.
 * All layouts are INFERRED (static analysis only), not CONFIRMED at runtime.
 * Field names are placeholder (field_0xNN); rename with evidence.
 * Rollback tags: PRES = presentation-only, SIM = simulation state.
 */
#ifndef CMN65_H
#define CMN65_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nuccPostEffectCompositeMotionBlur */
/* Size: 0x350 (848) -- operator_new(0x350) in factory RVA 0xA10160 */
struct nuccPostEffectCompositeMotionBlur {
    void *vtable; /* 0x0 */
    uint8_t _pad_0x8[224]; /* 0x8..0xE7 */
    uint32_t field_0xE8; /* 0xE8 [PRES] */
    uint8_t _pad_0xEC[4]; /* 0xEC..0xEF */
    uint64_t field_0xF0; /* 0xF0 [PRES] */
    uint64_t field_0xF8; /* 0xF8 [PRES] */
    uint32_t field_0x100; /* 0x100 [PRES] */
    uint32_t field_0x104; /* 0x104 [PRES] */
    uint32_t field_0x108; /* 0x108 [PRES] */
    uint32_t field_0x10C; /* 0x10C [PRES] */
    uint64_t field_0x110; /* 0x110 [PRES] */
    uint32_t field_0x118; /* 0x118 [PRES] */
    uint32_t field_0x11C; /* 0x11C [PRES] */
    uint32_t field_0x120; /* 0x120 [PRES] */
    uint32_t field_0x124; /* 0x124 [PRES] */
    uint32_t field_0x128; /* 0x128 [PRES] */
    uint8_t _pad_0x12C[4]; /* 0x12C..0x12F */
    uint64_t field_0x130; /* 0x130 [PRES] */
    uint32_t field_0x138; /* 0x138 [PRES] */
    uint8_t _pad_0x13C[4]; /* 0x13C..0x13F */
    uint64_t field_0x140; /* 0x140 [PRES] */
    uint64_t field_0x148; /* 0x148 [PRES] */
    uint32_t field_0x150; /* 0x150 [PRES] */
    uint32_t field_0x154; /* 0x154 [PRES] */
    uint32_t field_0x158; /* 0x158 [PRES] */
    uint32_t field_0x15C; /* 0x15C [PRES] */
    uint64_t field_0x160; /* 0x160 [PRES] */
    uint64_t field_0x168; /* 0x168 [PRES] */
    uint32_t field_0x170; /* 0x170 [PRES] */
    uint8_t _pad_0x174[12]; /* 0x174..0x17F */
    uint64_t field_0x180; /* 0x180 [PRES] */
    uint64_t field_0x188; /* 0x188 [PRES] */
    uint32_t field_0x190; /* 0x190 [PRES] */
    uint32_t field_0x194; /* 0x194 [PRES] */
    uint32_t field_0x198; /* 0x198 [PRES] */
    uint32_t field_0x19C; /* 0x19C [PRES] */
    uint64_t field_0x1A0; /* 0x1A0 [PRES] */
    uint32_t field_0x1A8; /* 0x1A8 [PRES] */
    uint64_t field_0x1AC; /* 0x1AC [PRES] */
    uint64_t field_0x1B4; /* 0x1B4 [PRES] */
    uint8_t _pad_0x1BC[4]; /* 0x1BC..0x1BF */
    uint64_t field_0x1C0; /* 0x1C0 [PRES] */
    uint64_t field_0x1C8; /* 0x1C8 [PRES] */
    uint32_t field_0x1D0; /* 0x1D0 [PRES] */
    uint64_t field_0x1D4; /* 0x1D4 [PRES] */
    uint8_t _pad_0x1DC[4]; /* 0x1DC..0x1DF */
    uint64_t field_0x1E0; /* 0x1E0 [PRES] */
    uint64_t field_0x1E8; /* 0x1E8 [PRES] */
    uint64_t field_0x1F0; /* 0x1F0 [PRES] */
    uint64_t field_0x1F8; /* 0x1F8 [PRES] */
    uint32_t field_0x200; /* 0x200 [PRES] */
    uint64_t field_0x204; /* 0x204 [PRES] */
    uint64_t field_0x20C; /* 0x20C [PRES] */
    uint64_t field_0x214; /* 0x214 [PRES] */
    uint64_t field_0x21C; /* 0x21C [PRES] */
    uint32_t field_0x224; /* 0x224 [PRES] */
    uint32_t field_0x228; /* 0x228 [PRES] */
    uint32_t field_0x22C; /* 0x22C [PRES] */
    uint32_t field_0x230; /* 0x230 [PRES] */
    uint32_t field_0x234; /* 0x234 [PRES] */
    uint64_t field_0x238; /* 0x238 [PRES] */
    uint32_t field_0x240; /* 0x240 [PRES] */
    uint32_t field_0x244; /* 0x244 [PRES] */
    uint32_t field_0x248; /* 0x248 [PRES] */
    uint32_t field_0x24C; /* 0x24C [PRES] */
    uint32_t field_0x250; /* 0x250 [PRES] */
    uint32_t field_0x254; /* 0x254 [PRES] */
    uint64_t field_0x258; /* 0x258 [PRES] */
    uint64_t field_0x260; /* 0x260 [PRES] */
    uint64_t field_0x268; /* 0x268 [PRES] */
    uint32_t field_0x270; /* 0x270 [PRES] */
    uint64_t field_0x274; /* 0x274 [PRES] */
    uint64_t field_0x27C; /* 0x27C [PRES] */
    uint32_t field_0x284; /* 0x284 [PRES] */
    uint32_t field_0x288; /* 0x288 [PRES] */
    uint32_t field_0x28C; /* 0x28C [PRES] */
    uint32_t field_0x290; /* 0x290 [PRES] */
    uint32_t field_0x294; /* 0x294 [PRES] */
    uint32_t field_0x298; /* 0x298 [PRES] */
    uint32_t field_0x29C; /* 0x29C [PRES] */
    uint32_t field_0x2A0; /* 0x2A0 [PRES] */
    uint32_t field_0x2A4; /* 0x2A4 [PRES] */
    uint64_t field_0x2A8; /* 0x2A8 [PRES] */
    uint64_t field_0x2B0; /* 0x2B0 [PRES] */
    uint32_t field_0x2B8; /* 0x2B8 [PRES] */
    uint8_t _pad_0x2BC[4]; /* 0x2BC..0x2BF */
    uint32_t field_0x2C0; /* 0x2C0 [PRES] */
    uint32_t field_0x2C4; /* 0x2C4 [PRES] */
    uint32_t field_0x2C8; /* 0x2C8 [PRES] */
    uint32_t field_0x2CC; /* 0x2CC [PRES] */
    uint32_t field_0x2D0; /* 0x2D0 [PRES] */
    uint32_t field_0x2D4; /* 0x2D4 [PRES] */
    uint64_t field_0x2D8; /* 0x2D8 [PRES] */
    uint64_t field_0x2E0; /* 0x2E0 [PRES] */
    uint32_t field_0x2E8; /* 0x2E8 [PRES] */
    uint32_t field_0x2EC; /* 0x2EC [PRES] */
    uint32_t field_0x2F0; /* 0x2F0 [PRES] */
    uint32_t field_0x2F4; /* 0x2F4 [PRES] */
    uint32_t field_0x2F8; /* 0x2F8 [PRES] */
    uint32_t field_0x2FC; /* 0x2FC [PRES] */
    uint32_t field_0x300; /* 0x300 [PRES] */
    uint32_t field_0x304; /* 0x304 [PRES] */
    uint32_t field_0x308; /* 0x308 [PRES] */
    uint64_t field_0x30C; /* 0x30C [PRES] */
    uint64_t field_0x314; /* 0x314 [PRES] */
    uint32_t field_0x31C; /* 0x31C [PRES] */
    uint8_t _pad_trail_0x320[48]; /* 0x320..0x34F */
} __attribute__((packed));

static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0xE8) == 0xE8, "nuccPostEffectCompositeMotionBlur.field_0xE8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0xF0) == 0xF0, "nuccPostEffectCompositeMotionBlur.field_0xF0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0xF8) == 0xF8, "nuccPostEffectCompositeMotionBlur.field_0xF8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x100) == 0x100, "nuccPostEffectCompositeMotionBlur.field_0x100 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x104) == 0x104, "nuccPostEffectCompositeMotionBlur.field_0x104 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x108) == 0x108, "nuccPostEffectCompositeMotionBlur.field_0x108 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x10C) == 0x10C, "nuccPostEffectCompositeMotionBlur.field_0x10C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x110) == 0x110, "nuccPostEffectCompositeMotionBlur.field_0x110 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x118) == 0x118, "nuccPostEffectCompositeMotionBlur.field_0x118 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x11C) == 0x11C, "nuccPostEffectCompositeMotionBlur.field_0x11C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x120) == 0x120, "nuccPostEffectCompositeMotionBlur.field_0x120 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x124) == 0x124, "nuccPostEffectCompositeMotionBlur.field_0x124 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x128) == 0x128, "nuccPostEffectCompositeMotionBlur.field_0x128 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x130) == 0x130, "nuccPostEffectCompositeMotionBlur.field_0x130 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x138) == 0x138, "nuccPostEffectCompositeMotionBlur.field_0x138 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x140) == 0x140, "nuccPostEffectCompositeMotionBlur.field_0x140 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x148) == 0x148, "nuccPostEffectCompositeMotionBlur.field_0x148 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x150) == 0x150, "nuccPostEffectCompositeMotionBlur.field_0x150 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x154) == 0x154, "nuccPostEffectCompositeMotionBlur.field_0x154 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x158) == 0x158, "nuccPostEffectCompositeMotionBlur.field_0x158 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x15C) == 0x15C, "nuccPostEffectCompositeMotionBlur.field_0x15C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x160) == 0x160, "nuccPostEffectCompositeMotionBlur.field_0x160 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x168) == 0x168, "nuccPostEffectCompositeMotionBlur.field_0x168 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x170) == 0x170, "nuccPostEffectCompositeMotionBlur.field_0x170 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x180) == 0x180, "nuccPostEffectCompositeMotionBlur.field_0x180 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x188) == 0x188, "nuccPostEffectCompositeMotionBlur.field_0x188 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x190) == 0x190, "nuccPostEffectCompositeMotionBlur.field_0x190 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x194) == 0x194, "nuccPostEffectCompositeMotionBlur.field_0x194 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x198) == 0x198, "nuccPostEffectCompositeMotionBlur.field_0x198 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x19C) == 0x19C, "nuccPostEffectCompositeMotionBlur.field_0x19C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1A0) == 0x1A0, "nuccPostEffectCompositeMotionBlur.field_0x1A0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1A8) == 0x1A8, "nuccPostEffectCompositeMotionBlur.field_0x1A8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1AC) == 0x1AC, "nuccPostEffectCompositeMotionBlur.field_0x1AC offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1B4) == 0x1B4, "nuccPostEffectCompositeMotionBlur.field_0x1B4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1C0) == 0x1C0, "nuccPostEffectCompositeMotionBlur.field_0x1C0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1C8) == 0x1C8, "nuccPostEffectCompositeMotionBlur.field_0x1C8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1D0) == 0x1D0, "nuccPostEffectCompositeMotionBlur.field_0x1D0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1D4) == 0x1D4, "nuccPostEffectCompositeMotionBlur.field_0x1D4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1E0) == 0x1E0, "nuccPostEffectCompositeMotionBlur.field_0x1E0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1E8) == 0x1E8, "nuccPostEffectCompositeMotionBlur.field_0x1E8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1F0) == 0x1F0, "nuccPostEffectCompositeMotionBlur.field_0x1F0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x1F8) == 0x1F8, "nuccPostEffectCompositeMotionBlur.field_0x1F8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x200) == 0x200, "nuccPostEffectCompositeMotionBlur.field_0x200 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x204) == 0x204, "nuccPostEffectCompositeMotionBlur.field_0x204 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x20C) == 0x20C, "nuccPostEffectCompositeMotionBlur.field_0x20C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x214) == 0x214, "nuccPostEffectCompositeMotionBlur.field_0x214 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x21C) == 0x21C, "nuccPostEffectCompositeMotionBlur.field_0x21C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x224) == 0x224, "nuccPostEffectCompositeMotionBlur.field_0x224 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x228) == 0x228, "nuccPostEffectCompositeMotionBlur.field_0x228 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x22C) == 0x22C, "nuccPostEffectCompositeMotionBlur.field_0x22C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x230) == 0x230, "nuccPostEffectCompositeMotionBlur.field_0x230 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x234) == 0x234, "nuccPostEffectCompositeMotionBlur.field_0x234 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x238) == 0x238, "nuccPostEffectCompositeMotionBlur.field_0x238 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x240) == 0x240, "nuccPostEffectCompositeMotionBlur.field_0x240 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x244) == 0x244, "nuccPostEffectCompositeMotionBlur.field_0x244 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x248) == 0x248, "nuccPostEffectCompositeMotionBlur.field_0x248 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x24C) == 0x24C, "nuccPostEffectCompositeMotionBlur.field_0x24C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x250) == 0x250, "nuccPostEffectCompositeMotionBlur.field_0x250 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x254) == 0x254, "nuccPostEffectCompositeMotionBlur.field_0x254 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x258) == 0x258, "nuccPostEffectCompositeMotionBlur.field_0x258 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x260) == 0x260, "nuccPostEffectCompositeMotionBlur.field_0x260 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x268) == 0x268, "nuccPostEffectCompositeMotionBlur.field_0x268 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x270) == 0x270, "nuccPostEffectCompositeMotionBlur.field_0x270 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x274) == 0x274, "nuccPostEffectCompositeMotionBlur.field_0x274 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x27C) == 0x27C, "nuccPostEffectCompositeMotionBlur.field_0x27C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x284) == 0x284, "nuccPostEffectCompositeMotionBlur.field_0x284 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x288) == 0x288, "nuccPostEffectCompositeMotionBlur.field_0x288 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x28C) == 0x28C, "nuccPostEffectCompositeMotionBlur.field_0x28C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x290) == 0x290, "nuccPostEffectCompositeMotionBlur.field_0x290 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x294) == 0x294, "nuccPostEffectCompositeMotionBlur.field_0x294 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x298) == 0x298, "nuccPostEffectCompositeMotionBlur.field_0x298 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x29C) == 0x29C, "nuccPostEffectCompositeMotionBlur.field_0x29C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2A0) == 0x2A0, "nuccPostEffectCompositeMotionBlur.field_0x2A0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2A4) == 0x2A4, "nuccPostEffectCompositeMotionBlur.field_0x2A4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2A8) == 0x2A8, "nuccPostEffectCompositeMotionBlur.field_0x2A8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2B0) == 0x2B0, "nuccPostEffectCompositeMotionBlur.field_0x2B0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2B8) == 0x2B8, "nuccPostEffectCompositeMotionBlur.field_0x2B8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2C0) == 0x2C0, "nuccPostEffectCompositeMotionBlur.field_0x2C0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2C4) == 0x2C4, "nuccPostEffectCompositeMotionBlur.field_0x2C4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2C8) == 0x2C8, "nuccPostEffectCompositeMotionBlur.field_0x2C8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2CC) == 0x2CC, "nuccPostEffectCompositeMotionBlur.field_0x2CC offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2D0) == 0x2D0, "nuccPostEffectCompositeMotionBlur.field_0x2D0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2D4) == 0x2D4, "nuccPostEffectCompositeMotionBlur.field_0x2D4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2D8) == 0x2D8, "nuccPostEffectCompositeMotionBlur.field_0x2D8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2E0) == 0x2E0, "nuccPostEffectCompositeMotionBlur.field_0x2E0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2E8) == 0x2E8, "nuccPostEffectCompositeMotionBlur.field_0x2E8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2EC) == 0x2EC, "nuccPostEffectCompositeMotionBlur.field_0x2EC offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2F0) == 0x2F0, "nuccPostEffectCompositeMotionBlur.field_0x2F0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2F4) == 0x2F4, "nuccPostEffectCompositeMotionBlur.field_0x2F4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2F8) == 0x2F8, "nuccPostEffectCompositeMotionBlur.field_0x2F8 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x2FC) == 0x2FC, "nuccPostEffectCompositeMotionBlur.field_0x2FC offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x300) == 0x300, "nuccPostEffectCompositeMotionBlur.field_0x300 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x304) == 0x304, "nuccPostEffectCompositeMotionBlur.field_0x304 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x308) == 0x308, "nuccPostEffectCompositeMotionBlur.field_0x308 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x30C) == 0x30C, "nuccPostEffectCompositeMotionBlur.field_0x30C offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x314) == 0x314, "nuccPostEffectCompositeMotionBlur.field_0x314 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeMotionBlur, field_0x31C) == 0x31C, "nuccPostEffectCompositeMotionBlur.field_0x31C offset mismatch");
static_assert(sizeof(struct nuccPostEffectCompositeMotionBlur) == 0x350, "nuccPostEffectCompositeMotionBlur size mismatch (expected 0x350)");

/* nuccPostEffectCompositeReduction */
/* Size: unknown, >= 0x84 (132) -- embedded at offset 0x48 in criAtomStdStreamer(0x240); no independent alloc */
struct nuccPostEffectCompositeReduction {
    void *vtable; /* 0x0 */
    uint8_t _pad_0x8[80]; /* 0x8..0x57 */
    uint32_t field_0x58; /* 0x58 [PRES] */
    uint8_t _pad_0x5C[4]; /* 0x5C..0x5F */
    uint64_t field_0x60; /* 0x60 [PRES] */
    uint64_t field_0x68; /* 0x68 [PRES] */
    uint32_t field_0x70; /* 0x70 [PRES] */
    uint8_t _pad_0x74[4]; /* 0x74..0x77 */
    uint64_t field_0x78; /* 0x78 [PRES] */
    uint32_t field_0x80; /* 0x80 [PRES] */
} __attribute__((packed));

static_assert(offsetof(struct nuccPostEffectCompositeReduction, field_0x58) == 0x58, "nuccPostEffectCompositeReduction.field_0x58 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeReduction, field_0x60) == 0x60, "nuccPostEffectCompositeReduction.field_0x60 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeReduction, field_0x68) == 0x68, "nuccPostEffectCompositeReduction.field_0x68 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeReduction, field_0x70) == 0x70, "nuccPostEffectCompositeReduction.field_0x70 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeReduction, field_0x78) == 0x78, "nuccPostEffectCompositeReduction.field_0x78 offset mismatch");
static_assert(offsetof(struct nuccPostEffectCompositeReduction, field_0x80) == 0x80, "nuccPostEffectCompositeReduction.field_0x80 offset mismatch");

/* nuccPostEffectDecal */
/* Size: unknown, >= 0x120 (288) -- no ctor or allocation site found; last field at 0x11C */
struct nuccPostEffectDecal {
    void *vtable; /* 0x0 */
    uint8_t _pad_0x8[8]; /* 0x8..0xF */
    int32_t field_0x10; /* 0x10 [PRES] */
    uint8_t _pad_0x14[4]; /* 0x14..0x17 */
    uint32_t field_0x18; /* 0x18 [PRES] */
    uint32_t field_0x1C; /* 0x1C [PRES] */
    uint32_t field_0x20; /* 0x20 [PRES] */
    uint8_t _pad_0x24[4]; /* 0x24..0x27 */
    void *field_0x28; /* 0x28 [PRES] */
    void *field_0x30; /* 0x30 [PRES] */
    uint8_t _pad_0x38[8]; /* 0x38..0x3F */
    uint32_t field_0x40; /* 0x40 [PRES] */
    void *field_0x44; /* 0x44 [PRES] */
    uint32_t field_0x4C; /* 0x4C [PRES] */
    float field_0x50; /* 0x50 [PRES] */
    float field_0x54; /* 0x54 [PRES] */
    void *field_0x58; /* 0x58 [PRES] */
    uint8_t _pad_0x60[16]; /* 0x60..0x6F */
    float field_0x70; /* 0x70 [PRES] */
    float field_0x74; /* 0x74 [PRES] */
    uint8_t _pad_0x78[4]; /* 0x78..0x7B */
    void *field_0x7C; /* 0x7C [PRES] */
    uint32_t field_0x84; /* 0x84 [PRES] */
    void *field_0x88; /* 0x88 [PRES] */
    uint32_t field_0x90; /* 0x90 [PRES] */
    float field_0x94; /* 0x94 [PRES] */
    float field_0x98; /* 0x98 [PRES] */
    float field_0x9C; /* 0x9C [PRES] */
    float field_0xA0; /* 0xA0 [PRES] */
    float field_0xA4; /* 0xA4 [PRES] */
    uint8_t _pad_0xA8[8]; /* 0xA8..0xAF */
    void *field_0xB0; /* 0xB0 [PRES] */
    uint8_t _pad_0xB8[72]; /* 0xB8..0xFF */
    void *field_0x100; /* 0x100 [PRES] */
    uint32_t field_0x108; /* 0x108 [PRES] */
    float field_0x10C; /* 0x10C [PRES] */
    float field_0x110; /* 0x110 [PRES] */
    float field_0x114; /* 0x114 [PRES] */
    float field_0x118; /* 0x118 [PRES] */
    int32_t field_0x11C; /* 0x11C [PRES] */
} __attribute__((packed));

static_assert(offsetof(struct nuccPostEffectDecal, field_0x10) == 0x10, "nuccPostEffectDecal.field_0x10 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x18) == 0x18, "nuccPostEffectDecal.field_0x18 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x1C) == 0x1C, "nuccPostEffectDecal.field_0x1C offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x20) == 0x20, "nuccPostEffectDecal.field_0x20 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x28) == 0x28, "nuccPostEffectDecal.field_0x28 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x30) == 0x30, "nuccPostEffectDecal.field_0x30 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x40) == 0x40, "nuccPostEffectDecal.field_0x40 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x44) == 0x44, "nuccPostEffectDecal.field_0x44 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x4C) == 0x4C, "nuccPostEffectDecal.field_0x4C offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x50) == 0x50, "nuccPostEffectDecal.field_0x50 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x54) == 0x54, "nuccPostEffectDecal.field_0x54 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x58) == 0x58, "nuccPostEffectDecal.field_0x58 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x70) == 0x70, "nuccPostEffectDecal.field_0x70 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x74) == 0x74, "nuccPostEffectDecal.field_0x74 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x7C) == 0x7C, "nuccPostEffectDecal.field_0x7C offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x84) == 0x84, "nuccPostEffectDecal.field_0x84 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x88) == 0x88, "nuccPostEffectDecal.field_0x88 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x90) == 0x90, "nuccPostEffectDecal.field_0x90 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x94) == 0x94, "nuccPostEffectDecal.field_0x94 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x98) == 0x98, "nuccPostEffectDecal.field_0x98 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x9C) == 0x9C, "nuccPostEffectDecal.field_0x9C offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0xA0) == 0xA0, "nuccPostEffectDecal.field_0xA0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0xA4) == 0xA4, "nuccPostEffectDecal.field_0xA4 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0xB0) == 0xB0, "nuccPostEffectDecal.field_0xB0 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x100) == 0x100, "nuccPostEffectDecal.field_0x100 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x108) == 0x108, "nuccPostEffectDecal.field_0x108 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x10C) == 0x10C, "nuccPostEffectDecal.field_0x10C offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x110) == 0x110, "nuccPostEffectDecal.field_0x110 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x114) == 0x114, "nuccPostEffectDecal.field_0x114 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x118) == 0x118, "nuccPostEffectDecal.field_0x118 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDecal, field_0x11C) == 0x11C, "nuccPostEffectDecal.field_0x11C offset mismatch");

/* nuccPostEffectDOF */
/* Size: unknown, >= 0x60 (96) -- embedded at offset 0x88 in nuccPostEffectComposite; no independent alloc */
struct nuccPostEffectDOF {
    void *vtable; /* 0x0 */
    uint8_t _pad_0x8[52]; /* 0x8..0x3B */
    uint32_t field_0x3C; /* 0x3C [PRES] */
    uint8_t _pad_0x40[4]; /* 0x40..0x43 */
    uint32_t field_0x44; /* 0x44 [PRES] */
    uint8_t _pad_0x48[12]; /* 0x48..0x53 */
    uint32_t field_0x54; /* 0x54 [PRES] */
    uint32_t field_0x58; /* 0x58 [PRES] */
    uint32_t field_0x5C; /* 0x5C [PRES] */
} __attribute__((packed));

static_assert(offsetof(struct nuccPostEffectDOF, field_0x3C) == 0x3C, "nuccPostEffectDOF.field_0x3C offset mismatch");
static_assert(offsetof(struct nuccPostEffectDOF, field_0x44) == 0x44, "nuccPostEffectDOF.field_0x44 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDOF, field_0x54) == 0x54, "nuccPostEffectDOF.field_0x54 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDOF, field_0x58) == 0x58, "nuccPostEffectDOF.field_0x58 offset mismatch");
static_assert(offsetof(struct nuccPostEffectDOF, field_0x5C) == 0x5C, "nuccPostEffectDOF.field_0x5C offset mismatch");

/* nuccPostEffectGlare */
/* Size: unknown, >= 0x40 (64) -- embedded at offset 0x00 in nuccPostEffectComposite; no independent alloc */
struct nuccPostEffectGlare {
    void *vtable; /* 0x0 */
    uint8_t _pad_0x8[28]; /* 0x8..0x23 */
    uint32_t field_0x24; /* 0x24 [PRES] */
    uint8_t _pad_0x28[4]; /* 0x28..0x2B */
    uint32_t field_0x2C; /* 0x2C [PRES] */
    uint8_t _pad_0x30[4]; /* 0x30..0x33 */
    uint32_t field_0x34; /* 0x34 [PRES] */
    uint8_t _pad_0x38[4]; /* 0x38..0x3B */
    uint32_t field_0x3C; /* 0x3C [PRES] */
} __attribute__((packed));

static_assert(offsetof(struct nuccPostEffectGlare, field_0x24) == 0x24, "nuccPostEffectGlare.field_0x24 offset mismatch");
static_assert(offsetof(struct nuccPostEffectGlare, field_0x2C) == 0x2C, "nuccPostEffectGlare.field_0x2C offset mismatch");
static_assert(offsetof(struct nuccPostEffectGlare, field_0x34) == 0x34, "nuccPostEffectGlare.field_0x34 offset mismatch");
static_assert(offsetof(struct nuccPostEffectGlare, field_0x3C) == 0x3C, "nuccPostEffectGlare.field_0x3C offset mismatch");

#endif /* CMN65_H */
