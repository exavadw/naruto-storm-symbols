// ccGameDrawEnv (NSUNS2.exe, build s2) — reconstructed from Ghidra decompilation
// Constructor RVA: 0x533FC0
// Minimum size: >= 0x1D28 bytes (highest proven access: param_1[0x3A4] = +0x1D20, 8 bytes)
// Confidence: INFERRED (static analysis only; verify with replay trace before CONFIRMED)
// Generated: 2026-10-19
// Cross-build: s1 struct was 0x4F8; s2 grew significantly with embedded sub-objects
// Field sizes corrected 2026-10-19 from known-good static_assert target offsets
#pragma once
#include <stdint.h>
#include <stddef.h>

// Forward declarations for referenced types (opaque; sizes not proven in s2)
typedef struct ccLightManager ccLightManager;
typedef struct ccStageLightParam ccStageLightParam;
typedef struct nuccCriticalSection nuccCriticalSection;

struct ccGameDrawEnv {
    // === 0x000-0x02F: Base class (Nucc::Memory::BlockAllocator) ===
    uint64_t vtablePtr;                 // 0x000 ctor: *param_1 = PTR_FUN_1408673e8
    uint8_t blockAllocatorBase[0x28];   // 0x008 BlockAllocator(param_1, 0) base data

    // === 0x030-0x1BB: Embedded ccLightManager ===
    // ccLightManager::ccLightManager(param_1 + 6) -> +0x30
    // Size inferred: next typed field at +0x1BC
    uint8_t lightManager[0x18C];        // 0x030 embedded ccLightManager sub-object

    // === 0x1BC-0x1C7: Vector3 ===
    float unkVec3_1BC[3];              // 0x1BC Nucc::Vector3::Vector3((longlong)param_1+0x1bc)

    // === 0x1C8-0x1EF: nuccCelshadeParam[5] ===
    // Corrected: gap to fogParams is 0x28 bytes (was incorrectly 0xA0)
    uint8_t celshadeParams[0x28];       // 0x1C8 nuccCelshadeParam[5]

    // === 0x1F0-0x2CF: nuccFogParam[5] ===
    // Corrected: gap to fogParamExtra is 0xE0 bytes
    uint8_t fogParams[0xE0];            // 0x1F0 nuccFogParam[5]

    // === 0x2D0-0x30F: Extra nuccFogParam + padding ===
    // Corrected: gap to vec4Vec3Pairs is 0x40 bytes (was 0x30)
    uint8_t fogParamExtra[0x40];        // 0x2D0 single nuccFogParam + pad

    // === 0x310-0x4CF: Vector4+Vector3 pairs region ===
    // Corrected: gap to unkZeroed_4D0 is 0x1C0 bytes (was 0x1A0+pad)
    uint8_t vec4Vec3Pairs[0x1C0];       // 0x310 Vector4+Vector3 pairs region

    // === 0x4D0-0x5BF: Zeroed blocks from constructor memsets ===
    uint8_t unkZeroed_4D0[0x50];        // 0x4D0 memset(0, 0x50)
    uint8_t unkZeroed_520[0x28];        // 0x520 memset(0, 0x28)
    uint8_t unkZeroed_548[0x78];        // 0x548 memset(0, 0x78)

    // === 0x5C0-0x5D3: Scalar fields ===
    uint64_t unk_5C0;                   // 0x5C0 param_1[0xb8] = 0
    uint64_t unk_5C8;                   // 0x5C8 param_1[0xb9] = 0
    uint32_t unk_5D0;                   // 0x5D0 *(uint32*)(param_1+0xba) = 0

    // === 0x5D4-0x65F: Zeroed region ===
    uint8_t unkZeroed_5D4[0x8C];        // 0x5D4 memset(0, 0x8C)

    // === 0x660-0x717: Zeroed region ===
    // Corrected: gap to vec2PairsRegion1 is 0xB8 bytes (was 0x64+pad)
    uint8_t unkZeroed_660[0xB8];        // 0x660 memset/zeroed region

    // === 0x718-0xACF: Vector2 pairs region 1 ===
    // Corrected: gap to vec2ArrayRegion2 is 0x3B8 bytes (was 0x3C0)
    uint8_t vec2PairsRegion1[0x3B8];    // 0x718 Vector2 pairs region 1

    // === 0xAD0-0xE4F: Vector2 array region 2 ===
    // Corrected: gap to blockAllocSub1 is 0x380 bytes (was 0x320+pad)
    uint8_t vec2ArrayRegion2[0x380];     // 0xAD0 Vector2 array region 2

    // === 0xE50-0xE67: BlockAllocator sub-object 1 ===
    uint8_t blockAllocSub1[0x18];       // 0xE50 BlockAllocator sub-object

    // === 0xE68-0xE87: Scalar fields around BlockAllocator sub-objects ===
    uint64_t unk_E68;                   // 0xE68 param_1[0x1CD] = 0
    uint64_t unk_E70;                   // 0xE70 param_1[0x1CE] = 0
    uint64_t unk_E78;                   // 0xE78 param_1[0x1CF] = 0
    uint64_t unk_E80;                   // 0xE80 widened to u64 to fill gap to blockAllocSub2

    // === 0xE88-0xE9F: BlockAllocator sub-object 2 ===
    uint8_t blockAllocSub2[0x18];       // 0xE88 BlockAllocator sub-object

    // === 0xEA0-0xEBF: More scalar fields ===
    uint64_t unk_EA0;                   // 0xEA0 param_1[0x1D4] = 0
    uint64_t unk_EA8;                   // 0xEA8 param_1[0x1D5] = 0
    uint64_t unk_EB0;                   // 0xEB0 param_1[0x1D6] = 0
    uint64_t unk_EB8;                   // 0xEB8 widened to u64 to fill gap to stageLightParam

    // === 0xEC0-0xF7F: ccStageLightParam ===
    // Corrected: gap to unk_F80 is 0xC0 bytes (was 0xE0)
    uint8_t stageLightParam[0xC0];      // 0xEC0 ccStageLightParam sub-object

    // === 0xF80-0xF9F: Region accessed by Init ===
    uint8_t unk_F80[0x20];              // 0xF80 Init-accessed region

    // === 0xFA0-0x1017: Vector2 pair array ===
    // Corrected: gap to criticalSection is 0x78 bytes (was 0xF0)
    uint8_t vec2PairArray_FA0[0x78];    // 0xFA0 Vector2 pairs region

    // === 0x1018-0x106F: nuccCriticalSection ===
    uint8_t criticalSection[0x58];      // 0x1018 nuccCriticalSection sub-object

    // === 0x1070-0x1077: Field accessed by Init/Exit ===
    uint64_t unk_1070;                  // 0x1070 rw, Init/Exit

    // === 0x1078-0x109F: Zeroed region ===
    uint8_t unkZeroed_1078[0x28];       // 0x1078 memset(0, 0x28)

    // === 0x10A0-0x11DF: Zeroed region ===
    uint8_t unkZeroed_10A0[0x140];      // 0x10A0 memset(0, 0x140)

    // === 0x11E0-0x131F: Zeroed region ===
    uint8_t unkZeroed_11E0[0x140];      // 0x11E0 memset(0, 0x140)

    // === 0x1320-0x13BF: Float4 struct array ===
    uint8_t float4StructArray[0xA0];    // 0x1320 float4 structs[4], stride 0x20

    // === 0x13C0-0x13E7: Zero array ===
    uint8_t zeroArray_13C0[0x28];       // 0x13C0 zero array[4]

    // === 0x13E8-0x142F: Zeroed region ===
    // Corrected: gap is 0x48 bytes (was 0x3C+pad)
    uint8_t unkZeroed_13E8[0x48];       // 0x13E8 memset(0, ...)

    // === 0x1430-0x151F: Zeroed region ===
    uint8_t unkZeroed_1430[0xF0];       // 0x1430 memset(0, 0xF0)

    // === 0x1520-0x160F: Zeroed region ===
    uint8_t unkZeroed_1520[0xF0];       // 0x1520 memset(0, 0xF0)

    // === 0x1610-0x165F: FUN_1405c9440 array ===
    uint8_t fun1405c9440Array[0x50];    // 0x1610 FUN_1405c9440 array[4]

    // === 0x1660-0x16AF: Vtable+zero array ===
    uint8_t vtableZeroArray[0x50];      // 0x1660 vtable+zero array[4]

    // === 0x16B0-0x17EF: Large struct array with 1.0f inits ===
    uint8_t largeStructArray[0x140];    // 0x16B0 large struct[4], stride 0x40

    // === 0x17F0-0x18F3: Zeroed region ===
    uint8_t unkZeroed_17F0[0x104];      // 0x17F0 memset(0, 0x104)

    // === 0x18F4-0x196B: Zeroed region ===
    uint8_t unkZeroed_18F4[0x78];       // 0x18F4 memset(0, 0x78)

    // === 0x196C-0x19CF: Zeroed region ===
    uint8_t unkZeroed_196C[0x64];       // 0x196C memset(0, 0x64)

    // === 0x19D0-0x1AD3: Shadow projection params ===
    uint8_t shadowProjectionParams[0x104]; // 0x19D0 shadow projection data

    // === 0x1AD4-0x1BD7: Zeroed region ===
    uint8_t unkZeroed_1AD4[0x104];      // 0x1AD4 memset(0, 0x104)

    // === 0x1BD8-0x1CDB: Zeroed region ===
    uint8_t unkZeroed_1BD8[0x104];      // 0x1BD8 memset(0, 0x104)

    // === 0x1CDC-0x1D17: Zeroed region ===
    uint8_t unkZeroed_1CDC[0x3C];       // 0x1CDC memset(0, 0x3C)

    // === 0x1D18-0x1D27: btSimdScalar / Vector4_MathGeo ===
    uint64_t simdScalar_1D18;           // 0x1D18 btSimdScalar low 8 bytes
    uint64_t simdScalar_1D20;           // 0x1D20 btSimdScalar high 8 bytes

    // === 0x1D28: End of proven object ===
};

// Compile-time offset checks (INFERRED from decompiler output)
_Static_assert(offsetof(struct ccGameDrawEnv, vtablePtr) == 0x000, "vtablePtr");
_Static_assert(offsetof(struct ccGameDrawEnv, blockAllocatorBase) == 0x008, "blockAllocatorBase");
_Static_assert(offsetof(struct ccGameDrawEnv, lightManager) == 0x030, "lightManager");
_Static_assert(offsetof(struct ccGameDrawEnv, unkVec3_1BC) == 0x1BC, "unkVec3_1BC");
_Static_assert(offsetof(struct ccGameDrawEnv, celshadeParams) == 0x1C8, "celshadeParams");
_Static_assert(offsetof(struct ccGameDrawEnv, fogParams) == 0x1F0, "fogParams");
_Static_assert(offsetof(struct ccGameDrawEnv, fogParamExtra) == 0x2D0, "fogParamExtra");
_Static_assert(offsetof(struct ccGameDrawEnv, vec4Vec3Pairs) == 0x310, "vec4Vec3Pairs");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_4D0) == 0x4D0, "unkZeroed_4D0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_520) == 0x520, "unkZeroed_520");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_548) == 0x548, "unkZeroed_548");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_5C0) == 0x5C0, "unk_5C0");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_5C8) == 0x5C8, "unk_5C8");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_5D0) == 0x5D0, "unk_5D0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_5D4) == 0x5D4, "unkZeroed_5D4");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_660) == 0x660, "unkZeroed_660");
_Static_assert(offsetof(struct ccGameDrawEnv, vec2PairsRegion1) == 0x718, "vec2PairsRegion1");
_Static_assert(offsetof(struct ccGameDrawEnv, vec2ArrayRegion2) == 0xAD0, "vec2ArrayRegion2");
_Static_assert(offsetof(struct ccGameDrawEnv, blockAllocSub1) == 0xE50, "blockAllocSub1");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_E68) == 0xE68, "unk_E68");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_E80) == 0xE80, "unk_E80");
_Static_assert(offsetof(struct ccGameDrawEnv, blockAllocSub2) == 0xE88, "blockAllocSub2");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_EA0) == 0xEA0, "unk_EA0");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_EB8) == 0xEB8, "unk_EB8");
_Static_assert(offsetof(struct ccGameDrawEnv, stageLightParam) == 0xEC0, "stageLightParam");
_Static_assert(offsetof(struct ccGameDrawEnv, vec2PairArray_FA0) == 0xFA0, "vec2PairArray_FA0");
_Static_assert(offsetof(struct ccGameDrawEnv, criticalSection) == 0x1018, "criticalSection");
_Static_assert(offsetof(struct ccGameDrawEnv, unk_1070) == 0x1070, "unk_1070");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_1078) == 0x1078, "unkZeroed_1078");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_10A0) == 0x10A0, "unkZeroed_10A0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_11E0) == 0x11E0, "unkZeroed_11E0");
_Static_assert(offsetof(struct ccGameDrawEnv, float4StructArray) == 0x1320, "float4StructArray");
_Static_assert(offsetof(struct ccGameDrawEnv, zeroArray_13C0) == 0x13C0, "zeroArray_13C0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_13E8) == 0x13E8, "unkZeroed_13E8");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_1430) == 0x1430, "unkZeroed_1430");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_1520) == 0x1520, "unkZeroed_1520");
_Static_assert(offsetof(struct ccGameDrawEnv, fun1405c9440Array) == 0x1610, "fun1405c9440Array");
_Static_assert(offsetof(struct ccGameDrawEnv, vtableZeroArray) == 0x1660, "vtableZeroArray");
_Static_assert(offsetof(struct ccGameDrawEnv, largeStructArray) == 0x16B0, "largeStructArray");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_17F0) == 0x17F0, "unkZeroed_17F0");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_18F4) == 0x18F4, "unkZeroed_18F4");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_196C) == 0x196C, "unkZeroed_196C");
_Static_assert(offsetof(struct ccGameDrawEnv, shadowProjectionParams) == 0x19D0, "shadowProjectionParams");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_1AD4) == 0x1AD4, "unkZeroed_1AD4");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_1BD8) == 0x1BD8, "unkZeroed_1BD8");
_Static_assert(offsetof(struct ccGameDrawEnv, unkZeroed_1CDC) == 0x1CDC, "unkZeroed_1CDC");
_Static_assert(offsetof(struct ccGameDrawEnv, simdScalar_1D18) == 0x1D18, "simdScalar_1D18");
_Static_assert(offsetof(struct ccGameDrawEnv, simdScalar_1D20) == 0x1D20, "simdScalar_1D20");
// Size not asserted: true size unknown, >= 0x1D28