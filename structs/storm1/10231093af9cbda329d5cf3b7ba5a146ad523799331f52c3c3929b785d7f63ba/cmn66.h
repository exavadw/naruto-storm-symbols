/* cmn66.h - Struct layouts for cmn66 group, build s1 (NSUNS1.exe)
 * INFERRED from static analysis only. Not CONFIRMED at runtime.
 * All offsets derived from PC x64 decompile (image base 0x140000000).
 */
#ifndef CMN66_H
#define CMN66_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nuccRenderTexture: render texture resource wrapper
 * Size unknown, >= 0x2C (last proven field at +0x24, size 8)
 * Ctor at 0x4B9A40 initializes fields up to +0x24
 */
typedef struct __attribute__((packed)) nuccRenderTexture {
    uint64_t vtable_or_flags_0;      /* +0x00: initialized to 0xFFFFFFFFFFFFFFFF in ctor */
    uint64_t field_8;                /* +0x08: initialized to 0xFFFFFFFFFFFFFFFF in ctor */
    uint16_t field_10;               /* +0x10: initialized to 0 in ctor */
    uint8_t _pad_12[1];              /* +0x12: padding */
    uint8_t field_13;                /* +0x13: set to 1 in Create* methods */
    uint64_t field_14;               /* +0x14: initialized to 0 in ctor */
    uint64_t field_1c;               /* +0x1C: initialized to 0 in ctor */
    uint64_t field_24;               /* +0x24: initialized to 1 in ctor */
} nuccRenderTexture;

static_assert(offsetof(nuccRenderTexture, vtable_or_flags_0) == 0x00, "nuccRenderTexture.vtable_or_flags_0");
static_assert(offsetof(nuccRenderTexture, field_8) == 0x08, "nuccRenderTexture.field_8");
static_assert(offsetof(nuccRenderTexture, field_10) == 0x10, "nuccRenderTexture.field_10");
static_assert(offsetof(nuccRenderTexture, field_13) == 0x13, "nuccRenderTexture.field_13");
static_assert(offsetof(nuccRenderTexture, field_14) == 0x14, "nuccRenderTexture.field_14");
static_assert(offsetof(nuccRenderTexture, field_1c) == 0x1C, "nuccRenderTexture.field_1c");
static_assert(offsetof(nuccRenderTexture, field_24) == 0x24, "nuccRenderTexture.field_24");

/* nuccPostEffectManager: post-effect pipeline manager (singleton)
 * Size unknown, >= 0xF0 (state_surface shows access at +0xF0 in Finalize/Initialize)
 * Field at +0x24 written in Initialize with shader param
 */
typedef struct __attribute__((packed)) nuccPostEffectManager {
    uint8_t _unknown_0[0x24];        /* +0x00: vtable + other fields, not yet mapped */
    uint32_t shader_param;           /* +0x24: written in Initialize from lVar9+0x18 */
    uint8_t _unknown_28[0xC8];       /* +0x28: gap to +0xF0 */
    uint8_t field_f0;                /* +0xF0: read in Finalize/Initialize (puVar8 = param_1 + 0x1e scaled) */
} nuccPostEffectManager;

static_assert(offsetof(nuccPostEffectManager, shader_param) == 0x24, "nuccPostEffectManager.shader_param");
static_assert(offsetof(nuccPostEffectManager, field_f0) == 0xF0, "nuccPostEffectManager.field_f0");

/* nuccRapidXml: XML parser state
 * Size unknown, >= 0x10028 (field at +0x10020 is pointer-sized, read in Clear)
 * Fields at +0x80 (vfunc call), +0x10018, +0x10020 seen in Clear/Init/ParseCore
 */
typedef struct __attribute__((packed)) nuccRapidXml {
    uint8_t _unknown_0[0x80];        /* +0x00: includes vtable ptr at +0x10 (vfunc call pattern) */
    uint8_t _gap_80[0xFF98];         /* +0x80: large gap to +0x10018 */
    uint64_t field_10018;            /* +0x10018: read in Clear (param_1[2] assignment context) */
    uint64_t field_10020;            /* +0x10020: pointer, null-checked in Clear */
} nuccRapidXml;

static_assert(offsetof(nuccRapidXml, field_10018) == 0x10018, "nuccRapidXml.field_10018");
static_assert(offsetof(nuccRapidXml, field_10020) == 0x10020, "nuccRapidXml.field_10020");

/* nuccReadThread: async file reader thread
 * Size unknown, >= 0x64 (field at +0x60 written in ctor)
 * Only one field found via state_surface; Exec uses byte-cast accesses
 */
typedef struct __attribute__((packed)) nuccReadThread {
    uint8_t _unknown_0[0x60];        /* +0x00: base class / vtable area */
    uint32_t field_60;               /* +0x60: initialized to 0 in ctor */
} nuccReadThread;

static_assert(offsetof(nuccReadThread, field_60) == 0x60, "nuccReadThread.field_60");

/* Classes with < 3 methods or no field evidence in s1:
 *   nuccPostEffectOutline (3 methods, 0 fields from state_surface - byte-cast only)
 *   nuccPostEffectParamGlare (1 method: ctor only)
 *   nuccPrimitiveTransform (1 method: Transform)
 *   nuccPrimitiveTransformP32N32C1UV1onPPU (1 method: TransformCore)
 *   nuccRefStr (2 methods: operator< and operator=, 0 fields)
 * These are listed in REPORT.md as gaps.
 */

#endif /* CMN66_H */