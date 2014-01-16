/*                                           W3C Reference Library libwww MIME REQUEST STREAM
                                   MIME REQUEST STREAM
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The MIME Request stream generates a MIME request header and writes it to the target
   which is normally a HTWriter stream.
   
   This module is implemented by HTMIMERq.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTMIMERQ_H
#define HTMIMERQ_H

#include "HTStream.h"
#include "HTReq.h"
/*

  Streams Definition
  
   This stream makes a MIME header before it goes into transparent mode. If endHeaderis
   YES then we send an empty CRLFin order to end the header.
   
 */
extern HTStream * HTMIMERequest_new    (HTRequest * request, HTStream * target,
                                        BOOL endHeader);

#endif
/*

   
   ___________________________________
   
                           @(#) $Id: HTMIMERq.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
