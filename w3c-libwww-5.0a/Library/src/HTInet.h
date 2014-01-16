/*                                 W3C Reference Library libwww Generic Network Communication
                              GENERIC NETWORK COMMUNICATION
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module has the common code for handling typical Internet functions like getting
   the name of the local host, getting the domain name and email address of user, parsing
   error codes returned in errnoor equivalent etc.
   
   This module is implemented by HTInet.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTINET_H
#define HTINET_H
#include "HTReq.h"
#include "HTNet.h"
/*

SYSTEM DESCRIPTION OF ERROR MESSAGE

   Return error message corresponding to errno number given. We need to pass the error
   number as a parameter as we on some platforms get different codes from sockets and
   local file access.
   
 */
extern const char * HTErrnoString       (int errnum);
extern int HTInetStatus                 (int errnum, char * where);
/*

PARSE A CARDINAL VALUE

   Converts a string to a cardinal value. On entry: *pp points to first character to be
   interpreted, terminated by non 0..9 character. *pstatus points to status already valid,
   maxvalue gives the largest allowable value. On exit: *pp points to first unread
   character, *pstatus points to status updated iff bad
   
 */
extern unsigned int HTCardinal (int *           pstatus,
                                char **         pp,
                                unsigned int    max_value);
/*

PRODUCE A STRING FOR AN INTERNET ADDRESS

   This function is equivalent to the BSD system call _inet_ntoa_ in that it converts a
   numeric 32-bit IP-address to a dotted-notation decimal string. The pointer returned
   points to static memory which must be copied if it is to be kept.
   
 */
extern const char * HTInetString (struct sockaddr_in * sin);
/*

PARSE A NETWORK NODE ADDRESS AND PORT

   It is assumed that any portnumber and numeric host address is given in decimal
   notation. Separation character is '.' Any port number given in host name overrides all
   other values. 'host' might be modified.
   
 */
extern int HTParseInet (HTNet * net, char * host);
/*

TIMEZONE OFFSET

   Calculates the offset from GMT in _seconds_.
   
 */
extern time_t HTGetTimeZoneOffset (void);
/*

FQDN OF THIS HOST

   This function returns a the name of this host or NULL if not available. The name is
   stored in a static variable.
   
 */
extern char * HTGetHostName (void);
/*

USER EMAIL ADDRESS

   This functions returns a char pointer to a static location containing the mail address
   of the current user. The static location is different from the one of the current host
   name so different values can be assigned. The default value is <USER>@hostnamewhere
   hostname is as returned by _HTGetHostName()_.
   
 */
#ifndef HT_DEFAULT_LOGIN
#define HT_DEFAULT_LOGIN        "libwww"
#endif

extern char * HTGetMailAddress (void);
/*

NEWS SERVER

   The default news host is "news" but you can get ans set the value here.
   
 */
extern char * HTGetNewsServer (void);
/*

GET A TEMPORARY FILE NAME

   Finds a temporary name in in the directory given. If the directory is NULLdo not
   prepend anything. If success, the result must be freed by caller, else we return NULL
   
 */
extern char * HTGetTmpFileName (const char * dir);
/*

SIGNAL HANDLING

   This is only necessary to compile on a few platforms and only if the application does
   not have its own signal handling. It is required on Solaris 2.3 (and other SVR4
   platforms?) due to a bug in the TCP kernel. When a connect()is tried to a illegal port,
   solaris gives a SIGPIPE signal instead of returning Connection refused.
   
 */
#ifdef WWWLIB_SIG
extern void HTSetSignal (void);
#endif

/*

  GET TIME OF DAY IN MILLI SECONDS

   Return the time of day in milli seconds.

 */
typedef unsigned long ms_t;
extern ms_t HTGetTimeInMillis (void);


#endif   /* HTINET_H */
/*

   
   ___________________________________
   
                             @(#) $Id: HTInet.h,v 1.2 1998/03/11 17:45:38 cvs Exp $
                                                                                          
    */
