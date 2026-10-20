/* cmn52 s1: struct group for NARUTO STORM 1 PC (NSUNS1.exe)
 * All layouts INFERRED from static analysis of build s1 (sha 10231093af9c).
 * Sizes proven from game code where noted; otherwise marked unknown.
 * Generated 2026-10-19.
 */
#ifndef CMN52_S1_H
#define CMN52_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccDrawEnv
 * Size: 0x289 (proven: stack alloc local_2b8[648] in nuccParticleRenderThread::Exec @ 0x4DE230)
 * Vtable: PTR_FUN_140737378 (set in ctor @ 0x48A840)
 * Methods: 29
 * Fields: 43
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccDrawEnv {
    /* 0x00 */ void *vtable;                          /* PRES: PTR_FUN_140737378 */
    /* 0x08 */ uint16_t field_0x08;                   /* UNKNOWN: ctor writes 0 */
    /* 0x0A */ uint8_t _pad_0x0A[6];                  /* padding to 0x10 */
    /* 0x10 */ void *field_0x10;                      /* UNKNOWN: &DAT_140737210 */
    /* 0x18 */ int32_t field_0x18;                    /* UNKNOWN: set to 1 */
    /* 0x1C */ uint8_t _pad_0x1C[4];                  /* padding */
    /* 0x20 */ uint8_t embedded_0x20[0x38];           /* UNKNOWN: FUN_14048a410 sub-obj */
    /* 0x58 */ uint64_t field_0x58;                   /* UNKNOWN */
    /* 0x60 */ uint64_t field_0x60;                   /* UNKNOWN: DAT_140884af8+0x2b8 */
    /* 0x68 */ uint64_t field_0x68;                   /* UNKNOWN: DAT_140884af8+0x3f0 */
    /* 0x70 */ uint64_t field_0x70;                   /* UNKNOWN */
    /* 0x78 */ float field_0x78;                      /* PRES: 1.0f */
    /* 0x7C */ uint8_t _pad_0x7C[4];                  /* padding */
    /* 0x80 */ uint64_t field_0x80;                   /* UNKNOWN: vtable-like dispatch */
    /* 0x88 */ uint32_t field_0x88;                   /* UNKNOWN */
    /* 0x8C */ uint64_t field_0x8C;                   /* PRES: init 1 */
    /* 0x94 */ uint64_t field_0x94;                   /* PRES: init -1 */
    /* 0x9C */ uint64_t field_0x9C;                   /* PRES: init -1 */
    /* 0xA4 */ uint64_t field_0xA4;                   /* PRES: init 0 */
    /* 0xAC */ uint64_t field_0xAC;                   /* PRES: init 0 */
    /* 0xB4 */ uint32_t field_0xB4;                   /* UNKNOWN */
    /* 0xB8 */ uint8_t _gap_0xB8[0x20];               /* UNKNOWN: read-only region 0xB8..0xD7 */
    /* 0xD8 */ uint64_t field_0xD8;                   /* UNKNOWN */
    /* 0xE0 */ uint64_t field_0xE0;                   /* PRES */
    /* 0xE8 */ uint64_t field_0xE8;                   /* PRES */
    /* 0xF0 */ uint8_t field_0xF0;                    /* PRES */
    /* 0xF1 */ uint8_t _pad_0xF1[7];                  /* padding */
    /* 0xF8 */ uint64_t field_0xF8;                   /* UNKNOWN */
    /* 0x100 */ uint64_t field_0x100;                 /* UNKNOWN: read-only */
    /* 0x108 */ uint64_t field_0x108;                 /* PRES */
    /* 0x110 */ uint64_t field_0x110;                 /* UNKNOWN */
    /* 0x118 */ uint8_t _gap_0x118[0x28];             /* UNKNOWN: gap 0x118..0x13F */
    /* 0x140 */ uint64_t field_0x140;                 /* SIM: access table ptr (init self+0x20) */
    /* 0x148 */ uint8_t _gap_0x148[0x30];             /* UNKNOWN: gap 0x148..0x177 */
    /* 0x178 */ uint64_t field_0x178;                 /* UNKNOWN */
    /* 0x180 */ uint8_t _gap_0x180[0x10];             /* UNKNOWN: gap 0x180..0x18F */
    /* 0x190 */ uint32_t field_0x190;                 /* UNKNOWN */
    /* 0x194 */ uint8_t _pad_0x194[4];                /* padding */
    /* 0x198 */ uint64_t field_0x198;                 /* UNKNOWN */
    /* 0x1A0 */ uint64_t field_0x1A0;                 /* UNKNOWN */
    /* 0x1A8 */ uint32_t field_0x1A8;                 /* UNKNOWN: trail param counter */
    /* 0x1AC */ uint8_t _pad_0x1AC[4];                /* padding */
    /* 0x1B0 */ uint64_t field_0x1B0;                 /* PRES */
    /* 0x1B8 */ uint8_t _gap_0x1B8[0x50];             /* UNKNOWN: gap 0x1B8..0x207 */
    /* 0x208 */ uint64_t field_0x208;                 /* SIM: param stack pointer */
    /* 0x210 */ uint8_t _gap_0x210[0x48];             /* UNKNOWN: gap 0x210..0x257 */
    /* 0x258 */ uint32_t field_0x258;                 /* PRES */
    /* 0x25C */ float field_0x25C;                    /* PRES: 1.0f */
    /* 0x260 */ uint64_t field_0x260;                 /* PRES */
    /* 0x268 */ uint32_t field_0x268;                 /* PRES */
    /* 0x26C */ uint8_t _pad_0x26C[4];                /* padding */
    /* 0x270 */ uint64_t field_0x26C;                 /* PRES: init 1 */
    /* 0x278 */ uint64_t field_0x274;                 /* PRES: init 0 */
    /* 0x280 */ uint64_t field_0x27C;                 /* PRES: init 0 */
    /* 0x288 */ uint8_t field_0x288;                  /* PRES */
} nuccDrawEnv;

static_assert(offsetof(nuccDrawEnv, vtable) == 0x00, "nuccDrawEnv.vtable");
static_assert(offsetof(nuccDrawEnv, field_0x08) == 0x08, "nuccDrawEnv.field_0x08");
static_assert(offsetof(nuccDrawEnv, field_0x10) == 0x10, "nuccDrawEnv.field_0x10");
static_assert(offsetof(nuccDrawEnv, field_0x18) == 0x18, "nuccDrawEnv.field_0x18");
static_assert(offsetof(nuccDrawEnv, embedded_0x20) == 0x20, "nuccDrawEnv.embedded_0x20");
static_assert(offsetof(nuccDrawEnv, field_0x58) == 0x58, "nuccDrawEnv.field_0x58");
static_assert(offsetof(nuccDrawEnv, field_0x60) == 0x60, "nuccDrawEnv.field_0x60");
static_assert(offsetof(nuccDrawEnv, field_0x68) == 0x68, "nuccDrawEnv.field_0x68");
static_assert(offsetof(nuccDrawEnv, field_0x70) == 0x70, "nuccDrawEnv.field_0x70");
static_assert(offsetof(nuccDrawEnv, field_0x78) == 0x78, "nuccDrawEnv.field_0x78");
static_assert(offsetof(nuccDrawEnv, field_0x80) == 0x80, "nuccDrawEnv.field_0x80");
static_assert(offsetof(nuccDrawEnv, field_0x88) == 0x88, "nuccDrawEnv.field_0x88");
static_assert(offsetof(nuccDrawEnv, field_0x8C) == 0x8C, "nuccDrawEnv.field_0x8C");
static_assert(offsetof(nuccDrawEnv, field_0x94) == 0x94, "nuccDrawEnv.field_0x94");
static_assert(offsetof(nuccDrawEnv, field_0x9C) == 0x9C, "nuccDrawEnv.field_0x9C");
static_assert(offsetof(nuccDrawEnv, field_0xA4) == 0xA4, "nuccDrawEnv.field_0xA4");
static_assert(offsetof(nuccDrawEnv, field_0xAC) == 0xAC, "nuccDrawEnv.field_0xAC");
static_assert(offsetof(nuccDrawEnv, field_0xB4) == 0xB4, "nuccDrawEnv.field_0xB4");
static_assert(offsetof(nuccDrawEnv, _gap_0xB8) == 0xB8, "nuccDrawEnv._gap_0xB8");
static_assert(offsetof(nuccDrawEnv, field_0xD8) == 0xD8, "nuccDrawEnv.field_0xD8");
static_assert(offsetof(nuccDrawEnv, field_0xE0) == 0xE0, "nuccDrawEnv.field_0xE0");
static_assert(offsetof(nuccDrawEnv, field_0xE8) == 0xE8, "nuccDrawEnv.field_0xE8");
static_assert(offsetof(nuccDrawEnv, field_0xF0) == 0xF0, "nuccDrawEnv.field_0xF0");
static_assert(offsetof(nuccDrawEnv, field_0xF8) == 0xF8, "nuccDrawEnv.field_0xF8");
static_assert(offsetof(nuccDrawEnv, field_0x100) == 0x100, "nuccDrawEnv.field_0x100");
static_assert(offsetof(nuccDrawEnv, field_0x108) == 0x108, "nuccDrawEnv.field_0x108");
static_assert(offsetof(nuccDrawEnv, field_0x110) == 0x110, "nuccDrawEnv.field_0x110");
static_assert(offsetof(nuccDrawEnv, _gap_0x118) == 0x118, "nuccDrawEnv._gap_0x118");
static_assert(offsetof(nuccDrawEnv, field_0x140) == 0x140, "nuccDrawEnv.field_0x140");
static_assert(offsetof(nuccDrawEnv, _gap_0x148) == 0x148, "nuccDrawEnv._gap_0x148");
static_assert(offsetof(nuccDrawEnv, field_0x178) == 0x178, "nuccDrawEnv.field_0x178");
static_assert(offsetof(nuccDrawEnv, _gap_0x180) == 0x180, "nuccDrawEnv._gap_0x180");
static_assert(offsetof(nuccDrawEnv, field_0x190) == 0x190, "nuccDrawEnv.field_0x190");
static_assert(offsetof(nuccDrawEnv, field_0x198) == 0x198, "nuccDrawEnv.field_0x198");
static_assert(offsetof(nuccDrawEnv, field_0x1A0) == 0x1A0, "nuccDrawEnv.field_0x1A0");
static_assert(offsetof(nuccDrawEnv, field_0x1A8) == 0x1A8, "nuccDrawEnv.field_0x1A8");
static_assert(offsetof(nuccDrawEnv, field_0x1B0) == 0x1B0, "nuccDrawEnv.field_0x1B0");
static_assert(offsetof(nuccDrawEnv, _gap_0x1B8) == 0x1B8, "nuccDrawEnv._gap_0x1B8");
static_assert(offsetof(nuccDrawEnv, field_0x208) == 0x208, "nuccDrawEnv.field_0x208");
static_assert(offsetof(nuccDrawEnv, _gap_0x210) == 0x210, "nuccDrawEnv._gap_0x210");
static_assert(offsetof(nuccDrawEnv, field_0x258) == 0x258, "nuccDrawEnv.field_0x258");
static_assert(offsetof(nuccDrawEnv, field_0x25C) == 0x25C, "nuccDrawEnv.field_0x25C");
static_assert(offsetof(nuccDrawEnv, field_0x260) == 0x260, "nuccDrawEnv.field_0x260");
static_assert(offsetof(nuccDrawEnv, field_0x268) == 0x268, "nuccDrawEnv.field_0x268");
static_assert(offsetof(nuccDrawEnv, field_0x26C) == 0x270, "nuccDrawEnv.field_0x26C");
static_assert(offsetof(nuccDrawEnv, field_0x274) == 0x278, "nuccDrawEnv.field_0x274");
static_assert(offsetof(nuccDrawEnv, field_0x27C) == 0x280, "nuccDrawEnv.field_0x27C");
static_assert(offsetof(nuccDrawEnv, field_0x288) == 0x288, "nuccDrawEnv.field_0x288");

/* =========================================================================
 * nuccEffectRoot
 * Size: unknown, >= 0x160 (last proven field at 0x158, size 8)
 * Subclasses nuccEffectSimpleAnm and nuccTrailGroup extend beyond this base.
 * Vtable: PTR_FUN_140678518 (set in ctor @ 0x4B7EA0)
 * Methods: 9
 * Fields: 29
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccEffectRoot {
    /* 0x00 */ void *vtable;                          /* PRES: PTR_FUN_140678518 */
    /* 0x08 */ int32_t field_0x08;                    /* PRES: init -1 */
    /* 0x0C */ uint8_t _pad_0x0C[20];                 /* padding to 0x20 */
    /* 0x20 */ uint8_t matrix_world[0x40];            /* PRES: Matrix44 identity */
    /* 0x60 */ uint8_t matrix_view[0x40];             /* PRES: Matrix44 identity */
    /* 0xA0 */ uint8_t matrix_proj[0x40];             /* PRES: Matrix44 identity */
    /* 0xE0 */ uint64_t field_0xE0;                   /* UNKNOWN: Vector3 data */
    /* 0xE8 */ uint32_t field_0xE8;                   /* PRES */
    /* 0xEC */ uint64_t field_0xEC;                   /* UNKNOWN: Vector3 data */
    /* 0xF4 */ uint32_t field_0xF4;                   /* PRES */
    /* 0xF8 */ uint64_t field_0xF8;                   /* UNKNOWN: Vector3 data */
    /* 0x100 */ uint32_t field_0x100;                 /* UNKNOWN */
    /* 0x104 */ uint64_t field_0x104;                 /* UNKNOWN: Vector3 data */
    /* 0x10C */ uint32_t field_0x10C;                 /* PRES */
    /* 0x110 */ uint64_t field_0x110;                 /* UNKNOWN: Vector3 data */
    /* 0x118 */ uint32_t field_0x118;                 /* PRES */
    /* 0x11C */ uint64_t field_0x11C;                 /* UNKNOWN: Vector3 data */
    /* 0x124 */ uint32_t field_0x124;                 /* PRES */
    /* 0x128 */ uint64_t field_0x128;                 /* UNKNOWN: Vector3 data */
    /* 0x130 */ uint32_t field_0x130;                 /* PRES */
    /* 0x134 */ uint32_t field_0x134;                 /* PRES: 1.0f as u32 */
    /* 0x138 */ uint32_t field_0x138;                 /* PRES */
    /* 0x13C */ uint32_t field_0x13C;                 /* PRES: init 0 */
    /* 0x140 */ uint32_t field_0x140;                 /* PRES */
    /* 0x144 */ uint32_t field_0x144;                 /* PRES: init 0 */
    /* 0x148 */ uint32_t field_0x148;                 /* UNKNOWN: read-only */
    /* 0x14C */ uint32_t field_0x14C;                 /* PRES: init 0 */
    /* 0x150 */ uint32_t field_0x150;                 /* PRES */
    /* 0x154 */ uint32_t field_0x154;                 /* PRES: init 1 */
    /* 0x158 */ uint64_t field_0x158;                 /* UNKNOWN */
} nuccEffectRoot;

static_assert(offsetof(nuccEffectRoot, vtable) == 0x00, "nuccEffectRoot.vtable");
static_assert(offsetof(nuccEffectRoot, field_0x08) == 0x08, "nuccEffectRoot.field_0x08");
static_assert(offsetof(nuccEffectRoot, _pad_0x0C) == 0x0C, "nuccEffectRoot._pad_0x0C");
static_assert(offsetof(nuccEffectRoot, matrix_world) == 0x20, "nuccEffectRoot.matrix_world");
static_assert(offsetof(nuccEffectRoot, matrix_view) == 0x60, "nuccEffectRoot.matrix_view");
static_assert(offsetof(nuccEffectRoot, matrix_proj) == 0xA0, "nuccEffectRoot.matrix_proj");
static_assert(offsetof(nuccEffectRoot, field_0xE0) == 0xE0, "nuccEffectRoot.field_0xE0");
static_assert(offsetof(nuccEffectRoot, field_0xE8) == 0xE8, "nuccEffectRoot.field_0xE8");
static_assert(offsetof(nuccEffectRoot, field_0xEC) == 0xEC, "nuccEffectRoot.field_0xEC");
static_assert(offsetof(nuccEffectRoot, field_0xF4) == 0xF4, "nuccEffectRoot.field_0xF4");
static_assert(offsetof(nuccEffectRoot, field_0xF8) == 0xF8, "nuccEffectRoot.field_0xF8");
static_assert(offsetof(nuccEffectRoot, field_0x100) == 0x100, "nuccEffectRoot.field_0x100");
static_assert(offsetof(nuccEffectRoot, field_0x104) == 0x104, "nuccEffectRoot.field_0x104");
static_assert(offsetof(nuccEffectRoot, field_0x10C) == 0x10C, "nuccEffectRoot.field_0x10C");
static_assert(offsetof(nuccEffectRoot, field_0x110) == 0x110, "nuccEffectRoot.field_0x110");
static_assert(offsetof(nuccEffectRoot, field_0x118) == 0x118, "nuccEffectRoot.field_0x118");
static_assert(offsetof(nuccEffectRoot, field_0x11C) == 0x11C, "nuccEffectRoot.field_0x11C");
static_assert(offsetof(nuccEffectRoot, field_0x124) == 0x124, "nuccEffectRoot.field_0x124");
static_assert(offsetof(nuccEffectRoot, field_0x128) == 0x128, "nuccEffectRoot.field_0x128");
static_assert(offsetof(nuccEffectRoot, field_0x130) == 0x130, "nuccEffectRoot.field_0x130");
static_assert(offsetof(nuccEffectRoot, field_0x134) == 0x134, "nuccEffectRoot.field_0x134");
static_assert(offsetof(nuccEffectRoot, field_0x138) == 0x138, "nuccEffectRoot.field_0x138");
static_assert(offsetof(nuccEffectRoot, field_0x13C) == 0x13C, "nuccEffectRoot.field_0x13C");
static_assert(offsetof(nuccEffectRoot, field_0x140) == 0x140, "nuccEffectRoot.field_0x140");
static_assert(offsetof(nuccEffectRoot, field_0x144) == 0x144, "nuccEffectRoot.field_0x144");
static_assert(offsetof(nuccEffectRoot, field_0x148) == 0x148, "nuccEffectRoot.field_0x148");
static_assert(offsetof(nuccEffectRoot, field_0x14C) == 0x14C, "nuccEffectRoot.field_0x14C");
static_assert(offsetof(nuccEffectRoot, field_0x150) == 0x150, "nuccEffectRoot.field_0x150");
static_assert(offsetof(nuccEffectRoot, field_0x154) == 0x154, "nuccEffectRoot.field_0x154");
static_assert(offsetof(nuccEffectRoot, field_0x158) == 0x158, "nuccEffectRoot.field_0x158");

#endif /* CMN52_S1_H */