/*
 * cmn34 struct group — Build s4 (NSUNS4_release.exe, NARUTO STORM 4 PC 1.09)
 * Reconstructed from static decompilation only. All layouts are INFERRED.
 * Offsets derived from s4 x64 code (image base 0x140000000).
 * Names from s4 symbols/strings only (own-game naming rule).
 * Packed layout with explicit padding; static_assert for every field.
 */

#ifndef CMN34_S4_H
#define CMN34_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * mmVertexDataBase
 * Base class with multiple embedded sub-objects (linked lists, allocators).
 * Evidence: ctor 0x18E390 (34 accesses), ctor 0x9F8BC0 (13 accesses).
 * Size = 0x138 (proven by _aligned_malloc(0x138,0x10) in QuadRenderer::Initialize 0x18EB50
 * and mmVertexData::CreateData 0x19A990).
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x14];       /* 0x00 - vtable + header (not resolved) */
    uint8_t field_0x14;           /* 0x14 - byte, zeroed in ctor 0x18E390 */
    uint8_t pad_0x15[0x43];       /* 0x15 */
    uint32_t field_0x58;          /* 0x58 - zeroed in ctor [0xb] */
    uint8_t pad_0x5c[0x04];       /* 0x5c - align to 0x60 */
    uint64_t sub_list_a_head;     /* 0x60 - zeroed [0xc] */
    uint64_t sub_list_a_tail;     /* 0x68 - zeroed [0xd] */
    uint64_t sub_list_b_prev;     /* 0x70 - not directly accessed */
    uint64_t sub_list_b_next;     /* 0x78 - rw, zeroed then self-linked [0xf] */
    uint64_t sub_list_b_sentinel; /* 0x80 - zeroed [0x10] */
    uint64_t sub_list_b_end;      /* 0x88 - PTR_LAB_1412f85f0 sentinel [0x11] */
    uint64_t field_0x90;          /* 0x90 - rw, mixed 1/8 byte writes [0x12] */
    uint32_t field_0x98;          /* 0x98 - zeroed [0x13] */
    uint8_t pad_0x9c[0x04];       /* 0x9c - align to 0xa0 */
    uint64_t sub_list_c_ptr;      /* 0xa0 - rw, address-taken [0x14] */
    uint64_t sub_list_c_head;     /* 0xa8 - zeroed [0x15] */
    uint64_t sub_list_c_tail;     /* 0xb0 - zeroed [0x16] */
    uint64_t sub_list_c_sentinel; /* 0xb8 - zeroed [0x17] */
    uint32_t field_0xc0;          /* 0xc0 - zeroed [0x18] */
    uint8_t pad_0xc4[0x04];       /* 0xc4 - align to 0xc8 */
    uint64_t sub_list_d_prev;     /* 0xc8 - PTR_LAB_1412f85f0 [0x19] */
    uint64_t sub_list_d_next;     /* 0xd0 - copies field_0x90 [0x1a] */
    uint64_t field_0xd8;          /* 0xd8 - zeroed [0x1b] */
    uint32_t field_0xe0;          /* 0xe0 - zeroed [0x1c] */
    uint8_t pad_0xe4[0x04];       /* 0xe4 - align to 0xe8 */
    uint64_t sub_list_e_sentinel; /* 0xe8 - PTR_LAB_1412f85f0 [0x1d] */
    uint64_t field_0xf0;          /* 0xf0 - zeroed [0x1e] */
    uint8_t pad_0xf8[0x08];       /* 0xf8 - align to 0x100 */
    uint64_t field_0x100;         /* 0x100 - read-only, address-taken [0x20] */
    uint64_t field_0x108;         /* 0x108 - zeroed [0x21] */
    uint64_t field_0x110;         /* 0x110 - zeroed [0x22] */
    uint64_t field_0x118;         /* 0x118 - zeroed [0x23] */
    uint32_t field_0x120;         /* 0x120 - zeroed [0x24] */
    uint8_t pad_0x124[0x04];      /* 0x124 - align to 0x128 */
    uint64_t sub_list_f_sentinel; /* 0x128 - PTR_LAB_1412f85f0 [0x25] */
    uint64_t field_0x130;         /* 0x130 - zeroed [0x26] */
} mmVertexDataBase_s4;

static_assert(sizeof(mmVertexDataBase_s4) == 0x138, "mmVertexDataBase_s4 size");
static_assert(offsetof(mmVertexDataBase_s4, field_0x14) == 0x14, "mmVertexDataBase.field_0x14");
static_assert(offsetof(mmVertexDataBase_s4, field_0x58) == 0x58, "mmVertexDataBase.field_0x58");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_a_head) == 0x60, "mmVertexDataBase.sub_list_a_head");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_a_tail) == 0x68, "mmVertexDataBase.sub_list_a_tail");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_prev) == 0x70, "mmVertexDataBase.sub_list_b_prev");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_next) == 0x78, "mmVertexDataBase.sub_list_b_next");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_sentinel) == 0x80, "mmVertexDataBase.sub_list_b_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_b_end) == 0x88, "mmVertexDataBase.sub_list_b_end");
static_assert(offsetof(mmVertexDataBase_s4, field_0x90) == 0x90, "mmVertexDataBase.field_0x90");
static_assert(offsetof(mmVertexDataBase_s4, field_0x98) == 0x98, "mmVertexDataBase.field_0x98");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_ptr) == 0xa0, "mmVertexDataBase.sub_list_c_ptr");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_head) == 0xa8, "mmVertexDataBase.sub_list_c_head");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_tail) == 0xb0, "mmVertexDataBase.sub_list_c_tail");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_c_sentinel) == 0xb8, "mmVertexDataBase.sub_list_c_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, field_0xc0) == 0xc0, "mmVertexDataBase.field_0xc0");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_d_prev) == 0xc8, "mmVertexDataBase.sub_list_d_prev");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_d_next) == 0xd0, "mmVertexDataBase.sub_list_d_next");
static_assert(offsetof(mmVertexDataBase_s4, field_0xd8) == 0xd8, "mmVertexDataBase.field_0xd8");
static_assert(offsetof(mmVertexDataBase_s4, field_0xe0) == 0xe0, "mmVertexDataBase.field_0xe0");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_e_sentinel) == 0xe8, "mmVertexDataBase.sub_list_e_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, field_0xf0) == 0xf0, "mmVertexDataBase.field_0xf0");
static_assert(offsetof(mmVertexDataBase_s4, field_0x100) == 0x100, "mmVertexDataBase.field_0x100");
static_assert(offsetof(mmVertexDataBase_s4, field_0x108) == 0x108, "mmVertexDataBase.field_0x108");
static_assert(offsetof(mmVertexDataBase_s4, field_0x110) == 0x110, "mmVertexDataBase.field_0x110");
static_assert(offsetof(mmVertexDataBase_s4, field_0x118) == 0x118, "mmVertexDataBase.field_0x118");
static_assert(offsetof(mmVertexDataBase_s4, field_0x120) == 0x120, "mmVertexDataBase.field_0x120");
static_assert(offsetof(mmVertexDataBase_s4, sub_list_f_sentinel) == 0x128, "mmVertexDataBase.sub_list_f_sentinel");
static_assert(offsetof(mmVertexDataBase_s4, field_0x130) == 0x130, "mmVertexDataBase.field_0x130");

/* =========================================================================
 * mmVertexDataFlexible
 * Flexible vertex buffer with dynamic offset info linked list.
 * Evidence: CreateData 0x1969F0 (writes through param_1[0x11] at offset 0x88).
 * Size >= 0x90 (last field at 0x88, 8 bytes). No allocator size found in callers.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x14];            /* 0x00 - vtable + header */
    uint8_t field_0x14;                /* 0x14 - byte, zeroed in CreateData */
    uint8_t pad_0x15[0x17];            /* 0x15 */
    uint32_t field_0x2c;               /* 0x2c - rw, compared < 3 in SetOffsetInfo */
    uint8_t pad_0x30[0x28];            /* 0x30 */
    uint64_t field_0x58;               /* 0x58 - zeroed [0xb] */
    uint64_t offset_info_list_head;    /* 0x60 - zeroed [0xc] */
    uint64_t offset_info_list_tail;    /* 0x68 - zeroed [0xd] */
    uint64_t field_0x70;               /* 0x70 - zeroed [0xe] */
    uint64_t field_0x78;               /* 0x78 - PTR_LAB_1412f85f0 sentinel [0xf] */
    uint64_t field_0x80;               /* 0x80 - zeroed [0x10] */
    void *shadow_copy;                 /* 0x88 - optional shadow buffer [0x11] */
} mmVertexDataFlexible_s4;

