
// ComStudy_OpenIE.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// ComStudy_OpenIEApp:
// See ComStudy_OpenIE.cpp for the implementation of this class
//

class ComStudy_OpenIEApp : public CWinApp
{
public:
	ComStudy_OpenIEApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern ComStudy_OpenIEApp theApp;