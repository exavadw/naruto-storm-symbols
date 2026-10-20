/*
 * nuccAnm — NARUTO STORM 2 PC (NSUNS2.exe, build s2, sha 697488011750)
 * Reconstructed from Ghidra decompilation cache via the decompiler cache.
 * All fields INFERRED from static analysis; not runtime-confirmed.
 *
 * Inheritance: nuccAnm -> nuccAnmMiddle -> nuccAnmBase (same as s1)
 * Object size: 0x1B8 (440 bytes), from FUN_140580190(0x1b8,...) in FUN_1401ed020
 * Vtable: PTR_FUN_140891468 (nuccAnm ctor sets *param_1 = &PTR_FUN_140891468)
 */

#ifndef NUCC_ANM_S2_H
#define NUCC_ANM_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for types not yet reconstructed */
typedef struct nuccInstanceList nuccInstanceList;

/*
 * Nucc::Matrix44_MathGeo — 4x4 matrix (64 bytes = 16 floats).
 * Constructor calls SetIdentity; used at nuccAnmBase+0x50.
 * Carried from s1 layout.
 */
struct Nucc_Matrix44_MathGeo {
    float m[4][4];
};

/*
 * nuccAnmBase — base class (offsets 0x00–0x97)
 * Vtable: set by base ctor chain
 * sizeof = 0x98 (carried from s1; same field pattern observed in s2 Elapse)
 */
typedef struct nuccAnmBase {
    /* 0x00 */ void *vtable; /* PTR_FUN_140891468 set by ctor */
    /* 0x08 */ uint8_t pad_08[0x10]; /* BlockAllocator or other base fields */
    /* 0x18 */ uint64_t unk_18; /* initialized to 0 in ctor */
    /* 0x20 */ uint64_t unk_20; /* param_1[4]=0 → 0x20 */
    /* 0x28 */ uint64_t coord_ptr; /* param_1[5] → 0x28; read by Elapse loop */
    /* 0x30 */ uint64_t anim_controller; /* ConstructAnimationController writes here */
    /* 0x38 */ uint8_t pad_38[0x04]; /* gap between anim_controller end and timer */
    /* 0x3C */ int32_t timer; /* Elapse reads/writes *(int*)(param_1+0x3c) */
    /* 0x40 */ uint8_t pad_40[0x04]; /* align */
    /* 0x44 */ int32_t unk_44; /* state_surface: sz=4 r; checked in ConstructObjectTable */
    /* 0x48 */ float speed_scale; /* Elapse: *(float*)(param_1+0x48); ctor sets 1.0f */
    /* 0x4C */ float unk_4c; /* ctor sets 0x3f800000 = 1.0f */
    /* 0x50 */ struct Nucc_Matrix44_MathGeo transform; /* Matrix44, 64 bytes */
    /* 0x90 */ nuccInstanceList *instance_list; /* param_1[0x12] → 0x90; passed to FUN_1405dbe20 */
} nuccAnmBase;

static_assert(offsetof(nuccAnmBase, vtable) == 0x00, "nuccAnmBase.vtable");
static_assert(offsetof(nuccAnmBase, unk_18) == 0x18, "nuccAnmBase.unk_18");
static_assert(offsetof(nuccAnmBase, unk_20) == 0x20, "nuccAnmBase.unk_20");
static_assert(offsetof(nuccAnmBase, coord_ptr) == 0x28, "nuccAnmBase.coord_ptr");
static_assert(offsetof(nuccAnmBase, anim_controller) == 0x30, "nuccAnmBase.anim_controller");
static_assert(offsetof(nuccAnmBase, timer) == 0x3C, "nuccAnmBase.timer");
static_assert(offsetof(nuccAnmBase, unk_44) == 0x44, "nuccAnmBase.unk_44");
static_assert(offsetof(nuccAnmBase, speed_scale) == 0x48, "nuccAnmBase.speed_scale");
static_assert(offsetof(nuccAnmBase, unk_4c) == 0x4C, "nuccAnmBase.unk_4c");
static_assert(offsetof(nuccAnmBase, transform) == 0x50, "nuccAnmBase.transform");
static_assert(offsetof(nuccAnmBase, instance_list) == 0x90, "nuccAnmBase.instance_list");
static_assert(sizeof(nuccAnmBase) == 0x98, "nuccAnmBase size");

/*
 * nuccAnmMiddle — middle class (offsets 0x98–0xF7)
 * Vtable: inherited from base chain
 * Fields derived from s2 constructor pattern (same offsets as s1)
 * sizeof = 0xF8
 */
