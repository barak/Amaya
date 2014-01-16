/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

#ifndef __CEXTRACT__
#ifdef __STDC__

extern int TtaGridDoAlign ( int value );
extern void BoxGeometry ( int frame,
                          int x,
                          int y,
                          int width,
                          int height,
                          int xr,
                          int yr );
extern void InvertEllipse ( int frame,
                            int x,
                            int y,
                            int width,
                            int height,
                            int xr,
                            int yr );
extern void GeometryResize ( int frame,
                             int x,
                             int y,
                             int *width,
                             int *height,
                             PtrBox box,
                             int xmin,
                             int xmax,
                             int ymin,
                             int ymax,
                             int xm,
                             int ym,
                             int percentW,
                             int percentH );
extern void GeometryMove ( int frame,
                           int *x,
                           int *y,
                           int width,
                           int height,
                           PtrBox box,
                           int xmin,
                           int xmax,
                           int ymin,
                           int ymax,
                           int xm,
                           int ym );
extern void GeometryCreate ( int frame,
                             int *x,
                             int *y,
                             int *width,
                             int *height,
                             int xmin,
                             int xmax,
                             int ymin,
                             int ymax,
                             PtrBox box,
                             int PosX,
                             int PosY,
                             int DimX,
                             int DimY,
                             int percentW,
                             int percentH );
extern void GetArrowCoord ( int *x1,
                            int *y1,
                            int *x2,
                            int *y2 );
extern ThotBool ShapeCreation ( int frame,
                                Document doc,
                                void *inverseCTM,
                                PtrBox svgBox,
                                int ancestorX,
                                int ancestorY,
                                int shape,
                                int *x1,
                                int *y1,
                                int *x2,
                                int *y2,
                                int *x3,
                                int *y3,
                                int *x4,
                                int *y4,
                                int *lx,
                                int *ly );
extern ThotBool TransformSVG ( int frame,
                               Document doc,
                               void *CTM,
                               void *inverse,
                               PtrBox svgBox,
                               int ancestorX,
                               int ancestorY,
                               int transform_type,
                               Element el );
extern ThotBool ShapeEdit ( int frame,
                            Document doc,
                            void *inverse,
                            PtrBox svgBox,
                            int ancestorX,
                            int ancestorY,
                            Element el,
                            int point_edited );
extern ThotBool PathEdit ( int frame,
                           Document doc,
                           void *inverse,
                           PtrBox svgBox,
                           int ancestorX,
                           int ancestorY,
                           Element el,
                           int point_edited );
extern ThotBool PathCreation ( int frame,
                               Document doc,
                               void *inverse,
                               PtrBox svgBox,
                               int ancestorX,
                               int ancestorY,
                               int shape,
                               Element el );
extern ThotBool MouseCoordinatesToSVG ( Document doc,
                                        AmayaFrame *p_frame,
                                        int x0,
                                        int y0,
                                        int width,
                                        int height,
                                        void *inverseCTM,
                                        ThotBool convert,
                                        char *msg,
                                        int *x,
                                        int *y,
                                        ThotBool displayCoordinates );
extern void SVGToMouseCoordinates ( Document doc,
                                    AmayaFrame *p_frame,
                                    int x0,
                                    int y0,
                                    int width,
                                    int height,
                                    void *CTM,
                                    float x,
                                    float y,
                                    int *newx,
                                    int *newy );
extern void ApproximateAngleOfLine ( int T,
                                     int x1,
                                     int y1,
                                     int *x2,
                                     int *y2 );

#else /* __STDC__ */

extern int TtaGridDoAlign ( int value );
extern void BoxGeometry ( int frame,
                            int x,
                            int y,
                            int width,
                            int height,
                            int xr,
                            int yr );
extern void InvertEllipse ( int frame,
                              int x,
                              int y,
                              int width,
                              int height,
                              int xr,
                              int yr );
extern void GeometryResize ( int frame,
                               int x,
                               int y,
                               int *width,
                               int *height,
                               PtrBox box,
                               int xmin,
                               int xmax,
                               int ymin,
                               int ymax,
                               int xm,
                               int ym,
                               int percentW,
                               int percentH );
extern void GeometryMove ( int frame,
                             int *x,
                             int *y,
                             int width,
                             int height,
                             PtrBox box,
                             int xmin,
                             int xmax,
                             int ymin,
                             int ymax,
                             int xm,
                             int ym );
extern void GeometryCreate ( int frame,
                               int *x,
                               int *y,
                               int *width,
                               int *height,
                               int xmin,
                               int xmax,
                               int ymin,
                               int ymax,
                               PtrBox box,
                               int PosX,
                               int PosY,
                               int DimX,
                               int DimY,
                               int percentW,
                               int percentH );
extern void GetArrowCoord ( int *x1,
                              int *y1,
                              int *x2,
                              int *y2 );
extern ThotBool ShapeCreation ( int frame,
                                  Document doc,
                                  void *inverseCTM,
                                  PtrBox svgBox,
                                  int ancestorX,
                                  int ancestorY,
                                  int shape,
                                  int *x1,
                                  int *y1,
                                  int *x2,
                                  int *y2,
                                  int *x3,
                                  int *y3,
                                  int *x4,
                                  int *y4,
                                  int *lx,
                                  int *ly );
extern ThotBool TransformSVG ( int frame,
                                 Document doc,
                                 void *CTM,
                                 void *inverse,
                                 PtrBox svgBox,
                                 int ancestorX,
                                 int ancestorY,
                                 int transform_type,
                                 Element el );
extern ThotBool ShapeEdit ( int frame,
                              Document doc,
                              void *inverse,
                              PtrBox svgBox,
                              int ancestorX,
                              int ancestorY,
                              Element el,
                              int point_edited );
extern ThotBool PathEdit ( int frame,
                             Document doc,
                             void *inverse,
                             PtrBox svgBox,
                             int ancestorX,
                             int ancestorY,
                             Element el,
                             int point_edited );
extern ThotBool PathCreation ( int frame,
                                 Document doc,
                                 void *inverse,
                                 PtrBox svgBox,
                                 int ancestorX,
                                 int ancestorY,
                                 int shape,
                                 Element el );
extern ThotBool MouseCoordinatesToSVG ( Document doc,
                                          AmayaFrame *p_frame,
                                          int x0,
                                          int y0,
                                          int width,
                                          int height,
                                          void *inverseCTM,
                                          ThotBool convert,
                                          char *msg,
                                          int *x,
                                          int *y,
                                          ThotBool displayCoordinates );
extern void SVGToMouseCoordinates ( Document doc,
                                      AmayaFrame *p_frame,
                                      int x0,
                                      int y0,
                                      int width,
                                      int height,
                                      void *CTM,
                                      float x,
                                      float y,
                                      int *newx,
                                      int *newy );
extern void ApproximateAngleOfLine ( int T,
                                       int x1,
                                       int y1,
                                       int *x2,
                                       int *y2 );

#endif /* __STDC__ */
#endif /* __CEXTRACT__ */