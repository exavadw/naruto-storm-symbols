#ifndef CMN78_S3_H
#define CMN78_S3_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* cmn78 group for build s3 (NSUNS3.exe x64). All layouts INFERRED from static analysis. */

typedef struct __attribute__((packed)) {
    uint8_t _pad0[84];
    uint8_t field_54;
    uint8_t _pad1[3];
    uint8_t field_58[8];
    uint8_t field_60[8];
    uint8_t field_68[8];
    uint8_t field_70[8];
    uint8_t field_78[8];
    uint8_t field_80[4];
    uint8_t field_84;
    uint8_t _pad2[3];
    uint8_t field_88[8];
    uint8_t field_90[8];
    uint8_t field_98[8];
    uint8_t field_a0[8];
    uint8_t field_a8[8];
    uint8_t field_b0[8];
    uint8_t field_b8[4];
    uint8_t _pad3[4];
    uint8_t field_c0[8];
    uint8_t field_c8[8];
    uint8_t field_d0[4];
    uint8_t field_d4;
    uint8_t _pad4[3];
    uint8_t field_d8[8];
    uint8_t field_e0[8];
    uint8_t field_e8[8];
    uint8_t field_f0[8];
    uint8_t field_f8[8];
    uint8_t field_100[4];
    uint8_t field_104;
    uint8_t _pad5[3];
    uint8_t field_108[8];
    uint8_t field_110[8];
    uint8_t field_118[8];
    uint8_t field_120[8];
    uint8_t field_128[8];
    uint8_t field_130[4];
    uint8_t field_134;
    uint8_t _pad6[3];
    uint8_t field_138[8];
    uint8_t field_140[8];
    uint8_t field_148[8];
    uint8_t field_150[8];
    uint8_t field_158[8];
    uint8_t field_160[4];
    uint8_t field_164;
    uint8_t _pad7[3];
    uint8_t field_168[8];
    uint8_t field_170[8];
    uint8_t field_178[8];
    uint8_t field_180[8];
    uint8_t field_188[8];
    uint8_t field_190[4];
    uint8_t field_194;
    uint8_t _pad8[3];
    uint8_t field_198[8];
    uint8_t field_1a0[8];
    uint8_t field_1a8[8];
    uint8_t field_1b0[8];
    uint8_t field_1b8[8];
    uint8_t field_1c0[4];
    uint8_t field_1c4;
    uint8_t _pad9[3];
    uint8_t field_1c8[8];
    uint8_t field_1d0[8];
    uint8_t field_1d8[8];
    uint8_t field_1e0[8];
    uint8_t field_1e8[8];
    uint8_t field_1f0[4];
    uint8_t _pad10[4];
    uint8_t field_1f8[8];
    uint8_t field_200[8];
    uint8_t field_208[8];
    uint8_t field_210[8];
    uint8_t field_218[8];
    uint8_t field_220[4];
    uint8_t field_224;
    uint8_t _pad11[3];
    uint8_t field_228[8];
    uint8_t field_230[8];
    uint8_t field_238[8];
    uint8_t field_240[8];
    uint8_t field_248[8];
    uint8_t field_250[4];
    uint8_t field_254;
    uint8_t _pad12[3];
    uint8_t field_258[8];
    uint8_t field_260[8];
    uint8_t field_268[8];
    uint8_t field_270;
    uint8_t _pad13[7];
    uint8_t field_278;
    uint8_t _pad14[7];
    uint8_t field_280[8];
    uint8_t field_288[8];
    uint8_t field_290;
    uint8_t _pad15[7];
    uint8_t field_298[4];
    uint8_t _pad16[4];
    uint8_t field_2a0[8];
    uint8_t field_2a8[8];
    uint8_t field_2b0[8];
    uint8_t _pad17[8];
    uint8_t field_2c0[8];
    uint8_t field_2c8[8];
    uint8_t field_2d0[8];
    uint8_t _pad18[8];
    uint8_t field_2e0[8];
    uint8_t field_2e8[4];
    uint8_t _pad19[4];
    uint8_t field_2f0;
    uint8_t _pad20[7];
    uint8_t field_2f8;
    uint8_t _pad21[7];
    uint8_t field_300[8];
    uint8_t field_308[8];
    uint8_t field_310;
    uint8_t _pad22[11];
    uint8_t field_31c;
    uint8_t _pad23[11];
    uint8_t field_328[8];
    uint8_t field_330[2];
    uint8_t _pad24[2];
    uint8_t field_334[4];
    uint8_t field_338[8];
    uint8_t field_340[8];
    uint8_t field_348[8];
    uint8_t field_350;
} nummSkinningControllerGPU;

static_assert(offsetof(nummSkinningControllerGPU, field_54) == 0x54, "nummSkinningControllerGPU offset 0x54");
static_assert(offsetof(nummSkinningControllerGPU, field_58) == 0x58, "nummSkinningControllerGPU offset 0x58");
static_assert(offsetof(nummSkinningControllerGPU, field_60) == 0x60, "nummSkinningControllerGPU offset 0x60");
static_assert(offsetof(nummSkinningControllerGPU, field_68) == 0x68, "nummSkinningControllerGPU offset 0x68");
static_assert(offsetof(nummSkinningControllerGPU, field_70) == 0x70, "nummSkinningControllerGPU offset 0x70");
static_assert(offsetof(nummSkinningControllerGPU, field_78) == 0x78, "nummSkinningControllerGPU offset 0x78");
static_assert(offsetof(nummSkinningControllerGPU, field_80) == 0x80, "nummSkinningControllerGPU offset 0x80");
static_assert(offsetof(nummSkinningControllerGPU, field_84) == 0x84, "nummSkinningControllerGPU offset 0x84");
static_assert(offsetof(nummSkinningControllerGPU, field_88) == 0x88, "nummSkinningControllerGPU offset 0x88");
static_assert(offsetof(nummSkinningControllerGPU, field_90) == 0x90, "nummSkinningControllerGPU offset 0x90");
static_assert(offsetof(nummSkinningControllerGPU, field_98) == 0x98, "nummSkinningControllerGPU offset 0x98");
static_assert(offsetof(nummSkinningControllerGPU, field_a0) == 0xa0, "nummSkinningControllerGPU offset 0xa0");
static_assert(offsetof(nummSkinningControllerGPU, field_a8) == 0xa8, "nummSkinningControllerGPU offset 0xa8");
static_assert(offsetof(nummSkinningControllerGPU, field_b0) == 0xb0, "nummSkinningControllerGPU offset 0xb0");
static_assert(offsetof(nummSkinningControllerGPU, field_b8) == 0xb8, "nummSkinningControllerGPU offset 0xb8");
static_assert(offsetof(nummSkinningControllerGPU, field_c0) == 0xc0, "nummSkinningControllerGPU offset 0xc0");
static_assert(offsetof(nummSkinningControllerGPU, field_c8) == 0xc8, "nummSkinningControllerGPU offset 0xc8");
static_assert(offsetof(nummSkinningControllerGPU, field_d0) == 0xd0, "nummSkinningControllerGPU offset 0xd0");
static_assert(offsetof(nummSkinningControllerGPU, field_d4) == 0xd4, "nummSkinningControllerGPU offset 0xd4");
static_assert(offsetof(nummSkinningControllerGPU, field_d8) == 0xd8, "nummSkinningControllerGPU offset 0xd8");
static_assert(offsetof(nummSkinningControllerGPU, field_e0) == 0xe0, "nummSkinningControllerGPU offset 0xe0");
static_assert(offsetof(nummSkinningControllerGPU, field_e8) == 0xe8, "nummSkinningControllerGPU offset 0xe8");
static_assert(offsetof(nummSkinningControllerGPU, field_f0) == 0xf0, "nummSkinningControllerGPU offset 0xf0");
static_assert(offsetof(nummSkinningControllerGPU, field_f8) == 0xf8, "nummSkinningControllerGPU offset 0xf8");
static_assert(offsetof(nummSkinningControllerGPU, field_100) == 0x100, "nummSkinningControllerGPU offset 0x100");
static_assert(offsetof(nummSkinningControllerGPU, field_104) == 0x104, "nummSkinningControllerGPU offset 0x104");
static_assert(offsetof(nummSkinningControllerGPU, field_108) == 0x108, "nummSkinningControllerGPU offset 0x108");
static_assert(offsetof(nummSkinningControllerGPU, field_110) == 0x110, "nummSkinningControllerGPU offset 0x110");
static_assert(offsetof(nummSkinningControllerGPU, field_118) == 0x118, "nummSkinningControllerGPU offset 0x118");
static_assert(offsetof(nummSkinningControllerGPU, field_120) == 0x120, "nummSkinningControllerGPU offset 0x120");
static_assert(offsetof(nummSkinningControllerGPU, field_128) == 0x128, "nummSkinningControllerGPU offset 0x128");
static_assert(offsetof(nummSkinningControllerGPU, field_130) == 0x130, "nummSkinningControllerGPU offset 0x130");
static_assert(offsetof(nummSkinningControllerGPU, field_134) == 0x134, "nummSkinningControllerGPU offset 0x134");
static_assert(offsetof(nummSkinningControllerGPU, field_138) == 0x138, "nummSkinningControllerGPU offset 0x138");
static_assert(offsetof(nummSkinningControllerGPU, field_140) == 0x140, "nummSkinningControllerGPU offset 0x140");
static_assert(offsetof(nummSkinningControllerGPU, field_148) == 0x148, "nummSkinningControllerGPU offset 0x148");
static_assert(offsetof(nummSkinningControllerGPU, field_150) == 0x150, "nummSkinningControllerGPU offset 0x150");
static_assert(offsetof(nummSkinningControllerGPU, field_158) == 0x158, "nummSkinningControllerGPU offset 0x158");
static_assert(offsetof(nummSkinningControllerGPU, field_160) == 0x160, "nummSkinningControllerGPU offset 0x160");
static_assert(offsetof(nummSkinningControllerGPU, field_164) == 0x164, "nummSkinningControllerGPU offset 0x164");
static_assert(offsetof(nummSkinningControllerGPU, field_168) == 0x168, "nummSkinningControllerGPU offset 0x168");
static_assert(offsetof(nummSkinningControllerGPU, field_170) == 0x170, "nummSkinningControllerGPU offset 0x170");
static_assert(offsetof(nummSkinningControllerGPU, field_178) == 0x178, "nummSkinningControllerGPU offset 0x178");
static_assert(offsetof(nummSkinningControllerGPU, field_180) == 0x180, "nummSkinningControllerGPU offset 0x180");
static_assert(offsetof(nummSkinningControllerGPU, field_188) == 0x188, "nummSkinningControllerGPU offset 0x188");
static_assert(offsetof(nummSkinningControllerGPU, field_190) == 0x190, "nummSkinningControllerGPU offset 0x190");
static_assert(offsetof(nummSkinningControllerGPU, field_194) == 0x194, "nummSkinningControllerGPU offset 0x194");
static_assert(offsetof(nummSkinningControllerGPU, field_198) == 0x198, "nummSkinningControllerGPU offset 0x198");
static_assert(offsetof(nummSkinningControllerGPU, field_1a0) == 0x1a0, "nummSkinningControllerGPU offset 0x1a0");
static_assert(offsetof(nummSkinningControllerGPU, field_1a8) == 0x1a8, "nummSkinningControllerGPU offset 0x1a8");
static_assert(offsetof(nummSkinningControllerGPU, field_1b0) == 0x1b0, "nummSkinningControllerGPU offset 0x1b0");
static_assert(offsetof(nummSkinningControllerGPU, field_1b8) == 0x1b8, "nummSkinningControllerGPU offset 0x1b8");
static_assert(offsetof(nummSkinningControllerGPU, field_1c0) == 0x1c0, "nummSkinningControllerGPU offset 0x1c0");
static_assert(offsetof(nummSkinningControllerGPU, field_1c4) == 0x1c4, "nummSkinningControllerGPU offset 0x1c4");
static_assert(offsetof(nummSkinningControllerGPU, field_1c8) == 0x1c8, "nummSkinningControllerGPU offset 0x1c8");
static_assert(offsetof(nummSkinningControllerGPU, field_1d0) == 0x1d0, "nummSkinningControllerGPU offset 0x1d0");
static_assert(offsetof(nummSkinningControllerGPU, field_1d8) == 0x1d8, "nummSkinningControllerGPU offset 0x1d8");
static_assert(offsetof(nummSkinningControllerGPU, field_1e0) == 0x1e0, "nummSkinningControllerGPU offset 0x1e0");
static_assert(offsetof(nummSkinningControllerGPU, field_1e8) == 0x1e8, "nummSkinningControllerGPU offset 0x1e8");
static_assert(offsetof(nummSkinningControllerGPU, field_1f0) == 0x1f0, "nummSkinningControllerGPU offset 0x1f0");
static_assert(offsetof(nummSkinningControllerGPU, field_1f8) == 0x1f8, "nummSkinningControllerGPU offset 0x1f8");
static_assert(offsetof(nummSkinningControllerGPU, field_200) == 0x200, "nummSkinningControllerGPU offset 0x200");
static_assert(offsetof(nummSkinningControllerGPU, field_208) == 0x208, "nummSkinningControllerGPU offset 0x208");
static_assert(offsetof(nummSkinningControllerGPU, field_210) == 0x210, "nummSkinningControllerGPU offset 0x210");
static_assert(offsetof(nummSkinningControllerGPU, field_218) == 0x218, "nummSkinningControllerGPU offset 0x218");
static_assert(offsetof(nummSkinningControllerGPU, field_220) == 0x220, "nummSkinningControllerGPU offset 0x220");
static_assert(offsetof(nummSkinningControllerGPU, field_224) == 0x224, "nummSkinningControllerGPU offset 0x224");
static_assert(offsetof(nummSkinningControllerGPU, field_228) == 0x228, "nummSkinningControllerGPU offset 0x228");
static_assert(offsetof(nummSkinningControllerGPU, field_230) == 0x230, "nummSkinningControllerGPU offset 0x230");
static_assert(offsetof(nummSkinningControllerGPU, field_238) == 0x238, "nummSkinningControllerGPU offset 0x238");
static_assert(offsetof(nummSkinningControllerGPU, field_240) == 0x240, "nummSkinningControllerGPU offset 0x240");
static_assert(offsetof(nummSkinningControllerGPU, field_248) == 0x248, "nummSkinningControllerGPU offset 0x248");
static_assert(offsetof(nummSkinningControllerGPU, field_250) == 0x250, "nummSkinningControllerGPU offset 0x250");
static_assert(offsetof(nummSkinningControllerGPU, field_254) == 0x254, "nummSkinningControllerGPU offset 0x254");
static_assert(offsetof(nummSkinningControllerGPU, field_258) == 0x258, "nummSkinningControllerGPU offset 0x258");
static_assert(offsetof(nummSkinningControllerGPU, field_260) == 0x260, "nummSkinningControllerGPU offset 0x260");
static_assert(offsetof(nummSkinningControllerGPU, field_268) == 0x268, "nummSkinningControllerGPU offset 0x268");
static_assert(offsetof(nummSkinningControllerGPU, field_270) == 0x270, "nummSkinningControllerGPU offset 0x270");
static_assert(offsetof(nummSkinningControllerGPU, field_278) == 0x278, "nummSkinningControllerGPU offset 0x278");
static_assert(offsetof(nummSkinningControllerGPU, field_280) == 0x280, "nummSkinningControllerGPU offset 0x280");
static_assert(offsetof(nummSkinningControllerGPU, field_288) == 0x288, "nummSkinningControllerGPU offset 0x288");
static_assert(offsetof(nummSkinningControllerGPU, field_290) == 0x290, "nummSkinningControllerGPU offset 0x290");
static_assert(offsetof(nummSkinningControllerGPU, field_298) == 0x298, "nummSkinningControllerGPU offset 0x298");
static_assert(offsetof(nummSkinningControllerGPU, field_2a0) == 0x2a0, "nummSkinningControllerGPU offset 0x2a0");
static_assert(offsetof(nummSkinningControllerGPU, field_2a8) == 0x2a8, "nummSkinningControllerGPU offset 0x2a8");
static_assert(offsetof(nummSkinningControllerGPU, field_2b0) == 0x2b0, "nummSkinningControllerGPU offset 0x2b0");
static_assert(offsetof(nummSkinningControllerGPU, field_2c0) == 0x2c0, "nummSkinningControllerGPU offset 0x2c0");
static_assert(offsetof(nummSkinningControllerGPU, field_2c8) == 0x2c8, "nummSkinningControllerGPU offset 0x2c8");
static_assert(offsetof(nummSkinningControllerGPU, field_2d0) == 0x2d0, "nummSkinningControllerGPU offset 0x2d0");
static_assert(offsetof(nummSkinningControllerGPU, field_2e0) == 0x2e0, "nummSkinningControllerGPU offset 0x2e0");
static_assert(offsetof(nummSkinningControllerGPU, field_2e8) == 0x2e8, "nummSkinningControllerGPU offset 0x2e8");
static_assert(offsetof(nummSkinningControllerGPU, field_2f0) == 0x2f0, "nummSkinningControllerGPU offset 0x2f0");
static_assert(offsetof(nummSkinningControllerGPU, field_2f8) == 0x2f8, "nummSkinningControllerGPU offset 0x2f8");
static_assert(offsetof(nummSkinningControllerGPU, field_300) == 0x300, "nummSkinningControllerGPU offset 0x300");
static_assert(offsetof(nummSkinningControllerGPU, field_308) == 0x308, "nummSkinningControllerGPU offset 0x308");
static_assert(offsetof(nummSkinningControllerGPU, field_310) == 0x310, "nummSkinningControllerGPU offset 0x310");
static_assert(offsetof(nummSkinningControllerGPU, field_31c) == 0x31c, "nummSkinningControllerGPU offset 0x31c");
static_assert(offsetof(nummSkinningControllerGPU, field_328) == 0x328, "nummSkinningControllerGPU offset 0x328");
static_assert(offsetof(nummSkinningControllerGPU, field_330) == 0x330, "nummSkinningControllerGPU offset 0x330");
static_assert(offsetof(nummSkinningControllerGPU, field_334) == 0x334, "nummSkinningControllerGPU offset 0x334");
static_assert(offsetof(nummSkinningControllerGPU, field_338) == 0x338, "nummSkinningControllerGPU offset 0x338");
static_assert(offsetof(nummSkinningControllerGPU, field_340) == 0x340, "nummSkinningControllerGPU offset 0x340");
static_assert(offsetof(nummSkinningControllerGPU, field_348) == 0x348, "nummSkinningControllerGPU offset 0x348");
static_assert(offsetof(nummSkinningControllerGPU, field_350) == 0x350, "nummSkinningControllerGPU offset 0x350");

