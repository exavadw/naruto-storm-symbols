/* cmn38.h - Nucc::Memory, Nucc::Memory::Block, Nucc::Memory::BlockManager,
 * Nucc::Quat_MathGeo, Nucc::ScaleOpType
 * Build: s2 (NSUNS2.exe, Storm 2 PC)
 * All layouts INFERRED from static decompilation, not CONFIRMED at runtime.
 * Generated 2026-10-19
 * Coverage: Nucc::Memory (6 methods, no instance state) verified 2026-10-19 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Quat_MathGeo
 * Value type: quaternion (4 floats). No vtable, no heap allocation.
 * Size proven: 16 bytes (param_1[0..3] as undefined4 in Set at 0x5AD4A0)
 * Evidence: Nucc::Quat_MathGeo::Set (0x5AD4A0), SetFromXfbin (0x5AD560)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Quat_MathGeo {
    float x;                    /* 0x00 */
    float y;                    /* 0x04 */
    float z;                    /* 0x08 */
    float w;                    /* 0x0C */
} Nucc_Quat_MathGeo;

static_assert(offsetof(Nucc_Quat_MathGeo, x) == 0x00, "Quat_MathGeo.x");
static_assert(offsetof(Nucc_Quat_MathGeo, y) == 0x04, "Quat_MathGeo.y");
static_assert(offsetof(Nucc_Quat_MathGeo, z) == 0x08, "Quat_MathGeo.z");
static_assert(offsetof(Nucc_Quat_MathGeo, w) == 0x0C, "Quat_MathGeo.w");
static_assert(sizeof(Nucc_Quat_MathGeo) == 0x10, "Quat_MathGeo size");

/* ========================================================================
 * Nucc::ScaleOpType
 * Value type wrapping math::ScaleOp. Passed as undefined8 (8 bytes).
 * Size proven: 8 bytes (passed by value as undefined8 in ToMatrix44/Offset)
 * Evidence: Nucc::ScaleOpType::ToMatrix44 (0x594CD0), Offset (0x594CA0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_ScaleOpType {
    uint64_t scale_op_data;     /* 0x00 - opaque math::ScaleOp handle */
} Nucc_ScaleOpType;

static_assert(offsetof(Nucc_ScaleOpType, scale_op_data) == 0x00, "ScaleOpType.scale_op_data");
static_assert(sizeof(Nucc_ScaleOpType) == 0x08, "ScaleOpType size");

/* ========================================================================
 * Nucc::Memory::Block
 * Heap-allocated block with vtable. Base class for memory blocks.
 * Size proven: >= 0x30 (operator_new(0x30,...) in StackBlock::Create at 0x5B7B70)
 * Vtable: PTR_FUN_1408995e8 (set in Block::Block ctor at 0x60D430)
 * Evidence: Block::Block (0x60D430), Block::Create (0x60D500), Block::Free (0x60D5F0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_Block {
    void *vtable;               /* 0x00 - PTR_FUN_1408995e8 */
    int32_t block_id;           /* 0x08 - init 0xFFFFFFFF in ctor */
    uint8_t _pad_0C[4];         /* 0x0C - alignment padding */
    void *data_ptr;             /* 0x10 - allocated data pointer (param_1[2] in Create) */
    void *field_18;             /* 0x18 - param_1[3], set via FUN_14062a2e0 in Create */
    void *field_20;             /* 0x20 - zeroed in ctor (param_1[2]=0) */
    uint64_t field_28;          /* 0x28 - set from SystemMemoryFree in Create (param_1[5]) */
} Nucc_Memory_Block;

static_assert(offsetof(Nucc_Memory_Block, vtable) == 0x00, "Block.vtable");
static_assert(offsetof(Nucc_Memory_Block, block_id) == 0x08, "Block.block_id");
static_assert(offsetof(Nucc_Memory_Block, _pad_0C) == 0x0C, "Block._pad_0C");
static_assert(offsetof(Nucc_Memory_Block, data_ptr) == 0x10, "Block.data_ptr");
static_assert(offsetof(Nucc_Memory_Block, field_18) == 0x18, "Block.field_18");
static_assert(offsetof(Nucc_Memory_Block, field_20) == 0x20, "Block.field_20");
static_assert(offsetof(Nucc_Memory_Block, field_28) == 0x28, "Block.field_28");
static_assert(sizeof(Nucc_Memory_Block) == 0x30, "Block size");

/* ========================================================================
 * Nucc::Memory::BlockAllocator
 * Allocator that manages a linked list of blocks. Has vtable.
 * Size proven: >= 0x48 (dtor accesses +0x44, GetBlockId accesses +0x08)
 * Vtable: PTR_FUN_14089c1b8 (set in ctor at 0x5858F0)
 * Evidence: BlockAllocator::BlockAllocator (0x5858F0), GetBlockId (0x585990),
 *           ~BlockAllocator (0x1D0640)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_BlockAllocator {
    void *vtable;               /* 0x00 - PTR_FUN_14089c1b8 */
    void *block_ptr;            /* 0x08 - IBlock* from BlockManager::GetBlock */
    uint16_t flags;             /* 0x10 - init 1 in ctor */
    uint8_t _pad_12[2];         /* 0x12 - alignment padding */
    uint32_t field_14;          /* 0x14 - init 0 in ctor */
    void *next_allocator;       /* 0x18 - linked list next (from dtor Vector3 ops) */
    void *field_20;             /* 0x20 - from dtor Vector3 yAxis */
    uint8_t _pad_28[4];         /* 0x28 - gap */
    uint32_t field_2C;          /* 0x2C - from dtor Vector3 zAxis low */
    uint8_t _pad_30[20];        /* 0x30 - padding to 0x44 */
    uint32_t field_44;          /* 0x44 - cleared in dtor */
} Nucc_Memory_BlockAllocator;

static_assert(offsetof(Nucc_Memory_BlockAllocator, vtable) == 0x00, "BlockAllocator.vtable");
static_assert(offsetof(Nucc_Memory_BlockAllocator, block_ptr) == 0x08, "BlockAllocator.block_ptr");
static_assert(offsetof(Nucc_Memory_BlockAllocator, flags) == 0x10, "BlockAllocator.flags");
static_assert(offsetof(Nucc_Memory_BlockAllocator, _pad_12) == 0x12, "BlockAllocator._pad_12");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_14) == 0x14, "BlockAllocator.field_14");
static_assert(offsetof(Nucc_Memory_BlockAllocator, next_allocator) == 0x18, "BlockAllocator.next_allocator");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_20) == 0x20, "BlockAllocator.field_20");
static_assert(offsetof(Nucc_Memory_BlockAllocator, _pad_28) == 0x28, "BlockAllocator._pad_28");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_2C) == 0x2C, "BlockAllocator.field_2C");
static_assert(offsetof(Nucc_Memory_BlockAllocator, _pad_30) == 0x30, "BlockAllocator._pad_30");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_44) == 0x44, "BlockAllocator.field_44");
static_assert(sizeof(Nucc_Memory_BlockAllocator) == 0x48, "BlockAllocator size");

/* ========================================================================
 * Nucc::Memory::BlockManager
 * Manages a std::vector<IBlock*> of memory blocks. Singleton via GetBlockManager.
 * Size proven: >= 0x18 (std::vector is 24 bytes = 3 pointers)
 * No vtable (not polymorphic itself, contains vector of IBlock*).
 * Evidence: BlockManager::Initialize (0x5B80D0), GetBlock (0x5B7F10),
 *           CreateBlock (0x5B7C20)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_BlockManager {
    void *vector_begin;         /* 0x00 - std::vector<IBlock*>::begin */
    void *vector_end;           /* 0x08 - std::vector<IBlock*>::end */
    void *vector_capacity;      /* 0x10 - std::vector<IBlock*>::capacity */
} Nucc_Memory_BlockManager;

static_assert(offsetof(Nucc_Memory_BlockManager, vector_begin) == 0x00, "BlockManager.vector_begin");
static_assert(offsetof(Nucc_Memory_BlockManager, vector_end) == 0x08, "BlockManager.vector_end");
static_assert(offsetof(Nucc_Memory_BlockManager, vector_capacity) == 0x10, "BlockManager.vector_capacity");
/* Size unknown, >= 0x18 — only vector fields proven in s2 decompiles */

/* ========================================================================
 * Nucc::Memory::StackBlock<16,3145728>
 * Stack-based memory block. Contains embedded BlockAllocator + sync fields.
 * Size proven: >= 0x30 (inner Block alloc is 0x30; outer has +0x28 access)
 * Vtable: PTR_FUN_140892a00 (set in Create at 0x5B7B70 after BlockAllocator ctor)
 * Evidence: StackBlock::Create (0x5B7B70), Destory (0x5B7DC0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_StackBlock {
    void *vtable;               /* 0x00 - PTR_FUN_140892a00 (after Create) */
    void *allocator_block;      /* 0x08 - inherited from BlockAllocator base */
    uint16_t allocator_flags;   /* 0x10 - inherited from BlockAllocator base */
    uint8_t _pad_12[6];         /* 0x12 - alignment padding */
    void *sync_point;           /* 0x18 - nummThreadSyncPointCreate result (puVar1[4]) */
    uint32_t field_20;          /* 0x20 - init 0 in Create (puVar1[5]=0) */
    uint8_t _pad_24[4];         /* 0x24 - alignment padding */
    uint64_t param_data;        /* 0x28 - param_2 stored in Create */
} Nucc_Memory_StackBlock;

static_assert(offsetof(Nucc_Memory_StackBlock, vtable) == 0x00, "StackBlock.vtable");
static_assert(offsetof(Nucc_Memory_StackBlock, allocator_block) == 0x08, "StackBlock.allocator_block");
static_assert(offsetof(Nucc_Memory_StackBlock, allocator_flags) == 0x10, "StackBlock.allocator_flags");
static_assert(offsetof(Nucc_Memory_StackBlock, _pad_12) == 0x12, "StackBlock._pad_12");
static_assert(offsetof(Nucc_Memory_StackBlock, sync_point) == 0x18, "StackBlock.sync_point");
static_assert(offsetof(Nucc_Memory_StackBlock, field_20) == 0x20, "StackBlock.field_20");
static_assert(offsetof(Nucc_Memory_StackBlock, _pad_24) == 0x24, "StackBlock._pad_24");
static_assert(offsetof(Nucc_Memory_StackBlock, param_data) == 0x28, "StackBlock.param_data");
/* Size unknown, >= 0x30 — last proven field at +0x28, inner alloc is 0x30 */
/* ========================================================================
 * Nucc::Memory: no instance state
 * All 6 methods are static/utility; no struct is emitted for this class.
 * Methods (all verified in s2 decompiles):
 *   - GetBlockManager  @ 0x5B7F40  returns global singleton DAT_140a9eb68
 *   - GetCurrentBlockId @ 0x585850 reads TLS offset 0x2ab0/0x2ac0
 *   - PushBlock        @ 0x5858B0 writes TLS stack at 0x2ab0/0x2ac0
 *   - PopBlock         @ 0x585880 decrements TLS stack index at 0x2ab0
 *   - SystemMemoryFree @ 0x62BA00 dlmalloc free wrapper, no this pointer
 *   - GetExclusion     @ 0x628740 dlmalloc mallinfo wrapper, no this pointer
 * Evidence: every signature has void param list or only non-this params;
 *           no method dereferences param_1 as an object pointer.
 * Instance state lives in nested classes: Block, BlockAllocator,
 * BlockManager, StackBlock (defined above).
 * ======================================================================== */
