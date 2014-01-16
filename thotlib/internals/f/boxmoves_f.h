/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void IsXYPosComplete ( PtrBox pBox,
                              boolean * horizRef,
                              boolean * vertRef );
extern boolean IsXPosComplete ( PtrBox pBox );
extern boolean IsYPosComplete ( PtrBox pBox );
extern boolean IsParentBox ( PtrBox pBox,
                             PtrBox pRefBox );
extern void MirrorShape ( PtrAbstractBox pAb,
                          boolean horizRef,
                          boolean vertRef,
                          boolean inAbtractBox );
extern void XEdgesExchange ( PtrBox pBox,
                             OpRelation op );
extern void YEdgesExchange ( PtrBox pBox,
                             OpRelation op );
extern void ChangeDefaultHeight ( PtrBox pBox,
                                  PtrBox pSourceBox,
                                  int height,
                                  int frame );
extern void ChangeDefaultWidth ( PtrBox pBox,
                                 PtrBox pSourceBox,
                                 int width,
                                 int spaceDelta,
                                 int frame );
extern void ChangeWidth ( PtrBox pBox,
                          PtrBox pSourceBox,
                          PtrBox pFromBox,
                          int delta,
                          int spaceDelta,
                          int frame );
extern void ChangeHeight ( PtrBox pBox,
                           PtrBox pSourceBox,
                           PtrBox pFromBox,
                           int delta,
                           int frame );
extern void MoveBoxEdge ( PtrBox pBox,
                          PtrBox pSourceBox,
                          OpRelation op,
                          int delta,
                          int frame,
                          boolean horizRef );
extern void XMoveAllEnclosed ( PtrBox pBox,
                               int delta,
                               int frame );
extern void YMoveAllEnclosed ( PtrBox pBox,
                               int delta,
                               int frame );
extern void MoveVertRef ( PtrBox pBox,
                          PtrBox pFromBox,
                          int delta,
                          int frame );
extern void MoveHorizRef ( PtrBox pBox,
                           PtrBox pFromBox,
                           int delta,
                           int frame );
extern void ResizeWidth ( PtrBox pBox,
                          PtrBox pSourceBox,
                          PtrBox pFromBox,
                          int delta,
                          int spaceDelta,
                          int frame );
extern void ResizeHeight ( PtrBox pBox,
                           PtrBox pSourceBox,
                           PtrBox pFromBox,
                           int delta,
                           int frame );
extern void XMove ( PtrBox pBox,
                    PtrBox pFromBox,
                    int delta,
                    int frame );
extern void YMove ( PtrBox pBox,
                    PtrBox pFromBox,
                    int delta,
                    int frame );
extern void WidthPack ( PtrAbstractBox pAb,
                        PtrBox pSourceBox,
                        int frame );
extern void HeightPack ( PtrAbstractBox pAb,
                         PtrBox pSourceBox,
                         int frame );

#else /* __STDC__ */

extern void IsXYPosComplete (/* PtrBox pBox,
                                boolean * horizRef,
                                boolean * vertRef */);
extern boolean IsXPosComplete (/* PtrBox pBox */);
extern boolean IsYPosComplete (/* PtrBox pBox */);
extern boolean IsParentBox (/* PtrBox pBox,
                               PtrBox pRefBox */);
extern void MirrorShape (/* PtrAbstractBox pAb,
                            boolean horizRef,
                            boolean vertRef,
                            boolean inAbtractBox */);
extern void XEdgesExchange (/* PtrBox pBox,
                               OpRelation op */);
extern void YEdgesExchange (/* PtrBox pBox,
                               OpRelation op */);
extern void ChangeDefaultHeight (/* PtrBox pBox,
                                    PtrBox pSourceBox,
                                    int height,
                                    int frame */);
extern void ChangeDefaultWidth (/* PtrBox pBox,
                                   PtrBox pSourceBox,
                                   int width,
                                   int spaceDelta,
                                   int frame */);
extern void ChangeWidth (/* PtrBox pBox,
                            PtrBox pSourceBox,
                            PtrBox pFromBox,
                            int delta,
                            int spaceDelta,
                            int frame */);
extern void ChangeHeight (/* PtrBox pBox,
                             PtrBox pSourceBox,
                             PtrBox pFromBox,
                             int delta,
                             int frame */);
extern void MoveBoxEdge (/* PtrBox pBox,
                            PtrBox pSourceBox,
                            OpRelation op,
                            int delta,
                            int frame,
                            boolean horizRef */);
extern void XMoveAllEnclosed (/* PtrBox pBox,
                                 int delta,
                                 int frame */);
extern void YMoveAllEnclosed (/* PtrBox pBox,
                                 int delta,
                                 int frame */);
extern void MoveVertRef (/* PtrBox pBox,
                            PtrBox pFromBox,
                            int delta,
                            int frame */);
extern void MoveHorizRef (/* PtrBox pBox,
                             PtrBox pFromBox,
                             int delta,
                             int frame */);
extern void ResizeWidth (/* PtrBox pBox,
                            PtrBox pSourceBox,
                            PtrBox pFromBox,
                            int delta,
                            int spaceDelta,
                            int frame */);
extern void ResizeHeight (/* PtrBox pBox,
                             PtrBox pSourceBox,
                             PtrBox pFromBox,
                             int delta,
                             int frame */);
extern void XMove (/* PtrBox pBox,
                      PtrBox pFromBox,
                      int delta,
                      int frame */);
extern void YMove (/* PtrBox pBox,
                      PtrBox pFromBox,
                      int delta,
                      int frame */);
extern void WidthPack (/* PtrAbstractBox pAb,
                          PtrBox pSourceBox,
                          int frame */);
extern void HeightPack (/* PtrAbstractBox pAb,
                           PtrBox pSourceBox,
                           int frame */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
