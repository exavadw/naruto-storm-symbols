/*
 * libDlmalloc — NARUTO STORM 1 (NSUNS1.exe, build s1)
 *
 * dlmalloc 2.8.x (Doug Lea malloc), statically linked into NSUNS1.exe.
 * Global allocator state at gm_ (RVA 0x8DA210, .data section).
 *
 * Layout derived from public dlmalloc 2.8.x source compiled with MSVC x64
 * ABI. Verified against binary bytes at RVA 0x8DA210 using PE section
 * mapping (.data VA=0x7CB000, RawOff=0x7C9800 -> file offset 0x8D8A10).
 * Compile options inferred: USE_LOCKS=1 (mutex field present at +0x374),
 * FOOTERS=0, MSPACES=1, MALLOC_ALIGNMENT=16, DEFAULT_GRANULARITY=64KB.
 *
 * Build:    s1 (NSUNS1.exe)
 * SHA256:   10231093af9cbda329d5cf3b7ba5a146ad523799331f52c3c3929b785d7f63ba
 * Source:   dlmalloc 2.8.x public domain (gee.cs.oswego.edu/pub/misc/)
 * Status:   INFERRED (static analysis + PE byte verification)
 */

#ifndef LIB_DLMALLOC_S1_H
#define LIB_DLMALLOC_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * Bin map types from dlmalloc 2.8.x.
 */
typedef uint32_t binmap_t;
typedef uint32_t bindex_t;
typedef uint32_t flag_t;

#define DLMALLOC_NSMALLBINS 32U
#define DLMALLOC_NTREEBINS  32U

/*
 * malloc_chunk — basic free chunk header (32 bytes on x64).
 * Verified: sizeof=32, prev_foot=0, head=8, fd=16, bk=24.
 */
struct __attribute__((packed)) dlmalloc_chunk {
    size_t              prev_foot;  /* 0x00 */
    size_t              head;       /* 0x08 */
    struct dlmalloc_chunk *fd;      /* 0x10 */
    struct dlmalloc_chunk *bk;      /* 0x18 */
};

static_assert(offsetof(struct dlmalloc_chunk, prev_foot) == 0x00, "dlmalloc_chunk.prev_foot");
static_assert(offsetof(struct dlmalloc_chunk, head)      == 0x08, "dlmalloc_chunk.head");
static_assert(offsetof(struct dlmalloc_chunk, fd)        == 0x10, "dlmalloc_chunk.fd");
static_assert(offsetof(struct dlmalloc_chunk, bk)        == 0x18, "dlmalloc_chunk.bk");
static_assert(sizeof(struct dlmalloc_chunk)              == 0x20, "dlmalloc_chunk size");

/*
 * malloc_tree_chunk — large-bin tree node (64 bytes on x64).
 * Verified: sizeof=64, child=32, parent=48, index=56.
 */
struct __attribute__((packed)) dlmalloc_tree_chunk {
    size_t                    prev_foot;  /* 0x00 */
    size_t                    head;       /* 0x08 */
    struct dlmalloc_tree_chunk *fd;       /* 0x10 */
    struct dlmalloc_tree_chunk *bk;       /* 0x18 */
    struct dlmalloc_tree_chunk *child[2]; /* 0x20 */
    struct dlmalloc_tree_chunk *parent;   /* 0x30 */
    bindex_t                  index;      /* 0x38 */
    uint8_t                   _pad[4];    /* 0x3C */
};

static_assert(offsetof(struct dlmalloc_tree_chunk, prev_foot) == 0x00, "dlmalloc_tree_chunk.prev_foot");
static_assert(offsetof(struct dlmalloc_tree_chunk, head)      == 0x08, "dlmalloc_tree_chunk.head");
static_assert(offsetof(struct dlmalloc_tree_chunk, fd)        == 0x10, "dlmalloc_tree_chunk.fd");
static_assert(offsetof(struct dlmalloc_tree_chunk, bk)        == 0x18, "dlmalloc_tree_chunk.bk");
static_assert(offsetof(struct dlmalloc_tree_chunk, child)     == 0x20, "dlmalloc_tree_chunk.child");
static_assert(offsetof(struct dlmalloc_tree_chunk, parent)    == 0x30, "dlmalloc_tree_chunk.parent");
static_assert(offsetof(struct dlmalloc_tree_chunk, index)     == 0x38, "dlmalloc_tree_chunk.index");
static_assert(sizeof(struct dlmalloc_tree_chunk)              == 0x40, "dlmalloc_tree_chunk size");