/* nummSkinningThreadGPU: no instance state found in s3 (state_surface returned 0 fields). */

/* nummSpriteMaterial: no instance state found in s3 (state_surface returned 0 fields). */

typedef struct __attribute__((packed)) {
    uint8_t _pad0[36];
    uint8_t field_24[8];
    uint8_t _pad1[32];
    uint8_t field_4c[8];
    uint8_t _pad2[12];
    uint8_t field_60;
    uint8_t _pad3[7];
    uint8_t field_68[8];
    uint8_t field_70[8];
    uint8_t field_78;
    uint8_t _pad4[7];
    uint8_t field_80[4];
    uint8_t _pad5[4];
    uint8_t field_88[8];
    uint8_t field_90;
    uint8_t _pad6[7];
    uint8_t field_98[8];
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

/* nummThread: no instance state found in s3 (state_surface returned 0 fields). */

/* nummSpriteMaterial::TLS: < 3 methods in s3, deferred. */

/* nummTexture: < 3 methods in s3, deferred. */

/* nummViewManager::FrustumInfo: < 3 methods in s3, deferred. */

/* nummViewManager::FrustumInfo::ProjectionInfo: < 3 methods in s3, deferred. */

/* nummViewManager::TLS: < 3 methods in s3, deferred. */

/* nummViewManager::TLS::WorldViewProjectionMatrix: < 3 methods in s3, deferred. */

#endif /* CMN78_S3_H */
