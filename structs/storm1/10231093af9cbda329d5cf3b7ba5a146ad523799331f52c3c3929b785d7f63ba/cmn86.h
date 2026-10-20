/* cmn86.h — CRI middleware filesystem classes for NARUTO STORM 1 (s1, NSUNS1.exe)
 *
 * All layouts INFERRED from static analysis of x64 decompiled code.
 * Sizes proven from ccFileLoadListForUi::LoadTh size arguments and array strides.
 * Own-game names only (Storm 1 / s1 sources).
 * Image base: 0x140000000
 */

#ifndef CMN86_H
#define CMN86_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types whose internal layout is not reconstructed here */
typedef struct nuccCriFsBindCpk nuccCriFsBindCpk;
typedef struct nuccCriFsBinder nuccCriFsBinder;
typedef struct nuccCriFsLoaderImpl nuccCriFsLoaderImpl;
typedef struct nuccCriFsLoader nuccCriFsLoader;
typedef struct nuccCriFsManager nuccCriFsManager;

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
 * ======================================================================== */
struct nuccCriFsLoaderImpl {
    uint64_t vtable;           /* +0x00  PTR_FUN_1407412b8 */
    uint64_t cri_loader_handle;/* +0x08  criFsLoader handle (set by Create, read by Load/GetStatus/Destroy) */
} __attribute__((packed));
static_assert(offsetof(nuccCriFsLoaderImpl, vtable) == 0x00, "LoaderImpl.vtable");
static_assert(offsetof(nuccCriFsLoaderImpl, cri_loader_handle) == 0x08, "LoaderImpl.cri_loader_handle");

/* ========================================================================
 * nuccCriFsLoader
 * Size: unknown, >= 0x18. Wraps LoaderImpl at +0x08 via composition.
 * Create delegates to LoaderImpl::Create(param_1 + 8).
 * No standalone allocation site found; always accessed through Manager slots.
 * Manager uses stride 0x18 for loader array → sizeof(nuccCriFsLoader) == 0x18.
 * ======================================================================== */
struct nuccCriFsLoader {
    uint64_t vtable;              /* +0x00  (inferred, not directly set in ctor — wrapper may be POD) */
    nuccCriFsLoaderImpl impl;     /* +0x08  embedded LoaderImpl */
} __attribute__((packed));
static_assert(offsetof(nuccCriFsLoader, vtable) == 0x00, "Loader.vtable");
static_assert(offsetof(nuccCriFsLoader, impl) == 0x08, "Loader.impl");
static_assert(sizeof(nuccCriFsLoader) == 0x18, "Loader size == 0x18 (proven by Manager array stride)");

/* ========================================================================
 * nuccCriFsBindCpk
 * Size: 0x58 (proven by ccFileLoadListForUi::LoadTh(0x58,...) in Binder::Bind
 * and Binder::BindDirectory, both at nuccCriFsBinder.cpp).
 * Vtable: PTR_FUN_140744ca0 (set in ctor at RVA 0x52C4F0).
 * ======================================================================== */
struct nuccCriFsBindCpk {
    uint64_t vtable;              /* +0x00  PTR_FUN_140744ca0 */
    uint32_t binder_handle;       /* +0x08  criFsBinder handle (SetPriority/IsBinded read *(u32*)(this+8)) */
    uint32_t _pad_0c;             /* +0x0C  padding */
    uint64_t malloc_buffer;       /* +0x10  allocated work buffer (BindCpk stores malloc result here) */
    uint32_t work_size;           /* +0x18  work buffer size (BindCpk stores size ptr deref here) */
    uint32_t _pad_1c;             /* +0x1C  padding */
    msvc_string cpk_path;         /* +0x20  std::string — BindCpk accesses param_1+0x20 as string */
    uint8_t _tail[0x58 - 0x40];  /* +0x40  remaining bytes up to proven size 0x58 */
} __attribute__((packed));
static_assert(offsetof(nuccCriFsBindCpk, vtable) == 0x00, "BindCpk.vtable");
static_assert(offsetof(nuccCriFsBindCpk, binder_handle) == 0x08, "BindCpk.binder_handle");
static_assert(offsetof(nuccCriFsBindCpk, malloc_buffer) == 0x10, "BindCpk.malloc_buffer");
static_assert(offsetof(nuccCriFsBindCpk, work_size) == 0x18, "BindCpk.work_size");
static_assert(offsetof(nuccCriFsBindCpk, cpk_path) == 0x20, "BindCpk.cpk_path");
static_assert(offsetof(nuccCriFsBindCpk, _pad_0c) == 0x0C, "BindCpk._pad_0c");
static_assert(offsetof(nuccCriFsBindCpk, _pad_1c) == 0x1C, "BindCpk._pad_1c");
static_assert(offsetof(nuccCriFsBindCpk, _tail) == 0x40, "BindCpk._tail");
static_assert(sizeof(nuccCriFsBindCpk) == 0x58, "BindCpk size == 0x58 (proven by LoadTh)");

/* ========================================================================
 * nuccCriFsBinder
 * Size: unknown, >= 0x28. No standalone allocation found; always embedded
 * in nuccCriFsManager at +0x18. Manager size 0x140 constrains it.
 * Vector at param_1+1..param_1+3 (+0x08/+0x10/+0x18), allocator at param_1+4 (+0x20).
 * Ctor reserves 0xe entries in vector.
 * ======================================================================== */
struct nuccCriFsBinder {
    uint64_t null_sentinel;       /* +0x00  set to 0 in ctor, checked before Bind */
    msvc_vector_bindcpk_ptr bind_list; /* +0x08  vector<nuccCriFsBindCpk*> */
    nucc_block_allocator allocator;    /* +0x20  BlockAllocator */
    uint8_t _pad_28[0x38 - 0x28];     /* +0x28  padding to reach 0x38 (embedded size in Manager) */
} __attribute__((packed));
static_assert(offsetof(nuccCriFsBinder, null_sentinel) == 0x00, "Binder.null_sentinel");
static_assert(offsetof(nuccCriFsBinder, bind_list) == 0x08, "Binder.bind_list");
static_assert(offsetof(nuccCriFsBinder, allocator) == 0x20, "Binder.allocator");
static_assert(offsetof(nuccCriFsBinder, _pad_28) == 0x28, "Binder._pad_28");
/* Embedded size in Manager: Binder spans +0x18 to +0x50 = 0x38 bytes */
static_assert(sizeof(nuccCriFsBinder) == 0x38, "Binder embedded size == 0x38 (Manager layout)");

/* ========================================================================
 * nuccCriFsManager
 * Size: 0x140 (proven by ccFileLoadListForUi::LoadTh(0x140,...) in Initialize
 * at RVA 0x4A6690, source file nuccCriFsManager.cpp line 0x9c).
 * Singleton stored in DAT_140884c10.
 * ======================================================================== */
struct nuccCriFsManager {
    uint64_t work_buffer;         /* +0x00  MallocCore result after criFs_CalculateWorkSizeForLibrary */
    uint32_t work_size;           /* +0x08  work size from criFs_CalculateWorkSizeForLibrary */
    uint32_t _pad_0c;             /* +0x0C  padding */
    uint64_t log_file;            /* +0x10  FILE* (checked in dtor with fclose) */
    nuccCriFsBinder binder;       /* +0x18  embedded Binder (ctor called at param_1+3 = +0x18) */
    /* +0x50: array of 8 nuccCriFsLoader entries, stride 0x18 each */
    nuccCriFsLoader loaders[8];   /* +0x50  8 × 0x18 = 0xC0, ends at +0x110 */
    msvc_vector_bindcpk_ptr encrypt_list; /* +0x110  vector (IsEncryptCpk accesses +0x110/+0x118) */
    nucc_block_allocator allocator;       /* +0x128  BlockAllocator (param_1+0x25 = +0x128) */
    uint8_t _tail[0x140 - 0x130];        /* +0x130  remaining bytes up to proven size 0x140 */
} __attribute__((packed));
static_assert(offsetof(nuccCriFsManager, work_buffer) == 0x00, "Manager.work_buffer");
static_assert(offsetof(nuccCriFsManager, work_size) == 0x08, "Manager.work_size");
static_assert(offsetof(nuccCriFsManager, log_file) == 0x10, "Manager.log_file");
static_assert(offsetof(nuccCriFsManager, binder) == 0x18, "Manager.binder");
static_assert(offsetof(nuccCriFsManager, loaders) == 0x50, "Manager.loaders");
static_assert(offsetof(nuccCriFsManager, encrypt_list) == 0x110, "Manager.encrypt_list");
static_assert(offsetof(nuccCriFsManager, allocator) == 0x128, "Manager.allocator");
static_assert(offsetof(nuccCriFsManager, _pad_0c) == 0x0C, "Manager._pad_0c");
static_assert(offsetof(nuccCriFsManager, _tail) == 0x130, "Manager._tail");
static_assert(sizeof(nuccCriFsManager) == 0x140, "Manager size == 0x140 (proven by LoadTh)");

/* ========================================================================
 * nuccCriFsFileMountManager: no instance state
 * All methods are static. FileMount (RVA 0x483520) takes direct params,
 * Finalize (RVA 0x4F8A70) operates on global DAT_1408c7c20,
 * FindByFileName (RVA 0x4F8B00) traverses tree nodes. No this pointer used.
 * ======================================================================== */

#endif /* CMN86_H */