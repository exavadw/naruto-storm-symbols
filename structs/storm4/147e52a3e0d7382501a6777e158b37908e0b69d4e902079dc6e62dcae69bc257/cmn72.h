/*
 * cmn72.h — nuccXfbinDocManager, nuccXfbinDocument, nuccXfbinParser
 * Build: s4 (NARUTO STORM 4 PC 1.09, NSUNS4_release.exe)
 * All layouts INFERRED from static analysis. Not CONFIRMED.
 * Offsets from x64 PE decompilation (image base 0x140000000).
 * Own-game names only (Storm 4 symbols/strings; no cross-game names).
 */

#ifndef CMN72_S4_H
#define CMN72_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for opaque embedded types */
typedef struct nuccXfbinParser nuccXfbinParser;

/*
 * nuccXfbinDocument
 * Size: 0x168 (360 bytes) — proven from FUN_140a01770(0x168,...) at RVA 0xA12A70 (Parser::Parse)
 * Vtable: PTR_FUN_1411052f0 (set in ctor at RVA 0xA11830)
 * Fields: 28 from state_surface + ctor decompile
 */
typedef struct __attribute__((packed)) nuccXfbinDocument {
    /* 0x00 */ void *vtable;               /* PTR_FUN_1411052f0 */
    /* 0x08 */ uint8_t _pad_08[0x50];      /* 0x08..0x57: base class / list node (sub-object ctor at +0x0F) */
    /* 0x58 */ uint64_t field_0x58;        /* w, ctor zeroes */
    /* 0x60 */ uint64_t field_0x60;        /* w, ctor zeroes */
    /* 0x68 */ uint64_t field_0x68;        /* w, ctor zeroes */
    /* 0x70 */ uint32_t _pad_0x70;         /* padding */
    /* 0x74 */ int32_t field_0x74;         /* w, ctor sets 0xFFFFFFFF */
    /* 0x78 */ uint8_t _subobj_0x78[0x28]; /* 0x78..0x9F: embedded sub-object (ctor at +0x0F) */
    /* 0xA0 */ uint64_t field_0xA0;        /* rw, sub-object init at +0x14 */
    /* 0xA8 */ uint8_t _pad_A8[0x10];      /* 0xA8..0xB7 */
    /* 0xB8 */ uint64_t field_0xB8;        /* w, ctor zeroes */
    /* 0xC0 */ uint64_t field_0xC0;        /* w, ctor zeroes */
    /* 0xC8 */ uint64_t field_0xC8;        /* w, ctor zeroes */
    /* 0xD0 */ uint16_t field_0xD0;        /* w, ctor zeroes */
    /* 0xD2 */ uint8_t _pad_D2[6];         /* padding to 0xD8 */
    /* 0xD8 */ uint64_t field_0xD8;        /* rw, sub-object init at +0x1b */
    /* 0xE0 */ uint8_t _pad_E0[0x10];      /* 0xE0..0xEF */
    /* 0xF0 */ uint64_t field_0xF0;        /* w, ctor zeroes */
    /* 0xF8 */ uint64_t field_0xF8;        /* w, ctor zeroes */
    /* 0x100 */ uint64_t field_0x100;      /* w, ctor zeroes */
    /* 0x108 */ uint16_t field_0x108;      /* w, ctor zeroes */
    /* 0x10A */ uint8_t _pad_10A[6];       /* padding to 0x110 */
    /* 0x110 */ uint32_t field_0x110;      /* w, ctor zeroes */
    /* 0x114 */ uint32_t field_0x114;      /* w, ctor zeroes */
    /* 0x118 */ uint64_t field_0x118;      /* w, ctor zeroes */
    /* 0x120 */ uint64_t field_0x120;      /* w, ctor zeroes */
    /* 0x128 */ uint64_t field_0x128;      /* w, ctor zeroes */
    /* 0x130 */ uint64_t field_0x130;      /* w, ctor zeroes */
    /* 0x138 */ uint64_t field_0x138;      /* w, ctor zeroes */
    /* 0x140 */ uint64_t field_0x140;      /* w, ctor zeroes */
    /* 0x148 */ uint64_t field_0x148;      /* w, ctor zeroes */
    /* 0x150 */ uint64_t field_0x150;      /* rw, ctor zeroes, later read */
    /* 0x158 */ uint64_t field_0x158;      /* w, ctor zeroes */
    /* 0x160 */ uint32_t field_0x160;      /* w, ctor zeroes */
    /* 0x164 */ uint32_t _pad_164;         /* trailing pad to 0x168 */
} nuccXfbinDocument;

static_assert(sizeof(nuccXfbinDocument) == 0x168, "nuccXfbinDocument size must be 0x168");
static_assert(offsetof(nuccXfbinDocument, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(nuccXfbinDocument, field_0x58) == 0x58, "field_0x58 @ 0x58");
static_assert(offsetof(nuccXfbinDocument, field_0x60) == 0x60, "field_0x60 @ 0x60");
static_assert(offsetof(nuccXfbinDocument, field_0x68) == 0x68, "field_0x68 @ 0x68");
static_assert(offsetof(nuccXfbinDocument, field_0x74) == 0x74, "field_0x74 @ 0x74");
static_assert(offsetof(nuccXfbinDocument, field_0xA0) == 0xA0, "field_0xA0 @ 0xA0");
static_assert(offsetof(nuccXfbinDocument, field_0xB8) == 0xB8, "field_0xB8 @ 0xB8");
static_assert(offsetof(nuccXfbinDocument, field_0xC0) == 0xC0, "field_0xC0 @ 0xC0");
static_assert(offsetof(nuccXfbinDocument, field_0xC8) == 0xC8, "field_0xC8 @ 0xC8");
static_assert(offsetof(nuccXfbinDocument, field_0xD0) == 0xD0, "field_0xD0 @ 0xD0");
static_assert(offsetof(nuccXfbinDocument, field_0xD8) == 0xD8, "field_0xD8 @ 0xD8");
static_assert(offsetof(nuccXfbinDocument, field_0xF0) == 0xF0, "field_0xF0 @ 0xF0");
static_assert(offsetof(nuccXfbinDocument, field_0xF8) == 0xF8, "field_0xF8 @ 0xF8");
static_assert(offsetof(nuccXfbinDocument, field_0x100) == 0x100, "field_0x100 @ 0x100");
static_assert(offsetof(nuccXfbinDocument, field_0x108) == 0x108, "field_0x108 @ 0x108");
static_assert(offsetof(nuccXfbinDocument, field_0x110) == 0x110, "field_0x110 @ 0x110");
static_assert(offsetof(nuccXfbinDocument, field_0x114) == 0x114, "field_0x114 @ 0x114");
static_assert(offsetof(nuccXfbinDocument, field_0x118) == 0x118, "field_0x118 @ 0x118");
static_assert(offsetof(nuccXfbinDocument, field_0x120) == 0x120, "field_0x120 @ 0x120");
static_assert(offsetof(nuccXfbinDocument, field_0x128) == 0x128, "field_0x128 @ 0x128");
static_assert(offsetof(nuccXfbinDocument, field_0x130) == 0x130, "field_0x130 @ 0x130");
static_assert(offsetof(nuccXfbinDocument, field_0x138) == 0x138, "field_0x138 @ 0x138");
static_assert(offsetof(nuccXfbinDocument, field_0x140) == 0x140, "field_0x140 @ 0x140");
static_assert(offsetof(nuccXfbinDocument, field_0x148) == 0x148, "field_0x148 @ 0x148");
static_assert(offsetof(nuccXfbinDocument, field_0x150) == 0x150, "field_0x150 @ 0x150");
static_assert(offsetof(nuccXfbinDocument, field_0x158) == 0x158, "field_0x158 @ 0x158");
static_assert(offsetof(nuccXfbinDocument, field_0x160) == 0x160, "field_0x160 @ 0x160");

/*
 * nuccXfbinParser
 * Size: unknown, >= 0x1E4 (last field at 0x1E0 is 4 bytes; stack-only allocation in callers)
 * Vtable: PTR_FUN_141105308 (set in ctor at RVA 0xA119A0)
 * Fields: 10 from state_surface
 */
typedef struct __attribute__((packed)) nuccXfbinParser {
    /* 0x000 */ void *vtable;              /* PTR_FUN_141105308 */
    /* 0x008 */ uint8_t _base[0x190];      /* 0x008..0x197: base class + sub-objects */
    /* 0x198 */ uint8_t _pad_198[0x18];    /* 0x198..0x1AF: gap before proven fields */
    /* 0x1B0 */ uint64_t field_0x1B0;      /* w, ctor zeroes (param_1[0x36]) */
    /* 0x1B8 */ uint64_t field_0x1B8;      /* w, ctor zeroes (param_1[0x37]) */
    /* 0x1C0 */ uint64_t field_0x1C0;      /* w, ctor zeroes (param_1[0x38]) */
    /* 0x1C8 */ uint64_t field_0x1C8;      /* rw, ctor/dtor access (param_1[0x39]) */
    /* 0x1D0 */ uint64_t field_0x1D0;      /* w, ctor zeroes (param_1[0x3a]) */
    /* 0x1D8 */ uint32_t field_0x1D8;      /* w, ctor sets 0xFFFFFFFF (param_1+0x3b) */
    /* 0x1DC */ uint8_t field_0x1DC;       /* w, ctor zeroes byte */
    /* 0x1DD */ uint8_t field_0x1DD;       /* rw, ctor bit-clear (& 0xFE) */
    /* 0x1DE */ uint8_t _pad_1DE[2];       /* padding */
    /* 0x1E0 */ uint32_t field_0x1E0;      /* w, ctor zeroes (param_1+0x3c) */
} nuccXfbinParser;

/* Size unproven — no sizeof assert. Last proven field ends at 0x1E4. */
static_assert(offsetof(nuccXfbinParser, vtable) == 0x000, "vtable @ 0x000");
static_assert(offsetof(nuccXfbinParser, field_0x1B0) == 0x1B0, "field_0x1B0 @ 0x1B0");
static_assert(offsetof(nuccXfbinParser, field_0x1B8) == 0x1B8, "field_0x1B8 @ 0x1B8");
static_assert(offsetof(nuccXfbinParser, field_0x1C0) == 0x1C0, "field_0x1C0 @ 0x1C0");
static_assert(offsetof(nuccXfbinParser, field_0x1C8) == 0x1C8, "field_0x1C8 @ 0x1C8");
static_assert(offsetof(nuccXfbinParser, field_0x1D0) == 0x1D0, "field_0x1D0 @ 0x1D0");
static_assert(offsetof(nuccXfbinParser, field_0x1D8) == 0x1D8, "field_0x1D8 @ 0x1D8");
static_assert(offsetof(nuccXfbinParser, field_0x1DC) == 0x1DC, "field_0x1DC @ 0x1DC");
static_assert(offsetof(nuccXfbinParser, field_0x1DD) == 0x1DD, "field_0x1DD @ 0x1DD");
static_assert(offsetof(nuccXfbinParser, field_0x1E0) == 0x1E0, "field_0x1E0 @ 0x1E0");

/*
 * nuccXfbinDocManager
 * Size: unknown, >= 0xC4 (last proven field at 0xC0 is 4 bytes; no heap allocation found)
 * Vtable: PTR_FUN_1411042f8 (dtor initial), PTR_FUN_1410075d8 (base/reset vtable)
 * Fields: 5 from state_surface + manual decompile inspection of dtor/Regist/Erase
 * Note: likely a singleton or embedded object; no operator-new site found.
 */
typedef struct __attribute__((packed)) nuccXfbinDocManager {
    /* 0x00 */ void *vtable;               /* PTR_FUN_1411042f8 (dtor) / PTR_FUN_1410075d8 (base) */
    /* 0x08 */ uint8_t _base[0x10];        /* 0x08..0x17: base class sub-objects */
    /* 0x18 */ uint8_t _lock_or_list[0x30]; /* 0x18..0x47: param_1+3 accessed by dtor cleanup */
    /* 0x48 */ uint64_t field_0x48;        /* rw, vtable-like dispatch at offset 0x80 via param_1+0x10 */
    /* 0x50 */ uint8_t _pad_50[0x28];      /* 0x50..0x77: opaque region */
    /* 0x78 */ uint64_t field_0x78;        /* r, RequestUnload passes to sub-func */
    /* 0x80 */ uint8_t _pad_80[0x18];      /* 0x80..0x97: vtable dispatch region */
    /* 0x98 */ uint64_t field_0x98;        /* r, container/map (param_1+0x13, dtor reads) */
    /* 0xA0 */ uint8_t _pad_A0[8];         /* 0xA0..0xA7 */
    /* 0xA8 */ uint64_t field_0xA8;        /* rw, dtor cleanup (param_1+0x15) */
    /* 0xB0 */ uint8_t _pad_B0[0x10];      /* 0xB0..0xBF */
    /* 0xC0 */ uint32_t load_state;        /* rw, thread state flag (InitLoadRequestThread/ExitLoadRequestThread/Load) */
    /* 0xC4 */ uint32_t _pad_C4;           /* trailing pad */
} nuccXfbinDocManager;

/* Size unproven — no sizeof assert. Last proven field ends at 0xC4. */
static_assert(offsetof(nuccXfbinDocManager, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(nuccXfbinDocManager, field_0x78) == 0x78, "field_0x78 @ 0x78");
static_assert(offsetof(nuccXfbinDocManager, field_0x98) == 0x98, "field_0x98 @ 0x98");
static_assert(offsetof(nuccXfbinDocManager, field_0xA8) == 0xA8, "field_0xA8 @ 0xA8");
static_assert(offsetof(nuccXfbinDocManager, load_state) == 0xC0, "load_state @ 0xC0");

#endif /* CMN72_S4_H */