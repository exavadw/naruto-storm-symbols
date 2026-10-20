/* Auto-generated st2a10 struct layouts for NARUTO STORM 2 PC (s2) */
/* INFERRED from static analysis; not CONFIRMED by runtime trace */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccAdvLeaderCharaLoad: no fields recovered (byte-cast accesses only) */
typedef struct __attribute__((packed)) ccAdvLeaderCharaLoad { uint8_t _empty; } ccAdvLeaderCharaLoad; /* size unknown */

/* ccAdvLetterManager: no fields recovered (byte-cast accesses only) */
typedef struct __attribute__((packed)) ccAdvLetterManager { uint8_t _empty; } ccAdvLetterManager; /* size unknown */

/* ccAdvLoadingScreen: no fields recovered (byte-cast accesses only) */
typedef struct __attribute__((packed)) ccAdvLoadingScreen { uint8_t _empty; } ccAdvLoadingScreen; /* size unknown */

typedef struct __attribute__((packed)) ccAdvManager {
    uint8_t _pad_0000[88];
    uint64_t field_0058;
    uint8_t field_0060; /* size unknown at 0x60 */
    uint8_t _pad_0061[7];
    uint64_t field_0068;
    uint64_t field_0070;
    uint64_t field_0078;
    uint64_t field_0080;
    uint8_t _pad_0088[16];
    uint8_t field_0098; /* size unknown at 0x98 */
    uint8_t _pad_0099[239];
    uint32_t field_0188;
    uint32_t field_018C;
    uint64_t field_0190;
    uint64_t field_0198;
    uint64_t field_01A0;
    uint64_t field_01A8;
    uint32_t field_01B0;
    uint32_t field_01B4;
    uint64_t field_01B8;
    uint8_t _pad_01C0[48];
    uint32_t field_01F0;
    uint8_t _pad_01F4[4];
    uint64_t field_01F8;
    uint64_t field_0200;
    uint8_t _pad_0208[5008];
    uint8_t field_1598; /* size unknown at 0x1598 */
    uint8_t _pad_1599[87];
    uint8_t field_15F0; /* size unknown at 0x15F0 */
    uint8_t _pad_15F1[39];
    uint8_t field_1618; /* size unknown at 0x1618 */
    uint8_t _pad_1619[47];
    uint8_t field_1648; /* size unknown at 0x1648 */
    uint8_t _pad_1649[39];
    uint8_t field_1670; /* size unknown at 0x1670 */
    uint8_t _pad_1671[39];
    uint8_t field_1698; /* size unknown at 0x1698 */
    uint8_t _pad_1699[39];
    uint8_t field_16C0; /* size unknown at 0x16C0 */
    uint8_t _pad_16C1[1007];
    uint8_t field_1AB0; /* size unknown at 0x1AB0 */
    uint8_t _pad_1AB1[39];
    uint8_t field_1AD8; /* size unknown at 0x1AD8 */
    uint8_t _pad_1AD9[143];
    uint8_t field_1B68; /* size unknown at 0x1B68 */
    uint8_t _pad_1B69[39];
    uint8_t field_1B90; /* size unknown at 0x1B90 */
    uint8_t _pad_1B91[39];
    uint8_t field_1BB8; /* size unknown at 0x1BB8 */
    uint8_t _pad_1BB9[55];
    uint8_t field_1BF0; /* size unknown at 0x1BF0 */
    uint8_t _pad_1BF1[55];
    uint8_t field_1C28; /* size unknown at 0x1C28 */
    uint8_t _pad_1C29[3479];
    uint8_t field_29C0; /* size unknown at 0x29C0 */
    uint8_t _pad_29C1[111];
    uint8_t field_2A30; /* size unknown at 0x2A30 */
    uint8_t _pad_2A31[23];
    uint8_t field_2A48; /* size unknown at 0x2A48 */
    uint8_t _pad_2A49[39];
    uint8_t field_2A70; /* size unknown at 0x2A70 */
    uint8_t _pad_2A71[5383];
    uint8_t field_3F78; /* size unknown at 0x3F78 */
    uint8_t _pad_3F79[71];
    uint8_t field_3FC0; /* size unknown at 0x3FC0 */
    uint8_t _pad_3FC1[47];
    uint64_t field_3FF0;
} ccAdvManager; /* size unknown, >= 0x3FF8 */

static_assert(offsetof(ccAdvManager, field_0058) == 0x58, "ccAdvManager::field_0058 offset");
static_assert(offsetof(ccAdvManager, field_0060) == 0x60, "ccAdvManager::field_0060 offset");
static_assert(offsetof(ccAdvManager, field_0068) == 0x68, "ccAdvManager::field_0068 offset");
static_assert(offsetof(ccAdvManager, field_0070) == 0x70, "ccAdvManager::field_0070 offset");
static_assert(offsetof(ccAdvManager, field_0078) == 0x78, "ccAdvManager::field_0078 offset");
static_assert(offsetof(ccAdvManager, field_0080) == 0x80, "ccAdvManager::field_0080 offset");
static_assert(offsetof(ccAdvManager, field_0098) == 0x98, "ccAdvManager::field_0098 offset");
static_assert(offsetof(ccAdvManager, field_0188) == 0x188, "ccAdvManager::field_0188 offset");
static_assert(offsetof(ccAdvManager, field_018C) == 0x18C, "ccAdvManager::field_018C offset");
static_assert(offsetof(ccAdvManager, field_0190) == 0x190, "ccAdvManager::field_0190 offset");
static_assert(offsetof(ccAdvManager, field_0198) == 0x198, "ccAdvManager::field_0198 offset");
static_assert(offsetof(ccAdvManager, field_01A0) == 0x1A0, "ccAdvManager::field_01A0 offset");
static_assert(offsetof(ccAdvManager, field_01A8) == 0x1A8, "ccAdvManager::field_01A8 offset");
static_assert(offsetof(ccAdvManager, field_01B0) == 0x1B0, "ccAdvManager::field_01B0 offset");
static_assert(offsetof(ccAdvManager, field_01B4) == 0x1B4, "ccAdvManager::field_01B4 offset");
static_assert(offsetof(ccAdvManager, field_01B8) == 0x1B8, "ccAdvManager::field_01B8 offset");
static_assert(offsetof(ccAdvManager, field_01F0) == 0x1F0, "ccAdvManager::field_01F0 offset");
static_assert(offsetof(ccAdvManager, field_01F8) == 0x1F8, "ccAdvManager::field_01F8 offset");
static_assert(offsetof(ccAdvManager, field_0200) == 0x200, "ccAdvManager::field_0200 offset");
static_assert(offsetof(ccAdvManager, field_1598) == 0x1598, "ccAdvManager::field_1598 offset");
static_assert(offsetof(ccAdvManager, field_15F0) == 0x15F0, "ccAdvManager::field_15F0 offset");
static_assert(offsetof(ccAdvManager, field_1618) == 0x1618, "ccAdvManager::field_1618 offset");
static_assert(offsetof(ccAdvManager, field_1648) == 0x1648, "ccAdvManager::field_1648 offset");
static_assert(offsetof(ccAdvManager, field_1670) == 0x1670, "ccAdvManager::field_1670 offset");
static_assert(offsetof(ccAdvManager, field_1698) == 0x1698, "ccAdvManager::field_1698 offset");
static_assert(offsetof(ccAdvManager, field_16C0) == 0x16C0, "ccAdvManager::field_16C0 offset");
static_assert(offsetof(ccAdvManager, field_1AB0) == 0x1AB0, "ccAdvManager::field_1AB0 offset");
static_assert(offsetof(ccAdvManager, field_1AD8) == 0x1AD8, "ccAdvManager::field_1AD8 offset");
static_assert(offsetof(ccAdvManager, field_1B68) == 0x1B68, "ccAdvManager::field_1B68 offset");
static_assert(offsetof(ccAdvManager, field_1B90) == 0x1B90, "ccAdvManager::field_1B90 offset");
static_assert(offsetof(ccAdvManager, field_1BB8) == 0x1BB8, "ccAdvManager::field_1BB8 offset");
static_assert(offsetof(ccAdvManager, field_1BF0) == 0x1BF0, "ccAdvManager::field_1BF0 offset");
static_assert(offsetof(ccAdvManager, field_1C28) == 0x1C28, "ccAdvManager::field_1C28 offset");
static_assert(offsetof(ccAdvManager, field_29C0) == 0x29C0, "ccAdvManager::field_29C0 offset");
static_assert(offsetof(ccAdvManager, field_2A30) == 0x2A30, "ccAdvManager::field_2A30 offset");
static_assert(offsetof(ccAdvManager, field_2A48) == 0x2A48, "ccAdvManager::field_2A48 offset");
static_assert(offsetof(ccAdvManager, field_2A70) == 0x2A70, "ccAdvManager::field_2A70 offset");
static_assert(offsetof(ccAdvManager, field_3F78) == 0x3F78, "ccAdvManager::field_3F78 offset");
static_assert(offsetof(ccAdvManager, field_3FC0) == 0x3FC0, "ccAdvManager::field_3FC0 offset");
static_assert(offsetof(ccAdvManager, field_3FF0) == 0x3FF0, "ccAdvManager::field_3FF0 offset");

typedef struct __attribute__((packed)) ccAdvMobDraw {
    uint8_t _pad_0000[20];
    uint32_t field_0014;
    uint8_t _pad_0018[168];
    uint8_t field_00C0; /* size unknown at 0xC0 */
} ccAdvMobDraw; /* size unknown, >= 0xC1 */

static_assert(offsetof(ccAdvMobDraw, field_0014) == 0x14, "ccAdvMobDraw::field_0014 offset");
static_assert(offsetof(ccAdvMobDraw, field_00C0) == 0xC0, "ccAdvMobDraw::field_00C0 offset");

/* ccAdvMobFileLoadList: no fields recovered (byte-cast accesses only) */
typedef struct __attribute__((packed)) ccAdvMobFileLoadList { uint8_t _empty; } ccAdvMobFileLoadList; /* size unknown */

typedef struct __attribute__((packed)) ccAdvMobObjDraw {
    uint8_t _pad_0000[244];
    uint32_t field_00F4;
    uint8_t _pad_00F8[136];
    uint8_t field_0180; /* size unknown at 0x180 */
    uint8_t _pad_0181[359];
    uint32_t field_02E8;
    uint32_t field_02EC;
    uint8_t field_02F0; /* size unknown at 0x2F0 */
    uint8_t _pad_02F1[55];
    uint8_t field_0328; /* size unknown at 0x328 */
} ccAdvMobObjDraw; /* size unknown, >= 0x329 */

static_assert(offsetof(ccAdvMobObjDraw, field_00F4) == 0xF4, "ccAdvMobObjDraw::field_00F4 offset");
static_assert(offsetof(ccAdvMobObjDraw, field_0180) == 0x180, "ccAdvMobObjDraw::field_0180 offset");
static_assert(offsetof(ccAdvMobObjDraw, field_02E8) == 0x2E8, "ccAdvMobObjDraw::field_02E8 offset");
static_assert(offsetof(ccAdvMobObjDraw, field_02EC) == 0x2EC, "ccAdvMobObjDraw::field_02EC offset");
static_assert(offsetof(ccAdvMobObjDraw, field_02F0) == 0x2F0, "ccAdvMobObjDraw::field_02F0 offset");
static_assert(offsetof(ccAdvMobObjDraw, field_0328) == 0x328, "ccAdvMobObjDraw::field_0328 offset");

typedef struct __attribute__((packed)) ccAdvMobParam {
    uint8_t _pad_0000[164];
    uint8_t field_00A4; /* size unknown at 0xA4 */
    uint8_t _pad_00A5[23];
    uint8_t field_00BC; /* size unknown at 0xBC */
    uint8_t _pad_00BD[27];
    uint64_t field_00D8;
    uint64_t field_00E0;
    uint8_t field_00E8; /* size unknown at 0xE8 */
    uint8_t _pad_00E9[11];
    uint8_t field_00F4; /* size unknown at 0xF4 */
    uint8_t _pad_00F5[63];
    float field_0134;
    uint8_t field_0138; /* size unknown at 0x138 */
    uint8_t _pad_0139[55];
    uint8_t field_0170; /* size unknown at 0x170 */
    uint8_t _pad_0171[55];
    uint32_t field_01A8;
    uint8_t _pad_01AC[12];
    uint8_t field_01B8; /* size unknown at 0x1B8 */
    uint8_t _pad_01B9[2055];
    uint8_t field_09C0; /* size unknown at 0x9C0 */
    uint8_t _pad_09C1[1423];
    uint8_t field_0F50; /* size unknown at 0xF50 */
    uint8_t _pad_0F51[1423];
    uint64_t field_14E0;
    uint64_t field_14E8;
    uint64_t field_14F0;
    uint8_t field_14F8; /* size unknown at 0x14F8 */
    uint8_t _pad_14F9[79];
    uint8_t field_1548; /* size unknown at 0x1548 */
    uint8_t _pad_1549[111];
    uint32_t field_15B8;
    uint32_t field_15BC;
    uint32_t field_15C0;
    uint32_t field_15C4;
    uint32_t field_15C8;
    uint32_t field_15CC;
    float field_15D0;
    uint8_t _pad_15D4[4];
    uint64_t field_15D8;
} ccAdvMobParam; /* size unknown, >= 0x15E0 */

static_assert(offsetof(ccAdvMobParam, field_00A4) == 0xA4, "ccAdvMobParam::field_00A4 offset");
static_assert(offsetof(ccAdvMobParam, field_00BC) == 0xBC, "ccAdvMobParam::field_00BC offset");
static_assert(offsetof(ccAdvMobParam, field_00D8) == 0xD8, "ccAdvMobParam::field_00D8 offset");
static_assert(offsetof(ccAdvMobParam, field_00E0) == 0xE0, "ccAdvMobParam::field_00E0 offset");
static_assert(offsetof(ccAdvMobParam, field_00E8) == 0xE8, "ccAdvMobParam::field_00E8 offset");
static_assert(offsetof(ccAdvMobParam, field_00F4) == 0xF4, "ccAdvMobParam::field_00F4 offset");
static_assert(offsetof(ccAdvMobParam, field_0134) == 0x134, "ccAdvMobParam::field_0134 offset");
static_assert(offsetof(ccAdvMobParam, field_0138) == 0x138, "ccAdvMobParam::field_0138 offset");
static_assert(offsetof(ccAdvMobParam, field_0170) == 0x170, "ccAdvMobParam::field_0170 offset");
static_assert(offsetof(ccAdvMobParam, field_01A8) == 0x1A8, "ccAdvMobParam::field_01A8 offset");
static_assert(offsetof(ccAdvMobParam, field_01B8) == 0x1B8, "ccAdvMobParam::field_01B8 offset");
static_assert(offsetof(ccAdvMobParam, field_09C0) == 0x9C0, "ccAdvMobParam::field_09C0 offset");
static_assert(offsetof(ccAdvMobParam, field_0F50) == 0xF50, "ccAdvMobParam::field_0F50 offset");
static_assert(offsetof(ccAdvMobParam, field_14E0) == 0x14E0, "ccAdvMobParam::field_14E0 offset");
static_assert(offsetof(ccAdvMobParam, field_14E8) == 0x14E8, "ccAdvMobParam::field_14E8 offset");
static_assert(offsetof(ccAdvMobParam, field_14F0) == 0x14F0, "ccAdvMobParam::field_14F0 offset");
static_assert(offsetof(ccAdvMobParam, field_14F8) == 0x14F8, "ccAdvMobParam::field_14F8 offset");
static_assert(offsetof(ccAdvMobParam, field_1548) == 0x1548, "ccAdvMobParam::field_1548 offset");
static_assert(offsetof(ccAdvMobParam, field_15B8) == 0x15B8, "ccAdvMobParam::field_15B8 offset");
static_assert(offsetof(ccAdvMobParam, field_15BC) == 0x15BC, "ccAdvMobParam::field_15BC offset");
static_assert(offsetof(ccAdvMobParam, field_15C0) == 0x15C0, "ccAdvMobParam::field_15C0 offset");
static_assert(offsetof(ccAdvMobParam, field_15C4) == 0x15C4, "ccAdvMobParam::field_15C4 offset");
static_assert(offsetof(ccAdvMobParam, field_15C8) == 0x15C8, "ccAdvMobParam::field_15C8 offset");
static_assert(offsetof(ccAdvMobParam, field_15CC) == 0x15CC, "ccAdvMobParam::field_15CC offset");
static_assert(offsetof(ccAdvMobParam, field_15D0) == 0x15D0, "ccAdvMobParam::field_15D0 offset");
static_assert(offsetof(ccAdvMobParam, field_15D8) == 0x15D8, "ccAdvMobParam::field_15D8 offset");

