/* st4c07.h — Story cutscene/event structs for NARUTO STORM 4 PC 1.09 (s4) */
/* INFERRED from static analysis. Not CONFIRMED at runtime. */
/* Generated 2026-10-19 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* MovieImpl — Scaleform GFx movie implementation */
/* Size: unknown, >= 0x5304 (highest proven access at 0x5300, no allocator proof) */
/* Vtable at offset 0x0, entries at vtable+0x1e0, vtable+0x1f0, vtable+0x200 */
/* All fields are uint8_t[] sized by offset gaps to guarantee exact placement. */
/* Comments show decompiler-inferred types; actual sizes come from offset gaps. */
struct MovieImpl {
    uint8_t vtable[16]; /* 0x0 void* (declared 8B, gap=16B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x10[8]; /* 0x10 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x18[4]; /* 0x18 int64_t (declared 8B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t viewport_x[4]; /* 0x1c float (declared 4B, gap=4B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x20[6]; /* 0x20 int64_t (declared 8B, gap=6B) [PRES] MovieImpl::Advance */
    uint8_t hit_test_y[2]; /* 0x26 float (declared 4B, gap=2B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x28[4]; /* 0x28 uint32_t (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0x2c[8]; /* 0x2c uint32_t (declared 4B, gap=8B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x34[20]; /* 0x34 uint32_t (declared 4B, gap=20B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x48[8]; /* 0x48 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x50[8]; /* 0x50 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x58[8]; /* 0x58 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x60[24]; /* 0x60 int64_t (declared 8B, gap=24B) [PRES] MovieImpl::Advance */
    uint8_t field_0x78[8]; /* 0x78 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x80[96]; /* 0x80 int64_t (declared 8B, gap=96B) [PRES] MovieImpl::Advance */
    uint8_t field_0xe0[4]; /* 0xe0 float (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0xe4[12]; /* 0xe4 float (declared 4B, gap=12B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0xf0[4]; /* 0xf0 float (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0xf4[4]; /* 0xf4 float (declared 4B, gap=4B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0xf8[4]; /* 0xf8 float (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0xfc[20]; /* 0xfc float (declared 4B, gap=20B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x110[32]; /* 0x110 int64_t (declared 8B, gap=32B) [PRES] MovieImpl::Advance */
    uint8_t field_0x130[4]; /* 0x130 float (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0x134[48]; /* 0x134 float (declared 4B, gap=48B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x164[8]; /* 0x164 uint32_t (declared 4B, gap=8B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x16c[8]; /* 0x16c uint32_t (declared 4B, gap=8B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x174[8]; /* 0x174 uint32_t (declared 4B, gap=8B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x17c[40]; /* 0x17c uint32_t (declared 4B, gap=40B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x1a4[8]; /* 0x1a4 uint32_t (declared 4B, gap=8B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x1ac[116]; /* 0x1ac uint32_t (declared 4B, gap=116B) [PRES] MovieImpl::GetTopMostEntity */
    uint8_t field_0x220[8]; /* 0x220 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x228[8]; /* 0x228 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x230[8]; /* 0x230 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x238[16]; /* 0x238 int64_t (declared 8B, gap=16B) [PRES] MovieImpl::Advance */
    uint8_t field_0x248[8]; /* 0x248 uint64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x250[24]; /* 0x250 int64_t (declared 8B, gap=24B) [PRES] MovieImpl::Advance */
    uint8_t field_0x268[8]; /* 0x268 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x270[4]; /* 0x270 float (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0x274[12]; /* 0x274 float (declared 4B, gap=12B) [PRES] MovieImpl::Advance */
    uint8_t field_0x280[8008]; /* 0x280 int64_t (declared 8B, gap=8008B) [PRES] MovieImpl::Advance */
    uint8_t field_0x21c8[56]; /* 0x21c8 int64_t (declared 8B, gap=56B) [PRES] MovieImpl::Advance */
    uint8_t field_0x2200[64]; /* 0x2200 int32_t (declared 4B, gap=64B) [PRES] MovieImpl::Advance */
    uint8_t field_0x2240[8]; /* 0x2240 uint32_t (declared 4B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x2248[4]; /* 0x2248 uint32_t (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0x224c[420]; /* 0x224c uint32_t (declared 4B, gap=420B) [PRES] MovieImpl::Advance */
    uint8_t field_0x23f0[16]; /* 0x23f0 uint32_t (declared 4B, gap=16B) [PRES] MovieImpl::Advance */
    uint8_t field_0x2400[10048]; /* 0x2400 int64_t (declared 8B, gap=10048B) [PRES] MovieImpl::Advance */
    uint8_t field_0x4b40[336]; /* 0x4b40 int64_t (declared 8B, gap=336B) [PRES] MovieImpl::Advance */
    uint8_t field_0x4c90[8]; /* 0x4c90 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x4c98[80]; /* 0x4c98 uint64_t (declared 8B, gap=80B) [PRES] MovieImpl::Advance */
    uint8_t field_0x4ce8[1520]; /* 0x4ce8 uint64_t (declared 8B, gap=1520B) [PRES] MovieImpl::Advance */
    uint8_t field_0x52d8[8]; /* 0x52d8 int64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x52e0[8]; /* 0x52e0 uint64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t field_0x52e8[8]; /* 0x52e8 uint64_t (declared 8B, gap=8B) [PRES] MovieImpl::Advance */
    uint8_t flags[4]; /* 0x52f0 uint32_t (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
    uint8_t field_0x52f4[12]; /* 0x52f4 uint32_t (declared 4B, gap=12B) [PRES] MovieImpl::Advance */
    uint8_t field_0x5300[4]; /* 0x5300 uint32_t (declared 4B, gap=4B) [PRES] MovieImpl::Advance */
};

static_assert(offsetof(struct MovieImpl, vtable) == 0x0, "MovieImpl.vtable offset");
static_assert(offsetof(struct MovieImpl, field_0x10) == 0x10, "MovieImpl.field_0x10 offset");
static_assert(offsetof(struct MovieImpl, field_0x18) == 0x18, "MovieImpl.field_0x18 offset");
static_assert(offsetof(struct MovieImpl, viewport_x) == 0x1c, "MovieImpl.viewport_x offset");
static_assert(offsetof(struct MovieImpl, field_0x20) == 0x20, "MovieImpl.field_0x20 offset");
static_assert(offsetof(struct MovieImpl, hit_test_y) == 0x26, "MovieImpl.hit_test_y offset");
static_assert(offsetof(struct MovieImpl, field_0x28) == 0x28, "MovieImpl.field_0x28 offset");
static_assert(offsetof(struct MovieImpl, field_0x2c) == 0x2c, "MovieImpl.field_0x2c offset");
static_assert(offsetof(struct MovieImpl, field_0x34) == 0x34, "MovieImpl.field_0x34 offset");
static_assert(offsetof(struct MovieImpl, field_0x48) == 0x48, "MovieImpl.field_0x48 offset");
static_assert(offsetof(struct MovieImpl, field_0x50) == 0x50, "MovieImpl.field_0x50 offset");
static_assert(offsetof(struct MovieImpl, field_0x58) == 0x58, "MovieImpl.field_0x58 offset");
static_assert(offsetof(struct MovieImpl, field_0x60) == 0x60, "MovieImpl.field_0x60 offset");
static_assert(offsetof(struct MovieImpl, field_0x78) == 0x78, "MovieImpl.field_0x78 offset");
static_assert(offsetof(struct MovieImpl, field_0x80) == 0x80, "MovieImpl.field_0x80 offset");
static_assert(offsetof(struct MovieImpl, field_0xe0) == 0xe0, "MovieImpl.field_0xe0 offset");
static_assert(offsetof(struct MovieImpl, field_0xe4) == 0xe4, "MovieImpl.field_0xe4 offset");
static_assert(offsetof(struct MovieImpl, field_0xf0) == 0xf0, "MovieImpl.field_0xf0 offset");
static_assert(offsetof(struct MovieImpl, field_0xf4) == 0xf4, "MovieImpl.field_0xf4 offset");
static_assert(offsetof(struct MovieImpl, field_0xf8) == 0xf8, "MovieImpl.field_0xf8 offset");
static_assert(offsetof(struct MovieImpl, field_0xfc) == 0xfc, "MovieImpl.field_0xfc offset");
static_assert(offsetof(struct MovieImpl, field_0x110) == 0x110, "MovieImpl.field_0x110 offset");
static_assert(offsetof(struct MovieImpl, field_0x130) == 0x130, "MovieImpl.field_0x130 offset");
static_assert(offsetof(struct MovieImpl, field_0x134) == 0x134, "MovieImpl.field_0x134 offset");
static_assert(offsetof(struct MovieImpl, field_0x164) == 0x164, "MovieImpl.field_0x164 offset");
static_assert(offsetof(struct MovieImpl, field_0x16c) == 0x16c, "MovieImpl.field_0x16c offset");
static_assert(offsetof(struct MovieImpl, field_0x174) == 0x174, "MovieImpl.field_0x174 offset");
static_assert(offsetof(struct MovieImpl, field_0x17c) == 0x17c, "MovieImpl.field_0x17c offset");
static_assert(offsetof(struct MovieImpl, field_0x1a4) == 0x1a4, "MovieImpl.field_0x1a4 offset");
static_assert(offsetof(struct MovieImpl, field_0x1ac) == 0x1ac, "MovieImpl.field_0x1ac offset");
static_assert(offsetof(struct MovieImpl, field_0x220) == 0x220, "MovieImpl.field_0x220 offset");
static_assert(offsetof(struct MovieImpl, field_0x228) == 0x228, "MovieImpl.field_0x228 offset");
static_assert(offsetof(struct MovieImpl, field_0x230) == 0x230, "MovieImpl.field_0x230 offset");
static_assert(offsetof(struct MovieImpl, field_0x238) == 0x238, "MovieImpl.field_0x238 offset");
static_assert(offsetof(struct MovieImpl, field_0x248) == 0x248, "MovieImpl.field_0x248 offset");
static_assert(offsetof(struct MovieImpl, field_0x250) == 0x250, "MovieImpl.field_0x250 offset");
static_assert(offsetof(struct MovieImpl, field_0x268) == 0x268, "MovieImpl.field_0x268 offset");
static_assert(offsetof(struct MovieImpl, field_0x270) == 0x270, "MovieImpl.field_0x270 offset");
static_assert(offsetof(struct MovieImpl, field_0x274) == 0x274, "MovieImpl.field_0x274 offset");
static_assert(offsetof(struct MovieImpl, field_0x280) == 0x280, "MovieImpl.field_0x280 offset");
static_assert(offsetof(struct MovieImpl, field_0x21c8) == 0x21c8, "MovieImpl.field_0x21c8 offset");
static_assert(offsetof(struct MovieImpl, field_0x2200) == 0x2200, "MovieImpl.field_0x2200 offset");
static_assert(offsetof(struct MovieImpl, field_0x2240) == 0x2240, "MovieImpl.field_0x2240 offset");
static_assert(offsetof(struct MovieImpl, field_0x2248) == 0x2248, "MovieImpl.field_0x2248 offset");
static_assert(offsetof(struct MovieImpl, field_0x224c) == 0x224c, "MovieImpl.field_0x224c offset");
static_assert(offsetof(struct MovieImpl, field_0x23f0) == 0x23f0, "MovieImpl.field_0x23f0 offset");
static_assert(offsetof(struct MovieImpl, field_0x2400) == 0x2400, "MovieImpl.field_0x2400 offset");
static_assert(offsetof(struct MovieImpl, field_0x4b40) == 0x4b40, "MovieImpl.field_0x4b40 offset");
static_assert(offsetof(struct MovieImpl, field_0x4c90) == 0x4c90, "MovieImpl.field_0x4c90 offset");
static_assert(offsetof(struct MovieImpl, field_0x4c98) == 0x4c98, "MovieImpl.field_0x4c98 offset");
static_assert(offsetof(struct MovieImpl, field_0x4ce8) == 0x4ce8, "MovieImpl.field_0x4ce8 offset");
static_assert(offsetof(struct MovieImpl, field_0x52d8) == 0x52d8, "MovieImpl.field_0x52d8 offset");
static_assert(offsetof(struct MovieImpl, field_0x52e0) == 0x52e0, "MovieImpl.field_0x52e0 offset");
static_assert(offsetof(struct MovieImpl, field_0x52e8) == 0x52e8, "MovieImpl.field_0x52e8 offset");
static_assert(offsetof(struct MovieImpl, flags) == 0x52f0, "MovieImpl.flags offset");
static_assert(offsetof(struct MovieImpl, field_0x52f4) == 0x52f4, "MovieImpl.field_0x52f4 offset");
static_assert(offsetof(struct MovieImpl, field_0x5300) == 0x5300, "MovieImpl.field_0x5300 offset");

/* cmnEventData — common event data container */
/* Size: unknown, >= 0xA4 (sub-object at 0x9c, no allocator proof) */
/* Vtable set in dtor to PTR_FUN_141119298 */
/* All fields are uint8_t[] sized by offset gaps to guarantee exact placement. */
/* Comments show decompiler-inferred types; actual sizes come from offset gaps. */
struct cmnEventData {
    uint8_t vtable_or_size[8]; /* 0x0 void* (declared 8B, gap=8B) [PRES] cmnEventData::cmnEventData */
    uint8_t field_0x8[4]; /* 0x8 uint32_t (declared 4B, gap=4B) [PRES] cmnEventData::~cmnEventData */
    uint8_t field_0xc[144]; /* 0xc uint32_t (declared 4B, gap=144B) [PRES] cmnEventData::~cmnEventData */
    uint8_t sub_object_0x9c[8]; /* 0x9c int64_t (declared 8B, gap=8B) [PRES] cmnEventData::~cmnEventData */
};

static_assert(offsetof(struct cmnEventData, vtable_or_size) == 0x0, "cmnEventData.vtable_or_size offset");
static_assert(offsetof(struct cmnEventData, field_0x8) == 0x8, "cmnEventData.field_0x8 offset");
static_assert(offsetof(struct cmnEventData, field_0xc) == 0xc, "cmnEventData.field_0xc offset");
static_assert(offsetof(struct cmnEventData, sub_object_0x9c) == 0x9c, "cmnEventData.sub_object_0x9c offset");

/*
 * Classes with < 3 methods in s4 (skipped for struct reconstruction):
 * ccTalkState (2), ccUiAdvTalkWindow (1), ccUiBattleEndDemo (2),
 * ccUiMessage (1), ccWindowTalkFix (1), cmnMessageGroupLabel (1),
 * cmnMessageManager (1), Event (1), mmScriptNodeXML (1),
 * mmStatMemoryEvent (1), MovieRoot (1)
 *
 * Movie (3 methods) — state_surface returned 0 fields; all methods
 * use byte-cast accesses only. Layout cannot be reconstructed from
 * this build's decompilation alone.
 */