/*
 * malloc_segment — memory segment descriptor (32 bytes on x64).
 * Verified: sizeof=32, base=0, size=8, next=16, sflags=24.
 */
struct __attribute__((packed)) dlmalloc_segment {
    char                     *base;   /* 0x00 */
    size_t                    size;   /* 0x08 */
    struct dlmalloc_segment  *next;   /* 0x10 */
    flag_t                    sflags; /* 0x18 */
    uint8_t                   _pad[4]; /* 0x1C */
};

static_assert(offsetof(struct dlmalloc_segment, base)   == 0x00, "dlmalloc_segment.base");
static_assert(offsetof(struct dlmalloc_segment, size)   == 0x08, "dlmalloc_segment.size");
static_assert(offsetof(struct dlmalloc_segment, next)   == 0x10, "dlmalloc_segment.next");
static_assert(offsetof(struct dlmalloc_segment, sflags) == 0x18, "dlmalloc_segment.sflags");
static_assert(sizeof(struct dlmalloc_segment)           == 0x20, "dlmalloc_segment size");

/*
 * malloc_params — global allocator parameters (48 bytes on x64).
 * Verified: sizeof=48, magic=0, page_size=8, granularity=16,
 *           mmap_threshold=24, trim_threshold=32, default_mflags=40.
 */
struct __attribute__((packed)) dlmalloc_params {
    size_t magic;           /* 0x00 */
    size_t page_size;       /* 0x08 */
    size_t granularity;     /* 0x10 */
    size_t mmap_threshold;  /* 0x18 */
    size_t trim_threshold;  /* 0x20 */
    flag_t default_mflags;  /* 0x28 */
    uint8_t _pad[4];        /* 0x2C */
};

static_assert(offsetof(struct dlmalloc_params, magic)           == 0x00, "dlmalloc_params.magic");
static_assert(offsetof(struct dlmalloc_params, page_size)       == 0x08, "dlmalloc_params.page_size");
static_assert(offsetof(struct dlmalloc_params, granularity)     == 0x10, "dlmalloc_params.granularity");
static_assert(offsetof(struct dlmalloc_params, mmap_threshold)  == 0x18, "dlmalloc_params.mmap_threshold");
static_assert(offsetof(struct dlmalloc_params, trim_threshold)  == 0x20, "dlmalloc_params.trim_threshold");
static_assert(offsetof(struct dlmalloc_params, default_mflags)  == 0x28, "dlmalloc_params.default_mflags");
static_assert(sizeof(struct dlmalloc_params)                    == 0x30, "dlmalloc_params size");

/*
 * malloc_state (mstate) — per-arena allocator state (936 bytes on x64).
 *
 * Global instance gm_ at RVA 0x8DA210 in NSUNS1.exe .data section.
 * Layout verified against PE bytes: footprint_limit present at +0x368,
 * mflags at +0x370, mutex (USE_LOCKS) at +0x374, seg at +0x378.
 *
 * Verified offsets (GCC ms_struct, matching MSVC x64 ABI):
 *   smallmap=0, treemap=4, dvsize=8, topsize=16, least_addr=24,
 *   dv=32, top=40, trim_check=48, release_checks=56, magic=64,
 *   smallbins=72 (66 entries * 8 = 528), treebins=600 (32 * 8 = 256),
 *   footprint=856, max_footprint=864, footprint_limit=872, mflags=880,
 *   seg=888, extp=920, exts=928. sizeof=936.
 */
