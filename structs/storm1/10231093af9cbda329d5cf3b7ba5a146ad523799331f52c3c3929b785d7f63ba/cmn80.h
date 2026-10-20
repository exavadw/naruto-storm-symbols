/* cmn80.h — CRI nus3 audio middleware struct layouts for Storm 1 (s1, NSUNS1.exe)
 * Reconstructed from Ghidra decompilation cache. All layouts INFERRED.
 * PC offsets only (x64 PE image base 0x140000000).
 * Own-game names only: no cross-game name imports.
 */
#ifndef CMN80_H
#define CMN80_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nusc::ObjectBase — linked-list node used by nusc::ObjectCreate/Unlink
 * Size proven: ObjectCreate memsets param_3 + 0x18 bytes
 * Layout: type_id(4) + size(4) + next(8) + prev(8) = 24 = 0x18
 * ========================================================================= */
typedef struct __attribute__((packed)) nusc_ObjectBase {
    uint32_t type_id;               /* +0x00: set to param_2 in ObjectCreate */
    uint32_t size;                  /* +0x04: set to param_3 in ObjectCreate */
    struct nusc_ObjectBase *next;   /* +0x08: linked list next ptr */
    struct nusc_ObjectBase *prev;   /* +0x10: linked list prev ptr */
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
    void *data_ptr;                 /* +0x00: allocated buffer pointer */
    uint8_t in_block_manager;       /* +0x08: 1 if allocated via BlockManager */
    uint8_t pad_09[7];              /* +0x09: padding */
} NutBuffer;
static_assert(offsetof(NutBuffer, data_ptr) == 0x00, "NutBuffer.data_ptr");
static_assert(offsetof(NutBuffer, in_block_manager) == 0x08, "NutBuffer.in_block_manager");

/* =========================================================================
 * nus3::CObject — base class with name string and linked-list search
 * Fields from SearchObject: name ptr at +8, next ptr at +0x18
 * Size unknown; >= 0x20 proven
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CObject {
    void *vtable;                   /* +0x00: vtable pointer */
    char *name;                     /* +0x08: object name string (strncmp 0x1f max) */
    uint8_t pad_10[8];              /* +0x10: gap */
    struct nus3_CObject *next;      /* +0x18: linked list next for SearchObject */
} nus3_CObject;
static_assert(offsetof(nus3_CObject, vtable) == 0x00, "nus3_CObject.vtable");
static_assert(offsetof(nus3_CObject, name) == 0x08, "nus3_CObject.name");
static_assert(offsetof(nus3_CObject, next) == 0x18, "nus3_CObject.next");

/* =========================================================================
 * nus3::CHandle<T> — shared handle wrapper pattern used by
 * HTone, HBank, HPlayer, HListener, HGroup
 * Magic validation: *(int*)(this+0x14)==0x876500, seq==DAT_140b8ba5c, released==0
 * Internal object ptr at +8, dispatches via FUN_140600990/FUN_140603bc0 etc.
 * Size unknown; >= 0x20 proven (fields up to +0x18 checked)
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CHandle {
    void *vtable;                   /* +0x00: vtable pointer */
    void *internal_obj;             /* +0x08: pointer to internal implementation object */
    uint32_t sequence;              /* +0x10: sequence counter, validated against DAT_140b8ba5c */
    uint32_t magic;                 /* +0x14: must be 0x876500 */
    uint8_t released;               /* +0x18: 0 = active, non-zero = released */
    uint8_t pad_19[7];              /* +0x19: padding */
} nus3_CHandle;
static_assert(offsetof(nus3_CHandle, vtable) == 0x00, "nus3_CHandle.vtable");
static_assert(offsetof(nus3_CHandle, internal_obj) == 0x08, "nus3_CHandle.internal_obj");
static_assert(offsetof(nus3_CHandle, sequence) == 0x10, "nus3_CHandle.sequence");
static_assert(offsetof(nus3_CHandle, magic) == 0x14, "nus3_CHandle.magic");
static_assert(offsetof(nus3_CHandle, released) == 0x18, "nus3_CHandle.released");

/* =========================================================================
 * nus3::HTone — tone handle, CHandle layout (no additional fields)
 * Methods: SetPan(0x5FE490), SetPitch(0x5FE410), IsFinished(0x5FE680),
 *          KeyOff(0x5FE6E0), SetVolume(0x5FE510), SetPause(0x5FE5A0)
 * Size unknown, >= 0x20 proven (CHandle fields up to +0x18 validated)
 * state_surface returned 0 typed fields (byte-cast dispatch only);
 * layout INFERRED from manual pseudocode inspection of SetVolume/IsFinished.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct nus3_HTone {
    void *vtable;                   /* +0x00 */
    void *internal_obj;             /* +0x08 */
    uint32_t sequence;              /* +0x10 */
    uint32_t magic;                 /* +0x14: 0x876500 */
    uint8_t released;               /* +0x18 */
    uint8_t pad_19[7];              /* +0x19 */
} nus3_HTone;
#pragma pack(pop)
static_assert(offsetof(nus3_HTone, vtable) == 0x00, "nus3_HTone.vtable");
static_assert(offsetof(nus3_HTone, internal_obj) == 0x08, "nus3_HTone.internal_obj");
static_assert(offsetof(nus3_HTone, sequence) == 0x10, "nus3_HTone.sequence");
static_assert(offsetof(nus3_HTone, magic) == 0x14, "nus3_HTone.magic");
static_assert(offsetof(nus3_HTone, released) == 0x18, "nus3_HTone.released");
static_assert(offsetof(nus3_HTone, pad_19) == 0x19, "nus3_HTone.pad_19");

/* =========================================================================
 * nus3::HPlayer — player handle, CHandle layout (no additional fields)
 * Methods: KeyOnById(0x63D0E0), SetPosition(0x63D2B0),
 *          KeyOnById(0x5FE310), SetFreeze(0x63D060)
 * Size unknown, >= 0x20 proven (CHandle fields up to +0x18 validated)
 * state_surface returned 0 typed fields (byte-cast dispatch only);
 * layout INFERRED from manual pseudocode inspection.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct nus3_HPlayer {
    void *vtable;                   /* +0x00 */
    void *internal_obj;             /* +0x08 */
    uint32_t sequence;              /* +0x10 */
    uint32_t magic;                 /* +0x14: 0x876500 */
    uint8_t released;               /* +0x18 */
    uint8_t pad_19[7];              /* +0x19 */
} nus3_HPlayer;
#pragma pack(pop)
static_assert(offsetof(nus3_HPlayer, vtable) == 0x00, "nus3_HPlayer.vtable");
static_assert(offsetof(nus3_HPlayer, internal_obj) == 0x08, "nus3_HPlayer.internal_obj");
static_assert(offsetof(nus3_HPlayer, sequence) == 0x10, "nus3_HPlayer.sequence");
static_assert(offsetof(nus3_HPlayer, magic) == 0x14, "nus3_HPlayer.magic");
static_assert(offsetof(nus3_HPlayer, released) == 0x18, "nus3_HPlayer.released");
static_assert(offsetof(nus3_HPlayer, pad_19) == 0x19, "nus3_HPlayer.pad_19");

/* =========================================================================
 * nus3::HBank — bank handle, CHandle layout (no additional fields)
 * Methods: KeyOnById(0x5FEA20), Release(0x5FEB00), IsPlaying(0x5FE940)
 * Size unknown, >= 0x20 proven (CHandle fields up to +0x18 validated)
 * state_surface returned 0 typed fields (byte-cast dispatch only);
 * layout INFERRED from manual pseudocode inspection.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct nus3_HBank {
    void *vtable;                   /* +0x00 */
    void *internal_obj;             /* +0x08 */
    uint32_t sequence;              /* +0x10 */
    uint32_t magic;                 /* +0x14: 0x876500 */
    uint8_t released;               /* +0x18 */
    uint8_t pad_19[7];              /* +0x19 */
} nus3_HBank;
#pragma pack(pop)
static_assert(offsetof(nus3_HBank, vtable) == 0x00, "nus3_HBank.vtable");
static_assert(offsetof(nus3_HBank, internal_obj) == 0x08, "nus3_HBank.internal_obj");
static_assert(offsetof(nus3_HBank, sequence) == 0x10, "nus3_HBank.sequence");
static_assert(offsetof(nus3_HBank, magic) == 0x14, "nus3_HBank.magic");
static_assert(offsetof(nus3_HBank, released) == 0x18, "nus3_HBank.released");
static_assert(offsetof(nus3_HBank, pad_19) == 0x19, "nus3_HBank.pad_19");

/* =========================================================================
 * nus3::HListener — listener handle, CHandle layout (no additional fields)
 * Methods: SetPosition(0x63D4B0), SetTarget(0x63D400), SetUp(0x63D350)
 * Size unknown, >= 0x20 proven (CHandle fields up to +0x18 validated)
 * state_surface returned 0 typed fields (byte-cast dispatch only);
 * layout INFERRED from manual pseudocode inspection.
 * ========================================================================= */
