/* cmn64 s1: struct layouts for nucc particle/post-effect classes (NARUTO STORM 1 PC)
 * All layouts INFERRED from static analysis of NSUNS1.exe (build s1, sha 10231093af9c).
 * Sizes proven from allocation sites or last accessed field; unproven sizes noted.
 * Field names from Switch Trilogy ns1:: namespace or s1 strings/code only.
 *
 * Reconstructed classes (>= 3 methods):
 *   nuccParticleNodeList, nuccParticleNodeListRenderer, nuccParticleNodeRoot,
 *   nuccParticlePosNode, nuccPostEffectComposite
 *
 * Listed-only classes (< 3 methods):
 *   nuccParticlePosList, nuccParticleRenderThread, nuccParticleResourceList,
 *   nuccParticlePosNodeData
 */
#ifndef CMN64_S1_H
#define CMN64_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccParticleNode (base class - not in cmn64 group, needed for inheritance)
 * Size: unknown, >= 0x40 (ctor touches param_1[7] = offset 0x38)
 * Vtable: PTR_FUN_140743c78
 * Evidence: nuccParticleNode::nuccParticleNode ctor
 *
 * Ghidra decompile (undefined8 *param_1):
 *   *(undefined4*)(param_1 + 3) = 0;  // byte off 0x18
 *   *(undefined4*)(param_1 + 4) = 0;  // byte off 0x20
 *   *param_1 = &PTR_FUN_140743c78;    // vtable
 *   param_1[5] = 0;                   // off 0x28
 *   param_1[6] = 0;                   // off 0x30
 *   param_1[7] = 0;                   // off 0x38
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNode {
    uint64_t vtable;          /* 0x00 */
    uint8_t  _gap_0x08[0x10]; /* 0x08 - unknown */
    uint32_t field_0x18;      /* 0x18 - *(param_1+3)=0 in ctor */
    uint32_t field_0x1C;      /* 0x1C - padding / unused */
    uint32_t field_0x20;      /* 0x20 - *(param_1+4)=0 in ctor */
    uint32_t field_0x24;      /* 0x24 - padding / unused */
    uint64_t list_prev;       /* 0x28 - param_1[5]=0 */
    uint64_t list_next;       /* 0x30 - param_1[6]=0 */
    uint64_t parent_list;     /* 0x38 - param_1[7]=0 */
} nuccParticleNode;

static_assert(offsetof(nuccParticleNode, vtable)      == 0x00, "nuccParticleNode::vtable");
static_assert(offsetof(nuccParticleNode, field_0x18)  == 0x18, "nuccParticleNode::field_0x18");
static_assert(offsetof(nuccParticleNode, field_0x20)  == 0x20, "nuccParticleNode::field_0x20");
static_assert(offsetof(nuccParticleNode, list_prev)   == 0x28, "nuccParticleNode::list_prev");
static_assert(offsetof(nuccParticleNode, list_next)   == 0x30, "nuccParticleNode::list_next");
static_assert(offsetof(nuccParticleNode, parent_list) == 0x38, "nuccParticleNode::parent_list");

/* =========================================================================
 * nuccParticleNodeList
 * Inherits: nuccParticleNode
 * Size: unknown, >= 0x60 (last proven field: critical_section at 0x50, size ~0x10)
 * Vtable: PTR_FUN_14073df60
 * Evidence: ctor @ RVA 0x4DD7D0
 *
 * Ghidra decompile of ctor (undefined8 *param_1):
 *   nuccParticleNode::nuccParticleNode();
 *   *param_1 = &PTR_FUN_14073df60;           // override vtable
 *   nuccCriticalSection(param_1 + 10);        // off 0x50
 *   nuccCriticalSection::Create(param_1 + 10);
 *   param_1[8] = 0;                          // off 0x40
 *   *(undefined4*)(param_1 + 9) = 0;         // off 0x48
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeList {
    nuccParticleNode base;            /* 0x00 - inherits nuccParticleNode (0x40 bytes) */
    uint64_t node_count;              /* 0x40 - param_1[8], set 0 in ctor, inc in EntryNode */
    uint32_t active_count;            /* 0x48 - *(undefined4*)(param_1+9), set 0 in ctor */
    uint32_t _pad_0x4C;               /* 0x4C - alignment padding */
    uint8_t  critical_section[0x10];  /* 0x50 - nuccCriticalSection embedded */
} nuccParticleNodeList;
/* Size unknown, >= 0x60. No sizeof assert. */

static_assert(offsetof(nuccParticleNodeList, base)             == 0x00, "nuccParticleNodeList::base");
static_assert(offsetof(nuccParticleNodeList, node_count)       == 0x40, "nuccParticleNodeList::node_count");
static_assert(offsetof(nuccParticleNodeList, active_count)     == 0x48, "nuccParticleNodeList::active_count");
static_assert(offsetof(nuccParticleNodeList, critical_section) == 0x50, "nuccParticleNodeList::critical_section");

/* =========================================================================
 * nuccParticleNodeListRenderer
 * Size: unknown (no allocation site found)
 * Vtable: not observed (state_surface returned 0 fields)
 * Only 4 methods; minimal reconstruction - listed in report only.
 * ========================================================================= */

/* =========================================================================
 * nuccParticleNodeRoot
 * Size: unknown, >= 0x20 (Init/Ctrl write *(undefined4*)(param_1 + 0x18))
 * Vtable: not directly observed
 * Evidence: Init sets state=1, Ctrl sets state=2, NowRelease checks state==3
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticleNodeRoot {
    uint8_t  _unknown_0x00[0x18]; /* 0x00 - unknown base/padding */
    uint32_t state;               /* 0x18 - 1=init, 2=ctrl, 3=release */
    uint8_t  _pad_0x1C[0x04];     /* 0x1C - padding to 0x20 */
} nuccParticleNodeRoot;
/* Size unknown, >= 0x20. No sizeof assert. */

static_assert(offsetof(nuccParticleNodeRoot, state) == 0x18, "nuccParticleNodeRoot::state");

/* =========================================================================
 * nuccParticlePosNode
 * Inherits: nuccParticleNodeRoot -> nuccParticleNode hierarchy
 * Size: 0xE0 (224 bytes) - PROVEN by ccFileLoadListForUi::LoadTh(0xe0, ...)
 * Vtable: set by subclass ctors (e.g. nuccParticleForceFieldNode -> PTR_FUN_140743d28)
 * Evidence: Init @ RVA 0x5400720, Ctrl @ RVA 0x5400128, ctor @ RVA 0x526470
 *
 * Fields from state_surface + manual decompile analysis:
 *   Init calls nuccParticleNodeRoot::Init, Vector3::zero(), stores GetPos result
 *   Ctrl accesses parent at param_1[6], calls GetPos on param_1+8 (offset 0x40),
 *   Vector3 ops at offsets 0xD0, 0xB4, 0xBC, 0x9C, 0xA4
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccParticlePosNode {
    nuccParticleNodeRoot base;   /* 0x00 - inherits nuccParticleNodeRoot */
    uint8_t  pos_data[0x70];     /* 0x20 - embedded data (GetPos at param_1+8=0x40) */
    uint64_t field_0x90;         /* 0x90 - rw, low conf */
    uint32_t field_0x98;         /* 0x98 - w, medium conf */
    uint32_t field_0x9C;         /* 0x9C - part of Vector3 (from Ctrl) */
    uint64_t field_0xA0;         /* 0xA0 - position data (from Init GetPos) */
    uint32_t field_0xA8;         /* 0xA8 - Vector3 component */
    uint32_t field_0xAC;         /* 0xAC - padding or float */
    uint32_t field_0xB0;         /* 0xB0 - rw high conf */
    uint32_t field_0xB4;         /* 0xB4 - rw, Vector3 copy (from Ctrl) */
    uint32_t field_0xB8;         /* 0xB8 - vector component */
    uint32_t field_0xBC;         /* 0xBC - w high conf (from Ctrl) */
    uint32_t field_0xC0;         /* 0xC0 - rw high conf */
    uint32_t field_0xC4;         /* 0xC4 - w high conf */
    uint64_t field_0xC8;         /* 0xC8 - rw high conf */
    uint64_t field_0xD0;         /* 0xD0 - rw low conf (Vector3 from Ctrl) */
    uint32_t field_0xD8;         /* 0xD8 - w high conf */
    uint8_t  _pad_0xDC[0x04];    /* 0xDC - padding to 0xE0 */
} nuccParticlePosNode;

static_assert(sizeof(nuccParticlePosNode)                == 0xE0, "nuccParticlePosNode size 0xE0 proven by LoadTh");
static_assert(offsetof(nuccParticlePosNode, base)        == 0x00, "nuccParticlePosNode::base");
static_assert(offsetof(nuccParticlePosNode, pos_data)    == 0x20, "nuccParticlePosNode::pos_data");
static_assert(offsetof(nuccParticlePosNode, field_0x90)  == 0x90, "nuccParticlePosNode::field_0x90");
static_assert(offsetof(nuccParticlePosNode, field_0x98)  == 0x98, "nuccParticlePosNode::field_0x98");
static_assert(offsetof(nuccParticlePosNode, field_0x9C)  == 0x9C, "nuccParticlePosNode::field_0x9C");
static_assert(offsetof(nuccParticlePosNode, field_0xA0)  == 0xA0, "nuccParticlePosNode::field_0xA0");
static_assert(offsetof(nuccParticlePosNode, field_0xA8)  == 0xA8, "nuccParticlePosNode::field_0xA8");
static_assert(offsetof(nuccParticlePosNode, field_0xB0)  == 0xB0, "nuccParticlePosNode::field_0xB0");
static_assert(offsetof(nuccParticlePosNode, field_0xB4)  == 0xB4, "nuccParticlePosNode::field_0xB4");
static_assert(offsetof(nuccParticlePosNode, field_0xBC)  == 0xBC, "nuccParticlePosNode::field_0xBC");
static_assert(offsetof(nuccParticlePosNode, field_0xC0)  == 0xC0, "nuccParticlePosNode::field_0xC0");
static_assert(offsetof(nuccParticlePosNode, field_0xC8)  == 0xC8, "nuccParticlePosNode::field_0xC8");
static_assert(offsetof(nuccParticlePosNode, field_0xD0)  == 0xD0, "nuccParticlePosNode::field_0xD0");
static_assert(offsetof(nuccParticlePosNode, field_0xD8)  == 0xD8, "nuccParticlePosNode::field_0xD8");

/* =========================================================================
 * nuccPostEffectComposite
 * Inherits: nuccPostEffectGlare -> nuccPostEffectDOF chain
 * Size: unknown, >= 0xD8 (ProcessPostDraw accesses param_1+0xd4)
 * Vtable: PTR_FUN_14073eea0 (ctor sets), PTR_FUN_14073ee68 (dtor restores)
 * Evidence: ctor @ RVA 0x4EDE00, ProcessPostDraw @ RVA 0x4EE0E0,
 *           SetResolution @ RVA 0x4F0510
 *
 * Ctor decompile (undefined8 *param_1):
 *   *param_1 = &PTR_FUN_14073eea0;
 *   nuccPostEffectGlare::nuccPostEffectGlare();
 *   nuccPostEffectDOF::nuccPostEffectDOF(param_1 + 0x11); // off 0x88
 *   param_1[1..7] = 0;
 *
 * SetResolution writes resolution at byte offsets 0x40 and 0x44.
 * ProcessPostDraw accesses: 0x08, 0x10, 0x14, 0x18, 0x1c, 0x34, 0x40, 0xb8, 0xbc, 0xd4
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccPostEffectComposite {
    uint64_t vtable;             /* 0x00 - PTR_FUN_14073eea0 */
    uint32_t field_0x08;         /* 0x08 - accessed in ProcessPostDraw */
    uint32_t field_0x0C;         /* 0x0C - padding/unused */
    uint64_t field_0x10;         /* 0x10 - accessed in ProcessPostDraw */
    uint32_t field_0x18;         /* 0x18 - accessed in ProcessPostDraw */
    uint32_t field_0x1C;         /* 0x1C - accessed in ProcessPostDraw */
    uint8_t  _gap_0x20[0x14];    /* 0x20 - unknown */
    uint32_t field_0x34;         /* 0x34 - accessed in ProcessPostDraw */
    uint8_t  _gap_0x38[0x08];    /* 0x38 - unknown */
    uint32_t resolution_width;   /* 0x40 - SetResolution writes here */
    uint32_t resolution_height;  /* 0x44 - SetResolution writes here */
    uint8_t  _gap_0x48[0x40];    /* 0x48 - Glare/DOF subobjects (ctor: DOF at 0x88) */
    uint32_t field_0x88;         /* 0x88 - DOF subobject start */
    uint8_t  _gap_0x8C[0x2C];    /* 0x8C - unknown */
    uint32_t field_0xB8;         /* 0xB8 - accessed in ProcessPostDraw */
    uint32_t field_0xBC;         /* 0xBC - accessed in ProcessPostDraw */
    uint8_t  _gap_0xC0[0x14];    /* 0xC0 - unknown */
    uint32_t field_0xD4;         /* 0xD4 - accessed in ProcessPostDraw */
    uint8_t  _pad_0xD8[0x08];    /* 0xD8 - padding */
} nuccPostEffectComposite;
/* Size unknown, >= 0xD8. No sizeof assert. */

static_assert(offsetof(nuccPostEffectComposite, vtable)            == 0x00, "nuccPostEffectComposite::vtable");
static_assert(offsetof(nuccPostEffectComposite, field_0x08)        == 0x08, "nuccPostEffectComposite::field_0x08");
static_assert(offsetof(nuccPostEffectComposite, field_0x10)        == 0x10, "nuccPostEffectComposite::field_0x10");
static_assert(offsetof(nuccPostEffectComposite, field_0x18)        == 0x18, "nuccPostEffectComposite::field_0x18");
static_assert(offsetof(nuccPostEffectComposite, field_0x1C)        == 0x1C, "nuccPostEffectComposite::field_0x1C");
static_assert(offsetof(nuccPostEffectComposite, field_0x34)        == 0x34, "nuccPostEffectComposite::field_0x34");
static_assert(offsetof(nuccPostEffectComposite, resolution_width)  == 0x40, "nuccPostEffectComposite::resolution_width");
static_assert(offsetof(nuccPostEffectComposite, resolution_height) == 0x44, "nuccPostEffectComposite::resolution_height");
static_assert(offsetof(nuccPostEffectComposite, field_0x88)        == 0x88, "nuccPostEffectComposite::field_0x88");
static_assert(offsetof(nuccPostEffectComposite, field_0xB8)        == 0xB8, "nuccPostEffectComposite::field_0xB8");
static_assert(offsetof(nuccPostEffectComposite, field_0xBC)        == 0xBC, "nuccPostEffectComposite::field_0xBC");
static_assert(offsetof(nuccPostEffectComposite, field_0xD4)        == 0xD4, "nuccPostEffectComposite::field_0xD4");

#endif /* CMN64_S1_H */