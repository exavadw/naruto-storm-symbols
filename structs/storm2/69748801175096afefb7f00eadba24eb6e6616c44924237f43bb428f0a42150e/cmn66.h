/* cmn66.h - Struct layouts for cmn66 group, build s2 (NSUNS2.exe)
 * INFERRED from static analysis only. Not CONFIRMED at runtime.
 * All offsets derived from PC x64 decompile (image base 0x140000000).
 */
#ifndef CMN66_H
#define CMN66_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nuccRenderTexture: render texture resource wrapper
 * Size unknown, >= 0x2C (last proven field at +0x24, size 8)
 * Ctor at 0x5ADDC0 initializes fields up to +0x24
 * Vtable pointer at +0x00 set to sentinel 0xFFFFFFFFFFFFFFFF in ctor
 */
typedef struct __attribute__((packed)) nuccRenderTexture {
    uint64_t vtable_or_flags_0;      /* +0x00: initialized to 0xFFFFFFFFFFFFFFFF in ctor */
    uint64_t field_8;                /* +0x08: initialized to 0xFFFFFFFFFFFFFFFF in ctor */
    uint16_t field_10;               /* +0x10: initialized to 0 in ctor */
    uint8_t _pad_12[1];              /* +0x12: padding */
    uint8_t field_13;                /* +0x13: set to 1 in Create* methods */
    uint64_t field_14;               /* +0x14: initialized to 0 in ctor */
    uint64_t field_1c;               /* +0x1C: initialized to 0 in ctor */
    uint64_t field_24;               /* +0x24: initialized to 1 in ctor */
} nuccRenderTexture;

static_assert(offsetof(nuccRenderTexture, vtable_or_flags_0) == 0x00, "nuccRenderTexture.vtable_or_flags_0");
static_assert(offsetof(nuccRenderTexture, field_8) == 0x08, "nuccRenderTexture.field_8");
static_assert(offsetof(nuccRenderTexture, field_10) == 0x10, "nuccRenderTexture.field_10");
static_assert(offsetof(nuccRenderTexture, field_13) == 0x13, "nuccRenderTexture.field_13");
static_assert(offsetof(nuccRenderTexture, field_14) == 0x14, "nuccRenderTexture.field_14");
static_assert(offsetof(nuccRenderTexture, field_1c) == 0x1C, "nuccRenderTexture.field_1c");
static_assert(offsetof(nuccRenderTexture, field_24) == 0x24, "nuccRenderTexture.field_24");

/* nuccPostEffectManager: post-effect pipeline manager (singleton)
 * Size likely 0x360 (ccFileLoadListForUi::LoadTh(0x360,...) in Initialize)
 * Fields at +0x08 (motion blur composite), +0x20 (grd00 tex id), +0x24 (nml00 tex id)
 * State surface shows access at +0xF0 in Finalize/Initialize
 */
typedef struct __attribute__((packed)) nuccPostEffectManager {
    uint64_t vtable_0;               /* +0x00: vtable pointer */
    uint64_t motion_blur_composite;  /* +0x08: nuccPostEffectCompositeMotionBlur ptr, set in Initialize */
    uint8_t _unknown_10[0x10];       /* +0x10: gap to +0x20 */
    uint32_t grd00_tex_id;           /* +0x20: written in Initialize from lVar5+0x18 */
    uint32_t nml00_tex_id;           /* +0x24: written in Initialize from lVar9+0x18 */
    uint8_t _unknown_28[0xC8];       /* +0x28: gap to +0xF0 */
    uint8_t field_f0;                /* +0xF0: read in Finalize/Initialize (puVar8 = param_1 + 0x1e scaled) */
    uint8_t _unknown_f1[0x26F];      /* +0xF1: gap to end of 0x360 allocation */
} nuccPostEffectManager;

static_assert(offsetof(nuccPostEffectManager, vtable_0) == 0x00, "nuccPostEffectManager.vtable_0");
static_assert(offsetof(nuccPostEffectManager, motion_blur_composite) == 0x08, "nuccPostEffectManager.motion_blur_composite");
static_assert(offsetof(nuccPostEffectManager, grd00_tex_id) == 0x20, "nuccPostEffectManager.grd00_tex_id");
static_assert(offsetof(nuccPostEffectManager, nml00_tex_id) == 0x24, "nuccPostEffectManager.nml00_tex_id");
static_assert(offsetof(nuccPostEffectManager, field_f0) == 0xF0, "nuccPostEffectManager.field_f0");

/* nuccRapidXml: XML parser state
 * Size unknown, >= 0x10028 (field at +0x10020 is pointer-sized, read in Clear)
 * Ctor at 0x60FF90 sets vtable at +0x00, BlockAllocator sub-object at +0x18
 * Fields at +0x10018, +0x10020 seen in Clear
 */
