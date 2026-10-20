#ifndef CC_CPU_PLAYER_S4_H
#define CC_CPU_PLAYER_S4_H

#include <stdint.h>
#include <stddef.h>

/* NARUTO STORM 4 PC 1.09 (NSUNS4_release.exe) — ccCpuPlayer struct layout.
 * All fields INFERRED from static analysis of Ghidra decompilation, not CONFIRMED at runtime.
 * Allocation size 0x1AC0 proven from operator_new in factory wrappers @ RVA 0x283d44 / 0x28cc40.
 * Cross-referenced with s3 header (~/storm-structs/s3/ccCpuPlayer.h, size 0x1438).
 */

#ifndef NUCC_VECTOR3_DEFINED
#define NUCC_VECTOR3_DEFINED
typedef struct { float x; float y; float z; } Nucc_Vector3;
#endif

/* Sub-object initialized by FUN_140a0d810 in ctor; 0x40 bytes per instance. */
typedef struct __attribute__((packed)) ccCpuPlayer_subobj_a0d810_s4 {
    uint8_t data[0x40];
} ccCpuPlayer_subobj_a0d810_s4;

/* Action entry: 0x28 bytes each, 44 entries in ctor loop. */
typedef struct __attribute__((packed)) ccCpuPlayer_action_entry_s4 {
    uint64_t field_00;
    uint64_t field_08;
    uint64_t field_10;
    uint32_t field_18;
    uint32_t field_1c;
    uint64_t field_20;
} ccCpuPlayer_action_entry_s4;

/* Situation entry at 0x1830: 7 entries of 0x30 bytes each. */
typedef struct __attribute__((packed)) ccCpuPlayer_situation_entry_s4 {
    uint64_t vtable;
    uint64_t field_08;
    uint64_t field_10;
    uint64_t field_18;
    uint64_t field_20;
    uint64_t field_28;
} ccCpuPlayer_situation_entry_s4;

typedef struct __attribute__((packed)) ccCpuPlayer_s4 {
    /* 0x000 */ uint64_t vtable;                          /* ctor: PTR_FUN_1410a5658 */
    /* 0x008 */ uint8_t  pad_008[8];
    /* 0x010 */ uint32_t unk_010;
    /* 0x014 */ uint32_t unk_014;
    /* 0x018 */ int32_t  player_id;                       /* ctor: -1 */
    /* 0x01C */ uint32_t unk_01c;
    /* 0x020 */ uint64_t unk_020;                         /* ctor: 0 */
    /* 0x028 */ uint64_t unk_028;                         /* ctor: 0 */
    /* 0x030 */ uint8_t  subobj_030[0xC0];                /* ctor: FUN_1407c0294 */
    /* 0x0F0 */ uint8_t  base_class_data[0x600];          /* base class timers/cooldowns/AI/cache */
    /* 0x6F0 */ int32_t  think_action_idx;                /* ctor: 0; CtrlThink reads */
    /* 0x6F4 */ uint32_t pad_6f4;
    /* 0x6F8 */ float    timer_accum;                     /* ctor: 0.0f; Update +=1.0 */
    /* 0x6FC */ uint32_t pad_6fc;
    /* 0x700 */ int32_t  think_mode;                      /* ctor: 0; CtrlThink checks ==1 */
    /* 0x704 */ uint32_t pad_704;
    /* 0x708 */ uint8_t  subobj_708[0x58];                /* ctor: FUN_1407322dc */
    /* 0x760 */ ccCpuPlayer_subobj_a0d810_s4 subobj_760;  /* ctor: FUN_140a0d810 */
    /* 0x7A0 */ ccCpuPlayer_subobj_a0d810_s4 subobj_7a0;  /* ctor: FUN_140a0d810 */
    /* 0x7E0 */ ccCpuPlayer_subobj_a0d810_s4 subobj_7e0;  /* ctor: FUN_140a0d810 */
    /* 0x820 */ ccCpuPlayer_subobj_a0d810_s4 subobj_820;  /* ctor: FUN_140a0d810 */
    /* 0x860 */ ccCpuPlayer_subobj_a0d810_s4 subobj_860;  /* ctor: FUN_140a0d810 */
    /* 0x8A0 */ ccCpuPlayer_subobj_a0d810_s4 subobj_8a0;  /* ctor: FUN_140a0d810 */
    /* 0x8E0 */ ccCpuPlayer_subobj_a0d810_s4 subobj_8e0;  /* ctor: FUN_140a0d810 */
    /* 0x920 */ ccCpuPlayer_subobj_a0d810_s4 subobj_920;  /* ctor: FUN_140a0d810 */
    /* 0x960 */ uint8_t  situation_data_960[0x2C];        /* ctor: FUN_140a046f0 */
    /* 0x98C */ uint8_t  situation_data_98c[0x2C];        /* ctor: FUN_140a046f0 */
    /* 0x9B8 */ uint8_t  pad_9b8[4];
    /* 0x9BC */ ccCpuPlayer_action_entry_s4 action_entries[44]; /* 44*0x28=0x6E0 */
    /* 0x109C */ uint8_t gap_109c[0x6DC];                 /* unaccessed by base methods */
    /* 0x1778 */ uint32_t unk_1778;                       /* UpdateSituation: zeroed */
    /* 0x177C */ int32_t  nearest_type;                   /* UpdateSituation: -1 */
    /* 0x1780 */ uint32_t pad_1780;
    /* 0x1784 */ int64_t  nearest_id_1784;                /* UpdateSituation: -1 */
    /* 0x178C */ int64_t  nearest_id_178c;                /* UpdateSituation: -1 */
    /* 0x1794 */ int64_t  nearest_id_1794;                /* UpdateSituation: -1 */
    /* 0x179C */ float    distance;                       /* UpdateSituation: float3 Length */
    /* 0x17A0 */ float    support_dists[8];               /* UpdateSituation: packed floats */
    /* 0x17C0 */ float    leader_distance;                /* UpdateSituation */
    /* 0x17C4 */ uint32_t pad_17c4;
    /* 0x17C8 */ uint64_t list_head;                      /* std::list node ptr */
    /* 0x17D0 */ uint64_t list_sentinel;                  /* 0x492492492492491 */
    /* 0x17D8 */ uint64_t list_size;
    /* 0x17E0 */ uint8_t  pad_17e0[16];
    /* 0x17F0 */ uint32_t list_flags;                     /* UpdateSituation: OR'd flags */
    /* 0x17F4 */ uint32_t pad_17f4;
    /* 0x17F8 */ uint64_t list2_head;
    /* 0x1800 */ uint64_t list2_sentinel;                 /* 0x492492492492491 */
    /* 0x1808 */ uint64_t list2_size;
    /* 0x1810 */ uint8_t  pad_1810[16];
    /* 0x1820 */ uint32_t nearest_enemy_count;            /* UpdateSituation */
    /* 0x1824 */ uint32_t list2_flags;
    /* 0x1828 */ uint32_t max_threat_level;
    /* 0x182C */ uint32_t pad_182c;
    /* 0x1830 */ ccCpuPlayer_situation_entry_s4 situation_entries[7]; /* 7*0x30=0x150 */
    /* 0x1980 */ uint8_t  subclass_extension[0x140];      /* to reach 0x1AC0 */
} ccCpuPlayer_s4;

_Static_assert(sizeof(ccCpuPlayer_s4) == 0x1AC0, "ccCpuPlayer_s4 size must be 0x1AC0");
_Static_assert(offsetof(ccCpuPlayer_s4, vtable) == 0x000, "vtable");
_Static_assert(offsetof(ccCpuPlayer_s4, player_id) == 0x018, "player_id");
_Static_assert(offsetof(ccCpuPlayer_s4, think_action_idx) == 0x6F0, "think_action_idx");
_Static_assert(offsetof(ccCpuPlayer_s4, timer_accum) == 0x6F8, "timer_accum");
_Static_assert(offsetof(ccCpuPlayer_s4, think_mode) == 0x700, "think_mode");
_Static_assert(offsetof(ccCpuPlayer_s4, subobj_708) == 0x708, "subobj_708");
_Static_assert(offsetof(ccCpuPlayer_s4, subobj_760) == 0x760, "subobj_760");
_Static_assert(offsetof(ccCpuPlayer_s4, situation_data_960) == 0x960, "situation_data_960");
_Static_assert(offsetof(ccCpuPlayer_s4, situation_data_98c) == 0x98C, "situation_data_98c");
_Static_assert(offsetof(ccCpuPlayer_s4, action_entries) == 0x9BC, "action_entries");
_Static_assert(offsetof(ccCpuPlayer_s4, unk_1778) == 0x1778, "unk_1778");
_Static_assert(offsetof(ccCpuPlayer_s4, nearest_type) == 0x177C, "nearest_type");
_Static_assert(offsetof(ccCpuPlayer_s4, distance) == 0x179C, "distance");
_Static_assert(offsetof(ccCpuPlayer_s4, support_dists) == 0x17A0, "support_dists");
_Static_assert(offsetof(ccCpuPlayer_s4, leader_distance) == 0x17C0, "leader_distance");
_Static_assert(offsetof(ccCpuPlayer_s4, list_head) == 0x17C8, "list_head");
_Static_assert(offsetof(ccCpuPlayer_s4, list_sentinel) == 0x17D0, "list_sentinel");
_Static_assert(offsetof(ccCpuPlayer_s4, list_flags) == 0x17F0, "list_flags");
_Static_assert(offsetof(ccCpuPlayer_s4, list2_head) == 0x17F8, "list2_head");
_Static_assert(offsetof(ccCpuPlayer_s4, list2_sentinel) == 0x1800, "list2_sentinel");
_Static_assert(offsetof(ccCpuPlayer_s4, nearest_enemy_count) == 0x1820, "nearest_enemy_count");
_Static_assert(offsetof(ccCpuPlayer_s4, list2_flags) == 0x1824, "list2_flags");
_Static_assert(offsetof(ccCpuPlayer_s4, max_threat_level) == 0x1828, "max_threat_level");
_Static_assert(offsetof(ccCpuPlayer_s4, situation_entries) == 0x1830, "situation_entries");

#endif /* CC_CPU_PLAYER_S4_H */