/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern int XpmCreateImageFromBuffer ( Display * display,
                                      char *buffer,
                                      XImage ** image_return,
                                      XImage ** shapeimage_return,
                                      XpmAttributes * attributes );
extern int XpmCreateXpmImageFromBuffer ( char *buffer,
                                         XpmImage * image,
                                         XpmInfo * info );

#else /* __STDC__ */

extern int XpmCreateImageFromBuffer (/* Display * display,
                                        char *buffer,
                                        XImage ** image_return,
                                        XImage ** shapeimage_return,
                                        XpmAttributes * attributes */);
extern int XpmCreateXpmImageFromBuffer (/* char *buffer,
                                           XpmImage * image,
                                           XpmInfo * info */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */