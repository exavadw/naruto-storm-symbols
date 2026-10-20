/* libCriMana.h — CRIWARE Sofdec/Mana video structs for Storm 4 PC 1.09 (s4, NSUNS4_release.exe-75912b)
 * Reconstructed from own-game decompilation only. All offsets INFERRED, not CONFIRMED.
 * CRIWARE is proprietary — no SDK source used.
 * Rollback: all CRI state tagged PRES unless code shows simulation dependency.
 * Image base: 0x140000000
 */
#ifndef LIBCRIMANA_S4_H
#define LIBCRIMANA_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ==========================================================================
 * Vtable addresses (RVA, image base 0x140000000)
 * Extracted from rip-relative LEA in constructors via raw byte disassembly.
 *
 * Inheritance chain (from ctor decompilation):
 *   CriMvSoundInterface          vftable[0] = RVA 0x12DBB58  (base-most, single vtable)
 *   CriAllocator                 vftable[0] = RVA 0x12DB200  (embedded at +8 in CriManaSound)
 *   CriManaSound               : CriMvSoundInterface
 *     vftable[0] = RVA 0x12DBBB8  vftable[1] = RVA 0x12DBC60
 *   CriManaSoundAtomVoice      : CriManaSound
 *     vftable[0] = RVA 0x12DBC78  vftable[1] = RVA 0x12DBD50
 *   CriManaSoundAtomVoice_Float32 : CriManaSoundAtomVoice (inherits vtables)
 *   CriManaFileReader            vftable[0] = RVA 0x12DD128  vftable[1] = RVA 0x12DB200
 * ========================================================================== */

/* --- CriManaSoundAtomVoice ------------------------------------------------
 * Size: unknown, >= 0x380 (last field field_37C ends at 0x380).
 * Subclass CriManaSoundAtomVoice_Float32 size 0x3B0 proven in s1 factory;
 * NOT re-proven in s4 (no factory symbol found). Carried forward as upper bound.
 * Constructor at RVA 0x703C0 calls base ctor FUN_140070370 then sets vtables and fields.
 * Vtables extracted from LEA at ctor+0x18 (0x12DBC78) and ctor+0x27 (0x12DBD50).
 * All fields PRES — CRI audio playback state, not simulation-coupled.
 */
