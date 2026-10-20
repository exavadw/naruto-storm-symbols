/* st1c02.h — Storm 1 (NSUNS1.exe) struct layouts for story/cutscene classes
 * Build: s1 (SHA 10231093af9c)
 * Generated from Ghidra decompilation + state_surface analysis
 * All layouts INFERRED unless marked PROVEN
 * Uses __attribute__((packed)) to guarantee exact field offsets
 */

#ifndef ST1C02_H
#define ST1C02_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ccIAEventTutorial */
/* Size: 0x20 */
typedef struct __attribute__((packed)) ccIAEventTutorial {
    void* vtable; /* 0x0 [high] vtable pointer */
    uint32_t pad_08; /* 0x8 [low] gap */
    uint32_t tutorialId; /* 0xC [high] read in Ctrl, written to msg window +0xa8 */
    uint8_t pad_10[16]; /* 0x10 [low] padding to 0x20 */
} ccIAEventTutorial;

static_assert(offsetof(ccIAEventTutorial, tutorialId) == 0xC, "ccIAEventTutorial::tutorialId offset mismatch");

/* ccMessageWindow */
/* Size: 0xA8 */
typedef struct __attribute__((packed)) ccMessageWindow {
    void* vtable; /* 0x0 [high] vtable pointer */
    void* msgDataList; /* 0x8 [medium] message data list head (seen in subclass dtors) */
    void* backSprite; /* 0x10 [high] background sprite (nuccSprite::SetAlpha in Inits) */
    uint64_t pad_18; /* 0x18 [low] unknown base field */
    uint64_t pad_20; /* 0x20 [low] unknown base field */
    uint64_t pad_28; /* 0x28 [low] unknown base field */
    uint64_t pad_30; /* 0x30 [low] unknown base field */
    void* turnPageBtn; /* 0x38 [medium] turn page button sprite (Puppet/System Inits) */
    uint64_t pad_40; /* 0x40 [low] unknown base field */
    void* dispFont; /* 0x48 [high] ccDispFont pointer (used in all subclass Inits) */
    uint32_t pad_50; /* 0x50 [low] gap before state_surface field */
    uint32_t windowState; /* 0x54 [medium] state_surface high-conf field */
    uint32_t pad_58; /* 0x58 [low] gap */
    float posX; /* 0x5C [high] X position (set in all subclass Inits) */
    float posY; /* 0x60 [high] Y position (set in all subclass Inits) */
    uint32_t pad_64; /* 0x64 [low] gap */
    uint32_t fontSize; /* 0x68 [high] font size index (0xf in most Inits) */
    float scaleX; /* 0x6C [high] horizontal scale factor */
    float scaleY; /* 0x70 [high] vertical scale factor */
    uint64_t pad_74; /* 0x74 [low] gap */
    uint32_t msgIndex; /* 0x7C [medium] state_surface field, message-related */
    uint64_t pad_80; /* 0x80 [low] gap */
    uint32_t animFrame; /* 0x88 [high] animation frame counter (init to 0 in all Inits) */
    uint32_t pad_8C; /* 0x8C [low] gap */
    uint16_t pad_90; /* 0x90 [low] gap */
    uint16_t isOpen; /* 0x92 [high] window open flag (checked in Talking::Open) */
    uint16_t visible; /* 0x94 [high] visibility flag (init to 0/1 in all Inits) */
    uint16_t pad_96; /* 0x96 [low] gap to 0x98 */
    uint8_t _tail_0x98[16];
} ccMessageWindow;

static_assert(offsetof(ccMessageWindow, msgDataList) == 0x8, "ccMessageWindow::msgDataList offset mismatch");
static_assert(offsetof(ccMessageWindow, backSprite) == 0x10, "ccMessageWindow::backSprite offset mismatch");
static_assert(offsetof(ccMessageWindow, turnPageBtn) == 0x38, "ccMessageWindow::turnPageBtn offset mismatch");
static_assert(offsetof(ccMessageWindow, dispFont) == 0x48, "ccMessageWindow::dispFont offset mismatch");
static_assert(offsetof(ccMessageWindow, windowState) == 0x54, "ccMessageWindow::windowState offset mismatch");
static_assert(offsetof(ccMessageWindow, posX) == 0x5C, "ccMessageWindow::posX offset mismatch");
static_assert(offsetof(ccMessageWindow, posY) == 0x60, "ccMessageWindow::posY offset mismatch");
static_assert(offsetof(ccMessageWindow, fontSize) == 0x68, "ccMessageWindow::fontSize offset mismatch");
static_assert(offsetof(ccMessageWindow, scaleX) == 0x6C, "ccMessageWindow::scaleX offset mismatch");
static_assert(offsetof(ccMessageWindow, scaleY) == 0x70, "ccMessageWindow::scaleY offset mismatch");
static_assert(offsetof(ccMessageWindow, msgIndex) == 0x7C, "ccMessageWindow::msgIndex offset mismatch");
static_assert(offsetof(ccMessageWindow, animFrame) == 0x88, "ccMessageWindow::animFrame offset mismatch");
static_assert(offsetof(ccMessageWindow, isOpen) == 0x92, "ccMessageWindow::isOpen offset mismatch");
static_assert(offsetof(ccMessageWindow, visible) == 0x94, "ccMessageWindow::visible offset mismatch");

/* ccMessageWindowManager */
/* Size: 0x790 */
typedef struct __attribute__((packed)) ccMessageWindowManager {
    void* vtable; /* 0x0 [high] vtable pointer */
    uint8_t pad_08[48]; /* 0x8 [low] gap to first known field */
    void* activeWindow; /* 0x38 [medium] state_surface field */
    void* windowArray; /* 0x40 [medium] state_surface field */
    uint64_t windowCount; /* 0x48 [medium] state_surface field */
    uint8_t pad_50[1840]; /* 0x50 [low] large gap to 0x780 */
    void* managerData; /* 0x780 [medium] state_surface field */
    uint64_t pad_788; /* 0x788 [low] padding */
} ccMessageWindowManager;

static_assert(offsetof(ccMessageWindowManager, activeWindow) == 0x38, "ccMessageWindowManager::activeWindow offset mismatch");
static_assert(offsetof(ccMessageWindowManager, windowArray) == 0x40, "ccMessageWindowManager::windowArray offset mismatch");
static_assert(offsetof(ccMessageWindowManager, windowCount) == 0x48, "ccMessageWindowManager::windowCount offset mismatch");
static_assert(offsetof(ccMessageWindowManager, managerData) == 0x780, "ccMessageWindowManager::managerData offset mismatch");

/* ccMovie__SkipSelect */
/* Size: unknown */
typedef struct __attribute__((packed)) ccMovie__SkipSelect {
    int32_t state; /* 0x0 [high] state machine: 0=idle, 3,4,5,6=skip phases */
    uint8_t pad_04[12]; /* 0x4 [low] padding */
} ccMovie__SkipSelect;

static_assert(offsetof(ccMovie__SkipSelect, state) == 0x0, "ccMovie__SkipSelect::state offset mismatch");

/* ccMsgWindowGeneral */
/* Size: 0xC0 */
typedef struct __attribute__((packed)) ccMsgWindowGeneral {
    uint8_t _gap_0x0[168];
    void* extraSprite; /* 0xA8 [medium] additional sprite reference (Talking::Open checks) */
    float anchorX; /* 0xB0 [high] anchor X (-1.0 default in Init) */
    float anchorY; /* 0xB4 [high] anchor Y (-1.0 default in Init) */
    uint64_t pad_B8; /* 0xB8 [low] padding to 0xC0 */
} ccMsgWindowGeneral;

static_assert(offsetof(ccMsgWindowGeneral, extraSprite) == 0xA8, "ccMsgWindowGeneral::extraSprite offset mismatch");
static_assert(offsetof(ccMsgWindowGeneral, anchorX) == 0xB0, "ccMsgWindowGeneral::anchorX offset mismatch");
static_assert(offsetof(ccMsgWindowGeneral, anchorY) == 0xB4, "ccMsgWindowGeneral::anchorY offset mismatch");

/* ccMsgWindowHugebtl */
/* Size: 0xD0 */
typedef struct __attribute__((packed)) ccMsgWindowHugebtl {
    uint8_t _gap_0x0[32];
    uint8_t mathGeoPlane[32]; /* 0x20 [high] embedded MathGeoPlane (dtor destroys at param_1+4) */
    uint8_t _gap_0x40[104];
    uint64_t pad_A8; /* 0xA8 [low] gap */
    uint64_t pad_B0; /* 0xB0 [low] gap */
    void* dispSprite; /* 0xB8 [high] ccDispSprite::Create(0x26) in Init */
    void* dispSpriteAnm; /* 0xC0 [high] ccDispSpriteAnm::Create(0x2f) in Init */
    uint64_t pad_C8; /* 0xC8 [low] padding */
} ccMsgWindowHugebtl;

static_assert(offsetof(ccMsgWindowHugebtl, mathGeoPlane) == 0x20, "ccMsgWindowHugebtl::mathGeoPlane offset mismatch");
static_assert(offsetof(ccMsgWindowHugebtl, dispSprite) == 0xB8, "ccMsgWindowHugebtl::dispSprite offset mismatch");
static_assert(offsetof(ccMsgWindowHugebtl, dispSpriteAnm) == 0xC0, "ccMsgWindowHugebtl::dispSpriteAnm offset mismatch");

/* ccMsgWindowItem */
/* Size: 0x180 */
typedef struct __attribute__((packed)) ccMsgWindowItem {
    uint8_t _gap_0x0[168];
    uint8_t msgDataList[8]; /* 0xA8 [high] nuccList_cmnMessageData ReleaseAll in Init */
    uint64_t pad_B0; /* 0xB0 [low] gap */
    uint64_t pad_B8; /* 0xB8 [low] gap */
    uint64_t pad_C0; /* 0xC0 [low] gap */
    uint64_t pad_C8; /* 0xC8 [low] gap */
    uint64_t pad_D0; /* 0xD0 [low] gap */
    uint64_t pad_D8; /* 0xD8 [low] gap */
    uint64_t pad_E0; /* 0xE0 [low] gap */
    uint32_t pad_E8; /* 0xE8 [low] gap */
    uint32_t itemCount; /* 0xEC [high] init to 0 in Init */
    uint8_t itemTextBuf[128]; /* 0xF0 [high] snprintf 0x80 bytes in Init */
    uint8_t pad_170[16]; /* 0x170 [low] padding to 0x180 */
} ccMsgWindowItem;

static_assert(offsetof(ccMsgWindowItem, msgDataList) == 0xA8, "ccMsgWindowItem::msgDataList offset mismatch");
static_assert(offsetof(ccMsgWindowItem, itemCount) == 0xEC, "ccMsgWindowItem::itemCount offset mismatch");
static_assert(offsetof(ccMsgWindowItem, itemTextBuf) == 0xF0, "ccMsgWindowItem::itemTextBuf offset mismatch");

/* ccMsgWindowPlot */
/* Size: 0x100 */
typedef struct __attribute__((packed)) ccMsgWindowPlot {
    uint8_t _gap_0x0[168];
    uint32_t plotFlag; /* 0xA8 [high] init to 0 in Init */
    uint32_t pad_AC; /* 0xAC [low] gap */
    uint8_t msgDataList[8]; /* 0xB0 [high] nuccList ReleaseAll in Init & dtor */
    uint64_t pad_B8; /* 0xB8 [low] gap */
    uint64_t pad_C0; /* 0xC0 [low] gap */
    uint64_t pad_C8; /* 0xC8 [low] gap */
    uint64_t pad_D0; /* 0xD0 [low] gap */
    uint64_t pad_D8; /* 0xD8 [low] gap */
    uint64_t pad_E0; /* 0xE0 [low] gap */
    void* plotData; /* 0xE8 [high] init to 0 in Init */
    uint32_t plotState; /* 0xF0 [high] init to 0 in Init */
    uint8_t pad_F4[12]; /* 0xF4 [low] padding to 0x100 */
} ccMsgWindowPlot;

static_assert(offsetof(ccMsgWindowPlot, plotFlag) == 0xA8, "ccMsgWindowPlot::plotFlag offset mismatch");
static_assert(offsetof(ccMsgWindowPlot, msgDataList) == 0xB0, "ccMsgWindowPlot::msgDataList offset mismatch");
static_assert(offsetof(ccMsgWindowPlot, plotData) == 0xE8, "ccMsgWindowPlot::plotData offset mismatch");
static_assert(offsetof(ccMsgWindowPlot, plotState) == 0xF0, "ccMsgWindowPlot::plotState offset mismatch");

/* ccMsgWindowPuppet */
/* Size: 0xC8 */
typedef struct __attribute__((packed)) ccMsgWindowPuppet {
    uint8_t _gap_0x0[168];
    void* puppetSprite; /* 0xA8 [high] ccDispSprite::Create(0x153) in Init */
    void* puppetSpriteAnm; /* 0xB0 [high] ccDispSpriteAnm::Create(0x298) in Init */
    void* postEffectGlare; /* 0xB8 [high] nuccPostEffectGlare created in Init */
    uint64_t pad_C0; /* 0xC0 [low] padding */
} ccMsgWindowPuppet;

static_assert(offsetof(ccMsgWindowPuppet, puppetSprite) == 0xA8, "ccMsgWindowPuppet::puppetSprite offset mismatch");
static_assert(offsetof(ccMsgWindowPuppet, puppetSpriteAnm) == 0xB0, "ccMsgWindowPuppet::puppetSpriteAnm offset mismatch");
static_assert(offsetof(ccMsgWindowPuppet, postEffectGlare) == 0xB8, "ccMsgWindowPuppet::postEffectGlare offset mismatch");

/* ccMsgWindowSelect */
/* Size: 0x100 */
typedef struct __attribute__((packed)) ccMsgWindowSelect {
    uint8_t _gap_0x0[168];
    uint64_t pad_A8; /* 0xA8 [low] gap */
    uint8_t msgDataList[8]; /* 0xB0 [high] nuccList ReleaseAll in Init */
    uint64_t pad_B8; /* 0xB8 [low] gap */
    uint64_t pad_C0; /* 0xC0 [low] gap */
    uint64_t pad_C8; /* 0xC8 [low] gap */
    uint64_t pad_D0; /* 0xD0 [low] gap */
    uint64_t pad_D8; /* 0xD8 [low] gap */
    uint64_t pad_E0; /* 0xE0 [low] gap */
    uint32_t selectIndex; /* 0xE8 [high] init to -1 in Init */
    uint32_t selectCount; /* 0xEC [high] init to 0 in Init */
    uint32_t selectState; /* 0xF0 [high] init to 0 in Init */
    uint32_t pad_F4; /* 0xF4 [low] gap */
    void* selectData; /* 0xF8 [high] init to 0 in Init */
} ccMsgWindowSelect;

static_assert(offsetof(ccMsgWindowSelect, msgDataList) == 0xB0, "ccMsgWindowSelect::msgDataList offset mismatch");
static_assert(offsetof(ccMsgWindowSelect, selectIndex) == 0xE8, "ccMsgWindowSelect::selectIndex offset mismatch");
static_assert(offsetof(ccMsgWindowSelect, selectCount) == 0xEC, "ccMsgWindowSelect::selectCount offset mismatch");
static_assert(offsetof(ccMsgWindowSelect, selectState) == 0xF0, "ccMsgWindowSelect::selectState offset mismatch");
static_assert(offsetof(ccMsgWindowSelect, selectData) == 0xF8, "ccMsgWindowSelect::selectData offset mismatch");

/* ccMsgWindowSystem */
/* Size: 0x4C0 */
typedef struct __attribute__((packed)) ccMsgWindowSystem {
    uint8_t _gap_0x0[168];
    void* sysSprite; /* 0xA8 [high] init to 0 in Init */
    uint64_t pad_B0; /* 0xB0 [low] large gap to 0x4B0 */
    uint8_t _gap_0xB8[1016];
    void* sysSpriteAnm; /* 0x4B0 [high] ccDispSpriteAnm::Create(0x32) in Init */
    uint32_t sysFlag; /* 0x4B8 [high] init to 1 in Init */
    uint32_t sysState; /* 0x4BC [high] init to -1 in Init */
} ccMsgWindowSystem;

static_assert(offsetof(ccMsgWindowSystem, sysSprite) == 0xA8, "ccMsgWindowSystem::sysSprite offset mismatch");
static_assert(offsetof(ccMsgWindowSystem, sysSpriteAnm) == 0x4B0, "ccMsgWindowSystem::sysSpriteAnm offset mismatch");
static_assert(offsetof(ccMsgWindowSystem, sysFlag) == 0x4B8, "ccMsgWindowSystem::sysFlag offset mismatch");
static_assert(offsetof(ccMsgWindowSystem, sysState) == 0x4BC, "ccMsgWindowSystem::sysState offset mismatch");

/* ccMsgWindowTalking */
/* Size: 0xC0 */
typedef struct __attribute__((packed)) ccMsgWindowTalking {
    uint8_t _gap_0x0[168];
    void* talkTarget; /* 0xA8 [high] checked non-null in Open, deref +0x84 */
    float anchorX; /* 0xB0 [medium] same pattern as General */
    float anchorY; /* 0xB4 [medium] same pattern as General */
    uint64_t pad_B8; /* 0xB8 [low] padding */
} ccMsgWindowTalking;

static_assert(offsetof(ccMsgWindowTalking, talkTarget) == 0xA8, "ccMsgWindowTalking::talkTarget offset mismatch");
static_assert(offsetof(ccMsgWindowTalking, anchorX) == 0xB0, "ccMsgWindowTalking::anchorX offset mismatch");
static_assert(offsetof(ccMsgWindowTalking, anchorY) == 0xB4, "ccMsgWindowTalking::anchorY offset mismatch");

/* ccNarutoRootObjManagerSearchMessage */
/* Size: 0xA0 */
typedef struct __attribute__((packed)) ccNarutoRootObjManagerSearchMessage {
    void* vtable; /* 0x0 [high] vtable pointer */
    uint32_t typeTag; /* 0x8 [high] 0x2711 type tag */
    uint32_t field_0C; /* 0xC [medium] set in ctor */
    uint64_t field_10; /* 0x10 [medium] ctor writes */
    uint64_t field_18; /* 0x18 [medium] ctor writes */
    uint64_t field_20; /* 0x20 [medium] ctor writes */
    uint64_t field_28; /* 0x28 [medium] ctor writes */
    uint64_t field_30; /* 0x30 [medium] ctor writes */
    uint64_t field_38; /* 0x38 [medium] ctor writes */
    uint64_t field_40; /* 0x40 [medium] ctor writes */
    uint64_t field_48; /* 0x48 [medium] ctor writes */
    uint64_t field_50; /* 0x50 [medium] ctor writes */
    uint64_t field_58; /* 0x58 [medium] ctor writes */
    uint64_t field_60; /* 0x60 [medium] ctor writes */
    uint64_t field_68; /* 0x68 [medium] ctor writes */
    uint64_t field_70; /* 0x70 [medium] ctor writes */
    uint64_t field_78; /* 0x78 [medium] ctor writes */
    uint64_t field_80; /* 0x80 [medium] ctor writes */
    uint64_t field_88; /* 0x88 [medium] ctor writes */
    uint64_t field_90; /* 0x90 [medium] ctor writes */
    uint64_t field_98; /* 0x98 [medium] last field accessed in ctor (param_1[0x13]) */
} ccNarutoRootObjManagerSearchMessage;

static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, typeTag) == 0x8, "ccNarutoRootObjManagerSearchMessage::typeTag offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_0C) == 0xC, "ccNarutoRootObjManagerSearchMessage::field_0C offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_10) == 0x10, "ccNarutoRootObjManagerSearchMessage::field_10 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_18) == 0x18, "ccNarutoRootObjManagerSearchMessage::field_18 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_20) == 0x20, "ccNarutoRootObjManagerSearchMessage::field_20 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_28) == 0x28, "ccNarutoRootObjManagerSearchMessage::field_28 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_30) == 0x30, "ccNarutoRootObjManagerSearchMessage::field_30 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_38) == 0x38, "ccNarutoRootObjManagerSearchMessage::field_38 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_40) == 0x40, "ccNarutoRootObjManagerSearchMessage::field_40 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_48) == 0x48, "ccNarutoRootObjManagerSearchMessage::field_48 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_50) == 0x50, "ccNarutoRootObjManagerSearchMessage::field_50 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_58) == 0x58, "ccNarutoRootObjManagerSearchMessage::field_58 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_60) == 0x60, "ccNarutoRootObjManagerSearchMessage::field_60 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_68) == 0x68, "ccNarutoRootObjManagerSearchMessage::field_68 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_70) == 0x70, "ccNarutoRootObjManagerSearchMessage::field_70 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_78) == 0x78, "ccNarutoRootObjManagerSearchMessage::field_78 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_80) == 0x80, "ccNarutoRootObjManagerSearchMessage::field_80 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_88) == 0x88, "ccNarutoRootObjManagerSearchMessage::field_88 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_90) == 0x90, "ccNarutoRootObjManagerSearchMessage::field_90 offset mismatch");
static_assert(offsetof(ccNarutoRootObjManagerSearchMessage, field_98) == 0x98, "ccNarutoRootObjManagerSearchMessage::field_98 offset mismatch");

/* ccNarutoRootObjMessage */
/* Size: 0x90 */
typedef struct __attribute__((packed)) ccNarutoRootObjMessage {
    void* vtable; /* 0x0 [high] vtable pointer */
    uint32_t msgType; /* 0x8 [high] Reset clears to 0 */
    uint32_t msgId; /* 0xC [high] Reset clears to 0 */
    uint32_t msgParam1; /* 0x10 [high] Reset clears to 0 */
    uint32_t msgParam2; /* 0x14 [high] Reset clears to 0 */
    uint8_t subObject[64]; /* 0x18 [high] FUN_140480ba0 copies 0x40 bytes here in Reset */
    void* dataPtr; /* 0x58 [high] Reset clears to 0 */
    uint8_t pad_60[32]; /* 0x60 [low] gap (dtor destroys sub-obj at +0xc=0x60) */
    uint32_t flags; /* 0x80 [high] Reset clears to 0 */
    uint8_t pad_84[12]; /* 0x84 [low] padding to 0x90 */
} ccNarutoRootObjMessage;

static_assert(offsetof(ccNarutoRootObjMessage, msgType) == 0x8, "ccNarutoRootObjMessage::msgType offset mismatch");
static_assert(offsetof(ccNarutoRootObjMessage, msgId) == 0xC, "ccNarutoRootObjMessage::msgId offset mismatch");
static_assert(offsetof(ccNarutoRootObjMessage, msgParam1) == 0x10, "ccNarutoRootObjMessage::msgParam1 offset mismatch");
static_assert(offsetof(ccNarutoRootObjMessage, msgParam2) == 0x14, "ccNarutoRootObjMessage::msgParam2 offset mismatch");
static_assert(offsetof(ccNarutoRootObjMessage, subObject) == 0x18, "ccNarutoRootObjMessage::subObject offset mismatch");
static_assert(offsetof(ccNarutoRootObjMessage, dataPtr) == 0x58, "ccNarutoRootObjMessage::dataPtr offset mismatch");
static_assert(offsetof(ccNarutoRootObjMessage, flags) == 0x80, "ccNarutoRootObjMessage::flags offset mismatch");

#endif /* ST1C02_H */
