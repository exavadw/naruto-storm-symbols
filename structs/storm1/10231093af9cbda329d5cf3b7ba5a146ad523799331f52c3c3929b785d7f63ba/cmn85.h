/* cmn85.h — CriMvEasyPlayer struct layout for NARUTO STORM 1 PC (s1)
 * INFERRED from static decompilation of NSUNS1.exe (build s1, sha 10231093af9c).
 * Size proven: CriAllocator::operator_new(0x830) in CriMvEasyPlayer::Create (RVA 0x6B110).
 * All offsets derived from x64 PC decompile; names from s1 symbols only.
 */
#ifndef CMN85_H
#define CMN85_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* CriMvEasyPlayer — CRI middleware movie player wrapper.
 * Proven size: 0x830 (2096 bytes) from operator_new call in Create.
 * Vtable at offset 0x00 (CriMvEasyPlayer::vftable).
 */
typedef struct __attribute__((packed)) CriMvEasyPlayer {
    /* 0x000 */ void *vftable;
    /* 0x008 */ void *mvply_handle;
    /* 0x010 */ void *allocator_or_deleter;
    /* 0x018 */ uint32_t field_0x18;
    uint8_t _pad_0x1C[4];
    /* 0x020 */ uint8_t _gap_0x20[0x480];
    /* 0x4A0 */ uint64_t field_0x4A0;
    /* 0x4A8 */ uint8_t _gap_0x4A8[8];
    /* 0x4B0 */ uint32_t field_0x4B0;
    /* 0x4B4 */ uint64_t field_0x4B4;
    /* 0x4BC */ uint8_t _gap_0x4BC[4];
    /* 0x4C0 */ uint64_t field_0x4C0;
    /* 0x4C8 */ uint64_t field_0x4C8;
    /* 0x4D0 */ uint64_t field_0x4D0;
    /* 0x4D8 */ uint64_t field_0x4D8;
    /* 0x4E0 */ uint8_t _gap_0x4E0[0x50];
    /* 0x530 */ uint64_t field_0x530;
    /* 0x538 */ uint64_t field_0x538;
    /* 0x540 */ uint32_t field_0x540;
    /* 0x544 */ uint64_t field_0x544;
    /* 0x54C */ uint64_t field_0x54C;
    /* 0x554 */ uint8_t _gap_0x554[8];
    /* 0x55C */ uint64_t field_0x55C;
    /* 0x564 */ uint32_t audio_track;
    /* 0x568 */ uint8_t _gap_0x568[8];
    /* 0x570 */ uint32_t field_0x570;
    /* 0x574 */ uint32_t field_0x574_array[3];
    /* 0x580 */ uint8_t _gap_0x580[0x48];
    /* 0x5C8 */ uint32_t field_0x5C8;
    /* 0x5CC */ uint8_t _gap_0x5CC[4];
    /* 0x5D0 */ void *field_0x5D0;
    /* 0x5D8 */ void *file_reader;
    /* 0x5E0 */ uint64_t field_0x5E0;
    /* 0x5E8 */ uint32_t field_0x5E8;
    /* 0x5EC */ uint8_t _gap_0x5EC[4];
    /* 0x5F0 */ uint8_t buffer_0x5F0[0x100];
    /* 0x6F0 */ uint64_t field_0x6F0;
    /* 0x6F8 */ uint64_t field_0x6F8;
    /* 0x700 */ uint64_t field_0x700;
    /* 0x708 */ uint32_t field_0x708;
    /* 0x70C */ uint32_t field_0x70C;
    /* 0x710 */ uint8_t _gap_0x710[4];
    /* 0x714 */ uint32_t field_0x714;
    /* 0x718 */ uint64_t field_0x718;
    /* 0x720 */ uint64_t field_0x720;
    /* 0x728 */ uint8_t _gap_0x728[0x10];
    /* 0x738 */ uint32_t field_0x738;
    /* 0x73C */ uint8_t _gap_0x73C[4];
    /* 0x740 */ uint64_t field_0x740;
    /* 0x748 */ uint64_t field_0x748;
    /* 0x750 */ uint64_t field_0x750;
    /* 0x758 */ uint8_t _gap_0x758[0x5C];
    /* 0x7B4 */ uint32_t atomic_destroy_flag;
    /* 0x7B8 */ uint8_t _gap_0x7B8[8];
    /* 0x7C0 */ uint64_t field_0x7C0;
    /* 0x7C8 */ uint64_t field_0x7C8;
    /* 0x7D0 */ uint64_t field_0x7D0;
    /* 0x7D8 */ uint32_t field_0x7D8;
    /* 0x7DC */ uint8_t _gap_0x7DC[4];
    /* 0x7E0 */ void *handle_work;
    /* 0x7E8 */ void *heap_handle;
    /* 0x7F0 */ uint64_t field_0x7F0;
    /* 0x7F8 */ uint8_t _gap_0x7F8[4];
    /* 0x7FC */ uint8_t field_0x7FC;
    uint8_t _pad_0x7FD[3];
    /* 0x800 */ void *critical_section;
    /* 0x808 */ void *cs_work_buffer;
    /* 0x810 */ uint32_t field_0x810;
    /* 0x814 */ uint32_t frame_time_scale;
    /* 0x818 */ uint32_t field_0x818;
    /* 0x81C */ uint32_t field_0x81C;
    /* 0x820 */ uint32_t field_0x820;
    /* 0x824 */ uint32_t field_0x824;
    uint8_t _pad_0x828[8];
} CriMvEasyPlayer;

static_assert(sizeof(CriMvEasyPlayer) == 0x830, "CriMvEasyPlayer size must be 0x830");
static_assert(offsetof(CriMvEasyPlayer, vftable) == 0x000, "vftable @ 0x000");
static_assert(offsetof(CriMvEasyPlayer, mvply_handle) == 0x008, "mvply_handle @ 0x008");
static_assert(offsetof(CriMvEasyPlayer, allocator_or_deleter) == 0x010, "allocator_or_deleter @ 0x010");
static_assert(offsetof(CriMvEasyPlayer, field_0x18) == 0x018, "field_0x18 @ 0x018");
static_assert(offsetof(CriMvEasyPlayer, field_0x4A0) == 0x4A0, "field_0x4A0 @ 0x4A0");
static_assert(offsetof(CriMvEasyPlayer, field_0x4B0) == 0x4B0, "field_0x4B0 @ 0x4B0");
static_assert(offsetof(CriMvEasyPlayer, field_0x4B4) == 0x4B4, "field_0x4B4 @ 0x4B4");
static_assert(offsetof(CriMvEasyPlayer, field_0x4C0) == 0x4C0, "field_0x4C0 @ 0x4C0");
static_assert(offsetof(CriMvEasyPlayer, field_0x4C8) == 0x4C8, "field_0x4C8 @ 0x4C8");
static_assert(offsetof(CriMvEasyPlayer, field_0x4D0) == 0x4D0, "field_0x4D0 @ 0x4D0");
static_assert(offsetof(CriMvEasyPlayer, field_0x4D8) == 0x4D8, "field_0x4D8 @ 0x4D8");
static_assert(offsetof(CriMvEasyPlayer, field_0x530) == 0x530, "field_0x530 @ 0x530");
static_assert(offsetof(CriMvEasyPlayer, field_0x538) == 0x538, "field_0x538 @ 0x538");
static_assert(offsetof(CriMvEasyPlayer, field_0x540) == 0x540, "field_0x540 @ 0x540");
static_assert(offsetof(CriMvEasyPlayer, field_0x544) == 0x544, "field_0x544 @ 0x544");
static_assert(offsetof(CriMvEasyPlayer, field_0x54C) == 0x54C, "field_0x54C @ 0x54C");
static_assert(offsetof(CriMvEasyPlayer, field_0x55C) == 0x55C, "field_0x55C @ 0x55C");
static_assert(offsetof(CriMvEasyPlayer, audio_track) == 0x564, "audio_track @ 0x564");
static_assert(offsetof(CriMvEasyPlayer, field_0x570) == 0x570, "field_0x570 @ 0x570");
static_assert(offsetof(CriMvEasyPlayer, field_0x574_array) == 0x574, "field_0x574_array @ 0x574");
static_assert(offsetof(CriMvEasyPlayer, field_0x5C8) == 0x5C8, "field_0x5C8 @ 0x5C8");
static_assert(offsetof(CriMvEasyPlayer, field_0x5D0) == 0x5D0, "field_0x5D0 @ 0x5D0");
static_assert(offsetof(CriMvEasyPlayer, file_reader) == 0x5D8, "file_reader @ 0x5D8");
static_assert(offsetof(CriMvEasyPlayer, field_0x5E0) == 0x5E0, "field_0x5E0 @ 0x5E0");
static_assert(offsetof(CriMvEasyPlayer, field_0x5E8) == 0x5E8, "field_0x5E8 @ 0x5E8");
static_assert(offsetof(CriMvEasyPlayer, buffer_0x5F0) == 0x5F0, "buffer_0x5F0 @ 0x5F0");
static_assert(offsetof(CriMvEasyPlayer, field_0x6F0) == 0x6F0, "field_0x6F0 @ 0x6F0");
static_assert(offsetof(CriMvEasyPlayer, field_0x6F8) == 0x6F8, "field_0x6F8 @ 0x6F8");
static_assert(offsetof(CriMvEasyPlayer, field_0x700) == 0x700, "field_0x700 @ 0x700");
static_assert(offsetof(CriMvEasyPlayer, field_0x708) == 0x708, "field_0x708 @ 0x708");
static_assert(offsetof(CriMvEasyPlayer, field_0x70C) == 0x70C, "field_0x70C @ 0x70C");
static_assert(offsetof(CriMvEasyPlayer, field_0x714) == 0x714, "field_0x714 @ 0x714");
static_assert(offsetof(CriMvEasyPlayer, field_0x718) == 0x718, "field_0x718 @ 0x718");
static_assert(offsetof(CriMvEasyPlayer, field_0x720) == 0x720, "field_0x720 @ 0x720");
static_assert(offsetof(CriMvEasyPlayer, field_0x738) == 0x738, "field_0x738 @ 0x738");
static_assert(offsetof(CriMvEasyPlayer, field_0x740) == 0x740, "field_0x740 @ 0x740");
static_assert(offsetof(CriMvEasyPlayer, field_0x748) == 0x748, "field_0x748 @ 0x748");
static_assert(offsetof(CriMvEasyPlayer, field_0x750) == 0x750, "field_0x750 @ 0x750");
static_assert(offsetof(CriMvEasyPlayer, atomic_destroy_flag) == 0x7B4, "atomic_destroy_flag @ 0x7B4");
static_assert(offsetof(CriMvEasyPlayer, field_0x7C0) == 0x7C0, "field_0x7C0 @ 0x7C0");
static_assert(offsetof(CriMvEasyPlayer, field_0x7C8) == 0x7C8, "field_0x7C8 @ 0x7C8");
static_assert(offsetof(CriMvEasyPlayer, field_0x7D0) == 0x7D0, "field_0x7D0 @ 0x7D0");
static_assert(offsetof(CriMvEasyPlayer, field_0x7D8) == 0x7D8, "field_0x7D8 @ 0x7D8");
static_assert(offsetof(CriMvEasyPlayer, handle_work) == 0x7E0, "handle_work @ 0x7E0");
static_assert(offsetof(CriMvEasyPlayer, heap_handle) == 0x7E8, "heap_handle @ 0x7E8");
static_assert(offsetof(CriMvEasyPlayer, field_0x7F0) == 0x7F0, "field_0x7F0 @ 0x7F0");
static_assert(offsetof(CriMvEasyPlayer, field_0x7FC) == 0x7FC, "field_0x7FC @ 0x7FC");
static_assert(offsetof(CriMvEasyPlayer, critical_section) == 0x800, "critical_section @ 0x800");
static_assert(offsetof(CriMvEasyPlayer, cs_work_buffer) == 0x808, "cs_work_buffer @ 0x808");
static_assert(offsetof(CriMvEasyPlayer, field_0x810) == 0x810, "field_0x810 @ 0x810");
static_assert(offsetof(CriMvEasyPlayer, frame_time_scale) == 0x814, "frame_time_scale @ 0x814");
static_assert(offsetof(CriMvEasyPlayer, field_0x818) == 0x818, "field_0x818 @ 0x818");
static_assert(offsetof(CriMvEasyPlayer, field_0x81C) == 0x81C, "field_0x81C @ 0x81C");
static_assert(offsetof(CriMvEasyPlayer, field_0x820) == 0x820, "field_0x820 @ 0x820");
static_assert(offsetof(CriMvEasyPlayer, field_0x824) == 0x824, "field_0x824 @ 0x824");

#endif /* CMN85_H */