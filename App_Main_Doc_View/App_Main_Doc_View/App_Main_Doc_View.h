
// App_Main_Doc_View.h : main header file for the App_Main_Doc_View application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CApp_Main_Doc_ViewApp:
// See App_Main_Doc_View.cpp for the implementation of this class
//

class CApp_Main_Doc_ViewApp : public CWinAppEx
{
public:
	CApp_Main_Doc_ViewApp();


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

extern CApp_Main_Doc_ViewApp theApp;
