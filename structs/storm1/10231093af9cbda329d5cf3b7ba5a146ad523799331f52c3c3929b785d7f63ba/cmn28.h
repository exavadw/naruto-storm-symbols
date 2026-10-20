#ifndef CMN28_H
#define CMN28_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * cmn28 — Storm 1 (NSUNS1.exe, s1) common engine struct definitions.
 * Build: s1 / NSUNS1.exe-a9fe00 / image base 0x140000000
 * All offsets INFERRED from static decompilation of PC x64 binary.
 * Own-game names only (ns1:: / Storm 1 strings). No cross-game names.
 *
 * Qualifying classes (>=3 methods with field evidence):
 *   mmFileSys_Impl, mmGPUDevice_NX, mmGPURenderState,
 *   mmGPUResource_DX11, mmGPUResourceFactory
 *
 * Skipped (present but insufficient instance-field evidence or <3 instance methods):
 *   mmFilePath (3 methods, static/utility — no this-pointer fields)
 *   mmFilePathParser (1 method: Parse)
 *   mmFilePathParseResult (1 method: GetDir)
 *   mmFileSys (7 methods, all static — no this-pointer fields)
 *   mmFileSys_Android (1 method: ctor — Android-only, absent from PC build)
 *   mmGPUBufferWrapper (4 methods, no extractable field accesses)
 *   mmGPURenderStateBlend_DX11 (1 method: Create)
 */

/* -------------------------------------------------------------------------
 * mmFileSys_Impl — platform file-system implementation
 * Size unknown, >= 0x48 (inferred from ctor zero-init span, no allocation found)
 * Methods: mmFileSys_Impl (0x4D5830), ~mmFileSys_Impl (0x1028C0), AddDrive (0x102930)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmFileSys_Impl {
    void       *vtable;           /* 0x00 — PTR_FUN_14073c990 */
    uint8_t     pad_08[0x24];     /* 0x08-0x2B: zeroed in ctor */
    uint8_t     flag_2C;          /* 0x2C — byte write in ctor */
    uint8_t     pad_2D[0x0F];     /* 0x2D-0x3B */
    uint8_t     flag_3C;          /* 0x3C — byte write in ctor */
    uint8_t     pad_3D[0x0B];     /* 0x3D-0x47 */
} mmFileSys_Impl;
#pragma pack(pop)
/* size unknown, >= 0x48 */
_Static_assert(offsetof(mmFileSys_Impl, vtable) == 0x00, "mmFileSys_Impl.vtable");
_Static_assert(offsetof(mmFileSys_Impl, flag_2C) == 0x2C, "mmFileSys_Impl.flag_2C");
_Static_assert(offsetof(mmFileSys_Impl, flag_3C) == 0x3C, "mmFileSys_Impl.flag_3C");

/* -------------------------------------------------------------------------
 * mmGPUDevice_NX — GPU device abstraction (DX11 backend)
 * Size: 0x1A0 (from _aligned_malloc(0x1A0, 0x10) in InitializeRenderSystem)
 * Methods: InitializeRenderSystem (0x10B020/0x453D00), Initialize (0x10AC10),
 *          Finalize (0x10AC70), InterpretSystemMessage (0x10ADD0),
 *          ~mmGPUDevice_NX (0x10ABC0)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmGPUDevice_NX {
    void       *vtable;           /* 0x00 */
    void       *renderManager;    /* 0x08 — FUN_14011ec30 result */
    void       *shaderCompiler;   /* 0x10 — mmShaderEffectCompiler ctor */
    void       *renderSystem;     /* 0x18 — allocated 0x138 object */
    void       *hwnd;             /* 0x20 — HWND for MessageBoxW */
    uint8_t     pad_28[0x0C];     /* 0x28-0x33 */
    int32_t     initFlag;         /* 0x34 — written from *param_2 in InitRS */
    uint8_t     pad_38[0x168];    /* 0x38-0x19F */
} mmGPUDevice_NX;
#pragma pack(pop)
/* Size: 0x1A0 (from _aligned_malloc) */
_Static_assert(sizeof(mmGPUDevice_NX) == 0x1A0, "mmGPUDevice_NX size mismatch");
_Static_assert(offsetof(mmGPUDevice_NX, vtable) == 0x00, "mmGPUDevice_NX.vtable");
_Static_assert(offsetof(mmGPUDevice_NX, renderManager) == 0x08, "mmGPUDevice_NX.renderManager");
_Static_assert(offsetof(mmGPUDevice_NX, shaderCompiler) == 0x10, "mmGPUDevice_NX.shaderCompiler");
_Static_assert(offsetof(mmGPUDevice_NX, renderSystem) == 0x18, "mmGPUDevice_NX.renderSystem");
_Static_assert(offsetof(mmGPUDevice_NX, hwnd) == 0x20, "mmGPUDevice_NX.hwnd");
_Static_assert(offsetof(mmGPUDevice_NX, initFlag) == 0x34, "mmGPUDevice_NX.initFlag");

/* -------------------------------------------------------------------------
 * mmGPUResource_DX11 — base GPU resource wrapper
 * Size: 0x68 (from _aligned_malloc(0x68) in CreateRenderTarget inner)
 * Methods: mmGPUResource_DX11 (0x1138E0 area — ctor seen inline)
 * Layout from ctor: vtable swap pattern (base -> derived), device ptr, flags
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmGPUResource_DX11 {
    void       *vtable;           /* 0x00 — PTR_FUN_140774848 -> PTR_FUN_1407748a8 */
    uint8_t     pad_08[0x50];     /* 0x08-0x57: zeroed in ctor */
    uint8_t     flag_58;          /* 0x58 — byte, set to 0 in ctor */
    uint8_t     pad_59[0x07];     /* 0x59-0x5F */
    void       *devicePtr;        /* 0x60 — *(lVar1+0x48) from render context */
} mmGPUResource_DX11;
#pragma pack(pop)
/* Size: 0x68 (from _aligned_malloc) */
_Static_assert(sizeof(mmGPUResource_DX11) == 0x68, "mmGPUResource_DX11 size mismatch");
_Static_assert(offsetof(mmGPUResource_DX11, vtable) == 0x00, "mmGPUResource_DX11.vtable");
_Static_assert(offsetof(mmGPUResource_DX11, flag_58) == 0x58, "mmGPUResource_DX11.flag_58");
_Static_assert(offsetof(mmGPUResource_DX11, devicePtr) == 0x60, "mmGPUResource_DX11.devicePtr");

/* -------------------------------------------------------------------------
 * mmGPURenderState — render state cache / pipeline state object
 * Size: 0x200 (from _aligned_malloc(0x200, 0x10) in ctor)
 * Methods: mmGPURenderState (0x1138E0), UpdateRenderState (seen in decomp)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmGPURenderState {
    void       *vtable;           /* 0x00 */
    void       *vertexShader;     /* 0x08 — read/write in UpdateRenderState */
    void       *pixelShader;      /* 0x10 — read/write in UpdateRenderState */
    uint8_t     pad_18[0x80];     /* 0x18-0x97 */
    void       *blendState;       /* 0x98 — passed to FUN_1401228e0 */
    uint8_t     pad_A0[0x28];     /* 0xA0-0xC7 */
    void       *treeRoot;         /* 0xC8 — param_1+200 tree root */
    uint8_t     pad_D0[0x08];     /* 0xD0-0xD7 */
    void      **treePtr;          /* 0xD8 — undefined8** tree traversal */
    uint8_t     pad_E0[0x30];     /* 0xE0-0x10F */
    void       *rasterizerState;  /* 0x110 — passed to FUN_140122ae0 */
    uint8_t     pad_118[0x20];    /* 0x118-0x137 */
    void       *samplerMap;       /* 0x138 — passed to FUN_140123d30 */
    void       *samplerSentinel;  /* 0x140 — param_1+0x140 end sentinel */
    uint8_t     pad_148[0x68];    /* 0x148-0x1AF */
    void       *textureMap;       /* 0x1B0 — passed to FUN_140124140 */
    void       *textureSentinel;  /* 0x1B8 — param_1+0x1B8 end sentinel */
    uint8_t     pad_1C0[0x40];    /* 0x1C0-0x1FF */
} mmGPURenderState;
#pragma pack(pop)
/* Size: 0x200 (from _aligned_malloc) */
_Static_assert(sizeof(mmGPURenderState) == 0x200, "mmGPURenderState size mismatch");
_Static_assert(offsetof(mmGPURenderState, vtable) == 0x00, "mmGPURenderState.vtable");
_Static_assert(offsetof(mmGPURenderState, vertexShader) == 0x08, "mmGPURenderState.vertexShader");
_Static_assert(offsetof(mmGPURenderState, pixelShader) == 0x10, "mmGPURenderState.pixelShader");
_Static_assert(offsetof(mmGPURenderState, blendState) == 0x98, "mmGPURenderState.blendState");
_Static_assert(offsetof(mmGPURenderState, treeRoot) == 0xC8, "mmGPURenderState.treeRoot");
_Static_assert(offsetof(mmGPURenderState, treePtr) == 0xD8, "mmGPURenderState.treePtr");
_Static_assert(offsetof(mmGPURenderState, rasterizerState) == 0x110, "mmGPURenderState.rasterizerState");
_Static_assert(offsetof(mmGPURenderState, samplerMap) == 0x138, "mmGPURenderState.samplerMap");
_Static_assert(offsetof(mmGPURenderState, samplerSentinel) == 0x140, "mmGPURenderState.samplerSentinel");
_Static_assert(offsetof(mmGPURenderState, textureMap) == 0x1B0, "mmGPURenderState.textureMap");
_Static_assert(offsetof(mmGPURenderState, textureSentinel) == 0x1B8, "mmGPURenderState.textureSentinel");

/* -------------------------------------------------------------------------
 * mmGPUResourceFactory_RenderTarget — factory-created render target object
 * Size unknown, >= 0x148 (highest accessed offset 0x140 + 8)
 * Methods: CreateRenderTarget (0x452AD0/0x112780)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmGPUResourceFactory_RenderTarget {
    uint32_t    typeTag;          /* 0x00 — set last in CreateRT */
    uint32_t    handles[18];      /* 0x04-0x4B — 9 pairs alternating 0/0xFFFFFFFF */
    uint32_t    rtIndex;          /* 0x4C — zeroed in CreateRT */
    void       *subObjectPtr;     /* 0x50 — mmRenderState::UpdateRenderState target base */
    uint8_t     renderState[216]; /* 0x58-0x12F — embedded sub-object */
    uint64_t    resourceHandle;   /* 0x130 — created resource ptr */
    uint32_t    flags;            /* 0x138 — zeroed in CreateRT */
    uint32_t    pad_13C;          /* 0x13C */
    void       *secondaryPtr;     /* 0x140 — zeroed in CreateRT */
} mmGPUResourceFactory_RenderTarget;
#pragma pack(pop)
/* size unknown, >= 0x148 */
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, typeTag) == 0x00, "mmGPUResourceFactory_RenderTarget.typeTag");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, handles) == 0x04, "mmGPUResourceFactory_RenderTarget.handles");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, rtIndex) == 0x4C, "mmGPUResourceFactory_RenderTarget.rtIndex");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, subObjectPtr) == 0x50, "mmGPUResourceFactory_RenderTarget.subObjectPtr");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, renderState) == 0x58, "mmGPUResourceFactory_RenderTarget.renderState");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, resourceHandle) == 0x130, "mmGPUResourceFactory_RenderTarget.resourceHandle");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, flags) == 0x138, "mmGPUResourceFactory_RenderTarget.flags");
_Static_assert(offsetof(mmGPUResourceFactory_RenderTarget, secondaryPtr) == 0x140, "mmGPUResourceFactory_RenderTarget.secondaryPtr");

/* -------------------------------------------------------------------------
 * mmDrawCommand_RenderPolygon — polygon draw command
 * Size unknown, >= 0xA0
 * Accessed offsets: 0x30 (vertex data ptr), 0x80 (mode flag u8),
 *   0x88 (secondary ptr when mode==1), 0x98/0x9C (u32 params)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmDrawCommand_RenderPolygon {
    uint8_t     pad_00[0x30];     /* 0x00-0x2F */
    void       *vertexData;       /* 0x30 — passed to vtable+0x80 call */
    uint8_t     pad_38[0x48];     /* 0x38-0x7F */
    uint8_t     mode;             /* 0x80 — 0 or 1 branch selector */
    uint8_t     pad_81[0x07];     /* 0x81-0x87 */
    void       *secondaryData;    /* 0x88 — used when mode==1 */
    uint8_t     pad_90[0x08];     /* 0x90-0x97 */
    uint32_t    param1;           /* 0x98 — passed to dispatch */
    uint32_t    param2;           /* 0x9C — passed to dispatch */
} mmDrawCommand_RenderPolygon;
#pragma pack(pop)
/* size unknown, >= 0xA0 */
_Static_assert(offsetof(mmDrawCommand_RenderPolygon, vertexData) == 0x30, "mmDrawCommand_RenderPolygon.vertexData");
_Static_assert(offsetof(mmDrawCommand_RenderPolygon, mode) == 0x80, "mmDrawCommand_RenderPolygon.mode");
_Static_assert(offsetof(mmDrawCommand_RenderPolygon, secondaryData) == 0x88, "mmDrawCommand_RenderPolygon.secondaryData");
_Static_assert(offsetof(mmDrawCommand_RenderPolygon, param1) == 0x98, "mmDrawCommand_RenderPolygon.param1");
_Static_assert(offsetof(mmDrawCommand_RenderPolygon, param2) == 0x9C, "mmDrawCommand_RenderPolygon.param2");

/* -------------------------------------------------------------------------
 * mmDrawCommand_SetRenderState — render state change command
 * Size unknown, >= 0x38
 * Accessed offset: 0x30 (state value u64)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmDrawCommand_SetRenderState {
    uint8_t     pad_00[0x30];     /* 0x00-0x2F */
    uint64_t    stateValue;       /* 0x30 — passed to SetRenderState */
} mmDrawCommand_SetRenderState;
#pragma pack(pop)
/* size unknown, >= 0x38 */
_Static_assert(offsetof(mmDrawCommand_SetRenderState, stateValue) == 0x30, "mmDrawCommand_SetRenderState.stateValue");

/* -------------------------------------------------------------------------
 * mmDrawCommand_BindConstantBuffer — constant buffer bind command
 * Size unknown, >= 0x40
 * Accessed offsets: 0x30 (slot u32), 0x34 (index u16), 0x38 (buffer ptr u64)
 * ---------------------------------------------------------------------- */
#pragma pack(push, 1)
typedef struct mmDrawCommand_BindConstantBuffer {
    uint8_t     pad_00[0x30];     /* 0x00-0x2F */
    uint32_t    slot;             /* 0x30 — bind slot index */
    uint16_t    index;            /* 0x34 — buffer index */
    uint16_t    pad_36;           /* 0x36 */
    void       *buffer;           /* 0x38 — buffer pointer (null-checked) */
} mmDrawCommand_BindConstantBuffer;
#pragma pack(pop)
/* size unknown, >= 0x40 */
_Static_assert(offsetof(mmDrawCommand_BindConstantBuffer, slot) == 0x30, "mmDrawCommand_BindConstantBuffer.slot");
_Static_assert(offsetof(mmDrawCommand_BindConstantBuffer, index) == 0x34, "mmDrawCommand_BindConstantBuffer.index");
_Static_assert(offsetof(mmDrawCommand_BindConstantBuffer, buffer) == 0x38, "mmDrawCommand_BindConstantBuffer.buffer");

/* -------------------------------------------------------------------------
 * mmGPUResourceFactory: no instance state
 * All 7 methods are static/factory functions that take external params only.
 * CreateTexture (0x112D00), CreateSamplerEntity (0x112AE0),
 * CreateRenderTarget (0x452AD0, 0x112780), CreateComputeShader (0x117F90),
 * CreateBuffer (0x119BF0), CreateConstantBuffer (0x1146E0).
 * state_surface shows zero this-pointer field accesses across all methods
 * except CreateRenderTarget which operates on a separately-allocated output
 * object (mmGPUResourceFactory_RenderTarget, defined above).
 * ---------------------------------------------------------------------- */

/* -------------------------------------------------------------------------
 * mmGPUBufferWrapper: no instance state
 * All 4 methods are static wrappers with no this-pointer field accesses.
 * CreateBuffer (0x1199B0, 0x1198C0, 0x10CBA0), Lock (0x119AC0).
 * state_surface returned 0 fields; decompiles show param_1 is not dereferenced
 * as an object pointer.
 * ---------------------------------------------------------------------- */

/* -------------------------------------------------------------------------
 * mmFilePath: no instance state
 * All 3 methods are static string-utility functions with no this-pointer usage.
 * GetDir (0x1025A0), GetNameNoExt (0x102690), Format (0x102F00).
 * state_surface returned 0 fields; decompiles confirm pure-function signatures.
 * ---------------------------------------------------------------------- */

#endif /* CMN28_H */