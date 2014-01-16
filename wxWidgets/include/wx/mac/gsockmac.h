/*
 Name:        wx/gsockmac.h
 Purpose:     GSocket base header
 Author:      Stefan Csomor
 Modified by:
 Created:
 Copyright:   (c) Stefan Csomor
 RCS-ID:      $Id: gsockmac.h,v 1.1.1.1 2005/07/06 09:30:09 gully Exp $
 Licence:     wxWindows Licence
*/

#ifdef __WXMAC_CLASSIC__
#include "wx/mac/classic/gsockmac.h"
#else
#include "wx/mac/carbon/gsockmac.h"
#endif