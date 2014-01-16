/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void InitializeTemplateEnvironment ( void );
extern void FreeTemplateEnvironment ( void );
extern XTigerTemplate NewXTigerTemplate ( const char *templatePath );
extern XTigerTemplate NewXTigerLibrary ( const char *templatePath );
extern XTigerTemplate LookForXTigerLibrary ( const char *templatePath );
extern XTigerTemplate LookForXTigerTemplate ( const char *templatePath );
extern XTigerTemplate GetXTigerTemplate ( const char *templatePath );
extern XTigerTemplate GetXTigerDocTemplate ( Document doc );
extern void Template_Close ( XTigerTemplate t );
extern void Template_AddStandardDependancies ( XTigerTemplate t );
extern XTigerTemplate CreatePredefinedTypesLibrary ( void );
extern XTigerTemplate CreateHTMLLibrary ( void );
extern Declaration Declaration_Clone ( Declaration dec );
extern void Declaration_Destroy ( Declaration dec );
extern ThotBool Declaration_GetElementType ( Declaration dec,
                                             ElementType *type );
extern int Declaration_Compare ( Declaration dec1,
                                 Declaration dec2 );
extern int Declaration_CompareToString ( Declaration dec,
                                         const char* name );
extern void Declaration_CalcBlockLevel ( Declaration dec );
extern void Template_CalcBlockLevel ( XTigerTemplate t );
extern char* Template_GetBlockLevelDeclarations ( XTigerTemplate t,
                                                  ThotBool addAny );
extern char* Template_GetInlineLevelDeclarations ( XTigerTemplate t,
                                                   ThotBool addAny,
                                                   ThotBool addSimple );
extern Declaration Template_DeclareNewSimpleType ( XTigerTemplate t,
                                                   const char *name,
                                                   SimpleTypeType xtype );
extern Declaration Template_DeclareNewComponent ( XTigerTemplate t,
                                                  const char *name,
                                                  Element el );
extern Declaration Template_DeclareNewElement ( const XTigerTemplate t,
                                                const char *name );
extern Declaration Template_DeclareNewUnion ( XTigerTemplate t,
                                              const char *name,
                                              const char* include,
                                              const char* exclude );
extern void Template_AddDeclaration ( XTigerTemplate t,
                                      Declaration dec );
extern void Template_RemoveUnknownDeclaration ( XTigerTemplate t,
                                                Declaration dec );
extern void Template_MoveUnknownDeclarationToXmlElement ( XTigerTemplate t );
extern Declaration Template_GetDeclaration ( const XTigerTemplate t,
                                             const char *name );
extern Declaration Template_GetSimpleTypeDeclaration ( const XTigerTemplate t,
                                                       const char *name );
extern Declaration Template_GetComponentDeclaration ( const XTigerTemplate t,
                                                      const char *name );
extern Declaration Template_GetElementDeclaration ( const XTigerTemplate t,
                                                    const char *name );
extern Declaration Template_GetUnionDeclaration ( const XTigerTemplate t,
                                                  const char *name );
extern void Template_Clear ( XTigerTemplate t );
extern void Template_FillDeclarations ( XTigerTemplate t );
extern void Template_AddLibraryDeclarations ( XTigerTemplate t,
                                              XTigerTemplate lib );
extern void Template_AddError ( XTigerTemplate t,
                                const char* format,
                                ... );
extern void Template_ShowErrors ( XTigerTemplate t );
extern ThotBool Template_HasErrors ( XTigerTemplate t );
extern void Template_PrintUnion ( Declaration dec,
                                  int indent,
                                  XTigerTemplate t,
                                  FILE *file );
extern void PrintElement ( Element elem,
                           int dec );
extern void PrintDeclarations ( XTigerTemplate t,
                                FILE *file );
extern void DumpAllDeclarations ( void );
extern void DumpDeclarations ( XTigerTemplate t );
extern void DumpTemplateReferences ( void );
extern SearchSet GetComponents ( XTigerTemplate t );
extern Element GetComponentContent ( Declaration d );
extern Document GetTemplateDocument ( XTigerTemplate t );
extern void SetTemplateDocument ( XTigerTemplate t,
                                  Document doc );
extern void Template_AddReference ( XTigerTemplate t );
extern void Template_RemoveReference ( XTigerTemplate t );
extern ThotBool Template_IsPredefined ( XTigerTemplate t );
extern ThotBool Template_IsLibrary ( XTigerTemplate t );
extern ThotBool Template_IsTemplate ( XTigerTemplate t );
extern ThotBool Template_IsInstance ( XTigerTemplate t );
extern ThotBool Template_IsLoaded ( XTigerTemplate t );
extern ThotBool Template_IsInternal ( XTigerTemplate t );
extern SearchSet Template_GetDeclarationSetFromNames ( XTigerTemplate t,
                                                       const char* names,
                                                       ThotBool expand );
extern SearchSet Template_ExpandUnion ( XTigerTemplate t,
                                        Declaration decl );
extern SearchSet Template_ExpandTypeSet ( XTigerTemplate t,
                                          SearchSet types );
extern void Template_FilterInsertableElement ( XTigerTemplate t,
                                               SearchSet set,
                                               Element refelem,
                                               ThotBool insertafter );
extern char* Template_ExpandTypes ( XTigerTemplate t,
                                    const char* types,
                                    Element refelem,
                                    ThotBool insertafter );
extern ThotBool Template_IsElementTypeAllowed ( ElementType type,
                                                Declaration decl );
extern ThotBool Template_IsTypeAllowed ( const char* type,
                                         Declaration decl );
extern ThotBool Template_CanInsertElementInBag ( Document doc,
                                                 ElementType type,
                                                 char* bagTypes );
extern ThotBool Template_CanInsertTypeInBag ( Document doc,
                                              const char* type,
                                              char* bagTypes );
extern ThotBool Template_CanInsertElementInBagElement ( Document doc,
                                                        ElementType type,
                                                        Element bag );
extern ThotBool Template_CanInsertElementInBagElement ( Document doc,
                                                        const char* type,
                                                        Element bag );
extern ThotBool Template_CanInsertElementInUse ( Document doc,
                                                 ElementType type,
                                                 char* useType,
                                                 Element parent,
                                                 int position );
extern ThotBool Template_IsUsedComponent ( XTigerTemplate t,
                                           Document doc,
                                           const char* name );

#else /* __STDC__ */

extern void InitializeTemplateEnvironment ( void );
extern void FreeTemplateEnvironment ( void );
extern XTigerTemplate NewXTigerTemplate ( const char *templatePath );
extern XTigerTemplate NewXTigerLibrary ( const char *templatePath );
extern XTigerTemplate LookForXTigerLibrary ( const char *templatePath );
extern XTigerTemplate LookForXTigerTemplate ( const char *templatePath );
extern XTigerTemplate GetXTigerTemplate ( const char *templatePath );
extern XTigerTemplate GetXTigerDocTemplate ( Document doc );
extern void Template_Close ( XTigerTemplate t );
extern void Template_AddStandardDependancies ( XTigerTemplate t );
extern XTigerTemplate CreatePredefinedTypesLibrary ( void );
extern XTigerTemplate CreateHTMLLibrary ( void );
extern Declaration Declaration_Clone ( Declaration dec );
extern void Declaration_Destroy ( Declaration dec );
extern ThotBool Declaration_GetElementType ( Declaration dec,
                                               ElementType *type );
extern int Declaration_Compare ( Declaration dec1,
                                   Declaration dec2 );
extern int Declaration_CompareToString ( Declaration dec,
                                           const char* name );
extern void Declaration_CalcBlockLevel ( Declaration dec );
extern void Template_CalcBlockLevel ( XTigerTemplate t );
extern char* Template_GetBlockLevelDeclarations ( XTigerTemplate t,
                                                    ThotBool addAny );
extern char* Template_GetInlineLevelDeclarations ( XTigerTemplate t,
                                                     ThotBool addAny,
                                                     ThotBool addSimple );
extern Declaration Template_DeclareNewSimpleType ( XTigerTemplate t,
                                                     const char *name,
                                                     SimpleTypeType xtype );
extern Declaration Template_DeclareNewComponent ( XTigerTemplate t,
                                                    const char *name,
                                                    Element el );
extern Declaration Template_DeclareNewElement ( const XTigerTemplate t,
                                                  const char *name );
extern Declaration Template_DeclareNewUnion ( XTigerTemplate t,
                                                const char *name,
                                                const char* include,
                                                const char* exclude );
extern void Template_AddDeclaration ( XTigerTemplate t,
                                        Declaration dec );
extern void Template_RemoveUnknownDeclaration ( XTigerTemplate t,
                                                  Declaration dec );
extern void Template_MoveUnknownDeclarationToXmlElement ( XTigerTemplate t );
extern Declaration Template_GetDeclaration ( const XTigerTemplate t,
                                               const char *name );
extern Declaration Template_GetSimpleTypeDeclaration ( const XTigerTemplate t,
                                                         const char *name );
extern Declaration Template_GetComponentDeclaration ( const XTigerTemplate t,
                                                        const char *name );
extern Declaration Template_GetElementDeclaration ( const XTigerTemplate t,
                                                      const char *name );
extern Declaration Template_GetUnionDeclaration ( const XTigerTemplate t,
                                                    const char *name );
extern void Template_Clear ( XTigerTemplate t );
extern void Template_FillDeclarations ( XTigerTemplate t );
extern void Template_AddLibraryDeclarations ( XTigerTemplate t,
                                                XTigerTemplate lib );
extern void Template_AddError ( XTigerTemplate t,
                                  const char* format,
                                  ... );
extern void Template_ShowErrors ( XTigerTemplate t );
extern ThotBool Template_HasErrors ( XTigerTemplate t );
extern void Template_PrintUnion ( Declaration dec,
                                    int indent,
                                    XTigerTemplate t,
                                    FILE *file );
extern void PrintElement ( Element elem,
                             int dec );
extern void PrintDeclarations ( XTigerTemplate t,
                                  FILE *file );
extern void DumpAllDeclarations ( void );
extern void DumpDeclarations ( XTigerTemplate t );
extern void DumpTemplateReferences ( void );
extern SearchSet GetComponents ( XTigerTemplate t );
extern Element GetComponentContent ( Declaration d );
extern Document GetTemplateDocument ( XTigerTemplate t );
extern void SetTemplateDocument ( XTigerTemplate t,
                                    Document doc );
extern void Template_AddReference ( XTigerTemplate t );
extern void Template_RemoveReference ( XTigerTemplate t );
extern ThotBool Template_IsPredefined ( XTigerTemplate t );
extern ThotBool Template_IsLibrary ( XTigerTemplate t );
extern ThotBool Template_IsTemplate ( XTigerTemplate t );
extern ThotBool Template_IsInstance ( XTigerTemplate t );
extern ThotBool Template_IsLoaded ( XTigerTemplate t );
extern ThotBool Template_IsInternal ( XTigerTemplate t );
extern SearchSet Template_GetDeclarationSetFromNames ( XTigerTemplate t,
                                                         const char* names,
                                                         ThotBool expand );
extern SearchSet Template_ExpandUnion ( XTigerTemplate t,
                                          Declaration decl );
extern SearchSet Template_ExpandTypeSet ( XTigerTemplate t,
                                            SearchSet types );
extern void Template_FilterInsertableElement ( XTigerTemplate t,
                                                 SearchSet set,
                                                 Element refelem,
                                                 ThotBool insertafter );
extern char* Template_ExpandTypes ( XTigerTemplate t,
                                      const char* types,
                                      Element refelem,
                                      ThotBool insertafter );
extern ThotBool Template_IsElementTypeAllowed ( ElementType type,
                                                  Declaration decl );
extern ThotBool Template_IsTypeAllowed ( const char* type,
                                           Declaration decl );
extern ThotBool Template_CanInsertElementInBag ( Document doc,
                                                   ElementType type,
                                                   char* bagTypes );
extern ThotBool Template_CanInsertTypeInBag ( Document doc,
                                                const char* type,
                                                char* bagTypes );
extern ThotBool Template_CanInsertElementInBagElement ( Document doc,
                                                          ElementType type,
                                                          Element bag );
extern ThotBool Template_CanInsertElementInBagElement ( Document doc,
                                                          const char* type,
                                                          Element bag );
extern ThotBool Template_CanInsertElementInUse ( Document doc,
                                                   ElementType type,
                                                   char* useType,
                                                   Element parent,
                                                   int position );
extern ThotBool Template_IsUsedComponent ( XTigerTemplate t,
                                             Document doc,
                                             const char* name );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
