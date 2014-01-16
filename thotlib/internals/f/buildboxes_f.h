/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrAbstractBox SearchNextAbsBox ( PtrAbstractBox pAb,
                                         PtrAbstractBox pRoot );
extern PtrAbstractBox GetParentTable ( PtrBox pBox );
extern PtrAbstractBox GetParentCell ( PtrBox pBox );
extern PtrAbstractBox GetParentDraw ( PtrBox pBox );
extern C_points *ComputeControlPoints ( PtrTextBuffer buffer,
                                        int nb );
extern char GiveTextParams ( PtrTextBuffer *pBuffer,
                             int *ind,
                             int *nChars,
                             SpecFont font,
                             int *width,
                             int *nSpaces,
                             char dir,
                             char bidi,
                             ThotBool *embedded,
                             char prevscript );
extern void GiveSymbolSize ( PtrAbstractBox pAb,
                             int *width,
                             int *height );
extern void GiveGraphicSize ( PtrAbstractBox pAb,
                              int *width,
                              int *height );
extern PtrBox SplitForScript ( PtrBox box,
                               PtrAbstractBox pAb,
                               char script,
                               int lg,
                               int width,
                               int height,
                               int spaces,
                               int ind,
                               PtrTextBuffer pBuffer,
                               int frame );
extern void GiveEnclosureSize ( PtrAbstractBox pAb,
                                int frame,
                                int *width,
                                int *height );
extern ThotBool CheckMBP ( PtrAbstractBox pAb,
                           PtrBox pBox,
                           int frame,
                           ThotBool evalAuto );
extern PtrAbstractBox SearchEnclosingType ( PtrAbstractBox pAb,
                                            BoxType type1,
                                            BoxType type2,
                                            BoxType type3 );
extern PtrLine SearchLine ( PtrBox pBox,
                            int frame );
extern void BoxUpdate ( PtrBox pBox,
                        PtrLine pLine,
                        int charDelta,
                        int spaceDelta,
                        int wDelta,
                        int adjustDelta,
                        int hDelta,
                        int frame,
                        ThotBool splitBox );
extern void RemoveBoxes ( PtrAbstractBox pAb,
                          ThotBool rebuild,
                          int frame );
extern void RecordEnclosing ( PtrBox pBox,
                              ThotBool horizRef );
extern ThotBool ComputeUpdates ( PtrAbstractBox pAb,
                                 int frame,
                                 ThotBool *computeBBoxes );
extern void ComputeEnclosing ( int frame );
extern void RebuildConcreteImage ( int frame,
                                   ThotBool scrollUpdate );
extern ThotBool IsDead ( PtrAbstractBox pAb );
extern void ClearConcreteImage ( int frame );
extern void CheckScrollingWidthHeight ( int frame );
extern ThotBool ChangeConcreteImage ( int frame,
                                      int *pageHeight,
                                      PtrAbstractBox pAb );

#else /* __STDC__ */

extern PtrAbstractBox SearchNextAbsBox ( PtrAbstractBox pAb,
                                           PtrAbstractBox pRoot );
extern PtrAbstractBox GetParentTable ( PtrBox pBox );
extern PtrAbstractBox GetParentCell ( PtrBox pBox );
extern PtrAbstractBox GetParentDraw ( PtrBox pBox );
extern C_points *ComputeControlPoints ( PtrTextBuffer buffer,
                                          int nb );
extern char GiveTextParams ( PtrTextBuffer *pBuffer,
                               int *ind,
                               int *nChars,
                               SpecFont font,
                               int *width,
                               int *nSpaces,
                               char dir,
                               char bidi,
                               ThotBool *embedded,
                               char prevscript );
extern void GiveSymbolSize ( PtrAbstractBox pAb,
                               int *width,
                               int *height );
extern void GiveGraphicSize ( PtrAbstractBox pAb,
                                int *width,
                                int *height );
extern PtrBox SplitForScript ( PtrBox box,
                                 PtrAbstractBox pAb,
                                 char script,
                                 int lg,
                                 int width,
                                 int height,
                                 int spaces,
                                 int ind,
                                 PtrTextBuffer pBuffer,
                                 int frame );
extern void GiveEnclosureSize ( PtrAbstractBox pAb,
                                  int frame,
                                  int *width,
                                  int *height );
extern ThotBool CheckMBP ( PtrAbstractBox pAb,
                             PtrBox pBox,
                             int frame,
                             ThotBool evalAuto );
extern PtrAbstractBox SearchEnclosingType ( PtrAbstractBox pAb,
                                              BoxType type1,
                                              BoxType type2,
                                              BoxType type3 );
extern PtrLine SearchLine ( PtrBox pBox,
                              int frame );
extern void BoxUpdate ( PtrBox pBox,
                          PtrLine pLine,
                          int charDelta,
                          int spaceDelta,
                          int wDelta,
                          int adjustDelta,
                          int hDelta,
                          int frame,
                          ThotBool splitBox );
extern void RemoveBoxes ( PtrAbstractBox pAb,
                            ThotBool rebuild,
                            int frame );
extern void RecordEnclosing ( PtrBox pBox,
                                ThotBool horizRef );
extern ThotBool ComputeUpdates ( PtrAbstractBox pAb,
                                   int frame,
                                   ThotBool *computeBBoxes );
extern void ComputeEnclosing ( int frame );
extern void RebuildConcreteImage ( int frame,
                                     ThotBool scrollUpdate );
extern ThotBool IsDead ( PtrAbstractBox pAb );
extern void ClearConcreteImage ( int frame );
extern void CheckScrollingWidthHeight ( int frame );
extern ThotBool ChangeConcreteImage ( int frame,
                                        int *pageHeight,
                                        PtrAbstractBox pAb );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
