/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void SVGGetDTDName ( char *DTDname,
                            char *elementName );
extern void MapSVGAttribute ( char *attrName,
                              AttributeType *attrType,
                              char* elementName,
                              ThotBool *level,
                              Document doc );
extern void MapSVGAttributeValue ( char* attVal,
                                   const AttributeType * attrType,
                                   int *value );
extern void MapSVGEntity ( char *entityName,
                           char *entityValue,
                           char *script );
extern void SVGEntityCreated ( unsigned char *entityValue,
                               Language lang,
                               char *entityName,
                               Document doc );
extern void ParseCSSequivAttribute ( int attrType,
                                     Attribute attr,
                                     Element el,
                                     Document doc,
                                     ThotBool delete_ );
extern void SetGraphicDepths ( Document doc,
                               Element el );
extern void CopyTRefContent ( Element source,
                              Element el,
                              Document doc );
extern void CopyUseContent ( Element el,
                             Document doc,
                             char *href );
extern void EvaluateTestAttrs ( Element el,
                                Document doc );
extern void SetTextAnchor ( Attribute attr,
                            Element el,
                            Document doc,
                            ThotBool delete_ );
extern void CreateCSSRules ( Element el,
                             Document doc );
extern void SVGElementCreated ( Element el,
                                Document doc );
extern void SVGElementComplete ( ParserData *context,
                                 Element el,
                                 int *error );
extern void UnknownSVGNameSpace ( ParserData *context,
                                  Element *unknownEl,
                                  char* content );
extern void UpdateTransformAttr ( Element el,
                                  Document doc,
                                  char *operation,
                                  float value,
                                  ThotBool firstParam,
                                  ThotBool increment );
extern void TranslateElement ( Element el,
                               Document doc,
                               int delta,
                               TypeUnit unit,
                               ThotBool horiz,
                               ThotBool increment );
extern void UpdatePositionOfPoly ( Element el,
                                   Document doc,
                                   int minX,
                                   int minY,
                                   int maxX,
                                   int maxY );
extern void ParseCoordAttribute ( Attribute attr,
                                  Element el,
                                  Document doc );
extern ThotBool ParseWidthHeightAttribute ( Attribute attr,
                                            Element el,
                                            Document doc,
                                            ThotBool delete_ );
extern void ParseBaselineShiftAttribute ( Attribute attr,
                                          Element el,
                                          Document doc,
                                          ThotBool delete_ );
extern void ParsePointsAttribute ( Attribute attr,
                                   Element el,
                                   Document doc );
extern void ParseTransformAttribute ( Attribute attr,
                                      Element el,
                                      Document doc,
                                      ThotBool delete_ );
extern void *ParseValuesDataAttribute ( Attribute attr,
                                        Element el,
                                        Document doc );
extern void *ParseFromToDataAttribute ( Attribute attrfrom,
                                        Attribute attrto,
                                        Element el,
                                        Document doc );
extern void *ParsePathDataAttribute ( Attribute attr,
                                      Element el,
                                      Document doc,
                                      ThotBool IsDrawn );
extern int ParseIntAttribute ( Attribute attr );
extern float ParseFloatAttribute ( Attribute attr );
extern void SVGAttributeComplete ( Attribute attr,
                                   Element el,
                                   Document doc );

#else /* __STDC__ */

extern void SVGGetDTDName ( char *DTDname,
                              char *elementName );
extern void MapSVGAttribute ( char *attrName,
                                AttributeType *attrType,
                                char* elementName,
                                ThotBool *level,
                                Document doc );
extern void MapSVGAttributeValue ( char* attVal,
                                     const AttributeType * attrType,
                                     int *value );
extern void MapSVGEntity ( char *entityName,
                             char *entityValue,
                             char *script );
extern void SVGEntityCreated ( unsigned char *entityValue,
                                 Language lang,
                                 char *entityName,
                                 Document doc );
extern void ParseCSSequivAttribute ( int attrType,
                                       Attribute attr,
                                       Element el,
                                       Document doc,
                                       ThotBool delete_ );
extern void SetGraphicDepths ( Document doc,
                                 Element el );
extern void CopyTRefContent ( Element source,
                                Element el,
                                Document doc );
extern void CopyUseContent ( Element el,
                               Document doc,
                               char *href );
extern void EvaluateTestAttrs ( Element el,
                                  Document doc );
extern void SetTextAnchor ( Attribute attr,
                              Element el,
                              Document doc,
                              ThotBool delete_ );
extern void CreateCSSRules ( Element el,
                               Document doc );
extern void SVGElementCreated ( Element el,
                                  Document doc );
extern void SVGElementComplete ( ParserData *context,
                                   Element el,
                                   int *error );
extern void UnknownSVGNameSpace ( ParserData *context,
                                    Element *unknownEl,
                                    char* content );
extern void UpdateTransformAttr ( Element el,
                                    Document doc,
                                    char *operation,
                                    float value,
                                    ThotBool firstParam,
                                    ThotBool increment );
extern void TranslateElement ( Element el,
                                 Document doc,
                                 int delta,
                                 TypeUnit unit,
                                 ThotBool horiz,
                                 ThotBool increment );
extern void UpdatePositionOfPoly ( Element el,
                                     Document doc,
                                     int minX,
                                     int minY,
                                     int maxX,
                                     int maxY );
extern void ParseCoordAttribute ( Attribute attr,
                                    Element el,
                                    Document doc );
extern ThotBool ParseWidthHeightAttribute ( Attribute attr,
                                              Element el,
                                              Document doc,
                                              ThotBool delete_ );
extern void ParseBaselineShiftAttribute ( Attribute attr,
                                            Element el,
                                            Document doc,
                                            ThotBool delete_ );
extern void ParsePointsAttribute ( Attribute attr,
                                     Element el,
                                     Document doc );
extern void ParseTransformAttribute ( Attribute attr,
                                        Element el,
                                        Document doc,
                                        ThotBool delete_ );
extern void *ParseValuesDataAttribute ( Attribute attr,
                                          Element el,
                                          Document doc );
extern void *ParseFromToDataAttribute ( Attribute attrfrom,
                                          Attribute attrto,
                                          Element el,
                                          Document doc );
extern void *ParsePathDataAttribute ( Attribute attr,
                                        Element el,
                                        Document doc,
                                        ThotBool IsDrawn );
extern int ParseIntAttribute ( Attribute attr );
extern float ParseFloatAttribute ( Attribute attr );
extern void SVGAttributeComplete ( Attribute attr,
                                     Element el,
                                     Document doc );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
