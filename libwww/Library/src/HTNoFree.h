/*

					W3C Sample Code Library libwww No Free Stream




!No Free Stream!

*/

/*
**	(c) COPYRIGHT MIT 1995.
**	Please first read the full copyright statement in the file COPYRIGH.
*/

/*

This stream is a throughline for all methods except FREE and
ABORT. This means that it can be use to put ahead of streams that you
don't want to be freed or aborted until you are redy to do it
yourself.

This module is implemented by HTNoFree.c, and
it is a part of the  W3C Sample
Code Library.

*/

#ifndef _HTNOFREE_H
#define _HTNOFREE_H

#include "HTStream.h"

extern HTStream * HTNoFreeStream_new (HTStream * target);

extern int HTNoFreeStream_delete (HTStream * me);

#endif /* HTNOFREE_H */

/*



@(#) $Id: HTNoFree.html,v 1.1.1.1 2005/07/06 09:34:02 gully Exp $


*/