typedef struct nuccAnmMiddle {
    struct nuccAnmBase base; /* 0x00–0x97, sizeof=0x98 */
    /* 0x98 */ uint8_t pad_98[0x18]; /* gap to 0xB0 */
    /* 0xB0 */ uint64_t unk_b0; /* param_1[0x16]=0 → 0xB0 */
    /* 0xB8 */ uint64_t unk_b8; /* *(uint32*)(param_1+0x17)=0 → 0xB8 */
    /* 0xC0 */ uint64_t unk_c0; /* beginAnm caller reads param_1[5]+0xc0 */
    /* 0xC8 */ uint32_t unk_c8; /* param_1[0x19]=0xffffffff → 0xC8 */
    /* 0xCC */ int32_t unk_cc; /* ctor sets 1 */
    /* 0xD0 */ uint32_t unk_d0; /* param_1[0x1a] → 0xD0 */
    /* 0xD4 */ uint8_t pad_d4[0x04]; /* align to 0xD8 */
    /* 0xD8 */ int32_t unk_d8; /* field at 0xD8 */
    /* 0xDC */ int32_t unk_dc; /* *(uint32*)(param_1+0x1c)=0xffffffff → 0xDC */
    /* 0xE0 */ int32_t unk_e0; /* ctor: *(uint32*)(param_1+0x1c)=-1 → 0xE0 */
    /* 0xE4 */ int32_t unk_e4; /* ctor sets 1 */
    /* 0xE8 */ int32_t unk_e8; /* *(uint32*)(param_1+0x1d)=-1 → 0xE8 */
    /* 0xEC */ uint8_t unk_ec; /* ctor sets 0; SetAnm writes 0 here */
    /* 0xED */ uint8_t pad_ed[3]; /* align */
    /* 0xF0 */ float unk_f0; /* Elapse uses *(float*)(param_1+0xf0) as multiplier */
    /* 0xF4 */ uint8_t pad_f4[4]; /* pad to 0xF8 */
} nuccAnmMiddle;

static_assert(offsetof(nuccAnmMiddle, base) == 0x00, "nuccAnmMiddle.base");
static_assert(offsetof(nuccAnmMiddle, unk_b0) == 0xB0, "nuccAnmMiddle.unk_b0");
static_assert(offsetof(nuccAnmMiddle, unk_b8) == 0xB8, "nuccAnmMiddle.unk_b8");
static_assert(offsetof(nuccAnmMiddle, unk_c0) == 0xC0, "nuccAnmMiddle.unk_c0");
static_assert(offsetof(nuccAnmMiddle, unk_c8) == 0xC8, "nuccAnmMiddle.unk_c8");
static_assert(offsetof(nuccAnmMiddle, unk_cc) == 0xCC, "nuccAnmMiddle.unk_cc");
static_assert(offsetof(nuccAnmMiddle, unk_d0) == 0xD0, "nuccAnmMiddle.unk_d0");
static_assert(offsetof(nuccAnmMiddle, unk_d8) == 0xD8, "nuccAnmMiddle.unk_d8");
static_assert(offsetof(nuccAnmMiddle, unk_dc) == 0xDC, "nuccAnmMiddle.unk_dc");
static_assert(offsetof(nuccAnmMiddle, unk_e0) == 0xE0, "nuccAnmMiddle.unk_e0");
static_assert(offsetof(nuccAnmMiddle, unk_e4) == 0xE4, "nuccAnmMiddle.unk_e4");
static_assert(offsetof(nuccAnmMiddle, unk_e8) == 0xE8, "nuccAnmMiddle.unk_e8");
static_assert(offsetof(nuccAnmMiddle, unk_ec) == 0xEC, "nuccAnmMiddle.unk_ec");
static_assert(offsetof(nuccAnmMiddle, unk_f0) == 0xF0, "nuccAnmMiddle.unk_f0");
static_assert(sizeof(nuccAnmMiddle) == 0xF8, "nuccAnmMiddle size");

/*
 * nuccAnm — full class (offsets 0xF8–0x1B7)
 * Vtable: PTR_FUN_140891468
 * Size: 0x1B8 (440 bytes) from FUN_140580190(0x1b8,...) in FUN_1401ed020
 * Constructor at RVA 0x5A07C0 (also 0x5A0560, 0x5A0670 variants)
 */
typedef struct nuccAnm {
    struct nuccAnmMiddle middle; /* 0x00–0xF7, sizeof=0xF8 */

    /* 0xF8 */ uint8_t allocator_1[0x18]; /* Nucc::Memory::BlockAllocator; ctor: FUN_140585940(param_1 + 0x1f) */
    /* 0x110 */ uint64_t unk_110; /* ctor sets 0; Clear checks !=0 and frees via this allocator */
    /* 0x118 */ uint32_t unk_118; /* ctor sets 0; Clear resets to 0 after freeing */
    /* 0x11C */ uint8_t pad_11c[4]; /* align */
    /* 0x120 */ uint64_t unk_120; /* Elapse: checked !=0; Clear frees if non-null; state_surface sz=8 rw */
    /* 0x128 */ uint32_t unk_128; /* Elapse: compared with *(uint*)(param_1+300) which is 0x12C */
    /* 0x12C */ uint32_t unk_12c; /* Elapse: incremented by iVar7; compared with unk_128 */
    /* 0x130 */ uint64_t clump; /* ConstructObjectTable: local_58 = param_1[0x26]; iterated as linked list */
    /* 0x138 */ uint64_t unk_138; /* ctor: FUN_140585940(param_1 + 0x27); state_surface sz=8 rw */
    /* 0x140 */ uint8_t pad_140[0x10]; /* gap to 0x150 */
    /* 0x150 */ uint64_t unk_150; /* ConstructObjectTable: lVar14 = param_1[0x2a]; linked list head */
    /* 0x158 */ uint64_t unk_158; /* ctor sets 0; state_surface sz=8 w */
    /* 0x160 */ uint64_t unk_160; /* ConstructObjectTable: param_1[0x2c] = lVar14; current node ptr */
    /* 0x168 */ uint16_t unk_168; /* ConstructObjectTable: uVar2 = *(ushort *)(param_1 + 0x2d); object count */
    /* 0x16A */ uint8_t pad_16a[6]; /* align */
    /* 0x170 */ int32_t prev_timer; /* Elapse: *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x3c); copy of timer */
    /* 0x174 */ uint8_t unk_174; /* ConstructObjectTable: set to 0/1; state_surface sz=1 w */
    /* 0x175 */ uint8_t pad_175[3]; /* align */
    /* 0x178 */ uint64_t unk_178; /* ConstructObjectTable: param_1[0x2f] (longlong*) → 0x178; checked != 0 → iVar22=5; low 32 bits at 0x17C used for material filter */
    /* 0x180 */ uint8_t pad_180[8]; /* gap to 0x188 */
    /* 0x188 */ nuccInstanceList **instance_array; /* Clear iterates from here; state_surface sz=8 w */
    /* 0x190 */ uint64_t instance_array_end; /* Clear: *(param_1+400)=end ptr; 400 = 0x190 in byte offset */
    /* 0x198 */ uint64_t unk_198; /* ctor sets 0; state_surface sz=8 w */
    /* 0x1A0 */ uint8_t allocator_2[0x18]; /* Nucc::Memory::BlockAllocator; ctor: FUN_1405858f0(param_1 + 0x34,uVar1) */
    /* 0x1B8 is the end — object size confirmed */
} nuccAnm;

static_assert(offsetof(nuccAnm, middle) == 0x00, "nuccAnm.middle");
static_assert(offsetof(nuccAnm, allocator_1) == 0xF8, "nuccAnm.allocator_1");
static_assert(offsetof(nuccAnm, unk_110) == 0x110, "nuccAnm.unk_110");
static_assert(offsetof(nuccAnm, unk_118) == 0x118, "nuccAnm.unk_118");
static_assert(offsetof(nuccAnm, unk_120) == 0x120, "nuccAnm.unk_120");
static_assert(offsetof(nuccAnm, unk_128) == 0x128, "nuccAnm.unk_128");
static_assert(offsetof(nuccAnm, unk_12c) == 0x12C, "nuccAnm.unk_12c");
static_assert(offsetof(nuccAnm, clump) == 0x130, "nuccAnm.clump");
static_assert(offsetof(nuccAnm, unk_138) == 0x138, "nuccAnm.unk_138");
static_assert(offsetof(nuccAnm, unk_150) == 0x150, "nuccAnm.unk_150");
static_assert(offsetof(nuccAnm, unk_158) == 0x158, "nuccAnm.unk_158");
static_assert(offsetof(nuccAnm, unk_160) == 0x160, "nuccAnm.unk_160");
static_assert(offsetof(nuccAnm, unk_168) == 0x168, "nuccAnm.unk_168");
static_assert(offsetof(nuccAnm, prev_timer) == 0x170, "nuccAnm.prev_timer");
static_assert(offsetof(nuccAnm, unk_174) == 0x174, "nuccAnm.unk_174");
static_assert(offsetof(nuccAnm, unk_178) == 0x178, "nuccAnm.unk_178");
static_assert(offsetof(nuccAnm, instance_array) == 0x188, "nuccAnm.instance_array");
static_assert(offsetof(nuccAnm, instance_array_end) == 0x190, "nuccAnm.instance_array_end");
static_assert(offsetof(nuccAnm, unk_198) == 0x198, "nuccAnm.unk_198");
static_assert(offsetof(nuccAnm, allocator_2) == 0x1A0, "nuccAnm.allocator_2");
static_assert(sizeof(nuccAnm) == 0x1B8, "nuccAnm total size must be 440 bytes");

#endif /* NUCC_ANM_S2_H */