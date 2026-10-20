/* libCriAtomEx.h - Reconstructed CRIWARE ADX2 AtomEx structs for Storm 2 (NSUNS2.exe)
 * Generated from decompilation analysis. All layouts INFERRED from static analysis.
 * Build: s2 (NSUNS2.exe)
 * Image base: 0x140000000
 */
#ifndef LIB_CRI_ATOM_EX_S2_H
#define LIB_CRI_ATOM_EX_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Rollback netcode field tags:
 * SIM - Simulation-critical: must be serialized/deserialized on rollback
 * PRES - Preserved across rollback but not sim-deterministic
 * UNKNOWN - Not yet classified
 */

/* criAtomExPlayer - Main player object
 * Allocation size: (param_2 + 0x4F0) aligned to 8 bytes (from criAtomExPlayer_Create)
 * Minimum fixed size: 0x4F8 (1272 bytes)
 * Struct layout matches s1 exactly (same CRIWARE ADX2 SDK version).
 */
typedef struct __attribute__((packed)) CriAtomExPlayer {
    /* 0x0000 */ uint8_t _pad_0000[8];
    /* 0x0008 */ uint64_t next;              /* [PRES] linked list next pointer */
    /* 0x0010 */ int32_t status;             /* [SIM] player status / state */
    /* 0x0014 */ uint8_t _pad_0014[2];
    /* 0x0016 */ uint16_t player_id;         /* [SIM] player index/id */
    /* 0x0018 */ void *prev;                 /* [PRES] linked list prev pointer */
    /* 0x0020 */ uint32_t field_0020;        /* [SIM] ResetParameters accesses 0x1c (=0x20 in s1 naming? NO: s1 has 0x1C at offset 28) */
    /* 0x0024 */ uint32_t field_0024;        /* [SIM] */
    /* 0x0028 */ uint32_t field_0028;        /* [SIM] */
    /* 0x002C */ uint32_t field_002C;        /* [SIM] */
    /* 0x0030 */ void *field_0030;           /* [SIM] */
    /* 0x0038 */ void *field_0038;           /* [SIM] */
    /* 0x0040 */ void *field_0040;           /* [SIM] */
    /* 0x0048 */ void *field_0048;           /* [SIM] random seed ptr */
    /* 0x0050 */ void *field_0050;           /* [SIM] random seed ptr */
    /* 0x0058 */ uint8_t _pad_0058[72];      /* 0x0058-0x009F */
    /* 0x00A0 */ int64_t sound_object;       /* [PRES] CriAtomExSoundObject handle */
    /* 0x00A8 */ uint64_t field_00A8;        /* [UNKNOWN] */
    /* 0x00B0 */ uint32_t field_00B0;        /* [UNKNOWN] */
    /* 0x00B4 */ uint16_t field_00B4;        /* [UNKNOWN] */
    /* 0x00B6 */ uint16_t field_00B6;        /* [UNKNOWN] */
    /* 0x00B8 */ uint64_t field_00B8;        /* [UNKNOWN] */
    /* 0x00C0 */ uint64_t cue_list;          /* [UNKNOWN] cue array pointer */
    /* 0x00C8 */ uint8_t _pad_00C8[8];       /* 0x00C8-0x00CF */
    /* 0x00D0 */ int64_t cue_data;           /* [SIM] current cue data pointer */
    /* 0x00D8 */ int32_t cue_id;             /* [SIM] current cue id */
    /* 0x00DC */ uint8_t _pad_00DC[4];       /* 0x00DC-0x00DF */
    /* 0x00E0 */ int64_t playback_handle;    /* [SIM] playback handle */
    /* 0x00E8 */ void *config_0;             /* [SIM] playback config */
    /* 0x00F0 */ uint32_t config_1;          /* [SIM] playback config */
    /* 0x00F4 */ uint32_t field_00F4;        /* [UNKNOWN] */
    /* 0x00F8 */ uint32_t field_00F8;        /* [UNKNOWN] */
    /* 0x00FC */ int32_t sync_playback_id;   /* [SIM] */
    /* 0x0100 */ char name_buf;              /* [PRES] name buffer start */
    /* 0x0101 */ uint8_t pause_flag;         /* [PRES] pause state */
    /* 0x0102 */ char field_0102;            /* [UNKNOWN] */
    /* 0x0103 */ char field_0103;            /* [UNKNOWN] */
    /* 0x0104 */ uint8_t _pad_0104[4];       /* 0x0104-0x0107 */
    /* 0x0108 */ int64_t *category_array;    /* [SIM] category index array */
    /* 0x0110 */ int64_t playback_info;      /* [PRES] playback info pointer */
    /* 0x0118 */ int32_t field_0118;         /* [SIM] */
    /* 0x011C */ uint8_t _pad_011C[4];       /* 0x011C-0x011F */
    /* 0x0120 */ void *atom_player;          /* [SIM] inner AtomPlayer handle */
    /* 0x0128 */ uint64_t field_0128;        /* [UNKNOWN] */
    /* 0x0130 */ uint8_t _pad_0130[36];      /* 0x0130-0x0153 */
    /* 0x0154 */ void *field_0154;           /* [UNKNOWN] */
    /* 0x015C */ uint8_t _pad_015C[4];       /* 0x015C-0x015F (alignment) */
    /* 0x0160 */ uint8_t _pad_0160[104];     /* 0x0160-0x01C7 */
    /* 0x01C8 */ uint32_t num_playbacks;     /* [UNKNOWN] GetNumPlaybacks reads this */
    /* 0x01CC */ uint8_t _pad_01CC[148];     /* 0x01CC-0x025F */
    /* 0x0260 */ void *field_0260;           /* [UNKNOWN] GetCategoryIndex reads this */
    /* 0x0268 */ uint8_t _pad_0268[72];      /* 0x0268-0x02AF */
    /* 0x02B0 */ int32_t field_02B0;         /* [SIM] ClearAll writes this */
    /* 0x02B4 */ uint32_t field_02B4;        /* [SIM] ClearAll writes this */
    /* 0x02B8 */ uint32_t num_saved_categories; /* [SIM] GetNumSavedCategoryIndexes reads this */
    /* 0x02BC */ uint8_t _pad_02BC[12];      /* 0x02BC-0x02C7 */
    /* 0x02C8 */ void *field_02C8;           /* [UNKNOWN] ClearAll touches this */
    /* 0x02D0 */ void *field_02D0;           /* [UNKNOWN] ClearAll touches this */
    /* 0x02D8 */ uint8_t _pad_02D8[368];     /* 0x02D8-0x0447 */
    /* 0x0448 */ int32_t volume;             /* [SIM] volume parameter */
    /* 0x044C */ int32_t pitch;              /* [SIM] pitch parameter */
    /* 0x0450 */ uint8_t _pad_0450[8];       /* 0x0450-0x0457 */
    /* 0x0458 */ int64_t fader_handle;       /* [PRES] fader */
    /* 0x0460 */ void (*start_cb)(void);     /* [PRES] start callback */
    /* 0x0468 */ void *start_cb_userdata;    /* [PRES] start callback userdata */
    /* 0x0470 */ void (*end_cb)(void);       /* [PRES] end callback */
    /* 0x0478 */ void *block_cb;             /* [PRES] block transition callback */
    /* 0x0480 */ uint8_t _pad_0480[32];      /* 0x0480-0x049F */
    /* 0x04A0 */ uint64_t work_area;         /* [PRES] work area pointer */
    /* 0x04A8 */ uint32_t cue_priority;      /* [UNKNOWN] GetCuePriority reads this */
    /* 0x04AC */ uint8_t _pad_04AC[4];       /* 0x04AC-0x04AF */
    /* 0x04B0 */ void *rng_hn;               /* [PRES] RNG handle 1 */
    /* 0x04B8 */ void *rng_hn_2;             /* [PRES] RNG handle 2 */
    /* 0x04C0 */ uint8_t _pad_04C0[8];       /* 0x04C0-0x04C7 */
    /* 0x04C8 */ void (*dsp_setting)(void);  /* [UNKNOWN] DSP bus setting callback */
    /* 0x04D0 */ void *sync_playback_id_ptr; /* [PRES] DoBlockTransitionCallback reads this */
    /* 0x04D8 */ int64_t beat_sync;          /* [PRES] BeatSync handle */
    /* 0x04E0 */ void *tail;                 /* [PRES] linked list tail */
    /* 0x04E8 */ uint64_t field_04E8;        /* [UNKNOWN] */
    /* 0x04F0 */ uint64_t field_04F0;        /* [UNKNOWN] */
} CriAtomExPlayer;

/* Per-field offsetof assertions */
_Static_assert(offsetof(CriAtomExPlayer, _pad_0000) == 0x0000, "CriAtomExPlayer._pad_0000 offset");
_Static_assert(offsetof(CriAtomExPlayer, next) == 0x0008, "CriAtomExPlayer.next offset");
_Static_assert(offsetof(CriAtomExPlayer, status) == 0x0010, "CriAtomExPlayer.status offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0014) == 0x0014, "CriAtomExPlayer._pad_0014 offset");
_Static_assert(offsetof(CriAtomExPlayer, player_id) == 0x0016, "CriAtomExPlayer.player_id offset");
_Static_assert(offsetof(CriAtomExPlayer, prev) == 0x0018, "CriAtomExPlayer.prev offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0020) == 0x0020, "CriAtomExPlayer.field_0020 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0024) == 0x0024, "CriAtomExPlayer.field_0024 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0028) == 0x0028, "CriAtomExPlayer.field_0028 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_002C) == 0x002C, "CriAtomExPlayer.field_002C offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0030) == 0x0030, "CriAtomExPlayer.field_0030 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0038) == 0x0038, "CriAtomExPlayer.field_0038 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0040) == 0x0040, "CriAtomExPlayer.field_0040 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0048) == 0x0048, "CriAtomExPlayer.field_0048 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0050) == 0x0050, "CriAtomExPlayer.field_0050 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0058) == 0x0058, "CriAtomExPlayer._pad_0058 offset");
_Static_assert(offsetof(CriAtomExPlayer, sound_object) == 0x00A0, "CriAtomExPlayer.sound_object offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00A8) == 0x00A8, "CriAtomExPlayer.field_00A8 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00B0) == 0x00B0, "CriAtomExPlayer.field_00B0 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00B4) == 0x00B4, "CriAtomExPlayer.field_00B4 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00B6) == 0x00B6, "CriAtomExPlayer.field_00B6 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00B8) == 0x00B8, "CriAtomExPlayer.field_00B8 offset");
_Static_assert(offsetof(CriAtomExPlayer, cue_list) == 0x00C0, "CriAtomExPlayer.cue_list offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_00C8) == 0x00C8, "CriAtomExPlayer._pad_00C8 offset");
_Static_assert(offsetof(CriAtomExPlayer, cue_data) == 0x00D0, "CriAtomExPlayer.cue_data offset");
_Static_assert(offsetof(CriAtomExPlayer, cue_id) == 0x00D8, "CriAtomExPlayer.cue_id offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_00DC) == 0x00DC, "CriAtomExPlayer._pad_00DC offset");
_Static_assert(offsetof(CriAtomExPlayer, playback_handle) == 0x00E0, "CriAtomExPlayer.playback_handle offset");
_Static_assert(offsetof(CriAtomExPlayer, config_0) == 0x00E8, "CriAtomExPlayer.config_0 offset");
_Static_assert(offsetof(CriAtomExPlayer, config_1) == 0x00F0, "CriAtomExPlayer.config_1 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00F4) == 0x00F4, "CriAtomExPlayer.field_00F4 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_00F8) == 0x00F8, "CriAtomExPlayer.field_00F8 offset");
_Static_assert(offsetof(CriAtomExPlayer, sync_playback_id) == 0x00FC, "CriAtomExPlayer.sync_playback_id offset");
_Static_assert(offsetof(CriAtomExPlayer, name_buf) == 0x0100, "CriAtomExPlayer.name_buf offset");
_Static_assert(offsetof(CriAtomExPlayer, pause_flag) == 0x0101, "CriAtomExPlayer.pause_flag offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0102) == 0x0102, "CriAtomExPlayer.field_0102 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0103) == 0x0103, "CriAtomExPlayer.field_0103 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0104) == 0x0104, "CriAtomExPlayer._pad_0104 offset");
_Static_assert(offsetof(CriAtomExPlayer, category_array) == 0x0108, "CriAtomExPlayer.category_array offset");
_Static_assert(offsetof(CriAtomExPlayer, playback_info) == 0x0110, "CriAtomExPlayer.playback_info offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0118) == 0x0118, "CriAtomExPlayer.field_0118 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_011C) == 0x011C, "CriAtomExPlayer._pad_011C offset");
_Static_assert(offsetof(CriAtomExPlayer, atom_player) == 0x0120, "CriAtomExPlayer.atom_player offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0128) == 0x0128, "CriAtomExPlayer.field_0128 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0130) == 0x0130, "CriAtomExPlayer._pad_0130 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0154) == 0x0154, "CriAtomExPlayer.field_0154 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_015C) == 0x015C, "CriAtomExPlayer._pad_015C offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0160) == 0x0160, "CriAtomExPlayer._pad_0160 offset");
_Static_assert(offsetof(CriAtomExPlayer, num_playbacks) == 0x01C8, "CriAtomExPlayer.num_playbacks offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_01CC) == 0x01CC, "CriAtomExPlayer._pad_01CC offset");
_Static_assert(offsetof(CriAtomExPlayer, field_0260) == 0x0260, "CriAtomExPlayer.field_0260 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0268) == 0x0268, "CriAtomExPlayer._pad_0268 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_02B0) == 0x02B0, "CriAtomExPlayer.field_02B0 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_02B4) == 0x02B4, "CriAtomExPlayer.field_02B4 offset");
_Static_assert(offsetof(CriAtomExPlayer, num_saved_categories) == 0x02B8, "CriAtomExPlayer.num_saved_categories offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_02BC) == 0x02BC, "CriAtomExPlayer._pad_02BC offset");
_Static_assert(offsetof(CriAtomExPlayer, field_02C8) == 0x02C8, "CriAtomExPlayer.field_02C8 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_02D0) == 0x02D0, "CriAtomExPlayer.field_02D0 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_02D8) == 0x02D8, "CriAtomExPlayer._pad_02D8 offset");
_Static_assert(offsetof(CriAtomExPlayer, volume) == 0x0448, "CriAtomExPlayer.volume offset");
_Static_assert(offsetof(CriAtomExPlayer, pitch) == 0x044C, "CriAtomExPlayer.pitch offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0450) == 0x0450, "CriAtomExPlayer._pad_0450 offset");
_Static_assert(offsetof(CriAtomExPlayer, fader_handle) == 0x0458, "CriAtomExPlayer.fader_handle offset");
_Static_assert(offsetof(CriAtomExPlayer, start_cb) == 0x0460, "CriAtomExPlayer.start_cb offset");
_Static_assert(offsetof(CriAtomExPlayer, start_cb_userdata) == 0x0468, "CriAtomExPlayer.start_cb_userdata offset");
_Static_assert(offsetof(CriAtomExPlayer, end_cb) == 0x0470, "CriAtomExPlayer.end_cb offset");
_Static_assert(offsetof(CriAtomExPlayer, block_cb) == 0x0478, "CriAtomExPlayer.block_cb offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_0480) == 0x0480, "CriAtomExPlayer._pad_0480 offset");
_Static_assert(offsetof(CriAtomExPlayer, work_area) == 0x04A0, "CriAtomExPlayer.work_area offset");
_Static_assert(offsetof(CriAtomExPlayer, cue_priority) == 0x04A8, "CriAtomExPlayer.cue_priority offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_04AC) == 0x04AC, "CriAtomExPlayer._pad_04AC offset");
_Static_assert(offsetof(CriAtomExPlayer, rng_hn) == 0x04B0, "CriAtomExPlayer.rng_hn offset");
_Static_assert(offsetof(CriAtomExPlayer, rng_hn_2) == 0x04B8, "CriAtomExPlayer.rng_hn_2 offset");
_Static_assert(offsetof(CriAtomExPlayer, _pad_04C0) == 0x04C0, "CriAtomExPlayer._pad_04C0 offset");
_Static_assert(offsetof(CriAtomExPlayer, dsp_setting) == 0x04C8, "CriAtomExPlayer.dsp_setting offset");
_Static_assert(offsetof(CriAtomExPlayer, sync_playback_id_ptr) == 0x04D0, "CriAtomExPlayer.sync_playback_id_ptr offset");
_Static_assert(offsetof(CriAtomExPlayer, beat_sync) == 0x04D8, "CriAtomExPlayer.beat_sync offset");
_Static_assert(offsetof(CriAtomExPlayer, tail) == 0x04E0, "CriAtomExPlayer.tail offset");
_Static_assert(offsetof(CriAtomExPlayer, field_04E8) == 0x04E8, "CriAtomExPlayer.field_04E8 offset");
_Static_assert(offsetof(CriAtomExPlayer, field_04F0) == 0x04F0, "CriAtomExPlayer.field_04F0 offset");

/* Total size assertion */
_Static_assert(sizeof(CriAtomExPlayer) == 0x4F8, "CriAtomExPlayer size mismatch");

#endif /* LIB_CRI_ATOM_EX_S2_H */