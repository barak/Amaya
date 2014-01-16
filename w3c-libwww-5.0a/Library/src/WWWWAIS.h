/*                                                   W3C Reference Library libwww WAIS CLIENT
                         DECLARATION OF W3C REFERENCE WAIS MODULE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the include file for the basic WAIS module that can be used together with the
   core of the W3C Reference Library. It contains all WAIS specific modules which are
   required to compile and build the WAIS DLL.
   
 */
#ifndef WWWWAIS_H
#define WWWWAIS_H
/*

 */
#ifdef __cplusplus
extern "C" {
#endif
/*

SYSTEM DEPENDENCIES

   The sysdep.h file includes system-specific include files and flags for I/O to network
   and disk. The only reason for this file is that the Internet world is more complicated
   than Posix and ANSI.
   
 */
#include "sysdep.h"
/*

LIBRARY INCLUDES

 */
#include "HTWAIS.h"                             /* WAIS client state machine */
/*

   End of WAIS module
   
 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                            @(#) $Id: WWWWAIS.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
