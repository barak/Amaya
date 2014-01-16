/*                                                    W3C Reference Library libwww PEP Engine
                                        PEP ENGINE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The _PEP Manager_ is a registry for _PEP Protocols_ that follow the generic syntax
   defined by the HTTP _PEP protocol_ headers. All _PEP Protocols_ are registered at
   run-time in form of a _PEP Module_. A _PEP Module_ consists of the following:
   
  _protocol_             The name which is used to identify the protocol.
                         
  _BEFORE Filter_        When a new request is issued, the _PEP Manager_ looks in the URL
                         tree to see if we have any PEP information for this particular
                         request. The search is based on the realm (if known) in which the
                         request belongs and the URL itself. If a record is found then the
                         _PEP Manager_ calls the _PEP Module_ in order to generate the PEP
                         protocol headers.
                         
  _AFTER Filter_         After a request has terminated and the result was lack of
                         required PEP protocol headers, the request should normally be
                         repeated with a new set of PEP protocol headers. The AFTER filter
                         is responsible for extracting the challenge from the HTTP
                         response and store it in the URL tree, so that we next time we
                         request the same URL we know that it is protected and we can ask
                         the user for the appropriate PRP protocol headers.
                         
  _garbage collection_   The PEP information is stored in a URL Tree but as it doesn't
                         know the format of the protocol specific parts, you must register
                         a garbage collector (gc). The gc is called when node is deleted
                         in the tree.
                         
   _Note: _The _PEP Manager_ itself consists of _BEFORE_ and an _AFTER_ filter - just like
   the _PEP Modules_. This means that any _PEP Module_ also can be registered directly as
   a _BEFORE_ and _AFTER_ filter by the Net Manager. The reason for having the two layer
   model is that the _PEP Manager_ maintains a single URL tree for storing PEP information
   for all _PEP Protocols_.
   
   A_PEP Module_ has three resources, it can use when creating PEP protocol headers:
   
      Handle the _PEP protocol headers_ send from the remote party (typically in the form
      of a HTTP response.
      
      Handle the _PEP protocol headers_ which typically are to part of the next request.
      
      Add information to the URL Tree
      
   This module is implemented by HTPEP.c (get it?), and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTPEP_H
#define HTPEP_H
#include "HTList.h"
#include "HTReq.h"
#include "HTUTree.h"

typedef struct _HTPEPModule HTPEPModule;
/*

PEP MODULE REGISTRATION

   A _PEP Protocol_ is registered by registering an _PEP Module_ to in the _PEP Manager_.
   
  Add a PEP Module
  
   You can add a PEP protocol by using the following method. Each of the callback function
   must have the type as defined below.
   
 */
extern HTPEPModule * HTPEP_newModule(const char *       protocol,
                                     HTNetBefore *      before,
                                     HTNetAfter *       after,
                                     HTUTree_gc *       gc);
/*

  Find a PEP Module
  
 */
extern HTPEPModule * HTPEP_findModule (const char * protocol);
/*

  Delete a PEP Module
  
 */
extern BOOL HTPEP_deleteModule (const char * protocol);
/*

  Delete ALL PEP modules
  
 */
extern BOOL HTPEP_deleteAllModules (void);
/*

HANDLING THE URL TREE

   The PEP information is stored as URL Trees.  The root of a URL Tree is identified by a
   _hostname_ and a _port number_. Each URL Tree contains a set of templates and realms
   which can be used to predict what information to use in a hierarchical tree.
   
   The URL trees are automatically collected after some time so the application does not
   have to worry about freeing the trees. When a node in a tree is freed, the gc
   registered as part of the PEP Module is called.
   
   Server applications can have different PEP setups for each hostname and port number,
   they control. For example, a server with interfaces "www.foo.com" and
   "internal.foo.com" can have different protection setups for each interface.
   
  Add information to the Database
  
   Add a PEP information node to the database. If the entry is already found then it is
   replaced with the new one. The template must follow normal URI syntax but can include a
   wildcard Return YES if added (or replaced), else NO
   
 */
extern HTPEPModule * HTPEP_findModule (const char * name);
/*

THE PEP MANAGER FILTERS

   As mentioned, the _PEP Manager_ is itself a set of filters that can be registered by
   the Net manager.
   
 */
extern HTNetBefore HTPEP_beforeFilter;
extern HTNetAfter  HTPEP_afterFilter;
/*

 */
#endif  /* NOT HTPEP_H */
/*

   
   ___________________________________
   
                              @(#) $Id: HTPEP.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
