/*                                             W3C Reference Library libwww Local File Access
                      DECLARATION OF W3C REFERENCE LOCAL FILE ACCESS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the module for accessing local files and directories. The module contans
   
 */
#ifndef WWWFILE_H
#define WWWFILE_H
/*

 */
#ifdef __cplusplus
extern "C" {
#endif
/*

  System dependencies
  
   The sysdep.h file includes system-specific include files and flags for I/O to network
   and disk. The only reason for this file is that the Internet world is more complicated
   than Posix and ANSI.
   
 */
#include "sysdep.h"
/*

  Access the Local File System
  
   The WWWFile interface provides a platform independent access scheme for local files.
   The local file access works exactly like any other access scheme, for example HTTP, in
   that the "file protocol" is independent of the underlying transport. This can be used
   to for example slide in a CVS transport layser underneath the file module without
   making any modifications to the file module itself. You can read more about the
   transport managament in the Transport Interface.
   
 */
#include "HTFile.h"
/*

  Content Negotiation
  
   When accessing the lccal file system, you can enable _content negotiation_ as described
   in the HTTP specification.  The content negotiation algorithm is based on file suffixes
   as defined by the Bind manager. When looking for a file you do _not_ have to specify a
   suffix. Instead this module looks for all alternatives with the same main name. For
   example, looking for the file _Overview_ can result in any of the files (or
   directories) _Overview.txt_, _Overview.html_, _Overview.ps_ etc. The selection
   algorithm is based on the values of the preferences for language, media type, encoding,
   etc. - exactly like a server would do with the acceptheaders.
   
 */
#include "HTMulti.h"
/*

   End of FILE module
   
 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                            @(#) $Id: WWWFile.h,v 1.1.1.1 1996/10/15 13:08:38 cvs Exp $
                                                                                          
    */
