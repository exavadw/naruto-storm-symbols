/* cmn52 s4: struct group for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe)
 * All layouts INFERRED from static analysis of build s4.
 * Sizes proven from game code where noted; otherwise marked unknown.
 * Generated 2026-10-19.
 */
#ifndef CMN52_S4_H
#define CMN52_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccDrawEnv
 * Size: 0x290 (proven: operator_new(0x290,...) @ RVA 0xA24BF0 in Initialize)
 * Vtable: PTR_FUN_141106990 (set in ctor @ RVA 0xA239E0 / 0xA23DB0)
 * Methods: 29
 * Fields: 47 (including padding)
 * ========================================================================= */
typedef struct __attribute__((packed)) ns4_nuccDrawEnv {
 /* 0x000 */ void *vtable; /* PRES: PTR_FUN_141106990 */
 /* 0x008 */ uint16_t field_0x08; /* UNKNOWN: ctor writes 0 */
 /* 0x00A */ uint8_t _pad_0x0A[6]; /* padding to 0x10 */
 /* 0x010 */ void *field_0x10; /* PRES: &DAT_141106850 */
 /* 0x018 */ int32_t field_0x18; /* PRES: init 1 */
 /* 0x01C */ uint8_t _pad_0x1C[4]; /* padding */
 /* 0x020 */ uint8_t embedded_0x20[0x38];/* UNKNOWN: sub-object region */
 /* 0x058 */ uint64_t field_0x58; /* PRES: DAT+0x2f0 ref (Reset) */
 /* 0x060 */ uint64_t field_0x60; /* PRES: DAT+0x2b8 ref */
 /* 0x068 */ uint64_t field_0x68; /* PRES: DAT+0x3f0 ref */
 /* 0x070 */ uint64_t field_0x70; /* PRES: DAT+0x400 ref */
 /* 0x078 */ float field_0x78; /* PRES: 1.0f */
 /* 0x07C */ uint8_t _pad_0x7C[4]; /* padding */
 /* 0x080 */ uint64_t field_0x80; /* UNKNOWN: vtable-like dispatch */
 /* 0x088 */ uint32_t field_0x88; /* UNKNOWN */
 /* 0x08C */ uint64_t field_0x8C; /* PRES: init 1 */
 /* 0x094 */ uint64_t field_0x94; /* PRES: init -1 */
 /* 0x09C */ uint64_t field_0x9C; /* PRES: init -1 */
 /* 0x0A4 */ uint64_t field_0xA4; /* PRES: init 0 */
 /* 0x0AC */ uint64_t field_0xAC; /* PRES: init 0 */
 /* 0x0B4 */ uint32_t field_0xB4; /* PRES: init 0 */
 /* 0x0B8 */ uint8_t vector4_0xB8[0x10]; /* PRES: Vector4_MathGeo */
 /* 0x0C8 */ uint8_t vector4_0xC8[0x10]; /* PRES: Vector4_MathGeo */
 /* 0x0D8 */ uint64_t field_0xD8; /* PRES: init 1.0f as u64 */
 /* 0x0E0 */ uint64_t field_0xE0; /* PRES: init 0 */
 /* 0x0E8 */ uint64_t field_0xE8; /* PRES: init 1.0f as u64 */
 /* 0x0F0 */ uint8_t field_0xF0; /* PRES: init 0 */
 /* 0x0F1 */ uint8_t _pad_0xF1[7]; /* padding */
 /* 0x0F8 */ uint64_t field_0xF8; /* UNKNOWN: load bank manager ptr */
 /* 0x100 */ uint64_t field_0x100; /* UNKNOWN: std::tree region */
 /* 0x108 */ uint64_t field_0x108; /* PRES: init 0 */
 /* 0x110 */ uint64_t field_0x110; /* UNKNOWN: BlockAllocator region */
 /* 0x118 */ uint8_t _gap_0x118[0x10]; /* UNKNOWN: gap */
 /* 0x128 */ uint8_t access_tbl_0x128[0x18]; /* UNKNOWN: nuccDrawEnvAccessTbl */
 /* 0x140 */ uint64_t field_0x140; /* SIM: access table ptr */
 /* 0x148 */ uint8_t _gap_0x148[0x30]; /* UNKNOWN: gap */
 /* 0x178 */ uint64_t field_0x178; /* UNKNOWN: BlockAllocator */
 /* 0x180 */ uint8_t _gap_0x180[0x10]; /* UNKNOWN: gap */
 /* 0x190 */ uint64_t field_0x190; /* UNKNOWN: modifier list count */
 /* 0x198 */ uint64_t field_0x198; /* UNKNOWN: modifier list array */
 /* 0x1A0 */ uint64_t field_0x1A0; /* UNKNOWN: modifier list write ptr */
 /* 0x1A8 */ uint32_t field_0x1A8; /* UNKNOWN: trail param counter */
 /* 0x1AC */ uint8_t _pad_0x1AC[4]; /* padding */
 /* 0x1B0 */ uint64_t field_0x1B0; /* PRES: init 0 */
 /* 0x1B8 */ uint8_t crit_section_0x1B8[0x50]; /* UNKNOWN: nuccCriticalSection */
 /* 0x208 */ uint64_t field_0x208; /* SIM: param stack pointer */
 /* 0x210 */ uint8_t color_filter_0x210[0x48]; /* UNKNOWN: nuccColorFilterManager */
 /* 0x258 */ uint32_t field_0x258; /* PRES: init 0 */
 /* 0x25C */ float field_0x25C; /* PRES: 1.0f */
 /* 0x260 */ uint8_t _pad_0x260[4]; /* padding */
 /* 0x264 */ uint64_t field_0x264; /* PRES: init 0.6f */
 /* 0x26C */ uint64_t field_0x26C; /* PRES: init 1 */
 /* 0x274 */ uint64_t field_0x274; /* PRES: init 0 */
 /* 0x27C */ uint64_t field_0x27C; /* PRES: init 0 */
 /* 0x284 */ uint32_t field_0x284; /* PRES: init 1 */
 /* 0x288 */ uint8_t field_0x288; /* PRES: flag */
 /* 0x289 */ uint8_t _pad_0x289[7]; /* padding to 0x290 */
} ns4_nuccDrawEnv;

static_assert(sizeof(ns4_nuccDrawEnv) == 0x290, "ns4_nuccDrawEnv size");
static_assert(offsetof(ns4_nuccDrawEnv, vtable) == 0x000, "ns4_nuccDrawEnv.vtable");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x08) == 0x008, "ns4_nuccDrawEnv.field_0x08");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0x0A) == 0x00A, "ns4_nuccDrawEnv._pad_0x0A");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x10) == 0x010, "ns4_nuccDrawEnv.field_0x10");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x18) == 0x018, "ns4_nuccDrawEnv.field_0x18");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0x1C) == 0x01C, "ns4_nuccDrawEnv._pad_0x1C");
static_assert(offsetof(ns4_nuccDrawEnv, embedded_0x20) == 0x020, "ns4_nuccDrawEnv.embedded_0x20");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x58) == 0x058, "ns4_nuccDrawEnv.field_0x58");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x60) == 0x060, "ns4_nuccDrawEnv.field_0x60");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x68) == 0x068, "ns4_nuccDrawEnv.field_0x68");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x70) == 0x070, "ns4_nuccDrawEnv.field_0x70");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x78) == 0x078, "ns4_nuccDrawEnv.field_0x78");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0x7C) == 0x07C, "ns4_nuccDrawEnv._pad_0x7C");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x80) == 0x080, "ns4_nuccDrawEnv.field_0x80");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x88) == 0x088, "ns4_nuccDrawEnv.field_0x88");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x8C) == 0x08C, "ns4_nuccDrawEnv.field_0x8C");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x94) == 0x094, "ns4_nuccDrawEnv.field_0x94");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x9C) == 0x09C, "ns4_nuccDrawEnv.field_0x9C");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xA4) == 0x0A4, "ns4_nuccDrawEnv.field_0xA4");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xAC) == 0x0AC, "ns4_nuccDrawEnv.field_0xAC");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xB4) == 0x0B4, "ns4_nuccDrawEnv.field_0xB4");
static_assert(offsetof(ns4_nuccDrawEnv, vector4_0xB8) == 0x0B8, "ns4_nuccDrawEnv.vector4_0xB8");
static_assert(offsetof(ns4_nuccDrawEnv, vector4_0xC8) == 0x0C8, "ns4_nuccDrawEnv.vector4_0xC8");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xD8) == 0x0D8, "ns4_nuccDrawEnv.field_0xD8");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xE0) == 0x0E0, "ns4_nuccDrawEnv.field_0xE0");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xE8) == 0x0E8, "ns4_nuccDrawEnv.field_0xE8");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xF0) == 0x0F0, "ns4_nuccDrawEnv.field_0xF0");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0xF1) == 0x0F1, "ns4_nuccDrawEnv._pad_0xF1");
static_assert(offsetof(ns4_nuccDrawEnv, field_0xF8) == 0x0F8, "ns4_nuccDrawEnv.field_0xF8");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x100) == 0x100, "ns4_nuccDrawEnv.field_0x100");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x108) == 0x108, "ns4_nuccDrawEnv.field_0x108");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x110) == 0x110, "ns4_nuccDrawEnv.field_0x110");
static_assert(offsetof(ns4_nuccDrawEnv, _gap_0x118) == 0x118, "ns4_nuccDrawEnv._gap_0x118");
static_assert(offsetof(ns4_nuccDrawEnv, access_tbl_0x128) == 0x128, "ns4_nuccDrawEnv.access_tbl_0x128");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x140) == 0x140, "ns4_nuccDrawEnv.field_0x140");
static_assert(offsetof(ns4_nuccDrawEnv, _gap_0x148) == 0x148, "ns4_nuccDrawEnv._gap_0x148");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x178) == 0x178, "ns4_nuccDrawEnv.field_0x178");
static_assert(offsetof(ns4_nuccDrawEnv, _gap_0x180) == 0x180, "ns4_nuccDrawEnv._gap_0x180");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x190) == 0x190, "ns4_nuccDrawEnv.field_0x190");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x198) == 0x198, "ns4_nuccDrawEnv.field_0x198");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x1A0) == 0x1A0, "ns4_nuccDrawEnv.field_0x1A0");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x1A8) == 0x1A8, "ns4_nuccDrawEnv.field_0x1A8");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0x1AC) == 0x1AC, "ns4_nuccDrawEnv._pad_0x1AC");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x1B0) == 0x1B0, "ns4_nuccDrawEnv.field_0x1B0");
static_assert(offsetof(ns4_nuccDrawEnv, crit_section_0x1B8) == 0x1B8, "ns4_nuccDrawEnv.crit_section_0x1B8");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x208) == 0x208, "ns4_nuccDrawEnv.field_0x208");
static_assert(offsetof(ns4_nuccDrawEnv, color_filter_0x210) == 0x210, "ns4_nuccDrawEnv.color_filter_0x210");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x258) == 0x258, "ns4_nuccDrawEnv.field_0x258");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x25C) == 0x25C, "ns4_nuccDrawEnv.field_0x25C");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0x260) == 0x260, "ns4_nuccDrawEnv._pad_0x260");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x264) == 0x264, "ns4_nuccDrawEnv.field_0x264");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x26C) == 0x26C, "ns4_nuccDrawEnv.field_0x26C");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x274) == 0x274, "ns4_nuccDrawEnv.field_0x274");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x27C) == 0x27C, "ns4_nuccDrawEnv.field_0x27C");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x284) == 0x284, "ns4_nuccDrawEnv.field_0x284");
static_assert(offsetof(ns4_nuccDrawEnv, field_0x288) == 0x288, "ns4_nuccDrawEnv.field_0x288");
static_assert(offsetof(ns4_nuccDrawEnv, _pad_0x289) == 0x289, "ns4_nuccDrawEnv._pad_0x289");

/* =========================================================================
 * nuccEffectRoot
 * Size: unknown, >= 0x160 (last proven field at 0x158; no direct alloc found)
 * Vtable: PTR_FUN_1410cd020 (set in ctor @ RVA 0xA4DB20)
 * Methods: 7
 * Fields: 32 (including padding)
 * ========================================================================= */
typedef struct __attribute__((packed)) ns4_nuccEffectRoot {
 /* 0x000 */ void *vtable; /* PRES: PTR_FUN_1410cd020 */
 /* 0x008 */ uint8_t _pad_0x08[0x18]; /* padding/gap before matrices */
 /* 0x020 */ uint8_t matrix44_0x20[0x40]; /* PRES: Matrix44 identity (ctor) */
 /* 0x060 */ uint8_t matrix44_0x60[0x40]; /* PRES: Matrix44 identity (ctor) */
 /* 0x0A0 */ uint8_t matrix44_0xA0[0x40]; /* PRES: Matrix44 identity (ctor) */
 /* 0x0E0 */ uint8_t vec3_pair_0xE0[0x18]; /* PRES: Vector3+float pair (ctor) */
 /* 0x0F8 */ uint8_t vec3_pair_0xF8[0x18]; /* PRES: Vector3+float pair (ctor) */
 /* 0x110 */ uint8_t vec3_pair_0x110[0x18]; /* PRES: Vector3+float pair (ctor) */
 /* 0x128 */ uint8_t vec3_pair_0x128[0x18]; /* PRES: Vector3+float pair (ctor) */
 /* 0x140 */ uint8_t vec3_pair_0x140[0x18]; /* PRES: Vector3+float pair (ctor) */
 /* 0x158 */ uint64_t field_0x158; /* PRES: init 1 (param_1[0x2b]=1 in ctor) */
 /* end: size unknown, >= 0x160 */
} ns4_nuccEffectRoot;

