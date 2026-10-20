/* rbBullet s3 — NARUTO STORM 3 Full Burst HD PC (NSUNS3.exe, 64-bit)
 * Bullet Physics 2.89, float precision, 16-byte aligned btVector3.
 * Statically linked into NSUNS3.exe.
 *
 * ADAPTED FROM s2 header — offsets must be re-verified against s3 decompiled code.
 * Storm-specific extensions in rbBtDiscreteDynamicsWorld:
 *   m_storm_fixedTimeAccumulator @ 0x174 (VERIFY for s3)
 *   m_storm_latencyInterpFlag    @ 0x1A4 (VERIFY for s3)
 *
 * All layouts INFERRED from static analysis unless marked VERIFIED in TSV.
 * Runtime confirmation recommended before use in live patches.
 */
#ifndef RB_BULLET_S3_H
#define RB_BULLET_S3_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ---- Primitive SIMD types ---- */

typedef struct rbBtVector3 {
    float m_floats[4];
} rbBtVector3;
static_assert(sizeof(rbBtVector3) == 16, "rbBtVector3 size");

typedef struct rbBtMatrix3x3 {
    rbBtVector3 m_el[3];
} rbBtMatrix3x3;
static_assert(sizeof(rbBtMatrix3x3) == 48, "rbBtMatrix3x3 size");

typedef struct rbBtQuaternion {
    float m_floats[4];
} rbBtQuaternion;
static_assert(sizeof(rbBtQuaternion) == 16, "rbBtQuaternion size");

typedef struct rbBtTransform {
    rbBtMatrix3x3 m_basis;
    rbBtVector3   m_origin;
} rbBtTransform;
static_assert(offsetof(rbBtTransform, m_basis) == 0x00, "rbBtTransform.m_basis");
static_assert(offsetof(rbBtTransform, m_origin) == 0x30, "rbBtTransform.m_origin");
static_assert(sizeof(rbBtTransform) == 64, "rbBtTransform size");

/* ---- AlignedObjectArray (template flattened) ---- */

typedef struct rbBtAlignedObjectArray {
    void*     m_data;
    int32_t   m_size;
    int32_t   m_capacity;
} rbBtAlignedObjectArray;
static_assert(offsetof(rbBtAlignedObjectArray, m_data) == 0x00, "aoa.m_data");
static_assert(offsetof(rbBtAlignedObjectArray, m_size) == 0x08, "aoa.m_size");
static_assert(offsetof(rbBtAlignedObjectArray, m_capacity) == 0x0C, "aoa.m_capacity");
static_assert(sizeof(rbBtAlignedObjectArray) == 16, "aoa size");

/* ---- btCollisionObject ---- */
/* Field order: vtable + broadphaseHandle (2 ptrs) then worldTransform at 0x10.
 * collisionShape pointer is stored elsewhere or after the transform block.
 * Verified offsets: worldTransform=0x10, interpWT=0x50, interpLV=0x90,
 * hasAniso=0xE8, uniqueId=0x10C, sizeof=0x110. */

typedef struct rbBtCollisionObject {
    void*         m_vtable;               /* 0x000 */
    void*         m_broadphaseHandle;     /* 0x008 */
    rbBtTransform m_worldTransform;       /* 0x010 VERIFIED */
    rbBtTransform m_interpolationWorldTransform; /* 0x050 VERIFIED */
    rbBtVector3   m_interpolationLinearVelocity;  /* 0x090 VERIFIED */
    rbBtVector3   m_interpolationAngularVelocity; /* 0x0A0 VERIFIED */
    rbBtVector3   m_anisotropicFriction;  /* 0x0B0 */
    float         m_contactProcessingThreshold; /* 0x0C0 */
    float         m_deactivationTime;     /* 0x0C4 */
    float         m_friction;             /* 0x0C8 */
    float         m_rollingFriction;      /* 0x0CC */
    float         m_contactDamping;       /* 0x0D0 */
    float         m_contactStiffness;     /* 0x0D4 */
    float         m_restitution;          /* 0x0D8 */
    float         m_hitFraction;          /* 0x0DC */
    float         m_ccdSweptSphereRadius; /* 0x0E0 */
    float         m_ccdMotionThreshold;   /* 0x0E4 */
    int32_t       m_hasAnisotropicFriction; /* 0x0E8 VERIFIED */
    int32_t       m_collisionFlags;       /* 0x0EC */
    int32_t       m_islandTag1;           /* 0x0F0 */
    int32_t       m_companionId;          /* 0x0F4 */
    int32_t       m_activationState1;     /* 0x0F8 */
    int32_t       m_internalType;         /* 0x0FC */
    int32_t       m_checkCollideWith;     /* 0x100 */
    int32_t       m_collisionFilterGroup; /* 0x104 */
    int32_t       m_collisionFilterMask;  /* 0x108 */
    int32_t       m_uniqueId;             /* 0x10C */
} rbBtCollisionObject;
static_assert(offsetof(rbBtCollisionObject, m_worldTransform) == 0x010, "co.m_worldTransform");
static_assert(offsetof(rbBtCollisionObject, m_interpolationWorldTransform) == 0x050, "co.m_interpWT");
static_assert(offsetof(rbBtCollisionObject, m_interpolationLinearVelocity) == 0x090, "co.m_interpLV");
static_assert(offsetof(rbBtCollisionObject, m_interpolationAngularVelocity) == 0x0A0, "co.m_interpAV");
static_assert(offsetof(rbBtCollisionObject, m_hasAnisotropicFriction) == 0x0E8, "co.m_hasAniso");
static_assert(offsetof(rbBtCollisionObject, m_uniqueId) == 0x10C, "co.m_uniqueId");
static_assert(offsetof(rbBtCollisionObject, m_broadphaseHandle) == 0x008, "rbBtCollisionObject.m_broadphaseHandle");
static_assert(offsetof(rbBtCollisionObject, m_anisotropicFriction) == 0x0B0, "rbBtCollisionObject.m_anisotropicFriction");
static_assert(offsetof(rbBtCollisionObject, m_contactProcessingThreshold) == 0x0C0, "rbBtCollisionObject.m_contactProcessingThreshold");
static_assert(offsetof(rbBtCollisionObject, m_deactivationTime) == 0x0C4, "rbBtCollisionObject.m_deactivationTime");
static_assert(offsetof(rbBtCollisionObject, m_friction) == 0x0C8, "rbBtCollisionObject.m_friction");
static_assert(offsetof(rbBtCollisionObject, m_rollingFriction) == 0x0CC, "rbBtCollisionObject.m_rollingFriction");
static_assert(offsetof(rbBtCollisionObject, m_contactDamping) == 0x0D0, "rbBtCollisionObject.m_contactDamping");
static_assert(offsetof(rbBtCollisionObject, m_contactStiffness) == 0x0D4, "rbBtCollisionObject.m_contactStiffness");
static_assert(offsetof(rbBtCollisionObject, m_restitution) == 0x0D8, "rbBtCollisionObject.m_restitution");
static_assert(offsetof(rbBtCollisionObject, m_hitFraction) == 0x0DC, "rbBtCollisionObject.m_hitFraction");
static_assert(offsetof(rbBtCollisionObject, m_ccdSweptSphereRadius) == 0x0E0, "rbBtCollisionObject.m_ccdSweptSphereRadius");
static_assert(offsetof(rbBtCollisionObject, m_ccdMotionThreshold) == 0x0E4, "rbBtCollisionObject.m_ccdMotionThreshold");
static_assert(offsetof(rbBtCollisionObject, m_collisionFlags) == 0x0EC, "rbBtCollisionObject.m_collisionFlags");
static_assert(offsetof(rbBtCollisionObject, m_islandTag1) == 0x0F0, "rbBtCollisionObject.m_islandTag1");
static_assert(offsetof(rbBtCollisionObject, m_companionId) == 0x0F4, "rbBtCollisionObject.m_companionId");
static_assert(offsetof(rbBtCollisionObject, m_activationState1) == 0x0F8, "rbBtCollisionObject.m_activationState1");
static_assert(offsetof(rbBtCollisionObject, m_internalType) == 0x0FC, "rbBtCollisionObject.m_internalType");
static_assert(offsetof(rbBtCollisionObject, m_checkCollideWith) == 0x100, "rbBtCollisionObject.m_checkCollideWith");
static_assert(offsetof(rbBtCollisionObject, m_collisionFilterGroup) == 0x104, "rbBtCollisionObject.m_collisionFilterGroup");
static_assert(offsetof(rbBtCollisionObject, m_collisionFilterMask) == 0x108, "rbBtCollisionObject.m_collisionFilterMask");
static_assert(sizeof(rbBtCollisionObject) == 0x110, "rbBtCollisionObject size");

/* ---- btRigidBody ---- */
/* Extends rbBtCollisionObject (base = 0x110 bytes).
 * Gap 0x110..0x18F (128 bytes) likely contains m_invInertiaTensorWorld etc.
 * Verified: linearVel=0x190, angularVel=0x1A0, mass=0x1B0,
 * gravityFactor=0x1C0, gravity_accel=0x1D0, gravity=0x1E0,
 * totalForce=0x200, totalTorque=0x210, constraintRefs at 0x254-0x264.
 * sizeof >= 0x268. */

typedef struct rbBtRigidBody {
    /* --- Base: rbBtCollisionObject (0x110 bytes) --- */
    void*         m_vtable;               /* 0x000 */
    void*         m_broadphaseHandle;     /* 0x008 */
    rbBtTransform m_worldTransform;       /* 0x010 */
    rbBtTransform m_interpolationWorldTransform; /* 0x050 */
    rbBtVector3   m_interpolationLinearVelocity;  /* 0x090 */
    rbBtVector3   m_interpolationAngularVelocity; /* 0x0A0 */
    rbBtVector3   m_anisotropicFriction;  /* 0x0B0 */
    float         m_contactProcessingThreshold; /* 0x0C0 */
    float         m_deactivationTime;     /* 0x0C4 */
    float         m_friction;             /* 0x0C8 */
    float         m_rollingFriction;      /* 0x0CC */
    float         m_contactDamping;       /* 0x0D0 */
    float         m_contactStiffness;     /* 0x0D4 */
    float         m_restitution;          /* 0x0D8 */
    float         m_hitFraction;          /* 0x0DC */
    float         m_ccdSweptSphereRadius; /* 0x0E0 */
    float         m_ccdMotionThreshold;   /* 0x0E4 */
    int32_t       m_hasAnisotropicFriction; /* 0x0E8 */
    int32_t       m_collisionFlags;       /* 0x0EC */
    int32_t       m_islandTag1;           /* 0x0F0 */
    int32_t       m_companionId;          /* 0x0F4 */
    int32_t       m_activationState1;     /* 0x0F8 */
    int32_t       m_internalType;         /* 0x0FC */
    int32_t       m_checkCollideWith;     /* 0x100 */
    int32_t       m_collisionFilterGroup; /* 0x104 */
    int32_t       m_collisionFilterMask;  /* 0x108 */
    int32_t       m_uniqueId;             /* 0x10C */
    /* --- RigidBody extension --- */
    uint8_t       _unknown_0x110[128];    /* 0x110..0x18F gap (invInertia etc.) */
    rbBtVector3   m_linearVelocity;       /* 0x190 VERIFIED */
    rbBtVector3   m_angularVelocity;      /* 0x1A0 VERIFIED */
    float         m_mass;                 /* 0x1B0 VERIFIED */
    float         m_inverseMass;          /* 0x1B4 */
    uint8_t       _pad_0x1B8[8];          /* 0x1B8..0x1BF */
    rbBtVector3   m_gravityFactor;        /* 0x1C0 VERIFIED */
    rbBtVector3   m_gravity_acceleration; /* 0x1D0 VERIFIED */
    rbBtVector3   m_gravity;              /* 0x1E0 VERIFIED */
    uint8_t       _pad_0x1F0[16];         /* 0x1F0..0x1FF */
    rbBtVector3   m_totalForce;           /* 0x200 VERIFIED */
    rbBtVector3   m_totalTorque;          /* 0x210 */
    uint8_t       _unknown_0x220[52];     /* 0x220..0x253 */
    int32_t       m_constraintRefs_m_size;     /* 0x254 VERIFIED */
    int32_t       m_constraintRefs_m_capacity; /* 0x258 VERIFIED */
    void**        m_constraintRefs_m_data;     /* 0x25C VERIFIED */
    uint8_t       m_constraintRefs_m_ownsMemory; /* 0x264 VERIFIED */
    uint8_t       _pad_0x265[3];          /* 0x265..0x267 */
} rbBtRigidBody;
static_assert(offsetof(rbBtRigidBody, m_worldTransform) == 0x010, "rb.m_worldTransform");
static_assert(offsetof(rbBtRigidBody, m_interpolationWorldTransform) == 0x050, "rb.m_interpWT");
static_assert(offsetof(rbBtRigidBody, m_interpolationLinearVelocity) == 0x090, "rb.m_interpLV");
static_assert(offsetof(rbBtRigidBody, m_interpolationAngularVelocity) == 0x0A0, "rb.m_interpAV");
static_assert(offsetof(rbBtRigidBody, m_linearVelocity) == 0x190, "rb.m_linearVel");
static_assert(offsetof(rbBtRigidBody, m_angularVelocity) == 0x1A0, "rb.m_angularVel");
static_assert(offsetof(rbBtRigidBody, m_mass) == 0x1B0, "rb.m_mass");
static_assert(offsetof(rbBtRigidBody, m_gravityFactor) == 0x1C0, "rb.m_gravFactor");
static_assert(offsetof(rbBtRigidBody, m_gravity_acceleration) == 0x1D0, "rb.m_gravAccel");
static_assert(offsetof(rbBtRigidBody, m_gravity) == 0x1E0, "rb.m_gravity");
static_assert(offsetof(rbBtRigidBody, m_totalForce) == 0x200, "rb.m_totalForce");
static_assert(offsetof(rbBtRigidBody, m_totalTorque) == 0x210, "rb.m_totalTorque");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_size) == 0x254, "rb.m_cref_size");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_capacity) == 0x258, "rb.m_cref_cap");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_data) == 0x25C, "rb.m_cref_data");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_ownsMemory) == 0x264, "rb.m_cref_owns");
static_assert(offsetof(rbBtRigidBody, m_broadphaseHandle) == 0x008, "rbBtRigidBody.m_broadphaseHandle");
static_assert(offsetof(rbBtRigidBody, m_anisotropicFriction) == 0x0B0, "rbBtRigidBody.m_anisotropicFriction");
static_assert(offsetof(rbBtRigidBody, m_contactProcessingThreshold) == 0x0C0, "rbBtRigidBody.m_contactProcessingThreshold");
static_assert(offsetof(rbBtRigidBody, m_deactivationTime) == 0x0C4, "rbBtRigidBody.m_deactivationTime");
static_assert(offsetof(rbBtRigidBody, m_friction) == 0x0C8, "rbBtRigidBody.m_friction");
static_assert(offsetof(rbBtRigidBody, m_rollingFriction) == 0x0CC, "rbBtRigidBody.m_rollingFriction");
static_assert(offsetof(rbBtRigidBody, m_contactDamping) == 0x0D0, "rbBtRigidBody.m_contactDamping");
static_assert(offsetof(rbBtRigidBody, m_contactStiffness) == 0x0D4, "rbBtRigidBody.m_contactStiffness");
static_assert(offsetof(rbBtRigidBody, m_restitution) == 0x0D8, "rbBtRigidBody.m_restitution");
static_assert(offsetof(rbBtRigidBody, m_hitFraction) == 0x0DC, "rbBtRigidBody.m_hitFraction");
static_assert(offsetof(rbBtRigidBody, m_ccdSweptSphereRadius) == 0x0E0, "rbBtRigidBody.m_ccdSweptSphereRadius");
static_assert(offsetof(rbBtRigidBody, m_ccdMotionThreshold) == 0x0E4, "rbBtRigidBody.m_ccdMotionThreshold");
static_assert(offsetof(rbBtRigidBody, m_hasAnisotropicFriction) == 0x0E8, "rbBtRigidBody.m_hasAnisotropicFriction");
static_assert(offsetof(rbBtRigidBody, m_collisionFlags) == 0x0EC, "rbBtRigidBody.m_collisionFlags");
static_assert(offsetof(rbBtRigidBody, m_islandTag1) == 0x0F0, "rbBtRigidBody.m_islandTag1");
static_assert(offsetof(rbBtRigidBody, m_companionId) == 0x0F4, "rbBtRigidBody.m_companionId");
static_assert(offsetof(rbBtRigidBody, m_activationState1) == 0x0F8, "rbBtRigidBody.m_activationState1");
static_assert(offsetof(rbBtRigidBody, m_internalType) == 0x0FC, "rbBtRigidBody.m_internalType");
static_assert(offsetof(rbBtRigidBody, m_checkCollideWith) == 0x100, "rbBtRigidBody.m_checkCollideWith");
static_assert(offsetof(rbBtRigidBody, m_collisionFilterGroup) == 0x104, "rbBtRigidBody.m_collisionFilterGroup");
static_assert(offsetof(rbBtRigidBody, m_collisionFilterMask) == 0x108, "rbBtRigidBody.m_collisionFilterMask");
static_assert(offsetof(rbBtRigidBody, m_uniqueId) == 0x10C, "rbBtRigidBody.m_uniqueId");
static_assert(offsetof(rbBtRigidBody, m_inverseMass) == 0x1B4, "rbBtRigidBody.m_inverseMass");
static_assert(sizeof(rbBtRigidBody) == 0x268, "rbBtRigidBody size");

/* ---- btManifoldPoint ---- */

typedef struct rbBtManifoldPoint {
    rbBtVector3 m_localPointA;            /* 0x000 */
    rbBtVector3 m_localPointB;            /* 0x010 */
    rbBtVector3 m_positionWorldOnB;       /* 0x020 */
    rbBtVector3 m_positionWorldOnA;       /* 0x030 */
    rbBtVector3 m_normalWorldOnB;         /* 0x040 */
    float       m_distance1;              /* 0x050 */
    float       m_combinedFriction;       /* 0x054 */
    float       m_combinedRollingFriction;/* 0x058 */
    float       m_combinedSpinningFriction;/* 0x05C */
    float       m_combinedRestitution;    /* 0x060 */
    int32_t     m_partId0;                /* 0x064 */
    int32_t     m_partId1;                /* 0x068 */
    int32_t     m_index0;                 /* 0x06C */
    int32_t     m_index1;                 /* 0x070 */
    uint8_t     _pad_0x074[4];            /* 0x074 */
    void*       m_userPersistentData;     /* 0x078 */
    int32_t     m_contactPointFlags;      /* 0x080 */
    uint8_t     _pad_0x084[4];            /* 0x084 */
    float       m_appliedImpulse;         /* 0x088 */
    float       m_prevRHS;                /* 0x08C */
    float       m_appliedImpulseLateral1; /* 0x090 */
    float       m_appliedImpulseLateral2; /* 0x094 */
    float       m_contactMotion1;         /* 0x098 */
    float       m_contactMotion2;         /* 0x09C */
    float       m_contactCFM;             /* 0x0A0 */
    float       m_contactERP;             /* 0x0A4 */
    float       m_frictionCFM;            /* 0x0A8 */
    int32_t     m_lifeTime;               /* 0x0AC */
    rbBtVector3 m_lateralFrictionDir1;    /* 0x0B0 */
    rbBtVector3 m_lateralFrictionDir2;    /* 0x0C0 */
} rbBtManifoldPoint;
static_assert(offsetof(rbBtManifoldPoint, m_localPointA) == 0x000, "mp.m_localPointA");
static_assert(offsetof(rbBtManifoldPoint, m_normalWorldOnB) == 0x040, "mp.m_normal");
static_assert(offsetof(rbBtManifoldPoint, m_appliedImpulse) == 0x088, "mp.m_appliedImpulse");
static_assert(offsetof(rbBtManifoldPoint, m_lateralFrictionDir1) == 0x0B0, "mp.m_latFric1");
static_assert(offsetof(rbBtManifoldPoint, m_localPointB) == 0x010, "rbBtManifoldPoint.m_localPointB");
static_assert(offsetof(rbBtManifoldPoint, m_positionWorldOnB) == 0x020, "rbBtManifoldPoint.m_positionWorldOnB");
static_assert(offsetof(rbBtManifoldPoint, m_positionWorldOnA) == 0x030, "rbBtManifoldPoint.m_positionWorldOnA");
static_assert(offsetof(rbBtManifoldPoint, m_distance1) == 0x050, "rbBtManifoldPoint.m_distance1");
static_assert(offsetof(rbBtManifoldPoint, m_combinedFriction) == 0x054, "rbBtManifoldPoint.m_combinedFriction");
static_assert(offsetof(rbBtManifoldPoint, m_combinedRollingFriction) == 0x058, "rbBtManifoldPoint.m_combinedRollingFriction");
static_assert(offsetof(rbBtManifoldPoint, m_combinedSpinningFriction) == 0x05C, "rbBtManifoldPoint.m_combinedSpinningFriction");
static_assert(offsetof(rbBtManifoldPoint, m_combinedRestitution) == 0x060, "rbBtManifoldPoint.m_combinedRestitution");
static_assert(offsetof(rbBtManifoldPoint, m_partId0) == 0x064, "rbBtManifoldPoint.m_partId0");
static_assert(offsetof(rbBtManifoldPoint, m_partId1) == 0x068, "rbBtManifoldPoint.m_partId1");
static_assert(offsetof(rbBtManifoldPoint, m_index0) == 0x06C, "rbBtManifoldPoint.m_index0");
static_assert(offsetof(rbBtManifoldPoint, m_index1) == 0x070, "rbBtManifoldPoint.m_index1");
static_assert(offsetof(rbBtManifoldPoint, m_userPersistentData) == 0x078, "rbBtManifoldPoint.m_userPersistentData");
static_assert(offsetof(rbBtManifoldPoint, m_contactPointFlags) == 0x080, "rbBtManifoldPoint.m_contactPointFlags");
static_assert(offsetof(rbBtManifoldPoint, m_prevRHS) == 0x08C, "rbBtManifoldPoint.m_prevRHS");
static_assert(offsetof(rbBtManifoldPoint, m_appliedImpulseLateral1) == 0x090, "rbBtManifoldPoint.m_appliedImpulseLateral1");
static_assert(offsetof(rbBtManifoldPoint, m_appliedImpulseLateral2) == 0x094, "rbBtManifoldPoint.m_appliedImpulseLateral2");
static_assert(offsetof(rbBtManifoldPoint, m_contactMotion1) == 0x098, "rbBtManifoldPoint.m_contactMotion1");
static_assert(offsetof(rbBtManifoldPoint, m_contactMotion2) == 0x09C, "rbBtManifoldPoint.m_contactMotion2");
static_assert(offsetof(rbBtManifoldPoint, m_contactCFM) == 0x0A0, "rbBtManifoldPoint.m_contactCFM");
static_assert(offsetof(rbBtManifoldPoint, m_contactERP) == 0x0A4, "rbBtManifoldPoint.m_contactERP");
static_assert(offsetof(rbBtManifoldPoint, m_frictionCFM) == 0x0A8, "rbBtManifoldPoint.m_frictionCFM");
static_assert(offsetof(rbBtManifoldPoint, m_lifeTime) == 0x0AC, "rbBtManifoldPoint.m_lifeTime");
static_assert(offsetof(rbBtManifoldPoint, m_lateralFrictionDir2) == 0x0C0, "rbBtManifoldPoint.m_lateralFrictionDir2");
static_assert(sizeof(rbBtManifoldPoint) == 0x0D0, "rbBtManifoldPoint size");

/* ---- btPersistentManifold ---- */

typedef struct rbBtPersistentManifold {
    void*             m_vtable;           /* 0x000 */
    int32_t           m_objectType;       /* 0x008 */
    uint8_t           _pad_0x00C[4];      /* 0x00C */
    rbBtManifoldPoint m_pointCache[4];    /* 0x010, 4*0xD0=0x340 */
    uint8_t           _pad_0x350[8];      /* 0x350 */
    const void*       m_body0;            /* 0x358 */
    const void*       m_body1;            /* 0x360 */
    int32_t           m_cachedPoints;     /* 0x368 */
    float             m_contactBreakingThreshold;  /* 0x36C */
    float             m_contactProcessingThreshold;/* 0x370 */
    int32_t           m_companionIdA;     /* 0x374 */
    int32_t           m_companionIdB;     /* 0x378 */
    int32_t           m_index1a;          /* 0x37C */
    uint8_t           _pad_0x380[48];     /* 0x380 trailing */
} rbBtPersistentManifold;
static_assert(offsetof(rbBtPersistentManifold, m_pointCache) == 0x010, "pm.m_pointCache");
static_assert(offsetof(rbBtPersistentManifold, m_body0) == 0x358, "pm.m_body0");
static_assert(offsetof(rbBtPersistentManifold, m_body1) == 0x360, "pm.m_body1");
static_assert(offsetof(rbBtPersistentManifold, m_cachedPoints) == 0x368, "pm.m_cachedPoints");
static_assert(offsetof(rbBtPersistentManifold, m_objectType) == 0x008, "rbBtPersistentManifold.m_objectType");
static_assert(offsetof(rbBtPersistentManifold, m_contactBreakingThreshold) == 0x36C, "rbBtPersistentManifold.m_contactBreakingThreshold");
static_assert(offsetof(rbBtPersistentManifold, m_contactProcessingThreshold) == 0x370, "rbBtPersistentManifold.m_contactProcessingThreshold");
static_assert(offsetof(rbBtPersistentManifold, m_companionIdA) == 0x374, "rbBtPersistentManifold.m_companionIdA");
static_assert(offsetof(rbBtPersistentManifold, m_companionIdB) == 0x378, "rbBtPersistentManifold.m_companionIdB");
static_assert(offsetof(rbBtPersistentManifold, m_index1a) == 0x37C, "rbBtPersistentManifold.m_index1a");
static_assert(sizeof(rbBtPersistentManifold) == 0x3B0, "rbBtPersistentManifold size");

/* ---- btBroadphaseProxy ---- */

typedef struct rbBtBroadphaseProxy {
    rbBtVector3 m_aabbMin;                /* 0x000 */
    rbBtVector3 m_aabbMax;                /* 0x010 */
    void*       m_multiSapParentProxy;    /* 0x020 */
    int32_t     m_uniqueId;               /* 0x028 */
    int32_t     m_collisionFilterGroup;   /* 0x02C */
    int32_t     m_collisionFilterMask;    /* 0x030 */
    uint8_t     _pad_0x034[4];            /* 0x034 */
    void*       m_clientObject;           /* 0x038 */
} rbBtBroadphaseProxy;
static_assert(offsetof(rbBtBroadphaseProxy, m_aabbMin) == 0x000, "bp.m_aabbMin");
static_assert(offsetof(rbBtBroadphaseProxy, m_clientObject) == 0x038, "bp.m_clientObj");
static_assert(offsetof(rbBtBroadphaseProxy, m_aabbMax) == 0x010, "rbBtBroadphaseProxy.m_aabbMax");
static_assert(offsetof(rbBtBroadphaseProxy, m_multiSapParentProxy) == 0x020, "rbBtBroadphaseProxy.m_multiSapParentProxy");
static_assert(offsetof(rbBtBroadphaseProxy, m_uniqueId) == 0x028, "rbBtBroadphaseProxy.m_uniqueId");
static_assert(offsetof(rbBtBroadphaseProxy, m_collisionFilterGroup) == 0x02C, "rbBtBroadphaseProxy.m_collisionFilterGroup");
static_assert(offsetof(rbBtBroadphaseProxy, m_collisionFilterMask) == 0x030, "rbBtBroadphaseProxy.m_collisionFilterMask");
static_assert(sizeof(rbBtBroadphaseProxy) == 0x040, "rbBtBroadphaseProxy size");

/* ---- btSolverBody ---- */

typedef struct rbBtSolverBody {
    rbBtTransform m_worldTransform;       /* 0x000 */
    rbBtVector3   m_deltaLinearVelocity;  /* 0x040 */
    rbBtVector3   m_deltaAngularVelocity; /* 0x050 */
    rbBtVector3   m_angularFactor;        /* 0x060 */
    rbBtVector3   m_linearFactor;         /* 0x070 */
    rbBtVector3   m_invMass;              /* 0x080 */
    rbBtVector3   m_pushVelocity;         /* 0x090 */
} rbBtSolverBody;
static_assert(offsetof(rbBtSolverBody, m_worldTransform) == 0x000, "sb.m_wt");
static_assert(offsetof(rbBtSolverBody, m_deltaLinearVelocity) == 0x040, "sb.m_dlv");
static_assert(offsetof(rbBtSolverBody, m_pushVelocity) == 0x090, "sb.m_pushVel");
static_assert(offsetof(rbBtSolverBody, m_deltaAngularVelocity) == 0x050, "rbBtSolverBody.m_deltaAngularVelocity");
static_assert(offsetof(rbBtSolverBody, m_angularFactor) == 0x060, "rbBtSolverBody.m_angularFactor");
static_assert(offsetof(rbBtSolverBody, m_linearFactor) == 0x070, "rbBtSolverBody.m_linearFactor");
static_assert(offsetof(rbBtSolverBody, m_invMass) == 0x080, "rbBtSolverBody.m_invMass");
static_assert(sizeof(rbBtSolverBody) == 0x0A0, "rbBtSolverBody size");

/* ---- btContactSolverInfoData ---- */

typedef struct rbBtContactSolverInfoData {
    float   m_tau;                        /* 0x00 */
    float   m_damping;                    /* 0x04 */
    float   m_friction;                   /* 0x08 */
    float   m_timeStep;                   /* 0x0C */
    float   m_restitution;                /* 0x10 */
    int32_t m_numIterations;              /* 0x14 */
    float   m_maxErrorReduction;          /* 0x18 */
    float   m_sor;                        /* 0x1C */
    float   m_erp;                        /* 0x20 */
    float   m_erp2;                       /* 0x24 */
    float   m_deformable_erp;             /* 0x28 */
    float   m_globalCfm;                  /* 0x2C */
    float   m_frictionERP;                /* 0x30 */
    float   m_frictionCFM;                /* 0x34 */
    int32_t m_splitImpulse;               /* 0x38 */
    float   m_splitImpulsePenetrationThreshold; /* 0x3C */
    float   m_splitImpulseTurnErp;        /* 0x40 */
    float   m_linearSlop;                 /* 0x44 */
    float   m_warmstartingFactor;         /* 0x48 */
    float   m_articulatedWarmstartingFactor; /* 0x4C */
    int32_t m_solverMode;                 /* 0x50 */
    int32_t m_restingContactRestitutionThreshold; /* 0x54 */
    int32_t m_minimumSolverBatchSize;     /* 0x58 */
    float   m_maxGyroscopicForce;         /* 0x5C */
    float   m_singleAxisRollingFrictionThreshold; /* 0x60 */
    float   m_leastSquaresResidualThreshold; /* 0x64 */
    float   m_restitutionVelocityThreshold; /* 0x68 */
    uint8_t m_jointFeedbackInWorldSpace;  /* 0x6C */
    uint8_t m_jointFeedbackInJointFrame;  /* 0x6D */
    uint8_t _pad_0x6E[2];                 /* 0x6E */
    int32_t m_reportSolverAnalytics;      /* 0x70 */
} rbBtContactSolverInfoData;
static_assert(offsetof(rbBtContactSolverInfoData, m_tau) == 0x00, "csid.m_tau");
static_assert(offsetof(rbBtContactSolverInfoData, m_solverMode) == 0x50, "csid.m_solverMode");
static_assert(offsetof(rbBtContactSolverInfoData, m_timeStep) == 0x0C, "rbBtContactSolverInfoData.m_timeStep");
static_assert(offsetof(rbBtContactSolverInfoData, m_numIterations) == 0x14, "rbBtContactSolverInfoData.m_numIterations");
static_assert(offsetof(rbBtContactSolverInfoData, m_maxErrorReduction) == 0x018, "rbBtContactSolverInfoData.m_maxErrorReduction");
static_assert(offsetof(rbBtContactSolverInfoData, m_sor) == 0x01C, "rbBtContactSolverInfoData.m_sor");
static_assert(offsetof(rbBtContactSolverInfoData, m_erp) == 0x020, "rbBtContactSolverInfoData.m_erp");
static_assert(offsetof(rbBtContactSolverInfoData, m_erp2) == 0x024, "rbBtContactSolverInfoData.m_erp2");
static_assert(offsetof(rbBtContactSolverInfoData, m_deformable_erp) == 0x028, "rbBtContactSolverInfoData.m_deformable_erp");
static_assert(offsetof(rbBtContactSolverInfoData, m_globalCfm) == 0x02C, "rbBtContactSolverInfoData.m_globalCfm");
static_assert(offsetof(rbBtContactSolverInfoData, m_frictionERP) == 0x030, "rbBtContactSolverInfoData.m_frictionERP");
static_assert(offsetof(rbBtContactSolverInfoData, m_frictionCFM) == 0x034, "rbBtContactSolverInfoData.m_frictionCFM");
static_assert(offsetof(rbBtContactSolverInfoData, m_splitImpulse) == 0x038, "rbBtContactSolverInfoData.m_splitImpulse");
static_assert(offsetof(rbBtContactSolverInfoData, m_splitImpulsePenetrationThreshold) == 0x03C, "rbBtContactSolverInfoData.m_splitImpulsePenetrationThreshold");
static_assert(offsetof(rbBtContactSolverInfoData, m_splitImpulseTurnErp) == 0x040, "rbBtContactSolverInfoData.m_splitImpulseTurnErp");
static_assert(offsetof(rbBtContactSolverInfoData, m_linearSlop) == 0x044, "rbBtContactSolverInfoData.m_linearSlop");
static_assert(offsetof(rbBtContactSolverInfoData, m_warmstartingFactor) == 0x048, "rbBtContactSolverInfoData.m_warmstartingFactor");
static_assert(offsetof(rbBtContactSolverInfoData, m_articulatedWarmstartingFactor) == 0x04C, "rbBtContactSolverInfoData.m_articulatedWarmstartingFactor");
static_assert(offsetof(rbBtContactSolverInfoData, m_restingContactRestitutionThreshold) == 0x054, "rbBtContactSolverInfoData.m_restingContactRestitutionThreshold");
static_assert(offsetof(rbBtContactSolverInfoData, m_minimumSolverBatchSize) == 0x058, "rbBtContactSolverInfoData.m_minimumSolverBatchSize");
static_assert(offsetof(rbBtContactSolverInfoData, m_maxGyroscopicForce) == 0x05C, "rbBtContactSolverInfoData.m_maxGyroscopicForce");
static_assert(offsetof(rbBtContactSolverInfoData, m_singleAxisRollingFrictionThreshold) == 0x060, "rbBtContactSolverInfoData.m_singleAxisRollingFrictionThreshold");
static_assert(offsetof(rbBtContactSolverInfoData, m_leastSquaresResidualThreshold) == 0x064, "rbBtContactSolverInfoData.m_leastSquaresResidualThreshold");
static_assert(offsetof(rbBtContactSolverInfoData, m_restitutionVelocityThreshold) == 0x068, "rbBtContactSolverInfoData.m_restitutionVelocityThreshold");
static_assert(offsetof(rbBtContactSolverInfoData, m_jointFeedbackInWorldSpace) == 0x06C, "rbBtContactSolverInfoData.m_jointFeedbackInWorldSpace");
static_assert(offsetof(rbBtContactSolverInfoData, m_jointFeedbackInJointFrame) == 0x06D, "rbBtContactSolverInfoData.m_jointFeedbackInJointFrame");
static_assert(sizeof(rbBtContactSolverInfoData) == 0x74, "rbBtContactSolverInfoData size");

/* ---- btDiscreteDynamicsWorld ---- */
/* Storm extends this class with fixedTimeAccumulator @ 0x174
 * and latencyInterpFlag @ 0x1A4. Base fields through
 * predictiveManifoldsMutex verified against Bullet 2.89 source. */

