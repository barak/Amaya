/*                                                    W3C Reference Library libwww FTP CLIENT
                         DECLARATION OF W3C REFERENCE FTP MODULE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the include file for the basic FTP module that can be used together with the
   core of the W3C Reference Library. It contains all FTP specific modules which are
   required to compile and build the FTP DLL.
   
 */
#ifndef WWWFTP_H
#define WWWFTP_H
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
#include "HTFTP.h"                      /* FTP client state machine */
#include "HTFTPDir.h"                   /* Streams for parsing FTP output */
/*

   End of FTP module
   
 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                             @(#) $Id: WWWFTP.h,v 1.1.1.1 1996/10/15 13:08:38 cvs Exp $
                                                                                          
    */
