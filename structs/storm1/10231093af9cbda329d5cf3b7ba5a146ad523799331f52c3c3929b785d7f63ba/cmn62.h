/* cmn62.h -- nuccParticle* struct layouts for NARUTO STORM 1 (s1 / NSUNS1.exe)
 * Generated: 2026-10-19
 * All fields INFERRED from decompiled code; not CONFIRMED by runtime trace.
 * Sizes proven from ccFileLoadListForUi::LoadTh allocation arguments.
 * Own-game names only (Storm 1 sources); no Switch Trilogy mapping available.
 */

#ifndef CMN62_H
#define CMN62_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __GNUC__
#define PACKED __attribute__((packed))
#else
#error "This header requires GCC or Clang for packed attribute"
#endif

/* Forward declaration for Nucc math type (12 bytes each, packed) */
typedef struct PACKED { float x, y, z; } Nucc_Vector3;

/* ========================================================================
 * nuccParticleNode -- base class for all particle nodes
 * Size: not allocated standalone; embedded in subclasses (min ~0x40)
 * Vtable: PTR_FUN_140743c78 (VA 0x140743c78)
 * Inherits from: Nucc::Memory::BlockAllocator
 * Evidence: nuccParticleNode::nuccParticleNode ctor @ RVA 0x522EE0
 * ======================================================================== */
typedef struct PACKED {
    /* 0x00 */ void     *vtable;           /* PTR_FUN_140743c78 */
    /* 0x08 */ uint32_t  block_alloc_0x08; /* BlockAllocator base field */
    /* 0x0C */ uint32_t  field_0x0C;       /* init 0 in ctor */
    /* 0x10 */ uint32_t  field_0x10;       /* init 0 in ctor */
    /* 0x14 */ uint32_t  _pad_0x14;
    /* 0x18 */ uint64_t  field_0x18;       /* param_1[5] = 0 */
    /* 0x20 */ uint64_t  field_0x20;       /* param_1[6] = 0 */
    /* 0x28 */ uint64_t  field_0x28;       /* param_1[7] = 0 */
    /* 0x30 */ uint8_t   _base_pad[0x10];  /* padding to reach subclass start */
} nuccParticleNode; /* sizeof = 0x40 inferred minimum */

/* ========================================================================
 * nuccParticlePosNode -- position-aware particle node
 * Size: 0xE0 (224 bytes) -- proven from LoadTh(0xe0) in nuccParticlePosList::AddList
 * Vtable: PTR_FUN_1407442c8 (VA 0x1407442c8)
 * Inherits from: nuccParticleNode
 * Evidence: nuccParticlePosNode::nuccParticlePosNode ctor @ RVA 0x526470
 *           nuccParticlePosList::AddList @ RVA 0x523680 calls LoadTh(0xe0)
 *
 * Ctor pointer-arithmetic decode (param_1 is undefined8*):
 *   param_1 + 10  => byte 0x50  (Matrix44_MathGeo, 64 bytes)
 *   param_1 + 0x12 => byte 0x90  (Vector3)
 *   (longlong)param_1 + 0x9c    (Vector3)
 *   param_1 + 0x15 => byte 0xA8  (Vector3)
 *   (longlong)param_1 + 0xb4    (Vector3)
 *   param_1 + 0x19 => byte 0xC8  (qword zero)
 *   param_1 + 0x1a => byte 0xD0  (Vector3)
 *   *(uint*)(param_1 + 0xc4) => unclear; adjusted to fit 0xE0 total
 * ======================================================================== */
typedef struct PACKED {
    /* --- nuccParticleNode base (0x00-0x3F) --- */
    /* 0x00 */ void     *vtable_node;      /* overwritten to PTR_FUN_1407442c8 */
    /* 0x08 */ uint32_t  block_alloc_0x08;
    /* 0x0C */ uint32_t  field_0x0C;
    /* 0x10 */ uint32_t  field_0x10;
    /* 0x14 */ uint32_t  _pad_0x14;
    /* 0x18 */ uint64_t  field_0x18;
    /* 0x20 */ uint64_t  field_0x20;
    /* 0x28 */ uint64_t  field_0x28;
    /* 0x30 */ uint8_t   _base_pad[0x10];

    /* --- nuccParticlePosNode own fields --- */
    /* 0x40 */ uint64_t  field_0x40;       /* param_1[8] = 0 */
    /* 0x48 */ uint64_t  field_0x48;       /* param_1[9] = 0 */
    /* 0x50 */ uint8_t   matrix44[0x40];   /* Matrix44_MathGeo, 64 bytes */
    /* 0x90 */ Nucc_Vector3 vec_at_0x90;   /* Vector3(param_1 + 0x12) */
    /* 0x9C */ Nucc_Vector3 vec_at_0x9C;   /* Vector3((longlong)param_1 + 0x9c) */
    /* 0xA8 */ Nucc_Vector3 vec_at_0xA8;   /* Vector3(param_1 + 0x15) */
    /* 0xB4 */ Nucc_Vector3 vec_at_0xB4;   /* Vector3((longlong)param_1 + 0xb4) */
    /* 0xC0 */ uint64_t  field_0xC0;       /* gap / alignment */
    /* 0xC8 */ Nucc_Vector3 vec_at_0xC8;   /* Vector3(param_1 + 0x1a) */
    /* 0xD4 */ uint32_t  field_0xD4;       /* tail field or pad */
    /* 0xD8 */ uint32_t  _pad_0xD8;
    /* 0xDC */ uint32_t  _pad_to_E0;
} nuccParticlePosNode;

static_assert(sizeof(nuccParticlePosNode) == 0xE0,
              "nuccParticlePosNode size must be 0xE0");

/* ========================================================================
 * nuccParticleForceFieldNode -- force field effect node
 * Size: 0x108 (264 bytes) -- proven from LoadTh(0x108) in ForceFieldList::AddList
 * Vtable: PTR_FUN_140743d28 (VA 0x140743d28)
 * Inherits from: nuccParticlePosNode
 * Evidence: nuccParticleForceFieldNode::nuccParticleForceFieldNode ctor @ RVA 0x522F80
 *           nuccParticleForceFieldList::AddList @ RVA 0x523900 calls LoadTh(0x108)
 * ======================================================================== */
typedef struct PACKED {
    /* --- nuccParticlePosNode base (0x00-0xDF) --- */
    uint8_t _posnode_base[0xE0];

    /* --- nuccParticleForceFieldNode own fields --- */
    /* 0xE0 */ uint64_t      field_0xE0;        /* param_1[0x1c]=0, qword write */
    /* 0xE8 */ Nucc_Vector3  vec_at_0xE8;       /* Vector3(param_1+0x1d) */
    /* 0xF4 */ Nucc_Vector3  force_field_vec;   /* Vector3 at byte 0xF4 */
    /* 0x100 */ float        force_field_scale; /* 1.0f (0x3f800000) */
    /* 0x104 */ uint32_t     _pad_to_108;
} nuccParticleForceFieldNode;

static_assert(sizeof(nuccParticleForceFieldNode) == 0x108,
              "nuccParticleForceFieldNode size must be 0x108");
static_assert(offsetof(nuccParticleForceFieldNode, field_0xE0) == 0xE0,
              "field_0xE0 offset");
static_assert(offsetof(nuccParticleForceFieldNode, vec_at_0xE8) == 0xE8,
              "vec_at_0xE8 offset");
static_assert(offsetof(nuccParticleForceFieldNode, force_field_vec) == 0xF4,
              "force_field_vec offset");
static_assert(offsetof(nuccParticleForceFieldNode, force_field_scale) == 0x100,
              "force_field_scale offset");

/* ========================================================================
 * nuccParticleElm -- particle element (renderable unit)
 * Size: embedded in nuccParticle (no standalone allocation found).
 *       Fields span 0x40-0x1DF within nuccParticle's 0x230 total.
 * Vtable: PTR_FUN_1407440f8 (VA 0x1407440f8)
 * Inherits from: nuccParticleNode
 * Evidence: nuccParticleElm::nuccParticleElm ctor @ RVA 0x523A80
 * ======================================================================== */
typedef struct PACKED {
    /* --- nuccParticleNode base (0x00-0x3F) --- */
    /* 0x00 */ void     *vtable_node;      /* overwritten to PTR_FUN_1407440f8 */
    /* 0x08 */ uint32_t  block_alloc_0x08;
    /* 0x0C */ uint32_t  field_0x0C;
    /* 0x10 */ uint32_t  field_0x10;
    /* 0x14 */ uint32_t  _pad_0x14;
    /* 0x18 */ uint64_t  field_0x18;
    /* 0x20 */ uint64_t  field_0x20;
    /* 0x28 */ uint64_t  field_0x28;
    /* 0x30 */ uint8_t   _base_pad[0x10];

    /* --- nuccParticleElm own fields --- */
    /* 0x40 */ uint64_t  clump_ptr;        /* param_1[8]=0; EntryMdl stores nuccClump* */
    /* 0x48 */ uint64_t  field_0x48;       /* param_1[9]=0 */
    /* 0x50 */ uint32_t  entry_mdl_flag;   /* *(uint*)(param_1+10)=0; set 1 by EntryMdl */
    /* 0x54 */ uint32_t  _pad_0x54;
    /* 0x58 */ uint8_t   _gap_0x58[0x08];
    /* 0x60 */ uint8_t   sub_struct_0x60[0x154]; /* FUN_140523a10(param_1+0xc) */
    /* 0x1B4 */ uint32_t render_layer;     /* SIM/PRES candidate */
    /* 0x1B8 */ float    scale_x;          /* 1.0f */
    /* 0x1BC */ float    scale_y;          /* 1.0f */
    /* 0x1C0 */ float    scale_z_or_alpha; /* 0.0f */
    /* 0x1C4 */ int32_t  fade_color;       /* 0xffffffff (-1 / white) */
    /* 0x1C8 */ uint64_t field_0x1C8;      /* rw, Vector3-like init */
    /* 0x1D0 */ float    sca_par_x;
    /* 0x1D4 */ float    sca_par_y;        /* 1.0f */
    /* 0x1D8 */ float    col_par;          /* 1.0f */
    /* 0x1DC */ float    rad_par;          /* 1.0f */
} nuccParticleElm; /* sizeof = 0x1E0 (embedded portion) */

/* ========================================================================
 * nuccParticle -- main particle instance (renderable + physics)
 * Size: 0x230 (560 bytes) -- proven from LoadTh(0x230) in nuccParticle::Create
 * Vtable: PTR_FUN_1407441e0 (VA 0x1407441e0)
 * Inherits from: nuccParticleElm -> nuccParticleNode
 * Evidence: nuccParticle::nuccParticle ctor @ RVA 0x524F80
 *           nuccParticle::Create @ RVA 0x525960 calls LoadTh(0x230)
 * Fields from state_surface (16 fields) + ctor analysis
 * ======================================================================== */
typedef struct PACKED {
    /* --- nuccParticleElm base (includes nuccParticleNode) 0x00-0x1DF --- */
    /* 0x00 */ void     *vtable_elm;       /* initially Elm vtable, overwritten */
    /* 0x08 */ uint32_t  block_alloc_0x08;
    /* 0x0C */ uint32_t  field_0x0C;
    /* 0x10 */ uint32_t  field_0x10;
    /* 0x14 */ int32_t   particle_type;    /* rw: checked ==6,==1,==2 in Create */
    /* 0x18 */ uint32_t  _pad_0x18;
    /* 0x1C */ uint8_t   _elm_base_gap[0x1C4]; /* nuccParticleElm fields */

    /* --- nuccParticle own fields --- */
    /* 0x1E0 */ uint64_t velocity_or_pos_a;  /* rw in CalcForceField */
    /* 0x1E8 */ int32_t  vel_a_component;
    /* 0x1EC */ uint64_t velocity_or_pos_b;  /* rw in CalcForceField */
    /* 0x1F4 */ uint32_t _pad_0x1F4;
    /* 0x1F8 */ uint64_t velocity_or_pos_c;  /* ctor init */
    /* 0x200 */ uint32_t _pad_0x200;
    /* 0x204 */ uint64_t vel_d_or_pos_d;     /* rw in CalcForceField */
    /* 0x20C */ int32_t  vel_c_component;
    /* 0x210 */ uint32_t _pad_0x210;
    /* 0x214 */ float    force_field_accum;  /* rw: accumulated force */
    /* 0x218 */ float    force_multiplier;   /* read-only in CalcForceField */
    /* 0x21C */ uint64_t gravity_or_accel;   /* ctor init */
    /* 0x224 */ uint32_t gravity_component;
    /* 0x228 */ uint32_t reuse_flag;         /* init 1 */
    /* 0x22C */ int32_t  draw_order;         /* init -1 (0xffffffff) */
} nuccParticle;

static_assert(sizeof(nuccParticle) == 0x230,
              "nuccParticle size must be 0x230");
static_assert(offsetof(nuccParticle, particle_type) == 0x14,
              "particle_type offset");
static_assert(offsetof(nuccParticle, velocity_or_pos_a) == 0x1E0,
              "velocity_or_pos_a offset");
static_assert(offsetof(nuccParticle, vel_a_component) == 0x1E8,
              "vel_a_component offset");
static_assert(offsetof(nuccParticle, velocity_or_pos_b) == 0x1EC,
              "velocity_or_pos_b offset");
static_assert(offsetof(nuccParticle, velocity_or_pos_c) == 0x1F8,
              "velocity_or_pos_c offset");
static_assert(offsetof(nuccParticle, vel_d_or_pos_d) == 0x204,
              "vel_d_or_pos_d offset");
static_assert(offsetof(nuccParticle, vel_c_component) == 0x20C,
              "vel_c_component offset");
static_assert(offsetof(nuccParticle, force_field_accum) == 0x214,
              "force_field_accum offset");
static_assert(offsetof(nuccParticle, force_multiplier) == 0x218,
              "force_multiplier offset");
static_assert(offsetof(nuccParticle, gravity_or_accel) == 0x21C,
              "gravity_or_accel offset");
static_assert(offsetof(nuccParticle, gravity_component) == 0x224,
              "gravity_component offset");
static_assert(offsetof(nuccParticle, reuse_flag) == 0x228,
              "reuse_flag offset");
static_assert(offsetof(nuccParticle, draw_order) == 0x22C,
              "draw_order offset");

/* ========================================================================
 * nuccParticleForceFieldCache -- cache/manager for force field nodes
 * Size: 0x18 (24 bytes) -- proven from LoadTh(0x18) in Create
 * Vtable: PTR_FUN_140773600 (VA 0x140773600)
 * Not a particle node; standalone manager class.
 * Evidence: nuccParticleForceFieldCache::Create @ RVA 0x4DF440
 * ======================================================================== */
typedef struct PACKED {
    /* 0x00 */ void    *vtable;            /* PTR_FUN_140773600 */
    /* 0x08 */ int32_t  count;             /* number of cached nodes */
    /* 0x0C */ uint32_t _pad_0x0C;
    /* 0x10 */ nuccParticleForceFieldNode **node_array_ptr; /* heap array, count*8 bytes */
} nuccParticleForceFieldCache;

static_assert(sizeof(nuccParticleForceFieldCache) == 0x18,
              "nuccParticleForceFieldCache size must be 0x18");
static_assert(offsetof(nuccParticleForceFieldCache, count) == 0x08,
              "count offset");
static_assert(offsetof(nuccParticleForceFieldCache, node_array_ptr) == 0x10,
              "node_array_ptr offset");

#undef PACKED

#endif /* CMN62_H */