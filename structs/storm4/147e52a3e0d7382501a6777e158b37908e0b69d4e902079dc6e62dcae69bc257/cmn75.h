/* cmn75 s4: Common struct group — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe)
 * Build: s4  SHA256: 75912b... (see the decompiler cache.db)
 * All results INFERRED from static analysis. Nothing CONFIRMED at runtime.
 * Compile check: gcc -fsyntax-only -x c -std=c11 cmn75.h
 *
 * Size proofs (operator_new in s4 decompilations):
 *   nummModel          0x30  operator_new(0x30) in nummModelManager::ModelLoad (RVA 0x9FB830)
 *   nummModelObject    0x50  operator_new(0x50) in nummModel::Create (RVA 0x9FAB20)
 *   nummModelPrimitive 0x50  operator_new(0x50) in nummModel::Create (RVA 0x9FAB20)
 *   nummModelMaterial  0x148 operator_new(0x148) in nummModelPrimitive::Create (RVA 0x9F90F0)
 *   nummMakeNudVertex  >=0x74 state_surface fields to +0x70; no operator_new found
 *   nummModelManager   >=0x20 hashtable fields at +0x08/+0x10/+0x18; no operator_new for manager itself
 *   nummNSHHeader      >=0x18 eastl::vector-like 3 pointers; no size proof
 *   nummNudInfo        >=0x08 dtor frees *param_1; no size proof
 *
 * Vtables (s4):
 *   nummModel          PTR_FUN_141103398  (set in ModelLoad)
 *   mmIndexData        PTR_FUN_141103258  (set in Primitive::Create)
 */
#ifndef CMN75_S4_H
#define CMN75_S4_H

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

/* nummModel — proven size 0x30 from operator_new(0x30) in nummModelManager::ModelLoad (RVA 0x9FB830)
 * vtable PTR_FUN_141103398 set in ModelLoad after allocation.
 * Layout from nummModel::Create (RVA 0x9FAB20): objects vector at +0x08/+0x10/+0x18,
 * refcount at +0x28, format_param at +0x2C. */
typedef struct __attribute__((packed)) nummModel {
    uint64_t vtable;              /* +0x00  PTR_FUN_141103398 set in ModelLoad */
    uint64_t objects_begin;       /* +0x08  eastl::vector<nummModelObject*> begin */
    uint64_t objects_end;         /* +0x10  eastl::vector end */
    uint64_t objects_capacity;    /* +0x18  eastl::vector capacity */
    uint8_t  _pad_20[8];          /* +0x20  gap between vector and refcount */
    uint32_t refcount;            /* +0x28  incremented in Create/ModelLoad, read in ForceRelease */
    uint32_t format_param;        /* +0x2C  *(param_1+0x2c)=param_3 in Create */
} nummModel;
static_assert(offsetof(nummModel, vtable) == 0x00, "nummModel.vtable");
static_assert(offsetof(nummModel, objects_begin) == 0x08, "nummModel.objects_begin");
static_assert(offsetof(nummModel, objects_end) == 0x10, "nummModel.objects_end");
static_assert(offsetof(nummModel, objects_capacity) == 0x18, "nummModel.objects_capacity");
static_assert(offsetof(nummModel, refcount) == 0x28, "nummModel.refcount");
static_assert(offsetof(nummModel, format_param) == 0x2C, "nummModel.format_param");
static_assert(sizeof(nummModel) == 0x30, "nummModel size");

/* nummModelObject — proven size 0x50 from operator_new(0x50) in nummModel::Create (RVA 0x9FAB20)
 * Layout from Create: puVar9 = allocated object, fields copied from nuccNudInfo::GetObject.
 * prims vector at puVar9[6]/[7]/[8] = +0x30/+0x38/+0x40. */