static_assert(offsetof(mmVertexDataFlexible_s4, field_0x14) == 0x14, "mmVertexDataFlexible.field_0x14");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x2c) == 0x2c, "mmVertexDataFlexible.field_0x2c");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x58) == 0x58, "mmVertexDataFlexible.field_0x58");
static_assert(offsetof(mmVertexDataFlexible_s4, offset_info_list_head) == 0x60, "mmVertexDataFlexible.offset_info_list_head");
static_assert(offsetof(mmVertexDataFlexible_s4, offset_info_list_tail) == 0x68, "mmVertexDataFlexible.offset_info_list_tail");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x70) == 0x70, "mmVertexDataFlexible.field_0x70");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x78) == 0x78, "mmVertexDataFlexible.field_0x78");
static_assert(offsetof(mmVertexDataFlexible_s4, field_0x80) == 0x80, "mmVertexDataFlexible.field_0x80");
static_assert(offsetof(mmVertexDataFlexible_s4, shadow_copy) == 0x88, "mmVertexDataFlexible.shadow_copy");

/* =========================================================================
 * mmVertexData
 * Concrete vertex data object.
 * Evidence: ~mmVertexData dtor writes DAT globals at 0x24, 0x2c; reads 0x70.
 * Size >= 0x78 (last accessed offset 0x70, size unknown).
 * Note: mmVertexData::CreateData 0x19A990 allocates 0x138 for the base
 * mmVertexDataBase sub-object, not for mmVertexData itself.
 * ========================================================================= */
typedef struct __attribute__((packed)) {
    uint8_t pad_0x00[0x24];       /* 0x00 - vtable + header */
    uint64_t field_0x24;          /* 0x24 - DAT_1482d96d8 written in dtor */
    uint32_t field_0x2c;          /* 0x2c - DAT_1482d96e0 written in dtor */
    uint8_t pad_0x30[0x40];       /* 0x30 */
    uint64_t field_0x70;          /* 0x70 - read in dtor (sub-object ptr?) */
} mmVertexData_s4;

static_assert(offsetof(mmVertexData_s4, field_0x24) == 0x24, "mmVertexData.field_0x24");
static_assert(offsetof(mmVertexData_s4, field_0x2c) == 0x2c, "mmVertexData.field_0x2c");
static_assert(offsetof(mmVertexData_s4, field_0x70) == 0x70, "mmVertexData.field_0x70");

/* =========================================================================
 * mmVertexSemantic — 0 fields resolved by state_surface in s4.
 * Methods: AddSemantic, GetSemanticSize, GetSemanticOffset.
 * All accesses were byte-cast; no typed field offsets recovered.
 * ========================================================================= */

/* =========================================================================
 * mmVBRenderInfoList — 0 fields resolved by state_surface in s4.
 * Methods: Add (3 overloads).
 * All accesses were byte-cast; no typed field offsets recovered.
 * ========================================================================= */

/* =========================================================================
 * mmVertexShader — 0 fields resolved by state_surface in s4.
 * Methods: LoadFromCompiledFile (2 overloads), LoadFromCompiledMemory.
 * All accesses were byte-cast; no typed field offsets recovered.
 * ========================================================================= */

/* =========================================================================
 * mmVertexDataStream — 0 fields resolved by state_surface in s4.
 * Methods: CreateData, CreateDataStream, Release.
 * All accesses were byte-cast; no typed field offsets recovered.
 * ========================================================================= */

/* =========================================================================
 * mmUTF8 — 0 fields resolved by state_surface in s4.
 * Methods: Next, GetCodePoint (+ others).
 * All accesses were byte-cast; no typed field offsets recovered.
 * ========================================================================= */

#endif /* CMN34_S4_H */