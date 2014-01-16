/*                                                   W3C Reference Library libwww Event Class
                                     THE EVENT CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The Event Class defines any event manager to be used by libwww for handling events. An
   _event_ is not strictly defined as it is highly platform dependent and hence out of
   scope for the Library. If you are using the libwww pseudo threads on Unix then an event
   is when the _select()_ system call returns a notification on a socket descriptor, but
   it may as well be an asynchronous event from the windows manager etc. If your
   application is not using anything but traditional blocking sockets then you do not need
   an event manager at all. In that case, libwww will block on any socket or system call
   until the process can proceed.
   
   The libwww interface to an event manager is very simple as it consists of _registering_
   a _socket descriptor_, the _location_ in the program, and the _current state_ when an
   operation (for example read) would block. When the event manager at a later point in
   time gets a notification that the socket has become ready, it can then call libwww with
   the state saved from the registration and libwww can continue. Second, libwww must be
   able to _unregister_ a socket when it is not anymore in a state where it can block.
   _Only_ in case the application wishes to use _non-blocking_ sockets it should register
   methods for handling the _registration_ process as described below.
   
   _Note_: The library _core_ does _not_ define any event manager - it is considered part
   of the application. The library comes with a default event manager which can be
   initiated using the function HTEventInit()in HTInit module
   
   This module is implemented by HTEvent.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTEVENT_H
#define HTEVENT_H
#include "sysdep.h"

#define FD_NONE 0
#define FD_ALL (FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT |FD_CLOSE)
#define FD_UNREGISTER (((FD_ALL) << 1) & (~(FD_ALL)))

typedef enum _HTPriority {
    HT_PRIORITY_INV = -1,
    HT_PRIORITY_OFF = 0,
    HT_PRIORITY_MIN = 1,
    HT_PRIORITY_MAX = 20
} HTPriority;

typedef u_long SockOps;

#include "HTReq.h"
/*

EVENT HANDLERS

   A _location_ is a function that can be registered by the event manager and called at a
   later point in time in order to continue an operation. All locations must be of type
   HTEventCallbackas defined here:
   
 */
typedef int HTEventCallback (SOCKET, HTRequest *, SockOps);
/*

   There are many default event handlers provided with the Library. For example, all the
   protocol modules such as the HTTP client module are implemented as event handlers. In
   stead of using blocking sockets, this allows a protocol module to register itself when
   performing an operation that would block. When the sockets becomes ready the handler is
   called with th socket in question, the request object, and the socket operation
   
REGISTERING AND UNREGISTERING EVENT HANDLERS

   As mentioned above, the only interface libwww requires from an event manager is a
   method to _register_ an event handler when an operation would block and _unregister_ it
   when the operation has completed The library registers and unregisters event handlers
   by calling the following two functions:
   
 */
extern int HTEvent_register     (SOCKET, HTRequest *,
                                 SockOps, HTEventCallback *,
                                 HTPriority);
extern int HTEvent_unregister   (SOCKET, SockOps);
/*

   The register function contains information about which socket we are waiting on to get
   ready and which operation we are waiting for (read, write, etc.), the request object
   containing the current request, the event handler that we want to be called when the
   socket becomes reasy, and finally the priority by which we want the thread to be
   processed by the event manager. Likewise, libwww can unregister a operation on a socket
   which means that libwww is no longer waiting for this actiion to become ready.
   
REGISTERING AN EVENT MANAGER

   The Library core does not contain any event manager as it depends on whether you want
   to use pseudo threads no threads, or real threads. Instead, libwww comes with a default
   implementation that you may register, but you may as well implement and register your
   own. The register and unregister functions above actually does nothing than looking for
   a registered event manager and then passes the call on to that. You register your own
   event manager by using the methods below:
   
 */
typedef int HTEvent_registerCallback(SOCKET, HTRequest *,
                                     SockOps, HTEventCallback *,
                                     HTPriority);
typedef int HTEvent_unregisterCallback(SOCKET, SockOps);

extern void HTEvent_setRegisterCallback(HTEvent_registerCallback *);
extern void HTEvent_setUnregisterCallback(HTEvent_unregisterCallback *);
/*

   You can register the event manager provided together with libwww by using the
   HTEventInit()in the HTInit module
   
 */
#endif /* HTEVENT_H */
/*

   
   ___________________________________
   
                               @(#) $Id: HTEvent.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
