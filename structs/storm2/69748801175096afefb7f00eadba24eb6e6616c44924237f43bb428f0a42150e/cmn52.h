/* cmn52 s2: struct group for NARUTO STORM 2 PC (NSUNS2.exe)
 * All layouts INFERRED from static analysis of build s2 (sha 697488011750).
 * Sizes proven from game code where noted; otherwise marked unknown.
 * Generated 2026-10-19.
 */
#ifndef CMN52_S2_H
#define CMN52_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccDrawEnv
 * Size: 0x289 (proven: stack alloc local_2b8[648] in FUN_1405c14b0 @ 0x5C14B0
 *        and FUN_1405d4f40 @ 0x5D4F40)
 * Vtable: PTR_FUN_1408917e8 (set in ctor @ 0x5A5930)
 * Methods: 28
 * Fields: 43
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccDrawEnv {
/* 0x00 */ void *vtable;               /* PRES: PTR_FUN_1408917e8 */
/* 0x08 */ uint16_t field_0x08;        /* UNKNOWN: ctor writes 0 */
/* 0x0A */ uint8_t _pad_0x0A[6];      /* padding to 0x10 */
/* 0x10 */ void *field_0x10;           /* UNKNOWN: &DAT_... */
/* 0x18 */ int32_t field_0x18;         /* UNKNOWN: set to 1 */
/* 0x1C */ uint8_t _pad_0x1C[4];      /* padding */
/* 0x20 */ uint8_t embedded_0x20[0x38]; /* UNKNOWN: sub-object region */
/* 0x58 */ uint64_t field_0x58;        /* UNKNOWN: DAT+0x2f0 ref */
/* 0x60 */ uint64_t field_0x60;        /* UNKNOWN: DAT+0x2b8 ref */
/* 0x68 */ uint64_t field_0x68;        /* UNKNOWN: DAT+0x3f0 ref */
/* 0x70 */ uint64_t field_0x70;        /* UNKNOWN */
/* 0x78 */ float field_0x78;           /* PRES: 1.0f */
/* 0x7C */ uint8_t _pad_0x7C[4];      /* padding */
/* 0x80 */ uint64_t field_0x80;        /* UNKNOWN: vtable-like dispatch */
/* 0x88 */ uint32_t field_0x88;        /* UNKNOWN */
/* 0x8C */ uint64_t field_0x8C;        /* PRES: init 1 */
/* 0x94 */ uint64_t field_0x94;        /* PRES: init -1 */
/* 0x9C */ uint64_t field_0x9C;        /* PRES: init -1 */
/* 0xA4 */ uint64_t field_0xA4;        /* PRES: init 0 */
/* 0xAC */ uint64_t field_0xAC;        /* PRES: init 0 */
/* 0xB4 */ uint32_t field_0xB4;        /* UNKNOWN */
/* 0xB8 */ uint8_t vector4_0xB8[0x10]; /* PRES: Vector4_MathGeo */
/* 0xC8 */ uint8_t vector4_0xC8[0x10]; /* PRES: Vector4_MathGeo */
/* 0xD8 */ uint64_t field_0xD8;        /* UNKNOWN: Vector4 region */
/* 0xE0 */ uint64_t field_0xE0;        /* PRES: init 0 */
/* 0xE8 */ uint64_t field_0xE8;        /* PRES: init 1.0f as u64 */
/* 0xF0 */ uint8_t field_0xF0;         /* PRES: init 0 */
/* 0xF1 */ uint8_t _pad_0xF1[7];      /* padding */
/* 0xF8 */ uint64_t field_0xF8;        /* UNKNOWN: draw command buffer ptr */
/* 0x100 */ uint64_t field_0x100;      /* UNKNOWN: read-only, std::tree */
/* 0x108 */ uint64_t field_0x108;      /* PRES: init 0 */
/* 0x110 */ uint64_t field_0x110;      /* UNKNOWN: BlockAllocator region */
/* 0x118 */ uint8_t _gap_0x118[0x10]; /* UNKNOWN: gap */
/* 0x128 */ uint8_t access_tbl_0x128[0x18]; /* UNKNOWN: nuccDrawEnvAccessTbl sub-obj */
/* 0x140 */ uint64_t field_0x140;      /* SIM: access table ptr (init self+0x20) */
/* 0x148 */ uint8_t _gap_0x148[0x30]; /* UNKNOWN: gap */
/* 0x178 */ uint64_t field_0x178;      /* UNKNOWN: BlockAllocator */
/* 0x180 */ uint8_t _gap_0x180[0x10]; /* UNKNOWN: gap */
/* 0x190 */ uint32_t field_0x190;      /* UNKNOWN: modifier list count */
/* 0x194 */ uint8_t _pad_0x194[4];    /* padding */
/* 0x198 */ uint64_t field_0x198;      /* UNKNOWN: modifier list array base */
/* 0x1A0 */ uint64_t field_0x1A0;      /* UNKNOWN: modifier list write ptr */
/* 0x1A8 */ uint32_t field_0x1A8;      /* UNKNOWN: trail param counter */
/* 0x1AC */ uint8_t _pad_0x1AC[4];    /* padding */
/* 0x1B0 */ uint64_t field_0x1B0;      /* PRES: init 0 */
/* 0x1B8 */ uint8_t crit_section_0x1B8[0x50]; /* UNKNOWN: nuccCriticalSection */
/* 0x208 */ uint64_t field_0x208;      /* SIM: param stack pointer */
/* 0x210 */ uint8_t color_filter_0x210[0x48]; /* UNKNOWN: nuccColorFilterManager */
/* 0x258 */ uint32_t field_0x258;      /* PRES: init 0 */
/* 0x25C */ float field_0x25C;         /* PRES: 1.0f */
/* 0x260 */ uint64_t field_0x260;      /* PRES: init 0.6f (0x3f19999a) */
/* 0x268 */ uint32_t field_0x268;      /* PRES: init 1 */
/* 0x26C */ uint8_t _pad_0x26C[4];    /* padding */
/* 0x270 */ uint64_t field_0x26C;      /* PRES: init 1 */
/* 0x278 */ uint64_t field_0x274;      /* PRES: init 0 */
/* 0x280 */ uint64_t field_0x27C;      /* PRES: init 0 */
/* 0x288 */ uint8_t field_0x288;       /* PRES: flag, last field */
} ns2_nuccDrawEnv;

static_assert(offsetof(ns2_nuccDrawEnv, vtable) == 0x00, "ns2_nuccDrawEnv.vtable");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x08) == 0x08, "ns2_nuccDrawEnv.field_0x08");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x10) == 0x10, "ns2_nuccDrawEnv.field_0x10");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x18) == 0x18, "ns2_nuccDrawEnv.field_0x18");
static_assert(offsetof(ns2_nuccDrawEnv, embedded_0x20) == 0x20, "ns2_nuccDrawEnv.embedded_0x20");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x58) == 0x58, "ns2_nuccDrawEnv.field_0x58");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x60) == 0x60, "ns2_nuccDrawEnv.field_0x60");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x68) == 0x68, "ns2_nuccDrawEnv.field_0x68");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x70) == 0x70, "ns2_nuccDrawEnv.field_0x70");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x78) == 0x78, "ns2_nuccDrawEnv.field_0x78");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x80) == 0x80, "ns2_nuccDrawEnv.field_0x80");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x88) == 0x88, "ns2_nuccDrawEnv.field_0x88");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x8C) == 0x8C, "ns2_nuccDrawEnv.field_0x8C");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x94) == 0x94, "ns2_nuccDrawEnv.field_0x94");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x9C) == 0x9C, "ns2_nuccDrawEnv.field_0x9C");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xA4) == 0xA4, "ns2_nuccDrawEnv.field_0xA4");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xAC) == 0xAC, "ns2_nuccDrawEnv.field_0xAC");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xB4) == 0xB4, "ns2_nuccDrawEnv.field_0xB4");
static_assert(offsetof(ns2_nuccDrawEnv, vector4_0xB8) == 0xB8, "ns2_nuccDrawEnv.vector4_0xB8");
static_assert(offsetof(ns2_nuccDrawEnv, vector4_0xC8) == 0xC8, "ns2_nuccDrawEnv.vector4_0xC8");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xD8) == 0xD8, "ns2_nuccDrawEnv.field_0xD8");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xE0) == 0xE0, "ns2_nuccDrawEnv.field_0xE0");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xE8) == 0xE8, "ns2_nuccDrawEnv.field_0xE8");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xF0) == 0xF0, "ns2_nuccDrawEnv.field_0xF0");
static_assert(offsetof(ns2_nuccDrawEnv, field_0xF8) == 0xF8, "ns2_nuccDrawEnv.field_0xF8");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x100) == 0x100, "ns2_nuccDrawEnv.field_0x100");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x108) == 0x108, "ns2_nuccDrawEnv.field_0x108");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x110) == 0x110, "ns2_nuccDrawEnv.field_0x110");
static_assert(offsetof(ns2_nuccDrawEnv, _gap_0x118) == 0x118, "ns2_nuccDrawEnv._gap_0x118");
static_assert(offsetof(ns2_nuccDrawEnv, access_tbl_0x128) == 0x128, "ns2_nuccDrawEnv.access_tbl_0x128");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x140) == 0x140, "ns2_nuccDrawEnv.field_0x140");
static_assert(offsetof(ns2_nuccDrawEnv, _gap_0x148) == 0x148, "ns2_nuccDrawEnv._gap_0x148");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x178) == 0x178, "ns2_nuccDrawEnv.field_0x178");
static_assert(offsetof(ns2_nuccDrawEnv, _gap_0x180) == 0x180, "ns2_nuccDrawEnv._gap_0x180");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x190) == 0x190, "ns2_nuccDrawEnv.field_0x190");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x198) == 0x198, "ns2_nuccDrawEnv.field_0x198");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x1A0) == 0x1A0, "ns2_nuccDrawEnv.field_0x1A0");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x1A8) == 0x1A8, "ns2_nuccDrawEnv.field_0x1A8");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x1B0) == 0x1B0, "ns2_nuccDrawEnv.field_0x1B0");
static_assert(offsetof(ns2_nuccDrawEnv, crit_section_0x1B8) == 0x1B8, "ns2_nuccDrawEnv.crit_section_0x1B8");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x208) == 0x208, "ns2_nuccDrawEnv.field_0x208");
static_assert(offsetof(ns2_nuccDrawEnv, color_filter_0x210) == 0x210, "ns2_nuccDrawEnv.color_filter_0x210");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x258) == 0x258, "ns2_nuccDrawEnv.field_0x258");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x25C) == 0x25C, "ns2_nuccDrawEnv.field_0x25C");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x260) == 0x260, "ns2_nuccDrawEnv.field_0x260");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x268) == 0x268, "ns2_nuccDrawEnv.field_0x268");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x26C) == 0x270, "ns2_nuccDrawEnv.field_0x26C");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x274) == 0x278, "ns2_nuccDrawEnv.field_0x274");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x27C) == 0x280, "ns2_nuccDrawEnv.field_0x27C");
static_assert(offsetof(ns2_nuccDrawEnv, field_0x288) == 0x288, "ns2_nuccDrawEnv.field_0x288");

/* =========================================================================
 * nuccEffectRoot
 * Size: unknown, >= 0x160 (last proven field at 0x158, size 8)
 * Subclasses extend beyond this base.
 * Vtable: PTR_FUN_140865580 (set in ctor @ 0x5C73A0)
 * Methods: 8
 * Fields: 29
 * ========================================================================= */
typedef struct __attribute__((packed)) ns2_nuccEffectRoot {
/* 0x00 */ void *vtable;               /* PRES: PTR_FUN_140865580 */
/* 0x08 */ int32_t field_0x08;         /* PRES: init -1 */
/* 0x0C */ uint8_t _pad_0x0C[4];      /* padding */
/* 0x10 */ uint64_t field_0x10;        /* PRES: init 0 */
/* 0x18 */ uint64_t field_0x18;        /* PRES: init 0 */
/* 0x20 */ uint8_t matrix_world[0x40]; /* PRES: Matrix44 identity */
/* 0x60 */ uint8_t matrix_view[0x40];  /* PRES: Matrix44 identity */
/* 0xA0 */ uint8_t matrix_proj[0x40];  /* PRES: Matrix44 identity */
/* 0xE0 */ uint64_t field_0xE0;        /* UNKNOWN: Vector3 data */
/* 0xE8 */ uint32_t field_0xE8;        /* PRES */
/* 0xEC */ uint64_t field_0xEC;        /* UNKNOWN: Vector3 data */
/* 0xF4 */ uint32_t field_0xF4;        /* PRES */
/* 0xF8 */ uint64_t field_0xF8;        /* UNKNOWN: Vector3 data */
/* 0x100 */ uint32_t field_0x100;      /* UNKNOWN */
/* 0x104 */ uint64_t field_0x104;      /* UNKNOWN: Vector3 data */
/* 0x10C */ uint32_t field_0x10C;      /* PRES */
/* 0x110 */ uint64_t field_0x110;      /* UNKNOWN: Vector3 data */
/* 0x118 */ uint32_t field_0x118;      /* PRES */
/* 0x11C */ uint64_t field_0x11C;      /* UNKNOWN: Vector3 data */
/* 0x124 */ uint32_t field_0x124;      /* PRES */
/* 0x128 */ uint64_t field_0x128;      /* UNKNOWN: Vector3 data */
/* 0x130 */ uint32_t field_0x130;      /* PRES */
/* 0x134 */ uint32_t field_0x134;      /* PRES: 1.0f as u32 */
/* 0x138 */ uint32_t field_0x138;      /* PRES */
/* 0x13C */ uint32_t field_0x13C;      /* PRES: init 0 */
/* 0x140 */ uint32_t field_0x140;      /* PRES */
/* 0x144 */ uint32_t field_0x144;      /* PRES: init 0 */
/* 0x148 */ uint32_t field_0x148;      /* UNKNOWN: read-only */
/* 0x14C */ uint32_t field_0x14C;      /* PRES: init 0 */
/* 0x150 */ uint32_t field_0x150;      /* PRES */
/* 0x154 */ uint32_t field_0x154;      /* PRES: init 1 */
/* 0x158 */ uint64_t field_0x158;      /* UNKNOWN */
} ns2_nuccEffectRoot;

static_assert(offsetof(ns2_nuccEffectRoot, vtable) == 0x00, "ns2_nuccEffectRoot.vtable");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x08) == 0x08, "ns2_nuccEffectRoot.field_0x08");
static_assert(offsetof(ns2_nuccEffectRoot, _pad_0x0C) == 0x0C, "ns2_nuccEffectRoot._pad_0x0C");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x10) == 0x10, "ns2_nuccEffectRoot.field_0x10");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x18) == 0x18, "ns2_nuccEffectRoot.field_0x18");
static_assert(offsetof(ns2_nuccEffectRoot, matrix_world) == 0x20, "ns2_nuccEffectRoot.matrix_world");
static_assert(offsetof(ns2_nuccEffectRoot, matrix_view) == 0x60, "ns2_nuccEffectRoot.matrix_view");
static_assert(offsetof(ns2_nuccEffectRoot, matrix_proj) == 0xA0, "ns2_nuccEffectRoot.matrix_proj");
static_assert(offsetof(ns2_nuccEffectRoot, field_0xE0) == 0xE0, "ns2_nuccEffectRoot.field_0xE0");
static_assert(offsetof(ns2_nuccEffectRoot, field_0xE8) == 0xE8, "ns2_nuccEffectRoot.field_0xE8");
static_assert(offsetof(ns2_nuccEffectRoot, field_0xEC) == 0xEC, "ns2_nuccEffectRoot.field_0xEC");
static_assert(offsetof(ns2_nuccEffectRoot, field_0xF4) == 0xF4, "ns2_nuccEffectRoot.field_0xF4");
static_assert(offsetof(ns2_nuccEffectRoot, field_0xF8) == 0xF8, "ns2_nuccEffectRoot.field_0xF8");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x100) == 0x100, "ns2_nuccEffectRoot.field_0x100");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x104) == 0x104, "ns2_nuccEffectRoot.field_0x104");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x10C) == 0x10C, "ns2_nuccEffectRoot.field_0x10C");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x110) == 0x110, "ns2_nuccEffectRoot.field_0x110");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x118) == 0x118, "ns2_nuccEffectRoot.field_0x118");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x11C) == 0x11C, "ns2_nuccEffectRoot.field_0x11C");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x124) == 0x124, "ns2_nuccEffectRoot.field_0x124");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x128) == 0x128, "ns2_nuccEffectRoot.field_0x128");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x130) == 0x130, "ns2_nuccEffectRoot.field_0x130");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x134) == 0x134, "ns2_nuccEffectRoot.field_0x134");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x138) == 0x138, "ns2_nuccEffectRoot.field_0x138");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x13C) == 0x13C, "ns2_nuccEffectRoot.field_0x13C");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x140) == 0x140, "ns2_nuccEffectRoot.field_0x140");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x144) == 0x144, "ns2_nuccEffectRoot.field_0x144");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x148) == 0x148, "ns2_nuccEffectRoot.field_0x148");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x14C) == 0x14C, "ns2_nuccEffectRoot.field_0x14C");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x150) == 0x150, "ns2_nuccEffectRoot.field_0x150");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x154) == 0x154, "ns2_nuccEffectRoot.field_0x154");
static_assert(offsetof(ns2_nuccEffectRoot, field_0x158) == 0x158, "ns2_nuccEffectRoot.field_0x158");

#endif /* CMN52_S2_H */
/* =========================================================================
 * nuccDrawEnvModifierList
 * Size: 0x40 (proven: embedded in nuccDrawEnv at offset 0x178; next sibling
 *        crit_section_0x1B8 starts at 0x1B8; 0x1B8 - 0x178 = 0x40)
 * Vtable: inherited (virtual dispatch at vtable+8 and vtable+0x10)
 * Methods: 5
 * Fields: 5
 * Always embedded in nuccDrawEnv; no standalone heap allocation found.
 * Entry nodes (inner class) use vtable PTR_FUN_140898ce8, size 0x18.
 * All layouts INFERRED from static analysis of build s2.
 * ========================================================================= */
#pragma pack(push, 1)
typedef struct ns2_nuccDrawEnvModifierList {
/* 0x00 */ void *vtable;               /* INHERITED: virtual dispatch slots at +8, +0x10 */
/* 0x08 */ uint8_t _base_0x08[0x10];  /* INHERITED: base class region (not accessed directly) */
/* 0x18 */ int32_t field_0x18;         /* UNKNOWN: capacity / array bound limit */
/* 0x1C */ uint8_t _pad_0x1C[4];      /* padding to 0x20 */
/* 0x20 */ void *field_0x20;           /* UNKNOWN: array base pointer (bounds check) */
/* 0x28 */ void *field_0x28;           /* UNKNOWN: array of entry pointers */
/* 0x30 */ int32_t field_0x30;         /* UNKNOWN: current count / write index */
/* 0x34 */ uint8_t _pad_0x34[4];      /* padding to 0x38 */
/* 0x38 */ uint64_t field_0x38;        /* UNKNOWN: written in SetTrailParameter */
} ns2_nuccDrawEnvModifierList;
#pragma pack(pop)

static_assert(offsetof(ns2_nuccDrawEnvModifierList, vtable) == 0x00, "ns2_nuccDrawEnvModifierList.vtable");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, _base_0x08) == 0x08, "ns2_nuccDrawEnvModifierList._base_0x08");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, field_0x18) == 0x18, "ns2_nuccDrawEnvModifierList.field_0x18");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, _pad_0x1C) == 0x1C, "ns2_nuccDrawEnvModifierList._pad_0x1C");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, field_0x20) == 0x20, "ns2_nuccDrawEnvModifierList.field_0x20");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, field_0x28) == 0x28, "ns2_nuccDrawEnvModifierList.field_0x28");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, field_0x30) == 0x30, "ns2_nuccDrawEnvModifierList.field_0x30");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, _pad_0x34) == 0x34, "ns2_nuccDrawEnvModifierList._pad_0x34");
static_assert(offsetof(ns2_nuccDrawEnvModifierList, field_0x38) == 0x38, "ns2_nuccDrawEnvModifierList.field_0x38");
