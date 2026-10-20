/* st2a16.h - Storm 2 (s2) adventure UI structs */
/* INFERRED from static analysis, not CONFIRMED at runtime */
#include <stdint.h>
#include <stddef.h>

/* ccUiAdvGauge — 4 seed methods, size 0x8D0 */
/* Size evidence: ccFileLoadListForUi::LoadTh(0x8d0) in ccAdvPlayerUiManager::_CreateGaugePlayer */
typedef struct {
    uint8_t _pad_0[84];
    uint32_t f54; /* 0x54 w medium [PRES] */
    uint32_t f58; /* 0x58 w low [UNKNOWN] */
    uint32_t f5C; /* 0x5C w medium [PRES] */
    uint64_t f60; /* 0x60 w high [PRES] */
    uint8_t f68[2040]; /* 0x68 r low [UNKNOWN] */
    uint64_t f860; /* 0x860 w medium [PRES] */
    uint64_t f868; /* 0x868 r low [UNKNOWN] */
    uint64_t f870; /* 0x870 w medium [PRES] */
    uint64_t f878; /* 0x878 r/w medium [SIM] */
    uint8_t f880[24]; /* 0x880 r/w low [SIM] */
    uint64_t f898; /* 0x898 w medium [PRES] */
    uint64_t f8A0; /* 0x8A0 w medium [PRES] */
    uint64_t f8A8; /* 0x8A8 w medium [PRES] */
    uint64_t f8B0; /* 0x8B0 w medium [PRES] */
    uint64_t f8B8; /* 0x8B8 w medium [PRES] */
    uint32_t f8C0; /* 0x8C0 r low [UNKNOWN] */
    uint8_t _tail_8C4[12]; /* padding to proven size 0x8D0 */
} __attribute__((packed)) ccUiAdvGauge;
_Static_assert(offsetof(ccUiAdvGauge, f54) == 0x54, "ccUiAdvGauge.f54 offset");
_Static_assert(offsetof(ccUiAdvGauge, f58) == 0x58, "ccUiAdvGauge.f58 offset");
_Static_assert(offsetof(ccUiAdvGauge, f5C) == 0x5C, "ccUiAdvGauge.f5C offset");
_Static_assert(offsetof(ccUiAdvGauge, f60) == 0x60, "ccUiAdvGauge.f60 offset");
_Static_assert(offsetof(ccUiAdvGauge, f68) == 0x68, "ccUiAdvGauge.f68 offset");
_Static_assert(offsetof(ccUiAdvGauge, f860) == 0x860, "ccUiAdvGauge.f860 offset");
_Static_assert(offsetof(ccUiAdvGauge, f868) == 0x868, "ccUiAdvGauge.f868 offset");
_Static_assert(offsetof(ccUiAdvGauge, f870) == 0x870, "ccUiAdvGauge.f870 offset");
_Static_assert(offsetof(ccUiAdvGauge, f878) == 0x878, "ccUiAdvGauge.f878 offset");
_Static_assert(offsetof(ccUiAdvGauge, f880) == 0x880, "ccUiAdvGauge.f880 offset");
_Static_assert(offsetof(ccUiAdvGauge, f898) == 0x898, "ccUiAdvGauge.f898 offset");
_Static_assert(offsetof(ccUiAdvGauge, f8A0) == 0x8A0, "ccUiAdvGauge.f8A0 offset");
_Static_assert(offsetof(ccUiAdvGauge, f8A8) == 0x8A8, "ccUiAdvGauge.f8A8 offset");
_Static_assert(offsetof(ccUiAdvGauge, f8B0) == 0x8B0, "ccUiAdvGauge.f8B0 offset");
_Static_assert(offsetof(ccUiAdvGauge, f8B8) == 0x8B8, "ccUiAdvGauge.f8B8 offset");
_Static_assert(offsetof(ccUiAdvGauge, f8C0) == 0x8C0, "ccUiAdvGauge.f8C0 offset");

/* ccUiAdvHokageMenuIndex — 11 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0xD4 */
typedef struct {
    uint8_t _pad_0[68];
    uint8_t f44[16]; /* 0x44 r medium [UNKNOWN] */
    uint64_t f54; /* 0x54 r low [UNKNOWN] */
    uint8_t f5C[16]; /* 0x5C w medium [PRES] */
    uint8_t f6C[16]; /* 0x6C r low [UNKNOWN] */
    uint32_t f7C; /* 0x7C r/w high [SIM] */
    uint8_t f80[84]; /* 0x80 r/w medium [SIM] */
    uint32_t fD4; /* 0xD4 w medium [PRES] */
} __attribute__((packed)) ccUiAdvHokageMenuIndex;
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, f44) == 0x44, "ccUiAdvHokageMenuIndex.f44 offset");
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, f54) == 0x54, "ccUiAdvHokageMenuIndex.f54 offset");
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, f5C) == 0x5C, "ccUiAdvHokageMenuIndex.f5C offset");
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, f6C) == 0x6C, "ccUiAdvHokageMenuIndex.f6C offset");
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, f7C) == 0x7C, "ccUiAdvHokageMenuIndex.f7C offset");
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, f80) == 0x80, "ccUiAdvHokageMenuIndex.f80 offset");
_Static_assert(offsetof(ccUiAdvHokageMenuIndex, fD4) == 0xD4, "ccUiAdvHokageMenuIndex.fD4 offset");

/* ccUiAdvIndexSelect — 7 seed methods, size unknown */
/* Size evidence: unknown */
typedef struct {
    uint8_t _empty[1]; /* no fields surfaced */
} __attribute__((packed)) ccUiAdvIndexSelect;

/* ccUiAdvItemCustomize — 13 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0xB0 */
typedef struct {
    uint8_t _pad_0[88];
    uint64_t f58; /* 0x58 w medium [PRES] */
    uint64_t f60; /* 0x60 w medium [PRES] */
    uint64_t f68; /* 0x68 w medium [PRES] */
    uint64_t f70; /* 0x70 w medium [PRES] */
    uint64_t f78; /* 0x78 w medium [PRES] */
    uint64_t f80; /* 0x80 w medium [PRES] */
    uint64_t f88; /* 0x88 w medium [PRES] */
    uint64_t f90; /* 0x90 w medium [PRES] */
    uint64_t f98; /* 0x98 w medium [PRES] */
    uint64_t fA0; /* 0xA0 w medium [PRES] */
    uint64_t fA8; /* 0xA8 w medium [PRES] */
    uint64_t fB0; /* 0xB0 r/w low [SIM] */
    uint64_t fB8; /* 0xB8 w medium [PRES] */
    uint8_t fC0[16]; /* 0xC0 r low [UNKNOWN] */
    uint64_t fD0; /* 0xD0 r/w low [SIM] */
} __attribute__((packed)) ccUiAdvItemCustomize;
_Static_assert(offsetof(ccUiAdvItemCustomize, f58) == 0x58, "ccUiAdvItemCustomize.f58 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f60) == 0x60, "ccUiAdvItemCustomize.f60 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f68) == 0x68, "ccUiAdvItemCustomize.f68 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f70) == 0x70, "ccUiAdvItemCustomize.f70 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f78) == 0x78, "ccUiAdvItemCustomize.f78 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f80) == 0x80, "ccUiAdvItemCustomize.f80 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f88) == 0x88, "ccUiAdvItemCustomize.f88 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f90) == 0x90, "ccUiAdvItemCustomize.f90 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, f98) == 0x98, "ccUiAdvItemCustomize.f98 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, fA0) == 0xA0, "ccUiAdvItemCustomize.fA0 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, fA8) == 0xA8, "ccUiAdvItemCustomize.fA8 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, fB0) == 0xB0, "ccUiAdvItemCustomize.fB0 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, fB8) == 0xB8, "ccUiAdvItemCustomize.fB8 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, fC0) == 0xC0, "ccUiAdvItemCustomize.fC0 offset");
_Static_assert(offsetof(ccUiAdvItemCustomize, fD0) == 0xD0, "ccUiAdvItemCustomize.fD0 offset");

/* ccUiAdvItemIcon — 7 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0x8C */
typedef struct {
    uint8_t _pad_0[84];
    uint32_t f54; /* 0x54 w medium [PRES] */
    uint64_t f58; /* 0x58 r/w low [SIM] */
    uint64_t f60; /* 0x60 w medium [PRES] */
    uint32_t f68; /* 0x68 w medium [PRES] */
    uint32_t f6C; /* 0x6C w medium [PRES] */
    uint32_t f70; /* 0x70 r/w low [SIM] */
    uint32_t f74; /* 0x74 w medium [PRES] */
    uint32_t f78; /* 0x78 w medium [PRES] */
    uint64_t f7C; /* 0x7C r/w low [SIM] */
    uint32_t f84; /* 0x84 w medium [PRES] */
    uint32_t f88; /* 0x88 w high [PRES] */
    uint8_t f8C[52]; /* 0x8C w high [PRES] */
    uint32_t fC0; /* 0xC0 r low [UNKNOWN] */
} __attribute__((packed)) ccUiAdvItemIcon;
_Static_assert(offsetof(ccUiAdvItemIcon, f54) == 0x54, "ccUiAdvItemIcon.f54 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f58) == 0x58, "ccUiAdvItemIcon.f58 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f60) == 0x60, "ccUiAdvItemIcon.f60 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f68) == 0x68, "ccUiAdvItemIcon.f68 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f6C) == 0x6C, "ccUiAdvItemIcon.f6C offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f70) == 0x70, "ccUiAdvItemIcon.f70 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f74) == 0x74, "ccUiAdvItemIcon.f74 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f78) == 0x78, "ccUiAdvItemIcon.f78 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f7C) == 0x7C, "ccUiAdvItemIcon.f7C offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f84) == 0x84, "ccUiAdvItemIcon.f84 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f88) == 0x88, "ccUiAdvItemIcon.f88 offset");
_Static_assert(offsetof(ccUiAdvItemIcon, f8C) == 0x8C, "ccUiAdvItemIcon.f8C offset");
_Static_assert(offsetof(ccUiAdvItemIcon, fC0) == 0xC0, "ccUiAdvItemIcon.fC0 offset");

/* ccUiAdvItemMainMenu — 19 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0x124 */
typedef struct {
    uint8_t _pad_0[88];
    uint64_t f58; /* 0x58 w high [PRES] */
    uint64_t f60; /* 0x60 r/w high [SIM] */
    uint64_t f68; /* 0x68 r/w high [SIM] */
    uint64_t f70; /* 0x70 r/w high [SIM] */
    uint64_t f78; /* 0x78 w high [PRES] */
    uint64_t f80; /* 0x80 w medium [PRES] */
    uint64_t f88; /* 0x88 r/w low [SIM] */
    uint64_t f90; /* 0x90 w medium [PRES] */
    uint64_t f98; /* 0x98 w medium [PRES] */
    uint64_t fA0; /* 0xA0 w medium [PRES] */
    uint64_t fA8; /* 0xA8 w medium [PRES] */
    uint64_t fB0; /* 0xB0 w medium [PRES] */
    uint64_t fB8; /* 0xB8 r/w low [SIM] */
    uint64_t fC0; /* 0xC0 r/w low [SIM] */
    uint64_t fC8; /* 0xC8 r/w low [SIM] */
    uint64_t fD0; /* 0xD0 w medium [PRES] */
    uint64_t fD8; /* 0xD8 w medium [PRES] */
    uint64_t fE0; /* 0xE0 w medium [PRES] */
    uint64_t fE8; /* 0xE8 w medium [PRES] */
    uint64_t fF0; /* 0xF0 w medium [PRES] */
    uint64_t fF8; /* 0xF8 w medium [PRES] */
    uint64_t f100; /* 0x100 w medium [PRES] */
    uint64_t f108; /* 0x108 w high [PRES] */
    uint64_t f110; /* 0x110 w medium [PRES] */
    uint32_t f118; /* 0x118 w medium [PRES] */
    uint32_t f11C; /* 0x11C w medium [PRES] */
    uint32_t f120; /* 0x120 w high [PRES] */
    uint8_t f124[12]; /* 0x124 r/w low [SIM] */
    uint64_t f130; /* 0x130 r low [UNKNOWN] */
    uint64_t f138; /* 0x138 r/w high [SIM] */
    uint64_t f140; /* 0x140 r/w low [SIM] */
} __attribute__((packed)) ccUiAdvItemMainMenu;
_Static_assert(offsetof(ccUiAdvItemMainMenu, f58) == 0x58, "ccUiAdvItemMainMenu.f58 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f60) == 0x60, "ccUiAdvItemMainMenu.f60 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f68) == 0x68, "ccUiAdvItemMainMenu.f68 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f70) == 0x70, "ccUiAdvItemMainMenu.f70 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f78) == 0x78, "ccUiAdvItemMainMenu.f78 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f80) == 0x80, "ccUiAdvItemMainMenu.f80 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f88) == 0x88, "ccUiAdvItemMainMenu.f88 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f90) == 0x90, "ccUiAdvItemMainMenu.f90 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f98) == 0x98, "ccUiAdvItemMainMenu.f98 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fA0) == 0xA0, "ccUiAdvItemMainMenu.fA0 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fA8) == 0xA8, "ccUiAdvItemMainMenu.fA8 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fB0) == 0xB0, "ccUiAdvItemMainMenu.fB0 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fB8) == 0xB8, "ccUiAdvItemMainMenu.fB8 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fC0) == 0xC0, "ccUiAdvItemMainMenu.fC0 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fC8) == 0xC8, "ccUiAdvItemMainMenu.fC8 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fD0) == 0xD0, "ccUiAdvItemMainMenu.fD0 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fD8) == 0xD8, "ccUiAdvItemMainMenu.fD8 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fE0) == 0xE0, "ccUiAdvItemMainMenu.fE0 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fE8) == 0xE8, "ccUiAdvItemMainMenu.fE8 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fF0) == 0xF0, "ccUiAdvItemMainMenu.fF0 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, fF8) == 0xF8, "ccUiAdvItemMainMenu.fF8 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f100) == 0x100, "ccUiAdvItemMainMenu.f100 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f108) == 0x108, "ccUiAdvItemMainMenu.f108 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f110) == 0x110, "ccUiAdvItemMainMenu.f110 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f118) == 0x118, "ccUiAdvItemMainMenu.f118 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f11C) == 0x11C, "ccUiAdvItemMainMenu.f11C offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f120) == 0x120, "ccUiAdvItemMainMenu.f120 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f124) == 0x124, "ccUiAdvItemMainMenu.f124 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f130) == 0x130, "ccUiAdvItemMainMenu.f130 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f138) == 0x138, "ccUiAdvItemMainMenu.f138 offset");
_Static_assert(offsetof(ccUiAdvItemMainMenu, f140) == 0x140, "ccUiAdvItemMainMenu.f140 offset");

/* ccUiAdvItemMainMenuBack — 3 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0x50 */
typedef struct {
    uint8_t _pad_0[88];
    uint32_t f58; /* 0x58 w medium [PRES] */
} __attribute__((packed)) ccUiAdvItemMainMenuBack;
_Static_assert(offsetof(ccUiAdvItemMainMenuBack, f58) == 0x58, "ccUiAdvItemMainMenuBack.f58 offset");

/* ccUiAdvItemManager — 6 seed methods, size unknown */
/* Size evidence: unknown */
typedef struct {
    uint8_t _empty[1]; /* no fields surfaced */
} __attribute__((packed)) ccUiAdvItemManager;

/* ccUiAdvItemPalette — 18 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0x74 */
typedef struct {
    uint8_t _pad_0[88];
    uint64_t f58; /* 0x58 w medium [PRES] */
    uint64_t f60; /* 0x60 w medium [PRES] */
    uint32_t f68; /* 0x68 w medium [PRES] */
    uint64_t f6C; /* 0x6C r/w low [SIM] */
    uint8_t f74[76]; /* 0x74 w high [PRES] */
    uint32_t fC0; /* 0xC0 r low [UNKNOWN] */
} __attribute__((packed)) ccUiAdvItemPalette;
_Static_assert(offsetof(ccUiAdvItemPalette, f58) == 0x58, "ccUiAdvItemPalette.f58 offset");
_Static_assert(offsetof(ccUiAdvItemPalette, f60) == 0x60, "ccUiAdvItemPalette.f60 offset");
_Static_assert(offsetof(ccUiAdvItemPalette, f68) == 0x68, "ccUiAdvItemPalette.f68 offset");
_Static_assert(offsetof(ccUiAdvItemPalette, f6C) == 0x6C, "ccUiAdvItemPalette.f6C offset");
_Static_assert(offsetof(ccUiAdvItemPalette, f74) == 0x74, "ccUiAdvItemPalette.f74 offset");
_Static_assert(offsetof(ccUiAdvItemPalette, fC0) == 0xC0, "ccUiAdvItemPalette.fC0 offset");

/* ccUiAdvItemSelectHead — 9 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0xA4 */
typedef struct {
    uint8_t _pad_0[88];
    uint64_t f58; /* 0x58 w medium [PRES] */
    uint64_t f60; /* 0x60 r/w low [SIM] */
    uint32_t f68; /* 0x68 w medium [PRES] */
    uint32_t f6C; /* 0x6C w high [PRES] */
    uint32_t f70; /* 0x70 w high [PRES] */
    uint8_t f74[40]; /* 0x74 w high [PRES] */
    uint32_t f9C; /* 0x9C w medium [PRES] */
    uint32_t fA0; /* 0xA0 r/w high [SIM] */
    uint8_t fA4[28]; /* 0xA4 w high [PRES] */
    uint32_t fC0; /* 0xC0 r low [UNKNOWN] */
} __attribute__((packed)) ccUiAdvItemSelectHead;
_Static_assert(offsetof(ccUiAdvItemSelectHead, f58) == 0x58, "ccUiAdvItemSelectHead.f58 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, f60) == 0x60, "ccUiAdvItemSelectHead.f60 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, f68) == 0x68, "ccUiAdvItemSelectHead.f68 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, f6C) == 0x6C, "ccUiAdvItemSelectHead.f6C offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, f70) == 0x70, "ccUiAdvItemSelectHead.f70 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, f74) == 0x74, "ccUiAdvItemSelectHead.f74 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, f9C) == 0x9C, "ccUiAdvItemSelectHead.f9C offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, fA0) == 0xA0, "ccUiAdvItemSelectHead.fA0 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, fA4) == 0xA4, "ccUiAdvItemSelectHead.fA4 offset");
_Static_assert(offsetof(ccUiAdvItemSelectHead, fC0) == 0xC0, "ccUiAdvItemSelectHead.fC0 offset");

/* ccUiAdvItemUse — 6 seed methods, size unknown */
/* Size evidence: highest ctor access at offset 0x50 */
typedef struct {
    uint8_t _empty[1]; /* no fields surfaced */
} __attribute__((packed)) ccUiAdvItemUse;

