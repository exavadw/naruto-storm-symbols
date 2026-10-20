/* cmn79.h — NUS3 (CRI audio middleware) struct layouts for Storm 1 PC (s1)
 * Build: s1 / NSUNS1.exe-a9fe00
 * SHA256: 10231093af9cbda329d5cf3b7ba5a146ad523799331f52c3c3929b785d7f63ba
 *
 * All layouts INFERRED from static decompilation. No runtime confirmation.
 * Offsets derived exclusively from s1 x64 decompiled code (image base 0x140000000).
 * Names from Switch Trilogy ns1:: namespace or Storm 1 strings only.
 *
 * Classes reconstructed: CHandle, CBankBase, CToneBase, CBufferTone,
 * CNUS2ConfigParser, CNUS2BankParser, CNUS2Config3DParser, CNUS3ConfigParser.
 * Classes listed in report only (< 3 methods or pure factory/global-state):
 * HPlayer, HTone, HBank, HListener (share CHandle layout),
 * CSystem, CNuscDriver, CNuscDriverBus, CNuscDriverFx, CConfigBase,
 * CSingleTone, CRandomizerBase, CObject.
 */

#ifndef CMN79_S1_H
#define CMN79_S1_H

#include <stdint.h>
#include <stddef.h>

/* =========================================================================
 * nus3::CHandle — base handle wrapper (all H* classes share this layout)
 * Size: >= 0x19, padded to 0x20. Vtable at PTR_FUN_140766848.
 * Evidence: CHandle::ctor (0x602F80), Attach (0x602FF0), Detach (0x603050),
 *           GetId (0x6030A0), IsValid (0x6030D0).
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CHandle {
    void     *vtable;        /* +0x00: PTR_FUN_140766848 */
    void     *object_ptr;    /* +0x08: underlying opaque object */
    int32_t   session_id;    /* +0x10: compared to DAT_140b8ba5c */
    uint32_t  magic;         /* +0x14: 0x876500 */
    uint8_t   released_flag; /* +0x18: set on Detach/Release */
    uint8_t   _pad_19[7];    /* +0x19 .. +0x1F */
} nus3_CHandle;

_Static_assert(offsetof(nus3_CHandle, vtable)        == 0x00, "CHandle.vtable");
_Static_assert(offsetof(nus3_CHandle, object_ptr)     == 0x08, "CHandle.object_ptr");
_Static_assert(offsetof(nus3_CHandle, session_id)     == 0x10, "CHandle.session_id");
_Static_assert(offsetof(nus3_CHandle, magic)          == 0x14, "CHandle.magic");
_Static_assert(offsetof(nus3_CHandle, released_flag)  == 0x18, "CHandle.released_flag");

/* HPlayer, HTone, HBank, HListener: identical layout to CHandle. */

/* =========================================================================
 * nus3::CBankBase — bank container (partial layout from Create 0x60E910)
 * Size: >= 0xB8 (last write at +0xB0 is an 8-byte pointer).
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CBankBase {
    void     *vtable;        /* +0x00 */
    void     *name_or_data;  /* +0x08: from vtable+0x20 call result */
    uint32_t  field_10;      /* +0x10: from vtable+0x28 */
    uint8_t   _pad_14[68];   /* +0x14 .. +0x57 */
    void     *parser_iface;  /* +0x58: param_2 passed to Create */
    uint32_t  entry_count;   /* +0x60: from vtable+0x38 */
    uint8_t   _pad_64[14];   /* +0x64 .. +0x71 */
    uint8_t   flag_72;       /* +0x72: set to 1 in Create */
    uint8_t   _pad_73[1];    /* +0x73 */
    uint32_t  field_74;      /* +0x74: from vtable+0x30 */
    void     *alloc_78;      /* +0x78: MemAlloc(entry_count * 4) */
    void     *alloc_80;      /* +0x80: MemAlloc(entry_count * 4) */
    uint8_t   _pad_88[28];   /* +0x88 .. +0xA3 */
    uint32_t  field_a4;      /* +0xA4: from vtable+0x30 */
    uint8_t   _pad_A8[8];    /* +0xA8 .. +0xAF */
    void     *alloc_b0;      /* +0xB0: MemAlloc(entry_count * 8) */
} nus3_CBankBase;

