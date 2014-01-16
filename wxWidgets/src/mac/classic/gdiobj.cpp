/////////////////////////////////////////////////////////////////////////////
// Name:        gdiobj.cpp
// Purpose:     wxGDIObject class
// Author:      Stefan Csomor
// Modified by:
// Created:     1998-01-01
// RCS-ID:      $Id: gdiobj.cpp,v 1.1.1.1 2005/07/06 09:30:54 gully Exp $
// Copyright:   (c) Stefan Csomor
// Licence:       wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "gdiobj.h"
#endif

#include "wx/gdiobj.h"

#if !USE_SHARED_LIBRARIES
IMPLEMENT_DYNAMIC_CLASS(wxGDIObject, wxObject)
#endif

// TODO: Nothing to do, unless you want to.