#pragma pack(push,1)
typedef struct nus3_HListener {
    void *vtable;                   /* +0x00 */
    void *internal_obj;             /* +0x08 */
    uint32_t sequence;              /* +0x10 */
    uint32_t magic;                 /* +0x14: 0x876500 */
    uint8_t released;               /* +0x18 */
    uint8_t pad_19[7];              /* +0x19 */
} nus3_HListener;
#pragma pack(pop)
static_assert(offsetof(nus3_HListener, vtable) == 0x00, "nus3_HListener.vtable");
static_assert(offsetof(nus3_HListener, internal_obj) == 0x08, "nus3_HListener.internal_obj");
static_assert(offsetof(nus3_HListener, sequence) == 0x10, "nus3_HListener.sequence");
static_assert(offsetof(nus3_HListener, magic) == 0x14, "nus3_HListener.magic");
static_assert(offsetof(nus3_HListener, released) == 0x18, "nus3_HListener.released");
static_assert(offsetof(nus3_HListener, pad_19) == 0x19, "nus3_HListener.pad_19");

/* HGroup uses the same CHandle layout (SetVolume 0x..., Stop 0x...).
 * Only 2 methods in this build, below the >= 3 threshold; kept as typedef. */
typedef nus3_CHandle nus3_HGroup;

/* =========================================================================
 * nus3::CToneBase — tone configuration base, inherits from CObject
 * Fields from Create and AssignPlayer pseudocode
 * Size proven: 0x278 (type 0) or 0x1d8 (type 1) from CSystem::CreateToneObject
 * Using larger size 0x278 as upper bound
 *
 * Offset verification (packed, x64):
 *   vtable(8) + name(8) + pad_10(8) + next(8) = 0x20
 *   + pad_20(32) = 0x40 -> config_ptr_40 ✓
 *   + config_ptr_40(8) = 0x48 + pad_48(16) = 0x58 -> group_or_config ✓
 *   + group_or_config(8) = 0x60 -> bank_ptr ✓
 *   + bank_ptr(8) = 0x68 + pad_68(13) = 0x75 -> flag_75 ✓
 *   + flag_75(1) = 0x76 + pad_76(3) = 0x79 -> bool_flag_79 ✓
 *   + bool_flag_79(1) = 0x7A + pad_7a(30) = 0x98 -> player_ptr ✓
 *   + player_ptr(8) = 0xA0 + pad_a0(8) = 0xA8 -> assign_param ✓
 *   + assign_param(4) = 0xAC + pad_ac(340) = 0x200 -> register_u32_200 ✓
 *   + register_u32_200(4) = 0x204 + pad_204(116) = 0x278 -> sizeof ✓
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CToneBase {
    /* CObject base (0x00-0x1F) */
    void *vtable;                   /* +0x00 */
    char *name;                     /* +0x08 */
    uint8_t pad_10[8];              /* +0x10 */
    struct nus3_CObject *next;      /* +0x18 */
    /* CToneBase own fields */
    uint8_t pad_20[32];             /* +0x20: gap to 0x40 */
    void *config_ptr_40;            /* +0x40: param_2 copy in Create */
    uint8_t pad_48[16];             /* +0x48: gap */
    void *group_or_config;          /* +0x58: param_2 in Create */
    void *bank_ptr;                 /* +0x60: param_3 in Create */
    uint8_t pad_68[13];             /* +0x68: gap */
    uint8_t flag_75;                /* +0x75: zeroed in Create */
    uint8_t pad_76[3];              /* +0x76 */
    uint8_t bool_flag_79;           /* +0x79: bool set in Create */
    uint8_t pad_7a[30];             /* +0x7A: gap to 0x98 */
    void *player_ptr;               /* +0x98: set in AssignPlayer */
    uint8_t pad_a0[8];              /* +0xA0: gap */
    uint32_t assign_param;          /* +0xA8: uint32 from AssignPlayer param_3 */
    uint8_t pad_ac[340];            /* +0xAC: gap to 0x200 (0x154 bytes) */
    uint32_t register_u32_200;      /* +0x200: param_4 in Create */
    uint8_t pad_204[116];           /* +0x204: gap to 0x278 (0x74 bytes) */
} nus3_CToneBase;
static_assert(offsetof(nus3_CToneBase, config_ptr_40) == 0x40, "CToneBase.config_ptr_40");
static_assert(offsetof(nus3_CToneBase, group_or_config) == 0x58, "CToneBase.group_or_config");
static_assert(offsetof(nus3_CToneBase, bank_ptr) == 0x60, "CToneBase.bank_ptr");
static_assert(offsetof(nus3_CToneBase, flag_75) == 0x75, "CToneBase.flag_75");
static_assert(offsetof(nus3_CToneBase, bool_flag_79) == 0x79, "CToneBase.bool_flag_79");
static_assert(offsetof(nus3_CToneBase, player_ptr) == 0x98, "CToneBase.player_ptr");
static_assert(offsetof(nus3_CToneBase, assign_param) == 0xA8, "CToneBase.assign_param");
static_assert(offsetof(nus3_CToneBase, register_u32_200) == 0x200, "CToneBase.register_u32_200");
static_assert(sizeof(nus3_CToneBase) == 0x278, "CToneBase size 0x278");

