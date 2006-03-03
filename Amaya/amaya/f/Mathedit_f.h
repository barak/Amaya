/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void UnFrameMath ( void );
extern void ClearMathFrame ( Document doc );
extern void MathSelectionChanged ( NotifyElement *event );
extern void MathElementCreated ( NotifyElement *event );
extern void AddMathButton ( Document doc,
                            View view );
extern void SwitchIconMath ( Document doc,
                             View view,
                             ThotBool state );
extern void CreateMath ( Document document,
                         View view );
extern void CreateMROOT ( Document document,
                          View view );
extern void CreateMSQRT ( Document document,
                          View view );
extern void CreateMENCLOSE ( Document document,
                             View view );
extern void CreateMFRAC ( Document document,
                          View view );
extern void CreateMSUBSUP ( Document document,
                            View view );
extern void CreateMSUB ( Document document,
                         View view );
extern void CreateMSUP ( Document document,
                         View view );
extern void CreateMUNDEROVER ( Document document,
                               View view );
extern void CreateMUNDER ( Document document,
                           View view );
extern void CreateMOVER ( Document document,
                          View view );
extern void CreateMROW ( Document document,
                         View view );
extern void CreateMMULTISCRIPTS ( Document document,
                                  View view );
extern void CreateMTABLE ( Document document,
                           View view );
extern void CreateMIntegral ( Document doc,
                              View view );
extern void CreateMSum ( Document doc,
                         View view );
extern void CreateMTEXT ( Document document,
                          View view );
extern void CreateMI ( Document document,
                       View view );
extern void CreateMN ( Document document,
                       View view );
extern void CreateMO ( Document document,
                       View view );
extern void CreateMSPACE ( Document document,
                           View view );
extern ThotBool GlobalMathAttrInMenu ( NotifyAttribute *event );
extern void FreeMathML ( void );
extern void InitMathML ( void );
extern void SetAttrParseMe ( Element el,
                             Document doc );
extern void CreateMathEntity ( Document document,
                               View view );
extern void CreateInvisibleTimes ( Document document,
                                   View view );
extern void CreateApplyFunction ( Document document,
                                  View view );
extern void SetMathCharFont ( Document doc,
                              int attribute );
extern void MtextCreated ( NotifyElement *event );
extern void MathStringModified ( NotifyOnTarget *event );
extern void NewMathString ( NotifyElement *event );
extern ThotBool NewMathElement ( NotifyOnValue *event );
extern void MathElementPasted ( NotifyElement *event );
extern ThotBool MathElementWillBeDeleted ( NotifyElement *event );
extern void MathElementDeleted ( NotifyElement *event );
extern ThotBool MathMLElementTypeInMenu ( NotifyElement *event );
extern void FenceModified ( NotifyOnValue *event );
extern void MathAttrOtherCreated ( NotifyAttribute *event );
extern void MathEntityModified ( NotifyAttribute *event );
extern void MathDisplayAttrCreated ( NotifyAttribute *event );
extern void MathDisplayAttrDeleted ( NotifyAttribute *event );
extern void MathDisplaystyleAttrCreated ( NotifyAttribute *event );
extern void MathDisplaystyleAttrDeleted ( NotifyAttribute *event );
extern void MathPresentAttrCreated ( NotifyAttribute *event );
extern ThotBool MathAttrFontsizeDelete ( NotifyAttribute *event );
extern ThotBool MathStyleAttrInMenu ( NotifyAttribute * event );
extern ThotBool MathAttrLspaceDelete ( NotifyAttribute *event );
extern ThotBool MathAttrRspaceDelete ( NotifyAttribute *event );
extern void MathAttrFontfamilyCreated ( NotifyAttribute *event );
extern ThotBool MathAttrFontfamilyDelete ( NotifyAttribute *event );
extern void MathAttrColorCreated ( NotifyAttribute *event );
extern ThotBool MathAttrColorDelete ( NotifyAttribute *event );
extern void MathAttrFormChanged ( NotifyAttribute *event );
extern void MathAttrBackgroundCreated ( NotifyAttribute *event );
extern ThotBool MathAttrBackgroundDelete ( NotifyAttribute *event );
extern void AttrStretchyChanged ( NotifyAttribute *event );
extern void AttrLargeopChanged ( NotifyAttribute *event );
extern void AttrMovablelimitsChanged ( NotifyAttribute *event );
extern void AttrSpacingCreated ( NotifyAttribute *event );
extern ThotBool AttrSpacingDelete ( NotifyAttribute *event );
extern ThotBool AttrLinethicknessDelete ( NotifyAttribute *event );
extern void AttrBevelledChanged ( NotifyAttribute *event );
extern void AttrScriptlevelCreated ( NotifyAttribute *event );
extern ThotBool AttrScriptlevelDelete ( NotifyAttribute *event );
extern void AttrOpenCloseChanged ( NotifyAttribute *event );
extern void FencedSeparatorModified ( NotifyOnValue *event );
extern void AttrSeparatorsChanged ( NotifyAttribute *event );
extern void AttrScriptShiftCreated ( NotifyAttribute *event );
extern ThotBool AttrScriptShiftDelete ( NotifyAttribute *event );
extern void AttrAltModified ( NotifyAttribute *event );
extern void AttrRowAlignCreated ( NotifyAttribute *event );
extern void AttrRowAlignDeleted ( NotifyAttribute *event );
extern void AttrRowAlignMtrCreated ( NotifyAttribute *event );
extern void AttrRowAlignMtrDeleted ( NotifyAttribute *event );
extern void AttrColAlignCreated ( NotifyAttribute *event );
extern void AttrColAlignDeleted ( NotifyAttribute *event );
extern void AttrColAlignMtdCreated ( NotifyAttribute *event );
extern void AttrColAlignMtdDeleted ( NotifyAttribute *event );
extern void AttrRowspacingCreated ( NotifyAttribute *event );
extern void AttrRowspacingDeleted ( NotifyAttribute *event );
extern void AttrColumnspacingCreated ( NotifyAttribute *event );
extern void AttrColumnspacingDeleted ( NotifyAttribute *event );
extern void AttrRowlinesCreated ( NotifyAttribute *event );
extern void AttrRowlinesDeleted ( NotifyAttribute *event );
extern void AttrColumnlinesCreated ( NotifyAttribute *event );
extern void AttrColumnlinesDeleted ( NotifyAttribute *event );
extern void AttrFramespacingCreated ( NotifyAttribute *event );
extern void AttrFramespacingDeleted ( NotifyAttribute *event );
extern void HandleColAndRowAlignAttributes ( Element row,
                                             Document doc );

#else /* __STDC__ */

extern void UnFrameMath ( void );
extern void ClearMathFrame ( Document doc );
extern void MathSelectionChanged ( NotifyElement *event );
extern void MathElementCreated ( NotifyElement *event );
extern void AddMathButton ( Document doc,
                              View view );
extern void SwitchIconMath ( Document doc,
                               View view,
                               ThotBool state );
extern void CreateMath ( Document document,
                           View view );
extern void CreateMROOT ( Document document,
                            View view );
extern void CreateMSQRT ( Document document,
                            View view );
extern void CreateMENCLOSE ( Document document,
                               View view );
extern void CreateMFRAC ( Document document,
                            View view );
extern void CreateMSUBSUP ( Document document,
                              View view );
extern void CreateMSUB ( Document document,
                           View view );
extern void CreateMSUP ( Document document,
                           View view );
extern void CreateMUNDEROVER ( Document document,
                                 View view );
extern void CreateMUNDER ( Document document,
                             View view );
extern void CreateMOVER ( Document document,
                            View view );
extern void CreateMROW ( Document document,
                           View view );
extern void CreateMMULTISCRIPTS ( Document document,
                                    View view );
extern void CreateMTABLE ( Document document,
                             View view );
extern void CreateMIntegral ( Document doc,
                                View view );
extern void CreateMSum ( Document doc,
                           View view );
extern void CreateMTEXT ( Document document,
                            View view );
extern void CreateMI ( Document document,
                         View view );
extern void CreateMN ( Document document,
                         View view );
extern void CreateMO ( Document document,
                         View view );
extern void CreateMSPACE ( Document document,
                             View view );
extern ThotBool GlobalMathAttrInMenu ( NotifyAttribute *event );
extern void FreeMathML ( void );
extern void InitMathML ( void );
extern void SetAttrParseMe ( Element el,
                               Document doc );
extern void CreateMathEntity ( Document document,
                                 View view );
extern void CreateInvisibleTimes ( Document document,
                                     View view );
extern void CreateApplyFunction ( Document document,
                                    View view );
extern void SetMathCharFont ( Document doc,
                                int attribute );
extern void MtextCreated ( NotifyElement *event );
extern void MathStringModified ( NotifyOnTarget *event );
extern void NewMathString ( NotifyElement *event );
extern ThotBool NewMathElement ( NotifyOnValue *event );
extern void MathElementPasted ( NotifyElement *event );
extern ThotBool MathElementWillBeDeleted ( NotifyElement *event );
extern void MathElementDeleted ( NotifyElement *event );
extern ThotBool MathMLElementTypeInMenu ( NotifyElement *event );
extern void FenceModified ( NotifyOnValue *event );
extern void MathAttrOtherCreated ( NotifyAttribute *event );
extern void MathEntityModified ( NotifyAttribute *event );
extern void MathDisplayAttrCreated ( NotifyAttribute *event );
extern void MathDisplayAttrDeleted ( NotifyAttribute *event );
extern void MathDisplaystyleAttrCreated ( NotifyAttribute *event );
extern void MathDisplaystyleAttrDeleted ( NotifyAttribute *event );
extern void MathPresentAttrCreated ( NotifyAttribute *event );
extern ThotBool MathAttrFontsizeDelete ( NotifyAttribute *event );
extern ThotBool MathStyleAttrInMenu ( NotifyAttribute * event );
extern ThotBool MathAttrLspaceDelete ( NotifyAttribute *event );
extern ThotBool MathAttrRspaceDelete ( NotifyAttribute *event );
extern void MathAttrFontfamilyCreated ( NotifyAttribute *event );
extern ThotBool MathAttrFontfamilyDelete ( NotifyAttribute *event );
extern void MathAttrColorCreated ( NotifyAttribute *event );
extern ThotBool MathAttrColorDelete ( NotifyAttribute *event );
extern void MathAttrFormChanged ( NotifyAttribute *event );
extern void MathAttrBackgroundCreated ( NotifyAttribute *event );
extern ThotBool MathAttrBackgroundDelete ( NotifyAttribute *event );
extern void AttrStretchyChanged ( NotifyAttribute *event );
extern void AttrLargeopChanged ( NotifyAttribute *event );
extern void AttrMovablelimitsChanged ( NotifyAttribute *event );
extern void AttrSpacingCreated ( NotifyAttribute *event );
extern ThotBool AttrSpacingDelete ( NotifyAttribute *event );
extern ThotBool AttrLinethicknessDelete ( NotifyAttribute *event );
extern void AttrBevelledChanged ( NotifyAttribute *event );
extern void AttrScriptlevelCreated ( NotifyAttribute *event );
extern ThotBool AttrScriptlevelDelete ( NotifyAttribute *event );
extern void AttrOpenCloseChanged ( NotifyAttribute *event );
extern void FencedSeparatorModified ( NotifyOnValue *event );
extern void AttrSeparatorsChanged ( NotifyAttribute *event );
extern void AttrScriptShiftCreated ( NotifyAttribute *event );
extern ThotBool AttrScriptShiftDelete ( NotifyAttribute *event );
extern void AttrAltModified ( NotifyAttribute *event );
extern void AttrRowAlignCreated ( NotifyAttribute *event );
extern void AttrRowAlignDeleted ( NotifyAttribute *event );
extern void AttrRowAlignMtrCreated ( NotifyAttribute *event );
extern void AttrRowAlignMtrDeleted ( NotifyAttribute *event );
extern void AttrColAlignCreated ( NotifyAttribute *event );
extern void AttrColAlignDeleted ( NotifyAttribute *event );
extern void AttrColAlignMtdCreated ( NotifyAttribute *event );
extern void AttrColAlignMtdDeleted ( NotifyAttribute *event );
extern void AttrRowspacingCreated ( NotifyAttribute *event );
extern void AttrRowspacingDeleted ( NotifyAttribute *event );
extern void AttrColumnspacingCreated ( NotifyAttribute *event );
extern void AttrColumnspacingDeleted ( NotifyAttribute *event );
extern void AttrRowlinesCreated ( NotifyAttribute *event );
extern void AttrRowlinesDeleted ( NotifyAttribute *event );
extern void AttrColumnlinesCreated ( NotifyAttribute *event );
extern void AttrColumnlinesDeleted ( NotifyAttribute *event );
extern void AttrFramespacingCreated ( NotifyAttribute *event );
extern void AttrFramespacingDeleted ( NotifyAttribute *event );
extern void HandleColAndRowAlignAttributes ( Element row,
                                               Document doc );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */