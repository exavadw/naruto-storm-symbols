/* cmn64.h — struct group cmn64 for build s4 (NSUNS4_release.exe, NARUTO STORM 4 PC 1.09)
 * Status: INFERRED (static analysis only; no runtime confirmation)
 * All offsets derived from s4 x64 decompilation (image base 0x140000000).
 * OWN-GAME NAMES: field names from Storm 4 code/strings only.
 */

#ifndef CMN64_S4_H
#define CMN64_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccParticleNode (base class)
 * Size: >= 0x40 (unproven; ctor touches param_1[7] = offset 0x38)
 * Vtable: PTR_FUN_14110b5a8 (set by nuccParticleNodeList ctor in s4)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNode {
    uint64_t vtable;           /* 0x00 */
    uint8_t  _gap_0x08[8];     /* 0x08 */
    uint32_t field_0x10;       /* 0x10 - zeroed in ctor *(param_1+2)=0 */
    uint32_t field_0x14;       /* 0x14 */
    uint32_t field_0x18;       /* 0x18 - zeroed in ctor *(param_1+3)=0 */
    uint32_t field_0x1C;       /* 0x1C */
    uint32_t node_index;       /* 0x20 - *(int*)(param_1+4), set in EntryNode */
    uint32_t field_0x24;       /* 0x24 */
    uint64_t list_prev;        /* 0x28 - param_1[5], linked list prev */
    uint64_t list_next;        /* 0x30 - param_1[6], linked list next */
    uint64_t parent_list;      /* 0x38 - param_1[7], back-pointer to owner list */
} nuccParticleNode;

static_assert(offsetof(nuccParticleNode, vtable) == 0x00, "nuccParticleNode::vtable");
static_assert(offsetof(nuccParticleNode, field_0x10) == 0x10, "nuccParticleNode::field_0x10");
static_assert(offsetof(nuccParticleNode, field_0x18) == 0x18, "nuccParticleNode::field_0x18");
static_assert(offsetof(nuccParticleNode, node_index) == 0x20, "nuccParticleNode::node_index");
static_assert(offsetof(nuccParticleNode, list_prev) == 0x28, "nuccParticleNode::list_prev");
static_assert(offsetof(nuccParticleNode, list_next) == 0x30, "nuccParticleNode::list_next");
static_assert(offsetof(nuccParticleNode, parent_list) == 0x38, "nuccParticleNode::parent_list");

/* =========================================================================
 * nuccParticleNodeList
 * Inherits: nuccParticleNode (base 0x40 bytes)
 * Size: >= 0x60 (unproven; last field critical_section at 0x50, ~0x10 bytes)
 * Vtable: PTR_FUN_14110b5a8 (set in ctor)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeList {
    nuccParticleNode base;     /* 0x00 - 0x3F */
    uint64_t last_node_ptr;    /* 0x40 - param_1[8], last entered node */
    uint32_t active_count;     /* 0x48 - *(uint32*)(param_1+9), inc/dec in Entry/Release */
    uint32_t _pad_0x4C;        /* 0x4C */
    uint8_t  critical_section[16]; /* 0x50 - nuccCriticalSection at param_1+10 */
} nuccParticleNodeList;

static_assert(offsetof(nuccParticleNodeList, base) == 0x00, "nuccParticleNodeList::base");
static_assert(offsetof(nuccParticleNodeList, last_node_ptr) == 0x40, "nuccParticleNodeList::last_node_ptr");
static_assert(offsetof(nuccParticleNodeList, active_count) == 0x48, "nuccParticleNodeList::active_count");
static_assert(offsetof(nuccParticleNodeList, critical_section) == 0x50, "nuccParticleNodeList::critical_section");

/* =========================================================================
 * nuccParticleNodeListRenderer
 * Size: >= 0xA0 (unproven; Initialize writes max_priority at p+0x9C)
 * Vtable: not directly observed (no vtable set in Initialize)
 * Contains std::vector<nuccParticleRenderThread> at 0x10-0x28
 * nuccParticleRenderThread size = 0x148 (from operator_new in Initialize)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeListRenderer {
    uint64_t _gap_0x00;        /* 0x00 */
    uint32_t thread_count;     /* 0x08 - *(uint*)(p+8), set in Initialize */
    uint32_t _pad_0x0C;        /* 0x0C */
    uint64_t vector_begin;     /* 0x10 - std::vector begin ptr */
    uint64_t vector_end;       /* 0x18 - std::vector end ptr */
    uint64_t vector_capacity;  /* 0x20 - std::vector capacity ptr */
    uint8_t  _gap_0x28[24];    /* 0x28 */
    uint8_t  critical_section[16]; /* 0x40 - nuccCriticalSection::Create(p+0x40) */
    uint8_t  _gap_0x50[64];    /* 0x50 */
    uint8_t  flag;             /* 0x90 - *(uint8*)(p+0x90)=0 in Initialize */
    uint8_t  _pad_0x91[7];     /* 0x91 */
    uint32_t enable;           /* 0x98 - checked != 0 in Request(2-arg) */
    uint32_t max_priority;     /* 0x9C - set in Initialize, read in Request(2-arg) */
} nuccParticleNodeListRenderer;

static_assert(offsetof(nuccParticleNodeListRenderer, thread_count) == 0x08, "nuccParticleNodeListRenderer::thread_count");
static_assert(offsetof(nuccParticleNodeListRenderer, vector_begin) == 0x10, "nuccParticleNodeListRenderer::vector_begin");
static_assert(offsetof(nuccParticleNodeListRenderer, vector_end) == 0x18, "nuccParticleNodeListRenderer::vector_end");
static_assert(offsetof(nuccParticleNodeListRenderer, vector_capacity) == 0x20, "nuccParticleNodeListRenderer::vector_capacity");
static_assert(offsetof(nuccParticleNodeListRenderer, critical_section) == 0x40, "nuccParticleNodeListRenderer::critical_section");
static_assert(offsetof(nuccParticleNodeListRenderer, flag) == 0x90, "nuccParticleNodeListRenderer::flag");
static_assert(offsetof(nuccParticleNodeListRenderer, enable) == 0x98, "nuccParticleNodeListRenderer::enable");
static_assert(offsetof(nuccParticleNodeListRenderer, max_priority) == 0x9C, "nuccParticleNodeListRenderer::max_priority");

/* =========================================================================
 * nuccParticleNodeRoot
 * Size: >= 0x20 (unproven; Init/Ctrl/Exit write *(uint32*)(param_1+0x18))
 * Vtable: not directly observed
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeRoot {
    uint8_t  _unknown_0x00[24]; /* 0x00 - base/padding */
    uint32_t state;            /* 0x18 - 1=init, 2=ctrl, 3=exit */
    uint32_t _pad_0x1C;        /* 0x1C */
} nuccParticleNodeRoot;

static_assert(offsetof(nuccParticleNodeRoot, state) == 0x18, "nuccParticleNodeRoot::state");

/* =========================================================================
 * nuccParticlePosNode
 * Inherits: nuccParticleNodeRoot (base 0x20 bytes)
 * Size: >= 0xE0 (unproven; Ctrl accesses through param_1[0x1a]=offset 0xD0,
 *   ReleaseCoord writes *(uint32*)(p+0xc4)=3, ctor touches p[0x1a])
 * Vtable: PTR_FUN_141112958 (set in ctor)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticlePosNode {
    nuccParticleNodeRoot base; /* 0x00 - 0x1F */
    uint8_t  _gap_0x20[32];    /* 0x20 - gap before pos_data_ptr */
    uint64_t pos_data_ptr;     /* 0x40 - longlong*, used in GetNodePosNew/ReleaseCoord */
    uint64_t field_0x48;       /* 0x48 - zeroed in ctor param_1[9]=0 */
    uint8_t  matrix_0x50[64];  /* 0x50 - Matrix44_MathGeo at param_1+10 (longlong idx) */
    uint8_t  vector3_0x90[12]; /* 0x90 - Vector3 from GetNodePosNew result */
    float    pos_x;            /* 0x9C - from Init, GetPos result stored */
    float    pos_y;            /* 0xA0 */
    float    pos_z;            /* 0xA4 */
    uint8_t  vector3_0xA8[12]; /* 0xA8 - Vector3 zeroed in Init */
    float    field_0xB4;       /* 0xB4 - Vector3 component in Ctrl */
    float    field_0xB8;       /* 0xB8 - Vector3 component in Ctrl */
    float    field_0xBC;       /* 0xBC - Vector3 component in Ctrl */
    float    blend_factor;     /* 0xC0 - *(float*)(param_1+0x18) in Ctrl, blended */
    uint32_t field_0xC4;       /* 0xC4 - zeroed in ctor, set to 3 in ReleaseCoord */
    uint64_t field_0xC8;       /* 0xC8 - rw in Ctrl */
    uint8_t  vector3_0xD0[12]; /* 0xD0 - Vector3 direction in Ctrl */
    uint32_t _pad_0xDC;        /* 0xDC */
} nuccParticlePosNode;

static_assert(offsetof(nuccParticlePosNode, base) == 0x00, "nuccParticlePosNode::base");
static_assert(offsetof(nuccParticlePosNode, pos_data_ptr) == 0x40, "nuccParticlePosNode::pos_data_ptr");
static_assert(offsetof(nuccParticlePosNode, matrix_0x50) == 0x50, "nuccParticlePosNode::matrix_0x50");
static_assert(offsetof(nuccParticlePosNode, vector3_0x90) == 0x90, "nuccParticlePosNode::vector3_0x90");
static_assert(offsetof(nuccParticlePosNode, pos_x) == 0x9C, "nuccParticlePosNode::pos_x");
static_assert(offsetof(nuccParticlePosNode, vector3_0xA8) == 0xA8, "nuccParticlePosNode::vector3_0xA8");
static_assert(offsetof(nuccParticlePosNode, blend_factor) == 0xC0, "nuccParticlePosNode::blend_factor");
static_assert(offsetof(nuccParticlePosNode, field_0xC4) == 0xC4, "nuccParticlePosNode::field_0xC4");
static_assert(offsetof(nuccParticlePosNode, vector3_0xD0) == 0xD0, "nuccParticlePosNode::vector3_0xD0");

/* =========================================================================
 * nuccPostEffectComposite
 * Size: >= 0xE0 (unproven; ProcessPostDraw reads p+0xD4, padded to 0xE0)
 * Vtable: PTR_FUN_14110caf8 (set in ctor); dtor sets PTR_FUN_14110cac0
 * Contains nuccPostEffectGlare sub-object at +0x40 and nuccPostEffectDOF at +0x88
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccPostEffectComposite {
    uint64_t vtable;           /* 0x00 - PTR_FUN_14110caf8 */
    uint32_t resolution_width; /* 0x08 - SetResolution writes */
    uint32_t resolution_height;/* 0x0C - SetResolution writes */
    uint32_t viewport_x;       /* 0x10 - SetViewport param_2 */
    uint32_t viewport_y;       /* 0x14 - SetViewport param_3 */
    uint32_t viewport_w;       /* 0x18 - SetViewport param_4 */
    uint32_t viewport_h;       /* 0x1C - SetViewport param_5 */
    uint32_t field_0x20;       /* 0x20 - SetViewport param_6 */
    uint32_t field_0x24;       /* 0x24 - SetViewport param_7 */
    uint8_t  _gap_0x28[12];    /* 0x28 */
    uint32_t field_0x34;       /* 0x34 - read in ProcessPostDraw (glare enable check) */
    uint8_t  _gap_0x38[8];     /* 0x38 */
    uint8_t  glare_subobject[72]; /* 0x40 - nuccPostEffectGlare, dtor calls ~nuccPostEffectCompositeReduction() */
    uint8_t  dof_subobject[48];   /* 0x88 - nuccPostEffectDOF, dtor calls ~nuccPostEffectCompositeReduction(p+8) */
    uint32_t dof_param_0xB8;   /* 0xB8 - read in ProcessPostDraw */
    uint32_t dof_param_0xBC;   /* 0xBC - read in ProcessPostDraw */
    uint8_t  _gap_0xC0[20];    /* 0xC0 */
    float    dof_focus;        /* 0xD4 - read in ProcessPostDraw */
    uint8_t  _pad_0xD8[8];     /* 0xD8 */
} nuccPostEffectComposite;

static_assert(offsetof(nuccPostEffectComposite, vtable) == 0x00, "nuccPostEffectComposite::vtable");
static_assert(offsetof(nuccPostEffectComposite, resolution_width) == 0x08, "nuccPostEffectComposite::resolution_width");
static_assert(offsetof(nuccPostEffectComposite, resolution_height) == 0x0C, "nuccPostEffectComposite::resolution_height");
static_assert(offsetof(nuccPostEffectComposite, viewport_x) == 0x10, "nuccPostEffectComposite::viewport_x");
static_assert(offsetof(nuccPostEffectComposite, viewport_y) == 0x14, "nuccPostEffectComposite::viewport_y");
static_assert(offsetof(nuccPostEffectComposite, viewport_w) == 0x18, "nuccPostEffectComposite::viewport_w");
static_assert(offsetof(nuccPostEffectComposite, viewport_h) == 0x1C, "nuccPostEffectComposite::viewport_h");
static_assert(offsetof(nuccPostEffectComposite, field_0x20) == 0x20, "nuccPostEffectComposite::field_0x20");
static_assert(offsetof(nuccPostEffectComposite, field_0x24) == 0x24, "nuccPostEffectComposite::field_0x24");
static_assert(offsetof(nuccPostEffectComposite, field_0x34) == 0x34, "nuccPostEffectComposite::field_0x34");
static_assert(offsetof(nuccPostEffectComposite, glare_subobject) == 0x40, "nuccPostEffectComposite::glare_subobject");
static_assert(offsetof(nuccPostEffectComposite, dof_subobject) == 0x88, "nuccPostEffectComposite::dof_subobject");
static_assert(offsetof(nuccPostEffectComposite, dof_param_0xB8) == 0xB8, "nuccPostEffectComposite::dof_param_0xB8");
static_assert(offsetof(nuccPostEffectComposite, dof_param_0xBC) == 0xBC, "nuccPostEffectComposite::dof_param_0xBC");
static_assert(offsetof(nuccPostEffectComposite, dof_focus) == 0xD4, "nuccPostEffectComposite::dof_focus");

#endif /* CMN64_S4_H */