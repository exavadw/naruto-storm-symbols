#ifndef CCPLAYERPAD_S1_H
#define CCPLAYERPAD_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccPlayerPad (NARUTO STORM 1 / s1) — INFERRED layout from static analysis.
 * Embedded in ccCharacterBase at offset 0x280 (see ccCharacterBase.h).
 * Size: >= 0x424 (highest proven field at 0x420 + 4 bytes).
 * Upper bound from ccCharacterBase next sibling at 0x6AC: max 0x42C.
 * Likely actual size: 0x428 (8-byte aligned).
 *
 * Key evidence: ccPlayerPad::Clear (RVA 0x357B2C) zeroes/initialises every
 * field below. Constructor at RVA 0x357AF0 called with this+0x50 inside
 * ccCharacterBase ctor (RVA 0x179550), confirming embed offset 0x280.
 *
 * IMPORTANT: This struct uses ONLY uint8_t and uint32_t fields to avoid
 * compiler-inserted alignment padding. The game binary accesses these as
 * raw byte offsets; any uint64_t would cause the compiler to insert 4-byte
 * padding before it on x86-64, breaking the layout. Fields that are logically
 * uint64 are represented as two adjacent uint32_t values (lo/hi).
 */

typedef struct ccPlayerPad {
    /* 0x000-0x03B: prefix region (vtable? unused?). Not touched by Clear. */
    uint8_t pad_000[60];              /* 0x000 */

    /* --- Analog stick 0 (left) --- stride 0xB8, loop base = this+0x40 --- */
    /* lVar2 = param_1 + 0x40; *(undefined8*)(lVar2 + -4) = 0 → offset 0x3C */
    uint32_t stick0_field_03C;        /* 0x03C — zeroed (written as 8 bytes at 0x3C) */
    /* *(undefined8*)(lVar2 + 4) = 0 → offset 0x44 (but written as 8 bytes starting 0x44) */
    /* Actually: lVar2+4 = 0x44, but the write is 8 bytes covering 0x44-0x4B.
     * However, lVar2-4 = 0x3C writes 8 bytes covering 0x3C-0x43.
     * So 0x3C field is 8 bytes (uint64), and 0x44 field is 8 bytes (uint64).
     * We split into uint32 pairs to avoid padding. */
    uint32_t stick0_field_040_lo;     /* 0x040 — low half of 8-byte zero at lVar2-4 */
    /* Wait — re-analyzing: lVar2 = base+0x40. lVar2 + (-4) = base+0x3C.
     * *(undefined8*)(base+0x3C) = 0 → 8 bytes at 0x3C..0x43.
     * Then *(undefined8*)(lVar2+4) = *(undefined8*)(base+0x44) = 0 → 8 bytes at 0x44..0x4B.
     * Then *(undefined8*)(lVar2+0xC) = *(undefined8*)(base+0x4C) = 1 → 8 bytes at 0x4C..0x53.
     * But 0x44..0x4B overlaps with 0x4C! That means the second write (0x44, 8 bytes)
     * covers 0x44-0x4B, then the third write (0x4C, 8 bytes) overwrites 0x4C-0x53.
     * Net effect: 0x3C-0x43 = 0, 0x44-0x4B = 0 (then partially overwritten), 0x4C-0x53 = 1.
     * Actually no: 0x44+8 = 0x4C, so they are adjacent, not overlapping. 0x44..0x4B then 0x4C..0x53.
     * So the three 8-byte writes cover: 0x3C-0x43, 0x44-0x4B, 0x4C-0x53. Total: 0x3C to 0x53 = 24 bytes.
     * After these, puVar3 = (undefined4*)(lVar2 + 100) = (undefined4*)(base + 0x40 + 0x64) = base+0xA4.
     * Wait, 100 decimal = 0x64. So puVar3 starts at base+0xA4.
     * Inner loop: puVar3[-0x14] = 0, *puVar3 = 0, puVar3++.
     * puVar3[-0x14] = base+0xA4 - 0x50 = base+0x54. So inner array starts at 0x54.
     * Loop runs 0x14 times, each iteration advances puVar3 by 4 bytes.
     * puVar3[-0x14] always points 0x50 bytes behind current puVar3.
     * Start: puVar3 = base+0xA4. puVar3[-0x14] = base+0x54. Write base+0x54=0, base+0xA4=0.
     * Next: puVar3 = base+0xA8. puVar3[-0x14] = base+0x58. Write base+0x58=0, base+0xA8=0.
     * ...after 0x14 iterations: last puVar3[-0x14] = base+0x54 + 0x4C = base+0xA0.
     *   last puVar3 = base+0xA4 + 0x4C = base+0xF0.
     * So inner loop zeroes: base+0x54..0xA0 (0x14 uint32s) AND base+0xA4..0xF0 (0x14 uint32s).
     * That's two parallel arrays of 0x14 uint32s each, or one contiguous block 0x54..0xF3.
     * Total per stick: 0x3C to 0xF3 = 0xB8 bytes. ✓ Matches stride.
     */
    uint32_t stick0_field_044_lo;     /* 0x044 — low half of 8-byte zero at base+0x44 */
    uint32_t stick0_field_044_hi;     /* 0x048 */
    uint32_t stick0_field_04C_lo;     /* 0x04C — low half of 8-byte value=1 at base+0x4C */
    uint32_t stick0_field_04C_hi;     /* 0x050 */
    uint32_t stick0_inner[20];        /* 0x054 — 0x14 uint32s, all zeroed (first half of dual array) */
    uint32_t stick0_inner2[20];       /* 0x0A4 — 0x14 uint32s, all zeroed (second half at base+0xA4) */
    uint8_t  stick0_pad_0F4[4];       /* 0x0F4-0x0F8 */

    /* --- Analog stick 1 (right) --- stride 0xB8, starts at 0x0F8 --- */
    uint32_t stick1_field_0F8;        /* 0x0F8 — zeroed (lVar2-4 where lVar2=base+0xF8) */
    uint32_t stick1_field_0FC_lo;     /* 0x0FC — low half of 8-byte zero */
    uint32_t stick1_field_0FC_hi;     /* 0x100 */
    uint32_t stick1_field_104_lo;     /* 0x104 — low half of 8-byte value=1 */
    uint32_t stick1_field_104_hi;     /* 0x108 */
    uint32_t stick1_inner[20];        /* 0x10C — first half of dual array */
    uint32_t stick1_inner2[20];       /* 0x15C — second half */
    uint8_t  stick1_pad_1AC[4];       /* 0x1AC-0x1B0 */

    /* --- Post-stick fields --- */
    uint32_t unk_1B0_lo;              /* 0x1B0 — low half of 8-byte zero */
    uint32_t unk_1B0_hi;              /* 0x1B4 */
    uint32_t unk_1B8_lo;              /* 0x1B8 — low half of 8-byte zero */
    uint32_t unk_1B8_hi;              /* 0x1BC */
    uint32_t unk_1C0;                 /* 0x1C0 — set to 0xFFFFFFFF */

    /* Button mapping array: 0x3C entries × 8 bytes = 0x1E0 bytes.
     * Each entry: key (uint32, init 0) + value (uint32, init 0xFFFFFFFF). */
    uint32_t buttons[120];            /* 0x1C4 — 60 key/value pairs */

    uint32_t unk_3A4;                 /* 0x3A4 — zeroed */
    uint8_t  buffer_3A8[104];         /* 0x3A8 — 0x68 bytes zeroed via memset; ends at 0x410 */

    uint32_t unk_410;                 /* 0x410 — zeroed */
    uint32_t timestamp_414_lo;        /* 0x414 — low half of FUN_14047fe80() return */
    uint32_t timestamp_414_hi;        /* 0x418 — high half */
    uint32_t unk_41C;                 /* 0x41C — upper uint32 from FUN_14047fe80()+8 */
    uint32_t unk_420;                 /* 0x420 — zeroed */

    /* Struct extent: last proven field ends at 0x424.
     * Size unknown, >= 0x424. Upper bound 0x42C from ccCharacterBase layout. */
} ccPlayerPad;

/* Offset assertions for every named field */
static_assert(offsetof(ccPlayerPad, pad_000) == 0x000, "ccPlayerPad.pad_000");
static_assert(offsetof(ccPlayerPad, stick0_field_03C) == 0x03C, "stick0_field_03C");
static_assert(offsetof(ccPlayerPad, stick0_field_040_lo) == 0x040, "stick0_field_040_lo");
static_assert(offsetof(ccPlayerPad, stick0_field_044_lo) == 0x044, "stick0_field_044_lo");
static_assert(offsetof(ccPlayerPad, stick0_field_044_hi) == 0x048, "stick0_field_044_hi");
static_assert(offsetof(ccPlayerPad, stick0_field_04C_lo) == 0x04C, "stick0_field_04C_lo");
static_assert(offsetof(ccPlayerPad, stick0_field_04C_hi) == 0x050, "stick0_field_04C_hi");
static_assert(offsetof(ccPlayerPad, stick0_inner) == 0x054, "stick0_inner");
static_assert(offsetof(ccPlayerPad, stick0_inner2) == 0x0A4, "stick0_inner2");
static_assert(offsetof(ccPlayerPad, stick0_pad_0F4) == 0x0F4, "stick0_pad_0F4");
static_assert(offsetof(ccPlayerPad, stick1_field_0F8) == 0x0F8, "stick1_field_0F8");
static_assert(offsetof(ccPlayerPad, stick1_field_0FC_lo) == 0x0FC, "stick1_field_0FC_lo");
static_assert(offsetof(ccPlayerPad, stick1_field_0FC_hi) == 0x100, "stick1_field_0FC_hi");
static_assert(offsetof(ccPlayerPad, stick1_field_104_lo) == 0x104, "stick1_field_104_lo");
static_assert(offsetof(ccPlayerPad, stick1_field_104_hi) == 0x108, "stick1_field_104_hi");
static_assert(offsetof(ccPlayerPad, stick1_inner) == 0x10C, "stick1_inner");
static_assert(offsetof(ccPlayerPad, stick1_inner2) == 0x15C, "stick1_inner2");
static_assert(offsetof(ccPlayerPad, stick1_pad_1AC) == 0x1AC, "stick1_pad_1AC");
static_assert(offsetof(ccPlayerPad, unk_1B0_lo) == 0x1B0, "unk_1B0_lo");
static_assert(offsetof(ccPlayerPad, unk_1B0_hi) == 0x1B4, "unk_1B0_hi");
static_assert(offsetof(ccPlayerPad, unk_1B8_lo) == 0x1B8, "unk_1B8_lo");
static_assert(offsetof(ccPlayerPad, unk_1B8_hi) == 0x1BC, "unk_1B8_hi");
static_assert(offsetof(ccPlayerPad, unk_1C0) == 0x1C0, "unk_1C0");
static_assert(offsetof(ccPlayerPad, buttons) == 0x1C4, "buttons");
static_assert(offsetof(ccPlayerPad, unk_3A4) == 0x3A4, "unk_3A4");
static_assert(offsetof(ccPlayerPad, buffer_3A8) == 0x3A8, "buffer_3A8");
static_assert(offsetof(ccPlayerPad, unk_410) == 0x410, "unk_410");
static_assert(offsetof(ccPlayerPad, timestamp_414_lo) == 0x414, "timestamp_414_lo");
static_assert(offsetof(ccPlayerPad, timestamp_414_hi) == 0x418, "timestamp_414_hi");
static_assert(offsetof(ccPlayerPad, unk_41C) == 0x41C, "unk_41C");
static_assert(offsetof(ccPlayerPad, unk_420) == 0x420, "unk_420");

#endif /* CCPLAYERPAD_S1_H */