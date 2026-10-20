/*
 * libDlmalloc.h - Storm 4 (NSUNS4_release.exe 1.09) dlmalloc struct layouts
 *
 * Reconstructed from public dlmalloc 2.8.x source and verified against
 * s4 decompiled code. Layout differs from canonical/s3: max_footprint and
 * footprint_limit fields are absent (16 bytes removed), shifting mflags
 * to 0x360 and mutex to 0x364. Total malloc_state size = 920 (0x398).
 *
 * _gm_ base: DAT_1416bc910 (VA 0x1416bc910)
 * Compile options inferred: MSPACES=1, USE_LOCKS=1, MALLOC_ALIGNMENT=16,
 * FOOTERS=0, INSECURE=0, NO_MAX_FOOTPRINT=1 (custom CC2 modification).
 */
#ifndef LIBDLMALLOC_S4_H
#define LIBDLMALLOC_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef uint32_t binmap_t;
typedef uint32_t bindex_t;
typedef uint32_t flag_t;

#define NSMALLBINS 32U
#define NTREEBINS  32U

struct malloc_chunk {
    size_t prev_foot;           /* 0x000 */
    size_t head;                /* 0x008 */
    struct malloc_chunk *fd;    /* 0x010 */
    struct malloc_chunk *bk;    /* 0x018 */
};
static_assert(sizeof(struct malloc_chunk) == 32, "malloc_chunk size");
static_assert(offsetof(struct malloc_chunk, prev_foot) == 0x000, "malloc_chunk.prev_foot");
static_assert(offsetof(struct malloc_chunk, head)      == 0x008, "malloc_chunk.head");
static_assert(offsetof(struct malloc_chunk, fd)         == 0x010, "malloc_chunk.fd");
static_assert(offsetof(struct malloc_chunk, bk)         == 0x018, "malloc_chunk.bk");

struct malloc_tree_chunk {
    size_t prev_foot;                   /* 0x000 */
    size_t head;                        /* 0x008 */
    struct malloc_tree_chunk *fd;       /* 0x010 */
    struct malloc_tree_chunk *bk;       /* 0x018 */
    struct malloc_tree_chunk *child[2]; /* 0x020 */
    struct malloc_tree_chunk *parent;   /* 0x030 */
    bindex_t index;                     /* 0x038 */
    uint8_t _pad_index[4];              /* 0x03C */
};
static_assert(sizeof(struct malloc_tree_chunk) == 64, "malloc_tree_chunk size");
static_assert(offsetof(struct malloc_tree_chunk, prev_foot) == 0x000, "tree.prev_foot");
static_assert(offsetof(struct malloc_tree_chunk, head)      == 0x008, "tree.head");
static_assert(offsetof(struct malloc_tree_chunk, fd)        == 0x010, "tree.fd");
static_assert(offsetof(struct malloc_tree_chunk, bk)        == 0x018, "tree.bk");
static_assert(offsetof(struct malloc_tree_chunk, child)     == 0x020, "tree.child");
static_assert(offsetof(struct malloc_tree_chunk, parent)    == 0x030, "tree.parent");
static_assert(offsetof(struct malloc_tree_chunk, index)     == 0x038, "tree.index");

struct malloc_segment {
    char *base;                     /* 0x000 */
    size_t size;                    /* 0x008 */
    struct malloc_segment *next;    /* 0x010 */
    flag_t sflags;                  /* 0x018 */
    uint8_t _pad_sflags[4];         /* 0x01C */
};
static_assert(sizeof(struct malloc_segment) == 32, "malloc_segment size");
static_assert(offsetof(struct malloc_segment, base)   == 0x000, "seg.base");
static_assert(offsetof(struct malloc_segment, size)   == 0x008, "seg.size");
static_assert(offsetof(struct malloc_segment, next)   == 0x010, "seg.next");
static_assert(offsetof(struct malloc_segment, sflags) == 0x018, "seg.sflags");

