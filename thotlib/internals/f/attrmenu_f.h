/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__
extern void TtaSetAttributeChangeFunction ( Proc2 procedure );
extern void CallbackReqAttrMenu ( int ref,
                                  int val,
                                  char *txt );
extern void BuildReqAttrMenu ( PtrAttribute pAttr,
                               PtrDocument pDoc,
                               PtrElement pEl );
extern void UpdateAttrMenu ( PtrDocument pDoc,
                             ThotBool force );
extern void TtaUpdateAttrMenu ( Document document );
extern void CallbackValAttrMenu ( int ref,
                                  int valmenu,
                                  char *valtext );
extern void SetAttrValueToRange ( PtrAttrListElem elem,
                                  intptr_t value );
extern void CallbackEditRefAttribute ( PtrAttrListElem pAttrElem,
                                       int frame );
extern void CallbackEditAttribute ( PtrAttrListElem pAttrElem,
                                    int frame );
extern void CallbackAttrMenu ( int refmenu,
                               int attMenu,
                               int frame );
extern void CallbackLanguageMenu ( int ref,
                                   int val,
                                   char *txt );
extern void CloseAttributeDialogues ( PtrDocument pDoc );
extern void AttributeMenuLoadResources ( void );

#else /* __STDC__ */
extern void TtaSetAttributeChangeFunction ( Proc2 procedure );
extern void CallbackReqAttrMenu ( int ref,
                                    int val,
                                    char *txt );
extern void BuildReqAttrMenu ( PtrAttribute pAttr,
                                 PtrDocument pDoc,
                                 PtrElement pEl );
extern void UpdateAttrMenu ( PtrDocument pDoc,
                               ThotBool force );
extern void TtaUpdateAttrMenu ( Document document );
extern void CallbackValAttrMenu ( int ref,
                                    int valmenu,
                                    char *valtext );
extern void SetAttrValueToRange ( PtrAttrListElem elem,
                                    intptr_t value );
extern void CallbackEditRefAttribute ( PtrAttrListElem pAttrElem,
                                         int frame );
extern void CallbackEditAttribute ( PtrAttrListElem pAttrElem,
                                      int frame );
extern void CallbackAttrMenu ( int refmenu,
                                 int attMenu,
                                 int frame );
extern void CallbackLanguageMenu ( int ref,
                                     int val,
                                     char *txt );
extern void CloseAttributeDialogues ( PtrDocument pDoc );
extern void AttributeMenuLoadResources ( void );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */