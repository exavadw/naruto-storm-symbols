/* st4a14.h — Story struct group for NSUNS4 PC 1.09 (build s4)
 * All layouts INFERRED from static decompilation. No runtime confirmation.
 * Own-game names only (Storm 4 symbols/strings).
 * PC offsets only; Switch Trilogy is name source, never offset source.
 */
#ifndef ST4A14_H
#define ST4A14_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccSceneAdvMissionOutline
 * Size: 0x2D8 (proven by CreateInstance alloc at FUN_1406e4cb0)
 * Vtable: PTR_FUN_140ee8b30 (set in ctor at RVA 0x1D2A10)
 * Fields: 24 from state_surface + ctor analysis
 * Embedded sub-objects at 0x168..0x27F initialized via FUN_1401ca8f8
 *   (likely ccString or similar small-string type, 0x38 bytes each based
 *    on spacing: 0x1A0-0x168=0x38, 0x1D8-0x1A0=0x38, etc.)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccSceneAdvMissionOutline {
    /* 0x000 */ void *vtable;                     /* PTR_FUN_140ee8b30 */
    /* 0x008 */ uint8_t _pad_008[0x120];          /* base class / vtable padding to 0x128 */

    /* 0x128 */ uint32_t field_128;               /* *(undefined4*)(p+0x25)=0; init zero */
    /* 0x12C */ uint8_t _pad_12c[4];              /* align to 0x130 */

    /* 0x130 */ uint64_t field_130;               /* p[0x26]=0; rw, high conf */
    /* 0x138 */ uint64_t field_138;               /* p[0x27]=0 */
    /* 0x140 */ uint64_t field_140;               /* p[0x28]=0 */
    /* 0x148 */ uint64_t field_148;               /* p[0x29]=event_handle?; rw */
    /* 0x150 */ uint64_t field_150;               /* p[0x2a]=0 */
    /* 0x158 */ uint64_t field_158;               /* p[0x2b]=0 */
    /* 0x160 */ uint64_t field_160;               /* p[0x2c]=0 */

    /* 0x168 */ uint8_t sub_obj_168[0x38];        /* FUN_1401ca8f8(p+0x2d); embedded string? */
    /* 0x1A0 */ uint8_t sub_obj_1a0[0x38];        /* FUN_1401ca8f8(p+0x34); embedded string? */
    /* 0x1D8 */ uint8_t sub_obj_1d8[0x38];        /* FUN_1401ca8f8(p+0x3b); embedded string? */
    /* 0x210 */ uint8_t sub_obj_210[0x38];        /* FUN_1401ca8f8(p+0x42); embedded string? */
    /* 0x248 */ uint8_t sub_obj_248[0x38];        /* FUN_1401ca8f8(p+0x49); embedded string? */

    /* 0x280 */ uint64_t field_280;               /* p[0x50]=0 */
    /* 0x288 */ uint64_t field_288;               /* p[0x51]=0 */
    /* 0x290 */ uint64_t field_290;               /* p[0x52]=0 */
    /* 0x298 */ uint64_t field_298;               /* p[0x53]=0 */
    /* 0x2A0 */ uint64_t field_2a0;               /* p[0x54]=0; size [4,8] ambiguous */
    /* 0x2A8 */ uint32_t field_2a8;               /* *(u4*)(p+0x55)=0xffffffff; sentinel */
    /* 0x2AC */ uint64_t field_2ac;               /* *(u8*)(p+0x2ac)=0 */
    /* 0x2B4 */ uint64_t field_2b4;               /* *(u8*)(p+0x2b4)=0 */
    /* 0x2BC */ uint8_t _pad_2bc[8];              /* gap to 0x2C4 */
    /* 0x2C4 */ uint64_t field_2c4;               /* *(u8*)(p+0x2c4)=0 */
    /* 0x2CC */ uint32_t field_2cc;               /* *(u4*)(p+0x2cc)=0 */
    /* 0x2D0 */ void *field_2d0;                  /* p[0x5a]=alloc(0x30); heap ptr */
    /* 0x2D8 */                                   /* end of object */
} ccSceneAdvMissionOutline;

static_assert(offsetof(ccSceneAdvMissionOutline, vtable)      == 0x000, "vtable");
static_assert(offsetof(ccSceneAdvMissionOutline, field_128)   == 0x128, "field_128");
static_assert(offsetof(ccSceneAdvMissionOutline, field_130)   == 0x130, "field_130");
static_assert(offsetof(ccSceneAdvMissionOutline, field_138)   == 0x138, "field_138");
static_assert(offsetof(ccSceneAdvMissionOutline, field_140)   == 0x140, "field_140");
static_assert(offsetof(ccSceneAdvMissionOutline, field_148)   == 0x148, "field_148");
static_assert(offsetof(ccSceneAdvMissionOutline, field_150)   == 0x150, "field_150");
static_assert(offsetof(ccSceneAdvMissionOutline, field_158)   == 0x158, "field_158");
static_assert(offsetof(ccSceneAdvMissionOutline, field_160)   == 0x160, "field_160");
static_assert(offsetof(ccSceneAdvMissionOutline, sub_obj_168) == 0x168, "sub_obj_168");
static_assert(offsetof(ccSceneAdvMissionOutline, sub_obj_1a0) == 0x1A0, "sub_obj_1a0");
static_assert(offsetof(ccSceneAdvMissionOutline, sub_obj_1d8) == 0x1D8, "sub_obj_1d8");
static_assert(offsetof(ccSceneAdvMissionOutline, sub_obj_210) == 0x210, "sub_obj_210");
static_assert(offsetof(ccSceneAdvMissionOutline, sub_obj_248) == 0x248, "sub_obj_248");
static_assert(offsetof(ccSceneAdvMissionOutline, field_280)   == 0x280, "field_280");
static_assert(offsetof(ccSceneAdvMissionOutline, field_288)   == 0x288, "field_288");
static_assert(offsetof(ccSceneAdvMissionOutline, field_290)   == 0x290, "field_290");
static_assert(offsetof(ccSceneAdvMissionOutline, field_298)   == 0x298, "field_298");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2a0)   == 0x2A0, "field_2a0");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2a8)   == 0x2A8, "field_2a8");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2ac)   == 0x2AC, "field_2ac");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2b4)   == 0x2B4, "field_2b4");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2c4)   == 0x2C4, "field_2c4");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2cc)   == 0x2CC, "field_2cc");
static_assert(offsetof(ccSceneAdvMissionOutline, field_2d0)   == 0x2D0, "field_2d0");
static_assert(sizeof(ccSceneAdvMissionOutline)                == 0x2D8, "size");

#endif /* ST4A14_H */