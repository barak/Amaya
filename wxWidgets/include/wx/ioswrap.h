///////////////////////////////////////////////////////////////////////////////
// Name:        wx/ioswrap.h
// Purpose:     includes the correct iostream headers for current compiler
// Author:      Vadim Zeitlin
// Modified by:
// Created:     03.02.99
// RCS-ID:      $Id: ioswrap.h,v 1.1.1.1 2005/07/06 09:30:08 gully Exp $
// Copyright:   (c) 1998 Vadim Zeitlin <zeitlin@dptmaths.ens-cachan.fr>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#if wxUSE_STD_IOSTREAM

#if wxUSE_IOSTREAMH
#   include <iostream.h>
#else
#   include <iostream>
#endif

#ifdef __WXMSW__
#   include "wx/msw/winundef.h"
#endif

#endif
  // wxUSE_STD_IOSTREAM

