/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void FrameToView ( int frame,
                          int *doc,
                          int *view );
extern void GetViewFromFrame ( int nframe,
                               PtrDocument pDoc,
                               int *viewNum );
extern void RedisplayDocViews ( PtrDocument pDoc );
extern void AbstractImageUpdated ( PtrDocument pDoc );
extern void BuildAbstractBoxes ( PtrElement pEl,
                                 PtrDocument pDoc );
extern void RedisplayNewElement ( Document document,
                                  PtrElement newElement,
                                  PtrElement sibling,
                                  ThotBool first,
                                  ThotBool creation );
extern void TCloseDocument ( PtrDocument pDoc );
extern int NumberOfOpenViews ( PtrDocument pDoc );
extern void FreeView ( PtrDocument pDoc,
                       DocViewNumber view );
extern void CloseDocumentView ( PtrDocument pDoc,
                                int view,
                                ThotBool closeDoc );
extern void CloseAllViewsDoc ( PtrDocument pDoc );
extern void CleanImageView ( int View,
                             PtrDocument pDoc,
                             ThotBool complete );
extern void RedisplayDefaultPresentation ( Document document,
                                           PtrElement pEl,
                                           PRuleType typeRuleP,
                                           FunctionType funcType,
                                           int view );
extern void HideElement ( PtrElement pEl,
                          Document document );
extern void RedisplayNewPRule ( Document document,
                                PtrElement pEl,
                                PtrPRule pRule );
extern void UndisplayAttribute ( PtrElement pEl,
                                 PtrAttribute pAttr,
                                 Document document );
extern void DisplayAttribute ( PtrElement pEl,
                               PtrAttribute pAttr,
                               Document document );
extern void RedisplayCommand ( Document doc );
extern void NewSelection ( Document doc,
                           Element element,
                           Attribute attr,
                           int firstCharacter,
                           int lastCharacter );
extern void NewSelectionExtension ( Document doc,
                                    Element element,
                                    int lastCharacter );
extern void TtaFreeView ( Document document,
                          View view );
extern ThotBool IsSelectionRegistered ( Document doc,
                                        ThotBool *abort );
extern void TtaSetDisplayMode ( Document doc,
                                DisplayMode newDisplayMode );
extern DisplayMode TtaGetDisplayMode ( Document document );
extern void TtaUpdateAccessRightInViews ( Document document,
                                          Element element );

#else /* __STDC__ */

extern void FrameToView ( int frame,
                            int *doc,
                            int *view );
extern void GetViewFromFrame ( int nframe,
                                 PtrDocument pDoc,
                                 int *viewNum );
extern void RedisplayDocViews ( PtrDocument pDoc );
extern void AbstractImageUpdated ( PtrDocument pDoc );
extern void BuildAbstractBoxes ( PtrElement pEl,
                                   PtrDocument pDoc );
extern void RedisplayNewElement ( Document document,
                                    PtrElement newElement,
                                    PtrElement sibling,
                                    ThotBool first,
                                    ThotBool creation );
extern void TCloseDocument ( PtrDocument pDoc );
extern int NumberOfOpenViews ( PtrDocument pDoc );
extern void FreeView ( PtrDocument pDoc,
                         DocViewNumber view );
extern void CloseDocumentView ( PtrDocument pDoc,
                                  int view,
                                  ThotBool closeDoc );
extern void CloseAllViewsDoc ( PtrDocument pDoc );
extern void CleanImageView ( int View,
                               PtrDocument pDoc,
                               ThotBool complete );
extern void RedisplayDefaultPresentation ( Document document,
                                             PtrElement pEl,
                                             PRuleType typeRuleP,
                                             FunctionType funcType,
                                             int view );
extern void HideElement ( PtrElement pEl,
                            Document document );
extern void RedisplayNewPRule ( Document document,
                                  PtrElement pEl,
                                  PtrPRule pRule );
extern void UndisplayAttribute ( PtrElement pEl,
                                   PtrAttribute pAttr,
                                   Document document );
extern void DisplayAttribute ( PtrElement pEl,
                                 PtrAttribute pAttr,
                                 Document document );
extern void RedisplayCommand ( Document doc );
extern void NewSelection ( Document doc,
                             Element element,
                             Attribute attr,
                             int firstCharacter,
                             int lastCharacter );
extern void NewSelectionExtension ( Document doc,
                                      Element element,
                                      int lastCharacter );
extern void TtaFreeView ( Document document,
                            View view );
extern ThotBool IsSelectionRegistered ( Document doc,
                                          ThotBool *abort );
extern void TtaSetDisplayMode ( Document doc,
                                  DisplayMode newDisplayMode );
extern DisplayMode TtaGetDisplayMode ( Document document );
extern void TtaUpdateAccessRightInViews ( Document document,
                                            Element element );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
