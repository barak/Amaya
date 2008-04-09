/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern int NumberOfFonts ( void );
extern int GetCharsCapacity ( int volpixel,
                              int frame );
extern int CharacterWidth ( int c,
                            ThotFont font );
extern int SpecialCharBoxWidth ( CHAR_T c );
extern int BoxCharacterWidth ( CHAR_T c,
                               int variant,
                               SpecFont specfont );
extern int CharacterHeight ( int c,
                             ThotFont font );
extern int CharacterAscent ( int c,
                             ThotFont font );
extern int FontAscent ( ThotFont font );
extern int FontHeight ( ThotFont font );
extern int BoxFontHeight ( SpecFont specfont,
                           char code );
extern int PixelValue ( int val,
                        TypeUnit unit,
                        PtrAbstractBox pAb,
                        int zoom );
extern int LogicalValue ( int val,
                          TypeUnit unit,
                          PtrAbstractBox pAb,
                          int zoom );
extern int FontBase ( ThotFont font );
extern int BoxFontBase ( SpecFont specfont );
extern int FontRelSize ( int size );
extern int ThotFontPointSize ( int size );
extern void GetFontIdentifier ( char script,
                                int family,
                                int highlight,
                                int size,
                                TypeUnit unit,
                                char text[10],
                                char textX[100] );
extern ThotFont ReadFont ( char script,
                           int family,
                           int highlight,
                           int size,
                           TypeUnit unit );
extern char *GetPostscriptNameFromFont ( void * font,
                                         char *fontname );
extern ThotFont LoadNearestFont ( char script,
                                  int family,
                                  int highlight,
                                  int size,
                                  int requestedsize,
                                  int frame,
                                  ThotBool increase,
                                  ThotBool decrease );
extern void *LoadStixFont ( int family,
                            int size );
extern void ChangeFontsetSize ( int size,
                                PtrBox box,
                                int frame );
extern int GetFontAndIndexFromSpec ( CHAR_T c,
                                     SpecFont fontset,
                                     int variant,
                                     ThotFont *font );
extern SpecFont ThotLoadFont ( char script,
                               int family,
                               int highlight,
                               int size,
                               TypeUnit unit,
                               int frame );
extern void TtaSetFontZoom ( int zoom );
extern void InitDialogueFonts ( const char *name );
extern void ThotFreeFont ( int frame );
extern void ThotFreeAllFonts ( void );
extern void LoadingArabicFont ( SpecFont fontset,
                                ThotFont *font );
extern int Char_Width ( int x );
extern void Put_Char_Width ( int car,
                             int l );
extern int BoxArabicCharacterWidth ( CHAR_T c,
                                     PtrTextBuffer *adbuff,
                                     int *ind,
                                     SpecFont specfont );

#else /* __STDC__ */

extern int NumberOfFonts ( void );
extern int GetCharsCapacity ( int volpixel,
                                int frame );
extern int CharacterWidth ( int c,
                              ThotFont font );
extern int SpecialCharBoxWidth ( CHAR_T c );
extern int BoxCharacterWidth ( CHAR_T c,
                                 int variant,
                                 SpecFont specfont );
extern int CharacterHeight ( int c,
                               ThotFont font );
extern int CharacterAscent ( int c,
                               ThotFont font );
extern int FontAscent ( ThotFont font );
extern int FontHeight ( ThotFont font );
extern int BoxFontHeight ( SpecFont specfont,
                             char code );
extern int PixelValue ( int val,
                          TypeUnit unit,
                          PtrAbstractBox pAb,
                          int zoom );
extern int LogicalValue ( int val,
                            TypeUnit unit,
                            PtrAbstractBox pAb,
                            int zoom );
extern int FontBase ( ThotFont font );
extern int BoxFontBase ( SpecFont specfont );
extern int FontRelSize ( int size );
extern int ThotFontPointSize ( int size );
extern void GetFontIdentifier ( char script,
                                  int family,
                                  int highlight,
                                  int size,
                                  TypeUnit unit,
                                  char text[10],
                                  char textX[100] );
extern ThotFont ReadFont ( char script,
                             int family,
                             int highlight,
                             int size,
                             TypeUnit unit );
extern char *GetPostscriptNameFromFont ( void * font,
                                           char *fontname );
extern ThotFont LoadNearestFont ( char script,
                                    int family,
                                    int highlight,
                                    int size,
                                    int requestedsize,
                                    int frame,
                                    ThotBool increase,
                                    ThotBool decrease );
extern void *LoadStixFont ( int family,
                              int size );
extern void ChangeFontsetSize ( int size,
                                  PtrBox box,
                                  int frame );
extern int GetFontAndIndexFromSpec ( CHAR_T c,
                                       SpecFont fontset,
                                       int variant,
                                       ThotFont *font );
extern SpecFont ThotLoadFont ( char script,
                                 int family,
                                 int highlight,
                                 int size,
                                 TypeUnit unit,
                                 int frame );
extern void TtaSetFontZoom ( int zoom );
extern void InitDialogueFonts ( const char *name );
extern void ThotFreeFont ( int frame );
extern void ThotFreeAllFonts ( void );
extern void LoadingArabicFont ( SpecFont fontset,
                                  ThotFont *font );
extern int Char_Width ( int x );
extern void Put_Char_Width ( int car,
                               int l );
extern int BoxArabicCharacterWidth ( CHAR_T c,
                                       PtrTextBuffer *adbuff,
                                       int *ind,
                                       SpecFont specfont );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
