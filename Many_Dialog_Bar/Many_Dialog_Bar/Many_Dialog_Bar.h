
// Many_Dialog_Bar.h : main header file for the Many_Dialog_Bar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMany_Dialog_BarApp:
// See Many_Dialog_Bar.cpp for the implementation of this class
//

class CMany_Dialog_BarApp : public CWinAppEx
{
public:
	CMany_Dialog_BarApp();


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

extern CMany_Dialog_BarApp theApp;
