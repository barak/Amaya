/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void ClearSVGDefs ( void );
extern char *GetElementData ( Document doc,
                              Element el,
                              SSchema sschema,
                              int el_type_num );
extern ThotBool SetElementData ( Document doc,
                                 Element el,
                                 SSchema sschema,
                                 int el_type_num,
                                 char *value );
extern ThotBool GetAncestorCanvasAndObject ( Document doc,
                                             Element *el,
                                             Element *svgAncestor,
                                             Element *svgCanvas );
extern void CreateGraphicElement ( Document doc,
                                   View view,
                                   int entry );
extern void SelectGraphicElement ( Document doc,
                                   View view );
extern void EditGraphicElement ( Document doc,
                                 View view,
                                 int entry );
extern void TransformGraphicElement ( Document doc,
                                      View view,
                                      int entry );
extern void UpdateTransformMatrix ( Document doc,
                                    Element el );
extern void UpdateSVGElement ( Document doc,
                               Element el,
                               int oldw,
                               int oldh,
                               int dx,
                               int dy,
                               int dw,
                               int dh );
extern void UpdatePointsOrPathAttribute ( Document doc,
                                          Element el,
                                          int w,
                                          int h,
                                          ThotBool withUndo );
extern void UpdateShapeElement ( Document doc,
                                 Element el,
                                 char shape,
                                 int x,
                                 int y,
                                 int width,
                                 int height,
                                 int rx,
                                 int ry );
extern void RotateElementInParentSpace ( Document doc,
                                         Element el,
                                         float theta );
extern void FlipElementInParentSpace ( Document doc,
                                       Element el,
                                       ThotBool horiz );
extern void MoveElementInParentSpace ( Document doc,
                                       Element el,
                                       float x,
                                       float y );
extern void GetPositionAndSizeInParentSpace ( Document doc,
                                              Element el,
                                              float *X,
                                              float *Y,
                                              float *width,
                                              float *height );
extern void CreateGroup ( void );
extern void Ungroup ( Document doc,
                      Element el );
extern void FreeSVG ( void );
extern void InitSVG ( void );
extern ThotBool SVGElementTypeInMenu ( NotifyElement *event );
extern void SVGCreated ( NotifyElement * event );
extern ThotBool SVGWillBeDeleted ( NotifyElement * event );
extern void TspanCreated ( NotifyElement * event );
extern void UsePasted ( NotifyElement * event );
extern void AttrXlinkHrefChanged ( NotifyAttribute *event );
extern ThotBool DeleteAttrXlinkHref ( NotifyAttribute *event );
extern void AttrAnimTimeChanged ( NotifyAttribute *event );
extern void Timeline_cross_prule_modified ( NotifyPresentation *event );
extern ThotBool GenerateDesc ( Document doc,
                               View view,
                               Element el );
extern void CreateSVG_Template ( Document document,
                                 View view );
extern void CreateSVG_Svg ( Document document,
                            View view );
extern void CreateSVG_Line ( Document document,
                             View view );
extern void CreateSVG_Rectangle ( Document document,
                                  View view );
extern void CreateSVG_RoundedRectangle ( Document document,
                                         View view );
extern void CreateSVG_Circle ( Document document,
                               View view );
extern void CreateSVG_Ellipse ( Document document,
                                View view );
extern void CreateSVG_Polyline ( Document document,
                                 View view );
extern void CreateSVG_Polygon ( Document document,
                                View view );
extern void CreateSVG_Spline ( Document document,
                               View view );
extern void CreateSVG_Closed ( Document document,
                               View view );
extern void CreateSVG_ForeignObject ( Document document,
                                      View view );
extern void CreateSVG_Text ( Document document,
                             View view );
extern void CreateSVG_Group ( Document document,
                              View view );
extern void CreateSVG_StartArrow ( Document document,
                                   View view );
extern void CreateSVG_EndArrow ( Document document,
                                 View view );
extern void CreateSVG_DoubleArrow ( Document document,
                                    View view );
extern void CreateSVG_Square ( Document document,
                               View view );
extern void CreateSVG_RoundedSquare ( Document document,
                                      View view );
extern void CreateSVG_Diamond ( Document document,
                                View view );
extern void CreateSVG_Trapezium ( Document document,
                                  View view );
extern void CreateSVG_Parallelogram ( Document document,
                                      View view );
extern void CreateSVG_EquilateralTriangle ( Document document,
                                            View view );
extern void CreateSVG_IsoscelesTriangle ( Document document,
                                          View view );
extern void CreateSVG_RectangleTriangle ( Document document,
                                          View view );
extern void TransformSVG_Ungroup ( Document document,
                                   View view );
extern void TransformSVG_FlipVertically ( Document document,
                                          View view );
extern void TransformSVG_FlipHorizontally ( Document document,
                                            View view );
extern void TransformSVG_BringToFront ( Document document,
                                        View view );
extern void TransformSVG_BringForward ( Document document,
                                        View view );
extern void TransformSVG_SendBackward ( Document document,
                                        View view );
extern void TransformSVG_SendToBack ( Document document,
                                      View view );
extern void TransformSVG_AntiClockWise ( Document document,
                                         View view );
extern void TransformSVG_ClockWise ( Document document,
                                     View view );
extern void TransformSVG_AlignLeft ( Document document,
                                     View view );
extern void TransformSVG_AlignCenter ( Document document,
                                       View view );
extern void TransformSVG_AlignRight ( Document document,
                                      View view );
extern void TransformSVG_AlignTop ( Document document,
                                    View view );
extern void TransformSVG_AlignMiddle ( Document document,
                                       View view );
extern void TransformSVG_AlignBottom ( Document document,
                                       View view );
extern void TransformSVG_Rotate ( Document document,
                                  View view );
extern void EditSVG_Select ( Document document,
                             View view );
extern void CreateSVG_Image ( Document document,
                              View view );
extern void TransformSVG_Skew ( Document document,
                                View view );
extern void TransformSVG_Scale ( Document document,
                                 View view );
extern void TransformSVG_Translate ( Document document,
                                     View view );
extern void TransformSVG_DistributeLeft ( Document document,
                                          View view );
extern void TransformSVG_DistributeCenter ( Document document,
                                            View view );
extern void TransformSVG_DistributeRight ( Document document,
                                           View view );
extern void TransformSVG_DistributeTop ( Document document,
                                         View view );
extern void TransformSVG_DistributeMiddle ( Document document,
                                            View view );
extern void TransformSVG_DistributeBottom ( Document document,
                                            View view );
extern void TransformSVG_DistributeHSpacing ( Document document,
                                              View view );
extern void TransformSVG_DistributeVSpacing ( Document document,
                                              View view );
extern void EditSVG_Information ( Document document,
                                  View view );
extern void EditSVG_GenerateDescription ( Document document,
                                          View view );

#else /* __STDC__ */

extern void ClearSVGDefs ( void );
extern char *GetElementData ( Document doc,
                                Element el,
                                SSchema sschema,
                                int el_type_num );
extern ThotBool SetElementData ( Document doc,
                                   Element el,
                                   SSchema sschema,
                                   int el_type_num,
                                   char *value );
extern ThotBool GetAncestorCanvasAndObject ( Document doc,
                                               Element *el,
                                               Element *svgAncestor,
                                               Element *svgCanvas );
extern void CreateGraphicElement ( Document doc,
                                     View view,
                                     int entry );
extern void SelectGraphicElement ( Document doc,
                                     View view );
extern void EditGraphicElement ( Document doc,
                                   View view,
                                   int entry );
extern void TransformGraphicElement ( Document doc,
                                        View view,
                                        int entry );
extern void UpdateTransformMatrix ( Document doc,
                                      Element el );
extern void UpdateSVGElement ( Document doc,
                                 Element el,
                                 int oldw,
                                 int oldh,
                                 int dx,
                                 int dy,
                                 int dw,
                                 int dh );
extern void UpdatePointsOrPathAttribute ( Document doc,
                                            Element el,
                                            int w,
                                            int h,
                                            ThotBool withUndo );
extern void UpdateShapeElement ( Document doc,
                                   Element el,
                                   char shape,
                                   int x,
                                   int y,
                                   int width,
                                   int height,
                                   int rx,
                                   int ry );
extern void RotateElementInParentSpace ( Document doc,
                                           Element el,
                                           float theta );
extern void FlipElementInParentSpace ( Document doc,
                                         Element el,
                                         ThotBool horiz );
extern void MoveElementInParentSpace ( Document doc,
                                         Element el,
                                         float x,
                                         float y );
extern void GetPositionAndSizeInParentSpace ( Document doc,
                                                Element el,
                                                float *X,
                                                float *Y,
                                                float *width,
                                                float *height );
extern void CreateGroup ( void );
extern void Ungroup ( Document doc,
                        Element el );
extern void FreeSVG ( void );
extern void InitSVG ( void );
extern ThotBool SVGElementTypeInMenu ( NotifyElement *event );
extern void SVGCreated ( NotifyElement * event );
extern ThotBool SVGWillBeDeleted ( NotifyElement * event );
extern void TspanCreated ( NotifyElement * event );
extern void UsePasted ( NotifyElement * event );
extern void AttrXlinkHrefChanged ( NotifyAttribute *event );
extern ThotBool DeleteAttrXlinkHref ( NotifyAttribute *event );
extern void AttrAnimTimeChanged ( NotifyAttribute *event );
extern void Timeline_cross_prule_modified ( NotifyPresentation *event );
extern ThotBool GenerateDesc ( Document doc,
                                 View view,
                                 Element el );
extern void CreateSVG_Template ( Document document,
                                   View view );
extern void CreateSVG_Svg ( Document document,
                              View view );
extern void CreateSVG_Line ( Document document,
                               View view );
extern void CreateSVG_Rectangle ( Document document,
                                    View view );
extern void CreateSVG_RoundedRectangle ( Document document,
                                           View view );
extern void CreateSVG_Circle ( Document document,
                                 View view );
extern void CreateSVG_Ellipse ( Document document,
                                  View view );
extern void CreateSVG_Polyline ( Document document,
                                   View view );
extern void CreateSVG_Polygon ( Document document,
                                  View view );
extern void CreateSVG_Spline ( Document document,
                                 View view );
extern void CreateSVG_Closed ( Document document,
                                 View view );
extern void CreateSVG_ForeignObject ( Document document,
                                        View view );
extern void CreateSVG_Text ( Document document,
                               View view );
extern void CreateSVG_Group ( Document document,
                                View view );
extern void CreateSVG_StartArrow ( Document document,
                                     View view );
extern void CreateSVG_EndArrow ( Document document,
                                   View view );
extern void CreateSVG_DoubleArrow ( Document document,
                                      View view );
extern void CreateSVG_Square ( Document document,
                                 View view );
extern void CreateSVG_RoundedSquare ( Document document,
                                        View view );
extern void CreateSVG_Diamond ( Document document,
                                  View view );
extern void CreateSVG_Trapezium ( Document document,
                                    View view );
extern void CreateSVG_Parallelogram ( Document document,
                                        View view );
extern void CreateSVG_EquilateralTriangle ( Document document,
                                              View view );
extern void CreateSVG_IsoscelesTriangle ( Document document,
                                            View view );
extern void CreateSVG_RectangleTriangle ( Document document,
                                            View view );
extern void TransformSVG_Ungroup ( Document document,
                                     View view );
extern void TransformSVG_FlipVertically ( Document document,
                                            View view );
extern void TransformSVG_FlipHorizontally ( Document document,
                                              View view );
extern void TransformSVG_BringToFront ( Document document,
                                          View view );
extern void TransformSVG_BringForward ( Document document,
                                          View view );
extern void TransformSVG_SendBackward ( Document document,
                                          View view );
extern void TransformSVG_SendToBack ( Document document,
                                        View view );
extern void TransformSVG_AntiClockWise ( Document document,
                                           View view );
extern void TransformSVG_ClockWise ( Document document,
                                       View view );
extern void TransformSVG_AlignLeft ( Document document,
                                       View view );
extern void TransformSVG_AlignCenter ( Document document,
                                         View view );
extern void TransformSVG_AlignRight ( Document document,
                                        View view );
extern void TransformSVG_AlignTop ( Document document,
                                      View view );
extern void TransformSVG_AlignMiddle ( Document document,
                                         View view );
extern void TransformSVG_AlignBottom ( Document document,
                                         View view );
extern void TransformSVG_Rotate ( Document document,
                                    View view );
extern void EditSVG_Select ( Document document,
                               View view );
extern void CreateSVG_Image ( Document document,
                                View view );
extern void TransformSVG_Skew ( Document document,
                                  View view );
extern void TransformSVG_Scale ( Document document,
                                   View view );
extern void TransformSVG_Translate ( Document document,
                                       View view );
extern void TransformSVG_DistributeLeft ( Document document,
                                            View view );
extern void TransformSVG_DistributeCenter ( Document document,
                                              View view );
extern void TransformSVG_DistributeRight ( Document document,
                                             View view );
extern void TransformSVG_DistributeTop ( Document document,
                                           View view );
extern void TransformSVG_DistributeMiddle ( Document document,
                                              View view );
extern void TransformSVG_DistributeBottom ( Document document,
                                              View view );
extern void TransformSVG_DistributeHSpacing ( Document document,
                                                View view );
extern void TransformSVG_DistributeVSpacing ( Document document,
                                                View view );
extern void EditSVG_Information ( Document document,
                                    View view );
extern void EditSVG_GenerateDescription ( Document document,
                                            View view );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
