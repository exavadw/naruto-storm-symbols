/* cmn57.h — nuccLayer* struct group for NARUTO STORM 1 PC (s1, NSUNS1.exe)
 * All layouts INFERRED from static decompilation of build s1 (sha 10231093af9c).
 * NOT CONFIRMED by runtime trace. Field names from s1 symbols/strings only.
 * Sizes proven from ccFileLoadListForUi::LoadTh allocation arguments where available.
 */
#ifndef CMN57_H
#define CMN57_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for opaque pointer types */
typedef void *nuccView_ptr;
typedef void *nuccRenderTexture_ptr;

/* ========================================================================
 * nuccLayerBase — base class for all nucc layers
 * Vtable: PTR_FUN_14073f3d8 (set in ctor)
 * Size: unknown, >= 0x28 (last proven field at 0x24 is uint32)
 * Evidence: nuccLayerBase::nuccLayerBase (RVA 0x488A90)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerBase {
    /* 0x00 */ void *vtable;                          /* set to &PTR_FUN_14073f3d8 in ctor */
    /* 0x08 */ char name[16];                         /* copied from param_2 in ctor loop */
    /* 0x18 */ uint32_t layer_type;                   /* param_3 stored at *(param_1+3)=offset 0x18 */
    /* 0x1C */ uint16_t flags;                        /* zeroed in ctor: *(param_1+0x1c)=0 */
    /* 0x1E */ uint8_t flag_byte;                     /* zeroed in ctor: *(param_1+0x1e)=0 */
    /* 0x1F */ uint8_t _pad_1f[1];                    /* explicit padding */
    /* 0x20 */ uint16_t _pad_20;                      /* zeroed in ctor: *(param_1+4)=0 → offset 0x20 */
    /* 0x22 */ uint16_t _pad_22;                      /* explicit padding */
    /* 0x24 */ uint32_t enabled;                      /* set to 1 in ctor: *(param_1+0x24)=1 */
} nuccLayerBase;
static_assert(offsetof(nuccLayerBase, vtable) == 0x00, "nuccLayerBase.vtable");
static_assert(offsetof(nuccLayerBase, name) == 0x08, "nuccLayerBase.name");
static_assert(offsetof(nuccLayerBase, layer_type) == 0x18, "nuccLayerBase.layer_type");
static_assert(offsetof(nuccLayerBase, flags) == 0x1C, "nuccLayerBase.flags");
static_assert(offsetof(nuccLayerBase, flag_byte) == 0x1E, "nuccLayerBase.flag_byte");
static_assert(offsetof(nuccLayerBase, enabled) == 0x24, "nuccLayerBase.enabled");

/* ========================================================================
 * nuccLayer — extends nuccLayerBase, adds draw command list management
 * Vtable: PTR_FUN_140737470 (set in ctor, overrides nuccLayerBase vtable)
 * Size: unknown, >= 0x40 (last proven field at 0x3c is uint32)
 * Evidence: nuccLayer::nuccLayer (RVA 0x48C010)
 * Inherits: nuccLayerBase (first 0x28 bytes)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayer {
    /* Base: nuccLayerBase (0x00–0x27) */
    /* 0x00 */ void *vtable;                          /* overridden to &PTR_FUN_140737470 */
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t layer_type;
    /* 0x1C */ uint16_t flags;
    /* 0x1E */ uint8_t flag_byte;
    /* 0x1F */ uint8_t _pad_1f[1];
    /* 0x20 */ uint16_t _pad_20;
    /* 0x22 */ uint16_t _pad_22;
    /* 0x24 */ uint32_t enabled;
    /* End of nuccLayerBase */
    /* 0x28 */ void *draw_command_list;               /* param_3 stored at param_1[5]=offset 0x28 */
    /* 0x30 */ uint64_t _field_30;                    /* param_1[6] zeroed */
    /* 0x38 */ uint64_t _field_38;                    /* param_1[7] zeroed */
    /* 0x40 */ uint32_t _field_34_flags;              /* computed from fields at 0x34,0x38 → stored at 0x3c */
    /* 0x44 */ uint32_t _pad_44;                      /* explicit padding */
    /* 0x48 */ void *_self_ptr;                       /* param_1[9] = &param_1[8], self-referential */
} nuccLayer;
static_assert(offsetof(nuccLayer, vtable) == 0x00, "nuccLayer.vtable");
static_assert(offsetof(nuccLayer, name) == 0x08, "nuccLayer.name");
static_assert(offsetof(nuccLayer, layer_type) == 0x18, "nuccLayer.layer_type");
static_assert(offsetof(nuccLayer, flags) == 0x1C, "nuccLayer.flags");
static_assert(offsetof(nuccLayer, enabled) == 0x24, "nuccLayer.enabled");
static_assert(offsetof(nuccLayer, draw_command_list) == 0x28, "nuccLayer.draw_command_list");
static_assert(offsetof(nuccLayer, _field_30) == 0x30, "nuccLayer._field_30");
static_assert(offsetof(nuccLayer, _field_38) == 0x38, "nuccLayer._field_38");
static_assert(offsetof(nuccLayer, _field_34_flags) == 0x40, "nuccLayer._field_34_flags");
static_assert(offsetof(nuccLayer, _self_ptr) == 0x48, "nuccLayer._self_ptr");

/* ========================================================================
 * nuccLayerPostEffectPreDraw — pre-draw post-effect layer
 * Vtable: PTR_FUN_14073f8b8 (set in ctor)
 * Size: 0x28 (proven from LoadTh(0x28,...) in Create, RVA 0x49FCD0)
 * Evidence: nuccLayerPostEffectPreDraw::nuccLayerPostEffectPreDraw (RVA 0x4FA9A0)
 * Inherits: nuccLayerBase (not nuccLayer — calls nuccLayerBase::nuccLayerBase directly)
 * Note: size 0x28 matches nuccLayerBase exactly; no additional fields beyond base.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerPostEffectPreDraw {
    /* 0x00 */ void *vtable;                          /* set to &PTR_FUN_14073f8b8 */
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t layer_type;
    /* 0x1C */ uint16_t flags;
    /* 0x1E */ uint8_t flag_byte;
    /* 0x1F */ uint8_t _pad_1f[1];
    /* 0x20 */ uint16_t _pad_20;
    /* 0x22 */ uint16_t _pad_22;
    /* 0x24 */ uint32_t enabled;
} nuccLayerPostEffectPreDraw;
static_assert(sizeof(nuccLayerPostEffectPreDraw) == 0x28, "nuccLayerPostEffectPreDraw size");
static_assert(offsetof(nuccLayerPostEffectPreDraw, vtable) == 0x00, "nuccLayerPostEffectPreDraw.vtable");
static_assert(offsetof(nuccLayerPostEffectPreDraw, flags) == 0x1C, "nuccLayerPostEffectPreDraw.flags");
static_assert(offsetof(nuccLayerPostEffectPreDraw, enabled) == 0x24, "nuccLayerPostEffectPreDraw.enabled");

/* ========================================================================
 * nuccLayerPostEffect — post-effect rendering layer with render texture
 * Vtable: PTR_FUN_14073f9f8 (set in ctor)
 * Size: 0x58 (proven from LoadTh(0x58,...) in Create, RVA 0x49FC80)
 * Evidence: nuccLayerPostEffect::nuccLayerPostEffect (RVA 0x4FBB20)
 * Inherits: nuccLayer (calls nuccLayer::nuccLayer)
 * Additional field: render_texture handle at param_1[10] = offset 0x50
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerPostEffect {
    /* Base: nuccLayer (0x00–0x4F) */
    /* 0x00 */ void *vtable;                          /* overridden to &PTR_FUN_14073f9f8 */
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t layer_type;
    /* 0x1C */ uint16_t flags;
    /* 0x1E */ uint8_t flag_byte;
    /* 0x1F */ uint8_t _pad_1f[1];
    /* 0x20 */ uint16_t _pad_20;
    /* 0x22 */ uint16_t _pad_22;
    /* 0x24 */ uint32_t enabled;
    /* 0x28 */ void *draw_command_list;
    /* 0x30 */ uint64_t _field_30;
    /* 0x38 */ uint64_t _field_38;
    /* 0x40 */ uint32_t _field_34_flags;
    /* 0x44 */ uint32_t _pad_44;
    /* 0x48 */ void *_self_ptr;
    /* End of nuccLayer base (0x50) */
    /* 0x50 */ nuccRenderTexture_ptr render_texture;  /* param_1[10] set in ctor via AddRenderTextureNormal */
    /* 0x58 — end of allocation */
} nuccLayerPostEffect;
static_assert(sizeof(nuccLayerPostEffect) == 0x58, "nuccLayerPostEffect size");
static_assert(offsetof(nuccLayerPostEffect, vtable) == 0x00, "nuccLayerPostEffect.vtable");
static_assert(offsetof(nuccLayerPostEffect, flags) == 0x1C, "nuccLayerPostEffect.flags");
static_assert(offsetof(nuccLayerPostEffect, draw_command_list) == 0x28, "nuccLayerPostEffect.draw_command_list");
static_assert(offsetof(nuccLayerPostEffect, render_texture) == 0x50, "nuccLayerPostEffect.render_texture");

/* ========================================================================
 * nuccLayerManager — singleton manager for all nucc layers
 * Vtable: PTR_FUN_14073caa8 (set in Create after nuccLayerList ctor)
 * Size: 0xA0 (proven from LoadTh(0xa0,...) in Create, RVA 0x4D5B20)
 * Evidence: nuccLayerManager::Create (RVA 0x4D5B20)
 * Inherits: nuccLayerList (inferred; calls nuccLayerList::nuccLayerList then overrides vtable)
 * Embedded: nuccCriticalSection at puVar1+10 = offset 0x50
 * Global: DAT_1408c6a60 holds the singleton instance
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerManager {
    /* Base: nuccLayerList (0x00–0x4F, layout inferred) */
    /* 0x00 */ void *vtable;                          /* overridden to &PTR_FUN_14073caa8 */
    /* 0x08 */ char name[16];                         /* "Manager" passed to nuccLayerList ctor */
    /* 0x18 */ uint32_t layer_type;
    /* 0x1C */ uint16_t flags;
    /* 0x1E */ uint8_t flag_byte;
    /* 0x1F */ uint8_t _pad_1f[1];
    /* 0x20 */ uint16_t _pad_20;
    /* 0x22 */ uint16_t _pad_22;
    /* 0x24 */ uint32_t enabled;
    /* 0x28 */ uint8_t _layerlist_fields[40];         /* nuccLayerList fields (0x28–0x4F), layout unknown */
    /* End of nuccLayerList base (0x50) */
    /* 0x50 */ uint8_t critical_section[80];          /* nuccCriticalSection embedded at puVar1+10=0x50, fills to 0xA0 */
} nuccLayerManager;
static_assert(sizeof(nuccLayerManager) == 0xA0, "nuccLayerManager size");
static_assert(offsetof(nuccLayerManager, vtable) == 0x00, "nuccLayerManager.vtable");
static_assert(offsetof(nuccLayerManager, name) == 0x08, "nuccLayerManager.name");
static_assert(offsetof(nuccLayerManager, critical_section) == 0x50, "nuccLayerManager.critical_section");

/* ========================================================================
 * Single-method layer classes (only Draw method in s1)
 * These inherit from nuccLayer (access param_1+0x1c flags and param_1+0x28 view ptr).
 * No unique fields observed beyond nuccLayer base. Sizes unknown (>= 0x50).
 * Listed here as typedef aliases to nuccLayer for documentation.
 * ======================================================================== */

/* nuccLayerOpaque — opaque geometry pass. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerOpaque;

/* nuccLayerOpaqueClearZ — opaque pass with Z-buffer clear. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerOpaqueClearZ;

/* nuccLayerOutline — outline/stroke effect layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerOutline;

/* nuccLayerPostDecal — post-process decal layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerPostDecal;

/* nuccLayerPostOutline — post-process outline layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerPostOutline;

/* nuccLayerReduction — resolution reduction layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerReduction;

/* nuccLayerReduction2 — secondary reduction/composite layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerReduction2;

/* nuccLayerRefraction — refraction/distortion effect layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerRefraction;

/* nuccLayerMotionBlur — motion blur post-effect layer. Size unknown, >= 0x50. */
typedef nuccLayer nuccLayerMotionBlur;

#endif /* CMN57_H */