struct malloc_params {
    size_t magic;                   /* 0x000 */
    size_t page_size;               /* 0x008 */
    size_t granularity;             /* 0x010 */
    size_t mmap_threshold;          /* 0x018 */
    size_t trim_threshold;          /* 0x020 */
    flag_t default_mflags;          /* 0x028 */
    uint8_t _pad_default_mflags[4]; /* 0x02C */
};
static_assert(sizeof(struct malloc_params) == 48, "malloc_params size");
static_assert(offsetof(struct malloc_params, magic)           == 0x000, "params.magic");
static_assert(offsetof(struct malloc_params, page_size)       == 0x008, "params.page_size");
static_assert(offsetof(struct malloc_params, granularity)     == 0x010, "params.granularity");
static_assert(offsetof(struct malloc_params, mmap_threshold)  == 0x018, "params.mmap_threshold");
static_assert(offsetof(struct malloc_params, trim_threshold)  == 0x020, "params.trim_threshold");
static_assert(offsetof(struct malloc_params, default_mflags)  == 0x028, "params.default_mflags");

/*
 * s4 malloc_state: missing max_footprint and footprint_limit vs canonical.
 * Verified via DAT_ globals in mspace_memalign/mspace_malloc/mspace_free:
 *   DAT_1416bcc70 @ offset 0x360 = mflags (& 2 check)
 *   DAT_1416bcc74 @ offset 0x364 = mutex (lock/unlock spin)
 *   DAT_1416bc910 @ offset 0x000 = smallmap (base of _gm_)
 * Total size: 920 bytes (0x398), vs canonical 936 (0x3A8).
 */
struct malloc_state {
    binmap_t smallmap;                              /* 0x000 */
    binmap_t treemap;                               /* 0x004 */
    size_t dvsize;                                  /* 0x008 */
    size_t topsize;                                 /* 0x010 */
    char *least_addr;                               /* 0x018 */
    struct malloc_chunk *dv;                        /* 0x020 */
    struct malloc_chunk *top;                       /* 0x028 */
    size_t trim_check;                              /* 0x030 */
    size_t release_checks;                          /* 0x038 */
    size_t magic;                                   /* 0x040 */
    struct malloc_chunk *smallbins[(NSMALLBINS+1)*2]; /* 0x048 */
    struct malloc_tree_chunk *treebins[NTREEBINS];  /* 0x258 */
    size_t footprint;                               /* 0x358 */
    /* NOTE: max_footprint and footprint_limit ABSENT in s4 */
    flag_t mflags;                                  /* 0x360 */
    volatile int mutex;                             /* 0x364 */
    struct malloc_segment seg;                      /* 0x368 */
    void *extp;                                     /* 0x388 */
    size_t exts;                                    /* 0x390 */
};
static_assert(sizeof(struct malloc_state) == 920, "malloc_state s4 size");
static_assert(offsetof(struct malloc_state, smallmap)       == 0x000, "ms.smallmap");
static_assert(offsetof(struct malloc_state, treemap)        == 0x004, "ms.treemap");
static_assert(offsetof(struct malloc_state, dvsize)         == 0x008, "ms.dvsize");
static_assert(offsetof(struct malloc_state, topsize)        == 0x010, "ms.topsize");
static_assert(offsetof(struct malloc_state, least_addr)     == 0x018, "ms.least_addr");
static_assert(offsetof(struct malloc_state, dv)             == 0x020, "ms.dv");
static_assert(offsetof(struct malloc_state, top)            == 0x028, "ms.top");
static_assert(offsetof(struct malloc_state, trim_check)     == 0x030, "ms.trim_check");
static_assert(offsetof(struct malloc_state, release_checks) == 0x038, "ms.release_checks");
static_assert(offsetof(struct malloc_state, magic)          == 0x040, "ms.magic");
static_assert(offsetof(struct malloc_state, smallbins)      == 0x048, "ms.smallbins");
static_assert(offsetof(struct malloc_state, treebins)       == 0x258, "ms.treebins");
static_assert(offsetof(struct malloc_state, footprint)      == 0x358, "ms.footprint");
static_assert(offsetof(struct malloc_state, mflags)         == 0x360, "ms.mflags");
static_assert(offsetof(struct malloc_state, mutex)          == 0x364, "ms.mutex");
static_assert(offsetof(struct malloc_state, seg)            == 0x368, "ms.seg");
static_assert(offsetof(struct malloc_state, extp)           == 0x388, "ms.extp");
static_assert(offsetof(struct malloc_state, exts)           == 0x390, "ms.exts");

#endif /* LIBDLMALLOC_S4_H */