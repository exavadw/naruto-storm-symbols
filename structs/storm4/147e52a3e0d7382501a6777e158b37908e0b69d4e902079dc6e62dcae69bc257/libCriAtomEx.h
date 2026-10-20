/*
 * libCriAtomEx.h - CRIWARE ADX2 AtomEx struct layouts for Storm 4 PC (s4)
 * Build: NSUNS4_release.exe 1.09, sha 147e52a3e0d7382501a6777e158b37908e0b69d4e902079dc6e62dcae69bc257
 *
 * RECONSTRUCTED FROM STATIC ANALYSIS ONLY. All layouts are INFERRED, not CONFIRMED.
 * Sizes proven from allocator calls in decompiled code; never from sizeof.
 * Field names from this build's own symbols (criAtomEx*).
 * No CRI SDK source was used (proprietary, license-required).
 *
 * Rollback context: CRI sound memory lives in an untracked heap and CRI threads
 * are not rewound. Fields tagged SIM in the companion TSV affect simulation
 * determinism; PRES fields are preserved across rollback but do not drive it.
 */

#ifndef LIB_CRI_ATOM_EX_S4_H
#define LIB_CRI_ATOM_EX_S4_H

#include <stdint.h>
#include <stddef.h>

/*
 * s4_CriAtomExPlayer - primary audio playback handle.
 *
 * Size: 0x4F0 bytes (INFERRED).
 * Evidence: criAtomExPlayer_Create calls criAtomExRng_Create(uVar11 + 0x4f0, iVar2),
 * proving the fixed allocation is exactly 0x4F0 before the RNG work area.
 *
 * Layout matches s3 ns3_CriAtomExPlayer (0x4F0) with identical field offsets
 * confirmed via state_surface and symbolized decompilation.
 */
struct __attribute__((packed)) s4_CriAtomExPlayer {
    /* 0x000 */ void* self_ptr;
    /* 0x008 */ void* linked_list_next;
    /* 0x010 */ int32_t status;
    /* 0x014 */ uint8_t _pad_014[2];
    /* 0x016 */ uint16_t ref_count;
    /* 0x018 */ uint8_t _unk_018[0x10];
    /* 0x028 */ int32_t reset_field_028;
    /* 0x02C */ int32_t reset_field_02c;
    /* 0x030 */ uint64_t default_value_030;
    /* 0x038 */ uint64_t reset_field_038;
    /* 0x040 */ uint64_t reset_field_040;
    /* 0x048 */ uint64_t reset_field_048;
    /* 0x050 */ uint64_t reset_field_050;
    /* 0x058 */ uint8_t _unk_058[0x48];
    /* 0x0A0 */ void* aisac_control;
    /* 0x0A8 */ int32_t default_aisac_val;
    /* 0x0AC */ int32_t cue_id_or_flags;
    /* 0x0B0 */ uint32_t config_flags;
    /* 0x0B4 */ uint16_t channel_count;
    /* 0x0B6 */ uint16_t max_channels;
    /* 0x0B8 */ uint32_t block_size;
    /* 0x0BC */ uint8_t _unk_0bc[0x44];
    /* 0x100 */ uint8_t fader_active;
    /* 0x101 */ uint8_t paused;
    /* 0x102 */ uint8_t loop_count;
    /* 0x103 */ char playback_mode;
    /* 0x104 */ uint8_t _unk_104[4];
    /* 0x108 */ void* track_list_head;
    /* 0x110 */ void* track_list_tail;
    /* 0x118 */ int32_t track_count;
    /* 0x11C */ uint8_t _unk_11c[4];
    /* 0x120 */ void* dsp_handle;
    /* 0x128 */ uint8_t dsp_buffer[0x320];
    /* 0x448 */ uint32_t last_playback_id;
    /* 0x44C */ uint32_t current_playback_id;
    /* 0x450 */ uint8_t _unk_450[8];
    /* 0x458 */ void* sound_object;
    /* 0x460 */ void* start_callback_fn;
    /* 0x468 */ void* start_callback_arg;
    /* 0x470 */ void* stop_callback_fn;
    /* 0x478 */ void* stop_callback_arg;
    /* 0x480 */ uint8_t _unk_480[0x30];
    /* 0x4B0 */ void* rng_handle_1;
    /* 0x4B8 */ void* rng_handle_2;
    /* 0x4C0 */ uint8_t _unk_4c0[8];
    /* 0x4C8 */ void* block_transition_cb;
    /* 0x4D0 */ void* block_transition_arg;
    /* 0x4D8 */ void* attached_sound_obj;
    /* 0x4E0 */ void* self_ref_4e0;
    /* 0x4E8 */ uint64_t _unk_4e8;
};

_Static_assert(sizeof(struct s4_CriAtomExPlayer) == 0x4F0, "s4_CriAtomExPlayer size");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, self_ptr) == 0x000, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, linked_list_next) == 0x008, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, status) == 0x010, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, ref_count) == 0x016, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_018) == 0x018, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, reset_field_028) == 0x028, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, reset_field_02c) == 0x02C, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, default_value_030) == 0x030, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, reset_field_038) == 0x038, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, reset_field_040) == 0x040, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, reset_field_048) == 0x048, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, reset_field_050) == 0x050, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_058) == 0x058, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, aisac_control) == 0x0A0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, default_aisac_val) == 0x0A8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, cue_id_or_flags) == 0x0AC, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, config_flags) == 0x0B0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, channel_count) == 0x0B4, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, max_channels) == 0x0B6, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, block_size) == 0x0B8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_0bc) == 0x0BC, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, fader_active) == 0x100, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, paused) == 0x101, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, loop_count) == 0x102, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, playback_mode) == 0x103, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_104) == 0x104, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, track_list_head) == 0x108, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, track_list_tail) == 0x110, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, track_count) == 0x118, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_11c) == 0x11C, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, dsp_handle) == 0x120, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, dsp_buffer) == 0x128, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, last_playback_id) == 0x448, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, current_playback_id) == 0x44C, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_450) == 0x450, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, sound_object) == 0x458, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, start_callback_fn) == 0x460, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, start_callback_arg) == 0x468, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, stop_callback_fn) == 0x470, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, stop_callback_arg) == 0x478, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_480) == 0x480, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, rng_handle_1) == 0x4B0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, rng_handle_2) == 0x4B8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_4c0) == 0x4C0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, block_transition_cb) == 0x4C8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, block_transition_arg) == 0x4D0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, attached_sound_obj) == 0x4D8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, self_ref_4e0) == 0x4E0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlayer, _unk_4e8) == 0x4E8, "");

/*
 * s4_CriAtomExPlaybackInfo - per-cue playback state.
 *
 * Size: unknown, >= 0xFA bytes (INFERRED).
 * No fixed-size allocator call found; state_surface found 76 fields
 * spanning 0x010..0x0F9. Allocated dynamically via CRI work heap.
 *
 * Note: criAtomExPlayback and criAtomExPlaybackInfo share the same
 * underlying struct in s4 (surface seeds resolved to identical functions).
 *
 * Many fields are single-byte flags written in FreeInfo/ResetPatterns.
 * Grouped into byte arrays where contiguous writes suggest flag blocks.
 */
struct __attribute__((packed)) s4_CriAtomExPlaybackInfo {
    /* 0x000 */ uint8_t _unk_000[0x10];
    /* 0x010 */ void* next_info;
    /* 0x018 */ void* sequence_data;
    /* 0x020 */ uint8_t _unk_020[0x18];
    /* 0x038 */ void* category_list;
    /* 0x040 */ uint8_t init_flags[8];
    /* 0x048 */ uint32_t playback_counter;
    /* 0x04C */ uint8_t _unk_04c[4];
    /* 0x050 */ void* parent_info;
    /* 0x058 */ uint8_t mute_flags[8];
    /* 0x060 */ int32_t ref_count;
    /* 0x064 */ uint8_t _unk_064[4];
    /* 0x068 */ void* cue_handle;
    /* 0x070 */ uint8_t stop_flags[8];
    /* 0x078 */ int32_t active_count;
    /* 0x07C */ uint8_t _unk_07c[4];
    /* 0x080 */ void* player_handle;
    /* 0x088 */ uint8_t _unk_088[8];
    /* 0x090 */ uint8_t state_byte_090;
    /* 0x091 */ uint8_t _unk_091[7];
    /* 0x098 */ uint8_t _unk_098[8];
    /* 0x0A0 */ uint8_t _unk_0a0[4];
    /* 0x0A4 */ uint8_t _unk_0a4[0x2C];
    /* 0x0D0 */ uint8_t end_flags[8];
    /* 0x0D8 */ uint8_t pattern_flags[8];
    /* 0x0E0 */ uint8_t transition_flag_0e0;
    /* 0x0E1 */ uint8_t _unk_0e1[7];
    /* 0x0E8 */ uint8_t transition_flag_0e8;
    /* 0x0E9 */ uint8_t _unk_0e9[7];
    /* 0x0F0 */ uint8_t read_flag_0f0;
    /* 0x0F1 */ uint8_t _unk_0f1[8];
    /* 0x0F9 */ uint8_t final_flag;
};

/* Size unknown: no sizeof assert. Last proven field at 0x0F9. */
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, next_info) == 0x010, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, sequence_data) == 0x018, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, category_list) == 0x038, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, init_flags) == 0x040, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, playback_counter) == 0x048, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, parent_info) == 0x050, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, mute_flags) == 0x058, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, ref_count) == 0x060, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, cue_handle) == 0x068, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, stop_flags) == 0x070, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, active_count) == 0x078, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, player_handle) == 0x080, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, state_byte_090) == 0x090, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, end_flags) == 0x0D0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, pattern_flags) == 0x0D8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, transition_flag_0e0) == 0x0E0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, transition_flag_0e8) == 0x0E8, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, read_flag_0f0) == 0x0F0, "");
_Static_assert(offsetof(struct s4_CriAtomExPlaybackInfo, final_flag) == 0x0F9, "");

/*
 * s4_CriAtomExCategory - category volume/priority control.
 *
 * Size: unknown, >= 0xBC bytes (INFERRED).
 * No fixed-size allocator call found; state_surface found 14 fields
 * spanning 0x038..0x0B8.
 */
struct __attribute__((packed)) s4_CriAtomExCategory {
    /* 0x000 */ uint8_t _unk_000[0x38];
    /* 0x038 */ void* prohibition_time_ptr;
    /* 0x040 */ uint32_t field_040;
    /* 0x044 */ uint32_t field_044;
    /* 0x048 */ uint32_t multiple_playback_limit;
    /* 0x04C */ uint8_t _unk_04c[0xC];
    /* 0x058 */ uint32_t field_058;
    /* 0x05C */ uint8_t _unk_05c[0x14];
    /* 0x070 */ uint32_t field_070;
    /* 0x074 */ uint32_t field_074;
    /* 0x078 */ uint8_t _unk_078[8];
    /* 0x080 */ void* playing_cue_internal;
    /* 0x088 */ uint8_t _unk_088[0x18];
    /* 0x0A0 */ uint32_t field_0a0;
    /* 0x0A4 */ uint8_t _unk_0a4[4];
    /* 0x0A8 */ void* field_0a8;
    /* 0x0B0 */ uint32_t field_0b0_lo;
    /* 0x0B4 */ uint32_t field_0b4;
    /* 0x0B8 */ uint32_t field_0b8;
};

/* Size unknown: no sizeof assert. Last proven field at 0x0B8. */
_Static_assert(offsetof(struct s4_CriAtomExCategory, prohibition_time_ptr) == 0x038, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_040) == 0x040, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_044) == 0x044, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, multiple_playback_limit) == 0x048, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_058) == 0x058, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_070) == 0x070, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_074) == 0x074, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, playing_cue_internal) == 0x080, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_0a0) == 0x0A0, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_0a8) == 0x0A8, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_0b0_lo) == 0x0B0, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_0b4) == 0x0B4, "");
_Static_assert(offsetof(struct s4_CriAtomExCategory, field_0b8) == 0x0B8, "");

/*
 * s4_CriAtomExCue - cue sheet reference handle.
 *
 * Size: variable (INFERRED). CalculateWorkSize returns a computed value
 * based on track count and RNG work size; no fixed allocation.
 * Only 3 fields surfaced from SetupActionTrack reads.
 */
struct __attribute__((packed)) s4_CriAtomExCue {
    /* 0x000 */ uint8_t _unk_000[0x18];
    /* 0x018 */ void* action_track_data;
    /* 0x020 */ uint8_t _unk_020[0x38];
    /* 0x058 */ void* sequence_ref;
    /* 0x060 */ uint8_t _unk_060[8];
    /* 0x068 */ void* cue_name_or_id;
};

/* Size unknown: no sizeof assert. Variable allocation. */
_Static_assert(offsetof(struct s4_CriAtomExCue, action_track_data) == 0x018, "");
_Static_assert(offsetof(struct s4_CriAtomExCue, sequence_ref) == 0x058, "");
_Static_assert(offsetof(struct s4_CriAtomExCue, cue_name_or_id) == 0x068, "");

/*
 * s4_CriAtomExSoundObject - game-specific sound object wrapper.
 *
 * Size: unknown, >= 0x15AB0 bytes (INFERRED).
 * This is NOT a standard CRI struct; it is a Storm 4 game-side wrapper
 * that embeds or references CRI player handles. Fields span 0x080..0x15AA8.
 * vtable-derived offsets (0x080, 0x200, 0xC040) are excluded as they
 * point to virtual dispatch, not direct member access.
 */
struct __attribute__((packed)) s4_CriAtomExSoundObject {
    /* 0x00000 */ uint8_t _unk_00000[0xC8C];
    /* 0x00C8C */ uint32_t player_count;
    /* 0x00C90 */ uint8_t _unk_00c90[0x14C90];
    /* 0x15920 */ void* player_array;
    /* 0x15928 */ uint8_t _unk_15928[4];
    /* 0x1592C */ uint32_t active_player_index;
    /* 0x15930 */ uint8_t _unk_15930[0x178];
    /* 0x15AA8 */ void* new_player_entry;
};

/* Size unknown: no sizeof assert. Last proven field at 0x15AA8. */
_Static_assert(offsetof(struct s4_CriAtomExSoundObject, player_count) == 0x00C8C, "");
_Static_assert(offsetof(struct s4_CriAtomExSoundObject, player_array) == 0x15920, "");
_Static_assert(offsetof(struct s4_CriAtomExSoundObject, active_player_index) == 0x1592C, "");
_Static_assert(offsetof(struct s4_CriAtomExSoundObject, new_player_entry) == 0x15AA8, "");

#endif /* LIB_CRI_ATOM_EX_S4_H */