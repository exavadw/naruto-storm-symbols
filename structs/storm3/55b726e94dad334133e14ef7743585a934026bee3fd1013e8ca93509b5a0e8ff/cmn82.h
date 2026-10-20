#ifndef CMN82_S3_H
#define CMN82_S3_H

/*
 * cmn82 struct group — build s3 (NSUNS3.exe, NARUTO STORM 3 Full Burst HD PC)
 * Classes: CriAllocator, CriManaFileReader, CriManaSound
 *
 * All layouts INFERRED from static analysis of s3 decompilations.
 * Not CONFIRMED by runtime trace.
 *
 * CriAllocator:     static-only utility class (operator new/delete wrappers).
 *                   No instance state; no struct emitted.
 * CriManaSound:     static-only initialization/finalization API.
 *                   No instance state found in s3 decompilations; no struct emitted.
 * CriManaFileReader: size 0x2B8 proven from CriAllocator::operator_new(0x2b8,...)
 *                    in CriManaFileReader::Create (RVA 0x7AD90).
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

/*
 * CriManaFileReader — CRI Mana video file reader wrapper around criFsLoader.
 * Size: 0x2B8 (proven: CriAllocator::operator_new(0x2b8,...) in Create, RVA 0x7AD90).
 * Vtable: offset 0x00 (set by criFsLoader_Create called in Create; vfunc at +0x48 is destructor dispatch).
 *
 * Field naming carried from s2 header and re-verified against s3 decompilations.
 * Rollback tags: PRES = presentation/transient state, SIM = simulation-relevant,
 *                UNKNOWN = purpose unclear.
 */
typedef struct __attribute__((packed)) CriManaFileReader {
    /* 0x000 */ void *vtable;                          /* PRES: vtable ptr, set by criFsLoader_Create in Create (RVA 0x7AD90) */
    /* 0x008 */ uint8_t _pad_008[0x018];               /* UNKNOWN: base class / criFsLoader internal (24 bytes) */
    /* 0x020 */ void *fs_loader;                       /* PRES: criFsLoader handle (used in Open/Close/Destroy; local_28[4] in Create) */
    /* 0x028 */ int64_t file_size;                     /* PRES: returned by GetFileSize (RVA 0x7B590); Seek uses as SEEK_END base */
    /* 0x030 */ int64_t seek_position;                 /* PRES: current seek position, read/written by Seek (RVA 0x7BBA0) */
    /* 0x038 */ uint8_t _pad_038[0x010];               /* UNKNOWN (16 bytes) */
    /* 0x048 */ uint32_t open_flag;                    /* PRES: set to 1 in Open (RVA 0x7B860); checked in Destroy */
    /* 0x04C */ uint32_t close_flag;                   /* PRES: set to 1 in Close (inferred from s2 pattern) */
    /* 0x050 */ uint32_t read_flag;                    /* PRES: set to 1 in Read (inferred from s2 pattern) */
    /* 0x054 */ void *cs_handle_054;                   /* PRES: criCs_Create output stored in Create (local_28[0x54]) */
    /* 0x05C */ uint8_t _pad_05c[0x054];               /* UNKNOWN: gap to delegate_handle (84 bytes) */
    /* 0x0B0 */ void *delegate_handle;                 /* PRES: passed to criDelegate_EndInvoke/criVdec_DecodeFrame in Open */
    /* 0x0B8 */ void *queue_head;                      /* PRES: linked-list head of pending IO requests */
    /* 0x0C0 */ void *queue_tail;                      /* PRES: linked-list tail of pending IO requests */
    /* 0x0C8 */ uint32_t queued_count;                 /* PRES: incremented in Open/Read/Close, decremented in ExecuteAsyncIO (byte offset 200 = 0xC8) */
    /* 0x0CC */ uint8_t _pad_0cc[0x004];               /* padding to 0xD0 (4 bytes) */
    /* 0x0D0 */ uint8_t io_requests[0x180];            /* PRES: 8-entry ring buffer of IO request structs (each 0x30 bytes); memset in Create */
    /* 0x250 */ uint32_t ring_index;                   /* PRES: ring buffer write cursor, mod 8 */
    /* 0x254 */ void *cs_handle_254;                   /* PRES: second criCs_Create output (size 0x48); freed in Destroy via param_1[0x16] */
    /* 0x25C */ uint8_t _pad_25c[0x044];               /* UNKNOWN: gap to field at 0x2A0 (68 bytes) */
    /* 0x2A0 */ void *destroy_field_2a0;               /* PRES: freed in Destroy via FUN_140011fbc(param_1[0x54]) — index 0x54 * 8 = 0x2A0 */
    /* 0x2A8 */ uint32_t async_status;                 /* PRES: set to 1 in ExecuteAsyncIO, 2 in Open */
    /* 0x2AC */ uint8_t _pad_2ac[0x00C];               /* padding to total size 0x2B8 (12 bytes) */
} CriManaFileReader;

/* Offset assertions for every named field */
static_assert(offsetof(CriManaFileReader, vtable)            == 0x000, "CriManaFileReader::vtable");
static_assert(offsetof(CriManaFileReader, fs_loader)         == 0x020, "CriManaFileReader::fs_loader");
static_assert(offsetof(CriManaFileReader, file_size)         == 0x028, "CriManaFileReader::file_size");
static_assert(offsetof(CriManaFileReader, seek_position)     == 0x030, "CriManaFileReader::seek_position");
static_assert(offsetof(CriManaFileReader, open_flag)         == 0x048, "CriManaFileReader::open_flag");
static_assert(offsetof(CriManaFileReader, close_flag)        == 0x04C, "CriManaFileReader::close_flag");
static_assert(offsetof(CriManaFileReader, read_flag)         == 0x050, "CriManaFileReader::read_flag");
static_assert(offsetof(CriManaFileReader, cs_handle_054)     == 0x054, "CriManaFileReader::cs_handle_054");
static_assert(offsetof(CriManaFileReader, delegate_handle)   == 0x0B0, "CriManaFileReader::delegate_handle");
static_assert(offsetof(CriManaFileReader, queue_head)        == 0x0B8, "CriManaFileReader::queue_head");
static_assert(offsetof(CriManaFileReader, queue_tail)        == 0x0C0, "CriManaFileReader::queue_tail");
static_assert(offsetof(CriManaFileReader, queued_count)      == 0x0C8, "CriManaFileReader::queued_count");
static_assert(offsetof(CriManaFileReader, io_requests)       == 0x0D0, "CriManaFileReader::io_requests");
static_assert(offsetof(CriManaFileReader, ring_index)        == 0x250, "CriManaFileReader::ring_index");
static_assert(offsetof(CriManaFileReader, cs_handle_254)     == 0x254, "CriManaFileReader::cs_handle_254");
static_assert(offsetof(CriManaFileReader, destroy_field_2a0) == 0x2A0, "CriManaFileReader::destroy_field_2a0");
static_assert(offsetof(CriManaFileReader, async_status)      == 0x2A8, "CriManaFileReader::async_status");

/* Total size assertion — proven from CriAllocator::operator_new(0x2b8,...) in Create (RVA 0x7AD90) */
static_assert(sizeof(CriManaFileReader) == 0x2B8, "CriManaFileReader size must be 0x2B8");

#endif /* CMN82_S3_H */