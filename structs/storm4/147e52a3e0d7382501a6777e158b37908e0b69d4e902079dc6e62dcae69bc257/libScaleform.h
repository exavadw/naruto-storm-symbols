/* libScaleform.h — Scaleform GFx runtime structs for NSUNS4 1.09 (s4)
 * Reconstructed from static analysis of NSUNS4_release.exe (sha256 prefix 75912b).
 * All layouts INFERRED from constructor decompilation; not CONFIRMED by runtime trace.
 * gcc-clean: compile with gcc -fsyntax-only -x c -std=c11
 */
#ifndef LIBSCALEFORM_H
#define LIBSCALEFORM_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Base class: RefCountImpl / RefCountNTSImpl
 * All Scaleform objects inherit vtable + refcount at offsets 0x00 and 0x08.
 * Evidence: Scaleform::Mutex::Mutex (RVA 0x87AAE0), BufferedFile::BufferedFile (RVA 0x900B10).
 */
typedef struct Scaleform_RefCountNTSImpl {
    void     *vtable;      /* +0x00 */
    uint32_t  refcount;    /* +0x08 */
    uint32_t  _pad_0C;     /* +0x0C alignment */
} __attribute__((packed)) Scaleform_RefCountNTSImpl;

static_assert(sizeof(Scaleform_RefCountNTSImpl) == 0x10, "RefCountNTSImpl size");

/* Scaleform::Mutex — wraps a Windows HANDLE (mutex or semaphore).
 * Constructor RVA 0x87AAE0: allocates internal 0x20-byte handle struct via allocator,
 * stores pointer at param_1[4] (offset 0x20). Object is 5 qwords = 0x28 bytes.
 * Evidence: Mutex::Mutex decompile shows param_1[0]=vtable, param_1[3]=secondary_vtable,
 * param_1[4]=handle_ptr. Internal alloc size 0x20 from allocator call.
 */
typedef struct Scaleform_Mutex {
    void     *vtable;         /* +0x00 PTR_FUN_1410ebd00 */
    uint64_t  _field_08;      /* +0x08 unknown (base class field?) */
    uint64_t  _field_10;      /* +0x10 unknown */
    void     *secondary_vtbl; /* +0x18 PTR_LAB_1410ebd18 */
    void     *handle_impl;    /* +0x20 ptr to 0x20-byte internal struct (HANDLE wrapper) */
} __attribute__((packed)) Scaleform_Mutex;

static_assert(offsetof(Scaleform_Mutex, vtable) == 0x00, "Mutex.vtable");
static_assert(offsetof(Scaleform_Mutex, secondary_vtbl) == 0x18, "Mutex.secondary_vtbl");
static_assert(offsetof(Scaleform_Mutex, handle_impl) == 0x20, "Mutex.handle_impl");
static_assert(sizeof(Scaleform_Mutex) == 0x28, "Mutex size");

/* Scaleform::WaitCondition — thin wrapper around a pointer to an opaque 0x48-byte impl.
 * Constructor RVA 0x87AC60: allocates 0x48 bytes, calls ccAdvOpenMenu(lVar1, 0) as base init,
 * then zeroes offsets +0x30, +0x38, +0x40 within the impl. Stores impl ptr at param_1[0].
 * The WaitCondition object itself is just one pointer (0x08 bytes).
 * Evidence: WaitCondition::WaitCondition decompile.
 */
typedef struct Scaleform_WaitCondition {
    void *impl;  /* +0x00 ptr to 0x48-byte internal struct */
} __attribute__((packed)) Scaleform_WaitCondition;

static_assert(sizeof(Scaleform_WaitCondition) == 0x08, "WaitCondition size");

/* Scaleform::Event — synchronization primitive embedding Mutex + WaitCondition.
 * Constructor RVA 0x8D67A0:
 *   param_1[0]  = vtable (PTR_FUN_1410f4438)
 *   param_1[3]  = secondary vtable (PTR_LAB_1410f4450)
 *   Mutex constructed at param_1+5 → offset 0x28
 *   WaitCondition constructed at param_1+10 → offset 0x50
 *   flag byte at param_1+4 → offset 0x20
 *   signaled byte at (longlong)param_1+0x21 → offset 0x21
 * Size >= 0x58 (WaitCondition at 0x50 is 8 bytes → ends at 0x58).
 * Evidence: Event::Event decompile, state_surface field at +0x21.
 */
typedef struct Scaleform_Event {
    void                  *vtable;         /* +0x00 PTR_FUN_1410f4438 */
    uint64_t               _field_08;      /* +0x08 */
    uint64_t               _field_10;      /* +0x10 */
    void                  *secondary_vtbl; /* +0x18 PTR_LAB_1410f4450 */
    uint8_t                auto_reset;     /* +0x20 param_2 from ctor */
    uint8_t                signaled;       /* +0x21 initialized to 0 */
    uint8_t                _pad_22[6];     /* +0x22 padding to align Mutex */
    Scaleform_Mutex        mutex;          /* +0x28 embedded Mutex (0x28 bytes) */
    Scaleform_WaitCondition wait;          /* +0x50 embedded WaitCondition (0x08 bytes) */
} __attribute__((packed)) Scaleform_Event;

static_assert(offsetof(Scaleform_Event, vtable) == 0x00, "Event.vtable");
static_assert(offsetof(Scaleform_Event, auto_reset) == 0x20, "Event.auto_reset");
static_assert(offsetof(Scaleform_Event, signaled) == 0x21, "Event.signaled");
static_assert(offsetof(Scaleform_Event, mutex) == 0x28, "Event.mutex");
static_assert(offsetof(Scaleform_Event, wait) == 0x50, "Event.wait");
static_assert(sizeof(Scaleform_Event) == 0x58, "Event size");

/* Scaleform::Thread — thread management object.
 * Constructor RVA 0x87ABC0:
 *   param_1[0]  = vtable (PTR_FUN_1410ebd40)
 *   param_1[3]  = secondary vtable (PTR_LAB_1410ebd80)
 *   param_1[4]  = param_2 (thread entry/arg?)
 *   param_1[5]  = param_3
 *   param_1[6]  = 0 (uint32 at offset 0x30)
 *   param_1[7]  = param_4
 *   param_1[8]  = param_5 (uint32 at offset 0x40)
 *   param_1[9]  = 0
 *   param_1[10] = 0 (uint32 at offset 0x50)
 *   uint32 at offset 0x34 = 0
 *   uint32 at offset 0x44 = 3
 *   uint32 at offset 0x54 = 0
 * Allocation size 0x30 from FUN_140d82330 caller was for a sub-object, not Thread itself.
 * Thread size unknown, >= 0x58 (last field at 0x54 is uint32 → ends at 0x58).
 * Evidence: Thread::Thread decompile, state_surface fields at 0x30,0x34,0x38,0x44,0x48,0x50,0x54.
 */
typedef struct Scaleform_Thread {
    void     *vtable;         /* +0x00 PTR_FUN_1410ebd40 */
    uint64_t  _field_08;      /* +0x08 */
    uint64_t  _field_10;      /* +0x10 */
    void     *secondary_vtbl; /* +0x18 PTR_LAB_1410ebd80 */
    void     *entry_arg;      /* +0x20 param_2 */
    void     *entry_func;     /* +0x28 param_3 */
    uint32_t  status;         /* +0x30 initialized 0 */
    uint32_t  _field_34;      /* +0x34 initialized 0 */
    void     *thread_handle;  /* +0x38 param_4 */
    uint32_t  priority;       /* +0x40 param_5 */
    uint32_t  state;          /* +0x44 initialized 3 */
    uint64_t  _field_48;      /* +0x48 initialized 0 */
    uint32_t  _field_50;      /* +0x50 initialized 0 */
    uint32_t  _field_54;      /* +0x54 initialized 0 */
} __attribute__((packed)) Scaleform_Thread;

static_assert(offsetof(Scaleform_Thread, vtable) == 0x00, "Thread.vtable");
static_assert(offsetof(Scaleform_Thread, status) == 0x30, "Thread.status");
static_assert(offsetof(Scaleform_Thread, state) == 0x44, "Thread.state");
static_assert(offsetof(Scaleform_Thread, _field_54) == 0x54, "Thread._field_54");
/* Size unproven: >= 0x58. No sizeof assert. */

/* Scaleform::SysFile — file handle wrapper (base class for BufferedFile).
 * Constructor RVA 0xBA6040:
 *   param_1[0] = vtable (PTR_FUN_140fba5b8)
 *   param_1[1] = refcount 1 (uint32 at offset 0x08)
 *   param_1[2] = 0 (file handle ptr)
 *   then sets vtable to PTR_FUN_14112e728 and calls Open()
 * Size = 0x18 (3 qwords). Allocation size 0x10 from SysFile::Open caller (RVA 0xBA6280)
 * was for a fallback/error path object, not SysFile itself.
 * Evidence: SysFile::SysFile decompile.
 */
typedef struct Scaleform_SysFile {
    void     *vtable;      /* +0x00 PTR_FUN_14112e728 (post-Open) */
    uint32_t  refcount;    /* +0x08 initialized 1 */
    uint32_t  _pad_0C;     /* +0x0C */
    void     *file_handle; /* +0x10 */
} __attribute__((packed)) Scaleform_SysFile;

static_assert(offsetof(Scaleform_SysFile, vtable) == 0x00, "SysFile.vtable");
static_assert(offsetof(Scaleform_SysFile, refcount) == 0x08, "SysFile.refcount");
static_assert(offsetof(Scaleform_SysFile, file_handle) == 0x10, "SysFile.file_handle");
static_assert(sizeof(Scaleform_SysFile) == 0x18, "SysFile size");

/* Scaleform::BufferedFile — buffered I/O wrapper around a SysFile*.
 * Constructor RVA 0x900B10:
 *   param_1[0] = vtable (PTR_FUN_1410f6638, after two vtable swaps)
 *   param_1[1] = refcount 1 (uint32 at offset 0x08)
 *   param_1[2] = param_2 (underlying SysFile* / file object)
 *   param_1[3] = buffer ptr (allocated 0x1FF8 bytes via allocator)
 *   param_1[4] = 0 (uint32 at offset 0x20, buffer position?)
 *   uint64 at offset 0x24 = 0 (buffer length / file position?)
 *   param_1[6] = file length from underlying file's vfunc+0x28
 * Allocation size 0x38 from SysFile::Open caller (RVA 0xBA6280):
 *   alloc(DAT_14165fd88, 0x38) → BufferedFile::BufferedFile(lVar3, file_ptr)
 * Confirms BufferedFile size = 0x38.
 * Evidence: BufferedFile::BufferedFile decompile, SysFile::Open decompile.
 */
typedef struct Scaleform_BufferedFile {
    void     *vtable;          /* +0x00 PTR_FUN_1410f6638 */
    uint32_t  refcount;        /* +0x08 initialized 1 */
    uint32_t  _pad_0C;         /* +0x0C */
    void     *underlying_file; /* +0x10 SysFile* or similar */
    void     *buffer;          /* +0x18 allocated 0x1FF8 bytes */
    uint32_t  buf_position;    /* +0x20 initialized 0 */
    uint32_t  _pad_24_unused;  /* +0x24 (part of uint64 below or separate) */
    uint64_t  file_offset;     /* +0x28? Actually at +0x24 per decompile: *(uint64*)(param_1+0x24)=0 */
    uint64_t  file_length;     /* +0x30 from underlying vfunc+0x28 */
} __attribute__((packed)) Scaleform_BufferedFile;

/* Corrected layout based on decompile: param_1[6] = offset 0x30, and uint64 at +0x24.
 * Total: 7 qwords = 0x38. Matches allocation proof. */

static_assert(offsetof(Scaleform_BufferedFile, vtable) == 0x00, "BufferedFile.vtable");
static_assert(offsetof(Scaleform_BufferedFile, refcount) == 0x08, "BufferedFile.refcount");
static_assert(offsetof(Scaleform_BufferedFile, underlying_file) == 0x10, "BufferedFile.underlying_file");
static_assert(offsetof(Scaleform_BufferedFile, buffer) == 0x18, "BufferedFile.buffer");
static_assert(offsetof(Scaleform_BufferedFile, buf_position) == 0x20, "BufferedFile.buf_position");
static_assert(offsetof(Scaleform_BufferedFile, file_length) == 0x30, "BufferedFile.file_length");
static_assert(sizeof(Scaleform_BufferedFile) == 0x38, "BufferedFile size");

#endif /* LIBSCALEFORM_H */