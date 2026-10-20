/* cmn69.h — struct group cmn69 for build s4 (NSUNS4_release.exe, 64-bit)
 * INFERRED from static analysis of PC x64 decompiles. Not CONFIRMED.
 * Own-game names only (Storm 4 symbols/strings). No cross-game names.
 * Sizes proven from game code where noted; otherwise "size unknown".
 */
#ifndef CMN69_S4_H
#define CMN69_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccStreamMem — memory-backed stream
 * Size: unknown, >= 0x24 (last ctor-written field at +0x20, uint32)
 * Vtable: PTR_FUN_1411137e0 (set in ctor)
 * Evidence: nuccStreamMem::nuccStreamMem @ RVA 0xAACA60
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccStreamMem {
    uint64_t vtable;            /* +0x00: &PTR_FUN_1411137e0 */
    uint64_t buffer_ptr;        /* +0x08: param_2 in ctor */
    uint32_t initial_size;      /* +0x10: param_3 in ctor */
    uint32_t current_pos;       /* +0x14: rw, Seek/ctor */
    uint32_t field_18;          /* +0x18: zeroed in ctor */
    uint32_t field_1c;          /* +0x1C: r, dtor checks non-zero */
    uint32_t field_20;          /* +0x20: zeroed in ctor */
} nuccStreamMem;

static_assert(offsetof(nuccStreamMem, vtable) == 0x00, "nuccStreamMem.vtable");
static_assert(offsetof(nuccStreamMem, buffer_ptr) == 0x08, "nuccStreamMem.buffer_ptr");
static_assert(offsetof(nuccStreamMem, initial_size) == 0x10, "nuccStreamMem.initial_size");
static_assert(offsetof(nuccStreamMem, current_pos) == 0x14, "nuccStreamMem.current_pos");
static_assert(offsetof(nuccStreamMem, field_18) == 0x18, "nuccStreamMem.field_18");
static_assert(offsetof(nuccStreamMem, field_1c) == 0x1C, "nuccStreamMem.field_1c");
static_assert(offsetof(nuccStreamMem, field_20) == 0x20, "nuccStreamMem.field_20");

/* =========================================================================
 * nuccTextureIdManager — texture ID registry (tree-based)
 * Size: unknown, >= 0x88 (vfunc access at +0x80 via vtable slot +0x10)
 * Vtable: present (vfunc at *param_1+0x08 called in Entry; no PTR_FUN found)
 * Evidence: nuccTextureIdManager::Entry @ RVA 0xA84450
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccTextureIdManager {
    uint64_t vtable;            /* +0x00: vfunc slot +0x08 used in Entry */
    uint8_t _pad_08[0x34 - 0x08]; /* +0x08..+0x33 */
    uint32_t field_34;          /* +0x34: r, passed to FUN_140a84030 */
    uint8_t _pad_38[0x60 - 0x38]; /* +0x38..+0x5F */
    uint64_t tree_data_ptr;     /* +0x60: r, passed to FUN_140a23340(param_1+0xc) */
    uint8_t _pad_68[0x80 - 0x68]; /* +0x68..+0x7F */
    uint64_t field_80;          /* +0x80: r, vfunc dispatch target */
} nuccTextureIdManager;

static_assert(offsetof(nuccTextureIdManager, vtable) == 0x00, "nuccTextureIdManager.vtable");
static_assert(offsetof(nuccTextureIdManager, field_34) == 0x34, "nuccTextureIdManager.field_34");
static_assert(offsetof(nuccTextureIdManager, tree_data_ptr) == 0x60, "nuccTextureIdManager.tree_data_ptr");
static_assert(offsetof(nuccTextureIdManager, field_80) == 0x80, "nuccTextureIdManager.field_80");

/* =========================================================================
 * nuccThread — OS thread wrapper
 * Size: unknown, >= 0x5C (state_flag at +0x58, uint32)
 * Vtable: PTR_FUN_141106830
 * Inherits: NUMM_THREAD_SIMPLE_THREAD_CONTEXT (embedded at +0x08)
 * Evidence: nuccThread::nuccThread @ RVA 0xA230C0
 * Note: subclasses allocate larger (TrailRenderThread, PrimTransformThread)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccThread {
    uint64_t vtable;            /* +0x00: &PTR_FUN_141106830 */
    uint8_t thread_context[0x50]; /* +0x08..+0x57: NUMM_THREAD_SIMPLE_THREAD_CONTEXT */
    uint32_t state_flag;        /* +0x58: rw, checked !=0 and !=3 in dtor */
} nuccThread;

static_assert(offsetof(nuccThread, vtable) == 0x00, "nuccThread.vtable");
static_assert(offsetof(nuccThread, thread_context) == 0x08, "nuccThread.thread_context");
static_assert(offsetof(nuccThread, state_flag) == 0x58, "nuccThread.state_flag");

/* =========================================================================
 * nuccTrailBase — trail effect base class (inherits nuccTrailRoot)
 * Size: PROVEN 0x390 from FUN_140a017f0(0x390,...) in
 *       nuccEffectManager::EntryTrail @ RVA 0xA07D80
 * Vtable: PTR_FUN_14110c210 (set in ctor after nuccTrailRoot::nuccTrailRoot)
 * Evidence: nuccTrailBase::nuccTrailBase @ RVA 0xA618B0
 * NOTE: packed with explicit padding to match exact decompile offsets.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccTrailBase {
    uint64_t vtable;            /* +0x000 */
    uint8_t trail_root[0x188];  /* +0x008..+0x18F: nuccTrailRoot base (inferred) */
    uint64_t field_190;         /* +0x190: rw, DrawTrailCore/ctor */
    uint64_t anm_handler;       /* +0x198: rw, DrawTrailCore/ctor (ptr-sized in s4) */
    uint64_t field_1a0;         /* +0x1A0: rw, DrawTrailCore/ctor */
    uint64_t field_1a8;         /* +0x1A8: w, ctor */
    uint64_t field_1b0;         /* +0x1B0: w, SetDelayDestroy */
    uint32_t delay_destroy;     /* +0x1B8: w, SetDelayDestroy/ctor */
    uint32_t field_1bc;         /* +0x1BC: w, ctor */
    uint64_t field_1c0;         /* +0x1C0: w, ctor */
    uint32_t field_1c8;         /* +0x1C8: w, ctor */
    uint32_t field_1cc;         /* +0x1CC: w, ctor (set to 1) */
    uint32_t field_1d0;         /* +0x1D0: w, ctor */
    uint32_t field_1d4;         /* +0x1D4: rw, DrawTrailCore (checked < 1) */
    uint8_t _pad_1d8[0x218 - 0x1D8]; /* +0x1D8..+0x217 */
    uint64_t field_218;         /* +0x218: rw, DrawTrailCore/ctor */
    uint64_t field_220;         /* +0x220: rw, DrawTrailCore/ctor */
    uint64_t field_228;         /* +0x228: w, ctor */
    uint64_t block_alloc_230;   /* +0x230: rw, ctor (block allocator) */
    uint8_t _pad_238[0x2C8 - 0x238]; /* +0x238..+0x2C7 */
    uint32_t field_2c8;         /* +0x2C8: rw, DrawTrailCore */
    uint32_t _pad_2cc;          /* +0x2CC */
    uint64_t field_2d0;         /* +0x2D0: rw, DrawTrailCore */
    uint8_t _pad_2d8[0x310 - 0x2D8]; /* +0x2D8..+0x30F */
    uint64_t field_310;         /* +0x310: rw, DrawTrailCore/ctor */
    uint32_t _pad_318;          /* +0x318: alignment gap */
    uint32_t field_31c;         /* +0x31C: r, DrawTrailCore */
    uint32_t field_320;         /* +0x320: placeholder */
    uint32_t field_324;         /* +0x324: placeholder */
    uint32_t field_328;         /* +0x328: w, ctor */
    uint32_t scale_factor;      /* +0x32C: rw, DrawTrailCore/ctor (0x3f800000 = 1.0f) */
    uint64_t field_330;         /* +0x330: w, ctor */
    uint32_t field_338;         /* +0x338: w, ctor */
    uint32_t _pad_33c;          /* +0x33C */
    uint64_t chunk_data_ptr;    /* +0x340: rw, DrawTrailCore/ctor */
    uint8_t _pad_348[0x390 - 0x348]; /* +0x348..+0x38F: remaining to proven size */
} nuccTrailBase;

static_assert(offsetof(nuccTrailBase, vtable) == 0x000, "nuccTrailBase.vtable");
static_assert(offsetof(nuccTrailBase, trail_root) == 0x008, "nuccTrailBase.trail_root");
static_assert(offsetof(nuccTrailBase, field_190) == 0x190, "nuccTrailBase.field_190");
static_assert(offsetof(nuccTrailBase, anm_handler) == 0x198, "nuccTrailBase.anm_handler");
static_assert(offsetof(nuccTrailBase, field_1a0) == 0x1A0, "nuccTrailBase.field_1a0");
static_assert(offsetof(nuccTrailBase, field_1a8) == 0x1A8, "nuccTrailBase.field_1a8");
static_assert(offsetof(nuccTrailBase, field_1b0) == 0x1B0, "nuccTrailBase.field_1b0");
static_assert(offsetof(nuccTrailBase, delay_destroy) == 0x1B8, "nuccTrailBase.delay_destroy");
static_assert(offsetof(nuccTrailBase, field_1bc) == 0x1BC, "nuccTrailBase.field_1bc");
static_assert(offsetof(nuccTrailBase, field_1c0) == 0x1C0, "nuccTrailBase.field_1c0");
static_assert(offsetof(nuccTrailBase, field_1c8) == 0x1C8, "nuccTrailBase.field_1c8");
static_assert(offsetof(nuccTrailBase, field_1cc) == 0x1CC, "nuccTrailBase.field_1cc");
static_assert(offsetof(nuccTrailBase, field_1d0) == 0x1D0, "nuccTrailBase.field_1d0");
static_assert(offsetof(nuccTrailBase, field_1d4) == 0x1D4, "nuccTrailBase.field_1d4");
static_assert(offsetof(nuccTrailBase, field_218) == 0x218, "nuccTrailBase.field_218");
static_assert(offsetof(nuccTrailBase, field_220) == 0x220, "nuccTrailBase.field_220");
static_assert(offsetof(nuccTrailBase, field_228) == 0x228, "nuccTrailBase.field_228");
static_assert(offsetof(nuccTrailBase, block_alloc_230) == 0x230, "nuccTrailBase.block_alloc_230");
static_assert(offsetof(nuccTrailBase, field_2c8) == 0x2C8, "nuccTrailBase.field_2c8");
static_assert(offsetof(nuccTrailBase, field_2d0) == 0x2D0, "nuccTrailBase.field_2d0");
static_assert(offsetof(nuccTrailBase, field_310) == 0x310, "nuccTrailBase.field_310");
static_assert(offsetof(nuccTrailBase, field_31c) == 0x31C, "nuccTrailBase.field_31c");
static_assert(offsetof(nuccTrailBase, field_328) == 0x328, "nuccTrailBase.field_328");
static_assert(offsetof(nuccTrailBase, scale_factor) == 0x32C, "nuccTrailBase.scale_factor");
static_assert(offsetof(nuccTrailBase, field_330) == 0x330, "nuccTrailBase.field_330");
static_assert(offsetof(nuccTrailBase, field_338) == 0x338, "nuccTrailBase.field_338");
static_assert(offsetof(nuccTrailBase, chunk_data_ptr) == 0x340, "nuccTrailBase.chunk_data_ptr");
static_assert(sizeof(nuccTrailBase) == 0x390, "nuccTrailBase total size proven 0x390");

#endif /* CMN69_S4_H */