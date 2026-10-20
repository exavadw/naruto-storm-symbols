/* cmn67.h — NARUTO STORM 4 PC 1.09 (s4) struct group cmn67
 * Reconstructed from decompiled NSUNS4_release.exe (build s4, image base 0x140000000).
 * All sizes proven from game code (operator_new / allocator size arg) where possible.
 * Static fields are INFERRED unless confirmed by replay trace.
 * OWN-GAME NAMES only (Storm 4 symbols/strings).
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
 * Size: 0x38 (proven: operator_new(0x38) in CreateInstance 0xA69280)
 * Singleton: DAT_1416b82e0
 * Vtable: PTR_FUN_141019170 (PRES: set in ctor 0x53470C)
 * BlockAllocator at base (ctor arg 1) and at param_1+5 (offset 0x28)
 * Vector at +0x08 (begin/end/cap at +0x08/+0x10/+0x18) per CreateInstance reserve
 * Note: ctor accesses up to param_1[0x5b] but those are byte-offset accesses
 *   on undefined8*; actual allocation is 0x38 per operator_new.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;              /* +0x00 (PRES: PTR_FUN_141019170 in ctor) */
    nucc_StdVector render_textures; /* +0x08 (PRES: reserve(0x10) in CreateInstance) */
    nucc_BlockAllocator allocator;  /* +0x20 (PRES: BlockAllocator(param_1+5) in ctor = offset 0x28) */
    uint8_t pad_28[0x10];        /* +0x28..+0x37 (UNKNOWN) */
} nucc_RenderTextureManager;
#pragma pack(pop)

static_assert(sizeof(nucc_RenderTextureManager) == 0x38, "RenderTextureManager size");
static_assert(offsetof(nucc_RenderTextureManager, vtable) == 0x00, "RTM vtable offset");
static_assert(offsetof(nucc_RenderTextureManager, render_textures) == 0x08, "RTM vector offset");
static_assert(offsetof(nucc_RenderTextureManager, allocator) == 0x20, "RTM allocator offset");
static_assert(offsetof(nucc_RenderTextureManager, pad_28) == 0x28, "RTM pad_28 offset");

/* ─── nuccReplacePathManager ─────────────────────────────────────
 * Inner entry size: 0x70 (proven: operator_new(0x70) in AddReplacePathImpl 0xA32770)
 * Outer manager size: 0x70 (same allocation pattern; vector at +0x50, allocator at +0x68)
 * Two std::string at +0x00 and +0x38 within inner entry (AddReplacePathImpl)
 * Critical section at +0x00 of outer (ClearReplacePath: Unlock(param_1))
 * Vector at +0x50 (begin/end at +0x50/+0x58 per ClearReplacePath)
 * BlockAllocator at +0x68 (ClearReplacePath: GetOwnerHandle(param_1+0x68))
 */
#pragma pack(push, 1)
typedef struct {
    uint8_t crit_section[0x50];  /* +0x00 (UNKNOWN, includes critical section) */
    nucc_StdVector replace_params; /* +0x50 (PRES: clear/push in ClearReplacePath/AddReplacePathImpl) */
    nucc_BlockAllocator allocator; /* +0x68 (PRES: GetOwnerHandle in ClearReplacePath) */
} nucc_ReplacePathManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ReplacePathManager) == 0x70, "ReplacePathManager size");
static_assert(offsetof(nucc_ReplacePathManager, crit_section) == 0x00, "RPM crit_section offset");
static_assert(offsetof(nucc_ReplacePathManager, replace_params) == 0x50, "RPM vector offset");
static_assert(offsetof(nucc_ReplacePathManager, allocator) == 0x68, "RPM allocator offset");

/* ─── nuccResolution ─────────────────────────────────────────────
 * Size: unknown, >= 0x28 (no operator_new/LoadTh found in s4 methods)
 * Vtable: PTR_FUN_1410075d8 (PRES: set in ctor 0xA08E10)
 * BlockAllocator at +0x10 (PRES: ctor calls BlockAllocator(param_1+2))
 * Viewport floats at +0x08/+0x0C/+0x10/+0x14 (Render 0xA68210)
 * Sprite dims at +0x20/+0x24 (Render 0xA68210)
 *
 * No sizeof assert emitted due to unproven total size.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;            /* +0x00 (PRES: PTR_FUN_1410075d8) */
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

/* No sizeof assert — size unproven in s4. Field offsets verified below. */
static_assert(offsetof(nucc_Resolution, vtable) == 0x00, "Res vtable offset");
static_assert(offsetof(nucc_Resolution, viewport_x) == 0x08, "Res viewport_x offset");
static_assert(offsetof(nucc_Resolution, viewport_y) == 0x0C, "Res viewport_y offset");
static_assert(offsetof(nucc_Resolution, viewport_w) == 0x10, "Res viewport_w offset");
static_assert(offsetof(nucc_Resolution, viewport_h) == 0x14, "Res viewport_h offset");
static_assert(offsetof(nucc_Resolution, pad_18) == 0x18, "Res pad_18 offset");
static_assert(offsetof(nucc_Resolution, sprite_w) == 0x20, "Res sprite_w offset");
static_assert(offsetof(nucc_Resolution, sprite_h) == 0x24, "Res sprite_h offset");

/* ─── nuccShaderManager ──────────────────────────────────────────
 * Size: 0x48 (proven: operator_new(0x48) in Initialize 0xA75F30)
 * Singleton: DAT_1416b8c58
 * puVar1 is uint32*: [0]=+0x00, [2]=+0x08, [4]=+0x10, [0xe]=+0x38, [0x10]=+0x40
 * Finalize calls std::__tree destroy → contains a std::map or similar container
 */
#pragma pack(push, 1)
typedef struct {
    uint32_t flags;             /* +0x00 (PRES: *puVar1=0 in Initialize) */
    uint8_t pad_04[0x04];      /* +0x04 (UNKNOWN) */
    uint64_t shader_tree_ptr;   /* +0x08 (PRES: *(puVar1+2)=0 in Initialize) */
    uint64_t fun_ptr_or_data;   /* +0x10 (PRES: FUN_1406c7864(puVar1+4) in Initialize) */
    uint8_t pad_18[0x20];      /* +0x18 (UNKNOWN) */
    uint32_t g_is_character_0;  /* +0x38 (PRES: puVar1[0xe] = 0xffffffff in Initialize) */
    uint32_t g_is_character_1;  /* +0x3C (PRES: puVar1[0xf] implied) */
    uint32_t map_field_0;       /* +0x40 (PRES: puVar1[0x10] = 0xffffffff in Initialize) */
    uint8_t pad_44[0x04];      /* +0x44 (UNKNOWN, pad to 0x48) */
} nucc_ShaderManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ShaderManager) == 0x48, "ShaderManager size");
static_assert(offsetof(nucc_ShaderManager, flags) == 0x00, "SM flags offset");
static_assert(offsetof(nucc_ShaderManager, pad_04) == 0x04, "SM pad_04 offset");
static_assert(offsetof(nucc_ShaderManager, shader_tree_ptr) == 0x08, "SM tree ptr offset");
static_assert(offsetof(nucc_ShaderManager, fun_ptr_or_data) == 0x10, "SM fun_ptr offset");
static_assert(offsetof(nucc_ShaderManager, pad_18) == 0x18, "SM pad_18 offset");
static_assert(offsetof(nucc_ShaderManager, g_is_character_0) == 0x38, "SM g_is_character_0 offset");
static_assert(offsetof(nucc_ShaderManager, g_is_character_1) == 0x3C, "SM g_is_character_1 offset");
static_assert(offsetof(nucc_ShaderManager, map_field_0) == 0x40, "SM map_field_0 offset");
static_assert(offsetof(nucc_ShaderManager, pad_44) == 0x44, "SM pad_44 offset");

/* ─── nuccShaderParamTbl ─────────────────────────────────────────
 * Size: unknown (no direct allocation found for this class in s4)
 * Only constructor/initialize methods found; field accesses sparse.
 * Listed in report only (< 3 non-ctor methods with field evidence).
 */

/* ─── nuccShadowProjection ───────────────────────────────────────
 * Size: 0x5a0 (proven: operator_new(0x5a0) in ShaderParamTbl::Initialize 0xA3F5A0,
 *        source file confirms "..\\source\\render\\nuccShadowProjection.cpp")
 * Singleton: DAT_1416b6030
 * Vtable: INFERRED (not directly observed in s4 methods)
 *
 * Proven field offsets from decompiled methods:
 * +0x018 render_texture (Initialize: LockRenderTexture result)
 * +0x030 depth_render_texture (Initialize: second LockRenderTexture)
 * +0x038 camera_ptr (SetCameraView: stores param_2; CreateShadowTexture reads +0x274/+0x278)
 * +0x040 view_matrix (UpdateMatrix: Matrix44_MathGeo from camera+0x140)
 * +0x080 inv_view_matrix (UpdateMatrix: Inverted(view_matrix))
 * +0x0C0 proj_matrix_src (UpdateMatrix: Matrix44_MathGeo from camera+0x100)
 * +0x100 light_dir_xy (SetLight: *(param_1+0x100)=*param_2, 8 bytes)
 * +0x108 light_dir_z (SetLight: *(param_1+0x108)=uVar1, 4 bytes)
 * +0x10C light_intensity (SetLight: *(float*)(param_1+0x10c)=param_3)
 * +0x110 view_matrices (CreateShadowTexture/UpdateMatrix: stride 0x40 per cascade)
 * +0x210 proj_matrices (CreateShadowTexture/UpdateMatrix: stride 0x40 per cascade)
 * +0x310 transpose_matrices (UpdateMatrix: mmMatrix4::Transpose stride 0x40)
 * +0x440 cascade_base (UpdateMatrix: float read/write)
 * +0x450 cascade_index_cur (UpdateMatrix: set to 0)
 * +0x454 cascade_splits (UpdateMatrix: float array, stride 4)
 * +0x460 cascade_end (UpdateMatrix: cascade_base + 200.0)
 * +0x470 cascade_rects (Initialize: Vector4_MathGeo::SetXYZW stride 0x10)
 * +0x4F0 lispsm_data (UpdateMatrix: calcLightViewLiSPSM sub-offsets, stride 0x18)
 * +0x550 cascade_split_ints (CreateShadowTexture: int array stride 4)
 * +0x560 current_cascade_idx (CreateShadowTexture/UpdateMatrix: loop counter)
 * +0x588 cascade_count (CreateShadowTexture/UpdateMatrix: loop bound)
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;            /* +0x000 (INFERRED) */
    uint8_t pad_008[0x010];    /* +0x008..+0x017 (UNKNOWN) */
    void *render_texture;       /* +0x018 (PRES: Initialize stores LockRenderTexture) */
    uint8_t pad_020[0x010];    /* +0x020..+0x02F (UNKNOWN) */
    void *depth_render_texture; /* +0x030 (PRES: Initialize stores second LockRenderTexture) */
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
    float cascade_end;          /* +0x464 (PRES: UpdateMatrix cascade_base+200) */
    uint8_t pad_468[0x008];    /* +0x468..+0x46F (aligns cascade_rects to +0x470) */
    nucc_Vector4 cascade_rects[8]; /* +0x470..+0x4EF (PRES: Initialize SetXYZW stride 0x10, 8 entries) */
    uint8_t lispsm_data[0x60]; /* +0x4F0..+0x54F (PRES: calcLightViewLiSPSM stride 0x18) */
    int32_t cascade_split_ints[4]; /* +0x550..+0x55F (PRES: CreateShadowTexture int array) */
    int32_t current_cascade_idx; /* +0x560 (PRES: loop counter) */
    uint8_t pad_564[0x024];    /* +0x564..+0x587 (UNKNOWN) */
    int32_t cascade_count;      /* +0x588 (PRES: loop bound) */
    uint8_t pad_58C[0x014];    /* +0x58C..+0x59F (pad to 0x5a0) */
} nucc_ShadowProjection;
#pragma pack(pop)

static_assert(sizeof(nucc_ShadowProjection) == 0x5a0, "ShadowProjection size");
static_assert(offsetof(nucc_ShadowProjection, vtable) == 0x000, "SP vtable offset");
static_assert(offsetof(nucc_ShadowProjection, pad_008) == 0x008, "SP pad_008 offset");
static_assert(offsetof(nucc_ShadowProjection, render_texture) == 0x018, "SP render_texture offset");
static_assert(offsetof(nucc_ShadowProjection, pad_020) == 0x020, "SP pad_020 offset");
static_assert(offsetof(nucc_ShadowProjection, depth_render_texture) == 0x030, "SP depth_render_texture offset");
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
static_assert(offsetof(nucc_ShadowProjection, cascade_split_ints) == 0x550, "SP cascade_split_ints offset");
static_assert(offsetof(nucc_ShadowProjection, current_cascade_idx) == 0x560, "SP current_cascade_idx offset");
static_assert(offsetof(nucc_ShadowProjection, pad_564) == 0x564, "SP pad_564 offset");
static_assert(offsetof(nucc_ShadowProjection, cascade_count) == 0x588, "SP cascade_count offset");
static_assert(offsetof(nucc_ShadowProjection, pad_58C) == 0x58C, "SP pad_58C offset");

/* nuccShaderParamTbl: no instance state
 * All 5 methods are static/utility functions operating on global data.
 * Evidence (s4 decompiles):
 *   Initialize       (0xA3F5A0) — void(void), allocates ShadowProjection into DAT_1416b6030
 *   Finalize         (0xA8A740) — void(void), destroys std::map at DAT_1416ba250
 *   GetUsedParameter (0xA44BF0) — returns &DAT_141561108 (static accessor)
 *   GetUsedParameter (0xA8A800) — tree traversal on param_1 (std::map node ptr, not this)
 *   ParseNSH         (0xA8A8B0) — parses NSH binary into global hashtable at DAT_141665c58
 * No method accesses fixed-offset fields on a this pointer.
 */
#endif /* CMN67_H */