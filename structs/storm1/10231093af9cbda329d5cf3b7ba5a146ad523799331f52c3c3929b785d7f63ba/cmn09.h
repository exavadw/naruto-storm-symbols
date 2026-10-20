/* cmn09.h — ccUiAnm, ccUiAnmCtrlCallbackManager for NARUTO STORM 1 (s1, NSUNS1.exe)
 * INFERRED from static analysis. Not CONFIRMED by runtime trace.
 * Build: s1 (a9fe00 / 10231093af9c), image base 0x140000000
 * All offsets from x64 PC decompile; names from s1 symbols/strings only.
 */
#ifndef CMN09_H
#define CMN09_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here. */
typedef void (*ccUiAnm_vtable_ptr)(void);

/* ccUiAnm — UI animation controller
 * Size: 0x1A8 (424 bytes), proven by FUN_14047ed10(0x1a8) at:
 *   - FUN_14056d690 (source\ui\ccUiLayout.cpp:0x68f)
 *   - FUN_140576210 (ccUiObjectHelper.h:0x8c)
 *   - FUN_1405916a0 (ccUiObjectHelper.h:0x8c)
 * Vtable: PTR_FUN_140748e78 (set in ctor at +0x0)
 * Note: surface shows accesses up to +0x1F0 but size is 0x1A8. The accesses at
 * +0x1B8..+0x1F0 come from the RequestPlay variant at 0x185650 which operates on a
 * DIFFERENT class (collection_diorama). True ccUiAnm fields end at +0x1A7.
 */
typedef struct __attribute__((packed)) ccUiAnm {
    /* +0x00 */ ccUiAnm_vtable_ptr vtable;          /* vtable ptr, set in ctor */
    /* +0x08 */ uint8_t _pad_08[0x50];              /* +0x08..+0x57: base class fields (inherited) */
    /* +0x58 */ uint64_t field_58;                  /* w, medium conf, RequestPlay sets =0 */
    /* +0x60 */ uint32_t field_60;                  /* w, medium conf, RequestPlay sets =0 */
    /* +0x64 */ uint8_t _pad_64[8];                 /* gap +0x64..+0x6B */
    /* +0x6C */ uint32_t field_6C;                  /* w, medium conf, RequestPlay sets =1 */
    /* +0x70 */ uint8_t field_70;                   /* w, medium conf, byte write =0 */
    /* +0x71 */ uint8_t _pad_71[0x0F];              /* gap +0x71..+0x7F */
    /* +0x80 */ uint64_t field_80;                  /* rw, low conf, vfunc dispatch site */
    /* +0x88 */ uint64_t field_88;                  /* rw, high conf, nuccChunkAnm load param */
    /* +0x90 */ uint32_t field_90;                  /* w, high conf, Initialize/RequestPlay =1 */
    /* +0x94 */ uint8_t _pad_94[4];                 /* gap +0x94..+0x97 */
    /* +0x98 */ uint8_t field_98;                   /* rw, low conf, byte access */
    /* +0x99 */ uint8_t _pad_99[0x0F];              /* gap +0x99..+0xA7 */
    /* +0xA8 */ uint64_t field_A8;                  /* w, medium conf, RequestPlay =0 */
    /* +0xB0 */ uint64_t field_B0;                  /* w, medium conf, RequestPlay =0xf */
    /* +0xB8 */ uint8_t _pad_B8[8];                 /* +0xB8..+0xBF: read-only ptr arithmetic site */
    /* +0xC0 */ uint64_t field_C0;                  /* w, medium conf, ctor =0 */
    /* +0xC8 */ uint32_t field_C8;                  /* w, medium conf, ctor init */
    /* +0xCC */ uint32_t field_CC;                  /* w, medium conf, ctor =0 */
    /* +0xD0 */ uint64_t field_D0;                  /* w, low conf, mixed 4/8 byte writes */
    /* +0xD8 */ uint64_t field_D8;                  /* w, medium conf, ctor =0 */
    /* +0xE0 */ uint64_t field_E0;                  /* rw, high conf, Initialize/ctor */
    /* +0xE8 */ uint64_t field_E8;                  /* w, medium conf, ctor =0 */
    /* +0xF0 */ uint64_t field_F0;                  /* w, medium conf, ctor =0 */
    /* +0xF8 */ uint8_t subobj_F8[0x40];            /* +0xF8..+0x137: matrix/embedded struct (FUN_140481c60/FUN_140480da0) */
    /* +0x138 */ uint8_t subobj_138[0x40];          /* +0x138..+0x177: transform/matrix (SetFlipVertical reads) */
    /* +0x178 */ uint32_t flags_178;                /* rw, low conf, dirty/changed bitmask */
    /* +0x17C */ uint32_t offset_pos_x;             /* w via SetOffsetPos, compared as float */
    /* +0x180 */ uint32_t offset_pos_y;             /* w via SetOffsetPos, compared as float */
    /* +0x184 */ uint32_t offset_pos_z;             /* w via SetOffsetPos, compared as float */
    /* +0x188 */ uint8_t _pad_188[8];               /* gap +0x188..+0x18F */
    /* +0x190 */ uint32_t field_190;                /* w, medium conf, RequestPlay =0 (u32 not u64) */
    /* +0x194 */ uint32_t flip_flag_194;            /* w, SetOffsetPos copies bit0 of flags_178 */
    /* +0x198 */ uint32_t flip_vertical_198;        /* w, SetFlipVertical result */
    /* +0x19C */ uint32_t dirty_flag_19C;           /* w, high conf, set=1 by many setters */
    /* +0x1A0 */ uint64_t callback_mgr_ptr;         /* w, high conf, ptr to ccUiAnmCtrlCallbackManager */
} ccUiAnm;

/* Compile-time offset checks for ccUiAnm */
static_assert(offsetof(ccUiAnm, vtable) == 0x00, "ccUiAnm::vtable");
static_assert(offsetof(ccUiAnm, field_58) == 0x58, "ccUiAnm::field_58");
static_assert(offsetof(ccUiAnm, field_60) == 0x60, "ccUiAnm::field_60");
static_assert(offsetof(ccUiAnm, field_6C) == 0x6C, "ccUiAnm::field_6C");
static_assert(offsetof(ccUiAnm, field_70) == 0x70, "ccUiAnm::field_70");
static_assert(offsetof(ccUiAnm, field_80) == 0x80, "ccUiAnm::field_80");
static_assert(offsetof(ccUiAnm, field_88) == 0x88, "ccUiAnm::field_88");
static_assert(offsetof(ccUiAnm, field_90) == 0x90, "ccUiAnm::field_90");
static_assert(offsetof(ccUiAnm, field_98) == 0x98, "ccUiAnm::field_98");
static_assert(offsetof(ccUiAnm, field_A8) == 0xA8, "ccUiAnm::field_A8");
static_assert(offsetof(ccUiAnm, field_B0) == 0xB0, "ccUiAnm::field_B0");
static_assert(offsetof(ccUiAnm, field_C0) == 0xC0, "ccUiAnm::field_C0");
static_assert(offsetof(ccUiAnm, field_C8) == 0xC8, "ccUiAnm::field_C8");
static_assert(offsetof(ccUiAnm, field_CC) == 0xCC, "ccUiAnm::field_CC");
static_assert(offsetof(ccUiAnm, field_D0) == 0xD0, "ccUiAnm::field_D0");
static_assert(offsetof(ccUiAnm, field_D8) == 0xD8, "ccUiAnm::field_D8");
static_assert(offsetof(ccUiAnm, field_E0) == 0xE0, "ccUiAnm::field_E0");
static_assert(offsetof(ccUiAnm, field_E8) == 0xE8, "ccUiAnm::field_E8");
static_assert(offsetof(ccUiAnm, field_F0) == 0xF0, "ccUiAnm::field_F0");
static_assert(offsetof(ccUiAnm, subobj_F8) == 0xF8, "ccUiAnm::subobj_F8");
static_assert(offsetof(ccUiAnm, subobj_138) == 0x138, "ccUiAnm::subobj_138");
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


/* ccUiAnmCtrlCallbackManager — manages animation control callbacks
 * Size: 0xC0 (192 bytes), proven by FUN_14047ed10(0xc0) at:
 *   - FUN_1405810A0 (source\ui\ccUiAnm.cpp:0x28b)
 * Vtable: PTR_FUN_140749ee0 (set in ctor at +0x0)
 * Secondary vtable-like ptr at +0x08: PTR_FUN_140749ec8
 * Only 1 field surfaced (+0x98, read-only, low confidence) — most of the
 * struct is opaque sub-objects initialized by FUN_14047f2e0/FUN_14047f370/FUN_140590ae0.
 */
typedef struct __attribute__((packed)) ccUiAnmCtrlCallbackManager {
    /* +0x00 */ ccUiAnm_vtable_ptr vtable;          /* PTR_FUN_140749ee0 */
    /* +0x08 */ ccUiAnm_vtable_ptr secondary_vtbl;  /* PTR_FUN_140749ec8 */
    /* +0x10 */ uint8_t _pad_10[0x08];              /* +0x10..+0x17: gap (ctor writes +0x20,+0x28,+0x30 etc as ptr-sized) */
    /* +0x18 */ uint8_t _pad_18[0x30];              /* +0x18..+0x47: sub-object (FUN_14047f2e0 init) */
    /* +0x48 */ uint8_t _pad_48[0x50];              /* +0x48..+0x97: sub-object (FUN_14047f370/FUN_140590ae0 init) */
    /* +0x98 */ uint8_t field_98;                   /* r, low conf, byte-cast access in ctor path */
    /* +0x99 */ uint8_t _pad_99[0x27];              /* +0x99..+0xBF: tail padding to 0xC0 */
} ccUiAnmCtrlCallbackManager;

/* Compile-time offset checks for ccUiAnmCtrlCallbackManager */
static_assert(offsetof(ccUiAnmCtrlCallbackManager, vtable) == 0x00, "ccUiAnmCtrlCallbackManager::vtable");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, secondary_vtbl) == 0x08, "ccUiAnmCtrlCallbackManager::secondary_vtbl");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_98) == 0x98, "ccUiAnmCtrlCallbackManager::field_98");
static_assert(sizeof(ccUiAnmCtrlCallbackManager) == 0xC0, "ccUiAnmCtrlCallbackManager size == 0xC0");

#endif /* CMN09_H */