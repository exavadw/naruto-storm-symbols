/* cmn88 s2: nuccCriTextureBuffer, nuccCriticalSection
 * Build: s2 (NSUNS2.exe, image base 0x140000000)
 * All results INFERRED from static decompilation.
 * Sizes proven from embedding offsets in game code.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * nuccCriTextureBuffer — CRI texture buffer wrapper
 * Size: 0x68 (proven: embedded at param_1+0x398 in nuccCriSofdec2Work::CreateTextureBuffer
 *   @0x5CD460, next CTB at param_1+0x400 -> stride 0x400-0x398=0x68)
 * Vtable: PTR_FUN_1408918e8 (set in ctor @0x1D5714)
 *
 * Embedded sub-objects (sizes inferred from offset gaps):
 *   Nucc::Memory::BlockAllocator at 0x10, size 0x08 (gap 0x10..0x17; ctor FUN_1401afc0c at +0x10)
 *   cmnEventData at 0x28, size 0x20 (gap 0x28..0x47; dtor FUN_1405803b0 pattern)
 */
typedef struct __attribute__((packed)) nuccCriTextureBuffer {
    /* 0x00 */ void     *vtable;        /* SIM: set to PTR_FUN_1408918e8 in ctor @0x1D5714 */
    /* 0x08 */ uint32_t  flags;         /* PRES: *(uint32*)(p+1)=0xFFFFFFFF in copy ctor */
    /* 0x0C */ uint32_t  _pad_0c;       /* UNKNOWN: alignment padding */
    /* 0x10 */ uint8_t   block_allocator[0x08]; /* PRES: BlockAllocator ctor(p+2) at 0x10 */
    /* 0x18 */ uint32_t  field_18;      /* PRES: p[3]=0 in ctor @0x61E400 */
    /* 0x1C */ uint32_t  _pad_1c;       /* UNKNOWN: alignment padding */
    /* 0x20 */ uint64_t  field_20;      /* PRES: p[4]=0 in ctor @0x61E400 */
    /* 0x28 */ uint8_t   event_data[0x20]; /* PRES: cmnEventData region, gap 0x28..0x47 */
    /* 0x48 */ int32_t   width;         /* PRES: *(int*)(p+9)=param_4 in Create @0x61E520 */
    /* 0x4C */ int32_t   height;        /* PRES: *(int*)((ll)p+0x4c)=param_5 in Create */
    /* 0x50 */ uint32_t  texture_id;    /* PRES: *(uint32*)(p+10) in Create/Destroy */
    /* 0x54 */ uint32_t  bank_handle;   /* PRES: *(uint32*)((ll)p+0x54) in Create */
    /* 0x58 */ uint32_t  field_58;      /* PRES: *(uint32*)(p+0xb)=0 in ctor @0x61E400 */
    /* 0x5C */ uint32_t  _pad_5c;       /* UNKNOWN: padding */
    /* 0x60 */ uint64_t  field_60;      /* PRES: p[0xc]=0 in main ctor @0x374498 */
    /* 0x68 — end of object (size proven by embedding stride) */
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
_Static_assert(sizeof(nuccCriTextureBuffer) == 0x68, "nuccCriTextureBuffer size");

/*
 * nuccCriticalSection — Critical section wrapper around NUMM threading primitive
 * Size: 0x50 (proven: two adjacent embeddings in FUN_140581280 at param_1+0x9b8 and
 *   param_1+0xa08 -> stride 0xa08-0x9b8=0x50)
 * Vtable: PTR_FUN_1408921e8 (set in ctor @0x5AC080)
 *
 * Embedded sub-object:
 *   NUMM_THREAD_CRITICAL_SECTION_CONTEXT at 0x08, size 0x40 (gap 0x08..0x47;
 *     ctor FUN_14055bc40 at +0x8, Create calls FUN_14040e2d0 at +0x8)
 */
typedef struct __attribute__((packed)) nuccCriticalSection {
    /* 0x00 */ void     *vtable;        /* SIM: set to PTR_FUN_1408921e8 in ctor @0x5AC080 */
    /* 0x08 */ uint8_t   context[0x40]; /* PRES: NUMM_THREAD_CRITICAL_SECTION_CONTEXT at +0x8 */
    /* 0x48 */ uint32_t  created_flag;  /* PRES: *(uint32*)(p+9)=0/1 in ctor/Create/Destroy */
    /* 0x4C */ uint32_t  _pad_4c;       /* UNKNOWN: trailing pad to 0x50 */
} nuccCriticalSection;

_Static_assert(offsetof(nuccCriticalSection, vtable) == 0x00, "nuccCriticalSection.vtable");
_Static_assert(offsetof(nuccCriticalSection, context) == 0x08, "nuccCriticalSection.context");
_Static_assert(offsetof(nuccCriticalSection, created_flag) == 0x48, "nuccCriticalSection.created_flag");
_Static_assert(sizeof(nuccCriticalSection) == 0x50, "nuccCriticalSection size");