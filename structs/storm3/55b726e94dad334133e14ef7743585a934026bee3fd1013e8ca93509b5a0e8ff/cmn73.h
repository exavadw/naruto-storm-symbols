/*
 * cmn73 s3 — struct layouts for common engine/UI/render/math classes
 * Build: s3 (NSUNS3.exe, PC x64, image base 0x140000000)
 * Status: INFERRED from static analysis. Not CONFIRMED at runtime.
 * Own-game names only (ns3:: / Storm 3 strings).
 */

#ifndef CMN73_S3_H
#define CMN73_S3_H

#include <stdint.h>
#include <stddef.h>

#pragma pack(push, 1)

/* NUMM_THREAD_CRITICAL_SECTION_CONTEXT — size >= 0x10 */
typedef struct {
    void     *vtable;       /* 0x00 */
    uint8_t   mmMutex_data[8]; /* 0x08 */
} NUMM_THREAD_CRITICAL_SECTION_CONTEXT;

/* NUMM_THREAD_SIMPLE_THREAD_CONTEXT — size >= 0x14 */
typedef struct {
    void     *vtable;       /* 0x00 */
    uint8_t   mmThreadImpl[8]; /* 0x08 */
    uint32_t  flags;        /* 0x10 */
} NUMM_THREAD_SIMPLE_THREAD_CONTEXT;

/* NUMM_THREAD_SYNCPOINT_CONTEXT — size >= 0x10 (no vtable, plain data) */
typedef struct {
    uint8_t   mmThreadCond[16]; /* 0x00 — ctor calls mmThreadCond(param_1,...) */
} NUMM_THREAD_SYNCPOINT_CONTEXT;

/* nuccZSortList — size PROVEN 0xA8
 * Clear sets end_ptr = base+0xA0, sentinel at base+0x58, head at base+0x80.
 * Embedded nummCriticalSection at +0x08 (Lock/Unlock dispatch at +8).
 * Array element stride 0x28 confirmed by nuccZCBBox::Add/Del iteration. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   crit_section[0x50]; /* 0x08 — embedded nummCriticalSection */
    uint8_t   sentinel_node[0x28]; /* 0x58 — ZSortEntry sentinel */
    void     *head;             /* 0x80 */
    uint64_t  field_88;         /* 0x88 */
    void     *tail_sentinel;    /* 0x90 */
    uint8_t   _pad_98[8];       /* 0x98 */
    void     *end_ptr;          /* 0xA0 */
} nuccZSortList;

/* nuccZCBBox — size >= 0x28
 * Init allocates array of nuccZSortList (stride 0xA8 per element in global array,
 * but each sort_list entry is 0x28 bytes). Add/Del iterate param_1+0x20 with stride 0x28. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x10];    /* 0x08 — vtable dispatch slots at +8,+0x10 */
    uint32_t  count;            /* 0x18 */
    uint8_t   _pad_1c[4];       /* 0x1C */
    void     *sort_list_array;  /* 0x20 */
} nuccZCBBox;

/* nuccZSortManager — size >= 0x34
 * ActiveListSort reads fields at +0x20, +0x28, +0x30.
 * Init allocates nuccZSortList array with stride 0xA8. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x18];    /* 0x08 */
    uint32_t  sort_param;       /* 0x20 */
    uint8_t   _pad_24[4];       /* 0x24 */
    void     *sort_list_base;   /* 0x28 */
    uint32_t  sort_index;       /* 0x30 */
} nuccZSortManager;

/* nummBinaryAccessor — size >= 0x20 */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x10];    /* 0x08 */
    void     *read_func_ptr;    /* 0x18 — dispatch slot used by ReadBinary */
} nummBinaryAccessor;

/* nummBinaryParser — size >= 0x28
 * ParseExecution_GetSize::OnParse accumulates at +0x8.
 * GetBinarySize/OnReadBinary/OnWriteBinary all dispatch vfunc at +0x20. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint64_t  accum_size;       /* 0x08 */
    uint8_t   _pad_10[0x10];    /* 0x10 */
    void     *dispatch_func;    /* 0x20 */
} nummBinaryParser;

/* nummCriticalSection — size >= 0x54
 * Unlock reads hash_table at +0x08, bucket_count at +0x10, lock_count at +0x14.
 * Lock writes lock_state at +0x20. ChangeGlobalIndex accesses +0x24. */
typedef struct {
    void     *vtable;           /* 0x00 */
    void     *hash_table;       /* 0x08 */
    uint32_t  bucket_count;     /* 0x10 */
    uint32_t  lock_count;       /* 0x14 */
    uint32_t  lock_state;       /* 0x18 — written by Lock */
    uint8_t   _pad_1c[4];       /* 0x1C */
    uint8_t   shader_mgr[0x30]; /* 0x20 — ChangeGlobalIndex target at +0x24 */
} nummCriticalSection;

/* nummDrawSpriteBase — size >= 0x24
 * Draw checks draw_flags bit 0x4000 at +0xC (param_1+3 as uint*).
 * Draw reads render_resource hash key at +0x1C (param_1 as longlong*, +0x1c byte offset).
 * Vtable dispatches at +0, +8, +0x10. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[4];       /* 0x08 */
    uint32_t  draw_flags;       /* 0x0C */
    uint8_t   _pad_10[0xC];     /* 0x10 */
    uint32_t  render_resource;  /* 0x1C — hash key for shader lookup */
} nummDrawSpriteBase;

