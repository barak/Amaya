/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void CreateDocument ( PtrDocument *pDoc,
                             Document *document );
extern void GetSRuleFromName ( int *typeNum,
                               PtrSSchema *pSS,
                               char *typeName,
                               int whichName );
extern void GetAttrRuleFromName ( int *attrNum,
                                  PtrSSchema *pSSch,
                                  PtrElement pElem,
                                  char *attrName,
                                  int whichName );
extern int GetTypeNumIdentity ( int typeNum,
                                PtrSSchema pSS );
extern ThotBool SameSRules ( int typeNum1,
                             PtrSSchema pSS1,
                             int typeNum2,
                             PtrSSchema pSS2 );
extern ThotBool EquivalentSRules ( int typeNum1,
                                   PtrSSchema pSS1,
                                   int typeNum2,
                                   PtrSSchema pSS2,
                                   PtrElement pEl );
extern int IdentRuleOfElem ( int typeNum,
                             PtrSSchema pSS );
extern int ListRuleOfElem ( int typeNum,
                            PtrSSchema pSS );
extern int AggregateRuleOfElem ( int typeNum,
                                 PtrSSchema pSS );
extern ThotBool ExcludedType ( PtrElement pEl,
                               int typeNum,
                               PtrSSchema pSS );
extern ThotBool AllowedIncludedElem ( PtrDocument pDoc,
                                      PtrElement pEl,
                                      int typeNum,
                                      PtrSSchema pSS );
extern void ListOrAggregateRule ( PtrDocument pDoc,
                                  PtrElement pEl,
                                  int *typeNum,
                                  PtrSSchema * pSS );
extern RConstruct GetElementConstruct ( PtrElement pEl,
                                        int *nComp );
extern PtrElement AncestorList ( PtrElement pEl );
extern ThotBool CanChangeNumberOfElem ( PtrElement pEl,
                                        int delta );
extern PtrElement ParentAny ( PtrElement pEl );
extern void SRuleForSibling ( PtrDocument pDoc,
                              PtrElement pEl,
                              ThotBool before,
                              int distance,
                              int *typeNum,
                              PtrSSchema *pSS,
                              ThotBool * list,
                              ThotBool * optional );
extern void ReferredType ( PtrElement pRefEl,
                           PtrAttribute pRefAttr,
                           PtrSSchema * pSS,
                           int *typeNum,
                           PtrDocument pDoc );
extern ThotBool CanCutElement ( PtrElement pEl,
                                PtrDocument pDoc,
                                PtrElement pElCut );
extern ThotBool AllowedSibling ( PtrElement pEl,
                                 PtrDocument pDoc,
                                 int typeNum,
                                 PtrSSchema pSS,
                                 ThotBool before,
                                 ThotBool user,
                                 ThotBool inTree );
extern ThotBool AllowedFirstComponent ( int aggrTypeNum,
                                        PtrSSchema pAggrSS,
                                        int compTypeNum,
                                        PtrSSchema pCompSS );
extern ThotBool AllowedFirstChild ( PtrElement pEl,
                                    PtrDocument pDoc,
                                    int typeNum,
                                    PtrSSchema pSS,
                                    ThotBool user,
                                    ThotBool inTree );
extern void InsertChildFirst ( PtrElement pEl,
                               PtrElement pChild,
                               PtrElement *pLeaf,
                               PtrDocument pDoc );
extern PtrElement CreateDescendant ( int typeNum,
                                     PtrSSchema pSS,
                                     PtrDocument pDoc,
                                     PtrElement *pLeaf,
                                     int descTypeNum,
                                     PtrSSchema pDescSS,
                                     PtrElement pParent );
extern SSchema TtaGetSchemaExtension ( Document document,
                                       char *NomExtension );
extern SRule *ExtensionRule ( PtrSSchema pSS,
                              int typeNum,
                              PtrSSchema pExtSS );
extern ThotBool ValidExtension ( PtrElement pEl,
                                 PtrSSchema * pExt );
extern PtrAttribute GetAttributeOfElement ( PtrElement pEl,
                                            PtrAttribute pAttr );
extern PtrAttribute AttributeValue ( PtrElement pEl,
                                     PtrAttribute pAttr );
extern ThotBool CanAssociateAttr ( PtrElement pEl,
                                   PtrAttribute pAttr,
                                   PtrAttribute pNewAttr,
                                   ThotBool *mandatory );
extern ThotBool CanSplitElement ( PtrElement firstEl,
                                  int firstChar,
                                  ThotBool lineBlock,
                                  PtrElement * pList,
                                  PtrElement * pEl,
                                  PtrElement * pSplitEl );

#else /* __STDC__ */

extern void CreateDocument ( PtrDocument *pDoc,
                               Document *document );
extern void GetSRuleFromName ( int *typeNum,
                                 PtrSSchema *pSS,
                                 char *typeName,
                                 int whichName );
extern void GetAttrRuleFromName ( int *attrNum,
                                    PtrSSchema *pSSch,
                                    PtrElement pElem,
                                    char *attrName,
                                    int whichName );
extern int GetTypeNumIdentity ( int typeNum,
                                  PtrSSchema pSS );
extern ThotBool SameSRules ( int typeNum1,
                               PtrSSchema pSS1,
                               int typeNum2,
                               PtrSSchema pSS2 );
extern ThotBool EquivalentSRules ( int typeNum1,
                                     PtrSSchema pSS1,
                                     int typeNum2,
                                     PtrSSchema pSS2,
                                     PtrElement pEl );
extern int IdentRuleOfElem ( int typeNum,
                               PtrSSchema pSS );
extern int ListRuleOfElem ( int typeNum,
                              PtrSSchema pSS );
extern int AggregateRuleOfElem ( int typeNum,
                                   PtrSSchema pSS );
extern ThotBool ExcludedType ( PtrElement pEl,
                                 int typeNum,
                                 PtrSSchema pSS );
extern ThotBool AllowedIncludedElem ( PtrDocument pDoc,
                                        PtrElement pEl,
                                        int typeNum,
                                        PtrSSchema pSS );
extern void ListOrAggregateRule ( PtrDocument pDoc,
                                    PtrElement pEl,
                                    int *typeNum,
                                    PtrSSchema * pSS );
extern RConstruct GetElementConstruct ( PtrElement pEl,
                                          int *nComp );
extern PtrElement AncestorList ( PtrElement pEl );
extern ThotBool CanChangeNumberOfElem ( PtrElement pEl,
                                          int delta );
extern PtrElement ParentAny ( PtrElement pEl );
extern void SRuleForSibling ( PtrDocument pDoc,
                                PtrElement pEl,
                                ThotBool before,
                                int distance,
                                int *typeNum,
                                PtrSSchema *pSS,
                                ThotBool * list,
                                ThotBool * optional );
extern void ReferredType ( PtrElement pRefEl,
                             PtrAttribute pRefAttr,
                             PtrSSchema * pSS,
                             int *typeNum,
                             PtrDocument pDoc );
extern ThotBool CanCutElement ( PtrElement pEl,
                                  PtrDocument pDoc,
                                  PtrElement pElCut );
extern ThotBool AllowedSibling ( PtrElement pEl,
                                   PtrDocument pDoc,
                                   int typeNum,
                                   PtrSSchema pSS,
                                   ThotBool before,
                                   ThotBool user,
                                   ThotBool inTree );
extern ThotBool AllowedFirstComponent ( int aggrTypeNum,
                                          PtrSSchema pAggrSS,
                                          int compTypeNum,
                                          PtrSSchema pCompSS );
extern ThotBool AllowedFirstChild ( PtrElement pEl,
                                      PtrDocument pDoc,
                                      int typeNum,
                                      PtrSSchema pSS,
                                      ThotBool user,
                                      ThotBool inTree );
extern void InsertChildFirst ( PtrElement pEl,
                                 PtrElement pChild,
                                 PtrElement *pLeaf,
                                 PtrDocument pDoc );
extern PtrElement CreateDescendant ( int typeNum,
                                       PtrSSchema pSS,
                                       PtrDocument pDoc,
                                       PtrElement *pLeaf,
                                       int descTypeNum,
                                       PtrSSchema pDescSS,
                                       PtrElement pParent );
extern SSchema TtaGetSchemaExtension ( Document document,
                                         char *NomExtension );
extern SRule *ExtensionRule ( PtrSSchema pSS,
                                int typeNum,
                                PtrSSchema pExtSS );
extern ThotBool ValidExtension ( PtrElement pEl,
                                   PtrSSchema * pExt );
extern PtrAttribute GetAttributeOfElement ( PtrElement pEl,
                                              PtrAttribute pAttr );
extern PtrAttribute AttributeValue ( PtrElement pEl,
                                       PtrAttribute pAttr );
extern ThotBool CanAssociateAttr ( PtrElement pEl,
                                     PtrAttribute pAttr,
                                     PtrAttribute pNewAttr,
                                     ThotBool *mandatory );
extern ThotBool CanSplitElement ( PtrElement firstEl,
                                    int firstChar,
                                    ThotBool lineBlock,
                                    PtrElement * pList,
                                    PtrElement * pEl,
                                    PtrElement * pSplitEl );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
