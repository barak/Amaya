/*                                                     W3C Reference Library libwww URL Tress
                                        URL TREES
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   A _URL tree_ is a hierarchical container class that is well suited for storing
   information about a URL hierarchy. The _root_ of a URL tree is the _hostname_ part of
   the URL, for example www.w3.org:8000. Client application can use URL trees to store
   what they know about remote servers, for example the access authentication, PICS labels
   and PEP modules required to access a specific URL from a remote server. However, URL
   trees can also be used on server side to contain information about the server tree, for
   example what parts of the tree is protected etc.
   
   There are three components of the URL tree which all can be searched for using the
   methods declared in this module.
   
      The Tree itself
      
      A URL Node which represents a hierarchy level in a URL
      
      A URL Template which can span multiple nodes and are very similar to the realms
      known from for example Basic Access Authentication in HTTP.
      
   Typically, a URL tree will be empty when the application starts and as time goes by and
   we get to know more about the remote servers that we have access, the URL trees will
   contain more and more information. A nice feature about URL trees is that the
   application can interpolate information based on realms and templates. This gives the
   application a good chance of guessing what information (for example a set of
   credentials) should be appended to a new request.
   
   We do not currently distinguish between multiple access mechanisms, for example _HTTP_
   and _FTP_, however, URL trees are mostly used within the HTTP domain.
   
   _URL Trees_ are often used by filters which stores information about remote services,
   Each filter can have its own URL tree _or_ a URL tree can be shared among multiple
   filters.
   
   This module is implemented by HTUTree.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTUTREE_H
#define HTUTREE_H
#include "HTReq.h"
/*

URL TREES

   The three parts of a URL tree are called
   
 */
typedef struct _HTUTree     HTUTree;
typedef struct _HTURealm     HTURealm;
typedef struct _HTUTemplate HTUTemplate;
/*

  Create a URL Tree
  
   Create a new authentication base Returns new object or NULL if error
   
 */
typedef int HTUTree_gc          (void * context);

extern HTUTree * HTUTree_new (const char *              root,
                              const char *              host,
                              int                       port,
                              HTUTree_gc *              gc);
/*

  Delete a URL Tree
  
   Delete a complete server tree and everything within it.
   
 */
extern BOOL HTUTree_delete (const char *        root,
                            const char *        host,
                            int                 port);
/*

  Delete ALL URL Trees
  
   Delete all information bases
   
 */
extern BOOL HTUTree_deleteAll (void);
/*

  Find a URL Tree
  
   Find a authentication base. Return NULL if not found
   
 */
extern HTUTree * HTUTree_find (const char *     root,
                               const char *     host,
                               int              port);
/*

URL NODES

 */
extern void * HTUTree_findNode (HTUTree * tree,
                                const char * realm, const char * path);
/*

 */
extern BOOL HTUTree_addNode (HTUTree * tree,
                             const char * realm, const char * path,
                             void * context);
/*

 */
extern BOOL HTUTree_replaceNode (HTUTree * tree,
                                 const char * realm, const char * path,
                                 void * context);
/*

 */
extern BOOL HTUTree_deleteNode (HTUTree * tree,
                                const char * realm, const char * path);
/*

 */
#endif /* HTUTREE_H */
/*

   
   ___________________________________
   
                            @(#) $Id: HTUTree.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