_Static_assert(offsetof(nus3_CBankBase, name_or_data) == 0x08, "CBankBase.name_or_data");
_Static_assert(offsetof(nus3_CBankBase, field_10)     == 0x10, "CBankBase.field_10");
_Static_assert(offsetof(nus3_CBankBase, parser_iface) == 0x58, "CBankBase.parser_iface");
_Static_assert(offsetof(nus3_CBankBase, entry_count)  == 0x60, "CBankBase.entry_count");
_Static_assert(offsetof(nus3_CBankBase, flag_72)      == 0x72, "CBankBase.flag_72");
_Static_assert(offsetof(nus3_CBankBase, field_74)     == 0x74, "CBankBase.field_74");
_Static_assert(offsetof(nus3_CBankBase, alloc_78)     == 0x78, "CBankBase.alloc_78");
_Static_assert(offsetof(nus3_CBankBase, alloc_80)     == 0x80, "CBankBase.alloc_80");
_Static_assert(offsetof(nus3_CBankBase, field_a4)     == 0xA4, "CBankBase.field_a4");
_Static_assert(offsetof(nus3_CBankBase, alloc_b0)     == 0xB0, "CBankBase.alloc_b0");

/* =========================================================================
 * nus3::CToneBase — tone/sound instance (partial layout from Create 0x6155D0)
 * Size: >= 0x204 (last write at +0x200 is uint32).
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CToneBase {
    void     *vtable;        /* +0x00 */
    void     *data_ptr;      /* +0x08: from param_2[0] */
    uint8_t   _pad_10[48];   /* +0x10 .. +0x3F */
    void     *config_ref;    /* +0x40: param_2 stored again */
    uint8_t   _pad_48[24];   /* +0x48 .. +0x5F */
    void     *tone_init;     /* +0x60: param_3 (tone init data) */
    uint8_t   _pad_68[17];   /* +0x68 .. +0x78 */
    uint8_t   flag_79;       /* +0x79: bool from tone_init check */
    uint8_t   _pad_7A[390];  /* +0x7A .. +0x1FF */
    uint32_t  tone_type;     /* +0x200: param_4 */
} nus3_CToneBase;

_Static_assert(offsetof(nus3_CToneBase, data_ptr)    == 0x08,  "CToneBase.data_ptr");
_Static_assert(offsetof(nus3_CToneBase, config_ref)  == 0x40,  "CToneBase.config_ref");
_Static_assert(offsetof(nus3_CToneBase, tone_init)   == 0x60,  "CToneBase.tone_init");
_Static_assert(offsetof(nus3_CToneBase, flag_79)     == 0x79,  "CToneBase.flag_79");
_Static_assert(offsetof(nus3_CToneBase, tone_type)   == 0x200, "CToneBase.tone_type");

/* =========================================================================
 * nus3::CBufferTone — buffered tone (extends CToneBase)
 * Size: >= 0x358 (sub-object at +0x350 accessed via vtable calls).
 * Create (0x606BB0) calls CToneBase::Create(param_1, ..., param_1+0x350, ...).
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CBufferTone {
    nus3_CToneBase base;          /* +0x000: CToneBase fields (0x204 bytes) */
    uint8_t        _gap_204[332]; /* +0x204 .. +0x34F */
    void          *buffer_subobj; /* +0x350: embedded buffer object (has vtable) */
} nus3_CBufferTone;

_Static_assert(offsetof(nus3_CBufferTone, buffer_subobj) == 0x350, "CBufferTone.buffer_subobj");

/* =========================================================================
 * nus3::CNUS2ConfigParser — NUSC config file parser
 * Size: >= 0x38. Create: 0x60C6D0. Magic: 'nusc'.
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CNUS2ConfigParser {
    void     *vtable;        /* +0x00 */
    char     *raw_data;      /* +0x08: param_2 (raw nusc buffer) */
    uint32_t  format_tag;    /* +0x10: param_3 */
    int32_t   bus_count;     /* +0x14: from raw_data+0x10 */
    int32_t   fx_count;      /* +0x18: from raw_data+0x28 */
    uint32_t  total_entries; /* +0x1C: bus_count + fx_count + 2 */
    uint8_t   _pad_20[8];    /* +0x20 .. +0x27 */
    void     *entry_table;   /* +0x28: MemAlloc(total_entries * 8) */
    void     *name_table;    /* +0x30: MemAlloc(total_entries * 8) */
} nus3_CNUS2ConfigParser;

_Static_assert(offsetof(nus3_CNUS2ConfigParser, raw_data)      == 0x08, "CNUS2ConfigParser.raw_data");
_Static_assert(offsetof(nus3_CNUS2ConfigParser, format_tag)     == 0x10, "CNUS2ConfigParser.format_tag");
_Static_assert(offsetof(nus3_CNUS2ConfigParser, bus_count)      == 0x14, "CNUS2ConfigParser.bus_count");
_Static_assert(offsetof(nus3_CNUS2ConfigParser, fx_count)       == 0x18, "CNUS2ConfigParser.fx_count");
_Static_assert(offsetof(nus3_CNUS2ConfigParser, total_entries)  == 0x1C, "CNUS2ConfigParser.total_entries");
_Static_assert(offsetof(nus3_CNUS2ConfigParser, entry_table)    == 0x28, "CNUS2ConfigParser.entry_table");
_Static_assert(offsetof(nus3_CNUS2ConfigParser, name_table)     == 0x30, "CNUS2ConfigParser.name_table");

/* =========================================================================
 * nus3::CNUS2Config3DParser — 3D audio config parser
 * Size: >= 0x30. Create: 0x6106E0. Magic: {0,1,2,3}.
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CNUS2Config3DParser {
    void     *vtable;        /* +0x00 */
    int32_t  *raw_data;      /* +0x08: param_2 */
    uint32_t  format_tag;    /* +0x10: param_3 */
    uint8_t   _pad_14[4];    /* +0x14 .. +0x17 */
    void     *data_region;   /* +0x18: raw_data + 0x20 */
    uint32_t  entry_count;   /* +0x20: from raw_data[2] */
    uint8_t   _pad_24[4];    /* +0x24 .. +0x27 */
    void     *entry_table;   /* +0x28: MemAlloc(entry_count * 8) */
} nus3_CNUS2Config3DParser;

_Static_assert(offsetof(nus3_CNUS2Config3DParser, raw_data)     == 0x08, "CNUS2Config3DParser.raw_data");
_Static_assert(offsetof(nus3_CNUS2Config3DParser, format_tag)    == 0x10, "CNUS2Config3DParser.format_tag");
_Static_assert(offsetof(nus3_CNUS2Config3DParser, data_region)   == 0x18, "CNUS2Config3DParser.data_region");
_Static_assert(offsetof(nus3_CNUS2Config3DParser, entry_count)   == 0x20, "CNUS2Config3DParser.entry_count");
_Static_assert(offsetof(nus3_CNUS2Config3DParser, entry_table)   == 0x28, "CNUS2Config3DParser.entry_table");

/* =========================================================================
 * nus3::CNUS2BankParser — bank binary parser
 * Size: >= 0x59. Create: 0x611D80. Magic: {2,1,0,0}.
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CNUS2BankParser {
    void     *vtable;        /* +0x00 */
    void     *raw_data;      /* +0x08: param_2 */
    uint32_t  data_size;     /* +0x10: param_3 */
    uint8_t   _pad_14[28];   /* +0x14 .. +0x2F */
    uint32_t  tone_count;    /* +0x30: from raw_data+8 */
    uint8_t   _pad_34[20];   /* +0x34 .. +0x47 */
    int32_t   field_48;      /* +0x48: from raw_data+0xC */
    uint8_t   _pad_4C[12];   /* +0x4C .. +0x57 */
    uint8_t   flag_58;       /* +0x58: conditional flag */
} nus3_CNUS2BankParser;

_Static_assert(offsetof(nus3_CNUS2BankParser, raw_data)    == 0x08, "CNUS2BankParser.raw_data");
_Static_assert(offsetof(nus3_CNUS2BankParser, data_size)   == 0x10, "CNUS2BankParser.data_size");
_Static_assert(offsetof(nus3_CNUS2BankParser, tone_count)  == 0x30, "CNUS2BankParser.tone_count");
_Static_assert(offsetof(nus3_CNUS2BankParser, field_48)    == 0x48, "CNUS2BankParser.field_48");
_Static_assert(offsetof(nus3_CNUS2BankParser, flag_58)     == 0x58, "CNUS2BankParser.flag_58");

/* =========================================================================
 * nus3::CNUS3ConfigParser — NUS3 format config parser
 * Size: >= 0xD0 (param_1 indexed as longlong*, max index 0x26 = offset 0xD0).
 * Create: 0x619080. Magic: 'NUS3', 'CNF ', 'TOC '.
 * ========================================================================= */
typedef struct __attribute__((packed)) nus3_CNUS3ConfigParser {
    void     *vtable;        /* +0x00 */
    int32_t  *raw_data;      /* +0x08: param_2 */
    uint32_t  format_tag;    /* +0x10: param_3 */
    uint8_t   _pad_14[4];    /* +0x14 .. +0x17 */
    uint8_t   _chunk_ptrs[0xB8]; /* +0x18 .. +0xCF: chunk pointers */
} nus3_CNUS3ConfigParser;

_Static_assert(offsetof(nus3_CNUS3ConfigParser, raw_data)    == 0x08, "CNUS3ConfigParser.raw_data");
_Static_assert(offsetof(nus3_CNUS3ConfigParser, format_tag)   == 0x10, "CNUS3ConfigParser.format_tag");

/* =========================================================================
 * nus3 (namespace): no instance state
 * All 17 free functions operate on global singletons (DAT_140b8b960,
 * DAT_140b8b961, DAT_140864748). No per-object fields.
 * Evidence: Init (0x5FF100), Quit (0x5FF0B0), SetCoordinateSystem (0x5FECE0),
 *           SetDistanceScale (0x5FEB60), SetOutputMode (0x5FEE70),
 *           SetTitlePause (0x5FEE20), StartLive (0x5FEEB0),
 *           RegisterConfig (0x5FEFC0), CreatePlayer (0x5FED60),
 *           GetListener (0x5FED20), GetMasterBus (0x5FEBC0),
 *           IsBankRegistered (0x5FEC80), KeyOffAll (0x5FEDE0),
 *           LinearToDecibels (0x5FEB80), SearchBank (0x602800),
 *           SearchGroup (0x5FEC00), Quit (0x53CBA0).
 * ========================================================================= */

/* =========================================================================
 * nus3::CConfigBase: no instance state (abstract interface / mixin)
 * All 9 methods access param_1+0x58 which is the parser_iface field of the
 * derived CNUS2ConfigParser/CNUS3ConfigParser object, not a CConfigBase-owned
 * field. CConfigBase has no standalone ctor, allocator, or vtable of its own;
 * it is never instantiated directly.
 * Evidence: CreatePlayer (0x60B8D0), CreateGraph (0x60B960),
 *           GetNumPlayers (0x60B930), GetNumGraphs (0x60B9C0),
 *           CreateGroup (0x60B9F0), GetNumGroups (0x60BA50),
 *           CreateFx (0x60BA80), GetNumFxs (0x60BB50),
 *           CreateBus (0x60BB80).
 * ========================================================================= */

#endif /* CMN79_S1_H */