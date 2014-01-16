/*                                          W3C Reference Library libwww HTTP RESPONSE STREAM
                                   HTTP RESPONSE STREAM
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The HTTP response stream generates a HTTP response header and writes it to the target
   which is normally a HTWriter stream.
   
   This module is implemented by HTTPRes.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTTPRES_H
#define HTTPRES_H

#include "HTStream.h"
#include "HTReq.h"
/*

  Streams Definition
  
   This stream makes a server specific HTTP header before it goes into transparent mode.
   If endHeaderis YES then we send an empty CRLFin order to end the header.
   
 */
extern HTStream * HTTPResponse_new (HTRequest * request, HTStream * target,
                                    BOOL endHeader, int version);
/*

 */
#endif
/*

   
   ___________________________________
   
                            @(#) $Id: HTTPRes.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
