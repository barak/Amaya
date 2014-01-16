/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void SwitchJavaScript ( Document document,
                               View view );
extern void ExecuteACommand ( Document document,
                              View view );
extern void InsertScript ( Document document,
                           View view );
extern void RemoveDeprecatedElements ( Document doc,
                                       View view );
extern void AddExternal ( Document document,
                          View view );
extern void ExecuteExternal ( Document document,
                              View view );
extern void SingleNewXHTML ( Document doc,
                             View view );
extern void DoNewXHTML ( Document doc,
                         View view );
extern void NewXHTML ( Document doc,
                       View view );
extern void NewMathML ( Document doc,
                        View view );
extern void NewSVG ( Document doc,
                     View view );
extern void NewCss ( Document doc,
                     View view );
extern void CreateDoctype ( Document doc,
                            Element doctype,
                            int profile,
                            int extraProfile,
                            ThotBool useMathML,
                            ThotBool useSVG,
                            ThotBool newDoc );
extern void InitializeNewDoc ( char *url,
                               int docType,
                               Document doc,
                               int profile,
                               int extraProfile,
                               ThotBool isXML );
extern void NotFoundDoc ( char *url,
                          Document doc );
extern void RemoveDoctype ( Document doc,
                            View view );
extern void AddDoctype ( Document doc,
                         View view );
extern void CreateDoctypeXhtml11 ( Document doc,
                                   View view );
extern void CreateDoctypeXhtmlTransitional ( Document doc,
                                             View view );
extern void CreateDoctypeXhtmlStrict ( Document doc,
                                       View view );
extern void CreateDoctypeXhtmlBasic ( Document doc,
                                      View view );
extern void CreateDoctypeXhtmlRDFa ( Document doc,
                                     View view );
extern void CreateDoctypeHtmlTransitional ( Document doc,
                                            View view );
extern void CreateDoctypeHtmlStrict ( Document doc,
                                      View view );
extern void CreateDoctypeMathML ( Document doc,
                                  View view );
extern void CreateDoctypeSVG ( Document doc,
                               View view );
extern void PasteBuffer ( Document doc,
                          View view );
extern void SpellCheck ( Document doc,
                         View view );
extern void CreateBreak ( Document doc,
                          View view );
extern Element InsertWithinHead ( Document doc,
                                  View view,
                                  int elementT );
extern void CreateBase ( Document doc,
                         View view );
extern void CreateMeta ( Document doc,
                         View view );
extern void CreateLinkInHead ( Document doc,
                               View view );
extern void CreateStyle ( Document doc,
                          View view );
extern void CreateComment ( Document doc,
                            View view );
extern void CreateDate ( Document doc,
                         View view );
extern void CreateScript ( Document doc,
                           View view,
                           ThotBool ExternalFile );
extern ThotBool HTMLelementAllowed ( Document doc );
extern ThotBool CreateHTMLelement ( int typeNum,
                                    Document doc );
extern void CreateParagraph ( Document doc,
                              View view );
extern void CreateHeading1 ( Document doc,
                             View view );
extern void CreateHeading2 ( Document doc,
                             View view );
extern void CreateHeading3 ( Document doc,
                             View view );
extern void CreateHeading4 ( Document doc,
                             View view );
extern void CreateHeading5 ( Document doc,
                             View view );
extern void CreateHeading6 ( Document doc,
                             View view );
extern void CreateMap ( Document doc,
                        View view );
extern void CreateList ( Document doc,
                         View view );
extern void CreateNumberedList ( Document doc,
                                 View view );
extern void CreateDefinitionList ( Document doc,
                                   View view );
extern void CreateDefinitionTerm ( Document doc,
                                   View view );
extern void CreateDefinitionDef ( Document doc,
                                  View view );
extern void CreateHorizontalRule ( Document doc,
                                   View view );
extern void CreateBlockQuote ( Document doc,
                               View view );
extern void CreatePreformatted ( Document doc,
                                 View view );
extern void CreateRuby ( Document doc,
                         View view );
extern void CreateAddress ( Document doc,
                            View view );
extern void DoTableCreation ( Document doc );
extern void CreateTable ( Document doc,
                          View view );
extern void SingleCreateTable ( Document doc,
                                View view );
extern void DoCreateTable ( Document doc,
                            View view );
extern void CreateCaption ( Document doc,
                            View view );
extern void ChangeToDataCell ( Document doc,
                               View view );
extern void ChangeToHeadingCell ( Document doc,
                                  View view );
extern void CellVertExtend ( Document doc,
                             View view );
extern void CellHorizExtend ( Document doc,
                              View view );
extern ThotBool CanMergeSelectedCells ( Document doc );
extern void MergeSelectedCells ( Document doc,
                                 View view );
extern ThotBool CanVShrinkCell ( Document doc );
extern void CellVertShrink ( Document doc,
                             View view );
extern ThotBool CanHShrinkCell ( Document doc );
extern void CellHorizShrink ( Document doc,
                              View view );
extern void SelectRow ( Document doc,
                        View view );
extern void CreateRowBefore ( Document doc,
                              View view );
extern void CreateRowAfter ( Document doc,
                             View view );
extern void SelectColumn ( Document doc,
                           View view );
extern void CreateColumnBefore ( Document doc,
                                 View view );
extern void CreateColumnAfter ( Document doc,
                                View view );
extern void PasteBefore ( Document doc,
                          View view );
extern void PasteAfter ( Document doc,
                         View view );
extern void CreateTHead ( Document doc,
                          View view );
extern void CreateTBody ( Document doc,
                          View view );
extern void CreateTFoot ( Document doc,
                          View view );
extern Element GetEnclosingForm ( Document doc,
                                  View view );
extern void CreateForm ( Document doc,
                         View view );
extern void CreateFieldset ( Document doc,
                             View view );
extern void CreateToggle ( Document doc,
                           View view );
extern void CreateRadio ( Document doc,
                          View view );
extern void UpdateAttrSelected ( NotifyAttribute * event );
extern void AttrSelectedDeleted ( NotifyAttribute * event );
extern ThotBool DeleteAttrSelected ( NotifyAttribute * event );
extern void CreateOption ( Document doc,
                           View view );
extern void CreateOptGroup ( Document doc,
                             View view );
extern void CreateTextInput ( Document doc,
                              View view );
extern void CreatePasswordInput ( Document doc,
                                  View view );
extern void CreateTextArea ( Document doc,
                             View view );
extern void CreateImageInput ( Document doc,
                               View view );
extern void CreateFileInput ( Document doc,
                              View view );
extern void CreateHiddenInput ( Document doc,
                                View view );
extern void CreateLabel ( Document doc,
                          View view );
extern void CreatePushButton ( Document doc,
                               View view );
extern void CreateSubmit ( Document doc,
                           View view );
extern void CreateReset ( Document doc,
                          View view );
extern void CreateDivision ( Document doc,
                             View view );
extern void CreateNOSCRIPT ( Document doc,
                             View view );
extern void CreateIFrame ( Document doc,
                           View view );
extern void CreateParameter ( Document doc,
                              View view );
extern void CreateOrChangeLink ( Document doc,
                                 View view );
extern void DoDeleteAnchor ( Document doc,
                             View view,
                             ThotBool noCallback );
extern void DeleteAnchor ( Document doc,
                           View view );
extern void FlushCache ( Document doc,
                         View view );
extern void ConfigAmaya ( Document doc,
                          View view );
extern void SaveOptions ( Document doc,
                          View view );
extern void AnnotateDocument ( Document doc,
                               View view );
extern void AnnotateSelection ( Document doc,
                                View view );
extern void LoadAnnotations ( Document doc,
                              View view );
extern void PostAnnotation ( Document doc,
                             View view );
extern void DeleteAnnotation ( Document doc,
                               View view );
extern void FilterAnnot ( Document doc,
                          View view );
extern void MoveAnnotationXPtr ( Document doc,
                                 View view );
extern void MoveAnnotationSel ( Document doc,
                                View view );
extern void ReplyToAnnotation ( Document doc,
                                View view );
extern void CustomQuery ( Document doc,
                          View view );
extern void BookmarkFile ( Document doc,
                           View view );
extern void EditTopics ( Document doc,
                         View view );
extern void AddSeparator ( Document doc,
                           View view );
extern void ViewBookmarks ( Document doc,
                            View view );
extern void MoveItem ( Document doc,
                       View view );
extern void LockDocument ( Document doc,
                           View view );
extern void UnlockDocument ( Document doc,
                             View view );
extern void PropDocument ( Document doc,
                           View view );
extern void CopyLockInformation ( Document doc,
                                  View view );
extern void LockIndicator ( Document doc,
                            View view );
extern void SelectAll ( Document doc,
                        View view );

#else /* __STDC__ */

extern void SwitchJavaScript ( Document document,
                                 View view );
extern void ExecuteACommand ( Document document,
                                View view );
extern void InsertScript ( Document document,
                             View view );
extern void RemoveDeprecatedElements ( Document doc,
                                         View view );
extern void AddExternal ( Document document,
                            View view );
extern void ExecuteExternal ( Document document,
                                View view );
extern void SingleNewXHTML ( Document doc,
                               View view );
extern void DoNewXHTML ( Document doc,
                           View view );
extern void NewXHTML ( Document doc,
                         View view );
extern void NewMathML ( Document doc,
                          View view );
extern void NewSVG ( Document doc,
                       View view );
extern void NewCss ( Document doc,
                       View view );
extern void CreateDoctype ( Document doc,
                              Element doctype,
                              int profile,
                              int extraProfile,
                              ThotBool useMathML,
                              ThotBool useSVG,
                              ThotBool newDoc );
extern void InitializeNewDoc ( char *url,
                                 int docType,
                                 Document doc,
                                 int profile,
                                 int extraProfile,
                                 ThotBool isXML );
extern void NotFoundDoc ( char *url,
                            Document doc );
extern void RemoveDoctype ( Document doc,
                              View view );
extern void AddDoctype ( Document doc,
                           View view );
extern void CreateDoctypeXhtml11 ( Document doc,
                                     View view );
extern void CreateDoctypeXhtmlTransitional ( Document doc,
                                               View view );
extern void CreateDoctypeXhtmlStrict ( Document doc,
                                         View view );
extern void CreateDoctypeXhtmlBasic ( Document doc,
                                        View view );
extern void CreateDoctypeXhtmlRDFa ( Document doc,
                                       View view );
extern void CreateDoctypeHtmlTransitional ( Document doc,
                                              View view );
extern void CreateDoctypeHtmlStrict ( Document doc,
                                        View view );
extern void CreateDoctypeMathML ( Document doc,
                                    View view );
extern void CreateDoctypeSVG ( Document doc,
                                 View view );
extern void PasteBuffer ( Document doc,
                            View view );
extern void SpellCheck ( Document doc,
                           View view );
extern void CreateBreak ( Document doc,
                            View view );
extern Element InsertWithinHead ( Document doc,
                                    View view,
                                    int elementT );
extern void CreateBase ( Document doc,
                           View view );
extern void CreateMeta ( Document doc,
                           View view );
extern void CreateLinkInHead ( Document doc,
                                 View view );
extern void CreateStyle ( Document doc,
                            View view );
extern void CreateComment ( Document doc,
                              View view );
extern void CreateDate ( Document doc,
                           View view );
extern void CreateScript ( Document doc,
                             View view,
                             ThotBool ExternalFile );
extern ThotBool HTMLelementAllowed ( Document doc );
extern ThotBool CreateHTMLelement ( int typeNum,
                                      Document doc );
extern void CreateParagraph ( Document doc,
                                View view );
extern void CreateHeading1 ( Document doc,
                               View view );
extern void CreateHeading2 ( Document doc,
                               View view );
extern void CreateHeading3 ( Document doc,
                               View view );
extern void CreateHeading4 ( Document doc,
                               View view );
extern void CreateHeading5 ( Document doc,
                               View view );
extern void CreateHeading6 ( Document doc,
                               View view );
extern void CreateMap ( Document doc,
                          View view );
extern void CreateList ( Document doc,
                           View view );
extern void CreateNumberedList ( Document doc,
                                   View view );
extern void CreateDefinitionList ( Document doc,
                                     View view );
extern void CreateDefinitionTerm ( Document doc,
                                     View view );
extern void CreateDefinitionDef ( Document doc,
                                    View view );
extern void CreateHorizontalRule ( Document doc,
                                     View view );
extern void CreateBlockQuote ( Document doc,
                                 View view );
extern void CreatePreformatted ( Document doc,
                                   View view );
extern void CreateRuby ( Document doc,
                           View view );
extern void CreateAddress ( Document doc,
                              View view );
extern void DoTableCreation ( Document doc );
extern void CreateTable ( Document doc,
                            View view );
extern void SingleCreateTable ( Document doc,
                                  View view );
extern void DoCreateTable ( Document doc,
                              View view );
extern void CreateCaption ( Document doc,
                              View view );
extern void ChangeToDataCell ( Document doc,
                                 View view );
extern void ChangeToHeadingCell ( Document doc,
                                    View view );
extern void CellVertExtend ( Document doc,
                               View view );
extern void CellHorizExtend ( Document doc,
                                View view );
extern ThotBool CanMergeSelectedCells ( Document doc );
extern void MergeSelectedCells ( Document doc,
                                   View view );
extern ThotBool CanVShrinkCell ( Document doc );
extern void CellVertShrink ( Document doc,
                               View view );
extern ThotBool CanHShrinkCell ( Document doc );
extern void CellHorizShrink ( Document doc,
                                View view );
extern void SelectRow ( Document doc,
                          View view );
extern void CreateRowBefore ( Document doc,
                                View view );
extern void CreateRowAfter ( Document doc,
                               View view );
extern void SelectColumn ( Document doc,
                             View view );
extern void CreateColumnBefore ( Document doc,
                                   View view );
extern void CreateColumnAfter ( Document doc,
                                  View view );
extern void PasteBefore ( Document doc,
                            View view );
extern void PasteAfter ( Document doc,
                           View view );
extern void CreateTHead ( Document doc,
                            View view );
extern void CreateTBody ( Document doc,
                            View view );
extern void CreateTFoot ( Document doc,
                            View view );
extern Element GetEnclosingForm ( Document doc,
                                    View view );
extern void CreateForm ( Document doc,
                           View view );
extern void CreateFieldset ( Document doc,
                               View view );
extern void CreateToggle ( Document doc,
                             View view );
extern void CreateRadio ( Document doc,
                            View view );
extern void UpdateAttrSelected ( NotifyAttribute * event );
extern void AttrSelectedDeleted ( NotifyAttribute * event );
extern ThotBool DeleteAttrSelected ( NotifyAttribute * event );
extern void CreateOption ( Document doc,
                             View view );
extern void CreateOptGroup ( Document doc,
                               View view );
extern void CreateTextInput ( Document doc,
                                View view );
extern void CreatePasswordInput ( Document doc,
                                    View view );
extern void CreateTextArea ( Document doc,
                               View view );
extern void CreateImageInput ( Document doc,
                                 View view );
extern void CreateFileInput ( Document doc,
                                View view );
extern void CreateHiddenInput ( Document doc,
                                  View view );
extern void CreateLabel ( Document doc,
                            View view );
extern void CreatePushButton ( Document doc,
                                 View view );
extern void CreateSubmit ( Document doc,
                             View view );
extern void CreateReset ( Document doc,
                            View view );
extern void CreateDivision ( Document doc,
                               View view );
extern void CreateNOSCRIPT ( Document doc,
                               View view );
extern void CreateIFrame ( Document doc,
                             View view );
extern void CreateParameter ( Document doc,
                                View view );
extern void CreateOrChangeLink ( Document doc,
                                   View view );
extern void DoDeleteAnchor ( Document doc,
                               View view,
                               ThotBool noCallback );
extern void DeleteAnchor ( Document doc,
                             View view );
extern void FlushCache ( Document doc,
                           View view );
extern void ConfigAmaya ( Document doc,
                            View view );
extern void SaveOptions ( Document doc,
                            View view );
extern void AnnotateDocument ( Document doc,
                                 View view );
extern void AnnotateSelection ( Document doc,
                                  View view );
extern void LoadAnnotations ( Document doc,
                                View view );
extern void PostAnnotation ( Document doc,
                               View view );
extern void DeleteAnnotation ( Document doc,
                                 View view );
extern void FilterAnnot ( Document doc,
                            View view );
extern void MoveAnnotationXPtr ( Document doc,
                                   View view );
extern void MoveAnnotationSel ( Document doc,
                                  View view );
extern void ReplyToAnnotation ( Document doc,
                                  View view );
extern void CustomQuery ( Document doc,
                            View view );
extern void BookmarkFile ( Document doc,
                             View view );
extern void EditTopics ( Document doc,
                           View view );
extern void AddSeparator ( Document doc,
                             View view );
extern void ViewBookmarks ( Document doc,
                              View view );
extern void MoveItem ( Document doc,
                         View view );
extern void LockDocument ( Document doc,
                             View view );
extern void UnlockDocument ( Document doc,
                               View view );
extern void PropDocument ( Document doc,
                             View view );
extern void CopyLockInformation ( Document doc,
                                    View view );
extern void LockIndicator ( Document doc,
                              View view );
extern void SelectAll ( Document doc,
                          View view );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
