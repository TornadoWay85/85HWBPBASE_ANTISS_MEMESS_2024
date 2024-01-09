# Microsoft Developer Studio Project File - Name="85HWBPBASE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=85HWBPBASE - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "85HWBPBASE.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "85HWBPBASE.mak" CFG="85HWBPBASE - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "85HWBPBASE - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MY85HWBPBASE_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MY85HWBPBASE_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x540a /d "NDEBUG"
# ADD RSC /l 0x540a /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"TEST/85HWBPBASE.dll"
# Begin Target

# Name "85HWBPBASE - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "antiss"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\antiss\antiss.cpp
# End Source File
# Begin Source File

SOURCE=.\antiss\antiss.h
# End Source File
# Begin Source File

SOURCE=.\antiss\bmpresize.cpp
# End Source File
# Begin Source File

SOURCE=.\antiss\bmpresize.h
# End Source File
# Begin Source File

SOURCE=.\antiss\opengl_callgates.cpp
# End Source File
# Begin Source File

SOURCE=.\antiss\opengl_callgates.h
# End Source File
# Begin Source File

SOURCE=.\antiss\readpixels.cpp
# End Source File
# Begin Source File

SOURCE=.\antiss\readpixels.h
# End Source File
# Begin Source File

SOURCE=.\antiss\screenshot.cpp
# End Source File
# Begin Source File

SOURCE=.\antiss\screenshot.h
# End Source File
# End Group
# Begin Group "x"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\defs.h
# End Source File
# Begin Source File

SOURCE=.\KEYDEFS.H
# End Source File
# Begin Source File

SOURCE=.\PARSEMSG.CPP
# End Source File
# Begin Source File

SOURCE=.\PARSEMSG.H
# End Source File
# Begin Source File

SOURCE=.\xorstr.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\AUTOOFFSETS.CPP
# End Source File
# Begin Source File

SOURCE=.\client.cpp
# End Source File
# Begin Source File

SOURCE=.\CVARS.CPP
# End Source File
# Begin Source File

SOURCE=.\draw.cpp
# End Source File
# Begin Source File

SOURCE=.\drawgl.cpp
# End Source File
# Begin Source File

SOURCE=.\HWBP.CPP
# End Source File
# Begin Source File

SOURCE=.\MAIN.CPP
# End Source File
# Begin Source File

SOURCE=.\menu\menu_nk.cpp
# End Source File
# Begin Source File

SOURCE=.\timehandling.cpp
# End Source File
# Begin Source File

SOURCE=.\WINAPI.CPP
# End Source File
# Begin Source File

SOURCE=.\XENGINE.CPP
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AUTOOFFSETS.H
# End Source File
# Begin Source File

SOURCE=.\client.h
# End Source File
# Begin Source File

SOURCE=.\client_headers.h
# End Source File
# Begin Source File

SOURCE=.\CVARS.H
# End Source File
# Begin Source File

SOURCE=.\draw.h
# End Source File
# Begin Source File

SOURCE=.\drawgl.h
# End Source File
# Begin Source File

SOURCE=.\HWBP.H
# End Source File
# Begin Source File

SOURCE=.\mainheaders.h
# End Source File
# Begin Source File

SOURCE=.\menu\menu_nk.h
# End Source File
# Begin Source File

SOURCE=.\peb.h
# End Source File
# Begin Source File

SOURCE=.\res\resource.h
# End Source File
# Begin Source File

SOURCE=.\timehandling.h
# End Source File
# Begin Source File

SOURCE=.\WINAPI.H
# End Source File
# Begin Source File

SOURCE=.\XENGINE.H
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Script1.rc
# End Source File
# Begin Source File

SOURCE=.\res\x2.bin
# End Source File
# End Group
# End Target
# End Project
