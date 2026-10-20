/* cmn75.h — Common struct group cmn75 for build s2 (NARUTO STORM 2 PC)
 * INFERRED from static analysis of NSUNS2.exe (sha256: 697488011750...)
 * All offsets proven from x64 decompiled code. Sizes proven from operator_new
 * arguments where available. Everything is INFERRED, not CONFIRMED.
 * Own-game names only: Storm 2 sources (ns2::, strings, code).
 */
#ifndef CMN75_S2_H
#define CMN75_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nummModel — size 0x30 (FUN_1401523b0(0x30) in nummModelManager::ModelLoad)
 * vtable: PTR_FUN_14088d2d8
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModel {
    uint64_t vtable;              /* +0x00: PTR_FUN_14088d2d8 */
    uint64_t objects_begin;       /* +0x08: eastl::vector begin ptr */
    uint64_t objects_end;         /* +0x10: eastl::vector end ptr */
    uint64_t objects_capacity;    /* +0x18: eastl::vector capacity ptr */
    uint64_t shader_related;      /* +0x20: written in Create, read in Draw */
    int32_t  refcount;            /* +0x28: incremented in Create */
    uint32_t format_param;        /* +0x2C: passed to constructor */
} nummModel;

static_assert(offsetof(nummModel, vtable)           == 0x00, "nummModel.vtable");
static_assert(offsetof(nummModel, objects_begin)     == 0x08, "nummModel.objects_begin");
static_assert(offsetof(nummModel, objects_end)       == 0x10, "nummModel.objects_end");
static_assert(offsetof(nummModel, objects_capacity)  == 0x18, "nummModel.objects_capacity");
static_assert(offsetof(nummModel, shader_related)    == 0x20, "nummModel.shader_related");
static_assert(offsetof(nummModel, refcount)          == 0x28, "nummModel.refcount");
static_assert(offsetof(nummModel, format_param)      == 0x2C, "nummModel.format_param");
static_assert(sizeof(nummModel)                      == 0x30, "nummModel size");

/* =========================================================================
 * nummModelObject — size 0x50 (FUN_1401523b0(0x50) in nummModel::Create)
 * vtable: not directly observed; allocated inline without vtable set
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelObject {
    uint64_t _pad_00;            /* +0x00: zeroed in Create */
    uint64_t _pad_08;            /* +0x08: zeroed in Create */
    float    pos_x;              /* +0x10: bounding sphere center X */
    float    pos_y;              /* +0x14: bounding sphere center Y */
    float    pos_z;              /* +0x18: bounding sphere center Z */
    float    bounds_radius;      /* +0x1C: bounding sphere radius */
    uint32_t field_20;           /* +0x20: copied from source object */
    uint32_t field_24;           /* +0x24: copied from source object */
    uint32_t field_28;           /* +0x28: copied from source object */
    uint32_t field_2c;           /* +0x2C: copied from source object */
    uint64_t prims_begin;        /* +0x30: eastl::vector<prim*> begin */
    uint64_t prims_end;          /* +0x38: eastl::vector<prim*> end */
    uint64_t prims_capacity;     /* +0x40: eastl::vector<prim*> capacity */
    uint8_t  _pad_48[0x08];      /* +0x48: tail padding to 0x50 */
} nummModelObject;

static_assert(offsetof(nummModelObject, pos_x)         == 0x10, "nummModelObject.pos_x");
static_assert(offsetof(nummModelObject, pos_y)         == 0x14, "nummModelObject.pos_y");
static_assert(offsetof(nummModelObject, pos_z)         == 0x18, "nummModelObject.pos_z");
static_assert(offsetof(nummModelObject, bounds_radius) == 0x1C, "nummModelObject.bounds_radius");
static_assert(offsetof(nummModelObject, field_20)      == 0x20, "nummModelObject.field_20");
static_assert(offsetof(nummModelObject, field_24)      == 0x24, "nummModelObject.field_24");
static_assert(offsetof(nummModelObject, field_28)      == 0x28, "nummModelObject.field_28");
static_assert(offsetof(nummModelObject, field_2c)      == 0x2C, "nummModelObject.field_2c");
static_assert(offsetof(nummModelObject, prims_begin)   == 0x30, "nummModelObject.prims_begin");
static_assert(offsetof(nummModelObject, prims_end)     == 0x38, "nummModelObject.prims_end");
static_assert(offsetof(nummModelObject, prims_capacity)== 0x40, "nummModelObject.prim_capacity");
static_assert(sizeof(nummModelObject)                  == 0x50, "nummModelObject size");

