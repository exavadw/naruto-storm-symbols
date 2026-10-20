/*
 * libCurl s4 — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe)
 * libcurl 7.29.0 statically linked, image base 0x140000000
 *
 * INFERRED layouts from public source + decompiled game code.
 * Sizes proven from game code: SessionHandle = 0x8a38, Curl_multi = 0xe8.
 * Sub-structs without proven x64 MSVC size are opaque uint8_t arrays.
 * All static_assert offsets are INFERRED from source order and alignment;
 * only the total sizes of SessionHandle and Curl_multi are CONFIRMED.
 */
#ifndef LIBCURL_S4_H
#define LIBCURL_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ---------- curl_slist (public, well-known layout) ---------- */
struct curl_slist {
    char *data;
    struct curl_slist *next;
};
static_assert(offsetof(struct curl_slist, data) == 0x00, "curl_slist.data");
static_assert(offsetof(struct curl_slist, next) == 0x08, "curl_slist.next");

/* ---------- Curl_share (share.h:39-55, no instance state proven) ---------- */
/*
 * Curl_share has no confirmed instance in Storm 4 game code.
 * curl_share_init/cleanup/setopt are present but share objects are not
 * observed in any decompiled function. Opaque placeholder.
 */
struct Curl_share_s4 {
    /* no instance state confirmed in this build */
    uint8_t _opaque[1]; /* placeholder to allow pointer types */
};

/* ---------- Curl_multi (multihandle.h:83-120, size 0xe8 CONFIRMED) ---------- */
/*
 * Size 0xe8 confirmed from curl_multi_init decomp (RVA 0xb42d60):
 * operator new(0xe8) followed by magic store 0xbab1e at offset 0x00.
 * Internal fields below are INFERRED from libcurl 7.29.0 source order.
 * Only the magic field offset is cross-checked against decomp output.
 */
struct Curl_multi {
    unsigned int magic;      /* 0x00: 0xbab1e (CONFIRMED) */
    uint8_t _rest[0xe4];     /* 0x04..0xe7: remaining fields, layout unproven */
};
static_assert(sizeof(struct Curl_multi) == 0xe8, "Curl_multi size");
static_assert(offsetof(struct Curl_multi, magic) == 0x00, "Curl_multi.magic");

/* ---------- SessionHandle (urldata.h:1607-1640, size 0x8a38 CONFIRMED) ---------- */
/*
 * Size 0x8a38 confirmed from curl_easy_duphandle decomp (RVA 0xb3be20):
 * malloc(0x8a38) then memcpy of source handle.
 * The struct contains embedded UserDefined, UrlState, Progress, etc.
 * whose individual x64 MSVC layouts are NOT proven from game code.
 * We use an opaque body after the first few pointer fields that have
 * direct evidence from decompiled access patterns.
 *
 * Note: _body is sized to make sizeof(SessionHandle)==0x8a38 on both
 * GCC/Linux x64 and MSVC/x64. The natural-alignment padding before _body
 * is already accounted for in the 0x30 prefix; the trailing array absorbs
 * the remaining bytes including any end-of-struct alignment.
 */
struct SessionHandle {
    /* dns (Names): hostcache ptr + enum => 0x10 on x64 */
    void *dns_hostcache;          /* 0x0000: Names.hostcache */
    int dns_hostcachetype;        /* 0x0008: Names.hostcachetype (enum=int) */
    uint8_t _pad_dns[4];          /* 0x000c: align to 0x10 */

    struct Curl_multi *multi;     /* 0x0010: multi handle ptr */
    struct Curl_multi *multi_easy;/* 0x0018: easy-mode multi ptr */
    void *multi_pos;              /* 0x0020: Curl_one_easy* position */
    struct Curl_share_s4 *share;  /* 0x0028: share handle ptr */

    /*
     * Remaining bytes contain SingleRequest, UserDefined, DynamicStatic,
     * CookieInfo*, Progress, UrlState, WildcardData, PureInfo, and magic.
     * These sub-structs have complex conditional compilation and their exact
     * x64 MSVC layout is NOT proven from game code beyond the total size.
     * Opaque until individual field offsets are verified via decomp xrefs.
     *
     * 0x8a38 - 0x30 = 0x8a08 bytes remain.
     */
    uint8_t _body[0x8a08];        /* 0x0030..0x8a37 */
};
static_assert(sizeof(struct SessionHandle) == 0x8a38, "SessionHandle size");
static_assert(offsetof(struct SessionHandle, dns_hostcache) == 0x0000, "SessionHandle.dns_hostcache");
static_assert(offsetof(struct SessionHandle, dns_hostcachetype) == 0x0008, "SessionHandle.dns_hostcachetype");
static_assert(offsetof(struct SessionHandle, _pad_dns) == 0x000c, "SessionHandle._pad_dns");
static_assert(offsetof(struct SessionHandle, multi) == 0x0010, "SessionHandle.multi");
static_assert(offsetof(struct SessionHandle, multi_easy) == 0x0018, "SessionHandle.multi_easy");
static_assert(offsetof(struct SessionHandle, multi_pos) == 0x0020, "SessionHandle.multi_pos");
static_assert(offsetof(struct SessionHandle, share) == 0x0028, "SessionHandle.share");
static_assert(offsetof(struct SessionHandle, _body) == 0x0030, "SessionHandle._body");

#endif /* LIBCURL_S4_H */