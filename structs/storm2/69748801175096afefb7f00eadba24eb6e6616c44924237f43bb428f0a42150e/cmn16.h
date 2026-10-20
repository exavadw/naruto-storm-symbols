/* cmn16.h — ccUiSelect, ccUiSelectWindow, ccUiSplitParts for s2 (NSUNS2.exe)
 * INFERRED from static decompilation of NSUNS2.exe (build s2, sha 697488011750).
 * All offsets derived from PC x64 code; names from s2 strings/symbols only.
 * Sizes proven from allocator/factory calls in game code.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccUiSelect — base selection logic class
 * Size: >= 0x50 (last proven field repeatRate at 0x4C; no standalone alloc found).
 * Vtable: PTR_FUN_1408a24e8 (set in ctor 0x697C40)
 * Proven offsets from ctor 0x697C40 + SelectCtrl 0x6983E0 + SetSelectNo 0x697F50:
 *   +0x18 selectNo, +0x1c selectMax, +0x20 cursorPos, +0x24 dispNum,
 *   +0x2c enabled(int64 write but logically int32+pad), +0x30 loopMode,
 *   +0x38 padObj, +0x40 padCreated(int64 write), +0x44 inputMode(int64 write),
 *   +0x4c repeatRate
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccUiSelect {
 /* 0x00 */ void *vtable;            /* PTR_FUN_1408a24e8 */
 /* 0x08 */ uint8_t _base[0x10];     /* inherited ccUiObjectHelper subobject */
 /* 0x18 */ int32_t selectNo;        /* ctor=0; SetSelectNo writes */
 /* 0x1C */ int32_t selectMax;       /* SelectCtrl reads for bounds */
 /* 0x20 */ int32_t cursorPos;       /* ctor=0; SetSelectNo writes */
 /* 0x24 */ int32_t dispNum;         /* ctor=-1; SetDispNum writes */
 /* 0x28 */ uint8_t _pad_28[4];      /* gap before enabled */
 /* 0x2C */ int32_t enabled;         /* ctor sets via int64 write at +0x2c; logically int32 */
 /* 0x30 */ int32_t loopMode;        /* SelectCtrl checks !=0 */
 /* 0x34 */ uint8_t _pad_34[4];      /* gap before padObj */
 /* 0x38 */ void *padObj;            /* CreatePad allocates; Ctrl dereferences */
 /* 0x40 */ int32_t padCreated;      /* ctor sets via int64 write at +0x40; logically int32 */
 /* 0x44 */ int32_t inputMode;       /* ctor sets via int64 write at +0x44; SelectCtrl reads */
 /* 0x48 */ uint8_t _pad_48[4];      /* gap before repeatRate */
 /* 0x4C */ int32_t repeatRate;      /* ctor=4 */
} ccUiSelect;
#pragma pack(pop)

static_assert(offsetof(ccUiSelect, vtable) == 0x00, "ccUiSelect::vtable");
static_assert(offsetof(ccUiSelect, _base) == 0x08, "ccUiSelect::_base");
static_assert(offsetof(ccUiSelect, selectNo) == 0x18, "ccUiSelect::selectNo");
static_assert(offsetof(ccUiSelect, selectMax) == 0x1C, "ccUiSelect::selectMax");
static_assert(offsetof(ccUiSelect, cursorPos) == 0x20, "ccUiSelect::cursorPos");
static_assert(offsetof(ccUiSelect, dispNum) == 0x24, "ccUiSelect::dispNum");
static_assert(offsetof(ccUiSelect, _pad_28) == 0x28, "ccUiSelect::_pad_28");
static_assert(offsetof(ccUiSelect, enabled) == 0x2C, "ccUiSelect::enabled");
static_assert(offsetof(ccUiSelect, loopMode) == 0x30, "ccUiSelect::loopMode");
static_assert(offsetof(ccUiSelect, _pad_34) == 0x34, "ccUiSelect::_pad_34");
static_assert(offsetof(ccUiSelect, padObj) == 0x38, "ccUiSelect::padObj");
static_assert(offsetof(ccUiSelect, padCreated) == 0x40, "ccUiSelect::padCreated");
static_assert(offsetof(ccUiSelect, inputMode) == 0x44, "ccUiSelect::inputMode");
static_assert(offsetof(ccUiSelect, _pad_48) == 0x48, "ccUiSelect::_pad_48");
static_assert(offsetof(ccUiSelect, repeatRate) == 0x4C, "ccUiSelect::repeatRate");

/* ========================================================================
 * ccUiSelectWindow — windowed selection UI with title, scrollbar, keyhelp
 * Size: 0x240 (proven by LoadTh(0x240,...) at factories 0x44DCCC and 0x66C320)
 * Vtable: PTR_FUN_1408a1230 (set in ctors 0x6821B0/0x682220)
 * Inherits ccUiWindow (~0xF8 byte base subobject)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccUiSelectWindow {
 /* 0x000 */ void *vtable;           /* PTR_FUN_1408a1230 */
 /* 0x008 */ uint8_t _base[0xF8];    /* inherited ccUiWindow base class */
 /* 0x100 */ int32_t windowState;    /* ctor sets =1 */
 /* 0x104 */ uint8_t _pad_104[0xEC]; /* gap to selectList */
 /* 0x1F0 */ void *selectList;       /* _Initialize stores; CreateKeyHelp reads */
 /* 0x1F8 */ void *keyHelp;          /* CreateKeyHelp writes; ctor zeroes */
 /* 0x200 */ uint8_t titleStr[0x3C]; /* BlockAllocator at +0x200 */
 /* 0x23C */ int32_t yesNoMode;      /* ctor sets =1 */
} ccUiSelectWindow;
#pragma pack(pop)

static_assert(sizeof(ccUiSelectWindow) == 0x240, "ccUiSelectWindow size == 0x240");
static_assert(offsetof(ccUiSelectWindow, vtable) == 0x000, "ccUiSelectWindow::vtable");
static_assert(offsetof(ccUiSelectWindow, _base) == 0x008, "ccUiSelectWindow::_base");
static_assert(offsetof(ccUiSelectWindow, windowState) == 0x100, "ccUiSelectWindow::windowState");
static_assert(offsetof(ccUiSelectWindow, _pad_104) == 0x104, "ccUiSelectWindow::_pad_104");
static_assert(offsetof(ccUiSelectWindow, selectList) == 0x1F0, "ccUiSelectWindow::selectList");
static_assert(offsetof(ccUiSelectWindow, keyHelp) == 0x1F8, "ccUiSelectWindow::keyHelp");
static_assert(offsetof(ccUiSelectWindow, titleStr) == 0x200, "ccUiSelectWindow::titleStr");
static_assert(offsetof(ccUiSelectWindow, yesNoMode) == 0x23C, "ccUiSelectWindow::yesNoMode");

/* ========================================================================
 * ccUiSplitParts — 9-slice / split-parts UI element (head/center/tail)
 * Size: 0x128 (proven by LoadTh(0x128,...) at factory 0x69BDD0)
 * Vtable: PTR_FUN_1408a31e0 (set in ctor 0x6A7470)
 * Three embedded Matrix44 subobjects at +0x58/+0x98/+0xD8 (each 0x40 bytes)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccUiSplitParts {
 /* 0x000 */ void *vtable;           /* PTR_FUN_1408a31e0 */
 /* 0x008 */ int32_t orientFlag;     /* ctor param_4 at +0x8 */
 /* 0x00C */ int32_t partType;       /* ctor param_5 at +0xC */
 /* 0x010 */ int32_t headModelIdx;   /* ctor loop iter 0 */
 /* 0x014 */ float unitScale;        /* SetLength reads as float */
 /* 0x018 */ int32_t tailModelIdx;   /* ctor loop iter 2 */
 /* 0x01C */ uint8_t _pad_01C[4];    /* gap before xfbinPath */
 /* 0x020 */ uint8_t xfbinPath[0x38];/* std::string at param_1+4 */
 /* 0x058 */ uint8_t headPart[0x40]; /* Matrix44 render state */
 /* 0x098 */ uint8_t centerPart[0x40]; /* Matrix44 render state */
 /* 0x0D8 */ uint8_t tailPart[0x40];   /* Matrix44 render state */
 /* 0x118 */ int32_t headInitFlag;   /* SetLength sets =1 */
 /* 0x11C */ int32_t centerInitFlag; /* SetLength sets =1 */
 /* 0x120 */ int32_t tailInitFlag;   /* SetLength sets =1 */
 /* 0x124 */ uint8_t _pad_124[4];    /* trailing pad to 0x128 */
} ccUiSplitParts;
#pragma pack(pop)

static_assert(sizeof(ccUiSplitParts) == 0x128, "ccUiSplitParts size == 0x128");
static_assert(offsetof(ccUiSplitParts, vtable) == 0x000, "ccUiSplitParts::vtable");
static_assert(offsetof(ccUiSplitParts, orientFlag) == 0x008, "ccUiSplitParts::orientFlag");
static_assert(offsetof(ccUiSplitParts, partType) == 0x00C, "ccUiSplitParts::partType");
static_assert(offsetof(ccUiSplitParts, headModelIdx) == 0x010, "ccUiSplitParts::headModelIdx");
static_assert(offsetof(ccUiSplitParts, unitScale) == 0x014, "ccUiSplitParts::unitScale");
static_assert(offsetof(ccUiSplitParts, tailModelIdx) == 0x018, "ccUiSplitParts::tailModelIdx");
static_assert(offsetof(ccUiSplitParts, _pad_01C) == 0x01C, "ccUiSplitParts::_pad_01C");
static_assert(offsetof(ccUiSplitParts, xfbinPath) == 0x020, "ccUiSplitParts::xfbinPath");
static_assert(offsetof(ccUiSplitParts, headPart) == 0x058, "ccUiSplitParts::headPart");
static_assert(offsetof(ccUiSplitParts, centerPart) == 0x098, "ccUiSplitParts::centerPart");
static_assert(offsetof(ccUiSplitParts, tailPart) == 0x0D8, "ccUiSplitParts::tailPart");
static_assert(offsetof(ccUiSplitParts, headInitFlag) == 0x118, "ccUiSplitParts::headInitFlag");
static_assert(offsetof(ccUiSplitParts, centerInitFlag) == 0x11C, "ccUiSplitParts::centerInitFlag");
static_assert(offsetof(ccUiSplitParts, tailInitFlag) == 0x120, "ccUiSplitParts::tailInitFlag");
static_assert(offsetof(ccUiSplitParts, _pad_124) == 0x124, "ccUiSplitParts::_pad_124");