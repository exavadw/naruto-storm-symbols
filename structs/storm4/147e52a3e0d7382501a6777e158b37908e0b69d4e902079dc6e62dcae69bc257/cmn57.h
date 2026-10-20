/* cmn57 s4 - nuccLayer* struct group (NARUTO STORM 4 PC 1.09, NSUNS4_release.exe)
 * All layouts INFERRED from static decompilation. NOT CONFIRMED by runtime trace.
 * Sizes proven from operator_new / allocator size arguments in Create/ctor.
 * Field offsets from x64 decompile (image base 0x140000000).
 */
#ifndef CMN57_S4_H
#define CMN57_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nuccLayerBase: base class, size >= 0x28 (last field at 0x24).
 * PostEffectPreDraw inherits directly with proven size 0x28.
 * Vtable: PTR_FUN_14110d020 */
typedef struct __attribute__((packed)) nuccLayerBase {
    void     *vtable;      /* 0x00 */
    char      name[16];    /* 0x08 */
    uint32_t  layer_type;  /* 0x18 */
    uint16_t  flags;       /* 0x1C */
    uint8_t   flag_byte;   /* 0x1E */
    uint8_t   _pad_1f[1];  /* 0x1F */
    uint16_t  _pad_20;     /* 0x20 */
    uint16_t  _pad_22;     /* 0x22 */
    uint32_t  enabled;     /* 0x24 */
} nuccLayerBase;

static_assert(offsetof(nuccLayerBase, vtable)     == 0x00, "nuccLayerBase.vtable");
static_assert(offsetof(nuccLayerBase, name)        == 0x08, "nuccLayerBase.name");
static_assert(offsetof(nuccLayerBase, layer_type)  == 0x18, "nuccLayerBase.layer_type");
static_assert(offsetof(nuccLayerBase, flags)       == 0x1C, "nuccLayerBase.flags");
static_assert(offsetof(nuccLayerBase, flag_byte)   == 0x1E, "nuccLayerBase.flag_byte");
static_assert(offsetof(nuccLayerBase, _pad_1f)     == 0x1F, "nuccLayerBase._pad_1f");
static_assert(offsetof(nuccLayerBase, _pad_20)     == 0x20, "nuccLayerBase._pad_20");
static_assert(offsetof(nuccLayerBase, _pad_22)     == 0x22, "nuccLayerBase._pad_22");
static_assert(offsetof(nuccLayerBase, enabled)     == 0x24, "nuccLayerBase.enabled");

/* nuccLayer: inherits nuccLayerBase, size >= 0x50 (last field at 0x48).
 * PostEffect inherits Layer with proven size 0x58, one field at 0x50.
 * Vtable: PTR_FUN_141109a70 */
typedef struct __attribute__((packed)) nuccLayer {
    void     *vtable;            /* 0x00 */
    char      name[16];          /* 0x08 */
    uint32_t  layer_type;        /* 0x18 */
    uint16_t  flags;             /* 0x1C */
    uint8_t   flag_byte;         /* 0x1E */
    uint8_t   _pad_1f[1];        /* 0x1F */
    uint16_t  _pad_20;           /* 0x20 */
    uint16_t  _pad_22;           /* 0x22 */
    uint32_t  enabled;           /* 0x24 */
    void     *draw_command_list; /* 0x28 */
    uint64_t  _field_30;         /* 0x30 */
    uint64_t  _field_38;         /* 0x38 */
    uint32_t  _field_40_flags;   /* 0x40 */
    uint32_t  _pad_44;           /* 0x44 */
    void     *_self_ptr;         /* 0x48 */
} nuccLayer;

static_assert(offsetof(nuccLayer, vtable)            == 0x00, "nuccLayer.vtable");
static_assert(offsetof(nuccLayer, name)               == 0x08, "nuccLayer.name");
static_assert(offsetof(nuccLayer, layer_type)         == 0x18, "nuccLayer.layer_type");
static_assert(offsetof(nuccLayer, flags)              == 0x1C, "nuccLayer.flags");
static_assert(offsetof(nuccLayer, flag_byte)          == 0x1E, "nuccLayer.flag_byte");
static_assert(offsetof(nuccLayer, _pad_1f)            == 0x1F, "nuccLayer._pad_1f");
static_assert(offsetof(nuccLayer, _pad_20)            == 0x20, "nuccLayer._pad_20");
static_assert(offsetof(nuccLayer, _pad_22)            == 0x22, "nuccLayer._pad_22");
static_assert(offsetof(nuccLayer, enabled)            == 0x24, "nuccLayer.enabled");
static_assert(offsetof(nuccLayer, draw_command_list)  == 0x28, "nuccLayer.draw_command_list");
static_assert(offsetof(nuccLayer, _field_30)          == 0x30, "nuccLayer._field_30");
static_assert(offsetof(nuccLayer, _field_38)          == 0x38, "nuccLayer._field_38");
static_assert(offsetof(nuccLayer, _field_40_flags)    == 0x40, "nuccLayer._field_40_flags");
static_assert(offsetof(nuccLayer, _pad_44)            == 0x44, "nuccLayer._pad_44");
static_assert(offsetof(nuccLayer, _self_ptr)          == 0x48, "nuccLayer._self_ptr");

/* nuccLayerPostEffectPreDraw: inherits nuccLayerBase directly.
 * Size = 0x28 proven by operator_new(0x28) in Create (RVA 0xA189D0).
 * Vtable: PTR_FUN_14110e5f0 (ctor), PTR_FUN_141109a70 (dtor) */
typedef struct __attribute__((packed)) nuccLayerPostEffectPreDraw {
    void     *vtable;      /* 0x00 */
    char      name[16];    /* 0x08 */
    uint32_t  layer_type;  /* 0x18 */
    uint16_t  flags;       /* 0x1C */
    uint8_t   flag_byte;   /* 0x1E */
    uint8_t   _pad_1f[1];  /* 0x1F */
    uint16_t  _pad_20;     /* 0x20 */
    uint16_t  _pad_22;     /* 0x22 */
    uint32_t  enabled;     /* 0x24 */
} nuccLayerPostEffectPreDraw;

static_assert(offsetof(nuccLayerPostEffectPreDraw, vtable)     == 0x00, "PEPD.vtable");
static_assert(offsetof(nuccLayerPostEffectPreDraw, name)        == 0x08, "PEPD.name");
static_assert(offsetof(nuccLayerPostEffectPreDraw, layer_type)  == 0x18, "PEPD.layer_type");
static_assert(offsetof(nuccLayerPostEffectPreDraw, flags)       == 0x1C, "PEPD.flags");
static_assert(offsetof(nuccLayerPostEffectPreDraw, flag_byte)   == 0x1E, "PEPD.flag_byte");
static_assert(offsetof(nuccLayerPostEffectPreDraw, _pad_1f)     == 0x1F, "PEPD._pad_1f");
static_assert(offsetof(nuccLayerPostEffectPreDraw, _pad_20)     == 0x20, "PEPD._pad_20");
static_assert(offsetof(nuccLayerPostEffectPreDraw, _pad_22)     == 0x22, "PEPD._pad_22");
static_assert(offsetof(nuccLayerPostEffectPreDraw, enabled)     == 0x24, "PEPD.enabled");

/* nuccLayerPostEffect: inherits nuccLayer.
 * Size = 0x58 proven by operator_new(0x58) in Create (RVA 0xA18A20).
 * Vtable: PTR_FUN_141109950 */
typedef struct __attribute__((packed)) nuccLayerPostEffect {
    void     *vtable;            /* 0x00 */
    char      name[16];          /* 0x08 */
    uint32_t  layer_type;        /* 0x18 */
    uint16_t  flags;             /* 0x1C */
    uint8_t   flag_byte;         /* 0x1E */
    uint8_t   _pad_1f[1];        /* 0x1F */
    uint16_t  _pad_20;           /* 0x20 */
    uint16_t  _pad_22;           /* 0x22 */
    uint32_t  enabled;           /* 0x24 */
    void     *draw_command_list; /* 0x28 */
    uint64_t  _field_30;         /* 0x30 */
    uint64_t  _field_38;         /* 0x38 */
    uint32_t  _field_40_flags;   /* 0x40 */
    uint32_t  _pad_44;           /* 0x44 */
    void     *_self_ptr;         /* 0x48 */
    void     *render_texture;    /* 0x50 */
} nuccLayerPostEffect;

static_assert(offsetof(nuccLayerPostEffect, vtable)            == 0x00, "PE.vtable");
static_assert(offsetof(nuccLayerPostEffect, name)               == 0x08, "PE.name");
static_assert(offsetof(nuccLayerPostEffect, layer_type)         == 0x18, "PE.layer_type");
static_assert(offsetof(nuccLayerPostEffect, flags)              == 0x1C, "PE.flags");
static_assert(offsetof(nuccLayerPostEffect, flag_byte)          == 0x1E, "PE.flag_byte");
static_assert(offsetof(nuccLayerPostEffect, _pad_1f)            == 0x1F, "PE._pad_1f");
static_assert(offsetof(nuccLayerPostEffect, _pad_20)            == 0x20, "PE._pad_20");
static_assert(offsetof(nuccLayerPostEffect, _pad_22)            == 0x22, "PE._pad_22");
static_assert(offsetof(nuccLayerPostEffect, enabled)            == 0x24, "PE.enabled");
static_assert(offsetof(nuccLayerPostEffect, draw_command_list)  == 0x28, "PE.draw_command_list");
static_assert(offsetof(nuccLayerPostEffect, _field_30)          == 0x30, "PE._field_30");
static_assert(offsetof(nuccLayerPostEffect, _field_38)          == 0x38, "PE._field_38");
static_assert(offsetof(nuccLayerPostEffect, _field_40_flags)    == 0x40, "PE._field_40_flags");
static_assert(offsetof(nuccLayerPostEffect, _pad_44)            == 0x44, "PE._pad_44");
static_assert(offsetof(nuccLayerPostEffect, _self_ptr)          == 0x48, "PE._self_ptr");
static_assert(offsetof(nuccLayerPostEffect, render_texture)     == 0x50, "PE.render_texture");

/* nuccLayerManager: inherits nuccLayerList (inherits nuccLayerBase).
 * Size = 0xA0 proven by operator_new(0xa0) in Create.
 * Singleton global: DAT_1416b8260.
 * Vtable: PTR_FUN_14110c538 */
typedef struct __attribute__((packed)) nuccLayerManager {
    void     *vtable;                /* 0x00 */
    char      name[16];              /* 0x08 */
    uint32_t  layer_type;            /* 0x18 */
    uint16_t  flags;                 /* 0x1C */
    uint8_t   flag_byte;             /* 0x1E */
    uint8_t   _pad_1f[1];            /* 0x1F */
    uint16_t  _pad_20;               /* 0x20 */
    uint16_t  _pad_22;               /* 0x22 */
    uint32_t  enabled;               /* 0x24 */
    uint8_t   _layerlist_fields[40]; /* 0x28 */
    uint8_t   critical_section[80];  /* 0x50 */
} nuccLayerManager;

static_assert(offsetof(nuccLayerManager, vtable)              == 0x00, "LM.vtable");
static_assert(offsetof(nuccLayerManager, name)                 == 0x08, "LM.name");
static_assert(offsetof(nuccLayerManager, layer_type)           == 0x18, "LM.layer_type");
static_assert(offsetof(nuccLayerManager, flags)                == 0x1C, "LM.flags");
static_assert(offsetof(nuccLayerManager, flag_byte)            == 0x1E, "LM.flag_byte");
static_assert(offsetof(nuccLayerManager, _pad_1f)              == 0x1F, "LM._pad_1f");
static_assert(offsetof(nuccLayerManager, _pad_20)              == 0x20, "LM._pad_20");
static_assert(offsetof(nuccLayerManager, _pad_22)              == 0x22, "LM._pad_22");
static_assert(offsetof(nuccLayerManager, enabled)              == 0x24, "LM.enabled");
static_assert(offsetof(nuccLayerManager, _layerlist_fields)    == 0x28, "LM._layerlist_fields");
static_assert(offsetof(nuccLayerManager, critical_section)     == 0x50, "LM.critical_section");

/* Single-method Draw classes: typedef aliases to nuccLayer.
 * No unique fields observed beyond nuccLayer base.
 * Sizes unknown (>= 0x50). */
typedef nuccLayer nuccLayerOpaque;
typedef nuccLayer nuccLayerOpaqueClearZ;
typedef nuccLayer nuccLayerOutline;
typedef nuccLayer nuccLayerPostDecal;
typedef nuccLayer nuccLayerPostOutline;
typedef nuccLayer nuccLayerReduction;
typedef nuccLayer nuccLayerReduction2;
typedef nuccLayer nuccLayerRefraction;
typedef nuccLayer nuccLayerMotionBlur;

#endif /* CMN57_S4_H */