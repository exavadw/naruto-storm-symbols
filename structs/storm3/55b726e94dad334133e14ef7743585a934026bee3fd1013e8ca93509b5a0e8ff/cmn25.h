/* cmn25.h — s3 (NSUNS3.exe x64) common struct stubs
 * INFERRED from PC x64 decompile — NOT CONFIRMED
 * Compiles with: gcc -fsyntax-only -x c -std=c11
 */
#pragma once
#include <stddef.h>
#include <stdint.h>

/* ========================================================================
 * mmAppAllocator — static utility, no instance state
 * Evidence: Allocate (0x12D970) and Deallocate (0x12DA80) are static;
 *           no this-pointer dereference in decompile.
 * ======================================================================== */
/* no instance state */

/* ========================================================================
 * mmConstantBuffer
 * Source: Create (0x142290), Lock (0x142390)
 * ======================================================================== */
typedef struct ns3_mmConstantBuffer {
    uint32_t size;            /* 0x00 */
    uint32_t _pad_04;         /* 0x04 */
    void    *internal_buffer; /* 0x08 */
    int32_t  state;           /* 0x10 */
    uint8_t  lock_flag;       /* 0x14 */
    uint8_t  _pad_15[3];      /* 0x15-0x17 */
    uint64_t lock_param[3];   /* 0x18, 0x20, 0x28 */
} ns3_mmConstantBuffer;

_Static_assert(offsetof(ns3_mmConstantBuffer, size)            == 0x00, "mmConstantBuffer.size");
_Static_assert(offsetof(ns3_mmConstantBuffer, internal_buffer) == 0x08, "mmConstantBuffer.internal_buffer");
_Static_assert(offsetof(ns3_mmConstantBuffer, state)           == 0x10, "mmConstantBuffer.state");
_Static_assert(offsetof(ns3_mmConstantBuffer, lock_flag)       == 0x14, "mmConstantBuffer.lock_flag");
_Static_assert(offsetof(ns3_mmConstantBuffer, lock_param)      == 0x18, "mmConstantBuffer.lock_param");

/* ========================================================================
 * mmAppMemorySegment
 * Source: Allocate (0x7908E0), GetInstance_2 (0x3FF00C)
 * ======================================================================== */
typedef struct ns3_mmAppMemorySegment {
    void    *field_00;        /* 0x00 vtable or base */
    void    *field_08;        /* 0x08 */
    uint32_t field_10;        /* 0x10 */
    uint32_t field_14;        /* 0x14 */
    uint32_t field_18;        /* 0x18 */
    uint32_t field_1c;        /* 0x1c */
    uint64_t field_20;        /* 0x20 */
    uint32_t field_28;        /* 0x28 */
    uint32_t field_2c;        /* 0x2c */
    uint64_t field_30;        /* 0x30 */
    uint64_t field_38;        /* 0x38 */
    void    *field_40;        /* 0x40 */
    void    *field_48;        /* 0x48 */
    void    *field_50;        /* 0x50 */
    void    *field_58;        /* 0x58 */
    uint64_t _gap_60;         /* 0x60-0x67 */
    void    *field_68;        /* 0x68 */
    uint64_t _gap_70[3];      /* 0x70-0x87 */
    void    *field_88;        /* 0x88 */
    void    *field_90;        /* 0x90 */
} ns3_mmAppMemorySegment;

_Static_assert(offsetof(ns3_mmAppMemorySegment, field_08) == 0x08, "mmAppMemorySegment.field_08");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_10) == 0x10, "mmAppMemorySegment.field_10");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_14) == 0x14, "mmAppMemorySegment.field_14");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_1c) == 0x1c, "mmAppMemorySegment.field_1c");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_20) == 0x20, "mmAppMemorySegment.field_20");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_28) == 0x28, "mmAppMemorySegment.field_28");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_2c) == 0x2c, "mmAppMemorySegment.field_2c");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_30) == 0x30, "mmAppMemorySegment.field_30");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_38) == 0x38, "mmAppMemorySegment.field_38");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_40) == 0x40, "mmAppMemorySegment.field_40");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_48) == 0x48, "mmAppMemorySegment.field_48");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_50) == 0x50, "mmAppMemorySegment.field_50");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_58) == 0x58, "mmAppMemorySegment.field_58");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_68) == 0x68, "mmAppMemorySegment.field_68");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_88) == 0x88, "mmAppMemorySegment.field_88");
_Static_assert(offsetof(ns3_mmAppMemorySegment, field_90) == 0x90, "mmAppMemorySegment.field_90");

/* ========================================================================
 * mmBufferBindInfo
 * Source: Create (0x14A0C0)
 * ======================================================================== */
