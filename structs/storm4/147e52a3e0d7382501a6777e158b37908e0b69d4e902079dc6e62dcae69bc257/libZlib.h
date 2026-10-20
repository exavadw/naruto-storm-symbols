/* libZlib.h — Storm 4 (s4) zlib 1.2.7 struct layouts
 * INFERRED from static decompilation of NSUNS4_release.exe (build s4).
 * NOT CONFIRMED at runtime. Field names from zlib 1.2.7 source structural match.
 *
 * z_stream layout verified against deflateInit2_ (RVA 0xB9CC90) and inflate (RVA 0xB999D0).
 * deflate_state allocation size 0x1720 proven from deflateInit2_ zalloc call.
 * inflate_state size unproven; fields inferred from inflate decomp only.
 */

#ifndef LIBZLIB_S4_H
#define LIBZLIB_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef void *(*zlib_alloc_func)(void *opaque, uint32_t items, uint32_t size);
typedef void (*zlib_free_func)(void *opaque, void *address);

/*
 * z_stream_s4 — z_stream as laid out in Storm 4's MSVC x64 build.
 *
 * Verified offsets (byte) from decompiled code:
 *   deflateInit2_: +0x20=msg, +0x28=state, +0x30=zalloc, +0x38=zfree, +0x40=opaque
 *   inflate:       [0]=next_in, [1]lo32=avail_in, [2]=next_out, [3]lo32=avail_out,
 *                  [4]=msg, [5]=state  (longlong* indexing → offsets 0,8,16,24,32,40)
 *
 * Size: 0x60 (96 bytes) inferred from field extent through reserved@0x58 + 8.
 * No explicit sizeof found in game code for z_stream itself.
 */
typedef struct __attribute__((packed)) z_stream_s4 {
    uint8_t        *next_in;     /* 0x00 */
    uint64_t        avail_in;    /* 0x08 — u64 slot, low 32 bits used */
    uint8_t        *next_out;    /* 0x10 */
    uint64_t        avail_out;   /* 0x18 — u64 slot, low 32 bits used */
    char           *msg;         /* 0x20 */
    void           *state;       /* 0x28 */
    zlib_alloc_func zalloc;      /* 0x30 */
    zlib_free_func  zfree;       /* 0x38 */
    void           *opaque;      /* 0x40 */
    int32_t         data_type;   /* 0x48 */
    uint32_t        _pad_4c;     /* 0x4C */
    uint64_t        adler;       /* 0x50 */
    uint64_t        reserved;    /* 0x58 */
} z_stream_s4;

static_assert(offsetof(z_stream_s4, next_in)   == 0x00, "z_stream_s4.next_in");
static_assert(offsetof(z_stream_s4, avail_in)  == 0x08, "z_stream_s4.avail_in");
static_assert(offsetof(z_stream_s4, next_out)  == 0x10, "z_stream_s4.next_out");
static_assert(offsetof(z_stream_s4, avail_out) == 0x18, "z_stream_s4.avail_out");
static_assert(offsetof(z_stream_s4, msg)       == 0x20, "z_stream_s4.msg");
static_assert(offsetof(z_stream_s4, state)     == 0x28, "z_stream_s4.state");
static_assert(offsetof(z_stream_s4, zalloc)    == 0x30, "z_stream_s4.zalloc");
static_assert(offsetof(z_stream_s4, zfree)     == 0x38, "z_stream_s4.zfree");
static_assert(offsetof(z_stream_s4, opaque)    == 0x40, "z_stream_s4.opaque");
static_assert(offsetof(z_stream_s4, data_type) == 0x48, "z_stream_s4.data_type");
static_assert(offsetof(z_stream_s4, adler)     == 0x50, "z_stream_s4.adler");
static_assert(offsetof(z_stream_s4, reserved)  == 0x58, "z_stream_s4.reserved");

/*
 * deflate_state_s4 — internal deflate state.
 *
 * Allocation size 0x1720 (5920 bytes) PROVEN from deflateInit2_ (RVA 0xB9CC90):
 *   zalloc(opaque, 1, 0x1720) → stored at strm+0x28 (state).
 *
 * Field offsets below are INFERRED from deflateInit2_ decomp using longlong* indexing
 * (plVar3 = deflate_state*). Offsets derived as plVar3[N] → byte offset N*8,
 * and *(plVar3 + byte_off) → direct byte offset. Mixed indexing in the decompiler
 * output makes some assignments uncertain; those fields are marked with lower confidence
 * in the fields TSV.
 *
 * Layout uses natural MSVC x64 alignment (no packed attribute). The window_size field
 * (uLong, 8 bytes at 0x58) was confirmed by layout probe: it fills the gap between
 * window@0x50 and prev@0x60 that the original packed layout could not explain.
 *
 * Only fields with clear decomp evidence are named; the remainder is opaque padding
 * to the proven allocation size.
 */
typedef struct deflate_state_s4 {
    void     *strm;              /* 0x0000 — back-pointer to z_stream (plVar3[0]) */
    int32_t   status;            /* 0x0008 — set to 0x29a on error (plVar3[1]) */
    uint32_t  _pad_0c;           /* 0x000C */
    uint8_t  *pending_buf;      /* 0x0010 — plVar3[2] */
    uint64_t  pending_buf_size;  /* 0x0018 — plVar3[3] */
    uint8_t  *pending_out;      /* 0x0020 — inferred from zlib 1.2.7 source order */
    uint32_t  pending;           /* 0x0028 — inferred */
    int32_t   wrap;              /* 0x002C — *(uint*)(plVar3+0x2c) in decomp */
    void     *gzhead;            /* 0x0030 — plVar3[6] initialized to 0 */
    uint32_t  gzindex;           /* 0x0038 — inferred */
    uint8_t   method;            /* 0x003C — *(undef1*)(plVar3+0x3c) = 8 */
    uint8_t   _pad_3d[3];        /* 0x003D */
    int32_t   last_flush;        /* 0x0040 — inferred */
    uint32_t  w_size;            /* 0x0044 — *(int*)((longlong)plVar3+0x44) */
    uint32_t  w_bits;            /* 0x0048 — *(int*)(plVar3+9), 9*8=0x48 */
    uint32_t  w_mask;            /* 0x004C — *(int*)((longlong)plVar3+0x4c) */
    uint8_t  *window;            /* 0x0050 — plVar3[10], 10*8=0x50 */
    uint64_t  window_size;       /* 0x0058 — uLong in zlib 1.2.7; fills gap to prev@0x60 */
    uint8_t  *prev;              /* 0x0060 — ush* in zlib source */
    uint8_t  *head;              /* 0x0068 — posh* in zlib source */
    uint32_t  ins_h;             /* 0x0070 — insert hash value */
    uint32_t  hash_size;         /* 0x0074 — *(int*)((longlong)plVar3+0x74) */
    uint32_t  hash_bits;         /* 0x0078 — *(int*)(plVar3+0xf), 0xf*8=0x78 */
    uint32_t  hash_mask;         /* 0x007C — *(int*)((longlong)plVar3+0x7c) */
    uint32_t  hash_shift;        /* 0x0080 — *(uint*)(plVar3+0x10), 0x10*8=0x80 */
    uint8_t   _pad_84[40];       /* 0x0084 */
    uint32_t  strategy;          /* 0x00AC — *(uint*)(plVar3+0xac) */
    uint32_t  method_field;      /* 0x00B0 — *(uint*)(plVar3+0x16), 0x16*8=0xB0 */
    uint8_t   _remaining[0x1720 - 0x00B4]; /* pad to proven alloc size */
} deflate_state_s4;

static_assert(offsetof(deflate_state_s4, strm)             == 0x0000, "deflate_state_s4.strm");
static_assert(offsetof(deflate_state_s4, status)           == 0x0008, "deflate_state_s4.status");
static_assert(offsetof(deflate_state_s4, pending_buf)      == 0x0010, "deflate_state_s4.pending_buf");
static_assert(offsetof(deflate_state_s4, pending_buf_size) == 0x0018, "deflate_state_s4.pending_buf_size");
static_assert(offsetof(deflate_state_s4, wrap)             == 0x002C, "deflate_state_s4.wrap");
static_assert(offsetof(deflate_state_s4, w_size)           == 0x0044, "deflate_state_s4.w_size");
static_assert(offsetof(deflate_state_s4, w_bits)           == 0x0048, "deflate_state_s4.w_bits");
static_assert(offsetof(deflate_state_s4, w_mask)           == 0x004C, "deflate_state_s4.w_mask");
static_assert(offsetof(deflate_state_s4, window)           == 0x0050, "deflate_state_s4.window");
static_assert(offsetof(deflate_state_s4, window_size)      == 0x0058, "deflate_state_s4.window_size");
static_assert(offsetof(deflate_state_s4, prev)             == 0x0060, "deflate_state_s4.prev");
static_assert(offsetof(deflate_state_s4, head)             == 0x0068, "deflate_state_s4.head");
static_assert(offsetof(deflate_state_s4, ins_h)            == 0x0070, "deflate_state_s4.ins_h");
static_assert(offsetof(deflate_state_s4, hash_size)        == 0x0074, "deflate_state_s4.hash_size");
static_assert(offsetof(deflate_state_s4, hash_bits)        == 0x0078, "deflate_state_s4.hash_bits");
static_assert(offsetof(deflate_state_s4, hash_mask)        == 0x007C, "deflate_state_s4.hash_mask");
static_assert(offsetof(deflate_state_s4, hash_shift)       == 0x0080, "deflate_state_s4.hash_shift");
static_assert(offsetof(deflate_state_s4, strategy)         == 0x00AC, "deflate_state_s4.strategy");
static_assert(sizeof(deflate_state_s4)                     == 0x1720, "deflate_state_s4.size=0x1720");

/*
 * inflate_state_s4 — internal inflate state.
 *
 * Size UNPROVEN. Highest accessed offset in inflate decomp is puVar2[0x11] = 0x88.
 * Conservative lower bound: >= 0x90. Padded to 0x100 for safety; actual size may differ.
 *
 * Field offsets from inflate (RVA 0xB999D0), puVar2 = inflate_state* = param_1[5]:
 *   puVar2[0]  → 0x00 mode
 *   puVar2[2]  → 0x10 flags
 *   puVar2[4]  → 0x20 have
 *   puVar2[5]  → 0x28 wsize
 *   puVar2[6]  → 0x30 check
 *   puVar2[8]  → 0x40 head (gz_header*)
 *   puVar2[10] → 0x50 wbits
 *   puVar2[0x10] → 0x80 hold
 *   puVar2[0x11] → 0x88 bits
 */
typedef struct __attribute__((packed)) inflate_state_s4 {
    int32_t   mode;              /* 0x00 */
    uint32_t  _pad_04;           /* 0x04 */
    uint64_t  _field_08;         /* 0x08 — puVar2[1], purpose unknown */
    int32_t   flags;             /* 0x10 */
    uint32_t  _pad_14;           /* 0x14 */
    uint64_t  _field_18;         /* 0x18 — puVar2[3] */
    int32_t   have;              /* 0x20 */
    uint32_t  _pad_24;           /* 0x24 */
    uint32_t  wsize;             /* 0x28 */
    uint32_t  _pad_2c;           /* 0x2C */
    uint64_t  check;             /* 0x30 */
    uint64_t  _field_38;         /* 0x38 — puVar2[7] */
    void     *head;              /* 0x40 — gz_header* */
    uint64_t  _field_48;         /* 0x48 — puVar2[9] */
    uint32_t  wbits;             /* 0x50 */
    uint8_t   _pad_54[44];       /* 0x54 */
    uint64_t  hold;              /* 0x80 */
    uint64_t  bits;              /* 0x88 */
    uint8_t   _remaining[0x100 - 0x90]; /* pad; size unproven, >= 0x90 */
} inflate_state_s4;

static_assert(offsetof(inflate_state_s4, mode)   == 0x00, "inflate_state_s4.mode");
static_assert(offsetof(inflate_state_s4, flags)  == 0x10, "inflate_state_s4.flags");
static_assert(offsetof(inflate_state_s4, have)   == 0x20, "inflate_state_s4.have");
static_assert(offsetof(inflate_state_s4, wsize)  == 0x28, "inflate_state_s4.wsize");
static_assert(offsetof(inflate_state_s4, check)  == 0x30, "inflate_state_s4.check");
static_assert(offsetof(inflate_state_s4, head)   == 0x40, "inflate_state_s4.head");
static_assert(offsetof(inflate_state_s4, wbits)  == 0x50, "inflate_state_s4.wbits");
static_assert(offsetof(inflate_state_s4, hold)   == 0x80, "inflate_state_s4.hold");
static_assert(offsetof(inflate_state_s4, bits)   == 0x88, "inflate_state_s4.bits");

#endif /* LIBZLIB_S4_H */