/* =========================================================================
 * nummModelPrimitive — size unknown, >= 0x4C
 * From Primitive::Create (param_1 is longlong*):
 *   param_1[0] = +0x00 vertex_data (mmVertexDataBase*, FUN_1401523b0 0xb0)
 *   param_1[1] = +0x08 index_data (mmIndexData*, FUN_1401523b0 0x48,
 *                vtable PTR_FUN_14088e4f0)
 *   param_1[2] = +0x10 crit_section (NUMM_THREAD_CRITICAL_SECTION_CONTEXT*)
 *   param_1[3] = +0x18 materials_begin (eastl::vector<material*> begin)
 *   param_1[4] = +0x20 materials_end (eastl::vector<material*> end)
 *   *(uint*)(param_1+7) = +0x38 flags (*(ushort*)(nud+0x22) & 3)
 *   *(int*)((longlong)param_1+0x3c) = skin_matrix_idx
 *   *(uint*)(param_1+8) = +0x40 field_40 (param_3)
 *   *(uint*)((longlong)param_1+0x44) = index_format (param_4)
 *   *(uint*)(param_1+9) = +0x48 field_48 (param_5)
 * No direct operator_new for this struct itself.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelPrimitive {
    uint64_t vertex_data;        /* +0x00: mmVertexDataBase* */
    uint64_t index_data;         /* +0x08: mmIndexData* */
    uint64_t crit_section;       /* +0x10: NUMM_THREAD_CRITICAL_SECTION_CONTEXT* */
    uint64_t materials_begin;    /* +0x18: eastl::vector<material*> begin */
    uint64_t materials_end;      /* +0x20: eastl::vector<material*> end */
    uint64_t materials_capacity; /* +0x28: inferred vector capacity slot */
    uint8_t  _pad_30[0x08];      /* +0x30: gap */
    uint32_t flags;              /* +0x38: prim type flags */
    uint32_t skin_matrix_idx;    /* +0x3C: skin matrix index when skinned */
    uint32_t field_40;           /* +0x40: param_3 from Create */
    uint32_t index_format;       /* +0x44: param_4 from Create */
    uint32_t field_48;           /* +0x48: param_5 from Create */
    uint8_t  _pad_4c[0x04];      /* +0x4C: tail padding */
} nummModelPrimitive;

static_assert(offsetof(nummModelPrimitive, vertex_data)       == 0x00, "nummModelPrimitive.vertex_data");
static_assert(offsetof(nummModelPrimitive, index_data)        == 0x08, "nummModelPrimitive.index_data");
static_assert(offsetof(nummModelPrimitive, crit_section)      == 0x10, "nummModelPrimitive.crit_section");
static_assert(offsetof(nummModelPrimitive, materials_begin)   == 0x18, "nummModelPrimitive.materials_begin");
static_assert(offsetof(nummModelPrimitive, materials_end)     == 0x20, "nummModelPrimitive.materials_end");
static_assert(offsetof(nummModelPrimitive, materials_capacity)== 0x28, "nummModelPrimitive.materials_capacity");
static_assert(offsetof(nummModelPrimitive, flags)             == 0x38, "nummModelPrimitive.flags");
static_assert(offsetof(nummModelPrimitive, skin_matrix_idx)   == 0x3C, "nummModelPrimitive.skin_matrix_idx");
static_assert(offsetof(nummModelPrimitive, field_40)          == 0x40, "nummModelPrimitive.field_40");
static_assert(offsetof(nummModelPrimitive, index_format)      == 0x44, "nummModelPrimitive.index_format");
static_assert(offsetof(nummModelPrimitive, field_48)          == 0x48, "nummModelPrimitive.field_48");
/* Size unproven; no sizeof assert. Fields proven to +0x48, so >= 0x4C. */

