#ifndef CMN78_S4_H
#define CMN78_S4_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* cmn78 group for build s4 (NSUNS4_release.exe x64). All layouts INFERRED from static analysis. */

/* nummSkinningControllerGPU: 13 methods, vtable at 0xC0..0x1E0 (PTR_FUN_1412f8d38), size >= 0x310 */
typedef struct __attribute__((packed)) {
    uint8_t _pad0[192];            /* 0x00 - 0xBF */
    uint64_t vtable_C0;            /* 0xC0 - PTR_FUN_1412f8d38 */
    uint8_t _pad1[40];             /* 0xC8 - 0xEF */
    uint64_t vtable_F0;            /* 0xF0 - PTR_FUN_1412f8d38 */
    uint8_t _pad2[40];             /* 0xF8 - 0x11F */
    uint64_t vtable_120;           /* 0x120 - PTR_FUN_1412f8d38 */
    uint8_t _pad3[40];             /* 0x128 - 0x14F */
    uint64_t vtable_150;           /* 0x150 - PTR_FUN_1412f8d38 */
    uint8_t _pad4[40];             /* 0x158 - 0x17F */
    uint64_t vtable_180;           /* 0x180 - PTR_FUN_1412f8d38 */
    uint8_t _pad5[40];             /* 0x188 - 0x1AF */
    uint64_t vtable_1B0;           /* 0x1B0 - PTR_FUN_1412f8d38 */
    uint8_t _pad6[40];             /* 0x1B8 - 0x1DF */
    uint64_t vtable_1E0;           /* 0x1E0 - PTR_FUN_1412f8d38 */
    uint8_t _pad7[288];            /* 0x1E8 - 0x307 */
    uint64_t field_308;            /* 0x308 - rw, ctor+dtor */
} nummSkinningControllerGPU;

static_assert(offsetof(nummSkinningControllerGPU, vtable_C0) == 0xC0, "nummSkinningControllerGPU offset 0xC0");
static_assert(offsetof(nummSkinningControllerGPU, vtable_F0) == 0xF0, "nummSkinningControllerGPU offset 0xF0");
static_assert(offsetof(nummSkinningControllerGPU, vtable_120) == 0x120, "nummSkinningControllerGPU offset 0x120");
static_assert(offsetof(nummSkinningControllerGPU, vtable_150) == 0x150, "nummSkinningControllerGPU offset 0x150");
static_assert(offsetof(nummSkinningControllerGPU, vtable_180) == 0x180, "nummSkinningControllerGPU offset 0x180");
static_assert(offsetof(nummSkinningControllerGPU, vtable_1B0) == 0x1B0, "nummSkinningControllerGPU offset 0x1B0");
static_assert(offsetof(nummSkinningControllerGPU, vtable_1E0) == 0x1E0, "nummSkinningControllerGPU offset 0x1E0");
static_assert(offsetof(nummSkinningControllerGPU, field_308) == 0x308, "nummSkinningControllerGPU offset 0x308");

/* nummThread: no instance state. All 5 methods (Construction 0x9DC3C0, Destruction 0x9DC520, Start 0x9DC5F0, StartFunction 0x9F1D70, WaitForEnd 0x9DC660) operate on TLS (ThreadLocalStoragePointer + _tls_index * 8), not on a this pointer. Construction takes int param_1 (flag), not an object pointer. Static/TLS utility class. */

/* nummSkinningThreadGPU: 4 methods, size = 0xA0 (FUN_14017d9e0 alloc in ctor 0x9E0B00). Singleton in DAT_141665cc8. Byte-cast only; no typed fields extracted. */
#pragma pack(push,1)
typedef struct {
    uint8_t _pad0[160];            /* 0x00 - 0x9F: allocated size 0xA0, no typed field accesses found */
} nummSkinningThreadGPU;
#pragma pack(pop)

static_assert(offsetof(nummSkinningThreadGPU, _pad0) == 0x00, "nummSkinningThreadGPU offset 0x00");

/* nummSpriteMaterial: 6 methods, size >= 0x60 (highest access param_1+0x58 in SubmitConstantBuffer 0x9F1A50). INFERRED from static analysis. */
#pragma pack(push,1)
typedef struct {
    uint64_t field_0x00;           /* 0x00 - w, Create (param_1[0], sprite material handle) */
    uint64_t field_0x08;           /* 0x08 - w, Create (param_1[1]) */
    uint64_t field_0x10;           /* 0x10 - w, Create (param_1[2]) */
    uint64_t field_0x18;           /* 0x18 - w, Create (param_1[3]) */
    uint64_t field_0x20;           /* 0x20 - w, Create (param_1[4]) */
    uint64_t field_0x28;           /* 0x28 - w, Create (param_1[5]) */
    uint64_t field_0x30;           /* 0x30 - w, Create (param_1[6]) */
    uint64_t field_0x38;           /* 0x38 - w, Create (param_1[7]) */
    uint64_t field_0x40;           /* 0x40 - rw, Release/SubmitConstantBuffer */
    uint64_t field_0x48;           /* 0x48 - rw, SubmitAttribute/Release */
    uint64_t field_0x50;           /* 0x50 - rw, Create(param_1[10])/Release */
    uint64_t field_0x58;           /* 0x58 - r, SubmitConstantBuffer */
} nummSpriteMaterial;
#pragma pack(pop)

