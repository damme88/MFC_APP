
// App_TaskPane.h : main header file for the App_TaskPane application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CApp_TaskPaneApp:
// See App_TaskPane.cpp for the implementation of this class
//

class CApp_TaskPaneApp : public CWinAppEx
{
public:
	CApp_TaskPaneApp();


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

extern CApp_TaskPaneApp theApp;
