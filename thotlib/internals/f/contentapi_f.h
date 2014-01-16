/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void TtaSetTextContent ( Element element,
                                char *content,
                                Language language,
                                Document document );
extern void InsertText ( PtrElement pEl,
                         int position,
                         char *content,
                         Document document );
extern void TtaAppendTextContent ( Element element,
                                   char *content,
                                   Document document );
extern void TtaInsertTextContent ( Element element,
                                   int position,
                                   char *content,
                                   Document document );
extern void TtaDeleteTextContent ( Element element,
                                   int position,
                                   int length,
                                   Document document );
extern void TtaSplitText ( Element element,
                           int position,
                           Document document );
extern boolean TtaMergeText ( Element element,
                              Document document );
extern void TtaSetGraphicsShape ( Element element,
                                  char shape,
                                  Document document );
extern void TtaAddPointInPolyline ( Element element,
                                    int rank,
                                    TypeUnit unit,
                                    int x,
                                    int y,
                                    Document document );
extern void TtaDeletePointInPolyline ( Element element,
                                       int rank,
                                       Document document );
extern void TtaModifyPointInPolyline ( Element element,
                                       int rank,
                                       TypeUnit unit,
                                       int x,
                                       int y,
                                       Document document );
extern void TtaChangeLimitOfPolyline ( Element element,
                                       TypeUnit unit,
                                       int x,
                                       int y,
                                       Document document );
extern void TtaCopyPage ( Element destination,
                          Element source );
extern int TtaGetTextLength ( Element element );
extern PicType TtaGetPictureType ( Element element );
extern void TtaGiveTextContent ( Element element,
                                 char *buffer,
                                 int *length,
                                 Language * language );
extern void TtaGiveSubString ( Element element,
                               char *buffer,
                               int position,
                               int length );
extern char TtaGetGraphicsShape ( Element element );
extern int TtaGetPolylineLength ( Element element );
extern void TtaGivePolylinePoint ( Element element,
                                   int rank,
                                   TypeUnit unit,
                                   int *x,
                                   int *y );
extern int TtaGetPageNumber ( Element pageElement );
extern int TtaGetPageView ( Element pageElement );

#else /* __STDC__ */

extern void TtaSetTextContent (/* Element element,
                                  char *content,
                                  Language language,
                                  Document document */);
extern void InsertText (/* PtrElement pEl,
                           int position,
                           char *content,
                           Document document */);
extern void TtaAppendTextContent (/* Element element,
                                     char *content,
                                     Document document */);
extern void TtaInsertTextContent (/* Element element,
                                     int position,
                                     char *content,
                                     Document document */);
extern void TtaDeleteTextContent (/* Element element,
                                     int position,
                                     int length,
                                     Document document */);
extern void TtaSplitText (/* Element element,
                             int position,
                             Document document */);
extern boolean TtaMergeText (/* Element element,
                                Document document */);
extern void TtaSetGraphicsShape (/* Element element,
                                    char shape,
                                    Document document */);
extern void TtaAddPointInPolyline (/* Element element,
                                      int rank,
                                      TypeUnit unit,
                                      int x,
                                      int y,
                                      Document document */);
extern void TtaDeletePointInPolyline (/* Element element,
                                         int rank,
                                         Document document */);
extern void TtaModifyPointInPolyline (/* Element element,
                                         int rank,
                                         TypeUnit unit,
                                         int x,
                                         int y,
                                         Document document */);
extern void TtaChangeLimitOfPolyline (/* Element element,
                                         TypeUnit unit,
                                         int x,
                                         int y,
                                         Document document */);
extern void TtaCopyPage (/* Element destination,
                            Element source */);
extern int TtaGetTextLength (/* Element element */);
extern PicType TtaGetPictureType (/* Element element */);
extern void TtaGiveTextContent (/* Element element,
                                   char *buffer,
                                   int *length,
                                   Language * language */);
extern void TtaGiveSubString (/* Element element,
                                 char *buffer,
                                 int position,
                                 int length */);
extern char TtaGetGraphicsShape (/* Element element */);
extern int TtaGetPolylineLength (/* Element element */);
extern void TtaGivePolylinePoint (/* Element element,
                                     int rank,
                                     TypeUnit unit,
                                     int *x,
                                     int *y */);
extern int TtaGetPageNumber (/* Element pageElement */);
extern int TtaGetPageView (/* Element pageElement */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
