/*                                        W3C Reference Library libwww Default Initialization
                              DEFAULT INITIALIZATION METHODS
                                             
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
   of Web application. The Library comes with a large set of default functions, for
   example for accessing HTTP and FTP servers, parsing RFC 822 headers etc. This module
   helps the application programmer setting up all this functionality, but it is important
   to note that none of it is _required_ in order to use the Library.
   
   This module is implemented by HTInit.c, and it is a part of the W3C Reference Library.
   You can also have a look at the other Initialization modules.
   
 */
#ifndef HTINIT_H
#define HTINIT_H
#include "WWWLib.h"
#include "WWWApp.h"
/*

DEFAULT TRANSPORT PROTOCOL MODULES

   Register the default set of transport protocols.
   
 */
#include "WWWTrans.h"

extern void HTTransportInit (void);
/*

DEFAULT PROTOCOL MODULES

   Set up default bindings between access schemes and the set of protocol modules in the
   Library. The preemptive version registers all protocol modules to use blocking sockets.
   
 */
#include "WWWHTTP.h"
#include "WWWFile.h"
#include "WWWFTP.h"
#include "WWWGophe.h"
#include "WWWTelnt.h"
#include "WWWNews.h"

#ifdef HT_DIRECT_WAIS
#include "WWWWAIS.h"
#endif

#define HTAccessInit    HTProtocolInit

extern void HTProtocolInit (void);

extern void HTProtocolPreemptiveInit (void);
/*

DEFAULT MIME PARSERS

   The core doesn't have any built in MIME parsers, but many of the protocols need them.
   For instance, many elements of the library rely on the Content-Lengthbeing correctly
   set. HTMIMEInit()provides the minimal functionality needed for library reliabilty.
   
 */
#include "WWWMIME.h"
#include "WWWApp.h"

extern void HTMIMEInit (void);
/*

DEFAULT EVENT MANAGER

   libwww core does not have any default event loop - it has to be added by the
   application. However, it does come with an example implementation thta may be used.
   This implementation is based on a selectsystem call using non-blocking and interleaved
   sockets.
   
 */
#include "WWWApp.h"
/*

DEFAULT MEDIA TYPE CONVERSIONS

   The Convertersare used to convert a media type to another media type, or to present it
   on screen. This is a part of the stream stack algorithm. The Presenters are also used
   in the stream stack, but are initialized separately.
   
 */
#include "WWWMIME.h"
#include "WWWHTML.h"
#include "WWWStream.h"
#include "WWWDir.h"
#include "WWWCache.h"

extern void HTConverterInit     (HTList * conversions);
/*

  Presenters
  
   The Presentersare used to present a media type to the use by calling an external
   program, for example a post script viewer. This is a part of the stream stack
   algorithm. The _Converters_ are also used in the stream stack, but are initialized
   separately. The _Presenters_ use the same include files as the _Converters_.
   
 */
extern void HTPresenterInit     (HTList * conversions);
/*

  Converters and Presenters
  
   This function is only defined in order to preserve backward compatibility.
   
 */
extern void HTFormatInit        (HTList * conversions);
/*

DEFAULT CONTENT AND TRANSFER ENCODINGS

   Content encoders and decoders can handle encodings like chunkedetc.
   
 */
#include "WWWHTTP.h"

extern void HTEncoderInit       (HTList * encodings);
/*

DEFAULT BEFORE AND AFTER FILTERS

   This module provides a set of default _BEFORE_ and _AFTER_ filters that can be
   registered by the Net manager to be called before and after a request. All filters can
   be registered either to be called _globally_ (all requests) or _locally_ (pr request
   basis). _Not_ done automaticly - may be done by application!
   
  BEFORE Filters
  
   The _BEFORE_ filters handle _proxies_, _caches_, _rule files_ etc. The filters are
   called in the order by which the are registered
   
 */
#include "WWWApp.h"

extern void HTBeforeInit (void);
/*

  AFTER Filters
  
   The _AFTER_ filters handle error messages, logging, redirection, authentication etc.
   The filters are called in the order by which the are registered
   
 */
extern void HTAfterInit (void);
/*

  BEFORE and AFTER Filters
  
   This is just a short cut for registrating both _BEFORE_ and _AFTER_ at once
   
 */
extern void HTNetInit (void);
/*

DEFAULT ACCESS AUTHENTICATION MODULES

   The Access Manager which is implemented as a _BEFORE_ and an _AFTER_ filter
   (automatically registered in HTNetInit()) does not by default know of any access
   authentication schemes. As everything else, this must be registered! This function does
   the job and should be all you need.
   
 */
extern void HTAAInit (void);
/*

DEFAULT MESSAGE AND DIALOG FUNCTIONS

   We register a set of alert messages Not done automaticly - may be done by application!
   
 */
#include "WWWApp.h"

extern void HTAlertInit (void);
/*

DEFAULT ICONS FOR DIRECTORY LISTINGS

   The WWWDir interface contains support for including references (URLs and ALTtext tags)
   to icons in directory listings. The icons are selected as a function of the media type
   and the content encoding of the file in question. That is - you can set up icons for
   compressed files, postscript files etc. There is also a small set of specific icons
   representing directories etc.
   
 */
#include "WWWFile.h"

extern void HTIconInit (const char * url_prefix);
/*

 */
#endif
/*

   
   ___________________________________
   
                            @(#) $Id: HTInit.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
