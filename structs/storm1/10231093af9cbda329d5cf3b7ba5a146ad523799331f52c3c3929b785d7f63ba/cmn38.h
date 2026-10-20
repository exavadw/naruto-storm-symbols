/* cmn38.h - Nucc::Memory, Nucc::Memory::Block, Nucc::Memory::BlockManager,
 * Nucc::Quat_MathGeo, Nucc::ScaleOpType
 * Build: s1 (NSUNS1.exe, Storm 1 PC)
 * All layouts INFERRED from static decompilation, not CONFIRMED at runtime.
 * Generated 2026-10-19 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Quat_MathGeo
 * Value type: quaternion (4 floats). No vtable, no heap allocation.
 * Size proven: 16 bytes (param_1[0..3] as undefined4 in Set/SetFromXfbin)
 * Evidence: Nucc::Quat_MathGeo::Set (0x4B5730), SetFromXfbin (0x4B5810)
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
 * Evidence: Nucc::ScaleOpType::ToMatrix44 (0x4A7850), Offset (0x4A7820)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_ScaleOpType {
    uint64_t scale_op_data;     /* 0x00 - opaque math::ScaleOp handle */
} Nucc_ScaleOpType;

static_assert(offsetof(Nucc_ScaleOpType, scale_op_data) == 0x00, "ScaleOpType.scale_op_data");
static_assert(sizeof(Nucc_ScaleOpType) == 0x08, "ScaleOpType size");

/* ========================================================================
 * Nucc::Memory::Block
 * Heap-allocated block with vtable. Base class for memory blocks.
 * Size proven: >= 0x30 (operator_new(0x30,...) in StackBlock::Create at 0x4D2600)
 * Vtable: PTR_FUN_140743a90 (set in Block::Block ctor at 0x51FD00)
 * Evidence: Block::Block (0x51FD00), Block::Create (0x51FDD0), Block::Free (0x51FEC0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_Block {
    void *vtable;               /* 0x00 - PTR_FUN_140743a90 */
    int32_t block_id;           /* 0x08 - init 0xFFFFFFFF in ctor */
    uint8_t _pad_0C[4];         /* 0x0C - alignment padding */
    void *data_ptr;             /* 0x10 - allocated data pointer */
    void *field_18;             /* 0x18 - set in Create via FUN_14052f390 */
    void *field_20;             /* 0x20 - zeroed in ctor */
    uint64_t field_28;          /* 0x28 - set from SystemMemoryFree in Create */
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
 * Size proven: >= 0x48 (dtor accesses +0x44, GetBlockId accesses +0x30)
 * Vtable: PTR_FUN_140745358 (set in ctor at 0x47F1E0)
 * Evidence: BlockAllocator::BlockAllocator (0x47F1E0), GetBlockId (0x47F280),
 *           ~BlockAllocator (0x5615E0), GetBlockId (0x521720)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_BlockAllocator {
    void *vtable;               /* 0x00 - PTR_FUN_140745358 */
    void *block_ptr;            /* 0x08 - IBlock* from BlockManager::GetBlock */
    uint16_t flags;             /* 0x10 - init 1 in ctor */
    uint8_t _pad_12[2];         /* 0x12 - alignment padding */
    uint32_t field_14;          /* 0x14 - init 0 in ctor */
    void *next_allocator;       /* 0x18 - linked list next (from GetBlockId 0x521720) */
    void *field_20;             /* 0x20 - cleared in GetBlockId */
    uint8_t _pad_28[8];         /* 0x28 - gap */
    uint16_t field_30;          /* 0x30 - cleared in GetBlockId */
    uint8_t _pad_32[18];        /* 0x32 - padding to 0x44 */
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
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_30) == 0x30, "BlockAllocator.field_30");
static_assert(offsetof(Nucc_Memory_BlockAllocator, _pad_32) == 0x32, "BlockAllocator._pad_32");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_44) == 0x44, "BlockAllocator.field_44");
static_assert(sizeof(Nucc_Memory_BlockAllocator) == 0x48, "BlockAllocator size");

