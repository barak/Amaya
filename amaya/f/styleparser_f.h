/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern char *SkipBlanksAndComments ( char *ptr );
extern char *ParseNumber ( char *cssRule,
                           PresentationValue *pval );
extern char *ParseCSSUnit ( char *cssRule,
                            PresentationValue *pval );
extern char *ParseClampedUnit ( char *cssRule,
                                PresentationValue *pval );
extern void ParseCSSImageCallback ( Document doc,
                                    Element element,
                                    char *file,
                                    void *extra,
                                    ThotBool isnew );
extern int GetEmValue ( char *data,
                        Element el,
                        Document doc );
extern char *GetCSSBackgroundURL ( char *cssRule );
extern void ParseCSSRule ( Element element,
                           PSchema tsch,
                           PresentationContext ctxt,
                           char *cssRule,
                           CSSInfoPtr css,
                           ThotBool isHTML );
extern void ParseHTMLSpecificStyle ( Element el,
                                     char *cssRule,
                                     Document doc,
                                     int specificity,
                                     ThotBool destroy );
extern int IsImplicitClassName ( char *class_,
                                 Document doc );
extern void HTMLSetBackgroundColor ( Document doc,
                                     Element el,
                                     int specificity,
                                     char *color );
extern void HTMLSetForegroundColor ( Document doc,
                                     Element el,
                                     int specificity,
                                     char *color );
extern void HTMLResetBackgroundColor ( Document doc,
                                       Element el );
extern void HTMLResetBackgroundImage ( Document doc,
                                       Element el );
extern void HTMLResetForegroundColor ( Document doc,
                                       Element el );
extern void HTMLSetAlinkColor ( Document doc,
                                Element el,
                                char *color );
extern void HTMLSetAactiveColor ( Document doc,
                                  Element el,
                                  char *color );
extern void HTMLSetAvisitedColor ( Document doc,
                                   Element el,
                                   char *color );
extern void HTMLResetAlinkColor ( Document doc,
                                  Element el );
extern void HTMLResetAactiveColor ( Document doc,
                                    Element el );
extern void HTMLResetAvisitedColor ( Document doc,
                                     Element el );
extern void ApplyCSSRules ( Element el,
                            char *cssRule,
                            Document doc,
                            ThotBool destroy );
extern char ReadCSSRules ( Document docRef,
                           CSSInfoPtr css,
                           char *buffer,
                           char *url,
                           int numberOfLinesRead,
                           ThotBool withUndo,
                           Element link );

#else /* __STDC__ */

extern char *SkipBlanksAndComments ( char *ptr );
extern char *ParseNumber ( char *cssRule,
                             PresentationValue *pval );
extern char *ParseCSSUnit ( char *cssRule,
                              PresentationValue *pval );
extern char *ParseClampedUnit ( char *cssRule,
                                  PresentationValue *pval );
extern void ParseCSSImageCallback ( Document doc,
                                      Element element,
                                      char *file,
                                      void *extra,
                                      ThotBool isnew );
extern int GetEmValue ( char *data,
                          Element el,
                          Document doc );
extern char *GetCSSBackgroundURL ( char *cssRule );
extern void ParseCSSRule ( Element element,
                             PSchema tsch,
                             PresentationContext ctxt,
                             char *cssRule,
                             CSSInfoPtr css,
                             ThotBool isHTML );
extern void ParseHTMLSpecificStyle ( Element el,
                                       char *cssRule,
                                       Document doc,
                                       int specificity,
                                       ThotBool destroy );
extern int IsImplicitClassName ( char *class_,
                                   Document doc );
extern void HTMLSetBackgroundColor ( Document doc,
                                       Element el,
                                       int specificity,
                                       char *color );
extern void HTMLSetForegroundColor ( Document doc,
                                       Element el,
                                       int specificity,
                                       char *color );
extern void HTMLResetBackgroundColor ( Document doc,
                                         Element el );
extern void HTMLResetBackgroundImage ( Document doc,
                                         Element el );
extern void HTMLResetForegroundColor ( Document doc,
                                         Element el );
extern void HTMLSetAlinkColor ( Document doc,
                                  Element el,
                                  char *color );
extern void HTMLSetAactiveColor ( Document doc,
                                    Element el,
                                    char *color );
extern void HTMLSetAvisitedColor ( Document doc,
                                     Element el,
                                     char *color );
extern void HTMLResetAlinkColor ( Document doc,
                                    Element el );
extern void HTMLResetAactiveColor ( Document doc,
                                      Element el );
extern void HTMLResetAvisitedColor ( Document doc,
                                       Element el );
extern void ApplyCSSRules ( Element el,
                              char *cssRule,
                              Document doc,
                              ThotBool destroy );
extern char ReadCSSRules ( Document docRef,
                             CSSInfoPtr css,
                             char *buffer,
                             char *url,
                             int numberOfLinesRead,
                             ThotBool withUndo,
                             Element link );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */