/* st3a20.h - Storm 3 Full Burst HD (s3) struct group st3a20
 * INFERRED from static analysis. Not CONFIRMED.
 */
#ifndef ST3A20_H
#define ST3A20_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccUiAdvRecoveryWindow */
/* vtable: PTR_FUN_1408b4bb8 */
/* size: 0x110 (272) from FUN_1401c84d8 (ccSceneShopRecovery) */
typedef struct __attribute__((packed)) ns3_ccUiAdvRecoveryWindow {
    uint8_t _pad_0x0[88];
    uint32_t field_0x58;
    uint8_t _pad_0x5c[4];
    uint64_t field_0x60;
    uint8_t field_0x68; /* size unknown */
    uint8_t _pad_0x69[47];
    uint8_t field_0x98; /* size unknown */
    uint8_t _pad_0x99[63];
    uint32_t field_0xd8;
    uint64_t field_0xdc;
    uint64_t field_0xe4;
    uint64_t field_0xec;
    uint64_t field_0xf4;
    uint32_t field_0xfc;
    uint32_t field_0x100;
    uint8_t _pad_0x104[4];
    uint64_t field_0x108;
} ns3_ccUiAdvRecoveryWindow;

/* ccUiAdvRewardWindow */
/* vtable: PTR_FUN_1408b4cd0 */
/* size: 0x88 (136) from FUN_140189994 (ccAdvBattleEndSequence) */
typedef struct __attribute__((packed)) ns3_ccUiAdvRewardWindow {
    uint8_t _pad_0x0[120];
    uint64_t field_0x78;
    uint32_t field_0x80;
    uint8_t _pad_trail[4];
} ns3_ccUiAdvRewardWindow;

/* ccUiAdvStartMenu */
/* vtable: PTR_FUN_1408b8598 */
/* size: 0x170 (368) from FUN_140211b48 (ccSceneAdvStartMenu::Initialize) */
typedef struct __attribute__((packed)) ns3_ccUiAdvStartMenu {
    uint8_t _pad_0x0[120];
    uint8_t field_0x78; /* size unknown */
    uint8_t _pad_0x79[95];
    uint8_t field_0xd8; /* size unknown */
    uint8_t _pad_0xd9[23];
    uint64_t field_0xf0;
    uint8_t _pad_0xf8[16];
    uint64_t field_0x108;
    uint8_t _pad_0x110[8];
    uint64_t field_0x118;
    uint8_t _pad_0x120[16];
    uint64_t field_0x130;
    uint8_t _pad_0x138[8];
    uint64_t field_0x140;
    uint8_t _pad_trail[40];
} ns3_ccUiAdvStartMenu;

/* ccUiAdvStartMenuCmn: no fields, size unknown -- skipped */

/* ccUiAdvStartMenuItemList */
/* vtable: PTR_FUN_1408bc608 */
/* size: 0xe88 (3720) from FUN_140221440 */
typedef struct __attribute__((packed)) ns3_ccUiAdvStartMenuItemList {
    uint8_t _pad_0x0[88];
    uint32_t field_0x58;
    uint8_t _pad_0x5c[4];
    uint64_t field_0x60;
    uint64_t field_0x68;
    uint64_t field_0x70;
    uint32_t field_0x78;
    uint64_t field_0x7c;
    uint8_t _pad_0x84[4];
    uint8_t field_0x88; /* size unknown */
    uint8_t _pad_0x89[39];
    uint32_t field_0xb0;
    uint8_t _pad_0xb4[4];
    uint64_t field_0xb8;
    uint8_t _pad_0xc0[16];
    uint8_t field_0xd0; /* size unknown */
    uint8_t _pad_0xd1[31];
    uint64_t field_0xf0;
    uint64_t field_0xf8;
    uint64_t field_0x100;
    uint8_t field_0x108; /* size unknown */
    uint8_t _pad_0x109[7];
    uint64_t field_0x110;
    uint64_t field_0x118;
    uint64_t field_0x120;
    uint8_t _pad_0x128[16];
    uint64_t field_0x138;
    uint32_t field_0x140;
    uint8_t _pad_0x144[4];
    uint64_t field_0x148;
    uint64_t field_0x150;
    uint64_t field_0x158;
    uint8_t field_0x160; /* size unknown */
    uint8_t _pad_0x161[1455];
    uint8_t field_0x710; /* size unknown */
    uint8_t _pad_0x711[1455];
    uint8_t field_0xcc0; /* size unknown */
    uint8_t _pad_0xcc1[7];
    uint8_t field_0xcc8; /* size unknown */
    uint8_t _pad_0xcc9[87];
    uint64_t field_0xd20;
    uint64_t field_0xd28;
    uint64_t field_0xd30;
    uint64_t field_0xd38;
    uint8_t _pad_0xd40[16];
    uint64_t field_0xd50;
    uint64_t field_0xd58;
    uint64_t field_0xd60;
    uint64_t field_0xd68;
    uint8_t _pad_0xd70[16];
    uint64_t field_0xd80;
    uint64_t field_0xd88;
    uint64_t field_0xd90;
    uint64_t field_0xd98;
    uint64_t field_0xda0;
    uint64_t field_0xda8;
    uint64_t field_0xdb0;
    uint8_t field_0xdb8; /* size unknown */
    uint8_t _pad_0xdb9[19];
    uint8_t field_0xdcc; /* size unknown */
    uint8_t _pad_0xdcd[27];
    uint8_t field_0xde8; /* size unknown */
    uint8_t _pad_0xde9[111];
    uint8_t field_0xe58; /* size unknown */
    uint8_t _pad_0xe59[31];
    uint32_t field_0xe78;
    uint64_t field_0xe7c;
    uint32_t field_0xe84;
} ns3_ccUiAdvStartMenuItemList;

/* ccUiAdvStartMenuMap */
/* vtable: PTR_FUN_1408bd088 */
/* size unknown, >= 0x2f0 */
typedef struct __attribute__((packed)) ns3_ccUiAdvStartMenuMap {
    uint8_t _pad_0x0[748];
    uint32_t field_0x2ec;
} ns3_ccUiAdvStartMenuMap;

/* ccUiAdvStartMenuQuestLog */
/* vtable: PTR_FUN_1408bd890 */
/* size: 0xc0 (192) from FUN_14022a158 */
typedef struct __attribute__((packed)) ns3_ccUiAdvStartMenuQuestLog {
    uint8_t _pad_0x0[88];
    uint32_t field_0x58;
    uint8_t _pad_0x5c[20];
    uint8_t field_0x70; /* size unknown */
    uint8_t _pad_0x71[63];
    uint64_t field_0xb0;
    uint64_t field_0xb8;
} ns3_ccUiAdvStartMenuQuestLog;

/* ccUiAdvStartMenuTutorial */
/* vtable: PTR_FUN_1408becf8 */
/* size: 0x258 (600) from FUN_14022f600 */
typedef struct __attribute__((packed)) ns3_ccUiAdvStartMenuTutorial {
    uint8_t _pad_0x0[88];
    uint32_t field_0x58;
    uint8_t _pad_0x5c[4];
    uint64_t field_0x60;
    uint64_t field_0x68;
    uint64_t field_0x70;
    uint32_t field_0x78;
    uint64_t field_0x7c;
    uint64_t field_0x84;
    uint32_t field_0x8c;
    uint64_t field_0x90;
    uint64_t field_0x98;
    uint32_t field_0xa0;
    uint64_t field_0xa4;
    uint64_t field_0xac;
    uint32_t field_0xb4;
    uint64_t field_0xb8;
    uint64_t field_0xc0;
    uint32_t field_0xc8;
    uint8_t field_0xcc; /* size unknown */
    uint8_t _pad_0xcd[31];
    uint64_t field_0xec;
    uint64_t field_0xf4;
    uint64_t field_0xfc;
    uint32_t field_0x104;
    uint64_t field_0x108;
    uint64_t field_0x110;
    uint32_t field_0x118;
    uint8_t _pad_0x11c[4];
    uint64_t field_0x120;
    uint64_t field_0x128;
    uint64_t field_0x130;
    uint8_t field_0x138; /* size unknown */
    uint8_t _pad_0x139[7];
    uint64_t field_0x140;
    uint64_t field_0x148;
    uint64_t field_0x150;
    uint8_t _pad_0x158[16];
    uint8_t field_0x168; /* size unknown */
    uint8_t _pad_trail[239];
} ns3_ccUiAdvStartMenuTutorial;

/* ccUiAdvTeamOrganize */
/* vtable: PTR_FUN_1408bf1b0 */
/* size: 0x48 (72) from FUN_1401c4adc (ccSceneAdvTeamOrganize::Initialize) */
typedef struct __attribute__((packed)) ns3_ccUiAdvTeamOrganize {
    uint8_t _pad_trail[72];
} ns3_ccUiAdvTeamOrganize;

/* ccUiAdvTeamOrganizeState */
/* vtable: PTR_FUN_1408bf160 */
/* size: 0x240 (576) from FUN_140234c94 (second alloc) */
typedef struct __attribute__((packed)) ns3_ccUiAdvTeamOrganizeState {
    uint8_t _pad_0x0[84];
    uint64_t field_0x54;
    uint32_t field_0x5c;
    uint32_t field_0x60;
    uint8_t _pad_0x64[4];
    uint64_t field_0x68;
    uint8_t field_0x70; /* size unknown */
    uint8_t _pad_0x71[19];
    uint8_t field_0x84; /* size unknown */
    uint8_t _pad_0x85[11];
    uint64_t field_0x90;
    uint64_t field_0x98;
    uint64_t field_0xa0;
    uint64_t field_0xa8;
    uint64_t field_0xb0;
    uint64_t field_0xb8;
    uint64_t field_0xc0;
    uint64_t field_0xc8;
    uint8_t field_0xd0; /* size unknown */
    uint8_t _pad_0xd1[159];
    uint64_t field_0x170;
    uint64_t field_0x178;
    uint64_t field_0x180;
    uint8_t field_0x188; /* size unknown */
    uint8_t _pad_0x189[47];
    uint64_t field_0x1b8;
    uint8_t field_0x1c0; /* size unknown */
    uint8_t _pad_0x1c1[63];
    uint64_t field_0x200;
    uint64_t field_0x208;
    uint64_t field_0x210;
    uint64_t field_0x218;
    uint8_t _pad_0x220[28];
    uint32_t field_0x23c;
} ns3_ccUiAdvTeamOrganizeState;

/* ccUiChallengeMissionBaseLayout: no fields, size unknown -- skipped */

/* Offset and size assertions */
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0x58) == 0x58, "ccUiAdvRecoveryWindow::field_0x58");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0x60) == 0x60, "ccUiAdvRecoveryWindow::field_0x60");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0x68) == 0x68, "ccUiAdvRecoveryWindow::field_0x68");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0x98) == 0x98, "ccUiAdvRecoveryWindow::field_0x98");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0xd8) == 0xd8, "ccUiAdvRecoveryWindow::field_0xd8");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0xdc) == 0xdc, "ccUiAdvRecoveryWindow::field_0xdc");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0xe4) == 0xe4, "ccUiAdvRecoveryWindow::field_0xe4");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0xec) == 0xec, "ccUiAdvRecoveryWindow::field_0xec");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0xf4) == 0xf4, "ccUiAdvRecoveryWindow::field_0xf4");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0xfc) == 0xfc, "ccUiAdvRecoveryWindow::field_0xfc");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0x100) == 0x100, "ccUiAdvRecoveryWindow::field_0x100");
_Static_assert(offsetof(ns3_ccUiAdvRecoveryWindow, field_0x108) == 0x108, "ccUiAdvRecoveryWindow::field_0x108");
_Static_assert(sizeof(ns3_ccUiAdvRecoveryWindow) == 0x110, "ccUiAdvRecoveryWindow size");

_Static_assert(offsetof(ns3_ccUiAdvRewardWindow, field_0x78) == 0x78, "ccUiAdvRewardWindow::field_0x78");
_Static_assert(offsetof(ns3_ccUiAdvRewardWindow, field_0x80) == 0x80, "ccUiAdvRewardWindow::field_0x80");
_Static_assert(sizeof(ns3_ccUiAdvRewardWindow) == 0x88, "ccUiAdvRewardWindow size");

_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0x78) == 0x78, "ccUiAdvStartMenu::field_0x78");
_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0xd8) == 0xd8, "ccUiAdvStartMenu::field_0xd8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0xf0) == 0xf0, "ccUiAdvStartMenu::field_0xf0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0x108) == 0x108, "ccUiAdvStartMenu::field_0x108");
_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0x118) == 0x118, "ccUiAdvStartMenu::field_0x118");
_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0x130) == 0x130, "ccUiAdvStartMenu::field_0x130");
_Static_assert(offsetof(ns3_ccUiAdvStartMenu, field_0x140) == 0x140, "ccUiAdvStartMenu::field_0x140");
_Static_assert(sizeof(ns3_ccUiAdvStartMenu) == 0x170, "ccUiAdvStartMenu size");

_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x58) == 0x58, "ccUiAdvStartMenuItemList::field_0x58");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x60) == 0x60, "ccUiAdvStartMenuItemList::field_0x60");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x68) == 0x68, "ccUiAdvStartMenuItemList::field_0x68");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x70) == 0x70, "ccUiAdvStartMenuItemList::field_0x70");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x78) == 0x78, "ccUiAdvStartMenuItemList::field_0x78");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x7c) == 0x7c, "ccUiAdvStartMenuItemList::field_0x7c");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x88) == 0x88, "ccUiAdvStartMenuItemList::field_0x88");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xb0) == 0xb0, "ccUiAdvStartMenuItemList::field_0xb0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xb8) == 0xb8, "ccUiAdvStartMenuItemList::field_0xb8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd0) == 0xd0, "ccUiAdvStartMenuItemList::field_0xd0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xf0) == 0xf0, "ccUiAdvStartMenuItemList::field_0xf0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xf8) == 0xf8, "ccUiAdvStartMenuItemList::field_0xf8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x100) == 0x100, "ccUiAdvStartMenuItemList::field_0x100");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x108) == 0x108, "ccUiAdvStartMenuItemList::field_0x108");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x110) == 0x110, "ccUiAdvStartMenuItemList::field_0x110");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x118) == 0x118, "ccUiAdvStartMenuItemList::field_0x118");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x120) == 0x120, "ccUiAdvStartMenuItemList::field_0x120");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x138) == 0x138, "ccUiAdvStartMenuItemList::field_0x138");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x140) == 0x140, "ccUiAdvStartMenuItemList::field_0x140");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x148) == 0x148, "ccUiAdvStartMenuItemList::field_0x148");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x150) == 0x150, "ccUiAdvStartMenuItemList::field_0x150");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x158) == 0x158, "ccUiAdvStartMenuItemList::field_0x158");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x160) == 0x160, "ccUiAdvStartMenuItemList::field_0x160");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0x710) == 0x710, "ccUiAdvStartMenuItemList::field_0x710");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xcc0) == 0xcc0, "ccUiAdvStartMenuItemList::field_0xcc0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xcc8) == 0xcc8, "ccUiAdvStartMenuItemList::field_0xcc8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd20) == 0xd20, "ccUiAdvStartMenuItemList::field_0xd20");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd28) == 0xd28, "ccUiAdvStartMenuItemList::field_0xd28");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd30) == 0xd30, "ccUiAdvStartMenuItemList::field_0xd30");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd38) == 0xd38, "ccUiAdvStartMenuItemList::field_0xd38");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd50) == 0xd50, "ccUiAdvStartMenuItemList::field_0xd50");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd58) == 0xd58, "ccUiAdvStartMenuItemList::field_0xd58");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd60) == 0xd60, "ccUiAdvStartMenuItemList::field_0xd60");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd68) == 0xd68, "ccUiAdvStartMenuItemList::field_0xd68");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd80) == 0xd80, "ccUiAdvStartMenuItemList::field_0xd80");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd88) == 0xd88, "ccUiAdvStartMenuItemList::field_0xd88");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd90) == 0xd90, "ccUiAdvStartMenuItemList::field_0xd90");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xd98) == 0xd98, "ccUiAdvStartMenuItemList::field_0xd98");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xda0) == 0xda0, "ccUiAdvStartMenuItemList::field_0xda0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xda8) == 0xda8, "ccUiAdvStartMenuItemList::field_0xda8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xdb0) == 0xdb0, "ccUiAdvStartMenuItemList::field_0xdb0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xdb8) == 0xdb8, "ccUiAdvStartMenuItemList::field_0xdb8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xdcc) == 0xdcc, "ccUiAdvStartMenuItemList::field_0xdcc");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xde8) == 0xde8, "ccUiAdvStartMenuItemList::field_0xde8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xe58) == 0xe58, "ccUiAdvStartMenuItemList::field_0xe58");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xe78) == 0xe78, "ccUiAdvStartMenuItemList::field_0xe78");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xe7c) == 0xe7c, "ccUiAdvStartMenuItemList::field_0xe7c");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuItemList, field_0xe84) == 0xe84, "ccUiAdvStartMenuItemList::field_0xe84");
_Static_assert(sizeof(ns3_ccUiAdvStartMenuItemList) == 0xe88, "ccUiAdvStartMenuItemList size");

_Static_assert(offsetof(ns3_ccUiAdvStartMenuMap, field_0x2ec) == 0x2ec, "ccUiAdvStartMenuMap::field_0x2ec");

_Static_assert(offsetof(ns3_ccUiAdvStartMenuQuestLog, field_0x58) == 0x58, "ccUiAdvStartMenuQuestLog::field_0x58");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuQuestLog, field_0x70) == 0x70, "ccUiAdvStartMenuQuestLog::field_0x70");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuQuestLog, field_0xb0) == 0xb0, "ccUiAdvStartMenuQuestLog::field_0xb0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuQuestLog, field_0xb8) == 0xb8, "ccUiAdvStartMenuQuestLog::field_0xb8");
_Static_assert(sizeof(ns3_ccUiAdvStartMenuQuestLog) == 0xc0, "ccUiAdvStartMenuQuestLog size");

_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x58) == 0x58, "ccUiAdvStartMenuTutorial::field_0x58");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x60) == 0x60, "ccUiAdvStartMenuTutorial::field_0x60");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x68) == 0x68, "ccUiAdvStartMenuTutorial::field_0x68");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x70) == 0x70, "ccUiAdvStartMenuTutorial::field_0x70");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x78) == 0x78, "ccUiAdvStartMenuTutorial::field_0x78");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x7c) == 0x7c, "ccUiAdvStartMenuTutorial::field_0x7c");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x84) == 0x84, "ccUiAdvStartMenuTutorial::field_0x84");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x8c) == 0x8c, "ccUiAdvStartMenuTutorial::field_0x8c");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x90) == 0x90, "ccUiAdvStartMenuTutorial::field_0x90");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x98) == 0x98, "ccUiAdvStartMenuTutorial::field_0x98");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xa0) == 0xa0, "ccUiAdvStartMenuTutorial::field_0xa0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xa4) == 0xa4, "ccUiAdvStartMenuTutorial::field_0xa4");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xac) == 0xac, "ccUiAdvStartMenuTutorial::field_0xac");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xb4) == 0xb4, "ccUiAdvStartMenuTutorial::field_0xb4");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xb8) == 0xb8, "ccUiAdvStartMenuTutorial::field_0xb8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xc0) == 0xc0, "ccUiAdvStartMenuTutorial::field_0xc0");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xc8) == 0xc8, "ccUiAdvStartMenuTutorial::field_0xc8");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xcc) == 0xcc, "ccUiAdvStartMenuTutorial::field_0xcc");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xec) == 0xec, "ccUiAdvStartMenuTutorial::field_0xec");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xf4) == 0xf4, "ccUiAdvStartMenuTutorial::field_0xf4");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0xfc) == 0xfc, "ccUiAdvStartMenuTutorial::field_0xfc");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x104) == 0x104, "ccUiAdvStartMenuTutorial::field_0x104");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x108) == 0x108, "ccUiAdvStartMenuTutorial::field_0x108");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x110) == 0x110, "ccUiAdvStartMenuTutorial::field_0x110");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x118) == 0x118, "ccUiAdvStartMenuTutorial::field_0x118");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x120) == 0x120, "ccUiAdvStartMenuTutorial::field_0x120");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x128) == 0x128, "ccUiAdvStartMenuTutorial::field_0x128");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x130) == 0x130, "ccUiAdvStartMenuTutorial::field_0x130");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x138) == 0x138, "ccUiAdvStartMenuTutorial::field_0x138");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x140) == 0x140, "ccUiAdvStartMenuTutorial::field_0x140");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x148) == 0x148, "ccUiAdvStartMenuTutorial::field_0x148");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x150) == 0x150, "ccUiAdvStartMenuTutorial::field_0x150");
_Static_assert(offsetof(ns3_ccUiAdvStartMenuTutorial, field_0x168) == 0x168, "ccUiAdvStartMenuTutorial::field_0x168");
_Static_assert(sizeof(ns3_ccUiAdvStartMenuTutorial) == 0x258, "ccUiAdvStartMenuTutorial size");

_Static_assert(sizeof(ns3_ccUiAdvTeamOrganize) == 0x48, "ccUiAdvTeamOrganize size");

_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x54) == 0x54, "ccUiAdvTeamOrganizeState::field_0x54");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x5c) == 0x5c, "ccUiAdvTeamOrganizeState::field_0x5c");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x60) == 0x60, "ccUiAdvTeamOrganizeState::field_0x60");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x68) == 0x68, "ccUiAdvTeamOrganizeState::field_0x68");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x70) == 0x70, "ccUiAdvTeamOrganizeState::field_0x70");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x84) == 0x84, "ccUiAdvTeamOrganizeState::field_0x84");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x90) == 0x90, "ccUiAdvTeamOrganizeState::field_0x90");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x98) == 0x98, "ccUiAdvTeamOrganizeState::field_0x98");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xa0) == 0xa0, "ccUiAdvTeamOrganizeState::field_0xa0");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xa8) == 0xa8, "ccUiAdvTeamOrganizeState::field_0xa8");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xb0) == 0xb0, "ccUiAdvTeamOrganizeState::field_0xb0");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xb8) == 0xb8, "ccUiAdvTeamOrganizeState::field_0xb8");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xc0) == 0xc0, "ccUiAdvTeamOrganizeState::field_0xc0");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xc8) == 0xc8, "ccUiAdvTeamOrganizeState::field_0xc8");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0xd0) == 0xd0, "ccUiAdvTeamOrganizeState::field_0xd0");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x170) == 0x170, "ccUiAdvTeamOrganizeState::field_0x170");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x178) == 0x178, "ccUiAdvTeamOrganizeState::field_0x178");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x180) == 0x180, "ccUiAdvTeamOrganizeState::field_0x180");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x188) == 0x188, "ccUiAdvTeamOrganizeState::field_0x188");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x1b8) == 0x1b8, "ccUiAdvTeamOrganizeState::field_0x1b8");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x1c0) == 0x1c0, "ccUiAdvTeamOrganizeState::field_0x1c0");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x200) == 0x200, "ccUiAdvTeamOrganizeState::field_0x200");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x208) == 0x208, "ccUiAdvTeamOrganizeState::field_0x208");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x210) == 0x210, "ccUiAdvTeamOrganizeState::field_0x210");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x218) == 0x218, "ccUiAdvTeamOrganizeState::field_0x218");
_Static_assert(offsetof(ns3_ccUiAdvTeamOrganizeState, field_0x23c) == 0x23c, "ccUiAdvTeamOrganizeState::field_0x23c");
_Static_assert(sizeof(ns3_ccUiAdvTeamOrganizeState) == 0x240, "ccUiAdvTeamOrganizeState size");

#endif /* ST3A20_H */
