/* cmn69.h — struct group cmn69 for build s1 (NSUNS1.exe)
 * INFERRED from static analysis of PC x64 decompiles. Not CONFIRMED.
 * Own-game names only (ns1:: / Storm 1 strings). No cross-game names.
 * Sizes proven from game code where noted; otherwise "size unknown".
 */
#ifndef CMN69_H
#define CMN69_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccStreamMem — memory-backed stream
 * Size: unknown, >= 0x20 (last proven field at +0x1C, vtable at +0x00)
 * Vtable: PTR_FUN_140739370
 * Evidence: nuccStreamMem::nuccStreamMem @ 0x4A6DA0
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccStreamMem {
    uint64_t vtable;              /* +0x00: &PTR_FUN_140739370 */
    uint64_t buffer_ptr;          /* +0x08: param_2 in ctor */
    uint32_t initial_size;        /* +0x10: param_3 in ctor */
    uint32_t current_pos;         /* +0x14: rw, Seek/ctor */
    uint32_t field_18;            /* +0x18: padding/reserved */
    uint32_t field_1c;            /* +0x1C: r, dtor checks non-zero */
} nuccStreamMem;

static_assert(offsetof(nuccStreamMem, vtable) == 0x00, "nuccStreamMem.vtable");
static_assert(offsetof(nuccStreamMem, buffer_ptr) == 0x08, "nuccStreamMem.buffer_ptr");
static_assert(offsetof(nuccStreamMem, initial_size) == 0x10, "nuccStreamMem.initial_size");
static_assert(offsetof(nuccStreamMem, current_pos) == 0x14, "nuccStreamMem.current_pos");
static_assert(offsetof(nuccStreamMem, field_18) == 0x18, "nuccStreamMem.field_18");
static_assert(offsetof(nuccStreamMem, field_1c) == 0x1C, "nuccStreamMem.field_1c");

/* =========================================================================
 * nuccSysUserSetting — user language settings
 * Size: unknown, >= 0x40 (last proven field at +0x3C)
 * Vtable: none found (no vfunc calls or vtable writes in any method)
 * Evidence: SetDefaultLanguage @ 0x48D970, SetLanguage @ 0x48D9C0,
 *           GetApplicationLangueage @ 0x42BC20
 * INFERRED from static analysis; state_surface returned 0 fields due to
 * element-size ambiguity, but explain shows param_1+4/+0x30/+0x38/+0x3C.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct nuccSysUserSetting {
    uint8_t _pad_00[0x04 - 0x00]; /* +0x00..+0x03 */
    uint32_t field_0x04;          /* +0x04: rw, SetDefaultLanguage reads/writes, SetLanguage writes */
    uint8_t _pad_08[0x30 - 0x08]; /* +0x08..+0x2F */
    uint64_t field_0x30;          /* +0x30: w, GetApplicationLangueage sets to &DAT_1408400d0 */
    uint32_t field_0x38;          /* +0x38: rw, GetApplicationLangueage loop result index */
    uint32_t field_0x3c;          /* +0x3C: w, GetApplicationLangueage sets to 6 (loop bound) */
} nuccSysUserSetting;
#pragma pack(pop)

static_assert(offsetof(nuccSysUserSetting, _pad_00) == 0x00, "nuccSysUserSetting._pad_00");
static_assert(offsetof(nuccSysUserSetting, field_0x04) == 0x04, "nuccSysUserSetting.field_0x04");
static_assert(offsetof(nuccSysUserSetting, _pad_08) == 0x08, "nuccSysUserSetting._pad_08");
static_assert(offsetof(nuccSysUserSetting, field_0x30) == 0x30, "nuccSysUserSetting.field_0x30");
static_assert(offsetof(nuccSysUserSetting, field_0x38) == 0x38, "nuccSysUserSetting.field_0x38");
static_assert(offsetof(nuccSysUserSetting, field_0x3c) == 0x3C, "nuccSysUserSetting.field_0x3c");

