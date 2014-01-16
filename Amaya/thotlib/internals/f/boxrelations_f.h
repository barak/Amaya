/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void SetPositionConstraint ( BoxEdge localEdge,
                                    PtrBox pBox,
                                    int *val );
extern int GetPixelValue ( int val,
                           TypeUnit unit,
                           int size,
                           PtrAbstractBox pAb,
                           int zoom );
extern void ComputeRadius ( PtrAbstractBox pAb,
                            int frame,
                            ThotBool horizRef );
extern void CleanAutoMargins ( PtrAbstractBox pAb );
extern PtrAbstractBox GetEnclosingViewport ( PtrAbstractBox pAb );
extern void ComputeMBP ( PtrAbstractBox pAb,
                         int frame,
                         ThotBool horizRef,
                         ThotBool evalAuto );
extern ThotBool ComputePositioning ( PtrBox pBox,
                                     int frame );
extern void ComputePosRelation ( AbPosition *rule,
                                 PtrBox pBox,
                                 int frame,
                                 ThotBool horizRef );
extern PtrBox GetHPosRelativeBox ( PtrBox pBox,
                                   PtrBox pPreviousBox );
extern PtrBox GetVPosRelativeBox ( PtrBox pBox,
                                   PtrBox pPreviousBox );
extern int GetPercentDim ( PtrAbstractBox pAb,
                           PtrAbstractBox pParentAb,
                           ThotBool horizRef );
extern ThotBool ComputeDimRelation ( PtrAbstractBox pAb,
                                     int frame,
                                     ThotBool horizRef );
extern void ComputeAxisRelation ( AbPosition rule,
                                  PtrBox pBox,
                                  int frame,
                                  ThotBool horizRef );
extern void ClearOutOfStructRelation ( PtrBox pBox,
                                       int frame );
extern void ClearPosRelation ( PtrBox pBox,
                               ThotBool horizRef );
extern void ClearAxisRelation ( PtrBox pBox,
                                ThotBool horizRef );
extern void ClearAllRelations ( PtrBox pBox,
                                int frame );
extern void ClearDimRelation ( PtrBox pBox,
                               ThotBool horizRef,
                               int frame );

#else /* __STDC__ */

extern void SetPositionConstraint ( BoxEdge localEdge,
                                      PtrBox pBox,
                                      int *val );
extern int GetPixelValue ( int val,
                             TypeUnit unit,
                             int size,
                             PtrAbstractBox pAb,
                             int zoom );
extern void ComputeRadius ( PtrAbstractBox pAb,
                              int frame,
                              ThotBool horizRef );
extern void CleanAutoMargins ( PtrAbstractBox pAb );
extern PtrAbstractBox GetEnclosingViewport ( PtrAbstractBox pAb );
extern void ComputeMBP ( PtrAbstractBox pAb,
                           int frame,
                           ThotBool horizRef,
                           ThotBool evalAuto );
extern ThotBool ComputePositioning ( PtrBox pBox,
                                       int frame );
extern void ComputePosRelation ( AbPosition *rule,
                                   PtrBox pBox,
                                   int frame,
                                   ThotBool horizRef );
extern PtrBox GetHPosRelativeBox ( PtrBox pBox,
                                     PtrBox pPreviousBox );
extern PtrBox GetVPosRelativeBox ( PtrBox pBox,
                                     PtrBox pPreviousBox );
extern int GetPercentDim ( PtrAbstractBox pAb,
                             PtrAbstractBox pParentAb,
                             ThotBool horizRef );
extern ThotBool ComputeDimRelation ( PtrAbstractBox pAb,
                                       int frame,
                                       ThotBool horizRef );
extern void ComputeAxisRelation ( AbPosition rule,
                                    PtrBox pBox,
                                    int frame,
                                    ThotBool horizRef );
extern void ClearOutOfStructRelation ( PtrBox pBox,
                                         int frame );
extern void ClearPosRelation ( PtrBox pBox,
                                 ThotBool horizRef );
extern void ClearAxisRelation ( PtrBox pBox,
                                  ThotBool horizRef );
extern void ClearAllRelations ( PtrBox pBox,
                                  int frame );
extern void ClearDimRelation ( PtrBox pBox,
                                 ThotBool horizRef,
                                 int frame );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
