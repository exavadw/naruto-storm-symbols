/*
 * ccSceneManager struct layout — NARUTO STORM 2 (NSUNS2.exe, s2)
 * Build SHA: 697488011750
 * Object size: 0x158 bytes (from ccFileLoadListForUi::LoadTh(0x158,...) in Framework::Initialize @ RVA 0x630CA0)
 * All field placements are INFERRED from static analysis of constructor, methods, and allocator calls.
 * Cross-build: layout matches s1 (Storm 1) exactly; field names carried forward and re-verified in s2 code.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/* Forward declarations for embedded types not yet fully reconstructed */
/* std::map<int, CreateSceneState*> at offset 0x18 — tree root (3 qwords = 24 bytes) */
/* Scene object: has key at +0x120, rank/type at +0x20, change_type at +0x18 (qword ptr +3) */

typedef struct ccSceneManager_CreateSceneState {
    /* Inferred from ChangeCore/DeleteScene/IsRegisteredScene usage:
     * +0x00: vtable or left child ptr
     * +0x08: key (int scene_id) — used in tree
     * +0x10: right child ptr
     * +0x18: change_type (int) — dispatch value in ChangeCore (*(int*)(puVar2 + 3))
     * +0x20: rank/type field — checked in Execute (*(int*)(param_1[9] + 0x20))
     * +0x28: cleanup/dtor vtable slot — called in DeleteScene
     * +0x40: execute vtable slot — called in Execute
     * +0x120: scene key/id (int) — used as lookup key in IsRegisteredScene loop
     */
    uint8_t _pad[0x124]; /* full layout not yet proven */
} ccSceneManager_CreateSceneState;

/* Vtable pointer for ccSceneManager (PTR_FUN_14089f210 from ctor) */
/* Methods resolved from vtable slots:
 * slot +0x00: dtor/cleanup? (called via (*param_1))
 * slot +0x08: cleanup/pre-change (called via (*param_1+8) in Execute/ChangeCore/DeleteScene)
 * slot +0x10: post-change/end (called via (*param_1+0x10) in Execute/ChangeCore/DeleteScene)
 */

typedef struct ccSceneManager {
    /* 0x00 */ void* vtable;                          /* PTR_FUN_14089f210, set in ctor */

    /* 0x08 */ int heap_tag;                          /* BlockAllocator base: param_1[1], passed to GetBlockId */
    /* 0x0C */ uint8_t pad_0c[4];                     /* alignment padding after heap_tag */

    /* 0x10 */ uint8_t flags;                         /* allocator-related flag (inferred from s1 carry-forward) */
    /* 0x11 */ uint8_t pad_11[7];                     /* alignment to 8-byte boundary for scene_map */

    /* 0x18 */ struct {                               /* std::map<int, CreateSceneState*> tree root */
        void* left;                                   /* initialized to self in ctor */
        void* parent;                                 /* initialized to self in ctor */
        void* right;                                  /* initialized to self in ctor */
    } scene_map;                                      /* 24 bytes, destroyed via std::__tree::destroy */

    /* 0x30 */ uint8_t pad_30[0x10];                  /* gap between map end (0x30) and next known field */

    /* 0x40 */ int current_scene_index;               /* param_1[8] as int, used in Execute/GetCurrentSceneKey */
    /* 0x44 */ uint8_t pad_44[4];                     /* alignment padding before pointer field */

    /* 0x48 */ ccSceneManager_CreateSceneState* current_scene; /* param_1[9], active/transitioning scene */

    /* 0x50 */ ccSceneManager_CreateSceneState* scenes[0x20];  /* param_1[10..0x29], array of 32 scene ptrs */
    /* memset'd to 0 in ctor (offset 0x50, size 0x100 = 256 bytes = 32 ptrs) */
    /* IsRegisteredScene iterates this array with bounds check < 0x20 */
    /* DeleteScene indexes as param_1[lVar3 + 10] confirming base at qword index 10 = byte 0x50 */

    /* 0x150 */ int some_state;                       /* param_1[0x2a] as int, checked in Execute/ChangeCore (==0 means idle?) */
    /* 0x154 */ int change_pending_flag;              /* checked in Execute: if == 1, calls vtable slot +0x40 instead of +0x20 */
    /* 0x158 */                                       /* END — total size 0x158 */
} ccSceneManager;

/* Static assertions for every field offset */
static_assert(offsetof(ccSceneManager, vtable) == 0x00, "vtable offset");
static_assert(offsetof(ccSceneManager, heap_tag) == 0x08, "heap_tag offset");
static_assert(offsetof(ccSceneManager, flags) == 0x10, "flags offset");
static_assert(offsetof(ccSceneManager, scene_map) == 0x18, "scene_map offset");
static_assert(offsetof(ccSceneManager, current_scene_index) == 0x40, "current_scene_index offset");
static_assert(offsetof(ccSceneManager, current_scene) == 0x48, "current_scene offset");
static_assert(offsetof(ccSceneManager, scenes) == 0x50, "scenes offset");
static_assert(offsetof(ccSceneManager, some_state) == 0x150, "some_state offset");
static_assert(offsetof(ccSceneManager, change_pending_flag) == 0x154, "change_pending_flag offset");

/* Total size assertion from game allocator (ccFileLoadListForUi::LoadTh(0x158,...)) */
static_assert(sizeof(ccSceneManager) == 0x158, "ccSceneManager size from Framework::Initialize alloc");