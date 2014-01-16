/*                                         W3C Reference Library libwww Socket Open and Close
                                  SOCKET OPEN AND CLOSE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The Socket Open and Close methods knows how to establish a BSD socket TCP connection
   and is part of the Transport interface.
   
   This module is implemented by HTTCP.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTTCP_H
#define HTTCP_H
#include "HTReq.h"
#include "HTNet.h"
/*

ACTIVE CONNECTION ESTABLISHMENT

   This makes an active connectto the specified host. An HTNet Object is parsed in order
   to handle errors and other stuff. The default port might be overwritten by any port
   indication in the URL specified as <host>:<port>If it is a _multihomed host _(a host
   having multiple IP-addresses with the same host name)  then HTDoConnect()measures the
   time it takes to connect and updates the calculated weights in the DNS object.
   
 */
extern int HTDoConnect (HTNet * net, char * url, u_short default_port);
/*

PASSIVE CONNECTION ESTABLISHMENT

   This function makes an accepton a port. The net must contain a valid socket to accept
   on. If accept is OK then we _duplicate_ the net object and assign the accepted socket
   to the newly created net object. The original Net object will keep accepting
   connections on the original socket, for example port 80 in the case of HTTP. The newly
   created Net object will be freed when the protocol module has finished. If the
   _accepted_ net object pointer points to the net object itself, that is - the same
   object all along - then we reuse the same Net obejct; closes the original socket and
   replaces it wik the accepted one. This is a quick way of accepting a single connection.
   
 */
extern int HTDoAccept (HTNet * net, HTNet ** accepted);
/*

LISTEN ON A SOCKET

   Listens on the specified port. Passing port 0means that we don't care and a temporary
   one will be assigned. If master==INVSOC then we listen on all local interfaces (using a
   wildcard). If INVSOCis _not_ NULLthen use this as the local interface. backlogis the
   number of connections that can be queued on the socket - you can use HT_BACKLOGfor a
   platform dependent value (typically 5 on BSD and 32 on SVR4). Returns HT_ERRORor HT_OK.
   
 */
extern int HTDoListen (HTNet * net, u_short port, SOCKET master, int backlog);
/*

CLOSING A SOCKET

   Closes a socket
   
 */
extern int HTDoClose (HTNet * net);
/*

 */
#endif   /* HTTCP_H */
/*

   
   ___________________________________
   
                             @(#) $Id: HTTCP.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
