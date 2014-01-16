/*                                          W3C Reference Library libwww WWW String Utilities
                              WWW RELATED STRING MANAGEMENT
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module is like the generic string utility module but it contains more Web related
   string utility functions. Examples are functions that return a _date string_, a
   _Message ID string_ etc.
   
   This module is implemented by HTWWWStr.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTWWWSTR_H
#define HTWWWSTR_H

#include "HTUser.h"
#include "HTAtom.h"
/*

NEXT WORD OR QUOTED STRING

   This function returns a RFC822 word separated by space, comma, or semi-colons.
   pstrpoints to a string containing a word separated by white white space "," ";" or "=".
   The word can optionally be quoted using or "" Comments surrrounded by '(' ')' are
   filtered out. On exit, pstrhas been moved to the first delimiter past the field THE
   STRING HAS BEEN MUTILATED by a 0 terminator. The function returns a pointer to the
   first word or NULL on error
   
 */
extern char * HTNextField (char** pstr);
/*

NEXT NAME-VALUE PAIR

   This is the same as HTNextFieldbut it does not look for '=' as a separator so if there
   is a name-value pair then both parts are returned. Returns a pointer to the first word
   or NULL on error
   
 */
extern char * HTNextPair (char ** pstr);
/*

NEXT S-EXPRESSION

   Find the next s-expression token from a string of characters. We return the nameof this
   expression and the parampoints to the parameters. Note, that the string has been
   mutilated by a 0 terminator!
   
 */
extern char * HTNextSExp (char ** exp, char ** param);
/*

READING CRLF

   The Library provides a default set of read routines that can handle the most common
   situations. However, before we start we make following definition is to make life
   easier when having a state machine looking for a <CRLF>sequence.
   
 */
typedef enum _HTEOLState {
    EOL_ERR = -1,
    EOL_BEGIN = 0,
    EOL_FCR,
    EOL_FLF,
    EOL_DOT,
    EOL_SCR,
    EOL_SLF,
    /* intermediate states */
    EOL_END,
    EOL_FOLD,
    EOL_LINE
} HTEOLState;
/*

RFC1123 DATE/TIME STAMP STRING

   Returns a string containing a date/time stamp string in RFC-1123 format. The string is
   in static memory so be aware!
   
 */
extern const char * HTDateTimeStr (time_t *calendar, BOOL local);
/*

DATE USED FOR DIRECTORY LISTINGS

   Generates a date/time stamp string used in directory listings. There is nothing special
   about this format, it is just to make directory listings look alike.
   
 */
extern BOOL HTDateDirStr (time_t * time, char * str, int len);
/*

PARSE A DATE/TIME STRING

   Converts a variety of different string representations of date time stamps in GMT to a
   local representation of localtime time_t. The local _time zone_ is taken from the user
   profile information or directly from the system if NULLis passed as user profile . If
   the time is relative (for example in the Ageheader) then you can indicate whether it
   should be expanded to local time or not by using the expandargument.
   
 */
extern time_t HTParseTime (const char * str, HTUserProfile * up, BOOL expand);
/*

UNIQUE MESSAGE-ID STRING

   The message ID string can for example be use as a RFC 822 header. The content is based
   on the information taken from the user profile which can be supplied by the
   application.
   
 */
extern const char * HTMessageIdStr (HTUserProfile * up);
/*

MATCHING MIME CONTENT-TYPES

   Matches MIME constructions for _content-types_ and others like them, for example
   "text/html", "text/plain". It can also match wild cards like "text/" and "/. We use
   instead of * in order note to make C like comments :-)
   
 */
extern BOOL HTMIMEMatch (HTAtom * tmplate, HTAtom * actual);
/*

CONVERTS AN INTEGER TO A STRING USING PREFIX

   In computer-world 1K is 1024 bytes and 1M is 1024K -- however, sprintf() still formats
   in base-10. Therefore I output only until 999, and then start using the next unit. This
   doesn't work wrong, it's just a feature. The conversion is done in "str" which must be
   large enough to contain the result.
   
 */
extern void HTNumToStr (unsigned long n, char *str, int len);
/*

CONVERSION BETWEEN URLS AND LOCAL FILE NAMES

   These are two functions that separate the URL naming syntax from platform dependent
   file naming schemes. If you are porting the code to a new platform, you probably have
   to do some translation here.
   
  Convert file URLs into a local representation
  
   The URL has already been translated through the rules in get_physical in HTAccess.c and
   all we need to do now is to map the path to a local representation, for example if must
   translate '/' to the ones that turn the wrong way ;-) Returns local file (that must be
   freed by caller) if OK, else NULL.
   
 */
extern char * HTWWWToLocal (const char * url, const char * base,
                            HTUserProfile * up);
/*

  Convert a local file name into a URL
  
   Generates a WWW URL name from a local file name or NULL if error. Returns URL (that
   must be freed by caller) if OK, else NULL.
   
 */
extern char * HTLocalToWWW (const char * local);
/*

 */
#endif
/*

   
   ___________________________________
   
                          @(#) $Id: HTWWWStr.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
