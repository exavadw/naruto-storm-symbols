/* cmn34 s1: common coverage batch 1 */
/* cmn34.h — Common engine struct group for NSUNS1 (build s1)
 * INFERRED from static decompilation of NSUNS1.exe (sha 10231093af9c).
 * All offsets derived from PC x64 code (image base 0x140000000).
 * Field names from Switch Trilogy ns1:: symbols via storm_map where available;
 * unnamed fields use descriptive placeholders.
 * Tag legend: SIM = simulation state, PRES = presentation/render-only, UNKNOWN = unclear purpose.
 * Packed struct: all fields are uint8_t arrays to guarantee exact byte offsets.
 * Named fields have comments showing intended type and evidence.
 */
#ifndef CMN34_H
#define CMN34_H

#include <stdint.h>
#include <stddef.h>

/* ========================================================================
 * mmVertexSemantic — vertex attribute semantic map (tree-based)
 * Size unknown, >= 0x58. Vtable not found in this build's methods.
 * Layout inferred from AddSemantic (0x118020), GetSemanticSize (0x1181B0),
 * GetSemanticOffset (0x118220).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVertexSemantic {
    uint8_t pad_0000[8];              /* 0x00: unknown / possible vtable or parent ptr */
    uint8_t tree_sentinel_left[8];    /* 0x08: u64 left child / sentinel */
    uint8_t pad_0010[8];              /* 0x10: padding */
    uint8_t tree_root[8];             /* 0x18: u64 tree root pointer */
    uint8_t pad_0020[8];              /* 0x20: padding */
    uint8_t tree_size[4];             /* 0x28: u32 element count threshold (< 0x10 inline) */
    uint8_t pad_002C[4];              /* 0x2C: padding */
    uint8_t semantic_ids_begin[8];    /* 0x30: u64 begin of semantic ID array */
    uint8_t semantic_ids_end[8];      /* 0x38: u64 end of semantic ID array */
    uint8_t pad_0040[16];             /* 0x40: padding */
    uint8_t semantic_sizes[8];        /* 0x50: u64 pointer to size table */
    /* ... size unknown, >= 0x58 ... */
} mmVertexSemantic;
#pragma pack(pop)

_Static_assert(offsetof(mmVertexSemantic, pad_0000) == 0x00, "mmVertexSemantic.pad_0000");
_Static_assert(offsetof(mmVertexSemantic, tree_sentinel_left) == 0x08, "mmVertexSemantic.tree_sentinel_left");
_Static_assert(offsetof(mmVertexSemantic, pad_0010) == 0x10, "mmVertexSemantic.pad_0010");
_Static_assert(offsetof(mmVertexSemantic, tree_root) == 0x18, "mmVertexSemantic.tree_root");
_Static_assert(offsetof(mmVertexSemantic, pad_0020) == 0x20, "mmVertexSemantic.pad_0020");
_Static_assert(offsetof(mmVertexSemantic, tree_size) == 0x28, "mmVertexSemantic.tree_size");
_Static_assert(offsetof(mmVertexSemantic, pad_002C) == 0x2C, "mmVertexSemantic.pad_002C");
_Static_assert(offsetof(mmVertexSemantic, semantic_ids_begin) == 0x30, "mmVertexSemantic.semantic_ids_begin");
_Static_assert(offsetof(mmVertexSemantic, semantic_ids_end) == 0x38, "mmVertexSemantic.semantic_ids_end");
_Static_assert(offsetof(mmVertexSemantic, pad_0040) == 0x40, "mmVertexSemantic.pad_0040");
_Static_assert(offsetof(mmVertexSemantic, semantic_sizes) == 0x50, "mmVertexSemantic.semantic_sizes");

/* ========================================================================
 * mmVBRenderInfoList — render info list with tree-based lookup
 * Size unknown, >= 0x48. Vtable not directly set in observed methods.
 * Layout from Add variants (0x10F480, 0x1186A0, 0x11C220).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVBRenderInfoList {
    uint8_t pad_0000[32];             /* 0x00: unknown header */
    uint8_t tree_sentinel[8];         /* 0x20: u64 tree sentinel node */
    uint8_t tree_right[8];            /* 0x28: u64 right child pointer */
    uint8_t tree_root[8];             /* 0x30: u64 tree root (null-checked) */
    uint8_t pad_0038[8];              /* 0x38: padding */
    uint8_t render_info_data[8];      /* 0x40: u64 passed to FUN_14010ff60 */
    /* ... size unknown, >= 0x48 ... */
} mmVBRenderInfoList;
#pragma pack(pop)

_Static_assert(offsetof(mmVBRenderInfoList, pad_0000) == 0x00, "mmVBRenderInfoList.pad_0000");
_Static_assert(offsetof(mmVBRenderInfoList, tree_sentinel) == 0x20, "mmVBRenderInfoList.tree_sentinel");
_Static_assert(offsetof(mmVBRenderInfoList, tree_right) == 0x28, "mmVBRenderInfoList.tree_right");
_Static_assert(offsetof(mmVBRenderInfoList, tree_root) == 0x30, "mmVBRenderInfoList.tree_root");
_Static_assert(offsetof(mmVBRenderInfoList, pad_0038) == 0x38, "mmVBRenderInfoList.pad_0038");
_Static_assert(offsetof(mmVBRenderInfoList, render_info_data) == 0x40, "mmVBRenderInfoList.render_info_data");

/* ========================================================================
 * mmVertexDataFlexible — flexible vertex buffer with dynamic offset info
 * Size unknown, >= 0x90. Vtable: PTR_FUN_140774bf0 at offset 0x00.
 * Layout from CreateData (0x118910, 0x118BA0), SetOffsetInfo (0x118C60, 0x118DC0).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVertexDataFlexible {
    uint8_t vtable[8];                /* 0x00: u64* PTR_FUN_140774bf0 */
    uint8_t field_0x08[8];            /* 0x08: u64 zeroed in ctor */
    uint8_t field_0x10[4];            /* 0x10: u32 zeroed in ctor */
    uint8_t pad_0014[4];              /* 0x14: padding to 0x18 */
    uint8_t allocator_ptr[8];         /* 0x18: u64 zeroed in ctor */
    uint8_t field_0x20[8];            /* 0x20: u64 zeroed in ctor */
    uint8_t field_0x28[8];            /* 0x28: u64 zeroed in ctor */
    uint8_t data_buffer[8];           /* 0x30: u64 void* allocated buffer ptr */
    uint8_t data_buffer_end[8];       /* 0x38: u64 void* buffer end */
    uint8_t field_0x40[8];            /* 0x40: u64 zeroed after alloc */
    uint8_t capacity[8];              /* 0x48: u64 aligned size */
    uint8_t alignment[8];             /* 0x50: u64 always 0x10 */
    uint8_t field_0x58[8];            /* 0x58: u64 zeroed in ctor */
    uint8_t offset_info_list_head[8]; /* 0x60: u64 head of offset info linked list */
    uint8_t offset_info_list_tail[8]; /* 0x68: u64 tail of offset info linked list */
    uint8_t field_0x70[8];            /* 0x70: u64 zeroed in ctor */
    uint8_t field_0x78[8];            /* 0x78: u64 PTR_LAB_1407744b8 */
    uint8_t field_0x80[8];            /* 0x80: u64 zeroed in ctor */
    uint8_t shadow_copy[8];           /* 0x88: u64 void* optional shadow buffer */
    /* ... size unknown, >= 0x90 ... */
} mmVertexDataFlexible;
#pragma pack(pop)

_Static_assert(offsetof(mmVertexDataFlexible, vtable) == 0x00, "mmVertexDataFlexible.vtable");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x08) == 0x08, "mmVertexDataFlexible.field_0x08");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x10) == 0x10, "mmVertexDataFlexible.field_0x10");
_Static_assert(offsetof(mmVertexDataFlexible, pad_0014) == 0x14, "mmVertexDataFlexible.pad_0014");
_Static_assert(offsetof(mmVertexDataFlexible, allocator_ptr) == 0x18, "mmVertexDataFlexible.allocator_ptr");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x20) == 0x20, "mmVertexDataFlexible.field_0x20");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x28) == 0x28, "mmVertexDataFlexible.field_0x28");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x40) == 0x40, "mmVertexDataFlexible.field_0x40");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x58) == 0x58, "mmVertexDataFlexible.field_0x58");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x70) == 0x70, "mmVertexDataFlexible.field_0x70");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x78) == 0x78, "mmVertexDataFlexible.field_0x78");
_Static_assert(offsetof(mmVertexDataFlexible, field_0x80) == 0x80, "mmVertexDataFlexible.field_0x80");
_Static_assert(offsetof(mmVertexDataFlexible, data_buffer) == 0x30, "mmVertexDataFlexible.data_buffer");
_Static_assert(offsetof(mmVertexDataFlexible, data_buffer_end) == 0x38, "mmVertexDataFlexible.data_buffer_end");
_Static_assert(offsetof(mmVertexDataFlexible, capacity) == 0x48, "mmVertexDataFlexible.capacity");
_Static_assert(offsetof(mmVertexDataFlexible, alignment) == 0x50, "mmVertexDataFlexible.alignment");
_Static_assert(offsetof(mmVertexDataFlexible, offset_info_list_head) == 0x60, "mmVertexDataFlexible.offset_info_list_head");
_Static_assert(offsetof(mmVertexDataFlexible, offset_info_list_tail) == 0x68, "mmVertexDataFlexible.offset_info_list_tail");
_Static_assert(offsetof(mmVertexDataFlexible, shadow_copy) == 0x88, "mmVertexDataFlexible.shadow_copy");

/* ========================================================================
 * mmVertexDataBase — base class for vertex data objects
 * Size unknown, >= 0x138. Vtable: PTR_FUN_140774d68 at offset 0x00.
 * Layout from ctors (0x1102E0, 0x47A6C0), ReleaseBase (0x111840, 0x11C660).
 * Contains multiple embedded sub-objects (linked lists, allocators).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVertexDataBase {
    uint8_t vtable[8];                /* 0x00: u64* PTR_FUN_140774d68 */
    uint8_t flags[2];                 /* 0x08: u16 low bits */
    uint8_t pad_000A[4];              /* 0x0A: padding to 0x0E */
    uint8_t refcount_or_flags[4];     /* 0x0E: u32 sub-object at param_1+6 */
    uint8_t pad_0012[6];              /* 0x12: padding to 0x18 */
    uint8_t field_0x18[8];            /* 0x18: u64 zeroed in ctor */
    uint8_t field_0x20[8];            /* 0x20: u64 zeroed in ctor */
    uint8_t field_0x28[8];            /* 0x28: u64 zeroed in ctor */
    uint8_t allocator_vtable[8];      /* 0x30: u64 vtable ptr for sub-allocator */
    uint8_t field_0x38[8];            /* 0x38: padding / sub-object continuation */
    uint8_t list_node_0x40[8];        /* 0x40: u64 self-linked list node */
    uint8_t list_node_0x48[8];        /* 0x48: u64 list node */
    uint8_t list_node_0x50[8];        /* 0x50: u64 list node */
    uint8_t field_0x58[4];            /* 0x58: u32 zeroed in ctor */
    uint8_t pad_005C[4];              /* 0x5C: padding to 0x60 */
    uint8_t sub_list_a_head[8];       /* 0x60: u64 PTR_LAB_1407744b8 sentinel */
    uint8_t sub_list_a_tail[8];       /* 0x68: u64 zeroed in ctor */
    uint8_t field_0x70[8];            /* 0x70: padding */
    uint8_t sub_list_b_prev[8];       /* 0x78: u64 zeroed in ctor */
    uint8_t sub_list_b_next[8];       /* 0x80: u64 self-link */
    uint8_t sub_list_b_sentinel[8];   /* 0x88: u64 PTR_LAB_1407744b8 */
    uint8_t field_0x90[8];            /* 0x90: u64 zeroed in ctor */
    uint8_t pad_0098[16];             /* 0x98: padding to 0xA8 */
    uint8_t sub_list_c_head[8];       /* 0xA8: u64 self-link ptr */
    uint8_t sub_list_c_tail[8];       /* 0xB0: u64 zeroed in ctor */
    uint8_t sub_list_c_sentinel[8];   /* 0xB8: u64 zeroed in ctor */
    uint8_t pad_00C0[8];              /* 0xC0: padding to 0xC8 */
    uint8_t sub_list_d_prev[8];       /* 0xC8: u64 PTR_LAB_1407744b8 */
    uint8_t sub_list_d_next[8];       /* 0xD0: u64 copies 0x12 */
    uint8_t field_0xD8[8];            /* 0xD8: u64 zeroed in ctor */
    uint8_t pad_00E0[8];              /* 0xE0: padding to 0xE8 */
    uint8_t sub_list_e_sentinel[8];   /* 0xE8: u64 PTR_LAB_1407744b8 */
    uint8_t field_0xF0[8];            /* 0xF0: u64 zeroed in ctor */
    uint8_t pad_00F8[16];             /* 0xF8: padding to 0x108 */
    uint8_t field_0x108[8];           /* 0x108: u64 zeroed in ctor */
    uint8_t field_0x110[8];           /* 0x110: u64 zeroed in ctor */
    uint8_t field_0x118[8];           /* 0x118: u64 zeroed in ctor */
    uint8_t pad_0120[8];              /* 0x120: padding to 0x128 */
    uint8_t sub_list_f_sentinel[8];   /* 0x128: u64 PTR_LAB_1407744b8 */
    uint8_t field_0x130[8];           /* 0x130: u64 zeroed in ctor */
    /* ... size unknown, >= 0x138 ... */
} mmVertexDataBase;
#pragma pack(pop)

_Static_assert(offsetof(mmVertexDataBase, vtable) == 0x00, "mmVertexDataBase.vtable");
_Static_assert(offsetof(mmVertexDataBase, flags) == 0x08, "mmVertexDataBase.flags");
_Static_assert(offsetof(mmVertexDataBase, pad_000A) == 0x0A, "mmVertexDataBase.pad_000A");
_Static_assert(offsetof(mmVertexDataBase, refcount_or_flags) == 0x0E, "mmVertexDataBase.refcount_or_flags");
_Static_assert(offsetof(mmVertexDataBase, pad_0012) == 0x12, "mmVertexDataBase.pad_0012");
_Static_assert(offsetof(mmVertexDataBase, field_0x18) == 0x18, "mmVertexDataBase.field_0x18");
_Static_assert(offsetof(mmVertexDataBase, field_0x20) == 0x20, "mmVertexDataBase.field_0x20");
_Static_assert(offsetof(mmVertexDataBase, field_0x28) == 0x28, "mmVertexDataBase.field_0x28");
_Static_assert(offsetof(mmVertexDataBase, allocator_vtable) == 0x30, "mmVertexDataBase.allocator_vtable");
_Static_assert(offsetof(mmVertexDataBase, field_0x38) == 0x38, "mmVertexDataBase.field_0x38");
_Static_assert(offsetof(mmVertexDataBase, list_node_0x40) == 0x40, "mmVertexDataBase.list_node_0x40");
_Static_assert(offsetof(mmVertexDataBase, list_node_0x48) == 0x48, "mmVertexDataBase.list_node_0x48");
_Static_assert(offsetof(mmVertexDataBase, list_node_0x50) == 0x50, "mmVertexDataBase.list_node_0x50");
_Static_assert(offsetof(mmVertexDataBase, field_0x58) == 0x58, "mmVertexDataBase.field_0x58");
_Static_assert(offsetof(mmVertexDataBase, pad_005C) == 0x5C, "mmVertexDataBase.pad_005C");
_Static_assert(offsetof(mmVertexDataBase, sub_list_a_head) == 0x60, "mmVertexDataBase.sub_list_a_head");
_Static_assert(offsetof(mmVertexDataBase, sub_list_a_tail) == 0x68, "mmVertexDataBase.sub_list_a_tail");
_Static_assert(offsetof(mmVertexDataBase, field_0x70) == 0x70, "mmVertexDataBase.field_0x70");
_Static_assert(offsetof(mmVertexDataBase, sub_list_b_prev) == 0x78, "mmVertexDataBase.sub_list_b_prev");
_Static_assert(offsetof(mmVertexDataBase, sub_list_b_next) == 0x80, "mmVertexDataBase.sub_list_b_next");
_Static_assert(offsetof(mmVertexDataBase, sub_list_b_sentinel) == 0x88, "mmVertexDataBase.sub_list_b_sentinel");
_Static_assert(offsetof(mmVertexDataBase, field_0x90) == 0x90, "mmVertexDataBase.field_0x90");
_Static_assert(offsetof(mmVertexDataBase, pad_0098) == 0x98, "mmVertexDataBase.pad_0098");
_Static_assert(offsetof(mmVertexDataBase, sub_list_c_head) == 0xA8, "mmVertexDataBase.sub_list_c_head");
_Static_assert(offsetof(mmVertexDataBase, sub_list_c_tail) == 0xB0, "mmVertexDataBase.sub_list_c_tail");
_Static_assert(offsetof(mmVertexDataBase, sub_list_c_sentinel) == 0xB8, "mmVertexDataBase.sub_list_c_sentinel");
_Static_assert(offsetof(mmVertexDataBase, pad_00C0) == 0xC0, "mmVertexDataBase.pad_00C0");
_Static_assert(offsetof(mmVertexDataBase, sub_list_d_prev) == 0xC8, "mmVertexDataBase.sub_list_d_prev");
_Static_assert(offsetof(mmVertexDataBase, sub_list_d_next) == 0xD0, "mmVertexDataBase.sub_list_d_next");
_Static_assert(offsetof(mmVertexDataBase, field_0xD8) == 0xD8, "mmVertexDataBase.field_0xD8");
_Static_assert(offsetof(mmVertexDataBase, pad_00E0) == 0xE0, "mmVertexDataBase.pad_00E0");
_Static_assert(offsetof(mmVertexDataBase, sub_list_e_sentinel) == 0xE8, "mmVertexDataBase.sub_list_e_sentinel");
_Static_assert(offsetof(mmVertexDataBase, field_0xF0) == 0xF0, "mmVertexDataBase.field_0xF0");
_Static_assert(offsetof(mmVertexDataBase, pad_00F8) == 0xF8, "mmVertexDataBase.pad_00F8");
_Static_assert(offsetof(mmVertexDataBase, field_0x108) == 0x108, "mmVertexDataBase.field_0x108");
_Static_assert(offsetof(mmVertexDataBase, field_0x110) == 0x110, "mmVertexDataBase.field_0x110");
_Static_assert(offsetof(mmVertexDataBase, field_0x118) == 0x118, "mmVertexDataBase.field_0x118");
_Static_assert(offsetof(mmVertexDataBase, pad_0120) == 0x120, "mmVertexDataBase.pad_0120");
_Static_assert(offsetof(mmVertexDataBase, sub_list_f_sentinel) == 0x128, "mmVertexDataBase.sub_list_f_sentinel");
_Static_assert(offsetof(mmVertexDataBase, field_0x130) == 0x130, "mmVertexDataBase.field_0x130");

/* ========================================================================
 * mmVertexData — concrete vertex data (inherits mmVertexDataBase pattern)
 * Size unknown, >= 0xA8. Vtable: PTR_FUN_140774d68 at offset 0x00.
 * Layout from ~mmVertexData (0x11C830), CreateData (0x11C8B0), Release (0x11CB10).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVertexData {
    uint8_t vtable[8];                /* 0x00: u64* PTR_FUN_140774d68 */
    uint8_t vertex_buffer[8];         /* 0x08: u64 void* freed in dtor/Release */
    uint8_t field_0x10[8];            /* 0x10: u64 zeroed in dtor */
    uint8_t field_0x18[8];            /* 0x18: u64 DAT_140b8e4e8 written in dtor */
    uint8_t field_0x20[4];            /* 0x20: u32 part of param_1[4] area */
    uint8_t pad_0024[4];              /* 0x24: padding to 0x28 */
    uint8_t field_0x28[4];            /* 0x28: u32 DAT_140b8e4e8 written at 0x28 */
    uint8_t field_0x2C[4];            /* 0x2C: u32 DAT_140b8e4f0 written at 0x2c */
    uint8_t pad_0030[8];              /* 0x30: padding to 0x38 */
    uint8_t render_info_tree_base[8]; /* 0x38: u64 tree sentinel for render info lookup */
    uint8_t render_info_tree_right[8];/* 0x40: u64 right child */
    uint8_t render_info_tree_root[8]; /* 0x48: u64 root ptr */
    uint8_t field_0x50[1];            /* 0x50: u8 byte flag zeroed in Release */
    uint8_t pad_0051[7];              /* 0x51: padding to 0x58 */
    uint8_t field_0x58[4];            /* 0x58: u32 zeroed in Release */
    uint8_t pad_005C[20];             /* 0x5C: padding to 0x70 */
    uint8_t sub_obj_0x70[8];          /* 0x70: u64 FUN_140111840 target */
    uint8_t sub_list_sentinel[8];     /* 0x78: u64 self-linked list sentinel */
    uint8_t sub_list_head[8];         /* 0x80: u64 list head ptr */
    uint8_t sub_list_nodes[8];        /* 0x88: u64 linked list walked in Release */
    uint8_t field_0x90[1];            /* 0x90: u8 byte flag zeroed in Release */
    uint8_t pad_0091[7];              /* 0x91: padding to 0x98 */
    uint8_t field_0x98[4];            /* 0x98: u32 zeroed in Release */
    uint8_t pad_009C[4];              /* 0x9C: padding to 0xA0 */
    uint8_t allocator_vtable[8];      /* 0xA0: u64 vtable for node allocator */
    /* ... size unknown, >= 0xA8 ... */
} mmVertexData;
#pragma pack(pop)

_Static_assert(offsetof(mmVertexData, vtable) == 0x00, "mmVertexData.vtable");
_Static_assert(offsetof(mmVertexData, vertex_buffer) == 0x08, "mmVertexData.vertex_buffer");
_Static_assert(offsetof(mmVertexData, field_0x10) == 0x10, "mmVertexData.field_0x10");
_Static_assert(offsetof(mmVertexData, field_0x18) == 0x18, "mmVertexData.field_0x18");
_Static_assert(offsetof(mmVertexData, field_0x20) == 0x20, "mmVertexData.field_0x20");
_Static_assert(offsetof(mmVertexData, pad_0024) == 0x24, "mmVertexData.pad_0024");
_Static_assert(offsetof(mmVertexData, field_0x28) == 0x28, "mmVertexData.field_0x28");
_Static_assert(offsetof(mmVertexData, field_0x2C) == 0x2C, "mmVertexData.field_0x2C");
_Static_assert(offsetof(mmVertexData, pad_0030) == 0x30, "mmVertexData.pad_0030");
_Static_assert(offsetof(mmVertexData, render_info_tree_base) == 0x38, "mmVertexData.render_info_tree_base");
_Static_assert(offsetof(mmVertexData, render_info_tree_right) == 0x40, "mmVertexData.render_info_tree_right");
_Static_assert(offsetof(mmVertexData, render_info_tree_root) == 0x48, "mmVertexData.render_info_tree_root");
_Static_assert(offsetof(mmVertexData, field_0x50) == 0x50, "mmVertexData.field_0x50");
_Static_assert(offsetof(mmVertexData, pad_0051) == 0x51, "mmVertexData.pad_0051");
_Static_assert(offsetof(mmVertexData, field_0x58) == 0x58, "mmVertexData.field_0x58");
_Static_assert(offsetof(mmVertexData, pad_005C) == 0x5C, "mmVertexData.pad_005C");
_Static_assert(offsetof(mmVertexData, sub_obj_0x70) == 0x70, "mmVertexData.sub_obj_0x70");
_Static_assert(offsetof(mmVertexData, sub_list_sentinel) == 0x78, "mmVertexData.sub_list_sentinel");
_Static_assert(offsetof(mmVertexData, sub_list_head) == 0x80, "mmVertexData.sub_list_head");
_Static_assert(offsetof(mmVertexData, sub_list_nodes) == 0x88, "mmVertexData.sub_list_nodes");
_Static_assert(offsetof(mmVertexData, field_0x90) == 0x90, "mmVertexData.field_0x90");
_Static_assert(offsetof(mmVertexData, pad_0091) == 0x91, "mmVertexData.pad_0091");
_Static_assert(offsetof(mmVertexData, field_0x98) == 0x98, "mmVertexData.field_0x98");
_Static_assert(offsetof(mmVertexData, pad_009C) == 0x9C, "mmVertexData.pad_009C");
_Static_assert(offsetof(mmVertexData, allocator_vtable) == 0xA0, "mmVertexData.allocator_vtable");

/* ========================================================================
 * mmVertexDataStream — streaming vertex data buffer with shadow copy
 * Size unknown, >= 0x80. Vtable not observed.
 * Layout from CreateData (0x118650), CreateDataStream (0x1255E0), Release (0x1257A0).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVertexDataStream {
    uint8_t pad_0000[16];             /* 0x00: unknown header */
    uint8_t sub_object[8];            /* 0x10: u64 sub-object passed to mmVBRenderInfoList::Add */
    uint8_t pad_0018[24];             /* 0x18: padding to 0x30 */
    uint8_t parent_or_config[8];      /* 0x30: u64 parent/config ptr read by CreateDataStream */
    uint8_t pad_0038[32];             /* 0x38: padding to 0x58 */
    uint8_t stream_array_begin[8];    /* 0x58: u64 begin of stream entry array stride 0x20 */
    uint8_t stream_array_end[8];      /* 0x60: u64 end of stream entry array */
    uint8_t pad_0068[16];             /* 0x68: padding to 0x78 */
    uint8_t shadow_buffer[8];         /* 0x78: u64 void* optional shadow copy freed in Release */
    /* ... size unknown, >= 0x80 ... */
} mmVertexDataStream;
#pragma pack(pop)

_Static_assert(offsetof(mmVertexDataStream, pad_0000) == 0x00, "mmVertexDataStream.pad_0000");
_Static_assert(offsetof(mmVertexDataStream, sub_object) == 0x10, "mmVertexDataStream.sub_object");
_Static_assert(offsetof(mmVertexDataStream, pad_0018) == 0x18, "mmVertexDataStream.pad_0018");
_Static_assert(offsetof(mmVertexDataStream, parent_or_config) == 0x30, "mmVertexDataStream.parent_or_config");
_Static_assert(offsetof(mmVertexDataStream, pad_0038) == 0x38, "mmVertexDataStream.pad_0038");
_Static_assert(offsetof(mmVertexDataStream, stream_array_begin) == 0x58, "mmVertexDataStream.stream_array_begin");
_Static_assert(offsetof(mmVertexDataStream, stream_array_end) == 0x60, "mmVertexDataStream.stream_array_end");
_Static_assert(offsetof(mmVertexDataStream, pad_0068) == 0x68, "mmVertexDataStream.pad_0068");
_Static_assert(offsetof(mmVertexDataStream, shadow_buffer) == 0x78, "mmVertexDataStream.shadow_buffer");

/* ========================================================================
 * mmVertexShader — compiled vertex shader object
 * Size unknown, >= 0xF8. Vtable not set in observed methods.
 * Layout from LoadFromCompiledFile (0x1170E0, 0x117340), LoadFromCompiledMemory (0x117230).
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmVertexShader {
    uint8_t pad_0000[200];            /* 0x00: large header before known fields */
    uint8_t debug_string_ref[8];      /* 0xC8: u64 "ShaderCompiledFromMemory.fx" context */
    uint8_t pad_00D0[32];             /* 0xD0: padding to 0xF0 */
    uint8_t compiled_shader_blob[8];  /* 0xF0: u64 void* compiled shader data ptr null-checked */
    /* ... size unknown, >= 0xF8 ... */
} mmVertexShader;
#pragma pack(pop)

_Static_assert(offsetof(mmVertexShader, debug_string_ref) == 0xC8, "mmVertexShader.debug_string_ref");
_Static_assert(offsetof(mmVertexShader, compiled_shader_blob) == 0xF0, "mmVertexShader.compiled_shader_blob");

/* ========================================================================
 * mmXMLSerializeReader — XML deserialization reader
 * Size unknown, >= 0x1C0. Vtable not observed.
 * Layout from CheckTypeID (0x108060), LoadObject (0x108B20).
 * Shares layout prefix with writer.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmXMLSerializeReader {
    uint8_t vtable_or_base[8];        /* 0x00: u64* base/vtable ptr */
    uint8_t current_node[8];          /* 0x08: u64 advanced by +0x10 per node */
    uint8_t node_end[8];              /* 0x10: u64 bounds check */
    uint8_t pad_0018[8];              /* 0x18: padding */
    uint8_t data_buffer[8];           /* 0x20: u64 base data buffer pointer */
    uint8_t pad_0028[32];             /* 0x28: padding to 0x48 */
    uint8_t current_offset[4];        /* 0x48: u32 offset into data_buffer 0xFFFFFFFF invalid */
    uint8_t pad_004C[52];             /* 0x4C: padding to 0x80 */
    uint8_t sub_object_0x80[8];       /* 0x80: u64 sub-object shared layout with writer */
    uint8_t pad_0088[304];            /* 0x88: padding to 0x1B8 */
    uint8_t metadata_ptr[8];          /* 0x1B8: u64 metadata/type-info pointer */
    /* ... size unknown, >= 0x1C0 ... */
} mmXMLSerializeReader;
#pragma pack(pop)

_Static_assert(offsetof(mmXMLSerializeReader, vtable_or_base) == 0x00, "mmXMLSerializeReader.vtable_or_base");
_Static_assert(offsetof(mmXMLSerializeReader, current_node) == 0x08, "mmXMLSerializeReader.current_node");
_Static_assert(offsetof(mmXMLSerializeReader, node_end) == 0x10, "mmXMLSerializeReader.node_end");
_Static_assert(offsetof(mmXMLSerializeReader, data_buffer) == 0x20, "mmXMLSerializeReader.data_buffer");
_Static_assert(offsetof(mmXMLSerializeReader, current_offset) == 0x48, "mmXMLSerializeReader.current_offset");
_Static_assert(offsetof(mmXMLSerializeReader, sub_object_0x80) == 0x80, "mmXMLSerializeReader.sub_object_0x80");
_Static_assert(offsetof(mmXMLSerializeReader, metadata_ptr) == 0x1B8, "mmXMLSerializeReader.metadata_ptr");

/* ========================================================================
 * mmXMLSerializeWriter — XML serialization writer
 * Size unknown, >= 0x1C0. Vtable not observed.
 * Layout from SaveObject<mmObject> (0x108950).
 * Shares layout prefix with reader.
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct mmXMLSerializeWriter {
    uint8_t vtable_or_base[8];        /* 0x00: u64* base/vtable ptr */
    uint8_t pad_0008[24];             /* 0x08: padding to 0x20 */
    uint8_t data_buffer[8];           /* 0x20: u64 base data buffer pointer */
    uint8_t pad_0028[32];             /* 0x28: padding to 0x48 */
    uint8_t current_offset[4];        /* 0x48: u32 offset into data_buffer 0xFFFFFFFF invalid */
    uint8_t pad_004C[52];             /* 0x4C: padding to 0x80 */
    uint8_t output_sub_object[8];     /* 0x80: u64 output target sub-object */
    uint8_t pad_0088[304];            /* 0x88: padding to 0x1B8 */
    uint8_t metadata_ptr[8];          /* 0x1B8: u64 metadata/type-info pointer */
    /* ... size unknown, >= 0x1C0 ... */
} mmXMLSerializeWriter;
#pragma pack(pop)

_Static_assert(offsetof(mmXMLSerializeWriter, vtable_or_base) == 0x00, "mmXMLSerializeWriter.vtable_or_base");
_Static_assert(offsetof(mmXMLSerializeWriter, data_buffer) == 0x20, "mmXMLSerializeWriter.data_buffer");
_Static_assert(offsetof(mmXMLSerializeWriter, current_offset) == 0x48, "mmXMLSerializeWriter.current_offset");
_Static_assert(offsetof(mmXMLSerializeWriter, output_sub_object) == 0x80, "mmXMLSerializeWriter.output_sub_object");
_Static_assert(offsetof(mmXMLSerializeWriter, metadata_ptr) == 0x1B8, "mmXMLSerializeWriter.metadata_ptr");

#endif /* CMN34_H */