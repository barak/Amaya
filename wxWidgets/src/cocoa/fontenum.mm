/////////////////////////////////////////////////////////////////////////////
// Name:        src/cocoa/fontenum.mm
// Purpose:     wxFontEnumerator class for Cocoa
// Author:      David Elliott
// Modified by:
// Created:     2003/07/23
// RCS-ID:      $Id: fontenum.mm,v 1.1.1.1 2005/07/06 09:30:49 gully Exp $
// Copyright:   (c) David Elliott
// Licence:     wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#endif

#include "wx/fontenum.h"

bool wxFontEnumerator::EnumerateFacenames(wxFontEncoding encoding,
                                          bool fixedWidthOnly)
{
    return false;
}

bool wxFontEnumerator::EnumerateEncodings(const wxString& family)
{
    return false;
}

