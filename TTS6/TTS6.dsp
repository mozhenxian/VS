# Microsoft Developer Studio Project File - Name="TTS6" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TTS6 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TTS6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TTS6.mak" CFG="TTS6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TTS6 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TTS6 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TTS6 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TTS6 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ   /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TTS6 - Win32 Release"
# Name "TTS6 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\agentctlanimationnames.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlaudioobjectex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlballoonex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacterex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacters.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommand.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandsex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandswindow.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlpropertysheet.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlrequest.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlspeechinput.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TTS6.cpp
# End Source File
# Begin Source File

SOURCE=.\TTS6.rc
# End Source File
# Begin Source File

SOURCE=.\TTS6Dlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\agentctlanimationnames.h
# End Source File
# Begin Source File

SOURCE=.\agentctlaudioobjectex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlballoonex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacterex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacters.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommand.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandsex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandswindow.h
# End Source File
# Begin Source File

SOURCE=.\agentctlex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlpropertysheet.h
# End Source File
# Begin Source File

SOURCE=.\agentctlrequest.h
# End Source File
# Begin Source File

SOURCE=.\agentctlspeechinput.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TTS6.h
# End Source File
# Begin Source File

SOURCE=.\TTS6Dlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\TTS6.ico
# End Source File
# Begin Source File

SOURCE=.\res\TTS6.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section TTS6 : {F5BE8BDD-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlSpeechInput
# 	2:10:HeaderFile:agentctlspeechinput.h
# 	2:8:ImplFile:agentctlspeechinput.cpp
# End Section
# Section TTS6 : {6D0ECB27-9968-11D0-AC6E-00C04FD97575}
# 	2:5:Class:CAgentCtlCommandsWindow
# 	2:10:HeaderFile:agentctlcommandswindow.h
# 	2:8:ImplFile:agentctlcommandswindow.cpp
# End Section
# Section TTS6 : {1DAB85C3-803A-11D0-AC63-00C04FD97575}
# 	2:5:Class:CAgentCtlRequest
# 	2:10:HeaderFile:agentctlrequest.h
# 	2:8:ImplFile:agentctlrequest.cpp
# End Section
# Section TTS6 : {DE8EF600-2F82-11D1-ACAC-00C04FD97575}
# 	2:5:Class:CAgentCtlCharacterEx
# 	2:10:HeaderFile:agentctlcharacterex.h
# 	2:8:ImplFile:agentctlcharacterex.cpp
# End Section
# Section TTS6 : {F5BE8BF0-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlAudioObjectEx
# 	2:10:HeaderFile:agentctlaudioobjectex.h
# 	2:8:ImplFile:agentctlaudioobjectex.cpp
# End Section
# Section TTS6 : {822DB1C0-8879-11D1-9EC6-00C04FD7081F}
# 	2:5:Class:CAgentCtlBalloonEx
# 	2:10:HeaderFile:agentctlballoonex.h
# 	2:8:ImplFile:agentctlballoonex.cpp
# End Section
# Section TTS6 : {8563FF20-8ECC-11D1-B9B4-00C04FD97575}
# 	2:5:Class:CAgentCtlEx
# 	2:10:HeaderFile:agentctlex.h
# 	2:8:ImplFile:agentctlex.cpp
# End Section
# Section TTS6 : {F5BE8BE8-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlCharacters
# 	2:10:HeaderFile:agentctlcharacters.h
# 	2:8:ImplFile:agentctlcharacters.cpp
# End Section
# Section TTS6 : {8B77181C-D3EF-11D1-8500-00C04FA34A14}
# 	2:5:Class:CAgentCtlAnimationNames
# 	2:10:HeaderFile:agentctlanimationnames.h
# 	2:8:ImplFile:agentctlanimationnames.cpp
# End Section
# Section TTS6 : {F5BE8BDF-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlPropertySheet
# 	2:10:HeaderFile:agentctlpropertysheet.h
# 	2:8:ImplFile:agentctlpropertysheet.cpp
# End Section
# Section TTS6 : {B0913410-3B44-11D1-ACBA-00C04FD97575}
# 	2:5:Class:CAgentCtlCommandEx
# 	2:10:HeaderFile:agentctlcommandex.h
# 	2:8:ImplFile:agentctlcommandex.cpp
# End Section
# Section TTS6 : {D45FD31B-5C6E-11D1-9EC1-00C04FD7081F}
# 	2:21:DefaultSinkHeaderFile:agentctlex.h
# 	2:16:DefaultSinkClass:CAgentCtlEx
# End Section
# Section TTS6 : {F5BE8BE3-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlCommand
# 	2:10:HeaderFile:agentctlcommand.h
# 	2:8:ImplFile:agentctlcommand.cpp
# End Section
# Section TTS6 : {6BA90C01-3910-11D1-ACB3-00C04FD97575}
# 	2:5:Class:CAgentCtlCommandsEx
# 	2:10:HeaderFile:agentctlcommandsex.h
# 	2:8:ImplFile:agentctlcommandsex.cpp
# End Section
