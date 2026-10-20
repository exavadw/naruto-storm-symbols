/* cmn46.h — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 * Reconstructed struct layouts for cmn46 group.
 * All offsets derived from x64 decompile of NSUNS4_release.exe (image base 0x140000000).
 * SHA256: 147e52a3e0d7382501a6777e158b37908e0b69d4e902079dc6e62dcae69bc257
 * Field names carried from s3 where layout matches; re-verified in s4 code.
 * Everything static is INFERRED, not CONFIRMED.
 * Sizes proven from allocator calls / ctor access bounds where noted.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccCdSpring — collision detection spring element
 * Vtable: PTR_FUN_141113fb8 at offset 0xB0 (set in ctor after sub-object init)
 * Size proof: s4 ctor accesses up to offset 0xE8 (flags_byte & 0xf3 | 3);
 *   layout matches s3 exactly; s3 proven size 0xF0 carried forward.
 * Proven size = 0xF0 (INFERRED from s3 + s4 ctor match).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSpring {
    /* 0x00 */ void*       vtable_base;           /* set by base init, overwritten at 0xB0 */
    uint8_t     _pad_08[0x38];                   /* 0x08-0x3F: sub-objects initialized via FUN_140a04640 */
    /* 0x40 */ uint8_t     subobj_40[0x0C];       /* FUN_140a04640(param_1+0x40, ...) */
    /* 0x4C */ uint8_t     subobj_4c[0x0C];       /* FUN_140a04640(param_1+0x4c, ...) */
    /* 0x58 */ uint8_t     subobj_58[0x0C];       /* FUN_140a04640(param_1+0x58, ...) */
    /* 0x64 */ uint8_t     subobj_64[0x0C];       /* FUN_140a04640(param_1+0x64, ...) */
    /* 0x70 */ uint8_t     subobj_70[0x10];       /* FUN_140a04640(param_1+0x70, ...) */
    /* 0x80 */ void*       child_ptr;             /* ptr=0 in ctor */
    /* 0x88 */ float       spring_k;              /* float=0 in ctor; stiffness coefficient */
    /* 0x8C */ float       spring_damping;        /* float=1.0 (0x3f800000) in ctor */
    /* 0x90 */ double      spring_mass;           /* double=1.0 in ctor */
    /* 0x98 */ int32_t     spring_flags;          /* int=0 in ctor */
    uint8_t     _pad_9C[0x04];                   /* 0x9C-0x9F */
    /* 0xA0 */ void*       coord_data_0;          /* ptr=0 in ctor */
    /* 0xA8 */ void*       coord_data_1;          /* ptr=0 in ctor */
    /* 0xB0 */ void*       vtable;                /* PTR_FUN_141113fb8 set in ctor */
    uint8_t     _pad_B8[0x10];                   /* 0xB8-0xC7 */
    /* 0xC8 */ void*       linked_prev;           /* ptr=0 in ctor */
    /* 0xD0 */ void*       linked_next_unused;    /* ptr=0 in ctor */
    /* 0xD8 */ void*       linked_parent;         /* ptr=0 in ctor */
    /* 0xE0 */ uint16_t    spring_index;          /* ushort=0 in ctor */
    uint8_t     _pad_E2[0x06];                   /* 0xE2-0xE7 */
    /* 0xE8 */ uint8_t     flags_byte;            /* byte flags; bit 0/1 cleared & 0xf3 | 3 */
    uint8_t     _pad_E9[0x07];                   /* 0xE9-0xEF */
} nuccCdSpring;

