/*
 * s3BossFramework.h — Storm 3 (NSUNS3.exe x64) boss-battle struct layouts
 * Build: s3 (sha 55b726e94dad)
 * All fields are INFERRED from static analysis (the decompiler cache state_surface + decomp).
 * Sizes come from FUN_140683f70 allocator calls in Create/factory methods.
 *
 * Classes reconstructed:
 *   ccBossBattleSituationVoice  (size 0xf440, embedded in ccBoss0402)
 *   ccSceneBossBattleRootBase   (size 0xb038, base for Root00-08)
 *   ccSceneBossFreeBattleBase   (size 0x400, via ccSceneBoss0810 factory)
 *   ccSceneBossBattleIA         (size unknown >= 0x658, last proven field at +0x650)
 */

#ifndef S3_BOSS_FRAMEWORK_H
#define S3_BOSS_FRAMEWORK_H

#include <stdint.h>
#include <stddef.h>

/* C11 _Static_assert wrapper */
#define SA_OFF(struct_t, field, off) \
    _Static_assert(offsetof(struct_t, field) == (off), #field " offset mismatch")

/* ========================================================================
 * ccBossBattleSituationVoice
 * Embedded sub-object of ccBoss0402 at +0x78 (param_1 + 0xf in undefined8 units).
 * Size: 0xf440 — from ccBoss0402::Create at RVA 0x2bd128:
 *   FUN_140683f70(0xf440, "source\\BossBattle\\04\\Battle02\\ccBoss0402.cpp", 0x9e)
 * Ctor RVA: 0x2bf354 | vtable: PTR_FUN_1408f1918
 * Contains std::list at +0x50/+0x58, voice table params, large array region.
 * ======================================================================== */
typedef struct ccBossBattleSituationVoice {
    /* 0x0000 */ void *vtable;                        /* PTR_FUN_1408f1918 */
    /* 0x0008 */ uint32_t voice_tbl_count;            /* Initialize/SetVoiceTbl */
    /* 0x000c */ uint32_t voice_tbl_unk0c;            /* Initialize */
    /* 0x0010 */ uint64_t voice_tbl_ptr;              /* SetVoiceTbl param */
    /* 0x0018 */ uint8_t pad_0018[0x0020 - 0x0018];
    /* 0x0020 */ uint64_t voice_tbl_param20;          /* Initialize */
    /* 0x0028 */ uint8_t pad_0028[0x0048 - 0x0028];
    /* 0x0048 */ uint64_t name_str_ptr;               /* ctor: param_1[9] */
    /* 0x0050 */ uint64_t list_head;                  /* std::list<_Node*> head */
    /* 0x0058 */ uint64_t list_size;                  /* std::list size or sentinel */
    /* 0x0060 */ uint8_t pad_0060[0x0068 - 0x0060];
    /* 0x0068 */ uint32_t unk_0068;                   /* ctor: *(param_1+0xd)=0 => byte 0x68 */
    /* 0x006c */ uint32_t unk_006c;                   /* ctor: *(longlong+0x6c)=0 */
    /* 0x0070 */ uint8_t pad_0070[0xf1e0 - 0x0070];   /* large gap: array region starts at 0xf1e0 */
    /* 0xf1e0 */ uint64_t arr_elem_0;                 /* param_1[0x1e3c]=0 */
    /* 0xf1e8 */ uint32_t arr_elem_1;                 /* *(param_1+0x1e3d)=0xffffffff */
    /* 0xf1ec */ uint32_t pad_f1ec;
    /* 0xf1f0 */ uint8_t subobj_f1f0[0xf2d8 - 0xf1f0];/* sub-ctor at +0x1e3e, size=0xe8 */
    /* 0xf2d8 */ uint8_t subobj_f2d8[0xf2f8 - 0xf2d8];/* sub-ctor at +0x1e5b, size=0x20 */
    /* 0xf2f8 */ uint64_t unk_f2f8;                   /* param_1[0x1e5f]=0 */
    /* 0xf300 */ uint64_t unk_f300;                   /* param_1[0x1e60]=0 */
    /* 0xf308 */ uint32_t unk_f308;                   /* *(param_1+0x1e61)=0x5a */
    /* 0xf30c */ uint32_t unk_f30c;                   /* *(longlong+0xf30c)=0 */
    /* 0xf310 */ uint32_t unk_f310;                   /* *(param_1+0x1e62)=0 */
    /* 0xf314 */ uint32_t unk_f314;                   /* *(longlong+0xf314)=0 */
    /* 0xf318 */ uint8_t pad_f318[0xf440 - 0xf318];   /* tail padding to confirmed size */
} ccBossBattleSituationVoice;

SA_OFF(ccBossBattleSituationVoice, vtable, 0x0000);
SA_OFF(ccBossBattleSituationVoice, voice_tbl_count, 0x0008);
SA_OFF(ccBossBattleSituationVoice, voice_tbl_unk0c, 0x000c);
SA_OFF(ccBossBattleSituationVoice, voice_tbl_ptr, 0x0010);
SA_OFF(ccBossBattleSituationVoice, voice_tbl_param20, 0x0020);
SA_OFF(ccBossBattleSituationVoice, name_str_ptr, 0x0048);
SA_OFF(ccBossBattleSituationVoice, list_head, 0x0050);
SA_OFF(ccBossBattleSituationVoice, list_size, 0x0058);
SA_OFF(ccBossBattleSituationVoice, unk_0068, 0x0068);
SA_OFF(ccBossBattleSituationVoice, unk_006c, 0x006c);
SA_OFF(ccBossBattleSituationVoice, arr_elem_0, 0xf1e0);
SA_OFF(ccBossBattleSituationVoice, arr_elem_1, 0xf1e8);
SA_OFF(ccBossBattleSituationVoice, subobj_f1f0, 0xf1f0);
SA_OFF(ccBossBattleSituationVoice, subobj_f2d8, 0xf2d8);
SA_OFF(ccBossBattleSituationVoice, unk_f2f8, 0xf2f8);
SA_OFF(ccBossBattleSituationVoice, unk_f300, 0xf300);
SA_OFF(ccBossBattleSituationVoice, unk_f308, 0xf308);
SA_OFF(ccBossBattleSituationVoice, unk_f30c, 0xf30c);
SA_OFF(ccBossBattleSituationVoice, unk_f310, 0xf310);
SA_OFF(ccBossBattleSituationVoice, unk_f314, 0xf314);
_Static_assert(sizeof(ccBossBattleSituationVoice) == 0xf440, "sizeof ccBossBattleSituationVoice");

/* ========================================================================
 * ccSceneBossBattleRootBase
 * Base class for ccSceneBossBattleRoot00 through Root08.
 * Size: 0xb038 — from ccSceneBossBattleRoot00::ccSceneBossBattleRoot00 at RVA 0x5a2ab8:
 *   FUN_140683f70(0xb038, ...)
 * Ctor RVA: 0x591398 | vtable: PTR_FUN_1409a6b30
 * Contains sub-objects at +0x128 (sub-ctor 0x591510), +0x1d0 (sub-ctor 0x5915dc),
 *   +0x348 (array of 6-element structs), +0x3a8 (sub-ctor), +0x430 (sub-ctor).
 * ======================================================================== */
typedef struct ccSceneBossBattleRootBase {
    /* 0x0000 */ void *vtable;                        /* PTR_FUN_1409a6b30 */
    /* 0x0008 */ uint8_t pad_0008[0x0128 - 0x0008];   /* base class / reserved region */
    /* 0x0128 */ uint8_t subobj_0128[0x01d0 - 0x0128];/* sub-ctor FUN_140591510 at +0x25 */
    /* 0x01d0 */ uint8_t subobj_01d0[0x0298 - 0x01d0];/* sub-ctor FUN_1405915dc at +0x3a */
    /* 0x0298 */ uint32_t flag_0298;                  /* ctor: *(param_1+0x53)=0 */
    /* 0x029c */ uint32_t init_flag_029c;             /* ctor: *(longlong+0x29c)=1 */
    /* 0x02a0 */ uint64_t param_store_02a0;           /* ctor: param_1[0x54]=param_2 */
    /* 0x02a8 */ uint64_t param_store_02a8;           /* ctor: param_1[0x55]=param_3 */
    /* 0x02b0 */ uint64_t param_store_02b0;           /* ctor: param_1[0x56]=param_4 */
    /* 0x02b8 */ uint64_t unk_02b8;                   /* ctor: param_1[0x57]=0 */
    /* 0x02c0 */ uint8_t subobj_02c0[0x0308 - 0x02c0];/* sub-ctor FUN_1403824dc at +0x58 */
    /* 0x0308 */ uint32_t unk_0308;                   /* ctor: *(param_1+0x61)=0xffffffff */
    /* 0x030c */ uint32_t unk_030c;                   /* ctor: *(longlong+0x30c)=0xffffffff */
    /* 0x0310 */ uint64_t unk_0310;                   /* ctor: param_1[0x62]=0 */
    /* 0x0318 */ uint8_t pad_0318[0x0348 - 0x0318];
    /* 0x0348 */ uint8_t array_region_0348[0x03a8 - 0x0348]; /* array of 6-elem structs at +0x69 */
    /* 0x03a8 */ uint8_t subobj_03a8[0x0410 - 0x03a8];/* sub-ctor FUN_14038bbb8 at +0x75 */
    /* 0x0410 */ uint64_t unk_0410;                   /* ctor: param_1[0x82]=0 */
    /* 0x0418 */ uint64_t unk_0418;                   /* ctor: param_1[0x83]=0 */
    /* 0x0420 */ uint64_t unk_0420;                   /* ctor: param_1[0x84]=0 */
    /* 0x0428 */ uint64_t unk_0428;                   /* ctor: param_1[0x85]=0 */
    /* 0x0430 */ uint8_t subobj_0430[0x04c0 - 0x0430];/* sub-ctor FUN_14037f490 at +0x86 */
    /* 0x04c0 */ uint64_t unk_04c0;                   /* ctor: param_1[0x98]=0 */
    /* 0x04c8 */ uint32_t unk_04c8;                   /* ctor: *(param_1+0x99)=0 */
    /* 0x04cc */ uint8_t pad_04cc[0xb038 - 0x04cc];   /* tail padding to confirmed size */
} ccSceneBossBattleRootBase;

SA_OFF(ccSceneBossBattleRootBase, vtable, 0x0000);
SA_OFF(ccSceneBossBattleRootBase, subobj_0128, 0x0128);
SA_OFF(ccSceneBossBattleRootBase, subobj_01d0, 0x01d0);
SA_OFF(ccSceneBossBattleRootBase, flag_0298, 0x0298);
SA_OFF(ccSceneBossBattleRootBase, init_flag_029c, 0x029c);
SA_OFF(ccSceneBossBattleRootBase, param_store_02a0, 0x02a0);
SA_OFF(ccSceneBossBattleRootBase, param_store_02a8, 0x02a8);
SA_OFF(ccSceneBossBattleRootBase, param_store_02b0, 0x02b0);
SA_OFF(ccSceneBossBattleRootBase, unk_02b8, 0x02b8);
SA_OFF(ccSceneBossBattleRootBase, subobj_02c0, 0x02c0);
SA_OFF(ccSceneBossBattleRootBase, unk_0308, 0x0308);
SA_OFF(ccSceneBossBattleRootBase, unk_030c, 0x030c);
SA_OFF(ccSceneBossBattleRootBase, unk_0310, 0x0310);
SA_OFF(ccSceneBossBattleRootBase, array_region_0348, 0x0348);
SA_OFF(ccSceneBossBattleRootBase, subobj_03a8, 0x03a8);
SA_OFF(ccSceneBossBattleRootBase, unk_0410, 0x0410);
SA_OFF(ccSceneBossBattleRootBase, unk_0418, 0x0418);
SA_OFF(ccSceneBossBattleRootBase, unk_0420, 0x0420);
SA_OFF(ccSceneBossBattleRootBase, unk_0428, 0x0428);
SA_OFF(ccSceneBossBattleRootBase, subobj_0430, 0x0430);
SA_OFF(ccSceneBossBattleRootBase, unk_04c0, 0x04c0);
SA_OFF(ccSceneBossBattleRootBase, unk_04c8, 0x04c8);
_Static_assert(sizeof(ccSceneBossBattleRootBase) == 0xb038, "sizeof ccSceneBossBattleRootBase");

/* ========================================================================
 * ccSceneBossFreeBattleBase
 * Free battle scene base (used by ccSceneBoss0810 etc.).
 * Size: 0x400 — from ccSceneBoss0810 factory caller at RVA 0x63c3a4:
 *   FUN_140683f70(0x400, "source\\sys\\Scene\\ccSceneFactory.cpp", 0x228)
 * Vtable dispatch slots at 0x48, 0x50, 0x60..0xf0 (from Execute/PostInitialize).
 * Fields up to +0x2e8 confirmed; vtable extends beyond data region.
 * ======================================================================== */
typedef struct ccSceneBossFreeBattleBase {
    /* 0x000 */ void *vtable;                         /* vtable with slots 0x48..0xf0 */
    /* 0x008 */ uint8_t pad_008[0x128 - 0x008];       /* base class region */
    /* 0x128 */ uint32_t post_init_val;               /* PostInitialize/_Finalize: *(param_1+0x25) */
    /* 0x12c */ uint32_t pad_12c;
    /* 0x130 */ uint64_t unk_130;                     /* PostInitialize: param_1+0x26 */
    /* 0x138 */ uint8_t subobj_138[0x190 - 0x138];    /* PostInitialize: param_1+0x27 */
    /* 0x190 */ uint8_t unk_region_190[0x288 - 0x190];/* PostInitialize: param_1+0x32 */
    /* 0x288 */ uint64_t finalize_ptr_288;            /* _Finalize: param_1[0x51] */
    /* 0x290 */ uint64_t finalize_ptr_290;            /* _Finalize: param_1[0x52] */
    /* 0x298 */ uint64_t unk_298;                     /* ctor: param_1[0x53]=0 */
    /* 0x2a0 */ uint32_t exec_flag_2a0;               /* Execute/PostInitialize: *(param_1+0x54) */
    /* 0x2a4 */ uint32_t exec_check_2a4;              /* Execute: read at +0x2a4 */
    /* 0x2a8 */ uint64_t finalize_cond_2a8;           /* _Finalize: param_1[0x55] */
    /* 0x2b0 */ uint32_t exec_int_2b0;                /* Execute: param_1[0x56] as int */
    /* 0x2b4 */ uint32_t pad_2b4;
    /* 0x2b8 */ uint64_t post_init_store_2b8;         /* PostInitialize: param_1[0x57] */
    /* 0x2c0 */ uint64_t final_post_2c0;              /* Finalize/PostInitialize: param_1[0x58] */
    /* 0x2c8 */ uint64_t post_init_2c8;               /* PostInitialize: param_1[0x59] */
    /* 0x2d0 */ uint64_t post_init_2d0;               /* PostInitialize: param_1[0x5a] */
    /* 0x2d8 */ uint64_t post_init_2d8;               /* PostInitialize: param_1[0x5b] */
    /* 0x2e0 */ uint64_t post_init_2e0;               /* PostInitialize: param_1[0x5c] */
    /* 0x2e8 */ uint64_t post_init_2e8;               /* PostInitialize: param_1[0x5d] */
    /* 0x2f0 */ uint64_t post_init_2f0;               /* PostInitialize: param_1[0x5e] */
    /* 0x2f8 */ uint8_t pad_2f8[0x400 - 0x2f8];       /* tail padding to confirmed size */
} ccSceneBossFreeBattleBase;

SA_OFF(ccSceneBossFreeBattleBase, vtable, 0x000);
SA_OFF(ccSceneBossFreeBattleBase, post_init_val, 0x128);
SA_OFF(ccSceneBossFreeBattleBase, unk_130, 0x130);
SA_OFF(ccSceneBossFreeBattleBase, subobj_138, 0x138);
SA_OFF(ccSceneBossFreeBattleBase, unk_region_190, 0x190);
SA_OFF(ccSceneBossFreeBattleBase, finalize_ptr_288, 0x288);
SA_OFF(ccSceneBossFreeBattleBase, finalize_ptr_290, 0x290);
SA_OFF(ccSceneBossFreeBattleBase, unk_298, 0x298);
SA_OFF(ccSceneBossFreeBattleBase, exec_flag_2a0, 0x2a0);
SA_OFF(ccSceneBossFreeBattleBase, exec_check_2a4, 0x2a4);
SA_OFF(ccSceneBossFreeBattleBase, finalize_cond_2a8, 0x2a8);
SA_OFF(ccSceneBossFreeBattleBase, exec_int_2b0, 0x2b0);
SA_OFF(ccSceneBossFreeBattleBase, post_init_store_2b8, 0x2b8);
SA_OFF(ccSceneBossFreeBattleBase, final_post_2c0, 0x2c0);
SA_OFF(ccSceneBossFreeBattleBase, post_init_2c8, 0x2c8);
SA_OFF(ccSceneBossFreeBattleBase, post_init_2d0, 0x2d0);
SA_OFF(ccSceneBossFreeBattleBase, post_init_2d8, 0x2d8);
SA_OFF(ccSceneBossFreeBattleBase, post_init_2e0, 0x2e0);
SA_OFF(ccSceneBossFreeBattleBase, post_init_2e8, 0x2e8);
SA_OFF(ccSceneBossFreeBattleBase, post_init_2f0, 0x2f0);
_Static_assert(sizeof(ccSceneBossFreeBattleBase) == 0x400, "sizeof ccSceneBossFreeBattleBase");

/* ========================================================================
 * ccSceneBossBattleIA
 * Boss AI controller scene. Inherits ccScene (base ctor called first).
 * Size: unknown, >= 0x658 (last proven write at +0x650, 8 bytes).
 * Ctor RVA: 0x58faec | vtable: PTR_FUN_1409a6870
 * Cross-build reference: s2 ccSceneBossBattleIA (similar layout, different offsets).
 * Contains ccIaStage-like sub-object, four 0x100-byte string buffers.
 * ======================================================================== */
typedef struct ccSceneBossBattleIA {
    /* 0x000 */ void *vtable;                         /* PTR_FUN_1409a6870, after ccScene base */
    /* 0x008 */ uint8_t ccScene_base[0x058 - 0x008];  /* ccScene base placeholder */
    /* 0x058 */ uint8_t subobj_058[0x0c0 - 0x058];    /* dtor: FUN_14034ac18(param_1+0xb) */
    /* 0x0c0 */ uint8_t subobj_0c0[0x0d8 - 0x0c0];    /* dtor: FUN_14020e3a0(param_1+0x18) */
    /* 0x0d8 */ uint64_t vtbl_slot_0d8;               /* dtor: param_1[0x1b]=PTR_FUN_1409ec308 */
    /* 0x0e0 */ uint8_t pad_0e0[0x108 - 0x0e0];
    /* 0x108 */ uint64_t vtbl_slot_108;               /* dtor: param_1[0x21]=PTR_FUN_1409daf00 */
    /* 0x110 */ uint8_t pad_110[0x128 - 0x110];
    /* 0x128 */ uint8_t subobj_128[0x138 - 0x128];    /* PostInitialize: FUN_14060f788 at +0x25 */
    /* 0x138 */ uint8_t strbuf_138[0x228 - 0x138];    /* dtor: FUN_14034b8c4 at +0x27, ~0x100 bytes */
    /* 0x228 */ uint64_t self_ref_228;                /* Initialize: param_1[0xb7]=(param_1+0x45) */
    /* 0x230 */ uint8_t pad_230[0x528 - 0x230];       /* gap: vtable dispatch region */
    /* 0x528 */ int32_t ia_param5;                    /* Execute/ctor: *(param_1+0xa5)=param_5 */
    /* 0x52c */ uint32_t flag_52c;                    /* Execute: *(longlong+0x52c)=1 */
    /* 0x530 */ uint32_t init_flag_530;               /* Initialize: *(param_1+0xa6)=1 */
    /* 0x534 */ uint32_t pad_534;
    /* 0x538 */ uint8_t pad_538[0x598 - 0x538];       /* gap */
    /* 0x598 */ uint64_t exec_cond_598;               /* Execute/Initialize: param_1[0xb3] */
    /* 0x5a0 */ uint8_t pad_5a0[0x5b8 - 0x5a0];
    /* 0x5b8 */ uint64_t self_ref_5b8;                /* Initialize: param_1[0xb7]=(param_1+0x45) */
    /* 0x5c0 */ uint8_t subobj_5c0[0x620 - 0x5c0];    /* Finalize/PostInitialize: param_1+0xb8 */
    /* 0x620 */ uint32_t state_flag_620;              /* Execute/PostInitialize: *(param_1+0xc4)=1 */
    /* 0x624 */ uint32_t pad_624;
    /* 0x628 */ uint64_t finalize_store_628;          /* Finalize: param_1[0xc5]=0 */
    /* 0x630 */ int32_t enter_state_val;              /* EnterState/Execute: param_1[0xc6] */
    /* 0x634 */ uint32_t retry_sentinel;              /* Execute/Retry: *(longlong+0x634)=0xffffffff */
    /* 0x638 */ uint32_t pad_638;
    /* 0x63c */ uint32_t retry_zero;                  /* Retry: *(longlong+0x63c)=0 */
    /* 0x640 */ uint32_t pad_640;
    /* 0x644 */ uint32_t copy_field_644;              /* Finalize/PostInitialize: copy */
    /* 0x648 */ uint32_t exec_post_648;               /* Execute/PostInitialize: *(param_1+0xc9)=0 */
    /* 0x64c */ uint32_t exec_post_64c;               /* Execute/PostInitialize: *(longlong+0x64c)=0 */
    /* 0x650 */ uint64_t init_final_store;            /* Finalize/Initialize: param_1[0xca] */
    /* Size unknown, >= 0x658 */
} ccSceneBossBattleIA;

SA_OFF(ccSceneBossBattleIA, vtable, 0x000);
SA_OFF(ccSceneBossBattleIA, ccScene_base, 0x008);
SA_OFF(ccSceneBossBattleIA, subobj_058, 0x058);
SA_OFF(ccSceneBossBattleIA, subobj_0c0, 0x0c0);
SA_OFF(ccSceneBossBattleIA, vtbl_slot_0d8, 0x0d8);
SA_OFF(ccSceneBossBattleIA, vtbl_slot_108, 0x108);
SA_OFF(ccSceneBossBattleIA, subobj_128, 0x128);
SA_OFF(ccSceneBossBattleIA, strbuf_138, 0x138);
SA_OFF(ccSceneBossBattleIA, self_ref_228, 0x228);
SA_OFF(ccSceneBossBattleIA, ia_param5, 0x528);
SA_OFF(ccSceneBossBattleIA, flag_52c, 0x52c);
SA_OFF(ccSceneBossBattleIA, init_flag_530, 0x530);
SA_OFF(ccSceneBossBattleIA, exec_cond_598, 0x598);
SA_OFF(ccSceneBossBattleIA, self_ref_5b8, 0x5b8);
SA_OFF(ccSceneBossBattleIA, subobj_5c0, 0x5c0);
SA_OFF(ccSceneBossBattleIA, state_flag_620, 0x620);
SA_OFF(ccSceneBossBattleIA, finalize_store_628, 0x628);
SA_OFF(ccSceneBossBattleIA, enter_state_val, 0x630);
SA_OFF(ccSceneBossBattleIA, retry_sentinel, 0x634);
SA_OFF(ccSceneBossBattleIA, retry_zero, 0x63c);
SA_OFF(ccSceneBossBattleIA, copy_field_644, 0x644);
SA_OFF(ccSceneBossBattleIA, exec_post_648, 0x648);
SA_OFF(ccSceneBossBattleIA, exec_post_64c, 0x64c);
SA_OFF(ccSceneBossBattleIA, init_final_store, 0x650);
/* No sizeof assert: size unknown, >= 0x658 */


/* ========================================================================
 * ccBossBattleLoader
 * Size: unknown
 * no instance state — ctor not found; LoadIa/UnloadIa operate on external singletons (DAT_140be4800); all 27 seeds returned 0 accesses
 */
/* ccBossBattleLoader: no instance state beyond base class */

/* ========================================================================
 * ccSceneBossBattleResult
 * Vtable: PTR_FUN_140938050
 * Size: unknown, >= 0x248
 * vtable PTR_FUN_140938050; size unknown, >= 0x0248; ctor RVA 0x380CBC
 */
typedef struct {
    uint8_t pad_0000[296]; /* 0x0000..0x0128 */
    uint64_t unk_0128; /* +0x0128 [low] ctor */
    uint8_t pad_0130[56]; /* 0x0130..0x0168 */
    uint32_t unk_0168; /* +0x0168 [medium] ctor */
    uint8_t pad_016c[4]; /* 0x016c..0x0170 */
    uint64_t unk_0170; /* +0x0170 [medium] ctor */
    uint32_t unk_0178; /* +0x0178 [medium] ctor */
    uint32_t retry_sentinel_017c; /* +0x017c [high] BattleResultOnUpdate/ctor */
    uint64_t unk_0180; /* +0x0180 [medium] ctor */
    uint32_t flag_0188; /* +0x0188 [high] BattleResultOnUpdate/ctor */
    uint8_t pad_018c[4]; /* 0x018c..0x0190 */
    uint64_t unk_0190; /* +0x0190 [medium] ctor */
    uint32_t unk_0198; /* +0x0198 [medium] ctor */
    uint32_t init_flag_019c; /* +0x019c [medium] ctor */
    uint64_t unk_01a0; /* +0x01a0 [medium] ctor */
    uint64_t param_01a8; /* +0x01a8 [high] BattleResultOnUpdate/ctor */
    uint64_t unk_01b0; /* +0x01b0 [medium] ctor */
    uint64_t unk_01b8; /* +0x01b8 [medium] ctor */
    uint64_t unk_01c0; /* +0x01c0 [medium] ctor */
    uint8_t pad_01c8[120]; /* 0x01c8..0x0240 */
    uint64_t unk_0240; /* +0x0240 [low] BattleResultOnUpdate */
} ccSceneBossBattleResult;
SA_OFF(ccSceneBossBattleResult, unk_0128, 0x128);
SA_OFF(ccSceneBossBattleResult, unk_0168, 0x168);
SA_OFF(ccSceneBossBattleResult, unk_0170, 0x170);
SA_OFF(ccSceneBossBattleResult, unk_0178, 0x178);
SA_OFF(ccSceneBossBattleResult, retry_sentinel_017c, 0x17c);
SA_OFF(ccSceneBossBattleResult, unk_0180, 0x180);
SA_OFF(ccSceneBossBattleResult, flag_0188, 0x188);
SA_OFF(ccSceneBossBattleResult, unk_0190, 0x190);
SA_OFF(ccSceneBossBattleResult, unk_0198, 0x198);
SA_OFF(ccSceneBossBattleResult, init_flag_019c, 0x19c);
SA_OFF(ccSceneBossBattleResult, unk_01a0, 0x1a0);
SA_OFF(ccSceneBossBattleResult, param_01a8, 0x1a8);
SA_OFF(ccSceneBossBattleResult, unk_01b0, 0x1b0);
SA_OFF(ccSceneBossBattleResult, unk_01b8, 0x1b8);
SA_OFF(ccSceneBossBattleResult, unk_01c0, 0x1c0);
SA_OFF(ccSceneBossBattleResult, unk_0240, 0x240);
/* No sizeof assert: size unknown, >= 0x248 */

/* ========================================================================
 * ccSceneBossBattleIA04050
 * Inherits: ccSceneBossBattleIA
 * Vtable: PTR_FUN_1408f5738
 * Size: unknown, >= 0x690
 * extends ccSceneBossBattleIA; vtable PTR_FUN_1408f5738; size unknown, >= 0x0690
 */
typedef struct {
    uint8_t pad_0000[1624]; /* 0x0000..0x0658 */
    uint64_t subobj_0658; /* +0x0658 [low] ctor */
    uint8_t pad_0660[40]; /* 0x0660..0x0688 */
    uint64_t unk_0688; /* +0x0688 [low] ctor */
} ccSceneBossBattleIA04050;
SA_OFF(ccSceneBossBattleIA04050, subobj_0658, 0x658);
SA_OFF(ccSceneBossBattleIA04050, unk_0688, 0x688);
/* No sizeof assert: size unknown, >= 0x690 */

/* ========================================================================
 * ccSceneBossBattleRoot00
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_1409a8c00
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_1409a8c00; size 0xb038 from FUN_140683f70 in ctor
 */
typedef struct {
    uint8_t pad_0000[1232]; /* 0x0000..0x04d0 */
    uint32_t load_flag_04d0; /* +0x04d0 [low] Initialize/ctor */
    uint8_t pad_04d4[4]; /* 0x04d4..0x04d8 */
    uint64_t char_mgr_ptr_04d8; /* +0x04d8 [high] ctor/dtor */
    uint64_t char_mgr2_ptr_04e0; /* +0x04e0 [high] ctor/dtor */
    uint64_t unk_04e8; /* +0x04e8 [low] Initialize/ctor */
    uint8_t pad_tail[43848]; /* 0x04f0..0xb038 */
} ccSceneBossBattleRoot00;
SA_OFF(ccSceneBossBattleRoot00, load_flag_04d0, 0x4d0);
SA_OFF(ccSceneBossBattleRoot00, char_mgr_ptr_04d8, 0x4d8);
SA_OFF(ccSceneBossBattleRoot00, char_mgr2_ptr_04e0, 0x4e0);
SA_OFF(ccSceneBossBattleRoot00, unk_04e8, 0x4e8);
_Static_assert(sizeof(ccSceneBossBattleRoot00) == 0xb038, "ccSceneBossBattleRoot00 size mismatch");

/* ========================================================================
 * ccSceneBossBattleRoot01
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_1409aaec8
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_1409aaec8; size 0xb038 (shared base)
 */
typedef struct {
    uint8_t pad_0000[1544]; /* 0x0000..0x0608 */
    uint32_t unk_0608; /* +0x0608 [low] Initialize */
    uint8_t pad_tail[43564]; /* 0x060c..0xb038 */
} ccSceneBossBattleRoot01;
SA_OFF(ccSceneBossBattleRoot01, unk_0608, 0x608);
_Static_assert(sizeof(ccSceneBossBattleRoot01) == 0xb038, "ccSceneBossBattleRoot01 size mismatch");

/* ========================================================================
 * ccSceneBossBattleRoot02
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_1409ab560
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_1409ab560; no subclass-specific fields
 */
/* ccSceneBossBattleRoot02: no instance state beyond base class */

/* ========================================================================
 * ccSceneBossBattleRoot04
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_1409ac590
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_1409ac590; size 0xb038 (shared base)
 */
typedef struct {
    uint8_t pad_0000[1544]; /* 0x0000..0x0608 */
    uint32_t retry_sentinel_0608; /* +0x0608 [medium] ctor */
    uint8_t pad_tail[43564]; /* 0x060c..0xb038 */
} ccSceneBossBattleRoot04;
SA_OFF(ccSceneBossBattleRoot04, retry_sentinel_0608, 0x608);
_Static_assert(sizeof(ccSceneBossBattleRoot04) == 0xb038, "ccSceneBossBattleRoot04 size mismatch");

/* ========================================================================
 * ccSceneBossBattleRoot06
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_1409adb58
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_1409adb58; no subclass-specific fields
 */
/* ccSceneBossBattleRoot06: no instance state beyond base class */

/* ========================================================================
 * ccSceneBossBattleRoot07
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_1409af150
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_1409af150; size 0xb038 (shared base)
 */
typedef struct {
    uint8_t pad_0000[1544]; /* 0x0000..0x0608 */
    uint32_t unk_0608; /* +0x0608 [low] Initialize */
    uint8_t pad_060c[4]; /* 0x060c..0x0610 */
    uint64_t unk_0610; /* +0x0610 [low] Initialize/ctor */
    uint8_t pad_tail[43552]; /* 0x0618..0xb038 */
} ccSceneBossBattleRoot07;
SA_OFF(ccSceneBossBattleRoot07, unk_0608, 0x608);
SA_OFF(ccSceneBossBattleRoot07, unk_0610, 0x610);
_Static_assert(sizeof(ccSceneBossBattleRoot07) == 0xb038, "ccSceneBossBattleRoot07 size mismatch");

/* ========================================================================
 * ccSceneBossBattleRoot08
 * Inherits: ccSceneBossBattleRootBase
 * Vtable: PTR_FUN_140933c80
 * Size: 0xb038
 * inherits ccSceneBossBattleRootBase; vtable PTR_FUN_140933c80; size 0xb038 (shared base)
 */
typedef struct {
    uint8_t pad_0000[1232]; /* 0x0000..0x04d0 */
    uint64_t unk_04d0; /* +0x04d0 [low] Initialize/ctor */
    uint8_t pad_tail[43872]; /* 0x04d8..0xb038 */
} ccSceneBossBattleRoot08;
SA_OFF(ccSceneBossBattleRoot08, unk_04d0, 0x4d0);
_Static_assert(sizeof(ccSceneBossBattleRoot08) == 0xb038, "ccSceneBossBattleRoot08 size mismatch");

/* ========================================================================
 * ccSceneBossBattleIA00045
 * Inherits: ccSceneBossBattleIA
 * Vtable: PTR_FUN_1408d2d10
 * Size: unknown
 * extends ccSceneBossBattleIA; vtable PTR_FUN_1408d2d10; no subclass-specific instance state (all 6 seeds returned 0 accesses)
 */
/* ccSceneBossBattleIA00045: no instance state beyond base class */

/* ========================================================================
 * ccSceneBossBattleIA00061
 * Inherits: ccSceneBossBattleIA
 * Vtable: PTR_FUN_1408d2e80
 * Size: unknown
 * extends ccSceneBossBattleIA; vtable PTR_FUN_1408d2e80; no subclass-specific instance state (all 6 seeds returned 0 accesses)
 */
/* ccSceneBossBattleIA00061: no instance state beyond base class */
/* ccSceneBossBattleVSLoading: size unknown, >= 0x0240; INFERRED */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleVSLoading {
    uint8_t pad_0000[0x17c];
    uint32_t unk_017c; /* 0x017c */
    uint8_t pad_0180[0x8];
    uint32_t unk_0188; /* 0x0188 */
    uint8_t pad_018c[0x14];
    uint64_t unk_01a0; /* 0x01a0 */
} ns3_ccSceneBossBattleVSLoading;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleVSLoading, unk_017c, 0x017c);
SA_OFF(ns3_ccSceneBossBattleVSLoading, unk_0188, 0x0188);
SA_OFF(ns3_ccSceneBossBattleVSLoading, unk_01a0, 0x01a0);

/* ccSceneBossBattleDemo: size unknown, >= 0x02b8; INFERRED */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleDemo {
    uint8_t pad_0000[0x128];
    uint32_t unk_0128; /* 0x0128 */
    uint8_t pad_012c[0x100];
    int32_t unk_022c; /* 0x022c */
    uint64_t unk_0230; /* 0x0230 */
    uint8_t unk_0238[0x8]; /* 0x0238 — passed to FUN_14058f904; low confidence */
    uint8_t unk_0240[0x40]; /* 0x0240 — vtable dispatch slot 0x48; low confidence */
    uint64_t unk_0280; /* 0x0280 — vtable dispatch slot 0x50; low confidence */
    uint64_t unk_0288; /* 0x0288 */
    uint8_t pad_0290[0x18];
    uint64_t unk_02a8; /* 0x02a8 */
    uint32_t unk_02b0; /* 0x02b0 — read as int in Execute; was uint64_t but must fit before 0x2b4 */
    uint32_t unk_02b4; /* 0x02b4 */
} ns3_ccSceneBossBattleDemo;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleDemo, unk_0128, 0x0128);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_022c, 0x022c);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_0230, 0x0230);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_0238, 0x0238);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_0240, 0x0240);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_0280, 0x0280);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_0288, 0x0288);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_02a8, 0x02a8);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_02b0, 0x02b0);
SA_OFF(ns3_ccSceneBossBattleDemo, unk_02b4, 0x02b4);

/* ========================================================================
 * ccSceneBossBattle01021FBResult
 * Inherits: ccSceneBossBattleResult (base >= 0x248)
 * Size: unknown, >= 0x130
 * 1 subclass-specific field at +0x128 (vtable ptr write in ctor); INFERRED
 */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattle01021FBResult {
    uint8_t pad_0000[0x128];
    uint64_t unk_0128; /* 0x0128 — vtable or dispatch ptr set in ctor */
} ns3_ccSceneBossBattle01021FBResult;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattle01021FBResult, unk_0128, 0x0128);

/* ccSceneBossBattle01030IA: no instance state beyond base class (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattle01050Dec: no instance state beyond base class — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA03060: no instance state beyond base class (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA03090: no instance state beyond base class (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA03091: no instance state beyond base class (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* ========================================================================
 * ccSceneBossBattleIA04030
 * Inherits: ccSceneBossBattleIA (base >= 0x658)
 * Size: unknown, >= 0x68c
 * 2 subclass-specific fields: +0x658 (read, low), +0x688 (write, medium); INFERRED
 */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleIA04030 {
    uint8_t pad_0000[0x658];
    uint8_t unk_0658[0x30]; /* 0x0658 — passed to FUN_1402c27dc in ctor; low confidence */
    uint32_t unk_0688; /* 0x0688 — zeroed in ctor */
} ns3_ccSceneBossBattleIA04030;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleIA04030, unk_0658, 0x0658);
SA_OFF(ns3_ccSceneBossBattleIA04030, unk_0688, 0x0688);

/* ========================================================================
 * ccSceneBossBattleIA07040
 * Inherits: ccSceneBossBattleIA (base >= 0x658)
 * Size: unknown, >= 0x660
 * 1 subclass-specific field at +0x658 (write, medium); INFERRED
 */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleIA07040 {
    uint8_t pad_0000[0x658];
    uint64_t unk_0658; /* 0x0658 — zeroed in ctor */
} ns3_ccSceneBossBattleIA07040;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleIA07040, unk_0658, 0x0658);

/* ========================================================================
 * ccSceneBossBattleIA07050
 * Inherits: ccSceneBossBattleIA (base >= 0x658)
 * Size: unknown, >= 0x660
 * 1 subclass-specific field at +0x658 (write, medium); INFERRED
 */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleIA07050 {
    uint8_t pad_0000[0x658];
    uint64_t unk_0658; /* 0x0658 — zeroed in ctor */
} ns3_ccSceneBossBattleIA07050;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleIA07050, unk_0658, 0x0658);

/* ========================================================================
 * ccSceneBossBattleIA07060
 * Inherits: ccSceneBossBattleIA (base >= 0x658)
 * Size: unknown, >= 0x660
 * 1 subclass-specific field at +0x658 (write, medium); INFERRED
 */
#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleIA07060 {
    uint8_t pad_0000[0x658];
    uint64_t unk_0658; /* 0x0658 — zeroed in ctor */
} ns3_ccSceneBossBattleIA07060;
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleIA07060, unk_0658, 0x0658);

/* ccSceneBossBattleRoot03: no instance state (extends ccSceneBossBattleRootBase) — all 6 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleRoot05: no instance state (extends ccSceneBossBattleRootBase) — all 6 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA04060: no instance state (extends ccSceneBossBattleIA) — all 5 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA07020: no instance state (extends ccSceneBossBattleIA) — all 5 seeds returned 0 accesses; INFERRED */

/* ccBossBattleLoseMenu: no instance state — all 5 seeds returned 0 accesses; INFERRED */

/* ccSceneGroupBattleLoadBoss: no instance state — all 5 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA00010: no instance state (extends ccSceneBossBattleIA) — all 5 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA00020: no instance state (extends ccSceneBossBattleIA) — all 5 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA00070: no instance state (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattle01020FB_: no instance state — all 4 seeds returned 0 accesses; INFERRED */

/* --- Batch 4 Coverage (2026-10-19) --- */

/* ccBossBattleLimitationLife: no instance state — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA00030: no instance state (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA00040: no instance state (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

#pragma pack(push, 1)
/* ccSceneBossBattleIA00052 — extends ccSceneBossBattleIA (base >= 0x658); INFERRED from state_surface */
typedef struct ns3_ccSceneBossBattleIA00052 {
    uint8_t pad_0000[0x53C];                   /* 0x0000: ccSceneBossBattleIA base */
    uint32_t unk_053C;                         /* 0x053C: zeroed in Finalize; w */
} ns3_ccSceneBossBattleIA00052;                /* size >= 0x0540 */
#pragma pack(pop)

SA_OFF(ns3_ccSceneBossBattleIA00052, unk_053C, 0x053C);

/* ccSceneBossBattleIA00060: no instance state (extends ccSceneBossBattleIA) — all 4 seeds returned 0 accesses; INFERRED */

/* --- Batch 5 Coverage (2026-10-19) --- */

/* ccSceneBossBattleIA00064: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattle01070Demo: no instance state — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattle01080FB: no instance state — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA02050: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* --- Batch 6 Coverage (2026-10-19) --- */

/* ccSceneBossBattleIA02060: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA02070: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA02080: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA02090: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* --- Batch 7 Coverage (2026-10-19) --- */

/* ccSceneBossBattleIA03030: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA03080: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleIA04040 {
    uint8_t base[0x658];               /* ccSceneBossBattleIA base */
    uint64_t unk_0658;                 /* +0x658 read in ctor (low); sub-ctor arg @ FUN_1402c27dc(param_1+0xcb) */
    uint8_t pad_0660[0x28];            /* +0x660..+0x687 padding */
    uint64_t unk_0688;                 /* +0x688 read in ctor (low); sub-ctor arg @ FUN_1402be428(param_1+0xd1) */
} ns3_ccSceneBossBattleIA04040;        /* size unknown >= 0x690; INFERRED */
#pragma pack(pop)
SA_OFF(ns3_ccSceneBossBattleIA04040, unk_0658, 0x658);
SA_OFF(ns3_ccSceneBossBattleIA04040, unk_0688, 0x688);

#pragma pack(push, 1)
typedef struct ns3_ccSceneBossBattleIA04070 {
    uint8_t base[0x658];               /* ccSceneBossBattleIA base */
    uint64_t unk_0658;                 /* +0x658 write in ctor (medium); param_1[0xcb] = 0 */
} ns3_ccSceneBossBattleIA04070;        /* size unknown >= 0x660; INFERRED */
#pragma pack(pop)
SA_OFF(ns3_ccSceneBossBattleIA04070, unk_0658, 0x658);

/* --- Batch 8 Coverage (2026-10-19) --- */

/* ccSceneBossBattleIA05040: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccBossBattleObjectManager: no instance state — all 3 seeds returned 0 accesses (template Create<> methods operate on external singletons); INFERRED */

/* --- Batch 9 Coverage (2026-10-19) --- */

/* ccSceneBossBattleIA06090: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleSceneLoader: no instance state — all 3 seeds returned 0 accesses; INFERRED */

/* --- Batch 10 Coverage (2026-10-19) --- */

/* ccSceneBossBattleIA00051: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

/* ccSceneBossBattleIA00065: no instance state (extends ccSceneBossBattleIA) — all 3 seeds returned 0 accesses; INFERRED */

#endif /* S3_BOSS_FRAMEWORK_H */

/* --- Batch 12 Coverage (2026-10-19) --- */
/* All 10 maintainer-listed classes already covered in prior batches:
 *   ccSceneBossBattleVSLoading     — struct ns3_ccSceneBossBattleVSLoading (batch 3)
 *   ccSceneBossBattleDemo          — struct ns3_ccSceneBossBattleDemo (batch 3)
 *   ccSceneBossBattle01021FBResult — struct ns3_ccSceneBossBattle01021FBResult (batch 3)
 *   ccSceneBossBattleIA04030       — struct ns3_ccSceneBossBattleIA04030 (batch 3)
 *   ccSceneBossBattleIA07040       — struct ns3_ccSceneBossBattleIA07040 (batch 3)
 *   ccSceneBossBattleIA07050       — struct ns3_ccSceneBossBattleIA07050 (batch 3)
 *   ccSceneBossBattleIA07060       — struct ns3_ccSceneBossBattleIA07060 (batch 3)
 *   ccSceneBossBattleIA00052       — struct ns3_ccSceneBossBattleIA00052 (batch 4)
 *   ccSceneBossBattleIA04040       — struct ns3_ccSceneBossBattleIA04040 (batch 7)
 *   ccSceneBossBattleIA04070       — struct ns3_ccSceneBossBattleIA04070 (batch 7)
 * No new fields discovered; gcc-clean verified. */
