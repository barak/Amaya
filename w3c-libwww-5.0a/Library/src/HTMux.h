/*                                                  W3C Reference Library libwww Multiplexing
                           CHANNELS, SESSIONS, AND MULTIPLEXING
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module defines the read and write functions to and from the network. As we are
   having reentrant function and a smarter network I/O this will get very small :-)
   
   This module is implemented by HTMux.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTMUX_H
#define HTMUX_H

#include "sysdep.h"
#include "HTReq.h"
#include "HTStream.h"
/*

THE W3MUX OBJECT

 */
typedef struct _HTW3mux HTW3mux;
/*

MULTIPLEXING AND DEMULTIPLEXING STREAMS

   The multiplexing protocol works just like another stream. We have a read loop and a
   output stream:
   
CREATE A NEW SESSION

   Create a new session and register it with a w3mux object. The output stream is where to
   output data returning from the session and the return stream is where to input data to
   the stream. If the output stream is NULL then we use a blackhole instead
   
 */
extern HTStream * HTSession_new (HTW3mux * w3mux, HTStream * output);
/*

CREATE A W3MUX OBJECT

   Create a new W3mux protocol object. Returns new W3Mux object or NULL on error
   
 */
extern HTW3mux * HTW3mux_new (HTStream * mux, BOOL active);
/*

  Does a w3mux object contain any more sessions?
  
 */
extern BOOL HTW3mux_isEmpty (HTW3mux * w3mux);
/*

  Delete a w3mux object
  
   Delete a W3mux protocol object. If there are any remaining sessions then cancel them by
   turning the output into a error stream. When no more sessions are referencing this
   object we can delete it for good. Until that point we turn this object into a zombie.
   
 */
extern BOOL HTW3mux_delete (HTW3mux * w3mux);
/*

  Shutdown a w3mux object
  
   Shutdown a w3mux object in one or both directions. This is equivalent to a socket
   shutdown() system call. That is, we have the following options:
   
  0                      Read half
                         
  1                      Write half
                         
  2                      Both read and write halves
                         
 */
extern BOOL HTW3mux_shutdown (HTW3mux * w3mux, int how);
/*

 */
#endif
/*

   
   ___________________________________
   
                              @(#) $Id: HTMux.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
