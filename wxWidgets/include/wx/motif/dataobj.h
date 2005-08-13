///////////////////////////////////////////////////////////////////////////////
// Name:        wx/motif/dataobj.h
// Purpose:     declaration of the wxDataObject class for Motif
// Author:      Julian Smart
// RCS-ID:      $Id: dataobj.h,v 1.1.1.1 2005/07/06 09:30:10 gully Exp $
// Copyright:   (c) 1998 Julian Smart
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MOTIF_DATAOBJ_H_
#define _WX_MOTIF_DATAOBJ_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dataobj.h"
#endif

// ----------------------------------------------------------------------------
// wxDataObject is the same as wxDataObjectBase under wxMotif
// ----------------------------------------------------------------------------

class wxDataObject : public wxDataObjectBase
{
public:
    virtual ~wxDataObject();
};

#endif //_WX_MOTIF_DATAOBJ_H_

