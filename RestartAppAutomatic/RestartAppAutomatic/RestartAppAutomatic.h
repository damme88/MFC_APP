
// RestartAppAutomatic.h : main header file for the RestartAppAutomatic application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// RestartAppAutomaticApp:
// See RestartAppAutomatic.cpp for the implementation of this class
//

class RestartAppAutomaticApp : public CWinAppEx
{
public:
	RestartAppAutomaticApp();


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

extern RestartAppAutomaticApp theApp;