static_assert(offsetof(nuccCdSpring, vtable_base) == 0x00, "nuccCdSpring.vtable_base");
static_assert(offsetof(nuccCdSpring, subobj_40) == 0x40, "nuccCdSpring.subobj_40");
static_assert(offsetof(nuccCdSpring, subobj_4c) == 0x4C, "nuccCdSpring.subobj_4c");
static_assert(offsetof(nuccCdSpring, subobj_58) == 0x58, "nuccCdSpring.subobj_58");
static_assert(offsetof(nuccCdSpring, subobj_64) == 0x64, "nuccCdSpring.subobj_64");
static_assert(offsetof(nuccCdSpring, subobj_70) == 0x70, "nuccCdSpring.subobj_70");
static_assert(offsetof(nuccCdSpring, child_ptr) == 0x80, "nuccCdSpring.child_ptr");
static_assert(offsetof(nuccCdSpring, spring_k) == 0x88, "nuccCdSpring.spring_k");
static_assert(offsetof(nuccCdSpring, spring_damping) == 0x8C, "nuccCdSpring.spring_damping");
static_assert(offsetof(nuccCdSpring, spring_mass) == 0x90, "nuccCdSpring.spring_mass");
static_assert(offsetof(nuccCdSpring, spring_flags) == 0x98, "nuccCdSpring.spring_flags");
static_assert(offsetof(nuccCdSpring, coord_data_0) == 0xA0, "nuccCdSpring.coord_data_0");
static_assert(offsetof(nuccCdSpring, coord_data_1) == 0xA8, "nuccCdSpring.coord_data_1");
static_assert(offsetof(nuccCdSpring, vtable) == 0xB0, "nuccCdSpring.vtable");
static_assert(offsetof(nuccCdSpring, linked_prev) == 0xC8, "nuccCdSpring.linked_prev");
static_assert(offsetof(nuccCdSpring, linked_next_unused) == 0xD0, "nuccCdSpring.linked_next_unused");
static_assert(offsetof(nuccCdSpring, linked_parent) == 0xD8, "nuccCdSpring.linked_parent");
static_assert(offsetof(nuccCdSpring, spring_index) == 0xE0, "nuccCdSpring.spring_index");
static_assert(offsetof(nuccCdSpring, flags_byte) == 0xE8, "nuccCdSpring.flags_byte");
static_assert(sizeof(nuccCdSpring) == 0xF0, "nuccCdSpring size must be 0xF0");


/* ========================================================================
 * nuccCdSpringGrp — spring group containing multiple springs
 * Size proof: s4 ctor initializes sub-objects at 0x00, 0x28, 0x34, 0x40, 0x4C;
 *   last access at 0x4C+8 → size ≥ 0x54; s3 proven size 0x58 carried forward.
 * No vtable (sub-object, not polymorphic).
 * Proven size = 0x58 (INFERRED from s3 + s4 ctor match).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSpringGrp {
    /* 0x00 */ uint8_t     base_subobj[0x10];     /* initialized via FUN_140a04690/FUN_140a04dd0 */
    /* 0x10 */ void*       spr_list_head;         /* ptr=0 in ctor */
    /* 0x18 */ void*       spr_list_tail;         /* ptr=0 in ctor */
    /* 0x20 */ void*       spr_list_end;          /* ptr=0 in ctor */
    /* 0x28 */ uint8_t     subobj_28[0x0C];       /* initialized via FUN_140a04690 */
    /* 0x34 */ uint8_t     subobj_34[0x0C];       /* initialized via FUN_140a04690 */
    /* 0x40 */ uint8_t     subobj_40[0x0C];       /* initialized via FUN_140a04690 */
    /* 0x4C */ uint8_t     subobj_4c[0x0C];       /* initialized via FUN_140a04690; last field */
} nuccCdSpringGrp;

static_assert(offsetof(nuccCdSpringGrp, base_subobj) == 0x00, "nuccCdSpringGrp.base_subobj");
static_assert(offsetof(nuccCdSpringGrp, spr_list_head) == 0x10, "nuccCdSpringGrp.spr_list_head");
static_assert(offsetof(nuccCdSpringGrp, spr_list_tail) == 0x18, "nuccCdSpringGrp.spr_list_tail");
static_assert(offsetof(nuccCdSpringGrp, spr_list_end) == 0x20, "nuccCdSpringGrp.spr_list_end");
static_assert(offsetof(nuccCdSpringGrp, subobj_28) == 0x28, "nuccCdSpringGrp.subobj_28");
static_assert(offsetof(nuccCdSpringGrp, subobj_34) == 0x34, "nuccCdSpringGrp.subobj_34");
static_assert(offsetof(nuccCdSpringGrp, subobj_40) == 0x40, "nuccCdSpringGrp.subobj_40");
static_assert(offsetof(nuccCdSpringGrp, subobj_4c) == 0x4C, "nuccCdSpringGrp.subobj_4c");
static_assert(sizeof(nuccCdSpringGrp) == 0x58, "nuccCdSpringGrp size must be 0x58");


/* ========================================================================
 * nuccCdSprTreeNode — node within a spring tree (intrusive linked list element)
 * Node stride: 0x58 bytes (ZEXT816(0x58) * count in nuccCdSprTree ctor)
 * Vtable: PTR_FUN_141112250 (shared with parent tree in s4)
 * Fields zeroed in ctor loop; node_flag at byte offset 0x52.
 * Proven size = 0x58 (stride from array allocation).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSprTreeNode {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_141112250 */
    uint8_t     _pad_08[0x10];                   /* 0x08-0x17: zeroed in ctor loop */
    /* 0x18 */ void*       node_prev;             /* self-pointer initially (intrusive list) */
    /* 0x20 */ void*       node_next;             /* self-pointer initially */
    uint8_t     _pad_28[0x2A];                   /* 0x28-0x51: zeroed fields */
    /* 0x52 */ uint8_t     node_flag;             /* byte flag, zeroed in ctor */
    uint8_t     _pad_53[0x05];                   /* 0x53-0x57 */
} nuccCdSprTreeNode;

static_assert(offsetof(nuccCdSprTreeNode, vtable) == 0x00, "nuccCdSprTreeNode.vtable");
static_assert(offsetof(nuccCdSprTreeNode, node_prev) == 0x18, "nuccCdSprTreeNode.node_prev");
static_assert(offsetof(nuccCdSprTreeNode, node_next) == 0x20, "nuccCdSprTreeNode.node_next");
static_assert(offsetof(nuccCdSprTreeNode, node_flag) == 0x52, "nuccCdSprTreeNode.node_flag");
static_assert(sizeof(nuccCdSprTreeNode) == 0x58, "nuccCdSprTreeNode stride must be 0x58");


/* ========================================================================
 * nuccCdSprTree — spring tree with dynamically allocated node array
 * Vtable: PTR_FUN_141112250 at offset 0x00
 * Source string confirms "nuccCdSprTree.cpp".
 * Node array allocated via FUN_140a018c0(count*0x58+8, "...nuccCdSprTree.cpp", ...).
 * Tree struct: param_1[0xf] = offset 0x78, so size >= 0x80.
 * default_value at *(uint32*)(param_1+100) = offset 0x64, value 5.
 * Byte flag at 0x52 confirmed in state_surface.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSprTree {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_141112250 */
    /* 0x08 */ void*       field_08;              /* param_1[1]=0 */
    /* 0x10 */ void*       field_10;              /* param_1[2]=0 */
    /* 0x18 */ void*       self_ptr_18;           /* param_1[3]=param_1 (self-reference) */
    /* 0x20 */ void*       self_ptr_20;           /* param_1[4]=param_1 (self-reference) */
    /* 0x28 */ void*       field_28;              /* param_1[5]=0 */
    /* 0x30 */ void*       field_30;              /* param_1[6]=0 */
    /* 0x38 */ void*       field_38;              /* param_1[7]=0 */
    /* 0x40 */ void*       field_40;              /* param_1[8]=0 */
    /* 0x48 */ void*       field_48;              /* param_1[9]=0 */
    /* 0x50 */ uint32_t    default_value;         /* *(uint32*)(param_1+100)=5 */
    uint8_t     _pad_54[0x04];                   /* 0x54-0x57 */
    /* 0x58 */ nuccCdSprTreeNode* node_array;     /* param_1[0xb] = allocated node array ptr */
    /* 0x60 */ uint16_t    node_count;            /* *(ushort*)(param_1+0xc) = count */
    uint8_t     _pad_62[0x06];                   /* 0x62-0x67 */
    /* 0x68 */ void*       field_68;              /* param_1[0xd]=0 */
    /* 0x70 */ void*       field_70;              /* param_1[0xe]=0 */
    /* 0x78 */ void*       field_78;              /* param_1[0xf]=0 */
} nuccCdSprTree;

static_assert(offsetof(nuccCdSprTree, vtable) == 0x00, "nuccCdSprTree.vtable");
static_assert(offsetof(nuccCdSprTree, field_08) == 0x08, "nuccCdSprTree.field_08");
static_assert(offsetof(nuccCdSprTree, field_10) == 0x10, "nuccCdSprTree.field_10");
static_assert(offsetof(nuccCdSprTree, self_ptr_18) == 0x18, "nuccCdSprTree.self_ptr_18");
static_assert(offsetof(nuccCdSprTree, self_ptr_20) == 0x20, "nuccCdSprTree.self_ptr_20");
static_assert(offsetof(nuccCdSprTree, field_28) == 0x28, "nuccCdSprTree.field_28");
static_assert(offsetof(nuccCdSprTree, field_30) == 0x30, "nuccCdSprTree.field_30");
static_assert(offsetof(nuccCdSprTree, field_38) == 0x38, "nuccCdSprTree.field_38");
static_assert(offsetof(nuccCdSprTree, field_40) == 0x40, "nuccCdSprTree.field_40");
static_assert(offsetof(nuccCdSprTree, field_48) == 0x48, "nuccCdSprTree.field_48");
static_assert(offsetof(nuccCdSprTree, default_value) == 0x50, "nuccCdSprTree.default_value");
static_assert(offsetof(nuccCdSprTree, node_array) == 0x58, "nuccCdSprTree.node_array");
static_assert(offsetof(nuccCdSprTree, node_count) == 0x60, "nuccCdSprTree.node_count");
static_assert(offsetof(nuccCdSprTree, field_68) == 0x68, "nuccCdSprTree.field_68");
static_assert(offsetof(nuccCdSprTree, field_70) == 0x70, "nuccCdSprTree.field_70");
static_assert(offsetof(nuccCdSprTree, field_78) == 0x78, "nuccCdSprTree.field_78");


/* ========================================================================
 * nuccCdSpringCtrl — spring controller managing groups and hit elements
 * Header allocated via FUN_140a017f0(0x20,"..\\source\\math\\nuccCdSpringCtrl.cpp",...).
 * DeleteHitElpAll traverses grp lists at param_1+0x08 and param_1+0x10,
 *   following next pointers at lVar3+0x100 within each group node.
 * Main reads param_1+0x1C (int32, read-only per state_surface).
 * ResetPosImmidiate iterates *param_1 (spr_tree ptr) following +0x20 links.
 * Size >= 0x20 (allocator proof); s3 had >= 0x180 but that included
 *   embedded sub-objects that are now separately allocated in s4.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSpringCtrl {
    /* 0x00 */ void*       spr_tree;              /* nuccCdSprTree*; iterated in ResetPosImmidiate */
    /* 0x08 */ void*       grp_list_head;         /* linked list head of CdSpringGrp nodes */
    /* 0x10 */ void*       grp_list_tail;         /* linked list tail */
    /* 0x18 */ int32_t     field_18;              /* zeroed in Create */
    /* 0x1C */ uint32_t    dat_ref;               /* read in Main; DAT reference */
} nuccCdSpringCtrl;

static_assert(offsetof(nuccCdSpringCtrl, spr_tree) == 0x00, "nuccCdSpringCtrl.spr_tree");
static_assert(offsetof(nuccCdSpringCtrl, grp_list_head) == 0x08, "nuccCdSpringCtrl.grp_list_head");
static_assert(offsetof(nuccCdSpringCtrl, grp_list_tail) == 0x10, "nuccCdSpringCtrl.grp_list_tail");
static_assert(offsetof(nuccCdSpringCtrl, field_18) == 0x18, "nuccCdSpringCtrl.field_18");
static_assert(offsetof(nuccCdSpringCtrl, dat_ref) == 0x1C, "nuccCdSpringCtrl.dat_ref");
static_assert(sizeof(nuccCdSpringCtrl) == 0x20, "nuccCdSpringCtrl size must be 0x20");


/* ========================================================================
 * nuccChannel — request channel / message queue
 * Vtable: PTR_FUN_14110b3f0 at offset 0x00 (set in ctor)
 * Inner vtable: PTR_FUN_1410075d8 at offset 0xB8 (sub-object at param_1+0xB8)
 * Vector storage at offsets 0xA0, 0xA8, 0xB0.
 * Size proof: ctor capacity check with grow call; last access at 0xD0+4.
 * Size >= 0xD4 (INFERRED from s4 ctor; s3 had >= 0xD8).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChannel {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_14110b3f0 */
    /* 0x08 */ uint32_t    channel_id;            /* [1]=0 in ctor (uint32) */
    uint8_t     _pad_0C[0x04];                   /* 0x0C-0x0F */
    /* 0x10 */ uint8_t     subobj_10[0x08];       /* initialized via sub-init */
    /* 0x18 */ uint8_t     subobj_18[0x88];       /* large sub-object block */
    /* 0xA0 */ void*       vec_begin;             /* vector begin pointer */
    /* 0xA8 */ void*       vec_end;               /* vector end pointer */
    /* 0xB0 */ void*       vec_capacity;          /* vector capacity/end-of-storage */
    /* 0xB8 */ uint8_t     subobj_b8[0x18];       /* sub-object with vtable PTR_FUN_1410075d8 */
    /* 0xD0 */ uint32_t    field_d0;              /* write-only per state_surface */
    uint8_t     _pad_D4[0x04];                   /* 0xD4-0xD7 */
} nuccChannel;

static_assert(offsetof(nuccChannel, vtable) == 0x00, "nuccChannel.vtable");
static_assert(offsetof(nuccChannel, channel_id) == 0x08, "nuccChannel.channel_id");
static_assert(offsetof(nuccChannel, subobj_10) == 0x10, "nuccChannel.subobj_10");
static_assert(offsetof(nuccChannel, subobj_18) == 0x18, "nuccChannel.subobj_18");
static_assert(offsetof(nuccChannel, vec_begin) == 0xA0, "nuccChannel.vec_begin");
static_assert(offsetof(nuccChannel, vec_end) == 0xA8, "nuccChannel.vec_end");
static_assert(offsetof(nuccChannel, vec_capacity) == 0xB0, "nuccChannel.vec_capacity");
static_assert(offsetof(nuccChannel, subobj_b8) == 0xB8, "nuccChannel.subobj_b8");
static_assert(offsetof(nuccChannel, field_d0) == 0xD0, "nuccChannel.field_d0");


/* ========================================================================
 * nuccChunk — base chunk class (abstract)
 * Vtable: set in subclasses. Minimal struct; GetName/GetHash/GetType are virtual.
 * Size unknown, >= 0x08 (vtable pointer only proven).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunk {
    /* 0x00 */ void*       vtable;
} nuccChunk;

static_assert(offsetof(nuccChunk, vtable) == 0x00, "nuccChunk.vtable");


