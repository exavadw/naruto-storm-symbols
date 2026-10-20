/* cmn16.h — ccUiSelect, ccUiSelectWindow, ccUiSplitParts for s1 (NSUNS1.exe)
 * INFERRED from static decompilation of NSUNS1.exe (build s1, sha 10231093af9c).
 * All offsets derived from PC x64 code; names from s1 strings/symbols only.
 * Sizes proven from allocator calls in game code.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for opaque embedded types */
typedef struct ccUiObjectHelper ccUiObjectHelper; /* size unknown, used as embedded subobject */

/* ========================================================================
 * ccUiSelect — base selection logic class
 * Size: unknown standalone allocation in s1 (only instantiated via ccUiSelectList).
 *       Last proven field at offset 0x4c; size >= 0x50.
 * Vtable: PTR_FUN_140748578 (set in ctor 0x573760)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccUiSelect {
    /* 0x00 */ void *vtable;              /* vtable ptr, set to PTR_FUN_140748578 */
    /* 0x08 */ uint8_t _pad_08[0x10];     /* inherited ccUiObjectHelper subobject bytes */
    /* 0x18 */ int32_t selectNo;          /* current selection index (SetSelectNo, SelectCtrl) */
    /* 0x1C */ int32_t selectMax;         /* max selectable items (SetSelectMax, SelectCtrl) */
    /* 0x20 */ int32_t cursorPos;         /* cursor/display position (SetSelectNo, SelectCtrl) */
    /* 0x24 */ int32_t dispNum;           /* display count / scroll window (SetDispNum, ctor=-1) */
    /* 0x28 */ uint8_t _pad_28[4];        /* padding */
    /* 0x2C */ int32_t enabled;           /* enable flag (Ctrl checks !=0, ctor=1) */
    /* 0x30 */ int32_t loopMode;          /* loop/wrap mode flag (SelectCtrl checks !=0) */
    /* 0x34 */ uint8_t _pad_34[4];        /* padding */
    /* 0x38 */ void *padObj;              /* pad/input object pointer (Ctrl dereferences +0x20,+0x28,+0x30) */
    /* 0x40 */ int32_t padCreated;        /* pad creation flag (Ctrl checks !=0) */
    /* 0x44 */ int32_t inputMode;         /* input direction mode (SelectCtrl: 1-5 maps to button combos) */
    /* 0x48 */ uint8_t _pad_48[4];        /* padding */
    /* 0x4C */ int32_t repeatRate;        /* input repeat rate (ctor=4, passed to FUN_140574110) */
} ccUiSelect;
#pragma pack(pop)

static_assert(offsetof(ccUiSelect, vtable)     == 0x00, "ccUiSelect::vtable");
static_assert(offsetof(ccUiSelect, selectNo)   == 0x18, "ccUiSelect::selectNo");
static_assert(offsetof(ccUiSelect, selectMax)  == 0x1C, "ccUiSelect::selectMax");
static_assert(offsetof(ccUiSelect, cursorPos)  == 0x20, "ccUiSelect::cursorPos");
static_assert(offsetof(ccUiSelect, dispNum)    == 0x24, "ccUiSelect::dispNum");
static_assert(offsetof(ccUiSelect, enabled)    == 0x2C, "ccUiSelect::enabled");
static_assert(offsetof(ccUiSelect, loopMode)   == 0x30, "ccUiSelect::loopMode");
static_assert(offsetof(ccUiSelect, padObj)     == 0x38, "ccUiSelect::padObj");
static_assert(offsetof(ccUiSelect, padCreated) == 0x40, "ccUiSelect::padCreated");
static_assert(offsetof(ccUiSelect, inputMode)  == 0x44, "ccUiSelect::inputMode");
static_assert(offsetof(ccUiSelect, repeatRate) == 0x4C, "ccUiSelect::repeatRate");

/* ========================================================================
 * ccUiSelectWindow — windowed selection UI with title, scrollbar, keyhelp
 * Size: 0x240 (proven by FUN_14047ed10(0x240,...) at 0x553680)
 * Vtable: PTR_FUN_1407487b0 (set in ctor 0x576B60)
 * Inherits from a base class (FUN_140589a70 called first in ctor)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccUiSelectWindow {
    /* 0x000 */ void *vtable;             /* vtable ptr, set to PTR_FUN_1407487b0 */
    /* 0x008 */ uint8_t _base[0xF8];      /* inherited base class subobject (FUN_140589a70 init) */
    /* 0x100 */ int32_t windowState;      /* window open/close state (state_surface rw) */
    /* 0x104 */ uint8_t _pad_104[0xEC];   /* gap to next proven field */
    /* 0x1F0 */ void *selectList;         /* ccUiSelectList* (_Initialize stores here, CreateKeyHelp reads) */
    /* 0x1F8 */ void *keyHelp;            /* ccUiKeyHelp* (CreateKeyHelp writes, ctor zeroes) */
    /* 0x200 */ uint8_t titleStr[0x3C];   /* title string buffer (FUN_1401551e0 copies into +0x200) */
    /* 0x23C */ int32_t yesNoMode;        /* yes/no selection mode (ctor sets =1) */
} ccUiSelectWindow;
#pragma pack(pop)

static_assert(sizeof(ccUiSelectWindow) <= 0x240, "ccUiSelectWindow fits in 0x240");
static_assert(offsetof(ccUiSelectWindow, vtable)      == 0x000, "ccUiSelectWindow::vtable");
static_assert(offsetof(ccUiSelectWindow, windowState)  == 0x100, "ccUiSelectWindow::windowState");
static_assert(offsetof(ccUiSelectWindow, selectList)   == 0x1F0, "ccUiSelectWindow::selectList");
static_assert(offsetof(ccUiSelectWindow, keyHelp)      == 0x1F8, "ccUiSelectWindow::keyHelp");
static_assert(offsetof(ccUiSelectWindow, titleStr)     == 0x200, "ccUiSelectWindow::titleStr");
static_assert(offsetof(ccUiSelectWindow, yesNoMode)    == 0x23C, "ccUiSelectWindow::yesNoMode");

/* ========================================================================
 * ccUiSplitParts — 9-slice / split-parts UI element (head/center/tail)
 * Size: 0x128 (proven by FUN_14047ed10(0x128,"source\\ui\\ccUiSelectList.cpp",0x89))
 * Vtable: PTR_FUN_1407497a8 (set in ctor 0x588FF0)
 * Contains three embedded subobjects at +0x58 (head), +0x98 (center), +0xD8 (tail)
 * ======================================================================== */
#pragma pack(push, 1)
typedef struct ccUiSplitParts {
    /* 0x000 */ void *vtable;             /* vtable ptr, set to PTR_FUN_1407497a8 */
    /* 0x008 */ int32_t orientFlag;       /* orientation flag (ctor undefined8*+1=byte 8; SetLength checks 0/1) */
    /* 0x00C */ int32_t partType;         /* part type selector (ctor byte 0xC; SetLength branches 0/1/2) */
    /* 0x010 */ int32_t headModelIdx;     /* head model index (ctor loop iter 0 at param_1+2 = byte 0x10) */
    /* 0x014 */ float unitScale;          /* unit scale / divisor (SetLength reads *(float*)(param_1+0x14)) */
    /* 0x018 */ int32_t tailModelIdx;     /* tail model index (ctor loop iter 2 at byte 0x18) */
    /* 0x01C */ uint8_t _pad_01C[4];      /* gap between ctor loop fields and xfbinPath */
    /* 0x020 */ uint8_t xfbinPath[0x38];  /* xfbin asset path (ctor FUN_1401551e0 at param_1+4=byte 0x20; SetLength passes +0x20) */
    /* 0x058 */ uint8_t headPart[0x40];   /* head segment render state (SetLength FUN_140480ba0 at +0x58) */
    /* 0x098 */ uint8_t centerPart[0x40]; /* center segment render state (SetLength FUN_140480ba0 at +0x98) */
    /* 0x0D8 */ uint8_t tailPart[0x40];   /* tail segment render state (SetLength FUN_140480ba0 at +0xd8) */
    /* 0x118 */ int32_t headInitFlag;     /* head segment initialized flag (SetLength sets =1) */
    /* 0x11C */ int32_t centerInitFlag;   /* center segment initialized flag (SetLength sets =1) */
    /* 0x120 */ int32_t tailInitFlag;     /* tail segment initialized flag (SetLength sets =1) */
    /* 0x124 */ uint8_t _pad_124[4];      /* trailing padding to reach 0x128 */
} ccUiSplitParts;
#pragma pack(pop)

static_assert(sizeof(ccUiSplitParts) == 0x128, "ccUiSplitParts size == 0x128");
static_assert(offsetof(ccUiSplitParts, vtable)        == 0x000, "ccUiSplitParts::vtable");
static_assert(offsetof(ccUiSplitParts, orientFlag)    == 0x008, "ccUiSplitParts::orientFlag");
static_assert(offsetof(ccUiSplitParts, partType)      == 0x00C, "ccUiSplitParts::partType");
static_assert(offsetof(ccUiSplitParts, headModelIdx)  == 0x010, "ccUiSplitParts::headModelIdx");
static_assert(offsetof(ccUiSplitParts, unitScale)     == 0x014, "ccUiSplitParts::unitScale");
static_assert(offsetof(ccUiSplitParts, tailModelIdx)  == 0x018, "ccUiSplitParts::tailModelIdx");
static_assert(offsetof(ccUiSplitParts, xfbinPath)     == 0x020, "ccUiSplitParts::xfbinPath");
static_assert(offsetof(ccUiSplitParts, headPart)      == 0x058, "ccUiSplitParts::headPart");
static_assert(offsetof(ccUiSplitParts, centerPart)    == 0x098, "ccUiSplitParts::centerPart");
static_assert(offsetof(ccUiSplitParts, tailPart)      == 0x0D8, "ccUiSplitParts::tailPart");
static_assert(offsetof(ccUiSplitParts, headInitFlag)  == 0x118, "ccUiSplitParts::headInitFlag");
static_assert(offsetof(ccUiSplitParts, centerInitFlag)== 0x11C, "ccUiSplitParts::centerInitFlag");
static_assert(offsetof(ccUiSplitParts, tailInitFlag)  == 0x120, "ccUiSplitParts::tailInitFlag");