/* nummDrawSprite — size PROVEN 0x100 (RequestDraw accesses up to +0xFC)
 * InitializeVertexBuffer sets vb_index=6 at +0x14, offset_info at +0x10.
 * RequestDraw sets request_flag at +0xC, material at +0x20 (param_1[4]).
 * RequestDraw writes color/UV data at +0x1E..+0x1F, +0xF4..+0xFC. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[4];       /* 0x08 */
    uint8_t   request_flag;     /* 0x0C */
    uint8_t   _pad_0d[3];       /* 0x0D */
    uint32_t  offset_info;      /* 0x10 */
    uint32_t  vb_index;         /* 0x14 */
    uint16_t  uv_data_a;        /* 0x18 — param_1+0xe region start */
    uint16_t  uv_data_b;        /* 0x1A */
    uint32_t  shader_hash;      /* 0x1C */
    uint16_t  color_r;          /* 0x20 — actually part of extended sprite data */
    uint16_t  color_g;          /* 0x22 */
    uint16_t  color_b;          /* 0x24 */
    uint16_t  color_a;          /* 0x26 */
    uint8_t   _pad_28[0xD0];    /* 0x28 — extended sprite data up to 0xF8 */
    uint32_t  priority_z_lo;    /* 0xF8 — TransformZToPriorityZ output region */
    uint32_t  priority_z_hi;    /* 0xFC */
} nummDrawSprite;

#pragma pack(pop)

/* ---- static_assert for every field ---- */
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, vtable) == 0x00, "cs.vtable");
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, mmMutex_data) == 0x08, "cs.mmMutex");

_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, vtable) == 0x00, "st.vtable");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, mmThreadImpl) == 0x08, "st.impl");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, flags) == 0x10, "st.flags");

_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, mmThreadCond) == 0x00, "sp.cond");

_Static_assert(offsetof(nuccZSortList, vtable) == 0x00, "zsl.vtable");
_Static_assert(offsetof(nuccZSortList, crit_section) == 0x08, "zsl.cs");
_Static_assert(offsetof(nuccZSortList, sentinel_node) == 0x58, "zsl.sentinel");
_Static_assert(offsetof(nuccZSortList, head) == 0x80, "zsl.head");
_Static_assert(offsetof(nuccZSortList, field_88) == 0x88, "zsl.f88");
_Static_assert(offsetof(nuccZSortList, tail_sentinel) == 0x90, "zsl.tail");
_Static_assert(offsetof(nuccZSortList, end_ptr) == 0xA0, "zsl.end");
_Static_assert(sizeof(nuccZSortList) == 0xA8, "zsl.size");

_Static_assert(offsetof(nuccZCBBox, vtable) == 0x00, "zcb.vtable");
_Static_assert(offsetof(nuccZCBBox, count) == 0x18, "zcb.count");
_Static_assert(offsetof(nuccZCBBox, sort_list_array) == 0x20, "zcb.array");

_Static_assert(offsetof(nuccZSortManager, sort_param) == 0x20, "zsm.param");
_Static_assert(offsetof(nuccZSortManager, sort_list_base) == 0x28, "zsm.base");
_Static_assert(offsetof(nuccZSortManager, sort_index) == 0x30, "zsm.idx");

_Static_assert(offsetof(nummBinaryAccessor, vtable) == 0x00, "ba.vtable");
_Static_assert(offsetof(nummBinaryAccessor, read_func_ptr) == 0x18, "ba.read");

_Static_assert(offsetof(nummBinaryParser, vtable) == 0x00, "bp.vtable");
_Static_assert(offsetof(nummBinaryParser, accum_size) == 0x08, "bp.accum");
_Static_assert(offsetof(nummBinaryParser, dispatch_func) == 0x20, "bp.dispatch");

_Static_assert(offsetof(nummCriticalSection, vtable) == 0x00, "mcs.vtable");
_Static_assert(offsetof(nummCriticalSection, hash_table) == 0x08, "mcs.ht");
_Static_assert(offsetof(nummCriticalSection, bucket_count) == 0x10, "mcs.bc");
_Static_assert(offsetof(nummCriticalSection, lock_count) == 0x14, "mcs.lc");
_Static_assert(offsetof(nummCriticalSection, lock_state) == 0x18, "mcs.ls");

_Static_assert(offsetof(nummDrawSpriteBase, vtable) == 0x00, "dsb.vtable");
_Static_assert(offsetof(nummDrawSpriteBase, draw_flags) == 0x0C, "dsb.flags");
_Static_assert(offsetof(nummDrawSpriteBase, render_resource) == 0x1C, "dsb.res");

_Static_assert(offsetof(nummDrawSprite, vtable) == 0x00, "ds.vtable");
_Static_assert(offsetof(nummDrawSprite, request_flag) == 0x0C, "ds.req");
_Static_assert(offsetof(nummDrawSprite, offset_info) == 0x10, "ds.off");
_Static_assert(offsetof(nummDrawSprite, vb_index) == 0x14, "ds.vbi");
_Static_assert(offsetof(nummDrawSprite, shader_hash) == 0x1C, "ds.shader");
_Static_assert(offsetof(nummDrawSprite, priority_z_hi) == 0xFC, "ds.pzhi");
_Static_assert(sizeof(nummDrawSprite) == 0x100, "ds.size");

#endif /* CMN73_S3_H */