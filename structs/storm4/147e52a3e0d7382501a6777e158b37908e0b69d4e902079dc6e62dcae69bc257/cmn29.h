/* cmn29.h — struct group cmn29 for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, s4)
 * Generated 2026-10-19. All layouts INFERRED from static analysis.
 * Sizes are unproven unless noted; no sizeof asserts on incomplete structs.
 */
#ifndef CMN29_H
#define CMN29_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmGPUTexture_DX11
 * Evidence: state_surface (5 seeds), CreateTexture1D/2D/3D
 * Vtable: at offset 0x00 (inferred from class pattern; s3 had vfunc calls at +0x28/+0x30)
 * Size: unknown, >= 0x78 (last proven access at 0x70, pointer-sized read)
 * Note: s4 state_surface found fewer fields than s3 (no RecreateTarget in s4 symbols).
 *       Fields 0x3C, 0x44 confirmed; 0x60/0x68/0x70 from pointer arithmetic.
 *       s3 fields at 0x4C, 0x80, 0x140, 0x180 not re-verified in s4 — omitted.
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUTexture_DX11 {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr */
    /* 0x08 */ uint8_t _pad_08[0x34];          /* gap to first proven field */
    /* 0x3C */ int32_t field_3C;               /* w, written in CreateTexture1D/2D/3D */
    /* 0x40 */ uint8_t _pad_40[4];             /* gap */
    /* 0x44 */ int32_t field_44;               /* w, written in CreateTexture1D/2D/3D */
    /* 0x48 */ uint8_t _pad_48[0x18];          /* gap to 0x60 */
    /* 0x60 */ uint64_t field_60;              /* r, ID3D11Resource* or similar COM ptr */
    /* 0x68 */ uint64_t field_68;              /* r, likely ID3D11ShaderResourceView* */
    /* 0x70 */ uint64_t field_70;              /* r, pointer-sized (from param_1+0xe arithmetic) */
    /* size unknown, >= 0x78 */
} mmGPUTexture_DX11;

static_assert(offsetof(mmGPUTexture_DX11, vtable)   == 0x00, "mmGPUTexture_DX11.vtable");
static_assert(offsetof(mmGPUTexture_DX11, field_3C)  == 0x3C, "mmGPUTexture_DX11.field_3C");
static_assert(offsetof(mmGPUTexture_DX11, field_44)  == 0x44, "mmGPUTexture_DX11.field_44");
static_assert(offsetof(mmGPUTexture_DX11, field_60)  == 0x60, "mmGPUTexture_DX11.field_60");
static_assert(offsetof(mmGPUTexture_DX11, field_68)  == 0x68, "mmGPUTexture_DX11.field_68");
static_assert(offsetof(mmGPUTexture_DX11, field_70)  == 0x70, "mmGPUTexture_DX11.field_70");

/* =========================================================================
 * mmGPUVertexShader_DX11
 * Evidence: symbolized decompile of Create (0x1A4C70), LoadFromCompiledMemory (0x1A52D0),
 *           CompileFromMemory (0x1A4F90), CreateVertexLayout (0x1A4B70)
 * Vtable: at offset 0x00 (inferred from class pattern)
 * Size: unknown, >= 0xC8 (last proven access at 0xC0, 8-byte ptr)
 * Note: layout matches s3 exactly (same offsets for all 8 data fields)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUVertexShader_DX11 {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr */
    /* 0x08 */ uint8_t _pad_08[0x40];          /* gap to 0x48 */
    /* 0x48 */ uint8_t name_string[0x28];      /* eastl::basic_string (seen in LoadFromCompiledMemory) */
    /* 0x70 */ uint8_t profile_string[0x28];   /* eastl::basic_string (seen in CompileFromMemory) */
    /* 0x98 */ uint64_t device_ptr;            /* ptr to ID3D11Device or wrapper (used in Create) */
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
 * Evidence: state_surface (5 seeds: Transpose, operator*, operator+=, MakeIdentity, operator*=)
 * Vtable: none (value type, no virtual calls)
 * Size: unknown, >= 0x40 (float[4][4] implied; last proven access at 0x3C)
 * Note: 4x4 float matrix stored row-major; fields at 0x2C-0x3C are row 3
 *       (rows 0-2 at 0x00-0x2B implied by matrix structure but not directly
 *        accessed by seed methods except through full-row operations)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmMatrix4 {
    /* 0x00 */ float m[4][4];                  /* 4x4 float matrix, row-major; m[3][0..3] at 0x30-0x3C proven */
    /* size unknown, >= 0x40 */
} mmMatrix4;

static_assert(offsetof(mmMatrix4, m) == 0x00, "mmMatrix4.m");

#endif /* CMN29_H */