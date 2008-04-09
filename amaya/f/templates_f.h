/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern ThotBool IsTemplateInstanceDocument ( Document doc );
extern ThotBool IsTemplateDocument ( Document doc );
extern ThotBool CheckPromptIndicator ( Element el,
                                       Document doc );
extern ThotBool RemovePromptIndicator ( NotifyOnTarget *event );
extern void* AllocTemplateRepositoryListElement ( const char* path,
                                                  void* prevElement );
extern void FreeTemplateRepositoryList ( void* list );
extern void GetTemplateRepositoryList ( void* list );
extern void SetTemplateRepositoryList ( const void* list );
extern void InitTemplates ( void );
extern void CreateInstanceOfTemplate ( Document doc,
                                       char *templatename,
                                       char *docname );
extern void PreventReloadingTemplate ( char* template_url );
extern void AllowReloadingTemplate ( char* template_url );
extern ThotBool isEOSorWhiteSpace ( const char c );
extern ThotBool isWhiteSpace ( const char c );
extern void giveItems ( char *text,
                        int size,
                        struct menuType **items,
                        int *nbitems );
extern ThotBool UseToBeCreated ( NotifyElement *event );
extern void UseCreated ( NotifyElement *event );
extern ThotBool Template_CanInsertRepeatChild ( Element el );
extern char *Template_GetListTypes ( XTigerTemplate t,
                                     Element el );
extern ThotBool BagButtonClicked ( NotifyElement *event );
extern ThotBool RepeatButtonClicked ( NotifyElement *event );
extern ThotBool UseButtonClicked ( NotifyElement *event );
extern ThotBool UseSimpleButtonClicked ( NotifyElement *event );
extern ThotBool OptionButtonClicked ( NotifyElement *event );
extern void CheckTemplate ( Document doc );
extern void OpeningInstance ( char *fileName,
                              Document doc );
extern ThotBool ClosingInstance ( NotifyDialog* dialog );
extern ThotBool IsTemplateElement ( Element elem );
extern Element GetFirstTemplateParentElement ( Element elem );
extern ThotBool TemplateElementWillBeCreated ( NotifyElement *event );
extern ThotBool TemplateElementWillBeDeleted ( NotifyElement *event );
extern ThotBool CurrentTypeWillBeExported ( NotifyAttribute *event );
extern ThotBool TemplateAttrInMenu ( NotifyAttribute * event );

#else /* __STDC__ */

extern ThotBool IsTemplateInstanceDocument ( Document doc );
extern ThotBool IsTemplateDocument ( Document doc );
extern ThotBool CheckPromptIndicator ( Element el,
                                         Document doc );
extern ThotBool RemovePromptIndicator ( NotifyOnTarget *event );
extern void* AllocTemplateRepositoryListElement ( const char* path,
                                                    void* prevElement );
extern void FreeTemplateRepositoryList ( void* list );
extern void GetTemplateRepositoryList ( void* list );
extern void SetTemplateRepositoryList ( const void* list );
extern void InitTemplates ( void );
extern void CreateInstanceOfTemplate ( Document doc,
                                         char *templatename,
                                         char *docname );
extern void PreventReloadingTemplate ( char* template_url );
extern void AllowReloadingTemplate ( char* template_url );
extern ThotBool isEOSorWhiteSpace ( const char c );
extern ThotBool isWhiteSpace ( const char c );
extern void giveItems ( char *text,
                          int size,
                          struct menuType **items,
                          int *nbitems );
extern ThotBool UseToBeCreated ( NotifyElement *event );
extern void UseCreated ( NotifyElement *event );
extern ThotBool Template_CanInsertRepeatChild ( Element el );
extern char *Template_GetListTypes ( XTigerTemplate t,
                                       Element el );
extern ThotBool BagButtonClicked ( NotifyElement *event );
extern ThotBool RepeatButtonClicked ( NotifyElement *event );
extern ThotBool UseButtonClicked ( NotifyElement *event );
extern ThotBool UseSimpleButtonClicked ( NotifyElement *event );
extern ThotBool OptionButtonClicked ( NotifyElement *event );
extern void CheckTemplate ( Document doc );
extern void OpeningInstance ( char *fileName,
                                Document doc );
extern ThotBool ClosingInstance ( NotifyDialog* dialog );
extern ThotBool IsTemplateElement ( Element elem );
extern Element GetFirstTemplateParentElement ( Element elem );
extern ThotBool TemplateElementWillBeCreated ( NotifyElement *event );
extern ThotBool TemplateElementWillBeDeleted ( NotifyElement *event );
extern ThotBool CurrentTypeWillBeExported ( NotifyAttribute *event );
extern ThotBool TemplateAttrInMenu ( NotifyAttribute * event );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */