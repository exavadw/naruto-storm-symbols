/* cmn38.h - Nucc::Memory, Nucc::Memory::Block, Nucc::Memory::BlockManager,
 * Nucc::Quat_MathGeo, Nucc::ScaleOpType
 * Build: s3 (NSUNS3.exe, Storm 3 Full Burst HD PC)
 * All layouts INFERRED from static decompilation, not CONFIRMED at runtime.
 * Generated 2026-10-19 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Quat_MathGeo
 * Value type: quaternion (4 floats). No vtable, no heap allocation.
 * Size proven: 16 bytes (param_1[0..3] as undefined4 in Set at 0x69B0C0)
 * Evidence: Nucc::Quat_MathGeo::Set (0x69B0C0), SetFromXfbin (0x69B180)
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
 * Evidence: Nucc::ScaleOpType::ToMatrix44 (0x6A2D30), Offset (0x6A2D00)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_ScaleOpType {
    uint64_t scale_op_data;     /* 0x00 - opaque math::ScaleOp handle */
} Nucc_ScaleOpType;

static_assert(offsetof(Nucc_ScaleOpType, scale_op_data) == 0x00, "ScaleOpType.scale_op_data");
static_assert(sizeof(Nucc_ScaleOpType) == 0x08, "ScaleOpType size");

/* ========================================================================
 * Nucc::Memory::Block
 * Heap-allocated block with vtable. Base class for memory blocks.
 * Size proven: 0x30 (operator_new(0x30) in BlockManager::CreateBlock at 0x6C3710)
 * Vtable: PTR_FUN_1409e7d00 (set in Block::Block ctor at 0x7152E0)
 * Evidence: Block::Block (0x7152E0), Block::Create (0x7153B0), Block::Free (0x7154A0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_Block {
    void *vtable;               /* 0x00 - PTR_FUN_1409e7d00 */
    int32_t block_id;           /* 0x08 - init 0xFFFFFFFF in ctor */
    uint8_t _pad_0C[4];         /* 0x0C - alignment padding */
    void *data_ptr;             /* 0x10 - allocated data pointer (param_1[2] in Create) */
    void *field_18;             /* 0x18 - param_1[3], set via FUN_14072f4c0 in Create */
    void *field_20;             /* 0x20 - set to param_2 in ctor (param_1[4]) */
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
 * Size proven: >= 0x48 (dtor clears field_44 at +0x44 in ~BlockAllocator at 0x18C720)
 * Vtable: PTR_FUN_1408a4ed8 (set in dtor at 0x18C720)
 * Evidence: BlockAllocator::~BlockAllocator (0x18C720), GetBlockId (0x181E88)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_BlockAllocator {
    void *vtable;               /* 0x00 - PTR_FUN_1408a4ed8 */
    uint8_t vector3_base[12];   /* 0x08 - Nucc::Vector3 (12 bytes, from dtor Vector3 ctor) */
    uint32_t field_14;          /* 0x14 - gap between Vector3 base and first axis Vector3 */
    uint8_t vector3_xAxis[12];  /* 0x18 - Nucc::Vector3 xAxis (from dtor) */
    uint32_t field_24;          /* 0x24 - padding after xAxis */
    uint8_t vector3_yAxis[12];  /* 0x28 - Nucc::Vector3 yAxis (from dtor) */
    uint32_t field_34;          /* 0x34 - padding after yAxis */
    uint8_t vector3_zAxis[12];  /* 0x38 - Nucc::Vector3 zAxis (from dtor) */
    uint32_t field_44;          /* 0x44 - cleared in dtor */
} Nucc_Memory_BlockAllocator;

