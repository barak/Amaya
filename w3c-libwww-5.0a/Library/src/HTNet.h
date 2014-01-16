/*                                                   W3C Reference Library libwww HTNet Class
                                      THE NET CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The Net class manages information related to a "thread" in libwww. As libwww threads
   are not really threads but a notion of using interleaved, non-blocking I/O for
   accessing data objects from the network (or local file system), they can be used on any
   platform with or without support for native threads. In the case where you have an
   application using real threads the Net class is simply a object maintaining links to
   all other objects involved in serving the request. If you are using the libwww pseudo
   threads then the Net object contains enough information to stop and start a request
   based on which BSD sockets are ready. In practise this is of course transparent to the
   application - this is just to explain the difference.
   
   When a Request object is passed to the Library , the core creates a new HTNet object pr
   channel used by the request. In many cases a request only uses a single channel object
   but for example FTP requests use at least two - one for the control connection and one
   for the data connection.
   
   You can find more information about the libwww pseudo thread model in the  Multithread
   Specifications.
   
   This module is implemented by HTNet.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTNET_H
#define HTNET_H
/*

   The HTNet object is the core of the request queue management. This object contains
   information about the socket descriptor, the input read buffer etc. required to
   identify and service a request.
   
 */
typedef struct _HTNet HTNet;

#include "HTEvent.h"
#include "HTReq.h"
#include "HTResponse.h"
#include "HTTrans.h"
#include "HTHost.h"
#include "HTChannl.h"
#include "HTDNS.h"
/*

Generic BEFORE and AFTER Filter Management

   Filter functions can be registered to be called before and after a request has either
   been started or has terminated. The conditions for BEFORE and AFTER filters are not the
   same so we maintain them independently. Filters can be registered globally or locally.
   The global filters are registered directly by the Net Object (this module) and the
   local filters are registered by the HTRequest Object. However, both &nbsp;local and
   global filters use the same regisration mechanism which we provide here.
   
  FILTER ORDERING
  
   Filters can be registered by anyone and as they are an often used mechanism for
   introducing extensions in libwww, they are videly used to handle authentication,
   redirection, etc. Many filters can be registered at once and not all of the filters may
   know about the other filters. Therefore, it is difficult to specify an absolute
   ordering by which the filters should be called. Instead you can decide a relative order
   by which the filters should be called. The order works pretty much like the Unix
   priority mechanism running from HT_FILTER_FIRST to HT_FILTER_LAST having
   HT_FILTER_MIDDLE being the "normal" case.
   
 */
typedef enum _HTFilterOrder {
    HT_FILTER_FIRST     = 0x0,          /*     0 */
    HT_FILTER_EARLY     = 0x3FFF,       /* 16383 */
    HT_FILTER_MIDDLE    = 0x7FFF,       /* 32767 */
    HT_FILTER_LATE      = 0xBFFE,       /* 49150 */
    HT_FILTER_LAST      = 0xFFFF        /* 65535 */
} HTFilterOrder;
/*

   In case multiple filters are registered with the same order then they are called in the
   inverse order they were registered.&nbsp;
   
  FILTER URL TEMPLATES
  
   Both BEFORE and AFTER filters can be registered with a URL template in which case they
   are only called when the Request URLmatches the template. A template is simply a string
   which is matched against the Request URL. The string can be terminated by a&nbsp;single
   "*" in which case all strings matching the template up til the "*" is considered a
   match. A template can be as short as the access scheme which enmables a filter for a
   specific access method only, for example "http//<star>".
   
  BEFORE FILTERS
  
   A BEFORE filter is called whenever we issue a request and they have been selected by
   the execution procedure. BEFORE filters are registered with a context and a filter
   order by which they are to be called and a URL template which may be NULL. In this
   case, the filter is called on every request. The mode can be used by anybody to pass an
   extra parameter to a filter. This is not really OO thinking - but hey - this is C ;-)
   
 */
typedef int HTNetBefore (HTRequest * request, void * param, int mode);
/*

   You can add a BEFORE filter in the list provided by the caller. Several filters can be
   registered in which case they are called with the filter ordering in mind.
   
 */
extern BOOL HTNetCall_addBefore (HTList * list, HTNetBefore * before,
                                 const char * tmplate, void * param,
                                 HTFilterOrder order);
/*

   You can also unregister all instances of a BEFORE filter from a list using the
   following function
   
 */
extern BOOL HTNetCall_deleteBefore (HTList * list, HTNetBefore * before);
/*

   You get rid of all BEFORE filters usign this function
   
 */
extern BOOL HTNetCall_deleteBeforeAll (HTList * list);
/*

   The BEFORE filters are expected and called if appropriate every time we issue a new
   request. Libwww calls the BEFORE filters in the order specified at registration time.
   If a filter returns other than HT_OK then stop and return immediately. Otherwise return
   what the last filter returns.
   
 */
extern int HTNetCall_executeBefore (HTList * list, HTRequest * request);
/*

  AFTER FILTERS
  
   An AFTER filter is called whenever we have terminated a request. That is, on the way
   out from the protocol module and back to the application. AFTER filters are registered
   with a context, a status, a filter order by which they are to be called and a URL
   template which may be NULL. The status of the request may determine which filter to
   call. The set of possible values are given below. An AFTER filter can be registered to
   handle one or more of the codes.
   
  HT_ERROR                   An error occured
                         
      HT_LOADED              The document was loaded
                         
      HT_NO_DATA             OK, but no data
                         
      HT_NO_ACCESS           The request could not be succeeded due to lack of credentials
                         
                         
      HT_NO_PROXY_ACCESS
                             The request could not be succeeded due to lack of credentials
                         for accessing     an intermediate proxy
                         
      HT_RETRY               Retry request after at a later time
                         
      HT_PERM_REDIRECT
                             The request has been permanently redirected and we send back
                         the new URL
                         
      HT_TEMP_REDIRECT
                             The request has been temporaryly redirected and we send back
                         the new URL
                         
      HT_ALL                 All of above
                         
   A Protocol module can also in certain cases return a HT_IGNORE in which case no filters
   are called
   
 */
typedef int HTNetAfter (HTRequest * request, HTResponse * response,
                        void * param, int status);
/*

   You can register a AFTER filter in the list provided by the caller. Several filters can
   be registered in which case they are called with the filter ordering in mind.
   
 */
extern BOOL HTNetCall_addAfter (HTList * list, HTNetAfter * after,
                                const char * tmplate, void * param,
                                int status, HTFilterOrder order);
/*

   You can either unregister all filters registered for a given status using this function
   or the filter for all status codes.
   
 */
extern BOOL HTNetCall_deleteAfter (HTList * list, HTNetAfter * after);
extern BOOL HTNetCall_deleteAfterStatus (HTList * list, int status);
/*

   You can also delete all AFTER filters in list
   
 */
extern BOOL HTNetCall_deleteAfterAll (HTList * list);
/*

   This function calls all the AFTER filters in the order specified at registration time
   and if it has the right status code and it's not HT_IGNORE. We also check for any
   template and whether it matches or not. If a filter returns other than HT_OK then stop
   and return immediately. Otherwise return what the last filter returns.
   
 */
extern int HTNetCall_executeAfter (HTList * list, HTRequest * request,
                                   int status);
/*

Global BEFORE and AFTER Filter Management

   Global filters are inspected on every request (they do not have to be called - only if
   the conditions match). You can also register filters locally in the Request object.
   
    Global BEFORE Filters
    
   These are the methods to handle global BEFORE Filters.
   
 */
extern BOOL HTNet_setBefore (HTList * list);

extern HTList * HTNet_before (void);

extern BOOL HTNet_addBefore (HTNetBefore * before, const char * tmplate,
                             void * param, HTFilterOrder order);

extern BOOL HTNet_deleteBefore (HTNetBefore * before);
/*

   You can call both the local and the global BEFORE filters (if any)
   
 */
extern int HTNet_executeBeforeAll (HTRequest * request);
/*

    Global AFTER Filters
    
   These are the methods to handle global AFTER Filters.
   
 */
extern BOOL HTNet_setAfter (HTList * list);

extern HTList * HTNet_after (void);

extern BOOL HTNet_addAfter (HTNetAfter * after, const char * tmplate,
                            void * param, int status,
                            HTFilterOrder order);

extern BOOL HTNet_deleteAfter (HTNetAfter * after);

extern BOOL HTNet_deleteAfterStatus (int status);
/*

   You can call both the local and the global AFTER filters (if any)
   
 */
extern int HTNet_executeAfterAll (HTRequest * request, int status);
/*

Socket Resource Management

   The request queue ensures that no more than a fixed number of TCP connections are open
   at the same time. If more requests are handed to the Library, they are put into the
   pending queue and initiated when sockets become free.
   
  NUMBER OF SIMULTANOUS OPEN TCP CONNECTIONS
  
   Set the max number of simultanous sockets. The default value is HT_MAX_SOCKETS which is
   6. The number of persistent connections depend on this value as a deadlock can occur if
   all available sockets a persistent (see the DNS Manager for more information on setting
   the number of persistent connections). The number of persistent connections can never
   be more than the max number of sockets-2, so letting newmax=2 prevents persistent
   sockets.
   
 */
extern BOOL HTNet_setMaxSocket (int newmax);
extern int  HTNet_maxSocket (void);
/*

  SOCKET COUNTERS
  
 */
extern void HTNet_increaseSocket (void);
extern void HTNet_decreaseSocket (void);

extern int HTNet_availableSockets (void);
/*

  PERSISTENT SOCKET COUNTERS
  
 */
extern void HTNet_increasePersistentSocket (void);
extern void HTNet_decreasePersistentSocket (void);

extern int HTNet_availablePersistentSockets (void);
/*

  ANY ONGOING CONNECTIONS?
  
   Returns whether there are active requests. Idle persistent sockets do not count as
   active.
   
 */
extern BOOL HTNet_isIdle (void);
/*

  LIST ACTIVE QUEUE
  
   Returns the list of active requests that are currently having an open connection.
   Returns list of HTNet objects or NULL if error.
   
 */
extern HTList *HTNet_activeQueue (void);
extern BOOL HTNet_idle (void);
/*

  ARE WE ACTIVE?
  
   We have some small functions that tell whether there are registered requests in the Net
   manager. There are tree queues: The active, the pending, and the persistent. The active
   queue is the set of requests that are actively sending or receiving data. The pending
   is the requests that we have registered but which are waiting for a free socket. The
   Persistent queue are requets that are waiting to use the same socket in order to save
   network resoures (if the server understands persistent connections).
   
    Active Reqeusts?
    
   Returns whether there are requests in the active queue or not
   
 */
extern BOOL HTNet_idle (void);
/*

    Registered Requests?
    
   Returns whether there are requests registered in any of the lists or not
   
 */
extern BOOL HTNet_isEmpty (void);
/*

  LIST PENDING QUEUE
  
   Returns the list of pending requests that are waiting to become active. Returns list of
   HTNet objects or NULL if error
   
 */
extern HTList *HTNet_pendingQueue (void);
/*

Creation and Deletion Methods

   The Net object is intended to live as long as the request is still active. In that
   regard it is very similar to the Request Object. However, the main difference is that a
   Net object represents a "thread" in the Library and a request may have multiple
   "threads" - an example is a FTP request which has a thread to handle the control
   connection and one to handle the data connections.
   
  CREATE A NEW OBJECT
  
   If we have more than HTMaxActive connections already then put this into the pending
   queue, else start the request by calling the call back function registered with this
   access method. Returns YES if OK, else NO
   
 */
extern BOOL HTNet_newClient (HTRequest * request);
/*

   You can create a new HTNet object as a new request to be handled. If we have more than
   HTMaxActive connections already then return NO. Returns YES if OK, else NO
   
 */
extern BOOL HTNet_newServer (HTRequest * request, HTNet * net, char *access);
/*

   And you can create a plain new HTNet object using the following method:
   
 */
extern HTNet * HTNet_new (SOCKET sockfd, HTRequest * request);
/*

  DUPLICATE AN EXISTING OBJECT
  
   Creates a new HTNet object as a duplicate of the same request. Returns YES if OK, else
   NO.
   
 */
extern HTNet * HTNet_dup (HTNet * src);
/*

  LAUNCH A NET OBJECT
  
   Start a Net obejct by calling the protocol module.
   
 */
extern BOOL HTNet_start (HTNet * net);
/*

  DELETE AN OBJECT
  
   Deletes the HTNet object from the list of active requests and calls any registered call
   back functions IF not the status is HT_IGNORE. This is used if we have internal
   requests that the app doesn't know about. We also see if we have pending requests that
   can be started up now when we have a socket free. The filters are called in the reverse
   order of which they were registered (last one first);
   
 */
extern BOOL HTNet_delete (HTNet * me, int status);
/*

  DELETE ALL HTNET OBJECTS
  
   Deletes all HTNet object that might either be active or pending We DO NOT call the call
   back functions - A crude way of saying goodbye!
   
 */
extern BOOL HTNet_deleteAll (void);
/*

Net Class Methods

  MAKE AN OBJECT WAIT
  
   Let a net object wait for a persistent socket. It will be launched from the
   HTNet_delete() function when the socket gets free.
   
 */
extern BOOL HTNet_wait (HTNet *net);
/*

  PRIORITY MANAGEMENT
  
   Each HTNet object is created with a priority which it inherits from the Request
   manager. However, in some stuations it is useful to be to change the current priority
   after the request has been started. These two functions allow you to do this. The
   effect will show up the first time (which might be imidiately) the socket blocks and
   control returns to the event loop. Also have a look at how you can do this before the
   request is issued in the request manager.
   
 */
extern HTPriority HTNet_priority (HTNet * net);
extern BOOL HTNet_setPriority (HTNet * net, HTPriority priority);
/*

  PERSISTENT CONNECTIONS
  
   You can set a Net object to handle persistent connections for example using HTTP, NNTP,
   or FTP. You can control whether a Net object supports persistent connections or not
   using this function.
   
 */
extern BOOL HTNet_persistent (HTNet * net);
/*

   You can set or disable a Net object supporting persistent connections using this
   function:
   
 */
extern BOOL HTNet_setPersistent (HTNet *           net,
                                 BOOL              persistent,
                                 HTTransportMode   mode);
/*

  KILL A REQUEST
  
   Kill the request by calling the call back function with a request for closing the
   connection. Does not remove the object. This is done by HTNet_delete() function which
   is called by the load routine. Returns OK if success, NO on error
   
 */
extern BOOL HTNet_kill (HTNet * me);
/*

  KILL ALL REQUESTS
  
   Kills all registered (active+pending) requests by calling the call back function with a
   request for closing the connection. We do not remove the HTNet object as it is done by
   HTNet_delete(). Returns OK if success, NO on error
   
 */
extern BOOL HTNet_killAll (void);
/*

  CREATE INPUT AND OUTPUT STREAMS
  
   You create the input stream and bind it to the channel using the following methods.
   Please read the description in the HTIOStream module on the parameters target, param,
   and mode. Both methods return YES if OK, else NO.
   
 */
extern HTInputStream * HTNet_getInput (HTNet * net, HTStream * target,
                                       void * param, int mode);

extern HTOutputStream * HTNet_getOutput (HTNet * net, void * param, int mode);
/*

  NET CONTEXT DESCRIPTOR
  
   Just like the request object, a net object can be assigned a context which keeps track
   of context dependent information. The Library does not use this information nor does it
   depend on it but it allows the application to customize a net object to specific uses.
   
 */
extern BOOL HTNet_setContext (HTNet * net, void * context);
extern void * HTNet_context (HTNet * net);
/*

  SOCKET DESCRIPTOR
  
 */
extern BOOL HTNet_setSocket (HTNet * net, SOCKET sockfd);
extern SOCKET HTNet_socket (HTNet * net);
/*

  THE REQUEST OBJECT
  
   The Request object is normally set up automatically but can be changed at a later time.
   
 */
extern BOOL HTNet_setRequest (HTNet * net, HTRequest * request);
extern HTRequest * HTNet_request (HTNet * net);
/*

  THE TRANSPORT OBJECT
  
   The transport object is normally set up automatically but can be changed at a later
   time.
   
 */
extern BOOL HTNet_setTransport (HTNet * net, HTTransport * tp);
extern HTTransport * HTNet_transport (HTNet * net);
/*

  THE CHANNEL OBJECT
  
 */
extern BOOL HTNet_setChannel (HTNet * net, HTChannel * channel);
extern HTChannel * HTNet_channel (HTNet * net);
/*

  THE HOST OBJECT
  
 */
extern BOOL HTNet_setHost (HTNet * net, HTHost * host);
extern HTHost * HTNet_host (HTNet * net);
/*

  THE DNS OBJECT
  
   The DNS object keeps track of the DNS entries that we have already checked out.
   
 */
extern BOOL HTNet_setDns (HTNet * net, HTdns * dns);
extern HTdns * HTNet_dns (HTNet * net);
/*

   If we are talking to a multi-homed host then we may connect to any of the homes. In
   that case we store the current home in the Net object so that we can query about it
   later.
   
 */
extern int HTNet_home (HTNet * net);
/*

 */
#endif /* HTNET_H */
/*

   
   ___________________________________
   
                              @(#) $Id: HTNet.h,v 1.2 1996/10/15 13:40:32 cvs Exp $
                                                                                          
    */
