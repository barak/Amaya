/*                                           W3C Reference Library libwww HTTP REQUEST STREAM
                                   HTTP REQUEST STREAM
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The HTTP Request stream generates a HTTP request header and writes it to the target
   which is normally a HTWriter stream.
   
   This module is implemented by HTTPReq.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTTPREQ_H
#define HTTPREQ_H

#include "HTStream.h"
#include "HTReq.h"
/*

  Streams Definition
  
   This stream makes a HTTP request header before it goes into transparent mode. If
   endHeaderis YES then we send an empty CRLFin order to end the header.
   
 */
extern HTStream * HTTPRequest_new (HTRequest * request, HTStream * target,
                                   BOOL endHeader, int version);
/*

 */
#endif
/*

   
   ___________________________________
   
                           @(#) $Id: HTTPReq.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
