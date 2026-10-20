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

/* ------------------------------------------------------------------ */
/* mmCompileInfo — compile-time error/warning collector               */
/* Size unknown (>= 0x4b8); fields from Reset switch + AddErrorMsg    */
/* hash-table layout. All offsets INFERRED from s3 PC decompile.      */
/* ------------------------------------------------------------------ */
#pragma pack(push,1)
typedef struct ns3_mmCompileInfo {
    uint8_t  _pad_00[0x08];            /* 0x00-0x07 */
    void    *reset_slot_7;             /* 0x08  type code 7 */
    uint8_t  _pad_10[0x20];            /* 0x10-0x2f */
    void    *errmsg_buckets;           /* 0x30  AddErrorMsg hash table */
    uint64_t errmsg_meta;              /* 0x38 */
    uint8_t  _pad_40[0x18];            /* 0x40-0x57 */
    void    *reset_slot_8;             /* 0x58  type code 8 / warn tbl */
    uint64_t errmsg_meta2;             /* 0x60 */
    uint8_t  _pad_68[0x18];            /* 0x68-0x7f */
    void    *warn_buckets;             /* 0x80  second hash table */
    uint64_t warn_meta;                /* 0x88 */
    uint8_t  _pad_90[0x18];            /* 0x90-0xa7 */
    void    *reset_slot_9;             /* 0xa8  type code 9 / third tbl */
    uint64_t warn_meta2;               /* 0xb0 */
    uint8_t  _pad_b8[0x40];            /* 0xb8-0xf7 */
    void    *reset_slot_10;            /* 0xf8  type code 10 */
    uint8_t  _pad_100[0x48];           /* 0x100-0x147 */
    void    *reset_slot_0d;            /* 0x148 type code 0xd */
    uint8_t  _pad_150[0x48];           /* 0x150-0x197 */
    void    *reset_slot_0e;            /* 0x198 type code 0xe */
    uint8_t  _pad_1a0[0x48];           /* 0x1a0-0x1e7 */
    void    *reset_slot_25;            /* 0x1e8 type code 0x25 */
    uint8_t  _pad_1f0[0x48];           /* 0x1f0-0x237 */
    void    *reset_slot_26;            /* 0x238 type code 0x26 */
    uint8_t  _pad_240[0x48];           /* 0x240-0x287 */
    void    *reset_slot_27;            /* 0x288 type code 0x27 */
    uint8_t  _pad_290[0x48];           /* 0x290-0x2d7 */
    void    *reset_slot_28;            /* 0x2d8 type code 0x28 */
    uint8_t  _pad_2e0[0x48];           /* 0x2e0-0x327 */
    void    *reset_slot_29;            /* 0x328 type code 0x29 */
    uint8_t  _pad_330[0x48];           /* 0x330-0x377 */
    void    *reset_slot_37;            /* 0x378 type code 0x37 */
    uint8_t  _pad_380[0x48];           /* 0x380-0x3c7 */
    void    *reset_slot_4a;            /* 0x3c8 type code 0x4a */
    uint8_t  _pad_3d0[0x48];           /* 0x3d0-0x417 */
    void    *reset_slot_6c;            /* 0x418 type code 0x6c */
    uint8_t  _pad_420[0x48];           /* 0x420-0x467 */
    void    *reset_slot_6f;            /* 0x468 type code 0x6f */
} ns3_mmCompileInfo;
#pragma pack(pop)

