/* cmn67.h — NARUTO STORM 3 Full Burst HD (s3) struct group cmn67
 * Reconstructed from decompiled NSUNS3.exe (build s3, image base 0x140000000).
 * All sizes proven from game code (LoadTh / allocator size arg) where possible.
 * Static fields are INFERRED unless confirmed by replay trace.
 * OWN-GAME NAMES only (ns3:: / Storm 3 strings).
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
 * Singleton: DAT_140c677c0
 * Vtable: not observed (singleton access pattern)
 * Vector at +0x08 (begin/end/cap at +0x08/+0x10/+0x18)
 * BlockAllocator at +0x20 (DeleteRenderTexture: GetOwnerHandle(param_1+0x20))
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable_or_pad;     /* +0x00 (INFERRED) */
    nucc_StdVector render_textures; /* +0x08 (PRES: push_back in AddRenderTextureNormal) */
    nucc_BlockAllocator allocator;  /* +0x20 (PRES: GetOwnerHandle in DeleteRenderTexture) */
    uint8_t pad_28[0x10];       /* +0x28 (UNKNOWN) */
} nucc_RenderTextureManager;
#pragma pack(pop)

static_assert(sizeof(nucc_RenderTextureManager) == 0x38, "RenderTextureManager size");
static_assert(offsetof(nucc_RenderTextureManager, vtable_or_pad) == 0x00, "RTM vtable_or_pad offset");
static_assert(offsetof(nucc_RenderTextureManager, render_textures) == 0x08, "RTM vector offset");
static_assert(offsetof(nucc_RenderTextureManager, allocator) == 0x20, "RTM allocator offset");
static_assert(offsetof(nucc_RenderTextureManager, pad_28) == 0x28, "RTM pad_28 offset");

/* ─── nuccReplacePathManager ─────────────────────────────────────
 * Inner entry size: 0x70 (proven: LoadTh(0x70, ...) in AddReplacePathImpl)
 * Outer manager size: 0x70 (same allocation; vector at +0x50, allocator at +0x68)
 * Two std::string at +0x00 and +0x38 within inner entry (AddReplacePathImpl)
 * Two BlockAllocator ctors at lVar6 and lVar6+0x38 within inner entry
 * Critical section at +0x00 of outer (ClearReplacePath: Unlock(param_1))
 * Vector at +0x50 (begin/end at +0x50/+0x58)
 * BlockAllocator at +0x68 (ClearReplacePath: GetOwnerHandle(param_1+0x68))
 */
#pragma pack(push, 1)
typedef struct {
    uint8_t crit_section[0x50]; /* +0x00 (UNKNOWN, includes critical section) */
    nucc_StdVector replace_params; /* +0x50 (PRES: clear/push in ClearReplacePath/AddReplacePathImpl) */
    nucc_BlockAllocator allocator; /* +0x68 (PRES: GetOwnerHandle in ClearReplacePath) */
} nucc_ReplacePathManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ReplacePathManager) == 0x70, "ReplacePathManager size");
static_assert(offsetof(nucc_ReplacePathManager, crit_section) == 0x00, "RPM crit_section offset");
static_assert(offsetof(nucc_ReplacePathManager, replace_params) == 0x50, "RPM vector offset");
static_assert(offsetof(nucc_ReplacePathManager, allocator) == 0x68, "RPM allocator offset");

/* ─── nuccResolution ─────────────────────────────────────────────
 * Size: unknown, >= 0x28 (no LoadTh in s3; last proven field sprite_y at +0x24)
 * Vtable: PTR_FUN_1409ec308 (PRES: set in ctor)
 * BlockAllocator at +0x10 (PRES: ctor calls BlockAllocator(param_1+2))
 * Viewport floats at +0x08/+0x0C/+0x10/+0x14 (Render)
 * Sprite dims at +0x20/+0x24 (Render)
 *
 * No sizeof assert emitted due to unproven total size.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;            /* +0x00 (PRES: PTR_FUN_1409ec308) */
    float viewport_x;           /* +0x08 (PRES: *(float*)(param_1+8) in Render) */
    float viewport_y;           /* +0x0C (PRES: *(float*)(param_1+0xc) in Render) */
    float viewport_w;           /* +0x10 (PRES: *(float*)(param_1+0x10) in Render) */
    float viewport_h;           /* +0x14 (PRES: *(float*)(param_1+0x14) in Render) */
    uint8_t pad_18[0x08];      /* +0x18 (UNKNOWN, includes allocator ref) */
    float sprite_w;             /* +0x20 (PRES: local_dc in Render) */
    float sprite_h;             /* +0x24 (PRES: local_e0 in Render) */
    /* Size unproven beyond this point. */
} nucc_Resolution;
#pragma pack(pop)

/* No sizeof assert — size unproven in s3. Field offsets verified below. */
static_assert(offsetof(nucc_Resolution, vtable) == 0x00, "Res vtable offset");
static_assert(offsetof(nucc_Resolution, viewport_x) == 0x08, "Res viewport_x offset");
static_assert(offsetof(nucc_Resolution, viewport_y) == 0x0C, "Res viewport_y offset");
static_assert(offsetof(nucc_Resolution, viewport_w) == 0x10, "Res viewport_w offset");
static_assert(offsetof(nucc_Resolution, viewport_h) == 0x14, "Res viewport_h offset");
static_assert(offsetof(nucc_Resolution, pad_18) == 0x18, "Res pad_18 offset");
static_assert(offsetof(nucc_Resolution, sprite_w) == 0x20, "Res sprite_w offset");
static_assert(offsetof(nucc_Resolution, sprite_h) == 0x24, "Res sprite_h offset");

/* ─── nuccShaderManager ──────────────────────────────────────────
 * Size: 0x40 (proven: LoadTh(0x40, ...) in Initialize)
 * Singleton: DAT_140c67d48
 * puVar1 is uint32*: [0]=+0x00, [2]=+0x08, [4]=+0x10, [0xe]=+0x38, [0xf]=+0x3C
 */
#pragma pack(push, 1)
typedef struct {
    uint32_t flags;             /* +0x00 (PRES: *puVar1=0 in Initialize) */
    uint8_t pad_04[0x04];      /* +0x04 (UNKNOWN) */
    uint64_t shader_tree_ptr;   /* +0x08 (PRES: *(puVar1+2)=0 in Initialize) */
    uint64_t fun_ptr_or_data;   /* +0x10 (PRES: FUN_1406255c0(puVar1+4) in Initialize) */
    uint8_t pad_18[0x20];      /* +0x18 (UNKNOWN) */
    uint32_t g_is_character_0;  /* +0x38 (PRES: puVar1[0xe] = handle in Create) */
    uint32_t g_is_character_1;  /* +0x3C (PRES: puVar1[0xf] = handle in Create) */
} nucc_ShaderManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ShaderManager) == 0x40, "ShaderManager size");
static_assert(offsetof(nucc_ShaderManager, flags) == 0x00, "SM flags offset");
static_assert(offsetof(nucc_ShaderManager, pad_04) == 0x04, "SM pad_04 offset");
static_assert(offsetof(nucc_ShaderManager, shader_tree_ptr) == 0x08, "SM tree ptr offset");
static_assert(offsetof(nucc_ShaderManager, fun_ptr_or_data) == 0x10, "SM fun_ptr offset");
static_assert(offsetof(nucc_ShaderManager, pad_18) == 0x18, "SM pad_18 offset");
static_assert(offsetof(nucc_ShaderManager, g_is_character_0) == 0x38, "SM g_is_character_0 offset");
static_assert(offsetof(nucc_ShaderManager, g_is_character_1) == 0x3C, "SM g_is_character_1 offset");

/* ─── nuccShaderParamTbl ─────────────────────────────────────────
 * No instance state — all 5 methods are static/utility:
 *   Initialize (0x6CB520): no this; allocates nuccShadowProjection via LoadTh(0x590)
 *   Finalize   (0x702AF0): no this; operates on global DAT_140c69460
 *   ParseNSH   (0x702C60): param_1 is std::map tree root (node color at +0x19), not this
 *   GetUsedParameter (0x6AFF90): no params; returns &DAT_140b5bea8
 *   GetUsedParameter (0x702BB0): param_1 is tree node ptr (same traversal as ParseNSH)
 * No struct emitted. All evidence INFERRED from s3 decompiled code.
 */

/* ─── nuccShadowProjection ───────────────────────────────────────
 * Size: 0x590 (proven: LoadTh(0x590, ...) in nuccShaderParamTbl::Initialize
 *        which actually allocates ShadowProjection — source file confirms
 *        "..\\source\\render\\nuccShadowProjection.cpp")
 * Singleton: DAT_140c66a00
 * Vtable: INFERRED (not directly observed in s3 methods)
 *
 * Proven field offsets from decompiled methods:
 * +0x018 render_texture (Initialize: LockRenderTexture result)
 * +0x038 camera_ptr (SetCameraView: stores param_2)
 * +0x040 view_matrix (UpdateMatrix: Matrix44_MathGeo from camera+0x140)
 * +0x080 inv_view_matrix (UpdateMatrix: Inverted(view_matrix))
 * +0x0C0 proj_matrix_src (UpdateMatrix: Matrix44_MathGeo from camera+0x100)
 * +0x100 light_dir_xy (SetLight: *(param_1+0x100)=*param_2, 8 bytes)
 * +0x108 light_dir_z (SetLight: *(param_1+0x108)=uVar1, 4 bytes)
 * +0x10C light_intensity (SetLight: *(float*)(param_1+0x10c)=param_3)
 * +0x110 view_matrices (CreateShadowTexture/GetShadowProjMatrix: stride 0x40 per cascade)
 * +0x210 proj_matrices (CreateShadowTexture/GetShadowProjMatrix: stride 0x40 per cascade)
 * +0x310 transpose_matrices (GetShadowProjMatrix: stride 0x40 per cascade)
 * +0x440 cascade_base (UpdateMatrix: float read/write)
 * +0x450 cascade_index_cur (UpdateMatrix: set to 0)
 * +0x454 cascade_splits (UpdateMatrix: float array, stride 4)
 * +0x460 cascade_end (UpdateMatrix: cascade_base + 100.0)
 * +0x470 cascade_rects (Initialize: Vector4_MathGeo::Set stride 0x10)
 * +0x4F0 lispsm_data (UpdateMatrix: calcLightViewLiSPSM sub-offsets, stride 0x18)
 * +0x560 current_cascade_idx (CreateShadowTexture/UpdateMatrix: loop counter)
 * +0x588 cascade_count (CreateShadowTexture/UpdateMatrix: loop bound)
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;            /* +0x000 (INFERRED) */
    uint8_t pad_008[0x010];    /* +0x008..+0x017 (UNKNOWN) */
    void *render_texture;       /* +0x018 (PRES: Initialize stores LockRenderTexture) */
    uint8_t pad_020[0x018];    /* +0x020..+0x037 (UNKNOWN) */
    void *camera_ptr;           /* +0x038 (PRES: SetCameraView stores param_2) */
    uint8_t view_matrix[0x40];  /* +0x040 (PRES: UpdateMatrix Matrix44 from camera+0x140) */
    uint8_t inv_view_matrix[0x40]; /* +0x080 (PRES: UpdateMatrix Inverted) */
    uint8_t proj_matrix_src[0x40]; /* +0x0C0 (PRES: UpdateMatrix Matrix44 from camera+0x100) */
    uint64_t light_dir_xy;      /* +0x100 (PRES: SetLight 8-byte copy) */
    uint32_t light_dir_z;       /* +0x108 (PRES: SetLight uVar1) */
    float light_intensity;      /* +0x10C (PRES: SetLight float param_3) */
    uint8_t matrix_block[0x200]; /* +0x110..+0x30F (PRES: view/proj matrices, 8 cascades * 0x40) */
    uint8_t transpose_block[0x130]; /* +0x310..+0x43F (PRES: transpose targets) */
    float cascade_base;         /* +0x440 (PRES: UpdateMatrix reads/writes) */
    uint8_t pad_444[0x00C];    /* +0x444..+0x44F (aligns next int to +0x450) */
    int32_t cascade_index_cur;  /* +0x450 (PRES: UpdateMatrix sets to 0) */
    float cascade_splits[4];    /* +0x454..+0x463 (PRES: UpdateMatrix float array) */
    float cascade_end;          /* +0x464 (PRES: UpdateMatrix cascade_base+100) */
    uint8_t pad_468[0x008];    /* +0x468..+0x46F (aligns cascade_rects to +0x470) */
    nucc_Vector4 cascade_rects[8]; /* +0x470..+0x4EF (PRES: Initialize Set stride 0x10, 8 entries) */
    uint8_t lispsm_data[0x70]; /* +0x4F0..+0x55F (PRES: calcLightViewLiSPSM stride 0x18) */
    int32_t current_cascade_idx; /* +0x560 (PRES: loop counter) */
    uint8_t pad_564[0x024];    /* +0x564..+0x587 (UNKNOWN) */
    int32_t cascade_count;      /* +0x588 (PRES: loop bound) */
    uint8_t pad_58C[0x004];    /* +0x58C..+0x58F (pad to 0x590) */
} nucc_ShadowProjection;
#pragma pack(pop)

static_assert(sizeof(nucc_ShadowProjection) == 0x590, "ShadowProjection size");
static_assert(offsetof(nucc_ShadowProjection, vtable) == 0x000, "SP vtable offset");
static_assert(offsetof(nucc_ShadowProjection, pad_008) == 0x008, "SP pad_008 offset");
static_assert(offsetof(nucc_ShadowProjection, render_texture) == 0x018, "SP render_texture offset");
static_assert(offsetof(nucc_ShadowProjection, pad_020) == 0x020, "SP pad_020 offset");
static_assert(offsetof(nucc_ShadowProjection, camera_ptr) == 0x038, "SP camera_ptr offset");
static_assert(offsetof(nucc_ShadowProjection, view_matrix) == 0x040, "SP view_matrix offset");
static_assert(offsetof(nucc_ShadowProjection, inv_view_matrix) == 0x080, "SP inv_view_matrix offset");
static_assert(offsetof(nucc_ShadowProjection, proj_matrix_src) == 0x0C0, "SP proj_matrix_src offset");
static_assert(offsetof(nucc_ShadowProjection, light_dir_xy) == 0x100, "SP light_dir_xy offset");
static_assert(offsetof(nucc_ShadowProjection, light_dir_z) == 0x108, "SP light_dir_z offset");
static_assert(offsetof(nucc_ShadowProjection, light_intensity) == 0x10C, "SP light_intensity offset");
static_assert(offsetof(nucc_ShadowProjection, matrix_block) == 0x110, "SP matrix_block offset");
static_assert(offsetof(nucc_ShadowProjection, transpose_block) == 0x310, "SP transpose_block offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_base) == 0x440, "SP cascade_base offset");
static_assert(offsetof(nucc_ShadowProjection, pad_444) == 0x444, "SP pad_444 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_index_cur) == 0x450, "SP cascade_index_cur offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_splits) == 0x454, "SP cascade_splits offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_end) == 0x464, "SP cascade_end offset");
static_assert(offsetof(nucc_ShadowProjection, pad_468) == 0x468, "SP pad_468 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_rects) == 0x470, "SP cascade_rects offset");
static_assert(offsetof(nucc_ShadowProjection, lispsm_data) == 0x4F0, "SP lispsm_data offset");
static_assert(offsetof(nucc_ShadowProjection, current_cascade_idx) == 0x560, "SP current_cascade_idx offset");
static_assert(offsetof(nucc_ShadowProjection, pad_564) == 0x564, "SP pad_564 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_count) == 0x588, "SP cascade_count offset");
static_assert(offsetof(nucc_ShadowProjection, pad_58C) == 0x58C, "SP pad_58C offset");

#endif /* CMN67_H */