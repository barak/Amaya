/* File generated by app - do not edit! */
/* #################################### */
/* Included files */
#include "string.h"
#include "thot_gui.h"
#include "thot_sys.h"
#include "application.h"
#include "appstruct.h"
#include "interface.h"
#include "Topics.h"

/*----------------------------------------------------------------------
 -----------------------------------------------------------------------*/
void TopicsApplicationInitialise ()
{
 PtrEventsSet appliActions;

  /* Create the new application context*/
  appliActions = TteNewEventsSet (15355, "Topics");
   /* Generate event/action entries */
  TteAddActionEvent (appliActions, 0, TteElemMenu, 1, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteElemNew, 1, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteElemDelete, 1, "BM_ItemDelete");
  TteAddActionEvent (appliActions, 0, TteElemRClick, 1, "BM_ShowProperties");
  TteAddActionEvent (appliActions, 0, TteElemActivate, 1, "BM_FollowBookmark");
  TteAddActionEvent (appliActions, 0, TteElemInclude, 1, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteElemCopy, 1, "BM_Copy");
  TteAddActionEvent (appliActions, 0, TteElemCopy, 0, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteElemPaste, 1, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteElemTextModify, 1, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteElemTextModify, 1, "BM_IgnoreEvent");
  TteAddActionEvent (appliActions, 0, TteDocClose, 0, "DocumentClosed");

}

/*########## Init Appplication action-list #################*/
extern ThotBool BM_ShowProperties (NotifyElement *event);
extern ThotBool BM_FollowBookmark (NotifyElement *event);
extern ThotBool BM_ItemDelete (NotifyElement *event);
extern ThotBool BM_Copy (NotifyElement *event);
extern void DocumentClosed (NotifyDialog *event);
extern ThotBool BM_IgnoreEvent (NotifyOnTarget *event);
void TopicsActionListInit ()
{
  TteAddAction ("BM_ShowProperties", (Proc)BM_ShowProperties);
  TteAddAction ("BM_FollowBookmark", (Proc)BM_FollowBookmark);
  TteAddAction ("BM_ItemDelete", (Proc)BM_ItemDelete);
  TteAddAction ("BM_Copy", (Proc)BM_Copy);
  TteAddAction ("DocumentClosed", (Proc)DocumentClosed);
  TteAddAction ("BM_IgnoreEvent", (Proc)BM_IgnoreEvent);
}

void TopicsLoadResources ()
{
  TopicsActionListInit ();
  TopicsApplicationInitialise ();
}

