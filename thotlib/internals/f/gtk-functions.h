/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 */

extern gboolean CharTranslationGTK (GtkWidget *w, GdkEventKey *event, gpointer data);
extern gboolean KeyScrolledGTK (GtkWidget *w, GdkEvent* event, gpointer data);
extern gboolean CallTextEnterGTK (ThotWidget w,  GdkEventButton *bu, gpointer data);

extern void FrameToView (int frame,
                          int *doc,
                          int *view);
extern void FrameToRedisplay (ThotWindow w,
                               int frame,
                               void *ev);
extern gboolean FrameResizedGTK (GtkWidget *w, GdkEventConfigure *event, gpointer data);

extern void FrameHScrolledGTK (GtkAdjustment *w,
                             int frame);
extern void FrameVScrolledGTK (GtkAdjustment *w,
                             int frame);
extern void TtcLineUp (Document document,
                        View view);
extern void TtcLineDown (Document document,
                          View view);
extern void TtcPageUp (Document document,
                        View view);
extern void TtcPageDown (Document document,
                          View view);
extern void TtcPageTop (Document document,
                         View view);
extern void TtcPageEnd (Document document,
                         View view);
extern void InitializeOtherThings (void);
extern void TtaRaiseView (Document document,
                           View view);
extern void DisplaySelMessage (char *text,
                                PtrDocument pDoc);
extern void TtaSetStatus (Document document,
                           View view,
                           char *text,
                           char *name);
/*extern void FrameCallback (int frame,
  void *evnt);*/
extern gboolean FrameCallbackGTK (GtkWidget *widget, GdkEventButton *event,
				  gpointer data);
extern void ThotGrab (ThotWindow win,
                       ThotCursor cursor,
                       long events,
                       int disp);
extern void ThotUngrab (void);
extern ThotWindow TtaGetThotWindow (int frame);
extern void SetCursorWatch (int thotThotWindowid);
extern void ResetCursorWatch (int thotThotWindowid);
extern void TtaSetCursorWatch (Document document,
                                View view);
extern void TtaResetCursor (Document document,
                             View view);
extern void GiveClickedAbsBox (int *frame,
                                PtrAbstractBox *pave);
extern void ChangeFrameTitle (int frame, unsigned char *text, CHARSET encoding);
extern void ChangeSelFrame (int frame);
extern int GetWindowFrame (ThotWindow w);
extern void GetSizesFrame (int frame,
                            int *width,
                            int *height);
extern void DefineClipping (int frame,
                             int orgx,
                             int orgy,
                             int *xd,
                             int *yd,
                             int *xf,
                             int *yf,
                             int raz);
extern void RemoveClipping (int frame);
extern void UpdateScrollbars (int frame);


extern int ThotInput (int frame, unsigned int value, int command,
                      int mask, int key, ThotBool iskey);
extern void FreeTranslations (void);
extern void InitTranslations (char *appliname);

extern gboolean APP_TextCallbackGTK (GtkWidget *w, int frame);

extern gint ExposeCallbackGTK (ThotWidget widget, GdkEventExpose *event, gpointer data);



extern gboolean DragCallbackGTK (GtkWidget *widget,
				 GdkDragContext *drag_context,
				 gint x,
				 gint y,
				 guint time,
				 gpointer user_data);
gboolean KillFrameGTK (GtkWidget *widget,
		       GdkEvent *event,
		       gpointer frame);

gboolean FocusInCallbackGTK (GtkWidget *widget,
			     GdkEventFocus *event,
			     gpointer user_data);

gboolean FocusOutCallbackGTK (GtkWidget *widget,
			      GdkEventFocus *event,
			      gpointer user_data);
gboolean LeaveCallbackGTK (GtkWidget *widget,
			   GdkEventCrossing *event,
			   gpointer user_data);
gboolean EnterCallbackGTK (GtkWidget *widget,
			   GdkEventCrossing *event,
			   gpointer user_data);
void ConnectSignalGTK (GtkObject *w, gchar *signal_name, GtkSignalFunc callback, gpointer data);
void ConnectSignalAfterGTK (GtkObject *w, gchar *signal_name, GtkSignalFunc callback, 
			    gpointer data);


void RemoveSignalGTK (GtkObject *w, gchar *signal_name);



gboolean ButtonPressCallbackGTK (GtkWidget *widget,
				 GdkEventButton *event,
				 gpointer user_data);

gboolean ButtonReleaseCallbackGTK (GtkWidget *widget,
				   GdkEventButton *event,
				   gpointer user_data);

gboolean ColorsExposeGTK (GtkWidget *widget, GdkEventExpose *ev, gpointer data);
gboolean ColorsExposeFgBgGTK (GtkWidget *widget, GdkEventExpose *ev, gpointer data);
void ButtonFgToggledGTK (GtkWidget *w, GdkEventButton *event, gpointer data);
void ButtonBgToggledGTK (GtkWidget *w, GdkEventButton *event, gpointer data);
gboolean ColorsPressGTK (GtkWidget *widget, gpointer data);
gboolean CreateExtendedColorSelectionGTK (GtkWidget *widget, gpointer data);
gboolean CloseExtendedColorSelectionGTK (GtkWidget *widget, gpointer data);
void gtk_claim_selection();

ThotBool formKillGTK (GtkWidget *w, GdkEvent *ev, struct Cat_Context *catalogue);
ThotBool scr_popup_button_press (GtkWidget *w, GdkEventButton *ev, 
				 struct Cat_Context *catalogue);
ThotBool scr_popup_key_press (GtkWidget *w, GdkEventKey *ev,
			      struct Cat_Context *catalogue);
ThotBool ListEventGTK (GtkWidget *w, GdkEventButton *ev, 
		       struct Cat_Context *catalogue);
gboolean CallSheetGTK (ThotWidget w, struct Cat_Context *catalogue);
ThotBool CallListGTK (ThotWidget w, struct Cat_Context *catalogue);
gboolean DeletePopShell (ThotWidget w, GdkEventButton *bu, gpointer data);
gboolean CallTextEnterGTK (ThotWidget w, GdkEventButton *bu, gpointer data);
ThotBool CallTextChangeGTK (ThotWidget w, struct Cat_Context *catalogue);
ThotBool CallRadioGTK (ThotWidget w, struct Cat_Context *catalogue);
ThotBool CallIconButtonGTK (ThotWidget w, struct Cat_Context *catalogue);
void CallValueSet (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d);
ThotBool CallToggleGTK (ThotWidget w, struct Cat_Context *catalogue);
ThotBool CallLabel (ThotWidget w, struct Cat_Context *catalogue, caddr_t call_d);
ThotBool ComboBoxGTK (ThotWidget w, struct Cat_Context *catalogue, 
		      caddr_t call_d);
