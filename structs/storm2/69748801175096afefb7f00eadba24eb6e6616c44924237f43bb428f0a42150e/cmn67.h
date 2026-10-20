/* cmn67.h — NARUTO STORM 2 (s2) struct group cmn67
 * Reconstructed from decompiled NSUNS2.exe (build s2, image base 0x140000000).
 * All sizes proven from game code (LoadTh / allocator size arg) where possible.
 * Static fields are INFERRED unless confirmed by replay trace.
 * OWN-GAME NAMES only (ns2:: / Storm 2 strings).
 * PC OFFSETS ONLY — no Switch arm64 offsets copied.
 *
 * Compile-check: gcc -fsyntax-only -x c -std=c11 cmn67.h
 */
#ifndef CMN67_H
#define CMN67_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── Common types ─────────────────────────────────────────────── */
typedef struct { float x, y, z; } nucc_Vector3;
typedef struct { float x, y, z, w; } nucc_Vector4;
typedef struct { float m[4][4]; } nucc_Matrix44;

/* std::vector<T*> layout: begin(+0x00), end(+0x08), capacity_end(+0x10) */
typedef struct {
    void *begin;      /* +0x00 */
    void *current;    /* +0x08 */
    void *cap_end;    /* +0x10 */
} nucc_StdVector;

/* Nucc::Memory::BlockAllocator — opaque, 8 bytes observed */
typedef struct {
    uint64_t block_id; /* +0x00 */
} nucc_BlockAllocator;

/* ─── nuccRenderTextureManager ───────────────────────────────────
 * Size: 0x38 (proven: LoadTh(0x38, ...) in CreateInstance)
 * Singleton: DAT_140a9fc30
 * Vtable: not observed (singleton access pattern)
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable_or_pad;   /* +0x00 (INFERRED) */
    nucc_StdVector render_textures; /* +0x08 (PRES: push_back in AddRenderTextureNormal) */
    uint8_t pad_20[0x18];     /* +0x20 (UNKNOWN) */
} nucc_RenderTextureManager;
#pragma pack(pop)

static_assert(sizeof(nucc_RenderTextureManager) == 0x38, "RenderTextureManager size");
static_assert(offsetof(nucc_RenderTextureManager, vtable_or_pad) == 0x00, "RTM vtable_or_pad offset");
static_assert(offsetof(nucc_RenderTextureManager, render_textures) == 0x08, "RTM vector offset");
static_assert(offsetof(nucc_RenderTextureManager, pad_20) == 0x20, "RTM pad_20 offset");

/* ─── nuccReplacePathManager ─────────────────────────────────────
 * Inner object size: 0x70 (proven: LoadTh(0x70, ...) in AddReplacePathImpl)
 * Outer manager size unproven; inner entry is 0x70.
 * Two BlockAllocator ctors at lVar6 and lVar6+0x38 within inner object.
 * Vtable: not observed
 */
#pragma pack(push, 1)
typedef struct {
    uint8_t pad_00[0x50];     /* +0x00 (UNKNOWN, includes crit section) */
    nucc_StdVector replace_params; /* +0x50 (PRES: clear/push in ClearReplacePath/AddReplacePathImpl) */
    nucc_BlockAllocator allocator; /* +0x68 (PRES: GetBlockId in ClearReplacePath) */
} nucc_ReplacePathManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ReplacePathManager) == 0x70, "ReplacePathManager size");
static_assert(offsetof(nucc_ReplacePathManager, pad_00) == 0x00, "RPM pad_00 offset");
static_assert(offsetof(nucc_ReplacePathManager, replace_params) == 0x50, "RPM vector offset");
static_assert(offsetof(nucc_ReplacePathManager, allocator) == 0x68, "RPM allocator offset");

/* ─── nuccResolution ─────────────────────────────────────────────
 * Size: unknown, >= 0x2C (no LoadTh in s2; last proven field sprite_y at +0x28)
 * Vtable: PTR_FUN_14089c1b8 (PRES: set in ctor)
 * BlockAllocator at +0x10 (PRES: ctor calls BlockAllocator(param_1+2))
 *
 * s2 field offsets differ from s1: viewport_x at +0x08 (was +0x0C in s1).
 * FUN_140585190 accesses param_1+0x10 (BlockAllocator) and param_1+0x18.
 * No sizeof assert emitted due to unproven total size.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;          /* +0x00 (PRES: PTR_FUN_14089c1b8) */
    float viewport_x;         /* +0x08 (PRES: *(float*)(param_1+8) in Render) */
    float viewport_y;         /* +0x0C (PRES: *(float*)(param_1+0xc) in Render) */
    float viewport_w;         /* +0x10 (PRES: *(float*)(param_1+0x10) in Render) */
    float viewport_h;         /* +0x14 (PRES: *(float*)(param_1+0x14) in Render) */
    uint8_t pad_18[0x10];     /* +0x18 (UNKNOWN, includes allocator ref at +0x18) */
    float sprite_x;           /* +0x28 (PRES: local_dc in Render) */
    float sprite_y;           /* +0x2C (PRES: local_e0 in Render) */
    /* Size unproven beyond this point. Pad to 0x30 for alignment only. */
    uint8_t pad_30[0x04];     /* +0x30 (UNKNOWN, aligns to 0x34) */
} nucc_Resolution;
#pragma pack(pop)

/* No sizeof assert — size unproven in s2. Field offsets verified below. */
static_assert(offsetof(nucc_Resolution, vtable) == 0x00, "Res vtable offset");
static_assert(offsetof(nucc_Resolution, viewport_x) == 0x08, "Res viewport_x offset");
static_assert(offsetof(nucc_Resolution, viewport_y) == 0x0C, "Res viewport_y offset");
static_assert(offsetof(nucc_Resolution, viewport_w) == 0x10, "Res viewport_w offset");
static_assert(offsetof(nucc_Resolution, viewport_h) == 0x14, "Res viewport_h offset");
static_assert(offsetof(nucc_Resolution, pad_18) == 0x18, "Res pad_18 offset");
static_assert(offsetof(nucc_Resolution, sprite_x) == 0x28, "Res sprite_x offset");
static_assert(offsetof(nucc_Resolution, sprite_y) == 0x2C, "Res sprite_y offset");
static_assert(offsetof(nucc_Resolution, pad_30) == 0x30, "Res pad_30 offset");

/* ─── nuccShaderManager ──────────────────────────────────────────
 * Size: 0x40 (proven: LoadTh(0x40, ...) in Initialize)
 * Singleton: DAT_140aa0378
 * puVar1 is uint32*: [0]=+0x00, [2]=+0x10, [4]=+0x20, [0xe]=+0x38
 */
#pragma pack(push, 1)
typedef struct {
    uint32_t flags;           /* +0x00 (PRES: *puVar1=0 in Initialize) */
    uint8_t pad_04[0x0C];     /* +0x04 (UNKNOWN) */
    uint64_t shader_tree_ptr; /* +0x10 (PRES: *(param_1+0x10) in GetInfoId) */
    uint8_t pad_18[0x08];     /* +0x18 (UNKNOWN) */
    uint64_t fun_ptr_or_data; /* +0x20 (PRES: FUN_1405dece0(puVar1+4)) */
    uint8_t pad_28[0x10];     /* +0x28 (UNKNOWN) */
    uint64_t sentinel;        /* +0x38 (PRES: puVar1[0xe]=0xffffffffffffffff) */
} nucc_ShaderManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ShaderManager) == 0x40, "ShaderManager size");
static_assert(offsetof(nucc_ShaderManager, flags) == 0x00, "SM flags offset");
static_assert(offsetof(nucc_ShaderManager, pad_04) == 0x04, "SM pad_04 offset");
static_assert(offsetof(nucc_ShaderManager, shader_tree_ptr) == 0x10, "SM tree ptr offset");
static_assert(offsetof(nucc_ShaderManager, pad_18) == 0x18, "SM pad_18 offset");
static_assert(offsetof(nucc_ShaderManager, fun_ptr_or_data) == 0x20, "SM fun_ptr offset");
static_assert(offsetof(nucc_ShaderManager, pad_28) == 0x28, "SM pad_28 offset");
static_assert(offsetof(nucc_ShaderManager, sentinel) == 0x38, "SM sentinel offset");

/* ─── nuccShaderParamTbl ─────────────────────────────────────────
 * Size: 0x28 (proven: LoadTh(0x28, ...) in Initialize)
 * NOTE: s2 size is 0x28, DIFFERENT from s1's 0x58.
 * Singleton: DAT_140aa1b50
 */
#pragma pack(push, 1)
typedef struct {
    uint8_t pad_00[0x28];     /* +0x00 (UNKNOWN, entire object initialized by FUN_1405f6d40) */
} nucc_ShaderParamTbl;
#pragma pack(pop)

static_assert(sizeof(nucc_ShaderParamTbl) == 0x28, "ShaderParamTbl size");
static_assert(offsetof(nucc_ShaderParamTbl, pad_00) == 0x00, "SPT pad_00 offset");

/* ─── nuccShadowProjection ───────────────────────────────────────
 * Size: unknown, >= 0x58C (statically allocated singleton DAT_140a5e840;
 *   no LoadTh in s2; highest proven field cascade_count at +0x588, 4 bytes)
 * Singleton: DAT_140a5e840
 * Vtable: INFERRED (not directly observed in s2 methods)
 *
 * Proven field offsets from decompiled methods:
 *   +0x018 render_texture (Initialize: LockRenderTexture result)
 *   +0x038 camera_ptr (SetCameraView: stores param_2)
 *   +0x100 light_dir (SetLight: Vector3 copy)
 *   +0x108 light_param (SetLight: uint32 from param_2+1)
 *   +0x10C light_intensity (SetLight: float param_3)
 *   +0x110 view_matrices (GetShadowProjMatrix: stride 0x40 per cascade)
 *   +0x210 proj_matrices (GetShadowProjMatrix: stride 0x40 per cascade)
 *   +0x310 transpose_matrices (GetShadowProjMatrix: stride 0x40 per cascade)
 *   +0x440 cascade_base (UpdateMatrix: float read/write)
 *   +0x450 cascade_index_cur (UpdateMatrix: set to 0)
 *   +0x454 cascade_splits (UpdateMatrix: float array)
 *   +0x464 shadow_bias (GetDistanceSplitFrustum: float*)
 *   +0x470 cascade_rects (Initialize: Vector4_MathGeo::Set stride 0x10)
 *   +0x4F0 lispsm_data (UpdateMatrix: calcLightViewLiSPSM sub-offsets)
 *   +0x560 current_cascade_idx (CreateShadowTexture: loop counter)
 *   +0x588 cascade_count (CreateShadowTexture/GetDistanceSplitFrustum: loop bound)
 *
 * No sizeof assert emitted due to unproven total size.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;          /* +0x000 (INFERRED) */
    uint8_t pad_008[0x010];   /* +0x008..+0x017 (UNKNOWN) */
    void *render_texture;     /* +0x018 (PRES: Initialize stores LockRenderTexture) */
    uint8_t pad_020[0x018];   /* +0x020..+0x037 (UNKNOWN) */
    void *camera_ptr;         /* +0x038 (PRES: SetCameraView stores param_2) */
    uint8_t pad_040[0x0C0];   /* +0x040..+0x0FF (view/proj/light matrices region) */
    uint64_t light_dir_xy;    /* +0x100 (PRES: SetLight *(param_1+0x100)=*param_2, 8 bytes) */
    uint32_t light_dir_z_pad; /* +0x108 (PRES: SetLight *(param_1+0x108)=uVar1) */
    float light_intensity;    /* +0x10C (PRES: SetLight *(float*)(param_1+0x10c)=param_3) */
    /* Matrix blocks: view at +0x110, proj at +0x210, transpose at +0x310, stride 0x40 per cascade */
    uint8_t matrix_block[0x200]; /* +0x110..+0x30F (PRES: Matrix44 arrays, 8 cascades * 0x40) */
    uint8_t pad_310[0x130];   /* +0x310..+0x43F (transpose targets, cascade data) */
    float cascade_base;       /* +0x440 (PRES: UpdateMatrix reads/writes) */
    uint8_t pad_444[0x00C];   /* +0x444..+0x44F (aligns next int to +0x450) */
    int32_t cascade_index_cur;/* +0x450 (PRES: *(param_1+0x450)=0 in UpdateMatrix) */
    float cascade_splits[4];  /* +0x454..+0x463 (PRES: UpdateMatrix float array) */
    float shadow_bias;        /* +0x464 (PRES: GetDistanceSplitFrustum reads) */
    uint8_t pad_468[0x008];   /* +0x468..+0x46F (aligns cascade_rects to +0x470) */
    nucc_Vector4 cascade_rects[16]; /* +0x470..+0x56F (PRES: Set writes stride 0x10, 16 entries) */
    int32_t current_cascade_idx; /* +0x570 (PRES: loop counter in CreateShadowTexture) */
    uint8_t pad_574[0x014];   /* +0x574..+0x587 (UNKNOWN) */
    int32_t cascade_count;    /* +0x588 (PRES: loop bound in CreateShadowTexture) */
    uint8_t pad_58C[0x004];   /* +0x58C..+0x58F (pad to 0x590) */
} nucc_ShadowProjection;
#pragma pack(pop)

/* No sizeof assert — size unproven in s2 (static singleton, no LoadTh).
 * Field offsets verified below up to cascade_count at +0x588. */
static_assert(offsetof(nucc_ShadowProjection, vtable) == 0x000, "SP vtable offset");
static_assert(offsetof(nucc_ShadowProjection, pad_008) == 0x008, "SP pad_008 offset");
static_assert(offsetof(nucc_ShadowProjection, render_texture) == 0x018, "SP render_texture offset");
static_assert(offsetof(nucc_ShadowProjection, pad_020) == 0x020, "SP pad_020 offset");
static_assert(offsetof(nucc_ShadowProjection, camera_ptr) == 0x038, "SP camera_ptr offset");
static_assert(offsetof(nucc_ShadowProjection, pad_040) == 0x040, "SP pad_040 offset");
static_assert(offsetof(nucc_ShadowProjection, light_dir_xy) == 0x100, "SP light_dir_xy offset");
static_assert(offsetof(nucc_ShadowProjection, light_dir_z_pad) == 0x108, "SP light_dir_z_pad offset");
static_assert(offsetof(nucc_ShadowProjection, light_intensity) == 0x10C, "SP light_intensity offset");
static_assert(offsetof(nucc_ShadowProjection, matrix_block) == 0x110, "SP matrix_block offset");
static_assert(offsetof(nucc_ShadowProjection, pad_310) == 0x310, "SP pad_310 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_base) == 0x440, "SP cascade_base offset");
static_assert(offsetof(nucc_ShadowProjection, pad_444) == 0x444, "SP pad_444 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_index_cur) == 0x450, "SP cascade_index_cur offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_splits) == 0x454, "SP cascade_splits offset");
static_assert(offsetof(nucc_ShadowProjection, shadow_bias) == 0x464, "SP shadow_bias offset");
static_assert(offsetof(nucc_ShadowProjection, pad_468) == 0x468, "SP pad_468 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_rects) == 0x470, "SP cascade_rects offset");
static_assert(offsetof(nucc_ShadowProjection, current_cascade_idx) == 0x570, "SP cascade idx offset");
static_assert(offsetof(nucc_ShadowProjection, pad_574) == 0x574, "SP pad_574 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_count) == 0x588, "SP cascade count offset");
static_assert(offsetof(nucc_ShadowProjection, pad_58C) == 0x58C, "SP pad_58C offset");

#endif /* CMN67_H */