typedef struct __attribute__((packed)) ccAdvMobState {
    uint8_t _pad_0000[5304];
    uint64_t field_14B8;
    uint32_t field_14C0;
    uint8_t _pad_14C4[4];
    uint64_t field_14C8;
    uint64_t field_14D0;
    uint64_t field_14D8;
    uint8_t field_14E0; /* size unknown at 0x14E0 */
    uint8_t _pad_14E1[11];
    uint8_t field_14EC; /* size unknown at 0x14EC */
    uint8_t _pad_14ED[11];
    uint8_t field_14F8; /* size unknown at 0x14F8 */
    uint8_t _pad_14F9[11];
    uint8_t field_1504; /* size unknown at 0x1504 */
    uint8_t _pad_1505[11];
    uint64_t field_1510;
    uint32_t field_1518;
    uint32_t field_151C;
    uint64_t field_1520;
    uint8_t _pad_1528[8];
    uint64_t field_1530;
    uint64_t field_1538;
    uint64_t field_1540;
    uint64_t field_1548;
    uint32_t field_1550;
    float field_1554;
    uint64_t field_1558;
    uint8_t field_1560; /* size unknown at 0x1560 */
    uint8_t _pad_1561[15];
    uint64_t field_1570;
    uint64_t field_1578;
    uint64_t field_1580;
    uint32_t field_1588;
    uint64_t field_158C;
    uint32_t field_1594;
    uint64_t field_1598;
    uint64_t field_15A0;
    uint8_t field_15A8; /* size unknown at 0x15A8 */
    uint8_t _pad_15A9[111];
    uint8_t field_1618; /* size unknown at 0x1618 */
} ccAdvMobState; /* size unknown, >= 0x1619 */

static_assert(offsetof(ccAdvMobState, field_14B8) == 0x14B8, "ccAdvMobState::field_14B8 offset");
static_assert(offsetof(ccAdvMobState, field_14C0) == 0x14C0, "ccAdvMobState::field_14C0 offset");
static_assert(offsetof(ccAdvMobState, field_14C8) == 0x14C8, "ccAdvMobState::field_14C8 offset");
static_assert(offsetof(ccAdvMobState, field_14D0) == 0x14D0, "ccAdvMobState::field_14D0 offset");
static_assert(offsetof(ccAdvMobState, field_14D8) == 0x14D8, "ccAdvMobState::field_14D8 offset");
static_assert(offsetof(ccAdvMobState, field_14E0) == 0x14E0, "ccAdvMobState::field_14E0 offset");
static_assert(offsetof(ccAdvMobState, field_14EC) == 0x14EC, "ccAdvMobState::field_14EC offset");
static_assert(offsetof(ccAdvMobState, field_14F8) == 0x14F8, "ccAdvMobState::field_14F8 offset");
static_assert(offsetof(ccAdvMobState, field_1504) == 0x1504, "ccAdvMobState::field_1504 offset");
static_assert(offsetof(ccAdvMobState, field_1510) == 0x1510, "ccAdvMobState::field_1510 offset");
static_assert(offsetof(ccAdvMobState, field_1518) == 0x1518, "ccAdvMobState::field_1518 offset");
static_assert(offsetof(ccAdvMobState, field_151C) == 0x151C, "ccAdvMobState::field_151C offset");
static_assert(offsetof(ccAdvMobState, field_1520) == 0x1520, "ccAdvMobState::field_1520 offset");
static_assert(offsetof(ccAdvMobState, field_1530) == 0x1530, "ccAdvMobState::field_1530 offset");
static_assert(offsetof(ccAdvMobState, field_1538) == 0x1538, "ccAdvMobState::field_1538 offset");
static_assert(offsetof(ccAdvMobState, field_1540) == 0x1540, "ccAdvMobState::field_1540 offset");
static_assert(offsetof(ccAdvMobState, field_1548) == 0x1548, "ccAdvMobState::field_1548 offset");
static_assert(offsetof(ccAdvMobState, field_1550) == 0x1550, "ccAdvMobState::field_1550 offset");
static_assert(offsetof(ccAdvMobState, field_1554) == 0x1554, "ccAdvMobState::field_1554 offset");
static_assert(offsetof(ccAdvMobState, field_1558) == 0x1558, "ccAdvMobState::field_1558 offset");
static_assert(offsetof(ccAdvMobState, field_1560) == 0x1560, "ccAdvMobState::field_1560 offset");
static_assert(offsetof(ccAdvMobState, field_1570) == 0x1570, "ccAdvMobState::field_1570 offset");
static_assert(offsetof(ccAdvMobState, field_1578) == 0x1578, "ccAdvMobState::field_1578 offset");
static_assert(offsetof(ccAdvMobState, field_1580) == 0x1580, "ccAdvMobState::field_1580 offset");
static_assert(offsetof(ccAdvMobState, field_1588) == 0x1588, "ccAdvMobState::field_1588 offset");
static_assert(offsetof(ccAdvMobState, field_158C) == 0x158C, "ccAdvMobState::field_158C offset");
static_assert(offsetof(ccAdvMobState, field_1594) == 0x1594, "ccAdvMobState::field_1594 offset");
static_assert(offsetof(ccAdvMobState, field_1598) == 0x1598, "ccAdvMobState::field_1598 offset");
static_assert(offsetof(ccAdvMobState, field_15A0) == 0x15A0, "ccAdvMobState::field_15A0 offset");
static_assert(offsetof(ccAdvMobState, field_15A8) == 0x15A8, "ccAdvMobState::field_15A8 offset");
static_assert(offsetof(ccAdvMobState, field_1618) == 0x1618, "ccAdvMobState::field_1618 offset");

/* ccAdvNavigator: no fields recovered (byte-cast accesses only) */
typedef struct __attribute__((packed)) ccAdvNavigator { uint8_t _empty; } ccAdvNavigator; /* size unknown */

typedef struct __attribute__((packed)) ccAdvObjectDrawList {
    uint8_t _pad_0000[128];
    uint8_t field_0080; /* size unknown at 0x80 */
    uint8_t _pad_0081[87];
    uint8_t field_00D8; /* size unknown at 0xD8 */
    uint8_t _pad_00D9[5639];
    uint8_t field_16E0; /* size unknown at 0x16E0 */
    uint8_t _pad_16E1[399];
    uint8_t field_1870; /* size unknown at 0x1870 */
    uint8_t _pad_1871[7];
    uint64_t field_1878;
    uint64_t field_1880;
    uint64_t field_1888;
    uint8_t _pad_1890[16];
    uint8_t field_18A0; /* size unknown at 0x18A0 */
    uint8_t _pad_18A1[7];
    uint64_t field_18A8;
    uint64_t field_18B0;
    uint64_t field_18B8;
    uint8_t _pad_18C0[16];
    uint8_t field_18D0; /* size unknown at 0x18D0 */
    uint8_t _pad_18D1[7];
    uint64_t field_18D8;
    uint64_t field_18E0;
    uint64_t field_18E8;
} ccAdvObjectDrawList; /* size unknown, >= 0x18F0 */

static_assert(offsetof(ccAdvObjectDrawList, field_0080) == 0x80, "ccAdvObjectDrawList::field_0080 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_00D8) == 0xD8, "ccAdvObjectDrawList::field_00D8 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_16E0) == 0x16E0, "ccAdvObjectDrawList::field_16E0 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_1870) == 0x1870, "ccAdvObjectDrawList::field_1870 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_1878) == 0x1878, "ccAdvObjectDrawList::field_1878 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_1880) == 0x1880, "ccAdvObjectDrawList::field_1880 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_1888) == 0x1888, "ccAdvObjectDrawList::field_1888 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18A0) == 0x18A0, "ccAdvObjectDrawList::field_18A0 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18A8) == 0x18A8, "ccAdvObjectDrawList::field_18A8 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18B0) == 0x18B0, "ccAdvObjectDrawList::field_18B0 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18B8) == 0x18B8, "ccAdvObjectDrawList::field_18B8 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18D0) == 0x18D0, "ccAdvObjectDrawList::field_18D0 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18D8) == 0x18D8, "ccAdvObjectDrawList::field_18D8 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18E0) == 0x18E0, "ccAdvObjectDrawList::field_18E0 offset");
static_assert(offsetof(ccAdvObjectDrawList, field_18E8) == 0x18E8, "ccAdvObjectDrawList::field_18E8 offset");
