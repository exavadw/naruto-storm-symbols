/* cmn86.h — CRI middleware filesystem classes for NARUTO STORM 4 PC 1.09 (s4, NSUNS4_release.exe)
 *
 * All layouts INFERRED from static analysis of x64 decompiled code.
 * Sizes proven from allocator calls in s4 code:
 *   Manager 0x140 — operator_new(0x140) in Initialize (RVA 0xA47DC0)
 *   BindCpk 0x58  — operator_new(0x58) in Binder::Bind (RVA 0xA907D0)
 *   Loader  0x18  — Manager ctor array stride: puVar3 += 3 uint64* = 0x18 (RVA 0xA479F0)
 * Own-game names only (Storm 4 / s4 sources). No Trilogy namespace for s4.
 * Image base: 0x140000000
 */

#ifndef CMN86_H
#define CMN86_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations */
typedef struct nuccCriFsBindCpk nuccCriFsBindCpk;
typedef struct nuccCriFsBinder nuccCriFsBinder;
typedef struct nuccCriFsLoaderImpl nuccCriFsLoaderImpl;
typedef struct nuccCriFsLoader nuccCriFsLoader;
typedef struct nuccCriFsManager nuccCriFsManager;

/* MSVC x64 std::vector<T*> placeholder — 3 pointers = 0x18 bytes */
typedef struct {
    uint64_t data_ptr;   /* +0x00 */
    uint64_t end_ptr;    /* +0x08 */
    uint64_t capacity;   /* +0x10 */
} msvc_vector_bindcpk_ptr;

/* MSVC x64 std::string placeholder — 0x20 bytes (SSO buffer 16 + size + capacity) */
typedef struct {
    uint8_t buf[16];     /* +0x00 SSO buffer or heap ptr */
    uint64_t size;       /* +0x10 */
    uint64_t capacity;   /* +0x18 */
} msvc_string;

/* Nucc::Memory::BlockAllocator placeholder — opaque pointer-sized */
typedef struct {
    uint64_t allocator_ptr;
} nucc_block_allocator;

/* ========================================================================
 * nuccCriFsLoaderImpl
 * Size: >= 0x10 (vtable + handle). Always embedded in nuccCriFsLoader at +0x08.
 * Vtable: PTR_FUN_141110310 (set in ctor at RVA 0xA91080).
 * ======================================================================== */
struct __attribute__((packed)) nuccCriFsLoaderImpl {
    uint64_t vtable;           /* +0x00  PTR_FUN_141110310 */
    uint64_t cri_loader_handle;/* +0x08  criFsLoader handle */
};
static_assert(offsetof(nuccCriFsLoaderImpl, vtable) == 0x00, "LoaderImpl.vtable");
static_assert(offsetof(nuccCriFsLoaderImpl, cri_loader_handle) == 0x08, "LoaderImpl.cri_loader_handle");

/* ========================================================================
 * nuccCriFsLoader
 * Size: 0x18 (proven by Manager ctor array stride: puVar3 += 3 uint64* = 0x18).
 * Wraps LoaderImpl at +0x08 via composition.
 * Vtable: PTR_FUN_141109730 (set per-entry in Manager ctor at RVA 0xA479F0).
 * ======================================================================== */
struct __attribute__((packed)) nuccCriFsLoader {
    uint64_t vtable;              /* +0x00  PTR_FUN_141109730 */
    nuccCriFsLoaderImpl impl;     /* +0x08  embedded LoaderImpl */
};
static_assert(offsetof(nuccCriFsLoader, vtable) == 0x00, "Loader.vtable");
static_assert(offsetof(nuccCriFsLoader, impl) == 0x08, "Loader.impl");
static_assert(sizeof(nuccCriFsLoader) == 0x18, "Loader size == 0x18 (Manager ctor stride)");

/* ========================================================================
 * nuccCriFsBindCpk
 * Size: 0x58 (proven by operator_new(0x58) in Binder::Bind at RVA 0xA907D0).
 * Vtable: PTR_FUN_141113488 (set in ctor at RVA 0xAAB050).
 * ======================================================================== */
struct __attribute__((packed)) nuccCriFsBindCpk {
    uint64_t vtable;              /* +0x00  PTR_FUN_141113488 */
    uint32_t binder_handle;       /* +0x08  criFsBinder handle (ctor: *(u32*)(this+8)=0) */
    uint32_t _pad_0c;             /* +0x0C  padding */
    uint64_t malloc_buffer;       /* +0x10  allocated work buffer (BindCpk stores malloc result) */
    uint32_t work_size;           /* +0x18  work buffer size (u32 at param_1+0x18) */
    uint32_t _pad_1c;             /* +0x1C  padding */
    msvc_string cpk_path;         /* +0x20  std::string (BindCpk accesses param_1+0x20 as string) */
    uint8_t _tail[0x58 - 0x40];  /* +0x40  remaining bytes up to proven size 0x58 */
};
static_assert(offsetof(nuccCriFsBindCpk, vtable) == 0x00, "BindCpk.vtable");
static_assert(offsetof(nuccCriFsBindCpk, binder_handle) == 0x08, "BindCpk.binder_handle");
static_assert(offsetof(nuccCriFsBindCpk, malloc_buffer) == 0x10, "BindCpk.malloc_buffer");
static_assert(offsetof(nuccCriFsBindCpk, work_size) == 0x18, "BindCpk.work_size");
static_assert(offsetof(nuccCriFsBindCpk, cpk_path) == 0x20, "BindCpk.cpk_path");
static_assert(sizeof(nuccCriFsBindCpk) == 0x58, "BindCpk size == 0x58 (Binder::Bind alloc)");

/* ========================================================================
 * nuccCriFsBinder
 * Size: 0x38 (embedded in Manager at +0x18, next field loaders at +0x50).
 * Ctor (RVA 0xA90710): null_sentinel=0, vector at +0x08/+0x10/+0x18,
 * allocator at +0x20. Reserves 0xe entries. No vtable (not polymorphic).
 * ======================================================================== */
struct __attribute__((packed)) nuccCriFsBinder {
    uint64_t null_sentinel;       /* +0x00  set to 0 in ctor */
    msvc_vector_bindcpk_ptr bind_list; /* +0x08  vector<nuccCriFsBindCpk*> */
    nucc_block_allocator allocator;    /* +0x20  BlockAllocator */
    uint8_t _pad_28[0x38 - 0x28];     /* +0x28  padding to reach 0x38 */
};
static_assert(offsetof(nuccCriFsBinder, null_sentinel) == 0x00, "Binder.null_sentinel");
static_assert(offsetof(nuccCriFsBinder, bind_list) == 0x08, "Binder.bind_list");
static_assert(offsetof(nuccCriFsBinder, allocator) == 0x20, "Binder.allocator");
static_assert(sizeof(nuccCriFsBinder) == 0x38, "Binder embedded size == 0x38 (Manager layout)");

/* ========================================================================
 * nuccCriFsManager
 * Size: 0x140 (proven by operator_new(0x140) in Initialize at RVA 0xA47DC0).
 * Singleton stored in DAT_1416b6480.
 * Ctor (RVA 0xA479F0):
 *   +0x00 work_buffer, +0x08 work_size, +0x10 log_file
 *   +0x18 Binder (ctor called via param_1+3), +0x50 loaders[8] (stride 0x18)
 *   +0x110 encrypt_list vector, +0x128 allocator
 * ======================================================================== */
struct __attribute__((packed)) nuccCriFsManager {
    uint64_t work_buffer;         /* +0x00  MallocCore result */
    uint32_t work_size;           /* +0x08  from criFs_CalculateWorkSizeForLibrary */
    uint32_t _pad_0c;             /* +0x0C  padding */
    uint64_t log_file;            /* +0x10  FILE* */
    nuccCriFsBinder binder;       /* +0x18  embedded Binder */
    nuccCriFsLoader loaders[8];   /* +0x50  8 x 0x18 = 0xC0, ends at +0x110 */
    msvc_vector_bindcpk_ptr encrypt_list; /* +0x110  vector<int> */
    nucc_block_allocator allocator;       /* +0x128  BlockAllocator */
    uint8_t _tail[0x140 - 0x130];        /* +0x130  remaining bytes to 0x140 */
};
static_assert(offsetof(nuccCriFsManager, work_buffer) == 0x00, "Manager.work_buffer");
static_assert(offsetof(nuccCriFsManager, work_size) == 0x08, "Manager.work_size");
static_assert(offsetof(nuccCriFsManager, log_file) == 0x10, "Manager.log_file");
static_assert(offsetof(nuccCriFsManager, binder) == 0x18, "Manager.binder");
static_assert(offsetof(nuccCriFsManager, loaders) == 0x50, "Manager.loaders");
static_assert(offsetof(nuccCriFsManager, encrypt_list) == 0x110, "Manager.encrypt_list");
static_assert(offsetof(nuccCriFsManager, allocator) == 0x128, "Manager.allocator");
static_assert(sizeof(nuccCriFsManager) == 0x140, "Manager size == 0x140 (Initialize alloc)");

/* ========================================================================
 * nuccCriFsFileMountManager — SKIP
 * All methods are static. No instance struct. FileMount takes direct params,
 * Finalize operates on global state (DAT_1416b83f0), FindByFileName traverses tree nodes.
 * ======================================================================== */

#endif /* CMN86_H */