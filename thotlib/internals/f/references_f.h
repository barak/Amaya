/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrElement ReferredElement ( PtrReference pRef,
                                    DocumentIdentifier * docIdent,
                                    PtrDocument * pDoc );
extern PtrReference SearchExternalReferenceToElem ( PtrElement pEl,
                                                    PtrDocument pDocEl,
                                                    boolean processNotLoaded,
                                                    PtrDocument * pDocRef,
                                                    PtrExternalDoc * pExtDoc,
                                                    boolean nextExtDoc );
extern PtrReferredDescr NewReferredElDescr ( PtrDocument pDoc );
extern void DeleteReferredElDescr ( PtrReferredDescr pRefD );
extern void DeleteAllReferences ( PtrElement pEl );
extern void DeleteReference ( PtrReference pRef );
extern void CancelReference ( PtrElement pEl );
extern void CopyReference ( PtrReference pCopyRef,
                            PtrReference pSourceRef,
                            PtrElement * pEl );
extern void TransferReferences ( PtrElement pTarget,
                                 PtrDocument pDoc,
                                 PtrElement pEl,
                                 PtrDocument pSourceDoc );
extern void RegisterExternalRef ( PtrElement pEl,
                                  PtrDocument pDoc,
                                  boolean new );
extern void AddDocOfExternalRef ( PtrElement pEl,
                                  DocumentIdentifier docIdent,
                                  PtrDocument pDoc2 );
extern boolean SetReference ( PtrElement pRefEl,
                              PtrAttribute pRefAttr,
                              PtrElement pTargetEl,
                              PtrDocument pDoc,
                              PtrDocument pTargetDoc,
                              boolean ancestor,
                              boolean withAppEvent );
extern void CopyDescrExtDoc ( PtrElement pEl,
                              PtrChangedReferredEl pChngRef );
extern void RegisterDeletedReferredElem ( PtrElement pEl,
                                          PtrDocument pDoc );
extern void UpdateInclusionElements ( PtrDocument pDoc,
                                      boolean loadExternalDoc,
                                      boolean removeExclusions );

#else /* __STDC__ */

extern PtrElement ReferredElement (/* PtrReference pRef,
                                      DocumentIdentifier * docIdent,
                                      PtrDocument * pDoc */);
extern PtrReference SearchExternalReferenceToElem (/* PtrElement pEl,
                                                      PtrDocument pDocEl,
                                                      boolean processNotLoaded,
                                                      PtrDocument * pDocRef,
                                                      PtrExternalDoc * pExtDoc,
                                                      boolean nextExtDoc */);
extern PtrReferredDescr NewReferredElDescr (/* PtrDocument pDoc */);
extern void DeleteReferredElDescr (/* PtrReferredDescr pRefD */);
extern void DeleteAllReferences (/* PtrElement pEl */);
extern void DeleteReference (/* PtrReference pRef */);
extern void CancelReference (/* PtrElement pEl */);
extern void CopyReference (/* PtrReference pCopyRef,
                              PtrReference pSourceRef,
                              PtrElement * pEl */);
extern void TransferReferences (/* PtrElement pTarget,
                                   PtrDocument pDoc,
                                   PtrElement pEl,
                                   PtrDocument pSourceDoc */);
extern void RegisterExternalRef (/* PtrElement pEl,
                                    PtrDocument pDoc,
                                    boolean new */);
extern void AddDocOfExternalRef (/* PtrElement pEl,
                                    DocumentIdentifier docIdent,
                                    PtrDocument pDoc2 */);
extern boolean SetReference (/* PtrElement pRefEl,
                                PtrAttribute pRefAttr,
                                PtrElement pTargetEl,
                                PtrDocument pDoc,
                                PtrDocument pTargetDoc,
                                boolean ancestor,
                                boolean withAppEvent */);
extern void CopyDescrExtDoc (/* PtrElement pEl,
                                PtrChangedReferredEl pChngRef */);
extern void RegisterDeletedReferredElem (/* PtrElement pEl,
                                            PtrDocument pDoc */);
extern void UpdateInclusionElements (/* PtrDocument pDoc,
                                        boolean loadExternalDoc,
                                        boolean removeExclusions */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
