/*                                        W3C Reference Library libwww Default Initialization
                                   APPLICATION PROFILES
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   As mentioned in the Library Architecture, libwww consists of a small core and a large
   set of hooks for adding functionality. By itself, the core it not capable of performing
   any Web related tasks like accessing a HTTP server or parsing a HTML document. All this
   functionality must be registered by the application. This way, the core of libwww is
   kept application independent and can be used as the basic building block for any kind
   of Web application.
   
   The Library comes with a large set of default functions, for example for accessing HTTP
   and FTP servers, parsing RFC 822 headers etc. but it must all be registered by the
   application before the core knows about it. You can either register the parts directly
   through the many initialization functions in the Initialization Interface or you can
   use these "precompiled" profiles which are set up to contain the featuers often used by
   the a specific type of application, for example a client, a server, a robot etc.
   
   This module helps the application programmer setting up all this functionality, but it
   is important to note that none of it is _required_ in order to use the Library. All the
   profiles declared below superseed the Library core initialization function
   HTLibInit()which is defined in the HTLib module.
   
   This module is implemented by HTProf.c, and it is a part of the W3C Reference Library.
   You can also have a look at the other Initialization modules.
   
 */
#ifndef HTPROF_H
#define HTPROF_H
#include "WWWLib.h"
#include "WWWInit.h"
/*

CLIENT APPLICATION PROFILES

   We have a couple of different client application profiles suited to different types of
   clients. The first uses a non-blocking socket interface which enables the application
   to perform multiple requests simultanously - in everyday words called pseudo-threads.
   Besides that this profile contains typical filters for handling redirection,
   authentication, logging, and proxy servers.
   
 */
extern void HTProfile_newClient (const char * AppName, const char * AppVersion);
/*

   We also have a blocking (preemptive) version of the same client interface. The
   difference is that this version uses traditional blocking sockets and hence only one
   reques can be performed at the same time.
   
 */
extern void HTProfile_newPreemptiveClient (const char * AppName,
                                           const char * AppVersion);
/*

ROBOT APPLICATION PROFILE

   The robot profile contains much of the same functionality as the client, but it does
   contain less filters. For example, robots are normally not interested in performing
   automatic redirections or access authentication, and hence this is not part of the
   robot profile.
   
 */
extern void HTProfile_newRobot (const char * AppName, const char * AppVersion);
/*

   As for the client interfacem we also have a blocking (preemptive) version of the same
   interface. The difference is that this version uses traditional blocking sockets and
   hence only one reques can be performed at the same time.
   
 */
extern void HTProfile_newPreemptiveRobot (const char * AppName,
                                          const char * AppVersion);
/*

PROXY SERVER PROFILE

   MORE
   
SERVER APPLICATION PROFILE

   MORE
   
DELETE A PROFILE

   This is a generic profile cleanup that should be used on all the profiles above. This
   will clean up the memory allocated by the profile and by the Library core itself. After
   calling this you can not call any Library function again. This call also superseeds the
   termination function for teh Library core, HTLibTerminate()so that you don't have to
   call that after calling this function.
   
 */
extern void HTProfile_delete (void);
/*

 */
#endif
/*

   
   ___________________________________
   
                           @(#) $Id: HTProfil.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
