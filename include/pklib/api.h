/*****************************************************************************/
/* api.h                                  Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Header file for PKWARE Data Compression Library                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 31.03.03  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __PKLIB_API_H__
#define __PKLIB_API_H__

#pragma once

//-----------------------------------------------------------------------------
// Define calling convention

#ifndef PKEXPORT
#ifdef WIN32
#define PKEXPORT  __cdecl                   // Use for normal __cdecl calling
#else
#define PKEXPORT
#endif
#endif

#endif // __PKLIB_API_H__
