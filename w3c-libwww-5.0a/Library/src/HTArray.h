/*                                   W3C Reference Library libwww Dynamic Array Pointer Class
                               DYNAMIC ARRAY POINTER CLASS
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This module implements a flexible array of pointers. It is a general utility module. An
   array is a structure which may be extended. These routines create and append data to
   arrays, automatically reallocating them as necessary. It is garanteed that the last
   entry in an array is _NULL_ This module is implemented by HTArray.c, and it is a part
   of the W3C Reference Library.
   
 */
#ifndef HTARRAY_H
#define HTARRAY_H
/*

PRIVATE DATA STRUCTURE

   This structure should not be referenced outside this module. If I find out I'll make it
   private ;-)
   
 */
typedef struct {
    int         size;           /* In numbers of elements       */
    int         growby;         /* Allocation unit in elements  */
    int         allocated;      /* Current size of *data        */
    void **     data;           /* Pointer to malloced area or 0 */
} HTArray;
/*

CREATE A NEW ARRAY

   Create a new array and specify the number of bytes to allocate at a time when the array
   is later extended. Arbitrary but normally a trade-off time vs. memory
   
 */
extern HTArray * HTArray_new (int grow);
/*

DELETE AN ARRAY

   Delete an array created by HTArray_new
   
 */
extern BOOL HTArray_delete (HTArray * array);
/*

CLEAR AN ARRAY

   Clears an array but keeps it around
   
 */
extern BOOL HTArray_clear (HTArray * array);
/*

APPEND AN ELEMENT TO THE ARRAY

   Add the element to the array.
   
 */
extern BOOL HTArray_addObject (HTArray * array, void * object);
/*

TRAVERSE AN ARRAY

   Fast macros to traverse a macro ending in a NULL element.
   
 */
#define HTArray_firstObject(me, data) \
        ((me) && ((data)=(me)->data) ? *(data)++ : NULL)
#define HTArray_nextObject(me, data) \
        ((me) && (data) ? *(data)++ : NULL)
/*

SORT AN ARRAY

   An array can be sorted in any way you like, for example with qsort(). This module
   provides an easy interface to the qsort() function using where you can define you own
   comparison routine as a function of the type:
   
 */
typedef int HTComparer (const void * a, const void * b);
/*

   The sort function returns YES if sorting OK, else NO.
   
 */
extern BOOL HTArray_sort (HTArray * array, HTComparer * comp);
/*

RETURNS DATA VECTOR

   Returns a pointer to the actual data
   
 */
#define HTArray_data(me)        ((me) ? (me)->data : NULL)
/*

RETURN CURRENT SIZE

   Returns the current size of the chunk
   
 */
#define HTArray_size(me)        ((me) ? (me)->size : -1)
/*

 */
#endif
/*

   
   ___________________________________
   
                            @(#) $Id: HTArray.h,v 1.1.1.1 1996/10/15 13:08:40 cvs Exp $
                                                                                          
    */
