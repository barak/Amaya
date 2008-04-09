/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern ThotBool APPgraphicModify ( PtrElement pEl,
                                   int value,
                                   int frame,
                                   ThotBool pre,
                                   ThotBool openclose );
extern ThotBool LocateSelectionInView ( int frame,
                                        int x,
                                        int y,
                                        int button );
extern ThotPoint *BuildPolygonForPath ( PtrPathSeg pPa,
                                        int frame,
                                        int* npoints,
                                        int **subpathStart );
extern PtrAbstractBox GetClickedAbsBox ( int frame,
                                         int xRef,
                                         int yRef );
extern PtrBox GetEnclosingClickedBox ( PtrAbstractBox pAb,
                                       int higherX,
                                       int lowerX,
                                       int y,
                                       int frame,
                                       int *pointselect,
                                       PtrFlow *pFlow );
extern PtrBox GetLeafBox ( PtrBox pSourceBox,
                           int frame,
                           int *x,
                           int *y,
                           int xDelta,
                           int yDelta,
                           PtrFlow *pFlow );
extern int GetShapeDistance ( int xRef,
                              int yRef,
                              PtrBox pBox,
                              int value,
                              int frame );
extern PtrBox GetClickedLeafBox ( int frame,
                                  int xRef,
                                  int yRef,
                                  PtrFlow *pFlow );
extern void ApplyDirectTranslate ( int frame,
                                   int xm,
                                   int ym );
extern void ApplyDirectResize ( int frame,
                                int xm,
                                int ym );
extern void DirectCreation ( PtrBox pBox,
                             int frame );
extern void LocateClickedChar ( PtrBox pBox,
                                int frame,
                                ThotBool extend,
                                PtrTextBuffer *pBuffer,
                                int *x,
                                int *index,
                                int *nChars,
                                int *nSpaces );

#else /* __STDC__ */

extern ThotBool APPgraphicModify ( PtrElement pEl,
                                     int value,
                                     int frame,
                                     ThotBool pre,
                                     ThotBool openclose );
extern ThotBool LocateSelectionInView ( int frame,
                                          int x,
                                          int y,
                                          int button );
extern ThotPoint *BuildPolygonForPath ( PtrPathSeg pPa,
                                          int frame,
                                          int* npoints,
                                          int **subpathStart );
extern PtrAbstractBox GetClickedAbsBox ( int frame,
                                           int xRef,
                                           int yRef );
extern PtrBox GetEnclosingClickedBox ( PtrAbstractBox pAb,
                                         int higherX,
                                         int lowerX,
                                         int y,
                                         int frame,
                                         int *pointselect,
                                         PtrFlow *pFlow );
extern PtrBox GetLeafBox ( PtrBox pSourceBox,
                             int frame,
                             int *x,
                             int *y,
                             int xDelta,
                             int yDelta,
                             PtrFlow *pFlow );
extern int GetShapeDistance ( int xRef,
                                int yRef,
                                PtrBox pBox,
                                int value,
                                int frame );
extern PtrBox GetClickedLeafBox ( int frame,
                                    int xRef,
                                    int yRef,
                                    PtrFlow *pFlow );
extern void ApplyDirectTranslate ( int frame,
                                     int xm,
                                     int ym );
extern void ApplyDirectResize ( int frame,
                                  int xm,
                                  int ym );
extern void DirectCreation ( PtrBox pBox,
                               int frame );
extern void LocateClickedChar ( PtrBox pBox,
                                  int frame,
                                  ThotBool extend,
                                  PtrTextBuffer *pBuffer,
                                  int *x,
                                  int *index,
                                  int *nChars,
                                  int *nSpaces );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
