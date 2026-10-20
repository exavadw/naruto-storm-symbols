/*
 * libCriAtom struct layouts — NARUTO STORM 2 PC (NSUNS2.exe, s2)
 * Reconstructed from x64 decompilation. All offsets INFERRED from game code.
 * CRIWARE ADX2 Atom middleware — proprietary, no public SDK source used.
 * Rollback note: CRI sound state is PRES (untracked heap, threads not rewound).
 *
 * Build: s2 / NSUNS2.exe-abf2b6 / SHA 69748801175096afefb7f00eadba24eb6e6616c44924237f43bb428f0a42150e
 * Image base: 0x140000000
 */

#ifndef LIB_CRI_ATOM_S2_H
#define LIB_CRI_ATOM_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================= */
/* criAtomPlayer — work buffer created by criAtomPlayer_CreateInternal       */
/* Size NOT proven from a single constant; fields extracted from             */
/* FUN_140016918 (the real Create after wrapper at 0x158BC).                 */
/* Highest proven write: +0x2f0 (variable_data_start).                       */
/* Evidence: FUN_140016918 (RVA 0x16918)                                    */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomPlayer {
    uint8_t  _pad_00[0x08];            /* 0x00 - 0x07 */
    uint32_t config_flags;             /* 0x08 */
    uint8_t  _pad_0c[0x2c];            /* 0x0c - 0x37 */
    uint64_t embedded_subobj;          /* 0x38 */
    uint8_t  _pad_40[0x58];            /* 0x40 - 0x97 */
    uint64_t subobj_handle;            /* 0x98 */
    uint64_t voice_mgr_ptr;            /* 0xa0 */
    uint8_t  _pad_a8[0x60];            /* 0xa8 - 0x107 */
    uint64_t loop_subobj_a;            /* 0x108 */
    uint8_t  _pad_110[0x60];           /* 0x110 - 0x16f */
    uint64_t loop_ptr_a;               /* 0x170 */
    uint64_t loop_ptr_b;               /* 0x178 */
    uint64_t voice_ptr;                /* 0x180 */
    uint8_t  _pad_188[0x4];            /* 0x188 - 0x18b */
    uint8_t  flag_byte;                /* 0x18c = 1 */
    uint8_t  _pad_18d[0xbb];           /* 0x18d - 0x247 */
    float    float_one;                /* 0x248 = 1.0f */
    uint8_t  _pad_24c[0xc];            /* 0x24c - 0x257 */
    uint32_t sentinel_ff;              /* 0x258 = 0xffffffff */
    uint8_t  _pad_25c[0x94];           /* 0x25c - 0x2ef */
    uint64_t variable_data_start;      /* 0x2f0 */
    /* Size unknown, >= 0x2f8. No allocator size constant found. */
} CriAtomPlayer;

static_assert(offsetof(CriAtomPlayer, config_flags) == 0x08, "CriAtomPlayer.config_flags");
static_assert(offsetof(CriAtomPlayer, embedded_subobj) == 0x38, "CriAtomPlayer.embedded_subobj");
static_assert(offsetof(CriAtomPlayer, subobj_handle) == 0x98, "CriAtomPlayer.subobj_handle");
static_assert(offsetof(CriAtomPlayer, voice_mgr_ptr) == 0xa0, "CriAtomPlayer.voice_mgr_ptr");
static_assert(offsetof(CriAtomPlayer, loop_subobj_a) == 0x108, "CriAtomPlayer.loop_subobj_a");
static_assert(offsetof(CriAtomPlayer, loop_ptr_a) == 0x170, "CriAtomPlayer.loop_ptr_a");
static_assert(offsetof(CriAtomPlayer, loop_ptr_b) == 0x178, "CriAtomPlayer.loop_ptr_b");
static_assert(offsetof(CriAtomPlayer, voice_ptr) == 0x180, "CriAtomPlayer.voice_ptr");
static_assert(offsetof(CriAtomPlayer, flag_byte) == 0x18c, "CriAtomPlayer.flag_byte");
static_assert(offsetof(CriAtomPlayer, float_one) == 0x248, "CriAtomPlayer.float_one");
static_assert(offsetof(CriAtomPlayer, sentinel_ff) == 0x258, "CriAtomPlayer.sentinel_ff");
static_assert(offsetof(CriAtomPlayer, variable_data_start) == 0x2f0, "CriAtomPlayer.variable_data_start");

/* ========================================================================= */
/* criAtomConfig — work size constant 0xd88                                  */
/* Evidence: criAtomConfig_CalculateWorkSize (FUN_14003a620) returns 0xd88   */
/* Internal layout not reconstructed (opaque).                               */
/* ========================================================================= */

#define CRI_ATOM_CONFIG_WORK_SIZE_S2 0xd88

/* ========================================================================= */
/* criAtomCueSheet — work size constant 0xe88                                */
/* Evidence: criAtomCueSheet_CalculateWorkSize (FUN_14004427c) returns 0xe88 */
/* Fields from criAtomCueSheet_Create (FUN_14004429c), piVar1 as int* (x4).  */
/* Highest proven write: +0xe38 (piVar1[0x38e]).                             */
/* Global instance counter: DAT_147e63300                                    */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomCueSheet {
    uint8_t  _pad_0000[0xdb8];         /* 0x0000 - 0xdb7 */
    uint32_t field_db8;                /* 0xdb8 = 0 (piVar1[0x36e]) */
    uint32_t field_dbc;                /* 0xdbc = 0 (piVar1[0x36f]) */
    uint64_t ptr_to_e40;               /* 0xdc0 = ptr to +0xe40 (piVar1[0x370]) */
    uint8_t  _pad_dc8[0x64];           /* 0xdc8 - 0xe2b */
    uint32_t field_e2c;                /* 0xe2c = 0 (piVar1[899]) */
    uint8_t  _pad_e30[0x8];            /* 0xe30 - 0xe37 */
    uint32_t field_e38;                /* 0xe38 = 0 (piVar1[0x38e]) */
    uint8_t  _pad_e3c[0x4c];           /* 0xe3c - 0xe87 */
    /* Total size: 0xe88 (proven by CalculateWorkSize) */
} CriAtomCueSheet;

static_assert(offsetof(CriAtomCueSheet, field_db8) == 0xdb8, "CriAtomCueSheet.field_db8");
static_assert(offsetof(CriAtomCueSheet, field_dbc) == 0xdbc, "CriAtomCueSheet.field_dbc");
static_assert(offsetof(CriAtomCueSheet, ptr_to_e40) == 0xdc0, "CriAtomCueSheet.ptr_to_e40");
static_assert(offsetof(CriAtomCueSheet, field_e2c) == 0xe2c, "CriAtomCueSheet.field_e2c");
static_assert(offsetof(CriAtomCueSheet, field_e38) == 0xe38, "CriAtomCueSheet.field_e38");
static_assert(sizeof(CriAtomCueSheet) == 0xe88, "CriAtomCueSheet size");

/* ========================================================================= */
/* criAtomVoice — per-voice work buffer, variable size                       */
/* Size: >= 0x70 + max_voices * 0x24                                         */
/* Evidence: criAtomVoice_Create (FUN_140020fa0), plVar3 as longlong* (x8)   */
/* Per-voice elements at plVar3+0xb (= byte +0x58), stride 0x24              */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomVoice {
    uint64_t vtable_or_self;           /* 0x00 -- FUN_14004fc18 result */
    uint64_t next_ptr;                 /* 0x08 -- linked list */
    uint8_t  _pad_10[0x8];            /* 0x10 - 0x17 */
    float    volume;                   /* 0x18 = 1.0f (plVar3+3) */
    uint32_t voice_id;                 /* 0x1c */
    uint8_t  voice_count;              /* 0x20 */
    uint8_t  _pad_21[0x2];            /* 0x21 - 0x22 */
    uint8_t  flags;                    /* 0x23 -- bit 1 = registered */
    uint8_t  _pad_24[0x2c];           /* 0x24 - 0x4f */
    uint64_t config_ptr;               /* 0x50 -- plVar3[10] */
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
/* criAtomFader — size 0xb0                                                  */
/* Evidence: criAtomFader_Create (FUN_14002fb30)                             */
/* Calls FUN_140012430(param_1, 0xb0). param_1 as longlong*:                */
/*   +0x00 = handle (FUN_1400a6f24 result)                                  */
/*   +0x98 = fade_time_a (500, index 0x13 x 8)                              */
/*   +0xa0 = fade_time_b (500, index 0x14 x 8)                              */
/* Globals: DAT_147e62ec4 (counter), DAT_147e62ef0, DAT_147e62ef4           */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomFader {
    uint64_t handle_or_vtable;         /* 0x00 -- FUN_1400a6f24 result */
    uint8_t  _pad_08[0x90];           /* 0x08 - 0x97 */
    uint32_t fade_time_a;              /* 0x98 = 500 */
    uint8_t  _pad_9c[0x4];            /* 0x9c - 0x9f */
    uint32_t fade_time_b;              /* 0xa0 = 500 */
    uint8_t  _pad_a4[0xc];            /* 0xa4 - 0xaf */
    /* Total size: 0xb0 (proven by Create allocator call) */
} CriAtomFader;

static_assert(offsetof(CriAtomFader, handle_or_vtable) == 0x00, "CriAtomFader.handle_or_vtable");
static_assert(offsetof(CriAtomFader, fade_time_a) == 0x98, "CriAtomFader.fade_time_a");
static_assert(offsetof(CriAtomFader, fade_time_b) == 0xa0, "CriAtomFader.fade_time_b");
static_assert(sizeof(CriAtomFader) == 0xb0, "CriAtomFader size");

/* ========================================================================= */
/* criAtomSoundPlayer — linked-list node, size 0x88                          */
/* Evidence: criAtomSoundPlayer_Create (FUN_140048e88)                       */
/* Calls FUN_140012430(param_2, 0x88). param_2 as undefined8*:              */
/*   +0x00 = self_ptr                                                        */
/*   +0x08 = next_ptr (linked list via DAT_147e63640/648)                   */
/*   +0x58 = id_or_flags (0xffffffff)                                        */
/*   +0x5c = ushort_field (0)                                                */
/*   +0x80 = callback_or_config                                              */
/* Globals: DAT_147e63640 (head), DAT_147e63648 (tail), _DAT_147e63650 (cnt)*/
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomSoundPlayer {
    uint64_t self_ptr;                 /* 0x00 */
    uint64_t next_ptr;                 /* 0x08 -- linked list */
    uint8_t  _pad_10[0x48];           /* 0x10 - 0x57 */
    uint32_t id_or_flags;              /* 0x58 = 0xffffffff */
    uint16_t ushort_field;             /* 0x5c = 0 */
    uint8_t  _pad_5e[0x22];           /* 0x5e - 0x7f */
    uint64_t callback_or_config;       /* 0x80 */
    /* Total size: 0x88 (proven by Create allocator call) */
} CriAtomSoundPlayer;

static_assert(offsetof(CriAtomSoundPlayer, self_ptr) == 0x00, "CriAtomSoundPlayer.self_ptr");
static_assert(offsetof(CriAtomSoundPlayer, next_ptr) == 0x08, "CriAtomSoundPlayer.next_ptr");
static_assert(offsetof(CriAtomSoundPlayer, id_or_flags) == 0x58, "CriAtomSoundPlayer.id_or_flags");
static_assert(offsetof(CriAtomSoundPlayer, ushort_field) == 0x5c, "CriAtomSoundPlayer.ushort_field");
static_assert(offsetof(CriAtomSoundPlayer, callback_or_config) == 0x80, "CriAtomSoundPlayer.callback_or_config");
static_assert(sizeof(CriAtomSoundPlayer) == 0x88, "CriAtomSoundPlayer size");

/* ========================================================================= */
/* criAtomDecoder — variable-size work buffer                                */
/* Base sizes from CalcWorkSize (FUN_140020390):                             */
/*   channels < 2 -> 0xc0, < 3 -> 0xe0, else -> 0x1a0                      */
/*   non-streaming: base + 0x90                                              */
/*   streaming: complex formula + 0x98 + base                                */
/* Evidence: criAtomDecoder_Create (FUN_14002040c), uVar7 = aligned buffer   */
/* Channel decoder sub-objects via FUN_1400a3834/a3858/a387c                 */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomDecoder {
    uint8_t  _pad_00[0x18];           /* 0x00 - 0x17 */
    uint64_t config_ptr;               /* 0x18 -- from param_1+4 */
    uint8_t  channels_minus1;          /* 0x20 -- from param_1+1 (byte) */
    uint8_t  _pad_21[0x1];            /* 0x21 */
    uint8_t  stream_flag;              /* 0x22 -- from param_1+3 */
    uint8_t  const_1;                  /* 0x23 = 1 */
    uint32_t buffer_size_words;        /* 0x24 */
    uint32_t buffer_size_words_dup;    /* 0x28 */
    uint8_t  _pad_2c[0x4];            /* 0x2c - 0x2f */
    uint64_t channel_decoders[4];      /* 0x30 -- 4 slots */
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
/* criAtomDbas — opaque handle                                               */
/* Evidence: criAtomDbas_Create (FUN_140019514), puVar3 as undefined4* (x4)  */
/* Slot array at DAT_147e621c0 (4 slots, up to DAT_147e621e0)               */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomDbas {
    uint32_t config_copy;              /* 0x00 -- *param_1 */
    uint8_t  _pad_04[0x4];            /* 0x04 - 0x07 */
    uint64_t alloc_handle;             /* 0x08 -- puVar3+2 */
    uint64_t sub_handle;               /* 0x10 -- puVar3+4 */
} CriAtomDbas;

static_assert(offsetof(CriAtomDbas, config_copy) == 0x00, "CriAtomDbas.config_copy");
static_assert(offsetof(CriAtomDbas, alloc_handle) == 0x08, "CriAtomDbas.alloc_handle");
static_assert(offsetof(CriAtomDbas, sub_handle) == 0x10, "CriAtomDbas.sub_handle");

/* ========================================================================= */
/* criAtomSequenceManager — manager with linked lists                        */
/* Variable size from config (track/event/seq/channel counts).               */
/* Evidence: criAtomSequence_Initialize (FUN_140033030), puVar5 as uint* (x4)*/
/* Sub-element strides: track=0xd8, event=0x68, seq=400, chan=0x130,        */
/*   list5=0x50, list6=0x30, list7=0x28                                      */
/* String: "CRI AtomEx Sequencer/PCx64 Ver.1.05.01 Build:Oct 6 2015"        */
/* Globals: DAT_147e62f70 (manager_ptr), DAT_147e62f78 (timer_handle)        */
/* NOTE: puVar5 is uint* so indices are x4 byte offsets.                     */
/* ========================================================================= */

typedef struct __attribute__((packed)) CriAtomSequenceManager {
    uint32_t track_count;              /* 0x00 -- from config */
    uint32_t event_count;              /* 0x04 -- from config */
    uint32_t seq_count;                /* 0x08 -- from config */
    uint32_t channel_count;            /* 0x0c -- from config */
    uint64_t track_list_head;          /* 0x10 -- stride 0xd8 */
    uint64_t track_list_tail;          /* 0x18 */
    uint64_t event_list_head;          /* 0x20 -- stride 0x68 */
    uint64_t event_list_tail;          /* 0x28 */
    uint64_t seq_list_head;            /* 0x30 -- stride 400 */
    uint64_t seq_list_tail;            /* 0x38 */
    uint64_t chan_list_head;           /* 0x40 -- stride 0x130 */
    uint64_t chan_list_tail;           /* 0x48 */
    uint64_t list5_head;               /* 0x50 -- stride 0x50 */
    uint64_t list5_tail;               /* 0x58 */
    uint64_t list6_head;               /* 0x60 -- stride 0x30 */
    uint64_t list6_tail;               /* 0x68 */
    uint64_t list7_head;               /* 0x70 -- stride 0x28 */
    uint64_t list7_tail;               /* 0x78 */
    uint8_t  _pad_80[0x80];           /* 0x80 - 0xff */
    uint64_t timestamp;                /* 0x100 */
    uint32_t flag;                     /* 0x108 = 1 */
    uint8_t  _pad_10c[0x4];           /* 0x10c - 0x10f */
    /* Size unknown, >= 0x110. Variable allocation based on config counts. */
} CriAtomSequenceManager;

static_assert(offsetof(CriAtomSequenceManager, track_count) == 0x00, "CriAtomSequenceManager.track_count");
static_assert(offsetof(CriAtomSequenceManager, event_count) == 0x04, "CriAtomSequenceManager.event_count");
static_assert(offsetof(CriAtomSequenceManager, seq_count) == 0x08, "CriAtomSequenceManager.seq_count");
static_assert(offsetof(CriAtomSequenceManager, channel_count) == 0x0c, "CriAtomSequenceManager.channel_count");
static_assert(offsetof(CriAtomSequenceManager, track_list_head) == 0x10, "CriAtomSequenceManager.track_list_head");
static_assert(offsetof(CriAtomSequenceManager, track_list_tail) == 0x18, "CriAtomSequenceManager.track_list_tail");
static_assert(offsetof(CriAtomSequenceManager, event_list_head) == 0x20, "CriAtomSequenceManager.event_list_head");
static_assert(offsetof(CriAtomSequenceManager, event_list_tail) == 0x28, "CriAtomSequenceManager.event_list_tail");
static_assert(offsetof(CriAtomSequenceManager, seq_list_head) == 0x30, "CriAtomSequenceManager.seq_list_head");
static_assert(offsetof(CriAtomSequenceManager, seq_list_tail) == 0x38, "CriAtomSequenceManager.seq_list_tail");
static_assert(offsetof(CriAtomSequenceManager, chan_list_head) == 0x40, "CriAtomSequenceManager.chan_list_head");
static_assert(offsetof(CriAtomSequenceManager, chan_list_tail) == 0x48, "CriAtomSequenceManager.chan_list_tail");
static_assert(offsetof(CriAtomSequenceManager, list5_head) == 0x50, "CriAtomSequenceManager.list5_head");
static_assert(offsetof(CriAtomSequenceManager, list5_tail) == 0x58, "CriAtomSequenceManager.list5_tail");
static_assert(offsetof(CriAtomSequenceManager, list6_head) == 0x60, "CriAtomSequenceManager.list6_head");
static_assert(offsetof(CriAtomSequenceManager, list6_tail) == 0x68, "CriAtomSequenceManager.list6_tail");
static_assert(offsetof(CriAtomSequenceManager, list7_head) == 0x70, "CriAtomSequenceManager.list7_head");
static_assert(offsetof(CriAtomSequenceManager, list7_tail) == 0x78, "CriAtomSequenceManager.list7_tail");
static_assert(offsetof(CriAtomSequenceManager, timestamp) == 0x100, "CriAtomSequenceManager.timestamp");
static_assert(offsetof(CriAtomSequenceManager, flag) == 0x108, "CriAtomSequenceManager.flag");

/* ========================================================================= */
/* criAtomTimerGlobals — scattered globals, not a heap object                */
/* Evidence: criAtomTimer_Initialize (FUN_14002e788)                         */
/* Increments DAT_147e62df0; on first call sets:                            */
/*   DAT_1409ae338 via FUN_1400a4008()                                       */
/*   DAT_147e62df8 via FUN_1400a3fec()                                       */
/* Clears DAT_147e62e00 and DAT_147e62df4                                   */
/* Not modeled as a struct — these are independent global variables.         */
/* ========================================================================= */

#endif /* LIB_CRI_ATOM_S2_H */