/* cmn81.h — struct group cmn81 for build s4 (NSUNS4_release.exe, PC 1.09)
 * INFERRED from static analysis only. Not CONFIRMED by runtime trace.
 * Generated 2026-10-19.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * SphereTriangleDetector — Bullet Physics sphere-triangle collision detector
 * Size: 0x28 (40 bytes), proven by stack allocation local_100[40] in
 *   btSphereTriangleCollisionAlgorithm::processCollision (RVA 0xDEA8C0).
 * Vtable: present at offset 0x00, set in ctor RVA 0xDF6D50; address not
 *   indexed as a symbol in the decompiler cache DB.
 * Methods (4): ctor (0xDF6D50), collide (0xDF6ED0),
 *   getClosestPoints (0xDF7320), pointInTriangle (0xDF7940).
 * Layout matches s3 exactly (same offsets, same size proof pattern).
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
 * spirv_cross::Compiler — 3 methods in s4 but NO size proof found.
 * Only field evidence: set_enabled_interface_variables accesses param_1+0x10
 *   (passed to bul::CDevice::FreeBuffer) and writes byte at param_1+0x54.
 * Without operator new / allocator size / array stride, layout cannot be
 * reconstructed per brief rules. Listed here for completeness.
 * Methods: compile (0xADCAB0), get_remapped_declared_block_name (0xA2E200),
 *          set_enabled_interface_variables (0x9333F0).
 *
 * Classes with < 3 methods in s4 — no layout reconstructed per brief rules.
 * See cmn81-REPORT.md for details.
 *
 * pead                          — 4 methods (BinaryStreamFormat::writeMemBlock @ 0x8ED410,
 *                                            HeapMgr::getCurrentHeap @ 0x51F304,
 *                                            allocateFromSeadHeap @ 0x4DFE88,
 *                                            allocateFromSeadHeap @ 0xAEBCA0)
 * pugi::xml_document            — 2 methods (destroy @ 0x1C4140,
 *                                            xml_document ctor @ 0xD4BCC0)
 * pugi::xml_node                — 1 method  (xml_node ctor @ 0x1C4040)
 * revmodel                      — 1 method  (hipass @ 0xE8CAF0)
 * SupportVertexCallback         — 1 method  (processTriangle @ 0x9CB240)
 * UnDecorator                   — 2 methods (getScope @ 0xB36BF0,
 *                                            getTemplateConstant @ 0xC442B0)
 * VmaBlockMetadata_Linear       — 1 method  (GetAllocationUserData @ 0xB0BA60)
 */