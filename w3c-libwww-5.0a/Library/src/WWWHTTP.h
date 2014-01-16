/*                                     W3C Reference Library libwww HTTP Client/Server Module
                         DECLARATION OF W3C REFERENCE HTTP MODULE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the include file for all HTTP access including the server side and the client
   side. It can be used together with the core of the W3C Reference Library. It contains
   all HTTP specific modules which are required to compile and build the HTTP DLL.
   
 */
#ifndef WWWHTTP_H
#define WWWHTTP_H
/*

 */
#ifdef __cplusplus
extern "C" {
#endif
/*

  System dependencies
  
   The sysdep.h file includes system-specific include files and flags for I/O to network
   and disk. The only reason for this file is that the Internet world is more complicated
   than Posix and ANSI.
   
 */
#include "sysdep.h"
/*

  Basic HTTP definitions and utilities
  
   A small set of very basic HTTP stuff
   
 */
#include "HTTPUtil.h"
/*

  HTTP Client State Machine
  
   The client statue machine handles the client side of HTTP generating requests and
   parsing responses.
   
 */
#include "HTTP.h"
/*

  HTTP Server State Machine
  
   The HTTP module also contains a very simple server module which can be used for
   experimenting but which is not a full blown server.
   
 */
#include "HTTPServ.h"                   /* HTTP server state machine */
/*

  General HTTP Header Stream
  
   The HTTP Request stream generates a HTTP request header and writes it to the target
   which is normally a HTWriter stream.
   
 */
#include "HTTPGen.h"
/*

  Client-side Request Generator Stream
  
   The HTTP Request stream generates a HTTP request header and writes it to the target
   which is normally a HTWriter stream.
   
 */
#include "HTTPReq.h"
/*

  Server-side Response Generator Stream
  
   The HTTP response stream generates a HTTP response header and writes it to the target
   which is normally a HTWriter stream.
   
 */
#include "HTTPRes.h"
/*

  Chunked Encoding and Decoding
  
   Chunked transfer encoding and decoding is new in HTTP/1.1. It allows applications to
   use persistent connections while not knowing the content length a priori to the
   response header is generated.
   
 */
#include "HTTChunk.h"
/*

  HTTP Extensions and PEP
  
   The PEP Manager is a registry for _PEP Protocols_ that follow the generic syntax
   defined by the HTTP _PEP protocol_ headers. All _PEP Protocols_ are registered at
   run-time in form of a _PEP Module_. A _PEP Module_ consists of the following:
   
 */
#include "HTPEP.h"
/*

  Generic Authentication
  
   The Authentication Manage_r_ is a registry for _Authentication Schemes_ that follow the
   generic syntax defined by the HTTP WWW-authenticateand Authorizationheaders. Currently,
   the only scheme defined is _Basic Authentication_, but _Digest Authentication _will
   soon follow. All _Authentication Schemes_ are registered at run-time in form of an
   _Authentication Module_. An _Authentication Module_ consists of the following:
   
 */
#include "HTAAUtil.h"
/*

  Client Side Authentication
  
   Contains code for parsing challenges and creating credentials for basic and digest
   authentication schemes. See also the HTAAUtil module for how to handle other
   authentication schemes.
   
 */
#include "HTAABrow.h"
/*

   End of HTTP module
   
 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                           @(#) $Id: WWWHTTP.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