typedef struct rbBtDiscreteDynamicsWorld {
    void**  m_collisionObjects_m_data;    /* 0x000 */
    int32_t m_collisionObjects_m_size;    /* 0x008 */
    int32_t m_collisionObjects_m_capacity;/* 0x00C */
    void*   m_dispatcher1;                /* 0x010 */
    void*   m_dispatchInfo;               /* 0x018 */
    void*   m_debugDrawer;                /* 0x020 */
    void*   m_broadphasePairCache;        /* 0x028 */
    void*   m_collisionAlgorithmPoolAllocator; /* 0x030 */
    void*   m_persistentManifoldPoolAllocator; /* 0x038 */
    void*   m_collisionAlgorithmConstructors;  /* 0x040 */
    int32_t m_numCcdSweptTests;           /* 0x048 */
    uint8_t m_forceUpdateAllAabbs;        /* 0x04C */
    uint8_t m_ownsBroadphasePairCache;    /* 0x04D */
    uint8_t m_ownsDispatcher;             /* 0x04E */
    uint8_t m_ownsCollisionAlgorithmPoolAllocator; /* 0x04F */
    uint8_t m_ownsPersistentManifoldPoolAllocator; /* 0x050 */
    uint8_t _pad_0x051[7];                /* 0x051 */
    void**  m_sortedConstraints_m_data;   /* 0x058 */
    int32_t m_sortedConstraints_m_size;   /* 0x060 */
    int32_t m_sortedConstraints_m_capacity;/* 0x064 */
    void*   m_solverIslandCallback;       /* 0x068 */
    void*   m_constraintSolver;           /* 0x070 */
    void*   m_islandManager;              /* 0x078 */
    void**  m_constraints_m_data;         /* 0x080 */
    int32_t m_constraints_m_size;         /* 0x088 */
    int32_t m_constraints_m_capacity;     /* 0x08C */
    void**  m_nonStaticRigidBodies_m_data;/* 0x090 */
    int32_t m_nonStaticRigidBodies_m_size;/* 0x098 */
    int32_t m_nonStaticRigidBodies_m_capacity; /* 0x09C */
    rbBtVector3 m_gravity;                /* 0x0A0 */
    uint8_t _unknown_0x0B0[192];          /* 0x0B0..0x16F gap (fixedTimeStep, owns*, actions, predictiveManifolds etc.) */
    float   m_localTime;                  /* 0x170 VERIFIED via state_surface */
    float   m_storm_fixedTimeAccumulator; /* 0x174 Storm extension VERIFIED */
    uint8_t _pad_0x178[44];               /* 0x178 */
    uint8_t m_storm_latencyInterpFlag;    /* 0x1A4 Storm extension */
    uint8_t _pad_0x1A5[11];               /* 0x1A5 trailing */
} rbBtDiscreteDynamicsWorld;
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_collisionObjects_m_data) == 0x000, "ddw.m_co_data");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_collisionObjects_m_size) == 0x008, "ddw.m_co_size");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_collisionObjects_m_capacity) == 0x00C, "ddw.m_co_cap");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_dispatcher1) == 0x010, "ddw.m_dispatcher1");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_dispatchInfo) == 0x018, "ddw.m_dispatchInfo");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_debugDrawer) == 0x020, "ddw.m_debugDrawer");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_broadphasePairCache) == 0x028, "ddw.m_bpPairCache");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_collisionAlgorithmPoolAllocator) == 0x030, "ddw.m_colAlgPool");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_persistentManifoldPoolAllocator) == 0x038, "ddw.m_pmPool");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_collisionAlgorithmConstructors) == 0x040, "ddw.m_colAlgCtors");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_numCcdSweptTests) == 0x048, "ddw.m_numCcd");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_forceUpdateAllAabbs) == 0x04C, "ddw.m_forceUpdAabbs");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_ownsBroadphasePairCache) == 0x04D, "ddw.m_ownsBp");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_ownsDispatcher) == 0x04E, "ddw.m_ownsDisp");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_ownsCollisionAlgorithmPoolAllocator) == 0x04F, "ddw.m_ownsColAlg");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_ownsPersistentManifoldPoolAllocator) == 0x050, "ddw.m_ownsPm");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_sortedConstraints_m_data) == 0x058, "ddw.m_sc_data");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_sortedConstraints_m_size) == 0x060, "ddw.m_sc_size");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_sortedConstraints_m_capacity) == 0x064, "ddw.m_sc_cap");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_solverIslandCallback) == 0x068, "ddw.m_solverIslCb");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_constraintSolver) == 0x070, "ddw.m_constrSolver");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_islandManager) == 0x078, "ddw.m_islandMgr");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_constraints_m_data) == 0x080, "ddw.m_constr_data");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_constraints_m_size) == 0x088, "ddw.m_constr_size");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_constraints_m_capacity) == 0x08C, "ddw.m_constr_cap");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_nonStaticRigidBodies_m_data) == 0x090, "ddw.m_nsrb_data");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_nonStaticRigidBodies_m_size) == 0x098, "ddw.m_nsrb_size");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_nonStaticRigidBodies_m_capacity) == 0x09C, "ddw.m_nsrb_cap");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_gravity) == 0x0A0, "ddw.m_gravity");
/* 0x0B0..0x16F opaque gap — unverified intermediate fields */
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_localTime) == 0x170, "ddw.m_localTime VERIFIED");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_storm_fixedTimeAccumulator) == 0x174, "ddw.m_storm_fta VERIFIED");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_storm_latencyInterpFlag) == 0x1A4, "ddw.m_storm_lif VERIFIED");
static_assert(sizeof(rbBtDiscreteDynamicsWorld) == 0x1B0, "ddw size");

#pragma pack(pop)

#endif /* RB_BULLET_S3_H */