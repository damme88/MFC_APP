
// Dialog_Bar_Form.h : main header file for the Dialog_Bar_Form application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDialog_Bar_FormApp:
// See Dialog_Bar_Form.cpp for the implementation of this class
//

class CDialog_Bar_FormApp : public CWinAppEx
{
public:
	CDialog_Bar_FormApp();


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

extern CDialog_Bar_FormApp theApp;
