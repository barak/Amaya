/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern Drawable XpmCreate ( char *fn,
                            PictureScaling pres,
                            int *xif,
                            int *yif,
                            int *wif,
                            int *hif,
                            unsigned long BackGroundPixel,
                            Drawable *mask1,
                            int *width,
                            int *height,
                            int zoom );
extern void XpmPrint ( char *fn,
                       PictureScaling pres,
                       int xif,
                       int yif,
                       int wif,
                       int hif,
                       int PicXArea,
                       int PicYArea,
                       int PicWArea,
                       int PicHArea,
                       int fd,
                       unsigned long BackGroundPixel );
extern boolean IsXpmFormat ( char *fn );

#else /* __STDC__ */

extern Drawable XpmCreate (/* char *fn,
                              PictureScaling pres,
                              int *xif,
                              int *yif,
                              int *wif,
                              int *hif,
                              unsigned long BackGroundPixel,
                              Drawable *mask1,
                              int *width,
                              int *height,
                              int zoom */);
extern void XpmPrint (/* char *fn,
                         PictureScaling pres,
                         int xif,
                         int yif,
                         int wif,
                         int hif,
                         int PicXArea,
                         int PicYArea,
                         int PicWArea,
                         int PicHArea,
                         int fd,
                         unsigned long BackGroundPixel */);
extern boolean IsXpmFormat (/* char *fn */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
