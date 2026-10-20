/* cmn56.h — s3 (NSUNS3.exe) nucc* struct layouts
 * Generated from Ghidra decompilation (the decompiler cache cache).
 * All fields INFERRED, not CONFIRMED. PC offsets only.
 * Own-game namespace: ns3::
 * Build: s3 / NSUNS3.exe-a7124b / sha 55b726e94dad
 */

#ifndef CMN56_S3_H
#define CMN56_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ── nuccLayerBase ───────────────────────────────────────────────
 * Vtable: 0x1409e02e8 (from ctor PTR_FUN_1409e02e8)
 * Size: >= 0x28 (no operator-new proof found)
 * Evidence: nuccLayerBase::nuccLayerBase @ 0x6B6F40
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void    *vtable;      /* set to &PTR_FUN_1409e02e8 in ctor */
    /* +0x08 */ char     name[16];    /* string copy loop in ctor, null-terminated */
    /* +0x18 */ uint32_t type_id;     /* *(param_1+3) = param_3 */
    /* +0x1C */ uint16_t field_1C;    /* zeroed in ctor */
    /* +0x1E */ uint8_t  field_1E;    /* zeroed in ctor */
    /* +0x1F */ uint8_t  _pad_1F[5];  /* gap to +0x24 */
    /* +0x24 */ uint32_t field_24;    /* set to 1 in ctor */
} ns3_nuccLayerBase;

static_assert(offsetof(ns3_nuccLayerBase, vtable)   == 0x00, "ns3_nuccLayerBase.vtable");
static_assert(offsetof(ns3_nuccLayerBase, name)     == 0x08, "ns3_nuccLayerBase.name");
static_assert(offsetof(ns3_nuccLayerBase, type_id)  == 0x18, "ns3_nuccLayerBase.type_id");
static_assert(offsetof(ns3_nuccLayerBase, field_1C) == 0x1C, "ns3_nuccLayerBase.field_1C");
static_assert(offsetof(ns3_nuccLayerBase, field_1E) == 0x1E, "ns3_nuccLayerBase.field_1E");
static_assert(offsetof(ns3_nuccLayerBase, field_24) == 0x24, "ns3_nuccLayerBase.field_24");
static_assert(sizeof(ns3_nuccLayerBase) == 0x28, "ns3_nuccLayerBase size");

/* ── nuccLayer ───────────────────────────────────────────────────
 * Inherits nuccLayerBase (ctor calls base with type_id=2).
 * Vtable: 0x1409e0ba8 (overrides base vtable)
 * Size: >= 0x50 (no operator-new proof found)
 * Evidence: nuccLayer::nuccLayer @ 0x6C02C0
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ ns3_nuccLayerBase base;       /* inherits base layout */
    /* +0x28 */ void    *field_28;            /* param_1[5] = param_3 */
    /* +0x30 */ uint32_t field_30;            /* param_1[6], zeroed */
    /* +0x34 */ int32_t  field_34;            /* read conditionally in ctor */
    /* +0x38 */ uint32_t field_38_lo;         /* low half of param_1[7], zeroed */
    /* +0x3C */ uint32_t field_3C;            /* conditional write uVar2 in ctor */
    /* +0x40 */ void    *field_40;            /* puVar1 = param_1+8, *puVar1=0 */
    /* +0x48 */ void    *field_48;            /* param_1[9] = puVar1 (self-ptr to +0x40) */
} ns3_nuccLayer;

static_assert(offsetof(ns3_nuccLayer, base)       == 0x00, "ns3_nuccLayer.base");
static_assert(offsetof(ns3_nuccLayer, field_28)   == 0x28, "ns3_nuccLayer.field_28");
static_assert(offsetof(ns3_nuccLayer, field_30)   == 0x30, "ns3_nuccLayer.field_30");
static_assert(offsetof(ns3_nuccLayer, field_34)   == 0x34, "ns3_nuccLayer.field_34");
static_assert(offsetof(ns3_nuccLayer, field_38_lo)== 0x38, "ns3_nuccLayer.field_38_lo");
static_assert(offsetof(ns3_nuccLayer, field_3C)   == 0x3C, "ns3_nuccLayer.field_3C");
static_assert(offsetof(ns3_nuccLayer, field_40)   == 0x40, "ns3_nuccLayer.field_40");
static_assert(offsetof(ns3_nuccLayer, field_48)   == 0x48, "ns3_nuccLayer.field_48");
static_assert(sizeof(ns3_nuccLayer) == 0x50, "ns3_nuccLayer size");

/* ── nuccLayerList ───────────────────────────────────────────────
 * Inherits nuccLayerBase (ctor calls base with type_id=3).
 * Vtable: 0x1409e0358 (overrides base vtable)
 * Size: >= 0x38 (sub-object at +0x28 via FUN_1406b7000; total size unknown)
 * Evidence: nuccLayerList::nuccLayerList @ 0x6B7070
 * Entry/Release access param_1[5] (+0x28 list head), param_1[6] (+0x30 count)
 * state_surface showed vtable dispatches at +0xC0 and +0x100 but these are
 * sub-object internal offsets, not direct fields of nuccLayerList.
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ ns3_nuccLayerBase base;
    /* +0x28 */ uint8_t sub_object[16]; /* FUN_1406b7000(param_1+5); size unknown, >= 0x10 */
} ns3_nuccLayerList;

static_assert(offsetof(ns3_nuccLayerList, base)        == 0x00, "ns3_nuccLayerList.base");
static_assert(offsetof(ns3_nuccLayerList, sub_object)  == 0x28, "ns3_nuccLayerList.sub_object");

/* ── nuccInstanceList ────────────────────────────────────────────
 * No vtable observed (base init FUN_1406d3ce0 sets no vtable).
 * Size: >= 0x48 (fields zeroed up to +0x40 inclusive = 8 bytes -> last byte at +0x47)
 * Evidence: nuccInstanceList::nuccInstanceList @ 0x6D3D50
 * Uses std::__tree internally (Entry calls FUN_1406d3740/FUN_1406d3a60,
 * Release calls std::__tree erase).
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ uint8_t  base_data[0x28]; /* initialized by FUN_1406d3ce0(), layout unknown */
    /* +0x28 */ uint64_t field_28;        /* zeroed in ctor */
    /* +0x30 */ uint64_t field_30;        /* zeroed in ctor */
    /* +0x38 */ uint64_t field_38;        /* zeroed in ctor */
    /* +0x40 */ uint64_t field_40;        /* zeroed in ctor */
} ns3_nuccInstanceList;

static_assert(offsetof(ns3_nuccInstanceList, base_data) == 0x00, "ns3_nuccInstanceList.base_data");
static_assert(offsetof(ns3_nuccInstanceList, field_28)   == 0x28, "ns3_nuccInstanceList.field_28");
static_assert(offsetof(ns3_nuccInstanceList, field_30)   == 0x30, "ns3_nuccInstanceList.field_30");
static_assert(offsetof(ns3_nuccInstanceList, field_38)   == 0x38, "ns3_nuccInstanceList.field_38");
static_assert(offsetof(ns3_nuccInstanceList, field_40)   == 0x40, "ns3_nuccInstanceList.field_40");
static_assert(sizeof(ns3_nuccInstanceList) == 0x48, "ns3_nuccInstanceList size");

/* ── nuccLayerDrawCmdExecuter ────────────────────────────────────
 * No vtable (not a polymorphic class).
 * Size: >= 0x68 (syncpoint context at +0x60 accessed in dtor/Execute)
 * Thread element stride: 0x118 (confirmed in dtor and Execute loops)
 * Evidence: ~dtor @ 0x6C0390, Execute @ 0x6C0BB0
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void    *thread_array;      /* *param_1, freed in dtor */
    /* +0x08 */ uint8_t  thread_count;      /* *(byte*)(param_1+1), loop bound */
    /* +0x09 */ uint8_t  _pad_09[3];        /* gap to +0x0C */
    /* +0x0C */ uint32_t active_mask;       /* rw bitmask in Execute, passed to syncpoint */
    /* +0x10 */ uint8_t  critical_section[0x50]; /* param_1+2, lock/unlock funcs */
    /* +0x60 */ uint8_t  syncpoint_ctx[8];  /* param_1+0xc, signaled in Execute */
} ns3_nuccLayerDrawCmdExecuter;

static_assert(offsetof(ns3_nuccLayerDrawCmdExecuter, thread_array)      == 0x00, "ns3_nuccLayerDrawCmdExecuter.thread_array");
static_assert(offsetof(ns3_nuccLayerDrawCmdExecuter, thread_count)      == 0x08, "ns3_nuccLayerDrawCmdExecuter.thread_count");
static_assert(offsetof(ns3_nuccLayerDrawCmdExecuter, active_mask)       == 0x0C, "ns3_nuccLayerDrawCmdExecuter.active_mask");
static_assert(offsetof(ns3_nuccLayerDrawCmdExecuter, critical_section)  == 0x10, "ns3_nuccLayerDrawCmdExecuter.critical_section");
static_assert(offsetof(ns3_nuccLayerDrawCmdExecuter, syncpoint_ctx)     == 0x60, "ns3_nuccLayerDrawCmdExecuter.syncpoint_ctx");
static_assert(sizeof(ns3_nuccLayerDrawCmdExecuter) == 0x68, "ns3_nuccLayerDrawCmdExecuter size");

/* ── nuccFrameBufferSampling ─────────────────────────────────────
 * Singleton pattern (CreateInstance/GetInstance/DeleteInstance).
 * Vtable: none (ctor sets *param_1 = 0, not a vtable ptr)
 * Size: 0x40 (proven by ccFileLoadListForUi::LoadTh(0x40,...) in CreateInstance @ 0x6A2F00)
 * Two arrays of 4 pointers each, indexed by char param_2 in Get/Update methods.
 * Evidence: ctor @ 0x6A2D90, Initialize @ 0x6A2FD0,
 *           GetRenderTexture @ 0x6A2FC0, GetChunkTexture @ 0x6A2FA0,
 *           UpdateSamplingTexture @ 0x6A3090, DeleteInstance @ 0x6A2F50
 * All fields INFERRED from static decompilation.
 */
#pragma pack(push, 1)
typedef struct {
    /* +0x00 */ void *render_textures[4];   /* GetRenderTexture: *(param_1 + idx*8); ctor zeros [0], Initialize writes [0] */
    /* +0x20 */ void *chunk_textures[4];    /* GetChunkTexture: *(param_1 + 0x20 + idx*8); ctor sets [0] to nuccChunkTexture* */
} ns3_nuccFrameBufferSampling;
#pragma pack(pop)

static_assert(offsetof(ns3_nuccFrameBufferSampling, render_textures) == 0x00, "ns3_nuccFrameBufferSampling.render_textures");
static_assert(offsetof(ns3_nuccFrameBufferSampling, chunk_textures)  == 0x20, "ns3_nuccFrameBufferSampling.chunk_textures");
static_assert(sizeof(ns3_nuccFrameBufferSampling) == 0x40, "ns3_nuccFrameBufferSampling size");

#endif /* CMN56_S3_H */