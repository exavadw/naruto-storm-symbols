/* cmn83.h — CriManaSoundAtomVoice / CriManaSoundAtomVoice_Float32 (s2, INFERRED)
 * Build: s2 (NSUNS2.exe, sha 697488011750...)
 * All layouts are INFERRED from static decompilation; not CONFIRMED at runtime.
 * Object size proven by CriAllocator::operator_new(0x3b0, ...) in factory at 0x707F0.
 */
#ifndef CMN83_H
#define CMN83_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---- CriManaSoundAtomVoice ---- */
/* Size proven: 0x3B0 via CriAllocator::operator_new in factory FUN_1400707F0 */
typedef struct __attribute__((packed)) CriManaSoundAtomVoice {
    /* 0x000 */ void *vftable;
    /* 0x008 */ void *vftable2;           /* second vtable ptr (dual-vtable layout) */
    /* 0x010 */ uint64_t field_0x10;      /* zeroed in ctor (param_1[2]=0) */
    /* 0x018 */ uint8_t gap_0x18[0x48];   /* criCrw_MemClear(param_1+3, 0x48): 0x18..0x5F */
    /* 0x060 */ uint64_t output_handle;   /* written in CreateOutput, ctor */
    /* 0x068 */ uint8_t gap_0x68[0x138];  /* criCrw_MemClear(param_1+0xd, 0x138): 0x68..0x19F */
    /* 0x1A0 */ uint64_t field_0x1A0;     /* read in ctor */
    /* 0x1A8 */ uint8_t gap_0x1A8[0x10];  /* padding to next known field */
    /* 0x1B8 */ uint64_t sound_renderer_type; /* rw: SetSoundRendererType, ctor */
    /* 0x1C0 */ uint64_t field_0x1C0;     /* read in ctor/GetPan */
    /* 0x1C8 */ uint8_t gap_0x1C8[0x58];  /* padding */
    /* 0x220 */ uint64_t pause_state;     /* rw: Pause, ctor */
    /* 0x228 */ uint64_t field_0x228;     /* write-only in ctor */
    /* 0x230 */ uint64_t field_0x230;     /* read in ctor */
    /* 0x238 */ uint8_t gap_0x238[0x8];   /* padding */
    /* 0x240 */ uint32_t status_code;     /* rw: SubmitOnePacket writes 0x4000a */
    /* 0x244 */ uint32_t num_channels;    /* rw: SetSoundRendererType loop bound, CreateOutput */
    /* 0x248 */ uint32_t field_0x248;     /* rw: Pause, ctor (param_1[0x49]) */
    /* 0x24C */ uint8_t gap_0x24C[0x4];   /* padding */
    /* 0x250 */ uint64_t field_0x250;     /* write-only in ctor */
    /* 0x258 */ uint64_t field_0x258;     /* write-only in ctor */
    /* 0x260 */ uint32_t field_0x260;     /* rw: SetSoundRendererType */
    /* 0x264 */ uint32_t send_level_count; /* rw: SetSoundRendererType MemClear size */
    /* 0x268 */ uint32_t field_0x268;     /* write-only in ctor */
    /* 0x26C */ uint32_t field_0x26C;     /* write-only in ctor, init=1 */
    /* 0x270 */ uint32_t field_0x270;     /* write-only in ctor */
    /* 0x274 */ uint32_t field_0x274;     /* write-only in ctor, init=0x3f800000 (1.0f) */
    /* 0x278 */ uint32_t field_0x278;     /* write-only in ctor */
    /* 0x27C */ uint32_t field_0x27C;     /* write-only in ctor */
    /* 0x280 */ uint32_t field_0x280;     /* write-only in ctor */
    /* 0x284 */ uint32_t field_0x284;     /* write-only in ctor */
    /* 0x288 */ uint32_t atom_voice_handle; /* rw: CalculateOutputWorkSize, CreateOutput */
    /* 0x28C */ uint32_t field_0x28C;     /* write-only in ctor */
    /* 0x290 */ uint32_t field_0x290;     /* write-only in ctor */
    /* 0x294 */ uint8_t gap_0x294[0x4];   /* padding */
    /* 0x298 */ uint64_t field_0x298;     /* rw: Pause, ctor */
    /* 0x2A0 */ uint64_t field_0x2A0;     /* write-only in ctor */
    /* 0x2A8 */ uint64_t field_0x2A8;     /* rw: Pause, ctor */
    /* 0x2B0 */ uint64_t field_0x2B0;     /* write-only in ctor */
    /* 0x2B8 */ uint32_t field_0x2B8;     /* write-only in ctor */
    /* 0x2BC */ uint8_t gap_0x2BC[0xC0];  /* criCrw_MemClear(param_1+700, 0xc0): 0x2BC..0x37B */
    /* 0x37C */ uint32_t field_0x37C;     /* write-only in ctor, init=0x3f800000 (1.0f) */
} CriManaSoundAtomVoice;

