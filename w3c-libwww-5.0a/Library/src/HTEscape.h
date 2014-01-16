/*                                                          W3C Reference Library libwww URIs
                      ESCAPE AND UNESCAPE ILLEGAL CHARACTERS IN URIS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   URLs are written only with the graphic printable characters of the US-ASCII coded
   character set. All other characters must be escaped before they can be used in URLs.
   This module defines the methods required for escaping and unescaping the URLs.
   Internally in the Library, all URLs are escaped so that we never see illegal characters
   in the URL handled by the Library. We only unescape the URLs when we have to, for
   example while taking to the local file system etc.
   
   This module is implemented by HTEscape.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTESCAPE_H
#define HTESCAPE_H

/*

ENCODE UNACCEPTABLE CHARACTERS USING %XY

   This function takes a string containing any sequence of ASCII characters, and returns a
   malloced string containing the same infromation but with all "unacceptable" characters
   represented in the form %xywhere xand yare two hex digits.
   
 */
typedef enum _HTURIEncoding {
    URL_XALPHAS         = 0x1,
    URL_XPALPHAS        = 0x2,
    URL_PATH            = 0x4
} HTURIEncoding;

extern char * HTEscape (const char * str, HTURIEncoding mask);
/*

DECODE %XY ESCAPED CHARACTERS

   This function takes a pointer to a string in which character smay have been encoded in
   %xyform, where xyis the acsii hex code for character 16x+y. The string is converted in
   place, as it will never grow.
   
 */
extern char * HTUnEscape (char * str);
/*

 */
#endif  /* HTESCAPE_H */
/*

   
   ___________________________________
   
                          @(#) $Id: HTEscape.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
