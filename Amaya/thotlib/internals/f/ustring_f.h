/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern wchar_t Ttowlower ( wchar_t wc );
extern int ustrcasecmp ( const CHAR_T *str1,
                         const CHAR_T *str2 );
extern CHAR_T *ustrcat ( CHAR_T *dest,
                         const CHAR_T *src );
extern CHAR_T *ustrchr ( const CHAR_T *src,
                         CHAR_T c );
extern int ustrcmp ( const CHAR_T *str1,
                     const CHAR_T *str2 );
extern CHAR_T *ustrcpy ( CHAR_T *dest,
                         const CHAR_T *src );
extern size_t ustrlen ( const CHAR_T *str );
extern int ustrncasecmp ( const CHAR_T *str1,
                          const CHAR_T *str2,
                          unsigned int count );
extern CHAR_T *ustrncat ( CHAR_T *dest,
                          const CHAR_T *src,
                          unsigned int count );
extern CHAR_T *ustrncmp ( const CHAR_T *str1,
                          const CHAR_T *str2,
                          unsigned int count );
extern CHAR_T *ustrncpy ( CHAR_T *dest,
                          const CHAR_T *src,
                          unsigned int count );
extern CHAR_T *ustrrchr ( const CHAR_T *str,
                          CHAR_T c );
extern CHAR_T *ustrtok ( CHAR_T *str,
                         const CHAR_T *delemiter );
extern CHAR_T *ustrstr ( const CHAR_T *str,
                         const CHAR_T *strCharSet );
extern CHARSET TtaGetCharset ( char *charsetname );
extern CHARSET TtaGetLocaleCharset ( void );
extern CHARSET TtaGetDefaultCharset ( void );
extern char *TtaGetCharsetName ( CHARSET charset );

#else /* __STDC__ */

extern wchar_t Ttowlower ( wchar_t wc );
extern int ustrcasecmp ( const CHAR_T *str1,
                           const CHAR_T *str2 );
extern CHAR_T *ustrcat ( CHAR_T *dest,
                           const CHAR_T *src );
extern CHAR_T *ustrchr ( const CHAR_T *src,
                           CHAR_T c );
extern int ustrcmp ( const CHAR_T *str1,
                       const CHAR_T *str2 );
extern CHAR_T *ustrcpy ( CHAR_T *dest,
                           const CHAR_T *src );
extern size_t ustrlen ( const CHAR_T *str );
extern int ustrncasecmp ( const CHAR_T *str1,
                            const CHAR_T *str2,
                            unsigned int count );
extern CHAR_T *ustrncat ( CHAR_T *dest,
                            const CHAR_T *src,
                            unsigned int count );
extern CHAR_T *ustrncmp ( const CHAR_T *str1,
                            const CHAR_T *str2,
                            unsigned int count );
extern CHAR_T *ustrncpy ( CHAR_T *dest,
                            const CHAR_T *src,
                            unsigned int count );
extern CHAR_T *ustrrchr ( const CHAR_T *str,
                            CHAR_T c );
extern CHAR_T *ustrtok ( CHAR_T *str,
                           const CHAR_T *delemiter );
extern CHAR_T *ustrstr ( const CHAR_T *str,
                           const CHAR_T *strCharSet );
extern CHARSET TtaGetCharset ( char *charsetname );
extern CHARSET TtaGetLocaleCharset ( void );
extern CHARSET TtaGetDefaultCharset ( void );
extern char *TtaGetCharsetName ( CHARSET charset );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */