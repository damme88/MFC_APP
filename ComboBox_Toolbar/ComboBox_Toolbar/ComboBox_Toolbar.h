
// ComboBox_Toolbar.h : main header file for the ComboBox_Toolbar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CComboBox_ToolbarApp:
// See ComboBox_Toolbar.cpp for the implementation of this class
//

class CComboBox_ToolbarApp : public CWinAppEx
{
public:
	CComboBox_ToolbarApp();


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

extern CComboBox_ToolbarApp theApp;
