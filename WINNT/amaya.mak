# Microsoft Developer Studio Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=amaya - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to amaya - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "amaya - Win32 Release" && "$(CFG)" != "amaya - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Amaya.mak" CFG="amaya - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "amaya - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "amaya - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "amaya - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "amaya - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\bin"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\.\bin
INTDIR=.\Release

ALL : "$(OUTDIR)\Amaya.exe"

CLEAN : 
	-@erase ".\bin\Amaya.exe"
	-@erase ".\Release\AHTMemConv.obj"
	-@erase ".\Release\MathMLAPP.obj"
	-@erase ".\Release\html2thot.obj"
	-@erase ".\Release\HTMLactions.obj"
	-@erase ".\Release\AHTBridge.obj"
	-@erase ".\Release\HTEvntrg.obj"
	-@erase ".\Release\AHTFWrite.obj"
	-@erase ".\Release\HTBInit.obj"
	-@erase ".\Release\HTMLtable.obj"
	-@erase ".\Release\css.obj"
	-@erase ".\Release\HTMLhistory.obj"
	-@erase ".\Release\UIcss.obj"
	-@erase ".\Release\AHTEvntrg.obj"
	-@erase ".\Release\answer.obj"
	-@erase ".\Release\HTMLpresentation.obj"
	-@erase ".\Release\javaamaya.obj"
	-@erase ".\Release\trans.obj"
	-@erase ".\Release\HTMLAPP.obj"
	-@erase ".\Release\p2css.obj"
	-@erase ".\Release\query.obj"
	-@erase ".\Release\transparse.obj"
	-@erase ".\Release\HTMLedit.obj"
	-@erase ".\Release\HTMLstyle.obj"
	-@erase ".\Release\HTMLimage.obj"
	-@erase ".\Release\EDITstyle.obj"
	-@erase ".\Release\EDITimage.obj"
	-@erase ".\Release\AHTURLTools.obj"
	-@erase ".\Release\init.obj"
	-@erase ".\Release\HTMLsave.obj"
	-@erase ".\Release\windialogapi.obj"
	-@erase ".\Release\EDITORAPP.obj"
	-@erase ".\Release\HTMLform.obj"
	-@erase ".\Release\EDITORactions.obj"
	-@erase ".\Release\HTMLbook.obj"
	-@erase ".\Release\Mathedit.obj"
	-@erase ".\Release\HTInit.obj"
	-@erase ".\Release\amaya.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /I "..\thotlib\include" /I "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I "..\thotlib\internals\f" /I "..\amaya\f" /I "..\w3c-libwww-5.0a\Library\src" /I "..\libpng\zlib" /I "..\amaya" /I "..\winnt\amaya" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "COUGAR" /D "__STDC__" /D "WWW_WIN_ASYNC" /D "WWW_WIN_DLL" /D "SOCKS" /D "MATHML" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /I "..\thotlib\include" /I\
 "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I\
 "..\thotlib\internals\f" /I "..\amaya\f" /I "..\w3c-libwww-5.0a\Library\src" /I\
 "..\libpng\zlib" /I "..\amaya" /I "..\winnt\amaya" /D "NDEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "COUGAR" /D "__STDC__" /D "WWW_WIN_ASYNC" /D "WWW_WIN_DLL" /D\
 "SOCKS" /D "MATHML" /Fp"$(INTDIR)/Amaya.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/amaya.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Amaya.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib wsock32.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib comctl32.lib wsock32.lib /nologo /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)/amaya.pdb" /machine:I386\
 /out:"$(OUTDIR)/amaya.exe" 
LINK32_OBJS= \
	"$(INTDIR)/AHTMemConv.obj" \
	"$(INTDIR)/MathMLAPP.obj" \
	"$(INTDIR)/html2thot.obj" \
	"$(INTDIR)/HTMLactions.obj" \
	"$(INTDIR)/AHTBridge.obj" \
	"$(INTDIR)/HTEvntrg.obj" \
	"$(INTDIR)/AHTFWrite.obj" \
	"$(INTDIR)/HTBInit.obj" \
	"$(INTDIR)/HTMLtable.obj" \
	"$(INTDIR)/css.obj" \
	"$(INTDIR)/HTMLhistory.obj" \
	"$(INTDIR)/UIcss.obj" \
	"$(INTDIR)/AHTEvntrg.obj" \
	"$(INTDIR)/answer.obj" \
	"$(INTDIR)/HTMLpresentation.obj" \
	"$(INTDIR)/javaamaya.obj" \
	"$(INTDIR)/trans.obj" \
	"$(INTDIR)/HTMLAPP.obj" \
	"$(INTDIR)/p2css.obj" \
	"$(INTDIR)/query.obj" \
	"$(INTDIR)/transparse.obj" \
	"$(INTDIR)/HTMLedit.obj" \
	"$(INTDIR)/HTMLstyle.obj" \
	"$(INTDIR)/HTMLimage.obj" \
	"$(INTDIR)/EDITstyle.obj" \
	"$(INTDIR)/EDITimage.obj" \
	"$(INTDIR)/AHTURLTools.obj" \
	"$(INTDIR)/init.obj" \
	"$(INTDIR)/HTMLsave.obj" \
	"$(INTDIR)/windialogapi.obj" \
	"$(INTDIR)/EDITORAPP.obj" \
	"$(INTDIR)/HTMLform.obj" \
	"$(INTDIR)/EDITORactions.obj" \
	"$(INTDIR)/HTMLbook.obj" \
	"$(INTDIR)/Mathedit.obj" \
	"$(INTDIR)/HTInit.obj" \
	"$(INTDIR)/amaya.res" \
	"..\w3c-libwww-5.0a\Bin\wwwhtml.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwdll.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwfile.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwmime.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwhttp.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwcore.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwutils.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwwais.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwstream.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwapp.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwnews.lib" \
	".\LibThotEditor.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwdir.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwcache.lib" \
	".\Libjpeg.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwtelnt.lib" \
	".\Libpng.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwgophe.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwftp.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwtrans.lib"

"$(OUTDIR)\Amaya.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\bin"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\.\bin
INTDIR=.\Debug

ALL : "$(OUTDIR)\Amaya.exe" "$(OUTDIR)\Amaya.bsc"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\bin\Amaya.bsc"
	-@erase ".\Debug\AHTURLTools.sbr"
	-@erase ".\Debug\HTMLstyle.sbr"
	-@erase ".\Debug\HTMLAPP.sbr"
	-@erase ".\Debug\HTMLform.sbr"
	-@erase ".\Debug\trans.sbr"
	-@erase ".\Debug\EDITstyle.sbr"
	-@erase ".\Debug\HTMLhistory.sbr"
	-@erase ".\Debug\HTMLbook.sbr"
	-@erase ".\Debug\p2css.sbr"
	-@erase ".\Debug\EDITimage.sbr"
	-@erase ".\Debug\query.sbr"
	-@erase ".\Debug\Mathedit.sbr"
	-@erase ".\Debug\HTMLpresentation.sbr"
	-@erase ".\Debug\EDITORAPP.sbr"
	-@erase ".\Debug\AHTEvntrg.sbr"
	-@erase ".\Debug\AHTMemConv.sbr"
	-@erase ".\Debug\answer.sbr"
	-@erase ".\Debug\css.sbr"
	-@erase ".\Debug\HTEvntrg.sbr"
	-@erase ".\Debug\HTMLactions.sbr"
	-@erase ".\Debug\HTMLimage.sbr"
	-@erase ".\Debug\windialogapi.sbr"
	-@erase ".\Debug\MathMLAPP.sbr"
	-@erase ".\Debug\html2thot.sbr"
	-@erase ".\Debug\AHTBridge.sbr"
	-@erase ".\Debug\AHTFWrite.sbr"
	-@erase ".\Debug\init.sbr"
	-@erase ".\Debug\HTMLtable.sbr"
	-@erase ".\Debug\HTBInit.sbr"
	-@erase ".\Debug\transparse.sbr"
	-@erase ".\Debug\HTMLedit.sbr"
	-@erase ".\Debug\javaamaya.sbr"
	-@erase ".\Debug\HTInit.sbr"
	-@erase ".\Debug\UIcss.sbr"
	-@erase ".\Debug\EDITORactions.sbr"
	-@erase ".\Debug\HTMLsave.sbr"
	-@erase ".\bin\Amaya.exe"
	-@erase ".\Debug\transparse.obj"
	-@erase ".\Debug\HTMLedit.obj"
	-@erase ".\Debug\javaamaya.obj"
	-@erase ".\Debug\HTInit.obj"
	-@erase ".\Debug\UIcss.obj"
	-@erase ".\Debug\EDITORactions.obj"
	-@erase ".\Debug\HTMLsave.obj"
	-@erase ".\Debug\AHTURLTools.obj"
	-@erase ".\Debug\HTMLstyle.obj"
	-@erase ".\Debug\HTMLAPP.obj"
	-@erase ".\Debug\HTMLform.obj"
	-@erase ".\Debug\trans.obj"
	-@erase ".\Debug\EDITstyle.obj"
	-@erase ".\Debug\HTMLhistory.obj"
	-@erase ".\Debug\HTMLbook.obj"
	-@erase ".\Debug\p2css.obj"
	-@erase ".\Debug\EDITimage.obj"
	-@erase ".\Debug\query.obj"
	-@erase ".\Debug\Mathedit.obj"
	-@erase ".\Debug\HTMLpresentation.obj"
	-@erase ".\Debug\EDITORAPP.obj"
	-@erase ".\Debug\AHTEvntrg.obj"
	-@erase ".\Debug\AHTMemConv.obj"
	-@erase ".\Debug\answer.obj"
	-@erase ".\Debug\css.obj"
	-@erase ".\Debug\HTEvntrg.obj"
	-@erase ".\Debug\HTMLactions.obj"
	-@erase ".\Debug\HTMLimage.obj"
	-@erase ".\Debug\windialogapi.obj"
	-@erase ".\Debug\MathMLAPP.obj"
	-@erase ".\Debug\html2thot.obj"
	-@erase ".\Debug\AHTBridge.obj"
	-@erase ".\Debug\AHTFWrite.obj"
	-@erase ".\Debug\init.obj"
	-@erase ".\Debug\HTMLtable.obj"
	-@erase ".\Debug\HTBInit.obj"
	-@erase ".\Debug\amaya.res"
	-@erase ".\bin\Amaya.ilk"
	-@erase ".\bin\Amaya.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /I "..\thotlib\include" /I "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I "..\thotlib\internals\f" /I "..\amaya\f" /I "..\w3c-libwww-5.0a\Library\src" /I "..\libpng\zlib" /I "..\amaya" /I "..\winnt\amaya" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "COUGAR" /D "__STDC__" /D "WWW_WIN_ASYNC" /D "WWW_WIN_DLL" /D "SOCKS" /D "MATHML" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /I "..\thotlib\include" /I\
 "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I\
 "..\thotlib\internals\f" /I "..\amaya\f" /I "..\w3c-libwww-5.0a\Library\src" /I\
 "..\libpng\zlib" /I "..\amaya" /I "..\winnt\amaya" /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "COUGAR" /D "__STDC__" /D "WWW_WIN_ASYNC" /D "WWW_WIN_DLL" /D\
 "SOCKS" /D "MATHML" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Amaya.pch" /YX\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/amaya.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Amaya.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/AHTURLTools.sbr" \
	"$(INTDIR)/HTMLstyle.sbr" \
	"$(INTDIR)/HTMLAPP.sbr" \
	"$(INTDIR)/HTMLform.sbr" \
	"$(INTDIR)/trans.sbr" \
	"$(INTDIR)/EDITstyle.sbr" \
	"$(INTDIR)/HTMLhistory.sbr" \
	"$(INTDIR)/HTMLbook.sbr" \
	"$(INTDIR)/p2css.sbr" \
	"$(INTDIR)/EDITimage.sbr" \
	"$(INTDIR)/query.sbr" \
	"$(INTDIR)/Mathedit.sbr" \
	"$(INTDIR)/HTMLpresentation.sbr" \
	"$(INTDIR)/EDITORAPP.sbr" \
	"$(INTDIR)/AHTEvntrg.sbr" \
	"$(INTDIR)/AHTMemConv.sbr" \
	"$(INTDIR)/answer.sbr" \
	"$(INTDIR)/css.sbr" \
	"$(INTDIR)/HTEvntrg.sbr" \
	"$(INTDIR)/HTMLactions.sbr" \
	"$(INTDIR)/HTMLimage.sbr" \
	"$(INTDIR)/windialogapi.sbr" \
	"$(INTDIR)/MathMLAPP.sbr" \
	"$(INTDIR)/html2thot.sbr" \
	"$(INTDIR)/AHTBridge.sbr" \
	"$(INTDIR)/AHTFWrite.sbr" \
	"$(INTDIR)/init.sbr" \
	"$(INTDIR)/HTMLtable.sbr" \
	"$(INTDIR)/HTBInit.sbr" \
	"$(INTDIR)/transparse.sbr" \
	"$(INTDIR)/HTMLedit.sbr" \
	"$(INTDIR)/javaamaya.sbr" \
	"$(INTDIR)/HTInit.sbr" \
	"$(INTDIR)/UIcss.sbr" \
	"$(INTDIR)/EDITORactions.sbr" \
	"$(INTDIR)/HTMLsave.sbr"

"$(OUTDIR)\Amaya.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib comctl32.lib wsock32.lib /nologo /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)/amaya.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/amaya.exe" 
LINK32_OBJS= \
	"$(INTDIR)/transparse.obj" \
	"$(INTDIR)/HTMLedit.obj" \
	"$(INTDIR)/javaamaya.obj" \
	"$(INTDIR)/HTInit.obj" \
	"$(INTDIR)/UIcss.obj" \
	"$(INTDIR)/EDITORactions.obj" \
	"$(INTDIR)/HTMLsave.obj" \
	"$(INTDIR)/AHTURLTools.obj" \
	"$(INTDIR)/HTMLstyle.obj" \
	"$(INTDIR)/HTMLAPP.obj" \
	"$(INTDIR)/HTMLform.obj" \
	"$(INTDIR)/trans.obj" \
	"$(INTDIR)/EDITstyle.obj" \
	"$(INTDIR)/HTMLhistory.obj" \
	"$(INTDIR)/HTMLbook.obj" \
	"$(INTDIR)/p2css.obj" \
	"$(INTDIR)/EDITimage.obj" \
	"$(INTDIR)/query.obj" \
	"$(INTDIR)/Mathedit.obj" \
	"$(INTDIR)/HTMLpresentation.obj" \
	"$(INTDIR)/EDITORAPP.obj" \
	"$(INTDIR)/AHTEvntrg.obj" \
	"$(INTDIR)/AHTMemConv.obj" \
	"$(INTDIR)/answer.obj" \
	"$(INTDIR)/css.obj" \
	"$(INTDIR)/HTEvntrg.obj" \
	"$(INTDIR)/HTMLactions.obj" \
	"$(INTDIR)/HTMLimage.obj" \
	"$(INTDIR)/windialogapi.obj" \
	"$(INTDIR)/MathMLAPP.obj" \
	"$(INTDIR)/html2thot.obj" \
	"$(INTDIR)/AHTBridge.obj" \
	"$(INTDIR)/AHTFWrite.obj" \
	"$(INTDIR)/init.obj" \
	"$(INTDIR)/HTMLtable.obj" \
	"$(INTDIR)/HTBInit.obj" \
	"$(INTDIR)/amaya.res" \
	"..\w3c-libwww-5.0a\Bin\wwwhtml.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwdll.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwfile.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwmime.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwhttp.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwcore.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwutils.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwwais.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwstream.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwapp.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwnews.lib" \
	".\LibThotEditor.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwdir.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwcache.lib" \
	".\Libjpeg.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwtelnt.lib" \
	".\Libpng.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwgophe.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwftp.lib" \
	"..\w3c-libwww-5.0a\Bin\wwwtrans.lib"

"$(OUTDIR)\Amaya.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "amaya - Win32 Release"
# Name "amaya - Win32 Debug"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\UIcss.c
DEP_CPP_UICSS=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	".\..\amaya\rcopy.xpm"\
	".\..\amaya\lcopy.xpm"\
	".\..\amaya\rmerge.xpm"\
	".\..\amaya\lmerge.xpm"\
	".\..\amaya\destroy.xpm"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\p2css_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\UIcss_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_UICSS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\UIcss.obj" : $(SOURCE) $(DEP_CPP_UICSS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\UIcss.obj" : $(SOURCE) $(DEP_CPP_UICSS) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\UIcss.sbr" : $(SOURCE) $(DEP_CPP_UICSS) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\transparse.c
DEP_CPP_TRANS=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\amaya\trans.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\transparse_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_TRANS=\
	".\..\amaya\parser.h"\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\transparse.obj" : $(SOURCE) $(DEP_CPP_TRANS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\transparse.obj" : $(SOURCE) $(DEP_CPP_TRANS) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\transparse.sbr" : $(SOURCE) $(DEP_CPP_TRANS) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\trans.c
DEP_CPP_TRANS_=\
	".\..\amaya\amaya.h"\
	".\..\amaya\trans.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\transparse_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_TRANS_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\trans.obj" : $(SOURCE) $(DEP_CPP_TRANS_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\trans.obj" : $(SOURCE) $(DEP_CPP_TRANS_) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\trans.sbr" : $(SOURCE) $(DEP_CPP_TRANS_) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\query.c
DEP_CPP_QUERY=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\answer_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTBridge_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTMemConv_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTFWrite_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_QUERY=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\query.obj" : $(SOURCE) $(DEP_CPP_QUERY) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\query.obj" : $(SOURCE) $(DEP_CPP_QUERY) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\query.sbr" : $(SOURCE) $(DEP_CPP_QUERY) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\p2css.c
DEP_CPP_P2CSS=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\p2css_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_P2CSS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\p2css.obj" : $(SOURCE) $(DEP_CPP_P2CSS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\p2css.obj" : $(SOURCE) $(DEP_CPP_P2CSS) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\p2css.sbr" : $(SOURCE) $(DEP_CPP_P2CSS) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\javaamaya.c
DEP_CPP_JAVAA=\
	".\..\amaya\amaya.h"\
	".\..\amaya\javaamaya.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_JAVAA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\javaamaya.obj" : $(SOURCE) $(DEP_CPP_JAVAA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\javaamaya.obj" : $(SOURCE) $(DEP_CPP_JAVAA) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\javaamaya.sbr" : $(SOURCE) $(DEP_CPP_JAVAA) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\init.c
DEP_CPP_INIT_=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	".\..\amaya\trans.h"\
	".\..\amaya\stopN.xpm"\
	".\..\amaya\stopR.xpm"\
	".\..\amaya\save.xpm"\
	".\..\amaya\find.xpm"\
	".\..\amaya\Back.xpm"\
	".\..\amaya\BackNo.xpm"\
	".\..\amaya\Forward.xpm"\
	".\..\amaya\ForwardNo.xpm"\
	".\..\amaya\Reload.xpm"\
	".\..\amaya\I.xpm"\
	".\..\amaya\B.xpm"\
	".\..\amaya\T.xpm"\
	".\..\amaya\H1.xpm"\
	".\..\amaya\H2.xpm"\
	".\..\amaya\H3.xpm"\
	".\..\amaya\Num.xpm"\
	".\..\amaya\Bullet.xpm"\
	".\..\amaya\Print.xpm"\
	".\..\amaya\css.xpm"\
	".\..\amaya\Image.xpm"\
	".\..\amaya\DL.xpm"\
	".\..\amaya\Link.xpm"\
	".\..\amaya\Table.xpm"\
	"e:\users\guetari\opera\thotlib\include\plugin.h"\
	".\..\amaya\Plugin.xpm"\
	".\..\amaya\Java.xpm"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLhistory_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\amaya\f\trans_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITORactions_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITimage_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\Mathedit_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLbook_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLsave_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\UIcss_f.h"\
	"e:\users\guetari\opera\amaya\f\javaamaya_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_INIT_=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\init.obj" : $(SOURCE) $(DEP_CPP_INIT_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\init.obj" : $(SOURCE) $(DEP_CPP_INIT_) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\init.sbr" : $(SOURCE) $(DEP_CPP_INIT_) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLtable.c
DEP_CPP_HTMLT=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_HTMLT=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLtable.obj" : $(SOURCE) $(DEP_CPP_HTMLT) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLtable.obj" : $(SOURCE) $(DEP_CPP_HTMLT) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLtable.sbr" : $(SOURCE) $(DEP_CPP_HTMLT) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLstyle.c
DEP_CPP_HTMLS=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLpresentation_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\UIcss_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLimage_f.h"\
	".\..\amaya\HTMLstyleColor.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_HTMLS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLstyle.obj" : $(SOURCE) $(DEP_CPP_HTMLS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLstyle.obj" : $(SOURCE) $(DEP_CPP_HTMLS) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLstyle.sbr" : $(SOURCE) $(DEP_CPP_HTMLS) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLsave.c
DEP_CPP_HTMLSA=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLbook_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLsave_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_HTMLSA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLsave.obj" : $(SOURCE) $(DEP_CPP_HTMLSA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLsave.obj" : $(SOURCE) $(DEP_CPP_HTMLSA) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLsave.sbr" : $(SOURCE) $(DEP_CPP_HTMLSA) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLpresentation.c
DEP_CPP_HTMLP=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\EDITstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_HTMLP=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLpresentation.obj" : $(SOURCE) $(DEP_CPP_HTMLP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLpresentation.obj" : $(SOURCE) $(DEP_CPP_HTMLP) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLpresentation.sbr" : $(SOURCE) $(DEP_CPP_HTMLP) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLimage.c
DEP_CPP_HTMLI=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_HTMLI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLimage.obj" : $(SOURCE) $(DEP_CPP_HTMLI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLimage.obj" : $(SOURCE) $(DEP_CPP_HTMLI) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLimage.sbr" : $(SOURCE) $(DEP_CPP_HTMLI) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLhistory.c
DEP_CPP_HTMLH=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\HTMLhistory_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_HTMLH=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLhistory.obj" : $(SOURCE) $(DEP_CPP_HTMLH) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLhistory.obj" : $(SOURCE) $(DEP_CPP_HTMLH) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLhistory.sbr" : $(SOURCE) $(DEP_CPP_HTMLH) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLform.c
DEP_CPP_HTMLF=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLform_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_HTMLF=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLform.obj" : $(SOURCE) $(DEP_CPP_HTMLF) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLform.obj" : $(SOURCE) $(DEP_CPP_HTMLF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLform.sbr" : $(SOURCE) $(DEP_CPP_HTMLF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLedit.c
DEP_CPP_HTMLE=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITimage_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITORactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLpresentation_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	
NODEP_CPP_HTMLE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLedit.obj" : $(SOURCE) $(DEP_CPP_HTMLE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLedit.obj" : $(SOURCE) $(DEP_CPP_HTMLE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLedit.sbr" : $(SOURCE) $(DEP_CPP_HTMLE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLbook.c
DEP_CPP_HTMLB=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\thotlib\include\print.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLbook_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_HTMLB=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLbook.obj" : $(SOURCE) $(DEP_CPP_HTMLB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLbook.obj" : $(SOURCE) $(DEP_CPP_HTMLB) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLbook.sbr" : $(SOURCE) $(DEP_CPP_HTMLB) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\HTMLactions.c
DEP_CPP_HTMLA=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLform_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLhistory_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLimage_f.h"\
	"e:\users\guetari\opera\amaya\f\trans_f.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_HTMLA=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLactions.obj" : $(SOURCE) $(DEP_CPP_HTMLA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLactions.obj" : $(SOURCE) $(DEP_CPP_HTMLA) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLactions.sbr" : $(SOURCE) $(DEP_CPP_HTMLA) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\html2thot.c
DEP_CPP_HTML2=\
	".\..\amaya\HTML.h"\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\libpng\zlib\zlib.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLtable_f.h"\
	"e:\users\guetari\opera\amaya\f\Mathedit_f.h"\
	".\amaya\MathML.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	".\..\libpng\zlib\zconf.h"\
	
NODEP_CPP_HTML2=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\html2thot.obj" : $(SOURCE) $(DEP_CPP_HTML2) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\html2thot.obj" : $(SOURCE) $(DEP_CPP_HTML2) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\html2thot.sbr" : $(SOURCE) $(DEP_CPP_HTML2) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\EDITstyle.c
DEP_CPP_EDITS=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLpresentation_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\UIcss_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_EDITS=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\EDITstyle.obj" : $(SOURCE) $(DEP_CPP_EDITS) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\EDITstyle.obj" : $(SOURCE) $(DEP_CPP_EDITS) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\EDITstyle.sbr" : $(SOURCE) $(DEP_CPP_EDITS) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\EDITORactions.c
DEP_CPP_EDITO=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITORactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_EDITO=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\EDITORactions.obj" : $(SOURCE) $(DEP_CPP_EDITO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\EDITORactions.obj" : $(SOURCE) $(DEP_CPP_EDITO) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\EDITORactions.sbr" : $(SOURCE) $(DEP_CPP_EDITO) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\EDITimage.c
DEP_CPP_EDITI=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLactions_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLedit_f.h"\
	"e:\users\guetari\opera\amaya\f\EDITimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLimage_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLpresentation_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	
NODEP_CPP_EDITI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\EDITimage.obj" : $(SOURCE) $(DEP_CPP_EDITI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\EDITimage.obj" : $(SOURCE) $(DEP_CPP_EDITI) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\EDITimage.sbr" : $(SOURCE) $(DEP_CPP_EDITI) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\css.c
DEP_CPP_CSS_C=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	"e:\users\guetari\opera\amaya\f\css_f.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\p2css_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\amaya\f\HTMLstyle_f.h"\
	"e:\users\guetari\opera\amaya\f\UIcss_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_CSS_C=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\css.obj" : $(SOURCE) $(DEP_CPP_CSS_C) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\css.obj" : $(SOURCE) $(DEP_CPP_CSS_C) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\css.sbr" : $(SOURCE) $(DEP_CPP_CSS_C) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\answer.c
DEP_CPP_ANSWE=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_ANSWE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\answer.obj" : $(SOURCE) $(DEP_CPP_ANSWE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\answer.obj" : $(SOURCE) $(DEP_CPP_ANSWE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\answer.sbr" : $(SOURCE) $(DEP_CPP_ANSWE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\AHTURLTools.c
DEP_CPP_AHTUR=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\init_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTURLTools_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_AHTUR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\AHTURLTools.obj" : $(SOURCE) $(DEP_CPP_AHTUR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\AHTURLTools.obj" : $(SOURCE) $(DEP_CPP_AHTUR) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\AHTURLTools.sbr" : $(SOURCE) $(DEP_CPP_AHTUR) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\AHTMemConv.c
DEP_CPP_AHTME=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\AHTMemConv_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_AHTME=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\AHTMemConv.obj" : $(SOURCE) $(DEP_CPP_AHTME) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\AHTMemConv.obj" : $(SOURCE) $(DEP_CPP_AHTME) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\AHTMemConv.sbr" : $(SOURCE) $(DEP_CPP_AHTME) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\AHTFWrite.c
DEP_CPP_AHTFW=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_AHTFW=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\AHTFWrite.obj" : $(SOURCE) $(DEP_CPP_AHTFW) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\AHTFWrite.obj" : $(SOURCE) $(DEP_CPP_AHTFW) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\AHTFWrite.sbr" : $(SOURCE) $(DEP_CPP_AHTFW) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\AHTBridge.c
DEP_CPP_AHTBR=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\AHTBridge_f.h"\
	"e:\users\guetari\opera\amaya\f\AHTFWrite_f.h"\
	"e:\users\guetari\opera\amaya\f\query_f.h"\
	"e:\users\guetari\opera\amaya\f\answer_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_AHTBR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\AHTBridge.obj" : $(SOURCE) $(DEP_CPP_AHTBR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\AHTBridge.obj" : $(SOURCE) $(DEP_CPP_AHTBR) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\AHTBridge.sbr" : $(SOURCE) $(DEP_CPP_AHTBR) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTInit.c"
DEP_CPP_HTINI=\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	
NODEP_CPP_HTINI=\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTInit.obj" : $(SOURCE) $(DEP_CPP_HTINI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTInit.obj" : $(SOURCE) $(DEP_CPP_HTINI) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTInit.sbr" : $(SOURCE) $(DEP_CPP_HTINI) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.c"
DEP_CPP_HTEVN=\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	
NODEP_CPP_HTEVN=\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTEvntrg.obj" : $(SOURCE) $(DEP_CPP_HTEVN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTEvntrg.obj" : $(SOURCE) $(DEP_CPP_HTEVN) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTEvntrg.sbr" : $(SOURCE) $(DEP_CPP_HTEVN) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.c"
DEP_CPP_HTBIN=\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	
NODEP_CPP_HTBIN=\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTBInit.obj" : $(SOURCE) $(DEP_CPP_HTBIN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTBInit.obj" : $(SOURCE) $(DEP_CPP_HTBIN) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTBInit.sbr" : $(SOURCE) $(DEP_CPP_HTBIN) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwwais.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwutils.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwtrans.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwtelnt.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwstream.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwnews.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwmime.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwhttp.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwhtml.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwgophe.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwftp.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwfile.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwdll.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwdir.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwcore.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwcache.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\windialogapi.c
DEP_CPP_WINDI=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\thotlib\internals\h\constmenu.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_WINDI=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\windialogapi.obj" : $(SOURCE) $(DEP_CPP_WINDI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\windialogapi.obj" : $(SOURCE) $(DEP_CPP_WINDI) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\windialogapi.sbr" : $(SOURCE) $(DEP_CPP_WINDI) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\amaya.rc
DEP_RSC_AMAYA=\
	".\..\amaya\bleft.bmp"\
	".\..\amaya\bright.bmp"\
	".\..\amaya\bcenter.bmp"\
	".\..\amaya\bindent1.bmp"\
	".\..\amaya\bindent2.bmp"\
	".\..\amaya\bssmall.bmp"\
	".\..\amaya\bsmedium.bmp"\
	".\..\amaya\bslarge.bmp"\
	".\..\amaya\toolbar1.bmp"\
	".\..\amaya\amaya.bmp"\
	".\..\amaya\math.bmp"\
	".\..\amaya\mathd.bmp"\
	".\..\amaya\root.bmp"\
	".\..\amaya\sroot.bmp"\
	".\..\amaya\div.bmp"\
	".\..\amaya\powind.bmp"\
	".\..\amaya\pow.bmp"\
	".\..\amaya\ind.bmp"\
	".\..\amaya\updn.bmp"\
	".\..\amaya\up.bmp"\
	".\..\amaya\down.bmp"\
	".\..\amaya\parexp.bmp"\
	".\..\amaya\udlr.bmp"\
	".\..\amaya\sym.bmp"\
	".\..\amaya\gkey001.bmp"\
	".\..\amaya\gkey002.bmp"\
	".\..\amaya\gkey003.bmp"\
	".\..\amaya\gkey004.bmp"\
	".\..\amaya\gkey005.bmp"\
	".\..\amaya\gkey006.bmp"\
	".\..\amaya\gkey007.bmp"\
	".\..\amaya\gkey008.bmp"\
	".\..\amaya\gkey009.bmp"\
	".\..\amaya\gkey010.bmp"\
	".\..\amaya\gkey011.bmp"\
	".\..\amaya\gkey012.bmp"\
	".\..\amaya\gkey013.bmp"\
	".\..\amaya\gkey014.bmp"\
	".\..\amaya\gkey015.bmp"\
	".\..\amaya\gkey016.bmp"\
	".\..\amaya\gkey017.bmp"\
	".\..\amaya\gkey018.bmp"\
	".\..\amaya\gkey019.bmp"\
	".\..\amaya\gkey020.bmp"\
	".\..\amaya\gkey021.bmp"\
	".\..\amaya\gkey022.bmp"\
	".\..\amaya\gkey023.bmp"\
	".\..\amaya\gkey024.bmp"\
	".\..\amaya\gkey025.bmp"\
	".\..\amaya\gkey026.bmp"\
	".\..\amaya\gkey027.bmp"\
	".\..\amaya\gkey028.bmp"\
	".\..\amaya\gkey029.bmp"\
	".\..\amaya\gkey030.bmp"\
	".\..\amaya\gkey031.bmp"\
	".\..\amaya\gkey032.bmp"\
	".\..\amaya\gkey033.bmp"\
	".\..\amaya\gkey034.bmp"\
	".\..\amaya\gkey035.bmp"\
	".\..\amaya\gkey036.bmp"\
	".\..\amaya\gkey037.bmp"\
	".\..\amaya\gkey038.bmp"\
	".\..\amaya\gkey039.bmp"\
	".\..\amaya\gkey040.bmp"\
	".\..\amaya\gkey041.bmp"\
	".\..\amaya\gkey042.bmp"\
	".\..\amaya\gkey043.bmp"\
	".\..\amaya\gkey044.bmp"\
	".\..\amaya\gkey045.bmp"\
	".\..\amaya\gkey046.bmp"\
	".\..\amaya\gkey047.bmp"\
	".\..\amaya\gkey048.bmp"\
	".\..\amaya\gkey049.bmp"\
	".\..\amaya\gkey050.bmp"\
	".\..\amaya\gkey051.bmp"\
	".\..\amaya\gkey052.bmp"\
	".\..\amaya\gkey053.bmp"\
	".\..\amaya\gkey054.bmp"\
	".\..\amaya\gkey055.bmp"\
	".\..\amaya\gkey056.bmp"\
	".\..\amaya\gkey057.bmp"\
	".\..\amaya\gkey058.bmp"\
	".\..\amaya\gkey059.bmp"\
	".\..\amaya\gkey060.bmp"\
	".\..\amaya\gkey061.bmp"\
	".\..\amaya\gkey062.bmp"\
	".\..\amaya\gkey063.bmp"\
	".\..\amaya\gkey064.bmp"\
	".\..\amaya\gkey065.bmp"\
	".\..\amaya\gkey066.bmp"\
	".\..\amaya\gkey067.bmp"\
	".\..\amaya\gkey068.bmp"\
	".\..\amaya\gkey069.bmp"\
	".\..\amaya\gkey070.bmp"\
	".\..\amaya\gkey071.bmp"\
	".\..\amaya\gkey072.bmp"\
	".\..\amaya\gkey073.bmp"\
	".\..\amaya\gkey074.bmp"\
	".\..\amaya\gkey075.bmp"\
	".\..\amaya\gkey076.bmp"\
	".\..\amaya\gkey077.bmp"\
	".\..\amaya\gkey078.bmp"\
	".\..\amaya\gkey079.bmp"\
	".\..\amaya\gkey080.bmp"\
	".\..\amaya\gkey081.bmp"\
	".\..\amaya\gkey082.bmp"\
	".\..\amaya\gkey083.bmp"\
	".\..\amaya\gkey084.bmp"\
	".\..\amaya\gkey085.bmp"\
	".\..\amaya\gkey086.bmp"\
	".\..\amaya\gkey087.bmp"\
	".\..\amaya\gkey088.bmp"\
	".\..\amaya\gkey089.bmp"\
	".\..\amaya\gkey090.bmp"\
	".\..\amaya\gkey091.bmp"\
	".\..\amaya\gkey092.bmp"\
	".\..\amaya\gkey093.bmp"\
	".\..\amaya\gkey094.bmp"\
	".\..\amaya\gkey095.bmp"\
	".\..\amaya\gkey096.bmp"\
	".\..\amaya\gkey097.bmp"\
	".\..\amaya\gkey098.bmp"\
	".\..\amaya\gkey099.bmp"\
	".\..\amaya\gkey100.bmp"\
	".\..\amaya\gkey101.bmp"\
	".\..\amaya\gkey102.bmp"\
	".\..\amaya\gkey103.bmp"\
	".\..\amaya\gkey104.bmp"\
	".\..\amaya\gkey105.bmp"\
	".\..\amaya\gkey106.bmp"\
	".\..\amaya\gkey107.bmp"\
	".\..\amaya\gkey108.bmp"\
	".\..\amaya\gkey109.bmp"\
	".\..\amaya\gkey110.bmp"\
	".\..\amaya\gkey111.bmp"\
	".\..\amaya\gkey112.bmp"\
	".\..\amaya\gkey113.bmp"\
	".\..\amaya\gkey114.bmp"\
	".\..\amaya\gkey115.bmp"\
	".\..\amaya\gkey116.bmp"\
	".\..\amaya\gkey117.bmp"\
	".\..\amaya\gkey118.bmp"\
	".\..\amaya\gkey119.bmp"\
	".\..\amaya\gkey120.bmp"\
	".\..\amaya\gkey121.bmp"\
	".\..\amaya\gkey122.bmp"\
	".\..\amaya\gkey123.bmp"\
	".\..\amaya\gkey124.bmp"\
	".\..\amaya\gkey125.bmp"\
	".\..\amaya\gkey126.bmp"\
	".\..\amaya\gkey127.bmp"\
	".\..\amaya\gkey128.bmp"\
	".\..\amaya\gkey129.bmp"\
	".\..\amaya\gkey130.bmp"\
	".\..\amaya\gkey131.bmp"\
	".\..\amaya\gkey132.bmp"\
	".\..\amaya\gkey133.bmp"\
	".\..\amaya\gkey134.bmp"\
	".\..\amaya\gkey135.bmp"\
	".\..\amaya\gkey136.bmp"\
	".\..\amaya\gkey137.bmp"\
	".\..\amaya\gkey138.bmp"\
	".\..\amaya\gkey139.bmp"\
	".\..\amaya\gkey140.bmp"\
	".\..\amaya\gkey141.bmp"\
	".\..\amaya\gkey142.bmp"\
	".\..\amaya\gkey143.bmp"\
	".\..\amaya\gkey144.bmp"\
	".\..\amaya\gkey145.bmp"\
	".\..\amaya\gkey146.bmp"\
	".\..\amaya\gkey147.bmp"\
	".\..\amaya\gkey148.bmp"\
	".\..\amaya\gkey149.bmp"\
	".\..\amaya\gkey150.bmp"\
	".\..\amaya\gkey151.bmp"\
	".\..\amaya\gkey152.bmp"\
	".\..\amaya\gkey153.bmp"\
	".\..\amaya\gkey154.bmp"\
	".\..\amaya\gkey155.bmp"\
	".\..\amaya\gkey156.bmp"\
	".\..\amaya\gkey157.bmp"\
	".\..\amaya\gkey158.bmp"\
	".\..\amaya\gkey159.bmp"\
	".\..\amaya\gkey160.bmp"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\amaya.res" : $(SOURCE) $(DEP_RSC_AMAYA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/amaya.res" /i "\users\guetari\opera\amaya" /d\
 "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


"$(INTDIR)\amaya.res" : $(SOURCE) $(DEP_RSC_AMAYA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/amaya.res" /i "\users\guetari\opera\amaya" /d\
 "_DEBUG" $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\AHTEvntrg.c
DEP_CPP_AHTEV=\
	".\..\amaya\amaya.h"\
	"e:\users\guetari\opera\amaya\f\AHTBridge_f.h"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	
NODEP_CPP_AHTEV=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\AHTEvntrg.obj" : $(SOURCE) $(DEP_CPP_AHTEV) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\AHTEvntrg.obj" : $(SOURCE) $(DEP_CPP_AHTEV) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\AHTEvntrg.sbr" : $(SOURCE) $(DEP_CPP_AHTEV) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\amaya\EDITORAPP.c
DEP_CPP_EDITOR=\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	".\amaya\EDITOR.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	"e:\users\guetari\opera\thotlib\internals\h\logo.xpm"\
	"e:\users\guetari\opera\thotlib\internals\h\logo.xbm"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	
NODEP_CPP_EDITOR=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\EDITORAPP.obj" : $(SOURCE) $(DEP_CPP_EDITOR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\EDITORAPP.obj" : $(SOURCE) $(DEP_CPP_EDITOR) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\EDITORAPP.sbr" : $(SOURCE) $(DEP_CPP_EDITOR) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\amaya\HTMLAPP.c
DEP_CPP_HTMLAP=\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	".\amaya\HTML.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	
NODEP_CPP_HTMLAP=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\HTMLAPP.obj" : $(SOURCE) $(DEP_CPP_HTMLAP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\HTMLAPP.obj" : $(SOURCE) $(DEP_CPP_HTMLAP) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\HTMLAPP.sbr" : $(SOURCE) $(DEP_CPP_HTMLAP) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\users\guetari\opera\amaya\Mathedit.c
DEP_CPP_MATHE=\
	".\..\amaya\amaya.h"\
	".\..\amaya\css.h"\
	".\..\amaya\trans.h"\
	"e:\users\guetari\opera\amaya\f\html2thot_f.h"\
	".\amaya\MathML.h"\
	".\..\amaya\Math.xpm"\
	".\..\amaya\mathdisp.xpm"\
	".\..\amaya\root.xpm"\
	".\..\amaya\sqrt.xpm"\
	".\..\amaya\frac.xpm"\
	".\..\amaya\subsup.xpm"\
	".\..\amaya\sup.xpm"\
	".\..\amaya\sub.xpm"\
	".\..\amaya\overunder.xpm"\
	".\..\amaya\over.xpm"\
	".\..\amaya\under.xpm"\
	".\..\amaya\fence.xpm"\
	".\..\amaya\mscript.xpm"\
	".\..\amaya\greek.xpm"\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\browser.h"\
	"e:\users\guetari\opera\thotlib\include\content.h"\
	"e:\users\guetari\opera\thotlib\include\dialog.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	"e:\users\guetari\opera\thotlib\include\libmsg.h"\
	"e:\users\guetari\opera\thotlib\include\message.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	"e:\users\guetari\opera\thotlib\include\selection.h"\
	"e:\users\guetari\opera\thotlib\include\reference.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	".\amaya\EDITOR.h"\
	".\..\amaya\HTML.h"\
	".\..\amaya\amayamsg.h"\
	".\..\amaya\libjava.h"\
	".\..\amaya\libilu.h"\
	".\..\amaya\libwww.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	"e:\users\guetari\opera\thotlib\include\language.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWLib.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWApp.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWHTTP.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\WWWInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReqMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTReq.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAncMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAccess.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTEvntrg.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTAlert.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTNetMan.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTBInit.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTProxy.h"\
	"e:\users\guetari\opera\w3c-libwww-5.0a\Library\src\HTHost.h"\
	".\..\w3c-libwww-5.0a\Library\src\sysdep.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCore.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTArray.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAssoc.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAtom.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTList.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMemory.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTString.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUU.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLib.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMethod.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAnchor.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLink.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEscape.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUTree.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWWWStr.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTUser.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTEvent.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTError.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFormat.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBind.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTStruct.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIOStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFWrite.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDNS.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTResponse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTChannl.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHome.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDialog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTRules.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFilter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLog.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHist.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPServ.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPReq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTPRes.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPEP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAAUtil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTAABrow.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTProfil.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHInit.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTrans.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWGophe.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWTelnt.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWWAIS.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWHTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWStream.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\WWWCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTANSI.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTLocal.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTCP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSocket.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTReader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWriter.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBufWrt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMux.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFile.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulti.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTP.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTFTPDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGopher.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTelnet.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNews.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsRq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNewsLs.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTNDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIME.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTHeader.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMERq.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMImp.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTBound.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMulpar.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLPDTD.h"\
	".\..\w3c-libwww-5.0a\Library\src\SGML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMLGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTeXGen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTConLen.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTGuess.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTTee.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMerge.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTSChunk.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTXParse.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDir.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTIcons.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTDescpt.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTCache.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTML.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTPlain.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTMIMPrs.h"\
	"e:\users\guetari\opera\thotlib\include\genericdriver.h"\
	"e:\users\guetari\opera\thotlib\include\specificdriver.h"\
	"e:\users\guetari\opera\thotlib\include\presentdriver.h"\
	
NODEP_CPP_MATHE=\
	".\..\thotlib\include\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTVMSUtils.h"\
	".\..\w3c-libwww-5.0a\Library\src\HTWAIS.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\Mathedit.obj" : $(SOURCE) $(DEP_CPP_MATHE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\Mathedit.obj" : $(SOURCE) $(DEP_CPP_MATHE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Mathedit.sbr" : $(SOURCE) $(DEP_CPP_MATHE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\amaya\MathMLAPP.c
DEP_CPP_MATHM=\
	"e:\users\guetari\opera\thotlib\include\thot_gui.h"\
	"e:\users\guetari\opera\thotlib\include\thot_sys.h"\
	"e:\users\guetari\opera\thotlib\include\application.h"\
	"e:\users\guetari\opera\thotlib\include\app.h"\
	"e:\users\guetari\opera\thotlib\include\interface.h"\
	".\amaya\MathML.h"\
	".\..\Thotlib\Include\Typebase.h"\
	".\..\thotlib\include\simx.h"\
	".\..\Thotlib\Include\Sysdep.h"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	{$(INCLUDE)}"\sys\STAT.H"\
	"e:\users\guetari\opera\thotlib\include\fileaccess.h"\
	".\..\thotlib\include\registry.h"\
	".\..\Thotlib\Include\appaction.h"\
	"e:\users\guetari\opera\thotlib\include\document.h"\
	"e:\users\guetari\opera\thotlib\include\pschema.h"\
	"e:\users\guetari\opera\thotlib\include\view.h"\
	"e:\users\guetari\opera\thotlib\include\attribute.h"\
	"e:\users\guetari\opera\thotlib\include\presentation.h"\
	
NODEP_CPP_MATHM=\
	".\..\thotlib\include\HTVMSUtils.h"\
	

!IF  "$(CFG)" == "amaya - Win32 Release"


"$(INTDIR)\MathMLAPP.obj" : $(SOURCE) $(DEP_CPP_MATHM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\MathMLAPP.obj" : $(SOURCE) $(DEP_CPP_MATHM) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\MathMLAPP.sbr" : $(SOURCE) $(DEP_CPP_MATHM) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE="\users\guetari\opera\w3c-libwww-5.0a\Bin\wwwapp.lib"

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\LibThotEditor.lib

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Libpng.lib

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Libjpeg.lib

!IF  "$(CFG)" == "amaya - Win32 Release"

!ELSEIF  "$(CFG)" == "amaya - Win32 Debug"

!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