static_assert(offsetof(ns4_nuccEffectRoot, vtable) == 0x000, "ns4_nuccEffectRoot.vtable");
static_assert(offsetof(ns4_nuccEffectRoot, _pad_0x08) == 0x008, "ns4_nuccEffectRoot._pad_0x08");
static_assert(offsetof(ns4_nuccEffectRoot, matrix44_0x20) == 0x020, "ns4_nuccEffectRoot.matrix44_0x20");
static_assert(offsetof(ns4_nuccEffectRoot, matrix44_0x60) == 0x060, "ns4_nuccEffectRoot.matrix44_0x60");
static_assert(offsetof(ns4_nuccEffectRoot, matrix44_0xA0) == 0x0A0, "ns4_nuccEffectRoot.matrix44_0xA0");
static_assert(offsetof(ns4_nuccEffectRoot, vec3_pair_0xE0) == 0x0E0, "ns4_nuccEffectRoot.vec3_pair_0xE0");
static_assert(offsetof(ns4_nuccEffectRoot, vec3_pair_0xF8) == 0x0F8, "ns4_nuccEffectRoot.vec3_pair_0xF8");
static_assert(offsetof(ns4_nuccEffectRoot, vec3_pair_0x110) == 0x110, "ns4_nuccEffectRoot.vec3_pair_0x110");
static_assert(offsetof(ns4_nuccEffectRoot, vec3_pair_0x128) == 0x128, "ns4_nuccEffectRoot.vec3_pair_0x128");
static_assert(offsetof(ns4_nuccEffectRoot, vec3_pair_0x140) == 0x140, "ns4_nuccEffectRoot.vec3_pair_0x140");
static_assert(offsetof(ns4_nuccEffectRoot, field_0x158) == 0x158, "ns4_nuccEffectRoot.field_0x158");

#endif /* CMN52_S4_H */

/* =========================================================================
 * nuccDrawEnvModifierList
 * Size: 0x90 (proven: embedded in ns4_nuccDrawEnv at offset 0x178,
 *   next field at 0x208 = param_1[0x41] in PopParam @ RVA 0xA24D50;
 *   0x208 - 0x178 = 0x90)
 * Vtable: PTR_FUN_14110fe80 (set in ctor @ RVA 0xA8B880)
 * Methods: 5
 * Fields: 11 (including padding and embedded crit section)
 * Notes: Pool-based modifier list with embedded nuccCriticalSection.
 *   Each pool entry is 0x20 bytes (MallocCore stride in init @ 0xA24700).
 *   All layouts INFERRED from static analysis.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct ns4_nuccDrawEnvModifierList {
 /* 0x00 */ void *vtable;              /* PRES: PTR_FUN_14110fe80 (ctor 0xA8B880) */
 /* 0x08 */ uint64_t field_0x08;       /* PRES: init 0 (ctor); link/prev in EntryModifier */
 /* 0x10 */ uint64_t field_0x10;       /* PRES: init 0 (ctor); head/next in UndoMethod */
 /* 0x18 */ int32_t capacity;          /* PRES: param_1[3] in init 0xA24700 */
 /* 0x1C */ uint8_t _pad_0x1C[4];     /* padding to 0x20 */
 /* 0x20 */ uint64_t pool_base;        /* PRES: MallocCore result in init 0xA24700 */
 /* 0x28 */ uint64_t index_array;      /* PRES: operator_new result in init 0xA24700 */
 /* 0x30 */ int32_t current_count;     /* PRES: param_1[6] in 0xA249D0/0xA24CC0 */
 /* 0x34 */ uint8_t _pad_0x34[4];     /* padding to 0x38 */
 /* 0x38 */ uint64_t pool_alloc_base;  /* PRES: param_1[7] in init 0xA24700 */
 /* 0x40 */ uint8_t crit_section[0x50];/* PRES: nuccCriticalSection (Lock/Unlock @ +0x40) */
} ns4_nuccDrawEnvModifierList;
#pragma pack(pop)

static_assert(sizeof(ns4_nuccDrawEnvModifierList) == 0x90, "ns4_nuccDrawEnvModifierList size");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, vtable) == 0x00, "ns4_nuccDrawEnvModifierList.vtable");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, field_0x08) == 0x08, "ns4_nuccDrawEnvModifierList.field_0x08");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, field_0x10) == 0x10, "ns4_nuccDrawEnvModifierList.field_0x10");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, capacity) == 0x18, "ns4_nuccDrawEnvModifierList.capacity");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, _pad_0x1C) == 0x1C, "ns4_nuccDrawEnvModifierList._pad_0x1C");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, pool_base) == 0x20, "ns4_nuccDrawEnvModifierList.pool_base");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, index_array) == 0x28, "ns4_nuccDrawEnvModifierList.index_array");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, current_count) == 0x30, "ns4_nuccDrawEnvModifierList.current_count");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, _pad_0x34) == 0x34, "ns4_nuccDrawEnvModifierList._pad_0x34");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, pool_alloc_base) == 0x38, "ns4_nuccDrawEnvModifierList.pool_alloc_base");
static_assert(offsetof(ns4_nuccDrawEnvModifierList, crit_section) == 0x40, "ns4_nuccDrawEnvModifierList.crit_section");
