/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void GetXYOrg ( int frame,
                       int *XOrg,
                       int *YOrg );
extern void DefClip ( int frame,
                      int xstart,
                      int ytop,
                      int xstop,
                      int ybottom );
extern void DefBoxRegion ( int frame,
                           PtrBox pBox,
                           int xstart,
                           int xstop,
                           int ystart,
                           int ystop );
extern void UpdateBoxRegion ( int frame,
                              PtrBox pBox,
                              int dx,
                              int dy,
                              int dw,
                              int dh );
extern void TtaRefresh ( void );
extern void DrawFilledBox ( PtrBox pBox,
                            PtrAbstractBox pFrom,
                            int frame,
                            PtrFlow pFlow,
                            int xmin,
                            int xmax,
                            int ymin,
                            int ymax,
                            ThotBool selected,
                            ThotBool first,
                            ThotBool last,
                            ThotBool topdown,
                            ThotBool show_bgimage );
extern void GetBoxTransformedCoord ( PtrAbstractBox pAbSeeked,
                                     int frame,
                                     int *lowerx,
                                     int *higherx,
                                     int *x,
                                     int *y );
extern PtrBox DisplayAllBoxes ( int frame,
                                PtrFlow pFlow,
                                int xmin,
                                int xmax,
                                int ymin,
                                int ymax,
                                PtrBox *create,
                                int *tVol,
                                int *bVol );
extern ThotBool NeedToComputeABoundingBox ( PtrAbstractBox pAb,
                                            int frame );
extern void ComputeChangedBoundingBoxes ( int frame );
extern ThotBool RedrawFrameTop ( int frame,
                                 int scroll );
extern ThotBool RedrawFrameBottom ( int frame,
                                    int scroll,
                                    PtrAbstractBox subtree );
extern void DisplayFrame ( int frame );

#else /* __STDC__ */

extern void GetXYOrg ( int frame,
                         int *XOrg,
                         int *YOrg );
extern void DefClip ( int frame,
                        int xstart,
                        int ytop,
                        int xstop,
                        int ybottom );
extern void DefBoxRegion ( int frame,
                             PtrBox pBox,
                             int xstart,
                             int xstop,
                             int ystart,
                             int ystop );
extern void UpdateBoxRegion ( int frame,
                                PtrBox pBox,
                                int dx,
                                int dy,
                                int dw,
                                int dh );
extern void TtaRefresh ( void );
extern void DrawFilledBox ( PtrBox pBox,
                              PtrAbstractBox pFrom,
                              int frame,
                              PtrFlow pFlow,
                              int xmin,
                              int xmax,
                              int ymin,
                              int ymax,
                              ThotBool selected,
                              ThotBool first,
                              ThotBool last,
                              ThotBool topdown,
                              ThotBool show_bgimage );
extern void GetBoxTransformedCoord ( PtrAbstractBox pAbSeeked,
                                       int frame,
                                       int *lowerx,
                                       int *higherx,
                                       int *x,
                                       int *y );
extern PtrBox DisplayAllBoxes ( int frame,
                                  PtrFlow pFlow,
                                  int xmin,
                                  int xmax,
                                  int ymin,
                                  int ymax,
                                  PtrBox *create,
                                  int *tVol,
                                  int *bVol );
extern ThotBool NeedToComputeABoundingBox ( PtrAbstractBox pAb,
                                              int frame );
extern void ComputeChangedBoundingBoxes ( int frame );
extern ThotBool RedrawFrameTop ( int frame,
                                   int scroll );
extern ThotBool RedrawFrameBottom ( int frame,
                                      int scroll,
                                      PtrAbstractBox subtree );
extern void DisplayFrame ( int frame );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */