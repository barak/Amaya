/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrPRule GetPageRule ( PtrElement pEl,
                              int view,
                              PtrPSchema * pSchP );
extern PtrPRule GetPRulePage ( PRuleType TypeR,
                               int b,
                               PtrPSchema pSchP );
extern void PageHeaderFooter ( PtrElement pElPage,
                               int view,
                               int *b,
                               PtrPSchema * pSchP );
extern void TagAbsBoxInPage ( PtrAbstractBox pAb );
extern void KillAbsBoxAboveLimit ( PtrAbstractBox pP,
                                   int limit,
                                   int viewNb,
                                   PtrDocument pDoc,
                                   PtrAbstractBox * RedispAbsBox );
extern boolean KillAbsBoxBeforePage ( PtrAbstractBox pPage,
                                      int frame,
                                      PtrDocument pDoc,
                                      int viewNb,
                                      int *clipOrg );

#else /* __STDC__ */

extern PtrPRule GetPageRule (/* PtrElement pEl,
                                int view,
                                PtrPSchema * pSchP */);
extern PtrPRule GetPRulePage (/* PRuleType TypeR,
                                 int b,
                                 PtrPSchema pSchP */);
extern void PageHeaderFooter (/* PtrElement pElPage,
                                 int view,
                                 int *b,
                                 PtrPSchema * pSchP */);
extern void TagAbsBoxInPage (/* PtrAbstractBox pAb */);
extern void KillAbsBoxAboveLimit (/* PtrAbstractBox pP,
                                     int limit,
                                     int viewNb,
                                     PtrDocument pDoc,
                                     PtrAbstractBox * RedispAbsBox */);
extern boolean KillAbsBoxBeforePage (/* PtrAbstractBox pPage,
                                        int frame,
                                        PtrDocument pDoc,
                                        int viewNb,
                                        int *clipOrg */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
