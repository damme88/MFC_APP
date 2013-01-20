
// DialogBar_MDI_MFC.h : main header file for the DialogBar_MDI_MFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDialogBar_MDI_MFCApp:
// See DialogBar_MDI_MFC.cpp for the implementation of this class
//

class CDialogBar_MDI_MFCApp : public CWinAppEx
{
public:
	CDialogBar_MDI_MFCApp();


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

extern CDialogBar_MDI_MFCApp theApp;
