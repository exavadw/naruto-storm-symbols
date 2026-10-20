/* cmn28.h — Storm 3 Full Burst HD (NSUNS3.exe, s3) common engine struct definitions
 * Build: s3 / NSUNS3.exe-a7124b / sha 55b726e94dad / image base 0x140000000
 * All offsets INFERRED from static decompilation of PC x64 binary.
 * Own-game names only (ns3:: / Storm 3 strings). No cross-game names.
 * Generated 2026-10-19 by cmn28-s3 pre-decompile task.
 *
 * Qualifying classes (>=3 methods with field evidence):
 *   mmFileSys_Impl, mmGPUDevice_NX
 *
 * Classes with no instance state (0 fields from state_surface across all seeds):
 *   mmFilePath — 3 methods (GetDir, GetNameNoExt, Format), static/utility
 *   mmFileSys — 6 methods (Initialize, GetPlatformPath, Find, FromOSPath, AddDrive, Exist), pure virtual interface
 *   mmGPUBufferWrapper — 4 methods (CreateBuffer x3, Lock), opaque wrapper
 *   mmGPUResourceFactory — 6 methods (CreateTexture, CreateSamplerEntity, CreateComputeShader, CreateBuffer, CreateConstantBuffer, CreateRenderTarget), stateless factory
 *
 * Classes absent from s3 build or with <3 methods:
 *   mmFilePathParser — 1 method only
 *   mmFilePathParseResult — 1 method only
 *   mmFileSys_Android — 1 method only (Android-specific, minimal in PC build)
 *   mmGPURenderState — 2 methods only
 *   mmGPURenderStateBlend_DX11 — 1 method only
 *   mmGPUResource_DX11 — 1 method only
 */
#ifndef CMN28_S3_H
#define CMN28_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---------------------------------------------------------------------------
 * mmFileSys_Impl — platform file-system implementation
 * Size: unknown, >= 0x50 (ctor zero-inits through param_1[9] = offset 0x48; next qword boundary = 0x50)
 * Proven size: no operator new or allocator size found in s3 for this class.
 * Methods: mmFileSys_Impl (0x704220), ~mmFileSys_Impl (0x12FFB0), AddDrive (0x130020)
 * Vtable: PTR_FUN_1409e6e70
 * --------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) mmFileSys_Impl {
    void     *vtable;      /* 0x00 — PTR_FUN_1409e6e70 */
    uint64_t  _field_08;   /* 0x08 — param_1[1], zeroed in ctor */
    uint64_t  _field_10;   /* 0x10 — param_1[2], zeroed in ctor */
    uint64_t  _field_18;   /* 0x18 — param_1[3], zeroed in ctor */
    uint64_t  _field_20;   /* 0x20 — param_1[4], zeroed in ctor */
    uint32_t  _field_28;   /* 0x28 — *(undefined4*)(param_1+5), zeroed as u32 in ctor */
    uint8_t   flag_2C;     /* 0x2C — byte write in ctor, likely bool */
    uint8_t   _pad_2D[3];  /* 0x2D — alignment padding */
    uint64_t  _field_30;   /* 0x30 — param_1[6], zeroed in ctor */
    uint32_t  _field_38;   /* 0x38 — *(undefined4*)(param_1+7), zeroed as u32 in ctor */
    uint8_t   flag_3C;     /* 0x3C — byte write in ctor, likely bool */
    uint8_t   _pad_3D[3];  /* 0x3D — alignment padding */
    uint64_t  _field_40;   /* 0x40 — param_1[8], zeroed in ctor */
    uint64_t  _field_48;   /* 0x48 — param_1[9], zeroed in ctor */
} mmFileSys_Impl;

_Static_assert(offsetof(mmFileSys_Impl, vtable)   == 0x00, "mmFileSys_Impl.vtable");
_Static_assert(offsetof(mmFileSys_Impl, _field_08) == 0x08, "mmFileSys_Impl._field_08");
_Static_assert(offsetof(mmFileSys_Impl, _field_10) == 0x10, "mmFileSys_Impl._field_10");
_Static_assert(offsetof(mmFileSys_Impl, _field_18) == 0x18, "mmFileSys_Impl._field_18");
_Static_assert(offsetof(mmFileSys_Impl, _field_20) == 0x20, "mmFileSys_Impl._field_20");
_Static_assert(offsetof(mmFileSys_Impl, _field_28) == 0x28, "mmFileSys_Impl._field_28");
_Static_assert(offsetof(mmFileSys_Impl, flag_2C)   == 0x2C, "mmFileSys_Impl.flag_2C");
_Static_assert(offsetof(mmFileSys_Impl, _field_30) == 0x30, "mmFileSys_Impl._field_30");
_Static_assert(offsetof(mmFileSys_Impl, _field_38) == 0x38, "mmFileSys_Impl._field_38");
_Static_assert(offsetof(mmFileSys_Impl, flag_3C)   == 0x3C, "mmFileSys_Impl.flag_3C");
_Static_assert(offsetof(mmFileSys_Impl, _field_40) == 0x40, "mmFileSys_Impl._field_40");
_Static_assert(offsetof(mmFileSys_Impl, _field_48) == 0x48, "mmFileSys_Impl._field_48");
/* size unknown, >= 0x50 — no sizeof assert */

/* ---------------------------------------------------------------------------
 * mmGPUDevice_NX — GPU device abstraction (DX11 backend)
 * Size: unknown, >= 0x38 (last observed field at 0x34 + 4 bytes)
 * Proven size: no operator new for mmGPUDevice_NX itself found in s3.
 *   Allocation sizes in InitializeRenderSystem (0x1390B0) are for composed sub-objects:
 *     0x1A0 — DX11 device object (FUN_14014ccc0)
 *     0x68  — shader effect compiler (mmShaderEffectCompiler ctor)
 *     0x138 — render system object (FUN_140138900, vtable PTR_FUN_140a1c8b8)
 * Methods: InitializeRenderSystem (0x1390B0, 0x666400), Initialize (0x138CA0),
 *          Finalize (0x138D00), InterpretSystemMessage (0x138E60),
 *          ~mmGPUDevice_NX (0x138C50)
 * Vtables: PTR_FUN_140a1c8d8 (dtor), PTR_FUN_140a1c860 (base after dtor)
 * --------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) mmGPUDevice_NX {
    void    *vtable;              /* 0x00 — implicit C++ vptr; dtor sets PTR_FUN_140a1c8d8 then PTR_FUN_140a1c860 */
    void    *dx11_device;         /* 0x08 — param_1[1], FUN_14014ccc0 result; freed via vfunc in Finalize */
    void    *shader_effect_compiler; /* 0x10 — param_1[2], mmShaderEffectCompiler ctor result */
    void    *render_system;       /* 0x18 — param_1[3], vtable PTR_FUN_140a1c8b8; freed via vfunc in Finalize */
    void    *hwnd;                /* 0x20 — param_1[4], HWND for MessageBoxW/DestroyWindow */
    void    *hinstance;           /* 0x28 — HINSTANCE for UnregisterClassW("MME_Sample") */
    int32_t  display_mode_flag;   /* 0x30 — checked == 1 in Finalize before ChangeDisplaySettingsW */
    int32_t  adapter_index;       /* 0x34 — written from *param_2 on success path in InitializeRenderSystem */
    /* size unknown, >= 0x38 — no sizeof assert */
} mmGPUDevice_NX;

_Static_assert(offsetof(mmGPUDevice_NX, vtable)                == 0x00, "mmGPUDevice_NX.vtable");
_Static_assert(offsetof(mmGPUDevice_NX, dx11_device)           == 0x08, "mmGPUDevice_NX.dx11_device");
_Static_assert(offsetof(mmGPUDevice_NX, shader_effect_compiler)== 0x10, "mmGPUDevice_NX.shader_effect_compiler");
_Static_assert(offsetof(mmGPUDevice_NX, render_system)         == 0x18, "mmGPUDevice_NX.render_system");
_Static_assert(offsetof(mmGPUDevice_NX, hwnd)                  == 0x20, "mmGPUDevice_NX.hwnd");
_Static_assert(offsetof(mmGPUDevice_NX, hinstance)             == 0x28, "mmGPUDevice_NX.hinstance");
_Static_assert(offsetof(mmGPUDevice_NX, display_mode_flag)     == 0x30, "mmGPUDevice_NX.display_mode_flag");
_Static_assert(offsetof(mmGPUDevice_NX, adapter_index)         == 0x34, "mmGPUDevice_NX.adapter_index");
/* size unknown, >= 0x38 — no sizeof assert */

/* ---------------------------------------------------------------------------
 * mmFilePath — no instance state
 * Evidence: state_surface returned 0 fields across 3 seed methods
 *   (GetDir 0x12FCC0, GetNameNoExt 0x12FDB0, Format 0x1305F0).
 * All methods operate on stack/temp data; no this-pointer member accesses.
 * --------------------------------------------------------------------------- */
/* no instance state — mmFilePath is a static/utility class */

/* ---------------------------------------------------------------------------
 * mmFileSys — no instance state
 * Evidence: state_surface returned 0 fields across 6 seed methods
 *   (Initialize 0x12E4D0, GetPlatformPath 0x130430, Find 0x130820,
 *    FromOSPath 0x130800, AddDrive 0x1307C0, Exist 0x1307E0).
 * Pure virtual interface delegating to mmFileSys_Impl.
 * --------------------------------------------------------------------------- */
/* no instance state — mmFileSys is a pure virtual interface */

/* ---------------------------------------------------------------------------
 * mmGPUBufferWrapper — no instance state
 * Evidence: state_surface returned 0 fields across 4 seed methods
 *   (CreateBuffer 0x147A40/0x147950/0x13A400, Lock 0x147B50).
 * Warning: Lock uses byte-cast accesses only (unknown element size).
 * Opaque wrapper around GPU buffer handles.
 * --------------------------------------------------------------------------- */
/* no instance state — mmGPUBufferWrapper is an opaque wrapper */

/* ---------------------------------------------------------------------------
 * mmGPUResourceFactory — no instance state
 * Evidence: state_surface returned 0 fields across 6 seed methods
 *   (CreateTexture 0x140590, CreateSamplerEntity 0x140370,
 *    CreateComputeShader 0x146020, CreateBuffer 0x147C80,
 *    CreateConstantBuffer 0x142770, CreateRenderTarget 0x140010).
 * Stateless factory; all methods take external params, store nothing on this.
 * --------------------------------------------------------------------------- */
/* no instance state — mmGPUResourceFactory is a stateless factory */

#endif /* CMN28_S3_H */