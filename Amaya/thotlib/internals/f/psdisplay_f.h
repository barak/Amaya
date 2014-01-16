/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern void DrawChar ( char car,
                       int frame,
                       int x,
                       int y,
                       ThotFont font,
                       int fg );
extern int DrawString ( unsigned char *buff,
                        int lg,
                        int frame,
                        int x,
                        int y,
                        ThotFont font,
                        int boxWidth,
                        int bl,
                        int hyphen,
                        int startABlock,
                        int fg );
extern int WDrawString ( wchar_t *buff,
                         int lg,
                         int frame,
                         int x,
                         int y,
                         ThotFont font,
                         int boxWidth,
                         int bl,
                         int hyphen,
                         int startABlock,
                         int fg );
extern void DisplayUnderline ( int frame,
                               int x,
                               int y,
                               int h,
                               int type,
                               int lg,
                               int fg );
extern void DrawRadical ( int frame,
                          int thick,
                          int x,
                          int y,
                          int l,
                          int h,
                          ThotFont font,
                          int fg );
extern void DrawIntegral ( int frame,
                           int thick,
                           int x,
                           int y,
                           int l,
                           int h,
                           int type,
                           ThotFont font,
                           int fg );
extern void DrawSigma ( int frame,
                        int x,
                        int y,
                        int l,
                        int h,
                        ThotFont font,
                        int fg );
extern void DrawPi ( int frame,
                     int x,
                     int y,
                     int l,
                     int h,
                     ThotFont font,
                     int fg );
extern void DrawUnion ( int frame,
                        int x,
                        int y,
                        int l,
                        int h,
                        ThotFont font,
                        int fg );
extern void DrawIntersection ( int frame,
                               int x,
                               int y,
                               int l,
                               int h,
                               ThotFont font,
                               int fg );
extern void DrawArrow ( int frame,
                        int thick,
                        int style,
                        int x,
                        int y,
                        int l,
                        int h,
                        int direction,
                        int type,
                        int fg );
extern void DrawBracket ( int frame,
                          int thick,
                          int x,
                          int y,
                          int l,
                          int h,
                          int direction,
                          ThotFont font,
                          int fg,
                          int baseline );
extern void DrawPointyBracket ( int frame,
                                int thick,
                                int x,
                                int y,
                                int l,
                                int h,
                                int direction,
                                ThotFont font,
                                int fg );
extern void DrawParenthesis ( int frame,
                              int thick,
                              int x,
                              int y,
                              int l,
                              int h,
                              int direction,
                              ThotFont font,
                              int fg,
                              int baseline );
extern void DrawBrace ( int frame,
                        int thick,
                        int x,
                        int y,
                        int l,
                        int h,
                        int direction,
                        ThotFont font,
                        int fg,
                        int baseline );
extern void DrawRectangle ( int frame,
                            int thick,
                            int style,
                            int x,
                            int y,
                            int width,
                            int height,
                            int fg,
                            int bg,
                            int pattern );
extern void DrawSegments ( int frame,
                           int thick,
                           int style,
                           int x,
                           int y,
                           PtrTextBuffer buffer,
                           int nb,
                           int fg,
                           int arrow,
                           int bg,
                           int pattern );
extern void DrawPolygon ( int frame,
                          int thick,
                          int style,
                          int x,
                          int y,
                          PtrTextBuffer buffer,
                          int nb,
                          int fg,
                          int bg,
                          int pattern,
                          int mode );
extern void DrawCurve ( int frame,
                        int thick,
                        int style,
                        int x,
                        int y,
                        PtrTextBuffer buffer,
                        int nb,
                        int fg,
                        int arrow,
                        C_points *controls );
extern void DrawSpline ( int frame,
                         int thick,
                         int style,
                         int x,
                         int y,
                         PtrTextBuffer buffer,
                         int nb,
                         int fg,
                         int bg,
                         int pattern,
                         C_points *controls );
extern void DrawPath ( int frame,
                       int thick,
                       int style,
                       int x,
                       int y,
                       PtrPathSeg path,
                       int fg,
                       int bg,
                       int pattern,
                       int mode );
extern void DrawDiamond ( int frame,
                          int thick,
                          int style,
                          int x,
                          int y,
                          int width,
                          int height,
                          int fg,
                          int bg,
                          int pattern );
extern void DrawOval ( int frame,
                       int thick,
                       int style,
                       int x,
                       int y,
                       int width,
                       int height,
                       int rx,
                       int ry,
                       int fg,
                       int bg,
                       int pattern );
extern void DrawEllips ( int frame,
                         int thick,
                         int style,
                         int x,
                         int y,
                         int width,
                         int height,
                         int fg,
                         int bg,
                         int pattern );
extern void DrawCorner ( int frame,
                         int thick,
                         int style,
                         int x,
                         int y,
                         int l,
                         int h,
                         int corner,
                         int fg );
extern void DrawRectangleFrame ( int frame,
                                 int thick,
                                 int style,
                                 int x,
                                 int y,
                                 int width,
                                 int height,
                                 int fg,
                                 int bg,
                                 int pattern );
extern void DrawEllipsFrame ( int frame,
                              int thick,
                              int style,
                              int x,
                              int y,
                              int width,
                              int height,
                              int fg,
                              int bg,
                              int pattern );
extern void DrawHorizontalLine ( int frame,
                                 int thick,
                                 int style,
                                 int x,
                                 int y,
                                 int l,
                                 int h,
                                 int align,
                                 int fg,
                                 PtrBox box,
                                 int leftslice,
                                 int rightslice );
extern void DrawVerticalLine ( int frame,
                               int thick,
                               int style,
                               int x,
                               int y,
                               int l,
                               int h,
                               int align,
                               int fg,
                               PtrBox box,
                               int topslice,
                               int bottomslice );
extern void DrawHat ( int frame,
                      int thick,
                      int style,
                      int x,
                      int y,
                      int l,
                      int h,
                      int fg,
                      int direction );
extern void DrawTilde ( int frame,
                        int thick,
                        int style,
                        int x,
                        int y,
                        int l,
                        int h,
                        int fg );
extern void DrawHorizontalParenthesis ( int frame,
                                        int thick,
                                        int style,
                                        int x,
                                        int y,
                                        int l,
                                        int h,
                                        int align,
                                        int fg );
extern void DrawHorizontalBrace ( int frame,
                                  int thick,
                                  int style,
                                  int x,
                                  int y,
                                  int l,
                                  int h,
                                  int align,
                                  int fg );
extern void DrawHorizontalBracket ( int frame,
                                    int thick,
                                    int style,
                                    int x,
                                    int y,
                                    int l,
                                    int h,
                                    int align,
                                    int fg );
extern void DrawPoints ( int frame,
                         int x,
                         int y,
                         int boxWidth,
                         int fg );
extern void DrawSlash ( int frame,
                        int thick,
                        int style,
                        int x,
                        int y,
                        int l,
                        int h,
                        int direction,
                        int fg );
extern void PaintWithPattern ( int frame,
                               int x,
                               int y,
                               int width,
                               int height,
                               ThotWindow w,
                               int fg,
                               int bg,
                               int pattern );

#else /* __STDC__ */

extern void DrawChar ( char car,
                         int frame,
                         int x,
                         int y,
                         ThotFont font,
                         int fg );
extern int DrawString ( unsigned char *buff,
                          int lg,
                          int frame,
                          int x,
                          int y,
                          ThotFont font,
                          int boxWidth,
                          int bl,
                          int hyphen,
                          int startABlock,
                          int fg );
extern int WDrawString ( wchar_t *buff,
                           int lg,
                           int frame,
                           int x,
                           int y,
                           ThotFont font,
                           int boxWidth,
                           int bl,
                           int hyphen,
                           int startABlock,
                           int fg );
extern void DisplayUnderline ( int frame,
                                 int x,
                                 int y,
                                 int h,
                                 int type,
                                 int lg,
                                 int fg );
extern void DrawRadical ( int frame,
                            int thick,
                            int x,
                            int y,
                            int l,
                            int h,
                            ThotFont font,
                            int fg );
extern void DrawIntegral ( int frame,
                             int thick,
                             int x,
                             int y,
                             int l,
                             int h,
                             int type,
                             ThotFont font,
                             int fg );
extern void DrawSigma ( int frame,
                          int x,
                          int y,
                          int l,
                          int h,
                          ThotFont font,
                          int fg );
extern void DrawPi ( int frame,
                       int x,
                       int y,
                       int l,
                       int h,
                       ThotFont font,
                       int fg );
extern void DrawUnion ( int frame,
                          int x,
                          int y,
                          int l,
                          int h,
                          ThotFont font,
                          int fg );
extern void DrawIntersection ( int frame,
                                 int x,
                                 int y,
                                 int l,
                                 int h,
                                 ThotFont font,
                                 int fg );
extern void DrawArrow ( int frame,
                          int thick,
                          int style,
                          int x,
                          int y,
                          int l,
                          int h,
                          int direction,
                          int type,
                          int fg );
extern void DrawBracket ( int frame,
                            int thick,
                            int x,
                            int y,
                            int l,
                            int h,
                            int direction,
                            ThotFont font,
                            int fg,
                            int baseline );
extern void DrawPointyBracket ( int frame,
                                  int thick,
                                  int x,
                                  int y,
                                  int l,
                                  int h,
                                  int direction,
                                  ThotFont font,
                                  int fg );
extern void DrawParenthesis ( int frame,
                                int thick,
                                int x,
                                int y,
                                int l,
                                int h,
                                int direction,
                                ThotFont font,
                                int fg,
                                int baseline );
extern void DrawBrace ( int frame,
                          int thick,
                          int x,
                          int y,
                          int l,
                          int h,
                          int direction,
                          ThotFont font,
                          int fg,
                          int baseline );
extern void DrawRectangle ( int frame,
                              int thick,
                              int style,
                              int x,
                              int y,
                              int width,
                              int height,
                              int fg,
                              int bg,
                              int pattern );
extern void DrawSegments ( int frame,
                             int thick,
                             int style,
                             int x,
                             int y,
                             PtrTextBuffer buffer,
                             int nb,
                             int fg,
                             int arrow,
                             int bg,
                             int pattern );
extern void DrawPolygon ( int frame,
                            int thick,
                            int style,
                            int x,
                            int y,
                            PtrTextBuffer buffer,
                            int nb,
                            int fg,
                            int bg,
                            int pattern,
                            int mode );
extern void DrawCurve ( int frame,
                          int thick,
                          int style,
                          int x,
                          int y,
                          PtrTextBuffer buffer,
                          int nb,
                          int fg,
                          int arrow,
                          C_points *controls );
extern void DrawSpline ( int frame,
                           int thick,
                           int style,
                           int x,
                           int y,
                           PtrTextBuffer buffer,
                           int nb,
                           int fg,
                           int bg,
                           int pattern,
                           C_points *controls );
extern void DrawPath ( int frame,
                         int thick,
                         int style,
                         int x,
                         int y,
                         PtrPathSeg path,
                         int fg,
                         int bg,
                         int pattern,
                         int mode );
extern void DrawDiamond ( int frame,
                            int thick,
                            int style,
                            int x,
                            int y,
                            int width,
                            int height,
                            int fg,
                            int bg,
                            int pattern );
extern void DrawOval ( int frame,
                         int thick,
                         int style,
                         int x,
                         int y,
                         int width,
                         int height,
                         int rx,
                         int ry,
                         int fg,
                         int bg,
                         int pattern );
extern void DrawEllips ( int frame,
                           int thick,
                           int style,
                           int x,
                           int y,
                           int width,
                           int height,
                           int fg,
                           int bg,
                           int pattern );
extern void DrawCorner ( int frame,
                           int thick,
                           int style,
                           int x,
                           int y,
                           int l,
                           int h,
                           int corner,
                           int fg );
extern void DrawRectangleFrame ( int frame,
                                   int thick,
                                   int style,
                                   int x,
                                   int y,
                                   int width,
                                   int height,
                                   int fg,
                                   int bg,
                                   int pattern );
extern void DrawEllipsFrame ( int frame,
                                int thick,
                                int style,
                                int x,
                                int y,
                                int width,
                                int height,
                                int fg,
                                int bg,
                                int pattern );
extern void DrawHorizontalLine ( int frame,
                                   int thick,
                                   int style,
                                   int x,
                                   int y,
                                   int l,
                                   int h,
                                   int align,
                                   int fg,
                                   PtrBox box,
                                   int leftslice,
                                   int rightslice );
extern void DrawVerticalLine ( int frame,
                                 int thick,
                                 int style,
                                 int x,
                                 int y,
                                 int l,
                                 int h,
                                 int align,
                                 int fg,
                                 PtrBox box,
                                 int topslice,
                                 int bottomslice );
extern void DrawHat ( int frame,
                        int thick,
                        int style,
                        int x,
                        int y,
                        int l,
                        int h,
                        int fg,
                        int direction );
extern void DrawTilde ( int frame,
                          int thick,
                          int style,
                          int x,
                          int y,
                          int l,
                          int h,
                          int fg );
extern void DrawHorizontalParenthesis ( int frame,
                                          int thick,
                                          int style,
                                          int x,
                                          int y,
                                          int l,
                                          int h,
                                          int align,
                                          int fg );
extern void DrawHorizontalBrace ( int frame,
                                    int thick,
                                    int style,
                                    int x,
                                    int y,
                                    int l,
                                    int h,
                                    int align,
                                    int fg );
extern void DrawHorizontalBracket ( int frame,
                                      int thick,
                                      int style,
                                      int x,
                                      int y,
                                      int l,
                                      int h,
                                      int align,
                                      int fg );
extern void DrawPoints ( int frame,
                           int x,
                           int y,
                           int boxWidth,
                           int fg );
extern void DrawSlash ( int frame,
                          int thick,
                          int style,
                          int x,
                          int y,
                          int l,
                          int h,
                          int direction,
                          int fg );
extern void PaintWithPattern ( int frame,
                                 int x,
                                 int y,
                                 int width,
                                 int height,
                                 ThotWindow w,
                                 int fg,
                                 int bg,
                                 int pattern );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */
