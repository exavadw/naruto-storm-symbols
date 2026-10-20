/* cmn25.h — s4 (NSUNS4_release.exe 1.09 x64) common struct stubs
 * INFERRED from PC x64 decompile — NOT CONFIRMED
 * Compiles with: gcc -fsyntax-only -x c -std=c11 cmn25.h
 */
#pragma once
#include <stddef.h>
#include <stdint.h>

/* ========================================================================
 * mmAppAllocator — static utility, no instance state
 * Evidence: Allocate/Deallocate/IsValid are all static; no this-pointer
 *           dereference in any decompiled method.
 * ======================================================================== */
/* no instance state */

/* ========================================================================
 * mmAppMemorySegment — static singleton, no per-instance fields
 * Evidence: GetInstance returns global DAT ptr; GetTotalSize/GetUseSize
 *           read only global data refs. No param_1 field access.
 * ======================================================================== */
/* no instance state */

/* ========================================================================
 * mmBufferBindInfo
 * Source: BuildRenderInfoList (0x19A7B0), Create (0x199E10), Create (0x199F00)
 * Size: >= 0x64 (last proven field element_count at +0x60, int32)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmBufferBindInfo {
    uint8_t  _unknown_00[0x18]; /* 0x00-0x17 */
    void    *element_list;      /* 0x18 passed to FUN_14019a7b0 */
    uint8_t  _unknown_20[0x3c]; /* 0x20-0x5b */
    uint32_t total_stride;      /* 0x5c */
    int32_t  element_count;     /* 0x60 */
} mmBufferBindInfo;

_Static_assert(offsetof(mmBufferBindInfo, element_list)  == 0x18, "mmBufferBindInfo.element_list");
_Static_assert(offsetof(mmBufferBindInfo, total_stride)  == 0x5c, "mmBufferBindInfo.total_stride");
_Static_assert(offsetof(mmBufferBindInfo, element_count) == 0x60, "mmBufferBindInfo.element_count");

/* ========================================================================
 * mmCompileInfo
 * Source: Reset (0x191BE0), ~mmCompileInfo (0x1923A0), AddErrorMsg (0x192C30),
 *         AddWarningMsg (0x1AE5B0)
 * Layout: 16 entries at stride 0x50 starting at offset 0x08 through 0x468.
 *         Each entry is a list/hash-map container with sub-fields at +0x20,
 *         +0x28 (data ptr, next ptr). AddErrorMsg accesses +0x30/+0x38,
 *         +0x58/+0x60, +0x80/+0x88, +0xa8/+0xb0 within the struct.
 * Size: >= 0x4B8 (last entry at 0x468 + 0x50 = 0x4B8)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmCompileInfo {
    uint8_t  _unknown_00[0x08]; /* 0x00-0x07 */
    uint8_t  entries[15][0x50]; /* 0x08-0x4B7: 15 containers at 0x50 stride */
} mmCompileInfo;

_Static_assert(offsetof(mmCompileInfo, entries) == 0x08, "mmCompileInfo.entries");

/* ========================================================================
 * mmComputeShader
 * Source: LoadFromCompiledFile (0x195B90, 0x195CE0), Release (0x195690)
 * Field at +0xF0: internal D3D compute shader object pointer.
 *   LoadFromCompiledFile checks *(param_1 + 0xf0) != 0 before alloc,
 *   stores result there; Release clears it.
 * Size: >= 0xF8 (pointer at +0xF0, 8 bytes)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmComputeShader {
    uint8_t  _unknown_00[0xF0]; /* 0x00-0xEF */
    void    *compute_shader;    /* 0xF0 ID3D11ComputeShader* or wrapper */
} mmComputeShader;

_Static_assert(offsetof(mmComputeShader, compute_shader) == 0xF0, "mmComputeShader.compute_shader");

/* ========================================================================
 * mmConstantBuffer
 * Source: Create (0x1922E0), Lock (0x1923E0), Unlock (0x192450),
 *         Release (0x18E4C0), Bind (0x1924C0)
 * Matches s3 layout exactly.
 * Size: >= 0x30 (lock_param[2] ends at 0x28+8=0x30)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmConstantBuffer {
    uint64_t size;              /* 0x00 param_1[0] = buffer size */
    void    *internal_buffer;   /* 0x08 param_1[1] = D3D buffer wrapper */
    int32_t  state;             /* 0x10 Lock sets *(param_1+2)=1, Unlock checks */
    uint8_t  lock_flag;         /* 0x14 byte at (longlong)param_1+0x14 */
    uint8_t  _pad_15[3];        /* 0x15-0x17 */
    uint64_t lock_param[3];     /* 0x18, 0x20, 0x28: param_1[3], [4], [5] */
} mmConstantBuffer;

_Static_assert(offsetof(mmConstantBuffer, size)            == 0x00, "mmConstantBuffer.size");
_Static_assert(offsetof(mmConstantBuffer, internal_buffer) == 0x08, "mmConstantBuffer.internal_buffer");
_Static_assert(offsetof(mmConstantBuffer, state)           == 0x10, "mmConstantBuffer.state");
_Static_assert(offsetof(mmConstantBuffer, lock_flag)       == 0x14, "mmConstantBuffer.lock_flag");
_Static_assert(offsetof(mmConstantBuffer, lock_param)      == 0x18, "mmConstantBuffer.lock_param");

/* ========================================================================
 * mmController_Win
 * Source: Update (0x1B5620) — only 1 method, below threshold but included
 *         because s3 had it and offsets are clear.
 * Fields: +0x08 (byte flag), +0x0C (uint buttons_prev), +0x10 (uint pressed),
 *         +0x14 (uint released), +0x1C-0x28 (float axes x4), +0xE4 (int mode).
 * Size: >= 0xE8 (mode at +0xE4, int32)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmController_Win {
    uint8_t  _unknown_00[0x08]; /* 0x00-0x07 */
    uint8_t  update_flag;       /* 0x08 cleared at start of Update */
    uint8_t  _pad_09[3];        /* 0x09-0x0B */
    uint32_t buttons_prev;      /* 0x0C saved before clear */
    uint32_t buttons_pressed;   /* 0x10 new & old */
    uint32_t buttons_released;  /* 0x14 ~new & old */
    uint8_t  _unknown_18[4];    /* 0x18-0x1B */
    float    axis_x;            /* 0x1C deadzone-checked */
    float    axis_y;            /* 0x20 deadzone-checked */
    float    axis_z;            /* 0x24 deadzone-checked */
    float    axis_w;            /* 0x28 deadzone-checked */
    uint8_t  _unknown_2c[0xB8]; /* 0x2C-0xE3 */
    int32_t  input_mode;        /* 0xE4 checked == 1 for gamepad path */
} mmController_Win;

_Static_assert(offsetof(mmController_Win, update_flag)      == 0x08, "mmController_Win.update_flag");
_Static_assert(offsetof(mmController_Win, buttons_prev)     == 0x0C, "mmController_Win.buttons_prev");
_Static_assert(offsetof(mmController_Win, buttons_pressed)  == 0x10, "mmController_Win.buttons_pressed");
_Static_assert(offsetof(mmController_Win, buttons_released) == 0x14, "mmController_Win.buttons_released");
_Static_assert(offsetof(mmController_Win, axis_x)           == 0x1C, "mmController_Win.axis_x");
_Static_assert(offsetof(mmController_Win, axis_y)           == 0x20, "mmController_Win.axis_y");
_Static_assert(offsetof(mmController_Win, axis_z)           == 0x24, "mmController_Win.axis_z");
_Static_assert(offsetof(mmController_Win, axis_w)           == 0x28, "mmController_Win.axis_w");
_Static_assert(offsetof(mmController_Win, input_mode)       == 0xE4, "mmController_Win.input_mode");

/* ========================================================================
 * mmCoreLibrary — static initializer/finalizer, no instance state
 * Evidence: Initialize/Finalize are all void(void) or take config params,
 *           operate entirely on global DAT_ variables.
 * ======================================================================== */
/* no instance state */

/* ========================================================================
 * mmDataFormatUtil — static utility, no instance state
 * Evidence: GetByteSize is pure lookup from global table DAT_1412f2690.
 * ======================================================================== */
/* no instance state */

/* ========================================================================
 * mmDebugMemorySegment — static singleton, no instance state
 * Evidence: GetInstance decrements global refcount, memset on global block.
 * ======================================================================== */
/* no instance state */

/* ========================================================================
 * mmDelayCommandManager
 * Source: Execute (0x18CA60) — only 1 method, below threshold but included
 *         because offsets are clear from pseudocode.
 * Fields: +0x08 (byte flag_clear_screen), +0x09 (byte flag_set_target),
 *         +0x0A (byte flag_viewport), +0x0B (byte flag_scissor),
 *         +0x0C (uint arg0), +0x10 (uint arg1).
 * Size: >= 0x14 (arg1 at +0x10, uint32)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmDelayCommandManager {
    uint8_t  _unknown_00[0x08]; /* 0x00-0x07 */
    uint8_t  flag_clear_screen; /* 0x08 */
    uint8_t  flag_set_target;   /* 0x09 */
    uint8_t  flag_viewport;     /* 0x0A */
    uint8_t  flag_scissor;      /* 0x0B */
    uint32_t arg0;              /* 0x0C */
    uint32_t arg1;              /* 0x10 */
} mmDelayCommandManager;

_Static_assert(offsetof(mmDelayCommandManager, flag_clear_screen) == 0x08, "mmDelayCommandManager.flag_clear_screen");
_Static_assert(offsetof(mmDelayCommandManager, flag_set_target)   == 0x09, "mmDelayCommandManager.flag_set_target");
_Static_assert(offsetof(mmDelayCommandManager, flag_viewport)     == 0x0A, "mmDelayCommandManager.flag_viewport");
_Static_assert(offsetof(mmDelayCommandManager, flag_scissor)      == 0x0B, "mmDelayCommandManager.flag_scissor");
_Static_assert(offsetof(mmDelayCommandManager, arg0)              == 0x0C, "mmDelayCommandManager.arg0");
_Static_assert(offsetof(mmDelayCommandManager, arg1)              == 0x10, "mmDelayCommandManager.arg1");

/* ========================================================================
 * mmDrawCommand / QuadRenderer
 * Source: Initialize (0x18E970), QuadRenderer::Initialize (0x18EB50),
 *         QuadRenderer::Render (0x18F0A0)
 *
 * The global QuadRenderer state is an array of 5 pointers at DAT_148d31b90:
 *   [0] = render_state (size 0x138 via _aligned_malloc)
 *   [1] = vertex_shader (size 0xF8)
 *   [2] = pixel_shader  (size 0xF8)
 *   [3] = constant_buffer (size 0x30, wraps mmConstantBuffer)
 *   [4] = rasterizer_state (size 0xD8)
 *
 * Rasterizer state object (plVar6[4] in Render):
 *   +0x20: uint32 rasterizer_flags (bitwise OR/AND in Init+Render)
 *   +0x24: uint16 blend_stencil_a
 *   +0x26: uint16 blend_stencil_b
 *   +0x28: uint8  unknown_byte (set from param_6 in Render)
 *   +0x30-0x68: 8 x uint64 viewport/scissor rects
 *   +0xD0: pointer to constant buffer wrapper
 *   +0xF0: pointer to shader internal buffer (checked != 0 in Render)
 * Size: >= 0xF8 (shader_internal_buf at +0xF0)
 * ======================================================================== */
typedef struct __attribute__((packed)) mmDrawCommand_QuadRenderer {
    void    *vtable;              /* 0x00 PTR_LAB_1412f8758 */
    uint8_t  _unknown_08[0x18];   /* 0x08-0x1F */
    uint32_t rasterizer_flags;    /* 0x20 */
    uint16_t blend_stencil_a;     /* 0x24 */
    uint16_t blend_stencil_b;     /* 0x26 */
    uint8_t  unknown_28;          /* 0x28 set from Render param_6 */
    uint8_t  _pad_29[7];          /* 0x29-0x2F */
    uint64_t viewport_scissor[7]; /* 0x30-0x67 */
    uint8_t  _unknown_68[0x68];   /* 0x68-0xCF */
    void    *constant_buffer;     /* 0xD0 */
    uint8_t  _unknown_d8[0x18];   /* 0xD8-0xEF */
    void    *shader_internal_buf; /* 0xF0 */
} mmDrawCommand_QuadRenderer;

_Static_assert(offsetof(mmDrawCommand_QuadRenderer, vtable)             == 0x00, "mmDrawCommand_QuadRenderer.vtable");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, rasterizer_flags)   == 0x20, "mmDrawCommand_QuadRenderer.rasterizer_flags");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, blend_stencil_a)    == 0x24, "mmDrawCommand_QuadRenderer.blend_stencil_a");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, blend_stencil_b)    == 0x26, "mmDrawCommand_QuadRenderer.blend_stencil_b");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, unknown_28)         == 0x28, "mmDrawCommand_QuadRenderer.unknown_28");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, viewport_scissor)   == 0x30, "mmDrawCommand_QuadRenderer.viewport_scissor");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, constant_buffer)    == 0xD0, "mmDrawCommand_QuadRenderer.constant_buffer");
_Static_assert(offsetof(mmDrawCommand_QuadRenderer, shader_internal_buf)== 0xF0, "mmDrawCommand_QuadRenderer.shader_internal_buf");