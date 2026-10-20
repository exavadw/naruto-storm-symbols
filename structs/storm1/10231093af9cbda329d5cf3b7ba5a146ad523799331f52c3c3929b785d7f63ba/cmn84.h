/* cmn84 s1: CriManaSystemTimer, CriMv, CriMvEasyFileReaderMem
 * Build: s1 (NSUNS1.exe, SHA 10231093af9c)
 * All layouts INFERRED from static decompilation, not CONFIRMED at runtime.
 * CRI middleware classes: proprietary, reconstructed from s1 code only.
 */
#ifndef CMN84_S1_H
#define CMN84_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * CriManaSystemTimer
 * Size: 0x70 (proven by CriAllocator::operator_new(0x70,...) in Create
 *        and CriAllocator::operator_delete(param_1,0x70) in dtor)
 * Vtable: set at +0x00 and +0x08 in ctor FUN_14007c010
 * ========================================================================= */
typedef struct __attribute__((packed)) CriManaSystemTimer {
    /* 0x00 */ void *vftable;              /* CriManaSystemTimer::vftable */
    /* 0x08 */ void *vftable2;             /* second vtable ptr (ctor sets both) */
    /* 0x10 */ void *allocator;            /* param_1 passed to Create */
    /* 0x18 */ void *mana_timer_handle;    /* criManaTimer_Create result */
    /* 0x20 */ int32_t timer_type;         /* SetTimerType writes here */
    /* 0x24 */ uint8_t _pad_24[4];         /* padding to 0x28 */
    /* 0x28 */ void *heap_alloc;           /* criHeap_AllocFix result */
    /* 0x30 */ int32_t work_size;          /* criManaTimer_CalculateWorkSize */
    /* 0x34 */ int32_t pause_state;        /* Pause/Stop read/write */
    /* 0x38 */ uint64_t accumulated_time;  /* GetTime accumulates here */
    /* 0x40 */ uint64_t time_denominator;  /* GetTime output param */
    /* 0x48 */ uint64_t last_tick;         /* Pause/GetTime snapshot */
    /* 0x50 */ uint64_t manual_unit_num;   /* SetManualTimerUnit */
    /* 0x58 */ uint64_t manual_unit_denom; /* SetManualTimerUnit */
    /* 0x60 */ uint64_t manual_counter;    /* AdvanceManualTimer increments */
    /* 0x68 */ int32_t speed_num;          /* SetSpeed numerator */
    /* 0x6C */ int32_t speed_denom;        /* SetSpeed denominator */
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
 * CriMv
 * NO INSTANCE STRUCT in s1. All methods are static/global initializers:
 *   Initialize_Common, Finalize, IsLibraryInitialized operate on globals.
 *   CalcHandleWorkSize returns criMvPly_CalcHandleWorkSize() + 0x998 (no this).
 *   SetupMovieHandleWork, AttachSofdecDecoder, InitializeMana take no this.
 * Skip: no instance layout to reconstruct.
 * ========================================================================= */

/* =========================================================================
 * CriMvEasyFileReaderMem
 * Size: 0x48 (proven by CriAllocator::operator_new(0x48,...) in Create
 *        and CriAllocator::operator_delete(param_1,0x48) in dtor)
 * Inherits: CriMvFileReaderInterface (vtable at +0x00), CriAllocator (+0x08)
 * ========================================================================= */
typedef struct __attribute__((packed)) CriMvEasyFileReaderMem {
    /* 0x00 */ void *vftable_reader;       /* CriMvFileReaderInterface::vftable */
    /* 0x08 */ void *vftable_allocator;    /* CriAllocator::vftable */
    /* 0x10 */ void *data_ptr;             /* Open sets from ParseFileName */
    /* 0x18 */ uint64_t data_size;         /* Open sets from ParseFileName */
    /* 0x20 */ void *parent;               /* param_1 passed to Create */
    /* 0x28 */ uint64_t read_pos;          /* Seek/Read update */
    /* 0x30 */ uint64_t last_read_size;    /* Read stores memcpy length */
    /* 0x38 */ int32_t open_status;        /* Open/GetOpenStatus */
    /* 0x3C */ int32_t close_status;       /* GetCloseStatus */
    /* 0x40 */ int32_t read_status;        /* Read/GetReadStatus */
    /* 0x44 */ uint8_t _pad_44[4];         /* padding to 0x48 */
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

#endif /* CMN84_S1_H */