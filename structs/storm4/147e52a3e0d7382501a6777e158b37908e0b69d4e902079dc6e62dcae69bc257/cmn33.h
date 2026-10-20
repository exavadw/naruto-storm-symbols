#ifndef CMN33_S4_H
#define CMN33_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * cmn33 s4 — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe)
 * All results: INFERRED (static analysis only, no runtime confirmation)
 * Build: s4, sha256 prefix 147e52a3e0d7
 * Date: 2026-10-20
 */

/*
 * mmThreadCond — size 0xA0 (proven)
 * Evidence: ctor at 0x9F2100 writes param_1[0x13] (offset 0x98), last qword → total 0xA0
 * Vtable: PTR_FUN_141102748 at +0x00
 * Embedded sub-objects at +0x70 (event/condvar, 16 bytes) and +0x80 (mmThread_Impl, 16 bytes)
 *   are passed to inner ctors but their internal layouts are not expanded here.
 */
typedef struct __attribute__((packed)) mmThreadCond {
    void     *vtable;              /* +0x00 */
    uint64_t  pool_buffer;         /* +0x08 */
    uint64_t  pool_field_10;       /* +0x10 */
    uint64_t  pool_field_18;       /* +0x18 */
    uint64_t  pool_size;           /* +0x20, init 0xe00 */
    uint64_t  pool_alignment;      /* +0x28, init 0x10 */
    uint64_t  pool_field_30;       /* +0x30 */
    void     *allocator_vtable;    /* +0x38 */
    void     *pool_ptr_copy;       /* +0x40 */
    void     *linked_list_head;    /* +0x48 */
    void     *linked_list_tail;    /* +0x50 */
    void     *field_58;            /* +0x58 */
    uint64_t  field_60;            /* +0x60 */
    uint32_t  ref_count;           /* +0x68, init 1 */
    uint32_t  _pad_6c;             /* +0x6C */
    uint8_t   embedded_event[16];  /* +0x70, passed to FUN_14017d380 */
    uint8_t   embedded_thread_impl[16]; /* +0x80, passed to mmThread_Impl::mmThread_Impl */
    uint32_t  thread_running;      /* +0x90, init 0 */
    uint32_t  _pad_94;             /* +0x94 */
    uint64_t  mutex_or_flag;       /* +0x98, via mmMutex::mmMutex at +0x90+8? actually param_1[0x13]=0 */
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
static_assert(offsetof(mmThreadCond, _pad_6c) == 0x6C, "mmThreadCond._pad_6c");
static_assert(offsetof(mmThreadCond, embedded_event) == 0x70, "mmThreadCond.embedded_event");
static_assert(offsetof(mmThreadCond, embedded_thread_impl) == 0x80, "mmThreadCond.embedded_thread_impl");
static_assert(offsetof(mmThreadCond, thread_running) == 0x90, "mmThreadCond.thread_running");
static_assert(offsetof(mmThreadCond, _pad_94) == 0x94, "mmThreadCond._pad_94");
static_assert(offsetof(mmThreadCond, mutex_or_flag) == 0x98, "mmThreadCond.mutex_or_flag");

/*
 * mmTexture — size unknown, >= 0x58
 * Evidence: Lock at 0x1911A0 accesses param_1[3..10] (longlong*, byte offsets up to +0x50);
 *   Unlock at 0x190FD0 writes byte at param_1+8; ChangeSampleCount dereferences vtable at +0x00.
 * No operator new size argument visible in factory methods.
 * Vtable: dereferenced at +0x00 for virtual dispatch (vfunc at vtable+0x38 in ChangeSampleCount)
 * Note: Lock accesses fields through *param_1 indirection (inner GPU buffer object).
 *   The outer mmTexture struct fields below are from direct param_1[N] accesses in Lock.
 */
typedef struct __attribute__((packed)) mmTexture {
    void     *vtable;              /* +0x00 */
    uint8_t   _pad_08[32];         /* +0x08 to +0x27, not directly accessed as mmTexture fields */
    uint64_t  gpu_resource_or_cmd; /* +0x28, param_1[5] in Lock (vfunc call target base) */
    uint64_t  cmd_buffer_ptr;      /* +0x30, param_1[6] area */
    uint64_t  lock_counter;        /* +0x38, param_1[7] = param_1[7]+1 */
    uint8_t   locked_flag;         /* +0x40, *(undefined1*)(param_1+8)=0 in Unlock */
    uint8_t   _pad_41[7];          /* +0x41 to +0x47 */
    uint64_t  current_context;     /* +0x48, param_1[9] = param_2 */
    uint64_t  lock_command_ptr;    /* +0x50, param_1[10] = puVar7 */
} mmTexture;

static_assert(offsetof(mmTexture, vtable) == 0x00, "mmTexture.vtable");
static_assert(offsetof(mmTexture, _pad_08) == 0x08, "mmTexture._pad_08");
static_assert(offsetof(mmTexture, gpu_resource_or_cmd) == 0x28, "mmTexture.gpu_resource_or_cmd");
static_assert(offsetof(mmTexture, cmd_buffer_ptr) == 0x30, "mmTexture.cmd_buffer_ptr");
static_assert(offsetof(mmTexture, lock_counter) == 0x38, "mmTexture.lock_counter");
static_assert(offsetof(mmTexture, locked_flag) == 0x40, "mmTexture.locked_flag");
static_assert(offsetof(mmTexture, _pad_41) == 0x41, "mmTexture._pad_41");
static_assert(offsetof(mmTexture, current_context) == 0x48, "mmTexture.current_context");
static_assert(offsetof(mmTexture, lock_command_ptr) == 0x50, "mmTexture.lock_command_ptr");

#endif /* CMN33_S4_H */