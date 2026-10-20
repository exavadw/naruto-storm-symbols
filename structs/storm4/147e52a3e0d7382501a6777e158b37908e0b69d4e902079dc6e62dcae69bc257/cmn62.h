/* cmn62.h -- nuccParticle* struct layouts for NARUTO STORM 4 PC 1.09 (s4 / NSUNS4_release.exe)
 * Generated: 2026-10-19
 * All fields INFERRED from decompiled code; not CONFIRMED by runtime trace.
 * Sizes proven from operator_new allocator calls in Create/AddList methods.
 * Own-game names only (Storm 4 symbols/strings); field names carried from s3
 * where layout matches and no s4-specific name was found.
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

typedef struct PACKED { float x, y, z; } Nucc_Vector3;

/* ========================================================================
 * nuccParticleNode -- base class (min ~0x40, embedded only)
 * Vtable (s4): PTR_FUN_141112188
 * Inherits: Nucc::Memory::BlockAllocator
 * ======================================================================== */
typedef struct PACKED {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint32_t block_alloc_0x08;
    /* 0x0C */ uint32_t field_0x0C;
    /* 0x10 */ uint32_t field_0x10;
    /* 0x14 */ uint32_t type_or_flags;      /* state_surface high-conf rw in Create */
    /* 0x18 */ uint64_t field_0x18;
    /* 0x20 */ uint64_t field_0x20;
    /* 0x28 */ uint64_t field_0x28;
    /* 0x30 */ uint8_t _base_pad[0x10];
} nuccParticleNode;

/* ========================================================================
 * nuccParticlePosNode -- 0xE0 (carried from s3 LoadTh proof)
 * Inherits: nuccParticleNode
 * ======================================================================== */
typedef struct PACKED {
    uint8_t _node_base[0x40];
    /* 0x40 */ uint64_t field_0x40;
    /* 0x48 */ uint64_t field_0x48;
    /* 0x50 */ uint8_t matrix44[0x40];
    /* 0x90 */ Nucc_Vector3 vec_at_0x90;
    /* 0x9C */ Nucc_Vector3 vec_at_0x9C;
    /* 0xA8 */ Nucc_Vector3 vec_at_0xA8;
    /* 0xB4 */ Nucc_Vector3 vec_at_0xB4;
    /* 0xC0 */ uint64_t field_0xC0;
    /* 0xC8 */ Nucc_Vector3 vec_at_0xC8;
    /* 0xD4 */ uint32_t field_0xD4;
    /* 0xD8 */ uint32_t _pad_0xD8;
    /* 0xDC */ uint32_t _pad_to_E0;
} nuccParticlePosNode;

static_assert(sizeof(nuccParticlePosNode) == 0xE0, "nuccParticlePosNode size");

/* ========================================================================
 * nuccParticleForceFieldNode -- 0x108
 * Proven: operator_new(0x108,...) in FFList::AddList @ RVA 0xAA2220
 * Vtable (s4): PTR_FUN_1411123a8
 * Inherits: nuccParticlePosNode -> nuccParticleNode
 * ======================================================================== */
typedef struct PACKED {
    uint8_t _posnode_base[0xE0];
    /* 0xE0 */ uint64_t field_0xE0;          /* zeroed in ctor */
    /* 0xE8 */ uint8_t sub_struct_0xE8[0x0C]; /* FUN_140a046f0 init */
    /* 0xF4 */ Nucc_Vector3 force_field_vec;  /* FUN_140a046d0 init */
    /* 0x100 */ float force_field_scale;      /* 1.0f default */
    /* 0x104 */ uint32_t _pad_to_108;
} nuccParticleForceFieldNode;

static_assert(sizeof(nuccParticleForceFieldNode) == 0x108, "FFNode size");
static_assert(offsetof(nuccParticleForceFieldNode, field_0xE0) == 0xE0, "field_0xE0");
static_assert(offsetof(nuccParticleForceFieldNode, sub_struct_0xE8) == 0xE8, "sub_0xE8");
static_assert(offsetof(nuccParticleForceFieldNode, force_field_vec) == 0xF4, "force_field_vec");
static_assert(offsetof(nuccParticleForceFieldNode, force_field_scale) == 0x100, "ff_scale");

/* ========================================================================
 * nuccParticleElm -- embedded 0x1E0 (no standalone alloc in s4)
 * Vtable (s4): PTR_FUN_14110ad50
 * Inherits: nuccParticleNode
 * ======================================================================== */
typedef struct PACKED {
    uint8_t _node_base[0x40];
    /* 0x40 */ uint64_t clump_ptr;
    /* 0x48 */ uint64_t field_0x48;
    /* 0x50 */ uint32_t entry_mdl_flag;
    /* 0x54 */ uint32_t _pad_0x54;
    /* 0x58 */ uint8_t _gap_0x58[0x08];
    /* 0x60 */ uint8_t sub_struct_0x60[0x154]; /* FUN_140a51490 init at +0x60 */
    /* 0x1B4 */ uint32_t render_layer;
    /* 0x1B8 */ float scale_x;                /* 1.0f default */
    /* 0x1BC */ float scale_y;                /* 1.0f default */
    /* 0x1C0 */ float scale_z_or_alpha;       /* 0.0f default */
    /* 0x1C4 */ int32_t fade_color;           /* 0xFFFFFFFF default */
    /* 0x1C8 */ uint64_t field_0x1C8;         /* FUN_140a046f0 init */
    /* 0x1D0 */ float sca_par_x;
    /* 0x1D4 */ float sca_par_y;              /* 1.0f default */
    /* 0x1D8 */ float col_par;                /* 1.0f default */
    /* 0x1DC */ float rad_par;
} nuccParticleElm;

static_assert(sizeof(nuccParticleElm) == 0x1E0, "nuccParticleElm size");
static_assert(offsetof(nuccParticleElm, clump_ptr) == 0x40, "clump_ptr");
static_assert(offsetof(nuccParticleElm, entry_mdl_flag) == 0x50, "entry_mdl_flag");
static_assert(offsetof(nuccParticleElm, sub_struct_0x60) == 0x60, "sub_struct_0x60");
static_assert(offsetof(nuccParticleElm, render_layer) == 0x1B4, "render_layer");
static_assert(offsetof(nuccParticleElm, scale_x) == 0x1B8, "scale_x");
static_assert(offsetof(nuccParticleElm, scale_y) == 0x1BC, "scale_y");
static_assert(offsetof(nuccParticleElm, scale_z_or_alpha) == 0x1C0, "scale_z");
static_assert(offsetof(nuccParticleElm, fade_color) == 0x1C4, "fade_color");
static_assert(offsetof(nuccParticleElm, field_0x1C8) == 0x1C8, "field_0x1C8");
static_assert(offsetof(nuccParticleElm, sca_par_x) == 0x1D0, "sca_par_x");
static_assert(offsetof(nuccParticleElm, sca_par_y) == 0x1D4, "sca_par_y");
static_assert(offsetof(nuccParticleElm, col_par) == 0x1D8, "col_par");
static_assert(offsetof(nuccParticleElm, rad_par) == 0x1DC, "rad_par");

/* ========================================================================
 * nuccParticle -- 0x230
 * Proven: operator_new(0x230,...) in Create @ RVA 0xAA2D10
 * Vtable (s4): PTR_FUN_141112838
 * Inherits: nuccParticleElm -> nuccParticleNode
 * ======================================================================== */
typedef struct PACKED {
    uint8_t _elm_base[0x1E0];
    /* 0x1E0 */ uint64_t velocity_or_pos_a;   /* FUN_140a04780 init */
    /* 0x1E8 */ int32_t vel_a_component;
    /* 0x1EC */ uint64_t velocity_or_pos_b;   /* FUN_140a04780 init */
    /* 0x1F4 */ uint32_t _pad_0x1F4;
    /* 0x1F8 */ uint64_t velocity_or_pos_c;   /* FUN_140a046f0 init */
    /* 0x200 */ uint32_t _pad_0x200;
    /* 0x204 */ uint64_t vel_d_or_pos_d;      /* FUN_140a04780 init */
    /* 0x20C */ int32_t vel_c_component;
    /* 0x210 */ uint32_t _pad_0x210;
    /* 0x214 */ float force_field_accum;      /* rw in CalcForceField */
    /* 0x218 */ float force_multiplier;
    /* 0x21C */ uint64_t gravity_or_accel;    /* FUN_140a046f0 init */
    /* 0x224 */ uint32_t gravity_component;
    /* 0x228 */ uint32_t reuse_flag;          /* 1 default */
    /* 0x22C */ int32_t draw_order;           /* -1 default */
} nuccParticle;

static_assert(sizeof(nuccParticle) == 0x230, "nuccParticle size");
static_assert(offsetof(nuccParticle, velocity_or_pos_a) == 0x1E0, "vel_a");
static_assert(offsetof(nuccParticle, vel_a_component) == 0x1E8, "vel_a_comp");
static_assert(offsetof(nuccParticle, velocity_or_pos_b) == 0x1EC, "vel_b");
static_assert(offsetof(nuccParticle, velocity_or_pos_c) == 0x1F8, "vel_c");
static_assert(offsetof(nuccParticle, vel_d_or_pos_d) == 0x204, "vel_d");
static_assert(offsetof(nuccParticle, vel_c_component) == 0x20C, "vel_c_comp");
static_assert(offsetof(nuccParticle, force_field_accum) == 0x214, "ff_accum");
static_assert(offsetof(nuccParticle, force_multiplier) == 0x218, "ff_mult");
static_assert(offsetof(nuccParticle, gravity_or_accel) == 0x21C, "gravity");
static_assert(offsetof(nuccParticle, gravity_component) == 0x224, "grav_comp");
static_assert(offsetof(nuccParticle, reuse_flag) == 0x228, "reuse_flag");
static_assert(offsetof(nuccParticle, draw_order) == 0x22C, "draw_order");

/* ========================================================================
 * nuccParticleForceFieldCache -- 0x18
 * Proven: operator_new(0x18,...) in Create @ RVA 0xA5AF30
 * Vtable (s4): PTR_FUN_1411046e8
 * Standalone manager (not a node)
 * ======================================================================== */
typedef struct PACKED {
    /* 0x00 */ void *vtable;
    /* 0x08 */ int32_t count;
    /* 0x0C */ uint32_t _pad_0x0C;
    /* 0x10 */ nuccParticleForceFieldNode **node_array_ptr;
} nuccParticleForceFieldCache;

static_assert(sizeof(nuccParticleForceFieldCache) == 0x18, "FFCache size");
static_assert(offsetof(nuccParticleForceFieldCache, count) == 0x08, "count");
static_assert(offsetof(nuccParticleForceFieldCache, node_array_ptr) == 0x10, "arr_ptr");

#undef PACKED

#endif /* CMN62_H */