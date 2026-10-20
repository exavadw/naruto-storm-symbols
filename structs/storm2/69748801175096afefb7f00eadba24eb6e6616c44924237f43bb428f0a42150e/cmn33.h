/*
 * cmn33.h — Storm 2 (NSUNS2.exe) common engine struct group
 * Build: s2 (NSUNS2.exe, sha256 prefix abf2b6)
 * All layouts INFERRED from static analysis. No runtime confirmation.
 * Generated: 2026-10-19
 *
 * Classes reconstructed (>=3 methods): mmThreadCond, mmTexture
 * Classes with <3 methods or no instance fields (listed only):
 *   mmShaderTechnique, mmStringEncoder, mmStructuredBuffer,
 *   mmSystemHeapAllocator, mmTechniqueTranslator, mmTextureTranslator,
 *   mmThread, mmThread_Impl, mmTimer, mmTLSFMallocAlgorithm
 */

#ifndef CMN33_S2_H
#define CMN33_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmThreadCond
 * Size: proven 0xA0 from ctor at 0x571D80 (param_1[0x13] is last qword write,
 *   + 0x14*8 = 0xA0). Ctor initializes fields up to offset 0x9C.
 * Evidence: mmThreadCond::mmThreadCond @ 0x571D80
 * ========================================================================= */
typedef struct __attribute__((packed)) mmThreadCond {
    /* 0x00 */ void **vtable;                          /* w: PTR_FUN_14088db70 */
    /* 0x08 */ uint64_t pool_buffer;                   /* w: allocated via FUN_1401624e0(0xe00,0x10) */
    /* 0x10 */ uint64_t pool_field_10;                 /* w: 0 in ctor */
    /* 0x18 */ uint64_t pool_field_18;                 /* w: 0 in ctor */
    /* 0x20 */ uint64_t pool_size;                     /* w: 0xe00 in ctor */
    /* 0x28 */ uint64_t pool_alignment;                /* w: 0x10 in ctor */
    /* 0x30 */ uint64_t pool_field_30;                 /* w: 0 in ctor */
    /* 0x38 */ void **allocator_vtable;                /* w: PTR_LAB_14088db58 */
    /* 0x40 */ uint64_t pool_ptr_copy;                 /* w: copy of pool_buffer */
    /* 0x48 */ uint64_t linked_list_head;              /* w: 0 in ctor, self-linked */
    /* 0x50 */ uint64_t linked_list_tail;              /* w: 0 in ctor */
    /* 0x58 */ void **field_58;                        /* w: PTR_LAB_14088db58 */
    /* 0x60 */ uint64_t field_60;                      /* w: copy of pool_ptr_copy */
    /* 0x68 */ uint32_t ref_count;                     /* w: 1 in ctor */
    /* 0x6C */ uint8_t pad_6C[4];                      /* padding to 0x70 */
    /* 0x70 */ uint8_t embedded_event[0x10];           /* r: passed to FUN_140153460 (inner mmThreadCond ctor) */
    /* 0x80 */ uint8_t embedded_thread_impl[0x10];     /* r: passed to FUN_140153640 (mmThread_Impl ctor) */
    /* 0x90 */ uint32_t thread_running;                /* w: 0 in ctor (via FUN_1401532b0) */
    /* 0x94 */ uint8_t pad_94[4];                      /* padding to 0x98 */
    /* 0x98 */ uint64_t mutex_or_flag;                 /* w: 0 in ctor */
} mmThreadCond;

static_assert(offsetof(mmThreadCond, vtable) == 0x00, "mmThreadCond.vtable");
static_assert(offsetof(mmThreadCond, pool_buffer) == 0x08, "mmThreadCond.pool_buffer");
static_assert(offsetof(mmThreadCond, pool_field_10) == 0x10, "mmThreadCond.pool_field_10");
static_assert(offsetof(mmThreadCond, pool_field_18) == 0x18, "mmThreadCond.pool_field_18");
static_assert(offsetof(mmThreadCond, pool_size) == 0x20, "mmThreadCond.pool_size");
static_assert(offsetof(mmThreadCond, pool_alignment) == 0x28, "mmThreadCond.pool_alignment");
static_assert(offsetof(mmThreadCond, pool_field_30) == 0x30, "mmThreadCond.pool_field_30");
static_assert(offsetof(mmThreadCond, allocator_vtable) == 0x38, "mmThreadCond.allocator_vtable");
static_assert(offsetof(mmThreadCond, pool_ptr_copy) == 0x40, "mmThreadCond.pool_ptr_copy");
static_assert(offsetof(mmThreadCond, linked_list_head) == 0x48, "mmThreadCond.linked_list_head");
static_assert(offsetof(mmThreadCond, linked_list_tail) == 0x50, "mmThreadCond.linked_list_tail");
static_assert(offsetof(mmThreadCond, field_58) == 0x58, "mmThreadCond.field_58");
static_assert(offsetof(mmThreadCond, field_60) == 0x60, "mmThreadCond.field_60");
static_assert(offsetof(mmThreadCond, ref_count) == 0x68, "mmThreadCond.ref_count");
static_assert(offsetof(mmThreadCond, embedded_event) == 0x70, "mmThreadCond.embedded_event");
static_assert(offsetof(mmThreadCond, embedded_thread_impl) == 0x80, "mmThreadCond.embedded_thread_impl");
static_assert(offsetof(mmThreadCond, thread_running) == 0x90, "mmThreadCond.thread_running");
static_assert(offsetof(mmThreadCond, mutex_or_flag) == 0x98, "mmThreadCond.mutex_or_flag");
static_assert(sizeof(mmThreadCond) == 0xA0, "mmThreadCond size");

/* =========================================================================
 * mmTexture
 * Size: unknown, >= 0x58. Instance methods access fields through param_1
 *   as longlong*, so offsets are byte-based. Lock accesses param_1[3..10].
 *   Unlock writes byte at param_1+8. ChangeSampleCount dereferences vtable.
 * Evidence: mmTexture::Lock @ 0x166CF0, mmTexture::Unlock @ 0x166B20,
 *   mmTexture::ChangeSampleCount @ 0x166B30
 * ========================================================================= */
typedef struct __attribute__((packed)) mmTexture {
    /* 0x00 */ void **vtable;                          /* r: dereferenced for virtual calls */
    /* 0x08 */ uint8_t unknown_08[0x18];              /* gap: no direct instance field access found */
    /* 0x20 */ uint64_t gpu_resource_or_cmd;           /* w: param_1[4] in Lock, used as linked list node */
    /* 0x28 */ uint64_t cmd_buffer_ptr;                /* w: param_1[5] in Lock, vfunc call target */
    /* 0x30 */ uint8_t unknown_30[0x08];              /* gap */
    /* 0x38 */ uint64_t lock_counter;                  /* rw: param_1[7] incremented in Lock */
    /* 0x40 */ uint8_t locked_flag;                    /* w: param_1+8 set to 0 in Unlock and conditionally in Lock */
    /* 0x41 */ uint8_t pad_41[7];                      /* padding */
    /* 0x48 */ uint64_t current_context;               /* w: param_1[9] in Lock */
    /* 0x50 */ uint64_t lock_command_ptr;              /* w: param_1[10] in Lock */
    /* Size beyond 0x58 unproven — factory methods allocate internally
     * but sizes are not visible in decompiled code. */
} mmTexture;

static_assert(offsetof(mmTexture, vtable) == 0x00, "mmTexture.vtable");
static_assert(offsetof(mmTexture, gpu_resource_or_cmd) == 0x20, "mmTexture.gpu_resource_or_cmd");
static_assert(offsetof(mmTexture, cmd_buffer_ptr) == 0x28, "mmTexture.cmd_buffer_ptr");
static_assert(offsetof(mmTexture, lock_counter) == 0x38, "mmTexture.lock_counter");
static_assert(offsetof(mmTexture, locked_flag) == 0x40, "mmTexture.locked_flag");
static_assert(offsetof(mmTexture, current_context) == 0x48, "mmTexture.current_context");
static_assert(offsetof(mmTexture, lock_command_ptr) == 0x50, "mmTexture.lock_command_ptr");
/* No sizeof assert: total size unproven */

/* =========================================================================
 * mmTLSFMallocAlgorithm — no struct (static/singleton)
 * All 3 methods operate on global state. No instance fields discovered.
 * ========================================================================= */

/* =========================================================================
 * mmThread_Impl — no struct (thin wrapper)
 * 3 methods returned 0 field accesses from state_surface.
 * ========================================================================= */

/* =========================================================================
 * mmThread — no struct (insufficient field evidence)
 * GetPriority reads through *param_1 indirection at offsets +0xF4 and +0x110,
 * but these are on the inner pointed-to object, not mmThread itself.
 * Only 2 fields found, both read-only through double indirection.
 * ========================================================================= */

#endif /* CMN33_S2_H */