typedef struct __attribute__((packed)) CriManaSoundAtomVoice {
    /* 0x000 */ uint64_t vftable_0;           /* CriManaSoundAtomVoice::vftable[0] @ RVA 0x12DBC78 */
    /* 0x008 */ uint64_t vftable_1;           /* CriManaSoundAtomVoice::vftable[1] @ RVA 0x12DBD50 */
    /* 0x010 */ uint8_t  _pad_010[0x50];      /* 0x010-0x05F: inherited CriManaSound/CriMvSoundInterface/CriAllocator fields (not surfaced) */
    /* 0x060 */ uint64_t field_060;           /* w medium — ctor: param_1[0xc]=0 */
    /* 0x068 */ uint8_t  embedded_array_068[0x138]; /* r low — FUN_140012640(param_1+0xd, 0x138) memset zero */
    /* 0x1A0 */ uint8_t  embedded_array_1A0[0x18];  /* r low — FUN_140012640(param_1+0x34, 0x18) */
    /* 0x1B8 */ uint64_t field_1B8;           /* rw high — param_1[0x37]=0 */
    /* 0x1C0 */ uint8_t  embedded_array_1C0[0x60];  /* r low — FUN_140012640(param_1+0x38, 0x60); also vcall site */
    /* 0x220 */ uint64_t field_220;           /* rw high — param_1[0x44]=0 */
    /* 0x228 */ uint64_t field_228;           /* w medium — ctor: param_1[0x45]=0 */
    /* 0x230 */ uint8_t  embedded_array_230[0x10];  /* r low — FUN_140012640(param_1+0x46, 0x10) */
    /* 0x240 */ uint32_t field_240;           /* rw high — *(u32*)(param_1+0x48)=0 */
    /* 0x244 */ uint32_t field_244_count;     /* rw high — loop bound: for(i=0; i<*(u32*)(param_1+0x244); i++) */
    /* 0x248 */ uint32_t field_248;           /* rw high — *(u32*)(param_1+0x49)=0 */
    /* 0x24C */ uint8_t  _pad_24C[4];         /* alignment padding */
    /* 0x250 */ uint64_t field_250;           /* w medium — ctor: param_1[0x4a]=0 */
    /* 0x258 */ uint64_t field_258;           /* w medium — ctor: param_1[0x4b]=0 */
    /* 0x260 */ uint32_t field_260;           /* rw high — *(u32*)(param_1+0x4c)=0 */
    /* 0x264 */ uint32_t field_264_size;      /* rw high — FUN_140012640(local_38, *(u32*)(param_1+0x264)) */
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
    /* 0x2BC */ uint8_t  embedded_array_2BC[0xC0]; /* from ctor: FUN_140012640(param_1+700, 0xc0) */
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
 * Size: <= 0x3B0 (carried from s1 factory proof; NOT re-proven in s4).
 * No separate Float32 constructor or factory found in s4 symbols.
 * Inherits CriManaSoundAtomVoice; adds fields at 0x3A0, 0x3A8.
 */
typedef struct __attribute__((packed)) CriManaSoundAtomVoice_Float32 {
    CriManaSoundAtomVoice base;               /* 0x000-0x37F (base fields through 0x37C+4=0x380) */
    uint8_t _pad_380[0x20];                   /* 0x380-0x39F: gap between base last field and subclass fields */
    /* 0x3A0 */ uint64_t field_3A0;           /* w medium — carried from s3 layout */
    /* 0x3A8 */ uint64_t field_3A8;           /* w medium — carried from s3 layout */
} CriManaSoundAtomVoice_Float32;

static_assert(sizeof(CriManaSoundAtomVoice_Float32) <= 0x3B0, "Float32 size <= carried 0x3B0");
static_assert(offsetof(CriManaSoundAtomVoice_Float32, field_3A0) == 0x3A0, "field_3A0");
static_assert(offsetof(CriManaSoundAtomVoice_Float32, field_3A8) == 0x3A8, "field_3A8");

/* --- CriManaFileReader ----------------------------------------------------
 * Size: 0x2B8 PROVEN (FUN_1400a9a90(0x2b8, ..., "CriManaFileReader", 4) at RVA 0x7B2F0).
 * Vtables extracted from inner ctors:
 *   [0] RVA 0x12DD128 (FUN_14007b060 LEA at 0x14007b06a)
 *   [1] RVA 0x12DB200 (FUN_14006b3c0 LEA at 0x14006b3c0, shared with CriAllocator)
 * Fields surfaced from Create (RVA 0x7B2F0) and Destroy (RVA 0x7B580) decompilation.
 * All fields PRES — file I/O handle state.
 */
typedef struct __attribute__((packed)) CriManaFileReader {
    /* 0x000 */ uint64_t vftable_0;           /* CriManaFileReader::vftable[0] @ RVA 0x12DD128 */
    /* 0x008 */ uint64_t vftable_1;           /* CriManaFileReader::vftable[1] @ RVA 0x12DB200 */
    /* 0x010 */ uint64_t field_010_param;     /* w — Create: local_28[2] = param_1 */
    uint8_t _pad_018[0x08];                   /* 0x018-0x01F: gap */
    /* 0x020 */ uint64_t field_020_io_state;  /* w — Create: FUN_14000698c(local_28 + 4) */
    /* 0x028 */ int64_t  field_028_neg1;      /* w — Create: local_28[5] = -1 */
    /* 0x030 */ uint64_t field_030_zero;      /* w — Create: local_28[6] = 0 */
    /* 0x038 */ uint64_t field_038_zero;      /* w — Create: local_28[7] = 0 */
    /* 0x040 */ uint64_t field_040_zero;      /* w — Create: local_28[8] = 0 */
    uint8_t _pad_048[0x68];                   /* 0x048-0x0AF: gap to next proven field */
    /* 0x0B0 */ uint64_t field_0B0_handle;    /* rw — Create: local_28[0x16]=buf; Destroy: FUN_1400121ec(param_1[0x16]) */
    uint8_t _pad_0B8[0x19C];                  /* 0x0B8-0x253: gap (includes memset region at 0x0D0-0x24F) */
    /* 0x254 */ uint8_t  embedded_array_254[0x48]; /* rw — Create: FUN_140012194(local_28+0x254, 0x48) */
    uint8_t _pad_29C[0x04];                   /* 0x29C-0x29F: gap */
    /* 0x2A0 */ uint64_t field_2A0_handle;    /* rw — Create: local_28[0x54]=buf; Destroy: FUN_1400121ec(param_1[0x54]) */
    uint8_t _pad_2A8[0x10];                   /* 0x2A8-0x2B7: tail padding to proven size 0x2B8 */
} CriManaFileReader;

static_assert(sizeof(CriManaFileReader) == 0x2B8, "CriManaFileReader size == proven 0x2B8");
static_assert(offsetof(CriManaFileReader, vftable_0) == 0x000, "vftable_0");
static_assert(offsetof(CriManaFileReader, vftable_1) == 0x008, "vftable_1");
static_assert(offsetof(CriManaFileReader, field_010_param) == 0x010, "field_010_param");
static_assert(offsetof(CriManaFileReader, field_020_io_state) == 0x020, "field_020_io_state");
static_assert(offsetof(CriManaFileReader, field_028_neg1) == 0x028, "field_028_neg1");
static_assert(offsetof(CriManaFileReader, field_030_zero) == 0x030, "field_030_zero");
static_assert(offsetof(CriManaFileReader, field_038_zero) == 0x038, "field_038_zero");
static_assert(offsetof(CriManaFileReader, field_040_zero) == 0x040, "field_040_zero");
static_assert(offsetof(CriManaFileReader, field_0B0_handle) == 0x0B0, "field_0B0_handle");
static_assert(offsetof(CriManaFileReader, embedded_array_254) == 0x254, "embedded_array_254");
static_assert(offsetof(CriManaFileReader, field_2A0_handle) == 0x2A0, "field_2A0_handle");

/* --- CriManaSystemTimer ---------------------------------------------------
 * Size: 0x70 PROVEN (FUN_1400a9a90(0x70, ..., "CriManaSystemTimer", 4) at RVA 0x7C870).
 * Internal layout fully visible from Create: fields at +0x10 through +0x6C.
 * All fields PRES — timer infrastructure, not simulation-coupled.
 */
typedef struct __attribute__((packed)) CriManaSystemTimer {
    uint8_t _pad_000[0x10];                   /* 0x000-0x00F: vtable or unsurfaced base */
    /* 0x010 */ uint64_t field_010;           /* w — Create: *(u64*)(obj+0x10)=param_1 */
    /* 0x018 */ uint64_t field_018;           /* w — Create: *(u64*)(obj+0x18)=0 */
    /* 0x020 */ uint32_t field_020;           /* w — Create: *(u32*)(obj+0x20)=0 */
    uint8_t _pad_024[4];                      /* alignment */
    /* 0x028 */ uint64_t field_028_timer_handle; /* w — Create: *(u64*)(obj+0x28)=FUN_1400a9054(...) */
    /* 0x030 */ uint32_t field_030;           /* w — Create: *(u32*)(obj+0x30)=FUN_14007d8f0() */
    uint8_t _pad_034[4];                      /* alignment */
    /* 0x038 */ uint64_t field_038;           /* w — Create: *(u64*)(obj+0x38)=0 */
    /* 0x040 */ uint64_t field_040;           /* w — Create: *(u64*)(obj+0x40)=1 */
    uint8_t _pad_048[8];                      /* gap to next proven field */
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
static_assert(offsetof(CriManaSystemTimer, field_028_timer_handle) == 0x028, "field_028_timer_handle");
static_assert(offsetof(CriManaSystemTimer, field_030) == 0x030, "field_030");
static_assert(offsetof(CriManaSystemTimer, field_038) == 0x038, "field_038");
static_assert(offsetof(CriManaSystemTimer, field_040) == 0x040, "field_040");
static_assert(offsetof(CriManaSystemTimer, field_050) == 0x050, "field_050");
static_assert(offsetof(CriManaSystemTimer, field_058) == 0x058, "field_058");
static_assert(offsetof(CriManaSystemTimer, field_060) == 0x060, "field_060");
static_assert(offsetof(CriManaSystemTimer, field_068) == 0x068, "field_068");
static_assert(offsetof(CriManaSystemTimer, field_06C) == 0x06C, "field_06C");

#endif /* LIBCRIMANA_S4_H */