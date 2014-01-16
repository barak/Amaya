/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void New ( Document document,
                  View view );
extern void SpellCheck ( Document document,
                         View view );
extern void CreateBreak ( Document document,
                          View view );
extern void CreateIsIndex ( Document document,
                            View view );
extern void CreateLinkInHead ( Document document,
                               View view );
extern void CreateBase ( Document document,
                         View view );
extern void CreateMeta ( Document document,
                         View view );
extern void CreateComment ( Document document,
                            View view );
extern void CreateParagraph ( Document document,
                              View view );
extern void CreateHeading1 ( Document document,
                             View view );
extern void CreateHeading2 ( Document document,
                             View view );
extern void CreateHeading3 ( Document document,
                             View view );
extern void CreateHeading4 ( Document document,
                             View view );
extern void CreateHeading5 ( Document document,
                             View view );
extern void CreateHeading6 ( Document document,
                             View view );
extern void CreateList ( Document document,
                         View view );
extern void CreateNumberedList ( Document document,
                                 View view );
extern void ThotCreateMenu ( Document document,
                             View view );
extern void ThotCreateDirectory ( Document document,
                                  View view );
extern void CreateDefinitionList ( Document document,
                                   View view );
extern void CreateDefinitionTerm ( Document document,
                                   View view );
extern void CreateDefinitionDef ( Document document,
                                  View view );
extern void CreateHorizontalRule ( Document document,
                                   View view );
extern void CreateBlockQuote ( Document document,
                               View view );
extern void CreatePreformatted ( Document document,
                                 View view );
extern void CreateAddress ( Document document,
                            View view );
extern void CreateTable ( Document document,
                          View view );
extern void CreateCaption ( Document document,
                            View view );
extern void CreateTHead ( Document document,
                          View view );
extern void CreateTBody ( Document document,
                          View view );
extern void CreateTFoot ( Document document,
                          View view );
extern void CreateRow ( Document document,
                        View view );
extern void CreateDataCell ( Document document,
                             View view );
extern void CreateHeadingCell ( Document document,
                                View view );
extern Element GetEnclosingForm ( Document document,
                                  View view );
extern void CreateForm ( Document doc,
                         View view );
extern void CreateToggle ( Document doc,
                           View view );
extern void CreateRadio ( Document doc,
                          View view );
extern void UpdateAttrSelected ( NotifyAttribute * event );
extern void AttrSelectedDeleted ( NotifyAttribute * event );
extern boolean DeleteAttrSelected ( NotifyAttribute * event );
extern void CreateOption ( Document doc,
                           View view );
extern void CreateTextInput ( Document doc,
                              View view );
extern void CreateTextArea ( Document doc,
                             View view );
extern void CreateCommandLine ( Document doc,
                                View view );
extern void SetAreaCoords ( Document document,
                            Element element,
                            int attrNum );
extern void CreateAreaRect ( Document doc,
                             View view );
extern void CreateAreaCircle ( Document doc,
                               View view );
extern void CreateAreaPoly ( Document doc,
                             View view );
extern void CreateDivision ( Document document,
                             View view );
extern void CreateObject ( Document document,
                           View view );
extern void CreateApplet ( Document document,
                           View view );
extern void CreateParameter ( Document document,
                              View view );
extern void ChangeLink ( Document doc,
                         View view );
extern void CreateOrChangeLink ( Document doc,
                                 View view );
extern void DeleteAnchor ( Document doc,
                           View view );

#else /* __STDC__ */

extern void New (/* Document document,
                    View view */);
extern void SpellCheck (/* Document document,
                           View view */);
extern void CreateBreak (/* Document document,
                            View view */);
extern void CreateIsIndex (/* Document document,
                              View view */);
extern void CreateLinkInHead (/* Document document,
                                 View view */);
extern void CreateBase (/* Document document,
                           View view */);
extern void CreateMeta (/* Document document,
                           View view */);
extern void CreateComment (/* Document document,
                              View view */);
extern void CreateParagraph (/* Document document,
                                View view */);
extern void CreateHeading1 (/* Document document,
                               View view */);
extern void CreateHeading2 (/* Document document,
                               View view */);
extern void CreateHeading3 (/* Document document,
                               View view */);
extern void CreateHeading4 (/* Document document,
                               View view */);
extern void CreateHeading5 (/* Document document,
                               View view */);
extern void CreateHeading6 (/* Document document,
                               View view */);
extern void CreateList (/* Document document,
                           View view */);
extern void CreateNumberedList (/* Document document,
                                   View view */);
extern void ThotCreateMenu (/* Document document,
                               View view */);
extern void ThotCreateDirectory (/* Document document,
                                    View view */);
extern void CreateDefinitionList (/* Document document,
                                     View view */);
extern void CreateDefinitionTerm (/* Document document,
                                     View view */);
extern void CreateDefinitionDef (/* Document document,
                                    View view */);
extern void CreateHorizontalRule (/* Document document,
                                     View view */);
extern void CreateBlockQuote (/* Document document,
                                 View view */);
extern void CreatePreformatted (/* Document document,
                                   View view */);
extern void CreateAddress (/* Document document,
                              View view */);
extern void CreateTable (/* Document document,
                            View view */);
extern void CreateCaption (/* Document document,
                              View view */);
extern void CreateTHead (/* Document document,
                            View view */);
extern void CreateTBody (/* Document document,
                            View view */);
extern void CreateTFoot (/* Document document,
                            View view */);
extern void CreateRow (/* Document document,
                          View view */);
extern void CreateDataCell (/* Document document,
                               View view */);
extern void CreateHeadingCell (/* Document document,
                                  View view */);
extern Element GetEnclosingForm (/* Document document,
                                    View view */);
extern void CreateForm (/* Document doc,
                           View view */);
extern void CreateToggle (/* Document doc,
                             View view */);
extern void CreateRadio (/* Document doc,
                            View view */);
extern void UpdateAttrSelected (/* NotifyAttribute * event */);
extern void AttrSelectedDeleted (/* NotifyAttribute * event */);
extern boolean DeleteAttrSelected (/* NotifyAttribute * event */);
extern void CreateOption (/* Document doc,
                             View view */);
extern void CreateTextInput (/* Document doc,
                                View view */);
extern void CreateTextArea (/* Document doc,
                               View view */);
extern void CreateCommandLine (/* Document doc,
                                  View view */);
extern void SetAreaCoords (/* Document document,
                              Element element,
                              int attrNum */);
extern void CreateAreaRect (/* Document doc,
                               View view */);
extern void CreateAreaCircle (/* Document doc,
                                 View view */);
extern void CreateAreaPoly (/* Document doc,
                               View view */);
extern void CreateDivision (/* Document document,
                               View view */);
extern void CreateObject (/* Document document,
                             View view */);
extern void CreateApplet (/* Document document,
                             View view */);
extern void CreateParameter (/* Document document,
                                View view */);
extern void ChangeLink (/* Document doc,
                           View view */);
extern void CreateOrChangeLink (/* Document doc,
                                   View view */);
extern void DeleteAnchor (/* Document doc,
                             View view */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
