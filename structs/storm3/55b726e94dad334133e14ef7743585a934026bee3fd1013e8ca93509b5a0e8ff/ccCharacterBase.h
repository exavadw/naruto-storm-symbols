#ifndef CCCHARACTERBASE_S3_H
#define CCCHARACTERBASE_S3_H

#include <stdint.h>
#include <stddef.h>

/* ccCharacterBase (NARUTO STORM 3 Full Burst HD / s3) — INFERRED layout from static analysis.
 * Base class: GameActor::Base (ctor sets vtable, region 0x0–0x8F).
 * ccCharacterBase ctor at RVA 0x4F4EA4 overrides vtable to PTR_FUN_140989cb0.
 * Size unknown; last proven field ends at 0x950 (0x910 + Matrix44_MathGeo 64 bytes).
 * Never instantiated directly — abstract base for ccPlayer, ccEventChara, ccBoss*.
 * Packed struct: all fields are uint8_t arrays to guarantee exact byte offsets.
 * Named fields have comments showing intended type and evidence.
 * Cross-build notes: s2 offsets differ significantly; see ccCharacterBase-REPORT.md.
 */
#pragma pack(push, 1)
typedef struct ccCharacterBase {
    /* --- GameActor::Base region (0x0–0x8F) --- */
    uint8_t vtable[8];              /* 0x0000 void* vtable ptr */
    uint8_t base_field_08[4];       /* 0x0008 u32 — set by parent ctor */
    uint8_t pad_000C[4];            /* 0x000C */
    uint8_t velocity_linear[8];     /* 0x0010 u64 — Velocity::Reset writes 0xC,0x14,0x1C,0x24 */
    uint8_t velocity_angular[8];    /* 0x0018 u64 — Velocity::Reset */
    uint8_t velocity_field_20[8];   /* 0x0020 u64 — Velocity::Reset writes 0x1C */
    uint8_t velocity_field_28[64];  /* 0x0028 u64 — Velocity::Reset writes 0x24 */
    uint8_t base_subobj_68[40];     /* 0x0068 sub-object region */

    /* --- ccCharacterBase fields (0x90+) --- */
    /* Vector3 array: 10 x Nucc::Vector3 (12 bytes each) at 0x90..0xFC */
    uint8_t effect_pos_vec[12];     /* 0x0090 Nucc::Vector3 — EntryEffectPosVec, ctor init */
    uint8_t transform_right[12];    /* 0x009C Nucc::Vector3 — ctor copies from xAxis */
    uint8_t transform_up[12];       /* 0x00A8 Nucc::Vector3 — ctor */
    uint8_t transform_fwd[12];      /* 0x00B4 Nucc::Vector3 — ctor copies from zAxis */
    uint8_t position_vec[12];       /* 0x00C0 Nucc::Vector3 — ctor, SetPositionNew */
    uint8_t unk_vec_00CC[12];       /* 0x00CC Nucc::Vector3 — ctor */
    uint8_t unk_vec_00D8[12];       /* 0x00D8 Nucc::Vector3 — ctor */
    uint8_t unk_vec_00E4[12];       /* 0x00E4 Nucc::Vector3 — ctor */
    uint8_t unk_vec_00F0[12];       /* 0x00F0 Nucc::Vector3 — ctor */
    uint8_t unk_vec_00FC[12];       /* 0x00FC Nucc::Vector3 — ctor */

    /* Matrix44 at 0x108 (64 bytes) */
    uint8_t transform_matrix[64];   /* 0x0108 Nucc::Matrix44_MathGeo — ctor FUN_1406856b0 */

    /* Velocity vectors: 3 x Nucc::Vector3 at 0x148, 0x174, 0x1A0 */
    uint8_t velocity_vec_148[12];   /* 0x0148 Nucc::Vector3 — ctor */
    uint8_t pad_0154[32];           /* 0x0154 gap before next Vector3 */
    uint8_t velocity_vec_174[12];   /* 0x0174 Nucc::Vector3 — ctor */
    uint8_t pad_0180[32];           /* 0x0180 gap */
    uint8_t velocity_vec_1A0[12];   /* 0x01A0 Nucc::Vector3 — ctor */
    uint8_t unk_vec_01AC[12];       /* 0x01AC Nucc::Vector3 — ctor */
    uint8_t pad_01B8[4];            /* 0x01B8 gap to align matrix */

    /* Matrix44 at 0x1BC (64 bytes) */
    uint8_t matrix_01BC[64];        /* 0x01BC Nucc::Matrix44_MathGeo — ctor FUN_1406856b0 */

    /* Scale factors */
    uint8_t scale_factor[4];        /* 0x01FC f32 w — ctor sets 0x3f800000 (1.0f) */
    uint8_t pad_0200[8];            /* 0x0200 */
    uint8_t entry_effect_ptr[8];    /* 0x0208 u64 rw — EntryEffect/EntryEffectMatrix */

    /* ccPlayerPad sub-object at 0x210 (368 bytes) */
    uint8_t player_pad[368];        /* 0x0210 ccPlayerPad — ctor FUN_140548cd0, dtor */

    /* Gap region 0x380–0x738 */
    uint8_t vfunc_slot_70[8];       /* 0x0380 u64 r — GetOpponentWeakPointHandle vcall slot 0x70 */
    uint8_t pad_0388[944];          /* 0x0388 gap to lock target region */

    /* Lock target IDs — initialized to 0xffffffff in ctor */
    uint8_t lockTarget_id[4];       /* 0x0738 u32 w — ctor 0xffffffff, high conf */
    uint8_t lockTarget_id_2[4];     /* 0x073C u32 w — ctor 0xffffffff */
    uint8_t lockTarget_id_3[4];     /* 0x0740 u32 w — ctor 0xffffffff */

    /* Vector3 pair arrays at 0x744 and 0x7A4 (2 iterations each, stride 0x30) */
    uint8_t vec_pair_array_744[96]; /* 0x0744 2x(Vector3+Vector3) stride 0x30 — ctor loop */
    uint8_t vec_pair_array_7A4[96]; /* 0x07A4 2x(Vector3+Vector3) stride 0x30 — ctor memcpy */
    uint8_t pad_0804[4];            /* 0x0804 gap to align block allocators */

    /* BlockAllocator arrays at 0x808 and 0x858 (2 iterations each, stride 0x28) */
    uint8_t block_alloc_array_808[80]; /* 0x0808 2xBlockAllocator stride 0x28 — ctor */
    uint8_t block_alloc_array_858[80]; /* 0x0858 2xBlockAllocator stride 0x28 — ctor, dtor */

    /* Final sub-objects */
    uint8_t field_08A8[8];          /* 0x08A8 u64 rw — ctor/dtor zeroed */
    uint8_t field_08B0[8];          /* 0x08B0 u64 w — ctor zeroed */
    uint8_t matrix_08B8[64];        /* 0x08B8 Nucc::Matrix44_MathGeo — ctor FUN_1406856b0 */
    uint8_t vec_08F8[12];           /* 0x08F8 Nucc::Vector3 — ctor FUN_140684430 */
    uint8_t vec_0904[12];           /* 0x0904 Nucc::Vector3 — ctor FUN_140684430 */
    uint8_t matrix_0910[64];        /* 0x0910 Nucc::Matrix44_MathGeo — ctor FUN_1406856b0 */
    /* ... size unknown, >= 0x950 (0x910 + 64) ... */
} ccCharacterBase;
#pragma pack(pop)

