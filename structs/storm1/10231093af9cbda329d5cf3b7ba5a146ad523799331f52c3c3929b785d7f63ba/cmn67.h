/* cmn67.h — NARUTO STORM 1 (s1) struct group cmn67
 * Reconstructed from decompiled NSUNS1.exe (build s1, image base 0x140000000).
 * All sizes proven from game code (LoadTh / embedded offset); never sizeof.
 * Static fields are INFERRED unless confirmed by replay trace.
 * OWN-GAME NAMES only (ns1:: / Switch Trilogy / Storm 1 strings).
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
 * Singleton: DAT_1408c7a20
 * Vtable: not observed (singleton access pattern)
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable_or_pad;           /* +0x00 (INFERRED) */
    nucc_StdVector render_textures;   /* +0x08 (PRES: push_back in AddRenderTextureNormal) */
    uint8_t pad_20[0x18];             /* +0x20 (UNKNOWN) */
} nucc_RenderTextureManager;
#pragma pack(pop)

static_assert(sizeof(nucc_RenderTextureManager) == 0x38, "RenderTextureManager size");
static_assert(offsetof(nucc_RenderTextureManager, vtable_or_pad) == 0x00, "RTM vtable_or_pad offset");
static_assert(offsetof(nucc_RenderTextureManager, render_textures) == 0x08, "RTM vector offset");
static_assert(offsetof(nucc_RenderTextureManager, pad_20) == 0x20, "RTM pad_20 offset");

/* ─── nuccReplacePathManager ─────────────────────────────────────
 * Size: 0x70 (proven: LoadTh(0x70, ...) in AddReplacePathImpl)
 * Vtable: not observed
 */
#pragma pack(push, 1)
typedef struct {
    uint8_t pad_00[0x50];             /* +0x00 (UNKNOWN, includes crit section) */
    nucc_StdVector replace_params;    /* +0x50 (PRES: clear/push in ClearReplacePath/AddReplacePathImpl) */
    nucc_BlockAllocator allocator;    /* +0x68 (PRES: GetBlockId in ClearReplacePath) */
} nucc_ReplacePathManager;
#pragma pack(pop)

static_assert(sizeof(nucc_ReplacePathManager) == 0x70, "ReplacePathManager size");
static_assert(offsetof(nucc_ReplacePathManager, pad_00) == 0x00, "RPM pad_00 offset");
static_assert(offsetof(nucc_ReplacePathManager, replace_params) == 0x50, "RPM vector offset");
static_assert(offsetof(nucc_ReplacePathManager, allocator) == 0x68, "RPM allocator offset");

/* ─── nuccResolution ─────────────────────────────────────────────
 * Size: 0x368 (proven: embedded at nuccSys+0x550, next field at +0x8b8 -> 0x8b8-0x550=0x368)
 * Vtable: PTR_FUN_140745358 (PRES: set in ctor)
 * BlockAllocator at +0x10 (PRES: ctor calls BlockAllocator(param_1+2))
 *
 * NOTE: Overlapping layout. The BlockAllocator is at word index 2 = byte +0x10.
 * Fields viewport_x..sprite_y are accessed in Render via float* casts and overlap
 * the same region. We document both interpretations; the flat layout below places
 * all fields sequentially for static_assert purposes. Actual internal ordering may differ.
 * No sizeof assert emitted due to overlapping interpretation.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;                  /* +0x00 (PRES: PTR_FUN_140745358) */
    uint32_t pad_08;                  /* +0x08 (UNKNOWN) */
    float viewport_x;                 /* +0x0C (PRES: read in Render) */
    float viewport_y;                 /* +0x10 (PRES: read in Render) */
    float viewport_w;                 /* +0x14 (PRES: read in Render) */
    float viewport_h;                 /* +0x18 (PRES: read in Render) */
    uint32_t render_mode;             /* +0x1C (PRES: read in Render) */
    uint32_t pad_20_val;              /* +0x20 (PRES: read in Render) */
    float sprite_x;                   /* +0x24 (PRES: read in Render) */
    float sprite_y;                   /* +0x28 (PRES: read in Render) */
    uint8_t pad_2C[0x33C];            /* +0x2C (UNKNOWN to 0x368) */
} nucc_Resolution;
#pragma pack(pop)

/* Size proven by embedding (0x368). Field offsets within are INFERRED from Render accesses.
 * No sizeof assert due to overlapping BlockAllocator interpretation documented above. */
static_assert(offsetof(nucc_Resolution, vtable) == 0x00, "Res vtable offset");
static_assert(offsetof(nucc_Resolution, pad_08) == 0x08, "Res pad_08 offset");
static_assert(offsetof(nucc_Resolution, viewport_x) == 0x0C, "Res viewport_x offset");
static_assert(offsetof(nucc_Resolution, viewport_y) == 0x10, "Res viewport_y offset");
static_assert(offsetof(nucc_Resolution, viewport_w) == 0x14, "Res viewport_w offset");
static_assert(offsetof(nucc_Resolution, viewport_h) == 0x18, "Res viewport_h offset");
static_assert(offsetof(nucc_Resolution, render_mode) == 0x1C, "Res render_mode offset");
static_assert(offsetof(nucc_Resolution, pad_20_val) == 0x20, "Res pad_20_val offset");
static_assert(offsetof(nucc_Resolution, sprite_x) == 0x24, "Res sprite_x offset");
static_assert(offsetof(nucc_Resolution, sprite_y) == 0x28, "Res sprite_y offset");
static_assert(offsetof(nucc_Resolution, pad_2C) == 0x2C, "Res pad_2C offset");

/* ─── nuccShaderManager ──────────────────────────────────────────
 * Size: 0x40 (proven: LoadTh(0x40, ...) in Initialize)
 * Singleton: DAT_1408c7c48
 * Note: LoadTh arg 0x40 = 64 bytes. Word-indexed accesses in Initialize:
 * puVar1[0]=0 -> +0x00, puVar1[2]=0 -> +0x10, puVar1[4] -> +0x20, puVar1[0xe] -> +0x38
 * puVar1 is uint32*.
 */
#pragma pack(push, 1)
typedef struct {
    uint32_t flags;                   /* +0x00 (PRES: *puVar1=0 in Initialize) */
    uint8_t pad_04[0x0C];             /* +0x04 (UNKNOWN) */
    uint64_t shader_tree_ptr;         /* +0x10 (PRES: *(param_1+0x10) in GetInfoId) */
    uint8_t pad_18[0x08];             /* +0x18 (UNKNOWN) */
    uint64_t fun_ptr_or_data;         /* +0x20 (PRES: FUN_1404f92b0(puVar1+4)) */
    uint8_t pad_28[0x10];             /* +0x28 (UNKNOWN) */
    uint64_t sentinel;                /* +0x38 (PRES: puVar1[0xe]=0xffffffffffffffff) */
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
 * Size: 0x58 (proven: LoadTh(0x58, ...) in Initialize for inner config)
 * Inner object allocated separately (LoadTh(0x58) returns ptr stored at +0x20)
 * Outer size unproven; inner config object is 0x58 from LoadTh.
 * If outer == inner (common pattern), size is 0x58. Marking as inferred.
 */
#pragma pack(push, 1)
typedef struct {
    uint8_t pad_00[0x18];             /* +0x00 (UNKNOWN) */
    uint64_t config_param;            /* +0x18 (PRES: ccNaviPlanner::Init reads *(param_1+0x18)) */
    void *inner_config;               /* +0x20 (PRES: Initialize stores LoadTh result here) */
    uint8_t pad_28[0x30];             /* +0x28 (UNKNOWN to 0x58 if outer==inner) */
} nucc_ShaderParamTbl;
#pragma pack(pop)

static_assert(offsetof(nucc_ShaderParamTbl, pad_00) == 0x00, "SPT pad_00 offset");
static_assert(offsetof(nucc_ShaderParamTbl, config_param) == 0x18, "SPT config_param offset");
static_assert(offsetof(nucc_ShaderParamTbl, inner_config) == 0x20, "SPT inner_config offset");
static_assert(offsetof(nucc_ShaderParamTbl, pad_28) == 0x28, "SPT pad_28 offset");

/* ─── nuccShadowProjection ───────────────────────────────────────
 * Size: 0x590 (proven: LoadTh(0x590, "..\\source\\render\nuccShadowProjection.cpp")
 * in Finalize->CreateInstance path)
 * Singleton: DAT_1408c59a0
 * Vtable: first qword of allocated object (INFERRED, dtor calls (**vtable)(this,1))
 *
 * Pad sizes computed so every static_assert below passes with #pragma pack(1).
 * Proven offsets: +0x018 render_texture, +0x038 camera_ptr, +0x470 cascade_rects,
 * +0x570 current_cascade_idx, +0x588 cascade_count.
 *
 * Field order must be strictly ascending by offset. Each pad fills the gap
 * between the previous field's end and the next field's start.
 */
#pragma pack(push, 1)
typedef struct {
    uint64_t vtable;                  /* +0x000 (INFERRED: dtor dispatch) */
    uint8_t pad_008[0x010];           /* +0x008..+0x017 (UNKNOWN) */
    void *render_texture;             /* +0x018 (PRES: Initialize stores LockRenderTexture result) */
    uint8_t pad_020[0x018];           /* +0x020..+0x037 (UNKNOWN) */
    void *camera_ptr;                 /* +0x038 (PRES: SetCameraView stores param_2) */
    uint8_t pad_040[0x0D0];           /* +0x040..+0x10F (view/proj/light matrices region) */
    uint8_t matrix_block[0x200];      /* +0x110..+0x30F (PRES: Matrix44 arrays stride 0x40) */
    uint8_t pad_310[0x130];           /* +0x310..+0x43F (transpose targets, cascade data) */
    float cascade_base;               /* +0x440 (PRES: UpdateMatrix reads/writes) */
    uint8_t pad_444[0x00C];           /* +0x444..+0x44F (aligns next int to +0x450) */
    int32_t cascade_index_cur;        /* +0x450 (PRES: *(param_1+0x450)=0 in UpdateMatrix) */
    float cascade_splits[4];          /* +0x454..+0x463 (PRES: pfVar13[-5]/[-4], 4xfloat) */
    float shadow_bias;                /* +0x464 (PRES: adjusted from decomp context) */
    uint8_t pad_468[0x008];           /* +0x468..+0x46F (aligns cascade_rects to +0x470) */
    nucc_Vector4 cascade_rects[16];   /* +0x470..+0x56F (PRES: Set writes stride 0x10, 16 entries) */
    int32_t current_cascade_idx;      /* +0x570 (PRES: loop counter in CreateShadowTexture) */
    uint8_t pad_574[0x014];           /* +0x574..+0x587 (UNKNOWN) */
    int32_t cascade_count;            /* +0x588 (PRES: loop bound in CreateShadowTexture) */
    uint8_t pad_58C[0x004];           /* +0x58C..+0x58F (pad to 0x590) */
} nucc_ShadowProjection;
#pragma pack(pop)

static_assert(sizeof(nucc_ShadowProjection) == 0x590, "ShadowProjection size");
static_assert(offsetof(nucc_ShadowProjection, vtable) == 0x000, "SP vtable offset");
static_assert(offsetof(nucc_ShadowProjection, pad_008) == 0x008, "SP pad_008 offset");
static_assert(offsetof(nucc_ShadowProjection, render_texture) == 0x018, "SP render_texture offset");
static_assert(offsetof(nucc_ShadowProjection, pad_020) == 0x020, "SP pad_020 offset");
static_assert(offsetof(nucc_ShadowProjection, camera_ptr) == 0x038, "SP camera_ptr offset");
static_assert(offsetof(nucc_ShadowProjection, pad_040) == 0x040, "SP pad_040 offset");
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