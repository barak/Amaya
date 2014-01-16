/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrAbstractBox Enclosing ( PtrAbstractBox pAbb1,
                                  PtrAbstractBox pAbb2 );
extern void UpdateAbsBoxVolume ( PtrElement pEl,
                                 int view,
                                 PtrDocument pDoc );
extern void SimpleSearchRulepEl ( PtrPRule * pRuleView1,
                                  PtrElement pEl,
                                  int view,
                                  PRuleType typeRule,
                                  FunctionType typeFunc,
                                  PtrPRule * pRule );
extern PtrPRule GlobalSearchRulepEl ( PtrElement pEl,
                                      PtrPSchema * pSPR,
                                      PtrSSchema * pSSR,
                                      int presNum,
                                      PtrPSchema pSchP,
                                      int view,
                                      PRuleType typeRule,
                                      FunctionType typeFunc,
                                      boolean isElPage,
                                      boolean attr,
                                      PtrAttribute * pAttr );
extern PtrPRule SearchRulepAb ( PtrDocument pDoc,
                                PtrAbstractBox pAb,
                                PtrPSchema * pSPR,
                                PRuleType typeRule,
                                FunctionType typeFunc,
                                boolean attr,
                                PtrAttribute * pAttr );
extern PtrPRule FunctionRule ( PtrElement pEl,
                               PtrPSchema * pSchP );
extern void SetDeadAbsBox ( PtrAbstractBox pAb );
extern void ApplyRefAbsBoxSupp ( PtrAbstractBox pAb,
                                 PtrAbstractBox * pAbbReDisp,
                                 PtrDocument pDoc );
extern void ApplyRefAbsBoxNew ( PtrAbstractBox pAbbFirst,
                                PtrAbstractBox pAbbLast,
                                PtrAbstractBox * pAbbReDisp,
                                PtrDocument pDoc );
extern void ChangeFirstLast ( PtrElement pEl,
                              PtrDocument pDoc,
                              boolean first,
                              boolean change );
extern PtrElement GetPageBreakForAssoc ( PtrElement pEl,
                                         int viewNb,
                                         int *boxType );
extern void CreateAllAbsBoxesOfEl ( PtrElement pE,
                                    PtrDocument pDoc );
extern void CreateNewAbsBoxes ( PtrElement pEl,
                                PtrDocument pDoc,
                                int viewNb );
extern void DestroyAbsBoxesView ( PtrElement pEl,
                                  PtrDocument pDoc,
                                  boolean verify,
                                  int view );
extern void DestroyAbsBoxes ( PtrElement pEl,
                              PtrDocument pDoc,
                              boolean verify );
extern void RedispRef ( PtrReference pRef,
                        PtrAbstractBox pAb,
                        PtrDocument pDocRef );
extern void RedispAllReferences ( PtrAbstractBox pAb,
                                  PtrDocument pDoc );
extern PtrAbstractBox AbsBoxFromElOrPres ( PtrAbstractBox pAb,
                                           boolean pres,
                                           int typeElOrPres,
                                           PtrPSchema pSchP,
                                           PtrSSchema pSchStr );
extern void ComputePageNum ( PtrElement pEl,
                             int view );
extern void TransmitCounterVal ( PtrElement pEl,
                                 PtrDocument pDoc,
                                 Name nameAttr,
                                 int counter,
                                 PtrPSchema pSchP,
                                 PtrSSchema pSchS );
extern void UpdateNumbers ( PtrElement pElBegin,
                            PtrElement pElModif,
                            PtrDocument pDoc,
                            boolean redisp );
extern void UpdateBoxesCounter ( PtrElement pElBegin,
                                 PtrDocument pDoc,
                                 int counter,
                                 PtrPSchema pSchP,
                                 PtrSSchema pSS );
extern boolean ElemWithinImage ( PtrElement pEl,
                                 int view,
                                 PtrAbstractBox pAbbRoot,
                                 PtrDocument pDoc );
extern void UpdatePresAttr ( PtrElement pEl,
                             PtrAttribute pAttr,
                             PtrDocument pDoc,
                             boolean remove,
                             boolean inherit,
                             PtrAttribute pAttrComp );
extern boolean IsIdenticalTextType ( PtrElement pEl,
                                     PtrDocument pDoc,
                                     PtrElement * pLib );

#else /* __STDC__ */

extern PtrAbstractBox Enclosing (/* PtrAbstractBox pAbb1,
                                    PtrAbstractBox pAbb2 */);
extern void UpdateAbsBoxVolume (/* PtrElement pEl,
                                   int view,
                                   PtrDocument pDoc */);
extern void SimpleSearchRulepEl (/* PtrPRule * pRuleView1,
                                    PtrElement pEl,
                                    int view,
                                    PRuleType typeRule,
                                    FunctionType typeFunc,
                                    PtrPRule * pRule */);
extern PtrPRule GlobalSearchRulepEl (/* PtrElement pEl,
                                        PtrPSchema * pSPR,
                                        PtrSSchema * pSSR,
                                        int presNum,
                                        PtrPSchema pSchP,
                                        int view,
                                        PRuleType typeRule,
                                        FunctionType typeFunc,
                                        boolean isElPage,
                                        boolean attr,
                                        PtrAttribute * pAttr */);
extern PtrPRule SearchRulepAb (/* PtrDocument pDoc,
                                  PtrAbstractBox pAb,
                                  PtrPSchema * pSPR,
                                  PRuleType typeRule,
                                  FunctionType typeFunc,
                                  boolean attr,
                                  PtrAttribute * pAttr */);
extern PtrPRule FunctionRule (/* PtrElement pEl,
                                 PtrPSchema * pSchP */);
extern void SetDeadAbsBox (/* PtrAbstractBox pAb */);
extern void ApplyRefAbsBoxSupp (/* PtrAbstractBox pAb,
                                   PtrAbstractBox * pAbbReDisp,
                                   PtrDocument pDoc */);
extern void ApplyRefAbsBoxNew (/* PtrAbstractBox pAbbFirst,
                                  PtrAbstractBox pAbbLast,
                                  PtrAbstractBox * pAbbReDisp,
                                  PtrDocument pDoc */);
extern void ChangeFirstLast (/* PtrElement pEl,
                                PtrDocument pDoc,
                                boolean first,
                                boolean change */);
extern PtrElement GetPageBreakForAssoc (/* PtrElement pEl,
                                           int viewNb,
                                           int *boxType */);
extern void CreateAllAbsBoxesOfEl (/* PtrElement pE,
                                      PtrDocument pDoc */);
extern void CreateNewAbsBoxes (/* PtrElement pEl,
                                  PtrDocument pDoc,
                                  int viewNb */);
extern void DestroyAbsBoxesView (/* PtrElement pEl,
                                    PtrDocument pDoc,
                                    boolean verify,
                                    int view */);
extern void DestroyAbsBoxes (/* PtrElement pEl,
                                PtrDocument pDoc,
                                boolean verify */);
extern void RedispRef (/* PtrReference pRef,
                          PtrAbstractBox pAb,
                          PtrDocument pDocRef */);
extern void RedispAllReferences (/* PtrAbstractBox pAb,
                                    PtrDocument pDoc */);
extern PtrAbstractBox AbsBoxFromElOrPres (/* PtrAbstractBox pAb,
                                             boolean pres,
                                             int typeElOrPres,
                                             PtrPSchema pSchP,
                                             PtrSSchema pSchStr */);
extern void ComputePageNum (/* PtrElement pEl,
                               int view */);
extern void TransmitCounterVal (/* PtrElement pEl,
                                   PtrDocument pDoc,
                                   Name nameAttr,
                                   int counter,
                                   PtrPSchema pSchP,
                                   PtrSSchema pSchS */);
extern void UpdateNumbers (/* PtrElement pElBegin,
                              PtrElement pElModif,
                              PtrDocument pDoc,
                              boolean redisp */);
extern void UpdateBoxesCounter (/* PtrElement pElBegin,
                                   PtrDocument pDoc,
                                   int counter,
                                   PtrPSchema pSchP,
                                   PtrSSchema pSS */);
extern boolean ElemWithinImage (/* PtrElement pEl,
                                   int view,
                                   PtrAbstractBox pAbbRoot,
                                   PtrDocument pDoc */);
extern void UpdatePresAttr (/* PtrElement pEl,
                               PtrAttribute pAttr,
                               PtrDocument pDoc,
                               boolean remove,
                               boolean inherit,
                               PtrAttribute pAttrComp */);
extern boolean IsIdenticalTextType (/* PtrElement pEl,
                                       PtrDocument pDoc,
                                       PtrElement * pLib */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
