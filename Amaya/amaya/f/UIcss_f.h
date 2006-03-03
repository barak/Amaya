/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern ThotBool LoadRemoteStyleSheet ( char *url,
                                       Document doc,
                                       Element el,
                                       char *urlRef,
                                       char *completeURL,
                                       char *localfile );
extern void InitUserStyleSheet ( char *url );
extern void LoadUserStyleSheet ( Document doc );
extern void EmbedStyleSheets ( Document docsrc,
                               Document docdest );
extern void AddStyle ( char *url,
                       Document doc,
                       Element link,
                       CSSCategory category );
extern void UpdateStyleSheet ( char *url,
                               char *tempdoc );
extern char *CssToPrint ( Document doc,
                          char *printdir );
extern void ShowAppliedStyle ( Document doc,
                               View view );
extern void SynchronizeAppliedStyle ( NotifyElement *event );
extern void InitCSS ( void );
extern void LinkCSS ( Document doc,
                      View view );
extern void OpenCSS ( Document doc,
                      View view );
extern void DisableCSS ( Document doc,
                         View view );
extern void EnableCSS ( Document doc,
                        View view );
extern void RemoveCSS ( Document doc,
                        View view );
extern void SetCSSStyle ( Document doc,
                          View view );

#else /* __STDC__ */

extern ThotBool LoadRemoteStyleSheet ( char *url,
                                         Document doc,
                                         Element el,
                                         char *urlRef,
                                         char *completeURL,
                                         char *localfile );
extern void InitUserStyleSheet ( char *url );
extern void LoadUserStyleSheet ( Document doc );
extern void EmbedStyleSheets ( Document docsrc,
                                 Document docdest );
extern void AddStyle ( char *url,
                         Document doc,
                         Element link,
                         CSSCategory category );
extern void UpdateStyleSheet ( char *url,
                                 char *tempdoc );
extern char *CssToPrint ( Document doc,
                            char *printdir );
extern void ShowAppliedStyle ( Document doc,
                                 View view );
extern void SynchronizeAppliedStyle ( NotifyElement *event );
extern void InitCSS ( void );
extern void LinkCSS ( Document doc,
                        View view );
extern void OpenCSS ( Document doc,
                        View view );
extern void DisableCSS ( Document doc,
                           View view );
extern void EnableCSS ( Document doc,
                          View view );
extern void RemoveCSS ( Document doc,
                          View view );
extern void SetCSSStyle ( Document doc,
                            View view );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */