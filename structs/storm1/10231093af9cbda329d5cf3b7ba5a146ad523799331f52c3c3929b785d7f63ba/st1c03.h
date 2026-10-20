/* st1c03.h - Story CUTSCENE / EVENT playback structs for NSUNS1 (s1)
 * Generated 2026-10-19 from the decompiler cache state_surface + decompile cache.
 * All layouts INFERRED from static analysis; not runtime-confirmed.
 * PC offsets only (image base 0x140000000). Names from s1/nucc only.
 */
#ifndef ST1C03_H
#define ST1C03_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * cmnEventData — event command data node
 * Size: unknown, >= 0xC8 (last field at 0xC0 size 8; no allocator constant found)
 * Vtable: PTR_FUN_14065ae98 (set in ctor at *param_1)
 * ======================================================================== */
typedef struct __attribute__((packed)) cmnEventData {
    /* 0x00 */ void *vtable;            /* PTR_FUN_14065ae98 */
    /* 0x08 */ uint64_t field_08;       /* zeroed in ctor (param_1[1]) */
    /* 0x10 */ uint64_t field_10;       /* zeroed in ctor (param_1[2]) */
    /* 0x18 */ uint64_t field_18;       /* zeroed in ctor (param_1[3]) */
    /* 0x20 */ uint64_t field_20;       /* zeroed in ctor (param_1[4]) */
    /* 0x28 */ uint8_t embedded_block[0x50]; /* memset 0x50 bytes in ctor */
    /* 0x78 */ uint32_t field_78;       /* write in ctor */
    /* 0x7C */ uint32_t field_7C;       /* write in ctor */
    /* 0x80 */ uint64_t field_80;       /* write in ctor (param_1[0x10]) */
    /* 0x88 */ uint64_t field_88;       /* write in ctor (param_1[0x11]) */
    /* 0x90 */ uint64_t field_90;       /* write in ctor (param_1[0x12]) */
    /* 0x98 */ uint32_t field_98;       /* write in ctor */
    /* 0x9C */ uint8_t pad_9C[0x24];   /* gap to 0xC0 */
    /* 0xC0 */ uint64_t field_C0;       /* write in dtor (param_1[0x18]) */
} cmnEventData;
static_assert(offsetof(cmnEventData, vtable) == 0x00, "cmnEventData.vtable");
static_assert(offsetof(cmnEventData, field_08) == 0x08, "cmnEventData.field_08");
static_assert(offsetof(cmnEventData, field_10) == 0x10, "cmnEventData.field_10");
static_assert(offsetof(cmnEventData, field_18) == 0x18, "cmnEventData.field_18");
static_assert(offsetof(cmnEventData, field_20) == 0x20, "cmnEventData.field_20");
static_assert(offsetof(cmnEventData, embedded_block) == 0x28, "cmnEventData.embedded_block");
static_assert(offsetof(cmnEventData, field_78) == 0x78, "cmnEventData.field_78");
static_assert(offsetof(cmnEventData, field_7C) == 0x7C, "cmnEventData.field_7C");
static_assert(offsetof(cmnEventData, field_80) == 0x80, "cmnEventData.field_80");
static_assert(offsetof(cmnEventData, field_88) == 0x88, "cmnEventData.field_88");
static_assert(offsetof(cmnEventData, field_90) == 0x90, "cmnEventData.field_90");
static_assert(offsetof(cmnEventData, field_98) == 0x98, "cmnEventData.field_98");
static_assert(offsetof(cmnEventData, pad_9C) == 0x9C, "cmnEventData.pad_9C");
static_assert(offsetof(cmnEventData, field_C0) == 0xC0, "cmnEventData.field_C0");

/* ========================================================================
 * cmnMessageManager — message/group data manager
 * Size: 0x1340 (proven by FUN_14047ed10(0x1340,...) in caller FUN_14042f544)
 * Vtable: none observed (not a polymorphic class; *param_1 = 0 in ctor)
 * Note: ctor calls FUN_14017fd28(param_1+1) for sub-object init at offset 0x08
 * ======================================================================== */
typedef struct __attribute__((packed)) cmnMessageManager {
    /* 0x00 */ uint64_t field_00;       /* set to 0 in ctor (*param_1 = 0) */
    /* 0x08 */ uint8_t sub_object[0x88]; /* FUN_14017fd28(param_1+1) initializes this region */
    /* 0x90 */ uint32_t field_90;       /* rw, written as u32 in LoadCmnChunk/ctor */
    /* 0x94 */ uint32_t field_94;       /* w, set in LoadCmnChunk_0001 */
    /* 0x98 */ uint64_t field_98;       /* w, ctor (param_1[0x13]) */
    /* 0xA0 */ uint64_t field_A0;       /* w, ctor (param_1[0x14]) */
    /* 0xA8 */ uint64_t field_A8;       /* w, ctor (param_1[0x15]) */
    /* 0xB0 */ uint8_t pad_B0[0x1290]; /* remainder of 0x1340 allocation */
} cmnMessageManager;
static_assert(offsetof(cmnMessageManager, field_00) == 0x00, "cmnMessageManager.field_00");
static_assert(offsetof(cmnMessageManager, sub_object) == 0x08, "cmnMessageManager.sub_object");
static_assert(offsetof(cmnMessageManager, field_90) == 0x90, "cmnMessageManager.field_90");
static_assert(offsetof(cmnMessageManager, field_94) == 0x94, "cmnMessageManager.field_94");
static_assert(offsetof(cmnMessageManager, field_98) == 0x98, "cmnMessageManager.field_98");
static_assert(offsetof(cmnMessageManager, field_A0) == 0xA0, "cmnMessageManager.field_A0");
static_assert(offsetof(cmnMessageManager, field_A8) == 0xA8, "cmnMessageManager.field_A8");
static_assert(offsetof(cmnMessageManager, pad_B0) == 0xB0, "cmnMessageManager.pad_B0");

/* ========================================================================
 * ccShopHelpMessage — shop help message UI element
 * Size: unknown, >= 0x3E4 (highest observed access at offset 0x3E0, size 4)
 * Vtable: accessed via *(*param_1 + 0x58) in Draw (indirect vcall)
 * Fields are sparse; most accesses go through indirection (*param_1 deref)
 * ======================================================================== */
typedef struct __attribute__((packed)) ccShopHelpMessage {
    /* 0x00 */ void *vtable_or_ptr;     /* dereferenced in Ctrl/Draw */
    /* 0x08 */ uint8_t pad_08[0x2B8];  /* gap to first observed field */
    /* 0x2C0 */ uint64_t field_2C0;     /* r in Draw: indirect vcall target */
    /* 0x2C8 */ uint8_t pad_2C8[0x118]; /* gap */
    /* 0x3E0 */ uint32_t field_3E0;     /* r in Ctrl */
    /* 0x3E4 */ uint8_t pad_3E4[0x76]; /* padding to >= 0x45A alloc boundary */
} ccShopHelpMessage;
/* Size note: allocator FUN_14019f498(0x45a) seen in caller, but that may be a
 * parent container. Object size unproven; layout ends at last proven field. */
static_assert(offsetof(ccShopHelpMessage, vtable_or_ptr) == 0x00, "ccShopHelpMessage.vtable_or_ptr");
static_assert(offsetof(ccShopHelpMessage, pad_08) == 0x08, "ccShopHelpMessage.pad_08");
static_assert(offsetof(ccShopHelpMessage, field_2C0) == 0x2C0, "ccShopHelpMessage.field_2C0");
static_assert(offsetof(ccShopHelpMessage, pad_2C8) == 0x2C8, "ccShopHelpMessage.pad_2C8");
static_assert(offsetof(ccShopHelpMessage, field_3E0) == 0x3E0, "ccShopHelpMessage.field_3E0");
static_assert(offsetof(ccShopHelpMessage, pad_3E4) == 0x3E4, "ccShopHelpMessage.pad_3E4");

/* ========================================================================
 * nuccAnmStrm — animation stream player (cutscene driver)
 * Size: 0x960 (proven by FUN_14047ed10(0x960,"source\\AnmStrm\\nuccAnmStrm.cpp",0xee1))
 * Vtable: PTR_FUN_1406586d0 (set in ctor at *param_1)
 * Sub-vtables: param_1[0x2a] = PTR_FUN_140658748, param_1[0x38] = PTR_FUN_140658700,
 *              param_1[0x3d] = PTR_FUN_1406ee938
 * This is the largest and most complex struct in the group (158 fields observed).
 * Only high-confidence and frequently-accessed fields are named below.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnmStrm {
    /* 0x000 */ void *vtable;           /* PTR_FUN_1406586d0 */
    /* 0x008 */ uint64_t field_008;     /* zeroed in ctor (param_1[1]) */
    /* 0x010 */ uint8_t pad_010[0x08]; /* gap */
    /* 0x018 */ uint64_t field_018;     /* sub-object init FUN_140487c50(param_1+3) starts here */
    /* 0x020 */ uint8_t pad_020[0xF8]; /* gap to sub-vtable region */
    /* 0x118 */ uint64_t field_118;     /* part of sub-object block */
    /* 0x120 */ uint8_t pad_120[0x18]; /* gap */
    /* 0x138 */ uint64_t field_138;     /* rw, high confidence */
    /* 0x140 */ uint64_t field_140;     /* rw, high confidence */
    /* 0x148 */ uint32_t field_148;     /* w, high confidence */
    /* 0x14C */ uint32_t field_14C;     /* w, high confidence */
    /* 0x150 */ uint64_t field_150;     /* rw */
    /* 0x158 */ uint8_t pad_158[0x10]; /* gap */
    /* 0x168 */ uint64_t field_168;     /* rw, high confidence */
    /* 0x170 */ uint64_t field_170;     /* w */
    /* 0x178 */ uint64_t field_178;     /* w */
    /* 0x180 */ uint16_t field_180;     /* rw, high confidence (frame/state index?) */
    /* 0x182 */ uint8_t pad_182[0x06]; /* alignment */
    /* 0x188 */ uint64_t field_188;     /* rw */
    /* 0x190 */ uint8_t pad_190[0x10]; /* gap */
    /* 0x1A0 */ uint64_t field_1A0;     /* rw, high confidence */
    /* 0x1A8 */ uint64_t field_1A8;     /* w */
    /* 0x1B0 */ uint64_t field_1B0;     /* w */
    /* 0x1B8 */ uint16_t field_1B8;     /* rw, high confidence */
    /* 0x1BA */ uint8_t pad_1BA[0x06]; /* alignment */
    /* 0x1C0 */ uint64_t field_1C0;     /* rw */
    /* 0x1C8 */ uint8_t pad_1C8[0x10]; /* gap */
    /* 0x1D8 */ uint64_t field_1D8;     /* rw, high confidence, 4r+3w */
    /* 0x1E0 */ uint32_t field_1E0;     /* rw, high confidence */
    /* 0x1E4 */ uint8_t pad_1E4[0x04]; /* alignment */
    /* 0x1E8 */ uint64_t field_1E8;     /* rw */
    /* 0x1F0 */ uint8_t pad_1F0[0x10]; /* gap */
    /* 0x200 */ uint64_t field_200;     /* rw, high confidence, 2r+2w */
    /* 0x208 */ uint32_t field_208;     /* w, high confidence */
    /* 0x20C */ uint8_t pad_20C[0x04]; /* alignment */
    /* 0x210 */ uint64_t field_210;     /* rw */
    /* 0x218 */ uint8_t pad_218[0x10]; /* gap */
    /* 0x228 */ uint64_t field_228;     /* rw, high confidence, 2r+2w */
    /* 0x230 */ uint32_t field_230;     /* w, high confidence */
    /* 0x234 */ uint8_t pad_234[0x04]; /* alignment */
    /* 0x238 */ uint64_t field_238;     /* rw */
    /* 0x240 */ uint8_t pad_240[0x10]; /* gap */
    /* 0x250 */ uint64_t field_250;     /* rw, high confidence, 2r+2w */
    /* 0x258 */ uint32_t field_258;     /* w, high confidence */
    /* 0x25C */ uint8_t pad_25C[0x04]; /* alignment */
    /* 0x260 */ uint64_t field_260;     /* rw, high confidence, 1r+2w */
    /* 0x268 */ uint32_t field_268;     /* rw */
    /* 0x26C */ uint8_t pad_26C[0x4BC]; /* large gap to upper fields */
    /* 0x728 */ uint8_t upper_block[0x238]; /* fields 0x728-0x95F: many w-only init fields */
} nuccAnmStrm;
static_assert(offsetof(nuccAnmStrm, vtable) == 0x000, "nuccAnmStrm.vtable");
static_assert(offsetof(nuccAnmStrm, field_008) == 0x008, "nuccAnmStrm.field_008");
static_assert(offsetof(nuccAnmStrm, pad_010) == 0x010, "nuccAnmStrm.pad_010");
static_assert(offsetof(nuccAnmStrm, field_018) == 0x018, "nuccAnmStrm.field_018");
static_assert(offsetof(nuccAnmStrm, pad_020) == 0x020, "nuccAnmStrm.pad_020");
static_assert(offsetof(nuccAnmStrm, field_118) == 0x118, "nuccAnmStrm.field_118");
static_assert(offsetof(nuccAnmStrm, pad_120) == 0x120, "nuccAnmStrm.pad_120");
static_assert(offsetof(nuccAnmStrm, field_138) == 0x138, "nuccAnmStrm.field_138");
static_assert(offsetof(nuccAnmStrm, field_140) == 0x140, "nuccAnmStrm.field_140");
static_assert(offsetof(nuccAnmStrm, field_148) == 0x148, "nuccAnmStrm.field_148");
static_assert(offsetof(nuccAnmStrm, field_14C) == 0x14C, "nuccAnmStrm.field_14C");
static_assert(offsetof(nuccAnmStrm, field_150) == 0x150, "nuccAnmStrm.field_150");
static_assert(offsetof(nuccAnmStrm, pad_158) == 0x158, "nuccAnmStrm.pad_158");
static_assert(offsetof(nuccAnmStrm, field_168) == 0x168, "nuccAnmStrm.field_168");
static_assert(offsetof(nuccAnmStrm, field_170) == 0x170, "nuccAnmStrm.field_170");
static_assert(offsetof(nuccAnmStrm, field_178) == 0x178, "nuccAnmStrm.field_178");
static_assert(offsetof(nuccAnmStrm, field_180) == 0x180, "nuccAnmStrm.field_180");
static_assert(offsetof(nuccAnmStrm, pad_182) == 0x182, "nuccAnmStrm.pad_182");
static_assert(offsetof(nuccAnmStrm, field_188) == 0x188, "nuccAnmStrm.field_188");
static_assert(offsetof(nuccAnmStrm, pad_190) == 0x190, "nuccAnmStrm.pad_190");
static_assert(offsetof(nuccAnmStrm, field_1A0) == 0x1A0, "nuccAnmStrm.field_1A0");
static_assert(offsetof(nuccAnmStrm, field_1A8) == 0x1A8, "nuccAnmStrm.field_1A8");
static_assert(offsetof(nuccAnmStrm, field_1B0) == 0x1B0, "nuccAnmStrm.field_1B0");
static_assert(offsetof(nuccAnmStrm, field_1B8) == 0x1B8, "nuccAnmStrm.field_1B8");
static_assert(offsetof(nuccAnmStrm, pad_1BA) == 0x1BA, "nuccAnmStrm.pad_1BA");
static_assert(offsetof(nuccAnmStrm, field_1C0) == 0x1C0, "nuccAnmStrm.field_1C0");
static_assert(offsetof(nuccAnmStrm, pad_1C8) == 0x1C8, "nuccAnmStrm.pad_1C8");
static_assert(offsetof(nuccAnmStrm, field_1D8) == 0x1D8, "nuccAnmStrm.field_1D8");
static_assert(offsetof(nuccAnmStrm, field_1E0) == 0x1E0, "nuccAnmStrm.field_1E0");
static_assert(offsetof(nuccAnmStrm, pad_1E4) == 0x1E4, "nuccAnmStrm.pad_1E4");
static_assert(offsetof(nuccAnmStrm, field_1E8) == 0x1E8, "nuccAnmStrm.field_1E8");
static_assert(offsetof(nuccAnmStrm, pad_1F0) == 0x1F0, "nuccAnmStrm.pad_1F0");
static_assert(offsetof(nuccAnmStrm, field_200) == 0x200, "nuccAnmStrm.field_200");
static_assert(offsetof(nuccAnmStrm, field_208) == 0x208, "nuccAnmStrm.field_208");
static_assert(offsetof(nuccAnmStrm, pad_20C) == 0x20C, "nuccAnmStrm.pad_20C");
static_assert(offsetof(nuccAnmStrm, field_210) == 0x210, "nuccAnmStrm.field_210");
static_assert(offsetof(nuccAnmStrm, pad_218) == 0x218, "nuccAnmStrm.pad_218");
static_assert(offsetof(nuccAnmStrm, field_228) == 0x228, "nuccAnmStrm.field_228");
static_assert(offsetof(nuccAnmStrm, field_230) == 0x230, "nuccAnmStrm.field_230");
static_assert(offsetof(nuccAnmStrm, pad_234) == 0x234, "nuccAnmStrm.pad_234");
static_assert(offsetof(nuccAnmStrm, field_238) == 0x238, "nuccAnmStrm.field_238");
static_assert(offsetof(nuccAnmStrm, pad_240) == 0x240, "nuccAnmStrm.pad_240");
static_assert(offsetof(nuccAnmStrm, field_250) == 0x250, "nuccAnmStrm.field_250");
static_assert(offsetof(nuccAnmStrm, field_258) == 0x258, "nuccAnmStrm.field_258");
static_assert(offsetof(nuccAnmStrm, pad_25C) == 0x25C, "nuccAnmStrm.pad_25C");
static_assert(offsetof(nuccAnmStrm, field_260) == 0x260, "nuccAnmStrm.field_260");
static_assert(offsetof(nuccAnmStrm, field_268) == 0x268, "nuccAnmStrm.field_268");
static_assert(offsetof(nuccAnmStrm, pad_26C) == 0x26C, "nuccAnmStrm.pad_26C");
static_assert(offsetof(nuccAnmStrm, upper_block) == 0x728, "nuccAnmStrm.upper_block");

#endif /* ST1C03_H */