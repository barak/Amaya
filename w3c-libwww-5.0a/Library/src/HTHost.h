/*                                                    W3C Reference Library libwww Host Class
                                      THE HOST CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The Host class manages what we know about a remote host. This can for example be what
   type of host it is, and what version it is using. Notice that a host object can be used
   to describe both a server or a client - all information in the Host object can be
   shared regardless of whether it is to be used in a server application or a client
   application.
   
   This module is implemented by HTHost.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTHOST_H
#define HTHOST_H

typedef struct _HTHost HTHost;

#include "HTChannl.h"
#include "HTReq.h"
#include "HTEvent.h"
/*

   The Host class contains information about the remote host, for example the type
   (HTTP/1.0, HTTP/1.1, FTP etc.) along with information on how the connections can be
   used (if it supports persistent connections, interleaved access etc.)
   
CREATION AND DELETION METHODS

   We keep a cache of information that we know about a remote host. This allows us to be
   much more detailed in generating requests. Search the host info cache for a host object
   or create a new one and add it. Examples of host names are
   
      www.w3.org
      
      www.foo.com:8000
      
  Add a Host Object
  
 */
extern HTHost * HTHost_new (char * host);
/*

  Delete a Host Object
  
   The Host Class contains an automatic garbage collection of Host objects so that we
   don't keep information around that is stale.
   
  Find a Host Object
  
   Searches the cache of known hosts to see if we already have information about this
   host. If not then we return NULL.
   
 */
extern HTHost * HTHost_find (char * host);
/*

HOST CLASS METHODS

   This is what we know about the remote host
   
  Remote Host Name
  
   Get the name of the remote host. This is set automatically when a new Host object and
   can be asked for at any point in time. You can not change the host name but must create
   a new Host object instead.
   
 */
extern char * HTHost_name       (HTHost * host);
/*

  Remote Host Protocol Class and Version
  
   Define the host classof the host at the other end. A class is a generic description of
   the protocol which is exactly like the access method in a URL, for example "http" etc.
   The host versionis a finer distinction (sub-class) between various versions of the host
   class, for example HTTP/0.9, HTTP/1.1 etc. The host version is a bit flag that the
   protocol module can define on its own. That way we don't have to change this module
   when registering a new protocol module. The host typeis a description of whether we can
   keep the connection persistent or not.
   
 */
extern char * HTHost_class      (HTHost * host);
extern void HTHost_setClass     (HTHost * host, char * s_class);

extern int  HTHost_version      (HTHost * host);
extern void HTHost_setVersion   (HTHost * host, int version);
/*

  Remote host Options and Services
  
   We keep track of the capabilities of the remote host. In many cases the information
   that we get is specific to servers but this doesn't _have_ to be the case.
   
    Public Methods accessible on This Host
    
   A server can inform a client about the supported methods using the Publicheader.
   
 */
extern HTMethod HTHost_publicMethods    (HTHost * me);
extern void HTHost_setPublicMethods     (HTHost * me, HTMethod methodset);
extern void HTHost_appendPublicMethods  (HTHost * me, HTMethod methodset);
/*

    Server Name of Remote Host
    
   A server can send its server application name and version in a HTTP response. We pick
   up this information and add it to the Host object
   
 */
extern char * HTHost_server     (HTHost * host);
extern BOOL HTHost_setServer    (HTHost * host, const char * server);
/*

    User Agent Name of Remote Host
    
   A client can send the name of the client application in a HTTP request. We pick up this
   information and add it to the Host Object
   
 */
extern char * HTHost_userAgent  (HTHost * host);
extern BOOL HTHost_setUserAgent (HTHost * host, const char * userAgent);
/*

    Range Units Accepted by this Host
    
   Since all HTTP entities are represented in HTTP messages as sequences of bytes, the
   concept of a byte range is meaningful for any HTTP entity. (However, not all clients
   and servers need to support byte-range operations.) Byte range specifications in HTTP
   apply to the sequence of bytes in the entity-body (not necessarily the same as the
   message-body). A byte range operation may specify a single range of bytes, or a set of
   ranges within a single entity.
   
   You can also check whether a specific range unit is OK. We always say YESexcept if we
   have a specific statement from the server that it doesn't understand byte ranges - that
   is - it has sent "none" in a "Accept-Range" response header
   
 */
extern char * HTHost_rangeUnits  (HTHost * host);
extern BOOL HTHost_setRangeUnits (HTHost * host, const char * units);
extern BOOL HTHost_isRangeUnitAcceptable (HTHost * host, const char * unit);
/*

  Register a Persistent Channel
  
   We don't want more than MaxSockets-2 connections to be persistent in order to avoid
   deadlock.
   
 */
extern BOOL HTHost_setChannel (HTHost * host, HTChannel * channel,
                               HTTransportMode mode);
extern BOOL HTHost_clearChannel (HTHost * host, int status);

extern HTChannel * HTHost_channel (HTHost * host);
/*

  Is this host Persistent?
  
   Check whether we have a persistent channel or not
   
 */
extern BOOL HTHost_isPersistent (HTHost * host);
/*

  Is the Host Idle
  
   Before we can start a new connection to the host we must be sure that the host is idle.
   That is, if it can accept a new connection. We have several modes describing how and
   when a host is idle. This is a function of the Transport Object
   
 */
extern BOOL HTHost_isIdle (HTHost * host);
/*

  Handling the Transport Mode
  
   Handle the connection mode. The mode may change mode in the middle of a connection If
   the new mode is lower than the old mode then adjust the pipeline accordingly. That is,
   if we are going into single mode then move all entries in the pipeline and move the
   rest to the pending queue. They will get launched at a later point in time.
   
 */
extern HTTransportMode HTHost_mode (HTHost * host, BOOL * active);
extern BOOL HTHost_setMode (HTHost * host, HTTransportMode mode);
/*

  Timing Persistent Channels
  
   Normally we wait for the peer process to close persistent connections but in order not
   to use up our own resources, we have a timeout on our own. The default value is 1 hour,
   but you can modify the value using the following methods:
   
 */
extern time_t HTHost_persistTimeout (time_t timeout);
extern void HTHost_setPersistTimeout (time_t timeout);
/*

   Each persistent connection has an absolute value of when this connection most likely
   will expire. If the peer process does not inform us, we use our own timeout.
   
 */
extern void HTHost_setPersistExpires (HTHost * host, time_t expires);
extern time_t HTHost_persistExpires (HTHost * host);
/*

QUEUING REQUESTS

   Requests are queued in the Host object until we have resources to start them. The
   request is in the form of a Net object as we may have multiple socket requests per
   Request object. This is for example the case with FTP which uses two connections.
   
 */
extern int HTHost_addNet     (HTHost * host, HTNet * net);
extern BOOL HTHost_deleteNet (HTHost * host, HTNet * net);
extern HTList * HTHost_net   (HTHost * host);
/*

  Is the Host Idle
  
   Before we can start a new connection to the host we must be sure that the host is idle.
   That is, if it can accept a new connection. We have several modes describing how and
   when a host is idle. This is a function of the Transport Object
   
 */
extern BOOL HTHost_isIdle (HTHost * host);
/*

  Handling Pending Requests
  
   There are two ways we can end up with pending reqyests:
   
      If we are out of sockets then register new host objects as pending.
      
      If we are pending on a connection then register new net objects as pending
      
   This set of functions handles pending host objects and can start new requests as
   resources get available. The first function checks the host object for any pending Net
   objects and return the first of these Net objects.
   
 */
extern HTNet * HTHost_nextPendingNet (HTHost * host);
/*

   The second checks the list of pending host objects waiting for a socket and returns the
   first of these Host objects.
   
 */
extern HTHost * HTHost_nextPendingHost (void);
/*

   Start the next pending request if any. First we look for pending requests for the same
   host and then we check for any other pending hosts. If nothing pending then register a
   catch close event handler to have something catching the socket if the remote server
   closes the connection, for example due to timeout.
   
 */
extern BOOL HTHost_launchPending (HTHost * host);
/*

   A new callback plugged to the activation of a request. Allows to simplify
   Amaya's use of libwww.
*/

typedef int HTHost_ActivateRequestCallback (HTRequest *);

extern void HTHost_setActivateRequestCallback (HTHost_ActivateRequestCallback * cbf);

/* 
   Controls whether pending requests should be automatically activated.
*/
PUBLIC void HTHost_enable_PendingReqLaunch (void);
PUBLIC void HTHost_disable_PendingReqLaunch (void);

/*
 */
#endif /* HTHOST_H */
/*

   
   ___________________________________
   
                             @(#) $Id: HTHost.h,v 1.2 1997/09/15 16:11:37 cvs Exp $
                                                                                          
    */
