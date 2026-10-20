/* cmn57.h — nuccLayer* struct group for NARUTO STORM 3 Full Burst HD PC (s3, NSUNS3.exe)
 * All layouts INFERRED from static decompilation of build s3 (sha 55b726e94dad).
 * NOT CONFIRMED by runtime trace. Field names from s3 symbols/strings only.
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
 * Vtable: PTR_FUN_1409e02e8 (set in ctor)
 * Size: unknown, >= 0x28 (last proven field at 0x24 is uint32)
 * Evidence: nuccLayerBase::nuccLayerBase (RVA 0x6B6F40)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerBase {
    /* 0x00 */ void *vtable;
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t layer_type;
    /* 0x1C */ uint16_t flags;
    /* 0x1E */ uint8_t flag_byte;
    /* 0x1F */ uint8_t _pad_1f[1];
    /* 0x20 */ uint16_t _pad_20;
    /* 0x22 */ uint16_t _pad_22;
    /* 0x24 */ uint32_t enabled;
} nuccLayerBase;
static_assert(offsetof(nuccLayerBase, vtable) == 0x00, "nuccLayerBase.vtable");
static_assert(offsetof(nuccLayerBase, name) == 0x08, "nuccLayerBase.name");
static_assert(offsetof(nuccLayerBase, layer_type) == 0x18, "nuccLayerBase.layer_type");
static_assert(offsetof(nuccLayerBase, flags) == 0x1C, "nuccLayerBase.flags");
static_assert(offsetof(nuccLayerBase, flag_byte) == 0x1E, "nuccLayerBase.flag_byte");
static_assert(offsetof(nuccLayerBase, _pad_1f) == 0x1F, "nuccLayerBase._pad_1f");
static_assert(offsetof(nuccLayerBase, _pad_20) == 0x20, "nuccLayerBase._pad_20");
static_assert(offsetof(nuccLayerBase, _pad_22) == 0x22, "nuccLayerBase._pad_22");
static_assert(offsetof(nuccLayerBase, enabled) == 0x24, "nuccLayerBase.enabled");

/* ========================================================================
 * nuccLayer — extends nuccLayerBase, adds draw command list management
 * Vtable: PTR_FUN_1409e0ba8 (set in ctor, overrides nuccLayerBase vtable)
 * Size: unknown, >= 0x50 (last proven field at 0x48 is ptr)
 * Evidence: nuccLayer::nuccLayer (RVA 0x6C02C0)
 * Inherits: nuccLayerBase (first 0x28 bytes)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayer {
    /* 0x00 */ void *vtable;
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
    /* 0x40 */ uint32_t _field_40_flags;
    /* 0x44 */ uint32_t _pad_44;
    /* 0x48 */ void *_self_ptr;
} nuccLayer;
static_assert(offsetof(nuccLayer, vtable) == 0x00, "nuccLayer.vtable");
static_assert(offsetof(nuccLayer, name) == 0x08, "nuccLayer.name");
static_assert(offsetof(nuccLayer, layer_type) == 0x18, "nuccLayer.layer_type");
static_assert(offsetof(nuccLayer, flags) == 0x1C, "nuccLayer.flags");
static_assert(offsetof(nuccLayer, enabled) == 0x24, "nuccLayer.enabled");
static_assert(offsetof(nuccLayer, draw_command_list) == 0x28, "nuccLayer.draw_command_list");
static_assert(offsetof(nuccLayer, _field_30) == 0x30, "nuccLayer._field_30");
static_assert(offsetof(nuccLayer, _field_38) == 0x38, "nuccLayer._field_38");
static_assert(offsetof(nuccLayer, _field_40_flags) == 0x40, "nuccLayer._field_40_flags");
static_assert(offsetof(nuccLayer, _pad_44) == 0x44, "nuccLayer._pad_44");
static_assert(offsetof(nuccLayer, _self_ptr) == 0x48, "nuccLayer._self_ptr");

/* ========================================================================
 * nuccLayerPostEffectPreDraw — pre-draw post-effect layer
 * Vtable: PTR_FUN_1409e5aa0 (set in ctor)
 * Size: 0x28 (proven from LoadTh(0x28,...) in Create, RVA 0x698EB0)
 * Evidence: nuccLayerPostEffectPreDraw::nuccLayerPostEffectPreDraw (RVA 0x6EFF20)
 * Inherits: nuccLayerBase (not nuccLayer)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerPostEffectPreDraw {
    /* 0x00 */ void *vtable;
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
static_assert(offsetof(nuccLayerPostEffectPreDraw, name) == 0x08, "nuccLayerPostEffectPreDraw.name");
static_assert(offsetof(nuccLayerPostEffectPreDraw, layer_type) == 0x18, "nuccLayerPostEffectPreDraw.layer_type");
static_assert(offsetof(nuccLayerPostEffectPreDraw, flags) == 0x1C, "nuccLayerPostEffectPreDraw.flags");
static_assert(offsetof(nuccLayerPostEffectPreDraw, flag_byte) == 0x1E, "nuccLayerPostEffectPreDraw.flag_byte");
static_assert(offsetof(nuccLayerPostEffectPreDraw, _pad_1f) == 0x1F, "nuccLayerPostEffectPreDraw._pad_1f");
static_assert(offsetof(nuccLayerPostEffectPreDraw, _pad_20) == 0x20, "nuccLayerPostEffectPreDraw._pad_20");
static_assert(offsetof(nuccLayerPostEffectPreDraw, _pad_22) == 0x22, "nuccLayerPostEffectPreDraw._pad_22");
static_assert(offsetof(nuccLayerPostEffectPreDraw, enabled) == 0x24, "nuccLayerPostEffectPreDraw.enabled");

/* ========================================================================
 * nuccLayerPostEffect — post-effect rendering layer with render texture
 * Vtable: PTR_FUN_1409e5be0 (set in ctor)
 * Size: 0x58 (proven from LoadTh(0x58,...) in Create, RVA 0x698E60)
 * Evidence: nuccLayerPostEffect::nuccLayerPostEffect (RVA 0x6F10A0)
 * Inherits: nuccLayer (calls nuccLayer::nuccLayer)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerPostEffect {
    /* 0x00 */ void *vtable;
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
    /* 0x40 */ uint32_t _field_40_flags;
    /* 0x44 */ uint32_t _pad_44;
    /* 0x48 */ void *_self_ptr;
    /* 0x50 */ nuccRenderTexture_ptr render_texture;
} nuccLayerPostEffect;
static_assert(sizeof(nuccLayerPostEffect) == 0x58, "nuccLayerPostEffect size");
static_assert(offsetof(nuccLayerPostEffect, vtable) == 0x00, "nuccLayerPostEffect.vtable");
static_assert(offsetof(nuccLayerPostEffect, name) == 0x08, "nuccLayerPostEffect.name");
static_assert(offsetof(nuccLayerPostEffect, flags) == 0x1C, "nuccLayerPostEffect.flags");
static_assert(offsetof(nuccLayerPostEffect, enabled) == 0x24, "nuccLayerPostEffect.enabled");
static_assert(offsetof(nuccLayerPostEffect, draw_command_list) == 0x28, "nuccLayerPostEffect.draw_command_list");
static_assert(offsetof(nuccLayerPostEffect, _field_30) == 0x30, "nuccLayerPostEffect._field_30");
static_assert(offsetof(nuccLayerPostEffect, _field_38) == 0x38, "nuccLayerPostEffect._field_38");
static_assert(offsetof(nuccLayerPostEffect, _field_40_flags) == 0x40, "nuccLayerPostEffect._field_40_flags");
static_assert(offsetof(nuccLayerPostEffect, _pad_44) == 0x44, "nuccLayerPostEffect._pad_44");
static_assert(offsetof(nuccLayerPostEffect, _self_ptr) == 0x48, "nuccLayerPostEffect._self_ptr");
static_assert(offsetof(nuccLayerPostEffect, render_texture) == 0x50, "nuccLayerPostEffect.render_texture");

/* ========================================================================
 * nuccLayerManager — singleton manager for all nucc layers
 * Vtable: PTR_FUN_1409e38b8 (set in Create after nuccLayerList ctor)
 * Size: 0xA0 (proven from LoadTh(0xa0,...) in Create, RVA 0x6DB590)
 * Evidence: nuccLayerManager::Create (RVA 0x6DB590)
 * Inherits: nuccLayerList (inferred; calls nuccLayerList::nuccLayerList)
 * Embedded: nuccCriticalSection at puVar1+10 = offset 0x50
 * Global: DAT_140c67740 holds the singleton instance
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccLayerManager {
    /* 0x00 */ void *vtable;
    /* 0x08 */ char name[16];
    /* 0x18 */ uint32_t layer_type;
    /* 0x1C */ uint16_t flags;
    /* 0x1E */ uint8_t flag_byte;
    /* 0x1F */ uint8_t _pad_1f[1];
    /* 0x20 */ uint16_t _pad_20;
    /* 0x22 */ uint16_t _pad_22;
    /* 0x24 */ uint32_t enabled;
    /* 0x28 */ uint8_t _layerlist_fields[40];
    /* 0x50 */ uint8_t critical_section[80];
} nuccLayerManager;
static_assert(sizeof(nuccLayerManager) == 0xA0, "nuccLayerManager size");
static_assert(offsetof(nuccLayerManager, vtable) == 0x00, "nuccLayerManager.vtable");
static_assert(offsetof(nuccLayerManager, name) == 0x08, "nuccLayerManager.name");
static_assert(offsetof(nuccLayerManager, layer_type) == 0x18, "nuccLayerManager.layer_type");
static_assert(offsetof(nuccLayerManager, flags) == 0x1C, "nuccLayerManager.flags");
static_assert(offsetof(nuccLayerManager, enabled) == 0x24, "nuccLayerManager.enabled");
static_assert(offsetof(nuccLayerManager, _layerlist_fields) == 0x28, "nuccLayerManager._layerlist_fields");
static_assert(offsetof(nuccLayerManager, critical_section) == 0x50, "nuccLayerManager.critical_section");

/* ========================================================================
 * Single-method layer classes (only Draw method in s3)
 * These inherit from nuccLayer (access param_1+0x1c flags and param_1+0x28 view ptr).
 * No unique fields observed beyond nuccLayer base. Sizes unknown (>= 0x50).
 * Listed here as typedef aliases to nuccLayer for documentation.
 * ======================================================================== */
typedef nuccLayer nuccLayerOpaque;
typedef nuccLayer nuccLayerOpaqueClearZ;
typedef nuccLayer nuccLayerOutline;
typedef nuccLayer nuccLayerPostDecal;
typedef nuccLayer nuccLayerPostOutline;
typedef nuccLayer nuccLayerReduction;
typedef nuccLayer nuccLayerReduction2;
typedef nuccLayer nuccLayerRefraction;
typedef nuccLayer nuccLayerMotionBlur;

#endif /* CMN57_H */