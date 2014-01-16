/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void CallbackImage ( int ref,
                            int typedata,
                            char *data );
extern void InitImage ( void );
extern char *GetImageURL ( Document document,
                           View view );
extern void ChangeBackgroundImage ( Document document,
                                    View view );
extern void ComputeSRCattribute ( Element el,
                                  Document doc,
                                  Document sourceDocument,
                                  Attribute attr,
                                  char *text );
extern void UpdateSRCattribute ( NotifyElement * event );
extern void SRCattrModified ( NotifyAttribute * event );
extern void CreateImage ( Document document,
                          View view );
extern boolean AddLocalImage ( char *fullname,
                               char *name,
                               char *url,
                               Document doc,
                               LoadedImageDesc ** desc );
extern void RemoveDocumentImages ( Document doc );
extern void UpdateImageMap ( Element image,
                             Document document );

#else /* __STDC__ */

extern void CallbackImage (/* int ref,
                              int typedata,
                              char *data */);
extern void InitImage (/* void */);
extern char *GetImageURL (/* Document document,
                             View view */);
extern void ChangeBackgroundImage (/* Document document,
                                      View view */);
extern void ComputeSRCattribute (/* Element el,
                                    Document doc,
                                    Document sourceDocument,
                                    Attribute attr,
                                    char *text */);
extern void UpdateSRCattribute (/* NotifyElement * event */);
extern void SRCattrModified (/* NotifyAttribute * event */);
extern void CreateImage (/* Document document,
                            View view */);
extern boolean AddLocalImage (/* char *fullname,
                                 char *name,
                                 char *url,
                                 Document doc,
                                 LoadedImageDesc ** desc */);
extern void RemoveDocumentImages (/* Document doc */);
extern void UpdateImageMap (/* Element image,
                               Document document */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