typedef struct __attribute__((packed)) nuccRapidXml {
    uint64_t vtable_0;               /* +0x00: vtable pointer set in ctor */
    uint8_t _unknown_8[0x10];        /* +0x08: gap to BlockAllocator */
    uint8_t block_allocator[0x68];   /* +0x18: Nucc::Memory::BlockAllocator sub-object (param_1+3) */
    uint8_t _gap_80[0xFF98];         /* +0x80: large gap to +0x10018 */
    uint64_t field_10018;            /* +0x10018: read in Clear (param_1[2] assignment context) */
    uint64_t field_10020;            /* +0x10020: pointer, null-checked in Clear */
} nuccRapidXml;

static_assert(offsetof(nuccRapidXml, vtable_0) == 0x00, "nuccRapidXml.vtable_0");
static_assert(offsetof(nuccRapidXml, block_allocator) == 0x18, "nuccRapidXml.block_allocator");
static_assert(offsetof(nuccRapidXml, field_10018) == 0x10018, "nuccRapidXml.field_10018");
static_assert(offsetof(nuccRapidXml, field_10020) == 0x10020, "nuccRapidXml.field_10020");

/* nuccReadThread: async file reader thread
 * Inherits from nuccThread (ctor calls nuccThread::nuccThread first)
 * Size unknown, >= 0x64 (field at +0x60 written in ctor per state_surface)
 * Ctor at 0x6103F0 sets vtable at +0x00, field at +0x0C to 0
 */
typedef struct __attribute__((packed)) nuccReadThread {
    uint64_t vtable_0;               /* +0x00: vtable pointer set after nuccThread ctor */
    uint32_t field_8;                /* +0x08: inherited from nuccThread or padding */
    uint32_t field_c;                /* +0x0C: initialized to 0 in ctor */
    uint8_t _unknown_10[0x50];       /* +0x10: gap to +0x60 */
    uint32_t field_60;               /* +0x60: written in ctor per state_surface */
} nuccReadThread;

static_assert(offsetof(nuccReadThread, vtable_0) == 0x00, "nuccReadThread.vtable_0");
static_assert(offsetof(nuccReadThread, field_c) == 0x0C, "nuccReadThread.field_c");
static_assert(offsetof(nuccReadThread, field_60) == 0x60, "nuccReadThread.field_60");

/* nuccPostEffectOutline: outline post-effect renderer (global singleton)
 * Size unknown, >= 0x30 (last proven field at +0x28, pointer-sized)
 * Global singleton accessed via PTR_PTR_14099b4f8 in nuccLayerPostOutline::Draw
 * Vtable present: DrawPEOutline_ShadingID referenced from data @0x14090d140, @0x14090d150
 * No ctor found; object is statically allocated
 */
#pragma pack(push,1)
typedef struct nuccPostEffectOutline {
    uint64_t vtable_0;               /* +0x00: vtable pointer (inferred from data xrefs) */
    int32_t field_8;                 /* +0x08: enable flag, checked == 1 in Draw */
    uint32_t render_tex_global_0;    /* +0x0C: render texture global index 0, set in SetRenderTex */
    uint32_t render_tex_global_1;    /* +0x10: render texture global index 1, set in SetRenderTex */
    uint32_t depth_tex_index;        /* +0x14: depth texture index, set in SetRenderTex */
    uint8_t _pad_18[0x10];           /* +0x18: gap to +0x28 */
    uint64_t view_ptr;               /* +0x28: nuccView pointer, null-checked in Draw */
} nuccPostEffectOutline;
#pragma pack(pop)

static_assert(offsetof(nuccPostEffectOutline, vtable_0) == 0x00, "nuccPostEffectOutline.vtable_0");
static_assert(offsetof(nuccPostEffectOutline, field_8) == 0x08, "nuccPostEffectOutline.field_8");
static_assert(offsetof(nuccPostEffectOutline, render_tex_global_0) == 0x0C, "nuccPostEffectOutline.render_tex_global_0");
static_assert(offsetof(nuccPostEffectOutline, render_tex_global_1) == 0x10, "nuccPostEffectOutline.render_tex_global_1");
static_assert(offsetof(nuccPostEffectOutline, depth_tex_index) == 0x14, "nuccPostEffectOutline.depth_tex_index");
static_assert(offsetof(nuccPostEffectOutline, _pad_18) == 0x18, "nuccPostEffectOutline._pad_18");
static_assert(offsetof(nuccPostEffectOutline, view_ptr) == 0x28, "nuccPostEffectOutline.view_ptr");

/* Classes with < 3 methods or no field evidence in s2:
 *   nuccPostEffectParamGlare (1 method: ctor only)
 *   nuccPrimitiveTransform (1 method: Transform)
 *   nuccPrimitiveTransformP32N32C1UV1onPPU (1 method: TransformCore)
 *   nuccRefStr (1 method: operator<, 0 fields)
 * These are listed in REPORT.md as gaps.
 */

#endif /* CMN66_H */