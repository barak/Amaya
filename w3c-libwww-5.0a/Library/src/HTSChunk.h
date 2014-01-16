/*                                     W3C Reference Library libwww Stream to Chunk Converter
                                STREAM TO CHUNK CONVERTER
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This stream converts a Stream obejct into a Chunk object. Chunks are dynamic streams so
   this is in other words a conversion from a stream based model to a dynamic data buffer
   model for handling a downloaded object. It is for the caller of this stream to free the
   chunk.
   
   This module is implemented by HTSChunk.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTSCHUNK_H
#define HTSCHUNK_H

#include "HTChunk.h"
#include "HTStream.h"

extern HTStream * HTStreamToChunk (HTRequest *  request,
                                   HTChunk **   chunk,
                                   int          max_size);
/*

   End of definition module
   
 */
#endif /* HTSCHUNK_H */
/*

   
   ___________________________________
   
                           @(#) $Id: HTSChunk.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
