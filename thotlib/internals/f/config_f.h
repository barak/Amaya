/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void ConfigInit ( void );
extern void TtaConfigReadConfigFiles ( char *aSchemaPath );
extern int ConfigMakeDocTypeMenu ( char *BufMenu,
                                   int *lgmenu,
                                   boolean doc );
extern void TtaConfigSSchemaExternalName ( char *nameUser,
                                           char *nameSchema,
                                           int Typ );
extern void ConfigSSchemaInternalName ( char *nameUser,
                                        char *nameSchema,
                                        boolean Doc );
extern int ConfigMakeMenuPres ( char *schema,
                                char *BufMenu );
extern void ConfigGetPSchemaName ( int choix,
                                   char *schpres );
extern int ConfigMakeImportMenu ( char *BufMenu );
extern int ConfigMakeMenuExport ( char *schema,
                                  char *BufMenu );
extern void ConfigGetExportSchemaName ( int choix,
                                        char *schtrad );
extern void ConfigTranslateSSchema ( PtrSSchema pSS );
extern boolean ConfigDefaultPSchema ( char *schstr,
                                      char *schpres );
extern void ConfigKeyboard ( int *x,
                             int *y );
extern void ConfigOpenFirstViews ( PtrDocument pDoc );
extern void ConfigGetViewGeometry ( PtrDocument pDoc,
                                    char *view,
                                    int *x,
                                    int *y,
                                    int *width,
                                    int *height );
extern void TtaGetViewGeometry ( Document document,
                                 char *name,
                                 int *x,
                                 int *y,
                                 int *width,
                                 int *height );
extern boolean ConfigGetPSchemaNature ( PtrSSchema pSS,
                                        char *nameNature,
                                        char *presNature );
extern void ConfigGetPresentationOption ( PtrSSchema pSS,
                                          char *optionName,
                                          char *optionValue );
extern void ConfigGetPSchemaForPageSize ( PtrSSchema pSS,
                                          char *pageSize,
                                          char *schemaName );
extern int MakeMenuPattern ( char *BufMenu,
                             int LgMax );
extern int MakeMenuColor ( char *BufMenu,
                           int LgMax );
extern boolean ConfigDefaultTypoSchema ( PtrSSchema pSS,
                                         char *nameNature,
                                         char *schtypo );

#else /* __STDC__ */

extern void ConfigInit (/* void */);
extern void TtaConfigReadConfigFiles (/* char *aSchemaPath */);
extern int ConfigMakeDocTypeMenu (/* char *BufMenu,
                                     int *lgmenu,
                                     boolean doc */);
extern void TtaConfigSSchemaExternalName (/* char *nameUser,
                                             char *nameSchema,
                                             int Typ */);
extern void ConfigSSchemaInternalName (/* char *nameUser,
                                          char *nameSchema,
                                          boolean Doc */);
extern int ConfigMakeMenuPres (/* char *schema,
                                  char *BufMenu */);
extern void ConfigGetPSchemaName (/* int choix,
                                     char *schpres */);
extern int ConfigMakeImportMenu (/* char *BufMenu */);
extern int ConfigMakeMenuExport (/* char *schema,
                                    char *BufMenu */);
extern void ConfigGetExportSchemaName (/* int choix,
                                          char *schtrad */);
extern void ConfigTranslateSSchema (/* PtrSSchema pSS */);
extern boolean ConfigDefaultPSchema (/* char *schstr,
                                        char *schpres */);
extern void ConfigKeyboard (/* int *x,
                               int *y */);
extern void ConfigOpenFirstViews (/* PtrDocument pDoc */);
extern void ConfigGetViewGeometry (/* PtrDocument pDoc,
                                      char *view,
                                      int *x,
                                      int *y,
                                      int *width,
                                      int *height */);
extern void TtaGetViewGeometry (/* Document document,
                                   char *name,
                                   int *x,
                                   int *y,
                                   int *width,
                                   int *height */);
extern boolean ConfigGetPSchemaNature (/* PtrSSchema pSS,
                                          char *nameNature,
                                          char *presNature */);
extern void ConfigGetPresentationOption (/* PtrSSchema pSS,
                                            char *optionName,
                                            char *optionValue */);
extern void ConfigGetPSchemaForPageSize (/* PtrSSchema pSS,
                                            char *pageSize,
                                            char *schemaName */);
extern int MakeMenuPattern (/* char *BufMenu,
                               int LgMax */);
extern int MakeMenuColor (/* char *BufMenu,
                             int LgMax */);
extern boolean ConfigDefaultTypoSchema (/* PtrSSchema pSS,
                                           char *nameNature,
                                           char *schtypo */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */