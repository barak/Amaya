/*                                            W3C Reference Library libwww News/NNTP Listings
                           NEWS/NNTP ARTICLE AND GROUP LISTINGS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module converts a generic News group listing to a HTML object
   
   This module is implemented by HTFTPDir.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTNEWSLS_H
#define HTNEWSLS_H
#include "HTStream.h"
#include "HTFormat.h"
#include "HTNet.h"

extern HTConverter HTNewsList, HTNewsGroup;
/*

  Newsgroup List Cache
  
   The news list cache uses a URL tree to store the information
   
 */
HTNetBefore HTNewsCache_before;
HTNetAfter HTNewsCache_after;
/*

 */
#endif /* HTNEWSLS_H */
/*

   
   ___________________________________
   
                           @(#) $Id: HTNewsLs.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
