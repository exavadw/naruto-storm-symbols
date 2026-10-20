#ifndef CCCHARACTERBASE_S1_H
#define CCCHARACTERBASE_S1_H

#include <stdint.h>
#include <stddef.h>

/* ccCharacterBase (NARUTO STORM 1 / s1) — INFERRED layout from static analysis.
 * Base class: ccNarutoRootObjManager::EntryNarutoRootObj (vtable at +0x0).
 * Size unknown; last proven field ends at 0x894. Never instantiated directly.
 * Packed struct: all fields are uint8_t arrays to guarantee exact byte offsets.
 * Named fields have comments showing intended type and evidence.
 */
#pragma pack(push, 1)
typedef struct ccCharacterBase {
    uint8_t vtable[8]; /* 0x0000 void* vtable ptr */
    uint8_t pad_0008[20];
    uint8_t unk_001C[4]; /* 0x001C u32 */
    uint8_t pad_0020[4];
    uint8_t unk_0024[4]; /* 0x0024 u32 */
    uint8_t pad_0028[4];
    uint8_t unk_002C[4]; /* 0x002C u32 */
    uint8_t pad_0030[4];
    uint8_t unk_0034[4]; /* 0x0034 u32 */
    uint8_t pad_0038[12];
    uint8_t unk_0044[8]; /* 0x0044 u64 */
    uint8_t unk_004C[4]; /* 0x004C u32 */
    uint8_t pad_0050[8];
    uint8_t unk_0058[4]; /* 0x0058 u32 */
    uint8_t unk_005C[8]; /* 0x005C u64 */
    uint8_t pad_0064[4];
    uint8_t unk_0068[8]; /* 0x0068 u64 */
    uint8_t unk_0070[4]; /* 0x0070 u32 */
    uint8_t unk_0074[4]; /* 0x0074 u32 */
    uint8_t pad_0078[140];
    uint8_t unk_0104[8]; /* 0x0104 u64 */
    uint8_t unk_010C[4]; /* 0x010C u32 */
    uint8_t unk_0110[8]; /* 0x0110 u64 */
    uint8_t unk_0118[4]; /* 0x0118 u32 */
    uint8_t unk_011C[8]; /* 0x011C u64 */
    uint8_t unk_0124[4]; /* 0x0124 u32 */
    uint8_t unk_0128[8]; /* 0x0128 u64 */
    uint8_t unk_0130[4]; /* 0x0130 u32 */
    uint8_t unk_0134[4]; /* 0x0134 u32 */
    uint8_t unk_0138[8]; /* 0x0138 u64 */
    uint8_t unk_0140[8]; /* 0x0140 u64 */
    uint8_t unk_0148[4]; /* 0x0148 u32 */
    uint8_t unk_014C[8]; /* 0x014C u64 */
    uint8_t unk_0154[8]; /* 0x0154 u64 */
    uint8_t unk_015C[8]; /* 0x015C u64 */
    uint8_t unk_0164[8]; /* 0x0164 u64 */
    uint8_t pad_016C[4];
    uint8_t unk_0170[8]; /* 0x0170 u64 */
    uint8_t unk_0178[8]; /* 0x0178 u64 */
    uint8_t unk_0180[8]; /* 0x0180 u64 */
    uint8_t pad_0188[20];
    uint8_t scale_factor[4]; /* 0x019C f32 */
    uint8_t effAtT0_ptr[8]; /* 0x01A0 u64 ptr */
    uint8_t unk_01A8[8]; /* 0x01A8 u64 */
    uint8_t ctrlTarget_flags[4]; /* 0x01B0 u32 */
    uint8_t ctrlTargetLock_id[4]; /* 0x01B4 u32 */
    uint8_t ctrlTarget_index[4]; /* 0x01B8 u32 */
    uint8_t ctrlTarget_ptr[8]; /* 0x01BC u64 ptr */
    uint8_t pad_01C4[12];
    uint8_t unk_01D0[4]; /* 0x01D0 u32 */
    uint8_t pad_01D4[124];
    uint8_t unk_0250[8]; /* 0x0250 u64 */
    uint8_t pad_0258[16];
    uint8_t field_268[4]; /* 0x0268 u32 */
    uint8_t field_26c[4]; /* 0x026C u32 */
    uint8_t unk_0270[8]; /* 0x0270 u64 */
    uint8_t field_278[4]; /* 0x0278 u32 */
    uint8_t pad_027C[4];
    uint8_t unk_0280[8]; /* 0x0280 u64 */
    uint8_t pad_0288[420];
    uint8_t unk_042C[4]; /* 0x042C u32 */
    uint8_t pad_0430[632];
    uint8_t unk_06A8[4]; /* 0x06A8 u32 */
    uint8_t pad_06AC[356];
    uint8_t unk_0810[8]; /* 0x0810 u64 */
    uint8_t pad_0818[4];
    uint8_t float_81c[4]; /* 0x081C f32 */
    uint8_t pad_0820[8];
    uint8_t float_828[4]; /* 0x0828 f32 */
    uint8_t pad_082C[8];
    uint8_t float_834[4]; /* 0x0834 f32 */
    uint8_t pad_0838[12];
    uint8_t mode_flag[4]; /* 0x0844 u32 */
    uint8_t unk_0848[8]; /* 0x0848 u64 */
    uint8_t pad_0850[64];
    uint8_t field_890[4]; /* 0x0890 u32 */
    /* ... size unknown, >= 0x894 ... */
} ccCharacterBase;
#pragma pack(pop)

/* Offset assertions — every field must land at its game offset */
_Static_assert(offsetof(ccCharacterBase, vtable) == 0x0, "ccCharacterBase.vtable");
_Static_assert(offsetof(ccCharacterBase, unk_001C) == 0x1C, "ccCharacterBase.unk_001C");
_Static_assert(offsetof(ccCharacterBase, unk_0024) == 0x24, "ccCharacterBase.unk_0024");
_Static_assert(offsetof(ccCharacterBase, unk_002C) == 0x2C, "ccCharacterBase.unk_002C");
_Static_assert(offsetof(ccCharacterBase, unk_0034) == 0x34, "ccCharacterBase.unk_0034");
_Static_assert(offsetof(ccCharacterBase, unk_0044) == 0x44, "ccCharacterBase.unk_0044");
_Static_assert(offsetof(ccCharacterBase, unk_004C) == 0x4C, "ccCharacterBase.unk_004C");
_Static_assert(offsetof(ccCharacterBase, unk_0058) == 0x58, "ccCharacterBase.unk_0058");
_Static_assert(offsetof(ccCharacterBase, unk_005C) == 0x5C, "ccCharacterBase.unk_005C");
_Static_assert(offsetof(ccCharacterBase, unk_0068) == 0x68, "ccCharacterBase.unk_0068");
_Static_assert(offsetof(ccCharacterBase, unk_0070) == 0x70, "ccCharacterBase.unk_0070");
_Static_assert(offsetof(ccCharacterBase, unk_0074) == 0x74, "ccCharacterBase.unk_0074");
_Static_assert(offsetof(ccCharacterBase, unk_0104) == 0x104, "ccCharacterBase.unk_0104");
_Static_assert(offsetof(ccCharacterBase, unk_010C) == 0x10C, "ccCharacterBase.unk_010C");
_Static_assert(offsetof(ccCharacterBase, unk_0110) == 0x110, "ccCharacterBase.unk_0110");
_Static_assert(offsetof(ccCharacterBase, unk_0118) == 0x118, "ccCharacterBase.unk_0118");
_Static_assert(offsetof(ccCharacterBase, unk_011C) == 0x11C, "ccCharacterBase.unk_011C");
_Static_assert(offsetof(ccCharacterBase, unk_0124) == 0x124, "ccCharacterBase.unk_0124");
_Static_assert(offsetof(ccCharacterBase, unk_0128) == 0x128, "ccCharacterBase.unk_0128");
_Static_assert(offsetof(ccCharacterBase, unk_0130) == 0x130, "ccCharacterBase.unk_0130");
_Static_assert(offsetof(ccCharacterBase, unk_0134) == 0x134, "ccCharacterBase.unk_0134");
_Static_assert(offsetof(ccCharacterBase, unk_0138) == 0x138, "ccCharacterBase.unk_0138");
_Static_assert(offsetof(ccCharacterBase, unk_0140) == 0x140, "ccCharacterBase.unk_0140");
_Static_assert(offsetof(ccCharacterBase, unk_0148) == 0x148, "ccCharacterBase.unk_0148");
_Static_assert(offsetof(ccCharacterBase, unk_014C) == 0x14C, "ccCharacterBase.unk_014C");
_Static_assert(offsetof(ccCharacterBase, unk_0154) == 0x154, "ccCharacterBase.unk_0154");
_Static_assert(offsetof(ccCharacterBase, unk_015C) == 0x15C, "ccCharacterBase.unk_015C");
_Static_assert(offsetof(ccCharacterBase, unk_0164) == 0x164, "ccCharacterBase.unk_0164");
_Static_assert(offsetof(ccCharacterBase, unk_0170) == 0x170, "ccCharacterBase.unk_0170");
_Static_assert(offsetof(ccCharacterBase, unk_0178) == 0x178, "ccCharacterBase.unk_0178");
_Static_assert(offsetof(ccCharacterBase, unk_0180) == 0x180, "ccCharacterBase.unk_0180");
_Static_assert(offsetof(ccCharacterBase, scale_factor) == 0x19C, "ccCharacterBase.scale_factor");
_Static_assert(offsetof(ccCharacterBase, effAtT0_ptr) == 0x1A0, "ccCharacterBase.effAtT0_ptr");
_Static_assert(offsetof(ccCharacterBase, unk_01A8) == 0x1A8, "ccCharacterBase.unk_01A8");
_Static_assert(offsetof(ccCharacterBase, ctrlTarget_flags) == 0x1B0, "ccCharacterBase.ctrlTarget_flags");
_Static_assert(offsetof(ccCharacterBase, ctrlTargetLock_id) == 0x1B4, "ccCharacterBase.ctrlTargetLock_id");
_Static_assert(offsetof(ccCharacterBase, ctrlTarget_index) == 0x1B8, "ccCharacterBase.ctrlTarget_index");
_Static_assert(offsetof(ccCharacterBase, ctrlTarget_ptr) == 0x1BC, "ccCharacterBase.ctrlTarget_ptr");
_Static_assert(offsetof(ccCharacterBase, unk_01D0) == 0x1D0, "ccCharacterBase.unk_01D0");
_Static_assert(offsetof(ccCharacterBase, unk_0250) == 0x250, "ccCharacterBase.unk_0250");
_Static_assert(offsetof(ccCharacterBase, field_268) == 0x268, "ccCharacterBase.field_268");
_Static_assert(offsetof(ccCharacterBase, field_26c) == 0x26C, "ccCharacterBase.field_26c");
_Static_assert(offsetof(ccCharacterBase, unk_0270) == 0x270, "ccCharacterBase.unk_0270");
_Static_assert(offsetof(ccCharacterBase, field_278) == 0x278, "ccCharacterBase.field_278");
_Static_assert(offsetof(ccCharacterBase, unk_0280) == 0x280, "ccCharacterBase.unk_0280");
_Static_assert(offsetof(ccCharacterBase, unk_042C) == 0x42C, "ccCharacterBase.unk_042C");
_Static_assert(offsetof(ccCharacterBase, unk_06A8) == 0x6A8, "ccCharacterBase.unk_06A8");
_Static_assert(offsetof(ccCharacterBase, unk_0810) == 0x810, "ccCharacterBase.unk_0810");
_Static_assert(offsetof(ccCharacterBase, float_81c) == 0x81C, "ccCharacterBase.float_81c");
_Static_assert(offsetof(ccCharacterBase, float_828) == 0x828, "ccCharacterBase.float_828");
_Static_assert(offsetof(ccCharacterBase, float_834) == 0x834, "ccCharacterBase.float_834");
_Static_assert(offsetof(ccCharacterBase, mode_flag) == 0x844, "ccCharacterBase.mode_flag");
_Static_assert(offsetof(ccCharacterBase, unk_0848) == 0x848, "ccCharacterBase.unk_0848");
_Static_assert(offsetof(ccCharacterBase, field_890) == 0x890, "ccCharacterBase.field_890");

#endif /* CCCHARACTERBASE_S1_H */
