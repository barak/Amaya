# Microsoft Developer Studio Project File - Name="libpng" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libpng - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libpng.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libpng.mak" CFG="libpng - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libpng - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libpng - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libpng - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "libpng__"
# PROP BASE Intermediate_Dir "libpng__"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\..\libpng\zlib" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "libpng - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "libpng_0"
# PROP BASE Intermediate_Dir "libpng_0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Z7 /Od /I "..\..\libpng\zlib" /D "_I18N_" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "libpng - Win32 Release"
# Name "libpng - Win32 Debug"
# Begin Source File

SOURCE=..\..\libpng\png.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngerror.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pnggccrd.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngget.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngmem.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngread.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngrio.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngrtran.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngrutil.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngset.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngtrans.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngvcrd.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwio.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwrite.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwtran.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwutil.c
# End Source File
# End Target
# End Project