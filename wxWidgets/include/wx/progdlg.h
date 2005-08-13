/////////////////////////////////////////////////////////////////////////////
// Name:        wx/progdlg.h
// Purpose:     Base header for wxProgressDialog
// Author:      Julian Smart
// Modified by:
// Created:
// RCS-ID:      $Id: progdlg.h,v 1.1.1.1 2005/07/06 09:30:08 gully Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWindows Licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_PROGDLG_H_BASE_
#define _WX_PROGDLG_H_BASE_

#include "wx/defs.h"

#ifdef __WXPALMOS__
    #include "wx/palmos/progdlg.h"
#else
    #include "wx/generic/progdlgg.h"
#endif

#endif // _WX_PROGDLG_H_BASE_