struct __attribute__((packed)) dlmalloc_state {
    binmap_t                smallmap;                           /* 0x000 */
    binmap_t                treemap;                            /* 0x004 */
    size_t                  dvsize;                             /* 0x008 */
    size_t                  topsize;                            /* 0x010 */
    char                   *least_addr;                         /* 0x018 */
    struct dlmalloc_chunk  *dv;                                 /* 0x020 */
    struct dlmalloc_chunk  *top;                                /* 0x028 */
    size_t                  trim_check;                         /* 0x030 */
    size_t                  release_checks;                     /* 0x038 */
    size_t                  magic;                              /* 0x040 */
    struct dlmalloc_chunk  *smallbins[(DLMALLOC_NSMALLBINS+1)*2]; /* 0x048 (66 ptrs = 528 bytes) */
    struct dlmalloc_tree_chunk *treebins[DLMALLOC_NTREEBINS];   /* 0x258 (32 ptrs = 256 bytes) */
    size_t                  footprint;                          /* 0x358 */
    size_t                  max_footprint;                      /* 0x360 */
    size_t                  footprint_limit;                    /* 0x368 */
    flag_t                  mflags;                             /* 0x370 */
    volatile int            mutex;                              /* 0x374 (USE_LOCKS=1) */
    struct dlmalloc_segment seg;                                /* 0x378 */
    void                   *extp;                               /* 0x398 */
    size_t                  exts;                               /* 0x3A0 */
};

static_assert(offsetof(struct dlmalloc_state, smallmap)         == 0x000, "dlmalloc_state.smallmap");
static_assert(offsetof(struct dlmalloc_state, treemap)          == 0x004, "dlmalloc_state.treemap");
static_assert(offsetof(struct dlmalloc_state, dvsize)           == 0x008, "dlmalloc_state.dvsize");
static_assert(offsetof(struct dlmalloc_state, topsize)          == 0x010, "dlmalloc_state.topsize");
static_assert(offsetof(struct dlmalloc_state, least_addr)       == 0x018, "dlmalloc_state.least_addr");
static_assert(offsetof(struct dlmalloc_state, dv)               == 0x020, "dlmalloc_state.dv");
static_assert(offsetof(struct dlmalloc_state, top)              == 0x028, "dlmalloc_state.top");
static_assert(offsetof(struct dlmalloc_state, trim_check)       == 0x030, "dlmalloc_state.trim_check");
static_assert(offsetof(struct dlmalloc_state, release_checks)   == 0x038, "dlmalloc_state.release_checks");
static_assert(offsetof(struct dlmalloc_state, magic)            == 0x040, "dlmalloc_state.magic");
static_assert(offsetof(struct dlmalloc_state, smallbins)        == 0x048, "dlmalloc_state.smallbins");
static_assert(offsetof(struct dlmalloc_state, treebins)         == 0x258, "dlmalloc_state.treebins");
static_assert(offsetof(struct dlmalloc_state, footprint)        == 0x358, "dlmalloc_state.footprint");
static_assert(offsetof(struct dlmalloc_state, max_footprint)    == 0x360, "dlmalloc_state.max_footprint");
static_assert(offsetof(struct dlmalloc_state, footprint_limit)  == 0x368, "dlmalloc_state.footprint_limit");
static_assert(offsetof(struct dlmalloc_state, mflags)           == 0x370, "dlmalloc_state.mflags");
static_assert(offsetof(struct dlmalloc_state, mutex)            == 0x374, "dlmalloc_state.mutex");
static_assert(offsetof(struct dlmalloc_state, seg)              == 0x378, "dlmalloc_state.seg");
static_assert(offsetof(struct dlmalloc_state, extp)             == 0x398, "dlmalloc_state.extp");
static_assert(offsetof(struct dlmalloc_state, exts)             == 0x3A0, "dlmalloc_state.exts");
static_assert(sizeof(struct dlmalloc_state)                     == 0x3A8, "dlmalloc_state size");

#endif /* LIB_DLMALLOC_S1_H */