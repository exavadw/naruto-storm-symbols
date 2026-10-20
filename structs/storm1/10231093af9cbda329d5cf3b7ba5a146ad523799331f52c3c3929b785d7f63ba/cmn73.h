/* cmn73.h — struct group cmn73 for build s1 (NSUNS1.exe)
 * INFERRED from static analysis of decompiled code. Not CONFIRMED at runtime.
 * All offsets proven from PC x64 decompile (image base 0x140000000).
 * Sizes proven from operator_new / array stride in game code where available.
 */
#ifndef CMN73_H
#define CMN73_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * NUMM_THREAD_CRITICAL_SECTION_CONTEXT
 * Base class wrapping mmMutex. Ctor calls mmMutex::mmMutex() then sets +8 = 0.
 * Size: not directly allocated standalone; embedded in other structs.
 * Minimum proven extent: 0x10 (vtable ptr + mmMutex data).
 * ========================================================================= */
typedef struct __attribute__((packed)) NUMM_THREAD_CRITICAL_SECTION_CONTEXT {
    void *vtable;                /* +0x00 */
    uint8_t mmMutex_data[8];     /* +0x08 mmMutex base (size inferred) */
} NUMM_THREAD_CRITICAL_SECTION_CONTEXT;
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, vtable) == 0x00, "NUMM_THREAD_CRITICAL_SECTION_CONTEXT.vtable");
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, mmMutex_data) == 0x08, "NUMM_THREAD_CRITICAL_SECTION_CONTEXT.mmMutex_data");

/* =========================================================================
 * NUMM_THREAD_SIMPLE_THREAD_CONTEXT
 * Inherits mmThread_Impl. Ctor calls mmThread_Impl::mmThread_Impl(), sets +0x10 = 0.
 * state_surface found field at +0x58.
 * Size: unknown, >= 0x60.
 * ========================================================================= */
typedef struct __attribute__((packed)) NUMM_THREAD_SIMPLE_THREAD_CONTEXT {
    void *vtable;                /* +0x00 */
    uint8_t mmThreadImpl[8];     /* +0x08 mmThread_Impl base */
    uint32_t flags;              /* +0x10 ctor sets *(uint32*)(param_1+0x10)=0 */
    uint8_t _pad_14[4];          /* +0x14 */
    uint8_t unknown_18[64];      /* +0x18 to reach state_surface field at +0x58 */
    uint64_t field_58;           /* +0x58 state_surface */
} NUMM_THREAD_SIMPLE_THREAD_CONTEXT;
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, vtable) == 0x00, "NUMM_THREAD_SIMPLE_THREAD_CONTEXT.vtable");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, mmThreadImpl) == 0x08, "NUMM_THREAD_SIMPLE_THREAD_CONTEXT.mmThreadImpl");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, flags) == 0x10, "NUMM_THREAD_SIMPLE_THREAD_CONTEXT.flags");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, field_58) == 0x58, "NUMM_THREAD_SIMPLE_THREAD_CONTEXT.field_58");

/* =========================================================================
 * NUMM_THREAD_SYNCPOINT_CONTEXT
 * Inherits mmThreadCond. Ctor calls mmThreadCond::mmThreadCond().
 * Size: unknown, >= 0x10 (base class only).
 * ========================================================================= */
typedef struct __attribute__((packed)) NUMM_THREAD_SYNCPOINT_CONTEXT {
    void *vtable;                /* +0x00 */
    uint8_t mmThreadCond[8];     /* +0x08 mmThreadCond base (inferred) */
} NUMM_THREAD_SYNCPOINT_CONTEXT;
_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, vtable) == 0x00, "NUMM_THREAD_SYNCPOINT_CONTEXT.vtable");
_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, mmThreadCond) == 0x08, "NUMM_THREAD_SYNCPOINT_CONTEXT.mmThreadCond");

/* =========================================================================
 * nuccZSortList
 * Array element allocated in nuccZCBBox::Init with stride 0x28 (40 bytes).
 * Evidence: operator_new__(count * 0x28 + 8, "nuccZSortManager.cpp", 0x2f)
 * Each element: vtable at +0x0, fields initialized at uint*[2..9] = bytes 0x8..0x24.
 * Size: 0x28 PROVEN from allocation stride.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccZSortList {
    void *vtable;                /* +0x00 PTR_FUN_14073a678 */
    uint32_t field_08;           /* +0x08 puVar4[2] = 0 */
    uint32_t field_0c;           /* +0x0C puVar4[3] = 0 */
    uint32_t field_10;           /* +0x10 puVar4[4] = 0 */
    uint32_t _pad_14;            /* +0x14 */
    uint32_t field_18;           /* +0x18 puVar4[6] = 0 */
    uint32_t field_1c;           /* +0x1C puVar4[7] = 0 */
    uint32_t field_20;           /* +0x20 puVar4[8] = 0 */
    uint32_t field_24;           /* +0x24 puVar4[9] = 0 */
} nuccZSortList;
_Static_assert(sizeof(nuccZSortList) == 0x28, "nuccZSortList size must be 0x28");
_Static_assert(offsetof(nuccZSortList, vtable) == 0x00, "nuccZSortList.vtable");
_Static_assert(offsetof(nuccZSortList, field_08) == 0x08, "nuccZSortList.field_08");
_Static_assert(offsetof(nuccZSortList, field_0c) == 0x0C, "nuccZSortList.field_0c");
_Static_assert(offsetof(nuccZSortList, field_10) == 0x10, "nuccZSortList.field_10");
_Static_assert(offsetof(nuccZSortList, field_18) == 0x18, "nuccZSortList.field_18");
_Static_assert(offsetof(nuccZSortList, field_1c) == 0x1C, "nuccZSortList.field_1c");
_Static_assert(offsetof(nuccZSortList, field_20) == 0x20, "nuccZSortList.field_20");
_Static_assert(offsetof(nuccZSortList, field_24) == 0x24, "nuccZSortList.field_24");

/* =========================================================================
 * nuccZCBBox
 * Owns an array of nuccZSortList. Init accesses:
 * vtable (+0x0), vfunc +0x8, vfunc +0x10, count at +0x18, array ptr at +0x20.
 * Size: unknown, >= 0x28 (last accessed field + pointer size).
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccZCBBox {
    void *vtable;                /* +0x00 */
    uint8_t _pad_08[16];         /* +0x08 */
    uint32_t count;              /* +0x18 param_1[3] as uint32 */
    uint32_t _pad_1c;            /* +0x1C */
    nuccZSortList *sort_list;    /* +0x20 param_1[4] */
} nuccZCBBox;
_Static_assert(offsetof(nuccZCBBox, vtable) == 0x00, "nuccZCBBox.vtable");
_Static_assert(offsetof(nuccZCBBox, count) == 0x18, "nuccZCBBox.count");
_Static_assert(offsetof(nuccZCBBox, sort_list) == 0x20, "nuccZCBBox.sort_list");

/* =========================================================================
 * nummBinaryParser
 * Abstract parser interface. Methods call vfunc at +0x20.
 * state_surface found vtable-like ref at +0x100 but that may be a subclass.
 * Size: unknown, >= 0x28 (vtable + vfunc dispatch table through +0x20).
 * ========================================================================= */
typedef struct __attribute__((packed)) nummBinaryParser {
    void *vtable;                /* +0x00 */
    uint8_t _pad_08[24];         /* +0x08 */
    /* vfunc slot at +0x20 used by GetBinarySize/OnReadBinary/OnWriteBinary */
} nummBinaryParser;
_Static_assert(offsetof(nummBinaryParser, vtable) == 0x00, "nummBinaryParser.vtable");

/* =========================================================================
 * nummDrawSpriteBase
 * Draw method accesses param_1 (longlong*) at indices mapping to byte offsets:
 * +0x00 vtable, +0x10 vertex count (uint32, cast to int in Draw),
 * +0x14 draw count (uint32), +0x18 flags high, +0x1C flags low (uint32),
 * +0x20 material ptr, +0x60 has_texture (bool),
 * +0xB0..+0xEF matrix (8 longlongs = param_1[0x16..0x1d]),
 * +0xF0 int, +0xF4 uint32, +0xF8 uint32, +0xFC uint32.
 * Size: unknown, >= 0x100 (highest access +0xFC + 4 bytes).
 * ========================================================================= */
typedef struct __attribute__((packed)) nummDrawSpriteBase {
    void *vtable;                /* +0x00 */
    uint8_t _pad_08[8];          /* +0x08 */
    uint32_t vertex_count;       /* +0x10 param_1[2], cast to (int) in Draw */
    uint32_t draw_count;         /* +0x14 *(uint32*)(this+0x14) in Draw */
    uint32_t flags_hi;           /* +0x18 param_1[3] high bits */
    uint32_t flags_lo;           /* +0x1C *(uint32*)(this+0x1c) */
    void *material;              /* +0x20 param_1[4], passed to SetTexture */
    uint8_t _pad_28[56];         /* +0x28 */
    uint8_t has_texture;         /* +0x60 param_1[0xc] as byte */
    uint8_t _pad_61[79];         /* +0x61 */
    uint64_t matrix[8];          /* +0xB0 param_1[0x16..0x1d] = 8 longlongs */
    uint32_t field_f0;           /* +0xF0 param_1[0x1e] as int */
    uint32_t field_f4;           /* +0xF4 *(uint32*)(this+0xf4) */
    uint32_t field_f8;           /* +0xF8 lower 32 bits of param_1[0x1f] */
    uint32_t field_fc;           /* +0xFC *(uint32*)(this+0xfc) */
} nummDrawSpriteBase;
_Static_assert(offsetof(nummDrawSpriteBase, vtable) == 0x00, "nummDrawSpriteBase.vtable");
_Static_assert(offsetof(nummDrawSpriteBase, vertex_count) == 0x10, "nummDrawSpriteBase.vertex_count");
_Static_assert(offsetof(nummDrawSpriteBase, draw_count) == 0x14, "nummDrawSpriteBase.draw_count");
_Static_assert(offsetof(nummDrawSpriteBase, flags_hi) == 0x18, "nummDrawSpriteBase.flags_hi");
_Static_assert(offsetof(nummDrawSpriteBase, flags_lo) == 0x1C, "nummDrawSpriteBase.flags_lo");
_Static_assert(offsetof(nummDrawSpriteBase, material) == 0x20, "nummDrawSpriteBase.material");
_Static_assert(offsetof(nummDrawSpriteBase, has_texture) == 0x60, "nummDrawSpriteBase.has_texture");
_Static_assert(offsetof(nummDrawSpriteBase, matrix) == 0xB0, "nummDrawSpriteBase.matrix");
_Static_assert(offsetof(nummDrawSpriteBase, field_f0) == 0xF0, "nummDrawSpriteBase.field_f0");
_Static_assert(offsetof(nummDrawSpriteBase, field_f4) == 0xF4, "nummDrawSpriteBase.field_f4");
_Static_assert(offsetof(nummDrawSpriteBase, field_f8) == 0xF8, "nummDrawSpriteBase.field_f8");
_Static_assert(offsetof(nummDrawSpriteBase, field_fc) == 0xFC, "nummDrawSpriteBase.field_fc");

/* =========================================================================
 * nummDrawSprite
 * Extends nummDrawSpriteBase. state_surface found additional fields at
 * +0x70, +0x78, +0x80, +0x88, +0x98, +0xA8 beyond the base layout.
 * These overlap with base's _pad_28 region, indicating subclass additions.
 * Size: unknown, >= 0x100 (same max offset as base).
 * ========================================================================= */
typedef struct __attribute__((packed)) nummDrawSprite {
    nummDrawSpriteBase base;     /* +0x00 */
    /* Subclass fields observed by state_surface at +0x70,+0x78,+0x80,+0x88,+0x98,+0xA8
     * are within base._pad_28 region; layout is inherited, not extended beyond 0x100. */
} nummDrawSprite;
_Static_assert(offsetof(nummDrawSprite, base) == 0x00, "nummDrawSprite.base");

#endif /* CMN73_H */