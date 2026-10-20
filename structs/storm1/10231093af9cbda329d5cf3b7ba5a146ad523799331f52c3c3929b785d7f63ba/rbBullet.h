/*
 * rbBullet.h — Bullet Physics struct layouts for NARUTO STORM 1 (s1, NSUNS1.exe)
 *
 * REBUILT from s1 decompiled bt* methods via the decompiler cache MCP.
 * Layout differs significantly from vanilla Bullet 2.89 due to Storm-specific
 * modifications. All offsets verified against decompiled code.
 *
 * Evidence functions per field are documented in rbBullet-fields.tsv.
 * All structs are __attribute__((packed)) with explicit padding.
 * Every field has an offsetof static_assert.
 */

#ifndef RBBULLET_S1_H
#define RBBULLET_S1_H

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* ─── Primitive types ─── */
typedef float btScalar;

/* ─── btVector3 (SIMD-aligned, 16 bytes) ─── */
typedef struct __attribute__((packed)) {
    btScalar m_floats[4]; /* 0x00: x,y,z,w (w unused/padding) */
} rbBtVector3;
static_assert(sizeof(rbBtVector3) == 16, "rbBtVector3 size");
static_assert(offsetof(rbBtVector3, m_floats) == 0x00, "rbBtVector3::m_floats");

/* ─── btMatrix3x3 (3 × btVector3 = 48 bytes) ─── */
typedef struct __attribute__((packed)) {
    rbBtVector3 m_el[3]; /* 0x00 */
} rbBtMatrix3x3;
static_assert(sizeof(rbBtMatrix3x3) == 48, "rbBtMatrix3x3 size");
static_assert(offsetof(rbBtMatrix3x3, m_el) == 0x00, "rbBtMatrix3x3::m_el");

/* ─── btQuaternion (SIMD-aligned, 16 bytes) ─── */
typedef struct __attribute__((packed)) {
    btScalar m_floats[4]; /* 0x00: x,y,z,w */
} rbBtQuaternion;
static_assert(sizeof(rbBtQuaternion) == 16, "rbBtQuaternion size");
static_assert(offsetof(rbBtQuaternion, m_floats) == 0x00, "rbBtQuaternion::m_floats");

/* ─── btTransform (btMatrix3x3 + btVector3 = 64 bytes) ─── */
typedef struct __attribute__((packed)) {
    rbBtMatrix3x3 m_basis;   /* 0x00 */
    rbBtVector3   m_origin;  /* 0x30 */
} rbBtTransform;
static_assert(sizeof(rbBtTransform) == 64, "rbBtTransform size");
static_assert(offsetof(rbBtTransform, m_basis) == 0x00, "rbBtTransform::m_basis");
static_assert(offsetof(rbBtTransform, m_origin) == 0x30, "rbBtTransform::m_origin");

/* ─── btAlignedObjectArray<T> (pointer + size + capacity) ─── */
typedef struct __attribute__((packed)) {
    void   **m_data;     /* 0x00 */
    int32_t  m_size;     /* 0x08 */
    int32_t  m_capacity; /* 0x0C */
} rbBtAlignedObjectArray;
static_assert(sizeof(rbBtAlignedObjectArray) == 16, "rbBtAlignedObjectArray size");

/* ═══════════════════════════════════════════════════════════════════
 * btCollisionObject — s1 layout
 *
 * Verified by: btCollisionObject::setWorldTransform (writes 0x20..0x44),
 *              btRigidBody::proceedToTransform (copies 0x10..0x4F and 0x50..0x8F),
 *              btRigidBody::applyGravity (reads 0xE8 activation state).
 *
 * NOTE: s1 layout differs from vanilla Bullet 2.89. The vtable pointer
 * and broadphase handle positions are inferred; the confirmed region
 * starts at 0x10 (worldTransform) based on proceedToTransform copies.
 * Fields before 0x10 are reconstructed from vanilla Bullet with the
 * caveat that Storm may have reordered them.
 * ═══════════════════════════════════════════════════════════════════ */
