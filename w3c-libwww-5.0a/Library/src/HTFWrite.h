/*                                           W3C Reference Library libwww ANSI C File Streams
                                   ANSI C FILE STREAMS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module contains a set of basic file writer streams that are used to dump data
   objects to disk at various places within the Library core. Most notably, we use these
   streams in the Format Manager in order to handle external presenters, for example post
   script viewers etc. These streams can of course also be used in other contexts by the
   application.
   
      An ANSI C File Writer Stream
      
      Various Converters using the File Writer Stream
      
   This module is implemented by HTFWrite.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTFWRITE_H
#define HTFWRITE_H

#include "HTStream.h"
#include "HTFormat.h"
/*

ANSI C FILE WRITER STREAM

   This function puts up a new stream given an _open_ file descripter. If the file is
   _not_ to be closed afterwards, then set leave_open=NO.
   
 */
extern HTStream * HTFWriter_new (HTRequest * request,
                                 FILE * fp,
                                 BOOL leave_open);
/*

VARIOUS CONVERTERS USING THE FILE WRITER STREAM

   This is a set of functions that can be registered as converters. They all use the basic
   ANSI C file writer stream for writing out to the local file system.
   
 */
extern HTConverter HTSaveAndExecute, HTSaveLocally, HTSaveAndCallback;
/*

  HTSaveLocally          Saves a file to local disk. This can for example be used to dump
                         date objects of unknown media types to local disk. The stream
                         prompts for a file name for the temporary file.
                         
  HTSaveAndExecute       Creates temporary file, writes to it and then executes system
                         command (maybe an external viewer) when EOFhas been reached. The
                         stream finds a suitable name of the temporary file which
                         preserves the suffix. This way, the system command can find out
                         the file type from the name of the temporary file name.
                         
  HTSaveAndCallback      This stream works exactly like the HTSaveAndExecutestream but in
                         addition when EOFhas been reached, it checks whether a callback
                         function has been associated with the request object in which
                         case, this callback is being called. This can be use by the
                         application to do some processing afterthe system command has
                         terminated. The callback function is called with the file name of
                         the temporary file as parameter.
                         
 */
#endif
/*

   
   ___________________________________
   
                          @(#) $Id: HTFWrite.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
