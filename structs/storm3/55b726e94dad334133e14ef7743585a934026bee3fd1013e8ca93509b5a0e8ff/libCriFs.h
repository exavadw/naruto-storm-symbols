/* libCriFs.h — CRIWARE middleware structs for NARUTO STORM 3 Full Burst HD PC (s3, NSUNS3.exe)
 * Reconstructed from x64 decompile + the decompiler cache state_surface.
 * All fields INFERRED from static analysis unless noted CONFIRMED.
 * Rollback tag: PRES (CRI state preserved across resim; not simulation-fed).
 * Build: s3  SHA: 55b726e94dad  Image base: 0x140000000
 */
#ifndef LIBCRIFS_S3_H
#define LIBCRIFS_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * CriMvEasyPlayer — movie player handle (size 0x830 proven)
 * Evidence: FUN_1400a9528(0x830, uVar3, "CriMvEasyPlayer", 4)
 *           in Create (RVA 0x6B230)
 * Vtable: CriMvEasyPlayer::vftable at offset 0x0
 * Field offsets derived from qword-indexed assignments in Create decompile:
 *   puVar4[N] as undefined8* => byte offset N*8
 *   *(undefined4*)(puVar4+0x6a) => byte offset 0x6a*8 = 0x350
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x000 */ void    *vftable;           /* *puVar4 = CriMvEasyPlayer::vftable */
    /* 0x008 */ void    *movie_handle;      /* puVar4[1]: criMvPly_CreateWithWork result */
    /* 0x010 */ uint64_t reserved_0x10;     /* puVar4[2]: initialized 0 */
    uint8_t _pad_0x018[0x350 - 0x018];     /* gap to status field */
    /* 0x350 */ uint32_t status;            /* *(uint32*)(puVar4+0x6a): set 0 in Create */
    uint8_t _pad_0x354[0x478 - 0x354];     /* gap to config_ptr */
    /* 0x478 */ void    *config_ptr;        /* puVar4[0x8f]: param_4 */
    /* 0x480 */ void    *callback_ptr;      /* puVar4[0x90]: param_6 */
    /* 0x488 */ uint64_t reserved_0x488;    /* puVar4[0x91]: set 0 */
    /* 0x490 */ uint64_t reserved_0x490;    /* puVar4[0x92]: set 0 */
    /* 0x498 */ void    *user_data;         /* puVar4[0x93]: param_5 */
    uint8_t _pad_0x4A0[0x5D0 - 0x4A0];     /* gap to reader_factory */
    /* 0x5D0 */ void    *reader_factory;    /* puVar4[0xba]: param_4 (factory ptr) */
    /* 0x5D8 */ void    *file_reader_mem;   /* puVar4[0xbb]: CriMvEasyFileReaderMem::Create result */
    uint8_t _pad_0x5E0[0x7E0 - 0x5E0];     /* gap to file_reader */
    /* 0x7E0 */ void    *file_reader;       /* puVar4[0xfc]: criFixedAllocator_Allocate result */
    /* 0x7E8 */ void    *work_buffer;       /* puVar4[0xfd]: allocator work ptr (uVar3) */
    uint8_t _pad_0x7F0[0x800 - 0x7F0];     /* gap to allocator_work */
    /* 0x800 */ void    *allocator_work;    /* puVar4[0x100]: thunk_criCs_Create result */
    /* 0x808 */ void    *allocator_info;    /* puVar4[0x101]: lVar5 info ptr */
    uint8_t _pad_0x810[0x830 - 0x810];     /* trailing pad to proven size */
} CriMvEasyPlayer;

static_assert(sizeof(CriMvEasyPlayer) == 0x830, "CriMvEasyPlayer size must be 0x830");
static_assert(offsetof(CriMvEasyPlayer, vftable) == 0x000, "vftable at 0x0");
static_assert(offsetof(CriMvEasyPlayer, movie_handle) == 0x008, "movie_handle at 0x8");
static_assert(offsetof(CriMvEasyPlayer, reserved_0x10) == 0x010, "reserved_0x10 at 0x10");
static_assert(offsetof(CriMvEasyPlayer, status) == 0x350, "status at 0x350");
static_assert(offsetof(CriMvEasyPlayer, config_ptr) == 0x478, "config_ptr at 0x478");
static_assert(offsetof(CriMvEasyPlayer, callback_ptr) == 0x480, "callback_ptr at 0x480");
static_assert(offsetof(CriMvEasyPlayer, reserved_0x488) == 0x488, "reserved_0x488 at 0x488");
static_assert(offsetof(CriMvEasyPlayer, reserved_0x490) == 0x490, "reserved_0x490 at 0x490");
static_assert(offsetof(CriMvEasyPlayer, user_data) == 0x498, "user_data at 0x498");
static_assert(offsetof(CriMvEasyPlayer, reader_factory) == 0x5D0, "reader_factory at 0x5D0");
static_assert(offsetof(CriMvEasyPlayer, file_reader_mem) == 0x5D8, "file_reader_mem at 0x5D8");
static_assert(offsetof(CriMvEasyPlayer, file_reader) == 0x7E0, "file_reader at 0x7E0");
static_assert(offsetof(CriMvEasyPlayer, work_buffer) == 0x7E8, "work_buffer at 0x7E8");
static_assert(offsetof(CriMvEasyPlayer, allocator_work) == 0x800, "allocator_work at 0x800");
static_assert(offsetof(CriMvEasyPlayer, allocator_info) == 0x808, "allocator_info at 0x808");

/* =========================================================================
 * CriMvEasyFileReaderMem — in-memory file reader (size 0x48 proven)
 * Evidence: FUN_1400a9528(0x48, param_1, "CriMvEasyFileReaderMem")
 *           in Create (RVA 0x7CD30)
 * Vtable: CriMvEasyFileReaderMem::vftable at offset 0x0 (duplicated at 0x8)
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void    *vftable;             /* CriMvEasyFileReaderMem::vftable */
    /* 0x08 */ void    *vftable_or_refcount; /* puVar1[1]: same vftable or secondary iface */
    /* 0x10 */ uint64_t zero_init;           /* puVar1[2]: 0 */
    /* 0x18 */ uint64_t sentinel;            /* puVar1[3]: 0xFFFFFFFFFFFFFFFF */
    /* 0x20 */ void    *parent_work;         /* puVar1[4]: param_1 (work buffer ptr) */
    /* 0x28 */ uint64_t reserved_0x28;       /* puVar1[5]: 0 */
    /* 0x30 */ uint64_t reserved_0x30;       /* puVar1[6]: 0 */
    /* 0x38 */ uint64_t reserved_0x38;       /* puVar1[7]: 0 */
    /* 0x40 */ uint32_t flags;               /* *(uint32*)(puVar1+8): 0 */
    uint8_t _pad_0x44[0x48 - 0x44];         /* trailing pad to proven size */
} CriMvEasyFileReaderMem;

static_assert(sizeof(CriMvEasyFileReaderMem) == 0x48, "CriMvEasyFileReaderMem size must be 0x48");
static_assert(offsetof(CriMvEasyFileReaderMem, vftable) == 0x00, "vftable at 0x0");
static_assert(offsetof(CriMvEasyFileReaderMem, vftable_or_refcount) == 0x08, "vftable_or_refcount at 0x8");
static_assert(offsetof(CriMvEasyFileReaderMem, zero_init) == 0x10, "zero_init at 0x10");
static_assert(offsetof(CriMvEasyFileReaderMem, sentinel) == 0x18, "sentinel at 0x18");
static_assert(offsetof(CriMvEasyFileReaderMem, parent_work) == 0x20, "parent_work at 0x20");
static_assert(offsetof(CriMvEasyFileReaderMem, reserved_0x28) == 0x28, "reserved_0x28 at 0x28");
static_assert(offsetof(CriMvEasyFileReaderMem, reserved_0x30) == 0x30, "reserved_0x30 at 0x30");
static_assert(offsetof(CriMvEasyFileReaderMem, reserved_0x38) == 0x38, "reserved_0x38 at 0x38");
static_assert(offsetof(CriMvEasyFileReaderMem, flags) == 0x40, "flags at 0x40");

#endif /* LIBCRIFS_S3_H */