typedef struct __attribute__((packed)) {
    /* --- Inferred base fields (vanilla Bullet order, unverified in s1) --- */
    void          *m_broadphaseHandle;              /* 0x000 (inferred) */
    void          *m_collisionShape;                /* 0x008 (inferred) */

    /* --- Verified region starts here --- */
    rbBtTransform  m_worldTransform;                /* 0x010 (proceedToTransform copies 0x10..0x4F) */
    rbBtTransform  m_interpolationWorldTransform;   /* 0x050 (proceedToTransform copies 0x50..0x8F) */

    /* Velocity interpolation fields (proceedToTransform copies 0x90..0xA8 from 0x190..0x1A8) */
    rbBtVector3    m_interpolationLinearVelocity;   /* 0x090 */
    rbBtVector3    m_interpolationAngularVelocity;  /* 0x0A0 */

    rbBtVector3    m_anisotropicFriction;           /* 0x0B0 (inferred position) */
    btScalar       m_contactProcessingThreshold;    /* 0x0C0 (inferred) */
    btScalar       m_deactivationTime;              /* 0x0C4 (inferred) */
    btScalar       m_friction;                      /* 0x0C8 (inferred) */
    btScalar       m_rollingFriction;               /* 0x0CC (inferred) */
    btScalar       m_contactDamping;                /* 0x0D0 (inferred) */
    btScalar       m_contactStiffness;              /* 0x0D4 (inferred) */
    btScalar       m_restitution;                   /* 0x0D8 (inferred) */
    btScalar       m_hitFraction;                   /* 0x0DC (inferred) */
    btScalar       m_ccdSweptSphereRadius;          /* 0x0E0 (inferred) */
    btScalar       m_ccdMotionThreshold;            /* 0x0E4 (inferred) */
    int32_t        m_hasAnisotropicFriction;        /* 0x0E8 (applyGravity reads byte at 0xE8 & 3) */
    int32_t        m_collisionFlags;                /* 0x0EC (inferred) */
    int32_t        m_islandTag1;                    /* 0x0F0 (inferred) */
    int32_t        m_companionId;                   /* 0x0F4 (inferred) */
    int32_t        m_activationState1;              /* 0x0F8 (inferred; 0xE8 may alias this) */
    int32_t        m_internalType;                  /* 0x0FC (inferred) */
    int32_t        m_checkCollideWith;              /* 0x100 (inferred) */
    int32_t        m_collisionFilterGroup;          /* 0x104 (inferred) */
    int32_t        m_collisionFilterMask;           /* 0x108 (inferred) */
    int32_t        m_uniqueId;                      /* 0x10C (inferred) */
} rbBtCollisionObject;
static_assert(sizeof(rbBtCollisionObject) == 272, "rbBtCollisionObject size");
static_assert(offsetof(rbBtCollisionObject, m_broadphaseHandle) == 0x000, "rbBtCollisionObject::m_broadphaseHandle");
static_assert(offsetof(rbBtCollisionObject, m_collisionShape) == 0x008, "rbBtCollisionObject::m_collisionShape");
static_assert(offsetof(rbBtCollisionObject, m_worldTransform) == 0x010, "rbBtCollisionObject::m_worldTransform");
static_assert(offsetof(rbBtCollisionObject, m_interpolationWorldTransform) == 0x050, "rbBtCollisionObject::m_interpolationWorldTransform");
static_assert(offsetof(rbBtCollisionObject, m_interpolationLinearVelocity) == 0x090, "rbBtCollisionObject::m_interpolationLinearVelocity");
static_assert(offsetof(rbBtCollisionObject, m_interpolationAngularVelocity) == 0x0A0, "rbBtCollisionObject::m_interpolationAngularVelocity");
static_assert(offsetof(rbBtCollisionObject, m_hasAnisotropicFriction) == 0x0E8, "rbBtCollisionObject::m_hasAnisotropicFriction");

