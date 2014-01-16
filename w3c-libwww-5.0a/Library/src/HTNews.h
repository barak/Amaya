/*                                            W3C Reference Library libwww NNTP State Machine
                                    NNTP STATE MACHINE
                                             
 */
/*
**      (c) COPYRIGHT MIT 1995.
**      Please first read the full copyright statement in the file COPYRIGH.
*/
/*

   This is the News/NNTP client module that handles all communication with
   News/NNTP-servers.
   
   This module is implemented by HTNews.c, and it is a part of the W3C Reference Library.
   
 */
#ifndef HTNEWS_H
#define HTNEWS_H
#include "HTEvent.h"
/*

   We define the max NNTP line as rather long as the result coming from a XOVERcommand
   needs it. If the line is longer then it is chopped, but we will almost have received
   the information we're looking for.
   
 */
#ifndef NEWS_PORT
#define NEWS_PORT               119                            /* See rfc977 */
#endif

#define MAX_NEWS_LINE           4096

extern HTEventCallback HTLoadNews;
/*

  Setting Number of Articles to Show
  
   You can set the number of news articles to be shown at a time. If you set the number to
   none (0) then allarticles are shown at once. This is also the default behavior.
   
 */
extern BOOL HTNews_setMaxArticles (int new_max);
extern int HTNews_maxArticles (void);
/*

 */
#endif /* HTNEWS_H */
/*

   
   ___________________________________
   
                            @(#) $Id: HTNews.h,v 1.1.1.1 1996/10/15 13:08:41 cvs Exp $
                                                                                          
    */
