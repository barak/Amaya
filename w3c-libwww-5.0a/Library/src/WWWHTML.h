/*                                                   W3C Reference Library libwww HTML PARSER
                         DECLARATION OF W3C REFERENCE HTML MODULE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the include file for the basic HTML module that can be used together with the
   core of the W3C Reference Library. It contains all HTML specific modules which are
   required to compile and build the HTML DLL. Please note that as the HText is _not_
   included in this interface. The reason is that the HText interface only is declared by
   the Library but must be defined by the application. Therefore it can not be part of a
   DLL but must be included directly in the application.
   
 */
#ifndef WWWHTML_H
#define WWWHTML_H
/*

 */
#ifdef __cplusplus
extern "C" {
#endif
/*

SYSTEM DEPENDENCIES

   The sysdep.h file includes system-specific include files and flags for I/O to network
   and disk. The only reason for this file is that the Internet world is more complicated
   than Posix and ANSI.
   
 */
#include "sysdep.h"
/*

LIBRARY INCLUDES

 */
#include "HTMLPDTD.h"
#include "SGML.h"
#include "HTMLGen.h"
/*

   End of HTML module
   
 */
#ifdef __cplusplus
} /* end extern C definitions */
#endif

#endif
/*

   
   ___________________________________
   
                            @(#) $Id: WWWHTML.h,v 1.2 1998/03/05 14:37:27 cvs Exp $
                                                                                          
    */
