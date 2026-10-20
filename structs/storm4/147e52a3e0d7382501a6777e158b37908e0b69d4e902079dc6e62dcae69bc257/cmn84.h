/* cmn84 s4: CriManaSystemTimer, CriMv, CriMvEasyFileReaderMem
 * Build: s4 (NSUNS4_release.exe, 64-bit, SHA 147e52a3e0d7)
 * All layouts INFERRED from static decompilation, not CONFIRMED at runtime.
 * CRI middleware classes: proprietary, reconstructed from s4 code only.
 */
#ifndef CMN84_S4_H
#define CMN84_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * CriManaSystemTimer
 * Size: 0x70 (proven by FUN_1400a9a90(0x70,...) in Create at RVA 0x7C870
 * and FUN_1400a9b34(param_1,0x70) in dtor at RVA 0x7C780)
 * Vtable: dual vtable set in ctor chain: FUN_14007c6f0 sets *param_1 = CriMvSystemTimerInterface::vftable;
 *         FUN_14006b3c0 sets *(param_1+1) = CriAllocator::vftable
 * ========================================================================= */
typedef struct __attribute__((packed)) CriManaSystemTimer {
    /* 0x00 */ void *vftable;            /* CriMvSystemTimerInterface::vftable (set by FUN_14007c6f0) */
    /* 0x08 */ void *vftable2;           /* CriAllocator::vftable (set by FUN_14006b3c0) */
    /* 0x10 */ void *allocator;          /* param_1 passed to Create */
    /* 0x18 */ void *mana_timer_handle;  /* initialized to 0 in Create; criManaTimer_Create result */
    /* 0x20 */ int32_t timer_type;       /* initialized to 0 in Create; SetTimerType writes here */
    /* 0x24 */ uint8_t _pad_24[4];       /* padding to 0x28 */
    /* 0x28 */ void *heap_alloc;         /* criHeap_AllocFix result (FUN_1400a9054) */
    /* 0x30 */ int32_t work_size;        /* FUN_14007d8f0 result stored in Create */
    /* 0x34 */ int32_t pause_state;      /* Pause/GetTime read/write; 0=running, 1=paused */
    /* 0x38 */ uint64_t accumulated_time;/* initialized to 0 in Create */
    /* 0x40 */ uint64_t time_denominator;/* initialized to 1 in Create */
    /* 0x48 */ uint64_t last_tick;       /* Pause/GetTime snapshot */
    /* 0x50 */ uint64_t manual_unit_num; /* initialized to 0 in Create */
    /* 0x58 */ uint64_t manual_unit_denom;/* initialized to 1 in Create */
    /* 0x60 */ uint64_t manual_counter;  /* initialized to 0 in Create; AdvanceManualTimer increments */
    /* 0x68 */ int32_t speed_num;        /* initialized to 1 in Create; SetSpeed writes */
    /* 0x6C */ int32_t speed_denom;      /* initialized to 1 in Create; SetSpeed writes */
} CriManaSystemTimer;

static_assert(offsetof(CriManaSystemTimer, vftable) == 0x00, "vftable");
static_assert(offsetof(CriManaSystemTimer, vftable2) == 0x08, "vftable2");
static_assert(offsetof(CriManaSystemTimer, allocator) == 0x10, "allocator");
static_assert(offsetof(CriManaSystemTimer, mana_timer_handle) == 0x18, "mana_timer_handle");
static_assert(offsetof(CriManaSystemTimer, timer_type) == 0x20, "timer_type");
static_assert(offsetof(CriManaSystemTimer, heap_alloc) == 0x28, "heap_alloc");
static_assert(offsetof(CriManaSystemTimer, work_size) == 0x30, "work_size");
static_assert(offsetof(CriManaSystemTimer, pause_state) == 0x34, "pause_state");
static_assert(offsetof(CriManaSystemTimer, accumulated_time) == 0x38, "accumulated_time");
static_assert(offsetof(CriManaSystemTimer, time_denominator) == 0x40, "time_denominator");
static_assert(offsetof(CriManaSystemTimer, last_tick) == 0x48, "last_tick");
static_assert(offsetof(CriManaSystemTimer, manual_unit_num) == 0x50, "manual_unit_num");
static_assert(offsetof(CriManaSystemTimer, manual_unit_denom) == 0x58, "manual_unit_denom");
static_assert(offsetof(CriManaSystemTimer, manual_counter) == 0x60, "manual_counter");
static_assert(offsetof(CriManaSystemTimer, speed_num) == 0x68, "speed_num");
static_assert(offsetof(CriManaSystemTimer, speed_denom) == 0x6C, "speed_denom");
static_assert(sizeof(CriManaSystemTimer) == 0x70, "CriManaSystemTimer size");

/* =========================================================================
 * CriMv: no instance state
 * All 11 methods are static/global initializers operating on CRI middleware globals:
 * Initialize_Common (RVA 0x6B390), Finalize (RVA 0x6B370), IsLibraryInitialized (RVA 0x6B3B0),
 * CalcHandleWorkSize (RVA 0x6B350), SetupVmpvParameters (RVA 0x73150), InitializeMana (RVA 0x7E620),
 * AttachSofdecDecoder (RVA 0x7E660), CalcMovieHandleWork (RVA 0x7CEE0, 0x7E670),
 * SetupMovieHandleWork (RVA 0x7CE70, 0x7E680).
 * Evidence: the decompiler cache state_surface returned 0 field accesses across all 11 seeds;
 * no param_1 dereferences in any method. No instance layout to reconstruct.
 * ========================================================================= */

/* =========================================================================
 * CriMvEasyFileReaderMem
 * Size: 0x48 (proven by FUN_1400a9a90(0x48,...) in Create at RVA 0x7D290
 * and FUN_1400a9b34(param_1,0x48) in dtor at RVA 0x7D230)
 * Inherits: CriMvFileReaderInterface (vtable at +0x00), CriAllocator (+0x08)
 * Vtable setup in Create: *puVar1 = CriMvEasyFileReaderMem::vftable; puVar1[1] = same vftable
 * Dtor restores: param_1[1] = CriAllocator::vftable; *param_1 = CriMvFileReaderInterface::vftable
 * ========================================================================= */
typedef struct __attribute__((packed)) CriMvEasyFileReaderMem {
    /* 0x00 */ void *vftable_reader;     /* CriMvFileReaderInterface::vftable */
    /* 0x08 */ void *vftable_allocator;  /* CriAllocator::vftable (restored in dtor) */
    /* 0x10 */ void *data_ptr;           /* Open sets from ParseFileName; init 0 in Create */
    /* 0x18 */ uint64_t data_size;       /* init 0xFFFFFFFFFFFFFFFF in Create (-1 = unset) */
    /* 0x20 */ void *parent;             /* param_1 passed to Create */
    /* 0x28 */ uint64_t read_pos;        /* Seek/Read update; init 0 */
    /* 0x30 */ uint64_t last_read_size;  /* Read stores memcpy length; init 0 */
    /* 0x38 */ int32_t open_status;      /* Open/GetOpenStatus; init 0 */
    /* 0x3C */ int32_t close_status;     /* GetCloseStatus */
    /* 0x40 */ int32_t read_status;      /* Read/GetReadStatus; init 0 */
    /* 0x44 */ uint8_t _pad_44[4];       /* padding to 0x48 */
} CriMvEasyFileReaderMem;

static_assert(offsetof(CriMvEasyFileReaderMem, vftable_reader) == 0x00, "vftable_reader");
static_assert(offsetof(CriMvEasyFileReaderMem, vftable_allocator) == 0x08, "vftable_allocator");
static_assert(offsetof(CriMvEasyFileReaderMem, data_ptr) == 0x10, "data_ptr");
static_assert(offsetof(CriMvEasyFileReaderMem, data_size) == 0x18, "data_size");
static_assert(offsetof(CriMvEasyFileReaderMem, parent) == 0x20, "parent");
static_assert(offsetof(CriMvEasyFileReaderMem, read_pos) == 0x28, "read_pos");
static_assert(offsetof(CriMvEasyFileReaderMem, last_read_size) == 0x30, "last_read_size");
static_assert(offsetof(CriMvEasyFileReaderMem, open_status) == 0x38, "open_status");
static_assert(offsetof(CriMvEasyFileReaderMem, close_status) == 0x3C, "close_status");
static_assert(offsetof(CriMvEasyFileReaderMem, read_status) == 0x40, "read_status");
static_assert(sizeof(CriMvEasyFileReaderMem) == 0x48, "CriMvEasyFileReaderMem size");

#endif /* CMN84_S4_H */