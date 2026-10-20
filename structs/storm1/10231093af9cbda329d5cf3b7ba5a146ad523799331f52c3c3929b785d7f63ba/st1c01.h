/* st1c01.h — Story cutscene/event struct layouts for NARUTO STORM 1 (s1)
 * Build: s1 (NSUNS1.exe, sha 10231093af9c)
 * All fields INFERRED from static analysis (state_surface + decompilation).
 * No sizeof asserts where size is unproven; embedded unknown-size arrays use uint8_t[n].
 */
#ifndef ST1C01_H
#define ST1C01_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * ccDispSubtitle — subtitle display manager
 * Fields from: Init (0x1DD4AC), Add (0x1DCFD8), Ctrl (0x1DD0D8), Draw (0x1DD278),
 *              Close (0x1DD098), Exit (0x1DD414)
 * Size: unknown, >= 0x274 (last field at 0x268 + 4 bytes, plus alignment)
 * Vtable: not found in analyzed methods
 * ======================================================================== */
typedef struct __attribute__((packed)) ccDispSubtitle {
    uint8_t _pad_0x00[0x28];                    /* 0x00-0x27: unknown base */
    void   *pWindowStyle;                       /* 0x28: window style object ptr (Init allocates 0x1b5) */
    void   *pFontObj;                           /* 0x30: font/render object ptr (Init allocates via FUN_14019f5b4) */
    uint8_t _pad_0x38[0x210];                   /* 0x38-0x247: linked list node area (Add traverses +0x210 next ptr) */
    void   *pCurrentEntry;                      /* 0x248: current subtitle entry (linked list head) */
    float   fadeAlpha;                          /* 0x250: fade alpha / display timer */
    uint8_t _pad_0x254[0x10];                   /* 0x254-0x263: gap */
    float   scaleX;                             /* 0x264: font scale X (Init sets 1.0f = 0x3f800000) */
    float   scaleY;                             /* 0x268: font scale Y (Init sets 1.0f = 0x3f800000) */
    int32_t displayMode;                        /* 0x26C: display mode flag (Ctrl checks != 0 at +0x270) */
    uint8_t _pad_0x270[0x4];                    /* 0x270-0x273: trailing pad */
} ccDispSubtitle;
static_assert(offsetof(ccDispSubtitle, pWindowStyle) == 0x28, "ccDispSubtitle.pWindowStyle");
static_assert(offsetof(ccDispSubtitle, pFontObj) == 0x30, "ccDispSubtitle.pFontObj");
static_assert(offsetof(ccDispSubtitle, pCurrentEntry) == 0x248, "ccDispSubtitle.pCurrentEntry");
static_assert(offsetof(ccDispSubtitle, fadeAlpha) == 0x250, "ccDispSubtitle.fadeAlpha");
static_assert(offsetof(ccDispSubtitle, scaleX) == 0x264, "ccDispSubtitle.scaleX");
static_assert(offsetof(ccDispSubtitle, scaleY) == 0x268, "ccDispSubtitle.scaleY");
static_assert(offsetof(ccDispSubtitle, displayMode) == 0x26C, "ccDispSubtitle.displayMode");

/* ========================================================================
 * ccGameJudgeEvent — event judge condition tracker
 * Fields from: Reset (0x232D60), SetSuccess (0x232EC0), SetBonusSuccess (0x232D8C),
 *              SetBonusViolation (0x232D94), GetConditionId (0x231FE8)
 * Size: unknown, >= 0x34 (arrays at +0xC, +0x1C, +0x24 indexed by param_2)
 * Vtable: pointer at offset 0x0 (GetConditionId dereferences *param_1)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccGameJudgeEvent {
    void   *vtable;                             /* 0x00: vtable pointer */
    int32_t conditionType;                      /* 0x08: condition type (Reset clears, GetConditionId checks ==1 or ==2) */
    int32_t successValues[4];                   /* 0x0C: success condition values (SetSuccess writes param_2*4+0xC) */
    int32_t bonusSuccessValues[2];              /* 0x1C: bonus success values (SetBonusSuccess writes param_2*4+0x1C) */
    int32_t bonusViolationValues[2];            /* 0x24: bonus violation values (SetBonusViolation writes param_2*4+0x24) */
    int32_t extraField;                         /* 0x2C: cleared by Reset loop */
    int32_t extraField2;                        /* 0x30: cleared by Reset loop */
} ccGameJudgeEvent;
static_assert(offsetof(ccGameJudgeEvent, vtable) == 0x00, "ccGameJudgeEvent.vtable");
static_assert(offsetof(ccGameJudgeEvent, conditionType) == 0x08, "ccGameJudgeEvent.conditionType");
static_assert(offsetof(ccGameJudgeEvent, successValues) == 0x0C, "ccGameJudgeEvent.successValues");
static_assert(offsetof(ccGameJudgeEvent, bonusSuccessValues) == 0x1C, "ccGameJudgeEvent.bonusSuccessValues");
static_assert(offsetof(ccGameJudgeEvent, bonusViolationValues) == 0x24, "ccGameJudgeEvent.bonusViolationValues");
static_assert(offsetof(ccGameJudgeEvent, extraField) == 0x2C, "ccGameJudgeEvent.extraField");
static_assert(offsetof(ccGameJudgeEvent, extraField2) == 0x30, "ccGameJudgeEvent.extraField2");

/* ========================================================================
 * ccEventSeekParam — seek arrow parameter container
 * Fields from: SetArrowParam (0x17FC28), GetArrowType (0x16E6C8)
 * Size: unknown, >= 0x38 (linked list at +0x30 with +0x10 next ptr)
 * Vtable: not found
 * Note: GetArrowType reads param_1[param_2 * 0xC] suggesting an array of 12-byte entries at base
 * ======================================================================== */
typedef struct __attribute__((packed)) ccEventSeekParam {
    uint8_t _pad_0x00[0x30];                    /* 0x00-0x2F: unknown base (may contain arrow type array) */
    void   *pArrowListHead;                     /* 0x30: linked list head (SetArrowParam traverses +0x10 next) */
    uint8_t _pad_0x38[0x8];                     /* 0x38-0x3F: trailing */
} ccEventSeekParam;
static_assert(offsetof(ccEventSeekParam, pArrowListHead) == 0x30, "ccEventSeekParam.pArrowListHead");

/* ========================================================================
 * ccAnmStrmTimeObjSetupXML — XML-based animation stream time object setup
 * Fields from: OnCtrl (0x420010), ~ccAnmStrmTimeObjSetupXML (0x414FB0)
 * Size: unknown, >= 0x18 (field at +0x10, vtable at +0x0)
 * Vtable: PTR_FUN_140729fc0 (set in dtor)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccAnmStrmTimeObjSetupXML {
    void   *vtable;                             /* 0x00: vtable (PTR_FUN_140729fc0) */
    uint8_t _pad_0x08[0x8];                     /* 0x08-0x0F: gap */
    int32_t initialized;                        /* 0x10: init flag (OnCtrl checks ==0, sets to 1) */
    uint8_t _pad_0x14[0x4];                     /* 0x14-0x17: trailing pad */
} ccAnmStrmTimeObjSetupXML;
static_assert(offsetof(ccAnmStrmTimeObjSetupXML, vtable) == 0x00, "ccAnmStrmTimeObjSetupXML.vtable");
static_assert(offsetof(ccAnmStrmTimeObjSetupXML, initialized) == 0x10, "ccAnmStrmTimeObjSetupXML.initialized");

/* ========================================================================
 * ccEventManager — story event manager (largest class in group)
 * Fields from state_surface (34 seeds, 22 fields detected)
 * Size: unknown, >= 0x568 (last proven field region at +0x528, sub-object at +0x568)
 * Vtable: at +0x4B8 (ctor writes PTR_FUN_140773790)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccEventManager {
    uint8_t _pad_0x00[0x110];                   /* 0x00-0x10F: unknown base */
    uint8_t subObj_0x110[0x58];                 /* 0x110: sub-object passed to FUN_14017f88c (size inferred from next field) */
    uint8_t subObj_0x168[0x58];                 /* 0x168: sub-object passed to FUN_14018239c */
    int32_t cmnCount;                           /* 0x1C0: common count (ctor writes 0) */
    int32_t crossFadeState;                     /* 0x1C4: cross-fade state (rw, ctor/dtor access) */
    void   *pDataPtr;                           /* 0x1C8: data pointer (read 12 times in ctor/dtor) */
    int64_t field_0x1D0;                        /* 0x1D0: written in ctor/dtor (kind=w) */
    int32_t loadState;                          /* 0x1D8: load state flag (dtor checks ==1) */
    uint8_t _pad_0x1DC[0x4];                    /* 0x1DC-0x1DF: alignment gap */
    int64_t field_0x1E0;                        /* 0x1E0: ctor writes 0 */
    int64_t field_0x1E8;                        /* 0x1E8: ctor writes 0 */
    uint8_t _pad_0x1F0[0x64];                   /* 0x1F0-0x253: gap to tmpFlags */
    uint8_t tmpFlags[0x200];                    /* 0x254: tmp flag array (memset 0x200 bytes in ctor) */
    uint8_t _pad_0x454[0x4];                    /* 0x454-0x457: alignment gap */
    void   *pSubObj_0x458;                      /* 0x458: sub-object ptr (rw in ctor/dtor) */
    uint8_t subObj_0x460[0x30];                 /* 0x460: sub-object passed to FUN_140105e80 */
    uint8_t subObj_0x490[0x20];                 /* 0x490: sub-object passed to FUN_140105e80 */
    int32_t field_0x4B0;                        /* 0x4B0: ctor writes 0 */
    uint8_t _pad_0x4B4[0x4];                    /* 0x4B4-0x4B7: alignment gap before vtable */
    void   *vtablePtr;                          /* 0x4B8: vtable (PTR_FUN_140773790 set in ctor) */
    uint8_t _pad_0x4C0[0x28];                   /* 0x4C0-0x4E7: gap to subObj_0x4E8 */
    uint8_t subObj_0x4E8[0xC];                  /* 0x4E8: sub-object (FUN_14047f900 in ctor) */
    uint8_t subObj_0x4F4[0xC];                  /* 0x4F4: sub-object (FUN_14047f900 in ctor) */
    uint8_t subObj_0x500[0x20];                 /* 0x500: memset 0x20 in ctor */
    int32_t rocketPoint;                        /* 0x520: rocket point (ctor writes -1) */
    int32_t seekResult;                         /* 0x524: seek result (ctor writes 0) */
    uint8_t subObj_0x528[0x40];                 /* 0x528: sub-object (FUN_140443c80 in ctor/dtor) */
    uint8_t subObj_0x568[0x8];                  /* 0x568: sub-object (FUN_14047f390 in ctor/dtor) */
} ccEventManager;
static_assert(offsetof(ccEventManager, subObj_0x110) == 0x110, "ccEventManager.subObj_0x110");
static_assert(offsetof(ccEventManager, subObj_0x168) == 0x168, "ccEventManager.subObj_0x168");
static_assert(offsetof(ccEventManager, cmnCount) == 0x1C0, "ccEventManager.cmnCount");
static_assert(offsetof(ccEventManager, crossFadeState) == 0x1C4, "ccEventManager.crossFadeState");
static_assert(offsetof(ccEventManager, pDataPtr) == 0x1C8, "ccEventManager.pDataPtr");
static_assert(offsetof(ccEventManager, field_0x1D0) == 0x1D0, "ccEventManager.field_0x1D0");
static_assert(offsetof(ccEventManager, loadState) == 0x1D8, "ccEventManager.loadState");
static_assert(offsetof(ccEventManager, field_0x1E0) == 0x1E0, "ccEventManager.field_0x1E0");
static_assert(offsetof(ccEventManager, field_0x1E8) == 0x1E8, "ccEventManager.field_0x1E8");
static_assert(offsetof(ccEventManager, tmpFlags) == 0x254, "ccEventManager.tmpFlags");
static_assert(offsetof(ccEventManager, pSubObj_0x458) == 0x458, "ccEventManager.pSubObj_0x458");
static_assert(offsetof(ccEventManager, subObj_0x460) == 0x460, "ccEventManager.subObj_0x460");
static_assert(offsetof(ccEventManager, subObj_0x490) == 0x490, "ccEventManager.subObj_0x490");
static_assert(offsetof(ccEventManager, field_0x4B0) == 0x4B0, "ccEventManager.field_0x4B0");
static_assert(offsetof(ccEventManager, vtablePtr) == 0x4B8, "ccEventManager.vtablePtr");
static_assert(offsetof(ccEventManager, subObj_0x4E8) == 0x4E8, "ccEventManager.subObj_0x4E8");
static_assert(offsetof(ccEventManager, subObj_0x4F4) == 0x4F4, "ccEventManager.subObj_0x4F4");
static_assert(offsetof(ccEventManager, subObj_0x500) == 0x500, "ccEventManager.subObj_0x500");
static_assert(offsetof(ccEventManager, rocketPoint) == 0x520, "ccEventManager.rocketPoint");
static_assert(offsetof(ccEventManager, seekResult) == 0x524, "ccEventManager.seekResult");
static_assert(offsetof(ccEventManager, subObj_0x528) == 0x528, "ccEventManager.subObj_0x528");
static_assert(offsetof(ccEventManager, subObj_0x568) == 0x568, "ccEventManager.subObj_0x568");

/* ========================================================================
 * ccAnmStrmTimeObjDodge — dodge animation stream time object
 * Fields from state_surface (6 fields)
 * Size: unknown, >= 0xA8 (last field at +0xA0, 8 bytes)
 * Vtable: not determined
 * ======================================================================== */
typedef struct __attribute__((packed)) ccAnmStrmTimeObjDodge {
    uint8_t _pad_0x00[0x58];                    /* 0x00-0x57: unknown base */
    uint8_t flag_0x58;                          /* 0x58: single byte flag */
    uint8_t _pad_0x59[0xF];                     /* 0x59-0x67: gap */
    void   *ptr_0x68;                           /* 0x68: pointer field */
    void   *ptr_0x70;                           /* 0x70: pointer field */
    uint8_t subObj_0x78[0x18];                  /* 0x78: sub-object (size unknown, extends to +0x90) */
    void   *ptr_0x90;                           /* 0x90: pointer field */
    uint8_t _pad_0x98[0x8];                     /* 0x98-0x9F: gap */
    void   *ptr_0xA0;                           /* 0xA0: pointer field */
} ccAnmStrmTimeObjDodge;
static_assert(offsetof(ccAnmStrmTimeObjDodge, flag_0x58) == 0x58, "ccAnmStrmTimeObjDodge.flag_0x58");
static_assert(offsetof(ccAnmStrmTimeObjDodge, ptr_0x68) == 0x68, "ccAnmStrmTimeObjDodge.ptr_0x68");
static_assert(offsetof(ccAnmStrmTimeObjDodge, ptr_0x70) == 0x70, "ccAnmStrmTimeObjDodge.ptr_0x70");
static_assert(offsetof(ccAnmStrmTimeObjDodge, subObj_0x78) == 0x78, "ccAnmStrmTimeObjDodge.subObj_0x78");
static_assert(offsetof(ccAnmStrmTimeObjDodge, ptr_0x90) == 0x90, "ccAnmStrmTimeObjDodge.ptr_0x90");
static_assert(offsetof(ccAnmStrmTimeObjDodge, ptr_0xA0) == 0xA0, "ccAnmStrmTimeObjDodge.ptr_0xA0");

/* ========================================================================
 * ccAnmStrmTimeObjCmnMove — common move animation stream time object
 * Fields from state_surface (12 fields, 1 seed: ctor at 0x413CD4)
 * Size: unknown, >= 0xF0 (last field at +0xEC + 4)
 * Vtable: not determined
 * Pattern: repeating 12-byte groups (8-byte ptr + 4-byte value) at 0xB0-0xEC
 * ======================================================================== */
typedef struct __attribute__((packed)) ccAnmStrmTimeObjCmnMove {
    uint8_t _pad_0x00[0x70];                    /* 0x00-0x6F: unknown base */
    uint8_t subObj_0x70[0x40];                  /* 0x70: sub-object (FUN_140480da0 in ctor) */
    void   *moveObj_0xB0;                       /* 0xB0: move object ptr (FUN_14047f900) */
    int32_t moveVal_0xB8;                       /* 0xB8: move value (copied from puVar1+1) */
    void   *moveObj_0xBC;                       /* 0xBC: move object ptr */
    int32_t moveVal_0xC4;                       /* 0xC4: move value */
    void   *moveObj_0xC8;                       /* 0xC8: move object ptr */
    int32_t moveVal_0xD0;                       /* 0xD0: move value */
    void   *moveObj_0xD4;                       /* 0xD4: move object ptr */
    int32_t moveVal_0xDC;                       /* 0xDC: move value */
    int32_t sentinel_0xE0;                      /* 0xE0: sentinel (ctor writes 0xFFFFFFFF) */
    void   *moveObj_0xE4;                       /* 0xE4: move object ptr */
    int32_t moveVal_0xEC;                       /* 0xEC: move value */
} ccAnmStrmTimeObjCmnMove;
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, subObj_0x70) == 0x70, "ccAnmStrmTimeObjCmnMove.subObj_0x70");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveObj_0xB0) == 0xB0, "ccAnmStrmTimeObjCmnMove.moveObj_0xB0");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveVal_0xB8) == 0xB8, "ccAnmStrmTimeObjCmnMove.moveVal_0xB8");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveObj_0xBC) == 0xBC, "ccAnmStrmTimeObjCmnMove.moveObj_0xBC");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveVal_0xC4) == 0xC4, "ccAnmStrmTimeObjCmnMove.moveVal_0xC4");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveObj_0xC8) == 0xC8, "ccAnmStrmTimeObjCmnMove.moveObj_0xC8");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveVal_0xD0) == 0xD0, "ccAnmStrmTimeObjCmnMove.moveVal_0xD0");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveObj_0xD4) == 0xD4, "ccAnmStrmTimeObjCmnMove.moveObj_0xD4");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveVal_0xDC) == 0xDC, "ccAnmStrmTimeObjCmnMove.moveVal_0xDC");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, sentinel_0xE0) == 0xE0, "ccAnmStrmTimeObjCmnMove.sentinel_0xE0");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveObj_0xE4) == 0xE4, "ccAnmStrmTimeObjCmnMove.moveObj_0xE4");
static_assert(offsetof(ccAnmStrmTimeObjCmnMove, moveVal_0xEC) == 0xEC, "ccAnmStrmTimeObjCmnMove.moveVal_0xEC");

/* ========================================================================
 * ccAnmStrmCmnChanger — common animation stream changer
 * Fields from state_surface (2 fields)
 * Size: unknown, >= 0x70 (fields at +0x60, +0x68)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccAnmStrmCmnChanger {
    uint8_t _pad_0x00[0x60];                    /* 0x00-0x5F: unknown base */
    void   *ptr_0x60;                           /* 0x60: pointer field */
    void   *ptr_0x68;                           /* 0x68: pointer field */
} ccAnmStrmCmnChanger;
static_assert(offsetof(ccAnmStrmCmnChanger, ptr_0x60) == 0x60, "ccAnmStrmCmnChanger.ptr_0x60");
static_assert(offsetof(ccAnmStrmCmnChanger, ptr_0x68) == 0x68, "ccAnmStrmCmnChanger.ptr_0x68");

/* ========================================================================
 * ccAnmStrmCmnChanger::Data — inner data struct for CmnChanger
 * Fields from state_surface (2 fields, same offsets as parent)
 * Size: unknown, >= 0x70
 * ======================================================================== */
typedef struct __attribute__((packed)) ccAnmStrmCmnChanger_Data {
    uint8_t _pad_0x00[0x60];                    /* 0x00-0x5F: unknown base */
    void   *ptr_0x60;                           /* 0x60: pointer field */
    void   *ptr_0x68;                           /* 0x68: pointer field */
} ccAnmStrmCmnChanger_Data;
static_assert(offsetof(ccAnmStrmCmnChanger_Data, ptr_0x60) == 0x60, "ccAnmStrmCmnChanger_Data.ptr_0x60");
static_assert(offsetof(ccAnmStrmCmnChanger_Data, ptr_0x68) == 0x68, "ccAnmStrmCmnChanger_Data.ptr_0x68");

/* ========================================================================
 * ccAnmStrmTimeObjChTex — texture change animation stream time object
 * Fields from state_surface (1 field)
 * Size: unknown, >= 0x60 (field at +0x5C)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccAnmStrmTimeObjChTex {
    uint8_t _pad_0x00[0x5C];                    /* 0x00-0x5B: unknown base */
    int32_t texId;                              /* 0x5C: texture ID or index */
} ccAnmStrmTimeObjChTex;
static_assert(offsetof(ccAnmStrmTimeObjChTex, texId) == 0x5C, "ccAnmStrmTimeObjChTex.texId");

/* ========================================================================
 * ccAnmStrmTimeObjClumpApplyAnm — clump apply animation time object
 * NO FIELDS DETECTED: state_surface returned 0 fields from 2 seeds.
 * Likely a thin wrapper or pure virtual base. Not reconstructed.
 * ======================================================================== */

/* ========================================================================
 * ccIAEventBeginHugeBattle — IA event: begin huge battle
 * STATIC DISPATCHER: only method is Ctrl (0x2DF9AC), which takes no this pointer.
 * Operates on global DAT_140842020. No instance fields.
 * ======================================================================== */

/* ========================================================================
 * ccIAEventDmg — IA event: damage
 * STATIC DISPATCHER: only method is Ctrl (0x2DF9D4), which takes no this pointer.
 * Calls vfunc at +0x5D8 on object from FUN_140384710(&DAT_140870fd0,0).
 * No instance fields.
 * ======================================================================== */

/* ========================================================================
 * ccIAEventLifeGaugeLeave — IA event: life gauge leave
 * STATIC DISPATCHER: only method is Ctrl (0x2DFA14), which takes no this pointer.
 * Sets global DAT_14082f884 = 1, calls FUN_1401d6134 and FUN_14043163c.
 * No instance fields.
 * ======================================================================== */

#endif /* ST1C01_H */