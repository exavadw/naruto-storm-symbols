/* cmn88 s3: nuccCriTextureBuffer, nuccCriticalSection
 * Build: s3 (NSUNS3.exe, image base 0x140000000)
 * All results INFERRED from static decompilation.
 * Sizes proven from embedding offsets in game code.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * nuccCriTextureBuffer — CRI texture buffer wrapper
 * Size: 0x68 (proven: embedded at param_1+0x73 and param_1+0x80 (undefined8* indices)
 *   in nuccCriSofdec2Work::nuccCriSofdec2Work @0x6C78B0; byte offsets 0x398 and 0x400;
 *   stride = 0x400 - 0x398 = 0x68)
 * Vtable: none set in ctor (ctor @0x716A60 sets *param_1 = 0, not a vtable ptr)
 *
 * Embedded sub-objects (sizes inferred from offset gaps):
 *   Nucc::Memory::BlockAllocator at 0x10, size 0x08 (ctor FUN_140191324 at param_1+2 = +0x10)
 *   std::string (event_data/name) at 0x28, size 0x20 (dtor @0x716AB0 accesses +0x28/+0x30)
 */
typedef struct __attribute__((packed)) nuccCriTextureBuffer {
    /* 0x00 */ void     *vtable;        /* SIM: set to 0 in ctor @0x716A60 (*param_1=0); Destroy also sets *param_1=0 */
    /* 0x08 */ uint32_t  flags;         /* PRES: *(uint32*)(p+1)=0xFFFFFFFF in ctor, set to param_3 in Create */
    /* 0x0C */ uint32_t  _pad_0c;       /* UNKNOWN: alignment padding */
    /* 0x10 */ uint8_t   block_allocator[0x08]; /* PRES: BlockAllocator ctor FUN_140191324(p+2) at 0x10 */
    /* 0x18 */ uint32_t  field_18;      /* PRES: p[3]=0 in Sofdec2Work ctor (parent zeroes this region) */
    /* 0x1C */ uint32_t  _pad_1c;       /* UNKNOWN: alignment padding */
    /* 0x20 */ uint64_t  field_20;      /* PRES: p[4]=0 in Sofdec2Work ctor; dtor checks 0xf < p[5] for string */
    /* 0x28 */ uint8_t   event_data[0x20]; /* PRES: std::string region, gap 0x28..0x47; dtor frees if len>0xf */
    /* 0x48 */ int32_t   width;         /* PRES: *(int*)(p+9)=param_4 in Create @0x716B80 */
    /* 0x4C */ int32_t   height;        /* PRES: *(int*)((ll)p+0x4c)=param_5 in Create */
    /* 0x50 */ uint32_t  texture_id;    /* PRES: *(uint32*)(p+10) in Create/Destroy; 0=unloaded */
    /* 0x54 */ uint32_t  bank_handle;   /* PRES: *(uint32*)((ll)p+0x54) in Create/Destroy; 0xFFFFFFFF=invalid */
    /* 0x58 */ uint32_t  field_58;      /* PRES: *(uint32*)(p+0xb)=iVar2 in Create, 0 in ctor */
    /* 0x5C */ uint32_t  _pad_5c;       /* UNKNOWN: padding */
    /* 0x60 */ uint64_t  field_60;      /* PRES: not directly accessed in CTB methods; part of parent zeroing */
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
 * Size: 0x50 (proven: same layout as s2; ctor @0x6BFFB0 sets vtable + created_flag=0;
 *   Create @0x6C0040 stores result at +0x48; Destroy @0x6C0060 checks +0x48==1;
 *   Unlock @0x6C00A0 checks +0x48==1. Context at +0x8 passed to NUMM functions.
 *   Size 0x50 = 8 (vtable) + 0x40 (context) + 4 (flag) + 4 (pad).
 *   Adjacent embedding proof carried from s2: stride 0xa08-0x9b8=0x50 in FUN_140581280.)
 * Vtable: PTR_FUN_1409e0b70 (set in ctor @0x6BFFB0)
 *
 * Embedded sub-object:
 *   NUMM_THREAD_CRITICAL_SECTION_CONTEXT at 0x08, size 0x40 (gap 0x08..0x47;
 *     Create calls FUN_1402b3ef0(param_1+8); Destroy calls FUN_1401336f0(param_1+8);
 *     Unlock calls FUN_14065e9e0(param_1+8))
 */
typedef struct __attribute__((packed)) nuccCriticalSection {
    /* 0x00 */ void     *vtable;        /* SIM: set to PTR_FUN_1409e0b70 in ctor @0x6BFFB0 */
    /* 0x08 */ uint8_t   context[0x40]; /* PRES: NUMM_THREAD_CRITICAL_SECTION_CONTEXT at +0x8 */
    /* 0x48 */ uint32_t  created_flag;  /* PRES: *(uint32*)(p+9)=0 in ctor, =Create() ret in Create, checked ==1 in Destroy/Unlock */
    /* 0x4C */ uint32_t  _pad_4c;       /* UNKNOWN: trailing pad to 0x50 */
} nuccCriticalSection;

_Static_assert(offsetof(nuccCriticalSection, vtable) == 0x00, "nuccCriticalSection.vtable");
_Static_assert(offsetof(nuccCriticalSection, context) == 0x08, "nuccCriticalSection.context");
_Static_assert(offsetof(nuccCriticalSection, created_flag) == 0x48, "nuccCriticalSection.created_flag");
_Static_assert(sizeof(nuccCriticalSection) == 0x50, "nuccCriticalSection size");