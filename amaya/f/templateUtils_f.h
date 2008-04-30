/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern char *GetSchemaFromDocType ( DocumentType docType );
extern void SetAttributeStringValue ( Element el,
                                      int att,
                                      char* value );
extern void SetAttributeStringValueWithUndo ( Element el,
                                              int att,
                                              char* value );
extern void GiveAttributeStringValueFromNum ( Element el,
                                              int att,
                                              char* buff,
                                              int* sz );
extern char *GetAttributeStringValueFromNum ( Element el,
                                              int att,
                                              int* sz );
extern char *GetAttributeStringValue ( Element el,
                                       Attribute attribute,
                                       int* sz );
extern Element GetFirstEditableElement ( Element el );
extern ThotBool TemplateCanInsertFirstChild ( ElementType elementType,
                                              Element parent,
                                              Document document );
extern ThotBool ValidateTemplateAttrInMenu ( NotifyAttribute * event );
extern void DumpElementSubPath ( Element el,
                                 char* buffer );
extern void DumpElementPath ( Element el );
extern void DumpTemplateElement ( Element el,
                                  Document doc );
extern ThotBool SaveDocumentToNewDoc ( Document doc,
                                       Document newdoc,
                                       char* newpath );

#else /* __STDC__ */

extern char *GetSchemaFromDocType ( DocumentType docType );
extern void SetAttributeStringValue ( Element el,
                                        int att,
                                        char* value );
extern void SetAttributeStringValueWithUndo ( Element el,
                                                int att,
                                                char* value );
extern void GiveAttributeStringValueFromNum ( Element el,
                                                int att,
                                                char* buff,
                                                int* sz );
extern char *GetAttributeStringValueFromNum ( Element el,
                                                int att,
                                                int* sz );
extern char *GetAttributeStringValue ( Element el,
                                         Attribute attribute,
                                         int* sz );
extern Element GetFirstEditableElement ( Element el );
extern ThotBool TemplateCanInsertFirstChild ( ElementType elementType,
                                                Element parent,
                                                Document document );
extern ThotBool ValidateTemplateAttrInMenu ( NotifyAttribute * event );
extern void DumpElementSubPath ( Element el,
                                   char* buffer );
extern void DumpElementPath ( Element el );
extern void DumpTemplateElement ( Element el,
                                    Document doc );
extern ThotBool SaveDocumentToNewDoc ( Document doc,
                                         Document newdoc,
                                         char* newpath );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
