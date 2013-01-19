
// Preview_Pane.h : main header file for the Preview_Pane application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPreview_PaneApp:
// See Preview_Pane.cpp for the implementation of this class
//

class CPreview_PaneApp : public CWinAppEx
{
public:
	CPreview_PaneApp();


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

extern CPreview_PaneApp theApp;
