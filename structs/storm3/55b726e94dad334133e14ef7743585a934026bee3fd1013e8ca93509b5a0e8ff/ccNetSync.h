#pragma once

// ccNetSync.h — Network synchronization structs for NSUNS3 (s3 build)
// Generated with explicit padding to match MSVC x64 ABI layout.
// All offsets verified against decompiled code from NSUNS3.exe (base 0x140000000).
// Status: INFERRED from static analysis only. Not CONFIRMED at runtime.

#include <stdint.h>
#include <stddef.h>

// C11/C++ static_assert compatibility
#ifdef __cplusplus
#define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
#define STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

// === ccNetSyncParam ===
// No methods found in s3 build. Carried from s2 layout (own-game names only).
// Likely an empty/trivial param struct passed by value.
typedef struct ccNetSyncParam {
    uint32_t field_0x00; // 0x0000
    uint32_t field_0x04; // 0x0004
} ccNetSyncParam;

// === ccNetInputBuffer_NetData ===
// Per-player input data within the ring buffer. Layout carried from s2 (same engine).
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
// Size 0x1D024 carried from s2 (same engine, same buffer dimensions).
// state_surface confirms field at 0x0C (frame_data region) and 0x1D01C (end_marker).
// frame_data size = 0x1D01C - 0x0C = 0x1D010 = 118800 bytes.
typedef struct ccNetInputBuffer {
    int64_t last_frame;     // 0x0000 — last processed frame (-1 = none)
    uint32_t frame_count;   // 0x0008 — current frame count
    uint8_t frame_data[118800]; // 0x000C — 464 frames × 8 players × 0x20 + alignment
    uint32_t end_marker;    // 0x1D01C
    uint8_t pad_trailing[4]; // 0x1D020
} __attribute__((packed)) ccNetInputBuffer;

// === ccNetBattleTimeLimit ===
// Small singleton UI timer class. CreateInstance allocates 0x28 bytes via LoadTh.
// Vtable at +0x00, fields at +0x04, +0x08, +0x0C.
typedef struct ccNetBattleTimeLimit {
    uint64_t vtable;        // 0x0000
    uint32_t unk_0x08;      // 0x0008
    uint32_t unk_0x0C;      // 0x000C
    uint64_t unk_0x10;      // 0x0010
    uint64_t unk_0x18;      // 0x0018
    uint32_t mode_flag;     // 0x0020
    uint8_t pad_trailing[4]; // 0x0024
} ccNetBattleTimeLimit;

// === ccNetBattleBeforeSync ===
// Pre-battle sync task. Extends ccTaskBase (vtable at +0x00, task fields at +0x08..+0x53).
// Own fields start at +0x54 per ctor writes. Size ≥ 0x88.
// ccTaskBase occupies 0x00..0x53 (84 bytes total: vtable@0x00 + body[76]@0x08).
// Uses packed attribute because field_0x54 (uint64_t) sits at offset 0x54 (84),
// which is not 8-byte aligned. Explicit pads restore alignment gaps at 0x64 and 0x7C.
typedef struct __attribute__((packed)) ccNetBattleBeforeSync {
    uint64_t vtable;            // 0x0000 — PTR_FUN_14096cb40
    uint8_t ccTaskBase_body[76]; // 0x0008 — ccTaskBase inherited fields (0x08..0x53)
    uint64_t field_0x54;        // 0x0054 — zeroed in ctor
    uint32_t field_0x5C;        // 0x005C — zeroed in ctor
    uint32_t field_0x60;        // 0x0060
    uint8_t pad_0x064[4];       // 0x0064 — explicit gap before aligned uint64_t
    uint64_t field_0x68;        // 0x0068
    uint32_t field_0x70;        // 0x0070
    uint32_t field_0x74;        // 0x0074 — set to -1 in ctor
    uint32_t field_0x78;        // 0x0078
    uint8_t pad_0x07C[4];       // 0x007C — explicit gap before aligned uint64_t
    uint64_t field_0x80;        // 0x0080
} ccNetBattleBeforeSync;

// === ccNetworkGameSyncTask ===
// Manages the active battle sync session. Holds pointer to ccNetFreeBattleSync at +0x00.
// dtor accesses param_1[0..5] as longlong*. state_surface shows field at 0x24 (sync_state).
// Large accesses at 0x240, 0x260, 0x7E0 likely reach into the inner ccNetFreeBattleSync.
// Size unknown; own fields end at 0x28. Estimate ≥ 0x30.
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

// === ccNetRecordSyncCtrl ===
// Record upload sync controller. Has vtable, creates dialog and online storage.
// Initialize accesses param_1 as longlong*: indices 1,2,3,4,6,8,9.
// state_surface confirms field at 0x58 (rw) and 0x80 (r, vtable call slot).
// Size ≥ 0x88 (matches s2 layout).
// Natural alignment with explicit 8-byte pad at 0x50 to push field_0x58 to offset 88.
typedef struct ccNetRecordSyncCtrl {
    uint64_t vtable;            // 0x0000
    uint64_t unk_0x08;          // 0x0008
    uint64_t unk_0x10;          // 0x0010
    uint64_t record_list_ptr;   // 0x0018 — param_1[3], iterated in Initialize
    uint64_t record_data_ptr;   // 0x0020 — param_1[4], base of record array (stride 0x28)
    uint8_t pad_0x028[8];       // 0x0028
    uint64_t active_record_ptr; // 0x0030 — param_1[6], set to first empty slot
    uint8_t pad_0x038[8];       // 0x0038
    uint64_t online_storage_ptr; // 0x0040 — param_1[8], zeroed then set
    uint64_t ccINetOnlineStorage_ptr; // 0x0048 — param_1[9], from ccINetOnlineStorage::Create
    uint8_t pad_0x050[8];       // 0x0050 — explicit gap: natural align would place next uint64_t at 0x50
    uint64_t field_0x58;        // 0x0058 — rw in EnterRetryAsk
    uint8_t pad_0x060[32];      // 0x0060
    uint64_t vtable_call_slot;  // 0x0080 — read in CreateDialog/EnterRetryAsk/Initialize
} ccNetRecordSyncCtrl;

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
// Extended subclass of ccNetFreeBattleSync. No methods found in s3 build.
// Layout carried from s2 where it was 0x290 bytes with base at +0x08.
// Not reconstructable from s3 alone; listed for completeness.

// === Absent classes in s3 ===
// ccNetFreeBattleSyncEX — no symbols in s3
// ccNetRecordManagementCtrl — no symbols in s3
// ccNetSyncParam — no symbols in s3 (struct may still exist, passed by value)
// ccNetBattleParam — 4 methods exist but state_surface found 0 fields (likely interface/empty)

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

STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, vtable) == 0x0000, "ccNetBattleBeforeSync::vtable offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x54) == 0x0054, "ccNetBattleBeforeSync::field_0x54 offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x5C) == 0x005C, "ccNetBattleBeforeSync::field_0x5C offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x60) == 0x0060, "ccNetBattleBeforeSync::field_0x60 offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x68) == 0x0068, "ccNetBattleBeforeSync::field_0x68 offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x70) == 0x0070, "ccNetBattleBeforeSync::field_0x70 offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x74) == 0x0074, "ccNetBattleBeforeSync::field_0x74 offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x78) == 0x0078, "ccNetBattleBeforeSync::field_0x78 offset");
STATIC_ASSERT(offsetof(ccNetBattleBeforeSync, field_0x80) == 0x0080, "ccNetBattleBeforeSync::field_0x80 offset");

STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, sync_session_ptr) == 0x0000, "ccNetworkGameSyncTask::sync_session_ptr offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, unk_0x08) == 0x0008, "ccNetworkGameSyncTask::unk_0x08 offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, unk_0x10) == 0x0010, "ccNetworkGameSyncTask::unk_0x10 offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, sync_timer) == 0x0018, "ccNetworkGameSyncTask::sync_timer offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, mode_id) == 0x0020, "ccNetworkGameSyncTask::mode_id offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, sync_state) == 0x0024, "ccNetworkGameSyncTask::sync_state offset");
STATIC_ASSERT(sizeof(ccNetworkGameSyncTask) == 0x0030, "ccNetworkGameSyncTask size");

STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, vtable) == 0x0000, "ccNetRecordSyncCtrl::vtable offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, record_list_ptr) == 0x0018, "ccNetRecordSyncCtrl::record_list_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, record_data_ptr) == 0x0020, "ccNetRecordSyncCtrl::record_data_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, active_record_ptr) == 0x0030, "ccNetRecordSyncCtrl::active_record_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, online_storage_ptr) == 0x0040, "ccNetRecordSyncCtrl::online_storage_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, ccINetOnlineStorage_ptr) == 0x0048, "ccNetRecordSyncCtrl::ccINetOnlineStorage_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, field_0x58) == 0x0058, "ccNetRecordSyncCtrl::field_0x58 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, vtable_call_slot) == 0x0080, "ccNetRecordSyncCtrl::vtable_call_slot offset");

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