static_assert(offsetof(Nucc_Memory_BlockAllocator, vtable) == 0x00, "BlockAllocator.vtable");
static_assert(offsetof(Nucc_Memory_BlockAllocator, vector3_base) == 0x08, "BlockAllocator.vector3_base");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_14) == 0x14, "BlockAllocator.field_14");
static_assert(offsetof(Nucc_Memory_BlockAllocator, vector3_xAxis) == 0x18, "BlockAllocator.vector3_xAxis");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_24) == 0x24, "BlockAllocator.field_24");
static_assert(offsetof(Nucc_Memory_BlockAllocator, vector3_yAxis) == 0x28, "BlockAllocator.vector3_yAxis");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_34) == 0x34, "BlockAllocator.field_34");
static_assert(offsetof(Nucc_Memory_BlockAllocator, vector3_zAxis) == 0x38, "BlockAllocator.vector3_zAxis");
static_assert(offsetof(Nucc_Memory_BlockAllocator, field_44) == 0x44, "BlockAllocator.field_44");
/* Size unknown, >= 0x48 — last proven field at +0x44, dtor accesses it */

/* ========================================================================
 * Nucc::Memory::BlockManager
 * Manages a std::vector<IBlock*> of memory blocks. Singleton via GetBlockManager.
 * Size proven: >= 0x18 (std::vector is 24 bytes = 3 pointers)
 * No vtable (not polymorphic itself, contains vector of IBlock*).
 * Evidence: BlockManager::Initialize (0x6C3BB0), GetBlockManager (0x6C3A30),
 *           CreateBlock (0x6C3710)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_BlockManager {
    void *vector_begin;         /* 0x00 - std::vector<IBlock*>::begin */
    void *vector_end;           /* 0x08 - std::vector<IBlock*>::end */
    void *vector_capacity;      /* 0x10 - std::vector<IBlock*>::capacity */
} Nucc_Memory_BlockManager;

static_assert(offsetof(Nucc_Memory_BlockManager, vector_begin) == 0x00, "BlockManager.vector_begin");
static_assert(offsetof(Nucc_Memory_BlockManager, vector_end) == 0x08, "BlockManager.vector_end");
static_assert(offsetof(Nucc_Memory_BlockManager, vector_capacity) == 0x10, "BlockManager.vector_capacity");
/* Size unknown, >= 0x18 — only vector fields proven in s3 decompiles */

/* ========================================================================
 * Nucc::Memory::StackBlock<16,3145728>
 * Stack-based memory block wrapper. Contains pointer to inner BlockAllocator.
 * Size proven: >= 0x30 (inner Block alloc is 0x30; outer has +0x28 access)
 * Inner vtable: PTR_FUN_1409e0ff8 (set in Create at 0x6C3660 after BlockAllocator ctor)
 * Evidence: StackBlock::Create (0x6C3660), Destory (0x6C38B0)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Memory_StackBlock {
    uint8_t _pad_00[8];         /* 0x00 - unknown (GetOwnerHandle reads +0x08) */
    void *block_allocator;      /* 0x08 - pointer to inner BlockAllocator (from Create) */
    void *allocator_param;      /* 0x10 - passed to operator_new as allocator (param_1+0x10) */
    uint8_t _pad_18[8];         /* 0x18 - gap */
    void *inner_block_ptr;      /* 0x20 - stored at param_1+0x20 in Create, read in Destory */
    uint32_t param_data;        /* 0x28 - param_2 stored in Create, read in Destory */
    uint8_t _pad_2C[4];         /* 0x2C - alignment padding */
} Nucc_Memory_StackBlock;

static_assert(offsetof(Nucc_Memory_StackBlock, _pad_00) == 0x00, "StackBlock._pad_00");
static_assert(offsetof(Nucc_Memory_StackBlock, block_allocator) == 0x08, "StackBlock.block_allocator");
static_assert(offsetof(Nucc_Memory_StackBlock, allocator_param) == 0x10, "StackBlock.allocator_param");
static_assert(offsetof(Nucc_Memory_StackBlock, _pad_18) == 0x18, "StackBlock._pad_18");
static_assert(offsetof(Nucc_Memory_StackBlock, inner_block_ptr) == 0x20, "StackBlock.inner_block_ptr");
static_assert(offsetof(Nucc_Memory_StackBlock, param_data) == 0x28, "StackBlock.param_data");
static_assert(offsetof(Nucc_Memory_StackBlock, _pad_2C) == 0x2C, "StackBlock._pad_2C");
/* Size unknown, >= 0x30 — last proven field at +0x28, inner alloc is 0x30 */