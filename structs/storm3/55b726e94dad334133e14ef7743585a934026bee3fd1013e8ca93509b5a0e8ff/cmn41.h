/* cmn41.h - Nucc::Vector4_MathGeo, nuccAABBCulling (AABB), nuccAmbient, nuccAnm::ApplyClumpData
 * Build: s3 (NSUNS3.exe, PC x64, sha 55b726e94dad)
 * All layouts INFERRED from static decompilation of s3 binary.
 * Sizes proven from game code where noted; otherwise size unknown, >= 0xNN.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ========================================================================
 * Nucc::Vector4_MathGeo - 4-component float vector (MathGeoLib-style)
 * Size: 0x10 (proven: copy ctor at 0x69FE00 copies 4 x uint32;
 * Cross3 at 0x6A24F0 writes w=1.0f at +0xC)
 * Vtable: none (value type)
 * ======================================================================== */
typedef struct __attribute__((packed)) Nucc_Vector4_MathGeo {
    float x; /* 0x00 */
    float y; /* 0x04 */
    float z; /* 0x08 */
    float w; /* 0x0C */
} Nucc_Vector4_MathGeo;

static_assert(sizeof(Nucc_Vector4_MathGeo) == 0x10, "Nucc_Vector4_MathGeo size");
static_assert(offsetof(Nucc_Vector4_MathGeo, x) == 0x00, "Nucc_Vector4_MathGeo.x");
static_assert(offsetof(Nucc_Vector4_MathGeo, y) == 0x04, "Nucc_Vector4_MathGeo.y");
static_assert(offsetof(Nucc_Vector4_MathGeo, z) == 0x08, "Nucc_Vector4_MathGeo.z");
static_assert(offsetof(Nucc_Vector4_MathGeo, w) == 0x0C, "Nucc_Vector4_MathGeo.w");

/* ========================================================================
 * nuccAABBCulling::AABB - axis-aligned bounding box (min/max Vector3 pair)
 * Size: 0x18 (proven: IsInFrustum at 0x6A9D00 reads param_1+0x00 and
 * param_1+0x0C as two Vector3s, loop i=0..2)
 * Vtable: none (plain struct)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAABBCulling_AABB {
    float min_x; /* 0x00 */
    float min_y; /* 0x04 */
    float min_z; /* 0x08 */
    float max_x; /* 0x0C */
    float max_y; /* 0x10 */
    float max_z; /* 0x14 */
} nuccAABBCulling_AABB;

static_assert(sizeof(nuccAABBCulling_AABB) == 0x18, "nuccAABBCulling_AABB size");
static_assert(offsetof(nuccAABBCulling_AABB, min_x) == 0x00, "nuccAABBCulling_AABB.min_x");
static_assert(offsetof(nuccAABBCulling_AABB, min_y) == 0x04, "nuccAABBCulling_AABB.min_y");
static_assert(offsetof(nuccAABBCulling_AABB, min_z) == 0x08, "nuccAABBCulling_AABB.min_z");
static_assert(offsetof(nuccAABBCulling_AABB, max_x) == 0x0C, "nuccAABBCulling_AABB.max_x");
static_assert(offsetof(nuccAABBCulling_AABB, max_y) == 0x10, "nuccAABBCulling_AABB.max_y");
static_assert(offsetof(nuccAABBCulling_AABB, max_z) == 0x14, "nuccAABBCulling_AABB.max_z");

/* ========================================================================
 * nuccAmbient - ambient light chunk (inherits nuccLight base via nuccRequest)
 * Size: 0x88 (proven: ctor at 0x275ADC calls base FUN_140381abc(param_1, 0x88))
 * Vtable: at offset 0x00
 * ctor1 (0x275ADC): PTR_FUN_140930658
 * ctor2 (0x6D2520): PTR_FUN_1409e3270 (via base FUN_1406d93f0)
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAmbient {
    void *vtable;           /* 0x00 */
    uint32_t base_type;     /* 0x08 - written by base ctor param_2 */
    uint32_t pad_0C;        /* 0x0C - 1.0f (0x3f800000) */
    uint64_t base_field_10; /* 0x10 - zeroed */
    uint64_t base_field_18; /* 0x18 - copied from src+0x08 in ctor2 */
    uint64_t base_field_20; /* 0x20 - zeroed */
    uint64_t base_field_28; /* 0x28 - zeroed */
    uint64_t base_field_30; /* 0x30 - zeroed */
    uint64_t base_field_38; /* 0x38 - zeroed */
    uint64_t ambient_param_0; /* 0x40 - copied from src+0x10 in ctor2 */
    uint64_t ambient_param_1; /* 0x48 - copied from src+0x18 in ctor2 */
    uint64_t base_field_50; /* 0x50 - 1.0f pair init then overwritten */
    uint64_t base_field_58; /* 0x58 - 1.0f pair init then overwritten */
    uint32_t _unknown_60;   /* 0x60 */
    uint32_t base_int_64;   /* 0x64 - set to -1 */
    uint64_t _gap_68;       /* 0x68 */
    uint64_t _gap_70;       /* 0x70 */
    uint64_t _gap_78;       /* 0x78 */
    uint64_t _gap_80;       /* 0x80 */
} nuccAmbient;

static_assert(sizeof(nuccAmbient) == 0x88, "nuccAmbient size");
static_assert(offsetof(nuccAmbient, vtable) == 0x00, "nuccAmbient.vtable");
static_assert(offsetof(nuccAmbient, base_type) == 0x08, "nuccAmbient.base_type");
static_assert(offsetof(nuccAmbient, pad_0C) == 0x0C, "nuccAmbient.pad_0C");
static_assert(offsetof(nuccAmbient, base_field_10) == 0x10, "nuccAmbient.base_field_10");
static_assert(offsetof(nuccAmbient, base_field_18) == 0x18, "nuccAmbient.base_field_18");
static_assert(offsetof(nuccAmbient, base_field_20) == 0x20, "nuccAmbient.base_field_20");
static_assert(offsetof(nuccAmbient, base_field_28) == 0x28, "nuccAmbient.base_field_28");
static_assert(offsetof(nuccAmbient, base_field_30) == 0x30, "nuccAmbient.base_field_30");
static_assert(offsetof(nuccAmbient, base_field_38) == 0x38, "nuccAmbient.base_field_38");
static_assert(offsetof(nuccAmbient, ambient_param_0) == 0x40, "nuccAmbient.ambient_param_0");
static_assert(offsetof(nuccAmbient, ambient_param_1) == 0x48, "nuccAmbient.ambient_param_1");
static_assert(offsetof(nuccAmbient, base_field_50) == 0x50, "nuccAmbient.base_field_50");
static_assert(offsetof(nuccAmbient, base_field_58) == 0x58, "nuccAmbient.base_field_58");
static_assert(offsetof(nuccAmbient, _unknown_60) == 0x60, "nuccAmbient._unknown_60");
static_assert(offsetof(nuccAmbient, base_int_64) == 0x64, "nuccAmbient.base_int_64");
static_assert(offsetof(nuccAmbient, _gap_68) == 0x68, "nuccAmbient._gap_68");
static_assert(offsetof(nuccAmbient, _gap_70) == 0x70, "nuccAmbient._gap_70");
static_assert(offsetof(nuccAmbient, _gap_78) == 0x78, "nuccAmbient._gap_78");
static_assert(offsetof(nuccAmbient, _gap_80) == 0x80, "nuccAmbient._gap_80");

/* ========================================================================
 * nuccAnm::ApplyClumpData - animation clump substitution data
 * Size: unknown, >= 0xA0 (dtor at 0x68ED60 accesses up to +0x98;
 * operator= at 0x691530 uses linked-list stride 0xB8)
 * Vtable: none observed
 * Three SSO strings at base offsets 0x00, 0x38, 0x70.
 * Linked list: head at +0x10, tail at +0x18, next stride 0xB8, refcount at +0x30.
 * ======================================================================== */
typedef struct __attribute__((packed)) nuccAnm_ApplyClumpData {
    /* String 0 region (SSO: inline buf, ptr at +0x08, size at +0x20) */
    uint8_t str0_sso_buf[8]; /* 0x00 */
    void *str0_ptr;          /* 0x08 - heap ptr or SSO data; dual-use list_head */
    void *list_tail;         /* 0x10 - linked-list tail / reused */
    uint64_t str0_size;      /* 0x18 - dtor resets to 0xf */
    uint64_t str0_extra;     /* 0x20 - allocator/capacity */
    uint64_t str0_alloc;     /* 0x28 - dtor sets PTR_FUN_1409ec308 */
    uint16_t refcount;       /* 0x30 */
    uint8_t _pad_32[6];      /* 0x32 */

    /* String 1 region */
    uint8_t str1_sso_buf[8]; /* 0x38 */
    void *str1_ptr;          /* 0x40 */
    uint64_t _gap_48;        /* 0x48 */
    uint64_t str1_size;      /* 0x50 */
    uint64_t str1_extra;     /* 0x58 */
    uint64_t _unknown_60;    /* 0x60 - accessed by dtor */
    uint64_t _pad_68;        /* 0x68 */

    /* String 2 region */
    uint8_t str2_sso_buf[8]; /* 0x70 */
    void *str2_ptr;          /* 0x78 */
    uint64_t _gap_80;        /* 0x80 */
    uint64_t str2_size;      /* 0x88 */
    uint64_t str2_extra;     /* 0x90 */
    uint64_t str2_allocator; /* 0x98 - dtor passes to FUN_140684c60 */
} nuccAnm_ApplyClumpData;
/* size unknown, >= 0xA0 */

static_assert(offsetof(nuccAnm_ApplyClumpData, str0_sso_buf) == 0x00, "ACD.str0_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_ptr) == 0x08, "ACD.str0_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, list_tail) == 0x10, "ACD.list_tail");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_size) == 0x18, "ACD.str0_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_extra) == 0x20, "ACD.str0_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, str0_alloc) == 0x28, "ACD.str0_alloc");
static_assert(offsetof(nuccAnm_ApplyClumpData, refcount) == 0x30, "ACD.refcount");
static_assert(offsetof(nuccAnm_ApplyClumpData, _pad_32) == 0x32, "ACD._pad_32");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_sso_buf) == 0x38, "ACD.str1_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_ptr) == 0x40, "ACD.str1_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, _gap_48) == 0x48, "ACD._gap_48");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_size) == 0x50, "ACD.str1_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str1_extra) == 0x58, "ACD.str1_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, _unknown_60) == 0x60, "ACD._unknown_60");
static_assert(offsetof(nuccAnm_ApplyClumpData, _pad_68) == 0x68, "ACD._pad_68");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_sso_buf) == 0x70, "ACD.str2_sso_buf");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_ptr) == 0x78, "ACD.str2_ptr");
static_assert(offsetof(nuccAnm_ApplyClumpData, _gap_80) == 0x80, "ACD._gap_80");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_size) == 0x88, "ACD.str2_size");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_extra) == 0x90, "ACD.str2_extra");
static_assert(offsetof(nuccAnm_ApplyClumpData, str2_allocator) == 0x98, "ACD.str2_allocator");
