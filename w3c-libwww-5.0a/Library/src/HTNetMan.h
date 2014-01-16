/*                                        W3C Reference Library libwww Private Net Definition
                                  PRIVATE NET DEFINITION
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the private definition of the Net Class. Please look in the public Net Class
   for more documentation
   
   This module is implemented by HTNet.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTNETMAN_H
#define HTNETMAN_H
#include "HTNet.h"
#include "HTDNS.h"
#include "HTEvent.h"
#include "HTProt.h"
/*

   The HTNetobject is the core of the request queue management. This object contains
   information about the socket descriptor, the input read buffer etc. required to
   identify and service a request.
   
 */
typedef enum _TCPState {
    TCP_ERROR           = -2,
    TCP_CONNECTED       = -1,
    TCP_BEGIN           = 0,
    TCP_CHANNEL,
    TCP_DNS,
    TCP_NEED_SOCKET,
    TCP_NEED_BIND,
    TCP_NEED_LISTEN,
    TCP_NEED_CONNECT
} TCPState;

struct _HTNet {
    int                 hash;                                  /* Hash value */

    SOCKET              sockfd;                         /* Socket descripter */
    FILE *              fp;                      /* If we can't use a socket */

    HTPriority          priority;        /* Priority of this request (event) */
    BOOL                preemptive;  /* Eff result from Request and Protocol */

    /* Link to other objects */
    HTRequest *         request;                   /* Link to request object */
    HTProtocol *        protocol;                /* Protocol to this request */
    HTTransport *       transport;             /* Transport for this request */
    HTChannel *         channel;                 /* Channel for this request */
    HTHost *            host;          /* What we know about the remote host */
    HTdns *             dns;                           /* Link to DNS object */

    /* For speed */
    HTEventCallback *   cbf;                       /* Protocol state machine */
    HTInputStream *     input;

    /* For progress notifications */
    long                bytes_read;               /* Bytes read from network */
    long                bytes_written;           /* Bytes written to network */

    /* Connection dependent stuff */
    TCPState            tcpstate;                     /* State in connection */
    SockA               sock_addr;           /* SockA is defined in sysdep.h */
    int                 retry;               /* Counting attempts to connect */
    int                 home;                    /* Current home if multiple */
    time_t              connecttime;             /* Used on multihomed hosts */

    /* User specific stuff */
    void *              context;                /* Protocol Specific context */
};

#define HTNet_bytesRead(me)             ((me) ? (me)->bytes_read : -1)
#define HTNet_bytesWritten(me)          ((me) ? (me)->bytes_written : -1)

#define HTNet_setBytesRead(me,l)        ((me) ? (me->bytes_read=(l)) : -1)
#define HTNet_setBytesWritten(me,l)     ((me) ? (me->bytes_written=(l)) :-1)
/*

 */
#endif /* HTNETMAN_H */
/*

   
   ___________________________________
   
                          @(#) $Id: HTNetMan.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
