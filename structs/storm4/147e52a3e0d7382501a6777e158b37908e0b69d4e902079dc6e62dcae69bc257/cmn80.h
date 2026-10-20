/* cmn80.h — CRI nus3 audio middleware struct layouts for Storm 4 (s4, NSUNS4_release.exe 1.09)
 * Reconstructed from Ghidra decompilation cache. All layouts INFERRED.
 * PC offsets only (x64 PE image base 0x140000000).
 * Own-game names only: s4 symbols/strings; cross-game names marked as such.
 */
#ifndef CMN80_S4_H
#define CMN80_S4_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nusc_ObjectBase — linked-list node used by nusc::ObjectCreate/Unlink
 * Size proven: ObjectCreate memsets param_3 + 0x18 bytes
 * Layout: type_id(4) + size(4) + next(8) + prev(8) = 24 = 0x18
 * ========================================================================= */
typedef struct __attribute__((packed)) nusc_ObjectBase {
    uint32_t type_id;              /* +0x00: set to param_2 in ObjectCreate */
    uint32_t size;                 /* +0x04: set to param_3 in ObjectCreate */
    struct nusc_ObjectBase *next;  /* +0x08: linked list next ptr */
    struct nusc_ObjectBase *prev;  /* +0x10: linked list prev ptr */
} nusc_ObjectBase;
static_assert(sizeof(nusc_ObjectBase) == 0x18, "nusc_ObjectBase size");
static_assert(offsetof(nusc_ObjectBase, type_id) == 0x00, "nusc_ObjectBase.type_id");
static_assert(offsetof(nusc_ObjectBase, size) == 0x04, "nusc_ObjectBase.size");
static_assert(offsetof(nusc_ObjectBase, next) == 0x08, "nusc_ObjectBase.next");
static_assert(offsetof(nusc_ObjectBase, prev) == 0x10, "nusc_ObjectBase.prev");

/* =========================================================================
 * NutBuffer — texture/buffer handle wrapper
 * Size unknown; >= 0x10 proven (ptr at +0, bool flag at byte offset +8)
 * ========================================================================= */
typedef struct __attribute__((packed)) NutBuffer {
    void *data_ptr;                /* +0x00: allocated buffer pointer */
    uint8_t in_block_manager;      /* +0x08: 1 if allocated via BlockManager */
    uint8_t pad_09[7];             /* +0x09: padding */
} NutBuffer;
static_assert(offsetof(NutBuffer, data_ptr) == 0x00, "NutBuffer.data_ptr");
static_assert(offsetof(NutBuffer, in_block_manager) == 0x08, "NutBuffer.in_block_manager");

/* =========================================================================
 * nus3_CObject — base class with name string and linked-list search
 * Fields from SearchObject: name ptr at +8, next ptr at +0x18
 * Size unknown; >= 0x20 proven
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CObject {
    void *vtable;                  /* +0x00: vtable pointer */
    char *name;                    /* +0x08: object name string (strncmp 0x1f max) */
    uint8_t pad_10[8];             /* +0x10: gap */
    struct nus3_CObject *next;     /* +0x18: linked list next for SearchObject */
} nus3_CObject;
static_assert(offsetof(nus3_CObject, vtable) == 0x00, "nus3_CObject.vtable");
static_assert(offsetof(nus3_CObject, name) == 0x08, "nus3_CObject.name");
static_assert(offsetof(nus3_CObject, next) == 0x18, "nus3_CObject.next");

/* =========================================================================
 * nus3_CHandle — shared handle wrapper pattern used by
 * HTone, HBank, HPlayer, HListener, HGroup
 * Magic validation: *(int*)(this+0x14)==0x876500, seq==DAT_148d304b0, released==0
 * Internal object ptr at +8, dispatches via vtable or helper functions.
 * Size unknown; >= 0x20 proven (fields up to +0x18 checked)
 * s4 globals: DAT_148d304b0 (sequence), DAT_148d30411 (active flag)
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CHandle {
    void *vtable;                  /* +0x00: vtable pointer */
    void *internal_obj;            /* +0x08: pointer to internal implementation object */
    uint32_t sequence;             /* +0x10: sequence counter, validated against DAT_148d304b0 */
    uint32_t magic;                /* +0x14: must be 0x876500 */
    uint8_t released;              /* +0x18: 0 = active, non-zero = released */
    uint8_t pad_19[7];             /* +0x19: padding */
} nus3_CHandle;
static_assert(offsetof(nus3_CHandle, vtable) == 0x00, "nus3_CHandle.vtable");
static_assert(offsetof(nus3_CHandle, internal_obj) == 0x08, "nus3_CHandle.internal_obj");
static_assert(offsetof(nus3_CHandle, sequence) == 0x10, "nus3_CHandle.sequence");
static_assert(offsetof(nus3_CHandle, magic) == 0x14, "nus3_CHandle.magic");
static_assert(offsetof(nus3_CHandle, released) == 0x18, "nus3_CHandle.released");

/* HTone, HBank, HPlayer, HListener, HGroup all use the CHandle layout above.
 * They differ only in which dispatch function is called through internal_obj.
 * No additional fields observed beyond the CHandle base. */
typedef nus3_CHandle nus3_HTone;
typedef nus3_CHandle nus3_HBank;
typedef nus3_CHandle nus3_HPlayer;
typedef nus3_CHandle nus3_HListener;
typedef nus3_CHandle nus3_HGroup;

/* =========================================================================
 * nus3_CToneBase — tone configuration base, inherits from CObject
 * Fields from Create and AssignPlayer pseudocode
 * Size proven: 0x278 (type 0) or 0x1d8 (type 1) from CSystem::CreateToneObject
 * Using larger size 0x278 as upper bound
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CToneBase {
    /* CObject base (0x00-0x1F) */
    void *vtable;                  /* +0x00 */
    char *name;                    /* +0x08 */
    uint8_t pad_10[8];             /* +0x10 */
    struct nus3_CObject *next;     /* +0x18 */
    /* CToneBase own fields */
    uint8_t pad_20[32];            /* +0x20: gap to 0x40 */
    void *config_ptr_40;           /* +0x40: param_2 copy in Create */
    uint8_t pad_48[16];            /* +0x48: gap */
    void *group_or_config;         /* +0x58: param_2 in Create */
    void *bank_ptr;                /* +0x60: param_3 in Create */
    uint8_t pad_68[13];            /* +0x68: gap */
    uint8_t flag_75;               /* +0x75: zeroed in Create */
    uint8_t pad_76[3];             /* +0x76 */
    uint8_t bool_flag_79;          /* +0x79: bool set in Create */
    uint8_t pad_7a[30];            /* +0x7A: gap to 0x98 */
    void *player_ptr;              /* +0x98: set in AssignPlayer */
    uint8_t pad_a0[8];             /* +0xA0: gap */
    uint32_t assign_param;         /* +0xA8: uint32 from AssignPlayer param_3 */
    uint8_t pad_ac[340];           /* +0xAC: gap to 0x200 */
    uint32_t register_u32_200;     /* +0x200: param_4 in Create */
    uint8_t pad_204[116];          /* +0x204: gap to 0x278 */
} nus3_CToneBase;
static_assert(sizeof(nus3_CToneBase) == 0x278, "nus3_CToneBase size");
static_assert(offsetof(nus3_CToneBase, vtable) == 0x00, "CToneBase.vtable");
static_assert(offsetof(nus3_CToneBase, name) == 0x08, "CToneBase.name");
static_assert(offsetof(nus3_CToneBase, next) == 0x18, "CToneBase.next");
static_assert(offsetof(nus3_CToneBase, config_ptr_40) == 0x40, "CToneBase.config_ptr_40");
static_assert(offsetof(nus3_CToneBase, group_or_config) == 0x58, "CToneBase.group_or_config");
static_assert(offsetof(nus3_CToneBase, bank_ptr) == 0x60, "CToneBase.bank_ptr");
static_assert(offsetof(nus3_CToneBase, flag_75) == 0x75, "CToneBase.flag_75");
static_assert(offsetof(nus3_CToneBase, bool_flag_79) == 0x79, "CToneBase.bool_flag_79");
static_assert(offsetof(nus3_CToneBase, player_ptr) == 0x98, "CToneBase.player_ptr");
static_assert(offsetof(nus3_CToneBase, assign_param) == 0xA8, "CToneBase.assign_param");
static_assert(offsetof(nus3_CToneBase, register_u32_200) == 0x200, "CToneBase.register_u32_200");

/* =========================================================================
 * nus3_CSingleTone — single-tone variant, inherits from CToneBase
 * Size proven: 0x278 (same allocation as CToneBase type 0)
 * Sub-object at +0x230 accessed via vtable dispatch in CSingleTone::Create
 * The sub_object occupies bytes 0x230..0x277 within the same 0x278 allocation.
 * We model it as CToneBase fields up to 0x230, then the sub_object region.
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CSingleTone {
    /* CObject base (0x00-0x1F) */
    void *vtable;                  /* +0x00 */
    char *name;                    /* +0x08 */
    uint8_t pad_10[8];             /* +0x10 */
    struct nus3_CObject *next;     /* +0x18 */
    /* CToneBase own fields (0x20-0x22F) */
    uint8_t pad_20[32];            /* +0x20: gap to 0x40 */
    void *config_ptr_40;           /* +0x40 */
    uint8_t pad_48[16];            /* +0x48 */
    void *group_or_config;         /* +0x58 */
    void *bank_ptr;                /* +0x60 */
    uint8_t pad_68[13];            /* +0x68 */
    uint8_t flag_75;               /* +0x75 */
    uint8_t pad_76[3];             /* +0x76 */
    uint8_t bool_flag_79;          /* +0x79 */
    uint8_t pad_7a[30];            /* +0x7A */
    void *player_ptr;              /* +0x98 */
    uint8_t pad_a0[8];             /* +0xA0 */
    uint32_t assign_param;         /* +0xA8 */
    uint8_t pad_ac[340];           /* +0xAC: gap to 0x200 */
    uint32_t register_u32_200;     /* +0x200 */
    uint8_t pad_204[44];           /* +0x204: gap to 0x230 */
    /* CSingleTone sub-object region (0x230-0x277) */
    uint8_t sub_object[72];        /* +0x230: embedded tone sub-object with vtable */
} nus3_CSingleTone;
static_assert(sizeof(nus3_CSingleTone) == 0x278, "nus3_CSingleTone size");
static_assert(offsetof(nus3_CSingleTone, config_ptr_40) == 0x40, "CSingleTone.config_ptr_40");
static_assert(offsetof(nus3_CSingleTone, sub_object) == 0x230, "CSingleTone.sub_object");

/* =========================================================================
 * nus3_CRandomizerBase — randomization config holder
 * Size unknown; >= 0x60 proven (randomizer_data ptr at +0x58)
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CRandomizerBase {
    uint8_t pad_00[88];            /* +0x00: unknown base fields */
    void *randomizer_data;         /* +0x58: config block with count at +0x10 */
} nus3_CRandomizerBase;
static_assert(offsetof(nus3_CRandomizerBase, randomizer_data) == 0x58, "CRandomizerBase.randomizer_data");

/* =========================================================================
 * nus3_CSystem — audio system manager singleton
 * Size unknown; >= 0xF0 proven (last field at +0xE8)
 * Factory allocations: Group=0x190, Player=0xC8, Tone=0x278/0x1d8
 * s4 global: DAT_1415af82c (tone sequence counter), DAT_1415af81c (sample rate?)
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CSystem {
    uint8_t pad_00[36];            /* +0x00: unknown init fields */
    uint32_t field_24;             /* +0x24: read in CreateGroupObject */
    uint8_t pad_28[4];             /* +0x28 */
    uint32_t field_2c;             /* +0x2C: read in CreateGroupObject */
    uint8_t pad_30[28];            /* +0x30 */
    uint32_t field_4c;             /* +0x4C: read in Init */
    uint8_t pad_50[152];           /* +0x50 */
    uint32_t field_e8;             /* +0xE8: read in CreateToneObject */
    uint8_t pad_ec[4];             /* +0xEC: padding to 0xF0 */
} nus3_CSystem;
static_assert(offsetof(nus3_CSystem, field_24) == 0x24, "CSystem.field_24");
static_assert(offsetof(nus3_CSystem, field_2c) == 0x2C, "CSystem.field_2c");
static_assert(offsetof(nus3_CSystem, field_4c) == 0x4C, "CSystem.field_4c");
static_assert(offsetof(nus3_CSystem, field_e8) == 0xE8, "CSystem.field_e8");

#endif /* CMN80_S4_H */