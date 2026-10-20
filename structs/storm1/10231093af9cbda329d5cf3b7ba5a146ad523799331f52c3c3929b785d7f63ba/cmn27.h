/* cmn27.h — Storm 1 (s1) struct group: mmDrawCommand*, mmDX11Mapping, mmFile*
 * All layouts INFERRED from static decompilation of NSUNS1.exe (build s1).
 * NOT CONFIRMED at runtime. Field names from s1 symbols/strings only.
 * Image base 0x140000000; offsets are RVA-relative to object base.
 */
#ifndef CMN27_H
#define CMN27_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmFile_Win — Win32 file handle wrapper
 * Evidence: mmFile_Win::Open/Read/Write/Close all access param_1+0x8 (error),
 *           param_1+0x10 (HANDLE). Open sets +0x8=0 on success, +0x10=handle.
 * Size: >= 0x18 (last proven field +0x10 is HANDLE=8 bytes -> 0x18).
 * No vtable found (no virtual calls on param_1 in any method).
 * ========================================================================= */
typedef struct __attribute__((packed)) mmFile_Win {
    uint8_t  _pad_0x00[8];          /* 0x00: unknown (possibly base class or vtable) */
    uint32_t error_code;            /* 0x08: HRESULT-style error, set by Read/Write/Close */
    uint32_t _pad_0x0C;             /* 0x0C: padding */
    void    *handle;                /* 0x10: HANDLE from CreateFileW, -1 = invalid */
} mmFile_Win;

static_assert(offsetof(mmFile_Win, error_code) == 0x08, "mmFile_Win.error_code");
static_assert(offsetof(mmFile_Win, handle)     == 0x10, "mmFile_Win.handle");

/* =========================================================================
 * mmDrawCommandList — intrusive list of draw commands
 * Evidence: Sort accesses param_1+0x10 (list head ptr), param_1+0x38 (sorted flag).
 * Size: >= 0x40 (head at 0x10 + sorted flag at 0x38 + tail padding).
 * No vtable observed.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommandList {
    uint8_t  _pad_0x00[0x10];       /* 0x00: unknown */
    uint64_t list_head;             /* 0x10: pointer to first node (self if empty) */
    uint8_t  _pad_0x18[0x20];       /* 0x18: likely embedded list sentinel/tail */
    uint8_t  sorted_flag;           /* 0x38: set to 1 by Sort */
    uint8_t  _pad_0x39[7];          /* 0x39: padding to 0x40 */
} mmDrawCommandList;

static_assert(offsetof(mmDrawCommandList, list_head)   == 0x10, "mmDrawCommandList.list_head");
static_assert(offsetof(mmDrawCommandList, sorted_flag) == 0x38, "mmDrawCommandList.sorted_flag");

/* =========================================================================
 * mmDrawCommandSorter — merge-sort utility (static function, no object state)
 * Evidence: Merge operates on param_1 as a linked-list node. Only 1 method
 * found in s1 (< 3 threshold). Not reconstructed as a struct.
 * ========================================================================= */

/* =========================================================================
 * mmDrawCommandStorageAllocator — double-buffered storage pool
 * Evidence: GetDrawCommandStorage accesses:
 *   param_1+0x59 (byte: active buffer index, toggled by Flip)
 *   param_1+0x68 (CRITICAL_SECTION)
 *   param_1+8 + index*0x28 (array of storage slots, stride 0x28)
 * Size: >= 0x90 (critsec at 0x68 is 0x28 bytes on x64 -> ends at 0x90).
 * No vtable observed.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommandStorageAllocator {
    uint8_t  _pad_0x00[8];          /* 0x00: unknown */
    uint8_t  storage_slots[0x51];   /* 0x08: array of storage ptrs, stride 0x28 */
    uint8_t  active_buffer_index;   /* 0x59: 0 or 1, selects which buffer set */
    uint8_t  _pad_0x5A[0xE];        /* 0x5A: padding */
    uint8_t  critical_section[0x28];/* 0x68: CRITICAL_SECTION (EnterCriticalSection) */
} mmDrawCommandStorageAllocator;

static_assert(offsetof(mmDrawCommandStorageAllocator, active_buffer_index) == 0x59,
              "mmDrawCommandStorageAllocator.active_buffer_index");
static_assert(offsetof(mmDrawCommandStorageAllocator, critical_section)    == 0x68,
              "mmDrawCommandStorageAllocator.critical_section");

/* =========================================================================
 * mmDrawCommandManager — top-level render thread manager
 * Evidence from Initialize/FrameStart/Flip/MergeSort:
 *   +0x58 byte: flip toggle A (swapped with +0x59 in Flip)
 *   +0x59 byte: flip toggle B
 *   +0x60 ptr:  mmThread_Impl* (RenderThread, passed to Start)
 *   +0x78 ptr:  pointer to CRITICAL_SECTION (Flip)
 *   +0x80 ptr:  pointer-to-pointer to event HANDLE (SetEvent(**(ptr+0x80)))
 *   +0x88 byte: frame-active flag (set in FrameStart, checked in Flip)
 *   +0x90 ptr:  pointer to CRITICAL_SECTION (FrameStart)
 *   +0x98 uint: buffer index A (used in Flip array calc)
 *   +0x9C uint: buffer index B
 *   +0xB8 ptr:  base of storage array (param_1+0xB8 + idx*0x28)
 *   +0xF8 uint: cleared in Flip
 *   +0x150 byte: initialized flag
 *   +0x151 byte: copied from param_2+0x11 in Initialize
 *   +0x190 byte: second initialized flag (decimal 400 = 0x190)
 *   +0x198 ptr: mmThread_Impl* (GPUResourceDestroyThread)
 * Size: >= 0x1A0 (last field +0x198 is ptr=8 bytes -> 0x1A0).
 * No vtable observed (Initialize is called directly, not virtually).
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommandManager {
    uint8_t  _pad_0x00[0x58];       /* 0x00: unknown preamble */
    uint8_t  flip_toggle_a;         /* 0x58: Flip swaps with 0x59 */
    uint8_t  flip_toggle_b;         /* 0x59: Flip swaps with 0x58 */
    uint8_t  _pad_0x5A[6];          /* 0x5A-0x5F */
    uint64_t render_thread;         /* 0x60: mmThread_Impl* (RenderThread) */
    uint8_t  _pad_0x68[0x10];       /* 0x68-0x77 */
    void    *critsec_flip_ptr;      /* 0x78: pointer to CRITICAL_SECTION (Flip) */
    void    *event_handle_pptr;     /* 0x80: pointer-to-pointer to event HANDLE */
    uint8_t  frame_active_flag;     /* 0x88: set=1 in FrameStart, checked in Flip */
    uint8_t  _pad_0x89[7];          /* 0x89-0x8F */
    void    *critsec_frame_ptr;     /* 0x90: pointer to CRITICAL_SECTION (FrameStart) */
    uint32_t buf_index_a;           /* 0x98: buffer index used in Flip array calc */
    uint32_t buf_index_b;           /* 0x9C: second buffer index */
    uint8_t  _pad_0xA0[0x18];       /* 0xA0-0xB7 */
    uint64_t storage_array_base;    /* 0xB8: base ptr for storage[idx*0x28] */
    uint8_t  _pad_0xC0[0x38];       /* 0xC0-0xF7 */
    uint32_t clear_in_flip;         /* 0xF8: zeroed in Flip */
    uint8_t  _pad_0xFC[0x54];       /* 0xFC-0x14F */
    uint8_t  init_flag_a;           /* 0x150: set to 1 in Initialize */
    uint8_t  init_flag_b;           /* 0x151: copied from param_2+0x11 */
    uint8_t  _pad_0x152[0x3E];      /* 0x152-0x18F */
    uint8_t  init_flag_c;           /* 0x190: set to 1 in Initialize */
    uint8_t  _pad_0x191[7];         /* 0x191-0x197 */
    uint64_t destroy_thread;        /* 0x198: mmThread_Impl* (GPUResourceDestroyThread) */
} mmDrawCommandManager;

static_assert(offsetof(mmDrawCommandManager, flip_toggle_a)     == 0x58,  "flip_toggle_a");
static_assert(offsetof(mmDrawCommandManager, flip_toggle_b)     == 0x59,  "flip_toggle_b");
static_assert(offsetof(mmDrawCommandManager, render_thread)     == 0x60,  "render_thread");
static_assert(offsetof(mmDrawCommandManager, critsec_flip_ptr)  == 0x78,  "critsec_flip_ptr");
static_assert(offsetof(mmDrawCommandManager, event_handle_pptr) == 0x80,  "event_handle_pptr");
static_assert(offsetof(mmDrawCommandManager, frame_active_flag) == 0x88,  "frame_active_flag");
static_assert(offsetof(mmDrawCommandManager, critsec_frame_ptr) == 0x90,  "critsec_frame_ptr");
static_assert(offsetof(mmDrawCommandManager, buf_index_a)       == 0x98,  "buf_index_a");
static_assert(offsetof(mmDrawCommandManager, buf_index_b)       == 0x9C,  "buf_index_b");
static_assert(offsetof(mmDrawCommandManager, storage_array_base)== 0xB8,  "storage_array_base");
static_assert(offsetof(mmDrawCommandManager, clear_in_flip)     == 0xF8,  "clear_in_flip");
static_assert(offsetof(mmDrawCommandManager, init_flag_a)       == 0x150, "init_flag_a");
static_assert(offsetof(mmDrawCommandManager, init_flag_b)       == 0x151, "init_flag_b");
static_assert(offsetof(mmDrawCommandManager, init_flag_c)       == 0x190, "init_flag_c");
static_assert(offsetof(mmDrawCommandManager, destroy_thread)    == 0x198, "destroy_thread");

/* =========================================================================
 * mmDrawCommand_SetShader — draw command: bind shader
 * Evidence: Execute reads param_1+0x30 and param_1+0x38 as shader params.
 * Likely inherits from a base DrawCommand with vtable at +0x00.
 * Size: >= 0x40.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommand_SetShader {
    uint64_t vtable;                  /* 0x00: vtable ptr (Execute is virtual) */
    uint8_t  _pad_0x08[0x28];         /* 0x08: base DrawCommand fields */
    uint64_t shader_param_a;          /* 0x30: passed to GPU backend */
    uint64_t shader_param_b;          /* 0x38: passed to GPU backend */
} mmDrawCommand_SetShader;

static_assert(offsetof(mmDrawCommand_SetShader, shader_param_a) == 0x30, "SetShader.shader_param_a");
static_assert(offsetof(mmDrawCommand_SetShader, shader_param_b) == 0x38, "SetShader.shader_param_b");

/* =========================================================================
 * mmDrawCommand_UpdateBuffer — draw command: upload buffer data
 * Evidence: Execute reads +0x30 (dst), +0x38 (size), +0x40 (src).
 * Size: >= 0x48.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommand_UpdateBuffer {
    uint64_t vtable;                  /* 0x00 */
    uint8_t  _pad_0x08[0x28];         /* 0x08 */
    uint64_t dst_buffer;              /* 0x30 */
    uint64_t size;                    /* 0x38 */
    uint64_t src_data;                /* 0x40 */
} mmDrawCommand_UpdateBuffer;

static_assert(offsetof(mmDrawCommand_UpdateBuffer, dst_buffer) == 0x30, "UpdateBuffer.dst_buffer");
static_assert(offsetof(mmDrawCommand_UpdateBuffer, size)       == 0x38, "UpdateBuffer.size");
static_assert(offsetof(mmDrawCommand_UpdateBuffer, src_data)   == 0x40, "UpdateBuffer.src_data");

/* =========================================================================
 * mmDrawCommand_UpdateConstantBuffer — draw command: update CB
 * Evidence: Execute reads +0x30 (cb), +0x38 (size), +0x40 (gpu_buf_wrapper).
 * Set accesses param_1 as longlong* array: [10]=cached_cmd (offset 0x50).
 * Size: >= 0x58.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommand_UpdateConstantBuffer {
    uint64_t vtable;                  /* 0x00 */
    uint8_t  _pad_0x08[0x28];         /* 0x08: base fields */
    uint64_t constant_buffer;         /* 0x30 */
    uint64_t data_size;               /* 0x38 */
    uint64_t gpu_buffer_wrapper;      /* 0x40 */
    uint8_t  _pad_0x48[8];            /* 0x48 */
    uint64_t cached_command;          /* 0x50: param_1[10] in Set */
} mmDrawCommand_UpdateConstantBuffer;

static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, constant_buffer)    == 0x30, "UCB.constant_buffer");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, data_size)          == 0x38, "UCB.data_size");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, gpu_buffer_wrapper) == 0x40, "UCB.gpu_buffer_wrapper");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, cached_command)     == 0x50, "UCB.cached_command");

/* =========================================================================
 * mmDrawCommand_UpdateRenderState — draw command: apply render state
 * Evidence: Execute passes param_1+0x30 to mmRenderStateData::Merge,
 *           reads *(uint*)(param_1+0x108) as merge count,
 *           reads *(ptr*)(param_1+0x100) as mmGPURenderState*.
 * Size: >= 0x110 (last field at 0x108 is uint -> 0x10C, aligned 0x110).
 * ========================================================================= */
typedef struct __attribute__((packed)) mmDrawCommand_UpdateRenderState {
    uint64_t vtable;                  /* 0x00 */
    uint8_t  _pad_0x08[0x28];         /* 0x08 */
    uint8_t  render_state_data[0xD0]; /* 0x30: mmRenderStateData blob */
    uint64_t gpu_render_state;        /* 0x100: mmGPURenderState* */
    uint32_t merge_count;             /* 0x108: count passed to Merge */
    uint32_t _pad_0x10C;              /* 0x10C */
} mmDrawCommand_UpdateRenderState;

static_assert(offsetof(mmDrawCommand_UpdateRenderState, render_state_data) == 0x30,  "URS.render_state_data");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, gpu_render_state)  == 0x100, "URS.gpu_render_state");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, merge_count)       == 0x108, "URS.merge_count");

/* =========================================================================
 * mmDX11Mapping — static utility, no object state
 * Evidence: GetBlendMultiplier is a pure switch on param_1 (no this).
 *           GetBlendOperator takes param_1 as output uint array, param_2 as input.
 * No instance fields. Not reconstructed as a struct.
 * ========================================================================= */

/* =========================================================================
 * mmDrawCommandStorage — template storage, only Create<> specializations exist
 * Evidence: Create<T> are factory functions returning new command objects.
 * No instance methods with this-pointer field access found in s1.
 * Template-only, no runtime layout. Not reconstructed.
 * ========================================================================= */

#endif /* CMN27_H */