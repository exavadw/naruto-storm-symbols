/* cmn88 s1: nuccCriTextureBuffer, nuccCriticalSection
 * Build: s1 (NSUNS1.exe, image base 0x140000000)
 * All results INFERRED from static decompilation.
 * Sizes proven from embedding offsets in game code.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * nuccCriTextureBuffer — CRI texture buffer wrapper
 * Size: 0xF8 (proven: embedded at param_1+1 in nuccCriSofdec2Work ctor @0x17E550,
 * next sibling field at param_1[0x20]=byte 0x100 -> 0x100-0x8=0xF8)
 * Vtable: PTR_FUN_14065aeb0 (set in ctor @0x17E4A8)
 *
 * Embedded sub-objects (sizes inferred from offset gaps):
 * Nucc::Memory::BlockAllocator at 0x10, size 0x08 (gap 0x10..0x17)
 * cmnEventData at 0x28, size 0x20 (gap 0x28..0x47)
 */
typedef struct __attribute__((packed)) nuccCriTextureBuffer {
 /* 0x00 */ void *vtable; /* SIM: vtable ptr set in ctor */
 /* 0x08 */ uint32_t flags; /* PRES: *(uint32*)(p+1)=0xFFFFFFFF in copy ctor */
 /* 0x0C */ uint32_t _pad_0c; /* UNKNOWN: padding */
 /* 0x10 */ uint8_t block_allocator[0x08]; /* PRES: BlockAllocator::ctor(p+2) at 0x10, size=0x08 */
 /* 0x18 */ uint32_t field_18; /* PRES: *(uint32*)(p+3)=0 in ctor */
 /* 0x1C */ uint32_t _pad_1c; /* UNKNOWN: padding */
 /* 0x20 */ uint64_t field_20; /* PRES: p[4]=0 in ctor */
 /* 0x28 */ uint8_t event_data[0x20]; /* PRES: cmnEventData::~cmnEventData(p+5) at 0x28, size=0x20 */
 /* 0x48 */ int32_t width; /* PRES: *(int*)(p+9)=param_4 in Create */
 /* 0x4C */ int32_t height; /* PRES: *(int*)((ll)p+0x4c)=param_5 in Create */
 /* 0x50 */ uint32_t texture_id; /* PRES: *(uint32*)(p+10) in Create/Destroy */
 /* 0x54 */ uint32_t bank_handle; /* PRES: *(uint32*)((ll)p+0x54) in Create */
 /* 0x58 */ uint32_t field_58; /* PRES: *(uint32*)(p+0xb)=0 in copy ctor */
 /* 0x5C */ uint32_t _pad_5c; /* UNKNOWN: padding */
 /* 0x60 */ uint64_t field_60; /* PRES: p[0xc]=0 in state_surface */
 /* 0x68 */ uint64_t field_68; /* PRES: p[0xd]=0 in state_surface */
 /* 0x70 */ uint64_t field_70; /* PRES: p[0xe]=0 in state_surface */
 /* 0x78 */ uint64_t field_78; /* PRES: p[0xf]=0 in state_surface */
 /* 0x80 */ uint64_t field_80; /* PRES: p[0x10]=0 in state_surface */
 /* 0x88 */ uint32_t field_88; /* PRES: *(uint32*)(p+0x11)=0 in state_surface */
 /* 0x8C */ uint32_t _pad_8c; /* UNKNOWN: padding */
 /* 0x90 */ uint8_t reserved_90[0x60];/* UNKNOWN: gap 0x90..0xEF (read via FUN_14047f900(p+0x12)) */
 /* 0xF0 */ uint32_t field_f0; /* PRES: *(uint32*)(p+0x1e)=0 in ctor */
 /* 0xF4 */ uint32_t _pad_f4; /* UNKNOWN: trailing pad to 0xF8 */
} nuccCriTextureBuffer;

_Static_assert(offsetof(nuccCriTextureBuffer, vtable) == 0x00, "nuccCriTextureBuffer.vtable");
_Static_assert(offsetof(nuccCriTextureBuffer, flags) == 0x08, "nuccCriTextureBuffer.flags");
_Static_assert(offsetof(nuccCriTextureBuffer, block_allocator) == 0x10, "nuccCriTextureBuffer.block_allocator");
_Static_assert(offsetof(nuccCriTextureBuffer, field_18) == 0x18, "nuccCriTextureBuffer.field_18");
_Static_assert(offsetof(nuccCriTextureBuffer, field_20) == 0x20, "nuccCriTextureBuffer.field_20");
_Static_assert(offsetof(nuccCriTextureBuffer, event_data) == 0x28, "nuccCriTextureBuffer.event_data");
_Static_assert(offsetof(nuccCriTextureBuffer, width) == 0x48, "nuccCriTextureBuffer.width");
_Static_assert(offsetof(nuccCriTextureBuffer, height) == 0x4C, "nuccCriTextureBuffer.height");
_Static_assert(offsetof(nuccCriTextureBuffer, texture_id) == 0x50, "nuccCriTextureBuffer.texture_id");
_Static_assert(offsetof(nuccCriTextureBuffer, bank_handle) == 0x54, "nuccCriTextureBuffer.bank_handle");
_Static_assert(offsetof(nuccCriTextureBuffer, field_58) == 0x58, "nuccCriTextureBuffer.field_58");
_Static_assert(offsetof(nuccCriTextureBuffer, field_60) == 0x60, "nuccCriTextureBuffer.field_60");
_Static_assert(offsetof(nuccCriTextureBuffer, field_68) == 0x68, "nuccCriTextureBuffer.field_68");
_Static_assert(offsetof(nuccCriTextureBuffer, field_70) == 0x70, "nuccCriTextureBuffer.field_70");
_Static_assert(offsetof(nuccCriTextureBuffer, field_78) == 0x78, "nuccCriTextureBuffer.field_78");
_Static_assert(offsetof(nuccCriTextureBuffer, field_80) == 0x80, "nuccCriTextureBuffer.field_80");
_Static_assert(offsetof(nuccCriTextureBuffer, field_88) == 0x88, "nuccCriTextureBuffer.field_88");
_Static_assert(offsetof(nuccCriTextureBuffer, reserved_90) == 0x90, "nuccCriTextureBuffer.reserved_90");
_Static_assert(offsetof(nuccCriTextureBuffer, field_f0) == 0xF0, "nuccCriTextureBuffer.field_f0");
_Static_assert(sizeof(nuccCriTextureBuffer) == 0xF8, "nuccCriTextureBuffer size");

/*
 * nuccCriticalSection — Critical section wrapper around NUMM threading primitive
 * Size: 0x50 (proven: embedded at param_1+3 in nuccXfbinData ctor @0x483590,
 * next sibling at param_1+0xd=byte 0x68 -> 0x68-0x18=0x50;
 * confirmed by globals DAT_140884498.._DAT_1408844e8 = 0x50 in Nucc::Effect::GetManager @0x499910)
 * Vtable: PTR_FUN_140736460 (set in ctor @0x47F2E0)
 *
 * Embedded sub-object:
 * NUMM_THREAD_CRITICAL_SECTION_CONTEXT at 0x08, size 0x40 (gap 0x08..0x47)
 */
typedef struct __attribute__((packed)) nuccCriticalSection {
 /* 0x00 */ void *vtable; /* SIM: vtable ptr set in ctor */
 /* 0x08 */ uint8_t context[0x40]; /* PRES: NUMM_THREAD_CRITICAL_SECTION_CONTEXT::ctor at +0x8, size=0x40 */
 /* 0x48 */ uint32_t created_flag; /* PRES: *(uint32*)(p+9)=0/1 in ctor/Create/Destroy */
 /* 0x4C */ uint32_t _pad_4c; /* UNKNOWN: trailing pad to 0x50 */
} nuccCriticalSection;

_Static_assert(offsetof(nuccCriticalSection, vtable) == 0x00, "nuccCriticalSection.vtable");
_Static_assert(offsetof(nuccCriticalSection, context) == 0x08, "nuccCriticalSection.context");
_Static_assert(offsetof(nuccCriticalSection, created_flag) == 0x48, "nuccCriticalSection.created_flag");
_Static_assert(sizeof(nuccCriticalSection) == 0x50, "nuccCriticalSection size");