/* =========================================================================
 * nummModelMaterial — size 0x148 (FUN_1401523b0(0x148) in Primitive::Create)
 * Layout from Create decompile (param_1 as undefined8*):
 *   param_1[0]  = +0x00  render_state_data
 *   param_1[1]  = +0x08  render_state_flags
 *   param_1[2]  = +0x10  material_headers_ptr
 *   param_1[3..5] = +0x18..+0x28  tex_params rbtree
 *   param_1[6..8] = +0x30..+0x40  const_buf_tree rbtree
 *   param_1[9..11] = +0x48..+0x58  shader_params vector
 *   param_1[0xe] = +0x70  shader_obj1 (FUN_1401523b0 0xf8)
 *   param_1[0xf] = +0x78  shader_obj2 (FUN_1401523b0 0xf8)
 *   param_1[0x10] = +0x80  const_buf_alloc (FUN_140152340 0x40)
 *   param_1[0x11] = +0x88  shader_handle (FUN_1401523b0 0x30)
 *   param_1[0x14] = +0xA0  shader_cache_entry
 *   param_1+0x15 = +0xA8  mmShaderBufferBinder (embedded)
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelMaterial {
    uint64_t render_state_data;    /* +0x00: mmRenderStateData* */
    uint64_t render_state_flags;   /* +0x08: ~*(uint*)(this+1) & 0x280000 */
    uint64_t material_headers_ptr; /* +0x10: pointer to array of 0x30-byte headers */
    uint64_t tex_params_begin;     /* +0x18: eastl::rbtree begin */
    uint64_t tex_params_end;       /* +0x20: eastl::rbtree end */
    uint64_t tex_params_cap;       /* +0x28: eastl::rbtree capacity/node */
    uint64_t const_buf_tree_begin; /* +0x30: eastl::rbtree begin */
    uint64_t const_buf_tree_end;   /* +0x38: eastl::rbtree end */
    uint64_t const_buf_tree_cap;   /* +0x40: eastl::rbtree capacity/node */
    uint64_t shader_params_begin;  /* +0x48: eastl::vector begin */
    uint64_t shader_params_end;    /* +0x50: eastl::vector end */
    uint64_t shader_params_cap;    /* +0x58: eastl::vector capacity */
    uint8_t  _pad_60[0x10];        /* +0x60: gap */
    uint64_t shader_obj1;          /* +0x70: FUN_1401523b0(0xf8) shader object */
    uint64_t shader_obj2;          /* +0x78: FUN_1401523b0(0xf8) shader object */
    uint64_t const_buf_alloc;      /* +0x80: FUN_140152340(0x40) allocation */
    uint64_t shader_handle;        /* +0x88: FUN_1401523b0(0x30) handle */
    uint8_t  _pad_90[0x10];        /* +0x90: gap before cache entry */
    uint64_t shader_cache_entry;   /* +0xA0: hashtable lookup result */
    uint8_t  shader_buffer_binder[0x20]; /* +0xA8: mmShaderBufferBinder (embedded) */
    uint8_t  _pad_c8[0x80];        /* +0xC8: remaining embedded objects to 0x148 */
} nummModelMaterial;

static_assert(offsetof(nummModelMaterial, render_state_data)    == 0x00, "nummModelMaterial.render_state_data");
static_assert(offsetof(nummModelMaterial, render_state_flags)   == 0x08, "nummModelMaterial.render_state_flags");
static_assert(offsetof(nummModelMaterial, material_headers_ptr) == 0x10, "nummModelMaterial.material_headers_ptr");
static_assert(offsetof(nummModelMaterial, tex_params_begin)     == 0x18, "nummModelMaterial.tex_params_begin");
static_assert(offsetof(nummModelMaterial, const_buf_tree_begin) == 0x30, "nummModelMaterial.const_buf_tree_begin");
static_assert(offsetof(nummModelMaterial, shader_params_begin)  == 0x48, "nummModelMaterial.shader_params_begin");
static_assert(offsetof(nummModelMaterial, shader_obj1)          == 0x70, "nummModelMaterial.shader_obj1");
static_assert(offsetof(nummModelMaterial, shader_obj2)          == 0x78, "nummModelMaterial.shader_obj2");
static_assert(offsetof(nummModelMaterial, const_buf_alloc)      == 0x80, "nummModelMaterial.const_buf_alloc");
static_assert(offsetof(nummModelMaterial, shader_handle)        == 0x88, "nummModelMaterial.shader_handle");
static_assert(offsetof(nummModelMaterial, shader_cache_entry)   == 0xA0, "nummModelMaterial.shader_cache_entry");
static_assert(offsetof(nummModelMaterial, shader_buffer_binder) == 0xA8, "nummModelMaterial.shader_buffer_binder");
static_assert(sizeof(nummModelMaterial)                         == 0x148, "nummModelMaterial size");

/* =========================================================================
 * nummMakeNudVertex — size unknown, >= 0x74
 * 11 fields from state_surface at +0x2C through +0x70.
 * No operator_new size found; likely stack-allocated or embedded.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummMakeNudVertex {
    uint8_t  _pad_00[0x2C];      /* +0x00: unknown header */
    uint32_t field_2c;           /* +0x2C: SIM field */
    uint32_t field_30;           /* +0x30: SIM field */
    uint32_t field_34;           /* +0x34: SIM field */
    uint32_t field_38;           /* +0x38: SIM field */
    uint32_t field_3c;           /* +0x3C: SIM field */
    uint32_t field_40;           /* +0x40: SIM field */
    uint32_t field_44;           /* +0x44: SIM field */
    uint8_t  _pad_48[0x10];      /* +0x48: gap (state_surface skipped) */
    uint32_t field_58;           /* +0x58: SIM field */
    uint8_t  _pad_5c[0x04];      /* +0x5C: gap */
    uint32_t field_60;           /* +0x60: SIM field */
    uint8_t  _pad_64[0x04];      /* +0x64: gap */
    uint32_t field_68;           /* +0x68: SIM field */
    uint8_t  _pad_6c[0x04];      /* +0x6C: gap */
    uint32_t field_70;           /* +0x70: SIM field */
} nummMakeNudVertex;

static_assert(offsetof(nummMakeNudVertex, field_2c) == 0x2C, "nummMakeNudVertex.field_2c");
static_assert(offsetof(nummMakeNudVertex, field_30) == 0x30, "nummMakeNudVertex.field_30");
static_assert(offsetof(nummMakeNudVertex, field_34) == 0x34, "nummMakeNudVertex.field_34");
static_assert(offsetof(nummMakeNudVertex, field_38) == 0x38, "nummMakeNudVertex.field_38");
static_assert(offsetof(nummMakeNudVertex, field_3c) == 0x3C, "nummMakeNudVertex.field_3c");
static_assert(offsetof(nummMakeNudVertex, field_40) == 0x40, "nummMakeNudVertex.field_40");
static_assert(offsetof(nummMakeNudVertex, field_44) == 0x44, "nummMakeNudVertex.field_44");
static_assert(offsetof(nummMakeNudVertex, field_58) == 0x58, "nummMakeNudVertex.field_58");
static_assert(offsetof(nummMakeNudVertex, field_60) == 0x60, "nummMakeNudVertex.field_60");
static_assert(offsetof(nummMakeNudVertex, field_68) == 0x68, "nummMakeNudVertex.field_68");
static_assert(offsetof(nummMakeNudVertex, field_70) == 0x70, "nummMakeNudVertex.field_70");
/* Size unproven; no sizeof assert */

/* =========================================================================
 * nummNSHHeader — size unknown, >= 0x18
 * eastl::vector-like: 3 pointers.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummNSHHeader {
    uint64_t data_begin;         /* +0x00: vector begin pointer */
    uint64_t data_end;           /* +0x08: vector end pointer */
    uint64_t data_capacity;      /* +0x10: vector capacity pointer */
} nummNSHHeader;

static_assert(offsetof(nummNSHHeader, data_begin)    == 0x00, "nummNSHHeader.data_begin");
static_assert(offsetof(nummNSHHeader, data_end)      == 0x08, "nummNSHHeader.data_end");
static_assert(offsetof(nummNSHHeader, data_capacity) == 0x10, "nummNSHHeader.data_capacity");
/* Size unproven; no sizeof assert */

/* =========================================================================
 * nummNudInfo — size unknown, >= 0x08
 * Simple wrapper: destructor frees *param_1.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummNudInfo {
    uint64_t data_ptr;           /* +0x00: pointer freed in dtor */
} nummNudInfo;

static_assert(offsetof(nummNudInfo, data_ptr) == 0x00, "nummNudInfo.data_ptr");
/* Size unproven; no sizeof assert */

/* =========================================================================
 * nummModelManager — size unknown, >= 0x20
 * Hashtable wrapper. ModelLoad accesses param_1+0x10 and param_1+0x18.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelManager {
    uint8_t  _pad_00[0x08];      /* +0x00: possible vtable or flags */
    uint64_t hashtable;          /* +0x08: eastl::hashtable pointer */
    uint64_t buckets;            /* +0x10: bucket array pointer */
    uint64_t bucket_count;       /* +0x18: number of buckets */
} nummModelManager;

static_assert(offsetof(nummModelManager, hashtable)    == 0x08, "nummModelManager.hashtable");
static_assert(offsetof(nummModelManager, buckets)      == 0x10, "nummModelManager.buckets");
static_assert(offsetof(nummModelManager, bucket_count) == 0x18, "nummModelManager.bucket_count");
/* Size unproven; no sizeof assert */

#endif /* CMN75_S2_H */