/* cmn64 s2: struct layouts for nucc particle/post-effect classes (NARUTO STORM 2 PC)
 * All layouts INFERRED from static analysis of NSUNS2.exe (build s2, sha 69748801175096af).
 * Sizes proven from allocation sites or last accessed field; unproven sizes noted.
 * Field names from s2 strings/code only (OWN-GAME rule: ns2:: namespace).
 *
 * Reconstructed classes (>= 3 methods):
 *   nuccParticleNodeList, nuccParticleNodeListRenderer, nuccParticleNodeRoot,
 *   nuccParticlePosNode, nuccPostEffectComposite
 *
 * Listed-only classes (< 3 methods):
 *   nuccParticlePosList, nuccParticleRenderThread, nuccParticleResourceList,
 *   nuccParticlePosNodeData
 */
#ifndef CMN64_S2_H
#define CMN64_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccParticleNode (base class - not in cmn64 group, needed for inheritance)
 * Size: unknown, >= 0x40 (ctor touches param_1[7] = offset 0x38)
 * Vtable: set by subclass ctors
 * Evidence: nuccParticleNode::nuccParticleNode ctor
 *
 * Ghidra decompile (undefined8 *param_1):
 *   *(undefined4*)(param_1 + 3) = 0;  // byte off 0x18
 *   *(undefined4*)(param_1 + 4) = 0;  // byte off 0x20
 *   param_1[5] = 0;                   // off 0x28
 *   param_1[6] = 0;                   // off 0x30
 *   param_1[7] = 0;                   // off 0x38
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNode {
    uint64_t vtable;              /* 0x00 */
    uint8_t  _gap_0x08[0x10];     /* 0x08 - unknown */
    uint32_t field_0x18;          /* 0x18 - *(param_1+3)=0 in ctor */
    uint32_t field_0x1C;          /* 0x1C - padding / unused */
    uint32_t field_0x20;          /* 0x20 - *(param_1+4)=0 in ctor */
    uint32_t field_0x24;          /* 0x24 - padding / unused */
    uint64_t list_prev;           /* 0x28 - param_1[5]=0 */
    uint64_t list_next;           /* 0x30 - param_1[6]=0 */
    uint64_t parent_list;         /* 0x38 - param_1[7]=0 */
} nuccParticleNode;

static_assert(offsetof(nuccParticleNode, vtable)      == 0x00, "nuccParticleNode::vtable");
static_assert(offsetof(nuccParticleNode, field_0x18)   == 0x18, "nuccParticleNode::field_0x18");
static_assert(offsetof(nuccParticleNode, field_0x20)   == 0x20, "nuccParticleNode::field_0x20");
static_assert(offsetof(nuccParticleNode, list_prev)    == 0x28, "nuccParticleNode::list_prev");
static_assert(offsetof(nuccParticleNode, list_next)    == 0x30, "nuccParticleNode::list_next");
static_assert(offsetof(nuccParticleNode, parent_list)  == 0x38, "nuccParticleNode::parent_list");

/* =========================================================================
 * nuccParticleNodeList
 * Inherits: nuccParticleNode
 * Size: unknown, >= 0x60 (last proven field: critical_section at 0x50, size ~0x10)
 * Vtable: PTR_FUN_140893528
 * Evidence: ctor @ RVA 0x5C0820
 *
 * Ctor decompile (undefined8 *param_1):
 *   nuccParticleNode::nuccParticleNode();
 *   *param_1 = &PTR_FUN_140893528;
 *   nuccCriticalSection(param_1 + 10);   // off 0x50
 *   nuccCriticalSection::Create(param_1 + 10);
 *   param_1[8] = 0;                     // off 0x40
 *   *(undefined4*)(param_1 + 9) = 0;     // off 0x48
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeList {
    nuccParticleNode base;             /* 0x00 - inherits nuccParticleNode (0x40 bytes) */
    uint64_t node_count;               /* 0x40 - param_1[8], set 0 in ctor, inc in EntryNode */
    uint32_t active_count;             /* 0x48 - *(undefined4*)(param_1+9), set 0 in ctor */
    uint32_t _pad_0x4C;                /* 0x4C - alignment padding */
    uint8_t  critical_section[0x10];   /* 0x50 - nuccCriticalSection embedded */
} nuccParticleNodeList;
/* Size unknown, >= 0x60. No sizeof assert. */

static_assert(offsetof(nuccParticleNodeList, base)             == 0x00, "nuccParticleNodeList::base");
static_assert(offsetof(nuccParticleNodeList, node_count)       == 0x40, "nuccParticleNodeList::node_count");
static_assert(offsetof(nuccParticleNodeList, active_count)     == 0x48, "nuccParticleNodeList::active_count");
static_assert(offsetof(nuccParticleNodeList, critical_section) == 0x50, "nuccParticleNodeList::critical_section");

/* =========================================================================
 * nuccParticleNodeListRenderer
 * Size: unknown (no allocation site found for the renderer itself)
 * Vtable: not directly observed
 * Evidence: Initialize @ RVA 0x5C1950
 *
 * Fields from Initialize/Request decompilation:
 *   *(uint*)(param_1 + 8) = param_2 & 0xff;        // thread count
 *   std::vector at param_1 + 0x10 (begin/end/capacity = 0x10/0x18/0x20)
 *   nuccCriticalSection at param_1 + 0x40
 *   *(undefined1*)(param_1 + 0x90) = 0;            // flag
 *   *(int*)(param_1 + 0x98) checked in Request     // enable flag
 *   *(undefined4*)(param_1 + 0x9c) = param_3;      // max priority
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeListRenderer {
    uint64_t vtable;                   /* 0x00 */
    uint32_t thread_count;             /* 0x08 - param_2 & 0xff in Initialize */
    uint32_t _pad_0x0C;                /* 0x0C - alignment */
    uint64_t vector_begin;             /* 0x10 - std::vector begin ptr */
    uint64_t vector_end;               /* 0x18 - std::vector end ptr */
    uint64_t vector_capacity;          /* 0x20 - std::vector capacity ptr */
    uint8_t  _gap_0x28[0x18];          /* 0x28 - unknown */
    uint8_t  critical_section[0x10];   /* 0x40 - nuccCriticalSection */
    uint8_t  _gap_0x50[0x40];          /* 0x50 - unknown */
    uint8_t  flag_0x90;                /* 0x90 - set 0 in Initialize */
    uint8_t  _gap_0x91[0x07];          /* 0x91 - padding */
    uint32_t enable_flag;              /* 0x98 - checked != 0 in Request */
    uint32_t max_priority;             /* 0x9C - param_3 in Initialize */
} nuccParticleNodeListRenderer;
/* Size unknown, >= 0xA0. No sizeof assert. */

static_assert(offsetof(nuccParticleNodeListRenderer, thread_count)     == 0x08, "nuccParticleNodeListRenderer::thread_count");
static_assert(offsetof(nuccParticleNodeListRenderer, vector_begin)     == 0x10, "nuccParticleNodeListRenderer::vector_begin");
static_assert(offsetof(nuccParticleNodeListRenderer, vector_end)       == 0x18, "nuccParticleNodeListRenderer::vector_end");
static_assert(offsetof(nuccParticleNodeListRenderer, vector_capacity)  == 0x20, "nuccParticleNodeListRenderer::vector_capacity");
static_assert(offsetof(nuccParticleNodeListRenderer, critical_section) == 0x40, "nuccParticleNodeListRenderer::critical_section");
static_assert(offsetof(nuccParticleNodeListRenderer, flag_0x90)        == 0x90, "nuccParticleNodeListRenderer::flag_0x90");
static_assert(offsetof(nuccParticleNodeListRenderer, enable_flag)      == 0x98, "nuccParticleNodeListRenderer::enable_flag");
static_assert(offsetof(nuccParticleNodeListRenderer, max_priority)     == 0x9C, "nuccParticleNodeListRenderer::max_priority");

/* =========================================================================
 * nuccParticleNodeRoot
 * Size: unknown, >= 0x20 (Init/Ctrl/Exit write *(undefined4*)(param_1 + 0x18))
 * Vtable: not directly observed
 * Evidence: Init @ RVA 0x5FDE70, Ctrl @ RVA 0x5FDE50, Exit @ RVA 0x5FDE60
 *
 * Init sets state=1, Ctrl sets state=2, Exit sets state=3
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeRoot {
    uint8_t  _unknown_0x00[0x18];  /* 0x00 - unknown base/padding */
    uint32_t state;                /* 0x18 - 1=init, 2=ctrl, 3=release */
    uint8_t  _pad_0x1C[0x04];      /* 0x1C - padding to 0x20 */
} nuccParticleNodeRoot;
/* Size unknown, >= 0x20. No sizeof assert. */

static_assert(offsetof(nuccParticleNodeRoot, state) == 0x18, "nuccParticleNodeRoot::state");

/* =========================================================================
 * nuccParticlePosNode
 * Inherits: nuccParticleNodeRoot -> nuccParticleNode hierarchy
 * Size: 0xE0 (224 bytes) - PROVEN by ccFileLoadListForUi::LoadTh(0xe0, ...)
 *   (observed in nuccParticleNodeListRenderer::Initialize allocating render threads)
 * Vtable: PTR_FUN_14089cd28 (set in ctor)
 * Evidence: ctor @ RVA 0x627700, Init @ RVA 0x627B20, Ctrl @ RVA 0x6278D0
 *
 * Ctor layout (param_1 as undefined8*):
 *   nuccParticleNode::nuccParticleNode()
 *   *param_1 = &PTR_FUN_14089cd28
 *   Matrix44 at param_1 + 10 (= byte 0x50)
 *   Vector3 at param_1 + 0x12 (= byte 0x90)
 *   Vector3 at param_1 + 0x15 (= byte 0xA8 -- but actually 0x9C from byte calc)
 *   Vector3 at param_1 + 0x1a (= byte 0xD0)
 *   param_1[8] = 0  => byte 0x40
 *   param_1[9] = 0  => byte 0x48
 *   *(uint32*)(param_1 + 0xc4) = 0
 *   param_1[0x19] = 0 => byte 0xC8
 *
 * From Ctrl:
 *   param_1[6] = parent (inherited from nuccParticleNode at 0x30)
 *   GetPos at param_1 + 8 => byte 0x40
 *   Vector3 ops at param_1 + 0x1a (byte 0xD0), param_1 + 0x15 (byte 0xA8)
 *   *(float*)(param_1 + 0x18) blend factor => byte 0xC4 (but 0x18*8=0xC0? no, 0x18 as int index)
 *   Actually: param_1 is longlong*, so param_1[0x18] = byte 0xC0, param_1[0x19] = byte 0xC8
 *   param_1[0x1a] = byte 0xD0, param_1[0x1b] = byte 0xD8
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticlePosNode {
    nuccParticleNodeRoot base;       /* 0x00 - inherits nuccParticleNodeRoot */
    uint8_t  pos_data[0x20];         /* 0x20 - embedded data region */
    uint64_t node_count_copy;        /* 0x40 - param_1[8], set 0 in ctor (same slot as NodeList) */
    uint64_t field_0x48;             /* 0x48 - param_1[9], set 0 in ctor */
    uint8_t  matrix44[0x40];         /* 0x50 - Nucc::Matrix44_MathGeo at param_1+10 */
    uint8_t  vector3_0x90[0x0C];     /* 0x90 - Nucc::Vector3 at param_1+0x12 */
    uint32_t _pad_0x9C;              /* 0x9C - padding */
    uint8_t  vector3_0xA0[0x0C];     /* 0xA0 - Nucc::Vector3 (from Init GetPos result) */
    uint32_t _pad_0xAC;              /* 0xAC - padding */
    uint8_t  vector3_0xB0[0x0C];     /* 0xB0 - Nucc::Vector3 copy in Ctrl */
    uint32_t blend_factor;           /* 0xBC - float, nuccPartFloatBlend result */
    uint64_t field_0xC0;             /* 0xC0 - rw in Ctrl */
    uint32_t field_0xC8;             /* 0xC8 - param_1[0x19], set 0 in ctor */
    uint32_t _pad_0xCC;              /* 0xCC - padding */
    uint8_t  vector3_0xD0[0x0C];     /* 0xD0 - Nucc::Vector3 at param_1+0x1a */
    uint32_t _pad_0xDC;              /* 0xDC - padding to 0xE0 */
} nuccParticlePosNode;

static_assert(sizeof(nuccParticlePosNode) == 0xE0, "nuccParticlePosNode size 0xE0 proven by LoadTh");
static_assert(offsetof(nuccParticlePosNode, base)          == 0x00, "nuccParticlePosNode::base");
static_assert(offsetof(nuccParticlePosNode, pos_data)      == 0x20, "nuccParticlePosNode::pos_data");
static_assert(offsetof(nuccParticlePosNode, node_count_copy) == 0x40, "nuccParticlePosNode::node_count_copy");
static_assert(offsetof(nuccParticlePosNode, field_0x48)    == 0x48, "nuccParticlePosNode::field_0x48");
static_assert(offsetof(nuccParticlePosNode, matrix44)      == 0x50, "nuccParticlePosNode::matrix44");
static_assert(offsetof(nuccParticlePosNode, vector3_0x90)  == 0x90, "nuccParticlePosNode::vector3_0x90");
static_assert(offsetof(nuccParticlePosNode, vector3_0xA0)  == 0xA0, "nuccParticlePosNode::vector3_0xA0");
static_assert(offsetof(nuccParticlePosNode, vector3_0xB0)  == 0xB0, "nuccParticlePosNode::vector3_0xB0");
static_assert(offsetof(nuccParticlePosNode, blend_factor)  == 0xBC, "nuccParticlePosNode::blend_factor");
static_assert(offsetof(nuccParticlePosNode, field_0xC0)    == 0xC0, "nuccParticlePosNode::field_0xC0");
static_assert(offsetof(nuccParticlePosNode, field_0xC8)    == 0xC8, "nuccParticlePosNode::field_0xC8");
static_assert(offsetof(nuccParticlePosNode, vector3_0xD0)  == 0xD0, "nuccParticlePosNode::vector3_0xD0");

/* =========================================================================
 * nuccPostEffectComposite
 * Inherits: nuccPostEffectGlare -> nuccPostEffectDOF chain
 * Size: unknown, >= 0xE0 (ProcessPostDraw accesses param_1+0xd4, SetViewport writes 0x24)
 * Vtable: PTR_FUN_140899160 (ctor sets), PTR_FUN_140899128 (dtor restores)
 * Evidence: ctor @ RVA 0x605620, ProcessPostDraw @ RVA 0x605740,
 *           SetResolution @ RVA 0x605D70, SetViewport @ RVA 0x605DF0
 *
 * Ctor decompile (undefined8 *param_1):
 *   *param_1 = &PTR_FUN_140899160;
 *   nuccPostEffectGlare::nuccPostEffectGlare();
 *   nuccPostEffectDOF::nuccPostEffectDOF(param_1 + 0x11); // byte 0x88
 *   param_1[1..7] = 0;  // 0x08 through 0x38 zeroed
 *
 * SetResolution: *(uint32*)(p+8)=width, *(uint32*)(p+0xc)=height, sub at p+0x40, p+0x88
 * SetViewport: writes 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24; sub at p+0x88
 * ProcessPostDraw: reads 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x34, 0xb8, 0xbc, 0xd4
 *                  sub-objects at p+0x40 (Glare), p+0x88 (DOF)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccPostEffectComposite {
    uint64_t vtable;                /* 0x00 - PTR_FUN_140899160 */
    uint32_t resolution_width;      /* 0x08 - SetResolution writes */
    uint32_t resolution_height;     /* 0x0C - SetResolution writes */
    uint32_t viewport_x;            /* 0x10 - SetViewport writes */
    uint32_t viewport_y;            /* 0x14 - SetViewport writes */
    uint32_t viewport_w;            /* 0x18 - SetViewport writes */
    uint32_t viewport_h;            /* 0x1C - SetViewport writes */
    uint32_t field_0x20;            /* 0x20 - SetViewport writes */
    uint32_t field_0x24;            /* 0x24 - SetViewport writes */
    uint8_t  _gap_0x28[0x0C];       /* 0x28 - unknown */
    uint32_t glare_enable;          /* 0x34 - checked in ProcessPostDraw */
    uint8_t  _gap_0x38[0x08];       /* 0x38 - unknown */
    uint8_t  glare_subobject[0x48]; /* 0x40 - nuccPostEffectGlare sub-object */
    uint8_t  dof_subobject[0x30];   /* 0x88 - nuccPostEffectDOF prefix (internal fields follow) */
    uint32_t dof_param_0xB8;        /* 0xB8 - checked != 0 in ProcessPostDraw */
    uint32_t dof_param_0xBC;        /* 0xBC - checked != 0 in ProcessPostDraw */
    uint8_t  _gap_0xC0[0x14];       /* 0xC0 - unknown */
    float    dof_focus;             /* 0xD4 - checked > 0.0 in ProcessPostDraw */
    uint8_t  _pad_0xD8[0x08];       /* 0xD8 - padding */
} nuccPostEffectComposite;
/* Size unknown, >= 0xE0. No sizeof assert. */

static_assert(offsetof(nuccPostEffectComposite, vtable)            == 0x00, "nuccPostEffectComposite::vtable");
static_assert(offsetof(nuccPostEffectComposite, resolution_width)  == 0x08, "nuccPostEffectComposite::resolution_width");
static_assert(offsetof(nuccPostEffectComposite, resolution_height) == 0x0C, "nuccPostEffectComposite::resolution_height");
static_assert(offsetof(nuccPostEffectComposite, viewport_x)        == 0x10, "nuccPostEffectComposite::viewport_x");
static_assert(offsetof(nuccPostEffectComposite, viewport_y)        == 0x14, "nuccPostEffectComposite::viewport_y");
static_assert(offsetof(nuccPostEffectComposite, viewport_w)        == 0x18, "nuccPostEffectComposite::viewport_w");
static_assert(offsetof(nuccPostEffectComposite, viewport_h)        == 0x1C, "nuccPostEffectComposite::viewport_h");
static_assert(offsetof(nuccPostEffectComposite, field_0x20)        == 0x20, "nuccPostEffectComposite::field_0x20");
static_assert(offsetof(nuccPostEffectComposite, field_0x24)        == 0x24, "nuccPostEffectComposite::field_0x24");
static_assert(offsetof(nuccPostEffectComposite, glare_enable)      == 0x34, "nuccPostEffectComposite::glare_enable");
static_assert(offsetof(nuccPostEffectComposite, glare_subobject)   == 0x40, "nuccPostEffectComposite::glare_subobject");
static_assert(offsetof(nuccPostEffectComposite, dof_subobject)     == 0x88, "nuccPostEffectComposite::dof_subobject");
static_assert(offsetof(nuccPostEffectComposite, dof_param_0xB8)    == 0xB8, "nuccPostEffectComposite::dof_param_0xB8");
static_assert(offsetof(nuccPostEffectComposite, dof_param_0xBC)    == 0xBC, "nuccPostEffectComposite::dof_param_0xBC");
static_assert(offsetof(nuccPostEffectComposite, dof_focus)         == 0xD4, "nuccPostEffectComposite::dof_focus");

#endif /* CMN64_S2_H */