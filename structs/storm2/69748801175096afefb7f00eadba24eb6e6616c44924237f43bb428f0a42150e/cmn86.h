/* cmn86.h — CRI middleware filesystem classes for NARUTO STORM 2 (s2, NSUNS2.exe)
 *
 * All layouts INFERRED from static analysis of x64 decompiled code.
 * Sizes proven from ccFileLoadListForUi::LoadTh size arguments and array strides.
 * Own-game names only (Storm 2 / s2 sources).
 * Image base: 0x140000000
 */

#ifndef CMN86_H
#define CMN86_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>


/* MSVC x64 std::vector<nuccCriFsBindCpk*> placeholder — 3 pointers = 0x18 bytes */
typedef struct {
    uint64_t data_ptr;   /* +0x00 */
    uint64_t end_ptr;    /* +0x08 */
    uint64_t capacity;   /* +0x10 */
} msvc_vector_bindcpk_ptr;

/* MSVC x64 std::string placeholder — 0x20 bytes (SSO buffer 16 + ptr + size) */
typedef struct {
    uint8_t buf[16];     /* +0x00 SSO buffer or heap ptr */
    uint64_t size;       /* +0x10 */
    uint64_t capacity;   /* +0x18 */
} msvc_string;

/* Nucc::Memory::BlockAllocator placeholder — treated as opaque pointer-sized */
typedef struct {
    uint64_t allocator_ptr;
} nucc_block_allocator;

/* ========================================================================
 * nuccCriFsLoaderImpl
 * Size: >= 0x10 (vtable + handle). No standalone allocation found; always
 * embedded in nuccCriFsLoader at +0x08. Last proven field at +0x08.
 * Vtable: PTR_FUN_14089a3a0 (set in ctor at RVA 0x611A10).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCriFsLoaderImpl {
    uint64_t vtable;           /* +0x00  PTR_FUN_14089a3a0 */
    uint64_t cri_loader_handle;/* +0x08  criFsLoader handle (set by Create, read by Load/GetStatus/Destroy) */
} nuccCriFsLoaderImpl;
static_assert(offsetof(nuccCriFsLoaderImpl, vtable) == 0x00, "LoaderImpl.vtable");
static_assert(offsetof(nuccCriFsLoaderImpl, cri_loader_handle) == 0x08, "LoaderImpl.cri_loader_handle");

/* ========================================================================
 * nuccCriFsLoader
 * Size: unknown, >= 0x18. Wraps LoaderImpl at +0x08 via composition.
 * Create delegates to LoaderImpl::Create(param_1 + 8).
 * Manager ctor iterates loaders with stride 3 (uint64* units) = 0x18 bytes each.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCriFsLoader {
    uint64_t vtable;              /* +0x00  (inferred, wrapper may be POD) */
    nuccCriFsLoaderImpl impl;     /* +0x08  embedded LoaderImpl */
} nuccCriFsLoader;
static_assert(offsetof(nuccCriFsLoader, vtable) == 0x00, "Loader.vtable");
static_assert(offsetof(nuccCriFsLoader, impl) == 0x08, "Loader.impl");
static_assert(sizeof(nuccCriFsLoader) == 0x18, "Loader size == 0x18 (proven by Manager array stride 3*8)");

/* ========================================================================
 * nuccCriFsBindCpk
 * Size: 0x58 (proven by ccFileLoadListForUi::LoadTh(0x58,...) in Binder::Bind
 * at RVA 0x611380, source file nuccCriFsBinder.cpp).
 * Vtable: PTR_FUN_14089ce48 (set in ctor at RVA 0x62BBC0).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCriFsBindCpk {
    uint64_t vtable;              /* +0x00  PTR_FUN_14089ce48 */
    uint32_t binder_handle;       /* +0x08  criFsBinder handle (IsBinded/SetPriority read *(u32*)(this+8)) */
    uint32_t _pad_0c;             /* +0x0C  padding */
    uint64_t malloc_buffer;       /* +0x10  allocated work buffer (BindCpk stores malloc result here) */
    uint32_t work_size;           /* +0x18  work buffer size (BindCpk stores size ptr deref here) */
    uint32_t _pad_1c;             /* +0x1C  padding */
    msvc_string cpk_path;         /* +0x20  std::string — BindCpk accesses param_1+0x20 as string */
    uint8_t _tail[0x58 - 0x40];  /* +0x40  remaining bytes up to proven size 0x58 */
} nuccCriFsBindCpk;
static_assert(offsetof(nuccCriFsBindCpk, vtable) == 0x00, "BindCpk.vtable");
static_assert(offsetof(nuccCriFsBindCpk, binder_handle) == 0x08, "BindCpk.binder_handle");
static_assert(offsetof(nuccCriFsBindCpk, _pad_0c) == 0x0C, "BindCpk._pad_0c");
static_assert(offsetof(nuccCriFsBindCpk, malloc_buffer) == 0x10, "BindCpk.malloc_buffer");
static_assert(offsetof(nuccCriFsBindCpk, work_size) == 0x18, "BindCpk.work_size");
static_assert(offsetof(nuccCriFsBindCpk, _pad_1c) == 0x1C, "BindCpk._pad_1c");
static_assert(offsetof(nuccCriFsBindCpk, cpk_path) == 0x20, "BindCpk.cpk_path");
static_assert(offsetof(nuccCriFsBindCpk, _tail) == 0x40, "BindCpk._tail");
static_assert(sizeof(nuccCriFsBindCpk) == 0x58, "BindCpk size == 0x58 (proven by LoadTh)");

/* ========================================================================
 * nuccCriFsBinder
 * Size: 0x38 (embedded in Manager at +0x18, next field loaders at +0x50).
 * Ctor sets null_sentinel=0, vector at param_1+1..param_1+3 (+0x08/+0x10/+0x18),
 * allocator at param_1+4 (+0x20). Reserves 0xe entries in vector.
 * No vtable (not polymorphic — no vtable set in ctor).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCriFsBinder {
    uint64_t null_sentinel;       /* +0x00  set to 0 in ctor, checked before Bind */
    msvc_vector_bindcpk_ptr bind_list; /* +0x08  vector<nuccCriFsBindCpk*> */
    nucc_block_allocator allocator;    /* +0x20  BlockAllocator */
    uint8_t _pad_28[0x38 - 0x28];     /* +0x28  padding to reach 0x38 (embedded size in Manager) */
} nuccCriFsBinder;
static_assert(offsetof(nuccCriFsBinder, null_sentinel) == 0x00, "Binder.null_sentinel");
static_assert(offsetof(nuccCriFsBinder, bind_list) == 0x08, "Binder.bind_list");
static_assert(offsetof(nuccCriFsBinder, allocator) == 0x20, "Binder.allocator");
static_assert(offsetof(nuccCriFsBinder, _pad_28) == 0x28, "Binder._pad_28");
static_assert(sizeof(nuccCriFsBinder) == 0x38, "Binder embedded size == 0x38 (Manager layout)");

/* ========================================================================
 * nuccCriFsManager
 * Size: 0x140 (proven by ccFileLoadListForUi::LoadTh(0x140,...) in Initialize
 * at RVA 0x5C6DE0, source file nuccCriFsManager.cpp line 0x9c).
 * Singleton stored in DAT_140a9f210.
 * Ctor layout:
 *   param_1[0] = work_buffer (+0x00)
 *   param_1+1 = work_size (+0x08, u32 via criFs_CalculateWorkSizeForLibrary)
 *   param_1[2] = log_file (+0x10, set to 0)
 *   param_1+3 = Binder (+0x18, nuccCriFsBinder ctor called)
 *   param_1+10 = loaders[0] (+0x50, 8 entries, stride 3 uint64* = 0x18 each)
 *   param_1[0x22..0x24] = encrypt_list vector (+0x110)
 *   param_1+0x25 = allocator (+0x128)
 * IsEncryptCpk reads vector at +0x110/+0x118 (int* elements, stride 4).
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccCriFsManager {
    uint64_t work_buffer;         /* +0x00  MallocCore result after criFs_CalculateWorkSizeForLibrary */
    uint32_t work_size;           /* +0x08  work size from criFs_CalculateWorkSizeForLibrary */
    uint32_t _pad_0c;             /* +0x0C  padding */
    uint64_t log_file;            /* +0x10  FILE* (checked in dtor with fclose) */
    nuccCriFsBinder binder;       /* +0x18  embedded Binder (ctor called at param_1+3 = +0x18) */
    /* +0x50: array of 8 nuccCriFsLoader entries, stride 0x18 each */
    nuccCriFsLoader loaders[8];   /* +0x50  8 × 0x18 = 0xC0, ends at +0x110 */
    msvc_vector_bindcpk_ptr encrypt_list; /* +0x110  vector<int> (IsEncryptCpk accesses +0x110/+0x118) */
    nucc_block_allocator allocator;       /* +0x128  BlockAllocator (param_1+0x25 = +0x128) */
    uint8_t _tail[0x140 - 0x130];        /* +0x130  remaining bytes up to proven size 0x140 */
} nuccCriFsManager;
static_assert(offsetof(nuccCriFsManager, work_buffer) == 0x00, "Manager.work_buffer");
static_assert(offsetof(nuccCriFsManager, work_size) == 0x08, "Manager.work_size");
static_assert(offsetof(nuccCriFsManager, _pad_0c) == 0x0C, "Manager._pad_0c");
static_assert(offsetof(nuccCriFsManager, log_file) == 0x10, "Manager.log_file");
static_assert(offsetof(nuccCriFsManager, binder) == 0x18, "Manager.binder");
static_assert(offsetof(nuccCriFsManager, loaders) == 0x50, "Manager.loaders");
static_assert(offsetof(nuccCriFsManager, encrypt_list) == 0x110, "Manager.encrypt_list");
static_assert(offsetof(nuccCriFsManager, allocator) == 0x128, "Manager.allocator");
static_assert(offsetof(nuccCriFsManager, _tail) == 0x130, "Manager._tail");
static_assert(sizeof(nuccCriFsManager) == 0x140, "Manager size == 0x140 (proven by LoadTh)");

/* ========================================================================
 * nuccCriFsFileMountManager: no instance state
 * All methods are static. FileMount (RVA 0x5C8E80) takes direct params,
 * Finalize (RVA 0x5C8D60) operates on global DAT_140a9fd40,
 * FindByFileName (RVA 0x5C8DC0) traverses tree nodes. No instance struct.
 * ======================================================================== */

#endif /* CMN86_H */