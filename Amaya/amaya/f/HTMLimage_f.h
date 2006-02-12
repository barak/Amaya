/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern ThotBool AddLoadedImage ( char *name,
                                 char *pathname,
                                 Document doc,
                                 LoadedImageDesc **desc );
extern LoadedImageDesc *SearchLoadedImage ( char *localpath,
                                            Document doc );
extern LoadedImageDesc *SearchLoadedDocImage ( Document doc,
                                               char *url );
extern void SetAreaCoords ( Document document,
                            Element element,
                            int attrNum,
                            Element image );
extern void UpdateImageMap ( Element image,
                             Document doc,
                             int oldWidth,
                             int oldHeight );
extern void SetAttrOnElement ( Document doc,
                               Element el,
                               int attrNum,
                               int value );
extern void DisplayImage ( Document doc,
                           Element el,
                           LoadedImageDesc *desc,
                           char *localfile,
                           char *mime_type );
extern void SetContainerImageName ( char *imagefile );
extern char *GetActiveImageInfo ( Document document,
                                  Element element );
extern ThotBool FetchImage ( Document doc,
                             Element el,
                             char *imageURI,
                             int flags,
                             LoadedImageCallback callback,
                             void *extra );
extern ThotBool FetchAndDisplayImages ( Document doc,
                                        int flags,
                                        Element elSubTree );
extern ThotBool SelectPicture ( NotifyElement *event );
extern ThotBool DeletePicture ( NotifyElement *event );

#else /* __STDC__ */

extern ThotBool AddLoadedImage ( char *name,
                                   char *pathname,
                                   Document doc,
                                   LoadedImageDesc **desc );
extern LoadedImageDesc *SearchLoadedImage ( char *localpath,
                                              Document doc );
extern LoadedImageDesc *SearchLoadedDocImage ( Document doc,
                                                 char *url );
extern void SetAreaCoords ( Document document,
                              Element element,
                              int attrNum,
                              Element image );
extern void UpdateImageMap ( Element image,
                               Document doc,
                               int oldWidth,
                               int oldHeight );
extern void SetAttrOnElement ( Document doc,
                                 Element el,
                                 int attrNum,
                                 int value );
extern void DisplayImage ( Document doc,
                             Element el,
                             LoadedImageDesc *desc,
                             char *localfile,
                             char *mime_type );
extern void SetContainerImageName ( char *imagefile );
extern char *GetActiveImageInfo ( Document document,
                                    Element element );
extern ThotBool FetchImage ( Document doc,
                               Element el,
                               char *imageURI,
                               int flags,
                               LoadedImageCallback callback,
                               void *extra );
extern ThotBool FetchAndDisplayImages ( Document doc,
                                          int flags,
                                          Element elSubTree );
extern ThotBool SelectPicture ( NotifyElement *event );
extern ThotBool DeletePicture ( NotifyElement *event );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
