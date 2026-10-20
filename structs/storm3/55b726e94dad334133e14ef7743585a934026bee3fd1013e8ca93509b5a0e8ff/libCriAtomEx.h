/*
 * libCriAtomEx.h - CRIWARE ADX2 AtomEx struct layouts for Storm 3 Full Burst HD (s3)
 * Build: NSUNS3.exe (64-bit), sha 55b726e94dad
 *
 * RECONSTRUCTED FROM STATIC ANALYSIS ONLY. All layouts are INFERRED, not CONFIRMED.
 * Sizes proven from allocator calls in decompiled code; never from sizeof.
 * Field names from this build's own symbols (nucc) and s2 carry-forward via storm_map.
 * No CRI SDK source was used (proprietary, license-required).
 *
 * Rollback context: CRI sound memory lives in an untracked heap and CRI threads
 * are not rewound. Fields tagged SIM in the companion TSV affect simulation
 * determinism; PRES fields are preserved across rollback but do not drive it.
 */

#ifndef LIB_CRI_ATOM_EX_S3_H
#define LIB_CRI_ATOM_EX_S3_H

#include <stdint.h>
#include <stddef.h>

/*
 * ns3_CriAtomExPlayer - primary audio playback handle.
 *
 * Size: 0x4F0 bytes (INFERRED).
 * Evidence: Create @ RVA 0x1DED4 calls FUN_140027038(uVar11 + 0x4f0, iVar2),
 * proving the fixed allocation is exactly 0x4F0.
 *
 * Key differences from s2 (0x4F8):
 * - RNG handles moved from 0x48/0x50 to 0x4B0/0x4B8
 * - Inline dsp_buffer[800] at 0x128 (s2 layout differs)
 * - Explicit fader_active/paused byte flags at 0x100/0x101
 * - nucc-named criAtomExPlayer_SetRandomSeed @ 0x2ED784 is MISNAMED
 *   (operates on ccBoss05HitSphereGroup, not this struct)
 */
struct __attribute__((packed)) ns3_CriAtomExPlayer {
    /* 0x000 */ void*       self_ptr;
    /* 0x008 */ void*       linked_list_next;
    /* 0x010 */ int32_t     status;
    /* 0x014 */ uint8_t     _pad_014[2];
    /* 0x016 */ uint16_t    ref_count;
    /* 0x018 */ uint8_t     _unk_018[0x10];
    /* 0x028 */ int32_t     reset_field_028;
    /* 0x02C */ int32_t     reset_field_02c;
    /* 0x030 */ uint64_t    default_value_030;
    /* 0x038 */ uint64_t    reset_field_038;
    /* 0x040 */ uint64_t    reset_field_040;
    /* 0x048 */ uint64_t    reset_field_048;
    /* 0x050 */ uint64_t    reset_field_050;
    /* 0x058 */ uint8_t     _unk_058[0x48];
    /* 0x0A0 */ void*       aisac_control;
    /* 0x0A8 */ int32_t     default_aisac_val;
    /* 0x0AC */ int32_t     cue_id_or_flags;
    /* 0x0B0 */ uint32_t    config_flags;
    /* 0x0B4 */ uint16_t    channel_count;
    /* 0x0B6 */ uint16_t    max_channels;
    /* 0x0B8 */ uint32_t    block_size;
    /* 0x0BC */ uint8_t     _unk_0bc[0x44];
    /* 0x100 */ uint8_t     fader_active;
    /* 0x101 */ uint8_t     paused;
    /* 0x102 */ uint8_t     loop_count;
    /* 0x103 */ char        playback_mode;
    /* 0x104 */ uint8_t     _unk_104[4];
    /* 0x108 */ void*       track_list_head;
    /* 0x110 */ void*       track_list_tail;
    /* 0x118 */ int32_t     track_count;
    /* 0x11C */ uint8_t     _unk_11c[4];
    /* 0x120 */ void*       dsp_handle;
    /* 0x128 */ uint8_t     dsp_buffer[0x320];
    /* 0x448 */ uint32_t    last_playback_id;
    /* 0x44C */ uint32_t    current_playback_id;
    /* 0x450 */ uint8_t     _unk_450[8];
    /* 0x458 */ void*       sound_object;
    /* 0x460 */ void*       start_callback_fn;
    /* 0x468 */ void*       start_callback_arg;
    /* 0x470 */ void*       stop_callback_fn;
    /* 0x478 */ void*       stop_callback_arg;
    /* 0x480 */ uint8_t     _unk_480[0x30];
    /* 0x4B0 */ void*       rng_handle_1;
    /* 0x4B8 */ void*       rng_handle_2;
    /* 0x4C0 */ uint8_t     _unk_4c0[8];
    /* 0x4C8 */ void*       block_transition_cb;
    /* 0x4D0 */ void*       block_transition_arg;
    /* 0x4D8 */ void*       attached_sound_obj;
    /* 0x4E0 */ void*       self_ref_4e0;
    /* 0x4E8 */ uint64_t    _unk_4e8;
};

_Static_assert(sizeof(struct ns3_CriAtomExPlayer) == 0x4F0, "size");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, self_ptr) == 0x000, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, linked_list_next) == 0x008, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, status) == 0x010, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, ref_count) == 0x016, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_018) == 0x018, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, reset_field_028) == 0x028, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, reset_field_02c) == 0x02C, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, default_value_030) == 0x030, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, reset_field_038) == 0x038, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, reset_field_040) == 0x040, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, reset_field_048) == 0x048, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, reset_field_050) == 0x050, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_058) == 0x058, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, aisac_control) == 0x0A0, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, default_aisac_val) == 0x0A8, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, cue_id_or_flags) == 0x0AC, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, config_flags) == 0x0B0, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, channel_count) == 0x0B4, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, max_channels) == 0x0B6, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, block_size) == 0x0B8, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_0bc) == 0x0BC, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, fader_active) == 0x100, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, paused) == 0x101, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, loop_count) == 0x102, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, playback_mode) == 0x103, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_104) == 0x104, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, track_list_head) == 0x108, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, track_list_tail) == 0x110, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, track_count) == 0x118, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_11c) == 0x11C, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, dsp_handle) == 0x120, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, dsp_buffer) == 0x128, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, last_playback_id) == 0x448, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, current_playback_id) == 0x44C, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_450) == 0x450, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, sound_object) == 0x458, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, start_callback_fn) == 0x460, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, start_callback_arg) == 0x468, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, stop_callback_fn) == 0x470, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, stop_callback_arg) == 0x478, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_480) == 0x480, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, rng_handle_1) == 0x4B0, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, rng_handle_2) == 0x4B8, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_4c0) == 0x4C0, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, block_transition_cb) == 0x4C8, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, block_transition_arg) == 0x4D0, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, attached_sound_obj) == 0x4D8, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, self_ref_4e0) == 0x4E0, "");
_Static_assert(offsetof(struct ns3_CriAtomExPlayer, _unk_4e8) == 0x4E8, "");

#endif /* LIB_CRI_ATOM_EX_S3_H */