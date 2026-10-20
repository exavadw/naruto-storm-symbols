/* cmn55.h — INFERRED struct layouts for Storm 1 (s1) font subsystem classes
 * Source: NSUNS1.exe x64 decompilation (image base 0x140000000)
 * All fields INFERRED from static analysis; not CONFIRMED at runtime.
 * Sizes proven only where allocator/factory calls provide explicit constants.
 */
#ifndef CMN55_H
#define CMN55_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose full layout is not in this group */
typedef struct Nucc_Vector2 { float x; float y; } Nucc_Vector2; /* 8 bytes */
typedef struct Nucc_Matrix44 { float m[16]; } Nucc_Matrix44;   /* 64 bytes */

/* Placeholder for BlockAllocator — internal engine type, layout not reconstructed here */
typedef struct Nucc_BlockAllocator { uint8_t _data[40]; } Nucc_BlockAllocator;

/* Placeholder for nuccCriticalSection */
typedef struct nuccCriticalSection { uint8_t _data[40]; } nuccCriticalSection;

/* =========================================================================
 * nuccFontRubyParam — ruby text annotation parameter
 * Size: >= 0x30 (last field at 0x2C + 4 bytes); no allocator proof
 * Vtable: PTR_FUN_14073a348 (from ctor)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFontRubyParam {
    /* 0x00 */ void *vtable;                        /* PTR_FUN_14073a348 */
    /* 0x08 */ Nucc_Vector2 position;               /* ctor: Vector2::Vector2() */
    /* 0x10 */ Nucc_Vector2 offset;                 /* ctor: Vector2::Vector2(param_1+3), set to zero */
    /* 0x18 */ Nucc_Vector2 scale;                  /* ctor: param_1[3] = zero vector */
    /* 0x20 */ int32_t flags;                       /* ctor: param_1[4] = 0 */
    /* 0x24 */ int32_t pad_24;                      /* padding */
    /* 0x28 */ int32_t unknown_28;                  /* ctor: *(param_1+5) = 0 */
    /* 0x2C */ float scale_factor;                  /* ctor: 0x3f800000 = 1.0f; state_surface confirms */
} nuccFontRubyParam;

static_assert(offsetof(nuccFontRubyParam, vtable)       == 0x00, "nuccFontRubyParam.vtable");
static_assert(offsetof(nuccFontRubyParam, position)     == 0x08, "nuccFontRubyParam.position");
static_assert(offsetof(nuccFontRubyParam, offset)       == 0x10, "nuccFontRubyParam.offset");
static_assert(offsetof(nuccFontRubyParam, scale)        == 0x18, "nuccFontRubyParam.scale");
static_assert(offsetof(nuccFontRubyParam, flags)        == 0x20, "nuccFontRubyParam.flags");
static_assert(offsetof(nuccFontRubyParam, unknown_28)   == 0x28, "nuccFontRubyParam.unknown_28");
static_assert(offsetof(nuccFontRubyParam, scale_factor) == 0x2C, "nuccFontRubyParam.scale_factor");

/* =========================================================================
 * nuccFont2ParamManager — manages pool of nuccFont2Param objects
 * Size: >= 0x68 (ctor accesses up to slot 9 + nuccCriticalSection ~40 bytes)
 * Vtable: PTR_FUN_14073b478 (primary ctor) / PTR_FUN_14073f2d0 (secondary ctor)
 * Object size PROVEN: 0x228 (552 bytes) from MallocCore(count*0x228) in
 *   nuccPoolAllocation<nuccFont2Param>::Create and LoadTh(0x228,...) in
 *   nuccFont2ParamManager::New — BUT this is the PARAM size, not the manager.
 *   Manager size remains unproven; last field access at slot 9 + critsec.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFont2ParamManager {
    /* 0x00 */ void *vtable;                        /* PTR_FUN_14073b478 or PTR_FUN_14073f2d0 */
    /* 0x08 */ void *secondary_vtable;              /* ctor: param_1[1] = PTR_FUN_14073b460 */
    /* 0x10 */ int32_t count;                       /* ctor: *(param_1+4) = 0 */
    /* 0x14 */ int32_t pad_14;
    /* 0x18 */ int64_t pool_base;                   /* ctor: param_1[5] = 0 */
    /* 0x20 */ int64_t pool_end;                    /* ctor: param_1[6] = 0 */
    /* 0x28 */ int32_t free_index;                  /* ctor: *(param_1+7) = 0 */
    /* 0x2C */ int32_t pad_2c;
    /* 0x30 */ int64_t free_list;                   /* ctor: param_1[8] = 0 */
    /* 0x38 */ nuccCriticalSection critsec;         /* ctor: nuccCriticalSection(param_1+9) */
} nuccFont2ParamManager;

static_assert(offsetof(nuccFont2ParamManager, vtable)          == 0x00, "nuccFont2ParamManager.vtable");
static_assert(offsetof(nuccFont2ParamManager, secondary_vtable)== 0x08, "nuccFont2ParamManager.secondary_vtable");
static_assert(offsetof(nuccFont2ParamManager, count)           == 0x10, "nuccFont2ParamManager.count");
static_assert(offsetof(nuccFont2ParamManager, pool_base)       == 0x18, "nuccFont2ParamManager.pool_base");
static_assert(offsetof(nuccFont2ParamManager, pool_end)        == 0x20, "nuccFont2ParamManager.pool_end");
static_assert(offsetof(nuccFont2ParamManager, free_index)      == 0x28, "nuccFont2ParamManager.free_index");
static_assert(offsetof(nuccFont2ParamManager, free_list)       == 0x30, "nuccFont2ParamManager.free_list");
static_assert(offsetof(nuccFont2ParamManager, critsec)         == 0x38, "nuccFont2ParamManager.critsec");

/* =========================================================================
 * nuccFont2Param — single font rendering parameter block
 * Size: PROVEN 0x228 (552 bytes) from MallocCore(count*0x228) in
 *   nuccPoolAllocation<nuccFont2Param>::Create and LoadTh(0x228,...) in
 *   nuccFont2ParamManager::New
 * Only one field surfaced by state_surface at 0x224; rest is opaque.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFont2Param {
    /* 0x000 */ uint8_t _opaque[0x224];            /* not yet reconstructed */
    /* 0x224 */ int32_t unknown_224;                /* state_surface: sz=4 */
} nuccFont2Param;

static_assert(offsetof(nuccFont2Param, unknown_224) == 0x224, "nuccFont2Param.unknown_224");
static_assert(sizeof(nuccFont2Param) == 0x228, "nuccFont2Param size proven 0x228");

/* =========================================================================
 * nuccFont2 — main font rendering object (base class for nuccFontTag)
 * Size: unknown, >= 0xEC (last state_surface field with size at 0xEC)
 *   state_surface also reports accesses at 0xC0..0x200 but without sizes.
 * Vtable: PTR_FUN_140739708 (from ctor); switches to PTR_FUN_140745358 in dtor
 * Fields named from ctor/dtor/DrawCore/GetBitmapFontEntry evidence.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFont2 {
    /* 0x00 */ void *vtable;                        /* PTR_FUN_140739708 */
    /* 0x08 */ Nucc_BlockAllocator allocator;       /* ctor: BlockAllocator::BlockAllocator */
    /* 0x30 */ int32_t pad_30[3];                   /* gap to 0x3C */
    /* 0x3C */ float field_3c;                      /* ctor: float init; state_surface sz=4 */
    /* 0x40 */ int32_t chunk_id;                    /* DrawRuby reads param_1+0x40 */
    /* 0x44 */ float field_44;                      /* ctor: float init; state_surface sz=4 */
    /* 0x48 */ int32_t pad_48[2];
    /* 0x50 */ int32_t pad_50;
    /* 0x54 */ float line_width;                    /* ctor: float init; state_surface sz=4 */
    /* 0x58 */ float alpha_multiplier;              /* ctor: float init; ExecTag reads +0x5C as alpha */
    /* 0x5C */ float color_alpha;                   /* ctor: float init; state_surface sz=4 */
    /* 0x60 */ int64_t field_60;                    /* state_surface sz=8 */
    /* 0x68 */ int32_t field_68;                    /* DrawRuby reads param_1+0x68 */
    /* 0x6C */ Nucc_Vector2 position_6c;            /* ctor: Vector2 at +0xC (slot); state_surface sz=8 */
    /* 0x74 */ Nucc_Vector2 position_74;            /* ctor: Vector2; state_surface sz=8 */
    /* 0x7C */ int64_t field_7c;                    /* state_surface sz=8 */
    /* 0x84 */ int64_t field_84;                    /* state_surface sz=8 */
    /* 0x8C */ float field_8c;                      /* ctor: float init; state_surface sz=4 */
    /* 0x90 */ int32_t field_90;                    /* state_surface sz=4 */
    /* 0x94 */ int32_t draw_mode;                   /* ctor: float init; DrawFont dispatches on +0x94 */
    /* 0x98 */ int64_t field_98;                    /* state_surface sz=None (accessed) */
    /* 0xA0 */ int32_t pad_a0[8];                   /* gap to 0xC0 */
    /* 0xC0 */ uint8_t field_c0[0x18];             /* state_surface accessed, size unknown */
    /* 0xD8 */ float color_r;                       /* ctor: float init; DrawCore uses for color */
    /* 0xDC */ int64_t field_dc;                    /* state_surface sz=8 */
    /* 0xE4 */ int64_t field_e4;                    /* state_surface sz=8 */
    /* 0xEC */ float field_ec;                      /* ctor: float init; state_surface sz=4 */
    /* 0xF0 */ uint8_t _remaining[0x110];          /* state_surface accesses at 0x100,0x140,0x180,0x1C0,0x200 — sizes unknown */
} nuccFont2;

static_assert(offsetof(nuccFont2, vtable)           == 0x00, "nuccFont2.vtable");
static_assert(offsetof(nuccFont2, allocator)        == 0x08, "nuccFont2.allocator");
static_assert(offsetof(nuccFont2, field_3c)         == 0x3C, "nuccFont2.field_3c");
static_assert(offsetof(nuccFont2, chunk_id)         == 0x40, "nuccFont2.chunk_id");
static_assert(offsetof(nuccFont2, field_44)         == 0x44, "nuccFont2.field_44");
static_assert(offsetof(nuccFont2, line_width)       == 0x54, "nuccFont2.line_width");
static_assert(offsetof(nuccFont2, alpha_multiplier) == 0x58, "nuccFont2.alpha_multiplier");
static_assert(offsetof(nuccFont2, color_alpha)      == 0x5C, "nuccFont2.color_alpha");
static_assert(offsetof(nuccFont2, field_60)         == 0x60, "nuccFont2.field_60");
static_assert(offsetof(nuccFont2, field_68)         == 0x68, "nuccFont2.field_68");
static_assert(offsetof(nuccFont2, position_6c)      == 0x6C, "nuccFont2.position_6c");
static_assert(offsetof(nuccFont2, position_74)      == 0x74, "nuccFont2.position_74");
static_assert(offsetof(nuccFont2, field_7c)         == 0x7C, "nuccFont2.field_7c");
static_assert(offsetof(nuccFont2, field_84)         == 0x84, "nuccFont2.field_84");
static_assert(offsetof(nuccFont2, field_8c)         == 0x8C, "nuccFont2.field_8c");
static_assert(offsetof(nuccFont2, field_90)         == 0x90, "nuccFont2.field_90");
static_assert(offsetof(nuccFont2, draw_mode)        == 0x94, "nuccFont2.draw_mode");
static_assert(offsetof(nuccFont2, field_98)         == 0x98, "nuccFont2.field_98");
static_assert(offsetof(nuccFont2, field_c0)         == 0xC0, "nuccFont2.field_c0");
static_assert(offsetof(nuccFont2, color_r)          == 0xD8, "nuccFont2.color_r");
static_assert(offsetof(nuccFont2, field_dc)         == 0xDC, "nuccFont2.field_dc");
static_assert(offsetof(nuccFont2, field_e4)         == 0xE4, "nuccFont2.field_e4");
static_assert(offsetof(nuccFont2, field_ec)         == 0xEC, "nuccFont2.field_ec");
static_assert(offsetof(nuccFont2, _remaining)       == 0xF0, "nuccFont2._remaining");

