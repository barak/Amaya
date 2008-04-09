/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void UpdateStyleList ( Document doc,
                              View view );
extern char *UpdateCSSURLs ( Document doc,
                             char *oldpath,
                             char *newpath,
                             char *imgpath,
                             char *styleString,
                             ThotBool imgSave,
                             ThotBool localimport );
extern void UpdateStyleSheetContent ( Document doc,
                                      char *cssfile,
                                      char *oldpath,
                                      char *newpath );
extern ThotBool UpdateStyleDelete ( NotifyAttribute * event );
extern ThotBool DeleteStyle ( NotifyElement *event );
extern Attribute GetCurrentStyleAttribute ( void );
extern char *GetCurrentStyle ( void );
extern void EnableStyleElement ( Document doc,
                                 Element el );
extern void DeleteStyleElement ( Document doc,
                                 Element el );
extern ThotBool ChangeStyle ( NotifyOnTarget * event );
extern void StyleChanged ( NotifyOnTarget *event );
extern void ChangeTheme ( const char *theme );
extern void DoClassicTheme ( Document doc,
                             View view );
extern void DoModernTheme ( Document doc,
                            View view );
extern void DoNoTheme ( Document doc,
                        View view );
extern void UpdateStylePost ( NotifyAttribute * event );
extern void SetStyleString ( Document doc,
                             Element el,
                             PRule presRule );
extern void GetHTMLStyleString ( Element el,
                                 Document doc,
                                 char *buf,
                                 int *len );
extern void HTMLSetBackgroundImage ( Document doc,
                                     Element el,
                                     int repeat,
                                     int specificity,
                                     char *image,
                                     ThotBool generate );
extern void CreateClass ( Document doc,
                          View view );
extern void ApplyClass ( Document doc,
                         View view );
extern void StyleCallbackDialogue ( int ref,
                                    int typedata,
                                    char *data );

#else /* __STDC__ */

extern void UpdateStyleList ( Document doc,
                                View view );
extern char *UpdateCSSURLs ( Document doc,
                               char *oldpath,
                               char *newpath,
                               char *imgpath,
                               char *styleString,
                               ThotBool imgSave,
                               ThotBool localimport );
extern void UpdateStyleSheetContent ( Document doc,
                                        char *cssfile,
                                        char *oldpath,
                                        char *newpath );
extern ThotBool UpdateStyleDelete ( NotifyAttribute * event );
extern ThotBool DeleteStyle ( NotifyElement *event );
extern Attribute GetCurrentStyleAttribute ( void );
extern char *GetCurrentStyle ( void );
extern void EnableStyleElement ( Document doc,
                                   Element el );
extern void DeleteStyleElement ( Document doc,
                                   Element el );
extern ThotBool ChangeStyle ( NotifyOnTarget * event );
extern void StyleChanged ( NotifyOnTarget *event );
extern void ChangeTheme ( const char *theme );
extern void DoClassicTheme ( Document doc,
                               View view );
extern void DoModernTheme ( Document doc,
                              View view );
extern void DoNoTheme ( Document doc,
                          View view );
extern void UpdateStylePost ( NotifyAttribute * event );
extern void SetStyleString ( Document doc,
                               Element el,
                               PRule presRule );
extern void GetHTMLStyleString ( Element el,
                                   Document doc,
                                   char *buf,
                                   int *len );
extern void HTMLSetBackgroundImage ( Document doc,
                                       Element el,
                                       int repeat,
                                       int specificity,
                                       char *image,
                                       ThotBool generate );
extern void CreateClass ( Document doc,
                            View view );
extern void ApplyClass ( Document doc,
                           View view );
extern void StyleCallbackDialogue ( int ref,
                                      int typedata,
                                      char *data );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */