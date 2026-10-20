// cmn25.h — Storm 1 (NSUNS1.exe) cmn25 class group struct layouts
// Build: s1 / NSUNS1.exe-a9fe00, SHA 10231093af9c
// Generated from manual decompilation of Ghidra pseudocode (34 functions, all cache hits).
// All results are INFERRED from static analysis, not CONFIRMED at runtime.
// state_surface failed for most classes (byte-cast access patterns);
// fields extracted by reading decompiled code directly.

#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

// ============================================================================
// mmController_Win — DirectInput/XInput controller wrapper
// Min size: 0x150 (last known field at 0x148 + ptr)
// Size unproven beyond last accessed field; no operator new found.
// ============================================================================
struct __attribute__((packed)) mmController_Win {
    uint8_t pad_00[0x08];           // 0x00-0x07: vtable or unknown
    uint8_t active_flag;            // 0x08: set 1 in UpdateDirectInput, cleared 0 in Update
    uint8_t pad_09[0x03];           // 0x09-0x0B: padding
    uint32_t button_state;          // 0x0C: accumulated button bitmask
    uint32_t buttons_pressed;       // 0x10: edge-detected pressed (current & ~prev)
    uint32_t buttons_released;      // 0x14: edge-detected released (~current & prev)
    uint8_t pad_18[0x04];           // 0x18-0x1B: padding
    float axis_x;                   // 0x1C: normalized -1.0..1.0, deadzone 0.12
    float axis_y;                   // 0x20: normalized -1.0..1.0, deadzone 0.12
    float axis_z;                   // 0x24: normalized -1.0..1.0, deadzone 0.12
    float axis_w;                   // 0x28: normalized -1.0..1.0, deadzone 0.12
    uint8_t pad_2C[0x64];           // 0x2C-0x8F: large gap, likely DIJOYSTATE or similar
    void* mapping_table_base;       // 0x90: hash table base pointer
    uint32_t mapping_table_size;    // 0x98: modulus for bucket index
    uint8_t pad_9C[0xA0];           // 0x9C-0x13B: large gap
    int32_t input_mode;             // 0x13C: 1=XInput/keyboard, 2=DirectInput
    uint8_t pad_140[0x08];          // 0x140-0x147: padding
    void* direct_input_device;      // 0x148: IDirectInputDevice8* COM interface
};

static_assert(offsetof(struct mmController_Win, active_flag) == 0x08, "mmController_Win::active_flag");
static_assert(offsetof(struct mmController_Win, button_state) == 0x0C, "mmController_Win::button_state");
static_assert(offsetof(struct mmController_Win, buttons_pressed) == 0x10, "mmController_Win::buttons_pressed");
static_assert(offsetof(struct mmController_Win, buttons_released) == 0x14, "mmController_Win::buttons_released");
static_assert(offsetof(struct mmController_Win, axis_x) == 0x1C, "mmController_Win::axis_x");
static_assert(offsetof(struct mmController_Win, axis_y) == 0x20, "mmController_Win::axis_y");
static_assert(offsetof(struct mmController_Win, axis_z) == 0x24, "mmController_Win::axis_z");
static_assert(offsetof(struct mmController_Win, axis_w) == 0x28, "mmController_Win::axis_w");
static_assert(offsetof(struct mmController_Win, mapping_table_base) == 0x90, "mmController_Win::mapping_table_base");
static_assert(offsetof(struct mmController_Win, mapping_table_size) == 0x98, "mmController_Win::mapping_table_size");
static_assert(offsetof(struct mmController_Win, input_mode) == 0x13C, "mmController_Win::input_mode");
static_assert(offsetof(struct mmController_Win, direct_input_device) == 0x148, "mmController_Win::direct_input_device");

// ============================================================================
// mmConstantBuffer — D3D constant buffer wrapper
// Size: 0x30 (allocated via _aligned_malloc with size 0x30 in Create)
// ============================================================================
struct __attribute__((packed)) mmConstantBuffer {
    void* buffer_ptr;               // 0x00: buffer pointer or size param
    void* d3d_buffer;               // 0x08: D3D buffer handle (ptr-to-ptr in Bind)
    int32_t lock_state;             // 0x10: 0=unlocked, 1=locked
    uint8_t lock_flag;              // 0x14: byte flag, set 1 in Lock, cleared 0 in Unlock
    uint8_t pad_15[0x03];           // 0x15-0x17: padding
    void* lock_output_ptr;          // 0x18: output pointer param from Lock
    uint64_t lock_param3;           // 0x20: third Lock parameter storage
    void* mapped_data;              // 0x28: mapped data pointer from Lock
};

static_assert(offsetof(struct mmConstantBuffer, buffer_ptr) == 0x00, "mmConstantBuffer::buffer_ptr");
static_assert(offsetof(struct mmConstantBuffer, d3d_buffer) == 0x08, "mmConstantBuffer::d3d_buffer");
static_assert(offsetof(struct mmConstantBuffer, lock_state) == 0x10, "mmConstantBuffer::lock_state");
static_assert(offsetof(struct mmConstantBuffer, lock_flag) == 0x14, "mmConstantBuffer::lock_flag");
static_assert(offsetof(struct mmConstantBuffer, lock_output_ptr) == 0x18, "mmConstantBuffer::lock_output_ptr");
static_assert(offsetof(struct mmConstantBuffer, lock_param3) == 0x20, "mmConstantBuffer::lock_param3");
static_assert(offsetof(struct mmConstantBuffer, mapped_data) == 0x28, "mmConstantBuffer::mapped_data");

// ============================================================================
// mmCoreLibrary_Config — Engine core initialization config parameter
// No instance state: Initialize takes a config struct pointer; the actual
// singleton lives at global DAT_140883420. The config struct layout below
// is the parameter passed to Initialize, NOT an object with a vtable.
// Evidence: mmCoreLibrary::Initialize(uint *param_1, ...) reads sequential
// uint32 values from param_1 at offsets 0x00..0x20.
// Config struct size: >= 0x24
// ============================================================================
struct __attribute__((packed)) mmCoreLibrary_Config {
    uint32_t config_0;              // 0x00
    uint32_t config_1;              // 0x04
    uint32_t config_2;              // 0x08
    uint32_t config_3;              // 0x0C
    uint32_t config_4;              // 0x10
    uint32_t config_5;              // 0x14
    void* config_6;                 // 0x18: pointer
    uint32_t config_7;              // 0x20
};

static_assert(offsetof(struct mmCoreLibrary_Config, config_0) == 0x00, "mmCoreLibrary_Config::config_0");
static_assert(offsetof(struct mmCoreLibrary_Config, config_1) == 0x04, "mmCoreLibrary_Config::config_1");
static_assert(offsetof(struct mmCoreLibrary_Config, config_2) == 0x08, "mmCoreLibrary_Config::config_2");
static_assert(offsetof(struct mmCoreLibrary_Config, config_3) == 0x0C, "mmCoreLibrary_Config::config_3");
static_assert(offsetof(struct mmCoreLibrary_Config, config_4) == 0x10, "mmCoreLibrary_Config::config_4");
static_assert(offsetof(struct mmCoreLibrary_Config, config_5) == 0x14, "mmCoreLibrary_Config::config_5");
static_assert(offsetof(struct mmCoreLibrary_Config, config_6) == 0x18, "mmCoreLibrary_Config::config_6");
static_assert(offsetof(struct mmCoreLibrary_Config, config_7) == 0x20, "mmCoreLibrary_Config::config_7");

// ============================================================================
// mmCompileInfo — Compilation error/warning message container
// Layout: array of 0x50-byte sub-struct slots indexed by type code
// Sub-struct stride: 0x50 (from Reset switch: case 7->+0x08, case 8->+0x58, etc.)
// Total size: >= 0x4B0 (15 slots x 0x50 from offset 0x08)
// ============================================================================
struct __attribute__((packed)) mmCompileInfo_SubSlot {
    uint8_t data[0x50];             // 0x50 bytes per slot
};

