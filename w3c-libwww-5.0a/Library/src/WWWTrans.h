/*                                                    W3C Reference Library libwww Transports
                     DECLARATION OF W3C REFERENCE LIBRARY TRANSPORTS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

 */
#ifndef WWWTRANS_H
#define WWWTRANS_H
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

TRANSPORT MODULES

   These are the transports describing this interface
   
  Local File Transport
  
 */
#include "HTANSI.h"
#include "HTLocal.h"
/*

  BSD Socket Transport
  
 */
#include "HTTCP.h"
#include "HTSocket.h"
#include "HTReader.h"
#include "HTWriter.h"
#include "HTBufWrt.h"
/*

  W3Mux Multiplexing Transport
  
 */
#include "HTMux.h"
/*

 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                           @(#) $Id: WWWTrans.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
