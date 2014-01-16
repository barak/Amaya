/*                                W3C Reference Library libwww HTML TO LATEX CONVERTER STREAM
                                     LATEX GENERATOR
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module converts a structured stream from HTML into LaTeX format. The conversion is
   mostly a 1:1 translation, but as the LaTeX compiler is much more strict than a typical
   HTML converter some typographical constraints are put on the translation. Only text is
   translated for the moment.
   
   This module is implemented by HTTeXGen.c, and it is a part of the W3C Reference
   Library.
   
 */
#ifndef HTTEXGEN_H
#define HTTEXGEN_H
#include "HTStruct.h"
#include "HTFormat.h"
/*

CONVERSION MODULE

   The conversion module is defined as
   
 */
extern HTConverter HTMLToTeX;
/*

 */
#endif
/*

   
   ___________________________________
   
                          @(#) $Id: HTTeXGen.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
