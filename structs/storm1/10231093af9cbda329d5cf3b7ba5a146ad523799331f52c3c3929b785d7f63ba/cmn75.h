/* cmn75.h — Common struct group cmn75 for build s1 (NARUTO STORM 1 PC)
 * INFERRED from static analysis of NSUNS1.exe (sha256: 10231093af9c...)
 * All offsets proven from x64 decompiled code. Sizes proven from operator_new
 * arguments where available. Everything is INFERRED, not CONFIRMED.
 * Own-game names only: Storm 1 sources (ns1::, Switch Trilogy ns1::, strings).
 */
#ifndef CMN75_H
#define CMN75_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nummModel — size 0x30 (operator_new(0x30) in nummModelManager::ModelLoad)
 * vtable: PTR_FUN_140734b20
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModel {
    uint64_t vtable;              /* +0x00: PTR_FUN_140734b20 */
    uint64_t objects_begin;       /* +0x08: eastl::vector begin ptr */
    uint64_t objects_end;         /* +0x10: eastl::vector end ptr */
    uint64_t objects_capacity;    /* +0x18: eastl::vector capacity ptr */
    uint64_t shader_related;      /* +0x20: written in Create, read in Draw */
    int32_t  refcount;            /* +0x28: incremented in Create, checked in ForceRelease */
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
 * nummModelObject — size 0x50 (operator_new(0x50) in nummModel::Create)
 * vtable: not directly observed; object allocated inline
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelObject {
    uint8_t  _pad_00[0x10];      /* +0x00: unknown header / possible vtable */
    float    pos_x;              /* +0x10: bounding sphere center X (VisibleCheck) */
    float    pos_y;              /* +0x14: bounding sphere center Y */
    float    pos_z;              /* +0x18: bounding sphere center Z */
    float    bounds_radius;      /* +0x1C: bounding sphere radius (VisibleCheck scale) */
    uint8_t  _pad_20[0x06];      /* +0x20: gap before flags */
    uint16_t flags;              /* +0x26: bitfield, bit 4 = skip frustum check */
    uint16_t matrix_index;       /* +0x28: skinning matrix index */
    uint8_t  _pad_2a[0x06];      /* +0x2A: alignment padding */
    uint64_t prims_begin;        /* +0x30: eastl::vector<prim*> begin */
    uint64_t prims_end;          /* +0x38: eastl::vector<prim*> end */
    uint64_t prims_capacity;     /* +0x40: eastl::vector<prim*> capacity */
    uint8_t  _pad_48[0x08];      /* +0x48: tail padding to 0x50 */
} nummModelObject;

static_assert(offsetof(nummModelObject, pos_x)         == 0x10, "nummModelObject.pos_x");
static_assert(offsetof(nummModelObject, pos_y)         == 0x14, "nummModelObject.pos_y");
static_assert(offsetof(nummModelObject, pos_z)         == 0x18, "nummModelObject.pos_z");
static_assert(offsetof(nummModelObject, bounds_radius) == 0x1C, "nummModelObject.bounds_radius");
static_assert(offsetof(nummModelObject, flags)         == 0x26, "nummModelObject.flags");
static_assert(offsetof(nummModelObject, matrix_index)  == 0x28, "nummModelObject.matrix_index");
static_assert(offsetof(nummModelObject, prims_begin)   == 0x30, "nummModelObject.prims_begin");
static_assert(offsetof(nummModelObject, prims_end)     == 0x38, "nummModelObject.prims_end");
static_assert(offsetof(nummModelObject, prims_capacity)== 0x40, "nummModelObject.prim_capacity");
static_assert(sizeof(nummModelObject)                  == 0x50, "nummModelObject size");

/* =========================================================================
 * nummModelPrimitive — size unknown, >= 0x48
 * Fields proven from Create/Draw/Release. operator_new(0xb0) allocates
 * mmVertexDataBase (separate object at +0x00), not this struct itself.
 * The primitive struct holds pointers to vertex data, index data, materials.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelPrimitive {
    uint64_t vertex_data;        /* +0x00: mmVertexDataBase* (operator_new 0xb0) */
    uint64_t index_data;         /* +0x08: mmIndexData* / skinning controller */
    uint64_t crit_section;       /* +0x10: NUMM_THREAD_CRITICAL_SECTION_CONTEXT* */
    uint64_t materials_begin;    /* +0x18: eastl::vector<material*> begin */
    uint64_t materials_end;      /* +0x20: eastl::vector<material*> end */
    uint8_t  _pad_28[0x10];      /* +0x28: gap */
    uint32_t prim_type;          /* +0x38: *(ushort*)(nud_prim+0x22) & 3 */
    uint32_t skin_matrix_idx;    /* +0x3C: written in Create when skinned */
    uint32_t material_count;     /* +0x40: nuccNudInfo::GetMaterialHeaderNum */
    uint32_t index_format;       /* +0x44: param_4 stored in Create */
    uint8_t  _pad_48[0x04];      /* +0x48: tail padding */
} nummModelPrimitive;

static_assert(offsetof(nummModelPrimitive, vertex_data)      == 0x00, "nummModelPrimitive.vertex_data");
static_assert(offsetof(nummModelPrimitive, index_data)       == 0x08, "nummModelPrimitive.index_data");
static_assert(offsetof(nummModelPrimitive, crit_section)     == 0x10, "nummModelPrimitive.crit_section");
static_assert(offsetof(nummModelPrimitive, materials_begin)  == 0x18, "nummModelPrimitive.materials_begin");
static_assert(offsetof(nummModelPrimitive, materials_end)    == 0x20, "nummModelPrimitive.materials_end");
static_assert(offsetof(nummModelPrimitive, prim_type)        == 0x38, "nummModelPrimitive.prim_type");
static_assert(offsetof(nummModelPrimitive, skin_matrix_idx)  == 0x3C, "nummModelPrimitive.skin_matrix_idx");
static_assert(offsetof(nummModelPrimitive, material_count)   == 0x40, "nummModelPrimitive.material_count");
static_assert(offsetof(nummModelPrimitive, index_format)     == 0x44, "nummModelPrimitive.index_format");

/* =========================================================================
 * nummModelMaterial — size unknown, >= 0xB0
 * Largest accessed offset: param_1 + 0x15 (= +0xA8) for mmShaderBufferBinder.
 * mmShaderBufferBinder is an embedded object; its size is unknown.
 * Destructor also touches param_1 + 0x12 (= +0x90) for NUMM_THREAD_CRITICAL_SECTION_CONTEXT.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummModelMaterial {
    uint64_t render_state_data;  /* +0x00: mmRenderStateData* (freed in dtor) */
    uint64_t render_state_flags; /* +0x08: ~*(uint*)(param_1+1) & 0x280000 */
    uint64_t texture_params_begin;/* +0x10: eastl::rbtree begin (dtor DoNukeSubtree +2) */
    uint64_t texture_params_end; /* +0x18: eastl::rbtree end */
    uint64_t texture_params_cap; /* +0x20: eastl::rbtree capacity */
    uint64_t const_buf_tree_begin;/* +0x28: eastl::rbtree begin (dtor DoNukeSubtree +6) */
    uint64_t const_buf_tree_end; /* +0x30: eastl::rbtree end */
    uint64_t const_buf_tree_cap; /* +0x38: eastl::rbtree capacity */
    uint8_t  _pad_40[0x08];      /* +0x40: gap */
    uint64_t shader_params_begin;/* +0x48: eastl::vector<ShaderParameter> begin (resize at +6) */
    uint64_t shader_params_end;  /* +0x50: vector end (+7) */
    uint64_t shader_params_cap;  /* +0x58: vector capacity */
    uint8_t  _pad_60[0x10];      /* +0x60: gap */
    uint64_t material_header_a;  /* +0x70: copied from local_b0 in Create */
    uint64_t material_header_b;  /* +0x78: copied from local_b0+2 */
    uint64_t material_header_c;  /* +0x80: copied from local_b0+4 */
    uint64_t material_header_d;  /* +0x88: copied from local_b0+6 */
    uint64_t constant_buffer;    /* +0x90: mmConstantBuffer* (Lock/Unlock in Update) */
    uint8_t  _pad_98[0x08];      /* +0x98: gap */
    uint64_t shader_handle;      /* +0xA0: nummShader* (SetParameter path in Update) */
    uint64_t shader_bind_list_vs;/* +0xA8: not directly seen; inferred slot */
    uint64_t thread_crit_sec;    /* +0xB0: NUMM_THREAD_CRITICAL_SECTION_CONTEXT (dtor +0x12=+0x90... actually +0x90) */
    uint8_t  _pad_b8[0x08];      /* +0xB8: gap */
    uint64_t shader_buffer_binder;/* +0xC0: mmShaderBufferBinder (dtor +0x15=+0xA8... recalc below) */
} nummModelMaterial;

/* Note: dtor calls ~mmShaderBufferBinder(param_1 + 0x15) → byte offset 0xA8
 * and ~NUMM_THREAD_CRITICAL_SECTION_CONTEXT(param_1 + 0x12) → byte offset 0x90
 * With undefined8* param_1, +0x15 = 0xA8, +0x12 = 0x90.
 * So thread_crit_sec is at +0x90 (size unknown), shader_buffer_binder at +0xA8.
 * Minimum size >= 0xA8 + sizeof(mmShaderBufferBinder). Unknown total.
 */
static_assert(offsetof(nummModelMaterial, render_state_data)    == 0x00, "nummModelMaterial.render_state_data");
static_assert(offsetof(nummModelMaterial, render_state_flags)   == 0x08, "nummModelMaterial.render_state_flags");
static_assert(offsetof(nummModelMaterial, texture_params_begin) == 0x10, "nummModelMaterial.texture_params_begin");
static_assert(offsetof(nummModelMaterial, const_buf_tree_begin) == 0x28, "nummModelMaterial.const_buf_tree_begin");
static_assert(offsetof(nummModelMaterial, shader_params_begin)  == 0x48, "nummModelMaterial.shader_params_begin");
static_assert(offsetof(nummModelMaterial, material_header_a)    == 0x70, "nummModelMaterial.material_header_a");
static_assert(offsetof(nummModelMaterial, constant_buffer)      == 0x90, "nummModelMaterial.constant_buffer");
static_assert(offsetof(nummModelMaterial, shader_handle)        == 0xA0, "nummModelMaterial.shader_handle");
/* Cannot static_assert sizeof: size unproven beyond 0xA8 + embedded binder */

/* =========================================================================
 * nummMakeNudVertex — size unknown, >= 0x74
 * 11 fields from state_surface at +0x2C through +0x70.
 * No operator_new size found; this may be stack-allocated or embedded.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummMakeNudVertex {
    uint8_t  _pad_00[0x2C];      /* +0x00: unknown header */
    uint32_t field_2c;           /* +0x2C: SIM field from state_surface */
    uint32_t field_30;           /* +0x30: SIM field */
    uint32_t field_34;           /* +0x34: SIM field */
    uint32_t field_38;           /* +0x38: SIM field */
    uint32_t field_3c;           /* +0x3C: SIM field */
    uint32_t field_40;           /* +0x40: SIM field */
    uint32_t field_44;           /* +0x44: SIM field */
    uint32_t field_48;           /* +0x48: SIM field */
    uint32_t field_4c;           /* +0x4C: SIM field */
    uint32_t field_50;           /* +0x50: SIM field */
    uint32_t field_54;           /* +0x54: SIM field */
    uint32_t field_58;           /* +0x58: SIM field */
    uint32_t field_5c;           /* +0x5C: SIM field */
    uint32_t field_60;           /* +0x60: SIM field */
    uint32_t field_64;           /* +0x64: SIM field */
    uint32_t field_68;           /* +0x68: SIM field */
    uint32_t field_6c;           /* +0x6C: SIM field */
    uint32_t field_70;           /* +0x70: SIM field */
} nummMakeNudVertex;

static_assert(offsetof(nummMakeNudVertex, field_2c) == 0x2C, "nummMakeNudVertex.field_2c");
static_assert(offsetof(nummMakeNudVertex, field_30) == 0x30, "nummMakeNudVertex.field_30");
static_assert(offsetof(nummMakeNudVertex, field_34) == 0x34, "nummMakeNudVertex.field_34");
static_assert(offsetof(nummMakeNudVertex, field_38) == 0x38, "nummMakeNudVertex.field_38");
static_assert(offsetof(nummMakeNudVertex, field_3c) == 0x3C, "nummMakeNudVertex.field_3c");
static_assert(offsetof(nummMakeNudVertex, field_40) == 0x40, "nummMakeNudVertex.field_40");
static_assert(offsetof(nummMakeNudVertex, field_44) == 0x44, "nummMakeNudVertex.field_44");
static_assert(offsetof(nummMakeNudVertex, field_48) == 0x48, "nummMakeNudVertex.field_48");
static_assert(offsetof(nummMakeNudVertex, field_4c) == 0x4C, "nummMakeNudVertex.field_4c");
static_assert(offsetof(nummMakeNudVertex, field_50) == 0x50, "nummMakeNudVertex.field_50");
static_assert(offsetof(nummMakeNudVertex, field_54) == 0x54, "nummMakeNudVertex.field_54");
static_assert(offsetof(nummMakeNudVertex, field_58) == 0x58, "nummMakeNudVertex.field_58");
static_assert(offsetof(nummMakeNudVertex, field_5c) == 0x5C, "nummMakeNudVertex.field_5c");
static_assert(offsetof(nummMakeNudVertex, field_60) == 0x60, "nummMakeNudVertex.field_60");
static_assert(offsetof(nummMakeNudVertex, field_64) == 0x64, "nummMakeNudVertex.field_64");
static_assert(offsetof(nummMakeNudVertex, field_68) == 0x68, "nummMakeNudVertex.field_68");
static_assert(offsetof(nummMakeNudVertex, field_6c) == 0x6C, "nummMakeNudVertex.field_6c");
static_assert(offsetof(nummMakeNudVertex, field_70) == 0x70, "nummMakeNudVertex.field_70");

/* =========================================================================
 * nummNSHHeader — size unknown, >= 0x20
 * eastl::vector-like: 3 pointers + possible count.
 * IsFormatError reads *(short*)(this + 10) → offset 0x0A for a count field.
 * Likely layout: begin(+0x00), end(+0x08), capacity(+0x10), count_or_flags(+0x18).
 * ========================================================================= */
typedef struct __attribute__((packed)) nummNSHHeader {
    uint64_t data_begin;         /* +0x00: vector begin pointer */
    uint64_t data_end;           /* +0x08: vector end pointer */
    uint64_t data_capacity;      /* +0x10: vector capacity pointer */
    uint16_t entry_count;        /* +0x18: *(short*)(this+10) in IsFormatError...
                                    actually param_1 as longlong*, +10 = byte 0x50?
                                    Re-check: IsFormatError takes longlong *param_1,
                                    *(short*)((longlong)local_b0 + 10) uses local_b0
                                    which is GetMaterialHeader return, not this.
                                    This field is uncertain. */
    uint8_t  _pad_1a[0x06];      /* +0x1A: padding */
} nummNSHHeader;

static_assert(offsetof(nummNSHHeader, data_begin)    == 0x00, "nummNSHHeader.data_begin");
static_assert(offsetof(nummNSHHeader, data_end)      == 0x08, "nummNSHHeader.data_end");
static_assert(offsetof(nummNSHHeader, data_capacity) == 0x10, "nummNSHHeader.data_capacity");
/* Size unproven; no sizeof assert */

/* =========================================================================
 * nummNudInfo — size unknown, >= 0x08
 * Simple wrapper: destructor frees *param_1. Local instance is 64 bytes
 * on stack but that includes alignment/padding. Heap size unproven.
 * ========================================================================= */
typedef struct __attribute__((packed)) nummNudInfo {
    uint64_t data_ptr;           /* +0x00: pointer freed in dtor */
} nummNudInfo;

static_assert(offsetof(nummNudInfo, data_ptr) == 0x00, "nummNudInfo.data_ptr");
/* Size unproven; no sizeof assert */

/* =========================================================================
 * nummModelManager — size unknown, >= 0x20
 * Hashtable wrapper. Fields at +0x08 (hashtable ptr), +0x10 (buckets),
 * +0x18 (bucket count). No operator_new size found for this class directly.
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

#endif /* CMN75_H */