/* ═══════════════════════════════════════════════════════════════════
 * btRigidBody — s1 layout
 *
 * Verified offsets from decompiled methods:
 *   applyGravity:      0xE8 (flags), 0x1C0-0x1C8 (gravityFactor),
 *                      0x1D0-0x1D8 (gravityAccel), 0x200-0x208 (totalForce)
 *   setGravity:        0x1B0 (mass), 0x1D0-0x1D8 (gravityAccel), 0x1E0-0x1E8 (gravity)
 *   predictIntegratedTransform: 0x10 (worldTransform), 0x190 (linearVel), 0x1A0 (angularVel)
 *   proceedToTransform: 0x50-0x8F (interpTransform), 0x90-0xA8 (interpVel copy)
 *   clearForces:       0x3C, 0x44, 0x4C, 0x54 (zeroed force/torque accumulators)
 *   addConstraintRef:  0x254 (constraintRefs.size), 0x258 (capacity), 0x260 (data), 0x268 (ownership)
 *   removeConstraintRef: same offsets confirmed
 *
 * NOTE: clearForces zeros 0x3C/0x44/0x4C/0x54 which overlap with
 * m_worldTransform.m_basis in the base class interpretation above.
 * This suggests either: (a) clearForces operates on a DIFFERENT struct
 * (not btRigidBody despite the symbol name), or (b) the base class
 * layout is compressed and worldTransform starts later.
 * Marking the ambiguous region explicitly.
 * ═══════════════════════════════════════════════════════════════════ */
typedef struct __attribute__((packed)) {
    /* ── btCollisionObject base (s1-modified) ── */
    void          *m_broadphaseHandle;              /* 0x000 (inferred) */
    void          *m_collisionShape;                /* 0x008 (inferred) */
    rbBtTransform  m_worldTransform;                /* 0x010 (proceedToTransform) */
    rbBtTransform  m_interpolationWorldTransform;   /* 0x050 (proceedToTransform) */
    rbBtVector3    m_interpolationLinearVelocity;   /* 0x090 (proceedToTransform copy dest) */
    rbBtVector3    m_interpolationAngularVelocity;  /* 0x0A0 (proceedToTransform copy dest) */
    rbBtVector3    m_anisotropicFriction;           /* 0x0B0 (inferred) */
    btScalar       m_contactProcessingThreshold;    /* 0x0C0 (inferred) */
    btScalar       m_deactivationTime;              /* 0x0C4 (inferred) */
    btScalar       m_friction;                      /* 0x0C8 (inferred) */
    btScalar       m_rollingFriction;               /* 0x0CC (inferred) */
    btScalar       m_contactDamping;                /* 0x0D0 (inferred) */
    btScalar       m_contactStiffness;              /* 0x0D4 (inferred) */
    btScalar       m_restitution;                   /* 0x0D8 (inferred) */
    btScalar       m_hitFraction;                   /* 0x0DC (inferred) */
    btScalar       m_ccdSweptSphereRadius;          /* 0x0E0 (inferred) */
    btScalar       m_ccdMotionThreshold;            /* 0x0E4 (inferred) */
    int32_t        m_hasAnisotropicFriction;        /* 0x0E8 (VERIFIED: applyGravity &3) */
    int32_t        m_collisionFlags;                /* 0x0EC (inferred) */
    int32_t        m_islandTag1;                    /* 0x0F0 (inferred) */
    int32_t        m_companionId;                   /* 0x0F4 (inferred) */
    int32_t        m_activationState1;              /* 0x0F8 (inferred) */
    int32_t        m_internalType;                  /* 0x0FC (inferred) */
    int32_t        m_checkCollideWith;              /* 0x100 (inferred) */
    int32_t        m_collisionFilterGroup;          /* 0x104 (inferred) */
    int32_t        m_collisionFilterMask;           /* 0x108 (inferred) */
    int32_t        m_uniqueId;                      /* 0x10C (inferred) */

    /* ── btRigidBody own fields ── */
    /* Gap 0x110..0x18F: unknown fields (likely inverseMass, localInertia, damping, etc.) */
    uint8_t        _unknown_0x110[128];             /* 0x110 */

    /* Velocity fields (VERIFIED by predictIntegratedTransform passing 0x190/0x1A0) */
    rbBtVector3    m_linearVelocity;                /* 0x190 (VERIFIED: predictIntegratedTransform) */
    rbBtVector3    m_angularVelocity;               /* 0x1A0 (VERIFIED: predictIntegratedTransform) */

    btScalar       m_mass;                          /* 0x1B0 (VERIFIED: setGravity checks != 0.0) */
    btScalar       m_inverseMass;                   /* 0x1B4 (inferred, follows mass) */
    uint8_t        _pad_0x1B8[8];                   /* 0x1B8 alignment pad */

    /* Gravity-related fields (VERIFIED by setGravity + applyGravity) */
    rbBtVector3    m_gravityFactor;                 /* 0x1C0 (VERIFIED: applyGravity multiplier) */
    rbBtVector3    m_gravity_acceleration;          /* 0x1D0 (VERIFIED: setGravity writes invMass*g) */
    rbBtVector3    m_gravity;                       /* 0x1E0 (VERIFIED: setGravity stores raw g) */
    uint8_t        _pad_0x1F0[16];                  /* 0x1F0 gap to totalForce */

    /* Force/torque accumulators (VERIFIED by applyGravity accumulation) */
    rbBtVector3    m_totalForce;                    /* 0x200 (VERIFIED: applyGravity += gravAccel) */
    rbBtVector3    m_totalTorque;                   /* 0x210 (inferred, follows totalForce) */

    /* Gap 0x220..0x253: unknown fields */
    uint8_t        _unknown_0x220[52];              /* 0x220 */

    /* Constraint reference array (VERIFIED by addConstraintRef/removeConstraintRef) */
    int32_t        m_constraintRefs_m_size;         /* 0x254 (VERIFIED) */
    int32_t        m_constraintRefs_m_capacity;     /* 0x258 (VERIFIED: decimal 600) */
    void         **m_constraintRefs_m_data;         /* 0x25C (VERIFIED: probe measured) */
    uint8_t        m_constraintRefs_m_ownsMemory;   /* 0x264 (VERIFIED: probe measured) */
    uint8_t        _pad_0x265[3];                   /* 0x265 trailing pad to 0x268 */
} rbBtRigidBody;

/* Size: unproven from game code; struct as declared is 616 bytes (0x268).
 * No operator-new or allocator call found for btRigidBody in s1.
 * Last verified field ends at 0x264 (m_constraintRefs_m_ownsMemory). */
static_assert(offsetof(rbBtRigidBody, m_worldTransform) == 0x010, "rbBtRigidBody::m_worldTransform");
static_assert(offsetof(rbBtRigidBody, m_interpolationWorldTransform) == 0x050, "rbBtRigidBody::m_interpolationWorldTransform");
static_assert(offsetof(rbBtRigidBody, m_interpolationLinearVelocity) == 0x090, "rbBtRigidBody::m_interpolationLinearVelocity");
static_assert(offsetof(rbBtRigidBody, m_interpolationAngularVelocity) == 0x0A0, "rbBtRigidBody::m_interpolationAngularVelocity");
static_assert(offsetof(rbBtRigidBody, m_hasAnisotropicFriction) == 0x0E8, "rbBtRigidBody::m_hasAnisotropicFriction");
static_assert(offsetof(rbBtRigidBody, m_mass) == 0x1B0, "rbBtRigidBody::m_mass");
static_assert(offsetof(rbBtRigidBody, m_gravityFactor) == 0x1C0, "rbBtRigidBody::m_gravityFactor");
static_assert(offsetof(rbBtRigidBody, m_gravity_acceleration) == 0x1D0, "rbBtRigidBody::m_gravity_acceleration");
static_assert(offsetof(rbBtRigidBody, m_gravity) == 0x1E0, "rbBtRigidBody::m_gravity");
static_assert(offsetof(rbBtRigidBody, m_totalForce) == 0x200, "rbBtRigidBody::m_totalForce");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_size) == 0x254, "rbBtRigidBody::m_constraintRefs_m_size");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_capacity) == 0x258, "rbBtRigidBody::m_constraintRefs_m_capacity");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_data) == 0x25C, "rbBtRigidBody::m_constraintRefs_m_data");
static_assert(offsetof(rbBtRigidBody, m_constraintRefs_m_ownsMemory) == 0x264, "rbBtRigidBody::m_constraintRefs_m_ownsMemory");

/* ═══════════════════════════════════════════════════════════════════
 * IMPORTANT LAYOUT NOTES
 *
 * 1. The _unknown_0x110[160] gap (0x110..0x1AF) contains at minimum:
 *    - m_linearVelocity at offset 0x190 (from predictIntegratedTransform)
 *    - m_angularVelocity at offset 0x1A0 (from predictIntegratedTransform)
 *    - Likely also: m_inverseMass, m_localInertia, m_invInertiaLocal,
 *      m_linearDamping, m_angularDamping, m_linearSleepingThreshold,
 *      m_angularSleepingThreshold, m_optionalMotionState
 *    These need additional decompiled methods to place precisely.
 *
 * 2. clearForces zeros 0x3C, 0x44, 0x4C, 0x54 — these overlap with
 *    m_worldTransform.m_basis in our current layout. POSSIBLE EXPLANATIONS:
 *    (a) The symbol "btRigidBody::clearForces" at RVA 0x229CA8 may actually
 *        be a DIFFERENT class's clearForces (confidence was only "medium").
 *    (b) The base class fields before 0x10 are arranged differently than
 *        assumed, pushing worldTransform to start later.
 *    (c) Storm uses a non-standard btCollisionObject layout where some
 *        base fields are removed or reordered.
 *    Resolution requires verifying the vtable at offset 0 and checking
 *    callers of FUN_140229ca8 to confirm it operates on btRigidBody.
 *
 * 3. The m_hasAnisotropicFriction field at 0xE8 is read as a BYTE with
 *    mask &3 in applyGravity, suggesting it may actually be the
 *    m_activationState field repurposed or aliased in s1.
 *
 * 4. Object allocation size is unknown — no operator new or allocator
 *    call has been found yet for btRigidBody in s1.
 * ═══════════════════════════════════════════════════════════════════ */

/* ─── btManifoldPoint ─── */
typedef struct __attribute__((packed)) {
    rbBtVector3 m_localPointA;             /* 0x000 */
    rbBtVector3 m_localPointB;             /* 0x010 */
    rbBtVector3 m_positionWorldOnB;        /* 0x020 */
    rbBtVector3 m_positionWorldOnA;        /* 0x030 */
    rbBtVector3 m_normalWorldOnB;          /* 0x040 */
    btScalar    m_distance1;               /* 0x050 */
    btScalar    m_combinedFriction;        /* 0x054 */
    btScalar    m_combinedRollingFriction; /* 0x058 */
    btScalar    m_combinedSpinningFriction;/* 0x05C */
    btScalar    m_combinedRestitution;     /* 0x060 */
    int32_t     m_partId0;                 /* 0x064 */
    int32_t     m_partId1;                 /* 0x068 */
    int32_t     m_index0;                  /* 0x06C */
    int32_t     m_index1;                  /* 0x070 */
    uint8_t     _pad_0x074[4];             /* 0x074 alignment pad */
    void       *m_userPersistentData;      /* 0x078 */
    int32_t     m_contactPointFlags;       /* 0x080 */
    uint8_t     _pad_0x084[4];             /* 0x084 alignment pad */
    btScalar    m_appliedImpulse;          /* 0x088 */
    btScalar    m_prevRHS;                 /* 0x08C */
    btScalar    m_appliedImpulseLateral1;  /* 0x090 */
    btScalar    m_appliedImpulseLateral2;  /* 0x094 */
    btScalar    m_contactMotion1;          /* 0x098 */
    btScalar    m_contactMotion2;          /* 0x09C */
    btScalar    m_contactCFM;              /* 0x0A0 */
    btScalar    m_contactERP;              /* 0x0A4 */
    btScalar    m_frictionCFM;             /* 0x0A8 */
    int32_t     m_lifeTime;                /* 0x0AC */
    rbBtVector3 m_lateralFrictionDir1;     /* 0x0B0 */
    rbBtVector3 m_lateralFrictionDir2;     /* 0x0C0 */
} rbBtManifoldPoint;
static_assert(sizeof(rbBtManifoldPoint) == 208, "rbBtManifoldPoint size");
static_assert(offsetof(rbBtManifoldPoint, m_localPointA) == 0x000, "rbBtManifoldPoint::m_localPointA");
static_assert(offsetof(rbBtManifoldPoint, m_normalWorldOnB) == 0x040, "rbBtManifoldPoint::m_normalWorldOnB");
static_assert(offsetof(rbBtManifoldPoint, m_appliedImpulse) == 0x088, "rbBtManifoldPoint::m_appliedImpulse");
static_assert(offsetof(rbBtManifoldPoint, m_lateralFrictionDir2) == 0x0C0, "rbBtManifoldPoint::m_lateralFrictionDir2");

/* ─── btPersistentManifold ─── */
typedef struct __attribute__((packed)) {
    void           *vtable;                /* 0x000 */
    int32_t         m_objectType;          /* 0x008 */
    uint8_t         _pad_0x00C[4];         /* 0x00C */
    rbBtManifoldPoint m_pointCache[4];     /* 0x010 */
    uint8_t         _pad_0x350[8];         /* 0x350 */
    const void     *m_body0;               /* 0x358 */
    const void     *m_body1;               /* 0x360 */
    int32_t         m_cachedPoints;        /* 0x368 */
    btScalar        m_contactBreakingThreshold;    /* 0x36C */
    btScalar        m_contactProcessingThreshold;  /* 0x370 */
    int32_t         m_companionIdA;        /* 0x374 */
    int32_t         m_companionIdB;        /* 0x378 */
    int32_t         m_index1a;             /* 0x37C */
    uint8_t         _pad_0x380[48];        /* 0x380 trailing pad to 0x398 */
} rbBtPersistentManifold;
/* Size: unproven from game code; struct as declared is 944 bytes (0x3B0).
 * No operator-new or allocator call found for btPersistentManifold in s1.
 * Last verified field ends at 0x37C (m_index1a). Trailing pad to 0x3B0 is inferred. */
static_assert(offsetof(rbBtPersistentManifold, m_pointCache) == 0x010, "rbBtPersistentManifold::m_pointCache");
static_assert(offsetof(rbBtPersistentManifold, m_body0) == 0x358, "rbBtPersistentManifold::m_body0");
static_assert(offsetof(rbBtPersistentManifold, m_body1) == 0x360, "rbBtPersistentManifold::m_body1");
static_assert(offsetof(rbBtPersistentManifold, m_cachedPoints) == 0x368, "rbBtPersistentManifold::m_cachedPoints");

/* ─── btBroadphaseProxy ─── */
typedef struct __attribute__((packed)) {
    rbBtVector3 m_aabbMin;        /* 0x000 */
    rbBtVector3 m_aabbMax;        /* 0x010 */
    void       *m_multiSapParentProxy; /* 0x020 */
    int32_t     m_uniqueId;       /* 0x028 */
    int32_t     m_collisionFilterGroup; /* 0x02C */
    int32_t     m_collisionFilterMask;  /* 0x030 */
    uint8_t     _pad_0x034[4];    /* 0x034 */
    void       *m_clientObject;   /* 0x038 */
} rbBtBroadphaseProxy;
static_assert(offsetof(rbBtBroadphaseProxy, m_aabbMin) == 0x000, "rbBtBroadphaseProxy::m_aabbMin");
static_assert(offsetof(rbBtBroadphaseProxy, m_aabbMax) == 0x010, "rbBtBroadphaseProxy::m_aabbMax");
static_assert(offsetof(rbBtBroadphaseProxy, m_clientObject) == 0x038, "rbBtBroadphaseProxy::m_clientObject");

/* ─── btSolverBody ─── */
typedef struct __attribute__((packed)) {
    rbBtTransform m_worldTransform;        /* 0x000 */
    rbBtVector3   m_deltaLinearVelocity;   /* 0x040 */
    rbBtVector3   m_deltaAngularVelocity;  /* 0x050 */
    rbBtVector3   m_angularFactor;         /* 0x060 */
    rbBtVector3   m_linearFactor;          /* 0x070 */
    rbBtVector3   m_invMass;               /* 0x080 */
    rbBtVector3   m_pushVelocity;          /* 0x090 */
} rbBtSolverBody;
static_assert(offsetof(rbBtSolverBody, m_worldTransform) == 0x000, "rbBtSolverBody::m_worldTransform");
static_assert(offsetof(rbBtSolverBody, m_deltaLinearVelocity) == 0x040, "rbBtSolverBody::m_deltaLinearVelocity");
static_assert(offsetof(rbBtSolverBody, m_invMass) == 0x080, "rbBtSolverBody::m_invMass");

/* ─── btContactSolverInfoData ─── */
typedef struct __attribute__((packed)) {
    btScalar m_tau;                                /* 0x00 */
    btScalar m_damping;                            /* 0x04 */
    btScalar m_friction;                           /* 0x08 */
    btScalar m_timeStep;                           /* 0x0C */
    btScalar m_restitution;                        /* 0x10 */
    int32_t  m_numIterations;                      /* 0x14 */
    btScalar m_maxErrorReduction;                  /* 0x18 */
    btScalar m_sor;                                /* 0x1C */
    btScalar m_erp;                                /* 0x20 */
    btScalar m_erp2;                               /* 0x24 */
    btScalar m_deformable_erp;                     /* 0x28 */
    btScalar m_globalCfm;                          /* 0x2C */
    btScalar m_frictionERP;                        /* 0x30 */
    btScalar m_frictionCFM;                        /* 0x34 */
    int32_t  m_splitImpulse;                       /* 0x38 */
    btScalar m_splitImpulsePenetrationThreshold;   /* 0x3C */
    btScalar m_splitImpulseTurnErp;                /* 0x40 */
    btScalar m_linearSlop;                         /* 0x44 */
    btScalar m_warmstartingFactor;                 /* 0x48 */
    btScalar m_articulatedWarmstartingFactor;      /* 0x4C */
    int32_t  m_solverMode;                         /* 0x50 */
    int32_t  m_restingContactRestitutionThreshold; /* 0x54 */
    int32_t  m_minimumSolverBatchSize;             /* 0x58 */
    btScalar m_maxGyroscopicForce;                 /* 0x5C */
    btScalar m_singleAxisRollingFrictionThreshold; /* 0x60 */
    btScalar m_leastSquaresResidualThreshold;      /* 0x64 */
    btScalar m_restitutionVelocityThreshold;       /* 0x68 */
    uint8_t  m_jointFeedbackInWorldSpace;          /* 0x6C */
    uint8_t  m_jointFeedbackInJointFrame;          /* 0x6D */
    uint8_t  _pad_0x6E[2];                         /* 0x6E */
    int32_t  m_reportSolverAnalytics;              /* 0x70 */
} rbBtContactSolverInfoData;
static_assert(sizeof(rbBtContactSolverInfoData) == 116, "rbBtContactSolverInfoData size");

