/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern SpecificContext GetSpecificContext ( Document doc );
extern void FreeSpecificContext ( SpecificContext ctxt );
extern int SpecificCleanPresentation ( PresentationTarget t,
                                       PresentationContext c,
                                       PresentationValue v );
extern int SpecificUpdatePresentation ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue v );
extern int SpecificSetForegroundColor ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue v );
extern int SpecificGetForegroundColor ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue *v );
extern int SpecificSetBackgroundColor ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue v );
extern int SpecificGetBackgroundColor ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue *v );
extern int SpecificSetFontSize ( PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue v );
extern int SpecificGetFontSize ( PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue *v );
extern int SpecificSetFontStyle ( PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue v );
extern int SpecificGetFontStyle ( PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue *v );
extern int SpecificSetAlignment ( PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue v );
extern int SpecificGetAlignment ( PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue *v );
extern int SpecificSetIndent ( PresentationTarget t,
                               PresentationContext c,
                               PresentationValue v );
extern int SpecificGetIndent ( PresentationTarget t,
                               PresentationContext c,
                               PresentationValue *v );
extern int SpecificSetJustification ( PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue v );
extern int SpecificGetJustification ( PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue *v );
extern int SpecificSetHyphenation ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue v );
extern int SpecificGetHyphenation ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue *v );
extern int SpecificSetTextUnderlining ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue v );
extern int SpecificGetTextUnderlining ( PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue *v );
extern int SpecificSetFillPattern ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue v );
extern int SpecificGetFillPattern ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue *v );
extern int SpecificSetFontFamily ( PresentationTarget t,
                                   PresentationContext c,
                                   PresentationValue v );
extern int SpecificGetFontFamily ( PresentationTarget t,
                                   PresentationContext c,
                                   PresentationValue *v );
extern int SpecificSetLineSpacing ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue v );
extern int SpecificGetLineSpacing ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue *v );
extern int SpecificSetHeight ( PresentationTarget t,
                               PresentationContext c,
                               PresentationValue v );
extern int SpecificGetHeight ( PresentationTarget t,
                               PresentationContext c,
                               PresentationValue *v );
extern int SpecificSetWidth ( PresentationTarget t,
                              PresentationContext c,
                              PresentationValue v );
extern int SpecificGetWidth ( PresentationTarget t,
                              PresentationContext c,
                              PresentationValue *v );
extern int SpecificSetVPos ( PresentationTarget t,
                             PresentationContext c,
                             PresentationValue v );
extern int SpecificGetVPos ( PresentationTarget t,
                             PresentationContext c,
                             PresentationValue *v );
extern int SpecificSetHPos ( PresentationTarget t,
                             PresentationContext c,
                             PresentationValue v );
extern int SpecificGetHPos ( PresentationTarget t,
                             PresentationContext c,
                             PresentationValue *v );
extern int SpecificSetInLine ( PresentationTarget t,
                               PresentationContext c,
                               PresentationValue v );
extern int SpecificGetInLine ( PresentationTarget t,
                               PresentationContext c,
                               PresentationValue *v );
extern int SpecificSetShowBox ( PresentationTarget t,
                                PresentationContext c,
                                PresentationValue v );
extern int SpecificGetShowBox ( PresentationTarget t,
                                PresentationContext c,
                                PresentationValue *v );
extern int SpecificSetPictureMode ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue v );
extern int SpecificGetPictureMode ( PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue *v );
extern int SpecificSetBgImage ( PresentationTarget t,
                                PresentationContext c,
                                PresentationValue v );
extern int SpecificGetBgImage ( PresentationTarget t,
                                PresentationContext c,
                                PresentationValue * v );
extern void ApplyAllSpecificContext ( Document doc,
                                      SpecificTarget target,
                                      SpecificContextApplyHandler handler,
                                      void *param );
extern void ApplyAllSpecificSettings ( SpecificTarget target,
                                       SpecificContext ctxt,
                                       SpecificSettingsApplyHandler handler,
                                       void *param );

#else /* __STDC__ */

extern SpecificContext GetSpecificContext (/* Document doc */);
extern void FreeSpecificContext (/* SpecificContext ctxt */);
extern int SpecificCleanPresentation (/* PresentationTarget t,
                                         PresentationContext c,
                                         PresentationValue v */);
extern int SpecificUpdatePresentation (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue v */);
extern int SpecificSetForegroundColor (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue v */);
extern int SpecificGetForegroundColor (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue *v */);
extern int SpecificSetBackgroundColor (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue v */);
extern int SpecificGetBackgroundColor (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue *v */);
extern int SpecificSetFontSize (/* PresentationTarget t,
                                   PresentationContext c,
                                   PresentationValue v */);
extern int SpecificGetFontSize (/* PresentationTarget t,
                                   PresentationContext c,
                                   PresentationValue *v */);
extern int SpecificSetFontStyle (/* PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue v */);
extern int SpecificGetFontStyle (/* PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue *v */);
extern int SpecificSetAlignment (/* PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue v */);
extern int SpecificGetAlignment (/* PresentationTarget t,
                                    PresentationContext c,
                                    PresentationValue *v */);
extern int SpecificSetIndent (/* PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue v */);
extern int SpecificGetIndent (/* PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue *v */);
extern int SpecificSetJustification (/* PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue v */);
extern int SpecificGetJustification (/* PresentationTarget t,
                                        PresentationContext c,
                                        PresentationValue *v */);
extern int SpecificSetHyphenation (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue v */);
extern int SpecificGetHyphenation (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue *v */);
extern int SpecificSetTextUnderlining (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue v */);
extern int SpecificGetTextUnderlining (/* PresentationTarget t,
                                          PresentationContext c,
                                          PresentationValue *v */);
extern int SpecificSetFillPattern (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue v */);
extern int SpecificGetFillPattern (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue *v */);
extern int SpecificSetFontFamily (/* PresentationTarget t,
                                     PresentationContext c,
                                     PresentationValue v */);
extern int SpecificGetFontFamily (/* PresentationTarget t,
                                     PresentationContext c,
                                     PresentationValue *v */);
extern int SpecificSetLineSpacing (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue v */);
extern int SpecificGetLineSpacing (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue *v */);
extern int SpecificSetHeight (/* PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue v */);
extern int SpecificGetHeight (/* PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue *v */);
extern int SpecificSetWidth (/* PresentationTarget t,
                                PresentationContext c,
                                PresentationValue v */);
extern int SpecificGetWidth (/* PresentationTarget t,
                                PresentationContext c,
                                PresentationValue *v */);
extern int SpecificSetVPos (/* PresentationTarget t,
                               PresentationContext c,
                               PresentationValue v */);
extern int SpecificGetVPos (/* PresentationTarget t,
                               PresentationContext c,
                               PresentationValue *v */);
extern int SpecificSetHPos (/* PresentationTarget t,
                               PresentationContext c,
                               PresentationValue v */);
extern int SpecificGetHPos (/* PresentationTarget t,
                               PresentationContext c,
                               PresentationValue *v */);
extern int SpecificSetInLine (/* PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue v */);
extern int SpecificGetInLine (/* PresentationTarget t,
                                 PresentationContext c,
                                 PresentationValue *v */);
extern int SpecificSetShowBox (/* PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue v */);
extern int SpecificGetShowBox (/* PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue *v */);
extern int SpecificSetPictureMode (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue v */);
extern int SpecificGetPictureMode (/* PresentationTarget t,
                                      PresentationContext c,
                                      PresentationValue *v */);
extern int SpecificSetBgImage (/* PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue v */);
extern int SpecificGetBgImage (/* PresentationTarget t,
                                  PresentationContext c,
                                  PresentationValue * v */);
extern void ApplyAllSpecificContext (/* Document doc,
                                        SpecificTarget target,
                                        SpecificContextApplyHandler handler,
                                        void *param */);
extern void ApplyAllSpecificSettings (/* SpecificTarget target,
                                         SpecificContext ctxt,
                                         SpecificSettingsApplyHandler handler,
                                         void *param */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
