/*
 * cmn73 s2 — struct layouts for common engine/UI/render/math classes
 * Build: s2 (NSUNS2.exe, PC x64, image base 0x140000000)
 * Status: INFERRED from static analysis. Not CONFIRMED at runtime.
 * Own-game names only (ns2:: / Storm 2 strings).
 */

#ifndef CMN73_S2_H
#define CMN73_S2_H

#include <stdint.h>
#include <stddef.h>

#pragma pack(push, 1)

/* NUMM_THREAD_CRITICAL_SECTION_CONTEXT — size >= 0x10 */
typedef struct {
    void    *vtable;        /* 0x00 */
    uint8_t  mmMutex_data[8]; /* 0x08 */
} NUMM_THREAD_CRITICAL_SECTION_CONTEXT;

/* NUMM_THREAD_SIMPLE_THREAD_CONTEXT — size >= 0x60 */
typedef struct {
    void     *vtable;          /* 0x00 */
    uint8_t   mmThreadImpl[8]; /* 0x08 */
    uint32_t  flags;           /* 0x10 */
    uint8_t   _pad_14[4];      /* 0x14 */
    uint8_t   thread_impl_ext[0x44]; /* 0x18 */
    uint32_t  thread_state;    /* 0x5C */
} NUMM_THREAD_SIMPLE_THREAD_CONTEXT;

/* NUMM_THREAD_SYNCPOINT_CONTEXT — size >= 0x20 */
typedef struct {
    void    *syncpoint_ptr;  /* 0x00 */
    void    *back_ptr;       /* 0x08 */
    uint8_t  mmThreadCond[8]; /* 0x10 */
    uint8_t  block_alloc[8];  /* 0x18 */
} NUMM_THREAD_SYNCPOINT_CONTEXT;

/* nuccZSortList — size PROVEN 0xA8 */
typedef struct {
    void     *vtable;            /* 0x00 */
    uint8_t   crit_section[0x50]; /* 0x08 */
    uint8_t   sentinel_node[0x28]; /* 0x58 */
    void     *head;              /* 0x80 */
    uint64_t  field_88;          /* 0x88 */
    void     *tail_sentinel;     /* 0x90 */
    uint8_t   _pad_98[8];        /* 0x98 */
    void     *end_ptr;           /* 0xA0 */
} nuccZSortList;

/* nuccZCBBox — size >= 0x28 */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x10];    /* 0x08 */
    uint32_t  count;            /* 0x18 */
    uint8_t   _pad_1c[4];       /* 0x1C */
    void     *sort_list_array;  /* 0x20 */
} nuccZCBBox;

/* nummBinaryAccessor — size >= 0x20 */
typedef struct {
    void    *vtable;         /* 0x00 */
    uint8_t  _pad_08[0x10];  /* 0x08 */
    void    *read_func_ptr;  /* 0x18 */
} nummBinaryAccessor;

/* nummBinaryParser — size >= 0x28 */
typedef struct {
    void     *vtable;        /* 0x00 */
    uint64_t  accum_size;    /* 0x08 */
    uint8_t   _pad_10[0x10]; /* 0x10 */
    void     *dispatch_func; /* 0x20 */
} nummBinaryParser;

/* nummCriticalSection — size >= 0x28 */
typedef struct {
    void     *vtable;       /* 0x00 */
    void     *hash_table;   /* 0x08 */
    uint64_t  bucket_count; /* 0x10 */
    uint32_t  lock_count;   /* 0x18 */
    uint8_t   _pad_1c[4];   /* 0x1C */
    uint32_t  lock_state;   /* 0x20 */
} nummCriticalSection;

/* nummDrawSpriteBase — size >= 0x20 */
typedef struct {
    void     *vtable;          /* 0x00 */
    uint8_t   _pad_08[4];      /* 0x08 */
    uint32_t  draw_flags;      /* 0x0C */
    uint8_t   _pad_10[0xC];    /* 0x10 */
    void     *render_resource; /* 0x1C */
} nummDrawSpriteBase;

/* nummDrawSprite — size PROVEN 0x78 */
typedef struct {
    void     *vtable;        /* 0x00 */
    uint8_t   _pad_08[4];    /* 0x08 */
    uint8_t   request_flag;  /* 0x0C */
    uint8_t   _pad_0d[3];    /* 0x0D */
    void     *offset_info;   /* 0x10 */
    uint32_t  vb_index;      /* 0x18 */
    uint8_t   _pad_1c[4];    /* 0x1C */
    void     *material;      /* 0x20 */
    uint8_t   _pad_28[0x50]; /* 0x28 */
} nummDrawSprite;

#pragma pack(pop)

/* ---- static_assert for every field ---- */
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, vtable) == 0x00, "cs.vtable");
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, mmMutex_data) == 0x08, "cs.mmMutex");

_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, vtable) == 0x00, "st.vtable");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, mmThreadImpl) == 0x08, "st.impl");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, flags) == 0x10, "st.flags");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, thread_state) == 0x5C, "st.state");

_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, syncpoint_ptr) == 0x00, "sp.ptr");
_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, back_ptr) == 0x08, "sp.back");
_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, mmThreadCond) == 0x10, "sp.cond");
_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, block_alloc) == 0x18, "sp.alloc");

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

_Static_assert(offsetof(nummBinaryAccessor, vtable) == 0x00, "ba.vtable");
_Static_assert(offsetof(nummBinaryAccessor, read_func_ptr) == 0x18, "ba.read");

_Static_assert(offsetof(nummBinaryParser, vtable) == 0x00, "bp.vtable");
_Static_assert(offsetof(nummBinaryParser, accum_size) == 0x08, "bp.accum");
_Static_assert(offsetof(nummBinaryParser, dispatch_func) == 0x20, "bp.dispatch");

_Static_assert(offsetof(nummCriticalSection, vtable) == 0x00, "mcs.vtable");
_Static_assert(offsetof(nummCriticalSection, hash_table) == 0x08, "mcs.ht");
_Static_assert(offsetof(nummCriticalSection, bucket_count) == 0x10, "mcs.bc");
_Static_assert(offsetof(nummCriticalSection, lock_count) == 0x18, "mcs.lc");
_Static_assert(offsetof(nummCriticalSection, lock_state) == 0x20, "mcs.ls");

_Static_assert(offsetof(nummDrawSpriteBase, vtable) == 0x00, "dsb.vtable");
_Static_assert(offsetof(nummDrawSpriteBase, draw_flags) == 0x0C, "dsb.flags");
_Static_assert(offsetof(nummDrawSpriteBase, render_resource) == 0x1C, "dsb.res");

_Static_assert(offsetof(nummDrawSprite, vtable) == 0x00, "ds.vtable");
_Static_assert(offsetof(nummDrawSprite, request_flag) == 0x0C, "ds.req");
_Static_assert(offsetof(nummDrawSprite, offset_info) == 0x10, "ds.off");
_Static_assert(offsetof(nummDrawSprite, vb_index) == 0x18, "ds.vbi");
_Static_assert(offsetof(nummDrawSprite, material) == 0x20, "ds.mat");
_Static_assert(sizeof(nummDrawSprite) == 0x78, "ds.size");

#endif /* CMN73_S2_H */