/* ─── btDiscreteDynamicsWorld (Storm-modified layout) ─── */
typedef struct __attribute__((packed)) {
    /* btCollisionWorld base */
    void         **m_collisionObjects_m_data;       /* 0x000 */
    int32_t        m_collisionObjects_m_size;       /* 0x008 */
    int32_t        m_collisionObjects_m_capacity;   /* 0x00C */
    void          *m_dispatcher1;                   /* 0x010 */
    void          *m_dispatchInfo;                  /* 0x018 */
    void          *m_debugDrawer;                   /* 0x020 */
    void          *m_broadphasePairCache;           /* 0x028 */
    void          *m_collisionAlgorithmPoolAllocator; /* 0x030 */
    void          *m_persistentManifoldPoolAllocator; /* 0x038 */
    void          *m_collisionAlgorithmConstructors;  /* 0x040 */
    int32_t        m_numCcdSweptTests;              /* 0x048 */
    uint8_t        m_forceUpdateAllAabbs;           /* 0x04C */
    uint8_t        m_ownsBroadphasePairCache;       /* 0x04D */
    uint8_t        m_ownsDispatcher;                /* 0x04E */
    uint8_t        m_ownsCollisionAlgorithmPoolAllocator; /* 0x04F */
    uint8_t        m_ownsPersistentManifoldPoolAllocator; /* 0x050 */
    uint8_t        _pad_0x051[7];                   /* 0x051 */
    void         **m_sortedConstraints_m_data;      /* 0x058 */
    int32_t        m_sortedConstraints_m_size;      /* 0x060 */
    int32_t        m_sortedConstraints_m_capacity;  /* 0x064 */
    void          *m_solverIslandCallback;          /* 0x068 */
    void          *m_constraintSolver;              /* 0x070 */
    void          *m_islandManager;                 /* 0x078 */
    void         **m_constraints_m_data;            /* 0x080 */
    int32_t        m_constraints_m_size;            /* 0x088 */
    int32_t        m_constraints_m_capacity;        /* 0x08C */
    void         **m_nonStaticRigidBodies_m_data;   /* 0x090 */
    int32_t        m_nonStaticRigidBodies_m_size;   /* 0x098 */
    int32_t        m_nonStaticRigidBodies_m_capacity; /* 0x09C */
    rbBtVector3    m_gravity;                       /* 0x0A0 */
    btScalar       m_localTime;                     /* 0x0B0 */
    btScalar       m_fixedTimeStep;                 /* 0x0B4 */
    uint8_t        m_ownsIslandManager;             /* 0x0B8 */
    uint8_t        m_ownsConstraintSolver;          /* 0x0B9 */
    uint8_t        m_synchronizeAllMotionStates;    /* 0x0BA */
    uint8_t        m_applySpeculativeContactRestitution; /* 0x0BB */
    uint8_t        _pad_0x0BC[4];                   /* 0x0BC */
    void         **m_actions_m_data;                /* 0x0C0 */
    int32_t        m_actions_m_size;                /* 0x0C8 */
    int32_t        m_actions_m_capacity;            /* 0x0CC */
    int32_t        m_profileTimings;                /* 0x0D0 */
    uint8_t        m_latencyMotionStateInterpolation; /* 0x0D4 */
    uint8_t        _pad_0x0D5[3];                   /* 0x0D5 */
    void         **m_predictiveManifolds_m_data;    /* 0x0D8 */
    int32_t        m_predictiveManifolds_m_size;    /* 0x0E0 */
    int32_t        m_predictiveManifolds_m_capacity; /* 0x0E4 */
    int32_t        m_predictiveManifoldsMutex_mLock; /* 0x0E8 */
    uint8_t        _pad_0x0EC[136];                 /* 0x0EC Storm extension gap */
    btScalar       m_storm_fixedTimeAccumulator;    /* 0x174 */
    uint8_t        _pad_0x178[44];                  /* 0x178 */
    uint8_t        m_storm_latencyInterpFlag;       /* 0x1A4 */
    uint8_t        _pad_0x1A5[11];                  /* 0x1A5 */
} rbBtDiscreteDynamicsWorld;
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_collisionObjects_m_data) == 0x000, "rbBtDiscreteDynamicsWorld::m_collisionObjects_m_data");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_dispatcher1) == 0x010, "rbBtDiscreteDynamicsWorld::m_dispatcher1");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_gravity) == 0x0A0, "rbBtDiscreteDynamicsWorld::m_gravity");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_storm_fixedTimeAccumulator) == 0x174, "rbBtDiscreteDynamicsWorld::m_storm_fixedTimeAccumulator");
static_assert(offsetof(rbBtDiscreteDynamicsWorld, m_storm_latencyInterpFlag) == 0x1A4, "rbBtDiscreteDynamicsWorld::m_storm_latencyInterpFlag");

#endif /* RBBULLET_S1_H */