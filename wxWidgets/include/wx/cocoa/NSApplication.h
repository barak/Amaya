///////////////////////////////////////////////////////////////////////////////
// Name:        wx/cocoa/NSApplication.h
// Purpose:     wxNSApplicationDelegate definition
// Author:      David Elliott
// Modified by:
// Created:     2004/01/26
// RCS-ID:      $Id: NSApplication.h,v 1.1.1.1 2005/07/06 09:30:08 gully Exp $
// Copyright:   (c) 2003,2004 David Elliott
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_COCOA_NSAPPLICATION_H__
#define _WX_COCOA_NSAPPLICATION_H__

// ========================================================================
// wxNSApplicationDelegate
// ========================================================================
@interface wxNSApplicationDelegate : NSObject
{
}

// Delegate methods
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication;
- (void)applicationWillBecomeActive:(NSNotification *)notification;
- (void)applicationDidBecomeActive:(NSNotification *)notification;
- (void)applicationWillResignActive:(NSNotification *)notification;
- (void)applicationDidResignActive:(NSNotification *)notification;

// Other notifications
- (void)controlTintChanged:(NSNotification *)notification;
@end // interface wxNSApplicationDelegate : NSObject

#endif //ndef _WX_COCOA_NSAPPLICATION_H__
