/* st1c04.h — Story cutscene/event struct group for NSUNS1.exe (s1)
 * INFERRED from static analysis of s1 PC build (image base 0x140000000).
 * NOT CONFIRMED at runtime. Field names from Storm 1 own-game evidence only.
 * Sizes proven from allocator calls / array strides where noted.
 */
#ifndef ST1C04_H
#define ST1C04_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * nuccAnmStrmManager::StrmData  (array element, stride 0xD0)
 * Size: 0xD0 (proven by array stride in Setup/Play/AnmStrmFrame:
 *        param_2 * 0xd0 + *(longlong*)(param_1 + 0x18))
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmStrmManager_StrmData {
    /* 0x00 */ uint8_t  _pad_0x00[0x10];           /* vtable ptr or reserved */
    /* 0x10 */ int32_t  state;                     /* 0=idle, 3=playing, 4=ended; written by Play/Update */
    /* 0x14 */ uint8_t  _pad_0x14[0x174];          /* gap to 0x188 */
    /* 0x188 */ uint8_t  name_buf[0x200];          /* string buffer (AddResourceFile writes here via FUN_1402f56c0) */
    /* 0x388 */ uint8_t  _pad_0x388[0x368];        /* gap to 0x6F0 */
    /* 0x6F0 */ uint16_t cue_id;                   /* read by StrmData::Update, passed to FUN_140498480 */
    /* 0x6F2 */ uint8_t  flag_6f2;                 /* cleared on Play, checked in Update */
    /* 0x6F3 */ uint8_t  _pad_0x6F3;
    /* 0x6F4 */ uint8_t  _pad_0x6F4;
    /* 0x6F5 */ uint8_t  flag_6f5;                 /* copied from 0x6F3 in Update */
    /* 0x6F6 */ uint8_t  flags_6f6;                /* bit 2 = skip flag (checked & 4 in Play/AnmStrmFrame) */
    /* 0x6F7 */ uint8_t  _pad_0x6F7;
    /* 0x6F8 */ uint8_t  _pad_0x6F8[0x10];         /* gap to 0x708 */
    /* 0x708 */ uint64_t light_ptr;                /* pointer to light object; freed in Update */
    /* 0x710 */ uint64_t light_ptr_copy;           /* cleared alongside 0x708 */
    /* 0x718 */ uint8_t  _pad_0x718[0x8];          /* gap to 0x720 */
    /* 0x720 */ uint64_t back_ref;                 /* pointer back to parent array slot+8 */
    /* 0x728 */ int32_t  ref_count_or_flag;        /* checked > 0 in Update before light cleanup */
    /* 0x72C */ uint8_t  _pad_0x72C[0x9D4];        /* padding to 0xD0... but 0x72C > 0xD0! */
} nuccAnmStrmManager_StrmData;

/* NOTE: The StrmData inner object allocated at 0x960 bytes (Entry method)
 * contains fields up to at least 0x728. The ARRAY STRIDE of 0xD0 refers to
 * the SLOT structure in the manager's array, not the full inner object.
 * Each slot holds a pointer to the 0x960-byte inner object plus metadata.
 * Redefining: the 0xD0 stride is the manager's slot, the inner object is separate. */

/* ========================================================================
 * nuccAnmStrmManager_StrmSlot  (the 0xD0-stride array element)
 * Size: 0xD0 (proven: index * 0xd0 + base_ptr in Setup/Play/AnmStrmFrame)
 * The slot at offset 0xC8 within this array is the "active" flag byte.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmStrmManager_StrmSlot {
    /* 0x00 */ uint64_t inner_obj_ptr;             /* pointer to 0x960-byte inner stream object */
    /* 0x08 */ uint64_t slot_back_ref;             /* back-reference used at lVar3+0x720 */
    /* 0x10 */ uint8_t  _pad_0x10[0xB8];           /* gap to 0xC8 */
    /* 0xC8 */ uint8_t  active_flag;               /* -1 = inactive; decremented in Update; checked != -1 */
    /* 0xC9 */ uint8_t  _pad_0xC9[0x7];            /* pad to 0xD0 */
} nuccAnmStrmManager_StrmSlot;

static_assert(sizeof(nuccAnmStrmManager_StrmSlot) == 0xD0,
              "nuccAnmStrmManager_StrmSlot must be 0xD0 (array stride)");

/* ========================================================================
 * nuccAnmStrmManager  (main manager object)
 * Size: unknown, >= 0xE0 (last proven field access at param_1 + 0xd8)
 * Vtable: set in ctor (PTR_FUN_14072a210 seen in AddTimeObject)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmStrmManager {
    /* 0x00 */ uint64_t vtable;                    /* PTR_FUN_14072a210 (from AddTimeObject ctor) */
    /* 0x08 */ uint8_t  _pad_0x08[0x10];           /* gap */
    /* 0x18 */ uint64_t strm_slots_ptr;            /* pointer to array of StrmSlot (stride 0xD0) */
    /* 0x20 */ int32_t  slot_count;                /* max slots; bounds-checked in Setup/Play/Release */
    /* 0x24 */ uint8_t  _pad_0x24[0x4];            /* pad to 0x28 */
    /* 0x28 */ uint8_t  cmn_res_name[0x18];        /* common resource name buffer (AddCmnResourceFile) */
    /* 0x40 */ uint64_t res_list_head;             /* linked list head for resource search (AddCmnResourceFile) */
    /* 0x48 */ uint8_t  _pad_0x48[0x8];            /* gap */
    /* 0x50 */ uint64_t res_search_ptr;            /* current search pointer in resource list */
    /* 0x58 */ uint16_t res_count_minus1;          /* *(ushort*)(param_1+0x58) - 1 returned by AddCmnResourceFile */
    /* 0x5A */ uint8_t  _pad_0x5A[0x3E];           /* gap to 0x98 */
    /* 0x98 */ uint64_t mutex_or_lock[2];          /* passed to FUN_140443b90/bd0 (lock/unlock) in Play/AnmStrmFrame */
    /* 0xA8 */ uint8_t  _pad_0xA8[0x30];           /* gap to 0xD8 */
    /* 0xD8 */ int32_t  active_stream_count;       /* incremented in Entry; checked != 0 in AnmStrmFrame */
    /* 0xDC */ uint8_t  _pad_0xDC[0x4];            /* pad to 0xE0 */
} nuccAnmStrmManager;

static_assert(offsetof(nuccAnmStrmManager, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(nuccAnmStrmManager, strm_slots_ptr) == 0x18, "strm_slots_ptr @ 0x18");
static_assert(offsetof(nuccAnmStrmManager, slot_count) == 0x20, "slot_count @ 0x20");
static_assert(offsetof(nuccAnmStrmManager, cmn_res_name) == 0x28, "cmn_res_name @ 0x28");
static_assert(offsetof(nuccAnmStrmManager, res_list_head) == 0x40, "res_list_head @ 0x40");
static_assert(offsetof(nuccAnmStrmManager, res_search_ptr) == 0x50, "res_search_ptr @ 0x50");
static_assert(offsetof(nuccAnmStrmManager, res_count_minus1) == 0x58, "res_count_minus1 @ 0x58");
static_assert(offsetof(nuccAnmStrmManager, mutex_or_lock) == 0x98, "mutex_or_lock @ 0x98");
static_assert(offsetof(nuccAnmStrmManager, active_stream_count) == 0xD8, "active_stream_count @ 0xD8");

/* ========================================================================
 * nuccIpcMessage  (IPC message queue manager)
 * Size: 0x40 (proven: FUN_14047ed10(0x40, ...) in CreateInstance)
 * Param type: int* (4-byte indexed)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccIpcMessage {
    /* 0x00 */ int32_t  state;                     /* 0=uninit, 1=initialized; checked in Init/Destroy */
    /* 0x04 */ int32_t  field_0x04;                /* set to 3 in Init */
    /* 0x08 */ int32_t  field_0x08;                /* set to 1 in Init */
    /* 0x0C */ uint8_t  _pad_0x0C[0x4];            /* pad to 0x10 */
    /* 0x10 */ uint64_t queue1_sentinel;           /* intrusive list sentinel (self-linked when empty) */
    /* 0x18 */ uint64_t queue1_tail;               /* tail pointer for queue1 */
    /* 0x20 */ int32_t  queue1_count;              /* element count for queue1 */
    /* 0x24 */ int32_t  queue1_field;              /* zeroed in Init */
    /* 0x28 */ uint64_t queue2_sentinel;           /* second intrusive list sentinel */
    /* 0x30 */ uint64_t queue2_tail;               /* tail pointer for queue2 */
    /* 0x38 */ int32_t  queue2_count;              /* element count for queue2 */
    /* 0x3C */ int32_t  queue2_field;              /* zeroed in Init */
} nuccIpcMessage;

static_assert(sizeof(nuccIpcMessage) == 0x40, "nuccIpcMessage must be 0x40 (allocator size)");
static_assert(offsetof(nuccIpcMessage, state) == 0x00, "state @ 0x00");
static_assert(offsetof(nuccIpcMessage, field_0x04) == 0x04, "field_0x04 @ 0x04");
static_assert(offsetof(nuccIpcMessage, field_0x08) == 0x08, "field_0x08 @ 0x08");
static_assert(offsetof(nuccIpcMessage, queue1_sentinel) == 0x10, "queue1_sentinel @ 0x10");
static_assert(offsetof(nuccIpcMessage, queue1_tail) == 0x18, "queue1_tail @ 0x18");
static_assert(offsetof(nuccIpcMessage, queue1_count) == 0x20, "queue1_count @ 0x20");
static_assert(offsetof(nuccIpcMessage, queue2_sentinel) == 0x28, "queue2_sentinel @ 0x28");
static_assert(offsetof(nuccIpcMessage, queue2_tail) == 0x30, "queue2_tail @ 0x30");
static_assert(offsetof(nuccIpcMessage, queue2_count) == 0x38, "queue2_count @ 0x38");

/* ========================================================================
 * nuccAnmStrmData  (animation stream data container)
 * Size: unknown, >= 0xB0 (last proven field at param_1[0x15] = 0xA8 as uint64*)
 * Vtable: PTR_FUN_140658600 (ctor), switched to PTR_FUN_140773600 in dtor
 * Contains embedded std::vector-like at offset 0x30 (3 pointers) and
 * an embedded sub-object at offset 0xA0.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmStrmData {
    /* 0x00 */ uint64_t vtable;                    /* PTR_FUN_140658600 (ctor), PTR_FUN_140773600 (dtor) */
    /* 0x08 */ uint64_t field_0x08;                /* zeroed in ctor */
    /* 0x10 */ uint64_t field_0x10;                /* zeroed in ctor */
    /* 0x18 */ uint64_t self_ptr_1;                /* points to self (intrusive list node) */
    /* 0x20 */ uint64_t self_ptr_2;                /* points to self (intrusive list node) */
    /* 0x28 */ uint8_t  _pad_0x28[0x8];            /* gap */
    /* 0x30 */ uint64_t vec_begin;                 /* std::vector-like: begin pointer */
    /* 0x38 */ uint64_t vec_end;                   /* std::vector-like: end pointer */
    /* 0x40 */ uint64_t vec_capacity;              /* std::vector-like: capacity/end-of-storage */
    /* 0x48 */ uint8_t  _pad_0x48[0x58];           /* gap to 0xA0 */
    /* 0xA0 */ uint64_t sub_object_ptr;            /* pointer to sub-object (FUN_1401552e0 called on it in dtor) */
    /* 0xA8 */ uint64_t field_0xa8;                /* zeroed in ctor (param_1[0x15]) */
} nuccAnmStrmData;

static_assert(offsetof(nuccAnmStrmData, vtable) == 0x00, "vtable @ 0x00");
static_assert(offsetof(nuccAnmStrmData, field_0x08) == 0x08, "field_0x08 @ 0x08");
static_assert(offsetof(nuccAnmStrmData, field_0x10) == 0x10, "field_0x10 @ 0x10");
static_assert(offsetof(nuccAnmStrmData, self_ptr_1) == 0x18, "self_ptr_1 @ 0x18");
static_assert(offsetof(nuccAnmStrmData, self_ptr_2) == 0x20, "self_ptr_2 @ 0x20");
static_assert(offsetof(nuccAnmStrmData, vec_begin) == 0x30, "vec_begin @ 0x30");
static_assert(offsetof(nuccAnmStrmData, vec_end) == 0x38, "vec_end @ 0x38");
static_assert(offsetof(nuccAnmStrmData, vec_capacity) == 0x40, "vec_capacity @ 0x40");
static_assert(offsetof(nuccAnmStrmData, sub_object_ptr) == 0xA0, "sub_object_ptr @ 0xA0");
static_assert(offsetof(nuccAnmStrmData, field_0xa8) == 0xA8, "field_0xa8 @ 0xA8");

#endif /* ST1C04_H */