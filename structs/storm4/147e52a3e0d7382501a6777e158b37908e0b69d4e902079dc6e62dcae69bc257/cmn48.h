/*
 * cmn48.h - nuccChunk* struct layouts for NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 *
 * All offsets derived from NSUNS4_release.exe x64 decompilation (image base 0x140000000).
 * Sizes confirmed via allocator-call size argument in Create where noted.
 * Everything is INFERRED from static analysis, not CONFIRMED at runtime.
 * Field names carried from s3 reconstruction; offsets re-verified in s4 decompiled code.
 */
#ifndef CMN48_H
#define CMN48_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccChunkList
 * Size: unknown (ctor does not allocate; embedded or subclass-allocated)
 * Vtable: PTR_FUN_1410075d8 (from ctor @ RVA 0xA333D0)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkList {
    uint64_t chunk_array_base;       /* +0x00 */
    uint64_t chunk_array_end;        /* +0x08 */
    uint64_t secondary_list_head;    /* +0x10 */
    uint64_t secondary_list_vtable;  /* +0x18 */
    uint32_t secondary_list_size;    /* +0x20 */
    uint32_t _pad_24;                /* +0x24 */
    uint32_t secondary_list_end;     /* +0x28 */
    uint32_t _pad_2c;                /* +0x2C */
    uint16_t chunk_count;            /* +0x30 */
    uint8_t  _pad_32[6];             /* +0x32 */
} nuccChunkList;
/* size unknown - no sizeof assert */
static_assert(offsetof(nuccChunkList, chunk_array_base) == 0x00, "nuccChunkList.chunk_array_base");
static_assert(offsetof(nuccChunkList, chunk_array_end) == 0x08, "nuccChunkList.chunk_array_end");
static_assert(offsetof(nuccChunkList, secondary_list_head) == 0x10, "nuccChunkList.secondary_list_head");
static_assert(offsetof(nuccChunkList, secondary_list_vtable) == 0x18, "nuccChunkList.secondary_list_vtable");
static_assert(offsetof(nuccChunkList, secondary_list_size) == 0x20, "nuccChunkList.secondary_list_size");
static_assert(offsetof(nuccChunkList, secondary_list_end) == 0x28, "nuccChunkList.secondary_list_end");
static_assert(offsetof(nuccChunkList, chunk_count) == 0x30, "nuccChunkList.chunk_count");

/* ========================================================================
 * nuccChunkMaterial
 * Size: unknown, >= 0x7C (no Create/allocator call found in s4; last field at 0x78)
 * Vtable: set by parent class; dtor sets PTR_FUN_14110f938 then PTR_FUN_141112cf8
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkMaterial {
    uint64_t vtable;                 /* +0x00 */
    uint64_t name_string_ref;        /* +0x08 */
    uint64_t texture_slot_array;     /* +0x10 */
    uint8_t  material_type_flags;    /* +0x18 */
    uint8_t  _pad_19[3];             /* +0x19 */
    uint32_t texture_flags_bitmask;  /* +0x1C */
    uint32_t specular_power;         /* +0x20 float as u32 */
    float    alpha_opacity;          /* +0x24 */
    uint64_t diffuse_color_rgba;     /* +0x28 */
    uint64_t ambient_color_rgba;     /* +0x30 */
    uint64_t specular_color_rgba;    /* +0x38 */
    uint64_t emissive_color_rgba;    /* +0x40 */
    uint64_t diffuse_uv_scale;       /* +0x48 */
    uint64_t ambient_uv_scale;       /* +0x50 */
    uint64_t specular_uv_scale;      /* +0x58 */
    uint64_t emissive_uv_scale;      /* +0x60 */
    uint64_t extra_param_pair_a;     /* +0x68 */
    uint32_t reserved_pad;           /* +0x70 */
    uint32_t extra_param_b;          /* +0x74 */
    uint32_t extra_param_c;          /* +0x78 */
} nuccChunkMaterial;
/* size unknown, >= 0x7C - no sizeof assert */
static_assert(offsetof(nuccChunkMaterial, vtable) == 0x00, "nuccChunkMaterial.vtable");
static_assert(offsetof(nuccChunkMaterial, name_string_ref) == 0x08, "nuccChunkMaterial.name_string_ref");
static_assert(offsetof(nuccChunkMaterial, texture_slot_array) == 0x10, "nuccChunkMaterial.texture_slot_array");
static_assert(offsetof(nuccChunkMaterial, material_type_flags) == 0x18, "nuccChunkMaterial.material_type_flags");
static_assert(offsetof(nuccChunkMaterial, texture_flags_bitmask) == 0x1C, "nuccChunkMaterial.texture_flags_bitmask");
static_assert(offsetof(nuccChunkMaterial, specular_power) == 0x20, "nuccChunkMaterial.specular_power");
static_assert(offsetof(nuccChunkMaterial, alpha_opacity) == 0x24, "nuccChunkMaterial.alpha_opacity");
static_assert(offsetof(nuccChunkMaterial, diffuse_color_rgba) == 0x28, "nuccChunkMaterial.diffuse_color_rgba");
static_assert(offsetof(nuccChunkMaterial, ambient_color_rgba) == 0x30, "nuccChunkMaterial.ambient_color_rgba");
static_assert(offsetof(nuccChunkMaterial, specular_color_rgba) == 0x38, "nuccChunkMaterial.specular_color_rgba");
static_assert(offsetof(nuccChunkMaterial, emissive_color_rgba) == 0x40, "nuccChunkMaterial.emissive_color_rgba");
static_assert(offsetof(nuccChunkMaterial, diffuse_uv_scale) == 0x48, "nuccChunkMaterial.diffuse_uv_scale");
static_assert(offsetof(nuccChunkMaterial, ambient_uv_scale) == 0x50, "nuccChunkMaterial.ambient_uv_scale");
static_assert(offsetof(nuccChunkMaterial, specular_uv_scale) == 0x58, "nuccChunkMaterial.specular_uv_scale");
static_assert(offsetof(nuccChunkMaterial, emissive_uv_scale) == 0x60, "nuccChunkMaterial.emissive_uv_scale");
static_assert(offsetof(nuccChunkMaterial, extra_param_pair_a) == 0x68, "nuccChunkMaterial.extra_param_pair_a");
static_assert(offsetof(nuccChunkMaterial, reserved_pad) == 0x70, "nuccChunkMaterial.reserved_pad");
static_assert(offsetof(nuccChunkMaterial, extra_param_b) == 0x74, "nuccChunkMaterial.extra_param_b");
static_assert(offsetof(nuccChunkMaterial, extra_param_c) == 0x78, "nuccChunkMaterial.extra_param_c");

