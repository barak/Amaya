/*                            W3C Reference Library libwww TELNET, RLOGIN, AND TN3270 CLIENTS
              DECLARATION OF W3C REFERENCE TELNET, RLOGIN, AND TN3270 MODULE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the include file for the basic Telnet, rlogin, and TN3270 module that can be
   used together with the core of the W3C Reference Library. It contains all Telnet,
   rlogin, and TN3270 specific modules which are required to compile and build the Telnet,
   rlogin, and TN3270 DLL.
   
 */
#ifndef WWWTELNET_H
#define WWWTELNET_H
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
#include "HTTelnet.h"                         /* TELNET client state machine */
/*

   End of TELNET module
   
 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                           @(#) $Id: WWWTelnt.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
