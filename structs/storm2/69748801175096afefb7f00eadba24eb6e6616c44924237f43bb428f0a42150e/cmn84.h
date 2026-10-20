/* cmn84 s2: CriManaSystemTimer, CriMv, CriMvEasyFileReaderMem
 * Build: s2 (NSUNS2.exe)
 * All layouts INFERRED from static decompilation, not CONFIRMED at runtime.
 * CRI middleware classes: proprietary, reconstructed from s2 code only.
 */
#ifndef CMN84_S2_H
#define CMN84_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * CriManaSystemTimer
 * Size: 0x70 (proven by FUN_1400a9400(0x70,...) in Create at 0x7C1F0
 * and FUN_1400a94a4(param_1,0x70) in dtor at 0x7C100)
 * Vtable: dual vtable set in ctor at 0x7C020 (*param_1 and param_1[1])
 * ========================================================================= */
typedef struct __attribute__((packed)) CriManaSystemTimer {
    /* 0x00 */ void *vftable;            /* CriManaSystemTimer::vftable */
    /* 0x08 */ void *vftable2;           /* second vtable ptr (ctor sets both) */
    /* 0x10 */ void *allocator;          /* param_1 passed to Create */
    /* 0x18 */ void *mana_timer_handle;  /* criManaTimer_Create result */
    /* 0x20 */ int32_t timer_type;       /* SetTimerType writes here */
    /* 0x24 */ uint8_t _pad_24[4];       /* padding to 0x28 */
    /* 0x28 */ void *heap_alloc;         /* criHeap_AllocFix result */
    /* 0x30 */ int32_t work_size;        /* CalculateHandleWorkSize result */
    /* 0x34 */ int32_t pause_state;      /* Pause/Stop read/write */
    /* 0x38 */ uint64_t accumulated_time;/* GetTime accumulates here */
    /* 0x40 */ uint64_t time_denominator;/* GetTime output param */
    /* 0x48 */ uint64_t last_tick;       /* Pause/GetTime snapshot */
    /* 0x50 */ uint64_t manual_unit_num; /* SetManualTimerUnit */
    /* 0x58 */ uint64_t manual_unit_denom;/* SetManualTimerUnit */
    /* 0x60 */ uint64_t manual_counter;  /* AdvanceManualTimer increments */
    /* 0x68 */ int32_t speed_num;        /* SetSpeed numerator */
    /* 0x6C */ int32_t speed_denom;      /* SetSpeed denominator */
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
 * NO INSTANCE STRUCT in s2. All methods are static/global initializers:
 * Initialize_Common (0x6AD20), Finalize (0x6AD00), IsLibraryInitialized (0x6AD40)
 * operate on globals (DAT_147e6be90, DAT_14812d9e0, etc.).
 * CalcHandleWorkSize (0x6ACE0) returns FUN_140073d40() + 0x998 with no this.
 * SetupMovieHandleWork, AttachSofdecDecoder, InitializeMana take no instance.
 * Skip: no instance layout to reconstruct.
 * ========================================================================= */

/* =========================================================================
 * CriMvEasyFileReaderMem
 * Size: 0x48 (proven by FUN_1400a9400(0x48,...) in Create at 0x7CC10
 * and FUN_1400a94a4(param_1,0x48) in dtor at 0x7CBB0)
 * Inherits: CriMvFileReaderInterface (vtable at +0x00), CriAllocator (+0x08)
 * ========================================================================= */
typedef struct __attribute__((packed)) CriMvEasyFileReaderMem {
    /* 0x00 */ void *vftable_reader;     /* CriMvFileReaderInterface::vftable */
    /* 0x08 */ void *vftable_allocator;  /* CriAllocator::vftable */
    /* 0x10 */ void *data_ptr;           /* Open sets from ParseFileName */
    /* 0x18 */ uint64_t data_size;       /* Open sets, -1 = unset */
    /* 0x20 */ void *parent;             /* param_1 passed to Create */
    /* 0x28 */ uint64_t read_pos;        /* Seek/Read update */
    /* 0x30 */ uint64_t last_read_size;  /* Read stores memcpy length */
    /* 0x38 */ int32_t open_status;      /* Open/GetOpenStatus */
    /* 0x3C */ int32_t close_status;     /* GetCloseStatus */
    /* 0x40 */ int32_t read_status;      /* Read/GetReadStatus */
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

#endif /* CMN84_S2_H */