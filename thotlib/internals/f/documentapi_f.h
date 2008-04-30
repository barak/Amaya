/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern int TtaGetDocumentProfile ( Document document );
extern int TtaGetDocumentExtraProfile ( Document document );
extern void TtaSetDocumentProfile ( Document document,
                                    int profile,
                                    int extraProfile );
extern CHARSET TtaGetDocumentCharset ( Document document );
extern void TtaSetDocumentCharset ( Document document,
                                    CHARSET charSet,
                                    ThotBool defaultCharset );
extern Document TtaOpenDocument ( char *documentName,
                                  int accessMode );
extern void UnloadTree ( Document document );
extern void UnloadDocument ( PtrDocument * pDoc );
extern void CloseDocumentAndViews ( PtrDocument pDoc,
                                    ThotBool notify );
extern void TtaCloseDocument ( Document document );
extern void TtaSetDocumentPath ( char *path );
extern ThotBool TtaCheckPath ( char *path );
extern ThotBool TtaIsInDocumentPath ( char *directory );
extern void TtaAppendDocumentPath ( char *directory );
extern void TtaSetSchemaPath ( char *path );
extern SSchema TtaNewNature ( Document document,
                              SSchema schema,
                              char *natureURI,
                              char *natureName,
                              char *presentationName );
extern SSchema TtaNewSchemaExtension ( Document document,
                                       char *extensionName,
                                       char *presentationName );
extern void TtaSetPSchema ( Document document,
                            char *presentationName );
extern void TtaSetDocumentDirectory ( Document document,
                                      char *directory );
extern void TtaSetDocumentAccessMode ( Document document,
                                       int accessMode );
extern void TtaSetDocumentBackUpInterval ( int interval );
extern void TtaSetNotificationMode ( Document document,
                                     int notificationMode );
extern void SetDocumentModified ( PtrDocument pDoc,
                                  ThotBool status,
                                  int length );
extern void TtaSetDocumentModified ( Document document );
extern void TtaSetDocumentUnmodified ( Document document );
extern void TtaSetDocumentUpdated ( Document document );
extern void TtaSetDocumentUnupdated ( Document document );
extern char *TtaGetDocumentName ( Document document );
extern Document TtaGetDocumentFromName ( char *documentName );
extern void TtaGetDocumentDirectory ( Document document,
                                      char *buffer,
                                      int bufferLength );
extern SSchema TtaGetDocumentSSchema ( Document document );
extern char *TtaGetSSchemaName ( SSchema schema );
extern char *TtaGetPSchemaName ( SSchema schema );
extern SSchema TtaGetSSchema ( char *name,
                               Document document );
extern SSchema TtaGetSSchemaByUri ( char *uriName,
                                    Document document );
extern ThotBool TtaSameSSchemas ( SSchema schema1,
                                  SSchema schema2 );
extern void TtaGiveSchemasOfDocument ( char *documentName,
                                       char *structureName,
                                       char *presentationName );
extern void TtaNextSchemaExtension ( Document document,
                                     SSchema * extension );
extern void TtaNextNature ( Document document,
                            SSchema * nature );
extern ThotBool TtaIsDocumentModified ( Document document );
extern ThotBool TtaIsDocumentUpdated ( Document document );
extern int TtaGetDocumentAccessMode ( Document document );
extern int TtaGetDocumentBackUpInterval ( void );
extern int TtaGetNotificationMode ( Document document );
extern void TtaGetDocumentPath ( char *buffer,
                                 int bufferLength );
extern void TtaGetSchemaPath ( char *buffer,
                               int bufferLength );
extern Document TtaGetDocumentOfSavedElements ( void );
extern PtrDocument DocToPtr ( Document document );
extern void TtaSetANamespaceDeclaration ( Document document,
                                          Element element,
                                          char *NsPrefix,
                                          char *NsUri );
extern char *TtaGiveNamespaceDeclaration ( Document document,
                                           Element element );
extern void TtaFreeElemNamespaceDeclarations ( Document document,
                                               Element element );
extern void TtaFreeNamespaceDeclarations ( Document document );
extern void TtaAppendXmlAttribute ( char *xmlName,
                                    AttributeType *attrType,
                                    Document document );
extern void TtaGetXmlAttributeType ( char* xmlName,
                                     AttributeType *attrType,
                                     Document document );
extern void TtaAddEmptyBox ( Element element );
extern ThotBool TtaHasXmlInLineRule ( ElementType elType,
                                      Document document );
extern void TtaSetXmlInLineRule ( ElementType elType,
                                  Document document );
extern void TtaAppendXmlElement ( char *xmlName,
                                  ElementType *elType,
                                  char **mappedName,
                                  Document document );
extern void TtaGetXmlElementType ( char *xmlName,
                                   ElementType *elType,
                                   char **mappedName,
                                   Document document );
extern void TtaSetUriSSchema ( SSchema sSchema,
                               char *sSchemaUri );
extern void TtaChangeGenericSchemaNames ( char *sSchemaUri,
                                          char *sSchemaName,
                                          Document document );
extern ThotBool TtaIsXmlSSchema ( SSchema schema );
extern void TtaAddDocumentReference ( Document document );
extern void TtaRemoveDocumentReference ( Document document );
extern void TtaDumpDocumentReference ( void );

#else /* __STDC__ */

extern int TtaGetDocumentProfile ( Document document );
extern int TtaGetDocumentExtraProfile ( Document document );
extern void TtaSetDocumentProfile ( Document document,
                                      int profile,
                                      int extraProfile );
extern CHARSET TtaGetDocumentCharset ( Document document );
extern void TtaSetDocumentCharset ( Document document,
                                      CHARSET charSet,
                                      ThotBool defaultCharset );
extern Document TtaOpenDocument ( char *documentName,
                                    int accessMode );
extern void UnloadTree ( Document document );
extern void UnloadDocument ( PtrDocument * pDoc );
extern void CloseDocumentAndViews ( PtrDocument pDoc,
                                      ThotBool notify );
extern void TtaCloseDocument ( Document document );
extern void TtaSetDocumentPath ( char *path );
extern ThotBool TtaCheckPath ( char *path );
extern ThotBool TtaIsInDocumentPath ( char *directory );
extern void TtaAppendDocumentPath ( char *directory );
extern void TtaSetSchemaPath ( char *path );
extern SSchema TtaNewNature ( Document document,
                                SSchema schema,
                                char *natureURI,
                                char *natureName,
                                char *presentationName );
extern SSchema TtaNewSchemaExtension ( Document document,
                                         char *extensionName,
                                         char *presentationName );
extern void TtaSetPSchema ( Document document,
                              char *presentationName );
extern void TtaSetDocumentDirectory ( Document document,
                                        char *directory );
extern void TtaSetDocumentAccessMode ( Document document,
                                         int accessMode );
extern void TtaSetDocumentBackUpInterval ( int interval );
extern void TtaSetNotificationMode ( Document document,
                                       int notificationMode );
extern void SetDocumentModified ( PtrDocument pDoc,
                                    ThotBool status,
                                    int length );
extern void TtaSetDocumentModified ( Document document );
extern void TtaSetDocumentUnmodified ( Document document );
extern void TtaSetDocumentUpdated ( Document document );
extern void TtaSetDocumentUnupdated ( Document document );
extern char *TtaGetDocumentName ( Document document );
extern Document TtaGetDocumentFromName ( char *documentName );
extern void TtaGetDocumentDirectory ( Document document,
                                        char *buffer,
                                        int bufferLength );
extern SSchema TtaGetDocumentSSchema ( Document document );
extern char *TtaGetSSchemaName ( SSchema schema );
extern char *TtaGetPSchemaName ( SSchema schema );
extern SSchema TtaGetSSchema ( char *name,
                                 Document document );
extern SSchema TtaGetSSchemaByUri ( char *uriName,
                                      Document document );
extern ThotBool TtaSameSSchemas ( SSchema schema1,
                                    SSchema schema2 );
extern void TtaGiveSchemasOfDocument ( char *documentName,
                                         char *structureName,
                                         char *presentationName );
extern void TtaNextSchemaExtension ( Document document,
                                       SSchema * extension );
extern void TtaNextNature ( Document document,
                              SSchema * nature );
extern ThotBool TtaIsDocumentModified ( Document document );
extern ThotBool TtaIsDocumentUpdated ( Document document );
extern int TtaGetDocumentAccessMode ( Document document );
extern int TtaGetDocumentBackUpInterval ( void );
extern int TtaGetNotificationMode ( Document document );
extern void TtaGetDocumentPath ( char *buffer,
                                   int bufferLength );
extern void TtaGetSchemaPath ( char *buffer,
                                 int bufferLength );
extern Document TtaGetDocumentOfSavedElements ( void );
extern PtrDocument DocToPtr ( Document document );
extern void TtaSetANamespaceDeclaration ( Document document,
                                            Element element,
                                            char *NsPrefix,
                                            char *NsUri );
extern char *TtaGiveNamespaceDeclaration ( Document document,
                                             Element element );
extern void TtaFreeElemNamespaceDeclarations ( Document document,
                                                 Element element );
extern void TtaFreeNamespaceDeclarations ( Document document );
extern void TtaAppendXmlAttribute ( char *xmlName,
                                      AttributeType *attrType,
                                      Document document );
extern void TtaGetXmlAttributeType ( char* xmlName,
                                       AttributeType *attrType,
                                       Document document );
extern void TtaAddEmptyBox ( Element element );
extern ThotBool TtaHasXmlInLineRule ( ElementType elType,
                                        Document document );
extern void TtaSetXmlInLineRule ( ElementType elType,
                                    Document document );
extern void TtaAppendXmlElement ( char *xmlName,
                                    ElementType *elType,
                                    char **mappedName,
                                    Document document );
extern void TtaGetXmlElementType ( char *xmlName,
                                     ElementType *elType,
                                     char **mappedName,
                                     Document document );
extern void TtaSetUriSSchema ( SSchema sSchema,
                                 char *sSchemaUri );
extern void TtaChangeGenericSchemaNames ( char *sSchemaUri,
                                            char *sSchemaName,
                                            Document document );
extern ThotBool TtaIsXmlSSchema ( SSchema schema );
extern void TtaAddDocumentReference ( Document document );
extern void TtaRemoveDocumentReference ( Document document );
extern void TtaDumpDocumentReference ( void );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