/* =========================================================================
 * nuccTextureIdManager — texture ID registry (tree-based)
 * Size: unknown, >= 0x80 (last accessed offset in Entry/Release)
 * Vtable: present (vfunc at *param_1+0x10 called in Entry)
 * Evidence: nuccTextureIdManager::Entry @ 0x504B40
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccTextureIdManager {
    uint64_t vtable;              /* +0x00 */
    uint8_t _pad_08[0x2C - 0x08]; /* +0x08..+0x2B */
    uint32_t field_2c;            /* +0x2C: r, used in Entry hash lookup */
    uint8_t _pad_30[0x34 - 0x30]; /* +0x30..+0x33 */
    uint32_t field_34;            /* +0x34: r, passed to FUN_140504720 */
    uint8_t _pad_38[0x60 - 0x38]; /* +0x38..+0x5F */
    uint64_t tree_root;           /* +0x60: r, ccShopEternalMission::CtrlCloseQuick base */
    uint8_t _pad_68[0x80 - 0x68]; /* +0x68..+0x7F */
    /* vfunc slot at +0x10 in vtable used by Entry/Release */
} nuccTextureIdManager;

static_assert(offsetof(nuccTextureIdManager, vtable) == 0x00, "nuccTextureIdManager.vtable");
static_assert(offsetof(nuccTextureIdManager, field_2c) == 0x2C, "nuccTextureIdManager.field_2c");
static_assert(offsetof(nuccTextureIdManager, field_34) == 0x34, "nuccTextureIdManager.field_34");
static_assert(offsetof(nuccTextureIdManager, tree_root) == 0x60, "nuccTextureIdManager.tree_root");

/* =========================================================================
 * nuccThread — OS thread wrapper
 * Size: unknown, >= 0x68 (field at +0x58 + NUMM_THREAD_SIMPLE_THREAD_CONTEXT base)
 * Vtable: PTR_FUN_14073c2a0
 * Inherits: NUMM_THREAD_SIMPLE_THREAD_CONTEXT (embedded at +0x08)
 * Evidence: nuccThread::nuccThread @ 0x4D10A0
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccThread {
    uint64_t vtable;              /* +0x00: &PTR_FUN_14073c2a0 */
    uint8_t thread_context[0x50]; /* +0x08..+0x57: NUMM_THREAD_SIMPLE_THREAD_CONTEXT */
    uint32_t state_flag;          /* +0x58: rw, checked !=0 and !=3 in dtor */
    uint8_t _pad_5c[0x68 - 0x5C]; /* +0x5C..+0x67 */
} nuccThread;

static_assert(offsetof(nuccThread, vtable) == 0x00, "nuccThread.vtable");
static_assert(offsetof(nuccThread, thread_context) == 0x08, "nuccThread.thread_context");
static_assert(offsetof(nuccThread, state_flag) == 0x58, "nuccThread.state_flag");

/* =========================================================================
 * nuccTrailBase — trail effect base class (inherits nuccTrailRoot)
 * Size: PROVEN 0x390 from ccFileLoadListForUi::LoadTh(0x390,...) in
 *        nuccEffectManager::EntryTrail @ 0x4993A0
 * Vtable: PTR_FUN_14073eb00 (set in ctor after nuccTrailRoot::nuccTrailRoot)
 * Evidence: nuccTrailBase::nuccTrailBase @ 0x4E56E0
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccTrailBase {
    uint64_t vtable;              /* +0x000: &PTR_FUN_14073eb00 */
    uint8_t trail_root[0x188];    /* +0x008..+0x18F: nuccTrailRoot base (inferred) */
    uint64_t anm_handler;         /* +0x190: rw, DrawTrailCore reads, ctor writes */
    uint64_t field_198;           /* +0x198: rw, DrawTrailCore */
    uint64_t field_1a0;           /* +0x1A0: rw, ctor writes 0 */
    uint64_t field_1a8;           /* +0x1A8: w, ctor writes 0 */
    uint64_t field_1b0;           /* +0x1B0: w, SetDelayDestroy writes 0 */
    uint32_t delay_destroy;       /* +0x1B8: w, SetDelayDestroy writes 0xFFFFFFFF */
    uint8_t _pad_1bc[0x1C0 - 0x1BC]; /* +0x1BC..+0x1BF */
    uint32_t field_1c0;           /* +0x1C0: w, ctor writes 0 */
    uint8_t _pad_1c4[0x1CC - 0x1C4]; /* +0x1C4..+0x1CB */
    uint64_t field_1cc;           /* +0x1CC: rw, ctor writes 1 */
    uint8_t _pad_1d4[0x1D4 - 0x1D4]; /* (none) */
    uint32_t field_1d4;           /* +0x1D4: rw, ctor writes 0xFFFFFFFF */
    uint8_t _pad_1d8[0x218 - 0x1D8]; /* +0x1D8..+0x217 */
    uint64_t field_218;           /* +0x218: rw, DrawTrailCore arithmetic */
    uint64_t field_220;           /* +0x220: rw, DrawTrailCore arithmetic */
    uint8_t _pad_228[0x230 - 0x228]; /* +0x228..+0x22F */
    uint64_t block_alloc_230;     /* +0x230: w, ctor BlockAllocator init */
    uint8_t _pad_238[0x2C8 - 0x238]; /* +0x238..+0x2C7 */
    uint32_t field_2c8;           /* +0x2C8: rw, DrawTrailCore */
    uint8_t _pad_2cc[0x2D0 - 0x2CC]; /* +0x2CC..+0x2CF */
    uint32_t field_2d0;           /* +0x2D0: rw, DrawTrailCore */
    uint8_t _pad_2d4[0x310 - 0x2D4]; /* +0x2D4..+0x30F */
    uint64_t field_310;           /* +0x310: rw, DrawTrailCore conditional */
    uint8_t _pad_318[0x32C - 0x318]; /* +0x318..+0x32B */
    float scale_factor;           /* +0x32C: rw, ctor writes 1.0f (0x3f800000) */
    uint8_t _pad_330[0x340 - 0x330]; /* +0x330..+0x33F */
    uint64_t chunk_data_ptr;      /* +0x340: rw, EntryTrail sets plVar6[0x34] */
    uint64_t billboard_ptr;       /* +0x348: rw, EntryTrail sets plVar6[0x38] */
    uint8_t _pad_350[0x390 - 0x350]; /* +0x350..+0x38F: remaining to proven size */
} nuccTrailBase;

static_assert(offsetof(nuccTrailBase, vtable) == 0x000, "nuccTrailBase.vtable");
static_assert(offsetof(nuccTrailBase, trail_root) == 0x008, "nuccTrailBase.trail_root");
static_assert(offsetof(nuccTrailBase, anm_handler) == 0x190, "nuccTrailBase.anm_handler");
static_assert(offsetof(nuccTrailBase, field_198) == 0x198, "nuccTrailBase.field_198");
static_assert(offsetof(nuccTrailBase, field_1a0) == 0x1A0, "nuccTrailBase.field_1a0");
static_assert(offsetof(nuccTrailBase, field_1a8) == 0x1A8, "nuccTrailBase.field_1a8");
static_assert(offsetof(nuccTrailBase, field_1b0) == 0x1B0, "nuccTrailBase.field_1b0");
static_assert(offsetof(nuccTrailBase, delay_destroy) == 0x1B8, "nuccTrailBase.delay_destroy");
static_assert(offsetof(nuccTrailBase, field_1c0) == 0x1C0, "nuccTrailBase.field_1c0");
static_assert(offsetof(nuccTrailBase, field_1cc) == 0x1CC, "nuccTrailBase.field_1cc");
static_assert(offsetof(nuccTrailBase, field_1d4) == 0x1D4, "nuccTrailBase.field_1d4");
static_assert(offsetof(nuccTrailBase, field_218) == 0x218, "nuccTrailBase.field_218");
static_assert(offsetof(nuccTrailBase, field_220) == 0x220, "nuccTrailBase.field_220");
static_assert(offsetof(nuccTrailBase, block_alloc_230) == 0x230, "nuccTrailBase.block_alloc_230");
static_assert(offsetof(nuccTrailBase, field_2c8) == 0x2C8, "nuccTrailBase.field_2c8");
static_assert(offsetof(nuccTrailBase, field_2d0) == 0x2D0, "nuccTrailBase.field_2d0");
static_assert(offsetof(nuccTrailBase, field_310) == 0x310, "nuccTrailBase.field_310");
static_assert(offsetof(nuccTrailBase, scale_factor) == 0x32C, "nuccTrailBase.scale_factor");
static_assert(offsetof(nuccTrailBase, chunk_data_ptr) == 0x340, "nuccTrailBase.chunk_data_ptr");
static_assert(offsetof(nuccTrailBase, billboard_ptr) == 0x348, "nuccTrailBase.billboard_ptr");
static_assert(sizeof(nuccTrailBase) == 0x390, "nuccTrailBase total size proven 0x390");

#endif /* CMN69_H */