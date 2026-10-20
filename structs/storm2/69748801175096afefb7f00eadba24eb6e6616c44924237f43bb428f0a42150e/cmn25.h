/* cmn25.h — Storm 2 (s2 / NSUNS2.exe-abf2b6) struct layouts for cmn25 group
 * All results are INFERRED from static analysis of x64 decompiled pseudocode.
 * Offsets derived from s2 build only (image base 0x140000000).
 * Sizes proven from allocator arguments in game code, never sizeof.
 */
#ifndef CMN25_S2_H
#define CMN25_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── mmConstantBuffer ────────────────────────────────────────────────
 * D3D11 constant buffer wrapper. Size proven: _aligned_malloc(0x30) in
 * QuadRenderer::Initialize (0x1646A0). Lock/Unlock manage GPU mapping.
 */
typedef struct __attribute__((packed)) ns2_mmConstantBuffer {
    uint64_t size;              /* 0x00 */
    void    *d3d_buffer;        /* 0x08  ID3D11Buffer* */
    int32_t  lock_state;        /* 0x10  0=unlocked, 1=locked */
    uint8_t  lock_flag;         /* 0x14 */
    uint8_t  _pad_15[3];       /* 0x15 */
    void    *lock_output_ptr;   /* 0x18 */
    uint64_t lock_param3;       /* 0x20 */
    void    *mapped_data;       /* 0x28 */
} ns2_mmConstantBuffer;         /* total 0x30 */

static_assert(offsetof(ns2_mmConstantBuffer, size)           == 0x00, "mmConstantBuffer.size");
static_assert(offsetof(ns2_mmConstantBuffer, d3d_buffer)     == 0x08, "mmConstantBuffer.d3d_buffer");
static_assert(offsetof(ns2_mmConstantBuffer, lock_state)     == 0x10, "mmConstantBuffer.lock_state");
static_assert(offsetof(ns2_mmConstantBuffer, lock_flag)      == 0x14, "mmConstantBuffer.lock_flag");
static_assert(offsetof(ns2_mmConstantBuffer, lock_output_ptr)== 0x18, "mmConstantBuffer.lock_output_ptr");
static_assert(offsetof(ns2_mmConstantBuffer, lock_param3)    == 0x20, "mmConstantBuffer.lock_param3");
static_assert(offsetof(ns2_mmConstantBuffer, mapped_data)    == 0x28, "mmConstantBuffer.mapped_data");
static_assert(sizeof(ns2_mmConstantBuffer)                   == 0x30, "mmConstantBuffer size");


/* ─── mmController_Win ────────────────────────────────────────────────
 * DirectInput/XInput controller wrapper. Size >= 0x150 (last accessed
 * field at 0x148 is a pointer; COM object stored there).
 * Large gaps 0x2C-0x8F and 0x9C-0x13B likely hold DIJOYSTATE / XINPUT_STATE
 * but are not accessed in decompiled methods.
 */
typedef struct __attribute__((packed)) ns2_mmController_Win {
    uint64_t vtable;            /* 0x00 */
    uint8_t  active;            /* 0x08 */
    uint8_t  _pad_09[3];       /* 0x09 */
    uint32_t button_state;      /* 0x0c  accumulated this frame */
    uint32_t edge_press;        /* 0x10  new & ~old */
    uint32_t edge_release;      /* 0x14  ~new & old */
    uint8_t  _pad_18[4];       /* 0x18 */
    float    axis_x;            /* 0x1c  deadzone 0.12 */
    float    axis_y;            /* 0x20 */
    float    axis_z;            /* 0x24 */
    float    axis_w;            /* 0x28 */
    uint8_t  _gap_2c[0x64];    /* 0x2c  likely DIJOYSTATE / padding */
    void    *mapping_hash_base; /* 0x90  hash table bucket array ptr */
    uint32_t mapping_hash_size; /* 0x98  bucket count */
    uint8_t  _gap_9c[0xa0];    /* 0x9c */
    int32_t  input_mode;        /* 0x13c 1=XInput?, 2=DirectInput */
    uint8_t  _pad_140[8];      /* 0x140 gap to reach 0x148 */
    void    *dinput_device;     /* 0x148 IDirectInputDevice8* */
    uint8_t  _tail_150[0x08];  /* 0x150 unknown tail to reach min size */
} ns2_mmController_Win;         /* min size 0x158, proven >= 0x150 */

static_assert(offsetof(ns2_mmController_Win, vtable)             == 0x000, "mmController_Win.vtable");
static_assert(offsetof(ns2_mmController_Win, active)             == 0x008, "mmController_Win.active");
static_assert(offsetof(ns2_mmController_Win, button_state)       == 0x00c, "mmController_Win.button_state");
static_assert(offsetof(ns2_mmController_Win, edge_press)         == 0x010, "mmController_Win.edge_press");
static_assert(offsetof(ns2_mmController_Win, edge_release)       == 0x014, "mmController_Win.edge_release");
static_assert(offsetof(ns2_mmController_Win, axis_x)             == 0x01c, "mmController_Win.axis_x");
static_assert(offsetof(ns2_mmController_Win, axis_y)             == 0x020, "mmController_Win.axis_y");
static_assert(offsetof(ns2_mmController_Win, axis_z)             == 0x024, "mmController_Win.axis_z");
static_assert(offsetof(ns2_mmController_Win, axis_w)             == 0x028, "mmController_Win.axis_w");
static_assert(offsetof(ns2_mmController_Win, mapping_hash_base)  == 0x090, "mmController_Win.mapping_hash_base");
static_assert(offsetof(ns2_mmController_Win, mapping_hash_size)  == 0x098, "mmController_Win.mapping_hash_size");
static_assert(offsetof(ns2_mmController_Win, input_mode)         == 0x13c, "mmController_Win.input_mode");
static_assert(offsetof(ns2_mmController_Win, dinput_device)      == 0x148, "mmController_Win.dinput_device");


/* ─── mmAppMemorySegment ──────────────────────────────────────────────
 * Memory pool allocator with 3D block tracking. Singleton via GetInstance.
 * Size >= 0x98 (last accessed field handle3 at 0x90 is a pointer).
 */
typedef struct __attribute__((packed)) ns2_mmAppMemorySegment {
    uint64_t vtable;            /* 0x00 */
    void    *base_ptr;          /* 0x08 */
    uint32_t flags_size;        /* 0x10 */
    uint32_t val_14;            /* 0x14 */
    uint8_t  _gap_18[0x14];    /* 0x18 .. 0x2b (unaccessed) */
    int32_t  dim_x;             /* 0x2c */
    int32_t  dim_y;             /* 0x30 */
    int32_t  dim_z;             /* 0x34 */
    uint8_t  _gap_38[8];       /* 0x38 .. 0x3f */
    void    *block_array_3d;    /* 0x40 */
    uint32_t val_48;            /* 0x48 */
    uint8_t  _gap_4c[4];       /* 0x4c */
    void    *vector_begin;      /* 0x50 */
    void    *vector_end;        /* 0x58 */
    uint8_t  _gap_60[8];       /* 0x60 */
    void    *sub_object;        /* 0x68 */
    uint8_t  _gap_70[0x18];    /* 0x70 .. 0x87 */
    void    *handle2;           /* 0x88 */
    void    *handle3;           /* 0x90 */
} ns2_mmAppMemorySegment;       /* min size >= 0x98 */

static_assert(offsetof(ns2_mmAppMemorySegment, vtable)        == 0x00, "mmAppMemorySegment.vtable");
static_assert(offsetof(ns2_mmAppMemorySegment, base_ptr)      == 0x08, "mmAppMemorySegment.base_ptr");
static_assert(offsetof(ns2_mmAppMemorySegment, flags_size)    == 0x10, "mmAppMemorySegment.flags_size");
static_assert(offsetof(ns2_mmAppMemorySegment, val_14)        == 0x14, "mmAppMemorySegment.val_14");
static_assert(offsetof(ns2_mmAppMemorySegment, dim_x)         == 0x2c, "mmAppMemorySegment.dim_x");
static_assert(offsetof(ns2_mmAppMemorySegment, dim_y)         == 0x30, "mmAppMemorySegment.dim_y");
static_assert(offsetof(ns2_mmAppMemorySegment, dim_z)         == 0x34, "mmAppMemorySegment.dim_z");
static_assert(offsetof(ns2_mmAppMemorySegment, block_array_3d)== 0x40, "mmAppMemorySegment.block_array_3d");
static_assert(offsetof(ns2_mmAppMemorySegment, val_48)        == 0x48, "mmAppMemorySegment.val_48");
static_assert(offsetof(ns2_mmAppMemorySegment, vector_begin)  == 0x50, "mmAppMemorySegment.vector_begin");
static_assert(offsetof(ns2_mmAppMemorySegment, vector_end)    == 0x58, "mmAppMemorySegment.vector_end");
static_assert(offsetof(ns2_mmAppMemorySegment, sub_object)    == 0x68, "mmAppMemorySegment.sub_object");
static_assert(offsetof(ns2_mmAppMemorySegment, handle2)       == 0x88, "mmAppMemorySegment.handle2");
static_assert(offsetof(ns2_mmAppMemorySegment, handle3)       == 0x90, "mmAppMemorySegment.handle3");


/* ─── mmCompileInfo ───────────────────────────────────────────────────
 * Compilation error/warning message container. 15 slot arrays at stride
 * 0x50, indexed by type code. Size >= 0x4B0 (15 × 0x50 + header).
 * Thread-safe via EnterCriticalSection/LeaveCriticalSection.
 */
typedef struct __attribute__((packed)) ns2_mmCompileInfo_Slot {
    void    *begin_ptr;         /* 0x00 */
    void    *end_or_count;      /* 0x08 */
    uint8_t  _gap_10[0x10];    /* 0x10 */
    void    *data_ptr;          /* 0x20 */
    void    *next_link;         /* 0x28 */
    uint8_t  _gap_30[0x20];    /* 0x30 */
} ns2_mmCompileInfo_Slot;       /* 0x50 each */

static_assert(sizeof(ns2_mmCompileInfo_Slot) == 0x50, "mmCompileInfo_Slot size");

typedef struct __attribute__((packed)) ns2_mmCompileInfo {
    uint64_t vtable;                    /* 0x000 */
    ns2_mmCompileInfo_Slot slots[15];   /* 0x008 .. 0x4B7 */
} ns2_mmCompileInfo;                    /* min size >= 0x4B8 */

static_assert(offsetof(ns2_mmCompileInfo, vtable)  == 0x000, "mmCompileInfo.vtable");
static_assert(offsetof(ns2_mmCompileInfo, slots)   == 0x008, "mmCompileInfo.slots");
static_assert(offsetof(ns2_mmCompileInfo, slots[1]) == 0x058, "mmCompileInfo.slots[1]");
static_assert(offsetof(ns2_mmCompileInfo, slots[2]) == 0x0a8, "mmCompileInfo.slots[2]");
static_assert(offsetof(ns2_mmCompileInfo, slots[14])== 0x468, "mmCompileInfo.slots[14]");


/* ─── mmComputeShader ─────────────────────────────────────────────────
 * Compute shader resource holder. Only one confirmed field at 0xF0.
 * Size >= 0xF8 (from s1 report; s2 Release frees ptr at 0xF0).
 */
typedef struct __attribute__((packed)) ns2_mmComputeShader {
    uint8_t  _unknown[0xf0];    /* 0x00  likely D3D shader blob storage */
    void    *shader_resource;   /* 0xf0  freed via FUN_140166b40 on Release */
} ns2_mmComputeShader;          /* min size >= 0xF8 */

static_assert(offsetof(ns2_mmComputeShader, shader_resource) == 0xf0, "mmComputeShader.shader_resource");


/* ─── mmBufferBindInfo ────────────────────────────────────────────────
 * Vertex/index buffer binding descriptor. Size >= 0x64.
 */
typedef struct __attribute__((packed)) ns2_mmBufferBindInfo {
    uint64_t vtable;            /* 0x00 */
    uint8_t  _gap_08[0x10];    /* 0x08 */
    void    *sub_object;        /* 0x18  passed to FUN_140170b00 */
    uint8_t  _gap_20[0x3c];    /* 0x20 */
    uint32_t total_stride;      /* 0x5c */
    int32_t  stride_per_element;/* 0x60  = param_4 / total_stride */
} ns2_mmBufferBindInfo;         /* min size >= 0x64 */

static_assert(offsetof(ns2_mmBufferBindInfo, vtable)             == 0x00, "mmBufferBindInfo.vtable");
static_assert(offsetof(ns2_mmBufferBindInfo, sub_object)         == 0x18, "mmBufferBindInfo.sub_object");
static_assert(offsetof(ns2_mmBufferBindInfo, total_stride)       == 0x5c, "mmBufferBindInfo.total_stride");
static_assert(offsetof(ns2_mmBufferBindInfo, stride_per_element) == 0x60, "mmBufferBindInfo.stride_per_element");


/* ─── mmCoreLibrary_Config ────────────────────────────────────────────
 * Config struct passed to mmCoreLibrary::Initialize (not an instance struct).
 * Accessed as param_1[] array of uint32 values.
 */
typedef struct __attribute__((packed)) ns2_mmCoreLibrary_Config {
    uint32_t val_00;            /* 0x00  param_1[0] */
    uint32_t val_04;            /* 0x04  param_1[1] */
    uint32_t val_08;            /* 0x08  param_1[2] */
    uint32_t val_0c;            /* 0x0c  param_1[3] */
    uint64_t ptr_10;            /* 0x10  param_1[4] (pointer-sized) */
    uint32_t val_18;            /* 0x18  param_1[5] */
    uint32_t val_1c;            /* 0x1c  param_1[6] */
    uint32_t val_20;            /* 0x20  param_1[7] */
} ns2_mmCoreLibrary_Config;     /* size >= 0x24 */

static_assert(offsetof(ns2_mmCoreLibrary_Config, val_00) == 0x00, "mmCoreLibrary_Config.val_00");
static_assert(offsetof(ns2_mmCoreLibrary_Config, val_04) == 0x04, "mmCoreLibrary_Config.val_04");
static_assert(offsetof(ns2_mmCoreLibrary_Config, val_08) == 0x08, "mmCoreLibrary_Config.val_08");
static_assert(offsetof(ns2_mmCoreLibrary_Config, val_0c) == 0x0c, "mmCoreLibrary_Config.val_0c");
static_assert(offsetof(ns2_mmCoreLibrary_Config, ptr_10) == 0x10, "mmCoreLibrary_Config.ptr_10");
static_assert(offsetof(ns2_mmCoreLibrary_Config, val_18) == 0x18, "mmCoreLibrary_Config.val_18");
static_assert(offsetof(ns2_mmCoreLibrary_Config, val_1c) == 0x1c, "mmCoreLibrary_Config.val_1c");
static_assert(offsetof(ns2_mmCoreLibrary_Config, val_20) == 0x20, "mmCoreLibrary_Config.val_20");


/* ─── mmDelayCommandManager ───────────────────────────────────────────
 * Delayed command execution queue. Fields from Execute (0x161420).
 * Size unknown; fields accessed up to offset 0x10.
 */
typedef struct __attribute__((packed)) ns2_mmDelayCommandManager {
    uint64_t vtable;            /* 0x00 */
    uint8_t  flag_cmd1;         /* 0x08  triggers vtable+0x158 dispatch */
    uint8_t  flag_cmd2;         /* 0x09  unused in Execute? */
    uint8_t  flag_cmd3;         /* 0x0a  triggers vtable+0x168 dispatch */
    uint8_t  flag_cmd4;         /* 0x0b  triggers vtable+0x160 dispatch */
    uint32_t cmd_param_a;       /* 0x0c  passed to dispatch */
    uint32_t cmd_param_b;       /* 0x10  passed to dispatch */
} ns2_mmDelayCommandManager;    /* size unknown, >= 0x14 */

static_assert(offsetof(ns2_mmDelayCommandManager, vtable)       == 0x00, "mmDelayCommandManager.vtable");
static_assert(offsetof(ns2_mmDelayCommandManager, flag_cmd1)    == 0x08, "mmDelayCommandManager.flag_cmd1");
static_assert(offsetof(ns2_mmDelayCommandManager, flag_cmd3)    == 0x0a, "mmDelayCommandManager.flag_cmd3");
static_assert(offsetof(ns2_mmDelayCommandManager, flag_cmd4)    == 0x0b, "mmDelayCommandManager.flag_cmd4");
static_assert(offsetof(ns2_mmDelayCommandManager, cmd_param_a)  == 0x0c, "mmDelayCommandManager.cmd_param_a");
static_assert(offsetof(ns2_mmDelayCommandManager, cmd_param_b)  == 0x10, "mmDelayCommandManager.cmd_param_b");


/* ─── mmDrawCommand (singleton state) ─────────────────────────────────
 * Global singleton allocated via _aligned_malloc(0xd0) in Initialize (0x1644C0).
 * Stored at DAT_148110c78. Internal layout not fully recovered.
 */
typedef struct __attribute__((packed)) ns2_mmDrawCommand {
    uint8_t _data[0xd0];        /* 0x00  opaque; allocated as 0xd0 bytes */
} ns2_mmDrawCommand;            /* size 0xd0 (proven) */

static_assert(sizeof(ns2_mmDrawCommand) == 0xd0, "mmDrawCommand size");


/* ─── mmDrawCommand::QuadRenderer (global singleton array) ────────────
 * Array of 5 pointers at DAT_148110c80, allocated in Initialize:
 *   [0] main renderer     _aligned_malloc(0x138)
 *   [1] VS_QUAD shader    _aligned_malloc(0xf8)
 *   [2] PS_QUAD shader    _aligned_malloc(0xf8)
 *   [3] mmConstantBuffer  _aligned_malloc(0x30)
 *   [4] render state obj  _aligned_malloc(0xd8)
 * Not a single struct; documented here for completeness.
 */

#endif /* CMN25_S2_H */