/* rbSpatk s4 — NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe) */
/* All layouts INFERRED from static analysis; not runtime-confirmed. */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * ccSpatkMng: ABSENT from build s4.
 * Evidence: sqlite3 query returned 0 symbols matching 'ccSpatkMng::%'.
 * storm_map of all key s1 methods (Ctrl, Begin, Create, Destroy, End, Draw,
 * IsPlay, Close, _WaitRequest, _ChangeProcess) returned unmapped=["s4"] or
 * low-confidence false positives only (Draw->0x41E550 @ 0.537, IsPlay->0x41E550
 * @ 0.591 — same unnamed RVA, not a real mapping). No SpAtk manager class
 * exists in this build. Consistent with s2 and s3 absence.
 */

/*
 * ccSpatkPlayer: ABSENT from build s4.
 * Evidence: sqlite3 query returned 0 symbols matching 'ccSpatkPlayer::%'.
 * storm_map of Ctrl returned nuccParticleNode::DelNode @ 0.548 (low conf,
 * false positive — particle system, not SpAtk). ForcedExit unmapped.
 * No per-player SpAtk state class exists in this build.
 */

/*
 * ccSpatkInput: PARTIALLY PRESENT — exactly 1 symbol (Exit) in build s4.
 * Source: nucc (medium confidence). RVA 0x3E4668, VA 0x1403E4668.
 * The decompiled Exit method reveals instance state via longlong* param_1
 * indexing, but no other methods are named, so size cannot be proven from
 * operator new/allocator/ctor/factory/array stride. Only field offsets
 * observed in Exit are documented below.
 *
 * Field layout inferred from ccSpatkInput::Exit decompile:
 *   param_1 is longlong*, so index N = byte offset N*8.
 *   - vtable pointer at +0x00 (implicit, code calls *(param_1+8) and *(param_1+0x10))
 *   - vfunc[1] call at +0x08 (dtor-like, no args)
 *   - ptr field at longlong index 0x25 = byte offset 0x128 (released via vcall(ptr,1), then nulled)
 *   - ptr field at longlong index 0x26 = byte offset 0x130 (released via vcall(ptr,1), then nulled)
 *   - ptr field at longlong index 0x28 = byte offset 0x140 (released via vcall(ptr,1), then nulled)
 *   - vfunc[2] call at +0x10 (final cleanup, takes param_1)
 *
 * Size unknown, >= 0x148 (last accessed field at 0x140 is a pointer, 8 bytes).
 * No sizeof assert possible without proven size.
 */
typedef struct __attribute__((packed)) ccSpatkInput_s4 {
    /* 0x000 */ void *vtable;                    /* INFERRED: vtable ptr, Exit reads +0 and +0x10 */
    /* 0x008 */ uint8_t _pad_008[0x120];         /* 0x008..0x127: unobserved gap */
    /* 0x128 */ void *field_0x128;               /* INFERRED: longlong[0x25], released in Exit */
    /* 0x130 */ void *field_0x130;               /* INFERRED: longlong[0x26], released in Exit */
    /* 0x138 */ uint8_t _pad_0x138[0x08];        /* 0x138..0x13F: unobserved gap between 0x26 and 0x28 */
    /* 0x140 */ void *field_0x140;               /* INFERRED: longlong[0x28], released in Exit */
    /* 0x148 */                                  /* end of observed fields; size >= 0x148 */
} ccSpatkInput_s4;

static_assert(offsetof(ccSpatkInput_s4, vtable)      == 0x000, "ccSpatkInput_s4.vtable");
static_assert(offsetof(ccSpatkInput_s4, _pad_008)    == 0x008, "ccSpatkInput_s4._pad_008");
static_assert(offsetof(ccSpatkInput_s4, field_0x128) == 0x128, "ccSpatkInput_s4.field_0x128");
static_assert(offsetof(ccSpatkInput_s4, field_0x130) == 0x130, "ccSpatkInput_s4.field_0x130");
static_assert(offsetof(ccSpatkInput_s4, _pad_0x138)  == 0x138, "ccSpatkInput_s4._pad_0x138");
static_assert(offsetof(ccSpatkInput_s4, field_0x140) == 0x140, "ccSpatkInput_s4.field_0x140");