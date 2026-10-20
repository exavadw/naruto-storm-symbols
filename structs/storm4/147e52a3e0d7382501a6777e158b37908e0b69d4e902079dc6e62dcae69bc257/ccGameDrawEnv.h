#ifndef CCGAMEDRAWENV_S4_H
#define CCGAMEDRAWENV_S4_H

#include <stdint.h>
#include <stddef.h>

/*
 * ccGameDrawEnv - NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe, build s4)
 *
 * Reconstructed from static analysis of ctor (RVA 0x85B5B8), Init (RVA 0x85D020),
 * Exit (RVA 0x85D2EC) and 83 other cached decompilations (86/87 cached; 1 failure).
 * All offsets INFERRED from x64 PC pseudocode; not runtime-confirmed.
 *
 * Object size: 0x2550 (9552 bytes). Derived from highest proven field end
 * (callbackHandle at 0x2548 + 8 = 0x2550). True allocation size not yet found.
 *
 * Storm 4 has no Trilogy namespace; names from s4 symbols/strings only.
 */

/* Placeholder types sized to match game memory exactly. */
typedef struct { float x, y; } Vector2;
typedef struct { float x, y, z; } Vector3;
typedef struct { float x, y, z, w; } Vector4;

/* All sub-object placeholders are opaque byte arrays of proven size. */
typedef struct { uint8_t data[0x180]; } ccLightManager_s4;
typedef struct { uint8_t data[0x04]; } nuccCelshadeParam;
typedef struct { uint8_t data[0x30]; } nuccFogParam;
typedef struct { uint8_t data[0x200]; } LightDirBlock_s4;
typedef struct { uint8_t data[0x60]; } Vector2Pair_s4;
typedef struct { uint8_t data[0x20]; } FloatStructEntry_s4;
typedef struct { uint8_t data[0x10]; } SubVtableEntry_s4;
typedef struct { uint8_t data[0x40]; } DrawEnvLargeEntry_s4;
typedef struct { uint8_t data[0x18]; } BlockAllocator_s4;
typedef struct { uint8_t data[0x170]; } ccStageLightParam_s4;
typedef struct { uint8_t data[0x10]; } DrawEnvSubObj_s4;
typedef struct { uint8_t data[0x18]; } InitStruct_s4;
typedef struct { uint8_t data[0x18]; } DivideScreenParam;
typedef struct { uint8_t data[0x5C]; } nuccCriticalSection_s4;

#pragma pack(push, 1)
typedef struct ccGameDrawEnv {
    /* 0x0000 */ void* vtablePtr; /* ctor: vtable */
    /* 0x0008 */ uint8_t pad_0008[0x18];
    /* 0x0020 */ ccLightManager_s4 lightManager; /* ctor: ccLightManager(param_1+4) */
    /* 0x01A0 */ float float_1A0; /* ctor: =1.0f */
    /* 0x01A4 */ uint32_t field_1A4; /* Init: =0 */
    /* 0x01A8 */ uint8_t pad_01A8[0xC];
    /* 0x01B4 */ Vector3 vec3_1B4; /* ctor: Vector3(param_1+0x1b4) */
    /* 0x01C0 */ uint8_t pad_01C0[0x10];
    /* 0x01D0 */ nuccCelshadeParam celshadeParams[6]; /* ctor: param_1+0x3a, stride 0x04, count 6 */
    /* 0x01E8 */ uint8_t pad_01E8[0x18];
    /* 0x0200 */ nuccFogParam fogParamArray[6]; /* ctor: param_1+0x40, stride 0x30, count 6 */
    /* 0x0320 */ uint8_t pad_0320[0x20];
    /* 0x0340 */ nuccFogParam fogParam; /* ctor: nuccFogParam(param_1+0x68) */
    /* 0x0370 */ uint8_t pad_0370[0x10];
    /* 0x0380 */ LightDirBlock_s4 lightDirBlock; /* ctor: Vector4 at byte 0x380 */
    /* 0x0580 */ uint8_t pad_0580[0x20];
    /* 0x05A0 */ uint8_t memset_5A0[0x60]; /* ctor: memset(0xb4,0,0x60) */
    /* 0x0600 */ uint8_t memset_600[0x30]; /* ctor: memset(0xc0,0,0x30) */
    /* 0x0630 */ uint8_t memset_630[0x90]; /* ctor: memset(0xc6,0,0x90) */
    /* 0x06C0 */ uint64_t field_6C0; /* ctor: param_1[0xd8]=0 */
    /* 0x06C8 */ uint64_t field_6C8; /* ctor: param_1[0xd9]=0 */
    /* 0x06D0 */ uint64_t field_6D0; /* ctor: param_1[0xda]=0 */
    /* 0x06D8 */ uint8_t memset_6D8[0xA8]; /* ctor: memset(0xdb,0,0xa8) */
    /* 0x0780 */ uint8_t memset_780[0x78]; /* ctor: memset(0xf0,0,0x78) */
    /* 0x07F8 */ uint8_t pad_07F8[0x48];
    /* 0x0840 */ Vector2Pair_s4 vec2Pairs[12]; /* ctor: param_1+0x108, stride 0x60, count 12 */
    /* 0x0CC0 */ uint8_t vec2Array[0x3C0]; /* 12 entries, each 0x50 bytes */
    /* 0x1080 */ uint8_t pad_1080[0x2D0];
    /* 0x1350 */ uint8_t vec3Array[0x300]; /* 12 entries, each 0x40 bytes */
    /* 0x1650 */ FloatStructEntry_s4 floatStructs[6]; /* ctor: param_1+0x2ca, stride 0x20, count 6 */
    /* 0x1710 */ uint64_t zeroArray[6]; /* ctor: param_1+0x2e2, count 6 */
    /* 0x1740 */ uint8_t pad_1740[0x290];
    /* 0x19D0 */ uint8_t memset_19D0[0x138]; /* ctor: memset(0x33a,0,0x138) */
    /* 0x1B08 */ uint8_t memset_1B08[0x90]; /* ctor: memset(0x361,0,0x90) */
    /* 0x1B98 */ uint8_t memset_1B98[0x78]; /* ctor: memset(0x373,0,0x78) */
    /* 0x1C10 */ uint8_t pad_1C10[0x3A8];
    /* 0x1FB8 */ SubVtableEntry_s4 subVtables[6]; /* ctor: param_1+0x3f7, stride 0x10, count 6 */
    /* 0x2018 */ uint8_t pad_2018[0x8];
    /* 0x2020 */ DrawEnvLargeEntry_s4 largeEntries[6]; /* ctor: param_1+0x404, stride 0x40, count 6 */
    /* 0x21A0 */ BlockAllocator_s4 blockAlloc_A; /* ctor: BlockAllocator(param_1+0x434) */
    /* 0x21B8 */ uint64_t field_21B8; /* ctor: param_1[0x437]=0 */
    /* 0x21C0 */ uint64_t field_21C0; /* ctor: param_1[0x438]=0 */
    /* 0x21C8 */ uint64_t field_21C8; /* ctor: param_1[0x439]=0 */
    /* 0x21D0 */ uint16_t field_21D0; /* ctor: *(u16*)(param_1+0x43a)=0 */
    /* 0x21D2 */ uint8_t pad_21D2[0x6];
    /* 0x21D8 */ BlockAllocator_s4 blockAlloc_B; /* ctor: BlockAllocator(param_1+0x43b) */
    /* 0x21F0 */ uint64_t field_21F0; /* ctor: param_1[0x43e]=0 */
    /* 0x21F8 */ uint64_t field_21F8; /* ctor: param_1[0x43f]=0 */
    /* 0x2200 */ uint64_t field_2200; /* ctor: param_1[0x440]=0 */
    /* 0x2208 */ uint16_t field_2208; /* ctor: *(u16*)(param_1+0x441)=0 */
    /* 0x220A */ uint8_t pad_220A[0x6];
    /* 0x2210 */ ccStageLightParam_s4 stageLightParam; /* ctor: ccStageLightParam(param_1+0x442) */
    /* 0x2380 */ uint8_t memset_2380[0x60]; /* ctor: memset(0x470,0,0x48) */
    /* 0x23E0 */ DrawEnvSubObj_s4 subObjs[6]; /* ctor: FUN_140a51470 x6 at param_1+0x47c */
    /* 0x2440 */ void* screenManagerPtr; /* Init/Exit: param_1[0x488] */
    /* 0x2448 */ InitStruct_s4 initStructs[5]; /* ctor: param_1+0x489, stride 0x18, count 5 */
    /* 0x24C0 */ DivideScreenParam divideScrParam; /* Init: param_1+0x498 */
    /* 0x24D8 */ nuccCriticalSection_s4 critSection; /* ctor: nuccCriticalSection(param_1+0x49b) */
    /* 0x2534 */ Vector4 vec4_2534; /* ctor: Vector4_MathGeo at byte 0x2534 */
    /* 0x2544 */ uint8_t pad_2544[0x4];
    /* 0x2548 */ uint64_t callbackHandle; /* ctor/Exit: param_1[0x4a9] */
} ccGameDrawEnv;
#pragma pack(pop)

_Static_assert(sizeof(ccGameDrawEnv) == 0x2550, "ccGameDrawEnv size");
_Static_assert(offsetof(ccGameDrawEnv, vtablePtr) == 0x0000, "vtablePtr");
_Static_assert(offsetof(ccGameDrawEnv, lightManager) == 0x0020, "lightManager");
_Static_assert(offsetof(ccGameDrawEnv, float_1A0) == 0x01A0, "float_1A0");
_Static_assert(offsetof(ccGameDrawEnv, field_1A4) == 0x01A4, "field_1A4");
_Static_assert(offsetof(ccGameDrawEnv, vec3_1B4) == 0x01B4, "vec3_1B4");
_Static_assert(offsetof(ccGameDrawEnv, celshadeParams) == 0x01D0, "celshadeParams");
_Static_assert(offsetof(ccGameDrawEnv, fogParamArray) == 0x0200, "fogParamArray");
_Static_assert(offsetof(ccGameDrawEnv, fogParam) == 0x0340, "fogParam");
_Static_assert(offsetof(ccGameDrawEnv, lightDirBlock) == 0x0380, "lightDirBlock");
_Static_assert(offsetof(ccGameDrawEnv, memset_5A0) == 0x05A0, "memset_5A0");
_Static_assert(offsetof(ccGameDrawEnv, memset_600) == 0x0600, "memset_600");
_Static_assert(offsetof(ccGameDrawEnv, memset_630) == 0x0630, "memset_630");
_Static_assert(offsetof(ccGameDrawEnv, field_6C0) == 0x06C0, "field_6C0");
_Static_assert(offsetof(ccGameDrawEnv, field_6C8) == 0x06C8, "field_6C8");
_Static_assert(offsetof(ccGameDrawEnv, field_6D0) == 0x06D0, "field_6D0");
_Static_assert(offsetof(ccGameDrawEnv, memset_6D8) == 0x06D8, "memset_6D8");
_Static_assert(offsetof(ccGameDrawEnv, memset_780) == 0x0780, "memset_780");
_Static_assert(offsetof(ccGameDrawEnv, vec2Pairs) == 0x0840, "vec2Pairs");
_Static_assert(offsetof(ccGameDrawEnv, vec2Array) == 0x0CC0, "vec2Array");
_Static_assert(offsetof(ccGameDrawEnv, vec3Array) == 0x1350, "vec3Array");
_Static_assert(offsetof(ccGameDrawEnv, floatStructs) == 0x1650, "floatStructs");
_Static_assert(offsetof(ccGameDrawEnv, zeroArray) == 0x1710, "zeroArray");
_Static_assert(offsetof(ccGameDrawEnv, memset_19D0) == 0x19D0, "memset_19D0");
_Static_assert(offsetof(ccGameDrawEnv, memset_1B08) == 0x1B08, "memset_1B08");
_Static_assert(offsetof(ccGameDrawEnv, memset_1B98) == 0x1B98, "memset_1B98");
_Static_assert(offsetof(ccGameDrawEnv, subVtables) == 0x1FB8, "subVtables");
_Static_assert(offsetof(ccGameDrawEnv, largeEntries) == 0x2020, "largeEntries");
_Static_assert(offsetof(ccGameDrawEnv, blockAlloc_A) == 0x21A0, "blockAlloc_A");
_Static_assert(offsetof(ccGameDrawEnv, field_21B8) == 0x21B8, "field_21B8");
_Static_assert(offsetof(ccGameDrawEnv, field_21C0) == 0x21C0, "field_21C0");
_Static_assert(offsetof(ccGameDrawEnv, field_21C8) == 0x21C8, "field_21C8");
_Static_assert(offsetof(ccGameDrawEnv, field_21D0) == 0x21D0, "field_21D0");
_Static_assert(offsetof(ccGameDrawEnv, blockAlloc_B) == 0x21D8, "blockAlloc_B");
_Static_assert(offsetof(ccGameDrawEnv, field_21F0) == 0x21F0, "field_21F0");
_Static_assert(offsetof(ccGameDrawEnv, field_21F8) == 0x21F8, "field_21F8");
_Static_assert(offsetof(ccGameDrawEnv, field_2200) == 0x2200, "field_2200");
_Static_assert(offsetof(ccGameDrawEnv, field_2208) == 0x2208, "field_2208");
_Static_assert(offsetof(ccGameDrawEnv, stageLightParam) == 0x2210, "stageLightParam");
_Static_assert(offsetof(ccGameDrawEnv, memset_2380) == 0x2380, "memset_2380");
_Static_assert(offsetof(ccGameDrawEnv, subObjs) == 0x23E0, "subObjs");
_Static_assert(offsetof(ccGameDrawEnv, screenManagerPtr) == 0x2440, "screenManagerPtr");
_Static_assert(offsetof(ccGameDrawEnv, initStructs) == 0x2448, "initStructs");
_Static_assert(offsetof(ccGameDrawEnv, divideScrParam) == 0x24C0, "divideScrParam");
_Static_assert(offsetof(ccGameDrawEnv, critSection) == 0x24D8, "critSection");
_Static_assert(offsetof(ccGameDrawEnv, vec4_2534) == 0x2534, "vec4_2534");
_Static_assert(offsetof(ccGameDrawEnv, callbackHandle) == 0x2548, "callbackHandle");

#endif /* CCGAMEDRAWENV_S4_H */