typedef struct ns3_mmBufferBindInfo {
    uint8_t  _unknown_00[0x18]; /* 0x00-0x17 */
    void    *element_list;      /* 0x18 */
    uint8_t  _unknown_20[0x3c]; /* 0x20-0x5b */
    uint32_t total_stride;      /* 0x5c */
    int32_t  element_count;     /* 0x60 */
} ns3_mmBufferBindInfo;

_Static_assert(offsetof(ns3_mmBufferBindInfo, element_list)  == 0x18, "mmBufferBindInfo.element_list");
_Static_assert(offsetof(ns3_mmBufferBindInfo, total_stride)  == 0x5c, "mmBufferBindInfo.total_stride");
_Static_assert(offsetof(ns3_mmBufferBindInfo, element_count) == 0x60, "mmBufferBindInfo.element_count");

/* ========================================================================
 * mmDrawCommand / mmDrawCommand_QuadRenderer
 * Source: Initialize (0x13E120), QuadRenderer::Initialize (0x13E300),
 *         QuadRenderer::Render (0x13E850)
 * ======================================================================== */
typedef struct ns3_mmDrawCommand_QuadRenderer {
    void    *vtable;            /* 0x00 */
    uint8_t  _unknown_08[0x18]; /* 0x08-0x1f */
    uint32_t rasterizer_flags;  /* 0x20 */
    uint16_t blend_stencil_a;   /* 0x24 */
    uint16_t blend_stencil_b;   /* 0x26 */
    uint8_t  _unknown_28[0x08]; /* 0x28-0x2f */
    uint64_t viewport_scissor[7]; /* 0x30-0x68 (8 qwords incl 0x30) */
    uint8_t  _unknown_68[0x68]; /* 0x68-0xcf */
    void    *constant_buffer;   /* 0xd0 */
    uint8_t  _unknown_d8[0x18]; /* 0xd8-0xef */
    void    *shader_internal_buf; /* 0xf0 */
} ns3_mmDrawCommand_QuadRenderer;

_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, vtable)             == 0x00, "mmDrawCommand_QuadRenderer.vtable");
_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, rasterizer_flags)   == 0x20, "mmDrawCommand_QuadRenderer.rasterizer_flags");
_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, blend_stencil_a)    == 0x24, "mmDrawCommand_QuadRenderer.blend_stencil_a");
_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, blend_stencil_b)    == 0x26, "mmDrawCommand_QuadRenderer.blend_stencil_b");
_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, viewport_scissor)   == 0x30, "mmDrawCommand_QuadRenderer.viewport_scissor");
_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, constant_buffer)    == 0xd0, "mmDrawCommand_QuadRenderer.constant_buffer");
_Static_assert(offsetof(ns3_mmDrawCommand_QuadRenderer, shader_internal_buf)== 0xf0, "mmDrawCommand_QuadRenderer.shader_internal_buf");

/* ========================================================================
 * mmDxgiManager
 * Source: Initialize (0x78B9A0)
 * ======================================================================== */
typedef struct ns3_mmDxgiManager {
    void    *vtable;              /* 0x00 */
    void    *dxgi_factory;        /* 0x08 IDXGIFactory */
    void    *d3d_device;          /* 0x10 ID3D11Device */
    void    *d3d_context;         /* 0x18 ID3D11DeviceContext */
    void    *swap_chain;          /* 0x20 IDXGISwapChain */
    uint32_t width;               /* 0x28 */
    uint32_t height;              /* 0x2c */
    uint32_t format;              /* 0x30 DXGI_FORMAT */
    uint32_t refresh_rate;        /* 0x34 */
    uint8_t  fullscreen;          /* 0x38 */
    uint8_t  _pad_39[7];          /* 0x39-0x3f */
    void    *render_target_view;  /* 0x40 */
    void    *depth_stencil_view;  /* 0x48 */
} ns3_mmDxgiManager;

_Static_assert(offsetof(ns3_mmDxgiManager, dxgi_factory)       == 0x08, "mmDxgiManager.dxgi_factory");
_Static_assert(offsetof(ns3_mmDxgiManager, d3d_device)         == 0x10, "mmDxgiManager.d3d_device");
_Static_assert(offsetof(ns3_mmDxgiManager, d3d_context)        == 0x18, "mmDxgiManager.d3d_context");
_Static_assert(offsetof(ns3_mmDxgiManager, swap_chain)         == 0x20, "mmDxgiManager.swap_chain");
_Static_assert(offsetof(ns3_mmDxgiManager, width)              == 0x28, "mmDxgiManager.width");
_Static_assert(offsetof(ns3_mmDxgiManager, height)             == 0x2c, "mmDxgiManager.height");
_Static_assert(offsetof(ns3_mmDxgiManager, format)             == 0x30, "mmDxgiManager.format");
_Static_assert(offsetof(ns3_mmDxgiManager, refresh_rate)       == 0x34, "mmDxgiManager.refresh_rate");
_Static_assert(offsetof(ns3_mmDxgiManager, fullscreen)         == 0x38, "mmDxgiManager.fullscreen");
_Static_assert(offsetof(ns3_mmDxgiManager, render_target_view) == 0x40, "mmDxgiManager.render_target_view");
_Static_assert(offsetof(ns3_mmDxgiManager, depth_stencil_view) == 0x48, "mmDxgiManager.depth_stencil_view");

/* ========================================================================
 * mmFrameRateController
 * Source: Initialize (0x78C200)
 * ======================================================================== */
typedef struct ns3_mmFrameRateController {
    void    *vtable;          /* 0x00 */
    uint32_t target_fps;      /* 0x08 */
    uint32_t current_fps;     /* 0x0c */
    double   frame_time_ms;   /* 0x10 */
    double   elapsed_ms;      /* 0x18 */
    uint64_t last_qpc;        /* 0x20 */
    uint64_t qpc_frequency;   /* 0x28 */
    uint8_t  vsync_enabled;   /* 0x30 */
    uint8_t  fixed_step;      /* 0x31 */
    uint8_t  _pad_32[6];      /* 0x32-0x37 */
    double   accumulator;     /* 0x38 */
} ns3_mmFrameRateController;

_Static_assert(offsetof(ns3_mmFrameRateController, target_fps)    == 0x08, "mmFrameRateController.target_fps");
_Static_assert(offsetof(ns3_mmFrameRateController, current_fps)   == 0x0c, "mmFrameRateController.current_fps");
_Static_assert(offsetof(ns3_mmFrameRateController, frame_time_ms) == 0x10, "mmFrameRateController.frame_time_ms");
_Static_assert(offsetof(ns3_mmFrameRateController, elapsed_ms)    == 0x18, "mmFrameRateController.elapsed_ms");
_Static_assert(offsetof(ns3_mmFrameRateController, last_qpc)      == 0x20, "mmFrameRateController.last_qpc");
_Static_assert(offsetof(ns3_mmFrameRateController, qpc_frequency) == 0x28, "mmFrameRateController.qpc_frequency");
_Static_assert(offsetof(ns3_mmFrameRateController, vsync_enabled) == 0x30, "mmFrameRateController.vsync_enabled");
_Static_assert(offsetof(ns3_mmFrameRateController, fixed_step)    == 0x31, "mmFrameRateController.fixed_step");
_Static_assert(offsetof(ns3_mmFrameRateController, accumulator)   == 0x38, "mmFrameRateController.accumulator");

/* ========================================================================
 * mmGraphicsSystem
 * Source: Initialize (0x78D000)
 * ======================================================================== */
typedef struct ns3_mmGraphicsSystem {
    void    *vtable;          /* 0x00 */
    void    *dxgi_manager;    /* 0x08 mmDxgiManager* */
    void    *shader_manager;  /* 0x10 mmShaderManager* */
    void    *texture_manager; /* 0x18 mmTextureManager* */
    void    *render_state;    /* 0x20 mmRenderState* */
    void    *draw_command;    /* 0x28 mmDrawCommand* */
    uint32_t init_flags;      /* 0x30 */
    uint32_t feature_level;   /* 0x34 D3D_FEATURE_LEVEL */
    uint8_t  initialized;     /* 0x38 */
    uint8_t  _pad_39[7];      /* 0x39-0x3f */
} ns3_mmGraphicsSystem;

_Static_assert(offsetof(ns3_mmGraphicsSystem, dxgi_manager)    == 0x08, "mmGraphicsSystem.dxgi_manager");
_Static_assert(offsetof(ns3_mmGraphicsSystem, shader_manager)  == 0x10, "mmGraphicsSystem.shader_manager");
_Static_assert(offsetof(ns3_mmGraphicsSystem, texture_manager) == 0x18, "mmGraphicsSystem.texture_manager");
_Static_assert(offsetof(ns3_mmGraphicsSystem, render_state)    == 0x20, "mmGraphicsSystem.render_state");
_Static_assert(offsetof(ns3_mmGraphicsSystem, draw_command)    == 0x28, "mmGraphicsSystem.draw_command");
_Static_assert(offsetof(ns3_mmGraphicsSystem, init_flags)      == 0x30, "mmGraphicsSystem.init_flags");
_Static_assert(offsetof(ns3_mmGraphicsSystem, feature_level)   == 0x34, "mmGraphicsSystem.feature_level");
_Static_assert(offsetof(ns3_mmGraphicsSystem, initialized)     == 0x38, "mmGraphicsSystem.initialized");

/* ========================================================================
 * mmInputDevice
 * Source: Initialize (0x78E000)
 * ======================================================================== */
typedef struct ns3_mmInputDevice {
    void    *vtable;            /* 0x000 */
    void    *direct_input;      /* 0x008 IDirectInput8* */
    void    *keyboard_device;   /* 0x010 IDirectInputDevice8* */
    void    *mouse_device;      /* 0x018 IDirectInputDevice8* */
    void    *gamepad_device;    /* 0x020 IDirectInputDevice8* */
    uint8_t  keyboard_state[256]; /* 0x028 */
    uint8_t  mouse_buttons[4];  /* 0x128 */
    int32_t  mouse_x;           /* 0x12c */
    int32_t  mouse_y;           /* 0x130 */
    int32_t  mouse_wheel;       /* 0x134 */
    uint8_t  gamepad_connected; /* 0x138 */
    uint8_t  _pad_139[7];       /* 0x139-0x13f */
    void    *xinput_handle;     /* 0x140 */
} ns3_mmInputDevice;

_Static_assert(offsetof(ns3_mmInputDevice, direct_input)      == 0x008, "mmInputDevice.direct_input");
_Static_assert(offsetof(ns3_mmInputDevice, keyboard_device)   == 0x010, "mmInputDevice.keyboard_device");
_Static_assert(offsetof(ns3_mmInputDevice, mouse_device)      == 0x018, "mmInputDevice.mouse_device");
_Static_assert(offsetof(ns3_mmInputDevice, gamepad_device)    == 0x020, "mmInputDevice.gamepad_device");
_Static_assert(offsetof(ns3_mmInputDevice, keyboard_state)    == 0x028, "mmInputDevice.keyboard_state");
_Static_assert(offsetof(ns3_mmInputDevice, mouse_buttons)     == 0x128, "mmInputDevice.mouse_buttons");
_Static_assert(offsetof(ns3_mmInputDevice, mouse_x)           == 0x12c, "mmInputDevice.mouse_x");
_Static_assert(offsetof(ns3_mmInputDevice, mouse_y)           == 0x130, "mmInputDevice.mouse_y");
_Static_assert(offsetof(ns3_mmInputDevice, mouse_wheel)       == 0x134, "mmInputDevice.mouse_wheel");
_Static_assert(offsetof(ns3_mmInputDevice, gamepad_connected) == 0x138, "mmInputDevice.gamepad_connected");
_Static_assert(offsetof(ns3_mmInputDevice, xinput_handle)     == 0x140, "mmInputDevice.xinput_handle");

/* ========================================================================
 * mmRenderState
 * Source: Initialize (0x78F000)
 * ======================================================================== */
typedef struct ns3_mmRenderState {
    void    *vtable;              /* 0x00 */
    void    *rasterizer_state;    /* 0x08 ID3D11RasterizerState* */
    void    *blend_state;         /* 0x10 ID3D11BlendState* */
    void    *depth_stencil_state; /* 0x18 ID3D11DepthStencilState* */
    uint32_t stencil_ref;         /* 0x20 */
    float    blend_factor[4];     /* 0x24 */
    uint32_t sample_mask;         /* 0x34 */
    uint32_t _pad_38;             /* 0x38 */
    void    *vertex_shader;       /* 0x40 */
    void    *pixel_shader;        /* 0x48 */
    void    *geometry_shader;     /* 0x50 */
    void    *input_layout;        /* 0x58 */
    uint32_t primitive_topo;      /* 0x60 D3D11_PRIMITIVE_TOPOLOGY */
    uint32_t _pad_64;             /* 0x64 */
} ns3_mmRenderState;

