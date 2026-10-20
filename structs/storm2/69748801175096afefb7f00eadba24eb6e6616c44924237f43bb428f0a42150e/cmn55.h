/* cmn55.h — INFERRED struct layouts for Storm 2 (s2) font subsystem classes
 * Source: NSUNS2.exe x64 decompilation (image base 0x140000000)
 * All fields INFERRED from static analysis; not CONFIRMED at runtime.
 * Sizes proven only where allocator/factory calls provide explicit constants.
 *
 * Layout strategy: __attribute__((packed)) with uint8_t gap arrays sized
 * to match proven field offsets. No embedded struct types (their internal
 * padding would shift offsets under packed). Every named field has a
 * static_assert(offsetof) check.
 */
#ifndef CMN55_S2_H
#define CMN55_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nuccFontRubyParam — ruby text annotation parameter
 * Size: >= 0x30 (last field at 0x2C + 4 bytes); no allocator proof found
 * Vtable: PTR_FUN_1408945e8 (from ctor at 0x611180)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFontRubyParam {
    /* 0x00 */ void     *vtable;          /* PTR_FUN_1408945e8 */
    /* 0x08 */ float     position_x;      /* ctor: FUN_140580630 vector init */
    /* 0x0C */ float     position_y;
    /* 0x10 */ float     offset_x;        /* ctor: param_1[2] = FUN_140580960() */
    /* 0x14 */ float     offset_y;
    /* 0x18 */ float     scale_x;         /* ctor: param_1[3] = FUN_140580960() */
    /* 0x1C */ float     scale_y;
    /* 0x20 */ int32_t   flags;           /* ctor: param_1[4] = 0 */
    /* 0x24 */ int32_t   unknown_24;      /* ctor: *(param_1+5)=0 at dword offset 5 → 0x28? see note */
    /* 0x28 */ int32_t   unknown_28;      /* state_surface: sz=4 w medium at 0x2C is scale_factor */
    /* 0x2C */ float     scale_factor;    /* ctor: 0x3f800000 = 1.0f */
} nuccFontRubyParam;

static_assert(offsetof(nuccFontRubyParam, vtable)       == 0x00, "nuccFontRubyParam.vtable");
static_assert(offsetof(nuccFontRubyParam, position_x)   == 0x08, "nuccFontRubyParam.position_x");
static_assert(offsetof(nuccFontRubyParam, position_y)   == 0x0C, "nuccFontRubyParam.position_y");
static_assert(offsetof(nuccFontRubyParam, offset_x)     == 0x10, "nuccFontRubyParam.offset_x");
static_assert(offsetof(nuccFontRubyParam, offset_y)     == 0x14, "nuccFontRubyParam.offset_y");
static_assert(offsetof(nuccFontRubyParam, scale_x)      == 0x18, "nuccFontRubyParam.scale_x");
static_assert(offsetof(nuccFontRubyParam, scale_y)      == 0x1C, "nuccFontRubyParam.scale_y");
static_assert(offsetof(nuccFontRubyParam, flags)        == 0x20, "nuccFontRubyParam.flags");
static_assert(offsetof(nuccFontRubyParam, unknown_24)   == 0x24, "nuccFontRubyParam.unknown_24");
static_assert(offsetof(nuccFontRubyParam, unknown_28)   == 0x28, "nuccFontRubyParam.unknown_28");
static_assert(offsetof(nuccFontRubyParam, scale_factor) == 0x2C, "nuccFontRubyParam.scale_factor");

/* =========================================================================
 * nuccFont2ParamManager — manages pool of nuccFont2Param objects
 * Size: PROVEN 0x98 (152 bytes) from FUN_140580190(0x98,...) in Initialize
 * nuccFont2Param element size: PROVEN 0x228 from FUN_140580190(0x228,...) in New
 * Vtable: PTR_FUN_140850528 (primary ctor at 0x4ADDD0)
 * Secondary ptr: PTR_FUN_14089c1b8 set at slots 0xf(+0x78) and 0x15(+0xA8)
 * Ctor field map (undefined8* param_1 indexing):
 *   slot 0  = vtable           → 0x00
 *   FUN_1403d6be4(param_1+0xc) → 0x60 (critsec init)
 *   slot 0xf = PTR             → 0x78
 *   FUN_1403d6be4(param_1+0x12)→ 0x90 (critsec init)
 *   slot 0x15 = PTR            → 0xA8 — BUT 0xA8 >= 0x98 proven size!
 *   Resolution: slot 0x15 write is at offset 0xA8 which is PAST the 0x98
 *   allocation. This means either (a) the 0x98 alloc is for a sub-object
 *   and the manager is larger, or (b) slot indexing uses a different base.
 *   The Initialize() call FUN_140580190(0x98) is definitive for the
 *   manager object itself. The slot 0x15 write may target an embedded
 *   sub-structure whose pointer arithmetic differs. We trust the 0x98 proof.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFont2ParamManager {
    /* 0x00 */ void     *vtable;          /* PTR_FUN_140850528 */
    /* 0x08 */ uint8_t   _pool_data[0x58]; /* pool management region (slots 1–10) */
    /* 0x60 */ uint8_t   _critsec_60[0x18]; /* critsec initialized by FUN_1403d6be4 */
    /* 0x78 */ void     *ptr_78;          /* slot 0xf = PTR_FUN_14089c1b8 */
    /* 0x80 */ uint8_t   _gap_80[0x10];   /* gap to 0x90 */
    /* 0x90 */ uint8_t   _critsec_90[0x08]; /* critsec tail; total = 0x98 */
} nuccFont2ParamManager;

static_assert(offsetof(nuccFont2ParamManager, vtable)      == 0x00, "nuccFont2ParamManager.vtable");
static_assert(offsetof(nuccFont2ParamManager, _pool_data)  == 0x08, "nuccFont2ParamManager._pool_data");
static_assert(offsetof(nuccFont2ParamManager, _critsec_60) == 0x60, "nuccFont2ParamManager._critsec_60");
static_assert(offsetof(nuccFont2ParamManager, ptr_78)      == 0x78, "nuccFont2ParamManager.ptr_78");
static_assert(offsetof(nuccFont2ParamManager, _gap_80)     == 0x80, "nuccFont2ParamManager._gap_80");
static_assert(offsetof(nuccFont2ParamManager, _critsec_90) == 0x90, "nuccFont2ParamManager._critsec_90");
static_assert(sizeof(nuccFont2ParamManager)                == 0x98, "nuccFont2ParamManager size proven 0x98");

/* =========================================================================
 * nuccFont2Param — single font rendering parameter block
 * Size: PROVEN 0x228 (552 bytes) from FUN_140580190(0x228,...) in
 *       nuccFont2ParamManager::New (same proof as s1)
 * Only one field surfaced by state_surface at 0x224; rest is opaque.
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFont2Param {
    /* 0x000 */ uint8_t  _opaque[0x224];  /* not yet reconstructed */
    /* 0x224 */ int32_t   unknown_224;    /* state_surface: sz=4 */
} nuccFont2Param;

static_assert(offsetof(nuccFont2Param, unknown_224) == 0x224, "nuccFont2Param.unknown_224");
static_assert(sizeof(nuccFont2Param)               == 0x228, "nuccFont2Param size proven 0x228");

/* =========================================================================
 * nuccFont2 — main font rendering object (base class for nuccFontTag)
 * Size: unknown, >= 0xF0 (last named field at 0xEC + 4)
 * BlockAllocator grow: FUN_1405b5cc0(param_1+4, 0x400) — capacity hint only
 * Vtable: PTR_FUN_140892628 (ctor 0x5B3AB0); dtor switches to PTR_FUN_14089c1b8
 *
 * Ctor field map (undefined8* param_1):
 *   slots 1-3 zeroed          → 0x08..0x1F (24 bytes)
 *   slot 4 = BlockAlloc base  → 0x20 (embedded allocator, ~24 bytes to 0x38)
 *   slot 7 = 1                → 0x38
 *   *(param_1+0x3c) = 1       → 0x3C (byte offset, not slot!)
 *   slot 8 = 1                → 0x40
 *   *(param_1+0x44) = 1       → 0x44
 *   *(param_1+0x54) = 1.0f    → 0x54
 *   slot 0xb = 1.0f           → 0x58
 *   *(param_1+0x5c) = 1.0f    → 0x5C
 *   FUN_140580630(param_1+0xc)→ 0x60 vector
 *   slot 0xd = 1.0f           → 0x68
 *   FUN vectors at +0x6c,+0x74,+0x7c
 *   *(param_1+0x84) = 1       → 0x84
 *   *(param_1+0x8c) = 0       → 0x8C
 *   *(param_1+0x94) = 0       → 0x94
 *   FUN_140586500(param_1+0x13)→ 0x98
 *   slot 0x12 = 0xe61         → 0x90
 *   *(param_1+0xdc) = 0       → 0xDC
 *   *(param_1+0xe4) = 0       → 0xE4
 *   *(param_1+0xec) = 0       → 0xEC
 *   *(param_1+0x1b) = 1.0f    → 0xD8
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFont2 {
    /* 0x00 */ void     *vtable;          /* PTR_FUN_140892628 */
    /* 0x08 */ uint8_t   _base_init[0x18]; /* slots 1-3 zeroed in ctor */
    /* 0x20 */ uint8_t   _block_alloc[0x18]; /* BlockAllocator head (slots 4-6 region) */
    /* 0x38 */ int32_t   init_flag_38;    /* ctor: slot 7 = 1 */
    /* 0x3C */ int32_t   draw_mode_a;     /* ctor: 1; DrawCore checks == 1 */
    /* 0x40 */ int32_t   init_flag_40;    /* ctor: slot 8 = 1 */
    /* 0x44 */ int32_t   draw_mode_b;     /* ctor: 1; DrawCore checks == 1 */
    /* 0x48 */ uint8_t   _gap_48[0x0C];   /* gap to 0x54 */
    /* 0x54 */ float     scale_x;         /* ctor: 1.0f */
    /* 0x58 */ float     scale_y;         /* ctor: slot 0xb = 1.0f */
    /* 0x5C */ float     scale_z;         /* ctor: 1.0f */
    /* 0x60 */ float     vec_60_x;        /* ctor: FUN_140580630 vector */
    /* 0x64 */ float     vec_60_y;
    /* 0x68 */ float     value_68;        /* ctor: slot 0xd = 1.0f */
    /* 0x6C */ float     vec_6c_x;        /* ctor: FUN_140580630 vector */
    /* 0x70 */ float     vec_6c_y;
    /* 0x74 */ float     vec_74_x;        /* ctor: FUN_140580630 vector */
    /* 0x78 */ float     vec_74_y;
    /* 0x7C */ float     vec_7c_x;        /* ctor: FUN_140580630 vector */
    /* 0x80 */ float     vec_7c_y;
    /* 0x84 */ int64_t   flag_84;         /* ctor: 1 */
    /* 0x8C */ int32_t   counter_8c;      /* ctor: 0 */
    /* 0x90 */ int32_t   tag_id;          /* ctor: slot 0x12 = 0xe61 */
    /* 0x94 */ int32_t   draw_enable;     /* ctor: 0; DrawCore checks == 0 */
    /* 0x98 */ uint8_t   _sub_alloc[0x28]; /* FUN_140586500(param_1+0x13) */
    /* 0xC0 */ uint8_t   _gap_c0[0x18];   /* virtual dispatch region */
    /* 0xD8 */ float     color_r;         /* ctor: slot 0x1b = 1.0f; DrawCore reads */
    /* 0xDC */ int32_t   _pad_dc;         /* alignment filler */
    /* 0xE0 */ uint8_t   _gap_e0[0x04];   /* gap to 0xE4 */
    /* 0xE4 */ int64_t   ptr_e4;          /* ctor: 0 */
    /* 0xEC */ int32_t   print_flag;      /* ctor: 0; Print sets */
    /* 0xF0 */ uint8_t   _remaining[0x10]; /* vtable calls at 0x100..0x200; size unproven */
} nuccFont2;

static_assert(offsetof(nuccFont2, vtable)       == 0x00, "nuccFont2.vtable");
static_assert(offsetof(nuccFont2, _base_init)   == 0x08, "nuccFont2._base_init");
static_assert(offsetof(nuccFont2, _block_alloc) == 0x20, "nuccFont2._block_alloc");
static_assert(offsetof(nuccFont2, init_flag_38) == 0x38, "nuccFont2.init_flag_38");
static_assert(offsetof(nuccFont2, draw_mode_a)  == 0x3C, "nuccFont2.draw_mode_a");
static_assert(offsetof(nuccFont2, init_flag_40) == 0x40, "nuccFont2.init_flag_40");
static_assert(offsetof(nuccFont2, draw_mode_b)  == 0x44, "nuccFont2.draw_mode_b");
static_assert(offsetof(nuccFont2, scale_x)      == 0x54, "nuccFont2.scale_x");
static_assert(offsetof(nuccFont2, scale_y)      == 0x58, "nuccFont2.scale_y");
static_assert(offsetof(nuccFont2, scale_z)      == 0x5C, "nuccFont2.scale_z");
static_assert(offsetof(nuccFont2, vec_60_x)     == 0x60, "nuccFont2.vec_60_x");
static_assert(offsetof(nuccFont2, vec_60_y)     == 0x64, "nuccFont2.vec_60_y");
static_assert(offsetof(nuccFont2, value_68)     == 0x68, "nuccFont2.value_68");
static_assert(offsetof(nuccFont2, vec_6c_x)     == 0x6C, "nuccFont2.vec_6c_x");
static_assert(offsetof(nuccFont2, vec_6c_y)     == 0x70, "nuccFont2.vec_6c_y");
static_assert(offsetof(nuccFont2, vec_74_x)     == 0x74, "nuccFont2.vec_74_x");
static_assert(offsetof(nuccFont2, vec_74_y)     == 0x78, "nuccFont2.vec_74_y");
static_assert(offsetof(nuccFont2, vec_7c_x)     == 0x7C, "nuccFont2.vec_7c_x");
static_assert(offsetof(nuccFont2, vec_7c_y)     == 0x80, "nuccFont2.vec_7c_y");
static_assert(offsetof(nuccFont2, flag_84)      == 0x84, "nuccFont2.flag_84");
static_assert(offsetof(nuccFont2, counter_8c)   == 0x8C, "nuccFont2.counter_8c");
static_assert(offsetof(nuccFont2, tag_id)       == 0x90, "nuccFont2.tag_id");
static_assert(offsetof(nuccFont2, draw_enable)  == 0x94, "nuccFont2.draw_enable");
static_assert(offsetof(nuccFont2, _sub_alloc)   == 0x98, "nuccFont2._sub_alloc");
static_assert(offsetof(nuccFont2, _gap_c0)      == 0xC0, "nuccFont2._gap_c0");
static_assert(offsetof(nuccFont2, color_r)      == 0xD8, "nuccFont2.color_r");
static_assert(offsetof(nuccFont2, ptr_e4)       == 0xE4, "nuccFont2.ptr_e4");
static_assert(offsetof(nuccFont2, print_flag)   == 0xEC, "nuccFont2.print_flag");
static_assert(offsetof(nuccFont2, _remaining)   == 0xF0, "nuccFont2._remaining");

/* =========================================================================
 * nuccFontTag — tagged/rich-text font renderer (inherits nuccFont2)
 * Size: unknown, >= 0x2A0 (state_surface vtable calls at 0x280)
 * Ctor calls nuccFont2::nuccFont2() first, then overrides vtable.
 * Vtable: PTR_FUN_1408945f0 (from ctor at 0x5C4F00)
 *
 * Extension fields (offsets relative to nuccFontTag this, NOT base):
 *   param_1[0x1e]=0           → 0xF0
 *   param_1[0x1f]=0           → 0xF8
 *   param_1[0x20]=0           → 0x100
 *   FUN(param_1+0x21)         → 0x108
 *   *(param_1+0x24)=0         → 0x120
 *   *(param_1+0x124)=1        → 0x124 (byte offset!)
 *   *(param_1+0x25)=1         → 0x128
 *   *(param_1+0x144)=0        → 0x144 (byte offset!)
 *   *(param_1+0x26)=1.0f      → 0x130
 *   *(param_1+0x134)=1.0f     → 0x134
 *   *(param_1+0x27)=1.0f      → 0x138
 *   *(param_1+0x13c)=1.0f     → 0x13C
 *   *(param_1+0x28)=0xe61     → 0x140
 *   FUN(param_1+0x29)         → 0x148
 *   FUN(param_1+0x2a)         → 0x150
 *   param_1[0x2b]=1           → 0x158
 *   *(param_1+0x15c)=1        → 0x15C (byte offset!)
 * ========================================================================= */
typedef struct __attribute__((packed)) nuccFontTag {
    /* --- inherited nuccFont2 base (layout matches above through 0xF0) --- */
    /* 0x00 */ void     *vtable;          /* overridden to PTR_FUN_1408945f0 */
    /* 0x08 */ uint8_t   _base[0xE8];    /* nuccFont2 fields 0x08..0xEF */
    /* 0xF0 */ uint8_t   _tag_alloc_1[0x08]; /* ctor: FUN_1405c5de0(param_1+0x1e) */
    /* 0xF8 */ void     *tag_ptr_f8;      /* ctor: param_1[0x1f]; ExecTag reads */
    /* 0x100 */ int64_t  tag_counter;     /* ctor: param_1[0x20] = 0 */
    /* 0x108 */ uint8_t  _tag_alloc_2[0x18]; /* ctor: FUN_1405858f0(param_1+0x21) */
    /* 0x120 */ int32_t  tag_flag_120;    /* ctor: 0; ExecTag writes 1 */
    /* 0x124 */ int32_t  ruby_enabled;    /* ctor: 1; gates ruby rendering */
    /* 0x128 */ int32_t  tag_flag_128;    /* ctor: 1 */
    /* 0x12C */ uint8_t  _gap_12c[0x04];  /* padding to 0x130 */
    /* 0x130 */ float    ruby_color_r;    /* ctor: 1.0f; ExecTag reads */
    /* 0x134 */ float    ruby_color_g;    /* ctor: 1.0f; ExecTag reads */
    /* 0x138 */ float    ruby_color_b;    /* ctor: 1.0f; ExecTag reads */
    /* 0x13C */ float    ruby_color_a;    /* ctor: 1.0f; ExecTag reads */
    /* 0x140 */ int32_t  tag_id_ext;      /* ctor: 0xe61 */
    /* 0x144 */ int32_t  tag_zero_144;    /* ctor: 0 */
    /* 0x148 */ float    ruby_off1_x;     /* ctor: FUN_140580630(param_1+0x29) */
    /* 0x14C */ float    ruby_off1_y;
    /* 0x150 */ float    ruby_off2_x;     /* ctor: FUN_140580630(param_1+0x2a) */
    /* 0x154 */ float    ruby_off2_y;
    /* 0x158 */ int32_t  tag_active;      /* ctor: 1; ExecTag checks != 0 */
    /* 0x15C */ int32_t  tag_enable_15c;  /* ctor: 1; ExecTag checks != 0 */
    /* 0x160 */ uint8_t  _remaining_tag[0x140]; /* vtable calls at +0x240,+0x280; size unproven */
} nuccFontTag;

static_assert(offsetof(nuccFontTag, vtable)         == 0x000, "nuccFontTag.vtable");
static_assert(offsetof(nuccFontTag, _base)           == 0x008, "nuccFontTag._base");
static_assert(offsetof(nuccFontTag, _tag_alloc_1)    == 0x0F0, "nuccFontTag._tag_alloc_1");
static_assert(offsetof(nuccFontTag, tag_ptr_f8)      == 0x0F8, "nuccFontTag.tag_ptr_f8");
static_assert(offsetof(nuccFontTag, tag_counter)     == 0x100, "nuccFontTag.tag_counter");
static_assert(offsetof(nuccFontTag, _tag_alloc_2)    == 0x108, "nuccFontTag._tag_alloc_2");
static_assert(offsetof(nuccFontTag, tag_flag_120)    == 0x120, "nuccFontTag.tag_flag_120");
static_assert(offsetof(nuccFontTag, ruby_enabled)    == 0x124, "nuccFontTag.ruby_enabled");
static_assert(offsetof(nuccFontTag, tag_flag_128)    == 0x128, "nuccFontTag.tag_flag_128");
static_assert(offsetof(nuccFontTag, ruby_color_r)    == 0x130, "nuccFontTag.ruby_color_r");
static_assert(offsetof(nuccFontTag, ruby_color_g)    == 0x134, "nuccFontTag.ruby_color_g");
static_assert(offsetof(nuccFontTag, ruby_color_b)    == 0x138, "nuccFontTag.ruby_color_b");
static_assert(offsetof(nuccFontTag, ruby_color_a)    == 0x13C, "nuccFontTag.ruby_color_a");
static_assert(offsetof(nuccFontTag, tag_id_ext)      == 0x140, "nuccFontTag.tag_id_ext");
static_assert(offsetof(nuccFontTag, tag_zero_144)    == 0x144, "nuccFontTag.tag_zero_144");
static_assert(offsetof(nuccFontTag, ruby_off1_x)     == 0x148, "nuccFontTag.ruby_off1_x");
static_assert(offsetof(nuccFontTag, ruby_off1_y)     == 0x14C, "nuccFontTag.ruby_off1_y");
static_assert(offsetof(nuccFontTag, ruby_off2_x)     == 0x150, "nuccFontTag.ruby_off2_x");
static_assert(offsetof(nuccFontTag, ruby_off2_y)     == 0x154, "nuccFontTag.ruby_off2_y");
static_assert(offsetof(nuccFontTag, tag_active)      == 0x158, "nuccFontTag.tag_active");
static_assert(offsetof(nuccFontTag, tag_enable_15c)  == 0x15C, "nuccFontTag.tag_enable_15c");
static_assert(offsetof(nuccFontTag, _remaining_tag)  == 0x160, "nuccFontTag._remaining_tag");

#endif /* CMN55_S2_H */