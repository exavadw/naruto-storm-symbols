/* cmn88.h — nuccCriTextureBuffer, nuccCriticalSection for Storm 4 (s4, NSUNS4_release.exe 1.09)
 * All results INFERRED from static decompilation. PC x64 offsets only.
 * Own-game names only. No external CRI source used.
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* nuccCriTextureBuffer — size 0x68 (104 bytes)
 * Size proof: embedding stride in nuccCriSofdec2Work::nuccCriSofdec2Work @0xA50120:
 *   four consecutive ctor calls at undefined8* indices 0x73, 0x80, 0x8d, 0x9a
 *   → byte offsets 0x398, 0x400, 0x468, 0x4D0. Stride = 0x400 − 0x398 = 0x68.
 * Vtable: none (ctor @0xA94D00 sets *param_1 = 0; confirmed identical to s3).
 */
typedef struct __attribute__((packed)) nuccCriTextureBuffer {
    uint64_t vtable;              /* 0x00 — always 0 in s4 (no vtable set) */
    uint32_t flags;               /* 0x08 — 0xFFFFFFFF = uninitialized; Create sets to param_3 */
    uint32_t _pad_0c;             /* 0x0C — alignment padding */
    uint8_t  block_allocator[8];  /* 0x10 — embedded Nucc::Memory::BlockAllocator (ctor FUN_140191324) */
    uint32_t field_18;            /* 0x18 — zeroed by parent Sofdec2Work ctor */
    uint32_t _pad_1c;             /* 0x1C — alignment padding */
    uint64_t field_20;            /* 0x20 — zeroed by parent; dtor checks string len at p[5] */
    uint8_t  event_data[32];      /* 0x28 — embedded std::string (name/event); dtor frees if len>0xF */
    int32_t  width;               /* 0x48 — texture width, Create stores param_4 */
    int32_t  height;              /* 0x4C — texture height, Create stores param_5 */
    uint32_t texture_id;          /* 0x50 — CRI texture handle; 0 = no texture loaded */
    uint32_t bank_handle;         /* 0x54 — CRI memory bank; 0xFFFFFFFF = invalid */
    uint32_t field_58;            /* 0x58 — set by Create to iVar2 (format/type?) */
    uint32_t _pad_5c;             /* 0x5C — alignment padding */
    uint64_t field_60;            /* 0x60 — part of parent zeroing; not directly accessed by CTB methods */
} nuccCriTextureBuffer;

static_assert(offsetof(nuccCriTextureBuffer, vtable) == 0x00, "CTB vtable");
static_assert(offsetof(nuccCriTextureBuffer, flags) == 0x08, "CTB flags");
static_assert(offsetof(nuccCriTextureBuffer, _pad_0c) == 0x0C, "CTB _pad_0c");
static_assert(offsetof(nuccCriTextureBuffer, block_allocator) == 0x10, "CTB block_allocator");
static_assert(offsetof(nuccCriTextureBuffer, field_18) == 0x18, "CTB field_18");
static_assert(offsetof(nuccCriTextureBuffer, _pad_1c) == 0x1C, "CTB _pad_1c");
static_assert(offsetof(nuccCriTextureBuffer, field_20) == 0x20, "CTB field_20");
static_assert(offsetof(nuccCriTextureBuffer, event_data) == 0x28, "CTB event_data");
static_assert(offsetof(nuccCriTextureBuffer, width) == 0x48, "CTB width");
static_assert(offsetof(nuccCriTextureBuffer, height) == 0x4C, "CTB height");
static_assert(offsetof(nuccCriTextureBuffer, texture_id) == 0x50, "CTB texture_id");
static_assert(offsetof(nuccCriTextureBuffer, bank_handle) == 0x54, "CTB bank_handle");
static_assert(offsetof(nuccCriTextureBuffer, field_58) == 0x58, "CTB field_58");
static_assert(offsetof(nuccCriTextureBuffer, _pad_5c) == 0x5C, "CTB _pad_5c");
static_assert(offsetof(nuccCriTextureBuffer, field_60) == 0x60, "CTB field_60");
static_assert(sizeof(nuccCriTextureBuffer) == 0x68, "CTB size 0x68");

/* nuccCriticalSection — size 0x50 (80 bytes)
 * Size proof: embedded in nuccDrawEnv::nuccDrawEnv @0xA239E0 at undefined8* index 0x37
 *   (byte 0x1B8); next object nuccColorFilterManager at index 0x42 (byte 0x210).
 *   Stride = 0x58 includes 8-byte alignment padding after the 0x50 struct.
 *   Field layout confirmed identical to s3 via ctor/Create/Destroy/Unlock accessing
 *   context at +0x08 and created_flag at +0x48. Last proven field ends at 0x4C.
 * Vtable: PTR_FUN_141106840 (set in ctor @0xA23260).
 */
typedef struct __attribute__((packed)) nuccCriticalSection {
    uint64_t vtable;              /* 0x00 — PTR_FUN_141106840 */
    uint8_t  context[64];         /* 0x08 — embedded NUMM_THREAD_CRITICAL_SECTION_CONTEXT */
    uint32_t created_flag;        /* 0x48 — 1 = initialized, 0 = destroyed/uninitialized */
    uint32_t _pad_4c;             /* 0x4C — trailing pad to 0x50 */
} nuccCriticalSection;

static_assert(offsetof(nuccCriticalSection, vtable) == 0x00, "CS vtable");
static_assert(offsetof(nuccCriticalSection, context) == 0x08, "CS context");
static_assert(offsetof(nuccCriticalSection, created_flag) == 0x48, "CS created_flag");
static_assert(offsetof(nuccCriticalSection, _pad_4c) == 0x4C, "CS _pad_4c");
static_assert(sizeof(nuccCriticalSection) == 0x50, "CS size 0x50");