/* =========================================================================
 * nus3::CSingleTone — singleton tone, extends CToneBase
 * From CSingleTone::Create: accesses param_1+0x230 as a sub-object ptr
 * Note: 0x230 is INSIDE the CToneBase 0x278 allocation, so this is an
 * embedded sub-object within CToneBase's padding region, not an extension.
 * We define it as a separate struct overlaying CToneBase for clarity.
 * Size == CToneBase size (0x278); no additional allocation.
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CSingleTone {
    uint8_t base[0x230];            /* +0x000: CToneBase fields up to 0x230 */
    void *sub_object;               /* +0x230: has vtable calls at +8,+0x10 */
    uint8_t pad_238[0x40];          /* +0x238: remainder to 0x278 (0x278-0x238=0x40) */
} nus3_CSingleTone;
static_assert(offsetof(nus3_CSingleTone, sub_object) == 0x230, "CSingleTone.sub_object");
static_assert(sizeof(nus3_CSingleTone) == 0x278, "CSingleTone size == CToneBase");

/* =========================================================================
 * nus3::CRandomizerBase — randomization parameter container
 * From Randomize: accesses param_1+0x58 as a config/data ptr
 * That ptr's layout: +0x10 = count (uint32), +0x18 = array base ptr
 * Array entries are 0x10 bytes each (stride), with fields:
 * [0] = switch case (uint32), [2] = float bias, [3] = float scale
 * CRandomizerBase itself: size unknown, >= 0x60 proven
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CRandomizerBase {
    uint8_t pad_00[88];             /* +0x00: gap */
    void *randomizer_data;          /* +0x58: ptr to randomizer config block */
} nus3_CRandomizerBase;
static_assert(offsetof(nus3_CRandomizerBase, randomizer_data) == 0x58, "CRandomizerBase.randomizer_data");

/* =========================================================================
 * nus3::CSystem — main audio system manager
 * state_surface fields: +0x24, +0x2C, +0x4C, +0xE8 (all uint32 read-only)
 * Allocation sizes from factory methods:
 *   CreateToneObject: 0x278 (type 0) / 0x1d8 (type 1)
 *   CreateGroupObject: 0x190
 *   CreatePlayerObject: 0xC8
 *   CreateBusObject: 0xB0
 *   RegisterBank: 0x2128 / 0x2170
 *   RegisterConfig: 0xC0 / 0x1C0
 * Vtables found: PTR_FUN_140771600 (initial BusObject), PTR_FUN_140771c10 (final BusObject)
 * Size unknown; >= 0xF0 proven (last field at 0xE8 + 4)
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CSystem {
    uint8_t pad_00[36];             /* +0x00: gap */
    uint32_t field_24;              /* +0x24: uint32 read in CreateGroupObject */
    uint8_t pad_28[4];              /* +0x28: gap */
    uint32_t field_2c;              /* +0x2C: uint32 read in CreateGroupObject */
    uint8_t pad_30[28];             /* +0x30: gap */
    uint32_t field_4c;              /* +0x4C: uint32 read in Init */
    uint8_t pad_50[152];            /* +0x50: gap */
    uint32_t field_e8;              /* +0xE8: uint32 read in CreateToneObject */
    uint8_t pad_ec[4];              /* +0xEC: gap to 0xF0 */
} nus3_CSystem;
static_assert(offsetof(nus3_CSystem, field_24) == 0x24, "CSystem.field_24");
static_assert(offsetof(nus3_CSystem, field_2c) == 0x2C, "CSystem.field_2c");
static_assert(offsetof(nus3_CSystem, field_4c) == 0x4C, "CSystem.field_4c");
static_assert(offsetof(nus3_CSystem, field_e8) == 0xE8, "CSystem.field_e8");

#endif /* CMN80_H */