/*
 * ccCpuAnalyzer — NARUTO STORM 3 Full Burst HD (NSUNS3.exe, build s3)
 *
 * STATIC UTILITY CLASS — NOT AN INSTANTIABLE OBJECT.
 *
 * All 54 ccCpuAnalyzer:: methods are static functions that take external
 * pointers (ccPlayer*, output structs, etc.) as their parameters. There is
 * no constructor, no destructor, no vtable, and no heap allocation for
 * this class. This matches the s1 and s2 findings exactly.
 *
 * Decompiled signatures confirm:
 *   ccCpuAnalyzer::IsActionGetup(longlong param_1)         — takes ccPlayer*
 *   ccCpuAnalyzer::GetPlayerInfo(undefined8* out, longlong* player)
 *   ccCpuAnalyzer::DecodeActionInfo(float* out, longlong, int)
 *   ccCpuAnalyzer::GetMemberPtr(undefined8, int)           — dispatch helper
 *
 * No ctor/dtor/vtable/operator-new symbols exist for ccCpuAnalyzer in s3.
 * The large-offset accesses (0x34C0, 0x45C0, etc.) seen in state_surface
 * belong to ccPlayer (param_2 in GetPlayerInfo, param_1 in IsUsable*),
 * not to ccCpuAnalyzer.
 *
 * Build:    s3 (NSUNS3.exe)
 * SHA256:   55b726e94dad...
 * Source:   nucc naming + decompiled code inspection
 * Status:   INFERRED (static analysis only)
 */

#ifndef CC_CPU_ANALYZER_S3_H
#define CC_CPU_ANALYZER_S3_H

#include <stdint.h>

/*
 * ccCpuAnalyzer has no instance state. This empty struct exists only so that
 * downstream code can reference the type name; it must never be instantiated.
 */
typedef struct ccCpuAnalyzer {
    /* No fields. Static utility class. */
    uint8_t _unused; /* prevent zero-size struct warning in C11 */
} ccCpuAnalyzer;

/*
 * Documented static methods (54 distinct RVAs in s3):
 *
 * Action queries (take ccPlayer* or equivalent pointer):
 *   IsActionCharge, IsActionComboS, IsActionDamage, IsActionDashFront,
 *   IsActionDodgeBegin, IsActionDown, IsActionGetup, IsActionGuardHit,
 *   IsActionItem, IsActionNinjaMove, IsActionProjectileMove, IsActionSkill,
 *   IsActionThrow
 *
 * Usability checks:
 *   IsUsableActionAwake, IsUsableActionChakraDash, IsUsableActionCharge,
 *   IsUsableActionComboS, IsUsableActionGuard, IsUsableActionItem,
 *   IsUsableActionNinjaMove, IsUsableActionProjectileChakra,
 *   IsUsableActionRecoverAir, IsUsableActionSkill, IsUsableActionSkillAir,
 *   IsUsableActionSkillReinforce, IsUsableActionSupport,
 *   IsUsableActionTeamSkill, IsUsableActionTimingChakraDash,
 *   IsUsableActionTimingSkill, IsUsableActionTimingSkillAir
 *
 * State queries:
 *   IsCanStartAwakeToThinkType, IsChakraMax, IsConnectAcceptEnd,
 *   IsConnectAcceptTiming, IsHitAttack, IsLifeMax
 *
 * Info getters (output structs passed as first param):
 *   DecodeActionInfo, GetActionAttrDamage, GetActionInfoAwake,
 *   GetActionInfoItem, GetActionInfoProjectileChakra (x2),
 *   GetActionInfoSkill, GetActionInfoSkillObject, GetActionInfoSupport,
 *   GetActionInfoTeamSkill, GetMemberPtr, GetMotion, GetNextActionAnmId,
 *   GetNextActionInfoComboM, GetNextActionInfoProjectile (x2),
 *   GetNowActionInfo, GetPlayerInfo
 *
 * Key callers pass ccPlayer* or sub-object pointers, never a ccCpuAnalyzer*.
 */

#endif /* CC_CPU_ANALYZER_S3_H */