struct __attribute__((packed)) mmCompileInfo {
    uint8_t pad_00[0x08];           // 0x00-0x07: unknown/vtable
    struct mmCompileInfo_SubSlot slots[15]; // 0x08: 15 slots x 0x50 = 0x4B0 total
};

static_assert(offsetof(struct mmCompileInfo, slots) == 0x08, "mmCompileInfo::slots");

// Linked-list node used internally by mmCompileInfo destructor
struct __attribute__((packed)) mmCompileInfo_Node {
    struct mmCompileInfo_Node* next; // 0x00: next node in linked list
    uint8_t pad_08[0x08];           // 0x08-0x0F: unknown
    void* data_begin;               // 0x10: begin iterator
    uint8_t pad_18[0x08];           // 0x18-0x1F: unknown
    void* data_end;                 // 0x20: end iterator
    uint8_t pad_28[0x08];           // 0x28-0x2F: unknown (vtable/release fn at [5])
};

static_assert(offsetof(struct mmCompileInfo_Node, next) == 0x00, "mmCompileInfo_Node::next");
static_assert(offsetof(struct mmCompileInfo_Node, data_begin) == 0x10, "mmCompileInfo_Node::data_begin");
static_assert(offsetof(struct mmCompileInfo_Node, data_end) == 0x20, "mmCompileInfo_Node::data_end");

// ============================================================================
// mmAppMemorySegment — Memory pool allocator with 3D block tracking
// Min size: 0x98 (last known field at 0x90 + ptr)
// Singleton accessed via GetInstance; size unproven beyond last field.
// Offsets below are the ACTUAL byte offsets from the binary (decompiled code).
// With __attribute__((packed)), explicit padding preserves these exact offsets.
// ============================================================================
struct __attribute__((packed)) mmAppMemorySegment {
    uint8_t pad_00[0x08];           // 0x00-0x07: vtable or unknown
    void* segment_base_1;           // 0x08: first segment base pointer
    uint32_t segment_flags_1;       // 0x10: size or flags for segment 1
    void* segment_base_2;           // 0x14: second segment base pointer
    uint32_t segment_flags_2;       // 0x1C: size or flags for segment 2
    void* segment_base_3;           // 0x20: third segment base pointer
    uint32_t segment_flags_3;       // 0x28: size or flags for segment 3
    int32_t dim_x;                  // 0x2C: X dimension count
    int32_t dim_y;                  // 0x30: Y dimension count
    int32_t dim_z;                  // 0x34: Z dimension count
    void* unknown_obj;              // 0x38: freed on reset if non-null
    void** block_array;             // 0x40: 3D array of pointers [z][y][x]
    uint32_t reset_flag;            // 0x48: cleared to 0 on reset
    uint8_t pad_4C[0x04];           // 0x4C-0x4F: padding
    void* vector_begin;             // 0x50: std::vector-like begin
    void* vector_end;               // 0x58: std::vector-like end
    uint8_t pad_60[0x08];           // 0x60-0x67: gap
    uint8_t vector_internal[0x10];  // 0x68: passed to FUN_14047f280
    uint8_t pad_78[0x10];           // 0x78-0x87: gap
    void* handle_1;                 // 0x88: freed via global DAT_1408c7ba8
    void* handle_2;                 // 0x90: freed via global DAT_1408c7ba8
};

