/*                                                   W3C Reference Library libwww HTTP Client
                 MULTI THREADED HYPERTEXT TRANFER PROTOCOL CLIENT MODULE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is actually a very small definition file as almost everything is set up elsewhere.
   
   This module is implemented by HTTP.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTTP_H
#define HTTP_H

#include "HTEvent.h"
#include "HTStream.h"
#include "HTFormat.h"

extern HTEventCallback HTLoadHTTP;
extern HTConverter HTTPStatus_new;

#endif /* HTTP_H */
/*

   
   ___________________________________
   
                              @(#) $Id: HTTP.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