_Static_assert(offsetof(ns3_mmCompileInfo, _pad_00)        == 0x000, "mmCompileInfo._pad_00");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_7)   == 0x008, "mmCompileInfo.reset_slot_7");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_10)        == 0x010, "mmCompileInfo._pad_10");
_Static_assert(offsetof(ns3_mmCompileInfo, errmsg_buckets) == 0x030, "mmCompileInfo.errmsg_buckets");
_Static_assert(offsetof(ns3_mmCompileInfo, errmsg_meta)    == 0x038, "mmCompileInfo.errmsg_meta");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_40)        == 0x040, "mmCompileInfo._pad_40");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_8)   == 0x058, "mmCompileInfo.reset_slot_8");
_Static_assert(offsetof(ns3_mmCompileInfo, errmsg_meta2)   == 0x060, "mmCompileInfo.errmsg_meta2");
_Static_assert(offsetof(ns3_mmCompileInfo, warn_buckets)   == 0x080, "mmCompileInfo.warn_buckets");
_Static_assert(offsetof(ns3_mmCompileInfo, warn_meta)      == 0x088, "mmCompileInfo.warn_meta");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_9)   == 0x0a8, "mmCompileInfo.reset_slot_9");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_68)        == 0x068, "mmCompileInfo._pad_68");
_Static_assert(offsetof(ns3_mmCompileInfo, warn_meta2)     == 0x0b0, "mmCompileInfo.warn_meta2");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_90)        == 0x090, "mmCompileInfo._pad_90");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_b8)        == 0x0b8, "mmCompileInfo._pad_b8");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_10)  == 0x0f8, "mmCompileInfo.reset_slot_10");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_100)       == 0x100, "mmCompileInfo._pad_100");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_150)       == 0x150, "mmCompileInfo._pad_150");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_1a0)       == 0x1a0, "mmCompileInfo._pad_1a0");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_1f0)       == 0x1f0, "mmCompileInfo._pad_1f0");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_240)       == 0x240, "mmCompileInfo._pad_240");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_290)       == 0x290, "mmCompileInfo._pad_290");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_2e0)       == 0x2e0, "mmCompileInfo._pad_2e0");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_330)       == 0x330, "mmCompileInfo._pad_330");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_380)       == 0x380, "mmCompileInfo._pad_380");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_3d0)       == 0x3d0, "mmCompileInfo._pad_3d0");
_Static_assert(offsetof(ns3_mmCompileInfo, _pad_420)       == 0x420, "mmCompileInfo._pad_420");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_0d)  == 0x148, "mmCompileInfo.reset_slot_0d");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_0e)  == 0x198, "mmCompileInfo.reset_slot_0e");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_25)  == 0x1e8, "mmCompileInfo.reset_slot_25");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_26)  == 0x238, "mmCompileInfo.reset_slot_26");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_27)  == 0x288, "mmCompileInfo.reset_slot_27");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_28)  == 0x2d8, "mmCompileInfo.reset_slot_28");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_29)  == 0x328, "mmCompileInfo.reset_slot_29");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_37)  == 0x378, "mmCompileInfo.reset_slot_37");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_4a)  == 0x3c8, "mmCompileInfo.reset_slot_4a");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_6c)  == 0x418, "mmCompileInfo.reset_slot_6c");
_Static_assert(offsetof(ns3_mmCompileInfo, reset_slot_6f)  == 0x468, "mmCompileInfo.reset_slot_6f");

/* ------------------------------------------------------------------ */
/* mmComputeShader — compute shader wrapper                           */
/* Size unknown (>= 0xf8); fields from Release + LoadFromCompiledFile */
/* ------------------------------------------------------------------ */
#pragma pack(push,1)
typedef struct ns3_mmComputeShader {
    uint8_t  _pad_00[0xc8];            /* 0x00-0xc7 */
    char    *name;                     /* 0xc8  shader name string */
    uint8_t  _pad_d0[0x20];            /* 0xd0-0xef */
    void    *internal_buffer;          /* 0xf0  released in Release() */
} ns3_mmComputeShader;
#pragma pack(pop)

_Static_assert(offsetof(ns3_mmComputeShader, _pad_00)         == 0x00, "mmComputeShader._pad_00");
_Static_assert(offsetof(ns3_mmComputeShader, name)            == 0xc8, "mmComputeShader.name");
_Static_assert(offsetof(ns3_mmComputeShader, _pad_d0)         == 0xd0, "mmComputeShader._pad_d0");
_Static_assert(offsetof(ns3_mmComputeShader, internal_buffer) == 0xf0, "mmComputeShader.internal_buffer");

/* ------------------------------------------------------------------ */
/* mmController_Win — Windows input controller                        */
/* Size unknown (>= 0x148); fields from Update + CreateDirectInput    */
/* ------------------------------------------------------------------ */
#pragma pack(push,1)
typedef struct ns3_mmController_Win {
    uint8_t  _pad_00[0x08];            /* 0x00-0x07 */
    uint8_t  update_flag;              /* 0x08 */
    uint8_t  _pad_09[3];               /* 0x09-0x0b */
    uint32_t button_state;             /* 0x0c  current frame buttons */
    uint32_t pressed_buttons;          /* 0x10  edge-triggered press */
    uint32_t released_buttons;         /* 0x14  edge-triggered release */
    uint8_t  _pad_18[4];               /* 0x18-0x1b */
    float    axis_0;                   /* 0x1c  deadzone 0.12 */
    float    axis_1;                   /* 0x20  deadzone 0.12 */
    float    axis_2;                   /* 0x24  deadzone 0.12 */
    float    axis_3;                   /* 0x28  deadzone 0.12 */
    uint8_t  _pad_2c[0x64];            /* 0x2c-0x8f */
    void    *input_mapping_table;      /* 0x90 */
    uint32_t mapping_table_size;       /* 0x98 */
    uint8_t  _pad_9c[0xa0];            /* 0x9c-0x13b */
    int32_t  controller_type;          /* 0x13c  1=keyboard 2=gamepad */
    uint8_t  _pad_140[8];              /* 0x140-0x147 */
    void    *direct_input_device;      /* 0x148 IDirectInputDevice8* */
} ns3_mmController_Win;
#pragma pack(pop)

_Static_assert(offsetof(ns3_mmController_Win, _pad_00)             == 0x000, "mmController_Win._pad_00");
_Static_assert(offsetof(ns3_mmController_Win, update_flag)          == 0x008, "mmController_Win.update_flag");
_Static_assert(offsetof(ns3_mmController_Win, _pad_09)             == 0x009, "mmController_Win._pad_09");
_Static_assert(offsetof(ns3_mmController_Win, _pad_18)             == 0x018, "mmController_Win._pad_18");
_Static_assert(offsetof(ns3_mmController_Win, _pad_2c)             == 0x02c, "mmController_Win._pad_2c");
_Static_assert(offsetof(ns3_mmController_Win, _pad_9c)             == 0x09c, "mmController_Win._pad_9c");
_Static_assert(offsetof(ns3_mmController_Win, _pad_140)            == 0x140, "mmController_Win._pad_140");
_Static_assert(offsetof(ns3_mmController_Win, button_state)         == 0x00c, "mmController_Win.button_state");
_Static_assert(offsetof(ns3_mmController_Win, pressed_buttons)     == 0x010, "mmController_Win.pressed_buttons");
_Static_assert(offsetof(ns3_mmController_Win, released_buttons)    == 0x014, "mmController_Win.released_buttons");
_Static_assert(offsetof(ns3_mmController_Win, axis_0)              == 0x01c, "mmController_Win.axis_0");
_Static_assert(offsetof(ns3_mmController_Win, axis_1)              == 0x020, "mmController_Win.axis_1");
_Static_assert(offsetof(ns3_mmController_Win, axis_2)              == 0x024, "mmController_Win.axis_2");
_Static_assert(offsetof(ns3_mmController_Win, axis_3)              == 0x028, "mmController_Win.axis_3");
_Static_assert(offsetof(ns3_mmController_Win, input_mapping_table) == 0x090, "mmController_Win.input_mapping_table");
_Static_assert(offsetof(ns3_mmController_Win, mapping_table_size)  == 0x098, "mmController_Win.mapping_table_size");
_Static_assert(offsetof(ns3_mmController_Win, controller_type)     == 0x13c, "mmController_Win.controller_type");
_Static_assert(offsetof(ns3_mmController_Win, direct_input_device) == 0x148, "mmController_Win.direct_input_device");

/* ------------------------------------------------------------------ */
/* mmCoreLibrary — global config singleton                            */
/* Allocated size 0x28 (align 0x10) from Initialize. Fields from      */
/* DAT_140c23e10 writes in FUN_140678770.                             */
/* ------------------------------------------------------------------ */
#pragma pack(push,1)
typedef struct ns3_mmCoreLibrary {
    void    *vtable;                   /* 0x00 */
    uint32_t config_field_0;           /* 0x08 */
    uint32_t config_field_1;           /* 0x0c */
    uint32_t config_field_2;           /* 0x10 */
    uint32_t config_field_3;           /* 0x14 */
    uint64_t config_field_4;           /* 0x18 */
    uint32_t config_field_5;           /* 0x20 */
    uint8_t  _pad_24[4];               /* 0x24-0x27 */
} ns3_mmCoreLibrary;
#pragma pack(pop)

_Static_assert(sizeof(ns3_mmCoreLibrary)                          == 0x28, "mmCoreLibrary.size");
_Static_assert(offsetof(ns3_mmCoreLibrary, vtable)                == 0x00, "mmCoreLibrary.vtable");
_Static_assert(offsetof(ns3_mmCoreLibrary, config_field_0)        == 0x08, "mmCoreLibrary.config_field_0");
_Static_assert(offsetof(ns3_mmCoreLibrary, config_field_1)        == 0x0c, "mmCoreLibrary.config_field_1");
_Static_assert(offsetof(ns3_mmCoreLibrary, config_field_2)        == 0x10, "mmCoreLibrary.config_field_2");
_Static_assert(offsetof(ns3_mmCoreLibrary, config_field_3)        == 0x14, "mmCoreLibrary.config_field_3");
_Static_assert(offsetof(ns3_mmCoreLibrary, config_field_4)        == 0x18, "mmCoreLibrary.config_field_4");
_Static_assert(offsetof(ns3_mmCoreLibrary, config_field_5)        == 0x20, "mmCoreLibrary.config_field_5");
_Static_assert(offsetof(ns3_mmCoreLibrary, _pad_24)               == 0x24, "mmCoreLibrary._pad_24");