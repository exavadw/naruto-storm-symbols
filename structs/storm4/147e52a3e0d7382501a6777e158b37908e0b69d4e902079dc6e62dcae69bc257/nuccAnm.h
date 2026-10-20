/*
 * nuccAnm — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4, sha 147e52a3e0d7)
 * Reconstructed from Ghidra decompilation cache via the decompiler cache.
 * All fields INFERRED from static analysis; not runtime-confirmed.
 *
 * Inheritance: nuccAnm -> nuccAnmMiddle -> nuccAnmBase (same as s1/s2/s3)
 * Object size: 0x1C0 (448 bytes) — confirmed by operator new callers passing 0x1c0
 *   to FUN_140a017f0 (e.g. FUN_140236f5c, FUN_14041b030, FUN_140233be8).
 *   This is 8 bytes larger than s3's 0x1B8; the new field unk_1b8 at offset 0x1B8
 *   accounts for 4 bytes, with 4 bytes trailing padding.
 * Vtable: PTR_FUN_141105490 (nuccAnm ctor sets *param_1 = &PTR_FUN_141105490)
 */

#ifndef NUCC_ANM_S4_H
#define NUCC_ANM_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for types not yet reconstructed */
typedef struct nuccInstanceList nuccInstanceList;

/*
 * Nucc::Matrix44_MathGeo — 4x4 matrix (64 bytes = 16 floats).
 * Constructor calls SetIdentity; used at nuccAnmBase+0x50.
 * Carried from s1/s2/s3 layout.
 */
struct Nucc_Matrix44_MathGeo {
    float m[4][4];
};

/*
 * nuccAnmBase — base class (offsets 0x00–0x97)
 * Vtable: set by base ctor chain
 * sizeof = 0x98 (same as s1/s2/s3; same field pattern observed in s4 Elapse)
 */
typedef struct nuccAnmBase {
    /* 0x00 */ void *vtable;                          /* PTR_FUN_141105490 set by ctor */
    /* 0x08 */ uint8_t pad_08[0x10];                  /* BlockAllocator or other base fields */
    /* 0x18 */ uint64_t unk_18;                        /* initialized to 0 in ctor */
    /* 0x20 */ uint64_t unk_20;                        /* param_1[4]=0 → 0x20 */
    /* 0x28 */ uint64_t coord_ptr;                     /* param_1[5] → 0x28; read by Elapse loop */
    /* 0x30 */ uint64_t anim_controller;               /* ConstructAnimationController writes here */
    /* 0x38 */ uint8_t pad_38[0x04];                   /* gap between anim_controller end and timer */
    /* 0x3C */ int32_t timer;                          /* Elapse reads/writes *(int*)(param_1+0x3c) */
    /* 0x40 */ uint8_t pad_40[0x04];                   /* align */
    /* 0x44 */ int32_t unk_44;                         /* state_surface: sz=4 r; checked in ConstructObjectTable */
    /* 0x48 */ float speed_scale;                      /* Elapse: *(float*)(param_1+0x48); ctor sets 1.0f */
    /* 0x4C */ float unk_4c;                           /* ctor sets 0x3f800000 = 1.0f */
    /* 0x50 */ struct Nucc_Matrix44_MathGeo transform; /* Matrix44, 64 bytes */
    /* 0x90 */ nuccInstanceList *instance_list;        /* param_1[0x12] → 0x90; passed to FUN_140a74b50 */
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
 * Fields derived from s4 constructor pattern (same offsets as s1/s2/s3)
 * sizeof = 0xF8
 */
typedef struct nuccAnmMiddle {
    struct nuccAnmBase base;          /* 0x00–0x97, sizeof=0x98 */
    /* 0x98 */ uint8_t pad_98[0x18];  /* gap to 0xB0 */
    /* 0xB0 */ uint64_t unk_b0;       /* param_1[0x16]=0 → 0xB0 */
    /* 0xB8 */ uint64_t unk_b8;       /* *(uint32*)(param_1+0x17)=0 → 0xB8 */
    /* 0xC0 */ uint64_t unk_c0;       /* beginAnm caller reads param_1[5]+0xc0 */
    /* 0xC8 */ uint32_t unk_c8;       /* param_1[0x19]=0xffffffff → 0xC8 */
    /* 0xCC */ int32_t unk_cc;        /* ctor sets 1 */
    /* 0xD0 */ uint32_t unk_d0;       /* param_1[0x1a] → 0xD0 */
    /* 0xD4 */ uint8_t pad_d4[0x04];  /* align to 0xD8 */
    /* 0xD8 */ int32_t unk_d8;        /* field at 0xD8 */
    /* 0xDC */ int32_t unk_dc;        /* *(uint32*)(param_1+0x1c)=0xffffffff → 0xDC */
    /* 0xE0 */ int32_t unk_e0;        /* ctor: *(uint32*)(param_1+0x1c)=-1 → 0xE0 */
    /* 0xE4 */ int32_t unk_e4;        /* ctor sets 1 */
    /* 0xE8 */ int32_t unk_e8;        /* *(uint32*)(param_1+0x1d)=-1 → 0xE8 */
    /* 0xEC */ uint8_t unk_ec;        /* ctor sets 0; SetAnm writes 0 here */
    /* 0xED */ uint8_t pad_ed[3];     /* align */
    /* 0xF0 */ float unk_f0;          /* Elapse uses *(float*)(param_1+0xf0) as multiplier */
    /* 0xF4 */ uint8_t pad_f4[4];     /* pad to 0xF8 */
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
 * nuccAnm — full class (offsets 0xF8–0x1BF)
 * Vtable: PTR_FUN_141105490
 * Size: 0x1C0 (448 bytes) — confirmed by operator new(0x1c0) in callers
 *   FUN_140236f5c, FUN_14041b030, FUN_140233be8 (all pass 0x1c0 to FUN_140a017f0).
 *   8 bytes larger than s3 (0x1B8); new field unk_1b8 at 0x1B8 + 4 bytes padding.
 * Constructors at RVA 0xA14850, 0xA14960, 0xA14AB0
 */
typedef struct nuccAnm {
    struct nuccAnmMiddle middle;              /* 0x00–0xF7, sizeof=0xF8 */

    /* 0xF8 */ uint8_t allocator_1[0x18];     /* Nucc::Memory::BlockAllocator; ctor: FUN_140a01d10(param_1 + 0x1f) */
    /* 0x110 */ uint64_t unk_110;             /* ctor sets 0; Clear checks !=0 and frees via this allocator */
    /* 0x118 */ uint32_t unk_118;             /* ctor sets 0; Clear resets to 0 after freeing */
    /* 0x11C */ uint8_t pad_11c[4];           /* align */
    /* 0x120 */ uint64_t unk_120;             /* Elapse: checked !=0; Clear frees if non-null; state_surface sz=8 rw */
    /* 0x128 */ uint32_t unk_128;             /* Elapse: compared with *(uint*)(param_1+300) which is 0x12C */
    /* 0x12C */ uint32_t unk_12c;             /* Elapse: incremented by iVar7; compared with unk_128 */
    /* 0x130 */ uint64_t clump;               /* ConstructObjectTable: local_58 = param_1[0x26]; iterated as linked list */
    /* 0x138 */ uint64_t unk_138;             /* ctor: FUN_140a01d10(param_1 + 0x27); state_surface sz=8 rw */
    /* 0x140 */ uint8_t pad_140[0x10];        /* gap to 0x150 */
    /* 0x150 */ uint64_t unk_150;             /* ConstructObjectTable: lVar14 = param_1[0x2a]; linked list head */
    /* 0x158 */ uint64_t unk_158;             /* ctor sets 0; state_surface sz=8 w */
    /* 0x160 */ uint64_t unk_160;             /* ConstructObjectTable: param_1[0x2c] = lVar14; current node ptr */
    /* 0x168 */ uint16_t unk_168;             /* ConstructObjectTable: uVar2 = *(ushort*)(param_1 + 0x2d); object count */
    /* 0x16A */ uint8_t pad_16a[6];           /* align */
    /* 0x170 */ int32_t prev_timer;           /* Elapse: *(int*)(param_1 + 0x170) = *(int*)(param_1 + 0x3c); copy of timer */
    /* 0x174 */ uint8_t unk_174;              /* ConstructObjectTable: set to 0/1; state_surface sz=1 w */
    /* 0x175 */ uint8_t pad_175[3];           /* align */
    /* 0x178 */ uint64_t unk_178;             /* ConstructObjectTable: param_1[0x2f] → 0x178; checked !=0 → iVar22=5; low 32 bits at 0x17C for material filter */
    /* 0x180 */ uint8_t pad_180[8];           /* gap to 0x188 */
    /* 0x188 */ nuccInstanceList **instance_array; /* Clear iterates from here; state_surface sz=8 w */
    /* 0x190 */ uint64_t instance_array_end;  /* Clear: *(param_1+400)=end ptr; 400 decimal = 0x190 */
    /* 0x198 */ uint64_t unk_198;             /* ctor sets 0; state_surface sz=8 w */
    /* 0x1A0 */ uint8_t allocator_2[0x18];    /* Nucc::Memory::BlockAllocator; ctor: FUN_140a01cc0(param_1 + 0x34,uVar1) */
    /* 0x1B8 */ int32_t unk_1b8;              /* NEW in s4: SetAnm clears to 0; MakeInterpCtrlTrack checks !=0 */
    /* 0x1BC */ uint8_t pad_1bc[4];           /* trailing padding to reach 0x1C0 */
    /* 0x1C0 is the end — object size 448 bytes */
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
static_assert(offsetof(nuccAnm, unk_1b8) == 0x1B8, "nuccAnm.unk_1b8");
static_assert(sizeof(nuccAnm) == 0x1C0, "nuccAnm total size must be 448 bytes");

#endif /* NUCC_ANM_S4_H */