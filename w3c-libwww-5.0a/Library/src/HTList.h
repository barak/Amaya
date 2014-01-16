/*                                                    W3C Reference Library libwww List Class
                                      THE LIST CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   The list class defines a generic container for storing collections of things in order.
   In principle it could be implemented in many ways, but in practice knowing that it is a
   linked list is important for speed.
   
   This module is implemented by HTList.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTLIST_H
#define HTLIST_H

#include "HTArray.h"

typedef struct _HTList HTList;

struct _HTList {
  void * object;
  HTList * next;
};
/*

CREATION AND DELETION METHODS

   These two functions create and deletes a list
   
 */
extern HTList * HTList_new      (void);
extern BOOL     HTList_delete   (HTList *me);
/*

ADD AN ELEMENT TO LIST

   A new list element is added to the beginning of the list so that it is first element
   just after the head element.
   
 */
extern BOOL HTList_addObject (HTList *me, void *newObject);
/*

   You can also append an element to the end of the list (the end is the first entered
   object) by using the following function:
   
 */
extern BOOL HTList_appendObject (HTList * me, void * newObject);
/*

REMOVE LIST ELEMENTS

   You can delete elements in a list using the following methods. The first method only
   removes the first entry that it finds matching the oldObjectwhereas the second method
   removes all occurances of oldObject.
   
 */
extern BOOL     HTList_removeObject             (HTList * me, void * oldObject);
extern BOOL     HTList_removeObjectAll          (HTList * me, void * oldObject);

extern void *   HTList_removeLastObject         (HTList * me);
extern void *   HTList_removeFirstObject        (HTList * me);
/*

SIZE OF A LIST

   Two small function to ask for the size
   
 */
#define         HTList_isEmpty(me)              (me ? me->next == NULL : YES)
extern int      HTList_count                    (HTList *me);
/*

REFERENCE LIST ELEMENTS BY INDEX

   In some situations is is required to use an index in order to refer to a list element.
   This is for example the case if an element can be registered multiple times.
   
 */
extern int      HTList_indexOf  (HTList *me, void *object);
extern void *   HTList_objectAt (HTList *me, int position);
/*

FIND LIST ELEMENTS

   This method returns the _last_ element to the list or NULL if list is empty
   
 */
#define         HTList_lastObject(me) \
                ((me) && (me)->next ? (me)->next->object : NULL)
/*

   This method returns the _first_ element to the list or NULL if list is empty
   
 */
extern void * HTList_firstObject  (HTList * me);
/*

TRAVERSE LIST

   Fast macro to traverse the list. Call it first with copy of list header: it returns the
   first object and increments the passed list pointer. Call it with the same variable
   until it returns NULL.
   
 */
#define         HTList_nextObject(me) \
                ((me) && ((me) = (me)->next) ? (me)->object : NULL)
/*

INSERTION SORT A LIST

   This function sorts a list using the insertion sort mechanism. The comparison function
   is passed as a parameter and you can  find the definition of HTComparerin the HTArray
   module. Insertion sort is good method whenever a list is nearly in the correct order
   and few items are many positions away from their sorted location. If the list gets very
   long then you may wanna use a quicksort instead.
   
 */
extern BOOL HTList_insertionSort(HTList * list, HTComparer * comp);
/*

FREE LIST

 */
#define HTList_free(x)  HT_FREE(x)

#endif /* HTLIST_H */
/*

   
   ___________________________________
   
                            @(#) $Id: HTList.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
