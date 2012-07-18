/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrDocument DocumentOfElement ( PtrElement pEl );
extern void ProtectElement ( PtrElement pEl );
extern PtrElement GetOtherPairedElement ( PtrElement pEl );
extern ThotBool ElementIsHidden ( PtrElement pEl );
extern ThotBool ElementIsReadOnly ( PtrElement pEl );
extern ThotBool CannotInsertNearElement ( PtrElement pEl,
                                          ThotBool beforeElement );
extern PtrElement SearchTypedElementInSubtree ( PtrElement pEl,
                                                int typeNum,
                                                PtrSSchema pSS );
extern PtrElement FwdSearchElemByTypeName ( PtrElement pEl,
                                            char *typeName );
extern PtrElement BackSearchElemByTypeName ( PtrElement pEl,
                                             char *typeName );
extern PtrElement FwdSearchRefOrEmptyElem ( PtrElement pEl,
                                            int Kind );
extern PtrElement BackSearchRefOrEmptyElem ( PtrElement pEl,
                                             int Kind );
extern void ChangeLanguageLeaves ( PtrElement pEl,
                                   Language lang );
extern void InsertElemAfterLastSibling ( PtrElement pOld,
                                         PtrElement pNew );
extern void CopyAttributes ( PtrElement pEl1,
                             PtrElement pEl2,
                             PtrDocument pSourceDoc,
                             PtrDocument pTargetDoc,
                             ThotBool Check,
                             ThotBool copyRef );
extern ThotBool ElemIsWithinSubtree ( PtrElement pEl,
                                      PtrElement pRoot );
extern ThotBool EquivalentType ( PtrElement pEl,
                                 int typeNum,
                                 PtrSSchema pSS );
extern ThotBool ElemIsBefore ( PtrElement pEl1,
                               PtrElement pEl2 );
extern ThotBool ElemIsBeforeWithin ( PtrElement pEl1,
                                     PtrElement pEl2,
                                     PtrElement subTree );
extern ThotBool ElemIsAnAncestor ( PtrElement pEl1,
                                   PtrElement pEl2 );
extern PtrElement CommonAncestor ( PtrElement pEl1,
                                   PtrElement pEl2 );
extern PtrElement FirstLeaf ( PtrElement pEl );
extern PtrElement LastLeaf ( PtrElement pRoot );
extern PtrElement GetTypedAncestor ( PtrElement pEl,
                                     int typeNum,
                                     PtrSSchema pSS );
extern PtrElement FwdSearch2TypesInSubtree ( PtrElement pEl,
                                             ThotBool test,
                                             int typeNum2,
                                             int typeNum1,
                                             PtrSSchema pSS2,
                                             PtrSSchema pSS1 );
extern PtrElement FwdSearchElem2Types ( PtrElement pEl,
                                        int typeNum1,
                                        int typeNum2,
                                        PtrSSchema pSS1,
                                        PtrSSchema pSS2,
                                        PtrElement pAncestor );
extern PtrElement FwdSearchTypedElem ( PtrElement pEl,
                                       int typeNum,
                                       PtrSSchema pSS,
                                       PtrElement pAncestor );
extern PtrElement BackSearchElem2Types ( PtrElement pEl,
                                         int typeNum1,
                                         int typeNum2,
                                         PtrSSchema pSS1,
                                         PtrSSchema pSS2,
                                         PtrElement pAncestor );
extern PtrElement BackSearchTypedElem ( PtrElement pEl,
                                        int typeNum,
                                        PtrSSchema pSS,
                                        PtrElement pAncestor );
extern PtrElement BackSearchVisibleElem ( PtrElement pRoot,
                                          PtrElement pEl,
                                          int view );
extern PtrElement FwdSearch2Attributes ( PtrElement pEl,
                                         int val,
                                         const char *textVal,
                                         int attNum,
                                         int attNum2,
                                         PtrSSchema pSS,
                                         PtrSSchema pSS2 );
extern PtrElement BackSearch2Attributes ( PtrElement pEl,
                                          int val,
                                          const char *textVal,
                                          int attNum,
                                          int attNum2,
                                          PtrSSchema pSS,
                                          PtrSSchema pSS2 );
extern void FwdSkipPageBreak ( PtrElement * pEl );
extern void FwdSkipPageBreakAndExtension ( PtrElement * pEl );
extern void SkipPageBreakBegin ( PtrElement * pEl );
extern void BackSkipPageBreak ( PtrElement * pEl );
extern PtrElement NextElement ( PtrElement pEl );
extern PtrElement PreviousElement ( PtrElement pEl );
extern PtrElement PreviousLeaf ( PtrElement pEl );
extern PtrElement NextLeaf ( PtrElement pEl );
extern void InsertElementBefore ( PtrElement pOld,
                                  PtrElement pNew );
extern void InsertElementAfter ( PtrElement pOld,
                                 PtrElement pNew );
extern void InsertFirstChild ( PtrElement pOld,
                               PtrElement pNew );
extern void InsertElemInChoice ( PtrElement pEl,
                                 PtrElement *pNew,
                                 PtrDocument pDoc,
                                 ThotBool del );
extern void AttachRequiredAttributes ( PtrElement pEl,
                                       SRule *pSRule,
                                       PtrSSchema pSS,
                                       ThotBool withAttr,
                                       PtrDocument pDoc );
extern ThotBool IsConstantConstructor ( PtrElement pEl );
extern PtrElement NewSubtree ( int typeNum,
                               PtrSSchema pSS,
                               PtrDocument pDoc,
                               ThotBool Desc,
                               ThotBool Root,
                               ThotBool withAttr,
                               ThotBool withLabel );
extern void RemoveExcludedElem ( PtrElement * pEl,
                                 PtrDocument pDoc );
extern void RemoveElement ( PtrElement pEl );
extern void RemoveAttribute ( PtrElement pEl,
                              PtrAttribute pAttr );
extern void DeleteAttribute ( PtrElement pEl,
                              PtrAttribute pAttr );
extern void DeleteElement ( PtrElement *pEl,
                            PtrDocument pDoc );
extern void CopyGradient ( PtrElement pSource,
                           PtrElement pEl );
extern PtrElement CopyTree ( PtrElement pSource,
                             PtrDocument pDocSource,
                             PtrSSchema pSSchema,
                             PtrDocument pDocCopy,
                             PtrElement pParent,
                             ThotBool checkAttr,
                             ThotBool shareRef,
                             ThotBool keepAccess,
                             ThotBool deepCopy,
                             ThotBool copyRef );
extern void CopyIncludedElem ( PtrElement pEl,
                               PtrDocument pDoc );
extern PtrElement ReplicateElement ( PtrElement pEl,
                                     PtrDocument pDoc );
extern PtrAttribute GetTypedAttrForElem ( PtrElement pEl,
                                          int attNum,
                                          PtrSSchema pSSattr );
extern PtrAttribute GetTypedAttrAncestor ( PtrElement pEl,
                                           int attNum,
                                           PtrSSchema pSSattr,
                                           PtrElement * pElAttr );
extern void CheckLanguageAttr ( PtrDocument pDoc,
                                PtrElement pEl );
extern Element TtaGetMainRoot ( Document document );
extern Element TtaGetRootElement ( Document document );
extern Document TtaGetDocument ( Element element );
extern Element TtaGetParent ( Element element );
extern ElementType TtaGetElementType ( Element element );
extern Element TtaSearchTypedElement ( ElementType searchedType,
                                       SearchDomain scope,
                                       Element element );
extern Element TtaSearchTypedElementInTree ( ElementType searchedType,
                                             SearchDomain scope,
                                             Element parent,
                                             Element element );
extern int TtaGetElementVolume ( Element element );
extern PtrElement FwdSearch5TypesInSubtree ( PtrElement pEl,
                                             ThotBool test,
                                             int typeNum5,
                                             int typeNum4,
                                             int typeNum3,
                                             int typeNum2,
                                             int typeNum1,
                                             PtrSSchema pSS5,
                                             PtrSSchema pSS4,
                                             PtrSSchema pSS3,
                                             PtrSSchema pSS2,
                                             PtrSSchema pSS1 );
extern PtrElement FwdSearch5Types ( PtrElement pEl,
                                    int typeNum5,
                                    int typeNum4,
                                    int typeNum3,
                                    int typeNum2,
                                    int typeNum1,
                                    PtrSSchema pSS5,
                                    PtrSSchema pSS4,
                                    PtrSSchema pSS3,
                                    PtrSSchema pSS2,
                                    PtrSSchema pSS1 );
extern PtrElement BackSearch5TypesInSubtree ( PtrElement pEl,
                                              int typeNum5,
                                              int typeNum4,
                                              int typeNum3,
                                              int typeNum2,
                                              int typeNum1,
                                              PtrSSchema pSS5,
                                              PtrSSchema pSS4,
                                              PtrSSchema pSS3,
                                              PtrSSchema pSS2,
                                              PtrSSchema pSS1 );
extern PtrElement BackSearch5Types ( PtrElement pEl,
                                     int typeNum5,
                                     int typeNum4,
                                     int typeNum3,
                                     int typeNum2,
                                     int typeNum1,
                                     PtrSSchema pSS5,
                                     PtrSSchema pSS4,
                                     PtrSSchema pSS3,
                                     PtrSSchema pSS2,
                                     PtrSSchema pSS1 );
extern Element TtaSearchElementAmong5Types ( ElementType type1,
                                             ElementType type2,
                                             ElementType type3,
                                             ElementType type4,
                                             ElementType type5,
                                             SearchDomain scope,
                                             Element element );
extern ThotBool TtaIsElementWithSpacePreserve ( Element el );

#else /* __STDC__ */

extern PtrDocument DocumentOfElement ( PtrElement pEl );
extern void ProtectElement ( PtrElement pEl );
extern PtrElement GetOtherPairedElement ( PtrElement pEl );
extern ThotBool ElementIsHidden ( PtrElement pEl );
extern ThotBool ElementIsReadOnly ( PtrElement pEl );
extern ThotBool CannotInsertNearElement ( PtrElement pEl,
                                            ThotBool beforeElement );
extern PtrElement SearchTypedElementInSubtree ( PtrElement pEl,
                                                  int typeNum,
                                                  PtrSSchema pSS );
extern PtrElement FwdSearchElemByTypeName ( PtrElement pEl,
                                              char *typeName );
extern PtrElement BackSearchElemByTypeName ( PtrElement pEl,
                                               char *typeName );
extern PtrElement FwdSearchRefOrEmptyElem ( PtrElement pEl,
                                              int Kind );
extern PtrElement BackSearchRefOrEmptyElem ( PtrElement pEl,
                                               int Kind );
extern void ChangeLanguageLeaves ( PtrElement pEl,
                                     Language lang );
extern void InsertElemAfterLastSibling ( PtrElement pOld,
                                           PtrElement pNew );
extern void CopyAttributes ( PtrElement pEl1,
                               PtrElement pEl2,
                               PtrDocument pSourceDoc,
                               PtrDocument pTargetDoc,
                               ThotBool Check,
                               ThotBool copyRef );
extern ThotBool ElemIsWithinSubtree ( PtrElement pEl,
                                        PtrElement pRoot );
extern ThotBool EquivalentType ( PtrElement pEl,
                                   int typeNum,
                                   PtrSSchema pSS );
extern ThotBool ElemIsBefore ( PtrElement pEl1,
                                 PtrElement pEl2 );
extern ThotBool ElemIsBeforeWithin ( PtrElement pEl1,
                                       PtrElement pEl2,
                                       PtrElement subTree );
extern ThotBool ElemIsAnAncestor ( PtrElement pEl1,
                                     PtrElement pEl2 );
extern PtrElement CommonAncestor ( PtrElement pEl1,
                                     PtrElement pEl2 );
extern PtrElement FirstLeaf ( PtrElement pEl );
extern PtrElement LastLeaf ( PtrElement pRoot );
extern PtrElement GetTypedAncestor ( PtrElement pEl,
                                       int typeNum,
                                       PtrSSchema pSS );
extern PtrElement FwdSearch2TypesInSubtree ( PtrElement pEl,
                                               ThotBool test,
                                               int typeNum2,
                                               int typeNum1,
                                               PtrSSchema pSS2,
                                               PtrSSchema pSS1 );
extern PtrElement FwdSearchElem2Types ( PtrElement pEl,
                                          int typeNum1,
                                          int typeNum2,
                                          PtrSSchema pSS1,
                                          PtrSSchema pSS2,
                                          PtrElement pAncestor );
extern PtrElement FwdSearchTypedElem ( PtrElement pEl,
                                         int typeNum,
                                         PtrSSchema pSS,
                                         PtrElement pAncestor );
extern PtrElement BackSearchElem2Types ( PtrElement pEl,
                                           int typeNum1,
                                           int typeNum2,
                                           PtrSSchema pSS1,
                                           PtrSSchema pSS2,
                                           PtrElement pAncestor );
extern PtrElement BackSearchTypedElem ( PtrElement pEl,
                                          int typeNum,
                                          PtrSSchema pSS,
                                          PtrElement pAncestor );
extern PtrElement BackSearchVisibleElem ( PtrElement pRoot,
                                            PtrElement pEl,
                                            int view );
extern PtrElement FwdSearch2Attributes ( PtrElement pEl,
                                           int val,
                                           const char *textVal,
                                           int attNum,
                                           int attNum2,
                                           PtrSSchema pSS,
                                           PtrSSchema pSS2 );
extern PtrElement BackSearch2Attributes ( PtrElement pEl,
                                            int val,
                                            const char *textVal,
                                            int attNum,
                                            int attNum2,
                                            PtrSSchema pSS,
                                            PtrSSchema pSS2 );
extern void FwdSkipPageBreak ( PtrElement * pEl );
extern void FwdSkipPageBreakAndExtension ( PtrElement * pEl );
extern void SkipPageBreakBegin ( PtrElement * pEl );
extern void BackSkipPageBreak ( PtrElement * pEl );
extern PtrElement NextElement ( PtrElement pEl );
extern PtrElement PreviousElement ( PtrElement pEl );
extern PtrElement PreviousLeaf ( PtrElement pEl );
extern PtrElement NextLeaf ( PtrElement pEl );
extern void InsertElementBefore ( PtrElement pOld,
                                    PtrElement pNew );
extern void InsertElementAfter ( PtrElement pOld,
                                   PtrElement pNew );
extern void InsertFirstChild ( PtrElement pOld,
                                 PtrElement pNew );
extern void InsertElemInChoice ( PtrElement pEl,
                                   PtrElement *pNew,
                                   PtrDocument pDoc,
                                   ThotBool del );
extern void AttachRequiredAttributes ( PtrElement pEl,
                                         SRule *pSRule,
                                         PtrSSchema pSS,
                                         ThotBool withAttr,
                                         PtrDocument pDoc );
extern ThotBool IsConstantConstructor ( PtrElement pEl );
extern PtrElement NewSubtree ( int typeNum,
                                 PtrSSchema pSS,
                                 PtrDocument pDoc,
                                 ThotBool Desc,
                                 ThotBool Root,
                                 ThotBool withAttr,
                                 ThotBool withLabel );
extern void RemoveExcludedElem ( PtrElement * pEl,
                                   PtrDocument pDoc );
extern void RemoveElement ( PtrElement pEl );
extern void RemoveAttribute ( PtrElement pEl,
                                PtrAttribute pAttr );
extern void DeleteAttribute ( PtrElement pEl,
                                PtrAttribute pAttr );
extern void DeleteElement ( PtrElement *pEl,
                              PtrDocument pDoc );
extern void CopyGradient ( PtrElement pSource,
                             PtrElement pEl );
extern PtrElement CopyTree ( PtrElement pSource,
                               PtrDocument pDocSource,
                               PtrSSchema pSSchema,
                               PtrDocument pDocCopy,
                               PtrElement pParent,
                               ThotBool checkAttr,
                               ThotBool shareRef,
                               ThotBool keepAccess,
                               ThotBool deepCopy,
                               ThotBool copyRef );
extern void CopyIncludedElem ( PtrElement pEl,
                                 PtrDocument pDoc );
extern PtrElement ReplicateElement ( PtrElement pEl,
                                       PtrDocument pDoc );
extern PtrAttribute GetTypedAttrForElem ( PtrElement pEl,
                                            int attNum,
                                            PtrSSchema pSSattr );
extern PtrAttribute GetTypedAttrAncestor ( PtrElement pEl,
                                             int attNum,
                                             PtrSSchema pSSattr,
                                             PtrElement * pElAttr );
extern void CheckLanguageAttr ( PtrDocument pDoc,
                                  PtrElement pEl );
extern Element TtaGetMainRoot ( Document document );
extern Element TtaGetRootElement ( Document document );
extern Document TtaGetDocument ( Element element );
extern Element TtaGetParent ( Element element );
extern ElementType TtaGetElementType ( Element element );
extern Element TtaSearchTypedElement ( ElementType searchedType,
                                         SearchDomain scope,
                                         Element element );
extern Element TtaSearchTypedElementInTree ( ElementType searchedType,
                                               SearchDomain scope,
                                               Element parent,
                                               Element element );
extern int TtaGetElementVolume ( Element element );
extern PtrElement FwdSearch5TypesInSubtree ( PtrElement pEl,
                                               ThotBool test,
                                               int typeNum5,
                                               int typeNum4,
                                               int typeNum3,
                                               int typeNum2,
                                               int typeNum1,
                                               PtrSSchema pSS5,
                                               PtrSSchema pSS4,
                                               PtrSSchema pSS3,
                                               PtrSSchema pSS2,
                                               PtrSSchema pSS1 );
extern PtrElement FwdSearch5Types ( PtrElement pEl,
                                      int typeNum5,
                                      int typeNum4,
                                      int typeNum3,
                                      int typeNum2,
                                      int typeNum1,
                                      PtrSSchema pSS5,
                                      PtrSSchema pSS4,
                                      PtrSSchema pSS3,
                                      PtrSSchema pSS2,
                                      PtrSSchema pSS1 );
extern PtrElement BackSearch5TypesInSubtree ( PtrElement pEl,
                                                int typeNum5,
                                                int typeNum4,
                                                int typeNum3,
                                                int typeNum2,
                                                int typeNum1,
                                                PtrSSchema pSS5,
                                                PtrSSchema pSS4,
                                                PtrSSchema pSS3,
                                                PtrSSchema pSS2,
                                                PtrSSchema pSS1 );
extern PtrElement BackSearch5Types ( PtrElement pEl,
                                       int typeNum5,
                                       int typeNum4,
                                       int typeNum3,
                                       int typeNum2,
                                       int typeNum1,
                                       PtrSSchema pSS5,
                                       PtrSSchema pSS4,
                                       PtrSSchema pSS3,
                                       PtrSSchema pSS2,
                                       PtrSSchema pSS1 );
extern Element TtaSearchElementAmong5Types ( ElementType type1,
                                               ElementType type2,
                                               ElementType type3,
                                               ElementType type4,
                                               ElementType type5,
                                               SearchDomain scope,
                                               Element element );
extern ThotBool TtaIsElementWithSpacePreserve ( Element el );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
