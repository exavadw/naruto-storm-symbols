/* cmn09.h — ccUiAnm, ccUiAnmCtrlCallbackManager for NARUTO STORM 3 Full Burst HD (s3, NSUNS3.exe)
 * INFERRED from static analysis. Not CONFIRMED by runtime trace.
 * Build: s3 (a7124b / 55b726e94dad), image base 0x140000000
 * All offsets from x64 PC decompile; names from s3 symbols/strings only.
 */
#ifndef CMN09_H
#define CMN09_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here. */
typedef void (*ccUiAnm_vtable_ptr)(void);

/* ccUiAnm — UI animation controller
 * Size: 0x1A8 (424 bytes), proven by FUN_140683f70(0x1a8,...) at:
 *   - FUN_14077ec20 (ccUiObjectHelper.h:0x8c)
 * Vtable: PTR_FUN_1409ed810 (set in ctor at +0x0)
 * Note: s3 ccUiAnm is SAME size as s1 (0x1A8). s2 was larger (0x1C8) due to
 *   subclass extension; s3 does not have that extension in the base alloc.
 */
typedef struct __attribute__((packed)) ccUiAnm {
    /* +0x00 */ ccUiAnm_vtable_ptr vtable;          /* vtable ptr, set in ctor */
    /* +0x08 */ uint8_t _pad_08[0x10];              /* +0x08..+0x17: base class fields (ccUiObject inherited) */
    /* +0x18 */ uint8_t std_string_region[0x20];    /* +0x18..+0x37: std::basic_string (Initialize writes via FUN_14017d4a0(param_1+3,...)) */
    /* +0x38 */ uint8_t _pad_38[0x48];              /* +0x38..+0x7F: gap / inherited fields */
    /* +0x80 */ uint64_t field_80;                  /* r, low conf, vfunc dispatch site (**(code**)(*param_1+0x10)) */
    /* +0x88 */ uint64_t nuccChunkAnm_ptr;          /* r, medium conf, Initialize loads chunk anm via ccGetUiObjectChunk */
    /* +0x90 */ uint32_t init_flag_90;              /* w, medium conf, Initialize sets =1 */
    /* +0x94 */ uint8_t _pad_94[4];                 /* gap +0x94..+0x97 */
    /* +0x98 */ uint8_t field_98;                   /* r, low conf, byte access in Initialize */
    /* +0x99 */ uint8_t _pad_99[0x27];              /* gap +0x99..+0xBF */
    /* +0xC0 */ uint64_t field_C0;                  /* w, medium conf, ctor param_1[0x18]=0 */
    /* +0xC8 */ uint32_t field_C8;                  /* w, medium conf, ctor DAT_140c7cee8 */
    /* +0xCC */ uint32_t field_CC;                  /* w, medium conf, ctor =0 */
    /* +0xD0 */ uint32_t play_state_D0;             /* rw, medium conf, RequestPlay reads/writes (0->2->0) */
    /* +0xD4 */ uint8_t _pad_D4[4];                 /* gap +0xD4..+0xD7 */
    /* +0xD8 */ uint64_t field_D8;                  /* w, medium conf, ctor param_1[0x1b]=0 */
    /* +0xE0 */ uint64_t timeline_obj_ptr;          /* rw, high conf, Initialize/RequestPlay dereferences */
    /* +0xE8 */ uint64_t field_E8;                  /* w, medium conf, ctor param_1[0x1d]=0 */
    /* +0xF0 */ uint64_t field_F0;                  /* w, medium conf, ctor param_1[0x1e]=0 */
    /* +0xF8 */ uint8_t matrix_subobj_F8[0x40];     /* +0xF8..+0x137: Nucc::Matrix44_MathGeo (ctor calls FUN_1406856b0(param_1+0x1f)) */
    /* +0x138 */ uint8_t transform_subobj_138[0x40]; /* +0x138..+0x177: Nucc::Matrix44_MathGeo (ctor calls FUN_1406856b0(param_1+0x27)) */
    /* +0x178 */ uint32_t flags_178;                /* rw, low conf, dirty/changed bitmask (SetOffsetPos ORs bit0) */
    /* +0x17C */ uint32_t offset_pos_x;             /* rw, high conf, SetOffsetPos float compare/write */
    /* +0x180 */ uint32_t offset_pos_y;             /* rw, high conf, SetOffsetPos float compare/write */
    /* +0x184 */ uint32_t offset_pos_z;             /* rw, high conf, SetOffsetPos float compare/write */
    /* +0x188 */ uint8_t _pad_188[8];               /* gap +0x188..+0x18F */
    /* +0x190 */ uint32_t field_190;                /* w, medium conf, ctor param_1[0x34]=0 -> low32 of +0x194 write */
    /* +0x194 */ uint32_t flip_flag_194;            /* rw, medium conf, SetOffsetPos copies bit0 of flags_178; _CalcWorldMatrixAll reads */
    /* +0x198 */ uint32_t flip_vertical_198;        /* rw, medium conf, SetFlipVertical writes; _CalcWorldMatrixAll reads */
    /* +0x19C */ uint32_t dirty_flag_19C;           /* rw, high conf, set=1 by Initialize/SetAttachDummy/RequestPlay/SetOffsetPos/SetMatrixAndCalc/SetFlipVertical/InterfaceSetScale; cleared by _CalcWorldMatrixAll */
    /* +0x1A0 */ uint64_t callback_mgr_ptr;         /* w, medium conf, SetCtrlCallback stores ptr to ccUiAnmCtrlCallbackManager */
    /* +0x1A8 end — size proven by allocator call 0x1a8 */
} ccUiAnm;

/* Compile-time offset checks for ccUiAnm */
static_assert(offsetof(ccUiAnm, vtable) == 0x00, "ccUiAnm::vtable");
static_assert(offsetof(ccUiAnm, std_string_region) == 0x18, "ccUiAnm::std_string_region");
static_assert(offsetof(ccUiAnm, field_80) == 0x80, "ccUiAnm::field_80");
static_assert(offsetof(ccUiAnm, nuccChunkAnm_ptr) == 0x88, "ccUiAnm::nuccChunkAnm_ptr");
static_assert(offsetof(ccUiAnm, init_flag_90) == 0x90, "ccUiAnm::init_flag_90");
static_assert(offsetof(ccUiAnm, field_98) == 0x98, "ccUiAnm::field_98");
static_assert(offsetof(ccUiAnm, field_C0) == 0xC0, "ccUiAnm::field_C0");
static_assert(offsetof(ccUiAnm, field_C8) == 0xC8, "ccUiAnm::field_C8");
static_assert(offsetof(ccUiAnm, field_CC) == 0xCC, "ccUiAnm::field_CC");
static_assert(offsetof(ccUiAnm, play_state_D0) == 0xD0, "ccUiAnm::play_state_D0");
static_assert(offsetof(ccUiAnm, field_D8) == 0xD8, "ccUiAnm::field_D8");
static_assert(offsetof(ccUiAnm, timeline_obj_ptr) == 0xE0, "ccUiAnm::timeline_obj_ptr");
static_assert(offsetof(ccUiAnm, field_E8) == 0xE8, "ccUiAnm::field_E8");
static_assert(offsetof(ccUiAnm, field_F0) == 0xF0, "ccUiAnm::field_F0");
static_assert(offsetof(ccUiAnm, matrix_subobj_F8) == 0xF8, "ccUiAnm::matrix_subobj_F8");
static_assert(offsetof(ccUiAnm, transform_subobj_138) == 0x138, "ccUiAnm::transform_subobj_138");
static_assert(offsetof(ccUiAnm, flags_178) == 0x178, "ccUiAnm::flags_178");
static_assert(offsetof(ccUiAnm, offset_pos_x) == 0x17C, "ccUiAnm::offset_pos_x");
static_assert(offsetof(ccUiAnm, offset_pos_y) == 0x180, "ccUiAnm::offset_pos_y");
static_assert(offsetof(ccUiAnm, offset_pos_z) == 0x184, "ccUiAnm::offset_pos_z");
static_assert(offsetof(ccUiAnm, field_190) == 0x190, "ccUiAnm::field_190");
static_assert(offsetof(ccUiAnm, flip_flag_194) == 0x194, "ccUiAnm::flip_flag_194");
static_assert(offsetof(ccUiAnm, flip_vertical_198) == 0x198, "ccUiAnm::flip_vertical_198");
static_assert(offsetof(ccUiAnm, dirty_flag_19C) == 0x19C, "ccUiAnm::dirty_flag_19C");
static_assert(offsetof(ccUiAnm, callback_mgr_ptr) == 0x1A0, "ccUiAnm::callback_mgr_ptr");
static_assert(sizeof(ccUiAnm) == 0x1A8, "ccUiAnm size == 0x1A8");

/* ccUiAnmCtrlCallbackManager — callback manager for UI animation control
 * Size: 0xC0 (192 bytes), proven by FUN_140683f70(0xc0,...) at:
 *   - ccUiAnm::SetCtrlCallback (source\ui\ccUiAnm.cpp:0x28b)
 * Vtable: PTR_FUN_1409f01c0 (set in ctor at +0x0)
 * Secondary vtable: PTR_FUN_1409f01a8 (set at +0x08)
 */
typedef struct __attribute__((packed)) ccUiAnmCtrlCallbackManager {
    /* +0x00 */ ccUiAnm_vtable_ptr vtable;          /* PTR_FUN_1409f01c0 */
    /* +0x08 */ ccUiAnm_vtable_ptr secondary_vtbl;  /* PTR_FUN_1409f01a8 */
    /* +0x10 */ uint8_t _pad_10[0x10];              /* +0x10..+0x1F: BlockAllocator sub-object */
    /* +0x20 */ uint32_t field_20;                  /* w, low conf, ctor *(u32*)(param_1+4)=0 -> +0x20 */
    /* +0x24 */ uint8_t _pad_24[4];                 /* gap +0x24..+0x27 */
    /* +0x28 */ uint64_t field_28;                  /* w, low conf, ctor param_1[5]=0 -> +0x28 */
    /* +0x30 */ uint64_t field_30;                  /* w, low conf, ctor param_1[6]=0 -> +0x30 */
    /* +0x38 */ uint32_t field_38;                  /* w, low conf, ctor *(u32*)(param_1+7)=0 -> +0x38 */
    /* +0x3C */ uint8_t _pad_3C[4];                 /* gap +0x3C..+0x3F */
    /* +0x40 */ uint64_t field_40;                  /* w, low conf, ctor param_1[8]=0 -> +0x40 */
    /* +0x48 */ uint8_t critsect_subobj_48[0x28];   /* +0x48..+0x6F: nuccCriticalSection (ctor calls FUN_1406bffb0(param_1+9)) */
    /* +0x70 */ uint8_t _pad_70[0x28];              /* +0x70..+0x97: gap / sub-object tail */
    /* +0x98 */ uint8_t field_98;                   /* r, low conf, byte-cast access in ctor (FUN_1407a0c30(param_1+0x13)) */
    /* +0x99 */ uint8_t _pad_99[0x27];              /* +0x99..+0xBF: tail padding to 0xC0 */
} ccUiAnmCtrlCallbackManager;

/* Compile-time offset checks for ccUiAnmCtrlCallbackManager */
static_assert(offsetof(ccUiAnmCtrlCallbackManager, vtable) == 0x00, "ccUiAnmCtrlCallbackManager::vtable");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, secondary_vtbl) == 0x08, "ccUiAnmCtrlCallbackManager::secondary_vtbl");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_20) == 0x20, "ccUiAnmCtrlCallbackManager::field_20");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_28) == 0x28, "ccUiAnmCtrlCallbackManager::field_28");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_30) == 0x30, "ccUiAnmCtrlCallbackManager::field_30");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_38) == 0x38, "ccUiAnmCtrlCallbackManager::field_38");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_40) == 0x40, "ccUiAnmCtrlCallbackManager::field_40");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, critsect_subobj_48) == 0x48, "ccUiAnmCtrlCallbackManager::critsect_subobj_48");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_98) == 0x98, "ccUiAnmCtrlCallbackManager::field_98");
static_assert(sizeof(ccUiAnmCtrlCallbackManager) == 0xC0, "ccUiAnmCtrlCallbackManager size == 0xC0");

#endif /* CMN09_H */