/* Offset assertions — every field must land at its game offset */
_Static_assert(offsetof(ccCharacterBase, vtable) == 0x0, "ccCharacterBase.vtable");
_Static_assert(offsetof(ccCharacterBase, base_field_08) == 0x8, "ccCharacterBase.base_field_08");
_Static_assert(offsetof(ccCharacterBase, pad_000C) == 0xC, "ccCharacterBase.pad_000C");
_Static_assert(offsetof(ccCharacterBase, velocity_linear) == 0x10, "ccCharacterBase.velocity_linear");
_Static_assert(offsetof(ccCharacterBase, velocity_angular) == 0x18, "ccCharacterBase.velocity_angular");
_Static_assert(offsetof(ccCharacterBase, velocity_field_20) == 0x20, "ccCharacterBase.velocity_field_20");
_Static_assert(offsetof(ccCharacterBase, velocity_field_28) == 0x28, "ccCharacterBase.velocity_field_28");
_Static_assert(offsetof(ccCharacterBase, base_subobj_68) == 0x68, "ccCharacterBase.base_subobj_68");
_Static_assert(offsetof(ccCharacterBase, effect_pos_vec) == 0x90, "ccCharacterBase.effect_pos_vec");
_Static_assert(offsetof(ccCharacterBase, transform_right) == 0x9C, "ccCharacterBase.transform_right");
_Static_assert(offsetof(ccCharacterBase, transform_up) == 0xA8, "ccCharacterBase.transform_up");
_Static_assert(offsetof(ccCharacterBase, transform_fwd) == 0xB4, "ccCharacterBase.transform_fwd");
_Static_assert(offsetof(ccCharacterBase, position_vec) == 0xC0, "ccCharacterBase.position_vec");
_Static_assert(offsetof(ccCharacterBase, unk_vec_00CC) == 0xCC, "ccCharacterBase.unk_vec_00CC");
_Static_assert(offsetof(ccCharacterBase, unk_vec_00D8) == 0xD8, "ccCharacterBase.unk_vec_00D8");
_Static_assert(offsetof(ccCharacterBase, unk_vec_00E4) == 0xE4, "ccCharacterBase.unk_vec_00E4");
_Static_assert(offsetof(ccCharacterBase, unk_vec_00F0) == 0xF0, "ccCharacterBase.unk_vec_00F0");
_Static_assert(offsetof(ccCharacterBase, unk_vec_00FC) == 0xFC, "ccCharacterBase.unk_vec_00FC");
_Static_assert(offsetof(ccCharacterBase, transform_matrix) == 0x108, "ccCharacterBase.transform_matrix");
_Static_assert(offsetof(ccCharacterBase, velocity_vec_148) == 0x148, "ccCharacterBase.velocity_vec_148");
_Static_assert(offsetof(ccCharacterBase, pad_0154) == 0x154, "ccCharacterBase.pad_0154");
_Static_assert(offsetof(ccCharacterBase, velocity_vec_174) == 0x174, "ccCharacterBase.velocity_vec_174");
_Static_assert(offsetof(ccCharacterBase, pad_0180) == 0x180, "ccCharacterBase.pad_0180");
_Static_assert(offsetof(ccCharacterBase, velocity_vec_1A0) == 0x1A0, "ccCharacterBase.velocity_vec_1A0");
_Static_assert(offsetof(ccCharacterBase, unk_vec_01AC) == 0x1AC, "ccCharacterBase.unk_vec_01AC");
_Static_assert(offsetof(ccCharacterBase, pad_01B8) == 0x1B8, "ccCharacterBase.pad_01B8");
_Static_assert(offsetof(ccCharacterBase, matrix_01BC) == 0x1BC, "ccCharacterBase.matrix_01BC");
_Static_assert(offsetof(ccCharacterBase, scale_factor) == 0x1FC, "ccCharacterBase.scale_factor");
_Static_assert(offsetof(ccCharacterBase, pad_0200) == 0x200, "ccCharacterBase.pad_0200");
_Static_assert(offsetof(ccCharacterBase, entry_effect_ptr) == 0x208, "ccCharacterBase.entry_effect_ptr");
_Static_assert(offsetof(ccCharacterBase, player_pad) == 0x210, "ccCharacterBase.player_pad");
_Static_assert(offsetof(ccCharacterBase, vfunc_slot_70) == 0x380, "ccCharacterBase.vfunc_slot_70");
_Static_assert(offsetof(ccCharacterBase, pad_0388) == 0x388, "ccCharacterBase.pad_0388");
_Static_assert(offsetof(ccCharacterBase, lockTarget_id) == 0x738, "ccCharacterBase.lockTarget_id");
_Static_assert(offsetof(ccCharacterBase, lockTarget_id_2) == 0x73C, "ccCharacterBase.lockTarget_id_2");
_Static_assert(offsetof(ccCharacterBase, lockTarget_id_3) == 0x740, "ccCharacterBase.lockTarget_id_3");
_Static_assert(offsetof(ccCharacterBase, vec_pair_array_744) == 0x744, "ccCharacterBase.vec_pair_array_744");
_Static_assert(offsetof(ccCharacterBase, vec_pair_array_7A4) == 0x7A4, "ccCharacterBase.vec_pair_array_7A4");
_Static_assert(offsetof(ccCharacterBase, pad_0804) == 0x804, "ccCharacterBase.pad_0804");
_Static_assert(offsetof(ccCharacterBase, block_alloc_array_808) == 0x808, "ccCharacterBase.block_alloc_array_808");
_Static_assert(offsetof(ccCharacterBase, block_alloc_array_858) == 0x858, "ccCharacterBase.block_alloc_array_858");
_Static_assert(offsetof(ccCharacterBase, field_08A8) == 0x8A8, "ccCharacterBase.field_08A8");
_Static_assert(offsetof(ccCharacterBase, field_08B0) == 0x8B0, "ccCharacterBase.field_08B0");
_Static_assert(offsetof(ccCharacterBase, matrix_08B8) == 0x8B8, "ccCharacterBase.matrix_08B8");
_Static_assert(offsetof(ccCharacterBase, vec_08F8) == 0x8F8, "ccCharacterBase.vec_08F8");
_Static_assert(offsetof(ccCharacterBase, vec_0904) == 0x904, "ccCharacterBase.vec_0904");
_Static_assert(offsetof(ccCharacterBase, matrix_0910) == 0x910, "ccCharacterBase.matrix_0910");

#endif /* CCCHARACTERBASE_S3_H */