/* ========================================================================
 * nuccChunkModel
 * Size: 0x250 (confirmed: FUN_140a017f0(0x250,...) in Create @ RVA 0xA3BBC0)
 * Vtable: PTR_FUN_141108b98 (from ctor @ RVA 0xA3AE30)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkModel {
    uint64_t vtable;                 /* +0x00 */
    uint64_t unknown_zeroed;         /* +0x08 */
    uint64_t sub_obj_vtable;         /* +0x10 */
    uint64_t sub_obj_data_ptr;       /* +0x18 */
    uint32_t sub_obj_count;          /* +0x20 */
    uint32_t _pad_24;                /* +0x24 */
    uint64_t sub_obj2_vtable;        /* +0x28 */
    uint64_t sub_obj2_data;          /* +0x30 */
    uint32_t sub_obj2_count;         /* +0x38 */
    uint32_t _pad_3c;                /* +0x3C */
    uint8_t  embedded_object[16];    /* +0x40 */
    uint64_t embedded_vec_vtable;    /* +0x50 */
    uint64_t container3_vtable;      /* +0x58 */
    uint64_t name_string;            /* +0x60 */
    uint64_t bounding_volume;        /* +0x68 */
    float    bound_min_x;            /* +0x70 */
    float    bound_min_y;            /* +0x74 */
    float    bound_min_z;            /* +0x78 */
    float    bound_max_packed;       /* +0x7C */
    uint8_t  sub_mesh_descriptor[24];/* +0x80 */
    uint64_t mesh_data_array_base;   /* +0x98 */
    uint64_t mesh_data_array_ref;    /* +0xA0 */
    uint16_t model_flags;            /* +0xA8 */
    uint16_t vertex_attr_flags;      /* +0xAA */
    uint16_t face_count_lod;         /* +0xAC */
    uint8_t  unknown_flag_a;         /* +0xAE */
    uint8_t  unknown_flag_b;         /* +0xAF */
    uint32_t material_index;         /* +0xB0 */
    uint32_t _pad_b4;                /* +0xB4 */
    uint64_t raw_vertex_index_buf;   /* +0xB8 */
    uint16_t mesh_count;             /* +0xC0 */
    uint16_t total_submesh_count;    /* +0xC2 */
    uint32_t total_face_count;       /* +0xC4 */
    uint64_t _pad_c8;                /* +0xC8 */
    uint64_t dtor_cleanup_target;    /* +0xD0 */
    uint64_t bone_transform_array;   /* +0xD8 */
    uint32_t bone_count;             /* +0xE0 */
    uint32_t _pad_e4;                /* +0xE4 */
    uint64_t gpu_resource_handle;    /* +0xE8 */
    uint64_t skinning_data;          /* +0xF0 */
    uint32_t skinning_entry_count;   /* +0xF8 */
    uint32_t _pad_fc;                /* +0xFC */
    uint64_t lod_data_ptr;           /* +0x100 */
    uint64_t collision_mesh_ref;     /* +0x108 */
    uint8_t  gpu_upload_state[16];   /* +0x110 */
    uint64_t render_setup_target;    /* +0x120 */
    uint32_t render_pass_flags;      /* +0x128 */
    uint32_t _pad_12c;               /* +0x12C */
    uint64_t shader_param_block;     /* +0x130 */
    uint8_t  trailing_reserved[280]; /* +0x138..0x24F */
} nuccChunkModel;
static_assert(sizeof(nuccChunkModel) == 0x250, "nuccChunkModel size");
static_assert(offsetof(nuccChunkModel, vtable) == 0x00, "nuccChunkModel.vtable");
static_assert(offsetof(nuccChunkModel, unknown_zeroed) == 0x08, "nuccChunkModel.unknown_zeroed");
static_assert(offsetof(nuccChunkModel, sub_obj_vtable) == 0x10, "nuccChunkModel.sub_obj_vtable");
static_assert(offsetof(nuccChunkModel, sub_obj_data_ptr) == 0x18, "nuccChunkModel.sub_obj_data_ptr");
static_assert(offsetof(nuccChunkModel, sub_obj_count) == 0x20, "nuccChunkModel.sub_obj_count");
static_assert(offsetof(nuccChunkModel, sub_obj2_vtable) == 0x28, "nuccChunkModel.sub_obj2_vtable");
static_assert(offsetof(nuccChunkModel, sub_obj2_data) == 0x30, "nuccChunkModel.sub_obj2_data");
static_assert(offsetof(nuccChunkModel, sub_obj2_count) == 0x38, "nuccChunkModel.sub_obj2_count");
static_assert(offsetof(nuccChunkModel, embedded_object) == 0x40, "nuccChunkModel.embedded_object");
static_assert(offsetof(nuccChunkModel, embedded_vec_vtable) == 0x50, "nuccChunkModel.embedded_vec_vtable");
static_assert(offsetof(nuccChunkModel, container3_vtable) == 0x58, "nuccChunkModel.container3_vtable");
static_assert(offsetof(nuccChunkModel, name_string) == 0x60, "nuccChunkModel.name_string");
static_assert(offsetof(nuccChunkModel, bounding_volume) == 0x68, "nuccChunkModel.bounding_volume");
static_assert(offsetof(nuccChunkModel, bound_min_x) == 0x70, "nuccChunkModel.bound_min_x");
static_assert(offsetof(nuccChunkModel, bound_min_y) == 0x74, "nuccChunkModel.bound_min_y");
static_assert(offsetof(nuccChunkModel, bound_min_z) == 0x78, "nuccChunkModel.bound_min_z");
static_assert(offsetof(nuccChunkModel, bound_max_packed) == 0x7C, "nuccChunkModel.bound_max_packed");
static_assert(offsetof(nuccChunkModel, sub_mesh_descriptor) == 0x80, "nuccChunkModel.sub_mesh_descriptor");
static_assert(offsetof(nuccChunkModel, mesh_data_array_base) == 0x98, "nuccChunkModel.mesh_data_array_base");
static_assert(offsetof(nuccChunkModel, mesh_data_array_ref) == 0xA0, "nuccChunkModel.mesh_data_array_ref");
static_assert(offsetof(nuccChunkModel, model_flags) == 0xA8, "nuccChunkModel.model_flags");
static_assert(offsetof(nuccChunkModel, vertex_attr_flags) == 0xAA, "nuccChunkModel.vertex_attr_flags");
static_assert(offsetof(nuccChunkModel, face_count_lod) == 0xAC, "nuccChunkModel.face_count_lod");
static_assert(offsetof(nuccChunkModel, unknown_flag_a) == 0xAE, "nuccChunkModel.unknown_flag_a");
static_assert(offsetof(nuccChunkModel, unknown_flag_b) == 0xAF, "nuccChunkModel.unknown_flag_b");
static_assert(offsetof(nuccChunkModel, material_index) == 0xB0, "nuccChunkModel.material_index");
static_assert(offsetof(nuccChunkModel, raw_vertex_index_buf) == 0xB8, "nuccChunkModel.raw_vertex_index_buf");
static_assert(offsetof(nuccChunkModel, mesh_count) == 0xC0, "nuccChunkModel.mesh_count");
static_assert(offsetof(nuccChunkModel, total_submesh_count) == 0xC2, "nuccChunkModel.total_submesh_count");
static_assert(offsetof(nuccChunkModel, total_face_count) == 0xC4, "nuccChunkModel.total_face_count");
static_assert(offsetof(nuccChunkModel, dtor_cleanup_target) == 0xD0, "nuccChunkModel.dtor_cleanup_target");
static_assert(offsetof(nuccChunkModel, bone_transform_array) == 0xD8, "nuccChunkModel.bone_transform_array");
static_assert(offsetof(nuccChunkModel, bone_count) == 0xE0, "nuccChunkModel.bone_count");
static_assert(offsetof(nuccChunkModel, gpu_resource_handle) == 0xE8, "nuccChunkModel.gpu_resource_handle");
static_assert(offsetof(nuccChunkModel, skinning_data) == 0xF0, "nuccChunkModel.skinning_data");
static_assert(offsetof(nuccChunkModel, skinning_entry_count) == 0xF8, "nuccChunkModel.skinning_entry_count");
static_assert(offsetof(nuccChunkModel, lod_data_ptr) == 0x100, "nuccChunkModel.lod_data_ptr");
static_assert(offsetof(nuccChunkModel, collision_mesh_ref) == 0x108, "nuccChunkModel.collision_mesh_ref");
static_assert(offsetof(nuccChunkModel, gpu_upload_state) == 0x110, "nuccChunkModel.gpu_upload_state");
static_assert(offsetof(nuccChunkModel, render_setup_target) == 0x120, "nuccChunkModel.render_setup_target");
static_assert(offsetof(nuccChunkModel, render_pass_flags) == 0x128, "nuccChunkModel.render_pass_flags");
static_assert(offsetof(nuccChunkModel, shader_param_block) == 0x130, "nuccChunkModel.shader_param_block");
static_assert(offsetof(nuccChunkModel, trailing_reserved) == 0x138, "nuccChunkModel.trailing_reserved");

/* ========================================================================
 * nuccChunkLightDirc
 * Size: 0xC0 (confirmed: FUN_140a017f0(0xc0,...) in Create @ RVA 0xA7CBE0)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkLightDirc {
    uint64_t vtable;              /* +0x00 */
    uint64_t name_string_ref;     /* +0x08 */
    uint32_t light_type;          /* +0x10: always 2 */
    uint32_t _pad_14;             /* +0x14 */
    uint64_t parent_mem_ctx;      /* +0x18 */
    uint64_t direction_xy;        /* +0x20 */
    uint64_t direction_zw;        /* +0x28 */
    uint32_t color_intensity;     /* +0x30 */
    uint32_t shadow_map_index;    /* +0x34: default 0xFFFFFFFF */
    uint64_t name_string_resolved;/* +0x38 */
    uint64_t secondary_color;     /* +0x40 */
    uint64_t tertiary_params;     /* +0x48 */
    uint8_t  remaining[0xC0 - 0x50]; /* +0x50..0xBF */
} nuccChunkLightDirc;
static_assert(sizeof(nuccChunkLightDirc) == 0xC0, "nuccChunkLightDirc size");
static_assert(offsetof(nuccChunkLightDirc, vtable) == 0x00, "nuccChunkLightDirc.vtable");
static_assert(offsetof(nuccChunkLightDirc, name_string_ref) == 0x08, "nuccChunkLightDirc.name_string_ref");
static_assert(offsetof(nuccChunkLightDirc, light_type) == 0x10, "nuccChunkLightDirc.light_type");
static_assert(offsetof(nuccChunkLightDirc, parent_mem_ctx) == 0x18, "nuccChunkLightDirc.parent_mem_ctx");
static_assert(offsetof(nuccChunkLightDirc, direction_xy) == 0x20, "nuccChunkLightDirc.direction_xy");
static_assert(offsetof(nuccChunkLightDirc, direction_zw) == 0x28, "nuccChunkLightDirc.direction_zw");
static_assert(offsetof(nuccChunkLightDirc, color_intensity) == 0x30, "nuccChunkLightDirc.color_intensity");
static_assert(offsetof(nuccChunkLightDirc, shadow_map_index) == 0x34, "nuccChunkLightDirc.shadow_map_index");
static_assert(offsetof(nuccChunkLightDirc, name_string_resolved) == 0x38, "nuccChunkLightDirc.name_string_resolved");
static_assert(offsetof(nuccChunkLightDirc, secondary_color) == 0x40, "nuccChunkLightDirc.secondary_color");
static_assert(offsetof(nuccChunkLightDirc, tertiary_params) == 0x48, "nuccChunkLightDirc.tertiary_params");
static_assert(offsetof(nuccChunkLightDirc, remaining) == 0x50, "nuccChunkLightDirc.remaining");

/* ========================================================================
 * nuccChunkLightPoint
 * Size: 0x90 (confirmed: FUN_140a017f0(0x90,...) in Create @ RVA 0xA7CD90)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkLightPoint {
    uint64_t vtable;              /* +0x00 */
    uint64_t name_string_ref;     /* +0x08 */
    uint32_t light_type;          /* +0x10: always 3 */
    uint32_t _pad_14;             /* +0x14 */
    uint64_t parent_mem_ctx;      /* +0x18 */
    uint64_t position_xy;         /* +0x20 */
    uint64_t position_z_range;    /* +0x28 */
    uint32_t attenuation_params;  /* +0x30 */
    uint32_t shadow_light_flags;  /* +0x34 */
    uint64_t name_string_resolved;/* +0x38 */
    uint64_t color_rgba;          /* +0x40 */
    float    falloff_radius;      /* +0x48 */
    uint32_t range_outer_radius;  /* +0x4C */
    uint64_t extra_params;        /* +0x50 */
    uint8_t  remaining[0x90 - 0x58]; /* +0x58..0x8F */
} nuccChunkLightPoint;
static_assert(sizeof(nuccChunkLightPoint) == 0x90, "nuccChunkLightPoint size");
static_assert(offsetof(nuccChunkLightPoint, vtable) == 0x00, "nuccChunkLightPoint.vtable");
static_assert(offsetof(nuccChunkLightPoint, name_string_ref) == 0x08, "nuccChunkLightPoint.name_string_ref");
static_assert(offsetof(nuccChunkLightPoint, light_type) == 0x10, "nuccChunkLightPoint.light_type");
static_assert(offsetof(nuccChunkLightPoint, parent_mem_ctx) == 0x18, "nuccChunkLightPoint.parent_mem_ctx");
static_assert(offsetof(nuccChunkLightPoint, position_xy) == 0x20, "nuccChunkLightPoint.position_xy");
static_assert(offsetof(nuccChunkLightPoint, position_z_range) == 0x28, "nuccChunkLightPoint.position_z_range");
static_assert(offsetof(nuccChunkLightPoint, attenuation_params) == 0x30, "nuccChunkLightPoint.attenuation_params");
static_assert(offsetof(nuccChunkLightPoint, shadow_light_flags) == 0x34, "nuccChunkLightPoint.shadow_light_flags");
static_assert(offsetof(nuccChunkLightPoint, name_string_resolved) == 0x38, "nuccChunkLightPoint.name_string_resolved");
static_assert(offsetof(nuccChunkLightPoint, color_rgba) == 0x40, "nuccChunkLightPoint.color_rgba");
static_assert(offsetof(nuccChunkLightPoint, falloff_radius) == 0x48, "nuccChunkLightPoint.falloff_radius");
static_assert(offsetof(nuccChunkLightPoint, range_outer_radius) == 0x4C, "nuccChunkLightPoint.range_outer_radius");
static_assert(offsetof(nuccChunkLightPoint, extra_params) == 0x50, "nuccChunkLightPoint.extra_params");
static_assert(offsetof(nuccChunkLightPoint, remaining) == 0x58, "nuccChunkLightPoint.remaining");

/* ========================================================================
 * nuccChunkLightSet
 * Size: unknown (>= 0x60; no Create allocator call found in s4)
 * Vtable: PTR_FUN_1410fb410 -> PTR_FUN_1410fb308 (from dtor @ RVA 0x9A5FA8)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkLightSet {
    uint64_t vtable;                /* +0x00 */
    uint64_t name_string_ref;       /* +0x08 */
    uint64_t unknown_10;            /* +0x10 */
    uint64_t mem_allocator_ctx;     /* +0x18 */
    uint64_t _pad_20;               /* +0x20 */
    uint64_t string_blob_base;      /* +0x28 */
    uint32_t dirc_light_count;      /* +0x30 */
    uint32_t _pad_34;               /* +0x34 */
    uint8_t  dirc_entries[0x28];    /* +0x38..0x5F */
} nuccChunkLightSet;
/* size unknown - no sizeof assert */
static_assert(offsetof(nuccChunkLightSet, vtable) == 0x00, "nuccChunkLightSet.vtable");
static_assert(offsetof(nuccChunkLightSet, name_string_ref) == 0x08, "nuccChunkLightSet.name_string_ref");
static_assert(offsetof(nuccChunkLightSet, unknown_10) == 0x10, "nuccChunkLightSet.unknown_10");
static_assert(offsetof(nuccChunkLightSet, mem_allocator_ctx) == 0x18, "nuccChunkLightSet.mem_allocator_ctx");
static_assert(offsetof(nuccChunkLightSet, string_blob_base) == 0x28, "nuccChunkLightSet.string_blob_base");
static_assert(offsetof(nuccChunkLightSet, dirc_light_count) == 0x30, "nuccChunkLightSet.dirc_light_count");
static_assert(offsetof(nuccChunkLightSet, dirc_entries) == 0x38, "nuccChunkLightSet.dirc_entries");

/* ========================================================================
 * nuccChunkLayerSet
 * Size: 0x2B0 (confirmed: FUN_140a017f0(0x2b0,...) in Create @ RVA 0xA799F0)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkLayerSet {
    uint64_t vtable;                /* +0x00 */
    uint64_t name_string_ref;       /* +0x08 */
    uint8_t  layer_entry_container[0x58]; /* +0x10..0x67 */
    uint16_t layer_count_a;         /* +0x68 */
    uint8_t  _pad_6a[6];            /* +0x6A */
    uint64_t layer_name_offset_tbl; /* +0x70 */
    uint64_t _pad_78;               /* +0x78 */
    uint64_t mem_allocator_ctx;     /* +0x80 */
    uint64_t _pad_88;               /* +0x88 */
    uint64_t string_blob_base;      /* +0x90 */
    uint32_t blob_size;             /* +0x98 */
    uint32_t _pad_9c;               /* +0x9C */
    uint8_t  remaining[0x210];      /* +0xA0..0x2AF */
} nuccChunkLayerSet;
static_assert(sizeof(nuccChunkLayerSet) == 0x2B0, "nuccChunkLayerSet size");
static_assert(offsetof(nuccChunkLayerSet, vtable) == 0x00, "nuccChunkLayerSet.vtable");
static_assert(offsetof(nuccChunkLayerSet, name_string_ref) == 0x08, "nuccChunkLayerSet.name_string_ref");
static_assert(offsetof(nuccChunkLayerSet, layer_entry_container) == 0x10, "nuccChunkLayerSet.layer_entry_container");
static_assert(offsetof(nuccChunkLayerSet, layer_count_a) == 0x68, "nuccChunkLayerSet.layer_count_a");
static_assert(offsetof(nuccChunkLayerSet, layer_name_offset_tbl) == 0x70, "nuccChunkLayerSet.layer_name_offset_tbl");
static_assert(offsetof(nuccChunkLayerSet, mem_allocator_ctx) == 0x80, "nuccChunkLayerSet.mem_allocator_ctx");
static_assert(offsetof(nuccChunkLayerSet, string_blob_base) == 0x90, "nuccChunkLayerSet.string_blob_base");
static_assert(offsetof(nuccChunkLayerSet, blob_size) == 0x98, "nuccChunkLayerSet.blob_size");
static_assert(offsetof(nuccChunkLayerSet, remaining) == 0xA0, "nuccChunkLayerSet.remaining");

/* ========================================================================
 * nuccChunkInternalIndex
 * Size: unknown (>= 0x50; no Create allocator call found in s4)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkInternalIndex {
    uint64_t vtable;              /* +0x00 */
    uint64_t unknown_08;          /* +0x08 */
    uint64_t unknown_10;          /* +0x10 */
    uint64_t unknown_18;          /* +0x18 */
    uint64_t unknown_20;          /* +0x20 */
    uint64_t unknown_28;          /* +0x28 */
    uint64_t unknown_30;          /* +0x30 */
    uint64_t unknown_38;          /* +0x38 */
    uint64_t unknown_40;          /* +0x40 */
    uint64_t managed_object;      /* +0x48 */
} nuccChunkInternalIndex;
/* size unknown - no sizeof assert */
static_assert(offsetof(nuccChunkInternalIndex, vtable) == 0x00, "nuccChunkInternalIndex.vtable");
static_assert(offsetof(nuccChunkInternalIndex, unknown_08) == 0x08, "nuccChunkInternalIndex.unknown_08");
static_assert(offsetof(nuccChunkInternalIndex, unknown_10) == 0x10, "nuccChunkInternalIndex.unknown_10");
static_assert(offsetof(nuccChunkInternalIndex, unknown_18) == 0x18, "nuccChunkInternalIndex.unknown_18");
static_assert(offsetof(nuccChunkInternalIndex, unknown_20) == 0x20, "nuccChunkInternalIndex.unknown_20");
static_assert(offsetof(nuccChunkInternalIndex, unknown_28) == 0x28, "nuccChunkInternalIndex.unknown_28");
static_assert(offsetof(nuccChunkInternalIndex, unknown_30) == 0x30, "nuccChunkInternalIndex.unknown_30");
static_assert(offsetof(nuccChunkInternalIndex, unknown_38) == 0x38, "nuccChunkInternalIndex.unknown_38");
static_assert(offsetof(nuccChunkInternalIndex, unknown_40) == 0x40, "nuccChunkInternalIndex.unknown_40");
static_assert(offsetof(nuccChunkInternalIndex, managed_object) == 0x48, "nuccChunkInternalIndex.managed_object");

/* ========================================================================
 * nuccChunkModelHit
 * Size: variable (no fixed allocator size; depends on hit data)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkModelHit {
    uint64_t vtable;              /* +0x00 */
    uint64_t unknown_08;          /* +0x08 */
    uint64_t unknown_10;          /* +0x10 */
    uint64_t unknown_18;          /* +0x18 */
    uint64_t unknown_20;          /* +0x20 */
    uint64_t unknown_28;          /* +0x28 */
    uint64_t unknown_30;          /* +0x30 */
    uint64_t unknown_38;          /* +0x38 */
    uint64_t hit_data_buffer;     /* +0x40 */
    uint64_t unknown_48;          /* +0x48 */
} nuccChunkModelHit;
/* size variable - no sizeof assert */
static_assert(offsetof(nuccChunkModelHit, vtable) == 0x00, "nuccChunkModelHit.vtable");
static_assert(offsetof(nuccChunkModelHit, unknown_08) == 0x08, "nuccChunkModelHit.unknown_08");
static_assert(offsetof(nuccChunkModelHit, unknown_10) == 0x10, "nuccChunkModelHit.unknown_10");
static_assert(offsetof(nuccChunkModelHit, unknown_18) == 0x18, "nuccChunkModelHit.unknown_18");
static_assert(offsetof(nuccChunkModelHit, unknown_20) == 0x20, "nuccChunkModelHit.unknown_20");
static_assert(offsetof(nuccChunkModelHit, unknown_28) == 0x28, "nuccChunkModelHit.unknown_28");
static_assert(offsetof(nuccChunkModelHit, unknown_30) == 0x30, "nuccChunkModelHit.unknown_30");
static_assert(offsetof(nuccChunkModelHit, unknown_38) == 0x38, "nuccChunkModelHit.unknown_38");
static_assert(offsetof(nuccChunkModelHit, hit_data_buffer) == 0x40, "nuccChunkModelHit.hit_data_buffer");
static_assert(offsetof(nuccChunkModelHit, unknown_48) == 0x48, "nuccChunkModelHit.unknown_48");

/* ========================================================================
 * nuccChunkModel::ChunkTable
 * Size: unknown (>= 0x10; embedded or pointer-based container)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkModel_ChunkTable {
    uint64_t chunk_array_base;    /* +0x00 */
    uint64_t chunk_array_end;     /* +0x08 */
} nuccChunkModel_ChunkTable;
/* size unknown - no sizeof assert */
static_assert(offsetof(nuccChunkModel_ChunkTable, chunk_array_base) == 0x00, "nuccChunkModel_ChunkTable.chunk_array_base");
static_assert(offsetof(nuccChunkModel_ChunkTable, chunk_array_end) == 0x08, "nuccChunkModel_ChunkTable.chunk_array_end");

/* ========================================================================
 * nuccChunkModel::Primitive
 * No instance state observed — vtable dispatch only.
 * Not emitted as a struct; listed here for completeness.
 * ======================================================================== */

#endif /* CMN48_H */