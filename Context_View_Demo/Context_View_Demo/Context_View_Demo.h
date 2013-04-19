
// Context_View_Demo.h : main header file for the Context_View_Demo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Context_View_DemoApp:
// See Context_View_Demo.cpp for the implementation of this class
//

class Context_View_DemoApp : public CWinAppEx
{
public:
	Context_View_DemoApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Context_View_DemoApp theApp;
