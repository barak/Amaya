/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void RedisplayDocument ( Document doc,
                                View view );
extern void SetInternalLinks ( Document document );
extern void PrintAs ( Document doc,
                      View view );
extern void CallbackPrint ( int ref,
                            int typedata,
                            char *data );
extern void InitPrint ( void );
extern void SetupAndPrint ( Document doc,
                            View view );
extern void UpdateURLsInSubtree ( NotifyElement *event,
                                  Element el );
extern void GetIncludedDocuments_callback ( int newdoc,
                                            int status,
                                            char *urlName,
                                            char *outputfile,
                                            char *proxyName,
                                            AHTHeaders *http_headers,
                                            void * context );
extern void MakeBook ( Document doc,
                       View view );
extern void ReadAsUTF_8 ( Document doc,
                          View view );
extern void ReadAsISO_8859_1 ( Document doc,
                               View view );
extern void ReadAsISO_8859_2 ( Document doc,
                               View view );
extern void ReadAsISO_8859_3 ( Document doc,
                               View view );
extern void ReadAsISO_8859_4 ( Document doc,
                               View view );
extern void ReadAsISO_8859_5 ( Document doc,
                               View view );
extern void ReadAsISO_8859_6 ( Document doc,
                               View view );
extern void ReadAsISO_8859_7 ( Document doc,
                               View view );
extern void ReadAsISO_8859_8 ( Document doc,
                               View view );
extern void ReadAsISO_8859_9 ( Document doc,
                               View view );
extern void ReadAsISO_8859_15 ( Document doc,
                                View view );
extern void ReadAsKOI8_R ( Document doc,
                           View view );
extern void ReadAsWINDOWS_1250 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1251 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1252 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1253 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1254 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1255 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1256 ( Document doc,
                                 View view );
extern void ReadAsWINDOWS_1257 ( Document doc,
                                 View view );
extern void ReadAsGB_2312 ( Document doc,
                            View view );
extern void ReadAsISO_2022_JP ( Document doc,
                                View view );
extern void ReadAsEUC_JP ( Document doc,
                           View view );
extern void ReadAsSHIFT_JIS ( Document doc,
                              View view );
extern void SectionNumbering ( Document doc,
                               View view );
extern void MakeToc ( Document doc,
                      View view );

#else /* __STDC__ */

extern void RedisplayDocument ( Document doc,
                                  View view );
extern void SetInternalLinks ( Document document );
extern void PrintAs ( Document doc,
                        View view );
extern void CallbackPrint ( int ref,
                              int typedata,
                              char *data );
extern void InitPrint ( void );
extern void SetupAndPrint ( Document doc,
                              View view );
extern void UpdateURLsInSubtree ( NotifyElement *event,
                                    Element el );
extern void GetIncludedDocuments_callback ( int newdoc,
                                              int status,
                                              char *urlName,
                                              char *outputfile,
                                              char *proxyName,
                                              AHTHeaders *http_headers,
                                              void * context );
extern void MakeBook ( Document doc,
                         View view );
extern void ReadAsUTF_8 ( Document doc,
                            View view );
extern void ReadAsISO_8859_1 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_2 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_3 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_4 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_5 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_6 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_7 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_8 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_9 ( Document doc,
                                 View view );
extern void ReadAsISO_8859_15 ( Document doc,
                                  View view );
extern void ReadAsKOI8_R ( Document doc,
                             View view );
extern void ReadAsWINDOWS_1250 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1251 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1252 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1253 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1254 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1255 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1256 ( Document doc,
                                   View view );
extern void ReadAsWINDOWS_1257 ( Document doc,
                                   View view );
extern void ReadAsGB_2312 ( Document doc,
                              View view );
extern void ReadAsISO_2022_JP ( Document doc,
                                  View view );
extern void ReadAsEUC_JP ( Document doc,
                             View view );
extern void ReadAsSHIFT_JIS ( Document doc,
                                View view );
extern void SectionNumbering ( Document doc,
                                 View view );
extern void MakeToc ( Document doc,
                        View view );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
