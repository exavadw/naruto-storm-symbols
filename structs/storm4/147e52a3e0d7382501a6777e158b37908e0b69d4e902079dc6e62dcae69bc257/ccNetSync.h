#pragma once

// ccNetSync.h — Network synchronization structs for NSUNS4 (s4 build, Steam 1.09)
// Generated with explicit padding to match MSVC x64 ABI layout.
// All offsets verified against decompiled code from NSUNS4_release.exe (base 0x140000000).
// Status: INFERRED from static analysis only. Not CONFIRMED at runtime.
// Cross-build: field names carried from s3 where offsets match; re-verified in s4 code.

#include <stdint.h>
#include <stddef.h>

// C11/C++ static_assert compatibility
#ifdef __cplusplus
#define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
#define STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

// === ccNetSyncParam ===
// No methods found in s4 build. Carried from s3 layout (own-game names only).
// Likely an empty/trivial param struct passed by value.
typedef struct ccNetSyncParam {
    uint32_t field_0x00; // 0x0000
    uint32_t field_0x04; // 0x0004
} ccNetSyncParam;

// === ccNetInputBuffer_NetData ===
// Per-player input data within the ring buffer. Layout carried from s3 (same engine).
typedef struct ccNetInputBuffer_NetData {
    uint32_t unk_0x00;      // 0x0000
    uint32_t buttons;       // 0x0004
    uint32_t input_word;    // 0x0008
    int16_t analog_l_x;     // 0x000C
    int16_t analog_l_y;     // 0x000E
    int16_t analog_r_x;     // 0x0010
    int16_t analog_r_y;     // 0x0012
    uint8_t pad_trailing[4]; // 0x0014
} ccNetInputBuffer_NetData;

// === ccNetInputBuffer_FrameData ===
// Per-frame sync flag element within the ring buffer.
typedef struct ccNetInputBuffer_FrameData {
    uint32_t unk_0x00;      // 0x0000
    uint32_t sync_flag;     // 0x0004
    uint8_t pad_trailing[24]; // 0x0008
} ccNetInputBuffer_FrameData;

// === ccNetInputBuffer ===
// Ring buffer holding 464 frames × 8 players × 0x20 bytes of input data.
// Size 0x1D024 carried from s3 (same engine, same buffer dimensions).
// state_surface confirms field at 0x0C (frame_data region via memset) and 0x1D01C (end_marker).
// frame_data size = 0x1D01C - 0x0C = 0x1D010 = 118800 bytes.
typedef struct ccNetInputBuffer {
    int64_t last_frame;     // 0x0000 — last processed frame (-1 = none)
    uint32_t frame_count;   // 0x0008 — current frame count
    uint8_t frame_data[118800]; // 0x000C — 464 frames × 8 players × 0x20 + alignment
    uint32_t end_marker;    // 0x1D01C
    uint8_t pad_trailing[4]; // 0x1D020
} __attribute__((packed)) ccNetInputBuffer;

// === ccNetBattleTimeLimit ===
// Small singleton UI timer class. 4 methods in s4 but no field accesses found via state_surface.
// Layout carried from s3 (same vtable pattern). Size = 0x28.
typedef struct ccNetBattleTimeLimit {
    uint64_t vtable;        // 0x0000
    uint32_t unk_0x08;      // 0x0008
    uint32_t unk_0x0C;      // 0x000C
    uint64_t unk_0x10;      // 0x0010
    uint64_t unk_0x18;      // 0x0018
    uint32_t mode_flag;     // 0x0020
    uint8_t pad_trailing[4]; // 0x0024
} ccNetBattleTimeLimit;

// === ccNetworkGameSyncTask ===
// Manages the active battle sync session. Holds pointer to ccNetFreeBattleSync at +0x00.
// state_surface shows field at 0x280 (read in IsWatchSide as inner sync object offset 0x50).
// dtor accesses param_1[0..5] as longlong*. Size unknown; own fields end at 0x28. Estimate ≥ 0x30.
typedef struct ccNetworkGameSyncTask {
    uint64_t sync_session_ptr;  // 0x0000 — pointer to ccNetFreeBattleSync
    uint64_t unk_0x08;          // 0x0008 — freed in dtor (callback/interface ptr)
    uint64_t unk_0x10;          // 0x0010 — freed in dtor (callback/interface ptr)
    float sync_timer;           // 0x0018 — float, updated in Ctrl (30.0/fps += timer)
    uint8_t pad_0x1C[4];        // 0x001C — explicit gap to align mode_id
    uint32_t mode_id;           // 0x0020 — 0=fighting, <0=watching
    uint32_t sync_state;        // 0x0024 — toggled 0/1 in Ctrl; checked in CheckOutOfSync
    uint8_t pad_trailing[8];    // 0x0028
} ccNetworkGameSyncTask;

