/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern PtrReference NextReferenceToEl ( PtrElement pEl,
                                        PtrDocument pDoc,
                                        boolean processNotLoaded,
                                        PtrReference pPrevRef,
                                        PtrDocument * pDocRef,
                                        PtrExternalDoc * pExtDoc,
                                        boolean nextExtDoc );
extern boolean GetCurrentSelection ( PtrDocument * pDoc,
                                     PtrElement * firstEl,
                                     PtrElement * lastEl,
                                     int *firstChar,
                                     int *lastChar );
extern void DefineClipping ( int frame,
                             int orgx,
                             int orgy,
                             int *xd,
                             int *yd,
                             int *xf,
                             int *yf,
                             int raz );
extern void RemoveClipping ( int frame );
extern void GetSizesFrame ( int frame,
                            int *width,
                            int *height );
extern ThotWindow TtaGetThotWindow ( int frame );
extern void GetDocAndView ( int frame,
                            PtrDocument * pDoc,
                            int *view,
                            boolean * assoc );
extern void PrintOnePage ( PtrDocument pDoc,
                           PtrAbstractBox pPageAb,
                           PtrAbstractBox pNextPageAb,
                           int view,
                           int clipOrg,
                           boolean assoc );
extern void DisplayConfirmMessage ( char *text );
extern void DisplayMessage ( char *text,
                             int msgType );
extern void TtaError ( int errorCode );
extern void CloseInsertion ( void );
extern void main ( int argc,
                   char **argv );

#else /* __STDC__ */

extern PtrReference NextReferenceToEl (/* PtrElement pEl,
                                          PtrDocument pDoc,
                                          boolean processNotLoaded,
                                          PtrReference pPrevRef,
                                          PtrDocument * pDocRef,
                                          PtrExternalDoc * pExtDoc,
                                          boolean nextExtDoc */);
extern boolean GetCurrentSelection (/* PtrDocument * pDoc,
                                       PtrElement * firstEl,
                                       PtrElement * lastEl,
                                       int *firstChar,
                                       int *lastChar */);
extern void DefineClipping (/* int frame,
                               int orgx,
                               int orgy,
                               int *xd,
                               int *yd,
                               int *xf,
                               int *yf,
                               int raz */);
extern void RemoveClipping (/* int frame */);
extern void GetSizesFrame (/* int frame,
                              int *width,
                              int *height */);
extern ThotWindow TtaGetThotWindow (/* int frame */);
extern void GetDocAndView (/* int frame,
                              PtrDocument * pDoc,
                              int *view,
                              boolean * assoc */);
extern void PrintOnePage (/* PtrDocument pDoc,
                             PtrAbstractBox pPageAb,
                             PtrAbstractBox pNextPageAb,
                             int view,
                             int clipOrg,
                             boolean assoc */);
extern void DisplayConfirmMessage (/* char *text */);
extern void DisplayMessage (/* char *text,
                               int msgType */);
extern void TtaError (/* int errorCode */);
extern void CloseInsertion (/* void */);
extern void main (/* int argc,
                     char **argv */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
