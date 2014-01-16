/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrTextBuffer NewTextBuffer ( PtrTextBuffer pBuf );
extern void CreateTextBuffer ( PtrElement pEl );
extern void DeleteTextBuffer ( PtrTextBuffer *pBuf );
extern void SplitTextElement ( PtrElement pEl,
                               int rank,
                               PtrDocument pDoc,
                               ThotBool withAppEvent,
                               PtrElement *pSecondPart,
                               ThotBool elBreak );
extern ThotBool MergeTextElements ( PtrElement pEl,
                                    PtrElement *pFreeEl,
                                    PtrDocument pDoc,
                                    ThotBool withAppEvent,
                                    ThotBool removeAbsBox );
extern PtrTextBuffer CopyText ( PtrTextBuffer pBuf,
                                PtrElement pEl );
extern PtrPathSeg CopyPath ( PtrPathSeg firstPathEl );
extern ThotBool StringAndTextEqual ( char *text,
                                     PtrTextBuffer pBuf );
extern ThotBool TextsEqual ( PtrTextBuffer pBuf1,
                             PtrTextBuffer pBuf2 );
extern void CopyTextToText ( PtrTextBuffer pSrceBuf,
                             PtrTextBuffer pCopyBuf,
                             int *len );
extern int CopyMBs2Buffer ( unsigned char *src,
                            PtrTextBuffer pBuf,
                            int pos,
                            int slength );
extern int CopyBuffer2MBs ( PtrTextBuffer pBuf,
                            int pos,
                            unsigned char *des,
                            int max );
extern void CopyStringToBuffer ( unsigned char *src,
                                 PtrTextBuffer pDestBuf,
                                 int *length );
extern void ClearText ( PtrTextBuffer pBuf );
extern void AddPointInPolyline ( PtrTextBuffer firstBuffer,
                                 int rank,
                                 int x,
                                 int y );
extern void DeletePointInPolyline ( PtrTextBuffer * firstBuffer,
                                    int rank );
extern void ModifyPointInPolyline ( PtrTextBuffer firstBuffer,
                                    int rank,
                                    int x,
                                    int y );
extern int TtaGetTextLength ( Element element );
extern void TtaGiveTextContent ( Element element,
                                 unsigned char *buffer,
                                 int *length,
                                 Language *language );
extern void *TtaCopyPath ( void *void_src );
extern void *TtaCopyAnim ( void *void_src );
extern void TtaReplaceTransform ( Element element,
                                  void *transform,
                                  Document document );
extern void *TtaCopyTransform ( void *void_pPa );
extern void *TtaNewBoxTransformTranslate ( float x,
                                           float y );
extern void *TtaNewTransformTranslate ( float x,
                                        float y );
extern void *TtaNewTransformAnimTranslate ( float x,
                                            float y );
extern void *TtaNewTransformAnimRotate ( float angle,
                                         float x_scale,
                                         float y_scale );
extern void *TtaNewTransformRotate ( float angle,
                                     float x_scale,
                                     float y_scale );
extern void *TtaNewTransformSkewX ( float factor );
extern void *TtaNewTransformSkewY ( float factor );
extern void *TtaNewTransformScale ( float x_scale,
                                    float y_scale );
extern void *TtaNewTransformViewBox ( float x,
                                      float y,
                                      float w,
                                      float h,
                                      int align,
                                      int meetOrSlice );
extern void *TtaNewTransformMatrix ( float a,
                                     float b,
                                     float c,
                                     float d,
                                     float e,
                                     float f );

#else /* __STDC__ */

extern PtrTextBuffer NewTextBuffer ( PtrTextBuffer pBuf );
extern void CreateTextBuffer ( PtrElement pEl );
extern void DeleteTextBuffer ( PtrTextBuffer *pBuf );
extern void SplitTextElement ( PtrElement pEl,
                                 int rank,
                                 PtrDocument pDoc,
                                 ThotBool withAppEvent,
                                 PtrElement *pSecondPart,
                                 ThotBool elBreak );
extern ThotBool MergeTextElements ( PtrElement pEl,
                                      PtrElement *pFreeEl,
                                      PtrDocument pDoc,
                                      ThotBool withAppEvent,
                                      ThotBool removeAbsBox );
extern PtrTextBuffer CopyText ( PtrTextBuffer pBuf,
                                  PtrElement pEl );
extern PtrPathSeg CopyPath ( PtrPathSeg firstPathEl );
extern ThotBool StringAndTextEqual ( char *text,
                                       PtrTextBuffer pBuf );
extern ThotBool TextsEqual ( PtrTextBuffer pBuf1,
                               PtrTextBuffer pBuf2 );
extern void CopyTextToText ( PtrTextBuffer pSrceBuf,
                               PtrTextBuffer pCopyBuf,
                               int *len );
extern int CopyMBs2Buffer ( unsigned char *src,
                              PtrTextBuffer pBuf,
                              int pos,
                              int slength );
extern int CopyBuffer2MBs ( PtrTextBuffer pBuf,
                              int pos,
                              unsigned char *des,
                              int max );
extern void CopyStringToBuffer ( unsigned char *src,
                                   PtrTextBuffer pDestBuf,
                                   int *length );
extern void ClearText ( PtrTextBuffer pBuf );
extern void AddPointInPolyline ( PtrTextBuffer firstBuffer,
                                   int rank,
                                   int x,
                                   int y );
extern void DeletePointInPolyline ( PtrTextBuffer * firstBuffer,
                                      int rank );
extern void ModifyPointInPolyline ( PtrTextBuffer firstBuffer,
                                      int rank,
                                      int x,
                                      int y );
extern int TtaGetTextLength ( Element element );
extern void TtaGiveTextContent ( Element element,
                                   unsigned char *buffer,
                                   int *length,
                                   Language *language );
extern void *TtaCopyPath ( void *void_src );
extern void *TtaCopyAnim ( void *void_src );
extern void TtaReplaceTransform ( Element element,
                                    void *transform,
                                    Document document );
extern void *TtaCopyTransform ( void *void_pPa );
extern void *TtaNewBoxTransformTranslate ( float x,
                                             float y );
extern void *TtaNewTransformTranslate ( float x,
                                          float y );
extern void *TtaNewTransformAnimTranslate ( float x,
                                              float y );
extern void *TtaNewTransformAnimRotate ( float angle,
                                           float x_scale,
                                           float y_scale );
extern void *TtaNewTransformRotate ( float angle,
                                       float x_scale,
                                       float y_scale );
extern void *TtaNewTransformSkewX ( float factor );
extern void *TtaNewTransformSkewY ( float factor );
extern void *TtaNewTransformScale ( float x_scale,
                                      float y_scale );
extern void *TtaNewTransformViewBox ( float x,
                                        float y,
                                        float w,
                                        float h,
                                        int align,
                                        int meetOrSlice );
extern void *TtaNewTransformMatrix ( float a,
                                       float b,
                                       float c,
                                       float d,
                                       float e,
                                       float f );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
