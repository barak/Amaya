/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern Element GetElemWithAttr ( Document doc,
                                 AttributeType attrType,
                                 char *nameVal,
                                 Attribute ignoreAtt,
                                 Element ignoreEl );
extern Element SearchNAMEattribute ( Document doc,
                                     char *nameVal,
                                     Attribute ignoreAtt,
                                     Element ignoreEl );
extern void CheckUniqueName ( Element el,
                              Document doc,
                              Attribute attr,
                              AttributeType attrType );
extern void FollowTheLink_callback ( int targetDocument,
                                     int status,
                                     char *urlName,
                                     char *outputfile,
                                     AHTHeaders *http_headers,
                                     void *context );
extern ThotBool IsCSSLink ( Element el,
                            Document doc );
extern void CheckRefresh ( Document doc );
extern void DoAction ( Document doc,
                       View view );
extern ThotBool AcceptTab ( NotifyOnTarget *event );
extern void NextLinkOrFormElement ( Document doc,
                                    View view );
extern void PreviousLinkOrFormElement ( Document doc,
                                        View view );
extern void AccessKeyHandler ( Document doc,
                               void *param );
extern ThotBool IgnoreEvent ( NotifyElement *event );
extern ThotBool DoubleClick ( NotifyElement *event );
extern ThotBool SimpleClick ( NotifyElement *event );
extern ThotBool SimpleLClick ( NotifyElement *event );
extern ThotBool SimpleRClick ( NotifyElement *event );
extern ThotBool AnnotSimpleClick ( NotifyElement *event );
extern void UpdateTitle ( Element el,
                          Document doc );
extern void CloseLogs ( Document doc );
extern void FreeDocumentResource ( Document doc );
extern void DocumentClosed ( NotifyDialog * event );
extern void UpdateContextSensitiveMenus ( Document doc );
extern void ResetHighlightedElement ( void );
extern void SynchronizeSourceView ( NotifyElement *event );
extern void GetCurrentLine ( Document doc,
                             int *line,
                             int *index );
extern void GotoLine ( Document doc,
                       int line,
                       int index,
                       ThotBool selpos );
extern ThotBool SimpleClickInText ( NotifyElement *event );
extern ThotBool DoubleClickInText ( NotifyElement *event );
extern ThotBool RightClickInText ( NotifyElement *event );
extern void CheckSynchronize ( NotifyElement *event );
extern void SelectionChanged ( NotifyElement *event );
extern ThotBool HTMLElementTypeInMenu ( NotifyElement *event );
extern void SetCharFontOrPhrase ( int doc,
                                  int elemtype );
extern void CopyLocation ( Document doc,
                           View view );
extern void PasteLocation ( Document doc,
                            View view );
extern void CopyLink ( Document doc,
                       View view );

#else /* __STDC__ */

extern Element GetElemWithAttr ( Document doc,
                                   AttributeType attrType,
                                   char *nameVal,
                                   Attribute ignoreAtt,
                                   Element ignoreEl );
extern Element SearchNAMEattribute ( Document doc,
                                       char *nameVal,
                                       Attribute ignoreAtt,
                                       Element ignoreEl );
extern void CheckUniqueName ( Element el,
                                Document doc,
                                Attribute attr,
                                AttributeType attrType );
extern void FollowTheLink_callback ( int targetDocument,
                                       int status,
                                       char *urlName,
                                       char *outputfile,
                                       AHTHeaders *http_headers,
                                       void *context );
extern ThotBool IsCSSLink ( Element el,
                              Document doc );
extern void CheckRefresh ( Document doc );
extern void DoAction ( Document doc,
                         View view );
extern ThotBool AcceptTab ( NotifyOnTarget *event );
extern void NextLinkOrFormElement ( Document doc,
                                      View view );
extern void PreviousLinkOrFormElement ( Document doc,
                                          View view );
extern void AccessKeyHandler ( Document doc,
                                 void *param );
extern ThotBool IgnoreEvent ( NotifyElement *event );
extern ThotBool DoubleClick ( NotifyElement *event );
extern ThotBool SimpleClick ( NotifyElement *event );
extern ThotBool SimpleLClick ( NotifyElement *event );
extern ThotBool SimpleRClick ( NotifyElement *event );
extern ThotBool AnnotSimpleClick ( NotifyElement *event );
extern void UpdateTitle ( Element el,
                            Document doc );
extern void CloseLogs ( Document doc );
extern void FreeDocumentResource ( Document doc );
extern void DocumentClosed ( NotifyDialog * event );
extern void UpdateContextSensitiveMenus ( Document doc );
extern void ResetHighlightedElement ( void );
extern void SynchronizeSourceView ( NotifyElement *event );
extern void GetCurrentLine ( Document doc,
                               int *line,
                               int *index );
extern void GotoLine ( Document doc,
                         int line,
                         int index,
                         ThotBool selpos );
extern ThotBool SimpleClickInText ( NotifyElement *event );
extern ThotBool DoubleClickInText ( NotifyElement *event );
extern ThotBool RightClickInText ( NotifyElement *event );
extern void CheckSynchronize ( NotifyElement *event );
extern void SelectionChanged ( NotifyElement *event );
extern ThotBool HTMLElementTypeInMenu ( NotifyElement *event );
extern void SetCharFontOrPhrase ( int doc,
                                    int elemtype );
extern void CopyLocation ( Document doc,
                             View view );
extern void PasteLocation ( Document doc,
                              View view );
extern void CopyLink ( Document doc,
                         View view );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
