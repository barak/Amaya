/*                                             W3C Reference Library libwww Channel Interface
                                    THE CHANNEL CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   A channel contains information about sockets and their input and output streams. A
   channelrepresents the front end for receiving data towards the underlying transport.
   The definition of a channel describes how we are to read the data coming in on a
   socket, for example. In other words - a channel represents the first part of how to get
   handle incoming data in the Library:
   
      Reading data on a channel
      
      Defining a target for incoming data
      
      Defining a protocol state machine that can handle the data
      
   This module is implemented by HTChannl.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTCHANNL_H
#define HTCHANNL_H

typedef struct _HTChannel HTChannel;

#include "HTTrans.h"
#include "HTReq.h"
#include "HTNet.h"
#include "HTHost.h"
#include "HTIOStream.h"
/*

THE CHANNEL OBJECT

   The channel object contains an input and an output stream for a particular connection.
   
  Creation and Deletion of Channel Objects
  
 */
extern HTChannel * HTChannel_new (HTNet * net, BOOL active);
/*

  Deleting a Channel Object
  
 */
extern BOOL HTChannel_delete (HTChannel * channel, int status);
extern BOOL HTChannel_deleteAll (void);
/*

  Search for a Channel
  
   Look for a channel object if we for some reason should have lost it
   
 */
extern HTChannel * HTChannel_find (SOCKET sockfd);
/*

  Get Transport Descriptor for Channel
  
   A transport descriptor can be either a ANSI C file descriptor or a BSD socket. As it is
   difficult for the channel to know which one is used by a specific transport, we leave
   this to the caller to figure out. This is probably not the best way of doing it.
   
 */
extern SOCKET HTChannel_socket  (HTChannel * channel);
extern FILE * HTChannel_file    (HTChannel * channel);
/*

  The Host Object
  
   The Channel object also keeps a link to the host object so that we have a link to the
   persistent connection repository.
   
 */
extern BOOL HTChannel_setHost (HTChannel * ch, HTHost * host);
extern HTHost * HTChannel_host (HTChannel * ch);
/*

  Semaphores
  
   Adjust the semaphore on a channel. As many Net objectscan point to the same channel we
   need to keep count of them so that we know if we can delete a channel or if it is still
   in use. We do this by having a simple semaphore associated with each channel object
   
 */
extern void HTChannel_upSemaphore   (HTChannel * channel);
extern void HTChannel_downSemaphore (HTChannel * channel);
extern void HTChannel_setSemaphore  (HTChannel * channel, int semaphore);
/*

  Create Input and Output Streams
  
   You create the input stream and bind it to the channel using the following methods.
   Please read the description in the HTIOStream module on the parameters target, param,
   and mode. The input and output stream are instances created by the Transport object.
   The Transport Object defines the creation methods for the inout and output streams and
   the Channel object contains the actualy stream objects.
   
 */
extern BOOL HTChannel_setInput (HTChannel * ch, HTInputStream * input);
extern HTInputStream * HTChannel_input (HTChannel * ch);

extern BOOL HTChannel_setOutput (HTChannel * ch, HTOutputStream * output);
extern HTOutputStream * HTChannel_output (HTChannel * ch);
/*

 */
#endif /* HTCHANNL */
/*

   
   ___________________________________
   
                           @(#) $Id: HTChannl.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
