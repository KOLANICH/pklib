/*****************************************************************************/
/* pklib.h                                Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Header file for PKWARE Data Compression Library                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 31.03.03  1.00  Lad  The first version of pkware.h                        */
/*****************************************************************************/

#ifndef __PKLIB_TABLES_H__
#define __PKLIB_TABLES_H__

#pragma once

#include <stddef.h>

#include "./api.h"

enum LUTSizesEnum {
    DIST_SIZES=0x40,
    CH_BITS_ASC_SIZE=0x100,
    LENS_SIZES=0x10,
};


// Sizes of look-uptables
struct LUTSizeConstants{
    size_t own_size, DIST_SIZES, CH_BITS_ASC_SIZE, LENS_SIZES;
};

//-----------------------------------------------------------------------------
// Tables (in PKWareLUTs.c)

extern const unsigned char DistBits[DIST_SIZES];
extern const unsigned char DistCode[DIST_SIZES];
extern const unsigned char ExLenBits[LENS_SIZES];
extern const unsigned short LenBase[LENS_SIZES];
extern const unsigned char LenBits[LENS_SIZES];
extern const unsigned char LenCode[LENS_SIZES];
extern const unsigned char ChBitsAsc[CH_BITS_ASC_SIZE];
extern const unsigned short ChCodeAsc[CH_BITS_ASC_SIZE];

//-----------------------------------------------------------------------------
// Public functions

#ifdef __cplusplus
   extern "C" {
#endif

struct LUTSizeConstants PKEXPORT getLUTSizeConstants();

#ifdef __cplusplus
   }                         // End of 'extern "C"' declaration
#endif

#endif // __PKLIB_TABLES_H__
