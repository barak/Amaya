/*                                          W3C Reference Library libwww Identity Socket Read
                               IDENTITY SOCKET READ METHOD
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This function is an "_identity_" application protocol in that it reads data from the
   transport and passes it down stream without doing anything with it. It simply reads
   data and is a wrapper around a registered transport mechanism for reading from a
   socket. It provides a callback function for the event loop so that a socket can be
   loaded using non-blocking I/O. The function requires an _open_ socket. It will
   typically be used in server applications or in a client application that can read
   directly from stdin.
   
   This module is implemented by HTSocket.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTSOCKET_H
#define HTSOCKET_H

#include "HTEvent.h"

extern HTEventCallback HTLoadSocket;
/*

 */

/*

 */
#endif
/*

   
   ___________________________________
   
                          @(#) $Id: HTSocket.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