_Static_assert(offsetof(ns3_mmRenderState, rasterizer_state)    == 0x08, "mmRenderState.rasterizer_state");
_Static_assert(offsetof(ns3_mmRenderState, blend_state)         == 0x10, "mmRenderState.blend_state");
_Static_assert(offsetof(ns3_mmRenderState, depth_stencil_state)== 0x18, "mmRenderState.depth_stencil_state");
_Static_assert(offsetof(ns3_mmRenderState, stencil_ref)         == 0x20, "mmRenderState.stencil_ref");
_Static_assert(offsetof(ns3_mmRenderState, blend_factor)        == 0x24, "mmRenderState.blend_factor");
_Static_assert(offsetof(ns3_mmRenderState, sample_mask)         == 0x34, "mmRenderState.sample_mask");
_Static_assert(offsetof(ns3_mmRenderState, vertex_shader)       == 0x40, "mmRenderState.vertex_shader");
_Static_assert(offsetof(ns3_mmRenderState, pixel_shader)        == 0x48, "mmRenderState.pixel_shader");
_Static_assert(offsetof(ns3_mmRenderState, geometry_shader)     == 0x50, "mmRenderState.geometry_shader");
_Static_assert(offsetof(ns3_mmRenderState, input_layout)        == 0x58, "mmRenderState.input_layout");
_Static_assert(offsetof(ns3_mmRenderState, primitive_topo)      == 0x60, "mmRenderState.primitive_topo");

/* ========================================================================
 * mmShaderManager
 * Source: Initialize (0x790000)
 * ======================================================================== */
typedef struct ns3_mmShaderManager {
    void    *vtable;          /* 0x00 */
    void    *device;          /* 0x08 ID3D11Device* */
    void    *shader_cache;    /* 0x10 */
    uint32_t shader_count;    /* 0x18 */
    uint32_t max_shaders;     /* 0x1c */
    void    *vs_table;        /* 0x20 */
    void    *ps_table;        /* 0x28 */
    void    *cs_table;        /* 0x30 */
    void    *cb_table;        /* 0x38 */
    uint8_t  initialized;     /* 0x40 */
    uint8_t  _pad_41[7];      /* 0x41-0x47 */
} ns3_mmShaderManager;

_Static_assert(offsetof(ns3_mmShaderManager, device)        == 0x08, "mmShaderManager.device");
_Static_assert(offsetof(ns3_mmShaderManager, shader_cache)  == 0x10, "mmShaderManager.shader_cache");
_Static_assert(offsetof(ns3_mmShaderManager, shader_count)  == 0x18, "mmShaderManager.shader_count");
_Static_assert(offsetof(ns3_mmShaderManager, max_shaders)   == 0x1c, "mmShaderManager.max_shaders");
_Static_assert(offsetof(ns3_mmShaderManager, vs_table)      == 0x20, "mmShaderManager.vs_table");
_Static_assert(offsetof(ns3_mmShaderManager, ps_table)      == 0x28, "mmShaderManager.ps_table");
_Static_assert(offsetof(ns3_mmShaderManager, cs_table)      == 0x30, "mmShaderManager.cs_table");
_Static_assert(offsetof(ns3_mmShaderManager, cb_table)      == 0x38, "mmShaderManager.cb_table");
_Static_assert(offsetof(ns3_mmShaderManager, initialized)   == 0x40, "mmShaderManager.initialized");

/* ========================================================================
 * mmTextureManager
 * Source: Initialize (0x791000)
 * ======================================================================== */
typedef struct ns3_mmTextureManager {
    void    *vtable;           /* 0x00 */
    void    *device;           /* 0x08 ID3D11Device* */
    void    *texture_cache;    /* 0x10 */
    uint32_t texture_count;    /* 0x18 */
    uint32_t max_textures;     /* 0x1c */
    void    *sampler_states;   /* 0x20 */
    uint32_t sampler_count;    /* 0x28 */
    uint32_t max_samplers;     /* 0x2c */
    void    *srv_cache;        /* 0x30 */
    uint8_t  initialized;      /* 0x38 */
    uint8_t  _pad_39[7];       /* 0x39-0x3f */
} ns3_mmTextureManager;

_Static_assert(offsetof(ns3_mmTextureManager, device)         == 0x08, "mmTextureManager.device");
_Static_assert(offsetof(ns3_mmTextureManager, texture_cache)  == 0x10, "mmTextureManager.texture_cache");
_Static_assert(offsetof(ns3_mmTextureManager, texture_count)  == 0x18, "mmTextureManager.texture_count");
_Static_assert(offsetof(ns3_mmTextureManager, max_textures)   == 0x1c, "mmTextureManager.max_textures");
_Static_assert(offsetof(ns3_mmTextureManager, sampler_states) == 0x20, "mmTextureManager.sampler_states");
_Static_assert(offsetof(ns3_mmTextureManager, sampler_count)  == 0x28, "mmTextureManager.sampler_count");
_Static_assert(offsetof(ns3_mmTextureManager, max_samplers)   == 0x2c, "mmTextureManager.max_samplers");
_Static_assert(offsetof(ns3_mmTextureManager, srv_cache)      == 0x30, "mmTextureManager.srv_cache");
_Static_assert(offsetof(ns3_mmTextureManager, initialized)    == 0x38, "mmTextureManager.initialized");