/* ========================================================================
 * Nucc::Memory::BlockManager
 * Manages a std::vector<IBlock*> of memory blocks. Singleton via GetBlockManager.
 * Size proven: >= 0x30 (global singleton at DAT_1408c64f8, vector is 24 bytes + fields)
 * No vtable (not polymorphic itself, contains vector of IBlock*).
 * Evidence: BlockManager::Initialize (0x4D2B50), GetBlock (0x4D29A0),
 *           GetBlockManager (0x4D29D0), CreateBlock (0x4D26B0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_BlockManager {
    void *vector_begin;         /* 0x00 - std::vector<IBlock*>::begin */
    void *vector_end;           /* 0x08 - std::vector<IBlock*>::end */
    void *vector_capacity;      /* 0x10 - std::vector<IBlock*>::capacity */
    int32_t field_18;           /* 0x18 - from GetBlockManager globals */
    int32_t field_1C;           /* 0x1C - init 0xFFFFFFFF */
    uint64_t field_20;          /* 0x20 - from globals */
    uint64_t field_28;          /* 0x28 - from globals */
} Nucc_Memory_BlockManager;

static_assert(offsetof(Nucc_Memory_BlockManager, vector_begin) == 0x00, "BlockManager.vector_begin");
static_assert(offsetof(Nucc_Memory_BlockManager, vector_end) == 0x08, "BlockManager.vector_end");
static_assert(offsetof(Nucc_Memory_BlockManager, vector_capacity) == 0x10, "BlockManager.vector_capacity");
static_assert(offsetof(Nucc_Memory_BlockManager, field_18) == 0x18, "BlockManager.field_18");
static_assert(offsetof(Nucc_Memory_BlockManager, field_1C) == 0x1C, "BlockManager.field_1C");
static_assert(offsetof(Nucc_Memory_BlockManager, field_20) == 0x20, "BlockManager.field_20");
static_assert(offsetof(Nucc_Memory_BlockManager, field_28) == 0x28, "BlockManager.field_28");
static_assert(sizeof(Nucc_Memory_BlockManager) == 0x30, "BlockManager size");

/* ========================================================================
 * Nucc::Memory::StackBlock<16,3145728>
 * Stack-based memory block extending BlockAllocator. Has vtable.
 * Size proven: >= 0x58 (Create accesses +0x28, Destory accesses +0x20,
 *   critical_section at +0x30 with estimated size >= 0x28)
 * Vtable: PTR_FUN_14073c520 (set in Create at 0x4D2400)
 * Evidence: StackBlock::Create (0x4D2400, 0x4D2600), Destory (0x4D2850)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_StackBlock {
    void *vtable;               /* 0x00 - PTR_FUN_14073c520 (after Create) */
    void *allocator_block;      /* 0x08 - from BlockAllocator base */
    uint16_t allocator_flags;   /* 0x10 - from BlockAllocator base */
    uint8_t _pad_12[6];         /* 0x12 - alignment padding */
    void *sync_point;           /* 0x18 - nummThreadSyncPointCreate result */
    uint32_t field_20;          /* 0x20 - init 0 in first Create */
    uint8_t _pad_24[4];         /* 0x24 - alignment padding */
    uint64_t param_data;        /* 0x28 - param_2 stored in Create */
    uint8_t critical_section[40]; /* 0x30 - nuccCriticalSection (size unknown, >= 0x28) */
} Nucc_Memory_StackBlock;

static_assert(offsetof(Nucc_Memory_StackBlock, vtable) == 0x00, "StackBlock.vtable");
static_assert(offsetof(Nucc_Memory_StackBlock, allocator_block) == 0x08, "StackBlock.allocator_block");
static_assert(offsetof(Nucc_Memory_StackBlock, allocator_flags) == 0x10, "StackBlock.allocator_flags");
static_assert(offsetof(Nucc_Memory_StackBlock, _pad_12) == 0x12, "StackBlock._pad_12");
static_assert(offsetof(Nucc_Memory_StackBlock, sync_point) == 0x18, "StackBlock.sync_point");
static_assert(offsetof(Nucc_Memory_StackBlock, field_20) == 0x20, "StackBlock.field_20");
static_assert(offsetof(Nucc_Memory_StackBlock, _pad_24) == 0x24, "StackBlock._pad_24");
static_assert(offsetof(Nucc_Memory_StackBlock, param_data) == 0x28, "StackBlock.param_data");
static_assert(offsetof(Nucc_Memory_StackBlock, critical_section) == 0x30, "StackBlock.critical_section");
static_assert(sizeof(Nucc_Memory_StackBlock) == 0x58, "StackBlock size");