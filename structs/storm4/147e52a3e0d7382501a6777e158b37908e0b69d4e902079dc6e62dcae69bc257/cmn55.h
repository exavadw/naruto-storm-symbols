/* cmn55 struct group — Storm 4 (s4) reconstruction
 * Build: s4 (NSUNS4_release.exe, x64, image base 0x140000000, SHA 147e52a3e0d7)
 * Status: INFERRED (static analysis only; no runtime confirmation)
 * All offsets derived from s4 PC x64 decompilation.
 * Names from s4 own symbols/strings; cross-game names marked where applicable.
 */
#ifndef CMN55_S4_H
#define CMN55_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── nuccFontRubyParam ─── size >= 0x30, vtable PTR_FUN_140fba5b8 */
typedef struct __attribute__((packed)) {
    void     *vtable;           /* 0x00 */
    float     position_x;       /* 0x08 ctor: via FUN_140a2a330 */
    float     position_y;       /* 0x0C ctor: via FUN_140a2a330 */
    float     offset_x;         /* 0x10 ctor: via FUN_140a2a1c0 */
    float     offset_y;         /* 0x14 ctor: via FUN_140a2a1c0 */
    float     scale_x;          /* 0x18 ctor: 0 (param_1[1]=0) */
    float     scale_y;          /* 0x1C ctor: via FUN_140a2a330 */
    int32_t   flags;            /* 0x20 ctor: param_1[4]=0 */
    int32_t   unknown_24;       /* 0x24 ctor: *(param_1+5)=0 */
    int32_t   unknown_28;       /* 0x28 gap */
    float     scale_factor;     /* 0x2C ctor: 1.0f (0x3f800000) */
} s4_nuccFontRubyParam;

static_assert(offsetof(s4_nuccFontRubyParam, vtable) == 0x00, "nuccFontRubyParam.vtable");
static_assert(offsetof(s4_nuccFontRubyParam, position_x) == 0x08, "nuccFontRubyParam.position_x");
static_assert(offsetof(s4_nuccFontRubyParam, position_y) == 0x0C, "nuccFontRubyParam.position_y");
static_assert(offsetof(s4_nuccFontRubyParam, offset_x) == 0x10, "nuccFontRubyParam.offset_x");
static_assert(offsetof(s4_nuccFontRubyParam, offset_y) == 0x14, "nuccFontRubyParam.offset_y");
static_assert(offsetof(s4_nuccFontRubyParam, scale_x) == 0x18, "nuccFontRubyParam.scale_x");
static_assert(offsetof(s4_nuccFontRubyParam, scale_y) == 0x1C, "nuccFontRubyParam.scale_y");
static_assert(offsetof(s4_nuccFontRubyParam, flags) == 0x20, "nuccFontRubyParam.flags");
static_assert(offsetof(s4_nuccFontRubyParam, unknown_24) == 0x24, "nuccFontRubyParam.unknown_24");
static_assert(offsetof(s4_nuccFontRubyParam, unknown_28) == 0x28, "nuccFontRubyParam.unknown_28");
static_assert(offsetof(s4_nuccFontRubyParam, scale_factor) == 0x2C, "nuccFontRubyParam.scale_factor");

/* ─── nuccFont2ParamManager ─── size PROVEN 0x98, vtable from ctor chain */
/* Size proof: FUN_140a8db40 (Initialize) calls FUN_140a017f0(0x98, ...) */
typedef struct __attribute__((packed)) {
    void     *vtable;           /* 0x00 */
    uint8_t   _pool_data[0x58]; /* 0x08 pool management region */
    uint8_t   _critsec_60[0x18];/* 0x60 critsec init */
    void     *ptr_78;           /* 0x78 slot */
    uint8_t   _gap_80[0x10];    /* 0x80 gap */
    uint8_t   _critsec_90[0x08];/* 0x90 critsec tail */
} s4_nuccFont2ParamManager;

static_assert(sizeof(s4_nuccFont2ParamManager) == 0x98, "nuccFont2ParamManager size proven 0x98");
static_assert(offsetof(s4_nuccFont2ParamManager, vtable) == 0x00, "Manager.vtable");
static_assert(offsetof(s4_nuccFont2ParamManager, _pool_data) == 0x08, "Manager._pool_data");
static_assert(offsetof(s4_nuccFont2ParamManager, _critsec_60) == 0x60, "Manager._critsec_60");
static_assert(offsetof(s4_nuccFont2ParamManager, ptr_78) == 0x78, "Manager.ptr_78");
static_assert(offsetof(s4_nuccFont2ParamManager, _gap_80) == 0x80, "Manager._gap_80");
static_assert(offsetof(s4_nuccFont2ParamManager, _critsec_90) == 0x90, "Manager._critsec_90");

/* ─── nuccFont2Param ─── size PROVEN 0x228, opaque body */
/* Size proof: FUN_140a8d870 (PoolAllocation::Create) allocates param_2 * 0x228;
   FUN_140a8dc20 (New) calls FUN_140a017f0(0x228, ...) */
typedef struct __attribute__((packed)) {
    uint8_t   _opaque[0x224];   /* 0x000 opaque body */
    int32_t   type_224;         /* 0x224 SetType writes here */
} s4_nuccFont2Param;

static_assert(sizeof(s4_nuccFont2Param) == 0x228, "nuccFont2Param size proven 0x228");
static_assert(offsetof(s4_nuccFont2Param, _opaque) == 0x000, "Param._opaque");
static_assert(offsetof(s4_nuccFont2Param, type_224) == 0x224, "Param.type_224");

/* ─── nuccFont2 ─── size >= 0x100, vtable PTR_FUN_141108720 */
/* No explicit allocator size found. Last named field at 0xEC; vtable dispatch
   observed up to +0x200 in state_surface. Size unproven, >= 0x100. */
typedef struct __attribute__((packed)) {
    void     *vtable;           /* 0x00 PTR_FUN_141108720 */
    uint8_t   _base_init[0x18]; /* 0x08 slots 1-3 zeroed in ctor */
    uint8_t   _block_alloc[0x18];/* 0x20 BlockAllocator head; grow threshold 0x400 */
    int32_t   init_flag_38;     /* 0x38 slot 7 = 1 */
    int32_t   draw_mode_a;      /* 0x3C ctor: 1; DrawCore checks == 1 */
    int32_t   init_flag_40;     /* 0x40 slot 8 = 1 */
    int32_t   draw_mode_b;      /* 0x44 ctor: 1; DrawCore checks == 1 */
    uint8_t   _gap_48[0x0C];    /* 0x48 gap to scale_x */
    float     scale_x;          /* 0x54 1.0f */
    float     scale_y;          /* 0x58 1.0f */
    float     scale_z;          /* 0x5C 1.0f */
    float     vec_60[2];        /* 0x60 vector init */
    float     value_68;         /* 0x68 1.0f */
    float     vec_6c[2];        /* 0x6C vector init */
    float     vec_74[2];        /* 0x74 vector init */
    float     vec_7c[2];        /* 0x7C vector init */
    int64_t   flag_84;          /* 0x84 ctor: 1 */
    int32_t   counter_8c;       /* 0x8C ctor: 0 */
    int32_t   tag_id;           /* 0x90 ctor: 0xe61 */
    int32_t   draw_enable;      /* 0x94 ctor: 0; DrawCore checks == 0 */
    uint8_t   _sub_alloc[0x28]; /* 0x98 sub-allocator FUN_140a0d810 */
    uint8_t   _gap_c0[0x18];    /* 0xC0 virtual dispatch region */
    float     color_r;          /* 0xD8 1.0f; DrawCore reads */
    int32_t   _pad_dc;          /* 0xDC ctor: 0 */
    uint8_t   _gap_e0[0x04];    /* 0xE0 gap */
    int64_t   ptr_e4;           /* 0xE4 ctor: 0 */
    int32_t   print_flag;       /* 0xEC ctor: 0; Print sets */
    uint8_t   _remaining[0x10]; /* 0xF0 vtable calls at 0x100..0x200; size unproven */
} s4_nuccFont2;

static_assert(offsetof(s4_nuccFont2, vtable) == 0x00, "nuccFont2.vtable");
static_assert(offsetof(s4_nuccFont2, _base_init) == 0x08, "nuccFont2._base_init");
static_assert(offsetof(s4_nuccFont2, _block_alloc) == 0x20, "nuccFont2._block_alloc");
static_assert(offsetof(s4_nuccFont2, init_flag_38) == 0x38, "nuccFont2.init_flag_38");
static_assert(offsetof(s4_nuccFont2, draw_mode_a) == 0x3C, "nuccFont2.draw_mode_a");
static_assert(offsetof(s4_nuccFont2, init_flag_40) == 0x40, "nuccFont2.init_flag_40");
static_assert(offsetof(s4_nuccFont2, draw_mode_b) == 0x44, "nuccFont2.draw_mode_b");
static_assert(offsetof(s4_nuccFont2, _gap_48) == 0x48, "nuccFont2._gap_48");
static_assert(offsetof(s4_nuccFont2, scale_x) == 0x54, "nuccFont2.scale_x");
static_assert(offsetof(s4_nuccFont2, scale_y) == 0x58, "nuccFont2.scale_y");
static_assert(offsetof(s4_nuccFont2, scale_z) == 0x5C, "nuccFont2.scale_z");
static_assert(offsetof(s4_nuccFont2, vec_60) == 0x60, "nuccFont2.vec_60");
static_assert(offsetof(s4_nuccFont2, value_68) == 0x68, "nuccFont2.value_68");
static_assert(offsetof(s4_nuccFont2, vec_6c) == 0x6C, "nuccFont2.vec_6c");
static_assert(offsetof(s4_nuccFont2, vec_74) == 0x74, "nuccFont2.vec_74");
static_assert(offsetof(s4_nuccFont2, vec_7c) == 0x7C, "nuccFont2.vec_7c");
static_assert(offsetof(s4_nuccFont2, flag_84) == 0x84, "nuccFont2.flag_84");
static_assert(offsetof(s4_nuccFont2, counter_8c) == 0x8C, "nuccFont2.counter_8c");
static_assert(offsetof(s4_nuccFont2, tag_id) == 0x90, "nuccFont2.tag_id");
static_assert(offsetof(s4_nuccFont2, draw_enable) == 0x94, "nuccFont2.draw_enable");
static_assert(offsetof(s4_nuccFont2, _sub_alloc) == 0x98, "nuccFont2._sub_alloc");
static_assert(offsetof(s4_nuccFont2, _gap_c0) == 0xC0, "nuccFont2._gap_c0");
static_assert(offsetof(s4_nuccFont2, color_r) == 0xD8, "nuccFont2.color_r");
static_assert(offsetof(s4_nuccFont2, _pad_dc) == 0xDC, "nuccFont2._pad_dc");
static_assert(offsetof(s4_nuccFont2, _gap_e0) == 0xE0, "nuccFont2._gap_e0");
static_assert(offsetof(s4_nuccFont2, ptr_e4) == 0xE4, "nuccFont2.ptr_e4");
static_assert(offsetof(s4_nuccFont2, print_flag) == 0xEC, "nuccFont2.print_flag");
static_assert(offsetof(s4_nuccFont2, _remaining) == 0xF0, "nuccFont2._remaining");

/* ─── nuccFontTag ─── inherits nuccFont2, size >= 0x2A0, vtable PTR_FUN_1412e5258 */
/* No explicit allocator size found. Extension fields reach 0x15C; vtable calls
   at +0x240 and +0x280 in state_surface. Size unproven, >= 0x2A0. */
typedef struct __attribute__((packed)) {
    void     *vtable;           /* 0x000 PTR_FUN_1412e5258 overrides nuccFont2 */
    uint8_t   _base[0xE8];      /* 0x008 inherited nuccFont2 fields 0x08..0xEF */
    uint8_t   _tag_alloc_1[0x08];/* 0x0F0 allocator */
    void     *tag_ptr_f8;       /* 0x0F8 ExecTag reads */
    int64_t   tag_counter;      /* 0x100 ctor: 0 */
    uint8_t   _tag_alloc_2[0x18];/* 0x108 allocator */
    int32_t   tag_flag_120;     /* 0x120 ctor: 0; ExecTag writes 1 */
    int32_t   ruby_enabled;     /* 0x124 ctor: 1; gates ruby rendering */
    int32_t   tag_flag_128;     /* 0x128 ctor: 1 */
    uint8_t   _gap_12c[0x04];   /* 0x12C padding */
    float     ruby_color_r;     /* 0x130 1.0f; ExecTag reads */
    float     ruby_color_g;     /* 0x134 1.0f; ExecTag reads */
    float     ruby_color_b;     /* 0x138 1.0f; ExecTag reads */
    float     ruby_color_a;     /* 0x13C 1.0f; ExecTag reads */
    int32_t   tag_id_ext;       /* 0x140 ctor: 0xe61 */
    int32_t   tag_zero_144;     /* 0x144 ctor: 0 */
    float     ruby_off1[2];     /* 0x148 vector */
    float     ruby_off2[2];     /* 0x150 vector */
    int32_t   tag_active;       /* 0x158 ctor: 1; ExecTag checks != 0 */
    int32_t   tag_enable_15c;   /* 0x15C ctor: 1; ExecTag checks != 0 */
    uint8_t   _remaining_tag[0x140];/* 0x160 vtable calls at +0x240,+0x280; size unproven >= 0x2A0 */
} s4_nuccFontTag;

static_assert(offsetof(s4_nuccFontTag, vtable) == 0x000, "nuccFontTag.vtable");
static_assert(offsetof(s4_nuccFontTag, _base) == 0x008, "nuccFontTag._base");
static_assert(offsetof(s4_nuccFontTag, _tag_alloc_1) == 0x0F0, "nuccFontTag._tag_alloc_1");
static_assert(offsetof(s4_nuccFontTag, tag_ptr_f8) == 0x0F8, "nuccFontTag.tag_ptr_f8");
static_assert(offsetof(s4_nuccFontTag, tag_counter) == 0x100, "nuccFontTag.tag_counter");
static_assert(offsetof(s4_nuccFontTag, _tag_alloc_2) == 0x108, "nuccFontTag._tag_alloc_2");
static_assert(offsetof(s4_nuccFontTag, tag_flag_120) == 0x120, "nuccFontTag.tag_flag_120");
static_assert(offsetof(s4_nuccFontTag, ruby_enabled) == 0x124, "nuccFontTag.ruby_enabled");
static_assert(offsetof(s4_nuccFontTag, tag_flag_128) == 0x128, "nuccFontTag.tag_flag_128");
static_assert(offsetof(s4_nuccFontTag, _gap_12c) == 0x12C, "nuccFontTag._gap_12c");
static_assert(offsetof(s4_nuccFontTag, ruby_color_r) == 0x130, "nuccFontTag.ruby_color_r");
static_assert(offsetof(s4_nuccFontTag, ruby_color_g) == 0x134, "nuccFontTag.ruby_color_g");
static_assert(offsetof(s4_nuccFontTag, ruby_color_b) == 0x138, "nuccFontTag.ruby_color_b");
static_assert(offsetof(s4_nuccFontTag, ruby_color_a) == 0x13C, "nuccFontTag.ruby_color_a");
static_assert(offsetof(s4_nuccFontTag, tag_id_ext) == 0x140, "nuccFontTag.tag_id_ext");
static_assert(offsetof(s4_nuccFontTag, tag_zero_144) == 0x144, "nuccFontTag.tag_zero_144");
static_assert(offsetof(s4_nuccFontTag, ruby_off1) == 0x148, "nuccFontTag.ruby_off1");
static_assert(offsetof(s4_nuccFontTag, ruby_off2) == 0x150, "nuccFontTag.ruby_off2");
static_assert(offsetof(s4_nuccFontTag, tag_active) == 0x158, "nuccFontTag.tag_active");
static_assert(offsetof(s4_nuccFontTag, tag_enable_15c) == 0x15C, "nuccFontTag.tag_enable_15c");
static_assert(offsetof(s4_nuccFontTag, _remaining_tag) == 0x160, "nuccFontTag._remaining_tag");

#endif /* CMN55_S4_H */