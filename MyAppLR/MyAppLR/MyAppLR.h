
// MyAppLR.h : main header file for the MyAppLR application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// MyAppLRApp:
// See MyAppLR.cpp for the implementation of this class
//

class MyAppLRApp : public CWinAppEx
{
public:
	MyAppLRApp();


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

extern MyAppLRApp theApp;
