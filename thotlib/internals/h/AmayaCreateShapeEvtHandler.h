#ifdef _WX

#ifndef __AMAYACREATESHAPEEVTHANDLER_H__
#define __AMAYACREATESHAPEEVTHANDLER_H__

#include "wx/wx.h"
#include "wx/event.h"

#include "thot_gui.h"
#include "thot_sys.h"
#include "constmedia.h"
#include "typeint.h"

class AmayaFrame;

class AmayaCreateShapeEvtHandler : public wxEvtHandler
{
 public:
  DECLARE_DYNAMIC_CLASS(AmayaCreateShapeEvtHandler)

  AmayaCreateShapeEvtHandler();
  AmayaCreateShapeEvtHandler(AmayaFrame * p_frame,
			     Document doc, void *transform,
			     int ancestorX,
			     int ancestorY,
			     int canvasWidth,
			     int canvasHeight,
			     int shape_number,
			     int *x1, int *y1, int *x2, int *y2,
			     ThotBool *created);
  virtual ~AmayaCreateShapeEvtHandler();

  bool IsFinish();

 protected:
  DECLARE_EVENT_TABLE()
  void OnKeyDown( wxKeyEvent& event );
  void OnMouseMove( wxMouseEvent& event );
  void OnMouseWheel( wxMouseEvent& event );
  void OnMouseDbClick( wxMouseEvent& event );
  void OnMouseUp( wxMouseEvent& event );
  void OnMouseDown( wxMouseEvent& event );
  void DrawShape ();

 protected:
  bool finished;

  AmayaFrame * pFrame;
  int frameId;
  int document;
  void *transform;
  int x0, y0, width, height;
  int shape;
  int *px1,*py1,*px2,*py2;
  ThotBool *created;
  int nb_points;
};

#endif /* __AMAYACREATESHAPEEVTHANDLER_H__ */

#endif /* #ifdef _WX */
