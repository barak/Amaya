/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void MovingCommands ( int code );
extern void TtcPreviousChar ( Document document,
                              View view );
extern void TtcNextChar ( Document document,
                          View view );
extern void TtcPreviousLine ( Document document,
                              View view );
extern void TtcNextLine ( Document document,
                          View view );
extern void TtcStartOfLine ( Document document,
                             View view );
extern void TtcEndOfLine ( Document document,
                           View view );
extern int CopyXClipboard ( unsigned char **buffer );
extern void TtcCopyToClipboard ( Document document,
                                 View view );

#else /* __STDC__ */

extern void MovingCommands (/* int code */);
extern void TtcPreviousChar (/* Document document,
                                View view */);
extern void TtcNextChar (/* Document document,
                            View view */);
extern void TtcPreviousLine (/* Document document,
                                View view */);
extern void TtcNextLine (/* Document document,
                            View view */);
extern void TtcStartOfLine (/* Document document,
                               View view */);
extern void TtcEndOfLine (/* Document document,
                             View view */);
extern int CopyXClipboard (/* unsigned char **buffer */);
extern void TtcCopyToClipboard (/* Document document,
                                   View view */);

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */