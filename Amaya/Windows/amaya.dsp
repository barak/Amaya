# Microsoft Developer Studio Project File - Name="amaya" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=AMAYA - WIN32 DEBUG
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "amaya.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "amaya.mak" CFG="AMAYA - WIN32 DEBUG"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "amaya - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "amaya - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\davlib" /I "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I ".\amaya" /I "..\amaya" /I "..\amaya\f" /I "..\thotlib\include" /I "..\..\libwww\Library\src" /I "..\..\libwww\modules\expat\lib" /I "..\libpng\zlib" /I "..\thotlib\internals\f" /I "..\annotlib" /I "..\annotlib\f" /I "..\davlib\h" /I "..\davlib\f" /I "..\davlib\tree\h" /D "NDEBUG" /D "BOOKMARKS" /D "XML_DTD" /D "XML_NS" /D "_SVG" /D "__STDC__" /D "WWW_WIN_ASYNC" /D "WWW_WIN_DLL" /D "SOCKS" /D "ANNOTATIONS" /D "XML_GENERIC" /D "DAV" /D "WIN32" /D "_WINDOWS" /D "_WINGUI" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib wsock32.lib user32.lib gdi32.lib advapi32.lib comdlg32.lib shell32.lib winspool.lib /nologo /subsystem:windows /machine:I386

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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /ZI /Od /I "..\..\..\libwww\modules\expat\lib" /I "..\thotlib\internals\h" /I "..\thotlib\internals\var" /I ".\amaya" /I "..\amaya" /I "..\amaya\f" /I "..\thotlib\include" /I "..\..\libwww\Library\src" /I "..\..\libwww\modules\expat\lib" /I "..\libpng\zlib" /I "..\thotlib\internals\f" /I "..\annotlib" /I "..\annotlib\f" /I "..\davlib\h" /I "..\davlib\f" /I "..\davlib\tree\h" /D "EXPAT_PARSER" /D "BOOKMARKS" /D "_DEBUG" /D "XML_DTD" /D "XML_NS" /D "_SVG" /D "__STDC__" /D "WWW_WIN_ASYNC" /D "WWW_WIN_DLL" /D "SOCKS" /D "ANNOTATIONS" /D "XML_GENERIC" /D "DAV" /D "WIN32" /D "_WINDOWS" /D "_WINGUI" /FR /YX /FD /c
# SUBTRACT CPP /X
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL"
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 comctl32.lib wsock32.lib user32.lib gdi32.lib advapi32.lib comdlg32.lib shell32.lib winspool.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /incremental:no

!ENDIF 

# Begin Target

# Name "amaya - Win32 Release"
# Name "amaya - Win32 Debug"
# Begin Source File

SOURCE=..\amaya\AHTBridge.c
# End Source File
# Begin Source File

SOURCE=..\amaya\AHTFWrite.c
# End Source File
# Begin Source File

SOURCE=..\amaya\AHTMemConv.c
# End Source File
# Begin Source File

SOURCE=..\amaya\AHTURLTools.c
# End Source File
# Begin Source File

SOURCE=..\amaya\amaya.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\amaya.rc
# End Source File
# Begin Source File

SOURCE=..\amaya\anim.c
# End Source File
# Begin Source File

SOURCE=..\amaya\animbuilder.c
# End Source File
# Begin Source File

SOURCE=..\amaya\answer.c
# End Source File
# Begin Source File

SOURCE=..\amaya\appicon.ico
# End Source File
# Begin Source File

SOURCE=..\amaya\bcenter.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bindent1.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bindent2.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bleft.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bright.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bslarge.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bsmedium.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\bssmall.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\css.c
# End Source File
# Begin Source File

SOURCE=..\amaya\EDITimage.c
# End Source File
# Begin Source File

SOURCE=..\amaya\EDITORactions.c
# End Source File
# Begin Source File

SOURCE=.\amaya\EDITORAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\EDITstyle.c
# End Source File
# Begin Source File

SOURCE=..\Amaya\fetchHTMLname.c
# End Source File
# Begin Source File

SOURCE=..\Amaya\fetchXMLname.c
# End Source File
# Begin Source File

SOURCE=..\amaya\html2thot.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLactions.c
# End Source File
# Begin Source File

SOURCE=.\amaya\HTMLAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLbook.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLedit.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLform.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLhistory.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLimage.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLpresentation.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLsave.c
# End Source File
# Begin Source File

SOURCE=..\amaya\HTMLtable.c
# End Source File
# Begin Source File

SOURCE=..\amaya\init.c
# End Source File
# Begin Source File

SOURCE=..\amaya\libmanag.c
# End Source File
# Begin Source File

SOURCE=..\amaya\math.bmp
# End Source File
# Begin Source File

SOURCE=..\amaya\Mathedit.c
# End Source File
# Begin Source File

SOURCE=.\amaya\MathMLAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\MathMLbuilder.c
# End Source File
# Begin Source File

SOURCE=..\amaya\MENUconf.c
# End Source File
# Begin Source File

SOURCE=..\amaya\query.c
# End Source File
# Begin Source File

SOURCE=..\amaya\styleparser.c
# End Source File
# Begin Source File

SOURCE=.\amaya\SVGAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\SVGbuilder.c
# End Source File
# Begin Source File

SOURCE=..\amaya\SVGedit.c
# End Source File
# Begin Source File

SOURCE=..\amaya\templates.c
# End Source File
# Begin Source File

SOURCE=.\amaya\TextFileAPP.c
# End Source File
# Begin Source File

SOURCE=.\amaya\TimelineAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\trans.c
# End Source File
# Begin Source File

SOURCE=..\amaya\transparse.c
# End Source File
# Begin Source File

SOURCE=..\amaya\UIcss.c
# End Source File
# Begin Source File

SOURCE=..\amaya\wincurso.cur
# End Source File
# Begin Source File

SOURCE=..\amaya\windialogapi.c
# End Source File
# Begin Source File

SOURCE=..\amaya\XHTMLbuilder.c
# End Source File
# Begin Source File

SOURCE=.\amaya\XLinkAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\XLinkbuilder.c
# End Source File
# Begin Source File

SOURCE=..\amaya\XLinkedit.c
# End Source File
# Begin Source File

SOURCE=..\amaya\Xml2thot.c
# End Source File
# Begin Source File

SOURCE=.\amaya\XMLAPP.c
# End Source File
# Begin Source File

SOURCE=..\amaya\Xmlbuilder.c
# End Source File
# Begin Source File

SOURCE=..\amaya\XPointer.c
# End Source File
# Begin Source File

SOURCE=..\amaya\XPointerparse.c
# End Source File
# End Target
# End Project