static_assert(offsetof(nummSpriteMaterial, field_0x00) == 0x00, "nummSpriteMaterial offset 0x00");
static_assert(offsetof(nummSpriteMaterial, field_0x08) == 0x08, "nummSpriteMaterial offset 0x08");
static_assert(offsetof(nummSpriteMaterial, field_0x10) == 0x10, "nummSpriteMaterial offset 0x10");
static_assert(offsetof(nummSpriteMaterial, field_0x18) == 0x18, "nummSpriteMaterial offset 0x18");
static_assert(offsetof(nummSpriteMaterial, field_0x20) == 0x20, "nummSpriteMaterial offset 0x20");
static_assert(offsetof(nummSpriteMaterial, field_0x28) == 0x28, "nummSpriteMaterial offset 0x28");
static_assert(offsetof(nummSpriteMaterial, field_0x30) == 0x30, "nummSpriteMaterial offset 0x30");
static_assert(offsetof(nummSpriteMaterial, field_0x38) == 0x38, "nummSpriteMaterial offset 0x38");
static_assert(offsetof(nummSpriteMaterial, field_0x40) == 0x40, "nummSpriteMaterial offset 0x40");
static_assert(offsetof(nummSpriteMaterial, field_0x48) == 0x48, "nummSpriteMaterial offset 0x48");
static_assert(offsetof(nummSpriteMaterial, field_0x50) == 0x50, "nummSpriteMaterial offset 0x50");
static_assert(offsetof(nummSpriteMaterial, field_0x58) == 0x58, "nummSpriteMaterial offset 0x58");

/* nummTextureManager: 9 methods, size >= 0xA0 */
typedef struct __attribute__((packed)) {
    uint8_t _pad0[36];             /* 0x00 - 0x23 */
    uint64_t field_24;             /* 0x24 - w, ctor, = 0x40000000 */
    uint8_t _pad1[32];             /* 0x2C - 0x4B */
    uint64_t field_4c;             /* 0x4C - w, ctor, = 0x40000000 */
    uint8_t _pad2[12];             /* 0x54 - 0x5F */
    uint8_t field_60[8];           /* 0x60 - r, ctor (address-taken) */
    uint64_t field_68;             /* 0x68 - w, ctor */
    uint64_t field_70;             /* 0x70 - w, ctor */
    uint8_t field_78[8];           /* 0x78 - w, ctor (mixed 1/8 byte) */
    uint32_t field_80;             /* 0x80 - w, ctor */
    uint8_t _pad3[4];              /* 0x84 - 0x87 */
    uint64_t field_88;             /* 0x88 - rw, ctor */
    uint8_t field_90[8];           /* 0x90 - r, ctor (passed to FUN_14017d1d0) */
    uint64_t field_98;             /* 0x98 - w, ctor */
} nummTextureManager;

static_assert(offsetof(nummTextureManager, field_24) == 0x24, "nummTextureManager offset 0x24");
static_assert(offsetof(nummTextureManager, field_4c) == 0x4c, "nummTextureManager offset 0x4c");
static_assert(offsetof(nummTextureManager, field_60) == 0x60, "nummTextureManager offset 0x60");
static_assert(offsetof(nummTextureManager, field_68) == 0x68, "nummTextureManager offset 0x68");
static_assert(offsetof(nummTextureManager, field_70) == 0x70, "nummTextureManager offset 0x70");
static_assert(offsetof(nummTextureManager, field_78) == 0x78, "nummTextureManager offset 0x78");
static_assert(offsetof(nummTextureManager, field_80) == 0x80, "nummTextureManager offset 0x80");
static_assert(offsetof(nummTextureManager, field_88) == 0x88, "nummTextureManager offset 0x88");
static_assert(offsetof(nummTextureManager, field_90) == 0x90, "nummTextureManager offset 0x90");
static_assert(offsetof(nummTextureManager, field_98) == 0x98, "nummTextureManager offset 0x98");

/* nummThread: 5 methods, no instance fields extracted (byte-cast only accesses). */

/* nummTexture: 2 methods (< 3 threshold), deferred. */

/* nummViewManager: 6 methods in group spec but not enumerated separately in s4 method count. */
/* nummViewManager::FrustumInfo: deferred (< 3 methods or absent in s4). */
/* nummViewManager::FrustumInfo::ProjectionInfo: deferred. */
/* nummViewManager::TLS: deferred. */
/* nummViewManager::TLS::WorldViewProjectionMatrix: deferred. */
/* nummSpriteMaterial::TLS: seeds found (Initialize/Finalize) but no fields extracted. */

#endif /* CMN78_S4_H */