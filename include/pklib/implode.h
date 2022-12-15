/*****************************************************************************/
/* pklib.h                                Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Header file for PKWARE Data Compression Library                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 31.03.03  1.00  Lad  The first version of pkware.h                        */
/*****************************************************************************/

#ifndef __PKLIB_IMPLODE_H__
#define __PKLIB_IMPLODE_H__

#pragma once

#include "./pklib.h"

//-----------------------------------------------------------------------------
// Defines

enum ImplodeDictSizes {
	CMP_IMPLODE_DICT_SIZE1 = 1024,       // Dictionary size of 1024
	CMP_IMPLODE_DICT_SIZE2 = 2048,       // Dictionary size of 2048
	CMP_IMPLODE_DICT_SIZE3 = 4096,       // Dictionary size of 4096
};

//-----------------------------------------------------------------------------
// Internal structures

// Sizes needed to allocate buffer for TCmpStruct and access its fields in a future-proof way
struct ImplodeSizeConstants{
    size_t own_size;
    size_t internal_struct_size;
    size_t OFFSS_SIZE2, LITERALS_COUNT, HASHTABLE_SIZE;
};

enum ImplodeSizesEnum {
    OFFSS_SIZE2=0x204,
    LITERALS_COUNT=0x306,
    HASHTABLE_SIZE=0x900,
};

//-----------------------------------------------------------------------------
// Internal structures

// Compression structure
typedef struct
{
    unsigned int   distance;                // 0000: Backward distance of the currently found repetition, decreased by 1
    unsigned int   out_bytes;               // 0004: # bytes available in out_buff
    unsigned int   out_bits;                // 0008: # of bits available in the last out byte
    unsigned int   dsize_bits;              // 000C: Number of bits needed for dictionary size. 4 = 0x400, 5 = 0x800, 6 = 0x1000
    unsigned int   dsize_mask;              // 0010: Bit mask for dictionary. 0x0F = 0x400, 0x1F = 0x800, 0x3F = 0x1000
    unsigned int   ctype;                   // 0014: Compression type (CMP_ASCII or CMP_BINARY)
    unsigned int   dsize_bytes;             // 0018: Dictionary size in bytes
    unsigned char  dist_bits[DIST_SIZES];   // 001C: Distance bits
    unsigned char  dist_codes[DIST_SIZES];  // 005C: Distance codes
    unsigned char  nChBits[LITERALS_COUNT]; // 009C: Table of literal bit lengths to be put to the output stream
    unsigned short nChCodes[LITERALS_COUNT];// 03A2: Table of literal codes to be put to the output stream
    unsigned short offs09AE;                // 09AE:

    void         * param;                   // 09B0: User parameter
    unsigned int (*read_buf)(char *buf, unsigned int *size, void *param);  // 9B4
    void         (*write_buf)(char *buf, unsigned int *size, void *param); // 9B8

    unsigned short offs09BC[OFFSS_SIZE2];   // 09BC:
    unsigned long  offs0DC4;                // 0DC4:
    unsigned short phash_to_index[HASHTABLE_SIZE];  // 0DC8: Array of indexes (one for each PAIR_HASH) to the "pair_hash_offsets" table
    unsigned short phash_to_index_end;      // 1FC8: End marker for "phash_to_index" table
    char           out_buff[OUT_BUFF_SIZE]; // 1FCA: Compressed data
    unsigned char  work_buff[BUFF_SIZE];     // 27CC: Work buffer
                                            //  + DICT_OFFSET  => Dictionary
                                            //  + UNCMP_OFFSET => Uncompressed data
    unsigned short phash_offs[BUFF_SIZE];    // 49D0: Table of offsets for each PAIR_HASH
} TCmpStruct;


enum {
    CMP_BUFFER_SIZE = sizeof(TCmpStruct), // Size of compression structure.
                                          // Defined as 36312 in pkware header file
};

//-----------------------------------------------------------------------------
// Public functions

#ifdef __cplusplus
   extern "C" {
#endif

struct ImplodeSizeConstants PKEXPORT getImplodeSizeConstants();

unsigned int PKEXPORT implode(
   unsigned int (*read_buf)(char *buf, unsigned int *size, void *param),
   void         (*write_buf)(char *buf, unsigned int *size, void *param),
   char         *work_buf,
   void         *param,
   unsigned int *type,
   unsigned int *dsize);

#ifdef __cplusplus
   }                         // End of 'extern "C"' declaration
#endif

#endif // __PKLIB_IMPLODE_H__
