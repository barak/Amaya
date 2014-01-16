/*         W3C Reference Library libwww Client Side Authentication Challenges and Credentials
                  CLIENT SIDE AUTHENTICATION CHALLENGES AND CREDENTIALS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   Contains code for parsing challenges and creating credentials for basic and digest
   authentication schemes. See also the HTAAUtil module for how to handle other
   authentication schemes. You don't have to use this code at all if you better like to
   use your own functions for parsing challenges and generating credentials. All functions
   are implemented as callback functions to the Authentication Manager
   
   This module is implemented by HTAABrow.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTAABROW_H
#define HTAABROW_H
#include "HTUTree.h"
#include "HTNet.h"
/*

BASIC AUTHENTICATION

   This is the set of callback functions for handling basic authentication.
   
 */
extern HTNetBefore      HTBasic_generate;
extern HTNetAfter       HTBasic_parse;
extern HTUTree_gc       HTBasic_delete;
/*

 */
#endif  /* NOT HTAABROW_H */
/*

   
   ___________________________________
   
                          @(#) $Id: HTAABrow.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
