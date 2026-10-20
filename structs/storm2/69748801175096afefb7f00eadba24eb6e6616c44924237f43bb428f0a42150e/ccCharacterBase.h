#ifndef CCCHARACTERBASE_S2_H
#define CCCHARACTERBASE_S2_H

#include <stdint.h>
#include <stddef.h>

/* ccCharacterBase (NARUTO STORM 2 / s2) — INFERRED layout from static analysis.
 * Base class: GameActor::Base (FUN_140641e60 ctor, vtable PTR_FUN_14089de48 then PTR_FUN_14089e268).
 * ccCharacterBase ctor at RVA 0x304008 overrides vtable to PTR_FUN_1407ed4f8.
 * Size unknown; last proven field ends at 0x820. Never instantiated directly.
 * Packed struct: all fields are uint8_t arrays to guarantee exact byte offsets.
 * Named fields have comments showing intended type and evidence.
 * Cross-build notes: s1 offsets differ significantly; see ccCharacterBase-REPORT.md.
 */
#pragma pack(push, 1)
typedef struct ccCharacterBase {
    /* --- GameActor::Base region (0x0–0x8F) --- */
    uint8_t vtable[8];              /* 0x0000 void* vtable ptr */
    uint8_t base_field_08[4];       /* 0x0008 u32 — set by parent ctor */
    uint8_t pad_000C[4];            /* 0x000C */
    uint8_t base_subobj_10[64];     /* 0x0010 sub-object initialized by FUN_140643120 at +0x9 */
    uint8_t base_subobj_50[16];     /* 0x0050 sub-object initialized by FUN_140580a40 at +0xe */
    uint8_t pad_0060[28];           /* 0x0060 */
    uint8_t base_field_7C[8];       /* 0x007C u64 — zeroed by parent ctor */
    uint8_t base_field_84[4];       /* 0x0084 u32 — zeroed by parent ctor */
    uint8_t base_field_88[8];       /* 0x0088 u64 — param_1[0x11] = 0 in parent ctor */

    /* --- ccCharacterBase fields (0x90+) --- */
    uint8_t unk_0090[4];            /* 0x0090 u32 w — ctor */
    uint8_t pad_0094[4];            /* 0x0094 */
    uint8_t unk_0098[8];            /* 0x0098 u64 r — ctor (read after sub-ctor) */
    uint8_t unk_00A0[4];            /* 0x00A0 u32 rw — ctor */
    uint8_t unk_00A4[8];            /* 0x00A4 u64 rw — ctor, FUN_140580a40 init */
    uint8_t unk_00AC[4];            /* 0x00AC u32 w — ctor */
    uint8_t unk_00B0[8];            /* 0x00B0 u64 rw — ctor, FUN_140580a40 at +0x16 */
    uint8_t unk_00B8[4];            /* 0x00B8 u32 rw — ctor */
    uint8_t unk_00BC[8];            /* 0x00BC u64 rw — ctor, FUN_140580a40 */
    uint8_t unk_00C4[4];            /* 0x00C4 u32 rw — ctor */
    uint8_t unk_00C8[8];            /* 0x00C8 u64 rw — ctor */
    uint8_t unk_00D0[4];            /* 0x00D0 u32 rw — ctor */
    uint8_t unk_00D4[8];            /* 0x00D4 u64 rw — ctor, FUN_140580a40 */
    uint8_t unk_00DC[8];            /* 0x00DC u64 w — ctor */
    uint8_t unk_00E4[8];            /* 0x00E4 u64 w — ctor */
    uint8_t unk_00EC[8];            /* 0x00EC u64 rw — ctor, FUN_140580a40 */
    uint8_t unk_00F4[4];            /* 0x00F4 u32 w — ctor */
    uint8_t unk_00F8[4];            /* 0x00F8 u32 rw — ctor */
    uint8_t unk_00FC[4];            /* 0x00FC u32 w — ctor */
    uint8_t unk_0100[4];            /* 0x0100 u32 w — ctor */
    uint8_t unk_0104[8];            /* 0x0104 u64 rw — ctor, FUN_140580a40 */
    uint8_t unk_010C[4];            /* 0x010C u32 w — ctor */
    uint8_t pad_0110[16];           /* 0x0110 */
    uint8_t unk_0120[8];            /* 0x0120 u64 — param_1[0x22], FUN_140586500 init */
    uint8_t pad_0128[40];           /* 0x0128 */
    uint8_t unk_0150[8];            /* 0x0150 u64 r — ctor */
    uint8_t unk_0158[8];            /* 0x0158 u64 r — ctor */
    uint8_t unk_0160[8];            /* 0x0160 u64 r — ctor */
    uint8_t unk_0168[8];            /* 0x0168 u64 r — ctor */
    uint8_t unk_0170[8];            /* 0x0170 u64 r — ctor */
    uint8_t unk_0178[8];            /* 0x0178 u64 r — ctor */
    uint8_t unk_0180[8];            /* 0x0180 u64 rw — ctor */
    uint8_t unk_0188[8];            /* 0x0188 u64 w — ctor */
    uint8_t unk_0190[8];            /* 0x0190 u64 w — ctor */
    uint8_t unk_0198[8];            /* 0x0198 u64 w — ctor */
    uint8_t unk_01A0[8];            /* 0x01A0 u64 w — ctor */
    uint8_t unk_01A8[8];            /* 0x01A8 u64 w — ctor */
    uint8_t unk_01B0[8];            /* 0x01B0 u64 rw — ctor */
    uint8_t unk_01B8[4];            /* 0x01B8 u32 w — ctor */
    uint8_t unk_01BC[8];            /* 0x01BC u64 rw — ctor, FUN_140580a40 */
    uint8_t unk_01C4[4];            /* 0x01C4 u32 w — ctor */
    uint8_t unk_01C8[8];            /* 0x01C8 u64 w — ctor, high conf */
    uint8_t pad_01D0[64];           /* 0x01D0 */
    uint8_t unk_0210[4];            /* 0x0210 u32 w — ctor */
    uint8_t pad_0214[4];            /* 0x0214 */
    uint8_t effAtT0_ptr[8];         /* 0x0218 u64 rw — EntryEffAtT0/EntryEffByCoord, high conf */
    uint8_t pad_0220[4];            /* 0x0220 */
    uint8_t scale_factor[4];        /* 0x0224 f32 w — ctor sets 0x3f800000 (1.0f) */
    uint8_t unk_0228[8];            /* 0x0228 u64 rw — ctor, dtor */
    uint8_t pad_0230[176];          /* 0x0230 */
    uint8_t unk_02E0[8];            /* 0x02E0 — array region start (param_1+0xc1 loop) */
    uint8_t pad_02E8[796];          /* 0x02E8 */
    uint8_t lockTarget_id[4];       /* 0x0604 u32 w — LockTarget/ctor, 0xffffffff init, high conf */
    uint8_t pad_0608[140];          /* 0x0608 */
    uint8_t unk_0694[4];            /* 0x0694 u32 — array element (memset loop in ctor) */
    uint8_t pad_0698[128];          /* 0x0698 */
    uint8_t unk_0718[8];            /* 0x0718 u64 r — ctor, dtor */
    uint8_t pad_0720[72];           /* 0x0720 */
    uint8_t unk_0768[8];            /* 0x0768 u64 rw — ctor, dtor */
    uint8_t unk_0770[8];            /* 0x0770 u64 w — ctor */
    uint8_t pad_0778[64];           /* 0x0778 */
    uint8_t unk_07B8[8];            /* 0x07B8 u64 r — ctor */
    uint8_t pad_07C0[4];            /* 0x07C0 */
    uint8_t unk_07C4[8];            /* 0x07C4 u64 r — ctor, FUN_140580a40 */
    uint8_t pad_07CC[4];            /* 0x07CC */
    uint8_t unk_07D0[8];            /* 0x07D0 u64 r — ctor */
    uint8_t pad_07D8[68];           /* 0x07D8 */
    uint8_t unk_081C[4];            /* 0x081C u32 w — ctor, zeroed */
    /* ... size unknown, >= 0x820 ... */
} ccCharacterBase;
#pragma pack(pop)