static_assert(sizeof(CriManaSoundAtomVoice) == 0x380, "CriManaSoundAtomVoice base size");
static_assert(offsetof(CriManaSoundAtomVoice, vftable) == 0x000, "vftable");
static_assert(offsetof(CriManaSoundAtomVoice, vftable2) == 0x008, "vftable2");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x10) == 0x010, "field_0x10");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x18) == 0x018, "gap_0x18");
static_assert(offsetof(CriManaSoundAtomVoice, output_handle) == 0x060, "output_handle");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x68) == 0x068, "gap_0x68");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x1A0) == 0x1A0, "field_0x1A0");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x1A8) == 0x1A8, "gap_0x1A8");
static_assert(offsetof(CriManaSoundAtomVoice, sound_renderer_type) == 0x1B8, "sound_renderer_type");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x1C0) == 0x1C0, "field_0x1C0");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x1C8) == 0x1C8, "gap_0x1C8");
static_assert(offsetof(CriManaSoundAtomVoice, pause_state) == 0x220, "pause_state");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x228) == 0x228, "field_0x228");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x230) == 0x230, "field_0x230");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x238) == 0x238, "gap_0x238");
static_assert(offsetof(CriManaSoundAtomVoice, status_code) == 0x240, "status_code");
static_assert(offsetof(CriManaSoundAtomVoice, num_channels) == 0x244, "num_channels");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x248) == 0x248, "field_0x248");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x24C) == 0x24C, "gap_0x24C");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x250) == 0x250, "field_0x250");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x258) == 0x258, "field_0x258");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x260) == 0x260, "field_0x260");
static_assert(offsetof(CriManaSoundAtomVoice, send_level_count) == 0x264, "send_level_count");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x268) == 0x268, "field_0x268");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x26C) == 0x26C, "field_0x26C");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x270) == 0x270, "field_0x270");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x274) == 0x274, "field_0x274");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x278) == 0x278, "field_0x278");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x27C) == 0x27C, "field_0x27C");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x280) == 0x280, "field_0x280");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x284) == 0x284, "field_0x284");
static_assert(offsetof(CriManaSoundAtomVoice, atom_voice_handle) == 0x288, "atom_voice_handle");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x28C) == 0x28C, "field_0x28C");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x290) == 0x290, "field_0x290");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x294) == 0x294, "gap_0x294");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x298) == 0x298, "field_0x298");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x2A0) == 0x2A0, "field_0x2A0");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x2A8) == 0x2A8, "field_0x2A8");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x2B0) == 0x2B0, "field_0x2B0");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x2B8) == 0x2B8, "field_0x2B8");
static_assert(offsetof(CriManaSoundAtomVoice, gap_0x2BC) == 0x2BC, "gap_0x2BC");
static_assert(offsetof(CriManaSoundAtomVoice, field_0x37C) == 0x37C, "field_0x37C");

/* ---- CriManaSoundAtomVoice_Float32 ---- */
/* Inherits CriManaSoundAtomVoice. Alloc size 0x3B0 proven in factory FUN_1400707F0.
 * Extended fields at 0x3A0 and 0x3A8 from SetCallbackGetFloat32PcmData.
 * Ctor also writes param_1[0x74]=0 (0x3A0) and param_1[0x75]=0 (0x3A8). */
typedef struct __attribute__((packed)) CriManaSoundAtomVoice_Float32 {
    CriManaSoundAtomVoice base;          /* 0x000..0x37F */
    /* 0x380 */ uint8_t gap_0x380[0x20]; /* reserved between base tail and callback fields */
    /* 0x3A0 */ void *callback_float32_pcm; /* SetCallbackGetFloat32PcmData param_3 */
    /* 0x3A8 */ void *callback_userdata;    /* SetCallbackGetFloat32PcmData param_2 */
} CriManaSoundAtomVoice_Float32;

static_assert(sizeof(CriManaSoundAtomVoice_Float32) == 0x3B0, "CriManaSoundAtomVoice_Float32 total size matches alloc");
static_assert(offsetof(CriManaSoundAtomVoice_Float32, callback_float32_pcm) == 0x3A0, "callback_float32_pcm");
static_assert(offsetof(CriManaSoundAtomVoice_Float32, callback_userdata) == 0x3A8, "callback_userdata");

#endif /* CMN83_H */