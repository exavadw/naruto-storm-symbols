/* libCriMana.h — CRIWARE Sofdec/Mana video structs for Storm 2 PC (s2, NSUNS2.exe-abf2b6)
 * Reconstructed from own-game decompilation only. All offsets INFERRED, not CONFIRMED.
 * CRIWARE is proprietary — no SDK source used.
 * Rollback: all CRI state tagged PRES unless code shows simulation dependency.
 * Image base: 0x140000000
 */
#ifndef LIBCRIMANA_S2_H
#define LIBCRIMANA_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ==========================================================================
 * Vtable addresses (RVA, image base 0x140000000)
 * Extracted from rip-relative LEA in constructors via raw byte disassembly.
 *
 * CriManaSoundAtomVoice     vftable[0] = RVA 0x8B6F98  vftable[1] = RVA 0x8B7070
 * CriManaFileReader         vftable[0] = RVA 0x8B84C8  vftable[1] = RVA 0x8B8528
 * ========================================================================== */

/* ==========================================================================
 * Inheritance chain (from ctor decompilation):
 *   CriMvSoundInterface (base-most, single vtable)
 *   CriAllocator (embedded at +8 in CriManaSound, single vtable)
 *   CriManaSound : CriMvSoundInterface (two vtables)
 *   CriManaSoundAtomVoice : CriManaSound (two vtables)
 *   CriManaSoundAtomVoice_Float32 : CriManaSoundAtomVoice (two vtables)
 * ========================================================================== */

/* --- CriManaSoundAtomVoice ------------------------------------------------
 * Size: unknown, >= 0x380 (last field field_37C ends at 0x380).
 * Subclass CriManaSoundAtomVoice_Float32 has proven size 0x3B0 (s1 factory pattern).
 * Constructor at RVA 0x6FD40 calls base ctor FUN_14006fcf0 then sets vtables and fields.
 * Vtables extracted from LEA at ctor+0x18 and ctor+0x27.
 * All fields PRES — CRI audio playback state, not simulation-coupled.
 */
typedef struct __attribute__((packed)) CriManaSoundAtomVoice {
    /* 0x000 */ uint64_t vftable_0;           /* CriManaSoundAtomVoice::vftable[0] @ RVA 0x8B6F98 */
    /* 0x008 */ uint64_t vftable_1;           /* CriManaSoundAtomVoice::vftable[1] @ RVA 0x8B7070 */
    /* 0x010 */ uint8_t  _pad_010[0x50];      /* 0x010-0x05F: inherited CriManaSound/CriMvSoundInterface/CriAllocator fields (not surfaced) */
    /* 0x060 */ uint64_t field_060;           /* w medium — ctor: param_1[0xc]=0 */
    /* 0x068 */ uint8_t  embedded_array_068[0x138]; /* r low — FUN_140012430(param_1+0xd, 0x138) memset zero */
    /* 0x1A0 */ uint8_t  embedded_array_1A0[0x18];  /* r low — FUN_140012430(param_1+0x34, 0x18) */
    /* 0x1B8 */ uint64_t field_1B8;           /* rw high — FUN_1400a396c(param_1[0x37],0) */
    /* 0x1C0 */ uint8_t  embedded_array_1C0[0x60];  /* r low — FUN_140012430(param_1+0x38, 0x60); also vcall site */
    /* 0x220 */ uint64_t field_220;           /* rw high — FUN_140021600(param_1[0x44],param_2) */
    /* 0x228 */ uint64_t field_228;           /* w medium — ctor: param_1[0x45]=0 */
    /* 0x230 */ uint8_t  embedded_array_230[0x10];  /* r low — FUN_140012430(param_1+0x46, 0x10) */
    /* 0x240 */ uint32_t field_240;           /* rw high — *(u32*)(param_1+0x48)=param_2 */
    /* 0x244 */ uint32_t field_244_count;     /* rw high — loop bound: for(i=0; i<*(u32*)(param_1+0x244); i++) */
    /* 0x248 */ uint32_t field_248;           /* rw high — *(u32*)(param_1+0x49)=0 */
    /* 0x24C */ uint8_t  _pad_24C[4];         /* alignment padding */
    /* 0x250 */ uint64_t field_250;           /* w medium — ctor: param_1[0x4a]=0 */
    /* 0x258 */ uint64_t field_258;           /* w medium — ctor: param_1[0x4b]=0 */
    /* 0x260 */ uint32_t field_260;           /* rw high — (int)param_1[0x4c] */
    /* 0x264 */ uint32_t field_264_size;      /* rw high — FUN_140012430(local_38, *(u32*)(param_1+0x264)) */
    /* 0x268 */ uint32_t field_268;           /* w medium — ctor: *(u32*)(param_1+0x4d)=0 */
    /* 0x26C */ uint32_t field_26C;           /* w medium — ctor: *(u32*)(param_1+0x26c)=1 */
    /* 0x270 */ uint32_t field_270;           /* w medium — ctor: *(u32*)(param_1+0x4e)=1 */
    /* 0x274 */ uint32_t field_274;           /* w medium — ctor: *(u32*)(param_1+0x274)=0x3f800000 (1.0f) */
    /* 0x278 */ uint32_t field_278;           /* w medium — ctor: *(u32*)(param_1+0x4f)=0 */
    /* 0x27C */ uint32_t field_27C;           /* w medium — ctor: *(u32*)(param_1+0x27c)=0 */
    /* 0x280 */ uint32_t field_280;           /* w medium — ctor: *(u32*)(param_1+0x50)=0 */
    /* 0x284 */ uint32_t field_284;           /* w medium — ctor: *(u32*)(param_1+0x284)=0 */
    /* 0x288 */ uint32_t field_288;           /* w medium — ctor: *(u32*)(param_1+0x51)=1 */
    /* 0x28C */ uint32_t field_28C;           /* w medium — ctor: *(u32*)(param_1+0x28c)=0 */
    /* 0x290 */ uint32_t field_290;           /* w medium — ctor: *(u32*)(param_1+0x52)=0 */
    /* 0x294 */ uint8_t  _pad_294[4];         /* alignment padding */
    /* 0x298 */ uint64_t field_298;           /* rw high — param_1[0x53]=0 */
    /* 0x2A0 */ uint64_t field_2A0;           /* w medium — ctor: param_1[0x54]=0 */
    /* 0x2A8 */ uint64_t field_2A8;           /* rw high — param_1[0x55]=0 */
    /* 0x2B0 */ uint64_t field_2B0;           /* w medium — ctor: param_1[0x56]=1 */
    /* 0x2B8 */ uint32_t field_2B8;           /* w medium — ctor: *(u32*)(param_1+0x57)=1 */
    /* 0x2BC */ uint8_t  embedded_array_2BC[0xC0]; /* from ctor: FUN_140012430(param_1+700, 0xc0) */
    /* 0x37C */ uint32_t field_37C;           /* w medium — ctor: *(u32*)(param_1+0x37c)=0x3f800000 (1.0f) */
} CriManaSoundAtomVoice;

static_assert(offsetof(CriManaSoundAtomVoice, vftable_0) == 0x000, "vftable_0");
static_assert(offsetof(CriManaSoundAtomVoice, vftable_1) == 0x008, "vftable_1");
static_assert(offsetof(CriManaSoundAtomVoice, field_060) == 0x060, "field_060");
static_assert(offsetof(CriManaSoundAtomVoice, embedded_array_068) == 0x068, "embedded_array_068");
static_assert(offsetof(CriManaSoundAtomVoice, embedded_array_1A0) == 0x1A0, "embedded_array_1A0");
static_assert(offsetof(CriManaSoundAtomVoice, field_1B8) == 0x1B8, "field_1B8");
static_assert(offsetof(CriManaSoundAtomVoice, embedded_array_1C0) == 0x1C0, "embedded_array_1C0");
static_assert(offsetof(CriManaSoundAtomVoice, field_220) == 0x220, "field_220");
static_assert(offsetof(CriManaSoundAtomVoice, field_228) == 0x228, "field_228");
static_assert(offsetof(CriManaSoundAtomVoice, embedded_array_230) == 0x230, "embedded_array_230");
static_assert(offsetof(CriManaSoundAtomVoice, field_240) == 0x240, "field_240");
static_assert(offsetof(CriManaSoundAtomVoice, field_244_count) == 0x244, "field_244_count");
static_assert(offsetof(CriManaSoundAtomVoice, field_248) == 0x248, "field_248");
static_assert(offsetof(CriManaSoundAtomVoice, field_250) == 0x250, "field_250");
static_assert(offsetof(CriManaSoundAtomVoice, field_258) == 0x258, "field_258");
static_assert(offsetof(CriManaSoundAtomVoice, field_260) == 0x260, "field_260");
static_assert(offsetof(CriManaSoundAtomVoice, field_264_size) == 0x264, "field_264_size");
static_assert(offsetof(CriManaSoundAtomVoice, field_268) == 0x268, "field_268");
static_assert(offsetof(CriManaSoundAtomVoice, field_26C) == 0x26C, "field_26C");
static_assert(offsetof(CriManaSoundAtomVoice, field_270) == 0x270, "field_270");
static_assert(offsetof(CriManaSoundAtomVoice, field_274) == 0x274, "field_274");
static_assert(offsetof(CriManaSoundAtomVoice, field_278) == 0x278, "field_278");
static_assert(offsetof(CriManaSoundAtomVoice, field_27C) == 0x27C, "field_27C");
static_assert(offsetof(CriManaSoundAtomVoice, field_280) == 0x280, "field_280");
static_assert(offsetof(CriManaSoundAtomVoice, field_284) == 0x284, "field_284");
static_assert(offsetof(CriManaSoundAtomVoice, field_288) == 0x288, "field_288");
static_assert(offsetof(CriManaSoundAtomVoice, field_28C) == 0x28C, "field_28C");
static_assert(offsetof(CriManaSoundAtomVoice, field_290) == 0x290, "field_290");
static_assert(offsetof(CriManaSoundAtomVoice, field_298) == 0x298, "field_298");
static_assert(offsetof(CriManaSoundAtomVoice, field_2A0) == 0x2A0, "field_2A0");
static_assert(offsetof(CriManaSoundAtomVoice, field_2A8) == 0x2A8, "field_2A8");
static_assert(offsetof(CriManaSoundAtomVoice, field_2B0) == 0x2B0, "field_2B0");
static_assert(offsetof(CriManaSoundAtomVoice, field_2B8) == 0x2B8, "field_2B8");
static_assert(offsetof(CriManaSoundAtomVoice, embedded_array_2BC) == 0x2BC, "embedded_array_2BC");
static_assert(offsetof(CriManaSoundAtomVoice, field_37C) == 0x37C, "field_37C");

/* --- CriManaSoundAtomVoice_Float32 ----------------------------------------
 * Size: 0x3B0 PROVEN (s1 factory FUN_1400a9420(0x3b0,...,"CriManaSoundAtomVoice_Float32",8);
 * s2 shares identical subclass layout — no separate s2 factory found, CreateOutput operates
 * on existing object at RVA 0x7BD40). Inherits CriManaSoundAtomVoice; adds fields at 0x3A0, 0x3A8.
 */
typedef struct __attribute__((packed)) CriManaSoundAtomVoice_Float32 {
    CriManaSoundAtomVoice base;               /* 0x000-0x37F (base fields through 0x37C+4=0x380) */
    uint8_t  _pad_380[0x20];                  /* 0x380-0x39F: gap between base last field and subclass fields */
    /* 0x3A0 */ uint64_t field_3A0;           /* w medium — ctor: param_1[0x74]=0 */
    /* 0x3A8 */ uint64_t field_3A8;           /* w medium — ctor: param_1[0x75]=0 */
} CriManaSoundAtomVoice_Float32;

static_assert(sizeof(CriManaSoundAtomVoice_Float32) <= 0x3B0, "Float32 size <= proven 0x3B0");
static_assert(offsetof(CriManaSoundAtomVoice_Float32, field_3A0) == 0x3A0, "field_3A0");
static_assert(offsetof(CriManaSoundAtomVoice_Float32, field_3A8) == 0x3A8, "field_3A8");

/* --- CriManaFileReader ----------------------------------------------------
 * Size: 0x2B8 PROVEN (FUN_1400a9400(0x2b8, ..., "CriManaFileReader", 4) at RVA 0x7AC70).
 * Vtables extracted from inner ctor at RVA 0x7A990: [0] RVA 0x8B84C8, [1] RVA 0x8B8528.
 * 3 fields surfaced from state_surface; large interior gaps.
 * All fields PRES — file I/O handle state.
 */
typedef struct __attribute__((packed)) CriManaFileReader {
    /* 0x000 */ uint64_t vftable_0;           /* CriManaFileReader::vftable[0] @ RVA 0x8B84C8 */
    /* 0x008 */ uint64_t vftable_1;           /* CriManaFileReader::vftable[1] @ RVA 0x8B8528 */
    uint8_t  _pad_010[0xA0];                  /* 0x010-0x0AF: unsurfaced fields */
    /* 0x0B0 */ uint64_t field_0B0;           /* r medium — Destroy: FUN_1400121e8(param_1[0x16]) */
    uint8_t  _pad_0B8[0x188];                 /* 0x0B8-0x23F: gap */
    /* 0x240 */ uint8_t  vcall_or_field_240[8]; /* r low — Destroy: (**(code**)(*param_1+0x48))(param_1,1) */
    uint8_t  _pad_248[0x58];                  /* 0x248-0x29F: gap */
    /* 0x2A0 */ uint64_t field_2A0;           /* r medium — Destroy: FUN_1400121e8(param_1[0x54]) */
    uint8_t  _pad_2A8[0x10];                  /* 0x2A8-0x2B7: tail padding to proven size 0x2B8 */
} CriManaFileReader;

static_assert(sizeof(CriManaFileReader) == 0x2B8, "CriManaFileReader size == proven 0x2B8");
static_assert(offsetof(CriManaFileReader, vftable_0) == 0x000, "vftable_0");
static_assert(offsetof(CriManaFileReader, vftable_1) == 0x008, "vftable_1");
static_assert(offsetof(CriManaFileReader, field_0B0) == 0x0B0, "field_0B0");
static_assert(offsetof(CriManaFileReader, vcall_or_field_240) == 0x240, "vcall_or_field_240");
static_assert(offsetof(CriManaFileReader, field_2A0) == 0x2A0, "field_2A0");

/* --- CriManaSystemTimer ---------------------------------------------------
 * Size: 0x70 PROVEN (FUN_1400a9400(0x70, ..., "CriManaSystemTimer", 4) at RVA 0x7C1F0).
 * Internal layout partially visible from Create: fields at +0x10, +0x18, +0x20, +0x28,
 * +0x30, +0x38, +0x40, +0x50, +0x58, +0x60, +0x68, +0x6C.
 * All fields PRES — timer infrastructure, not simulation-coupled.
 */
typedef struct __attribute__((packed)) CriManaSystemTimer {
    uint8_t  _pad_000[0x10];                  /* 0x000-0x00F: vtable or unsurfaced base */
    /* 0x010 */ uint64_t field_010;           /* w — Create: *(u64*)(obj+0x10)=param_1 */
    /* 0x018 */ uint64_t field_018;           /* w — Create: *(u64*)(obj+0x18)=0 */
    /* 0x020 */ uint32_t field_020;           /* w — Create: *(u32*)(obj+0x20)=0 */
    uint8_t  _pad_024[4];                     /* alignment */
    /* 0x028 */ uint64_t field_028;           /* w — Create: *(u64*)(obj+0x28)=timer_handle */
    /* 0x030 */ uint32_t field_030;           /* w — Create: *(u32*)(obj+0x30)=FUN_14007d260() */
    uint8_t  _pad_034[4];                     /* alignment */
    /* 0x038 */ uint64_t field_038;           /* w — Create: *(u64*)(obj+0x38)=0 */
    /* 0x040 */ uint64_t field_040;           /* w — Create: *(u64*)(obj+0x40)=1 */
    /* 0x048 */ uint8_t  _pad_048[8];         /* gap to next proven field */
    /* 0x050 */ uint64_t field_050;           /* w — Create: *(u64*)(obj+0x50)=0 */
    /* 0x058 */ uint64_t field_058;           /* w — Create: *(u64*)(obj+0x58)=1 */
    /* 0x060 */ uint64_t field_060;           /* w — Create: *(u64*)(obj+0x60)=0 */
    /* 0x068 */ uint32_t field_068;           /* w — Create: *(u32*)(obj+0x68)=1 */
    /* 0x06C */ uint32_t field_06C;           /* w — Create: *(u32*)(obj+0x6c)=1 */
} CriManaSystemTimer;

static_assert(sizeof(CriManaSystemTimer) == 0x70, "CriManaSystemTimer size == proven 0x70");
static_assert(offsetof(CriManaSystemTimer, field_010) == 0x010, "field_010");
static_assert(offsetof(CriManaSystemTimer, field_018) == 0x018, "field_018");
static_assert(offsetof(CriManaSystemTimer, field_020) == 0x020, "field_020");
static_assert(offsetof(CriManaSystemTimer, field_028) == 0x028, "field_028");
static_assert(offsetof(CriManaSystemTimer, field_030) == 0x030, "field_030");
static_assert(offsetof(CriManaSystemTimer, field_038) == 0x038, "field_038");
static_assert(offsetof(CriManaSystemTimer, field_040) == 0x040, "field_040");
static_assert(offsetof(CriManaSystemTimer, field_050) == 0x050, "field_050");
static_assert(offsetof(CriManaSystemTimer, field_058) == 0x058, "field_058");
static_assert(offsetof(CriManaSystemTimer, field_060) == 0x060, "field_060");
static_assert(offsetof(CriManaSystemTimer, field_068) == 0x068, "field_068");
static_assert(offsetof(CriManaSystemTimer, field_06C) == 0x06C, "field_06C");

#endif /* LIBCRIMANA_S2_H */