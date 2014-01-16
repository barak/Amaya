/*                                                    W3C Reference Library libwww Atom Class
                                      THE ATOM CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The Atom Class defines strings which are given representative pointer values so that
   they can be stored more efficiently, and comparisons for equality done more
   efficiently. The list of atomsare stored in a has table, so when asking for a new atom
   you might infact get back an existing one.
   
   _Note_: There are a whole bunch of MIME-types defined as atoms, so please use them!
   
   This module is implemented by HTAtom.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTATOM_H
#define HTATOM_H

#include "HTList.h"

typedef struct _HTAtom HTAtom;
struct _HTAtom {
        HTAtom *        next;
        char *          name;
}; /* struct _HTAtom */
/*

  Get an Atom
  
   This function returns a representative value (an atom) such that it will always (within
   one run of the program) return the same value for the same given string. The former is
   case sensitive, the latter is case insensitive.
   
 */
extern HTAtom * HTAtom_for      (const char * string);
extern HTAtom * HTAtom_caseFor  (const char * string);
/*

  Get Content of an Atom
  
 */
#define HTAtom_name(a) ((a) ? (a)->name : NULL)
/*

   This macro returns the string pointed to by the atom.
   
  Search For Atoms
  
   Returns a list of atomswhich matches the template given. It is especially made for
   MIME-types so that for example a template like text<slash><star>returns a list of all
   MIME-types of type text.
   
 */
extern HTList * HTAtom_templateMatches (const char * templ);
/*

  Cleanup Memory
  
   In order to cleanup memory, call this function. This is done automaticly from the
   HTLibTerminate function.
   
 */
extern void HTAtom_deleteAll (void);

#endif
/*

   
   ___________________________________
   
                            @(#) $Id: HTAtom.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