// === ccNetFreeBattleSync ===
// Main P2P battle synchronization class. Core of Storm's network sync.
// Constructor takes (param_1, player_index, fallback_id, config_bytes[8], unk_param).
// Allocates internal buffer of 0x7080 bytes via MallocCore (stored at +0xF0 as ptr).
// Object fields span 0x00..0x257. Size ≥ 0x258 (no operator new size found for the object itself).
// Note: param_1 typed as undefined4* in ctor, so param_1[N] = byte offset N*4.
typedef struct ccNetFreeBattleSync {
    uint32_t mode;              // 0x0000 — set to 2 in ctor
    uint8_t pad_0x004[40];      // 0x0004
    int32_t player_index;       // 0x002C — param_1[0xb], local player side
    uint32_t peer_handle;       // 0x0030 — param_1[0xc], remote peer / fallback id
    uint8_t pad_0x034[1];       // 0x0034
    uint8_t config_0x35;        // 0x0035 — from param_4[1]
    uint8_t config_0x36;        // 0x0036 — from param_4[2]
    uint8_t config_0x37;        // 0x0037 — from param_4[3]
    uint8_t pad_0x038[1];       // 0x0038
    uint8_t config_0x39;        // 0x0039 — from param_4[5]
    uint8_t config_0x3A;        // 0x003A — from param_4[6]
    uint8_t config_0x3B;        // 0x003B — from param_4[7]
    uint32_t send_sequence;     // 0x003C — rw, incremented in UpdateWatchFrame
    uint32_t recv_frame_counter; // 0x0040 — rw, incremented in UpdateWatchFrame
    uint32_t synced_frame;      // 0x0044 — rw, last confirmed synced frame
    uint32_t battle_state;      // 0x0048 — read in CtrlFighting
    uint32_t coercion_flag;     // 0x004C — written in CtrlFighting
    uint32_t watch_mode;        // 0x0050 — read in UpdateWatchFrame
    uint32_t local_frame_result; // 0x0054 — written in UpdateFrame
    uint32_t remote_frame_number; // 0x0058 — written in SendDataToWatcherFromFighter/UpdateWatchFrame
    uint64_t send_buffer_ptr;   // 0x0060 — read in SendDataToWatcherFromFighter
    uint8_t pad_0x068[16];      // 0x0068
    uint32_t buffer_related;    // 0x0078 — rw, low confidence
    uint32_t unk_0x7C;          // 0x007C — written in SendDataToWatcherFromFighter
    uint64_t secondary_ptr;     // 0x0080 — read in SendDataToWatcherFromFighter
    uint8_t pad_0x088[24];      // 0x0088
    uint32_t ack_sequence;      // 0x00A0 — rw, acknowledgment sequence number
    uint32_t send_seq_copy;     // 0x00A4 — rw, copy of send_sequence
    uint8_t udp_socket[48];     // 0x00A8 — embedded ccNetUDPSocket (read in multiple funcs)
    uint64_t allocator_mgr_ptr; // 0x00D8 — read in AddNetDataToInputBuffer/CtrlFighting
    uint64_t secondary_buffer_ptr; // 0x00E0 — read in CtrlFighting/CtrlSendWatchData
    uint64_t heap_buffer_1;     // 0x00E8 — read in SendDataToWatcherFromFighter
    uint64_t heap_buffer_2;     // 0x00F0 — internal MallocCore buffer ptr (0x7080 bytes)
    uint32_t send_flag;         // 0x00F8 — rw, checked/set in CtrlFighting/SendDataToFighter
    uint32_t sync_state;        // 0x00FC — rw, checked in CtrlFighting/UpdateWatchFrame
    uint64_t vtable_or_allocator; // 0x0100
    uint8_t pad_0x108[304];     // 0x0108 — large uncharacterized region
    uint32_t field_0x238;       // 0x0238 — read in CtrlFighting/ReceiveWatchData
    uint32_t field_0x23C;       // 0x023C — read in ReceiveWatchData
    uint8_t pad_0x240[8];       // 0x0240
    uint64_t deque_ptr;         // 0x0248 — read in AddNetDataToInputBuffer
    uint64_t watch_data_ptr;    // 0x0250 — read in ReceiveWatchData
} ccNetFreeBattleSync;

// === ccNetFreeBattleSyncEX ===
// Extended subclass of ccNetFreeBattleSync. 2 methods in s4 (ctor only).
// state_surface shows fields at 0x80, 0x490, 0x498, 0x4A0, 0x4A4, 0x4A8, 0x4B0.
// Base class occupies 0x00..0x257; own fields start at 0x490+.
// Size ≥ 0x4B8 (last field at 0x4B0 + 8).
typedef struct ccNetFreeBattleSyncEX {
    uint8_t base[0x490];        // 0x0000 — ccNetFreeBattleSync base (size uncertain, padded to 0x490)
    uint64_t field_0x490;       // 0x0490 — written in ctor (ptr assignment)
    uint32_t field_0x498;       // 0x0498 — zeroed in ctor
    uint32_t field_0x49C_pad;   // 0x049C — padding
    uint32_t field_0x4A0;       // 0x04A0 — rw in ctor
    uint32_t field_0x4A4;       // 0x04A4 — rw in ctor
    uint32_t field_0x4A8;       // 0x04A8 — written in ctor (DAT_14161ffca == 0)
    uint32_t field_0x4AC_pad;   // 0x04AC — padding
    uint64_t field_0x4B0;       // 0x04B0 — written in ctor
} ccNetFreeBattleSyncEX;

// === ccNetRecordManagementCtrl ===
// 1 method in s4 but no field accesses found via state_surface.
// Not reconstructable from s4 alone; listed for completeness.

// === Absent classes in s4 ===
// ccNetRecordSyncCtrl — no symbols in s4
// ccNetBattleBeforeSync — no symbols in s4
// ccNetSyncParam — no symbols in s4 (struct may still exist, passed by value)
// ccNetBattleParam — no symbols in s4

// === Static assertions ===
STATIC_ASSERT(offsetof(ccNetSyncParam, field_0x00) == 0x0000, "ccNetSyncParam::field_0x00 offset");
STATIC_ASSERT(offsetof(ccNetSyncParam, field_0x04) == 0x0004, "ccNetSyncParam::field_0x04 offset");
STATIC_ASSERT(sizeof(ccNetSyncParam) == 0x0008, "ccNetSyncParam size");

STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, unk_0x00) == 0x0000, "ccNetInputBuffer_NetData::unk_0x00 offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, buttons) == 0x0004, "ccNetInputBuffer_NetData::buttons offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, input_word) == 0x0008, "ccNetInputBuffer_NetData::input_word offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, analog_l_x) == 0x000C, "ccNetInputBuffer_NetData::analog_l_x offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, analog_l_y) == 0x000E, "ccNetInputBuffer_NetData::analog_l_y offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, analog_r_x) == 0x0010, "ccNetInputBuffer_NetData::analog_r_x offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_NetData, analog_r_y) == 0x0012, "ccNetInputBuffer_NetData::analog_r_y offset");
STATIC_ASSERT(sizeof(ccNetInputBuffer_NetData) == 0x0018, "ccNetInputBuffer_NetData size");

STATIC_ASSERT(offsetof(ccNetInputBuffer_FrameData, unk_0x00) == 0x0000, "ccNetInputBuffer_FrameData::unk_0x00 offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer_FrameData, sync_flag) == 0x0004, "ccNetInputBuffer_FrameData::sync_flag offset");
STATIC_ASSERT(sizeof(ccNetInputBuffer_FrameData) == 0x0020, "ccNetInputBuffer_FrameData size");

STATIC_ASSERT(offsetof(ccNetInputBuffer, last_frame) == 0x0000, "ccNetInputBuffer::last_frame offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer, frame_count) == 0x0008, "ccNetInputBuffer::frame_count offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer, frame_data) == 0x000C, "ccNetInputBuffer::frame_data offset");
STATIC_ASSERT(offsetof(ccNetInputBuffer, end_marker) == 0x1D01C, "ccNetInputBuffer::end_marker offset");
STATIC_ASSERT(sizeof(ccNetInputBuffer) == 0x1D024, "ccNetInputBuffer size");

STATIC_ASSERT(offsetof(ccNetBattleTimeLimit, vtable) == 0x0000, "ccNetBattleTimeLimit::vtable offset");
STATIC_ASSERT(offsetof(ccNetBattleTimeLimit, unk_0x08) == 0x0008, "ccNetBattleTimeLimit::unk_0x08 offset");
STATIC_ASSERT(offsetof(ccNetBattleTimeLimit, unk_0x0C) == 0x000C, "ccNetBattleTimeLimit::unk_0x0C offset");
STATIC_ASSERT(offsetof(ccNetBattleTimeLimit, unk_0x10) == 0x0010, "ccNetBattleTimeLimit::unk_0x10 offset");
STATIC_ASSERT(offsetof(ccNetBattleTimeLimit, unk_0x18) == 0x0018, "ccNetBattleTimeLimit::unk_0x18 offset");
STATIC_ASSERT(offsetof(ccNetBattleTimeLimit, mode_flag) == 0x0020, "ccNetBattleTimeLimit::mode_flag offset");
STATIC_ASSERT(sizeof(ccNetBattleTimeLimit) == 0x0028, "ccNetBattleTimeLimit size");

STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, sync_session_ptr) == 0x0000, "ccNetworkGameSyncTask::sync_session_ptr offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, unk_0x08) == 0x0008, "ccNetworkGameSyncTask::unk_0x08 offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, unk_0x10) == 0x0010, "ccNetworkGameSyncTask::unk_0x10 offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, sync_timer) == 0x0018, "ccNetworkGameSyncTask::sync_timer offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, mode_id) == 0x0020, "ccNetworkGameSyncTask::mode_id offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, sync_state) == 0x0024, "ccNetworkGameSyncTask::sync_state offset");
STATIC_ASSERT(sizeof(ccNetworkGameSyncTask) == 0x0030, "ccNetworkGameSyncTask size");

STATIC_ASSERT(offsetof(ccNetFreeBattleSync, mode) == 0x0000, "ccNetFreeBattleSync::mode offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, player_index) == 0x002C, "ccNetFreeBattleSync::player_index offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, peer_handle) == 0x0030, "ccNetFreeBattleSync::peer_handle offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, config_0x35) == 0x0035, "ccNetFreeBattleSync::config_0x35 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, config_0x36) == 0x0036, "ccNetFreeBattleSync::config_0x36 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, config_0x37) == 0x0037, "ccNetFreeBattleSync::config_0x37 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, config_0x39) == 0x0039, "ccNetFreeBattleSync::config_0x39 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, config_0x3A) == 0x003A, "ccNetFreeBattleSync::config_0x3A offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, config_0x3B) == 0x003B, "ccNetFreeBattleSync::config_0x3B offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, send_sequence) == 0x003C, "ccNetFreeBattleSync::send_sequence offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, recv_frame_counter) == 0x0040, "ccNetFreeBattleSync::recv_frame_counter offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, synced_frame) == 0x0044, "ccNetFreeBattleSync::synced_frame offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, battle_state) == 0x0048, "ccNetFreeBattleSync::battle_state offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, coercion_flag) == 0x004C, "ccNetFreeBattleSync::coercion_flag offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, watch_mode) == 0x0050, "ccNetFreeBattleSync::watch_mode offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, local_frame_result) == 0x0054, "ccNetFreeBattleSync::local_frame_result offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, remote_frame_number) == 0x0058, "ccNetFreeBattleSync::remote_frame_number offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, send_buffer_ptr) == 0x0060, "ccNetFreeBattleSync::send_buffer_ptr offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, buffer_related) == 0x0078, "ccNetFreeBattleSync::buffer_related offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, unk_0x7C) == 0x007C, "ccNetFreeBattleSync::unk_0x7C offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, secondary_ptr) == 0x0080, "ccNetFreeBattleSync::secondary_ptr offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, ack_sequence) == 0x00A0, "ccNetFreeBattleSync::ack_sequence offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, send_seq_copy) == 0x00A4, "ccNetFreeBattleSync::send_seq_copy offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, udp_socket) == 0x00A8, "ccNetFreeBattleSync::udp_socket offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, allocator_mgr_ptr) == 0x00D8, "ccNetFreeBattleSync::allocator_mgr_ptr offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, secondary_buffer_ptr) == 0x00E0, "ccNetFreeBattleSync::secondary_buffer_ptr offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, heap_buffer_1) == 0x00E8, "ccNetFreeBattleSync::heap_buffer_1 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, heap_buffer_2) == 0x00F0, "ccNetFreeBattleSync::heap_buffer_2 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, send_flag) == 0x00F8, "ccNetFreeBattleSync::send_flag offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, sync_state) == 0x00FC, "ccNetFreeBattleSync::sync_state offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, vtable_or_allocator) == 0x0100, "ccNetFreeBattleSync::vtable_or_allocator offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, field_0x238) == 0x0238, "ccNetFreeBattleSync::field_0x238 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, field_0x23C) == 0x023C, "ccNetFreeBattleSync::field_0x23C offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, deque_ptr) == 0x0248, "ccNetFreeBattleSync::deque_ptr offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, watch_data_ptr) == 0x0250, "ccNetFreeBattleSync::watch_data_ptr offset");

STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, base) == 0x0000, "ccNetFreeBattleSyncEX::base offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, field_0x490) == 0x0490, "ccNetFreeBattleSyncEX::field_0x490 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, field_0x498) == 0x0498, "ccNetFreeBattleSyncEX::field_0x498 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, field_0x4A0) == 0x04A0, "ccNetFreeBattleSyncEX::field_0x4A0 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, field_0x4A4) == 0x04A4, "ccNetFreeBattleSyncEX::field_0x4A4 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, field_0x4A8) == 0x04A8, "ccNetFreeBattleSyncEX::field_0x4A8 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, field_0x4B0) == 0x04B0, "ccNetFreeBattleSyncEX::field_0x4B0 offset");