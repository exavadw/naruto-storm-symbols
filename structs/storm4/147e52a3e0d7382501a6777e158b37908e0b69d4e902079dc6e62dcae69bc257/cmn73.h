/*
 * cmn73 s4 — struct layouts for common engine/UI/render/math classes
 * Build: s4 (NSUNS4_release.exe, PC x64, image base 0x140000000)
 * Status: INFERRED from static analysis. Not CONFIRMED at runtime.
 * Own-game names only (Storm 4 symbols/strings).
 */

#ifndef CMN73_S4_H
#define CMN73_S4_H

#include <stdint.h>
#include <stddef.h>

#pragma pack(push, 1)

/* NUMM_THREAD_CRITICAL_SECTION_CONTEXT — size >= 0x10
 * ctor 0x9DC220: calls mmMutex(), sets +8=0.
 * dtor 0x17D240: DeleteCriticalSection(*param_1), frees *param_1. */
typedef struct {
    void     *crit_section_ptr; /* 0x00 — pointer to allocated CRITICAL_SECTION */
    uint8_t   mmMutex_data[8];  /* 0x08 — set to 0 by ctor */
} NUMM_THREAD_CRITICAL_SECTION_CONTEXT;

/* NUMM_THREAD_SIMPLE_THREAD_CONTEXT — size >= 0x14
 * ctor 0x9DC260: calls mmThread_Impl(), sets +0x10=0.
 * dtor 0x9F47C0: CloseHandle(*(HANDLE*)(param_1+8)) if != INVALID_HANDLE_VALUE. */
typedef struct {
    void     *vtable;           /* 0x00 */
    void     *thread_handle;    /* 0x08 — HANDLE, closed by dtor */
    uint32_t  flags;            /* 0x10 — set to 0 by ctor */
} NUMM_THREAD_SIMPLE_THREAD_CONTEXT;

/* NUMM_THREAD_SYNCPOINT_CONTEXT — size >= 0x10 (no vtable, plain data)
 * ctor 0x9DC2A0: calls mmThreadCond(param_1,...). */
typedef struct {
    uint8_t   mmThreadCond[16]; /* 0x00 — ctor calls mmThreadCond directly on this */
} NUMM_THREAD_SYNCPOINT_CONTEXT;

/* nuccZSortList — size PROVEN 0xA8
 * Clear 0xA54040: head at +0x70, sentinel setup at +0x58/+0x80, end at +0xA0.
 * Add 0xA53F40: array element stride 0x28.
 * Sort 0xA54560: node +0x8(float), +0xc(uint), +0x18(next).
 * Embedded nummCriticalSection at +0x08 (Lock dispatch at +8). */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   crit_section[0x50]; /* 0x08 — embedded nummCriticalSection */
    uint8_t   sentinel_node[0x18]; /* 0x58 — ZSortEntry sentinel start */
    void     *head;             /* 0x70 */
    uint64_t  field_78;         /* 0x78 */
    uint8_t   sentinel_ext[0x20]; /* 0x80 — extended sentinel / sort region */
    void     *end_ptr;          /* 0xA0 */
} nuccZSortList;

/* nuccZCBBox — size >= 0x28
 * Init 0xA54310: vtable slots at +8,+0x10; count at param_1[3]=+0x18; array at param_1[4]=+0x20.
 * Del 0xA540B0: checks +0x18, iterates +0x20 stride 0x28.
 * Exit 0xA54190: frees param_1[4], clears param_1[3]. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x10];    /* 0x08 — vtable dispatch slots at +8,+0x10 */
    uint32_t  count;            /* 0x18 */
    uint8_t   _pad_1c[4];       /* 0x1C */
    void     *sort_list_array;  /* 0x20 */
} nuccZCBBox;

/* nuccZSortManager — size >= 0x34
 * Init 0xA543C0: vtable +8,+0x10; array at param_1[5]=+0x28; count at +0x1c; stride 0xa8.
 * ActiveListSort 0xA53F20: reads +0x30 (index), +0x28 (base), +0x20 (sort arg). */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x14];    /* 0x08 */
    uint32_t  count;            /* 0x1C */
    uint32_t  sort_param;       /* 0x20 */
    uint8_t   _pad_24[4];       /* 0x24 */
    void     *sort_list_base;   /* 0x28 */
    uint32_t  sort_index;       /* 0x30 */
} nuccZSortManager;

/* nummBinaryAccessor — size >= 0x90
 * ReadBinary 0x8EE0B0: dispatches vfunc at *param_1+0x88. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[0x80];    /* 0x08 */
    void     *read_func_ptr;    /* 0x88 — dispatch slot used by ReadBinary */
} nummBinaryAccessor;

/* nummBinaryParser — size >= 0x28
 * GetBinarySize 0x9F51B0: dispatches vfunc at *param_1+0x20. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint64_t  accum_size;       /* 0x08 */
    uint8_t   _pad_10[0x10];    /* 0x10 */
    void     *dispatch_func;    /* 0x20 */
} nummBinaryParser;

/* nummCriticalSection — size >= 0x54
 * Lock 0x9E0720: writes lock_state at +0x20.
 * Unlock 0x9EC6B0: reads hash_table at +0x08, bucket_count at +0x10, lock_count at +0x14.
 * ChangeGlobalIndex accesses embedded shader_mgr at +0x24 size 0x30. */
typedef struct {
    void     *vtable;           /* 0x00 */
    void     *hash_table;       /* 0x08 */
    uint32_t  bucket_count;     /* 0x10 */
    uint32_t  lock_count;       /* 0x14 */
    uint8_t   _pad_18[8];       /* 0x18 */
    uint32_t  lock_state;       /* 0x20 — written by Lock */
    uint8_t   shader_mgr[0x30]; /* 0x24 — ChangeGlobalIndex target */
} nummCriticalSection;

/* nummDrawSpriteBase — size >= 0x24
 * Draw 0x9EFD00: checks draw_flags bit 0x4000 at +0xC (param_1+3 as uint*).
 * Draw reads render_resource hash key at +0x1C.
 * Vtable dispatches at +0, +8, +0x10. */
typedef struct {
    void     *vtable;           /* 0x00 */
    uint8_t   _pad_08[4];       /* 0x08 */
    uint32_t  draw_flags;       /* 0x0C */
    uint8_t   _pad_10[0xC];     /* 0x10 */
    uint32_t  render_resource;  /* 0x1C — hash key for shader lookup */
} nummDrawSpriteBase;

/* nummDrawSprite — size PROVEN 0x100 (RequestDraw accesses up to +0xFC)
 * InitializeVertexBuffer 0x9F0F40: sets vb_index=6 at +0x14, offset_info at +0x10.
 * RequestDraw 0x9F1170: sets flags at +0xC (param_1[3]), material at +0x20 (param_1[4]).
 * RequestDraw writes color/UV data at +0x1E..+0x1F, +0xF4..+0xFC.
 * Draw 0x9EFD00: reads param_1[0x16..0x1b] as vertex data pairs. */
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
    uint16_t  color_r;          /* 0x20 */
    uint16_t  color_g;          /* 0x22 */
    uint16_t  color_b;          /* 0x24 */
    uint16_t  color_a;          /* 0x26 */
    uint8_t   _pad_28[0xD0];    /* 0x28 — extended sprite data up to 0xF8 */
    uint32_t  priority_z_lo;    /* 0xF8 — TransformZToPriorityZ output region */
    uint32_t  priority_z_hi;    /* 0xFC */
} nummDrawSprite;

#pragma pack(pop)

/* ---- static_assert for every field ---- */
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, crit_section_ptr) == 0x00, "cs.ptr");
_Static_assert(offsetof(NUMM_THREAD_CRITICAL_SECTION_CONTEXT, mmMutex_data) == 0x08, "cs.mmMutex");

_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, vtable) == 0x00, "st.vtable");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, thread_handle) == 0x08, "st.handle");
_Static_assert(offsetof(NUMM_THREAD_SIMPLE_THREAD_CONTEXT, flags) == 0x10, "st.flags");

_Static_assert(offsetof(NUMM_THREAD_SYNCPOINT_CONTEXT, mmThreadCond) == 0x00, "sp.cond");

_Static_assert(offsetof(nuccZSortList, vtable) == 0x00, "zsl.vtable");
_Static_assert(offsetof(nuccZSortList, crit_section) == 0x08, "zsl.cs");
_Static_assert(offsetof(nuccZSortList, sentinel_node) == 0x58, "zsl.sentinel");
_Static_assert(offsetof(nuccZSortList, head) == 0x70, "zsl.head");
_Static_assert(offsetof(nuccZSortList, field_78) == 0x78, "zsl.f78");
_Static_assert(offsetof(nuccZSortList, sentinel_ext) == 0x80, "zsl.sentext");
_Static_assert(offsetof(nuccZSortList, end_ptr) == 0xA0, "zsl.end");
_Static_assert(sizeof(nuccZSortList) == 0xA8, "zsl.size");

_Static_assert(offsetof(nuccZCBBox, vtable) == 0x00, "zcb.vtable");
_Static_assert(offsetof(nuccZCBBox, count) == 0x18, "zcb.count");
_Static_assert(offsetof(nuccZCBBox, sort_list_array) == 0x20, "zcb.array");

_Static_assert(offsetof(nuccZSortManager, count) == 0x1C, "zsm.count");
_Static_assert(offsetof(nuccZSortManager, sort_param) == 0x20, "zsm.param");
_Static_assert(offsetof(nuccZSortManager, sort_list_base) == 0x28, "zsm.base");
_Static_assert(offsetof(nuccZSortManager, sort_index) == 0x30, "zsm.idx");

_Static_assert(offsetof(nummBinaryAccessor, vtable) == 0x00, "ba.vtable");
_Static_assert(offsetof(nummBinaryAccessor, read_func_ptr) == 0x88, "ba.read");

_Static_assert(offsetof(nummBinaryParser, vtable) == 0x00, "bp.vtable");
_Static_assert(offsetof(nummBinaryParser, accum_size) == 0x08, "bp.accum");
_Static_assert(offsetof(nummBinaryParser, dispatch_func) == 0x20, "bp.dispatch");

_Static_assert(offsetof(nummCriticalSection, vtable) == 0x00, "mcs.vtable");
_Static_assert(offsetof(nummCriticalSection, hash_table) == 0x08, "mcs.ht");
_Static_assert(offsetof(nummCriticalSection, bucket_count) == 0x10, "mcs.bc");
_Static_assert(offsetof(nummCriticalSection, lock_count) == 0x14, "mcs.lc");
_Static_assert(offsetof(nummCriticalSection, lock_state) == 0x20, "mcs.ls");

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

#endif /* CMN73_S4_H */