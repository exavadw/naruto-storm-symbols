// ccGameDrawEnv (NSUNS3.exe, build s3) — reconstructed from Ghidra decompilation
// Constructor RVA: 0x6336D8
// Minimum size: >= 0xe18 bytes (highest proven access: param_1+0xe10, 8-byte write in ctor)
// Confidence: INFERRED (static analysis only; verify with replay trace before CONFIRMED)
// Generated: 2026-10-19
// Cross-build: s2 struct was >= 0x1D28; s3 is smaller (different engine revision)
#pragma once
#include <stdint.h>
#include <stddef.h>

struct ccGameDrawEnv {
    // 0x000: ctor sets vtable via sub-object init
    uint64_t vtablePtr;
    // 0x008: BlockAllocator base data (to 0x18C)
    uint8_t blockAllocatorBase[0x184];
    // 0x18c: FUN_140684430(param_1+0x18c)
    uint8_t subObj_18C[0xc];
    // 0x198: ctor loop stride 4 count 2
    uint32_t fogLoop_198[0x2];
    // 0x1a0: memset(0, part of 0x60 block at 0x1a0)
    uint8_t pad_1A0[0x4];
    // 0x1a4: SetFogParam writes at +0x1a4+index*0x30
    uint8_t fogParamSrc_1A4[0x18];
    // 0x1bc: SetFogParam reads/writes here
    uint8_t fogVec3_1BC[0xc];
    // 0x1c8: gap to next proven field at 0x200
    uint8_t pad_1C8[0x38];
    // 0x200: *(u64*)(param_1+0x200)=0
    uint64_t zero_200;
    // 0x208: *(u64*)(param_1+0x208)=0
    uint64_t zero_208;
    // 0x210: memset(0, 0x20); also FUN_1406b6ed0 init
    uint8_t zeroed_210[0x20];
    // 0x230: shadow params[2], stride 0x60
    uint8_t shadowArray_230[0xc0];
    // 0x2f0: memset(0, 0x20)
    uint8_t zeroed_2F0[0x20];
    // 0x310: *(u64*)(param_1+0x310)=0
    uint64_t zero_310;
    // 0x318: *(u64*)(param_1+0x318)=0
    uint64_t zero_318;
    // 0x320: DoF params[2], stride 0x18
    uint8_t dofArray_320[0x30];
    // 0x350: ResetMotBlurParam: +0x350+index*4
    uint8_t motBlurArray_350[0x8];
    // 0x358: memset(0, 0x38)
    uint8_t zeroed_358[0x38];
    // 0x390: memset(0, 0x28)
    uint8_t zeroed_390[0x28];
    // 0x3b8: color conv params (stride 0x14)
    uint8_t colorConvArray_3B8[0x48];
    // 0x400: directional filter params
    uint8_t colorFilterDirArray_400[0x144];
    // 0x544: radial filter params
    uint8_t colorFilterRadialArray_544[0x180];
    // 0x6c4: sunshafts params[2], stride 0x40
    uint8_t sunshaftsArray_6C4[0x7c];
    // 0x740: memset(0, 0x80)
    uint8_t zeroed_740[0x80];
    // 0x7c0: float4 structs, stride 0x20, count 2
    uint8_t float4Array_7C0[0x40];
    // 0x800: memset(0, 0x30)
    uint8_t zeroed_800[0x30];
    // 0x830: padding to 0x8F0
    uint8_t pad_830[0xc0];
    // 0x8f0: memset(0, 0x68)
    uint8_t zeroed_8F0[0x68];
    // 0x958: memset(0, 0x30)
    uint8_t zeroed_958[0x30];
    // 0x988: fisheye params, memset(0,0x28) in ctor
    uint8_t fishEyeArray_988[0x28];
    // 0x9b0: padding to 0xAE8
    uint8_t pad_9B0[0x138];
    // 0xae8: sub-object vtable ptrs
    uint8_t vtableArray_AE8[0x28];
    // 0xb10: structs with 1.0f fields, stride 0x40
    uint8_t largeStructArray_B10[0x80];
    // 0xb90: linked-list container
    uint8_t container_B90[0x38];
    // 0xbc8: linked-list container
    uint8_t container_BC8[0x38];
    // 0xc00: FUN_1405bcc9c(param_1+0xc00)
    uint8_t subObj_C00[0x60];
    // 0xc60: ResetShadowParam reads *(u64*)(+0xc60)
    uint64_t shadowSrc_C60;
    // 0xc68: ResetShadowParam reads *(u32*)(+0xc68)
    uint32_t shadowSrc_C68;
    // 0xc6c: ResetShadowParam reads *(u32*)(+0xc6c)
    uint32_t shadowSrc_C6C;
    // 0xc70: ResetShadowParam reads *(u32*)(+0xc70)
    uint32_t shadowSrc_C70;
    // 0xc74: ResetShadowParam reads *(u32*)(+0xc74)
    uint32_t shadowSrc_C74;
    // 0xc78: ResetShadowParam reads *(u32*)(+0xc78)
    uint32_t shadowSrc_C78;
    // 0xc7c: ResetShadowParam reads *(u32*)(+0xc7c)
    uint32_t shadowSrc_C7C;
    // 0xc80: ResetFogParam reads from here
    uint8_t fogSrc_C80[0x20];
    // 0xca0: ResetColorConvParam reads
    uint32_t colorConvSrc_CA0;
    // 0xca4: ResetColorConvParam reads
    uint32_t colorConvSrc_CA4;
    // 0xca8: ResetColorConvParam reads
    uint32_t colorConvSrc_CA8;
    // 0xcac: ResetColorConvParam reads
    uint32_t colorConvSrc_CAC;
    // 0xcb0: ResetGlareParam reads
    uint32_t glareSrc_CB0;
    // 0xcb4: ResetGlareParam reads
    uint32_t glareSrc_CB4;
    // 0xcb8: ResetGlareParam reads
    uint32_t glareSrc_CB8;
    // 0xcbc: ResetGlareParam reads
    uint32_t glareSrc_CBC;
    // 0xcc0: padding to 0xCE4
    uint8_t pad_CC0[0x24];
    // 0xce4: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_CE4;
    // 0xce8: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_CE8;
    // 0xcec: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_CEC;
    // 0xcf0: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_CF0;
    // 0xcf4: padding to 0xD00
    uint8_t pad_CF4[0xc];
    // 0xd00: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D00;
    // 0xd04: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D04;
    // 0xd08: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D08;
    // 0xd0c: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D0C;
    // 0xd10: ResetSunshaftsParam reads *(u64*)
    uint64_t sunshaftsSrc_D10;
    // 0xd18: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D18;
    // 0xd1c: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D1C;
    // 0xd20: ResetSunshaftsParam reads
    uint32_t sunshaftsSrc_D20;
    // 0xd24: padding to 0xD30
    uint8_t pad_D24[0xc];
    // 0xd30: *(u64*)(param_1+0xd30)=0
    uint64_t zero_D30;
    // 0xd38: *(u64*)(param_1+0xd38)=0
    uint64_t zero_D38;
    // 0xd40: *(u64*)(param_1+0xd40)=0
    uint64_t zero_D40;
    // 0xd48: Init writes *(u32*)(+0xd48)
    uint64_t initField_D48;
    // 0xd50: ZRange params[2], stride 0x10
    uint8_t zrangeArray_D50[0x20];
    // 0xd70: Init allocates, Exit frees
    uint64_t ptr_D70;
    // 0xd78: two 0x18-byte structs
    uint8_t initStruct_D78[0x30];
    // 0xda8: FUN_1406bffb0/FUN_1406c0060
    uint8_t subObj_DA8[0x18];
    // 0xdc0: padding to highest proven access
    uint8_t pad_DC0[0x44];
    // 0xe04: implicit align padding before u64 at 0xE08
    uint8_t alignPad_E04[0x4];
    // 0xe08: ctor/shadow writes (was E04 in decomp, u64 aligned to E08)
    uint64_t highField_E08;
    // 0xe10: ctor writes (was E0C in decomp, u64 aligned to E10)
    uint64_t highField_E10;
    // 0xe18: End of proven object
};

// Compile-time offset checks (INFERRED from decompiler output)
_Static_assert(offsetof(struct ccGameDrawEnv, vtablePtr) == 0x0, "vtablePtr");
_Static_assert(offsetof(struct ccGameDrawEnv, blockAllocatorBase) == 0x8, "blockAllocatorBase");
_Static_assert(offsetof(struct ccGameDrawEnv, subObj_18C) == 0x18c, "subObj_18C");
_Static_assert(offsetof(struct ccGameDrawEnv, fogLoop_198) == 0x198, "fogLoop_198");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_1A0) == 0x1a0, "pad_1A0");
_Static_assert(offsetof(struct ccGameDrawEnv, fogParamSrc_1A4) == 0x1a4, "fogParamSrc_1A4");
_Static_assert(offsetof(struct ccGameDrawEnv, fogVec3_1BC) == 0x1bc, "fogVec3_1BC");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_1C8) == 0x1c8, "pad_1C8");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_200) == 0x200, "zero_200");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_208) == 0x208, "zero_208");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_210) == 0x210, "zeroed_210");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowArray_230) == 0x230, "shadowArray_230");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_2F0) == 0x2f0, "zeroed_2F0");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_310) == 0x310, "zero_310");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_318) == 0x318, "zero_318");
_Static_assert(offsetof(struct ccGameDrawEnv, dofArray_320) == 0x320, "dofArray_320");
_Static_assert(offsetof(struct ccGameDrawEnv, motBlurArray_350) == 0x350, "motBlurArray_350");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_358) == 0x358, "zeroed_358");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_390) == 0x390, "zeroed_390");
_Static_assert(offsetof(struct ccGameDrawEnv, colorConvArray_3B8) == 0x3b8, "colorConvArray_3B8");
_Static_assert(offsetof(struct ccGameDrawEnv, colorFilterDirArray_400) == 0x400, "colorFilterDirArray_400");
_Static_assert(offsetof(struct ccGameDrawEnv, colorFilterRadialArray_544) == 0x544, "colorFilterRadialArray_544");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsArray_6C4) == 0x6c4, "sunshaftsArray_6C4");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_740) == 0x740, "zeroed_740");
_Static_assert(offsetof(struct ccGameDrawEnv, float4Array_7C0) == 0x7c0, "float4Array_7C0");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_800) == 0x800, "zeroed_800");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_830) == 0x830, "pad_830");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_8F0) == 0x8f0, "zeroed_8F0");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroed_958) == 0x958, "zeroed_958");
_Static_assert(offsetof(struct ccGameDrawEnv, fishEyeArray_988) == 0x988, "fishEyeArray_988");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_9B0) == 0x9b0, "pad_9B0");
_Static_assert(offsetof(struct ccGameDrawEnv, vtableArray_AE8) == 0xae8, "vtableArray_AE8");
_Static_assert(offsetof(struct ccGameDrawEnv, largeStructArray_B10) == 0xb10, "largeStructArray_B10");
_Static_assert(offsetof(struct ccGameDrawEnv, container_B90) == 0xb90, "container_B90");
_Static_assert(offsetof(struct ccGameDrawEnv, container_BC8) == 0xbc8, "container_BC8");
_Static_assert(offsetof(struct ccGameDrawEnv, subObj_C00) == 0xc00, "subObj_C00");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C60) == 0xc60, "shadowSrc_C60");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C68) == 0xc68, "shadowSrc_C68");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C6C) == 0xc6c, "shadowSrc_C6C");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C70) == 0xc70, "shadowSrc_C70");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C74) == 0xc74, "shadowSrc_C74");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C78) == 0xc78, "shadowSrc_C78");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowSrc_C7C) == 0xc7c, "shadowSrc_C7C");
_Static_assert(offsetof(struct ccGameDrawEnv, fogSrc_C80) == 0xc80, "fogSrc_C80");
_Static_assert(offsetof(struct ccGameDrawEnv, colorConvSrc_CA0) == 0xca0, "colorConvSrc_CA0");
_Static_assert(offsetof(struct ccGameDrawEnv, colorConvSrc_CA4) == 0xca4, "colorConvSrc_CA4");
_Static_assert(offsetof(struct ccGameDrawEnv, colorConvSrc_CA8) == 0xca8, "colorConvSrc_CA8");
_Static_assert(offsetof(struct ccGameDrawEnv, colorConvSrc_CAC) == 0xcac, "colorConvSrc_CAC");
_Static_assert(offsetof(struct ccGameDrawEnv, glareSrc_CB0) == 0xcb0, "glareSrc_CB0");
_Static_assert(offsetof(struct ccGameDrawEnv, glareSrc_CB4) == 0xcb4, "glareSrc_CB4");
_Static_assert(offsetof(struct ccGameDrawEnv, glareSrc_CB8) == 0xcb8, "glareSrc_CB8");
_Static_assert(offsetof(struct ccGameDrawEnv, glareSrc_CBC) == 0xcbc, "glareSrc_CBC");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_CC0) == 0xcc0, "pad_CC0");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_CE4) == 0xce4, "sunshaftsSrc_CE4");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_CE8) == 0xce8, "sunshaftsSrc_CE8");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_CEC) == 0xcec, "sunshaftsSrc_CEC");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_CF0) == 0xcf0, "sunshaftsSrc_CF0");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_CF4) == 0xcf4, "pad_CF4");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D00) == 0xd00, "sunshaftsSrc_D00");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D04) == 0xd04, "sunshaftsSrc_D04");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D08) == 0xd08, "sunshaftsSrc_D08");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D0C) == 0xd0c, "sunshaftsSrc_D0C");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D10) == 0xd10, "sunshaftsSrc_D10");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D18) == 0xd18, "sunshaftsSrc_D18");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D1C) == 0xd1c, "sunshaftsSrc_D1C");
_Static_assert(offsetof(struct ccGameDrawEnv, sunshaftsSrc_D20) == 0xd20, "sunshaftsSrc_D20");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_D24) == 0xd24, "pad_D24");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_D30) == 0xd30, "zero_D30");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_D38) == 0xd38, "zero_D38");
_Static_assert(offsetof(struct ccGameDrawEnv, zero_D40) == 0xd40, "zero_D40");
_Static_assert(offsetof(struct ccGameDrawEnv, initField_D48) == 0xd48, "initField_D48");
_Static_assert(offsetof(struct ccGameDrawEnv, zrangeArray_D50) == 0xd50, "zrangeArray_D50");
_Static_assert(offsetof(struct ccGameDrawEnv, ptr_D70) == 0xd70, "ptr_D70");
_Static_assert(offsetof(struct ccGameDrawEnv, initStruct_D78) == 0xd78, "initStruct_D78");
_Static_assert(offsetof(struct ccGameDrawEnv, subObj_DA8) == 0xda8, "subObj_DA8");
_Static_assert(offsetof(struct ccGameDrawEnv, pad_DC0) == 0xdc0, "pad_DC0");
_Static_assert(offsetof(struct ccGameDrawEnv, alignPad_E04) == 0xe04, "alignPad_E04");
_Static_assert(offsetof(struct ccGameDrawEnv, highField_E08) == 0xe08, "highField_E08");
_Static_assert(offsetof(struct ccGameDrawEnv, highField_E10) == 0xe10, "highField_E10");
// Size not asserted: true size unknown, >= 0xe18
