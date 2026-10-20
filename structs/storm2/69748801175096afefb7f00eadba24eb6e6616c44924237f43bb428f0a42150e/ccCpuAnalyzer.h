/*
 * ccCpuAnalyzer — NARUTO STORM 2 (NSUNS2.exe, build s2)
 *
 * STATIC UTILITY CLASS — NOT AN INSTANTIABLE OBJECT.
 *
 * All 63 ccCpuAnalyzer:: methods are static functions that take external
 * pointers (ccPlayer*, ccCpuActionInfo*, ccPlMotAndEventHeader*, etc.) as
 * their parameters. There is no constructor, no destructor, no vtable, and
 * no heap allocation for this class. This matches the s1 finding exactly.
 *
 * Mangled symbols confirm signatures like:
 *   ns2::ccCpuAnalyzer::IsActionGetup(longlong)           — takes ccPlayer*
 *   ns2::ccCpuAnalyzer::GetMemberPtr(undefined8,int)      — dispatch helper
 *   ns2::ccCpuAnalyzer::GetPlayerInfo(undefined8*,longlong*)
 *   ns2::ccCpuAnalyzer::DecodeActionInfo(float*,longlong,int)
 *
 * No ctor/dtor/vtable/operator-new symbols exist for ccCpuAnalyzer in s2.
 * The field at offset 0x854 accessed in IsActionGetup belongs to ccPlayer,
 * not ccCpuAnalyzer.
 *
 * Build:    s2 (NSUNS2.exe)
 * SHA256:   697488011750...
 * Source:   nucc naming + decompiled code inspection
 * Status:   INFERRED (static analysis only)
 */

#ifndef CC_CPU_ANALYZER_S2_H
#define CC_CPU_ANALYZER_S2_H

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
 * Documented static methods (63 distinct RVAs in s2):
 *
 * Action queries (take ccPlayer* or equivalent pointer):
 *   IsActionComboM, IsActionComboS, IsActionDamage, IsActionDodgeBegin,
 *   IsActionDodgeEnd, IsActionDown, IsActionGetup, IsActionGuardHit,
 *   IsActionItem, IsActionJump, IsActionRestrain, IsActionSkill,
 *   IsActionSkillAir, IsActionSmash, IsActionThrow
 *
 * Usability checks:
 *   IsUsableActionAwake, IsUsableActionChakraDash, IsUsableActionCharge,
 *   IsUsableActionComboM, IsUsableActionComboS, IsUsableActionGuard,
 *   IsUsableActionItem, IsUsableActionNinjaMove, IsUsableActionProjectileChakra,
 *   IsUsableActionRecoverAir, IsUsableActionSkill, IsUsableActionSkillAir,
 *   IsUsableActionSkillReinforce, IsUsableActionSupport,
 *   IsUsableActionTeamSkill, IsUsableActionThrow,
 *   IsUsableActionTimingChakraDash, IsUsableActionTimingSkill,
 *   IsUsableActionTimingSkillAir
 *
 * State queries:
 *   IsChakraMax, IsConnectAcceptEnd, IsConnectAcceptTiming, IsHitAttack
 *
 * Info getters (output structs passed as first param):
 *   DecodeActionInfo, GetActionAttrDamage, GetActionInfoAwake,
 *   GetActionInfoComboM, GetActionInfoComboS, GetActionInfoItem,
 *   GetActionInfoProjectile, GetActionInfoProjectileAir,
 *   GetActionInfoSkill, GetActionInfoSkillAir, GetActionInfoSkillObject,
 *   GetActionInfoSupport, GetActionInfoTeamSkill, GetActionInfoThrow,
 *   GetMemberPtr, GetMotion, GetNextActionAnmId, GetNextActionInfoComboM,
 *   GetNextActionInfoComboS, GetNextActionInfoProjectile,
 *   GetNowActionInfo, GetNowActionInfoSkill, GetPlayerInfo
 *
 * Key callers pass ccPlayer* or sub-object pointers, never a ccCpuAnalyzer*.
 */

#endif /* CC_CPU_ANALYZER_S2_H */