typedef struct __attribute__((packed)) nummModelObject {
    uint64_t field_00;            /* +0x00  copied from nuccNudInfo object[0] */
    uint64_t field_08;            /* +0x08  copied from nuccNudInfo object[1] */
    uint32_t field_10;            /* +0x10  *(puVar8+2) bounding sphere / pos data */
    uint32_t field_14;            /* +0x14  *(longlong)(puVar8+0x14) */
    uint32_t field_18;            /* +0x18  *(puVar8+3) */
    uint32_t field_1c;            /* +0x1C  *(longlong)(puVar8+0x1c) */
    uint32_t field_20;            /* +0x20  *(puVar8+4) */
    uint32_t field_24;            /* +0x24  *(longlong)(puVar8+0x24) */
    uint32_t field_28;            /* +0x28  *(puVar8+5) */
    uint32_t field_2c;            /* +0x2C  *(longlong)(puVar8+0x2c) */
    uint64_t prims_begin;         /* +0x30  eastl::vector<nummModelPrimitive*> begin (puVar9[6]) */
    uint64_t prims_end;           /* +0x38  vector end (puVar9[7]) */
    uint64_t prims_capacity;      /* +0x40  vector capacity (puVar9[8]) */
    uint8_t  _pad_48[8];          /* +0x48  padding to 0x50 */
} nummModelObject;
static_assert(offsetof(nummModelObject, field_00) == 0x00, "nummModelObject.field_00");
static_assert(offsetof(nummModelObject, field_08) == 0x08, "nummModelObject.field_08");
static_assert(offsetof(nummModelObject, field_10) == 0x10, "nummModelObject.field_10");
static_assert(offsetof(nummModelObject, field_14) == 0x14, "nummModelObject.field_14");
static_assert(offsetof(nummModelObject, field_18) == 0x18, "nummModelObject.field_18");
static_assert(offsetof(nummModelObject, field_1c) == 0x1c, "nummModelObject.field_1c");
static_assert(offsetof(nummModelObject, field_20) == 0x20, "nummModelObject.field_20");
static_assert(offsetof(nummModelObject, field_24) == 0x24, "nummModelObject.field_24");
static_assert(offsetof(nummModelObject, field_28) == 0x28, "nummModelObject.field_28");
static_assert(offsetof(nummModelObject, field_2c) == 0x2c, "nummModelObject.field_2c");
static_assert(offsetof(nummModelObject, prims_begin) == 0x30, "nummModelObject.prims_begin");
static_assert(offsetof(nummModelObject, prims_end) == 0x38, "nummModelObject.prims_end");
static_assert(offsetof(nummModelObject, prims_capacity) == 0x40, "nummModelObject.prims_capacity");
static_assert(sizeof(nummModelObject) == 0x50, "nummModelObject size");

/* nummModelPrimitive — proven size 0x50 from operator_new(0x50) in nummModel::Create inner loop
 * Note: this is the container allocated per-primitive in the model create loop.
 * Vertex data (0xb0 mmVertexDataBase) and index data (0x48 mmIndexData) are separate allocations
 * stored as pointers at +0x00 and +0x08.
 * Layout from Primitive::Create (RVA 0x9F90F0): param_1 is longlong*, so param_1[N] = +N*8.
 *   param_1[0] = vertex_data ptr, param_1[1] = index_data ptr
 *   param_1[3..5] = materials vector (+0x18/+0x20/+0x28)
 *   *(param_1+7) = flags at +0x38 (uint), but state_surface shows skin_matrix_idx at +0x3C (rw)
 *   *(longlong)(param_1+0x44) = index_format at +0x44 (w)
 * State surface also shows read at +0x80 (low confidence, indirect access). */
