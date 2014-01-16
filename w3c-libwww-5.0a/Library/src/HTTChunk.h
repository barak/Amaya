/*                        W3C Reference Library libwww Chunked Transfer Encoding and Decoding
                          CHUNKED TRANSFER ENCODING AND DECODING
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   Chunked transfer encoding and decoding is new in HTTP/1.1. It allows applications to
   use persistent connections while not knowing the content length a priori to the
   response header is generated.
   
   Both the encoder and the decoder are of type HTCoder which is defined in the Stream
   Pipe Builder. This means that bot the encoder and the decoder are registered
   dynamically and called by the Stream Pipe Builder if required.
   
   _Note_: These streams are _not_ set up by default. They must be registered by the
   application. You can use the default initialization function HTEncoderInit()function in
   the initialization interface.
   
   This module is implemented by HTTChunk.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTTCHUNK_H
#define HTTCHUNK_H

#include "HTFormat.h"
/*

 */
extern HTCoder HTChunkedDecoder, HTChunkedEncoder;
/*

 */
#endif /* HTTCHUNK_H */
/*

   
   ___________________________________
   
                           @(#) $Id: HTTChunk.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
