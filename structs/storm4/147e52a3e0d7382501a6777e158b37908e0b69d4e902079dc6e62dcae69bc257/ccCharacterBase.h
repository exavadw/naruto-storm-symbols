#ifndef CCCHARACTERBASE_S4_H
#define CCCHARACTERBASE_S4_H

#include <stdint.h>
#include <stddef.h>

/* ccCharacterBase (NARUTO STORM 4 PC 1.09 / s4) — INFERRED layout from static analysis.
 * Base class: GameActor::Base (ctor calls GameActor::Base::Base(), region 0x0–0x8F).
 * ccCharacterBase ctor at RVA 0x762440 overrides vtable to PTR_FUN_1410a6220.
 * Size = 0xB00 (confirmed: last field u32 at 0xAFC + 4 = 0xB00; subclass ccPlayer
 * starts own fields at param_1+0x160 = byte 0xB00).
 * Never instantiated directly — abstract base for ccPlayer, ccEventChara, ccBoss*.
 * Packed struct: all fields are uint8_t arrays to guarantee exact byte offsets.
 * Named fields have comments showing intended type and evidence.
 * Cross-build notes: s3 size was >=0x950; s4 is 0xB00 (+0x1B0 growth).
 *
 * Offset derivation: ctor param_1 is undefined8*, so (param_1 + N) = byte N*8.
 * Direct byte casts like (longlong)param_1 + 0xNN are literal byte offsets.
 */
#pragma pack(push, 1)
typedef struct ccCharacterBase {
    /* --- GameActor::Base region (0x0–0x8F) --- */
    uint8_t vtable[8];              /* 0x000 void* vtable ptr — ctor sets PTR_FUN_1410a6220 */
    uint8_t base_field_08[4];       /* 0x008 u32 — set by parent ctor */
    uint8_t pad_000C[4];            /* 0x00C padding */
    uint8_t velocity_linear[8];     /* 0x010 u64 — Velocity::Reset writes here */
    uint8_t velocity_angular[8];    /* 0x018 u64 — Velocity::Reset */
    uint8_t velocity_field_20[8];   /* 0x020 u64 — Velocity::Reset */
    uint8_t velocity_field_28[64];  /* 0x028 u64 — Velocity::Reset region */
    uint8_t base_subobj_68[40];     /* 0x068 sub-object region (GameActor::Base) */

    /* --- ccCharacterBase fields (0x90+) --- */
    /* Vector3 array: 10 x Nucc::Vector3 (12 bytes each) at 0x90..0xFC */
    uint8_t effect_pos_vec[12];     /* 0x090 Nucc::Vector3 — EntryEffectPosVec, ctor init from zero() */
    uint8_t transform_right[12];    /* 0x09C Nucc::Vector3 — ctor copies from xAxis */
    uint8_t transform_up[12];       /* 0x0A8 Nucc::Vector3 — ctor */
    uint8_t transform_fwd[12];      /* 0x0B4 Nucc::Vector3 — ctor copies from zAxis */
    uint8_t position_vec[12];       /* 0x0C0 Nucc::Vector3 — ctor, SetPositionNew */
    uint8_t unk_vec_00CC[12];       /* 0x0CC Nucc::Vector3 — ctor */
    uint8_t unk_vec_00D8[12];       /* 0x0D8 Nucc::Vector3 — ctor */
    uint8_t unk_vec_00E4[12];       /* 0x0E4 Nucc::Vector3 — ctor */
    uint8_t unk_vec_00F0[12];       /* 0x0F0 Nucc::Vector3 — ctor */
    uint8_t unk_vec_00FC[12];       /* 0x0FC Nucc::Vector3 — ctor */

    /* Matrix44 at 0x108 (64 bytes, ends 0x148) */
    uint8_t transform_matrix[64];   /* 0x108 Nucc::Matrix44_MathGeo — ctor SetIdentity */

    /* Velocity vectors: 3 x Nucc::Vector3 at 0x148, 0x174, 0x1A0 */
    uint8_t velocity_vec_148[12];   /* 0x148 Nucc::Vector3 — ctor Velocity::Reset */
    uint8_t pad_0154[32];           /* 0x154 gap before next Vector3 */
    uint8_t velocity_vec_174[12];   /* 0x174 Nucc::Vector3 — ctor */
    uint8_t pad_0180[32];           /* 0x180 gap */
    uint8_t velocity_vec_1A0[12];   /* 0x1A0 Nucc::Vector3 — ctor */
    uint8_t unk_vec_01AC[12];       /* 0x1AC Nucc::Vector3 — ctor */

    /* Two u32 fields before second Matrix44 */
    uint8_t field_01B8[4];          /* 0x1B8 u32 w — ctor *(param_1+0x37)=0 */
    uint8_t field_01BC[4];          /* 0x1BC u32 w — ctor *(longlong param_1+0x1bc)=0 */

    /* Matrix44 at 0x1C0 (64 bytes, ends 0x200) */
    uint8_t matrix_01C0[64];        /* 0x1C0 Nucc::Matrix44_MathGeo — ctor SetIdentity(param_1+0x38) */

    /* Scale factor and draw state */
    uint8_t drawScale[4];           /* 0x200 f32 rw — GetDrawScale/SetDrawScale; ctor sets 0x3f800000 (1.0f) */
    uint8_t pad_0204[4];            /* 0x204 gap to align entry_effect_ptr */
    uint8_t entry_effect_ptr[8];    /* 0x208 u64 rw — IsEnableDraw/GetCoord read as ptr; ctor param_1[0x41]=0 */
    uint8_t field_0210[4];          /* 0x210 u32 w — ctor *(param_1+0x42)=0 */
    uint8_t pad_0214[4];            /* 0x214 gap to align player_pad */

    /* ccPlayerPad sub-object at 0x218 (368 bytes, ends 0x388) — s4 shifted +8 vs s3's 0x210 */
    uint8_t player_pad[368];        /* 0x218 ccPlayerPad — ctor FUN_1407c0294(param_1+0x43), dtor */

    /* Gap region 0x388–0x8D8 */
    uint8_t vfunc_slot_70[8];       /* 0x388 u64 r — GetOpponentWeakPointHandle vcall slot 0x70 */
    uint8_t pad_0390[1352];         /* 0x390 gap to lock target region (0x390 to 0x8D8) */

    /* Lock target / effect flags region */
    uint8_t field_08D8[4];          /* 0x8D8 u32 w — ctor *(param_1+0x11b)=0 */
    uint8_t opponentWeakPointHandle[4]; /* 0x8DC u32 rw — GetOpponentWeakPointHandle reads; ctor *(longlong+0x8dc)=1 */
    uint8_t lockTarget_id[4];       /* 0x8E0 u32 w — ctor *(param_1+0x11c)=0xffffffff */
    uint8_t lockTarget_id_2[4];     /* 0x8E4 u32 w — ctor *(longlong+0x8e4)=0xffffffff */

    /* Vector3 pair array 1: start 0x8E8, 2 iters, stride 0x30 (ends 0x948) */
    uint8_t vec_pair_array_8E8[96]; /* 0x8E8 2x(Vector3+Vector3+Vector3) stride 0x30 — ctor loop1 */

    /* Vector3 pair array 2: start 0x948, 2 iters, stride 0x30 (ends 0x9A8) */
    uint8_t vec_pair_array_948[96]; /* 0x948 2x(Vector3+Vector3+Vector3) stride 0x30 — ctor loop2 */

    /* BlockAllocator array 1: start 0x9A8, 2 iters, stride 0x28 (ends 0x9F8) */
    uint8_t block_alloc_array_9A8[80]; /* 0x9A8 2xBlockAllocator stride 0x28 — ctor */

    /* BlockAllocator array 2: start 0x9F8, 2 iters, stride 0x28 (ends 0xA48) */
    uint8_t block_alloc_array_9F8[80]; /* 0x9F8 2xBlockAllocator stride 0x28 — ctor, dtor */

    /* Final sub-objects */
    uint8_t eyeTbl_flag[8];         /* 0xA48 u64 rw — ctor param_1[0x149]=0; ReleaseEyeTbl/EntryEyeTbl */
    uint8_t faceDirc_flag[8];       /* 0xA50 u64 w — ctor param_1[0x14a]=0; ResetFaceDirc */
    uint8_t matrix_0A58[64];        /* 0xA58 Nucc::Matrix44_MathGeo — ctor SetIdentity(param_1+0x14b) */
    uint8_t vec_0A98[12];           /* 0xA98 Nucc::Vector3 — ctor Vector3(param_1+0x153) */
    uint8_t vec_0AA4[12];           /* 0xAA4 Nucc::Vector3 — ctor Vector3((longlong)param_1+0xaa4) */
    uint8_t matrix_0AB0[64];        /* 0xAB0 Nucc::Matrix44_MathGeo — ctor Matrix44(param_1+0x156) */
    uint8_t field_0AF0[12];         /* 0xAF0 gap/padding to 0xAFC */
    uint8_t field_0AFC[4];          /* 0xAFC u32 w — ctor *(longlong+0xafc)=0; last field */
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
_Static_assert(offsetof(ccCharacterBase, field_01B8) == 0x1B8, "ccCharacterBase.field_01B8");
_Static_assert(offsetof(ccCharacterBase, field_01BC) == 0x1BC, "ccCharacterBase.field_01BC");
_Static_assert(offsetof(ccCharacterBase, matrix_01C0) == 0x1C0, "ccCharacterBase.matrix_01C0");
_Static_assert(offsetof(ccCharacterBase, drawScale) == 0x200, "ccCharacterBase.drawScale");
_Static_assert(offsetof(ccCharacterBase, pad_0204) == 0x204, "ccCharacterBase.pad_0204");
_Static_assert(offsetof(ccCharacterBase, entry_effect_ptr) == 0x208, "ccCharacterBase.entry_effect_ptr");
_Static_assert(offsetof(ccCharacterBase, field_0210) == 0x210, "ccCharacterBase.field_0210");
_Static_assert(offsetof(ccCharacterBase, pad_0214) == 0x214, "ccCharacterBase.pad_0214");
_Static_assert(offsetof(ccCharacterBase, player_pad) == 0x218, "ccCharacterBase.player_pad");
_Static_assert(offsetof(ccCharacterBase, vfunc_slot_70) == 0x388, "ccCharacterBase.vfunc_slot_70");
_Static_assert(offsetof(ccCharacterBase, pad_0390) == 0x390, "ccCharacterBase.pad_0390");
_Static_assert(offsetof(ccCharacterBase, field_08D8) == 0x8D8, "ccCharacterBase.field_08D8");
_Static_assert(offsetof(ccCharacterBase, opponentWeakPointHandle) == 0x8DC, "ccCharacterBase.opponentWeakPointHandle");
_Static_assert(offsetof(ccCharacterBase, lockTarget_id) == 0x8E0, "ccCharacterBase.lockTarget_id");
_Static_assert(offsetof(ccCharacterBase, lockTarget_id_2) == 0x8E4, "ccCharacterBase.lockTarget_id_2");
_Static_assert(offsetof(ccCharacterBase, vec_pair_array_8E8) == 0x8E8, "ccCharacterBase.vec_pair_array_8E8");
_Static_assert(offsetof(ccCharacterBase, vec_pair_array_948) == 0x948, "ccCharacterBase.vec_pair_array_948");
_Static_assert(offsetof(ccCharacterBase, block_alloc_array_9A8) == 0x9A8, "ccCharacterBase.block_alloc_array_9A8");
_Static_assert(offsetof(ccCharacterBase, block_alloc_array_9F8) == 0x9F8, "ccCharacterBase.block_alloc_array_9F8");
_Static_assert(offsetof(ccCharacterBase, eyeTbl_flag) == 0xA48, "ccCharacterBase.eyeTbl_flag");
_Static_assert(offsetof(ccCharacterBase, faceDirc_flag) == 0xA50, "ccCharacterBase.faceDirc_flag");
_Static_assert(offsetof(ccCharacterBase, matrix_0A58) == 0xA58, "ccCharacterBase.matrix_0A58");
_Static_assert(offsetof(ccCharacterBase, vec_0A98) == 0xA98, "ccCharacterBase.vec_0A98");
_Static_assert(offsetof(ccCharacterBase, vec_0AA4) == 0xAA4, "ccCharacterBase.vec_0AA4");
_Static_assert(offsetof(ccCharacterBase, matrix_0AB0) == 0xAB0, "ccCharacterBase.matrix_0AB0");
_Static_assert(offsetof(ccCharacterBase, field_0AF0) == 0xAF0, "ccCharacterBase.field_0AF0");
_Static_assert(offsetof(ccCharacterBase, field_0AFC) == 0xAFC, "ccCharacterBase.field_0AFC");
_Static_assert(sizeof(ccCharacterBase) == 0xB00, "ccCharacterBase size");

#endif /* CCCHARACTERBASE_S4_H */