//Default MFC Starter App
// OculusDataExtractorGUImain.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// COculusDataExtractorGUImainApp:
// See OculusDataExtractorGUImain.cpp for the implementation of this class
//

class COculusDataExtractorGUImainApp : public CWinApp
{
public:
	COculusDataExtractorGUImainApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern COculusDataExtractorGUImainApp theApp;