/* ========================================================================
 * nuccChunkAnm — animation chunk with particle/trail sub-objects
 * Vtable: PTR_FUN_14110f7a0 at offset 0x00
 * Source string confirms "nuccChunkAnm.cpp".
 * Five sub-object blocks initialized in ctor at 0x10, 0x38, 0x60, 0x90, 0xB8.
 * Parse writes trail_data at 0xD0, trail_count at 0xD8, trail_flag at 0xDA,
 *   anm_resource at 0xE0; also writes arrays at 0x18/0x28/0x30, 0x40/0x50/0x58,
 *   0x68/0x78/0x80, and scalar at 0x88. Calls FUN_140a85900(param_1+0x90).
 * Size proof: s3 allocator FUN_140580190(0x1b8,"...nuccChunkAnm.cpp");
 *   s4 Parse accesses match s3 layout exactly through 0xE0+.
 * Proven size = 0x1B8 (INFERRED from s3 allocator + s4 layout match).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAnm {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_14110f7a0 */
    uint8_t     _pad_08[0x08];                   /* 0x08-0x0F */
    /* 0x10 */ uint8_t     subobj_anm_10[0x08];   /* sub-object block (vtable PTR_FUN_141108b68) */
    /* 0x18 */ void*       array_18;              /* allocated array ptr (from Parse) */
    /* 0x20 */ uint8_t     _pad_20[0x08];         /* 0x20-0x27 */
    /* 0x28 */ void*       array_28;              /* allocated array ptr (from Parse) */
    /* 0x30 */ uint32_t    count_30;              /* array count (from Parse) */
    uint8_t     _pad_34[0x04];                   /* 0x34-0x37 */
    /* 0x38 */ uint8_t     subobj_anm_38[0x08];   /* sub-object block (vtable PTR_FUN_141108b68) */
    /* 0x40 */ void*       array_40;              /* allocated array ptr (from Parse) */
    /* 0x48 */ uint8_t     _pad_48[0x08];         /* 0x48-0x4F */
    /* 0x50 */ void*       array_50;              /* allocated array ptr (from Parse) */
    /* 0x58 */ uint32_t    count_58;              /* array count (from Parse) */
    uint8_t     _pad_5C[0x04];                   /* 0x5C-0x5F */
    /* 0x60 */ uint8_t     subobj_anm_60[0x08];   /* sub-object block (vtable PTR_FUN_141107788) */
    /* 0x68 */ void*       array_68;              /* allocated array ptr (from Parse) */
    /* 0x70 */ uint8_t     _pad_70[0x08];         /* 0x70-0x77 */
    /* 0x78 */ void*       array_78;              /* allocated array ptr (from Parse) */
    /* 0x80 */ uint32_t    count_80;              /* array count (from Parse) */
    uint8_t     _pad_84[0x04];                   /* 0x84-0x87 */
    /* 0x88 */ uint64_t    scalar_88;             /* byteswapped ulong from Parse */
    /* 0x90 */ uint8_t     subobj_anm_90[0x28];   /* sub-object block (vtable PTR_FUN_14110f788); FUN_140a85900 */
    /* 0xB8 */ uint8_t     subobj_anm_b8[0x18];   /* sub-object block (vtable PTR_FUN_141105380); FUN_140a129f0 */
    /* 0xD0 */ void*       trail_data_ptr;        /* written in Parse */
    /* 0xD8 */ uint16_t    trail_count;           /* number of trail entries */
    /* 0xDA */ uint16_t    trail_flag;            /* flag & 1 from Parse */
    uint8_t     _pad_DC[0x04];                   /* 0xDC-0xDF */
    /* 0xE0 */ void*       anm_resource;          /* from Parse via FUN_140a127c0 */
    uint8_t     _pad_E8[0xD0];                   /* 0xE8-0x1B7: remaining fields up to proven size */
} nuccChunkAnm;

static_assert(offsetof(nuccChunkAnm, vtable) == 0x00, "nuccChunkAnm.vtable");
static_assert(offsetof(nuccChunkAnm, subobj_anm_10) == 0x10, "nuccChunkAnm.subobj_anm_10");
static_assert(offsetof(nuccChunkAnm, array_18) == 0x18, "nuccChunkAnm.array_18");
static_assert(offsetof(nuccChunkAnm, array_28) == 0x28, "nuccChunkAnm.array_28");
static_assert(offsetof(nuccChunkAnm, count_30) == 0x30, "nuccChunkAnm.count_30");
static_assert(offsetof(nuccChunkAnm, subobj_anm_38) == 0x38, "nuccChunkAnm.subobj_anm_38");
static_assert(offsetof(nuccChunkAnm, array_40) == 0x40, "nuccChunkAnm.array_40");
static_assert(offsetof(nuccChunkAnm, array_50) == 0x50, "nuccChunkAnm.array_50");
static_assert(offsetof(nuccChunkAnm, count_58) == 0x58, "nuccChunkAnm.count_58");
static_assert(offsetof(nuccChunkAnm, subobj_anm_60) == 0x60, "nuccChunkAnm.subobj_anm_60");
static_assert(offsetof(nuccChunkAnm, array_68) == 0x68, "nuccChunkAnm.array_68");
static_assert(offsetof(nuccChunkAnm, array_78) == 0x78, "nuccChunkAnm.array_78");
static_assert(offsetof(nuccChunkAnm, count_80) == 0x80, "nuccChunkAnm.count_80");
static_assert(offsetof(nuccChunkAnm, scalar_88) == 0x88, "nuccChunkAnm.scalar_88");
static_assert(offsetof(nuccChunkAnm, subobj_anm_90) == 0x90, "nuccChunkAnm.subobj_anm_90");
static_assert(offsetof(nuccChunkAnm, subobj_anm_b8) == 0xB8, "nuccChunkAnm.subobj_anm_b8");
static_assert(offsetof(nuccChunkAnm, trail_data_ptr) == 0xD0, "nuccChunkAnm.trail_data_ptr");
static_assert(offsetof(nuccChunkAnm, trail_count) == 0xD8, "nuccChunkAnm.trail_count");
static_assert(offsetof(nuccChunkAnm, trail_flag) == 0xDA, "nuccChunkAnm.trail_flag");
static_assert(offsetof(nuccChunkAnm, anm_resource) == 0xE0, "nuccChunkAnm.anm_resource");
static_assert(sizeof(nuccChunkAnm) == 0x1B8, "nuccChunkAnm size must be 0x1B8");


