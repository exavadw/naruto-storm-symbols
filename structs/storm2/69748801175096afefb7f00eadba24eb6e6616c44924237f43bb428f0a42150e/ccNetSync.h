#pragma once

// ccNetSync.h — Network synchronization structs for NSUNS2 (s2 build)
// Generated with explicit padding to match MSVC x64 ABI layout.
// All offsets verified against decompiled code from NSUNS2.exe (base 0x140000000).

#include <stdint.h>
#include <stddef.h>

// C11/C++ static_assert compatibility
#ifdef __cplusplus
#define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
#define STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

typedef struct ccNetSyncParam {
    uint32_t field_0x00; // 0x0000
    uint32_t field_0x04; // 0x0004
} ccNetSyncParam;

typedef struct ccNetInputBuffer_NetData {
    uint32_t unk_0x00; // 0x0000
    uint32_t buttons; // 0x0004
    uint32_t input_word; // 0x0008
    int16_t analog_l_x; // 0x000C
    int16_t analog_l_y; // 0x000E
    int16_t analog_r_x; // 0x0010
    int16_t analog_r_y; // 0x0012
    uint8_t pad_trailing[4]; // 0x0014
} ccNetInputBuffer_NetData;

typedef struct ccNetInputBuffer_FrameData {
    uint32_t unk_0x00; // 0x0000
    uint32_t sync_flag; // 0x0004
    uint8_t pad_trailing[24]; // 0x0008
} ccNetInputBuffer_FrameData;

typedef struct ccNetInputBuffer {
    int64_t last_frame; // 0x0000
    uint32_t frame_count; // 0x0008
    uint8_t frame_data[118800]; // 0x000C
    uint32_t end_marker; // 0x1D01C
    uint8_t pad_trailing[4]; // 0x1D020
} __attribute__((packed)) ccNetInputBuffer;

typedef struct ccNetworkGameSyncTask {
    uint64_t inner_ptr; // 0x0000
    uint8_t pad_0x008[36]; // 0x0008
    uint32_t start_frame_sync_flag; // 0x002C
    uint32_t unk_0x30; // 0x0030
    uint32_t draw_frame_stop_flag; // 0x0034
    uint8_t pad_trailing[8]; // 0x0038
} ccNetworkGameSyncTask;

typedef struct ccNetRecordSyncCtrl {
    uint64_t vtable; // 0x0000
    uint8_t pad_0x008[16]; // 0x0008
    uint32_t mode_id; // 0x0018
    uint64_t unk_0x20; // 0x0020
    uint8_t pad_0x028[8]; // 0x0028
    uint64_t unk_0x30; // 0x0030
    uint32_t unk_0x38; // 0x0038
    uint64_t unk_0x40; // 0x0040
    uint64_t unk_0x48; // 0x0048
    uint64_t unk_0x50; // 0x0050
    uint64_t field_0x58; // 0x0058
    uint64_t data_table_ptr; // 0x0060
    uint64_t unk_0x68; // 0x0068
    uint64_t unk_0x70; // 0x0070
    uint32_t sentinel; // 0x0078
    uint64_t vtable_call_slot; // 0x0080
} ccNetRecordSyncCtrl;

typedef struct ccNetRecordManagementCtrl {
    uint64_t vtable; // 0x0000
    uint8_t pad_0x008[16]; // 0x0008
    uint64_t type_tag; // 0x0018
    uint64_t data_table_ptr; // 0x0020
    uint64_t unk_0x28; // 0x0028
    uint64_t unk_0x30; // 0x0030
    uint32_t sentinel; // 0x0038
    uint64_t unk_0x40; // 0x0040
    uint32_t mode_param; // 0x0048
    uint32_t unk_0x4C_zero; // 0x004C
    uint32_t unk_0x50; // 0x0050
    uint32_t sync_param_1_field_0x00; // 0x0054
    uint32_t sync_param_1_field_0x04; // 0x0058
    uint32_t sync_param_2_field_0x00; // 0x005C
    uint32_t sync_param_2_field_0x04; // 0x0060
    uint8_t pad_0x064[28]; // 0x0064
    uint64_t vtable_call_slot; // 0x0080
} ccNetRecordManagementCtrl;

typedef struct ccNetFreeBattleSync {
    uint32_t mode; // 0x0000
    uint8_t pad_0x004[40]; // 0x0004
    int32_t player_index; // 0x002C
    uint32_t peer_handle; // 0x0030
    uint8_t pad_0x034[1]; // 0x0034
    uint8_t config_0x35; // 0x0035
    uint8_t config_0x36; // 0x0036
    uint8_t config_0x37; // 0x0037
    uint8_t pad_0x038[1]; // 0x0038
    uint8_t config_0x39; // 0x0039
    uint8_t config_0x3A; // 0x003A
    uint8_t config_0x3B; // 0x003B
    uint32_t send_sequence; // 0x003C
    uint32_t recv_frame_counter; // 0x0040
    uint32_t synced_frame; // 0x0044
    uint32_t battle_state; // 0x0048
    uint32_t coercion_flag; // 0x004C
    uint32_t watch_mode; // 0x0050
    uint32_t local_frame_result; // 0x0054
    uint32_t remote_frame_number; // 0x0058
    uint64_t send_buffer_ptr; // 0x0060
    uint8_t pad_0x068[16]; // 0x0068
    uint32_t buffer_related; // 0x0078
    uint32_t unk_0x7C; // 0x007C
    uint64_t secondary_ptr; // 0x0080
    uint8_t pad_0x088[24]; // 0x0088
    uint32_t ack_sequence; // 0x00A0
    uint32_t send_seq_copy; // 0x00A4
    uint8_t udp_socket[48]; // 0x00A8
    uint64_t allocator_mgr_ptr; // 0x00D8
    uint64_t secondary_buffer_ptr; // 0x00E0
    uint64_t heap_buffer_1; // 0x00E8
    uint64_t heap_buffer_2; // 0x00F0
    uint32_t send_flag; // 0x00F8
    uint32_t sync_state; // 0x00FC
    uint64_t vtable_or_allocator; // 0x0100
    uint8_t pad_0x108[320]; // 0x0108
    uint64_t deque_ptr; // 0x0248
    uint64_t watch_data_ptr; // 0x0250
    uint8_t pad_trailing[8]; // 0x0258
} ccNetFreeBattleSync;

typedef struct ccNetFreeBattleSyncEX {
    uint64_t vtable;                    // 0x0000
    uint8_t base_bytes[0x248];          // 0x0008 — ccNetFreeBattleSync[0x00..0x247]
    uint64_t ex_field_0x250;            // 0x0250
    uint64_t ex_field_0x258;            // 0x0258
    uint64_t ex_cleanup_ptr_1;          // 0x0260
    uint64_t ex_cleanup_ptr_2;          // 0x0268
    uint32_t ex_param_0;                // 0x0270
    uint32_t ex_param_1;                // 0x0274
    uint32_t ex_param_2;                // 0x0278
    uint32_t ex_param_3;                // 0x027C
    uint64_t ex_param_4;                // 0x0280
    uint32_t ex_param_6;                // 0x0288
    uint8_t pad_trailing[4];            // 0x028C
} ccNetFreeBattleSyncEX;

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
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, inner_ptr) == 0x0000, "ccNetworkGameSyncTask::inner_ptr offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, start_frame_sync_flag) == 0x002C, "ccNetworkGameSyncTask::start_frame_sync_flag offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, unk_0x30) == 0x0030, "ccNetworkGameSyncTask::unk_0x30 offset");
STATIC_ASSERT(offsetof(ccNetworkGameSyncTask, draw_frame_stop_flag) == 0x0034, "ccNetworkGameSyncTask::draw_frame_stop_flag offset");
STATIC_ASSERT(sizeof(ccNetworkGameSyncTask) == 0x0040, "ccNetworkGameSyncTask size");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, vtable) == 0x0000, "ccNetRecordSyncCtrl::vtable offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, mode_id) == 0x0018, "ccNetRecordSyncCtrl::mode_id offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x20) == 0x0020, "ccNetRecordSyncCtrl::unk_0x20 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x30) == 0x0030, "ccNetRecordSyncCtrl::unk_0x30 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x38) == 0x0038, "ccNetRecordSyncCtrl::unk_0x38 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x40) == 0x0040, "ccNetRecordSyncCtrl::unk_0x40 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x48) == 0x0048, "ccNetRecordSyncCtrl::unk_0x48 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x50) == 0x0050, "ccNetRecordSyncCtrl::unk_0x50 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, field_0x58) == 0x0058, "ccNetRecordSyncCtrl::field_0x58 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, data_table_ptr) == 0x0060, "ccNetRecordSyncCtrl::data_table_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x68) == 0x0068, "ccNetRecordSyncCtrl::unk_0x68 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, unk_0x70) == 0x0070, "ccNetRecordSyncCtrl::unk_0x70 offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, sentinel) == 0x0078, "ccNetRecordSyncCtrl::sentinel offset");
STATIC_ASSERT(offsetof(ccNetRecordSyncCtrl, vtable_call_slot) == 0x0080, "ccNetRecordSyncCtrl::vtable_call_slot offset");
STATIC_ASSERT(sizeof(ccNetRecordSyncCtrl) == 0x0088, "ccNetRecordSyncCtrl size");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, vtable) == 0x0000, "ccNetRecordManagementCtrl::vtable offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, type_tag) == 0x0018, "ccNetRecordManagementCtrl::type_tag offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, data_table_ptr) == 0x0020, "ccNetRecordManagementCtrl::data_table_ptr offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, unk_0x28) == 0x0028, "ccNetRecordManagementCtrl::unk_0x28 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, unk_0x30) == 0x0030, "ccNetRecordManagementCtrl::unk_0x30 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, sentinel) == 0x0038, "ccNetRecordManagementCtrl::sentinel offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, unk_0x40) == 0x0040, "ccNetRecordManagementCtrl::unk_0x40 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, mode_param) == 0x0048, "ccNetRecordManagementCtrl::mode_param offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, unk_0x4C_zero) == 0x004C, "ccNetRecordManagementCtrl::unk_0x4C_zero offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, unk_0x50) == 0x0050, "ccNetRecordManagementCtrl::unk_0x50 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, sync_param_1_field_0x00) == 0x0054, "ccNetRecordManagementCtrl::sync_param_1_field_0x00 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, sync_param_1_field_0x04) == 0x0058, "ccNetRecordManagementCtrl::sync_param_1_field_0x04 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, sync_param_2_field_0x00) == 0x005C, "ccNetRecordManagementCtrl::sync_param_2_field_0x00 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, sync_param_2_field_0x04) == 0x0060, "ccNetRecordManagementCtrl::sync_param_2_field_0x04 offset");
STATIC_ASSERT(offsetof(ccNetRecordManagementCtrl, vtable_call_slot) == 0x0080, "ccNetRecordManagementCtrl::vtable_call_slot offset");
STATIC_ASSERT(sizeof(ccNetRecordManagementCtrl) == 0x0088, "ccNetRecordManagementCtrl size");
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
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, deque_ptr) == 0x0248, "ccNetFreeBattleSync::deque_ptr offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSync, watch_data_ptr) == 0x0250, "ccNetFreeBattleSync::watch_data_ptr offset");
STATIC_ASSERT(sizeof(ccNetFreeBattleSync) == 0x0260, "ccNetFreeBattleSync size");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, vtable) == 0x0000, "ccNetFreeBattleSyncEX::vtable offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, base_bytes) == 0x0008, "ccNetFreeBattleSyncEX::base_bytes offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, ex_field_0x250) == 0x0250, "ccNetFreeBattleSyncEX::ex_field_0x250 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, ex_cleanup_ptr_1) == 0x0260, "ccNetFreeBattleSyncEX::ex_cleanup_ptr_1 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, ex_param_0) == 0x0270, "ccNetFreeBattleSyncEX::ex_param_0 offset");
STATIC_ASSERT(offsetof(ccNetFreeBattleSyncEX, ex_param_6) == 0x0288, "ccNetFreeBattleSyncEX::ex_param_6 offset");
STATIC_ASSERT(sizeof(ccNetFreeBattleSyncEX) == 0x0290, "ccNetFreeBattleSyncEX size");
