/* cmn09.h — ccUiAnm, ccUiAnmCtrlCallbackManager for NARUTO STORM 4 PC 1.09 (s4, NSUNS4_release.exe)
 * INFERRED from static analysis. Not CONFIRMED by runtime trace.
 * Build: s4 (75912b / 147e52a3e0d7), image base 0x140000000
 * All offsets from x64 PC decompile; names from s4 symbols/strings only.
 */
#ifndef CMN09_H
#define CMN09_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose layout is not proven here. */
typedef void (*ccUiAnm_vtable_ptr)(void);

/* ccUiAnm — UI animation controller
 * Size: TWO allocations observed in Initialize (0xace720):
 *   - param_4==0: operator_new(0xb8) -> timeline sub-object at +0x98 offset within alloc
 *   - param_4!=0: operator_new(0x1e0) -> extended timeline sub-object at +0x1c0 offset within alloc
 * The ccUiAnm object itself has fields up to +0x1A0 (callback_mgr_ptr).
 * Size proven >= 0x1A8 by field access at +0x1A0 (8-byte ptr) and dirty_flag at +0x19C.
 * Vtable: set via vfunc dispatch at *(code**)(*param_1 + 0x10) in multiple methods.
 * Note: s4 differs from s3 — Initialize uses conditional allocation (0xb8 vs 0x1e0)
 *   for timeline sub-objects, but the ccUiAnm wrapper struct layout is consistent.
 */
typedef struct __attribute__((packed)) ccUiAnm {
    /* +0x00 */ ccUiAnm_vtable_ptr vtable;          /* vtable ptr, vfunc dispatch at +0x08,+0x10,+0x28 */
    /* +0x08 */ uint8_t _pad_08[0x10];              /* +0x08..+0x17: base class fields (ccUiObject inherited) */
    /* +0x18 */ uint8_t std_string_region[0x20];    /* +0x18..+0x37: std::basic_string (SetAnm/Initialize write via __grow_by_and_replace(param_1+3,...)) */
    /* +0x38 */ uint8_t _pad_38[0x48];              /* +0x38..+0x7F: gap / inherited fields */
    /* +0x80 */ uint64_t field_80;                  /* r, low conf, vfunc dispatch site (**(code**)(*param_1+0x10)) */
    /* +0x88 */ uint64_t nuccChunkAnm_ptr;          /* rw, high conf, Initialize/SetAnm load/store chunk anm via ccGetUiObjectChunk */
    /* +0x90 */ uint32_t init_flag_90;              /* rw, high conf, Initialize sets =1; SetAnm checks !=0 before DecReference */
    /* +0x94 */ uint8_t _pad_94[4];                 /* gap +0x94..+0x97 */
    /* +0x98 */ uint64_t chunk_data_ptr_98;         /* rw, medium conf, SetAnm writes via ccGetUiObjectChunk(param_1+0x98,...); SetAttachDummy reads param_1[0x1d] */
    /* +0xA0 */ uint8_t _pad_A0[0x20];              /* gap +0xA0..+0xBF */
    /* +0xC0 */ uint64_t play_ctrl_C0;              /* rw, medium conf, CtrlInternal checks ==0; SetAnm sets =0 */
    /* +0xC8 */ uint32_t field_C8;                  /* w, medium conf, ctor/init region */
    /* +0xCC */ uint32_t auto_disable_CC;           /* r, medium conf, CtrlInternal checks !=0 with play_state==1 for SetEnable(0) */
    /* +0xD0 */ uint32_t play_state_D0;             /* rw, high conf, RequestPlay sets=0; CtrlInternal checks ==0, sets=1 on IsEnd */
    /* +0xD4 */ uint32_t stop_timeline_D4;          /* rw, medium conf, CtrlInternal reads as timeline comparison value */
    /* +0xD8 */ uint8_t _pad_D8[8];                 /* gap +0xD8..+0xDF */
    /* +0xE0 */ uint64_t timeline_obj_ptr;          /* rw, high conf, Initialize/RequestPlay/CtrlInternal/_CalcWorldMatrixAll dereference */
    /* +0xE8 */ uint64_t attach_dummy_ptr_E8;       /* rw, medium conf, CtrlInternal reads; SetAttachDummy stores */
    /* +0xF0 */ uint8_t _pad_F0[8];                 /* gap +0xF0..+0xF7 */
    /* +0xF8 */ uint8_t matrix_subobj_F8[0x40];     /* +0xF8..+0x137: Nucc::Matrix44_MathGeo (_CalcWorldMatrixAll/SetOffsetPos/InterfaceSetScale operate on) */
    /* +0x138 */ uint8_t transform_subobj_138[0x40]; /* +0x138..+0x177: Nucc::Matrix44_MathGeo (_CalcWorldMatrixAll copies/multiplies into) */
    /* +0x178 */ uint32_t flags_178;                /* rw, medium conf, SetOffsetPos ORs bit0 (non-zero offset flag) */
    /* +0x17C */ uint32_t offset_pos_x;             /* rw, high conf, SetOffsetPos float compare/write; _CalcWorldMatrixAll reads for SetTranslatePart */
    /* +0x180 */ uint32_t offset_pos_y;             /* rw, high conf, SetOffsetPos float compare/write */
    /* +0x184 */ uint32_t offset_pos_z;             /* rw, high conf, SetOffsetPos float compare/write */
    /* +0x188 */ uint8_t _pad_188[8];               /* gap +0x188..+0x18F */
    /* +0x190 */ uint32_t field_190;                /* w, low conf, adjacent to flip_flag region */
    /* +0x194 */ uint32_t flip_flag_194;            /* rw, medium conf, SetOffsetPos copies bit0 of flags_178; _CalcWorldMatrixAll checks !=0 for translate */
    /* +0x198 */ uint32_t flip_vertical_198;        /* rw, high conf, SetFlipVertical writes; _CalcWorldMatrixAll checks !=0 for Y-scale negation */
    /* +0x19C */ uint32_t dirty_flag_19C;           /* rw, high conf, set=1 by Initialize/SetAttachDummy/SetAnm/SetOffsetPos/SetFlipVertical/InterfaceSetScale/_CalcWorldMatrixAll; cleared by _CalcWorldMatrixAll */
    /* +0x1A0 */ uint64_t callback_mgr_ptr;         /* rw, high conf, SetCtrlCallback stores ptr to ccUiAnmCtrlCallbackManager; CtrlInternal checks !=0 */
    /* +0x1A8 end — size >= 0x1A8 proven by last field at +0x1A0 (8 bytes) */
} ccUiAnm;

/* Compile-time offset checks for ccUiAnm */
static_assert(offsetof(ccUiAnm, vtable) == 0x00, "ccUiAnm::vtable");
static_assert(offsetof(ccUiAnm, std_string_region) == 0x18, "ccUiAnm::std_string_region");
static_assert(offsetof(ccUiAnm, field_80) == 0x80, "ccUiAnm::field_80");
static_assert(offsetof(ccUiAnm, nuccChunkAnm_ptr) == 0x88, "ccUiAnm::nuccChunkAnm_ptr");
static_assert(offsetof(ccUiAnm, init_flag_90) == 0x90, "ccUiAnm::init_flag_90");
static_assert(offsetof(ccUiAnm, chunk_data_ptr_98) == 0x98, "ccUiAnm::chunk_data_ptr_98");
static_assert(offsetof(ccUiAnm, play_ctrl_C0) == 0xC0, "ccUiAnm::play_ctrl_C0");
static_assert(offsetof(ccUiAnm, field_C8) == 0xC8, "ccUiAnm::field_C8");
static_assert(offsetof(ccUiAnm, auto_disable_CC) == 0xCC, "ccUiAnm::auto_disable_CC");
static_assert(offsetof(ccUiAnm, play_state_D0) == 0xD0, "ccUiAnm::play_state_D0");
static_assert(offsetof(ccUiAnm, stop_timeline_D4) == 0xD4, "ccUiAnm::stop_timeline_D4");
static_assert(offsetof(ccUiAnm, timeline_obj_ptr) == 0xE0, "ccUiAnm::timeline_obj_ptr");
static_assert(offsetof(ccUiAnm, attach_dummy_ptr_E8) == 0xE8, "ccUiAnm::attach_dummy_ptr_E8");
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
/* No sizeof assert: exact total size not proven by single allocator call for the wrapper.
 * Fields proven up to +0x1A0 (8 bytes) => size >= 0x1A8. */

/* ccUiAnmCtrlCallbackManager — callback manager for UI animation control
 * Size: 0xC0 (192 bytes), proven by operator_new(0xc0,...) at:
 *   - ccUiAnm::SetCtrlCallback (0xacee90, source line 0x28b)
 * Vtable: PTR_FUN_1411198e0 (set in ctor at +0x0)
 * Secondary vtable: PTR_FUN_1411198c8 (set at +0x08)
 */
typedef struct __attribute__((packed)) ccUiAnmCtrlCallbackManager {
    /* +0x00 */ ccUiAnm_vtable_ptr vtable;          /* PTR_FUN_1411198e0 */
    /* +0x08 */ ccUiAnm_vtable_ptr secondary_vtbl;  /* PTR_FUN_1411198c8, BlockAllocator vtable */
    /* +0x10 */ uint8_t blockalloc_subobj_10[0x10]; /* +0x10..+0x1F: BlockAllocator sub-object (ctor calls BlockAllocator()) */
    /* +0x20 */ uint32_t field_20;                  /* w, low conf, ctor *(u32*)(param_1+4)=0 -> +0x20 */
    /* +0x24 */ uint8_t _pad_24[4];                 /* gap +0x24..+0x27 */
    /* +0x28 */ uint64_t pool_base_28;             /* rw, medium conf, Ctrl checks bounds against this; Add region */
    /* +0x30 */ uint64_t pool_array_ptr_30;         /* rw, medium conf, Ctrl writes pool_array_ptr + index*8 */
    /* +0x38 */ uint32_t pool_index_38;            /* rw, medium conf, Ctrl increments; used as array index */
    /* +0x3C */ uint8_t _pad_3C[4];                 /* gap +0x3C..+0x3F */
    /* +0x40 */ uint64_t field_40;                  /* w, low conf, ctor param_1[8]=0 -> +0x40 */
    /* +0x48 */ uint8_t critsect_subobj_48[0x28];   /* +0x48..+0x6F: nuccCriticalSection (ctor calls nuccCriticalSection + Create) */
    /* +0x70 */ uint8_t _pad_70[0x28];              /* +0x70..+0x97: gap / sub-object tail */
    /* +0x98 */ uint64_t list_head_98;             /* rw, high conf, Ctrl iterates **(longlong**)(param_1+0x98); Add reads/writes */
    /* +0xA0 */ uint64_t list_size_A0;             /* rw, high conf, Add increments; Ctrl decrements; checked against 0xaaaaaaaaaaaaaa9 */
    /* +0xA8 */ uint8_t owner_handle_A8[0x18];     /* +0xA8..+0xBF: GameActor::Component::GetOwnerHandle region (Ctrl calls PushBlock with) */
    /* +0xC0 end — size proven by operator_new(0xc0) */
} ccUiAnmCtrlCallbackManager;

/* Compile-time offset checks for ccUiAnmCtrlCallbackManager */
static_assert(offsetof(ccUiAnmCtrlCallbackManager, vtable) == 0x00, "ccUiAnmCtrlCallbackManager::vtable");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, secondary_vtbl) == 0x08, "ccUiAnmCtrlCallbackManager::secondary_vtbl");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, blockalloc_subobj_10) == 0x10, "ccUiAnmCtrlCallbackManager::blockalloc_subobj_10");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_20) == 0x20, "ccUiAnmCtrlCallbackManager::field_20");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, pool_base_28) == 0x28, "ccUiAnmCtrlCallbackManager::pool_base_28");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, pool_array_ptr_30) == 0x30, "ccUiAnmCtrlCallbackManager::pool_array_ptr_30");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, pool_index_38) == 0x38, "ccUiAnmCtrlCallbackManager::pool_index_38");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, field_40) == 0x40, "ccUiAnmCtrlCallbackManager::field_40");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, critsect_subobj_48) == 0x48, "ccUiAnmCtrlCallbackManager::critsect_subobj_48");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, list_head_98) == 0x98, "ccUiAnmCtrlCallbackManager::list_head_98");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, list_size_A0) == 0xA0, "ccUiAnmCtrlCallbackManager::list_size_A0");
static_assert(offsetof(ccUiAnmCtrlCallbackManager, owner_handle_A8) == 0xA8, "ccUiAnmCtrlCallbackManager::owner_handle_A8");
static_assert(sizeof(ccUiAnmCtrlCallbackManager) == 0xC0, "ccUiAnmCtrlCallbackManager size == 0xC0");

#endif /* CMN09_H */