/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrReference NextReferenceToEl ( PtrElement pEl,
                                        PtrDocument pDoc,
                                        PtrReference pPrevRef );
extern PtrElement ReferredElement ( PtrReference pRef );
extern void LinkReferredElDescr ( PtrReferredDescr pRefD,
                                  PtrDocument pDoc );
extern PtrReferredDescr NewReferredElDescr ( PtrDocument pDoc );
extern void UnlinkReferredElDescr ( PtrReferredDescr pRefD );
extern void DeleteReferredElDescr ( PtrReferredDescr pRefD );
extern void DeleteAllReferences ( PtrElement pEl );
extern void DeleteReference ( PtrReference pRef );
extern void CancelReference ( PtrElement pEl,
                              PtrDocument pDoc );
extern void CopyReference ( PtrReference pCopyRef,
                            PtrReference pSourceRef,
                            PtrElement *pEl );
extern void TransferReferences ( PtrElement pTarget,
                                 PtrDocument pDoc,
                                 PtrElement pEl,
                                 PtrDocument pSourceDoc );
extern ThotBool SetReference ( PtrElement pRefEl,
                               PtrAttribute pRefAttr,
                               PtrElement pTargetEl,
                               PtrDocument pDoc,
                               PtrDocument pTargetDoc,
                               ThotBool ancestor,
                               ThotBool withAppEvent );
extern void UpdateInclusionElements ( PtrDocument pDoc );

#else /* __STDC__ */

extern PtrReference NextReferenceToEl ( PtrElement pEl,
                                          PtrDocument pDoc,
                                          PtrReference pPrevRef );
extern PtrElement ReferredElement ( PtrReference pRef );
extern void LinkReferredElDescr ( PtrReferredDescr pRefD,
                                    PtrDocument pDoc );
extern PtrReferredDescr NewReferredElDescr ( PtrDocument pDoc );
extern void UnlinkReferredElDescr ( PtrReferredDescr pRefD );
extern void DeleteReferredElDescr ( PtrReferredDescr pRefD );
extern void DeleteAllReferences ( PtrElement pEl );
extern void DeleteReference ( PtrReference pRef );
extern void CancelReference ( PtrElement pEl,
                                PtrDocument pDoc );
extern void CopyReference ( PtrReference pCopyRef,
                              PtrReference pSourceRef,
                              PtrElement *pEl );
extern void TransferReferences ( PtrElement pTarget,
                                   PtrDocument pDoc,
                                   PtrElement pEl,
                                   PtrDocument pSourceDoc );
extern ThotBool SetReference ( PtrElement pRefEl,
                                 PtrAttribute pRefAttr,
                                 PtrElement pTargetEl,
                                 PtrDocument pDoc,
                                 PtrDocument pTargetDoc,
                                 ThotBool ancestor,
                                 ThotBool withAppEvent );
extern void UpdateInclusionElements ( PtrDocument pDoc );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
