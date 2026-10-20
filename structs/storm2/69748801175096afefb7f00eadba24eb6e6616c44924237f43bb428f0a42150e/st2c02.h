#ifndef ST2C02_H
#define ST2C02_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Auto-generated from the decompiler cache state_surface for build s2 (NSUNS2.exe)
 * All layouts INFERRED from static analysis. Sizes proven from LoadTh/operator new where noted.
 * Rollback tags: SIM = must snapshot, PRES = preserve on rollback, UNKNOWN = unclassified */

/* ccAdvWindowManager::TalkFix: skipped (< 3 methods or no surface data) */

/* ccCpuScript: skipped (< 3 methods or no surface data) */

/* ccDuelEndDemo: size unknown (thin wrapper); last field ends at 0x111 */
typedef struct __attribute__((packed)) ccDuelEndDemo {
    uint8_t _pad_0x0[0x110];
    uint8_t _unk_0x110[8]; /* conf=low, evidence=ccDuelEndDemo::ccDuelEndDemo */
} ccDuelEndDemo;

/* ccEventAnmState: proven size 0x1660 (5728 bytes) */
typedef struct __attribute__((packed)) ccEventAnmState {
    uint8_t _pad_0x0[0x14B8];
    uint64_t field_0x14B8; /* conf=medium */
    uint8_t _unk_0x14C0[8]; /* conf=low, evidence=ccEventAnmState::ccEventAnmState */
    uint8_t _pad_0x14C8[0x8];
    uint64_t field_0x14D0; /* conf=medium */
    uint64_t field_0x14D8; /* conf=medium */
    uint8_t _pad_0x14E0[0x18];
    uint32_t field_0x14F8; /* conf=medium */
    uint8_t _unk_0x14FC[8]; /* conf=low, evidence=ccEventAnmState::ccEventAnmState */
    uint8_t _pad_0x1504[0x4];
    uint8_t _unk_0x1508[8]; /* conf=low, evidence=ccEventAnmState::ccEventAnmState */
    uint8_t _pad_0x1510[0x4];
    uint32_t field_0x1514; /* conf=medium */
    uint32_t field_0x1518; /* conf=medium */
    uint8_t _pad_0x151C[0x4];
    uint64_t field_0x1520; /* conf=medium */
    uint8_t _unk_0x1528[8]; /* conf=low, evidence=ccEventAnmState::ccEventAnmState */
    uint8_t _tail[0x130];
} ccEventAnmState;
static_assert(offsetof(ccEventAnmState, field_0x14B8) == 0x14B8, "ccEventAnmState +0x14B8");
static_assert(offsetof(ccEventAnmState, field_0x14D0) == 0x14D0, "ccEventAnmState +0x14D0");
static_assert(offsetof(ccEventAnmState, field_0x14D8) == 0x14D8, "ccEventAnmState +0x14D8");
static_assert(offsetof(ccEventAnmState, field_0x14F8) == 0x14F8, "ccEventAnmState +0x14F8");
static_assert(offsetof(ccEventAnmState, field_0x1514) == 0x1514, "ccEventAnmState +0x1514");
static_assert(offsetof(ccEventAnmState, field_0x1518) == 0x1518, "ccEventAnmState +0x1518");
static_assert(offsetof(ccEventAnmState, field_0x1520) == 0x1520, "ccEventAnmState +0x1520");

/* ccEventBlurState: embedded in ccAdvScreenEffect at +0x0; last field ends at 0x14DC */
typedef struct __attribute__((packed)) ccEventBlurState {
    uint8_t _pad_0x0[0x14B8];
    uint64_t field_0x14B8; /* conf=medium */
    uint64_t field_0x14C0; /* conf=medium */
    uint32_t field_0x14C8; /* conf=medium */
    uint64_t field_0x14CC; /* conf=medium */
    uint64_t field_0x14D4; /* conf=medium */
} ccEventBlurState;
static_assert(offsetof(ccEventBlurState, field_0x14B8) == 0x14B8, "ccEventBlurState +0x14B8");
static_assert(offsetof(ccEventBlurState, field_0x14C0) == 0x14C0, "ccEventBlurState +0x14C0");
static_assert(offsetof(ccEventBlurState, field_0x14C8) == 0x14C8, "ccEventBlurState +0x14C8");
static_assert(offsetof(ccEventBlurState, field_0x14CC) == 0x14CC, "ccEventBlurState +0x14CC");
static_assert(offsetof(ccEventBlurState, field_0x14D4) == 0x14D4, "ccEventBlurState +0x14D4");

/* ccEventCamera: proven size 0x16E8 (5864 bytes) */
typedef struct __attribute__((packed)) ccEventCamera {
    uint8_t _pad_0x0[0x1B0];
    uint8_t _unk_0x1B0[8]; /* conf=low, evidence=ccEventCamera::ccEventCamera */
    uint8_t _pad_0x1B8[0x4];
    uint8_t _unk_0x1BC[8]; /* conf=low, evidence=ccEventCamera::ccEventCamera */
    uint8_t _pad_0x1C4[0x4];
    uint32_t field_0x1C8; /* conf=medium */
    uint32_t field_0x1CC; /* conf=medium */
    uint32_t field_0x1D0; /* conf=medium */
    uint32_t field_0x1D4; /* conf=medium */
    uint8_t _unk_0x1D8[8]; /* conf=low, evidence=ccEventCamera::ccEventCamera */
    uint8_t _pad_0x1E0[0x14F0];
    uint8_t _unk_0x16D0[8]; /* conf=low, evidence=ccEventCamera::ccEventCamera */
    uint8_t _tail[0x10];
} ccEventCamera;
static_assert(offsetof(ccEventCamera, field_0x1C8) == 0x1C8, "ccEventCamera +0x1C8");
static_assert(offsetof(ccEventCamera, field_0x1CC) == 0x1CC, "ccEventCamera +0x1CC");
static_assert(offsetof(ccEventCamera, field_0x1D0) == 0x1D0, "ccEventCamera +0x1D0");
static_assert(offsetof(ccEventCamera, field_0x1D4) == 0x1D4, "ccEventCamera +0x1D4");

/* ccEventCameraState: proven size 0x1570 (5488 bytes) */
typedef struct __attribute__((packed)) ccEventCameraState {
    uint8_t _pad_0x0[0x14B8];
    uint8_t field_0x14B8; /* conf=low */
    uint8_t _pad_0x14B9[0xF];
    uint64_t field_0x14C8; /* conf=high */
    uint64_t field_0x14D0; /* conf=high */
    uint64_t field_0x14D8; /* conf=low */
    uint8_t _pad_0x14E0[0x10];
    uint8_t _unk_0x14F0[8]; /* conf=low, evidence=ccEventCameraState::ccEventCameraState */
    uint8_t _pad_0x14F8[0x4];
    uint8_t _unk_0x14FC[8]; /* conf=low, evidence=ccEventCameraState::ccEventCameraState */
    uint8_t _pad_0x1504[0x4];
    uint8_t _unk_0x1508[8]; /* conf=low, evidence=ccEventCameraState::ccEventCameraState */
    uint8_t _pad_0x1510[0x4];
    uint8_t _unk_0x1514[8]; /* conf=low, evidence=ccEventCameraState::ccEventCameraState */
    uint8_t _pad_0x151C[0x4];
    uint32_t field_0x1520; /* conf=medium */
    uint32_t field_0x1524; /* conf=medium */
    uint32_t field_0x1528; /* conf=medium */
    uint32_t field_0x152C; /* conf=medium */
    uint8_t _unk_0x1530[8]; /* conf=low, evidence=ccEventCameraState::ccEventCameraState */
    uint8_t _pad_0x1538[0x4];
    uint8_t _unk_0x153C[8]; /* conf=low, evidence=ccEventCameraState::ccEventCameraState */
    uint8_t _pad_0x1544[0x4];
    uint32_t field_0x1548; /* conf=medium */
    uint32_t field_0x154C; /* conf=medium */
    uint32_t field_0x1550; /* conf=medium */
    uint32_t field_0x1554; /* conf=medium */
    uint64_t field_0x1558; /* conf=medium */
    uint64_t field_0x1560; /* conf=medium */
    uint64_t field_0x1568; /* conf=medium */
} ccEventCameraState;
static_assert(offsetof(ccEventCameraState, field_0x14B8) == 0x14B8, "ccEventCameraState +0x14B8");
static_assert(offsetof(ccEventCameraState, field_0x14C8) == 0x14C8, "ccEventCameraState +0x14C8");
static_assert(offsetof(ccEventCameraState, field_0x14D0) == 0x14D0, "ccEventCameraState +0x14D0");
static_assert(offsetof(ccEventCameraState, field_0x14D8) == 0x14D8, "ccEventCameraState +0x14D8");
static_assert(offsetof(ccEventCameraState, field_0x1520) == 0x1520, "ccEventCameraState +0x1520");
static_assert(offsetof(ccEventCameraState, field_0x1524) == 0x1524, "ccEventCameraState +0x1524");
static_assert(offsetof(ccEventCameraState, field_0x1528) == 0x1528, "ccEventCameraState +0x1528");
static_assert(offsetof(ccEventCameraState, field_0x152C) == 0x152C, "ccEventCameraState +0x152C");
static_assert(offsetof(ccEventCameraState, field_0x1548) == 0x1548, "ccEventCameraState +0x1548");
static_assert(offsetof(ccEventCameraState, field_0x154C) == 0x154C, "ccEventCameraState +0x154C");
static_assert(offsetof(ccEventCameraState, field_0x1550) == 0x1550, "ccEventCameraState +0x1550");
static_assert(offsetof(ccEventCameraState, field_0x1554) == 0x1554, "ccEventCameraState +0x1554");
static_assert(offsetof(ccEventCameraState, field_0x1558) == 0x1558, "ccEventCameraState +0x1558");
static_assert(offsetof(ccEventCameraState, field_0x1560) == 0x1560, "ccEventCameraState +0x1560");
static_assert(offsetof(ccEventCameraState, field_0x1568) == 0x1568, "ccEventCameraState +0x1568");

/* ccEventCameraVibration: embedded in ccEventCamera at +0x3B; last field ends at 0x14F0 */
typedef struct __attribute__((packed)) ccEventCameraVibration {
    uint8_t _pad_0x0[0x14B8];
    uint8_t _unk_0x14B8[8]; /* conf=low, evidence=ccEventCameraVibration::ccEventCameraVibration */
    uint8_t _pad_0x14C0[0x4];
    uint8_t _unk_0x14C4[8]; /* conf=low, evidence=ccEventCameraVibration::ccEventCameraVibration */
    uint8_t _pad_0x14CC[0x4];
    uint8_t _unk_0x14D0[8]; /* conf=low, evidence=ccEventCameraVibration::ccEventCameraVibration */
    uint8_t _pad_0x14D8[0x4];
    uint8_t _unk_0x14DC[8]; /* conf=low, evidence=ccEventCameraVibration::ccEventCameraVibration */
    uint8_t _pad_0x14E4[0x4];
    uint32_t field_0x14E8; /* conf=medium */
    uint32_t field_0x14EC; /* conf=medium */
} ccEventCameraVibration;
static_assert(offsetof(ccEventCameraVibration, field_0x14E8) == 0x14E8, "ccEventCameraVibration +0x14E8");
static_assert(offsetof(ccEventCameraVibration, field_0x14EC) == 0x14EC, "ccEventCameraVibration +0x14EC");

/* ccEventChara: embedded in ccCharacterSelectSide at +0xC8; last field ends at 0x16D8 */
typedef struct __attribute__((packed)) ccEventChara {
    uint8_t _pad_0x0[0x110];
    uint8_t _unk_0x110[8]; /* conf=low, evidence=ccEventChara::ApplyPos; ccEventChara::Ctrl */
    uint8_t _pad_0x118[0x100];
    uint64_t field_0x218; /* conf=medium */
    uint8_t _pad_0x220[0x1E0];
    uint8_t _unk_0x400[8]; /* conf=low, evidence=ccEventChara::Ctrl */
    uint8_t _pad_0x408[0x38];
    uint8_t _unk_0x440[8]; /* conf=low, evidence=ccEventChara::ApplyPos; ccEventChara::Ctrl */
    uint8_t _pad_0x448[0x3E0];
    uint32_t field_0x828; /* conf=medium */
    uint8_t _pad_0x82C[0x4];
    uint64_t field_0x830; /* conf=medium */
    uint64_t field_0x838; /* conf=medium */
    uint8_t _pad_0x840[0x18];
    uint64_t field_0x858; /* conf=medium */
    uint8_t _unk_0x860[8]; /* conf=low, evidence=ccEventChara::Ctrl */
    uint8_t _pad_0x868[0x134];
    uint32_t field_0x99C; /* conf=medium */
    uint32_t field_0x9A0; /* conf=medium */
    uint8_t _pad_0x9A4[0x4];
    uint8_t _unk_0x9A8[8]; /* conf=low, evidence=ccEventChara::Ctrl */
    uint8_t _pad_0x9B0[0x10];
    uint64_t field_0x9C0; /* conf=medium */
    uint8_t _pad_0x9C8[0x18];
    uint8_t _unk_0x9E0[8]; /* conf=low, evidence=ccEventChara::Ctrl */
    uint8_t _pad_0x9E8[0x10];
    uint64_t field_0x9F8; /* conf=medium */
    uint8_t _pad_0xA00[0xAB8];
    uint32_t field_0x14B8; /* conf=medium */
    uint32_t field_0x14BC; /* conf=medium */
    uint32_t field_0x14C0; /* conf=medium */
    uint64_t field_0x14C4; /* conf=medium */
    uint64_t field_0x14CC; /* conf=medium */
    uint32_t field_0x14D4; /* conf=medium */
    uint8_t _pad_0x14D8[0x4];
    uint16_t field_0x14DC; /* conf=medium */
    uint8_t _pad_0x14DE[0x2];
    uint64_t field_0x14E0; /* conf=medium */
    uint64_t field_0x14E8; /* conf=medium */
    uint32_t field_0x14F0; /* conf=medium */
    uint8_t _pad_0x14F4[0x4];
    uint64_t field_0x14F8; /* conf=medium */
    uint64_t field_0x1500; /* conf=medium */
    uint64_t field_0x1508; /* conf=medium */
    uint64_t field_0x1510; /* conf=low */
    uint8_t _pad_0x1518[0x10];
    uint64_t field_0x1528; /* conf=medium */
    uint64_t field_0x1530; /* conf=medium */
    uint64_t field_0x1538; /* conf=medium */
    uint64_t field_0x1540; /* conf=low */
    uint8_t _pad_0x1548[0x10];
    uint32_t field_0x1558; /* conf=medium */
    uint8_t _pad_0x155C[0x4];
    uint64_t field_0x1560; /* conf=medium */
    uint64_t field_0x1568; /* conf=medium */
    uint8_t _pad_0x1570[0x48];
    uint64_t field_0x15B8; /* conf=medium */
    uint64_t field_0x15C0; /* conf=medium */
    uint8_t _unk_0x15C8[8]; /* conf=low, evidence=ccEventChara::ccEventChara */
    uint8_t _pad_0x15D0[0x100];
    uint8_t _unk_0x16D0[8]; /* conf=low, evidence=ccEventChara::ccEventChara */
} ccEventChara;
static_assert(offsetof(ccEventChara, field_0x218) == 0x218, "ccEventChara +0x218");
static_assert(offsetof(ccEventChara, field_0x828) == 0x828, "ccEventChara +0x828");
static_assert(offsetof(ccEventChara, field_0x830) == 0x830, "ccEventChara +0x830");
static_assert(offsetof(ccEventChara, field_0x838) == 0x838, "ccEventChara +0x838");
static_assert(offsetof(ccEventChara, field_0x858) == 0x858, "ccEventChara +0x858");
static_assert(offsetof(ccEventChara, field_0x99C) == 0x99C, "ccEventChara +0x99C");
static_assert(offsetof(ccEventChara, field_0x9A0) == 0x9A0, "ccEventChara +0x9A0");
static_assert(offsetof(ccEventChara, field_0x9C0) == 0x9C0, "ccEventChara +0x9C0");
static_assert(offsetof(ccEventChara, field_0x9F8) == 0x9F8, "ccEventChara +0x9F8");
static_assert(offsetof(ccEventChara, field_0x14B8) == 0x14B8, "ccEventChara +0x14B8");
static_assert(offsetof(ccEventChara, field_0x14BC) == 0x14BC, "ccEventChara +0x14BC");
static_assert(offsetof(ccEventChara, field_0x14C0) == 0x14C0, "ccEventChara +0x14C0");
static_assert(offsetof(ccEventChara, field_0x14C4) == 0x14C4, "ccEventChara +0x14C4");
static_assert(offsetof(ccEventChara, field_0x14CC) == 0x14CC, "ccEventChara +0x14CC");
static_assert(offsetof(ccEventChara, field_0x14D4) == 0x14D4, "ccEventChara +0x14D4");
static_assert(offsetof(ccEventChara, field_0x14DC) == 0x14DC, "ccEventChara +0x14DC");
static_assert(offsetof(ccEventChara, field_0x14E0) == 0x14E0, "ccEventChara +0x14E0");
static_assert(offsetof(ccEventChara, field_0x14E8) == 0x14E8, "ccEventChara +0x14E8");
static_assert(offsetof(ccEventChara, field_0x14F0) == 0x14F0, "ccEventChara +0x14F0");
static_assert(offsetof(ccEventChara, field_0x14F8) == 0x14F8, "ccEventChara +0x14F8");
static_assert(offsetof(ccEventChara, field_0x1500) == 0x1500, "ccEventChara +0x1500");
static_assert(offsetof(ccEventChara, field_0x1508) == 0x1508, "ccEventChara +0x1508");
static_assert(offsetof(ccEventChara, field_0x1510) == 0x1510, "ccEventChara +0x1510");
static_assert(offsetof(ccEventChara, field_0x1528) == 0x1528, "ccEventChara +0x1528");
static_assert(offsetof(ccEventChara, field_0x1530) == 0x1530, "ccEventChara +0x1530");
static_assert(offsetof(ccEventChara, field_0x1538) == 0x1538, "ccEventChara +0x1538");
static_assert(offsetof(ccEventChara, field_0x1540) == 0x1540, "ccEventChara +0x1540");
static_assert(offsetof(ccEventChara, field_0x1558) == 0x1558, "ccEventChara +0x1558");
static_assert(offsetof(ccEventChara, field_0x1560) == 0x1560, "ccEventChara +0x1560");
static_assert(offsetof(ccEventChara, field_0x1568) == 0x1568, "ccEventChara +0x1568");
static_assert(offsetof(ccEventChara, field_0x15B8) == 0x15B8, "ccEventChara +0x15B8");
static_assert(offsetof(ccEventChara, field_0x15C0) == 0x15C0, "ccEventChara +0x15C0");

/* ccEventCharaCreateParam: skipped (< 3 methods or no surface data) */

/* ccEventCharaReqMotionParam: skipped (< 3 methods or no surface data) */

/* ccEventCharaState: proven size 0x18F8 (6392 bytes) */
typedef struct __attribute__((packed)) ccEventCharaState {
    uint8_t _pad_0x0[0x14B8];
    uint64_t field_0x14B8; /* conf=medium */
    uint64_t field_0x14C0; /* conf=medium */
    uint8_t _unk_0x14C8[8]; /* conf=low, evidence=ccEventCharaState::ccEventCharaState */
    uint8_t _pad_0x14D0[0x8];
    uint64_t field_0x14D8; /* conf=medium */
    uint64_t field_0x14E0; /* conf=medium */
    uint8_t _pad_0x14E8[0x18];
    uint32_t field_0x1500; /* conf=medium */
    uint8_t _unk_0x1504[8]; /* conf=low, evidence=ccEventCharaState::ccEventCharaState */
    uint8_t _pad_0x150C[0x4];
    uint8_t _unk_0x1510[8]; /* conf=low, evidence=ccEventCharaState::ccEventCharaState */
    uint8_t _pad_0x1518[0x4];
    uint32_t field_0x151C; /* conf=medium */
    uint32_t field_0x1520; /* conf=medium */
    uint8_t _pad_0x1524[0x4];
    uint64_t field_0x1528; /* conf=medium */
    uint32_t field_0x1530; /* conf=medium */
    uint32_t field_0x1534; /* conf=medium */
    uint8_t _unk_0x1538[8]; /* conf=low, evidence=ccEventCharaState::ccEventCharaState */
    uint8_t _tail[0x3B8];
} ccEventCharaState;
static_assert(offsetof(ccEventCharaState, field_0x14B8) == 0x14B8, "ccEventCharaState +0x14B8");
static_assert(offsetof(ccEventCharaState, field_0x14C0) == 0x14C0, "ccEventCharaState +0x14C0");
static_assert(offsetof(ccEventCharaState, field_0x14D8) == 0x14D8, "ccEventCharaState +0x14D8");
static_assert(offsetof(ccEventCharaState, field_0x14E0) == 0x14E0, "ccEventCharaState +0x14E0");
static_assert(offsetof(ccEventCharaState, field_0x1500) == 0x1500, "ccEventCharaState +0x1500");
static_assert(offsetof(ccEventCharaState, field_0x151C) == 0x151C, "ccEventCharaState +0x151C");
static_assert(offsetof(ccEventCharaState, field_0x1520) == 0x1520, "ccEventCharaState +0x1520");
static_assert(offsetof(ccEventCharaState, field_0x1528) == 0x1528, "ccEventCharaState +0x1528");
static_assert(offsetof(ccEventCharaState, field_0x1530) == 0x1530, "ccEventCharaState +0x1530");
static_assert(offsetof(ccEventCharaState, field_0x1534) == 0x1534, "ccEventCharaState +0x1534");

/* ccEventColorConv: skipped (< 3 methods or no surface data) */

/* ccEventColorFilterState: embedded in ccAdvScreenEffect at +0x29C0; last field ends at 0x1508 */
typedef struct __attribute__((packed)) ccEventColorFilterState {
    uint8_t _pad_0x0[0x14B8];
    uint64_t field_0x14B8; /* conf=medium */
    uint64_t field_0x14C0; /* conf=medium */
    uint64_t field_0x14C8; /* conf=medium */
    uint64_t field_0x14D0; /* conf=medium */
    uint64_t field_0x14D8; /* conf=medium */
    uint64_t field_0x14E0; /* conf=medium */
    uint64_t field_0x14E8; /* conf=medium */
    uint32_t field_0x14F0; /* conf=medium */
    uint8_t _unk_0x14F4[8]; /* conf=low, evidence=ccEventColorFilterState::ccEventColorFilterState */
    uint32_t field_0x14FC; /* conf=medium */
    uint8_t _unk_0x1500[8]; /* conf=low, evidence=ccEventColorFilterState::ccEventColorFilterState */
} ccEventColorFilterState;
static_assert(offsetof(ccEventColorFilterState, field_0x14B8) == 0x14B8, "ccEventColorFilterState +0x14B8");
static_assert(offsetof(ccEventColorFilterState, field_0x14C0) == 0x14C0, "ccEventColorFilterState +0x14C0");
static_assert(offsetof(ccEventColorFilterState, field_0x14C8) == 0x14C8, "ccEventColorFilterState +0x14C8");
static_assert(offsetof(ccEventColorFilterState, field_0x14D0) == 0x14D0, "ccEventColorFilterState +0x14D0");
static_assert(offsetof(ccEventColorFilterState, field_0x14D8) == 0x14D8, "ccEventColorFilterState +0x14D8");
static_assert(offsetof(ccEventColorFilterState, field_0x14E0) == 0x14E0, "ccEventColorFilterState +0x14E0");
static_assert(offsetof(ccEventColorFilterState, field_0x14E8) == 0x14E8, "ccEventColorFilterState +0x14E8");
static_assert(offsetof(ccEventColorFilterState, field_0x14F0) == 0x14F0, "ccEventColorFilterState +0x14F0");
static_assert(offsetof(ccEventColorFilterState, field_0x14FC) == 0x14FC, "ccEventColorFilterState +0x14FC");

#endif /* ST2C02_H */