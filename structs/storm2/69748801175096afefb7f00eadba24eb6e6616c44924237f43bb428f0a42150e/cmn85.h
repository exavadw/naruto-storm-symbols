#ifndef CMN85_S2_H
#define CMN85_S2_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* CriMvEasyPlayer — NARUTO STORM 2 PC (s2, NSUNS2.exe)
 * Proven size: 0x830 (CriAllocator::operator_new(0x830,...) in Create RVA 0x6B110)
 * INFERRED from static analysis only. Not CONFIRMED at runtime.
 * CRI Movie Ver.4.05.04 middleware wrapper.
 */
typedef struct __attribute__((packed)) CriMvEasyPlayer_s2 {
 void* vftable; /* 0x000 [PRES] */
 void* mvply_handle; /* 0x008 [SIM] */
 void* allocator_or_deleter; /* 0x010 [PRES] */
 uint32_t field_0x18; /* 0x018 [UNKNOWN] */
 uint8_t _pad_0x01C[820]; /* gap 0x01C..0x34F */
 uint32_t field_0x350; /* 0x350 [UNKNOWN] */
 uint8_t _pad_0x354[292]; /* gap 0x354..0x477 */
 void* field_0x478; /* 0x478 [PRES] */
 void* field_0x480; /* 0x480 [PRES] */
 void* field_0x488; /* 0x488 [PRES] */
 void* field_0x490; /* 0x490 [PRES] */
 void* field_0x498; /* 0x498 [PRES] */
 uint64_t field_0x4A0; /* 0x4A0 [UNKNOWN] */
 uint8_t _pad_0x4A8[8]; /* gap 0x4A8..0x4AF */
 uint32_t field_0x4B0; /* 0x4B0 [UNKNOWN] */
 uint64_t field_0x4B4; /* 0x4B4 [UNKNOWN] */
 uint8_t _pad_0x4BC[4]; /* gap 0x4BC..0x4BF */
 uint64_t field_0x4C0; /* 0x4C0 [UNKNOWN] */
 uint64_t field_0x4C8; /* 0x4C8 [UNKNOWN] */
 uint64_t field_0x4D0; /* 0x4D0 [UNKNOWN] */
 uint64_t field_0x4D8; /* 0x4D8 [UNKNOWN] */
 uint8_t _pad_0x4E0[80]; /* gap 0x4E0..0x52F */
 uint64_t field_0x530; /* 0x530 [UNKNOWN] */
 uint64_t field_0x538; /* 0x538 [UNKNOWN] */
 uint32_t field_0x540; /* 0x540 [UNKNOWN] */
 uint64_t field_0x544; /* 0x544 [UNKNOWN] */
 uint64_t field_0x54C; /* 0x54C [UNKNOWN] */
 uint8_t _pad_0x554[8]; /* gap 0x554..0x55B */
 uint64_t field_0x55C; /* 0x55C [UNKNOWN] */
 uint32_t audio_track; /* 0x564 [SIM] */
 uint8_t _pad_0x568[8]; /* gap 0x568..0x56F */
 uint32_t field_0x570; /* 0x570 [UNKNOWN] */
 uint32_t field_0x574_array[3]; /* 0x574 [UNKNOWN] */
 uint8_t _pad_0x580[72]; /* gap 0x580..0x5C7 */
 uint32_t field_0x5C8; /* 0x5C8 [UNKNOWN] */
 uint8_t _pad_0x5CC[4]; /* gap 0x5CC..0x5CF */
 void* field_0x5D0; /* 0x5D0 [PRES] */
 void* file_reader; /* 0x5D8 [SIM] */
 uint64_t field_0x5E0; /* 0x5E0 [UNKNOWN] */
 uint32_t field_0x5E8; /* 0x5E8 [UNKNOWN] */
 uint8_t _pad_0x5EC[4]; /* gap 0x5EC..0x5EF */
 uint8_t buffer_0x5F0[0x100]; /* 0x5F0 [UNKNOWN] */
 uint64_t field_0x6F0; /* 0x6F0 [UNKNOWN] */
 uint64_t field_0x6F8; /* 0x6F8 [UNKNOWN] */
 uint64_t field_0x700; /* 0x700 [UNKNOWN] */
 uint32_t field_0x708; /* 0x708 [UNKNOWN] */
 uint32_t field_0x70C; /* 0x70C [UNKNOWN] */
 uint8_t _pad_0x710[4]; /* gap 0x710..0x713 */
 uint32_t field_0x714; /* 0x714 [UNKNOWN] */
 uint64_t field_0x718; /* 0x718 [UNKNOWN] */
 uint64_t field_0x720; /* 0x720 [UNKNOWN] */
 uint8_t _pad_0x728[16]; /* gap 0x728..0x737 */
 uint32_t field_0x738; /* 0x738 [UNKNOWN] */
 uint8_t _pad_0x73C[4]; /* gap 0x73C..0x73F */
 uint64_t field_0x740; /* 0x740 [UNKNOWN] */
 uint64_t field_0x748; /* 0x748 [UNKNOWN] */
 uint64_t field_0x750; /* 0x750 [UNKNOWN] */
 uint8_t _pad_0x758[92]; /* gap 0x758..0x7B3 */
 uint32_t atomic_destroy_flag; /* 0x7B4 [SIM] */
 uint8_t _pad_0x7B8[8]; /* gap 0x7B8..0x7BF */
 uint64_t field_0x7C0; /* 0x7C0 [UNKNOWN] */
 uint64_t field_0x7C8; /* 0x7C8 [UNKNOWN] */
 uint64_t field_0x7D0; /* 0x7D0 [UNKNOWN] */
 uint32_t field_0x7D8; /* 0x7D8 [UNKNOWN] */
 uint8_t _pad_0x7DC[4]; /* gap 0x7DC..0x7DF */
 void* handle_work; /* 0x7E0 [SIM] */
 void* heap_handle; /* 0x7E8 [SIM] */
 uint64_t field_0x7F0; /* 0x7F0 [UNKNOWN] */
 uint8_t _pad_0x7F8[4]; /* gap 0x7F8..0x7FB */
 uint8_t field_0x7FC; /* 0x7FC [UNKNOWN] */
 uint8_t _pad_0x7FD[3]; /* gap 0x7FD..0x7FF */
 void* critical_section; /* 0x800 [SIM] */
 void* cs_work_buffer; /* 0x808 [SIM] */
 uint32_t field_0x810; /* 0x810 [UNKNOWN] */
 uint32_t frame_time_scale; /* 0x814 [PRES] */
 uint32_t field_0x818; /* 0x818 [PRES] */
 uint32_t field_0x81C; /* 0x81C [PRES] */
 uint32_t field_0x820; /* 0x820 [PRES] */
 uint32_t field_0x824; /* 0x824 [PRES] */
 uint8_t _pad_0x828[8]; /* tail pad to 0x830 */
} CriMvEasyPlayer_s2;

/* Offset assertions */
static_assert(offsetof(CriMvEasyPlayer_s2, vftable) == 0x000, "vftable offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, mvply_handle) == 0x008, "mvply_handle offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, allocator_or_deleter) == 0x010, "allocator_or_deleter offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x18) == 0x018, "field_0x18 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x350) == 0x350, "field_0x350 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x478) == 0x478, "field_0x478 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x480) == 0x480, "field_0x480 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x488) == 0x488, "field_0x488 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x490) == 0x490, "field_0x490 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x498) == 0x498, "field_0x498 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4A0) == 0x4A0, "field_0x4A0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4B0) == 0x4B0, "field_0x4B0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4B4) == 0x4B4, "field_0x4B4 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4C0) == 0x4C0, "field_0x4C0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4C8) == 0x4C8, "field_0x4C8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4D0) == 0x4D0, "field_0x4D0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x4D8) == 0x4D8, "field_0x4D8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x530) == 0x530, "field_0x530 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x538) == 0x538, "field_0x538 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x540) == 0x540, "field_0x540 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x544) == 0x544, "field_0x544 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x54C) == 0x54C, "field_0x54C offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x55C) == 0x55C, "field_0x55C offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, audio_track) == 0x564, "audio_track offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x570) == 0x570, "field_0x570 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x574_array) == 0x574, "field_0x574_array offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x5C8) == 0x5C8, "field_0x5C8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x5D0) == 0x5D0, "field_0x5D0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, file_reader) == 0x5D8, "file_reader offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x5E0) == 0x5E0, "field_0x5E0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x5E8) == 0x5E8, "field_0x5E8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, buffer_0x5F0) == 0x5F0, "buffer_0x5F0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x6F0) == 0x6F0, "field_0x6F0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x6F8) == 0x6F8, "field_0x6F8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x700) == 0x700, "field_0x700 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x708) == 0x708, "field_0x708 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x70C) == 0x70C, "field_0x70C offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x714) == 0x714, "field_0x714 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x718) == 0x718, "field_0x718 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x720) == 0x720, "field_0x720 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x738) == 0x738, "field_0x738 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x740) == 0x740, "field_0x740 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x748) == 0x748, "field_0x748 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x750) == 0x750, "field_0x750 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, atomic_destroy_flag) == 0x7B4, "atomic_destroy_flag offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x7C0) == 0x7C0, "field_0x7C0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x7C8) == 0x7C8, "field_0x7C8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x7D0) == 0x7D0, "field_0x7D0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x7D8) == 0x7D8, "field_0x7D8 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, handle_work) == 0x7E0, "handle_work offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, heap_handle) == 0x7E8, "heap_handle offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x7F0) == 0x7F0, "field_0x7F0 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x7FC) == 0x7FC, "field_0x7FC offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, critical_section) == 0x800, "critical_section offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, cs_work_buffer) == 0x808, "cs_work_buffer offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x810) == 0x810, "field_0x810 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, frame_time_scale) == 0x814, "frame_time_scale offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x818) == 0x818, "field_0x818 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x81C) == 0x81C, "field_0x81C offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x820) == 0x820, "field_0x820 offset mismatch");
static_assert(offsetof(CriMvEasyPlayer_s2, field_0x824) == 0x824, "field_0x824 offset mismatch");
static_assert(sizeof(CriMvEasyPlayer_s2) == 0x830, "CriMvEasyPlayer_s2 size mismatch");

#endif /* CMN85_S2_H */
