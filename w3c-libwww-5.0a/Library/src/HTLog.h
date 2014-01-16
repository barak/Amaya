/*                                                     W3C Reference Library libwww LOG FILES
                                       LOG MANAGER
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module maintaines logs of request to a file.
   
   This module is implemented by HTLog.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTLIBLOG_H
#define HTLIBLOG_H

#include "HTReq.h"
/*

ENABLE THE LOG

   Open the log file and start doing log. The time used in the log file is either GMT or
   local dependent on local.
   
 */
extern BOOL HTLog_open (const char * filename, BOOL local, BOOL append);
/*

DISABLE THE LOG

   Close the log file and do more log
   
 */
extern BOOL HTLog_close (void);
/*

IN LOG ENABLED?

 */
extern BOOL HTLog_isOpen (void);
/*

LOG A REQUEST

   This functions logs the result of a request.
   
 */
extern BOOL HTLog_add (HTRequest * request, int status);

#endif
/*

   
   ___________________________________
   
                             @(#) $Id: HTLog.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
