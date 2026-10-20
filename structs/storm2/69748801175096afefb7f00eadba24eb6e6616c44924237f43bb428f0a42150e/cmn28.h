/* cmn28.h — Storm 2 (NSUNS2.exe, s2) common engine struct definitions
 * Build: s2 / NSUNS2.exe-abf2b6 / sha 697488011750 / image base 0x140000000
 * All offsets INFERRED from static decompilation of PC x64 binary.
 * Own-game names only (ns2:: / Storm 2 strings). No cross-game names.
 * Generated 2026-10-19 by cmn28-s2 pre-decompile task.
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
 * Classes absent from s2 build or with <3 methods:
 *   mmFilePathParser — not found in s2 symbol table
 *   mmFilePathParseResult — not found in s2 symbol table
 *   mmFileSys_Android — Android-only, absent from PC build
 *   mmGPURenderState — state_surface not yet run (deferred)
 *   mmGPURenderStateBlend_DX11 — state_surface not yet run (deferred)
 *   mmGPUResource_DX11 — state_surface not yet run (deferred)
 */
#ifndef CMN28_S2_H
#define CMN28_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---------------------------------------------------------------------------
 * mmFileSys_Impl — platform file-system implementation
 * Size: >= 0x50 (from ctor zero-init span up to param_1[9] = offset 0x48, next qword = 0x50)
 * Proven size: unknown, >= 0x50 (no operator new size found in s2; s1 used 0x48)
 * Methods: mmFileSys_Impl (0x5F8630), ~mmFileSys_Impl (0x155AE0), AddDrive (0x155B50)
 * Vtable: PTR_FUN_1408983d8
 * --------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) mmFileSys_Impl {
    void     *vtable;      /* 0x00 — PTR_FUN_1408983d8 */
    uint64_t  _field_08;   /* 0x08 — zeroed in ctor */
    uint64_t  _field_10;   /* 0x10 — zeroed in ctor */
    uint64_t  _field_18;   /* 0x18 — zeroed in ctor */
    uint64_t  _field_20;   /* 0x20 — zeroed in ctor */
    uint32_t  _field_28;   /* 0x28 — zeroed as u32 in ctor */
    uint8_t   flag_2C;     /* 0x2C — byte write in ctor, likely bool */
    uint8_t   _pad_2D[3];  /* 0x2D — alignment padding */
    uint64_t  _field_30;   /* 0x30 — zeroed in ctor */
    uint32_t  _field_38;   /* 0x38 — zeroed as u32 in ctor */
    uint8_t   flag_3C;     /* 0x3C — byte write in ctor, likely bool */
    uint8_t   _pad_3D[3];  /* 0x3D — alignment padding */
    uint64_t  _field_40;   /* 0x40 — zeroed in ctor */
    uint64_t  _field_48;   /* 0x48 — zeroed in ctor */
} mmFileSys_Impl;

_Static_assert(offsetof(mmFileSys_Impl, vtable)  == 0x00, "mmFileSys_Impl.vtable");
_Static_assert(offsetof(mmFileSys_Impl, _field_08) == 0x08, "mmFileSys_Impl._field_08");
_Static_assert(offsetof(mmFileSys_Impl, _field_10) == 0x10, "mmFileSys_Impl._field_10");
_Static_assert(offsetof(mmFileSys_Impl, _field_18) == 0x18, "mmFileSys_Impl._field_18");
_Static_assert(offsetof(mmFileSys_Impl, _field_20) == 0x20, "mmFileSys_Impl._field_20");
_Static_assert(offsetof(mmFileSys_Impl, _field_28) == 0x28, "mmFileSys_Impl._field_28");
_Static_assert(offsetof(mmFileSys_Impl, flag_2C)  == 0x2C, "mmFileSys_Impl.flag_2C");
_Static_assert(offsetof(mmFileSys_Impl, _field_30) == 0x30, "mmFileSys_Impl._field_30");
_Static_assert(offsetof(mmFileSys_Impl, _field_38) == 0x38, "mmFileSys_Impl._field_38");
_Static_assert(offsetof(mmFileSys_Impl, flag_3C)  == 0x3C, "mmFileSys_Impl.flag_3C");
_Static_assert(offsetof(mmFileSys_Impl, _field_40) == 0x40, "mmFileSys_Impl._field_40");
_Static_assert(offsetof(mmFileSys_Impl, _field_48) == 0x48, "mmFileSys_Impl._field_48");
/* size unknown, >= 0x50 — no sizeof assert */

/* ---------------------------------------------------------------------------
 * mmGPUDevice_NX — GPU device abstraction (DX11 backend)
 * Size: >= 0x38 (last observed field at 0x34 + 4 bytes)
 * Proven size: unknown, >= 0x38 (Finalize/InterpretSystemMessage showed byte-cast only;
 *   s1 used 0x1A0 from _aligned_malloc but s2 allocation sizes differ)
 * Allocation sizes observed in s2 InitializeRenderSystem (0x15F180):
 *   0x1A0 (device object via FUN_140173060)
 *   0x68  (swap chain via FUN_14016e600)
 *   0x138 (render system via FUN_14015e9d0)
 * These are composed objects, NOT mmGPUDevice_NX itself.
 * Methods: InitializeRenderSystem (0x15F180/0x560DB0), Initialize (0x15ED70),
 *          Finalize (0x15EDD0), InterpretSystemMessage (0x15EF30),
 *          ~mmGPUDevice_NX (0x15ED20)
 * --------------------------------------------------------------------------- */
typedef struct __attribute__((packed)) mmGPUDevice_NX {
    void    *vtable;              /* 0x00 — implicit C++ vptr */
    void    *dx11_device;         /* 0x08 — param_1[1], FUN_140173060 result */
    void    *swap_chain;          /* 0x10 — param_1[2], FUN_14016e600 result */
    void    *render_system;       /* 0x18 — param_1[3], vtable PTR_FUN_1408cf2e0 */
    void    *hwnd;                /* 0x20 — param_1[4], HWND for MessageBoxW */
    uint8_t  _pad_28[12];         /* 0x28 — gap: unobserved */
    int32_t  adapter_index;       /* 0x34 — written from *param_2 on success path */
    /* size unknown, >= 0x38 — no sizeof assert */
} mmGPUDevice_NX;

_Static_assert(offsetof(mmGPUDevice_NX, vtable)         == 0x00, "mmGPUDevice_NX.vtable");
_Static_assert(offsetof(mmGPUDevice_NX, dx11_device)    == 0x08, "mmGPUDevice_NX.dx11_device");
_Static_assert(offsetof(mmGPUDevice_NX, swap_chain)     == 0x10, "mmGPUDevice_NX.swap_chain");
_Static_assert(offsetof(mmGPUDevice_NX, render_system)  == 0x18, "mmGPUDevice_NX.render_system");
_Static_assert(offsetof(mmGPUDevice_NX, hwnd)           == 0x20, "mmGPUDevice_NX.hwnd");
_Static_assert(offsetof(mmGPUDevice_NX, adapter_index)  == 0x34, "mmGPUDevice_NX.adapter_index");
/* size unknown, >= 0x38 — no sizeof assert */

/* ---------------------------------------------------------------------------
 * mmFilePath — no instance state
 * Evidence: state_surface returned 0 fields across 3 seed methods
 *   (GetDir 0x1557E0, GetNameNoExt 0x1558D0, Format 0x156120).
 * All methods operate on stack/temp data; no this-pointer member accesses.
 * --------------------------------------------------------------------------- */
/* no instance state — mmFilePath is a static/utility class */

/* ---------------------------------------------------------------------------
 * mmFileSys — no instance state
 * Evidence: state_surface returned 0 fields across 6 seed methods
 *   (Initialize 0x158C90, GetPlatformPath 0x155F60, Find 0x156350,
 *    FromOSPath 0x156330, AddDrive 0x1562F0, Exist 0x156310).
 * Pure virtual interface delegating to mmFileSys_Impl.
 * --------------------------------------------------------------------------- */
/* no instance state — mmFileSys is a pure virtual interface */

/* ---------------------------------------------------------------------------
 * mmGPUBufferWrapper — no instance state
 * Evidence: state_surface returned 0 fields across 4 seed methods
 *   (CreateBuffer 0x16DDE0/0x16DCF0/0x1607A0, Lock 0x16DEF0).
 * Warning: Lock uses byte-cast accesses only (unknown element size).
 * Opaque wrapper around GPU buffer handles.
 * --------------------------------------------------------------------------- */
/* no instance state — mmGPUBufferWrapper is an opaque wrapper */

/* ---------------------------------------------------------------------------
 * mmGPUResourceFactory — no instance state
 * Evidence: state_surface returned 0 fields across 6 seed methods
 *   (CreateTexture 0x166930, CreateSamplerEntity 0x166710,
 *    CreateComputeShader 0x16C3C0, CreateBuffer 0x16E020,
 *    CreateConstantBuffer 0x168B10, CreateRenderTarget 0x1663B0).
 * Stateless factory; all methods take external params, store nothing on this.
 * --------------------------------------------------------------------------- */
/* no instance state — mmGPUResourceFactory is a stateless factory */

#endif /* CMN28_S2_H */