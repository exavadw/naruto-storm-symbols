/* cmn50.h — Common struct pre-decompile for build s4 (NARUTO STORM 4 PC 1.09, NSUNS4_release.exe)
 * Generated from the decompiler cache decompile cache + state_surface analysis.
 * All layouts INFERRED from static analysis; not CONFIRMED by runtime trace.
 * Sizes proven from factory FUN_140a344b0 allocation sizes where available.
 * Own-game naming: Storm 4 names only from s4 symbols/strings/code.
 * Offsets derived exclusively from s4 x64 decompile (image base 0x140000000).
 */
#ifndef CMN50_H
#define CMN50_H

#include <stdint.h>
#include <stddef.h>

/* ========================================================================
 * nuccColorFilterRadial — size 0x70 (112 bytes), PROVEN from factory FUN_140a344b0(0x70)
 * Vtable: PTR_FUN_141107b90 (s4-specific)
 * Constructor: nuccColorFilterRadial::nuccColorFilterRadial @ RVA 0xA345F0
 * Factory: FUN_140a344b0 (param_1==1 allocates 0x70 via FUN_140a017f0)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccColorFilterRadial {
    /* 0x00 */ void *vtable;                    /* PTR_FUN_141107b90 */
    /* 0x08 */ uint64_t field_08;               /* set to 0 in ctor */
    /* 0x10 */ uint32_t field_10;               /* set to 1 in ctor */
    /* 0x14 */ uint32_t enabled;                /* set to 1 in ctor */
    /* 0x18 */ uint32_t field_18;               /* set to 1 in ctor */
    /* 0x1C */ uint32_t _pad_1c;
    /* 0x20 */ float center_x;                  /* Vector2 sub-obj at param_1+4, init via FUN_140a2a1c0 */
    /* 0x24 */ float center_y;
    /* 0x28 */ float mid_x;                     /* Vector2 sub-obj at param_1+5, init via FUN_140a2a1c0 */
    /* 0x2C */ float mid_y;
    /* 0x30 */ uint64_t field_30;               /* set to 0 in ctor (param_1[6]) */
    /* 0x38 */ double field_38;                 /* 1.0 as double (param_1[7] = 0x3f80000000000000) */
    /* 0x40 */ uint32_t field_40;               /* set to 0 in ctor */
    /* 0x44 */ float alpha_inner;               /* 0x3f000000 = 0.5f */
    /* 0x48 */ uint32_t _pad_48;
    /* 0x4C */ float scale_x;                   /* 0x3f800000 = 1.0f (overwritten to 0x3e4ccccd = 0.2f) */
    /* 0x50 */ float alpha_outer;               /* 0x3f800000 = 1.0f */
    /* 0x54 */ float scale_y;                   /* 0x3f800000 = 1.0f */
    /* 0x58 */ float field_58;                  /* 0x3f800000 = 1.0f */
    /* 0x5C */ float color_intensity;           /* 0x3f800000 = 1.0f (overwritten to 0x3ecccccd = 0.4f) */
    /* 0x60 */ float alpha_base;                /* 0x3f000000 = 0.5f */
    /* 0x64 */ uint32_t sprite_alpha_blendtype; /* from FUN_140a8cee0(1) */
    /* 0x68 */ uint8_t _pad_68[8];              /* padding to 0x70 */
} nuccColorFilterRadial;

_Static_assert(offsetof(nuccColorFilterRadial, vtable) == 0x00, "nuccColorFilterRadial::vtable");
_Static_assert(offsetof(nuccColorFilterRadial, field_08) == 0x08, "nuccColorFilterRadial::field_08");
_Static_assert(offsetof(nuccColorFilterRadial, field_10) == 0x10, "nuccColorFilterRadial::field_10");
_Static_assert(offsetof(nuccColorFilterRadial, enabled) == 0x14, "nuccColorFilterRadial::enabled");
_Static_assert(offsetof(nuccColorFilterRadial, field_18) == 0x18, "nuccColorFilterRadial::field_18");
_Static_assert(offsetof(nuccColorFilterRadial, center_x) == 0x20, "nuccColorFilterRadial::center_x");
_Static_assert(offsetof(nuccColorFilterRadial, center_y) == 0x24, "nuccColorFilterRadial::center_y");
_Static_assert(offsetof(nuccColorFilterRadial, mid_x) == 0x28, "nuccColorFilterRadial::mid_x");
_Static_assert(offsetof(nuccColorFilterRadial, mid_y) == 0x2C, "nuccColorFilterRadial::mid_y");
_Static_assert(offsetof(nuccColorFilterRadial, field_30) == 0x30, "nuccColorFilterRadial::field_30");
_Static_assert(offsetof(nuccColorFilterRadial, field_38) == 0x38, "nuccColorFilterRadial::field_38");
_Static_assert(offsetof(nuccColorFilterRadial, field_40) == 0x40, "nuccColorFilterRadial::field_40");
_Static_assert(offsetof(nuccColorFilterRadial, alpha_inner) == 0x44, "nuccColorFilterRadial::alpha_inner");
_Static_assert(offsetof(nuccColorFilterRadial, scale_x) == 0x4C, "nuccColorFilterRadial::scale_x");
_Static_assert(offsetof(nuccColorFilterRadial, alpha_outer) == 0x50, "nuccColorFilterRadial::alpha_outer");
_Static_assert(offsetof(nuccColorFilterRadial, scale_y) == 0x54, "nuccColorFilterRadial::scale_y");
_Static_assert(offsetof(nuccColorFilterRadial, field_58) == 0x58, "nuccColorFilterRadial::field_58");
_Static_assert(offsetof(nuccColorFilterRadial, color_intensity) == 0x5C, "nuccColorFilterRadial::color_intensity");
_Static_assert(offsetof(nuccColorFilterRadial, alpha_base) == 0x60, "nuccColorFilterRadial::alpha_base");
_Static_assert(offsetof(nuccColorFilterRadial, sprite_alpha_blendtype) == 0x64, "nuccColorFilterRadial::sprite_alpha_blendtype");
_Static_assert(sizeof(nuccColorFilterRadial) == 0x70, "nuccColorFilterRadial size");

/* ========================================================================
 * nuccColorFilterDirectional — size 0x70 (112 bytes), PROVEN from factory FUN_140a344b0(0x70)
 * Vtable: PTR_FUN_14110b260 (s4-specific)
 * Constructor: nuccColorFilterDirectional::nuccColorFilterDirectional @ RVA 0xA56400
 * Factory: FUN_140a344b0 (param_1==2 allocates 0x70 via FUN_140a017f0)
 * Layout identical to Radial except no second Vector2 init call
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccColorFilterDirectional {
    /* 0x00 */ void *vtable;                    /* PTR_FUN_14110b260 */
    /* 0x08 */ uint64_t field_08;               /* set to 0 in ctor */
    /* 0x10 */ uint32_t field_10;               /* set to 1 in ctor */
    /* 0x14 */ uint32_t enabled;                /* set to 1 in ctor */
    /* 0x18 */ uint32_t field_18;               /* set to 1 in ctor */
    /* 0x1C */ uint32_t _pad_1c;
    /* 0x20 */ float direction_x;               /* Vector2 sub-obj at param_1+4, init via FUN_140a2a1c0 */
    /* 0x24 */ float direction_y;
    /* 0x28 */ uint64_t _pad_28;                /* no Vector2 at param_1+5 unlike Radial */
    /* 0x30 */ uint64_t field_30;               /* set to 0 in ctor (param_1[6]) */
    /* 0x38 */ double field_38;                 /* 1.0 as double (param_1[7] = 0x3f80000000000000) */
    /* 0x40 */ uint32_t field_40;               /* set to 0 in ctor */
    /* 0x44 */ float alpha_inner;               /* 0x3f000000 = 0.5f */
    /* 0x48 */ uint32_t _pad_48;
    /* 0x4C */ float scale_x;                   /* 0x3f800000 = 1.0f (overwritten to 0x3e4ccccd = 0.2f) */
    /* 0x50 */ float alpha_outer;               /* 0x3f800000 = 1.0f */
    /* 0x54 */ float scale_y;                   /* 0x3f800000 = 1.0f */
    /* 0x58 */ float field_58;                  /* 0x3f800000 = 1.0f */
    /* 0x5C */ float color_intensity;           /* 0x3f800000 = 1.0f (overwritten to 0x3ecccccd = 0.4f) */
    /* 0x60 */ float alpha_base;                /* 0x3f000000 = 0.5f */
    /* 0x64 */ uint32_t sprite_alpha_blendtype; /* from FUN_140a8cee0(1) */
    /* 0x68 */ uint8_t _pad_68[8];              /* padding to 0x70 */
} nuccColorFilterDirectional;

_Static_assert(offsetof(nuccColorFilterDirectional, vtable) == 0x00, "nuccColorFilterDirectional::vtable");
_Static_assert(offsetof(nuccColorFilterDirectional, field_08) == 0x08, "nuccColorFilterDirectional::field_08");
_Static_assert(offsetof(nuccColorFilterDirectional, field_10) == 0x10, "nuccColorFilterDirectional::field_10");
_Static_assert(offsetof(nuccColorFilterDirectional, enabled) == 0x14, "nuccColorFilterDirectional::enabled");
_Static_assert(offsetof(nuccColorFilterDirectional, field_18) == 0x18, "nuccColorFilterDirectional::field_18");
_Static_assert(offsetof(nuccColorFilterDirectional, direction_x) == 0x20, "nuccColorFilterDirectional::direction_x");
_Static_assert(offsetof(nuccColorFilterDirectional, direction_y) == 0x24, "nuccColorFilterDirectional::direction_y");
_Static_assert(offsetof(nuccColorFilterDirectional, field_30) == 0x30, "nuccColorFilterDirectional::field_30");
_Static_assert(offsetof(nuccColorFilterDirectional, field_38) == 0x38, "nuccColorFilterDirectional::field_38");
_Static_assert(offsetof(nuccColorFilterDirectional, field_40) == 0x40, "nuccColorFilterDirectional::field_40");
_Static_assert(offsetof(nuccColorFilterDirectional, alpha_inner) == 0x44, "nuccColorFilterDirectional::alpha_inner");
_Static_assert(offsetof(nuccColorFilterDirectional, scale_x) == 0x4C, "nuccColorFilterDirectional::scale_x");
_Static_assert(offsetof(nuccColorFilterDirectional, alpha_outer) == 0x50, "nuccColorFilterDirectional::alpha_outer");
_Static_assert(offsetof(nuccColorFilterDirectional, scale_y) == 0x54, "nuccColorFilterDirectional::scale_y");
_Static_assert(offsetof(nuccColorFilterDirectional, field_58) == 0x58, "nuccColorFilterDirectional::field_58");
_Static_assert(offsetof(nuccColorFilterDirectional, color_intensity) == 0x5C, "nuccColorFilterDirectional::color_intensity");
_Static_assert(offsetof(nuccColorFilterDirectional, alpha_base) == 0x60, "nuccColorFilterDirectional::alpha_base");
_Static_assert(offsetof(nuccColorFilterDirectional, sprite_alpha_blendtype) == 0x64, "nuccColorFilterDirectional::sprite_alpha_blendtype");
_Static_assert(sizeof(nuccColorFilterDirectional) == 0x70, "nuccColorFilterDirectional size");

/* ========================================================================
 * nuccColorFilterManager — size unknown, >= 0x48
 * Vtable: PTR_FUN_141107ae8 (s4-specific, from ctor at RVA 0xA33D30)
 * Constructor: nuccColorFilterManager::nuccColorFilterManager @ RVA 0xA33D30
 * Not independently heap-allocated; embedded in containing class.
 * Factory creates sub-types at param_1==0 (size 0x20), 3 (0x40), 4 (0x40).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccColorFilterManager {
    /* 0x00 */ void *vtable;                    /* PTR_FUN_141107ae8 */
    /* 0x08 */ uint8_t base_subobject[0x10];    /* initialized via FUN_140a01d10() */
    /* 0x18 */ uint8_t sub_object_18[0x28];     /* initialized via FUN_140a33cc0(param_1+3) */
    /* 0x40 */ int32_t field_40;                /* set to -1 (0xffffffff) in ctor */
    /* 0x44 */ int32_t active_filter_index;     /* set to 0 in ctor */
} nuccColorFilterManager;

_Static_assert(offsetof(nuccColorFilterManager, vtable) == 0x00, "nuccColorFilterManager::vtable");
_Static_assert(offsetof(nuccColorFilterManager, base_subobject) == 0x08, "nuccColorFilterManager::base_subobject");
_Static_assert(offsetof(nuccColorFilterManager, sub_object_18) == 0x18, "nuccColorFilterManager::sub_object_18");
_Static_assert(offsetof(nuccColorFilterManager, field_40) == 0x40, "nuccColorFilterManager::field_40");
_Static_assert(offsetof(nuccColorFilterManager, active_filter_index) == 0x44, "nuccColorFilterManager::active_filter_index");
/* No sizeof assert: size unproven, >= 0x48 */

/* ========================================================================
 * nuccChunkTrail — size unknown, >= 0x68
 * Vtable: not directly observed in decompiled methods (set by base class ctor)
 * Destructor: nuccChunkTrail::~nuccChunkTrail @ RVA 0xA669F0
 * Parse: nuccChunkTrail::Parse @ RVA 0xA66CC0 reveals header fields 0x10-0x36
 * Parse allocates arrays at 0x38 (count_14 * 0x70 element stride).
 * Not independently allocated via operator new; created by chunk factory.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccChunkTrail {
    /* 0x00 */ void *vtable;
    /* 0x08 */ uint64_t trail_index;            /* read in FinalizeParsing */
    /* 0x10 */ uint32_t header_field_10;        /* first ulong read in Parse, byteswapped */
    /* 0x14 */ uint16_t count_14;               /* ushort, byteswapped; loop count for array at 0x38 */
    /* 0x16 */ uint16_t field_16;               /* ushort, byteswapped */
    /* 0x18 */ uint32_t field_18;               /* ulong, byteswapped */
    /* 0x1C */ uint16_t count_1c;               /* ushort, byteswapped */
    /* 0x1E */ uint16_t field_1e;               /* ushort, byteswapped */
    /* 0x20 */ uint32_t field_20;               /* ulong, byteswapped */
    /* 0x24 */ uint16_t count_24;               /* ushort, byteswapped */
    /* 0x26 */ uint16_t field_26;               /* ushort, byteswapped */
    /* 0x28 */ uint32_t field_28;               /* ulong, byteswapped */
    /* 0x2C */ uint16_t field_2c;               /* ushort, byteswapped */
    /* 0x2E */ uint16_t field_2e;               /* ushort, byteswapped */
    /* 0x30 */ uint32_t field_30;               /* ulong, byteswapped */
    /* 0x34 */ uint16_t count_34;               /* ushort, byteswapped */
    /* 0x36 */ uint16_t count_36;               /* ushort, byteswapped */
    /* 0x38 */ uint64_t array_ptr_38;           /* dynamically allocated, element size 0x70, count = count_14 */
    /* 0x40 */ uint64_t array_ptr_40;           /* allocated in Parse second loop */
    /* 0x48 */ uint64_t array_ptr_48;           /* allocated in Parse second loop */
    /* 0x50 */ uint64_t array_ptr_50;           /* read in Parse inner loop */
    /* 0x58 */ uint64_t array_ptr_58;           /* allocated count_34 * 0x28 */
    /* 0x60 */ uint64_t array_ptr_60;           /* allocated count_36 * 4 */
} nuccChunkTrail;

_Static_assert(offsetof(nuccChunkTrail, vtable) == 0x00, "nuccChunkTrail::vtable");
_Static_assert(offsetof(nuccChunkTrail, trail_index) == 0x08, "nuccChunkTrail::trail_index");
_Static_assert(offsetof(nuccChunkTrail, header_field_10) == 0x10, "nuccChunkTrail::header_field_10");
_Static_assert(offsetof(nuccChunkTrail, count_14) == 0x14, "nuccChunkTrail::count_14");
_Static_assert(offsetof(nuccChunkTrail, field_16) == 0x16, "nuccChunkTrail::field_16");
_Static_assert(offsetof(nuccChunkTrail, field_18) == 0x18, "nuccChunkTrail::field_18");
_Static_assert(offsetof(nuccChunkTrail, count_1c) == 0x1C, "nuccChunkTrail::count_1c");
_Static_assert(offsetof(nuccChunkTrail, field_1e) == 0x1E, "nuccChunkTrail::field_1e");
_Static_assert(offsetof(nuccChunkTrail, field_20) == 0x20, "nuccChunkTrail::field_20");
_Static_assert(offsetof(nuccChunkTrail, count_24) == 0x24, "nuccChunkTrail::count_24");
_Static_assert(offsetof(nuccChunkTrail, field_26) == 0x26, "nuccChunkTrail::field_26");
_Static_assert(offsetof(nuccChunkTrail, field_28) == 0x28, "nuccChunkTrail::field_28");
_Static_assert(offsetof(nuccChunkTrail, field_2c) == 0x2C, "nuccChunkTrail::field_2c");
_Static_assert(offsetof(nuccChunkTrail, field_2e) == 0x2E, "nuccChunkTrail::field_2e");
_Static_assert(offsetof(nuccChunkTrail, field_30) == 0x30, "nuccChunkTrail::field_30");
_Static_assert(offsetof(nuccChunkTrail, count_34) == 0x34, "nuccChunkTrail::count_34");
_Static_assert(offsetof(nuccChunkTrail, count_36) == 0x36, "nuccChunkTrail::count_36");
_Static_assert(offsetof(nuccChunkTrail, array_ptr_38) == 0x38, "nuccChunkTrail::array_ptr_38");
_Static_assert(offsetof(nuccChunkTrail, array_ptr_40) == 0x40, "nuccChunkTrail::array_ptr_40");
_Static_assert(offsetof(nuccChunkTrail, array_ptr_48) == 0x48, "nuccChunkTrail::array_ptr_48");
_Static_assert(offsetof(nuccChunkTrail, array_ptr_50) == 0x50, "nuccChunkTrail::array_ptr_50");
_Static_assert(offsetof(nuccChunkTrail, array_ptr_58) == 0x58, "nuccChunkTrail::array_ptr_58");
_Static_assert(offsetof(nuccChunkTrail, array_ptr_60) == 0x60, "nuccChunkTrail::array_ptr_60");
/* No sizeof assert: size unproven, >= 0x68 */

/* ========================================================================
 * nuccCOLOR — value type (4 floats), NOT a heap-allocated class
 * No instance state beyond 4 floats. Methods operate on float* (value semantics).
 * Constructor: nuccCOLOR::nuccCOLOR @ RVA 0xA141A0 takes float* and uint RGBA,
 * writes param_1[0..3] = R,G,B,A as normalized floats.
 * The state_surface fields at 0x30+ belong to a CONTAINING class that
 * embeds nuccCOLOR as a member, not to nuccCOLOR itself.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCOLOR {
    float r;
    float g;
    float b;
    float a;
} nuccCOLOR;

_Static_assert(sizeof(nuccCOLOR) == 0x10, "nuccCOLOR size");

#endif /* CMN50_H */