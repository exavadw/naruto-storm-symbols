/* rbFighter struct group for NARUTO STORM 1 (NSUNS1.exe, build s1)
 * Classes: ccPlayerLeader, ccPlayerSupport, ccPlayerPartner, ccPlayerGrp, ccPlayerTeamMng
 * All fields INFERRED from static analysis (state_surface + decompilation), not CONFIRMED.
 * Layout VERIFIED via compile-time offsetof checks against proven allocator sizes.
 *
 * Base class: ccPlayer (0x1830 bytes) — see ccPlayer.h
 * Subclass sizes PROVEN from allocator calls (FUN_14047ed10 = operator new):
 *   ccPlayerLeader:  0x1908 (FUN_140350524 -> FUN_14047ed10(0x1908, "source\\playerLeader.cpp", 0x13ca))
 *   ccPlayerSupport: 0x1890 (FUN_1403835F8 -> FUN_14047ed10(0x1890, "source\\playerSupport.cpp", 0x351))
 *   ccPlayerPartner: absent from s1 (no NewPlayer symbol found)
 *   ccPlayerGrp:     no instance state (container/logic class)
 *   ccPlayerTeamMng: no instance state (manager class)
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#pragma pack(push, 1)

/* ============================================================
 * ccPlayerLeader — extends ccPlayer (0x1830), total size 0x1908
 * Proven: FUN_140350524 allocates 0x1908 via FUN_14047ed10
 * Constructor: FUN_140349930
 * Vtable: PTR_FUN_1406d1f08 (set in ctor)
 * ============================================================ */
typedef struct {
    /* --- ccPlayer base (0x0000..0x182F) --- */
    uint8_t ccPlayer_base[0x1830];

    /* --- ccPlayerLeader subclass fields (0x1830..0x1907) --- */
    uint64_t input_pad_state;      /* 0x1830 sz=8  r  CtrlInputPad */
    uint32_t tension_timer;        /* 0x1838 sz=4  r  CtrlTension */
    uint8_t  _pad_183C[12];        /* 0x183C..0x1847 */
    uint32_t counter_flags;        /* 0x1848 sz=4  rw CtrlCounter */
    uint32_t counter_cooldown;     /* 0x184C sz=4  w  CtrlCounter */
    uint32_t counter_state;        /* 0x1850 sz=4  w  CtrlCounter */
    uint8_t  _pad_1854[4];         /* 0x1854..0x1857 */
    uint32_t counter_charge;       /* 0x1858 sz=4  rw CtrlCounter */
    uint8_t  _pad_185C[4];         /* 0x185C..0x185F */
    uint64_t chakra_load_ptr;      /* 0x1860 sz=8  r  CtrlCounter/IsLoadChakraOk */
    uint8_t  _pad_1868[8];         /* 0x1868..0x186F */
    uint64_t counter_target;       /* 0x1870 sz=8  r  CtrlCounter */
    uint32_t tension_gauge_1;      /* 0x1878 sz=4  w  CtrlTension (ctor init) */
    uint32_t tension_gauge_2;      /* 0x187C sz=4  w  ctor init 0x42c80000 */
    uint32_t tension_level;        /* 0x1880 sz=4  rw CtrlTension */
    uint32_t tension_active;       /* 0x1884 sz=4  w  CtrlTension */
    uint32_t tension_mode;         /* 0x1888 sz=4  w  CtrlTension */
    uint32_t tension_state;        /* 0x188C sz=4  w  CtrlTension */
    uint32_t tension_counter;      /* 0x1890 sz=4  rw CtrlTension */
    uint32_t tension_decay;        /* 0x1894 sz=4  w  CtrlTension */
    uint32_t tension_flags;        /* 0x1898 sz=4  w  CtrlTension */
    uint64_t tension_params;       /* 0x189C sz=8  w  CtrlTension */
    uint32_t tension_threshold;    /* 0x18A4 sz=4  rw CtrlTension */
    uint8_t  _pad_18A8[20];        /* 0x18A8..0x18BB (timer obj embedded) */
    uint32_t pad_input_slot_0;     /* 0x18BC sz=4  r  CtrlInputPad array[0] */
    uint64_t pad_input_slot_1;     /* 0x18C0 sz=8  r  CtrlInputPad array[1] */
    uint32_t pad_input_slot_2;     /* 0x18C8 sz=4  r  CtrlInputPad array[2] */
    uint64_t pad_input_slot_3;     /* 0x18CC sz=8  r  CtrlInputPad array[3] */
    uint32_t pad_input_slot_4;     /* 0x18D4 sz=4  r  CtrlInputPad */
    uint64_t pad_input_slot_5;     /* 0x18D8 sz=8  r  CtrlInputPad */
    uint32_t pad_input_slot_6;     /* 0x18E0 sz=4  r  CtrlInputPad */
    uint64_t pad_input_slot_7;     /* 0x18E4 sz=8  r  CtrlInputPad */
    uint32_t item_attack_state;    /* 0x18EC sz=4  rw CtrlAct_USE_ITEM_ATK */
    uint32_t counter_result;       /* 0x18F0 sz=4  w  CtrlCounter */
    uint8_t  _pad_18F4[4];         /* 0x18F4..0x18F7 */
    uint32_t counter_chain;        /* 0x18F8 sz=4  rw CtrlCounter */
    uint32_t awake_gauge;          /* 0x18FC sz=4  rw CtrlAwakeGauge/IsChargeAwakeOk */
    uint32_t awake_charge_state;   /* 0x1900 sz=4  rw CtrlAct_AWAKE_CHARGE/CtrlAwakeGauge */
    uint8_t  _pad_1904[4];         /* 0x1904..0x1907 tail padding to 0x1908 */
} ccPlayerLeader;

static_assert(sizeof(ccPlayerLeader) == 0x1908, "ccPlayerLeader size must be 0x1908");
static_assert(offsetof(ccPlayerLeader, input_pad_state)    == 0x1830, "input_pad_state offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_timer)      == 0x1838, "tension_timer offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_flags)      == 0x1848, "counter_flags offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_cooldown)   == 0x184C, "counter_cooldown offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_state)      == 0x1850, "counter_state offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_charge)     == 0x1858, "counter_charge offset mismatch");
static_assert(offsetof(ccPlayerLeader, chakra_load_ptr)    == 0x1860, "chakra_load_ptr offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_target)     == 0x1870, "counter_target offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_gauge_1)    == 0x1878, "tension_gauge_1 offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_gauge_2)    == 0x187C, "tension_gauge_2 offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_level)      == 0x1880, "tension_level offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_active)     == 0x1884, "tension_active offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_mode)       == 0x1888, "tension_mode offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_state)      == 0x188C, "tension_state offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_counter)    == 0x1890, "tension_counter offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_decay)      == 0x1894, "tension_decay offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_flags)      == 0x1898, "tension_flags offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_params)     == 0x189C, "tension_params offset mismatch");
static_assert(offsetof(ccPlayerLeader, tension_threshold)  == 0x18A4, "tension_threshold offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_0)   == 0x18BC, "pad_input_slot_0 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_1)   == 0x18C0, "pad_input_slot_1 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_2)   == 0x18C8, "pad_input_slot_2 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_3)   == 0x18CC, "pad_input_slot_3 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_4)   == 0x18D4, "pad_input_slot_4 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_5)   == 0x18D8, "pad_input_slot_5 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_6)   == 0x18E0, "pad_input_slot_6 offset mismatch");
static_assert(offsetof(ccPlayerLeader, pad_input_slot_7)   == 0x18E4, "pad_input_slot_7 offset mismatch");
static_assert(offsetof(ccPlayerLeader, item_attack_state)  == 0x18EC, "item_attack_state offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_result)     == 0x18F0, "counter_result offset mismatch");
static_assert(offsetof(ccPlayerLeader, counter_chain)      == 0x18F8, "counter_chain offset mismatch");
static_assert(offsetof(ccPlayerLeader, awake_gauge)        == 0x18FC, "awake_gauge offset mismatch");
static_assert(offsetof(ccPlayerLeader, awake_charge_state) == 0x1900, "awake_charge_state offset mismatch");

/* ============================================================
 * ccPlayerSupport — extends ccPlayer (0x1830), total size 0x1890
 * Proven: FUN_1403835F8 allocates 0x1890 via FUN_14047ed10
 * Constructor: FUN_1403822a4
 * Only 1 subclass field found at >= 0x1830 via state_surface.
 * Additional fields at 0x1214, 0x1250, 0x1254, 0x173C, 0x17C4, 0x17DC, 0x17E4
 * are within the ccPlayer base range and handled there.
 * ============================================================ */
typedef struct {
    /* --- ccPlayer base (0x0000..0x182F) --- */
    uint8_t ccPlayer_base[0x1830];

    /* --- ccPlayerSupport subclass fields (0x1830..0x188F) --- */
    uint8_t  _pad_1830[92];        /* 0x1830..0x188B (no surface fields found) */
    uint32_t sup_exit_flag;        /* 0x188C sz=4  r  CtrlAct_SUP_EXIT */
} ccPlayerSupport;

static_assert(sizeof(ccPlayerSupport) == 0x1890, "ccPlayerSupport size must be 0x1890");
static_assert(offsetof(ccPlayerSupport, sup_exit_flag) == 0x188C, "sup_exit_flag offset mismatch");

/* ============================================================
 * ccPlayerPartner — ABSENT from s1
 * No NewPlayer symbol, no methods found in s1 symbol table.
 * This class exists in later builds (s2/s3/s4) but not Storm 1.
 * ============================================================ */
/* no instance state — class absent from s1 build */

/* ============================================================
 * ccPlayerGrp — no proven instance state in s1
 * Methods exist (BeginDirection, IsWallMode, etc.) but state_surface
 * returned only 1 field (below 0x1830, part of base or unrelated).
 * Likely a logic/container class operating on external player objects.
 * Size unknown, >= 0x0 (no allocation found).
 * ============================================================ */
/* no instance state proven — container/logic class */

/* ============================================================
 * ccPlayerTeamMng — no proven instance state in s1
 * Manager class (CreateTeams, GetMemberPtr, etc.). state_surface
 * returned only 1 field (below 0x1830). Operates on global/team data.
 * Size unknown, >= 0x0 (no allocation found).
 * ============================================================ */
/* no instance state proven — manager class */

#pragma pack(pop)