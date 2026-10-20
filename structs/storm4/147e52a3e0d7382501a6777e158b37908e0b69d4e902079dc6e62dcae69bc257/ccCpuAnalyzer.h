/*
 * ccCpuAnalyzer — NARUTO STORM 4 (NSUNS4_release.exe, build s4, v1.09)
 *
 * STATIC UTILITY CLASS — NOT AN INSTANTIABLE OBJECT.
 *
 * All 51 ccCpuAnalyzer:: methods are static functions that take external
 * pointers (ccPlayer*, output structs, etc.) as their parameters. There is
 * no constructor, no destructor, no vtable, and no heap allocation for
 * this class. This matches the s1, s2, and s3 findings exactly.
 *
 * Decompiled signatures confirm:
 *   ccCpuAnalyzer::IsUsableActionSkill(longlong *param_1)    — param_1 is ccPlayer*
 *     accesses ccPlayer vtable at +0xc08, +0x1398, +0xd08; calls ccPlayer::GetConditionFunc
 *   ccCpuAnalyzer::GetPlayerInfo(undefined8* out, longlong* player)
 *   ccCpuAnalyzer::DecodeActionInfo(float* out, longlong, int)
 *   ccCpuAnalyzer::GetMemberPtr(undefined8, int)             — dispatch helper
 *
 * No ctor/dtor/vtable/operator-new symbols exist for ccCpuAnalyzer in s4.
 * The state_surface accesses on param_1 belong to ccPlayer (the external
 * pointer passed to these static methods), not to a ccCpuAnalyzer instance.
 *
 * Build:    s4 (NSUNS4_release.exe)
 * SHA256:   147e52a3e0d7...
 * Source:   nucc naming + decompiled code inspection
 * Status:   INFERRED (static analysis only)
 */

#ifndef CC_CPU_ANALYZER_S4_H
#define CC_CPU_ANALYZER_S4_H

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
 * Documented static methods (51 distinct RVAs in s4):
 *
 * Action queries (take ccPlayer* or equivalent pointer):
 *   IsActionComboS, IsActionDamage, IsActionDashFront, IsActionDodgeBegin,
 *   IsActionDown, IsActionGetup, IsActionGuardHit, IsActionJump,
 *   IsActionNinjaMove, IsActionSkill, IsActionSkillAir, IsActionThrow
 *
 * Usability checks:
 *   IsUsableActionChakraDash, IsUsableActionCharge, IsUsableActionGuard,
 *   IsUsableActionItem, IsUsableActionNinjaMove, IsUsableActionRecoverAir,
 *   IsUsableActionSkill, IsUsableActionSkillAir, IsUsableActionSkillReinforce,
 *   IsUsableActionSupport (x2 overloads), IsUsableActionTeamSkill,
 *   IsUsableActionThrow, IsUsableActionTimingChakraDash,
 *   IsUsableActionTimingSkill, IsUsableActionTimingSkillAir
 *
 * State queries:
 *   IsChakraMax, IsConnectAcceptEnd, IsConnectAcceptTiming, IsHitAttack
 *
 * Info getters (output structs passed as first param):
 *   DecodeActionInfo, GetActionAttrDamage, GetActionInfoAwake,
 *   GetActionInfoItem, GetActionInfoProjectileChakra,
 *   GetActionInfoSkill, GetActionInfoSkillAir, GetActionInfoSkillObject,
 *   GetActionInfoSupport, GetActionInfoTeamSkill, GetActionInfoThrow,
 *   GetMemberPtr, GetMotion, GetNextActionAnmId,
 *   GetNextActionInfoComboM, GetNextActionInfoProjectile (x2 overloads),
 *   GetNowActionInfo, GetPlayerInfo
 *
 * Key callers pass ccPlayer* or sub-object pointers, never a ccCpuAnalyzer*.
 */

#endif /* CC_CPU_ANALYZER_S4_H */