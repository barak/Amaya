/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void LoadDocument ( PtrDocument * pDoc,
                           char *fileName );
extern void NewDocument ( PtrDocument * pDoc,
                          PtrBuffer SSchemaName,
                          Name docName,
                          PathBuffer directory );
extern void SetAccessMode ( PtrDocument pDoc,
                            int accessMode );
extern void UnloadTree ( Document document );
extern void UnloadDocument ( PtrDocument * pDoc );
extern void PaginateDocument ( PtrDocument pDoc );
extern void DocumentModified ( PtrDocument pDoc,
                               PtrElement pEl );
extern void UpdateIncludedElement ( PtrElement pEl,
                                    PtrDocument pDoc );
extern boolean StoreDocument ( PtrDocument pDoc,
                               Name docName,
                               PathBuffer dirName,
                               boolean copy,
                               boolean move );
extern boolean WriteDocument ( PtrDocument pDoc,
                               int mode );

#else /* __STDC__ */

extern void LoadDocument (/* PtrDocument * pDoc,
                             char *fileName */);
extern void NewDocument (/* PtrDocument * pDoc,
                            PtrBuffer SSchemaName,
                            Name docName,
                            PathBuffer directory */);
extern void SetAccessMode (/* PtrDocument pDoc,
                              int accessMode */);
extern void UnloadTree (/* Document document */);
extern void UnloadDocument (/* PtrDocument * pDoc */);
extern void PaginateDocument (/* PtrDocument pDoc */);
extern void DocumentModified (/* PtrDocument pDoc,
                                 PtrElement pEl */);
extern void UpdateIncludedElement (/* PtrElement pEl,
                                      PtrDocument pDoc */);
extern boolean StoreDocument (/* PtrDocument pDoc,
                                 Name docName,
                                 PathBuffer dirName,
                                 boolean copy,
                                 boolean move */);
extern boolean WriteDocument (/* PtrDocument pDoc,
                                 int mode */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */