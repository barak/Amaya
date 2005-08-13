/////////////////////////////////////////////////////////////////////////////
// Name:        print.h
// Purpose:     wxPrinter, wxPrintPreview classes
// Author:      David Webster
// Modified by:
// Created:     10/14/99
// RCS-ID:      $Id: print.h,v 1.1.1.1 2005/07/06 09:30:10 gully Exp $
// Copyright:   (c) David Webster
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_PRINT_H_
#define _WX_PRINT_H_

#include "wx/prntbase.h"

/*
 * Represents the printer: manages printing a wxPrintout object
 */

class WXDLLEXPORT wxOS2Printer: public wxPrinterBase
{
  DECLARE_DYNAMIC_CLASS(wxPrinter)

 public:
  wxOS2Printer(wxPrintData *data = NULL);
  ~wxOS2Printer();

  virtual bool Print(wxWindow *parent, wxPrintout *printout, bool prompt = TRUE);
  virtual wxDC* PrintDialog(wxWindow *parent);
  virtual bool Setup(wxWindow *parent);
private:
};

/*
 * wxPrintPreview
 * Programmer creates an object of this class to preview a wxPrintout.
 */

class WXDLLEXPORT wxOS2PrintPreview: public wxPrintPreviewBase
{
  DECLARE_CLASS(wxPrintPreview)

 public:
  wxOS2PrintPreview(wxPrintout *printout, wxPrintout *printoutForPrinting = NULL, wxPrintData *data = NULL);
  ~wxOS2PrintPreview();

  virtual bool Print(bool interactive);
  virtual void DetermineScaling();
};

#endif
    // _WX_PRINT_H_
