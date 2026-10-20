/* cmn79.h — NUS3/CRI audio middleware struct layouts for s2 (NSUNS2.exe)
 * All layouts INFERRED from static decompilation. No runtime confirmation.
 * Build: s2 / NSUNS2.exe-abf2b6 / sha 697488011750...
 * Date: 2026-10-19
 */
#ifndef CMN79_S2_H
#define CMN79_S2_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* =========================================================================
 * nus3::CHandle — handle wrapper (shared by HPlayer, HTone, HBank, HListener)
 * Size: 0x20 (proven by ctor zero-init pattern and field accesses)
 * Vtable: PTR_FUN_1408c1848
 * Evidence: CHandle::ctor 0x71E7B0, Attach 0x71E620, Detach 0x71E5E0,
 *           GetId 0x71E690, IsReleased 0x71E6B0, operator= 0x75D620
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
 * Evidence: CToneBase::Create 0x7355E0, AssignPlayer 0x734DC0,
 *           SetRegisterUint8 0x734D90
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
    uint8_t   _gap_7a[0x186];/* +0x7A..+0x1FF large opaque region */
    uint32_t  tone_type;     /* +0x200 param_4 */
} nus3_CToneBase;

_Static_assert(offsetof(nus3_CToneBase, vtable)     == 0x000, "CToneBase.vtable");
_Static_assert(offsetof(nus3_CToneBase, data_ptr)   == 0x008, "CToneBase.data_ptr");
_Static_assert(offsetof(nus3_CToneBase, config_ref) == 0x040, "CToneBase.config_ref");
_Static_assert(offsetof(nus3_CToneBase, tone_init)  == 0x058, "CToneBase.tone_init");
_Static_assert(offsetof(nus3_CToneBase, flag_75)    == 0x075, "CToneBase.flag_75");
_Static_assert(offsetof(nus3_CToneBase, flag_79)    == 0x079, "CToneBase.flag_79");
_Static_assert(offsetof(nus3_CToneBase, tone_type)  == 0x200, "CToneBase.tone_type");

/* =========================================================================
 * nus3::CNUS2BankParser — bank file parser
 * Size: >= 0x60 (fields accessed up to +0x59 in Create)
 * Evidence: CNUS2BankParser::Create 0x731D90, CreateToneInit 0x731300,
 *           GetToneInit 0x7319B0
 * Magic check: bytes at param_2+1..+4 must be {0x02, 0x01, 0x00, 0x00}
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
    uint8_t   _gap_34[0x14]; /* +0x34..+0x47 */
    int32_t   field_48;      /* +0x48 from raw_data+0xC */
    uint8_t   _gap_4c[4];    /* +0x4C..+0x4F */
    void     *tone_table;    /* +0x50 MemAlloc(tone_count * 16) */
    uint8_t   _gap_58;       /* +0x58 conditional flag */
    uint8_t   flag_59;       /* +0x59 param_6 */
    uint8_t   _gap_5a[6];    /* +0x5A..+0x5F */
    uint8_t   tone_entries[0x100]; /* +0x60 embedded array (from FUN_1401509d0) */
} nus3_CNUS2BankParser;

_Static_assert(offsetof(nus3_CNUS2BankParser, vtable)      == 0x00, "CNUS2BankParser.vtable");
_Static_assert(offsetof(nus3_CNUS2BankParser, raw_data)    == 0x08, "CNUS2BankParser.raw_data");
_Static_assert(offsetof(nus3_CNUS2BankParser, data_size)   == 0x10, "CNUS2BankParser.data_size");
_Static_assert(offsetof(nus3_CNUS2BankParser, name_ptr)    == 0x18, "CNUS2BankParser.name_ptr");
_Static_assert(offsetof(nus3_CNUS2BankParser, format_tag)  == 0x20, "CNUS2BankParser.format_tag");
_Static_assert(offsetof(nus3_CNUS2BankParser, bank_name)   == 0x28, "CNUS2BankParser.bank_name");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_count)  == 0x30, "CNUS2BankParser.tone_count");
_Static_assert(offsetof(nus3_CNUS2BankParser, field_48)    == 0x48, "CNUS2BankParser.field_48");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_table)  == 0x50, "CNUS2BankParser.tone_table");
_Static_assert(offsetof(nus3_CNUS2BankParser, flag_59)     == 0x59, "CNUS2BankParser.flag_59");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_entries)== 0x60, "CNUS2BankParser.tone_entries");

/* =========================================================================
 * Handle typedefs — HTone, HPlayer, HListener are CHandle wrappers
 * (identical layout, distinct types for API safety)
 * ========================================================================= */
typedef nus3_CHandle nus3_HTone;
typedef nus3_CHandle nus3_HPlayer;
typedef nus3_CHandle nus3_HListener;

/* =========================================================================
 * nus3::CSystem — singleton; state lives in DAT_14810f* globals, not per-object.
 * CreatePlayerObject allocates 200 bytes via FUN_140721ac0.
 * No per-instance fields reconstructed; listed for completeness (17 methods).
 * ========================================================================= */

#endif /* CMN79_S2_H */