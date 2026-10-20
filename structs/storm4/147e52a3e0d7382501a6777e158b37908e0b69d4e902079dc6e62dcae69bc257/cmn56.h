/* cmn56.h — s4 (NSUNS4_release.exe) nucc* struct layouts
 * Generated from Ghidra decompilation (the decompiler cache cache).
 * All fields INFERRED, not CONFIRMED. PC offsets only.
 * Own-game namespace: s4 has no Trilogy ns prefix; names from Storm 4 symbols/strings.
 * Build: s4 / NSUNS4_release.exe-75912b
 */

#ifndef CMN56_S4_H
#define CMN56_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ── nuccLayerBase ───────────────────────────────────────────────
 * Vtable: 0x14110d020 (from ctor PTR_FUN_14110d020)
 * Size: unknown, >= 0x28 (no operator-new proof found)
 * Evidence: nuccLayerBase::nuccLayerBase @ 0xA915A0
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;      /* set to &PTR_FUN_14110d020 in ctor */
    /* +0x08 */ char      name[16];    /* string copy loop in ctor, null-terminated */
    /* +0x18 */ uint32_t  type_id;     /* *(param_1+3) = param_3 */
    /* +0x1C */ uint16_t  field_1C;    /* zeroed in ctor */
    /* +0x1E */ uint8_t   field_1E;    /* zeroed in ctor */
    /* +0x1F */ uint8_t   _pad_1F[5];  /* gap to +0x24 */
    /* +0x24 */ uint32_t  field_24;    /* set to 1 in ctor */
} s4_nuccLayerBase;

static_assert(offsetof(s4_nuccLayerBase, vtable)   == 0x00, "s4_nuccLayerBase.vtable");
static_assert(offsetof(s4_nuccLayerBase, name)     == 0x08, "s4_nuccLayerBase.name");
static_assert(offsetof(s4_nuccLayerBase, type_id)  == 0x18, "s4_nuccLayerBase.type_id");
static_assert(offsetof(s4_nuccLayerBase, field_1C) == 0x1C, "s4_nuccLayerBase.field_1C");
static_assert(offsetof(s4_nuccLayerBase, field_1E) == 0x1E, "s4_nuccLayerBase.field_1E");
static_assert(offsetof(s4_nuccLayerBase, field_24) == 0x24, "s4_nuccLayerBase.field_24");
/* size unproven: no sizeof assert */

/* ── nuccLayer ───────────────────────────────────────────────────
 * Inherits nuccLayerBase (ctor calls base with type_id=2).
 * Vtable: 0x141109a70 (overrides base vtable)
 * Size: unknown, >= 0x84 (BeginScene writes up to +0x80 as uint32 -> last byte at +0x83)
 * Evidence: nuccLayer::nuccLayer @ 0xA4CB20, BeginScene @ 0xAA5900
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ s4_nuccLayerBase base;       /* inherits base layout */
    /* +0x28 */ void     *field_28;          /* param_1[5] = param_3 in ctor */
    /* +0x30 */ uint32_t  field_30;          /* param_1[6], zeroed in ctor and BeginScene */
    /* +0x34 */ int32_t   field_34;          /* read conditionally in ctor */
    /* +0x38 */ uint32_t  field_38_lo;       /* low half of param_1[7], zeroed in ctor */
    /* +0x3C */ uint32_t  field_3C;          /* conditional write uVar2 in ctor; written in BeginScene */
    /* +0x40 */ void     *field_40;          /* puVar1 = param_1+8, *puVar1=0 in ctor */
    /* +0x48 */ void     *field_48;          /* param_1[9] = puVar1 (self-ptr to +0x40) */
    /* +0x50 */ uint8_t   _pad_50[4];        /* gap: state_surface shows +0x4C write but ctor skips */
    /* +0x54 */ uint8_t   _pad_54[4];        /* gap to +0x58 */
    /* +0x58 */ void     *field_58;          /* param_1[0xb] = 0 in BeginScene */
    /* +0x60 */ void     *field_60;          /* param_1[0xc] = 0 in BeginScene */
    /* +0x68 */ void     *field_68;          /* param_1[0xd] = 0 in BeginScene */
    /* +0x70 */ uint32_t  field_70;          /* *(uint32*)(param_1+0xe) = 0 in BeginScene */
    /* +0x74 */ uint32_t  field_74;          /* float 0.5f (0x3f000000) in BeginScene */
    /* +0x78 */ uint64_t  field_78;          /* param_1[0xf] = 0x3f000000 in BeginScene */
    /* +0x80 */ uint32_t  field_80;          /* *(uint32*)(param_1+0x10) = 1 in BeginScene */
} s4_nuccLayer;

static_assert(offsetof(s4_nuccLayer, base)       == 0x00, "s4_nuccLayer.base");
static_assert(offsetof(s4_nuccLayer, field_28)   == 0x28, "s4_nuccLayer.field_28");
static_assert(offsetof(s4_nuccLayer, field_30)   == 0x30, "s4_nuccLayer.field_30");
static_assert(offsetof(s4_nuccLayer, field_34)   == 0x34, "s4_nuccLayer.field_34");
static_assert(offsetof(s4_nuccLayer, field_38_lo)== 0x38, "s4_nuccLayer.field_38_lo");
static_assert(offsetof(s4_nuccLayer, field_3C)   == 0x3C, "s4_nuccLayer.field_3C");
static_assert(offsetof(s4_nuccLayer, field_40)   == 0x40, "s4_nuccLayer.field_40");
static_assert(offsetof(s4_nuccLayer, field_48)   == 0x48, "s4_nuccLayer.field_48");
static_assert(offsetof(s4_nuccLayer, field_58)   == 0x58, "s4_nuccLayer.field_58");
static_assert(offsetof(s4_nuccLayer, field_60)   == 0x60, "s4_nuccLayer.field_60");
static_assert(offsetof(s4_nuccLayer, field_68)   == 0x68, "s4_nuccLayer.field_68");
static_assert(offsetof(s4_nuccLayer, field_70)   == 0x70, "s4_nuccLayer.field_70");
static_assert(offsetof(s4_nuccLayer, field_74)   == 0x74, "s4_nuccLayer.field_74");
static_assert(offsetof(s4_nuccLayer, field_78)   == 0x78, "s4_nuccLayer.field_78");
static_assert(offsetof(s4_nuccLayer, field_80)   == 0x80, "s4_nuccLayer.field_80");
/* size unproven: no sizeof assert */

/* ── nuccLayerList ───────────────────────────────────────────────
 * Inherits nuccLayerBase (ctor calls base with type_id=3).
 * Vtable: 0x1411103e0 (overrides base vtable)
 * Size: unknown, >= 0x38 (sub-object at +0x28 via FUN_140a91620; total size unknown)
 * Evidence: nuccLayerList::nuccLayerList @ 0xA91690
 * Sub-object init FUN_140a91620 mirrors nuccInstanceList base init pattern
 * (BlockAllocator + tree structure), suggesting it is an embedded container.
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ s4_nuccLayerBase base;
    /* +0x28 */ uint8_t sub_object[16]; /* FUN_140a91620(param_1+5); BlockAllocator-based container, size unknown >= 0x10 */
} s4_nuccLayerList;

static_assert(offsetof(s4_nuccLayerList, base)        == 0x00, "s4_nuccLayerList.base");
static_assert(offsetof(s4_nuccLayerList, sub_object)  == 0x28, "s4_nuccLayerList.sub_object");
/* size unproven: no sizeof assert */

/* ── nuccInstanceList ────────────────────────────────────────────
 * No vtable observed (base init FUN_140a74a50 sets no vtable).
 * Size: unknown, >= 0x48 (fields zeroed up to +0x40 inclusive = 8 bytes -> last byte at +0x47)
 * Evidence: nuccInstanceList::nuccInstanceList @ 0xA74AC0
 * Base init FUN_140a74a50 creates a BlockAllocator-based std::__tree container
 * (same pattern as nuccLayerList sub-object). Entry/Release use std::__tree erase.
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ uint8_t  base_data[0x28]; /* initialized by FUN_140a74a50(), BlockAllocator+tree */
    /* +0x28 */ uint64_t field_28;        /* zeroed in ctor */
    /* +0x30 */ uint64_t field_30;        /* zeroed in ctor */
    /* +0x38 */ uint64_t field_38;        /* zeroed in ctor */
    /* +0x40 */ uint64_t field_40;        /* zeroed in ctor */
} s4_nuccInstanceList;

static_assert(offsetof(s4_nuccInstanceList, base_data) == 0x00, "s4_nuccInstanceList.base_data");
static_assert(offsetof(s4_nuccInstanceList, field_28)   == 0x28, "s4_nuccInstanceList.field_28");
static_assert(offsetof(s4_nuccInstanceList, field_30)   == 0x30, "s4_nuccInstanceList.field_30");
static_assert(offsetof(s4_nuccInstanceList, field_38)   == 0x38, "s4_nuccInstanceList.field_38");
static_assert(offsetof(s4_nuccInstanceList, field_40)   == 0x40, "s4_nuccInstanceList.field_40");
/* size unproven: no sizeof assert */

/* ── nuccLayerDrawCmdExecuter ────────────────────────────────────
 * No vtable (not a polymorphic class).
 * Size: PROVEN 0xA0 (operator_new(0xa0) in Initialize @ 0xA4D660)
 * Thread element stride: 0x118 (confirmed in dtor and Execute loops)
 * Evidence: Initialize @ 0xA4D660, ~dtor @ 0xA4CBF0, Execute @ 0xA4D410
 */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void    *thread_array;      /* *param_1, freed in dtor */
    /* +0x08 */ uint8_t  thread_count;      /* *(byte*)(param_1+1), loop bound */
    /* +0x09 */ uint8_t  _pad_09[3];        /* gap to +0x0C */
    /* +0x0C */ uint32_t active_mask;       /* rw bitmask in Execute, passed to syncpoint */
    /* +0x10 */ uint8_t  critical_section[0x50]; /* param_1+2, nuccCriticalSection */
    /* +0x60 */ uint8_t  syncpoint_ctx[0x40]; /* param_1+0xc, NUMM_THREAD_SYNCPOINT_CONTEXT */
} s4_nuccLayerDrawCmdExecuter;

static_assert(offsetof(s4_nuccLayerDrawCmdExecuter, thread_array)      == 0x00, "s4_nuccLayerDrawCmdExecuter.thread_array");
static_assert(offsetof(s4_nuccLayerDrawCmdExecuter, thread_count)      == 0x08, "s4_nuccLayerDrawCmdExecuter.thread_count");
static_assert(offsetof(s4_nuccLayerDrawCmdExecuter, active_mask)       == 0x0C, "s4_nuccLayerDrawCmdExecuter.active_mask");
static_assert(offsetof(s4_nuccLayerDrawCmdExecuter, critical_section)  == 0x10, "s4_nuccLayerDrawCmdExecuter.critical_section");
static_assert(offsetof(s4_nuccLayerDrawCmdExecuter, syncpoint_ctx)     == 0x60, "s4_nuccLayerDrawCmdExecuter.syncpoint_ctx");
static_assert(sizeof(s4_nuccLayerDrawCmdExecuter) == 0xA0, "s4_nuccLayerDrawCmdExecuter size PROVEN by operator_new(0xa0)");

/* ── nuccFrameBufferSampling ─────────────────────────────────────
 * Singleton pattern (CreateInstance/GetInstance/DeleteInstance).
 * No instance fields observed via param_1 in any method.
 * No struct layout reconstructed.
 */

/* ── nuccFrameBufferSampling ─────────────────────────────────────
 * Singleton (CreateInstance/GetInstance/DeleteInstance via DAT_141666ab0).
 * Size: PROVEN 0x40 (operator_new(0x40) in CreateInstance @ 0xA21660)
 * No vtable on outer object (inner nuccChunkTexture has vtable PTR_FUN_1411066a8).
 * Layout: two parallel arrays of 4 slots each (render textures + chunk textures).
 * Evidence: ctor @ 0xA21660, CreateInstance @ 0xA21700, Initialize @ 0xA218A0,
 *           GetRenderTexture @ 0xA219D0, GetChunkTexture @ 0xA21A10,
 *           UpdateSamplingTexture @ 0xA21A50, DeleteInstance @ 0xA217B0
 */
#pragma pack(push,1)
typedef struct {
    /* +0x00 */ uint64_t  render_textures[4];  /* GetRenderTexture: *(param_1 + idx*8); Initialize writes [0] */
    /* +0x20 */ void     *chunk_textures[4];   /* GetChunkTexture: *(param_1 + 0x20 + idx*8); ctor writes [0] */
} s4_nuccFrameBufferSampling;
#pragma pack(pop)

static_assert(offsetof(s4_nuccFrameBufferSampling, render_textures) == 0x00, "s4_nuccFrameBufferSampling.render_textures");
static_assert(offsetof(s4_nuccFrameBufferSampling, chunk_textures)  == 0x20, "s4_nuccFrameBufferSampling.chunk_textures");
static_assert(sizeof(s4_nuccFrameBufferSampling) == 0x40, "s4_nuccFrameBufferSampling size PROVEN by operator_new(0x40)");

#endif /* CMN56_S4_H */
