/*                                    W3C Reference Library libwww Private Request Definition
                                PRIVATE REQUEST DEFINITION
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module is the private part of the request object. It has the functions
   declarations that are private to the Library and that shouldn't be used by
   applications. The module has been separated from the old HTAccess module. See also the
   public part of the declarition in the HTReq Module.
   
   This module is implemented by HTReqMan.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTREQMAN_H
#define HTREQMAN_H

#include "HTReq.h"
#include "HTList.h"
#include "HTFormat.h"
#include "HTAnchor.h"
#include "HTMethod.h"
#include "HTAABrow.h"
#include "HTStream.h"
#include "HTNet.h"
#include "HTMIMPrs.h"
/*

   When a request is handled, all kinds of things about it need to be passed along
   together with a request. It is intended to live as long as the request is still active,
   but can be deleted as soon as it has terminated. Only the anchor object stays around
   after the request itself is terminated.
   
 */
struct _HTRequest {

    BOOL                internal;      /* Does the app knows about this one? */

    time_t              date;      /* Time stamp when the request was issued */

    HTMethod            method;

    HTPriority          priority;               /* Priority for this request */
/*

  User Profile
  
   Each request can be assigned a user profile containing information about this host and
   the user issuing the request.
   
 */
    HTUserProfile *     userprofile;
/*

  Net Object
  
   Each request is assigned a Net object which contains pointers to other objects handling
   the request.
   
 */
    HTNet *             net;                /* Information about socket etc. */
/*

  Response Object
  
   When we start getting MIME headers in as a response we keep it in this object until we
   know what to do with it.
   
 */
    HTResponse *        response;
/*

  Error Manager
  
 */
    HTList *            error_stack;                       /* List of errors */
/*

  Have many times do We Want to Try?
  
 */
    int                 retrys;               /* Number of automatic reloads */
    int                 max_forwards;
/*

  Preemtive or Non-Preemptive load?
  
   Each protocol module is registered with a default behavior but if you have registered a
   protocol module for non-preemtive load you can override this by using the following
   flag.
   
 */
    BOOL                preemptive;
/*

  Content Negotiation
  
   Normally, when we access the local file system we do content negotiation in order to
   find the most suited representation. However, you can turn this off by using the
   following flag.
   
 */
    BOOL                ContentNegotiation;
/*

  Headers and header information
  
   These are the masks that decides what headers to send.
   
 */
    HTGnHd              GenMask;
    HTRsHd              ResponseMask;
    HTRqHd              RequestMask;
    HTEnHd              EntityMask;

    HTList *            generators;
    BOOL                gens_local;
/*

  Local MIME Header Parsers
  
   Each request can be assigned its own MIME header parsers.
   
 */
    HTMIMEParseSet *    parseSet;
    BOOL                pars_local;
/*

  Accept headers
  
   These are the accept headers that we want to send out.
   
 */
    HTList *            conversions;
    BOOL                conv_local;

    HTList *            encodings;
    BOOL                enc_local;

    HTList *            ctes;
    BOOL                cte_local;

    HTList *            languages;
    BOOL                lang_local;

    HTList *            charsets;
    BOOL                char_local;

    HTList *            befores;
    BOOL                befores_local;

    HTList *            afters;
    BOOL                afters_local;
/*

  Are we using a Proxy?
  
   If so then we keep the name in this variable
   
 */
    char *              proxy;
    BOOL                full_uri;
/*

  Cache Control Directives
  
   This association list is a list of the cache control directives that are to be sent as
   part of the Cache-Controlheader.
   
 */
    HTReload            reload;
    HTAssocList *       cache_control;
/*

  Byte Ranges
  
   This association list is a list of the cache control directives that are to be sent as
   part of the Rangeheader.
   
 */
    HTAssocList *       byte_ranges;
/*

  Connection Control Directives
  
   This association list is a list of the connection control directives that are to be
   sent as part of the Connectionheader.
   
 */
    HTAssocList *       connection;
/*

  Access Authentication Information
  
   The credentialslist contains the information that we are to send as part of the
   Authorizationheader. The realm is if we already know that we need to generate
   credentials for a specific realm.
   
 */
    char *              realm;                              /* Current realm */
    HTAssocList *       credentials;       /* Credentials received by server */
/*

  Protocol Extension Protocol (PEP) Information
  
   These association lists contain the information that we are to send as PEP headers in
   the request.
   
 */
    HTAssocList *       protocol;
    HTAssocList *       protocol_info;
    HTAssocList *       protocol_request;
/*

  Anchors
  
 */
    HTParentAnchor *    anchor;        /* The Client anchor for this request */

    HTChildAnchor *     childAnchor;        /* For element within the object */
    HTParentAnchor *    parentAnchor;                   /* For referer field */
/*

  Streams From Network to Application
  
 */
    HTStream *          output_stream;
    HTFormat            output_format;
    BOOL                connected;

    HTStream*           debug_stream;
    HTFormat            debug_format;
/*

  Streams From Application to Network
  
 */
    HTStream *          input_stream;
    HTFormat            input_format;
/*

  Callback Function for getting data down the Input Stream
  
 */
    HTPostCallback *    PostCallback;
/*

  Context Swapping
  
 */
    HTRequestCallback * callback;
    void *              context;
/*

  PostWeb Information
  
 */
    HTRequest *         source;              /* Source for request or itself */
    HTParentAnchor *    source_anchor;            /* Source anchor or itself */

    HTRequest *         mainDestination;             /* For the typical case */
    HTList *            destinations;            /* List of related requests */
    int                 destRequests;      /* Number of destination requests */
    int                 destStreams;        /* Number of destination streams */
/*

 */
};
/*

POST WEB MANAGEMENT

   These functions are mainly used internally in the Library but there is no reason for
   them not to be public.
   
 */
extern BOOL HTRequest_addDestination (HTRequest * src, HTRequest * dest);
extern BOOL HTRequest_removeDestination (HTRequest * dest);
extern BOOL HTRequest_destinationsReady (HTRequest * me);

extern BOOL HTRequest_linkDestination (HTRequest * dest);
extern BOOL HTRequest_unlinkDestination (HTRequest * dest);

extern BOOL HTRequest_removePostWeb (HTRequest * me);
extern BOOL HTRequest_killPostWeb (HTRequest * me);

#define HTRequest_mainDestination(me) \
        ((me) && (me)->source ? (me)->source->mainDestination : NULL)
#define HTRequest_isDestination(me) \
        ((me) && (me)->source && (me) != (me)->source)
#define HTRequest_isMainDestination(me) \
        ((me) && (me)->source && \
        (me) == (me)->source->mainDestination)
#define HTRequest_isSource(me) \
        ((me) && (me)->source && (me) == (me)->source)
/*

   End of Declaration
   
 */
#endif /* HTREQMAN_H */
/*

   
   ___________________________________
   
                          @(#) $Id: HTReqMan.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
