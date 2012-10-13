
// Toolbar_Xml.h : main header file for the Toolbar_Xml application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CToolbar_XmlApp:
// See Toolbar_Xml.cpp for the implementation of this class
//

class CToolbar_XmlApp : public CWinAppEx
{
public:
	CToolbar_XmlApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();
  virtual BOOL LoadState(LPCTSTR lpszProfileName = NULL, CFrameImpl* pDefaultFrame = NULL);
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CToolbar_XmlApp theApp;
