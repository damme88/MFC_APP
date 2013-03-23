
// Rebar_And_Bitmap.h : main header file for the Rebar_And_Bitmap application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Rebar_And_BitmapApp:
// See Rebar_And_Bitmap.cpp for the implementation of this class
//

class Rebar_And_BitmapApp : public CWinAppEx
{
public:
	Rebar_And_BitmapApp();


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

extern Rebar_And_BitmapApp theApp;
