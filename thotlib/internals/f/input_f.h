/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__
extern int ThotInput ( int frame,
                       unsigned int value,
                       int command,
                       int modifiers,
                       int key,
                       ThotBool isKey );
extern void FreeTranslations ( void );
extern void TtaSetAccessKeyFunction ( Proc2 procedure );
extern void TtaAddAccessKey ( Document doc,
                              unsigned int key,
                              void *param );
extern void TtaRemoveDocAccessKeys ( Document doc );
extern void TtaRemoveAccessKey ( Document doc,
                                 unsigned int key );
extern void TtaCloseShortcutSequence ( void );
extern ThotBool TtaInShortcutSequence ( void );
extern void TtaListShortcuts ( Document doc,
                               FILE *fileDescriptor );
extern void InitTranslations ( char *appliname );

#else /* __STDC__ */
extern int ThotInput ( int frame,
                         unsigned int value,
                         int command,
                         int modifiers,
                         int key,
                         ThotBool isKey );
extern void FreeTranslations ( void );
extern void TtaSetAccessKeyFunction ( Proc2 procedure );
extern void TtaAddAccessKey ( Document doc,
                                unsigned int key,
                                void *param );
extern void TtaRemoveDocAccessKeys ( Document doc );
extern void TtaRemoveAccessKey ( Document doc,
                                   unsigned int key );
extern void TtaCloseShortcutSequence ( void );
extern ThotBool TtaInShortcutSequence ( void );
extern void TtaListShortcuts ( Document doc,
                                 FILE *fileDescriptor );
extern void InitTranslations ( char *appliname );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
