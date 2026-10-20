/* cmn79.h — NUS3/CRI audio middleware struct layouts for s3 (NSUNS3.exe 64-bit)
 * All layouts INFERRED from static decompilation. No runtime confirmation.
 * Build: s3 / NSUNS3.exe-a7124b / sha 55b726e94dad
 * Date: 2026-10-19
 */
#ifndef CMN79_S3_H
#define CMN79_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nus3::CHandle — handle wrapper (shared by HPlayer, HTone, HListener, HBank)
 * Size: 0x20 (proven by ctor zero-init pattern: last write at param_1+0x18)
 * Vtable: PTR_FUN_140a0eef8
 * Evidence: CHandle::ctor 0x824D70, Attach 0x824DE0, Detach 0x824DA0,
 *           GetId 0x824BF0, IsReleased 0x824C10, operator= 0x863630
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CHandle {
    void     *vtable;        /* +0x00 */
    void     *object_ptr;    /* +0x08 */
    int32_t   session_id;    /* +0x10 */
    uint32_t  magic;         /* +0x14 = 0x876500 */
    uint8_t   released_flag; /* +0x18 */
    uint8_t   _pad_19[7];   /* +0x19..+0x1F */
} nus3_CHandle;

_Static_assert(offsetof(nus3_CHandle, vtable)        == 0x00, "CHandle.vtable");
_Static_assert(offsetof(nus3_CHandle, object_ptr)     == 0x08, "CHandle.object_ptr");
_Static_assert(offsetof(nus3_CHandle, session_id)     == 0x10, "CHandle.session_id");
_Static_assert(offsetof(nus3_CHandle, magic)          == 0x14, "CHandle.magic");
_Static_assert(offsetof(nus3_CHandle, released_flag)  == 0x18, "CHandle.released_flag");

/* =========================================================================
 * nus3::CConfigBase — config dispatch base
 * Size unknown, >= 0x60 (last proven access at +0x58 is a pointer deref)
 * Only field proven: +0x58 holds a sub-object pointer whose vtable is used
 * for Create/GetNum dispatch (offsets +0x30, +0x38 in sub-vtable).
 * Evidence: CConfigBase::CreateBus 0x831BA0
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CConfigBase {
    uint8_t   _opaque_00[0x58]; /* +0x00..+0x57 */
    void     *dispatch_obj;     /* +0x58 sub-object with vtable */
    uint8_t   _opaque_60[0x08]; /* +0x60..+0x67 (size unproven beyond this) */
} nus3_CConfigBase;

_Static_assert(offsetof(nus3_CConfigBase, dispatch_obj) == 0x58, "CConfigBase.dispatch_obj");

/* =========================================================================
 * nus3::CToneBase — tone instance base
 * Size: >= 0x204 (field at +0x200 written in Create)
 * Evidence: CToneBase::Create 0x83B5F0, AssignPlayer 0x83ADD0,
 *           SetRegisterUint8 0x83ADA0
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CToneBase {
    void     *vtable;        /* +0x00 */
    void     *data_ptr;      /* +0x08 from param_2[0] */
    uint8_t   _gap_10[0x30]; /* +0x10..+0x3F */
    void     *config_ref;    /* +0x40 param_2 stored */
    uint8_t   _gap_48[0x10]; /* +0x48..+0x57 */
    void     *tone_init;     /* +0x58 param_3 */
    uint8_t   _gap_60[0x15]; /* +0x60..+0x74 */
    uint8_t   flag_75;       /* +0x75 set to 0 in Create */
    uint8_t   _gap_76[3];    /* +0x76..+0x78 */
    uint8_t   flag_79;       /* +0x79 bool from tone_init check */
    uint8_t   _gap_7a[0x1e]; /* +0x7A..+0x97 */
    void     *player_ref;    /* +0x98 from AssignPlayer param_2 */
    uint8_t   _gap_a0[8];    /* +0xA0..+0xA7 */
    uint32_t  player_slot;   /* +0xA8 from AssignPlayer param_3 */
    uint8_t   _gap_ac[0x154];/* +0xAC..+0x1FF large opaque region */
    uint32_t  tone_type;     /* +0x200 param_4 */
} nus3_CToneBase;

_Static_assert(offsetof(nus3_CToneBase, vtable)      == 0x000, "CToneBase.vtable");
_Static_assert(offsetof(nus3_CToneBase, data_ptr)    == 0x008, "CToneBase.data_ptr");
_Static_assert(offsetof(nus3_CToneBase, config_ref)  == 0x040, "CToneBase.config_ref");
_Static_assert(offsetof(nus3_CToneBase, tone_init)   == 0x058, "CToneBase.tone_init");
_Static_assert(offsetof(nus3_CToneBase, flag_75)     == 0x075, "CToneBase.flag_75");
_Static_assert(offsetof(nus3_CToneBase, flag_79)     == 0x079, "CToneBase.flag_79");
_Static_assert(offsetof(nus3_CToneBase, player_ref)  == 0x098, "CToneBase.player_ref");
_Static_assert(offsetof(nus3_CToneBase, player_slot) == 0x0A8, "CToneBase.player_slot");
_Static_assert(offsetof(nus3_CToneBase, tone_type)   == 0x200, "CToneBase.tone_type");

/* =========================================================================
 * nus3::CNUS2BankParser — bank file parser
 * Size: >= 0x160 (fields accessed up to +0x60 in Create via FUN_14012a6c0)
 * Evidence: CNUS2BankParser::Create 0x837DA0, CreateToneInit 0x837310,
 *           GetToneInit 0x8379C0
 * Magic check: bytes at param_4+0..+3 must be {0x01, 0x00, 0x00, 0x00}
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CNUS2BankParser {
    void     *vtable;        /* +0x00 */
    void     *raw_data;      /* +0x08 param_2 */
    uint32_t  data_size;     /* +0x10 param_3 (updated during parse) */
    uint8_t   _gap_14[4];    /* +0x14..+0x17 */
    char     *name_ptr;      /* +0x18 param_4 or NULL */
    uint32_t  format_tag;    /* +0x20 param_5 */
    uint8_t   _gap_24[4];    /* +0x24..+0x27 */
    char     *bank_name;     /* +0x28 points to name_buf or param_4+0x20 */
    uint32_t  tone_count;    /* +0x30 from raw_data+8 */
    uint8_t   _gap_34[0x0c]; /* +0x34..+0x3F */
    void     *name_table;    /* +0x40 MemAlloc(tone_count * 8) */
    uint8_t   _gap_48[0];    /* placeholder alignment */
    int32_t   field_48;      /* +0x48 from raw_data+0xC */
    uint8_t   _gap_4c[4];    /* +0x4C..+0x4F */
    void     *tone_table;    /* +0x50 MemAlloc(tone_count * 16) */
    uint8_t   flag_58;       /* +0x58 conditional flag */
    uint8_t   flag_59;       /* +0x59 param_6 */
    uint8_t   _gap_5a[6];    /* +0x5A..+0x5F */
    uint8_t   tone_entries[0x100]; /* +0x60 embedded array (from FUN_14012a6c0) */
} nus3_CNUS2BankParser;

_Static_assert(offsetof(nus3_CNUS2BankParser, vtable)       == 0x00, "CNUS2BankParser.vtable");
_Static_assert(offsetof(nus3_CNUS2BankParser, raw_data)     == 0x08, "CNUS2BankParser.raw_data");
_Static_assert(offsetof(nus3_CNUS2BankParser, data_size)    == 0x10, "CNUS2BankParser.data_size");
_Static_assert(offsetof(nus3_CNUS2BankParser, name_ptr)     == 0x18, "CNUS2BankParser.name_ptr");
_Static_assert(offsetof(nus3_CNUS2BankParser, format_tag)   == 0x20, "CNUS2BankParser.format_tag");
_Static_assert(offsetof(nus3_CNUS2BankParser, bank_name)    == 0x28, "CNUS2BankParser.bank_name");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_count)   == 0x30, "CNUS2BankParser.tone_count");
_Static_assert(offsetof(nus3_CNUS2BankParser, name_table)   == 0x40, "CNUS2BankParser.name_table");
_Static_assert(offsetof(nus3_CNUS2BankParser, field_48)     == 0x48, "CNUS2BankParser.field_48");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_table)   == 0x50, "CNUS2BankParser.tone_table");
_Static_assert(offsetof(nus3_CNUS2BankParser, flag_58)      == 0x58, "CNUS2BankParser.flag_58");
_Static_assert(offsetof(nus3_CNUS2BankParser, flag_59)      == 0x59, "CNUS2BankParser.flag_59");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_entries) == 0x60, "CNUS2BankParser.tone_entries");

/* =========================================================================
 * Handle typedefs — HTone, HPlayer, HListener, HBank are CHandle wrappers
 * (identical layout, distinct types for API safety)
 * ========================================================================= */
typedef nus3_CHandle nus3_HTone;
typedef nus3_CHandle nus3_HPlayer;
typedef nus3_CHandle nus3_HListener;
typedef nus3_CHandle nus3_HBank;

/* =========================================================================
 * nus3::CSystem: no instance state
 * Singleton — all state lives in DAT_1482d6* globals, not per-object fields.
 * Init (0x829320) writes exclusively to globals (DAT_1482d6c4c, DAT_1482d6b53,
 *   DAT_1482d95a8/b0/518, DAT_1482d6bf8); the allocated 0x20028 buffer is
 *   stored in DAT_1482d6bf8, not returned as an instance.
 * CreatePlayerObject (0x827C20) allocates 200 bytes via MemAlloc but stores
 *   the result through param_2 output pointer; CSystem itself holds nothing.
 * Free functions (nus3::Init 0x824B00, nus3::CreatePlayer 0x824760, etc.)
 *   are static wrappers that read/write only DAT_1482d6* globals.
 * state_surface found 4 reads at offsets +0x24/+0x2C/+0x4C/+0xE8 but these
 *   access the init-config struct passed to Init, not persistent instance data.
 * Evidence: Init 0x829320, CreatePlayerObject 0x827C20, CreateBusObject 0x827D90,
 *   CreateGroupObject 0x827ED0, CreateToneObject 0x827FD0, CreateFxObject 0x8260F0,
 *   RegisterBank 0x828890, RegisterConfig 0x8289F0, Sync 0x828EA0, Quit 0x828F90,
 *   KeyOffAll 0x827510, SetTitlePause 0x827730, MemAlloc 0x827AB0,
 *   SearchBankSync 0x825FA0, SearchGroupSync 0x826020, SetGlobalPlayerInit 0x825190
 * ========================================================================= */

#endif /* CMN79_S3_H */