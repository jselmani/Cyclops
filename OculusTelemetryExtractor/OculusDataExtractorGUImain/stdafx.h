//Default MFC header class

#define _CRT_SECURE_NO_WARNINGS

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


#include <afxdisp.h>        // MFC Automation classes

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars


//Includes added to the project
#include <Windows.h>
#include <fileapi.h>
#include <ShlObj.h>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <vector>
#include <ctime>
#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

#include "..\..\lib\OculusSDK\LibOVR\Include\OVR_CAPI.h"
#include "..\..\lib\OculusSDK\LibOVR\Include\Extras\OVR_Math.h"

#include "AngAccel.h"
#include "AngVelocity.h"
#include "LinAccel.h"
#include "LinVelocity.h"
#include "Orientation.h"
#include "resource.h"
