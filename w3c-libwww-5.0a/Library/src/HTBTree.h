/*                                          W3C Reference Library libwww Balanced Binary Tree
                                   BALANCED BINARY TREE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   Tree creation, traversal and freeing. User-supplied comparison routine.
   
   This module is implemented by HTBTree.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTBTTEE_H
#define HTBTREE_H

#include "HTArray.h"
/*

 */
typedef struct _HTBTree HTBTree;

typedef struct _HTBTree_element HTBTElement;
/*

CREATE A BINARY TREE

   This function creates a new binary tree and uses the comparison function when building
   the tree.
   
 */
extern HTBTree * HTBTree_new (HTComparer * comp);
/*

FREE STORAGE OF THE TREE BUT NOT OF THE OBJECTS

 */
extern void HTBTree_free (HTBTree * tree);
/*

FREE STORAGE OF THE TREE AND OF THE OBJECTS

 */
extern void HTBTreeAndObject_free (HTBTree * tree);
/*

ADD AN OBJECT TO A BINARY TREE

 */
extern void HTBTree_add (HTBTree* tree, void * object);
/*

RETURN AN OBJECT

 */
extern void * HTBTree_object (HTBTElement * element);
/*

FIND NEXT ELEMENT IN DEPTH-FIRST ORDER

  On entry,
  
   If elementis NULL then start with leftmost element. if not NULL then give next object
   to the right. The function returns a pointer to element or NULL if none left.
   
 */
extern HTBTElement * HTBTree_next (HTBTree * tree, HTBTElement * element);
/*

 */
#endif
/*

   
   ___________________________________
   
                           @(#) $Id: HTBTree.h,v 1.1.1.1 1996/10/15 13:08:39 cvs Exp $
                                                                                          
    */
