/*
 * ccCpuAnalyzer — NARUTO STORM 1 (NSUNS1.exe, build s1)
 *
 * STATIC UTILITY CLASS — NOT AN INSTANTIABLE OBJECT.
 *
 * All ccCpuAnalyzer methods are static functions that take a ccPlayer* (or
 * related pointer) as their first argument. There is no constructor, no
 * destructor, no vtable, and no heap allocation for this class. The mangled
 * symbols confirm signatures like:
 *
 *   ns2::ccCpuAnalyzer::IsActionGetup(ns2::ccPlayer*)
 *   ns2::ccCpuAnalyzer::IsConnectAcceptEnd(ns2::ccPlayer*)
 *   ns2::ccCpuAnalyzer::DecodeActionInfo(ccCpuActionInfo*, const ccPlMotAndEventHeader*, int)
 *   ns2::ccCpuAnalyzer::GetPlayerInfo(ccCpuPlayerInfo*, ccPlayerLeader*)
 *
 * The nucc naming assigned "ccCpuAnalyzer::" to these functions at low
 * confidence; the mangled names confirm the class exists but only as a
 * namespace for static CPU-AI helper functions.
 *
 * No struct layout is possible because there is no object. The field at
 * offset 0x10D0 accessed in IsActionGetup belongs to ccPlayer, not
 * ccCpuAnalyzer.
 *
 * Build:    s1 (NSUNS1.exe)
 * SHA256:   10231093af9cbda329d5cf3b7ba5a146ad523799331f52c3c3929b785d7f63ba
 * Source:   nucc (low confidence), verified via mangled symbol demangling
 * Status:   INFERRED (static analysis only)
 */

#ifndef CC_CPU_ANALYZER_S1_H
#define CC_CPU_ANALYZER_S1_H

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
 * Documented static methods (RVA in s1):
 *
 *   0x1966B4  ccCpuAnalyzer::IsConnectAcceptEnd(ccPlayer*)
 *   0x31FF30  ccCpuAnalyzer::IsActionGetup(ccPlayer*)
 *
 * Additional methods exist at other RVAs (import thunks, duplicate mappings)
 * but resolve to the same two unique function bodies in s1. See REPORT.md
 * for the full list of ~100+ named entries across all builds.
 *
 * Key callers (all pass ccPlayer* or ccCpuPlayer sub-object pointers):
 *   FUN_140191ad4          — passes *(param_1 + 0x290) as ccPlayer*
 *   ccCpuPlayer::CtrlAct_ATTACK_COMBO_2 — passes *(param_1 + 0x10) as ccPlayer*
 *   ccPlayer::IsRequestActAtkDownOk     — passes GetActionTargetAsPlayerPtr() result
 */

#endif /* CC_CPU_ANALYZER_S1_H */