/* rbProjectile s4 - Storm 4 (NSUNS4_release.exe PC 1.09) struct layouts */
/* AUTO-GENERATED from state_surface analysis. All results are INFERRED. */
/* All fields are uint8_t[] to guarantee exact offsets under pack(1). */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ccGameObjectSkill: size >= 0x6E0 (INFERRED from state_surface max field offset 0x6D8) */
typedef struct {
    uint8_t _pad_000[112]; /* 0x0..0x70 */
    uint8_t field_070[8]; /* 0x70 size=8 kind=r conf=low */
    /* SKIP field_074 at 0x74 (overlaps previous field ending at 0x78) */
    uint8_t field_078[8]; /* 0x78 size=8 kind=r conf=low */
    uint8_t field_080[8]; /* 0x80 size=8 kind=r conf=low */
    uint8_t _pad_088[8]; /* 0x88..0x90 */
    uint8_t field_090[8]; /* 0x90 size=8 kind=r conf=low */
    uint8_t field_098[8]; /* 0x98 size=8 kind=rw conf=high */
    uint8_t field_0a0[8]; /* 0xA0 size=8 kind=rw conf=low */
    /* SKIP field_0a4 at 0xA4 (overlaps previous field ending at 0xA8) */
    uint8_t field_0a8[4]; /* 0xA8 size=4 kind=rw conf=high */
    uint8_t field_0ac[8]; /* 0xAC size=8 kind=r conf=low */
    uint8_t _pad_0b4[56]; /* 0xB4..0xEC */
    uint8_t field_0ec[4]; /* 0xEC size=4 kind=r conf=medium */
    uint8_t field_0f0[4]; /* 0xF0 size=4 kind=rw conf=high */
    uint8_t field_0f4[4]; /* 0xF4 size=4 kind=rw conf=high */
    uint8_t field_0f8[4]; /* 0xF8 size=4 kind=rw conf=high */
    uint8_t _pad_0fc[4]; /* 0xFC..0x100 */
    uint8_t field_100[8]; /* 0x100 size=8 kind=rw conf=high */
    uint8_t field_108[8]; /* 0x108 size=8 kind=r conf=medium */
    /* SKIP field_10c at 0x10C (overlaps previous field ending at 0x110) */
    uint8_t field_110[8]; /* 0x110 size=8 kind=rw conf=high */
    uint8_t field_118[8]; /* 0x118 size=8 kind=r conf=low */
    uint8_t _pad_120[32]; /* 0x120..0x140 */
    uint8_t field_140[8]; /* 0x140 size=8 kind=rw conf=high */
    uint8_t field_148[4]; /* 0x148 size=4 kind=rw conf=high */
    uint8_t _pad_14c[16]; /* 0x14C..0x15C */
    uint8_t field_15c; /* 0x15C kind=rw conf=high */
    uint8_t _pad_15d[3]; /* 0x15D..0x160 */
    uint8_t field_160[8]; /* 0x160 size=8 kind=r conf=low */
    /* SKIP field_164 at 0x164 (overlaps previous field ending at 0x168) */
    uint8_t field_168[4]; /* 0x168 size=4 kind=rw conf=medium */
    uint8_t field_16c[8]; /* 0x16C size=8 kind=r conf=low */
    uint8_t field_174[8]; /* 0x174 size=8 kind=r conf=medium */
    uint8_t field_17c[8]; /* 0x17C size=8 kind=r conf=medium */
    uint8_t field_184[8]; /* 0x184 size=8 kind=r conf=medium */
    uint8_t field_18c[8]; /* 0x18C size=8 kind=r conf=medium */
    uint8_t field_194[8]; /* 0x194 size=8 kind=r conf=medium */
    uint8_t field_19c[8]; /* 0x19C size=8 kind=r conf=medium */
    uint8_t field_1a4[8]; /* 0x1A4 size=8 kind=r conf=medium */
    uint8_t field_1ac[4]; /* 0x1AC size=4 kind=r conf=low */
    /* SKIP field_1ae at 0x1AE (overlaps previous field ending at 0x1B0) */
    uint8_t field_1b0[8]; /* 0x1B0 size=8 kind=r conf=medium */
    /* SKIP field_1b2 at 0x1B2 (overlaps previous field ending at 0x1B8) */
    /* SKIP field_1b4 at 0x1B4 (overlaps previous field ending at 0x1B8) */
    uint8_t field_1b8[8]; /* 0x1B8 size=8 kind=r conf=medium */
    /* SKIP field_1bc at 0x1BC (overlaps previous field ending at 0x1C0) */
    uint8_t field_1c0[8]; /* 0x1C0 size=8 kind=r conf=medium */
    /* SKIP field_1c4 at 0x1C4 (overlaps previous field ending at 0x1C8) */
    uint8_t field_1c8[2]; /* 0x1C8 size=2 kind=rw conf=high */
    uint8_t _pad_1ca[2]; /* 0x1CA..0x1CC */
    uint8_t field_1cc[4]; /* 0x1CC size=4 kind=rw conf=high */
    uint8_t field_1d0[8]; /* 0x1D0 size=8 kind=r conf=medium */
    uint8_t _pad_1d8[4]; /* 0x1D8..0x1DC */
    uint8_t field_1dc[4]; /* 0x1DC size=4 kind=r conf=medium */
    uint8_t field_1e0[8]; /* 0x1E0 size=8 kind=r conf=medium */
    /* SKIP field_1e4 at 0x1E4 (overlaps previous field ending at 0x1E8) */
    uint8_t field_1e8[8]; /* 0x1E8 size=8 kind=r conf=low */
    /* SKIP field_1ec at 0x1EC (overlaps previous field ending at 0x1F0) */
    uint8_t _pad_1f0[12]; /* 0x1F0..0x1FC */
    uint8_t field_1fc[4]; /* 0x1FC size=4 kind=r conf=medium */
    uint8_t field_200[8]; /* 0x200 size=8 kind=r conf=medium */
    uint8_t field_208[8]; /* 0x208 size=8 kind=r conf=medium */
    uint8_t field_210[8]; /* 0x210 size=8 kind=r conf=medium */
    uint8_t _pad_218[4]; /* 0x218..0x21C */
    uint8_t field_21c[4]; /* 0x21C size=4 kind=r conf=medium */
    uint8_t _pad_220[20]; /* 0x220..0x234 */
    uint8_t field_234[4]; /* 0x234 size=4 kind=r conf=medium */
    uint8_t field_238[8]; /* 0x238 size=8 kind=r conf=medium */
    uint8_t field_240[8]; /* 0x240 size=8 kind=r conf=medium */
    uint8_t field_248[8]; /* 0x248 size=8 kind=r conf=medium */
    /* SKIP field_24c at 0x24C (overlaps previous field ending at 0x250) */
    uint8_t field_250[4]; /* 0x250 size=4 kind=w conf=medium */
    uint8_t field_254[4]; /* 0x254 size=4 kind=rw conf=high */
    uint8_t field_258[8]; /* 0x258 size=8 kind=r conf=medium */
    uint8_t _pad_260[256]; /* 0x260..0x360 */
    uint8_t field_360[8]; /* 0x360 size=8 kind=r conf=low */
    uint8_t _pad_368[24]; /* 0x368..0x380 */
    uint8_t field_380[8]; /* 0x380 size=8 kind=r conf=low */
    uint8_t _pad_388[32]; /* 0x388..0x3A8 */
    uint8_t field_3a8[8]; /* 0x3A8 size=8 kind=rw conf=low */
    /* SKIP field_3ac at 0x3AC (overlaps previous field ending at 0x3B0) */
    uint8_t field_3b0[8]; /* 0x3B0 size=8 kind=rw conf=medium */
    uint8_t field_3b8[8]; /* 0x3B8 size=8 kind=rw conf=medium */
    uint8_t field_3c0[8]; /* 0x3C0 size=8 kind=r conf=low */
    uint8_t _pad_3c8[40]; /* 0x3C8..0x3F0 */
    uint8_t field_3f0[8]; /* 0x3F0 size=8 kind=r conf=medium */
    /* SKIP field_3f4 at 0x3F4 (overlaps previous field ending at 0x3F8) */
    uint8_t _pad_3f8[8]; /* 0x3F8..0x400 */
    uint8_t field_400[8]; /* 0x400 size=8 kind=r conf=low */
    uint8_t _pad_408[48]; /* 0x408..0x438 */
    uint8_t field_438[8]; /* 0x438 size=8 kind=r conf=low */
    uint8_t field_440[8]; /* 0x440 size=8 kind=r conf=low */
    uint8_t _pad_448[40]; /* 0x448..0x470 */
    uint8_t field_470[8]; /* 0x470 size=8 kind=r conf=medium */
    /* SKIP field_474 at 0x474 (overlaps previous field ending at 0x478) */
    uint8_t _pad_478[4]; /* 0x478..0x47C */
    uint8_t field_47c[4]; /* 0x47C size=4 kind=w conf=medium */
    uint8_t field_480[8]; /* 0x480 size=8 kind=r conf=low */
    uint8_t field_488[8]; /* 0x488 size=8 kind=rw conf=high */
    uint8_t field_490[4]; /* 0x490 size=4 kind=rw conf=high */
    uint8_t field_494[8]; /* 0x494 size=8 kind=r conf=medium */
    uint8_t field_49c[4]; /* 0x49C size=4 kind=r conf=medium */
    uint8_t field_4a0[8]; /* 0x4A0 size=8 kind=r conf=medium */
    /* SKIP field_4a4 at 0x4A4 (overlaps previous field ending at 0x4A8) */
    uint8_t _pad_4a8[8]; /* 0x4A8..0x4B0 */
    uint8_t field_4b0[8]; /* 0x4B0 size=8 kind=rw conf=low */
    uint8_t field_4b8[4]; /* 0x4B8 size=4 kind=w conf=high */
    uint8_t field_4bc[4]; /* 0x4BC size=4 kind=rw conf=medium */
    uint8_t field_4c0[8]; /* 0x4C0 size=8 kind=r conf=low */
    uint8_t _pad_4c8[40]; /* 0x4C8..0x4F0 */
    uint8_t field_4f0[8]; /* 0x4F0 size=8 kind=r conf=low */
    uint8_t field_4f8[8]; /* 0x4F8 size=8 kind=w conf=medium */
    uint8_t _pad_500[8]; /* 0x500..0x508 */
    uint8_t field_508[8]; /* 0x508 size=8 kind=r conf=low */
    uint8_t _pad_510[16]; /* 0x510..0x520 */
    uint8_t field_520[8]; /* 0x520 size=8 kind=r conf=low */
    uint8_t _pad_528[40]; /* 0x528..0x550 */
    uint8_t field_550[8]; /* 0x550 size=8 kind=r conf=medium */
    uint8_t field_558[8]; /* 0x558 size=8 kind=r conf=medium */
    uint8_t _pad_560[32]; /* 0x560..0x580 */
    uint8_t field_580[8]; /* 0x580 size=8 kind=r conf=low */
    uint8_t field_588[8]; /* 0x588 size=8 kind=rw conf=medium */
    uint8_t _pad_590[8]; /* 0x590..0x598 */
    uint8_t field_598[8]; /* 0x598 size=8 kind=r conf=low */
    uint8_t _pad_5a0[16]; /* 0x5A0..0x5B0 */
    uint8_t field_5b0[4]; /* 0x5B0 size=4 kind=rw conf=high */
    uint8_t field_5b4[4]; /* 0x5B4 size=4 kind=rw conf=high */
    uint8_t _pad_5b8[8]; /* 0x5B8..0x5C0 */
    uint8_t field_5c0[8]; /* 0x5C0 size=8 kind=r conf=low */
    uint8_t field_5c8[8]; /* 0x5C8 size=8 kind=rw conf=medium */
    uint8_t _pad_5d0[8]; /* 0x5D0..0x5D8 */
    uint8_t field_5d8[8]; /* 0x5D8 size=8 kind=r conf=low */
    uint8_t _pad_5e0[16]; /* 0x5E0..0x5F0 */
    uint8_t field_5f0[4]; /* 0x5F0 size=4 kind=w conf=medium */
    uint8_t _pad_5f4[4]; /* 0x5F4..0x5F8 */
    uint8_t field_5f8[8]; /* 0x5F8 size=8 kind=w conf=medium */
    uint8_t field_600[8]; /* 0x600 size=8 kind=w conf=medium */
    uint8_t field_608[8]; /* 0x608 size=8 kind=w conf=medium */
    uint8_t field_610[4]; /* 0x610 size=4 kind=w conf=medium */
    uint8_t _pad_614[4]; /* 0x614..0x618 */
    uint8_t field_618[8]; /* 0x618 size=8 kind=w conf=medium */
    uint8_t field_620[4]; /* 0x620 size=4 kind=w conf=medium */
    uint8_t _pad_624[4]; /* 0x624..0x628 */
    uint8_t field_628[8]; /* 0x628 size=8 kind=r conf=medium */
    uint8_t field_630[4]; /* 0x630 size=4 kind=rw conf=high */
    uint8_t _pad_634[16]; /* 0x634..0x644 */
    uint8_t field_644[4]; /* 0x644 size=4 kind=w conf=medium */
    uint8_t field_648[4]; /* 0x648 size=4 kind=rw conf=high */
    uint8_t _pad_64c[4]; /* 0x64C..0x650 */
    uint8_t field_650[8]; /* 0x650 size=8 kind=r conf=low */
    uint8_t _pad_658[32]; /* 0x658..0x678 */
    uint8_t field_678[8]; /* 0x678 size=8 kind=rw conf=medium */
    uint8_t _pad_680[64]; /* 0x680..0x6C0 */
    uint8_t field_6c0[8]; /* 0x6C0 size=8 kind=w conf=medium */
    uint8_t field_6c8[8]; /* 0x6C8 size=8 kind=rw conf=medium */
    uint8_t _pad_6d0[4]; /* 0x6D0..0x6D4 */
    uint8_t field_6d4[4]; /* 0x6D4 size=4 kind=rw conf=high */
    uint8_t field_6d8[8]; /* 0x6D8 size=8 kind=r conf=medium */
} ccGameObjectSkill_partial_t;

/* ccHitGroup: size >= 0x598 (INFERRED from state_surface max_end 0x594 + alignment) */
typedef struct {
    uint8_t _pad_000[84]; /* 0x0..0x54 */
    uint8_t field_054[8]; /* 0x54 size=8 kind=w conf=medium */
    uint8_t field_05c[4]; /* 0x5C size=4 kind=w conf=medium */
    uint8_t field_060[4]; /* 0x60 size=4 kind=w conf=medium */
    uint8_t _pad_064[4]; /* 0x64..0x68 */
    uint8_t field_068[8]; /* 0x68 size=8 kind=w conf=medium */
    uint8_t field_070[4]; /* 0x70 size=4 kind=w conf=medium */
    uint8_t field_074[8]; /* 0x74 size=8 kind=r conf=low */
    uint8_t _pad_07c[4]; /* 0x7C..0x80 */
    uint8_t field_080[8]; /* 0x80 size=8 kind=w conf=medium */
    uint8_t _pad_088[28]; /* 0x88..0xA4 */
    uint8_t field_0a4[8]; /* 0xA4 size=8 kind=w conf=medium */
    uint8_t field_0ac[8]; /* 0xAC size=8 kind=w conf=medium */
    uint8_t _pad_0b4[4]; /* 0xB4..0xB8 */
    uint8_t field_0b8[4]; /* 0xB8 size=4 kind=w conf=medium */
    uint8_t _pad_0bc[4]; /* 0xBC..0xC0 */
    uint8_t field_0c0[8]; /* 0xC0 size=8 kind=w conf=medium */
    uint8_t field_0c8[8]; /* 0xC8 size=8 kind=r conf=low */
    uint8_t _pad_0d0[4]; /* 0xD0..0xD4 */
    uint8_t field_0d4[8]; /* 0xD4 size=8 kind=r conf=low */
    uint8_t _pad_0dc[4]; /* 0xDC..0xE0 */
    uint8_t field_0e0[8]; /* 0xE0 size=8 kind=r conf=low */
    uint8_t _pad_0e8[4]; /* 0xE8..0xEC */
    uint8_t field_0ec[8]; /* 0xEC size=8 kind=r conf=low */
    uint8_t _pad_0f4[4]; /* 0xF4..0xF8 */
    uint8_t field_0f8[8]; /* 0xF8 size=8 kind=r conf=low */
    uint8_t _pad_100[32]; /* 0x100..0x120 */
    uint8_t field_120[4]; /* 0x120 size=4 kind=w conf=medium */
    uint8_t _pad_124[4]; /* 0x124..0x128 */
    uint8_t field_128[8]; /* 0x128 size=8 kind=w conf=medium */
    uint8_t field_130[8]; /* 0x130 size=8 kind=r conf=low */
    uint8_t _pad_138[40]; /* 0x138..0x160 */
    uint8_t field_160[8]; /* 0x160 size=8 kind=r conf=low */
    uint8_t _pad_168[40]; /* 0x168..0x190 */
    uint8_t field_190[8]; /* 0x190 size=8 kind=r conf=low */
    uint8_t _pad_198[4]; /* 0x198..0x19C */
    uint8_t field_19c[4]; /* 0x19C size=4 kind=w conf=medium */
    uint8_t field_1a0[8]; /* 0x1A0 size=8 kind=w conf=medium */
    uint8_t _pad_1a8[8]; /* 0x1A8..0x1B0 */
    uint8_t field_1b0[8]; /* 0x1B0 size=8 kind=r conf=low */
    uint8_t _pad_1b8[8]; /* 0x1B8..0x1C0 */
    uint8_t field_1c0[8]; /* 0x1C0 size=8 kind=r conf=low */
    uint8_t _pad_1c8[928]; /* 0x1C8..0x568 */
    uint8_t field_568[4]; /* 0x568 size=4 kind=w conf=medium */
    uint8_t field_56c[8]; /* 0x56C size=8 kind=r conf=low */
    uint8_t _pad_574[4]; /* 0x574..0x578 */
    uint8_t field_578[8]; /* 0x578 size=8 kind=r conf=low */
    uint8_t _pad_580[4]; /* 0x580..0x584 */
    uint8_t field_584[8]; /* 0x584 size=8 kind=r conf=low */
    uint8_t _pad_58c[4]; /* 0x58C..0x590 */
    uint8_t field_590[4]; /* 0x590 size=4 kind=w conf=medium */
} ccHitGroup_partial_t;

/* ccEffectMassProduction: size >= 0xB48 (INFERRED from state_surface max_end 0xB41 + alignment) */
typedef struct {
    uint8_t _pad_000[360]; /* 0x0..0x168 */
    uint8_t field_168[8]; /* 0x168 size=8 kind=r conf=low */
    uint8_t _pad_170[56]; /* 0x170..0x1A8 */
    uint8_t field_1a8[4]; /* 0x1A8 size=4 kind=rw conf=medium */
    uint8_t field_1ac[4]; /* 0x1AC size=4 kind=rw conf=high */
    uint8_t field_1b0[4]; /* 0x1B0 size=4 kind=rw conf=high */
    uint8_t _pad_1b4[4]; /* 0x1B4..0x1B8 */
    uint8_t field_1b8[8]; /* 0x1B8 size=8 kind=r conf=low */
    uint8_t field_1c0[4]; /* 0x1C0 size=4 kind=rw conf=high */
    uint8_t _pad_1c4[12]; /* 0x1C4..0x1D0 */
    uint8_t field_1d0[8]; /* 0x1D0 size=8 kind=r conf=low */
    uint8_t _pad_1d8[8]; /* 0x1D8..0x1E0 */
    uint8_t field_1e0[4]; /* 0x1E0 size=4 kind=w conf=medium */
    uint8_t field_1e4[4]; /* 0x1E4 size=4 kind=w conf=medium */
    uint8_t field_1e8[4]; /* 0x1E8 size=4 kind=w conf=medium */
    uint8_t _pad_1ec[4]; /* 0x1EC..0x1F0 */
    uint8_t field_1f0[4]; /* 0x1F0 size=4 kind=w conf=medium */
    uint8_t _pad_1f4[1804]; /* 0x1F4..0x900 */
    uint8_t field_900[8]; /* 0x900 size=8 kind=r conf=low */
    uint8_t _pad_908[120]; /* 0x908..0x980 */
    uint8_t field_980[8]; /* 0x980 size=8 kind=r conf=low */
    uint8_t _pad_988[440]; /* 0x988..0xB40 */
    uint8_t field_b40[8]; /* 0xB40 size=8 kind=r conf=low */
} ccEffectMassProduction_partial_t;

