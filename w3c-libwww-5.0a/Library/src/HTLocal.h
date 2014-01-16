/*                                             W3C Reference Library libwww Local File Access
                                    LOCAL FILE ACCESS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module has the common code for opening and closing local files.
   
   This module is implemented by HTTCP.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTLOCAL_H
#define HTLOCAL_H

#include "HTNet.h"
/*

MODE OF FILE

   A file can be opened in variuos modes dependent on whether it is to be opened for
   reading or writing or both. We here define a set that is largely equivalent to what we
   know from ANSI C file modes and Unix file modes:
   
 */
#ifndef NO_UNIX_IO
typedef int HTLocalMode;

#define HT_FB_RDONLY    O_RDONLY
#define HT_FT_RDONLY    HT_FB_RDONLY

#define HT_FB_WRONLY    O_WRONLY|O_CREAT
#define HT_FT_WRONLY    HT_FB_WRONLY

#define HT_FB_RDWR      O_RDWR
#define HT_FT_RDWR      HT_FB_RDWR

#define HT_FB_APPEND    O_APPEND
#define HT_FT_APPEND    HT_FB_APPEND

#else
typedef const char HTLocalMode[10];

#define HT_FB_RDONLY    "rb"
#define HT_FT_RDONLY    "r"

#define HT_FB_WRONLY    "wb"
#define HT_FT_WRONLY    "w"

#define HT_FB_RDWR      "r+b"
#define HT_FT_RDWR      "r+"

#define HT_FB_APPEND    "ab"
#define HT_FT_APPEND    "a"

#endif
/*

OPEN A LOCAL FILE

   Opens a local file using whatever means are available on the current platform. If we
   have unix file descriptors then use that as we can use select on them. On windows we
   want to use asynchrounous handles - just like we handle the socket interface as well.
   On other platforms, we use ANSI C file descriptors.
   
 */
extern int HTFileOpen (HTNet * net, char * local, HTLocalMode mode);
/*

CLOSE A LOCAL FILE

   Closes a file descriptor whatever means are available on the current platform. If we
   have unix file descriptors then use this otherwise use the ANSI C file descriptors
   
 */
extern int HTFileClose (HTNet * net);
/*

 */
#endif   /* HTLOCAL_H */
/*

   
   ___________________________________
   
                            @(#) $Id: HTLocal.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
