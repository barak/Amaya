/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern int TtaXLookupString ( ThotKeyEvent *event,
                              char *buffer,
                              int nbytes,
                              KeySym *keysym,
                              ThotComposeStatus *status );
extern void TtaInstallMultiKey ( void );
extern int TtaGetIsoKeysym ( ThotEvent * event,
                             KeySym keysym );
extern int TtaHandleMultiKeyEvent ( ThotEvent * event );
extern void TtaSetMainLoop ( ExternalInitMainLoop init,
                             ExternalMainLoop loop,
                             ExternalFetchEvent fetch,
                             ExternalFetchAvailableEvent fetchavail );
extern void TtaFetchOneEvent ( ThotEvent *ev );
extern boolean TtaFetchOneAvailableEvent ( ThotEvent *ev );
extern void TtaHandleOneEvent ( ThotEvent * ev );
extern void TtaHandlePendingEvents ( void );
extern void TtaMainLoop ( void );
extern Pixel TtaGetMenuColor ( void );
extern Pixel TtaGetButtonColor ( void );
extern void DisplayEmptyBoxLoadResources ( void );
extern Display *TtaGetCurrentDisplay ( void );
extern int TtaGetScreenDepth ( void );
extern void TtaClickElement ( Document * document,
                              Element * element );
extern void TtaGiveSelectPosition ( Document document,
                                    Element element,
                                    View view,
                                    int *X,
                                    int *Y );

#else /* __STDC__ */

extern int TtaXLookupString (/* ThotKeyEvent *event,
                                char *buffer,
                                int nbytes,
                                KeySym *keysym,
                                ThotComposeStatus *status */);
extern void TtaInstallMultiKey (/* void */);
extern int TtaGetIsoKeysym (/* ThotEvent * event,
                               KeySym keysym */);
extern int TtaHandleMultiKeyEvent (/* ThotEvent * event */);
extern void TtaSetMainLoop (/* ExternalInitMainLoop init,
                               ExternalMainLoop loop,
                               ExternalFetchEvent fetch,
                               ExternalFetchAvailableEvent fetchavail */);
extern void TtaFetchOneEvent (/* ThotEvent *ev */);
extern boolean TtaFetchOneAvailableEvent (/* ThotEvent *ev */);
extern void TtaHandleOneEvent (/* ThotEvent * ev */);
extern void TtaHandlePendingEvents (/* void */);
extern void TtaMainLoop (/* void */);
extern Pixel TtaGetMenuColor (/* void */);
extern Pixel TtaGetButtonColor (/* void */);
extern void DisplayEmptyBoxLoadResources (/* void */);
extern Display *TtaGetCurrentDisplay (/* void */);
extern int TtaGetScreenDepth (/* void */);
extern void TtaClickElement (/* Document * document,
                                Element * element */);
extern void TtaGiveSelectPosition (/* Document document,
                                      Element element,
                                      View view,
                                      int *X,
                                      int *Y */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
