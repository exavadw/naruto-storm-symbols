/* cmn29.h — struct group cmn29 for NARUTO STORM 1 PC (NSUNS1.exe, s1)
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
 * Evidence: state_surface (7 seeds), CreateTexture1D/2D, RecreateTarget
 * Vtable: at offset 0x00 (vfunc calls at *param_1+0x28, *param_1+0x30 in RecreateTarget)
 * Size: unknown, >= 0x188 (last proven access at 0x180, 8-byte read)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUTexture_DX11 {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr; vfuncs at +0x28, +0x30 */
    /* 0x08 */ uint8_t _pad_08[0x34];          /* gap to first proven field */
    /* 0x3C */ int32_t field_3C;               /* rw, written in CreateTexture1D/2D/RecreateTarget */
    /* 0x40 */ uint8_t _pad_40[4];             /* gap */
    /* 0x44 */ int32_t field_44;               /* w, written in CreateTexture1D/2D */
    /* 0x48 */ uint8_t _pad_48[4];             /* gap */
    /* 0x4C */ int32_t field_4C;               /* r, read in RecreateTarget */
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
 * Evidence: symbolized decompile of Create (0x126D40), LoadFromCompiledMemory (0x1273A0)
 * Vtable: at offset 0x00 (inferred from class pattern)
 * Size: unknown, >= 0xC8 (last proven access at 0xC0, 8-byte ptr)
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUVertexShader_DX11 {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr */
    /* 0x08 */ uint8_t _pad_08[0x40];          /* gap to 0x48 */
    /* 0x48 */ uint8_t name_string[0x50];      /* eastl::basic_string (seen in LoadFromCompiledMemory) */
    /* 0x98 */ uint64_t device_ptr;            /* ptr to ID3D11Device or wrapper (used in Create) */
    /* 0xA0 */ uint64_t shader_blob;           /* ptr to compiled shader blob */
    /* 0xA8 */ uint64_t input_layout_0;        /* ptr to ID3D11InputLayout (slot 0) */
    /* 0xB0 */ uint64_t input_layout_1;        /* ptr to ID3D11InputLayout (slot 1) */
    /* 0xB8 */ uint64_t semantic_list_begin;   /* ptr, semantic list begin */
    /* 0xC0 */ uint64_t semantic_list_end;     /* ptr, semantic list end */
    /* size unknown, >= 0xC8 */
} mmGPUVertexShader_DX11;

static_assert(offsetof(mmGPUVertexShader_DX11, vtable)            == 0x00, "mmGPUVertexShader_DX11.vtable");
static_assert(offsetof(mmGPUVertexShader_DX11, name_string)       == 0x48, "mmGPUVertexShader_DX11.name_string");
static_assert(offsetof(mmGPUVertexShader_DX11, device_ptr)        == 0x98, "mmGPUVertexShader_DX11.device_ptr");
static_assert(offsetof(mmGPUVertexShader_DX11, shader_blob)       == 0xA0, "mmGPUVertexShader_DX11.shader_blob");
static_assert(offsetof(mmGPUVertexShader_DX11, input_layout_0)    == 0xA8, "mmGPUVertexShader_DX11.input_layout_0");
static_assert(offsetof(mmGPUVertexShader_DX11, input_layout_1)    == 0xB0, "mmGPUVertexShader_DX11.input_layout_1");
static_assert(offsetof(mmGPUVertexShader_DX11, semantic_list_begin)== 0xB8, "mmGPUVertexShader_DX11.semantic_list_begin");
static_assert(offsetof(mmGPUVertexShader_DX11, semantic_list_end) == 0xC0, "mmGPUVertexShader_DX11.semantic_list_end");

/* =========================================================================
 * mmGPUTexture_NX
 * Evidence: state_surface (3 seeds, only 1 field found)
 * Only 1 proven field — minimal reconstruction.
 * Size: unknown, >= 0x50
 * ========================================================================= */
typedef struct __attribute__((packed)) mmGPUTexture_NX {
    /* 0x00 */ uint8_t vtable[8];              /* vtable ptr (inferred) */
    /* 0x08 */ uint8_t _pad_08[0x44];          /* gap */
    /* 0x4C */ int32_t field_4C;               /* w, written in CreateTextureFromImage */
    /* size unknown, >= 0x50 */
} mmGPUTexture_NX;

static_assert(offsetof(mmGPUTexture_NX, vtable)  == 0x00, "mmGPUTexture_NX.vtable");
static_assert(offsetof(mmGPUTexture_NX, field_4C) == 0x4C, "mmGPUTexture_NX.field_4C");

/* =========================================================================
 * mmIdManager: no instance state
 * Evidence: state_surface with 3 seeds returned 0 fields, 0 param_1 accesses.
 *   RegisterIdString @ RVA 0x1058D0 — 0 accesses
 *   GetIdString      @ RVA 0x105B60 — 0 accesses
 *   Finalize         @ RVA 0xAE684  — 0 accesses
 * All methods operate on global DAT_140b8d108 (singleton pattern).
 * Not reconstructable as an instance struct. INFERRED from static analysis.
 * ========================================================================= */

#endif /* CMN29_H */