static_assert(offsetof(struct mmAppMemorySegment, segment_base_1) == 0x08, "mmAppMemorySegment::segment_base_1");
static_assert(offsetof(struct mmAppMemorySegment, segment_flags_1) == 0x10, "mmAppMemorySegment::segment_flags_1");
static_assert(offsetof(struct mmAppMemorySegment, segment_base_2) == 0x14, "mmAppMemorySegment::segment_base_2");
static_assert(offsetof(struct mmAppMemorySegment, segment_flags_2) == 0x1C, "mmAppMemorySegment::segment_flags_2");
static_assert(offsetof(struct mmAppMemorySegment, segment_base_3) == 0x20, "mmAppMemorySegment::segment_base_3");
static_assert(offsetof(struct mmAppMemorySegment, segment_flags_3) == 0x28, "mmAppMemorySegment::segment_flags_3");
static_assert(offsetof(struct mmAppMemorySegment, dim_x) == 0x2C, "mmAppMemorySegment::dim_x");
static_assert(offsetof(struct mmAppMemorySegment, dim_y) == 0x30, "mmAppMemorySegment::dim_y");
static_assert(offsetof(struct mmAppMemorySegment, dim_z) == 0x34, "mmAppMemorySegment::dim_z");
static_assert(offsetof(struct mmAppMemorySegment, unknown_obj) == 0x38, "mmAppMemorySegment::unknown_obj");
static_assert(offsetof(struct mmAppMemorySegment, block_array) == 0x40, "mmAppMemorySegment::block_array");
static_assert(offsetof(struct mmAppMemorySegment, reset_flag) == 0x48, "mmAppMemorySegment::reset_flag");
static_assert(offsetof(struct mmAppMemorySegment, vector_begin) == 0x50, "mmAppMemorySegment::vector_begin");
static_assert(offsetof(struct mmAppMemorySegment, vector_end) == 0x58, "mmAppMemorySegment::vector_end");
static_assert(offsetof(struct mmAppMemorySegment, vector_internal) == 0x68, "mmAppMemorySegment::vector_internal");
static_assert(offsetof(struct mmAppMemorySegment, handle_1) == 0x88, "mmAppMemorySegment::handle_1");
static_assert(offsetof(struct mmAppMemorySegment, handle_2) == 0x90, "mmAppMemorySegment::handle_2");

// ============================================================================
// mmBufferBindInfo — Vertex/index buffer binding descriptor
// Min size: 0x64 (last known field at 0x60 + int32)
// ============================================================================
struct __attribute__((packed)) mmBufferBindInfo {
    uint8_t pad_00[0x18];           // 0x00-0x17: unknown header
    uint8_t sub_object[0x10];       // 0x18: passed to FUN_14011c6d0
    uint8_t pad_28[0x34];           // 0x28-0x5B: gap
    uint32_t total_stride;          // 0x5C: accumulated stride from Create loop
    int32_t stride_per_element;     // 0x60: param_4 / total_stride
};

static_assert(offsetof(struct mmBufferBindInfo, sub_object) == 0x18, "mmBufferBindInfo::sub_object");
static_assert(offsetof(struct mmBufferBindInfo, total_stride) == 0x5C, "mmBufferBindInfo::total_stride");
static_assert(offsetof(struct mmBufferBindInfo, stride_per_element) == 0x60, "mmBufferBindInfo::stride_per_element");

// ============================================================================
// mmComputeShader — Compute shader resource holder
// Known field at 0xF0; full layout unknown (LoadFromCompiledFile uses only stack)
// Min size: 0xF8
// ============================================================================
struct __attribute__((packed)) mmComputeShader {
    uint8_t pad_00[0xF0];           // 0x00-0xEF: unknown (likely D3D shader blob, CSO data)
    void* shader_resource;          // 0xF0: freed via FUN_140112f10 on Release
};

static_assert(offsetof(struct mmComputeShader, shader_resource) == 0xF0, "mmComputeShader::shader_resource");

// ============================================================================
// mmDrawCommand::QuadRenderer — Global singleton (NO INSTANCE STATE)
// Lives at DAT_140b8d140 as an array of 5 pointers:
//   [0] = main renderer object (0x138 bytes)
//   [1] = vertex shader "VS_QUAD" (0xf8 bytes)
//   [2] = pixel shader "PS_QUAD" (0xf8 bytes)
//   [3] = constant buffer (0x30 bytes, mmConstantBuffer)
//   [4] = render state object (0xd8 bytes)
// +0x20: uint32 render state flags
// +0x24: uint16 blend/rasterizer state
// +0x26: uint16 blend/rasterizer state
// Evidence: mmDrawCommand::QuadRenderer::Draw accesses global DAT_140b8d140
// directly; no param_1 member access found in any decompiled method.
// No struct defined — this is a global singleton, not an instance-based class.
// ============================================================================