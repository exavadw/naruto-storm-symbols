/* cmn27.h — Storm 4 (s4) struct group: mmDrawCommand*, mmFile*, mmDX11Mapping
 * Build: s4 (NSUNS4_release.exe PC 1.09, sha 75912b)
 * Status: INFERRED (static decompilation only, not runtime-confirmed)
 * All offsets from s4 x64 decompile. Sizes proven from Storage::Create allocation sizes.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#ifdef _WIN32
typedef void *HANDLE;
#else
typedef void *HANDLE;
#endif

/* CRITICAL_SECTION is 40 bytes on x64 Windows */
typedef struct {
    uint8_t opaque[40];
} CRITICAL_SECTION_x64;

/* ========================================================================
 * mmFile_Win — Win32 file wrapper
 * Fields from Open/Read/Write/Close decompiles (RVA 0x1833F0..0x183770)
 * Size: >= 0x18 (handle at +0x10 is 8 bytes -> 0x18)
 * No vtable found in s4 (dtor not decompiled here; may be inlined)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;           /* PRES — assumed from s3 pattern */
    /* +0x08 */ int32_t   error_code;       /* PRES — Open/Read/Write/Close write error codes */
    /* +0x0C */ uint32_t  _pad_0x0C;        /* UNKNOWN — alignment padding */
    /* +0x10 */ HANDLE    handle;           /* PRES — CreateFileW result, checked in Read/Write/Close */
} mmFile_Win;

static_assert(offsetof(mmFile_Win, vtable)     == 0x00, "mmFile_Win::vtable");
static_assert(offsetof(mmFile_Win, error_code) == 0x08, "mmFile_Win::error_code");
static_assert(offsetof(mmFile_Win, _pad_0x0C)  == 0x0C, "mmFile_Win::_pad_0x0C");
static_assert(offsetof(mmFile_Win, handle)     == 0x10, "mmFile_Win::handle");

/* ========================================================================
 * mmDrawCommand_SetShader — draw command to bind a shader
 * Fields from Execute (RVA 0x18A1E0): reads +0x30, +0x38
 * Size: >= 0x40 (proven by Storage::Create<BindTexture> = 0x40, same base layout)
 * Vtable at +0x00 (Execute dispatches via vtable)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;           /* PRES — Execute dispatches via vtable */
    /* +0x08 */ uint8_t   base_cmd[0x28];   /* PRES — intrusive list node + base fields */
    /* +0x30 */ uint64_t  shader_param_a;   /* PRES — Execute reads +0x30 */
    /* +0x38 */ uint64_t  shader_param_b;   /* PRES — Execute reads +0x38 */
} mmDrawCommand_SetShader;

static_assert(offsetof(mmDrawCommand_SetShader, vtable)         == 0x00, "SetShader::vtable");
static_assert(offsetof(mmDrawCommand_SetShader, base_cmd)       == 0x08, "SetShader::base_cmd");
static_assert(offsetof(mmDrawCommand_SetShader, shader_param_a) == 0x30, "SetShader::shader_param_a");
static_assert(offsetof(mmDrawCommand_SetShader, shader_param_b) == 0x38, "SetShader::shader_param_b");

/* ========================================================================
 * mmDrawCommand_UpdateBuffer — draw command to copy CPU data to GPU buffer
 * Fields from Execute (RVA 0x18A220): reads +0x30, +0x38, +0x40
 * Size: >= 0x48 (last field at +0x40 is 8 bytes -> 0x48)
 * Vtable at +0x00
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;           /* PRES — Execute dispatches via vtable */
    /* +0x08 */ uint8_t   base_cmd[0x28];   /* PRES — intrusive list node + base fields */
    /* +0x30 */ uint64_t  size;             /* PRES — Execute reads +0x30 as transfer size */
    /* +0x38 */ uint64_t  src_data;         /* PRES — Execute reads +0x38 as source pointer */
    /* +0x40 */ uint64_t  dst_buffer;       /* PRES — Execute reads +0x40 as destination */
} mmDrawCommand_UpdateBuffer;

static_assert(offsetof(mmDrawCommand_UpdateBuffer, vtable)     == 0x00, "UpdateBuffer::vtable");
static_assert(offsetof(mmDrawCommand_UpdateBuffer, base_cmd)   == 0x08, "UpdateBuffer::base_cmd");
static_assert(offsetof(mmDrawCommand_UpdateBuffer, size)       == 0x30, "UpdateBuffer::size");
static_assert(offsetof(mmDrawCommand_UpdateBuffer, src_data)   == 0x38, "UpdateBuffer::src_data");
static_assert(offsetof(mmDrawCommand_UpdateBuffer, dst_buffer) == 0x40, "UpdateBuffer::dst_buffer");

/* ========================================================================
 * mmDrawCommand_UpdateConstantBuffer — draw command to update CB
 * Fields from Set (RVA 0x192850) and Execute (RVA 0x18A850)
 * Set uses longlong* param_1: [3]=+0x18, [4]=+0x20, [5]=+0x28, [7]=+0x38, [9]=+0x48, [10]=+0x50
 * Execute reads +0x30, +0x38, +0x40
 * Size: >= 0x58 (cached_command at +0x50 is 8 bytes -> 0x58)
 * Vtable at +0x00
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;           /* PRES — Execute/Set dispatch via vtable */
    /* +0x08 */ uint64_t  gpu_buffer_wrapper; /* PRES — Set accesses *(param_1+8)+8 for wrapper */
    /* +0x10 */ uint64_t  buffer_offset;    /* PRES — Set reads/writes +0x10 as offset into buffer */
    /* +0x18 */ uint64_t  constant_buffer;  /* PRES — Set accesses +0x18 via param_1[3] */
    /* +0x20 */ uint64_t  data_size;        /* PRES — Set accesses +0x20 via param_1[4] */
    /* +0x28 */ uint64_t  allocator_ptr;    /* PRES — Set accesses +0x28 via param_1[5] */
    /* +0x30 */ uint64_t  cb_data_ptr;      /* PRES — Execute reads +0x30 */
    /* +0x38 */ uint64_t  cached_command;   /* PRES — Execute checks +0x38 != 0 */
    /* +0x40 */ uint64_t  gpu_state_ref;    /* PRES — Execute reads +0x40 */
    /* +0x48 */ uint64_t  cached_key;       /* PRES — Set writes param_1[9] = key */
    /* +0x50 */ uint64_t  cached_cmd_ptr;   /* PRES — Set writes param_1[10] = cmd ptr */
} mmDrawCommand_UpdateConstantBuffer;

static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, vtable)            == 0x00, "UCB::vtable");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, gpu_buffer_wrapper)== 0x08, "UCB::gpu_buffer_wrapper");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, buffer_offset)     == 0x10, "UCB::buffer_offset");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, constant_buffer)   == 0x18, "UCB::constant_buffer");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, data_size)         == 0x20, "UCB::data_size");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, allocator_ptr)     == 0x28, "UCB::allocator_ptr");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, cb_data_ptr)       == 0x30, "UCB::cb_data_ptr");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, cached_command)    == 0x38, "UCB::cached_command");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, gpu_state_ref)     == 0x40, "UCB::gpu_state_ref");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, cached_key)        == 0x48, "UCB::cached_key");
static_assert(offsetof(mmDrawCommand_UpdateConstantBuffer, cached_cmd_ptr)    == 0x50, "UCB::cached_cmd_ptr");

/* ========================================================================
 * mmDrawCommand_UpdateRenderState — draw command to apply render state
 * Fields from Execute (RVA 0x18A170): Merge at +0x30, gpu_render_state at +0x100, merge_count at +0x108
 * Size: >= 0x110 (merge_count at +0x108 is uint32 -> 0x10C, aligned 0x110)
 * Vtable at +0x00
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;           /* PRES — Execute dispatches via vtable */
    /* +0x08 */ uint8_t   base_cmd[0x28];   /* PRES — intrusive list node + base fields */
    /* +0x30 */ uint8_t   render_state_data[0xD0]; /* PRES — Merge operates on 0xD0 bytes starting at +0x30 */
    /* +0x100 */ uint64_t gpu_render_state; /* PRES — Execute reads +0x100 as GPU state ptr */
    /* +0x108 */ uint32_t merge_count;      /* PRES — Execute reads +0x108 as merge count */
    /* +0x10C */ uint32_t _pad_0x10C;       /* UNKNOWN — alignment to 0x110 */
} mmDrawCommand_UpdateRenderState;

static_assert(offsetof(mmDrawCommand_UpdateRenderState, vtable)            == 0x00,  "URS::vtable");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, base_cmd)          == 0x08,  "URS::base_cmd");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, render_state_data) == 0x30,  "URS::render_state_data");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, gpu_render_state)  == 0x100, "URS::gpu_render_state");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, merge_count)       == 0x108, "URS::merge_count");
static_assert(offsetof(mmDrawCommand_UpdateRenderState, _pad_0x10C)        == 0x10C, "URS::_pad_0x10C");

/* ========================================================================
 * mmDrawCommandList — linked list of draw commands
 * Carried from s3 (only Sort method, 1 method total — below threshold)
 * Size: >= 0x40 (from s3; no new s4 evidence)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *list_head;        /* PRES — Sort iterates from +0x00 */
    /* +0x08 */ uint8_t   _pad_0x08[0x18];  /* UNKNOWN — gap before tail/count */
    /* +0x20 */ void     *tail_or_count;    /* PRES — Sort accesses +0x20 */
    /* +0x28 */ uint8_t   _pad_0x28[0x10];  /* UNKNOWN — gap */
    /* +0x38 */ uint8_t   sorted_flag;      /* PRES — Sort sets +0x38 = 1 */
    /* +0x39 */ uint8_t   _pad_0x39[7];     /* UNKNOWN — align to 0x40 */
} mmDrawCommandList;

static_assert(offsetof(mmDrawCommandList, list_head)     == 0x00, "DCL::list_head");
static_assert(offsetof(mmDrawCommandList, _pad_0x08)     == 0x08, "DCL::_pad_0x08");
static_assert(offsetof(mmDrawCommandList, tail_or_count) == 0x20, "DCL::tail_or_count");
static_assert(offsetof(mmDrawCommandList, _pad_0x28)     == 0x28, "DCL::_pad_0x28");
static_assert(offsetof(mmDrawCommandList, sorted_flag)   == 0x38, "DCL::sorted_flag");
static_assert(offsetof(mmDrawCommandList, _pad_0x39)     == 0x39, "DCL::_pad_0x39");

/* ========================================================================
 * mmDrawCommandSorter — sorts draw commands by type/priority
 * Ctor1 (RVA 0x4CDDA8): vtable at +0x00, secondary vtable at +0x18, subobjects at +0x86/+0x9F
 * Ctor2 (RVA 0x4F2828): vtable at +0x00, MergeBuffer at +0x08 and +0x30, flag at +0x58
 * Size: >= 0xE0 (from ctor2: flag at +0x58 + MergeBuffer objects; s3 had 0xE0)
 * Dual vtables at +0x00 and +0x18
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ void     *vtable;           /* PRES — ctor1/ctor2 write vtable */
    /* +0x08 */ uint8_t   merge_buffer_a[0x10]; /* PRES — ctor2 calls MergeBuffer::MergeBuffer(param_1+1) = +0x08 */
    /* +0x18 */ void     *vtable_secondary; /* PRES — ctor1 writes param_1[3] = &PTR_FUN_1411046e8 */
    /* +0x20 */ uint8_t   _pad_0x20[0x10];  /* UNKNOWN — gap */
    /* +0x30 */ uint8_t   merge_buffer_b[0x28]; /* PRES — ctor2 calls MergeBuffer::MergeBuffer(param_1+6) = +0x30 */
    /* +0x58 */ uint32_t  sort_flag;        /* PRES — ctor2 sets *(param_1+0xb)=0, i.e. +0x58 */
    /* +0x5C */ uint8_t   _pad_0x5C[0x2A];  /* UNKNOWN — gap to subobject_a */
    /* +0x86 */ uint8_t   subobject_a[0x19];/* PRES — ctor1 calls dtor at param_1+0x9f, init at param_1+0x86 */
    /* +0x9F */ uint8_t   subobject_b[0x41];/* PRES — ctor1 calls ~ccAdvCollisionResultList at param_1+0x9f */
} mmDrawCommandSorter;

static_assert(offsetof(mmDrawCommandSorter, vtable)           == 0x00, "DCS::vtable");
static_assert(offsetof(mmDrawCommandSorter, merge_buffer_a)   == 0x08, "DCS::merge_buffer_a");
static_assert(offsetof(mmDrawCommandSorter, vtable_secondary) == 0x18, "DCS::vtable_secondary");
static_assert(offsetof(mmDrawCommandSorter, _pad_0x20)        == 0x20, "DCS::_pad_0x20");
static_assert(offsetof(mmDrawCommandSorter, merge_buffer_b)   == 0x30, "DCS::merge_buffer_b");
static_assert(offsetof(mmDrawCommandSorter, sort_flag)        == 0x58, "DCS::sort_flag");
static_assert(offsetof(mmDrawCommandSorter, _pad_0x5C)        == 0x5C, "DCS::_pad_0x5C");
static_assert(offsetof(mmDrawCommandSorter, subobject_a)      == 0x86, "DCS::subobject_a");
static_assert(offsetof(mmDrawCommandSorter, subobject_b)      == 0x9F, "DCS::subobject_b");

/* ========================================================================
 * mmDrawCommandStorageAllocator — manages double-buffered command storage
 * Carried from s3 (only GetDrawCommandStorage, 1 method — below threshold)
 * Size: >= 0x90 (CRITICAL_SECTION at +0x68 is 40 bytes -> 0x90)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ uint8_t              storage_slots[0x58]; /* PRES — indexed array of storage ptrs */
    /* +0x58 */ uint8_t              active_buffer_index;  /* SIM — Flip toggles between 0/1 */
    /* +0x59 */ uint8_t              _pad_0x59[7];         /* UNKNOWN — align to CRITICAL_SECTION */
    /* +0x60 */ uint64_t             _pad_0x60;            /* UNKNOWN — pre-CRIT padding */
    /* +0x68 */ CRITICAL_SECTION_x64 critical_section;     /* PRES — InitializeCriticalSection */
} mmDrawCommandStorageAllocator;

static_assert(offsetof(mmDrawCommandStorageAllocator, storage_slots)      == 0x00, "DCSA::storage_slots");
static_assert(offsetof(mmDrawCommandStorageAllocator, active_buffer_index)== 0x58, "DCSA::active_buffer_index");
static_assert(offsetof(mmDrawCommandStorageAllocator, _pad_0x59)          == 0x59, "DCSA::_pad_0x59");
static_assert(offsetof(mmDrawCommandStorageAllocator, _pad_0x60)          == 0x60, "DCSA::_pad_0x60");
static_assert(offsetof(mmDrawCommandStorageAllocator, critical_section)   == 0x68, "DCSA::critical_section");

/* ========================================================================
 * mmDrawCommandManager — orchestrates frame rendering pipeline
 * Fields from Initialize (0x18D4A0), Flip (0x18D7E0), FrameStart (0x18D740)
 * Size: >= 0x1A0 (destroy_thread at +0x198 is ptr -> 0x1A0)
 * ======================================================================== */
typedef struct __attribute__((packed)) {
    /* +0x00 */ uint8_t              _pad_0x00[0x58];      /* UNKNOWN — base region */
    /* +0x58 */ uint8_t              flip_toggle_a;        /* SIM — Flip swaps a/b each frame */
    /* +0x59 */ uint8_t              flip_toggle_b;        /* SIM — Flip swaps a/b each frame */
    /* +0x5A */ uint8_t              _pad_0x5A[6];         /* UNKNOWN — gap */
    /* +0x60 */ void                *render_thread;        /* PRES — Initialize starts thread from +0x60 */
    /* +0x68 */ uint8_t              _pad_0x68[0x10];      /* UNKNOWN — gap */
    /* +0x78 */ CRITICAL_SECTION_x64 *critsec_ptr;         /* PRES — Flip enters critsec at *(param_1+0x78) */
    /* +0x80 */ void               **event_handle_ptr;     /* PRES — FrameStart SetEvent(**(param_1+0x80)) */
    /* +0x88 */ uint8_t              frame_active_flag;    /* SIM — FrameStart sets +0x88=1, Flip checks */
    /* +0x89 */ uint8_t              _pad_0x89[7];         /* UNKNOWN — gap */
    /* +0x90 */ CRITICAL_SECTION_x64 *critsec_frame;       /* PRES — FrameStart enters critsec at *(param_1+0x90) */
    /* +0x98 */ uint32_t             buf_index_a;          /* SIM — Flip uses for storage array calc */
    /* +0x9C */ uint32_t             buf_index_b;          /* SIM — Flip uses for storage array calc */
    /* +0xA0 */ uint8_t              _pad_0xA0[0x18];      /* UNKNOWN — unaccounted gap */
    /* +0xB8 */ uint64_t            *storage_array_base;   /* PRES — Flip indexes *(param_1+0xB8 + idx*0x28) */
    /* +0xC0 */ uint8_t              _pad_0xC0[0x38];      /* UNKNOWN — large unaccounted gap */
    /* +0xF8 */ uint32_t             flags;                /* PRES — Flip clears +0xF8=0 */
    /* +0xFC */ uint8_t              _pad_0xFC[0x54];      /* UNKNOWN — large unaccounted gap */
    /* +0x150 */ uint8_t             init_flag;            /* PRES — Initialize sets +0x150=1 */
    /* +0x151 */ uint8_t             config_byte;          /* PRES — Initialize copies from param_2+0x11 */
    /* +0x152 */ uint8_t             _pad_0x152[0x3E];     /* UNKNOWN — gap */
    /* +0x190 */ uint8_t             destroy_flag;         /* PRES — Initialize sets +0x190=1 (400=0x190) */
    /* +0x191 */ uint8_t             _pad_0x191[7];        /* UNKNOWN — gap */
    /* +0x198 */ void                *destroy_thread;       /* PRES — Initialize starts destroy thread from +0x198 */
} mmDrawCommandManager;

static_assert(offsetof(mmDrawCommandManager, _pad_0x00)          == 0x00,  "DCM::_pad_0x00");
static_assert(offsetof(mmDrawCommandManager, flip_toggle_a)      == 0x58,  "DCM::flip_toggle_a");
static_assert(offsetof(mmDrawCommandManager, flip_toggle_b)      == 0x59,  "DCM::flip_toggle_b");
static_assert(offsetof(mmDrawCommandManager, _pad_0x5A)          == 0x5A,  "DCM::_pad_0x5A");
static_assert(offsetof(mmDrawCommandManager, render_thread)      == 0x60,  "DCM::render_thread");
static_assert(offsetof(mmDrawCommandManager, _pad_0x68)          == 0x68,  "DCM::_pad_0x68");
static_assert(offsetof(mmDrawCommandManager, critsec_ptr)        == 0x78,  "DCM::critsec_ptr");
static_assert(offsetof(mmDrawCommandManager, event_handle_ptr)   == 0x80,  "DCM::event_handle_ptr");
static_assert(offsetof(mmDrawCommandManager, frame_active_flag)  == 0x88,  "DCM::frame_active_flag");
static_assert(offsetof(mmDrawCommandManager, _pad_0x89)          == 0x89,  "DCM::_pad_0x89");
static_assert(offsetof(mmDrawCommandManager, critsec_frame)      == 0x90,  "DCM::critsec_frame");
static_assert(offsetof(mmDrawCommandManager, buf_index_a)        == 0x98,  "DCM::buf_index_a");
static_assert(offsetof(mmDrawCommandManager, buf_index_b)        == 0x9C,  "DCM::buf_index_b");
static_assert(offsetof(mmDrawCommandManager, _pad_0xA0)          == 0xA0,  "DCM::_pad_0xA0");
static_assert(offsetof(mmDrawCommandManager, storage_array_base) == 0xB8,  "DCM::storage_array_base");
static_assert(offsetof(mmDrawCommandManager, _pad_0xC0)          == 0xC0,  "DCM::_pad_0xC0");
static_assert(offsetof(mmDrawCommandManager, flags)              == 0xF8,  "DCM::flags");
static_assert(offsetof(mmDrawCommandManager, _pad_0xFC)          == 0xFC,  "DCM::_pad_0xFC");
static_assert(offsetof(mmDrawCommandManager, init_flag)          == 0x150, "DCM::init_flag");
static_assert(offsetof(mmDrawCommandManager, config_byte)        == 0x151, "DCM::config_byte");
static_assert(offsetof(mmDrawCommandManager, _pad_0x152)         == 0x152, "DCM::_pad_0x152");
static_assert(offsetof(mmDrawCommandManager, destroy_flag)       == 0x190, "DCM::destroy_flag");
static_assert(offsetof(mmDrawCommandManager, _pad_0x191)         == 0x191, "DCM::_pad_0x191");
static_assert(offsetof(mmDrawCommandManager, destroy_thread)     == 0x198, "DCM::destroy_thread");