
// Text_Editor.h : main header file for the Text_Editor application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CText_EditorApp:
// See Text_Editor.cpp for the implementation of this class
//

class CText_EditorApp : public CWinAppEx
{
public:
	CText_EditorApp();


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

extern CText_EditorApp theApp;
