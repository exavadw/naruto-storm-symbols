/* cmn46.h — NARUTO STORM 2 PC (NSUNS2.exe, build s2)
 * Reconstructed struct layouts for cmn46 group.
 * All offsets derived from x64 decompile of NSUNS2.exe (image base 0x140000000).
 * Field names from s2 code evidence or carried from s1 where layout matches.
 * Everything static is INFERRED, not CONFIRMED.
 * Sizes proven from allocator calls where noted; otherwise ">= last_field + field_size".
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccCdSpring — collision detection spring element
 * Vtable: PTR_FUN_1408910b8 at offset 0xB0 (set in ctor after sub-object init)
 * Size proof: allocator FUN_140580190(0xf0,"..\\source\\math\\nuccCdSprTree.cpp")
 *   in FUN_14061e180 allocates nuccCdSpring at 0xF0 bytes each.
 * Ctor accesses up to 0xE8 (flags_byte). Proven size = 0xF0.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSpring {
    /* 0x00 */ void*       vtable_base;          /* set by FUN_1405862c0 in ctor, overwritten at 0xB0 */
    uint8_t     _pad_08[0x38];                   /* 0x08-0x3F: sub-objects initialized via FUN_1405809b0 */
    /* 0x40 */ uint8_t     subobj_40[0x0C];       /* FUN_1405809b0(param_1+0x40, &DAT_14088f6a8) */
    /* 0x4C */ uint8_t     subobj_4c[0x0C];       /* FUN_1405809b0(param_1+0x4c, &DAT_14088f6a8) */
    /* 0x58 */ uint8_t     subobj_58[0x0C];       /* FUN_1405809b0(param_1+0x58, &DAT_14088f6a8) */
    /* 0x64 */ uint8_t     subobj_64[0x0C];       /* FUN_1405809b0(param_1+100, &DAT_14088f6a8) */
    /* 0x70 */ uint8_t     subobj_70[0x10];       /* FUN_1405809b0(param_1+0x70, &DAT_14088f6a8) */
    /* 0x80 */ void*       child_ptr;             /* ptr=0 in ctor */
    /* 0x88 */ float       spring_k;              /* float=0 in ctor; stiffness coefficient */
    /* 0x8C */ float       spring_damping;        /* float=1.0 (0x3f800000) in ctor */
    /* 0x90 */ double      spring_mass;           /* double=1.0 (0x3f800000) in ctor */
    /* 0x98 */ int32_t     spring_flags;          /* int=0 in ctor */
    uint8_t     _pad_9C[0x04];                   /* 0x9C-0x9F */
    /* 0xA0 */ void*       coord_data_0;          /* ptr=0 in ctor */
    /* 0xA8 */ void*       coord_data_1;          /* ptr=0 in ctor */
    /* 0xB0 */ void*       vtable;                /* PTR_FUN_1408910b8 set in ctor */
    uint8_t     _pad_B8[0x10];                   /* 0xB8-0xC7 */
    /* 0xC8 */ void*       linked_prev;           /* ptr=0 in ctor */
    /* 0xD0 */ void*       linked_next_unused;    /* ptr=0 in ctor */
    /* 0xD8 */ void*       linked_parent;         /* ptr=0 in ctor */
    /* 0xE0 */ uint16_t    spring_index;          /* ushort=0 in ctor */
    uint8_t     _pad_E2[0x06];                   /* 0xE2-0xE7 */
    /* 0xE8 */ uint8_t     flags_byte;            /* byte flags; bit 0/1 cleared in CdSpringCtrl::Create */
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
 * Size proof: allocator FUN_140580190(0x58,"..\\source\\math\\nuccCdSprTree.cpp",0xf7)
 *   in FUN_14061e180 allocates nuccCdSpringGrp nodes at 0x58 bytes each.
 * Ctor initializes sub-objects at 0x00, 0x28, 0x34, 0x40, 0x4C.
 * Proven size = 0x58.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSpringGrp {
    /* 0x00 */ uint8_t     base_subobj[0x10];     /* initialized via FUN_1405809e0(param_1, FUN_140581170()) */
    /* 0x10 */ void*       spr_list_head;         /* ptr=0 in ctor */
    /* 0x18 */ void*       spr_list_tail;         /* ptr=0 in ctor */
    /* 0x20 */ void*       spr_list_end;          /* ptr=0 in ctor */
    /* 0x28 */ uint8_t     subobj_28[0x0C];       /* initialized via FUN_1405809e0 */
    /* 0x34 */ uint8_t     subobj_34[0x0C];       /* initialized via FUN_1405809e0 */
    /* 0x40 */ uint8_t     subobj_40[0x0C];       /* initialized via FUN_1405809e0 */
    /* 0x4C */ uint8_t     subobj_4c[0x0C];       /* initialized via FUN_1405809e0; last field before end */
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
 * nuccCdSprTree — spring tree with dynamically allocated node array
 * Vtable: PTR_FUN_14089be98 at offset 0x00
 * Node stride: 0x58 bytes (ZEXT816(0x58) * count in ctor)
 * Node struct has its own vtable PTR_FUN_14089be98, fields at [2..0xf], byte at +0x52
 * Tree size: >= 0x80 (param_1[0xf] = offset 0x78 + 8)
 * Allocator: FUN_140580260(count*0x58+8, "...nuccCdSprTree.cpp", 0x2f) for node array
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSprTreeNode {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_14089be98 */
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

typedef struct __attribute__((packed)) nuccCdSprTree {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_14089be98 */
    /* 0x08 */ void*       field_08;              /* param_1[1]=0 */
    /* 0x10 */ void*       field_10;              /* param_1[2]=0 */
    /* 0x18 */ void*       self_ptr_18;           /* param_1[3]=param_1 (self-reference) */
    /* 0x20 */ void*       self_ptr_20;           /* param_1[4]=param_1 (self-reference) */
    /* 0x28 */ void*       field_28;              /* param_1[5]=0 */
    /* 0x30 */ void*       field_30;              /* param_1[6]=0 */
    /* 0x38 */ void*       field_38;              /* param_1[7]=0 */
    /* 0x40 */ void*       field_40;              /* param_1[8]=0 */
    /* 0x48 */ void*       field_48;              /* param_1[9]=0 */
    /* 0x50 */ uint32_t    default_value;         /* *(uint32*)(param_1+100)=5, i.e. offset 0x64 */
    uint8_t     _pad_54[0x04];                   /* 0x54-0x57 */
    /* 0x58 */ nuccCdSprTreeNode* node_array;    /* param_1[0xb] = allocated node array ptr */
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
 * Size proof: allocator FUN_140580190(0x20,"..\\source\\math\\nuccCdSpringCtrl.cpp",0x1db)
 *   in Create allocates the ctrl itself at 0x20 bytes.
 * Inner allocations: 0x80 for SprTree, 0x110 for CdSpringGrp nodes (in s1; s2 uses 0x58).
 * Fields at 0x128 (ushort count), 0x178 (pointer array) from Create.
 * Linked list of Grp nodes via offset 0x100.
 * Size >= 0x180 (last access at 0x178 + pointer size 8).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCdSpringCtrl {
    /* 0x00 */ void*       spr_tree;              /* allocated via FUN_140580190(0x80,...); nuccCdSprTree* */
    /* 0x08 */ void*       grp_list_head;         /* linked list head of CdSpringGrp nodes */
    /* 0x10 */ void*       grp_list_tail;         /* linked list tail */
    /* 0x18 */ int32_t     field_18;              /* zeroed in Create */
    /* 0x1C */ uint32_t    dat_ref;               /* DAT_140a9f480 reference */
    uint8_t     _pad_20[0x108];                  /* 0x20-0x127: internal state */
    /* 0x128 */ uint16_t   hit_elp_count;         /* ushort count checked against spr index */
    uint8_t     _pad_12A[0x4E];                  /* 0x12A-0x177 */
    /* 0x178 */ void**    spr_ptr_array;         /* pointer array indexed by ushort */
} nuccCdSpringCtrl;

static_assert(offsetof(nuccCdSpringCtrl, spr_tree) == 0x00, "nuccCdSpringCtrl.spr_tree");
static_assert(offsetof(nuccCdSpringCtrl, grp_list_head) == 0x08, "nuccCdSpringCtrl.grp_list_head");
static_assert(offsetof(nuccCdSpringCtrl, grp_list_tail) == 0x10, "nuccCdSpringCtrl.grp_list_tail");
static_assert(offsetof(nuccCdSpringCtrl, field_18) == 0x18, "nuccCdSpringCtrl.field_18");
static_assert(offsetof(nuccCdSpringCtrl, dat_ref) == 0x1C, "nuccCdSpringCtrl.dat_ref");
static_assert(offsetof(nuccCdSpringCtrl, hit_elp_count) == 0x128, "nuccCdSpringCtrl.hit_elp_count");
static_assert(offsetof(nuccCdSpringCtrl, spr_ptr_array) == 0x178, "nuccCdSpringCtrl.spr_ptr_array");


/* ========================================================================
 * nuccChannel — request channel / message queue
 * Vtable: PTR_FUN_1408985a0 at offset 0x00 (set in ctor)
 * Inner vtable: PTR_FUN_14089c1b8 at offset 0xB8 (sub-object at param_1+0x17*8=0xB8)
 * Size proof: allocator FUN_140580190(0x70,"..\\source\\std\\nuccChannel.cpp")
 *   in Create allocates individual request items at 0x70 bytes each.
 * Channel itself uses vector-like storage at offsets 0xA0, 0xA8, 0xB0.
 * Size >= 0xD8 (state_surface shows field at 0xD0 + 8).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChannel {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_1408985a0 */
    /* 0x08 */ uint32_t    channel_id;            /* [1]=0 in ctor (uint32) */
    uint8_t     _pad_0C[0x04];                   /* 0x0C-0x0F */
    /* 0x10 */ uint8_t     subobj_10[0x08];       /* initialized via FUN_1405f8ff0 */
    /* 0x18 */ uint8_t     subobj_18[0x88];       /* initialized via FUN_1405ac080(param_1+10) */
    /* 0xA0 */ void*       vec_begin;             /* vector begin pointer */
    /* 0xA8 */ void*       vec_end;               /* vector end pointer */
    /* 0xB0 */ void*       vec_capacity;          /* vector capacity/end-of-storage */
    /* 0xB8 */ uint8_t     subobj_b8[0x18];       /* sub-object with vtable PTR_FUN_14089c1b8 */
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
 * Vtable: PTR_FUN_140897dd0 at offset 0x00
 * Size proof: allocator FUN_140580190(0x1b8,"..\\source\\render\\nuccChunkAnm.cpp",0x5b)
 *   in Create allocates nuccChunkAnm at 0x1B8 bytes each.
 * Multiple embedded sub-objects with their own vtables:
 *   0x10: PTR_FUN_14088fb38, 0x38: PTR_FUN_14088fb38,
 *   0x60: PTR_FUN_1408914f8, 0x90: PTR_FUN_140897da0, 0xB8: PTR_FUN_140897db8
 * Proven size = 0x1B8.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAnm {
    /* 0x00 */ void*       vtable;                /* PTR_FUN_140897dd0 */
    uint8_t     _pad_08[0x08];                   /* 0x08-0x0F */
    /* 0x10 */ uint8_t     subobj_anm_10[0x28];   /* vtable PTR_FUN_14088fb38 at offset 0x10 */
    /* 0x38 */ uint8_t     subobj_anm_38[0x28];   /* vtable PTR_FUN_14088fb38 at offset 0x38 */
    /* 0x60 */ uint8_t     subobj_anm_60[0x30];   /* vtable PTR_FUN_1408914f8 at offset 0x60 */
    /* 0x90 */ uint8_t     subobj_anm_90[0x28];   /* vtable PTR_FUN_140897da0 at offset 0x90 */
    /* 0xB8 */ uint8_t     subobj_anm_b8[0x18];   /* vtable PTR_FUN_140897db8 at offset 0xB8 */
    /* 0xD0 */ void*       trail_data_ptr;        /* written in Parse */
    /* 0xD8 */ uint16_t    trail_count;           /* number of trail entries */
    /* 0xDA */ uint16_t    trail_flag;            /* flag & 1 from Parse */
    uint8_t     _pad_DC[0x04];                   /* 0xDC-0xDF */
    /* 0xE0 */ void*       anm_resource;          /* from Parse */
    uint8_t     _pad_E8[0xD0];                   /* 0xE8-0x1B7: remaining fields up to proven size */
} nuccChunkAnm;

static_assert(offsetof(nuccChunkAnm, vtable) == 0x00, "nuccChunkAnm.vtable");
static_assert(offsetof(nuccChunkAnm, subobj_anm_10) == 0x10, "nuccChunkAnm.subobj_anm_10");
static_assert(offsetof(nuccChunkAnm, subobj_anm_38) == 0x38, "nuccChunkAnm.subobj_anm_38");
static_assert(offsetof(nuccChunkAnm, subobj_anm_60) == 0x60, "nuccChunkAnm.subobj_anm_60");
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
 * Very small struct; Parse reads 0x10 bytes into two uint64 fields.
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
 * Size unknown, >= 0x08 (vtable/base pointer only).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAnmCtrlCamera {
    /* 0x00 */ void*       vtable_or_base;
    uint8_t     _pad_08[0x08];                   /* minimum padding */
} nuccChunkAnmCtrlCamera;

static_assert(offsetof(nuccChunkAnmCtrlCamera, vtable_or_base) == 0x00, "nuccChunkAnmCtrlCamera.vtable_or_base");


/* ========================================================================
 * nuccChunkAnmCtrlAmbient — ambient animation controller
 * Only 1 method (< 3 threshold); minimal layout.
 * Size unknown, >= 0x08 (vtable/base pointer only).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkAnmCtrlAmbient {
    /* 0x00 */ void*       vtable_or_base;
    uint8_t     _pad_08[0x08];                   /* minimum padding */
} nuccChunkAnmCtrlAmbient;

static_assert(offsetof(nuccChunkAnmCtrlAmbient, vtable_or_base) == 0x00, "nuccChunkAnmCtrlAmbient.vtable_or_base");


/* ========================================================================
 * nuccCelshadeParam — cel-shading parameters
 * Only 1 method (< 3 threshold). Trivially small: ctor sets *param_1 = 0.
 * Size = 0x04 (minimum for a non-empty struct with one int field).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCelshadeParam {
    /* 0x00 */ uint32_t    celshade_flags;        /* set to 0 in ctor */
} nuccCelshadeParam;

static_assert(offsetof(nuccCelshadeParam, celshade_flags) == 0x00, "nuccCelshadeParam.celshade_flags");


/* ========================================================================
 * nuccCdSprNode — spring node parameter factory
 * Only 1 method (< 3 threshold). CreateParam is empty (returns immediately).
 * No instance fields proven. Listed for completeness.
 * ======================================================================== */
/* nuccCdSprNode has no proven instance layout; omitted as struct. */