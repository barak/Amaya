/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void FindOutColor ( Display * dsp,
                           Colormap colormap,
                           ThotColorStruct * colr );
extern void InitDocColors ( char *name );
extern unsigned long ColorPixel ( int num );
extern void TtaGiveThotRGB ( int num,
                             unsigned short *red,
                             unsigned short *green,
                             unsigned short *blue );
extern unsigned long CreatePattern ( int disp,
                                     int RO,
                                     int active,
                                     int fg,
                                     int bg,
                                     int pattern );

#else /* __STDC__ */

extern void FindOutColor (/* Display * dsp,
                             Colormap colormap,
                             ThotColorStruct * colr */);
extern void InitDocColors (/* char *name */);
extern unsigned long ColorPixel (/* int num */);
extern void TtaGiveThotRGB (/* int num,
                               unsigned short *red,
                               unsigned short *green,
                               unsigned short *blue */);
extern unsigned long CreatePattern (/* int disp,
                                       int RO,
                                       int active,
                                       int fg,
                                       int bg,
                                       int pattern */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
