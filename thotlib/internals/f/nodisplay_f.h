/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern boolean CallEventType ( NotifyEvent * notifyEvent,
                               boolean pre );
extern boolean CallEventAttribute ( NotifyAttribute * notifyAttr,
                                    boolean pre );
extern void FreePictInfo ( int *desc );
extern void FreePicture ( int *desc );
extern void AddInSelection ( PtrElement pEl,
                             boolean dernier );
extern void LibAbbEl ( PtrElement pEl );
extern void ConfigTranslateSSchema ( PtrSSchema pSS );
extern PtrPRule GlobalSearchRulepEl ( PtrElement pEl,
                                      PtrPSchema * pSPR,
                                      PtrSSchema * pSSR,
                                      int NumPres,
                                      PtrPSchema pSchP,
                                      int Vue,
                                      PRuleType TRegle,
                                      FunctionType typeFunc,
                                      boolean Pag,
                                      boolean attr,
                                      PtrAttribute * pAttr );
extern boolean IsASavedElement ( PtrElement pEl );
extern boolean BothHaveNoSpecRules ( PtrElement pEl1,
                                     PtrElement pEl2 );
extern void UnloadDocument ( PtrDocument * pDoc );

#else /* __STDC__ */

extern boolean CallEventType (/* NotifyEvent * notifyEvent,
                                 boolean pre */);
extern boolean CallEventAttribute (/* NotifyAttribute * notifyAttr,
                                      boolean pre */);
extern void FreePictInfo (/* int *desc */);
extern void FreePicture (/* int *desc */);
extern void AddInSelection (/* PtrElement pEl,
                               boolean dernier */);
extern void LibAbbEl (/* PtrElement pEl */);
extern void ConfigTranslateSSchema (/* PtrSSchema pSS */);
extern PtrPRule GlobalSearchRulepEl (/* PtrElement pEl,
                                        PtrPSchema * pSPR,
                                        PtrSSchema * pSSR,
                                        int NumPres,
                                        PtrPSchema pSchP,
                                        int Vue,
                                        PRuleType TRegle,
                                        FunctionType typeFunc,
                                        boolean Pag,
                                        boolean attr,
                                        PtrAttribute * pAttr */);
extern boolean IsASavedElement (/* PtrElement pEl */);
extern boolean BothHaveNoSpecRules (/* PtrElement pEl1,
                                       PtrElement pEl2 */);
extern void UnloadDocument (/* PtrDocument * pDoc */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
