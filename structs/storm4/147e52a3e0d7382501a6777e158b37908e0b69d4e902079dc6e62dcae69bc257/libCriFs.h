/* libCriFs.h — CRIWARE middleware structs for NARUTO STORM 4 PC 1.09 (s4, NSUNS4_release.exe)
 * Reconstructed from x64 decompile + the decompiler cache state_surface.
 * All fields INFERRED from static analysis unless noted CONFIRMED.
 * Rollback tag: PRES (CRI state preserved across resim; not simulation-fed).
 * Build: s4 SHA: 147e52a3e0d7 Image base: 0x140000000
 */
#ifndef LIBCRIFS_S4_H
#define LIBCRIFS_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * CriMvEasyPlayer — movie player handle (size 0x830 proven)
 * Evidence: CriAllocator::operator_new(0x830, uVar3, "CriMvEasyPlayer", 4)
 *           in Create (RVA 0x6B780)
 * Vtable: CriMvEasyPlayer::vftable at offset 0x0
 * Field offsets from two sources:
 *   Create: puVar4[N] as undefined8* => byte offset N*8
 *   initializeHandleParameters (RVA 0x6F000): byte-offset writes
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x000 */ void     *vftable;            /* *puVar4 = CriMvEasyPlayer::vftable */
    /* 0x008 */ void     *movie_handle;       /* puVar4[1]: criMvPly_CreateWithWork result */
    /* 0x010 */ uint64_t  reserved_0x10;      /* puVar4[2]: initialized 0 */
    /* 0x018 */ uint32_t  init_flag;          /* initParams: *(u4*)(p+0x18)=0 */
    uint8_t _pad_0x01C[0x4A0 - 0x01C];       /* gap to first initParams qword */
    /* 0x4A0 */ uint64_t  handle_param_4a0;   /* initParams: *(u8*)(p+0x4a0)=1 */
    /* 0x4A8 */ uint64_t  reserved_4a8;       /* gap (no evidence) */
    /* 0x4B0 */ uint32_t  handle_param_4b0;   /* initParams: *(u4*)(p+0x4b0)=0 */
    uint8_t _pad_0x4B4[0x4B4 - 0x4B4];       /* zero-width placeholder */
    /* 0x4B4 */ uint64_t  handle_param_4b4;   /* initParams: *(u8*)(p+0x4b4)=1 */
    /* 0x4BC */ uint32_t  reserved_4bc;       /* gap */
    /* 0x4C0 */ uint64_t  handle_param_4c0;   /* initParams: *(u8*)(p+0x4c0)=0 */
    /* 0x4C8 */ uint64_t  handle_param_4c8;   /* initParams: *(u8*)(p+0x4c8)=1 */
    /* 0x4D0 */ uint64_t  handle_param_4d0;   /* initParams: *(u8*)(p+0x4d0)=0 */
    /* 0x4D8 */ uint64_t  handle_param_4d8;   /* initParams: *(u8*)(p+0x4d8)=~0ULL */
    uint8_t _pad_0x4E0[0x530 - 0x4E0];       /* gap */
    /* 0x530 */ uint64_t  handle_param_530;   /* initParams: *(u8*)(p+0x530)=0 */
    /* 0x538 */ uint64_t  handle_param_538;   /* initParams: *(u8*)(p+0x538)=0 */
    /* 0x540 */ uint32_t  handle_param_540;   /* initParams: *(u4*)(p+0x540)=0xFFFFFFFF */
    uint8_t _pad_0x544[0x544 - 0x544];       /* zero-width */
    /* 0x544 */ uint64_t  handle_param_544;   /* initParams: *(u8*)(p+0x544)=0 */
    /* 0x54C */ uint64_t  handle_param_54c;   /* initParams: *(u8*)(p+0x54c)=0 */
    uint8_t _pad_0x554[0x55C - 0x554];       /* gap */
    /* 0x55C */ uint64_t  handle_param_55c;   /* initParams: *(u8*)(p+0x55c)=~0ULL */
    /* 0x564 */ uint32_t  audio_track;        /* initParams: *(u4*)(p+0x564)=100 */
    uint8_t _pad_0x568[0x56C - 0x568];       /* gap */
    /* 0x56C */ uint32_t  handle_param_56c;   /* loop: puVar1[-3]=0xFFFFFFFF */
    /* 0x570 */ uint32_t  handle_param_570;   /* initParams: *(u4*)(p+0x570)=0xFFFFFFFF */
    /* 0x574 */ uint32_t  handle_param_574;   /* loop: *puVar1=0xFFFFFFFF */
    /* 0x578 */ uint32_t  handle_param_578;   /* loop: puVar1[1] after increment */
    /* 0x57C */ uint32_t  handle_param_57c;   /* initParams: *(u4*)(p+0x57c)=0xFFFFFFFF */
    uint8_t _pad_0x580[0x5C8 - 0x580];       /* gap */
    /* 0x5C8 */ uint32_t  handle_param_5c8;   /* initParams: *(u4*)(p+0x5c8)=0 */
    uint8_t _pad_0x5CC[0x5D0 - 0x5CC];       /* gap */
    /* 0x5D0 */ void     *reader_factory;     /* puVar4[0xba]: param_4 */
    /* 0x5D8 */ void     *file_reader_mem;    /* puVar4[0xbb]: CriMvEasyFileReaderMem::Create */
    /* 0x5E0 */ uint64_t  handle_param_5e0;   /* initParams: *(u8*)(p+0x5e0)=1 */
    /* 0x5E8 */ uint32_t  handle_param_5e8;   /* initParams: *(u4*)(p+0x5e8)=0 */
    uint8_t _pad_0x5EC[0x5F0 - 0x5EC];       /* gap */
    /* 0x5F0 */ uint8_t   handle_buf_5f0[0x100]; /* memset(p+0x5f0, 0, 0x100) */
    /* 0x6F0 */ uint64_t  handle_param_6f0;   /* initParams: *(u8*)(p+0x6f0)=0 */
    /* 0x6F8 */ uint64_t  handle_param_6f8;   /* initParams: *(u8*)(p+0x6f8)=~0ULL */
    /* 0x700 */ uint64_t  handle_param_700;   /* initParams: *(u8*)(p+0x700)=0 */
    /* 0x708 */ uint32_t  handle_param_708;   /* initParams: *(u4*)(p+0x708)=0 */
    /* 0x70C */ uint32_t  handle_param_70c;   /* initParams: *(u4*)(p+0x70c)=0 */
    uint8_t _pad_0x710[0x714 - 0x710];       /* gap */
    /* 0x714 */ uint32_t  handle_param_714;   /* initParams: *(u4*)(p+0x714)=0 */
    uint8_t _pad_0x718[0x718 - 0x718];       /* zero-width */
    /* 0x718 */ uint64_t  handle_param_718;   /* initParams: *(u8*)(p+0x718)=0 */
    /* 0x720 */ uint64_t  handle_param_720;   /* initParams: *(u8*)(p+0x720)=0 */
    uint8_t _pad_0x728[0x738 - 0x728];       /* gap */
    /* 0x738 */ uint32_t  handle_param_738;   /* initParams: *(u4*)(p+0x738)=0 */
    uint8_t _pad_0x73C[0x740 - 0x73C];       /* gap */
    /* 0x740 */ uint64_t  handle_param_740;   /* initParams: *(u8*)(p+0x740)=0 */
    /* 0x748 */ uint64_t  handle_param_748;   /* initParams: *(u8*)(p+0x748)=0 */
    /* 0x750 */ uint64_t  handle_param_750;   /* initParams: *(u8*)(p+0x750)=0 */
    uint8_t _pad_0x758[0x7C0 - 0x758];       /* gap */
    /* 0x7C0 */ uint64_t  handle_param_7c0;   /* initParams: *(u8*)(p+0x7c0)=0 */
    /* 0x7C8 */ uint64_t  handle_param_7c8;   /* initParams: *(u8*)(p+0x7c8)=0 */
    /* 0x7D0 */ uint64_t  handle_param_7d0;   /* initParams: *(u8*)(p+2000)=0 (2000=0x7d0) */
    /* 0x7D8 */ uint32_t  handle_param_7d8;   /* initParams: *(u4*)(p+0x7d8)=0 */
    uint8_t _pad_0x7DC[0x7E0 - 0x7DC];       /* gap */
    /* 0x7E0 */ void     *file_reader;        /* puVar4[0xfc]: criFixedAllocator_Allocate */
    /* 0x7E8 */ void     *work_buffer;        /* puVar4[0xfd]: allocator work ptr (uVar3) */
    /* 0x7F0 */ uint64_t  handle_param_7f0;   /* initParams: *(u8*)(p+0x7f0)=0 */
    uint8_t _pad_0x7F8[0x7FC - 0x7F8];       /* gap */
    /* 0x7FC */ uint8_t   handle_param_7fc;   /* initParams: *(u1*)(p+0x7fc)=0 */
    uint8_t _pad_0x7FD[0x800 - 0x7FD];       /* gap */
    /* 0x800 */ void     *allocator_work;     /* puVar4[0x100]: thunk_criCs_Create result */
    /* 0x808 */ void     *allocator_info;     /* puVar4[0x101]: lVar5 info ptr */
    /* 0x810 */ uint32_t  handle_param_810;   /* initParams: *(u4*)(p+0x810)=0 */
    /* 0x814 */ uint32_t  handle_param_814;   /* initParams: *(u4*)(p+0x814)=0x3f800000 (1.0f) */
    /* 0x818 */ uint32_t  handle_param_818;   /* initParams: *(u4*)(p+0x818)=0x40accccd (~5.4f) */
    /* 0x81C */ uint32_t  handle_param_81c;   /* initParams: *(u4*)(p+0x81c)=0x3f800000 (1.0f) */
    /* 0x820 */ uint32_t  handle_param_820;   /* initParams: *(u4*)(p+0x820)=0x3f800000 (1.0f) */
    /* 0x824 */ uint32_t  handle_param_824;   /* initParams: *(u4*)(p+0x824)=0 */
    uint8_t _pad_0x828[0x830 - 0x828];       /* trailing pad to proven size */
} CriMvEasyPlayer;

static_assert(sizeof(CriMvEasyPlayer) == 0x830, "CriMvEasyPlayer size must be 0x830");
static_assert(offsetof(CriMvEasyPlayer, vftable) == 0x000, "vftable at 0x0");
static_assert(offsetof(CriMvEasyPlayer, movie_handle) == 0x008, "movie_handle at 0x8");
static_assert(offsetof(CriMvEasyPlayer, reserved_0x10) == 0x010, "reserved_0x10 at 0x10");
static_assert(offsetof(CriMvEasyPlayer, init_flag) == 0x018, "init_flag at 0x18");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4a0) == 0x4A0, "handle_param_4a0 at 0x4a0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4b0) == 0x4B0, "handle_param_4b0 at 0x4b0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4b4) == 0x4B4, "handle_param_4b4 at 0x4b4");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4c0) == 0x4C0, "handle_param_4c0 at 0x4c0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4c8) == 0x4C8, "handle_param_4c8 at 0x4c8");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4d0) == 0x4D0, "handle_param_4d0 at 0x4d0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_4d8) == 0x4D8, "handle_param_4d8 at 0x4d8");
static_assert(offsetof(CriMvEasyPlayer, handle_param_530) == 0x530, "handle_param_530 at 0x530");
static_assert(offsetof(CriMvEasyPlayer, handle_param_538) == 0x538, "handle_param_538 at 0x538");
static_assert(offsetof(CriMvEasyPlayer, handle_param_540) == 0x540, "handle_param_540 at 0x540");
static_assert(offsetof(CriMvEasyPlayer, handle_param_544) == 0x544, "handle_param_544 at 0x544");
static_assert(offsetof(CriMvEasyPlayer, handle_param_54c) == 0x54C, "handle_param_54c at 0x54c");
static_assert(offsetof(CriMvEasyPlayer, handle_param_55c) == 0x55C, "handle_param_55c at 0x55c");
static_assert(offsetof(CriMvEasyPlayer, audio_track) == 0x564, "audio_track at 0x564");
static_assert(offsetof(CriMvEasyPlayer, handle_param_56c) == 0x56C, "handle_param_56c at 0x56c");
static_assert(offsetof(CriMvEasyPlayer, handle_param_570) == 0x570, "handle_param_570 at 0x570");
static_assert(offsetof(CriMvEasyPlayer, handle_param_574) == 0x574, "handle_param_574 at 0x574");
static_assert(offsetof(CriMvEasyPlayer, handle_param_578) == 0x578, "handle_param_578 at 0x578");
static_assert(offsetof(CriMvEasyPlayer, handle_param_57c) == 0x57C, "handle_param_57c at 0x57c");
static_assert(offsetof(CriMvEasyPlayer, handle_param_5c8) == 0x5C8, "handle_param_5c8 at 0x5c8");
static_assert(offsetof(CriMvEasyPlayer, reader_factory) == 0x5D0, "reader_factory at 0x5d0");
static_assert(offsetof(CriMvEasyPlayer, file_reader_mem) == 0x5D8, "file_reader_mem at 0x5d8");
static_assert(offsetof(CriMvEasyPlayer, handle_param_5e0) == 0x5E0, "handle_param_5e0 at 0x5e0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_5e8) == 0x5E8, "handle_param_5e8 at 0x5e8");
static_assert(offsetof(CriMvEasyPlayer, handle_buf_5f0) == 0x5F0, "handle_buf_5f0 at 0x5f0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_6f0) == 0x6F0, "handle_param_6f0 at 0x6f0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_6f8) == 0x6F8, "handle_param_6f8 at 0x6f8");
static_assert(offsetof(CriMvEasyPlayer, handle_param_700) == 0x700, "handle_param_700 at 0x700");
static_assert(offsetof(CriMvEasyPlayer, handle_param_708) == 0x708, "handle_param_708 at 0x708");
static_assert(offsetof(CriMvEasyPlayer, handle_param_70c) == 0x70C, "handle_param_70c at 0x70c");
static_assert(offsetof(CriMvEasyPlayer, handle_param_714) == 0x714, "handle_param_714 at 0x714");
static_assert(offsetof(CriMvEasyPlayer, handle_param_718) == 0x718, "handle_param_718 at 0x718");
static_assert(offsetof(CriMvEasyPlayer, handle_param_720) == 0x720, "handle_param_720 at 0x720");
static_assert(offsetof(CriMvEasyPlayer, handle_param_738) == 0x738, "handle_param_738 at 0x738");
static_assert(offsetof(CriMvEasyPlayer, handle_param_740) == 0x740, "handle_param_740 at 0x740");
static_assert(offsetof(CriMvEasyPlayer, handle_param_748) == 0x748, "handle_param_748 at 0x748");
static_assert(offsetof(CriMvEasyPlayer, handle_param_750) == 0x750, "handle_param_750 at 0x750");
static_assert(offsetof(CriMvEasyPlayer, handle_param_7c0) == 0x7C0, "handle_param_7c0 at 0x7c0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_7c8) == 0x7C8, "handle_param_7c8 at 0x7c8");
static_assert(offsetof(CriMvEasyPlayer, handle_param_7d0) == 0x7D0, "handle_param_7d0 at 0x7d0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_7d8) == 0x7D8, "handle_param_7d8 at 0x7d8");
static_assert(offsetof(CriMvEasyPlayer, file_reader) == 0x7E0, "file_reader at 0x7e0");
static_assert(offsetof(CriMvEasyPlayer, work_buffer) == 0x7E8, "work_buffer at 0x7e8");
static_assert(offsetof(CriMvEasyPlayer, handle_param_7f0) == 0x7F0, "handle_param_7f0 at 0x7f0");
static_assert(offsetof(CriMvEasyPlayer, handle_param_7fc) == 0x7FC, "handle_param_7fc at 0x7fc");
static_assert(offsetof(CriMvEasyPlayer, allocator_work) == 0x800, "allocator_work at 0x800");
static_assert(offsetof(CriMvEasyPlayer, allocator_info) == 0x808, "allocator_info at 0x808");
static_assert(offsetof(CriMvEasyPlayer, handle_param_810) == 0x810, "handle_param_810 at 0x810");
static_assert(offsetof(CriMvEasyPlayer, handle_param_814) == 0x814, "handle_param_814 at 0x814");
static_assert(offsetof(CriMvEasyPlayer, handle_param_818) == 0x818, "handle_param_818 at 0x818");
static_assert(offsetof(CriMvEasyPlayer, handle_param_81c) == 0x81C, "handle_param_81c at 0x81c");
static_assert(offsetof(CriMvEasyPlayer, handle_param_820) == 0x820, "handle_param_820 at 0x820");
static_assert(offsetof(CriMvEasyPlayer, handle_param_824) == 0x824, "handle_param_824 at 0x824");

/* =========================================================================
 * CriMvEasyFileReaderMem — in-memory file reader (size unknown, >= 0x248)
 * Evidence: state_surface shows vtable deref at *(param_1+0x48)+0x240 in Destroy
 *           Create allocates via CriAllocator but size arg not captured in decomp.
 *           s3 had proven size 0x48; s4 vtable access at offset 0x240 implies >= 0x248.
 * Vtable: CriMvEasyFileReaderMem::vftable at offset 0x0
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    /* 0x00 */ void    *vftable;              /* CriMvEasyFileReaderMem::vftable */
    uint8_t _pad_0x08[0x248 - 0x08];         /* gap — size unproven beyond vtable access */
} CriMvEasyFileReaderMem;

/* Size NOT asserted: only lower bound 0x248 proven from vtable+0x240 access in Destroy.
 * static_assert(sizeof(CriMvEasyFileReaderMem) == ..., "..."); — omitted, size unknown.
 */
static_assert(offsetof(CriMvEasyFileReaderMem, vftable) == 0x00, "vftable at 0x0");

#endif /* LIBCRIFS_S4_H */