/* cmn81.h — struct group cmn81 for build s1 (NSUNS1.exe)
 * INFERRED from static analysis only. Not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * SphereTriangleDetector — Bullet Physics sphere-triangle collision detector
 * Size: 0x28 (40 bytes), proven by stack allocation local_100[40] in
 *   btSphereTriangleCollisionAlgorithm::processCollision (RVA 0x5B2A60).
 * Vtable: present at offset 0x00 (set in ctor RVA 0x5C2FF0), address not
 *   indexed as a symbol in the decompiler cache DB.
 * Methods (4): ctor (0x5C2FF0), collide (0x5C31A0),
 *   getClosestPoints (0x5C35F0), pointInTriangle (0x5C3C10).
 */
typedef struct __attribute__((packed)) SphereTriangleDetector {
    uint64_t vftable;           /* 0x00: vtable pointer, set in ctor */
    uint64_t sphere_shape;      /* 0x08: ptr to sphere shape object (has floats at +0x20,+0x30) */
    uint64_t triangle_mesh;     /* 0x10: ptr to triangle mesh data (plVar1 in collide) */
    uint32_t collision_flags;   /* 0x18: flags passed as param_4 to ctor, read in getClosestPoints */
    uint8_t  _pad_1c[4];        /* 0x1C: padding to reach proven size 0x28 */
    uint8_t  _unknown_20[8];    /* 0x20: unproven tail bytes within 0x28 allocation */
} SphereTriangleDetector;

static_assert(offsetof(SphereTriangleDetector, vftable)          == 0x00, "SphereTriangleDetector.vftable");
static_assert(offsetof(SphereTriangleDetector, sphere_shape)     == 0x08, "SphereTriangleDetector.sphere_shape");
static_assert(offsetof(SphereTriangleDetector, triangle_mesh)    == 0x10, "SphereTriangleDetector.triangle_mesh");
static_assert(offsetof(SphereTriangleDetector, collision_flags)  == 0x18, "SphereTriangleDetector.collision_flags");
static_assert(offsetof(SphereTriangleDetector, _pad_1c)          == 0x1C, "SphereTriangleDetector._pad_1c");
static_assert(offsetof(SphereTriangleDetector, _unknown_20)      == 0x20, "SphereTriangleDetector._unknown_20");
static_assert(sizeof(SphereTriangleDetector)                     == 0x28, "SphereTriangleDetector size");

/*
 * Classes with < 3 methods in s1 — no layout reconstructed per brief rules.
 * Listed here for completeness; see cmn81-REPORT.md for details.
 *
 * pead                          — 1 method  (allocateFromSeadHeap @ 0x562B90)
 * pugi::xml_document            — 1 method  (destroy @ 0x14BBD0)
 * pugi::xml_node                — 1 method  (xml_node ctor @ 0x14BAD0)
 * revmodel                      — 1 method  (hipass @ 0x63A700)
 * spirv_cross::Compiler         — 2 methods (compile @ 0x568DA0,
 *                                            get_remapped_declared_block_name @ 0x48D9A0)
 * SupportVertexCallback         — 1 method  (processTriangle @ 0x5F8A40)
 * UnDecorator                   — 1 method  (getScope @ 0x59C6D0)
 * VmaBlockMetadata_Linear       — 1 method  (GetAllocationUserData @ 0x571940)
 */