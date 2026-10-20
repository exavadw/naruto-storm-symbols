/*
 * libDlmalloc.h - Storm 3 (NSUNS3.exe) dlmalloc struct layouts
 *
 * Reconstructed from public dlmalloc 2.8.6 source and verified against
 * s3 decompiled code (dlmalloc RVA 0x72D450, mspace_malloc RVA 0x72C4E0).
 * All offsets confirmed via offsetof under x86_64 MSVC ABI.
 *
 * Compile options inferred from binary: MSPACES=1, USE_LOCKS=1,
 * MALLOC_ALIGNMENT=16, FOOTERS=0, INSECURE=0.
 *
 * This is a library header: no game-specific instance state beyond the
 * standard dlmalloc structs. All fields are SIM (heap allocator state
 * that must be snapshotted for rollback determinism).
 */
#ifndef LIBDLMALLOC_H
#define LIBDLMALLOC_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef uint32_t binmap_t;
typedef uint32_t bindex_t;
typedef uint32_t flag_t;

#define NSMALLBINS 32U
#define NTREEBINS  32U

/* malloc_chunk: free chunk in small bins or dv */
struct malloc_chunk {
    size_t prev_foot;           /* 0x000 */
    size_t head;                /* 0x008 */
    struct malloc_chunk *fd;    /* 0x010 */
    struct malloc_chunk *bk;    /* 0x018 */
};
static_assert(sizeof(struct malloc_chunk) == 32, "malloc_chunk size");
static_assert(offsetof(struct malloc_chunk, prev_foot) == 0x000, "malloc_chunk.prev_foot");
static_assert(offsetof(struct malloc_chunk, head) == 0x008, "malloc_chunk.head");
static_assert(offsetof(struct malloc_chunk, fd) == 0x010, "malloc_chunk.fd");
static_assert(offsetof(struct malloc_chunk, bk) == 0x018, "malloc_chunk.bk");

/* malloc_tree_chunk: free chunk in tree bins */
struct malloc_tree_chunk {
    size_t prev_foot;               /* 0x000 */
    size_t head;                    /* 0x008 */
    struct malloc_tree_chunk *fd;   /* 0x010 */
    struct malloc_tree_chunk *bk;   /* 0x018 */
    struct malloc_tree_chunk *child[2]; /* 0x020 */
    struct malloc_tree_chunk *parent;   /* 0x030 */
    bindex_t index;                 /* 0x038 */
    uint8_t _pad_index[4];          /* 0x03C padding to 64 */
};
static_assert(sizeof(struct malloc_tree_chunk) == 64, "malloc_tree_chunk size");
static_assert(offsetof(struct malloc_tree_chunk, prev_foot) == 0x000, "malloc_tree_chunk.prev_foot");
static_assert(offsetof(struct malloc_tree_chunk, head) == 0x008, "malloc_tree_chunk.head");
static_assert(offsetof(struct malloc_tree_chunk, fd) == 0x010, "malloc_tree_chunk.fd");
static_assert(offsetof(struct malloc_tree_chunk, bk) == 0x018, "malloc_tree_chunk.bk");
static_assert(offsetof(struct malloc_tree_chunk, child) == 0x020, "malloc_tree_chunk.child");
static_assert(offsetof(struct malloc_tree_chunk, parent) == 0x030, "malloc_tree_chunk.parent");
static_assert(offsetof(struct malloc_tree_chunk, index) == 0x038, "malloc_tree_chunk.index");

/* malloc_segment: linked list of mmap/VirtualAlloc segments */
struct malloc_segment {
    char *base;                     /* 0x000 */
    size_t size;                    /* 0x008 */
    struct malloc_segment *next;    /* 0x010 */
    flag_t sflags;                  /* 0x018 */
    uint8_t _pad_sflags[4];         /* 0x01C padding to 32 */
};
static_assert(sizeof(struct malloc_segment) == 32, "malloc_segment size");
static_assert(offsetof(struct malloc_segment, base) == 0x000, "malloc_segment.base");
static_assert(offsetof(struct malloc_segment, size) == 0x008, "malloc_segment.size");
static_assert(offsetof(struct malloc_segment, next) == 0x010, "malloc_segment.next");
static_assert(offsetof(struct malloc_segment, sflags) == 0x018, "malloc_segment.sflags");

/* malloc_params: global tunable parameters (_gm_ / mparams) */
struct malloc_params {
    size_t magic;                   /* 0x000 */
    size_t page_size;               /* 0x008 */
    size_t granularity;             /* 0x010 */
    size_t mmap_threshold;          /* 0x018 */
    size_t trim_threshold;          /* 0x020 */
    flag_t default_mflags;          /* 0x028 */
    uint8_t _pad_default_mflags[4]; /* 0x02C padding to 48 */
};
static_assert(sizeof(struct malloc_params) == 48, "malloc_params size");
static_assert(offsetof(struct malloc_params, magic) == 0x000, "malloc_params.magic");
static_assert(offsetof(struct malloc_params, page_size) == 0x008, "malloc_params.page_size");
static_assert(offsetof(struct malloc_params, granularity) == 0x010, "malloc_params.granularity");
static_assert(offsetof(struct malloc_params, mmap_threshold) == 0x018, "malloc_params.mmap_threshold");
static_assert(offsetof(struct malloc_params, trim_threshold) == 0x020, "malloc_params.trim_threshold");
static_assert(offsetof(struct malloc_params, default_mflags) == 0x028, "malloc_params.default_mflags");

/* malloc_state (mstate): per-mspace allocator state */
struct malloc_state {
    binmap_t smallmap;                          /* 0x000 */
    binmap_t treemap;                           /* 0x004 */
    size_t dvsize;                              /* 0x008 */
    size_t topsize;                             /* 0x010 */
    char *least_addr;                           /* 0x018 */
    struct malloc_chunk *dv;                    /* 0x020 */
    struct malloc_chunk *top;                   /* 0x028 */
    size_t trim_check;                          /* 0x030 */
    size_t release_checks;                      /* 0x038 */
    size_t magic;                               /* 0x040 */
    struct malloc_chunk *smallbins[(NSMALLBINS+1)*2]; /* 0x048 */
    struct malloc_tree_chunk *treebins[NTREEBINS];     /* 0x258 */
    size_t footprint;                           /* 0x358 */
    size_t max_footprint;                       /* 0x360 */
    size_t footprint_limit;                     /* 0x368 */
    flag_t mflags;                              /* 0x370 */
    volatile int mutex;                         /* 0x374 */
    struct malloc_segment seg;                  /* 0x378 */
    void *extp;                                 /* 0x398 */
    size_t exts;                                /* 0x3A0 */
};
static_assert(sizeof(struct malloc_state) == 936, "malloc_state size");
static_assert(offsetof(struct malloc_state, smallmap) == 0x000, "malloc_state.smallmap");
static_assert(offsetof(struct malloc_state, treemap) == 0x004, "malloc_state.treemap");
static_assert(offsetof(struct malloc_state, dvsize) == 0x008, "malloc_state.dvsize");
static_assert(offsetof(struct malloc_state, topsize) == 0x010, "malloc_state.topsize");
static_assert(offsetof(struct malloc_state, least_addr) == 0x018, "malloc_state.least_addr");
static_assert(offsetof(struct malloc_state, dv) == 0x020, "malloc_state.dv");
static_assert(offsetof(struct malloc_state, top) == 0x028, "malloc_state.top");
static_assert(offsetof(struct malloc_state, trim_check) == 0x030, "malloc_state.trim_check");
static_assert(offsetof(struct malloc_state, release_checks) == 0x038, "malloc_state.release_checks");
static_assert(offsetof(struct malloc_state, magic) == 0x040, "malloc_state.magic");
static_assert(offsetof(struct malloc_state, smallbins) == 0x048, "malloc_state.smallbins");
static_assert(offsetof(struct malloc_state, treebins) == 0x258, "malloc_state.treebins");
static_assert(offsetof(struct malloc_state, footprint) == 0x358, "malloc_state.footprint");
static_assert(offsetof(struct malloc_state, max_footprint) == 0x360, "malloc_state.max_footprint");
static_assert(offsetof(struct malloc_state, footprint_limit) == 0x368, "malloc_state.footprint_limit");
static_assert(offsetof(struct malloc_state, mflags) == 0x370, "malloc_state.mflags");
static_assert(offsetof(struct malloc_state, mutex) == 0x374, "malloc_state.mutex");
static_assert(offsetof(struct malloc_state, seg) == 0x378, "malloc_state.seg");
static_assert(offsetof(struct malloc_state, extp) == 0x398, "malloc_state.extp");
static_assert(offsetof(struct malloc_state, exts) == 0x3A0, "malloc_state.exts");

#endif /* LIBDLMALLOC_H */