/* Offset assertions — every field must land at its game offset */
_Static_assert(offsetof(ccCharacterBase, vtable) == 0x0, "ccCharacterBase.vtable");
_Static_assert(offsetof(ccCharacterBase, base_field_08) == 0x8, "ccCharacterBase.base_field_08");
_Static_assert(offsetof(ccCharacterBase, pad_000C) == 0xC, "ccCharacterBase.pad_000C");
_Static_assert(offsetof(ccCharacterBase, base_subobj_10) == 0x10, "ccCharacterBase.base_subobj_10");
_Static_assert(offsetof(ccCharacterBase, base_subobj_50) == 0x50, "ccCharacterBase.base_subobj_50");
_Static_assert(offsetof(ccCharacterBase, pad_0060) == 0x60, "ccCharacterBase.pad_0060");
_Static_assert(offsetof(ccCharacterBase, base_field_7C) == 0x7C, "ccCharacterBase.base_field_7C");
_Static_assert(offsetof(ccCharacterBase, base_field_84) == 0x84, "ccCharacterBase.base_field_84");
_Static_assert(offsetof(ccCharacterBase, base_field_88) == 0x88, "ccCharacterBase.base_field_88");
_Static_assert(offsetof(ccCharacterBase, unk_0090) == 0x90, "ccCharacterBase.unk_0090");
_Static_assert(offsetof(ccCharacterBase, pad_0094) == 0x94, "ccCharacterBase.pad_0094");
_Static_assert(offsetof(ccCharacterBase, unk_0098) == 0x98, "ccCharacterBase.unk_0098");
_Static_assert(offsetof(ccCharacterBase, unk_00A0) == 0xA0, "ccCharacterBase.unk_00A0");
_Static_assert(offsetof(ccCharacterBase, unk_00A4) == 0xA4, "ccCharacterBase.unk_00A4");
_Static_assert(offsetof(ccCharacterBase, unk_00AC) == 0xAC, "ccCharacterBase.unk_00AC");
_Static_assert(offsetof(ccCharacterBase, unk_00B0) == 0xB0, "ccCharacterBase.unk_00B0");
_Static_assert(offsetof(ccCharacterBase, unk_00B8) == 0xB8, "ccCharacterBase.unk_00B8");
_Static_assert(offsetof(ccCharacterBase, unk_00BC) == 0xBC, "ccCharacterBase.unk_00BC");
_Static_assert(offsetof(ccCharacterBase, unk_00C4) == 0xC4, "ccCharacterBase.unk_00C4");
_Static_assert(offsetof(ccCharacterBase, unk_00C8) == 0xC8, "ccCharacterBase.unk_00C8");
_Static_assert(offsetof(ccCharacterBase, unk_00D0) == 0xD0, "ccCharacterBase.unk_00D0");
_Static_assert(offsetof(ccCharacterBase, unk_00D4) == 0xD4, "ccCharacterBase.unk_00D4");
_Static_assert(offsetof(ccCharacterBase, unk_00DC) == 0xDC, "ccCharacterBase.unk_00DC");
_Static_assert(offsetof(ccCharacterBase, unk_00E4) == 0xE4, "ccCharacterBase.unk_00E4");
_Static_assert(offsetof(ccCharacterBase, unk_00EC) == 0xEC, "ccCharacterBase.unk_00EC");
_Static_assert(offsetof(ccCharacterBase, unk_00F4) == 0xF4, "ccCharacterBase.unk_00F4");
_Static_assert(offsetof(ccCharacterBase, unk_00F8) == 0xF8, "ccCharacterBase.unk_00F8");
_Static_assert(offsetof(ccCharacterBase, unk_00FC) == 0xFC, "ccCharacterBase.unk_00FC");
_Static_assert(offsetof(ccCharacterBase, unk_0100) == 0x100, "ccCharacterBase.unk_0100");
_Static_assert(offsetof(ccCharacterBase, unk_0104) == 0x104, "ccCharacterBase.unk_0104");
_Static_assert(offsetof(ccCharacterBase, unk_010C) == 0x10C, "ccCharacterBase.unk_010C");
_Static_assert(offsetof(ccCharacterBase, pad_0110) == 0x110, "ccCharacterBase.pad_0110");
_Static_assert(offsetof(ccCharacterBase, unk_0120) == 0x120, "ccCharacterBase.unk_0120");
_Static_assert(offsetof(ccCharacterBase, pad_0128) == 0x128, "ccCharacterBase.pad_0128");
_Static_assert(offsetof(ccCharacterBase, unk_0150) == 0x150, "ccCharacterBase.unk_0150");
_Static_assert(offsetof(ccCharacterBase, unk_0158) == 0x158, "ccCharacterBase.unk_0158");
_Static_assert(offsetof(ccCharacterBase, unk_0160) == 0x160, "ccCharacterBase.unk_0160");
_Static_assert(offsetof(ccCharacterBase, unk_0168) == 0x168, "ccCharacterBase.unk_0168");
_Static_assert(offsetof(ccCharacterBase, unk_0170) == 0x170, "ccCharacterBase.unk_0170");
_Static_assert(offsetof(ccCharacterBase, unk_0178) == 0x178, "ccCharacterBase.unk_0178");
_Static_assert(offsetof(ccCharacterBase, unk_0180) == 0x180, "ccCharacterBase.unk_0180");
_Static_assert(offsetof(ccCharacterBase, unk_0188) == 0x188, "ccCharacterBase.unk_0188");
_Static_assert(offsetof(ccCharacterBase, unk_0190) == 0x190, "ccCharacterBase.unk_0190");
_Static_assert(offsetof(ccCharacterBase, unk_0198) == 0x198, "ccCharacterBase.unk_0198");
_Static_assert(offsetof(ccCharacterBase, unk_01A0) == 0x1A0, "ccCharacterBase.unk_01A0");
_Static_assert(offsetof(ccCharacterBase, unk_01A8) == 0x1A8, "ccCharacterBase.unk_01A8");
_Static_assert(offsetof(ccCharacterBase, unk_01B0) == 0x1B0, "ccCharacterBase.unk_01B0");
_Static_assert(offsetof(ccCharacterBase, unk_01B8) == 0x1B8, "ccCharacterBase.unk_01B8");
_Static_assert(offsetof(ccCharacterBase, unk_01BC) == 0x1BC, "ccCharacterBase.unk_01BC");
_Static_assert(offsetof(ccCharacterBase, unk_01C4) == 0x1C4, "ccCharacterBase.unk_01C4");
_Static_assert(offsetof(ccCharacterBase, unk_01C8) == 0x1C8, "ccCharacterBase.unk_01C8");
_Static_assert(offsetof(ccCharacterBase, pad_01D0) == 0x1D0, "ccCharacterBase.pad_01D0");
_Static_assert(offsetof(ccCharacterBase, unk_0210) == 0x210, "ccCharacterBase.unk_0210");
_Static_assert(offsetof(ccCharacterBase, pad_0214) == 0x214, "ccCharacterBase.pad_0214");
_Static_assert(offsetof(ccCharacterBase, effAtT0_ptr) == 0x218, "ccCharacterBase.effAtT0_ptr");
_Static_assert(offsetof(ccCharacterBase, pad_0220) == 0x220, "ccCharacterBase.pad_0220");
_Static_assert(offsetof(ccCharacterBase, scale_factor) == 0x224, "ccCharacterBase.scale_factor");
_Static_assert(offsetof(ccCharacterBase, unk_0228) == 0x228, "ccCharacterBase.unk_0228");
_Static_assert(offsetof(ccCharacterBase, pad_0230) == 0x230, "ccCharacterBase.pad_0230");
_Static_assert(offsetof(ccCharacterBase, unk_02E0) == 0x2E0, "ccCharacterBase.unk_02E0");
_Static_assert(offsetof(ccCharacterBase, pad_02E8) == 0x2E8, "ccCharacterBase.pad_02E8");
_Static_assert(offsetof(ccCharacterBase, lockTarget_id) == 0x604, "ccCharacterBase.lockTarget_id");
_Static_assert(offsetof(ccCharacterBase, pad_0608) == 0x608, "ccCharacterBase.pad_0608");
_Static_assert(offsetof(ccCharacterBase, unk_0694) == 0x694, "ccCharacterBase.unk_0694");
_Static_assert(offsetof(ccCharacterBase, pad_0698) == 0x698, "ccCharacterBase.pad_0698");
_Static_assert(offsetof(ccCharacterBase, unk_0718) == 0x718, "ccCharacterBase.unk_0718");
_Static_assert(offsetof(ccCharacterBase, pad_0720) == 0x720, "ccCharacterBase.pad_0720");
_Static_assert(offsetof(ccCharacterBase, unk_0768) == 0x768, "ccCharacterBase.unk_0768");
_Static_assert(offsetof(ccCharacterBase, unk_0770) == 0x770, "ccCharacterBase.unk_0770");
_Static_assert(offsetof(ccCharacterBase, pad_0778) == 0x778, "ccCharacterBase.pad_0778");
_Static_assert(offsetof(ccCharacterBase, unk_07B8) == 0x7B8, "ccCharacterBase.unk_07B8");
_Static_assert(offsetof(ccCharacterBase, pad_07C0) == 0x7C0, "ccCharacterBase.pad_07C0");
_Static_assert(offsetof(ccCharacterBase, unk_07C4) == 0x7C4, "ccCharacterBase.unk_07C4");
_Static_assert(offsetof(ccCharacterBase, pad_07CC) == 0x7CC, "ccCharacterBase.pad_07CC");
_Static_assert(offsetof(ccCharacterBase, unk_07D0) == 0x7D0, "ccCharacterBase.unk_07D0");
_Static_assert(offsetof(ccCharacterBase, pad_07D8) == 0x7D8, "ccCharacterBase.pad_07D8");
_Static_assert(offsetof(ccCharacterBase, unk_081C) == 0x81C, "ccCharacterBase.unk_081C");

#endif /* CCCHARACTERBASE_S2_H */