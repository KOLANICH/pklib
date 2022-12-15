/*****************************************************************************/
/* pklib.h                                Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Header file for PKWARE Data Compression Library                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 31.03.03  1.00  Lad  The first version of pkware.h                        */
/*****************************************************************************/

#ifndef __PKLIB_EXPLODE_H__
#define __PKLIB_EXPLODE_H__

#pragma once

#include "./pklib.h"

// Sizes needed to allocate buffer for TDcmpStruct and access its fields in a future-proof way
struct ExplodeSizeConstants{
    size_t own_size;
    size_t internal_struct_size;
    size_t IN_BUFF_SIZE, CODES_SIZE, OFFSS_SIZE, OFFSS_SIZE1, CH_BITS_ASC_SIZE, LENS_SIZES;
};

enum ExplodeSizesEnum{
    IN_BUFF_SIZE=0x800,
    CODES_SIZE=0x100,
    OFFSS_SIZE=0x100,
    OFFSS_SIZE1=0x80,
};


//-----------------------------------------------------------------------------
// Internal structures

// Decompression structure
typedef struct
{
    unsigned long offs0000;                 // 0000
    unsigned long ctype;                    // 0004: Compression type (CMP_BINARY or CMP_ASCII)
    unsigned long outputPos;                // 0008: Position in output buffer
    unsigned long dsize_bits;               // 000C: Dict size (4, 5, 6 for 0x400, 0x800, 0x1000)
    unsigned long dsize_mask;               // 0010: Dict size bitmask (0x0F, 0x1F, 0x3F for 0x400, 0x800, 0x1000)
    unsigned long bit_buff;                 // 0014: 16-bit buffer for processing input data
    unsigned long extra_bits;               // 0018: Number of extra (above 8) bits in bit buffer
    unsigned int  in_pos;                   // 001C: Position in in_buff
    unsigned long in_bytes;                 // 0020: Number of bytes in input buffer
    void        * param;                    // 0024: Custom parameter
    unsigned int (*read_buf)(char *buf, unsigned int *size, void *param); // Pointer to function that reads data from the input stream
    void         (*write_buf)(char *buf, unsigned int *size, void *param);// Pointer to function that writes data to the output stream

    unsigned char out_buff[BUFF_SIZE];      // 0030: Output circle buffer.
                                            //       0x0000 - 0x0FFF: Previous uncompressed data, kept for repetitions
                                            //       0x1000 - 0x1FFF: Currently decompressed data
                                            //       0x2000 - 0x2203: Reserve space for the longest possible repetition
    unsigned char in_buff[IN_BUFF_SIZE];           // 2234: Buffer for data to be decompressed
    unsigned char DistPosCodes[CODES_SIZE];      // 2A34: Table of distance position codes
    unsigned char LengthCodes[CODES_SIZE];       // 2B34: Table of length codes
    unsigned char offs2C34[OFFSS_SIZE];          // 2C34: Buffer for
    unsigned char offs2D34[OFFSS_SIZE];          // 2D34: Buffer for
    unsigned char offs2E34[OFFSS_SIZE1];           // 2E34: Buffer for
    unsigned char offs2EB4[OFFSS_SIZE];          // 2EB4: Buffer for
    unsigned char ChBitsAsc[CH_BITS_ASC_SIZE];         // 2FB4: Buffer for
    unsigned char DistBits[DIST_SIZES];           // 30B4: Numbers of bytes to skip copied block length
    unsigned char LenBits[LENS_SIZES];            // 30F4: Numbers of bits for skip copied block length
    unsigned char ExLenBits[LENS_SIZES];          // 3104: Number of valid bits for copied block
    unsigned short LenBase[LENS_SIZES];           // 3114: Buffer for
} TDcmpStruct;

enum {
    EXP_BUFFER_SIZE = sizeof(TDcmpStruct), // Size of decompression structure
                                           // Defined as 12596 in pkware headers
};

//-----------------------------------------------------------------------------
// Public functions

#ifdef __cplusplus
   extern "C" {
#endif

struct ExplodeSizeConstants PKEXPORT getExplodeSizeConstants();

unsigned int PKEXPORT explode(
   unsigned int (*read_buf)(char *buf, unsigned  int *size, void *param),
   void         (*write_buf)(char *buf, unsigned  int *size, void *param),
   char         *work_buf,
   void         *param);

// The original name "crc32" was changed to "crc32pk" due
// to compatibility with zlib
unsigned long PKEXPORT crc32_pklib(char *buffer, unsigned int *size, unsigned long *old_crc);

#ifdef __cplusplus
   }                         // End of 'extern "C"' declaration
#endif

#endif // __PKLIB_EXPLODE_H__
