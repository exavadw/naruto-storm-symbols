/*
 * libCriAtom struct layouts — NARUTO STORM 1 PC (NSUNS1.exe, s1)
 * Reconstructed from x64 decompilation. All offsets INFERRED from game code.
 * CRIWARE ADX2 Atom middleware — proprietary, no public SDK source used.
 * Rollback note: CRI sound state is PRES (untracked heap, threads not rewound).
 *
 * Build: s1 / NSUNS1.exe-a9fe00 / SHA 10231093af9c / image base 0x140000000
 */

#ifndef LIB_CRI_ATOM_S1_H
#define LIB_CRI_ATOM_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================= */
/* criAtomPlayer — global singleton module state                             */
/* These are scattered globals, not a contiguous heap object.                */
/* Modelled as a flat byte map for offset verification only.                */
/* Evidence: criAtomPlayer_Initialize (FUN_140015e10),                       */
/*           criAtomPlayer_Finalize (FUN_140015c00),                         */
/*           criAtomPlayer_ExecuteMain (FUN_140020684)                       */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomPlayerGlobals {
    uint8_t  _pad_000[0x388];          /* 0x000 - 0x387 */
    uint32_t init_flag;                /* 0x388 = DAT_1408de388 */
    int32_t  sample_rate;              /* 0x38c = DAT_1408de38c */
    uint8_t  _pad_390[0x8];            /* 0x390 - 0x397 */
    uint64_t allocator_handle;         /* 0x398 = DAT_1408de398 */
    uint8_t  _pad_3a0[0x630];          /* 0x3a0 - 0x9cf */
    uint64_t execute_handle;           /* 0x9d0 = DAT_1408de9d0 */
} CriAtomPlayerGlobals;

static_assert(offsetof(CriAtomPlayerGlobals, init_flag) == 0x388, "CriAtomPlayerGlobals.init_flag");
static_assert(offsetof(CriAtomPlayerGlobals, sample_rate) == 0x38c, "CriAtomPlayerGlobals.sample_rate");
static_assert(offsetof(CriAtomPlayerGlobals, allocator_handle) == 0x398, "CriAtomPlayerGlobals.allocator_handle");
static_assert(offsetof(CriAtomPlayerGlobals, execute_handle) == 0x9d0, "CriAtomPlayerGlobals.execute_handle");

/* ========================================================================= */
/* criAtomVoice — per-voice work buffer                                      */
/* Size proven: CalcWorkSize returns base + max_voices*0x48 + 0x70           */
/* Per-voice element stride: 0x24 (from Create loop plVar3+8..plVar3+0xb)   */
/* Evidence: criAtomVoice_Create (FUN_14002102c),                            */
/*           criAtomVoice_CalculateWorkSize (FUN_140020f5c)                  */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomVoice {
    uint64_t vtable_or_self;           /* 0x00 */
    uint64_t next_ptr;                 /* 0x08 */
    uint8_t  _pad_10[0x8];            /* 0x10 - 0x17 */
    float    volume;                   /* 0x18 = 1.0f (0x3f800000) */
    uint32_t voice_id;                 /* 0x1c — set after registration */
    uint8_t  voice_count;              /* 0x20 */
    uint8_t  _pad_21[0x2];            /* 0x21 - 0x22 */
    uint8_t  flags;                    /* 0x23 — bit 1 = registered */
    uint8_t  _pad_24[0x2c];           /* 0x24 - 0x4f */
    uint64_t config_ptr;               /* 0x50 — from param_2+6 */
    uint8_t  _pad_58[0x18];           /* 0x58 - 0x6f */
    /* Voice elements follow at +0x70, stride 0x24 each */
} CriAtomVoice;

static_assert(offsetof(CriAtomVoice, vtable_or_self) == 0x00, "CriAtomVoice.vtable_or_self");
static_assert(offsetof(CriAtomVoice, next_ptr) == 0x08, "CriAtomVoice.next_ptr");
static_assert(offsetof(CriAtomVoice, volume) == 0x18, "CriAtomVoice.volume");
static_assert(offsetof(CriAtomVoice, voice_id) == 0x1c, "CriAtomVoice.voice_id");
static_assert(offsetof(CriAtomVoice, voice_count) == 0x20, "CriAtomVoice.voice_count");
static_assert(offsetof(CriAtomVoice, flags) == 0x23, "CriAtomVoice.flags");
static_assert(offsetof(CriAtomVoice, config_ptr) == 0x50, "CriAtomVoice.config_ptr");

/* ========================================================================= */
/* criAtomParameter2 — linked-list node with parameter arrays                */
/* Work buffer allocated externally, aligned to 8 bytes                      */
/* Evidence: criAtomParameter2_Create (FUN_14002b9ac)                        */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomParameter2 {
    uint64_t vtable;                   /* 0x00 — &DAT_1408deda0 */
    uint64_t next;                     /* 0x08 — DAT_1408deda8 (list head) */
    uint8_t  _pad_10[0x4];            /* 0x10 - 0x13 */
    uint32_t param_4_field;            /* 0x14 — from param_4 */
    uint8_t  _pad_18[0x38];           /* 0x18 - 0x4f */
    uint8_t  byte_at_50;               /* 0x50 = 8 (constant in Create) */
    uint8_t  _pad_51[0x77];           /* 0x51 - 0xc7 */
    uint64_t array_end_ptr;            /* 0xc8 */
    uint64_t array_ptr;                /* 0xd0 */
    uint64_t array_mid_ptr;            /* 0xd8 — lVar1 + param_2*8 */
    uint8_t  param_2_byte;             /* 0xe0 */
    uint8_t  _pad_e1[0x1];            /* 0xe1 */
    uint8_t  param_3_byte;             /* 0xe2 */
} CriAtomParameter2;

static_assert(offsetof(CriAtomParameter2, vtable) == 0x00, "CriAtomParameter2.vtable");
static_assert(offsetof(CriAtomParameter2, next) == 0x08, "CriAtomParameter2.next");
static_assert(offsetof(CriAtomParameter2, param_4_field) == 0x14, "CriAtomParameter2.param_4_field");
static_assert(offsetof(CriAtomParameter2, byte_at_50) == 0x50, "CriAtomParameter2.byte_at_50");
static_assert(offsetof(CriAtomParameter2, array_end_ptr) == 0xc8, "CriAtomParameter2.array_end_ptr");
static_assert(offsetof(CriAtomParameter2, array_ptr) == 0xd0, "CriAtomParameter2.array_ptr");
static_assert(offsetof(CriAtomParameter2, array_mid_ptr) == 0xd8, "CriAtomParameter2.array_mid_ptr");
static_assert(offsetof(CriAtomParameter2, param_2_byte) == 0xe0, "CriAtomParameter2.param_2_byte");
static_assert(offsetof(CriAtomParameter2, param_3_byte) == 0xe2, "CriAtomParameter2.param_3_byte");

/* ========================================================================= */
/* criAtomCueSheet — work size constant 0xe88                                */
/* Evidence: criAtomCueSheet_Create (FUN_14004421c) returns 0xe88,           */
/*           criAtomCueSheet_AttachCue (FUN_1400441e4) field offsets         */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomCueSheet {
    uint8_t  _pad_0000[0xe10];        /* 0x0000 - 0xe0f */
    uint64_t cue_list_head;            /* 0xe10 */
    uint64_t cue_list_tail;            /* 0xe18 */
    uint32_t cue_count;                /* 0xe20 */
    uint8_t  _pad_e24[0x64];          /* 0xe24 - 0xe87 */
    /* Total size: 0xe88 (proven by Create return value) */
} CriAtomCueSheet;

static_assert(offsetof(CriAtomCueSheet, cue_list_head) == 0xe10, "CriAtomCueSheet.cue_list_head");
static_assert(offsetof(CriAtomCueSheet, cue_list_tail) == 0xe18, "CriAtomCueSheet.cue_list_tail");
static_assert(offsetof(CriAtomCueSheet, cue_count) == 0xe20, "CriAtomCueSheet.cue_count");
static_assert(sizeof(CriAtomCueSheet) == 0xe88, "CriAtomCueSheet size");

/* Cue node embedded in CueSheet: +0x0=self, +0x8=next (from AttachCue) */
typedef struct __attribute__((packed)) CriAtomCueNode {
    uint64_t self_ptr;                 /* 0x00 */
    uint64_t next_ptr;                 /* 0x08 */
} CriAtomCueNode;

static_assert(offsetof(CriAtomCueNode, self_ptr) == 0x00, "CriAtomCueNode.self_ptr");
static_assert(offsetof(CriAtomCueNode, next_ptr) == 0x08, "CriAtomCueNode.next_ptr");

/* ========================================================================= */
/* criAtomSequence — manager at DAT_1408df150                                */
/* Sub-object sizes from Initialize: track=0xd8, event=0x68, seq=0x190,     */
/*   channel=0x130, other=0x50/0x30/0x28                                    */
/* Evidence: criAtomSequence_Initialize (FUN_140032fb8),                     */
/*           criAtomSequence_Execute (FUN_14003284c),                        */
/*           criAtomSequence_CalculateWorkSize (FUN_140032808)               */
/*                                                                           */
/* NOTE: The early offsets (+0x04..+0x32) come from Ghidra treating the     */
/* manager as a qword array (puVar5[N]). The actual byte offsets depend on  */
/* whether those are qword or dword indices. Only the offsets confirmed by  */
/* Execute (+0x88, +0x90, +0x98, +0x100) and Init (+0x40, +0x42) are       */
/* reliable. The early list fields are modelled as an opaque block.         */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomSequenceManager {
    uint8_t  lists_block[0x40];        /* 0x00 - 0x3f: track/event/seq/chan/other lists (INFERRED layout, see note) */
    uint64_t timestamp;                /* 0x40 */
    uint32_t flag;                     /* 0x48 — set to 1 in Init (was +0x42 in qword-indexed decomp) */
    uint8_t  _pad_4c[0x3c];           /* 0x4c - 0x87 */
    uint64_t current_list_head;        /* 0x88 — confirmed in Execute */
    uint64_t current_list_tail;        /* 0x90 — confirmed in Execute */
    uint32_t current_list_count;       /* 0x98 — confirmed in Execute */
    uint8_t  _pad_9c[0x64];           /* 0x9c - 0xff */
    uint64_t timestamp_exec;           /* 0x100 — confirmed in Execute */
} CriAtomSequenceManager;

static_assert(offsetof(CriAtomSequenceManager, timestamp) == 0x40, "CriAtomSequenceManager.timestamp");
static_assert(offsetof(CriAtomSequenceManager, flag) == 0x48, "CriAtomSequenceManager.flag");
static_assert(offsetof(CriAtomSequenceManager, current_list_head) == 0x88, "CriAtomSequenceManager.current_list_head");
static_assert(offsetof(CriAtomSequenceManager, current_list_tail) == 0x90, "CriAtomSequenceManager.current_list_tail");
static_assert(offsetof(CriAtomSequenceManager, current_list_count) == 0x98, "CriAtomSequenceManager.current_list_count");
static_assert(offsetof(CriAtomSequenceManager, timestamp_exec) == 0x100, "CriAtomSequenceManager.timestamp_exec");

/* ========================================================================= */
/* criAtomSoundPlayer — linked-list node, size 0x88                          */
/* Evidence: criAtomSoundPlayer_Create (FUN_140048e28),                      */
/*           criAtomSoundPlayer_ExecuteMain (FUN_140048f30)                  */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomSoundPlayer {
    uint64_t self_ptr;                 /* 0x00 */
    uint64_t next_ptr;                 /* 0x08 — linked list */
    uint8_t  _pad_10[0x18];           /* 0x10 - 0x27 */
    uint64_t queue_head;               /* 0x28 */
    uint64_t queue_tail;               /* 0x30 */
    uint32_t queue_count;              /* 0x38 */
    uint8_t  _pad_3c[0x1c];           /* 0x3c - 0x57 */
    uint32_t id_or_flags;              /* 0x58 = 0xffffffff */
    uint16_t ushort_field;             /* 0x5c = 0 */
    uint8_t  byte_flag;                /* 0x5e — flag in Execute */
    uint8_t  _pad_5f[0x21];           /* 0x5f - 0x7f */
    uint64_t callback_or_config;       /* 0x80 */
    /* Total size: 0x88 (proven by Create: param_1 size arg = 0x88) */
} CriAtomSoundPlayer;

static_assert(offsetof(CriAtomSoundPlayer, self_ptr) == 0x00, "CriAtomSoundPlayer.self_ptr");
static_assert(offsetof(CriAtomSoundPlayer, next_ptr) == 0x08, "CriAtomSoundPlayer.next_ptr");
static_assert(offsetof(CriAtomSoundPlayer, queue_head) == 0x28, "CriAtomSoundPlayer.queue_head");
static_assert(offsetof(CriAtomSoundPlayer, queue_tail) == 0x30, "CriAtomSoundPlayer.queue_tail");
static_assert(offsetof(CriAtomSoundPlayer, queue_count) == 0x38, "CriAtomSoundPlayer.queue_count");
static_assert(offsetof(CriAtomSoundPlayer, id_or_flags) == 0x58, "CriAtomSoundPlayer.id_or_flags");
static_assert(offsetof(CriAtomSoundPlayer, ushort_field) == 0x5c, "CriAtomSoundPlayer.ushort_field");
static_assert(offsetof(CriAtomSoundPlayer, byte_flag) == 0x5e, "CriAtomSoundPlayer.byte_flag");
static_assert(offsetof(CriAtomSoundPlayer, callback_or_config) == 0x80, "CriAtomSoundPlayer.callback_or_config");
static_assert(sizeof(CriAtomSoundPlayer) == 0x88, "CriAtomSoundPlayer size");

/* ========================================================================= */
/* criAtomFader — size 0xb0                                                  */
/* Evidence: criAtomFader_Create (FUN_14002fab8)                             */
/* Note: decompiler shows puVar1+0x13 (=byte offset 0x98) and               */
/*       puVar1+0x14 (=byte offset 0xa0) but these are qword indices:       */
/*       0x13*8=0x98, 0x14*8=0xa0. Both hold uint32 value 500.              */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomFader {
    uint64_t handle_or_vtable;         /* 0x00 — set by FUN_1400a6f44 */
    uint8_t  _pad_08[0x90];           /* 0x08 - 0x97 */
    uint32_t fade_time_a;              /* 0x98 = 500 */
    uint8_t  _pad_9c[0x4];            /* 0x9c - 0x9f */
    uint32_t fade_time_b;              /* 0xa0 = 500 */
    uint8_t  _pad_a4[0xc];            /* 0xa4 - 0xaf */
    /* Total size: 0xb0 (proven by Create: FUN_14001263c(param_1, 0xb0)) */
} CriAtomFader;

static_assert(offsetof(CriAtomFader, handle_or_vtable) == 0x00, "CriAtomFader.handle_or_vtable");
static_assert(offsetof(CriAtomFader, fade_time_a) == 0x98, "CriAtomFader.fade_time_a");
static_assert(offsetof(CriAtomFader, fade_time_b) == 0xa0, "CriAtomFader.fade_time_b");
static_assert(sizeof(CriAtomFader) == 0xb0, "CriAtomFader size");

/* ========================================================================= */
/* criAtomDecoder — work buffer, variable size                               */
/* Base sizes from CalcWorkSize: channels<2 → 0xc0+0x90=0x150,              */
/*   channels==2 → 0xe0+0x90=0x170, channels>=3 → 0x1a0+0x90=0x230        */
/* With streaming buffers added when param_1[3]>0                           */
/* Evidence: criAtomDecoder_Create (FUN_140020498),                          */
/*           criAtomDecoder_CalculateWorkSize (FUN_14002041c)                */
/* Note: uVar7 = aligned work buffer. Fields written at byte offsets:        */
/*   +0x18 = config ptr, +0x20 = channels, +0x22 = stream flag,             */
/*   +0x23 = const 1, +0x24/+0x28 = buffer sizes, +0x30 = chan decoders,   */
/*   +0x58 = magic. But +0x20 was written as *(undefined1*)(uVar7+0x20)     */
/*   which is byte offset 0x20 from the aligned base.                       */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomDecoder {
    uint8_t  _pad_00[0x18];           /* 0x00 - 0x17 */
    uint64_t config_ptr;               /* 0x18 — from param_1+4 */
    uint8_t  _pad_20[0x0];            /* placeholder — next field is at byte 0x20 */
    uint8_t  channels_minus1;          /* 0x20 — from param_1+1 (byte write) */
    uint8_t  _pad_21[0x1];            /* 0x21 */
    uint8_t  stream_flag;              /* 0x22 — from param_1+3 */
    uint8_t  const_1;                  /* 0x23 = 1 */
    uint32_t buffer_size_words;        /* 0x24 — computed stream buf size */
    uint32_t buffer_size_words_dup;    /* 0x28 — same value */
    uint8_t  _pad_2c[0x4];            /* 0x2c - 0x2f */
    uint64_t channel_decoders[4];      /* 0x30 — 4 slots, stride varies */
    uint8_t  _pad_50[0x8];            /* 0x50 - 0x57 */
    uint32_t magic_4040404;            /* 0x58 = 0x4040404 */
} CriAtomDecoder;

static_assert(offsetof(CriAtomDecoder, config_ptr) == 0x18, "CriAtomDecoder.config_ptr");
static_assert(offsetof(CriAtomDecoder, channels_minus1) == 0x20, "CriAtomDecoder.channels_minus1");
static_assert(offsetof(CriAtomDecoder, stream_flag) == 0x22, "CriAtomDecoder.stream_flag");
static_assert(offsetof(CriAtomDecoder, const_1) == 0x23, "CriAtomDecoder.const_1");
static_assert(offsetof(CriAtomDecoder, buffer_size_words) == 0x24, "CriAtomDecoder.buffer_size_words");
static_assert(offsetof(CriAtomDecoder, buffer_size_words_dup) == 0x28, "CriAtomDecoder.buffer_size_words_dup");
static_assert(offsetof(CriAtomDecoder, channel_decoders) == 0x30, "CriAtomDecoder.channel_decoders");
static_assert(offsetof(CriAtomDecoder, magic_4040404) == 0x58, "CriAtomDecoder.magic_4040404");

/* ========================================================================= */
/* criAtomDbas — opaque handle, slot array at DAT_1408de3a0 (4 slots)       */
/* Internal struct: +0x0=config_copy, +0x8=sub_handle, +0x10=alloc_handle   */
/* Evidence: criAtomDbas_Create (FUN_140019714)                              */
/* Note: puVar3 is uint32*, so puVar3+2 = byte +0x8, puVar3+4 = byte +0x10 */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomDbas {
    uint32_t config_copy;              /* 0x00 — *param_1 copied here */
    uint8_t  _pad_04[0x4];            /* 0x04 - 0x07 */
    uint64_t sub_handle;               /* 0x08 — from FUN_1400189b8 */
    uint64_t alloc_handle;             /* 0x10 — local_88 from FUN_1400146b0 */
} CriAtomDbas;

static_assert(offsetof(CriAtomDbas, config_copy) == 0x00, "CriAtomDbas.config_copy");
static_assert(offsetof(CriAtomDbas, sub_handle) == 0x08, "CriAtomDbas.sub_handle");
static_assert(offsetof(CriAtomDbas, alloc_handle) == 0x10, "CriAtomDbas.alloc_handle");

/* ========================================================================= */
/* criAtomConfig — work size constant 0xd88                                  */
/* Evidence: criAtomConfig_CalculateWorkSize returns 0xd88                   */
/* Internal layout not reconstructed (no Create/Init decompiled with fields) */
/* ========================================================================= */

/* Size known (0xd88), internal fields unknown. Opaque. */
#define CRI_ATOM_CONFIG_WORK_SIZE 0xd88

/* ========================================================================= */
/* criAtomTimer — global singleton (scattered, not contiguous)               */
/* Evidence: criAtomTimer_Initialize (FUN_14002e710)                         */
/* ========================================================================= */

/* Not modelled as a struct — these are separate global addresses:
 *   DAT_1408defd0  init_count (uint32)
 *   DAT_1408defd4  counter (uint32)
 *   DAT_140857438  tick_rate (uint64)
 *   DAT_1408defd8  handle_a (uint64)
 *   DAT_1408defe0  handle_b (uint64)
 */

#endif /* LIB_CRI_ATOM_S1_H */