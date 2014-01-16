/*
 *
 *  (c) COPYRIGHT INRIA, 1996.
 *  Please first read the full copyright statement in file COPYRIGHT.
 *
 */

/*
 * Warning:
 * This module is part of the Thot library, which was originally
 * developed in French. That's why some comments are still in
 * French, but their translation is in progress and the full module
 * will be available in English in the next release.
 * 
 */
 
#define	MAXCBUFSIZ	16384	/* 1024 x 16 */

typedef struct _CBuf *PtrCBuf;
typedef struct _CBuf {
			     int  CBufIndx;
			     char CBufData[MAXCBUFSIZ];
			   } CBuf ;

