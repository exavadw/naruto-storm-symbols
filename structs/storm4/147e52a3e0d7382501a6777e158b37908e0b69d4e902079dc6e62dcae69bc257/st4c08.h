/* st4c08.h — Story cutscene/event playback structs for NARUTO STORM 4 PC 1.09 (s4)
 *
 * All layouts are INFERRED from static analysis of NSUNS4_release.exe (sha 147e52a3e0d7).
 * No runtime confirmation. Field names from Storm 4 symbols/strings only.
 * Cross-game names marked where applicable.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded Scaleform types.
 * Sizes derived from ctor/dtor decompilation in s4 build.
 */

/* Scaleform::Mutex — 5 pointers, 0x28 bytes.
 * Ctor allocates 0x20-byte heap impl via allocator+0x50.
 * Fields: vtable[0..2], impl_ptr[3], heap_impl[4].
 */
typedef struct __attribute__((packed)) Scaleform_Mutex {
    uint64_t vtable[3];       /* 0x00 - vtable ptrs */
    uint64_t impl_ptr;        /* 0x18 - points to self or base */
    uint64_t heap_impl;       /* 0x20 - heap-allocated 0x20-byte impl (HANDLE at +0x00) */
} Scaleform_Mutex;
static_assert(sizeof(Scaleform_Mutex) == 0x28, "Scaleform_Mutex size");

/* Scaleform::WaitCondition — single pointer wrapper, 0x08 bytes.
 * Ctor allocates 0x48-byte heap impl.
 */
typedef struct __attribute__((packed)) Scaleform_WaitCondition {
    uint64_t impl;            /* 0x00 - heap-allocated 0x48-byte impl */
} Scaleform_WaitCondition;
static_assert(sizeof(Scaleform_WaitCondition) == 0x08, "Scaleform_WaitCondition size");

/* Scaleform::Event — synchronization primitive for UI/cutscene signaling.
 * Layout from ctor (0x8D67A0), PulseEvent (0x8D6CD0), SetEvent (0x8D7040),
 * ResetEvent (0x8D6F70), Wait (0x8D7130), TryAcquireCommit (0x8D70F0).
 *
 * Size proven >= 0x58 by embedded Mutex at +0x28 (0x28 bytes) and
 * WaitCondition at +0x50 (0x08 bytes). No standalone operator_new found;
 * always embedded in larger objects.
 */
typedef struct __attribute__((packed)) Scaleform_Event {
    uint64_t vtable;          /* 0x00 - PTR_FUN_1410f4438 */
    uint64_t base_field_08;   /* 0x08 - accessed by TryAcquireCommit (byte at +0x08) */
    uint64_t base_field_10;   /* 0x10 - handler array ptr / commit mutex context */
    uint64_t ref_count_or_pad;/* 0x18 - PTR_LAB_1410f4450 set in ctor */
    uint8_t  signaled;        /* 0x20 - event signaled flag */
    uint8_t  auto_reset;      /* 0x21 - auto-reset flag (cleared after Wait if set) */
    uint8_t  _pad_22[6];     /* 0x22 - padding to align Mutex */
    Scaleform_Mutex mutex;    /* 0x28 - protects signaled/auto_reset flags */
    Scaleform_WaitCondition wait_cond; /* 0x50 - condition variable for Wait() */
} Scaleform_Event;
static_assert(offsetof(Scaleform_Event, vtable) == 0x00, "Scaleform_Event.vtable");
static_assert(offsetof(Scaleform_Event, base_field_08) == 0x08, "Scaleform_Event.base_field_08");
static_assert(offsetof(Scaleform_Event, base_field_10) == 0x10, "Scaleform_Event.base_field_10");
static_assert(offsetof(Scaleform_Event, ref_count_or_pad) == 0x18, "Scaleform_Event.ref_count_or_pad");
static_assert(offsetof(Scaleform_Event, signaled) == 0x20, "Scaleform_Event.signaled");
static_assert(offsetof(Scaleform_Event, auto_reset) == 0x21, "Scaleform_Event.auto_reset");
static_assert(offsetof(Scaleform_Event, mutex) == 0x28, "Scaleform_Event.mutex");
static_assert(offsetof(Scaleform_Event, wait_cond) == 0x50, "Scaleform_Event.wait_cond");
/* Size unknown, >= 0x58. No sizeof assert — object always embedded. */

/* nuccAnmStrmData — animation stream data loader/parser.
 * Layout from Read (0x9A9D28). Only 1 method in s4 build (< 3 threshold).
 * Vtable at +0x00, virtual call at +0x10, status field at +0x74.
 * Size unknown, >= 0x78.
 */
typedef struct __attribute__((packed)) nuccAnmStrmData {
    uint64_t vtable;          /* 0x00 */
    uint64_t _unk_08;         /* 0x08 */
    uint64_t _unk_10_vfunc;   /* 0x10 - virtual function slot called at end of Read */
    uint8_t  _pad_18[92];    /* 0x18 - gap to status field */
    int32_t  load_status;     /* 0x74 - set to 1 on load failure (CriFsLoader status check) */
    uint8_t  _pad_78[8];     /* 0x78 - padding */
} nuccAnmStrmData;
static_assert(offsetof(nuccAnmStrmData, vtable) == 0x00, "nuccAnmStrmData.vtable");
static_assert(offsetof(nuccAnmStrmData, _unk_10_vfunc) == 0x10, "nuccAnmStrmData._unk_10_vfunc");
static_assert(offsetof(nuccAnmStrmData, load_status) == 0x74, "nuccAnmStrmData.load_status");
/* Size unknown, >= 0x78. No sizeof assert. */

/* nuccIpcMessageQueue — IPC message queue with std::list storage.
 * Layout from Remove (0x210D04). Only 1 method in s4 build (< 3 threshold).
 * std::list<nuccIpcMessageTable> at offset +0x68.
 * Size unknown, >= 0x80 (std::list is typically 0x18 on x64 MSVC).
 */
typedef struct __attribute__((packed)) nuccIpcMessageQueue {
    uint8_t  _pad_00[104];   /* 0x00 - unknown fields before list */
    uint64_t list_head;       /* 0x68 - std::list<nuccIpcMessageTable> begin/end/sentinel */
    uint64_t list_end;        /* 0x70 */
    uint64_t list_size;       /* 0x78 */
} nuccIpcMessageQueue;
static_assert(offsetof(nuccIpcMessageQueue, list_head) == 0x68, "nuccIpcMessageQueue.list_head");
/* Size unknown, >= 0x80. No sizeof assert. */

/* Classes SKIPPED (absent or insufficient methods in s4 build):
 * - nuccAnmStrm: 1 symbol (LoadCore at 0x9A7608), state_surface returned 0 fields.
 *   LoadCore is a free-function-style loader; param_1 accesses at +0x18,+0x20,+0x28
 *   belong to the caller's context, not a nuccAnmStrm instance.
 * - nuccAnmStrmManager::StrmData: 1 symbol (Update at 0x531704), trivial wrapper
 *   calling ccAdvCtrlStateMachine::DrawGame then FreeCore. No struct access.
 * - nuccIpcMessage: 2 symbols (Receive at 0x4FF0EC, Init at 0x6B1FDC) but both
 *   resolve to "(no symbol)" — no Ghidra function body exists at those RVAs.
 *   Phantom symbol table entries; cannot reconstruct.
 * - TrophyUnlockEvent: 1 symbol (TotalMoneyEarned at 0x4EF3B0), also resolves
 *   to "(no symbol)" — no code body. Phantom entry.
 */