/* =========================================================================
 * nuccFontTag — extends nuccFont2 with tag/ruby processing
 * Inherits nuccFont2 as first member (ctor calls nuccFont2::nuccFont2 first).
 * Size: unknown, >= 0x2A0 (state_surface accesses at 0x268, 0x280)
 * Vtable: PTR_FUN_14073a350 (from ctor/dtor)
 * Additional fields start after nuccFont2 base (offset depends on base size).
 * Ctor uses qword slots relative to param_1 directly (not base+offset),
 * so fields below are absolute offsets within nuccFontTag.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFontTag {
    /* Inherit nuccFont2 at offset 0x00 */
    nuccFont2 base;

    /* --- nuccFontTag extension fields (absolute offsets from ctor) --- */
    /* The ctor writes to param_1[0x1e..0x2b] as qword slots and
     * param_1+byte_offset for others. Slots 0x1e-0x21 = BlockAllocator region.
     * Byte-offset fields from ctor/state_surface: */

    /* Note: since nuccFont2 size is unproven, we cannot use static_assert
     * for extension field offsets relative to base. We document absolute
     * offsets from the ctor evidence instead. The base struct above covers
     * at least 0xF0+0x110 = 0x200 bytes. Extension fields overlap with
     * nuccFont2._remaining until base size is proven. */
} nuccFontTag;

/* Absolute offset asserts from ctor/state_surface evidence (not relative to base): */
/* These document what the decompiler shows; they cannot be validated with
 * offsetof until nuccFont2 size is proven. Kept as comments for reference:
 *   0xF0  — pointer (state_surface sz=8, DrawRuby iterates)
 *   0xF8  — pointer (state_surface sz=8, DrawRuby end iterator)
 *   0x100 — pointer (state_surface sz=8)
 *   0x108 — pointer (state_surface sz=8)
 *   0x120 — int32 (state_surface sz=4)
 *   0x124 — int32 (state_surface sz=4, DrawRuby checks == 1)
 *   0x128 — int32 (state_surface sz=4)
 *   0x130 — int32 (state_surface sz=4)
 *   0x134 — float (state_surface sz=4, ExecTag reads as color.g)
 *   0x138 — int32 (state_surface sz=4)
 *   0x13C — float (state_surface sz=4, ExecTag reads as color.a)
 *   0x140 — int32 (state_surface sz=4, DrawRuby reads)
 *   0x144 — int32 (state_surface sz=4, DrawRuby reads)
 *   0x148 — float (state_surface sz=None, DrawRuby scales *0.4)
 *   0x14C — float (implied by DrawRuby scale.y *0.4)
 *   0x150 — float (state_surface sz=None, DrawRuby adds to position)
 *   0x154 — float (DrawRuby adds to accumulator)
 *   0x158 — int32 (state_surface sz=4)
 *   0x15C — int32 (state_surface sz=4, ExecTag checks != 0)
 *   0x268 — pointer (state_surface sz=8)
 *   0x280 — (state_surface sz=None, accessed)
 */

#endif /* CMN55_H */