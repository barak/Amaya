/*                                           W3C Reference Library libwww NNTP REQUEST STREAM
                                   NNTP REQUEST STREAM
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The NNTP Request stream generates a NNTP request header and writes it to the target
   which is normally a HTWriter stream.
   
   This module is implemented by HTNewsRq.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTNEWSREQ_H
#define HTNEWSREQ_H

#include "HTStream.h"
#include "HTAccess.h"
/*

  Streams Definition
  
   This stream makes a HTNews request header before it goes into transparent mode.
   
 */
extern HTStream * HTNewsPost_new (HTRequest * request, HTStream * target);

#endif
/*

   
   ___________________________________
   
                           @(#) $Id: HTNewsRq.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