/* ccSkillObjectFactory: size >= 0x240 (INFERRED from ctor writes up to +0x23C) */
typedef struct {
    uint8_t _pad_000[12]; /* 0x0..0xC */
    uint8_t field_00c[4]; /* 0xC size=4 kind=w conf=high */
    uint8_t _pad_010[12]; /* 0x10..0x1C */
    uint8_t field_01c[8]; /* 0x1C size=8 kind=r conf=low */
    uint8_t _pad_024[16]; /* 0x24..0x34 */
    uint8_t field_034[8]; /* 0x34 size=8 kind=rw conf=low */
    uint8_t field_03c[4]; /* 0x3C size=4 kind=w conf=medium */
    uint8_t _pad_040[12]; /* 0x40..0x4C */
    uint8_t field_04c[4]; /* 0x4C size=4 kind=w conf=high */
    uint8_t _pad_050[8]; /* 0x50..0x58 */
    uint8_t field_058[8]; /* 0x58 size=8 kind=w conf=medium */
    uint8_t field_060[8]; /* 0x60 size=8 kind=w conf=medium */
    uint8_t field_068[4]; /* 0x68 size=4 kind=w conf=medium */
    uint8_t _pad_06c[4]; /* 0x6C..0x70 */
    uint8_t field_070[8]; /* 0x70 size=8 kind=w conf=medium */
    uint8_t field_078[8]; /* 0x78 size=8 kind=r conf=low */
    uint8_t _pad_080[440]; /* 0x80..0x238 */
    uint8_t field_238[4]; /* 0x238 size=4 kind=w conf=medium */
    uint8_t field_23c[4]; /* 0x23C size=4 kind=w conf=high */
} ccSkillObjectFactory_partial_t;

/* ccSkillManager: size >= 0x88 (INFERRED from state_surface max_end 0x81 + alignment) */
typedef struct {
    uint8_t _pad_000[28]; /* 0x0..0x1C */
    uint8_t field_01c[4]; /* 0x1C size=4 kind=rw conf=high */
    uint8_t _pad_020[56]; /* 0x20..0x58 */
    uint8_t field_058[4]; /* 0x58 size=4 kind=rw conf=low */
    uint8_t _pad_05c[4]; /* 0x5C..0x60 */
    uint8_t field_060[8]; /* 0x60 size=8 kind=w conf=medium */
    uint8_t field_068[8]; /* 0x68 size=8 kind=w conf=medium */
    uint8_t field_070[8]; /* 0x70 size=8 kind=rw conf=high */
    uint8_t field_078[8]; /* 0x78 size=8 kind=r conf=low */
    uint8_t field_080[8]; /* 0x80 size=8 kind=r conf=low */
} ccSkillManager_partial_t;

/* ccSkillLoader: size >= 0x88 (INFERRED from state_surface max_end 0x81 + alignment) */
typedef struct {
    uint8_t _pad_000[64]; /* 0x0..0x40 */
    uint8_t field_040[4]; /* 0x40 size=4 kind=w conf=medium */
    uint8_t _pad_044[60]; /* 0x44..0x80 */
    uint8_t field_080[8]; /* 0x80 size=8 kind=r conf=low */
} ccSkillLoader_partial_t;

/* ccSkillGroupManager: size >= 0x88 (INFERRED from state_surface max_end 0x81 + alignment) */
typedef struct {
    uint8_t _pad_000[44]; /* 0x0..0x2C */
    uint8_t field_02c[4]; /* 0x2C size=4 kind=w conf=high */
    uint8_t _pad_030[80]; /* 0x30..0x80 */
    uint8_t field_080[8]; /* 0x80 size=8 kind=r conf=low */
} ccSkillGroupManager_partial_t;

/* ccHitSphereGroup: size >= 0xCD0 (INFERRED from state_surface max_end 0xCC8 + alignment) */
typedef struct {
    uint8_t _pad_000[3232]; /* 0x0..0xCA0 */
    uint8_t field_ca0[8]; /* 0xCA0 size=8 kind=r conf=medium */
    uint8_t _pad_ca8[24]; /* 0xCA8..0xCC0 */
    uint8_t field_cc0[8]; /* 0xCC0 size=8 kind=r conf=medium */
} ccHitSphereGroup_partial_t;

/* ccSkillActorBoundBall: size >= 0x48 (INFERRED from state_surface max_end 0x34 + alignment; s3 had >= 0x34) */
typedef struct {
    uint8_t _pad_000[44]; /* 0x0..0x2C */
    uint8_t field_02c[8]; /* 0x2C size=8 kind=w conf=medium */
} ccSkillActorBoundBall_partial_t;

#pragma pack(pop)

/* Offset verification asserts */
static_assert(offsetof(ccGameObjectSkill_partial_t, field_070) == 0x70, "ccGameObjectSkill.field_070 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_078) == 0x78, "ccGameObjectSkill.field_078 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_080) == 0x80, "ccGameObjectSkill.field_080 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_090) == 0x90, "ccGameObjectSkill.field_090 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_098) == 0x98, "ccGameObjectSkill.field_098 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0a0) == 0xA0, "ccGameObjectSkill.field_0a0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0a8) == 0xA8, "ccGameObjectSkill.field_0a8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0ac) == 0xAC, "ccGameObjectSkill.field_0ac offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0ec) == 0xEC, "ccGameObjectSkill.field_0ec offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0f0) == 0xF0, "ccGameObjectSkill.field_0f0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0f4) == 0xF4, "ccGameObjectSkill.field_0f4 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_0f8) == 0xF8, "ccGameObjectSkill.field_0f8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_100) == 0x100, "ccGameObjectSkill.field_100 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_108) == 0x108, "ccGameObjectSkill.field_108 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_110) == 0x110, "ccGameObjectSkill.field_110 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_118) == 0x118, "ccGameObjectSkill.field_118 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_140) == 0x140, "ccGameObjectSkill.field_140 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_148) == 0x148, "ccGameObjectSkill.field_148 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_15c) == 0x15C, "ccGameObjectSkill.field_15c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_160) == 0x160, "ccGameObjectSkill.field_160 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_168) == 0x168, "ccGameObjectSkill.field_168 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_16c) == 0x16C, "ccGameObjectSkill.field_16c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_174) == 0x174, "ccGameObjectSkill.field_174 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_17c) == 0x17C, "ccGameObjectSkill.field_17c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_184) == 0x184, "ccGameObjectSkill.field_184 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_18c) == 0x18C, "ccGameObjectSkill.field_18c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_194) == 0x194, "ccGameObjectSkill.field_194 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_19c) == 0x19C, "ccGameObjectSkill.field_19c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1a4) == 0x1A4, "ccGameObjectSkill.field_1a4 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1ac) == 0x1AC, "ccGameObjectSkill.field_1ac offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1b0) == 0x1B0, "ccGameObjectSkill.field_1b0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1b8) == 0x1B8, "ccGameObjectSkill.field_1b8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1c0) == 0x1C0, "ccGameObjectSkill.field_1c0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1c8) == 0x1C8, "ccGameObjectSkill.field_1c8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1cc) == 0x1CC, "ccGameObjectSkill.field_1cc offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1d0) == 0x1D0, "ccGameObjectSkill.field_1d0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1dc) == 0x1DC, "ccGameObjectSkill.field_1dc offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1e0) == 0x1E0, "ccGameObjectSkill.field_1e0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1e8) == 0x1E8, "ccGameObjectSkill.field_1e8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_1fc) == 0x1FC, "ccGameObjectSkill.field_1fc offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_200) == 0x200, "ccGameObjectSkill.field_200 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_208) == 0x208, "ccGameObjectSkill.field_208 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_210) == 0x210, "ccGameObjectSkill.field_210 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_21c) == 0x21C, "ccGameObjectSkill.field_21c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_234) == 0x234, "ccGameObjectSkill.field_234 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_238) == 0x238, "ccGameObjectSkill.field_238 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_240) == 0x240, "ccGameObjectSkill.field_240 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_248) == 0x248, "ccGameObjectSkill.field_248 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_250) == 0x250, "ccGameObjectSkill.field_250 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_254) == 0x254, "ccGameObjectSkill.field_254 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_258) == 0x258, "ccGameObjectSkill.field_258 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_360) == 0x360, "ccGameObjectSkill.field_360 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_380) == 0x380, "ccGameObjectSkill.field_380 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_3a8) == 0x3A8, "ccGameObjectSkill.field_3a8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_3b0) == 0x3B0, "ccGameObjectSkill.field_3b0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_3b8) == 0x3B8, "ccGameObjectSkill.field_3b8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_3c0) == 0x3C0, "ccGameObjectSkill.field_3c0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_3f0) == 0x3F0, "ccGameObjectSkill.field_3f0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_400) == 0x400, "ccGameObjectSkill.field_400 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_438) == 0x438, "ccGameObjectSkill.field_438 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_440) == 0x440, "ccGameObjectSkill.field_440 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_470) == 0x470, "ccGameObjectSkill.field_470 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_47c) == 0x47C, "ccGameObjectSkill.field_47c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_480) == 0x480, "ccGameObjectSkill.field_480 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_488) == 0x488, "ccGameObjectSkill.field_488 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_490) == 0x490, "ccGameObjectSkill.field_490 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_494) == 0x494, "ccGameObjectSkill.field_494 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_49c) == 0x49C, "ccGameObjectSkill.field_49c offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4a0) == 0x4A0, "ccGameObjectSkill.field_4a0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4b0) == 0x4B0, "ccGameObjectSkill.field_4b0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4b8) == 0x4B8, "ccGameObjectSkill.field_4b8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4bc) == 0x4BC, "ccGameObjectSkill.field_4bc offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4c0) == 0x4C0, "ccGameObjectSkill.field_4c0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4f0) == 0x4F0, "ccGameObjectSkill.field_4f0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_4f8) == 0x4F8, "ccGameObjectSkill.field_4f8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_508) == 0x508, "ccGameObjectSkill.field_508 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_520) == 0x520, "ccGameObjectSkill.field_520 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_550) == 0x550, "ccGameObjectSkill.field_550 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_558) == 0x558, "ccGameObjectSkill.field_558 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_580) == 0x580, "ccGameObjectSkill.field_580 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_588) == 0x588, "ccGameObjectSkill.field_588 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_598) == 0x598, "ccGameObjectSkill.field_598 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5b0) == 0x5B0, "ccGameObjectSkill.field_5b0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5b4) == 0x5B4, "ccGameObjectSkill.field_5b4 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5c0) == 0x5C0, "ccGameObjectSkill.field_5c0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5c8) == 0x5C8, "ccGameObjectSkill.field_5c8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5d8) == 0x5D8, "ccGameObjectSkill.field_5d8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5f0) == 0x5F0, "ccGameObjectSkill.field_5f0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_5f8) == 0x5F8, "ccGameObjectSkill.field_5f8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_600) == 0x600, "ccGameObjectSkill.field_600 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_608) == 0x608, "ccGameObjectSkill.field_608 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_610) == 0x610, "ccGameObjectSkill.field_610 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_618) == 0x618, "ccGameObjectSkill.field_618 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_620) == 0x620, "ccGameObjectSkill.field_620 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_628) == 0x628, "ccGameObjectSkill.field_628 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_630) == 0x630, "ccGameObjectSkill.field_630 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_644) == 0x644, "ccGameObjectSkill.field_644 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_648) == 0x648, "ccGameObjectSkill.field_648 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_650) == 0x650, "ccGameObjectSkill.field_650 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_678) == 0x678, "ccGameObjectSkill.field_678 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_6c0) == 0x6C0, "ccGameObjectSkill.field_6c0 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_6c8) == 0x6C8, "ccGameObjectSkill.field_6c8 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_6d4) == 0x6D4, "ccGameObjectSkill.field_6d4 offset mismatch");
static_assert(offsetof(ccGameObjectSkill_partial_t, field_6d8) == 0x6D8, "ccGameObjectSkill.field_6d8 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_054) == 0x54, "ccHitGroup.field_054 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_05c) == 0x5C, "ccHitGroup.field_05c offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_060) == 0x60, "ccHitGroup.field_060 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_068) == 0x68, "ccHitGroup.field_068 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_070) == 0x70, "ccHitGroup.field_070 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_074) == 0x74, "ccHitGroup.field_074 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_080) == 0x80, "ccHitGroup.field_080 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0a4) == 0xA4, "ccHitGroup.field_0a4 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0ac) == 0xAC, "ccHitGroup.field_0ac offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0b8) == 0xB8, "ccHitGroup.field_0b8 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0c0) == 0xC0, "ccHitGroup.field_0c0 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0c8) == 0xC8, "ccHitGroup.field_0c8 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0d4) == 0xD4, "ccHitGroup.field_0d4 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0e0) == 0xE0, "ccHitGroup.field_0e0 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0ec) == 0xEC, "ccHitGroup.field_0ec offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_0f8) == 0xF8, "ccHitGroup.field_0f8 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_120) == 0x120, "ccHitGroup.field_120 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_128) == 0x128, "ccHitGroup.field_128 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_130) == 0x130, "ccHitGroup.field_130 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_160) == 0x160, "ccHitGroup.field_160 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_190) == 0x190, "ccHitGroup.field_190 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_19c) == 0x19C, "ccHitGroup.field_19c offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_1a0) == 0x1A0, "ccHitGroup.field_1a0 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_1b0) == 0x1B0, "ccHitGroup.field_1b0 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_1c0) == 0x1C0, "ccHitGroup.field_1c0 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_568) == 0x568, "ccHitGroup.field_568 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_56c) == 0x56C, "ccHitGroup.field_56c offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_578) == 0x578, "ccHitGroup.field_578 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_584) == 0x584, "ccHitGroup.field_584 offset mismatch");
static_assert(offsetof(ccHitGroup_partial_t, field_590) == 0x590, "ccHitGroup.field_590 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_168) == 0x168, "ccEffectMassProduction.field_168 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1a8) == 0x1A8, "ccEffectMassProduction.field_1a8 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1ac) == 0x1AC, "ccEffectMassProduction.field_1ac offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1b0) == 0x1B0, "ccEffectMassProduction.field_1b0 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1b8) == 0x1B8, "ccEffectMassProduction.field_1b8 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1c0) == 0x1C0, "ccEffectMassProduction.field_1c0 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1d0) == 0x1D0, "ccEffectMassProduction.field_1d0 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1e0) == 0x1E0, "ccEffectMassProduction.field_1e0 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1e4) == 0x1E4, "ccEffectMassProduction.field_1e4 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1e8) == 0x1E8, "ccEffectMassProduction.field_1e8 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_1f0) == 0x1F0, "ccEffectMassProduction.field_1f0 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_900) == 0x900, "ccEffectMassProduction.field_900 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_980) == 0x980, "ccEffectMassProduction.field_980 offset mismatch");
static_assert(offsetof(ccEffectMassProduction_partial_t, field_b40) == 0xB40, "ccEffectMassProduction.field_b40 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_00c) == 0xC, "ccSkillObjectFactory.field_00c offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_01c) == 0x1C, "ccSkillObjectFactory.field_01c offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_034) == 0x34, "ccSkillObjectFactory.field_034 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_03c) == 0x3C, "ccSkillObjectFactory.field_03c offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_04c) == 0x4C, "ccSkillObjectFactory.field_04c offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_058) == 0x58, "ccSkillObjectFactory.field_058 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_060) == 0x60, "ccSkillObjectFactory.field_060 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_068) == 0x68, "ccSkillObjectFactory.field_068 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_070) == 0x70, "ccSkillObjectFactory.field_070 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_078) == 0x78, "ccSkillObjectFactory.field_078 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_238) == 0x238, "ccSkillObjectFactory.field_238 offset mismatch");
static_assert(offsetof(ccSkillObjectFactory_partial_t, field_23c) == 0x23C, "ccSkillObjectFactory.field_23c offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_01c) == 0x1C, "ccSkillManager.field_01c offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_058) == 0x58, "ccSkillManager.field_058 offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_060) == 0x60, "ccSkillManager.field_060 offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_068) == 0x68, "ccSkillManager.field_068 offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_070) == 0x70, "ccSkillManager.field_070 offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_078) == 0x78, "ccSkillManager.field_078 offset mismatch");
static_assert(offsetof(ccSkillManager_partial_t, field_080) == 0x80, "ccSkillManager.field_080 offset mismatch");
static_assert(offsetof(ccSkillLoader_partial_t, field_040) == 0x40, "ccSkillLoader.field_040 offset mismatch");
static_assert(offsetof(ccSkillLoader_partial_t, field_080) == 0x80, "ccSkillLoader.field_080 offset mismatch");
static_assert(offsetof(ccSkillGroupManager_partial_t, field_02c) == 0x2C, "ccSkillGroupManager.field_02c offset mismatch");
static_assert(offsetof(ccSkillGroupManager_partial_t, field_080) == 0x80, "ccSkillGroupManager.field_080 offset mismatch");
static_assert(offsetof(ccHitSphereGroup_partial_t, field_ca0) == 0xCA0, "ccHitSphereGroup.field_ca0 offset mismatch");
static_assert(offsetof(ccHitSphereGroup_partial_t, field_cc0) == 0xCC0, "ccHitSphereGroup.field_cc0 offset mismatch");
static_assert(offsetof(ccSkillActorBoundBall_partial_t, field_02c) == 0x2C, "ccSkillActorBoundBall.field_02c offset mismatch");

