/*                                          W3C Reference Library ANSI Read and Write Streams
                               ANSI READ AND WRITE STREAMS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The ANSI Reader Stream and the ANSI Writer Stream are output streams which knows how to
   read and write to an ANSI C type FILE descriptor. Both streams are part of the
   Transport interface and may be registered as part of a Transport Object. In the default
   initialization interface, you can find the HTTransportInit()function which sets up the
   streams for handling local file access on some platforms.
   
   This module is implemented by HTANSI.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTANSI_H
#define HTANSI_H

#include "HTIOStream.h"
/*

INPUT BUFFERING

   In order to optimize reading a channel, we bind a buffer to each channel object. The
   size of this buffer is a compromise between speed and memory.
   
 */
#define FILE_BUFFER_SIZE        8192
/*

READ STREAM

 */
extern HTInput_new HTANSIReader_new;
/*

WRITE STREAM

 */
extern HTOutput_new HTANSIWriter_new;
/*

 */
#endif
/*

   End of declaration module */
