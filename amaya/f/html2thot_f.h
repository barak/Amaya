/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void ParseAreaCoords ( Element element,
                              Document document );
extern int MapGI ( char *gi,
                   SSchema *schema );
extern void GIType ( char *gi,
                     ElementType *elType,
                     Document doc );
extern char *GITagNameByType ( ElementType elType );
extern char *GITagName ( Element elem );
extern int MapThotAttr ( char *Attr,
                         char *tag );
extern int MapAttrValue ( int ThotAtt,
                          char *AttrVal );
extern void InitMapping ( void );
extern void ParseHTMLError ( Document doc,
                             unsigned char *msg );
extern boolean IsCharacterLevelElement ( Element el );
extern void OnlyOneOptionSelected ( Element el,
                                    Document doc,
                                    boolean parsing );
extern void SetAttrIntItemStyle ( Element el,
                                  Document doc );
extern void CreateAttrWidthPercentPxl ( char *buffer,
                                        Element el,
                                        Document doc );
extern void CreateAttrIntSize ( char *buffer,
                                Element el,
                                Document doc );
extern void InitAutomaton ( void );
extern char GetNextInputChar ( void );
extern void HTMLparse ( FILE * infile,
                        char *HTMLbuf );
extern void ReadTextFile ( FILE * infile,
                           char *textbuf );
extern void CheckAbstractTree ( char *pathURL );
extern void InitializeParser ( Element lastelem,
                               boolean isclosed,
                               Document doc );
extern void StartHTMLParser ( Document doc,
                              char *htmlFileName,
                              char *documentName,
                              char *documentDirectory,
                              char *pathURL,
                              boolean PlainText );

#else /* __STDC__ */

extern void ParseAreaCoords (/* Element element,
                                Document document */);
extern int MapGI (/* char *gi,
                     SSchema *schema */);
extern void GIType (/* char *gi,
                       ElementType *elType,
                       Document doc */);
extern char *GITagNameByType (/* ElementType elType */);
extern char *GITagName (/* Element elem */);
extern int MapThotAttr (/* char *Attr,
                           char *tag */);
extern int MapAttrValue (/* int ThotAtt,
                            char *AttrVal */);
extern void InitMapping (/* void */);
extern void ParseHTMLError (/* Document doc,
                               unsigned char *msg */);
extern boolean IsCharacterLevelElement (/* Element el */);
extern void OnlyOneOptionSelected (/* Element el,
                                      Document doc,
                                      boolean parsing */);
extern void SetAttrIntItemStyle (/* Element el,
                                    Document doc */);
extern void CreateAttrWidthPercentPxl (/* char *buffer,
                                          Element el,
                                          Document doc */);
extern void CreateAttrIntSize (/* char *buffer,
                                  Element el,
                                  Document doc */);
extern void InitAutomaton (/* void */);
extern char GetNextInputChar (/* void */);
extern void HTMLparse (/* FILE * infile,
                          char *HTMLbuf */);
extern void ReadTextFile (/* FILE * infile,
                             char *textbuf */);
extern void CheckAbstractTree (/* char *pathURL */);
extern void InitializeParser (/* Element lastelem,
                                 boolean isclosed,
                                 Document doc */);
extern void StartHTMLParser (/* Document doc,
                                char *htmlFileName,
                                char *documentName,
                                char *documentDirectory,
                                char *pathURL,
                                boolean PlainText */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
