/* cmn28.h — Storm 4 Ultimate Ninja Impact (NSUNS4_release.exe, s4) common engine struct definitions
 * Build: s4 / NSUNS4_release.exe 1.09 / image base 0x140000000
 * All offsets INFERRED from static decompilation of PC x64 binary.
 * Own-game names only (Storm 4 symbols/strings). No cross-game names.
 * Generated 2026-10-19 by cmn28-s4 pre-decompile task.
 *
 * Qualifying classes (>=3 methods with field evidence):
 * mmFileSys_Impl, mmGPUDevice_NX
 *
 * Classes with no instance state (0 fields from state_surface across all seeds):
 * mmFilePath — 3 methods (GetDir, GetNameNoExt, Format), static/utility
 * mmFileSys — 6 methods (Initialize, GetPlatformPath, Find, FromOSPath, AddDrive, Exist), pure virtual interface
 * mmGPUBufferWrapper — 4 methods (CreateBuffer x3, Lock), opaque wrapper
 * mmGPUResourceFactory — 7 methods (CreateTexture, CreateComputeShader, CreateConstantBuffer, CreatePixelShader, CreateBuffer, CreateRenderTarget x2), stateless factory
 *
 * Classes absent from s4 build or with <3 methods:
 * mmFilePathParser — 1 method only
 * mmFilePathParseResult — 1 method only
 * mmFileSys_Android — 1 method only (Android-specific, minimal in PC build)
 * mmGPURenderState — 2 methods only
 * mmGPURenderStateBlend_DX11 — 1 method only
 * mmGPUResource_DX11 — 1 method only
 */
#ifndef CMN28_S4_H
#define CMN28_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---------------------------------------------------------------------------
 * mmFileSys_Impl — platform file-system implementation
 * Size: unknown, >= 0x50 (ctor zero-inits through param_1[9] = offset 0x48; next qword boundary = 0x50)
 * Proven size: no operator new or allocator size found in s4 for this class.
 * Methods: mmFileSys_Impl (0xA738C0), ~mmFileSys_Impl (0x1800B0), AddDrive (0x180120)
 * Vtable: PTR_FUN_14110ce60
 * --------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) mmFileSys_Impl {
    void *vtable;           /* 0x00 — PTR_FUN_14110ce60 */
    uint64_t _field_08;     /* 0x08 — param_1[1], zeroed in ctor */
    uint64_t _field_10;     /* 0x10 — param_1[2], zeroed in ctor */
    uint64_t _field_18;     /* 0x18 — param_1[3], zeroed in ctor */
    uint64_t _field_20;     /* 0x20 — param_1[4], zeroed in ctor */
    uint32_t _field_28;     /* 0x28 — *(undefined4*)(param_1+5), zeroed as u32 in ctor */
    uint8_t flag_2C;        /* 0x2C — byte write in ctor, likely bool */
    uint8_t _pad_2D[3];     /* 0x2D — alignment padding */
    uint64_t _field_30;     /* 0x30 — param_1[6], zeroed in ctor */
    uint32_t _field_38;     /* 0x38 — *(undefined4*)(param_1+7), zeroed as u32 in ctor */
    uint8_t flag_3C;        /* 0x3C — byte write in ctor, likely bool */
    uint8_t _pad_3D[3];     /* 0x3D — alignment padding */
    uint64_t _field_40;     /* 0x40 — param_1[8], zeroed in ctor */
    uint64_t _field_48;     /* 0x48 — param_1[9], zeroed in ctor */
} mmFileSys_Impl;

_Static_assert(offsetof(mmFileSys_Impl, vtable) == 0x00, "mmFileSys_Impl.vtable");
_Static_assert(offsetof(mmFileSys_Impl, _field_08) == 0x08, "mmFileSys_Impl._field_08");
_Static_assert(offsetof(mmFileSys_Impl, _field_10) == 0x10, "mmFileSys_Impl._field_10");
_Static_assert(offsetof(mmFileSys_Impl, _field_18) == 0x18, "mmFileSys_Impl._field_18");
_Static_assert(offsetof(mmFileSys_Impl, _field_20) == 0x20, "mmFileSys_Impl._field_20");
_Static_assert(offsetof(mmFileSys_Impl, _field_28) == 0x28, "mmFileSys_Impl._field_28");
_Static_assert(offsetof(mmFileSys_Impl, flag_2C) == 0x2C, "mmFileSys_Impl.flag_2C");
_Static_assert(offsetof(mmFileSys_Impl, _field_30) == 0x30, "mmFileSys_Impl._field_30");
_Static_assert(offsetof(mmFileSys_Impl, _field_38) == 0x38, "mmFileSys_Impl._field_38");
_Static_assert(offsetof(mmFileSys_Impl, flag_3C) == 0x3C, "mmFileSys_Impl.flag_3C");
_Static_assert(offsetof(mmFileSys_Impl, _field_40) == 0x40, "mmFileSys_Impl._field_40");
_Static_assert(offsetof(mmFileSys_Impl, _field_48) == 0x48, "mmFileSys_Impl._field_48");
/* size unknown, >= 0x50 — no sizeof assert */

/* ---------------------------------------------------------------------------
 * mmGPUDevice_NX — GPU device abstraction (DX11 backend)
 * Size: unknown, >= 0x38 (last observed field at 0x34 + 4 bytes)
 * Proven size: no operator new for mmGPUDevice_NX itself found in s4.
 * Allocation sizes in InitializeRenderSystem (0x1890A0) are for composed sub-objects:
 *   0x1A0 — DX11 device object (FUN_14019c760)
 *   0x68  — shader effect compiler
 *   0x138 — render system object (vtable PTR_FUN_1412f83c0)
 * Methods: InitializeRenderSystem (0x1890A0, 0x9E42D0), Initialize (0x188C90),
 *          Finalize (0x188CF0), InterpretSystemMessage (0x188E50),
 *          ~mmGPUDevice_NX (0x188C40)
 * Vtables: PTR_FUN_1412f83e0 (dtor), PTR_FUN_1412f8368 (base after dtor)
 * --------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) mmGPUDevice_NX {
    void *vtable;                /* 0x00 — implicit C++ vptr; dtor sets PTR_FUN_1412f83e0 then PTR_FUN_1412f8368 */
    void *dx11_device;           /* 0x08 — param_1[1], FUN_14019c760 result; freed via vfunc in Finalize */
    void *shader_effect_compiler;/* 0x10 — param_1[2], mmShaderEffectCompiler-like object */
    void *render_system;         /* 0x18 — param_1[3], vtable PTR_FUN_1412f83c0; freed via vfunc in Finalize */
    void *hwnd;                  /* 0x20 — param_1[4], HWND for DestroyWindow */
    void *hinstance;             /* 0x28 — HINSTANCE for UnregisterClassW("MME_Sample") */
    int32_t display_mode_flag;   /* 0x30 — checked == 1 in Finalize before ChangeDisplaySettingsW */
    int32_t adapter_index;       /* 0x34 — written from *param_2 on success path in InitializeRenderSystem */
    /* size unknown, >= 0x38 — no sizeof assert */
} mmGPUDevice_NX;

_Static_assert(offsetof(mmGPUDevice_NX, vtable) == 0x00, "mmGPUDevice_NX.vtable");
_Static_assert(offsetof(mmGPUDevice_NX, dx11_device) == 0x08, "mmGPUDevice_NX.dx11_device");
_Static_assert(offsetof(mmGPUDevice_NX, shader_effect_compiler)== 0x10, "mmGPUDevice_NX.shader_effect_compiler");
_Static_assert(offsetof(mmGPUDevice_NX, render_system) == 0x18, "mmGPUDevice_NX.render_system");
_Static_assert(offsetof(mmGPUDevice_NX, hwnd) == 0x20, "mmGPUDevice_NX.hwnd");
_Static_assert(offsetof(mmGPUDevice_NX, hinstance) == 0x28, "mmGPUDevice_NX.hinstance");
_Static_assert(offsetof(mmGPUDevice_NX, display_mode_flag) == 0x30, "mmGPUDevice_NX.display_mode_flag");
_Static_assert(offsetof(mmGPUDevice_NX, adapter_index) == 0x34, "mmGPUDevice_NX.adapter_index");
/* size unknown, >= 0x38 — no sizeof assert */

/* ---------------------------------------------------------------------------
 * mmFilePath — no instance state
 * Evidence: state_surface returned 0 fields across 3 seed methods in s3
 * (GetDir, GetNameNoExt, Format). All methods operate on stack/temp data.
 * --------------------------------------------------------------------------- */
/* no instance state — mmFilePath is a static/utility class */

/* ---------------------------------------------------------------------------
 * mmFileSys — no instance state
 * Evidence: state_surface returned 0 fields across 6 seed methods in s3
 * (Initialize, GetPlatformPath, Find, FromOSPath, AddDrive, Exist).
 * Pure virtual interface delegating to mmFileSys_Impl.
 * --------------------------------------------------------------------------- */
/* no instance state — mmFileSys is a pure virtual interface */

/* ---------------------------------------------------------------------------
 * mmGPUBufferWrapper — no instance state
 * Evidence: state_surface returned 0 fields across 4 seed methods in s3
 * (CreateBuffer x3, Lock). Opaque wrapper around GPU buffer handles.
 * --------------------------------------------------------------------------- */
/* no instance state — mmGPUBufferWrapper is an opaque wrapper */

/* ---------------------------------------------------------------------------
 * mmGPUResourceFactory — no instance state
 * Evidence: state_surface returned 0 fields across 7 seed methods in s3
 * (CreateTexture, CreateComputeShader, CreateConstantBuffer, CreatePixelShader,
 *  CreateBuffer, CreateRenderTarget x2). Stateless factory pattern.
 * --------------------------------------------------------------------------- */
/* no instance state — mmGPUResourceFactory is a stateless factory */

#endif /* CMN28_S4_H */