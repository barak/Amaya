/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern boolean TtaReadByte ( BinFile file,
                             char *bval );
extern boolean TtaReadBool ( BinFile file,
                             boolean * bval );
extern boolean TtaReadShort ( BinFile file,
                              int *sval );
extern boolean TtaReadSignedShort ( BinFile file,
                                    int *sval );
extern boolean TtaReadInteger ( BinFile file,
                                int *sval );
extern boolean TtaReadName ( BinFile file,
                             char *name );
extern BinFile TtaReadOpen ( CONST char *filename );
extern void TtaReadClose ( BinFile file );
extern BinFile TtaWriteOpen ( CONST char *filename );
extern void TtaWriteClose ( BinFile file );
extern boolean TtaWriteByte ( BinFile file,
                              char bval );
extern boolean TtaWriteShort ( BinFile file,
                               int sval );
extern boolean TtaWriteInteger ( BinFile file,
                                 int lval );
extern void TtaWriteDocIdent ( BinFile file,
                               DocumentIdentifier Ident );
extern void TtaReadDocIdent ( BinFile file,
                              DocumentIdentifier * Ident );
extern void CopyDocIdent ( DocumentIdentifier * Dest,
                           DocumentIdentifier Source );
extern boolean SameDocIdent ( DocumentIdentifier Ident1,
                              DocumentIdentifier Ident2 );
extern void ClearDocIdent ( DocumentIdentifier * Ident );
extern boolean DocIdentIsNull ( DocumentIdentifier Ident );
extern void MakeCompleteName ( char *fname,
                               char *fext,
                               PathBuffer directory_list,
                               PathBuffer completeName,
                               int *length );
extern void GetPictureFileName ( char *name,
                                 char *fileName );
extern void FindCompleteName ( char *fileName,
                               char *extension,
                               PathBuffer directory,
                               PathBuffer completeName,
                               int *length );
extern void GetDocIdent ( DocumentIdentifier *Ident,
                          Name docName );
extern void GetDocName ( DocumentIdentifier Ident,
                         Name docName );
extern int FileWriteAccess ( char *fileName );
extern void GetCounterValue ( int number,
                              CounterStyle style,
                              char *string,
                              int *len );

#else /* __STDC__ */

extern boolean TtaReadByte (/* BinFile file,
                               char *bval */);
extern boolean TtaReadBool (/* BinFile file,
                               boolean * bval */);
extern boolean TtaReadShort (/* BinFile file,
                                int *sval */);
extern boolean TtaReadSignedShort (/* BinFile file,
                                      int *sval */);
extern boolean TtaReadInteger (/* BinFile file,
                                  int *sval */);
extern boolean TtaReadName (/* BinFile file,
                               char *name */);
extern BinFile TtaReadOpen (/* CONST char *filename */);
extern void TtaReadClose (/* BinFile file */);
extern BinFile TtaWriteOpen (/* CONST char *filename */);
extern void TtaWriteClose (/* BinFile file */);
extern boolean TtaWriteByte (/* BinFile file,
                                char bval */);
extern boolean TtaWriteShort (/* BinFile file,
                                 int sval */);
extern boolean TtaWriteInteger (/* BinFile file,
                                   int lval */);
extern void TtaWriteDocIdent (/* BinFile file,
                                 DocumentIdentifier Ident */);
extern void TtaReadDocIdent (/* BinFile file,
                                DocumentIdentifier * Ident */);
extern void CopyDocIdent (/* DocumentIdentifier * Dest,
                             DocumentIdentifier Source */);
extern boolean SameDocIdent (/* DocumentIdentifier Ident1,
                                DocumentIdentifier Ident2 */);
extern void ClearDocIdent (/* DocumentIdentifier * Ident */);
extern boolean DocIdentIsNull (/* DocumentIdentifier Ident */);
extern void MakeCompleteName (/* char *fname,
                                 char *fext,
                                 PathBuffer directory_list,
                                 PathBuffer completeName,
                                 int *length */);
extern void GetPictureFileName (/* char *name,
                                   char *fileName */);
extern void FindCompleteName (/* char *fileName,
                                 char *extension,
                                 PathBuffer directory,
                                 PathBuffer completeName,
                                 int *length */);
extern void GetDocIdent (/* DocumentIdentifier *Ident,
                            Name docName */);
extern void GetDocName (/* DocumentIdentifier Ident,
                           Name docName */);
extern int FileWriteAccess (/* char *fileName */);
extern void GetCounterValue (/* int number,
                                CounterStyle style,
                                char *string,
                                int *len */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
