/* cmn29.h — struct group cmn29 for NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, s3)
 * Generated 2026-10-19. Repaired 2026-10-19. All layouts INFERRED from static analysis.
 * Sizes are unproven unless noted; no sizeof asserts on incomplete structs.
 */
#ifndef CMN29_H
#define CMN29_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmGPUTexture_DX11
 * Evidence: state_surface (8 seeds), CreateTexture1D/2D/3D, RecreateTarget
 * Vtable: at offset 0x00 (vfunc calls at *param_1+0x28, *param_1+0x30 in RecreateTarget)
 * Size: unknown, >= 0x188 (last proven access at 0x180, 8-byte read)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUTexture_DX11 {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr; vfuncs at +0x28, +0x30 */
    /* 0x08 */ uint8_t _pad_08[0x34];          /* gap to first proven field */
    /* 0x3C */ int32_t field_3C;               /* rw, written in CreateTexture1D/2D/3D/RecreateTarget */
    /* 0x40 */ uint8_t _pad_40[4];             /* gap */
    /* 0x44 */ int32_t field_44;               /* w, written in CreateTexture1D/2D/3D */
    /* 0x48 */ uint8_t _pad_48[4];             /* gap */
    /* 0x4C */ int32_t field_4C;               /* rw, read/written in CreateTextureFromResource/RecreateTarget */
    /* 0x50 */ uint8_t _pad_50[0x10];          /* gap */
    /* 0x60 */ uint64_t field_60;              /* r, ID3D11Resource* or similar COM ptr */
    /* 0x68 */ uint64_t field_68;              /* r, likely ID3D11ShaderResourceView* */
    /* 0x70 */ uint64_t field_70;              /* r, pointer-sized (size not proven as 8) */
    /* 0x78 */ uint8_t _pad_78[8];             /* gap */
    /* 0x80 */ uint64_t field_80;              /* r, read in RecreateTarget */
    /* 0x88 */ uint8_t _pad_88[0xB8];          /* gap to 0x140 */
    /* 0x140 */ uint64_t field_140;            /* r, vfunc-related */
    /* 0x148 */ uint8_t _pad_148[0x38];        /* gap to 0x180 */
    /* 0x180 */ uint64_t field_180;            /* r, vfunc-related */
    /* size unknown, >= 0x188 */
} mmGPUTexture_DX11;

static_assert(offsetof(mmGPUTexture_DX11, vtable)   == 0x00, "mmGPUTexture_DX11.vtable");
static_assert(offsetof(mmGPUTexture_DX11, field_3C)  == 0x3C, "mmGPUTexture_DX11.field_3C");
static_assert(offsetof(mmGPUTexture_DX11, field_44)  == 0x44, "mmGPUTexture_DX11.field_44");
static_assert(offsetof(mmGPUTexture_DX11, field_4C)  == 0x4C, "mmGPUTexture_DX11.field_4C");
static_assert(offsetof(mmGPUTexture_DX11, field_60)  == 0x60, "mmGPUTexture_DX11.field_60");
static_assert(offsetof(mmGPUTexture_DX11, field_68)  == 0x68, "mmGPUTexture_DX11.field_68");
static_assert(offsetof(mmGPUTexture_DX11, field_70)  == 0x70, "mmGPUTexture_DX11.field_70");
static_assert(offsetof(mmGPUTexture_DX11, field_80)  == 0x80, "mmGPUTexture_DX11.field_80");
static_assert(offsetof(mmGPUTexture_DX11, field_140) == 0x140, "mmGPUTexture_DX11.field_140");
static_assert(offsetof(mmGPUTexture_DX11, field_180) == 0x180, "mmGPUTexture_DX11.field_180");

/* =========================================================================
 * mmGPUVertexShader_DX11
 * Evidence: symbolized decompile of Create (0x154DD0), LoadFromCompiledMemory (0x155430),
 *           CompileFromMemory (0x1550F0), CreateVertexLayout (0x154CD0)
 * Vtable: at offset 0x00 (inferred from class pattern)
 * Size: unknown, >= 0xC8 (last proven access at 0xC0, 8-byte ptr)
 * Note: field at 0x70 found in CompileFromMemory (eastl::string append), matches s2 layout
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUVertexShader_DX11 {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr */
    /* 0x08 */ uint8_t _pad_08[0x40];          /* gap to 0x48 */
    /* 0x48 */ uint8_t name_string[0x28];      /* eastl::basic_string (seen in LoadFromCompiledMemory) */
    /* 0x70 */ uint8_t profile_string[0x28];   /* eastl::basic_string (seen in CompileFromMemory) */
    /* 0x98 */ uint64_t device_ptr;            /* ptr to ID3D11Device or wrapper (used in Create/CreateVertexLayout) */
    /* 0xA0 */ uint64_t shader_blob;           /* ptr to compiled shader blob */
    /* 0xA8 */ uint64_t input_layout_0;        /* ptr to ID3D11InputLayout (slot 0) */
    /* 0xB0 */ uint64_t input_layout_1;        /* ptr to ID3D11InputLayout (slot 1) */
    /* 0xB8 */ uint64_t semantic_list_begin;   /* ptr, semantic list begin */
    /* 0xC0 */ uint64_t semantic_list_end;     /* ptr, semantic list end */
    /* size unknown, >= 0xC8 */
} mmGPUVertexShader_DX11;

static_assert(offsetof(mmGPUVertexShader_DX11, vtable)             == 0x00, "mmGPUVertexShader_DX11.vtable");
static_assert(offsetof(mmGPUVertexShader_DX11, name_string)        == 0x48, "mmGPUVertexShader_DX11.name_string");
static_assert(offsetof(mmGPUVertexShader_DX11, profile_string)     == 0x70, "mmGPUVertexShader_DX11.profile_string");
static_assert(offsetof(mmGPUVertexShader_DX11, device_ptr)         == 0x98, "mmGPUVertexShader_DX11.device_ptr");
static_assert(offsetof(mmGPUVertexShader_DX11, shader_blob)        == 0xA0, "mmGPUVertexShader_DX11.shader_blob");
static_assert(offsetof(mmGPUVertexShader_DX11, input_layout_0)     == 0xA8, "mmGPUVertexShader_DX11.input_layout_0");
static_assert(offsetof(mmGPUVertexShader_DX11, input_layout_1)     == 0xB0, "mmGPUVertexShader_DX11.input_layout_1");
static_assert(offsetof(mmGPUVertexShader_DX11, semantic_list_begin)== 0xB8, "mmGPUVertexShader_DX11.semantic_list_begin");
static_assert(offsetof(mmGPUVertexShader_DX11, semantic_list_end)  == 0xC0, "mmGPUVertexShader_DX11.semantic_list_end");

/* =========================================================================
 * mmMatrix4
 * Evidence: state_surface (3 seeds: Transpose, operator+=, operator-=)
 * Vtable: none (value type, no virtual calls)
 * Size: unknown, >= 0x40 (last proven access at 0x3C, 4-byte float)
 * Note: 4x4 float matrix stored row-major; fields at 0x2C-0x3C are row 3
 *       (rows 0-2 at 0x00-0x2B not accessed by these methods but implied)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmMatrix4 {
    /* 0x00 */ float m[4][4];                  /* 4x4 float matrix, row-major; m[3][0..3] at 0x30-0x3C proven */
    /* size unknown, >= 0x40 */
} mmMatrix4;

static_assert(offsetof(mmMatrix4, m) == 0x00, "mmMatrix4.m");

#endif /* CMN29_H */