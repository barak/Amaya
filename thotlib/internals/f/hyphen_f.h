/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern boolean IsSeparatorChar ( char c );
extern void SmallLettering ( char *word );
extern int HyphenLastWord ( ptrfont font,
                            Language language,
                            PtrTextBuffer * buffer,
                            int *rank,
                            int *width,
                            boolean * hyphen );
extern boolean CanHyphen ( PtrBox pBox );

#else /* __STDC__ */

extern boolean IsSeparatorChar (/* char c */);
extern void SmallLettering (/* char *word */);
extern int HyphenLastWord (/* ptrfont font,
                              Language language,
                              PtrTextBuffer * buffer,
                              int *rank,
                              int *width,
                              boolean * hyphen */);
extern boolean CanHyphen (/* PtrBox pBox */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