typedef struct __attribute__((packed)) nummModelPrimitive {
    uint64_t vertex_data;         /* +0x00  mmVertexDataBase* from operator_new(0xb0) */
    uint64_t index_data;          /* +0x08  mmIndexData* from operator_new(0x48), vtable PTR_FUN_141103258 */
    uint64_t crit_section;        /* +0x10  NUMM_THREAD_CRITICAL_SECTION_CONTEXT* (inferred from s3) */
    uint64_t materials_begin;     /* +0x18  eastl::vector<nummModelMaterial*> begin (param_1[3]) */
    uint64_t materials_end;       /* +0x20  vector end (param_1[4]) */
    uint64_t materials_capacity;  /* +0x28  vector capacity (param_1[5]) */
    uint8_t  _pad_30[12];         /* +0x30  gap before skin_matrix_idx */
    uint32_t skin_matrix_idx;     /* +0x3C  rw in Create/DrawSkin: *(int*)(param_1+0x3c)=*param_6 */
    uint32_t field_40;            /* +0x40  gap fill */
    uint32_t index_format;        /* +0x44  w in Create: *(undefined4*)(param_1+0x44)=param_4 */
    uint8_t  _pad_48[8];          /* +0x48  padding to 0x50 */
} nummModelPrimitive;
static_assert(offsetof(nummModelPrimitive, vertex_data) == 0x00, "nummModelPrimitive.vertex_data");
static_assert(offsetof(nummModelPrimitive, index_data) == 0x08, "nummModelPrimitive.index_data");
static_assert(offsetof(nummModelPrimitive, crit_section) == 0x10, "nummModelPrimitive.crit_section");
static_assert(offsetof(nummModelPrimitive, materials_begin) == 0x18, "nummModelPrimitive.materials_begin");
static_assert(offsetof(nummModelPrimitive, materials_end) == 0x20, "nummModelPrimitive.materials_end");
static_assert(offsetof(nummModelPrimitive, materials_capacity) == 0x28, "nummModelPrimitive.materials_capacity");
static_assert(offsetof(nummModelPrimitive, skin_matrix_idx) == 0x3C, "nummModelPrimitive.skin_matrix_idx");
static_assert(offsetof(nummModelPrimitive, field_40) == 0x40, "nummModelPrimitive.field_40");
static_assert(offsetof(nummModelPrimitive, index_format) == 0x44, "nummModelPrimitive.index_format");
static_assert(sizeof(nummModelPrimitive) == 0x50, "nummModelPrimitive size");

/* nummModelMaterial — proven size 0x148 from operator_new(0x148) in nummModelPrimitive::Create (RVA 0x9F90F0)
 * Layout from Material::Create (RVA 0x9FF970) and state_surface:
 *   param_1[0] = render_state_data, param_1[1] = render_state_flags
 *   param_1[2] = material_headers_ptr (texture headers, 0x30 each)
 *   param_1[6..8] = shader_params vector (eastl::vector<ShaderParameter>)
 *   param_1[0xe] = shader_obj_vs (mmShaderResourceBindList* from operator_new(0xf8))
 *   param_1[0xf] = shader_obj_ps (mmShaderResourceBindList* from operator_new(0xf8))
 *   param_1[0x10] = const_buf_alloc (mmEngineMalloc(0x40))
 *   param_1[0x11] = shader_handle (mmConstantBuffer* from operator_new(0x30))
 *   param_1[0x14] = shader_cache_entry (hashtable lookup result)
 *   param_1[0x15] = shader_buffer_binder (embedded mmShaderBufferBinder, Register call)
 * State surface confirms reads at +0x70,+0x78,+0x88,+0x90,+0xA0,+0xA8. */
typedef struct __attribute__((packed)) nummModelMaterial {
    uint64_t render_state_data;   /* +0x00  mmRenderStateData* (param_1[0], SetRenderState target) */
    uint64_t render_state_flags;  /* +0x08  ~*(uint*)(this+1)&0x280000 flag mask */
    uint64_t material_headers_ptr;/* +0x10  pointer to 0x30-byte texture headers (param_1[2]) */
    uint64_t tex_params_begin;    /* +0x18  eastl::rbtree tex params begin (inferred from s3 layout) */
    uint64_t tex_params_end;      /* +0x20  rbtree end */
    uint64_t tex_params_cap;      /* +0x28  rbtree node/capacity */
    uint64_t const_buf_tree_begin;/* +0x30  eastl::rbtree const buf begin */
    uint64_t const_buf_tree_end;  /* +0x38  rbtree end */
    uint64_t const_buf_tree_cap;  /* +0x40  rbtree cap */
    uint64_t shader_params_begin; /* +0x48  eastl::vector<ShaderParameter> begin (param_1[6]) */
    uint64_t shader_params_end;   /* +0x50  vector end (param_1[7]) */
    uint64_t shader_params_cap;   /* +0x58  vector capacity */
    uint64_t shader_node_data;    /* +0x60  material node data ptr (param_1[0xc]) */
    uint64_t shader_node_extra;   /* +0x68  (param_1[0xd]) */
    uint64_t shader_obj_vs;       /* +0x70  mmShaderResourceBindList* VS from operator_new(0xf8) (param_1[0xe]) */
    uint64_t shader_obj_ps;       /* +0x78  mmShaderResourceBindList* PS from operator_new(0xf8) (param_1[0xf]) */
    uint64_t const_buf_alloc;     /* +0x80  mmEngineMalloc(0x40) result (param_1[0x10]) */
    uint64_t shader_handle;       /* +0x88  mmConstantBuffer* from operator_new(0x30) (param_1[0x11]) */
    uint64_t field_90;            /* +0x90  dtor reads param_1+0x12 → embedded obj or ptr */
    uint64_t field_98;            /* +0x98  gap fill */
    uint64_t shader_cache_entry;  /* +0xA0  hashtable lookup result (param_1[0x14]) */
    uint8_t  shader_buffer_binder[32]; /* +0xA8  embedded mmShaderBufferBinder (Register at param_1+0x15) */
    uint64_t material_hdr_copy0;  /* +0xC8  *(undefined8*)local_b0 (param_1[10]) */
    uint64_t material_hdr_copy1;  /* +0xD0  *(local_b0+2) (param_1[0xb]) */
    uint64_t material_hdr_copy2;  /* +0xD8  *(local_b0+4) (param_1[0xc]) */
    uint64_t material_hdr_copy3;  /* +0xE0  *(local_b0+6) (param_1[0xd]) */
    uint8_t  _pad_e8[96];         /* +0xE8  padding to 0x148 */
} nummModelMaterial;
static_assert(offsetof(nummModelMaterial, render_state_data) == 0x00, "nummModelMaterial.render_state_data");
static_assert(offsetof(nummModelMaterial, render_state_flags) == 0x08, "nummModelMaterial.render_state_flags");
static_assert(offsetof(nummModelMaterial, material_headers_ptr) == 0x10, "nummModelMaterial.material_headers_ptr");
static_assert(offsetof(nummModelMaterial, tex_params_begin) == 0x18, "nummModelMaterial.tex_params_begin");
static_assert(offsetof(nummModelMaterial, tex_params_end) == 0x20, "nummModelMaterial.tex_params_end");
static_assert(offsetof(nummModelMaterial, tex_params_cap) == 0x28, "nummModelMaterial.tex_params_cap");
static_assert(offsetof(nummModelMaterial, const_buf_tree_begin) == 0x30, "nummModelMaterial.const_buf_tree_begin");
static_assert(offsetof(nummModelMaterial, const_buf_tree_end) == 0x38, "nummModelMaterial.const_buf_tree_end");
static_assert(offsetof(nummModelMaterial, const_buf_tree_cap) == 0x40, "nummModelMaterial.const_buf_tree_cap");
static_assert(offsetof(nummModelMaterial, shader_params_begin) == 0x48, "nummModelMaterial.shader_params_begin");
static_assert(offsetof(nummModelMaterial, shader_params_end) == 0x50, "nummModelMaterial.shader_params_end");
static_assert(offsetof(nummModelMaterial, shader_params_cap) == 0x58, "nummModelMaterial.shader_params_cap");
static_assert(offsetof(nummModelMaterial, shader_node_data) == 0x60, "nummModelMaterial.shader_node_data");
static_assert(offsetof(nummModelMaterial, shader_node_extra) == 0x68, "nummModelMaterial.shader_node_extra");
static_assert(offsetof(nummModelMaterial, shader_obj_vs) == 0x70, "nummModelMaterial.shader_obj_vs");
static_assert(offsetof(nummModelMaterial, shader_obj_ps) == 0x78, "nummModelMaterial.shader_obj_ps");
static_assert(offsetof(nummModelMaterial, const_buf_alloc) == 0x80, "nummModelMaterial.const_buf_alloc");
static_assert(offsetof(nummModelMaterial, shader_handle) == 0x88, "nummModelMaterial.shader_handle");
static_assert(offsetof(nummModelMaterial, field_90) == 0x90, "nummModelMaterial.field_90");
static_assert(offsetof(nummModelMaterial, field_98) == 0x98, "nummModelMaterial.field_98");
static_assert(offsetof(nummModelMaterial, shader_cache_entry) == 0xa0, "nummModelMaterial.shader_cache_entry");
static_assert(offsetof(nummModelMaterial, shader_buffer_binder) == 0xa8, "nummModelMaterial.shader_buffer_binder");
static_assert(offsetof(nummModelMaterial, material_hdr_copy0) == 0xc8, "nummModelMaterial.material_hdr_copy0");
static_assert(offsetof(nummModelMaterial, material_hdr_copy1) == 0xd0, "nummModelMaterial.material_hdr_copy1");
static_assert(offsetof(nummModelMaterial, material_hdr_copy2) == 0xd8, "nummModelMaterial.material_hdr_copy2");
static_assert(offsetof(nummModelMaterial, material_hdr_copy3) == 0xe0, "nummModelMaterial.material_hdr_copy3");
static_assert(sizeof(nummModelMaterial) == 0x148, "nummModelMaterial size");

/* nummMakeNudVertex — size >= 0x74 from state_surface fields to +0x70; no operator_new found.
 * State surface (SetType + ctor) shows writes at +0x2C,+0x30,+0x34,+0x38,+0x3C,+0x40,+0x44,+0x58,+0x60,+0x68,+0x70.
 * Base 0x00-0x2B unknown (possibly vtable + inherited fields). */
typedef struct __attribute__((packed)) nummMakeNudVertex {
    uint8_t  _pad_00[44];         /* +0x00  unknown base (vtable or inherited fields) */
    uint32_t field_2c;            /* +0x2C  w high conf: param_1[0xb]=4 in SetType */
    uint32_t field_30;            /* +0x30  w low conf: param_1[0xc]=1 in SetType (size 4 or 8) */
    uint32_t field_34;            /* +0x34  w high conf: param_1[0xd]=4 in SetType */
    uint32_t field_38;            /* +0x38  w high conf: param_1[0xe]=param_3>>4&0xf in SetType */
    uint32_t field_3c;            /* +0x3C  w low conf: *(undefined8*)(param_1+0xf)=0 (size 4 or 8) */
    uint32_t field_40;            /* +0x40  w medium conf: param_1[0x10]=0x20 in SetType */
    uint64_t field_44;            /* +0x44  w medium conf: *(undefined8*)(param_1+0x44)=0 in ctor */
    uint8_t  _pad_4c[12];         /* +0x4C  gap between +0x44 and +0x58 */
    uint64_t field_58;            /* +0x58  w medium conf: param_1[0xb]=0 in ctor */
    uint64_t field_60;            /* +0x60  w medium conf: param_1[0xc]=0 in ctor */
    uint32_t field_68;            /* +0x68  w medium conf: *(undefined4*)(param_1+0xd)=0 in ctor */
    uint8_t  _pad_6c[4];          /* +0x6C  gap */
    uint64_t field_70;            /* +0x70  w medium conf: param_1[0xe]=0 in ctor */
} nummMakeNudVertex;
static_assert(offsetof(nummMakeNudVertex, field_2c) == 0x2c, "nummMakeNudVertex.field_2c");
static_assert(offsetof(nummMakeNudVertex, field_30) == 0x30, "nummMakeNudVertex.field_30");
static_assert(offsetof(nummMakeNudVertex, field_34) == 0x34, "nummMakeNudVertex.field_34");
static_assert(offsetof(nummMakeNudVertex, field_38) == 0x38, "nummMakeNudVertex.field_38");
static_assert(offsetof(nummMakeNudVertex, field_3c) == 0x3c, "nummMakeNudVertex.field_3c");
static_assert(offsetof(nummMakeNudVertex, field_40) == 0x40, "nummMakeNudVertex.field_40");
static_assert(offsetof(nummMakeNudVertex, field_44) == 0x44, "nummMakeNudVertex.field_44");
static_assert(offsetof(nummMakeNudVertex, field_58) == 0x58, "nummMakeNudVertex.field_58");
static_assert(offsetof(nummMakeNudVertex, field_60) == 0x60, "nummMakeNudVertex.field_60");
static_assert(offsetof(nummMakeNudVertex, field_68) == 0x68, "nummMakeNudVertex.field_68");
static_assert(offsetof(nummMakeNudVertex, field_70) == 0x70, "nummMakeNudVertex.field_70");
static_assert(sizeof(nummMakeNudVertex) == 0x78, "nummMakeNudVertex size");

/* nummNSHHeader — size >= 0x18 from eastl::vector-like 3 pointers; no size proof.
 * Used via nummNSHHeader::IsFormatError(param_1+8,...) in nummModel::Create, suggesting
 * it may be embedded at offset 8 within another struct or passed by pointer. */
typedef struct __attribute__((packed)) nummNSHHeader {
    uint64_t data_begin;          /* +0x00  vector begin pointer */
    uint64_t data_end;            /* +0x08  vector end pointer */
    uint64_t data_capacity;       /* +0x10  vector capacity pointer */
} nummNSHHeader;
static_assert(offsetof(nummNSHHeader, data_begin) == 0x00, "nummNSHHeader.data_begin");
static_assert(offsetof(nummNSHHeader, data_end) == 0x08, "nummNSHHeader.data_end");
static_assert(offsetof(nummNSHHeader, data_capacity) == 0x10, "nummNSHHeader.data_capacity");
static_assert(sizeof(nummNSHHeader) == 0x18, "nummNSHHeader size");

/* nummNudInfo — size >= 0x08 from dtor freeing *param_1.
 * Only method with field access is ~nummNudInfo which frees the data pointer. */
typedef struct __attribute__((packed)) nummNudInfo {
    uint64_t data_ptr;            /* +0x00  heap pointer freed in ~nummNudInfo */
} nummNudInfo;
static_assert(offsetof(nummNudInfo, data_ptr) == 0x00, "nummNudInfo.data_ptr");
static_assert(sizeof(nummNudInfo) == 0x08, "nummNudInfo size");

/* nummModelManager — size >= 0x20 from hashtable fields in ModelLoad; no operator_new for manager itself.
 * ModelLoad accesses param_1+0x10 (buckets ptr), param_1+0x18 (bucket count),
 * and calls DoInsertValue(param_1+8,...) for the hashtable. */
typedef struct __attribute__((packed)) nummModelManager {
    uint64_t _pad_00;             /* +0x00  unknown (possibly vtable or allocator) */
    uint64_t hashtable;           /* +0x08  eastl::hashtable ptr (DoInsertValue target) */
    uint64_t buckets;             /* +0x10  bucket array ptr (param_1+0x10 in ModelLoad) */
    uint64_t bucket_count;        /* +0x18  bucket count (param_1+0x18 in ModelLoad) */
} nummModelManager;
static_assert(offsetof(nummModelManager, hashtable) == 0x08, "nummModelManager.hashtable");
static_assert(offsetof(nummModelManager, buckets) == 0x10, "nummModelManager.buckets");
static_assert(offsetof(nummModelManager, bucket_count) == 0x18, "nummModelManager.bucket_count");
static_assert(sizeof(nummModelManager) == 0x20, "nummModelManager size");

#endif /* CMN75_S4_H */