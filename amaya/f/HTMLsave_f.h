/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__
extern ThotBool CheckValidProfile ( NotifyElement *event );
extern ThotBool CheckGenerator ( NotifyElement *event );
extern ThotBool CheckUSEMAP ( NotifyAttribute *event );
extern ThotBool CheckValidEntity ( NotifyAttribute *event );
extern ThotBool CheckValidID ( NotifyAttribute *event );
extern char *UpdateDocResource ( Document doc,
                                 char *oldpath,
                                 char *newpath,
                                 char *relpath,
                                 char *sString,
                                 Element el,
                                 ThotBool saveResources,
                                 ThotBool isLink,
                                 ThotBool fullCopy );
extern void SetRelativeURLs ( Document doc,
                              char *newpath,
                              char *cssbase,
                              ThotBool savedImages,
                              ThotBool savedResources,
                              ThotBool fullCopy );
extern void InitSaveObjectForm ( Document document,
                                 View view,
                                 char *object,
                                 char *pathname );
extern void DeleteTempObjectFile ( void );
extern void DoSaveObjectAs ( void );
extern void SaveDocumentAs ( Document doc,
                             View view );
extern char *UpdateDocumentCharset ( Document doc );
extern void SetNamespacesAndDTD ( Document doc );
extern ThotBool ParseWithNewDoctype ( Document doc,
                                      char *localFile,
                                      char *tempdir,
                                      char *documentname,
                                      int new_doctype,
                                      ThotBool *error,
                                      ThotBool xml_doctype,
                                      ThotBool useMathML,
                                      ThotBool useSVG );
extern void RestartParser ( Document doc,
                            char *localFile,
                            char *tempdir,
                            char *documentname,
                            ThotBool show_errors,
                            ThotBool check_ids );
extern void RedisplaySourceFile ( Document doc );
extern Document GetDocFromSource ( Document sourceDoc );
extern void DoSynchronize ( Document doc,
                            View view,
                            NotifyElement *event );
extern ThotBool SaveBefore ( Document doc );
extern void Synchronize ( Document doc,
                          View view );
extern void RedisplayDoc ( Document doc );
extern void SaveAll ( Document doc,
                      View view );
extern void SaveDocument ( Document doc,
                           View view );
extern ThotBool CanReplaceCurrentDocument ( Document doc,
                                            View view );
extern void BackUpDocs ( void );
extern void RemoveAutoSavedDoc ( Document doc );
extern void GenerateAutoSavedDoc ( Document doc );
extern ThotBool DocumentToSave ( NotifyDialog *event );
extern void DoSaveAs ( char *user_charset,
                       char *user_mimetype,
                       ThotBool fullCopy );
extern ThotBool SaveTempCopy ( Document doc,
                               const char* dstdir,
                               char** filename );
extern void SendByMail ( Document document,
                         View view );

#else /* __STDC__ */
extern ThotBool CheckValidProfile ( NotifyElement *event );
extern ThotBool CheckGenerator ( NotifyElement *event );
extern ThotBool CheckUSEMAP ( NotifyAttribute *event );
extern ThotBool CheckValidEntity ( NotifyAttribute *event );
extern ThotBool CheckValidID ( NotifyAttribute *event );
extern char *UpdateDocResource ( Document doc,
                                   char *oldpath,
                                   char *newpath,
                                   char *relpath,
                                   char *sString,
                                   Element el,
                                   ThotBool saveResources,
                                   ThotBool isLink,
                                   ThotBool fullCopy );
extern void SetRelativeURLs ( Document doc,
                                char *newpath,
                                char *cssbase,
                                ThotBool savedImages,
                                ThotBool savedResources,
                                ThotBool fullCopy );
extern void InitSaveObjectForm ( Document document,
                                   View view,
                                   char *object,
                                   char *pathname );
extern void DeleteTempObjectFile ( void );
extern void DoSaveObjectAs ( void );
extern void SaveDocumentAs ( Document doc,
                               View view );
extern char *UpdateDocumentCharset ( Document doc );
extern void SetNamespacesAndDTD ( Document doc );
extern ThotBool ParseWithNewDoctype ( Document doc,
                                        char *localFile,
                                        char *tempdir,
                                        char *documentname,
                                        int new_doctype,
                                        ThotBool *error,
                                        ThotBool xml_doctype,
                                        ThotBool useMathML,
                                        ThotBool useSVG );
extern void RestartParser ( Document doc,
                              char *localFile,
                              char *tempdir,
                              char *documentname,
                              ThotBool show_errors,
                              ThotBool check_ids );
extern void RedisplaySourceFile ( Document doc );
extern Document GetDocFromSource ( Document sourceDoc );
extern void DoSynchronize ( Document doc,
                              View view,
                              NotifyElement *event );
extern ThotBool SaveBefore ( Document doc );
extern void Synchronize ( Document doc,
                            View view );
extern void RedisplayDoc ( Document doc );
extern void SaveAll ( Document doc,
                        View view );
extern void SaveDocument ( Document doc,
                             View view );
extern ThotBool CanReplaceCurrentDocument ( Document doc,
                                              View view );
extern void BackUpDocs ( void );
extern void RemoveAutoSavedDoc ( Document doc );
extern void GenerateAutoSavedDoc ( Document doc );
extern ThotBool DocumentToSave ( NotifyDialog *event );
extern void DoSaveAs ( char *user_charset,
                         char *user_mimetype,
                         ThotBool fullCopy );
extern ThotBool SaveTempCopy ( Document doc,
                                 const char* dstdir,
                                 char** filename );
extern void SendByMail ( Document document,
                           View view );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