/* ========================================================================
 * nuccChunkAmbient — ambient lighting chunk
 * Size: >= 0x20 (Parse writes at offset 0x10 and 0x18)
 * Only 2 methods (< 3 threshold); listed for completeness.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAmbient {
    /* 0x00 */ void*       vtable_or_base;        /* inherited from nuccChunk */
    uint8_t     _pad_08[0x08];                   /* 0x08-0x0F */
    /* 0x10 */ uint64_t    ambient_param_0;       /* written by Parse */
    /* 0x18 */ uint64_t    ambient_param_1;       /* written by Parse */
} nuccChunkAmbient;

static_assert(offsetof(nuccChunkAmbient, vtable_or_base) == 0x00, "nuccChunkAmbient.vtable_or_base");
static_assert(offsetof(nuccChunkAmbient, ambient_param_0) == 0x10, "nuccChunkAmbient.ambient_param_0");
static_assert(offsetof(nuccChunkAmbient, ambient_param_1) == 0x18, "nuccChunkAmbient.ambient_param_1");


/* ========================================================================
 * nuccChunkAnmCtrlCamera — camera animation controller
 * Only 2 methods (< 3 threshold); minimal layout.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAnmCtrlCamera {
    /* 0x00 */ void*       vtable_or_base;
    uint8_t     _pad_08[0x08];                   /* minimum padding */
} nuccChunkAnmCtrlCamera;

static_assert(offsetof(nuccChunkAnmCtrlCamera, vtable_or_base) == 0x00, "nuccChunkAnmCtrlCamera.vtable_or_base");


/* ========================================================================
 * nuccChunkAnmCtrlAmbient — ambient animation controller
 * Only 1 method (< 3 threshold); minimal layout.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAnmCtrlAmbient {
    /* 0x00 */ void*       vtable_or_base;
    uint8_t     _pad_08[0x08];                   /* minimum padding */
} nuccChunkAnmCtrlAmbient;

static_assert(offsetof(nuccChunkAnmCtrlAmbient, vtable_or_base) == 0x00, "nuccChunkAnmCtrlAmbient.vtable_or_base");


/* ========================================================================
 * nuccCelshadeParam — cel-shading parameters
 * Only 1 method (< 3 threshold). Trivially small: ctor sets *param_1 = 0.
 * Size = 0x04.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCelshadeParam {
    /* 0x00 */ uint32_t    celshade_flags;        /* set to 0 in ctor */
} nuccCelshadeParam;

static_assert(offsetof(nuccCelshadeParam, celshade_flags) == 0x00, "nuccCelshadeParam.celshade_flags");


/* ========================================================================
 * nuccCdSprNode — spring node parameter factory
 * Only 1 method (< 3 threshold). CreateParam is empty.
 * No instance fields proven. Listed for completeness.
 * ======================================================================== */
/* nuccCdSprNode has no proven instance layout; omitted as struct. */