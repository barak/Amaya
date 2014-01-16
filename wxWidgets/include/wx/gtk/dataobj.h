///////////////////////////////////////////////////////////////////////////////
// Name:        gtk/dataobj.h
// Purpose:     declaration of the wxDataObject
// Author:      Robert Roebling
// RCS-ID:      $Id: dataobj.h,v 1.1.1.1 2005/07/06 09:30:09 gully Exp $
// Copyright:   (c) 1998, 1999 Vadim Zeitlin, Robert Roebling
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_GTK_DATAOBJ_H_
#define _WX_GTK_DATAOBJ_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma interface "dataobj.h"
#endif

// ----------------------------------------------------------------------------
// wxDataObject is the same as wxDataObjectBase under wxGTK
// ----------------------------------------------------------------------------

class wxDataObject : public wxDataObjectBase
{
public:
    wxDataObject();
    virtual ~wxDataObject();

    virtual bool IsSupportedFormat( const wxDataFormat& format, Direction dir = Get ) const;
};

#endif // _WX_GTK_DATAOBJ_H_

